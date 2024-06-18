// 

#include "MUserWidget.h"

#include "Aura/Aura.h"

void UMUserWidget::SetWidgetController(UObject* NewController)
{
	RETURN_IF_TRUE(WidgetController == NewController);

	WidgetController = NewController;
	BPI_OnWidgetControllerSet();
}
