#include "Draw.h"

#include "../../Classes/CMainMenuScreen_Tablet.h"
#include "../../Classes/CBloonsTD5Game.h"
#include "../../Classes/CTextObject.h"

namespace Patcher
{
    namespace Patches
    {
        namespace CMainMenuScreen_Tablet
        {
			Classes::CTextObject* brandingText;
			std::string brandText = "Patcher v0.1";

			uintptr_t Draw::funcOriginal = 0;
            void __fastcall cb_hook(Classes::CMainMenuScreen_Tablet* baseScreen) {
				if(!brandingText) {
					if(Utils::GetFontTexture() != nullptr) {
						brandingText = new Classes::CTextObject(brandText);
						std::cout << "Created text at " << brandingText << std::endl;
						brandingText->SetText(&brandText);
						brandingText->SetScale(1, 1);
						brandingText->SetXY(256, 0);
						brandingText->SetWH(100, 100);
						brandingText->SetTexture(Utils::GetFontTexture());
						
						std::cout << "Set text properties" << std::endl;
					}
				}
				else {
					std::cout << "Drawing..." << std::endl;
					brandingText->Draw(false);
					std::cout << "Drawn" << std::endl;
				}
               	PLH::FnCast(Draw::funcOriginal, cb_hook)(baseScreen);
            }

			Draw::Draw() : IPatch("CMainMenuScreen_Tablet::Draw") {
				this->AddSignature(new SigInfo(new std::string("56 8B F1 ?? BE ?? ?? ?? ?? ?? 74 ?? ?? BE ?? ?? ?? ?? ?? 74 ?? 8B"), 0)); //3.32 (21758)
			}

            auto Draw::Apply() -> bool
            {
				return this->AutoPatch(cb_hook, &funcOriginal);
            }
        }
    }
}