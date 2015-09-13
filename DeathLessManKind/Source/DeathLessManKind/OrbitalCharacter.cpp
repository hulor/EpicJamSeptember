// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathLessManKind.h"
#include "OrbitalCharacter.h"


// Sets default values
AOrbitalCharacter::AOrbitalCharacter(const class FObjectInitializer& PCIP)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_arm = PCIP.CreateDefaultSubobject<USpringArmComponent>(this, TEXT("SpringArm"));
	ZoomSpeed = 50.0f;
	MinZoom = 200.0f;
	MaxZoom = 500.0f;
	InverseUpAxis = false;
	_moveActivated = false;
	_currentWeapon = 0;
}

// Called when the game starts or when spawned
void	AOrbitalCharacter::BeginPlay()
{
	APlayerController* pc = this->GetWorld()->GetFirstPlayerController();

	pc->bShowMouseCursor = true;
	pc->bEnableClickEvents = true;
	Super::BeginPlay();
	
}

// Called every frame
void	AOrbitalCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void	AOrbitalCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAction("ZoomIn", EInputEvent::IE_Pressed, this, &AOrbitalCharacter::ZoomIn);
	InputComponent->BindAction("ZoomOut", EInputEvent::IE_Pressed, this, &AOrbitalCharacter::ZoomOut);
	InputComponent->BindAction("MoveActivation", EInputEvent::IE_Pressed, this, &AOrbitalCharacter::MoveActivate);
	InputComponent->BindAction("MoveActivation", EInputEvent::IE_Released, this, &AOrbitalCharacter::MoveUnactivate);

	InputComponent->BindAction("Shot", EInputEvent::IE_Released, this, &AOrbitalCharacter::Shot);
	InputComponent->BindAction("SelectWeapon1", EInputEvent::IE_Released, this, &AOrbitalCharacter::SelectWeapon1);
	InputComponent->BindAction("SelectWeapon2", EInputEvent::IE_Released, this, &AOrbitalCharacter::SelectWeapon2);
	InputComponent->BindAction("SelectWeapon3", EInputEvent::IE_Released, this, &AOrbitalCharacter::SelectWeapon3);
	InputComponent->BindAction("SelectWeapon4", EInputEvent::IE_Released, this, &AOrbitalCharacter::SelectWeapon4);

	InputComponent->BindAxis("MouseMoveX", this, &AOrbitalCharacter::MouseRotateZ);
	InputComponent->BindAxis("MouseMoveY", this, &AOrbitalCharacter::MouseRotateX);
	InputComponent->BindAxis("ZRotation", this, &AOrbitalCharacter::RotateAroundZ);
	InputComponent->BindAxis("XRotation", this, &AOrbitalCharacter::RotateAroundX);
	InputComponent->BindAxis("Zoom", this, &AOrbitalCharacter::Zoom);
}

void	AOrbitalCharacter::MoveActivate()
{
	_moveActivated = true;
}

void	AOrbitalCharacter::MoveUnactivate()
{
	_moveActivated = false;
}

void	AOrbitalCharacter::MouseRotateZ(float axis)
{
	if (_moveActivated == false)
		return;
	RotateAroundZ(axis);
}

void	AOrbitalCharacter::MouseRotateX(float axis)
{
	if (_moveActivated == false)
		return;
	RotateAroundX(axis);
}

void	AOrbitalCharacter::RotateAroundZ(float axis)
{
	this->AddControllerYawInput(axis);
}

void	AOrbitalCharacter::RotateAroundX(float axis)
{
	if (InverseUpAxis == true)
		axis = -axis;
	this->AddControllerPitchInput(axis);
}

void	AOrbitalCharacter::ZoomIn()
{
	this->Zoom(1.0f);
}

void	AOrbitalCharacter::ZoomOut()
{
	this->Zoom(-1.0f);
}

void	AOrbitalCharacter::Zoom(float axis)
{
	if (_arm == NULL)
		return;
	_arm->TargetArmLength += axis * ZoomSpeed;
	_arm->TargetArmLength = FMath::Clamp(_arm->TargetArmLength, MinZoom, MaxZoom);
}

void	AOrbitalCharacter::SelectWeapon1()
{
	SelectWeapon(0);
}

void	AOrbitalCharacter::SelectWeapon2()
{
	SelectWeapon(1);

}

void	AOrbitalCharacter::SelectWeapon3()
{
	SelectWeapon(2);

}

void	AOrbitalCharacter::SelectWeapon4()
{
	SelectWeapon(3);
}

void	AOrbitalCharacter::SelectWeapon(int32 weaponId)
{
	_currentWeapon = weaponId;
}

void	AOrbitalCharacter::Shot()
{
	APlayerController* pc = Cast<APlayerController>(this->GetController());
	if (pc == NULL)
		return;

	FVector worldCursor;
	FVector dirCursor;

	pc->DeprojectMousePositionToWorld(worldCursor, dirCursor);
	this->GetWorld()->SpawnActor(this->Powers[_currentWeapon]); // cast to init
	//init with direction
}

