// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE4_PracticeGameMode.h"
#include "UE4_PracticeHUD.h"
#include "UE4_PracticeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE4_PracticeGameMode::AUE4_PracticeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUE4_PracticeHUD::StaticClass();
}
