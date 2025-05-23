﻿// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "GasInputConfig.generated.h"

USTRUCT(BlueprintType)
struct FGasInputAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly) const class UInputAction* InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly) FGameplayTag InputTag = FGameplayTag();
};

/**
 * 
 */
UCLASS()
class GASPROJECT_API UGasInputConfig : public UDataAsset
{
	GENERATED_BODY()

public:

	const UInputAction* FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound = false) const;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly) TArray<FGasInputAction> AbilityInputActions;
};
