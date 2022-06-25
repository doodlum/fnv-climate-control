#include "Patches.h"
#include "ClimateControl.h"

namespace Patches
{
	void Patches::Install()
	{
		ClimateControl::InstallPatches();
		PrintLog("Installed all patches");
	}
}
