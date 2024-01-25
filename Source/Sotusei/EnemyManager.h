// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "EnemyManager.generated.h"

/**
 * 
 */
// 拡張用BPのベースとなるクラス
UCLASS(Blueprintable, Abstract, MinimalAPI, meta = (ShowWorldContextPin))
class UEnemyManagerHelperBase : public UObject
{
	GENERATED_BODY()

public:
	// 処理の中身はBP側で書くことを宣言

	// パラメータ取得
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void GetSpawnParams(TArray<FTransform>& transforms, TArray<FName>& names, TArray<float>& nums, TArray<float>& spawnCD, TArray<bool>& isPossible);

	// パラメータ設定
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetSpawnParams(const TArray<FTransform>& transforms, const TArray<FName>& names, const TArray<float>& nums, const TArray<float>& spawnCD, const TArray<bool>& isPossible);


	// パラメータ追加
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void AddSpawnParam(UPARAM(ref) FTransform& transform, UPARAM(ref) FName& name, UPARAM(ref) float& num);


	// パラメータ全消去
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void ClearSpawnParams();


	// クールダウン更新
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

	// 拡張用BPのプロパティ
	UPROPERTY(Transient, BlueprintReadOnly);
	UEnemyManagerHelperBase* SubsystemHelper;

private:
	TSubclassOf< class UEnemyManagerHelperBase > SubsystemHelperClass;

};