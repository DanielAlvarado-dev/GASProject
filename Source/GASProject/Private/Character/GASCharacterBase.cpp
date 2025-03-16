// Copyright Daniel Alvarado


#include "Character/GASCharacterBase.h"


AGASCharacterBase::AGASCharacterBase()
{

	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* AGASCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void AGASCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

