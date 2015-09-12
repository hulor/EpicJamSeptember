// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "OrbitalCharacter.generated.h"

UCLASS()
class DEATHLESSMANKIND_API AOrbitalCharacter : public ACharacter
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SpringArm)
		USpringArmComponent* _arm;

public:
	// Sets default values for this character's properties
	AOrbitalCharacter(const class FObjectInitializer& PCIP);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void RotateAroundZ(float axis);
	void RotateAroundX(float axis);
	
};
