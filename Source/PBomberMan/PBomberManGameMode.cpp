// Copyright Epic Games, Inc. All Rights Reserved.

#include "PBomberManGameMode.h"
#include "PBomberManCharacter.h"
#include "UObject/ConstructorHelpers.h"

APBomberManGameMode::APBomberManGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
