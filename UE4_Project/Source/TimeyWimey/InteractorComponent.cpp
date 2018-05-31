// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractorComponent.h"

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "InteractableActor.h"
#include "InteractComponent.h"

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
		UInteractComponent* InteractComponent = InteractableActor->FindComponentByClass<UInteractComponent>();

		if (InteractComponent)
		{
			InteractComponent->RequestInteract();
		}
	}
}