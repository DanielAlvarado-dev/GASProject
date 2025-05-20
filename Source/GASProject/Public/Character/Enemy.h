// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GASCharacterBase.h"
#include "Interfaces/EnemyInterface.h"
#include "Enemy.generated.h"

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

protected:
	virtual void InitAbilityActorInfo() override;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Character class defaults")	int32 Level = 1;
private:


};
