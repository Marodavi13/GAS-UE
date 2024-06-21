// 

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"

#include "MAbilitySystemComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AURA_API UMAbilitySystemComponent: public UAbilitySystemComponent
{
	GENERATED_BODY()

public:

	UMAbilitySystemComponent();


	void OnAbilityActorInfoSet();

protected:

	void OnEffectAplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& GameplayEffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle);

};
