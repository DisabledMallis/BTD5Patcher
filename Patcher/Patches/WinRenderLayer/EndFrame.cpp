#include "EndFrame.h"

#include "../../Classes/CTextObject.h"

namespace Patcher
{
    namespace Patches
    {
        namespace WinRenderLayer
        {
			uintptr_t EndFrame::funcOriginal = 0;
			Classes::CTextObject* brandingText;
			std::string brandText = "Patcher v0.1";
            void __fastcall cb_hook(void* winRenderLayer) {

				if(!brandingText) {
					brandingText = new Classes::CTextObject(brandText);
					std::cout << "Created text at " << brandingText << std::endl;
					brandingText->SetText(&brandText);
					brandingText->SetXY(0, 0);
					brandingText->SetWH(100, 100);
					std::cout << "Set text properties" << std::endl;
				}
				else {
					brandingText->Draw(false);
				}

               	PLH::FnCast(EndFrame::funcOriginal, cb_hook)(winRenderLayer);
            }

			EndFrame::EndFrame() : IPatch("WinRenderLayer::EndFrame") {
				this->AddSignature(new SigInfo(new std::string("E8 ?? ?? ?? ?? E8 ?? ?? ?? ?? FF ?? ?? ?? ?? ?? FF ?? ?? ?? ?? ?? E8"), 0)); //3.28 (21607)
			}

            auto EndFrame::Apply() -> bool {
				return this->AutoPatch(cb_hook, &funcOriginal);
            }
        }
    }
}