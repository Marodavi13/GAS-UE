// 

#include "MPlayerState.h"

#include "Aura/AbilitySystem/MAbilitySystemComponent.h"
#include "Aura/AbilitySystem/MAttributeSet.h"

AMPlayerState::AMPlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UMAbilitySystemComponent>(TEXT("Ability System Component"));
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<UMAttributeSet>(TEXT("Attribute Set"));
}

UAbilitySystemComponent* AMPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UMAttributeSet* AMPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
