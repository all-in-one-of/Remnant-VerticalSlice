#include "Puzzle01_Machine.h"

APuzzle01_Machine::APuzzle01_Machine()
: IsStarted(false)
{ 	
	LampOffset.Set(-600.f, 0.f, 0.f);
}

void APuzzle01_Machine::BeginPlay()
{
	Super::BeginPlay();	
}

void APuzzle01_Machine::ChangeSetting()
{
	if (!IsStarted)
	{
		return;
	}


}

void APuzzle01_Machine::ApplySetting()
{
	if (!IsStarted)
	{
		return;
	}


}

void APuzzle01_Machine::StartMachine()
{
	IsStarted = true;

	if (Lamp)
	{
		Lamp->SetActorLocation(Lamp->GetActorLocation() + LampOffset);	
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Lamp is nullptr in Puzzle01_Machine"))
	}
}