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

void UInventoryComponent::AddItem(FName ItemName)
{
	if (!HasItem(ItemName))
	{
		Inventory.Add(ItemName);
	}
}

void UInventoryComponent::RemoveItem(FName ItemName)
{
	if (HasItem(ItemName))
	{
		Inventory.Remove(ItemName);
	}
}