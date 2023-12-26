// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"

#include "Menu.generated.h"

class UButton;
class UMultiplayerSessionsSubsystem;

UCLASS()
class MULTIPLAYERSESSION_API UMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
		void MenuSetup(int32 NumverOfPublicconnections = 4, FString TypeOfMatch = FString(TEXT("FreeForAll")), FString LobbyPath = FString(TEXT("/Game/ThirdPerson/Maps/LobbyLevel")));

protected:
	virtual bool Initialize() override;

	virtual void NativeDestruct() override;

protected:
	UFUNCTION()
	void OnCreateSessionComplete(bool bWasSucceful);
	
	void OnFindSessionComplete(const TArray<FOnlineSessionSearchResult>& SearchResults, bool bWasSucceful);

	void OnJoinSessionComplete(EOnJoinSessionCompleteResult::Type Result);

	UFUNCTION()
	void OnDestroySessionComplete(bool bWasSucceful);

	UFUNCTION()
	void OnStartSessionComplete(bool bWasSucceful);

private:
	UPROPERTY(meta = (BindWidget))
	UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	UButton* JoinButton;

	UFUNCTION()
	void HostButtonClicked();

	UFUNCTION()
	void JoinButtonClicked();

	void MenuTearDown();

	UMultiplayerSessionsSubsystem* MultiplayerSessionsSubsystem;

	int32 NumPublicConnections;
	FString MatchType;
	FString PathToLobby;
};
