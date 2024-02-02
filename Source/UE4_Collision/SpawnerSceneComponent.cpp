// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerSceneComponent.h"

// Sets default values for this component's properties
USpawnerSceneComponent::USpawnerSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// 자식 개체 3개 생성
	for (int i = 0; i < 3; i++){
		// 같은 이름을 사용할 시 빌드에서 오류 발생하여 FName()을 통해 이름을 달리 함
		UStaticMeshComponent* Child = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("Child"), i));
		Child->SetupAttachment(this);
		static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone"));
		if (MeshAsset.Succeeded()){
			Child->SetStaticMesh(MeshAsset.Object);
		}
		// 자식 컴포넌트 위치 배정
		float radian = (2.0f * PI) / 3.0f;
		radian *= i; // ★ 3π/2 -> 6π/2 -> 12π/2
		FVector Location = FVector(FMath::Cos(radian), FMath::Sin(radian), 0.0f) * 100.0f; // 부모 클래스를 중심으로 원형으로 배치 
		Child->SetRelativeLocation(Location);
		Childs.Add(Child);
	}

	DestroyTime = 3.0f;
}


// Called when the game starts
void USpawnerSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USpawnerSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	DestroyTime -= DeltaTime;
	if(DestroyTime < 0.0f){
		for (int i = 0; i < Childs.Num(); i++){
			Childs[i]->DestroyComponent(); // 자식 컴포넌트 소멸
		}
		DestroyComponent(); // 부모 컴포넌트 소멸
	}
}

