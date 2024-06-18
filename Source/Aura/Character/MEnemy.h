// 

#pragma once

#include "CoreMinimal.h"
#include "MCharacterBase.h"
#include "MEnemy.generated.h"

class UMHighlightComponent;

UCLASS(Abstract)
class AURA_API AMEnemy: public AMCharacterBase
{
	GENERATED_BODY()

public:
	
	AMEnemy();

	
protected:

	UPROPERTY(VisibleAnywhere, Category ="Component")
	TObjectPtr<UMHighlightComponent> HighlightComponent = nullptr;

	virtual void BeginPlay() override;
};
