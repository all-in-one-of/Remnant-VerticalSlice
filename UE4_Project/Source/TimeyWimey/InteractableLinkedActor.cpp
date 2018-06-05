// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractableLinkedActor.h"

AInteractableLinkedActor::AInteractableLinkedActor()
: AInteractableActor()
{
	
}

void AInteractableLinkedActor::BeginPlay()
{
	Super::BeginPlay();
}

AActor* AInteractableLinkedActor::GetLinkedActor()
{
	if (LinkedActor)
	{
		return LinkedActor;
	}

	return nullptr;
}