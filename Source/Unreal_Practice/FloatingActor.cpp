// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
	FloatingSpeed = FVector(1.0f, 1.0f, 1.0f);
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 하드 코딩 (FloatingSpeed를 DeltaTime에 곱하기 추가)
	FVector NewLocation = GetActorLocation(); // Actor 위치 받아오기
	// float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime * FloatingSpeed) - FMath::Sin(RunningTime)); // 시간의 지나면서 Sin 함수를 따라 위치 구하기
	float DeltaX = (FMath::Sin(RunningTime.X + DeltaTime * FloatingSpeed.X) - FMath::Sin(RunningTime.X)); // 시간의 지나면서 Sin 함수를 따라 X 좌표 구하기
	float DeltaY = (FMath::Sin(RunningTime.Y + DeltaTime * FloatingSpeed.Y) - FMath::Sin(RunningTime.Y)); // 시간의 지나면서 Sin 함수를 따라 Y 좌표 구하기
	float DeltaZ = (FMath::Sin(RunningTime.Z + DeltaTime * FloatingSpeed.Z) - FMath::Sin(RunningTime.Z)); // 시간의 지나면서 Sin 함수를 따라 Z 좌표 구하기
	NewLocation += FVector(DeltaX, DeltaY, DeltaZ) * 20.0f; // Sin 함수에 따른 위치를 점프로 적용 (Z축에 적용)
	RunningTime += DeltaTime * FloatingSpeed;
	SetActorLocation(NewLocation); // 실질적인 Actor 위치 조정 적용


}

