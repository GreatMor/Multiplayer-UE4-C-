// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/Classes/GameFramework/Actor.h"
#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

void AMovingPlatform::Tick(float DeltaTiame)
{
	Super::Tick(DeltaTiame);
	
	if (HasAuthority()) //Returns whether this actor has network authority 
	{
		FVector Location = GetActorLocation();
		FVector GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);//The transform that transforms from actor space to world space.
		FVector Direction = (GlobalTargetLocation - Location).GetSafeNormal();
		Location += speed * DeltaTiame* Direction;//движение по оси х 5 см в секунду 
		SetActorLocation(Location);
	}
}
