// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractorComponent.generated.h"

class USphereComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TIMEYWIMEY_API UInteractorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UInteractorComponent();

	void AttemptInteract();

protected:
	
	virtual void BeginPlay() override;

private:	

	UPROPERTY(EditAnywhere)
	float InteractRange;

};
