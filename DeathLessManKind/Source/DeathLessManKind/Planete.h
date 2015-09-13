// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Planete.generated.h"

UCLASS()
class DEATHLESSMANKIND_API APlanete : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
		USkeletalMeshComponent* Mesh;
	/** Mass of the planete in kilograms. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gravity)
		float	Mass;

public:
	// Sets default values for this actor's properties
	APlanete(const class FObjectInitializer& PCIP);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
