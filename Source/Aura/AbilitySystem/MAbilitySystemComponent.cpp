// 

#include "MAbilitySystemComponent.h"

UMAbilitySystemComponent::UMAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicated(true);
}
