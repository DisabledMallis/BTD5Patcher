#ifndef PATCHER_CLASSES_CTEXTOBJECT
#define PATCHER_CLASSES_CTEXTOBJECT

#include <string>
#include "CRenderableTextureObject.h"
#include "CFont.h"
#include "CTexture.h"
#include "../Utils.h"

namespace Patcher
{
    namespace Classes
    {
        class CTextObject : public CRenderableTextureObject
		{
		public:
			std::string text;
			class CFont *Font; //0x00E0
			char pad_00E4[24]; //0x00E4
			float pointZeroFour; //0x00FC
			char pad_0100[8]; //0x0100
			float onef_2; //0x0108
			float onef_3; //0x010C
			int zerozerozeroeighty; //0x0110
			float onef_4; //0x0114
			float onef_5; //0x0118
			float onef_6; //0x011C
			float onef_7; //0x0120
			char pad_0124[8]; //0x0124
			int eightI; //0x012C
			char pad_0130[4]; //0x0130
			bool dunno; //0x0134
			bool Invisible; //0x0135
			char pad_0136[2]; //0x0136
			int onei; //0x0138
			char pad_013C[28]; //0x013C

			virtual void Function52() {};
			virtual void Function53() {};
			virtual void Function54() {};
			virtual void Function55() {};
			virtual void Function56() {};
			virtual void SetText(std::string* text) {};
			virtual void Function58() {};
			virtual void Function59() {};
			virtual void Function60() {};

		public:
			//You have to set the text *after* construction
			CTextObject(std::string text) : CRenderableTextureObject() {
				Constructor(this);

				this->SetText(&text);
				this->Font = Utils::GetGameInstance()->CFont;
				this->Texture = Utils::GetFontTexture();
			}
			void Constructor(CTextObject* self);
		}; //Size: 0x0154
        
    } // namespace Classes
    
} // namespace Patcher

#endif /* PATCHER_CLASSES_CTEXTOBJECT */
