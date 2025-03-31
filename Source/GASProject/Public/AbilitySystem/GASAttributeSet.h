// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "GASAttributeSet.generated.h"

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
	
};
