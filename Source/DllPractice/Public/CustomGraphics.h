// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "CustomGraphics.generated.h"


UCLASS()
class DLLPRACTICE_API UCustomGraphics : public UGameUserSettings
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetGraphicsValue(int32 NewValue);

	UFUNCTION(BlueprintPure)
	int32 GetGraphicsValue() const;

	UCustomGraphics(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable)
	static UCustomGraphics* ImprovedGameUserSettings();

protected:
	int32 GraphicsValue;
};
