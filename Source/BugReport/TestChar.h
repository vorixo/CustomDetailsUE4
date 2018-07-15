// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FDropName.h"
#include "FNameDetailCustomization.h"
#include "TestChar.generated.h"

UCLASS()
class BUGREPORT_API ATestChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATestChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	TSharedPtr<IPropertyUtilities> Utils;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SocketSelection)
	FDropName CustomProperty;
	
	void SetCustomizationUtils(TSharedPtr<IPropertyUtilities> inUtils);
};
