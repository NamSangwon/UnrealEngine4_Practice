// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class UNREAL_PRACTICE_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// float -> FVector 변환은 모든 축으로의 이동을 적용시키기 위함
	FVector RunningTime;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	FVector FloatingSpeed;
};
