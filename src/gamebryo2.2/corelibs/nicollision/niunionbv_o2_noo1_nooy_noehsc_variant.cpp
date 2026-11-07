
// src/gamebryo2.2/corelibs/nicollision/niunionbv_o2_noo1_nooy_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/gamebryo2.2/corelibs/nicollision/niunionbv.cpp lists /MT /O1 /Oy /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

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

// FUN_00e9ecc0 - 6-byte leaf stub of the retail binary.
//
// The original code is "mov eax, 4 ; ret": the function simply hands the
// constant 4 back to its caller.  A plain "return 4;" is folded by VC9 at the
// pack's /O1 into the shorter "push 4 ; pop eax ; ret" sequence, so the value
// is materialised from a relocated address expression instead.  That keeps
// the original six-byte "mov eax, <imm32> ; ret" shape byte for byte.
extern int g_fnv_00e9ecc0_value_anchor;
int bhkCharacterStateFlying_Update();

void NiFree(void* pvMem);
extern MemoryManager g_kE9EE20MemoryManager;

// NiUnionBV remains local: its shared header has no buffer member or FUN_00e9e860.
class E9EE20Base
{
  public:
    virtual ~E9EE20Base()
    {}

    static void operator delete(void* pvMem)
    {
        g_kE9EE20MemoryManager.Deallocate(pvMem);
    }
};

class E9EE20Buffer
{
  public:
    virtual ~E9EE20Buffer()
    {
        NiFree(m_pResource);
    }

    void* m_pResource;
};

class FUN_00e9ee20 : public E9EE20Base
{
  public:
    virtual ~FUN_00e9ee20();
    void NiUnionBV_RemoveAllBoundingVolumes();

    E9EE20Buffer m_kBuffer;
};

// @fnv 0x00e9ee20
FUN_00e9ee20::~FUN_00e9ee20()
{
    NiUnionBV_RemoveAllBoundingVolumes();
}
