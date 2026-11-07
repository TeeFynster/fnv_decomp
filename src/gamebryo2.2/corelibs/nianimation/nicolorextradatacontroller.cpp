#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiColorExtraData.h"
#include "../../../../include/NiColorExtraDataController.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiColorInterpolator.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiColorA.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiUpdateData.h"

// src/gamebryo2.2/corelibs/nianimation/nicolorextradatacontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nicolorextradatacontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C"
{
    extern void* g_011f3fdc;
}

// @fnv 0x00a4fb00
// src: COMMUNITY 0x00a4fb00
void* __cdecl NiColorExtraDataController_GetRTTI()
{
    return &g_011f3fdc;
}

extern "C" void __cdecl FUN_00a572d0(void);
extern "C" void __cdecl __Dummy_00b6fef0(void* p, int size);

// The shared controller has no deleting-destructor helper declaration.
// An unused EDX argument preserves its ECX receiver and stack arguments.
// @fnv 0x00a4fb10
void* __fastcall FUN_00a4fb10(NiColorExtraDataController* self, void*, int aiFlags)
{
    FUN_00a572d0();
    if (aiFlags & 1)
    {
        __Dummy_00b6fef0(self, 0x40);
    }
    return self;
}

int* __fastcall InitTimeController(int* p);

extern int DAT_0109947c;

// Allocates a 0x40-byte BSFadeNode, initialises it via InitTimeController, sets its vtable to DAT_0109947c, and returns it (or null on allocation failure).
// @fnv 0x00a4fac0
// src: EXE 0x00a4fac0
void* __cdecl NiColorExtraDataController_CreateObject()
{
    void* mem = BSFadeNode::operator new(0x40);
    if (mem)
    {
        int* p = InitTimeController((int*)mem);
        *(int**)(int*)mem = &DAT_0109947c;
        return mem;
    }
    return 0;
}

struct Holder_00a55f80
{
    void* __thiscall FUN_00a55f80(int, float, int);
};
// @fnv 0x00a4fa70
// src: XBOX_PDB 0x00a4fa70
void* __stdcall NiColorExtraDataController_CreateBlendInterpolator(int a1, int a2, int a3, float a4, int a5)
{
    void* p = BSFadeNode::operator new(0x44);
    if (p)
        return ((Holder_00a55f80*)p)->FUN_00a55f80(a2, a4, a5);
    return 0;
}

struct Interp9
{
    void* __thiscall FUN_00a3bd80(NiColorA c);
};
// @fnv 0x00a4fb30
// src: XBOX_PDB 0x00a4fb30
void* __thiscall NiColorExtraDataController::CreatePoseInterpolator(unsigned short usIndex)
{
    void* mem = BSFadeNode::operator new(0x24);
    if (mem)
    {
        Interp9* p = (Interp9*)mem;
        return p->FUN_00a3bd80(reinterpret_cast<const NiColorA&>(static_cast<NiColorExtraData*>(m_pExtraData.m_pObject)->m_kFogTint));
    }
    return 0;
}

extern NiRTTI _g_011f3730;
// @fnv 0x00a4fc90
// src: XBOX_PDB 0x00a4fc90
void NiColorExtraDataController::SynchronizePoseInterpolator(NiInterpolator* pkInterp, unsigned short usIndex)
{
    NiColorInterpolator* pkColorInterp;
    if (!pkInterp)
        pkColorInterp = 0;
    else
        pkColorInterp = (NiColorInterpolator*)pkInterp->DynamicCast(&_g_011f3730);
    pkColorInterp->SetColorValue(static_cast<NiColorExtraData*>(m_pExtraData.m_pObject)->m_kFogTint);
}


struct Base57420
{
    void __thiscall FUN_00a57420(StrArr*);
};
char* __cdecl _FUN_00a7d330(const char*);
// Appends the string returned by _FUN_00a7d330(g_011f3fdc) to pkStrings, growing the array if its size has reached its allocation.
// @fnv 0x00a4fd90
void __thiscall NiColorExtraDataController::AppendString(StrArr* pkStrings)
{
    reinterpret_cast<Base57420*>(this)->FUN_00a57420(pkStrings);
    char* pcString = _FUN_00a7d330((const char*)g_011f3fdc);
    unsigned int uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIndex + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiIndex, pcString);
}

// Stand-in with the target virtual at vtable slot 0xB4/4 = 45
struct InterpVT_00a4faa0
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual bool IsCorrectType();
};

// Calls IsCorrectType on the interpolator's vtable and returns the result, ignoring the index.
// @fnv 0x00a4faa0
// src: XBOX_PDB 0x00a4faa0
bool __stdcall NiColorExtraDataController_InterpolatorIsCorrectType(NiInterpolator* pkInterpolator, unsigned short usIndex)
{
    return reinterpret_cast<InterpVT_00a4faa0*>(pkInterpolator)->IsCorrectType();
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern int DAT_0109947c;

extern "C" void FUN_00c312f0();

// Allocates a 0x40-byte object, initialises it with InitTimeController and a vtable, then calls FUN_00c312f0 with arg and returns it.
// @fnv 0x00a4fb80
NiColorExtraDataController* __fastcall CreateObject(NiColorExtraDataController* self, void*, unsigned int arg)
{
    NiColorExtraDataController* p = (NiColorExtraDataController*)Object_DispatchCommandFour(0x40);
    if (p != 0)
    {
        InitTimeController((int*)p);
        *reinterpret_cast<void**>(p) = (void*)&DAT_0109947c;
    }
    else
    {
        p = 0;
    }
    typedef void (__thiscall *CopyMemberData)(NiColorExtraDataController*, NiColorExtraDataController*, unsigned int);
    reinterpret_cast<CopyMemberData>(&FUN_00c312f0)(self, p, arg);
    return p;
}

NiColorA::NiColorA(float fR, float fG, float fB, float fA)
{
    r = fR;
    g = fG;
    b = fB;
    a = fA;
}

extern const float INVALID_TIME_A4F;

// Keep the update entry point local until the shared controller declares it.
// @fnv 0x00a4fce0
void __fastcall UpdateColorController(NiColorExtraDataController* self, void*, NiUpdateData& kUpdateData)
{
    if ((bool)(((self->m_uiObjectFlags & 0x0020) >> 5) & 1))
    {
        self->m_fControllerTime = INVALID_TIME_A4F;
    }
    else if (self->AdvanceController(kUpdateData.fTime) &&
             (!self->m_spControllerInterpolator.m_pObject || !self->m_spControllerInterpolator.m_pObject->AlwaysUpdate()))
    {
        return;
    }

    if (self->m_spControllerInterpolator.m_pObject)
    {
        NiColorA kColor;
        if (self->m_spControllerInterpolator.m_pObject->UpdateColorA(self->m_fControllerTime, self->m_pkTarget, *reinterpret_cast<NiColorA*>(&kColor)))
        {
            if (self->m_pExtraData.m_pObject)
                static_cast<NiColorExtraData*>(self->m_pExtraData.m_pObject)->SetColor(*reinterpret_cast<NiColorA*>(&kColor));
        }
    }
}

extern "C" void __cdecl IsEquivalent();

// @fnv 0x00a4faf0
// src: XBOX_PDB 0x00a4faf0
void __cdecl NiColorExtraDataController_IsEqual()
{
    IsEquivalent();
}
