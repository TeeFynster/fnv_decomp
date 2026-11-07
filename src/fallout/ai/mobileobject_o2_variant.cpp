
// src/fallout/ai/mobileobject_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/mobileobject.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

class ExtraDismemberedLimbs;
class bhkCharacterController;
#include "../../../include/layout_support.h"
#include "../../../include/Actor.h"
#include "../../../include/BaseProcess.h"
#include "mobileobject_private/mobileobject_types_TESPackage.h"
#include "mobileobject_private/mobileobject_interface.h"
#include "../../../include/BSAudio.h"
#include "../../../include/BSSoundHandle.h"
extern TESDataHandler* g_dataHandler;
#include "mobileobject_private/mobileobject_packet.h"
bhkCharacterController* CopyCharacterControllerVector(bhkCharacterController* output, const NiPoint3& point);

struct UnkCallee
{
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4(int, int);
};
struct UnkRet
{
    char _0[16];
    UnkCallee* p10;
};
struct UnkHolder
{
    char _0[12];
    volatile int mC;
    volatile int m10;
    volatile int m14;
    UnkRet* hkMemoryRouter_getInstance();
    void UpdateState_00c72210();
};
// @fnv 0x00c72210
// src: GUESS 0x00c72210 (confidence: low)
void UnkHolder::UpdateState_00c72210()
{
    UnkRet* r = hkMemoryRouter_getInstance();
    UnkCallee* c = r->p10;
    int v = m14;
    m10 = 0;
    if ((v & (int)0x80000000) == 0)
    {
        int off = (v & 0x3fffffff) * 8;
        c->F4(mC, off);
    }
    m14 = (int)0x80000000;
    mC = 0;
}
