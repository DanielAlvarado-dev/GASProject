// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "GasAIController.generated.h"


class UBehaviorTreeComponent;

UCLASS()
class GASPROJECT_API AGasAIController : public AAIController
{
	GENERATED_BODY()

public:
	AGasAIController();

protected:
	virtual void BeginPlay() override;
	

	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;


public:
	virtual void Tick(float DeltaTime) override;
};
