// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectibleActor.generated.h"

UCLASS()
class SIMPLECOLLECTORGAME_API ACollectibleActor : public AActor
{
    GENERATED_BODY()
public:
    ACollectibleActor();
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* MeshComponent;

    static int32 CollectiblesRemaining;
    static void UpdateCollectibles();
};