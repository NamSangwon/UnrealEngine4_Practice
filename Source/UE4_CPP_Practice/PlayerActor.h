// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerActor.generated.h"

DECLARE_EVENT_OneParam(APlayerActor, FOnDecideEvent, int32)

UCLASS()
class UE4_CPP_PRACTICE_API APlayerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void initMesh();
	void setPose(int pose_num);
	void removeAllPose();
	void OnPoseTimer();
	void OnDecisionTimer();

	FTimerHandle PoseHandler;
	FTimerHandle DecisionHandler;

	int mouse_cnt;
	int mouse_remain;
	int decision_action;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 몸통
	UStaticMeshComponent* bodyMeshComp;

	// 머리
	UStaticMeshComponent* headMeshComp;

	// Catch Arm
	UStaticMeshComponent* catch_Arm_L_Mesh_Comp;
	UStaticMeshComponent* catch_Arm_R_Mesh_Comp;

	// Miss Arm
	UStaticMeshComponent* miss_Arm_L_Mesh_Comp;
	UStaticMeshComponent* miss_Arm_R_Mesh_Comp;

	// Hooray Arm
	UStaticMeshComponent* hooray_Arm_L_Mesh_Comp;
	UStaticMeshComponent* hooray_Arm_R_Mesh_Comp;
	
	// Material 
	UMaterial* bodyMaterial;
	UMaterial* missArmMaterial;
	UMaterial* hoorayArmMaterial;

	// Player Own Index
	UPROPERTY(EditAnywhere)
	int playerOwnIndex;

	void informMouseCnt(int mouse_cnt); // For get total mouse count In Game
	void informPlayerIdx(int player_idx); 

// UE Event
public:
	FOnDecideEvent& OnDecided(){
		return decideEvent;
	}

private:
	FOnDecideEvent decideEvent;
	
};
