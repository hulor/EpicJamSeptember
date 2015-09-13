// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathLessManKind.h"
#include "Planete.h"
#include "GravityComponent.h"

#define GCONST 0.0000000000667
DEFINE_LOG_CATEGORY(GravityComp);

// Sets default values for this component's properties
UGravityComponent::UGravityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGravityComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGravityComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	//FVector force;
	FVector dist;
	float gravityApplied = 0.0f;

	force = FVector::ZeroVector;
	for (TActorIterator<APlanete> it(GetWorld()); it; ++it)
	{
		dist = (it->GetActorLocation() - this->GetOwner()->GetActorLocation());
		if (dist.Size() < 20.0f)
			continue;
		gravityApplied = (GCONST * it->Mass * Mass) / (dist.SizeSquared() * 0.01f); // convert cm to m

		dist.Normalize();
		force += dist * (gravityApplied / Mass) * 100.0f; // convert m to cm
	}
	FHitResult hit;
	FCollisionQueryParams colParam;
	FCollisionObjectQueryParams colObjParam;

	if (this->GetWorld()->LineTraceSingle(hit, this->GetOwner()->GetActorLocation(), this->GetOwner()->GetActorLocation() + force * DeltaTime, colParam, colObjParam) == true)
	//if (this->GetOwner()->SetActorLocation(this->GetOwner()->GetActorLocation() + force * DeltaTime, true, &hit) == false)
	{
		//UE_LOG(GravityComp, Warning, TEXT("Sweep hit before set location!"));
		this->GetOwner()->SetActorRotation(FRotationMatrix::MakeFromY(hit.ImpactNormal).ToQuat());
		this->GetOwner()->SetActorLocation(hit.ImpactPoint);
	}
	else
	{
		this->GetOwner()->SetActorLocation(this->GetOwner()->GetActorLocation() + force * DeltaTime);
		//UE_LOG(GravityComp, Warning, TEXT("No hit!"));
	}
}

