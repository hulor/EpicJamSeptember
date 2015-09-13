// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "GravityComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(GravityComp, Log, All);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEATHLESSMANKIND_API UGravityComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Mass of the object in kilograms. */
	UPROPERTY(VisibleAnywhere, Category = Gravity)
		FVector force;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gravity)
		float	Mass;

public:	
	// Sets default values for this component's properties
	UGravityComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	
};
