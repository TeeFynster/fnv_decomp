
// gamebryo2.2/corelibs/nimain/nitextureeffect.cpp
// NiTextureEffect: static texture-type string table init.
#include "../../../../include/NiDynamicEffect.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiMatrix3.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiPlane.h"
// NiFixedString is already supplied by the shared NiDynamicEffect hierarchy.
#define FNV_NIFIXEDSTRING_H
#include "nitextureeffect.h"

NiFixedString NiTextureEffect::ms_kTextureEffectNames[4];

// Initializes the four NiFixedString entries with the strings ProjectedLight, ProjectedShadow, EnvironmentMap and FogMap, releasing the previous handles.
// @fnv 0x00a927e0
void NiTextureEffect::InitializePoint3()
{
    char* pcOld = ms_kTextureEffectNames[0].m_kHandle;
    if (pcOld != "ProjectedLight")
    {
        ms_kTextureEffectNames[0].m_kHandle = NiGlobalStringTable::AddString("ProjectedLight");
        if (pcOld != EmptyFS.m_kHandle)
            InterlockedDecrement((LONG*)(pcOld - 8));
    }

    pcOld = ms_kTextureEffectNames[1].m_kHandle;
    if (pcOld != "ProjectedShadow")
    {
        ms_kTextureEffectNames[1].m_kHandle = NiGlobalStringTable::AddString("ProjectedShadow");
        if (pcOld != EmptyFS.m_kHandle)
            InterlockedDecrement((LONG*)(pcOld - 8));
    }

    pcOld = ms_kTextureEffectNames[2].m_kHandle;
    if (pcOld != "EnvironmentMap")
    {
        ms_kTextureEffectNames[2].m_kHandle = NiGlobalStringTable::AddString("EnvironmentMap");
        if (pcOld != EmptyFS.m_kHandle)
            InterlockedDecrement((LONG*)(pcOld - 8));
    }

    pcOld = ms_kTextureEffectNames[3].m_kHandle;
    if (pcOld != "FogMap")
    {
        ms_kTextureEffectNames[3].m_kHandle = NiGlobalStringTable::AddString("FogMap");
        if (pcOld != EmptyFS.m_kHandle)
            InterlockedDecrement((LONG*)(pcOld - 8));
    }
}

extern int g_011f5e94;

// @fnv 0x00a927d0
// src: COMMUNITY 0x00a927d0
int* __cdecl NiTextureEffect_GetRTTI()
{
    return &g_011f5e94;
}

extern long DAT_011f5ea0;
extern long DAT_011f5ea4;
extern long DAT_011f5ea8;

struct FUN_00a928b0_shell : NiTextureEffect
{
    void ClearFixedStrings();
};

// @fnv 0x00a928b0
void FUN_00a928b0_shell::ClearFixedStrings()
{
    NiFixedString* arr = ms_kTextureEffectNames;
    char* pOldHandle = arr[0].m_kHandle;
    if (pOldHandle != 0)
    {
        arr[0].m_kHandle = NiGlobalStringTable::AddString(0);
        if (pOldHandle != EmptyFS.m_kHandle)
            InterlockedDecrement((long*)(pOldHandle - 8));
    }
    pOldHandle = (char*)DAT_011f5ea0;
    if (pOldHandle != 0)
    {
        DAT_011f5ea0 = (long)NiGlobalStringTable::AddString(0);
        if (pOldHandle != EmptyFS.m_kHandle)
            InterlockedDecrement((long*)(pOldHandle - 8));
    }
    pOldHandle = (char*)DAT_011f5ea4;
    if (pOldHandle != 0)
    {
        DAT_011f5ea4 = (long)NiGlobalStringTable::AddString(0);
        if (pOldHandle != EmptyFS.m_kHandle)
            InterlockedDecrement((long*)(pOldHandle - 8));
    }
    pOldHandle = (char*)DAT_011f5ea8;
    if (pOldHandle != 0)
    {
        DAT_011f5ea8 = (long)NiGlobalStringTable::AddString(0);
        if (pOldHandle != EmptyFS.m_kHandle)
            InterlockedDecrement((long*)(pOldHandle - 8));
    }
}

struct FUN_00a6ff10_holder
{
    bool NiDynamicEffect_RegisterStreamables(NiStream&);
};
struct FUN_00a92a30_shell : NiTextureEffect
{
    bool NiTextureEffect_RegisterStreamables(NiStream&);
};
// @fnv 0x00a92a30
// src: XBOX_PDB 0x00a92a30
bool FUN_00a92a30_shell::NiTextureEffect_RegisterStreamables(NiStream& kStream)
{
    if (!((FUN_00a6ff10_holder*)this)->NiDynamicEffect_RegisterStreamables(kStream))
        return false;
    NiObject* pkObj = *(NiObject**)((char*)this + 0x124);
    if (pkObj)
        pkObj->RegisterStreamables(kStream);
    return true;
}

namespace fnv_00a929d0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct FUN_00a929d0_Holder : NiDynamicEffect
{
    char _pad[0x60];
    NiObject* m_pObject;
    void NiTextureEffect_LinkObject(NiStream&);
};
}  // namespace fnv_00a929d0

extern int DAT_0109fd0c;
extern float DAT_011a9448[32];
extern float DAT_011a946c;

// Invoke the shared base constructor in the storage being initialized here.
inline void* operator new(size_t, NiDynamicEffect* object)
{
    return object;
}

// Constructs the dynamic-effect base, sets the vtable pointer, copies the projection matrices, and initializes the texture settings and planes.
// @fnv 0x00a92710
void* NiTextureEffect::InitializeEffect()
{
    __assume(this != 0);
    ::new (static_cast<NiDynamicEffect*>(this)) NiDynamicEffect;
    *reinterpret_cast<int*>(this) = (int)&DAT_0109fd0c;
    m_mat1 = *(NiMatrix3*)&DAT_011a9448[0];
    m_e8 = 0.0f;
    m_ec = 0.0f;
    m_f0 = 0.0f;
    m_mat2 = *(NiMatrix3*)&DAT_011a9448[0];
    m_118 = 0.0f;
    m_11c = 0.0f;
    m_120 = 0.0f;
    m_124 = 0;
    m_sub1.Initialize(&DAT_011a946c, 0.0f);
    m_sub2.Initialize(&DAT_011a946c, 0.0f);
    m_128 = 0;
    m_130 = 0;
    m_134 = 0;
    m_138 = 0;
    effectType = 5;
    m_12c = 3;
    return this;
}

int __cdecl FUN_00aa1360(const char*, const char*);

struct TexTypeAccess : NiTextureEffect
{
    static const NiFixedString& Str(unsigned int ui)
    {
        return ms_kTextureEffectNames[ui];
    }
};

bool FixedSame(const char* pcTable, const char* pcKey)
{
    if (pcTable == pcKey)
        return true;
    if (pcKey != 0 && pcTable != 0)
        return FUN_00aa1360(pcTable, pcKey) == 0;
    return false;
}

// Searches the four texture-effect type strings for one matching kType and, on a match, stores its index in uiType and returns true.
// @fnv 0x00a92960
bool FindTexTypeIndex(const NiFixedString& kType, unsigned int& uiType)
{
    for (unsigned int ui = 0; ui < 4; ui++)
    {
        if (FixedSame(TexTypeAccess::Str(ui).m_kHandle, kType.m_kHandle))
        {
            uiType = ui;
            return true;
        }
    }
    return false;
}

namespace fnv_00a92bd0 {
extern "C" void* DAT_0109fd0c;

struct RegistrationManager
{
    void** vtable;
    void Deregister(void* object)
    {
        typedef void(__thiscall * Function)(RegistrationManager*, void*);
        Function callback = reinterpret_cast<Function>(vtable[62]);
        callback(this, object);
    }
};
extern RegistrationManager* DAT_011f4748;

inline void ReleaseTextureResource(NiObject* object)
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount)) == 0)
        object->DeleteThis();
}

void __cdecl FUN_00aa1460(void* object, unsigned int size);

struct TextureEffectMatch
{
    void** m_ppVirtualMethodTable;
    TextureEffectMatch* FUN_00a92bd0(unsigned int flags);
};

// @fnv 0x00a92bd0
TextureEffectMatch* TextureEffectMatch::FUN_00a92bd0(unsigned int flags)
{
    m_ppVirtualMethodTable = reinterpret_cast<void**>(&DAT_0109fd0c);
    if (DAT_011f4748)
        DAT_011f4748->Deregister(this);
    NiObject* resource = *reinterpret_cast<NiObject**>(reinterpret_cast<char*>(this) + 0x124);
    if (resource)
        ReleaseTextureResource(resource);
    reinterpret_cast<NiDynamicEffect*>(this)->NiDynamicEffect::~NiDynamicEffect();
    if (flags & 1)
        FUN_00aa1460(this, 0x15c);
    return this;
}
}  // namespace fnv_00a92bd0

struct CallTarget_00a68c60
{
    int FUN_00a68c60(int);
};
struct CallTarget_00a92c40
{
    int UpdateWorldProjection();
};
struct SearchObject
{
    int NiTextureEffect_UpdateWorldData(unsigned int arg0);
};
// @fnv 0x00a92ef0
// src: XBOX_PDB 0x00a92ef0
int SearchObject::NiTextureEffect_UpdateWorldData(unsigned int arg0)
{
    unsigned int callResult0 = (unsigned int)((CallTarget_00a68c60*)this)->FUN_00a68c60((int)arg0);
    unsigned int callResult1 = (unsigned int)((CallTarget_00a92c40*)this)->UpdateWorldProjection();
    return (int)callResult1;
}

class SubCmpA
{
  public:
    bool Equal(void* other);
};
class SubCmpB
{
  public:
    bool Equal(void* other);
};
class SubCmpC
{
  public:
    bool Equal(void* other);
};
class FUN_00a93040_cls
{
  public:
    bool FUN_00a68d80(FUN_00a93040_cls* other);
    bool NiTextureEffect_IsEqual(FUN_00a93040_cls* other);
    unsigned int unk_000;
    unsigned int unk_004;
    unsigned int unk_008;
    unsigned int unk_00c;
    unsigned int unk_010;
    unsigned int unk_014;
    unsigned int unk_018;
    unsigned int unk_01c;
    unsigned int unk_020;
    unsigned int unk_024;
    unsigned int unk_028;
    unsigned int unk_02c;
    unsigned int unk_030;
    unsigned int unk_034;
    unsigned int unk_038;
    unsigned int unk_03c;
    unsigned int unk_040;
    unsigned int unk_044;
    unsigned int unk_048;
    unsigned int unk_04c;
    unsigned int unk_050;
    unsigned int unk_054;
    unsigned int unk_058;
    unsigned int unk_05c;
    unsigned int unk_060;
    unsigned int unk_064;
    unsigned int unk_068;
    unsigned int unk_06c;
    unsigned int unk_070;
    unsigned int unk_074;
    unsigned int unk_078;
    unsigned int unk_07c;
    unsigned int unk_080;
    unsigned int unk_084;
    unsigned int unk_088;
    unsigned int unk_08c;
    unsigned int unk_090;
    unsigned int unk_094;
    unsigned int unk_098;
    unsigned int unk_09c;
    unsigned int unk_0a0;
    unsigned int unk_0a4;
    unsigned int unk_0a8;
    unsigned int unk_0ac;
    unsigned int unk_0b0;
    unsigned int unk_0b4;
    unsigned int unk_0b8;
    unsigned int unk_0bc;
    unsigned int unk_0c0;
    unsigned int unk_0c4;
    unsigned int unk_0c8;
    unsigned int unk_0cc;
    unsigned int unk_0d0;
    unsigned int unk_0d4;
    unsigned int unk_0d8;
    unsigned int unk_0dc;
    unsigned int unk_0e0;
    unsigned int unk_0e4;
    unsigned int unk_0e8;
    unsigned int unk_0ec;
    unsigned int unk_0f0;
    unsigned int unk_0f4;
    unsigned int unk_0f8;
    unsigned int unk_0fc;
    unsigned int unk_100;
    unsigned int unk_104;
    unsigned int unk_108;
    unsigned int unk_10c;
    unsigned int unk_110;
    unsigned int unk_114;
    unsigned int unk_118;
    unsigned int unk_11c;
    unsigned int unk_120;
    unsigned int unk_124;
    unsigned int m_128;
    unsigned int m_12c;
    unsigned int m_130;
    unsigned int m_134;
    unsigned char m_138;
    unsigned char unk_139;
    unsigned short unk_13a;
    unsigned int unk_13c;
};
// Returns true when FUN_00a68d80 succeeds, the unk_0c4 subobjects match, the unk_0e8 and unk_13c subobjects differ, and m_128 through m_138 are equal.
// @fnv 0x00a93040
// src: XBOX_PDB 0x00a93040
bool FUN_00a93040_cls::NiTextureEffect_IsEqual(FUN_00a93040_cls* other)
{
    if (FUN_00a68d80(other) != 0 && reinterpret_cast<SubCmpA*>(&other->unk_0c4)->Equal(&unk_0c4) != 0 &&
        reinterpret_cast<SubCmpB*>(&other->unk_0e8)->Equal(&unk_0e8) == 0 && other->m_128 == m_128 &&
        other->m_12c == m_12c && other->m_130 == m_130 && other->m_134 == m_134 && other->m_138 == m_138 &&
        reinterpret_cast<SubCmpC*>(&other->unk_13c)->Equal(&unk_13c) == 0)
        return true;
    return false;
}

struct WriteStream
{
    typedef unsigned int (*WriteFn)(WriteStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    WriteFn m_pfnWrite;
    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytes = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytes;
        return uiBytes;
    }
};

template <class T> inline void StreamSaveBinary(WriteStream& kStream, const T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&kValue, sizeof(T), &uiSize, 1);
}

// The output binary stream is stored at +0x250 in the original stream layout.
inline WriteStream* NiStream::GetWriter()
{
    return *reinterpret_cast<WriteStream**>(reinterpret_cast<char*>(this) + 0x250);
}

namespace fnv_00a929d0 {
// Links the stream's object to m_pObject, releasing the previous object and incrementing the new one's reference count.
// @fnv 0x00a929d0
// src: XBOX_PDB 0x00a929d0
void FUN_00a929d0_Holder::NiTextureEffect_LinkObject(NiStream& kStream)
{
    NiDynamicEffect::LinkObject(kStream);
    NiObject* pkObj = kStream.GetLoadedObject();
    NiObject* pOld = m_pObject;
    if (pOld != pkObj)
    {
        if (pOld && InterlockedDecrement(reinterpret_cast<volatile long*>(&pOld->m_uiRefCount)) == 0)
            pOld->DeleteThis();
        m_pObject = pkObj;
        if (pkObj)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&pkObj->m_uiRefCount));
    }
}
}  // namespace fnv_00a929d0

// NiPlane lacks SaveBinary; this adds only the missing method, with no local layout.
struct PlaneSaver : NiPlane
{
    void SaveBinary(NiStream& kStream);
};

struct TexEffectSaver : NiDynamicEffect
{
    NiMatrix3 m_kModelProjMat;
    NiPoint3 m_kModelProjTrans;
    NiMatrix3 m_kWorldProjMat;
    NiPoint3 m_kWorldProjTrans;

    NiObject* m_spSourceTexture;
    int m_eTextureFiltering;
    int m_eTextureClamping;
    int m_eTextureType;
    int m_eCoordGenType;
    bool m_bClippingPlaneEnable;
    PlaneSaver m_kModelPlane;
    void NiTextureEffect_SaveBinary(NiStream& kStream);
};

// Saves the dynamic effect base, model projection matrix and translation, texture settings, source texture link, clipping flag and model plane to the stream.
// @fnv 0x00a932f0
// src: XBOX_PDB 0x00a932f0
void TexEffectSaver::NiTextureEffect_SaveBinary(NiStream& kStream)
{
    NiDynamicEffect::SaveBinary(kStream);
    m_kModelProjMat.SaveBinary(kStream);
    m_kModelProjTrans.SaveBinary(&kStream);
    StreamSaveBinary(*kStream.GetWriter(), m_eTextureFiltering);
    StreamSaveBinary(*kStream.GetWriter(), m_eTextureClamping);
    StreamSaveBinary(*kStream.GetWriter(), m_eTextureType);
    StreamSaveBinary(*kStream.GetWriter(), m_eCoordGenType);
    kStream.SaveLinkID(reinterpret_cast<const NiObject*>(m_spSourceTexture));
    bool bClip = m_bClippingPlaneEnable;
    StreamSaveBinary(*kStream.GetWriter(), bClip);
    m_kModelPlane.SaveBinary(kStream);
}

#include "../../../../include/NiMemObject.h"
// @fnv 0x00a929b0
// src: EXE 0x00a929b0
void* __cdecl NiTextureEffect_CreateObject()
{
    NiTextureEffect* obj = (NiTextureEffect*)NiMemObject::operator new(0x15c);
    if (obj)
        return obj->InitializeEffect();
    return 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct TextureRef
{
    virtual void Destroy();
    virtual void DeleteThis();
    volatile long references;
};

struct TextureEffectCandidate
{
    unsigned field_000;
    unsigned field_004;
    unsigned field_008;
    unsigned field_00c;
    unsigned field_010;
    unsigned field_014;
    unsigned field_018;
    unsigned field_01c;
    unsigned field_020;
    unsigned field_024;
    unsigned field_028;
    unsigned field_02c;
    unsigned field_030;
    unsigned field_034;
    unsigned field_038;
    unsigned field_03c;
    unsigned field_040;
    unsigned field_044;
    unsigned field_048;
    unsigned field_04c;
    unsigned field_050;
    unsigned field_054;
    unsigned field_058;
    unsigned field_05c;
    unsigned field_060;
    unsigned field_064;
    unsigned field_068;
    unsigned field_06c;
    unsigned field_070;
    unsigned field_074;
    unsigned field_078;
    unsigned field_07c;
    unsigned field_080;
    unsigned field_084;
    unsigned field_088;
    unsigned field_08c;
    unsigned field_090;
    unsigned field_094;
    unsigned field_098;
    unsigned field_09c;
    unsigned field_0a0;
    unsigned field_0a4;
    unsigned field_0a8;
    unsigned field_0ac;
    unsigned field_0b0;
    unsigned field_0b4;
    unsigned field_0b8;
    unsigned field_0bc;
    unsigned field_0c0;
    NiMatrix3 matrix_c4;
    NiPoint3 vector_e8;
    unsigned field_0f4;
    unsigned field_0f8;
    unsigned field_0fc;
    unsigned field_100;
    unsigned field_104;
    unsigned field_108;
    unsigned field_10c;
    unsigned field_110;
    unsigned field_114;
    unsigned field_118;
    unsigned field_11c;
    unsigned field_120;
    TextureRef* texture_124;
    unsigned field_128, field_12c, field_130, field_134;
    bool field_138;
    unsigned field_13c, field_140, field_144, field_148;
    NiPlane vector_14c;
    void FUN_00a68d40(TextureEffectCandidate*, void*);
    void CopyTo(TextureEffectCandidate*, void*);
};
// Copies this candidate into dest via FUN_00a68d40, then copies the texture reference (with refcount add/release), matrix, vectors and trailing fields.
// @fnv 0x00a92f10
void TextureEffectCandidate::CopyTo(TextureEffectCandidate* dest, void* context)
{
    FUN_00a68d40(dest, context);
    TextureRef* oldTexture = dest->texture_124;
    if (oldTexture != texture_124)
    {
        if (oldTexture && !InterlockedDecrement(&oldTexture->references))
            oldTexture->DeleteThis();
        dest->texture_124 = texture_124;
        if (dest->texture_124)
            InterlockedIncrement(&dest->texture_124->references);
    }
    dest->matrix_c4 = matrix_c4;
    dest->vector_e8 = vector_e8;
    dest->field_128 = field_128;
    dest->field_12c = field_12c;
    dest->field_130 = field_130;
    dest->field_134 = field_134;
    dest->field_138 = field_138;
    dest->field_13c = field_13c;
    dest->field_140 = field_140;
    dest->field_144 = field_144;
    dest->field_148 = field_148;
    dest->vector_14c = vector_14c;
}

inline void StrArr::AppendInline(char* value)
{
    unsigned int index = m_usSize;
    if (index >= m_usMaxSize)
        SetSize(index + m_usGrowBy);
    SetAt(index, value);
}
// The shared class does not yet declare the dynamic-effect viewer method.
struct DynamicEffectViewer : NiDynamicEffect
{
    void FUN_00a69140(StrArr& strings);
};

struct PlaneViewer : PlaneSaver
{
    char* FUN_00a69a60(const char* name);
};
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* name);
char* __cdecl NiTextureEffect_GetViewerString(const char* name, int value);
char* __cdecl BuildFilterModeString(const char* name, int value);
char* __cdecl BuildTextureAddressModeString(const char* name, int value);
char* __cdecl BuildProjectionModeString(const char* name, int value);
char* __cdecl NiGetViewerString(const char* name, bool value);
struct TextureEffectViewer : DynamicEffectViewer
{
    NiMatrix3 modelProjMat;
    NiPoint3 modelProjTrans;
    NiMatrix3 worldProjMat;
    NiPoint3 worldProjTrans;
    NiObject* sourceTexture;
    int filter;
    int clamp;
    int textureMode;
    int coordMode;
    bool planeEnable;
    PlaneViewer modelPlane;
    void AppendToStrings(StrArr& strings);
};
// @fnv 0x00a93400
void TextureEffectViewer::AppendToStrings(StrArr& strings)
{
    FUN_00a69140(strings);
    strings.AppendInline(NiViewerStrings_NiGetViewerString_Title(reinterpret_cast<const char*>(g_011f5e94)));
    strings.AppendInline(modelProjMat.GetViewerString("m_kModelProjMat"));
    strings.AppendInline(modelProjTrans.GetViewerString_00a59af0("m_kModelProjTrans"));
    strings.AppendInline(NiTextureEffect_GetViewerString("m_eTextureMode", textureMode));
    strings.AppendInline(BuildFilterModeString("m_eFilter", filter));
    strings.AppendInline(BuildTextureAddressModeString("m_eClamp", clamp));
    strings.AppendInline(NiTextureEffect_GetViewerString("m_eTextureMode", textureMode));
    strings.AppendInline(BuildProjectionModeString("m_eCoordMode", coordMode));
    strings.AppendInline(NiGetViewerString("m_bPlaneEnable", planeEnable));
    strings.AppendInline(modelPlane.FUN_00a69a60("m_kModelPlane"));
}

// Preserve the original inline arithmetic while using the shared point and matrix layouts.
inline NiPoint3 SubtractProjectionPoints(const NiPoint3& a, const NiPoint3& b)
{
    NiPoint3 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}
inline float ProjectionDot(const NiPoint3& a, const NiPoint3& b)
{
    return a.y * b.y + a.x * b.x + a.z * b.z;
}
inline NiPoint3 ProjectPlaneNormal(const NiMatrix3& m, const NiPoint3& p)
{
    NiPoint3 result;
    result.x = m.m_pEntry[0][1] * p.y + m.m_pEntry[0][0] * p.x + m.m_pEntry[0][2] * p.z;
    result.y = m.m_pEntry[1][1] * p.y + m.m_pEntry[1][0] * p.x + m.m_pEntry[1][2] * p.z;
    result.z = m.m_pEntry[2][1] * p.y + m.m_pEntry[2][0] * p.x + m.m_pEntry[2][2] * p.z;
    return result;
}

struct TextureProjection
{
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned int unk060, unk064;
    NiMatrix3 worldRotation;
    NiPoint3 worldTranslation;
    float worldScale;
    unsigned int unk09c, unk0a0, unk0a4, revision;
    unsigned int unk0ac, unk0b0, unk0b4, unk0b8, unk0bc, unk0c0;
    NiMatrix3 modelProjection;
    NiPoint3 modelTranslation;
    NiMatrix3 worldProjection;
    NiPoint3 projectionTranslation;
    unsigned int sourceTexture, filtering, clamping, textureType, coordGenType;
    bool clippingEnabled;
    NiPoint3 modelPlaneNormal;
    float modelPlaneConstant;
    NiPoint3 worldPlaneNormal;
    float worldPlaneConstant;
    void UpdateWorldProjection();
};

// Builds worldProjection and projectionTranslation from coordGenType, computes the world plane normal and constant, and increments revision.
// @fnv 0x00a92c40
void TextureProjection::UpdateWorldProjection()
{
    float y;
    float* p = &y;
    if (coordGenType == 2)
    {
        projectionTranslation.x = projectionTranslation.y = 0.5f;
        projectionTranslation.z = 0.0f;
        *p = worldRotation.m_pEntry[0][1];
        worldProjection.m_pEntry[0][0] = 0.5 * worldRotation.m_pEntry[0][2];
        worldProjection.m_pEntry[1][0] = -0.5 * (*p);
        worldProjection.m_pEntry[2][0] = 0.0f;
        *p = worldRotation.m_pEntry[1][1];
        worldProjection.m_pEntry[0][1] = 0.5 * worldRotation.m_pEntry[1][2];
        worldProjection.m_pEntry[1][1] = -0.5 * (*p);
        worldProjection.m_pEntry[2][1] = 0.0f;
        *p = worldRotation.m_pEntry[2][1];
        worldProjection.m_pEntry[0][2] = 0.5 * worldRotation.m_pEntry[2][2];
        worldProjection.m_pEntry[1][2] = -0.5 * (*p);
        worldProjection.m_pEntry[2][2] = 0.0f;
    }
    else if (coordGenType == 3 || coordGenType == 4)
    {
        projectionTranslation.x = projectionTranslation.y = projectionTranslation.z = 0.0f;
        worldProjection = modelProjection.operator*(worldRotation.Transpose());
    }
    else
    {
        worldProjection = modelProjection.operator*(worldRotation.Transpose()).operator*(1.0f / worldScale);
        projectionTranslation = SubtractProjectionPoints(modelTranslation, worldProjection.operator*(worldTranslation));
    }
    NiPoint3 worldNormal;
    worldNormal = ProjectPlaneNormal(worldRotation, modelPlaneNormal);
    float fUnusedDot =
        worldTranslation.x * worldNormal.x + worldTranslation.y * worldNormal.y + worldTranslation.z * worldNormal.z;
    float fPlaneDist = ProjectionDot(worldTranslation, worldNormal);
    *p = fPlaneDist + modelPlaneConstant * worldScale;
    worldPlaneNormal = worldNormal;
    revision += 1;
    worldPlaneConstant = *p;
}

struct NiBinaryStreamL
{
    typedef unsigned int (*ReadFn)(NiBinaryStreamL*, void*, unsigned int, unsigned int*, unsigned int);
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    ReadFn m_pfnRead;
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytes = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytes;
        return uiBytes;
    }
};
template <class T> inline void StreamLoadBinary(NiBinaryStreamL& kStream, T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&kValue, sizeof(T), &uiSize, 1);
}
template <class T> inline void StreamLoadEnum(NiBinaryStreamL& kStream, T& eValue)
{
    unsigned int uiValue;
    StreamLoadBinary(kStream, uiValue);
    eValue = (T)uiValue;
}
// Input stream and file version accessors preserve the original stream layout.
inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}

inline unsigned int NiStream::GetFileVersion() const
{
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0xd8);
}

struct TexEffectLoader : NiDynamicEffect
{
    NiMatrix3 m_kModelProjMat;
    NiPoint3 m_kModelProjTrans;
    NiMatrix3 m_kWorldProjMat;
    NiPoint3 m_kWorldProjTrans;
    void* m_spSourceTexture;
    int m_eTextureFiltering;
    int m_eTextureClamping;
    int m_eTextureType;
    int m_eCoordGenType;
    bool m_bClippingPlaneEnable;
    NiPlane m_kModelPlane;
    void NiTextureEffect_LoadBinary(NiStream& kStream);
};
// @fnv 0x00a93140
// src: XBOX_PDB 0x00a93140
void TexEffectLoader::NiTextureEffect_LoadBinary(NiStream& kStream)
{
    NiDynamicEffect::LoadBinary(kStream);
    m_kModelProjMat.LoadBinary(kStream);
    m_kModelProjTrans.LoadBinary(kStream);
    StreamLoadEnum(*reinterpret_cast<NiBinaryStreamL*>(kStream.GetBinaryStream()), m_eTextureFiltering);
    StreamLoadEnum(*reinterpret_cast<NiBinaryStreamL*>(kStream.GetBinaryStream()), m_eTextureClamping);
    StreamLoadEnum(*reinterpret_cast<NiBinaryStreamL*>(kStream.GetBinaryStream()), m_eTextureType);
    StreamLoadEnum(*reinterpret_cast<NiBinaryStreamL*>(kStream.GetBinaryStream()), m_eCoordGenType);
    kStream.ResetStreamState();
    char bClip;
    StreamLoadBinary(*reinterpret_cast<NiBinaryStreamL*>(kStream.GetBinaryStream()), bClip);
    m_bClippingPlaneEnable = bClip != 0;
    m_kModelPlane.LoadBinary(kStream);
    if (kStream.GetFileVersion() < 0x0a030004)
    {
        short sPS2;
        StreamLoadBinary(*reinterpret_cast<NiBinaryStreamL*>(kStream.GetBinaryStream()), sPS2);
        StreamLoadBinary(*reinterpret_cast<NiBinaryStreamL*>(kStream.GetBinaryStream()), sPS2);
    }
    if (kStream.GetFileVersion() < 0x04010010)
    {
        short sTemp;
        StreamLoadBinary(*reinterpret_cast<NiBinaryStreamL*>(kStream.GetBinaryStream()), sTemp);
    }
}

// The constructor and copy targets are 0x00a92710 and 0x00a92f10, respectively.
// @fnv 0x00a930f0
NiTextureEffect* NiTextureEffect::Clone(CloningProcess& kCloning)
{
    NiTextureEffect* pkObject = new NiTextureEffect;
    CopyTo(pkObject, kCloning);
    return pkObject;
}

#include <string.h>
extern "C" void* __cdecl _NiMalloc(unsigned int);
int __cdecl NiSprintf(char*, unsigned int, const char*, ...);

// @fnv 0x00a92a60
// src: XBOX_PDB 0x00a92a60
char* __cdecl NiTextureEffect_GetViewerString(const char* pPrefix, unsigned int eMode)
{
    unsigned int uiLen = strlen(pPrefix) + 0x19;
    char* pString = static_cast<char*>(_NiMalloc(uiLen));
    switch (eMode)
    {
    case 0:
        NiSprintf(pString, uiLen, "%s = PROJECTED_LIGHT", pPrefix);
        break;
    case 1:
        NiSprintf(pString, uiLen, "%s = PROJECTED_SHADOW", pPrefix);
        break;
    case 2:
        NiSprintf(pString, uiLen, "%s = ENVIRONMENT_MAP", pPrefix);
        break;
    case 3:
        NiSprintf(pString, uiLen, "%s = FOG_MAP", pPrefix);
        break;
    }
    return pString;
}

namespace fnv_00a92b00 {
extern "C"
{
    void* __cdecl NiMalloc(unsigned int);
    int __cdecl NiSprintf(char*, unsigned int, const char*, ...);
}
// Allocates a buffer and formats pPrefix with a projection mode name selected by eMode into it.
// @fnv 0x00a92b00
char* __cdecl BuildProjectionModeString(const char* pPrefix, int eMode)
{
    unsigned int uiLen = strlen(pPrefix) + 25;
    char* pString = (char*)NiMalloc(uiLen);
    switch (eMode)
    {
    case 0:
        NiSprintf(pString, uiLen, "%s = WORLD_PARALLEL", pPrefix);
        return pString;
    case 1:
        NiSprintf(pString, uiLen, "%s = WORLD_PERSPECTIVE", pPrefix);
        return pString;
    case 2:
        NiSprintf(pString, uiLen, "%s = SPHERE_MAP", pPrefix);
        return pString;
    case 3:
        NiSprintf(pString, uiLen, "%s = SPECULAR_CUBE_MAP", pPrefix);
        return pString;
    case 4:
        NiSprintf(pString, uiLen, "%s = DIFFUSE_CUBE_MAP", pPrefix);
        return pString;
    default:
        NiSprintf(pString, uiLen, "%s = UNKNOWN!!!", pPrefix);
        return pString;
    }
}
}  // namespace fnv_00a92b00
