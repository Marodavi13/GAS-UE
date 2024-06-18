// 

#include "MPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Aura/Aura.h"

AMPlayerController::AMPlayerController()
{
	bReplicates = true;
}

void AMPlayerController::TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	Super::TickActor(DeltaTime, TickType, ThisTickFunction);

	CurrentHoveredActor = CurrentClickablePrimitive.IsValid() ? CurrentClickablePrimitive->GetOwner() : nullptr;
}

void AMPlayerController::BeginPlay()
{
	Super::BeginPlay();
	InitPlayerInput();
}

void AMPlayerController::InitPlayerInput()
{
	RETURN_IF_NOT_VALID_ENSURE(PlayerContext);

	// set the player context
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	RETURN_IF_NOT_VALID_ENSURE(Subsystem);
	Subsystem->AddMappingContext(PlayerContext, 0);

	// Show mouse
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	// set input mode
	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetHideCursorDuringCapture(false);
}

void AMPlayerController::Move(const FInputActionValue& InputActionValue)
{
	APawn* ControlledPawn = GetPawn();
	RETURN_IF_NOT_VALID(ControlledPawn);
	
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>()	;
	const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);

	const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	ControlledPawn->AddMovementInput(Forward, InputAxisVector.Y);
	ControlledPawn->AddMovementInput(Right  , InputAxisVector.X);
}

void AMPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent);
	RETURN_IF_NOT_VALID_ENSURE(EnhancedInput);
	
	EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMPlayerController::Move);
}
