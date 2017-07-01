// Fill out your copyright notice in the Description page of Project Settings.

#include "AdCollectionEditor.h"
#include "UnitySetting.h"




#if WITH_EDITOR
void UUnitySetting::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
    SaveConfig(CPF_Config, *GetDefaultConfigFilename() );
}
#endif
