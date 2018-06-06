// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TeleportComponent.generated.h"

class APlayerFPP_Character;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TIMEYWIMEY_API UTeleportComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTeleportComponent();

	void TraverseDimension();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Teleport(const FVector location);

private:
	UPROPERTY(EditAnywhere)
	float teleport_amount = 10000.0f;

	UPROPERTY(EditAnywhere)
	float trace_length = 10500.0f;

	bool TryTeleport();
	void DenyTeleport();

	APlayerFPP_Character* player;
};
