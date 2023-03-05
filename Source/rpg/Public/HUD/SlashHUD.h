// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SlashHUD.generated.h"

class USlashOverlay;
class UItemInfo;
/**
 * 
 */
UCLASS()
class RPG_API ASlashHUD : public AHUD
{
	GENERATED_BODY()

protected:
	void virtual BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = Slash)
	TSubclassOf<USlashOverlay> SlashOverlayClass;

	UPROPERTY()
	USlashOverlay* SlashOverlay;

	UPROPERTY(EditDefaultsOnly, Category = Slash)
	TSubclassOf<UItemInfo> ItemInfoClass;

	UPROPERTY()
	UItemInfo* ItemInfo;

public:
	UFUNCTION(BlueprintCallable)
	USlashOverlay* GetSlashOverlay();

	UFUNCTION(BlueprintCallable)
	UItemInfo* GetItemInfo();
};
