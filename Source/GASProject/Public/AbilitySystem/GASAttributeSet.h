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

	/*
	 *Primary Attributes
	 */

	UPROPERTY(ReplicatedUsing = OnRep_Strength,BlueprintReadOnly,Category ="Primary Attributesi") FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Strength);

	UPROPERTY(ReplicatedUsing = OnRep_Intelligence,BlueprintReadOnly,Category ="Primary Attributesi") FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Intelligence);
	
	UPROPERTY(ReplicatedUsing = OnRep_Resilience,BlueprintReadOnly,Category ="Primary Attributesi") FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Resilience);
	
	UPROPERTY(ReplicatedUsing = OnRep_Vigor,BlueprintReadOnly,Category ="Primary Attributesi") FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Vigor);
	
	/*
	 *VitalAttributes
	 */
	
	/** Health*/
	UPROPERTY(ReplicatedUsing = OnRep_Health,BlueprintReadOnly,Category ="Vital Attributesi") FGameplayAttributeData Health;
	UPROPERTY(ReplicatedUsing = OnRep_MaxHealth,BlueprintReadOnly,Category ="Vital Attributesi") FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Health);
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxHealth);

	/** Mana*/
	UPROPERTY(ReplicatedUsing = OnRep_Mana,BlueprintReadOnly,Category ="Vital Attributesi") FGameplayAttributeData Mana;
	UPROPERTY(ReplicatedUsing = OnRep_MaxMana,BlueprintReadOnly,Category ="Vital Attributesi") FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Mana);
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxMana);

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

	
private:

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
	
};





