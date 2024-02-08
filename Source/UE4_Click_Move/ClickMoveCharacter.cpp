// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickMoveCharacter.h"
#include "Engine/Classes/Components/CapsuleComponent.h"
#include "Engine/Classes/Camera/CameraComponent.h"
#include "Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Engine/Classes/GameFramework/SpringArmComponent.h"


// Sets default values
AClickMoveCharacter::AClickMoveCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true; // BeginPlay() 실행 후 Tick()을 수행하도록 함

	// 캐릭터 콜라이더 사이즈 설정
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	// 캐릭터가 카메라의 회전에 따라 움직이지 않게 설정
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// 캐릭터가 움직이는 방향으로 향하도록 회전 (초당 640도)
	GetCharacterMovement()->bOrientRotationToMovement = true; // 캐릭터가 움직이는 방향으로 향하도록 회전
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 640.0f, 0.0f); // 초당 640도
	GetCharacterMovement()->bConstrainToPlane = true; // 캐릭터의 이동을 평면 이동으로 한정
	GetCharacterMovement()->bSnapToPlaneAtStart = true; // 게임 시작 시 캐릭터를 가까운 평면으로 이동

	// SpringArm 초기화
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->SetUsingAbsoluteRotation(true); // RootComponent등과 같은 상위 Component를 따르지 않고 월드 좌표계의 회전에 따름
	SpringArmComponent->TargetArmLength = 800.0f; // 길이 조절
	SpringArmComponent->SetRelativeRotation(FRotator(-60.0f, 45.0f, 0.0f)); // 캐릭터를 내려다 보도록 SpringArm 회전 조절
	SpringArmComponent->bDoCollisionTest = false; // SpringArm이 충돌 시 사물을 뚫지 않도록 함

	// 카메라 컴포넌트 초기화
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName); // 카메라 SpringArm에 부착
	CameraComponent->bUsePawnControlRotation = false; // 카메라의 회전이 Pawn의 회전에 영향을 주지 않도록 설정

}

// Called when the game starts or when spawned
void AClickMoveCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AClickMoveCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void AClickMoveCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

