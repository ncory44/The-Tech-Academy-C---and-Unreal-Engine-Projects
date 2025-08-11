// Copyright Epic Games, Inc. All Rights Reserved.


#include "SimpleCollectorGamePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "SimpleCollectorGameCameraManager.h"

ASimpleCollectorGamePlayerController::ASimpleCollectorGamePlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = ASimpleCollectorGameCameraManager::StaticClass();
}

void ASimpleCollectorGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
