#include "Puzzle01_MovingBookshelves.h"

APuzzle01_MovingBookshelves::APuzzle01_MovingBookshelves()
: IsActive(false)
, SequenceActiveTimer(0.f)
, SequenceActiveDuration(10.f)
, CurrentSequence(1)
{
	PrimaryActorTick.bCanEverTick = true;

	DeltaBookshelfMovement = FVector(100.f, 0.f, 0.f);
}

// Called when the game starts or when spawned
void APuzzle01_MovingBookshelves::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuzzle01_MovingBookshelves::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APuzzle01_MovingBookshelves::StartSequence()
{
	if (IsActive)
	{
		return;
	}

	SequenceActiveTimer = 0.f;
	IsActive = true;
}

void APuzzle01_MovingBookshelves::EndSequence()
{
	if (!IsActive)
	{
		return;
	}

	IsActive = false;
}

void APuzzle01_MovingBookshelves::OpenBookshelves()
{

}

void APuzzle01_MovingBookshelves::CloseBookshelves()
{

}