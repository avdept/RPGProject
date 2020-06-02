// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayableCharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APlayableCharacterBase::APlayableCharacterBase()
{
 	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true; 
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; 
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); 
	FollowCamera->bUsePawnControlRotation = true;

	FollowCamera->PostProcessSettings.bOverride_AutoExposureMethod = true;
	FollowCamera->PostProcessSettings.AutoExposureMethod = AEM_Manual;
}

UAnimMontage* APlayableCharacterBase::GetNextAttackMontage()
{
	if (AnimationList.Num() > 0)
	{
		TArray<UAnimMontage*> AvailableMontages = AnimationList.FilterByPredicate([this](const UAnimMontage* montage)
		{
			return montage != this->LastPlayerAttackAnimation;
		});

		const int NextAnimIndex = FMath::RandRange(0, AvailableMontages.Num() - 1);
		UE_LOG(LogTemp, Log, TEXT("NextAnimIndex %d"), NextAnimIndex);
		UAnimMontage* NextMontage = AvailableMontages[NextAnimIndex];
		LastPlayerAttackAnimation = NextMontage;
		return NextMontage;	
	}
	return nullptr;
}

void APlayableCharacterBase::OnAttackFinished()
{
	if (bAttackInProgress)
	{
		bAttackInProgress = false;
	}
}

// Called when the game starts or when spawned
void APlayableCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayableCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ChangeSprintSpeed(DeltaTime);

}

void APlayableCharacterBase::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void APlayableCharacterBase::ChangeSprintSpeed(float DeltaTime)
{
	if (!bIsCurrentlySprinting) {
		CurrentMaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
		GetCharacterMovement()->MaxWalkSpeed = FMath::Lerp(CurrentMaxWalkSpeed, OriginalWalkMaxSpeed, FMath::Clamp(DeltaTime * 2.f, 0.f, 1.f));
		return;
	}

	if (LimitMaxWalkSpeed - CurrentMaxWalkSpeed <= 0.001) {
		CurrentMaxWalkSpeed = LimitMaxWalkSpeed;
	}

	CurrentMaxWalkSpeed = FMath::Lerp(CurrentMaxWalkSpeed, LimitMaxWalkSpeed, FMath::Clamp(DeltaTime, 0.f, 1.f));

	GetCharacterMovement()->MaxWalkSpeed = CurrentMaxWalkSpeed;
}

void APlayableCharacterBase::onWeaponHide()
{
	if (bWeaponDrawn && !bWeaponDrawing) {
		UE_LOG(LogTemp, All, TEXT("Hiding started"));
		bWeaponDrawing = true;
		onWeaponHideEvent();
	}
}

void APlayableCharacterBase::onWeaponHideFinished() {
	bWeaponDrawing = false;
	bWeaponDrawn = false;
}

void APlayableCharacterBase::Attack()
{
	// Here we want to do any preparations before we run attack
	if (!bWeaponDrawn && !bWeaponDrawing) {
		bWeaponDrawing = true;
		onWeaponDrawing();
		StopSprint();
		return;
	}

	
	if (bWeaponDrawn && !bAttackInProgress) {
		bAttackInProgress = true;
		this->onAttack();
	}
}

void APlayableCharacterBase::StartSprint()
{

	if (bWeaponDrawn) {
		return;
	}
	bIsCurrentlySprinting = true;
}

void APlayableCharacterBase::StopSprint()
{
	bIsCurrentlySprinting = false;
}

void APlayableCharacterBase::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void APlayableCharacterBase::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void APlayableCharacterBase::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

// Called to bind functionality to input
void APlayableCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("HideWeapon", IE_Released, this, &APlayableCharacterBase::onWeaponHide);

	PlayerInputComponent->BindAction("LeftAction", IE_Pressed, this, &APlayableCharacterBase::Attack);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &APlayableCharacterBase::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &APlayableCharacterBase::StopSprint);


	PlayerInputComponent->BindAxis("MoveForward", this, &APlayableCharacterBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayableCharacterBase::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &APlayableCharacterBase::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &APlayableCharacterBase::LookUpAtRate);

}

