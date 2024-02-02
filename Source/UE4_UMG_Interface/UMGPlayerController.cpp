// Fill out your copyright notice in the Description page of Project Settings.


#include "UMGPlayerController.h"

void AUMGPlayerController::BeginPlay(){
    Super::BeginPlay();

    SetInputMode(FInputModeGameAndUI()); // 게임 시작 시 Input & UI를 입력 처리 가능하도록 설정
}