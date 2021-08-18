#include "IPatch.h"

using namespace Patcher::Patches;

IPatch::IPatch(std::string name)
{
    this->name = name;
	this->signatures = new std::vector<SigInfo*>();
}
IPatch::~IPatch() {
	if(this->ManualCleanup()) {
		return;
	}
	// Clear signatures
	for(auto* elem : *this->signatures) {
		delete elem;
	}
	this->signatures->clear();
	delete this->signatures;

	//Clear hook & unhook
	detourHook->unHook();
	delete detourHook;
}
auto IPatch::ManualCleanup() -> bool {
	return false;
}

void IPatch::AddSignature(SigInfo* sigInfo)
{
	this->signatures->push_back(sigInfo);
}
auto IPatch::ScanSigs() -> uintptr_t {
	uintptr_t reqAddr = 0;
	int sigIndex = 0;
	while(reqAddr == 0) {
		if(sigIndex >= this->signatures->size()) {
			std::cout << "Failed to find signature for Patch \"" << name << "\"!";
			//Remember to handle this!
			return 0;
		};

		SigInfo* info = signatures->at(sigIndex);
		std::string* sig = info->signature;
		int offset = info->offset;

		reqAddr = Utils::FindPattern(sig->c_str());
		//We need to do this, because adding the offset might cause it to not be 0.
		//This is bad because it will break the loop and have a bad memory address returned, resulting in a crash.
		if(reqAddr != 0) {
			reqAddr += offset;
		}
		sigIndex++;
	};

	return reqAddr;
}
auto IPatch::GetName() -> std::string
{
    return this->name;
}
auto IPatch::GetDis() -> PLH::CapstoneDisassembler
{
    return PLH::CapstoneDisassembler(PLH::Mode::x86);
}
auto IPatch::Apply() -> bool
{
    return false;
}
auto IPatch::AutoPatch(void* callbackPtr, uintptr_t* funcOriginal) -> bool {
	PLH::CapstoneDisassembler dis = this->GetDis();

	uintptr_t hookAddr = this->ScanSigs();

	if(hookAddr == 0) {
		return false;
	}

	detourHook = new PLH::x86Detour((char*)hookAddr, (char*)callbackPtr, (uint64_t*)funcOriginal, dis);

	if(!detourHook->hook()) {
		return false;
	}

	return true;
}