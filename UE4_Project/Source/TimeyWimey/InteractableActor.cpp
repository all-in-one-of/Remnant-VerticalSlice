// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractableActor.h"

#include "Components/SphereComponent.h"
#include "InteractComponent.h"

AInteractableActor::AInteractableActor()
{
	/// Set up Sphere Component
	FName SphereComponentName = TEXT("SphereCollision");
	bool EnableOverlapEvents = true;
	FName CollisionProfileName = TEXT("Interactable");
	const float DefaultSphereRadius = 100.f;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(SphereComponentName);
	SphereComponent->SetCollisionProfileName(CollisionProfileName);
	SphereComponent->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	SphereComponent->bGenerateOverlapEvents = EnableOverlapEvents;
	SphereComponent->SetSphereRadius(DefaultSphereRadius);
	SphereComponent->SetupAttachment(RootComponent);	
	RootComponent = SphereComponent;

	// This component should be added in C++, however, for some reason I cannot add blueprint event dispatcher from a component which is not added by blueprint. Fix this in future.
	/*/// Set up Interact Component
	FName InteractComponentName = TEXT("InteractComponent");

	InteractComponent = CreateDefaultSubobject<UInteractComponent>(InteractComponentName);*/
}

void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
}