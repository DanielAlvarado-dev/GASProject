// Copyright Daniel Alvarado


#include "Character/Enemy.h"


AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemy::HighlightActor()
{
	bHighlighted = true;
	DrawDebugSphere(GetWorld(), GetActorLocation(), 100.0f, 24, FColor::Green, false, 1.0f);
}

void AEnemy::UnhighlightActor()
{
	bHighlighted = false;
	DrawDebugSphere(GetWorld(), GetActorLocation(), 100.0f, 24, FColor::Red, false, 1.0f);
}

