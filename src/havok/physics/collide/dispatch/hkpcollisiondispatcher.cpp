#include "../../../../../include/hkArray.h"
#include "../../../../../include/BSAudio.h"
#include "../../../../../include/hkpCollisionDispatcher.h"

// src/havok/physics/collide/dispatch/hkpcollisiondispatcher.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/dispatch/hkpcollisiondispatcher.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00cfb1e0
{
    void Set(bool b);
};
// @fnv 0x00cfb1e0
void FUN_00cfb1e0::Set(bool b)
{
    *(reinterpret_cast<char*>(this) + 0x1e23) = b;
}

struct Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* p, int size);
};

inline Allocator& BSAudio::GetAlloc()
{
    return *reinterpret_cast<Allocator*>(SynchTimer.m_uiValueAt00);
}

BSAudio* hkMemoryRouter_getInstance();

inline void FreeBuffer(void* p)
{
    hkMemoryRouter_getInstance()->GetAlloc().Free(p, 0xc00);
}

struct Owner
{
    char pad[0x1e30];
    void* unk1e30;
    void* unk1e34;
    void* unk1e38;
    void* unk1e3c;
    void FreeBuffers();
};

// If unk1e30 is set, frees the four buffers at unk1e30..unk1e3c and clears them to null.
// @fnv 0x00cfbb40
void Owner::FreeBuffers()
{
    if (unk1e30)
    {
        FreeBuffer(unk1e30);
        FreeBuffer(unk1e34);
        FreeBuffer(unk1e38);
        FreeBuffer(unk1e3c);
        unk1e30 = 0;
        unk1e34 = 0;
        unk1e38 = 0;
        unk1e3c = 0;
    }
}

struct S_00cfb1f0_Ref
{
    void FUN_00c90510();
    void FUN_00c905b0();
};

struct S_00cfb1f0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    S_00cfb1f0_Ref* m_slot[64];
    void SetSlotPair(S_00cfb1f0_Ref* p, int a, int b);
};

// @fnv 0x00cfb1f0
void S_00cfb1f0_Obj::SetSlotPair(S_00cfb1f0_Ref* pRef, int iIndexA, int iIndexB)
{
    pRef->FUN_00c90510();
    m_slot[iIndexA + iIndexB * 8]->FUN_00c905b0();
    m_slot[iIndexA + iIndexB * 8] = pRef;
    pRef->FUN_00c90510();
    m_slot[iIndexB + iIndexA * 8]->FUN_00c905b0();
    m_slot[iIndexB + iIndexA * 8] = pRef;
}

struct CFB240ContactMgrFactory
{
    void RetainReference() const;
    void removeReference() const;
};

struct CFB240Dispatcher
{
    int unk00;
    int unk04;
    int unk08;
    CFB240ContactMgrFactory* m_apContactMgrFactoriesByResponsePair[8][8];

    void SetContactMgrFactory(CFB240ContactMgrFactory* fac, int responseA);
};

// For each of 8 slots, releases the old factory in row i and column responseA, then stores fac in both positions.
// @fnv 0x00cfb240
void CFB240Dispatcher::SetContactMgrFactory(CFB240ContactMgrFactory* apFactory, int aiResponseIndex)
{
    for (int i = 0; i < 8; i++)
    {
        apFactory->RetainReference();
        m_apContactMgrFactoriesByResponsePair[i][aiResponseIndex]->removeReference();
        m_apContactMgrFactoriesByResponsePair[i][aiResponseIndex] = apFactory;

        apFactory->RetainReference();
        m_apContactMgrFactoriesByResponsePair[aiResponseIndex][i]->removeReference();
        m_apContactMgrFactoriesByResponsePair[aiResponseIndex][i] = apFactory;
    }
}

const char* GetHavokShapeTypeName(int type);
int Vsnprintf(char* buf, int size, const char* fmt, ...);

struct IntegerPair
{
    int m_iFirst;
    int m_iSecond;
};

struct CollisionAgentEntry
{
    signed char m_iAgentTypeA;
    signed char m_iAgentTypeB;
    signed char m_priority;
};

// @fnv 0x00cfb2a0
void hkpCollisionDispatcher::RegisterAgentType(signed char (*table)[32], signed char agentType, int typeA, int typeB,
                                               signed char origTypeA, signed char origTypeB,
                                               CollisionAgentEntry (*entries)[32], int depth)
{
    m_bEnableDeprecatedFeature = true;

    for (int i = 0; i < m_numShapeInheritance; i++)
    {
        ::IntegerPair& si = m_pShapeInheritance[i];
        if (si.m_iSecond == typeA)
        {
            RegisterAgentType(table, agentType, si.m_iFirst, typeB, origTypeA, origTypeB, entries, depth + 1);
        }
        if (si.m_iSecond == typeB)
        {
            RegisterAgentType(table, agentType, typeA, si.m_iFirst, origTypeA, origTypeB, entries, depth + 1);
        }
    }

    int beginTypeA = typeA;
    int beginTypeB = typeB;
    int endTypeA = typeA + 1;
    int endTypeB = typeB + 1;
    int priority = depth;
    if (typeA == -1)
    {
        beginTypeA = 1;
        endTypeA = 32;
        priority++;
    }
    if (typeB == -1)
    {
        beginTypeB = 1;
        endTypeB = 32;
        priority++;
    }

    for (int a = beginTypeA; a < endTypeA; a++)
    {
        for (int b = beginTypeB; b < endTypeB; b++)
        {
            table[a][b] = agentType;
            if (entries)
            {
                CollisionAgentEntry& e = entries[a][b];
                if (m_debugWarnings && priority > e.m_priority)
                {
                    const char* entryNameA = GetHavokShapeTypeName(e.m_iAgentTypeA);
                    const char* entryNameB = GetHavokShapeTypeName(e.m_iAgentTypeB);
                    const char* typeNameA = GetHavokShapeTypeName(typeA);
                    const char* typeNameB = GetHavokShapeTypeName(typeB);
                    unsigned int buf[256];
                    Vsnprintf(
                        (char*)buf, 1000,
                        "Agent handling types <%s-%s> would override more specialized agent <%s-%s>\nMaybe the order of registering your collision agent is wrong, make sure you register your alternate type agents first",
                        typeNameA, typeNameB, entryNameA, entryNameB);
                }
                e.m_iAgentTypeA = origTypeA;
                e.m_priority = (signed char)priority;
                e.m_iAgentTypeB = origTypeB;
            }
        }
    }
}

struct FUN_00cfb510_cls
{
    void MergeBitsRecursive(unsigned int a1, unsigned int a2, int depth);
};

struct FUN_00cfb510_entry
{
    unsigned int unk00;
    unsigned int unk04;
};

// @fnv 0x00cfb510
void FUN_00cfb510_cls::MergeBitsRecursive(unsigned int uiDstIndex, unsigned int uiSrcIndex, int depth)
{
    unsigned int* bits = (unsigned int*)((char*)this + 0x110);
    bits[uiDstIndex] |= bits[uiSrcIndex];

    for (int i = 0; i < *(int*)((char*)this + 0x1e28); ++i)
    {
        FUN_00cfb510_entry* pEntries = *(FUN_00cfb510_entry**)((char*)this + 0x1e24);
        FUN_00cfb510_entry* e = &pEntries[i];
        if (e->unk04 == uiDstIndex)
        {
            this->MergeBitsRecursive(e->unk00, e->unk04, depth + 1);
        }
    }
}

// Record passed by pointer: five dwords, byte 0x11 is a flag.
struct FUN_00cfbbe0_rec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

class FUN_00cfbbe0_cls
{
  public:
    void __thiscall RegisterAgentType(void* p, int flag, int a2, int a3, int a4, int a5, int h, int g);
    void __thiscall AppendRecordAndRegisterAgents(FUN_00cfbbe0_rec* a1, int a2, int a3);
};

// Copies a record into the array at offset 0x9a0 at the current index, calls RegisterAgentType on several sub-objects, and increments the index.
// @fnv 0x00cfbbe0
// src: GUESS 0x00cfbbe0 (confidence: medium)
void FUN_00cfbbe0_cls::AppendRecordAndRegisterAgents(FUN_00cfbbe0_rec* pRecord, int a2, int a3)
{
    char* base = (char*)this;
    Owner* o = (Owner*)this;
    int idx = *(int*)(base + 0x190);
    FUN_00cfbbe0_rec* arr = (FUN_00cfbbe0_rec*)(base + 0x9a0);
    arr[idx].unk00 = pRecord->unk00;
    FUN_00cfbbe0_rec* slot = &arr[idx];
    slot->unk04 = pRecord->unk04;
    slot->unk08 = pRecord->unk08;
    slot->unk0c = pRecord->unk0c;
    slot->unk10 = pRecord->unk10;

    RegisterAgentType(base + 0xeb0, 1, a2, a3, a2, a3, (int)o->unk1e38, 0);
    RegisterAgentType(base + 0x1a0, *(int*)(base + 0x190), a2, a3, a2, a3, (int)o->unk1e30, 0);
    if (((unsigned char*)pRecord)[0x11] != 0)
    {
        RegisterAgentType(base + 0x12b0, 1, a2, a3, a2, a3, (int)o->unk1e3c, 0);
        RegisterAgentType(base + 0x5a0, *(int*)(base + 0x190), a2, a3, a2, a3, (int)o->unk1e34, 0);
    }
    (*(int*)(base + 0x190))++;
}

struct SpawnRequest
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    union
    {
        int unk10;
        struct
        {
            unsigned char unk10b0;
            unsigned char unk10b1;
            unsigned char unk10b2;
            unsigned char unk10b3;
        };
    };
};

struct SpawnEntry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

struct FUN_00cfbcc0_cls
{
    void AddSpawnEntry(SpawnRequest* req, int a, int b);
    void RegisterAgentType(char* p, int idx, int a, int b, int c, int d, int e, int f);
};

// @fnv 0x00cfbcc0
void FUN_00cfbcc0_cls::AddSpawnEntry(SpawnRequest* pRequest, int a, int b)
{
    char* self = (char*)this;
    int idx = *(int*)(self + 0x190);
    *(int*)(self + 0x9a0 + idx * 20) = pRequest->unk00;
    SpawnEntry* entry = (SpawnEntry*)(self + 0x9a0 + idx * 20);
    entry->unk04 = pRequest->unk04;
    entry->unk08 = pRequest->unk08;
    entry->unk0c = pRequest->unk0c;
    entry->unk10 = pRequest->unk10;

    int tail = *(int*)(self + 0x1e30);
    RegisterAgentType(self + 0x1a0, *(int*)(self + 0x190), a, b, a, b, tail, 0);

    if (pRequest->unk10b1 != 0)
    {
        int tail2 = *(int*)(self + 0x1e34);
        RegisterAgentType(self + 0x5a0, *(int*)(self + 0x190), a, b, a, b, tail2, 0);
    }

    ++*(int*)(self + 0x190);
}

// Source record copied by value: 0x40 bytes, flags at +0x30..+0x33.
struct SrcRec
{
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
    unsigned char b30;
    unsigned char b31;
    unsigned char b32;
    unsigned char b33;
    int unk34;
    int unk38;
    int unk3C;
};

// 0x50-byte table entry: source record plus a tag dword at +0x40.
struct Ent
{
    SrcRec src;
    int u40;
    int u44;
    int u48;
    int u4C;
};

struct FUN_00cfbd60_cls
{
    void RegisterAgentType(void* p, int i, int a, int b, int c, int d, int e, int f);
    int AddEntry(SrcRec* a1, int a2, int a3);
};

// @fnv 0x00cfbd60
int FUN_00cfbd60_cls::AddEntry(SrcRec* pSrc, int a2, int a3)
{
    __declspec(align(16)) Ent e;
    *((unsigned char*)this + 0x1e21) = 1;
    e.src = *pSrc;
    e.u40 = 0;
    if (a2 != a3 && pSrc->b31 == 0)
    {
        e.u40 = 2;
        ((Ent*)((char*)this + 0x16b0))[(*(int*)((char*)this + 0xea0))] = e;
        RegisterAgentType(((char*)this + 0xeb0), (*(int*)((char*)this + 0xea0)), a3, a2, a3, a2,
                          (*(int*)((char*)this + 0x1e38)), 0);
        if (e.src.b30 != 0)
        {
            RegisterAgentType(((char*)this + 0x12b0), (*(int*)((char*)this + 0xea0)), a3, a2, a3, a2,
                              (*(int*)((char*)this + 0x1e3c)), 0);
        }
        (*(int*)((char*)this + 0xea0))++;
        e.u40 = 1;
    }
    int idx;
    if (pSrc->b32 == 0)
    {
        idx = (*(int*)((char*)this + 0xea0));
        (*(int*)((char*)this + 0xea0)) = idx + 1;
        ((Ent*)((char*)this + 0x16b0))[idx] = e;
    }
    else
    {
        idx = (*(int*)((char*)this + 0xea0)) - 1;
    }
    RegisterAgentType(((char*)this + 0xeb0), idx, a2, a3, a2, a3, (*(int*)((char*)this + 0x1e38)), 0);
    if (e.src.b30 != 0)
    {
        RegisterAgentType(((char*)this + 0x12b0), idx, a2, a3, a2, a3, (*(int*)((char*)this + 0x1e3c)), 0);
    }
    return idx;
}

int __cdecl hkStatisticsCollector_getAllocatedSize(const void* p, int numBytes);

struct CFBED0ShapeInheritance
{
    int m_vFrom;
    int m_vTo;
};



struct CFBED0Object;

struct CFBED0StatisticsCollector
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void addChildObject(const char* fieldName, const CFBED0Object* object, int flags);
    virtual void vfunc10();
    virtual void AddMemoryChunk(int type, const char* fieldName, const void* chunk, int usedSize, int allocatedSize);

    int unk04;
    int unk08;
    int unk0C;
    bool m_countDontDeallocate;

    void addArray(const char* fieldName, const hkArrayBase<CFBED0ShapeInheritance>& array)
    {
        if ((array.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate)
        {
            int allocated = hkStatisticsCollector_getAllocatedSize(array.m_data, array.getCapacity() * sizeof(CFBED0ShapeInheritance));
            AddMemoryChunk(3, fieldName, array.m_data, array.m_iElementCount * sizeof(CFBED0ShapeInheritance), allocated);
        }
    }
};

// Retained: the shared dispatcher places the factory grid at 0x08 instead of 0x0C.
struct CFBED0Dispatcher
{
    int unk0000;
    int unk0004;
    int unk0008;
    CFBED0Object* m_apContactMgrFactoriesByResponsePair[8][8];
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    int unk04F0;
    int unk04F4;
    int unk04F8;
    int unk04FC;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050C;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052C;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053C;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054C;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055C;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056C;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057C;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058C;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059C;
    int unk05A0;
    int unk05A4;
    int unk05A8;
    int unk05AC;
    int unk05B0;
    int unk05B4;
    int unk05B8;
    int unk05BC;
    int unk05C0;
    int unk05C4;
    int unk05C8;
    int unk05CC;
    int unk05D0;
    int unk05D4;
    int unk05D8;
    int unk05DC;
    int unk05E0;
    int unk05E4;
    int unk05E8;
    int unk05EC;
    int unk05F0;
    int unk05F4;
    int unk05F8;
    int unk05FC;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060C;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061C;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062C;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063C;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064C;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065C;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066C;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067C;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068C;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069C;
    int unk06A0;
    int unk06A4;
    int unk06A8;
    int unk06AC;
    int unk06B0;
    int unk06B4;
    int unk06B8;
    int unk06BC;
    int unk06C0;
    int unk06C4;
    int unk06C8;
    int unk06CC;
    int unk06D0;
    int unk06D4;
    int unk06D8;
    int unk06DC;
    int unk06E0;
    int unk06E4;
    int unk06E8;
    int unk06EC;
    int unk06F0;
    int unk06F4;
    int unk06F8;
    int unk06FC;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070C;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071C;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072C;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073C;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074C;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075C;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076C;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077C;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078C;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079C;
    int unk07A0;
    int unk07A4;
    int unk07A8;
    int unk07AC;
    int unk07B0;
    int unk07B4;
    int unk07B8;
    int unk07BC;
    int unk07C0;
    int unk07C4;
    int unk07C8;
    int unk07CC;
    int unk07D0;
    int unk07D4;
    int unk07D8;
    int unk07DC;
    int unk07E0;
    int unk07E4;
    int unk07E8;
    int unk07EC;
    int unk07F0;
    int unk07F4;
    int unk07F8;
    int unk07FC;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080C;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081C;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082C;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083C;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084C;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085C;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086C;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087C;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088C;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089C;
    int unk08A0;
    int unk08A4;
    int unk08A8;
    int unk08AC;
    int unk08B0;
    int unk08B4;
    int unk08B8;
    int unk08BC;
    int unk08C0;
    int unk08C4;
    int unk08C8;
    int unk08CC;
    int unk08D0;
    int unk08D4;
    int unk08D8;
    int unk08DC;
    int unk08E0;
    int unk08E4;
    int unk08E8;
    int unk08EC;
    int unk08F0;
    int unk08F4;
    int unk08F8;
    int unk08FC;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090C;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091C;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092C;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093C;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094C;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095C;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096C;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097C;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098C;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099C;
    int unk09A0;
    int unk09A4;
    int unk09A8;
    int unk09AC;
    int unk09B0;
    int unk09B4;
    int unk09B8;
    int unk09BC;
    int unk09C0;
    int unk09C4;
    int unk09C8;
    int unk09CC;
    int unk09D0;
    int unk09D4;
    int unk09D8;
    int unk09DC;
    int unk09E0;
    int unk09E4;
    int unk09E8;
    int unk09EC;
    int unk09F0;
    int unk09F4;
    int unk09F8;
    int unk09FC;
    int unk0A00;
    int unk0A04;
    int unk0A08;
    int unk0A0C;
    int unk0A10;
    int unk0A14;
    int unk0A18;
    int unk0A1C;
    int unk0A20;
    int unk0A24;
    int unk0A28;
    int unk0A2C;
    int unk0A30;
    int unk0A34;
    int unk0A38;
    int unk0A3C;
    int unk0A40;
    int unk0A44;
    int unk0A48;
    int unk0A4C;
    int unk0A50;
    int unk0A54;
    int unk0A58;
    int unk0A5C;
    int unk0A60;
    int unk0A64;
    int unk0A68;
    int unk0A6C;
    int unk0A70;
    int unk0A74;
    int unk0A78;
    int unk0A7C;
    int unk0A80;
    int unk0A84;
    int unk0A88;
    int unk0A8C;
    int unk0A90;
    int unk0A94;
    int unk0A98;
    int unk0A9C;
    int unk0AA0;
    int unk0AA4;
    int unk0AA8;
    int unk0AAC;
    int unk0AB0;
    int unk0AB4;
    int unk0AB8;
    int unk0ABC;
    int unk0AC0;
    int unk0AC4;
    int unk0AC8;
    int unk0ACC;
    int unk0AD0;
    int unk0AD4;
    int unk0AD8;
    int unk0ADC;
    int unk0AE0;
    int unk0AE4;
    int unk0AE8;
    int unk0AEC;
    int unk0AF0;
    int unk0AF4;
    int unk0AF8;
    int unk0AFC;
    int unk0B00;
    int unk0B04;
    int unk0B08;
    int unk0B0C;
    int unk0B10;
    int unk0B14;
    int unk0B18;
    int unk0B1C;
    int unk0B20;
    int unk0B24;
    int unk0B28;
    int unk0B2C;
    int unk0B30;
    int unk0B34;
    int unk0B38;
    int unk0B3C;
    int unk0B40;
    int unk0B44;
    int unk0B48;
    int unk0B4C;
    int unk0B50;
    int unk0B54;
    int unk0B58;
    int unk0B5C;
    int unk0B60;
    int unk0B64;
    int unk0B68;
    int unk0B6C;
    int unk0B70;
    int unk0B74;
    int unk0B78;
    int unk0B7C;
    int unk0B80;
    int unk0B84;
    int unk0B88;
    int unk0B8C;
    int unk0B90;
    int unk0B94;
    int unk0B98;
    int unk0B9C;
    int unk0BA0;
    int unk0BA4;
    int unk0BA8;
    int unk0BAC;
    int unk0BB0;
    int unk0BB4;
    int unk0BB8;
    int unk0BBC;
    int unk0BC0;
    int unk0BC4;
    int unk0BC8;
    int unk0BCC;
    int unk0BD0;
    int unk0BD4;
    int unk0BD8;
    int unk0BDC;
    int unk0BE0;
    int unk0BE4;
    int unk0BE8;
    int unk0BEC;
    int unk0BF0;
    int unk0BF4;
    int unk0BF8;
    int unk0BFC;
    int unk0C00;
    int unk0C04;
    int unk0C08;
    int unk0C0C;
    int unk0C10;
    int unk0C14;
    int unk0C18;
    int unk0C1C;
    int unk0C20;
    int unk0C24;
    int unk0C28;
    int unk0C2C;
    int unk0C30;
    int unk0C34;
    int unk0C38;
    int unk0C3C;
    int unk0C40;
    int unk0C44;
    int unk0C48;
    int unk0C4C;
    int unk0C50;
    int unk0C54;
    int unk0C58;
    int unk0C5C;
    int unk0C60;
    int unk0C64;
    int unk0C68;
    int unk0C6C;
    int unk0C70;
    int unk0C74;
    int unk0C78;
    int unk0C7C;
    int unk0C80;
    int unk0C84;
    int unk0C88;
    int unk0C8C;
    int unk0C90;
    int unk0C94;
    int unk0C98;
    int unk0C9C;
    int unk0CA0;
    int unk0CA4;
    int unk0CA8;
    int unk0CAC;
    int unk0CB0;
    int unk0CB4;
    int unk0CB8;
    int unk0CBC;
    int unk0CC0;
    int unk0CC4;
    int unk0CC8;
    int unk0CCC;
    int unk0CD0;
    int unk0CD4;
    int unk0CD8;
    int unk0CDC;
    int unk0CE0;
    int unk0CE4;
    int unk0CE8;
    int unk0CEC;
    int unk0CF0;
    int unk0CF4;
    int unk0CF8;
    int unk0CFC;
    int unk0D00;
    int unk0D04;
    int unk0D08;
    int unk0D0C;
    int unk0D10;
    int unk0D14;
    int unk0D18;
    int unk0D1C;
    int unk0D20;
    int unk0D24;
    int unk0D28;
    int unk0D2C;
    int unk0D30;
    int unk0D34;
    int unk0D38;
    int unk0D3C;
    int unk0D40;
    int unk0D44;
    int unk0D48;
    int unk0D4C;
    int unk0D50;
    int unk0D54;
    int unk0D58;
    int unk0D5C;
    int unk0D60;
    int unk0D64;
    int unk0D68;
    int unk0D6C;
    int unk0D70;
    int unk0D74;
    int unk0D78;
    int unk0D7C;
    int unk0D80;
    int unk0D84;
    int unk0D88;
    int unk0D8C;
    int unk0D90;
    int unk0D94;
    int unk0D98;
    int unk0D9C;
    int unk0DA0;
    int unk0DA4;
    int unk0DA8;
    int unk0DAC;
    int unk0DB0;
    int unk0DB4;
    int unk0DB8;
    int unk0DBC;
    int unk0DC0;
    int unk0DC4;
    int unk0DC8;
    int unk0DCC;
    int unk0DD0;
    int unk0DD4;
    int unk0DD8;
    int unk0DDC;
    int unk0DE0;
    int unk0DE4;
    int unk0DE8;
    int unk0DEC;
    int unk0DF0;
    int unk0DF4;
    int unk0DF8;
    int unk0DFC;
    int unk0E00;
    int unk0E04;
    int unk0E08;
    int unk0E0C;
    int unk0E10;
    int unk0E14;
    int unk0E18;
    int unk0E1C;
    int unk0E20;
    int unk0E24;
    int unk0E28;
    int unk0E2C;
    int unk0E30;
    int unk0E34;
    int unk0E38;
    int unk0E3C;
    int unk0E40;
    int unk0E44;
    int unk0E48;
    int unk0E4C;
    int unk0E50;
    int unk0E54;
    int unk0E58;
    int unk0E5C;
    int unk0E60;
    int unk0E64;
    int unk0E68;
    int unk0E6C;
    int unk0E70;
    int unk0E74;
    int unk0E78;
    int unk0E7C;
    int unk0E80;
    int unk0E84;
    int unk0E88;
    int unk0E8C;
    int unk0E90;
    int unk0E94;
    int unk0E98;
    int unk0E9C;
    int unk0EA0;
    int unk0EA4;
    int unk0EA8;
    int unk0EAC;
    int unk0EB0;
    int unk0EB4;
    int unk0EB8;
    int unk0EBC;
    int unk0EC0;
    int unk0EC4;
    int unk0EC8;
    int unk0ECC;
    int unk0ED0;
    int unk0ED4;
    int unk0ED8;
    int unk0EDC;
    int unk0EE0;
    int unk0EE4;
    int unk0EE8;
    int unk0EEC;
    int unk0EF0;
    int unk0EF4;
    int unk0EF8;
    int unk0EFC;
    int unk0F00;
    int unk0F04;
    int unk0F08;
    int unk0F0C;
    int unk0F10;
    int unk0F14;
    int unk0F18;
    int unk0F1C;
    int unk0F20;
    int unk0F24;
    int unk0F28;
    int unk0F2C;
    int unk0F30;
    int unk0F34;
    int unk0F38;
    int unk0F3C;
    int unk0F40;
    int unk0F44;
    int unk0F48;
    int unk0F4C;
    int unk0F50;
    int unk0F54;
    int unk0F58;
    int unk0F5C;
    int unk0F60;
    int unk0F64;
    int unk0F68;
    int unk0F6C;
    int unk0F70;
    int unk0F74;
    int unk0F78;
    int unk0F7C;
    int unk0F80;
    int unk0F84;
    int unk0F88;
    int unk0F8C;
    int unk0F90;
    int unk0F94;
    int unk0F98;
    int unk0F9C;
    int unk0FA0;
    int unk0FA4;
    int unk0FA8;
    int unk0FAC;
    int unk0FB0;
    int unk0FB4;
    int unk0FB8;
    int unk0FBC;
    int unk0FC0;
    int unk0FC4;
    int unk0FC8;
    int unk0FCC;
    int unk0FD0;
    int unk0FD4;
    int unk0FD8;
    int unk0FDC;
    int unk0FE0;
    int unk0FE4;
    int unk0FE8;
    int unk0FEC;
    int unk0FF0;
    int unk0FF4;
    int unk0FF8;
    int unk0FFC;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100C;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101C;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102C;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103C;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104C;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105C;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106C;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107C;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108C;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109C;
    int unk10A0;
    int unk10A4;
    int unk10A8;
    int unk10AC;
    int unk10B0;
    int unk10B4;
    int unk10B8;
    int unk10BC;
    int unk10C0;
    int unk10C4;
    int unk10C8;
    int unk10CC;
    int unk10D0;
    int unk10D4;
    int unk10D8;
    int unk10DC;
    int unk10E0;
    int unk10E4;
    int unk10E8;
    int unk10EC;
    int unk10F0;
    int unk10F4;
    int unk10F8;
    int unk10FC;
    int unk1100;
    int unk1104;
    int unk1108;
    int unk110C;
    int unk1110;
    int unk1114;
    int unk1118;
    int unk111C;
    int unk1120;
    int unk1124;
    int unk1128;
    int unk112C;
    int unk1130;
    int unk1134;
    int unk1138;
    int unk113C;
    int unk1140;
    int unk1144;
    int unk1148;
    int unk114C;
    int unk1150;
    int unk1154;
    int unk1158;
    int unk115C;
    int unk1160;
    int unk1164;
    int unk1168;
    int unk116C;
    int unk1170;
    int unk1174;
    int unk1178;
    int unk117C;
    int unk1180;
    int unk1184;
    int unk1188;
    int unk118C;
    int unk1190;
    int unk1194;
    int unk1198;
    int unk119C;
    int unk11A0;
    int unk11A4;
    int unk11A8;
    int unk11AC;
    int unk11B0;
    int unk11B4;
    int unk11B8;
    int unk11BC;
    int unk11C0;
    int unk11C4;
    int unk11C8;
    int unk11CC;
    int unk11D0;
    int unk11D4;
    int unk11D8;
    int unk11DC;
    int unk11E0;
    int unk11E4;
    int unk11E8;
    int unk11EC;
    int unk11F0;
    int unk11F4;
    int unk11F8;
    int unk11FC;
    int unk1200;
    int unk1204;
    int unk1208;
    int unk120C;
    int unk1210;
    int unk1214;
    int unk1218;
    int unk121C;
    int unk1220;
    int unk1224;
    int unk1228;
    int unk122C;
    int unk1230;
    int unk1234;
    int unk1238;
    int unk123C;
    int unk1240;
    int unk1244;
    int unk1248;
    int unk124C;
    int unk1250;
    int unk1254;
    int unk1258;
    int unk125C;
    int unk1260;
    int unk1264;
    int unk1268;
    int unk126C;
    int unk1270;
    int unk1274;
    int unk1278;
    int unk127C;
    int unk1280;
    int unk1284;
    int unk1288;
    int unk128C;
    int unk1290;
    int unk1294;
    int unk1298;
    int unk129C;
    int unk12A0;
    int unk12A4;
    int unk12A8;
    int unk12AC;
    int unk12B0;
    int unk12B4;
    int unk12B8;
    int unk12BC;
    int unk12C0;
    int unk12C4;
    int unk12C8;
    int unk12CC;
    int unk12D0;
    int unk12D4;
    int unk12D8;
    int unk12DC;
    int unk12E0;
    int unk12E4;
    int unk12E8;
    int unk12EC;
    int unk12F0;
    int unk12F4;
    int unk12F8;
    int unk12FC;
    int unk1300;
    int unk1304;
    int unk1308;
    int unk130C;
    int unk1310;
    int unk1314;
    int unk1318;
    int unk131C;
    int unk1320;
    int unk1324;
    int unk1328;
    int unk132C;
    int unk1330;
    int unk1334;
    int unk1338;
    int unk133C;
    int unk1340;
    int unk1344;
    int unk1348;
    int unk134C;
    int unk1350;
    int unk1354;
    int unk1358;
    int unk135C;
    int unk1360;
    int unk1364;
    int unk1368;
    int unk136C;
    int unk1370;
    int unk1374;
    int unk1378;
    int unk137C;
    int unk1380;
    int unk1384;
    int unk1388;
    int unk138C;
    int unk1390;
    int unk1394;
    int unk1398;
    int unk139C;
    int unk13A0;
    int unk13A4;
    int unk13A8;
    int unk13AC;
    int unk13B0;
    int unk13B4;
    int unk13B8;
    int unk13BC;
    int unk13C0;
    int unk13C4;
    int unk13C8;
    int unk13CC;
    int unk13D0;
    int unk13D4;
    int unk13D8;
    int unk13DC;
    int unk13E0;
    int unk13E4;
    int unk13E8;
    int unk13EC;
    int unk13F0;
    int unk13F4;
    int unk13F8;
    int unk13FC;
    int unk1400;
    int unk1404;
    int unk1408;
    int unk140C;
    int unk1410;
    int unk1414;
    int unk1418;
    int unk141C;
    int unk1420;
    int unk1424;
    int unk1428;
    int unk142C;
    int unk1430;
    int unk1434;
    int unk1438;
    int unk143C;
    int unk1440;
    int unk1444;
    int unk1448;
    int unk144C;
    int unk1450;
    int unk1454;
    int unk1458;
    int unk145C;
    int unk1460;
    int unk1464;
    int unk1468;
    int unk146C;
    int unk1470;
    int unk1474;
    int unk1478;
    int unk147C;
    int unk1480;
    int unk1484;
    int unk1488;
    int unk148C;
    int unk1490;
    int unk1494;
    int unk1498;
    int unk149C;
    int unk14A0;
    int unk14A4;
    int unk14A8;
    int unk14AC;
    int unk14B0;
    int unk14B4;
    int unk14B8;
    int unk14BC;
    int unk14C0;
    int unk14C4;
    int unk14C8;
    int unk14CC;
    int unk14D0;
    int unk14D4;
    int unk14D8;
    int unk14DC;
    int unk14E0;
    int unk14E4;
    int unk14E8;
    int unk14EC;
    int unk14F0;
    int unk14F4;
    int unk14F8;
    int unk14FC;
    int unk1500;
    int unk1504;
    int unk1508;
    int unk150C;
    int unk1510;
    int unk1514;
    int unk1518;
    int unk151C;
    int unk1520;
    int unk1524;
    int unk1528;
    int unk152C;
    int unk1530;
    int unk1534;
    int unk1538;
    int unk153C;
    int unk1540;
    int unk1544;
    int unk1548;
    int unk154C;
    int unk1550;
    int unk1554;
    int unk1558;
    int unk155C;
    int unk1560;
    int unk1564;
    int unk1568;
    int unk156C;
    int unk1570;
    int unk1574;
    int unk1578;
    int unk157C;
    int unk1580;
    int unk1584;
    int unk1588;
    int unk158C;
    int unk1590;
    int unk1594;
    int unk1598;
    int unk159C;
    int unk15A0;
    int unk15A4;
    int unk15A8;
    int unk15AC;
    int unk15B0;
    int unk15B4;
    int unk15B8;
    int unk15BC;
    int unk15C0;
    int unk15C4;
    int unk15C8;
    int unk15CC;
    int unk15D0;
    int unk15D4;
    int unk15D8;
    int unk15DC;
    int unk15E0;
    int unk15E4;
    int unk15E8;
    int unk15EC;
    int unk15F0;
    int unk15F4;
    int unk15F8;
    int unk15FC;
    int unk1600;
    int unk1604;
    int unk1608;
    int unk160C;
    int unk1610;
    int unk1614;
    int unk1618;
    int unk161C;
    int unk1620;
    int unk1624;
    int unk1628;
    int unk162C;
    int unk1630;
    int unk1634;
    int unk1638;
    int unk163C;
    int unk1640;
    int unk1644;
    int unk1648;
    int unk164C;
    int unk1650;
    int unk1654;
    int unk1658;
    int unk165C;
    int unk1660;
    int unk1664;
    int unk1668;
    int unk166C;
    int unk1670;
    int unk1674;
    int unk1678;
    int unk167C;
    int unk1680;
    int unk1684;
    int unk1688;
    int unk168C;
    int unk1690;
    int unk1694;
    int unk1698;
    int unk169C;
    int unk16A0;
    int unk16A4;
    int unk16A8;
    int unk16AC;
    int unk16B0;
    int unk16B4;
    int unk16B8;
    int unk16BC;
    int unk16C0;
    int unk16C4;
    int unk16C8;
    int unk16CC;
    int unk16D0;
    int unk16D4;
    int unk16D8;
    int unk16DC;
    int unk16E0;
    int unk16E4;
    int unk16E8;
    int unk16EC;
    int unk16F0;
    int unk16F4;
    int unk16F8;
    int unk16FC;
    int unk1700;
    int unk1704;
    int unk1708;
    int unk170C;
    int unk1710;
    int unk1714;
    int unk1718;
    int unk171C;
    int unk1720;
    int unk1724;
    int unk1728;
    int unk172C;
    int unk1730;
    int unk1734;
    int unk1738;
    int unk173C;
    int unk1740;
    int unk1744;
    int unk1748;
    int unk174C;
    int unk1750;
    int unk1754;
    int unk1758;
    int unk175C;
    int unk1760;
    int unk1764;
    int unk1768;
    int unk176C;
    int unk1770;
    int unk1774;
    int unk1778;
    int unk177C;
    int unk1780;
    int unk1784;
    int unk1788;
    int unk178C;
    int unk1790;
    int unk1794;
    int unk1798;
    int unk179C;
    int unk17A0;
    int unk17A4;
    int unk17A8;
    int unk17AC;
    int unk17B0;
    int unk17B4;
    int unk17B8;
    int unk17BC;
    int unk17C0;
    int unk17C4;
    int unk17C8;
    int unk17CC;
    int unk17D0;
    int unk17D4;
    int unk17D8;
    int unk17DC;
    int unk17E0;
    int unk17E4;
    int unk17E8;
    int unk17EC;
    int unk17F0;
    int unk17F4;
    int unk17F8;
    int unk17FC;
    int unk1800;
    int unk1804;
    int unk1808;
    int unk180C;
    int unk1810;
    int unk1814;
    int unk1818;
    int unk181C;
    int unk1820;
    int unk1824;
    int unk1828;
    int unk182C;
    int unk1830;
    int unk1834;
    int unk1838;
    int unk183C;
    int unk1840;
    int unk1844;
    int unk1848;
    int unk184C;
    int unk1850;
    int unk1854;
    int unk1858;
    int unk185C;
    int unk1860;
    int unk1864;
    int unk1868;
    int unk186C;
    int unk1870;
    int unk1874;
    int unk1878;
    int unk187C;
    int unk1880;
    int unk1884;
    int unk1888;
    int unk188C;
    int unk1890;
    int unk1894;
    int unk1898;
    int unk189C;
    int unk18A0;
    int unk18A4;
    int unk18A8;
    int unk18AC;
    int unk18B0;
    int unk18B4;
    int unk18B8;
    int unk18BC;
    int unk18C0;
    int unk18C4;
    int unk18C8;
    int unk18CC;
    int unk18D0;
    int unk18D4;
    int unk18D8;
    int unk18DC;
    int unk18E0;
    int unk18E4;
    int unk18E8;
    int unk18EC;
    int unk18F0;
    int unk18F4;
    int unk18F8;
    int unk18FC;
    int unk1900;
    int unk1904;
    int unk1908;
    int unk190C;
    int unk1910;
    int unk1914;
    int unk1918;
    int unk191C;
    int unk1920;
    int unk1924;
    int unk1928;
    int unk192C;
    int unk1930;
    int unk1934;
    int unk1938;
    int unk193C;
    int unk1940;
    int unk1944;
    int unk1948;
    int unk194C;
    int unk1950;
    int unk1954;
    int unk1958;
    int unk195C;
    int unk1960;
    int unk1964;
    int unk1968;
    int unk196C;
    int unk1970;
    int unk1974;
    int unk1978;
    int unk197C;
    int unk1980;
    int unk1984;
    int unk1988;
    int unk198C;
    int unk1990;
    int unk1994;
    int unk1998;
    int unk199C;
    int unk19A0;
    int unk19A4;
    int unk19A8;
    int unk19AC;
    int unk19B0;
    int unk19B4;
    int unk19B8;
    int unk19BC;
    int unk19C0;
    int unk19C4;
    int unk19C8;
    int unk19CC;
    int unk19D0;
    int unk19D4;
    int unk19D8;
    int unk19DC;
    int unk19E0;
    int unk19E4;
    int unk19E8;
    int unk19EC;
    int unk19F0;
    int unk19F4;
    int unk19F8;
    int unk19FC;
    int unk1A00;
    int unk1A04;
    int unk1A08;
    int unk1A0C;
    int unk1A10;
    int unk1A14;
    int unk1A18;
    int unk1A1C;
    int unk1A20;
    int unk1A24;
    int unk1A28;
    int unk1A2C;
    int unk1A30;
    int unk1A34;
    int unk1A38;
    int unk1A3C;
    int unk1A40;
    int unk1A44;
    int unk1A48;
    int unk1A4C;
    int unk1A50;
    int unk1A54;
    int unk1A58;
    int unk1A5C;
    int unk1A60;
    int unk1A64;
    int unk1A68;
    int unk1A6C;
    int unk1A70;
    int unk1A74;
    int unk1A78;
    int unk1A7C;
    int unk1A80;
    int unk1A84;
    int unk1A88;
    int unk1A8C;
    int unk1A90;
    int unk1A94;
    int unk1A98;
    int unk1A9C;
    int unk1AA0;
    int unk1AA4;
    int unk1AA8;
    int unk1AAC;
    int unk1AB0;
    int unk1AB4;
    int unk1AB8;
    int unk1ABC;
    int unk1AC0;
    int unk1AC4;
    int unk1AC8;
    int unk1ACC;
    int unk1AD0;
    int unk1AD4;
    int unk1AD8;
    int unk1ADC;
    int unk1AE0;
    int unk1AE4;
    int unk1AE8;
    int unk1AEC;
    int unk1AF0;
    int unk1AF4;
    int unk1AF8;
    int unk1AFC;
    int unk1B00;
    int unk1B04;
    int unk1B08;
    int unk1B0C;
    int unk1B10;
    int unk1B14;
    int unk1B18;
    int unk1B1C;
    int unk1B20;
    int unk1B24;
    int unk1B28;
    int unk1B2C;
    int unk1B30;
    int unk1B34;
    int unk1B38;
    int unk1B3C;
    int unk1B40;
    int unk1B44;
    int unk1B48;
    int unk1B4C;
    int unk1B50;
    int unk1B54;
    int unk1B58;
    int unk1B5C;
    int unk1B60;
    int unk1B64;
    int unk1B68;
    int unk1B6C;
    int unk1B70;
    int unk1B74;
    int unk1B78;
    int unk1B7C;
    int unk1B80;
    int unk1B84;
    int unk1B88;
    int unk1B8C;
    int unk1B90;
    int unk1B94;
    int unk1B98;
    int unk1B9C;
    int unk1BA0;
    int unk1BA4;
    int unk1BA8;
    int unk1BAC;
    int unk1BB0;
    int unk1BB4;
    int unk1BB8;
    int unk1BBC;
    int unk1BC0;
    int unk1BC4;
    int unk1BC8;
    int unk1BCC;
    int unk1BD0;
    int unk1BD4;
    int unk1BD8;
    int unk1BDC;
    int unk1BE0;
    int unk1BE4;
    int unk1BE8;
    int unk1BEC;
    int unk1BF0;
    int unk1BF4;
    int unk1BF8;
    int unk1BFC;
    int unk1C00;
    int unk1C04;
    int unk1C08;
    int unk1C0C;
    int unk1C10;
    int unk1C14;
    int unk1C18;
    int unk1C1C;
    int unk1C20;
    int unk1C24;
    int unk1C28;
    int unk1C2C;
    int unk1C30;
    int unk1C34;
    int unk1C38;
    int unk1C3C;
    int unk1C40;
    int unk1C44;
    int unk1C48;
    int unk1C4C;
    int unk1C50;
    int unk1C54;
    int unk1C58;
    int unk1C5C;
    int unk1C60;
    int unk1C64;
    int unk1C68;
    int unk1C6C;
    int unk1C70;
    int unk1C74;
    int unk1C78;
    int unk1C7C;
    int unk1C80;
    int unk1C84;
    int unk1C88;
    int unk1C8C;
    int unk1C90;
    int unk1C94;
    int unk1C98;
    int unk1C9C;
    int unk1CA0;
    int unk1CA4;
    int unk1CA8;
    int unk1CAC;
    int unk1CB0;
    int unk1CB4;
    int unk1CB8;
    int unk1CBC;
    int unk1CC0;
    int unk1CC4;
    int unk1CC8;
    int unk1CCC;
    int unk1CD0;
    int unk1CD4;
    int unk1CD8;
    int unk1CDC;
    int unk1CE0;
    int unk1CE4;
    int unk1CE8;
    int unk1CEC;
    int unk1CF0;
    int unk1CF4;
    int unk1CF8;
    int unk1CFC;
    int unk1D00;
    int unk1D04;
    int unk1D08;
    int unk1D0C;
    int unk1D10;
    int unk1D14;
    int unk1D18;
    int unk1D1C;
    int unk1D20;
    int unk1D24;
    int unk1D28;
    int unk1D2C;
    int unk1D30;
    int unk1D34;
    int unk1D38;
    int unk1D3C;
    int unk1D40;
    int unk1D44;
    int unk1D48;
    int unk1D4C;
    int unk1D50;
    int unk1D54;
    int unk1D58;
    int unk1D5C;
    int unk1D60;
    int unk1D64;
    int unk1D68;
    int unk1D6C;
    int unk1D70;
    int unk1D74;
    int unk1D78;
    int unk1D7C;
    int unk1D80;
    int unk1D84;
    int unk1D88;
    int unk1D8C;
    int unk1D90;
    int unk1D94;
    int unk1D98;
    int unk1D9C;
    int unk1DA0;
    int unk1DA4;
    int unk1DA8;
    int unk1DAC;
    int unk1DB0;
    int unk1DB4;
    int unk1DB8;
    int unk1DBC;
    int unk1DC0;
    int unk1DC4;
    int unk1DC8;
    int unk1DCC;
    int unk1DD0;
    int unk1DD4;
    int unk1DD8;
    int unk1DDC;
    int unk1DE0;
    int unk1DE4;
    int unk1DE8;
    int unk1DEC;
    int unk1DF0;
    int unk1DF4;
    int unk1DF8;
    int unk1DFC;
    int unk1E00;
    int unk1E04;
    int unk1E08;
    int unk1E0C;
    int unk1E10;
    int unk1E14;
    int unk1E18;
    int unk1E1C;
    int unk1E20;
    hkArrayBase<CFBED0ShapeInheritance> m_pShapeInheritance;

    void CollectStatistics(CFBED0StatisticsCollector* collector, const void* cls) const;
};

// Adds the shapeInheritanceArray and all 8x8 contactMgrFactory child objects to the statistics collector.
// @fnv 0x00cfbed0
void CFBED0Dispatcher::CollectStatistics(CFBED0StatisticsCollector* collector, const void* cls) const
{
    collector->addArray("shapeInheritanceArray", m_pShapeInheritance);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            collector->addChildObject("contactMgrFactory", m_apContactMgrFactoriesByResponsePair[i][j], 0);
    }
}

struct CFBF60Allocator;

struct CFBF60MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CFBF60Allocator* m_pStreamAllocator;

    CFBF60Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" CFBF60MemoryRouter& __cdecl CFBF60GetMemoryRouter();
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);

struct CFBF60ShapeInheritance
{
    int m_iSecond;
    int m_iFirst;
};

static __forceinline void CFBF60InheritanceArray_removeAtAndCopy(hkArrayBase<CFBF60ShapeInheritance>& self, int index);

static __forceinline CFBF60ShapeInheritance& CFBF60InheritanceArray_AllocatePair(hkArrayBase<CFBF60ShapeInheritance>& self);

static __forceinline void CFBF60InheritanceArray_removeAtAndCopy(hkArrayBase<CFBF60ShapeInheritance>& self, int index)
{
        self.m_iElementCount--;
        int nbytes = (self.m_iElementCount - index) * sizeof(CFBF60ShapeInheritance);
        char* dst = (char*)&self.m_data[index];
        const char* src = (const char*)&self.m_data[index + 1];
        for (int k = 0; k < nbytes; k += 4)
            *(int*)(dst + k) = *(const int*)(src + k);
    }

static __forceinline CFBF60ShapeInheritance& CFBF60InheritanceArray_AllocatePair(hkArrayBase<CFBF60ShapeInheritance>& self)
{
        CFBF60Allocator& alloc = CFBF60GetMemoryRouter().heap();
        if (self.m_iElementCount == self.getCapacity())
            ResizeAudioStream(&alloc, (&self), sizeof(CFBF60ShapeInheritance));
        return self.m_data[self.m_iElementCount++];
    }

// Removes all entries matching primaryType/alternateType from the inheritance array, then updates inheritance and appends a new entry for the pair.
// @fnv 0x00cfbf60
// src: HAVOK_LIB 0x00cfbf60
void hkpCollisionDispatcher::registerAlternateShapeType(int primaryType, int alternateType)
{
    for (int i = 0; i < reinterpret_cast<hkArrayBase<CFBF60ShapeInheritance>*>(&m_pShapeInheritance)->m_iElementCount; i++)
    {
        const CFBF60ShapeInheritance& si = reinterpret_cast<hkArrayBase<CFBF60ShapeInheritance>*>(&m_pShapeInheritance)->m_data[i];
        if (si.m_iSecond == primaryType && si.m_iFirst == alternateType)
        {
            CFBF60InheritanceArray_removeAtAndCopy(*reinterpret_cast<hkArrayBase<CFBF60ShapeInheritance>*>(&m_pShapeInheritance), i);
            i--;
        }
    }
    updateShapeInheritance(primaryType, alternateType, false);
    CFBF60ShapeInheritance& si = CFBF60InheritanceArray_AllocatePair(*reinterpret_cast<hkArrayBase<CFBF60ShapeInheritance>*>(&m_pShapeInheritance));
    si.m_iFirst = alternateType;
    si.m_iSecond = primaryType;
}

extern "C" int DAT_010cc7c0;
extern "C" int DAT_0102e388;
struct CleanupAllocator
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Free(void*, unsigned);
};
struct Holder
{
    unsigned unk00, unk04, unk08, unk0c;
    CleanupAllocator* allocator;
};
Holder* _FUN_00c85750();
struct CleanupBuffer
{
    void* data;
    int count;
    unsigned capacityFlags;
};
struct Cleanup
{
    void Destroy();
};
// Resets the vtable, releases the 8x8 grid references, frees the buffer through the allocator, and sets the final vtable.
// @fnv 0x00cfc140
void Cleanup::Destroy()
{
    *reinterpret_cast<int**>(this) = &DAT_010cc7c0;
    reinterpret_cast<Owner*>(this)->FreeBuffers();
    hkReferencedObject*(*grid)[8] = reinterpret_cast<hkReferencedObject*(*)[8]>(reinterpret_cast<char*>(this) + 0xc);
    for (int r = 0; r < 8; ++r)
        for (int c = 0; c < 8; ++c)
        {
            if (grid[r][c])
                grid[r][c]->removeReference();
        }
    CleanupBuffer& buffer = *reinterpret_cast<CleanupBuffer*>(reinterpret_cast<char*>(this) + 0x1e24);
    Holder* audio = _FUN_00c85750();
    CleanupAllocator* allocator = audio->allocator;
    unsigned flags = buffer.capacityFlags;
    buffer.count = 0;
    if (!(flags & 0x80000000u))
        allocator->Free(buffer.data, (flags & 0x3fffffffu) * 8u);
    buffer.data = 0;
    buffer.capacityFlags = 0x80000000u;
    *reinterpret_cast<int**>(this) = &DAT_0102e388;
}

extern "C" int DAT_010cc7c0;

struct RefCounted
{
    void AddRef();
};

template <class T> static inline volatile T& At(void* base, unsigned int off)
{
    return *(volatile T*)((char*)base + off);
}

struct FUN_00cfc030_cls
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    unsigned int unk08;
    void Reset_cfb080();
    FUN_00cfc030_cls* hkpCollisionDispatcher_hkpCollisionDispatcher(unsigned int a1, unsigned int v);
};

// Initializes the object by zeroing arrays, setting up a reference-counted pointer array from v, and initializing a bit rotation sequence.
// @fnv 0x00cfc030
// src: HAVOK_LIB 0x00cfc030
FUN_00cfc030_cls* FUN_00cfc030_cls::hkpCollisionDispatcher_hkpCollisionDispatcher(unsigned int a1, unsigned int v)
{
    *(volatile unsigned short*)&unk06 = 1;

    unk08 = a1;
    unsigned int one = 1;
    int n = one + 0x3e;
    unk00 = (void*)&DAT_010cc7c0;

    char* p = (char*)this + 0x9b1;
    for (; n >= 0; --n)
    {
        p[-1] = 0;
        p[0] = 0;
        p += 0x14;
    }

    int m = 0xf;
    p = (char*)this + 0x16e1;
    for (; m >= 0; --m)
    {
        p[-1] = 0;
        p[0] = 0;
        p[1] = 0;
        At<unsigned int>(p, (unsigned int)-0x19) = 0;
        At<unsigned int>(p, (unsigned int)-0x15) = 0;
        At<unsigned int>(p, (unsigned int)-0x11) = 0;
        At<unsigned int>(p, (unsigned int)-0xd) = 0;
        At<unsigned int>(p, (unsigned int)-9) = 0;
        p += 0x50;
    }

    At<unsigned int>(this, 0x1e24) = 0;
    At<unsigned int>(this, 0x1e28) = 0;
    At<unsigned int>(this, 0x1e2c) = 0x80000000;
    At<unsigned int>(this, 0x1e30) = 0;
    At<unsigned int>(this, 0x1e34) = 0;
    At<unsigned int>(this, 0x1e38) = 0;
    At<unsigned int>(this, 0x1e3c) = 0;
    At<unsigned char>(this, 0x1e20) = 0;
    *(volatile unsigned char*)((char*)this + 0x1e23) = 1;
    At<unsigned int>(this, 0xea0) = 0;
    At<unsigned char>(this, 0x1e22) = 0;

    unsigned int* dst = (unsigned int*)((char*)this + 0xc);
    a1 = 8;
    do
    {
        int j = 8;
        do
        {
            unsigned int cur = *(volatile unsigned int*)&v;
            *dst = cur;
            if (cur != 0)
            {
                ((RefCounted*)cur)->AddRef();
            }
            ++dst;
        } while (--j != 0);
    } while (--a1 != 0);

    unsigned int bit = 1;
    unsigned int* bits = (unsigned int*)((char*)this + 0x110);
    for (int k = 0x20; k != 0; --k)
    {
        *bits++ = bit;
        bit = (bit << 1) | (bit >> 31);
    }

    Reset_cfb080();
    At<unsigned char>(this, 0x1e21) = 0;
    return this;
}

typedef void (*Callback)();

void Runtime_UpdateState_00cfb050();
void nullsub_7();
void Runtime_GetC();
void Runtime_GetD107A0RTTIAddress();
void nullsub_12();
void nullsub_11();
void nullsub_13();

struct S00cfb080_IO
{
    Callback m_pfnRead;
    Callback m_pfnWrite;
    Callback m_pfnSeek;
    Callback m_pfnClose;
    bool m_bOpen;
    bool m_bEnableState;

    void Init()
    {
        m_pfnRead = Runtime_GetD107A0RTTIAddress;
        m_pfnWrite = nullsub_12;
        m_pfnSeek = nullsub_11;
        m_pfnClose = nullsub_13;
        m_bOpen = false;
        m_bEnableState = true;
    }
};

struct S00cfb080_State
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int m_iDirtyA;  // 0x190
    int unk0194;
    int unk0198;
    int unk019C;
    unsigned char m_aucMapA[32][32];  // 0x1A0
    unsigned char m_aucMapC[32][32];  // 0x5A0
    S00cfb080_IO m_kIO;               // 0x9A0
    int unk09B4;
    int unk09B8;
    int unk09BC;
    int unk09C0;
    int unk09C4;
    int unk09C8;
    int unk09CC;
    int unk09D0;
    int unk09D4;
    int unk09D8;
    int unk09DC;
    int unk09E0;
    int unk09E4;
    int unk09E8;
    int unk09EC;
    int unk09F0;
    int unk09F4;
    int unk09F8;
    int unk09FC;
    int unk0A00;
    int unk0A04;
    int unk0A08;
    int unk0A0C;
    int unk0A10;
    int unk0A14;
    int unk0A18;
    int unk0A1C;
    int unk0A20;
    int unk0A24;
    int unk0A28;
    int unk0A2C;
    int unk0A30;
    int unk0A34;
    int unk0A38;
    int unk0A3C;
    int unk0A40;
    int unk0A44;
    int unk0A48;
    int unk0A4C;
    int unk0A50;
    int unk0A54;
    int unk0A58;
    int unk0A5C;
    int unk0A60;
    int unk0A64;
    int unk0A68;
    int unk0A6C;
    int unk0A70;
    int unk0A74;
    int unk0A78;
    int unk0A7C;
    int unk0A80;
    int unk0A84;
    int unk0A88;
    int unk0A8C;
    int unk0A90;
    int unk0A94;
    int unk0A98;
    int unk0A9C;
    int unk0AA0;
    int unk0AA4;
    int unk0AA8;
    int unk0AAC;
    int unk0AB0;
    int unk0AB4;
    int unk0AB8;
    int unk0ABC;
    int unk0AC0;
    int unk0AC4;
    int unk0AC8;
    int unk0ACC;
    int unk0AD0;
    int unk0AD4;
    int unk0AD8;
    int unk0ADC;
    int unk0AE0;
    int unk0AE4;
    int unk0AE8;
    int unk0AEC;
    int unk0AF0;
    int unk0AF4;
    int unk0AF8;
    int unk0AFC;
    int unk0B00;
    int unk0B04;
    int unk0B08;
    int unk0B0C;
    int unk0B10;
    int unk0B14;
    int unk0B18;
    int unk0B1C;
    int unk0B20;
    int unk0B24;
    int unk0B28;
    int unk0B2C;
    int unk0B30;
    int unk0B34;
    int unk0B38;
    int unk0B3C;
    int unk0B40;
    int unk0B44;
    int unk0B48;
    int unk0B4C;
    int unk0B50;
    int unk0B54;
    int unk0B58;
    int unk0B5C;
    int unk0B60;
    int unk0B64;
    int unk0B68;
    int unk0B6C;
    int unk0B70;
    int unk0B74;
    int unk0B78;
    int unk0B7C;
    int unk0B80;
    int unk0B84;
    int unk0B88;
    int unk0B8C;
    int unk0B90;
    int unk0B94;
    int unk0B98;
    int unk0B9C;
    int unk0BA0;
    int unk0BA4;
    int unk0BA8;
    int unk0BAC;
    int unk0BB0;
    int unk0BB4;
    int unk0BB8;
    int unk0BBC;
    int unk0BC0;
    int unk0BC4;
    int unk0BC8;
    int unk0BCC;
    int unk0BD0;
    int unk0BD4;
    int unk0BD8;
    int unk0BDC;
    int unk0BE0;
    int unk0BE4;
    int unk0BE8;
    int unk0BEC;
    int unk0BF0;
    int unk0BF4;
    int unk0BF8;
    int unk0BFC;
    int unk0C00;
    int unk0C04;
    int unk0C08;
    int unk0C0C;
    int unk0C10;
    int unk0C14;
    int unk0C18;
    int unk0C1C;
    int unk0C20;
    int unk0C24;
    int unk0C28;
    int unk0C2C;
    int unk0C30;
    int unk0C34;
    int unk0C38;
    int unk0C3C;
    int unk0C40;
    int unk0C44;
    int unk0C48;
    int unk0C4C;
    int unk0C50;
    int unk0C54;
    int unk0C58;
    int unk0C5C;
    int unk0C60;
    int unk0C64;
    int unk0C68;
    int unk0C6C;
    int unk0C70;
    int unk0C74;
    int unk0C78;
    int unk0C7C;
    int unk0C80;
    int unk0C84;
    int unk0C88;
    int unk0C8C;
    int unk0C90;
    int unk0C94;
    int unk0C98;
    int unk0C9C;
    int unk0CA0;
    int unk0CA4;
    int unk0CA8;
    int unk0CAC;
    int unk0CB0;
    int unk0CB4;
    int unk0CB8;
    int unk0CBC;
    int unk0CC0;
    int unk0CC4;
    int unk0CC8;
    int unk0CCC;
    int unk0CD0;
    int unk0CD4;
    int unk0CD8;
    int unk0CDC;
    int unk0CE0;
    int unk0CE4;
    int unk0CE8;
    int unk0CEC;
    int unk0CF0;
    int unk0CF4;
    int unk0CF8;
    int unk0CFC;
    int unk0D00;
    int unk0D04;
    int unk0D08;
    int unk0D0C;
    int unk0D10;
    int unk0D14;
    int unk0D18;
    int unk0D1C;
    int unk0D20;
    int unk0D24;
    int unk0D28;
    int unk0D2C;
    int unk0D30;
    int unk0D34;
    int unk0D38;
    int unk0D3C;
    int unk0D40;
    int unk0D44;
    int unk0D48;
    int unk0D4C;
    int unk0D50;
    int unk0D54;
    int unk0D58;
    int unk0D5C;
    int unk0D60;
    int unk0D64;
    int unk0D68;
    int unk0D6C;
    int unk0D70;
    int unk0D74;
    int unk0D78;
    int unk0D7C;
    int unk0D80;
    int unk0D84;
    int unk0D88;
    int unk0D8C;
    int unk0D90;
    int unk0D94;
    int unk0D98;
    int unk0D9C;
    int unk0DA0;
    int unk0DA4;
    int unk0DA8;
    int unk0DAC;
    int unk0DB0;
    int unk0DB4;
    int unk0DB8;
    int unk0DBC;
    int unk0DC0;
    int unk0DC4;
    int unk0DC8;
    int unk0DCC;
    int unk0DD0;
    int unk0DD4;
    int unk0DD8;
    int unk0DDC;
    int unk0DE0;
    int unk0DE4;
    int unk0DE8;
    int unk0DEC;
    int unk0DF0;
    int unk0DF4;
    int unk0DF8;
    int unk0DFC;
    int unk0E00;
    int unk0E04;
    int unk0E08;
    int unk0E0C;
    int unk0E10;
    int unk0E14;
    int unk0E18;
    int unk0E1C;
    int unk0E20;
    int unk0E24;
    int unk0E28;
    int unk0E2C;
    int unk0E30;
    int unk0E34;
    int unk0E38;
    int unk0E3C;
    int unk0E40;
    int unk0E44;
    int unk0E48;
    int unk0E4C;
    int unk0E50;
    int unk0E54;
    int unk0E58;
    int unk0E5C;
    int unk0E60;
    int unk0E64;
    int unk0E68;
    int unk0E6C;
    int unk0E70;
    int unk0E74;
    int unk0E78;
    int unk0E7C;
    int unk0E80;
    int unk0E84;
    int unk0E88;
    int unk0E8C;
    int unk0E90;
    int unk0E94;
    int unk0E98;
    int unk0E9C;
    int m_iDirtyB;  // 0xEA0
    int unk0EA4;
    int unk0EA8;
    int unk0EAC;
    unsigned char m_aucMapB[32][32];  // 0xEB0
    unsigned char m_aucMapD[32][32];  // 0x12B0
    Callback m_pfnAlloc;              // 0x16B0
    Callback m_pfnFree;
    int m_i16B8;
    int m_i16BC;
    int m_i16C0;
    int m_i16C4;
    int m_i16C8;
    int m_i16CC;
    int m_i16D0;
    int m_i16D4;
    int m_i16D8;
    Callback m_pfnNotify;  // 0x16DC
    int unk16E0;
    int unk16E4;
    int unk16E8;
    int unk16EC;
    int m_i16F0;
    int unk16F4;
    int unk16F8;
    int unk16FC;
    int unk1700;
    int unk1704;
    int unk1708;
    int unk170C;
    int unk1710;
    int unk1714;
    int unk1718;
    int unk171C;
    int unk1720;
    int unk1724;
    int unk1728;
    int unk172C;
    int unk1730;
    int unk1734;
    int unk1738;
    int unk173C;
    int unk1740;
    int unk1744;
    int unk1748;
    int unk174C;
    int unk1750;
    int unk1754;
    int unk1758;
    int unk175C;
    int unk1760;
    int unk1764;
    int unk1768;
    int unk176C;
    int unk1770;
    int unk1774;
    int unk1778;
    int unk177C;
    int unk1780;
    int unk1784;
    int unk1788;
    int unk178C;
    int unk1790;
    int unk1794;
    int unk1798;
    int unk179C;
    int unk17A0;
    int unk17A4;
    int unk17A8;
    int unk17AC;
    int unk17B0;
    int unk17B4;
    int unk17B8;
    int unk17BC;
    int unk17C0;
    int unk17C4;
    int unk17C8;
    int unk17CC;
    int unk17D0;
    int unk17D4;
    int unk17D8;
    int unk17DC;
    int unk17E0;
    int unk17E4;
    int unk17E8;
    int unk17EC;
    int unk17F0;
    int unk17F4;
    int unk17F8;
    int unk17FC;
    int unk1800;
    int unk1804;
    int unk1808;
    int unk180C;
    int unk1810;
    int unk1814;
    int unk1818;
    int unk181C;
    int unk1820;
    int unk1824;
    int unk1828;
    int unk182C;
    int unk1830;
    int unk1834;
    int unk1838;
    int unk183C;
    int unk1840;
    int unk1844;
    int unk1848;
    int unk184C;
    int unk1850;
    int unk1854;
    int unk1858;
    int unk185C;
    int unk1860;
    int unk1864;
    int unk1868;
    int unk186C;
    int unk1870;
    int unk1874;
    int unk1878;
    int unk187C;
    int unk1880;
    int unk1884;
    int unk1888;
    int unk188C;
    int unk1890;
    int unk1894;
    int unk1898;
    int unk189C;
    int unk18A0;
    int unk18A4;
    int unk18A8;
    int unk18AC;
    int unk18B0;
    int unk18B4;
    int unk18B8;
    int unk18BC;
    int unk18C0;
    int unk18C4;
    int unk18C8;
    int unk18CC;
    int unk18D0;
    int unk18D4;
    int unk18D8;
    int unk18DC;
    int unk18E0;
    int unk18E4;
    int unk18E8;
    int unk18EC;
    int unk18F0;
    int unk18F4;
    int unk18F8;
    int unk18FC;
    int unk1900;
    int unk1904;
    int unk1908;
    int unk190C;
    int unk1910;
    int unk1914;
    int unk1918;
    int unk191C;
    int unk1920;
    int unk1924;
    int unk1928;
    int unk192C;
    int unk1930;
    int unk1934;
    int unk1938;
    int unk193C;
    int unk1940;
    int unk1944;
    int unk1948;
    int unk194C;
    int unk1950;
    int unk1954;
    int unk1958;
    int unk195C;
    int unk1960;
    int unk1964;
    int unk1968;
    int unk196C;
    int unk1970;
    int unk1974;
    int unk1978;
    int unk197C;
    int unk1980;
    int unk1984;
    int unk1988;
    int unk198C;
    int unk1990;
    int unk1994;
    int unk1998;
    int unk199C;
    int unk19A0;
    int unk19A4;
    int unk19A8;
    int unk19AC;
    int unk19B0;
    int unk19B4;
    int unk19B8;
    int unk19BC;
    int unk19C0;
    int unk19C4;
    int unk19C8;
    int unk19CC;
    int unk19D0;
    int unk19D4;
    int unk19D8;
    int unk19DC;
    int unk19E0;
    int unk19E4;
    int unk19E8;
    int unk19EC;
    int unk19F0;
    int unk19F4;
    int unk19F8;
    int unk19FC;
    int unk1A00;
    int unk1A04;
    int unk1A08;
    int unk1A0C;
    int unk1A10;
    int unk1A14;
    int unk1A18;
    int unk1A1C;
    int unk1A20;
    int unk1A24;
    int unk1A28;
    int unk1A2C;
    int unk1A30;
    int unk1A34;
    int unk1A38;
    int unk1A3C;
    int unk1A40;
    int unk1A44;
    int unk1A48;
    int unk1A4C;
    int unk1A50;
    int unk1A54;
    int unk1A58;
    int unk1A5C;
    int unk1A60;
    int unk1A64;
    int unk1A68;
    int unk1A6C;
    int unk1A70;
    int unk1A74;
    int unk1A78;
    int unk1A7C;
    int unk1A80;
    int unk1A84;
    int unk1A88;
    int unk1A8C;
    int unk1A90;
    int unk1A94;
    int unk1A98;
    int unk1A9C;
    int unk1AA0;
    int unk1AA4;
    int unk1AA8;
    int unk1AAC;
    int unk1AB0;
    int unk1AB4;
    int unk1AB8;
    int unk1ABC;
    int unk1AC0;
    int unk1AC4;
    int unk1AC8;
    int unk1ACC;
    int unk1AD0;
    int unk1AD4;
    int unk1AD8;
    int unk1ADC;
    int unk1AE0;
    int unk1AE4;
    int unk1AE8;
    int unk1AEC;
    int unk1AF0;
    int unk1AF4;
    int unk1AF8;
    int unk1AFC;
    int unk1B00;
    int unk1B04;
    int unk1B08;
    int unk1B0C;
    int unk1B10;
    int unk1B14;
    int unk1B18;
    int unk1B1C;
    int unk1B20;
    int unk1B24;
    int unk1B28;
    int unk1B2C;
    int unk1B30;
    int unk1B34;
    int unk1B38;
    int unk1B3C;
    int unk1B40;
    int unk1B44;
    int unk1B48;
    int unk1B4C;
    int unk1B50;
    int unk1B54;
    int unk1B58;
    int unk1B5C;
    int unk1B60;
    int unk1B64;
    int unk1B68;
    int unk1B6C;
    int unk1B70;
    int unk1B74;
    int unk1B78;
    int unk1B7C;
    int unk1B80;
    int unk1B84;
    int unk1B88;
    int unk1B8C;
    int unk1B90;
    int unk1B94;
    int unk1B98;
    int unk1B9C;
    int unk1BA0;
    int unk1BA4;
    int unk1BA8;
    int unk1BAC;
    int unk1BB0;
    int unk1BB4;
    int unk1BB8;
    int unk1BBC;
    int unk1BC0;
    int unk1BC4;
    int unk1BC8;
    int unk1BCC;
    int unk1BD0;
    int unk1BD4;
    int unk1BD8;
    int unk1BDC;
    int unk1BE0;
    int unk1BE4;
    int unk1BE8;
    int unk1BEC;
    int unk1BF0;
    int unk1BF4;
    int unk1BF8;
    int unk1BFC;
    int unk1C00;
    int unk1C04;
    int unk1C08;
    int unk1C0C;
    int unk1C10;
    int unk1C14;
    int unk1C18;
    int unk1C1C;
    int unk1C20;
    int unk1C24;
    int unk1C28;
    int unk1C2C;
    int unk1C30;
    int unk1C34;
    int unk1C38;
    int unk1C3C;
    int unk1C40;
    int unk1C44;
    int unk1C48;
    int unk1C4C;
    int unk1C50;
    int unk1C54;
    int unk1C58;
    int unk1C5C;
    int unk1C60;
    int unk1C64;
    int unk1C68;
    int unk1C6C;
    int unk1C70;
    int unk1C74;
    int unk1C78;
    int unk1C7C;
    int unk1C80;
    int unk1C84;
    int unk1C88;
    int unk1C8C;
    int unk1C90;
    int unk1C94;
    int unk1C98;
    int unk1C9C;
    int unk1CA0;
    int unk1CA4;
    int unk1CA8;
    int unk1CAC;
    int unk1CB0;
    int unk1CB4;
    int unk1CB8;
    int unk1CBC;
    int unk1CC0;
    int unk1CC4;
    int unk1CC8;
    int unk1CCC;
    int unk1CD0;
    int unk1CD4;
    int unk1CD8;
    int unk1CDC;
    int unk1CE0;
    int unk1CE4;
    int unk1CE8;
    int unk1CEC;
    int unk1CF0;
    int unk1CF4;
    int unk1CF8;
    int unk1CFC;
    int unk1D00;
    int unk1D04;
    int unk1D08;
    int unk1D0C;
    int unk1D10;
    int unk1D14;
    int unk1D18;
    int unk1D1C;
    int unk1D20;
    int unk1D24;
    int unk1D28;
    int unk1D2C;
    int unk1D30;
    int unk1D34;
    int unk1D38;
    int unk1D3C;
    int unk1D40;
    int unk1D44;
    int unk1D48;
    int unk1D4C;
    int unk1D50;
    int unk1D54;
    int unk1D58;
    int unk1D5C;
    int unk1D60;
    int unk1D64;
    int unk1D68;
    int unk1D6C;
    int unk1D70;
    int unk1D74;
    int unk1D78;
    int unk1D7C;
    int unk1D80;
    int unk1D84;
    int unk1D88;
    int unk1D8C;
    int unk1D90;
    int unk1D94;
    int unk1D98;
    int unk1D9C;
    int unk1DA0;
    int unk1DA4;
    int unk1DA8;
    int unk1DAC;
    int unk1DB0;
    int unk1DB4;
    int unk1DB8;
    int unk1DBC;
    int unk1DC0;
    int unk1DC4;
    int unk1DC8;
    int unk1DCC;
    int unk1DD0;
    int unk1DD4;
    int unk1DD8;
    int unk1DDC;
    int unk1DE0;
    int unk1DE4;
    int unk1DE8;
    int unk1DEC;
    int unk1DF0;
    int unk1DF4;
    int unk1DF8;
    int unk1DFC;
    int unk1E00;
    int unk1E04;
    int unk1E08;
    int unk1E0C;
    int unk1E10;
    int unk1E14;
    int unk1E18;
    int unk1E1C;
    bool m_bPending;  // 0x1E20
    char unk1E21;
    char unk1E22;
    char unk1E23;
    int unk1E24;
    int unk1E28;
    int unk1E2C;
    unsigned char* m_apucColor[4];  // 0x1E30

    void hkpCollisionDispatcher_resetCreationFunctions();
};

void __cdecl hkAgent3Bridge_registerAgent3(S00cfb080_State* pkState);

// Initializes the state by zeroing map arrays, setting color buffers to 100, assigning allocation and notification callbacks, and calling FUN_00d923b0.
// @fnv 0x00cfb080
// src: HAVOK_LIB 0x00cfb080
void S00cfb080_State::hkpCollisionDispatcher_resetCreationFunctions()
{
    m_iDirtyA = 1;
    m_iDirtyB = 1;
    for (int i = 0; i < 32; ++i)
    {
        for (int j = 0; j < 32; ++j)
        {
            int iIndex = i * 32 + j;
            if (m_apucColor[0])
            {
                m_apucColor[0][iIndex * 3 + 2] = 100;
                m_apucColor[1][iIndex * 3 + 2] = 100;
                m_apucColor[2][iIndex * 3 + 2] = 100;
                m_apucColor[3][iIndex * 3 + 2] = 100;
            }
            m_aucMapA[i][j] = 0;
            m_aucMapB[i][j] = 0;
            m_aucMapC[i][j] = 0;
            m_aucMapD[i][j] = 0;
        }
    }

    m_kIO.Init();

    m_pfnAlloc = Runtime_UpdateState_00cfb050;
    m_pfnFree = nullsub_7;
    m_i16B8 = 0;
    m_i16BC = 0;
    m_i16C0 = 0;
    m_i16C4 = 0;
    m_i16C8 = 0;
    m_i16CC = 0;
    m_i16D8 = 0;
    m_i16D0 = 0;
    m_i16D4 = 0;
    m_pfnNotify = Runtime_GetC;
    m_i16F0 = 0;
    hkAgent3Bridge_registerAgent3(this);
    m_bPending = false;

    if (m_apucColor[2])
    {
        for (int i = 0; i < 32; ++i)
        {
            for (int j = 0; j < 32; ++j)
            {
                int iIndex = i * 32 + j;
                m_apucColor[2][iIndex * 3 + 2] = 100;
                m_apucColor[3][iIndex * 3 + 2] = 100;
            }
        }
    }
}

#include <math.h>
extern "C" void* __cdecl fnv_zlib_memset(void* dst, int val, unsigned int n);

struct Src
{
    float f00, f04, f08, f0c, f10, f14, f18, f1c;
    short s20, s22, s24, s26;
    unsigned char b28, b29, b2a, b2b;
};
struct Block
{
    float f00, f04, f08, f0c;
    int i10;
    unsigned char b14;
    unsigned char x15, x16, x17;
    float f18, f1c, f20, f24, f28, f2c, f30, f34, f38;
    short s3c;
    unsigned char b3e;
    unsigned char x3f;
};
struct Big
{
    int unk0000, unk0004, unk0008, unk000C, unk0010, unk0014, unk0018, unk001C, unk0020, unk0024, unk0028, unk002C,
        unk0030, unk0034, unk0038, unk003C;
    int unk0040, unk0044, unk0048, unk004C, unk0050, unk0054, unk0058, unk005C, unk0060, unk0064, unk0068, unk006C,
        unk0070, unk0074, unk0078, unk007C;
    int unk0080, unk0084, unk0088, unk008C, unk0090, unk0094, unk0098, unk009C, unk00A0, unk00A4, unk00A8, unk00AC,
        unk00B0, unk00B4, unk00B8, unk00BC;
    int unk00C0, unk00C4, unk00C8, unk00CC, unk00D0, unk00D4, unk00D8, unk00DC, unk00E0, unk00E4, unk00E8, unk00EC,
        unk00F0, unk00F4, unk00F8, unk00FC;
    int unk0100, unk0104, unk0108, unk010C, unk0110, unk0114, unk0118, unk011C, unk0120, unk0124, unk0128, unk012C,
        unk0130, unk0134, unk0138, unk013C;
    int unk0140, unk0144, unk0148, unk014C, unk0150, unk0154, unk0158, unk015C, unk0160, unk0164, unk0168, unk016C,
        unk0170, unk0174, unk0178, unk017C;
    int unk0180, unk0184, unk0188, unk018C, unk0190, unk0194, unk0198, unk019C, unk01A0, unk01A4, unk01A8, unk01AC,
        unk01B0, unk01B4, unk01B8, unk01BC;
    int unk01C0, unk01C4, unk01C8, unk01CC, unk01D0, unk01D4, unk01D8, unk01DC, unk01E0, unk01E4, unk01E8, unk01EC,
        unk01F0, unk01F4, unk01F8, unk01FC;
    int unk0200, unk0204, unk0208, unk020C, unk0210, unk0214, unk0218, unk021C, unk0220, unk0224, unk0228, unk022C,
        unk0230, unk0234, unk0238, unk023C;
    int unk0240, unk0244, unk0248, unk024C, unk0250, unk0254, unk0258, unk025C, unk0260, unk0264, unk0268, unk026C,
        unk0270, unk0274, unk0278, unk027C;
    int unk0280, unk0284, unk0288, unk028C, unk0290, unk0294, unk0298, unk029C, unk02A0, unk02A4, unk02A8, unk02AC,
        unk02B0, unk02B4, unk02B8, unk02BC;
    int unk02C0, unk02C4, unk02C8, unk02CC, unk02D0, unk02D4, unk02D8, unk02DC, unk02E0, unk02E4, unk02E8, unk02EC,
        unk02F0, unk02F4, unk02F8, unk02FC;
    int unk0300, unk0304, unk0308, unk030C, unk0310, unk0314, unk0318, unk031C, unk0320, unk0324, unk0328, unk032C,
        unk0330, unk0334, unk0338, unk033C;
    int unk0340, unk0344, unk0348, unk034C, unk0350, unk0354, unk0358, unk035C, unk0360, unk0364, unk0368, unk036C,
        unk0370, unk0374, unk0378, unk037C;
    int unk0380, unk0384, unk0388, unk038C, unk0390, unk0394, unk0398, unk039C, unk03A0, unk03A4, unk03A8, unk03AC,
        unk03B0, unk03B4, unk03B8, unk03BC;
    int unk03C0, unk03C4, unk03C8, unk03CC, unk03D0, unk03D4, unk03D8, unk03DC, unk03E0, unk03E4, unk03E8, unk03EC,
        unk03F0, unk03F4, unk03F8, unk03FC;
    int unk0400, unk0404, unk0408, unk040C, unk0410, unk0414, unk0418, unk041C, unk0420, unk0424, unk0428, unk042C,
        unk0430, unk0434, unk0438, unk043C;
    int unk0440, unk0444, unk0448, unk044C, unk0450, unk0454, unk0458, unk045C, unk0460, unk0464, unk0468, unk046C,
        unk0470, unk0474, unk0478, unk047C;
    int unk0480, unk0484, unk0488, unk048C, unk0490, unk0494, unk0498, unk049C, unk04A0, unk04A4, unk04A8, unk04AC,
        unk04B0, unk04B4, unk04B8, unk04BC;
    int unk04C0, unk04C4, unk04C8, unk04CC, unk04D0, unk04D4, unk04D8, unk04DC, unk04E0, unk04E4, unk04E8, unk04EC,
        unk04F0, unk04F4, unk04F8, unk04FC;
    int unk0500, unk0504, unk0508, unk050C, unk0510, unk0514, unk0518, unk051C, unk0520, unk0524, unk0528, unk052C,
        unk0530, unk0534, unk0538, unk053C;
    int unk0540, unk0544, unk0548, unk054C, unk0550, unk0554, unk0558, unk055C, unk0560, unk0564, unk0568, unk056C,
        unk0570, unk0574, unk0578, unk057C;
    int unk0580, unk0584, unk0588, unk058C, unk0590, unk0594, unk0598, unk059C, unk05A0, unk05A4, unk05A8, unk05AC,
        unk05B0, unk05B4, unk05B8, unk05BC;
    int unk05C0, unk05C4, unk05C8, unk05CC, unk05D0, unk05D4, unk05D8, unk05DC, unk05E0, unk05E4, unk05E8, unk05EC,
        unk05F0, unk05F4, unk05F8, unk05FC;
    int unk0600, unk0604, unk0608, unk060C, unk0610, unk0614, unk0618, unk061C, unk0620, unk0624, unk0628, unk062C,
        unk0630, unk0634, unk0638, unk063C;
    int unk0640, unk0644, unk0648, unk064C, unk0650, unk0654, unk0658, unk065C, unk0660, unk0664, unk0668, unk066C,
        unk0670, unk0674, unk0678, unk067C;
    int unk0680, unk0684, unk0688, unk068C, unk0690, unk0694, unk0698, unk069C, unk06A0, unk06A4, unk06A8, unk06AC,
        unk06B0, unk06B4, unk06B8, unk06BC;
    int unk06C0, unk06C4, unk06C8, unk06CC, unk06D0, unk06D4, unk06D8, unk06DC, unk06E0, unk06E4, unk06E8, unk06EC,
        unk06F0, unk06F4, unk06F8, unk06FC;
    int unk0700, unk0704, unk0708, unk070C, unk0710, unk0714, unk0718, unk071C, unk0720, unk0724, unk0728, unk072C,
        unk0730, unk0734, unk0738, unk073C;
    int unk0740, unk0744, unk0748, unk074C, unk0750, unk0754, unk0758, unk075C, unk0760, unk0764, unk0768, unk076C,
        unk0770, unk0774, unk0778, unk077C;
    int unk0780, unk0784, unk0788, unk078C, unk0790, unk0794, unk0798, unk079C, unk07A0, unk07A4, unk07A8, unk07AC,
        unk07B0, unk07B4, unk07B8, unk07BC;
    int unk07C0, unk07C4, unk07C8, unk07CC, unk07D0, unk07D4, unk07D8, unk07DC, unk07E0, unk07E4, unk07E8, unk07EC,
        unk07F0, unk07F4, unk07F8, unk07FC;
    int unk0800, unk0804, unk0808, unk080C, unk0810, unk0814, unk0818, unk081C, unk0820, unk0824, unk0828, unk082C,
        unk0830, unk0834, unk0838, unk083C;
    int unk0840, unk0844, unk0848, unk084C, unk0850, unk0854, unk0858, unk085C, unk0860, unk0864, unk0868, unk086C,
        unk0870, unk0874, unk0878, unk087C;
    int unk0880, unk0884, unk0888, unk088C, unk0890, unk0894, unk0898, unk089C, unk08A0, unk08A4, unk08A8, unk08AC,
        unk08B0, unk08B4, unk08B8, unk08BC;
    int unk08C0, unk08C4, unk08C8, unk08CC, unk08D0, unk08D4, unk08D8, unk08DC, unk08E0, unk08E4, unk08E8, unk08EC,
        unk08F0, unk08F4, unk08F8, unk08FC;
    int unk0900, unk0904, unk0908, unk090C, unk0910, unk0914, unk0918, unk091C, unk0920, unk0924, unk0928, unk092C,
        unk0930, unk0934, unk0938, unk093C;
    int unk0940, unk0944, unk0948, unk094C, unk0950, unk0954, unk0958, unk095C, unk0960, unk0964, unk0968, unk096C,
        unk0970, unk0974, unk0978, unk097C;
    int unk0980, unk0984, unk0988, unk098C, unk0990, unk0994, unk0998, unk099C, unk09A0, unk09A4, unk09A8, unk09AC,
        unk09B0, unk09B4, unk09B8, unk09BC;
    int unk09C0, unk09C4, unk09C8, unk09CC, unk09D0, unk09D4, unk09D8, unk09DC, unk09E0, unk09E4, unk09E8, unk09EC,
        unk09F0, unk09F4, unk09F8, unk09FC;
    int unk0A00, unk0A04, unk0A08, unk0A0C, unk0A10, unk0A14, unk0A18, unk0A1C, unk0A20, unk0A24, unk0A28, unk0A2C,
        unk0A30, unk0A34, unk0A38, unk0A3C;
    int unk0A40, unk0A44, unk0A48, unk0A4C, unk0A50, unk0A54, unk0A58, unk0A5C, unk0A60, unk0A64, unk0A68, unk0A6C,
        unk0A70, unk0A74, unk0A78, unk0A7C;
    int unk0A80, unk0A84, unk0A88, unk0A8C, unk0A90, unk0A94, unk0A98, unk0A9C, unk0AA0, unk0AA4, unk0AA8, unk0AAC,
        unk0AB0, unk0AB4, unk0AB8, unk0ABC;
    int unk0AC0, unk0AC4, unk0AC8, unk0ACC, unk0AD0, unk0AD4, unk0AD8, unk0ADC, unk0AE0, unk0AE4, unk0AE8, unk0AEC,
        unk0AF0, unk0AF4, unk0AF8, unk0AFC;
    int unk0B00, unk0B04, unk0B08, unk0B0C, unk0B10, unk0B14, unk0B18, unk0B1C, unk0B20, unk0B24, unk0B28, unk0B2C,
        unk0B30, unk0B34, unk0B38, unk0B3C;
    int unk0B40, unk0B44, unk0B48, unk0B4C, unk0B50, unk0B54, unk0B58, unk0B5C, unk0B60, unk0B64, unk0B68, unk0B6C,
        unk0B70, unk0B74, unk0B78, unk0B7C;
    int unk0B80, unk0B84, unk0B88, unk0B8C, unk0B90, unk0B94, unk0B98, unk0B9C, unk0BA0, unk0BA4, unk0BA8, unk0BAC,
        unk0BB0, unk0BB4, unk0BB8, unk0BBC;
    int unk0BC0, unk0BC4, unk0BC8, unk0BCC, unk0BD0, unk0BD4, unk0BD8, unk0BDC, unk0BE0, unk0BE4, unk0BE8, unk0BEC,
        unk0BF0, unk0BF4, unk0BF8, unk0BFC;
    int unk0C00, unk0C04, unk0C08, unk0C0C, unk0C10, unk0C14, unk0C18, unk0C1C, unk0C20, unk0C24, unk0C28, unk0C2C,
        unk0C30, unk0C34, unk0C38, unk0C3C;
    int unk0C40, unk0C44, unk0C48, unk0C4C, unk0C50, unk0C54, unk0C58, unk0C5C, unk0C60, unk0C64, unk0C68, unk0C6C,
        unk0C70, unk0C74, unk0C78, unk0C7C;
    int unk0C80, unk0C84, unk0C88, unk0C8C, unk0C90, unk0C94, unk0C98, unk0C9C, unk0CA0, unk0CA4, unk0CA8, unk0CAC,
        unk0CB0, unk0CB4, unk0CB8, unk0CBC;
    int unk0CC0, unk0CC4, unk0CC8, unk0CCC, unk0CD0, unk0CD4, unk0CD8, unk0CDC, unk0CE0, unk0CE4, unk0CE8, unk0CEC,
        unk0CF0, unk0CF4, unk0CF8, unk0CFC;
    int unk0D00, unk0D04, unk0D08, unk0D0C, unk0D10, unk0D14, unk0D18, unk0D1C, unk0D20, unk0D24, unk0D28, unk0D2C,
        unk0D30, unk0D34, unk0D38, unk0D3C;
    int unk0D40, unk0D44, unk0D48, unk0D4C, unk0D50, unk0D54, unk0D58, unk0D5C, unk0D60, unk0D64, unk0D68, unk0D6C,
        unk0D70, unk0D74, unk0D78, unk0D7C;
    int unk0D80, unk0D84, unk0D88, unk0D8C, unk0D90, unk0D94, unk0D98, unk0D9C, unk0DA0, unk0DA4, unk0DA8, unk0DAC,
        unk0DB0, unk0DB4, unk0DB8, unk0DBC;
    int unk0DC0, unk0DC4, unk0DC8, unk0DCC, unk0DD0, unk0DD4, unk0DD8, unk0DDC, unk0DE0, unk0DE4, unk0DE8, unk0DEC,
        unk0DF0, unk0DF4, unk0DF8, unk0DFC;
    int unk0E00, unk0E04, unk0E08, unk0E0C, unk0E10, unk0E14, unk0E18, unk0E1C, unk0E20, unk0E24, unk0E28, unk0E2C,
        unk0E30, unk0E34, unk0E38, unk0E3C;
    int unk0E40, unk0E44, unk0E48, unk0E4C, unk0E50, unk0E54, unk0E58, unk0E5C, unk0E60, unk0E64, unk0E68, unk0E6C,
        unk0E70, unk0E74, unk0E78, unk0E7C;
    int unk0E80, unk0E84, unk0E88, unk0E8C, unk0E90, unk0E94, unk0E98, unk0E9C, unk0EA0, unk0EA4, unk0EA8, unk0EAC,
        unk0EB0, unk0EB4, unk0EB8, unk0EBC;
    int unk0EC0, unk0EC4, unk0EC8, unk0ECC, unk0ED0, unk0ED4, unk0ED8, unk0EDC, unk0EE0, unk0EE4, unk0EE8, unk0EEC,
        unk0EF0, unk0EF4, unk0EF8, unk0EFC;
    int unk0F00, unk0F04, unk0F08, unk0F0C, unk0F10, unk0F14, unk0F18, unk0F1C, unk0F20, unk0F24, unk0F28, unk0F2C,
        unk0F30, unk0F34, unk0F38, unk0F3C;
    int unk0F40, unk0F44, unk0F48, unk0F4C, unk0F50, unk0F54, unk0F58, unk0F5C, unk0F60, unk0F64, unk0F68, unk0F6C,
        unk0F70, unk0F74, unk0F78, unk0F7C;
    int unk0F80, unk0F84, unk0F88, unk0F8C, unk0F90, unk0F94, unk0F98, unk0F9C, unk0FA0, unk0FA4, unk0FA8, unk0FAC,
        unk0FB0, unk0FB4, unk0FB8, unk0FBC;
    int unk0FC0, unk0FC4, unk0FC8, unk0FCC, unk0FD0, unk0FD4, unk0FD8, unk0FDC, unk0FE0, unk0FE4, unk0FE8, unk0FEC,
        unk0FF0, unk0FF4, unk0FF8, unk0FFC;
    int unk1000, unk1004, unk1008, unk100C, unk1010, unk1014, unk1018, unk101C, unk1020, unk1024, unk1028, unk102C,
        unk1030, unk1034, unk1038, unk103C;
    int unk1040, unk1044, unk1048, unk104C, unk1050, unk1054, unk1058, unk105C, unk1060, unk1064, unk1068, unk106C,
        unk1070, unk1074, unk1078, unk107C;
    int unk1080, unk1084, unk1088, unk108C, unk1090, unk1094, unk1098, unk109C, unk10A0, unk10A4, unk10A8, unk10AC,
        unk10B0, unk10B4, unk10B8, unk10BC;
    int unk10C0, unk10C4, unk10C8, unk10CC, unk10D0, unk10D4, unk10D8, unk10DC, unk10E0, unk10E4, unk10E8, unk10EC,
        unk10F0, unk10F4, unk10F8, unk10FC;
    int unk1100, unk1104, unk1108, unk110C, unk1110, unk1114, unk1118, unk111C, unk1120, unk1124, unk1128, unk112C,
        unk1130, unk1134, unk1138, unk113C;
    int unk1140, unk1144, unk1148, unk114C, unk1150, unk1154, unk1158, unk115C, unk1160, unk1164, unk1168, unk116C,
        unk1170, unk1174, unk1178, unk117C;
    int unk1180, unk1184, unk1188, unk118C, unk1190, unk1194, unk1198, unk119C, unk11A0, unk11A4, unk11A8, unk11AC,
        unk11B0, unk11B4, unk11B8, unk11BC;
    int unk11C0, unk11C4, unk11C8, unk11CC, unk11D0, unk11D4, unk11D8, unk11DC, unk11E0, unk11E4, unk11E8, unk11EC,
        unk11F0, unk11F4, unk11F8, unk11FC;
    int unk1200, unk1204, unk1208, unk120C, unk1210, unk1214, unk1218, unk121C, unk1220, unk1224, unk1228, unk122C,
        unk1230, unk1234, unk1238, unk123C;
    int unk1240, unk1244, unk1248, unk124C, unk1250, unk1254, unk1258, unk125C, unk1260, unk1264, unk1268, unk126C,
        unk1270, unk1274, unk1278, unk127C;
    int unk1280, unk1284, unk1288, unk128C, unk1290, unk1294, unk1298, unk129C, unk12A0, unk12A4, unk12A8, unk12AC,
        unk12B0, unk12B4, unk12B8, unk12BC;
    int unk12C0, unk12C4, unk12C8, unk12CC, unk12D0, unk12D4, unk12D8, unk12DC, unk12E0, unk12E4, unk12E8, unk12EC,
        unk12F0, unk12F4, unk12F8, unk12FC;
    int unk1300, unk1304, unk1308, unk130C, unk1310, unk1314, unk1318, unk131C, unk1320, unk1324, unk1328, unk132C,
        unk1330, unk1334, unk1338, unk133C;
    int unk1340, unk1344, unk1348, unk134C, unk1350, unk1354, unk1358, unk135C, unk1360, unk1364, unk1368, unk136C,
        unk1370, unk1374, unk1378, unk137C;
    int unk1380, unk1384, unk1388, unk138C, unk1390, unk1394, unk1398, unk139C, unk13A0, unk13A4, unk13A8, unk13AC,
        unk13B0, unk13B4, unk13B8, unk13BC;
    int unk13C0, unk13C4, unk13C8, unk13CC, unk13D0, unk13D4, unk13D8, unk13DC, unk13E0, unk13E4, unk13E8, unk13EC,
        unk13F0, unk13F4, unk13F8, unk13FC;
    int unk1400, unk1404, unk1408, unk140C, unk1410, unk1414, unk1418, unk141C, unk1420, unk1424, unk1428, unk142C,
        unk1430, unk1434, unk1438, unk143C;
    int unk1440, unk1444, unk1448, unk144C, unk1450, unk1454, unk1458, unk145C, unk1460, unk1464, unk1468, unk146C,
        unk1470, unk1474, unk1478, unk147C;
    int unk1480, unk1484, unk1488, unk148C, unk1490, unk1494, unk1498, unk149C, unk14A0, unk14A4, unk14A8, unk14AC,
        unk14B0, unk14B4, unk14B8, unk14BC;
    int unk14C0, unk14C4, unk14C8, unk14CC, unk14D0, unk14D4, unk14D8, unk14DC, unk14E0, unk14E4, unk14E8, unk14EC,
        unk14F0, unk14F4, unk14F8, unk14FC;
    int unk1500, unk1504, unk1508, unk150C, unk1510, unk1514, unk1518, unk151C, unk1520, unk1524, unk1528, unk152C,
        unk1530, unk1534, unk1538, unk153C;
    int unk1540, unk1544, unk1548, unk154C, unk1550, unk1554, unk1558, unk155C, unk1560, unk1564, unk1568, unk156C,
        unk1570, unk1574, unk1578, unk157C;
    int unk1580, unk1584, unk1588, unk158C, unk1590, unk1594, unk1598, unk159C, unk15A0, unk15A4, unk15A8, unk15AC,
        unk15B0, unk15B4, unk15B8, unk15BC;
    int unk15C0, unk15C4, unk15C8, unk15CC, unk15D0, unk15D4, unk15D8, unk15DC, unk15E0, unk15E4, unk15E8, unk15EC,
        unk15F0, unk15F4, unk15F8, unk15FC;
    int unk1600, unk1604, unk1608, unk160C, unk1610, unk1614, unk1618, unk161C, unk1620, unk1624, unk1628, unk162C,
        unk1630, unk1634, unk1638, unk163C;
    int unk1640, unk1644, unk1648, unk164C, unk1650, unk1654, unk1658, unk165C, unk1660, unk1664, unk1668, unk166C,
        unk1670, unk1674, unk1678, unk167C;
    int unk1680, unk1684, unk1688, unk168C, unk1690, unk1694, unk1698, unk169C, unk16A0, unk16A4, unk16A8, unk16AC,
        unk16B0, unk16B4, unk16B8, unk16BC;
    int unk16C0, unk16C4, unk16C8, unk16CC, unk16D0, unk16D4, unk16D8, unk16DC, unk16E0, unk16E4, unk16E8, unk16EC,
        unk16F0, unk16F4, unk16F8, unk16FC;
    int unk1700, unk1704, unk1708, unk170C, unk1710, unk1714, unk1718, unk171C, unk1720, unk1724, unk1728, unk172C,
        unk1730, unk1734, unk1738, unk173C;
    int unk1740, unk1744, unk1748, unk174C, unk1750, unk1754, unk1758, unk175C, unk1760, unk1764, unk1768, unk176C,
        unk1770, unk1774, unk1778, unk177C;
    int unk1780, unk1784, unk1788, unk178C, unk1790, unk1794, unk1798, unk179C, unk17A0, unk17A4, unk17A8, unk17AC,
        unk17B0, unk17B4, unk17B8, unk17BC;
    int unk17C0, unk17C4, unk17C8, unk17CC, unk17D0, unk17D4, unk17D8, unk17DC, unk17E0, unk17E4, unk17E8, unk17EC,
        unk17F0, unk17F4, unk17F8, unk17FC;
    int unk1800, unk1804, unk1808, unk180C, unk1810, unk1814, unk1818, unk181C, unk1820, unk1824, unk1828, unk182C,
        unk1830, unk1834, unk1838, unk183C;
    int unk1840, unk1844, unk1848, unk184C, unk1850, unk1854, unk1858, unk185C, unk1860, unk1864, unk1868, unk186C,
        unk1870, unk1874, unk1878, unk187C;
    int unk1880, unk1884, unk1888, unk188C, unk1890, unk1894, unk1898, unk189C, unk18A0, unk18A4, unk18A8, unk18AC,
        unk18B0, unk18B4, unk18B8, unk18BC;
    int unk18C0, unk18C4, unk18C8, unk18CC, unk18D0, unk18D4, unk18D8, unk18DC, unk18E0, unk18E4, unk18E8, unk18EC,
        unk18F0, unk18F4, unk18F8, unk18FC;
    int unk1900, unk1904, unk1908, unk190C, unk1910, unk1914, unk1918, unk191C, unk1920, unk1924, unk1928, unk192C,
        unk1930, unk1934, unk1938, unk193C;
    int unk1940, unk1944, unk1948, unk194C, unk1950, unk1954, unk1958, unk195C, unk1960, unk1964, unk1968, unk196C,
        unk1970, unk1974, unk1978, unk197C;
    int unk1980, unk1984, unk1988, unk198C, unk1990, unk1994, unk1998, unk199C, unk19A0, unk19A4, unk19A8, unk19AC,
        unk19B0, unk19B4, unk19B8, unk19BC;
    int unk19C0, unk19C4, unk19C8, unk19CC, unk19D0, unk19D4, unk19D8, unk19DC, unk19E0, unk19E4, unk19E8, unk19EC,
        unk19F0, unk19F4, unk19F8, unk19FC;
    int unk1A00, unk1A04, unk1A08, unk1A0C, unk1A10, unk1A14, unk1A18, unk1A1C, unk1A20, unk1A24, unk1A28, unk1A2C,
        unk1A30, unk1A34, unk1A38, unk1A3C;
    int unk1A40, unk1A44, unk1A48, unk1A4C, unk1A50, unk1A54, unk1A58, unk1A5C, unk1A60, unk1A64, unk1A68, unk1A6C,
        unk1A70, unk1A74, unk1A78, unk1A7C;
    int unk1A80, unk1A84, unk1A88, unk1A8C, unk1A90, unk1A94, unk1A98, unk1A9C, unk1AA0, unk1AA4, unk1AA8, unk1AAC,
        unk1AB0, unk1AB4, unk1AB8, unk1ABC;
    int unk1AC0, unk1AC4, unk1AC8, unk1ACC, unk1AD0, unk1AD4, unk1AD8, unk1ADC, unk1AE0, unk1AE4, unk1AE8, unk1AEC,
        unk1AF0, unk1AF4, unk1AF8, unk1AFC;
    int unk1B00, unk1B04, unk1B08, unk1B0C, unk1B10, unk1B14, unk1B18, unk1B1C, unk1B20, unk1B24, unk1B28, unk1B2C,
        unk1B30, unk1B34, unk1B38, unk1B3C;
    int unk1B40, unk1B44, unk1B48, unk1B4C, unk1B50, unk1B54, unk1B58, unk1B5C, unk1B60, unk1B64, unk1B68, unk1B6C,
        unk1B70, unk1B74, unk1B78, unk1B7C;
    int unk1B80, unk1B84, unk1B88, unk1B8C, unk1B90, unk1B94, unk1B98, unk1B9C, unk1BA0, unk1BA4, unk1BA8, unk1BAC;
    unsigned char table[100];
    int unk1C14, unk1C18, unk1C1C, unk1C20, unk1C24, unk1C28, unk1C2C, unk1C30, unk1C34, unk1C38, unk1C3C, unk1C40,
        unk1C44, unk1C48, unk1C4C, unk1C50;
    int unk1C54, unk1C58, unk1C5C;
    Block blk[7];
    int unk1E20, unk1E24, unk1E28, unk1E2C, unk1E30, unk1E34, unk1E38, unk1E3C;
    float f1e40, f1e44;
    void hkpCollisionDispatcher_initCollisionQualityInfo(Src* src);
};

// Fills the 7 Block entries in blk from src with conditional overrides based on src flags, and fills the 100-byte table with fixed values.
// @fnv 0x00cfb570
// src: HAVOK_LIB 0x00cfb570
void Big::hkpCollisionDispatcher_initCollisionQualityInfo(Src* src)
{
    Block* b0 = &blk[0];
    f1e44 = src->f08;
    f1e40 = src->f0c;
    float t = (float)(src->f00 * 0.5 * src->f08 * src->f08);
    b0->b3e = src->b2b;
    b0->f00 = src->f04;
    b0->f04 = src->f04;
    b0->f0c = src->f04;
    if (src->b29)
        b0->f0c = (float)(-2.0 * t);
    b0->f08 = src->f04;
    double c1a6b0 = -1.0;
    if (src->b2a)
        b0->f08 = (float)(t * c1a6b0);
    b0->f34 = 3.40282e+38f;
    b0->i10 = 0;
    b0->b14 = 0;
    b0->s3c = src->s20;
    b0->f18 = -5e19f;
    b0->f1c = -5e19f;
    b0->f28 = -1e19f;
    b0->f2c = -1e19f;
    t = fabsf(-4.999999990253224e+18);
    b0->f30 = t;
    b0->f20 = 1.0f;
    b0->f24 = 1.0f;
    b0->f38 = 1.0f;
    Block* b6 = &blk[6];
    *b6 = *b0;
    Block* b1 = &blk[1];
    *b1 = *b0;
    Block* b2 = &blk[2];
    *b2 = *b0;
    Block* b3 = &blk[3];
    *b3 = *b0;
    Block* b4 = &blk[4];
    *b4 = *b0;
    b6->f0c = src->f04;
    b6->f04 = src->f04;
    b6->f08 = src->f04;
    if (src->b28)
    {
        b1->f18 = -0.5f;
        b1->f1c = (float)(-0.5 / (src->f10 - 1.0));
        b1->f28 = -0.25f;
        float u = (float)(-0.3499999940395355 / (src->f10 - 1.0));
        b1->f2c = u;
        b1->f30 = (float)(u * -0.30000001192092896);
        b1->f34 = (float)(b1->f1c * c1a6b0);
        b1->f20 = (float)(5.0 / src->f0c);
        b1->f24 = (float)(0.004999999888241291 / src->f0c);
        b1->f38 = (float)(b1->f1c * -2.0 / src->f0c);
        b1->s3c = src->s22;
        b1->i10 = 1;
        b1->b14 = 1;
    }
    if (src->b28)
    {
        b2->f18 = -0.5f;
        b2->f1c = (float)(-0.5 / (src->f14 - 1.0));
        b2->f28 = -0.25f;
        float u2 = (float)(-0.3499999940395355 / (src->f14 - 1.0));
        b2->f2c = u2;
        b2->f30 = (float)(u2 * -0.30000001192092896);
        b2->f34 = (float)(b2->f1c * c1a6b0);
        b2->f20 = (float)(5.0 / src->f0c);
        b2->f24 = (float)(0.004999999888241291 / src->f0c);
        b2->f38 = (float)(b2->f1c * -2.0 / src->f0c);
        b2->s3c = src->s22;
        b2->i10 = 1;
    }
    if (src->b28)
    {
        b3->f18 = -0.5f;
        b3->f1c = (float)(-0.5 / (src->f18 - 1.0));
        b3->f28 = -0.25f;
        float u3 = (float)(-0.3499999940395355 / (src->f18 - 1.0));
        b3->f2c = u3;
        b3->f30 = (float)(u3 * -0.30000001192092896);
        double p = b3->f1c * c1a6b0;
        b3->f34 = (float)p;
        b3->f20 = (float)(5.0 / src->f0c);
        b3->f24 = (float)(0.004999999888241291 / src->f0c);
        b3->f38 = (float)(p / src->f0c);
        b3->s3c = src->s24;
        b3->i10 = 1;
    }
    b4->f00 = src->f04;
    if (src->b28)
    {
        b4->f18 = -0.4f;
        b4->f1c = (float)(-0.5999999940395355 / (src->f1c - 1.0));
        b4->f28 = -0.2f;
        float u = (float)(-0.41999998867511756 / (src->f1c - 1.0));
        b4->f2c = u;
        b4->f30 = (float)(u * -0.30000001192092896);
        double p = b4->f1c * c1a6b0;
        b4->f34 = (float)p;
        b4->f20 = (float)(5.0 / src->f0c);
        b4->f24 = (float)(0.004999999888241291 / src->f0c);
        b4->f38 = (float)(p / src->f0c);
        b4->s3c = src->s26;
        b4->i10 = 1;
    }
    Block* b5 = &blk[5];
    *b5 = *b4;
    b5->f0c = src->f04;
    b5->f08 = src->f04;
    fnv_zlib_memset(table, 1, 100);
    table[0] = 0;
    table[1] = 0;
    table[9] = 3;
    table[2] = 1;
    table[3] = 2;
    table[4] = 4;
    table[5] = 5;
    table[6] = 4;
    table[8] = 6;
    table[10] = 0;
    table[11] = 0;
    table[19] = 3;
    table[12] = 1;
    table[13] = 1;
    table[14] = 3;
    table[15] = 3;
    table[16] = 3;
    table[18] = 3;
    table[90] = 3;
    table[91] = 3;
    table[99] = 3;
    table[92] = 1;
    table[93] = 1;
    table[94] = 3;
    table[95] = 3;
    table[96] = 3;
    table[98] = 3;
    table[20] = 1;
    table[21] = 1;
    table[29] = 1;
    table[22] = 1;
    table[23] = 1;
    table[24] = 1;
    table[25] = 1;
    table[26] = 3;
    table[28] = 1;
    table[30] = 2;
    table[31] = 1;
    table[39] = 1;
    table[32] = 1;
    table[33] = 1;
    table[34] = 1;
    table[35] = 1;
    table[36] = 3;
    table[38] = 1;
    table[40] = 4;
    table[41] = 3;
    table[49] = 3;
    table[42] = 1;
    table[43] = 1;
    table[44] = 1;
    table[45] = 3;
    table[46] = 3;
    table[48] = 3;
    table[50] = 5;
    table[51] = 3;
    table[59] = 3;
    table[52] = 1;
    table[53] = 1;
    table[54] = 3;
    table[55] = 3;
    table[56] = 3;
    table[58] = 3;
    table[60] = 4;
    table[82] = 1;
    table[83] = 1;
    table[61] = 3;
    table[69] = 3;
    table[62] = 3;
    table[63] = 3;
    table[64] = 3;
    table[65] = 3;
    table[66] = 3;
    table[68] = 3;
    table[80] = 6;
    table[81] = 3;
    table[89] = 3;
    table[84] = 3;
    table[85] = 3;
    table[86] = 3;
    table[88] = 3;
}

struct S_00cfc550_Alloc
{
    virtual void unk0();
    virtual void unk4();
    virtual void ReleaseBlock(void* p, int n);
};
struct S_00cfc550_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_00cfc550_Alloc* m_pStreamAllocator;
    static S_00cfc550_Router& hkMemoryRouter_getInstance();
    S_00cfc550_Alloc& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct S_00cfc550_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00cfc550_RefObj()
    {}
    void operator delete(void* p)
    {
        S_00cfc550_RefObj* b = static_cast<S_00cfc550_RefObj*>(p);
        S_00cfc550_Router::hkMemoryRouter_getInstance().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

struct FUN_00cfc550 : S_00cfc550_RefObj
{
    FUN_00cfc550();
    virtual ~FUN_00cfc550();
};

// @fnv 0x00cfc550
FUN_00cfc550::FUN_00cfc550()
{}

struct Src_cfcba0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short unk10;
    unsigned short unk12;
};
struct Cls_cfcba0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    float unk1c;
    int unk20;
    Src_cfcba0* unk24;
    int unk28;
    int unk2c;
    unsigned short unk30;
    unsigned short unk32;
    Cls_cfcba0* hkpManifoldPointAddedEvent_hkpManifoldPointAddedEvent(unsigned short a0, Src_cfcba0* a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8,
                             float a9);
};
// Sets fields from parameters, stores a1 in unk24, sets unk32 from a1->unk12 when a1->unk08 is zero, and returns this.
// @fnv 0x00cfcba0
// src: HAVOK_LIB 0x00cfcba0
Cls_cfcba0* Cls_cfcba0::hkpManifoldPointAddedEvent_hkpManifoldPointAddedEvent(unsigned short a0, Src_cfcba0* a1, int a2, int a3, int a4, int a5, int a6, int a7,
                                     int a8, float a9)
{
    unk00 = a4;
    unk04 = a5;
    unk08 = 1;
    float& ref1c = unk1c;
    ref1c = a9;
    unk10 = a6;
    unk14 = a7;
    unk18 = a8;
    unk28 = a2;
    unk24 = a1;
    unk2c = a3;
    unk20 = 0;
    unk30 = a0;
    if (a1->unk08 == 0)
        unk32 = a1->unk12;
    else
        unk32 = 0;
    return this;
}
