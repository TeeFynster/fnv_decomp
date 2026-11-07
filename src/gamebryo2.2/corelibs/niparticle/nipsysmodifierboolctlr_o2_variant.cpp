
// src/gamebryo2.2/corelibs/niparticle/nipsysmodifierboolctlr_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/niparticle/nipsysmodifierboolctlr.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../../include/NiPSysModifierBoolCtlr.h"
#include "../../../../include/NiBoolInterpolator.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/StrArr.h"
// 54-byte covered span: constructor (33 B) + 15 B int3 padding +
// 6 B static-address accessor at 0x00c31290 (nirotkey.cpp pattern).
extern NiFixedString EmptyFS;
extern void* NiPSysModifierCtlr_vtable[];

struct NiTimeController_Call
{
    void SetControllerActive();
};
struct CtlrStandin
{
    char _pad[0x38];
    NiFixedString m_s;
    void* m_p;
    CtlrStandin* NiPSysModifierCtlr_NiPSysModifierCtlr();
};
// @fnv 0x00c31260
// src: EXE 0x00c31260
CtlrStandin* CtlrStandin::NiPSysModifierCtlr_NiPSysModifierCtlr()
{
    ((NiTimeController_Call*)this)->SetControllerActive();
    *(void**)this = (void*)NiPSysModifierCtlr_vtable;
    m_s.m_kHandle = EmptyFS.m_kHandle;
    m_p = 0;
    return this;
}

extern unsigned int DAT_011f404c;
// @fnv 0x00c32c70
// src: XBOX_PDB 0x00c32c70
void __fastcall NiPSysModifierBoolCtlr_SynchronizePoseInterpolator(NiPSysModifierBoolCtlr* controller, void*, NiInterpolator* pkInterp, unsigned short usIndex)
{
    bool bValue;
    NiBoolInterpolator* pkBoolInterp;
    if (pkInterp == 0)
        pkBoolInterp = 0;
    else
        pkBoolInterp = (NiBoolInterpolator*)pkInterp->DynamicCast(&DAT_011f404c);
    controller->vf60(&bValue);
    pkBoolInterp->SetBoolValue(bValue);
}

namespace fnv_00c32d30 {
char* __cdecl _FUN_00a7d330(char const*);
extern char const* const g_012026d0_arg1;
}  // namespace fnv_00c32d30

// The base viewer-string routine is not declared in the shared base header.
void __fastcall AppendBaseModifierInfo(NiPSysModifierCtlr*, void*, StrArr*);

// @fnv 0x00c32d30
void NiPSysModifierBoolCtlr::AppendModifierInfo(StrArr* pkStrings)
{
    typedef void (__thiscall *AppendBaseInfo)(NiPSysModifierCtlr*, StrArr*);
    reinterpret_cast<AppendBaseInfo>(&AppendBaseModifierInfo)(this, pkStrings);
    char* tmp = fnv_00c32d30::_FUN_00a7d330(fnv_00c32d30::g_012026d0_arg1);
    unsigned int size = pkStrings->m_usSize;
    unsigned int maxs = pkStrings->m_usMaxSize;
    if (size >= maxs)
        pkStrings->SetSize(pkStrings->m_usGrowBy + size);
    pkStrings->SetAt(size, tmp);
}

extern const float DAT_01096324;

class C32CB0Interpolator
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual bool Update(float fTime, void* pkTarget, int& fValue);
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual bool IsChannelPosed();
};

// @fnv 0x00c32cb0
// src: XBOX_PDB 0x00c32cb0
void __fastcall NiPSysModifierBoolCtlr_Update(NiPSysModifierBoolCtlr* controller, void*, const float& fTime)
{
    if (((unsigned char)(controller->m_uiObjectFlags >> 5) & 1) != 0)
    {
        controller->m_fControllerTime = DAT_01096324;
    }
    else if (controller->DontDoUpdate(fTime) && (!controller->m_spControllerInterpolator.m_pObject ||
             !((C32CB0Interpolator*)(NiInterpolator*)controller->m_spControllerInterpolator.m_pObject)->IsChannelPosed()))
    {
        return;
    }

    if (controller->m_spControllerInterpolator.m_pObject)
    {
        int fValue;
        if (((C32CB0Interpolator*)(NiInterpolator*)controller->m_spControllerInterpolator.m_pObject)->Update(
                controller->m_fControllerTime, controller->m_pkTarget, fValue))
            controller->vf61(fValue);
    }
}
