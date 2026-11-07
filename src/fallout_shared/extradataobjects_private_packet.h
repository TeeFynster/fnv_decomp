// Authored header for fallout_shared/extradataobjects.cpp hand matches.
//
// BSExtraData is declared locally (not included from the canonical tree)
// because the canonical BSExtraData.h carries layout only, while every Extra
// constructor below must invoke the base initializer BSExtraData(etype) (the
// 0x0040ec80 call that stores the base vtable, the type tag and a null next
// pointer before the derived vtable store). Request: promote
// BSExtraData(unsigned char) into the canonical BSExtraData.h so this local
// declaration can be replaced by the canonical include; layouts here are
// identical to the canonical ones.
//
// with their layout asserts; only matched member-function declarations are
// existed), so its two members come from the 0x00414010 ctor bytes (8-byte
// construction: pointer at +0x0, float at +0x4) and the operator new(8)
// construction sites. Each Extra class declares its virtual destructor so
// the compiler emits the vtable store the originals contain.
#ifndef FNV_EXTRADATAOBJECTS_PRIVATE_PACKET_H
#define FNV_EXTRADATAOBJECTS_PRIVATE_PACKET_H

#include "extradataobjects_private_layout_support.h"

class TESObjectREFR;
class TESObjectCELL;
class TESGlobal;
class TESKey;
class Script;
class ScriptLocals;
class RagDollData;
class Point3Offset;
class TESForm;

class BSExtraData
{
  public:
    // Promoted form: the compiler vptr occupies +0x0, so the explicit
    unsigned char m_ucExtraDataType;  // +0x4
    unsigned char layoutPadding5[3];
    BSExtraData* pNext;  // +0x8

    virtual ~BSExtraData();
    BSExtraData(unsigned char aEtype);
    bool Compare(BSExtraData*);
};
FNV_STATIC_ASSERT(sizeof(BSExtraData) == 0xC);
FNV_STATIC_ASSERT(offsetof(BSExtraData, m_ucExtraDataType) == 0x4);
FNV_STATIC_ASSERT(offsetof(BSExtraData, pNext) == 0x8);

// 8-byte activation record. Proved by the 0x00414010 ctor (stores a pointer
// at +0x0 and +0.0f at +0x4, no base construction) and by operator new(8)
// construction sites that fill +0x0 with a reference and link the record
// into a child list.
class ReferenceFloatEntry
{
  public:
    TESObjectREFR* m_pWorldReferenceInfo;  // +0x0, 4 bytes
    float m_fDelay;               // +0x4, 4 bytes

    ReferenceFloatEntry();
};
FNV_STATIC_ASSERT(sizeof(ReferenceFloatEntry) == 8);
FNV_STATIC_ASSERT(offsetof(ReferenceFloatEntry, m_pWorldReferenceInfo) == 0);
FNV_STATIC_ASSERT(offsetof(ReferenceFloatEntry, m_fDelay) == 4);

// matched member-function declaration is added.
enum LOCK_LEVEL
{
    LOCK_LEVEL_LL_VERYEASY = 0,
    LOCK_LEVEL_LL_EASY = 1,
    LOCK_LEVEL_LL_AVERAGE = 2,
    LOCK_LEVEL_LL_HARD = 3,
    LOCK_LEVEL_LL_VERYHARD = 4,
    LOCK_LEVEL_LL_IMPOSSIBLE = 5,
    LOCK_LEVEL_LL_COUNT = 6
};

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

    void SetLocked(bool aLocked);
    int GetLevel(TESObjectREFR*);
    static int ConvertLockLevel(int);
    static int EnumToNumericValue(LOCK_LEVEL);
    int GetLockLevel(TESObjectREFR*);
    bool MeetsMinimumLockLevel();
};
FNV_STATIC_ASSERT(sizeof(LockExtraData) == 20);
FNV_STATIC_ASSERT(offsetof(LockExtraData, m_uiLockState) == 0);
FNV_STATIC_ASSERT(offsetof(LockExtraData, pKey) == 4);
FNV_STATIC_ASSERT(offsetof(LockExtraData, cFlags) == 8);
FNV_STATIC_ASSERT(offsetof(LockExtraData, m_uiLockDifficulty) == 12);
FNV_STATIC_ASSERT(offsetof(LockExtraData, m_uiLockValue) == 16);

// matched member-function declarations are added.
class ExtraUsedMarkers : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    unsigned int m_uiUsedMarkerFlags;  // +0xC, 4 bytes

    virtual ~ExtraUsedMarkers();
    void SetUsedMarker(unsigned int aMarker, bool aUsed);
};
FNV_STATIC_ASSERT(sizeof(ExtraUsedMarkers) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraUsedMarkers, m_uiUsedMarkerFlags) == 12);

class ExtraAction : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    unsigned char eAction;  // +0xC, 1 bytes
    unsigned char layoutPaddingD[3];
    TESObjectREFR* m_pActionReference;  // +0x10, 4 bytes

    virtual ~ExtraAction();
    ExtraAction();
};
FNV_STATIC_ASSERT(sizeof(ExtraAction) == 20);
FNV_STATIC_ASSERT(offsetof(ExtraAction, eAction) == 12);
FNV_STATIC_ASSERT(offsetof(ExtraAction, m_pActionReference) == 16);

class ExtraGlobal : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    TESGlobal* pGlobalForm;  // +0xC, 4 bytes

    virtual ~ExtraGlobal();
    ExtraGlobal(TESGlobal* aGlobal);
};
FNV_STATIC_ASSERT(sizeof(ExtraGlobal) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraGlobal, pGlobalForm) == 12);

class ExtraCount : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    short iCount;  // +0xC, 2 bytes
    unsigned char layoutPaddingE[2];

    virtual ~ExtraCount();
    ExtraCount(short aCount);
};
FNV_STATIC_ASSERT(sizeof(ExtraCount) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraCount, iCount) == 12);

class ExtraScript : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    Script* pScript;          // +0xC, 4 bytes
    ScriptLocals* m_pLocals;  // +0x10, 4 bytes

    virtual ~ExtraScript();
    ExtraScript(Script* aScript);
};
FNV_STATIC_ASSERT(sizeof(ExtraScript) == 20);
FNV_STATIC_ASSERT(offsetof(ExtraScript, pScript) == 12);
FNV_STATIC_ASSERT(offsetof(ExtraScript, m_pLocals) == 16);

class ExtraLeveledItem : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    int iIndex;             // +0xC, 4 bytes
    bool m_bIsLeveledItem;  // +0x10, 1 bytes
    unsigned char layoutPadding11[3];

    virtual ~ExtraLeveledItem();
    ExtraLeveledItem(int aIndex);
    bool Compare(BSExtraData*);
};
FNV_STATIC_ASSERT(sizeof(ExtraLeveledItem) == 20);
FNV_STATIC_ASSERT(offsetof(ExtraLeveledItem, iIndex) == 12);
FNV_STATIC_ASSERT(offsetof(ExtraLeveledItem, m_bIsLeveledItem) == 16);

class ExtraPersistentCell : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    TESObjectCELL* m_pCell;  // +0xC, 4 bytes

    virtual ~ExtraPersistentCell();
    ExtraPersistentCell(TESObjectCELL* aCell);
};
FNV_STATIC_ASSERT(sizeof(ExtraPersistentCell) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraPersistentCell, m_pCell) == 12);

class ExtraRagDollData : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    RagDollData* m_pRagDollData;  // +0xC, 4 bytes

    virtual ~ExtraRagDollData();
    ExtraRagDollData();
};
FNV_STATIC_ASSERT(sizeof(ExtraRagDollData) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraRagDollData, m_pRagDollData) == 12);

class ExtraReservedMarkers : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    unsigned int m_uiReservedMarkers;  // +0xC, 4 bytes

    virtual ~ExtraReservedMarkers();
    ExtraReservedMarkers();
};
FNV_STATIC_ASSERT(sizeof(ExtraReservedMarkers) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraReservedMarkers, m_uiReservedMarkers) == 12);

class ExtraStartingWorldOrCell : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    TESForm* m_pStartingWorldOrCell;  // +0xC, 4 bytes

    virtual ~ExtraStartingWorldOrCell();
    ExtraStartingWorldOrCell();
};
FNV_STATIC_ASSERT(sizeof(ExtraStartingWorldOrCell) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraStartingWorldOrCell, m_pStartingWorldOrCell) == 12);

class ExtraMultiBoundData : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    Point3Offset* pBound;  // +0xC, 4 bytes

    virtual ~ExtraMultiBoundData();
    ExtraMultiBoundData();
};
FNV_STATIC_ASSERT(sizeof(ExtraMultiBoundData) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraMultiBoundData, pBound) == 12);

class ExtraPatrolRefInUseData : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    unsigned int User;  // +0xC, 4 bytes

    virtual ~ExtraPatrolRefInUseData();
};
FNV_STATIC_ASSERT(sizeof(ExtraPatrolRefInUseData) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraPatrolRefInUseData, User) == 12);

// vtbl 0x01015bdc (kVtbl_ExtraWorn, JIP-LN-NVSE); the 0x004322f0 ctor stores
// only the derived vtable after BSExtraData(0x16), so the class adds no data.
class ExtraWorn : public BSExtraData
{
  public:
    virtual ~ExtraWorn();
    ExtraWorn();
};

// Placeholder per the approved address-naming scheme. 0x00432f30 is a
// thiscall whose only statement invokes the BSExtraData base destructor on
// this: 19 bytes, no derived vtable store (checked: a declared derived dtor
// emits one, so this is not a class destructor). Its real identity is
// address.
class FUN_00432f30_D : public BSExtraData
{
  public:
    void FUN_00432f30();
};

extern char* DAT_011c6444;
class ExtraSecuritronFace
{
  public:
    static char* GetPersonality();
};
class ExtraLock
{
  public:
    char pad[12];
    LockExtraData* lock;
    void Unlock();
    void Lock();
};
template <class T> class NiTNewInterface;
#include "../../include/NiTArray.h"
enum MagicSystem__CastingType
{
    CastingTypeNone
};
class TESEnchantableForm
{
  public:
    void SetCastingType(MagicSystem__CastingType);
};
class BaseProcess
{
  public:
    int vptr;
    TESEnchantableForm procedure;
    void SetPackageInfoState(int);
};
class NavMeshInfo;
class TESForm
{
  public:
    unsigned int GetFormID();
};
class Actor : public TESForm
{
  public:
    unsigned short GetLevel();
};
template <class T, unsigned int N> class BSSimpleArray
{
  public:
    template <class U> unsigned int Find(U&, unsigned int, bool(__cdecl*)(U&, U&));
    unsigned int Add(T&);
};
bool __cdecl Actor_AreReferencedValuesEqual(NavMeshInfo*&, NavMeshInfo*&);
class ExtraGuardedRefData
{
  public:
    char pad[12];
    BSSimpleArray<NavMeshInfo*, 1024> guards;
    void AddGuardingActor(Actor*);
};

extern char DAT_01183b2c;
extern char DAT_01184680;
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
class TESFaction;
class BGSPerkEntry
{
  public:
    TESFaction* faction;
};
class QuestDialogueInfo;
class TESTopic
{
  public:
    BSSimpleList<QuestDialogueInfo*>* GetQuestInfoList() const;
};
// Names of nested/template specializations use the canonical generator identifier mapping.
class ExtraFactionChanges;
class FactionReaction;
class ExtraFactionChanges : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    BSSimpleList<FactionReaction*>* m_pFactionChanges;  // +0xC, 4 bytes
    bool HasFactionEntry(TESFaction*);
    void RemoveFaction(TESFaction*);
    void SetFactionRank(TESFaction*, int);
    // ExtraFactionChanges
    // void __cdecl ExtraFactionChanges::*()
    // void __cdecl ExtraFactionChanges::*(TESFaction*)
    // void __cdecl ExtraFactionChanges::*(TESFaction*, int)
    // void __cdecl ExtraFactionChanges::*(TESFaction*, int)
    // bool __cdecl ExtraFactionChanges::*(TESFaction*)
    // bool __cdecl ExtraFactionChanges::*(TESFaction*)
    // int __cdecl ExtraFactionChanges::*(TESFaction*)
    // void __cdecl ExtraFactionChanges::*(TESActorBase*)
    // ExtraFactionChanges& __cdecl ExtraFactionChanges::*(const ExtraFactionChanges&)
    // void __cdecl ExtraFactionChanges::*()
};
FNV_STATIC_ASSERT(sizeof(ExtraFactionChanges) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraFactionChanges, m_pFactionChanges) == 12);

class PlayerCharacter;
extern PlayerCharacter* g_thePlayer;
void __cdecl ApplyPerkModifiers(int, Actor*, ...);

// Genuine declaration-only members used through pointers. PC ABIs are
// supplied by IDENTITIES.md for 00567e10 and 0087f9f0.
class TESObjectREFR
{
  public:
    unsigned int GetReferenceLevel(bool allowShift);
};
class PlayerCharacter : public Actor
{
};

#endif
