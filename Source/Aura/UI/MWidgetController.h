// 

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MWidgetController.generated.h"

class UMAttributeSet;
class UMAbilitySystemComponent;
class AMPlayerController;
class AMPlayerState;
/**
 * 
 */
UCLASS()
class AURA_API UMWidgetController: public UObject
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly, Category ="Widget Controller")
	TObjectPtr<AMPlayerState> PlayerState = nullptr;

	UPROPERTY(BlueprintReadOnly, Category ="Widget Controller")
	TObjectPtr<AMPlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category ="Widget Controller")
	TObjectPtr<UMAbilitySystemComponent> AbilitySystem = nullptr;

	UPROPERTY(BlueprintReadOnly, Category ="Widget Controller")
	TObjectPtr<UMAttributeSet> Attributes = nullptr;
	
};
