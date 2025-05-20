// Copyright Daniel Alvarado


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/GASAbilitySystemComponent.h"
#include "AbilitySystem/GASAttributeSet.h"


void UOverlayWidgetController::BroadcastInitialValues()
{
	const UGASAttributeSet* GasAttributeSet = CastChecked<UGASAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(GasAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(GasAttributeSet->GetMaxHealth());

	OnManaChanged.Broadcast(GasAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(GasAttributeSet->GetMaxMana());
	
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UGASAttributeSet* GasAttributeSet = CastChecked<UGASAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		GasAttributeSet->GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
		);

	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	GasAttributeSet->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	GasAttributeSet->GetManaAttribute()).AddLambda(
	[this](const FOnAttributeChangeData& Data)
	{
		OnManaChanged.Broadcast(Data.NewValue);
	}
);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	GasAttributeSet->GetMaxManaAttribute()).AddLambda(
	[this](const FOnAttributeChangeData& Data)
	{
		OnMaxManaChanged.Broadcast(Data.NewValue);
	}
);

	Cast<UGASAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
			{
				for(auto Tag: AssetTags)
				{
					FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
					if(Tag.MatchesTag(MessageTag))
					{
						const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
						MessageWidgetRowDelegate.Broadcast(*Row);
					}
				}
			}
		);
}
