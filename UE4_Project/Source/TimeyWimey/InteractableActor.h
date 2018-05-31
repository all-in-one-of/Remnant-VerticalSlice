// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableActor.generated.h"

class UStaticMeshComponent;
class USphereComponent;
class UInteractComponent;

UCLASS()
class TIMEYWIMEY_API AInteractableActor : public AActor
{
	GENERATED_BODY()
	
public:	

	AInteractableActor();

protected:
	
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	USphereComponent* SphereComponent;

	// This component should be added in C++, however, for some reason I cannot add blueprint event dispatcher from a component which is not added by blueprint. Fix this in future.
	// UInteractComponent* InteractComponent;
	
};
