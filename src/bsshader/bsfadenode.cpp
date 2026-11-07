#include "../../include/SettingT.h"
// bsshader/bsfadenode.cpp: BSFadeNode, NiFixedString, BSShaderManager, FadeViewer and more (22 functions)

#include "../../include/BSFadeNode.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiNode.h"
#include "../../include/BSTreeNode.h"
#include "../../include/NiAlphaProperty.h"
#include "../../include/Bound.h"
// LocalPt3: unit-local copy of the former shared stand-in Pt3. Same layout as NiPoint3; with NiPoint3 (its __forceinline constructor and in-class Dot), FadeNodeObj::FUN_00b4e490 (0x00b4e490) does not match.
class LocalPt3
{
public:
    float x;
    float y;
    float z;

    LocalPt3();
    LocalPt3(float fX, float fY, float fZ);

    LocalPt3 operator+(const LocalPt3& other) const;
    LocalPt3 operator-(const LocalPt3& other) const;
    LocalPt3 operator-() const;
    LocalPt3 operator*(float scale) const;
    LocalPt3& operator*=(float scale);
    bool operator!=(const LocalPt3& other) const;

    float Dot(const LocalPt3& other) const;
    float DotAccumulated(const LocalPt3& other) const;
    float DotPlane(const LocalPt3& other) const;
    float DotProduct(const LocalPt3& other) const;
    LocalPt3 Cross(const LocalPt3& other) const;
    float SqrLength() const;
    float Length2() const;
    float Length() const;
    float Len() const;
    float GetSquaredXYLength();
    float GetSquaredXYLength() const;

    void Unitize_004a0c10();
    LocalPt3* SubtractIntoVector(LocalPt3* out, LocalPt3* other);
    LocalPt3 SubtractIntoVector(const LocalPt3& rhs);
    bool FUN_00439090(LocalPt3* other);
    float FUN_00457990() const;

    static const LocalPt3 ms_kFirstPoint;
    static const LocalPt3 ms_kSecondPoint;
    static const LocalPt3 ms_kThirdPoint;
};
#include "../../include/NiPoint3.h"
#include <math.h>
#include "../../include/BSShaderManager.h"
#include "../../include/ImageSpaceManager.h"
#include "../../include/Setting.h"
#include "../../include/NiStream.h"
#include "../../include/MemoryManager.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

extern MemoryManager g_memoryManager;

using ::SettingT;

typedef char BSFadeNodeSizeCheck[sizeof(BSFadeNode) == 0xE4 ? 1 : -1];
typedef char NiAlphaPropertySizeCheck[sizeof(NiAlphaProperty) == 0x1C ? 1 : -1];
// PC depth texture forwarding declarations. The singleton has no known
// canonical data name, so its address-based name is kept here.
extern ImageSpaceManager* DAT_011f91ac;

// Keep the original inline bodies with the shared class declarations.
inline NiAlphaProperty::NiAlphaProperty() : m_usAlphaArg(0xEC), m_ucAlphaArg2(0)
{}

inline void NiObjectNET::DecRefCount()
{
    if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
        DeleteThis();
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (pkNew)
            InterlockedIncrement((volatile long*)&pkNew->m_uiRefCount);
    }
    return *this;
}

template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

inline void* NiFixedString::operator new(size_t n)
{
    return g_memoryManager.Allocate(n);
}


inline LocalPt3::LocalPt3()
{}

inline LocalPt3::LocalPt3(float fx, float fy, float fz) : x(fx), y(fy), z(fz)
{}

inline float LocalPt3::Dot(const LocalPt3& pt) const
{
    return x * pt.x + y * pt.y + z * pt.z;
}

inline LocalPt3 LocalPt3::operator-(const LocalPt3& other) const
{
    return LocalPt3(x - other.x, y - other.y, z - other.z);
}

inline float LocalPt3::Length() const
{
    return sqrtf(x * x + y * y + z * z);
}


// @fnv 0x00b4e270
void BSFadeNode::InitializeMultiBounds()
{
    ms_pAlphaProperty = new NiAlphaProperty;
    ms_pAlphaProperty->m_usAlphaArg |= 1;
    ms_pFadeNodeAnimationName = new NiFixedString("FadeNode Anim");
}

// Allocates and returns a new BSFadeNode instance.
// @fnv 0x00b4eaa0
NiObject* BSFadeNode::CreateObject()
{
    return new BSFadeNode;
}

// Clamps nearDistance to the INI setting's integer value and raises farDistance to twice that minimum, then stores both into fNearDistSqr and fFarDistSqr.
// @fnv 0x00b4dfd0
void BSFadeNode::SetRange(float nearDistance, float farDistance)
{
    float minDistance =
        (float)reinterpret_cast<const volatile int&>(
            static_cast<const volatile SettingT<INISettingCollection>&>(ms_kMinimumFadeDistanceSetting).uValue);
    if (nearDistance < minDistance)
    {
        nearDistance = minDistance;
        if (farDistance < minDistance * 2.0f)
            farDistance = minDistance * 2.0f;
    }
    fNearDistSqr = nearDistance;
    fFarDistSqr = farDistance;
}

// @fnv 0x00b4f530
BSRenderedTexture* BSShaderManager::GetSceneDepthRenderedTexture()
{
    return DAT_011f91ac->GetDepthRenderedTexture();
}

typedef char _sizecheck_BSTreeNode[sizeof(BSTreeNode) == 304 ? 1 : -1];
struct FUN_00b4def0_shell : public BSFadeNode
{
    bool BSFadeNode_RegisterStreamables(NiStream*);
};

struct FUN_00a5e5b0_helper
{
    unsigned char RegisterChildStreamables(NiStream*);
};

// @fnv 0x00b4def0
// src: XBOX_PDB 0x00b4def0
bool FUN_00b4def0_shell::BSFadeNode_RegisterStreamables(NiStream* arStream)
{
    if (!((FUN_00a5e5b0_helper*)this)->RegisterChildStreamables(arStream))
        return false;
    return true;
}

struct Dummy
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual char* v4();
};

// @fnv 0x00b4dfb0
void __cdecl SetFlagOnVirtualResult(Dummy* apDummy)
{
    if (apDummy)
    {
        char* r = apDummy->v4();
        if (r)
        {
            *(unsigned int*)(r + 0x30) |= 0x20000;
        }
    }
}

// Recursively frees the linked list hanging off self[1], deallocating each node, then clears self[0].
// @fnv 0x00b4df30
// src: GUESS 0x00b4df30 (confidence: medium)
void __fastcall BSFadeNode_FreeLinkedNodesRecursively(void* p)
{
    void** self = (void**)p;
    if (self[1])
    {
        void* next;
        do
        {
            void* node = self[1];
            next = *(void**)((char*)node + 4);
            *(void**)((char*)node + 4) = 0;
            void* pCurrent = self[1];
            if (pCurrent)
            {
                BSFadeNode_FreeLinkedNodesRecursively(pCurrent);
                g_memoryManager._DeallocateAlias(pCurrent);
            }
            self[1] = next;
        } while (next);
    }
    self[0] = 0;
}

double(__cdecl* DAT_011f9134)(void*);

// Returns the result of calling the DAT_011f9134 function pointer on param_1, or 1.0f if the pointer is null.
// @fnv 0x00b4df80
// src: COMMUNITY 0x00b4df80
float __fastcall BSFadeNode_GetMaxAlpha(void* param_1)
{
    float f;
    if (DAT_011f9134)
        f = DAT_011f9134(param_1);
    else
        f = 1.0f;
    return f;
}

struct FUN_00b4dec0_shell : public BSFadeNode
{
    void BSFadeNode_SetLODMultType(int);
};

// @fnv 0x00b4dec0
// src: XBOX_PDB 0x00b4dec0
void FUN_00b4dec0_shell::BSFadeNode_SetLODMultType(int aeMultType)
{
    *(int*)((char*)this + 0xc4) = aeMultType;
}

// @fnv 0x00b4e3f0
// src: XBOX_PDB 0x00b4e3f0
void* __fastcall BSFadeNode_CreateClone(void* apSource, int dummy, void* kCloning)
{
    BSFadeNode* pFadeNode = new BSFadeNode();
    ((NiNode*)apSource)->CopyMemberData((NiNode*)pFadeNode, *(CloningProcess*)kCloning);
    *(unsigned int*)((char*)pFadeNode + 0x30) &= 0xfffd3fff;
    *(float*)((char*)pFadeNode + 0xac) = *(float*)((char*)apSource + 0xac);
    *(float*)((char*)pFadeNode + 0xb0) = *(float*)((char*)apSource + 0xb0);
    *(void**)((char*)pFadeNode + 0xc4) = *(void**)((char*)apSource + 0xc4);
    return pFadeNode;
}

struct FUN_00b4ed40_t
{
    void FUN_00b4e1e0();
    FUN_00b4ed40_t* FUN_00b4ed40(unsigned char flags);
};
void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);
// Calls FUN_00b4e1e0, then if bit 0 of flags is set calls __Dummy_00b6fef0 on this with size 0xe4, and returns this.
// @fnv 0x00b4ed40
FUN_00b4ed40_t* FUN_00b4ed40_t::FUN_00b4ed40(unsigned char flags)
{
    FUN_00b4e1e0();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0xe4);
    return this;
}

// @fnv 0x00b4e380
void __cdecl ReleaseFadeNodeResources()
{
    if (BSFadeNode::ms_pAlphaProperty.m_pObject)
    {
        BSFadeNode::ms_pAlphaProperty.m_pObject->DecRefCount();
        BSFadeNode::ms_pAlphaProperty.m_pObject = 0;
    }
    NiFixedString* animName = BSFadeNode::ms_pFadeNodeAnimationName;
    if (BSFadeNode::ms_pFadeNodeAnimationName)
    {
        BSFadeNode::ms_pFadeNodeAnimationName->~NiFixedString();
        g_memoryManager.Deallocate(animName);
    }
    BSFadeNode::ms_pFadeNodeAnimationName = 0;
}

extern unsigned char DAT_011ad7b4;
extern int DAT_011f36ac;

bool __cdecl FUN_00b4ea20_probe(void* obj);

struct FUN_00b4ea20_child
{
    unsigned char unk00[0xc];
    void Apply(void* arg);
};

struct FUN_00b4ea20_mid
{
    unsigned char unk00[0xc];
    FUN_00b4ea20_child* m_pChildObject;
};

struct FUN_00b4ea20_holder
{
    FUN_00b4ea20_mid* m_pMid;
};

class FUN_00b4ea20_cls
{
  public:
    unsigned char unk00[0xa0];
    FUN_00b4ea20_holder* m_pHolder;
    unsigned char unkA4[2];
    unsigned short m_uA6;
    unsigned char unkA8[0x18];
    float m_fC0;
    void Tail(float* p, int v);
    void BSFadeNode_UpdateSelectedDownwardPass(float* p, int v);
};

// @fnv 0x00b4ea20
// src: XBOX_PDB 0x00b4ea20
void FUN_00b4ea20_cls::BSFadeNode_UpdateSelectedDownwardPass(float* apValue, int aiValue)
{
    if (DAT_011ad7b4 == 0)
    {
        m_fC0 = *apValue;
        if (*apValue > 0.0f)
        {
            bool notSet = (FUN_00b4ea20_probe(this) == false);
            if (notSet)
            {
                if (m_uA6 > 0 && notSet)
                {
                    FUN_00b4ea20_mid* pMid = m_pHolder->m_pMid;
                    if (pMid != 0)
                    {
                        FUN_00b4ea20_child* pChild = pMid->m_pChildObject;
                        if (pChild != 0)
                        {
                            pChild->Apply(&DAT_011f36ac);
                        }
                    }
                }
            }
        }
    }
    Tail(apValue, aiValue);
}

struct Strings
{
    void* vtable;
    char** data;
    unsigned short capacity, size, count, grow;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char*&);
    void Add(char*& text)
    {
        unsigned int index = size;
        if (index >= capacity)
            FUN_0096ad30(index + grow);
        FUN_0096ae90(index, text);
    }
};
struct Extra
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void Viewer(Strings*);
};
extern const char* DAT_011f9140;
extern void* DAT_01202ddc;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
char* __cdecl NiGetViewerString_00a7d550(const char*, float);
char* __cdecl NiGetViewerString_00a7d4d0(const char*, int);
struct ViewerBool
{
    bool value;
};
char* __cdecl FlagString(const char*, ViewerBool);
int __cdecl BSsprintf(char*, unsigned int, const char*, ...);
struct FadeViewer
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    unsigned int field50;
    unsigned int field54;
    unsigned int field58;
    unsigned int field5c;
    unsigned int field60;
    unsigned int field64;
    unsigned int field68;
    unsigned int field6c;
    unsigned int field70;
    unsigned int field74;
    unsigned int field78;
    unsigned int field7c;
    unsigned int field80;
    unsigned int field84;
    unsigned int field88;
    unsigned int field8c;
    unsigned int field90;
    unsigned int field94;
    unsigned int field98;
    unsigned int field9c;
    unsigned int fielda0;
    unsigned int fielda4;
    unsigned int fielda8;
    float nearDist, farDist, lastFade, currentFade, boundRadius, timeSinceUpdate;
    int multType, frameCounter;
    void NiNode_GetViewerStrings(Strings*);
    Extra* FUN_00a5bdd0(void*);
    void BSFadeNode_GetViewerStrings(Strings* strings);
};
// Appends formatted fade-viewer fields and bit flags from field30 to the strings list, then forwards to an Extra viewer if found.
// @fnv 0x00b4ed70
// src: XBOX_PDB 0x00b4ed70
void FadeViewer::BSFadeNode_GetViewerStrings(Strings* strings)
{
    NiNode_GetViewerStrings(strings);
    {
        char* text = NiViewerStrings_NiGetViewerString_Title(DAT_011f9140);
        strings->Add(text);
        float fNearDist = nearDist;
        float fFarDist = farDist;
        text = (char*)g_memoryManager.Allocate(64);
        if (fNearDist == 3.4028234663852886e38)
            BSsprintf(text, 64, "fNearDistSqr = DISABLED");
        else
            BSsprintf(text, 64, "fNearDistSqr = %.2f", fNearDist);
        strings->Add(text);
        text = (char*)g_memoryManager.Allocate(64);
        if (fFarDist == 3.4028234663852886e38)
            BSsprintf(text, 64, "fFarDistSqr = DISABLED");
        else
            BSsprintf(text, 64, "fFarDistSqr = %.2f", fFarDist);
        strings->Add(text);
        text = (char*)g_memoryManager.Allocate(64);
        BSsprintf(text, 64, "eMultType = %d", multType);
        strings->Add(text);
        text = NiGetViewerString_00a7d550("fLastFade", lastFade);
        strings->Add(text);
        text = NiGetViewerString_00a7d550("fCurrentFade", currentFade);
        strings->Add(text);
        text = NiGetViewerString_00a7d550("fTimeSinceUpdate", timeSinceUpdate);
        strings->Add(text);
        text = NiGetViewerString_00a7d4d0("iFrameCounter", frameCounter);
        strings->Add(text);
    }
    {
        ViewerBool flag;
        flag.value = (field30 >> 14) & 1;
        char* text = FlagString("bFadedIn", flag);
        strings->Add(text);
    }
    {
        ViewerBool flag;
        flag.value = (field30 >> 15) & 1;
        char* text = FlagString("bIgnoreFade", flag);
        strings->Add(text);
    }
    {
        ViewerBool flag;
        flag.value = (field30 >> 16) & 1;
        char* text = FlagString("bLODFadingOut", flag);
        strings->Add(text);
    }
    {
        ViewerBool flag;
        flag.value = (field30 >> 17) & 1;
        char* text = FlagString("bHasMovingSound", flag);
        strings->Add(text);
    }
    {
        ViewerBool flag;
        flag.value = (field30 >> 24) & 1;
        char* text = FlagString("bHighDetail", flag);
        strings->Add(text);
    }
    Extra* extra = FUN_00a5bdd0(DAT_01202ddc);
    if (extra)
        extra->Viewer(strings);
}

void FUN_00a5dd70();

// @fnv 0x00b4ded0
// src: XBOX_PDB 0x00b4ded0
void BSFadeNode_UpdateDownwardPass()
{
    FUN_00a5dd70();
}

void NiNode_LoadBinary();
// @fnv 0x00b4dee0
// src: XBOX_PDB 0x00b4dee0
void BSFadeNode_LoadBinary()
{
    NiNode_LoadBinary();
}

struct Cls00b4df20
{
    bool NiNode_IsEqual(Cls00b4df20* other);
    bool BSFadeNode_IsEqual(Cls00b4df20* other);
};

// @fnv 0x00b4df20
// src: XBOX_PDB 0x00b4df20
bool Cls00b4df20::BSFadeNode_IsEqual(Cls00b4df20* other)
{
    return NiNode_IsEqual(other);
}

struct Fade
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Bound* unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    float unk8c;
    float unk90;
    float unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    float unkac;
    float unkb0;
    float unkb4;
    float unkb8;
    float unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    float unk110;
    bool UpdateFade(Fade* camera, int unused);
};
extern unsigned char DAT_011ad7b4;
extern float DAT_011ad7b8[];
extern int DAT_011f9138;
extern float DAT_011ad7f4, DAT_011ad7f0;
void FUN_00b6bb30(Fade*, float);
// @fnv 0x00b4eb10
bool Fade::UpdateFade(Fade* camera, int unused)
{
    float alpha = 1.0f;
    if (DAT_011ad7b4)
    {
        float scale = camera->unk110;
        NiPoint3 vDelta;
        vDelta.x = unk8c - camera->unk8c;
        vDelta.y = unk90 - camera->unk90;
        vDelta.z = unk94 - camera->unk94;
        float mult = 1.0f;
        if (unkc4 > 0 && unkc4 < 11)
            mult = DAT_011ad7b8[unkc4];
        if (unkc4 == 6)
        {
            unk30 &= ~0x4000;
            unkb4 = unkb8 = 0.0f;
        }
        else
        {
            if (unkc4 == 10)
                return true;
            if (unkb0 > 2600.0f)
            {
                unkb0 = 2600.0f;
                unkac = 1300.0f;
                if (unkc8 < DAT_011f9138 - 20)
                {
                    unk30 &= ~0x4000;
                    unkb4 = unkb8 = 0.0f;
                }
            }
        }
        if (unk20)
            unkbc = unk20->radius;
        if (unkc4 == 1 || unkc4 == 5 || unkc4 == 4 || unkc4 == 6)
        {
            unkc8 = DAT_011f9138;
            return false;
        }
        if (mult > 0.0f)
        {
            scale /= mult;
            float dist = vDelta.FUN_00457990();
            if (dist < 0.0f)
                dist = 0.0f;
            dist *= scale;
            float nearDist = unkac * DAT_011ad7f4;
            float farDist = unkb0 * DAT_011ad7f4;
            if (dist > farDist)
                return false;
            if (dist > nearDist)
            {
                float range = farDist - nearDist;
                float fade = 1.0f - (dist - nearDist) / range;
                if (fade < DAT_011ad7f0)
                    return false;
            }
        }
        else if (mult == 0.0f)
        {
            unk30 |= 0x4000;
            unkb4 = unkb8 = 1.0f;
            FUN_00b6bb30(this, 1.0f);
            return true;
        }
    }
    unk30 |= 0x4000;
    unkb4 = unkb8 = alpha;
    FUN_00b6bb30(this, alpha);
    return true;
}

class NiCamera;

struct FUN_00b4e030_shell : public BSFadeNode
{
    bool IsWithinFadeDistance(NiCamera*, float);
};

extern float DAT_011ad7b8[];
extern float DAT_011ad7f4;


// Checks whether the camera is within the node's fade distance, adjusted by a per-state factor, and returns true if the scaled distance is below the fade limit.
// @fnv 0x00b4e030
bool FUN_00b4e030_shell::IsWithinFadeDistance(NiCamera* apCamera, float afDistMult)
{
    float ffadeAdjust = *(float*)((char*)apCamera + 0x110);
    if (*(int*)((char*)this + 0xc4) == 9)
        return false;
    if (*(int*)((char*)this + 0xc4) >= 0 && *(int*)((char*)this + 0xc4) < 11)
    {
        float fdiff = DAT_011ad7b8[*(int*)((char*)this + 0xc4)];
        if (fdiff != 0.0f)
            ffadeAdjust = ffadeAdjust / fdiff;
    }
    const LocalPt3& kA = *(LocalPt3*)((char*)this + 0x8c);
    const LocalPt3& kB = *(LocalPt3*)((char*)apCamera + 0x8c);
    LocalPt3 kDiff(kA.x - kB.x, kA.y - kB.y, kA.z - kB.z);
    float fDist = sqrtf(kDiff.Dot(kDiff)) * afDistMult;
    if (fDist < 0.0f)
        fDist = 0.0f;
    float fadeMult = fDist * ffadeAdjust;
    if (fadeMult > *(float*)((char*)this + 0xb0) * DAT_011ad7f4)
        return false;
    return true;
}

namespace fnv_00b4e490 {

struct FadeCamera
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    LocalPt3 m_kWorldTranslate;  // 0x8c
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    float m_fTrailingValue;  // 0x110
};

struct FadeCuller
{
    int unk00;
    int unk04;
    int unk08;
    FadeCamera* m_pCamera;  // 0x0c
};

struct FadeQueue
{
    void RenderBound(const char* name, int b);
    void DispatchBatchRenderer();
};

struct FadeQueueHolder
{
    int unk00;
    int unk04;
    FadeQueue* m_pQueue;
};

extern char DAT_011ad7b4;
extern float DAT_011ad7b8[11];
extern float DAT_011ad7e4;
extern float DAT_011ad7e8;
extern float DAT_011ad7ec;
extern float DAT_011ad7f0;
extern float DAT_011ad7f4;
extern float DAT_011ad7f8;
extern float DAT_011f63a0;
extern int DAT_011f9138;
extern FadeQueueHolder* DAT_011f4748;
extern int DAT_011fa000;
extern char DAT_011f4288[];

float BSMIN(float a, float b);
float BSMAX_00404010(float a, float b);
bool NiObject_IsKindOf(void* list, FadeQueue* q);

struct FadeNodeObj;
void FUN_00b6bb30(FadeNodeObj* node, float fade);

struct FadeNodeObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    const char* m_pcName;  // 0x20
    int unk24;
    int unk28;
    int unk2C;
    unsigned int m_uiValue1;  // 0x30
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
    LocalPt3 m_kWorldTranslate;  // 0x8c
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    float fNearDistSqr;      // 0xac
    float fFarDistSqr;       // 0xb0
    float fLastFade;         // 0xb4
    float fCurrentFade;      // 0xb8
    float m_fFadeDelta;      // 0xbc
    float fTimeSinceUpdate;  // 0xc0
    int eMultType;           // 0xc4
    int iFrameCounter;       // 0xc8

    bool IsCulledFlag() const
    {
        return (m_uiValue1 >> 15) & 1;
    }
    bool IsFadedIn() const
    {
        return (m_uiValue1 >> 14) & 1;
    }
    bool IsAlwaysFade() const
    {
        return (m_uiValue1 >> 28) & 1;
    }
    void NiNode_OnVisible(FadeCuller& culler);
    float BSFadeNode_GetMaxAlpha();
    void BSFadeNode_OnVisible(FadeCuller& culler);
};

// Updates the fade state of a FadeNodeObj based on camera distance and fade thresholds, queueing a batch render when the fade target is in progress.
// @fnv 0x00b4e490
// src: XBOX_PDB 0x00b4e490
void FadeNodeObj::BSFadeNode_OnVisible(FadeCuller& culler)
{
    if (!DAT_011ad7b4 || IsCulledFlag())
    {
        NiNode_OnVisible(culler);
        return;
    }
    float fFadeAmount;
    if (eMultType == 6)
    {
        if (!IsFadedIn())
        {
            fFadeAmount = BSMIN(1.0f, BSMIN(DAT_011f63a0 / DAT_011ad7e4, DAT_011ad7f8) + fCurrentFade);
            fCurrentFade = fFadeAmount;
            FUN_00b6bb30(this, fFadeAmount);
            fLastFade = fCurrentFade;
            if (fCurrentFade >= 1.0f)
                m_uiValue1 |= 0x4000;
        }
        NiNode_OnVisible(culler);
        return;
    }

    float fMult = DAT_011ad7b8[eMultType];
    FadeCamera* pCamera = culler.m_pCamera;
    float fDist;
    LocalPt3 kDiff;
    if (fMult > 0.0f)
    {
        fDist = pCamera->m_fTrailingValue / fMult;
    }
    else
    {
        fDist = 0.2f;
        m_uiValue1 |= 0x4000;
        fLastFade = fCurrentFade = 1.0f;
        FUN_00b6bb30(this, *(volatile float*)&fCurrentFade);
    }

    kDiff = m_kWorldTranslate - pCamera->m_kWorldTranslate;
    fDist = kDiff.Length() * fDist;
    fFadeAmount = 1.0f;
    float fNear = fNearDistSqr * DAT_011ad7f4;
    if (fDist > fNear)
    {
        float fFar = fFarDistSqr * DAT_011ad7f4;
        fFadeAmount = 1.0f - (fDist - fNear) / (fFar - fNear);
    }
    if (eMultType == 10)
    {
        if (IsAlwaysFade())
            fFadeAmount = 1.0f;
        else
            fFadeAmount = 0.0f;
    }

    if (eMultType != 8 && iFrameCounter < DAT_011f9138 - 20 && m_fFadeDelta < 600.0f)
    {
        if (fFadeAmount > DAT_011ad7ec || (IsFadedIn() && fFadeAmount > DAT_011ad7f0))
        {
            FUN_00b6bb30(this, 1.0f);
            fLastFade = fCurrentFade = 1.0f;
            m_uiValue1 |= 0x4000;
        }
        else
        {
            FUN_00b6bb30(this, 0.0f);
            fLastFade = fCurrentFade = 0.0f;
            m_uiValue1 &= ~0x4000;
        }
    }
    iFrameCounter = DAT_011f9138;

    float fTarget = BSFadeNode_GetMaxAlpha();
    bool bFadeQueuedCur = false;
    if (IsFadedIn() && fTarget > 0.0f && fTarget < 1.0f)
    {
        FadeQueue* m_pPrimaryTaskProcessor = DAT_011f4748->m_pQueue;
        if (NiObject_IsKindOf(&DAT_011fa000, m_pPrimaryTaskProcessor))
        {
            m_pPrimaryTaskProcessor->RenderBound(m_pcName ? m_pcName : DAT_011f4288, 1);
            bFadeQueuedCur = true;
            FUN_00b6bb30(this, fTarget);
            fLastFade = fCurrentFade = fTarget;
        }
    }
    else if ((!IsFadedIn() && fFadeAmount > DAT_011ad7ec) ||
             (fCurrentFade > 0.0f && fCurrentFade < 1.0f && fFadeAmount > DAT_011ad7ec))
    {
        fFadeAmount = BSMIN(1.0f, BSMIN(DAT_011f63a0 / DAT_011ad7e4, DAT_011ad7f8) + fCurrentFade);
        fCurrentFade = fFadeAmount;
        FUN_00b6bb30(this, fFadeAmount);
        fLastFade = fCurrentFade;
        if (fCurrentFade >= 1.0f)
            m_uiValue1 |= 0x4000;
    }
    else if ((IsFadedIn() && fFadeAmount < DAT_011ad7f0) ||
             (fCurrentFade < 1.0f && fCurrentFade > 0.0f && fFadeAmount < DAT_011ad7f0))
    {
        fCurrentFade = BSMAX_00404010(0.0f, fCurrentFade - BSMIN(DAT_011f63a0 / DAT_011ad7e8, DAT_011ad7f8));
        FUN_00b6bb30(this, fCurrentFade);
        fLastFade = fCurrentFade;
        if (fCurrentFade <= 0.0f)
            m_uiValue1 &= ~0x4000;
    }

    if (fCurrentFade > 0.0f && fTarget != 0.0f)
        NiNode_OnVisible(culler);
    if (bFadeQueuedCur)
        DAT_011f4748->m_pQueue->DispatchBatchRenderer();
}
}  // namespace fnv_00b4e490

// @fnv 0x00b4df10
extern "C" void __cdecl NiNode_SaveBinary();
// src: XBOX_PDB 0x00b4df10
void __cdecl BSFadeNode_SaveBinary()
{
    NiNode_SaveBinary();
}
