// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GASGameMode.generated.h"
class UCharacterClassInfo;

/**
 * 
 */
UCLASS()
class GASPROJECT_API AGASGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly,Category = "Character Class Defaults") TObjectPtr<UCharacterClassInfo> CharacterClassInfo;
	
};
