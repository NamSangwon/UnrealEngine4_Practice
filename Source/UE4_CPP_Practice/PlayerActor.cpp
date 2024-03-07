// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerActor.h"

// Sets default values
APlayerActor::APlayerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	initMesh();
}

// Called when the game starts or when spawned
void APlayerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerActor::initMesh(){
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

	// Catch Arm
	catch_Arm_L_Mesh_Comp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Catch Left Arm Mesh Component"));
	catch_Arm_R_Mesh_Comp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Catch Right Arm Mesh Component"));
	UStaticMesh* catch_Arm_Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Engine/BasicShapes/Cube.Cube")).Object;

	catch_Arm_L_Mesh_Comp->SetStaticMesh(catch_Arm_Mesh);
	catch_Arm_R_Mesh_Comp->SetStaticMesh(catch_Arm_Mesh);

	catch_Arm_L_Mesh_Comp->SetRelativeScale3D(FVector(1.5f, 0.3f, 0.3f));
	catch_Arm_L_Mesh_Comp->SetRelativeLocation(FVector(70.0f, 70.0f, 50.0f));
	catch_Arm_L_Mesh_Comp->SetRelativeRotation(FRotator(30.0f, 0.0f, 0.0f));
	catch_Arm_R_Mesh_Comp->SetRelativeScale3D(FVector(1.5f, 0.3f, 0.3f));
	catch_Arm_R_Mesh_Comp->SetRelativeLocation(FVector(70.0f, -70.0f, 50.0f));
	catch_Arm_R_Mesh_Comp->SetRelativeRotation(FRotator(30.0f, 0.0f, 0.0f));

	catch_Arm_L_Mesh_Comp->SetupAttachment(bodyMeshComp);
	catch_Arm_R_Mesh_Comp->SetupAttachment(bodyMeshComp);

	// Miss Arm
	miss_Arm_L_Mesh_Comp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Miss Left Arm Mesh Component"));
	miss_Arm_R_Mesh_Comp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Miss Right Arm Mesh Component"));
	UStaticMesh* miss_Arm_Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Engine/BasicShapes/Cube.Cube")).Object;

	miss_Arm_L_Mesh_Comp->SetStaticMesh(miss_Arm_Mesh);
	miss_Arm_R_Mesh_Comp->SetStaticMesh(miss_Arm_Mesh);

	miss_Arm_L_Mesh_Comp->SetRelativeScale3D(FVector(1.5f, 0.3f, 0.3f));
	miss_Arm_L_Mesh_Comp->SetRelativeLocation(FVector(80.0f, 0.0f, 50.0f));
	miss_Arm_L_Mesh_Comp->SetRelativeRotation(FRotator(45.0f, 90.0f, 0.0f));
	miss_Arm_R_Mesh_Comp->SetRelativeScale3D(FVector(1.5f, 0.3f, 0.3f));
	miss_Arm_R_Mesh_Comp->SetRelativeLocation(FVector(80.0f, 0.0f, 50.0f));
	miss_Arm_R_Mesh_Comp->SetRelativeRotation(FRotator(-45.0f, 90.0f, 0.0f));

	miss_Arm_L_Mesh_Comp->SetupAttachment(bodyMeshComp);
	miss_Arm_R_Mesh_Comp->SetupAttachment(bodyMeshComp);
	
	// Hooray Arm
	hooray_Arm_L_Mesh_Comp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hooray Left Arm Mesh Component"));
	hooray_Arm_R_Mesh_Comp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hooray Right Arm Mesh Component"));
	UStaticMesh* hooray_Arm_Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Engine/BasicShapes/Cube.Cube")).Object;

	hooray_Arm_L_Mesh_Comp->SetStaticMesh(hooray_Arm_Mesh);
	hooray_Arm_R_Mesh_Comp->SetStaticMesh(hooray_Arm_Mesh);

	hooray_Arm_L_Mesh_Comp->SetRelativeScale3D(FVector(0.3f, 0.3f, 1.5f));
	hooray_Arm_L_Mesh_Comp->SetRelativeLocation(FVector(0.0f, 70.0f, 80.0f));
	hooray_Arm_L_Mesh_Comp->SetRelativeRotation(FRotator(0.0f, 0.0f, 15.0f));
	hooray_Arm_R_Mesh_Comp->SetRelativeScale3D(FVector(0.3f, 0.3f, 1.5f));
	hooray_Arm_R_Mesh_Comp->SetRelativeLocation(FVector(0.0f, -70.0f, 80.0f));
	hooray_Arm_R_Mesh_Comp->SetRelativeRotation(FRotator(0.0f, 0.0f, -15.0f));

	hooray_Arm_L_Mesh_Comp->SetupAttachment(bodyMeshComp);
	hooray_Arm_R_Mesh_Comp->SetupAttachment(bodyMeshComp);
}
