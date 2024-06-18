#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "GameFramework/PlayerController.h"
#include "MPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AMPlayerController: public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
	void InitPlayerInput();
	void Move(const FInputActionValue& InputActionValue);


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mapping")
	TObjectPtr<UInputMappingContext> PlayerContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mapping")	
	TObjectPtr<UInputAction> MoveAction;
};
