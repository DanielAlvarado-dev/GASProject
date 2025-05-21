// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "GasAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class GASPROJECT_API UGasAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	static UGasAssetManager& Get();

protected:

	virtual void StartInitialLoading() override;
};
