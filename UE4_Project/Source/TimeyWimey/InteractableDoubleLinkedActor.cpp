#include "InteractableDoubleLinkedActor.h"

AInteractableDoubleLinkedActor::AInteractableDoubleLinkedActor()
: AInteractableActor()
{

}

void AInteractableDoubleLinkedActor::BeginPlay()
{
	Super::BeginPlay();
}

AActor* AInteractableDoubleLinkedActor::GetLinkedActorOne()
{
	if (LinkedActorOne)
	{
		return LinkedActorOne;
	}

	return nullptr;
}

AActor* AInteractableDoubleLinkedActor::GetLinkedActorTwo()
{
	if (LinkedActorTwo)
	{
		return LinkedActorTwo;
	}

	return nullptr;
}