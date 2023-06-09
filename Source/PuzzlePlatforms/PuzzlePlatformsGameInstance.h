// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "PuzzlePlatformsGameInstance.generated.h"

class UMainMenu;

UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:
	UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init() override;

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(FString Address);
	
	UFUNCTION(BlueprintCallable)
	void LoadMenu();
protected:
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> UserWidgetClass;

private:
	 TObjectPtr<UMainMenu> Menu;
};
