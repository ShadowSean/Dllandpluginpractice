// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CustomAwards.generated.h"


UCLASS()
class DLLPRACTICE_API UCustomAwards : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


public:
	
	UFUNCTION(BlueprintCallable, Category = "Game Achievement|Set Achievement")
	void SetAward(FString AwardName);

	UCustomAwards(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Game Achievement|Player Achievements")
	static UCustomAwards* PlayerAchievementName();

	UFUNCTION(BlueprintPure, Category = "Game Achievement|Get Achievement")
	FString GetAward() const;

protected:
	UPROPERTY()
	FString NewAwardName;
};
