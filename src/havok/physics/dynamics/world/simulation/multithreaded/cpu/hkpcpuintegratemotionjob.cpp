
// src/havok/physics/dynamics/world/simulation/multithreaded/cpu/hkpcpuintegratemotionjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/simulation/multithreaded/cpu/hkpcpuintegratemotionjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>
// Havok job: timer-wrapped step

extern DWORD DAT_0126835c;

struct S_00d943d0_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        unsigned int t = (unsigned int)__rdtsc();
        m_uiStartTicks = *(volatile unsigned int*)&t;
    }
};

struct S_00d943d0_TimerBeginListCommand : S_00d943d0_TimerCommand
{
    const char* m_pFirst;
};

struct S_00d943d0_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00d943d0_MonitorStream& GetMonitorStream()
    {
        return *(S_00d943d0_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

static inline void S_00d943d0_TimerBeginList(const char* name, const char* split)
{
    S_00d943d0_MonitorStream& mStream = S_00d943d0_MonitorStream::GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        S_00d943d0_TimerBeginListCommand* h = (S_00d943d0_TimerBeginListCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->m_pFirst = split;
        _ReadWriteBarrier();
        h->setTime();
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

static inline void S_00d943d0_Timer(const char* name)
{
    S_00d943d0_MonitorStream& mStream = S_00d943d0_MonitorStream::GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        S_00d943d0_TimerCommand* h = (S_00d943d0_TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        h->setTime();
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

struct S_00d943d0_Elem
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
};

struct S_00d943d0_Block
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
    S_00d943d0_Elem* m_pElements;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int* m_auiHeaderValues;
};

struct S_00d943d0_Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    S_00d943d0_Block* m_block;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    unsigned short m_uiValueCount;
    unsigned short m_idx;
    int m_result;
    char m_flag;
};

struct S_00d943d0_Inner
{
    int unk000;
    int unk004;
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
};

struct S_00d943d0_Ctx
{
    S_00d943d0_Inner* m_inner;
};

struct S_00d943d0_Obj
{
    void ProcessCallback(S_00d943d0_Item* a, S_00d943d0_Item* b, int c);
};

int __cdecl hkRigidMotionUtilApplyForcesAndStep(int* p1e0, int* p1d0, int* p200, int* ints, int n, int sz);
int __cdecl hkRigidMotionUtilApplyAccumulators(int* p1e0, int* p1d0, S_00d943d0_Elem* e, int* ints, int n, int sz);
void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(int a, int* ints, int n);

// Picks FUN_00d28a30 or FUN_00d29bf0 by item->m_flag to set item->m_result, calls FUN_00d1a330, then obj->ProcessCallback.
// @fnv 0x00d943d0
// src: HAVOK_LIB 0x00d943d0
void __cdecl hkCpuIntegrateMotionJob(S_00d943d0_Ctx* ctx, S_00d943d0_Obj* obj, S_00d943d0_Item* item)
{
    S_00d943d0_TimerBeginList("LtIntegrate", "StIntegrateMotions");

    unsigned int idx = item->m_idx;
    S_00d943d0_Block* pBlock = item->m_block;
    unsigned int n = item->m_uiValueCount;
    S_00d943d0_Elem* e = pBlock->m_pElements + (idx + 1);
    int* ints = pBlock->m_auiHeaderValues + idx;
    if (item->m_flag)
    {
        item->m_result =
            hkRigidMotionUtilApplyForcesAndStep(&ctx->m_inner->unk1E0, &ctx->m_inner->unk1D0, &ctx->m_inner->unk200, ints, n, 0xe0);
    }
    else
    {
        item->m_result = hkRigidMotionUtilApplyAccumulators(&ctx->m_inner->unk1E0, &ctx->m_inner->unk1D0, e, ints, n, 0xe0);
    }
    hkpEntityAabbUtil_entityBatchRecalcAabb(ctx->m_inner->unk078, ints, n);

    S_00d943d0_Timer("lt");

    obj->ProcessCallback(item, item, 0);
}
