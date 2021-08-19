#include "Constructor.h"

namespace Patcher
{
    namespace Patches
    {
        namespace CBloonsTD5Game
        {
            void* __stdcall cb_hook(void* gameInstance) {
                std::cout << "Gameinstance created: " << gameInstance << std::endl;
                return PLH::FnCast(Constructor::funcOriginal, cb_hook)(gameInstance);
            }

			Constructor::Constructor() : IPatch("CBloonsTD5Game::Constructor") {
				this->AddSignature(new SigInfo(new std::string("55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 53 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 ?? 75 ?? E8 ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? ?? 86"), 0)); //3.32 (21758)
				this->AddSignature(new SigInfo(new std::string("55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 51 56 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 ?? 75 ?? E8 ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86"), 0)); //3.28 (21607)
			}

            auto Constructor::Apply() -> bool
            {
				return this->AutoPatch(cb_hook, &funcOriginal);
            }
        }
    }
}