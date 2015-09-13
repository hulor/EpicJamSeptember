// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathLessManKind.h"
#include "PlanetCitizen.h"


// Sets default values
APlanetCitizen::APlanetCitizen(const class FObjectInitializer& PCIP)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->RootComponent = PCIP.CreateDefaultSubobject<USceneComponent>(this, TEXT("Root"));
	Mesh = PCIP.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("SKMesh"));
	RandMove = PCIP.CreateDefaultSubobject<URandomMove>(this, TEXT("RandomMove"));
	Gravity = PCIP.CreateDefaultSubobject<UGravityComponent>(this, TEXT("Gravity"));
	Projectile = PCIP.CreateDefaultSubobject<UProjectileMovementComponent>(this, TEXT("ProjectileComponent"));

	Mesh->AttachTo(this->RootComponent);
}

// Called when the game starts or when spawned
void	APlanetCitizen::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void	APlanetCitizen::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

