#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "PickUpActor.generated.h"

UCLASS()
class TIMEYWIMEY_API APickUpActor : public AInteractableActor
{
	GENERATED_BODY()
	
public:

	APickUpActor();

	UFUNCTION(BlueprintCallable)
	FName GetName() const { return PickUpName; }

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	FName PickUpName;
	
};
