// Copyright Daniel Alvarado


#include "Input/GasInputConfig.h"

const UInputAction* UGasInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for(const FGasInputAction& Action  : AbilityInputActions)
	{
		if(Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}
	if(bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Input Action not found for tag: %s"), *InputTag.ToString());
	}
	return nullptr;
}
