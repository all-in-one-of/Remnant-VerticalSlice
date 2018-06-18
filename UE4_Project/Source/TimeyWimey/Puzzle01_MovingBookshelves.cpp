#include "Puzzle01_MovingBookshelves.h"

#define OUT

APuzzle01_MovingBookshelves::APuzzle01_MovingBookshelves()
: IsActive(false)
, SequenceActiveTimer(0.f)
, SequenceActiveDuration(10.f)
, CurrentSequence(1)
{
	PrimaryActorTick.bCanEverTick = true;

	DeltaBookshelfMovement = FVector(100.f, 0.f, 0.f);
}

void APuzzle01_MovingBookshelves::BeginPlay()
{
	Super::BeginPlay();
	
}

void APuzzle01_MovingBookshelves::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!IsActive)
	{
		return;
	}

	if (SequenceActiveTimer >= SequenceActiveDuration)
	{
		EndSequence();
	}

	SequenceActiveTimer += DeltaTime;
}

void APuzzle01_MovingBookshelves::StartSequence()
{
	if (IsActive)
	{
		return;
	}

	SequenceActiveTimer = 0.f;
	IsActive = true;

	OpenBookshelves();
}

void APuzzle01_MovingBookshelves::EndSequence()
{
	if (!IsActive)
	{
		return;
	}

	IsActive = false;

	CloseBookshelves();
}

void APuzzle01_MovingBookshelves::OpenBookshelves()
{
	TArray<AActor*> AffectedBookshelves;
	GetBookshelvesAffectedBySequence(OUT AffectedBookshelves);

	for (AActor* Bookshelf : AffectedBookshelves)
	{
		FVector BookshelfLocation = Bookshelf->GetActorLocation();
		Bookshelf->SetActorLocation(BookshelfLocation + DeltaBookshelfMovement);
	}

	if (CurrentSequence == 2 && FinishDoor)
	{
		FinishDoor->SetActorLocation(FinishDoor->GetActorLocation() + FinishDoorOffset);
	}
}

void APuzzle01_MovingBookshelves::CloseBookshelves()
{
	TArray<AActor*> AffectedBookshelves;
	GetBookshelvesAffectedBySequence(OUT AffectedBookshelves);

	for (AActor* Bookshelf : AffectedBookshelves)
	{
		FVector BookshelfLocation = Bookshelf->GetActorLocation();
		Bookshelf->SetActorLocation(BookshelfLocation - DeltaBookshelfMovement);
	}

	if (CurrentSequence == 2 && FinishDoor)
	{
		FinishDoor->SetActorLocation(FinishDoor->GetActorLocation() - FinishDoorOffset);
	}
}

void APuzzle01_MovingBookshelves::GetBookshelvesAffectedBySequence(TArray<AActor*>& OutAffectedBookshelves)
{
	OutAffectedBookshelves = (CurrentSequence == 1) ? BookshelvesSequenceOne : BookshelvesSequenceTwo;
}