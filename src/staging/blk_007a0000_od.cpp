#include "../../include/BSStringT.h"

// src/staging/blk_007a0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/BSSimpleArray.h"
#include "../../include/NiPointer.h"
#include "../../include/EffectSetting.h"
#include "../../include/Menu.h"
#include "../../include/MapMenu.h"
#include "../../include/NiPoint3.h"
#include "../../include/SL.h"

struct FUN_007a1400_class
{
    void Tile_ClearNeedsUpdate(int flags);
};

// @fnv 0x007a1400
// src: COMMUNITY 0x007a1400
void FUN_007a1400_class::Tile_ClearNeedsUpdate(int flags)
{
    if (*(int*)((char*)this + 0x30) & flags)
        *(int*)((char*)this + 0x30) ^= flags;
}

struct FUN_007a1430_Class
{
    unsigned char m_data[0x92];
    unsigned char m_flag;
    void SetFlag(unsigned char value);
};

// @fnv 0x007a1430
void FUN_007a1430_Class::SetFlag(unsigned char value)
{
    m_flag = value;
}

struct Unk65
{
    void FUN_0065de30(int);
};

struct Unk65a
{
    Unk65* __thiscall EvaluateValue_007ab230(Unk65* other);
};

// @fnv 0x007ab230
// src: GUESS 0x007ab230 (confidence: low)
Unk65* __thiscall Unk65a::EvaluateValue_007ab230(Unk65* other)
{
    other->FUN_0065de30((int)this);
    return other;
}

// Opaque MessageMenu element types; the arrays never dereference their elements here.
struct MessageMenuEntry;
struct PerkActivation;

// @fnv 0x007ab590
template <>
BSSimpleArray<MessageMenuEntry*, 1024>::BSSimpleArray()
{
    BSSimpleArray_float_1024_InitialSetup(0, false);
}

// @fnv 0x007ab610
template <>
BSSimpleArray<PerkActivation*, 1024>::BSSimpleArray()
{
    BSSimpleArray_float_1024_InitialSetup(0, false);
}

// @fnv 0x007ab5f0
template <>
BSSimpleArray<MessageMenuEntry*, 1024>::~BSSimpleArray()
{
    Clear(true);
}

// @fnv 0x007ab670
template <>
BSSimpleArray<PerkActivation*, 1024>::~BSSimpleArray()
{
    Clear(true);
}

struct FUN_007adcc0_class
{
    void SetAllow(bool abAllow);
};

// @fnv 0x007adcc0
void FUN_007adcc0_class::SetAllow(bool abAllow)
{
    ((unsigned char*)this)[0x75d] = abAllow;
}

struct FUN_007b8f10_Class
{
    unsigned int __thiscall GetField630();
};

// @fnv 0x007b8f10
unsigned int __thiscall FUN_007b8f10_Class::GetField630()
{
    return *(unsigned int*)((char*)this + 0x630);
}

void __cdecl BSstrupr(char*, int);

struct FUN_007b52a0_class
{
    char* m_ptr;
    unsigned short m_uiItemCount;
    void __thiscall BSStringT_MakeUpper();
};

// @fnv 0x007b52a0
// src: COMMUNITY 0x007b52a0
void __thiscall FUN_007b52a0_class::BSStringT_MakeUpper()
{
    if (m_ptr)
        BSstrupr(m_ptr, m_uiItemCount + 1);
}

extern MapMenu* DAT_011da368;
// The parent-world accessor shares 0x004fd380 with EffectSetting::GetLight (pointer at offset 0xc0).
// @fnv 0x007a1880
// src: XBOX_PDB 0x007a1880
void __cdecl MapMenu_SetRootMapSpace(TESWorldSpace* worldspace)
{
    if (DAT_011da368)
    {
        TESWorldSpace* previous = DAT_011da368->m_pCurrentWorldspace;
        DAT_011da368->m_pCurrentWorldspace = worldspace;
        while (DAT_011da368->m_pCurrentWorldspace && reinterpret_cast<EffectSetting*>(DAT_011da368->m_pCurrentWorldspace)->GetLight())
            DAT_011da368->m_pCurrentWorldspace = reinterpret_cast<TESWorldSpace*>(reinterpret_cast<EffectSetting*>(DAT_011da368->m_pCurrentWorldspace)->GetLight());
        DAT_011da368->m_bLocalMapMode = previous != DAT_011da368->m_pCurrentWorldspace;
    }
}

struct NavMeshInfo;
struct NavMeshInfo4
{
    NavMeshInfo* m_pObjectInfo;
    unsigned int m_uiSize;
    unsigned int m_uiCount;
    unsigned int m_uiValue1;
};
struct FUN_007a1450_Class
{
    unsigned char m_data[0x68];
    NavMeshInfo4 m_pMesh;
    void SetNavMeshInfo(NavMeshInfo4& source);
};
// @fnv 0x007a1450
void FUN_007a1450_Class::SetNavMeshInfo(NavMeshInfo4& source)
{
    m_pMesh = source;
}

struct FUN_007a8030_Class
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    unsigned int ListBox_TESChallenge_NumUnfiltered(int);
    virtual void FUN_007a8030_v5(int);
};

struct FUN_007a62b0_Class : FUN_007a8030_Class
{
    void ListBox_TESChallenge_GetLastItem();
};

// Calls FUN_007a8030 with 0, subtracts 1 from the result, and passes it to FUN_007a8030_v5.
// @fnv 0x007a62b0
// src: XBOX_PDB 0x007a62b0
void FUN_007a62b0_Class::ListBox_TESChallenge_GetLastItem()
{
    FUN_007a8030_v5(ListBox_TESChallenge_NumUnfiltered(0) - 1);
}


// Destructs the object and, if bit 0 of flags is set, frees its memory, then returns the pointer.
// @fnv 0x007a86b0
template <> BSStringT<char>* BSStringT<char>::FUN_007a86b0(unsigned int flags)
{
    this->~BSStringT();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern int DAT_011dea14;

// @fnv 0x007a1480
// src: XBOX_PDB 0x007a1480
int __cdecl Main_LandLODNode()
{
    return DAT_011dea14;
}

struct NavMeshPayload
{
    bool Equals(int mode);
};
struct NavMeshListNode
{
    void* m_payload;
    unsigned int m_uiEdgeIndex;
    unsigned int m_uiContentCount;
    NavMeshListNode* m_next;
    NavMeshListNode(NavMeshPayload* payload);
    bool IsNotEqual(int mode);
    void FUN_00418900(NavMeshPayload* payload);
    void BSSimpleList_BSSoundHandle_AddTail(NavMeshPayload* payload);
};
// @fnv 0x007a19a0
// src: XBOX_PDB 0x007a19a0
void NavMeshListNode::BSSimpleList_BSSoundHandle_AddTail(NavMeshPayload* payload)
{
    if (payload->Equals(0))
        return;
    NavMeshListNode* current = this;
    while (current->m_next)
        current = current->m_next;
    if (current->IsNotEqual(0))
        current->m_next = new NavMeshListNode(payload);
    else
        current->FUN_00418900(payload);
}

struct FUN_0046ffb0
{
    ~FUN_0046ffb0();
};

struct FUN_007a28c0
{
    virtual ~FUN_007a28c0();
    FUN_0046ffb0 member;
    void ClearEntries();
};

void __cdecl InterfaceManager_UnregisterListBox(FUN_007a28c0* object);

// Calls ClearEntries, then passes this to FUN_007211c0 as part of destruction.
// @fnv 0x007a28c0
FUN_007a28c0::~FUN_007a28c0()
{
    ClearEntries();
    InterfaceManager_UnregisterListBox(this);
}

class SubObj
{
  public:
    int unk00;
    ~SubObj();
};

class FUN_007a37b0
{
  public:
    virtual void unk00();
    void Cleanup();
    SubObj m_sub;
    ~FUN_007a37b0();
};

void __cdecl ReleaseObject(FUN_007a37b0* p);

// @fnv 0x007a37b0
FUN_007a37b0::~FUN_007a37b0()
{
    Cleanup();
    ReleaseObject(this);
}

class FUN_007a4470_sub
{
  public:
    ~FUN_007a4470_sub();
    int m_00;
};

class FUN_007a4470_cls
{
  public:
    virtual ~FUN_007a4470_cls();
    void Step();
    FUN_007a4470_sub m_04;
};

void __cdecl InterfaceManager_UnregisterListBox(FUN_007a4470_cls* p);

// Calls Step, then passes this to FUN_007211c0 during destruction.
// @fnv 0x007a4470
FUN_007a4470_cls::~FUN_007a4470_cls()
{
    Step();
    InterfaceManager_UnregisterListBox(this);
}

struct FUN_007a51c0_m4
{
    int m_00;
    ~FUN_007a51c0_m4();
};

void __cdecl InterfaceManager_UnregisterListBox(void* p);

struct FUN_007a51c0_cls
{
    virtual ~FUN_007a51c0_cls();
    FUN_007a51c0_m4 m_04;

    void ReleaseStorage_007a54d0();
};

// @fnv 0x007a51c0
FUN_007a51c0_cls::~FUN_007a51c0_cls()
{
    ReleaseStorage_007a54d0();
    InterfaceManager_UnregisterListBox(this);
}

struct FUN_007a6220_class
{
    virtual void FUN_007a6220_v1();
    virtual void FUN_007a6220_v2();
    virtual void FUN_007a6220_v3();
    virtual void FUN_007a6220_v4();
    virtual void FUN_007a6220_v5();
    virtual void FUN_007a6220_v6(int value);

    int __thiscall GetUnfilteredCount(int value);

    void __thiscall ListBox_BGSNote_GetLastItem();
};

// Calls GetUnfilteredCount with 0, subtracts 1 from the result, and passes it to FUN_007a6220_v6.
// @fnv 0x007a6220
// src: XBOX_PDB 0x007a6220
void __thiscall FUN_007a6220_class::ListBox_BGSNote_GetLastItem()
{
    FUN_007a6220_v6(GetUnfilteredCount(0) - 1);
}

// FUN_007a6250 : thiscall member, no stack args.
// this->FUN_007a71b0(0) returns a count; the count-1 is passed to the
// virtual function living in vtable slot 5 (offset 0x14).
struct SpawnedObject
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(int value);

    int GetUnfilteredRaceCount(int mode);

    void ForwardCall_007a6250();
};

// Calls FUN_007a71b0 with 0, subtracts 1 from the result, and passes it to v05.
// @fnv 0x007a6250
// src: GUESS 0x007a6250 (confidence: low)
void SpawnedObject::ForwardCall_007a6250()
{
    this->v05(this->GetUnfilteredRaceCount(0) - 1);
}

struct SceneThing
{
    void __thiscall FUN_00700320(unsigned int flags, unsigned int index);
};

struct SceneInner
{
    SceneThing* m_00;
    unsigned int unk04;
    unsigned char m_flag08;
};

struct FUN_007a80e0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    unsigned short unk1e;
    float m_20;

    void AccumulateTileHeight(SceneThing* thing);
    void ListBox_TESChallenge_SetTotalListHeight();
    void UpdateHighlight();
    void InitSceneNodes();
};

// @fnv 0x007a80e0
void FUN_007a80e0_cls::InitSceneNodes()
{
    this->m_1c = 0;
    this->m_20 = 0.0f;
    for (SL* pNodeRef = this ? (SL*)((char*)this + 4) : 0;
         pNodeRef != 0 && pNodeRef->FUN_006815c0() != 0; pNodeRef = pNodeRef->FUN_00726070())
    {
        if (reinterpret_cast<SceneInner*>(pNodeRef->FUN_006815c0())->m_flag08 == 0)
        {
            reinterpret_cast<SceneInner*>(pNodeRef->FUN_006815c0())->m_00->FUN_00700320(0xfac, this->m_1c++);
            this->AccumulateTileHeight(reinterpret_cast<SceneInner*>(pNodeRef->FUN_006815c0())->m_00);
        }
    }
    this->ListBox_TESChallenge_SetTotalListHeight();
    this->UpdateHighlight();
}

// Sub-object with an out-of-line destructor (shared by every member below).
class ManagedSubObject
{
  public:
    int unk00;
    ~ManagedSubObject();
};

extern "C" void __cdecl FormHeapFreeAndLog_00401030(void* p);

class FUN_007a8960_cls : public ManagedSubObject
{
  public:
    int unk04;
    void* m_08;
    ManagedSubObject m_0c;
    int unk10;
    ManagedSubObject m_14;
    int unk18;
    int unk1c;
    ManagedSubObject m_20;
    int unk24;
    int unk28;
    int unk2c;
    ManagedSubObject m_30;
    ~FUN_007a8960_cls();
};

// @fnv 0x007a8960
FUN_007a8960_cls::~FUN_007a8960_cls()
{
    void* p = m_08;
    FormHeapFreeAndLog_00401030(p);
    m_08 = 0;
}

// FUN_007abda0: returns constant 0x3f8
// @fnv 0x007abda0
// src: XBOX_PDB 0x007abda0
int __cdecl QuantityMenu_GetClassStatic()
{
    return 0x3f8;
}

template <class T>
NiPointer<T>::NiPointer(T* object)
{
    m_pObject = object;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T>
NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

struct RefObj7ac9f0
{
    void IncRefCount();
    void DecRefCount();
};

struct Base7ac9f0
{
    Base7ac9f0();
    virtual ~Base7ac9f0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
};

struct FUN_007ac9f0 : Base7ac9f0
{
    NiPointer<RefObj7ac9f0> pFirst[4];
    NiPointer<RefObj7ac9f0> pSecond[4];
    NiPointer<RefObj7ac9f0> spObj0;
    NiPointer<RefObj7ac9f0> spObj1;
    NiPointer<RefObj7ac9f0> spObj2;
    NiPointer<RefObj7ac9f0> spObj3;
    NiPointer<RefObj7ac9f0> spObj4;
    NiPointer<RefObj7ac9f0> spObj5;
    NiPoint3 kPos0;
    NiPoint3 kPos1;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    NiPoint3 kPos2;
    FUN_007ac9f0();
    virtual ~FUN_007ac9f0();
};

// @fnv 0x007ac9f0
FUN_007ac9f0::FUN_007ac9f0() : spObj0(0), spObj1(0), spObj2(0), spObj3(0), spObj4(0), spObj5(0)
{}

extern "C" const double DAT_01012060;
struct ActiveEffectEntry
{
    float FUN_00a011b0(unsigned int id);
    void Tile_Set(unsigned int id, float value, bool update);
};
struct ActiveEffectCollection
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    float rate;
    int Modelloader_GetReferencedThis();
    ActiveEffectEntry*** NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(int* iterator);
    void RaceSexMenu_MenuOptionList_ScrollBy(int amount);
};
// @fnv 0x007b4530
// src: XBOX_PDB 0x007b4530
void ActiveEffectCollection::RaceSexMenu_MenuOptionList_ScrollBy(int amount)
{
    if (rate <= DAT_01012060)
        return;
    int it = Modelloader_GetReferencedThis();
    while (it)
    {
        ActiveEffectEntry* pEffect = **NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(&it);
        float fAmount = pEffect->FUN_00a011b0(4002);
        fAmount = (float)amount * rate + fAmount;
        pEffect->Tile_Set(4002, fAmount, true);
    }
}

struct FUN_007b52d0_cls
{
    int* DereferenceIfNotNull(int** pParam);
};

// Returns the pointer stored at pParam when pParam is non-null, otherwise returns null.
// @fnv 0x007b52d0
int* FUN_007b52d0_cls::DereferenceIfNotNull(int** pParam)
{
    return pParam != 0 ? *pParam : (int*)0;
}

struct FUN_0049fa80_Result
{
    int unk00;
    int unk04;
    int unk08;
};

struct FUN_007b5330_Class
{
    FUN_0049fa80_Result* __thiscall NiTPointerListBase_NiTPointerAllocator_unsigned_int_unsigned_int_NewItem();
    void __thiscall InsertBefore(int arg1, FUN_0049fa80_Result* arg2);
    void __thiscall NiTPointerListBase_InsertBefore_0(int arg1, int* arg2);
};

// Gets a result object, stores the int pointed to by arg2 into its unk08 field, then passes it with arg1 to InsertBefore.
// @fnv 0x007b5330
// src: COMMUNITY 0x007b5330
void __thiscall FUN_007b5330_Class::NiTPointerListBase_InsertBefore_0(int arg1, int* arg2)
{
    FUN_0049fa80_Result* result = this->NiTPointerListBase_NiTPointerAllocator_unsigned_int_unsigned_int_NewItem();
    result->unk08 = *arg2;
    this->InsertBefore(arg1, result);
}

struct Target
{
    void FUN_00700320(int id, int idx);
};
struct Item
{
    Target* m_pFlagTarget;
    int u4;
    bool m_bSkip;
};
// @fnv 0x007a7260
// src: GUESS 0x007a7260 (confidence: low)
void Menu::ProcessEntries_007a7260()
{
    // Preserve the original word/float accesses at 0x1c/0x20 and list head at 0x04.
    *reinterpret_cast<unsigned short*>(&m_bIsSpecial) = 0;
    *reinterpret_cast<float*>(&m_iMenuId) = 0.0f;
    for (SL* it = this ? reinterpret_cast<SL*>(&pMenu) : 0; it && it->FUN_006815c0(); it = it->FUN_00726070())
    {
        if (!it->FUN_006815c0()->m_bSkip)
        {
            it->FUN_006815c0()->m_pFlagTarget->FUN_00700320(0xfac, (*reinterpret_cast<unsigned short*>(&m_bIsSpecial))++);
            AccumulateTileHeight(it->FUN_006815c0()->m_pFlagTarget);
        }
    }
    UpdateScrollTraits_007a7700();
    UpdateHighlightTraits_007a73e0();
}
