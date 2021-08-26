#ifndef PATCHER_PATCHES_CBASESCREEN_DRAW
#define PATCHER_PATCHES_CBASESCREEN_DRAW

#include "../IPatch.h"
#include "../../Utils.h"

namespace Patcher
{
    namespace Patches
    {
        namespace CMainMenuScreen_Tablet
        {
            class Draw : public IPatch
            {
            public:
				static uintptr_t funcOriginal;
                Draw();
                auto Apply() -> bool override;
            };
        } // namespace CBloonsTD5Game
        
    } // namespace Patches
    
} // namespace Patcher


#endif /* PATCHER_PATCHES_CBASESCREEN_DRAW */
