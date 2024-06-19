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

	// if true the parent widget 
	UPROPERTY(EditAnywhere, Category = "UI")
	bool bAutoSetParentController = false;

	void SetWidgetController(UObject* NewController, bool bIncludeChildren = false);
	
protected:

	UFUNCTION(BlueprintImplementableEvent, DisplayName="OnWidgetControllerSet")
	void BPI_OnWidgetControllerSet();
};
