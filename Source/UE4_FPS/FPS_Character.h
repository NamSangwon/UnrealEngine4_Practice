// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "FPS_Character.generated.h"

UCLASS()
class UE4_FPS_API AFPS_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPS_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 상하좌우 이동 함수
	UFUNCTION()
	void MoveForward(float AxisValue);
	
	UFUNCTION()
	void MoveRight(float AxisValue);

	// 점프 함수 
	UFUNCTION()
	void StartJump();
	
	UFUNCTION()
	void StopJump();

	// 카메라 클래스 변수 (3인칭 메시 문제 해결)
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* FPSCameraComponent;

	// 1인칭 메시
	UPROPERTY(VisibleDefaultsOnly, Category="Mesh")
	USkeletalMeshComponent* FPSMesh;
};
