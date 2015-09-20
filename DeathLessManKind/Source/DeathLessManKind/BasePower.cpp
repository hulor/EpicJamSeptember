// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathLessManKind.h"
#include "BasePower.h"
#include "PlanetCitizen.h"
#include "CitizenState.h"

DEFINE_LOG_CATEGORY(BasePower);

// Sets default values
ABasePower::ABasePower(const class FObjectInitializer& PCIP)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->RootComponent = PCIP.CreateDefaultSubobject<USceneComponent>(this, TEXT("Root"));
	Collider = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("Collider"));
	Collider->AttachTo(this->RootComponent);
	ImpulsionForce = 1000.0f;
}

// Called when the game starts or when spawned
void	ABasePower::BeginPlay()
{
	Super::BeginPlay();

	TScriptDelegate<FWeakObjectPtr> beginDelegate;
	_time = 0.0f;
	Collider->SetRelativeScale3D(StartColliderSize);

	beginDelegate.BindUFunction(this, FName("OnBeginOverlap"));
	Collider->OnComponentBeginOverlap.Add(beginDelegate);
	TArray<AActor*> actors;
	ACitizenState* state = Cast<ACitizenState>(GetWorld()->GetGameState());

	Collider->GetOverlappingActors(actors, APlanetCitizen::StaticClass());

	if (state != NULL)
	{
		state->PlanetPop -= actors.Num();
		state->SpacePop += actors.Num();
	}
	for (int i = 0, size = actors.Num(); i < size; ++i)
	{
		Cast<APlanetCitizen>(actors[i])->Projectile->Velocity = (actors[i]->GetActorLocation() - this->GetActorLocation()).SafeNormal() * ImpulsionForce;
	}
}

// Called every frame
void	ABasePower::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	_time += DeltaTime;
	if (_time > GrownDuration)
		return ;
	Collider->SetRelativeScale3D(FMath::Lerp(StartColliderSize, EndColliderSize, (_time / GrownDuration)));
}

void	ABasePower::OnBeginOverlap(AActor* other)
{
	APlanetCitizen* citizen = Cast<APlanetCitizen>(other);
	UE_LOG(BasePower, Warning, TEXT("Overlap!"));

	if (citizen == NULL)
	{
		UE_LOG(BasePower, Warning, TEXT("No citizen here!"));
		return;
	}
	citizen->Projectile->Velocity = (citizen->GetActorLocation() - this->GetActorLocation()).SafeNormal() * ImpulsionForce;
	ACitizenState* state = Cast<ACitizenState>(GetWorld()->GetGameState());

	if (state != NULL)
	{
		state->PlanetPop -= 1;
		state->SpacePop += 1;
	}
}

void	ABasePower::Init(FVector dest, FVector normale)
{
	this->SetActorLocation(dest);
	this->SetActorRotation(FRotationMatrix::MakeFromZ(normale).ToQuat());
}

