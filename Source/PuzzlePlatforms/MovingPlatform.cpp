// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
	EndLocation = StartLocation + PlatformVelocity;
	StartToEndLocation = FVector::Distance(StartLocation, EndLocation);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (HasAuthority()) {
		FVector LastLocation = GetActorLocation();
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		FVector NextLocation = LastLocation + MoveDirection * MoveDistance;
		float TraveledDistance = FVector::Distance(StartLocation, NextLocation);

		if (TraveledDistance > StartToEndLocation) {
			PlatformVelocity = -PlatformVelocity;
		}
		SetActorLocation(NextLocation);
	}

}

