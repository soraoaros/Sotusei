// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManager.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

UEnemyManager::UEnemyManager()
{
	// �g���pBP�̃N���X���������E�擾�B�p�X�̎w��ɂ͒���
    // .ini �� �v���W�F�N�g�ݒ��BP�A�Z�b�g�̃p�X��ݒ�ł���悤�ɂ��Ă����Ɛe��
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
		// �g���pBP�𐶐��E�ݒ�
		SubsystemHelper = NewObject<UEnemyManagerHelperBase>(GetTransientPackage(), SubsystemHelperClass);
	}	
}

void UEnemyManager::Deinitialize()
{
	SubsystemHelper = nullptr;	
}
