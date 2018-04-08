// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSBlackhole.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"


// Sets default values
AFPSBlackhole::AFPSBlackhole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	RootComponent = MeshComp;

	DestructorComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Destructor"));
	DestructorComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	DestructorComponent->SetSphereRadius(100);
	DestructorComponent->SetupAttachment(MeshComp);
	DestructorComponent->OnComponentBeginOverlap.AddDynamic(this, &AFPSBlackhole::OnComponentOverlap);

	AttractorComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Attractor"));
	AttractorComponent->SetSphereRadius(3000);
	AttractorComponent->SetupAttachment(MeshComp);

}

void AFPSBlackhole::OnComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		OtherActor->Destroy();
	}
}

// Called when the game starts or when spawned
void AFPSBlackhole::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSBlackhole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<UPrimitiveComponent*> overlaps;
	AttractorComponent->GetOverlappingComponents(overlaps);
	float radius = AttractorComponent->GetScaledSphereRadius();

	for (auto comp : overlaps)
	{
		if (comp && comp->IsSimulatingPhysics()) 
		{ 
			comp->AddRadialForce(GetActorLocation(),radius, -2000.f, ERadialImpulseFalloff::RIF_Constant, true);
		}
	}
	
}

