// 

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "Aura/Aura.h"
#include "Aura/UI/MWidgetController.h"
#include "MHUDController.generated.h"

class UMUserWidget;

USTRUCT()
struct FUIWidgetRow: public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	FGameplayTag AssetTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	FText Message;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	TSubclassOf<UMUserWidget> MessageWidgetClass = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	TObjectPtr<UTexture2D> Texture = nullptr;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMOnStatChanged, float, NewStatValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMessageWidgetRowSignature, FUIWidgetRow, Row);

/**
 *  Widget Controller for the player HUD 
 */
UCLASS(BlueprintType, Blueprintable)
class AURA_API UMHUDController: public UMWidgetController
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FMOnStatChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FMOnStatChanged OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FMOnStatChanged OnManaChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FMOnStatChanged OnMaxManaChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Messages")
	FMessageWidgetRowSignature OnEffectAppliedUIMessage;
	
	virtual void BroadcastInitialValues() override;
	
	void BindAttributesCallbacks();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI Data")
	TObjectPtr<UDataTable> MessageWidgetDataTable = nullptr;
	
	void HealthChanged(const FOnAttributeChangeData& Data);
	void MaxHealthChanged(const FOnAttributeChangeData& Data);
	void ManaChanged(const FOnAttributeChangeData& Data);
	void MaxManaChanged(const FOnAttributeChangeData& Data);

	template<typename T>
	T* GetDataTableRowByTag(UDataTable* DataTAble, const FGameplayTag& Tag);

};

template<typename T>
T* UMHUDController::GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag)
{
	RETURN_VALUE_IF_NULL(DataTable, nullptr);
	T* Row = DataTable->FindRow<T>(Tag.GetTagName(), TEXT(""));
	return Row;
}
