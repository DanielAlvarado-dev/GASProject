// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GASCharacterBase.h"
#include "GASCharacter.generated.h"

UCLASS()
class GASPROJECT_API AGASCharacter : public AGASCharacterBase
{
	GENERATED_BODY()

public:
	AGASCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	


};
