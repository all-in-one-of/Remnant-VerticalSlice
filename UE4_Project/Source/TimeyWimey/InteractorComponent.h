// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractorComponent.generated.h"

class USphereComponent;
class APlayerFPP_Character;
class AInteractableActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLookingAtObject, AActor*, actor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTraceHit, bool, trace);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TIMEYWIMEY_API UInteractorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UInteractorComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AttemptInteract();

	UPROPERTY(BlueprintAssignable)
	FLookingAtObject looking_at_object;

	UPROPERTY(BlueprintAssignable)
	FTraceHit trace_hit;

protected:
	
	virtual void BeginPlay() override;

private:	

	UPROPERTY(EditAnywhere)
	float InteractRange;

	APlayerFPP_Character* player;

	FHitResult LineTrace();
};
