#ifndef PATCHER_PATCHES_GLOBAL_CALCSLEEPTIME
#define PATCHER_PATCHES_GLOBAL_CALCSLEEPTIME

#include "../IPatch.h"
#include "../../Utils.h"

namespace Patcher
{
    namespace Patches
    {
        namespace Global
        {
            class CalcSleepTime : public IPatch
            {
            public:
				static uintptr_t funcOriginal;
                CalcSleepTime();
                auto Apply() -> bool override;
            };
        } // namespace Global
        
    } // namespace Patches
    
} // namespace Patcher

#endif /* PATCHER_PATCHES_GLOBAL_CALCSLEEPTIME */
