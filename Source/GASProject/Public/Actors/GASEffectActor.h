// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GASEffectActor.generated.h"

class UGameplayEffect;
class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class GASPROJECT_API AGASEffectActor : public AActor
{
	GENERATED_BODY()

public:
	AGASEffectActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable) void ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass);
	
	UPROPERTY(EditAnywhere,Category = "Applied Effects")TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
private:

};
