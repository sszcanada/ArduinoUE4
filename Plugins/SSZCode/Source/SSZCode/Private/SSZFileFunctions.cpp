// © SSZ Canada Inc. All Rights Reserved.

#include "SSZFileFunctions.h"
#include "SSZCode.h"

USSZFileFunctions::USSZFileFunctions(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void USSZFileFunctions::SaveStringToFile(FString SaveDirectory, FString FileName, FString StringToSave, bool AllowOverWriting, FString& Report, bool& Success)
{

	SaveDirectory += "\\";
	SaveDirectory += FileName;

	if (!AllowOverWriting)
	{
		if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory))
		{
			Success = false;
			Report = FString::Printf(TEXT("ERROR File Can Not Be Overwritten"));
			return;
		}
	}

	Success = FFileHelper::SaveStringToFile(StringToSave, *SaveDirectory);
	int64 FileSizeOnDisk = FPlatformFileManager::Get().GetPlatformFile().FileSize(*SaveDirectory);

	if (FileSizeOnDisk > 1000000)
	{
		int64 MBSize = (FileSizeOnDisk / 1000000);
		Report = FString::Printf(TEXT("SUCCESS Saved File that is %i MB"), MBSize);
	}
	else
	{
		Report = FString::Printf(TEXT("SUCCESS Saved File that is %i Bytes"), FileSizeOnDisk);
	}
}

void USSZFileFunctions::LoadStringFromFile(FString SaveDirectory, FString FileName, FString& Report, bool& Success, FString& StringInFile)
{

	SaveDirectory += "\\";
	SaveDirectory += FileName;

	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory))
	{
		StringInFile = FString::Printf(TEXT("ERROR File Can Not Be Found"));
		Report = FString::Printf(TEXT("ERROR File Can Not Be Found"));
		Success = false;
		return;
	}

	int64 FileSizeOnDisk = FPlatformFileManager::Get().GetPlatformFile().FileSize(*SaveDirectory);

	if (FileSizeOnDisk > 1000000)
	{
		int64 MBSize = (FileSizeOnDisk / 1000000);
		Report = FString::Printf(TEXT("SUCCESS Loaded File that is %i MB"), MBSize);
	}
	else
	{
		Report = FString::Printf(TEXT("SUCCESS Loaded File that is %i Bytes"), FileSizeOnDisk);
	}
	FFileHelper::LoadFileToString(StringInFile, *SaveDirectory);
	Success = true;


}

void USSZFileFunctions::SaveStringArrayToFile(FString SaveDirectory, FString FileName, TArray<FString> ArrayToSave, bool AllowOverWriting, FString& Report, bool& Success)
{
	SaveDirectory += "\\";
	SaveDirectory += FileName;

	if (!AllowOverWriting)
	{
		if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory))
		{
			Success = false;
			Report = FString::Printf(TEXT("ERROR File Can Not Be Overwritten"));
			return;
		}
	}

	Success = FFileHelper::SaveStringArrayToFile(ArrayToSave, *SaveDirectory);

	int64 FileSizeOnDisk = FPlatformFileManager::Get().GetPlatformFile().FileSize(*SaveDirectory);

	if (FileSizeOnDisk > 1000000)
	{
		int64 MBSize = (FileSizeOnDisk / 1000000);
		Report = FString::Printf(TEXT("SUCCESS Saved File that is %i MB"), MBSize);
	}
	else
	{
		Report = FString::Printf(TEXT("SUCCESS Saved File that is %i Bytes"), FileSizeOnDisk);
	}
}

void USSZFileFunctions::LoadStringArrayFromFile(FString SaveDirectory, FString FileName, FString& Report, bool& Success, TArray<FString>& ArrayInFile)
{
	SaveDirectory += "\\";
	SaveDirectory += FileName;

	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory))
	{
		TArray<FString> FileData;
		ArrayInFile = FileData;
		Report = FString::Printf(TEXT("ERROR File Can Not Be Found"));
		Success = false;
		return;
	}

	int64 FileSizeOnDisk = FPlatformFileManager::Get().GetPlatformFile().FileSize(*SaveDirectory);
	
	if (FileSizeOnDisk > 1000000)
	{
		int64 MBSize = (FileSizeOnDisk / 1000000);
		Report = FString::Printf(TEXT("SUCCESS Loaded File that is %i MB"), MBSize);
	}
	else
	{
		Report = FString::Printf(TEXT("SUCCESS Loaded File that is %i Bytes"), FileSizeOnDisk);
	}

	TArray<FString> FileData;
	FFileHelper::LoadFileToStringArray(FileData, *SaveDirectory);
	ArrayInFile = FileData;
	Success = true;
}

void USSZFileFunctions::CopyFile(FString CopyFrom, FString CopyTo)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	PlatformFile.CopyFile(*CopyTo, *CopyFrom);

}

void USSZFileFunctions::DeleteFile(bool& Success, FString File)
{
	FString Path = File;
	if (!FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*Path))
	{
		Success = false;
	} 
	else
	{
		Success = true;
	}
}

void USSZFileFunctions::MoveFile(FString MoveFrom, FString MoveTo)
{
	CopyFile(MoveFrom, MoveTo);
	bool t = true;
	DeleteFile(t, MoveFrom);
}

FDateTime USSZFileFunctions::GetFileLastModified(const FString& File)
{
	int hold1 = FPlatformFileManager::Get().GetPlatformFile().GetTimeStamp(*File).ToUnixTimestamp();
	return FDateTime::FromUnixTimestamp(hold1);
}