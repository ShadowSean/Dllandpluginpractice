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
	AntiAliasingValue = 0;
	PostProcessValue = 0;
	ShadowsValue = 0;
	ReflectionsValue = 0;
	EffectsValue = 0;
	FoliageValue = 0;
	LandscapeValue = 0;
	ShadingValue = 0;
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
//set our view distance value to be newvalue
void UCustomGraphics::SetAntiAliasingValue(int32 NewValue)
{
	AntiAliasingValue = NewValue;
	//Clamps value between 0-4
	if (AntiAliasingValue < 0)
	{
		AntiAliasingValue = 0;
	}
	else if (AntiAliasingValue > 4)
	{
		AntiAliasingValue = 4;
	}
}

void UCustomGraphics::SetPostProcessValue(int32 NewValue)
{
	PostProcessValue = NewValue;
	//Clamps value between 0-4
	if (PostProcessValue < 0)
	{
		PostProcessValue = 0;
	}
	else if (PostProcessValue > 4)
	{
		PostProcessValue = 4;
	}
}

void UCustomGraphics::SetShadowsValue(int32 NewValue)
{
	ShadowsValue = NewValue;
	//Clamps value between 0-4
	if (ShadowsValue < 0)
	{
		ShadowsValue = 0;
	}
	else if (ShadowsValue > 4)
	{
		ShadowsValue = 4;
	}
}

void UCustomGraphics::SetReflectionsValue(int32 NewValue)
{
	ReflectionsValue = NewValue;
	//Clamps value between 0-4
	if (ReflectionsValue < 0)
	{
		ReflectionsValue = 0;
	}
	else if (ReflectionsValue > 4)
	{
		ReflectionsValue = 4;
	}
}

void UCustomGraphics::SetEffectsValue(int32 NewValue)
{
	EffectsValue = NewValue;
	//Clamps value between 0-4
	if (EffectsValue < 0)
	{
		EffectsValue = 0;
	}
	else if (EffectsValue > 4)
	{
		EffectsValue = 4;
	}
}

void UCustomGraphics::SetFoliageValue(int32 NewValue)
{
	FoliageValue = NewValue;
	//Clamps value between 0-4
	if (FoliageValue < 0)
	{
		FoliageValue = 0;
	}
	else if (FoliageValue > 4)
	{
		FoliageValue = 4;
	}
}

void UCustomGraphics::SetLandscapeValue(int32 NewValue)
{
	LandscapeValue = NewValue;
	//Clamps value between 0-4
	if (LandscapeValue < 0)
	{
		LandscapeValue = 0;
	}
	else if (LandscapeValue > 4)
	{
		LandscapeValue = 4;
	}
}

void UCustomGraphics::SetShadingValue(int32 NewValue)
{
	ShadingValue = NewValue;
	//Clamps value between 0-4
	if (ShadingValue < 0)
	{
		ShadingValue = 0;
	}
	else if (ShadingValue > 4)
	{
		ShadingValue = 4;
	}
}

void UCustomGraphics::CustomGameSettings(int32 Texture, int32 Effects, int32 PostProcess, 
	int32 Shadows, int32 Shading, int32 Foliage, int32 Illumination, int32 ViewDistance, 
	int32 AntiAlising, int32 Reflections, int32 Landscape)
{
	TextureValue = Texture;
	EffectsValue = Effects;
	PostProcessValue = PostProcess;
	ShadowsValue = Shadows;
	ShadingValue = Shading;
	FoliageValue = Foliage;
	GlobalIlluminationValue = Illumination;
	ViewDistanceValue = ViewDistance;
	AntiAliasingValue = AntiAlising;
	ReflectionsValue = Reflections;
	LandscapeValue = Landscape;	
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

int32 UCustomGraphics::GetAntiAliasingValue() const
{
	return AntiAliasingValue;
}

int32 UCustomGraphics::GetPostProcessValue() const
{
	return PostProcessValue;
}

int32 UCustomGraphics::GetReflectionsValue() const
{
	return ReflectionsValue;
}

int32 UCustomGraphics::GetEffectsValue() const
{
	return EffectsValue;
}

int32 UCustomGraphics::GetFoliageValue() const
{
	return FoliageValue;
}

int32 UCustomGraphics::GetLandscapeValue() const
{
	return LandscapeValue;
}

int32 UCustomGraphics::GetShadingValue() const
{
	return ShadingValue;
}

int32 UCustomGraphics::GetShadowsValue() const
{
	return ShadowsValue;
}





















