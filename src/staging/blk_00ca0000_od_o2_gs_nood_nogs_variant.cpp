
// src/staging/blk_00ca0000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Gy /O2 /GS- /EHsc (unit src/staging/blk_00ca0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00ca0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);

extern unsigned int DAT_0126835c;
extern char DAT_010c9268[];
extern char DAT_010c41f8[];

struct CbfTimerCmd
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct CbfMonitor
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

__forceinline void cbfTimer(const char* name)
{
    CbfMonitor* stream = (CbfMonitor*)TlsGetValue(DAT_0126835c);
    CbfTimerCmd* cmd = (CbfTimerCmd*)stream->m_kRayEnd;
    if (cmd < (CbfTimerCmd*)stream->m_pCurrentCommand)
    {
        cmd->m_pCommandName = name;
        _ReadWriteBarrier();
        volatile unsigned int stamped = (unsigned int)__rdtsc();
        cmd->m_uiStartTicks = stamped;
        stream->m_kRayEnd = (char*)(cmd + 1);
    }
}

struct __declspec(align(16)) CbfRayIn
{
    float x, y, z, w;
    int m_iCachedVertexCount;
    void* m_vTo;
    int m_ten;
    int m_iFilter;
};

struct __declspec(align(16)) CbfSrc
{
    __m128 m_vFrom;
    int m_10;
    int unk14;
    int unk18;
    int unk1c;
    char unk20;
};

class CbfTarget
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void Cast(CbfRayIn* args, void* owner, int flag);
};

struct CbfOwner
{
    int unk00;
    CbfSrc* m_04;
    int m_08;
    int m_0C;
    int m_10;
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
    int m_44;
    void hkpWorldRayCaster_castRay(CbfTarget* obj, CbfSrc* src, int* p3, int p4, int p5);
};

// @fnv 0x00cbf860
// src: COMMUNITY 0x00cbf860
void CbfOwner::hkpWorldRayCaster_castRay(CbfTarget* obj, CbfSrc* src, int* p3, int p4, int p5)
{
    cbfTimer(DAT_010c9268);
    m_04 = src;
    m_0C = p5;
    m_10 = 0;
    m_08 = p3 != 0 ? (int)p3 + 0x14 : 0;
    if (src->unk20 != 0)
        m_44 = p3 != 0 ? (int)p3 + 0x10 : 0;
    else
        m_44 = 0;
    CbfRayIn local;
    __m128 from = src->m_vFrom;
    _ReadWriteBarrier();
    local.m_iCachedVertexCount = 1;
    local.m_vTo = (char*)src + 0x10;
    local.m_ten = 0x10;
    local.m_iFilter = p4;
    _mm_store_ps(&local.x, from);
    obj->Cast(&local, this, 0);
    cbfTimer(DAT_010c41f8);
}
