// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "EnemyManager.generated.h"

/**
 * 
 */
// �g���pBP�̃x�[�X�ƂȂ�N���X
UCLASS(Blueprintable, Abstract, MinimalAPI, meta = (ShowWorldContextPin))
class UEnemyManagerHelperBase : public UObject
{
	GENERATED_BODY()
};


UCLASS()
class SOTUSEI_API UEnemyManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	// �g���pBP�̃v���p�e�B
	UPROPERTY(Transient, BlueprintReadWrite)
	UEnemyManagerHelperBase* SubsystemHelper;

	/*UFUNCTION(BlueprintCallable)

	UEnemyManager();

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;*/
};