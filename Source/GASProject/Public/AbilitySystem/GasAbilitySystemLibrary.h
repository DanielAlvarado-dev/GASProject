// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "Data/CharacterClassInfo.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GasAbilitySystemLibrary.generated.h"

class UAttributeMenuWidgetController;
class UOverlayWidgetController;

UCLASS()
class GASPROJECT_API UGasAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category = "GasAbilitySystemLibrary | WidgetController")
	static UOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category = "GasAbilitySystemLibrary | WidgetController")
	static UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "GasAbilitySystemLibrary | Character Class Defaults")
	static void InitializeDefaultAttributes(const UObject* WorldContextObject, ECharacterClass CharacterClass, float Level, UAbilitySystemComponent* ASC);

	static void GiveStartupAbilities(const UObject* WorldContextObject, UAbilitySystemComponent* ASC);
	
	UFUNCTION(BlueprintCallable, Category = "GasAbilitySystemLibrary | Character Class Defaults")
	static UCharacterClassInfo* GetCharacterClassInfo(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category = "GasAbilitySystemLibrary | GameplayEffects")
	static bool IsBlockedHit(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category = "GasAbilitySystemLibrary | GameplayEffects")
	static bool IsCriticalHit(const FGameplayEffectContextHandle& EffectContextHandle);
	
	UFUNCTION(BlueprintCallable, Category = "GasAbilitySystemLibrary | GameplayEffects")
	static void SetIsBlockedHit(UPARAM(ref)FGameplayEffectContextHandle& EffectContextHandle, bool bInIsBlockedHit);
	
	UFUNCTION(BlueprintCallable, Category = "GasAbilitySystemLibrary | GameplayEffects")
	static void SetIsCriticalHit(UPARAM(ref)FGameplayEffectContextHandle& EffectContextHandle, bool bInIsCriticalHit);
};
