// 

#include "MAbilitySystemComponent.h"

#include "Aura/Utils/MDebugUtils.h"

UMAbilitySystemComponent::UMAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicated(true);
}

void UMAbilitySystemComponent::OnAbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UMAbilitySystemComponent::OnEffectApplied);
}

void UMAbilitySystemComponent::OnEffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	OnEffectAppliedDelegate.Broadcast(TagContainer);
}



