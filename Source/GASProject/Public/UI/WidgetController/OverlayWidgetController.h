// Copyright Daniel Alvarado

#pragma once

#include "CoreMinimal.h"
#include "GASWidgetController.h"
#include "OverlayWidgetController.generated.h"

USTRUCT(BlueprintType)
struct FUIWidgetRow : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FGameplayTag MessageTag = FGameplayTag();
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FText Message = FText();
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<class UGASUserWidget> MessageWidgetClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UTexture2D* Image = nullptr;
};

class UGASUserWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributedChangedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMessageWidgetRowSignature, FUIWidgetRow,  Row);


/**
 * 
 */
UCLASS(BlueprintType,Blueprintable)
class GASPROJECT_API UOverlayWidgetController : public UGASWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes") FOnAttributedChangedSignature OnHealthChanged;
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes") FOnAttributedChangedSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes") FOnAttributedChangedSignature OnManaChanged;
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes") FOnAttributedChangedSignature OnMaxManaChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Messages") FMessageWidgetRowSignature MessageWidgetRowDelegate;

protected:

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = WidgetData)	TObjectPtr<UDataTable> MessageWidgetDataTable = nullptr;

	template<typename T>
	T* GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag);
};

template <typename T>
T* UOverlayWidgetController::GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag)
{
		return DataTable->FindRow<T>(Tag.GetTagName(), TEXT(""));
}
