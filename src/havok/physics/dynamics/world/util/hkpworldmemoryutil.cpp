
// src/havok/physics/dynamics/world/util/hkpworldmemoryutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/hkpworldmemoryutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00d01bc0_Node
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
    unsigned char unk24;
    unsigned char m_flags;
    bool hkpSimulationIsland_isFullyConnected();
};

struct S_00d01bc0_Iter
{
    int m_key;
    int unk04;
    S_00d01bc0_Node* m_node;
};

struct S_00d01bc0_Sink
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual bool v8(int key);
};

struct S_00d01bc0_Global
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S_00d01bc0_Sink* m_sink;
    S_00d01bc0_Sink* sink()
    {
        return m_sink;
    }
};

struct S_00d01bc0_Handler
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(S_00d01bc0_Node* node, int arg);
};

struct S_00d01bc0_Owner
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
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    unsigned int m_uiItemCount;
    void IncrementCounter();
    void hkpWorld_unlock();
    void ComputeMemoryUsage(S_00d01bc0_Iter* out);
    S_00d01bc0_Handler* hkpWorld_getMemoryWatchDog();
};

S_00d01bc0_Global* __cdecl hkMemoryRouter_getInstance();
void __cdecl PropagateStateToChildren(S_00d01bc0_Owner* owner, S_00d01bc0_Node* node);

// @fnv 0x00d01bc0
// src: HAVOK_LIB 0x00d01bc0
void __cdecl hkpWorldMemoryUtil_checkMemoryForIntegration(S_00d01bc0_Owner* pOwner)
{
    pOwner->IncrementCounter();
    unsigned int saved = pOwner->m_uiItemCount;
    S_00d01bc0_Iter iter;
    pOwner->ComputeMemoryUsage(&iter);
    if (!hkMemoryRouter_getInstance()->sink()->v8(iter.m_key))
    {
        do
        {
            unsigned char s = (iter.m_node->m_flags >> 2) & 3;
            while (s != 0)
            {
                int key = iter.m_key;
                S_00d01bc0_Node* node = iter.m_node;
                if (s != 0)
                {
                    do
                    {
                        PropagateStateToChildren(pOwner, node);
                        pOwner->ComputeMemoryUsage(&iter);
                        if (iter.m_node != node || iter.m_key != key)
                            break;
                        pOwner->m_uiItemCount >>= 1;
                    } while (iter.m_node->m_flags & 0xc);
                }
                s = (iter.m_node->m_flags >> 2) & 3;
            }
            if (!hkMemoryRouter_getInstance()->sink()->v8(iter.m_key))
            {
                S_00d01bc0_Node* node = iter.m_node;
                if (!node->hkpSimulationIsland_isFullyConnected())
                {
                    node->m_flags = (node->m_flags & 0xf7) | 4;
                }
                else
                {
                    pOwner->hkpWorld_getMemoryWatchDog()->v5(node, 0);
                    pOwner->ComputeMemoryUsage(&iter);
                }
            }
        } while (!hkMemoryRouter_getInstance()->sink()->v8(iter.m_key));
    }
    pOwner->m_uiItemCount = saved;
    pOwner->hkpWorld_unlock();
}

struct D01CE0Action
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void vfunc10();
    virtual void applyFirst();
    virtual void applySecond();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_iValueAfterFlags;
};

struct D01CE0Context
{
    int unk00;
    int unk04;
    D01CE0Action* m_pAction;
};

// Calls applyFirst when the action's state is 0 or 2, and applySecond when it is 0 or 3.
// @fnv 0x00d01ce0
void __cdecl ApplyActionPhases(D01CE0Context* context)
{
    if (context->m_pAction->m_iValueAfterFlags == 0 || context->m_pAction->m_iValueAfterFlags == 2)
        context->m_pAction->applyFirst();
    if (context->m_pAction->m_iValueAfterFlags == 0 || context->m_pAction->m_iValueAfterFlags == 3)
        context->m_pAction->applySecond();
}

struct InnerObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(void* param);
};

struct ParamObj;

struct ChildObj
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
    int m_28;
};

struct ParamObj
{
    int unk00;
    int unk04;
    ChildObj* m_08;

    InnerObj* hkpWorld_getMemoryWatchDog();
};

void __cdecl hkSetOutOfMemoryState(int value);
void __cdecl ApplyActionPhases(ParamObj* param);

// Returns early if the inner object is null; otherwise loops up to 10 times while the child's m_28 is nonzero, calling v10, FUN_00d88040 and ApplyActionPhases.
// @fnv 0x00d01df0
void __cdecl ProcessChildLoop(ParamObj* param)
{
    if (param->hkpWorld_getMemoryWatchDog() == 0)
    {
        return;
    }

    int i = 10;
    while (param->m_08->m_28 != 0)
    {
        if (i-- <= 0)
        {
            break;
        }

        InnerObj* inner = param->hkpWorld_getMemoryWatchDog();
        inner->v10(param);
        hkSetOutOfMemoryState(0);
        ApplyActionPhases(param);
    }
}

#include <windows.h>
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkMonitorStream.h"

extern "C" void _ReadWriteBarrier(void);

extern DWORD DAT_0126835c;
extern DWORD DAT_01269200;
extern DWORD DAT_00fdf044;

typedef LPVOID(WINAPI* PFN_TlsGetValue)(DWORD dwTlsIndex);

unsigned __int64 __cdecl __rdtsc(void);



class TaskObj
{
  public:
    virtual void vtbl00(void);
    virtual void vtbl04(void);
    virtual void vtbl08(void);
    virtual DWORD vtbl0C(void);
    virtual void vtbl10(DWORD arg);
    virtual void vtbl14(void);
    virtual void vtbl18(void);
    virtual void vtbl1C(void);
    virtual void vtbl20(void);
    virtual bool vtbl24(DWORD arg);
};

class Src
{
  public:
    TaskObj* GetA(void);
    TaskObj* GetB(void);
};

struct D01D20Holder
{
    DWORD unk00;
    DWORD unk04;
    DWORD unk08;
    DWORD unk0C;
    TaskObj* m_pTask;
};

// If GetA is non-null and vtbl24 returns false, records profiler ticks around a vtbl10 call, then calls FUN_00d88040(0) if DAT_01269200 is set.
// @fnv 0x00d01d20
// src: HAVOK_LIB 0x00d01d20
void __cdecl hkpWorldMemoryUtil_watchHeapMemory(Src* pSrc)
{
    volatile DWORD tick;
    if (pSrc->GetA() == 0)
    {
        return;
    }
    PFN_TlsGetValue pfnTls;
    TaskObj* pTask = pSrc->GetB();
    DWORD r = pTask->vtbl0C();
    D01D20Holder* h = (D01D20Holder*)hkMemoryRouter_getInstance();
    if (!h->m_pTask->vtbl24(r))
    {
        pfnTls = (PFN_TlsGetValue)DAT_00fdf044;
        hkMonitorStream* pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
        if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
        {
            hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
            pRec->m_commandAndMonitor = "TtWatchDog:FreeMem";
            _ReadWriteBarrier();
            tick = (DWORD)__rdtsc();
            pRec->m_time0 = tick;
            pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
        }
        TaskObj* pTask2 = pSrc->GetB();
        pTask2->vtbl10((DWORD)pSrc);
        hkMonitorStream* pBuf2 = (hkMonitorStream*)pfnTls(DAT_0126835c);
        if (pBuf2->m_end.m_storage < pBuf2->m_capacityMinus16.m_storage)
        {
            hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf2->m_end.m_storage);
            pRec->m_commandAndMonitor = "Et";
            _ReadWriteBarrier();
            tick = (DWORD)__rdtsc();
            pRec->m_time0 = tick;
            pBuf2->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
        }
    }
    if (DAT_01269200 != 0)
    {
        hkSetOutOfMemoryState(0);
    }
}
