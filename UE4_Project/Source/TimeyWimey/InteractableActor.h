// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableActor.generated.h"

class UStaticMeshComponent;
class USphereComponent;
class UInteractComponent;

UENUM()
enum class EInteractableType : uint8
{
	INTERACTABLE_NORMAL UMETA(DisplayName="Normal"),
	INTERACTABLE_PICK_UP UMETA(DisplayName="PickUp")
};

UCLASS()
class TIMEYWIMEY_API AInteractableActor : public AActor
{
	GENERATED_BODY()
	
public:	

	AInteractableActor();

	EInteractableType GetInteractableType() const { return InteractableType; }

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
	UInteractComponent* InteractComponent;

	UPROPERTY(VisibleAnywhere)
	EInteractableType InteractableType;

private:

	UPROPERTY(EditAnywhere)
	USphereComponent* SphereComponent;
	
};
