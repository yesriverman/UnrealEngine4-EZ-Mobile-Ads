/*
* EZ-Mobile-Ads - unreal engine 4 ads plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com> All Rights Reserved.
*/

#pragma once

#include "UObject/NoExportTypes.h"
#include "AdMobSetting.generated.h"

/**
 * 
 */
UCLASS(transient, config = Engine)
class UAdMobSetting : public UObject
{
	GENERATED_BODY()
	
	// if the android admob enable
	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "If AdMob Android Enable"))
	bool bAndroidEnabled;

	// the android admob appid
	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "Android AppID"))
	FString AndroidAppId;

	// the banner adunit
	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "Android Banner AdUnit"))
	FString AndroidBannerUnit;

	// the interstitial adunit
	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "Android Interstitial AdUnit"))
	FString AndroidInterstitialUnit;

	// the rewardedvideo adunit
	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "Android RewardVideo AdUnit"))
	FString AndroidRewardedVideoAdUnit;
    
    // if the ios admob enable
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "If AdMob IOS Enable"))
    bool bIOSEnabled;
    
	// the admob ios app id
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "IOS AppID"))
    FString IOSAppId;
    
	// the admob ios banner adunit
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "IOS Banner AdUnit"))
    FString IOSBannerUnit;
    
	// the admob ios interstitial adunit
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "IOS Interstitial AdUnit"))
    FString IOSInterstitialUnit;
    
	// the admob ios rewardedvideo adunit
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "IOS RewardVideo AdUnit"))
    FString IOSRewardedVideoAdUnit;
	
#if WITH_EDITOR
	
	// UObject interface
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
};
