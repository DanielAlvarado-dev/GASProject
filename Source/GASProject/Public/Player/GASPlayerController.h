﻿// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GASPlayerController.generated.h"


class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;


/**
 * 
 */
UCLASS()
class GASPROJECT_API AGASPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AGASPlayerController();

	virtual void PlayerTick(float DeltaTime) override;

	virtual void SetupInputComponent() override;
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = Input) TObjectPtr<UInputMappingContext> GASContext;
	UPROPERTY(EditAnywhere, Category = Input) TObjectPtr<UInputAction> MoveAction;
	
	void Move(const FInputActionValue& Value);

	void CursorTrace();

	TScriptInterface<IEnemyInterface> ThisActor;
	TScriptInterface<IEnemyInterface> LastActor;
	
};
