
#include "nipsysboundupdatemodifier_decls.h"

inline NiBound::NiBound()
{
}

inline void* NiBound::operator new[](size_t size)
{
    return g_memoryManager.Allocate(size);
}

inline void NiBound::SetCenterAndRadius(const NiPoint3& center, float radius)
{
    m_kCenter = center;
    m_fRadius = radius;
}

// @fnv 0x00c2d720
void NiPSysBoundUpdateModifier::SetUpdateSkipCounter(int iUpdateSkip)
{
    m_usUpdateSkip = (short)iUpdateSkip;
    g_memoryManager.Deallocate(m_pkBounds);
    int iSkip = (short)iUpdateSkip;
    short sNumBounds = iSkip > 1 ? iSkip : 1;
    m_pkBounds = new NiBound[sNumBounds];
    for (int i = 0; i < sNumBounds; ++i) {
        m_pkBounds[i].SetCenterAndRadius(NiPoint3_ZERO, 0.0f);
    }
}
