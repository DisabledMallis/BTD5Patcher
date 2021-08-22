#include "CRenderableTextureObject.h"

#include "../../../Utils.h"
#include <iostream>

namespace Patcher
{
    namespace Classes
    {
        void* CRenderableTextureObject_Constructor_Addr = 0;
		void CRenderableTextureObject::Constructor(CRenderableTextureObject* self) {
			if (CRenderableTextureObject_Constructor_Addr == 0) {
				CRenderableTextureObject_Constructor_Addr = (void*)Utils::FindPattern("56 8B F1 E8 ?? ?? ?? ?? A0");
				if (CRenderableTextureObject_Constructor_Addr == 0) {
					std::cout << "CRITICAL ERROR: COULDN'T CONSTRUCT A CRTO!" << std::endl;
				}
			}
			void (__thiscall * CRenderableTextureObject_Constructor_Func)(void*);
			memcpy(&CRenderableTextureObject_Constructor_Func, &CRenderableTextureObject_Constructor_Addr, 4);
			CRenderableTextureObject_Constructor_Func(self);
		}
    } // namespace Classes
} // namespace Patcher
