// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemGlobals.h"
#include "GasAbilitySystemGlobals.generated.h"

/**
 * 
 */
UCLASS()
class GASPROJECT_API UGasAbilitySystemGlobals : public UAbilitySystemGlobals
{
	GENERATED_BODY()

	virtual FGameplayEffectContext* AllocGameplayEffectContext() const override;
};
