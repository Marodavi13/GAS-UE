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
};
