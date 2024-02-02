// Copyright Epic Games, Inc. All Rights Reserved.


#include "UE4_UMG_InterfaceGameModeBase.h"
#include "Blueprint/UserWidget.h"

void AUE4_UMG_InterfaceGameModeBase::BeginPlay(){
    Super::BeginPlay();

    ChangeMenuWidget(StartingWidgetClass); // 게임 시작 시 StartingWidgetClass 위젯을 표시
}

void AUE4_UMG_InterfaceGameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass){
    // 현재 출력하고 있는 widget 비우기
    if (CurrentWidget != nullptr){
        CurrentWidget->RemoveFromViewport();
        CurrentWidget = nullptr;
    }

    // 입력 받은 위젯으로 변경
    if (NewWidgetClass != nullptr){
        CurrentWidget = CreateWidget(GetWorld(), NewWidgetClass);
        if (CurrentWidget != nullptr){
            CurrentWidget->AddToViewport(); // 위젯 출력
        }
    }
}