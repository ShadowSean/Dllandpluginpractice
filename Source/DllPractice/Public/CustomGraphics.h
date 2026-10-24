// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "CustomGraphics.generated.h"


UCLASS()
class DLLPRACTICE_API UCustomGraphics : public UGameUserSettings
{
	GENERATED_BODY()

/*
* Public functions that will hold signatures of what
* each function value should hold
*/
public:
	UFUNCTION(BlueprintCallable, Category = "Improved Game User Settings|Set Graphics")
	void SetTextureValue(int32 NewValue);
	UFUNCTION(BlueprintCallable, Category = "Improved Game User Settings|Set Graphics")
	void SetIlluminationValue(int32 NewValue);
	UFUNCTION(BlueprintCallable, Category = "Improved Game User Settings|Set Graphics")
	void SetViewDistanceValue(int32 NewValue);

	UFUNCTION(BlueprintPure, Category = "Improved Game User Settings|Get Graphics")
	int32 GetTextureValue() const;
	UFUNCTION(BlueprintPure, Category = "Improved Game User Settings|Get Graphics")
	int32 GetIlluminationValue() const;
	UFUNCTION(BlueprintPure, Category = "Improved Game User Settings|Get Graphics")
	int32 GetViewDistanceValue() const;

	UCustomGraphics(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Improved Game User Settings|Custom Settings")
	static UCustomGraphics* ImprovedGameUserSettings();

//Protected variables that hold each graphic value
protected:
	int32 TextureValue;
	int32 GlobalIlluminationValue;
	int32 ViewDistanceValue;
};
