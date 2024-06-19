// 

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/HUD.h"
#include "MHUD.generated.h"

class UMAttributeSet;
class UMAbilitySystemComponent;
class AMPlayerState;
class AMPlayerController;
struct FMWidgetControllerData;
class UMHUDController;
class UMUserWidget;
/**
 * 
 */
UCLASS()
class AURA_API AMHUD: public AHUD
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadOnly, Transient, Category = "UI")
	TObjectPtr<UMUserWidget> HUDWidget = nullptr;

	UMHUDController* GetHUDController(const FMWidgetControllerData& Params);

	void InitHUD(AMPlayerController* PC, AMPlayerState* PS, UMAbilitySystemComponent* ASC, UMAttributeSet* AS);
	
protected:
	
	UPROPERTY(EditAnywhere, Category="UI")
	TSubclassOf<UMUserWidget> HUDWidgetClass = nullptr;
	
	UPROPERTY(EditAnywhere, Category="UI")
	TSubclassOf<UMHUDController> HUDControllerClass = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Transient, Category = "UI")
	TObjectPtr<UMHUDController> HUDController = nullptr;
};
