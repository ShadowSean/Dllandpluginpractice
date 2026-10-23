// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyModBridgeBPLibrary.generated.h"

UCLASS()
class MYMODBRIDGE_API UMyModBridgeBPLibrary : public UBlueprintFunctionLibrary
{

	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "MyNewTestMod|DLL")
	static bool LoadMyModDLL();

	UFUNCTION(BlueprintCallable, Category = "MyNewTestMod|Language", meta = (DisplayName = "MyNewTestMod set preferred Language"))
	static void SetPreferredLanguageBP(const FString& LangCode);


	UFUNCTION(BlueprintCallable, Category = "MyNewTestMod|Language", meta = (DisplayName = "MyNewTestMod get preferred language"))
	static FString GetPreferredLanguageBP();

	UFUNCTION(BlueprintPure, Category = "MyNewTestMod|Gameplay", meta = (DisplayName = "MyNewTestMod scale speed"))
	static float ScaleSpeedBP(float BaseSpeed, float Multiplier);

private:
	static void* DllHandle;

	typedef void (*SetLangFn)(const char*);
	typedef const char* (*GetLangFn)();
	typedef float (*ScaleSpeedFn)(float, float);

	static SetLangFn  pSetLang;
	static GetLangFn  pGetLang;
	static ScaleSpeedFn pScaleSpeed;
};

