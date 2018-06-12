#include "Puzzle01_Machine.h"

APuzzle01_Machine::APuzzle01_Machine()
: IsStarted(false)
{ 	

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