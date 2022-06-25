#pragma once

#define RUNTIME_VERSION 0x040020D0

#define JIP_AS_LIBRARY
#pragma warning(push)
#include "Internal/Prefix.h"
#include "Internal/JIP_Core.h"
#pragma warning(pop)

#define NVSEAPI __cdecl
#define DLLEXPORT __declspec(dllexport)

#include "Plugin.h"
#include <fmt/core.h>
#include <fmt/format.h>
