// 

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "MAttributeSet.generated.h"
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
/**
 * 
 */
UCLASS()
class AURA_API UMAttributeSet: public UAttributeSet
{
	GENERATED_BODY()

public:
	
	UMAttributeSet();

	/* Attributes */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing="OnRep_Health", Category="Attribute|Health")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UMAttributeSet, Health);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing="OnRep_MaxHealth", Category="Attribute|Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UMAttributeSet, MaxHealth);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing="OnRep_Mana", Category="Attribute|Mana")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UMAttributeSet, Mana);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing="OnRep_MaxMana", Category="Attribute|Mana")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UMAttributeSet, MaxMana);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
	
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana);

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana);
	
};
