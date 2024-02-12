// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDownPlayerController.h"
#include "Kismet/KismetMathLibrary.h"

ATopDownPlayerController::ATopDownPlayerController(){
    bShowMouseCursor = true;
}

void ATopDownPlayerController::PlayerTick(float DeltaTime){
    Super::PlayerTick(DeltaTime);

    LookMouseCursor();
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

void ATopDownPlayerController::LookMouseCursor(){
    FHitResult Hit;
    GetHitResultUnderCursor(ECC_Visibility, false, Hit);

    if (Hit.bBlockingHit){
        APawn* const MyPawn = GetPawn();
        if (MyPawn){
            FRotator LookRotation = UKismetMathLibrary::FindLookAtRotation(MyPawn->GetActorLocation(), 
                                                        FVector(Hit.Location.X, Hit.Location.Y, MyPawn->GetActorLocation().Z));
            MyPawn->SetActorRotation(LookRotation);
        }
    }
}