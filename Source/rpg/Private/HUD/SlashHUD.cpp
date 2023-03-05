#include "HUD/SlashHUD.h"
#include "HUD/ItemInfo.h"
#include "HUD/SlashOverlay.h"

void ASlashHUD::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* Controller = World->GetFirstPlayerController();
		if (Controller)
		{
			if (SlashOverlayClass)
			{
				SlashOverlay = CreateWidget<USlashOverlay>(Controller, SlashOverlayClass);
				SlashOverlay->AddToViewport();
			}

			if (ItemInfoClass)
			{
				ItemInfo = CreateWidget<UItemInfo>(Controller, ItemInfoClass);
				ItemInfo->AddToViewport();
			}
		}
		

		
	}
}

USlashOverlay* ASlashHUD::GetSlashOverlay()
{
	if (SlashOverlay)
	{
		return SlashOverlay;
	}
	return nullptr;
}

UItemInfo* ASlashHUD::GetItemInfo()
{
	if (ItemInfo)
	{
		return ItemInfo;
	}
	return nullptr;
}
