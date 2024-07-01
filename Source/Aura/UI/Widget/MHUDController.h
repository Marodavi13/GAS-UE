// 

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "Aura/UI/MWidgetController.h"
#include "MHUDController.generated.h"

class UMUserWidget;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMOnStatChanged, float, NewStatValue);

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

	virtual void BroadcastInitialValues() override;
	
	void BindAttributesCallbacks();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI Data")
	TObjectPtr<UDataTable> MessageWidgetDataTable = nullptr;
	
	void HealthChanged(const FOnAttributeChangeData& Data);
	void MaxHealthChanged(const FOnAttributeChangeData& Data);
	void ManaChanged(const FOnAttributeChangeData& Data);
	void MaxManaChanged(const FOnAttributeChangeData& Data);

};
