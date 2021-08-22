#ifndef PATCHER_PATCHES_CTEXTOBJECT_DRAW
#define PATCHER_PATCHES_CTEXTOBJECT_DRAW

#include "../IPatch.h"
#include "../../Utils.h"

namespace Patcher
{
    namespace Patches
    {
        namespace CTextObject
        {
            class Draw : public IPatch
            {
            public:
				static uintptr_t funcOriginal;
                Draw();
                auto Apply() -> bool override;
            };
        } // namespace CTextObject
        
    } // namespace Patches
    
} // namespace NKHook5
#endif /* PATCHER_PATCHES_CTEXTOBJECT_DRAW */
