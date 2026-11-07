
// src/staging/blk_006e0000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/staging/blk_006e0000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_006e0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
struct S006e6ae0_Vector
{
    __m128 m_vComponents;
};

struct S006e6ae0_Point3
{
    float x, y, z;
};

const S006e6ae0_Vector* __cdecl NI2HK(S006e6ae0_Vector* pOut, const S006e6ae0_Point3* pPoint);

class S006e6ae0_Aabb
{
  public:
    S006e6ae0_Aabb();  // FUN_00437c10
    S006e6ae0_Vector m_kMinimumCorner;
    S006e6ae0_Vector m_kMaximumCorner;
};

class S006e6ae0_Shape
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual int vf60();
    virtual void vf64();
    virtual void vf68(const S006e6ae0_Aabb* pAabb, int iHandle);
};

class S006e6ae0_Body
{
  public:
    S006e6ae0_Shape* FUN_006286d0();
};

class S006e6ae0_World
{
  public:
    void FUN_005533c0();
    S006e6ae0_Body* FUN_00541c80();
};

class S006e6ae0_Owner2
{
  public:
    S006e6ae0_World* TESObjectCELL_GetbhkWorld();
};

class S006e6ae0_Owner1
{
  public:
    S006e6ae0_Owner2* FUN_006dd4f0();
};

class S006e6ae0_Node
{
  public:
    S006e6ae0_Owner1* GetOffsetC();
};

int __cdecl hkAllocateStack_char(int iValue, int iFlags);

class S006e6ae0_Object
{
  public:
    void PathingSearchRayCast_CreateCache();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    S006e6ae0_Node* m_pkNode;
    unsigned int unk58;
    S006e6ae0_Point3 m_kMin;
    S006e6ae0_Point3 m_kMax;
    unsigned int unk74;
    int m_iHandle;
};

// @fnv 0x006e6ae0
// src: COMMUNITY 0x006e6ae0
void S006e6ae0_Object::PathingSearchRayCast_CreateCache()
{
    S006e6ae0_Aabb kAabb;
    NI2HK(&kAabb.m_kMinimumCorner, &m_kMin);
    NI2HK(&kAabb.m_kMaximumCorner, &m_kMax);
    S006e6ae0_World* pkWorld = m_pkNode->GetOffsetC()->FUN_006dd4f0()->TESObjectCELL_GetbhkWorld();
    pkWorld->FUN_005533c0();
    S006e6ae0_Shape* pkShape = pkWorld->FUN_00541c80()->FUN_006286d0();
    int iValue = pkShape->vf60();
    m_iHandle = hkAllocateStack_char(iValue, 0);
    S006e6ae0_Shape* pkShape2 = pkWorld->FUN_00541c80()->FUN_006286d0();
    pkShape2->vf68(&kAabb, m_iHandle);
    pkWorld->FUN_005533c0();
}
