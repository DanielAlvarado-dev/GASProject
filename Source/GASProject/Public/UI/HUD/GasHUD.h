// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/WidgetController/GASWidgetController.h"
#include "GasHUD.generated.h"

class UAttributeMenuWidgetController;
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

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
	
protected:


private:
	UPROPERTY() TObjectPtr<UGASUserWidget> OverlayWidget;
	
	UPROPERTY(EditAnywhere) TSubclassOf<UGASUserWidget> OverlayWidgetClass;

	UPROPERTY()TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
	UPROPERTY()TObjectPtr<UAttributeMenuWidgetController> AttributeMenuWidgetController;

	UPROPERTY(EditAnywhere)TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
	UPROPERTY(EditAnywhere)TSubclassOf<UAttributeMenuWidgetController> AttributeMenuWidgetControllerClass;
};
