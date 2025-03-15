// Copyright Daniel Alvarado


#include "GASCharacterBase.h"


AGASCharacterBase::AGASCharacterBase()
{

	PrimaryActorTick.bCanEverTick = true;

}


void AGASCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGASCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGASCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

