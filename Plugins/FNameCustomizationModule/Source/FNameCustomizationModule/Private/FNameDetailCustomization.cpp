#include "FNameCustomizationModule.h"
#include "FNameDetailCustomization.h"

//Copypaste from RangeStructCustomization
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Engine/GameViewportClient.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Layout/SSpacer.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Input/SComboBox.h"
#include "DetailWidgetRow.h"
#include "Editor.h"
#include "PropertyHandle.h"
#include "DetailLayoutBuilder.h"
#include "Widgets/Input/SNumericEntryBox.h"
#include "SlateBasics.h"
#include "STextComboBox.h"
#include "AssertionMacros.h"
#include "FDropName.h"
#include "TestChar.h"



void FNameDetailCustomization::CustomizeHeader(TSharedRef<IPropertyHandle> inStructPropertyHandle, FDetailWidgetRow & HeaderRow, IPropertyTypeCustomizationUtils & StructCustomizationUtils)
{
	StructPropertyHandle = inStructPropertyHandle;
	TSharedPtr<IPropertyUtilities> Utils = StructCustomizationUtils.GetPropertyUtilities();

	// Initialising handles
	NameHandle = StructPropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FDropName, SelectedBone)).ToSharedRef();
	NameHandle->GetValue(key);
	BonesHandle = StructPropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FDropName, Bones)).ToSharedRef();

	TArray<UObject*> ss;
	StructPropertyHandle->GetOuterObjects(ss);
	for (auto s : ss) {
		ATestChar *n = Cast<ATestChar>(s);
		if (n) {
			n->SetCustomizationUtils(Utils);
		}
	}

	TSharedPtr<IPropertyHandleArray> arr(BonesHandle->AsArray());
	uint32 NumElms(0);
	arr->GetNumElements(NumElms);

	// Out.
	if (NumElms == 0) {
		NameHandle->SetValue("");
		return;
	}

	// DropDown selected option to display when refresh 
	uint8 selectedOpt(0);
	for (uint32 idx = 0; idx < NumElms; ++idx)
	{
		const TSharedPtr<IPropertyHandle> ChildHandle = arr->GetElement(idx);
		FString s("");
		ChildHandle->GetValueAsDisplayString(s);
		AvailableOptions.Add(MakeShareable<FString>(new FString(s)));
		if (key == *s) {
			selectedOpt = idx;
		}
	}

	NameHandle->SetValue(*AvailableOptions[selectedOpt]);
	
	HeaderRow
		.NameContent()
		[
			StructPropertyHandle->CreatePropertyNameWidget()
		]
	.ValueContent()
		.MinDesiredWidth(500)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.HAlign(HAlign_Left)
		[
			SAssignNew(KeyComboBox, STextComboBox)
			.OptionsSource(&AvailableOptions)
		.OnSelectionChanged(this, &FNameDetailCustomization::OnStateValueChanged)
		.InitiallySelectedItem(AvailableOptions[selectedOpt])
		]
		];
}

void FNameDetailCustomization::CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, IDetailChildrenBuilder & StructBuilder, IPropertyTypeCustomizationUtils & StructCustomizationUtils)
{
	//do nothing
}

void FNameDetailCustomization::OnStateValueChanged(TSharedPtr<FString> ItemSelected, ESelectInfo::Type SelectInfo)
{
	if (ItemSelected.IsValid())
	{
		// Fetches the byte index for this string from the settings class
		for (int32 i = 0; i < AvailableOptions.Num(); ++i)
		{
			if (AvailableOptions[i] == ItemSelected)
			{
				NameHandle->SetValue(*ItemSelected);
			}
		}
	}
}


