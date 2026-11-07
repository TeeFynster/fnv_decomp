
// src/staging/blk_00da0000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00da0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00da0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/FinishingFlag.h"

struct ScratchBlock
{
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
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
};

void __cdecl Object_InitializeDispatchFunctionTable(ScratchBlock* block);

class ScratchOwner
{
  public:
    void AddEntry(ScratchBlock* block, int a, int b);
};

// @fnv 0x00da7020
// src: HAVOK_LIB 0x00da7020
void __cdecl hkListAgent3_registerAgent3(ScratchOwner* owner)
{
    __declspec(align(16)) ScratchBlock s;
    s.unk30 = 0;
    s.unk31 = 0;
    s.unk32 = 0;
    s.unk18 = 0;
    s.unk1C = 0;
    s.unk20 = 0;
    s.unk24 = 0;
    s.unk28 = 0;
    Object_InitializeDispatchFunctionTable(&s);
    owner->AddEntry(&s, -1, 9);
}

struct S00da0780_Member
{
    S00da0780_Member(FinishingFlag flag);  // FUN_00cb0a70
    int m_iWordAt00;
};

class __declspec(align(16)) S00da0780_Object
{
  public:
    S00da0780_Object(FinishingFlag flag) : m_kMember(flag)
    {}
    virtual void vf00();
    int unk04;
    S00da0780_Member m_kMember;
    int unk0C;
};

// @fnv 0x00da0780
// src: HAVOK_LIB 0x00da0780
const void* __cdecl getVtablehkLocalFrameGroup()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00da0780_Object kObject(flag);
    return *reinterpret_cast<const void**>(&kObject);
}

namespace fnv_00da07d0 {
struct S00da07d0_Member
{
    S00da07d0_Member(FinishingFlag flag);  // FUN_00cb0a70
    int m_iWordAt00;
};

class __declspec(align(16)) S00da07d0_Object
{
  public:
    S00da07d0_Object(FinishingFlag flag) : m_kMember(flag)
    {}
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    S00da07d0_Member m_kMember;
    int unk68;
    int unk6C;
};

// @fnv 0x00da07d0
// src: HAVOK_LIB 0x00da07d0
const void* __cdecl getVtablehkSimpleLocalFrame()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00da07d0_Object kObject(flag);
    return *reinterpret_cast<const void**>(&kObject);
}
}  // namespace fnv_00da07d0

#include <xmmintrin.h>
__declspec(align(16)) struct FUN_00da7180_cls
{
    __m128 m_v00;
    __m128 m_v10;
    float m_f20;
    unsigned int m_i24;
    float m_f28;
    unsigned int m_i2C;
    unsigned int m_i30;

    FUN_00da7180_cls* AssignFields_00da7180(const FUN_00da7180_cls* src);
};

// @fnv 0x00da7180
// src: GUESS 0x00da7180 (confidence: low)
FUN_00da7180_cls* FUN_00da7180_cls::AssignFields_00da7180(const FUN_00da7180_cls* src)
{
    _mm_store_ps((float*)&m_v00, _mm_load_ps((const float*)&src->m_v00));
    _mm_store_ps((float*)&m_v10, _mm_load_ps((const float*)&src->m_v10));
    m_f20 = src->m_f20;
    m_i24 = src->m_i24;
    m_f28 = src->m_f28;
    m_i2C = src->m_i2C;
    m_i30 = src->m_i30;
    return this;
}

namespace fnv_00db7c40 {
struct S00db7c40_Member
{
    S00db7c40_Member(FinishingFlag flag);  // FUN_00cb0a70
    int m_iWordAt00;
};

class __declspec(align(16)) S00db7c40_Object
{
  public:
    S00db7c40_Object(FinishingFlag flag) : m_kMember(flag)
    {}
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    S00db7c40_Member m_kMember;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
};

// @fnv 0x00db7c40
// src: HAVOK_LIB 0x00db7c40
const void* __cdecl getVtablehkpPhysicsSystem()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00db7c40_Object kObject(flag);
    return *reinterpret_cast<const void**>(&kObject);
}
}  // namespace fnv_00db7c40
