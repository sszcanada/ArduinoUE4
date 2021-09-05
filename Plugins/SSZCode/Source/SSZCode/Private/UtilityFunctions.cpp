// © SSZ Canada Inc. All Rights Reserved.


#include "UtilityFunctions.h"

void USSZUtilityFunctions::QuickCurveSingle(float StartTime, float StartValue, float EndTime, float EndValue, float TimeToEval, float& Value)
{
	FRichCurve QuickCurve;
	QuickCurve.AddKey(StartTime, StartValue);
	QuickCurve.AddKey(EndTime, EndValue);
	Value = QuickCurve.Eval(TimeToEval);
	QuickCurve.Reset();
}

void USSZUtilityFunctions::QuickCurveSingleMultiPoint(TArray<float> Times, TArray<float> Values, float TimeToEval, FString& Report, float& Value)
{
	FRichCurve QuickCurve;
	for (int i = 0; i < Times.Num(); i++)
	{
		QuickCurve.AddKey(Times[i], Values[i]);
	}
	Value = QuickCurve.Eval(TimeToEval);
	QuickCurve.Reset();
	Report = FString::Printf(TEXT("%i Points added to the curve and the Value is %i at the time of %i"), Times.Num(), Value, TimeToEval);
}

