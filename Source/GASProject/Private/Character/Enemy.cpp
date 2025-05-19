// Copyright Daniel Alvarado


#include "Character/Enemy.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/GASAbilitySystemComponent.h"
#include "AbilitySystem/GASAttributeSet.h"
#include "GASProject/GASProject.h"


AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UGASAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UGASAttributeSet>("AttributeSet");
	
}


void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	InitAbilityActorInfo();
	
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemy::HighlightActor()
{
	bHighlighted = true;
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->CustomDepthStencilValue = CUSTOM_DEPTH_RED;
	Weapon->SetRenderCustomDepth(true);
	Weapon->CustomDepthStencilValue = CUSTOM_DEPTH_RED;
}

void AEnemy::UnhighlightActor()
{
	bHighlighted = false;
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

void AEnemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UGASAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}
