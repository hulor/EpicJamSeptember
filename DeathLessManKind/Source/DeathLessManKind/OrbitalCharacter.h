// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "OrbitalCharacter.generated.h"

UCLASS()
class DEATHLESSMANKIND_API AOrbitalCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	bool _moveActivated;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SpringArm)
		USpringArmComponent* _arm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Zoom)
		float	ZoomSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Zoom)
		float	MinZoom;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Zoom)
		float	MaxZoom;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Move)
		bool	InverseUpAxis;

public:
	// Sets default values for this character's properties
	AOrbitalCharacter(const class FObjectInitializer& PCIP);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void	MoveActivate();
	void	MoveUnactivate();
	void	MouseRotateZ(float axis);
	void	MouseRotateX(float axis);

	void	RotateAroundZ(float axis);
	void	RotateAroundX(float axis);
	void	ZoomIn();
	void	ZoomOut();
	void	Zoom(float axis);
	
};
