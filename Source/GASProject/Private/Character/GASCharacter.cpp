// Copyright Daniel Alvarado


#include "Character/GASCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/GASAbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/GASPlayerController.h"
#include "Player/GASPlayerState.h"
#include "UI/HUD/GasHUD.h"


AGASCharacter::AGASCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 400.f, 0);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AGASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGASCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilityActorInfo();
	AddCharacterAbilities();
}

void AGASCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilityActorInfo();
}

int32 AGASCharacter::GetPlayerLevel()
{
	const AGASPlayerState* GASPlayerState = GetPlayerState<AGASPlayerState>();
	check(GASPlayerState)
	return GASPlayerState->GetPlayerLevel();
}

void AGASCharacter::InitAbilityActorInfo()
{
	
	AGASPlayerState* GASPlayerState = GetPlayerState<AGASPlayerState>();
	check(GASPlayerState);
	GASPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(GASPlayerState, this);
	Cast<UGASAbilitySystemComponent>(GASPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	AbilitySystemComponent = GASPlayerState->GetAbilitySystemComponent();
	AttributeSet = GASPlayerState->GetAttributeSet();

	if(AGASPlayerController* GASPlayerController = Cast<AGASPlayerController>(GetController()))
	{
		if(AGasHUD* GasHUD = Cast<AGasHUD>(GASPlayerController->GetHUD()))
		{
			GasHUD->InitOverlay(GASPlayerController, GASPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
	InitializeDefaultAttributes();
}

