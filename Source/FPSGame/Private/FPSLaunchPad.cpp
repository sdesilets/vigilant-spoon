// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSLaunchPad.h"
#include "Components/BoxComponent.h"
#include "FPSCharacter.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AFPSLaunchPad::AFPSLaunchPad()
{
	TriggerZone = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Zone"));
	TriggerZone->SetBoxExtent(FVector(75, 75, 50));
	RootComponent = TriggerZone;
	TriggerZone->OnComponentBeginOverlap.AddDynamic(this, &AFPSLaunchPad::HandleOverlap);

	LaunchPadMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Launch Pad"));
	LaunchPadMesh->SetupAttachment(RootComponent);

	LaunchAngle = 75.0f;
	LaunchStrength = 2000.0f;
}

void AFPSLaunchPad::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FRotator launchPadRotator = GetActorRotation();
	launchPadRotator.Pitch = LaunchAngle;
	FVector launchVelocity = launchPadRotator.Vector() * LaunchStrength;

	AFPSCharacter* player = Cast<AFPSCharacter>(OtherActor);

	if (player)
	{
		player->LaunchCharacter(launchVelocity, true, true);
	}
	else if (OtherComp && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulse(launchVelocity, NAME_None, true);
	}
}

