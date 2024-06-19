// 

#include "MWidgetController.h"

void UMWidgetController::SetWidgetControllerData(const FMWidgetControllerData& NewData)
{
	PlayerController = NewData.PlayerController;
	PlayerState = NewData.PlayerState;
	AbilitySystem = NewData.AbilitySystem;
	Attributes = NewData.Attributes;
}
