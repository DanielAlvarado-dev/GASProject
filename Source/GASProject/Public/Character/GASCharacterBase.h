// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interfaces/CombatInterface.h"
#include "GASCharacterBase.generated.h"

class UGameplayAbility;
class UGameplayEffect;
class UAttributeSet;
class UAbilitySystemComponent;
class UMotionWarpingComponent;

UCLASS(Abstract)
class GASPROJECT_API AGASCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	AGASCharacterBase();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

	//** ICombatInterface **//
	virtual void UpdateFacingTarget_Implementation(const FVector& TargetLocation) override;
	virtual UAnimMontage* GetHitReactMontage_Implementation() override;
	virtual void Die() override;

	virtual TArray<FTaggedMontage> GetAttackMontages_Implementation() override;
	
	UFUNCTION(NetMulticast,Reliable)virtual void MulticastHandleDeath();

	UPROPERTY(EditAnywhere,Category = Combat)
	TArray<FTaggedMontage> AttackMontages;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat") TObjectPtr<USkeletalMeshComponent> Weapon;
	UPROPERTY(EditAnywhere, Category = Combat)	FName WeaponTipSocketName  = FName("TipSocket");
	UPROPERTY(EditAnywhere, Category = Combat)	FName LeftHandSocketName  = FName("LeftHandSocket");
	UPROPERTY(EditAnywhere, Category = Combat)	FName RightHandSocketName  = FName("RightHandSocket");
	virtual FVector GetCombatSocketLocation_Implementation(const FGameplayTag& MontageTag) override;
	virtual bool IsDead_Implementation() const override;
	virtual AActor* GetAvatar_Implementation() override;

	UPROPERTY() TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY() TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "Combat")	TObjectPtr<UMotionWarpingComponent> MotionWarpingComponent;

	virtual void InitAbilityActorInfo();

	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category = "Attributes") TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category = "Attributes") TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category = "Attributes") TSubclassOf<UGameplayEffect> DefaultVitalAttributes;

	void ApplyEffectToSelf(const TSubclassOf<UGameplayEffect>& GameplayEffectClass, float Level) const;
	virtual void InitializeDefaultAttributes() const;

	void AddCharacterAbilities() const;


	/**Dissolve Effect*/
	
	void Dissolve();

	UFUNCTION(BlueprintImplementableEvent) void StartDissolveTimeline(UMaterialInstanceDynamic* DynamicMaterialInstance);
	UFUNCTION(BlueprintImplementableEvent) void StartWeaponDissolveTimeline(UMaterialInstanceDynamic* DynamicMaterialInstance);
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly) TObjectPtr<UMaterialInstance> DissolveMaterialInstance;
	UPROPERTY(EditAnywhere,BlueprintReadOnly) TObjectPtr<UMaterialInstance> WeaponDissolveMaterialInstance;

	bool bDead = false;
private:

	

	UPROPERTY(EditAnywhere,Category = Abilitites) TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	UPROPERTY(EditAnywhere, Category = Combat)TObjectPtr<UAnimMontage> HitReactMontage;


};
