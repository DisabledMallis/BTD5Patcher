#ifndef PATCHER_UTILS
#define PATCHER_UTILS

#include <Windows.h>
#include <Psapi.h>
#include <tlhelp32.h>
#include <string>
#include <vector>
#include "Config.h"
#include "Classes/CBloonsTD5Game.h"

namespace Patcher
{
	class Utils {
		static Classes::CBloonsTD5Game* gameInstance;
	public:
		static auto GetModuleBase() -> int;
		static auto GetModuleBaseHandle() -> HMODULE;
		static auto GetBaseModuleSize() -> int;
		static auto GetBaseModuleEnd() -> int;
		static auto GetThisModule() -> HMODULE;
		static auto FindPattern(const char* pattern) -> void*;
		static auto FindPattern(int rangeStart, int rangeEnd, const char* pattern) -> void*;
		static auto GetTypeName(void* object) -> std::string;
		static void SetGameInstance(Classes::CBloonsTD5Game* gameInstance);
		static auto GetGameInstance() -> Classes::CBloonsTD5Game*;
	};
}
#endif /* PATCHER_UTILS */
