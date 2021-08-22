#include <Windows.h>
#include <thread>
#include <string>
#include <iostream>
#include "Patches/Global/WinMain.h"
#include "Patches/PatchManager.h"
#include "Utils.h"
#include "Config.h"

using namespace Patcher;

auto bootstrapPatcher() -> int {
	Config conf = Config::getConfig();
	//If the user doesn't want us patching, we shouldn't bootstrap & patch the game.
	if(!conf.at("patch").get<bool>()) {
		std::cout << "Patcher injection cancelled because the config value \"patch\" was set to false." << std::endl;
		SetConsoleTitleA("The bootstapper was cancelled. You may close this window.");
		FreeConsole();
		FreeLibraryAndExitThread(Utils::GetThisModule(), 0);
		return 0;
	}
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