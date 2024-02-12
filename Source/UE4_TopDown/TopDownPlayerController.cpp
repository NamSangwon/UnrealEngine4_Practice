// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDownPlayerController.h"

ATopDownPlayerController::ATopDownPlayerController(){
    bShowMouseCursor = true;
}

void ATopDownPlayerController::SetupInputComponent(){
    Super::SetupInputComponent();

    InputComponent->BindAxis("MoveForward", this, &ATopDownPlayerController::MoveForward);
    InputComponent->BindAxis("MoveRight", this, &ATopDownPlayerController::MoveRight);
}

void ATopDownPlayerController::MoveForward(float AxisValue){
    APawn* const MyPawn = GetPawn();

    if (MyPawn){
        FVector Direction = FVector::ForwardVector;
        MyPawn->AddMovementInput(Direction, AxisValue);
    }
}

void ATopDownPlayerController::MoveRight(float AxisValue){
    APawn* const MyPawn = GetPawn();

    if (MyPawn){
        FVector Direction = FVector::RightVector;
        MyPawn->AddMovementInput(Direction, AxisValue);
    }
}