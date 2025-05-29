// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GasGameplayAbility.h"
#include "GasDamageGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class GASPROJECT_API UGasDamageGameplayAbility : public UGasGameplayAbility
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)TSubclassOf<UGameplayEffect> DamageEffectClass;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Damage")TMap<FGameplayTag, FScalableFloat> DamageTypes;
};
