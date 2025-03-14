// Fill out your copyright notice in the Description page of Project Settings.


#include "madera.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/MaterialInterface.h"

// Sets default values
Amadera::Amadera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Crear el componente de malla
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MaderaMesh"));
	RootComponent = MeshComponent;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (MeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
	}
	// Asignar material de madera
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaderaMaterial(TEXT("/Game/StarterContent/Textures/T_Wood_Oak_D.T_Wood_Oak_D"));
	if (MaderaMaterial.Succeeded())
	{
		MeshComponent->SetMaterial(0, MaderaMaterial.Object); // Aplica el material a la malla
	}

	// Permitir eventos de superposición
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MeshComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	MeshComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap); // Detectar solo jugadores
	// Vincular la función al evento de superposición
	MeshComponent->OnComponentBeginOverlap.AddDynamic(this, &Amadera::OnPlayerHit);
}

// Called when the game starts or when spawned
void Amadera::BeginPlay()
{
	Super::BeginPlay();
	
}
void Amadera::OnPlayerHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Player")) // Verifica si el que colisionó es el jugador
	{
		// Reproducir el sonido de destrucción
		if (DestructionSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, DestructionSound, GetActorLocation());
		}
		// Destruir la madera
		Destroy();
	}
}


// Called every frame
void Amadera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

