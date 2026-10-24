// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGraphics.h"

UCustomGraphics::UCustomGraphics(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	GraphicsValue = 0;
}

UCustomGraphics* UCustomGraphics::ImprovedGameUserSettings()
{
	return Cast<UCustomGraphics>(UCustomGraphics::GetGameUserSettings());
}

void UCustomGraphics::SetGraphicsValue(int32 NewValue)
{
	GraphicsValue = NewValue;
}

int32 UCustomGraphics::GetGraphicsValue() const
{
	return GraphicsValue;
}

