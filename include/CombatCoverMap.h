#pragma once

#include "NiTMap.h"

class ReservedCoverLocation;
class CoverMapValue;
class CoverMapOwnerEx;

template <class T> struct CoverMapPointer
{
    T* m_pObject;

    ~CoverMapPointer();
    operator T*() const;
};

// RTTI: CombatCoverMap : NiTMap<unsigned int,ReservedCoverLocation *>, vftable 0x0108d0e4 (destructor 0x00983100).
class CombatCoverMap : public NiTMap<unsigned int, ReservedCoverLocation*>
{
public:
    class ReadWriteLock
    {
    public:
        volatile unsigned int m_uiLockState;
        unsigned int m_uiWriterThreadId;
    };

    CoverMapPointer<CoverMapOwnerEx> m_spOwner;
    ReadWriteLock Lock;


    void* __thiscall DestroyAndFree(unsigned int flags);
    ~CombatCoverMap();
    void* __thiscall FUN_00983100(unsigned int flags);
    void __thiscall FUN_00983130();

    void* GetFirstPos();
    void GetNext(void*& pos, unsigned int& uiKey, ReservedCoverLocation*& pValue);
    void GetNext(void*& pos, unsigned int& uiKey, CoverMapValue*& pValue);
    void RemoveAll();
};
