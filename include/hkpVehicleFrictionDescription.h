#pragma once

#include <cstddef>

struct ClassMemberDescriptor;
class hkClass;

class hkpVehicleFrictionDescription
{
public:
    struct AxisDescription
    {
        class CommandArgument;
        struct DefaultStruct;

        static const ClassMemberDescriptor Members[];
        static const hkClass& __cdecl staticClass();

        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* place);
        static void __cdecl operator delete[](void* p, void* place);

        float m_afFrictionCurveSamples[16];
        float m_fAxisFrictionTuning1;
        float m_fAxisFrictionTuning2;
        float m_fAxisFrictionTuning3;
        float m_fAxisFrictionTuning4;
        float m_fAxisFrictionTuning5;
        float m_fAxisFrictionTuning6;
        float m_fAxisFrictionTuning7;
        float m_fAxisFrictionTuning8;
        float m_fAxisFrictionTuning9;
    };

    float m_fFrictionEqualizer;
    float m_fMaxVelocityForPositionalFriction;
    AxisDescription m_kAxisDescriptions[2];
};
