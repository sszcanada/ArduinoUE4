// © SSZ Canada Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MathFunctions.generated.h"

/**
 * 
 */
UCLASS()
class USSZMathFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
private:

	UFUNCTION(BlueprintCallable, Category = "SSZ|Math|Single", meta = (Keywords = "+, add, float, int, calculate, ssz"))
	static void IntAddFloat(int32 Integer, float Add, float& Anwser);

	UFUNCTION(BlueprintCallable, Category = "SSZ|Math|Single", meta = (Keywords = "-, sub, float, int, calculate, ssz"))
	static void IntSubFloat(int32 Integer, float Minus, float& Anwser);

	UFUNCTION(BlueprintCallable, Category = "SSZ|Math|Single", meta = (Keywords = "*, multiply, float, int, calculate, ssz"))
	static void IntMultiplyFloat(int32 Integer, float MultiplyBy, float& Anwser);

	UFUNCTION(BlueprintCallable, Category = "SSZ|Math|Single", meta = (Keywords = "/, divide, float, int, calculate, ssz"))
	static void IntDivideFloat(int32 Integer, float DivideBy, float& Anwser);

	UFUNCTION(BlueprintCallable, Category = "SSZ|Math|Array", meta = (Keywords = "+, add, array, int, calculate, ssz"))
	static void AddArrayOfInteger(int32 StartNumber, TArray<int32> NumbersToAdd, int32& Anwser);

	UFUNCTION(BlueprintCallable, Category = "SSZ|Math|Array", meta = (Keywords = "-, sub, array, int, calculate, ssz"))
	static void SubtractArrayOfInteger(int32 StartNumber, TArray<int32> NumbersToSubtract, int32& Anwser);

	UFUNCTION(BlueprintCallable, Category = "SSZ|Math|Array", meta = (Keywords = "+, add, array, float, calculate, ssz"))
	static void AddArrayOfFloats(float StartNumber, TArray<float> NumberToAdd, float& Anwser);

	UFUNCTION(BlueprintCallable, Category = "SSZ|Math|Array", meta = (Keywords = "-, sub, array, float, calculate, ssz"))
	static void SubtractArrayOfFloats(float StartNumber, TArray<float> NumberToSubtract, float& Anwser);
	
};
