// gamebryo2.2/corelibs/nianimation/nikeyframemanager.cpp: NiGeomMorpherController (1 function)

#include "../../../../include/NiGeomMorpherController.h"

// NiMorphData's shared declaration does not yet expose its target-count getter.
unsigned int __fastcall GetMorphTargetCount(NiMorphData* pkMorphData);

// @fnv 0x008d3ed0
unsigned int NiGeomMorpherController::GetNumTargets() const
{
    return m_spMorphTargetData.operator->()
               ? GetMorphTargetCount(m_spMorphTargetData.operator->())
               : 0;
}
