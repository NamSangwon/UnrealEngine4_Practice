// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerActor.h"
#include "MCActor.generated.h"

UCLASS()
class UE4_CPP_PRACTICE_API AMCActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMCActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void initMesh();

	void initGame();
	void moveNextPlayer();

	void OnInitTimer();
	void OnPlayerDecidedEvent(int32 decision_action);

	int mouse_cnt;
	int mouse_remain;

	int player_idx;

	FTimerHandle InitTimer;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 몸통
	UStaticMeshComponent* bodyMeshComp;

	// 머리
	UStaticMeshComponent* headMeshComp;

	// Material
	UMaterial* MC_Material;

	// Players
	UPROPERTY(EditAnywhere)
	APlayerActor* player0;
	
	UPROPERTY(EditAnywhere)
	APlayerActor* player1;
	
	UPROPERTY(EditAnywhere)
	APlayerActor* player2;
	
	UPROPERTY(EditAnywhere)
	APlayerActor* player3;
	
	UPROPERTY(EditAnywhere)
	APlayerActor* player4;
};
