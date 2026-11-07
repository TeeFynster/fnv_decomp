
// src/gamebryo2.2/corelibs/nicollision/niunionbv_o2_noo1_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /Oy /GS /EHsc /Gy (unit src/gamebryo2.2/corelibs/nicollision/niunionbv.cpp lists /MT /O1 /Oy /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiGPUProgram.h"
#include "../../../../include/NiD3DShaderProgram.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiBoundingVolume.h"
#include "../../../../include/NiTexturingProperty.h"

extern MemoryManager g_memoryManager;
struct S
{
    S* NiUnionBV_NiUnionBV(void*);
};
S* __fastcall NiUnionBV_Clone(void* self);
// FUN_00e9ecc0 - 6-byte leaf stub of the retail binary.
//
// The original code is "mov eax, 4 ; ret": the function simply hands the
// constant 4 back to its caller.  A plain "return 4;" is folded by VC9 at the
// pack's /O1 into the shorter "push 4 ; pop eax ; ret" sequence, so the value
// is materialised from a relocated address expression instead.  That keeps
// the original six-byte "mov eax, <imm32> ; ret" shape byte for byte.
extern int g_fnv_00e9ecc0_value_anchor;
int bhkCharacterStateFlying_Update();

extern void* DAT_010f1778[];
extern void* DAT_010f17ac[];

struct SViewQ
{
    void** vtbl;
    NiTPrimitiveArray<NiBoundingVolume*> m_kArray;
};

// @fnv 0x00e9ee60
// src: XBOX_PDB 0x00e9ee60
S* S::NiUnionBV_NiUnionBV(void* pkOtherRaw)
{
    SViewQ* pkOther = (SViewQ*)pkOtherRaw;
    SViewQ* pkSelf = (SViewQ*)this;
    pkSelf->vtbl = DAT_010f1778;
    NiTPrimitiveArray<NiBoundingVolume*>* pkArray = &pkSelf->m_kArray;
    pkArray->m_usMaxSize = 0;
    pkArray->m_usGrowBy = 1;
    pkArray->m_usSize = 0;
    pkArray->m_usESize = 0;
    pkArray->m_pBase = 0;
    *(void***)pkArray = DAT_010f17ac;
    pkArray->SetSize(pkOther->m_kArray.m_usSize);
    for (unsigned int i = 0; i < pkOther->m_kArray.m_usSize; i++)
    {
        NiBoundingVolume* p = pkOther->m_kArray.m_pBase[i];
        if (p)
        {
            NiBoundingVolume* q = p->Clone();
            pkArray->SetAt(i, q);
        }
    }
    return this;
}
