// Copyright Daniel Alvarado


#include "GasAssetManager.h"
#include "GASGameplayTags.h"
#include "AbilitySystemGlobals.h"


UGasAssetManager& UGasAssetManager::Get()
{
	check(GEngine)

	UGasAssetManager* GasAssetManager = Cast<UGasAssetManager>(GEngine->AssetManager);

	return *GasAssetManager;
}

void UGasAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	UAbilitySystemGlobals::Get().InitGlobalData();
	FGasGameplayTags::InitializeNativeGameplayTags();
}
