// © SSZ Canada Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FSSZCodeModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
