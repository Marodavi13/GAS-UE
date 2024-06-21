// 

#include "MEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Aura/Aura.h"

AMEffectActor::AMEffectActor()
{
	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot")));
}

void AMEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* AbilitySystemComp = GetAbilitySystemComponent(TargetActor);
	RETURN_IF_NOT_VALID(AbilitySystemComp);
	RETURN_IF_NULL_ENSURE(GameplayEffectClass);

	FGameplayEffectContextHandle ContextHandle = AbilitySystemComp->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = AbilitySystemComp->MakeOutgoingSpec(GameplayEffectClass, ActorLevel, ContextHandle);
	const FActiveGameplayEffectHandle Handle = AbilitySystemComp->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());

	RETURN_IF_FALSE(SpecHandle.Data.Get()->Def->DurationPolicy == EGameplayEffectDurationType::Infinite &&
					InfiniteEffectRemovalPolicy == EMEffectPolicy::OnEndOverlap);
	
	ActiveGameplayEffectHandles.Add(Handle, AbilitySystemComp);
}

void AMEffectActor::OnBeginOverlap(AActor* TargetActor)
{
	if (InstantEffectApplicationPolicy == EMEffectPolicy::OnBeginOverlap)
	{
		ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
	}

	if (DurationEffectApplicationPolicy == EMEffectPolicy::OnBeginOverlap)
	{
		ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
	}

	if (InfiniteEffectApplicationPolicy == EMEffectPolicy::OnBeginOverlap)
	{
		ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
	}
}

void AMEffectActor::OnEndOverlap(AActor* TargetActor)
{
	if (InstantEffectApplicationPolicy == EMEffectPolicy::OnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
	}
	
	if (DurationEffectApplicationPolicy == EMEffectPolicy::OnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
	}

	if (InfiniteEffectApplicationPolicy == EMEffectPolicy::OnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
	}
	
	if(InfiniteEffectRemovalPolicy == EMEffectPolicy::OnEndOverlap)
	{
		UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent(TargetActor);
		RETURN_IF_NOT_VALID(AbilitySystemComponent);

		for(auto It = ActiveGameplayEffectHandles.CreateIterator(); It; ++It)
		{
			if(It.Value() != AbilitySystemComponent)
			{
				continue;
			}

			AbilitySystemComponent->RemoveActiveGameplayEffect(It.Key(), 1);
			It.RemoveCurrent();
			break;
		}
	}
}
