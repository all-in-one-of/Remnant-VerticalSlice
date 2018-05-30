// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerFPP_Character.generated.h"

class UInputComponent;
class UCharacterMovementComponent;

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

	UPROPERTY(EditAnywhere)
		AActor* main_camera;

	UPROPERTY(EditAnywhere)
		AActor* second_camera;

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
	void SwitchCameras();

	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

private:

	UCharacterMovementComponent* MovementComponent;

};