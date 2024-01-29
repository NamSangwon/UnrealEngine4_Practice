// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class UNREAL_PRACTICE_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
	int32 TotalDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
	float DamageTimeInSeconds;

	UPROPERTY(BlueprintReadOnly, VisibleAnyWhere, Transient, Category="Damage")
	float DamagePerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bAttackable;

	// // 블루프린트 받아오기 1
	// UFUNCTION(BlueprintImplementableEvent, Category = "Damage")
	// void CallFromCpp();

	// 블루프린트 받아오기 2
	UFUNCTION(BlueprintNativeEvent, Category = "Damage")
	void CallFromCpp();
	virtual void CallFromCpp_Implementation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// DPS 구하기
	UFUNCTION(BlueprintCallable, Category = "Damage")
	void CalculateDPS();

	// AActor 부모 클래스의 함수 오버라이딩
	virtual void PostInitProperties() override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};
