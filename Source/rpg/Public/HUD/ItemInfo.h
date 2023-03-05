// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemInfo.generated.h"

class UImage;
class UTextBlock;
/**
 * 
 */
UCLASS()
class RPG_API UItemInfo : public UUserWidget
{
	GENERATED_BODY()
public:

protected:
	virtual void NativePreConstruct() override;



private:
	UPROPERTY(meta = (BindWidget))
	UImage* ItemImage;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Name;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Price;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Ability;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Description;

public:
	void SetItemImage(UTexture2D* Image);
	void SetName(FString name);
	void SetPrice(int32 price);
	void SetAbility(int32 ability);
	void SetDescription(FString description);
};
