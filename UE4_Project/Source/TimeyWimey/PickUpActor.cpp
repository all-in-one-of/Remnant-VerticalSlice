// Fill out your copyright notice in the Description page of Project Settings.

#include "PickUpActor.h"

APickUpActor::APickUpActor()
: AInteractableActor()
, PickUpName(TEXT("Enter pickup string name here please"))
{
	InteractableType = EInteractableType::INTERACTABLE_PICK_UP;
}

void APickUpActor::BeginPlay()
{
	Super::BeginPlay();
}