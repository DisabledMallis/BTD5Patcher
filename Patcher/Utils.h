#ifndef PATCHER_UTILS
#define PATCHER_UTILS

#include <Windows.h>
#include <Psapi.h>
#include <tlhelp32.h>
#include <string>

namespace Patcher
{
	class Utils {
	public:
		static auto GetModuleBase() -> int;
		static auto GetModuleBaseHandle() -> HMODULE;
		static auto GetBaseModuleSize() -> int;
		static auto GetBaseModuleEnd() -> int;
		static auto GetThisModule() -> HMODULE;
		static auto FindPattern(const char* pattern) -> int;
		static auto FindPattern(int rangeStart, int rangeEnd, const char* pattern) -> int;
		static auto GetTypeName(void* object) -> std::string;
	};
}
#endif /* PATCHER_UTILS */