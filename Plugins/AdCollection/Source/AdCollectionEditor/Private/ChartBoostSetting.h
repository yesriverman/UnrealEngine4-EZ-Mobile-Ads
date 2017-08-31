/*
* EZ-Mobile-Ads - unreal engine 4 ads plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com> All Rights Reserved.
*/


#pragma once

#include "UObject/NoExportTypes.h"
#include "ChartBoostSetting.generated.h"

/**
 * 
 */
UCLASS(transient, config = Engine)
class UChartBoostSetting : public UObject
{
	GENERATED_BODY()
	
	// if the android chartboost enable
	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "If Android Enable"))
	bool bIsAndroidEnabled;

	// the android chartboost appid
	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "Android AppID"))
	FString AndroidAppId;

	// the android app signature
	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "Android Signature"))
	FString AndroidSignature;
    
	// if the ios chartboost enable
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "If IOS Enable"))
    bool bIsIOSEnabled;
    
	// the ios chartboost appid
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "IOS AppID"))
    FString IOSAppId;
    
	// the ios chartboost signature
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "IOS Signature"))
    FString IOSSignature;
	
#if WITH_EDITOR
	// UObject interface
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};
