// Fill out your copyright notice in the Description page of Project Settings.


#include "concreto.h"
#include "Engine/Engine.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h" //para usar temporizador


// Sets default values
Aconcreto::Aconcreto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    // Crear el componente de malla
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = MeshComponent;

    // Asignar una malla predeterminada (opcional)
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
    if (MeshAsset.Succeeded())
    {
        MeshComponent->SetStaticMesh(MeshAsset.Object);
    }
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("el bloque concreto se autodestruira en 10 segundos"));
    }

   // Posicioninicial = GetActorLocation();
    
    // Definir la velocidad del bloque (X = Avance, Y = Lateral, Z = Vertical)
    //Velocidad = FVector(100.0f, 100.0f, 50.0f); // Mueve el bloque en el eje X

}

// Called when the game starts or when spawned
void Aconcreto::BeginPlay()
{
	Super::BeginPlay();

    // Guardar la posición inicial
    Posicioninicial = GetActorLocation();

    // Programar la destrucción después de 10 segundos
    GetWorldTimerManager().SetTimer(TimerHandle, this, &Aconcreto::Destruirconcreto, 10.0f, false);
	
}

// Called every frame
void Aconcreto::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    float DeltaX = amplitud * FMath::Sin(GetWorld()->TimeSeconds * velocidadeoscilacion);

    // Nueva posición con oscilación
    FVector NuevaPosicion = Posicioninicial + FVector(DeltaX, 0.0f, 0.0f);

    // Aplicar la nueva posición al actor
    SetActorLocation(NuevaPosicion);
}

void Aconcreto::Destruirconcreto()
{
    Destroy(); //esto para destruir el bloque concreto
}

