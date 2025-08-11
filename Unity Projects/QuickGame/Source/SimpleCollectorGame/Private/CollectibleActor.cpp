// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectibleActor.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

int32 ACollectibleActor::CollectiblesRemaining = 5;

ACollectibleActor::ACollectibleActor()
{
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;
    MeshComponent->SetCollisionProfileName(TEXT("OverlapAll"));
    MeshComponent->OnComponentBeginOverlap.AddDynamic(this, &ACollectibleActor::OnOverlapBegin);
}

void ACollectibleActor::BeginPlay()
{
    Super::BeginPlay();
}

void ACollectibleActor::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
    if (OtherActor == UGameplayStatics::GetPlayerPawn(this, 0))
    {
        CollectiblesRemaining--;
        UpdateCollectibles();
        Destroy();
    }
}

void ACollectibleActor::UpdateCollectibles()
{
    if (CollectiblesRemaining <= 0)
    {
        APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GWorld, 0);
        if (PlayerController)
        {
            PlayerController->bShowMouseCursor = true;
            PlayerController->SetInputMode(FInputModeUIOnly());
            UGameplayStatics::OpenLevel(GWorld, TEXT("WinLevel"));
        }
    }
}