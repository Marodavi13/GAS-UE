// 

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MDebugUtils.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UMDebugUtils: public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static void DrawBox		   (const UWorld* World, const FVector& Center, const FVector& Extent = FVector(32.f),
								const float Duration = 5.f,	const FColor& Color = FColor::Blue, const float Thickness = 1.f);
	
	static void DrawBoxPriority(const UWorld* World, const FVector& Center, const FVector& Extent = FVector(32.f),
								const float Duration = 5.f,	const FColor& Color = FColor::Blue, const float Thickness = 1.f);

	static void DrawSphere		  (const UWorld* World, const FVector& Center, const float& Radius = 16.f, const float Duration = 5.f, 
								   const FColor& Color = FColor::Blue, const float Thickness = 1.f);
	
	static void DrawSpherePriority(const UWorld* World, const FVector& Center, const float& Radius = 16.f, const float Duration = 5.f, 
								   const FColor& Color = FColor::Blue, const float Thickness = 1.f);
	
	static void DrawCircle		  (const UWorld* World, const FVector& Center, const float& Radius = 16.f, const float Duration = 5.f, 
								   const FColor& Color = FColor::Blue, const FVector& YAxis = FVector::RightVector,
								   const FVector& ZAxis = FVector::ForwardVector, const float Thickness = 1.f);
	
	static void DrawCirclePriority(const UWorld* World, const FVector& Center, const float& Radius = 16.f, const float Duration = 5.f, 
								   const FColor& Color = FColor::Blue, const FVector& YAxis = FVector::RightVector,
								   const FVector& ZAxis = FVector::ForwardVector, const float Thickness = 1.f);
	
	static void DrawArrow		 (const UWorld* World, const FVector& Start, const FVector& End, float Duration = 5.f,
								   const FColor& Color = FColor::Blue, const float Thickness = 1.f);
	
	static void DrawArrowPriority(const UWorld* World, const FVector& Start, const FVector& End, float Duration = 5.f,
								  const FColor& Color = FColor::Blue, const float Thickness = 1.f);
	
	static void DrawCapsule	     (const UWorld* World, const FVector& Center, const FQuat& Rotation, float HalfHeight,
								  float Radius = 16.f, float Duration = 5.f, const FColor& Color = FColor::Blue, float Thickness = 1.f);
	
	static void DrawText   (const UWorld* World, const FString& Text, const FVector& Offset, AActor* BaseActor,
						    const float Duration = 5.f, const FColor& Color = FColor::Yellow);
	
	static void LogOnScreen(const UObject* WorldContext, const FString& Msg, const FColor& Color = FColor::Green,
						    const float Duration = 5.f, const int32 Key = INDEX_NONE);
};
