#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puzzle01_Bookshelf.generated.h"

class APuzzle01_Lamp;

UENUM()
enum class EBookshelfPositionPast
{
	BOOKSHELF_LEFT UMETA(DisplayName = "Left"),
	BOOKSHELF_MIDDLE UMETA(DisplayName = "Middle"),
	BOOKSHELF_RIGHT UMETA(DisplayName = "Right"),
};

UENUM()
enum class EBookshelfPositionPresent
{
	BOOKSHELF_LEFT_HIGH UMETA(DisplayName = "Left-High"),
	BOOKSHELF_LEFT_MIDDLE UMETA(DisplayName = "Left-Middle"),
	BOOKSHELF_LEFT_LOW UMETA(DisplayName = "Left-Low"),
	BOOKSHELF_MIDDLE UMETA(DisplayName = "Middle"),
	BOOKSHELF_RIGHT UMETA(DisplayName = "Right"),
};

USTRUCT()
struct FBookshelfData
{

	GENERATED_BODY()

	FVector Position;
	FRotator Rotation;
};

UCLASS()
class TIMEYWIMEY_API APuzzle01_Bookshelf : public AActor
{

	GENERATED_BODY()
	
public:	

	APuzzle01_Bookshelf();

	UFUNCTION(BlueprintCallable)
	void MoveRight();

	UFUNCTION(BlueprintCallable)
	void MoveLeft();

	int GetPosition() { return CurrentPosition; }

	void SetBookshelfPositions();

protected:

	virtual void BeginPlay() override;

private:

	static const int NUM_POS_PRESETS_PAST = 3;
	static const int NUM_POS_PRESETS_PRESENT = 5;

	
	void SetBookshelfPositionPast(int BookshelfIndex);
	void SetBookshelfPositionPresent(int BookshelfIndex);
	void SetStartValueBookshelfDataPresent(int BookshelfIndex, FVector Pos, FRotator Rot);
	void SetStartValueBookshelfDataPast(int BookshelfIndex, FVector Pos, FRotator Rot);
	
	void SetPresetsDefaultValues();

	UPROPERTY(EditAnywhere, Category = "Past Presets")
	FVector PastPositionLeft;
	UPROPERTY(EditAnywhere, Category = "Past Presets")
	FVector PastPositionMiddle;
	UPROPERTY(EditAnywhere, Category = "Past Presets")
	FVector PastPositionRight;

	UPROPERTY(EditAnywhere, Category = "Past Presets")
	FRotator PastRotationLeft;
	UPROPERTY(EditAnywhere, Category = "Past Presets")
	FRotator PastRotationMiddle;
	UPROPERTY(EditAnywhere, Category = "Past Presets")
	FRotator PastRotationRight;

	UPROPERTY(EditAnywhere, Category = "Present Presets")
	FVector PresentPositionLeftHigh;
	UPROPERTY(EditAnywhere, Category = "Present Presets")
	FVector PresentPositionLeftMiddle;
	UPROPERTY(EditAnywhere, Category = "Present Presets")
	FVector PresentPositionLeftLow;
	UPROPERTY(EditAnywhere, Category = "Present Presets")
	FVector PresentPositionMiddle;
	UPROPERTY(EditAnywhere, Category = "Present Presets")
	FVector PresentPositionRight;

	UPROPERTY(EditAnywhere, Category = "Present Presets")
	FRotator PresentRotationLeftHigh;
	UPROPERTY(EditAnywhere, Category = "Present Presets")
	FRotator PresentRotationLeftMiddle;
	UPROPERTY(EditAnywhere, Category = "Present Presets")
	FRotator PresentRotationLeftLow;
	UPROPERTY(EditAnywhere, Category = "Present Presets")
	FRotator PresentRotationMiddle;
	UPROPERTY(EditAnywhere, Category = "Present Presets")
	FRotator PresentRotationRight;	

	int CurrentPosition;

	UPROPERTY(EditAnywhere, Category="Bookshelf Properties")
	EBookshelfPositionPast StartPosition;
	
	FBookshelfData PositionPresetsPast[NUM_POS_PRESETS_PAST];
	FBookshelfData PositionPresetsPresent[NUM_POS_PRESETS_PRESENT];

	UPROPERTY(EditAnywhere, Category = "Linked Actors")
	AActor* BookshelfInPresent;

	UPROPERTY(EditAnywhere, Category = "Linked Actors")
	APuzzle01_Lamp* Lamp;
};