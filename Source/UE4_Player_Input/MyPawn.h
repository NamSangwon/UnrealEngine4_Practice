// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class UE4_PLAYER_INPUT_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	USceneComponent* OurVisibleComponent; // USceneComponent == 위치와 회전 등을 포함하는 월드에 배치 가능한 다른 컴포너트들의 부모 클래스 컴포넌트 (충돌같은 물리효과 X -> 더미로 사용하기 좋음)

	// 입력에 따른 무빙 함수 구현
	void Move_XAxis(float AxisValue);
	void Move_YAxis(float AxisValue);
	void StartGrowing();
	void StopGrowing();

	FVector CurrentVelocity;
	bool bGrowing;

	float InputTime;
};
