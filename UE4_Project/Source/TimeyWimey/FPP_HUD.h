// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

//#include "../Engine/Public/CanvasItem.h"
//#include "../Engine/Classes/Engine/Canvas.h"	

#include "FPP_HUD.generated.h"

UCLASS()
class AFPP_HUD : public AHUD
{
	GENERATED_BODY()


public:

	AFPP_HUD();

	virtual void DrawHUD() override;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FPP_HUD)
	//UFont* default_font;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FPP_HUD)
	//	float default_font_scale;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FPP_HUD)
	//	float global_hud_multiplier;

	//FORCEINLINE static FCanvasTextItem& DrawText2D(const FString& text, const float& x, const float& y, const FLinearColor& color, const float& scale,
	//	UFont* font, bool draw_outline = false, const FLinearColor outline_color = FLinearColor(0.0f, 0.0f, 0.0f, 1.0f))
	//{
	//	FCanvasTextItem new_text(FVector2D(x, y), FText::FromString(text), font, color);
	//	new_text.Scale.Set(scale, scale);

	//	new_text.bOutlined = true;
	//	new_text.OutlineColor = outline_color;
	//	
	//	return new_text;
	//	//Canvas->DrawItem(new_text);
	//}

private:

	class UTexture2D* CrosshairTexture;

};

