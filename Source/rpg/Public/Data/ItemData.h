// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ItemData.generated.h"

UENUM()
enum class EItemType : uint8
{
	None UMETA(DisplayName = "None"),
	Sword UMETA(DisplayName = "Sword"),
	Axe UMETA(DisplayName = "Axe"),
};

USTRUCT(BlueprintType)
struct FGenericItemInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
	uint8 ItemCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
	uint8 ItemDurability;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
	FString ItemInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
	UStaticMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
	UTexture2D* ItemImage;

};

/**
 * 
 */
UCLASS()
class RPG_API UItemData : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
};
