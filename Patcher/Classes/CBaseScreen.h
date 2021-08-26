#ifndef PATCHER_CLASSES_CBASESCREEN
#define PATCHER_CLASSES_CBASESCREEN

#include <vector>
#include <string>

namespace Patcher {
	namespace Classes {
		class CBaseScreen
		{
		public:
			char pad_0004[108]; //0x0004
			int BaseScreenStart; //0x0070
			char pad_0074[8]; //0x0074
			std::vector<CBaseScreen*> children;
			std::string screenName;
			class CBaseScreen* parent; //0x00A4
			
			virtual void Function0();
			virtual void Function1();
			virtual void init(CBaseScreen* screen, int param_1);
			virtual void Function3();
			virtual void Function4();
			virtual void Function5();
			virtual void Function6();
			virtual void Function7();
			virtual void Function8();
			virtual void Function9();
			virtual void Function10();
			virtual void Function11();
			virtual void Function12();
			virtual void Function13();
			virtual void Function14();
			virtual void Function15();
			virtual void Function16();
			virtual void Function17();
			virtual void draw();
		}; //Size: 0x0250
	};
};

#endif /* PATCHER_CLASSES_CBASESCREEN */
