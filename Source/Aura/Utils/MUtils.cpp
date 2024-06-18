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