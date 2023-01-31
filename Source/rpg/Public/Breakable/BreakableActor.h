#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/HitInterface.h"
#include "BreakableActor.generated.h"

class UGeometryCollectionComponent;
class ATreasure;
class UCapsuleComponent;


UCLASS()
class RPG_API ABreakableActor : public AActor, public IHitInterface
{
	GENERATED_BODY()
	
public:	
	ABreakableActor();
	virtual void Tick(float DeltaTime) override;

	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UGeometryCollectionComponent* GeometryCollection;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UCapsuleComponent* Capsule;

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Breakable Properties")
	TArray<TSubclassOf<ATreasure>> TreasureClasses;

};
