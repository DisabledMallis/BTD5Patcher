#include "Draw.h"

#include "../../Classes/CTextObject.h"

namespace Patcher
{
    namespace Patches
    {
        namespace CTextObject
        {
			uintptr_t Draw::funcOriginal = 0;
            void __fastcall cb_hook(Classes::CTextObject* object, bool drawChildren) {
				Utils::SetFontTexture(object->Texture);
                PLH::FnCast(Draw::funcOriginal, cb_hook)(object, drawChildren);
            }

			Draw::Draw() : IPatch("CTextObject::Draw")
			{
				this->AddSignature(new SigInfo(new std::string("55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B D9 ?? 5D ?? ?? BB ?? ?? ?? ?? ?? 0F ?? ?? ?? ?? ?? 8B ?? 6A"), 0));
			}

            auto Draw::Apply() -> bool
            {
                return this->AutoPatch(cb_hook, &funcOriginal);
            }
        } // namespace CTextObject
    }
}
