// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractComponent.h"

UInteractComponent::UInteractComponent()
{

}

void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInteractComponent::RequestInteract()
{
	OnInteractRequset.Broadcast();
}