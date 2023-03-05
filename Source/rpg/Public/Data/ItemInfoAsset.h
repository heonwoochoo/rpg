// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemData.h"
#include "ItemInfoAsset.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API UItemInfoAsset : public UDataAsset
{
	GENERATED_BODY()
	public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Info")
	TArray<FGenericItemInfo> ItemInfoArray;
};
