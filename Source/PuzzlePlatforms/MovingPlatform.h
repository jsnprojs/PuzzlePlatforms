// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	AMovingPlatform();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	
	FVector StartLocation;
	FVector EndLocation;
	float StartToEndLocation;

	UPROPERTY(EditAnywhere)
	FVector PlatformVelocity{10, 0, 0};

	UPROPERTY(EditAnywhere)
	float MoveDistance = 5.f;
};
