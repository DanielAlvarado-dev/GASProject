// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GASEffectActor.generated.h"

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
	
	UFUNCTION() virtual void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
UPROPERTY(EditAnywhere)	TObjectPtr<USphereComponent> SphereComponent;
	UPROPERTY(EditAnywhere)	TObjectPtr<UStaticMeshComponent> MeshComponent;
};
