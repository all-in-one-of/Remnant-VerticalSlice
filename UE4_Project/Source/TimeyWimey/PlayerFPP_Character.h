// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerFPP_Character.generated.h"

class UInputComponent;
class UCharacterMovementComponent;
class UInteractorComponent;
class UInventoryComponent;
class UTeleportComponent;

enum class EDimension
{
	LOWER,
	UPPER
};

UCLASS(config=Game)
class APlayerFPP_Character : public ACharacter
{
	GENERATED_BODY()

	// First person camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;

public:

	APlayerFPP_Character();

	// Returns FirstPersonCameraComponent sub object
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	EDimension GetDimension() { return dimension; }
	void SetDimension(EDimension new_dimension) { dimension = new_dimension; }

protected:

	virtual void BeginPlay();

	/// Input Callbacks
	// Move forward / backwards
	void MoveForward(float Val);
	// Move left / right
	void MoveRight(float Val);
	void CharacterCrouch();
	void CharacterUnCrouch();
	void CharacterCrouchToggle();

	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

private:
	
	void TraverseDimension();
	void OnInteract();

	UInteractorComponent* InteractorComponent;
	UCharacterMovementComponent* MovementComponent;
	UInventoryComponent* InventoryComponent;
	UTeleportComponent* teleport_component;

	EDimension dimension;

};