// 

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "Aura/UI/MWidgetController.h"
#include "MHUDController.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMOnStatChanged, float, NewStatValue);
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


	void HealthChanged(const FOnAttributeChangeData& Data);
	void MaxHealthChanged(const FOnAttributeChangeData& Data);
	void ManaChanged(const FOnAttributeChangeData& Data);
	void MaxManaChanged(const FOnAttributeChangeData& Data);



};
