// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/item.h"
#include "Components/SphereComponent.h"
#include "Interfaces/PickupInterface.h"
#include "NiagaraComponent.h"

Aitem::Aitem()
{
	PrimaryActorTick.bCanEverTick = true;

	itemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	itemMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	itemMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = itemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());

	ItemEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Ember"));
	ItemEffect->SetupAttachment(GetRootComponent());
}

void Aitem::BeginPlay()
{
	Super::BeginPlay();

	// Dynamic multicast delegate (Binding)
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &Aitem::OnSphereOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &Aitem::OnSphereEndOverlap);
}

float Aitem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float Aitem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

void Aitem::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IPickupInterface* PickupInterface = Cast<IPickupInterface>(OtherActor);
	if (PickupInterface)
	{
		PickupInterface->SetOverlappingItem(this);
	}
}

void Aitem::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	IPickupInterface* PickupInterface = Cast<IPickupInterface>(OtherActor);
	if (PickupInterface)
	{
		PickupInterface->SetOverlappingItem(nullptr);
	}
}

void Aitem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;

	if (ItemState == EItemState::EIS_Hovering)
	{
		AddActorWorldOffset(FVector(0.f, 0.f, TransformedSin()));
	}
}

