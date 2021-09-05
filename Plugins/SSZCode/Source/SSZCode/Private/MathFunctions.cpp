// © SSZ Canada Inc. All Rights Reserved.

#include "MathFunctions.h"

void USSZMathFunctions::IntAddFloat(int32 Integer, float Add, float& Anwser)
{
	float Convert = FMath::RoundToInt(Integer);
	Anwser = (Integer + Add);
}

void USSZMathFunctions::IntSubFloat(int32 Integer, float Minus, float& Anwser)
{
	float Convert = FMath::RoundToInt(Integer);
	Anwser = (Integer - Minus);
}

void USSZMathFunctions::IntMultiplyFloat(int32 Integer, float MultiplyBy, float& Anwser)
{
	float Convert = FMath::RoundToInt(Integer);
	Anwser = (Integer * MultiplyBy);
}

void USSZMathFunctions::IntDivideFloat(int32 Integer, float DivideBy, float& Anwser)
{
	float Convert = FMath::RoundToInt(Integer);
	Anwser = (Integer / DivideBy);
}

void USSZMathFunctions::AddArrayOfInteger(int32 StartNumber, TArray<int32> NumbersToAdd, int32& Anwser)
{
	Anwser = StartNumber;
	for (uint8 i = 0; i < NumbersToAdd.Num(); ++i)
	{
		Anwser = (Anwser + NumbersToAdd[i]);
	}
}

void USSZMathFunctions::SubtractArrayOfInteger(int32 StartNumber, TArray<int32> NumbersToSubtract, int32& Anwser)
{
	Anwser = StartNumber;
	for (uint8 i = 0; i < NumbersToSubtract.Num(); ++i)
	{
		Anwser = (Anwser - NumbersToSubtract[i]);
	}
}

void USSZMathFunctions::AddArrayOfFloats(float StartNumber, TArray<float> NumberToAdd, float& Anwser)
{
	Anwser = StartNumber;
	for (uint8 i = 0; i < NumberToAdd.Num(); ++i)
	{
		Anwser = (Anwser + NumberToAdd[i]);
	}
}

void USSZMathFunctions::SubtractArrayOfFloats(float StartNumber, TArray<float> NumberToSubtract, float& Anwser)
{
	Anwser = StartNumber;
	for (uint8 i = 0; i < NumberToSubtract.Num(); ++i)
	{
		Anwser = (Anwser - NumberToSubtract[i]);
	}
}
