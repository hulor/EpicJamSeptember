// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RandomMove.h"
#include "GravityComponent.h"
#include "PlanetCitizen.generated.h"

UCLASS()
class DEATHLESSMANKIND_API APlanetCitizen : public AActor
{
	GENERATED_BODY()

private:

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
		USkeletalMeshComponent* Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Move)
		URandomMove* RandMove;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Move)
		UGravityComponent* Gravity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Move)
		UProjectileMovementComponent* Projectile;

public:	
	// Sets default values for this actor's properties
	APlanetCitizen(const class FObjectInitializer& PCIP);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
