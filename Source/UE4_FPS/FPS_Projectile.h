// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "FPS_Projectile.generated.h"

UCLASS()
class UE4_FPS_API AFPS_Projectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPS_Projectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 발사체의 충돌 처리 변수
	UPROPERTY(VisibleDefaultsOnly, Category="Projectile")
	USphereComponent* CollisionComponent;

	// 발사체의 움직임 처리 변수
	UPROPERTY(VisibleAnywhere, Category="Movement")
	UProjectileMovementComponent* ProjectileMovementComponent;

	// 발사체 담당 함수
	void FireInDirection(const FVector& ShootDirection); // const == 함수에 전달되는 포인터의 내용 훼손 방지
};
