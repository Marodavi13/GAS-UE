// 

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/Actor.h"
#include "MEffectActor.generated.h"

class UGameplayEffect;
class USphereComponent;

UENUM(BlueprintType)
enum class EMEffectPolicy : uint8
{
	None,
	OnBeginOverlap,
	OnEndOverlap,
};


UCLASS()
class AURA_API AMEffectActor: public AActor
{
	GENERATED_BODY()

public:
	
	AMEffectActor();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Effects")
	float ActorLevel = 1.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass = nullptr;

	UPROPERTY(EditAnywhere, Category="Effects")
	EMEffectPolicy InstantEffectApplicationPolicy = EMEffectPolicy::None;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass = nullptr;

	UPROPERTY(EditAnywhere, Category="Effects")
	EMEffectPolicy DurationEffectApplicationPolicy = EMEffectPolicy::None;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Effects")
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass = nullptr;

	UPROPERTY(EditAnywhere, Category="Effects")
	EMEffectPolicy InfiniteEffectApplicationPolicy = EMEffectPolicy::None;

	UPROPERTY(EditAnywhere, Category="Effects")
	EMEffectPolicy InfiniteEffectRemovalPolicy = EMEffectPolicy::OnEndOverlap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Effects")
	bool bDestroyActorOnEffectRemoval = false;

	UPROPERTY(Transient)
	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveGameplayEffectHandles;
	
	UFUNCTION(BlueprintCallable, Category="Effects")
	void ApplyEffectToTarget(AActor* TargetActor,
	                         TSubclassOf<UGameplayEffect> GameplayEffectClass);
	
	UFUNCTION(BlueprintCallable, Category="Effects")
	void OnBeginOverlap(AActor* TargetActor);

	UFUNCTION(BlueprintCallable, Category="Effects")
	void OnEndOverlap(AActor* TargetActor);
};
