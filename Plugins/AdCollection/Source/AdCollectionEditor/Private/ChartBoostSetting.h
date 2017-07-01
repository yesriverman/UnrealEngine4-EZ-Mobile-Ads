// Fill out your copyright notice in the Description page of Project Settings.

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
	
		UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "If Android Enable"))
		bool bIsAndroidEnabled;

	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "Android AppID"))
		FString AndroidAppId;

	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "Android Signature"))
		FString AndroidSignature;
    
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "If IOS Enable"))
    bool bIsIOSEnabled;
    
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "IOS AppID"))
    FString IOSAppId;
    
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "IOS Signature"))
    FString IOSSignature;
	
#if WITH_EDITOR
		// UObject interface
		virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};
