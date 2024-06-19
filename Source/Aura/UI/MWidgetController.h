// 

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MWidgetController.generated.h"

class UMAttributeSet;
class UMAbilitySystemComponent;
class AMPlayerController;
class AMPlayerState;

USTRUCT(BlueprintType)
struct FMWidgetControllerData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category ="Widget Controller")
	TObjectPtr<AMPlayerController> PlayerController = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category ="Widget Controller")
	TObjectPtr<AMPlayerState> PlayerState = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category ="Widget Controller")
	TObjectPtr<UMAbilitySystemComponent> AbilitySystem = nullptr;

	UPROPERTY(BlueprintReadOnly, Category ="Widget Controller")
	TObjectPtr<UMAttributeSet> Attributes = nullptr;

	
	FMWidgetControllerData(){}

	FMWidgetControllerData(AMPlayerController* PC, AMPlayerState* PS, UMAbilitySystemComponent* ASC, UMAttributeSet* AS) :
	PlayerController(PC),PlayerState(PS), AbilitySystem(ASC), Attributes(AS) { }
	
};

/**
 * 
 */
UCLASS()
class AURA_API UMWidgetController: public UObject
{
	GENERATED_BODY()

public:

	void SetWidgetControllerData(const FMWidgetControllerData& NewData);

	virtual void BroadcastInitialValues() {}
protected:

	UPROPERTY(BlueprintReadOnly, Category ="Widget Controller")
	TObjectPtr<AMPlayerController> PlayerController = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category ="Widget Controller")
	TObjectPtr<AMPlayerState> PlayerState = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category ="Widget Controller")
	TObjectPtr<UMAbilitySystemComponent> AbilitySystem = nullptr;

	UPROPERTY(BlueprintReadOnly, Category ="Widget Controller")
	TObjectPtr<UMAttributeSet> Attributes = nullptr;
	
};
