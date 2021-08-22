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
				else if(!object->Texture) {
					object->Texture = fontTexture;
					std::cout << "Used cached font" << std::endl;
				}
                PLH::FnCast(Draw::funcOriginal, cb_hook)(object, drawChildren);
            }

			Draw::Draw() : IPatch("CTextObject::Draw")
			{
				this->AddSignature(new SigInfo(new std::string("55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F9 8B ?? ?? 83 EC ?? 8B"), 0));
			}

            auto Draw::Apply() -> bool
            {
                return this->AutoPatch(cb_hook, &funcOriginal);
            }
        } // namespace CTextObject
    }
}
