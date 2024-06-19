// 

#include "MUserWidget.h"

#include "Aura/Aura.h"
#include "Blueprint/WidgetTree.h"

void UMUserWidget::SetWidgetController(UObject* NewController, bool bIncludeChildren /*= false*/)
{
	RETURN_IF_TRUE(WidgetController == NewController);

	WidgetController = NewController;
	BPI_OnWidgetControllerSet();

	RETURN_IF_FALSE(bIncludeChildren);
	
	TArray<UWidget*> ChildWidgets;
	WidgetTree->GetAllWidgets(ChildWidgets);
	for(auto ChildWidget: ChildWidgets)
	{
		UMUserWidget* Widget = Cast<UMUserWidget>(ChildWidget);
		if (!Widget)
		{
			continue;
		}

		if (!Widget->bAutoSetParentController)
		{
			continue;
		}

		// don't set the controller to the children as main parent is already doing it
		Widget->SetWidgetController(WidgetController);
	}
}
