// Copyright Daniel Alvarado


#include "Character/Enemy.h"

#include "AbilitySystemComponent.h"
#include "GASGameplayTags.h"
#include "AbilitySystem/GASAbilitySystemComponent.h"
#include "AbilitySystem/GasAbilitySystemLibrary.h"
#include "AbilitySystem/GASAttributeSet.h"
#include "AI/GasAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GASProject/GASProject.h"
#include "UI/Widgets/GASUserWidget.h"


AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UGASAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AttributeSet = CreateDefaultSubobject<UGASAttributeSet>("AttributeSet");

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = true;

	HealthBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthBar"));
	HealthBar->SetupAttachment(GetRootComponent());

	
}


void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	InitAbilityActorInfo();
	GetCharacterMovement()-> MaxWalkSpeed = bHitReacting ? 0.f : BaseWalkSpeed;
	if(HasAuthority())
	{
		UGasAbilitySystemLibrary::GiveStartupAbilities(this,AbilitySystemComponent, CharacterClass);
	}
	
	

	if (UGASUserWidget* AuraUserWidget = Cast<UGASUserWidget>(HealthBar->GetUserWidgetObject()))
	{
		AuraUserWidget->SetWidgetController(this);
	}
	
	if (const UGASAttributeSet* GasAs = Cast<UGASAttributeSet>(AttributeSet))
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(GasAs->GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
		);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(GasAs->GetMaxHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxHealthChanged.Broadcast(Data.NewValue);
			}
		);
	
		AbilitySystemComponent->RegisterGameplayTagEvent(	FGasGameplayTags::Get().Effects_HitReact, EGameplayTagEventType::NewOrRemoved).AddUObject(
			this,
			&AEnemy::HitReactTagChanged);

		OnMaxHealthChanged.Broadcast(GasAs->GetMaxHealth());
		OnHealthChanged.Broadcast(GasAs->GetHealth());
	}
}


void AEnemy::HitReactTagChanged(const FGameplayTag CallbackTag, int32 NewCount)
{
	bHitReacting = NewCount > 0;
	GetCharacterMovement()-> MaxWalkSpeed = bHitReacting ? 0.f : BaseWalkSpeed;
	if(GasAIController && GasAIController->GetBlackboardComponent())
	{
		GasAIController->GetBlackboardComponent()->SetValueAsBool(FName("HitReacting"), bHitReacting);
	}
	
}


void AEnemy::InitializeDefaultAttributes() const
{
	UGasAbilitySystemLibrary::InitializeDefaultAttributes(this, CharacterClass, Level, AbilitySystemComponent);
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemy::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if(!HasAuthority()) return;
	GasAIController = Cast<AGasAIController>(GetController());
	GasAIController->GetBlackboardComponent()->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
	GasAIController->RunBehaviorTree(BehaviorTree);
	GasAIController->GetBlackboardComponent()->SetValueAsBool(FName("HitReacting"), false);
	GasAIController->GetBlackboardComponent()->SetValueAsBool(FName("RangedAttacker"), CharacterClass != ECharacterClass::Warrior);
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

int32 AEnemy::GetPlayerLevel()
{
	return Level;
}

void AEnemy::Die()
{
	SetLifeSpan(LifeSpan);
	Super::Die();
}

void AEnemy::SetCombatTarget_Implementation(AActor* InCombatTarget)
{
	CombatTarget = InCombatTarget;
}

AActor* AEnemy::GetCombatTarget_Implementation() const
{
	return CombatTarget;
}

void AEnemy::InitAbilityActorInfo()
{
	
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UGASAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
	if(HasAuthority())
	{
		InitializeDefaultAttributes();
	}
}
