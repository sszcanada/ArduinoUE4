// © SSZ Canada Inc. All Rights Reserved.


#include "Encryption.h"

FString UEncryption::Encrypt(FString InputString, FString Key)
{
	if (InputString.IsEmpty()) return "";
	if (Key.IsEmpty()) return "";

	FString S = "EL@$@!";
	InputString.Append(S);

	Key = FMD5::HashAnsiString(*Key);
	TCHAR* KeyTChar = Key.GetCharArray().GetData();
	ANSICHAR* KeyAnsi = (ANSICHAR*)TCHAR_TO_ANSI(KeyTChar);

	uint8* Blob;
	uint32 Z;

	Z = InputString.Len();
	Z = Z + (FAES::AESBlockSize - (Z % FAES::AESBlockSize));

	Blob = new uint8[Z];

	if (StringToBytes(InputString, Blob, Z)) {

		FAES::EncryptData(Blob, Z, KeyAnsi);
		InputString = FString::FromHexBlob(Blob, Z);

		delete Blob;
		return InputString;
	}

	delete Blob;
	return "";
}

FString UEncryption::Decrypt(FString InputString, FString Key)
{
	if (InputString.IsEmpty()) return "";
	if (Key.IsEmpty()) return "";

	FString S = "EL@$@!";

	Key = FMD5::HashAnsiString(*Key);
	TCHAR* KeyTChar = Key.GetCharArray().GetData();
	ANSICHAR* KeyAnsi = (ANSICHAR*)TCHAR_TO_ANSI(KeyTChar);

	uint8* B;
	uint32 Z;

	Z = InputString.Len();
	Z = Z + (FAES::AESBlockSize - (Z % FAES::AESBlockSize));

	B = new uint8[Z];

	if (FString::ToHexBlob(InputString, B, Z)) {

		FAES::DecryptData(B, Z, KeyAnsi);
		InputString = BytesToString(B, Z);

		FString L;
		FString R;
		InputString.Split(S, &L, &R, ESearchCase::CaseSensitive, ESearchDir::FromStart);
		InputString = L;

		delete B;
		return InputString;
	}

	delete B;
	return "";
}