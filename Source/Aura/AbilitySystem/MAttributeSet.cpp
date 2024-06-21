// 

#include "MAttributeSet.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "Aura/Aura.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"

FMEffectProperties::FMEffectProperties(const FGameplayEffectModCallbackData& Data)
{
	/* Source: causer of the effect
	 * Target: Target of the effect (owner of this AttributeSet) */
	ContextHandle = Data.EffectSpec.GetContext();;

	SetSourceProperties(ContextHandle.GetOriginalInstigatorAbilitySystemComponent());
	SetTargetProperties(&Data.Target);
}

void FMEffectProperties::SetSourceProperties(UAbilitySystemComponent* AbilitySystem)
{
	SourceASC = AbilitySystem;
	SourceAvatar = SourceASC->AbilityActorInfo->AvatarActor.Get();
	SourceCharacter = Cast<ACharacter>(SourceAvatar);
	SourceController = SourceASC->AbilityActorInfo->PlayerController.Get();

	const APawn* SourcePawnAvatar = Cast<APawn>(SourceAvatar);
	if(!SourceController && SourcePawnAvatar)
	{
		SourceController = SourcePawnAvatar->GetController();
	}
}

void FMEffectProperties::SetTargetProperties(UAbilitySystemComponent* AbilitySystem)
{
	TargetASC = AbilitySystem;
	TargetAvatar = TargetASC->AbilityActorInfo->AvatarActor.Get();
	TargetCharacter = Cast<ACharacter>(TargetAvatar);
	TargetController = TargetASC->AbilityActorInfo->PlayerController.Get();

	const APawn* TargetPawnAvatar = Cast<APawn>(TargetAvatar);
	if(!TargetController && TargetPawnAvatar)
	{
		TargetController = TargetPawnAvatar->GetController();
	}
}

UMAttributeSet::UMAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.f);
	InitMana(50.f);
	InitMaxMana(100.f);
}

void UMAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UMAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UMAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}

	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
	}
	
}

void UMAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FMEffectProperties Properties(Data);
}

void UMAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMAttributeSet, Health, OldHealth);
}

void UMAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMAttributeSet, MaxHealth, OldMaxHealth);
}

void UMAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMAttributeSet, Mana, OldMana);
}

void UMAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMAttributeSet, MaxMana, OldMaxMana);
}
