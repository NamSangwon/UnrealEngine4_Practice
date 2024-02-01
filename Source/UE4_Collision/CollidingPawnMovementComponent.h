// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "CollidingPawnMovementComponent.generated.h"

/**
 Collding Pawn의 무빙을 구현할 클래스 (PawnMovementComponent 쿨래스를 상속하여 생성)
 */
UCLASS()
class UE4_COLLISION_API UCollidingPawnMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
	
public:
	// Tick 컴포넌트 오버라이드
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};
