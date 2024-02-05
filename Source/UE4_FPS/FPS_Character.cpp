// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_Character.h"

// Sets default values
AFPS_Character::AFPS_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPS_Character::BeginPlay()
{
	Super::BeginPlay();
	
	// 뷰포트에 로그 띄우기
	if (GEngine){
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using FPS_Character"));
	}
}

// Called every frame
void AFPS_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPS_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 구현한 함수와 매핑한 입력 값 바인딩
	PlayerInputComponent->BindAxis("MoveForward", this, &AFPS_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPS_Character::MoveRight);

	// 캐릭터 클래스에서 제공하는 카메라 회전 컨트롤에 대한 필수 함수 사용
	PlayerInputComponent->BindAxis("Turn", this, &AFPS_Character::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPS_Character::AddControllerPitchInput);

	// 점프 함수 매핑
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFPS_Character::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFPS_Character::StopJump);

}

// 캐릭터의 동작 축을 카메라에 상대적이게 설정 (전방 == 카메라가 향하는 방향)
// 제어 방향 구하기 => 플레이어의 컨트롤러 사용
// 제어 회전 함수의 피치 컴포너트를 무시하여 입력을 X, Y로 제한시켜 위나 아래를 바라보더라도 캐릭터는 땅과 평행하게 움직이도록 함
void AFPS_Character::MoveForward(float AxisValue){
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, AxisValue);
}

void AFPS_Character::MoveRight(float AxisValue){
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, AxisValue);
}

void AFPS_Character::StartJump(){
	bPressedJump = true;
}

void AFPS_Character::StopJump(){
	bPressedJump = false;
}