/*
* EZ-Mobile-Ads - unreal engine 4 ads plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com> All Rights Reserved.
*/

#pragma once

#include "Engine.h"
#include "AdCollectionBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/

UENUM(BlueprintType)		
enum class EAdType : uint8
{
	Vungle 	UMETA(DisplayName = "Vungle"),  // the vungle ads type
	AdMob 	UMETA(DisplayName = "AdMob"),	// the admob ads type
	Unity 	UMETA(DisplayName = "Unity"),	// the unity ads type
	ChartBoost 	UMETA(DisplayName = "ChartBoost")	// the chartboost ads type
};


USTRUCT(BlueprintType)
struct FAdMobRewardItem
{
	GENERATED_USTRUCT_BODY()
	
	/** the admob rewarded item type*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Type;

	/** the admob rewarded item value*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Amount;
};


USTRUCT(BlueprintType)
struct FRewardedStatus
{
	GENERATED_USTRUCT_BODY()
	
	/** the rewarded ads type*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EAdType AdType;

	/** if the AdType is AdMob, the AdmobItem is valid*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FAdMobRewardItem  AdMobItem;

	/** if the AdType is ChartBoost the value is the reward value*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 ChartBoostReward;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayRewardedDelegate, FRewardedStatus, RewardStatus);

UCLASS()
class UAdCollectionBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	/**
	* play rewardedvideo ads
	* @param	adType			the ads type
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SimplePlayRewardedVideo", Keywords = "AdCollection Play"), Category = "AdCollection")
	static void PlayAdVideo(EAdType adType);

	/**
	* Show  banner
	* @param	isOnBottom		if the banner show on the bottom of the screen
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ShowBanner", Keywords = "AdCollection Show Banner"), Category = "AdCollection")
	static void ShowBanner(EAdType adType, bool isOnBottom);

	/**
	* hide  banner
	* @param	adType			the  ads type
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HideBanner", Keywords = "AdCollection Hide Banner"), Category = "AdCollection")
	static void HideBanner(EAdType adType);

	/**
	* show interstitial ads
	* @param	adType			the  ads type
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ShowInterstitial", Keywords = "AdCollection Show Interstitial Ads"), Category = "AdCollection")
	static void ShowInterstitial(EAdType adType);

	/**
	* check is the banner is load finish
	* @param	adType			the  ads type
	*/
	UFUNCTION(BlueprintPure, meta = (DisplayName = "IsBannerAdsReady", Keywords = "AdCollection Check Banner Ads Ready"), Category = "AdCollection")
	static bool IsBannerReady(EAdType adType);

	/**
	* check is the interstitial is load finish
	* @param	adType			the  ads type
	*/
	UFUNCTION(BlueprintPure, meta = (DisplayName = "IsInterstitialAdsReady", Keywords = "AdCollection Check Interstital Ads Ready"), Category = "AdCollection")
	static bool IsInterstitialReady(EAdType adType);

	/**
	* check is the rewardedvideo ads load finish
	* @param	adType			the  ads type
	*/
	UFUNCTION(BlueprintPure, meta = (DisplayName = "IsRewardedVideoAdsReady", Keywords = "AdCollection Check RewardedVideo Ads Ready"), Category = "AdCollection")
	static bool IsRewardedVideoReady(EAdType adType);
};
