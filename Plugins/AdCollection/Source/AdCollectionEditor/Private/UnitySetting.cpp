/*
* EZ-Mobile-Ads - unreal engine 4 ads plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com> All Rights Reserved.
*/


#include "AdCollectionEditor.h"
#include "UnitySetting.h"




#if WITH_EDITOR
void UUnitySetting::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
    SaveConfig(CPF_Config, *GetDefaultConfigFilename() );
}
#endif
