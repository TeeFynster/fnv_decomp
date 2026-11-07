// gamebryo2.2/corelibs/nianimation/nitexturetransformcontroller.cpp: NiTextureTransformController, NiNIFImageReader, TextureTransformOwner (20 functions)

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiAlphaController.h"
#include "../../../../include/BSFrustumFOVController.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiNIFImageReader.h"
#include "../../../../include/NiPoint2.h"
// NiStreamStandInW_nitexturetransformcontroller: local type (was include/NiStreamStandInW.h, which had no evidence of one real class); no method of it is bound to a named game function
class NiBinaryStreamW;

struct NiStreamStandInW_nitexturetransformcontroller
{
public:
    char _000[0x250];
    NiBinaryStreamW* m_pBackingStream;
};

#include "../../../../include/NiTextureTransformController.h"
#include "../../../../include/MemoryManager.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

int NiSprintf(char* buffer, unsigned int bufferSize, const char* format, ...);
void* _NiMalloc(unsigned int size);
void NiFree(void* pointer);


extern MemoryManager g_memoryManager;
extern const float DAT_01096324;

struct TextureShaderMaps
{
    unsigned int pad;
    NiTexturingProperty__Map** data;
    unsigned short capacity, size;
    NiTexturingProperty__Map* Get(unsigned int i)
    {
        return i < size ? data[i] : 0;
    }
};
struct TexturePropertyLayout
{
    char pad[0x20];
    NiTexturingProperty__Map** maps;
    unsigned short capacity, size;
    unsigned int pad28;
    TextureShaderMaps* shaders;
    unsigned int UpdateState_00a46410();
    NiTexturingProperty__Map* GetGeometryShaderObject(unsigned int i)
    {
        return shaders ? shaders->Get(i) : 0;
    }
};
inline NiPoint2::NiPoint2(float a, float b) : x(a), y(b)
{}
class TextureMapTransform
{
  public:
    NiPoint2 translate;
    float rotate;
    NiPoint2 scale;
    char pad[52];
    static void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }
    TextureMapTransform(const NiPoint2&, float, const NiPoint2&, const NiPoint2&, int) throw();
    void UpdateFromPair(const NiPoint2&);
    void SetValue(float);
    void NiTextureTransform_SetScale(const NiPoint2&);
};
extern const float DAT_01016248;
class NiTexturingProperty__Map
{
  public:
    char pad[12];
    TextureMapTransform* transform;
};


// Builds and caches a controller ID string from the transform member, formatting it as "%d-%d-<member>".
// @fnv 0x00a46300
const char* NiTextureTransformController::GetControllerID() const
{
    char* pCachedID = m_pCachedControllerID;
    if (pCachedID)
        return pCachedID;

    m_pCachedControllerID = (char*)_NiMalloc(0x32);
    switch (m_eTransformMember)
    {
    case NiTextureTransformController__TransformMember_TT_TRANSLATE_U:
        NiSprintf(m_pCachedControllerID, 0x32, "%d-%d-TT_TRANSLATE_U", m_bIsBumpMap, m_uiTextureMapIndex);
        break;
    case NiTextureTransformController__TransformMember_TT_TRANSLATE_V:
        NiSprintf(m_pCachedControllerID, 0x32, "%d-%d-TT_TRANSLATE_V", m_bIsBumpMap, m_uiTextureMapIndex);
        break;
    case NiTextureTransformController__TransformMember_TT_ROTATE:
        NiSprintf(m_pCachedControllerID, 0x32, "%d-%d-TT_ROTATE", m_bIsBumpMap, m_uiTextureMapIndex);
        break;
    case NiTextureTransformController__TransformMember_TT_SCALE_U:
        NiSprintf(m_pCachedControllerID, 0x32, "%d-%d-TT_SCALE_U", m_bIsBumpMap, m_uiTextureMapIndex);
        break;
    case NiTextureTransformController__TransformMember_TT_SCALE_V:
        NiSprintf(m_pCachedControllerID, 0x32, "%d-%d-TT_SCALE_V", m_bIsBumpMap, m_uiTextureMapIndex);
        break;
    }
    return m_pCachedControllerID;
}

// @fnv 0x00a46740
NiTextureTransformController::NiTextureTransformController(NiObjectNET* property, NiTexturingProperty__Map* map,
                                                           NiTextureTransformController__TransformMember member) throw()
    : m_eTransformMember(member)
{
    m_pCachedControllerID = 0;
    m_uiLastKeyIndex = 0;
    m_bIsBumpMap = false;
    m_uiTextureMapIndex = 0;
    if (m_pkTarget != property)
        m_pTaskMap = 0;
    NiTimeController::SetTarget(property);
    m_pTaskMap = map;
    if (!map)
    {
        NiFree(m_pCachedControllerID);
        m_pCachedControllerID = 0;
        return;
    }
    TexturePropertyLayout* prop = (TexturePropertyLayout*)m_pkTarget;
    if (!prop)
        return;
    for (unsigned int uiIndex = 0; uiIndex < prop->size; ++uiIndex)
    {
        if (prop->maps[uiIndex] == map)
        {
            m_bIsBumpMap = false;
            m_uiTextureMapIndex = uiIndex;
            NiFree(m_pCachedControllerID);
            m_pCachedControllerID = 0;
            IsTextureMapValid();
            return;
        }
    }
    unsigned int uiIndex = 0;
    unsigned int count = prop->UpdateState_00a46410();
    for (; uiIndex < count; ++uiIndex)
    {
        if (prop->GetGeometryShaderObject(uiIndex) == map)
        {
            m_bIsBumpMap = true;
            m_uiTextureMapIndex = uiIndex;
            NiFree(m_pCachedControllerID);
            m_pCachedControllerID = 0;
            if (!m_pTaskMap && m_pkTarget)
            {
                TexturePropertyLayout* p = (TexturePropertyLayout*)m_pkTarget;
                if (m_bIsBumpMap)
                {
                    NiTexturingProperty__Map* pMap = p->GetGeometryShaderObject(m_uiTextureMapIndex);
                    m_pTaskMap = pMap;
                }
                else
                    m_pTaskMap = p->maps[m_uiTextureMapIndex];
            }
            return;
        }
    }
}

// @fnv 0x00a46490
void NiTextureTransformController::Update(NiUpdateData& data)
{
    if (((unsigned char)(m_uiObjectFlags >> 5)) & 1)
        m_fControllerTime = DAT_01096324;
    else if (AdvanceController(data.fTime))
    {
        if (!m_spControllerInterpolator.m_pObject || !m_spControllerInterpolator.m_pObject->AlwaysUpdate())
            return;
    }
    if (!m_spControllerInterpolator.m_pObject)
        return;
    float value;
    if (!m_spControllerInterpolator.m_pObject->UpdateFloat(m_fControllerTime, m_pkTarget, value))
        return;
    if (!IsTextureMapValid())
        return;
    TextureMapTransform* transform = m_pTaskMap->transform;
    if (!transform)
    {
        void* memory = g_memoryManager.Allocate(sizeof(TextureMapTransform));
        transform = memory ? new (memory) TextureMapTransform(NiPoint2(0, 0), 0, NiPoint2(1, 1),
                                                             NiPoint2(DAT_01016248, DAT_01016248), 2)
                           : 0;
        m_pTaskMap->transform = transform;
    }
    switch (m_eTransformMember)
    {
    case NiTextureTransformController__TransformMember_TT_TRANSLATE_U: {
        NiPoint2 p = transform->translate;
        p.x = value;
        transform->UpdateFromPair(p);
        break;
    }
    case NiTextureTransformController__TransformMember_TT_TRANSLATE_V: {
        NiPoint2 p = transform->translate;
        p.y = value;
        transform->UpdateFromPair(p);
        break;
    }
    case NiTextureTransformController__TransformMember_TT_ROTATE:
        transform->SetValue(value);
        break;
    case NiTextureTransformController__TransformMember_TT_SCALE_U: {
        NiPoint2 p = transform->scale;
        p.x = value;
        transform->NiTextureTransform_SetScale(p);
        break;
    }
    case NiTextureTransformController__TransformMember_TT_SCALE_V: {
        NiPoint2 p = transform->scale;
        p.y = value;
        transform->NiTextureTransform_SetScale(p);
        break;
    }
    }
}

struct FUN_00a46480_shell : public NiTextureTransformController
{
    void* NiTextureTransformController_GetRTTI();
};

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f3f20;

// @fnv 0x00a46480
// src: COMMUNITY 0x00a46480
void* FUN_00a46480_shell::NiTextureTransformController_GetRTTI()
{
    return &g_011f3f20;
}

struct FUN_00a46410_shell
{
    void* m_0x2c;
    unsigned int __thiscall UpdateState_00a46410();
};

// @fnv 0x00a46410
// src: GUESS 0x00a46410 (confidence: low)
unsigned int __thiscall FUN_00a46410_shell::UpdateState_00a46410()
{
    void* p = *(void**)((char*)this + 0x2c);
    if (!p)
        return 0;
    return *(unsigned short*)((char*)p + 0xa);
}

struct FUN_00a461a0_shell : public NiTimeController
{
    void __thiscall NiTextureTransformController_SetTarget(NiObjectNET* target);
};

// @fnv 0x00a461a0
// src: GAMEBRYO_LIB 0x00a461a0
void __thiscall FUN_00a461a0_shell::NiTextureTransformController_SetTarget(NiObjectNET* target)
{
    if (*(NiObjectNET**)((char*)this + 0x2c) != target)
        *(int*)((char*)this + 0x3c) = 0;
    NiTimeController::SetTarget(target);
}

bool __stdcall FUN_00a57c10(NiObject*);
struct FUN_00a461e0_shell : public NiTextureTransformController
{
    bool NiTextureTransformController_IsEqual(NiObject* pkObject);
};
// Returns true if pkObject passes FUN_00a57c10 and its four fields match the expected values.
// @fnv 0x00a461e0
// src: GAMEBRYO_LIB 0x00a461e0
bool FUN_00a461e0_shell::NiTextureTransformController_IsEqual(NiObject* pkObject)
{
    NiTextureTransformController* pkCtrl = (NiTextureTransformController*)pkObject;
    if (FUN_00a57c10(pkObject) && pkCtrl->m_uiLastKeyIndex == m_uiLastKeyIndex &&
        pkCtrl->m_bIsBumpMap == m_bIsBumpMap && pkCtrl->m_uiTextureMapIndex == m_uiTextureMapIndex &&
        pkCtrl->m_eTransformMember == m_eTransformMember)
        return true;
    return false;
}

struct S00a46220
{
    float m_f0;
    float m_f1;
    char m_auiShapeKeys[20];
    bool m_flag;
    void UpdateFromPair(float* p);
};
// Sets m_flag if it was already set or the two floats differ from p[0] and p[1], then copies both floats from p into m_f0 and m_f1.
// @fnv 0x00a46220
void S00a46220::UpdateFromPair(float* afPair)
{
    m_flag = (m_flag || m_f0 != afPair[0] || m_f1 != afPair[1]);
    *(int*)&m_f0 = *(int*)afPair;
    *(int*)&m_f1 = *((int*)afPair + 1);
}

struct C462b0
{
    char _00[12];
    NiPoint2 m_0c;
    char _14[8];
    bool m_1c;
    void __thiscall NiTextureTransform_SetScale(NiPoint2* p);
};
// Sets m_1c if the stored m_0c differs from p, then copies p into m_0c.
// @fnv 0x00a462b0
// src: GAMEBRYO_LIB 0x00a462b0
void __thiscall C462b0::NiTextureTransform_SetScale(NiPoint2* p)
{
    m_1c = m_1c || m_0c.x != p->x || m_0c.y != p->y;
    m_0c = *p;
}

struct FUN_00a463e0_Inner
{
    unsigned int m_iWordAt00;
    void** m_iWordAt04;
    unsigned short m_8;
    unsigned short m_kPointA;
};
struct FUN_00a463e0_Holder
{
    unsigned char _pad[0x2c];
    FUN_00a463e0_Inner* m_2c;
    void* __thiscall GetElementAt(unsigned int);
};
// Returns the element at index from the array held by m_2c if it exists and index is below its count, otherwise returns 0.
// @fnv 0x00a463e0
void* __thiscall FUN_00a463e0_Holder::GetElementAt(unsigned int index)
{
    FUN_00a463e0_Inner* p = m_2c;
    if (p && index < p->m_kPointA)
        return p->m_iWordAt04[index];
    return 0;
}

inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
inline void __cdecl operator delete(void*, void*)
{}
struct FUN_00a468f0_shell
{
    NiTextureTransformController* __thiscall Clone(CloningProcess& kCloning);
};
// @fnv 0x00a468f0
NiTextureTransformController* __thiscall FUN_00a468f0_shell::Clone(CloningProcess& kCloning)
{
    NiTextureTransformController* pkObject;
    pkObject = (NiTextureTransformController*)BSFadeNode::operator new(0x50);
    if (pkObject)
        pkObject = ::new (pkObject) NiTextureTransformController(0, 0, (NiTextureTransformController__TransformMember)0);
    else
        pkObject = 0;
    ((NiAlphaController*)this)->CopyMemberData((NiAlphaController*)pkObject, kCloning);
    *(unsigned int*)((char*)pkObject + 0x38) = *(unsigned int*)((char*)this + 0x38);
    *(unsigned char*)((char*)pkObject + 0x40) = *(unsigned char*)((char*)this + 0x40);
    *(unsigned int*)((char*)pkObject + 0x44) = *(unsigned int*)((char*)this + 0x44);
    *(unsigned int*)((char*)pkObject + 0x48) = *(unsigned int*)((char*)this + 0x48);
    return pkObject;
}

void __stdcall NiFloatInterpController_GetViewerStrings(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
// Ensures pkStrings has room, then stores the string returned by _FUN_00a7d330 at index m_0A.
// @fnv 0x00a46ac0
// src: XBOX_PDB 0x00a46ac0
void __stdcall NiTextureTransformController_GetViewerStrings(StrArr* pkStrings)
{
    NiFloatInterpController_GetViewerStrings(pkStrings);
    char* pszString = _FUN_00a7d330(*(const char**)&g_011f3f20);
    unsigned int uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIndex + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiIndex, pszString);
}

void __fastcall UpdateMatrix(void*);

// Copies two fields each from s, t and u, stores f and d, calls UpdateMatrix on this, and returns this.
// @fnv 0x00a88eb0
NiNIFImageReader* NiNIFImageReader::InitFromInputs(const NiNIFImageReader* apSource, float afValue,
                                                   const NiNIFImageReader* apSecond, const NiNIFImageReader* apThird,
                                                   NiNIFImageReader* d)
{
    // This entry point initializes transform storage at the original object offsets.
    // NiNIFImageReader's inherited reader layout does not describe that storage.
    reinterpret_cast<void**>(this)[0] = reinterpret_cast<void* const*>(apSource)[0];
    reinterpret_cast<void**>(this)[1] = reinterpret_cast<void* const*>(apSource)[1];
    reinterpret_cast<float*>(this)[2] = afValue;
    reinterpret_cast<void**>(this)[3] = reinterpret_cast<void* const*>(apSecond)[0];
    reinterpret_cast<void**>(this)[4] = reinterpret_cast<void* const*>(apSecond)[1];
    reinterpret_cast<void**>(this)[5] = reinterpret_cast<void* const*>(apThird)[0];
    reinterpret_cast<void**>(this)[6] = reinterpret_cast<void* const*>(apThird)[1];
    reinterpret_cast<void**>(this)[17] = d;
    UpdateMatrix(this);
    return this;
}

struct FUN_00a46660_shell : public NiTextureTransformController
{
    void GetTextureTransformValue(float& value);
};
// @fnv 0x00a46660
void FUN_00a46660_shell::GetTextureTransformValue(float& value)
{
    NiPoint2 kPoint;
    if (IsTextureMapValid())
    {
        TextureMapTransform* transform = m_pTaskMap->transform;
        if (!transform)
        {
            value = 0.0f;
            return;
        }
        switch (m_eTransformMember)
        {
        case NiTextureTransformController__TransformMember_TT_TRANSLATE_U:
            kPoint = *(NiPoint2*)transform;
            value = kPoint.x;
            break;
        case NiTextureTransformController__TransformMember_TT_TRANSLATE_V:
            kPoint = *(NiPoint2*)transform;
            value = kPoint.y;
            break;
        case NiTextureTransformController__TransformMember_TT_ROTATE:
            value = *(float*)((char*)transform + 8);
            break;
        case NiTextureTransformController__TransformMember_TT_SCALE_U:
            kPoint = *(NiPoint2*)((char*)transform + 12);
            value = kPoint.x;
            break;
        case NiTextureTransformController__TransformMember_TT_SCALE_V:
            kPoint = *(NiPoint2*)((char*)transform + 12);
            value = kPoint.y;
            break;
        }
    }
}

class FUN_00a46270_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    float m_f08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned char m_b1C;
    void SetValue(float v);
};

// @fnv 0x00a46270
void FUN_00a46270_cls::SetValue(float afValue)
{
    int r;
    if (m_b1C == 0 && m_f08 == afValue)
    {
        r = 0;
    }
    else
    {
        r = 1;
    }
    m_f08 = afValue;
    m_b1C = r;
}

struct NiBinaryStreamW
{
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    char _08[4];
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStreamW* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
    template <class T> unsigned int Write(const T* pValue)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pValue, sizeof(T), &uiSize, 1);
    }
};

struct FUN_00a46a30_Cls
{
    char _00[0x40];
    unsigned char m_40;
    unsigned int m_44;
    unsigned int m_48;
    void __thiscall NiBoolInterpController_SaveBinary(NiStreamStandInW_nitexturetransformcontroller* pkStream);
    void __thiscall WriteToStream(NiStreamStandInW_nitexturetransformcontroller* pkStream);
};

// @fnv 0x00a46a30
void __thiscall FUN_00a46a30_Cls::WriteToStream(NiStreamStandInW_nitexturetransformcontroller* pkStream)
{
    NiBoolInterpController_SaveBinary(pkStream);
    unsigned char ucFlag = m_40;
    pkStream->m_pBackingStream->Write(&ucFlag);
    pkStream->m_pBackingStream->Write(&m_44);
    pkStream->m_pBackingStream->Write(&m_48);
}

void __cdecl _NiFree_00aa10f0(void* memory);
void __cdecl FUN_00aa1460(void* memory, unsigned int size);

struct InterpolationControllerBase
{
    virtual ~InterpolationControllerBase() throw();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int unk1c, unk20, unk24, unk28, unk2c, unk30;
};

struct TextureTransformOwner : InterpolationControllerBase
{
    NiPointer<NiRefObject> interpolator;
    unsigned int unk38, unk3c, unk40, unk44, unk48;
    char* controllerID;
    virtual ~TextureTransformOwner() throw()
    {
        _NiFree_00aa10f0(controllerID);
        controllerID = 0;
    }
    void* FUN_00a46890(unsigned int flags);
    static void operator delete(void* memory, unsigned int size)
    {
        FUN_00aa1460(memory, size);
    }
};

// Destroys the object and, if the first bit of flags is set, frees its memory with FUN_00aa1460.
// @fnv 0x00a46890
void* TextureTransformOwner::FUN_00a46890(unsigned int flags)
{
    this->TextureTransformOwner::~TextureTransformOwner();
    if (flags & 1)
        FUN_00aa1460(this, sizeof(TextureTransformOwner));
    return this;
}

struct S7 : NiTextureTransformController
{
    bool GetTaskMap();
};
// Returns true if m_pTaskMap is set, otherwise resolves it from the target TexturePropertyLayout and returns whether it was found.
// @fnv 0x00a46420
bool S7::GetTaskMap()
{
    if (m_pTaskMap)
        return true;
    TexturePropertyLayout* p = reinterpret_cast<TexturePropertyLayout*>(m_pkTarget);
    if (!p)
        return false;
    if (m_bIsBumpMap)
        m_pTaskMap = p->GetGeometryShaderObject(m_uiTextureMapIndex);
    else
        m_pTaskMap = p->maps[m_uiTextureMapIndex];
    return m_pTaskMap ? true : false;
}

struct S00a46970_BinStream
{
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(S00a46970_BinStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryRead(void* pv, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pv, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};
template <class T>
inline unsigned int S00a46970_BinaryStreamLoad(S00a46970_BinStream& istr, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return istr.BinaryRead(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}
struct S00a46970_Stream
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    unsigned int m_uiNifVersion;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    S00a46970_BinStream* m_pUnderlyingStream;
};
template <class T> inline void S00a46970_StreamLoadBinary(S00a46970_Stream& kStream, T& value)
{
    S00a46970_BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value, 1);
}
struct S00a46970_Base
{
    void FUN_00a57c70(S00a46970_Stream& kStream);
};
struct S00a46970_StreamFix
{
    void ReadLinkID();
};
struct S00a46970_Ctlr : public NiTextureTransformController
{
    void NiTextureTransformController_LoadBinary(S00a46970_Stream& kStream);
};
// @fnv 0x00a46970
// src: XBOX_PDB 0x00a46970
void S00a46970_Ctlr::NiTextureTransformController_LoadBinary(S00a46970_Stream& kStream)
{
    reinterpret_cast<S00a46970_Base*>(this)->FUN_00a57c70(kStream);
    bool bShaderMap;
    S00a46970_StreamLoadBinary(kStream, bShaderMap);
    m_bIsBumpMap = bShaderMap != 0;
    S00a46970_StreamLoadBinary(kStream, m_uiTextureMapIndex);
    unsigned int uiMember;
    S00a46970_StreamLoadBinary(kStream, uiMember);
    m_eTransformMember = (NiTextureTransformController__TransformMember)uiMember;
    if (kStream.m_uiNifVersion < 0x0a010068)
        reinterpret_cast<S00a46970_StreamFix*>(&kStream)->ReadLinkID();
}

// @fnv 0x00a46950
// src: EXE 0x00a46950
NiTextureTransformController* __cdecl NiTextureTransformController_CreateObject()
{
    void* storage = BSFadeNode::operator new(sizeof(NiTextureTransformController));
    if (storage != 0)
        return ::new (storage)
            NiTextureTransformController(0, 0, NiTextureTransformController__TransformMember_TT_TRANSLATE_U);
    return 0;
}
