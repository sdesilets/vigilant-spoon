// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSLaunchPad.generated.h"

class UBoxComponent;

UCLASS()
class FPSGAME_API AFPSLaunchPad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSLaunchPad();

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* LaunchPadMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent * TriggerZone;

	UPROPERTY(EditInstanceOnly, Category ="Launch Pad")
	float LaunchAngle;

	UPROPERTY(EditInstanceOnly, Category = "Launch Pad")
	float LaunchStrength;

protected :
	
	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
