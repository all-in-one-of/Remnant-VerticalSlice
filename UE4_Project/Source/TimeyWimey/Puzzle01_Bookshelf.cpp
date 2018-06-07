#include "Puzzle01_Bookshelf.h"

APuzzle01_Bookshelf::APuzzle01_Bookshelf()
: StartPosition(EBookshelfPositionPast::BOOKSHELF_RIGHT)
{
	SetStartValueBookshelfDataPast((int)EBookshelfPositionPast::BOOKSHELF_LEFT, FVector(-7049.26416, -147.416321f, 10000.839844f), FRotator(0.f, 180.f, 0.f));
	SetStartValueBookshelfDataPast((int)EBookshelfPositionPast::BOOKSHELF_MIDDLE, FVector(-8150.07959f, -147.416321f, 10000.839844f), FRotator(0.f, 180.f, 0.f));
	SetStartValueBookshelfDataPast((int)EBookshelfPositionPast::BOOKSHELF_RIGHT, FVector(-8852.035156f, -147.416321f, 10000.839844f), FRotator(0.f, 180.f, 0.f));

	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_LEFT_HIGH, FVector(-7049.26416f, -133.816177f, -114.383659f), FRotator(0.f, 0.f, -44.254944f));
	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_LEFT_MIDDLE, FVector(-7049.26416f, -187.495071, -114.383659f), FRotator(0.f, 0.f, -24.65209f));
	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_LEFT_LOW, FVector(-7049.26416f, -187.495071f, -114.383659f), FRotator(-4.182432f, 0.f, -8.735152f));
	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_MIDDLE, FVector(-8150.080078f, -185.646927f, -114.3825f), FRotator(14.960928f, -0.897583f, -25.156158f));
	SetStartValueBookshelfDataPresent((int)EBookshelfPositionPresent::BOOKSHELF_RIGHT, FVector(-8852.035156f, -205.443604f, -2.499939f), FRotator(0.f, 0.f, 0.f));
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
			SetBookshelfPositionPresent((int)EBookshelfPositionPast::BOOKSHELF_LEFT);

			UE_LOG(LogTemp, Warning, TEXT("LEFT"))
		}
		else if (CurrentPosition == (int)EBookshelfPositionPast::BOOKSHELF_MIDDLE)
		{
			SetBookshelfPositionPresent((int)EBookshelfPositionPast::BOOKSHELF_MIDDLE);

			UE_LOG(LogTemp, Warning, TEXT("MIDDLE"))
		}
		else if (CurrentPosition == (int)EBookshelfPositionPast::BOOKSHELF_RIGHT)
		{
			SetBookshelfPositionPresent((int)EBookshelfPositionPast::BOOKSHELF_RIGHT);

			UE_LOG(LogTemp, Warning, TEXT("RIGHT"))
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