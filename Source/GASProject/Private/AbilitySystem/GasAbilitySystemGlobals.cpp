// Copyright Daniel Alvarado


#include "AbilitySystem/GasAbilitySystemGlobals.h"

#include "GasAbilityTypes.h"

FGameplayEffectContext* UGasAbilitySystemGlobals::AllocGameplayEffectContext() const
{
	return new FGasGameplayEffectContext();
}
