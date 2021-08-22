#include "PatchManager.h"
#include <iostream>

#include "CBasePositionableObject/Constructor.h"
#include "CBloonsTD5Game/Constructor.h"
#include "CTextObject/Draw.h"
#include "Global/CalcSleepTime.h"
#include "Win32/LoadStringWHook.h"
#include "WinRenderLayer/EndFrame.h"

using namespace Patcher::Patches;

void PatchManager::ApplyAll()
{
    PatchManager::ApplyPatch(new CBasePositionableObject::Constructor());
    PatchManager::ApplyPatch(new CBloonsTD5Game::Constructor());
	PatchManager::ApplyPatch(new CTextObject::Draw());
	PatchManager::ApplyPatch(new Global::CalcSleepTime());
	PatchManager::ApplyPatch(new Win32::LoadStringWHook());
	PatchManager::ApplyPatch(new WinRenderLayer::EndFrame());
}

void PatchManager::ApplyPatch(IPatch* toAdd)
{
    if(toAdd->Apply())
    {
        PatchManager::patches->push_back(toAdd);
        std::cout << "Successfully applied \'" << toAdd->GetName() << "\' patch!" << std::endl;
    }
    else
    {
        std::cout << "Failed to apply patch: " << toAdd->GetName() << std::endl;
    }
}