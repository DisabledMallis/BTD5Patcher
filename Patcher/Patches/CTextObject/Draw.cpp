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
				this->AddSignature(new SigInfo(new std::string("68 e9 fb ?? ??"), 0));
			}

            auto Draw::Apply() -> bool
            {
                return this->AutoPatch(cb_hook, &funcOriginal);
            }
        } // namespace CTextObject
    }
}
