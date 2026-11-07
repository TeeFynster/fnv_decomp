
// src/gamebryo2.2/corelibs/nianimation/niflipcontroller_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nianimation/niflipcontroller.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/gamebryo2.2/corelibs/nianimation/niflipcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niflipcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../include/BSFadeNode.h"

extern "C" const void* g_011f3fd4;
const void* __cdecl NiFlipController_GetRTTI();
void* __cdecl CreateNiFlipController();

struct StaticKey
{
    StaticKey(int v);
    ~StaticKey();
    unsigned int m_00;
};

struct SlotTarget
{
    unsigned int m_00;
    bool IsNotEqual(StaticKey* k);
    bool LightRefData_IsEqual(StaticKey* k);
    void FUN_006e5cc0(SlotTarget* a);
};

class FUN_0060c120_cls
{
  public:
    unsigned int unk00;
    SlotTarget* m_04;
    unsigned short unk08;
    unsigned short m_0a;
    unsigned short m_0c;
    void NiTObjectArray_NiPointer_NiTexture_SetAt(unsigned int idx, SlotTarget* a2);
};

// @fnv 0x0060c120
// src: COMMUNITY 0x0060c120
void FUN_0060c120_cls::NiTObjectArray_NiPointer_NiTexture_SetAt(unsigned int idx, SlotTarget* a2)
{
    static StaticKey key(0);
    if (idx >= m_0a)
    {
        m_0a = (unsigned short)(idx + 1);
        if (a2->IsNotEqual(&key))
        {
            m_0c++;
        }
    }
    else
    {
        if (a2->IsNotEqual(&key))
        {
            if ((m_04 + idx)->LightRefData_IsEqual(&key))
            {
                m_0c++;
            }
        }
        else
        {
            if ((m_04 + idx)->IsNotEqual(&key))
            {
                m_0c--;
            }
        }
    }
    (m_04 + idx)->FUN_006e5cc0(a2);
}
