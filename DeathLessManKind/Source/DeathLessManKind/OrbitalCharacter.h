// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "OrbitalCharacter.generated.h"

UCLASS()
class DEATHLESSMANKIND_API AOrbitalCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	bool	_moveActivated;
	int32	_currentWeapon;

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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Power)
		TArray<TSubclassOf<AActor>>	Powers;

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

	void	SelectWeapon1();
	void	SelectWeapon2();
	void	SelectWeapon3();
	void	SelectWeapon4();

	UFUNCTION(BlueprintCallable, Category = Power)
		void	SelectWeapon(int32 weaponId);

	void	Shot();
	
};
