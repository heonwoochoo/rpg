// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/item.h"
#include "Weapon.generated.h"

class USoundBase;

/**
 * 
 */
UCLASS()
class RPG_API AWeapon : public Aitem
{
	GENERATED_BODY()
	
public:
	void Equip(USceneComponent* InParent, FName InputSocketName);
	void AttachMeshToSocket(USceneComponent* InParent, const FName& InputSocketName);

protected:
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

private:
	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
	USoundBase* EquipSound;
};
