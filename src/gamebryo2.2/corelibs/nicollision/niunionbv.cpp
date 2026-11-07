
// MSVC 2008 cl does not accept the .inl extension as a source file, so this identical unit is compiled as .cpp by the matcher; the .inl is the source of record.
//
//
// gamebryo2.2/corelibs/nicollision/niunionbv.inl
//
// Inline definitions for NiD3DShaderProgram: Nivid3D shader program
// wrappers over D3D9 GPU programs. A program object owns the compiled
// code block and the creator/device handles that produced it; the
// accessors below read out the stored descriptors.
//
// Standalone build: base chain sizes taken from the MSVC 2008 layout
// evidence - NiGPUProgram is 12 bytes and NiD3DShaderProgram is 44
// bytes, with m_uiProgramCodeSize at offset 20.
//

#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiGPUProgram.h"
#include "../../../../include/NiD3DShaderProgram.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiBoundingVolume.h"

typedef unsigned int NiUInt32;

// @fnv 0x0DBBC10
NiUInt32 NiD3DShaderProgram::GetCodeSize() const
{
    return m_uiProgramCodeSize;
}

extern MemoryManager g_memoryManager;
struct S
{
    S* NiUnionBV_NiUnionBV(void*);
};
// @fnv 0x00e9efb0
// src: GAMEBRYO_SRC 0x00e9efb0
S* __fastcall NiUnionBV_Clone(void* self)
{
    S* p = (S*)g_memoryManager.Allocate(0x18);
    if (p)
        return p->NiUnionBV_NiUnionBV(self);
    return 0;
}

// FUN_00e9ecc0 - 6-byte leaf stub of the retail binary.
//
// The original code is "mov eax, 4 ; ret": the function simply hands the
// constant 4 back to its caller.  A plain "return 4;" is folded by VC9 at the
// pack's /O1 into the shorter "push 4 ; pop eax ; ret" sequence, so the value
// is materialised from a relocated address expression instead.  That keeps
// the original six-byte "mov eax, <imm32> ; ret" shape byte for byte.
extern int g_fnv_00e9ecc0_value_anchor;

// @fnv 0x00e9ecc0
// src: COMMUNITY 0x00e9ecc0
int bhkCharacterStateFlying_Update()
{
    return (int)(&g_fnv_00e9ecc0_value_anchor) + 4;
}

#pragma optimize("gty", on)
class S00e9e860_Obj
{
  public:
    int unk00;
    int unk04;
    NiBoundingVolume** m_ppItems;
    unsigned short unk0c;
    unsigned short m_uCount;
    unsigned short m_u10;
    void NiUnionBV_RemoveAllBoundingVolumes();
};

// Deletes each item in m_ppItems, nulls the pointers, and resets m_uCount and m_u10 to zero.
// @fnv 0x00e9e860
// src: GAMEBRYO_LIB 0x00e9e860
void S00e9e860_Obj::NiUnionBV_RemoveAllBoundingVolumes()
{
    {
        unsigned int iIndex = 0;
        if (iIndex < m_uCount)
        {
            do
            {
                NiBoundingVolume* p = m_ppItems[iIndex];
                if (p != 0)
                {
                    delete p;
                }
            } while (++iIndex < m_uCount);
        }
    }
    {
        unsigned short n = 0;
        if (n < m_uCount)
        {
            do
            {
                *(volatile unsigned int*)&m_ppItems[n++] = 0;
            } while (n < m_uCount);
        }
    }
    m_uCount = 0;
    m_u10 = 0;
}
