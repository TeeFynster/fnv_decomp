
// src/gamebryo2.2/corelibs/nimain/niambientlight.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niambientlight.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/StrArr.h"

struct S00
{
    void _FUN_00a72010();
    void* DestroyIfFlagged(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// Calls _FUN_00a72010, then if flags has bit 1 set deletes this with size 0xF0, and returns this.
// @fnv 0x00a9b3a0
void* S00::DestroyIfFlagged(unsigned int flags)
{
    _FUN_00a72010();
    if (flags & 1)
        _delete(this, 0xF0);
    return this;
}

void __stdcall AppendEffectProperties(StrArr*);
char* __cdecl _FUN_00a7d330(void const*);
extern void const* const g_011f5f6c;
// Appends the string returned by _FUN_00a7d330(g_011f5f6c) to the StrArr, growing it via SetSize when the size reaches the max.
// @fnv 0x00a9b430
// src: XBOX_PDB 0x00a9b430
void __stdcall NiAmbientLight_GetViewerStrings(StrArr* pStrArr)
{
    AppendEffectProperties(pStrArr);
    char* pkString = _FUN_00a7d330(g_011f5f6c);
    unsigned int uiIndex = pStrArr->m_usSize;
    if (uiIndex >= pStrArr->m_usMaxSize)
    {
        pStrArr->SetSize(uiIndex + pStrArr->m_usGrowBy);
    }
    pStrArr->SetAt(uiIndex, pkString);
}

void __cdecl FUN_00a72080();

// @fnv 0x00a75c00
// src: XBOX_PDB 0x00a75c00
void __cdecl NiAmbientLight_LoadBinary()
{
    FUN_00a72080();
}

void NiLight_RegisterStreamables();

// @fnv 0x00a75c10
// src: XBOX_PDB 0x00a75c10
void NiAmbientLight_RegisterStreamables()
{
    NiLight_RegisterStreamables();
}

class CloningProcessA9B3;

class TESObjectDoorController
{
  public:
    static void* operator new(unsigned int n);
};

class FUN_00a71f60
{
  public:
    FUN_00a71f60() throw();
    virtual ~FUN_00a71f60() throw();
    char unk004[0x99];
    bool m_b9d;
    char unk09e[0x52];
};

class CloneA9B3 : public FUN_00a71f60
{
  public:
    CloneA9B3() throw()
    {
        m_b9d = false;
    }
    virtual ~CloneA9B3() throw();

    static void* operator new(unsigned int n)
    {
        return TESObjectDoorController::operator new(n);
    }

    void FUN_00a71ec0(CloneA9B3* dest, CloningProcessA9B3& cloning);
    CloneA9B3* NiAmbientLight_CreateClone(CloningProcessA9B3& cloning);
};

// Allocates a new CloneA9B3, calls FUN_00a71ec0 with the instance and cloning argument, then returns it.
// @fnv 0x00a9b3d0
// src: XBOX_PDB 0x00a9b3d0
CloneA9B3* CloneA9B3::NiAmbientLight_CreateClone(CloningProcessA9B3& cloning)
{
    CloneA9B3* p = new CloneA9B3;
    FUN_00a71ec0(p, cloning);
    return p;
}
