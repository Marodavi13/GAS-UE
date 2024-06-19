// 

#include "MEnemy.h"

#include "Aura/Aura.h"
#include "Aura/AbilitySystem/MAbilitySystemComponent.h"
#include "Aura/AbilitySystem/MAttributeSet.h"
#include "Aura/Component/MHighlightComponent.h"
#include "Components/CapsuleComponent.h"

AMEnemy::AMEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	HighlightComponent = CreateDefaultSubobject<UMHighlightComponent>(TEXT("Highlight Component"));

	AbilitySystemComponent = CreateDefaultSubobject<UMAbilitySystemComponent>(TEXT("Ability System Component"));
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UMAttributeSet>(TEXT("Attribute Set"));
}

void AMEnemy::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_HIGHLIGHT, ECR_Block);
}

void AMEnemy::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

