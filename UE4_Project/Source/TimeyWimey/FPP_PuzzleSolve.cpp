// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FPP_PuzzleSolve.h"
#include "FPP_HUD.h"
#include "PlayerFPP_Character.h"
#include "UObject/ConstructorHelpers.h"

AFPP_PuzzleSolve::AFPP_PuzzleSolve()
: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/PlayerFPP_BP"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPP_HUD::StaticClass();
}
