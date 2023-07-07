// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"
#include "Algo/Reverse.h"
AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);

	StartToEndDistance = FVector::Distance(StartLocation, GlobalTargetLocation);
	Direction = (GlobalTargetLocation - StartLocation).GetSafeNormal();

	if (HasAuthority()) {
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

		if (ActiveTriggers > 0 && HasAuthority()) {

			FVector Location = GetActorLocation();
			float CurrentDistance = FVector::Distance(Location, StartLocation);

			if (CurrentDistance > StartToEndDistance) {
				Swap(GlobalTargetLocation, StartLocation);
				Direction = -Direction;
			}

			Location += Speed * DeltaTime * Direction;
			SetActorLocation(Location);

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



