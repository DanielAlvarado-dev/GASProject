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

public:
	UFUNCTION(BlueprintCallable)
	void CauseDamage(AActor* TargetActor);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)TSubclassOf<UGameplayEffect> DamageEffectClass;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Damage")TMap<FGameplayTag, FScalableFloat> DamageTypes;
};
