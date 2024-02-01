// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CollidingPawn.generated.h"

UCLASS()
class UE4_COLLISION_API ACollidingPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACollidingPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UPawnMovementComponent* GetMovementComponent() const override; // UCollidingPawnMovementComponent의 GetMovementComponent()를 사용하도록 재정의

	UParticleSystemComponent* OurParticleSystem;

	class UCollidingPawnMovementComponent* OurMovementComponent; // 임시 선언 클래스 -> 소스파일에서 import 必 (헤더에서 import해도 무관)

	void MoveForward(float AxisValue);

	void MoveRight(float AxisValue);

	void Turn(float AxisValue);

	void ParticleToggle();
};
