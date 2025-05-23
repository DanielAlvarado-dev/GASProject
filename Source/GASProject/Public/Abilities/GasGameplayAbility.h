// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GasGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class GASPROJECT_API UGasGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "Input") FGameplayTag StartupInputTag;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Damage")FScalableFloat Damage;
	
};
