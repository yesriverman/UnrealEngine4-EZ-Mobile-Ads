/*
* EZ-Mobile-Ads - unreal engine 4 ads plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com> All Rights Reserved.
*/


#pragma once

#include "UObject/NoExportTypes.h"
#include "UnitySetting.generated.h"

/**
 * 
 */
UCLASS(transient, config = Engine)
class UUnitySetting : public UObject
{
	GENERATED_BODY()
	
	// if the android unity ads enable
    UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "If Is Unity Android Enable"))
	bool bIsAndroidEnabled;

	// the android unity appid
	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "Unity Android AppID"))
	FString AndroidAppId;
    
    // if the ios unity ads enable
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "If Is Unity IOS Enable"))
    bool bIsIOSEnabled;
    
	// the ios unity appid
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "Unity IOS AppID"))
    FString IOSAppId;


#if WITH_EDITOR
	// UObject interface
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
};
