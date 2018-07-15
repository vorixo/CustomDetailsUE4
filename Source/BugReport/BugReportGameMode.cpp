// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "BugReportGameMode.h"
#include "BugReportPawn.h"

ABugReportGameMode::ABugReportGameMode()
{
	// set default pawn class to our flying pawn
	DefaultPawnClass = ABugReportPawn::StaticClass();
}
