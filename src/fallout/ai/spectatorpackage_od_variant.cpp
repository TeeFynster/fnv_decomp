
// src/fallout/ai/spectatorpackage_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/spectatorpackage.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "spectatorpackage_decls.h"
#include "../../../include/SpectatorPackage.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/Actor.h"
#include "../../../include/MobileObject.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/TESForm.h"
#include "../../../include/BGSSaveGameBuffer.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/GameTimerRecord.h"
#include "../../../include/TESPackage.h"
#include "../../../include/BSSimpleArray.h"
#include "../../../include/Setting.h"
#include "../../../include/CombatController.h"
#include "../../../include/TESObjectWEAP.h"


struct FUN_009f7050_class
{
    NiPoint3& FUN_009f7050(NiPoint3& akDest);
};

// @fnv 0x009f7050
NiPoint3& FUN_009f7050_class::FUN_009f7050(NiPoint3& akDest)
{
    akDest = *reinterpret_cast<const NiPoint3*>(reinterpret_cast<const char*>(this) + 0x14);
    return akDest;
}

namespace fnv_009f7080 {

struct FUN_009f7080_class
{
    NiPoint3& FUN_009f7080(NiPoint3& akDest);
};

// @fnv 0x009f7080
NiPoint3& FUN_009f7080_class::FUN_009f7080(NiPoint3& akDest)
{
    akDest = *reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0x20);
    return akDest;
}
}  // namespace fnv_009f7080

unsigned int __cdecl gm_GetTickCount(void);
struct Helper62d0
{
    Helper62d0& operator=(const Helper62d0&);
};
// Retained locally: include/ has no SpectatorThreatInfo.h; 0x009f7630 copies this 0x34-byte record.
struct SpectatorThreatInfo
{
    Actor* pSource;
    Actor* pTarget;
    int m_iFirstInteger;
    unsigned int m_uiSecondValue;
    float fRadius;
    NiPoint3 aPos;
    NiPoint3 bPos;
    bool m_bFirstFlag;
    bool m_bFollowingFlag;
    char _pad[2];
    Helper62d0 spEffect;
    void __thiscall FUN_009f70b0(BGSSaveFormBuffer* buffer);
    void FUN_009f7170(BGSLoadFormBuffer* buffer);
    unsigned int __thiscall _ref_00726070();
    SpectatorThreatInfo& FUN_009f7630(const SpectatorThreatInfo& that);
};
// @fnv 0x009f70b0
void __thiscall SpectatorThreatInfo::FUN_009f70b0(BGSSaveFormBuffer* buffer)
{
    unsigned int imodifiedPerceivedTime;
    buffer->SaveData(reinterpret_cast<char*>(this) + 8, 4, 0);
    imodifiedPerceivedTime = gm_GetTickCount() - ((unsigned int*)this)[3];
    buffer->SaveData(&imodifiedPerceivedTime, 4, 0);
    buffer->SaveData(reinterpret_cast<char*>(this) + 16, 4, 0);
    buffer->SaveData(reinterpret_cast<char*>(this) + 20, 12, 0);
    buffer->SaveData(reinterpret_cast<char*>(this) + 32, 12, 0);
    buffer->SaveData(reinterpret_cast<char*>(this) + 44, 1, 0);
    buffer->SaveData(reinterpret_cast<char*>(this) + 45, 1, 0);
    buffer->SerializeFormData(*(void**)this, 0);
    buffer->SerializeFormData(*(void**)(reinterpret_cast<char*>(this) + 4), 0);
}

// @fnv 0x009f7170
void SpectatorThreatInfo::FUN_009f7170(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData(static_cast<void*>(reinterpret_cast<char*>(this) + 8), 4u);
    unsigned int imodifiedPerceivedTime = 0;
    buffer->ReadTypedData(static_cast<void*>(&imodifiedPerceivedTime), 4u);
    *(unsigned int*)(reinterpret_cast<char*>(this) + 0xc) = gm_GetTickCount() - imodifiedPerceivedTime;
    buffer->ReadTypedData(static_cast<void*>(reinterpret_cast<char*>(this) + 0x10), 4u);
    buffer->ReadTypedData(static_cast<void*>(reinterpret_cast<char*>(this) + 0x14), 0xcu);
    buffer->ReadTypedData(static_cast<void*>(reinterpret_cast<char*>(this) + 0x20), 0xcu);
    buffer->ReadTypedData(static_cast<void*>(reinterpret_cast<char*>(this) + 0x2c), 1u);
    buffer->ReadTypedData(static_cast<void*>(reinterpret_cast<char*>(this) + 0x2d), 1u);
    buffer->ReadFormIdentifier(this);
    buffer->ReadFormIdentifier(reinterpret_cast<char*>(this) + 4);
}

struct FUN_009f73e0
{
    void __thiscall FUN_009f7410();
    void* __thiscall DeleteThis(unsigned int flags);
};

// @fnv 0x009f73e0
void* FUN_009f73e0::DeleteThis(unsigned int flags)
{
    FUN_009f7410();
    if (flags & 1)
        operator delete(this);
    return this;
}

namespace fnv_009f8300 {

struct FUN_009f8300_class
{
    NiPoint3& FUN_009f8300(NiPoint3& akDest);
};

// @fnv 0x009f8300
NiPoint3& FUN_009f8300_class::FUN_009f8300(NiPoint3& akDest)
{
    akDest = *reinterpret_cast<const NiPoint3*>(reinterpret_cast<const char*>(this) + 0x94);
    return akDest;
}
}  // namespace fnv_009f8300

struct Saver
{
    unsigned short FUN_00678fd0();
    unsigned short FUN_009f86f0();
};
// @fnv 0x009f86f0
unsigned short Saver::FUN_009f86f0()
{
    unsigned short size = 0;
    size += FUN_00678fd0();
    size += 8;
    return size;
}

struct Base009f8770
{
    void FUN_00679340();
};
struct Helper009f8770
{
    void FUN_00484d00(void*, int);
};
struct Holder009f8770
{
    void FUN_009f8770();
};
// @fnv 0x009f8770
void Holder009f8770::FUN_009f8770()
{
    ((Base009f8770*)this)->FUN_00679340();
    ((Helper009f8770*)this)->FUN_00484d00((char*)this + 0x84, 4);
    ((Helper009f8770*)this)->FUN_00484d00((char*)this + 0x88, 4);
}

struct FUN_009f8aa0_class
{
    int __thiscall FUN_009f8ac0(int);
    int __thiscall FUN_009f8aa0();
};
// @fnv 0x009f8aa0
int __thiscall FUN_009f8aa0_class::FUN_009f8aa0()
{
    return FUN_009f8ac0(0);
}

struct FUN_009f8ac0_class
{
    int __thiscall FUN_009f8ac0(int a);
};
// @fnv 0x009f8ac0
int __thiscall FUN_009f8ac0_class::FUN_009f8ac0(int a)
{
    return a * 0x34 + *(int*)((char*)this + 4);
}

extern int DAT_01093980;
struct FUN_009f8ae0Class
{
    void* vtbl;
    void FUN_009f90f0(int a, int b);
    void* FUN_009f8ae0(int a, int b);
};
// @fnv 0x009f8ae0
void* FUN_009f8ae0Class::FUN_009f8ae0(int a, int b)
{
    vtbl = &DAT_01093980;
    FUN_009f90f0(a, b);
    return this;
}

namespace fnv_009f8b10 {
extern int DAT_01093980;
// 0x01093980 is the threat-array vtable; 0x009f8d00 clears its 0x34-byte records.
struct ThreatRecordArray
{
    void* ReallocateStorage(int);
    void FUN_009f8b10();
};
// @fnv 0x009f8b10
void ThreatRecordArray::FUN_009f8b10()
{
    *reinterpret_cast<void**>(this) = &DAT_01093980;
    ReallocateStorage(1);
}
}  // namespace fnv_009f8b10

// SpectatorThreatInfo records are 0x34 bytes. Keep this element view until a
// shared header exposes the record and its deleting destructor.
struct S009f9180
{
    char data[0x34];
    void __thiscall FUN_009f9180(int);
};

// 0x006a8500 releases pBuffer through _Deallocate (virtual slot 2), then clears it.
void __fastcall ReleaseSpectatorThreatArrayBuffer(BSSimpleArray<S009f9180, 1024>*);

// @fnv 0x009f8d00
template <>
void BSSimpleArray<S009f9180, 1024>::Clear(bool freeStorage)
{
    if (pBuffer)
    {
        ReleaseElements(pBuffer, iSize);
        if (freeStorage)
        {
            ReleaseSpectatorThreatArrayBuffer(this);
            pBuffer = 0;
            SimpleArrayStorage = 0;
        }
        iSize = 0;
    }
}

struct FUN_009f8d60_Class
{
    void* __thiscall FUN_009f8d60(int size);
};

// @fnv 0x009f8d60
void* __thiscall FUN_009f8d60_Class::FUN_009f8d60(int size)
{
    void* memory = operator new(size * 0x34);
    return memory;
}

extern "C" void* __cdecl Reallocate(void*, int);

struct FUN_009f8d90
{
    void* __thiscall Reallocate(void* p, int n);
};

// @fnv 0x009f8d90
void* __thiscall FUN_009f8d90::Reallocate(void* p, int n)
{
    return ::Reallocate(p, n * 0x34);
}

struct FUN_009f8b10_class
{
    void FUN_009f8b10();
    void* FUN_009f8db0(unsigned int flags);
};

// @fnv 0x009f8db0
void* FUN_009f8b10_class::FUN_009f8db0(unsigned int flags)
{
    FUN_009f8b10();
    if (flags & 1)
        operator delete(this);
    return this;
}

// @fnv 0x009f8f60
template <>
void BSSimpleArray<S009f9180, 1024>::ReleaseElements(S009f9180* a1, unsigned int a2)
{
    for (int i = 0; i < a2; ++i)
        a1[i].FUN_009f9180(0);
}

// Exe 0x009f7fe0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct SpectatorpackageOffset08View
{
    unsigned int GetFlags();
};
struct Holder_009f7fe0
{
    char _pad0[0x90];
    unsigned char _flag90;
    char _pad1[0xA0 - 0x90 - 1];
    SpectatorpackageOffset08View _arrA0;
    bool FUN_009f7fe0();
};
// @fnv 0x009f7fe0
bool Holder_009f7fe0::FUN_009f7fe0()
{
    return _arrA0.GetFlags() == 0 || _flag90 != 0;
}

struct PC7d
{
    void FUN_00484ce0(unsigned int, int);
};
struct S00679120
{
    void SavePackage();
};
struct Wrap
{
    char _pad[0x84];
    unsigned int u84;
    unsigned int u88;
    void FUN_009f8730();
};
// @fnv 0x009f8730
void Wrap::FUN_009f8730()
{
    ((S00679120*)this)->SavePackage();
    ((PC7d*)this)->FUN_00484ce0((unsigned int)&u84, 4);
    ((PC7d*)this)->FUN_00484ce0((unsigned int)&u88, 4);
}

struct TESObjectREFRHelper
{
    void SetTargetingState(bool);
};
struct FUN_009f7230_class
{
    Actor* p;
    Actor* q;
    void FUN_009f7230(TESObjectREFRHelper* a);
};
TESForm* __cdecl GetFormByID(unsigned int);
// @fnv 0x009f7230
void FUN_009f7230_class::FUN_009f7230(TESObjectREFRHelper* a)
{
    p = p ? dynamic_cast<Actor*>(GetFormByID((unsigned int)p)) : 0;
    q = q ? dynamic_cast<Actor*>(GetFormByID((unsigned int)q)) : 0;
    if (p)
        ((TESObjectREFRHelper*)p)->SetTargetingState(true);
    if (q)
        ((TESObjectREFRHelper*)q)->SetTargetingState(true);
}

struct Flt
{
    operator unsigned int();
};
struct FUN_009f8a80_class
{
    Flt* FUN_009f8a80(unsigned int);
    void* _ref_00726070();
};
struct FUN_009f8c70_class
{
    void FUN_009f8c70(unsigned int, unsigned int);
};
struct FUN_009f84d0_class
{
    char _pad[0xA0];
    SpectatorpackageOffset08View arr;
    void FUN_009f84d0(unsigned int);
};

// @fnv 0x009f84d0
void FUN_009f84d0_class::FUN_009f84d0(unsigned int id)
{
    int count = arr.GetFlags();
    for (int i = 0; i < count; ++i)
    {
        Flt* item = reinterpret_cast<FUN_009f8a80_class*>(&arr)->FUN_009f8a80(i);
        if (item->operator unsigned int() == id ||
            reinterpret_cast<FUN_009f8a80_class*>(item)->_ref_00726070() == (void*)id)
        {
            reinterpret_cast<FUN_009f8c70_class*>(&arr)->FUN_009f8c70(i, 1);
            --count;
            --i;
        }
    }
}

struct FUN_009f8660_class
{
    void FUN_009f8660(BSSimpleArray<Actor*, 1024>& aArray);
};
// @fnv 0x009f8660
void FUN_009f8660_class::FUN_009f8660(BSSimpleArray<Actor*, 1024>& aArray)
{
    aArray.Clear(true);
    unsigned int count = ((FUN_009f84d0_class*)this)->arr.GetFlags();
    aArray.GrowCapacity(count << 1);
    {
        int i = 0;
        int j = 0;
        for (; j < (int)count; j++)
        {
            Flt* form = ((FUN_009f8a80_class*)((char*)this + 0xa0))->FUN_009f8a80(j);
            Actor* id = reinterpret_cast<Actor*>((unsigned int)*form);
            if (id)
                aArray.Add(id);
        }
    }
}

struct FUN_00679a90_shell
{
    void DispatchToSubobjects(void*);
};
struct FUN_009f8a10 : FUN_00679a90_shell
{
    void InitLoadGame(void* apLoadGameBuffer);
};
// @fnv 0x009f8a10
void FUN_009f8a10::InitLoadGame(void* apLoadGameBuffer)
{
    unsigned int i;
    unsigned int isaveGameCount8;
    SpectatorThreatInfo* threatInfo;
    DispatchToSubobjects(apLoadGameBuffer);
    isaveGameCount8 = ((SpectatorpackageOffset08View*)((char*)this + 0xa0))->GetFlags();
    for (i = 0; i < isaveGameCount8; ++i)
    {
        threatInfo = (SpectatorThreatInfo*)((FUN_009f8a80_class*)((char*)this + 0xa0))->FUN_009f8a80(i);
        ((FUN_009f7230_class*)threatInfo)->FUN_009f7230((TESObjectREFRHelper*)apLoadGameBuffer);
    }
}

// @fnv 0x009f7630
SpectatorThreatInfo& SpectatorThreatInfo::FUN_009f7630(const SpectatorThreatInfo& that)
{
    pSource = that.pSource;
    pTarget = that.pTarget;
    m_iFirstInteger = that.m_iFirstInteger;
    m_uiSecondValue = that.m_uiSecondValue;
    fRadius = that.fRadius;
    aPos = that.aPos;
    bPos = that.bPos;
    m_bFirstFlag = that.m_bFirstFlag;
    m_bFollowingFlag = that.m_bFollowingFlag;
    spEffect = that.spEffect;
    return *this;
}

struct FUN_006797c0_shell
{
    void __thiscall FUN_006797c0(void*);
};



GameTimerRecord g_timeGlobal;

struct SpectatorPackageSave : SpectatorPackage
{
    void __thiscall FUN_009f87d0(BGSSaveFormBuffer* apSaveGameBuffer);
};

// @fnv 0x009f87d0
void SpectatorPackageSave::FUN_009f87d0(BGSSaveFormBuffer* apSaveGameBuffer)
{
    int i;
    unsigned int threatInfo;
    unsigned int ipathTimeDelta;
    SpectatorThreatInfo* isaveGameCount;

    reinterpret_cast<FUN_006797c0_shell*>(this)->FUN_006797c0(apSaveGameBuffer);

    i = g_timeGlobal.GetTime() - *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x80);

    apSaveGameBuffer->SaveData(&i, 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x84), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x88), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x8c), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x90), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x94), 12, 0);

    threatInfo = reinterpret_cast<SpectatorpackageOffset08View*>(reinterpret_cast<char*>(this) + 0xa0)
                     ? reinterpret_cast<SpectatorpackageOffset08View*>(reinterpret_cast<char*>(this) + 0xa0)->GetFlags()
                     : 0;

    reinterpret_cast<BGSSaveGameBuffer*>(apSaveGameBuffer)->FUN_00865f60(threatInfo);

    for (ipathTimeDelta = 0; ipathTimeDelta < threatInfo; ++ipathTimeDelta)
    {
        isaveGameCount = reinterpret_cast<SpectatorThreatInfo*>(
            reinterpret_cast<FUN_009f8a80_class*>(reinterpret_cast<char*>(this) + 0xa0)->FUN_009f8a80(ipathTimeDelta));
        isaveGameCount->FUN_009f70b0(apSaveGameBuffer);
    }
}

struct FUN_009f8a80_wrapper : FUN_009f8aa0_class
{
    int __thiscall FUN_009f8a80(unsigned int a);
};
// @fnv 0x009f8a80
int FUN_009f8a80_wrapper::FUN_009f8a80(unsigned int a)
{
    return FUN_009f8ac0((int)a);
}

// @fnv 0x009f8420
void SpectatorPackage::FUN_009f8420(Actor& aActor)
{
    SpectatorThreatInfo* scanInfo;
    int isize_ = reinterpret_cast<SpectatorpackageOffset08View*>(reinterpret_cast<char*>(this) + 0xA0)->GetFlags();
    int i6 = 0;

    for (; i6 < isize_; ++i6)
    {
        scanInfo = reinterpret_cast<SpectatorThreatInfo*>(
            reinterpret_cast<FUN_009f8a80_class*>(reinterpret_cast<char*>(this) + 0xA0)->FUN_009f8a80(i6));

        if (reinterpret_cast<Flt*>(scanInfo)->operator unsigned int() == reinterpret_cast<unsigned int>(&aActor))
        {
            reinterpret_cast<FUN_009f8c70_class*>(reinterpret_cast<char*>(this) + 0xA0)->FUN_009f8c70(i6, 1);
            isize_--;
            i6--;
        }
        else if (scanInfo->_ref_00726070() ==
                 reinterpret_cast<unsigned int>(&aActor))
        {
            *reinterpret_cast<Actor**>(reinterpret_cast<char*>(scanInfo) + 4) = 0;
            *reinterpret_cast<bool*>(reinterpret_cast<char*>(scanInfo) + 0x2D) = false;
        }
    }
}



struct FUN_009f8b30_class
{
    void __thiscall FUN_009f8b30(unsigned int size, int flag);
};

struct FUN_009f8900_class
{
    unsigned char _pad00[0x80];
    unsigned int field80;
    unsigned int field84;
    unsigned int field88;
    unsigned int field8C;
    unsigned char field90;
    unsigned char _pad91[3];
    unsigned char field94[12];
    unsigned char _padA0[4];

    void __thiscall FUN_009f8900(BGSLoadFormBuffer* buffer);
};

// @fnv 0x009f8900
void FUN_009f8900_class::FUN_009f8900(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<TESPackage*>(this)->TESPackage::LoadGame(apLoadGameBuffer);

    int ipathTimeDelta = 0;
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&ipathTimeDelta), 4u);
    field80 = g_timeGlobal.GetTime() - ipathTimeDelta;

    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&field84), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&field88), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&field8C), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&field90), 1u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(field94), 12u);

    {
        unsigned int isaveGameCount = apLoadGameBuffer->ReadElementCount();

        reinterpret_cast<FUN_009f8b30_class*>(reinterpret_cast<unsigned char*>(this) + 0xA0)
            ->FUN_009f8b30(isaveGameCount, 1);

        {
            unsigned int i;
            for (i = 0; i < isaveGameCount; ++i)
            {
                SpectatorThreatInfo* threatInfo = reinterpret_cast<SpectatorThreatInfo*>(
                    reinterpret_cast<FUN_009f8a80_wrapper*>(reinterpret_cast<unsigned char*>(this) + 0xA0)
                        ->FUN_009f8a80(i));

                threatInfo->FUN_009f7170(apLoadGameBuffer);
            }
        }
    }
}

unsigned int __cdecl gm_GetTickCount(void);
int __cdecl ClampThreat(int, int);
struct ThreatInfo
{
    Actor* pSource;
    Actor* pTarget;
    int m_iFirstInteger;
    unsigned int m_uiSecondValue;
    float fRadius;
    NiPoint3 aPos;
    NiPoint3 bPos;
    void FUN_009f6d50();
};
// @fnv 0x009f6d50
void ThreatInfo::FUN_009f6d50()
{
    m_uiSecondValue = pSource ? gm_GetTickCount() : m_uiSecondValue;
    NiPoint3* pA = pSource ? static_cast<const Actor*>(pSource)->GetPos() : &aPos;
    aPos = *pA;
    NiPoint3* pB = pTarget ? static_cast<const Actor*>(pTarget)->GetPos() : &bPos;
    bPos = *pB;
    CombatController* pItem = pSource ? pSource->GetCombatController() : 0;
    TESObjectWEAP* pWeap7 = pItem ? static_cast<TESObjectWEAP*>(pItem->FUN_007031c0()) : 0;
    int iLevel = 0;
    if (pWeap7)
    {
        switch (pWeap7->GetWeaponType())
        {
        case 0:
            iLevel = 3;
            fRadius = 512.0f;
            break;
        case 1:
            iLevel = 2;
            fRadius = 256.0f;
            break;
        case 2:
            iLevel = 1;
            fRadius = 128.0f;
            break;
        case 3:
            iLevel = 3;
            fRadius = 512.0f;
            break;
        case 4:
            iLevel = 3;
            fRadius = 256.0f;
            break;
        }
    }
    m_iFirstInteger = ClampThreat(m_iFirstInteger, iLevel);
}

class Base_9f72f0
{
  public:
    virtual ~Base_9f72f0();
    Base_9f72f0();
};

struct Vec3U
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
};

extern Vec3U DAT_011f426c;

class SubA0
{
  public:
    SubA0(int a, int b);
    ~SubA0();
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0c;
};

class SubB0
{
  public:
    SubB0(int a);
    ~SubB0();
    unsigned int m_unk00;
    unsigned int m_unk04;
};

class FUN_009f72f0 : public Base_9f72f0
{
  public:
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0c;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18;
    unsigned int m_unk1c;
    unsigned int m_unk20;
    unsigned int m_unk24;
    unsigned int m_unk28;
    unsigned int m_unk2c;
    unsigned int m_unk30;
    unsigned int m_unk34;
    unsigned int m_unk38;
    unsigned int m_unk3c;
    unsigned int m_unk40;
    unsigned int m_unk44;
    unsigned int m_unk48;
    unsigned int m_unk4c;
    unsigned int m_unk50;
    unsigned int m_unk54;
    unsigned int m_unk58;
    unsigned int m_unk5c;
    unsigned int m_unk60;
    unsigned int m_unk64;
    unsigned int m_unk68;
    unsigned int m_unk6c;
    unsigned int m_unk70;
    unsigned int m_unk74;
    unsigned int m_unk78;
    unsigned int m_unk7c;
    int m_i80;
    unsigned int m_unk84;
    float m_f88;
    float m_f8c;
    unsigned char m_b90;
    Vec3U m_v94;
    SubA0 m_a0;
    SubB0 m_b0;
    FUN_009f72f0();
    virtual ~FUN_009f72f0();
    void SetPackageType(int a);
    void FUN_00984f60(int a);
};

// @fnv 0x009f72f0
FUN_009f72f0::FUN_009f72f0() : m_v94(DAT_011f426c), m_a0(0x20, 0), m_b0(0)
{
    SetPackageType(0x18);
    m_i80 = 0;
    m_f88 = 0.0f;
    m_f8c = 0.0f;
    m_b90 = 0;
    FUN_00984f60(0xf);
}

struct ActorObject
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void RemoveReference(void* referencedObject);
};
struct ObjectRef
{
    ActorObject* FUN_009611e0();
};
struct FUN_006708b0
{
    virtual ~FUN_006708b0();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
};
struct FUN_009f8b10
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~FUN_009f8b10();
};
struct FUN_0045cec0
{
    ObjectRef* FUN_00559450();
    void FUN_0066b0d0(int release);
    ~FUN_0045cec0();
};
struct FUN_009f7410 : FUN_006708b0
{
    FUN_009f8b10 memberA0;
    FUN_0045cec0 memberB0;
    virtual ~FUN_009f7410();
};
// @fnv 0x009f7410
FUN_009f7410::~FUN_009f7410()
{
    if (memberB0.FUN_00559450())
    {
        if (memberB0.FUN_00559450()->FUN_009611e0())
        {
            memberB0.FUN_00559450()->FUN_009611e0()->RemoveReference(memberB0.FUN_00559450());
        }
        memberB0.FUN_0066b0d0(0);
    }
}

struct Parameter
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual void slot216();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();
    virtual void slot240();
    virtual void slot241();
    virtual void slot242();
    virtual void slot243();
    virtual void slot244();
    virtual void slot245();
    virtual void slot246();
    virtual void slot247();
    virtual void slot248();
    virtual void slot249();
    virtual void slot250();
    virtual void slot251();
    virtual void slot252();
    virtual void slot253();
    virtual void slot254();
    virtual void slot255();
    virtual void slot256();
    virtual void slot257();
    virtual void slot258();
    virtual void slot259();
    virtual void slot260();
    virtual void slot261();
    virtual void slot262();
    virtual void slot263();
    virtual void slot264();
    virtual void slot265();
    virtual void slot266();
    virtual int GetMark();
};
struct Entry
{
    Parameter* FUN_00559450();
    int FUN_00726070();
    void SetSourceReference(Parameter*);
};
struct ThreatList
{
    int FUN_0044ddc0();
    Entry* FUN_009f8a80(int);
    void FUN_009f8b30(int, int);
};
struct Package
{
    void FUN_009f8330(Parameter*);
    void FUN_009f76e0();
};
// @fnv 0x009f8330
void Package::FUN_009f8330(Parameter* actor)
{
    int id = actor->GetMark();
    int count = ((ThreatList*)((char*)this + 0xA0))->FUN_0044ddc0();
    Entry* match = 0;
    for (int i = 0; i < count; ++i)
    {
        Entry* e = ((ThreatList*)((char*)this + 0xA0))->FUN_009f8a80(i);
        if (e->FUN_00559450() == actor && e->FUN_00726070() == id)
        {
            match = e;
            break;
        }
    }
    if (!match)
    {
        int n = ((ThreatList*)((char*)this + 0xA0))->FUN_0044ddc0();
        ((ThreatList*)((char*)this + 0xA0))->FUN_009f8b30(n + 1, 1);
        match = ((ThreatList*)((char*)this + 0xA0))->FUN_009f8a80(n);
    }
    match->SetSourceReference(actor);
    FUN_009f76e0();
}

struct ThreatArray
{
    virtual void ReleaseStorage();
    virtual S009f9180* Allocate(unsigned int count);
    S009f9180* data;
    unsigned int size;
    unsigned int capacity;
    void EnsureBuffer(unsigned int, unsigned int);
    void FUN_009f8de0(S009f9180*, unsigned int);
    void FUN_009f8f60(S009f9180*, unsigned int);
    void FUN_009f8b30(unsigned int count, bool shrink);
};
// @fnv 0x009f8b30
void ThreatArray::FUN_009f8b30(unsigned int count, bool shrink)
{
    if (count == 0)
    {
        reinterpret_cast<BSSimpleArray<S009f9180, 1024>*>(this)->Clear(shrink);
    }
    else if (count > capacity)
    {
        if (capacity == 0)
        {
            data = Allocate(count);
            capacity = count;
        }
        else
        {
            EnsureBuffer(count, size);
            capacity = count;
        }
        FUN_009f8de0(data + size, count - size);
        size = count;
    }
    else if (count < size)
    {
        FUN_009f8f60(data + count, size - count);
        size = count;
        if (shrink && count <= capacity / 4)
        {
            EnsureBuffer(count, count);
            capacity = count;
        }
    }
    else
    {
        FUN_009f8de0(data + size, count - size);
        size = count;
    }
}

int __cdecl SpanIndex(int a, int b);

struct FUN_009f8c70_cls
{
    int unk00;
    char* m_pData;
    int m_uiItemCount;

    void FUN_009f8f60(void* apElem, unsigned int auiArg);
    void CopyElements(void* apDst, void* apSrc, int aiIdx);
    void FUN_009f8c70(unsigned int a1, unsigned int a2);
};

// @fnv 0x009f8c70
void FUN_009f8c70_cls::FUN_009f8c70(unsigned int a1, unsigned int a2)
{
    int idx = SpanIndex(m_uiItemCount - a1 - a2, a2);
    FUN_009f8f60(m_pData + a1 * 0x34, a2);
    CopyElements(m_pData + a1 * 0x34, m_pData + m_uiItemCount * 0x34 - idx * 0x34, idx);
    m_uiItemCount = m_uiItemCount - a2;
}

namespace fnv_009f8e80 {
struct FUN_009f8e80_vec3
{
    float x;
    float y;
    float z;
};

extern FUN_009f8e80_vec3 DAT_011f426c;

struct FUN_009f8e80_sub
{
    FUN_009f8e80_sub(int a);
    ~FUN_009f8e80_sub();
    void FUN_00633c90(int a);
    void FUN_0066b0d0(int a);
};

class FUN_009f8e80_cls
{
  public:
    FUN_009f8e80_cls();
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    float m_10;
    FUN_009f8e80_vec3 m_14;
    FUN_009f8e80_vec3 m_20;
    unsigned char m_2c;
    unsigned char m_2d;
    unsigned short m_2e;
    FUN_009f8e80_sub m_30;
};

// @fnv 0x009f8e80
FUN_009f8e80_cls::FUN_009f8e80_cls()
    : m_00(0), m_04(0), m_08(0), m_0c(0), m_10(0.0f), m_14(DAT_011f426c), m_20(DAT_011f426c), m_2c(0), m_2d(0), m_30(0)
{
    m_30.FUN_0066b0d0(0);
}
}  // namespace fnv_009f8e80

struct SpectatorVolume
{
    float f00, f04, f08, f0C, f10, f14, f18, f1C, f20;
    SpectatorVolume(const NiPoint3& akFrom, const NiPoint3& akTo, float afRadius, float afHeight);
    SpectatorVolume(const NiPoint3& akCenter, float afRadius, float afHeight);
};

struct SpectatorInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float fRadius;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    bool bHasStart;
    bool bHasEnd;

    NiPoint3 GetStart();
    NiPoint3 GetEnd();
    void FUN_009f6f30(SpectatorVolume& arVolume);
};

// @fnv 0x009f6f30
void SpectatorInfo::FUN_009f6f30(SpectatorVolume& arVolume)
{
    if (bHasStart)
    {
        if (bHasEnd)
        {
            arVolume = SpectatorVolume(GetStart(), GetEnd(), fRadius, 100.0f);
        }
        else
        {
            arVolume = SpectatorVolume(GetStart(), fRadius, 100.0f);
        }
    }
    else if (bHasEnd)
    {
        arVolume = SpectatorVolume(GetEnd(), fRadius, 100.0f);
    }
}

struct FUN_009f7500_class
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int field80;
    float field84;
    float field88;
    float field8c;
    unsigned char field90;
    unsigned char pad91;
    unsigned char pad92;
    unsigned char pad93;
    struct ThreeWords
    {
        unsigned int first;
        unsigned int second;
        unsigned int third;
    } field94;
    SpectatorpackageOffset08View arrA0;
    void CopyFromPackage(void*);
    void FUN_009f7500(void*);
};
extern int DAT_01183028;
extern int DAT_011a5fd8;
extern void* __cdecl FUN_00ec43fb(void*, int, int*, int*, int);
// @fnv 0x009f7500
void FUN_009f7500_class::FUN_009f7500(void* param_2)
{
    CopyFromPackage(param_2);
    FUN_009f7500_class* other = (FUN_009f7500_class*)FUN_00ec43fb(param_2, 0, &DAT_01183028, &DAT_011a5fd8, 0);
    if (other != 0)
    {
        field80 = other->field80;
        field84 = other->field84;
        field88 = other->field88;
        field8c = other->field8c;
        field94 = other->field94;
        field90 = other->field90;
        int count = other->arrA0.GetFlags();
        ((FUN_009f8b30_class*)&arrA0)->FUN_009f8b30(count, 1);
        int i;
        for (i = 0; i < count; i++)
        {
            ((SpectatorThreatInfo*)((FUN_009f8a80_class*)&arrA0)->FUN_009f8a80(i))
                ->FUN_009f7630(*(SpectatorThreatInfo*)((FUN_009f8a80_class*)&other->arrA0)->FUN_009f8a80(i));
        }
    }
}

namespace ThreatBounds {
struct Threat
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    bool hasSource, hasTarget;
    NiPoint3 FUN_009f7050();
    NiPoint3 FUN_009f7080();
};
struct ThreatList
{
    unsigned int unk00;
    int FUN_0044ddc0();
    Threat* FUN_009f8a80(int);
};
extern const NiPoint3 DAT_011f426c;
extern const float DAT_01016248;
float FUN_00404010(float, float);
float FUN_0040ebd0(float, float);
float FUN_004019d0(float);
struct Package
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    float radius;
    bool empty;
    NiPoint3 center;
    ThreatList threats;
    void FUN_009f76e0();
};
// @fnv 0x009f76e0
void Package::FUN_009f76e0()
{
    if (!threats.FUN_0044ddc0())
        return;
    int sizeSlot13 = threats.FUN_0044ddc0();
    int pointCountSlot1 = 0;
    NiPoint3 minimumSlot0 = DAT_011f426c;
    NiPoint3 maximumSlot27 = DAT_011f426c;
    bool unusedSlot12 = false;
    int index;
    for (index = 0; index < sizeSlot13; index++)
    {
        Threat* threat = threats.FUN_009f8a80(index);
        if (threat->hasSource && threat->hasTarget)
        {
            minimumSlot0.x = FUN_00404010(threat->FUN_009f7050().x, threat->FUN_009f7080().x);
            minimumSlot0.y = FUN_00404010(threat->FUN_009f7050().y, threat->FUN_009f7080().y);
            minimumSlot0.z = FUN_00404010(threat->FUN_009f7050().z, threat->FUN_009f7080().z);
            maximumSlot27.x = FUN_0040ebd0(threat->FUN_009f7050().x, threat->FUN_009f7080().x);
            maximumSlot27.y = FUN_0040ebd0(threat->FUN_009f7050().y, threat->FUN_009f7080().y);
            maximumSlot27.z = FUN_0040ebd0(threat->FUN_009f7050().z, threat->FUN_009f7080().z);
            pointCountSlot1 += 2;
            break;
        }
        else if (threat->hasSource)
        {
            minimumSlot0 = threat->FUN_009f7050();
            maximumSlot27 = threat->FUN_009f7050();
            pointCountSlot1++;
            break;
        }
        else if (threat->hasTarget)
        {
            minimumSlot0 = threat->FUN_009f7080();
            maximumSlot27 = threat->FUN_009f7080();
            pointCountSlot1++;
            break;
        }
    }
    for (index++; index < sizeSlot13; index++)
    {
        Threat* nextThreat = threats.FUN_009f8a80(index);
        if (nextThreat->hasSource)
        {
            minimumSlot0.x = FUN_00404010(minimumSlot0.x, nextThreat->FUN_009f7050().x);
            minimumSlot0.y = FUN_00404010(minimumSlot0.y, nextThreat->FUN_009f7050().y);
            minimumSlot0.z = FUN_00404010(minimumSlot0.z, nextThreat->FUN_009f7050().z);
            maximumSlot27.x = FUN_0040ebd0(maximumSlot27.x, nextThreat->FUN_009f7050().x);
            maximumSlot27.y = FUN_0040ebd0(maximumSlot27.y, nextThreat->FUN_009f7050().y);
            maximumSlot27.z = FUN_0040ebd0(maximumSlot27.z, nextThreat->FUN_009f7050().z);
            pointCountSlot1++;
        }
        if (nextThreat->hasTarget)
        {
            minimumSlot0.x = FUN_00404010(minimumSlot0.x, nextThreat->FUN_009f7080().x);
            minimumSlot0.y = FUN_00404010(minimumSlot0.y, nextThreat->FUN_009f7080().y);
            minimumSlot0.z = FUN_00404010(minimumSlot0.z, nextThreat->FUN_009f7080().z);
            maximumSlot27.x = FUN_0040ebd0(maximumSlot27.x, nextThreat->FUN_009f7080().x);
            maximumSlot27.y = FUN_0040ebd0(maximumSlot27.y, nextThreat->FUN_009f7080().y);
            maximumSlot27.z = FUN_0040ebd0(maximumSlot27.z, nextThreat->FUN_009f7080().z);
            pointCountSlot1++;
        }
    }
    if (pointCountSlot1 == 0)
    {
        empty = true;
        return;
    }
    NiPoint3 midpointSlot20 = minimumSlot0;
    midpointSlot20.FUN_0063c8a0(maximumSlot27);
    midpointSlot20.FUN_00439180(DAT_01016248);
    float distance = 0.0f;
    float radiusSquaredSlot57 = 0.0f;
    for (index = 0; index < sizeSlot13; index++)
    {
        Threat* radiusThreat = threats.FUN_009f8a80(index);
        if (!radiusThreat->hasSource && !radiusThreat->hasTarget)
            continue;
        if (radiusThreat->hasSource)
        {
            distance = midpointSlot20.FUN_00439ef0(radiusThreat->FUN_009f7050()).FUN_004a7290();
            if (distance >= radiusSquaredSlot57)
                radiusSquaredSlot57 = distance;
        }
        if (radiusThreat->hasTarget)
        {
            distance = midpointSlot20.FUN_00439ef0(radiusThreat->FUN_009f7080()).FUN_004a7290();
            if (distance >= radiusSquaredSlot57)
                radiusSquaredSlot57 = distance;
        }
    }
    center = midpointSlot20;
    radius = FUN_004019d0(radiusSquaredSlot57);
}
}

struct UnknownObject32
{
    unsigned int a, b, c, d, e, f, g, h;
};
struct UnknownObject64
{
    UnknownObject32 lo, hi;
};

struct TargetView;
struct TargetView
{
    virtual void tp0();
    virtual void tp1();
    virtual void tp2();
    virtual void tp3();
    virtual void tp4();
    virtual void tp5();
    virtual void tp6();
    virtual void tp7();
    virtual void tp8();
    virtual void tp9();
    virtual void tp10();
    virtual void tp11();
    virtual void tp12();
    virtual void tp13();
    virtual void tp14();
    virtual void tp15();
    virtual void tp16();
    virtual void tp17();
    virtual void tp18();
    virtual void tp19();
    virtual void tp20();
    virtual void tp21();
    virtual void tp22();
    virtual void tp23();
    virtual void tp24();
    virtual void tp25();
    virtual void tp26();
    virtual void tp27();
    virtual void tp28();
    virtual void tp29();
    virtual void tp30();
    virtual void tp31();
    virtual void tp32();
    virtual void tp33();
    virtual void tp34();
    virtual void tp35();
    virtual void tp36();
    virtual void tp37();
    virtual void tp38();
    virtual void tp39();
    virtual void tp40();
    virtual void tp41();
    virtual void tp42();
    virtual void tp43();
    virtual void tp44();
    virtual void tp45();
    virtual void tp46();
    virtual void tp47();
    virtual void tp48();
    virtual void tp49();
    virtual void tp50();
    virtual void tp51();
    virtual void tp52();
    virtual void tp53();
    virtual void tp54();
    virtual void tp55();
    virtual void tp56();
    virtual void tp57();
    virtual void tp58();
    virtual void tp59();
    virtual void tp60();
    virtual void tp61();
    virtual void tp62();
    virtual void tp63();
    virtual unsigned char IsActor();
};



struct FUN_009f7f20_class
{
    UnknownObject64 u0, u1;
    UnknownObject32 u2;
    SpectatorpackageOffset08View entries;
    void __thiscall FUN_009f7f20(MobileObject* actor, unsigned char flag);
};

// @fnv 0x009f7f20
void __thiscall FUN_009f7f20_class::FUN_009f7f20(MobileObject* actor, unsigned char flag)
{
    TargetView* AX;
    if (flag != 0)
    {
        if ((unsigned int)(((ThreatList*)((char*)this + 0xa0))->FUN_0044ddc0()) > 0)
        {
            TargetView* A5 =
                (TargetView*)((Entry*)((FUN_009f8aa0_class*)((char*)this + 0xa0))->FUN_009f8aa0())->FUN_00726070();
            AX = (A5 != 0 && A5->IsActor() != 0) ? A5 : (TargetView*)0;
            if (AX != 0)
            {
                ((BaseProcess*)actor->FUN_008d8520())->SetActorProcessState(reinterpret_cast<TESObjectREFR*>(AX));
                return;
            }
        }
    }
    ((BaseProcess*)actor->FUN_008d8520())->ClearCachedTargetReferences(true);
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned int bytes);
struct FUN_006e3850
{
    void* begin;
    void* end;
    void* reservedEnd;
    unsigned int capacity;
    unsigned int count;
    unsigned int flags;
    static __forceinline void* __cdecl operator new(unsigned int bytes)
    {
        return FUN_00aa13e0(bytes);
    }
    FUN_006e3850();
    int __thiscall FUN_0044ddc0();
    void __thiscall SetSize(int newCount, int preserve);
    void* __thiscall FUN_006a1400(int index);
};
struct ThreatItem_009f8570
{
    void __thiscall FUN_009f6f30(void* element);
};
struct FUN_009f8570_class
{
    FUN_006e3850* __thiscall FUN_009f8570();
};
// @fnv 0x009f8570
FUN_006e3850* __thiscall FUN_009f8570_class::FUN_009f8570()
{
    FUN_006e3850* output = new FUN_006e3850;
    int total = reinterpret_cast<ThreatList*>(reinterpret_cast<char*>(this) + 0xa0)->FUN_0044ddc0();
    for (int index = 0; index < total; ++index)
    {
        int used;
        ThreatItem_009f8570* item;
        item = reinterpret_cast<ThreatItem_009f8570*>(
            reinterpret_cast<ThreatList*>(reinterpret_cast<char*>(this) + 0xa0)->FUN_009f8a80(index));
        used = output->FUN_0044ddc0();
        output->SetSize(used + 1, 1);
        item->FUN_009f6f30(output->FUN_006a1400(used));
    }
    return output;
}

extern const double DAT_01012060;
unsigned int __cdecl FUN_00487f50();
void* __cdecl GetTopicSubTypeName(int iType, int iFlags);

extern Setting DAT_011cdc04;
extern Setting DAT_011ccff0;

struct Timer9f7d
{
    float FUN_0084d030();
};
extern Timer9f7d DAT_011f6394;


struct Candidate9f7d
{
    Actor* FUN_00726070();
};

struct List9f7d
{
    unsigned int FUN_0044ddc0();
    Candidate9f7d* FUN_009f8aa0();
};


struct FUN_009f7d70_cls
{
    unsigned char unk00[0x88];
    float m_fTimer;
    unsigned char unk8C[0xa0 - 0x8c];
    List9f7d m_kTargets;

    void FUN_009f7d70(Actor* pkActor, bool bActive);
};

// @fnv 0x009f7d70
void FUN_009f7d70_cls::FUN_009f7d70(Actor* pkActor, bool bActive)
{
    if (!bActive)
    {
        pkActor->MobileObject::FUN_008d8520()->SetCombatAlerted(false);
        pkActor->FUN_008b3ab0();
        return;
    }
    if (m_kTargets.FUN_0044ddc0() > 0)
    {
        int iRoll = FUN_00487f50() % 100;
        Actor* pkCandidate = m_kTargets.FUN_009f8aa0()->FUN_00726070();
        Actor* pkTarget = (pkCandidate && pkCandidate->IsActor()) ? pkCandidate : 0;
        if (pkTarget)
        {
            if (pkActor->MobileObject::FUN_008d8520() && !pkActor->MobileObject::FUN_008d8520()->IsDetecting() && iRoll < *DAT_011cdc04.FUN_00403e20() &&
                m_fTimer <= DAT_01012060)
            {
                void* pkPackage = GetTopicSubTypeName(6, 0);
                if (pkPackage)
                {
                    pkActor->FUN_0057bd60(pkTarget);
                    pkActor->MobileObject::FUN_008d8520()->ProcessDialogueTopic(reinterpret_cast<Actor*>(pkActor), reinterpret_cast<TESTopic*>(pkPackage), false, false, true, false);
                    m_fTimer = *DAT_011ccff0.FUN_00403e20();
                }
            }
            m_fTimer -= DAT_011f6394.FUN_0084d030();
        }
    }
}

// BaseProcess slot 0x504 returns DetectionViewData; this unit reads its count at +8.
struct DetectionStatePrefix
{
    int unk00;
    int unk04;
    int count;
};
struct Threat8020
{
    Actor* source;
    Actor* target;
    Actor* FUN_00559450();
    Actor* FUN_00726070();
    unsigned int FUN_0084e3a0();
    void FUN_009f6d50();
};
struct ThreatList8020
{
    int FUN_0044ddc0();
    Threat8020* FUN_009f8a80(int);
    void FUN_009f8c70(int, int);
};
extern Setting originalRuntimeFloatSetting144;
struct Package8020
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    ThreatList8020 threats;
    void FUN_009f8330(Actor*);
    void FUN_009f76e0();
    void FUN_004534f0(Actor*);
    void FUN_009f8020(Actor* actor);
};
// @fnv 0x009f8020
void Package8020::FUN_009f8020(Actor* owner)
{
    bool updated = false;
    int count = threats.FUN_0044ddc0();
    for (int i = 0; i < count; ++i)
    {
        Threat8020* entry = threats.FUN_009f8a80(i);
        if (entry->FUN_00559450() && entry->FUN_00726070())
        {
            Actor* currentTarget = entry->FUN_00559450()->GetCombatTarget();
            if (currentTarget && currentTarget != entry->FUN_00726070())
            {
                FUN_009f8330(owner);
                updated = true;
            }
        }
    }
    count = threats.FUN_0044ddc0();
    for (int j = 0; j < count; ++j)
    {
        Threat8020* entry = threats.FUN_009f8a80(j);
        Actor* actor = entry->FUN_00559450();
        Actor* target = entry->FUN_00726070();
        if (gm_GetTickCount() <= entry->FUN_0084e3a0() + 2000)
            continue;
        if (gm_GetTickCount() > entry->FUN_0084e3a0() + *originalRuntimeFloatSetting144.Float() * 1000.0)
        {
            threats.FUN_009f8c70(j, 1);
            --count;
            --j;
            updated = true;
            continue;
        }
        if (target && (target->HasHealth(0) || target->FUN_00440d80() || target->GetIsParalyzed() || target->GetHasKnockedState()))
        {
            entry->target = 0;
            updated = true;
            continue;
        }
        if (actor && actor->IsCharacter() && owner->MobileObject::FUN_008d8520())
        {
            DetectionStatePrefix* relation = owner->MobileObject::FUN_008d8520()
                ? reinterpret_cast<DetectionStatePrefix*>(owner->MobileObject::FUN_008d8520()->GetDetectionState(
                      actor, BaseProcess::_DetectionListType::BY_ME))
                : 0;
            if (!relation || relation->count <= 0)
                continue;
        }
        if (actor && target && actor->GetCombatTarget() != target)
            continue;
        updated = true;
        entry->FUN_009f6d50();
    }
    if (updated)
        FUN_009f76e0();
    FUN_004534f0(owner);
}

void* __cdecl operator new(unsigned int, void*);
void __cdecl operator delete(void*, void*);

struct Elem
{
    Elem();
    int unk00;
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
};

struct ElemArray
{
    void FUN_009f8de0(Elem* apArray, unsigned int ItemUpdateArray);
};

// @fnv 0x009f8de0
void ElemArray::FUN_009f8de0(Elem* apArray, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; ++i)
    {
        new (&apArray[i]) Elem;
    }
}
