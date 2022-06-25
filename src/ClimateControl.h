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
		static void Install()
		{
			WriteRelJump(0x63AD5F, 0x63AD9D);  // Patch interior check so weathers always update
		}
	};
};
