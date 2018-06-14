#include "Puzzle01_Lamp.h"

#include "Puzzle01_Bookshelf.h"

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

	if (Bookshelf)
	{
		if (Bookshelf->GetPosition() == (int)EBookshelfPositionPast::BOOKSHELF_LEFT)
		{
			Bookshelf->SetBookshelfPositions();
		}
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
	PastPositionHigh.Set(-7050.f, -459.f, 10828.381836f); PastRotationHigh = FRotator(0.f, 0.f, 0.f);
	PastPositionMiddle.Set(-7050.f, 450.f, 10508.173828f); PastRotationMiddle = FRotator(0.f, 0.f, 0.f);
	PastPositionLow.Set(-7050.f, 450.f, 10212.046875f); PastRotationLow = FRotator(0.f, 0.f, 0.f);

	/// Present
	PresentPositionHigh.Set(-7050.f, 450.f, 1116.252319f);  PresentRotationHigh = FRotator(0.f, 0.f, 0.f);
	PresentPositionMiddle.Set(-7050.f, 625.359314f, 191.996323f);  PresentRotationMiddle = FRotator(0.f, 0.f, -90.f);
	PresentPositionLow.Set(-7050.f, 612.970093f, -80.492676f);  PresentRotationLow = FRotator(0.f, 0.f, -110.f);
}