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
	// WBP_HealthBar ���� ������ ProgressBar�� �̸��� ��ġ�Ǿ�� ���ε��� ��
	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;
};
