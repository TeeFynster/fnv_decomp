#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiAlphaController.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiLight.h"
#include "../../../../include/NiLightColorController.h"
#include "../../../../include/NiObjectNET.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTimeController.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/StrArr.h"

// src/gamebryo2.2/corelibs/nianimation/nilightcolorcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nilightcolorcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// The shared declarations keep the stream internals and the light channel flags
// opaque; these accessors use the original 32-bit offsets in this unit.
static __forceinline unsigned short& LightColorFlags(NiLightColorController* controller)
{
    return *(unsigned short*)((char*)controller + 0x38);
}

__forceinline NiColor::NiColor() {}
__forceinline unsigned int NiStream::version() { return *(unsigned int*)((char*)this + 0xd8); }
__forceinline unsigned short NiStream::savedFlags() { return *(unsigned short*)((char*)this + 0x286); }
__forceinline NiBinaryStream* NiStream::GetBinaryStream() { return *(NiBinaryStream**)((char*)this + 0x250); }
__forceinline NiBinaryStream& NiStream::Istr() { return **(NiBinaryStream**)((char*)this + 0x24c); }
__forceinline unsigned int NiBinaryStream::BinaryWrite(const void* buffer, unsigned int bytes,
    unsigned int* sizes, unsigned int count)
{
    unsigned int result = (*(WriteFunction*)((char*)this + 12))(this, buffer, bytes, sizes, count);
    *(unsigned int*)((char*)this + 4) += result;
    return result;
}
template <class T> __forceinline void NiBinaryStream::Read(T& value)
{
    unsigned int componentSize = sizeof(value);
    unsigned int bytesRead = (*(ReadFunction*)((char*)this + 8))(this, &value, sizeof(value), &componentSize, 1);
    *(unsigned int*)((char*)this + 4) += bytesRead;
}

// Functions missing from the shared classes use explicit-this adapters. The
// unused EDX argument leaves original thiscall stack arguments in place.
void __cdecl NiBoolInterpController_SaveBinary();
void __cdecl FUN_00a6d290();
void __cdecl FUN_00a38e00();
void __cdecl FUN_00a57c70();
void __cdecl ReadLinkID();
void __cdecl NiLight_SetAmbientColor();
extern int DAT_0109ad74;
__declspec(noinline) NiPoint3InterpController* __fastcall InitializePoint3Controller(NiPoint3InterpController* self);

extern "C" bool __stdcall FUN_00a57780(void*);

// @fnv 0x00a461c0
// src: XBOX_PDB 0x00a461c0
char __stdcall NiLightColorController_RegisterStreamables(void* kStream)
{
    char result = 0;
    result = FUN_00a57780(kStream) ? 1 : 0;
    return result;
}

// @fnv 0x00a4d1b0
const char* __fastcall GetLightTypeName(NiLightColorController* self)
{
    unsigned char flag = *(unsigned char*)((char*)self + 0x38);
    const char* result = "Ambient";
    if (!(flag & 1))
        result = "Diffuse";
    return result;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f3fa8;

// @fnv 0x00a4d200
// src: COMMUNITY 0x00a4d200
GlobalObjectO2_00a7b610* __cdecl NiLightColorController_GetRTTI()
{
    return &g_011f3fa8;
}

extern int DAT_01098dd4;

// @fnv 0x00a4d500
// src: EXE 0x00a4d500
void* __cdecl NiLightColorController_CreateObject()
{
    void* p = BSFadeNode::operator new(0x3c);
    if (p)
    {
        NiLightColorController* pController = (NiLightColorController*)p;
        ((void(__thiscall*)(NiLightColorController*))InitializePoint3Controller)(pController);
        *(short*)((char*)p + 0x38) = 0;
        *(void**)p = &DAT_01098dd4;
        return p;
    }
    return 0;
}

// Reads the light's first or second color depending on the flag and writes its RGB components into kValue.
// @fnv 0x00a4d150
void __fastcall GetLightColor(NiLightColorController* self, void*, NiPoint3& kValue)
{
    NiColor kColor;
    NiLight* apTargetLight = (NiLight*)self->m_pkTarget;
    if (apTargetLight)
    {
        if (LightColorFlags(self) & 1)
            kColor = apTargetLight->m_kAmb;
        else
            kColor = apTargetLight->m_kDiff;
        kValue.x = kColor.r;
        kValue.y = kColor.g;
        kValue.z = kColor.b;
    }
}

bool __stdcall FUN_00a57c10(void*);
// Checks pkObject via FUN_00a57c10, then compares bit 0 of the inverted byte at offset 0x38 with the byte at this+0x38 and returns the result.
// @fnv 0x00a4d1d0
// src: GAMEBRYO_LIB 0x00a4d1d0
bool __fastcall NiLightColorController_IsEqual(NiLightColorController* self, void*, NiObject* pkObject)
{
    NiLightColorController* pkControl = (NiLightColorController*)pkObject;
    if (!FUN_00a57c10(pkControl))
        return false;
    unsigned char v = *(unsigned char*)((char*)pkControl + 0x38);
    v = ~v;
    v ^= *(unsigned char*)((char*)self + 0x38);
    v &= 1;
    return v;
}

extern NiRTTI g_011f4a68_arg1;
// Walks the RTTI chain of pkTarget and returns true if it reaches g_011f4a68_arg1, false if pkTarget is null or the chain ends.
// @fnv 0x00a4d210
// src: GUESS 0x00a4d210 (confidence: high)
bool __stdcall NiObjectNET_HasTargetRTTIInChain(NiObjectNET* pkTarget)
{
    if (!pkTarget)
        return false;
    for (const NiRTTI* p = pkTarget->GetRTTI(); p; p = p->m_pBaseRTTI)
    {
        if (p == &g_011f4a68_arg1)
            return true;
    }
    return false;
}

void __cdecl _delete(void*, unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
// @fnv 0x00a4d460
void* __fastcall DestroyAndFree(NiLightColorController* self, void*, unsigned int auiFlags)
{
    *(void* volatile*)self = (void*)&DAT_01098dd4;
    void* p = *(void* volatile*)((char*)self + 0x34);
    if (p)
    {
        if (InterlockedDecrement((long volatile*)((char*)p + 4)) == 0)
            ((NiInterpolator*)p)->DeleteThis();
    }
    ((void(__thiscall*)(NiLightColorController*))FUN_00a6d290)(self);
    if (auiFlags & 1)
        _delete(self, 0x3c);
    return self;
}

struct CloningProcess
{
    void* m_pCloneMap;
};
// @fnv 0x00a4d4b0
// src: XBOX_PDB 0x00a4d4b0
void* __fastcall NiLightColorController_CreateClone(NiLightColorController* self, void*, CloningProcess& kCloning)
{
    NiLightColorController* pkObject = (NiLightColorController*)BSFadeNode::operator new(0x3c);
    if (pkObject)
    {
        ((void(__thiscall*)(NiLightColorController*))InitializePoint3Controller)(pkObject);
        *(void**)pkObject = (void*)&DAT_01098dd4;
        LightColorFlags(pkObject) = 0;
    }
    else
    {
        pkObject = 0;
    }
    ((NiAlphaController*)self)->CopyMemberData((NiAlphaController*)pkObject, kCloning);
    LightColorFlags(pkObject) = LightColorFlags(self);
    return pkObject;
}

void __stdcall NiPoint3InterpController_GetViewerStrings(StrArr*);
char* __cdecl NiViewerStrings_NiGetViewerString_Title(GlobalObjectO2_00a7b610*);
// @fnv 0x00a4d5a0
// src: XBOX_PDB 0x00a4d5a0
void __stdcall NiLightColorController_GetViewerStrings(StrArr* pkStrings)
{
    NiPoint3InterpController_GetViewerStrings(pkStrings);
    char* p = NiViewerStrings_NiGetViewerString_Title(*(GlobalObjectO2_00a7b610**)&g_011f3fa8);
    unsigned int uiIndex = ((unsigned short*)pkStrings)[5];
    if (uiIndex >= ((unsigned short*)pkStrings)[4])
        pkStrings->SetSize(((unsigned short*)pkStrings)[7] + uiIndex);
    pkStrings->SetAt(uiIndex, p);
}

// @fnv 0x00a4b840
void __fastcall WriteToStream(NiLightColorController* self, void*, NiStream& stream)
{
    ((void(__thiscall*)(NiLightColorController*, NiStream&))NiBoolInterpController_SaveBinary)(self, stream);
    NiBinaryStream* __restrict out = stream.GetBinaryStream();
    unsigned int size = 2;
    out->BinaryWrite(&LightColorFlags(self), 2, &size, 1);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
void* __cdecl Object_DispatchCommandFour(unsigned int);

struct RefObject
{
    virtual void Unknown00();
    virtual void ReleaseObject();
    virtual void Unknown02();
    virtual void Unknown03();
    virtual void Unknown04();
    virtual void Unknown05();
    virtual void Unknown06();
    virtual void Unknown07();
    virtual void Unknown08();
    virtual void Unknown09();
    virtual void Unknown10();
    virtual void Unknown11();
    virtual void Unknown12();
    virtual void Unknown13();
    virtual void Unknown14();
    virtual void Unknown15();
    virtual void Unknown16();
    virtual void Unknown17();
    virtual void Unknown18();
    virtual void Unknown19();
    virtual void Unknown20();
    virtual void Unknown21();
    virtual void Unknown22();
    virtual void Unknown23();
    virtual void Unknown24();
    virtual void Unknown25();
    virtual void Unknown26();
    virtual void Unknown27();
    virtual void Unknown28();
    virtual void Unknown29();
    virtual void Unknown30();
    virtual void Unknown31();
    virtual void Unknown32();
    virtual void Unknown33();
    virtual void Unknown34();
    virtual void Unknown35();
    virtual void Unknown36();
    virtual void Unknown37();
    virtual void Unknown38();
    virtual void Unknown39();
    virtual void Unknown40();
    virtual void Unknown41();
    virtual void Unknown42();
    virtual void Unknown43();
    virtual void Unknown44();
    virtual void Unknown45();
    virtual void Unknown46();
    virtual void Activate();
    volatile long referenceCount;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    RefObject* __thiscall FUN_00a495f0(RefObject* source);
};
void __stdcall FUN_00a57630(NiStream* stream);
void __cdecl FUN_00a63430();
// Reads a stream, and for older versions creates a RefObject from it, swaps it into activeObject with reference counting, then activates it.
// @fnv 0x00a4d3a0
void __fastcall LoadActiveObject(NiLightColorController* self, void*, NiStream* stream)
{
    FUN_00a57630(stream);
    if (stream->version() >= 0x0a010068)
        return;
    RefObject* source = ((RefObject*(__thiscall*)(NiStream*))FUN_00a63430)(stream);
    if (source)
        InterlockedIncrement(&source->referenceCount);
    void* memory = Object_DispatchCommandFour(sizeof(RefObject));
    RefObject* fresh = memory ? static_cast<RefObject*>(memory)->FUN_00a495f0(source) : 0;
    RefObject*& activeObject = *(RefObject**)&self->m_spControllerInterpolator.m_pObject;
    RefObject* old = activeObject;
    if (old != fresh)
    {
        if (old && InterlockedDecrement(&old->referenceCount) == 0)
            old->ReleaseObject();
        activeObject = fresh;
        if (fresh)
            InterlockedIncrement(&fresh->referenceCount);
    }
    activeObject->Activate();
    if (source && InterlockedDecrement(&source->referenceCount) == 0)
        source->ReleaseObject();
}

extern float DAT_01096324;
extern NiColor DAT_011f4998;
extern NiRTTI g_011f4a28;

// Evaluates the controller output into a clamped 0..1 vector and writes it to the output object, swapping vector/color when the light channel flag is set.
// @fnv 0x00a4d240
void NiTimeController::EvaluateAndApplyOutput(float& parameter)
{
    if ((unsigned char)(m_uiObjectFlags >> 5) & 1)
        m_fControllerTime = DAT_01096324;
    else if (DontDoUpdate(parameter))
    {
        if (((NiSingleInterpController*)this)->m_spControllerInterpolator.m_pObject == 0)
            return;
        if (!((bool(__thiscall**)(NiInterpolator*))
            (*(void***)((NiSingleInterpController*)this)->m_spControllerInterpolator.m_pObject + 53))[0](
                ((NiSingleInterpController*)this)->m_spControllerInterpolator.m_pObject))
            return;
    }

    NiInterpolator* controller = ((NiSingleInterpController*)this)->m_spControllerInterpolator.m_pObject;
    if (controller == 0)
        return;

    NiPoint3 sourceValues;
    NiPoint3 kClampedValues;
    typedef bool(__thiscall * Evaluate)(NiInterpolator*, float, NiObjectNET*, NiPoint3*);
    if (!((Evaluate)(*(void***)controller)[37])(controller, m_fControllerTime, m_pkTarget, &sourceValues))
        return;

    kClampedValues.x = sourceValues.x;
    kClampedValues.y = sourceValues.y;
    kClampedValues.z = sourceValues.z;
    if (kClampedValues.x < 0.0f)
        kClampedValues.x = 0.0f;
    else if (kClampedValues.x > 1.0f)
        kClampedValues.x = 1.0f;
    if (kClampedValues.y < 0.0f)
        kClampedValues.y = 0.0f;
    else if (kClampedValues.y > 1.0f)
        kClampedValues.y = 1.0f;
    if (kClampedValues.z < 0.0f)
        kClampedValues.z = 0.0f;
    else if (kClampedValues.z > 1.0f)
        kClampedValues.z = 1.0f;

    if (m_pkTarget == 0)
        return;
    NiLight* pOutput = (NiLight*)m_pkTarget->DynamicCast(&g_011f4a28);
    if ((LightColorFlags((NiLightColorController*)this) & 1) != 0)
    {
        ((void(__thiscall*)(NiLight*, const NiPoint3&))NiLight_SetAmbientColor)(pOutput, kClampedValues);
        pOutput->SetEffectColor(DAT_011f4998);
    }
    else
    {
        ((void(__thiscall*)(NiLight*, const NiPoint3&))NiLight_SetAmbientColor)(pOutput, (const NiPoint3&)DAT_011f4998);
        pOutput->SetEffectColor((const NiColor&)kClampedValues);
    }
}

// @fnv 0x00a57c80
__declspec(noinline) NiPoint3InterpController* __fastcall InitializePoint3Controller(NiPoint3InterpController* self)
{
    ((void(__thiscall*)(NiPoint3InterpController*))FUN_00a38e00)(self);
    *(void**)self = &DAT_0109ad74;
    return self;
}

// @fnv 0x00a4d530
void __fastcall ReadFromStream(NiLightColorController* self, void*, NiStream& stream)
{
    ((void(__thiscall*)(NiLightColorController*, NiStream&))FUN_00a57c70)(self, stream);
    if (stream.version() < 0x0a000102)
    {
        LightColorFlags(self) = (stream.savedFlags() >> 5) & 0x3f;
    }
    else
    {
        stream.Istr().Read(LightColorFlags(self));
    }
    if (stream.version() < 0x0a010068)
        ((void(__thiscall*)(NiStream*))ReadLinkID)(&stream);
}
