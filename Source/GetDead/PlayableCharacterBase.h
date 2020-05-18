// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayableCharacterBase.generated.h"

UCLASS()
class GETDEAD_API APlayableCharacterBase : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	// Sets default values for this character's properties
	APlayableCharacterBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	float LimitMaxWalkSpeed = 900.f;

	UPROPERTY(BlueprintReadWrite, Category = Weapons)
	bool bWeaponDrawn;

	UPROPERTY(BlueprintReadWrite, Category = Weapons)
	bool bWeaponDrawing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character | Animation")
	TArray<UAnimMontage *> AnimationList; 

	UAnimMontage* LastPlayerAttackAnimation;

	bool bAttackInProgress;

	UFUNCTION(BlueprintCallable, BlueprintPure) UAnimMontage* GetNextAttackMontage();
	UFUNCTION(BlueprintCallable)
	void OnAttackFinished();
	
	bool bIsCurrentlySprinting;
	float OriginalWalkMaxSpeed = 600.f;
	float CurrentMaxWalkSpeed;
	
	float TransitionSpeed;

protected:
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	UFUNCTION(BlueprintImplementableEvent, Category="Attack")
	void onAttack();

	UFUNCTION(BlueprintImplementableEvent, Category = "Attack")
	void onWeaponDrawing();

	UFUNCTION(BlueprintImplementableEvent, Category = "Attack")
	void onWeaponHideEvent();
	UFUNCTION(BlueprintCallable, Category = "Attack")
	void onWeaponHideFinished();

	void onWeaponHide();


	UFUNCTION(BlueprintCallable, Category = "Attack")
	void Attack();
	void StartSprint();

	void StopSprint();
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void ChangeSprintSpeed(float DeltaTime);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
