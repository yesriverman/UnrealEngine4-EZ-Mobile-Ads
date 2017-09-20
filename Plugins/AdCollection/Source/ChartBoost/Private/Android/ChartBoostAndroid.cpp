/*
* EZ-Mobile-Ads - unreal engine 4 ads plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com> All Rights Reserved.
*/

#include "ChartBoost.h"

#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "Misc/ConfigCacheIni.h"
#include "Async/TaskGraphInterfaces.h"
#include "StringConv.h"

DEFINE_LOG_CATEGORY_STATIC(AdCollection, Log, All);


void FChartBoostModule::PlayRewardedVideo()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional = false;
		static jmethodID PlayRewardVideoMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ChartBoost_PlayRewardedVideo", "()V", bIsOptional);
		if (PlayRewardVideoMethod == nullptr)
		{
			UE_LOG(AdCollection, Error, TEXT("AndroidThunkJava_ChartBoost_PlayRewardedVideo not found"));
			return;
		}

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, PlayRewardVideoMethod);
	}
}

void FChartBoostModule::ShowInterstitialAd()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional = false;
		static jmethodID ShowInterstitialMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ChartBoost_ShowInterstitialAds", "()V", bIsOptional);

		if (ShowInterstitialMethod == nullptr)
		{
			UE_LOG(AdCollection, Error, TEXT("AndroidThunkJava_ChartBoost_ShowInterstitialAds not found"));
			return;
		}
		
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, ShowInterstitialMethod);
	}
}

bool FChartBoostModule::IsInterstitalReady()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional = false;
		static jmethodID JniMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ChartBoost_InterstitialReady", "()Z", bIsOptional);
		if (JniMethod == nullptr)
		{
			UE_LOG(AdCollection, Error, TEXT("AndroidThunkJava_ChartBoost_InterstitialReady not found"));
			return false;
		}

		// Convert scope array into java fields
		return FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, JniMethod);
	}

	return false;
}

bool FChartBoostModule::IsRewardedVideoReady()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional = false;
		static jmethodID JniMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ChartBoost_RewardedVideoReady", "()Z", bIsOptional);
		if (JniMethod == nullptr)
		{
			UE_LOG(AdCollection, Error, TEXT("AndroidThunkJava_ChartBoost_RewardedVideoReady not found"));
			return false;
		}

		// Convert scope array into java fields
		return FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, JniMethod);
	}

	return false;
}

__attribute__((visibility("default"))) extern "C" void Java_com_ads_util_ChartBoost_nativePlayRewardedComplete(JNIEnv* jenv, jobject thiz, jint amount)
{
	FChartBoostModule* pModule = FModuleManager::Get().LoadModulePtr<FChartBoostModule>(TEXT("ChartBoost"));
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
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    
}

void FChartBoostModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
    
}
