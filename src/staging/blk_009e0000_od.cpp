
// src/staging/blk_009e0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/ActorPackageData.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiTMallocInterface.h"
#include "../../include/PathingLocation.h"
#include "../../include/PathingRequest.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESPackage.h"

extern "C" void* DAT_010939ec;

struct FUN_009f91b0 : TESPackage
{
    FUN_009f91b0();
};

// @fnv 0x009f91b0
FUN_009f91b0::FUN_009f91b0()
{
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x80) = 0.0f;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x84) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x88) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x8c) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x90) = -1;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x94) = 3;
}

struct FUN_009e9c10
{
    void SetVtableAndProcessState_009e9c30();
    void Call();
};

// @fnv 0x009e9c10
void FUN_009e9c10::Call()
{
    SetVtableAndProcessState_009e9c30();
}

extern "C" void* DAT_010939ec;

struct FUN_009f2970_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void GuardActorPackageData_SetTarget(void* arg);
};
// @fnv 0x009f2970
// src: COMMUNITY 0x009f2970
void FUN_009f2970_Class::GuardActorPackageData_SetTarget(void* arg)
{
    m_8 = arg;
    ((TESObjectREFR*)m_8)->TESObjectREFR_SetTargeted(true);
}

extern "C" void* DAT_01093614;
struct FUN_009f61b0
{
    void* vtbl;
    void ResetAndWrite(int, int);
    FUN_009f61b0();
};
// Sets the vtable pointer to DAT_01093614 and calls ResetAndWrite with 0, 0.
// @fnv 0x009f61b0
FUN_009f61b0::FUN_009f61b0()
{
    vtbl = &DAT_01093614;
    ResetAndWrite(0, 0);
}

extern "C" void* DAT_01093614;
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_009f61e0 : GlobalObject_00869f00
{
    void Init();
};
// @fnv 0x009f61e0
void FUN_009f61e0::Init()
{
    *(void**)this = &DAT_01093614;
    Clear(true);
}

extern "C" void* Deallocate(void*);

struct FUN_009e9a20_Class
{
    void FUN_009e9980();
    void* FUN_009e9a20(unsigned int flags);
};

// Calls FUN_009e9980, then frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x009e9a20
void* FUN_009e9a20_Class::FUN_009e9a20(unsigned int flags)
{
    FUN_009e9980();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_009f9180_Class
{
    void FUN_009f6c90();
    void* FUN_009f9180(unsigned int flags);
};
// Calls FUN_009f6c90, then deletes this when flags has bit 1 set, and returns this.
// @fnv 0x009f9180
void* FUN_009f9180_Class::FUN_009f9180(unsigned int flags)
{
    FUN_009f6c90();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_009e9b20_Class
{
    virtual void v0();
    virtual int Write(unsigned int size);
    void ConstructElements(int size, unsigned int saved);
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void InitBuffer(unsigned int requested, unsigned int savedSize);
};

// @fnv 0x009e9b20
void FUN_009e9b20_Class::InitBuffer(unsigned int requested, unsigned int savedSize)
{
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
    if (savedSize > requested)
        requested = savedSize;
    if (requested > 0)
    {
        m_iWordAt04 = Write(requested);
        m_iThirdValue = requested;
    }
    if (savedSize > 0)
    {
        ConstructElements(m_iWordAt04, savedSize);
        m_8 = savedSize;
    }
}

struct BSSimpleArray_TESObjectREFR_1024
{
    BSSimpleArray_TESObjectREFR_1024();
    ~BSSimpleArray_TESObjectREFR_1024();
    void* pBase;
    void* pEnd;
    unsigned int ItemUpdateArray;
    unsigned int uiCapacity;
    unsigned int uiGrowSize;
    TESObjectREFR* m_pBuffer;
};
struct FUN_009f29a0 : ActorPackageData
{
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    BSSimpleArray_TESObjectREFR_1024 refs;
    FUN_009f29a0();
    virtual ~FUN_009f29a0();
};
// Initializes the package data fields to null.
// @fnv 0x009f29a0
FUN_009f29a0::FUN_009f29a0()
{
    m_iWordAt04 = 0;
    m_10 = 0;
    m_14 = 0;
    m_18 = 0;
}

void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int len);

struct FUN_009f8fa0_Class
{
    void CopyElements(char* dst, char* src, unsigned int count);
};

// Copies count elements of 0x34 bytes from src to dst, iterating forward when dst < src and backward otherwise to handle overlap.
// @fnv 0x009f8fa0
void FUN_009f8fa0_Class::CopyElements(char* apDest, char* apSource, unsigned int count)
{
    if (count <= 0)
        return;
    if (apDest < apSource)
    {
        for (unsigned int i = 0; i < count; ++i)
            FUN_00ec7230(apDest + i * 0x34, apSource + i * 0x34, 0x34);
    }
    else if (apDest > apSource)
    {
        for (int i = (int)count - 1; i >= 0; --i)
            FUN_00ec7230(apDest + i * 0x34, apSource + i * 0x34, 0x34);
    }
}

struct FUN_009f90f0_Class
{
    unsigned int m_iWordAt04;
    unsigned int m_8;
    unsigned int m_iThirdValue;
    virtual ~FUN_009f90f0_Class();
    virtual unsigned int Write(unsigned int);
    void ProcessEntries_009f8de0(unsigned int, unsigned int);
    void BSSimpleArray_SpectatorThreatInfo_1024_Initialize(unsigned int requested, unsigned int savedSize);
};

// @fnv 0x009f90f0
// src: COMMUNITY 0x009f90f0
void FUN_009f90f0_Class::BSSimpleArray_SpectatorThreatInfo_1024_Initialize(unsigned int uiRequestedSize, unsigned int savedSize)
{
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
    if (savedSize > uiRequestedSize)
    {
        uiRequestedSize = savedSize;
    }
    if (uiRequestedSize > 0)
    {
        m_iWordAt04 = Write(uiRequestedSize);
        m_iThirdValue = uiRequestedSize;
    }
    if (savedSize > 0)
    {
        ProcessEntries_009f8de0(m_iWordAt04, savedSize);
        m_8 = savedSize;
    }
}

struct Elem9f6340
{
    int v;
};
struct Host9f6340
{
    int iSize;
    int iPosition;
    int iDataLength;
    virtual void v0();
    virtual int Write(unsigned int);
    void BSSimpleArray_SandBoxChoiceListItem_1024_ConstructItems(int, int);
    void ResetAndWrite(unsigned int requested, unsigned int savedSize);
};

// @fnv 0x009f65f0
void Host9f6340::ResetAndWrite(unsigned int requested, unsigned int savedSize)
{
    iSize = 0;
    iPosition = 0;
    iDataLength = 0;
    if (savedSize > requested)
        requested = savedSize;
    if (requested > 0)
    {
        iSize = Write(requested);
        iDataLength = requested;
    }
    if (savedSize > 0)
    {
        BSSimpleArray_SandBoxChoiceListItem_1024_ConstructItems(iSize, savedSize);
        iPosition = savedSize;
    }
}

struct FUN_009e99f0_Class
{
    void* m_iWordAt00;
    float m_iWordAt04;
    void* AssignFromSource(const void* src);
};
// Copies a pointer and a float from src into the object's fields and returns this.
// @fnv 0x009e99f0
void* FUN_009e99f0_Class::AssignFromSource(const void* apSource)
{
    m_iWordAt00 = *(void**)apSource;
    m_iWordAt04 = *(float*)((char*)apSource + 4);
    return this;
}

extern float DAT_01015f5c;
struct FUN_009e9af0_Class
{
    int m_iWordAt00;
    float m_iWordAt04;
    FUN_009e9af0_Class();
};
// Initializes the object's integer field to 0 and its float field to DAT_01015f5c.
// @fnv 0x009e9af0
FUN_009e9af0_Class::FUN_009e9af0_Class()
{
    m_iWordAt00 = 0;
    m_iWordAt04 = DAT_01015f5c;
}

extern int DAT_01092928;
struct FUN_009e9c90
{
    FUN_009e9c90(int a, int b);
};
struct FUN_009e9bb0 : FUN_009e9c90
{
    int* vtbl;
    FUN_009e9bb0(int a, int b);
};
// Calls the base constructor with a and b, then sets vtbl to point at DAT_01092928.
// @fnv 0x009e9bb0
FUN_009e9bb0::FUN_009e9bb0(int a, int b) : FUN_009e9c90(a, b)
{
    vtbl = &DAT_01092928;
}

extern "C" void* Deallocate(void*);

struct GlobalObject_009e9bb0
{
    virtual void v0();
    void Call();
    void* ReleaseIfFlagged(unsigned int flags);
};

// Calls Call(), then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x009e9be0
void* GlobalObject_009e9bb0::ReleaseIfFlagged(unsigned int flags)
{
    Call();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern int DAT_01092930;

// @fnv 0x009e9c30
// src: GUESS 0x009e9c30 (confidence: low)
void FUN_009e9c10::SetVtableAndProcessState_009e9c30()
{
    *(void**)this = &DAT_01092930;
    NiTMallocInterface<Actor*>::Deallocate(*(Actor***)((char*)this + 4));
}

void __cdecl _Deallocate(void*);

struct FUN_009e9c60_Class : FUN_009e9c10
{
    void* FUN_009e9c60(unsigned int flags);
};

// Calls FUN_009e9c30, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x009e9c60
void* FUN_009e9c60_Class::FUN_009e9c60(unsigned int flags)
{
    SetVtableAndProcessState_009e9c30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_01092930;

struct FUN_009e9c90_Class
{
    void* vtbl;
    void* m_iWordAt04;
    unsigned short m_8;
    unsigned short m_kPointA;
    unsigned short m_iThirdValue;
    unsigned short m_usTrailingValue;
    FUN_009e9c90_Class(unsigned short a, unsigned short b);
};

// @fnv 0x009e9c90
FUN_009e9c90_Class::FUN_009e9c90_Class(unsigned short a, unsigned short b)
{
    vtbl = &DAT_01092930;
    m_8 = a;
    m_usTrailingValue = b;
    m_kPointA = 0;
    m_iThirdValue = 0;
    if (m_8 > 0)
        m_iWordAt04 = NiTMallocInterface<Actor*>::Allocate(m_8);
    else
        m_iWordAt04 = 0;
}

extern int DAT_01092d84;
struct FUN_009ed330 : TESPackage
{
    ~FUN_009ed330();
};
// @fnv 0x009ed330
FUN_009ed330::~FUN_009ed330()
{}

struct FUN_009e99a0_Entry
{
    unsigned int m_uiKey;
    unsigned int m_uiCurrentValue;
    void SetValue(unsigned int value);
};

class FUN_009e99a0_cls
{
  public:
    unsigned int m_uiUnk00;
    FUN_009e99a0_Entry* m_pEntries;
    unsigned int m_uiUnk08;
    unsigned int m_uiUnk0C;

    int GetCount();
    void RegisterEntry(FUN_009e99a0_Entry* entry, int flag);
    int BSSimpleArray_DetailedActorPathHandler_ActorAvoidanceData_1024_Add(unsigned int value);
};

// @fnv 0x009e99a0
// src: COMMUNITY 0x009e99a0
int FUN_009e99a0_cls::BSSimpleArray_DetailedActorPathHandler_ActorAvoidanceData_1024_Add(unsigned int value)
{
    int iIndex = GetCount();
    RegisterEntry(m_pEntries + iIndex, 1);
    m_pEntries[iIndex].SetValue(value);
    return iIndex;
}

class FUN_009eb620_cls
{
  public:
    int ProcessLists_GetCrimeNumber();
};

// @fnv 0x009eb620
// src: XBOX_PDB 0x009eb620
int FUN_009eb620_cls::ProcessLists_GetCrimeNumber()
{
    return (*(int*)((char*)this + 0x103b8))++;
}

struct S_009eb8a0_Time
{
    int FUN_00867d20();
    char FUN_00867d60();
    int Calendar_GetYear();
};
struct S_009eb8a0_Setting
{
    int* Setting_Int();
};
extern S_009eb8a0_Time DAT_011de7b8;
extern S_009eb8a0_Setting DAT_011cd39c;
struct S_009eb8a0_Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    BSSimpleList<TESObjectREFR*> list;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    bool Crime_ShouldCrimeBeRemoved();
};
// @fnv 0x009eb8a0
// src: COMMUNITY 0x009eb8a0
bool S_009eb8a0_Cls::Crime_ShouldCrimeBeRemoved()
{
    int now4 = (DAT_011de7b8.FUN_00867d20() << 9) | DAT_011de7b8.FUN_00867d60() | (DAT_011de7b8.Calendar_GetYear() << 13);
    bool result5 = false;
    if (now4 - unk30 >= *DAT_011cd39c.Setting_Int())
    {
        result5 = true;
    }
    else if (unk00 < 1)
    {
        result5 = true;
    }
    else
    {
        BSSimpleList<TESObjectREFR*>* pList = &list;
        if (!pList || pList->IsEmpty())
        {
            result5 = true;
        }
        else
        {
            bool bAllValid = true;
            while (pList && pList->GetItem() && bAllValid)
            {
                TESObjectREFR* o = pList->GetItem();
                if (!o->HasHealth(false))
                    bAllValid = false;
                pList = pList->GetNext();
            }
            if (bAllValid)
                result5 = true;
        }
    }
    return result5;
}

// GetVector80: thiscall member, one stack out-pointer (ret 4).
// Copies the 12-byte value struct at this+0x80 into *pOut and returns pOut.

class FUN_009ed350_cls
{
  public:
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4C;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5C;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6C;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7C;
    NiPoint3 m_v80;
    NiPoint3* GetVector80(NiPoint3* pOut);
};

// Copies the vector at offset 0x80 into pOut and returns pOut.
// @fnv 0x009ed350
NiPoint3* FUN_009ed350_cls::GetVector80(NiPoint3* pOut)
{
    *pOut = m_v80;
    return pOut;
}

struct GlobalObject_0041a250
{
    GlobalObject_0041a250();
    int unk00;
    int unk04;
    int unk08;
};

struct FUN_009edbc0 : TESPackage
{
    GlobalObject_0041a250 unk80;
    int unk8c;
    float unk90;
    int unk94;
    bool unk98;
    int unk9c;
    bool unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    bool unkbc;
    bool unkbd;
    bool unkbe;
    bool unkbf;
    bool unkc0;
    bool unkc1;
    bool unkc2;
    int unkc4;
    int unkc8;
    bool unkcc;
    FUN_009edbc0();
    virtual ~FUN_009edbc0();
};

// @fnv 0x009edbc0
FUN_009edbc0::FUN_009edbc0()
{
    unka8 = 0;
    unkac = 0;
    unka4 = 0;
    unk90 = 0.0f;
    unk8c = 0;
    unk94 = 0;
    unkb0 = 0;
    unkb8 = 0;
    unk98 = false;
    unkbd = false;
    unkbe = false;
    unkbf = false;
    unkc0 = false;
    unkbc = true;
    unkc1 = false;
    unk9c = 0;
    unkb4 = 0;
    unkc4 = 0;
    unkc8 = 50;
    unka0 = false;
    unkb8 = 0;
    unkc2 = false;
    unkcc = true;
}


struct SpawnedMember
{
    SpawnedMember();
};

struct FUN_009f0900_cls : ActorPackageData
{
    int m_04;
    int m_08;
    int m_0c;
    int m_10;

    FUN_009f0900_cls();
};

// @fnv 0x009f0900
FUN_009f0900_cls::FUN_009f0900_cls()
{
    ((SpawnedMember*)&this->m_10)->SpawnedMember::SpawnedMember();
    this->m_04 = 0;
    this->m_08 = 0;
    this->m_0c = 0;
}


// The 0xEC-byte request matches the cover request size; its 0x006dad40 setter writes at +0xB0, beyond PathingRequest.
class CoverSearchRequest : public PathingRequest
{
  public:
    void SetDestination(const NiPoint3& kPos);

    unsigned char coverData[0x3C];
};

class PathResult9F6
{
  public:
    int unk00;
};

void __cdecl FindNearbyTriangles(CoverSearchRequest* pkRequest, PathResult9F6* pkResult);

class Pather9F6
{
  public:
    void BuildPathRequest(NiPoint3 kStart, NiPoint3 kEnd, TESObjectCELL* pkCell, TESWorldSpace* pkWorld);

    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    int unk0A0, unk0A4;
    CoverSearchRequest m_kRequest;
    PathResult9F6 m_kResult;
};

// Builds a pathing request from start/end points, cell and world, sets a 1000.0 center radius, and runs it into m_kResult.
// @fnv 0x009f6830
void Pather9F6::BuildPathRequest(NiPoint3 kStart, NiPoint3 kEnd, TESObjectCELL* pkCell,
                                 TESWorldSpace* pkWorld)
{
    m_kRequest.SetOrigin(&PathingLocation(kStart, pkCell, pkWorld));
    m_kRequest.SetDestination(kEnd);
    m_kRequest.SetCenterRadius(1000.0f);
    FindNearbyTriangles(&m_kRequest, &m_kResult);
}

struct GameReference
{
    virtual void unknownVirtual_0();
    virtual void unknownVirtual_1();
    virtual void unknownVirtual_2();
    virtual void unknownVirtual_3();
    virtual void unknownVirtual_4();
    virtual void unknownVirtual_5();
    virtual void unknownVirtual_6();
    virtual void unknownVirtual_7();
    virtual void unknownVirtual_8();
    virtual void unknownVirtual_9();
    virtual void unknownVirtual_a();
    virtual void unknownVirtual_b();
    virtual void unknownVirtual_c();
    virtual void unknownVirtual_d();
    virtual void unknownVirtual_e();
    virtual void unknownVirtual_f();
    virtual void unknownVirtual_10();
    virtual void unknownVirtual_11();
    virtual void unknownVirtual_12();
    virtual void unknownVirtual_13();
    virtual void unknownVirtual_14();
    virtual void unknownVirtual_15();
    virtual void unknownVirtual_16();
    virtual void unknownVirtual_17();
    virtual void unknownVirtual_18();
    virtual void unknownVirtual_19();
    virtual void unknownVirtual_1a();
    virtual void unknownVirtual_1b();
    virtual void unknownVirtual_1c();
    virtual void unknownVirtual_1d();
    virtual void unknownVirtual_1e();
    virtual void unknownVirtual_1f();
    virtual void unknownVirtual_20();
    virtual void unknownVirtual_21();
    virtual void unknownVirtual_22();
    virtual void unknownVirtual_23();
    virtual void unknownVirtual_24();
    virtual void unknownVirtual_25();
    virtual void unknownVirtual_26();
    virtual void unknownVirtual_27();
    virtual void unknownVirtual_28();
    virtual void unknownVirtual_29();
    virtual void unknownVirtual_2a();
    virtual void unknownVirtual_2b();
    virtual void unknownVirtual_2c();
    virtual void unknownVirtual_2d();
    virtual void unknownVirtual_2e();
    virtual void unknownVirtual_2f();
    virtual void unknownVirtual_30();
    virtual void unknownVirtual_31();
    virtual void unknownVirtual_32();
    virtual void unknownVirtual_33();
    virtual void unknownVirtual_34();
    virtual void unknownVirtual_35();
    virtual void unknownVirtual_36();
    virtual void unknownVirtual_37();
    virtual void unknownVirtual_38();
    virtual void unknownVirtual_39();
    virtual void unknownVirtual_3a();
    virtual void unknownVirtual_3b();
    virtual void unknownVirtual_3c();
    virtual void unknownVirtual_3d();
    virtual void unknownVirtual_3e();
    virtual void unknownVirtual_3f();
    virtual void unknownVirtual_40();
    virtual void unknownVirtual_41();
    virtual void unknownVirtual_42();
    virtual void unknownVirtual_43();
    virtual void unknownVirtual_44();
    virtual void unknownVirtual_45();
    virtual void unknownVirtual_46();
    virtual void unknownVirtual_47();
    virtual void unknownVirtual_48();
    virtual void unknownVirtual_49();
    virtual void unknownVirtual_4a();
    virtual void unknownVirtual_4b();
    virtual void unknownVirtual_4c();
    virtual void unknownVirtual_4d();
    virtual void unknownVirtual_4e();
    virtual void unknownVirtual_4f();
    virtual void unknownVirtual_50();
    virtual void unknownVirtual_51();
    virtual void unknownVirtual_52();
    virtual void unknownVirtual_53();
    virtual void unknownVirtual_54();
    virtual void unknownVirtual_55();
    virtual void unknownVirtual_56();
    virtual void unknownVirtual_57();
    virtual void unknownVirtual_58();
    virtual void unknownVirtual_59();
    virtual void unknownVirtual_5a();
    virtual void unknownVirtual_5b();
    virtual void unknownVirtual_5c();
    virtual void unknownVirtual_5d();
    virtual void unknownVirtual_5e();
    virtual void unknownVirtual_5f();
    virtual void unknownVirtual_60();
    virtual void unknownVirtual_61();
    virtual void unknownVirtual_62();
    virtual void unknownVirtual_63();
    virtual void unknownVirtual_64();
    virtual void unknownVirtual_65();
    virtual void unknownVirtual_66();
    virtual void unknownVirtual_67();
    virtual void unknownVirtual_68();
    virtual void unknownVirtual_69();
    virtual void unknownVirtual_6a();
    virtual void unknownVirtual_6b();
    virtual void unknownVirtual_6c();
    virtual void unknownVirtual_6d();
    virtual void unknownVirtual_6e();
    virtual void unknownVirtual_6f();
    virtual void unknownVirtual_70();
    virtual void unknownVirtual_71();
    virtual void unknownVirtual_72();
    virtual void unknownVirtual_73();
    virtual void unknownVirtual_74();
    virtual void unknownVirtual_75();
    virtual void unknownVirtual_76();
    virtual void unknownVirtual_77();
    virtual void unknownVirtual_78();
    virtual void unknownVirtual_79();
    virtual void unknownVirtual_7a();
    virtual void unknownVirtual_7b();
    virtual void unknownVirtual_7c();
    virtual void unknownVirtual_7d();
    virtual void unknownVirtual_7e();
    virtual void unknownVirtual_7f();
    virtual void unknownVirtual_80();
    virtual void unknownVirtual_81();
    virtual void unknownVirtual_82();
    virtual void unknownVirtual_83();
    virtual void unknownVirtual_84();
    virtual void unknownVirtual_85();
    virtual void unknownVirtual_86();
    virtual void unknownVirtual_87();
    virtual void unknownVirtual_88();
    virtual void unknownVirtual_89();
    virtual void unknownVirtual_8a();
    virtual void unknownVirtual_8b();
    virtual void unknownVirtual_8c();
    virtual void unknownVirtual_8d();
    virtual void unknownVirtual_8e();
    virtual void unknownVirtual_8f();
    virtual void unknownVirtual_90();
    virtual void unknownVirtual_91();
    virtual void unknownVirtual_92();
    virtual void unknownVirtual_93();
    virtual void unknownVirtual_94();
    virtual void unknownVirtual_95();
    virtual void unknownVirtual_96();
    virtual void unknownVirtual_97();
    virtual void unknownVirtual_98();
    virtual void unknownVirtual_99();
    virtual void unknownVirtual_9a();
    virtual void unknownVirtual_9b();
    virtual void unknownVirtual_9c();
    virtual void unknownVirtual_9d();
    virtual void unknownVirtual_9e();
    virtual void unknownVirtual_9f();
    virtual void unknownVirtual_a0();
    virtual void unknownVirtual_a1();
    virtual void unknownVirtual_a2();
    virtual void unknownVirtual_a3();
    virtual void unknownVirtual_a4();
    virtual void unknownVirtual_a5();
    virtual void unknownVirtual_a6();
    virtual void unknownVirtual_a7();
    virtual void unknownVirtual_a8();
    virtual void unknownVirtual_a9();
    virtual void unknownVirtual_aa();
    virtual void unknownVirtual_ab();
    virtual void unknownVirtual_ac();
    virtual void unknownVirtual_ad();
    virtual void unknownVirtual_ae();
    virtual void unknownVirtual_af();
    virtual void unknownVirtual_b0();
    virtual void unknownVirtual_b1();
    virtual void unknownVirtual_b2();
    virtual void unknownVirtual_b3();
    virtual void unknownVirtual_b4();
    virtual void unknownVirtual_b5();
    virtual void unknownVirtual_b6();
    virtual void unknownVirtual_b7();
    virtual void unknownVirtual_b8();
    virtual void unknownVirtual_b9();
    virtual void unknownVirtual_ba();
    virtual void unknownVirtual_bb();
    virtual void unknownVirtual_bc();
    virtual void unknownVirtual_bd();
    virtual void unknownVirtual_be();
    virtual void unknownVirtual_bf();
    virtual void unknownVirtual_c0();
    virtual void unknownVirtual_c1();
    virtual void unknownVirtual_c2();
    virtual void unknownVirtual_c3();
    virtual void unknownVirtual_c4();
    virtual void unknownVirtual_c5();
    virtual void unknownVirtual_c6();
    virtual void unknownVirtual_c7();
    virtual void unknownVirtual_c8();
    virtual void unknownVirtual_c9();
    virtual void unknownVirtual_ca();
    virtual void unknownVirtual_cb();
    virtual void unknownVirtual_cc();
    virtual void unknownVirtual_cd();
    virtual void unknownVirtual_ce();
    virtual void unknownVirtual_cf();
    virtual void unknownVirtual_d0();
    virtual void unknownVirtual_d1();
    virtual void unknownVirtual_d2();
    virtual void unknownVirtual_d3();
    virtual void unknownVirtual_d4();
    virtual void unknownVirtual_d5();
    virtual void unknownVirtual_d6();
    virtual void unknownVirtual_d7();
    virtual void unknownVirtual_d8();
    virtual void unknownVirtual_d9();
    virtual void unknownVirtual_da();
    virtual void unknownVirtual_db();
    virtual void unknownVirtual_dc();
    virtual void unknownVirtual_dd();
    virtual void unknownVirtual_de();
    virtual void unknownVirtual_df();
    virtual void unknownVirtual_e0();
    virtual void unknownVirtual_e1();
    virtual void unknownVirtual_e2();
    virtual void unknownVirtual_e3();
    virtual void unknownVirtual_e4();
    virtual void unknownVirtual_e5();
    virtual void unknownVirtual_e6();
    virtual void unknownVirtual_e7();
    virtual void unknownVirtual_e8();
    virtual void unknownVirtual_e9();
    virtual void unknownVirtual_ea();
    virtual void unknownVirtual_eb();
    virtual void unknownVirtual_ec();
    virtual void unknownVirtual_ed();
    virtual void unknownVirtual_ee();
    virtual void unknownVirtual_ef();
    virtual void unknownVirtual_f0();
    virtual void unknownVirtual_f1();
    virtual void unknownVirtual_f2();
    virtual void unknownVirtual_f3();
    virtual void unknownVirtual_f4();
    virtual void unknownVirtual_f5();
    virtual void unknownVirtual_f6();
    virtual void unknownVirtual_f7();
    virtual void unknownVirtual_f8();
    virtual void unknownVirtual_f9();
    virtual void unknownVirtual_fa();
    virtual void unknownVirtual_fb();
    virtual void unknownVirtual_fc();
    virtual void unknownVirtual_fd();
    virtual void unknownVirtual_fe();
    virtual void unknownVirtual_ff();
    virtual void unknownVirtual_100();
    virtual void unknownVirtual_101();
    virtual void unknownVirtual_102();
    virtual void unknownVirtual_103();
    virtual void unknownVirtual_104();
    virtual void unknownVirtual_105();
    virtual void unknownVirtual_106();
    virtual void unknownVirtual_107();
    virtual void unknownVirtual_108();
    virtual void unknownVirtual_109();
    virtual void unknownVirtual_10a();
    virtual GameReference* GetLinkedReference();
    void TESObjectREFR_SetTargeted(bool enabled);
};
struct ReferenceLinkController
{
    GameReference* source;
    GameReference* linked;
    unsigned int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
    bool enabled;
    bool hasLinkedReference;
    void SpectatorThreatInfo_Update();
    void SetSourceReference(GameReference* reference);
};
// @fnv 0x009f6c20
void ReferenceLinkController::SetSourceReference(GameReference* apSource)
{
    source = apSource;
    linked = apSource->GetLinkedReference();
    enabled = true;
    hasLinkedReference = linked != 0;
    source->TESObjectREFR_SetTargeted(true);
    if (linked)
        linked->TESObjectREFR_SetTargeted(true);
    SpectatorThreatInfo_Update();
}

struct FUN_0045cec0
{
    void* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(int release);
    ~FUN_0045cec0();
};
struct Reference
{
    virtual void slot_000();
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void slot_010();
    virtual void slot_014();
    virtual void slot_018();
    virtual void slot_01c();
    virtual void slot_020();
    virtual void slot_024();
    virtual void slot_028();
    virtual void slot_02c();
    virtual void slot_030();
    virtual void slot_034();
    virtual void slot_038();
    virtual void slot_03c();
    virtual void slot_040();
    virtual void slot_044();
    virtual void slot_048();
    virtual void slot_04c();
    virtual void slot_050();
    virtual void slot_054();
    virtual void slot_058();
    virtual void slot_05c();
    virtual void slot_060();
    virtual void slot_064();
    virtual void slot_068();
    virtual void slot_06c();
    virtual void slot_070();
    virtual void slot_074();
    virtual void slot_078();
    virtual void slot_07c();
    virtual void slot_080();
    virtual void slot_084();
    virtual void slot_088();
    virtual void slot_08c();
    virtual void slot_090();
    virtual void slot_094();
    virtual void slot_098();
    virtual void slot_09c();
    virtual void slot_0a0();
    virtual void slot_0a4();
    virtual void slot_0a8();
    virtual void slot_0ac();
    virtual void slot_0b0();
    virtual void slot_0b4();
    virtual void slot_0b8();
    virtual void slot_0bc();
    virtual void slot_0c0();
    virtual void slot_0c4();
    virtual void slot_0c8();
    virtual void slot_0cc();
    virtual void slot_0d0();
    virtual void slot_0d4();
    virtual void slot_0d8();
    virtual void slot_0dc();
    virtual void slot_0e0();
    virtual void slot_0e4();
    virtual void NotifyOwner(void* owner);
    Reference* NiAVObject_GetParent();
};
struct FUN_009f6c90
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    FUN_0045cec0 ref;
    ~FUN_009f6c90();
};
// If ref holds an object, notifies that object's owner with ref and then releases ref with argument 0.
// @fnv 0x009f6c90
FUN_009f6c90::~FUN_009f6c90()
{
    if (ref.Modelloader_GetReferencedThis())
    {
        if (((Reference*)ref.Modelloader_GetReferencedThis())->NiAVObject_GetParent())
        {
            ((Reference*)ref.Modelloader_GetReferencedThis())->NiAVObject_GetParent()->NotifyOwner(ref.Modelloader_GetReferencedThis());
        }
        ref.FUN_0066b0d0(0);
    }
}

class FUN_009f9040_cls
{
  public:
    virtual void v0();
    virtual void* v1(int a);
    virtual void v2();
    virtual void* v3(void* cur, int a);
    void* m_iWordAt04;
    void* m_8;
    unsigned int m_iThirdValue;
    void CopyBlock(void* dst, void* src, unsigned int count);
    void Reset();
    void EnsureBuffer(int a1, unsigned int a2);
};

// @fnv 0x009f9040
void FUN_009f9040_cls::EnsureBuffer(int aiSize, unsigned int auiCount)
{
    if (m_iWordAt04 != 0)
    {
        if (auiCount == m_iThirdValue)
        {
            m_iWordAt04 = v3(m_iWordAt04, aiSize);
        }
        else
        {
            void* pNewBuffer = v1(aiSize);
            CopyBlock(pNewBuffer, m_iWordAt04, auiCount);
            Reset();
            m_iWordAt04 = pNewBuffer;
        }
    }
    else
    {
        m_iWordAt04 = v1(aiSize);
        m_iThirdValue = aiSize;
    }
}

struct FUN_009eb660;
struct ItemCls;
struct MidCls;
struct DestCls
{
    void RemoveMatchingItem(FUN_009eb660* const&);
};
struct MidCls
{
    DestCls* ExtraDataList_GetPlayerCrimeList();
};
struct SrcCls
{
    virtual void unknownVirtual_0();
    virtual void unknownVirtual_1();
    virtual void unknownVirtual_2();
    virtual void unknownVirtual_3();
    virtual void unknownVirtual_4();
    virtual void unknownVirtual_5();
    virtual void unknownVirtual_6();
    virtual void unknownVirtual_7();
    virtual void unknownVirtual_8();
    virtual void unknownVirtual_9();
    virtual void unknownVirtual_10();
    virtual void unknownVirtual_11();
    virtual void unknownVirtual_12();
    virtual void unknownVirtual_13();
    virtual void unknownVirtual_14();
    virtual void unknownVirtual_15();
    virtual void unknownVirtual_16();
    virtual void unknownVirtual_17();
    virtual void unknownVirtual_18();
    virtual void unknownVirtual_19();
    virtual void unknownVirtual_20();
    virtual void unknownVirtual_21();
    virtual void unknownVirtual_22();
    virtual void unknownVirtual_23();
    virtual void unknownVirtual_24();
    virtual void unknownVirtual_25();
    virtual void unknownVirtual_26();
    virtual void unknownVirtual_27();
    virtual void unknownVirtual_28();
    virtual void unknownVirtual_29();
    virtual void unknownVirtual_30();
    virtual void unknownVirtual_31();
    virtual void unknownVirtual_32();
    virtual void unknownVirtual_33();
    virtual void unknownVirtual_34();
    virtual void unknownVirtual_35();
    virtual void unknownVirtual_36();
    virtual void unknownVirtual_37();
    virtual void unknownVirtual_38();
    virtual void unknownVirtual_39();
    virtual void unknownVirtual_40();
    virtual void unknownVirtual_41();
    virtual void unknownVirtual_42();
    virtual void unknownVirtual_43();
    virtual void unknownVirtual_44();
    virtual void unknownVirtual_45();
    virtual void unknownVirtual_46();
    virtual void unknownVirtual_47();
    virtual void unknownVirtual_48();
    virtual void unknownVirtual_49();
    virtual void unknownVirtual_50();
    virtual void unknownVirtual_51();
    virtual void unknownVirtual_52();
    virtual void unknownVirtual_53();
    virtual void unknownVirtual_54();
    virtual void unknownVirtual_55();
    virtual void unknownVirtual_56();
    virtual void unknownVirtual_57();
    virtual void unknownVirtual_58();
    virtual void unknownVirtual_59();
    virtual void unknownVirtual_60();
    virtual void unknownVirtual_61();
    virtual void unknownVirtual_62();
    virtual void unknownVirtual_63();
    virtual bool VCall100();
    MidCls* BSFile_GetDevice();
};
struct ItemCls
{
    void ForwardCall_0047eb90(int);
    bool Actor_IsAlarmed();
    void Actor_EndInterruptPackage(int);
    MidCls* BSFile_GetDevice();
};
// Exe 0x009eb660: unit-local ListNode view; declarations and layout are preserved.
struct BlkListNodeView
{
    void* m_item;
    BlkListNodeView* m_next;
    bool FUN_008256d0();
    void** FUN_006815c0();
    BlkListNodeView* FUN_00726070();
    void FUN_00470470();
    void* FUN_004702f0(unsigned int);
    ~BlkListNodeView();
};
struct ListMember
{
    int lm00;
    int lm04;
    int lm08;
    int lm0c;
    int lm10;
    int lm14;
    int lm18;
    void FUN_00470470();
    ~ListMember();
};
struct DHCls
{
    bool TESDataHandler_GetClearingData();
};
struct GlobalCls
{
    void ProcessLists_RemoveCrimeGlobalCrimeList(FUN_009eb660*);
    bool IsActorInOtherList(ItemCls*, FUN_009eb660*);
    BlkListNodeView* FindDialogueSpeakers(FUN_009eb660*, int);
};
extern DHCls* DAT_011c3f2c;
extern GlobalCls DAT_011e0e80;

struct FUN_009eb660
{
    int f00;
    int f04;
    SrcCls* f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    ListMember m1c;
    BlkListNodeView* m38;
    void Crime_ClearActorKnowList();
    SrcCls* FUN_0044ddc0();
    ~FUN_009eb660();
};

// @fnv 0x009eb660
FUN_009eb660::~FUN_009eb660()
{
    if (DAT_011c3f2c != 0 && !DAT_011c3f2c->TESDataHandler_GetClearingData())
    {
        SrcCls* pACopy;
        BlkListNodeView* pA3;
        BlkListNodeView* pB6;
        ItemCls* node5;
        DestCls* itemB;
        SrcCls* destA8;
        DestCls* destB_;
        ItemCls* item6;
        Crime_ClearActorKnowList();
        DAT_011e0e80.ProcessLists_RemoveCrimeGlobalCrimeList(this);
        if (f08 != 0)
        {
            if (f08->BSFile_GetDevice()->ExtraDataList_GetPlayerCrimeList() != 0)
                f08->BSFile_GetDevice()->ExtraDataList_GetPlayerCrimeList()->RemoveMatchingItem(this);
        }
        pB6 = m38;
        while (pB6 != 0 && !pB6->FUN_008256d0())
        {
            node5 = (ItemCls*)*pB6->FUN_006815c0();
            if (!DAT_011e0e80.IsActorInOtherList(node5, this))
                node5->ForwardCall_0047eb90(0);
            pB6 = pB6->FUN_00726070();
        }
        pACopy = FUN_0044ddc0();
        if (pACopy != 0)
        {
            if (pACopy->VCall100())
            {
                destA8 = pACopy;
                itemB = destA8->BSFile_GetDevice()->ExtraDataList_GetPlayerCrimeList();
                if (itemB != 0)
                    itemB->RemoveMatchingItem(this);
            }
        }
        pA3 = DAT_011e0e80.FindDialogueSpeakers(this, 1);
        while (pA3 != 0)
        {
            item6 = (ItemCls*)*pA3->FUN_006815c0();
            if (item6->Actor_IsAlarmed())
                item6->Actor_EndInterruptPackage(0);
            destB_ = item6->BSFile_GetDevice()->ExtraDataList_GetPlayerCrimeList();
            if (destB_ != 0)
                destB_->RemoveMatchingItem(this);
        }
    }
    if (m38 != 0)
    {
        m38->FUN_00470470();
        delete m38;
    }
    m1c.FUN_00470470();
}

void Pathing_FindPointOnNavMesh(void*, void*, NiPoint3*, float, NiPoint3*);
// @fnv 0x009ed380
// src: COMMUNITY 0x009ed380
NiPoint3 BackUpPackage_CalculateBackUpPointInterior(TESObjectREFR* source, TESObjectREFR* target)
{
    NiPoint3 result = NiPoint3::ZERO;
    if (target && source)
    {
        NiPoint3 cell = *static_cast<const TESObjectREFR*>(target)->GetPos();
        NiPoint3 distance = *static_cast<const TESObjectREFR*>(source)->GetPos();
        float targetPos = 300.0f;
        NiPoint3 sourcePos = distance - cell;
        sourcePos.Unitize_004a0c10();
        sourcePos = distance + sourcePos * targetPos;
        result = sourcePos;
        void* direction = source->GetParentCellStub();
        Pathing_FindPointOnNavMesh(source->TESObjectREFR_GetWorldSpace(), direction, &sourcePos, 200.0f, &result);
    }
    return result;
}

namespace fnv_009ed4b0 {


void __cdecl Pathing_FindPointOnNavMesh(TESWorldSpace* ws, ParentCellStub* cell, NiPoint3* pos, float radius, NiPoint3* out);

// @fnv 0x009ed4b0
NiPoint3 __cdecl ComputeAdjustedTargetPosition(TESObjectREFR* target, TESObjectREFR* source)
{
    NiPoint3 result5 = NiPoint3::ZERO;
    if (source && target)
    {
        NiPoint3 sourcePos = *static_cast<const TESObjectREFR*>(source)->GetPos();
        NiPoint3 targetPosX = *static_cast<const TESObjectREFR*>(target)->GetPos();
        float distance2 = 300.0f;
        NiPoint3 _dir = targetPosX - sourcePos;
        _dir.Unitize();
        _dir = targetPosX + _dir * distance2;
        result5 = _dir;
        ParentCellStub* cellB = target->GetParentCellStub();
        Pathing_FindPointOnNavMesh(target->TESObjectREFR_GetWorldSpace(), cellB, &_dir, 200.0f, &result5);
        if (result5.HasEqualComponents(_dir))
        {
        }
    }
    return result5;
}
}  // namespace fnv_009ed4b0

namespace fnv_009f6900 {
struct Waypoint
{
    Waypoint(const Waypoint&);
    ~Waypoint();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;

    NiPoint3 FUN_005c3420();
};
struct Route
{
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
    unsigned FUN_0044ddc0();
    Waypoint& FUN_009a3280(unsigned);
};
NiPoint3 __cdecl RandomOffsetVectorFromOrigin(NiPoint3, float, float, int);
void __cdecl Pathing_FindPointOnNavMesh(void*, void*, const NiPoint3*, float, NiPoint3*);
struct Pather
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    unsigned index;
    int unk090;
    NiPoint3 destination;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    Route route;
    void BuildPathRequest(NiPoint3, NiPoint3, void*, void*);
    NiPoint3 GetPathPoint(TESObjectREFR*);
};
// Returns a path point for ref: initialises destination when zero, advances the route waypoint index, or computes a point near destination.
// @fnv 0x009f6900
NiPoint3 Pather::GetPathPoint(TESObjectREFR* ref)
{
    NiPoint3 result = destination;
    if (destination.HasEqualComponents(NiPoint3::ZERO))
    {
        destination = RandomOffsetVectorFromOrigin(*static_cast<const TESObjectREFR*>(ref)->GetPos(), 800.0f, 1000.0f, 0);
        Pathing_FindPointOnNavMesh(ref->TESObjectREFR_GetWorldSpace(), ref->GetParentCellStub(), static_cast<const TESObjectREFR*>(ref)->GetPos(), 300.0f, &destination);
        return destination;
    }
    if (route.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
        BuildPathRequest(*static_cast<const TESObjectREFR*>(ref)->GetPos(), destination, ref->GetParentCellStub(), ref->TESObjectREFR_GetWorldSpace());
    if (!route.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty() && index < route.FUN_0044ddc0())
    {
        Waypoint waypoint(route.FUN_009a3280(index));
        index = index + 1;
        result = waypoint.FUN_005c3420();
    }
    else
    {
        result = RandomOffsetVectorFromOrigin(destination, 800.0f, 300.0f, 0);
        Pathing_FindPointOnNavMesh(ref->TESObjectREFR_GetWorldSpace(), ref->GetParentCellStub(), &result, 300.0f, &result);
    }
    return result;
}
}  // namespace fnv_009f6900

struct FUN_004f2770_Class;
extern FUN_004f2770_Class* _g_thePlayer;

struct FUN_0041ce10_Holder
{
    void ClearScript(void* obj);
};
FUN_0041ce10_Holder* __fastcall BSFile_GetDevice(FUN_004f2770_Class* player);

struct FUN_009f9450 : TESPackage
{
    virtual ~FUN_009f9450();
};

// Destructor that, if _g_thePlayer is set, gets its holder via FUN_005d43c0 and calls ClearScript on this object.
// @fnv 0x009f9450
FUN_009f9450::~FUN_009f9450()
{
    if (_g_thePlayer)
    {
        BSFile_GetDevice(_g_thePlayer)->ClearScript(this);
    }
}

struct FUN_006e6da0
{
    int a, b;
};
void* __cdecl operator new(unsigned int uiSize, FUN_006e6da0* pPlace);
inline void __cdecl operator delete(void*, FUN_006e6da0*)
{}
class FUN_009e9af0
{
  public:
    FUN_009e9af0();
    int unk0, unk4;
};
class ArrX
{
  public:
    void ConstructElements(FUN_006e6da0* pData, unsigned int ItemUpdateArray);
};
// @fnv 0x009e9a50
void ArrX::ConstructElements(FUN_006e6da0* pData, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        new (&pData[i]) FUN_009e9af0;
    }
}

struct FUN_009dad00
{
    FUN_009dad00(void*);
    virtual ~FUN_009dad00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
};
extern const float DAT_01012054;
struct FUN_009e9d00 : FUN_009dad00
{
    NiPoint3 position;
    int unk94;
    int unk98;
    float unk9c;
    FUN_009e9d00(void*);
    virtual ~FUN_009e9d00();
};
// Constructor that initializes position to zero, sets unk94 and unk98 to 0, and assigns unk9c from DAT_01012054.
// @fnv 0x009e9d00
FUN_009e9d00::FUN_009e9d00(void* arg) : FUN_009dad00(arg)
{
    position = NiPoint3::ZERO;
    unk94 = 0;
    unk9c = DAT_01012054;
    unk98 = 0;
}


// member at +0x20, initialised by FUN_009f61b0
struct SandBoxLocation
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    void FUN_009f61b0();
};

class FUN_009f3900 : public ActorPackageData
{
  public:
    int m_04;
    int m_08;
    float m_0c;
    int m_10;
    float m_14;
    float m_18;
    int m_1c;
    SandBoxLocation m_kPathingLocation;
    int m_30;
    bool m_34;
    bool m_35;
    bool m_36;
    bool m_37;
    int unk38;
    int m_3c;
    char m_40;
    int m_44;
    int unk48;
    int m_4c;
    float m_50;
    float m_54;
    int m_58;
    unsigned char m_5c[6];
    FUN_009f3900();
};

// Constructor that sets the vtable, calls m_kPathingLocation.FUN_009f61b0(), initialises fields (some to -1, m_40 to 0x7f) and fills m_5c with 0x80.
// @fnv 0x009f3900
FUN_009f3900::FUN_009f3900()
{
    m_kPathingLocation.FUN_009f61b0();
    m_08 = -1;
    m_0c = 0.0f;
    m_14 = 0.0f;
    m_18 = 0.0f;
    m_30 = 0;
    m_1c = -1;
    m_34 = true;
    m_35 = false;
    m_36 = false;
    m_37 = false;
    m_3c = 0;
    m_44 = 0;
    m_40 = 0x7f;
    m_10 = 0;
    m_04 = 0;
    m_4c = 0;
    m_50 = 0.0f;
    m_54 = 0.0f;
    m_58 = -1;
    for (int i = 0; i < 6; i++)
        m_5c[i] = 0x80;
}

struct FUN_009f61e0_Class : FUN_009f61e0
{
    void* FUN_009f6430(unsigned int flags);
};

// Initializes the object, deallocates it if the low bit of flags is set, and returns this.
// @fnv 0x009f6430
void* FUN_009f61e0_Class::FUN_009f6430(unsigned int flags)
{
    Init();
    if (flags & 1)
        Deallocate(this);
    return this;
}
