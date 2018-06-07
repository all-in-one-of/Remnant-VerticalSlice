#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puzzle01_Bookshelf.generated.h"

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

protected:

	virtual void BeginPlay() override;

private:

	static const int NUM_POS_PRESETS_PAST = 3;
	static const int NUM_POS_PRESETS_PRESENT = 5;

	void SetBookshefPositions();
	void SetBookshelfPositionPresent(int BookshelfIndex);
	void SetStartValueBookshelfDataPresent(int BookshelfIndex, FVector Pos, FRotator Rot);
	void SetStartValueBookshelfDataPast(int BookshelfIndex, FVector Pos, FRotator Rot);

	int CurrentPosition;

	UPROPERTY(EditAnywhere, Category="Bookshelf Properties")
	EBookshelfPositionPast StartPosition;

	UPROPERTY(EditAnywhere, Category="Bookshelf Properties")
	FBookshelfData PositionPresetsPast[NUM_POS_PRESETS_PAST];

	UPROPERTY(EditAnywhere, Category = "Bookshelf Properties")
	FBookshelfData PositionPresetsPresent[NUM_POS_PRESETS_PRESENT];

	UPROPERTY(EditAnywhere, Category = "Bookshelf Properties")
	AActor* BookshelfInPresent;
};