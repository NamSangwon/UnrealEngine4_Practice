// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UE4_PracticeHUD.generated.h"

UCLASS()
class AUE4_PracticeHUD : public AHUD
{
	GENERATED_BODY()

public:
	AUE4_PracticeHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

