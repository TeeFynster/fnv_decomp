#include "../../include/hkArray.h"

// src/staging/blk_00e20000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMemoryRouter.h"
// ScriptRecord_blk_00e20000_o2: local type (was include/ScriptRecord.h, which had no evidence of one real class); no method of it is bound to a named game function
class ScriptRecord_blk_00e20000_o2
{
public:
    unsigned int identifier;
    unsigned short flags;
    short type;
    unsigned int value;
};
// ScriptRecordList_blk_00e20000_o2: local type (was include/ScriptRecordList.h, which had no evidence of one real class); its methods are 0x00e3df60 hkxVertexDescription::getElementDecl
class ScriptRecord_blk_00e20000_o2;

class ScriptRecordList_blk_00e20000_o2
{
public:
    ScriptRecord_blk_00e20000_o2* records;
    int count;

    ScriptRecord_blk_00e20000_o2* FindByTypeAndOccurrence(int type, int occurrence);
};
#include "../../include/V4.h"
#include "../../include/hkBaseObject.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkReferencedObject.h"
// hkRefPtrE_blk_00e20000_o2: local type (was include/hkRefPtrE.h, which had no evidence of one real class); no method of it is bound to a named game function
#include "../../include/hkReferencedObject.h"

class hkRefPtrE_blk_00e20000_o2
{
public:
    hkReferencedObject* m_pRetainedObject;

    ~hkRefPtrE_blk_00e20000_o2();
};
#include "../../include/hkTypeIsClass.h"

#include "../../include/hkBool.h"
#include "../../include/hkRotation.h"
#include "../../include/hkStringPtr.h"
#include "../../include/hkpTyremarksInfo.h"

// These small operations were inline in this unit's original class definitions.
template <class T> __forceinline void hkMemoryAllocator::_bufFree(void* p, int numElem)
{
    bufFree(p, numElem * sizeof(T));
}
inline V4::V4() {}
inline float& V4::operator()(int i) { return ((float*)&q)[i]; }
inline void V4::setZero() { q = _mm_setzero_ps(); }
inline void V4::setZero4() { q = _mm_setzero_ps(); }

// hkMemoryAllocator's shared declarations are nonvirtual; preserve the runtime slot.
__forceinline void FreeAudioArray(hkMemoryAllocator* allocator, void* memory, unsigned int size) throw()
{
    typedef void (__thiscall* FreeFunction)(hkMemoryAllocator*, void*, unsigned int);
    reinterpret_cast<FreeFunction>((*reinterpret_cast<void***>(allocator))[4])(allocator, memory, size);
}

// @fnv 0x00e30f20
int __cdecl PackBitFields(int a, int aiMiddleBits, int aiHighBits)
{
    return (((aiHighBits << 4) | aiMiddleBits) << 1) << 1 | a;
}

extern void* DAT_011be488[];

// @fnv 0x00e30f50
void __cdecl CallHandlerByIndex(int iHandlerIndex, int b, int c)
{
    ((void (*)(int, int))DAT_011be488[iHandlerIndex])(b, c);
}

struct FUN_00e39e60_class
{
    int ComputeIndex(int param);
};

// @fnv 0x00e39e60
int FUN_00e39e60_class::ComputeIndex(int aiOffset)
{
    return (((*reinterpret_cast<const int*>(this + 8)) + aiOffset) % *reinterpret_cast<const int*>(this + 12)) * 32 +
           *reinterpret_cast<const int*>(this + 16);
}

struct FUN_00e3f340_Class
{
    int __thiscall FindEntryByKey(int arg);
    void* __thiscall GetEntryByArg(int arg);
};

// @fnv 0x00e3f340
void* __thiscall FUN_00e3f340_Class::GetEntryByArg(int arg)
{
    int index = FindEntryByKey(arg);
    if (index != -1)
    {
        void* entry = *(void**)(*(char**)((char*)this + 8) + index * 8 + 4);
        return (void*)((unsigned int)entry & ~1u);
    }
    return 0;
}

struct FUN_00e3f900_class
{
    int __thiscall ReturnSelf(int a);
    int __thiscall ProcessAndReturnValue_00e3f900(int a);
};

// @fnv 0x00e3f900
// src: GUESS 0x00e3f900 (confidence: low)
int __thiscall FUN_00e3f900_class::ProcessAndReturnValue_00e3f900(int a)
{
    ReturnSelf(a);
    return (int)this;
}

// @fnv 0x00e30f40
// src: HAVOK_LIB 0x00e30f40
int __cdecl hkaSplineCompressedAnimation_packMaskAndQuantizationType(int a, int b)
{
    return ((unsigned char)b << 1) | (unsigned char)a;
}

struct S_00df8990_Obj;
extern void(__cdecl* DAT_0126ec04)(void*, void*, S_00df8990_Obj*);
void __cdecl Runtime_ProcessEntries_00e2b9b0(void*, void*, S_00df8990_Obj*);
// @fnv 0x00e2ba90
// src: GUESS 0x00e2ba90 (confidence: low)
void __cdecl Runtime_SetDAT0126ec04()
{
    DAT_0126ec04 = Runtime_ProcessEntries_00e2b9b0;
}

extern int DAT_010eb3b8[];
extern int DAT_010eb3d0[];
int __cdecl hkaSplineCompressedAnimation_handleEndianQuaternion(int a, int b);

// @fnv 0x00e31010
void __cdecl AlignAndAdvance(char flags, int aiCount, int aiIndex, int* p)
{
    if (!flags)
        return;

    int align = DAT_010eb3b8[aiIndex];
    *p = (*p + align - 1) & ~(align - 1);

    if (flags & 0xf0)
    {
        if (aiCount < 0)
            return;
        int count = aiCount + 1;
        do
        {
            hkaSplineCompressedAnimation_handleEndianQuaternion(aiIndex, *p);
            *p += DAT_010eb3d0[aiIndex];
            count--;
        } while (count);
    }
    else
    {
        hkaSplineCompressedAnimation_handleEndianQuaternion(aiIndex, *p);
        *p += DAT_010eb3d0[aiIndex];
    }
}

extern int DAT_010eb770;
struct FUN_00e34800
{
    int vtbl;
    int a;
    int b;
    int c;
    void __thiscall m(int);
    FUN_00e34800(int x);
};
// @fnv 0x00e34800
FUN_00e34800::FUN_00e34800(int aiValue)
{
    vtbl = (int)&DAT_010eb770;
    ((FUN_00e34800*)((char*)this + 0xc))->m(aiValue);
}

struct CB2FC0Object
{
    void __thiscall hkRotation_set(void*);
};
struct FUN_00e3b4d0_Class
{
    void __thiscall ApplyToBothObjects(void* a, void* b);
};
// Calls FUN_00cb2d90 on the object at this+0x20 with a and on the object at this+0x50 with b.
// @fnv 0x00e3b4d0
void __thiscall FUN_00e3b4d0_Class::ApplyToBothObjects(void* a, void* b)
{
    ((CB2FC0Object*)(this + 0x20))->hkRotation_set(a);
    ((CB2FC0Object*)(this + 0x50))->hkRotation_set(b);
}

int __cdecl CompareStringsCaseInsensitive(int, int);

struct FUN_00e3ec30_Class
{
    int __thiscall ProcessEntries_00e3ec30(int arg);
};

// @fnv 0x00e3ec30
// src: GUESS 0x00e3ec30 (confidence: low)
int FUN_00e3ec30_Class::ProcessEntries_00e3ec30(int arg)
{
    if (!arg)
        return 0;
    for (int i = 0; i < *(int*)((char*)this + 0x2c); ++i)
    {
        int* p = *(int**)((char*)this + 0x28);
        int pEntry = p[i];
        int eax = *(int*)(pEntry + 0x14);
        if ((eax & 0xfffffffe) != 0)
        {
            eax &= 0xfffffffe;
            if (CompareStringsCaseInsensitive(eax, arg) == 0)
                return pEntry;
        }
    }
    return 0;
}

struct D481D0RefVariant
{
    void set(void*, const void*);
};
struct FUN_00e3f8d0_class
{
    void Set_Thunk(void* a, const void* b);
};
// @fnv 0x00e3f8d0
// src: GUESS 0x00e3f8d0 (confidence: medium)
void FUN_00e3f8d0_class::Set_Thunk(void* a, const void* b)
{
    ((D481D0RefVariant*)((char*)this + 4))->set(a, b);
}

struct FUN_00e29620_class
{
    void __thiscall ProcessEntries_00e29620(int param);
};

// @fnv 0x00e298f0
// src: GUESS 0x00e298f0 (confidence: low)
void __cdecl Runtime_ForwardCall_00e298f0(FUN_00e29620_class* object, int param)
{
    object->ProcessEntries_00e29620(param);
}

struct SplitChunk
{
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
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
};

// @fnv 0x00e2aa70
void __cdecl InitSplitChunks(int a1, int aiTotal, int a3, int a4, int a5, SplitChunk* out)
{
    if (a5 > aiTotal)
    {
        a5 = aiTotal;
    }
    int n = a5;
    int q = aiTotal / n;
    out->unk10 = a4;
    out->unk50 = a1;
    out->unk54 = a3;
    out->unk58 = 0;
    out->unk5c = q;
    if (n > 1)
    {
        int bnd = q;
        int* e = &out[1].unk5c;
        int cnt = n - 1;
        do
        {
            SplitChunk* p = (SplitChunk*)((char*)e - 0x5c);
            *p = *out;
            e[-1] = bnd;
            bnd += q;
            *e = bnd;
            e = (int*)((char*)e + 0x70);
            cnt--;
        } while (cnt != 0);
    }
    out[n - 1].unk5c = aiTotal;
}

struct E2baaSrc
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    signed char unk20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
};

struct E2baaDst
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    float unk14;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1A;
    unsigned char unk1B;
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
};

// Initializes an output record from a source record: sets a float, copies several source fields, and derives unk54 from src->unk20 and flag.
// @fnv 0x00e2baa0
// src: HAVOK_LIB 0x00e2baa0
E2baaDst* __cdecl setCollector(E2baaDst* out, E2baaSrc* src, int flag)
{
    out->unk14 = 1.0f;
    out->unk18 = 0;
    *(volatile int*)&out->unk24 = *(volatile int*)&src->unk30;
    int iSrc30 = src->unk30;
    *(volatile int*)&out->unk20 = (int)src;
    out->unk28 = iSrc30;
    int iSrc24 = src->unk24;
    *(volatile int*)&out->unk1C = (int)src;
    out->unk50 = iSrc24;
    int v = ((src->unk20 != 0) ? -1 : 0) & flag;
    out->unk54 = (v != 0) ? v + 0x10 : 0;
    return out;
}

struct FUN_00e2d0d0_cls;
struct E2d0Ref;
struct E2d0Node;

extern float DAT_0104da48;

struct E2d0Owner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    E2d0Ref* m_pRef30;
};

struct E2d0Ref
{
    E2d0Owner* m_pSharedOwner;
    unsigned int unk04;
    unsigned int unk08;
    E2d0Node* m_pReferencedNode;
};

struct E2d0Slot
{
    E2d0Ref* m_pReference;
    unsigned int unk04;
    float m_f08;
    int m_state0c;
};

struct E2d0Node
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    E2d0Slot m_slots[3];
    int Probe(int a, FUN_00e2d0d0_cls* self, int* out);
};

struct FUN_00e2d0d0_cls
{
    unsigned int unk00;
    int m_04;
    unsigned int unk08;
    int m_count0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    unsigned int unk3EC;
    unsigned int unk3F0;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42C;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43C;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44C;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45C;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46C;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47C;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned int unk4A0;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    unsigned int unk4B0;
    unsigned int unk4B4;
    unsigned int unk4B8;
    unsigned int unk4BC;
    unsigned int unk4C0;
    unsigned int unk4C4;
    unsigned int unk4C8;
    unsigned int unk4CC;
    unsigned int unk4D0;
    unsigned int unk4D4;
    unsigned int unk4D8;
    unsigned int unk4DC;
    unsigned int unk4E0;
    unsigned int unk4E4;
    unsigned int unk4E8;
    unsigned int unk4EC;
    unsigned int unk4F0;
    unsigned int unk4F4;
    unsigned int unk4F8;
    unsigned int unk4FC;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50C;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51C;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52C;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53C;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54C;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55C;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56C;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57C;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58C;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59C;
    unsigned int unk5A0;
    unsigned int unk5A4;
    unsigned int unk5A8;
    unsigned int unk5AC;
    unsigned int unk5B0;
    unsigned int unk5B4;
    unsigned int unk5B8;
    unsigned int unk5BC;
    unsigned int unk5C0;
    unsigned int unk5C4;
    unsigned int unk5C8;
    unsigned int unk5CC;
    unsigned int unk5D0;
    unsigned int unk5D4;
    unsigned int unk5D8;
    unsigned int unk5DC;
    unsigned int unk5E0;
    unsigned int unk5E4;
    unsigned int unk5E8;
    unsigned int unk5EC;
    unsigned int unk5F0;
    unsigned int unk5F4;
    unsigned int unk5F8;
    unsigned int unk5FC;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60C;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61C;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62C;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63C;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64C;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65C;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66C;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67C;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68C;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69C;
    unsigned int unk6A0;
    unsigned int unk6A4;
    unsigned int unk6A8;
    unsigned int unk6AC;
    unsigned int unk6B0;
    unsigned int unk6B4;
    unsigned int unk6B8;
    unsigned int unk6BC;
    unsigned int unk6C0;
    unsigned int unk6C4;
    unsigned int unk6C8;
    unsigned int unk6CC;
    unsigned int unk6D0;
    unsigned int unk6D4;
    unsigned int unk6D8;
    unsigned int unk6DC;
    unsigned int unk6E0;
    unsigned int unk6E4;
    unsigned int unk6E8;
    unsigned int unk6EC;
    unsigned int unk6F0;
    unsigned int unk6F4;
    unsigned int unk6F8;
    unsigned int unk6FC;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70C;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71C;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72C;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73C;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74C;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75C;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76C;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77C;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78C;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79C;
    unsigned int unk7A0;
    unsigned int unk7A4;
    unsigned int unk7A8;
    unsigned int unk7AC;
    unsigned int unk7B0;
    unsigned int unk7B4;
    unsigned int unk7B8;
    unsigned int unk7BC;
    unsigned int unk7C0;
    unsigned int unk7C4;
    unsigned int unk7C8;
    unsigned int unk7CC;
    unsigned int unk7D0;
    unsigned int unk7D4;
    unsigned int unk7D8;
    unsigned int unk7DC;
    unsigned int unk7E0;
    unsigned int unk7E4;
    unsigned int unk7E8;
    unsigned int unk7EC;
    unsigned int unk7F0;
    unsigned int unk7F4;
    unsigned int unk7F8;
    unsigned int unk7FC;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80C;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81C;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82C;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83C;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84C;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85C;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86C;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87C;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88C;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89C;
    unsigned int unk8A0;
    unsigned int unk8A4;
    unsigned int unk8A8;
    unsigned int unk8AC;
    unsigned int unk8B0;
    unsigned int unk8B4;
    unsigned int unk8B8;
    unsigned int unk8BC;
    unsigned int unk8C0;
    unsigned int unk8C4;
    unsigned int unk8C8;
    unsigned int unk8CC;
    unsigned int unk8D0;
    unsigned int unk8D4;
    unsigned int unk8D8;
    unsigned int unk8DC;
    unsigned int unk8E0;
    unsigned int unk8E4;
    unsigned int unk8E8;
    unsigned int unk8EC;
    unsigned int unk8F0;
    unsigned int unk8F4;
    unsigned int unk8F8;
    unsigned int unk8FC;
    unsigned int unk900;
    unsigned int unk904;
    unsigned int unk908;
    unsigned int unk90C;
    unsigned int unk910;
    unsigned int unk914;
    unsigned int unk918;
    unsigned int unk91C;
    unsigned int unk920;
    unsigned int unk924;
    unsigned int unk928;
    unsigned int unk92C;
    unsigned int unk930;
    unsigned int unk934;
    unsigned int unk938;
    unsigned int unk93C;
    unsigned int unk940;
    unsigned int unk944;
    unsigned int unk948;
    unsigned int unk94C;
    unsigned int unk950;
    unsigned int unk954;
    unsigned int unk958;
    unsigned int unk95C;
    unsigned int unk960;
    unsigned int unk964;
    unsigned int unk968;
    unsigned int unk96C;
    unsigned int unk970;
    unsigned int unk974;
    unsigned int unk978;
    unsigned int unk97C;
    unsigned int unk980;
    unsigned int unk984;
    unsigned int unk988;
    unsigned int unk98C;
    unsigned int unk990;
    unsigned int unk994;
    unsigned int unk998;
    unsigned int unk99C;
    unsigned int unk9A0;
    unsigned int unk9A4;
    unsigned int unk9A8;
    unsigned int unk9AC;
    unsigned int unk9B0;
    unsigned int unk9B4;
    unsigned int unk9B8;
    unsigned int unk9BC;
    unsigned int unk9C0;
    unsigned int unk9C4;
    unsigned int unk9C8;
    unsigned int unk9CC;
    unsigned int unk9D0;
    unsigned int unk9D4;
    unsigned int unk9D8;
    unsigned int unk9DC;
    unsigned int unk9E0;
    unsigned int unk9E4;
    unsigned int unk9E8;
    unsigned int unk9EC;
    unsigned int unk9F0;
    unsigned int unk9F4;
    unsigned int unk9F8;
    unsigned int unk9FC;
    unsigned int unkA00;
    unsigned int unkA04;
    unsigned int unkA08;
    unsigned int unkA0C;
    unsigned int unkA10;
    unsigned int unkA14;
    unsigned int unkA18;
    unsigned int unkA1C;
    unsigned int unkA20;
    unsigned int unkA24;
    unsigned int unkA28;
    unsigned int unkA2C;
    unsigned int unkA30;
    unsigned int unkA34;
    unsigned int unkA38;
    unsigned int unkA3C;
    unsigned int unkA40;
    unsigned int unkA44;
    unsigned int unkA48;
    unsigned int unkA4C;
    unsigned int unkA50;
    unsigned int unkA54;
    unsigned int unkA58;
    unsigned int unkA5C;
    unsigned int unkA60;
    unsigned int unkA64;
    unsigned int unkA68;
    unsigned int unkA6C;
    unsigned int unkA70;
    unsigned int unkA74;
    unsigned int unkA78;
    unsigned int unkA7C;
    unsigned int unkA80;
    unsigned int unkA84;
    unsigned int unkA88;
    unsigned int unkA8C;
    unsigned int unkA90;
    unsigned int unkA94;
    unsigned int unkA98;
    unsigned int unkA9C;
    unsigned int unkAA0;
    unsigned int unkAA4;
    unsigned int unkAA8;
    unsigned int unkAAC;
    unsigned int unkAB0;
    unsigned int unkAB4;
    unsigned int unkAB8;
    unsigned int unkABC;
    unsigned int unkAC0;
    unsigned int unkAC4;
    unsigned int unkAC8;
    unsigned int unkACC;
    unsigned int unkAD0;
    unsigned int unkAD4;
    unsigned int unkAD8;
    unsigned int unkADC;
    unsigned int unkAE0;
    unsigned int unkAE4;
    unsigned int unkAE8;
    unsigned int unkAEC;
    unsigned int unkAF0;
    unsigned int unkAF4;
    unsigned int unkAF8;
    unsigned int unkAFC;
    unsigned int unkB00;
    unsigned int unkB04;
    unsigned int unkB08;
    unsigned int unkB0C;
    unsigned int unkB10;
    unsigned int unkB14;
    unsigned int unkB18;
    unsigned int unkB1C;
    unsigned int unkB20;
    unsigned int unkB24;
    unsigned int unkB28;
    unsigned int unkB2C;
    unsigned int unkB30;
    unsigned int unkB34;
    unsigned int unkB38;
    unsigned int unkB3C;
    unsigned int unkB40;
    unsigned int unkB44;
    unsigned int unkB48;
    unsigned int unkB4C;
    unsigned int unkB50;
    unsigned int unkB54;
    unsigned int unkB58;
    unsigned int unkB5C;
    unsigned int unkB60;
    unsigned int unkB64;
    unsigned int unkB68;
    unsigned int unkB6C;
    unsigned int unkB70;
    unsigned int unkB74;
    unsigned int unkB78;
    unsigned int unkB7C;
    unsigned int unkB80;
    unsigned int unkB84;
    unsigned int unkB88;
    unsigned int unkB8C;
    unsigned int unkB90;
    unsigned int unkB94;
    unsigned int unkB98;
    unsigned int unkB9C;
    unsigned int unkBA0;
    unsigned int unkBA4;
    unsigned int unkBA8;
    unsigned int unkBAC;
    unsigned int unkBB0;
    unsigned int unkBB4;
    unsigned int unkBB8;
    unsigned int unkBBC;
    unsigned int unkBC0;
    unsigned int unkBC4;
    unsigned int unkBC8;
    unsigned int unkBCC;
    unsigned int unkBD0;
    unsigned int unkBD4;
    unsigned int unkBD8;
    unsigned int unkBDC;
    unsigned int unkBE0;
    unsigned int unkBE4;
    unsigned int unkBE8;
    unsigned int unkBEC;
    unsigned int unkBF0;
    unsigned int unkBF4;
    unsigned int unkBF8;
    unsigned int unkBFC;
    unsigned int unkC00;
    unsigned int unkC04;
    unsigned int unkC08;
    unsigned int unkC0C;
    unsigned int unkC10;
    unsigned int unkC14;
    unsigned int unkC18;
    unsigned int unkC1C;
    unsigned int unkC20;
    unsigned int unkC24;
    unsigned int unkC28;
    unsigned int unkC2C;
    unsigned int unkC30;
    unsigned int unkC34;
    unsigned int unkC38;
    unsigned int unkC3C;
    unsigned int unkC40;
    unsigned int unkC44;
    unsigned int unkC48;
    unsigned int unkC4C;
    unsigned int unkC50;
    unsigned int unkC54;
    unsigned int unkC58;
    unsigned int unkC5C;
    unsigned int unkC60;
    unsigned int unkC64;
    unsigned int unkC68;
    unsigned int unkC6C;
    unsigned int unkC70;
    unsigned int unkC74;
    unsigned int unkC78;
    unsigned int unkC7C;
    unsigned int unkC80;
    unsigned int unkC84;
    unsigned int unkC88;
    unsigned int unkC8C;
    unsigned int unkC90;
    unsigned int unkC94;
    unsigned int unkC98;
    unsigned int unkC9C;
    unsigned int unkCA0;
    unsigned int unkCA4;
    unsigned int unkCA8;
    unsigned int unkCAC;
    unsigned int unkCB0;
    unsigned int unkCB4;
    unsigned int unkCB8;
    unsigned int unkCBC;
    unsigned int unkCC0;
    unsigned int unkCC4;
    unsigned int unkCC8;
    unsigned int unkCCC;
    unsigned int unkCD0;
    unsigned int unkCD4;
    unsigned int unkCD8;
    unsigned int unkCDC;
    unsigned int unkCE0;
    unsigned int unkCE4;
    unsigned int unkCE8;
    unsigned int unkCEC;
    unsigned int unkCF0;
    unsigned int unkCF4;
    unsigned int unkCF8;
    unsigned int unkCFC;
    unsigned int unkD00;
    unsigned int unkD04;
    unsigned int unkD08;
    unsigned int unkD0C;
    unsigned int unkD10;
    unsigned int unkD14;
    unsigned int unkD18;
    unsigned int unkD1C;
    unsigned int unkD20;
    unsigned int unkD24;
    unsigned int unkD28;
    unsigned int unkD2C;
    unsigned int unkD30;
    unsigned int unkD34;
    unsigned int unkD38;
    unsigned int unkD3C;
    unsigned int unkD40;
    unsigned int unkD44;
    unsigned int unkD48;
    unsigned int unkD4C;
    unsigned int unkD50;
    unsigned int unkD54;
    unsigned int unkD58;
    unsigned int unkD5C;
    unsigned int unkD60;
    unsigned int unkD64;
    unsigned int unkD68;
    unsigned int unkD6C;
    unsigned int unkD70;
    unsigned int unkD74;
    unsigned int unkD78;
    unsigned int unkD7C;
    unsigned int unkD80;
    unsigned int unkD84;
    unsigned int unkD88;
    unsigned int unkD8C;
    unsigned int unkD90;
    unsigned int unkD94;
    unsigned int unkD98;
    unsigned int unkD9C;
    unsigned int unkDA0;
    unsigned int unkDA4;
    unsigned int unkDA8;
    unsigned int unkDAC;
    unsigned int unkDB0;
    unsigned int unkDB4;
    unsigned int unkDB8;
    unsigned int unkDBC;
    unsigned int unkDC0;
    unsigned int unkDC4;
    unsigned int unkDC8;
    unsigned int unkDCC;
    unsigned int unkDD0;
    unsigned int unkDD4;
    unsigned int unkDD8;
    unsigned int unkDDC;
    E2d0Node* m_pNodes[100];
    int TraverseNode(E2d0Node* a1, int a2, int* a3, E2d0Ref** a4);
};

// @fnv 0x00e2d0d0
int FUN_00e2d0d0_cls::TraverseNode(E2d0Node* apNode, int aiArg, int* piCount, E2d0Ref** papMatch)
{
    int result = 0;
    for (int i = 0; i < 3; ++i)
    {
        E2d0Ref* ref = apNode->m_slots[i].m_pReference;
        E2d0Node* node = ref->m_pReferencedNode;
        int state = node->m_slots[2].m_state0c;
        if (state == 0)
        {
            state = node->Probe(aiArg, this, &m_04);
            node->m_slots[2].m_state0c = state;
            if (state == 1)
            {
                result = this->TraverseNode(node, aiArg, piCount, papMatch);
                if (result == 2)
                    break;
                continue;
            }
            if (state == 4)
            {
                result = 2;
                break;
            }
        }
        if (state == 2)
        {
            ref->m_pSharedOwner->m_pRef30 = ref;
            ++*piCount;
            *papMatch = ref;
        }
    }
    apNode->m_slots[2].m_f08 = DAT_0104da48;
    if (m_count0c >= 100)
    {
        return 2;
    }
    m_pNodes[m_count0c] = apNode;
    ++m_count0c;
    return result;
}

inline void* operator new(unsigned int, void* p)
{
    return p;
}

hkMemoryRouter* GetMemoryRouterStub();

struct RefHolderE2
{
    void* m_ptr;
    RefHolderE2(const RefHolderE2& other);
    ~RefHolderE2();
    RefHolderE2& operator=(const RefHolderE2& other);
};

struct KeyedEntryE2
{
    float m_key;
    RefHolderE2 m_uiFilterValue;
};

// The original reserve call is 0x00c908c0, hkArrayUtil::_reserve in the shared units.
template <typename T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    if (getCapacity() < n)
    {
        int cap2 = 2 * getCapacity();
        int newCap = n < cap2 ? cap2 : n;
        hkArrayUtil::_reserve(alloc, this, newCap, sizeof(T));
    }
}

template <typename T> __forceinline void hkArrayUtil::destruct(T* p, int n, hkTypeIsClass)
{
    for (int i = 0; i < n; i++)
        p[i].~T();
}

template <typename T> __forceinline void hkArrayUtil::constructWithArray(T* dst, int n, const T* src, hkTypeIsClass)
{
    for (int i = 0; i < n; i++)
        new (dst + i) T(src[i]);
}

template <typename T> __forceinline hkArrayBase<T>& hkArrayBase<T>::copyFromArray(
    hkMemoryAllocator& kHeap, const hkArrayBase<T>& kSrc, hkTypeIsClass)
{
    const int iWas = m_iElementCount;
    const int iNow = kSrc.m_iElementCount;
    const int iShared = iNow > iWas ? iWas : iNow;
    GrowArrayCapacity(kHeap, iNow);
    hkArrayUtil::destruct(m_data + iNow, iWas - iNow, hkTypeIsClass());
    copy(m_data, kSrc.m_data, iShared);
    hkArrayUtil::constructWithArray(m_data + iShared, iNow - iShared, kSrc.m_data + iShared, hkTypeIsClass());
    m_iElementCount = iNow;
    return *this;
}

template <typename T, typename A> __forceinline hkArray<T, A>& hkArray<T, A>::operator=(const hkArray<T, A>& a)
{
    copyFromArray(GetMemoryRouterStub()->heap(), a, hkTypeIsClass());
    return *this;
}

struct FUN_00e2f680_Class
{
    RefHolderE2 m_ref;
    hkArray<KeyedEntryE2> m_entries;

    FUN_00e2f680_Class& CopyFrom(const FUN_00e2f680_Class& other);
};

// Copies the reference holder and the keyed-entry array from other into this object and returns *this.
// @fnv 0x00e2f680
FUN_00e2f680_Class& FUN_00e2f680_Class::CopyFrom(const FUN_00e2f680_Class& other)
{
    m_ref = other.m_ref;
    m_entries = other.m_entries;
    return *this;
}

class FUN_00e30f10
{
  public:
    unsigned short m_kPointA;
    unsigned char m_kPointB;
    FUN_00e30f10();
};

// @fnv 0x00e30f10
FUN_00e30f10::FUN_00e30f10() : m_kPointA(0x100), m_kPointB(0)
{}

// Map fValue from [fMin, fScaledValue] onto the 16-bit range.
// @fnv 0x00e30fb0
unsigned short NormalizeToUShort(float fMin, float fScaledValue, float fValue)
{
    return (unsigned short)((fValue - fMin) / (fScaledValue - fMin) * 65535.0);
}

// Reverses the byte order of the n-byte block at *pp for n of 2 or 4, then advances *pp by n bytes.
// @fnv 0x00e31510
void __cdecl SwapBytesAndAdvance(int iByteCount, unsigned char** ppBuffer)
{
    if (iByteCount != 1)
    {
        if (iByteCount == 2)
        {
            unsigned char* b = *ppBuffer;
            unsigned char lo = b[1];
            unsigned char hi = b[0];
            b[0] = lo;
            b[1] = hi;
        }
        else if (iByteCount == 4)
        {
            unsigned char* b = *ppBuffer;
            unsigned char t0 = b[3];
            unsigned char t3 = b[0];
            b[0] = t0;
            b[3] = t3;
            b = *ppBuffer;
            unsigned char t1 = b[2];
            unsigned char t2 = b[1];
            b[1] = t1;
            b[2] = t2;
        }
    }
    *ppBuffer += iByteCount;
}

// Fills values[0..count] with a linear interpolation from first to last, using i/count as the fraction.
// @fnv 0x00e31650
void __cdecl FillInterpolatedValues(int count, float** array, float first, float last)
{
    float* values = *array;
    *values = first;
    values[count] = last;
    int i = 1;
    if (count - 1 >= 4)
    {
        int limit = count - 3;
        int j = 3;
        do
        {
            values[i] = (float)i / (float)count * (last - first) + first;
            values[i + 1] = (float)(j - 1) / (float)count * (last - first) + first;
            values[i + 2] = (float)j / (float)count * (last - first) + first;
            values[i + 3] = (float)(i + 3) / (float)count * (last - first) + first;
            i += 4;
            j += 4;
        } while (i < limit);
    }
    if (i < count)
    {
        float* output = values + i;
        do
        {
            *output = (float)i / (float)count * (last - first) + first;
            ++output;
            ++i;
        } while (i < count);
    }
}

unsigned int __cdecl hkaSplineCompressedAnimation_handleEndianKnots(unsigned char a1, unsigned int* a2);
int __cdecl hkaSplineCompressedAnimation_handleEndianScalarControlPoints(unsigned char a1, unsigned int a2, unsigned int a3, unsigned int* a4);

// @fnv 0x00e31740
// src: GUESS 0x00e31740 (confidence: low)
void __cdecl Object_UpdateFields_00e31740(unsigned char flag, unsigned int uiValue, unsigned int* puiOut)
{
    if (flag != 0)
    {
        unsigned int r = hkaSplineCompressedAnimation_handleEndianKnots(flag, puiOut);
        hkaSplineCompressedAnimation_handleEndianScalarControlPoints(flag, r, uiValue, puiOut);
        *puiOut = (*puiOut + 3) & 0xfffffffcu;
    }
}

int __cdecl hkaSplineCompressedAnimation_handleEndianKnots(int a, int* c);
void __cdecl AlignAndAdvance(int a, int result, int b, int* c);

// @fnv 0x00e31780
// src: GUESS 0x00e31780 (confidence: low)
void __cdecl Object_UpdateFields_00e31780(int a, int b, int* c)
{
    if ((a & 0xff) != 0)
    {
        int result = hkaSplineCompressedAnimation_handleEndianKnots(a, c);
        AlignAndAdvance(a, result, b, c);
        *c = (*c + 3) & 0xfffffffc;
    }
}

// @fnv 0x00e32d90
int __cdecl FindKeyInterval(int aiLowIndex, int aiHighIndex, unsigned char key, unsigned char* aucTable)
{
    if (key >= aucTable[aiLowIndex + 1])
        return aiLowIndex;
    if (key <= aucTable[0])
        return aiHighIndex;
    int hi = aiHighIndex;
    int lo = aiLowIndex + 1;
    int mid = (lo + hi) / 2;
    for (;;)
    {
        if (aucTable[mid] <= key && key < aucTable[mid + 1])
            return mid;
        if (key < aucTable[mid])
            lo = mid;
        else
            hi = mid;
        mid = (lo + hi) / 2;
    }
}

// Writes to *pDest whether value is 0 or 1, then returns pDest.
// @fnv 0x00e32e30
unsigned char* StoreBoolFlag(unsigned char* pDest, int value)
{
    bool bIsZeroOrOne = (value == 0 || value == 1);
    *pDest = bIsZeroOrOne;
    return pDest;
}

struct FUN_00e33910_item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    bool* Test(bool* result);
};

class FUN_00e33910_cls
{
  public:
    FUN_00e33910_item* m_pItems;
    int m_uiItemCount;
    bool* AreAllItemsValid(bool* out);
};

// Iterates over m_pItems calling Test on each item; writes 0 to out and returns early if any Test fails, otherwise writes 1.
// @fnv 0x00e33910
bool* FUN_00e33910_cls::AreAllItemsValid(bool* out)
{
    bool flag;
    int i = 0;
    int off;
    if (i < m_uiItemCount)
    {
        off = 0;
        do
        {
            FUN_00e33910_item* item = (FUN_00e33910_item*)((char*)m_pItems + off);
            if (*item->Test(&flag) == 0)
            {
                *out = 0;
                return out;
            }
            off += 0x1c;
            ++i;
        } while (i < m_uiItemCount);
    }
    *out = 1;
    return out;
}

extern "C" void _ReadWriteBarrier(void);
extern int DAT_010eb770;

struct SubObj_b4888
{
    SubObj_b4888();
};

struct Base_b4888
{
    unsigned int unk00;
    unsigned short unk04;
    volatile unsigned short m_06;
    volatile unsigned int m_08;

    Base_b4888()
    {
        m_06 = 1;
        *(int**)this = &DAT_010eb770;
        m_08 = 0;
    }
};

struct FUN_00e347c0 : Base_b4888
{
    SubObj_b4888 m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;

    FUN_00e347c0();
};

// @fnv 0x00e347c0
FUN_00e347c0::FUN_00e347c0()
{
    m_10 = 0;
    m_14 = 0;
    m_18 = 0;
    _ReadWriteBarrier();
    unsigned int v = 0x80000000;
    m_1c = v;
    _ReadWriteBarrier();
    m_20 = 0;
    m_24 = 0;
    m_28 = v;
}

struct S_00e34950_Foo
{
    unsigned short unk00;
    unsigned short unk02;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;

    S_00e34950_Foo* Init();
};

// Initialises the object's fields to fixed defaults (8, 0xffff, 0.0f, 0.01f, 0.001f, 0.01f, 0.001f) and returns this.
// @fnv 0x00e34950
S_00e34950_Foo* S_00e34950_Foo::Init()
{
    unk00 = 8;
    unk02 = 0xffff;
    unk04 = 0.0f;
    unk08 = 0.01f;
    unk0c = 0.001f;
    unk10 = 0.01f;
    unk14 = 0.001f;
    return this;
}

extern int DAT_010df9f4;

class FUN_00e39a80
{
  public:
    int m_vptr00;
    unsigned short unk04;
    unsigned short m_06;
    int m_08;
    int m_0c;
    int m_10;
    float m_14;
    FUN_00e39a80();
};

// @fnv 0x00e39a80
FUN_00e39a80::FUN_00e39a80()
{
    float zero = 0.0f;
    *(volatile unsigned short*)&m_06 = 1;
    *(volatile int*)&m_vptr00 = (int)&DAT_010df9f4;
    *(volatile int*)&m_08 = 0;
    *(volatile int*)&m_0c = 0;
    *(volatile int*)&m_10 = 0x80000000;
    *(volatile float*)&m_14 = zero;
}

struct FUN_00e3a270 : hkReferencedObject
{
    int unk08;
    int unk0c;
    int m_data;
    int m_iElementCount;
    int m_iCapacityState;

    FUN_00e3a270();
    virtual void FUN_vfn0();
};

// @fnv 0x00e3a270
FUN_00e3a270::FUN_00e3a270()
{
    m_data = 0;
    m_iCapacityState = 0x80000000;
    unk0c = 0;
    unk08 = 0;
    m_iElementCount = 0;
}

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct S_00e3ae70_Item
{
    int unk00;
    int unk04;
    int unk08;
    float m_0c;
    float m_10;
};

struct S_00e3ae70_Array
{
    S_00e3ae70_Item** pBuffer;
    int iSize;
    unsigned int SimpleArrayStorage;
};

struct S_00e3ae70_cls
{
    void CollectSlotValues(unsigned int a1, unsigned int a2, S_00e3ae70_Array* pOut);
    void SetItemValues(unsigned int a1, unsigned int a2, float a3, float a4);
};

// @fnv 0x00e3ae70
void S_00e3ae70_cls::SetItemValues(unsigned int a1, unsigned int a2, float afValue1, float afValue2)
{
    S_00e3ae70_Array arr;
    arr.pBuffer = 0;
    arr.iSize = 0;
    arr.SimpleArrayStorage = 0x80000000;
    CollectSlotValues(a1, a2, &arr);
    int n = arr.iSize;
    if (n != 0)
    {
        int i = 0;
        afValue1 = afValue1 / (float)n;
        afValue2 = afValue2 / (float)n;
        if (n > 0)
        {
            do
            {
                S_00e3ae70_Item* pItem = arr.pBuffer[i];
                pItem->m_0c = afValue1;
                pItem->m_10 = afValue2;
                i++;
            } while (i < arr.iSize);
        }
    }
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    unsigned int uiCapacityFlags = arr.SimpleArrayStorage;
    arr.iSize = 0;
    if ((uiCapacityFlags & 0x80000000u) == 0)
    {
        FreeAudioArray(pAllocator, arr.pBuffer, (uiCapacityFlags & 0x3fffffff) * 4);
    }
}

extern void* DAT_010eb98c;
union ReleaseFlags
{
    int releaseHandle;
    int releaseOwner;
};
struct LinkOwner
{
    void* unk00;
    void* unk04;
    void* unk08;
    void __thiscall hkpBridgeConstraintAtom_init(void*);
};
struct FUN_00e3b060_Class
{
    void* vtable;
    int unk04;
    int unk08;
    LinkOwner links;
    FUN_00e3b060_Class* __thiscall ReleaseLinks(ReleaseFlags flags);
};
// Sets the vtable and, depending on flags, releases the link owner's handle and/or the owner itself, then returns this.
// @fnv 0x00e3b060
FUN_00e3b060_Class* FUN_00e3b060_Class::ReleaseLinks(ReleaseFlags aReleaseFlags)
{
    vtable = &DAT_010eb98c;
    LinkOwner* owner = &links;
    if (aReleaseFlags.releaseHandle)
        owner->hkpBridgeConstraintAtom_init(owner->unk08);
    if (aReleaseFlags.releaseOwner)
        owner->hkpBridgeConstraintAtom_init(this);
    return this;
}

namespace fnv_00e3b0a0 {

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
extern int DAT_010eb98c;
extern int DAT_0102e388;

struct FUN_00e3b0a0_cls
{
    int m_vptr00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    void ReleaseOwnedArrayAndResetFields();
};

// Sets the vtable, frees the data array through the audio allocator if capacity is not flagged, then resets the data pointer and capacity and sets a new vtable.
// @fnv 0x00e3b0a0
// src: GUESS 0x00e3b0a0 (confidence: medium)
void FUN_00e3b0a0_cls::ReleaseOwnedArrayAndResetFields()
{
    m_vptr00 = (int)&DAT_010eb98c;
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    unsigned int uCapBits = m_uCapBits;
    m_iArrayLength = 0;
    if ((uCapBits & 0x80000000u) == 0)
    {
        FreeAudioArray(pAllocator, m_pData, (uCapBits & 0x3fffffffu) * 48);
    }
    m_pData = 0;
    m_uCapBits = 0x80000000u;
    m_vptr00 = (int)&DAT_0102e388;
}
}  // namespace fnv_00e3b0a0

struct S_00e3c5b0_Obj
{
    int unk04;
    int unk08;
    int unk0c;
    virtual void vf0();
};
struct S_00e3c5b0_Act
{
    int unk14;
    virtual void vf1();
};
struct S_00e3c5b0_Base : S_00e3c5b0_Obj, S_00e3c5b0_Act
{
    S_00e3c5b0_Base(int type, int flag) throw();
};
struct S_00e3c5b0_Arr
{
    int* data;
    int size;
    int cap;
    S_00e3c5b0_Arr()
    {
        data = 0;
        size = 0;
        cap = (int)0x80000000;
    }
};
struct FUN_00e3c5b0 : S_00e3c5b0_Base
{
    S_00e3c5b0_Arr a;
    S_00e3c5b0_Arr b;
    S_00e3c5b0_Arr c;
    float unk3c;
    unsigned char unk40;
    FUN_00e3c5b0(float f);
};
// Initializes the base with type 0x17 and flag 4, stores f in unk3c and sets unk40 to 6.
// @fnv 0x00e3c5b0
FUN_00e3c5b0::FUN_00e3c5b0(float afValue) : S_00e3c5b0_Base(0x17, 4)
{
    unk3c = afValue;
    unk40 = 6;
}

// Scans records for the entry whose type matches the given type, returning the one at the requested occurrence index, or null if none.
// @fnv 0x00e3df60
ScriptRecord_blk_00e20000_o2* ScriptRecordList_blk_00e20000_o2::FindByTypeAndOccurrence(int type, int occurrence)
{
    int matched = 0;
    for (int index = 0; index < count; ++index)
    {
        if (records[index].type == static_cast<short>(type))
        {
            if (matched == occurrence)
            {
                return &records[index];
            }
            ++matched;
        }
    }
    return 0;
}

struct FUN_00e3dfb0_arg
{
    int value;
    unsigned short m_type;
    unsigned short unk06;
};

class FUN_00e3dfb0_cls
{
  public:
    int unk00;
    int unk04;
    int m_08;
    int unk0c;
    int unk10;
    int m_14;
    int unk18;
    int unk1c;
    int m_20;
    int unk24;
    int unk28;
    int m_2c;
    int unk30;
    int unk34;
    int m_38;

    int hkxVertexBuffer_getVertexDataPtr(FUN_00e3dfb0_arg* rec);
};

// Selects one of the object's fields based on rec->m_type and returns rec->value plus that field, or 0 for unknown types.
// @fnv 0x00e3dfb0
// src: XBOX_PDB 0x00e3dfb0
int FUN_00e3dfb0_cls::hkxVertexBuffer_getVertexDataPtr(FUN_00e3dfb0_arg* apRecord)
{
    int field;
    switch (apRecord->m_type)
    {
    case 1:
        field = m_38;
        break;
    case 2:
        field = m_2c;
        break;
    case 3:
        field = m_20;
        break;
    case 4:
    case 5:
        field = m_14;
        break;
    case 6:
    case 7:
        field = m_08;
        break;
    default:
        return 0;
    }
    return apRecord->value + field;
}

struct FUN_00e3ec00_Class
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
    FUN_00e3ec00_Class** unk28;
    int unk2c;

    int __thiscall GetTotal();
};

// Returns unk2c plus the sum of GetTotal() over the unk2c elements of unk28.
// @fnv 0x00e3ec00
int __thiscall FUN_00e3ec00_Class::GetTotal()
{
    int total = unk2c;
    int i = 0;

    if (unk2c > 0)
    {
        do
        {
            total += unk28[i]->GetTotal();
            ++i;
        } while (i < unk2c);
    }

    return total;
}

struct S_00e3ed00_Foo;

struct S_00e3ed00_Result
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

struct S_00e3ed00_List
{
    S_00e3ed00_Foo** elements;
    int count;
    int capacity;
};

struct S_00e3ed00_Foo
{
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
    S_00e3ed00_Foo** children;
    int childCount;

    S_00e3ed00_Result* __thiscall hkMemoryRouter_getInstance();
    int __thiscall AppendToTraversalList(S_00e3ed00_Foo* param1, S_00e3ed00_List* param2);
};

void __cdecl ResizeAudioStream(int param1, S_00e3ed00_List* param2, int param3);

// Appends this node to param2's list, then recurses into children until param1 is found; returns 0 on match, 1 otherwise (rolling back the append).
// @fnv 0x00e3ed00
int __thiscall S_00e3ed00_Foo::AppendToTraversalList(S_00e3ed00_Foo* pTarget, S_00e3ed00_List* pList)
{
    S_00e3ed00_Result* resultInfo = this->hkMemoryRouter_getInstance();

    if (pList->count == (pList->capacity & 0x3fffffff))
    {
        ResizeAudioStream(resultInfo->unk10, pList, 4);
    }

    S_00e3ed00_Foo** slot = pList->elements + (unsigned)pList->count;
    *(S_00e3ed00_Foo**)((char*)slot - 0) = this;
    *slot = this;

    int result = 1;
    pList->count += result;

    if (this == pTarget)
    {
        result = 0;
    }
    else
    {
        int index = 0;
        if (this->childCount > 0)
        {
            do
            {
                S_00e3ed00_Foo* child = this->children[index];
                result = child->AppendToTraversalList(pTarget, pList);
                if (!result)
                {
                    break;
                }
                ++index;
            } while (index < this->childCount);
        }

        if (result)
        {
            pList->count -= 1;
        }
    }

    return result;
}

hkMemoryRouter& GetMemoryRouter();

inline hkRefPtrE_blk_00e20000_o2::~hkRefPtrE_blk_00e20000_o2()
{
    if (m_pRetainedObject)
        m_pRetainedObject->removeReference();
    m_pRetainedObject = 0;
}

struct ReferenceCountedPointer
{
    hkReferencedObject* m_pRetainedObject;
    __forceinline ~ReferenceCountedPointer()
    {
        release();
    }
    void release()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
};

struct Pair8
{
    int unk00;
    hkStringPtr m_name;
    ~Pair8()
    {}
};

struct Elem40
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

template <class T> __forceinline void destructAll2(T* t, int n, hkTypeIsClass)
{
    for (int i = 0; i < n; ++i)
        t[i].~T();
}
__forceinline void destructAll(Elem40* t, int n)
{}
template <class T> __forceinline void destructAll(T* t, int n)
{
    destructAll2(t, n, hkTypeIsClass());
}

// hkArray<T>::~hkArray() = clearAndDeallocate() on the heap allocator (hkArray.inl: clear() destructs the elements).
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())->heap();
}
template <typename T> __forceinline void hkArrayBase<T>::clear()
{
    destructAll(m_data, m_iElementCount);
    m_iElementCount = 0;
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    clear();
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc._bufFree<T>(m_data, getCapacity());
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    clearAndDeallocate();
}
struct BaseE3EAA0
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    virtual void vf0();
    void Shutdown();
    ~BaseE3EAA0();   // 0x00e3eaa0 (was called as Shutdown)
};

struct FUN_00e3ed80 : BaseE3EAA0
{
    hkStringPtr m_14;
    ReferenceCountedPointer m_18;
    hkArray<Elem40> m_1c;
    hkArray<hkRefPtrE_blk_00e20000_o2> m_28;
    hkArray<Pair8> m_34;
    hkStringPtr m_40;
    virtual ~FUN_00e3ed80() throw();
};

// Compiler-generated member teardown: m_40, the m_34 / m_28 / m_1c arrays, m_18, m_14, then the base destructor.
// @fnv 0x00e3ed80
FUN_00e3ed80::~FUN_00e3ed80() throw()
{
}

struct E3F0F0Less
{
};

void __cdecl HeapSort(int* piFirst, int* piLast, E3F0F0Less kPred);

struct E3F0F0Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int* m_piFirst;
    int* m_piLast;

    void ProcessState_00e3f0f0();
};

// @fnv 0x00e3f0f0
// src: GUESS 0x00e3f0f0 (confidence: low)
void E3F0F0Owner::ProcessState_00e3f0f0()
{
    E3F0F0Less kPred;
    HeapSort(m_piFirst, m_piLast, kPred);
}

class BSAudio;
namespace fnv_00e3f110 {

extern int DAT_010e33dc;
BSAudio* __cdecl hkMemoryRouter_getInstance();

struct AudioRefObject
{
    void Release();
};

struct AudioSub
{
    int unk00;
    void Reset();
};

struct FUN_00e3f110_cls
{
    int m_vptr00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    AudioSub m_sub14;
    void* m_pBuf18;
    int m_iCount1c;
    unsigned int m_uCap20;
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
    AudioRefObject** m_pBuf70;
    int m_iCount74;
    unsigned int m_uCap78;
    AudioRefObject* m_p7c;

    void BaseTeardown();
    void Destroy() throw();
};

// Releases m_p7c and every element of the two reference arrays, frees their buffers via the allocator, resets m_sub14 and calls BaseTeardown.
// @fnv 0x00e3f110
void FUN_00e3f110_cls::Destroy() throw()
{
    *(volatile int*)&m_vptr00 = (int)&DAT_010e33dc;
    AudioRefObject* pRef = *(AudioRefObject* volatile*)&m_p7c;
    if (pRef != 0)
    {
        pRef->Release();
    }
    m_p7c = 0;
    hkMemoryRouter* pHolder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    int count = m_iCount74;
    AudioRefObject** pBuf = m_pBuf70;
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    for (int i = 0; i < count; i++)
    {
        if (pBuf[i] != 0)
        {
            pBuf[i]->Release();
        }
        pBuf[i] = 0;
    }
    m_iCount74 = 0;
    if ((m_uCap78 & 0x80000000u) == 0)
    {
        FreeAudioArray(pAllocator, m_pBuf70, (m_uCap78 & 0x3fffffffu) * 4);
    }
    m_pBuf70 = 0;
    m_uCap78 = 0x80000000u;
    hkMemoryRouter* pHolder2 = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
    int* pEntry = (int*)m_pBuf18;
    if (m_iCount1c > 0)
    {
        int n = m_iCount1c;
        do
        {
            if (*pEntry != 0)
            {
                ((AudioRefObject*)*pEntry)->Release();
            }
            *pEntry = 0;
            pEntry += 3;
            n--;
        } while (n != 0);
    }
    m_iCount1c = 0;
    if ((m_uCap20 & 0x80000000u) == 0)
    {
        FreeAudioArray(pAllocator2, m_pBuf18, (m_uCap20 & 0x3fffffffu) * 12);
    }
    m_pBuf18 = 0;
    m_uCap20 = 0x80000000u;
    m_sub14.Reset();
    BaseTeardown();
}
}  // namespace fnv_00e3f110

struct FUN_00e3f210_cls
{
    char m_buf[2];
    unsigned char HasDelimiter();
};

// Scans m_buf until a NUL and returns 1 if any character is <= 0x20, '=' or ';', otherwise 0.
// @fnv 0x00e3f210
unsigned char FUN_00e3f210_cls::HasDelimiter()
{
    char* p = m_buf;
    char c;
    while ((c = *p) != 0)
    {
        if (c <= 0x20 || c == '=' || c == ';')
            return 1;
        ++p;
    }
    return 0;
}

int __cdecl CompareStringsCaseInsensitive(unsigned int a, int b);

struct FUN_00e3f230_Entry
{
    unsigned int m_flagged;
    unsigned int unk04;
};

struct FUN_00e3f230_cls
{
    int unk00;
    int unk04;
    FUN_00e3f230_Entry* m_pEntries;
    int m_uiItemCount;
    int FindEntryByKey(int arg);
};

// Scans m_pEntries for the first entry whose masked key matches arg via CompareStringsCaseInsensitive, returning its index or -1.
// @fnv 0x00e3f230
int FUN_00e3f230_cls::FindEntryByKey(int arg)
{
    int i = 0;
    if (m_uiItemCount > 0)
    {
        do
        {
            unsigned int key = m_pEntries[i].m_flagged & 0xfffffffeu;
            if (CompareStringsCaseInsensitive(key, arg) == 0)
            {
                return i;
            }
            i++;
        } while (i < m_uiItemCount);
    }
    return -1;
}

namespace fnv_00e30ff0 {
extern int(__cdecl* DAT_011be4a0[])(int);

// @fnv 0x00e30ff0
// src: HAVOK_LIB 0x00e30ff0
void __cdecl hkaSplineCompressedAnimation_handleEndianQuaternion(int index, int arg)
{
    DAT_011be4a0[index](arg);
}
}  // namespace fnv_00e30ff0

int __cdecl CompareStringsCaseInsensitive(const char* pcA, const char* pcB);

struct BE3E7E0Entry
{
    unsigned int m_uiTaggedName;
    int unk04;
    int unk08;
    int unk0C;

    const char* GetName() const
    {
        return (const char*)(m_uiTaggedName & ~1u);
    }
};

class BE3E7E0Table
{
  public:
    int unk00;
    int unk04;
    BE3E7E0Entry* m_pkEntryArray;
    int m_iArrayLength;

    BE3E7E0Entry* FindEntryByName(const char* pcName);
};

// Searches the table's entries for one whose name matches pcName via CompareStringsCaseInsensitive, returning a pointer to it or null.
// @fnv 0x00e3e7e0
BE3E7E0Entry* BE3E7E0Table::FindEntryByName(const char* pcName)
{
    if (!pcName)
        return 0;
    for (int i = 0; i < m_iArrayLength; i++)
    {
        BE3E7E0Entry& kEntry = m_pkEntryArray[i];
        if (kEntry.GetName() && CompareStringsCaseInsensitive(kEntry.GetName(), pcName) == 0)
            return &kEntry;
    }
    return 0;
}

void __cdecl SetEntity();

// @fnv 0x00e36f40
// src: GUESS 0x00e36f40 (confidence: medium)
void __cdecl Object_SetEntity_Thunk()
{
    SetEntity();
}

struct FUN_00e39e80_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    float unk1C;
    float GetUnk1C_00e39e80();
};
// @fnv 0x00e39e80
// src: GUESS 0x00e39e80 (confidence: low)
float FUN_00e39e80_class::GetUnk1C_00e39e80()
{
    return unk1C;
}

struct FUN_00e3df50_Class
{
    FUN_00e3df50_Class* __thiscall ReturnSelf(int param);
};

// @fnv 0x00e3df50
// src: GUESS 0x00e3df50 (confidence: high)
FUN_00e3df50_Class* FUN_00e3df50_Class::ReturnSelf(int param)
{
    return this;
}

int __cdecl hkxVertexBuffer_getVertexDataPtr(int param_1, int* param_2);

// @fnv 0x00e3e020
// src: GUESS 0x00e3e020 (confidence: medium)
int __cdecl Object_HkxVertexBuffer_getVertexDataPtr_Thunk(int param_1, int* param_2)
{
    return hkxVertexBuffer_getVertexDataPtr(param_1, param_2);
}

struct FNVTreeNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned int taggedName;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    FNVTreeNode** children;
    int childCount;

    FNVTreeNode* __thiscall FindChildByName(const char* name);
};
// Searches children recursively for a node whose tagged name string matches name, returning the first match or 0.
// @fnv 0x00e3ec90
FNVTreeNode* __thiscall FNVTreeNode::FindChildByName(const char* pcName)
{
    if (pcName == 0)
        return 0;

    for (int i = 0; i < childCount; ++i)
    {
        FNVTreeNode* child = children[i];
        if ((child->taggedName & ~1u) != 0)
        {
            const char* pcTag = reinterpret_cast<const char*>(child->taggedName & ~1u);
            if (CompareStringsCaseInsensitive(pcTag, pcName) == 0)
                return child;
        }

        FNVTreeNode* descendant = child->FindChildByName(pcName);
        if (descendant != 0)
            return descendant;
    }
    return 0;
}

class Base
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int GetUnk0C();
};
// @fnv 0x00e3f270
// src: GUESS 0x00e3f270 (confidence: low)
int Base::GetUnk0C()
{
    return unk0C;
}

struct FUN_00e31080
{
    float f0;
    float f4;
    float f8;
    float fc;
    unsigned short w10;
    unsigned short w12;
    unsigned short w14;
    unsigned short w16;
    unsigned char b18;
    unsigned char b19;
    unsigned char b1a;
    unsigned char b1b;
    FUN_00e31080();
};
// Constructor that initializes four float fields to 0.001f, four unsigned short fields to 3, and four unsigned char fields to 1.
// @fnv 0x00e31080
FUN_00e31080::FUN_00e31080()
{
    fc = 0.001f;
    f8 = 0.001f;
    w16 = 3;
    f4 = 0.001f;
    w14 = 3;
    w12 = 3;
    f0 = 0.001f;
    w10 = 3;
    b19 = 1;
    b18 = 1;
    b1a = 1;
    b1b = 1;
}

// Checks whether mode is in the range 0 to 5, stores the result in out, and returns out.
// @fnv 0x00e32df0
bool* IsValidMode(bool* pbValid, unsigned int mode)
{
    bool r;
    if (mode == 0 || mode == 1 || mode == 2 || mode == 3 || mode == 4 || mode == 5)
        r = true;
    else
        r = false;
    *pbValid = r;
    return pbValid;
}

struct E3F290Entry
{
    int unk00;
    int unk04;
};

struct E3F290Class
{
    int unk00;
    int unk04;
    E3F290Entry* unk08;
    int __thiscall GetEntryValue(int index);
};

// @fnv 0x00e3f290
int E3F290Class::GetEntryValue(int index)
{
    return unk08[index].unk04 & ~1;
}

struct FUN_00e3f370_handle
{
    int unk00;
    void Release();
};

struct FUN_00e3f370_pair
{
    FUN_00e3f370_handle first;
    FUN_00e3f370_handle second;
};

struct FUN_00e3f370_cls
{
    int unk00;
    int unk04;
    FUN_00e3f370_pair* m_pItems;
    int m_iArrayLength;
    void ReleaseItems();
};

// @fnv 0x00e3f370
void FUN_00e3f370_cls::ReleaseItems()
{
    FUN_00e3f370_pair* p = m_pItems;
    int n = m_iArrayLength;
    for (int i = 0; i < n; i++)
    {
        p[i].second.Release();
        p[i].first.Release();
    }
    m_iArrayLength = 0;
}

// Probe for 0x00e29900: does cl 15.00.30729.01 /GL + /LTCG deliver this
// wrapper's pointer argument in EAX, so the body compiles to
//   50              push eax
//   e8 xx xx xx xx  call ?__time64@@YA_JPA_J@Z
//   83 c4 04        add esp, 4
//   c3              ret
// (original bytes at 0x00e29900: 50 e8 d4 14 0a 00 83 c4 04 c3)?
// Without /GL the cdecl stack parameter forces "mov eax,[esp+4]" first,
// which the original does not have.

__int64 __cdecl __time64(__int64* t);

// @fnv 0x00e29900
// src: GUESS 0x00e29900 (confidence: medium)
static __int64 Object___time64_Thunk(__int64* t)
{
    return __time64(t);
}

__int64* volatile g_ptr;
__int64 probe_caller(void)
{
    return Object___time64_Thunk(g_ptr);
}

typedef __int64 (*probe_fn)(void);
probe_fn volatile g_keep = probe_caller;

int main(void)
{
    g_ptr = 0;
    probe_fn f = g_keep;
    return (int)f();
}

// @fnv 0x00e2abd0
// src: COMMUNITY 0x00e2abd0
void __cdecl nullsub_333()
{
    return;
    __debugbreak();
    __debugbreak();
    __debugbreak();
    __debugbreak();
    __debugbreak();
    __debugbreak();
    __debugbreak();
    __debugbreak();
    __debugbreak();
    __debugbreak();
    __debugbreak();
    __debugbreak();
    __debugbreak();
    __debugbreak();
    __debugbreak();
}

extern "C" unsigned int be_arg_src_e2f9(void);

volatile unsigned int g_be_sink_e2f9;

// Swaps the byte order of x by writing its bytes in reverse into u and returning u.
// @fnv 0x00e2f9a0
static __declspec(noinline) unsigned int SwapByteOrder(unsigned int auiValue)
{
    unsigned int u;
    unsigned char* p = (unsigned char*)&u;
    p[0] = (unsigned char)(auiValue >> 24);
    p[1] = (unsigned char)(auiValue >> 16);
    p[2] = (unsigned char)(auiValue >> 8);
    p[3] = (unsigned char)auiValue;
    return u;
}

void call_byteswap_e2f9(void)
{
    g_be_sink_e2f9 = SwapByteOrder(be_arg_src_e2f9());
}

// Normalizes fValue between fMin and fScaledValue and scales the result to a 0-255 unsigned byte.
// @fnv 0x00e30f70
unsigned char __cdecl ScaleToByte(float fMin, float fScaledValue, float fValue)
{
    return (unsigned char)(((fValue - fMin) / (fScaledValue - fMin)) * 255.0);
}

extern "C" double __cdecl fabs(double);
inline float S00e311f0_abs(float x)
{
    float result = (float)fabs(x);
    return result;
}
struct S00e311f0_PA
{
    const V4* value;
    const V4* operator->() const
    {
        return value;
    }
};
struct S00e311f0_PB
{
    const V4* value;
    const V4* operator->() const
    {
        return value;
    }
};
struct S00e311f0_T
{
    float value;
    operator float() const
    {
        return value;
    }
};
// Compares each component of a against b, c and d within eps, setting bit 16<<i if it differs from b or c, else bit 1<<i if it differs from d.
// @fnv 0x00e311f0
// src: HAVOK_LIB 0x00e311f0
unsigned char __cdecl hkaSplineCompressedAnimation_isStatic(S00e311f0_PA apVecA, S00e311f0_PB apVecB, const V4* apVecC, S00e311f0_T eps,
                                   const V4* apVecD)
{
    unsigned char result = 0;
    for (int i = 0; i < 4; i++)
    {
        if (!(S00e311f0_abs(apVecA->f[i] - apVecB->f[i]) <= eps.value) ||
            !(S00e311f0_abs(apVecA->f[i] - apVecC->f[i]) <= eps.value))
            result |= 16 << i;
        else if (!(S00e311f0_abs(apVecA->f[i] - apVecD->f[i]) <= eps.value) ||
                 !(S00e311f0_abs(apVecA->f[i] - apVecD->f[i]) <= eps.value))
            result |= 1 << i;
    }
    return result;
}

namespace se34af0 {

// Swaps the byte order of a float value by reversing its four bytes and returns the result.
// @fnv 0x00e34af0
// src: XBOX_PDB 0x00e34af0
float delta_hkConvertEndianF32(float fValue)
{
    union
    {
        float f;
        unsigned int ui;
        unsigned char auc[4];
    } kSwap;

    kSwap.f = fValue;
    unsigned int uiBits = kSwap.ui;
    kSwap.auc[0] = (unsigned char)(uiBits >> 24);
    kSwap.auc[1] = (unsigned char)(uiBits >> 16);
    kSwap.auc[2] = (unsigned char)(uiBits >> 8);
    kSwap.auc[3] = (unsigned char)uiBits;
    return kSwap.f;
}

}

extern "C" unsigned short stub_val_e34b20(void);

// Swaps the two bytes of the input unsigned short and returns the result.
// @fnv 0x00e34b20
// src: XBOX_PDB 0x00e34b20
static __declspec(noinline) unsigned short delta_hkConvertEndianU16(unsigned short v)
{
    union SwapWordE34B20
    {
        unsigned short w;
        struct SwapBytesE34B20
        {
            unsigned char lo;
            unsigned char hi;
        } bytes;
    } u;

    u.bytes.lo = (unsigned char)(v >> 8);
    u.bytes.hi = (unsigned char)v;
    return u.w;
}

unsigned short call_e34b20()
{
    return delta_hkConvertEndianU16(stub_val_e34b20());
}

#include <xmmintrin.h>

inline hkRotation::hkRotation() {}
inline void hkVector4::setZero4() { m_vComponents = _mm_setzero_ps(); }
// hkRotation has no setZero declaration; zero its shared columns through their vector operations.
inline void ZeroRotation(hkRotation& rotation)
{
    rotation.m_kColumn0.setZero4();
    rotation.m_kColumn1.setZero4();
    rotation.m_kColumn2.setZero4();
}

struct WheelComponentParamsX
{
    float m_fSphereRadius;
};

struct FrictionDescX
{
    float m_fFrictionEqualizer, m_fMaxVelocityForPositionalFriction, m_a0, m_a1, m_a2, m_a3, m_a4, m_a5;
    float m_b0, m_b1, m_b2, m_b3, m_b4, m_b5, m_b6, m_b7;
    float m_c0, m_c1, m_c2, m_c3, m_c4, m_c5, m_c6, m_c7;
    float m_d0, m_d1, m_d2, m_d3, m_d4, m_d5, m_d6, m_d7;
    float m_e0, m_e1, m_e2, m_e3, m_e4, m_e5, m_e6, m_e7;
    float m_f0, m_f1, m_f2, m_f3, m_f4, m_f5, m_f6, m_f7;
    float m_g0, m_g1, m_g2, m_g3, m_g4, m_g5, m_g6;
};

struct FUN_00e39da0 : hkReferencedObject
{
    V4 m_kGravity;
    signed char m_iWheelCount;
    hkRotation m_kChassisOrientation;
    float m_fChassisMass;
    float m_fTorqueMax;
    float m_fTorqueMin;
    float m_fTorqueFactor;
    float m_fTorquePitchFactor;
    float m_fTorqueRollFactor;
    float m_fTorqueYawFactor;
    float m_fExtraTorqueFactor;
    float m_fChassisUnitInertiaRoll;
    float m_fChassisUnitInertiaPitch;
    float m_fChassisUnitInertiaYaw;
    hkArray<WheelComponentParamsX> m_kWheelParams;
    hkArray<signed char> m_kNumWheelsPerAxle;
    FrictionDescX m_kFrictionDescription;
    V4 m_vChassisUnitInertiaAndMassInv;
    hkBool m_bWheelsUseChassisForGround;
    FUN_00e39da0();
};
// Constructor: zeroes the gravity vector, chassis orientation, wheel count, mass and torque max, and sets fixed torque and inertia factors.
// @fnv 0x00e39da0
FUN_00e39da0::FUN_00e39da0()
{
    m_iWheelCount = 0;
    ZeroRotation(m_kChassisOrientation);
    m_fChassisMass = 0.0f;
    m_fTorqueMax = 0.0f;
    m_vChassisUnitInertiaAndMassInv.setZero4();
    m_kGravity.setZero4();
    m_fTorqueMin = 1.0f;
    m_fTorqueFactor = 0.0f;
    m_fTorquePitchFactor = 10.0f;
    m_fTorqueRollFactor = 1.0f;
    m_fTorqueYawFactor = 1.0f;
    m_fExtraTorqueFactor = 1.0f;
    m_fChassisUnitInertiaRoll = 0.0f;
    m_fChassisUnitInertiaPitch = 0.1f;
    m_bWheelsUseChassisForGround = false;
    m_fChassisUnitInertiaYaw = 30.0f;
}

struct FUN_00e39e50_cls
{
    __m128 m_v0;
    __m128 m_v1;
    FUN_00e39e50_cls* __thiscall InitializeFields_00e39e50();
};

// @fnv 0x00e39e50
// src: GUESS 0x00e39e50 (confidence: low)
FUN_00e39e50_cls* FUN_00e39e50_cls::InitializeFields_00e39e50()
{
    m_v0 = _mm_setzero_ps();
    m_v1 = _mm_setzero_ps();
    return this;
}

extern float DAT_010d0c80;

struct S3b010Links
{
    volatile unsigned short unk00;
    int unk04;
    int unk08;

    void hkpBridgeConstraintAtom_init(void* arg);
};

struct S3b010Obj
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    unsigned int unk08;
    S3b010Links m_0c;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    volatile float unk24;
    float unk28;
    float unk2c;

    void* hkpStiffSpringChainData_hkpStiffSpringChainData();
};

// Initializes S3b010Obj fields to default values and calls m_0c.FUN_00d21ce0(this) before returning this.
// @fnv 0x00e3b010
// src: HAVOK_LIB 0x00e3b010
void* S3b010Obj::hkpStiffSpringChainData_hkpStiffSpringChainData()
{
    unk06 = 1;
    unk08 = 0;
    unk00 = (void*)&DAT_010eb98c;
    m_0c.unk00 = 1;
    unk18 = 0;
    unk1c = 0;
    unk20 = 0x80000000u;
    unk24 = 0.6f;
    unk28 = 1.0f;
    unk2c = DAT_010d0c80;
    m_0c.hkpBridgeConstraintAtom_init(this);
    return this;
}

extern int DAT_010e11ec;

struct M3
{
    V4 c0;
    V4 c1;
    V4 c2;

    void setIdentity()
    {
        c0.setZero();
        c1.setZero();
        c2.setZero();
        c0(0) = 1.0f;
        c1(1) = 1.0f;
        c2(2) = 1.0f;
    }
};

struct FUN_00e3b5c0
{
    int m_vtbl00;
    unsigned short unk04;
    volatile unsigned short m_06;
    volatile int m_08;
    int m_0c;
    volatile unsigned short m_10;
    unsigned short unk12;
    int unk14;
    int unk18;
    int unk1c;
    M3 m_rot20;
    M3 m_rot50;
    unsigned short m_80;
    unsigned char m_82;
    unsigned char m_83;

    FUN_00e3b5c0();
};

// Sets the vtable pointer, stores constants in several small fields, and sets m_rot20 and m_rot50 to identity matrices.
// @fnv 0x00e3b5c0
FUN_00e3b5c0::FUN_00e3b5c0()
{
    *(int**)this = &DAT_010e11ec;
    m_06 = 1;
    m_08 = 0;
    m_10 = 4;
    m_80 = 13;
    m_rot20.setIdentity();
    m_rot50.setIdentity();
    m_82 = 0;
    m_83 = 3;
}

namespace se3b790 {

struct Cell
{
    unsigned char m_aucFlags[48];
};

struct CellInfo
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int m_iIndex;
};

struct CellArray
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    Cell* m_pkCells;
};

struct Grid
{
    int unk000;
    int unk004;
    int unk008;
    CellInfo* m_pkInfo;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    CellArray* m_pkArray;
};

inline void SetPair(Cell* pkCell, int iByte, int iPair, unsigned char ucValue)
{
    int iShift = iPair * 2;
    pkCell->m_aucFlags[iByte] =
        (pkCell->m_aucFlags[iByte] & ~(unsigned char)(3 << iShift)) | (unsigned char)(ucValue << iShift);
}

// Sets the iPair bit-pair in byte iByte of the current cell's flags to zero via SetPair.
// @fnv 0x00e3b790
// src: GUESS 0x00e3b790 (confidence: high)
void Runtime_ClearCellBitPair(Grid* pkGrid, int iByte, int iPair)
{
    Cell* pkCell = &pkGrid->m_pkArray->m_pkCells[pkGrid->m_pkInfo->m_iIndex];
    SetPair(pkCell, iByte, iPair, 0);
}

}

namespace se3d200 {

struct Mesh
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    unsigned short* m_pusIndices;

    void ProcessState_00e3cd50(int iV0, int iV1, int iV2, float fValue, int iArg0, int iArg1, int iArg2);
    void ForwardCall_00e3d200(int iTri, float fValue, int iArg0, int iArg1, int iArg2);
};

// Calls FUN_00e3cd50 with m_pusIndices[iTri], [iTri+1], [iTri+2] each multiplied by 3, then fValue and the three remaining arguments.
// @fnv 0x00e3d200
// src: GUESS 0x00e3d200 (confidence: low)
void Mesh::ForwardCall_00e3d200(int iTri, float fValue, int iArg0, int iArg1, int iArg2)
{
    ProcessState_00e3cd50(m_pusIndices[iTri] * 3, m_pusIndices[iTri + 1] * 3, m_pusIndices[iTri + 2] * 3, fValue, iArg0, iArg1,
                 iArg2);
}

}

namespace ns_e3e8 {
int __cdecl CompareStringsCaseInsensitive(const char* a, const char* b) throw();
}
struct Resource_e3e8
{
    const char* FUN_00d46d40() throw();
    void FUN_00c905b0() throw();
};

template <class T> struct hkRefPtr_e3e8
{
    T* m_pRetainedObject;
    ~hkRefPtr_e3e8() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
    }
    T* hkRefVariant_getClass() throw();
    T* val() const
    {
        return m_pRetainedObject;
    }
};

hkRefPtr_e3e8<Resource_e3e8> __stdcall FindWorldByKey(const char* name) throw();

// Finds an object by name with FindWorldByKey and returns it if expected is null or their FUN_00d46d40 strings match case-insensitively, otherwise returns null.
// @fnv 0x00e3e8e0
// src: GUESS 0x00e3e8e0 (confidence: medium)
Resource_e3e8* __stdcall Object_FindNamedWorldWithExpectedType(const char* name, Resource_e3e8* expected)
{
    if (!name)
        return 0;
    hkRefPtr_e3e8<Resource_e3e8> found = FindWorldByKey(name);
    if (found.m_pRetainedObject)
    {
        if (!expected ||
            ns_e3e8::CompareStringsCaseInsensitive(expected->FUN_00d46d40(), found.hkRefVariant_getClass()->FUN_00d46d40()) == 0)
            return found.m_pRetainedObject;
    }
    return 0;
}

struct S_00e3f280_Entry
{
    int unk00;
    int unk04;
};

struct S_00e3f280_Class
{
    int unk00;
    int unk04;
    S_00e3f280_Entry* unk08;

    int __thiscall GetMaskedValue0xfffffffe(int index);
    int __thiscall GetEntryValue(int index);
};

// @fnv 0x00e3f280
// src: GUESS 0x00e3f280 (confidence: medium)
int S_00e3f280_Class::GetMaskedValue0xfffffffe(int index)
{
    return unk08[index].unk00 & 0xfffffffe;
}

int S_00e3f280_Class::GetEntryValue(int index)
{
    return unk08[index].unk04 & 0xfffffffe;
}

struct FUN_00e22d50
{
    virtual ~FUN_00e22d50();
    void operator delete(void* p)
    {
        GetMemoryRouter().heap().blockFree(p, 0x30);
    }
};

// @fnv 0x00e22d50
FUN_00e22d50::~FUN_00e22d50()
{}


// Releases each referenced wheel object, then frees the wheel array.
// @fnv 0x00e3a360
hkpTyremarksInfo::~hkpTyremarksInfo() throw()
{
    for (int i = 0; i < m_kTyremarksWheels.m_iElementCount; i++)
        reinterpret_cast<hkReferencedObject*>(m_kTyremarksWheels.m_data[i])->removeReference();
}



struct Owner_e3f4e0 : hkReferencedObject
{
    hkArrayBase<int> m_entries;
    Owner_e3f4e0();
    virtual ~Owner_e3f4e0();
};

// Default constructor for Owner_e3f4e0 that initializes the base hkReferencedObject and the m_entries array member.
// @fnv 0x00e3f4e0
Owner_e3f4e0::Owner_e3f4e0()
{}

struct S_00df8990_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    signed char unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    unsigned char unk3c;
};
struct CastOutput
{
    int* vtable;
    float fraction;
    int shape08;
    int shape0c;
    int shape10;
    int shape14;
    int shape18;
};
struct __declspec(align(16)) CastCollector
{
    int* vtable00;
    int* vtable04;
    int* vtable08;
    int* vtable0c;
    int value10;
    float fraction14;
    unsigned char hit18;
    S_00df8990_Obj* owner1c;
    S_00df8990_Obj* owner20;
    int shape24;
    int shape28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int extra50;
    int adjusted54;
    int unk58;
    int unk5c;
    CastOutput* output60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
};
extern int DAT_010dbaf8, DAT_010dbae4, DAT_010dbad8, DAT_010dbacc, DAT_010dbb04;
void __cdecl hkKdTreeUtils_castRayIterative(void*, void*, S_00df8990_Obj*, void*, void*);
// Initializes a CastCollector from source and value, optionally fills a CastOutput, then calls FUN_00d98ca0 with the caster and source.
// @fnv 0x00e2abf0
// src: HAVOK_LIB 0x00e2abf0
void __cdecl hkTreeRayCastJobUtil_castRayKdTree(void* caster, S_00df8990_Obj* source, int value, CastOutput* output)
{
    if (caster)
    {
        CastCollector collector;
        unsigned char result;
        collector.vtable00 = &DAT_010dbaf8;
        collector.vtable04 = &DAT_010dbae4;
        collector.vtable08 = &DAT_010dbad8;
        collector.vtable0c = &DAT_010dbacc;
        collector.fraction14 = 1.0f;
        collector.hit18 = 0;
        collector.value10 = value;
        collector.owner20 = source;
        collector.owner1c = source;
        collector.shape24 = source->unk30;
        collector.shape28 = source->unk30;
        collector.extra50 = source->unk24;
        int adjusted = source->unk20 ? -1 : 0;
        adjusted &= value;
        if (adjusted)
            collector.adjusted54 = adjusted + 0x10;
        else
            collector.adjusted54 = 0;
        if (source->unk3c)
        {
            if (output)
            {
                int b = source->unk34;
                int a = source->unk30;
                output->fraction = 1.0f;
                output->vtable = &DAT_010dbb04;
                output->shape08 = a;
                output->shape0c = a;
                output->shape10 = b;
                output->shape14 = 0;
                output->shape18 = 0;
                collector.output60 = output;
            }
            else
                collector.output60 = 0;
            DAT_0126ec04 = Runtime_ProcessEntries_00e2b9b0;
        }
        else
            collector.output60 = 0;
        hkKdTreeUtils_castRayIterative(&result, caster, source, &source->unk10, &collector.vtable04);
    }
}

// @fnv 0x00e2cfc0
// src: COMMUNITY 0x00e2cfc0
void __cdecl nullsub_334()
{}

// @fnv 0x00e2cfd0
// src: GUESS 0x00e2cfd0 (confidence: high)
void Runtime_DoNothing_00e2cfd0()
{}

#include <xmmintrin.h>
namespace fnv_00e2cfe0 {
// Exe 0x00e2c8a0 FUN_00e2c8a0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_set_ss(float);
    void _mm_store_ss(float*, LocalM128);
    void _mm_store_ps(float*, LocalM128);
    float _mm_cvtss_f32(LocalM128);
    void _WriteBarrier();
}

extern const float DAT_01011d78;
extern const float DAT_01017718;
extern const float DAT_01016248;

struct PlaneScalar
{
    LocalM128 q;
    __forceinline PlaneScalar(LocalM128 value) : q(value)
    {}
    __forceinline operator float() const
    {
        float value;
        _mm_store_ss(&value, q);
        return value;
    }
    __forceinline LocalM128 splat() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};

struct PlaneVector
{
    LocalM128 q;
    __forceinline void difference(const PlaneVector& a, const PlaneVector& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    __forceinline void cross(const PlaneVector& a, const PlaneVector& b)
    {
        LocalM128 lhs = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2));
        LocalM128 rhs = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9));
        q = _mm_sub_ps(lhs, rhs);
    }
    __forceinline PlaneScalar dot(const PlaneVector& b) const
    {
        LocalM128 p = _mm_mul_ps(q, b.q);
        LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy);
    }
    __forceinline PlaneScalar inverseLength() const
    {
        LocalM128 half = _mm_set_ss(0.5f);
        LocalM128 three = _mm_set_ss(3.0f);
        LocalM128 zero = _mm_set_ss(0.0f);
        LocalM128 sum = dot(*this).q;
        LocalM128 isZero = _mm_cmpeq_ss(sum, zero);
        LocalM128 r = _mm_rsqrt_ss(sum);
        LocalM128 refined = _mm_mul_ss(_mm_mul_ss(half, r), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(sum, r), r)));
        return _mm_andnot_ps(isZero, refined);
    }
    __forceinline void normalize()
    {
        LocalM128 inv = inverseLength().splat();
        q = _mm_mul_ps(inv, q);
    }
};

struct TrianglePlane
{
    PlaneVector m_00;
    PlaneVector* m_10;
    int m_14;
    int m_18;
    int m_1c;
    PlaneVector* m_20;
    int m_24;
    int m_28;
    int m_2c;
    PlaneVector* m_30;
    int m_34;
    int m_38;
    int m_3c;
    float m_40;

    void ComputePlane();
};

// Computes the normalized plane normal from the triangle's three vertices and stores the plane constant in m_40.
// @fnv 0x00e2cfe0
void TrianglePlane::ComputePlane()
{
    PlaneVector vEdgeAB;
    PlaneVector vEdgeBC;
    PlaneVector* first = m_10;
    vEdgeAB.difference(*first, *m_20);
    vEdgeBC.difference(*m_20, *m_30);
    PlaneVector& normal = m_00;
    normal.cross(vEdgeAB, vEdgeBC);
    LocalM128 vInvLength = normal.inverseLength().splat();
    LocalM128 vScaledNormal = _mm_mul_ps(vInvLength, normal.q);
    m_00.q = vScaledNormal;
    m_40 = m_00.dot(*first);
}
}  // namespace fnv_00e2cfe0

float __cdecl Object_GetGlobalValue_00e52f40();
float __cdecl Runtime_GetField010ec960();
float __cdecl Object_GetGlobalValue_00e52f60();
float __cdecl Runtime_GetField010ec964();
float __cdecl Object_GetDAT_010ec968_00e52f80();
float __cdecl Runtime_GetDAT0104da4c();

// Returns a float value from one of six type-specific getters selected by the type argument, or 0.0f for unknown types.
// @fnv 0x00e32e50
// src: HAVOK_LIB 0x00e32e50
float __cdecl hkaSplineCompressedAnimation_TrackCompressionParams_approximateQuantizationAccuracy(int type)
{
    switch (type)
    {
    case 4:
        return Object_GetGlobalValue_00e52f40();
    case 3:
        return Runtime_GetField010ec960();
    case 0:
        return Object_GetGlobalValue_00e52f60();
    case 1:
        return Runtime_GetField010ec964();
    case 2:
        return Object_GetDAT_010ec968_00e52f80();
    case 5:
        return Runtime_GetDAT0104da4c();
    }
    return 0.0f;
}

// @fnv 0x00e32ea0
// src: GUESS 0x00e32ea0 (confidence: low)
float __cdecl Object_ComputeValue_00e32ea0(int type)
{
    switch (type)
    {
    case 0:
        return 0.0078125f;
    case 1:
        return 3.0517578125e-05f;
    }
    return 0.0f;
}

extern "C" void _ReadWriteBarrier(void);
struct Chain
{
    int unk00;
    int value;
    int unk08;
    Chain* next;
};

struct __declspec(align(16)) Node
{
    V4 vector;
    float value;
    int id;
    int unk18;
    int unk1c;
    int chainValues[12];
    Chain* tail;
    int unk54;
    int unk58;
    int unk5c;
};

template <class T> struct Cell
{
    T data;
    __forceinline Cell()
    {}
    __forceinline Cell(T item) : data(item)
    {}
    __forceinline void operator=(T item)
    {
        data = item;
    }
    __forceinline T get() const
    {
        return data;
    }
    __forceinline operator T() const
    {
        return get();
    }
    __forceinline T operator->() const
    {
        return get();
    }
};
struct Manager
{
    int unk00;
    int unk04;
    Cell<Node*> base;
    Cell<Node*> current;
    Cell<int> capacity;
    Cell<int> used;
    Cell<Chain*> tail;
};

// Copies source into a free slot of manager, or when full over the node with the largest value if source's is smaller, then records the chain's values in it.
// @fnv 0x00e2b9b0
// src: GUESS 0x00e2b9b0 (confidence: low)
void __cdecl Runtime_ProcessEntries_00e2b9b0(Chain* chain, Node* source, Manager* manager)
{
    Node* destination;

    if (manager->used < manager->capacity)
    {
        destination = manager->current;
        manager->used = manager->used + 1;
        manager->current = manager->current + 1;
    }
    else
    {
        Node* last = manager->base + 1;
        Node* identifier = manager->base;
        for (int i = 1; i < manager->used; ++i)
        {
            if (last->value > identifier->value)
                identifier = last;
            last++;
        }

        if (!(source->value < identifier->value))
            return;

        destination = identifier;
    }

    destination->value = source->value;
    destination->vector.q = source->vector.q;
    int best = source->id;
    _ReadWriteBarrier();
    destination->id = best;
    _ReadWriteBarrier();

    if (manager->tail != 0)
    {
        destination->tail = manager->tail;
    }
    else
    {
        Chain* kIter = chain;

        while (kIter->next != 0)
            kIter = kIter->next;

        destination->tail = kIter;
    }

    int iCount = 0;
    Chain* current = chain->next;

    while ((bool)current)
    {
        ++iCount;
        current = current->next;
    }

    destination->chainValues[iCount] = -1;
    for (int index = iCount - 1; index >= 0; --index)
    {
        int value = chain->value;
        _ReadWriteBarrier();
        destination->chainValues[index] = value;
        chain = chain->next;
    }
}

extern "C" void _ReadWriteBarrier();
struct PlaneIndex
{
    unsigned short value;
};
struct PackedPlane
{
    unsigned int x, y, z;
    union
    {
        unsigned int w;
        struct
        {
            unsigned short low;
            PlaneIndex left;
        };
    };
    unsigned short flags;
    PlaneIndex extra;
    PackedPlane()
    {
        flags = 0;
    }
};

struct WorkItem
{
    PackedPlane plane;
    PackedPlane* node;
    int side;
    int count;
};
struct PlaneList
{
    PackedPlane* data;
    PackedPlane* GetEntryOffset(PlaneIndex index) throw();
};
struct SplitInput
{
    int unk00, unk04, unk08, unk0c;
    PackedPlane* root;
    int unk14, unk18;
    PlaneList nodes;
};
hkMemoryRouter* hkStackMemory_getInstance() throw();
void Object_ProcessEntries_00e2c100(SplitInput*, PackedPlane*, PackedPlane*, int, int, int, int, int, float*, int*, int, int, int, int,
                  int*, int*, int*, int*, PackedPlane*, PackedPlane*) throw();
struct WorkStack
{
    WorkItem* data;
    int size;
    static __forceinline void initialize(WorkItem* ptr, int length)
    {
        for (int j = 0; j < length; ++j)
            new (ptr + j) WorkItem;
    }
    __forceinline WorkItem* expand(int amount)
    {
        int old = size;
        size = old + amount;
        initialize(data + old, size - old);
        return data + old;
    }
};
// hkLocalArray<T> (Havok 7.1 hkLocalArray.h: hkArray<T> + T* m_localMemory) as FUN_00e2cc30 fills it by hand. A plain
// layout of hkArray's fields: deriving from the shared hkArrayBase reorders the WorkItem copy stores in expand().
template <class T> struct FUN_00e2cc30_LocalArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T* localMemory;
    __forceinline void ClearAndRelease()
    {
        reinterpret_cast<hkArrayBase<T>*>(this)->_clearAndDeallocate(GetMemoryRouter().heap());
    }
};
typedef FUN_00e2cc30_LocalArray<float> WeightArray;
struct WorkArray : FUN_00e2cc30_LocalArray<WorkItem>
{
    static __forceinline void initialize(WorkItem* ptr, int length)
    {
        for (int j = 0; j < length; ++j)
            new (ptr + j) WorkItem;
    }
    __forceinline WorkItem* expand(int amount)
    {
        int old = m_iElementCount;
        m_iElementCount = old + amount;
        initialize(m_data + old, m_iElementCount - old);
        return m_data + old;
    }
};
// Splits indices 0..count-1 using a work stack of plane nodes, calling FUN_00e2c100 on each popped item and pushing non-empty left and right results.
// @fnv 0x00e2cc30
// src: HAVOK_LIB 0x00e2cc30
void hkAabbTreeRayCastUtil_struct_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_castRayFiltering(SplitInput* input, int a2, int a3, int a4, int a5, int a6, int count)
{
    if (!input)
        return;
    hkMemoryRouter* router = hkMemoryRouter_getInstance();
    WeightArray weightArray;
    float* weights = (float*)router->m_stack.m_next.m_storage;
    weightArray.m_data = weights;
    weightArray.localMemory = weights;
    router->m_stack.m_next.m_storage = (void*)((int)weights + ((count * 4 + 127) & -128));
    weightArray.m_iElementCount = count;
    weightArray.m_iCapacityState = count | 0x80000000;
    for (int i = 0; i < count; ++i)
        weights[i] = 1.0f;
    hkStackMemory_getInstance();
    int populations[2] = {0, 0};
    int& usedA = populations[0];
    int& usedB = populations[1];
    hkStackMemory_getInstance();
    router = hkMemoryRouter_getInstance();
    WorkArray stack;
    WorkItem* data = (WorkItem*)router->m_stack.m_next.m_storage;
    stack.m_data = data;
    stack.localMemory = data;
    router->m_stack.m_next.m_storage = (void*)((int)data + 384);
    int iMaxDepth = 0;
    stack.m_iElementCount = 0;
    stack.m_iCapacityState = 10 | 0x80000000;
    WorkItem* root = stack.expand(1);
    root->plane = *input->root;
    root->node = 0;
    root->side = 0;
    root->count = count;
    int indices[2][250];
    for (int i = 0; i < count; ++i)
        indices[0][usedA++] = i;

    WorkItem item;
    do
    {
        item = stack.m_data[stack.m_iElementCount - 1];
        --stack.m_iElementCount;

        PackedPlane desc = item.plane;
        PackedPlane children[2];
        int leftCount, rightCount;
        populations[item.side] -= item.count;
        Object_ProcessEntries_00e2c100(input, &desc, item.node, a2, a5, a6, a3, a4, weights, indices[item.side] + populations[item.side],
                     item.count, 10 - stack.m_iElementCount, 250 - usedA, 250 - usedB, indices[0] + usedA, &leftCount,
                     indices[1] + usedB, &rightCount, &children[0], &children[1]);
        usedA += leftCount;
        usedB += rightCount;
        if (leftCount)
        {

            WorkItem* next = stack.expand(1);
            next->plane = children[0];
            next->node = input->nodes.GetEntryOffset(desc.left);
            next->side = 0;
            next->count = leftCount;
        }
        _ReadWriteBarrier();
        if (rightCount)
        {

            WorkItem* next = stack.expand(1);
            next->plane = children[1];
            next->node = desc.extra.value != 0x7fff ? input->nodes.GetEntryOffset(desc.extra) : 0;
            next->side = 1;
            next->count = rightCount;
        }
        if (iMaxDepth <= stack.m_iElementCount)
            iMaxDepth = stack.m_iElementCount;
    } while (stack.m_iElementCount);
    hkMemoryRouter_getInstance()->m_stack.m_next.m_storage = (void*)((int)stack.localMemory);
    stack.ClearAndRelease();
    hkMemoryRouter_getInstance()->m_stack.m_next.m_storage = (void*)((int)weightArray.localMemory);
    weightArray.ClearAndRelease();
}

#include <xmmintrin.h>
namespace fnv_00e2c8a0 {
// Exe 0x00e2c8a0 FUN_00e2c8a0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;

struct ShortIndex
{
    unsigned short value;
};
// AABB node: min/max quads then flags and 16-bit indices at +0x20..+0x26 (the 32-byte shared Bounds has none).
struct IndexedAabbNode
{
    LocalM128 a;
    LocalM128 b;
    union
    {
        int f20;
        struct
        {
            unsigned short low20;
            ShortIndex index22;
        };
    };
    unsigned short f24;
    ShortIndex index26;
    __forceinline void assign(const IndexedAabbNode& rhs) throw()
    {
        a = rhs.a;
        b = rhs.b;
        f20 = rhs.f20;
        f20 = rhs.f20;
        f24 = rhs.f24;
        index26 = rhs.index26;
    }
    __forceinline void copy(const IndexedAabbNode& rhs) throw()
    {
        a = rhs.a;
        b = rhs.b;
        f20 = rhs.f20;
        f24 = rhs.f24;
        index26 = rhs.index26;
    }
};
struct Item
{
    IndexedAabbNode bounds;
    int* data;
    int kind;
    int count;
    int unk3c;
};
struct InitItem : Item
{
    __forceinline InitItem() throw()
    {
        bounds.f24 = 0;
    }
};
struct IndexLookup
{
    int* GetElementAddress_00d1bb40(ShortIndex) throw();
};
struct Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    IndexedAabbNode* bounds;
    int unk14;
    int unk18;
    IndexLookup lookup;
};
struct Allocator
{
    virtual void v00() = 0;
    virtual void v04() = 0;
    virtual void v08() = 0;
    virtual void v0c() = 0;
    virtual void freeBlock(void*, int) = 0;
};
struct Scratch
{
    char* top;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* allocator;
    __forceinline Allocator& heap() throw()
    {
        return *allocator;
    }
};
__forceinline Scratch* scratchRouter() throw()
{
    return (Scratch*)hkMemoryRouter_getInstance();
}
void hkStackMemory_getInstance() throw();
extern "C" __declspec(noalias) void hkCpuWorldRayCastCollector_PartitionRaysByChildBounds(Owner*, IndexedAabbNode*, int*, int, int, int, int, int, float*, int*, int, int,
                                                 int, int, int*, int*, int*, int*, IndexedAabbNode*, IndexedAabbNode*) throw();
struct __declspec(align(16)) Weights
{
    float* data;
    int size;
    int capacity;
    __forceinline Weights(int n) throw()
    {
        Scratch* s = scratchRouter();
        data = (float*)s->top;
        s->top += (n * 4 + 127) & ~127;
        capacity = n | 0x80000000;
        for (int i = 0; i < n; ++i)
            data[i] = 1.0f;
        hkStackMemory_getInstance();
    }
    __forceinline void release() throw()
    {
        scratchRouter()->top = (char*)data;
        Allocator& a = scratchRouter()->heap();
        if ((capacity & 0x80000000) == 0)
            a.freeBlock(data, (capacity & 0x3fffffff) * 4);
    }
};
__forceinline void constructItems(Item* p, int n) throw()
{
    for (int i = 0; i < n; ++i)
        new (p + i) InitItem;
}
__forceinline Item* growItems(Item* data, int old, int size) throw()
{
    int delta = size - old;
    Item* p = data + old;
    constructItems(p, delta);
    return p;
}
__forceinline Item* growAt(Item* data, int offset, int old, int size) throw()
{
    int delta = size - old;
    Item* p = (Item*)((char*)data + offset);
    constructItems(p, delta);
    return p;
}
struct Outputs
{
    IndexedAabbNode out0;
    IndexedAabbNode out1;
};
// Pops an item stack, calls FUN_00e2bbd0 on each item, and pushes non-empty first and second results until the stack is empty.
// @fnv 0x00e2c8a0
// src: XBOX_PDB 0x00e2c8a0
void hkAabbTreeRayCastUtil_hkAabbTreeData_hkAabbTreeAabb_unsigned_short_castRayFiltering(Owner* owner, int p2, int p3, int p4, int p5, int p6, int aiCount)
{
    if (!owner)
        return;
    Weights weights(aiCount);
    int counts[2] = {0, 0};
    int indices[2][250];
    hkStackMemory_getInstance();
    Scratch* scratch = scratchRouter();
    Item* stack = (Item*)scratch->top;
    scratch->top += 640;
    int highWater = 0;
    int stackSize = 1;
    new (stack) InitItem;
    Item* first = stack;
    first->bounds.assign(*owner->bounds);
    first->data = 0;
    first->kind = 0;
    first->count = aiCount;
    for (int i = 0; i < aiCount; ++i)
        indices[0][counts[0]++] = i;
    int stackBytes = sizeof(Item);
    int depth = 9;
    do
    {
        Outputs outs;
        Item current = stack[stackSize - 1];
        --stackSize;
        stackBytes -= sizeof(Item);
        IndexedAabbNode input = current.bounds;
        outs.out0.f24 = 0;
        outs.out1.f24 = 0;
        counts[current.kind] -= current.count;
        int* inputIndices = &indices[current.kind][counts[current.kind]];
        ++depth;
        int count0, count1;
        hkCpuWorldRayCastCollector_PartitionRaysByChildBounds(owner, &input, current.data, p2, p5, p6, p3, p4, weights.data, inputIndices, current.count, depth,
                     250 - counts[0], 250 - counts[1], &indices[0][counts[0]], &count0, &indices[1][counts[1]], &count1,
                     &outs.out0, &outs.out1);
        counts[0] += count0;
        const int generated1 = count1;
        counts[1] += generated1;
        if (count0)
        {
            int oldSize = stackSize;
            int oldBytes = stackBytes;
            stackBytes += sizeof(Item);
            ++stackSize;
            --depth;
            Item* next = growAt(stack, oldBytes, oldSize, stackSize);
            next->bounds.assign(outs.out0);
            next->data = owner->lookup.GetElementAddress_00d1bb40(input.index22);
            next->kind = 0;
            next->count = count0;
        }
        if (generated1)
        {
            int oldSize = stackSize;
            int oldBytes = stackBytes;
            stackBytes += sizeof(Item);
            ++stackSize;
            --depth;
            Item* next = growAt(stack, oldBytes, oldSize, stackSize);
            next->bounds.assign(outs.out1);
            next->data = input.index26.value != 0x7fff ? owner->lookup.GetElementAddress_00d1bb40(input.index26) : 0;
            next->kind = 1;
            next->count = generated1;
        }
        if (highWater <= stackSize)
            highWater = stackSize;
    } while (stackSize);
    scratchRouter()->top = (char*)stack;
    hkMemoryRouter_getInstance();
    weights.release();
}
}  // namespace fnv_00e2c8a0

namespace FanSpace {
// Exe 0x00e2c8a0 FUN_00e2c8a0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m[4];
} __m128, LocalM128;
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_rsqrt_ss(LocalM128);
extern "C" LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" LocalM128 _mm_set_ss(float);
extern "C" void _mm_store_ss(float*, LocalM128);
struct SimdScalar
{
    union
    {
        LocalM128 q;
        float values[4];
    };
    SimdScalar(LocalM128 x) : q(x)
    {}
    __forceinline operator float() const
    {
        float f;
        _mm_store_ss(&f, q);
        return f;
    }
    __forceinline LocalM128 splat() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};
struct FanVec
{
    union
    {
        LocalM128 q;
        float values[4];
    };
    __forceinline void subtract(const FanVec& a, const FanVec& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    __forceinline void cross(const FanVec& a, const FanVec& b)
    {
        LocalM128 p = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2));
        LocalM128 r = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9));
        q = _mm_sub_ps(p, r);
    }
    __forceinline SimdScalar dot(const FanVec& b) const
    {
        LocalM128 prod = _mm_mul_ps(q, b.q);
        LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod);
        return _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), xy);
    }
    __forceinline SimdScalar inverseLength() const
    {
        LocalM128 half = _mm_set_ss(0.5f);
        LocalM128 three = _mm_set_ss(3.0f);
        LocalM128 zero = _mm_set_ss(0.0f);
        LocalM128 len = dot(*this).q;
        LocalM128 mask = _mm_cmpeq_ss(len, zero);
        LocalM128 estimate = _mm_rsqrt_ss(len);
        LocalM128 val =
            _mm_mul_ss(_mm_mul_ss(half, estimate), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, estimate), estimate)));
        return _mm_andnot_ps(mask, val);
    }
    __forceinline void normalize()
    {
        q = _mm_mul_ps(inverseLength().splat(), q);
    }
};
template <class T> struct FanPad
{
    T value;
    FanPad()
    {}
    FanPad(T v) : value(v)
    {}
    __forceinline operator T() const
    {
        return val();
    }
    __forceinline T operator->() const
    {
        return value;
    }
    __forceinline void operator=(T v)
    {
        value = v;
    }
    __forceinline T val() const
    {
        return value;
    }
};
struct FanEdge;
struct FanVertex
{
    FanVec position;
    FanVec pointA;
    FanVec pointB;
    FanPad<FanEdge*> referee;
};
struct FanTriangle;
struct FanEdge
{
    FanVertex* vertex;
    FanEdge* next;
    FanEdge* twin;
    FanTriangle* triangle;
};
struct FanTriangle
{
    FanVec normal;
    FanEdge edges[3];
    float distance;
    int state;
    __forceinline int plane(const FanVec& a, const FanVec& b, const FanVec& c)
    {
        FanVec x;
        x.subtract(a, b);
        FanVec y;
        y.subtract(b, c);
        FanVec n;
        n.cross(x, y);
        if (float(n.dot(n)) == 0.0)
            return 1;
        n.normalize();
        distance = a.dot(n);
        normal.q = n.q;
        return 0;
    }
};
struct FanBuilder
{
    FanPad<float> tolerance;
    FanPad<float> previous;
    FanPad<int> numVertices;
    FanPad<int> numFree;
    FanPad<int> numTriangles;
    FanVertex vertices[55];
    FanTriangle* freeTriangles[100];
    FanTriangle triangles[100];
    __forceinline FanTriangle* allocateOne()
    {
        FanTriangle* t = &triangles[numTriangles];
        numTriangles = numTriangles + 1;
        return t;
    }
    __forceinline void allocate(int n, FanTriangle** result)
    {
        int i = 0;
        for (int f = numFree - 1; n != 0 && f >= 0; --f)
        {
            result[i++] = freeTriangles[f];
            numFree = numFree - 1;
            --n;
        }
        for (int j = 0; j < n; ++j)
        {
            FanTriangle* q = &triangles[numTriangles];
            numTriangles = numTriangles + 1;
            result[i++] = q;
        }
    }
    __forceinline int initialize(FanTriangle** t, int count, FanEdge* chain, FanVertex*& apex)
    {
        FanEdge* current = chain;
        for (int i = 0; i < count; ++i)
        {
            if (current == 0)
                return 2;
            FanTriangle* tri = t[i];
            FanTriangle* nextTri;
            if (i + 1 < count)
                nextTri = t[i + 1];
            else
                nextTri = t[0];
            tri->edges[0].triangle = tri;
            tri->edges[1].triangle = tri;
            tri->edges[2].triangle = tri;
            tri->edges[0].next = &tri->edges[1];
            tri->edges[1].next = &tri->edges[2];
            tri->edges[2].next = &tri->edges[0];
            FanVertex* a = current->next->vertex;
            FanVertex* b = current->vertex;
            tri->edges[0].vertex = a;
            tri->edges[1].vertex = b;
            tri->edges[2].vertex = apex;
            current->twin = &tri->edges[0];
            tri->edges[0].twin = current;
            nextTri->edges[1].twin = &tri->edges[2];
            tri->edges[2].twin = &nextTri->edges[1];
            if (tri->plane(a->position, b->position, apex->position))
                return 2;
            FanVertex* last = current->next->vertex;
            FanEdge* following = last->referee;
            last->referee = 0;
            current = following;
        }
        for (int j = 0; j < numTriangles; ++j)
            triangles[j].state = 0;
        for (int k = 0; k < numVertices; ++k)
            vertices[k].referee = 0;
        return chain == current ? 0 : 2;
    }
    int AllocateTriangleFan(int count, FanEdge* chain, FanVertex* apex);
};
// Allocates the requested number of triangles and initializes them into a fan around the apex vertex.
// @fnv 0x00e2d1b0
// src: GUESS 0x00e2d1b0 (confidence: medium)
int FanBuilder::AllocateTriangleFan(int count, FanEdge* chain, FanVertex* apex)
{
    FanTriangle* fresh[100];
    allocate(count, fresh);
    return initialize(fresh, count, chain, apex);
}
}

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00e2d550 {
extern "C" void _ReadWriteBarrier();
// Exe 0x00e2c8a0 FUN_00e2c8a0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

extern "C"
{
    LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
    LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
    void _mm_store_ss(float* p, LocalM128 a);
    double __cdecl fabs(double x);
}

struct HullFace;

struct HullEdge
{
    LocalM128* m_kRayStart;
    LocalM128** m_kRayEnd;
    HullEdge* m_twin;
    HullFace* m_face;
};

struct HullFace
{
    LocalM128 m_vHitNormal;
    HullEdge m_kEdges[3];
    float m_fClosestPointDistanceSquared;
    int m_uiContentCount;
};

struct HullWalker
{
    void ClearEntries();
    HullFace* WalkAdjacentHullFaces(HullFace* start);
};

// Walks from start across twin edges to neighbouring faces, stopping when no edge qualifies or the next face already has m_uiContentCount equal to 3.
// @fnv 0x00e2d550
// src: GUESS 0x00e2d550 (confidence: medium)
HullFace* HullWalker::WalkAdjacentHullFaces(HullFace* start)
{
    ClearEntries();
    HullFace* face = start;
    HullEdge* pFromEdge = 0;
    bool done = false;
    int i;
    do
    {
        if (done)
            break;
        face->m_uiContentCount = 3;
        for (i = 0; i < 3; i++)
        {
            HullEdge* edge = &face->m_kEdges[i];
            if (edge == pFromEdge)
                continue;
            LocalM128 p = *edge->m_kRayStart;
            LocalM128 n;
            (void)n;
            LocalM128 q = **edge->m_kRayEnd;
            LocalM128 vDir = _mm_sub_ps(q, p);
            LocalM128 vSq = _mm_mul_ps(vDir, vDir);
            float fLenSq;
            _mm_store_ss(&fLenSq,
                         _mm_add_ss(_mm_shuffle_ps(vSq, vSq, 0xaa), _mm_add_ss(_mm_shuffle_ps(vSq, vSq, 0x55), vSq)));
            n = face->m_vHitNormal;
            LocalM128 dy = _mm_shuffle_ps(vDir, vDir, 0xc9);
            LocalM128 nz = _mm_shuffle_ps(n, n, 0xd2);
            LocalM128 p0 = _mm_mul_ps(dy, nz);
            LocalM128 dz = _mm_shuffle_ps(vDir, vDir, 0xd2);
            LocalM128 ny = _mm_shuffle_ps(n, n, 0xc9);
            LocalM128 p1 = _mm_mul_ps(dz, ny);
            LocalM128 c = _mm_sub_ps(p0, p1);
            LocalM128 sp = _mm_mul_ps(c, p);
            float side;
            _mm_store_ss(&side, _mm_add_ss(_mm_shuffle_ps(sp, sp, 0xaa), _mm_add_ss(_mm_shuffle_ps(sp, sp, 0x55), sp)));
            if (side * (float)fabs(side) < (float)(fLenSq * -9.99999949475751e-11))
            {
                HullFace* next = edge->m_twin->m_face;
                if (!(start->m_fClosestPointDistanceSquared > 0.0f) ||
                    !(next->m_fClosestPointDistanceSquared <
                      start->m_fClosestPointDistanceSquared * 0.8999999761581421))
                {
                    pFromEdge = face->m_kEdges[i].m_twin;
                    face = next;
                    done = next->m_uiContentCount == 3;
                    break;
                }
            }
        }
    } while (i != 3);
    return face;
}
}  // namespace fnv_00e2d550

namespace fnv_00e31570 {
extern void __cdecl SwapBytesAndAdvance(int, unsigned char**);
// If flags & 0xf0, calls FUN_00e31510(2, pp), advances *pp by the byte at *pp plus the short at *pp-2 plus 3 and returns that short; otherwise returns -1.
// @fnv 0x00e31570
// src: HAVOK_LIB 0x00e31570
unsigned int __cdecl hkaSplineCompressedAnimation_handleEndianKnots(unsigned char flags, unsigned int* pp)
{
    if (flags & 0xf0)
    {
        SwapBytesAndAdvance(2, (unsigned char**)pp);
        unsigned int& p = *pp;
        unsigned int b = *(unsigned char*)p;
        unsigned int len = *(unsigned short*)(p - 2);
        p = p + b + len + 3;
        return len;
    }
    return -1;
}
}  // namespace fnv_00e31570

extern int DAT_010e00dc;

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* allocator, void* array, int capacity, int elementSize);

template <class T>
static __forceinline void TyremarkArray_initialize(hkArrayBase<T>& self);

template <class T>
static __forceinline void TyremarkArray_SetSizeAndGrow(hkArrayBase<T>& self, int count);

template <class T>
static __forceinline void TyremarkArray_initialize(hkArrayBase<T>& self)
{
        self.m_data = 0;
        self.m_iElementCount = 0;
        self.m_iCapacityState = 0x80000000;
    }

template <class T>
static __forceinline void TyremarkArray_SetSizeAndGrow(hkArrayBase<T>& self, int count)
{
        hkMemoryAllocator& allocator = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())->heap();
        int capacity = self.m_iCapacityState & 0x3fffffff;
        if (capacity < count)
        {
            int doubled = capacity * 2;
            hkArrayUtil__reserve(&allocator, (&self), count < doubled ? doubled : count, sizeof(T));
        }
        self.m_iElementCount = count;
    }

struct TyremarkWheelView : FUN_00e3a270
{
    TyremarkWheelView* FUN_00e3a270();
    void hkpTyremarksWheel_setNumPoints(int pointCount);
};

inline TyremarkWheelView* allocateTyremarkWheel()
{
    void* memory =
        reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())->heap().blockAlloc(sizeof(TyremarkWheelView));
    TyremarkWheelView* wheel = static_cast<TyremarkWheelView*>(memory);
    wheel->m_usMemSizeAndFlags = sizeof(TyremarkWheelView);
    return wheel->FUN_00e3a270();
}

struct TyremarkVehicleView
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    signed char m_iWheelCount;
};

struct TyremarkInfoView
{
    int* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    float m_fMinTyremarkPointDistance;
    float m_fMaxTyremarkPointDistance;
    hkArrayBase<TyremarkWheelView*> m_wheels;

    TyremarkInfoView* hkpTyremarksInfo_hkpTyremarksInfo(const TyremarkVehicleView* vehicle, int pointCount);
};

// Initializes the TyremarkInfoView from a TyremarkVehicleView, allocating and storing wheel views for each wheel in the vehicle.
// @fnv 0x00e3a2a0
// src: HAVOK_LIB 0x00e3a2a0
TyremarkInfoView* TyremarkInfoView::hkpTyremarksInfo_hkpTyremarksInfo(const TyremarkVehicleView* vehicle, int pointCount)
{
    m_ppVirtualMethodTable = &DAT_010e00dc;
    m_sReferenceCount = 1;
    TyremarkArray_initialize(m_wheels);
    m_fMinTyremarkPointDistance = 0.0f;
    m_fMaxTyremarkPointDistance = 0.0f;
    TyremarkArray_SetSizeAndGrow(m_wheels, vehicle->m_iWheelCount);
    for (int index = 0; index < m_wheels.m_iElementCount; ++index)
    {
        TyremarkWheelView* wheel = allocateTyremarkWheel();
        wheel->hkpTyremarksWheel_setNumPoints(pointCount);
        m_wheels.m_data[index] = wheel;
    }
    return this;
}

struct Q_cls
{
    char m_buf[2];
    __declspec(noinline) unsigned char HasDelimiter();
};

__declspec(noinline) unsigned char Q_cls::HasDelimiter()
{
    char* p = m_buf;
    char c;
    while ((c = *p) != 0)
    {
        if (c <= 0x20 || c == '=' || c == ';')
            return 1;
        ++p;
    }
    return 0;
}

struct S_Pair2b0
{
    unsigned int first;
    unsigned int second;
};

struct S_Out2b0
{
    void FUN_00d61cc0();
    void FUN_00d61df0(const char* separator);
};

extern char DAT_01021184[];
extern char DAT_01011584[];
extern char str_010ebaa4[];
extern char str_010ebaa0[];

void __cdecl WriteFormatted(S_Out2b0* out, const char* format, ...);

struct S_Class2b0
{
    int unk00;
    int unk04;
    S_Pair2b0* unk08;
    int unk0c;

    void hkxEnvironment_convertToString(S_Out2b0* param);
};

// Writes unk0c pairs from unk08 to param, formatting each with DAT_01021184 or DAT_01011584 based on Q_cls::FUN_00e3f210 and joining with str_010ebaa0.
// @fnv 0x00e3f2b0
// src: COMMUNITY 0x00e3f2b0
void S_Class2b0::hkxEnvironment_convertToString(S_Out2b0* apOut)
{
    apOut->FUN_00d61cc0();
    for (int i = 0; i < unk0c; i++)
    {
        Q_cls* first = (Q_cls*)(unk08[i].first & ~1u);
        Q_cls* second = (Q_cls*)(unk08[i].second & ~1u);
        const char* a = first->HasDelimiter() ? DAT_01021184 : DAT_01011584;
        const char* b = second->HasDelimiter() ? DAT_01021184 : DAT_01011584;
        WriteFormatted(apOut, str_010ebaa4, a, first, a, b, second, b);
        if (i < unk0c - 1)
            apOut->FUN_00d61df0(str_010ebaa0);
    }
}
