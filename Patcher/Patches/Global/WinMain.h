#ifndef PATCHER_PATCHES_GLOBAL_WINMAIN
#define PATCHER_PATCHES_GLOBAL_WINMAIN

#include "../IPatch.h"
#include "../../Utils.h"

namespace Patcher
{
    namespace Patches
    {
        namespace Global
        {
            class WinMain : public IPatch
            {
            public:
				static inline uintptr_t funcOriginal;
                WinMain();
                auto Apply() -> bool override;
            };
        } // namespace Global
        
    } // namespace Patches
    
} // namespace Patcher

#endif /* PATCHER_PATCHES_GLOBAL_WINMAIN */
