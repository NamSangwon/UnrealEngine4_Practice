// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_Projectile.h"

// Sets default values
AFPS_Projectile::AFPS_Projectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 발사체 충돌 처리 변수 초기화
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionComponent->InitSphereRadius(15.0f);
	RootComponent = CollisionComponent;
	// 발사체 클래스의 소스파일에 충돌 프로파일 지정
	CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
	// OnHit 함수 등록
	CollisionComponent->OnComponentHit.AddDynamic(this, &AFPS_Projectile::OnHit);

	// 발사체 움직임 처리 변수 초기화
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
	ProjectileMovementComponent->InitialSpeed = 3000.0f;
	ProjectileMovementComponent->MaxSpeed = 3000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;
	ProjectileMovementComponent->Bounciness = 0.3f;

	// 해당 액터 클래스 수명
	InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void AFPS_Projectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPS_Projectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// 발사체 담당 함수
void AFPS_Projectile::FireInDirection(const FVector& ShootDirection){
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed; // 발사체 속도 = 해당 방향에 초기 속력 
}

// 충돌 처리 함수 
void AFPS_Projectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit){
	if (OtherActor != this && OtherComponent->IsSimulatingPhysics()){
		// 발사체에 맞은 액터를 날아가게 하도록 구현
		OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
	}
}
