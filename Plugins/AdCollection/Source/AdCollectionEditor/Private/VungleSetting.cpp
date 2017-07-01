// Fill out your copyright notice in the Description page of Project Settings.

#include "AdCollectionEditor.h"
#include "VungleSetting.h"




#if WITH_EDITOR
void UVungleSetting::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	SaveConfig(CPF_Config, *GetDefaultConfigFilename() );
}
#endif
