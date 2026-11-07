
// NiRTTI: the Gamebryo runtime type descriptor.
#include "layout_support.h"
#include "../../../../include/NiRTTI.h"

FNV_STATIC_ASSERT(sizeof(NiRTTI) == 0x8);

// @fnv 0x00a7b610
NiRTTI::NiRTTI(const char* pcName, const NiRTTI* pkBaseRTTI)
{
    m_pcName = pcName;
    m_pBaseRTTI = pkBaseRTTI;
}

void __fastcall Construct(void*);
extern int DAT_010c4314;
extern int DAT_01267b60;

// Calls Construct on pThis, installs the DAT_010c4314 vtable, zeroes field at offset 16, increments DAT_01267b60 and sets a ushort at offset 12 to 0x41.
// @fnv 0x00c6b910
// src: GUESS 0x00c6b910 (confidence: low)
void* __fastcall NiRTTI_UpdateState_00c6b910(void* apObject)
{
    Construct(apObject);
    *(int**)apObject = &DAT_010c4314;
    *((int*)apObject + 4) = 0;
    ++DAT_01267b60;
    *((unsigned short*)apObject + 6) = 0x41;
    return apObject;
}
