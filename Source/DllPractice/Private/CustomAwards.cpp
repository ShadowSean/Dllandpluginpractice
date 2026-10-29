// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomAwards.h"


UCustomAwards::UCustomAwards(const FObjectInitializer& ObjectInitializer)
{
	NewAwardName = TEXT("Default Award");
}

void UCustomAwards::SetAward(FString LangCode)
{
	NewAwardName = LangCode;
}

UCustomAwards* UCustomAwards::PlayerAchievementName()
{
	UObject* PlayerAwards = (UObject*)GetTransientPackage();

	static UCustomAwards* Instance = NewObject<UCustomAwards>(PlayerAwards, UCustomAwards::StaticClass());

	return Instance;
}




FString UCustomAwards::GetAward() const
{
	return NewAwardName;
}






