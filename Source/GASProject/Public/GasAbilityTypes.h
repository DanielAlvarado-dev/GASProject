#pragma once

#include "GameplayEffectTypes.h"
#include "GasAbilityTypes.generated.h"

USTRUCT(BlueprintType)
struct FGasGameplayEffectContext : public FGameplayEffectContext
{
	GENERATED_BODY()

public:

	bool IsCriticalHit() const { return bIsCriticalHit; }
	bool IsBlockedHit() const { return bIsBlockedHit; }

	void SetIsCriticalHit(const bool bInIsCriticalHit) { bIsCriticalHit = bInIsCriticalHit; }
	void SetIsBlockedHit(const bool bInIsBlockedHit) { bIsBlockedHit = bInIsBlockedHit; }

	virtual UScriptStruct* GetScriptStruct() const override
	{
		return FGasGameplayEffectContext::StaticStruct();
	}

	virtual bool NetSerialize(FArchive& Ar, UPackageMap* Map, bool& bOutSuccess) override;

	virtual FGameplayEffectContext* Duplicate() const override
	{
		FGasGameplayEffectContext* NewContext = new FGasGameplayEffectContext();
		*NewContext = *this;
		if (GetHitResult())
		{
			NewContext->AddHitResult(*GetHitResult(), true);
		}
		return NewContext;
	}

protected:
	UPROPERTY() bool bIsBlockedHit = false;
	UPROPERTY() bool bIsCriticalHit = false;
};

template<>
struct TStructOpsTypeTraits<FGasGameplayEffectContext> : public TStructOpsTypeTraitsBase2<FGasGameplayEffectContext>
{
	enum
	{
		WithNetSerializer = true,
		WithCopy = true
	};
};
