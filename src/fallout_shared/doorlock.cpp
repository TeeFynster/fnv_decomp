// fallout_shared/doorlock.cpp: DoorAccessData, PathingActorData, LockAccess (15 functions)

// Use the shared TESFile with the legacy layout helpers.
#define FNV_TESFILE_H
#include "layout_support.h"
#define FNV64_BSSIMPLELIST_DEFINED
#include <new>
#include "../../include/NiFile.h"
#include "../../include/MemoryManager.h"
#include "../../include/DoorAccessData.h"
#include "../../include/PathingActorData.h"
#include "../../include/InventoryChanges.h"
#include "../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}
__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
#include "../../include/TESBoundObject.h"
#include "../../include/TESForm.h"
#include "../../include/TESClass.h"
#include "../../include/TESGlobal.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESFaction.h"
#include "../../include/TESKey.h"
#include "../../include/TESFile.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/ExtraRadioData.h"
#include "../../include/LowProcess.h"

// Remaining doorlock support declarations; TESObjectREFR comes from the shared header.
class ExtraRadioData;
class LockExtraData;
class InventoryChanges;




class FUN_00411b00;

class ActorData
{
  public:
    TESActorBase* m_pActorBaseFormItem;
    InventoryChanges* m_pInventoryChangesValue;
    bool m_bCanIgnoreLocks;
    unsigned char layoutPadding9[3];

    ActorData(Actor* actor);
};

FNV_STATIC_ASSERT(sizeof(PathingActorData) == 12);
FNV_STATIC_ASSERT(offsetof(PathingActorData, m_pActorBaseFormItem) == 0);
FNV_STATIC_ASSERT(offsetof(PathingActorData, m_pInventoryChangesValue) == 4);
FNV_STATIC_ASSERT(offsetof(PathingActorData, m_bCanIgnoreLocks) == 8);


class TESObjectCELL;
class LockExtraData;
class TESGlobal;
class TESClass;
class InventoryChanges;
#pragma pack(push, 4)
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(DoorAccessData) == 24);
FNV_STATIC_ASSERT(offsetof(DoorAccessData, m_pSourceCell) == 0);
FNV_STATIC_ASSERT(offsetof(DoorAccessData, m_pDestinationCell) == 4);
FNV_STATIC_ASSERT(offsetof(DoorAccessData, m_pTeleportData) == 8);
FNV_STATIC_ASSERT(offsetof(DoorAccessData, m_pKeyForm) == 12);
FNV_STATIC_ASSERT(offsetof(DoorAccessData, m_iLockLevel) == 16);
FNV_STATIC_ASSERT(offsetof(DoorAccessData, m_pLockLevelGlobal) == 20);

// Copy-assigns another actor's data into this object's actor-data member at offset 0x5c via CopyFrom and returns it.
// @fnv 0x006e2b20
PathingActorData& PathingActorData::operator=(const PathingActorData& other)
{
    return reinterpret_cast<PathingActorData*>(reinterpret_cast<char*>(this) + 0x5c)
        ->CopyFrom(ActorData(reinterpret_cast<Actor*>(const_cast<PathingActorData*>(&other))));
}

// @fnv 0x0073cb80
bool DoorAccessData::ReadState98()
{
    return *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x98);
}

// Minimal callee declarations (codegen only; layouts remain with owning units).
class TESGlobalValueReader
{
  public:
    float GetValue();
};
class DoorCell
{
  public:
    bool IsOwnedByActor(TESActorBase* m_pActorBaseFormItem);
    TESForm* GetOwner();
};
struct FactionOwnership
{
    TESFaction* pFaction;
    int m_iRank;
};
struct IgnoreLocals
{
    TESActorBase* m_pActorBaseFormItem;
    TESClass* pClass;
};
struct KeySearch
{
    int iCount;
};
#pragma pack(push, 4)
class LockExtraData
{
  public:
    unsigned char m_uiLockState;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    TESKey* pKey;  // +0x4, 4 bytes
    char cFlags;   // +0x8, 1 bytes
    unsigned char layoutPadding9[3];
    unsigned int m_uiLockDifficulty;  // +0xC, 4 bytes
    unsigned int m_uiLockValue;       // +0x10, 4 bytes
    int GetLockLevel(TESObjectREFR* pRef);
    bool IsLocked();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(LockExtraData) == 20);
FNV_STATIC_ASSERT(offsetof(LockExtraData, m_uiLockState) == 0);
FNV_STATIC_ASSERT(offsetof(LockExtraData, pKey) == 4);
FNV_STATIC_ASSERT(offsetof(LockExtraData, cFlags) == 8);
FNV_STATIC_ASSERT(offsetof(LockExtraData, m_uiLockDifficulty) == 12);
FNV_STATIC_ASSERT(offsetof(LockExtraData, m_uiLockValue) == 16);

// @fnv 0x005021a0
bool LockExtraData::IsLocked()
{
    return (cFlags & 1) != 0;
}

class FUN_00411b00 : public LockExtraData
{
  public:
    FUN_00411b00();
};

struct DoorLockCtorLocals
{
    ExtraRadioData* pRadioData;
    LockExtraData* pSourceLock;
};

// @fnv 0x00501d20
DoorAccessData::DoorAccessData(TESObjectREFR* pRef)
{
    DoorLockCtorLocals data;
    m_pSourceCell = reinterpret_cast<TESObjectCELL*>(reinterpret_cast<LowProcess*>(pRef)->LowProcess::GetTarget());

    data.pRadioData = pRef->GetExtraRadioData();
    if (data.pRadioData != 0)
        m_pDestinationCell = data.pRadioData->DoorTeleportData_GetTeleportCell();
    else
        m_pDestinationCell = 0;

    data.pSourceLock = pRef->GetLock();
    if (data.pSourceLock != 0)
    {
        m_pTeleportData = new FUN_00411b00;
        m_pTeleportData->pKey = data.pSourceLock->pKey;
        m_pTeleportData->m_uiLockState = data.pSourceLock->m_uiLockState;
        m_pTeleportData->cFlags = data.pSourceLock->cFlags;
    }
    else
        m_pTeleportData = 0;

    m_pKeyForm = pRef->GetOwner();
    m_iLockLevel = pRef->GetReferenceLockLevel();
    m_pLockLevelGlobal = pRef->GetLockLevelGlobal();
}

// Frees the memory block held by the object if it is non-null, then returns.
// @fnv 0x00501e50
DoorAccessData::~DoorAccessData()
{
    if (m_pTeleportData != 0)
    {
        void* pMem = m_pTeleportData;
        ::operator delete(pMem);
    }
}

extern TESBoundObject* g_pLockpickItem;

// @fnv 0x00502550
bool DoorAccessData::CanActorUseDoor(const PathingActorData* pActorData, bool bFlag)
{
    bool bIsOwner = false;
    FactionOwnership own;
    if (m_pKeyForm != 0 && pActorData != 0)
    {
        bIsOwner = true;
        if (m_pKeyForm != pActorData->m_pActorBaseFormItem)
        {
            own.pFaction = 0;
            if (m_pKeyForm != 0 && m_pKeyForm->GetFormType() == ENUM_FORM_ID_FACT_ID)
                own.pFaction = static_cast<TESFaction*>(m_pKeyForm);
            own.m_iRank = 0;
            if (own.pFaction == 0 || !bFlag)
            {
                if (m_pLockLevelGlobal == 0 || m_pLockLevelGlobal->GetValue() == 0.0)
                    bIsOwner = false;
            }
            if (own.pFaction != 0 && pActorData->m_pActorBaseFormItem != 0)
            {
                own.m_iRank = pActorData->m_pActorBaseFormItem->GetFactionRank(own.pFaction, false);
                if (own.m_iRank < m_iLockLevel)
                    bIsOwner = false;
            }
        }
    }
    return bIsOwner;
}

// Checks pActorData against the current door/cell state and returns whether the actor can be ignored, using class and guard checks.
// @fnv 0x00502310
bool DoorAccessData::CanActorOpenDoor(const PathingActorData* pActorData, bool bFlag)
{
    bool bCanIgnore = false;
    IgnoreLocals data;
    if (pActorData != 0)
    {
        if (m_pTeleportData == 0)
            bCanIgnore = true;
        else if (m_pTeleportData->pKey == 0 && bFlag)
            bCanIgnore = true;
        else if (m_pSourceCell != 0 &&
                 reinterpret_cast<DoorCell*>(m_pSourceCell)->IsOwnedByActor(pActorData->m_pActorBaseFormItem))
        {
            if (m_pDestinationCell == 0 || reinterpret_cast<DoorCell*>(m_pDestinationCell)->GetOwner() == 0 ||
                reinterpret_cast<DoorCell*>(m_pDestinationCell)->IsOwnedByActor(pActorData->m_pActorBaseFormItem))
                bCanIgnore = true;
        }
        else if (CanActorUseDoor(pActorData, true))
            bCanIgnore = true;
        else
        {
            data.pClass = 0;
            if (pActorData->m_pActorBaseFormItem != 0 && pActorData->m_pActorBaseFormItem->GetFormType() == ENUM_FORM_ID_NPC__ID)
            {
                data.m_pActorBaseFormItem = pActorData->m_pActorBaseFormItem;
                if (data.m_pActorBaseFormItem != 0)
                    data.pClass = data.m_pActorBaseFormItem->GetClass();
                if (data.pClass != 0 && data.pClass->IsGuard() && pActorData->m_bCanIgnoreLocks)
                    bCanIgnore = true;
            }
        }
    }
    return bCanIgnore;
}

// @fnv 0x00502450
bool DoorAccessData::CanUnlockDoor(const PathingActorData* pActorData, TESObjectREFR* pRef, bool& bNeedsKey)
{
    KeySearch kSearch;
    bool bCanUnlock = false;
    kSearch.iCount = 0;
    bNeedsKey = false;
    if (pActorData != 0)
    {
        if (CanActorOpenDoor(pActorData, false))
            bCanUnlock = true;
        else if (m_pTeleportData->IsLocked())
        {
            if (m_pTeleportData->pKey != 0 && pActorData->m_pInventoryChangesValue != 0 &&
                pActorData->m_pInventoryChangesValue->FindItemInInventory(m_pTeleportData->pKey, 0, 1, kSearch.iCount,
                                                                          0, 0))
                bCanUnlock = true;
            else if (m_pTeleportData->GetLockLevel(pRef) != 5 && pActorData->m_pInventoryChangesValue != 0 &&
                     pActorData->m_pInventoryChangesValue->FindItemInInventory(g_pLockpickItem, 0, 1, kSearch.iCount, 0,
                                                                               0))
            {
                bCanUnlock = true;
                bNeedsKey = true;
            }
        }
        else
            bCanUnlock = true;
    }
    return bCanUnlock;
}

struct XCont;
struct XExtraList
{
    XCont* GetContainerChangeData();
};
struct XActor
{
    void* GetActorBase();
    const XExtraList* GetExtra() const;
    bool IsInDeadState();
};
// Stores the actor's base, the container from its extra list, and its alarm state.
// @fnv 0x00502670
ActorData::ActorData(Actor* apActor)
{
    m_pActorBaseFormItem = static_cast<TESActorBase*>(reinterpret_cast<XActor*>(apActor)->GetActorBase());
    m_pInventoryChangesValue = reinterpret_cast<InventoryChanges*>(
        ((XExtraList*)reinterpret_cast<XActor*>(apActor)->GetExtra())->GetContainerChangeData());
    m_bCanIgnoreLocks = reinterpret_cast<XActor*>(apActor)->IsInDeadState();
}

struct FUN_00996800_shell : public DoorAccessData
{
    void AStarMap_AStarNode_NavMeshSearchNode_NavMeshSearchLink_Clear();
};

void* __cdecl memset(void*, int, unsigned int);

// If the int at offset 0x1fdc is nonzero, zeroes the first 0x1fdc bytes of the object and resets that int to 0.
// @fnv 0x00996800
// src: XBOX_PDB 0x00996800
void FUN_00996800_shell::AStarMap_AStarNode_NavMeshSearchNode_NavMeshSearchLink_Clear()
{
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x1fdc) != 0)
    {
        memset(this, 0, 0x1fdc);
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x1fdc) = 0;
    }
}

struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct TESObjectCELL;
struct TESWorldSpace;
struct blob16
{
    char b[16];
};
struct TeleportableReference
{
    TESObjectREFR* GetLinkedDoor();
    void* GetTeleportPosition();
    void* GetTeleportRotation();
    TESObjectCELL* GetTeleportCell();
    void GetTeleportCellMapName(void*);
    TESWorldSpace* GetTeleportWorldspace();
    struct blob16 GetTeleportDestinationPosition();
    TESForm* GetTeleportDestinationForm();
    bool GetNoAlarm();
    void SetNoAlarm(bool);
    void SetLinkedDoor(TESObjectREFR*);
    void SetTeleportPosition(void*);
    void SetTeleportRotation(void*);
    void SetLinkedDoorReference(TESObjectREFR*, bool);
    void Save();
    void Load(TESFile*);
    bool InitItem(TESForm*);
    void Copy(TeleportableReference*);
    bool Compare(TeleportableReference*);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveGameBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadGameBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadGameBuffer*);
    void InitLoadGame();
    void FinishLoadGameTES();
    void* __vecDelDtor(unsigned int);
    TESObjectREFR* m_pLinkedDoorReference;
    char position[12];
    char rotation[12];
    unsigned char cFlags;
    char _pad_1d[3];
};
typedef char _sizecheck_DoorTeleportData[sizeof(TeleportableReference) == 32 ? 1 : -1];
struct FUN_00501e80_shell : public DoorAccessData
{
    void DoorLock_SetFromDoorRef(TESObjectREFR*);
};

// @fnv 0x00501e80
// src: XBOX_PDB 0x00501e80
void FUN_00501e80_shell::DoorLock_SetFromDoorRef(TESObjectREFR* apDoorRef)
{
    ExtraRadioData* ptel;
    LockExtraData* pDoorLock;
    m_pSourceCell = (TESObjectCELL*)((LowProcess*)apDoorRef)->LowProcess::GetTarget();
    ptel = apDoorRef->GetExtraRadioData();
    if (ptel)
        m_pDestinationCell = ptel->DoorTeleportData_GetTeleportCell();
    else
        m_pDestinationCell = 0;
    pDoorLock = apDoorRef->GetLock();
    if (pDoorLock)
    {
        if (!m_pTeleportData)
            m_pTeleportData = new FUN_00411b00;
        m_pTeleportData->pKey = pDoorLock->pKey;
        m_pTeleportData->m_uiLockState = pDoorLock->m_uiLockState;
        m_pTeleportData->cFlags = pDoorLock->cFlags;
    }
    else if (m_pTeleportData)
    {
        delete m_pTeleportData;
        m_pTeleportData = 0;
    }
    m_pKeyForm = apDoorRef->GetOwner();
    m_iLockLevel = apDoorRef->GetReferenceLockLevel();
    m_pLockLevelGlobal = apDoorRef->GetLockLevelGlobal();
}

// Copies the actor's base, inventory changes and lock flag, then returns this.
// @fnv 0x00502630
PathingActorData& PathingActorData::CopyFrom(const ActorData& other)
{
    m_pActorBaseFormItem = other.m_pActorBaseFormItem;
    m_pInventoryChangesValue = other.m_pInventoryChangesValue;
    m_bCanIgnoreLocks = other.m_bCanIgnoreLocks;
    return *this;
}

struct FUN_00502180_shell
{
    bool IsFlag20Set();
};
// @fnv 0x00502180
bool FUN_00502180_shell::IsFlag20Set()
{
    return (((unsigned char*)this)[0x24] & 0x20);
}

struct LockActor;
struct LockCell
{
    void* GetOwner();
    bool IsActorCellOwner(LockActor*);
    bool IsInterior();
    bool IsFlag20Set();
};
struct LockActor
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual void vf125();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual void vf135();
    virtual void vf136();
    virtual void vf137();
    virtual void vf138();
    virtual void vf139();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf150();
    virtual void vf151();
    virtual void vf152();
    virtual void vf153();
    virtual void vf154();
    virtual void vf155();
    virtual void vf156();
    virtual void vf157();
    virtual void vf158();
    virtual void vf159();
    virtual void vf160();
    virtual void vf161();
    virtual void vf162();
    virtual void vf163();
    virtual void vf164();
    virtual void vf165();
    virtual void vf166();
    virtual void vf167();
    virtual void vf168();
    virtual void vf169();
    virtual void vf170();
    virtual void vf171();
    virtual void vf172();
    virtual void vf173();
    virtual void vf174();
    virtual void vf175();
    virtual void vf176();
    virtual void vf177();
    virtual void vf178();
    virtual void vf179();
    virtual void vf180();
    virtual void vf181();
    virtual void vf182();
    virtual void vf183();
    virtual void vf184();
    virtual void vf185();
    virtual void vf186();
    virtual void vf187();
    virtual void vf188();
    virtual void vf189();
    virtual void vf190();
    virtual void vf191();
    virtual void vf192();
    virtual bool vf193();
    virtual void vf194();
    virtual void vf195();
    virtual void vf196();
    virtual void vf197();
    virtual void vf198();
    virtual void vf199();
    virtual void vf200();
    virtual void vf201();
    virtual void vf202();
    virtual void vf203();
    virtual void vf204();
    virtual void vf205();
    virtual void vf206();
    virtual void vf207();
    virtual void vf208();
    virtual void vf209();
    virtual void vf210();
    virtual void vf211();
    virtual void vf212();
    virtual void vf213();
    virtual void vf214();
    virtual void vf215();
    virtual void vf216();
    virtual void vf217();
    virtual void vf218();
    virtual void vf219();
    virtual void vf220();
    virtual void vf221();
    virtual void vf222();
    virtual void vf223();
    virtual void vf224();
    virtual void vf225();
    virtual void vf226();
    virtual void vf227();
    virtual void vf228();
    virtual void vf229();
    virtual void vf230();
    virtual void vf231();
    virtual void vf232();
    virtual void vf233();
    virtual void vf234();
    virtual void vf235();
    virtual void vf236();
    virtual void vf237();
    virtual void vf238();
    virtual void vf239();
    virtual void vf240();
    virtual void vf241();
    virtual void vf242();
    virtual void vf243();
    virtual void vf244();
    virtual void vf245();
    virtual void vf246();
    virtual void vf247();
    virtual void vf248();
    virtual void vf249();
    virtual void vf250();
    virtual void vf251();
    virtual void vf252();
    virtual void vf253();
    virtual void vf254();
    virtual void vf255();
    virtual void vf256();
    virtual void vf257();
    virtual void vf258();
    virtual void vf259();
    virtual void vf260();
    virtual void vf261();
    virtual void vf262();
    virtual void vf263();
    virtual void vf264();
    virtual void vf265();
    virtual void vf266();
    virtual void vf267();
    virtual void vf268();
    virtual void vf269();
    virtual void vf270();
    virtual void vf271();
    virtual void vf272();
    virtual void vf273();
    virtual bool vf274();
    LockCell* GetParentCell();
    bool Actor_IsAlarmed();
};
extern LockActor* DAT_011dea3c;
struct DoorState
{
    unsigned char level;
    bool FUN_005021a0();
};
struct LockAccess
{
    LockCell* unk00;
    LockCell* cell;
    DoorState* state;
    bool DoorLock_IsAnOwner(LockActor*, bool);
    bool CanAccessLock(LockActor*, int, bool);
};
// Returns whether actor may access the lock: checks state, cell ownership, parent cell, and the global actor, returning true if any condition passes.
// @fnv 0x00501fd0
bool LockAccess::CanAccessLock(LockActor* actor, int unused, bool flag)
{
    bool a = false;
    if (actor)
    {
        if (!state && flag)
            a = true;
        else if (state && !state->FUN_005021a0() && flag)
            a = true;
        else if (actor != DAT_011dea3c && actor->GetParentCell() && actor->GetParentCell()->GetOwner() &&
                 actor->GetParentCell()->IsActorCellOwner(actor))
        {
            if (!cell || !cell->GetOwner() || cell->IsActorCellOwner(actor))
                a = true;
        }
        else if (actor != DAT_011dea3c && DoorLock_IsAnOwner(actor, true))
            a = true;
        else if (actor->vf193() && actor->Actor_IsAlarmed())
            a = true;
        else if (actor == DAT_011dea3c && DAT_011dea3c->vf274() && cell && state && state->level != 100)
        {
            if (!cell->IsInterior() || cell->IsFlag20Set())
                a = true;
        }
    }
    return a;
}

struct Nav
{
    void* NavMeshInfo_GetWorldSpace();
    void* GetInteriorCell();
};
struct Position
{
    NiPoint3& FUN_00717e50();
};
struct Door
{
    Position* FUN_00568e50();
};
struct Location
{
    bool FUN_006dd6f0(int);
    Nav* TESMain_GetThread();
    NiPoint3 FUN_005c3420() const;
};
struct ParentSpaceNode
{
    bool unk00;
    void* unk04;
    void* unk08;
};
struct FUN_006d5320
{
    Door* unk00;
    NiPoint3 unk04;
    FUN_006d5320();
};
struct DoorArray
{
    int unk00, unk04, unk08, unk0C;
    unsigned FUN_0044ddc0();
    Door*& FUN_00877a30(unsigned);
    void BSSimpleArray_TeleportLink_1024_Add(const FUN_006d5320&);
};
struct Result
{
    int unk00, unk04, unk08, unk0C;
    DoorArray unk10;
    NiPoint3 unk20, unk2C;
    unsigned BSSimpleArray_ParentSpaceNode_1024_Add(const ParentSpaceNode&);
};
#include "../../include/PathBuilderDetailedPathInfos.h"
struct FUN_005e04c0
{
    int unk00, unk04, unk08, unk0C;
    FUN_005e04c0();
    ~FUN_005e04c0();
    Door*& FUN_00877a30(unsigned);
    unsigned FUN_0044ddc0();
};
struct BuilderBase
{
    int unk0000, unk0004;
    int unk0008, unk000C;
    int unk0010, unk0014;
    int unk0018, unk001C;
    int unk0020, unk0024;
    int unk0028, unk002C;
    int unk0030, unk0034;
    int unk0038, unk003C;
    int unk0040, unk0044;
    int unk0048, unk004C;
    int unk0050, unk0054;
    int unk0058, unk005C;
    int unk0060, unk0064;
    int unk0068, unk006C;
    int unk0070, unk0074;
    int unk0078, unk007C;
    int unk0080, unk0084;
    int unk0088, unk008C;
    int unk0090, unk0094;
    int unk0098, unk009C;
    int unk00A0, unk00A4;
    int unk00A8, unk00AC;
    int unk00B0, unk00B4;
    int unk00B8, unk00BC;
    int unk00C0, unk00C4;
    int unk00C8, unk00CC;
    int unk00D0, unk00D4;
    int unk00D8, unk00DC;
    int unk00E0, unk00E4;
    int unk00E8, unk00EC;
    int unk00F0, unk00F4;
    int unk00F8, unk00FC;
    int unk0100, unk0104;
    int unk0108, unk010C;
    int unk0110, unk0114;
    int unk0118, unk011C;
    int unk0120, unk0124;
    int unk0128, unk012C;
    int unk0130, unk0134;
    int unk0138, unk013C;
    int unk0140, unk0144;
    int unk0148, unk014C;
    int unk0150, unk0154;
    int unk0158, unk015C;
    int unk0160, unk0164;
    int unk0168, unk016C;
    int unk0170, unk0174;
    int unk0178, unk017C;
    int unk0180, unk0184;
    int unk0188, unk018C;
    int unk0190, unk0194;
    int unk0198, unk019C;
    int unk01A0, unk01A4;
    int unk01A8, unk01AC;
    int unk01B0, unk01B4;
    int unk01B8, unk01BC;
    int unk01C0, unk01C4;
    int unk01C8, unk01CC;
    int unk01D0, unk01D4;
    int unk01D8, unk01DC;
    int unk01E0, unk01E4;
    int unk01E8, unk01EC;
    int unk01F0, unk01F4;
    int unk01F8, unk01FC;
    int unk0200, unk0204;
    int unk0208, unk020C;
    int unk0210, unk0214;
    int unk0218, unk021C;
    int unk0220, unk0224;
    int unk0228, unk022C;
    int unk0230, unk0234;
    int unk0238, unk023C;
    int unk0240, unk0244;
    int unk0248, unk024C;
    int unk0250, unk0254;
    int unk0258, unk025C;
    int unk0260, unk0264;
    int unk0268, unk026C;
    int unk0270, unk0274;
    int unk0278, unk027C;
    int unk0280, unk0284;
    int unk0288, unk028C;
    int unk0290, unk0294;
    int unk0298, unk029C;
    int unk02A0, unk02A4;
    int unk02A8, unk02AC;
    int unk02B0, unk02B4;
    int unk02B8, unk02BC;
    int unk02C0, unk02C4;
    int unk02C8, unk02CC;
    int unk02D0, unk02D4;
    int unk02D8, unk02DC;
    int unk02E0, unk02E4;
    int unk02E8, unk02EC;
    int unk02F0, unk02F4;
    int unk02F8, unk02FC;
    int unk0300, unk0304;
    int unk0308, unk030C;
    int unk0310, unk0314;
    int unk0318, unk031C;
    int unk0320, unk0324;
    int unk0328, unk032C;
    int unk0330, unk0334;
    int unk0338, unk033C;
    int unk0340, unk0344;
    int unk0348, unk034C;
    int unk0350, unk0354;
    int unk0358, unk035C;
    int unk0360, unk0364;
    int unk0368, unk036C;
    int unk0370, unk0374;
    int unk0378, unk037C;
    int unk0380, unk0384;
    int unk0388, unk038C;
    int unk0390, unk0394;
    int unk0398, unk039C;
    int unk03A0, unk03A4;
    int unk03A8, unk03AC;
    int unk03B0, unk03B4;
    int unk03B8, unk03BC;
    int unk03C0, unk03C4;
    int unk03C8, unk03CC;
    int unk03D0, unk03D4;
    int unk03D8, unk03DC;
    int unk03E0, unk03E4;
    int unk03E8, unk03EC;
    int unk03F0, unk03F4;
    int unk03F8, unk03FC;
    int unk0400, unk0404;
    int unk0408, unk040C;
    int unk0410, unk0414;
    int unk0418, unk041C;
    int unk0420, unk0424;
    int unk0428, unk042C;
    int unk0430, unk0434;
    int unk0438, unk043C;
    int unk0440, unk0444;
    int unk0448, unk044C;
    int unk0450, unk0454;
    int unk0458, unk045C;
    int unk0460, unk0464;
    int unk0468, unk046C;
    int unk0470, unk0474;
    int unk0478, unk047C;
    int unk0480, unk0484;
    int unk0488, unk048C;
    int unk0490, unk0494;
    int unk0498, unk049C;
    int unk04A0, unk04A4;
    int unk04A8, unk04AC;
    int unk04B0, unk04B4;
    int unk04B8, unk04BC;
    int unk04C0, unk04C4;
    int unk04C8, unk04CC;
    int unk04D0, unk04D4;
    int unk04D8, unk04DC;
    int unk04E0, unk04E4;
    int unk04E8, unk04EC;
    int unk04F0, unk04F4;
    int unk04F8, unk04FC;
    int unk0500, unk0504;
    int unk0508, unk050C;
    int unk0510, unk0514;
    int unk0518, unk051C;
    int unk0520, unk0524;
    int unk0528, unk052C;
    int unk0530, unk0534;
    int unk0538, unk053C;
    int unk0540, unk0544;
    int unk0548, unk054C;
    int unk0550, unk0554;
    int unk0558, unk055C;
    int unk0560, unk0564;
    int unk0568, unk056C;
    int unk0570, unk0574;
    int unk0578, unk057C;
    int unk0580, unk0584;
    int unk0588, unk058C;
    int unk0590, unk0594;
    int unk0598, unk059C;
    int unk05A0, unk05A4;
    int unk05A8, unk05AC;
    int unk05B0, unk05B4;
    int unk05B8, unk05BC;
    int unk05C0, unk05C4;
    int unk05C8, unk05CC;
    int unk05D0, unk05D4;
    int unk05D8, unk05DC;
    int unk05E0, unk05E4;
    int unk05E8, unk05EC;
    int unk05F0, unk05F4;
    int unk05F8, unk05FC;
    int unk0600, unk0604;
    int unk0608, unk060C;
    int unk0610, unk0614;
    int unk0618, unk061C;
    int unk0620, unk0624;
    int unk0628, unk062C;
    int unk0630, unk0634;
    int unk0638, unk063C;
    int unk0640, unk0644;
    int unk0648, unk064C;
    int unk0650, unk0654;
    int unk0658, unk065C;
    int unk0660, unk0664;
    int unk0668, unk066C;
    int unk0670, unk0674;
    int unk0678, unk067C;
    int unk0680, unk0684;
    int unk0688, unk068C;
    int unk0690, unk0694;
    int unk0698, unk069C;
    int unk06A0, unk06A4;
    int unk06A8, unk06AC;
    int unk06B0, unk06B4;
    int unk06B8, unk06BC;
    int unk06C0, unk06C4;
    int unk06C8, unk06CC;
    int unk06D0, unk06D4;
    int unk06D8, unk06DC;
    int unk06E0, unk06E4;
    int unk06E8, unk06EC;
    int unk06F0, unk06F4;
    int unk06F8, unk06FC;
    int unk0700, unk0704;
    int unk0708, unk070C;
    int unk0710, unk0714;
    int unk0718, unk071C;
    int unk0720, unk0724;
    int unk0728, unk072C;
    int unk0730, unk0734;
    int unk0738, unk073C;
    int unk0740, unk0744;
    int unk0748, unk074C;
    int unk0750, unk0754;
    int unk0758, unk075C;
    int unk0760, unk0764;
    int unk0768, unk076C;
    int unk0770, unk0774;
    int unk0778, unk077C;
    int unk0780, unk0784;
    int unk0788, unk078C;
    int unk0790, unk0794;
    int unk0798, unk079C;
    int unk07A0, unk07A4;
    int unk07A8, unk07AC;
    int unk07B0, unk07B4;
    int unk07B8, unk07BC;
    int unk07C0, unk07C4;
    int unk07C8, unk07CC;
    int unk07D0, unk07D4;
    int unk07D8, unk07DC;
    int unk07E0, unk07E4;
    int unk07E8, unk07EC;
    int unk07F0, unk07F4;
    int unk07F8, unk07FC;
    int unk0800, unk0804;
    int unk0808, unk080C;
    int unk0810, unk0814;
    int unk0818, unk081C;
    int unk0820, unk0824;
    int unk0828, unk082C;
    int unk0830, unk0834;
    int unk0838, unk083C;
    int unk0840, unk0844;
    int unk0848, unk084C;
    int unk0850, unk0854;
    int unk0858, unk085C;
    int unk0860, unk0864;
    int unk0868, unk086C;
    int unk0870, unk0874;
    int unk0878, unk087C;
    int unk0880, unk0884;
    int unk0888, unk088C;
    int unk0890, unk0894;
    int unk0898, unk089C;
    int unk08A0, unk08A4;
    int unk08A8, unk08AC;
    int unk08B0, unk08B4;
    int unk08B8, unk08BC;
    int unk08C0, unk08C4;
    int unk08C8, unk08CC;
    int unk08D0, unk08D4;
    int unk08D8, unk08DC;
    int unk08E0, unk08E4;
    int unk08E8, unk08EC;
    int unk08F0, unk08F4;
    int unk08F8, unk08FC;
    int unk0900, unk0904;
    int unk0908, unk090C;
    int unk0910, unk0914;
    int unk0918, unk091C;
    int unk0920, unk0924;
    int unk0928, unk092C;
    int unk0930, unk0934;
    int unk0938, unk093C;
    int unk0940, unk0944;
    int unk0948, unk094C;
    int unk0950, unk0954;
    int unk0958, unk095C;
    int unk0960, unk0964;
    int unk0968, unk096C;
    int unk0970, unk0974;
    int unk0978, unk097C;
    int unk0980, unk0984;
    int unk0988, unk098C;
    int unk0990, unk0994;
    int unk0998, unk099C;
    int unk09A0, unk09A4;
    int unk09A8, unk09AC;
    int unk09B0, unk09B4;
    int unk09B8, unk09BC;
    int unk09C0, unk09C4;
    int unk09C8, unk09CC;
    int unk09D0, unk09D4;
    int unk09D8, unk09DC;
    int unk09E0, unk09E4;
    int unk09E8, unk09EC;
    int unk09F0, unk09F4;
    int unk09F8, unk09FC;
    int unk0A00, unk0A04;
    int unk0A08, unk0A0C;
    int unk0A10, unk0A14;
    int unk0A18, unk0A1C;
    int unk0A20, unk0A24;
    int unk0A28, unk0A2C;
    int unk0A30, unk0A34;
    int unk0A38, unk0A3C;
    int unk0A40, unk0A44;
    int unk0A48, unk0A4C;
    int unk0A50, unk0A54;
    int unk0A58, unk0A5C;
    int unk0A60, unk0A64;
    int unk0A68, unk0A6C;
    int unk0A70, unk0A74;
    int unk0A78, unk0A7C;
    int unk0A80, unk0A84;
    int unk0A88, unk0A8C;
    int unk0A90, unk0A94;
    int unk0A98, unk0A9C;
    int unk0AA0, unk0AA4;
    int unk0AA8, unk0AAC;
    int unk0AB0, unk0AB4;
    int unk0AB8, unk0ABC;
    int unk0AC0, unk0AC4;
    int unk0AC8, unk0ACC;
    int unk0AD0, unk0AD4;
    int unk0AD8, unk0ADC;
    int unk0AE0, unk0AE4;
    int unk0AE8, unk0AEC;
    int unk0AF0, unk0AF4;
    int unk0AF8, unk0AFC;
    int unk0B00, unk0B04;
    int unk0B08, unk0B0C;
    int unk0B10, unk0B14;
    int unk0B18, unk0B1C;
    int unk0B20, unk0B24;
    int unk0B28, unk0B2C;
    int unk0B30, unk0B34;
    int unk0B38, unk0B3C;
    int unk0B40, unk0B44;
    int unk0B48, unk0B4C;
    int unk0B50, unk0B54;
    int unk0B58, unk0B5C;
    int unk0B60, unk0B64;
    int unk0B68, unk0B6C;
    int unk0B70, unk0B74;
    int unk0B78, unk0B7C;
    int unk0B80, unk0B84;
    int unk0B88, unk0B8C;
    int unk0B90, unk0B94;
    int unk0B98, unk0B9C;
    int unk0BA0, unk0BA4;
    int unk0BA8, unk0BAC;
    int unk0BB0, unk0BB4;
    int unk0BB8, unk0BBC;
    int unk0BC0, unk0BC4;
    int unk0BC8, unk0BCC;
    int unk0BD0, unk0BD4;
    int unk0BD8, unk0BDC;
    int unk0BE0, unk0BE4;
    int unk0BE8, unk0BEC;
    int unk0BF0, unk0BF4;
    int unk0BF8, unk0BFC;
    int unk0C00, unk0C04;
    int unk0C08, unk0C0C;
    int unk0C10, unk0C14;
    int unk0C18, unk0C1C;
    int unk0C20, unk0C24;
    int unk0C28, unk0C2C;
    int unk0C30, unk0C34;
    int unk0C38, unk0C3C;
    int unk0C40, unk0C44;
    int unk0C48, unk0C4C;
    int unk0C50, unk0C54;
    int unk0C58, unk0C5C;
    int unk0C60, unk0C64;
    int unk0C68, unk0C6C;
    int unk0C70, unk0C74;
    int unk0C78, unk0C7C;
    int unk0C80, unk0C84;
    int unk0C88, unk0C8C;
    int unk0C90, unk0C94;
    int unk0C98, unk0C9C;
    int unk0CA0, unk0CA4;
    int unk0CA8, unk0CAC;
    int unk0CB0, unk0CB4;
    int unk0CB8, unk0CBC;
    int unk0CC0, unk0CC4;
    int unk0CC8, unk0CCC;
    int unk0CD0, unk0CD4;
    int unk0CD8, unk0CDC;
    int unk0CE0, unk0CE4;
    int unk0CE8, unk0CEC;
    int unk0CF0, unk0CF4;
    int unk0CF8, unk0CFC;
    int unk0D00, unk0D04;
    int unk0D08, unk0D0C;
    int unk0D10, unk0D14;
    int unk0D18, unk0D1C;
    int unk0D20, unk0D24;
    int unk0D28, unk0D2C;
    int unk0D30, unk0D34;
    int unk0D38, unk0D3C;
    int unk0D40, unk0D44;
    int unk0D48, unk0D4C;
    int unk0D50, unk0D54;
    int unk0D58, unk0D5C;
    int unk0D60, unk0D64;
    int unk0D68, unk0D6C;
    int unk0D70, unk0D74;
    int unk0D78, unk0D7C;
    int unk0D80, unk0D84;
    int unk0D88, unk0D8C;
    int unk0D90, unk0D94;
    int unk0D98, unk0D9C;
    int unk0DA0, unk0DA4;
    int unk0DA8, unk0DAC;
    int unk0DB0, unk0DB4;
    int unk0DB8, unk0DBC;
    int unk0DC0, unk0DC4;
    int unk0DC8, unk0DCC;
    int unk0DD0, unk0DD4;
    int unk0DD8, unk0DDC;
    int unk0DE0, unk0DE4;
    int unk0DE8, unk0DEC;
    int unk0DF0, unk0DF4;
    int unk0DF8, unk0DFC;
    int unk0E00, unk0E04;
    int unk0E08, unk0E0C;
    int unk0E10, unk0E14;
    int unk0E18, unk0E1C;
    int unk0E20, unk0E24;
    int unk0E28, unk0E2C;
    int unk0E30, unk0E34;
    int unk0E38, unk0E3C;
    int unk0E40, unk0E44;
    int unk0E48, unk0E4C;
    int unk0E50, unk0E54;
    int unk0E58, unk0E5C;
    int unk0E60, unk0E64;
    int unk0E68, unk0E6C;
    int unk0E70, unk0E74;
    int unk0E78, unk0E7C;
    int unk0E80, unk0E84;
    int unk0E88, unk0E8C;
    int unk0E90, unk0E94;
    int unk0E98, unk0E9C;
    int unk0EA0, unk0EA4;
    int unk0EA8, unk0EAC;
    int unk0EB0, unk0EB4;
    int unk0EB8, unk0EBC;
    int unk0EC0, unk0EC4;
    int unk0EC8, unk0ECC;
    int unk0ED0, unk0ED4;
    int unk0ED8, unk0EDC;
    int unk0EE0, unk0EE4;
    int unk0EE8, unk0EEC;
    int unk0EF0, unk0EF4;
    int unk0EF8, unk0EFC;
    int unk0F00, unk0F04;
    int unk0F08, unk0F0C;
    int unk0F10, unk0F14;
    int unk0F18, unk0F1C;
    int unk0F20, unk0F24;
    int unk0F28, unk0F2C;
    int unk0F30, unk0F34;
    int unk0F38, unk0F3C;
    int unk0F40, unk0F44;
    int unk0F48, unk0F4C;
    int unk0F50, unk0F54;
    int unk0F58, unk0F5C;
    int unk0F60, unk0F64;
    int unk0F68, unk0F6C;
    int unk0F70, unk0F74;
    int unk0F78, unk0F7C;
    int unk0F80, unk0F84;
    int unk0F88, unk0F8C;
    int unk0F90, unk0F94;
    int unk0F98, unk0F9C;
    int unk0FA0, unk0FA4;
    int unk0FA8, unk0FAC;
    int unk0FB0, unk0FB4;
    int unk0FB8, unk0FBC;
    int unk0FC0, unk0FC4;
    int unk0FC8, unk0FCC;
    int unk0FD0, unk0FD4;
    int unk0FD8, unk0FDC;
    int unk0FE0, unk0FE4;
    int unk0FE8, unk0FEC;
    int unk0FF0, unk0FF4;
    int unk0FF8, unk0FFC;
    int unk1000, unk1004;
    int unk1008, unk100C;
    int unk1010, unk1014;
    int unk1018, unk101C;
    int unk1020, unk1024;
    int unk1028, unk102C;
    int unk1030, unk1034;
    int unk1038, unk103C;
    int unk1040, unk1044;
    int unk1048, unk104C;
    int unk1050, unk1054;
    int unk1058, unk105C;
    int unk1060, unk1064;
    int unk1068, unk106C;
    int unk1070, unk1074;
    int unk1078, unk107C;
    int unk1080, unk1084;
    int unk1088, unk108C;
    int unk1090, unk1094;
    int unk1098, unk109C;
    int unk10A0, unk10A4;
    int unk10A8, unk10AC;
    int unk10B0, unk10B4;
    int unk10B8, unk10BC;
    int unk10C0, unk10C4;
    int unk10C8, unk10CC;
    int unk10D0, unk10D4;
    int unk10D8, unk10DC;
    int unk10E0, unk10E4;
    int unk10E8, unk10EC;
    int unk10F0, unk10F4;
    int unk10F8, unk10FC;
    int unk1100, unk1104;
    int unk1108, unk110C;
    int unk1110, unk1114;
    int unk1118, unk111C;
    int unk1120, unk1124;
    int unk1128, unk112C;
    int unk1130, unk1134;
    int unk1138, unk113C;
    int unk1140, unk1144;
    int unk1148, unk114C;
    int unk1150, unk1154;
    int unk1158, unk115C;
    int unk1160, unk1164;
    int unk1168, unk116C;
    int unk1170, unk1174;
    int unk1178, unk117C;
    int unk1180, unk1184;
    int unk1188, unk118C;
    int unk1190, unk1194;
    int unk1198, unk119C;
    int unk11A0, unk11A4;
    int unk11A8, unk11AC;
    int unk11B0, unk11B4;
    int unk11B8, unk11BC;
    int unk11C0, unk11C4;
    int unk11C8, unk11CC;
    int unk11D0, unk11D4;
    int unk11D8, unk11DC;
    int unk11E0, unk11E4;
    int unk11E8, unk11EC;
    int unk11F0, unk11F4;
    int unk11F8, unk11FC;
    int unk1200, unk1204;
    int unk1208, unk120C;
    int unk1210, unk1214;
    int unk1218, unk121C;
    int unk1220, unk1224;
    int unk1228, unk122C;
    int unk1230, unk1234;
    int unk1238, unk123C;
    int unk1240, unk1244;
    int unk1248, unk124C;
    int unk1250, unk1254;
    int unk1258, unk125C;
    int unk1260, unk1264;
    int unk1268, unk126C;
    int unk1270, unk1274;
    int unk1278, unk127C;
    int unk1280, unk1284;
    int unk1288, unk128C;
    int unk1290, unk1294;
    int unk1298, unk129C;
    int unk12A0, unk12A4;
    int unk12A8, unk12AC;
    int unk12B0, unk12B4;
    int unk12B8, unk12BC;
    int unk12C0, unk12C4;
    int unk12C8, unk12CC;
    int unk12D0, unk12D4;
    int unk12D8, unk12DC;
    int unk12E0, unk12E4;
    int unk12E8, unk12EC;
    int unk12F0, unk12F4;
    int unk12F8, unk12FC;
    int unk1300, unk1304;
    int unk1308, unk130C;
    int unk1310, unk1314;
    int unk1318, unk131C;
    int unk1320, unk1324;
    int unk1328, unk132C;
    int unk1330, unk1334;
    int unk1338, unk133C;
    int unk1340, unk1344;
    int unk1348, unk134C;
    int unk1350, unk1354;
    int unk1358, unk135C;
    int unk1360, unk1364;
    int unk1368, unk136C;
    int unk1370, unk1374;
    int unk1378, unk137C;
    int unk1380, unk1384;
    int unk1388, unk138C;
    int unk1390, unk1394;
    int unk1398, unk139C;
    int unk13A0, unk13A4;
    int unk13A8, unk13AC;
    int unk13B0, unk13B4;
    int unk13B8, unk13BC;
    int unk13C0, unk13C4;
    int unk13C8, unk13CC;
    int unk13D0, unk13D4;
    int unk13D8, unk13DC;
    int unk13E0, unk13E4;
    int unk13E8, unk13EC;
    int unk13F0, unk13F4;
    int unk13F8, unk13FC;
    int unk1400, unk1404;
    int unk1408, unk140C;
    int unk1410, unk1414;
    int unk1418, unk141C;
    int unk1420, unk1424;
    int unk1428, unk142C;
    int unk1430, unk1434;
    int unk1438, unk143C;
    int unk1440, unk1444;
    int unk1448, unk144C;
    int unk1450, unk1454;
    int unk1458, unk145C;
    int unk1460, unk1464;
    int unk1468, unk146C;
    int unk1470, unk1474;
    int unk1478, unk147C;
    int unk1480, unk1484;
    int unk1488, unk148C;
    int unk1490, unk1494;
    int unk1498, unk149C;
    int unk14A0, unk14A4;
    int unk14A8, unk14AC;
    int unk14B0, unk14B4;
    int unk14B8, unk14BC;
    int unk14C0, unk14C4;
    int unk14C8, unk14CC;
    int unk14D0, unk14D4;
    int unk14D8, unk14DC;
    int unk14E0, unk14E4;
    int unk14E8, unk14EC;
    int unk14F0, unk14F4;
    int unk14F8, unk14FC;
    int unk1500, unk1504;
    int unk1508, unk150C;
    int unk1510, unk1514;
    int unk1518, unk151C;
    int unk1520, unk1524;
    int unk1528, unk152C;
    int unk1530, unk1534;
    int unk1538, unk153C;
    int unk1540, unk1544;
    int unk1548, unk154C;
    int unk1550, unk1554;
    int unk1558, unk155C;
    int unk1560, unk1564;
    int unk1568, unk156C;
    int unk1570, unk1574;
    int unk1578, unk157C;
    int unk1580, unk1584;
    int unk1588, unk158C;
    int unk1590, unk1594;
    int unk1598, unk159C;
    int unk15A0, unk15A4;
    int unk15A8, unk15AC;
    int unk15B0, unk15B4;
    int unk15B8, unk15BC;
    int unk15C0, unk15C4;
    int unk15C8, unk15CC;
    int unk15D0, unk15D4;
    int unk15D8, unk15DC;
    int unk15E0, unk15E4;
    int unk15E8, unk15EC;
    int unk15F0, unk15F4;
    int unk15F8, unk15FC;
    int unk1600, unk1604;
    int unk1608, unk160C;
    int unk1610, unk1614;
    int unk1618, unk161C;
    int unk1620, unk1624;
    int unk1628, unk162C;
    int unk1630, unk1634;
    int unk1638, unk163C;
    int unk1640, unk1644;
    int unk1648, unk164C;
    int unk1650, unk1654;
    int unk1658, unk165C;
    int unk1660, unk1664;
    int unk1668, unk166C;
    int unk1670, unk1674;
    int unk1678, unk167C;
    int unk1680, unk1684;
    int unk1688, unk168C;
    int unk1690, unk1694;
    int unk1698, unk169C;
    int unk16A0, unk16A4;
    int unk16A8, unk16AC;
    int unk16B0, unk16B4;
    int unk16B8, unk16BC;
    int unk16C0, unk16C4;
    int unk16C8, unk16CC;
    int unk16D0, unk16D4;
    int unk16D8, unk16DC;
    int unk16E0, unk16E4;
    int unk16E8, unk16EC;
    int unk16F0, unk16F4;
    int unk16F8, unk16FC;
    int unk1700, unk1704;
    int unk1708, unk170C;
    int unk1710, unk1714;
    int unk1718, unk171C;
    int unk1720, unk1724;
    int unk1728, unk172C;
    int unk1730, unk1734;
    int unk1738, unk173C;
    int unk1740, unk1744;
    int unk1748, unk174C;
    int unk1750, unk1754;
    int unk1758, unk175C;
    int unk1760, unk1764;
    int unk1768, unk176C;
    int unk1770, unk1774;
    int unk1778, unk177C;
    int unk1780, unk1784;
    int unk1788, unk178C;
    int unk1790, unk1794;
    int unk1798, unk179C;
    int unk17A0, unk17A4;
    int unk17A8, unk17AC;
    int unk17B0, unk17B4;
    int unk17B8, unk17BC;
    int unk17C0, unk17C4;
    int unk17C8, unk17CC;
    int unk17D0, unk17D4;
    int unk17D8, unk17DC;
    int unk17E0, unk17E4;
    int unk17E8, unk17EC;
    int unk17F0, unk17F4;
    int unk17F8, unk17FC;
    int unk1800, unk1804;
    int unk1808, unk180C;
    int unk1810, unk1814;
    int unk1818, unk181C;
    int unk1820, unk1824;
    int unk1828, unk182C;
    int unk1830, unk1834;
    int unk1838, unk183C;
    int unk1840, unk1844;
    int unk1848, unk184C;
    int unk1850, unk1854;
    int unk1858, unk185C;
    int unk1860, unk1864;
    int unk1868, unk186C;
    int unk1870, unk1874;
    int unk1878, unk187C;
    int unk1880, unk1884;
    int unk1888, unk188C;
    int unk1890, unk1894;
    int unk1898, unk189C;
    int unk18A0, unk18A4;
    int unk18A8, unk18AC;
    int unk18B0, unk18B4;
    int unk18B8, unk18BC;
    int unk18C0, unk18C4;
    int unk18C8, unk18CC;
    int unk18D0, unk18D4;
    int unk18D8, unk18DC;
    int unk18E0, unk18E4;
    int unk18E8, unk18EC;
    int unk18F0, unk18F4;
    int unk18F8, unk18FC;
    int unk1900, unk1904;
    int unk1908, unk190C;
    int unk1910, unk1914;
    int unk1918, unk191C;
    int unk1920, unk1924;
    int unk1928, unk192C;
    int unk1930, unk1934;
    int unk1938, unk193C;
    int unk1940, unk1944;
    int unk1948, unk194C;
    int unk1950, unk1954;
    int unk1958, unk195C;
    int unk1960, unk1964;
    int unk1968, unk196C;
    int unk1970, unk1974;
    int unk1978, unk197C;
    int unk1980, unk1984;
    int unk1988, unk198C;
    int unk1990, unk1994;
    int unk1998, unk199C;
    int unk19A0, unk19A4;
    int unk19A8, unk19AC;
    int unk19B0, unk19B4;
    int unk19B8, unk19BC;
    int unk19C0, unk19C4;
    int unk19C8, unk19CC;
    int unk19D0, unk19D4;
    int unk19D8, unk19DC;
    int unk19E0, unk19E4;
    int unk19E8, unk19EC;
    int unk19F0, unk19F4;
    int unk19F8, unk19FC;
    int unk1A00, unk1A04;
    int unk1A08, unk1A0C;
    int unk1A10, unk1A14;
    int unk1A18, unk1A1C;
    int unk1A20, unk1A24;
    int unk1A28, unk1A2C;
    int unk1A30, unk1A34;
    int unk1A38, unk1A3C;
    int unk1A40, unk1A44;
    int unk1A48, unk1A4C;
    int unk1A50, unk1A54;
    int unk1A58, unk1A5C;
    int unk1A60, unk1A64;
    int unk1A68, unk1A6C;
    int unk1A70, unk1A74;
    int unk1A78, unk1A7C;
    int unk1A80, unk1A84;
    int unk1A88, unk1A8C;
    int unk1A90, unk1A94;
    int unk1A98, unk1A9C;
    int unk1AA0, unk1AA4;
    int unk1AA8, unk1AAC;
    int unk1AB0, unk1AB4;
    int unk1AB8, unk1ABC;
    int unk1AC0, unk1AC4;
    int unk1AC8, unk1ACC;
    int unk1AD0, unk1AD4;
    int unk1AD8, unk1ADC;
    int unk1AE0, unk1AE4;
    int unk1AE8, unk1AEC;
    int unk1AF0, unk1AF4;
    int unk1AF8, unk1AFC;
    int unk1B00, unk1B04;
    int unk1B08, unk1B0C;
    int unk1B10, unk1B14;
    int unk1B18, unk1B1C;
    int unk1B20, unk1B24;
    int unk1B28, unk1B2C;
    int unk1B30, unk1B34;
    int unk1B38, unk1B3C;
    int unk1B40, unk1B44;
    int unk1B48, unk1B4C;
    int unk1B50, unk1B54;
    int unk1B58, unk1B5C;
    int unk1B60, unk1B64;
    int unk1B68, unk1B6C;
    int unk1B70, unk1B74;
    int unk1B78, unk1B7C;
    int unk1B80, unk1B84;
    int unk1B88, unk1B8C;
    int unk1B90, unk1B94;
    int unk1B98, unk1B9C;
    int unk1BA0, unk1BA4;
    int unk1BA8, unk1BAC;
    int unk1BB0, unk1BB4;
    int unk1BB8, unk1BBC;
    int unk1BC0, unk1BC4;
    int unk1BC8, unk1BCC;
    int unk1BD0, unk1BD4;
    int unk1BD8, unk1BDC;
    int unk1BE0, unk1BE4;
    int unk1BE8, unk1BEC;
    int unk1BF0, unk1BF4;
    int unk1BF8, unk1BFC;
    int unk1C00, unk1C04;
    int unk1C08, unk1C0C;
    int unk1C10, unk1C14;
    int unk1C18, unk1C1C;
    int unk1C20, unk1C24;
    int unk1C28, unk1C2C;
    int unk1C30, unk1C34;
    int unk1C38, unk1C3C;
    int unk1C40, unk1C44;
    int unk1C48, unk1C4C;
    int unk1C50, unk1C54;
    int unk1C58, unk1C5C;
    int unk1C60, unk1C64;
    int unk1C68, unk1C6C;
    int unk1C70, unk1C74;
    int unk1C78, unk1C7C;
    int unk1C80, unk1C84;
    int unk1C88, unk1C8C;
    int unk1C90, unk1C94;
    int unk1C98, unk1C9C;
    int unk1CA0, unk1CA4;
    int unk1CA8, unk1CAC;
    int unk1CB0, unk1CB4;
    int unk1CB8, unk1CBC;
    int unk1CC0, unk1CC4;
    int unk1CC8, unk1CCC;
    int unk1CD0, unk1CD4;
    int unk1CD8, unk1CDC;
    int unk1CE0, unk1CE4;
    int unk1CE8, unk1CEC;
    int unk1CF0, unk1CF4;
    int unk1CF8, unk1CFC;
    int unk1D00, unk1D04;
    int unk1D08, unk1D0C;
    int unk1D10, unk1D14;
    int unk1D18, unk1D1C;
    int unk1D20, unk1D24;
    int unk1D28, unk1D2C;
    int unk1D30, unk1D34;
    int unk1D38, unk1D3C;
    int unk1D40, unk1D44;
    int unk1D48, unk1D4C;
    int unk1D50, unk1D54;
    int unk1D58, unk1D5C;
    int unk1D60, unk1D64;
    int unk1D68, unk1D6C;
    int unk1D70, unk1D74;
    int unk1D78, unk1D7C;
    int unk1D80, unk1D84;
    int unk1D88, unk1D8C;
    int unk1D90, unk1D94;
    int unk1D98, unk1D9C;
    int unk1DA0, unk1DA4;
    int unk1DA8, unk1DAC;
    int unk1DB0, unk1DB4;
    int unk1DB8, unk1DBC;
    int unk1DC0, unk1DC4;
    int unk1DC8, unk1DCC;
    int unk1DD0, unk1DD4;
    int unk1DD8, unk1DDC;
    int unk1DE0, unk1DE4;
    int unk1DE8, unk1DEC;
    int unk1DF0, unk1DF4;
    int unk1DF8, unk1DFC;
    int unk1E00, unk1E04;
    int unk1E08, unk1E0C;
    int unk1E10, unk1E14;
    int unk1E18, unk1E1C;
    int unk1E20, unk1E24;
    int unk1E28, unk1E2C;
    int unk1E30, unk1E34;
    int unk1E38, unk1E3C;
    int unk1E40, unk1E44;
    int unk1E48, unk1E4C;
    int unk1E50, unk1E54;
    int unk1E58, unk1E5C;
    int unk1E60, unk1E64;
    int unk1E68, unk1E6C;
    int unk1E70, unk1E74;
    int unk1E78, unk1E7C;
    int unk1E80, unk1E84;
    int unk1E88, unk1E8C;
    int unk1E90, unk1E94;
    int unk1E98, unk1E9C;
    int unk1EA0, unk1EA4;
    int unk1EA8, unk1EAC;
    int unk1EB0, unk1EB4;
    int unk1EB8, unk1EBC;
    int unk1EC0, unk1EC4;
    int unk1EC8, unk1ECC;
    int unk1ED0, unk1ED4;
    int unk1ED8, unk1EDC;
    int unk1EE0, unk1EE4;
    int unk1EE8, unk1EEC;
    int unk1EF0, unk1EF4;
    int unk1EF8, unk1EFC;
    int unk1F00, unk1F04;
    int unk1F08, unk1F0C;
    int unk1F10, unk1F14;
    int unk1F18, unk1F1C;
    int unk1F20, unk1F24;
    int unk1F28, unk1F2C;
    int unk1F30, unk1F34;
    int unk1F38, unk1F3C;
    int unk1F40, unk1F44;
    int unk1F48, unk1F4C;
    int unk1F50, unk1F54;
    int unk1F58, unk1F5C;
    int unk1F60, unk1F64;
    int unk1F68, unk1F6C;
    int unk1F70, unk1F74;
    int unk1F78, unk1F7C;
    int unk1F80, unk1F84;
    int unk1F88, unk1F8C;
    int unk1F90, unk1F94;
    int unk1F98, unk1F9C;
    int unk1FA0, unk1FA4;
    int unk1FA8, unk1FAC;
    int unk1FB0, unk1FB4;
    int unk1FB8, unk1FBC;
    int unk1FC0, unk1FC4;
    int unk1FC8, unk1FCC;
    int unk1FD0, unk1FD4;
    int unk1FD8, unk1FDC;
    int unk1FE0, unk1FE4;
    int unk1FE8, unk1FEC;
    int unk1FF0, unk1FF4;
    int unk1FF8, unk1FFC;
    int unk2000, unk2004;
    int unk2008, unk200C;
    int unk2010, unk2014;
    int unk2018, unk201C;
    int unk2020, unk2024;
    int unk2028, unk202C;
    int unk2030, unk2034;
    int unk2038, unk203C;
    int unk2040, unk2044;
    int unk2048, unk204C;
    int unk2050, unk2054;
};
struct FUN_006b8340 : BuilderBase
{
    int unk2058, unk205C;
    int unk2060, unk2064;
    int unk2068, unk206C;
    int unk2070, unk2074;
    int unk2078, unk207C;
    int unk2080, unk2084;
    int unk2088, unk208C;
    int unk2090, unk2094;
    int unk2098, unk209C;
    FUN_006b8340();
    ~FUN_006b8340();
    bool SetupNavMeshSearch(int, const NiPoint3&, Nav*, const NiPoint3&, Nav*, PathBuilderDetailedPathInfos&, FUN_005e04c0&,
                            int);
};
struct FUN_006f33b0 : BuilderBase
{
    int unk2058, unk205C;
    int unk2060, unk2064;
    int unk2068, unk206C;
    int unk2070, unk2074;
    int unk2078, unk207C;
    int unk2080, unk2084;
    int unk2088, unk208C;
    int unk2090, unk2094;
    int unk2098, unk209C;
    int unk20A0, unk20A4;
    int unk20A8, unk20AC;
    int unk20B0;
    FUN_006f33b0();
    ~FUN_006f33b0();
    bool InitDoorSearch(Location*, Location*, Result*, int, float, int, int);
};
// Builds a path between two locations via a door-aware builder, records parent-space nodes and door entries in result, else falls back to InitDoorSearch.
// @fnv 0x006d4f70
bool BuildPathWithDoors(Location* start, Location* end, Result* result, int a4, int a5)
{
    if (start->FUN_006dd6f0(0) && end->FUN_006dd6f0(0))
    {
        FUN_006b8340 builder;
        PathBuilderDetailedPathInfos infos;
        FUN_005e04c0 doors;
        if (builder.SetupNavMeshSearch(a4, start->FUN_005c3420(), start->TESMain_GetThread(), end->FUN_005c3420(),
                                       end->TESMain_GetThread(), infos, doors, a5))
        {
            ParentSpaceNode node;
            node.unk04 = infos.FUN_00877a30(0)->NavMeshInfo_GetWorldSpace();
            node.unk08 = infos.FUN_00877a30(0)->GetInteriorCell();
            node.unk00 = infos.FUN_00877a30(0)->NavMeshInfo_GetWorldSpace() != 0;
            result->BSSimpleArray_ParentSpaceNode_1024_Add(node);
            for (unsigned i = 0; i < doors.FUN_0044ddc0(); ++i)
            {
                if (doors.FUN_00877a30(i))
                {
                    FUN_006d5320 entry;
                    entry.unk00 = doors.FUN_00877a30(i);
                    entry.unk04 = doors.FUN_00877a30(i)->FUN_00568e50()->FUN_00717e50();
                    result->unk10.BSSimpleArray_TeleportLink_1024_Add(entry);
                    ParentSpaceNode next;
                    next.unk04 = infos.FUN_00877a30(i + 1)->NavMeshInfo_GetWorldSpace();
                    next.unk08 = infos.FUN_00877a30(i + 1)->GetInteriorCell();
                    next.unk00 = infos.FUN_00877a30(i + 1)->NavMeshInfo_GetWorldSpace() != 0;
                    result->BSSimpleArray_ParentSpaceNode_1024_Add(next);
                }
            }
            result->unk20 = start->FUN_005c3420();
            result->unk2C = end->FUN_005c3420();
            return true;
        }
    }
    FUN_006f33b0 fallback;
    return fallback.InitDoorSearch(start, end, result, 0, 0.0f, a4, a5);
}
