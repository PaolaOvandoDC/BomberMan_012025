// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "concreto.generated.h"

UCLASS()
class PBOMBERMAN_API Aconcreto : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aconcreto();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(VisibleAnywhere, Category = "bloque")
	UStaticMeshComponent* MeshComponent;

	FVector Posicioninicial;
	float amplitud = 200.0f; //esto es para cuanto se movera de un lado al otro
	float velocidadeoscilacion = 4.0f; // limite del movimientp

	// Temporizador para autodestruirse
	FTimerHandle TimerHandle;
	void Destruirconcreto();
};
