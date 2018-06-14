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
	bool IsMachineStarted() { return IsStarted; }

	UFUNCTION(BlueprintCallable)
	void StartMachine();

	UFUNCTION(BlueprintCallable)
	void ChangeSetting();

	UFUNCTION(BlueprintCallable)
	void ApplySetting();

protected:

	virtual void BeginPlay() override;

private:

	bool IsStarted;

	UPROPERTY(EditAnywhere, Category = "Machine Properties", DisplayName = "Lamp")
	AActor* Lamp;

	UPROPERTY(EditAnywhere, Category = "Machine Properties", DisplayName = "Lamp Buttons Pos Offset")
	FVector LampOffset;
};
