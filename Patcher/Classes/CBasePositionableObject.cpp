#include "CBasePositionableObject.h"

#include <iostream>
#include "../../../Utils.h"

namespace Patcher
{
    namespace Classes
    {
		void* CBasePositionableObject_Constructor_Addr = 0;
		void CBasePositionableObject::Constructor(CBasePositionableObject* self) {
			if (CBasePositionableObject_Constructor_Addr == 0) {
				CBasePositionableObject_Constructor_Addr = (void*)Utils::FindPattern("56 57 8B F9 0F 57 ?? 8D");
				if (CBasePositionableObject_Constructor_Addr == 0) {
					std::cout << "CRITICAL ERROR: COULDN'T CONSTRUCT A CBPO!" << std::endl;
				}
			}
			void (__thiscall * CBasePositionableObject_Constructor_Func)(void*);
			memcpy(&CBasePositionableObject_Constructor_Func, &CBasePositionableObject_Constructor_Addr, 4);
			CBasePositionableObject_Constructor_Func(self);
		}
	}
}