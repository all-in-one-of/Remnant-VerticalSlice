// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractableActor.h"

#include "Components/SphereComponent.h"
#include "InteractComponent.h"

AInteractableActor::AInteractableActor()
: InteractableType(EInteractableType::INTERACTABLE_NORMAL)
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

	/// Set up Interact Component
	FName InteractComponentName = TEXT("InteractComponent");

	InteractComponent = CreateDefaultSubobject<UInteractComponent>(InteractComponentName);
}

void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
}