#include "Puzzle01_Bookshelf.h"

APuzzle01_Bookshelf::APuzzle01_Bookshelf()
: StartPosition(EBookshelfPositionPast::BOOKSHELF_RIGHT)
{
	SetStartValueBookshelfDataPast((int)EBookshelfPositionPast::BOOKSHELF_LEFT, FVector(-7050.f, -170.f, 10583.f), FVector(180.f, 0.f, 0.f));
	SetStartValueBookshelfDataPast((int)EBookshelfPositionPast::BOOKSHELF_MIDDLE, FVector(-7950.0, -170.f, 10583.f), FVector(180.f, 0.f, 0.f));
	SetStartValueBookshelfDataPast((int)EBookshelfPositionPast::BOOKSHELF_RIGHT, FVector(-8787.f, -170.f, 10583.f), FVector(180.f, 0.f, 0.f));

	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_LEFT_HIGH, FVector(-7050.f, 400.f, 230.f), FVector(-110.f, 0.f, 0.f));
	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_LEFT_MIDDLE, FVector(-7050.f, 407.f, 34.f), FVector(-90.f, 0.f, 0.f));
	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_LEFT_LOW, FVector(-7051.5f, 445.f, -170.f), FVector(-68.f, 0.f, 0.f));
	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_MIDDLE, FVector(-7950.f, 448.f, 34.f), FVector(-90.f, 0.f, 0.f));
	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_RIGHT, FVector(-8787.f, 445.f, -169.f), FVector(-68.f, 0.f, 0.f));
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

void APuzzle01_Bookshelf::SetStartValueBookshelfDataPresent(int BookshelfIndex, FVector Pos, FVector Rot)
{
	FBookshelfData BookshelfData;

	FRotator Rotator;
	Rotator.MakeFromEuler(Rot);

	PositionPresetsPresent[BookshelfIndex].Position = Pos;
	PositionPresetsPresent[BookshelfIndex].Rotation = Rotator;
}

void APuzzle01_Bookshelf::SetStartValueBookshelfDataPast(int BookshelfIndex, FVector Pos, FVector Rot)
{
	FBookshelfData BookshelfData;

	FRotator Rotator;
	Rotator.MakeFromEuler(Rot);

	PositionPresetsPast[BookshelfIndex].Position = Pos;
	PositionPresetsPast[BookshelfIndex].Rotation = Rotator;
}

void APuzzle01_Bookshelf::SetBookshefPositions()
{
	SetActorLocation(
		PositionPresetsPast[CurrentPosition].Position
	);
	SetActorRotation(
		PositionPresetsPast[CurrentPosition].Rotation
	);

	UE_LOG(LogTemp, Warning, TEXT("%i"), CurrentPosition)

	if (BookshelfInPresent)
	{
		if (CurrentPosition == (int)EBookshelfPositionPast::BOOKSHELF_LEFT)
		{
			BookshelfInPresent->SetActorLocation(
				PositionPresetsPresent[(int)EBookshelfPositionPresent::BOOKSHELF_LEFT_MIDDLE].Position
			);
			BookshelfInPresent->SetActorRotation(
				PositionPresetsPresent[(int)EBookshelfPositionPresent::BOOKSHELF_LEFT_MIDDLE].Rotation
			);
		}
		else if (CurrentPosition == (int)EBookshelfPositionPast::BOOKSHELF_MIDDLE)
		{
			BookshelfInPresent->SetActorLocation(
				PositionPresetsPresent[(int)EBookshelfPositionPresent::BOOKSHELF_MIDDLE].Position
			);
			BookshelfInPresent->SetActorRotation(
				PositionPresetsPresent[(int)EBookshelfPositionPresent::BOOKSHELF_MIDDLE].Rotation
			);
		}
		else if (CurrentPosition == (int)EBookshelfPositionPast::BOOKSHELF_RIGHT)
		{
			BookshelfInPresent->SetActorLocation(
				PositionPresetsPresent[(int)EBookshelfPositionPresent::BOOKSHELF_RIGHT].Position
			);
			BookshelfInPresent->SetActorRotation(
				PositionPresetsPresent[(int)EBookshelfPositionPresent::BOOKSHELF_RIGHT].Rotation
			);
		}
	}
}