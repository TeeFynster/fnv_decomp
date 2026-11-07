
// src/staging/blk_00de0000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00de0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00de0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/FinishingFlag.h"
#define FNV_VEC4_SCALAR
#include "../../include/Vec4.h"

struct __declspec(align(8)) Entry8
{
    int m_key;
    int m_uiFilterValue;
};
// @fnv 0x00df32a0
// src: HAVOK_LIB 0x00df32a0
void hkKdTreeBuilder_struct_hkKdTreeProjectedEntry_const_struct_hkKdTreeProjectedEntry_restrict_0_writeEmptyLeaf(Entry8* table, int index, int n)
{
    Entry8 e;
    e.m_uiFilterValue = 0;
    e.m_key = 0x7fffffff;
    table[index] = e;
}

__declspec(align(16)) struct HavokObjDfd
{
    void* m_ppVirtualMethodTable;
    int m_04, m_08, m_0c;
    int m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
    int m_30, m_34, m_38, m_3c, m_40, m_44, m_48, m_4c;
    int m_50, m_54, m_58, m_5c, m_60, m_64, m_68, m_6c;
    int m_70, m_74, m_78, m_7c, m_80, m_84, m_88, m_8c;
    int m_90, m_94, m_98, m_9c, m_a0, m_a4, m_a8, m_ac;
    int m_b0, m_b4, m_b8, m_bc, m_c0, m_c4, m_c8, m_cc;
    int m_d0, m_d4, m_d8, m_dc, m_e0, m_e4, m_e8, m_ec;

    HavokObjDfd(FinishingFlag flag);
};

// @fnv 0x00dfd320
// src: GUESS 0x00dfd320 (confidence: medium)
void* __cdecl Object_GetConstructedVirtualTable_00dfd320()
{
    FinishingFlag f;
    f.m_bFinishing = 0;
    HavokObjDfd o(f);
    return o.m_ppVirtualMethodTable;
}

struct __declspec(align(16)) DFFObject
{
    void* m_vtbl;
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
    DFFObject(FinishingFlag flag);
};

// @fnv 0x00dff1a0
// src: GUESS 0x00dff1a0 (confidence: low)
void* Object_ProcessAndReturnValue_00dff1a0()
{
    FinishingFlag f;
    f.m_bFinishing = 0;
    DFFObject o(f);
    return o.m_vtbl;
}

struct __declspec(align(16)) FinishLoadedShape
{
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    FinishLoadedShape(FinishingFlag flag);
};

// @fnv 0x00dff550
// src: GUESS 0x00dff550 (confidence: low)
void* __cdecl Runtime_UpdateState_00dff550()
{
    FinishingFlag f;
    f.m_bFinishing = 0;
    FinishLoadedShape o(f);
    return *(void**)&o;
}

#include <xmmintrin.h>
struct FnvCpu_FUN_00de1170_CpuData0
{
    __m128 field00;
};
struct FnvCpu_FUN_00de1170_CpuData1
{
    __m128 field00;
};
struct FnvCpu_FUN_00de1170_CpuObject
{
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
    __m128 field60;
    __m128 field70;
    void hkDisplayAABB_setExtents(FnvCpu_FUN_00de1170_CpuData0* input0, FnvCpu_FUN_00de1170_CpuData1* input1);
};
// @fnv 0x00de1170
// src: XBOX_PDB 0x00de1170
void FnvCpu_FUN_00de1170_CpuObject::hkDisplayAABB_setExtents(FnvCpu_FUN_00de1170_CpuData0* input0,
                                                 FnvCpu_FUN_00de1170_CpuData1* input1)
{
    this->field60 = input0->field00;
    this->field70 = input1->field00;
}

typedef __m128 S_00de2010_Vec;

struct S_00de2010_Class
{
    int unk00;
    S_00de2010_Vec unk10;
    S_00de2010_Vec unk20;
    S_00de2010_Vec unk30;
    S_00de2010_Vec unk40;
    S_00de2010_Vec unk50;
    S_00de2010_Vec unk60;

    void InitializeFields_00de2010(const S_00de2010_Vec* arg0, const S_00de2010_Vec* arg1);
};

// @fnv 0x00de2010
// src: GUESS 0x00de2010 (confidence: low)
void S_00de2010_Class::InitializeFields_00de2010(const S_00de2010_Vec* arg0, const S_00de2010_Vec* arg1)
{
    // translation, then the four rows of the rotation/transform matrix
    unk60 = arg0[0];
    unk10 = arg1[0];
    unk20 = arg1[1];
    unk30 = arg1[2];
    unk40 = arg1[3];
}

struct __declspec(align(16)) SetupTarget
{
    int unk00;
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
    Vec4 m_vec60;
    Vec4 m_vec70;
    Vec4 m_vec80;
    float m_float90;
    float m_float94;
    float m_float98;
    int m_int9C;

    void UpdateState_00de4950(float f98, float f90, float f94, int i9C, const Vec4& v80, const Vec4& v60, const Vec4& v70);
};

// @fnv 0x00de4950
// src: GUESS 0x00de4950 (confidence: low)
void SetupTarget::UpdateState_00de4950(float f98, float f90, float f94, int i9C, const Vec4& v80, const Vec4& v60,
                               const Vec4& v70)
{
    reinterpret_cast<__m128&>(m_vec80) = reinterpret_cast<const __m128&>(v80);
    reinterpret_cast<__m128&>(m_vec60) = reinterpret_cast<const __m128&>(v60);
    reinterpret_cast<__m128&>(m_vec70) = reinterpret_cast<const __m128&>(v70);
    m_float90 = f90;
    m_float94 = f94;
    m_int9C = i9C;
    m_float98 = f98;
}

struct S00de49b0_Quad
{
    __m128 m_vComponents;
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
};

// local form of hkRotation: 0x00de49b0 needs implicit construction and inline setIdentity; shared form gives 202 bytes vs exe 199.
struct S00de49b0_Rotation
{
    S00de49b0_Quad m_kColumn0;
    S00de49b0_Quad m_kColumn1;
    S00de49b0_Quad m_kColumn2;
    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }
};

struct S00de49b0_Transform
{
    S00de49b0_Rotation m_rotation;
    __m128 m_vTranslation;
    void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation = _mm_setzero_ps();
    }
};

class __declspec(novtable) S00de49b0_RefObject
{
  public:
    S00de49b0_RefObject() : m_sReferenceCount(1)
    {}
    virtual void vf00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class __declspec(novtable) S00de49b0_Base : public S00de49b0_RefObject
{
  public:
    S00de49b0_Base() : m_ulUserData(0), m_type(5)
    {
        m_kMotionTransform.setIdentity();
    }
    unsigned int m_ulUserData;
    S00de49b0_Transform m_kMotionTransform;
    int m_type;
};

class FUN_00de49b0 : public S00de49b0_Base
{
  public:
    FUN_00de49b0(const Vec4& kC, const Vec4& kA, const Vec4& kB, float f1, float f2,
                 float f3, int i1);
    virtual void vf00();

    Vec4 m_kA;
    Vec4 m_kB;
    Vec4 m_kC;
    float m_f90;
    float m_f94;
    float m_f98;
    int m_i9C;
};

// @fnv 0x00de49b0
FUN_00de49b0::FUN_00de49b0(const Vec4& kC, const Vec4& kA, const Vec4& kB, float f1,
                           float f2, float f3, int i1)
    : m_kA(kA), m_kB(kB), m_kC(kC), m_f90(f1), m_f94(f2), m_f98(f3), m_i9C(i1)
{}

// Object holding two 16-byte vectors and three scalars; the setter copies
// the two vectors and the three scalars into the object.
struct FUN_00de5370_cls
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    __m128 m_v60;
    __m128 m_v70;
    int m_i80;
    float m_f84;
    float m_f88;
    void InitializeFields_00de5370(float f1, float f2, int i1, const __m128* p1, const __m128* p2);
};

// @fnv 0x00de5370
// src: GUESS 0x00de5370 (confidence: low)
void FUN_00de5370_cls::InitializeFields_00de5370(float f1, float f2, int i1, const __m128* p1, const __m128* p2)
{
    m_f84 = f1;
    m_v60 = *p2;
    m_v70 = *p1;
    m_f88 = f2;
    m_i80 = i1;
}

struct S00de53b0_Quad
{
    __m128 m_vComponents;
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
};

// local form of hkRotation: 0x00de53b0 needs implicit construction and inline setIdentity; shared form gives 155 bytes vs exe 152.
struct S00de53b0_Rotation
{
    S00de53b0_Quad m_kColumn0;
    S00de53b0_Quad m_kColumn1;
    S00de53b0_Quad m_kColumn2;
    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }
};

struct S00de53b0_Transform
{
    S00de53b0_Rotation m_rotation;
    __m128 m_vTranslation;
    void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation = _mm_setzero_ps();
    }
};

class __declspec(novtable) S00de53b0_RefObject
{
  public:
    S00de53b0_RefObject() : m_sReferenceCount(1)
    {}
    virtual void vf00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class __declspec(novtable) S00de53b0_Base : public S00de53b0_RefObject
{
  public:
    S00de53b0_Base() : m_ulUserData(0), m_type(4)
    {
        m_kMotionTransform.setIdentity();
    }
    unsigned int m_ulUserData;
    S00de53b0_Transform m_kMotionTransform;
    int m_type;
};

class FUN_00de53b0 : public S00de53b0_Base
{
  public:
    FUN_00de53b0(float f1, float f2, int i1, const Vec4& p1, const Vec4& p2);
    virtual void vf00();

    Vec4 m_v60;
    Vec4 m_v70;
    int m_i80;
    float m_f84;
    float m_f88;
};

// @fnv 0x00de53b0
FUN_00de53b0::FUN_00de53b0(float f1, float f2, int i1, const Vec4& p1, const Vec4& p2)
    : m_v60(p2), m_v70(p1), m_i80(i1), m_f84(f1), m_f88(f2)
{}

struct ScaleMatrix
{
    __m128 row0, row1, row2, row3;
    const __m128* ProcessAndReturnValue_00de88a0(const __m128* scalar, const ScaleMatrix* matrix);
};

// @fnv 0x00de88a0
// src: GUESS 0x00de88a0 (confidence: low)
const __m128* ScaleMatrix::ProcessAndReturnValue_00de88a0(const __m128* scalar, const ScaleMatrix* matrix)
{
    row0 = _mm_mul_ps(_mm_shuffle_ps(*scalar, *scalar, 0), matrix->row0);
    row1 = _mm_mul_ps(_mm_shuffle_ps(*scalar, *scalar, 0), matrix->row1);
    row2 = _mm_mul_ps(_mm_shuffle_ps(*scalar, *scalar, 0), matrix->row2);
    row3 = _mm_mul_ps(_mm_shuffle_ps(*scalar, *scalar, 0), matrix->row3);
    return scalar;
}

struct __declspec(align(16)) Vector4_df07c0
{
    float q[4];
};

struct Motion_df07c0
{
    int unk00;
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
    Vector4_df07c0 m_kTranslationalVelocity[3];  // +0x30
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    Vector4_df07c0 m_kAngularVelocity[3];  // +0x90
};

struct MotionArgument
{
    Motion_df07c0* p;
    MotionArgument(Motion_df07c0* q) : p(q)
    {}
};

// @fnv 0x00df07c0
// src: GUESS 0x00df07c0 (confidence: low)
void __cdecl Object_ProcessEntries_00df07c0(const unsigned char* pucLockedAxes, MotionArgument pkMotion)
{
    if (*pucLockedAxes)
    {
        Motion_df07c0* motion = pkMotion.p;
        for (int i = 0; i < 3; i++)
        {
            if ((*pucLockedAxes >> (i * 2)) & 3)
            {
                _mm_store_ps(motion->m_kTranslationalVelocity[i].q, _mm_setzero_ps());
                _mm_store_ps(motion->m_kAngularVelocity[i].q, _mm_setzero_ps());
            }
        }
    }
}

// @fnv 0x00df3120
// src: GUESS 0x00df3120 (confidence: low)
void __stdcall Object_UpdateFields_00df3120(__m128* dest, unsigned int index, __m128* src)
{
    *(__m128*)((char*)dest + (index << 4)) = *src;
}

// Exe 0x00df32d0: unit-local Vector4f view; declarations and layout are preserved.
struct BlkVector4fView
{
    unsigned int a, b, c, d;
};
struct MetaEntry
{
    unsigned int index;
    unsigned int state;
};

// @fnv 0x00df32d0
// src: GUESS 0x00df32d0 (confidence: low)
void __cdecl Runtime_UpdateState_00df32d0(MetaEntry* meta, BlkVector4fView* src, __m128* dst, unsigned int metaIndex, unsigned int index)
{
    __declspec(align(16)) BlkVector4fView u = src[index];
    MetaEntry e;
    e.index = index & 0x7fffffff;
    e.state = 1;
    meta[metaIndex] = e;
    dst[index] = *(__m128*)&u;
}

extern __m128 DAT_010cbfc0;

inline __m128 RotateDF5D20(__m128 v, const __m128* rows)
{
    return _mm_add_ps(
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), rows[1]), _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), rows[0])),
        _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), rows[2]));
}

// @fnv 0x00df5d20
// src: GUESS 0x00df5d20 (confidence: low)
__m128* __cdecl Object_ProcessAndReturnValue_00df5d20(__m128* fields, const __m128* input, __m128* outA, __m128* outB)
{
    __m128 rotated = RotateDF5D20(*input, fields + 16);
    __m128 scaleA = _mm_shuffle_ps(fields[6], fields[6], 0xff);
    *outA = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(scaleA, scaleA, 0), rotated), *outA);
    __m128 scaleB = _mm_shuffle_ps(fields[14], fields[14], 0xff);
    *outB = _mm_sub_ps(*outB, _mm_mul_ps(_mm_shuffle_ps(scaleB, scaleB, 0), rotated));
    outA[1] = _mm_add_ps(RotateDF5D20(*input, fields + 3), outA[1]);
    outB[1] = _mm_sub_ps(outB[1], RotateDF5D20(*input, fields + 11));
    outA[1] = _mm_and_ps(outA[1], DAT_010cbfc0);
    outB[1] = _mm_and_ps(outB[1], DAT_010cbfc0);
    *outA = _mm_and_ps(*outA, DAT_010cbfc0);
    *outB = _mm_and_ps(*outB, DAT_010cbfc0);
    return fields;
}

struct __declspec(align(16)) Holder
{
    void* m_pVTable;
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
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    void FUN_00c93d10(FinishingFlag arg);
};

// @fnv 0x00df6470
// src: HAVOK_LIB 0x00df6470
void* getVtablehkpWorld()
{
    Holder holder;
    FinishingFlag arg(0);
    holder.FUN_00c93d10(arg);
    return holder.m_pVTable;
}

class __declspec(align(16)) S00dfb2b0_Object
{
  public:
    S00dfb2b0_Object(FinishingFlag flag);  // FUN_00dfb2d0
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dfb2b0
// src: GUESS 0x00dfb2b0 (confidence: medium)
const void* __cdecl Runtime_GetVtableFromTemporary_00dfb2b0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfb2b0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

namespace fnv_00dfb2d0 {
extern "C" char DAT_010305a8;
extern "C" char DAT_010ce3c8;
extern "C" char DAT_010d0d70;
extern "C" char DAT_010d0dac;
extern "C" char DAT_010c6fd0;

struct ShapeChild
{
    int unk00;
    int unk04;
    int unk08;
    __m128 unk10;
    int unk20;
    int unk24;
};

struct FUN_00dfb2d0
{
    char* unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    ShapeChild* unk14;
    int unk18;
    int unk1c;
    __m128 unk20;
    char* unk30;

    FUN_00dfb2d0(FinishingFlag flag);
};

// @fnv 0x00dfb2d0
FUN_00dfb2d0::FUN_00dfb2d0(FinishingFlag flag)
{
    this->unk00 = &DAT_010305a8;

    if (flag.m_bFinishing)
    {
        this->unk0c = 0;
    }

    this->unk00 = &DAT_010ce3c8;

    if (flag.m_bFinishing)
    {
        this->unk0c = 8;
        this->unk10 = 2;
    }

    this->unk00 = &DAT_010d0d70;

    if (flag.m_bFinishing)
    {
        this->unk10 = 0;
    }

    this->unk00 = &DAT_010d0dac;
    this->unk30 = &DAT_010c6fd0;

    if (flag.m_bFinishing == 1)
    {
        this->unk0c = 0xa;
        this->unk20 = this->unk14->unk10;
        this->unk18 = this->unk14->unk20;
        this->unk1c = this->unk14->unk24;
    }
}
}  // namespace fnv_00dfb2d0

class __declspec(align(16)) S00dfb400_Object
{
  public:
    S00dfb400_Object(FinishingFlag flag);  // FUN_00e2ea20
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dfb400
// src: GUESS 0x00dfb400 (confidence: medium)
const void* __cdecl Object_GetConstructedVirtualTable_00dfb400()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfb400_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00dfb460_Object
{
  public:
    S00dfb460_Object(FinishingFlag flag);  // Init
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dfb460
// src: GUESS 0x00dfb460 (confidence: medium)
const void* __cdecl Object_GetConstructedVirtualTable_00dfb460()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfb460_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00dfba80_Object
{
  public:
    S00dfba80_Object(FinishingFlag flag);  // FUN_00e34800
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dfba80
// src: GUESS 0x00dfba80 (confidence: medium)
const void* __cdecl Object_GetConstructedVirtualTable_00dfba80()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfba80_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00dfc7a0_Object
{
  public:
    S00dfc7a0_Object(FinishingFlag flag);  // ReleaseLinks
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dfc7a0
// src: GUESS 0x00dfc7a0 (confidence: medium)
const void* __cdecl Object_GetConstructedVirtualTable_00dfc7a0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfc7a0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

struct __declspec(align(16)) DFC830Obj
{
    int unk00;
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    void FUN_00dfc850(FinishingFlag arg);
};

// @fnv 0x00dfc830
// src: GUESS 0x00dfc830 (confidence: low)
void* Runtime_EvaluateValue_00dfc830()
{
    DFC830Obj holder;
    FinishingFlag zero(0);
    holder.FUN_00dfc850(zero);
    return *(void**)&holder.unk00;
}

class __declspec(align(16)) S00dfcb70_Object
{
  public:
    S00dfcb70_Object(FinishingFlag flag);  // FUN_00e3b960
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dfcb70
// src: GUESS 0x00dfcb70 (confidence: medium)
const void* __cdecl Runtime_GetVtableFromTemporary_00dfcb70()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfcb70_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

struct __declspec(align(16)) FUN_00d53df0
{
    FUN_00d53df0(FinishingFlag kHandle);
    int m_iResult;
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
};
// @fnv 0x00dfce10
// src: GUESS 0x00dfce10 (confidence: low)
int __cdecl Runtime_EvaluateValue_00dfce10()
{
    FinishingFlag kHandle(0);
    FUN_00d53df0 kQuery(kHandle);
    return kQuery.m_iResult;
}

class __declspec(align(16)) S00dfcf40_Object
{
  public:
    S00dfcf40_Object(FinishingFlag flag);  // InitializeVtables
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dfcf40
// src: GUESS 0x00dfcf40 (confidence: medium)
const void* __cdecl Object_GetConstructedVirtualTable_00dfcf40()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfcf40_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00dfd200_Object
{
  public:
    S00dfd200_Object(FinishingFlag flag);  // FUN_00cf56f0
    void* m_ppVirtualMethodTable;
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
    int unk64;
    int unk68;
    int unk6C;
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dfd200
// src: GUESS 0x00dfd200 (confidence: medium)
const void* __cdecl Object_GetConstructedVirtualTable_00dfd200()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfd200_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00dfd280_Object
{
  public:
    S00dfd280_Object(FinishingFlag flag);  // FUN_00d59830
    void* m_ppVirtualMethodTable;
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
    int unk64;
    int unk68;
    int unk6C;
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dfd280
// src: GUESS 0x00dfd280 (confidence: medium)
const void* __cdecl Object_GetConstructedVirtualTable_00dfd280()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfd280_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

// FUN_00dfd630 (0x00dfd630, 28 bytes, pack /MT /Od /Oy- /GS /EHsc /Gy)
//
// Original: push ebp / mov ebp,esp / and esp,-16 / sub esp,0x70
//           xor eax,eax / push eax        -> byval 1-int zero UDT arg
//           lea ecx,[esp+4]               -> this = 0x70-byte stack object at frame bottom
//           call FUN_00e3e380             -> thiscall ctor, callee pops its 4-byte arg
//           mov eax,[esp]                 -> return object's first dword
//           mov esp,ebp / pop ebp / ret
//
// The simple aligned ESP frame is /O2 WITHOUT /Oy- output (dfc830/d4b330 twins:
// proofs accepted). Source mirrors the accepted dfc830 draft.
struct __declspec(align(16)) Dfd630Obj
{
    int unk00;  // vptr slot written by the ctor
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
    int unk64;
    int unk68;
    int unk6C;
    void FUN_00e3e380(FinishingFlag arg);
};

// @fnv 0x00dfd630
// src: GUESS 0x00dfd630 (confidence: low)
void* Runtime_EvaluateValue_00dfd630()
{
    Dfd630Obj holder;
    FinishingFlag z(0);
    holder.FUN_00e3e380(z);
    return *(void**)&holder.unk00;
}

unsigned int DAT_010e33dc;

struct FUN_00dfd9b0_sub
{
    int m_00;
    void ReturnSelf(FinishingFlag arg);
};

struct __declspec(align(16)) FUN_00dfd9b0_holder
{
    unsigned int* m_pTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00dfd9b0_sub m_sub;
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};

// @fnv 0x00dfd9b0
// src: GUESS 0x00dfd9b0 (confidence: low)
unsigned int* Runtime_UpdateState_00dfd9b0()
{
    FUN_00dfd9b0_holder holder;
    FinishingFlag arg(0);
    holder.m_pTable = &DAT_010e33dc;
    holder.m_sub.ReturnSelf(arg);
    return holder.m_pTable;
}

class __declspec(align(16)) S00dfda80_Object
{
  public:
    S00dfda80_Object(FinishingFlag flag);  // FUN_00e3f510
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dfda80
// src: GUESS 0x00dfda80 (confidence: medium)
const void* __cdecl Object_GetConstructedVirtualTable_00dfda80()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfda80_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00dfe280_Object
{
  public:
    S00dfe280_Object(FinishingFlag flag);  // FUN_00ce25f0
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dfe280
// src: GUESS 0x00dfe280 (confidence: medium)
const void* __cdecl Object_GetConstructedVirtualTable_00dfe280()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfe280_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

int DAT_010cb864;

struct ZSubDFE2F0
{
    int m_00;
    void ComputeValue_00ce5360(FinishingFlag arg);
};

struct __declspec(align(16)) ZHolderDFE2F0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ZSubDFE2F0 m_sub;
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};

// @fnv 0x00dfe2f0
// src: HAVOK_LIB 0x00dfe2f0
int* getVtablehkaSkeletonMapper()
{
    ZHolderDFE2F0 holder;
    FinishingFlag arg(0);
    holder.unk00 = (int)&DAT_010cb864;
    holder.m_sub.ComputeValue_00ce5360(arg);
    return *(int**)&holder.unk00;
}

struct __declspec(align(16)) FUN_00dfe440_obj
{
    int m_pVTable;
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
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    void InitializeFields_00e40ca0(FinishingFlag arg);
};

// @fnv 0x00dfe440
// src: HAVOK_LIB 0x00dfe440
int getVtablehkaFootstepAnalysisInfo()
{
    FUN_00dfe440_obj obj;
    obj.InitializeFields_00e40ca0(FinishingFlag());
    return obj.m_pVTable;
}

struct FUN_00dff130_sub
{
    void ReturnSelf(FinishingFlag kHandle);
    int m_00;
};
extern int DAT_010cc2fc;
extern int DAT_010e6834;
struct __declspec(align(16)) FUN_00dff130_obj
{
    int* m_pVtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00dff130_sub m_kSub;
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
};
// @fnv 0x00dff130
// src: HAVOK_LIB 0x00dff130
int* __cdecl getVtablehkpReorientAction()
{
    FinishingFlag kHandle(0);
    FUN_00dff130_obj kObj;
    kObj.m_pVtbl = &DAT_010cc2fc;
    kObj.m_kSub.ReturnSelf(kHandle);
    return &DAT_010e6834;
}

class __declspec(align(16)) S00dff310_Object
{
  public:
    S00dff310_Object(FinishingFlag flag);  // Initialize
    void* m_ppVirtualMethodTable;
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
    int unk64;
    int unk68;
    int unk6C;
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dff310
// src: GUESS 0x00dff310 (confidence: medium)
const void* __cdecl Runtime_GetVtableFromTemporary_00dff310()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dff310_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00dff4f0_Object
{
  public:
    S00dff4f0_Object(FinishingFlag flag);  // FUN_00e46300
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dff4f0
// src: GUESS 0x00dff4f0 (confidence: medium)
const void* __cdecl Runtime_GetVtableFromTemporary_00dff4f0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dff4f0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00dff8b0_Object
{
  public:
    S00dff8b0_Object(FinishingFlag flag);  // InitializeRecordPointers
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dff8b0
// src: GUESS 0x00dff8b0 (confidence: medium)
const void* __cdecl Runtime_GetVtableFromTemporary_00dff8b0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dff8b0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00dffa70_Object
{
  public:
    S00dffa70_Object(FinishingFlag flag);  // FUN_00dffa90
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dffa70
// src: GUESS 0x00dffa70 (confidence: medium)
const void* __cdecl Runtime_GetVtableFromTemporary_00dffa70()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dffa70_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00dffbb0_Object
{
  public:
    S00dffbb0_Object(FinishingFlag flag);  // FUN_00e46f20
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dffbb0
// src: GUESS 0x00dffbb0 (confidence: medium)
const void* __cdecl Runtime_GetVtableFromTemporary_00dffbb0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dffbb0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00dfffa0_Object
{
  public:
    S00dfffa0_Object(FinishingFlag flag);  // FUN_00cdf760
    virtual void vf00();
    int m_kNextStreamField[7];
};

// @fnv 0x00dfffa0
// src: GUESS 0x00dfffa0 (confidence: low)
const void* __cdecl Object_ProcessAndReturnValue_00dfffa0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfffa0_Object kObject(flag);
    return *reinterpret_cast<const void**>(&kObject);
}

struct __declspec(align(16)) Quad_de1190
{
    float q[4];
};  // hkVector4 storage (float[4]: see the vptr padding note)

struct RefObject_de1190
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    RefObject_de1190()
    {
        m_sReferenceCount = 1;
    }
    virtual ~RefObject_de1190()
    {}
};

struct TransformShape_de1190 : RefObject_de1190
{
    int m_type;
    int unk0c;
    Quad_de1190 m_rotation[3];
    Quad_de1190 m_vTranslation;
    int m_userType;
    int unk54, unk58, unk5c;
    TransformShape_de1190()
    {
        m_type = 0;
        m_userType = 3;
        __m128 kZero = _mm_setzero_ps();
        _mm_store_ps(m_rotation[0].q, kZero);
        _mm_store_ps(m_rotation[1].q, kZero);
        _mm_store_ps(m_rotation[2].q, kZero);
        m_rotation[0].q[0] = 1.0f;
        m_rotation[1].q[1] = 1.0f;
        m_rotation[2].q[2] = 1.0f;
        _mm_store_ps(m_vTranslation.q, kZero);
    }
    virtual ~TransformShape_de1190()
    {}
};

struct Shape_de1190 : TransformShape_de1190
{
    Vec4 m_kMin;
    Vec4 m_kMax;
    Shape_de1190(const Vec4& kMinBoundsCur, const Vec4& kMaxPoint);
    virtual ~Shape_de1190();
};

// @fnv 0x00de1190
Shape_de1190::Shape_de1190(const Vec4& kMinBoundsCur, const Vec4& kMaxPoint)
    : m_kMin(Vec4::Uninitialized), m_kMax(Vec4::Uninitialized)
{
    m_kMin = kMinBoundsCur;
    m_kMax = kMaxPoint;
}

namespace SIMD56 {
// Exe 0x00df56a0 FUN_00df56a0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef struct __declspec(intrin_type) __declspec(align(16)) {
    float x, y, z, w;
} __m128, LocalM128;
extern "C" LocalM128 _mm_and_ps(LocalM128, LocalM128);
}
struct SplitB
{
    int f0;
    int f4;
};

struct Node56
{
    SplitB* m0;
    int m4;
    int m8;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    SIMD56::LocalM128 m20;
    int m30;
    int m34;
    int m38;
    int m3c;
    SIMD56::LocalM128 m40;
};

struct W2
{
    short lo;
    short hi;
};

union Packed56
{
    int bits;
    W2 words;
};

struct SplitA
{
    int f0;
    int f4;
    short lo;
    short hi;
};

struct Pairs56
{
    SplitB r[2];
};

extern SIMD56::LocalM128 DAT_012684d0;
extern SIMD56::LocalM128 DAT_01268460[];

struct Output56
{
    unsigned int flags;
    int v;
    void setPlanes(short lo, short hi)
    {
        v = 0;
        ((short*)&v)[0] = lo;
        ((short*)&v)[1] = hi;
    }
};

int hkKdTreeBuilder_struct_hkKdTreeProjectedEntry_const_struct_hkKdTreeProjectedEntry_restrict_0_writeEmptyLeaf(Output56* a, int b, int c);
int Runtime_UpdateState_00df32d0(Output56* a, int b, int c, int d, int e, int f);
int Runtime_ProcessEntries_00df3330(Output56* a, int b, int c, int d, int e, int f, int g);
__declspec(noalias) int ProcessEntries_00df4ec0(SplitB* a, int b, int c, SplitA* sa, int* p5, SplitB* sb, SIMD56::LocalM128* v20,
                                     SIMD56::LocalM128* v40);

// @fnv 0x00df56a0
// src: XBOX_PDB 0x00df56a0
int hkKdTreeBuilder_hkKdTreeProjectedEntry_const_hkKdTreeProjectedEntry_restrict_0_buildTreeRecursive(Node56* p, Output56** p2, int p3, int* p4, int* p5)
{
    int i;
    i = p->m10 - p->m0c;
    if (0 == i)
    {
        hkKdTreeBuilder_struct_hkKdTreeProjectedEntry_const_struct_hkKdTreeProjectedEntry_restrict_0_writeEmptyLeaf(*p2, p->m4, p->m30);
        return 1 + i;
    }
    if (1 == i)
    {
        Runtime_UpdateState_00df32d0(*p2, p->m0->f0, p3, p->m4, p->m0c, p->m30);
        return i;
    }
    if (4 >= i)
    {
        *p5 += Runtime_ProcessEntries_00df3330(*p2, p->m0->f0, p3, p->m4, p->m0c, i, p->m30);
        return 1;
    }
    int t[3];
    Output56 y;
    Node56 left;
    Node56 right;
    Pairs56 saved40;
    int mid;
    unsigned long a;
    {
        SplitA ptr;
        SplitB j;
        if (ProcessEntries_00df4ec0(p->m0, p->m0c, p->m10, &ptr, p5, &j, &p->m20, &p->m40) == 1)
        {
            *p5 += Runtime_ProcessEntries_00df3330(*p2, p->m0->f0, p3, p->m4, p->m0c, i, p->m30);
            return 1;
        }
        y.setPlanes(ptr.lo, ptr.hi);
        long pForm;
        pForm = *p4 + 1;
        *p4 = *p4 + 2;
        a = ptr.f0;
        y.flags = ((pForm - p->m4) << 3) | (3 & a) | 0x80000000;
        (*p2)[p->m4] = y;
        saved40.r[0] = j;
        saved40.r[1] = j;
        mid = ptr.f4;
        left.m40 = DAT_012684d0;
        left.m0 = &saved40.r[0];
        left.m0c = p->m0c;
        left.m10 = mid;
        left.m4 = pForm;
        left.m20 = p->m20;
        ((short*)&left.m20)[a + 4] = ptr.hi;
        int writer = p->m30;
        left.m8 = p->m8;
        right.m40 = DAT_012684d0;
        right.m0 = &saved40.r[1];
        right.m4 = pForm + 1;
        right.m0c = mid;
        right.m10 = p->m10;
        right.m20 = p->m20;
        ((short*)&right.m20)[a] = ptr.lo;
        left.m30 = writer;
        right.m30 = writer;
        right.m8 = p->m8;
    }
    if (mid == p->m10 || mid == p->m0c)
    {
        t[0] = 6;
        t[1] = 5;
        t[2] = 3;
        struct
        {
            SIMD56::LocalM128 table;
            SIMD56::LocalM128 result;
        } masks;
        masks.table = DAT_01268460[t[a]];
        masks.result = SIMD56::_mm_and_ps(masks.table, p->m40);
        left.m40 = masks.result;
        right.m40 = masks.result;
    }
    int cnt;
    int r;
    cnt = hkKdTreeBuilder_hkKdTreeProjectedEntry_const_hkKdTreeProjectedEntry_restrict_0_buildTreeRecursive(&left, p2, p3, p4, p5);
    r = hkKdTreeBuilder_hkKdTreeProjectedEntry_const_hkKdTreeProjectedEntry_restrict_0_buildTreeRecursive(&right, p2, p3, p4, p5);
    return (cnt > r ? cnt : r) + 1;
}

struct S00dfbe20_Member
{
    S00dfbe20_Member(FinishingFlag flag);  // FUN_00cb0a70
    int m_iWordAt00;
};

class S00dfbe20_Base
{
  public:
    S00dfbe20_Base(FinishingFlag flag)
    {}
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class S00dfbe20_Mid : public S00dfbe20_Base
{
  public:
    S00dfbe20_Mid(FinishingFlag flag) : S00dfbe20_Base(flag), m_kMember(flag)
    {}
    virtual void vf00();
    S00dfbe20_Member m_kMember;
};

class __declspec(align(16)) S00dfbe20_Object : public S00dfbe20_Mid
{
  public:
    S00dfbe20_Object(FinishingFlag flag) : S00dfbe20_Mid(flag)
    {}
    virtual void vf00();
    int m_kNextStreamField[48];
};

// @fnv 0x00dfbe20
// src: HAVOK_LIB 0x00dfbe20
const void* __cdecl getVtablehkpVehicleInstance()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfbe20_Object kObject(flag);
    return *reinterpret_cast<const void**>(&kObject);
}

class __declspec(align(16)) S00dfe5e0_Object
{
  public:
    S00dfe5e0_Object(FinishingFlag flag)
    {
        FinishingFlag arg;
        arg.m_bFinishing = flag.m_bFinishing;
        m_kFirst.ReturnSelf(arg);
        m_kSecond.ReturnSelf(arg);
    }
    virtual void vf00();
    int unk04;
    FUN_00dfd9b0_sub m_kFirst;
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
    FUN_00dfd9b0_sub m_kSecond;
    int unk58;
    int unk5C;
};

// @fnv 0x00dfe5e0
// src: HAVOK_LIB 0x00dfe5e0
const void* __cdecl getVtablehkaBoneAttachment()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfe5e0_Object kObject(flag);
    return *reinterpret_cast<const void**>(&kObject);
}

struct S00dfba10_Member
{
    S00dfba10_Member(FinishingFlag flag);  // FUN_00cb0a70
    int m_iWordAt00;
};

class __declspec(align(16)) S00dfba10_Object
{
  public:
    S00dfba10_Object(FinishingFlag flag) : m_kMember(flag)
    {}
    virtual void vf00();
    int unk04;
    S00dfba10_Member m_kMember;
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
};

// @fnv 0x00dfba10
// src: HAVOK_LIB 0x00dfba10
const void* __cdecl getVtablehkaSkeleton()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfba10_Object kObject(flag);
    return *reinterpret_cast<const void**>(&kObject);
}

struct S00dfc400_Member
{
    S00dfc400_Member(FinishingFlag flag);
    int m_iWordAt00;
};

class __declspec(align(16)) S00dfc400_Object
{
  public:
    S00dfc400_Object(FinishingFlag flag) : m_kMember(flag)
    {}
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    S00dfc400_Member m_kMember;
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
};

// @fnv 0x00dfc400
// src: HAVOK_LIB 0x00dfc400
const void* __cdecl getVtablehkpSerializedAgentNnEntry()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfc400_Object kObject(flag);
    return *reinterpret_cast<const void**>(&kObject);
}

class __declspec(align(16)) AnimationBindingVtableProbe
{
  public:
    AnimationBindingVtableProbe(FinishingFlag flag)
    {
        FinishingFlag argument(flag.m_bFinishing);
        m_skeletonName.ReturnSelf(argument);
    }
    virtual void vf00();
    int unk04;
    FUN_00dfd9b0_sub m_skeletonName;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

// @fnv 0x00dfe9b0
// src: HAVOK_LIB 0x00dfe9b0
const void* __cdecl getVtablehkaAnimationBinding()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    AnimationBindingVtableProbe object(flag);
    return *reinterpret_cast<const void**>(&object);
}

extern int DAT_010d08f4;

struct __declspec(align(16)) SpringVtableObject
{
    int* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00dff130_sub m_name;
    int unk18;
    int unk1C;
    float m_lastForceX;
    float m_lastForceY;
    float m_lastForceZ;
    float m_lastForceW;
    float m_pivotAX;
    float m_pivotAY;
    float m_pivotAZ;
    float m_pivotAW;
    float m_pivotBX;
    float m_pivotBY;
    float m_pivotBZ;
    float m_pivotBW;
    float m_fRestLength;
    float m_fSpringStrength;
    float m_fMotorDamping;
    bool m_compression;
    bool m_extension;
};

// @fnv 0x00dfef90
// src: GUESS 0x00dfef90 (confidence: low)
const void* __cdecl Runtime_UpdateState_00dfef90()
{
    FinishingFlag finish(0);
    SpringVtableObject object;
    object.m_ppVirtualMethodTable = &DAT_010cc2fc;
    object.m_name.ReturnSelf(finish);
    return &DAT_010d08f4;
}

extern int DAT_010cce28;
extern int DAT_010d07f4;

struct __declspec(align(16)) ContactSystemView
{
    int* table;
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
    FUN_00dfd9b0_sub name;
    int userData;
    int active;
    int contactsData;
    int contactsSize;
    int contactsCapacity;
};

// @fnv 0x00dff220
// src: HAVOK_LIB 0x00dff220
const void* __cdecl getVtablehkpPhysicsSystemWithContacts()
{
    FinishingFlag flag(0);
    ContactSystemView object;
    object.table = &DAT_010cce28;
    object.name.ReturnSelf(flag);
    return &DAT_010d07f4;
}

extern int DAT_010c8e94;

struct __declspec(align(16)) VtableProbeDff2b0
{
    int* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00dff130_sub m_name;
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
};

// @fnv 0x00dff2b0
// src: GUESS 0x00dff2b0 (confidence: low)
const void* __cdecl Runtime_UpdateState_00dff2b0()
{
    FinishingFlag flag(0);
    VtableProbeDff2b0 object;
    object.m_ppVirtualMethodTable = &DAT_010cc2fc;
    object.m_name.ReturnSelf(flag);
    return &DAT_010c8e94;
}

class __declspec(align(16)) S00dff380_Object : public S00dfbe20_Mid
{
  public:
    S00dff380_Object(FinishingFlag flag) : S00dfbe20_Mid(flag)
    {}
    virtual void vf00();
    int unkD18;
    int unkD1C;
    int unkD20;
    int unkD24;
    int unkD28;
    int unkD2C;
    int unkD30;
    int unkD34;
    int unkD38;
    int unkD3C;
};

// @fnv 0x00dff380
// src: GUESS 0x00dff380 (confidence: low)
const void* __cdecl Object_ProcessAndReturnValue_00dff380()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dff380_Object kObject(flag);
    return *reinterpret_cast<const void**>(&kObject);
}

extern int DAT_010d0994;

struct __declspec(align(16)) DashpotTypeInfoObject
{
    FUN_00dff130_obj m_pAction;
    float m_impulseX;
    float m_impulseY;
    float m_impulseZ;
    float m_impulseW;
};

// @fnv 0x00dff9f0
// src: GUESS 0x00dff9f0 (confidence: low)
int* __cdecl Runtime_UpdateState_00dff9f0()
{
    FinishingFlag finishing(0);
    DashpotTypeInfoObject object;
    object.m_pAction.m_pVtbl = &DAT_010cc2fc;
    object.m_pAction.m_kSub.ReturnSelf(finishing);
    return &DAT_010d0994;
}

extern int DAT_010d09f4;

struct __declspec(align(16)) AngularActionVtableObject
{
    int* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00dff130_sub m_name;
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
};

// @fnv 0x00dffc20
// src: GUESS 0x00dffc20 (confidence: low)
const void* __cdecl Object_ProcessAndReturnValue_00dffc20()
{
    FinishingFlag flag(0);
    AngularActionVtableObject object;
    object.m_ppVirtualMethodTable = &DAT_010cc2fc;
    object.m_name.ReturnSelf(flag);
    return &DAT_010d09f4;
}
