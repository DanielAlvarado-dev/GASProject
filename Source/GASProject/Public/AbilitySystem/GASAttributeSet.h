// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "GASAttributeSet.generated.h"

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties(){}

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY() UAbilitySystemComponent* SourceASC = nullptr;
	UPROPERTY() AActor* SourceAvatarActor = nullptr;
	UPROPERTY() AController* SourceController = nullptr;
	UPROPERTY() ACharacter* SourceCharacter = nullptr;

	UPROPERTY() UAbilitySystemComponent* TargetASC = nullptr;
	UPROPERTY() AActor* TargetAvatarActor = nullptr;
	UPROPERTY() AController* TargetController = nullptr;
	UPROPERTY() ACharacter* TargetCharacter = nullptr;
	
};

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

template <class  T>
using TStaticFuncPtr = typename  TBaseStaticDelegateInstance<T, FDefaultDelegateUserPolicy>::FFuncPtr;
/**
 * 
 */
UCLASS()
class GASPROJECT_API UGASAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UGASAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	TMap<FGameplayTag, TStaticFuncPtr<FGameplayAttribute()>> TagsToAttributes;

	/*
	 *Primary Attributes
	 */

	UPROPERTY(ReplicatedUsing = OnRep_Strength,BlueprintReadOnly,Category ="Primary Attributes") FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Strength);

	UPROPERTY(ReplicatedUsing = OnRep_Intelligence,BlueprintReadOnly,Category ="Primary Attributes") FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Intelligence);
	
	UPROPERTY(ReplicatedUsing = OnRep_Resilience,BlueprintReadOnly,Category ="Primary Attributes") FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Resilience);
	
	UPROPERTY(ReplicatedUsing = OnRep_Vigor,BlueprintReadOnly,Category ="Primary Attributes") FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Vigor);

	/*
 *Secondary Attributes
 */
	UPROPERTY(ReplicatedUsing = OnRep_Armor,BlueprintReadOnly,Category ="Secondary Attributes") FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Armor);

	UPROPERTY(ReplicatedUsing = OnRep_ArmorPenetration,BlueprintReadOnly,Category ="Secondary Attributes") FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, ArmorPenetration);

	UPROPERTY(ReplicatedUsing = OnRep_BlockChance,BlueprintReadOnly,Category ="Secondary Attributes") FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, BlockChance);

	UPROPERTY(ReplicatedUsing = OnRep_CriticalHitChance,BlueprintReadOnly,Category ="Secondary Attributes") FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, CriticalHitChance);

	UPROPERTY(ReplicatedUsing = OnRep_CriticalHitDamage,BlueprintReadOnly,Category ="Secondary Attributes") FGameplayAttributeData CriticalHitDamage;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, CriticalHitDamage);

	UPROPERTY(ReplicatedUsing = OnRep_CriticalHitResistance,BlueprintReadOnly,Category ="Secondary Attributes") FGameplayAttributeData CriticalHitResistance;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, CriticalHitResistance);

	UPROPERTY(ReplicatedUsing = OnRep_HealthRegeneration,BlueprintReadOnly,Category ="Secondary Attributes") FGameplayAttributeData HealthRegeneration;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, HealthRegeneration);

	UPROPERTY(ReplicatedUsing = OnRep_ManaRegeneration,BlueprintReadOnly,Category ="Secondary Attributes") FGameplayAttributeData ManaRegeneration;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, ManaRegeneration);

	UPROPERTY(ReplicatedUsing = OnRep_MaxHealth,BlueprintReadOnly,Category ="Vital Attributes") FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxHealth);
	
	UPROPERTY(ReplicatedUsing = OnRep_MaxMana,BlueprintReadOnly,Category ="Vital Attributes") FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxMana);
	/*
	 *VitalAttributes
	 */
	
	/** Health*/
	UPROPERTY(ReplicatedUsing = OnRep_Health,BlueprintReadOnly,Category ="Vital Attributes") FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Health);


	/** Mana*/
	UPROPERTY(ReplicatedUsing = OnRep_Mana,BlueprintReadOnly,Category ="Vital Attributes") FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Mana);


	/** Health*/
	UFUNCTION()  void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	UFUNCTION()  void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	
	/** Mana*/
	UFUNCTION()  void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
	UFUNCTION()  void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

	/** Strength*/
	UFUNCTION()  void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;
	
	/** Intelligence*/
	UFUNCTION()  void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;
	
	/** Resiliance*/
	UFUNCTION()  void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;

	/** Vigor*/
	UFUNCTION()  void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;

	/** Armor*/
	UFUNCTION()  void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;

	/** Armor Penetration*/
	UFUNCTION()  void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const;

	/** Block Chance*/
	UFUNCTION()  void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;

	/** Critical Hit Chance*/
	UFUNCTION()  void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const;

	/** Critical Hit Damage*/
	UFUNCTION()  void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const;

	/** Critical Hit Resistance*/
	UFUNCTION()  void OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance) const;

	/** Health Regeneration*/
	UFUNCTION()  void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration) const;
	
	/** Mana Regeneration*/
	UFUNCTION()  void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration) const;
	

	
private:

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
	
};





