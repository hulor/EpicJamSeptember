// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BasePower.h"
#include "ThrowablePower.generated.h"

/**
 * 
 */
UCLASS()
class DEATHLESSMANKIND_API AThrowablePower : public ABasePower
{
	GENERATED_BODY()

private:
	FVector _dest;
	FVector	_dir;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		FVector Offset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Move)
		float	Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FX)
		TSubclassOf<AActor>	DieFX;

public:
	virtual void	Tick(float DeltaSeconds) override;

	virtual void	Init(FVector dest, FVector normale) override;
	
};
