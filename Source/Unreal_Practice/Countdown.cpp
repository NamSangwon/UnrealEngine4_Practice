// Fill out your copyright notice in the Description page of Project Settings.


#include "Countdown.h"

// Sets default values
ACountdown::ACountdown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// 꺽쇠 내의 객체에 해당하는 sub object 생성하여 초기화
	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Countdown Text"));
	CountdownText->SetHorizontalAlignment(EHTA_Center);
	CountdownText->SetWorldSize(150.0f);
	RootComponent = CountdownText; // Actor에서 CountdownText를 모든 컴포넌트의 상위 컴포넌트로 지정

	CountdownTime = 3;
}

// Called when the game starts or when spawned
void ACountdown::BeginPlay()
{
	Super::BeginPlay();

	UpdateTimerDisplay();

	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ACountdown::AdvanceTimer, 1.0f, true); // world 타이머 실행
	
}

// Called every frame
void ACountdown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// CountdownTime을 화면에 출력하는 함수 (CountdownTime ~ 0 까지 만을 출력 가능)
void ACountdown::UpdateTimerDisplay(){
	CountdownText->SetText(FString::FromInt(FMath::Max(CountdownTime, 0))); 
}

// countdown 적용 후 화면에 출력
void ACountdown::AdvanceTimer(){
	--CountdownTime;
	UpdateTimerDisplay();

	if (CountdownTime < 1){
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle); // We're done counting down, so stop running the timer.
		CountdownHasFinished(); // perform finished action
	}
}

void ACountdown::CountdownHasFinished_Implementation(){
	CountdownText->SetText(TEXT("GO!"));
}
