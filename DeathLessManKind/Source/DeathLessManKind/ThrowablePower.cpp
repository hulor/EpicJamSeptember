// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathLessManKind.h"
#include "ThrowablePower.h"


void	AThrowablePower::Init(FVector dest, FVector normale)
{
	this->SetActorLocation(this->GetActorLocation() + this->GetActorForwardVector() * Offset.X + this->GetActorRightVector() * Offset.Y +
		this->GetActorUpVector() * Offset.Z);

	_dest = dest;
	_dir = dest - this->GetActorLocation();
	_dir.Normalize();
	this->SetActorRotation(FRotationMatrix::MakeFromZ(-_dir).ToQuat());
}

void	AThrowablePower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (FVector::Dist(_dest, this->GetActorLocation()) < 50.0f)
	{
		this->GetWorld()->SpawnActor<AActor>(this->DieFX, this->GetActorLocation(), FRotationMatrix::MakeFromZ(-_dir).Rotator());
		this->Destroy();
		return;
	}
	this->SetActorLocation(this->GetActorLocation() + _dir * Speed * DeltaSeconds);
}

