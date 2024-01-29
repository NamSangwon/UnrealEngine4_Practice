// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
	// : TotalDamage(200), DamageTimeInSeconds(1.0f), CharacterName(TEXT("TEST")), bAttackable(true) // 생성자 내의 변수 값 지정 1
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// 생성자 내의 변수 값 지정 2
	TotalDamage = 200;
	DamageTimeInSeconds = 1.0f;
	CharacterName = TEXT("TEST");
	bAttackable = true;
}

// ※ 블루프린트에서 Call from Cpp의 부모 함수를 불러와서 연결하면 [블루프린트 받아오기 1, 2]가 모두 실행됨
// 블루프린트에서 각 노드들이 연결된 순서에 따라 부모 함수가 먼저 실행될 수도 있고 (ex. 이벤트 노드 ->  부모 함수 노드 -> set 노드)
// 자식 함수가 먼저 실행될 수 있다. (ex. 이벤트 노드 -> set 노드 -> 부모 함수 노드)

// 블루프린트 받아오기 2 (블루프린트에서 구현된 이벤트가 없으면 대신 자동적으로 실행됨)
void AMyActor::CallFromCpp_Implementation(){
	CharacterName.Append(TEXT("_Implementation"));
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	CallFromCpp(); // 블루프린트 받아오기 1
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::CalculateDPS(){
	DamagePerSecond = TotalDamage / DamageTimeInSeconds;
}

void AMyActor::PostInitProperties(){
	Super::PostInitProperties(); // 실제로 처리되는 작업이 수행되지 않아 문제가 발생할 수 있기 떄문에 부모 클래스의 원래 함수를 호출함
	CalculateDPS();
}

void AMyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent){
	CalculateDPS();
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

