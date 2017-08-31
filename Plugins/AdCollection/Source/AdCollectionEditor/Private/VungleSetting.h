/*
* EZ-Mobile-Ads - unreal engine 4 ads plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com> All Rights Reserved.
*/


#pragma once

#include "UObject/NoExportTypes.h"
#include "VungleSetting.generated.h"

/**
 * 
 */
UCLASS(transient, config = Engine)
class UVungleSetting : public UObject
{
	GENERATED_BODY()
	
	// if the android vungle ads enable
	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "If Is Vungle Android Enable"))
	bool bAndroidEnabled;

	// the android vungle appid
	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "Vungle Android AppID"))
	FString AndroidAppId;

    // if the ios vungle ads enable
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "If Is Vungle IOS Enable"))
    bool bIOSEnabled;
    
	// the ios vungle appid
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "Vungle IOS AppID"))
    FString IOSAppId;

#if WITH_EDITOR
	// UObject interface
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
};
