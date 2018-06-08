// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MirrorComponent.generated.h"

class APlayerFPP_Character;
class UTeleportComponent;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TIMEYWIMEY_API UMirrorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMirrorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool switch_mirrors;

private:
	APlayerFPP_Character* player;
	UTeleportComponent* teleport_component;

};
