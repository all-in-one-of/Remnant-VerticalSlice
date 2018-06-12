// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "Engine/World.h"
#include "Public/TimerManager.h"

#include "TeleportComponent.generated.h"

class APlayerFPP_Character;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
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

	// Just for the mirror
	bool just_teleported;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool teleport_allowed = true;

private:
	UPROPERTY(EditAnywhere)
		float teleport_amount = 10000.0f;

	UPROPERTY(EditAnywhere)
		float trace_length = 10500.0f;

	void Teleport(const FVector location);
	void Teleport();
	bool TryTeleport();
	void DenyTeleport();

	APlayerFPP_Character* player;

	/** Teleport cooldown. Must match FOV timer in PlayerFPP_BP */
	UPROPERTY(EditAnywhere)
		float cooldown_timer_length = 0.75f;

	FTimerHandle teleport_cooldown_handle;

	void OnTeleportCooldownEnd();
	FORCEINLINE void StartTeleportCooldown()
	{
		if (GetWorld()->GetTimerManager().IsTimerActive(teleport_cooldown_handle)) return; // Prevent spam
		teleport_allowed = false;
		GetWorld()->GetTimerManager().SetTimer(teleport_cooldown_handle, this, &UTeleportComponent::OnTeleportCooldownEnd, cooldown_timer_length, false);
	}
	// End of teleport cooldown

	// Teleport buildup
	UPROPERTY(EditAnywhere)
		float teleport_buildup_time = 0.25f;

	FTimerHandle teleport_buildup_handle;

	void OnBuildUpEnd();
	FORCEINLINE void StartBuildUpTimer()
	{
		if (GetWorld()->GetTimerManager().IsTimerActive(teleport_buildup_handle)) return; // prevent spam
		GetWorld()->GetTimerManager().SetTimer(teleport_buildup_handle, this, &UTeleportComponent::OnBuildUpEnd, teleport_buildup_time, false);
	}
	// End of buildup timer
};
