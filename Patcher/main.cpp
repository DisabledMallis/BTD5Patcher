#include <Windows.h>
#include <thread>
#include <string>
#include <iostream>
#include "Patches/Global/WinMain.h"
#include "Patches/PatchManager.h"
#include "Utils.h"

using namespace Patcher;

auto bootstrapPatcher() -> int {
	SetConsoleTitleA("Hooking main function...");
	Patches::PatchManager::ApplyPatch(new Patches::Global::WinMain());
	return 0;
}


extern "C" __declspec(dllexport) bool __stdcall DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved )  // reserved
{
    // Perform actions based on the reason for calling.
    switch( fdwReason ) 
    { 
        case DLL_PROCESS_ATTACH:
            std::thread(bootstrapPatcher).detach();
            break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}