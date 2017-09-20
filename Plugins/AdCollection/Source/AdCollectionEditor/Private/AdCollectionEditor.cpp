/*
* EZ-Mobile-Ads - unreal engine 4 ads plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com> All Rights Reserved.
*/

#include "AdCollectionEditor.h"

#include "SlateBasics.h"
#include "SlateExtras.h"
#include "PropertyEditorModule.h"
#include "VungleSetting.h"
#include "AdMobSetting.h"
#include "UnitySetting.h"
#include "ChartBoostSetting.h"
#include "ISettingsModule.h"

#include "LevelEditor.h"

static const FName AdCollectionEditorTabName("AdCollectionEditor");

#define LOCTEXT_NAMESPACE "FAdCollectionEditorModule"

void FAdCollectionEditorModule::StartupModule()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		
		SettingsModule->RegisterSettings(TEXT("Project"), TEXT("AdCollection"), TEXT("Vungle"),
			LOCTEXT("Vungle", "Vungle"),
			LOCTEXT("Vungle", "Settings for Vungle"),
			GetMutableDefault<UVungleSetting>()
		);
        
        

		SettingsModule->RegisterSettings(TEXT("Project"), TEXT("AdCollection"), TEXT("AdMob"),
			LOCTEXT("AdMob", "AdMob"),
			LOCTEXT("AdMob", "Settings for AdMob"),
			GetMutableDefault<UAdMobSetting>()
		);

		SettingsModule->RegisterSettings(TEXT("Project"), TEXT("AdCollection"), TEXT("Unity"),
			LOCTEXT("Unity", "Unity"),
			LOCTEXT("Unity", "Settings for Unity"),
			GetMutableDefault<UUnitySetting>()
		);


		SettingsModule->RegisterSettings(TEXT("Project"), TEXT("AdCollection"), TEXT("ChartBoost"),
			LOCTEXT("ChartBoost", "ChartBoost"),
			LOCTEXT("ChartBoost", "Settings for ChartBoost"),
			GetMutableDefault<UChartBoostSetting>()
		);
		
	}
}

void FAdCollectionEditorModule::ShutdownModule()
{
}



#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAdCollectionEditorModule, AdCollectionEditor)
