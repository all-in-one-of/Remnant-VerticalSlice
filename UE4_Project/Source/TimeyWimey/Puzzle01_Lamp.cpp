#include "Puzzle01_Lamp.h"

APuzzle01_Lamp::APuzzle01_Lamp()
: StartPosition(ELampPosition::LAMP_HIGH)
{
	SetPresetsDefaultValues();

	/// Plz no touch this horrible code, its just hard coded presets for the Lamp positions
	SetStartValueLampDataPast((int)ELampPosition::LAMP_HIGH, PastPositionHigh, PastRotationHigh);
	SetStartValueLampDataPast((int)ELampPosition::LAMP_MIDDLE, PastPositionMiddle, PastRotationMiddle);
	SetStartValueLampDataPast((int)ELampPosition::LAMP_LOW, PastPositionLow, PastRotationLow);

	SetStartValueLampDataPresent((int)ELampPosition::LAMP_HIGH, PresentPositionHigh, PresentRotationHigh);
	SetStartValueLampDataPresent((int)ELampPosition::LAMP_MIDDLE, PresentPositionMiddle, PresentRotationMiddle);
	SetStartValueLampDataPresent((int)ELampPosition::LAMP_LOW, PresentPositionLow, PresentRotationLow);
}

void APuzzle01_Lamp::BeginPlay()
{
	Super::BeginPlay();

	CurrentPosition = (int)StartPosition;
	SetLampPositions();
}

void APuzzle01_Lamp::MoveDown()
{
	if (CurrentPosition == (int)ELampPosition::LAMP_LOW)
	{
		return;
	}

	CurrentPosition -= 1;
	SetLampPositions();
}

void APuzzle01_Lamp::MoveUp()
{
	if (CurrentPosition == (int)ELampPosition::LAMP_HIGH)
	{
		return;
	}

	CurrentPosition += 1;
	SetLampPositions();
}

void APuzzle01_Lamp::SetStartValueLampDataPresent(int LampIndex, FVector Pos, FRotator Rot)
{
	FLampData LampData;

	PositionPresetsPresent[LampIndex].Position = Pos;
	PositionPresetsPresent[LampIndex].Rotation = Rot;
}

void APuzzle01_Lamp::SetStartValueLampDataPast(int LampIndex, FVector Pos, FRotator Rot)
{
	FLampData LampData;

	PositionPresetsPast[LampIndex].Position = Pos;
	PositionPresetsPast[LampIndex].Rotation = Rot;
}

void APuzzle01_Lamp::SetLampPositions()
{
	SetLampPositionPast(CurrentPosition);

	if (LampInPresent)
	{
		SetLampPositionPresent(CurrentPosition);
	}
}

void APuzzle01_Lamp::SetLampPositionPresent(int LampIndex)
{
	LampInPresent->SetActorLocation(PositionPresetsPresent[LampIndex].Position);
	LampInPresent->SetActorRotation(PositionPresetsPresent[LampIndex].Rotation);
}

void APuzzle01_Lamp::SetLampPositionPast(int LampIndex)
{
	SetActorLocation(PositionPresetsPast[LampIndex].Position);
	SetActorRotation(PositionPresetsPast[LampIndex].Rotation);
}

void APuzzle01_Lamp::SetPresetsDefaultValues()
{
	/// Past
	PastPositionHigh.Set(-7050.f, -170.f, 10575.5f); PastRotationHigh = FRotator(0.f, 0.f, 0.f);
	PastPositionMiddle.Set(-7950.f, -170.f, 10575.5f); PastRotationMiddle = FRotator(0.f, 0.f, 0.f);
	PastPositionLow.Set(-8787.f, -170.f, 10575.5f); PastRotationLow = FRotator(0.f, 0.f, 0.f);

	/// Present
	PresentPositionHigh.Set(-7050.f, 398.87f, 229.6f);  PresentRotationHigh = FRotator(0.f, 0.f, -110.f);
	PresentPositionMiddle.Set(-7050.f, 406.579132f, 33.823f);  PresentRotationMiddle = FRotator(0.f, 0.f, -90.f);
	PresentPositionLow.Set(-7050.f, 444.596954f, -169.25676f);  PresentRotationLow = FRotator(0.f, 0.f, -68.f);
}