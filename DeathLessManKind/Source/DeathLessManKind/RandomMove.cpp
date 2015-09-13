// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathLessManKind.h"
#include "RandomMove.h"


// Sets default values for this component's properties
URandomMove::URandomMove()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	MinAngleDirection = -60.0f;
	MaxAngleDirection = 60.0f;
	MinTimeBeforeNextRand = 2.0f;
	MaxTimeBeforeNextRand = 10.0f;
	MoveSpeed = 10.0f;

	// ...
}


// Called when the game starts
void URandomMove::BeginPlay()
{
	Super::BeginPlay();
	_dir = this->GetOwner()->GetActorForwardVector();
	RandomizeDirection();

	// ...
	
}


// Called every frame
void URandomMove::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	this->GetOwner()->SetActorLocation(this->GetOwner()->GetActorLocation() + _dir * MoveSpeed * DeltaTime);
	_timeLastRand += DeltaTime;
	if (_timeLastRand >= _timeNextRand)
	{
		RandomizeDirection();
	}

	// ...
}

void	URandomMove::RandomizeDirection()
{
	FQuat quat = this->GetOwner()->GetActorQuat();
	FQuat rot(this->GetOwner()->GetActorUpVector(), FMath::RandRange(MinAngleDirection, MaxAngleDirection));

	quat = quat + rot;
	_dir = quat.RotateVector(FVector::ForwardVector);
	//_dir = rot.RotateVector(this->GetActorForwardVector());
	_timeLastRand = 0.0f;
	_timeNextRand = FMath::RandRange(MinTimeBeforeNextRand, MaxTimeBeforeNextRand);
}

