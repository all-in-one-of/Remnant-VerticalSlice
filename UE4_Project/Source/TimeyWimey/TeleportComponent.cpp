// Fill out your copyright notice in the Description page of Project Settings.

#include "TeleportComponent.h"
#include "../CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerFPP_Character.h"
#include "../Engine/Classes/Components/PrimitiveComponent.h"
#include "../Engine/Classes/Engine/CollisionProfile.h"
#include "../Engine/Classes/Engine/World.h"

// Sets default values for this component's properties
UTeleportComponent::UTeleportComponent()
{
}


// Called when the game starts
void UTeleportComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UTeleportComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
}

void UTeleportComponent::Teleport(EDimension dimension, const FVector location)
{
	auto player = Cast<APlayerFPP_Character>(GetOwner());
	player->SetActorLocation(location);
	player->SetDimension(dimension);
}

void UTeleportComponent::TraverseDimension()
{
	// Get Player
	auto player = Cast<APlayerFPP_Character>(GetOwner());
	const FVector player_pos = player->GetActorLocation();
	static const float teleport_amount = 10000.0f;

	FCollisionQueryParams trace_params;
	FVector trace_end = player_pos;
	EDimension dimension = player->GetDimension();

	if (dimension == EDimension::LOWER)
	{
		// Setup trace params
		trace_params = FCollisionQueryParams(FName(TEXT("Prop_D2")), true, player);
		trace_params.bTraceComplex = true;
		trace_params.bTraceAsyncScene = true;
		trace_params.bReturnPhysicalMaterial = false;

		trace_end.Z += teleport_amount;
		dimension = EDimension::UPPER;
	}
	else
	{
		// Setup trace params
		trace_params = FCollisionQueryParams(FName(TEXT("Prop_D1")), true, player);
		trace_params.bTraceComplex = true;
		trace_params.bTraceAsyncScene = true;
		trace_params.bReturnPhysicalMaterial = false;

		trace_end.Z -= teleport_amount;
		dimension = EDimension::LOWER;
	}

	TArray<FHitResult> hit;
	if (!GetWorld()->LineTraceMultiByObjectType(hit, player_pos, trace_end, ECC_WorldStatic, trace_params))
		Teleport(dimension, trace_end);

	// TODO: Add screen shake / fade before teleporting
}

