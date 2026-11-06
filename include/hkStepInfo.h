#pragma once
#include <stddef.h>
#include "hkPadSpu.h"   // Havok 7.1 hkPadSpu<T> (hkBaseTypes.h:692; PC: a bare T m_storage)

// Havok 7.1 Common/Base/Types/Physics/hkStepInfo.h: four hkPadSpu members, the first HK_ALIGN16, sizeof == 16.
// Havok names: m_startTime, m_endTime, m_deltaTime, m_invDeltaTime (the units use the names below).
// HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR: operator new/delete are declared here; a unit that allocates one defines
// them out of class (__forceinline, thread-memory heap), as the units did.
class hkStepInfo
{
  public:
    void* __cdecl operator new(size_t nbytes);
    void __cdecl operator delete(void* p);

    hkStepInfo() {}
    void set(float startTime, float endTime)
    {
        m_uiStartTime = startTime;
        m_fEndTime = endTime;
        m_fTimeStep = endTime - startTime;
        m_fInverseDeltaTime = m_fTimeStep == 0.0f ? 0.0f : 1.0f / m_fTimeStep;
    }
    hkStepInfo(float startTime, float endTime) { set(startTime, endTime); }

  public:
    __declspec(align(16)) hkPadSpu<float> m_uiStartTime;   // hkPadSpu<hkTime> m_startTime
    hkPadSpu<float> m_fEndTime;                            // hkPadSpu<hkTime> m_endTime
    hkPadSpu<float> m_fTimeStep;                           // hkPadSpu<hkReal> m_deltaTime
    hkPadSpu<float> m_fInverseDeltaTime;                   // hkPadSpu<hkReal> m_invDeltaTime
};
