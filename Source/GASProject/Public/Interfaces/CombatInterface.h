// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CombatInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UCombatInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GASPROJECT_API ICombatInterface
{
	GENERATED_BODY()

public:
	virtual int32 GetPlayerLevel();

	virtual FVector GetCombatSocketLocation();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UpdateFacingTarget(const FVector& TargetLocation);

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	UAnimMontage* GetHitReactMontage();

	virtual void Die() = 0;

};
