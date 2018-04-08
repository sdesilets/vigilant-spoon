// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSBlackhole.generated.h"

class UPrimitiveComponent;
class USphereComponent;
struct FHitResult;

UCLASS()
class FPSGAME_API AFPSBlackhole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSBlackhole();

	UPROPERTY(VisibleAnywhere, Category="Mesh")
	UStaticMeshComponent* MeshComp;
	
	UPROPERTY(VisibleAnywhere, Category = "Destructor")
	USphereComponent* DestructorComponent;

	UPROPERTY(VisibleAnywhere, Category = "Attractor")
	USphereComponent* AttractorComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
