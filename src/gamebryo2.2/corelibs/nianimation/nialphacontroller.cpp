// gamebryo2.2/corelibs/nianimation/nialphacontroller.cpp: NiAlphaController (9 functions)

#include "../../../../include/NiAlphaController.h"
#include "../../../../include/NiTransformController.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiFloatInterpController.h"

// @fnv 0x00a57620
__declspec(noinline) void NiAlphaController::CopyMemberData(NiAlphaController* clone, CloningProcess& process)
{
    reinterpret_cast<NiTransformController*>(this)->CopyMemberData(reinterpret_cast<NiTransformController*>(clone),
                                                                   process);
}

// The unused EDX parameter keeps the original thiscall stack arguments in place.
// @fnv 0x00a569f0
void __fastcall GetAlphaValue(NiAlphaController* self, void*, float& fValue)
{
    float* p = reinterpret_cast<float*>(self->m_pkTarget);
    fValue = p[0x3c / 4];
}

extern int g_011f4084;

// @fnv 0x00a56a80
// src: COMMUNITY 0x00a56a80
int* __cdecl NiAlphaController_GetRTTI()
{
    return &g_011f4084;
}

extern int DAT_0109a76c;
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
// Allocates a 0x38-byte NiFloatInterpController, constructs it in place, sets its vtable to DAT_0109a76c, and returns it (or null on allocation failure).
// @fnv 0x00a56b30
NiFloatInterpController* __cdecl CreateFloatInterpController()
{
    NiFloatInterpController* p = (NiFloatInterpController*)BSFadeNode::operator new(0x38);
    if (p)
    {
        ::new (p) NiFloatInterpController;
        *(int**)p = &DAT_0109a76c;
        return p;
    }
    return 0;
}

struct FUN_00bc3050_RTTI
{
    const char* m_pcName;
    FUN_00bc3050_RTTI* m_pParentNode;
};
extern FUN_00bc3050_RTTI g_011f4a5c;
struct FUN_00bc3050_Obj
{
    virtual void f0();
    virtual void f1();
    virtual FUN_00bc3050_RTTI* GetRTTI();
};
// Checks whether pkTarget's RTTI chain contains g_011f4a5c, returning false for a null target or null RTTI.
// @fnv 0x00bc3050
// src: COMMUNITY 0x00bc3050
bool __stdcall NiMaterialColorController_InterpTargetIsCorrectType(FUN_00bc3050_Obj* pkTarget)
{
    if (!pkTarget)
        return false;
    FUN_00bc3050_RTTI* pkRTTI = pkTarget->GetRTTI();
    if (!pkRTTI)
        return false;
    do
    {
        if (pkRTTI == &g_011f4a5c)
            return true;
        pkRTTI = pkRTTI->m_pParentNode;
    } while (pkRTTI);
    return false;
}

// Keep this array local while the approved headers only forward-declare NiTPrimitiveArray.
template <class T> struct AlphaPrimitiveArray
{
    char _pad[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    char _pad2[2];
    unsigned short m_usGrowBy;
    void __thiscall SetSize(unsigned int);
    void __thiscall SetAt(unsigned int, T&);
};
void __stdcall NiFloatInterpController_GetViewerStrings(AlphaPrimitiveArray<char*>*);
char* __cdecl _FUN_00a7d330(const char*);
// Grows pkStrings if full, then appends the string returned by _FUN_00a7d330(g_011f4084) at the current size index.
// @fnv 0x00a56b60
// src: XBOX_PDB 0x00a56b60
void __stdcall NiAlphaController_GetViewerStrings(AlphaPrimitiveArray<char*>* pkStrings)
{
    NiFloatInterpController_GetViewerStrings(pkStrings);
    char* pszStr = _FUN_00a7d330((const char*)g_011f4084);
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiSize, pszStr);
}

extern int DAT_0109a76c;
// Allocates and initialises a NiFloatInterpController, then copies p into it via Copy and returns the new object, or null if allocation fails.
// @fnv 0x00a56ae0
NiFloatInterpController* __fastcall CreateAndCopy(NiAlphaController* self, void*, CloningProcess* apSource)
{
    NiFloatInterpController* n = (NiFloatInterpController*)NiFloatInterpController::operator new(0x38);
    NiFloatInterpController* r;
    if (n)
    {
        ::new (n) NiFloatInterpController;
        *(int**)n = &DAT_0109a76c;
        r = n;
    }
    else
    {
        r = 0;
    }
    self->CopyMemberData(reinterpret_cast<NiAlphaController*>(r), *apSource);
    return r;
}

static const float kInvalidTime = -3.402823466e+38f;
struct FloatTarget
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    float m_fValue;
    int unk40;
    unsigned int m_uiRevID;
    void SetValue(float f)
    {
        m_fValue = f;
        m_uiRevID++;
    }
};
struct FloatInterpolator
{
    virtual void s00(), s01(), s02(), s03(), s04(), s05(), s06(), s07();
    virtual void s08(), s09(), s10(), s11(), s12(), s13(), s14(), s15();
    virtual void s16(), s17(), s18(), s19(), s20(), s21(), s22(), s23();
    virtual void s24(), s25(), s26(), s27(), s28(), s29(), s30(), s31();
    virtual void s32(), s33(), s34(), s35(), s36(), s37(), s38();
    virtual bool Update(float fTime, FloatTarget* pkTarget, float& fValue);
    virtual void s40(), s41(), s42(), s43(), s44(), s45(), s46(), s47();
    virtual void s48(), s49(), s50(), s51(), s52();
    virtual bool AlwaysUpdate();
};
struct UpdateData
{
    float m_fTime;
};
inline bool NiTimeController::GetManagerControlled() const
{
    return ((m_uiObjectFlags >> 5) & 1) ? true : false;
}
// @fnv 0x00a56a00
void __fastcall UpdateAlpha(NiAlphaController* self, void*, UpdateData& kData)
{
    if (self->GetManagerControlled())
    {
        self->m_fControllerTime = kInvalidTime;
    }
    else if (self->DontDoUpdate(kData.m_fTime) &&
             (!self->m_spControllerInterpolator.m_pObject ||
              !reinterpret_cast<FloatInterpolator*>(self->m_spControllerInterpolator.m_pObject)->AlwaysUpdate()))
    {
        return;
    }
    if (self->m_spControllerInterpolator.m_pObject)
    {
        float fValue;
        if (reinterpret_cast<FloatInterpolator*>(self->m_spControllerInterpolator.m_pObject)->Update(
                self->m_fControllerTime, reinterpret_cast<FloatTarget*>(self->m_pkTarget), fValue))
        {
            reinterpret_cast<FloatTarget*>(self->m_pkTarget)->SetValue(fValue);
        }
    }
}

#include <windows.h>
void __cdecl FUN_00a6d290();
void __cdecl _delete(void*, unsigned int);
// Releases the interpolator, destroys the base, and optionally deletes the controller.
// @fnv 0x00a56a90
void* __fastcall DeleteAlphaController(NiAlphaController* self, void*, unsigned int uiFlags)
{
    NiInterpolator* p = self->m_spControllerInterpolator.m_pObject;
    if (p)
    {
        if (InterlockedDecrement(reinterpret_cast<LONG*>(&p->m_uiRefCount)) == 0)
            p->DeleteThis();
    }
    reinterpret_cast<void (__thiscall*)(NiAlphaController*)>(FUN_00a6d290)(self);
    if (uiFlags & 1)
        _delete(self, 0x38);
    return self;
}
