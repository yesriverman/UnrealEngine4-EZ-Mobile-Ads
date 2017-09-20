/*
* EZ-Mobile-Ads - unreal engine 4 ads plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com> All Rights Reserved.
*/

#include "Vungle.h"

void FVungleModule::PlayRewardedVideo()
{
}

bool FVungleModule::IsRewardedVideoReady()
{
	return false;
}

#define LOCTEXT_NAMESPACE "FVungleModule"

void FVungleModule::StartupModule()
{
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    
}

void FVungleModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
    
}



#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FVungleModule, Vungle)
