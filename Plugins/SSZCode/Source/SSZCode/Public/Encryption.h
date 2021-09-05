// © SSZ Canada Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/Core/Public/Misc/AES.h"
#include "Runtime/Core/Public/Misc/SecureHash.h"
#include "Runtime/Core/Public/Misc/Base64.h"
#include "Encryption.generated.h"

UCLASS()
class SSZCODE_API UEncryption : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:

	UFUNCTION(BlueprintCallable, Category = "SSZ|Encryption")
	static FString Encrypt(FString InputString, FString Key);

	UFUNCTION(BlueprintCallable, Category = "SSZ|Encryption")
	static FString Decrypt(FString InputString, FString Key);
};
