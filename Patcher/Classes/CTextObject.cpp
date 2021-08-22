#include "CTextObject.h"

#include "../../../Utils.h"
#include <iostream>

namespace Patcher
{
    namespace Classes
    {
        void* CTextObject_Constructor_Addr = 0;
		void CTextObject::Constructor(CTextObject* self) {
			if (CTextObject_Constructor_Addr == 0) {
				CTextObject_Constructor_Addr = (void*)Utils::FindPattern("55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 51 56 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 ?? 75 ?? E8 ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? 8D");
				if (CTextObject_Constructor_Addr == 0) {
					std::cout << "CRITICAL ERROR: COULDN'T CONSTRUCT A CTO!" << std::endl;
				}
			}
			void (__thiscall * CTextObject_Constructor_Func)(void*);
			memcpy(&CTextObject_Constructor_Func, &CTextObject_Constructor_Addr, 4);
			CTextObject_Constructor_Func(self);
		}
    } // namespace Classes
} // namespace Patcher