// Fill out your copyright notice in the Description page of Project Settings.


#include "MCActor.h"

// Sets default values
AMCActor::AMCActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	initMesh();
}

// Called when the game starts or when spawned
void AMCActor::BeginPlay()
{
	Super::BeginPlay();
	
	bodyMeshComp->SetMaterial(0, MC_Material);
	headMeshComp->SetMaterial(0, MC_Material);
}

// Called every frame
void AMCActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMCActor::initMesh(){
	// Get Material
	static ConstructorHelpers::FObjectFinder<UMaterial> M_MC(TEXT("/Game/M_MC.M_MC"));
	if (M_MC.Object != NULL){
		MC_Material = (UMaterial*)M_MC.Object;
	}

	// 몸통
	bodyMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body Mesh Component"));
	UStaticMesh* bodyMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Engine/BasicShapes/Cube.Cube")).Object;
	bodyMeshComp->SetStaticMesh(bodyMesh);
	bodyMeshComp->SetWorldScale3D(FVector(0.3f, 0.3f, 0.3f));

	// 머리
	headMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head Mesh Component"));
	UStaticMesh* headMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Engine/BasicShapes/Sphere.Sphere")).Object;
	headMeshComp->SetStaticMesh(headMesh);

	headMeshComp->SetupAttachment(bodyMeshComp);
	headMeshComp->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));

}

// 잡아야 하는 쥐의 수와 남은 쥐의 수 초기화 & 플레이어에게 잡아야 할 쥐의 수 알리기
void AMCActor::initGame(){
	mouse_cnt = FMath::RandRange(3, 3);
	mouse_remain = mouse_cnt;

	player0->informMouseCnt(mouse_cnt);
}