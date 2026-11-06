#pragma once

#include <cstddef>
#include "hkReferencedObject.h"
#include "hkBool.h"

class hkpConstraintInstance;
struct hkpConstraintDataInfo;
struct RuntimeInfoD4D;

class hkpConstraintData : public hkReferencedObject
{
public:
    enum ConstraintType
    {
        CONSTRAINT_TYPE_BALLANDSOCKET = 0,
        CONSTRAINT_TYPE_HINGE = 1,
        CONSTRAINT_TYPE_LIMITEDHINGE = 2,
        CONSTRAINT_TYPE_POINTTOPATH = 3,
        CONSTRAINT_TYPE_PRISMATIC = 6,
        CONSTRAINT_TYPE_RAGDOLL = 7,
        CONSTRAINT_TYPE_STIFFSPRING = 8,
        CONSTRAINT_TYPE_WHEEL = 9,
        CONSTRAINT_TYPE_GENERIC = 10,
        CONSTRAINT_TYPE_CONTACT = 11,
        CONSTRAINT_TYPE_BREAKABLE = 12,
        CONSTRAINT_TYPE_MALLEABLE = 13,
        CONSTRAINT_TYPE_POINTTOPLANE = 14,
        CONSTRAINT_TYPE_PULLEY = 15,
        CONSTRAINT_TYPE_ROTATIONAL = 16,
        CONSTRAINT_TYPE_HINGE_LIMITS = 18,
        CONSTRAINT_TYPE_RAGDOLL_LIMITS = 19,
        CONSTRAINT_TYPE_CUSTOM = 20,
        BEGIN_CONSTRAINT_CHAIN_TYPES = 100,
        CONSTRAINT_TYPE_STIFF_SPRING_CHAIN = 100,
        CONSTRAINT_TYPE_BALL_SOCKET_CHAIN = 101,
        CONSTRAINT_TYPE_POWERED_CHAIN = 102
    };

    struct ConstraintInfo;

    hkpConstraintData() throw();
    hkpConstraintData(FinishingFlag f);
    virtual ~hkpConstraintData() throw();
    static void* __cdecl operator new(std::size_t nbytes);
    void FUN_00c90510() const throw();
    void removeReference() const throw();
    void removeReference() throw();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual int getType() const throw();
    virtual void GetConstraintRuntimeInfo(hkBool wantRuntime, RuntimeInfoD4D& infoOut) const throw();
    virtual void v0A();
    virtual void AddInstance(hkpConstraintInstance* instance, void* runtime, unsigned int runtimeSize);
    virtual void v0C();
    virtual unsigned char* WantsRuntime(unsigned char* result);
    virtual void v0E();
    virtual void PopulateInfo(hkpConstraintDataInfo& infoOut) const;

    void v08();
    __forceinline void GetRuntimeInfo(unsigned int wantRuntime, void* runtimeInfo)
    {
        reinterpret_cast<void (__thiscall*)(hkpConstraintData*, unsigned int, void*)>(
            (*reinterpret_cast<void***>(this))[9])(this, wantRuntime, runtimeInfo);
    }

    unsigned long m_ulUserData;

    friend class ConstraintInstance;
};
