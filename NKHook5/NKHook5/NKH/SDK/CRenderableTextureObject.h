#pragma once
#include "CBasePositionableObject.h"
// Created with ReClass.NET 1.2 by KN4CK3R

class CRenderableTextureObject : public CBasePositionableObject
{
public:
	int CRenderableTextureObject_Start; //0x00A8
	char pad_00AC[20]; //0x00AC
	class CTexture* Texture; //0x00C0
	char pad_00C4[4]; //0x00C4

	CRenderableTextureObject() : CBasePositionableObject() {
		Constructor(this);
		//int vTableAddr = Utils::getModuleBase() + 0x72F188; // "BTD5-Win.exe"+72F188
		//memcpy(this, &vTableAddr, 4);
	}
	void Constructor(CRenderableTextureObject* self);
}; //Size: 0x00C8