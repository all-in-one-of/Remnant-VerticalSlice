#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puzzle01_Machine.generated.h"

UCLASS()
class TIMEYWIMEY_API APuzzle01_Machine : public AActor
{
	GENERATED_BODY()
	
public:	

	APuzzle01_Machine();

	UFUNCTION(BlueprintCallable)
	void StartMachine() { IsStarted = true; }

	UFUNCTION(BlueprintCallable)
	void ChangeSetting();

	UFUNCTION(BlueprintCallable)
	void ApplySetting();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere, Category="Machine Properties")
	bool IsStarted;
};
