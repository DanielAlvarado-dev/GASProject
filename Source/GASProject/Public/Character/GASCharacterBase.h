// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GASCharacterBase.generated.h"

UCLASS(Abstract)
class GASPROJECT_API AGASCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AGASCharacterBase();

protected:
	virtual void BeginPlay() override;

private:


};
