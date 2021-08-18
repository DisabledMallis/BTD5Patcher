#ifndef NKHOOK5_PATCHES_CBASEPOSITIONABLEOBJECT_CONSTRUCTOR
#define NKHOOK5_PATCHES_CBASEPOSITIONABLEOBJECT_CONSTRUCTOR

#include "../IPatch.h"
#include "../../Utils.h"

namespace Patcher
{
    namespace Patches
    {
        namespace CBasePositionableObject
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
#endif /* NKHOOK5_PATCHES_CBASEPOSITIONABLEOBJECT_CONSTRUCTOR */
