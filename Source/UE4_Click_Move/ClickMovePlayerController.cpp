// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickMovePlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

AClickMovePlayerController::AClickMovePlayerController(){
    bShowMouseCursor = true;
}

void AClickMovePlayerController::SetupInputComponent(){
    Super::SetupInputComponent();

    InputComponent->BindAction("LeftClick", IE_Pressed, this, &AClickMovePlayerController::InputLeftMouseButtonPressed);
    InputComponent->BindAction("LeftClick", IE_Released, this, &AClickMovePlayerController::InputLeftMouseButtonReleased);
}

void AClickMovePlayerController::PlayerTick(float DeltaTime){
    Super::PlayerTick(DeltaTime);

    // 마우스 좌클릭 시 이동 시작
    if (bClickLeftMouse){
        MoveToMouseCursor();
    }
}

void AClickMovePlayerController::InputLeftMouseButtonPressed(){
    bClickLeftMouse = true;
}

void AClickMovePlayerController::InputLeftMouseButtonReleased(){
    bClickLeftMouse = false;
}

// 마우스 좌클릭 시 목적지 이동 함수
void AClickMovePlayerController::SetNewDestination(const FVector Destination){
    APawn* const MyPawn = GetPawn();

    if (MyPawn){
        float const Distance = FVector::Dist(Destination, MyPawn->GetActorLocation());; // 목표 위치와 Pawn 사이의 거리 구하기
        if (Distance > 120.0f){ // 120 이상 차이가 날 시 이동
            UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, Destination); // 목표 지점으로 이동 함수
        }
    }
}

// 마우스 좌클릭 시 목적지 좌표 전달 함수
void AClickMovePlayerController::MoveToMouseCursor(){
    // 마우스 커서 아래에 레이트레이스를 사용하여 SetNewDestination()으로 전달
    FHitResult Hit;
    GetHitResultUnderCursor(ECC_Visibility, false, Hit);  

    if (Hit.bBlockingHit){
        SetNewDestination(Hit.ImpactPoint);
    }
}