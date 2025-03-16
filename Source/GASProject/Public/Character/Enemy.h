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

	UPROPERTY(BlueprintReadOnly) bool bHighlighted = false;

protected:

	virtual void BeginPlay() override;

};
