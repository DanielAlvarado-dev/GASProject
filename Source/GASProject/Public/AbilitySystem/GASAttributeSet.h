// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GASAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class GASPROJECT_API UGASAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UGASAttributeSet();

	UPROPERTY(ReplicatedUsing = OnRep_Health) FGameplayAttributeData Health;

	UFUNCTION() void OnRep_Health(const FGameplayAttributeData& OldHealth);
};
