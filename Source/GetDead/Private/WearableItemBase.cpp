// Fill out your copyright notice in the Description page of Project Settings.


#include "WearableItemBase.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AWearableItemBase::AWearableItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mest"));
	Mesh->SetupAttachment(RootComponent);

		

}

void AWearableItemBase::AttachToPerson()
{
}

// Called when the game starts or when spawned
void AWearableItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWearableItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

