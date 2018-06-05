#include "InventoryComponent.h"


UInventoryComponent::UInventoryComponent()
{

}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();	
}

bool UInventoryComponent::HasItem(FName ItemName) const
{
	return Inventory.Contains(ItemName);
}

bool UInventoryComponent::AddItem(FName ItemName)
{
	if (!HasItem(ItemName))
	{		
		Inventory.Add(ItemName);
		return true;
	}

	return false;
}

bool UInventoryComponent::RemoveItem(FName ItemName)
{
	if (HasItem(ItemName))
	{
		Inventory.Remove(ItemName);
		return true;
	}

	return false;
}