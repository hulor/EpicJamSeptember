// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathLessManKind.h"
#include "OrbitalCharacter.h"


// Sets default values
AOrbitalCharacter::AOrbitalCharacter(const class FObjectInitializer& PCIP)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_arm = PCIP.CreateDefaultSubobject<USpringArmComponent>(this, TEXT("SpringArm"));
}

// Called when the game starts or when spawned
void AOrbitalCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOrbitalCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AOrbitalCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("ZRotation", this, &AOrbitalCharacter::RotateAroundZ);
	InputComponent->BindAxis("XRotation", this, &AOrbitalCharacter::RotateAroundX);
}

void AOrbitalCharacter::RotateAroundZ(float axis)
{
	this->AddControllerYawInput(axis);
}

void AOrbitalCharacter::RotateAroundX(float axis)
{
	this->AddControllerPitchInput(axis);
}

