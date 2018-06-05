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

	// Set the new dimension to the not active dimension
	EDimension new_dimension = player->GetDimension() == EDimension::LOWER ? EDimension::UPPER : EDimension::LOWER;
	player->SetDimension(new_dimension);

	UE_LOG(LogTemp, Warning, TEXT("Teleporting player to position: %s"), *location.ToString());
}

void UTeleportComponent::TraverseDimension()
{
	// Get Player & pos
	auto player = Cast<APlayerFPP_Character>(GetOwner());
	const FVector player_pos = player->GetActorLocation();

	// Set some constants
	static const float teleport_amount = 10000.0f;
	static const float trace_length = 10500.0f;

	// Create needed variables and default them
	FVector new_pos = player_pos;
	FVector trace_end = player_pos;
	EDimension dimension = player->GetDimension();

	// Setup trace params
	FCollisionQueryParams query_params(TEXT(""), true, player);
	query_params.bTraceComplex = true;
	query_params.bTraceAsyncScene = true;
	query_params.bReturnPhysicalMaterial = false;

	FHitResult hit;

	// Setup capsule shape for SweepSingleByObjectType
	const FVector extent(player->GetCapsuleComponent()->GetCollisionShape().Capsule.Radius);
	const FCollisionShape shape = FCollisionShape::MakeCapsule(extent);
	const FQuat quat = FQuat(player->GetActorRotation());

	// TODO: Add screen shake / fade before teleporting

	if (dimension == EDimension::LOWER)
	{
		// Increase trace end and new pos
		trace_end.Z += trace_length;
		new_pos.Z += teleport_amount;

		// Capsule trace against D2 objects, if nothing is hit, teleport
		if (!GetWorld()->SweepSingleByObjectType(hit, player_pos, trace_end, quat, ECC_GameTraceChannel3, shape, query_params))
		{
			Teleport(dimension, new_pos);
			return;
		}
	}
	else
	{
		// Decrease trace end and new pos
		trace_end.Z -= trace_length;
		new_pos.Z -= teleport_amount;

		// Capsule trace against D1 objects, if nothing is hit, teleport
		if (!GetWorld()->SweepSingleByObjectType(hit, player_pos, trace_end, quat, ECC_GameTraceChannel2, shape, query_params))
		{
			Teleport(dimension, new_pos);
			return;
		}
	}

	// If the ray hit something, pop text to the screen
	DenyTeleport();
}

void UTeleportComponent::DenyTeleport()
{
	auto player = Cast<APlayerFPP_Character>(GetOwner());
	const FColor color = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f).ToFColor(true);
	const float duration(3.0f);
	bool draw_shadow(true);

	// TODO: Change debug to actual text rendering. AHUD::DrawText
	//DrawDebugString(GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::ReturnNull), player->GetActorLocation(), *FString(TEXT("Something is blocking your way")), NULL, color, duration, draw_shadow);
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, color, TEXT("Something is blocking your way"));
	//UCanvas* canvas = GetWorld()->GetCanvasForDrawMaterialToRenderTarget();
	//canvas->DrawItem(AFPP_HUD::DrawText2D(TEXT("LOL"), 0.0f, 0.0f, color, 1.0f, DEFAULT_GUI_FONT));
}

