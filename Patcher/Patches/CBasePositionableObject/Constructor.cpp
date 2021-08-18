#include "Constructor.h"

namespace Patcher
{
    namespace Patches
    {
        namespace CBasePositionableObject
        {
            uint64_t totalCreations = 0;
            void* __fastcall cb_hook(void* object) {
                totalCreations++;
                void* result = PLH::FnCast(Constructor::funcOriginal, &cb_hook)(object);
                return result;
            }

			Constructor::Constructor() : IPatch("CBasePositionableObject::Constructor")
			{
				this->AddSignature(new SigInfo(new std::string("56 57 8B F9 0F 57 ?? 8D"), 0));
			}

            auto Constructor::Apply() -> bool
            {
                return this->AutoPatch(cb_hook, &funcOriginal);
            }
        } // namespace CBasePositionableObject
    }
}
