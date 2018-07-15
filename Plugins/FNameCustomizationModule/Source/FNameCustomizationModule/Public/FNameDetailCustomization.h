#pragma once
#include "FNameCustomizationModule.h"

#include "IPropertyTypeCustomization.h"
#include "SCheckBox.h"
#include "SharedPointer.h"
#include "IPropertyUtilities.h"
#include "SSearchBox.h"
#include "STableRow.h"

class FNameDetailCustomization : public IPropertyTypeCustomization
{


public:
	/**
	* Creates a new instance.
	*
	* @return A new customization for FName.
	*/
	static TSharedRef<IPropertyTypeCustomization> MakeInstance()
	{
		return MakeShareable(new FNameDetailCustomization());
	}

public:
	// IPropertyTypeCustomization interface
	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder& StructBuilder, IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;

private:
	// Cached elements
	TSharedPtr<IPropertyHandle> StructPropertyHandle;


	TArray<TSharedPtr<FString>> AvailableOptions;
	TSharedPtr<STextComboBox> KeyComboBox;

	void OnStateValueChanged(TSharedPtr<FString> ItemSelected, ESelectInfo::Type SelectInfo);

	FName key;
	TArray<FString> BonesComp;
	TSharedPtr<IPropertyHandle> NameHandle;
	TSharedPtr<IPropertyHandle> BonesHandle;
};