// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "EnemyManager.generated.h"

/**
 * 
 */
UCLASS()
class SOTUSEI_API UEnemyManager : public UWorldSubsystem
{
	GENERATED_BODY()
public:

	UEnemyManager();

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
};