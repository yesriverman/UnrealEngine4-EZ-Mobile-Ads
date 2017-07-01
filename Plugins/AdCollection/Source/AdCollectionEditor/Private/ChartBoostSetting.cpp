// Fill out your copyright notice in the Description page of Project Settings.

#include "AdCollectionEditor.h"
#include "ChartBoostSetting.h"




#if WITH_EDITOR
void UChartBoostSetting::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	SaveConfig(CPF_Config, *GetDefaultConfigFilename() );
}
#endif
