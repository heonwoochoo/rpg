// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBar.generated.h"

class UProgressBar;

/**
 * 
 */
UCLASS()
class RPG_API UHealthBar : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// WBP_HealthBar 에서 생성된 ProgressBar와 이름이 일치되어야 바인딩이 됨
	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;
};
