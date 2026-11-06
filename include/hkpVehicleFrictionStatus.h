#pragma once

#include <cstddef>

struct ClassMemberDescriptor;
class hkClass;

class hkpVehicleFrictionStatus
{
public:
    struct AxisStatus
    {
        static const ClassMemberDescriptor Members[];
        static const hkClass& __cdecl staticClass();
        struct DefaultStruct;
        class CommandArgument;

        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* place);
        static void __cdecl operator delete[](void* p, void* place);

        float m_fAxisStatusMetric1;
        float m_fAxisStatusMetric2;
        float m_fAxisStatusMetric3;
        float m_fAxisStatusMetric4;
        float m_fAxisStatusMetric5;
        float m_fAxisStatusMetric6;
        float m_fAxisStatusMetric7;
        float m_fAxisStatusMetric8;
        float m_fAxisStatusMetric9;

        void init();
    };

    AxisStatus m_kAxisEndPoints[2];
};
