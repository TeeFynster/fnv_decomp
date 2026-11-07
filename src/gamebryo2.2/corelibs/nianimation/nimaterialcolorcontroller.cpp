#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiAlphaController.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiMaterialProperty.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiPoint3Interpolator.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/NiLightColorController.h"
#include "../../../../include/NiMaterialColorController.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPoint3InterpController.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/StrArr.h"

// src/gamebryo2.2/corelibs/nianimation/nimaterialcolorcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nimaterialcolorcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f3f88;

// @fnv 0x00a4b570
// src: COMMUNITY 0x00a4b570
void* __cdecl NiMaterialColorController_GetRTTI()
{
    return &g_011f3f88;
}

void __cdecl FUN_00a57c80(void*);

extern int DAT_01098a14;

// Allocates a 0x3c-byte BSFadeNode, runs its constructor, zeroes the field at offset 0x38, sets its vtable, and returns the object or null.
// @fnv 0x00a4b790
// src: EXE 0x00a4b790
void* __cdecl NiMaterialColorController_CreateObject()
{
    void* p = BSFadeNode::operator new(0x3c);
    if (p)
    {
        ((void(__thiscall*)(void*))FUN_00a57c80)(p);
        *(unsigned short*)((char*)p + 0x38) = 0;
        *(void**)p = &DAT_01098a14;
        return p;
    }
    return 0;
}

namespace fnv_00a4b880 {

struct GlobalObjectO2_00a7b610
{
    char const* m_str;
};
extern GlobalObjectO2_00a7b610 g_011f3f88;
void __stdcall NiPoint3InterpController_GetViewerStrings(StrArr*);
char* __cdecl NiViewerStrings_NiGetViewerString_Title(char const*);

// Appends the controller name, growing the string array when needed.
// @fnv 0x00a4b880
// src: XBOX_PDB 0x00a4b880
void __stdcall NiMaterialColorController_GetViewerStrings(StrArr* pkStrings)
{
    NiPoint3InterpController_GetViewerStrings(pkStrings);
    char* pStr = NiViewerStrings_NiGetViewerString_Title(g_011f3f88.m_str);
    unsigned int len = pkStrings->m_usSize;
    unsigned int cnt = pkStrings->m_usMaxSize;
    if (len >= cnt)
    {
        pkStrings->SetSize(pkStrings->m_usGrowBy + len);
    }
    pkStrings->SetAt(len, pStr);
}
}  // namespace fnv_00a4b880

extern "C" void* g_01201f74;

// @fnv 0x00bc29d0
// src: XBOX_PDB 0x00bc29d0
void* __cdecl BSClearZNode_GetRTTI()
{
    return &g_01201f74;
}

extern unsigned int DAT_011f4998;
extern unsigned int DAT_011f499c;
extern unsigned int DAT_011f49a0;
// Selects an RGB color from global constants, source fields, or a color pointer based on mode, then writes the three floats into output.
// @fnv 0x00a4b3c0
void __fastcall GetMaterialColor(NiMaterialColorController* self, void*, float* afOut)
{
    float red = 0.0f;
    float green = 0.0f;
    float blue = 0.0f;
    register unsigned int type = self->m_uiObjectFlags & 7;
    register NiMaterialProperty* source = (NiMaterialProperty*)self->m_pkTarget;
    switch (type)
    {
    case 0:
    case 1:
        *(unsigned int*)&red = DAT_011f4998;
        *(unsigned int*)&green = DAT_011f499c;
        *(unsigned int*)&blue = DAT_011f49a0;
        break;
    case 2:
        *(unsigned int*)&red = source->unk1c;
        *(unsigned int*)&green = source->unk20;
        *(unsigned int*)&blue = source->unk24;
        break;
    case 3: {
        unsigned int* selected = source->unk34 ? reinterpret_cast<unsigned int*>(source->unk34) : reinterpret_cast<unsigned int*>(&source->unk28);
        *(unsigned int*)&red = selected[0];
        *(unsigned int*)&green = selected[1];
        *(unsigned int*)&blue = selected[2];
        break;
    }
    }
    afOut[0] = red;
    afOut[1] = green;
    afOut[2] = blue;
}

// Returns the name string selected by the low 3 bits of the flags field at offset 0x38.
// @fnv 0x00a4b470
const char* NiMaterialColorController::GetChannelName()
{
    unsigned short flags = m_uiObjectFlags;
    switch (flags & 7)
    {
    case 0:
        return "AMB";
    case 1:
        return "DIFF";
    case 2:
        return "SPEC";
    case 3:
        return "SELF_ILLUM";
    default:
        return 0;
    }
}

#include <windows.h>
// Preserve this unit's inlined smart-pointer assignment and reference counting.
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* apObject)
{
    T* pOld = m_pObject;
    if (pOld != apObject)
    {
        if (pOld)
        {
            if (InterlockedDecrement((LONG*)&pOld->m_uiRefCount) == 0)
                pOld->DeleteThis();
        }
        m_pObject = apObject;
        if (apObject)
            InterlockedIncrement((LONG*)&apObject->m_uiRefCount);
    }
    return *this;
}

// 0x00a495f0 is NiPoint3Interpolator(NiPosData*) in nipoint3interpolator.cpp.
// Allocate its animation fields only: the shared header also overlays unrelated VATS state.
static __forceinline NiPoint3Interpolator* CreateMaterialInterpolator(NiPosData* source)
{
    NiPoint3Interpolator* interpolator = static_cast<NiPoint3Interpolator*>(
        NiPoint3Interpolator::operator new(offsetof(NiPoint3Interpolator, m_uiLastKeyIndex) + sizeof(unsigned int)));
    if (interpolator)
        return new (interpolator) NiPoint3Interpolator(source);
    return 0;
}

// The shared class has no declaration for this legacy material linker.
// An explicit ECX object parameter preserves its original member-function ABI.
// @fnv 0x00a4b4b0
void __fastcall LinkMaterialColor(NiMaterialColorController* self, void*, NiStream* apStream)
{
    self->NiInterpController::LinkObject(*apStream);

    if (*(unsigned int*)((char*)apStream + 0xd8) < 0xa010068)
    {
        NiPosData* pSource = (NiPosData*)apStream->GetLoadedObject();
        self->m_spControllerInterpolator = CreateMaterialInterpolator(pSource);
        self->m_spControllerInterpolator.m_pObject->Collapse();
    }
}

// Compares the base controller and the low three material-channel flag bits.
// @fnv 0x00a4b540
bool NiMaterialColorController::IsEqual(NiObject* pkObject) const
{
    if (!NiSingleInterpController::IsEqual(pkObject))
        return false;
    return ((unsigned char)((NiMaterialColorController*)pkObject)->m_uiObjectFlags ^ (unsigned char)m_uiObjectFlags) & 7 ? false : true;
}

extern const float DAT_01096324;

// NiColor is the three-float RGB type; NiColorA has a fourth alpha component.
inline NiColor::NiColor()
{}

__forceinline void NiColor::Clamp()
{
    if (r < 0.0f)
        r = 0.0f;
    else if (r > 1.0f)
        r = 1.0f;
    if (g < 0.0f)
        g = 0.0f;
    else if (g > 1.0f)
        g = 1.0f;
    if (b < 0.0f)
        b = 0.0f;
    else if (b > 1.0f)
        b = 1.0f;
}

// The shared material header exposes these fields but does not yet declare its inline setters.
static __forceinline void SetAmbientColor(NiMaterialProperty*, const NiColor&)
{}
static __forceinline void SetDiffuseColor(NiMaterialProperty*, const NiColor&)
{}
static __forceinline void SetSpecularColor(NiMaterialProperty* material, const NiColor& color)
{
    *reinterpret_cast<NiColor*>(&material->unk1c) = color;
    ++reinterpret_cast<unsigned int&>(material->unk44);
}
static __forceinline void SetEmittance(NiMaterialProperty* material, const NiColor& color)
{
    *reinterpret_cast<NiColor*>(&material->unk28) = color;
    ++reinterpret_cast<unsigned int&>(material->unk44);
}

inline bool NiTimeController::GetManagerControlled() const
{
    return (bool)((m_uiObjectFlags >> 5) & 1);
}

// Sets controller time for manager-controlled updates, then may evaluate the interpolator and update a material color channel.
// @fnv 0x00a4b580
void __fastcall UpdateMaterialColor(NiMaterialColorController* self, void*, NiUpdateData& kUpdateData)
{
    if (self->GetManagerControlled())
    {
        self->m_fControllerTime = DAT_01096324;
    }
    else if (self->DontDoUpdate(kUpdateData.fTime) &&
             (!((NiPoint3Interpolator*)self->m_spControllerInterpolator.m_pObject) || !((NiPoint3Interpolator*)self->m_spControllerInterpolator.m_pObject)->AlwaysUpdate()))
    {
        return;
    }

    if (((NiPoint3Interpolator*)self->m_spControllerInterpolator.m_pObject))
    {
        NiPoint3 kValue;
        if (((NiPoint3Interpolator*)self->m_spControllerInterpolator.m_pObject)->UpdatePoint3(self->m_fControllerTime, ((NiMaterialProperty*)self->m_pkTarget), kValue))
        {
            NiMaterialProperty* pkMat = ((NiMaterialProperty*)self->m_pkTarget);
            NiColor kColor;
            kColor.r = kValue.x;
            kColor.g = kValue.y;
            kColor.b = kValue.z;
            kColor.Clamp();
            switch ((self->m_uiObjectFlags & 7))
            {
            case 0:
                SetAmbientColor(pkMat, kColor);
                break;
            case 1:
                SetDiffuseColor(pkMat, kColor);
                break;
            case 2:
                SetSpecularColor(pkMat, kColor);
                break;
            case 3:
                SetEmittance(pkMat, kColor);
                break;
            }
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
void __cdecl _delete(void*, unsigned int);
struct RefObj
{
    virtual void f0();
    virtual void f1();
    long m_ref;
};
struct BaseB
{
    void FUN_00a6d290();
};

// Sets the vtable pointer, decrements p->m_ref and calls p->f1() at zero, calls FUN_00a6d290, then conditionally deletes this.
// @fnv 0x00a4b6f0
void* __fastcall ReleaseMaterialColor(NiMaterialColorController* self, void*, unsigned int uiFlags)
{
    *(void* volatile*)self = (void*)&DAT_01098a14;
    RefObj* p = (RefObj* volatile&)self->m_spControllerInterpolator.m_pObject;
    if (p)
    {
        if (InterlockedDecrement((volatile long*)&p->m_ref) == 0)
            p->f1();
    }
    ((BaseB*)self)->FUN_00a6d290();
    if (uiFlags & 1)
        _delete(self, 0x3c);
    return self;
}

// Allocates a new NiMaterialColorController, initializes it, copies member data from this, and returns the new object.
// @fnv 0x00a4b740
NiMaterialColorController* NiMaterialColorController::Clone(CloningProcess& kCloning)
{
    NiMaterialColorController* pkObject = (NiMaterialColorController*)BSFadeNode::operator new(0x3c);
    if (pkObject)
    {
        ((void(__thiscall*)(NiLightColorController*))FUN_00a57c80)((NiLightColorController*)pkObject);
        *(void**)pkObject = (void*)&DAT_01098a14;
        pkObject->m_uiObjectFlags = 0;
    }
    else
    {
        pkObject = 0;
    }
    ((NiAlphaController*)this)->CopyMemberData((NiAlphaController*)pkObject, kCloning);
    pkObject->m_uiObjectFlags = m_uiObjectFlags;
    return pkObject;
}

struct StreamRecord
{
    unsigned int unknown00;
    unsigned int bytesRead;
    int(__cdecl* read)(StreamRecord*, void*, unsigned int, unsigned int*, unsigned int);
};

inline StreamRecord* NiStream::record() { return *(StreamRecord**)((char*)this + 0x24c); }
inline unsigned int NiStream::version() { return *(unsigned int*)((char*)this + 0xd8); }
inline unsigned short NiStream::savedFlags() { return *(unsigned short*)((char*)this + 0x286); }
void __stdcall FUN_00a57c70(NiStream*);

// @fnv 0x00a4b7c0
void __fastcall LoadMaterialColor(NiMaterialColorController* self, void*, NiStream* stream)
{
    unsigned int value;
    FUN_00a57c70(stream);
    if (stream->version() < 0x0a000102)
    {
        self->m_uiObjectFlags = (stream->savedFlags() >> 5) & 0xff;
    }
    else
    {
        StreamRecord* record = stream->record();
        int(__cdecl * read)(StreamRecord*, void*, unsigned int, unsigned int*, unsigned int) = record->read;
        value = 2;
        unsigned int uiBytesAdded = read(record, &self->m_uiObjectFlags, 2, &value, 1);
        record->bytesRead += uiBytesAdded;
    }
    if (stream->version() < 0x0a010068)
        stream->ResetStreamState();
}

extern float DAT_010ba600;
extern int DAT_010ba608;
struct FUN_00bc2980 : NiNode
{
    unsigned char m_ac;
    unsigned char m_ad;
    float m_b0;
    float m_b4;
    FUN_00bc2980();
};
// Constructs a NiNode-derived object, sets m_b4 to 100.0f, m_b0 to DAT_010ba600, m_ad and m_ac to 0, and sets the vtable pointer to DAT_010ba608.
// @fnv 0x00bc2980
FUN_00bc2980::FUN_00bc2980() : NiNode(0)
{
    m_b4 = 100.0f;
    *(void**)this = (void*)&DAT_010ba608;
    m_b0 = DAT_010ba600;
    m_ad = 0;
    m_ac = 0;
}

void __cdecl NiNode_GetViewerStrings();

// @fnv 0x00bc29c0
// src: XBOX_PDB 0x00bc29c0
void __cdecl BSClearZNode_GetViewerStrings()
{
    NiNode_GetViewerStrings();
}

extern void __fastcall UpdateFields_00c5faa0(NiMaterialColorController*);
extern "C" void __cdecl __Dummy_00b6fef0(NiMaterialColorController*, int);

// Resets the node fields, runs base destruction, and optionally frees the object.
// @fnv 0x00bc29e0
NiMaterialColorController* __thiscall NiMaterialColorController::Destroy(int aiFlags)
{
    ((float*)this)[0x2d] = 100.0f;
    ((float*)this)[0x2c] = DAT_010ba600;
    ((void**)this)[0] = &DAT_010ba608;
    ((unsigned char*)this)[0xad] = 0;
    ((unsigned char*)this)[0xac] = 0;
    UpdateFields_00c5faa0(this);
    if (aiFlags & 1)
        __Dummy_00b6fef0(this, 0xb8);
    return this;
}

