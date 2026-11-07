
// src/havok/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// hkRefObj_hkpsampledheightfieldshape: local type (was include/hkRefObj.h, which had no evidence of one real class); its methods are 0x00c90510 hkReferencedObject::addReference, 0x00c905b0 hkReferencedObject::removeReference
class hkRefObj_hkpsampledheightfieldshape
{
public:
    hkRefObj_hkpsampledheightfieldshape() : m_sReferenceCount(1) {}
    ~hkRefObj_hkpsampledheightfieldshape();

    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;

    void FUN_00c90510();
    void FUN_00c905b0();
};
// Exe 0x00d248a0 FUN_00d248a0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; unsigned __int64 m128_u64[2]; } __m128, LocalM128;
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkpSampledHeightFieldShape.h"
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" LocalM128 _mm_load_ps1(const float*);
extern float DAT_01012068;
extern double DAT_01012070;
struct Cls_00d24670 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30();
    virtual float getH(int x, int y);
    virtual void getFlip(bool& flip);
    void UpdateState_00d24670(int x, int y, float fx, float fy, LocalM128* nrm, float* height, int* flag);
};
struct hkInfoD260 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fScalar;
};
class hkCollectorD260 {
public:
    hkCollectorD260(hkInfoD260* info) : m_fScalar(info->m_fScalar), m_bHasHit(false), m_info(info) {}
    virtual void AddHit(void* hit);

    float m_fScalar;
    bool m_bHasHit;
    hkInfoD260* m_info;
};
struct FUN_00d24b50_Obj {
    void __thiscall hkpSampledHeightFieldShape_castRayInternal(void* object, int flags, hkBool flag2, float f, hkCollectorD260* collector);
};
class hkShapeD260 : public FUN_00d24b50_Obj {
public:
    hkBool __thiscall hkpSampledHeightFieldShape_castRayImpl(void* object, hkInfoD260* info);
};
struct S00d261b0_Elem {
    LocalM128 v00;
    float f10;
    int i14;
    int unk18;
    int unk1c;
    int m_slots[8];
    int m_idx40;
};
struct S00d261b0_cls {
    int unk00;
    float f04;
    unsigned char b08;
    S00d261b0_Elem* p0c;
    void UpdateMinValue(int a0, int a1);
};
extern int DAT_010ce310;
struct Arg3 {
    int unk00;
    float m_04;
};
struct Local12 {
    void* m_00;
    float m_04;
    const Arg3* m_08;
};
struct Val1 {
    unsigned char m_00;
    Val1() : m_00(0) {}
    Val1(const Val1& o) : m_00(o.m_00) {}
};
struct Host {
    void hkpSampledHeightFieldShape_castRayInternal(int a1, int a2, Val1 v, float f, Local12* pLocal);
    void hkpSampledHeightFieldShape_castRayWithCollectorImpl(int a1, int a2, const Arg3* a3);
};
struct __declspec(align(16)) RayData {
    float x; float y; float z; float w;
    float endX; float endY; float endZ; float endW;
    float extraX; float extraY; float extraZ; float extraW;
};
struct Input {
    RayData base;
    float f30;
    float f34;
};
struct Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    float unk24;

    void hkpSampledHeightFieldShape_castRayInternal(RayData* data, void* arg2, hkBool arg3, float arg4, void* arg5);
    void hkpSampledHeightFieldShape_castSphere(Input* input, void* arg2, void* arg3);
};
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
struct SampledHeightField : hkpSampledHeightFieldShape {
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual float getHeightAt(int x, int z);
    void hkpSampledHeightFieldShape_getAabbImpl(hkUlong transform, float tolerance, hkUlong aabb);
};
void __cdecl hkAabbUtil_calcAabb_00d26230(hkUlong, const hkVector4&, const hkVector4&, float, hkUlong);

inline void* operator new(unsigned int,void* p) throw() { return p; }
extern "C" { LocalM128 _mm_set_ps(float,float,float,float); LocalM128 _mm_setr_ps(float,float,float,float); LocalM128 _mm_mul_ps(LocalM128,LocalM128); LocalM128 _mm_load_ss(const float*); LocalM128 _mm_shuffle_ps(LocalM128,LocalM128,int); }



struct hkVec4
{
    LocalM128 m_vComponents;
    void set(float x, float y, float z, float w = 0.0f)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    void operator=(const hkVec4& v) { m_vComponents = v.m_vComponents; }
    void mul4(const hkVec4& a) { LocalM128 components = _mm_load_ps(m_vComponents.m128_f32); m_vComponents = _mm_mul_ps(components, a.m_vComponents); }
    void setMul4(float r, const hkVec4& a) { LocalM128 s = _mm_load_ss(&r); LocalM128 t = _mm_shuffle_ps(s, s, 0); m_vComponents = _mm_mul_ps(t, a.m_vComponents); }
    float& operator()(int i) { return m_vComponents.m128_f32[i]; }
    const float& operator()(int i) const { return m_vComponents.m128_f32[i]; }
};

float Object_ComputeBisectionMidpoint() throw();

enum HeightFieldType { HEIGHTFIELD_STORAGE = 0, HEIGHTFIELD_COMPRESSED = 1, HEIGHTFIELD_USER = 2 };

template <typename ENUM, typename STORAGE>
struct hkEnumT
{
    hkEnumT() {}
    hkEnumT(ENUM e) { m_kStorage = static_cast<STORAGE>(e); }
    void operator=(ENUM e) { m_kStorage = static_cast<STORAGE>(e); }
    STORAGE m_kStorage;
};

struct hkSampledHeightFieldShapeCinfo
{
    hkVec4 m_vScale;
    int m_iXResolution;
    int m_iZResolution;
    float m_fMinHeight;
    float m_fMaxHeight;
    char m_bUseProjectionBasedHeight;
};

struct hkShapeBase : hkRefObj_hkpsampledheightfieldshape
{
    hkShapeBase(unsigned int type) : m_ulUserData(0), m_type(type) {}
    unsigned long m_ulUserData;
    unsigned int m_type;
};

struct hkHeightFieldBase : hkShapeBase
{
    hkHeightFieldBase(unsigned int type, void* vtable) : hkShapeBase(type) { m_vtbl = vtable; }
};

extern void* HeightField_vtable[];

struct HeightField : hkHeightFieldBase
{
    __forceinline HeightField(const hkSampledHeightFieldShapeCinfo& ci, HeightFieldType hfType);
    ~HeightField();
    HeightField* ProcessAndReturnValue_00d248a0(const hkSampledHeightFieldShapeCinfo& ci, HeightFieldType hfType);
    int m_iXResolution;
    int m_iZResolution;
    float m_fHeightScale;
    char m_bUseProjectionBasedHeight;
    hkEnumT<HeightFieldType, unsigned char> m_ucHeightFieldType;
    hkVec4 m_kHeightScaleVector;
    hkVec4 m_kInverseScale;
    hkVec4 m_kOffset;
    hkVec4 SetCenterPosition;
};

__forceinline HeightField::HeightField(const hkSampledHeightFieldShapeCinfo& ci, HeightFieldType hfType)
    : hkHeightFieldBase(13, HeightField_vtable), m_ucHeightFieldType(hfType)
{
    m_iXResolution = ci.m_iXResolution;
    m_iZResolution = ci.m_iZResolution;
    m_bUseProjectionBasedHeight = ci.m_bUseProjectionBasedHeight;

    SetCenterPosition.set(ci.m_iXResolution - 1.0f, ci.m_fMaxHeight - ci.m_fMinHeight, ci.m_iZResolution - 1.0f);
    SetCenterPosition.mul4(ci.m_vScale);

    if (ci.m_fMinHeight > ci.m_fMaxHeight)
    {
        m_fHeightScale = -1.0f;
        SetCenterPosition(1) = -1.0f;
    }
    else
    {
        m_fHeightScale = (ci.m_fMaxHeight + ci.m_fMinHeight) * 0.5 * ci.m_vScale(1);
    }

    m_kHeightScaleVector = ci.m_vScale;
    m_kInverseScale.set(1.0f / ci.m_vScale(0), 1.0f / ci.m_vScale(1), 1.0f / ci.m_vScale(2));

    hkVec4 offset;
    offset.setMul4(Object_ComputeBisectionMidpoint(), m_kHeightScaleVector);
    offset.m_vComponents.m128_f32[1] = 0.0f;
    m_kOffset = offset;
}

// @fnv 0x00d248a0
// src: GUESS 0x00d248a0 (confidence: low)
HeightField* HeightField::ProcessAndReturnValue_00d248a0(const hkSampledHeightFieldShapeCinfo& ci, HeightFieldType hfType) { __assume(this != 0); return new(this) HeightField(ci,hfType); }
