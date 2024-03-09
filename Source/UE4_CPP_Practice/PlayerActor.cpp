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
	
	// Accept Material 
	bodyMeshComp->SetMaterial(0, bodyMaterial);
	headMeshComp->SetMaterial(0, bodyMaterial);
	catch_Arm_L_Mesh_Comp->SetMaterial(0, bodyMaterial);
	catch_Arm_R_Mesh_Comp->SetMaterial(0, bodyMaterial);
	miss_Arm_L_Mesh_Comp->SetMaterial(0, missArmMaterial);
	miss_Arm_R_Mesh_Comp->SetMaterial(0, missArmMaterial);
	hooray_Arm_L_Mesh_Comp->SetMaterial(0, hoorayArmMaterial);
	hooray_Arm_R_Mesh_Comp->SetMaterial(0, hoorayArmMaterial);

	// Posing
	this->removeAllPose();
}

// Called every frame
void APlayerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerActor::initMesh(){
	// Get Material
	static ConstructorHelpers::FObjectFinder<UMaterial> M_Player(TEXT("/Game/M_Player.M_Player"));
	if (M_Player.Object != NULL){
		bodyMaterial = (UMaterial*)M_Player.Object;
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> M_Miss(TEXT("/Game/M_Miss.M_Miss"));
	if (M_Miss.Object != NULL){
		missArmMaterial = (UMaterial*)M_Miss.Object;
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> M_Hooray(TEXT("/Game/M_Hooray.M_Hooray"));
	if (M_Hooray.Object != NULL){
		hoorayArmMaterial = (UMaterial*)M_Hooray.Object;
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

void APlayerActor::setPose(int pose_num){
	this->removeAllPose();

	switch(pose_num){
		case 0: // catch
			catch_Arm_L_Mesh_Comp->SetHiddenInGame(false);
			catch_Arm_R_Mesh_Comp->SetHiddenInGame(false);
			break;

		case 1: // miss
			miss_Arm_L_Mesh_Comp->SetHiddenInGame(false);
			miss_Arm_R_Mesh_Comp->SetHiddenInGame(false);
			break;

		case 2: // hooray
			hooray_Arm_L_Mesh_Comp->SetHiddenInGame(false);
			hooray_Arm_R_Mesh_Comp->SetHiddenInGame(false);
			break;
	}

	// Execute OnPoseTimer(Timer Handler) After 1 second
	GetWorldTimerManager().SetTimer(PoseHandler, this, &APlayerActor::OnPoseTimer, 0.5f, false);

}

void APlayerActor::removeAllPose(){
	catch_Arm_L_Mesh_Comp->SetHiddenInGame(true);
	catch_Arm_R_Mesh_Comp->SetHiddenInGame(true);
	miss_Arm_L_Mesh_Comp->SetHiddenInGame(true);
	miss_Arm_R_Mesh_Comp->SetHiddenInGame(true);
	hooray_Arm_L_Mesh_Comp->SetHiddenInGame(true);
	hooray_Arm_R_Mesh_Comp->SetHiddenInGame(true);
}

void APlayerActor::OnPoseTimer(){
	this->removeAllPose();
}

void APlayerActor::informMouseCnt(int mouse_cnt_in_game){
	this->mouse_cnt = mouse_cnt_in_game;
	this->mouse_remain = this->mouse_cnt;
}

void APlayerActor::informPlayerIdx(int player_idx){
	if (player_idx == playerOwnIndex){ // 자신이 할 차례인지 확인
		// 1초 후에 취할 행동 결정
		GetWorldTimerManager().SetTimer(DecisionHandler, this, &APlayerActor::OnDecisionTimer, 1.0f, false);
	}
}

void APlayerActor::OnDecisionTimer(){
	this->decision_action = FMath::RandRange(0, 1); // 0 == catch || 1 == miss

	this->setPose(decision_action);
}