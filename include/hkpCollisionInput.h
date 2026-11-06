#pragma once

#include <stddef.h>
#include "hkPadSpu.h"
#include "hkVector4_S.h"

class hkpCollisionDispatcher;
class hkpCollisionFilter;
class hkpConvexListFilter;

class hkpCollisionInput
{
public:
    hkpCollisionInput(const hkpCollisionInput& other);

    float getTolerance() const { return m_fScalar; }

    hkPadSpu<hkpCollisionDispatcher*> m_pCollisionDispatcher;
    hkPadSpu<int> m_collisionQuality;
    hkPadSpu<float> m_fScalar;
    hkPadSpu<const hkpCollisionFilter*> m_iFilter;
    hkPadSpu<const hkpConvexListFilter*> m_pConvexListCollisionFilter;
    unsigned int m_bCreatePredictiveAgents;
    unsigned int unk18;
    unsigned int unk1C;

    struct AabbBoundsAndScale
    {
        static void* __cdecl operator new(size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(size_t n, void* p);
        static void* __cdecl operator new[](size_t n, void* p);
        static void __cdecl operator delete(void* p, void* placement);
        static void __cdecl operator delete[](void* p, void* placement);

        class CommandArgument;

        hkVector4_S m_kAabbMin;
        hkVector4_S m_kAabbMaximum;
        hkVector4_S m_kAabbScale;
    };

    AabbBoundsAndScale m_aiValues;
};
