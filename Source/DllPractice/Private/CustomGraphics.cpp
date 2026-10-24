// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGraphics.h"

/*
* Default constructor that has 
* default values for all graphic values
*/
UCustomGraphics::UCustomGraphics(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ViewDistanceValue = 0;
	GlobalIlluminationValue = 0;
	TextureValue = 0;
}

/*
* Will make a node that returns all of our improved settings funcitonality and
* be able to access game user settings by casting to it
*/
UCustomGraphics* UCustomGraphics::ImprovedGameUserSettings()
{
	return Cast<UCustomGraphics>(UCustomGraphics::GetGameUserSettings());
}

//Set our view distance value to be new value
void UCustomGraphics::SetViewDistanceValue(int32 NewValue)
{
	ViewDistanceValue = NewValue;
	//Clamps value between 0-4
	if (ViewDistanceValue < 0)
	{
		ViewDistanceValue = 0;
	}
	else if (ViewDistanceValue > 4)
	{
		ViewDistanceValue = 4;
	}
}

//Set our global illumination value to be new value
void UCustomGraphics::SetIlluminationValue(int32 NewValue)
{
	GlobalIlluminationValue = NewValue;
	//Clamps value between 0-4
	if (GlobalIlluminationValue < 0)
	{
		GlobalIlluminationValue = 0;
	}
	else if (GlobalIlluminationValue > 4)
	{
		GlobalIlluminationValue = 4;
	}
}

//Set our texture value to be new value
void UCustomGraphics::SetTextureValue(int32 NewValue)
{
	TextureValue = NewValue;
	//Clamps value between 0-4
	if (TextureValue < 0)
	{
		TextureValue = 0;
	}
	else if (TextureValue > 4)
	{
		TextureValue = 4;
	}
}

//Get our texture set texture value
int32 UCustomGraphics::GetTextureValue() const
{
	return TextureValue;
}

//Get our set global illumination value
int32 UCustomGraphics::GetIlluminationValue() const
{
	return GlobalIlluminationValue;
}

//Get our set view distance value
int32 UCustomGraphics::GetViewDistanceValue() const
{
	return ViewDistanceValue;
}







