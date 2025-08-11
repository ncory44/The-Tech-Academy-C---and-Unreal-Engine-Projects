// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SimpleCollectorGameGameMode.generated.h"

/**
 *  Simple GameMode for a first person game
 */
UCLASS(abstract)
class ASimpleCollectorGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASimpleCollectorGameGameMode();
};



