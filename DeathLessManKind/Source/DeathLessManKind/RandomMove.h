// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "RandomMove.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEATHLESSMANKIND_API URandomMove : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category = Move)
		FVector	_dir;
	float	_timeLastRand;
	float	_timeNextRand;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Move)
		float	MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Move)
		float	MinAngleDirection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Move)
		float	MaxAngleDirection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rand | Move")
		float	MinTimeBeforeNextRand;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rand | Move")
		float	MaxTimeBeforeNextRand;

protected:
	void	RandomizeDirection();

public:	
	// Sets default values for this component's properties
	URandomMove();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	
};
