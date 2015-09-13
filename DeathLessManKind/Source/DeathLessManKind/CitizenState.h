// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameState.h"
#include "CitizenState.generated.h"

/**
 * 
 */
UCLASS()
class DEATHLESSMANKIND_API ACitizenState : public AGameState
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Population)
		int32 PlanetPop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Population)
		int32 SpacePop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Population)
		int32 BlackHolePop;
	
};
