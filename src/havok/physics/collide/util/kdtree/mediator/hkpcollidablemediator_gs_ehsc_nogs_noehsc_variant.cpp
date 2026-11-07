#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkAabbUint32.h"


// src/havok/physics/collide/util/kdtree/mediator/hkpcollidablemediator_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/util/kdtree/mediator/hkpcollidablemediator.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/util/kdtree/mediator/hkpcollidablemediator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/util/kdtree/mediator/hkpcollidablemediator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Child { unsigned int unk00; unsigned int unk04; };
struct Owner { unsigned int unk00; unsigned int unk04; Child* child; unsigned int hkpCollidableMediator_getNumPrimitives(); };
// InitWalker: thiscall (2 stack args). Stores vptr, flag word and list, walks the item list when ctx != 0, returns this.
extern int DAT_010d40b4;
struct __declspec(align(16)) OutSlot {
    void* m_ptr;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
};
struct OutPlain { void* m_ptr; };
struct SubRec {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18(OutSlot* out);
    void hkpPhantom_setBoundingVolumeData(OutSlot* out);
};
struct ItemRec {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    signed char m_subOff;
    unsigned int unk14;
    unsigned char m_flag18;
    unsigned int unk1c;
    unsigned int m_20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int m_30;
};
struct ItemListRec {
    ItemRec** m_items;
    int m_uiItemCount;
};
struct CtxRec {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    void* m_78;
};
void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(void* mgr, OutSlot* out, int flag);
class ListWalker {
public:
    int m_vptr;
    unsigned short unk04;
    unsigned short m_06;
    ItemListRec* m_08;
    ListWalker* InitWalker(ItemListRec* list, CtxRec* ctx);
};
struct FUN_00d9e010_cls {
    unsigned int unk00;
    unsigned int unk04;
    Child* child;
    unsigned int hkpCollidableMediator_getPrimitiveId(unsigned int index);
};
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

#include <emmintrin.h>

extern const __m128 DAT_011b6d70;
extern const __m128 DAT_01267e30;

__forceinline hkAabb::hkAabb() {}

__declspec(noalias) void __cdecl FUN_00cf8690(hkAabbUint32* dst, const hkAabbUint32* src);

class ShapeQ
{
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void getAabb(const void* localToWorld, float tolerance, hkAabb& out) const;
};

struct BroadPhaseQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    __m128 m_kVectorAt40;
    __m128 m_kVectorAt50;
    __m128 m_vScale;
};

struct WorldQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    BroadPhaseQ* m_pJobSemaphore;
};

struct WorldObjectQ
{
    int unk00;
    int unk04;
    WorldQ* m_pOwningWorld;
};

struct CollidableQ
{
    ShapeQ* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const void* m_parent;
    signed char m_iOwnerOffset;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    int unk14;
    int unk18;
    int unk1c;
    hkAabbUint32 m_kBoundingVolumeData;

    WorldObjectQ* getOwner() const { return (WorldObjectQ*)((char*)this + m_iOwnerOffset); }
};

union hkVec4U
{
    __m128 m_vComponents;
    float m_f[4];
    __forceinline float operator()(int i) const { return m_f[i]; }
};

static __forceinline void convertToUint32WithClip(const __m128& in, const __m128& offset, const __m128& scale,
                                                  const __m128& maxVal, const __m128& minVal, unsigned int* out)
{
    hkVec4U x;
    x.m_vComponents = _mm_add_ps(in, offset);
    x.m_vComponents = _mm_mul_ps(x.m_vComponents, scale);
    x.m_vComponents = _mm_min_ps(x.m_vComponents, maxVal);
    x.m_vComponents = _mm_max_ps(x.m_vComponents, minVal);
    out[0] = fnv_FloatToInt(x(0));
    out[1] = fnv_FloatToInt(x(1));
    out[2] = fnv_FloatToInt(x(2));
    out[3] = fnv_FloatToInt(x(3));
}

// @fnv 0x00d9e020
// src: XBOX_PDB 0x00d9e020
void __stdcall hkpCollidableMediator_projectPrimitive(const CollidableQ* collidable, __m128i* out)
{
    hkAabbUint32 aabb32;
    const hkAabbUint32& bv = collidable->m_kBoundingVolumeData;
    if (bv.m_kMinimumCorner[0] <= bv.m_kMaximumCorner[0])
    {
        FUN_00cf8690(&aabb32, &collidable->m_kBoundingVolumeData);
    }
    else
    {
        hkAabb aabb;
        WorldQ* world = collidable->getOwner()->m_pOwningWorld;
        collidable->m_pCollisionShape->getAabb(collidable->m_pMotionState, 0.0f, aabb);
        BroadPhaseQ* bp = world->m_pJobSemaphore;
        __m128 maxVal = DAT_011b6d70;
        convertToUint32WithClip(aabb.m_kMinimumCorner.m_vComponents, bp->m_kVectorAt40, bp->m_vScale, maxVal, DAT_01267e30, aabb32.m_kMinimumCorner);
        convertToUint32WithClip(aabb.m_kMaximumCorner.m_vComponents, bp->m_kVectorAt50, bp->m_vScale, maxVal, DAT_01267e30, aabb32.m_kMaximumCorner);
        aabb32.m_ucExpansionShift = 0;
        aabb32.m_ucExpansionMin[0] = 0;
        aabb32.m_ucExpansionMin[1] = 0;
        aabb32.m_ucExpansionMin[2] = 0;
        aabb32.m_ucExpansionMax[0] = 0;
        aabb32.m_ucExpansionMax[1] = 0;
        aabb32.m_ucExpansionMax[2] = 0;
    }

    __m128i mi = _mm_load_si128((const __m128i*)aabb32.m_kMinimumCorner);
    __m128i ma = _mm_load_si128((const __m128i*)aabb32.m_kMaximumCorner);
    mi = _mm_slli_epi32(mi, 1);
    ma = _mm_adds_epu16(_mm_slli_epi32(ma, 1), _mm_set1_epi16(1));

    union { __m128i m_vComponents; unsigned short m_u16[8]; } r;
    r.m_u16[0] = mi.m128i_u16[1];
    r.m_u16[1] = mi.m128i_u16[3];
    r.m_u16[2] = mi.m128i_u16[5];
    r.m_u16[3] = mi.m128i_u16[7];
    r.m_u16[4] = ma.m128i_u16[1];
    r.m_u16[5] = ma.m128i_u16[3];
    r.m_u16[6] = ma.m128i_u16[5];
    r.m_u16[7] = ma.m128i_u16[7];
    *out = r.m_vComponents;
}
