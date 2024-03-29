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

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation); //The transform that transforms from actor space to world space.

}

void AMovingPlatform::Tick(float DeltaTiame)
{
	Super::Tick(DeltaTiame);
	if (ActiveTriggers > 0)
	{
		if (HasAuthority()) //Returns whether this actor has network authority 
		{
			FVector Location = GetActorLocation();

			float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();//����� �� A �� B
			float JourneyTravelled = (Location - GlobalStartLocation).Size();

			if (JourneyTravelled >= JourneyLength)
			{
				FVector Swap = GlobalStartLocation;
				GlobalStartLocation = GlobalTargetLocation;
				GlobalTargetLocation = Swap;
			}

			FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
			Location += speed * DeltaTiame* Direction;//�������� �� ��� � 5 �� � ������� 
			SetActorLocation(Location);
		}
	}
}

void AMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers++;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if (ActiveTriggers > 0)
	{
		ActiveTriggers--;
	}
}

