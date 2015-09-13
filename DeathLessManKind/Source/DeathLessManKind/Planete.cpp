// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathLessManKind.h"
#include "Planete.h"


// Sets default values
APlanete::APlanete(const class FObjectInitializer& PCIP)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	this->RootComponent = PCIP.CreateDefaultSubobject<USceneComponent>(this, TEXT("Root"));
	Mesh = PCIP.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("SKMesh"));
	Mesh->AttachTo(this->RootComponent);
}

// Called when the game starts or when spawned
void APlanete::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlanete::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

