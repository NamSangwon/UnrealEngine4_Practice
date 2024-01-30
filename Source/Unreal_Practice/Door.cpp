// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	RootComponent = DoorMesh;

	CloseTime = 3.0f;

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
	OriginRotation = GetActorRotation();

	GetWorldTimerManager().SetTimer(DoorTimerHandle, this,  &ADoor::Open, 0.03f, true); // 0.03초 간격으로 실행
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DoorDeltaTime += DeltaTime;
}

void ADoor::Open(){
	if (!bOpen){
		bOpen = true;
		DoorDeltaTime = 0.0f;
	}

	// 문 열림 작동
	FRotator rotation = GetActorRotation();
	rotation = OriginRotation + FRotator(0.0f, FMath::Lerp(0.0f, 90.0f, DoorDeltaTime), 0.0f); // delta time에 따른 y축만 회전 -> 문 열림 적용 (Lerp == 선형보간 -> 사잇 값 계산)
	SetActorRotation(rotation);

	// 문 닫힘 작동 준비
	if (DoorDeltaTime > 1.0f){
		GetWorldTimerManager().ClearTimer(DoorTimerHandle); // Timer 중지
		GetWorldTimerManager().SetTimer(DoorTimerHandle, this, &ADoor::Close, 0.03f, true, CloseTime); // CloseTime이 지난 후에 Close()를 0.03초 간격으로 실행
	}
}

void ADoor::Close(){
	if (bOpen){
		bOpen = false;
		DoorDeltaTime = 0.0f;
	}

	// 문 닫힘 작동
	FRotator rotation = GetActorRotation();
	rotation = OriginRotation + FRotator(0.0f, FMath::Lerp(90.0f, 0.0f, DoorDeltaTime), 0.0f); // delta time에 따른 y축만 회전 -> 문 열림 적용 (Lerp == 선형보간 -> 사잇 값 계산)
	SetActorRotation(rotation);

	// 문 닫힘 작동 준비
	if (DoorDeltaTime > 1.0f){
		GetWorldTimerManager().ClearTimer(DoorTimerHandle); // Timer 중지
	}
}

