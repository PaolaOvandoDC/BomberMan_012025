// Fill out your copyright notice in the Description page of Project Settings.


#include "ladrillo.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"

// Sets default values
Aladrillo::Aladrillo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Crear el componente de malla (si no está creado)
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LadrilloMesh"));
	RootComponent = MeshComponent;

	// Cargar la malla desde el contenido del juego
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (MeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
	}
     
	// Permitir eventos de superposición
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MeshComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	MeshComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap); // Detectar solo jugadores

	// Vincular la función al evento de superposición
	MeshComponent->OnComponentBeginOverlap.AddDynamic(this, &Aladrillo::OnPlayerHit);

}

// Called when the game starts or when spawned
void Aladrillo::BeginPlay()
{
	Super::BeginPlay();
	
}
void Aladrillo::OnPlayerHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Player")) // Verifica si el que colisionó es el jugador
	{
		Destroy(); // El ladrillo desaparece
	}
}

// Called every frame
void Aladrillo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

