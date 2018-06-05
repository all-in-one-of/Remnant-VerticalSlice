// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "PlayerFPP_Character.h"

#include "Engine/World.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/InputSettings.h"
#include "InteractorComponent.h"
#include "InventoryComponent.h"

APlayerFPP_Character::APlayerFPP_Character()
{
	/// Set up Capsule
	const float CapsuleRadius = 55.f;
	const float CapsuleHeight = 96.f;

	GetCapsuleComponent()->InitCapsuleSize(CapsuleRadius, CapsuleHeight);

	/// Set up Camera Component
	const FVector CameraOffset(-39.56f, 1.75f, 64.f);

	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = CameraOffset;
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	/// Set up Movement Component
	const bool EnableCrouch = true;
	MovementComponent = GetCharacterMovement();
	MovementComponent->NavAgentProps.bCanCrouch = EnableCrouch;

	/// Set up Interactor Component
	FName InteractorComponentName = TEXT("InteractorComponent");

	InteractorComponent = CreateDefaultSubobject<UInteractorComponent>(InteractorComponentName);

	/// Set up Inventory Component
	FName InventoryComponentName = TEXT("InventoryComponent");

	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(InventoryComponentName);
}

void APlayerFPP_Character::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerFPP_Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up game play key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &APlayerFPP_Character::OnInteract);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("CrouchHold", IE_Pressed, this, &APlayerFPP_Character::CharacterCrouch);
	PlayerInputComponent->BindAction("CrouchHold", IE_Released, this, &APlayerFPP_Character::CharacterUnCrouch);
	PlayerInputComponent->BindAction("CrouchToggle", IE_Pressed, this, &APlayerFPP_Character::CharacterCrouchToggle);
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

void APlayerFPP_Character::CharacterCrouch()
{
	if (MovementComponent->IsCrouching())
		return;

	MovementComponent->Crouch();
}

void APlayerFPP_Character::CharacterUnCrouch()
{
	if (!MovementComponent->IsCrouching())
		return;

	MovementComponent->UnCrouch();
}

void APlayerFPP_Character::CharacterCrouchToggle()
{
	MovementComponent->IsCrouching() ? MovementComponent->Crouch() : MovementComponent->UnCrouch();
}

void APlayerFPP_Character::OnInteract()
{
	InteractorComponent->AttemptInteract();
}