#include "CalcSleepTime.h"

namespace Patcher
{
    namespace Patches
    {
        namespace Global
        {
			bool limitFps = false;
			uintptr_t CalcSleepTime::funcOriginal = 0;
            int __cdecl cb_hook() {
				if(limitFps) {
					return PLH::FnCast(CalcSleepTime::funcOriginal, &cb_hook)();
				}
                return 1;
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