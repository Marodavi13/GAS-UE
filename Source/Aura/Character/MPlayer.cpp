// 

#include "MPlayer.h"

#include "Aura/Aura.h"
#include "Aura/AbilitySystem/MAbilitySystemComponent.h"
#include "Aura/Player/MPlayerState.h"
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

void AMPlayer::InitAbilitySystem()
{
	AMPlayerState* MPlayerState = GetPlayerState<AMPlayerState>();
	RETURN_IF_NOT_VALID_ENSURE(MPlayerState);
	
	AbilitySystemComponent = MPlayerState->GetAbilitySystemComponent();
	AttributeSet = MPlayerState->GetAttributeSet();
	
	AbilitySystemComponent->InitAbilityActorInfo(MPlayerState, this);
}

void AMPlayer::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilitySystem();
}

void AMPlayer::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilitySystem();
}


