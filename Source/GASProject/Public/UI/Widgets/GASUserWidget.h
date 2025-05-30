﻿// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GASUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class GASPROJECT_API UGASUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)void SetWidgetController(UObject* InWidgetController);
	UPROPERTY(BlueprintReadOnly) TObjectPtr<UObject> WidgetController;

protected:

	UFUNCTION(BlueprintImplementableEvent) void WidgetControllerSet();
};