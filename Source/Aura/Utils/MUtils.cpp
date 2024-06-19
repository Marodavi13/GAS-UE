// 

#include "MUtils.h"


bool UMUtils::LerpHelper(float DeltaTime, float& CurrentTime, float TargetTime, float& OutAlpha, EAlphaBlendOption BlendOption)
{
	CurrentTime += DeltaTime;
	
	if (CurrentTime >= TargetTime)
	{
		OutAlpha = 1.f;
		return true;
	}

	OutAlpha =  FAlphaBlend::AlphaToBlendOption(CurrentTime/TargetTime, BlendOption);
	return false;
}

bool UMUtils::FLerpDecay(float& From, const float To, const float Decay, const float DeltaTime)
{
	From = LerpDecay<float>(From, To, Decay, DeltaTime);;
	return FMath::IsNearlyEqual(From, To);
}

bool UMUtils::VLerpDecay(FVector& From, const FVector To, const float Decay, const float DeltaTime)
{
	From = LerpDecay<FVector>(From, To, Decay, DeltaTime);
	return From.Equals(To);
}

bool UMUtils::RLerpDecay(FRotator& From, FRotator To, const float Decay, const float DeltaTime)
{
	SanitizeFromToRotators(From, To);
	From = LerpDecay<FRotator>(To, From, Decay, DeltaTime);
	return From.Equals(To);
}

void UMUtils::SanitizeFromToRotators(FRotator& From, FRotator& To)
{
	From.Pitch = FMath::Fmod(From.Pitch + 360.f, 360.f);
	From.Yaw = FMath::Fmod(From.Yaw + 360.f, 360.f);
	From.Roll = FMath::Fmod(From.Roll + 360.f, 360.f);

	
	To.Pitch = FMath::Fmod(To.Pitch + 360.f, 360.f);
	To.Yaw = FMath::Fmod(To.Yaw + 360.f, 360.f);
	To.Roll = FMath::Fmod(To.Roll + 360.f, 360.f);

	// Yaw
	if (To.Yaw - From.Yaw > 180.f)
	{
		From.Yaw += 360.f;
	}
	else if (From.Yaw - To.Yaw > 180.f)
	{
		To.Yaw += 360.f;
	}

	// Pitch
	if (To.Pitch - From.Pitch > 180.f)
	{
		From.Pitch += 360.f;
	}
	else if (From.Pitch - To.Pitch > 180.f)
	{
		To.Pitch += 360.f;
	}

	// Roll
	if (To.Roll - From.Roll > 180.f)
	{
		From.Roll += 360.f;
	}
	else if (From.Roll - To.Roll > 180.f)
	{
		To.Roll += 360.f;
	}
}