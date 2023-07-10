// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"
#include "../PuzzlePlatformsGameInstance.h"

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) { return false; }

	if (!Host) { return false; }

	Host->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	return true;
}

void UMainMenu::SetMenuInterface(IMenuInterface* ParamMenuInterface)
{
	this->MenuInterface = ParamMenuInterface;
}

void UMainMenu::Setup()
{
	this->AddToViewport();

	TObjectPtr<UWorld> World = GetWorld();
	if (!World) { return; }

	TObjectPtr<APlayerController> PlayerController = World->GetFirstPlayerController();
	if (!PlayerController) { return; }

	FInputModeUIOnly ModeData;
	ModeData.SetWidgetToFocus(this->TakeWidget());
	ModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PlayerController->SetInputMode(ModeData);
	PlayerController->bShowMouseCursor = true;
}

void UMainMenu::Teardown()
{
	this->RemoveFromViewport();

	TObjectPtr<UWorld> World = GetWorld();
	if (!World) { return; }

	TObjectPtr<APlayerController> PlayerController = World->GetFirstPlayerController();
	if (!PlayerController) { return; }

	FInputModeGameOnly ModeData;

	PlayerController->SetInputMode(ModeData);
	PlayerController->bShowMouseCursor = false;
}

void UMainMenu::HostServer()
{
	if (MenuInterface)
	{
		MenuInterface->Host();
	}
}