// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Camera/CameraComponent.h" // for UCameraComponent

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0; // ★ 게임이 시작되면 자동으로 플레이어의 입력이 연결되도록 함

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// RootComponent에 OurCamera 부착
	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurCamera->SetupAttachment(RootComponent);
	OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
	OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));

	// RootComponent에 OurVisibleComponent 부착
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	{ // Growing 실행 처리
		float CurrentScale = OurVisibleComponent->GetComponentScale().X;
		if(bGrowing){
			CurrentScale += DeltaTime;
		}
		else{
			CurrentScale -= DeltaTime;
		}
		CurrentScale = FMath::Clamp(CurrentScale, 1.0f, 2.0f); // 1 ~ 2까지만 크기 조절 가능하게 제한
		OurVisibleComponent->SetWorldScale3D(FVector(CurrentScale)); // 적용
	}

	{
		if (!CurrentVelocity.IsZero()){
			InputTime += DeltaTime;
			FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime * (InputTime <= 1.0f ? 1.0f : 3.0f)); // 움직임 계산 (키 누르는 시간이 1초보다 길면 속도 3배 증가) 
			SetActorLocation(NewLocation); // 적용
		}
		else{
			InputTime = 0.0f;
		}
	}
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 입력 키와 해당 키에 대응되는 함수 바인딩
	// Growing 처리
	PlayerInputComponent->BindAction("Grow", IE_Pressed, this, &AMyPawn::StartGrowing);
	PlayerInputComponent->BindAction("Grow", IE_Released, this, &AMyPawn::StopGrowing);

	// Moving 처리
	PlayerInputComponent->BindAxis("MoveX", this, &AMyPawn::Move_XAxis);
	PlayerInputComponent->BindAxis("MoveY", this, &AMyPawn::Move_YAxis);

}

// 입력 키 값과의 바인딩 必
void AMyPawn::Move_XAxis(float AxisValue){
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f; // -1 ~ 1로 제한 (-> w & ↑ 모두 등록 되어 있을 경우 동시에 누르면 두 값이 합산되어 전달되어 이동 속도 2배가 됨)
}

void AMyPawn::Move_YAxis(float AxisValue){
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f; // -1 ~ 1로 제한 (-> w & ↑ 모두 등록 되어 있을 경우 동시에 누르면 두 값이 합산되어 전달되어 이동 속도 2배가 됨)
}

void AMyPawn::StartGrowing(){
	bGrowing = true;
}

void AMyPawn::StopGrowing(){
	bGrowing = false;
}

