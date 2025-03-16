// Copyright Daniel Alvarado


#include "Actors/GASEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/GASAttributeSet.h"
#include "Components/SphereComponent.h"


AGASEffectActor::AGASEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	SetRootComponent(MeshComponent);
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(GetRootComponent());
	
}


void AGASEffectActor::BeginPlay()
{
	Super::BeginPlay();
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AGASEffectActor::OnOverlap);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AGASEffectActor::EndOverlap);
}

void AGASEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		// TODO: Change this to apply a Gameplay Effect. For now, using const_cast to modify the attribute directly.
		const UGASAttributeSet* GASAttributeSet = Cast<UGASAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UGASAttributeSet::StaticClass()));
		UGASAttributeSet* MutableGASAttributeSet = const_cast<UGASAttributeSet*>(GASAttributeSet);
		MutableGASAttributeSet->SetHealth(GASAttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void AGASEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}



