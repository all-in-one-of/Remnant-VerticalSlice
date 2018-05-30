// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TimeyWimeyGameMode.h"
#include "TimeyWimeyHUD.h"
#include "TimeyWimeyCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATimeyWimeyGameMode::ATimeyWimeyGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATimeyWimeyHUD::StaticClass();
}
