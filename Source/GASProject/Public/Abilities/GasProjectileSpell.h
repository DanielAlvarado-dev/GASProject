// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GasDamageGameplayAbility.h"
#include "GasGameplayAbility.h"
#include "GasProjectileSpell.generated.h"

class AGasProjectile;
class UGameplayEffect;
/**
 * 
 */
UCLASS()
class GASPROJECT_API UGasProjectileSpell : public UGasDamageGameplayAbility
{
	GENERATED_BODY()


protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	UFUNCTION(BlueprintCallable)void SpawnProjectile(const FVector& ProjectileTargetLocation);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)	TSubclassOf<AGasProjectile> ProjectileClass;
	
};
