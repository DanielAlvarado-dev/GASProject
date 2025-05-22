// Copyright Daniel Alvarado
#include "Player/GASPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "GameplayTagContainer.h"
#include "Debug/DebugHelper.h"
#include "Input/GasInputComponent.h"
#include "Interfaces/EnemyInterface.h"

AGASPlayerController::AGASPlayerController()
{
	bReplicates = true;
	
}

void AGASPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
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
 
	/**
	 * Line trace from cursor. There are several scenarios:
	 *  A. LastActor is null && ThisActor is null
	 *		- Do nothing
	 *	B. LastActor is null && ThisActor is valid
	 *		- Highlight ThisActor
	 *	C. LastActor is valid && ThisActor is null
	 *		- UnHighlight LastActor
	 *	D. Both actors are valid, but LastActor != ThisActor
	 *		- UnHighlight LastActor, and Highlight ThisActor
	 *	E. Both actors are valid, and are the same actor
	 *		- Do nothing
	 */
 
	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			// Case B
			ThisActor->HighlightActor();
		}
		else
		{
			// Case A - both are null, do nothing
		}
	}
	else // LastActor is valid
	{
		if (ThisActor == nullptr)
		{
			// Case C
			LastActor->UnhighlightActor();
		}
		else // both actors are valid
		{
			if (LastActor != ThisActor)
			{
				// Case D
				LastActor->UnhighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				// Case E - do nothing
			}
		}
	}

}

void AGASPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{

	Debug::Print(InputTag.ToString(), FColor::Green, 1);
}

void AGASPlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
	Debug::Print(InputTag.ToString(), FColor::Red, 0);
}

void AGASPlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
	Debug::Print(InputTag.ToString(), FColor::Blue, 0);
}
