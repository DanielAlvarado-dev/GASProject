// Copyright Daniel Alvarado


#include "AbilitySystem/Data/AttributeInfo.h"

FGasAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for(const FGasAttributeInfo& Info : AttributeInformation)
	{
		if(Info.AttributeTag == AttributeTag)
		{
			if(Info.AttributeTag.MatchesTag(AttributeTag))
			{
				return Info;
			}
		}
	}
	if(bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("AttributeInfo: AttributeTag %s not found"), *AttributeTag.ToString());
	}
	return FGasAttributeInfo();
}
