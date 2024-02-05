// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UE4_FPSGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UE4_FPS_API AUE4_FPSGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	// 게임이 시작될 떄, 게임 모드에서 액터들의 BeginPlay()를 호출하는 함수
	virtual void StartPlay() override; 


};
