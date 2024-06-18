// 

#pragma once

#include "CoreMinimal.h"
#include "MCharacterBase.h"
#include "MPlayer.generated.h"

UCLASS(Abstract)
class AURA_API AMPlayer: public AMCharacterBase
{
	GENERATED_BODY()

public:
	
	AMPlayer();
	
	virtual void PossessedBy(AController* NewController) override;

protected:

	virtual void OnRep_PlayerState() override;

private:

	void InitAbilitySystem();

};
