#pragma once

#include "bhkEntityListener.h"
#include "NiTMap.h"

class NiAVObject;
class RootContactPoint;
class TESObjectREFR;

class BGSAcousticSpaceListener : public bhkEntityListener
{
public:
    virtual ~BGSAcousticSpaceListener();
    virtual void EntityAddedCallback(hkpEntity*);
    virtual void EntityRemovedCallback(hkpEntity*);
    virtual void EntityDeletionCallback(hkpEntity*);

    virtual void UpdateAcousticSpaceRefCounts(float afTime);
    virtual bool CheckAcousticSpaceEntered(RootContactPoint* pPoint);
    virtual bool CheckAcousticSpaceListener(RootContactPoint* pPoint);
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();

    void __thiscall FUN_0061f5d0();
    void* __thiscall Destroy(unsigned int flags);
    void CheckPlayerReference(TESObjectREFR* apEntity);
    void SetCopyMapEntry(TESObjectREFR* apEntity);
    void SetCopyMapEntry(unsigned int uiKey);
    bool __thiscall FUN_0061f890(TESObjectREFR* apEntity, bool flag);
    bool __thiscall FUN_0061f890(NiAVObject* object, bool flag);
    void FUN_0061f8e0(bool abDoRemoval);

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned char m_ucState;
    unsigned char unk15[3];
    NiTMap<TESObjectREFR*, int> m_map; // destroyed by 0x0061fae0, which stores the NiTMap<TESObjectREFR *,int> vftable 0x0104d948
};
