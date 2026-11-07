
// src/havok/physics/dynamics/constraint/util/hkpconstraintcallbackutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/util/hkpconstraintcallbackutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkMonitorStream.h"
extern DWORD DAT_0126835c;
extern LPVOID(WINAPI* DAT_00fdf044)(DWORD);
extern const char str_010d3824[];
extern const char str_010c41f8[];

unsigned __int64 __cdecl __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);



struct ListenerOwner;

class ListenerObj
{
  public:
    virtual void v00(void);
    virtual void v01(void);
    virtual void v02(void);
    virtual void v03(ListenerOwner* pEvent);
};

struct ListenerOwner;

struct ListenerArray
{
    ListenerObj** m_ppItems;
    WORD m_wCount;
};

struct ListenerOwner
{
    DWORD unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    ListenerArray m_kListeners;
};

// src: GUESS 0x00d85d40 (confidence: low)
static __declspec(noinline) void Object_ProcessEntries_00d85d40(ListenerArray* pArr)
{
    for (int i = (int)pArr->m_wCount - 1; i >= 0; i--)
    {
        if (pArr->m_ppItems[i] == 0)
        {
            pArr->m_wCount--;
            for (int j = i; j < (int)pArr->m_wCount; j++)
                pArr->m_ppItems[j] = pArr->m_ppItems[j + 1];
        }
    }
}

// Invokes v03 on each non-null listener in pOwner->m_kListeners with pOwner, logging start and end ticks, then compacts the array.
// @fnv 0x00d85ef0
// src: HAVOK_LIB 0x00d85ef0
void __cdecl hkpConstraintCallbackUtil_fireConstraintDeleted(ListenerOwner* pOwner)
{
    volatile DWORD ticks[2];
    ListenerArray* pArr = &pOwner->m_kListeners;
    int i = (int)pArr->m_wCount - 1;
    if (i >= 0)
    {
        LPVOID(WINAPI * pfnTls)(DWORD) = DAT_00fdf044;
        do
        {
            if (pArr->m_ppItems[i] != 0)
            {
                hkMonitorStream* pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
                hkMonitorStream::TimerCommand* cur = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
                if (reinterpret_cast<char*>(cur) < pBuf->m_capacityMinus16.m_storage)
                {
                    cur->m_commandAndMonitor = str_010d3824;
                    _ReadWriteBarrier();
                    ticks[0] = (DWORD)__rdtsc();
                    cur->m_time0 = ticks[0];
                    cur++;
                    pBuf->m_end.m_storage = reinterpret_cast<char*>(cur);
                }
                pArr->m_ppItems[i]->v03(pOwner);
                pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
                cur = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
                if (reinterpret_cast<char*>(cur) < pBuf->m_capacityMinus16.m_storage)
                {
                    cur->m_commandAndMonitor = str_010c41f8;
                    _ReadWriteBarrier();
                    ticks[1] = (DWORD)__rdtsc();
                    cur->m_time0 = ticks[1];
                    cur++;
                    pBuf->m_end.m_storage = reinterpret_cast<char*>(cur);
                }
            }
            i--;
        } while (i >= 0);
    }
    Object_ProcessEntries_00d85d40(pArr);
}
