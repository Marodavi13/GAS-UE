// 

#include "MEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Aura/Aura.h"
#include "Aura/AbilitySystem/MAttributeSet.h"
#include "Components/SphereComponent.h"

AMEffectActor::AMEffectActor()
{

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	EffectCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Effect Collider"));
	EffectCollider->SetupAttachment(Mesh);
}

void AMEffectActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	EffectCollider->OnComponentBeginOverlap.AddUniqueDynamic(this, &AMEffectActor::OnBeginOverlap);
	EffectCollider->OnComponentEndOverlap.AddUniqueDynamic(this, &AMEffectActor::OnEndOverlap);
}

void AMEffectActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IAbilitySystemInterface* AbilityInterface = Cast<IAbilitySystemInterface>(OtherActor);
	RETURN_IF_NULL(AbilityInterface);

	const UAbilitySystemComponent* Ability = AbilityInterface->GetAbilitySystemComponent();
	const UMAttributeSet* Attributes = Cast<UMAttributeSet>(Ability->GetAttributeSet(UMAttributeSet::StaticClass()));

	const_cast<UMAttributeSet*>(Attributes)->SetMana(Attributes->GetHealth() + 25.f);
	Destroy();
}

void AMEffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}
