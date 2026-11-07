
// src/havok/animation/animation/mapper/hkaskeletonmapper.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/mapper/hkaskeletonmapper.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "../../../../../include/hkError.h"
#include "../../../../../include/hkOstream.h"
#include "../../../../../include/hkaBone.h"
// Retain the unit's intrinsic declarations when the shared math headers include xmmintrin.h.
#define _INCLUDED_MM2
// Exe 0x00ce2ae0 ValidateRagdollMapping: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sqrt_ss(LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" void _mm_store_ss(float*, LocalM128);

#include "../../../../../include/hkQsTransform.h"
#include "../../../../../include/hkaSkeletonMapperData.h"

struct FUN_00ce4ab0Allocator
{
    virtual void FUN_00ce4ab0Unused1() = 0;
    virtual void FUN_00ce4ab0Unused2() = 0;
    virtual void FUN_00ce4ab0Free(void* object, unsigned short size) = 0;
};

struct FUN_00ce4ab0Router
{
    unsigned char pad[16];
    FUN_00ce4ab0Allocator* allocator;
};

FUN_00ce4ab0Router* _D1A0E0GetMemoryRouter();
void UpdateFields_00ce29e0();

struct FUN_00ce4ab0Class
{
    FUN_00ce4ab0Class* Destroy(unsigned int flags);
};

// Calls FUN_00ce29e0, then if flags has bit 0 set frees this through the memory router allocator using the size at offset 4, and returns this.
// @fnv 0x00ce4ab0
FUN_00ce4ab0Class* FUN_00ce4ab0Class::Destroy(unsigned int flags)
{
    UpdateFields_00ce29e0();

    if (flags & 1)
    {
        FUN_00ce4ab0Router* router = _D1A0E0GetMemoryRouter();
        unsigned short size = *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 4);

        router->allocator->FUN_00ce4ab0Free(this, size);
    }

    return this;
}

class hkaSkeletonMapperDataSimpleMapping
{
    public:
    hkInt16 m_sBoneA;
    hkInt16 m_sBoneB;
    int unk04;
    int unk08;
    int unk0c;
    hkQsTransform m_kAFromBTransform;
};

static inline float getTranslationError(const hkVector4& t)
{
    LocalM128 v = t.m_vComponents;
    LocalM128 v2 = _mm_mul_ps(v, v);
    LocalM128 v1 = _mm_shuffle_ps(v2, v2, 0x55);
    LocalM128 v0 = _mm_shuffle_ps(v2, v2, 0xaa);
    v1 = _mm_add_ss(v1, v2);
    v0 = _mm_add_ss(v0, v1);
    v0 = _mm_sqrt_ss(v0);
    float len;
    _mm_store_ss(&len, v0);
    return len;
}

// For ragdoll mappings, warns if locked-translation bones are misaligned or if no bone in skeleton B has translation locked.
// @fnv 0x00ce2ae0
void ValidateRagdollMapping(hkaSkeletonMapperData* apMapperData)
{
    if (apMapperData->m_eMappingType == hkaSkeletonMapperData::HK_RAGDOLL_MAPPING)
    {
        for (int iIndex = 0; iIndex < apMapperData->m_kSimpleMappings.m_iElementCount; ++iIndex)
        {
            const hkaSkeletonMapperDataSimpleMapping& mapping = apMapperData->m_kSimpleMappings.m_data[iIndex];
            const hkaBone& boneA = apMapperData->m_pSkeletonA->m_kBones.m_data[mapping.m_sBoneA];
            const hkaBone& boneB = apMapperData->m_pSkeletonB->m_kBones.m_data[mapping.m_sBoneB];

            if (boneB.m_bLockTranslation.m_cBooleanValue)
            {
                float len = getTranslationError(mapping.m_kAFromBTransform.m_vTranslation);
                if (len > 0.01f)
                {
                    int buf[128];
                    // Explicit lifetime preserves the original absence of exception unwind cleanup.
                    int streamStorage[sizeof(hkOstream) / sizeof(int)];
                    ::new (streamStorage) hkOstream(static_cast<void*>(buf), sizeof(buf));
                    hkOstream& str = *reinterpret_cast<hkOstream*>(streamStorage);
                    str.ProcessAndReturnValue_00cc01c0("Bones A:")
                        .WriteName(boneA.m_name)
                        .ProcessAndReturnValue_00cc01c0(" and B:")
                        .WriteName(boneB.m_name)
                        .ProcessAndReturnValue_00cc01c0(" are not fully aligned (error :")
                        .WriteFloat(len)
                        .ProcessAndReturnValue_00cc01c0(").");
                    hkError::s_instance->message(1, 0xabbaefbf, (char*)buf, ".\\Mapper\\hkaSkeletonMapper.cpp", 499);
                    str.hkOstream::~hkOstream();
                }
            }
        }
    }

    if (apMapperData->m_eMappingType == hkaSkeletonMapperData::HK_RAGDOLL_MAPPING)
    {
        hkaSkeleton* skeletonB = apMapperData->m_pSkeletonB;
        for (int iIndex = 0; iIndex < skeletonB->m_kBones.m_iElementCount; ++iIndex)
        {
            if (skeletonB->m_kBones.m_data[iIndex].m_bLockTranslation.m_cBooleanValue)
                return;
        }

        int buf[128];
        int streamStorage[sizeof(hkOstream) / sizeof(int)];
        ::new (streamStorage) hkOstream(static_cast<void*>(buf), sizeof(buf));
        hkOstream& str = *reinterpret_cast<hkOstream*>(streamStorage);
        str.ProcessAndReturnValue_00cc01c0(
            "None of the bones in skeleton have translations locked - did you forget to lock translations ?.");
        hkError::s_instance->message(1, 0xabba77a5, (char*)buf, ".\\Mapper\\hkaSkeletonMapper.cpp", 521);
        str.hkOstream::~hkOstream();
    }
}

#include <math.h>
// Clamps the input to the domain of asin and returns the result, substituting the sign of pi/2 when the magnitude is at least 1.0f.
// @fnv 0x00ce0c40
float ClampAsin(float angle)
{
    float original = angle;
    angle = fabsf(angle);
    if (angle >= 1.0f)
    {
        if (original > 0.0f)
            angle = 1.5707963705062866f;
        else
            angle = -1.5707963705062866f;
    }
    else
    {
        return asinf(original);
    }
    return angle;
}
