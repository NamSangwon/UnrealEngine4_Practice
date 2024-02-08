// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickMovePlayerController.h"

AClickMovePlayerController::AClickMovePlayerController(){
    bShowMouseCursor = true;
}

void AClickMovePlayerController::SetupInputComponent(){
    Super::SetupInputComponent();

    InputComponent->BindAction("LeftClick", IE_Pressed, this, &AClickMovePlayerController::InputLeftMouseButtonPressed)
    InputComponent->BindAction("LeftClick", IE_Released, this, &AClickMovePlayerController::InputLeftMouseButtonReleased)
}

void AClickMovePlayerController::InputLeftMouseButtonPressed(){
    bClickLeftMouse = true;
}

void AClickMovePlayerController::InputLeftMouseButtonReleased(){
    bClickLeftMouse = false;
}