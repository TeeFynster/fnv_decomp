
// src/unmapped/rtlfile_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/unmapped/rtlfile.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

unsigned int gm_GetCurrentThreadId();
int BSAtomicCompareExchange(const long* lock, long zero, long owner);
void ProgramFlow();

struct FUN_0078d200_cls
{
    unsigned int m_pOwnerObject;
    unsigned int m_uiItemCount;
    bool BSSpinLock_TryLock();
};

// @fnv 0x0078d200
// src: COMMUNITY 0x0078d200
bool FUN_0078d200_cls::BSSpinLock_TryLock()
{
    __declspec(align(32)) unsigned int tid;
    bool ok = false;
    tid = gm_GetCurrentThreadId();
    if (m_pOwnerObject == tid)
    {
        m_uiItemCount = m_uiItemCount + 1;
        ok = true;
    }
    else
    {
        ok = !BSAtomicCompareExchange((const long*)this, 0, (long)tid);
        if (ok)
        {
            ProgramFlow();
            m_uiItemCount = 1;
        }
    }
    return ok;
}
