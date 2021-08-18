#ifndef PATCHER_PATCHES_CBLOONSTD5GAME_CONSTRUCTOR
#define PATCHER_PATCHES_CBLOONSTD5GAME_CONSTRUCTOR

#include "../IPatch.h"
#include "../../Utils.h"

namespace Patcher
{
    namespace Patches
    {
        namespace CBloonsTD5Game
        {
            class Constructor : public IPatch
            {
            public:
				static inline uintptr_t funcOriginal;
                Constructor();
                auto Apply() -> bool override;
            };
        } // namespace CBloonsTD5Game
        
    } // namespace Patches
    
} // namespace NKHook5
#endif /* PATCHER_PATCHES_CBLOONSTD5GAME_CONSTRUCTOR */
