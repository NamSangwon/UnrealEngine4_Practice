// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSHUD.h"
#include "Engine/Canvas.h"

// 조준선을 화면에 중심에 그리기
void AFPSHUD::DrawHUD(){
    Super::DrawHUD();

    if(CrosshairTexture){
        FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f); // 화면 중심
        FVector2D CrosshairDrawPosition(Center.X - (CrosshairTexture->GetSurfaceWidth() * 0.5f), Center.Y - (CrosshairTexture->GetSurfaceHeight() * 0.5f)); // 조준선 그릴 위치 지정

        // 조준선 그리기
        FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTexture->Resource, FLinearColor::White); 
        TileItem.BlendMode = SE_BLEND_Translucent;
        Canvas->DrawItem(TileItem);
    }
}