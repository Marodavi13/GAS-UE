// 

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "MPlayerState.generated.h"

class UMAttributeSet;
class UMAbilitySystemComponent;
/**
 * 
 */
UCLASS(Abstract)
class AURA_API AMPlayerState: public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	
	AMPlayerState();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UMAttributeSet* GetAttributeSet() const;
	
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	TObjectPtr<UMAbilitySystemComponent> AbilitySystemComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	TObjectPtr<UMAttributeSet> AttributeSet = nullptr;
};
