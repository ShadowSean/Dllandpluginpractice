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
	UFUNCTION(BlueprintCallable, Category = "Improved Game User Settings|Set Graphics")
	void SetAntiAliasingValue(int32 NewValue);
	UFUNCTION(BlueprintCallable, Category = "Improved Game User Settings|Set Graphics")
	void SetPostProcessValue(int32 NewValue);
	UFUNCTION(BlueprintCallable, Category = "Improved Game User Settings|Set Graphics")
	void SetShadowsValue(int32 NewValue);
	UFUNCTION(BlueprintCallable, Category = "Improved Game User Settings|Set Graphics")
	void SetReflectionsValue(int32 NewValue);
	UFUNCTION(BlueprintCallable, Category = "Improved Game User Settings|Set Graphics")
	void SetEffectsValue(int32 NewValue);
	UFUNCTION(BlueprintCallable, Category = "Improved Game User Settings|Set Graphics")
	void SetFoliageValue(int32 NewValue);
	UFUNCTION(BlueprintCallable, Category = "Improved Game User Settings|Set Graphics")
	void SetLandscapeValue(int32 NewValue);
	UFUNCTION(BlueprintCallable, Category = "Improved Game User Settings|Set Graphics")
	void SetShadingValue(int32 NewValue);


	UFUNCTION(BlueprintPure, Category = "Improved Game User Settings|Get Graphics")
	int32 GetTextureValue() const;
	UFUNCTION(BlueprintPure, Category = "Improved Game User Settings|Get Graphics")
	int32 GetIlluminationValue() const;
	UFUNCTION(BlueprintPure, Category = "Improved Game User Settings|Get Graphics")
	int32 GetViewDistanceValue() const;
	UFUNCTION(BlueprintPure, Category = "Improved Game User Settings|Get Graphics")
	int32 GetAntiAliasingValue() const;
	UFUNCTION(BlueprintPure, Category = "Improved Game User Settings|Get Graphics")
	int32 GetPostProcessValue() const;
	UFUNCTION(BlueprintPure, Category = "Improved Game User Settings|Get Graphics")
	int32 GetReflectionsValue() const;
	UFUNCTION(BlueprintPure, Category = "Improved Game User Settings|Get Graphics")
	int32 GetEffectsValue() const;
	UFUNCTION(BlueprintPure, Category = "Improved Game User Settings|Get Graphics")
	int32 GetFoliageValue() const;
	UFUNCTION(BlueprintPure, Category = "Improved Game User Settings|Get Graphics")
	int32 GetLandscapeValue() const;
	UFUNCTION(BlueprintPure, Category = "Improved Game User Settings|Get Graphics")
	int32 GetShadingValue() const;
	UFUNCTION(BlueprintPure, Category = "Improved Game User Settings|Get Graphics")
	int32 GetShadowsValue() const;

	UCustomGraphics(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Improved Game User Settings|Custom Settings")
	static UCustomGraphics* ImprovedGameUserSettings();

//Protected variables that hold each graphic value
protected:
	int32 TextureValue;
	int32 GlobalIlluminationValue;
	int32 ViewDistanceValue;
	int32 AntiAliasingValue;
	int32 PostProcessValue;
	int32 ShadowsValue;
	int32 ReflectionsValue;
	int32 EffectsValue;
	int32 FoliageValue;
	int32 LandscapeValue;
	int32 ShadingValue;
};
