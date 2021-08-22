#ifndef PATCHER_PATCHES_WINRENDERLAYER_ENDFRAME
#define PATCHER_PATCHES_WINRENDERLAYER_ENDFRAME
#include "../IPatch.h"
#include "../../Utils.h"

namespace Patcher
{
    namespace Patches
    {
        namespace WinRenderLayer
        {
            class EndFrame : public IPatch
            {
            public:
				static uintptr_t funcOriginal;
                EndFrame();
                auto Apply() -> bool override;
            };
        } // namespace CBloonsTD5Game
        
    } // namespace Patches
    
} // namespace Patcher


#endif /* PATCHER_PATCHES_WINRENDERLAYER_ENDFRAME */
