#ifndef PATCHER_PATCHES_IPATCH
#define PATCHER_PATCHES_IPATCH

#include "../Utils.h"

#include <string>
#include <polyhook2/Detour/x86Detour.hpp>
#include <polyhook2/CapstoneDisassembler.hpp>

struct SigInfo {
    std::string* signature;
    int offset;

    SigInfo(std::string* signature, int offset) {
        this->signature = signature;
        this->offset = offset;
    };
    ~SigInfo() {
        delete signature;
    }
};

namespace Patcher
{
    namespace Patches
    {
        class IPatch
        {
            //The main disasembler
			static inline PLH::CapstoneDisassembler* dis = new PLH::CapstoneDisassembler(PLH::Mode::x64);

			//Patch metadata
			std::string name;
			std::vector<SigInfo*>* signatures;

			//PLH
			PLH::x86Detour* detourHook;
        public:
            IPatch(std::string name);
			virtual ~IPatch();
			//Not using AutoPatch? You'll have to clean up
			//your mess alone! Here's a func to let IPatch know
			//you've got it alone.
			virtual auto ManualCleanup() -> bool;
			//When adding sigs, the first added have priority.
			//Order matters, older version sigs might work on new versions
			//but result in the wrong func or bad memory
			void AddSignature(SigInfo* sigInfo);
			//Scans all sigs in the order
			auto ScanSigs() -> uintptr_t;
			//The patches name
			auto GetName() -> std::string;
			//Returns the polyhook disassembler. You might not need this.
			auto GetDis() -> PLH::CapstoneDisassembler;
			//Actually apply the hook
			virtual auto Apply() -> bool;
			//Use polyhook to hook the function
			auto AutoPatch(void* callback, uintptr_t* original) -> bool;
        };
    } // namespace Patches
    
} // namespace NKHook5

#endif /* PATCHER_PATCHES_IPATCH */
