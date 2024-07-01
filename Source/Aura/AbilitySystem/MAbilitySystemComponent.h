// 

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"

#include "MAbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FMEffectAssetTags, const FGameplayTagContainer& /* Asset tags */);
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AURA_API UMAbilitySystemComponent: public UAbilitySystemComponent
{
	GENERATED_BODY()

public:

	UMAbilitySystemComponent();

	FMEffectAssetTags OnEffectAppliedDelegate;

	void OnAbilityActorInfoSet();

protected:

	void OnEffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& GameplayEffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle);

};
