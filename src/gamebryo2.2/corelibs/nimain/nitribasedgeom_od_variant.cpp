// src/gamebryo2.2/corelibs/nimain/nitribasedgeom_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nitribasedgeom.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "nitribasedgeom_decls.h"
#pragma optimize("", off)
#pragma optimize("", on)
#pragma optimize("", off)

struct S_0051d080
{
    void NiBillboardNode_SetFlags(bool, unsigned short);
};
// @fnv 0x0051d080
// src: COMMUNITY 0x0051d080
void S_0051d080::NiBillboardNode_SetFlags(bool a1, unsigned short a2)
{
    if (a1)
        *(unsigned short*)((char*)this + 0xAC) |= a2;
    else
        *(unsigned short*)((char*)this + 0xAC) &= ~a2;
}

struct SpawnedBase
{
    SpawnedBase();
    virtual ~SpawnedBase();
    unsigned int unk04;
};

struct SpawnedElem
{
    SpawnedElem();
    ~SpawnedElem();
    unsigned int m_00;
    unsigned int m_04;
};

class FUN_0051d0d0 : public SpawnedBase
{
  public:
    SpawnedElem m_08[6];
    FUN_0051d0d0();
    virtual ~FUN_0051d0d0();
};

// @fnv 0x0051d0d0
FUN_0051d0d0::FUN_0051d0d0()
{}
