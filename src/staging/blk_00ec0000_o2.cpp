
// src/staging/blk_00ec0000_o2.cpp - STAGING unit created by stage_release.py for functions with no attributed unit
// (128 KB address window, flags from the matched neighbours). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern int DAT_010f20a8;

struct FUN_00ece2f0_cls
{
    int m_vptr;
    void FUN_00ec79a1();
    void SetVtableAndProcessState_00ece2f0();
};

// @fnv 0x00ece2f0
// src: GUESS 0x00ece2f0 (confidence: low)
void FUN_00ece2f0_cls::SetVtableAndProcessState_00ece2f0()
{
    m_vptr = (int)&DAT_010f20a8;
    FUN_00ec79a1();
}

extern "C" void __cdecl doexit(int code, int quick, int retcaller);

// @fnv 0x00eccf00
// src: COMMUNITY 0x00eccf00
extern "C" void __cdecl _c_exit(void)
{
    doexit(0, 1, 1);
}
