// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "madera.generated.h"

UCLASS()
class PBOMBERMAN_API Amadera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Amadera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Función que maneja la superposición con el jugador o las explosiones
	UFUNCTION()
	void OnPlayerHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
private:
	// Componente de malla
	UPROPERTY(VisibleAnywhere, Category = "Madera")
	UStaticMeshComponent* MeshComponent;
	// Sonido cuando la madera se destruye
	UPROPERTY(EditAnywhere, Category = "Efectos")
	USoundBase* DestructionSound;
	// Material para la textura de la madera
	UPROPERTY(EditAnywhere, Category = "Material")
	UMaterialInterface* MaderaMaterial;
};
