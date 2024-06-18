// 

#include "MEnemy.h"

#include "Aura/AbilitySystem/MAbilitySystemComponent.h"
#include "Aura/AbilitySystem/MAttributeSet.h"
#include "Aura/Component/MHighlightComponent.h"
#include "Components/CapsuleComponent.h"

AMEnemy::AMEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
	HighlightComponent = CreateDefaultSubobject<UMHighlightComponent>(TEXT("Highlight Component"));

	AbilitySystemComponent = CreateDefaultSubobject<UMAbilitySystemComponent>(TEXT("Ability System Component"));
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UMAttributeSet>(TEXT("Attribute Set"));
}

void AMEnemy::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

