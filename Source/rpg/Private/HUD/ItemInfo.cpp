// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/ItemInfo.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UItemInfo::NativePreConstruct()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UItemInfo::SetItemImage(UTexture2D* Image)
{
	if (ItemImage)
	{
		ItemImage->SetBrushFromTexture(Image);
	}
}

void UItemInfo::SetName(FString name)
{
	if (Name)
	{
		Name->SetText(FText::FromString(name));
	}
}

void UItemInfo::SetPrice(int32 price)
{
	if (Price)
	{
		Price->SetText(FText::FromString(FString::FromInt(price)));
	}
}

void UItemInfo::SetAbility(int32 ability)
{
	if (Ability)
	{
		Ability->SetText(FText::FromString(FString::FromInt(ability)));
	}
}

void UItemInfo::SetDescription(FString description)
{
	if (Description)
	{
		Description->SetText(FText::FromString(description));
	}
}
