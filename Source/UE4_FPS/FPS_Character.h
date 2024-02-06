// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "FPS_Projectile.h"
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

	// 발사체 발사 기능 추가
	UFUNCTION()
	void Fire();

	// 발사체 스폰 위치 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GamePlay")
	FVector MuzzleOffset;

	// Fire() 함수 실행 시 생성될 발사체 클래스 변수
	UPROPERTY(EditDefaultsOnly, Category="Projectile")
	TSubclassOf<AFPS_Projectile> ProjectileClass;

	// 카메라 클래스 변수 (3인칭 메시 문제 해결)
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* FPSCameraComponent;

	// 1인칭 메시
	UPROPERTY(VisibleDefaultsOnly, Category="Mesh")
	USkeletalMeshComponent* FPSMesh;

};
