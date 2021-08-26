#include "EndFrame.h"

#include "../../Classes/CTextObject.h"

namespace Patcher
{
    namespace Patches
    {
        namespace WinRenderLayer
        {
			uintptr_t EndFrame::funcOriginal = 0;
            void __fastcall cb_hook(void* winRenderLayer) {
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