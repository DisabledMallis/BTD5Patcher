#include "WinMain.h"

#include "../PatchManager.h"
#include "../../Config.h"

namespace Patcher
{
    namespace Patches
    {
        namespace Global
        {
			DWORD outBuff; //Stuff to not crash virtual protect
			void unprotectMem(void* address, int size) {
				VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &outBuff);
			}

            int __stdcall cb_hook(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow) {
				SetConsoleTitleA("Loading...");
				//Hey we are in the game's process, lets do cool shit
				std::cout << "Loading Patcher..." << std::endl;
				std::cout << "BTD5 Patcher made by DisabledMallis" << std::endl;
				std::cout << "https://github.com/DisabledMallis/BTD5Patcher" << std::endl;

				//Overwrite crash message with custom one
				char* crashMessage = (char*)Utils::FindPattern("42 6c 6f 6f 6e 73 20 54 44 20 35 20 68"); //Find address of crash message
#define ERROR_MSG "Bloons TD 5 has crashed while Patcher was loaded. DO NOT REPORT THIS CRASH TO NINJA KIWI!! Ninja Kiwi's code DID NOT cause this crash!" //Macros for crash message data
#define ERROR_MSG_SIZE sizeof ERROR_MSG //Including the length for the copy
				unprotectMem(crashMessage, ERROR_MSG_SIZE);
				strcpy_s(crashMessage, ERROR_MSG_SIZE, ERROR_MSG);
				//Hey user, this isn't NK code, so if shit breaks don't blame them :D
				std::cout << "Don't ask Ninja Kiwi for support with this, please." << std::endl;

				//TODO: Config related things
				Config conf = Config::getConfig();
				std::cout << conf << std::endl;

				//Apply all hooks & patches
				std::cout << "Loading all patches..." << std::endl;
				PatchManager::ApplyAll();
				std::cout << "All patches loaded!" << std::endl;

				std::cout << "Loaded Patcher!" << std::endl;
				
				//Complete launch & load game
				std::cout << "Launching game..." << std::endl;
				SetConsoleTitleA("Bloons TD5 - Output");
				return PLH::FnCast(WinMain::funcOriginal, cb_hook)(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
            }

			WinMain::WinMain() : IPatch("Global::WinMain") {
				this->AddSignature(new SigInfo(new std::string("55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 81 EC ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? ?? 65 ?? 8B ?? ?? 8B"), 0));
			}

            auto WinMain::Apply() -> bool
            {
				return this->AutoPatch(cb_hook, &WinMain::funcOriginal);
            }
        }
    }
}