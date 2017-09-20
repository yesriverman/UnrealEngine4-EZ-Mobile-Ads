/*
* EZ-Mobile-Ads - unreal engine 4 ads plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com> All Rights Reserved.
*/

#include "Unity.h"

#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "Misc/ConfigCacheIni.h"
#include "Async/TaskGraphInterfaces.h"
#include "StringConv.h"

DEFINE_LOG_CATEGORY_STATIC(AdCollection, Log, All);


void FUnityModule::PlayRewardedVideo()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional = false;
		static jmethodID PlayRewardVideoMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Unity_PlayRewardedVideo", "()V", bIsOptional);

		if (PlayRewardVideoMethod == nullptr)
		{
			UE_LOG(AdCollection, Error, TEXT("AndroidThunkJava_Unity_PlayRewardedVideo not found"));
			return;
		}

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, PlayRewardVideoMethod);
	}
}


bool FUnityModule::IsRewardedVideoReady()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional = false;
		static jmethodID JniMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Unity_RewardedVideoReady", "()Z", bIsOptional);
		if (JniMethod == nullptr)
		{
			UE_LOG(AdCollection, Error, TEXT("AndroidThunkJava_Unity_RewardedVideoReady not found"));
			return false;
		}

		// Convert scope array into java fields
		return FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, JniMethod);
	}

	return false;
}


__attribute__((visibility("default"))) extern "C" void Java_com_ads_util_Unity_nativePlayRewardedComplete(JNIEnv* jenv, jobject thiz)
{
	FUnityModule* pModule = FModuleManager::Get().LoadModulePtr<FUnityModule>(TEXT("Unity"));
	if (pModule == nullptr)
	{
		return;
	}

	FRewardedStatus status;
	status.AdType = EAdType::Unity;

	UE_LOG(AdCollection, Log, TEXT("AndroidThunkJava_Unity Reward Callback"));
	pModule->TriggerPlayRewardCompleteDelegates(status);
}


void FUnityModule::StartupModule()
{
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    
}

void FUnityModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
    
}
