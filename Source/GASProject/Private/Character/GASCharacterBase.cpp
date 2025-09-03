// Copyright Daniel Alvarado

#include "Character/GASCharacterBase.h"
#include "AbilitySystem/GASAbilitySystemComponent.h"
#include "AbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "GASGameplayTags.h"
#include "GASProject/GASProject.h"
#include "MotionWarping/Public/MotionWarpingComponent.h"

AGASCharacterBase::AGASCharacterBase()
{

	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);
	GetCapsuleComponent()->SetGenerateOverlapEvents(false);
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_Projectile,ECR_Overlap);
	GetMesh()->SetGenerateOverlapEvents(true);
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	MotionWarpingComponent = CreateDefaultSubobject<UMotionWarpingComponent>(TEXT("MotionWarping"));
	

}

UAbilitySystemComponent* AGASCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void AGASCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

FVector AGASCharacterBase::GetCombatSocketLocation_Implementation(const FGameplayTag& MontageTag)
{
	const FGasGameplayTags& GameplayTags = FGasGameplayTags::Get();
	if( MontageTag.MatchesTagExact(GameplayTags.Montage_Attack_Weapon) && IsValid(Weapon)) {
		return Weapon->GetSocketLocation(WeaponTipSocketName);
	}
	if( MontageTag.MatchesTagExact(GameplayTags.Montage_Attack_LeftHand) ) {
		return Weapon->GetSocketLocation(LeftHandSocketName);
	}
	if( MontageTag.MatchesTagExact(GameplayTags.Montage_Attack_RightHand) ) {
		return Weapon->GetSocketLocation(RightHandSocketName);
	}
	return FVector::ZeroVector;
}

bool AGASCharacterBase::IsDead_Implementation() const
{
	return bDead;
}

AActor* AGASCharacterBase::GetAvatar_Implementation() 
{
	return this;
}

void AGASCharacterBase::InitAbilityActorInfo()
{
}

void AGASCharacterBase::ApplyEffectToSelf(const TSubclassOf<UGameplayEffect>& GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = 	GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(),GetAbilitySystemComponent());
}

void AGASCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultVitalAttributes, 1.f);
	
}

void AGASCharacterBase::AddCharacterAbilities() const
{
	UGASAbilitySystemComponent* GasAsc = CastChecked<UGASAbilitySystemComponent>(AbilitySystemComponent);
	if(!HasAuthority()) return;
	
	GasAsc->AddCharacterAbilities(StartupAbilities);
}

void AGASCharacterBase::Dissolve()
{
	if(IsValid(DissolveMaterialInstance))
	{
		if(UMaterialInstanceDynamic* DynamicMaterialInstance = UMaterialInstanceDynamic::Create(DissolveMaterialInstance, this))
		{
			GetMesh()->SetMaterial(0, DynamicMaterialInstance);
			StartDissolveTimeline(DynamicMaterialInstance);
			
		}
	}
	if(IsValid(WeaponDissolveMaterialInstance))
	{
		if(UMaterialInstanceDynamic* WeaponMaterialInst = UMaterialInstanceDynamic::Create(WeaponDissolveMaterialInstance, this))
		{
			Weapon->SetMaterial(0, WeaponMaterialInst);
			StartWeaponDissolveTimeline(WeaponMaterialInst);
		}
	}
}

void AGASCharacterBase::UpdateFacingTarget_Implementation(const FVector& TargetLocation)
{
	if (MotionWarpingComponent)
	{
		MotionWarpingComponent->AddOrUpdateWarpTargetFromLocation("FacingTarget", TargetLocation);
	}
}

UAnimMontage* AGASCharacterBase::GetHitReactMontage_Implementation()
{
	return HitReactMontage;
}

void AGASCharacterBase::Die() {
  Weapon->DetachFromComponent(
      FDetachmentTransformRules(EDetachmentRule::KeepWorld, true));
  MulticastHandleDeath();
}

TArray<FTaggedMontage> AGASCharacterBase::GetAttackMontages_Implementation() {
  return AttackMontages;
}

void AGASCharacterBase::MulticastHandleDeath_Implementation()
{
	Weapon->SetSimulatePhysics(true);
	Weapon->SetEnableGravity(true);
	Weapon->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);

	GetMesh()->SetEnableGravity(true);
	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	GetMesh()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Dissolve();
	bDead = true;
}

