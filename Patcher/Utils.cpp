#include "Utils.h"

#define INRANGE(x,a,b)	(x >= a && x <= b) 
#define getBits( x )	(INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define getByte( x )	(getBits(x[0]) << 4 | getBits(x[1]))

auto Patcher::Utils::GetModuleBase() -> int
{
	return (int)GetModuleHandle(NULL);
}
auto Patcher::Utils::GetModuleBaseHandle() -> HMODULE
{
	return GetModuleHandle(NULL);
}
auto Patcher::Utils::GetBaseModuleSize() -> int
{
	MODULEINFO info;
	GetModuleInformation(GetCurrentProcess(), GetModuleBaseHandle(), &info, sizeof(info));
	return info.SizeOfImage;
}
auto Patcher::Utils::GetBaseModuleEnd() -> int
{
	return GetModuleBase() + GetBaseModuleSize();
}
auto Patcher::Utils::GetThisModule() -> HMODULE
{
	return GetModuleHandleA("Patcher.dll");
}

auto Patcher::Utils::FindPattern(const char* pattern) -> int
{
	return FindPattern(GetModuleBase(), GetBaseModuleEnd(), pattern);
}

auto Patcher::Utils::FindPattern(int rangeStart, int rangeEnd, const char* pattern) -> int
{
	const char* pat = pattern;
	DWORD firstMatch = 0;
	for (int pCur = rangeStart; pCur < rangeEnd; pCur++)
	{
		if (!*pat) return firstMatch;
		if (*(PBYTE)pat == '\?' || *(BYTE*)pCur == getByte(pat)) {
			if (!firstMatch) firstMatch = pCur;
			if (!pat[2]) return firstMatch;
			if (*(PWORD)pat == '\?\?' || *(PBYTE)pat != '\?') pat += 3;
			else pat += 2;	//one ?
		}
		else {
			pat = pattern;
			firstMatch = 0;
		}
	}
	return NULL;
}

auto Patcher::Utils::GetTypeName(void* object) -> std::string
{
	void* vtable = *(void**)object;
	void** metaPtr = (void**)((size_t)vtable-(size_t)sizeof(void*));
	void** typeDesc = (void**)((size_t)*metaPtr+(sizeof(void*)*3));
	char* name = (char*)((size_t)*typeDesc+(sizeof(void*)*3));
	return std::string(name);
}