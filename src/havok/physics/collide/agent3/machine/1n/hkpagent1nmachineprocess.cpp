
// src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/Pair.h"

struct Out
{
    int res;
    int val;
};

struct Updater
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual int update(int x, int y);
};

// Copies src into dest, calling self->update and other->update for each changed component and storing results in out1 and out2.
// @fnv 0x00da4a50
// src: HAVOK_LIB 0x00da4a50
static __declspec(noinline) void extractChildShapes_00da4a50(Updater* self, int flag, Pair* dest, Pair* src, Updater* other, int y,
                                              Out* out2, Out* out1)
{
    Out** ppOut1 = &out1;
    Out* pOut1 = *ppOut1;
    int b = src->b;
    if (dest->b != b)
    {
        dest->b = b;
        pOut1->res = self->update(b, flag);
        pOut1->val = b;
    }
    int a = src->a;
    if (dest->a != a)
    {
        dest->a = a;
        out2->res = other->update(a, y);
        out2->val = a;
    }
}

void S00da4a50_Wrap(Updater* self, int flag, Pair* dest, Pair* src, Updater* other, int y, Out* out2, Out* out1)
{
    extractChildShapes_00da4a50(self, flag, dest, src, other, y, out2, out1);
}

// @fnv 0x00da4960
// src: GUESS 0x00da4960 (confidence: low)
static __declspec(noinline) int Object_ProcessAndReturnValue_00da4960(int savedValue, Out* out, Updater* obj, int value)
{
    int result = obj->update(savedValue, value);
    out->res = result;
    out->val = savedValue;
    return result;
}
extern int volatile probeSaved;
extern Out* volatile probeOut;
extern Updater* volatile probeObj;
extern int volatile probeValue;
extern int volatile probeSink;
void callProbe()
{
    probeSink = Object_ProcessAndReturnValue_00da4960(probeSaved, probeOut, probeObj, probeValue);
}

struct Entry00da4970
{
    int m_00;
    int m_04;
    int m_08;
};

struct Owner00da4970
{
    int* m_kRayEnd;
    int m_unk04;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
};

struct CParam00da4970
{
    int m_uiFilterValue;
};

extern "C" Owner00da4970* d4970_self(void);
extern "C" int d4970_a(void);
extern "C" int d4970_b(void);
extern "C" CParam00da4970 d4970_c(void);

// For each Entry00da4970 between self+0x408 and m_kRayEnd, if m_04 minus a is in range, set m_04 to that value plus b and add b minus a to m_08.
// @fnv 0x00da4970
// src: HAVOK_LIB 0x00da4970
static __declspec(noinline) void fixupPotentialContactPointers_00da4970(Owner00da4970* self, int a, int b, CParam00da4970 c)
{
    int iLimit = *(volatile int*)&c.m_uiFilterValue;
    if (self == 0)
        return;
    Entry00da4970* p = (Entry00da4970*)((char*)self + 0x408);
    if ((int*)p >= self->m_kRayEnd)
        return;
    do
    {
        int iDiff = p->m_04 - a;
        if (iDiff >= 0 && iDiff < iLimit)
        {
            p->m_04 = iDiff + b;
            p->m_08 += b - a;
        }
        ++p;
    } while ((int*)p < self->m_kRayEnd);
}

void d4970_caller(void)
{
    fixupPotentialContactPointers_00da4970(d4970_self(), d4970_a(), d4970_b(), d4970_c());
}

extern "C" void _ReadWriteBarrier();
struct DaSub
{
    Pair pair;
    void* unk08;
};
struct DaShape
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
    float unk50;
};
struct DaSource
{
    DaSub* unk00;
    DaSub* unk04;
    void* unk08;
    DaShape* unk0c;
    void* unk10;
};
struct DaDest
{
    Pair pair;
    void* unk08;
    DaSub* unk0c;
};
struct DaResult
{
    void* unk00;
    void* unk04;
    void* unk08;
    DaShape* unk0c;
    void* unk10;
};
struct DaNode
{
    void* unk00;
    void* unk04;
    void* unk08;
    DaSub* unk0c;
};
struct DaReceiver
{
    void hkTransform_setMulInverseMul(void*, void*);
};
struct DaResultArg
{
    DaResult* p;
};
void* __cdecl hkSweptTransformUtil_lerp2(void*, float, void*);
// Calls FUN_00cf1510 to fill dest+0x20 and dest+0x60, sets up dest, its node and result from source, then calls FUN_00cb22f0 on result+0x20.
// @fnv 0x00da49b0
// src: HAVOK_LIB 0x00da49b0
static __declspec(noinline) void hkAgent1nMachine_initInputAtTime(DaDest* dest, DaSource* source, void* p)
{
    DaResult* result = (DaResult*)p;
    float value = source->unk0c->unk50;
    void* first = (char*)dest + 0x20;
    hkSweptTransformUtil_lerp2((char*)source->unk00->unk08 + 0x40, value, first);
    p = (char*)dest + 0x60;
    hkSweptTransformUtil_lerp2((char*)source->unk04->unk08 + 0x40, source->unk0c->unk50, p);
    DaNode* node = (DaNode*)((char*)dest + 0x10);
    result->unk00 = dest;
    result->unk04 = node;
    result->unk10 = source->unk10;
    result->unk0c = source->unk0c;
    int b = source->unk00->pair.b;
    int a = source->unk00->pair.a;
    dest->pair.a = a;
    dest->pair.b = b;
    dest->unk0c = source->unk00;
    dest->unk08 = first;
    if (node)
    {
        _ReadWriteBarrier();
        node->unk0c = source->unk04;
        node->unk08 = p;
    }
    _ReadWriteBarrier();
    ((DaReceiver*)((char*)result + 0x20))->hkTransform_setMulInverseMul(first, p);
}
DaDest* volatile daDest;
DaSource* volatile daSource;
DaResult* volatile daResult;
void daCaller()
{
    hkAgent1nMachine_initInputAtTime(daDest, daSource, daResult);
}
