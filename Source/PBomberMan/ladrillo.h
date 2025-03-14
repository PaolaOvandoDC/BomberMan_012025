// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ladrillo.generated.h"

UCLASS()
class PBOMBERMAN_API Aladrillo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aladrillo();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Función que maneja la superposición con el jugador
	UFUNCTION()
	void OnPlayerHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	// Componente de malla
	UPROPERTY(VisibleAnywhere, Category = "Ladrillo")
	UStaticMeshComponent* MeshComponent;
}; 


