// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FPP_HUD.generated.h"

UCLASS()
class AFPP_HUD : public AHUD
{
	GENERATED_BODY()

public:

	AFPP_HUD();

	virtual void DrawHUD() override;

private:

	class UTexture2D* CrosshairTexture;

};

