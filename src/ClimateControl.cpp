#include "ClimateControl.h"

bool Cmd_GetOutgoingWeather_Execute(COMMAND_ARGS)
{
	*result = 0;
	TESWeather* weather = TES::GetSingleton()->sky ? TES::GetSingleton()->sky->transWeather : NULL;
	if (weather) {
		REFR_RES = weather->refID;
		if (IsConsoleOpen())
			Console_Print(fmt::format(FMT_STRING("GetOutgoingWeather >> {:X} \"{}\""), weather->refID, weather->GetEditorID()).data());
	}
	return true;
}
