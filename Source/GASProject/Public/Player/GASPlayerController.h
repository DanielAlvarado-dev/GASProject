// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GASPlayerController.generated.h"


class UDamageTextComponent;
struct FGameplayTag;
class UGasInputConfig;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;
class UGASAbilitySystemComponent;


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

	UFUNCTION(Client,Reliable)void ShowDamageNumber(float DamageAmount, ACharacter* TargetCharacter, bool bBlockedHit,bool bCriticalHit);
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category = Input) TObjectPtr<UInputMappingContext> GASContext;
	UPROPERTY(EditAnywhere, Category = Input) TObjectPtr<UInputAction> MoveAction;
	
	void Move(const FInputActionValue& Value);

	void CursorTrace();

	TScriptInterface<IEnemyInterface> ThisActor;
	TScriptInterface<IEnemyInterface> LastActor;

	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);

	UPROPERTY(EditDefaultsOnly,Category = Input)TObjectPtr<UGasInputConfig> InputConfig;

	UPROPERTY() TObjectPtr<UGASAbilitySystemComponent> GASAbilitySystemComponent;

	UGASAbilitySystemComponent* GetASC();
	
	bool bTargeting = false;

	UPROPERTY(EditDefaultsOnly) TSubclassOf<UDamageTextComponent> DamageTextClass;
};
