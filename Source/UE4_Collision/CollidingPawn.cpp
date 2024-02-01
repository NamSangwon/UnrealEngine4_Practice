// Fill out your copyright notice in the Description page of Project Settings.


#include "CollidingPawn.h"
#include "CollidingPawnMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ACollidingPawn::ACollidingPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// USphereComponent == 구체의 물리 처리 컴포넌트 (충돌 처리)
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(40.0f); // 크기 지정
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));

	// 구체의 보이게 할 Mesh 추가 
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	SphereVisual->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere")); // 구체 에셋 불러오기
	if (SphereVisualAsset.Succeeded()){ // 에셋을 성공적으로 찾을 시
		SphereVisual->SetStaticMesh(SphereVisualAsset.Object); // Mesh 적용
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f)); // 위치 지정
		SphereVisual->SetWorldScale3D(FVector(0.8f)); // 크기 지정
	}

	// 구체에 Particle 추가
	OurParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("OurParticleSystem"));
	OurParticleSystem->SetupAttachment(RootComponent);
	OurParticleSystem->bAutoActivate = false; // 시작 시 파티클 작동 X
	OurParticleSystem->SetRelativeLocation(FVector(-20.0f, 0.0f, 20.0f)); // 위치 지정
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Game/StarterContent/Particles/P_Fire.P_Fire")); // 파티클 에셋 불러오기
	if (ParticleAsset.Succeeded()){ // 에셋을 성공적으로 찾을 시
		OurParticleSystem->SetTemplate(ParticleAsset.Object); // 에셋 적용
	}

	// USpringArmComponent == Pawn을 따라가는 카메라의 유용한 기능을 제공하는 컴포넌트 (벽 뚫기 X & 느리게 따라가기)
	USpringArmComponent* SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
	SpringArm->SetupAttachment(RootComponent); 
	SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f)); // 회전 지정
	SpringArm->TargetArmLength = 400.0f; // Pawn과 카메라 간의 거리 지정
	SpringArm->bEnableCameraLag = true; // 느리게 따라가기
	SpringArm->CameraLagSpeed = 3.0f; // 속도 지정

	// 카메라 생성
	UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName); // USpringArmComponent::SocketName을 통해 USpringArm의 소켓에 카메라 부착

	OurMovementComponent = CreateDefaultSubobject<UCollidingPawnMovementComponent>(TEXT("OurMovementComponent"));
	OurMovementComponent->UpdatedComponent = RootComponent; // UCollidingPawnMovementComponent 클래스의 업데이트될 컴포넌트를 의미하는 UpdatedComponent를 RootComponent로 하여 Root를 움직일 수 있도록 함

	AutoPossessPlayer = EAutoReceiveInput::Player0; // 게임 시작 시 Pawn 조작 권한 자동 부여
}

// Called when the game starts or when spawned
void ACollidingPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollidingPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACollidingPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("ParticleToggle", IE_Pressed, this, &ACollidingPawn::ParticleToggle);

	InputComponent->BindAxis("MoveForward", this, &ACollidingPawn::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACollidingPawn::MoveRight);
	InputComponent->BindAxis("Turn", this, &ACollidingPawn::Turn);
}

// UPawnMovementComponent의 GetMovementComponent를 UCollidingPawnMovementComponent의 GetMovementComponent로 재정의
UPawnMovementComponent* ACollidingPawn::GetMovementComponent() const{
	return OurMovementComponent; 
}

void ACollidingPawn::MoveForward(float AxisValue){
	if(OurMovementComponent && (OurMovementComponent->UpdatedComponent == RootComponent)){
		OurMovementComponent->AddInputVector(GetActorForwardVector() * AxisValue); // AddInputVector()는 UCollidingPawnMovementComponent의 ConsumeInputVector()를 통해 사용 됨
	}
}

void ACollidingPawn::MoveRight(float AxisValue){
	if(OurMovementComponent && (OurMovementComponent->UpdatedComponent == RootComponent)){
		OurMovementComponent->AddInputVector(GetActorRightVector() * AxisValue); // AddInputVector()는 UCollidingPawnMovementComponent의 ConsumeInputVector()를 통해 사용 됨
	}
}

void ACollidingPawn::Turn(float AxisValue){
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += AxisValue;
	SetActorRotation(NewRotation);
}

void ACollidingPawn::ParticleToggle(){
	if (OurParticleSystem && OurParticleSystem->Template){
		OurParticleSystem->ToggleActive();
	}
}
