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

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	static bool FLerpDecay(UPARAM(ref)float& From, const float To, const float Decay, const float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	static bool VLerpDecay(UPARAM(ref)FVector& From, const FVector To, const float Decay, const float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	static bool RLerpDecay(UPARAM(ref)FRotator& From, FRotator To, const float Decay, const float DeltaTime);
	
	template<class T>
	static T LerpDecay(T From, T To, float Decay, float DeltaTime)
	{
		return To + (From-To)*FMath::Exp(-Decay * DeltaTime);
	}

protected:

	static void SanitizeFromToRotators(FRotator& From, FRotator& To);
	
};
