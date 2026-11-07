
// src/bscore/bssimplelist_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bscore/bssimplelist.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "InventoryStackRecord.h"
template class BSSimpleList<InventoryStackRecord*>;

struct MyRTTI
{
    void* m_pName;
    const MyRTTI* m_base;
};
struct MyCtrl
{
    virtual void f0();
    virtual void f1();
    virtual const MyRTTI* GetRTTI();
    char _pad[0x2C];
    MyCtrl* m_next;
};
struct MyHost
{
    char _pad[0xC];
    MyCtrl* m_pFirstNode;
    MyCtrl* NiObjectNET_GetController(const MyRTTI* pkRTTI) const;
};
// @fnv 0x00a5c570
// src: GAMEBRYO_LIB 0x00a5c570
MyCtrl* MyHost::NiObjectNET_GetController(const MyRTTI* pkRTTI) const
{
    MyCtrl* pkCtrl = m_pFirstNode;
    while (pkCtrl)
    {
        const MyRTTI* pkR = pkCtrl->GetRTTI();
        while (pkR)
        {
            if (pkR == pkRTTI)
                return pkCtrl;
            pkR = pkR->m_base;
        }
        pkCtrl = pkCtrl->m_next;
    }
    return 0;
}
