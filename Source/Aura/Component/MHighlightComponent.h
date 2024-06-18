// 

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MHighlightComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AURA_API UMHighlightComponent: public UActorComponent
{
	GENERATED_BODY()

public:
	UMHighlightComponent();

	void EnsureHighlightCollision();

protected:
	
	virtual void BeginPlay() override;

	UFUNCTION()
	void Highlight(AActor* TouchedActor);

	UFUNCTION()
	void UnHighlight(AActor* TouchedActor);

	UPROPERTY(Transient)
	TArray<UMeshComponent*> HighlightedMeshes;

	// 250 - red || 251 - blue || 252 - yellow 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Highlight")
	int32 DepthStencilValue = 250;
};
