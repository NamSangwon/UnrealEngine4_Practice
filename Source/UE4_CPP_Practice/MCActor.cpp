// Fill out your copyright notice in the Description page of Project Settings.


#include "MCActor.h"

// Sets default values
AMCActor::AMCActor()
		: player_idx(-1)
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

	// APlayerActor에서 선언한 이벤트를 처리할 핸들러 바인딩
	player0->OnDecided().AddUObject(this, &AMCActor::OnPlayerDecidedEvent);

	this->initGame();
	this->moveNextPlayer();
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

void AMCActor::moveNextPlayer(){
	this->player_idx = (this->player_idx + 1) % 5; // 0 ~ 4의 인덱스로 총 5명의 플레이어 지정

	player0->informPlayerIdx(player_idx);
}

// 이벤트 처리 핸들러
void AMCActor::OnPlayerDecidedEvent(int32 decision_action){
	if (decision_action == 0){ // catch
		this->mouse_remain--;

		if (this->mouse_remain == 0){ // hooray
			GetWorldTimerManager().SetTimer(InitTimer, this, &AMCActor::OnInitTimer, 2.0f, false);
		}
		else{
			this->moveNextPlayer();
		}
	}
	else{ // miss
		this->moveNextPlayer();
	}
}

void AMCActor::OnInitTimer(){
	this->initGame();
	this->moveNextPlayer();
}