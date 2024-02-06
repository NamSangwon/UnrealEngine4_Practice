// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_Character.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AFPS_Character::AFPS_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 3인칭 메시 문제 해결을 위한 카메라 위치 조정
	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FPSCameraComponent->SetupAttachment(GetCapsuleComponent()); // 카메라 부착
	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight)); // 카메라 위치 조정
	FPSCameraComponent->bUsePawnControlRotation = true; // Pawn 카메라 로테이션 제어 허용

	// 1인칭 메시 컴포넌트
	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	FPSMesh->SetOnlyOwnerSee(true); // 해당 플레이어만 보이도록 함
	FPSMesh->SetupAttachment(FPSCameraComponent); // 카메라에 붙여서 보이도록 함
	FPSMesh->bCastDynamicShadow = false; // 그림자 보이지 않게 하기 1
	FPSMesh->CastShadow = false; // 그림자 보이지 않게 하기 2

	// 해당 플레이어는 3인칭 메시가 보이지 않도록 설정
	GetMesh()->SetOwnerNoSee(true);
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

	// 발사체 발사 함수 매핑
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPS_Character::Fire);

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

void AFPS_Character::Fire(){
	if (ProjectileClass){
		// 캐릭터의 카메라 위치 및 방향 구하기
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation); 

		// 발사체 클래스 스폰될 위치 정하기
		// MuzzleOffset 을 카메라 스페이스에서 월드 스페이스로 변환합니다.
		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);
		FRotator MuzzleRotation = CameraRotation;
		MuzzleRotation.Pitch += 10.0f; // 조준을 약간 윗쪽으로 올리기

		// 발사체 스폰 위치에서 부터 발사체 생성 후 발사
		UWorld* World = GetWorld();
		if (World){
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			// 발사체 생성
			AFPS_Projectile* Projectile = World->SpawnActor<AFPS_Projectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
			if (Projectile) {
				// LaunchDirection == MuzzleRotation.Vector()의 방향으로 발사체 발사
				FVector LaunchDirection = MuzzleRotation.Vector();
				Projectile->FireInDirection(LaunchDirection);
			}
		}
	}
}