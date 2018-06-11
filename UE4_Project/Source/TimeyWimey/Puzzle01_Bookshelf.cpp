#include "Puzzle01_Bookshelf.h"

APuzzle01_Bookshelf::APuzzle01_Bookshelf()
: StartPosition(EBookshelfPositionPast::BOOKSHELF_RIGHT)
{
	/// Plz no touch this horrible code, its just hard coded presets for the bookshelf positions
	SetStartValueBookshelfDataPast((int)EBookshelfPositionPast::BOOKSHELF_LEFT, FVector(-7050.f, -170.f, 10575.5f), FRotator(0.f, 0.f, 0.f));
	SetStartValueBookshelfDataPast((int)EBookshelfPositionPast::BOOKSHELF_MIDDLE, FVector(-7950.f, -170.f, 10575.5f), FRotator(0.f, 0.f, 0.f));
	SetStartValueBookshelfDataPast((int)EBookshelfPositionPast::BOOKSHELF_RIGHT, FVector(-8787.f, -170.f, 10575.5f), FRotator(0.f, 0.f, 0.f));

	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_LEFT_HIGH, FVector(-7050.f, 398.87f, 229.6f), FRotator(0.f, 0.f, -110.f));
	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_LEFT_MIDDLE, FVector(-7050.f, 406.579132f, 33.823f), FRotator(0.f, 0.f, -90.f));
	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_LEFT_LOW, FVector(-7050.f, 444.596954f, -169.25676f), FRotator(0.f, 0.f, -68.f));
	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_MIDDLE, FVector(-7950.f, 480.f, 34.f), FRotator(5.f, 0.f, 84.262581f));
	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_RIGHT, FVector(-8787.313477f, 458.825592f, -134.042709f), FRotator(0.f, 0.f, -68.0f));
}

void APuzzle01_Bookshelf::BeginPlay()
{
	Super::BeginPlay();

	CurrentPosition = (int)StartPosition;
	SetBookshefPositions();
}

void APuzzle01_Bookshelf::MoveLeft()
{
	if (CurrentPosition == (int)EBookshelfPositionPast::BOOKSHELF_LEFT)
	{
		return;
	}

	CurrentPosition -= 1;
	SetBookshefPositions();
}

void APuzzle01_Bookshelf::MoveRight()
{
	if (CurrentPosition == (int)EBookshelfPositionPast::BOOKSHELF_RIGHT)
	{
		return;
	}

	CurrentPosition += 1;
	SetBookshefPositions();
}

void APuzzle01_Bookshelf::SetStartValueBookshelfDataPresent(int BookshelfIndex, FVector Pos, FRotator Rot)
{
	FBookshelfData BookshelfData;

	PositionPresetsPresent[BookshelfIndex].Position = Pos;
	PositionPresetsPresent[BookshelfIndex].Rotation = Rot;
}

void APuzzle01_Bookshelf::SetStartValueBookshelfDataPast(int BookshelfIndex, FVector Pos, FRotator Rot)
{
	FBookshelfData BookshelfData;;

	PositionPresetsPast[BookshelfIndex].Position = Pos;
	PositionPresetsPast[BookshelfIndex].Rotation = Rot;
}

void APuzzle01_Bookshelf::SetBookshefPositions()
{
	SetActorLocation(
		PositionPresetsPast[CurrentPosition].Position
	);
	SetActorRotation(
		PositionPresetsPast[CurrentPosition].Rotation
	);

	if (BookshelfInPresent)
	{
		if (CurrentPosition == (int)EBookshelfPositionPast::BOOKSHELF_LEFT)
		{
			SetBookshelfPositionPresent((int)EBookshelfPositionPresent::BOOKSHELF_LEFT_LOW);

			// TODO: Make the bookshelf rotate differently depending on the lamps state.
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
	BookshelfInPresent->SetActorLocation(
		PositionPresetsPresent[BookshelfIndex].Position
	);
	BookshelfInPresent->SetActorRotation(
		PositionPresetsPresent[BookshelfIndex].Rotation
	);
}