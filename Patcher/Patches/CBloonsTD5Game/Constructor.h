#ifndef NKHOOK5_PATCHES_CBLOONSTD5GAME_CONSTRUCTOR
#define NKHOOK5_PATCHES_CBLOONSTD5GAME_CONSTRUCTOR

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
				uintptr_t funcOriginal = 0;
            public:
                Constructor();
                auto Apply() -> bool override;
            };
        } // namespace CBloonsTD5Game
        
    } // namespace Patches
    
} // namespace NKHook5
#endif /* NKHOOK5_PATCHES_CBLOONSTD5GAME_CONSTRUCTOR */
