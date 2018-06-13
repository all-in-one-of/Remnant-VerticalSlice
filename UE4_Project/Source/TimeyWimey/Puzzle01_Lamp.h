#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puzzle01_Lamp.generated.h"

UENUM()
enum class ELampPosition
{
	LAMP_LOW UMETA(DisplayName = "Low"),
	LAMP_MIDDLE UMETA(DisplayName = "Middle"),
	LAMP_HIGH UMETA(DisplayName = "High")
};

USTRUCT()
struct FLampData
{

	GENERATED_BODY()

	FVector Position;
	FRotator Rotation;
};

UCLASS()
class TIMEYWIMEY_API APuzzle01_Lamp : public AActor
{

	GENERATED_BODY()

public:

	APuzzle01_Lamp();

	int GetPosition() { return CurrentPosition; }

	UFUNCTION(BlueprintCallable)
	void MoveUp();

	UFUNCTION(BlueprintCallable)
	void MoveDown();	

protected:

	virtual void BeginPlay() override;

private:

	static const int NUM_POS_PRESETS = 3;

	void SetLampPositions();
	void SetLampPositionPast(int LampIndex);
	void SetLampPositionPresent(int LampIndex);
	void SetStartValueLampDataPresent(int LampIndex, FVector Pos, FRotator Rot);
	void SetStartValueLampDataPast(int LampIndex, FVector Pos, FRotator Rot);

	void SetPresetsDefaultValues();

	UPROPERTY(EditAnywhere, Category = "Past Presets")
	FVector PastPositionHigh;
	UPROPERTY(EditAnywhere, Category = "Past Presets")
	FVector PastPositionMiddle;
	UPROPERTY(EditAnywhere, Category = "Past Presets")
	FVector PastPositionLow;

	UPROPERTY(EditAnywhere, Category = "Past Presets")
	FRotator PastRotationHigh;
	UPROPERTY(EditAnywhere, Category = "Past Presets")
	FRotator PastRotationMiddle;
	UPROPERTY(EditAnywhere, Category = "Past Presets")
	FRotator PastRotationLow;

	UPROPERTY(EditAnywhere, Category = "Present Presets")
	FVector PresentPositionHigh;
	UPROPERTY(EditAnywhere, Category = "Present Presets")
	FVector PresentPositionMiddle;
	UPROPERTY(EditAnywhere, Category = "Present Presets")
	FVector PresentPositionLow;

	UPROPERTY(EditAnywhere, Category = "Present Presets")
	FRotator PresentRotationHigh;
	UPROPERTY(EditAnywhere, Category = "Present Presets")
	FRotator PresentRotationMiddle;
	UPROPERTY(EditAnywhere, Category = "Present Presets")
	FRotator PresentRotationLow;

	int CurrentPosition;

	UPROPERTY(EditAnywhere, Category = "Lamp Properties")
	ELampPosition StartPosition;

	FLampData PositionPresetsPast[NUM_POS_PRESETS];
	FLampData PositionPresetsPresent[NUM_POS_PRESETS];

	UPROPERTY(EditAnywhere, Category = "Lamp Properties")
	AActor* LampInPresent;
};