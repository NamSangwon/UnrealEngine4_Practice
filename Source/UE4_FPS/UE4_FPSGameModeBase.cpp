// Copyright Epic Games, Inc. All Rights Reserved.


#include "UE4_FPSGameModeBase.h"

void AUE4_FPSGameModeBase::StartPlay(){
    Super::StartPlay();

    if(GEngine){
        // 뷰포트 화면에 로그 띄우기
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, This is FPS Game Mode!")); 
    }
}
