// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSObjectiveActor.generated.h"

class USphereComponent;
UCLASS()
class FPSGAME_API AFPSObjectiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSObjectiveActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* SphereComp;

	void PlayEffects();
	UPROPERTY(EditDefaultsOnly, Category="FX")
	UParticleSystem* PickupFX;

	UPROPERTY(EditDefaultsOnly, Category = "FX")
    UParticleSystem* SpawnFX;

	bool IsSpawning;

public:	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;


};
