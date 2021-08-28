#ifndef PATCHER_CLASSES_CBASEPOSITIONABLEOBJECT
#define PATCHER_CLASSES_CBASEPOSITIONABLEOBJECT

#include "CMatrix.h"
#include "Color.h"
#include "Vector.h"

namespace Patcher
{
    namespace Classes
    {
        class CBasePositionableObject
		{
		public:
			char pad_0004[8]; //0x0004
			int onei; //0x000C
			class CBasePositionableObject *parentObject; //0x0010
			void *selfPlus14; //0x0014
			void *selfPlus14_2; //0x0018
			char pad_001C[4]; //0x001C
			float Width; //0x0020
			float Height; //0x0024
			class CMatrix CMatrix; //0x0028
			float PosX; //0x0068
			float PosY; //0x006C
			float PosZ; //0x0070
			float onef; //0x0074
			char pad_0078[24]; //0x0078
			float AlignmentX; //0x0090
			float AlignmentY; //0x0094
			char pad_0098[4]; //0x0098
			float Angle; //0x009C
			float ScaleX; //0x00A0
			float ScaleY; //0x00A4
			char pad_00A8[4]; //0x00A8

			virtual void Function0() {};
			virtual void Draw(bool drawChildren) {};
			virtual void DrawOverlay() {};
			virtual void Process_r() {};
			virtual void Function4() {};
			virtual void DeleteChildren() {};
			virtual void SetXYZ(float x, float y, float z) {};
			virtual void SetXY(float x, float y) {};
			virtual void SetXYB(float x, float y) {};
			virtual void SetX(float x) {};
			virtual void SetY(float y) {};
			virtual void SetZ(float z) {};
			virtual void MoveXYZ(float x, float y, float z) {};
			virtual void MoveXY(float x, float y) {};
			virtual void MoveX(float x) {};
			virtual void MoveY(float y) {};
			virtual void MoveZ(float z) {};
			virtual void SetScale(float x, float y) {};
			virtual void SetScaleB(float x, float y) {};
			virtual void SetScaleX(float x) {};
			virtual void SetScaleY(float y) {};
			virtual void SetAngle(float angle) {};
			virtual void SetWH(float width, float height) {};
			virtual void SetW(float width) {};
			virtual void SetH(float height) {};
			virtual void SetAlignmentX(float x) {};
			virtual void SetAlignmentY(float y) {};
			virtual void SetAlignmentXY(float x, float y) {};
			virtual void GetXYZ(Vector3<float>* xyz) {};
			virtual void GetXY(Vector2<float>* xy) {};
			virtual void GetX(float* x) {};
			virtual void GetY(float* y) {};
			virtual void GetZ(float* z) {};
			virtual void GetWH(Vector2<float>* wh) {};
			virtual void GetW(float* w) {};
			virtual void GetH(float* h) {};
			virtual void Function36() {};
			virtual void Function37() {};
			virtual void Function38() {};
			virtual void Function39() {};
			virtual void SetScreenTransition() {};
			virtual void SetDefaultDirtyState() {};
			virtual void Function42() {};
			virtual void BaseDrawChildren() {};

		public:
			CBasePositionableObject() {
				Constructor(this);
			}
			void Constructor(CBasePositionableObject* self);
		}; //Size 0xA8
    } // namespace Classes
} // namespace NKHook5
#endif /* PATCHER_CLASSES_CBASEPOSITIONABLEOBJECT */
