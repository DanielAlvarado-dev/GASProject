// Copyright Daniel Alvarado


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "GASGameplayTags.h"
#include "AbilitySystem/GASAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	UGASAttributeSet* AS = CastChecked<UGASAttributeSet>(AttributeSet);
	check(AttributeInfo)
	for(auto& Pair : AS->TagsToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
			[this, Pair](const FOnAttributeChangeData& Data)
				{
				BroadcastAttributeInfo(Pair.Key, Pair.Value());
		
				}
			);
	}

}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UGASAttributeSet* AS = CastChecked<UGASAttributeSet>(AttributeSet);

	check(AttributeInfo)
	for(auto& Pair : AS->TagsToAttributes)
	{
			BroadcastAttributeInfo(Pair.Key, Pair.Value());
	}
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& AttributeTag,
	const FGameplayAttribute& Attribute) const
{
	FGasAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
	Info.AttributeValue  = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}
