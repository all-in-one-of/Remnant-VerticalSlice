#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puzzle01_Bookshelf.generated.h"

UENUM()
enum class EBookshelfPositionPast : uint8
{
	BOOKSHELF_LEFT UMETA(DisplayName = "Left"),
	BOOKSHELF_MIDDLE UMETA(DisplayName = "Middle"),
	BOOKSHELF_RIGHT UMETA(DisplayName = "Right"),

	TOTAL_NUMBER_POSITIONS
};

UENUM()
enum class EBookshelfPositionPresent : uint8
{
	BOOKSHELF_LEFT_HIGH UMETA(DisplayName = "Left-High"),
	BOOKSHELF_LEFT_MIDDLE UMETA(DisplayName = "Left-Middle"),
	BOOKSHELF_LEFT_LOW UMETA(DisplayName = "Left-Low"),
	BOOKSHELF_MIDDLE UMETA(DisplayName = "Middle"),
	BOOKSHELF_RIGHT UMETA(DisplayName = "Right"),

	TOTAL_NUMBER_POSITIONS
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

	void SetBookshefPositions();
	void SetStartValueBookshelfDataPresent(int BookshelfIndex, FVector rPos, FVector rRot);
	void SetStartValueBookshelfDataPast(int BookshelfIndex, FVector rPos, FVector rRot);

	int CurrentPosition;

	UPROPERTY(EditAnywhere, Category="Bookshelf Properties")
	EBookshelfPositionPast StartPosition;

	UPROPERTY(EditAnywhere, Category="Bookshelf Properties")
	FBookshelfData PositionPresetsPast[EBookshelfPositionPast::TOTAL_NUMBER_POSITIONS];

	UPROPERTY(EditAnywhere, Category = "Bookshelf Properties")
	FBookshelfData PositionPresetsPresent[EBookshelfPositionPresent::TOTAL_NUMBER_POSITIONS];

	UPROPERTY(EditAnywhere, Category = "Bookshelf Properties")
	AActor* BookshelfInPresent;
};