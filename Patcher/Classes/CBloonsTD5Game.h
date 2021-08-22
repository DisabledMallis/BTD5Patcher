#ifndef NKHOOK5_CLASSES_CBLOONSTD5GAME
#define NKHOOK5_CLASSES_CBLOONSTD5GAME

#include "IBasePointers.h"
#include "CFont.h"

namespace Patcher
{
	namespace Classes
	{
		class CBloonsTD5Game : public IBasePointers
		{
		public:
			char pad_0074[8]; //0x0070
			class CMemoryTracker *CMemoryTracker; //0x0078
			class CTimerTracker *CTimerTracker; //0x007C
			class CTimerTrackerGraph *CTimerTrackerGraph; //0x0080
			char pad_0084[192]; //0x0084
			class CAssetBag *CAssetBag; //0x0144
			char pad_0148[4]; //0x0148
			class CGameSystemPointers *CGameSystemPointers; //0x014C
			char pad_0150[4]; //0x0150
			class CFont* CFont; //0x0154
			class N00000D1A *N0000030B; //0x0158
			class CTextObject *CTextObject; //0x015C
			class CTextObject *N0000030D; //0x0160
			char pad_0164[212]; //0x0164
		};
	} // namespace Classes
	
} // namespace Patcher


#endif /* NKHOOK5_CLASSES_CBLOONSTD5GAME */
