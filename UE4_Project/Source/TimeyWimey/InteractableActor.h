// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteract);

UCLASS()
class TIMEYWIMEY_API AInteractableActor : public AActor
{
	GENERATED_BODY()
	
public:	

	AInteractableActor();

	virtual void Tick(float DeltaTime) override;

	void OnInteract();

	FOnInteract OnInteractEvent;

protected:
	
	virtual void BeginPlay() override;
	
};
