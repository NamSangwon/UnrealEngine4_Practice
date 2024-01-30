// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TextRenderComponent.h"
#include "Countdown.generated.h"

UCLASS()
class UNREAL_PRACTICE_API ACountdown : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACountdown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// countdown을 위한 기초 변수 및 함수

	// 타이머 시간 조정
	UPROPERTY(EditAnyWhere)
	int32 CountdownTime;

	UTextRenderComponent* CountdownText;

	void UpdateTimerDisplay();

	// countdown을 실행 및 적용하기 위한 함수 및 변수
	void AdvanceTimer();

	// 블루프린트 제공
	UFUNCTION(BlueprintNativeEvent)
	void CountdownHasFinished();
	virtual void CountdownHasFinished_Implementation();

	FTimerHandle CountdownTimerHandle;
};
