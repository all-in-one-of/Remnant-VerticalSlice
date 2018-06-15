#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puzzle01_MovingBookshelves.generated.h"

UENUM()
enum ESequence
{
	SEQUENCE_ONE UMETA(DisplayName="One"),
	SEQUENCE_TWO UMETA(DisplayName = "Two"),
};

UCLASS()
class TIMEYWIMEY_API APuzzle01_MovingBookshelves : public AActor
{
	GENERATED_BODY()
	
public:	
	
	APuzzle01_MovingBookshelves();

	UFUNCTION(BlueprintCallable)
	void StartSequence();

	UFUNCTION(BlueprintCallable)
	void SwitchSequence() { CurrentSequence = (CurrentSequence == 1) ? 2 : 1; }

	virtual void Tick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;

private:

	void GetBookshelvesAffectedBySequence(TArray<AActor*>& OutAffectedBookshelves);

	UPROPERTY(EditAnywhere, Category="BookshelfData", DisplayName = "Movement Change")
	FVector DeltaBookshelfMovement;

	UPROPERTY(EditAnywhere, Category="SequenceData", DisplayName = "Actors, Sequence 1")
	TArray<AActor*> BookshelvesSequenceOne;

	UPROPERTY(EditAnywhere, Category = "SequenceData", DisplayName = "Actors, Sequence 2")
	TArray<AActor*> BookshelvesSequenceTwo;

	UPROPERTY(EditAnywhere, Category = "FinishDoor", DisplayName = "Door Pointer")
	AActor* FinishDoor;

	UPROPERTY(EditAnywhere, Category = "FinishDoor", DisplayName = "Door Open Pos Offset")
	FVector FinishDoorOffset;

	UPROPERTY(EditAnywhere, Category = "SequenceData", DisplayName = "Sequence active length")
	float SequenceActiveDuration;

	float SequenceActiveTimer;

	bool IsActive;	
	int CurrentSequence;

	void EndSequence();
	void OpenBookshelves();
	void CloseBookshelves();
};