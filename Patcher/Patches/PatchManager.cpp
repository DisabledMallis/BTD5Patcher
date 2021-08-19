#include "PatchManager.h"
#include <iostream>

#include "CBloonsTD5Game/Constructor.h"
#include "CBasePositionableObject/Constructor.h"
#include "Global/CalcSleepTime.h"

using namespace Patcher::Patches;

void PatchManager::ApplyAll()
{
    PatchManager::ApplyPatch(new CBloonsTD5Game::Constructor());
    PatchManager::ApplyPatch(new CBasePositionableObject::Constructor());
	PatchManager::ApplyPatch(new Global::CalcSleepTime());
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