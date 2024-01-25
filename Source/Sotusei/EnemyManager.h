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

public:
	// �����̒��g��BP���ŏ������Ƃ�錾

	// �p�����[�^�擾
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void GetSpawnParams(TArray<FTransform>& transforms, TArray<FName>& names, TArray<float>& nums, TArray<float>& spawnCD, TArray<bool>& isPossible);

	// �p�����[�^�ݒ�
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetSpawnParams(const TArray<FTransform>& transforms, const TArray<FName>& names, const TArray<float>& nums, const TArray<float>& spawnCD, const TArray<bool>& isPossible);


	// �p�����[�^�ǉ�
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void AddSpawnParam(UPARAM(ref) FTransform& transform, UPARAM(ref) FName& name, UPARAM(ref) float& num);


	// �p�����[�^�S����
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void ClearSpawnParams();


	// �N�[���_�E���X�V
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void UpdateSpawnCoolDown(const float& delta);
};


UCLASS()
class SOTUSEI_API UEnemyManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	UEnemyManager();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// �g���pBP�̃v���p�e�B
	UPROPERTY(Transient, BlueprintReadOnly);
	UEnemyManagerHelperBase* SubsystemHelper;

private:
	TSubclassOf< class UEnemyManagerHelperBase > SubsystemHelperClass;

};