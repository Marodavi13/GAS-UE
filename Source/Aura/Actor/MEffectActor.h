// 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MEffectActor.generated.h"

class USphereComponent;

UCLASS()
class AURA_API AMEffectActor: public AActor
{
	GENERATED_BODY()

public:
	
	AMEffectActor();

	
	virtual void PostInitializeComponents() override;

protected:

	UPROPERTY(VisibleAnywhere, Category="Effect Actor")
	TObjectPtr<USphereComponent> EffectCollider;

	UPROPERTY(VisibleAnywhere, Category="Effect Actor")
	TObjectPtr<UStaticMeshComponent> Mesh;


	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
						int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
					  int32 OtherBodyIndex);

};
