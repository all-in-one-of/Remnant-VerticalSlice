// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractorComponent.h"

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "InteractableActor.h"
#include "PickupActor.h"
#include "InteractComponent.h"
#include "InventoryComponent.h"

#define OUT

UInteractorComponent::UInteractorComponent()
: InteractRange(200.f)
{

}

void UInteractorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInteractorComponent::AttemptInteract()
{
	UWorld* World = GetWorld();

	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	World->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation, OUT PlayerViewPointRotation);

	FHitResult HitResult;
	FVector LineStart = PlayerViewPointLocation;
	FVector LineEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * InteractRange;
	FCollisionObjectQueryParams CollisionObjectQueryParams(ECC_WorldDynamic);
	FCollisionQueryParams CollisionQueryParams(TEXT(""), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(
		OUT HitResult,
		LineStart,
		LineEnd,
		CollisionObjectQueryParams,
		CollisionQueryParams
	);

	if (HitResult.GetActor())
	{
		AInteractableActor* InteractableActor = Cast<AInteractableActor>(HitResult.GetActor());

		if (InteractableActor)
		{
			UInteractComponent* InteractComponent = InteractableActor->FindComponentByClass<UInteractComponent>();

			if (InteractComponent)
			{
				/// Add to inventory
				if (InteractableActor->GetInteractableType() == EInteractableType::INTERACTABLE_PICK_UP)
				{
					UInventoryComponent* Inventory = GetOwner()->FindComponentByClass<UInventoryComponent>();
					APickUpActor* PickUp = Cast<APickUpActor>(InteractableActor);

					if (Inventory && PickUp)
					{
						Inventory->AddItem(PickUp->GetName());
						InteractComponent->RequestInteract();
					}
				}
				else
				{
					InteractComponent->RequestInteract();
				}
			}
		}
	}
}