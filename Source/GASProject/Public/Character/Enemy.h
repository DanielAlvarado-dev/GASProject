// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GASCharacterBase.h"
#include "AbilitySystem/Data/CharacterClassInfo.h"
#include "Interfaces/EnemyInterface.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "Enemy.generated.h"

class UWidgetComponent;

UCLASS()
class GASPROJECT_API AEnemy : public AGASCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:

	AEnemy();
	virtual void Tick(float DeltaTime) override;

	// ** IEnemyInterface ** //
	virtual void HighlightActor() override;
	virtual void UnhighlightActor() override;
	// ** IEnemyInterface ** //

	//** ICombatInterface ** //
	virtual int32 GetPlayerLevel() override;
	/** CombatInterfaceEndpoint */

	UPROPERTY(BlueprintReadOnly) bool bHighlighted = false;

	UPROPERTY(BlueprintAssignable)	FOnAttributedChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable) FOnAttributedChangedSignature OnMaxHealthChanged;


protected:
	virtual void InitAbilityActorInfo() override;
	virtual void BeginPlay() override;
	virtual void InitializeDefaultAttributes() const override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Character class defaults")	int32 Level = 1;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Character class defaults") ECharacterClass CharacterClass = ECharacterClass::Warrior;

	UPROPERTY(EditAnywhere,BlueprintReadOnly) TObjectPtr<UWidgetComponent> HealthBar;
private:


};
