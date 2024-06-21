#include "MCharacterBase.h"

#include "Aura/AbilitySystem/MAbilitySystemComponent.h"
#include "Aura/AbilitySystem/MAttributeSet.h"

AMCharacterBase::AMCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetMesh(), TEXT("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AMCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AMCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void AMCharacterBase::InitAbilitySystem()
{
	InitAbilitySystem_Internal();
	AbilitySystemComponent->OnAbilityActorInfoSet();
}



