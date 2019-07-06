// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/Classes/GameFramework/Actor.h"
#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaTiame)
{
	Super::Tick(DeltaTiame);
	
	if (HasAuthority()) 
	{
		FVector Location = GetActorLocation();
		Location += FVector(5 * DeltaTiame, 0, 0);//движение по оси х 5 см в секунду 
		SetActorLocation(Location);
	}
}
