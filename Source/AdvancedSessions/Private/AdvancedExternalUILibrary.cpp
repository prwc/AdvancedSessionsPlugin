// Fill out your copyright notice in the Description page of Project Settings.
#include "OnlineSubSystemHeader.h"
#include "AdvancedExternalUILibrary.h"

//General Log
DEFINE_LOG_CATEGORY(AdvancedExternalUILog);

void UAdvancedExternalUILibrary::ShowAccountUpgradeUI(const FBPUniqueNetId PlayerRequestingAccountUpgradeUI, TEnumAsByte<EBlueprintResultSwitch::Type> &Result)
{
	IOnlineExternalUIPtr ExternalUIInterface = Online::GetExternalUIInterface();

	if (!ExternalUIInterface.IsValid())
	{
		UE_LOG(AdvancedExternalUILog, Warning, TEXT("ShowAccountUpgradeUI Failed to get External UI interface!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	ExternalUIInterface->ShowAccountUpgradeUI(*PlayerRequestingAccountUpgradeUI.GetUniqueNetId());
	Result = EBlueprintResultSwitch::Type::OnSuccess;
}

void UAdvancedExternalUILibrary::ShowProfileUI(const FBPUniqueNetId PlayerViewingProfile, const FBPUniqueNetId PlayerToViewProfileOf, TEnumAsByte<EBlueprintResultSwitch::Type> &Result)
{

	IOnlineExternalUIPtr ExternalUIInterface = Online::GetExternalUIInterface();

	if (!ExternalUIInterface.IsValid())
	{
		UE_LOG(AdvancedExternalUILog, Warning, TEXT("ShowProfileUI Failed to get External UI interface!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}
	
	ExternalUIInterface->ShowProfileUI(*PlayerViewingProfile.GetUniqueNetId(), *PlayerToViewProfileOf.GetUniqueNetId(), NULL);
	Result = EBlueprintResultSwitch::Type::OnSuccess;
}



void UAdvancedExternalUILibrary::ShowWebURLUI(FString URLToShow, TEnumAsByte<EBlueprintResultSwitch::Type> &Result)
{
	IOnlineExternalUIPtr ExternalUIInterface = Online::GetExternalUIInterface();

	if (!ExternalUIInterface.IsValid())
	{
		UE_LOG(AdvancedExternalUILog, Warning, TEXT("ShowWebURLUI Failed to get External UI interface!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	ExternalUIInterface->ShowWebURL(URLToShow);
	Result = EBlueprintResultSwitch::Type::OnSuccess;
}

void UAdvancedExternalUILibrary::ShowLeaderBoardUI(FString LeaderboardName, TEnumAsByte<EBlueprintResultSwitch::Type> &Result)
{
	IOnlineExternalUIPtr ExternalUIInterface = Online::GetExternalUIInterface();

	if (!ExternalUIInterface.IsValid())
	{
		UE_LOG(AdvancedExternalUILog, Warning, TEXT("ShowLeaderboardsUI Failed to get External UI interface!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	ExternalUIInterface->ShowLeaderboardUI(LeaderboardName);
	Result = EBlueprintResultSwitch::Type::OnSuccess;

}


void UAdvancedExternalUILibrary::ShowInviteUI(APlayerController *PlayerController, TEnumAsByte<EBlueprintResultSwitch::Type> &Result)
{
	if (!PlayerController)
	{
		UE_LOG(AdvancedExternalUILog, Warning, TEXT("ShowInviteUI Had a bad Player Controller!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	IOnlineExternalUIPtr ExternalUIInterface = Online::GetExternalUIInterface();

	if (!ExternalUIInterface.IsValid())
	{
		UE_LOG(AdvancedExternalUILog, Warning, TEXT("ShowInviteUI Failed to get External UI interface!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	ULocalPlayer* Player = Cast<ULocalPlayer>(PlayerController->Player);

	if (!Player)
	{
		UE_LOG(AdvancedExternalUILog, Warning, TEXT("ShowInviteUI Failed to get ULocalPlayer for the given PlayerController!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	ExternalUIInterface->ShowInviteUI(Player->GetControllerId(), GameSessionName);
	Result = EBlueprintResultSwitch::Type::OnSuccess;
}

void UAdvancedExternalUILibrary::ShowFriendsUI(APlayerController *PlayerController, TEnumAsByte<EBlueprintResultSwitch::Type> &Result)
{
	if (!PlayerController)
	{
		UE_LOG(AdvancedExternalUILog, Warning, TEXT("ShowFriendsUI Had a bad Player Controller!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	IOnlineExternalUIPtr ExternalUIInterface = Online::GetExternalUIInterface();

	if (!ExternalUIInterface.IsValid())
	{
		UE_LOG(AdvancedExternalUILog, Warning, TEXT("ShowFriendsUI Failed to get External UI interface!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	ULocalPlayer* Player = Cast<ULocalPlayer>(PlayerController->Player);

	if (!Player)
	{
		UE_LOG(AdvancedExternalUILog, Warning, TEXT("ShowFriendsUI Failed to get ULocalPlayer for the given PlayerController!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	ExternalUIInterface->ShowFriendsUI(Player->GetControllerId());
	Result = EBlueprintResultSwitch::Type::OnSuccess;
}