// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

class UButton;
class IMenuInterface;

UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetMenuInterface(IMenuInterface* MenuInterface);
	void Setup();
	void Teardown();
protected:
	virtual bool Initialize() override;

private:
	IMenuInterface* MenuInterface;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Host;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Join;
	
	UFUNCTION()
	void HostServer();
};
