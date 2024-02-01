// Fill out your copyright notice in the Description page of Project Settings.


#include "CollidingPawnMovementComponent.h"

void UCollidingPawnMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction); // 부모 클래스 
    
    // Pawn 이동 코드 (추후에 배울 내용이므로 간략한 설명만을 포함)
    // 이동 가능한 상태인지 판별
    if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime)){
        return;
    }

    // ConsumeInputVector() == 입력된 이동 벡터 가져오기 
    FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * 150.0f;

    if (!DesiredMovementThisFrame.IsNearlyZero()){
        FHitResult Hit;
        // 언리얼의 물리 엔진을 통해 장애물을 피해 PawnMovementComponent를 이동
        SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);

        if(Hit.IsValidBlockingHit()){ // 충돌 발생 시
            // 표면체에 미끄러지듯이 움직이도록 함
            SlideAlongSurface(DesiredMovementThisFrame, 1.0f - Hit.Time, Hit.Normal, Hit);
        }
    }
}