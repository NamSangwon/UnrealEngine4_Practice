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

}

