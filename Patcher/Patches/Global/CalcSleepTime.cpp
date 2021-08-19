#include "CalcSleepTime.h"

#define NO_FPS_LIMIT

namespace Patcher
{
    namespace Patches
    {
        namespace Global
        {
            int __cdecl cb_hook() {
                int sleepTime = PLH::FnCast(CalcSleepTime::funcOriginal, &cb_hook)();
                std::cout << "Current sleep time: " << sleepTime << std::endl;
				#ifdef NO_FPS_LIMIT
                std::cout << "Overridden sleep time" << std::endl;
				return 1;
				#else
				return sleepTime;
				#endif
            }

			CalcSleepTime::CalcSleepTime() : IPatch("Global::CalcSleepTime") {
				this->AddSignature(new SigInfo(new std::string("b9 01 00 00 00 f2 0f 10 2d ?? ?? ?? ?? eb 1c b9 04"), 0));
			}

            auto CalcSleepTime::Apply() -> bool
            {
				return this->AutoPatch(cb_hook, &CalcSleepTime::funcOriginal);
            }
        }
    }
}