// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractorComponent.h"

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "InteractableActor.h"
#include "PickupActor.h"
#include "InteractComponent.h"
#include "InventoryComponent.h"
#include "PlayerFPP_Character.h"

#define OUT

UInteractorComponent::UInteractorComponent()
: InteractRange(350.f)
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UInteractorComponent::BeginPlay()
{
	Super::BeginPlay();
	
	player = Cast<APlayerFPP_Character>(GetOwner());
	if (!player)
		UE_LOG(LogTemp, Error, TEXT("Failed to get player!"))
}

FHitResult UInteractorComponent::LineTrace()
{
	UWorld* world = GetWorld();

	FVector vp_location;
	FRotator vp_rotation;
	world->GetFirstPlayerController()->GetPlayerViewPoint(OUT vp_location, OUT vp_rotation);

	FHitResult hit_result;
	const FVector trace_start = vp_location;
	const FVector trace_end = vp_location + vp_rotation.Vector() * InteractRange;
	const FCollisionQueryParams query_params(TEXT(""), false, player);

	world->LineTraceSingleByObjectType(OUT hit_result, trace_start, trace_end, ECC_GameTraceChannel1, query_params);

	return hit_result;
}

void UInteractorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FHitResult hit = LineTrace();
	if (hit.GetActor())
	{
		looking_at_object.Broadcast(hit.GetActor());
		trace_hit.Broadcast(true);
	}
	else
		trace_hit.Broadcast(false);

}

void UInteractorComponent::AttemptInteract()
{
	FHitResult hit = LineTrace();
	if (hit.GetActor())
	{
		const AInteractableActor* InteractableActor = Cast<AInteractableActor>(hit.GetActor());

		if (InteractableActor)
		{
			UInteractComponent* InteractComponent = InteractableActor->FindComponentByClass<UInteractComponent>();

			if (InteractComponent)
			{
				/// Add to inventory
				if (InteractableActor->GetInteractableType() == EInteractableType::INTERACTABLE_PICK_UP)
				{
					UInventoryComponent* Inventory = GetOwner()->FindComponentByClass<UInventoryComponent>();
					const APickUpActor* PickUp = Cast<APickUpActor>(InteractableActor);

					if (Inventory && PickUp)
					{
						on_pickup.Broadcast();
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