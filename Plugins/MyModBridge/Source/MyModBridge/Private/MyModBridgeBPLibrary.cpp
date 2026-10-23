// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyModBridgeBPLibrary.h"
#include "MyModBridge.h"
#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"
#include <string>

void* UMyModBridgeBPLibrary::DllHandle = nullptr;
UMyModBridgeBPLibrary::SetLangFn  UMyModBridgeBPLibrary::pSetLang = nullptr;
UMyModBridgeBPLibrary::GetLangFn  UMyModBridgeBPLibrary::pGetLang = nullptr;
UMyModBridgeBPLibrary::ScaleSpeedFn  UMyModBridgeBPLibrary::pScaleSpeed = nullptr;

bool UMyModBridgeBPLibrary::LoadMyModDLL()
{
	if (DllHandle) return true;
#if PLATFORM_WINDOWS
	
	DllHandle = FPlatformProcess::GetDllHandle(TEXT("MyNewTestMod.dll"));
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

void UMyModBridgeBPLibrary::SetPreferredLanguageBP(const FString& LangCode)
{
	if (!DllHandle && !LoadMyModDLL()) return;
	if (pSetLang)
	{
		std::string s = TCHAR_TO_ANSI(*LangCode);
		pSetLang(s.c_str());
	}
}

FString UMyModBridgeBPLibrary::GetPreferredLanguageBP()
{
	if (!DllHandle && !LoadMyModDLL()) return TEXT("en");
	if (pGetLang)
	{
		const char* c = pGetLang();
		return FString(ANSI_TO_TCHAR(c ? c : "en"));
	}
	return TEXT("en");
}

float UMyModBridgeBPLibrary::ScaleSpeedBP(float BaseSpeed, float Multiplier)
{
	if (!DllHandle && !LoadMyModDLL()) return BaseSpeed * Multiplier;
	return pScaleSpeed ? pScaleSpeed(BaseSpeed, Multiplier) : BaseSpeed * Multiplier;
}

