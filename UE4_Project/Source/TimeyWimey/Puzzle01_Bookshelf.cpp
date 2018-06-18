#include "Puzzle01_Bookshelf.h"

#include "Puzzle01_Lamp.h"

APuzzle01_Bookshelf::APuzzle01_Bookshelf()
: StartPosition(EBookshelfPositionPast::BOOKSHELF_RIGHT)
{
	SetPresetsDefaultValues();

	/// Plz no touch this horrible code, its just hard coded presets for the bookshelf positions
	SetStartValueBookshelfDataPast((int)EBookshelfPositionPast::BOOKSHELF_LEFT, PastPositionLeft, PastRotationLeft);
	SetStartValueBookshelfDataPast((int)EBookshelfPositionPast::BOOKSHELF_MIDDLE, PastPositionMiddle, PastRotationMiddle);
	SetStartValueBookshelfDataPast((int)EBookshelfPositionPast::BOOKSHELF_RIGHT, PastPositionRight, PastRotationRight);

	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_LEFT_HIGH, PresentPositionLeftHigh, PresentRotationLeftHigh);
	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_LEFT_MIDDLE, PresentPositionLeftMiddle, PresentRotationLeftMiddle);
	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_LEFT_LOW, PresentPositionLeftLow, PresentRotationLeftLow);
	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_MIDDLE, PresentPositionMiddle, PresentRotationMiddle);
	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_RIGHT, PresentPositionRight, PresentRotationRight);
}

void APuzzle01_Bookshelf::BeginPlay()
{
	Super::BeginPlay();

	CurrentPosition = (int)StartPosition;
	SetBookshelfPositions();
}

void APuzzle01_Bookshelf::MoveLeft()
{
	if (CurrentPosition == (int)EBookshelfPositionPast::BOOKSHELF_LEFT)
	{
		return;
	}

	CurrentPosition -= 1;
	SetBookshelfPositions();
}

void APuzzle01_Bookshelf::MoveRight()
{
	if (CurrentPosition == (int)EBookshelfPositionPast::BOOKSHELF_RIGHT)
	{
		return;
	}

	CurrentPosition += 1;
	SetBookshelfPositions();
}

void APuzzle01_Bookshelf::SetStartValueBookshelfDataPresent(int BookshelfIndex, FVector Pos, FRotator Rot)
{
	FBookshelfData BookshelfData;

	PositionPresetsPresent[BookshelfIndex].Position = Pos;
	PositionPresetsPresent[BookshelfIndex].Rotation = Rot;
}

void APuzzle01_Bookshelf::SetStartValueBookshelfDataPast(int BookshelfIndex, FVector Pos, FRotator Rot)
{
	FBookshelfData BookshelfData;

	PositionPresetsPast[BookshelfIndex].Position = Pos;
	PositionPresetsPast[BookshelfIndex].Rotation = Rot;
}

void APuzzle01_Bookshelf::SetBookshelfPositions()
{
	SetBookshelfPositionPast(CurrentPosition);

	if (BookshelfInPresent)
	{
		if (CurrentPosition == (int)EBookshelfPositionPast::BOOKSHELF_LEFT)
		{
			if (Lamp)
			{
				if (Lamp->GetPosition() == (int)ELampPosition::LAMP_HIGH)
				{
					SetBookshelfPositionPresent((int)EBookshelfPositionPresent::BOOKSHELF_LEFT_LOW);
				}
				else if (Lamp->GetPosition() == (int)ELampPosition::LAMP_MIDDLE)
				{
					SetBookshelfPositionPresent((int)EBookshelfPositionPresent::BOOKSHELF_LEFT_HIGH);
				}
				else if (Lamp->GetPosition() == (int)ELampPosition::LAMP_LOW)
				{
					SetBookshelfPositionPresent((int)EBookshelfPositionPresent::BOOKSHELF_LEFT_MIDDLE);
				}
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("Linked Actor lamp in Puzzle01_Bookshelf actor is nullptr"))
			}
		}
		else if (CurrentPosition == (int)EBookshelfPositionPast::BOOKSHELF_MIDDLE)
		{
			SetBookshelfPositionPresent((int)EBookshelfPositionPresent::BOOKSHELF_MIDDLE);
		}
		else if (CurrentPosition == (int)EBookshelfPositionPast::BOOKSHELF_RIGHT)
		{
			SetBookshelfPositionPresent((int)EBookshelfPositionPresent::BOOKSHELF_RIGHT);
		}
	}
}

void APuzzle01_Bookshelf::SetBookshelfPositionPresent(int BookshelfIndex)
{
	BookshelfInPresent->SetActorLocation(PositionPresetsPresent[BookshelfIndex].Position);
	BookshelfInPresent->SetActorRotation(PositionPresetsPresent[BookshelfIndex].Rotation);
}

void APuzzle01_Bookshelf::SetBookshelfPositionPast(int BookshelfIndex)
{
	SetActorLocation(PositionPresetsPast[BookshelfIndex].Position);
	SetActorRotation(PositionPresetsPast[BookshelfIndex].Rotation);
}

void APuzzle01_Bookshelf::SetPresetsDefaultValues()
{
		/// Past
		PastPositionLeft.Set(-7050.f, -170.f, 10000.f); PastRotationLeft = FRotator(0.f, 180.f, 0.f);
		PastPositionMiddle.Set(-7950.f, -170.f, 10000.f); PastRotationMiddle = FRotator(0.f, 180.f, 0.f);
		PastPositionRight.Set(-8787.f, -170.f, 10000.f); PastRotationRight = FRotator(0.f, 180.f, 0.f);

		/// Present
		PresentPositionLeftHigh.Set(-7050.f, 942.65f, 370.9f);  PresentRotationLeftHigh = FRotator(0.f, 0.f, -110.f);
		PresentPositionLeftMiddle.Set(-7050.f, 1000.f, 2.5f);  PresentRotationLeftMiddle = FRotator(0.f, 0.f, -90.f);
		PresentPositionLeftLow.Set(-7050.f, 900.15f, -410.f);  PresentRotationLeftLow = FRotator(0.f, 0.f, -68.f);
		PresentPositionMiddle.Set(-7950.f, -130.f, 30.f);  PresentRotationMiddle = FRotator(-5.f, 180.f, -96.f);
		PresentPositionRight.Set(-8771.668945f, 922.4f, -423.f);  PresentRotationRight = FRotator(0.f, 0.f, -68.0f);
}