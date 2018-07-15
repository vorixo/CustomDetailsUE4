// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FNameCustomizationModule.h"

#define LOCTEXT_NAMESPACE "FFNameCustomizationModuleModule"

void FFNameCustomizationModuleModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.RegisterCustomPropertyTypeLayout("DropName", FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FNameDetailCustomization::MakeInstance));
}

void FFNameCustomizationModuleModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.UnregisterCustomPropertyTypeLayout("DropName");
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFNameCustomizationModuleModule, FNameCustomizationModule)