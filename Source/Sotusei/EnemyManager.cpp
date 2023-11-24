// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManager.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

UEnemyManager::UEnemyManager()
{
	// 拡張用BPのクラス情報を検索・取得。パスの指定には注意
    // .ini や プロジェクト設定でBPアセットのパスを設定できるようにしておくと親切
	static ConstructorHelpers::FClassFinder<UEnemyManagerHelperBase> BluePrintFile(TEXT("/Game/Enemy/BP_EnemyManager"));
	if (BluePrintFile.Class)
	{
		SubsystemHelperClass = (UClass*)BluePrintFile.Class;
	}
}

void UEnemyManager::Initialize(FSubsystemCollectionBase& Collection)
{
	SubsystemHelper = nullptr;

	if (SubsystemHelperClass)
	{
		// 拡張用BPを生成・設定
		SubsystemHelper = NewObject<UEnemyManagerHelperBase>(GetTransientPackage(), SubsystemHelperClass);
	}	
}

void UEnemyManager::Deinitialize()
{
	SubsystemHelper = nullptr;	
}
