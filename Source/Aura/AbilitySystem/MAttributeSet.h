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

USTRUCT(BlueprintType)
struct FMEffectProperties
{
	GENERATED_BODY()

	FMEffectProperties(){}

	FMEffectProperties(const FGameplayEffectModCallbackData& Data);
	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TObjectPtr<UAbilitySystemComponent> SourceASC = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TObjectPtr<UAbilitySystemComponent> TargetASC = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TObjectPtr<AActor> SourceAvatar = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TObjectPtr<AActor> TargetAvatar = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TObjectPtr<AController> SourceController = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TObjectPtr<AController> TargetController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TObjectPtr<ACharacter> SourceCharacter = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TObjectPtr<ACharacter> TargetCharacter = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	FGameplayEffectContextHandle ContextHandle;

	void SetSourceProperties(UAbilitySystemComponent* AbilitySystem);

	void SetTargetProperties(UAbilitySystemComponent* AbilitySystem);
};
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
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
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
