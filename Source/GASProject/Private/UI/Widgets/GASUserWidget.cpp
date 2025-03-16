// Copyright Daniel Alvarado


#include "UI/Widgets/GASUserWidget.h"

void UGASUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
