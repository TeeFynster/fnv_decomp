
// src/havok/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00d24670 FUN_00d24670: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; unsigned __int64 m128_u64[2]; } __m128, LocalM128;

#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkBoolResult.h"
#define FNV64_HKVECTOR4_OWN_COPY
#include "../../../../../../../include/hkpSampledHeightFieldShape.h"

__forceinline hkVector4::hkVector4(const hkVector4& vector)
{
    for (int i = 0; i < 4; ++i)
        reinterpret_cast<unsigned int*>(this)[i] = reinterpret_cast<const unsigned int*>(&vector)[i];
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

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

// @fnv 0x00d24670
// src: GUESS 0x00d24670 (confidence: low)
void Cls_00d24670::UpdateState_00d24670(int x, int y, float fx, float fy, LocalM128* nrm, float* height, int* flag)
{
    *nrm = _mm_load_ps1(&DAT_01012068);
    bool flip;
    getFlip(flip);
    if (flip) {
        float h00 = getH(x, y);
        float h11 = getH(x + 1, y + 1);
        if (fx > fy) {
            float h10 = getH(x + 1, y);
            const float dx = h10 - h00;
            const float dy = h11 - h10;
            *height = h00 + dy * fy + dx * fx;
            nrm->m128_f32[0] = -dx;
            nrm->m128_f32[2] = -dy;
            *flag = 1;
        } else {
            float h01 = getH(x, y + 1);
            const float dx = h11 - h01;
            const float dy = h01 - h00;
            *height = h00 + dy * fy + dx * fx;
            nrm->m128_f32[0] = -dx;
            nrm->m128_f32[2] = -dy;
            *flag = 0;
        }
    } else {
        float h10 = getH(x + 1, y);
        float h01 = getH(x, y + 1);
        if (fx + fy > 1.0) {
            float h11 = getH(x + 1, y + 1);
            const float dx = h11 - h01;
            const float dy = h11 - h10;
            *height = h10 + dy * fy + dx * (fx - 1.0);
            nrm->m128_f32[0] = -dx;
            nrm->m128_f32[2] = -dy;
            *flag = 1;
        } else {
            float h00 = getH(x, y);
            const float dx = h10 - h00;
            const float dy = h01 - h00;
            *height = h00 + dy * fy + dx * fx;
            nrm->m128_f32[0] = -dx;
            nrm->m128_f32[2] = -dy;
            *flag = 0;
        }
    }
}

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

// These call/return flags use the nontrivial byte-copy ABI of shared hkBoolResult.
struct FUN_00d24b50_Obj {
    void __thiscall hkpSampledHeightFieldShape_castRayInternal(void* object, int flags, hkBoolResult flag2, float f, hkCollectorD260* collector);
};

class hkShapeD260 : public FUN_00d24b50_Obj {
public:
    hkBoolResult __thiscall hkpSampledHeightFieldShape_castRayImpl(void* object, hkInfoD260* info);
};

// Runs FUN_00d24b50 on object with a collector built from info and returns whether the collector recorded a hit.
// @fnv 0x00d26080
// src: HAVOK_LIB 0x00d26080
hkBoolResult __thiscall hkShapeD260::hkpSampledHeightFieldShape_castRayImpl(void* object, hkInfoD260* info) {
    hkCollectorD260 collector(info);
    this->hkpSampledHeightFieldShape_castRayInternal(object, 0, hkBoolResult(false), 0.0f, &collector);
    hkBoolResult result;
    result.m_cBooleanValue = static_cast<char>(collector.m_bHasHit);
    return result;
}

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

// If a1's f10 is below f04, stores it in f04, copies v00, f10 and i14 into *p0c, sets p0c's slot at m_idx40 to -1, and sets b08 to 1.
// @fnv 0x00d261b0
void S00d261b0_cls::UpdateMinValue(int a0, int a1)
{
    S00d261b0_Elem* a = (S00d261b0_Elem*)a1;
    if (a->f10 < f04) {
        f04 = a->f10;
        p0c->v00 = a->v00;
        p0c->f10 = a->f10;
        (*(S00d261b0_Elem* volatile*)&p0c)->i14 = a->i14;
        p0c->m_slots[p0c->m_idx40] = -1;
        b08 = 1;
    }
}

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

struct Host {
    void hkpSampledHeightFieldShape_castRayInternal(int a1, int a2, hkBoolResult v, float f, Local12* pLocal);
    void hkpSampledHeightFieldShape_castRayWithCollectorImpl(int a1, int a2, const Arg3* a3);
};

// Builds a local record from DAT_010ce310 and a3 (its float and pointer), then calls FUN_00d24b50 with a1, a2, a false hkBoolResult, 0.0f and that record.
// @fnv 0x00d260d0
// src: HAVOK_LIB 0x00d260d0
void Host::hkpSampledHeightFieldShape_castRayWithCollectorImpl(int a1, int a2, const Arg3* a3)
{
    Local12 local;
    local.m_00 = &DAT_010ce310;
    local.m_04 = a3->m_04;
    local.m_08 = a3;
    hkpSampledHeightFieldShape_castRayInternal(a1, a2, hkBoolResult(false), 0.0f, &local);
}

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

    void hkpSampledHeightFieldShape_castRayInternal(RayData* data, void* arg2, hkBoolResult arg3, float arg4, void* arg5);
    void hkpSampledHeightFieldShape_castSphere(Input* input, void* arg2, void* arg3);
};

// Copies the input ray, offsets its Y and endY by a signed value, and calls FUN_00d24b50 with the modified ray.
// @fnv 0x00d26120
// src: HAVOK_LIB 0x00d26120
void Obj::hkpSampledHeightFieldShape_castSphere(Input* input, void* arg2, void* arg3) {
    float a = input->f30;
    RayData local = input->base;

    if (this->unk24 > 0.0f)
        a = -a;

    local.y += a;
    local.endY += a;

    this->hkpSampledHeightFieldShape_castRayInternal(&local, arg2, true, input->f34, arg3);
}

extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);

__declspec(align(16)) const float halfScale[4] = {0.5f, 0.5f, 0.5f, 0.5f};

struct SampledHeightField : hkpSampledHeightFieldShape {
    void hkpSampledHeightFieldShape_getAabbImpl(hkUlong transform, float tolerance, hkUlong aabb);
};

void __cdecl hkAabbUtil_calcAabb_00d26230(hkUlong, const hkVector4&, const hkVector4&, float, hkUlong);

// If the cached height range is not yet set, scans all heights to compute it; then calls FUN_00d26230 with the box center and half extents, tolerance and aabb.
// @fnv 0x00d249f0
// src: HAVOK_SRC 0x00d249f0
void SampledHeightField::hkpSampledHeightFieldShape_getAabbImpl(hkUlong transform, float tolerance, hkUlong aabb)
{
    float fMinHeight = GetHeightAtGridPoint(0, 0);
    float maximum = fMinHeight;
    if (SetCenterPosition.y < 0.0f) {
        for (int x = 0; x < m_iXResolution; ++x) {
            for (int z = 0; z < m_iZResolution; ++z) {
                float height = GetHeightAtGridPoint(x, z);
                fMinHeight = fMinHeight < height ? fMinHeight : height;
                maximum = maximum > height ? maximum : height;
            }
        }
        fMinHeight *= m_kHeightScaleVector.y;
        maximum *= m_kHeightScaleVector.y;
        float oldMinimum = fMinHeight;
        fMinHeight = fMinHeight < maximum ? fMinHeight : maximum;
        maximum = maximum < oldMinimum ? oldMinimum : maximum;
        m_fHeightScale = (fMinHeight + maximum) * 0.5;
        SetCenterPosition.y = maximum - fMinHeight;
    }
    __declspec(align(16)) hkVector4 center;
    *reinterpret_cast<LocalM128*>(&center) = _mm_mul_ps(*reinterpret_cast<const LocalM128*>(&SetCenterPosition), *reinterpret_cast<const LocalM128*>(&halfScale));
    __declspec(align(16)) hkVector4 halfExtents = center;
    center.y = m_fHeightScale;
    hkAabbUtil_calcAabb_00d26230(transform, halfExtents, center, tolerance, aabb);
}
