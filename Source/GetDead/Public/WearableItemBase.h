// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "WearableItemBase.generated.h"

UCLASS()
class GETDEAD_API AWearableItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWearableItemBase();
	UPROPERTY(EditAnywhere, Category = "Placing Params")
	FName SocketName;

	UPROPERTY(EditAnywhere, Category = "General")
	FName ItemName;

	UFUNCTION(BlueprintCallable)
	void AttachToPerson();
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
