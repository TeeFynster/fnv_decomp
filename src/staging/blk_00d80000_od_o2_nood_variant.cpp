
// src/staging/blk_00d80000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00d80000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d80000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include "../../include/hkVector4.h"
#include "../../include/hkTransform.h"
#include "../../include/hkContactPoint.h"
#include "../../include/hkpSimpleContactConstraintAtom.h"


inline float& hkVector4::operator()(int i)
{
    return m_f[i];
}

inline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}

__forceinline hkContactPoint& hkContactPoint::operator=(const hkContactPoint& other)
{
    m_vContactPosition = other.m_vContactPosition;
    m_vSeparatingNormal = other.m_vSeparatingNormal;
    return *this;
}

struct BaseD85
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
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    BaseD85& Assign(const BaseD85& o);
};
struct ObjD85 : BaseD85
{
    short unk90;
    char unk92;
    short unk94;
    short unk96;
    __m128 unka0;
    __m128 unkb0;
    __m128 unkc0;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    ObjD85& ProcessAndReturnValue_00d85ba0(const ObjD85& o);
};

// @fnv 0x00d85ba0
// src: GUESS 0x00d85ba0 (confidence: low)
ObjD85& ObjD85::ProcessAndReturnValue_00d85ba0(const ObjD85& o)
{
    Assign(o);
    unk90 = o.unk90;
    unk92 = o.unk92;
    unk94 = o.unk94;
    unk96 = o.unk96;
    unka0 = o.unka0;
    unkb0 = o.unkb0;
    unkc0 = o.unkc0;
    unkd0 = o.unkd0;
    unkd4 = o.unkd4;
    unkd8 = o.unkd8;
    unke0 = o.unke0;
    unke4 = o.unke4;
    unke8 = o.unke8;
    unkec = o.unkec;
    unkf0 = o.unkf0;
    unkf4 = o.unkf4;
    unkf8 = o.unkf8;
    unkfc = o.unkfc;
    unk100 = o.unk100;
    unk104 = o.unk104;
    unk108 = o.unk108;
    unk10c = o.unk10c;
    unk110 = o.unk110;
    unk114 = o.unk114;
    unk118 = o.unk118;
    unk11c = o.unk11c;
    unk120 = o.unk120;
    unk124 = o.unk124;
    unk128 = o.unk128;
    unk12c = o.unk12c;
    return *this;
}

struct __declspec(align(16)) StandinClass
{
    unsigned short unk00;
    __m128 value10;
    __m128 value20;
    __m128 value30;
    __m128 value40;
    __m128 value50;
    __m128 value60;
    __m128 value70;
    __m128 value80;
    StandinClass& ComputeValue_00d85300(const StandinClass* source);
};

// @fnv 0x00d85300
// src: GUESS 0x00d85300 (confidence: low)
StandinClass& StandinClass::ComputeValue_00d85300(const StandinClass* source)
{
    unk00 = source->unk00;
    value10 = source->value10;
    value20 = source->value20;
    value30 = source->value30;
    value40 = source->value40;
    value50 = source->value50;
    value60 = source->value60;
    value70 = source->value70;
    value80 = source->value80;
    return *this;
}

__forceinline hkContactPoint* hkpSimpleContactConstraintAtom::getContactPoints()
{
    return (hkContactPoint*)(this + 1);
}

__forceinline hkContactPoint* hkpSimpleContactConstraintAtom::getContactPoints() const
{
    return (hkContactPoint*)(this + 1);
}

__forceinline UInt32Value* hkpSimpleContactConstraintAtom::getContactPointPropertiesStream() const
{
    return (UInt32Value*)((char*)getContactPoints() + sizeof(hkContactPoint) * m_usMaxNumContactPoints);
}

__forceinline int hkpSimpleContactConstraintAtom::getContactPointPropertiesStriding() const
{
    return m_ucContactPointPropertiesStriding;
}

namespace fnv_00d925b0 {
typedef unsigned int hkUint32;

struct __declspec(align(16)) hkpSimpleContactConstraintDataInfo
{
    hkUint32 m_flags;
    hkUint32 m_uiEdgeIndex;
    float m_internalData0;
    float m_rhsRolling0;
    float m_rhsRolling1;
    float m_rollingFrictionMultiplier;
    float m_internalData1;
    hkUint32 m_data7;
};


__forceinline void memCpy4(void* dst, const void* src, int numWords)
{
    const hkUint32* src32 = (const hkUint32*)src;
    hkUint32* dst32 = (hkUint32*)dst;
    for (int i = 0; i < numWords; i++)
    {
        *(dst32++) = *(src32++);
    }
}

// @fnv 0x00d925b0
// src: GUESS 0x00d925b0 (confidence: low)
void hkpSimpleContactConstraintAtom_ProcessEntries_00d925b0(hkpSimpleContactConstraintAtom* dst, const hkpSimpleContactConstraintAtom* src)
{
    *(hkpSimpleContactConstraintDataInfo*)&dst->m_infoFlags =
        *(const hkpSimpleContactConstraintDataInfo*)&src->m_infoFlags;
    dst->m_usNumContactPoints = src->m_usNumContactPoints;

    hkContactPoint* dstCp = dst->getContactPoints();
    UInt32Value* dstProps = dst->getContactPointPropertiesStream();
    const hkContactPoint* srcCp = src->getContactPoints();
    const UInt32Value* srcProps = src->getContactPointPropertiesStream();
    int striding = src->getContactPointPropertiesStriding();
    for (int i = 0; i < src->m_usNumContactPoints; i++)
    {
        *(dstCp++) = *(srcCp++);
        memCpy4(dstProps, srcProps, striding >> 2);
        dstProps = (UInt32Value*)((char*)dstProps + striding);
        srcProps = (const UInt32Value*)((const char*)srcProps + striding);
    }
}
}  // namespace fnv_00d925b0

inline void hkTransform::setIdentity()
{
    hkVector4 zero;
    zero.setZero4();
    m_kColumn0 = zero.m_vComponents;
    m_kColumn1 = zero.m_vComponents;
    m_kColumn2 = zero.m_vComponents;
    reinterpret_cast<hkVector4&>(m_kColumn0)(0) = 1.0f;
    reinterpret_cast<hkVector4&>(m_kColumn1)(1) = 1.0f;
    reinterpret_cast<hkVector4&>(m_kColumn2)(2) = 1.0f;
    reinterpret_cast<hkVector4&>(m_vTranslation).setZero4();
}

struct ShapeStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int getType() const;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ShapeStub* unk18;
    ShapeStub* GetFieldC();
};

struct ShapeWithVectors : ShapeStub
{
    int unk1c;
    hkVector4 m_kShapeVectorData[1];
};

struct ShapeWithTransforms : ShapeStub
{
    int unk1c;
    hkTransform m_kTransforms[1];
};

// @fnv 0x00d84ee0
// src: GUESS 0x00d84ee0 (confidence: low)
void hkTransform_ProcessEntries_00d84ee0(ShapeStub* shape, int key, hkTransform* out)
{
    for (;;)
    {
        out->setIdentity();
        switch (shape->getType())
        {
        case 12:
            shape = shape->unk18;
            break;
        case 13:
            shape = shape->GetFieldC();
            break;
        case 1:
            *out = ((ShapeWithTransforms*)shape)->m_kTransforms[key];
            return;
        case 2:
            *out = ((ShapeWithTransforms*)shape)->m_kTransforms[key];
            return;
        case 6:
            *out = ((ShapeWithTransforms*)shape)->m_kTransforms[key];
            return;
        case 7:
            *out = ((ShapeWithTransforms*)shape)->m_kTransforms[key];
            return;
        case 14:
            *out = ((ShapeWithTransforms*)shape)->m_kTransforms[key];
            return;
        case 9:
            *out = ((ShapeWithTransforms*)shape)->m_kTransforms[key];
            return;
        case 0:
            out->m_vTranslation = ((ShapeWithVectors*)shape)->m_kShapeVectorData[key].m_vComponents;
            return;
        case 8:
            out->m_vTranslation = ((ShapeWithVectors*)shape)->m_kShapeVectorData[key].m_vComponents;
            return;
        case 15:
            out->m_vTranslation = ((ShapeWithVectors*)shape)->m_kShapeVectorData[key].m_vComponents;
            return;
        default:
            return;
        }
    }
}
