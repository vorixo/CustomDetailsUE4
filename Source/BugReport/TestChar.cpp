// Fill out your copyright notice in the Description page of Project Settings.

#include "TestChar.h"
#include "KismetEditorUtilities.h"


// Sets default values
ATestChar::ATestChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestChar::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATestChar::SetCustomizationUtils(TSharedPtr<IPropertyUtilities> inUtils)
{
	Utils = inUtils;
}

// Called every frame
void ATestChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATestChar::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if (PropertyChangedEvent.GetPropertyName() == "Mesh") {
		CustomProperty.Bones = GetMesh()->GetAllSocketNames();	
		if (Utils.Get()) {
			Utils.Get()->ForceRefresh();
		}
	}
}

