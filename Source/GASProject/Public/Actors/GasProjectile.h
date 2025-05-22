// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "GameFramework/Actor.h"
#include "GasProjectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;
class UNiagaraSystem;
class USoundBase;

UCLASS()
class GASPROJECT_API AGasProjectile : public AActor
{
	GENERATED_BODY()

public:
	AGasProjectile();

	UPROPERTY(VisibleAnywhere) TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;
	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = true)) FGameplayEffectSpecHandle DamageEffectSpecHandle;
protected:
	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void BeginPlay() override;

	virtual void Destroyed() override;
	
private:

	bool bHit = false;

	
	UPROPERTY(EditAnywhere)float LifeSpan = 15.f;

	UPROPERTY(VisibleAnywhere) TObjectPtr<USphereComponent> Sphere;
	
	UPROPERTY(EditAnywhere) TObjectPtr<UNiagaraSystem> ImpactEffect;

	UPROPERTY(EditAnywhere)TObjectPtr<USoundBase> ImpactSound;
	UPROPERTY(EditAnywhere)TObjectPtr<USoundBase> LoopingSound;
	UPROPERTY()TObjectPtr<UAudioComponent> LoopingSoundComponent = nullptr;
};

