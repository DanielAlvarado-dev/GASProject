// Copyright Daniel Alvarado


#include "AI/GasAIController.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"


// Sets default values
AGasAIController::AGasAIController()
{
	PrimaryActorTick.bCanEverTick = true;

	Blackboard= CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
	check(Blackboard);
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	check(BehaviorTreeComponent);
}

// Called when the game starts or when spawned
void AGasAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGasAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

