// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UE4_UMG_InterfaceGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UE4_UMG_INTERFACE_API AUE4_UMG_InterfaceGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	// 위젯 변경 함수
	UFUNCTION(BlueprintCallable, Category="UMG_Game")
	void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:
	virtual void BeginPlay() override;

	// 게임 시작 시 표시될 UI 위젯을 저장
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG_Game")
	TSubclassOf<UUserWidget> StartingWidgetClass;

	// 현재 화면에 표시되고 있는 UI 위젯을 저장
	UPROPERTY()
	UUserWidget* CurrentWidget;
};
