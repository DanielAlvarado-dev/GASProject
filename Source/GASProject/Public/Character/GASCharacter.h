// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GASCharacterBase.h"
#include "GASCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class GASPROJECT_API AGASCharacter : public AGASCharacterBase
{
	GENERATED_BODY()

public:
	AGASCharacter();

	virtual void Tick(float DeltaTime) override;


	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
protected:
	virtual void BeginPlay() override;
	
	virtual void InitAbilityActorInfo() override;
private:
	UPROPERTY(EditAnywhere) TObjectPtr<USpringArmComponent> SpringArm;
	UPROPERTY(EditAnywhere) TObjectPtr<UCameraComponent> Camera;
	


};
