// Copyright Daniel Alvarado
#include "Player/GASPlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "GameplayTagContainer.h"
#include "GASGameplayTags.h"
#include "AbilitySystem/GASAbilitySystemComponent.h"
#include "Debug/DebugHelper.h"
#include "GameFramework/Character.h"
#include "Input/GasInputComponent.h"
#include "Interfaces/EnemyInterface.h"
#include "UI/Widget/DamageTextComponent.h"

AGASPlayerController::AGASPlayerController()
{
	bReplicates = true;
	
}

void AGASPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}

void AGASPlayerController::ShowDamageNumber_Implementation(const float DamageAmount, ACharacter* TargetCharacter, bool bBlockedHit,bool bCriticalHit)
{
	if (IsValid(TargetCharacter) && DamageTextClass && IsLocalController())
	{
		UDamageTextComponent* DamageText = NewObject<UDamageTextComponent>(TargetCharacter, DamageTextClass);
		DamageText->RegisterComponent();
		DamageText->AttachToComponent(TargetCharacter->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		DamageText->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
		DamageText->SetDamageText(DamageAmount, bBlockedHit, bCriticalHit);
	}
}


void AGASPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UGasInputComponent* GasInputComponent = CastChecked<UGasInputComponent>(InputComponent);
		
	GasInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGASPlayerController::Move);
	GasInputComponent->BindAbilityActions(InputConfig, this,
		&AGASPlayerController::AbilityInputTagPressed,
		&AGASPlayerController::AbilityInputTagReleased,
		&AGASPlayerController::AbilityInputTagHeld);
}

void AGASPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(GASContext);

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(GASContext, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AGASPlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D MoveDirection = Value.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, MoveDirection.Y);
		ControlledPawn->AddMovementInput(RightDirection, MoveDirection.X);
	}
}

void AGASPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;
 
	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();
	
	if(LastActor != ThisActor)
	{
		if(LastActor)LastActor->UnhighlightActor();
		if(ThisActor)ThisActor->HighlightActor();
	}
}

void AGASPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
	if (InputTag.MatchesTagExact(FGasGameplayTags::Get().InputTag_LMB))
	{
		bTargeting = true;
	}
}

void AGASPlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
	if (!InputTag.MatchesTagExact(FGasGameplayTags::Get().InputTag_LMB))
	{
		if (GetASC()) GetASC()->AbilityInputTagReleased(InputTag);
		return;
	}
	if (GetASC()) GetASC()->AbilityInputTagReleased(InputTag);
	if (bTargeting)
	{
		if (GetASC()) GetASC()->AbilityInputTagReleased(InputTag);
	}
	else
	{
		bTargeting = false;
	}
}

void AGASPlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
	if (!InputTag.MatchesTagExact(FGasGameplayTags::Get().InputTag_LMB))
	{
		if (GetASC()) GetASC()->AbilityInputTagHeld(InputTag);
		return;
	}

	if (bTargeting)
	{
		if (GetASC()) GetASC()->AbilityInputTagHeld(InputTag);
	}
}

UGASAbilitySystemComponent* AGASPlayerController::GetASC()
{
	if (GASAbilitySystemComponent == nullptr)
	{
		GASAbilitySystemComponent = Cast<UGASAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}
	return GASAbilitySystemComponent;
}
