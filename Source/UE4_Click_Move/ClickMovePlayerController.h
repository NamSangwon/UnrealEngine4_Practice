// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ClickMovePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UE4_CLICK_MOVE_API AClickMovePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AClickMovePlayerController();

protected:
	bool bClickLeftMouse; //  좌클릭 시 true

	void InputLeftMouseButtonPressed();

	void InputLeftMouseButtonReleased();

	virtual void SetupInputComponent() override;
};
