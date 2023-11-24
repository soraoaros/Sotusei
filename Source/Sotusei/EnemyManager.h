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
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void GetSpawnParams(TArray<FTransform>& transforms, TArray<FName>& names, TArray<int32>& nums);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void AddSpawnParam(UPARAM(ref) FTransform& transform, UPARAM(ref) FName& name, UPARAM(ref) int32& num);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void ClearSpawnParams();
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