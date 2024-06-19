// 

#include "MPlayer.h"

#include "Aura/Aura.h"
#include "Aura/AbilitySystem/MAbilitySystemComponent.h"
#include "Aura/Player/MPlayerController.h"
#include "Aura/Player/MPlayerState.h"
#include "Aura/UI/MHUD.h"
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
	
	AbilitySystemComponent = Cast<UMAbilitySystemComponent>(MPlayerState->GetAbilitySystemComponent());
	AttributeSet = MPlayerState->GetAttributeSet();
	
	AbilitySystemComponent->InitAbilityActorInfo(MPlayerState, this);

	AMPlayerController* PlayerController = GetController<AMPlayerController>();
	RETURN_IF_NOT_VALID(PlayerController);

	AMHUD* HUD = PlayerController->GetHUD<AMHUD>();

	HUD->InitHUD(PlayerController, MPlayerState, AbilitySystemComponent, AttributeSet);
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


