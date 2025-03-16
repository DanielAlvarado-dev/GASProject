// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GASWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class GASPROJECT_API UGASWidgetController : public UObject
{
	GENERATED_BODY()

public:


protected:
	UPROPERTY(BlueprintReadOnly,Category = WidgetController)TObjectPtr<APlayerController> PlayerController;
	UPROPERTY(BlueprintReadOnly,Category = WidgetController)TObjectPtr<APlayerState> PlayerState;
	UPROPERTY(BlueprintReadOnly,Category = WidgetController)TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(BlueprintReadOnly,Category = WidgetController)TObjectPtr<UAttributeSet> AttributeSet;
};
