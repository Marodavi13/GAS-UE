// 

#include "MHUD.h"

#include "AttributeSet.h"
#include "Aura/Aura.h"
#include "Widget/MHUDController.h"
#include "Widget/MUserWidget.h"

UMHUDController* AMHUD::GetHUDController(const FMWidgetControllerData& Params)
{
	if (HUDController == nullptr)
	{
		HUDController = NewObject<UMHUDController>(this, HUDControllerClass);
		HUDController->SetWidgetControllerData(Params);
		HUDController->BindAttributesCallbacks();
	}

	return HUDController;
}

void AMHUD::InitHUD(AMPlayerController* PC, AMPlayerState* PS, UMAbilitySystemComponent* ASC, UMAttributeSet* AS)
{
	RETURN_IF_NOT_VALID_ENSURE(HUDWidgetClass);
	RETURN_IF_NOT_VALID_ENSURE(HUDControllerClass);
	
	HUDWidget = CreateWidget<UMUserWidget>(GetWorld(), HUDWidgetClass);

	const FMWidgetControllerData Params (PC, PS, ASC, AS);
	UMHUDController* NewController = GetHUDController(Params);
	
	HUDWidget->SetWidgetController(NewController, true);
	NewController->BroadcastInitialValues();
	
	HUDWidget->AddToViewport();

	
}
