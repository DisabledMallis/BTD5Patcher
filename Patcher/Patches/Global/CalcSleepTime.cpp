#include "CalcSleepTime.h"

namespace Patcher
{
    namespace Patches
    {
        namespace Global
        {
            int __stdcall cb_hook() {
                int sleepTime = PLH::FnCast(CalcSleepTime::funcOriginal, &cb_hook)();
                std::cout << "Current sleep time: " << sleepTime << std::endl;
				return sleepTime;
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