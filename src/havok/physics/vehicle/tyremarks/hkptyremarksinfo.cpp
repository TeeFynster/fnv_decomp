
// src/havok/physics/vehicle/tyremarks/hkptyremarksinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/tyremarks/hkptyremarksinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkStatisticsCollector.h"
#include "../../../../../include/hkVector4.h"

int __cdecl hkStatisticsCollector_getAllocatedSize(const void* pvChunk, int iNumBytes) throw();

// The shared collector has no addArray template; keep its array reporting helper here.
template <class T>
__forceinline void addArray(hkStatisticsCollector* collector, const char* pcName, const hkArray<T>& kArray)
{
    if ((kArray.m_iCapacityState & 0x80000000) == 0 || collector->m_reportInplaceAllocations)
    {
        const T* pData = kArray.m_data;
        int iAllocated = hkStatisticsCollector_getAllocatedSize(pData, kArray.getCapacity() * sizeof(T));
        collector->AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
    }
}

struct hkRayE39E
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
};

class hkPointSetE39E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkArray<hkRayE39E> m_kPoints;
};

class hkObjE39E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkArray<hkPointSetE39E*> m_kPointSets;

    void hkpTyremarksInfo_calcContentStatistics(hkStatisticsCollector* pkCollector, const hkClass* pkClass) const throw();
};

// For each point set in the array, adds its ray array to the statistics collector under the name "Points".
// @fnv 0x00e39ee0
// src: HAVOK_LIB 0x00e39ee0
void hkObjE39E::hkpTyremarksInfo_calcContentStatistics(hkStatisticsCollector* pkCollector, const hkClass* pkClass) const throw()
{
    for (int i = 0; i < m_kPointSets.GetLogicalSize(); i++)
        addArray(pkCollector, "Points", m_kPointSets.m_data[i]->m_kPoints);
}

struct hkSampleE39F
{
    hkVector4 m_vContactPosition;
    hkVector4 m_fVelocity;

    float GetUnk1C_00e39e80() const;
};

// src: GUESS 0x00e39e80 (confidence: low)
__declspec(noinline) float hkSampleE39F::GetUnk1C_00e39e80() const
{
    return m_fVelocity.m_vComponents.m128_f32[3];
}

class hkSampleRingE39F
{
  public:
    int unk00;
    int unk04;
    int m_pFirstNode;
    int m_pRayCursor;
    hkSampleE39F* m_samples;

    void addTyremarkPoint(const hkSampleE39F& sample);
};

// Copies sample into the slot at m_pFirstNode and advances it with wraparound, unless the sample and the previous slot both give 0 from FUN_00e39e80.
// @fnv 0x00e39f50
// src: XBOX_PDB 0x00e39f50
void hkSampleRingE39F::addTyremarkPoint(const hkSampleE39F& sample)
{
    if (sample.GetUnk1C_00e39e80() == 0.0f && m_samples[(m_pFirstNode + m_pRayCursor - 1) % m_pRayCursor].GetUnk1C_00e39e80() == 0.0f)
        return;
    hkSampleE39F& dst = m_samples[m_pFirstNode];
    dst.m_vContactPosition = sample.m_vContactPosition;
    dst.m_fVelocity = sample.m_fVelocity;
    m_pFirstNode = (m_pFirstNode + 1) % m_pRayCursor;
}
