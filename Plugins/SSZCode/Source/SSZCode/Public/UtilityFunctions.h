// © SSZ Canada Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Curves/RichCurve.h"
#include "EdGraph/EdGraphPin.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "UtilityFunctions.generated.h"

UCLASS()
class USSZUtilityFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "SSZ|Utilities|Curves", meta = (Keywords = "curve, quick, ssz"))
	static void QuickCurveSingle(float StartTime, float StartValue, float EndTime, float EndValue, float TimeToEval, float& Value);

	UFUNCTION(BlueprintCallable, Category = "SSZ|Utilities|Curves", meta = (Keywords = "curve, multi, quick, ssz"))
	static void QuickCurveSingleMultiPoint(TArray<float> Times, TArray<float> Values, float TimeToEval, FString& Report, float& Value);
};
