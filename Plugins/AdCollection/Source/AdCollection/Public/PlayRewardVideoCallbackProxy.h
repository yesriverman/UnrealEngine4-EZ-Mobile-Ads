/*
* EZ-Mobile-Ads - unreal engine 4 ads plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com> All Rights Reserved.
*/

#pragma once

#include "AdCollectionBPLibrary.h"
#include "AdCollection.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "PlayRewardVideoCallbackProxy.generated.h"

/**
 * Async play rewarded video action, when play finished success, the OnSuccess will be called.
 */
UCLASS(MinimalAPI)
class  UPlayRewardVideoCallbackProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UPlayRewardVideoCallbackProxy();

	/**
	* Called when the Rewarded video ads complete
	*/
	UPROPERTY(BlueprintAssignable)
	FPlayRewardedDelegate OnSuccess;

	/**
	* play rewarded video ads
	* @param	AdType		the type of the ads
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PlayRewardedVideo", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AdCollection")
	static UPlayRewardVideoCallbackProxy* PlayRewardedVideo(EAdType AdType);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;

	/**
	* find ads module by type
	* @param	AdType		the type of the ads
	*/
	static IAdModuleInterface* FindAdsModule(EAdType adType);

	/**
	* ad network type the ads belong
	*/
	EAdType AdType;
	
private:

	FPlayRewardCompleteDelegate Delegate;
	FDelegateHandle DelegateHandle;

	void OnComplete(FRewardedStatus Status);
};
