// 

#include "MDebugUtils.h"

#include "Aura/Aura.h"

namespace
{
	constexpr float DurationScale = 1.1f;
	constexpr float ArrowScale = 0.2f;
	constexpr int32 SphereSegments = 12;
}

void UMDebugUtils::DrawBox(const UWorld* World, const FVector& Center, const FVector& Extent, const float Duration, const FColor& Color, const float Thickness)
{
	RETURN_IF_NULL(World);
	DrawDebugBox(World, Center, Extent, Color, false, Duration * DurationScale, 0, Thickness);
}

void UMDebugUtils::DrawBoxPriority(const UWorld* World, const FVector& Center, const FVector& Extent, const float Duration, const FColor& Color, const float Thickness)
{
	RETURN_IF_NULL(World);
	DrawDebugBox(World, Center, Extent, Color, false, Duration * DurationScale, 1, Thickness);
}

void UMDebugUtils::DrawSphere(const UWorld* World, const FVector& Center, const float& Radius, const float Duration,
	const FColor& Color, float Thickness)
{
	RETURN_IF_NULL(World);
	DrawDebugSphere(World, Center, Radius, SphereSegments, Color, false, Duration * DurationScale, 0, Thickness);
}

void UMDebugUtils::DrawSpherePriority(const UWorld* World, const FVector& Center, const float& Radius, const float Duration,
	const FColor& Color, const float Thickness)
{
	RETURN_IF_NULL(World);
	DrawDebugSphere(World, Center, Radius, SphereSegments, Color, false, Duration * DurationScale, 1, Thickness);
}

void UMDebugUtils::DrawCircle(const UWorld* World, const FVector& Center, const float& Radius, const float Duration,
                         const FColor& Color, const FVector& YAxis, const FVector& ZAxis, const float Thickness)
{
	RETURN_IF_NULL(World);
	DrawDebugCircle(World, Center, Radius, 24, Color, false, Duration * DurationScale, 0, Thickness, YAxis, ZAxis);
}

void UMDebugUtils::DrawCirclePriority(const UWorld* World, const FVector& Center, const float& Radius, 
                                 const float Duration,const FColor& Color, const FVector& YAxis, const FVector& ZAxis, const float Thickness)
{
	RETURN_IF_NULL(World);
	DrawDebugCircle(World, Center, Radius, 24, Color, false, Duration * DurationScale, 1, Thickness, YAxis, ZAxis);
}

void UMDebugUtils::DrawArrow(const UWorld* World, const FVector& Start, const FVector& End, const float Duration, const FColor& Color, const float Thickness)
{
	RETURN_IF_NULL(World);
	const float ArrowSize = (Start - End).Length() * ArrowScale;
	DrawDebugDirectionalArrow(World, Start, End, ArrowSize, Color, false, Duration * DurationScale, 0, Thickness);
}

void UMDebugUtils::DrawArrowPriority(const UWorld* World, const FVector& Start, const FVector& End, const float Duration, const FColor& Color, const float Thickness)
{
	RETURN_IF_NULL(World);
	const float ArrowSize = (Start - End).Length() * ArrowScale;
	DrawDebugDirectionalArrow(World, Start, End, ArrowSize, Color, false, Duration * DurationScale, 1, Thickness);
}

void UMDebugUtils::DrawCapsule(const UWorld* World, const FVector& Center, const FQuat& Rotation, float HalfHeight, float Radius, float Duration,
	const FColor& Color, float Thickness)
{
	DrawDebugCapsule(World, Center, HalfHeight, Radius, Rotation, Color, false, Duration * DurationScale, 0, Thickness);
}

void UMDebugUtils::DrawText(const UWorld* World, const FString& Text, const FVector& Offset, AActor* BaseActor, const float Duration, const FColor& Color)
{
	RETURN_IF_NULL(World);
	DrawDebugString(World, Offset, Text, BaseActor, Color, Duration * DurationScale, false, 1.f);
}

void UMDebugUtils::LogOnScreen(const UObject* WorldContext, const FString& Msg, const FColor& Color, const float Duration, const int32 Key)
{
	RETURN_IF_NULL_ENSURE(WorldContext);
	RETURN_IF_NULL(GEngine);
	const UWorld* World = WorldContext->GetWorld();
	RETURN_IF_NULL_ENSURE(World);
	const bool bIsStandalone = World->IsNetMode(NM_Standalone);
	const bool bIsClient = World->IsNetMode(NM_Client);
	FString NetPrefix;
	if(!bIsStandalone)
	{
		NetPrefix = TEXT("[SERVER]: ");
	
		if (bIsClient)
		{
			NetPrefix = FString::Printf(TEXT("[CLIENT %d]: "), World->GetGameInstance()->GetWorldContext()->PIEInstance);
		}
	}
	const FColor DebugColor = bIsStandalone ? Color : bIsClient ? FColor::Green : FColor::Blue;
	GEngine->AddOnScreenDebugMessage(-1, Duration, DebugColor , NetPrefix + Msg);
}
