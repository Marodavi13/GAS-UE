

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MCharacterBase.generated.h"

UCLASS(Abstract)
class AURA_API AMCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AMCharacterBase();

protected:

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
