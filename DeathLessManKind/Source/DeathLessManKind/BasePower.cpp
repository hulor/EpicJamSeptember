// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathLessManKind.h"
#include "BasePower.h"


// Sets default values
ABasePower::ABasePower(const class FObjectInitializer& PCIP)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->RootComponent = PCIP.CreateDefaultSubobject<USceneComponent>(this, TEXT("Root"));
	Collider = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("Collider"));
	Collider->AttachTo(this->RootComponent);
}

// Called when the game starts or when spawned
void	ABasePower::BeginPlay()
{
	Super::BeginPlay();
	_time = 0.0f;
	Collider->SetRelativeScale3D(StartColliderSize);
}

// Called every frame
void	ABasePower::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	_time += DeltaTime;
	if (_time > GrownDuration)
		return ;
	Collider->SetRelativeScale3D(FMath::Lerp(StartColliderSize, EndColliderSize, (_time / GrownDuration)));
}

