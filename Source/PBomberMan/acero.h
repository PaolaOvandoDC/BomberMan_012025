// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "acero.generated.h"

UCLASS()
class PBOMBERMAN_API Aacero : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aacero();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Configura la posición del muro en el mundo 
	void SetPosition(FVector NewPosition);

	// Función que podría llamarse cuando el muro recibe impacto 
	UFUNCTION()
	void OnHit();
private:
	// Componente de malla estática para representar el muro
	UPROPERTY(VisibleAnywhere, Category = "Muro")
	UStaticMeshComponent* MeshComponent;

	// Sonido cuando el muro recibe un impacto
	UPROPERTY(EditAnywhere, Category = "Sonido")
	class USoundBase* ImpactSound;
};
