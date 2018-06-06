// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TIMEYWIMEY_API UInteractComponent : public UActorComponent
{

	GENERATED_BODY()

public:	
	
	UInteractComponent();

	void RequestInteract();

	UPROPERTY(BlueprintAssignable)
	FOnInteractRequest OnInteractRequest;

protected:
	
	virtual void BeginPlay() override;

};
