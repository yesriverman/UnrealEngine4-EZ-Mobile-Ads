/*
* EZ-Mobile-Ads - unreal engine 4 ads plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com> All Rights Reserved.
*/

#include "Unity.h"
#include "IOSAppDelegate.h"
#import <AdsUtil/AdsUtil.h>

void FUnityModule::PlayRewardedVideo()
{
    UIViewController* curViewController = (UIViewController*)[IOSAppDelegate GetDelegate].IOSController;
    [[UnityHelper GetDelegate] performSelectorOnMainThread:@selector(Play:) withObject:curViewController waitUntilDone:NO];

}

bool FUnityModule::IsRewardedVideoReady()
{
    NSMutableDictionary *resultDictionary = [NSMutableDictionary dictionaryWithCapacity:1];
    [[UnityHelper GetDelegate] performSelectorOnMainThread:@selector(IsPlayable:) withObject:resultDictionary waitUntilDone:YES];
    
    NSNumber* number = (NSNumber*)[resultDictionary objectForKey:@"RetValue"];
    bool ret = (bool)[number boolValue];
    
    return ret;
}


static void IOS_UnityPlayComplete()
{
    FUnityModule* pModule = FModuleManager::Get().LoadModulePtr<FUnityModule>(TEXT("Unity") );
	if (pModule == nullptr)
	{
		return;
	}
    
    FRewardedStatus status;
    status.AdType = EAdType::Unity;
    
    pModule->TriggerPlayRewardCompleteDelegates(status);
}


void FUnityModule::StartupModule()
{
    bool isEnable = false;
    
    GConfig->GetBool(TEXT("/Script/AdCollectionEditor.UnitySetting"), TEXT("bIsIOSEnabled"), isEnable, GEngineIni);
    if(isEnable)
    {
        FString appId;
        GConfig->GetString(TEXT("/Script/AdCollectionEditor.UnitySetting"), TEXT("IOSAppId"), appId, GEngineIni);
        
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [[UnityHelper GetDelegate] InitSDK:[NSString stringWithFString:appId] callback:&IOS_UnityPlayComplete];
        });
    }

}

void FUnityModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
    
}
