// Fill out your copyright notice in the Description page of Project Settings.

#include "PickUpActor.h"

APickUpActor::APickUpActor()
: AInteractableActor()
, PickUpName(TEXT("Enter pickup string name here please"))
{

}

void APickUpActor::BeginPlay()
{
	Super::BeginPlay();
}