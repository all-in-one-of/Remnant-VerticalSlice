// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "InteractableLinkedActor.generated.h"

UCLASS()
class TIMEYWIMEY_API AInteractableLinkedActor : public AInteractableActor
{
	GENERATED_BODY()
	
public:

	AInteractableLinkedActor();

	UFUNCTION(BlueprintCallable)
	AActor* GetLinkedActor();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	AActor* LinkedActor;
	
};
