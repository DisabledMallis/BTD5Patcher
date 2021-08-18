#include <Windows.h>
#include <string>
#include <iostream>
#include "Patches/PatchManager.h"

auto initialize() -> int {
    std::cout << "Loading Patcher..." << std::endl;

    std::cout << "Loading all patches..." << std::endl;
    Patcher::Patches::PatchManager::ApplyAll();
    std::cout << "All patches loaded!" << std::endl;

    std::cout << "Loaded Patcher!" << std::endl;

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
            initialize();
            break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}