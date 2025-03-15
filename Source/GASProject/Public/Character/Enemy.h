// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GASCharacterBase.h"
#include "Enemy.generated.h"

UCLASS()
class GASPROJECT_API AEnemy : public AGASCharacterBase
{
	GENERATED_BODY()

public:

	AEnemy();
	virtual void Tick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;

};
