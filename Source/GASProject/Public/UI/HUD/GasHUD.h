﻿// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GasHUD.generated.h"

struct FWidgetControllerParams;
class UOverlayWidgetController;
class UGASUserWidget;
class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class GASPROJECT_API AGasHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY() TObjectPtr<UGASUserWidget> OverlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
	
protected:


private:
	UPROPERTY(EditAnywhere) TSubclassOf<UGASUserWidget> OverlayWidgetClass;

	UPROPERTY()TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
