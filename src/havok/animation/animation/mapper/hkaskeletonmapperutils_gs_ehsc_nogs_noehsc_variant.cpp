#include "../../../../../include/hkError.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkOstream.h"
#include "../../../../../include/hkStringPtr.h"
#include "../../../../../include/hkaBone.h"
#include "../../../../../include/hkaSkeletonMapperData.h"

// src/havok/animation/animation/mapper/hkaskeletonmapperutils_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/animation/mapper/hkaskeletonmapperutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/animation/mapper/hkaskeletonmapperutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/mapper/hkaskeletonmapperutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct CE5F90QsTransform
{
    float m_vTranslation[4];
    float m_rotation[4];
    float m_vScale[4];
};
void __cdecl hkaSkeletonMapperUtils_computeMappingTransform(CE5F90QsTransform* out, const CE5F90QsTransform* a, const CE5F90QsTransform* b, int mode,
                          float weightA, float weightB);
void __cdecl hkaSkeletonMapperUtils_computeMappingTransform_00ce5f90(CE5F90QsTransform* out, const CE5F90QsTransform* poseA, short boneA,
                          const CE5F90QsTransform* poseB, short boneB, int mode, float weightA, float weightB);

extern "C" void _ReadBarrier();
template <typename T> T& GetElement(hkArray<T>& array, int i)
{
    return array.m_data[i];
}
struct __declspec(align(16)) MapperQsTransform
{
    float translation[4];
    float rotation[4];
    float scale[4];
};
struct hkaSkeletonMapperDataSimpleMapping
{
    short m_sBoneA;
    short m_sBoneB;
    MapperQsTransform transform;
};
extern hkError* DAT_01268360;
// @fnv 0x00ce5840
// src: HAVOK_LIB 0x00ce5840
int __cdecl hkaSkeletonMapperUtils_lockTranslationsAutomatically(hkaSkeletonMapperData* mapping)
{
    int i = 0;
    int count = mapping->m_kSimpleMappings.m_iElementCount;
    hkaSkeleton* skelA = mapping->m_pSkeletonA;
    int numBonesA = skelA->m_kBones.m_iElementCount;
    hkaSkeleton* skelB = mapping->m_pSkeletonB;
    int numBonesB = skelB->m_kBones.m_iElementCount;
    int rootA = numBonesA;
    _ReadBarrier();
    int rootB;
    if (count > 0)
    {
        do
        {
            hkaSkeletonMapperDataSimpleMapping* current = &GetElement(mapping->m_kSimpleMappings, i);
            if (current->m_sBoneA < rootA)
            {
                rootB = current->m_sBoneB;
                if (rootB < numBonesB)
                {
                    rootA = current->m_sBoneA;
                    goto found;
                }
                else
                {
                    char buf[512];
                    hkOstream os(buf, 512);
                    os << "Invalid mapping - cannot lock translation based on it";
                    DAT_01268360->message(1, 0xabba782a, buf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 767);
                    return 1;
                }
            }
        } while (++i < count);
        rootB = numBonesB;
    }
    else
    {
        rootB = numBonesB;
    }
found:
    if (rootA == skelA->m_kBones.m_iElementCount)
    {
        char buf[512];
        hkOstream os(buf, 512);
        os << "Invalid mapping - cannot lock translations based on it";
        DAT_01268360->message(1, 0xabba782a, buf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 776);
        return 1;
    }
    DAT_01268360->beginSection(0x87e5654e, "lockTranslationsAutomatically");
    {
        char buf[512];
        hkOstream os(buf, 512);
        os << "Locking translations in skeleton " << skelA->m_name << " from bone " << GetElement(skelA->m_kBones, rootA).m_name;
        DAT_01268360->message(0, -1, buf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 784);
    }
    for (int i = 0; i < skelA->m_kBones.m_iElementCount; ++i)
    {
        GetElement(skelA->m_kBones, i).m_bLockTranslation = (i > rootA);
    }
    {
        char buf[512];
        hkOstream os(buf, 512);
        os << "Locking translations in skeleton " << skelB->m_name << " from bone " << GetElement(skelB->m_kBones, rootB).m_name;
        DAT_01268360->message(0, -1, buf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 793);
    }
    for (int i = 0; i < skelB->m_kBones.m_iElementCount; ++i)
    {
        GetElement(skelB->m_kBones, i).m_bLockTranslation = (i > rootB);
    }
    DAT_01268360->endSection();
    return 0;
}
