// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GasGameplayAbility.h"
#include "GasProjectileSpell.generated.h"

class AGasProjectile;
class UGameplayEffect;
/**
 * 
 */
UCLASS()
class GASPROJECT_API UGasProjectileSpell : public UGasGameplayAbility
{
	GENERATED_BODY()


protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	UFUNCTION(BlueprintCallable)void SpawnProjectile(const FVector& ProjectileTargetLocation);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)	TSubclassOf<AGasProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere)TSubclassOf<UGameplayEffect> DamageEffectClass;
	UPROPERTY(EditAnywhere)TSubclassOf<UGameplayEffect> HitReactEffectClass;
};
