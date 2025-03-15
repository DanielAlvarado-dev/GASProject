// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GASCharacterBase.generated.h"

UCLASS()
class GASPROJECT_API AGASCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AGASCharacterBase();
		virtual void Tick(float DeltaTime) override;
    	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:


};
