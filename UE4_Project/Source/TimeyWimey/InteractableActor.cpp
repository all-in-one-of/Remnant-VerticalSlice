// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractableActor.h"

AInteractableActor::AInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AInteractableActor::OnInteract()
{
	OnInteractEvent.Broadcast();
}

void AInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}