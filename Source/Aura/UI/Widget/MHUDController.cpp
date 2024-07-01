// 

#include "MHUDController.h"

#include "Aura/Aura.h"
#include "Aura/AbilitySystem/MAbilitySystemComponent.h"
#include "Aura/AbilitySystem/MAttributeSet.h"

void UMHUDController::BindAttributesCallbacks()
{
	AbilitySystem->GetGameplayAttributeValueChangeDelegate(
		Attributes->GetHealthAttribute()).AddUObject(this, &UMHUDController::HealthChanged);

	AbilitySystem->GetGameplayAttributeValueChangeDelegate(
	Attributes->GetMaxHealthAttribute()).AddUObject(this, &UMHUDController::MaxHealthChanged);

	AbilitySystem->GetGameplayAttributeValueChangeDelegate(
	Attributes->GetManaAttribute()).AddUObject(this, &UMHUDController::ManaChanged);

	AbilitySystem->GetGameplayAttributeValueChangeDelegate(
	Attributes->GetMaxManaAttribute()).AddUObject(this, &UMHUDController::MaxManaChanged);

	AbilitySystem->OnEffectAppliedDelegate.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			RETURN_IF_NULL(MessageWidgetDataTable);
		}
	);
}

void UMHUDController::HealthChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UMHUDController::MaxHealthChanged(const FOnAttributeChangeData& Data)
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UMHUDController::ManaChanged(const FOnAttributeChangeData& Data)
{
	OnManaChanged.Broadcast(Data.NewValue);

}

void UMHUDController::MaxManaChanged(const FOnAttributeChangeData& Data)
{
	OnMaxManaChanged.Broadcast(Data.NewValue);

}

void UMHUDController::BroadcastInitialValues()
{
	RETURN_IF_NOT_VALID_ENSURE(Attributes);
	
	OnHealthChanged.Broadcast(Attributes->GetHealth());
	OnMaxHealthChanged.Broadcast(Attributes->GetMaxHealth());
	OnManaChanged.Broadcast(Attributes->GetMana());
	OnMaxManaChanged.Broadcast(Attributes->GetMaxMana());
}
