// 

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MUtils.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UMUtils: public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	static bool LerpHelper(float DeltaTime, UPARAM(ref)float& CurrentTime, float TargetTime, float& OutAlpha, EAlphaBlendOption BlendOption);

};
