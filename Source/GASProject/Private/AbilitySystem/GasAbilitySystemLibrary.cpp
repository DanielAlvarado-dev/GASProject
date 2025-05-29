// Copyright Daniel Alvarado


#include "AbilitySystem/GasAbilitySystemLibrary.h"

#include "GasAbilityTypes.h"
#include "GameMode/GASGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Player/GASPlayerState.h"
#include "UI/HUD/GasHUD.h"
#include "UI/WidgetController/GASWidgetController.h"

UOverlayWidgetController* UGasAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if(APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if(AGasHUD* GasHUD = Cast<AGasHUD>(PC->GetHUD()))
		{
			AGASPlayerState* PS = PC->GetPlayerState<AGASPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return GasHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* UGasAbilitySystemLibrary::GetAttributeMenuWidgetController(const UObject* WorldContextObject)
{
	if(APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if(AGasHUD* GasHUD = Cast<AGasHUD>(PC->GetHUD()))
		{
			AGASPlayerState* PS = PC->GetPlayerState<AGASPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return GasHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

void UGasAbilitySystemLibrary::InitializeDefaultAttributes(const UObject* WorldContextObject,
	ECharacterClass CharacterClass, float Level, UAbilitySystemComponent* ASC)
{
	const AActor* AvatarActor = ASC->GetAvatarActor();

	const UCharacterClassInfo* CharacterClassInfo = GetCharacterClassInfo(WorldContextObject);
	const FCharacterClassDefaultInfo ClassInfo = CharacterClassInfo->GetCharacterClassInfo(CharacterClass);

	FGameplayEffectContextHandle PrimaryAttributesContextHandle = ASC->MakeEffectContext();
	PrimaryAttributesContextHandle.AddSourceObject(AvatarActor);
	
	const FGameplayEffectSpecHandle PrimaryAttributeSpecHandle = ASC->MakeOutgoingSpec(ClassInfo.PrimaryAttributes, Level, PrimaryAttributesContextHandle);
	ASC->ApplyGameplayEffectSpecToSelf(*PrimaryAttributeSpecHandle.Data.Get());

	FGameplayEffectContextHandle SecondaryAttributesContextHandle = ASC->MakeEffectContext();
	SecondaryAttributesContextHandle.AddSourceObject(AvatarActor);

	const FGameplayEffectSpecHandle SecondaryAttributeSpecHandle = ASC->MakeOutgoingSpec(CharacterClassInfo->SecondaryAttributes, Level, SecondaryAttributesContextHandle);
	ASC->ApplyGameplayEffectSpecToSelf(*SecondaryAttributeSpecHandle.Data.Get());

	FGameplayEffectContextHandle VitalAttributesContextHandle = ASC->MakeEffectContext();
	VitalAttributesContextHandle.AddSourceObject(AvatarActor);

	const FGameplayEffectSpecHandle VitalAttributeSpecHandle = ASC->MakeOutgoingSpec(CharacterClassInfo->VitalAttributes, Level, VitalAttributesContextHandle);
	ASC->ApplyGameplayEffectSpecToSelf(*VitalAttributeSpecHandle.Data.Get());

	
}

void UGasAbilitySystemLibrary::GiveStartupAbilities(const UObject* WorldContextObject, UAbilitySystemComponent* ASC)
{
	const UCharacterClassInfo* CharacterClassInfo = GetCharacterClassInfo(WorldContextObject);
	for(const TSubclassOf<UGameplayAbility> Ability : CharacterClassInfo->CommonAbilities)
	{
		ASC->GiveAbility(FGameplayAbilitySpec(Ability, 1));
	}
}

UCharacterClassInfo* UGasAbilitySystemLibrary::GetCharacterClassInfo(const UObject* WorldContextObject)
{
	const AGASGameMode* GameMode = Cast<AGASGameMode>(UGameplayStatics::GetGameMode(WorldContextObject));
	if(GameMode == nullptr) return nullptr;
	return GameMode->CharacterClassInfo;
}

bool UGasAbilitySystemLibrary::IsBlockedHit(const FGameplayEffectContextHandle& EffectContextHandle)
{
	if(const FGasGameplayEffectContext* GasContext = static_cast<const FGasGameplayEffectContext*>(EffectContextHandle.Get()))
	{
		return GasContext->IsBlockedHit();
	}
	return false;
}

bool UGasAbilitySystemLibrary::IsCriticalHit(const FGameplayEffectContextHandle& EffectContextHandle)
{
	if(const FGasGameplayEffectContext* GasContext = static_cast<const FGasGameplayEffectContext*>(EffectContextHandle.Get()))
	{
		return GasContext->IsCriticalHit();
	}
	return false;
}

void UGasAbilitySystemLibrary::SetIsBlockedHit(FGameplayEffectContextHandle& EffectContextHandle, bool bInIsBlockedHit)
{
	if(FGasGameplayEffectContext* GasContext = static_cast< FGasGameplayEffectContext*>(EffectContextHandle.Get()))
	{
		GasContext->SetIsBlockedHit(bInIsBlockedHit);
	}
}

void UGasAbilitySystemLibrary::SetIsCriticalHit(FGameplayEffectContextHandle& EffectContextHandle,
	bool bInIsCriticalHit)
{
	if(FGasGameplayEffectContext* GasContext = static_cast< FGasGameplayEffectContext*>(EffectContextHandle.Get()))
	{
		GasContext->SetIsCriticalHit(bInIsCriticalHit);
	}
}

