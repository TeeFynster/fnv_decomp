#pragma once

#include <cstddef>
#include "hkpShape.h"
#include "hkaAnimation.h"
#include "hkVector4.h"

class hkpMultiRayShape : public hkpShape
{
public:
    static const ClassMemberDescriptor Members[];

    struct Ray
    {
        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* placement);
        static void __cdecl operator delete[](void* p, void* placement);

        class CommandArgument;
        static const ClassMemberDescriptor Members[];
        static const hkClass& __cdecl staticClass();
        struct DefaultStruct;

        hkVector4 m_kRayStart;
        hkVector4 m_kRayEnd;
    };

    hkpMultiRayShape(const Ray* rays, int nRays, hkReal rayPenetrationDistance = 0.0f);
    hkpMultiRayShape(FinishingFlag flag);

    const hkArray<Ray>& getRays() const { return m_kRays; }
    hkReal getRayPenetrationDistance() const { return m_fRayRadius; }

    hkArray<Ray> m_kRays;
    hkReal m_fRayRadius;
};
