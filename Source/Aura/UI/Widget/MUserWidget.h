// 

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UMUserWidget: public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(Transient, BlueprintReadOnly, Category = "UI")
	TObjectPtr<UObject> WidgetController;

	void SetWidgetController(UObject* NewController);
	
protected:

	UFUNCTION(BlueprintImplementableEvent, DisplayName="OnWidgetControllerSet")
	void BPI_OnWidgetControllerSet();
};
