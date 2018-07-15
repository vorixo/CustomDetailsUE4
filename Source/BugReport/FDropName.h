#pragma once
#include "FDropName.generated.h"

USTRUCT(BlueprintType)
struct FDropName
{
	GENERATED_USTRUCT_BODY()
public:
	FDropName(FName nm) : SelectedBone(nm) {};
	FDropName() {};
	~FDropName() { SelectedBone = ""; };
	bool operator==(const FDropName& aOther)
	{
		return aOther.SelectedBone == SelectedBone;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
	FName SelectedBone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
	TArray<FName> Bones;
};
