// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BasePower.generated.h"

UCLASS()
class DEATHLESSMANKIND_API ABasePower : public AActor
{
	GENERATED_BODY()

private:
	float	_time;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collision)
		UShapeComponent* Collider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collision)
		FVector	StartColliderSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collision)
		FVector	EndColliderSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collision)
		float	GrownDuration;

public:	
	// Sets default values for this actor's properties
	ABasePower(const class FObjectInitializer& PCIP);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
};
