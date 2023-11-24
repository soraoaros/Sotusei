// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManager.h"
#include "MyWorldSettings.h"

UEnemyManager::UEnemyManager()
{
}

bool UEnemyManager::ShouldCreateSubsystem(UObject* Outer) const
{
	if (!Super::ShouldCreateSubsystem(Outer))
	{
		return false;
	}

	if (UWorld* WorldOuter = Cast<UWorld>(Outer))
	{
		if (AMyWorldSettings* MyWorldSettings = Cast<AMyWorldSettings>(WorldOuter->GetWorldSettings()))
		{
			return MyWorldSettings->bUseEnemyManager;
		}
	}

	return false;
}

void UEnemyManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UEnemyManager::Deinitialize()
{
	Super::Deinitialize();
}