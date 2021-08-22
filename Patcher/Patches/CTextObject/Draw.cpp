#include "Draw.h"

#include "../../Classes/CTextObject.h"

namespace Patcher
{
    namespace Patches
    {
        namespace CTextObject
        {
			Classes::CTexture* fontTexture;
			uintptr_t Draw::funcOriginal = 0;
            void __fastcall cb_hook(Classes::CTextObject* object, bool drawChildren) {
				if(fontTexture == 0) {
					fontTexture = object->Texture;
					std::cout << "Cached font texture at " << fontTexture << std::endl;
				}
				if(object->Texture == 0) {
					object->Texture = fontTexture;
					std::cout << "Used cached font" << std::endl;
				}
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
