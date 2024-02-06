// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FPSHUD.generated.h"

/**
 * 
 */
UCLASS()
class UE4_FPS_API AFPSHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	// 조준선 이미지 저장 변수
	UPROPERTY(EditAnywhere)
	UTexture2D* CrosshairTexture;

public:
	// 조준선 화면에 출력하는 함수
	virtual void DrawHUD() override;
};
