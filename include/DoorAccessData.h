#pragma once

class Actor;
class TESObjectCELL;
class LockExtraData;
class TESForm;
class TESGlobal;
class TESObjectREFR;
class PathingActorData;

class DoorAccessData
{
public:
    TESObjectCELL* m_pSourceCell;
    TESObjectCELL* m_pDestinationCell;
    LockExtraData* m_pTeleportData;
    TESForm* m_pKeyForm;
    int m_iLockLevel;
    TESGlobal* m_pLockLevelGlobal;

    DoorAccessData(TESObjectREFR* pRef);
    ~DoorAccessData();
    void SetDoorReference(TESObjectREFR* pRef);
    bool ReadState98();
    bool DoorLock_IsAnOwner(Actor* ref, bool b);
    bool CanActorUseDoor(const PathingActorData* pActorData, bool bFlag);
    bool CanActorOpenDoor(const PathingActorData* pActorData, bool bFlag);
    bool CanUnlockDoor(const PathingActorData* pActorData, TESObjectREFR* pRef, bool& bNeedsKey);
};
