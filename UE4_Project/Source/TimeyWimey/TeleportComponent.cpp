// Fill out your copyright notice in the Description page of Project Settings.

#include "TeleportComponent.h"
#include "../CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerFPP_Character.h"
#include "../Engine/Classes/Components/PrimitiveComponent.h"
#include "../Engine/Classes/Engine/CollisionProfile.h"
#include "../Engine/Public/WorldCollision.h"
#include "../Engine/Classes/Engine/World.h"
#include "../Engine/Classes/Engine/Engine.h"
#include "../Engine/Public/DrawDebugHelpers.h"
#include "../Engine/Classes/GameFramework/HUD.h"
#include "../Engine/Classes/GameFramework/Character.h"
#include "../Engine/Classes/Components/SphereComponent.h"
#include "../Engine/Classes/Components/CapsuleComponent.h"
#include "FPP_HUD.h"
#include "../Engine/Classes/GameFramework/HUD.h"
#include "../Engine/Classes/Camera/CameraComponent.h"

// Sets default values for this component's properties
UTeleportComponent::UTeleportComponent()
{
	//PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UTeleportComponent::BeginPlay()
{
	Super::BeginPlay();

	player = Cast<APlayerFPP_Character>(GetOwner());
	if (!player)
		UE_LOG(LogTemp, Error, TEXT("Failed to get player!"));
}

// Called every frame
void UTeleportComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTeleportComponent::Teleport(const FVector location)
{
	player->SetActorLocation(location);

	// Set the new dimension to the not active dimension
	const EDimension new_dimension = player->GetDimension() == EDimension::LOWER ? EDimension::UPPER : EDimension::LOWER;
	player->SetDimension(new_dimension);

	UE_LOG(LogTemp, Warning, TEXT("Teleporting player to position: %s"), *location.ToString());
}

bool UTeleportComponent::TryTeleport()
{
	const EDimension dimension = player->GetDimension();

	const FVector trace_start = player->GetActorLocation();
	const FVector trace_end = trace_start + FVector(0.0f, 0.0f, (dimension == EDimension::LOWER ? trace_length : -trace_length));

	FHitResult hit;
	const FCollisionQueryParams query_params(TEXT(""), true, player);
	const FCollisionObjectQueryParams object_query_params = dimension == EDimension::LOWER ? ECC_GameTraceChannel3 : ECC_GameTraceChannel2;

	// Setup capsule shape for SweepSingleByObjectType
	const FVector extent(player->GetCapsuleComponent()->GetCollisionShape().Capsule.Radius);
	const FCollisionShape shape = FCollisionShape::MakeCapsule(extent);
	const FQuat quat = FQuat(player->GetActorRotation());

	if (!GetWorld()->SweepSingleByObjectType(hit, trace_start, trace_end, quat, object_query_params, shape, query_params))
		return true;

	return false;
}

void UTeleportComponent::TraverseDimension()
{
	const FVector player_pos = player->GetActorLocation();
	const FVector new_pos = player_pos + FVector(0.0f, 0.0f, (player->GetDimension() == EDimension::LOWER ? teleport_amount : -teleport_amount));

	// TODO: Add screen shake / fade before teleporting
	if (TryTeleport())
		Teleport(new_pos);
	else
		DenyTeleport();
}

void UTeleportComponent::DenyTeleport()
{
	const FColor color = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f).ToFColor(true);

	// TODO: Change debug to actual text rendering. AHUD::DrawText
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, color, TEXT("Something is blocking your way"));
}