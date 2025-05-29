// Copyright Daniel Alvarado


#include "GASGameplayTags.h"
#include "GameplayTagContainer.h"
#include "GameplayTagsManager.h"


FGasGameplayTags FGasGameplayTags::GameplayTags;

void FGasGameplayTags::InitializeNativeGameplayTags()
{

	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Strength"),
		FString("Increases physical damage")
		);

	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Intelligence"),
		FString("Increases magical damage")
		);

	GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Resilience"),
		FString("Increases Armor and Armor Penetration")
		);

	GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Vigor"),
		FString("Increases Health")
		);

	/*
	 * Secondary Attributes
	 */
	
	GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Armor"),
		FString("Reduces damage taken, improves Block Chance")
		);

	GameplayTags.Attributes_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.ArmorPenetration"),
		FString("Ignores Percentage of enemy Armor, increases Critical Hit Chance")
		);

	GameplayTags.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.BlockChance"),
		FString("Chance to cut incoming damage in half")
		);

	GameplayTags.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.CriticalHitChance"),
		FString("Chance to double damage plus critical hit bonus")
		);

	GameplayTags.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.CriticalHitDamage"),
		FString("Bonus damage added when a critical hit is scored")
		);

	GameplayTags.Attributes_Secondary_CriticalHitResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.CriticalHitResistance"),
		FString("Reduces Critical Hit Chance of attacking enemies")
		);

	GameplayTags.Attributes_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.HealthRegeneration"),
		FString("Amount of Health regenerated every 1 second")
		);

	GameplayTags.Attributes_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.ManaRegeneration"),
		FString("Amount of Mana regenerated every 1 second")
		);

	GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MaxHealth"),
		FString("Maximum amount of Health obtainable")
		);

	GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MaxMana"),
		FString("Maximum amount of Mana obtainable")
		);

		/*
	 * Inputs
	 */

	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.LMB"),
		FString("Left Mouse Button")
		);

	GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.RMB"),
		FString("Right Mouse Button")
		);

	GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.1"),
		FString("Input tag for 1 key")
		);

	GameplayTags.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.2"),
		FString("Input tag for 2 key")
		); 

	GameplayTags.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.3"),
		FString("Input tag for 3 key")
		);

	GameplayTags.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.4"),
		FString("Input tag for 4 key")
		);

	GameplayTags.Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Damage"),
		FString("Damage")
		);

	GameplayTags.Effects_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Effects.HitReact"),
		FString("Hit React Effect")
		);

	/*
	 *Damage Types
	 */

	GameplayTags.Damage_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Damage.Fire"),
		FString("Fire Damage")
		);

	GameplayTags.Damage_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Damage.Lightning"),
		FString("Lightning Damage")
		);

	GameplayTags.Damage_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Damage.Arcane"),
		FString("Arcane Damage")
		);
	
	GameplayTags.Damage_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Damage.Physical"),
		FString("Physical Damage")
		);


	/*
	 *resistances
	 */

	GameplayTags.Attributes_Resistance_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Resistance.Fire"),
		FString("Resistance to Fire Damage")
		);

	GameplayTags.Attributes_Resistance_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Resistance.Lightning"),
		FString("Resistance to Lightning Damage")
		);

	GameplayTags.Attributes_Resistance_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Resistance.Arcane"),
		FString("Resistance to Arcane Damage")
		);

	GameplayTags.Attributes_Resistance_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Resistance.Physical"),
		FString("Resistance to Physical Damage")
		);


	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Arcane, GameplayTags.Attributes_Resistance_Arcane);
	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Fire, GameplayTags.Attributes_Resistance_Fire);
	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Lightning, GameplayTags.Attributes_Resistance_Lightning);
	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Physical, GameplayTags.Attributes_Resistance_Physical);
}
