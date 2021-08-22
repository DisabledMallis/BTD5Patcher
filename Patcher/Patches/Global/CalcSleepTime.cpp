#include "CalcSleepTime.h"

namespace Patcher
{
    namespace Patches
    {
        namespace Global
        {
			uintptr_t CalcSleepTime::funcOriginal = 0;
			bool remove_cap = false;
            int __cdecl cb_hook() {
				//If the fps cap should be removed
				if(remove_cap) {
                	return 1;
				}
				return PLH::FnCast(CalcSleepTime::funcOriginal, &cb_hook)();
            }

			CalcSleepTime::CalcSleepTime() : IPatch("Global::CalcSleepTime") {
				//Read config file val
				Config conf = Config::getConfig();
				remove_cap = conf.at("remove_fps_cap").get<bool>();

				//Sigs for de func
				this->AddSignature(new SigInfo(new std::string("b9 01 00 00 00 f2 0f 10 2d ?? ?? ?? ?? eb 1c b9 04"), 0));
			}

            auto CalcSleepTime::Apply() -> bool
            {
				return this->AutoPatch(cb_hook, &CalcSleepTime::funcOriginal);
            }
        }
    }
}