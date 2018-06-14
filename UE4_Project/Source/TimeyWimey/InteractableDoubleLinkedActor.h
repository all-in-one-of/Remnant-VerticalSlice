#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "InteractableDoubleLinkedActor.generated.h"

UCLASS()
class TIMEYWIMEY_API AInteractableDoubleLinkedActor : public AInteractableActor
{
	GENERATED_BODY()

public:

	AInteractableDoubleLinkedActor();

	UFUNCTION(BlueprintCallable)
	AActor* GetLinkedActorOne();

	UFUNCTION(BlueprintCallable)
	AActor* GetLinkedActorTwo();


protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	AActor* LinkedActorOne;

	UPROPERTY(EditAnywhere)
	AActor* LinkedActorTwo;
};
