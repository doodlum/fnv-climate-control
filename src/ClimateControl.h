DEFINE_COMMAND_PLUGIN(GetOutgoingWeather, 0, 0, NULL);

bool Cmd_GetOutgoingWeather_Execute(COMMAND_ARGS);

class ClimateControl
{
public:
	static void InstallPatches()
	{
		Patches::Install();
	}

protected:
	struct Patches
	{
		static double __fastcall SunUpdate_GetYExtremeHook(void* _this, void* _edx)
		{
			double result = ((double(__thiscall*)(void*))0x00450410)(_this);
			return -result;
		}

		static void Install()
		{
			WriteRelJump(0x63AD5F, 0x63AD9D);  // Patch interior check so weathers always update
			WriteRelCall(0x00641830 + 0xA68, (UInt32)&SunUpdate_GetYExtremeHook); // Patch sun update to correct direction
		}
	};
};
