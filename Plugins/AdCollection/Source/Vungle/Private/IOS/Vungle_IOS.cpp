/*
* EZ-Mobile-Ads - unreal engine 4 ads plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com> All Rights Reserved.
*/

#include "Vungle.h"
#include "IOSAppDelegate.h"
#import <VungleSDK/VungleSDK.h>
#import <AdsUtil/VungleHelper.h>


void FVungleModule::PlayRewardedVideo()
{
    UIViewController* curViewController = (UIViewController*)[IOSAppDelegate GetDelegate].IOSController;
    [[VungleHelper GetDelegate] performSelectorOnMainThread:@selector(Play:) withObject:curViewController waitUntilDone:NO];
}

bool FVungleModule::IsRewardedVideoReady()
{
    NSMutableDictionary *resultDictionary = [NSMutableDictionary dictionaryWithCapacity:1];
    [[VungleHelper GetDelegate] performSelectorOnMainThread:@selector(IsPlayable:) withObject:resultDictionary waitUntilDone:YES];
    
    NSNumber* number = (NSNumber*)[resultDictionary objectForKey:@"RetValue"];
    bool ret = (bool)[number boolValue];
	
    return ret;
}

static void IOS_VunglePlayComplete()
{
    FVungleModule* pModule = FModuleManager::Get().LoadModulePtr<FVungleModule>(TEXT("Vungle") );
    if (pModule == nullptr) return;
    
    
    FRewardedStatus status;
    status.AdType = EAdType::Vungle;
    
    pModule->TriggerPlayRewardCompleteDelegates(status);
}

#define LOCTEXT_NAMESPACE "FVungleModule"

void FVungleModule::StartupModule()
{
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    bool isEnable = false;
    
    GConfig->GetBool(TEXT("/Script/AdCollectionEditor.VungleSetting"), TEXT("bIOSEnabled"), isEnable, GEngineIni);
    if(isEnable)
    {
        FString appId;
        GConfig->GetString(TEXT("/Script/AdCollectionEditor.VungleSetting"), TEXT("IOSAppId"), appId, GEngineIni);
        
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [[VungleHelper GetDelegate] InitSDK:[NSString stringWithFString:appId] callback:&IOS_VunglePlayComplete];
        });
    }
}

void FVungleModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
    
}



#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FVungleModule, Vungle)
