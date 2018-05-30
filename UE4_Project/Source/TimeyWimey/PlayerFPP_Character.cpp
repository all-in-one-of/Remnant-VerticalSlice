// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "PlayerFPP_Character.h"

#include "Engine/World.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/InputSettings.h"

APlayerFPP_Character::APlayerFPP_Character()
{
	/// Set up Capsule
	const float CapsuleRadius = 55.f;
	const float CapsuleHeight = 96.f;

	GetCapsuleComponent()->InitCapsuleSize(CapsuleRadius, CapsuleHeight);

	/// Set up camera component
	const FVector CameraOffset(-39.56f, 1.75f, 64.f);

	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = CameraOffset;
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
}

void APlayerFPP_Character::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerFPP_Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up game play key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerFPP_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerFPP_Character::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}

void APlayerFPP_Character::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void APlayerFPP_Character::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}