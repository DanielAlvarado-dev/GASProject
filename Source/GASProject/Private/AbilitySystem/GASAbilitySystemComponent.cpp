// Copyright Daniel Alvarado


#include "AbilitySystem/GASAbilitySystemComponent.h"

void UGASAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UGASAbilitySystemComponent::EffectApplied);
}

void UGASAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                               const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	for(auto Tag: TagContainer)
	{
		//Todo: Broadcast the tag to the Widget Controller
		const FString Msg = FString::Printf(TEXT("Tag: %s"), *Tag.ToString());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, Msg);
	}
}
