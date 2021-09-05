// © SSZ Canada Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "HAL/PlatformFilemanager.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/DateTime.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "SSZFileFunctions.generated.h"


UCLASS()
class USSZFileFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

private:

	UFUNCTION(BlueprintCallable, Category = "SSZ|File I/O", meta = (Keywords = "save, string, file, ssz"))
	static void SaveStringToFile(FString SaveDirectory, FString FileName, FString StringToSave, bool AllowOverWriting, FString& Report, bool& Success);

	UFUNCTION(BlueprintCallable, Category = "SSZ|File I/O", meta = (Keywords = "load, string, file, ssz"))
	static void LoadStringFromFile(FString SaveDirectory, FString FileName, FString& Report, bool& Success, FString& StringInFile);

	UFUNCTION(BlueprintCallable, Category = "SSZ|File I/O", meta = (Keywords = "save, string, file, ssz"))
	static void SaveStringArrayToFile(FString SaveDirectory, FString FileName, TArray<FString> ArrayToSave, bool AllowOverWriting, FString& Report, bool& Success);

	UFUNCTION(BlueprintCallable, Category = "SSZ|File I/O", meta = (Keywords = "load, string, file, ssz"))
	static void LoadStringArrayFromFile(FString SaveDirectory, FString FileName, FString& Report, bool& Success, TArray<FString>& ArrayInFile);

	UFUNCTION(BlueprintCallable, Category = "SSZ|File I/O", meta = (Keywords = "copy, file, ssz"))
	static void CopyFile(FString CopyFrom, FString CopyTo);

	UFUNCTION(BlueprintCallable, Category = "SSZ|File I/O", meta = (Keywords = "delete, file, ssz"))
	static void DeleteFile(bool& Success, FString File);

	UFUNCTION(BlueprintCallable, Category = "SSZ|File I/O", meta = (Keywords = "move, file, ssz"))
	static void MoveFile(FString MoveFrom, FString MoveTo);

	UFUNCTION(BlueprintCallable, Category = "SSZ|File I/O", meta = (Keywords = "last, modified, time, file, ssz"))
	static FDateTime GetFileLastModified(const FString& File);

};