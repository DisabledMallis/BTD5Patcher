#ifndef NKHOOK5_PATCHES_CBLOONSTD5GAME_CONSTRUCTOR
#define NKHOOK5_PATCHES_CBLOONSTD5GAME_CONSTRUCTOR

#include "../IPatch.h"
#include "../../Utils.h"

namespace NKHook5
{
    namespace Patches
    {
        namespace CBloonsTD5Game
        {
            class Constructor : public IPatch
            {
            public:
                Constructor() : IPatch("CBloonsTD5Game::Constructor")
                {

                }
                auto Apply() -> bool override;
            };
        } // namespace CBloonsTD5Game
        
    } // namespace Patches
    
} // namespace NKHook5
#endif /* NKHOOK5_PATCHES_CBLOONSTD5GAME_CONSTRUCTOR */
