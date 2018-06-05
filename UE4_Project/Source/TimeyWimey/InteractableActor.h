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

	UPROPERTY(BlueprintReadWrite)
	UInteractComponent* InteractComponent;

private:

	UPROPERTY(EditAnywhere)
	USphereComponent* SphereComponent;
	
};
