// 

#include "MEnemy.h"

#include "Aura/Component/MHighlightComponent.h"
#include "Components/CapsuleComponent.h"

AMEnemy::AMEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
	HighlightComponent = CreateDefaultSubobject<UMHighlightComponent>(TEXT("Highlight Component"));
}

