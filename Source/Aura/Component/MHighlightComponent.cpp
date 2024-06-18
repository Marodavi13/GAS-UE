// 

#include "MHighlightComponent.h"

#include "Aura/Aura.h"
#include "Aura/Utils/MDebugUtils.h"

UMHighlightComponent::UMHighlightComponent()
{
	//	PrimaryComponentTick.bCanEverTick = true;
}

void UMHighlightComponent::EnsureHighlightCollision()
{
	TArray<UPrimitiveComponent*> OutComponents;
	GetOwner()->GetComponents(UPrimitiveComponent::StaticClass(), OutComponents, false);

	bool bIsCollisionSetUp = false;
	for(UPrimitiveComponent* Component : OutComponents)
	{
		if (Component->GetCollisionEnabled() == ECollisionEnabled::NoCollision)
		{
			continue;
		}
		
		if (Component->GetCollisionResponseToChannel(ECC_Visibility) == ECR_Ignore)
		{
			continue;
		}
		
		bIsCollisionSetUp = true;
		break;
	}

	UE_CLOG(!bIsCollisionSetUp, LogHighlight, Warning,
	        TEXT("Actor %s can't be highlighted due collision setup"), *GetNameSafe(GetOwner()));
}

void UMHighlightComponent::BeginPlay()
{
	Super::BeginPlay();

	RETURN_IF_NOT_VALID_ENSURE(GetOwner());

	GetOwner()->OnBeginCursorOver.AddUniqueDynamic(this, &UMHighlightComponent::Highlight);
	GetOwner()->OnEndCursorOver.AddUniqueDynamic(this, &UMHighlightComponent::UnHighlight);

	EnsureHighlightCollision();
}

void UMHighlightComponent::Highlight(AActor* TouchedActor)
{
	GetOwner()->GetComponents(UMeshComponent::StaticClass(), HighlightedMeshes, false);

	for (auto Mesh : HighlightedMeshes)
	{
		Mesh->SetRenderCustomDepth(true);
		Mesh->SetCustomDepthStencilValue(DepthStencilValue);
	}

}

void UMHighlightComponent::UnHighlight(AActor* TouchedActor)
{
	for (auto Mesh : HighlightedMeshes)
	{
		Mesh->SetRenderCustomDepth(false);
	}
}
