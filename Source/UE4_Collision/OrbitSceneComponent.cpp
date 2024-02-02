// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitSceneComponent.h"

// Sets default values for this component's properties
UOrbitSceneComponent::UOrbitSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// 공전 개체 이미지(?) 적용
	UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Orbit"));
	Mesh->SetupAttachment(this);
	Mesh->SetRelativeLocation(FVector(0.0f, 100.0f, 0.0f));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (MeshAsset.Succeeded()){
		Mesh->SetStaticMesh(MeshAsset.Object);
	}


}


// Called when the game starts
void UOrbitSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOrbitSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// 해당 공전 컴포넌트 회전 코드
	FRotator NewRotation = GetComponentRotation();
	NewRotation.Yaw += DeltaTime * 500.0f; // 회전 속도 (Yaw == Z축을 기준으로 회전 반경)
	SetWorldRotation(NewRotation); // 월드에 적용

}

