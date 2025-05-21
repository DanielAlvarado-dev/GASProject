// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GasAbilitySystemLibrary.generated.h"

class UOverlayWidgetController;
/**
 * 
 */
UCLASS()
class GASPROJECT_API UGasAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category = "GasAbilitySystemLibrary | WidgetController") static UOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category = "GasAbilitySystemLibrary | WidgetController") static UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const UObject* WorldContextObject);};
