// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"
#include "Blueprint/UserWidget.h" 
#include "MenuSystem/MainMenu.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Constructor"))
}

void UPuzzlePlatformsGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"))
}

void UPuzzlePlatformsGameInstance::Host()
{
	TObjectPtr<UWorld> World = GetWorld();
	UE_LOG(LogTemp, Warning, TEXT("aaaaaaaa!"))
	if (!World) { return; }

	World->ServerTravel("/Game/ThirdPerson/Maps/ThirdPersonMap?listen");
	
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Hosting"));
	}
}

void UPuzzlePlatformsGameInstance::Join(FString Address)
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, (TEXT("Joining %s"), Address));
	}

	TObjectPtr<APlayerController> PlayerController = GetFirstLocalPlayerController();
	if (!PlayerController) { return; }
	
	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

void UPuzzlePlatformsGameInstance::LoadMenu()
{

	if (!UserWidgetClass) { return; }
	TObjectPtr<UMainMenu> Menu = CreateWidget<UMainMenu>(this, UserWidgetClass);

	if (!Menu) { return; }
	Menu->AddToViewport();

	TObjectPtr<APlayerController> PlayerController = GetFirstLocalPlayerController();
	if (!PlayerController) { return; }
	
	FInputModeUIOnly ModeData;
	ModeData.SetWidgetToFocus(Menu->TakeWidget());
	ModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PlayerController->SetInputMode(ModeData);
	PlayerController->bShowMouseCursor = true;

	Menu->SetMenuInterface(this);
}
