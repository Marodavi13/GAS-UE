// 

#include "MAbilitySystemComponent.h"

#include "Aura/Utils/MDebugUtils.h"
#include "Aura/Utils/MUtils.h"

UMAbilitySystemComponent::UMAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicated(true);
}

void UMAbilitySystemComponent::OnAbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UMAbilitySystemComponent::OnEffectAplied);
}

void UMAbilitySystemComponent::OnEffectAplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& GameplayEffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	UMDebugUtils::LogOnScreen(this, TEXT("Effect!"));
}



