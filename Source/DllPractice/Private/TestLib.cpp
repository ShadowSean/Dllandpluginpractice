// Fill out your copyright notice in the Description page of Project Settings.


#include "TestLib.h"



#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"
#include <string>

void* UTestLib::DllHandle = nullptr;
UTestLib::SetLangFn  UTestLib::pSetLang = nullptr;
UTestLib::GetLangFn  UTestLib::pGetLang = nullptr;
UTestLib::ScaleSpeedFn  UTestLib::pScaleSpeed = nullptr;

FString UTestLib::HelloTest()
{
	return TEXT("Hello from TestLib");
}

bool UTestLib::LoadMyModDLL()
{
	if (DllHandle) return true;

#if PLATFORM_WINDOWS
	const FString DllPath = FPaths::Combine(FPaths::ProjectDir(), TEXT("Binaries/Win64/MyNewTestMod.dll"));
	DllHandle = FPlatformProcess::GetDllHandle(*DllPath);
	if (!DllHandle) return false;

	pSetLang = reinterpret_cast<SetLangFn>(FPlatformProcess::GetDllExport(DllHandle, TEXT("SetPreferredLanguage")));
	pGetLang = reinterpret_cast<GetLangFn>(FPlatformProcess::GetDllExport(DllHandle, TEXT("GetPreferredLanguage")));
	pScaleSpeed = reinterpret_cast<ScaleSpeedFn>(FPlatformProcess::GetDllExport(DllHandle, TEXT("ScaleSpeed")));

	const bool ok = (pSetLang && pGetLang && pScaleSpeed);
	if (!ok)
	{
		FPlatformProcess::FreeDllHandle(DllHandle);
		DllHandle = nullptr;
		return false;

	}
	return true;

#else
	return false;
#endif
}

void UTestLib::SetPreferredLanguageBP(const FString& LangCode)
{
	if (!DllHandle && !LoadMyModDLL()) return;
	if (pSetLang)
	{
		std::string s = TCHAR_TO_ANSI(*LangCode);
		pSetLang(s.c_str());
	}
}

FString UTestLib::GetPreferredLanguageBP()
{
	if (!DllHandle && !LoadMyModDLL()) return TEXT("en");
	if (pGetLang)
	{
		const char* c = pGetLang();
		return FString(ANSI_TO_TCHAR(c ? c : "en"));
	}
	return TEXT("en");
}

float UTestLib::ScaleSpeedBP(float BaseSpeed, float Multiplier)
{
	if (!DllHandle && !LoadMyModDLL()) return BaseSpeed * Multiplier;
	return pScaleSpeed ? pScaleSpeed(BaseSpeed, Multiplier) : BaseSpeed * Multiplier;
}

