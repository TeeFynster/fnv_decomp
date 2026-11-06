#pragma once

#include <cstddef>
#include "hkpConstraintData.h"
#include "hkpSetLocalRotationsConstraintAtom.h"

typedef float hkReal;

#include "hkpAngLimitConstraintAtom.h"

#include "hkp2dAngConstraintAtom.h"

class __declspec(align(16)) hkpHingeLimitsDataAtoms
{
public:
    enum Axis
    {
        AXIS_AXLE = 0,
        AXIS_PERP_TO_AXLE_1 = 1,
        AXIS_PERP_TO_AXLE_2 = 2
    };

    class CommandArgument;
    struct DefaultStruct;
    static const ClassMemberDescriptor Members[];
    static const hkClass& __cdecl staticClass();

    static void* __cdecl operator new(std::size_t nbytes);
    static void __cdecl operator delete(void* p);
    static void* __cdecl operator new(std::size_t n, void* p);
    static void* __cdecl operator new[](std::size_t n, void* p);
    static void __cdecl operator delete(void* p, void* placement);
    static void __cdecl operator delete[](void* p, void* placement);

    hkpHingeLimitsDataAtoms();
    hkpHingeLimitsDataAtoms(FinishingFlag f);
    const hkpConstraintAtom* getAtoms() const;
    int getSizeOfAllAtoms() const;

    hkpSetLocalRotationsConstraintAtom m_kLocalRotations;
    hkpAngLimitConstraintAtom m_kAngularLimit;
    hkp2dAngConstraintAtom m_kTwoDimensionalAngular;
    char unk84[0xC];
};

class hkpHingeLimitsData : public hkpConstraintData
{
public:
    typedef hkpHingeLimitsDataAtoms Atoms;

    static const ClassMemberDescriptor Members[];

    hkpHingeLimitsData(FinishingFlag f);
    hkReal getMaxAngularLimit() const;
    hkReal getMinAngularLimit() const;

    char padC[0x4];
    hkpHingeLimitsDataAtoms m_kBridgeAtoms;
};
