// Fill out your copyright notice in the Description page of Project Settings.


#include "acero.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

// Sets default values
Aacero::Aacero()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	// Crear el componente de malla
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroMesh"));
	RootComponent = MeshComponent;

	// Cargar la malla desde el contenido del juego
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (MeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
	}
	// Configura la colisión
	MeshComponent->SetSimulatePhysics(false);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MeshComponent->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	MeshComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

	// Carga sonido de impacto desde los assets del juego
	static ConstructorHelpers::FObjectFinder<USoundBase> SoundAsset(TEXT("/Game/StarterContent/Audio/Collapse02.Collapse02"));
	if (SoundAsset.Succeeded())
	{
		ImpactSound = SoundAsset.Object;
	}
}

// Called when the game starts or when spawned
void Aacero::BeginPlay()
{
	Super::BeginPlay();
	
}
// Función para colocar el muro en una posición específica
void Aacero::SetPosition(FVector NewPosition)
{
	SetActorLocation(NewPosition);
}
// Función para cuando el muro recibe un impacto (ejemplo: una explosión)
void Aacero::OnHit()
{
	if (ImpactSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation());
	}
}

// Called every frame
void Aacero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

