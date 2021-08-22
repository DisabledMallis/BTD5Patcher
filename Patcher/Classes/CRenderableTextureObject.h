#ifndef PATCHER_CLASSES_CRENDERABLETEXTUREOBJECT
#define PATCHER_CLASSES_CRENDERABLETEXTUREOBJECT

#include "CBasePositionableObject.h"

namespace Patcher
{
    namespace Classes
    {
        class CRenderableTextureObject : public CBasePositionableObject
		{
		public:
			int CRenderableTextureObject_Start; //0x00A8
			char pad_00AC[20]; //0x00AC
			class CTexture* Texture; //0x00C0
			char pad_00C4[4]; //0x00C4

			CRenderableTextureObject() : CBasePositionableObject() {
				Constructor(this);
			}
			void Constructor(CRenderableTextureObject* self);
		}; //Size: 0x00C8
    } // namespace Classes
} // namespace Patcher

#endif /* PATCHER_CLASSES_CRENDERABLETEXTUREOBJECT */
