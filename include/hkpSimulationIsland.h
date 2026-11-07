#pragma once

#include <cstddef>
#include "hkpConstraintOwner.h"
#include "hkMultiThreadCheck.h"

class hkpWorld;
class hkpAction;
class hkpEntity;
class IncompleteClassType;

typedef float hkReal;

template <class T>
struct hkArrayNative
{
    T* data;
    int count;
    unsigned int capRaw;

    int getCapacity() const;
    void reserve(int n);
    void AddBack(const T& t);
    void SetSize(int size);
};

class hkpSimulationIsland : public hkpConstraintOwner
{
public:
    hkpSimulationIsland(hkpWorld* world);
    virtual ~hkpSimulationIsland() throw();

    hkpWorld* m_pOwningWorld;
    mutable hkMultiThreadCheck m_kMultiThreadCheck;
    hkReal m_fIslandValueBeforeActions1;
    int unk1C;
    unsigned short storageIndex;
    unsigned short dirtyIndex;
    unsigned char unk24;
    unsigned char flags25;
    union
    {
        unsigned char flags26;
        struct
        {
            unsigned char f26lo : 2;
            unsigned char f26mid : 2;
        } f26;
    };
    unsigned char unk27;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    hkArrayNative<hkpAction*> actions;
    int unk44;
    union
    {
        hkArrayNative<hkpEntity*> entities;
        struct
        {
            hkpEntity** m_kActorEntries;
            int m_iActorEntryCount;
            unsigned int unk50;
        };
    };
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;

    static void* __cdecl operator new(std::size_t nbytes);
    bool CheckIslandConnectivity(IncompleteClassType& checkConnectivityOut);
    int getStorageIndex();
    void MarkForWrite();
    void isValid();
    void MergeFrom(hkpSimulationIsland*);
    void RemoveEntry(hkpAction* action);
    void AddItem(hkpAction* action) throw();
    __declspec(nothrow) void RemoveItem(hkpEntity* entity);
    void nullsub_30();
    void hkpSimulationIsland_internalAddEntity(hkpEntity* entity);
    void nullsub_10();
};
