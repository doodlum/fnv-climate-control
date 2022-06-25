#include "ClimateControl.h"
#include "Patches.h"
#include <NVSE/PluginAPI.h>

void Init(const NVSEInterface* nvse)
{
	bool (*RegisterCommand)(CommandInfo * info) = nvse->RegisterCommand;
	bool (*RegisterTypedCommand)(CommandInfo * info, CommandReturnType retnType) = nvse->RegisterTypedCommand;
	nvse->SetOpcodeBase(0x3DEF);
	REG_CMD_FRM(GetOutgoingWeather);

	if (!nvse->isEditor)
		Patches::Install();
}

extern "C" DLLEXPORT bool NVSEAPI NVSEPlugin_Load(const NVSEInterface* nvse)
{
#ifndef NDEBUG
	while (!IsDebuggerPresent()) {};
#endif
	s_log().Create(fmt::format("{}.log", Plugin::NAME).data());
	PrintLog("Loaded plugin");

	Init(nvse);

	return true;
}

extern "C" DLLEXPORT bool NVSEAPI NVSEPlugin_Query(const NVSEInterface* nvse, PluginInfo* info)
{
	info->infoVersion = PluginInfo::kInfoVersion;
	info->name = Plugin::NAME;
	return true;
}
