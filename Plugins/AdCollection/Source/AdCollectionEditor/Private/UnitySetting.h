// Fill out your copyright notice in the Description page of Project Settings.

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
	
	
    UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "If Is Unity Android Enable"))
		bool bIsAndroidEnabled;

	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "Unity Android AppID"))
		FString AndroidAppId;
    
    
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "If Is Unity IOS Enable"))
    bool bIsIOSEnabled;
    
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "Unity IOS AppID"))
    FString IOSAppId;


#if WITH_EDITOR
	// UObject interface
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
};
