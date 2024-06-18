// 

#include "MPlayer.h"

#include "GameFramework/CharacterMovementComponent.h"

AMPlayer::AMPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	UCharacterMovementComponent* Movement = GetCharacterMovement();
	Movement->bOrientRotationToMovement = true;
	Movement->RotationRate = FRotator(0.f, 400.f, 0.f);
	Movement->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}


