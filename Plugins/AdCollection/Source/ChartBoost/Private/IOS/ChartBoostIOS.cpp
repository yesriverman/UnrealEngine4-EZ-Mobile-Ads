/*
* EZ-Mobile-Ads - unreal engine 4 ads plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com> All Rights Reserved.
*/

#include "ChartBoost.h"
#include "IOSAppDelegate.h"
#import <AdsUtil/AdsUtil.h>

void FChartBoostModule::PlayRewardedVideo()
{
    UIViewController* curViewController = (UIViewController*)[IOSAppDelegate GetDelegate].IOSController;
    [[ChartBoostHelper GetDelegate] performSelectorOnMainThread:@selector(Play:) withObject:curViewController waitUntilDone:NO];
}

void FChartBoostModule::ShowInterstitialAd()
{
    [[ChartBoostHelper GetDelegate] performSelectorOnMainThread:@selector(ShowInterstitialAds) withObject:nil waitUntilDone:NO];
}

bool FChartBoostModule::IsInterstitalReady()
{
    NSMutableDictionary *resultDictionary = [NSMutableDictionary dictionaryWithCapacity:1];
    [[ChartBoostHelper GetDelegate] performSelectorOnMainThread:@selector(IsInterstitalReady:) withObject:resultDictionary waitUntilDone:YES];
    
    NSNumber* number = (NSNumber*)[resultDictionary objectForKey:@"RetValue"];
    bool ret = (bool)[number boolValue];
    
    return ret;
}

bool FChartBoostModule::IsRewardedVideoReady()
{
    NSMutableDictionary *resultDictionary = [NSMutableDictionary dictionaryWithCapacity:1];
    [[ChartBoostHelper GetDelegate] performSelectorOnMainThread:@selector(IsPlayable:) withObject:resultDictionary waitUntilDone:YES];
    
    NSNumber* number = (NSNumber*)[resultDictionary objectForKey:@"RetValue"];
    bool ret = (bool)[number boolValue];
    
    return ret;
}


static void IOS_ChartBoostPlayComplete(int amount)
{
    FChartBoostModule* pModule = FModuleManager::Get().LoadModulePtr<FChartBoostModule>(TEXT("ChartBoost") );
	if (pModule == nullptr)
	{
		return;
	}
    
    FRewardedStatus status;
    status.AdType = EAdType::ChartBoost;
    status.ChartBoostReward = (int)amount;
    
    pModule->TriggerPlayRewardCompleteDelegates(status);
}


void FChartBoostModule::StartupModule()
{
    bool isEnable = false;
    
    GConfig->GetBool(TEXT("/Script/AdCollectionEditor.ChartBoostSetting"), TEXT("bIsIOSEnabled"), isEnable, GEngineIni);
    if(isEnable)
    {
        FString appId;
        GConfig->GetString(TEXT("/Script/AdCollectionEditor.ChartBoostSetting"), TEXT("IOSAppId"), appId, GEngineIni);
        
        FString appSignature;
        GConfig->GetString(TEXT("/Script/AdCollectionEditor.ChartBoostSetting"), TEXT("IOSSignature"), appSignature, GEngineIni);
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [[ChartBoostHelper GetDelegate] InitSDK:[NSString stringWithFString:appId] AppSignature:[NSString stringWithFString:appSignature] callback:&IOS_ChartBoostPlayComplete];
        });
    }
}

void FChartBoostModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
    
}
