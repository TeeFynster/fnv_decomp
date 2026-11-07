
// src/staging/blk_00c00000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include <stddef.h>
#include "../../include/BSRenderedTexture.h"
#include "../../include/ImageSpaceEffectParam.h"
#include "../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}

inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}

__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}

__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}

inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
#include "../../include/ImageSpaceTexture.h"
#include "../../include/NiTArray.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NiTObjectArray.h"
#include "../../include/NiObject.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiPointer.h"
#include "../../include/MemoryManager.h"
#include "../../include/BSShaderPPLightingProperty.h"
#include "../../include/NiBound.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiD3DShader.h"
#include "../../include/NiD3DShaderConstantMap.h"
#include "../../include/NiNode.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiScreenElements.h"
#include "../../include/NiShaderConstantMapEntry.h"
#include "../../include/StrArr.h"


template <class T, class A> inline unsigned int NiTArray<T, A>::GetSize() const { return m_usSize; }
template <class T, class A> inline T& NiTArray<T, A>::GetAt(unsigned int uiIndex) { return m_pBase[uiIndex]; }
template <class T, class A> inline unsigned int NiTArray<T, A>::SetAtGrow(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0) {}
template <class T> inline NiPointer<T>::NiPointer(T* pkNew) : m_pObject(pkNew)
{
    if (m_pObject != 0) m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::NiPointer(const NiPointer& kSrc) : m_pObject(kSrc.m_pObject)
{
    if (m_pObject != 0) m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0) m_pObject->DecRefCount();
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0) m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0) m_pObject->IncRefCount();
    }
    return *this;
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer& kSrc)
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject != 0) m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject != 0) m_pObject->IncRefCount();
    }
    return *this;
}
template <class T> inline NiPointer<T>::operator T*() const { return m_pObject; }
template <class T> inline T* NiPointer<T>::operator->() const { return m_pObject; }

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}
// The shared texture header exposes the reference-counted base as eight bytes.
inline void BSRenderedTexture::IncRefCount()
{
    volatile long* p = reinterpret_cast<volatile long*>(base + 4);
    InterlockedIncrement(p);
}

template <> inline NiPointer<BSRenderedTexture>::~NiPointer()
{
    if (m_pObject != 0)
        reinterpret_cast<NiRefObject*>(m_pObject)->DecRefCount();
}

inline void NiAVObject::IncRefCount() { NiRefObject::IncRefCount(); }
inline void NiAVObject::DecRefCount() { NiRefObject::DecRefCount(); }
template <class T> inline bool operator==(const NiPointer<T>& left, const NiPointer<T>& right)
{
    return left.m_pObject == right.m_pObject;
}
template <class T> inline bool operator!=(const NiPointer<T>& left, const NiPointer<T>& right)
{
    return left.m_pObject != right.m_pObject;
}

extern MemoryManager g_memoryManager;
void __cdecl FUN_00c03270();
struct FUN_00c033f0_class
{
    void* __thiscall FUN_00c033f0(int);
};
// Calls FUN_00c03270, then deallocates this via g_memoryManager when flag has bit 1 set, and returns this.
// @fnv 0x00c033f0
void* __thiscall FUN_00c033f0_class::FUN_00c033f0(int flag)
{
    FUN_00c03270();
    if (flag & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

extern int(__stdcall* DAT_00fdf1c4)(void*);
extern int(__stdcall* DAT_00fdf1c0)(void*);

struct RefObject
{
    virtual void Unused0();
    virtual void DeleteThis();
    int m_iObjectReferenceCount;

    void DecRefCount(int(__stdcall* pfnDec)(void*))
    {
        if (pfnDec(&m_iObjectReferenceCount) == 0)
            DeleteThis();
    }
    void IncRefCount()
    {
        DAT_00fdf1c0(&m_iObjectReferenceCount);
    }
};

struct Arg_00c04090
{
    char pad00[0x4c];
    RefObject* m_sp4c;
    RefObject* m_sp50;
};

struct Target_00c04090
{
    char pad00[0x30];
    RefObject* m_sp30;
    RefObject* m_sp34;
    char pad38[0xcc - 0x38];
    Arg_00c04090* m_pCC;

    void AssignRefObjects(Arg_00c04090* arg);
};

// Copies two RefObject pointers from arg into m_sp34 and m_sp30 with refcount updates, then stores arg in m_pCC.
// @fnv 0x00c04090
void Target_00c04090::AssignRefObjects(Arg_00c04090* apSource)
{
    int(__stdcall * pfnDec)(void*) = DAT_00fdf1c4;
    if (m_sp34 != apSource->m_sp4c)
    {
        if (m_sp34)
            m_sp34->DecRefCount(pfnDec);
        m_sp34 = apSource->m_sp4c;
        if (m_sp34)
            m_sp34->IncRefCount();
    }
    if (m_sp30 != apSource->m_sp50)
    {
        if (m_sp30)
            m_sp30->DecRefCount(pfnDec);
        m_sp30 = apSource->m_sp50;
        if (m_sp30)
            m_sp30->IncRefCount();
    }
    m_pCC = apSource;
}

namespace fnv_00c04710 {
extern MemoryManager g_memoryManager;

struct FUN_00c04710Class
{
    void __thiscall FUN_00c04620();
    FUN_00c04710Class* __thiscall ReleaseStorage_00c04710(bool flag);
};

// Calls FUN_00c04620, then deallocates this via g_memoryManager when flag's low bit is set, and returns this.
// @fnv 0x00c04710
// src: GUESS 0x00c04710 (confidence: low)
FUN_00c04710Class* __thiscall FUN_00c04710Class::ReleaseStorage_00c04710(bool abFree)
{
    FUN_00c04620();
    if ((unsigned char)abFree & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00c04710

extern "C" void __cdecl BSShaderManager_ReturnVelocityBuffers();



struct FUN_00c04960_class
{
    void ResetArrayElement();
};

// Calls FUN_00b4f510, then sets the int array at offset 0x28 to value 0 at index 2.
// @fnv 0x00c04960
void FUN_00c04960_class::ResetArrayElement()
{
    BSShaderManager_ReturnVelocityBuffers();
    int value = 0;
    ((NiTPrimitiveArray<int>*)((char*)this + 0x28))->SetAt(2, value);
}

namespace fnv_00c04a80 {
extern MemoryManager g_memoryManager;
void __cdecl FUN_00c048b0();
struct FUN_00c04a80_class
{
    void* __thiscall FUN_00c04a80(int);
};
// Calls FUN_00c048b0, deallocates this via g_memoryManager when flag has bit 1 set, and returns this.
// @fnv 0x00c04a80
void* __thiscall FUN_00c04a80_class::FUN_00c04a80(int flag)
{
    FUN_00c048b0();
    if (flag & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00c04a80

struct FUN_00c04d50_class
{
    unsigned char b[0x58];
    void CopyByteAndStoreInt(int a);
};

// Copies the byte at offset 0x58 into offset 5 and stores the int argument at offset 0x5c.
// @fnv 0x00c04d50
void FUN_00c04d50_class::CopyByteAndStoreInt(int aiValue)
{
    *(unsigned char*)((char*)this + 5) = *(unsigned char*)((char*)this + 0x58);
    *(int*)((char*)this + 0x5c) = aiValue;
}

extern "C" unsigned char _DAT_011F941E;

struct FUN_00c04d60_class
{
    unsigned char pad[0x60];
    int m_0x60;
    int __thiscall ImageSpaceEffectCinematic_IsActive();
};

// @fnv 0x00c04d60
// src: COMMUNITY 0x00c04d60
int __thiscall FUN_00c04d60_class::ImageSpaceEffectCinematic_IsActive()
{
    if (m_0x60 && !_DAT_011F941E)
        return 1;
    return 0;
}

struct FUN_00c04d80_cls
{
    void __thiscall SetByteValue(char v);
};

// @fnv 0x00c04d80
void __thiscall FUN_00c04d80_cls::SetByteValue(char acValue)
{
    if (acValue != *(char*)((char*)this + 0x58))
        *(char*)((char*)this + 5) = 1;
    *(char*)((char*)this + 0x58) = acValue;
}

namespace fnv_00c05160 {
extern "C" void __cdecl FUN_00c04da0();
extern MemoryManager g_memoryManager;

struct FUN_00c05160_class
{
    void* __thiscall FUN_00c05160(int);
};

// @fnv 0x00c05160
void* __thiscall FUN_00c05160_class::FUN_00c05160(int aiFlags)
{
    FUN_00c04da0();
    if (aiFlags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00c05160

extern char DAT_011f9422;

struct FUN_00c05350_class
{
    int ImageSpaceEffectBloom_IsActive();
};

// @fnv 0x00c05350
// src: COMMUNITY 0x00c05350
int FUN_00c05350_class::ImageSpaceEffectBloom_IsActive()
{
    if (DAT_011f9422 && *(int*)((char*)this + 0x58))
        return 1;
    return 0;
}

extern void* DAT_010bcb60;
void __cdecl Runtime_UpdateState_00bb45b0();
extern "C" void __cdecl _delete(void*, unsigned int);
struct FUN_00c058c0
{
    void* vtbl;
    __thiscall FUN_00c058c0(bool flag);
};
// Sets the vtable pointer, calls FUN_00bb45b0, and if flag bit 0 is set, deletes this with size 0x108.
// @fnv 0x00c058c0
__thiscall FUN_00c058c0::FUN_00c058c0(bool abDelete)
{
    vtbl = &DAT_010bcb60;
    Runtime_UpdateState_00bb45b0();
    if (abDelete & 1)
        _delete(this, 0x108);
}

extern "C" void __cdecl ShadowLightShader_EnableConstantsForPass(int, int);

// @fnv 0x00c1a2f0
// src: COMMUNITY 0x00c1a2f0
void __stdcall SpeedTreeBranchShader_EnableConstantsForPass(unsigned short ausValue)
{
    ShadowLightShader_EnableConstantsForPass(ausValue, 0);
}

void __fastcall FUN_00a89760(void*);

extern "C" void __cdecl _delete(void*, unsigned int);


// Calls FUN_00a89760, then if b has bit 0 set frees this with _delete, and returns this.
// @fnv 0x00c1a450
void* NiScreenElements::DestroyIfRequested(bool abFree)
{
    ::FUN_00a89760(this);
    if (abFree & 1)
        _delete(this, 0xd8);
    return this;
}

extern int DAT_010bcdc8;
struct FUN_00a74480_holder
{
    void FUN_00a74480(unsigned int);
};
struct FUN_00c1a660_holder : FUN_00a74480_holder
{
    FUN_00c1a660_holder* InitializeFields_00c1a660(unsigned int a);
};
// @fnv 0x00c1a660
// src: GUESS 0x00c1a660 (confidence: low)
FUN_00c1a660_holder* FUN_00c1a660_holder::InitializeFields_00c1a660(unsigned int a)
{
    FUN_00a74480(a);
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_010bcdc8);
    return this;
}

extern int DAT_011f9530;
struct FUN_00c0bb20_class
{
    void Lighting30Shader_SetHairMaps(int a, int b);
};
// @fnv 0x00c0bb20
// src: COMMUNITY 0x00c0bb20
void __thiscall FUN_00c0bb20_class::Lighting30Shader_SetHairMaps(int apTarget, int apSource)
{
    *(int*)(*(int*)(*(int*)(apTarget + 0x24) + 0x10) + 8) = DAT_011f9530;
    *(int*)(*(int*)(*(int*)(apTarget + 0x24) + 0x14) + 8) = *(int*)(*(int*)(apSource + 0xb4));
}


extern NiShaderConstantMapEntry* DAT_011fec44;
extern NiShaderConstantMapEntry* DAT_011fec6c;
void __cdecl UpdateFlagHolders(int);
// @fnv 0x00c02ce0
void SetShaderConstantMapEntryFlags(int a)
{
    UpdateFlagHolders(a);
    unsigned char v = 0;
    if (a == 193 || a == 194)
        reinterpret_cast<unsigned char&>(DAT_011fec6c->unk08) = 1;
    else
        reinterpret_cast<unsigned char&>(DAT_011fec6c->unk08) = v;
    if (DAT_011fec44 != 0 && (unsigned int)a < 728 && (unsigned int)a > 751)
        reinterpret_cast<unsigned char&>(DAT_011fec44->unk08) = v;
}

struct FUN_00c036e0_class
{
    void __thiscall ImageSpaceEffectBloom_SetRadius(int a);
};
// @fnv 0x00c036e0
// src: COMMUNITY 0x00c036e0
void __thiscall FUN_00c036e0_class::ImageSpaceEffectBloom_SetRadius(int a)
{
    *(unsigned char*)((char*)this + 5) = 1;
    *(int*)((char*)this + 0x58) = a;
}

// @fnv 0x00c06dc0
int PackBits(char a, char b, char c, char d, char e, char f, char g, char h)
{
    return ((((((((h * 2 | g) * 2 | f) * 2 | e) * 2 | d) * 2 | c) * 2 | b) * 2 | a));
}

struct FUN_00c06ee0_class
{
    char pad00[0x34];
    RefObject* m_sp34;

    void __thiscall NiPSEmitParticlesCtlr_SetBirthRateInterpolator(RefObject* p);
};

// Sets m_sp34 to p, releasing the previous RefObject and incrementing the new one's reference count when it changes.
// @fnv 0x00c06ee0
// src: GAMEBRYO_LIB 0x00c06ee0
void __thiscall FUN_00c06ee0_class::NiPSEmitParticlesCtlr_SetBirthRateInterpolator(RefObject* apObject)
{
    if (m_sp34 != apObject)
    {
        if (m_sp34)
            m_sp34->DecRefCount(DAT_00fdf1c4);
        m_sp34 = apObject;
        if (m_sp34)
            m_sp34->IncRefCount();
    }
}

struct FUN_00c06f30_class
{
    char pad[0x48];
    RefObject* m_sp48;
    void __thiscall NiD3DPass_SetPixelShader_00c06f30(RefObject* p);
};

// Assigns p to m_sp48, releasing the previous reference and incrementing the new one's ref count when it differs.
// @fnv 0x00c06f30
// src: GAMEBRYO_LIB 0x00c06f30
void __thiscall FUN_00c06f30_class::NiD3DPass_SetPixelShader_00c06f30(RefObject* apRefObject)
{
    if (m_sp48 != apRefObject)
    {
        if (m_sp48)
            m_sp48->DecRefCount(DAT_00fdf1c4);
        m_sp48 = apRefObject;
        if (m_sp48)
            m_sp48->IncRefCount();
    }
}

struct FUN_00c0d1b0_class
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    void ParallaxShader_PresetPasses();
};

// @fnv 0x00c0d1b0
// src: COMMUNITY 0x00c0d1b0
void FUN_00c0d1b0_class::ParallaxShader_PresetPasses()
{
    v15c();
    v160();
    v164();
    v168();
    v16c();
    v170();
}

struct FUN_00c1a640_class
{
    unsigned short __thiscall TallGrassTriStrips_SetCount(unsigned short a);
};
// @fnv 0x00c1a640
// src: COMMUNITY 0x00c1a640
unsigned short __thiscall FUN_00c1a640_class::TallGrassTriStrips_SetCount(unsigned short a)
{
    return ((unsigned short*)((char*)this + 0xc4))[0] = a;
}

extern float DAT_011ae6cc;
extern float DAT_011ae6c8;
extern float _DAT_012003c4;

struct ImageSpaceShaderParam
{
    void __thiscall SetShaderConstantVector4(int a, float b, float c, float d, float e);
};

struct FUN_00c053c0_class
{
    char pad00[0x1c];
    ImageSpaceShaderParam* m_pParam;
    char pad20[0x58 - 0x20];
    char* m_p58;

    bool __thiscall UpdateShaderParam(int);
};

// Reads a shader param from this+0x1c and sets its values from m_p58 offsets 4/8 or two globals, then stores 4.0 to _DAT_012003c4 and returns true.
// @fnv 0x00c053c0
bool __thiscall FUN_00c053c0_class::UpdateShaderParam(int)
{
    ImageSpaceShaderParam* p = *reinterpret_cast<ImageSpaceShaderParam**>(reinterpret_cast<int**>(this)[7]);
    if (m_p58)
    {
        p->SetShaderConstantVector4(0, 0.0f, *(float*)(m_p58 + 4), *(float*)(m_p58 + 8), 0.0f);
    }
    else
    {
        p->SetShaderConstantVector4(0, 0.0f, DAT_011ae6c8, DAT_011ae6cc, 0.0f);
    }
    _DAT_012003c4 = 4.0f;
    return true;
}


struct FUN_00c03260_class
{
    char pad[0x58];
    ImageSpaceTexture m_tex;
    void AddRenderedTexture_Thunk();
};
// @fnv 0x00c03260
// src: GUESS 0x00c03260 (confidence: medium)
void FUN_00c03260_class::AddRenderedTexture_Thunk()
{
    m_tex.AddRenderedTexture();
}

extern float DAT_012023f4;
extern float DAT_012023f8;
extern int DAT_011ae680;

struct FUN_00c03350_class
{
    char pad00[0x1c];
    FUN_00c053c0_class* m_pParam;
    char pad20[0x58 - 0x20];
    char* m_p58;
    bool __thiscall ImageSpaceEffectSunbeams_UpdateParams(int);
};

// Sets the shader parameter from DAT_012023f4 and DAT_012023f8, assigns DAT_011ae680 = 0x80, and returns false.
// @fnv 0x00c03350
// src: COMMUNITY 0x00c03350
bool FUN_00c03350_class::ImageSpaceEffectSunbeams_UpdateParams(int)
{
    ((ImageSpaceShaderParam*)*((int*)(*(int*)((char*)this + 0x1c) + 4)))
        ->SetShaderConstantVector4(0, DAT_012023f4, DAT_012023f8, 0.0f, 0.0f);
    DAT_011ae680 = 0x80;
    return false;
}



struct FUN_00c03390_class
{
    void __thiscall ImageSpaceEffectSunbeams_BorrowTextures(int);
};

// @fnv 0x00c03390
// src: COMMUNITY 0x00c03390
void FUN_00c03390_class::ImageSpaceEffectSunbeams_BorrowTextures(int)
{
    int texture;
    ImageSpaceTexture* pTexture = reinterpret_cast<ImageSpaceTexture*>(reinterpret_cast<char*>(this) + 0x58);

    pTexture->ImageSpaceTexture_BorrowRenderedTexture(3);

    texture = reinterpret_cast<int>(pTexture);
    reinterpret_cast<NiTPrimitiveArray<int>*>(reinterpret_cast<char*>(this) + 0x28)->SetAt(2, texture);
}

struct BeamStage
{
    char pad00[8];
    void* m_p08;
    char pad0c[0x54];
    int m_iObjectReferenceCount;
};

// Texture stages use the stage pool and the reference count at 0x60;
// they are distinct from the NiD3DPass objects created by CreateD3DPass.
struct StageReturn : BeamStage
{
    void __thiscall ReturnToPool();
    bool __thiscall ApplyRenderStateChanges(bool);
    void DecRefCount()
    {
        if (--m_iObjectReferenceCount == 0)
            ReturnToPool();
    }
};

struct UnkBA38F0
{
    void __thiscall ImageSpaceTexture_SetupTexture(BeamStage*);
};


extern int DAT_0126f74c;

struct StageReturnPtr
{
    StageReturn* m_pObject;

    StageReturnPtr() : m_pObject(0)
    {}

    void operator=(StageReturn* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
            {
                if (--m_pObject->m_iObjectReferenceCount == 0)
                    m_pObject->ReturnToPool();
            }

            m_pObject = pObject;

            if (m_pObject)
                ++m_pObject->m_iObjectReferenceCount;
        }
    }

    ~StageReturnPtr()
    {
        if (m_pObject)
        {
            if (--m_pObject->m_iObjectReferenceCount == 0)
                m_pObject->ReturnToPool();
        }
    }
};

struct FUN_00c04310_class
{
    char pad00[0x98];
    UnkBA38F0** m_ppStages;
    char pad9c[2];
    unsigned short m_usStageCount;

    void __thiscall ReleaseStagePasses(int);
};

// @fnv 0x00c04310
void __thiscall FUN_00c04310_class::ReleaseStagePasses(int)
{
    StageReturnPtr stageReturn;

    for (unsigned int i = 1; i < m_usStageCount; ++i)
    {
        NiD3DPass* pPass = reinterpret_cast<NiD3DPass*>(DAT_0126f74c);
        stageReturn = static_cast<StageReturn*>(pPass->m_kStages.m_pBase[i - 1].m_pObject);

        if (stageReturn.m_pObject)
        {
            UnkBA38F0* stage = m_ppStages[i];

            if (stage)
                stage->ImageSpaceTexture_SetupTexture(stageReturn.m_pObject);
            else
                stageReturn.m_pObject->m_p08 = 0;

            stageReturn.m_pObject->ApplyRenderStateChanges(false);
        }
    }
}

namespace fnv_00c04490 {
extern unsigned int _data_011c16bc;

struct StageReturn
{
    char pad00[0x8];
    int m_8;
    char pad0c[0x60 - 0xc];
    int m_iObjectReferenceCount;

    void __thiscall ReturnToPool();
};

struct StageReturnPtr
{
    StageReturn* m_p;

    StageReturnPtr() : m_p(0)
    {}

    void Release()
    {
        if (m_p)
        {
            m_p->m_iObjectReferenceCount += -1;
            if (m_p->m_iObjectReferenceCount == 0)
                m_p->ReturnToPool();
        }
    }

    void operator=(StageReturn* p)
    {
        if (m_p != p)
        {
            Release();
            m_p = p;
            if (m_p)
                ++m_p->m_iObjectReferenceCount;
        }
    }

    ~StageReturnPtr()
    {
        Release();
    }
};

struct VirtualTarget
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void __thiscall Call(int, int);
};

struct FUN_00e7f7c0_class
{
    char pad00[0x24];
    StageReturn** m_pStages;

    VirtualTarget* __thiscall NiD3DPass_GetD3DRenderState();
};

extern FUN_00e7f7c0_class* DAT_0126f74c;

struct FUN_00c04490_class
{
    char pad00[0x9e];
    unsigned short m_uiItemCount;

    void __thiscall ResetStages(int);
};

// @fnv 0x00c04490
void __thiscall FUN_00c04490_class::ResetStages(int)
{
    StageReturnPtr current;

    for (unsigned int i = 1; i < m_uiItemCount; ++i)
    {
        current = DAT_0126f74c->m_pStages[i - 1];
        if (current.m_p != 0)
        {
            current.m_p->m_8 = 0;
            DAT_0126f74c->NiD3DPass_GetD3DRenderState()->Call(i - 1, 0);
        }
    }
}
}  // namespace fnv_00c04490

extern int DAT_010bca64;
// Local until include/ImageSpaceEffect.h is available; constructor binds to 0x00ba4080.
class ImageSpaceEffect__EffectInput;
class ImageSpaceEffect
{
public:
    ImageSpaceEffect();
    virtual ~ImageSpaceEffect();
    bool bIsActive;
    bool bParamsChanged;
    unsigned char layoutPadding6[2];
    NiTPrimitiveArray<ImageSpaceEffect*> pEffectList;
    NiTPrimitiveArray<ImageSpaceEffectParam*> pEffectParamList;
    NiTPrimitiveArray<ImageSpaceTexture*> pTextures;
    NiTPrimitiveArray<ImageSpaceEffect__EffectInput*> pEffectInputs;
    NiTPrimitiveArray<int> pEffectOutput;
};
struct FUN_00c04600 : ImageSpaceEffect
{
    int m_58;
    FUN_00c04600();
};
// @fnv 0x00c04600
FUN_00c04600::FUN_00c04600()
{
    *(int*)this = (int)&DAT_010bca64;
    m_58 = 0;
}

struct FUN_00c046e0_holder
{
    ImageSpaceShaderParam* m_pParam;
};

struct FUN_00c046e0_class
{
    unsigned char pad00[0x1c];
    FUN_00c046e0_holder* m_pHolder;
    unsigned char pad20[0x3c];
    float m_f5c;

    bool __thiscall ImageSpaceEffectMenuBG_UpdateParams(int);
};

// @fnv 0x00c046e0
// src: COMMUNITY 0x00c046e0
bool FUN_00c046e0_class::ImageSpaceEffectMenuBG_UpdateParams(int)
{
    m_pHolder->m_pParam->SetShaderConstantVector4(0, m_f5c, 0.0f, 0.0f, 0.0f);
    return true;
}

struct FUN_00c054a0_class
{
    void FUN_00c05250();
    void* FUN_00c054a0(unsigned char a);
};
// Calls FUN_00c05250, then frees this via g_memoryManager.Deallocate when bit 0 of a is set, and returns this.
// @fnv 0x00c054a0
void* FUN_00c054a0_class::FUN_00c054a0(unsigned char a)
{
    FUN_00c05250();
    if (a & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct FUN_00c056a0_class
{
    void __thiscall FUN_00c056a0();
    FUN_00c056a0_class* __thiscall FUN_00c05760(char flag);
};
// Calls FUN_00c056a0, then frees this via g_memoryManager.Deallocate when flag bit 0 is set, and returns this.
// @fnv 0x00c05760
FUN_00c056a0_class* FUN_00c056a0_class::FUN_00c05760(char flag)
{
    FUN_00c056a0();
    if (flag & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

namespace fnv_00c12480 {
extern int DAT_012022c0;

// @fnv 0x00c12480
// src: COMMUNITY 0x00c12480
bool __fastcall SkinShader_LoadStagesAndPasses(int* pObject)
{
    int* pPassEntry = &DAT_012022c0;
    int iRemaining = 0x1a;
    do
    {
        NiD3DPass::CreateD3DPass((NiD3DPass*&)*pPassEntry);
        pPassEntry++;
        iRemaining--;
    } while (iRemaining != 0);
    (*(void(__thiscall**)(int*))(*(int*)pObject + 0x158))(pObject);
    return true;
}
}  // namespace fnv_00c12480

namespace fnv_00c16350 {
extern int DAT_011f91c0;
extern int DAT_01202350;

// @fnv 0x00c16350
// src: COMMUNITY 0x00c16350
bool __fastcall SpeedTreeBranchShader_LoadStagesAndPasses(void* self)
{
    int* p = &DAT_01202350;
    int count = 0x1e;
    do
    {
        NiD3DPass::CreateD3DPass(*(NiD3DPass**)p);
        p++;
        count--;
    } while (count != 0);

    (*(void(__thiscall**)(void*))(*(int*)self + 0x15c))(self);
    if (DAT_011f91c0 >= 2)
        (*(void(__thiscall**)(void*))(*(int*)self + 0x160))(self);
    return true;
}
}  // namespace fnv_00c16350

extern int DAT_010bcc90;
struct FUN_00c1a480_class
{
    int m_vtbl;
    int m_iWordAt04;
    int __thiscall NiTriStrips_NiTriStrips(int);
    int __thiscall SetVirtualTable_00c1a480(int a);
};
// @fnv 0x00c1a480
// src: GUESS 0x00c1a480 (confidence: low)
int FUN_00c1a480_class::SetVirtualTable_00c1a480(int aiArg)
{
    NiTriStrips_NiTriStrips(aiArg);
    m_vtbl = (int)&DAT_010bcc90;
    return (int)this;
}


struct Holder
{
    unsigned char pad00[0xC4];
    unsigned short m_instanceCount;
    unsigned char padC6[2];
    NiBound m_bound;

    void __thiscall AppendString(StrArr* strings);
    void __thiscall AppendBoundInfo(StrArr* strings);
};

char* __cdecl NiGetViewerString_00a7d490(char const* name, unsigned short value);

// Appends the pLocalBound string and the instance count string to the given string array, growing it as needed.
// @fnv 0x00c1a5a0
void Holder::AppendBoundInfo(StrArr* strings)
{
    AppendString(strings);

    char* value = m_bound.FormatToBuffer("pLocalBound");
    unsigned int index = strings->m_usSize;

    if (index >= strings->m_usMaxSize)
        strings->SetSize(strings->m_usGrowBy + index);

    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d490("instance count", m_instanceCount);
    index = strings->m_usSize;

    if (index >= strings->m_usMaxSize)
        strings->SetSize(strings->m_usGrowBy + index);

    strings->SetAt(index, value);
}


struct FUN_00c1a680_class
{
    void __thiscall TallGrassTriShape_UpdateWorldBound();
};
// @fnv 0x00c1a680
// src: COMMUNITY 0x00c1a680
void __thiscall FUN_00c1a680_class::TallGrassTriShape_UpdateWorldBound()
{
    ((NiBound*)(*(void**)((char*)this + 0x20)))
        ->Update((char*)this + 0xc8, (char*)this + 0x68);
}

namespace fnv_00c1a740 {


struct Caller74690
{
    void __thiscall FUN_00a74690(StrArr* value);
};

char* __cdecl NiGetViewerString_00a7d490(char const* text, unsigned short value);


struct FUN_00c1a740_class
{
    unsigned char pad00[0xc4];
    unsigned short m_c4;
    unsigned char padc6[2];
    NiBound m_c8;

    void __thiscall SetLocalBoundAndInstanceCount(StrArr* value);
};

// Calls FUN_00a74690, then appends the "pLocalBound" and "instance count" strings to the StrArr, growing it as needed.
// @fnv 0x00c1a740
void __thiscall FUN_00c1a740_class::SetLocalBoundAndInstanceCount(StrArr* pStrArr)
{
    reinterpret_cast<Caller74690*>(this)->FUN_00a74690(pStrArr);

    char* text = m_c8.FormatToBuffer("pLocalBound");

    unsigned int index = pStrArr->m_usSize;
    if (index >= pStrArr->m_usMaxSize)
        pStrArr->SetSize(pStrArr->m_usGrowBy + index);

    pStrArr->SetAt(index, text);

    text = NiGetViewerString_00a7d490("instance count", m_c4);

    index = pStrArr->m_usSize;
    if (index >= pStrArr->m_usMaxSize)
        pStrArr->SetSize(pStrArr->m_usGrowBy + index);

    pStrArr->SetAt(index, text);
}
}  // namespace fnv_00c1a740

struct FnvObj;

struct FnvHolder
{
    virtual void vt00();
    virtual void vt04();
    virtual void vt08();
    virtual void vt0c();
    virtual void vt10();
    virtual void vt14();
    virtual void vt18();
    virtual void vt1c();
    virtual void vt20();
    virtual void vt24();
    virtual void vt28();
    virtual void vt2c();
    virtual void vt30();
    virtual void vt34();
    virtual void vt38();
    virtual void vt3c();
    virtual void vt40();
    virtual void vt44();
    virtual void vt48();
    virtual void vt4c();
    virtual void vt50();
    virtual void vt54();
    virtual void vt58();
    virtual void vt5c();
    virtual void vt60();
    virtual void vt64();
    virtual void vt68();
    virtual void vt6c();
    virtual void vt70();
    virtual void vt74();
    virtual void vt78();
    virtual void vt7c();
    virtual void vt80();
    virtual void vt84();
    virtual void vt88();
    virtual void vt8c();
    virtual void vt90();
    virtual void vt94();
    virtual void vt98();
    virtual void vt9c();
    virtual void vta0();
    virtual void vta4();
    virtual void vta8();
    virtual void vtac();
    virtual void vtb0();
    virtual void vtb4();
    virtual void vtb8();
    virtual void vtbc();
    virtual void vtc0();
    virtual void vtc4();
    virtual FnvObj* vtc8();
};

struct FnvObj
{
    virtual void vt00();
    virtual void vt04();
    virtual void vt08();
    virtual void vt0c();
    virtual void vt10();
    virtual void vt14();
    virtual void vt18();
    virtual void vt1c();
    virtual void vt20();
    virtual void vt24();
    virtual void vt28();
    virtual void vt2c();
    virtual void vt30();
    virtual void vt34();
    virtual void vt38();
    virtual void vt3c();
    virtual void vt40();
    virtual void vt44();
    virtual void vt48();
    virtual void vt4c();
    virtual void vt50();
    virtual void vt54();
    virtual void vt58();
    virtual void vt5c();
    virtual void vt60();
    virtual void vt64();
    virtual void vt68();
    virtual void vt6c();
    virtual void vt70();
    virtual void vt74();
    virtual void vt78();
    virtual void vt7c();
    virtual void vt80();
    virtual void vt84();
    virtual void vt88();
    virtual void vt8c();
    virtual unsigned int vt90(int);
};

extern FnvHolder* g_pFnvHolder;

struct FUN_00c02d40_cls
{
    int unk00[0x17];
    float m_f5c;
    float ImageSpaceEffectMotionBlur_GetObjectBlurConst();
};

// Divides m_f5c by the float of the value returned by vt90(0) on the object from g_pFnvHolder->vtc8(), returning the result as float.
// @fnv 0x00c02d40
// src: COMMUNITY 0x00c02d40
float FUN_00c02d40_cls::ImageSpaceEffectMotionBlur_GetObjectBlurConst()
{
    FnvObj* pObj = g_pFnvHolder->vtc8();
    double num = m_f5c;
    unsigned int n = pObj->vt90(0);
    return (float)(num / (double)(float)n);
}

extern unsigned int DAT_011a9bd0;
extern unsigned int DAT_011a9bd4;
extern unsigned int DAT_011a9bd8;
extern unsigned int DAT_011a9bdc;
extern float DAT_01018f5c;
extern unsigned int DAT_011fa2d0;
extern unsigned int DAT_011fa2d4;
extern unsigned int DAT_011fa2d8;
extern unsigned int DAT_011fa2dc;
class FUN_00c02d90_tgt
{
  public:
    unsigned char unk00[0x24];
    unsigned char m_24;
    unsigned char unk25[0x38 - 0x25];
    float m_38;
};
class FUN_00c02d90_cls
{
  public:
    unsigned char unk00[0xa8];
    FUN_00c02d90_tgt* m_a8;
};
class FUN_00c02d90_loc
{
  public:
    float m_00;
    float m_04;
    float m_08;
    unsigned int m_0c;
};
// @fnv 0x00c02d90
// src: COMMUNITY 0x00c02d90
void __stdcall ShadowLightShader_UpdateTogglesConstant(FUN_00c02d90_cls* a1, int a2, FUN_00c02d90_tgt* a3)
{
    FUN_00c02d90_loc loc;
    *(volatile unsigned int*)&loc.m_00 = DAT_011a9bd0;
    unsigned int uiWord1 = DAT_011a9bd4;
    *(volatile unsigned int*)&loc.m_08 = DAT_011a9bd8;
    unsigned int uiWord3 = DAT_011a9bdc;
    loc.m_00 = (a1->m_a8->m_24 & 0x20) > 0 ? 1.0f : 0.0f;
    if (a2 != 0)
    {
        loc.m_04 = 1.0f;
        uiWord1 = *(volatile unsigned int*)&loc.m_04;
    }
    loc.m_08 = (a3 != 0) ? a3->m_38 : DAT_01018f5c;
    DAT_011fa2d0 = *(unsigned int*)&loc.m_00;
    DAT_011fa2d4 = uiWord1;
    DAT_011fa2d8 = *(unsigned int*)&loc.m_08;
    DAT_011fa2dc = uiWord3;
}

struct FlagHolderB5649
{
    char pad00[8];
    unsigned char m_flag08;
};

extern unsigned int DAT_011febdc;
extern unsigned int DAT_011fec34;
extern unsigned int DAT_011fec8c;
extern unsigned int DAT_011fcc80;
extern unsigned int DAT_011fc0a0;

// For each non-null FlagHolderB5649 in two pointer arrays, sets m_flag08 from the bit of the idx-th word in DAT_011fcc80 or DAT_011fc0a0.
// @fnv 0x00c02f70
void UpdateFlagHolders(unsigned int uiIndex)
{
    unsigned int m = 1;
    FlagHolderB5649** cur = (FlagHolderB5649**)&DAT_011febdc;
    do
    {
        FlagHolderB5649* a = cur[-1];
        unsigned int bit = (m << 1) | (m >> 31);
        if (a != 0)
        {
            a->m_flag08 = (*(unsigned int*)((char*)&DAT_011fcc80 + uiIndex * 4) & bit) != 0;
        }
        m = (m << 1) | (m >> 31);
        FlagHolderB5649* b = cur[0];
        bit = (m << 1) | (m >> 31);
        if (b != 0)
        {
            b->m_flag08 = (*(unsigned int*)((char*)&DAT_011fcc80 + uiIndex * 4) & bit) != 0;
        }
        m = (m << 1) | (m >> 31);
        cur += 2;
    } while ((int)cur < (int)&DAT_011fec34);
    m = 1;
    cur = (FlagHolderB5649**)&DAT_011fec34;
    do
    {
        FlagHolderB5649* a = cur[-1];
        unsigned int bit = (m << 1) | (m >> 31);
        if (a != 0)
        {
            a->m_flag08 = (*(unsigned int*)((char*)&DAT_011fc0a0 + uiIndex * 4) & bit) != 0;
        }
        m = (m << 1) | (m >> 31);
        FlagHolderB5649* b = cur[0];
        bit = (m << 1) | (m >> 31);
        if (b != 0)
        {
            b->m_flag08 = (*(unsigned int*)((char*)&DAT_011fc0a0 + uiIndex * 4) & bit) != 0;
        }
        m = (m << 1) | (m >> 31);
        cur += 2;
    } while ((int)cur < (int)&DAT_011fec8c);
}

extern int DAT_010bc8a4;

struct Base03270
{
    ~Base03270();
};

struct Obj03270
{
    virtual void Release(int flags);
};

struct Holder03270
{
    Obj03270* m_iWordAt00;
    Obj03270* m_iWordAt04;
};

struct Table03270
{
    void SetAt(unsigned int index, Obj03270*& value);
    unsigned int m_u00;
};

struct Ptr03270
{
    Obj03270* m_p;
    Ptr03270()
    {}
    ~Ptr03270()
    {}
};

struct Sub03270
{
    ~Sub03270();
};

struct FUN_00c03270 : Base03270
{
    void* m_vtbl;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    Table03270 m_18;
    Holder03270* m_1c;
    unsigned int unk20[14];
    Sub03270 m_58;

    ~FUN_00c03270();
};

// Restores the vtable, releases the two objects held by m_1c and clears their slots in m_18.
// @fnv 0x00c03270
FUN_00c03270::~FUN_00c03270()
{
    *(void* volatile*)&m_vtbl = (void*)&DAT_010bc8a4;
    Holder03270* h = *(Holder03270* volatile*)&m_1c;
    Ptr03270 tmp;
    if (h->m_iWordAt04 != 0)
    {
        Obj03270* p = *(Obj03270* volatile*)&h->m_iWordAt04;
        if (p != 0)
        {
            p->Release(1);
        }
        tmp.m_p = 0;
        m_18.SetAt(1, tmp.m_p);
    }
    if (m_1c->m_iWordAt00 != 0)
    {
        Obj03270* q = m_1c->m_iWordAt00;
        if (q != 0)
        {
            q->Release(1);
        }
        tmp.m_p = 0;
        m_18.SetAt(0, tmp.m_p);
    }
}

extern unsigned char g_unk012023f0;

// @fnv 0x00c03340
// src: COMMUNITY 0x00c03340
unsigned char __cdecl ImageSpaceEffectSunbeams_IsActive()
{
    return g_unk012023f0;
}

struct FUN_00c033c0
{
    FUN_00c033c0();
};

// @fnv 0x00c033c0
FUN_00c033c0::FUN_00c033c0()
{
    ((ImageSpaceEffect*)this)->ImageSpaceEffect::ImageSpaceEffect();
    *(int*)this = 0x10bc8a4;
    *(volatile unsigned char*)((char*)this + 0x58) = 0;
    *(volatile unsigned char*)((char*)this + 0x59) = 0;
    *(volatile unsigned char*)((char*)this + 0x5a) = 0;
    *(volatile int*)((char*)this + 0x5c) = 0;
    *(volatile int*)((char*)this + 0x60) = 0;
    *(volatile int*)((char*)this + 0x64) = 0;
}

struct DestroyableReference
{
    virtual ~DestroyableReference();
};

struct Handle
{
    void FUN_00ba3a00();
};

struct HandlePool
{
    void MemoryManager_Deallocate(Handle* handle);
};
extern HandlePool DAT_011f6238;

struct RefMapEntries
{
    int m_zero;
    DestroyableReference* m_pHeadNode;
    int m_eight;
    DestroyableReference* m_third;
};

struct HandleMapEntries
{
    int m_zero;
    int m_four;
    Handle* m_iSecondInteger;
    Handle* m_third;
};

struct ElementMap
{
    int m_unknown;
    void* m_entries;
    int m_uiItemCount;
    int m_pRayCursor;
    void FUN_00ba3aa0(unsigned int index, int* newValue);
};

struct Entry
{
    int m_zero;
    int m_four;
    int m_eight;
    int m_twelve;
    ~Entry();
};

struct Parent
{
    virtual ~Parent();
};

struct FUN_00c03580 : Parent
{
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    ElementMap m_refs;
    ElementMap m_handles;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    Entry m_entries[2];

    ~FUN_00c03580();
};

// Releases the handles and destroyable references stored in m_handles and m_refs, then clears those map entries.
// @fnv 0x00c03580
FUN_00c03580::~FUN_00c03580()
{
    if (static_cast<HandleMapEntries*>(m_handles.m_entries)->m_iSecondInteger)
    {
        Handle* handle = static_cast<HandleMapEntries*>(m_handles.m_entries)->m_iSecondInteger;
        if (handle)
        {
            handle->FUN_00ba3a00();
            DAT_011f6238.MemoryManager_Deallocate(handle);
        }
        int cleared = 0;
        m_handles.FUN_00ba3aa0(2, &cleared);
    }

    if (static_cast<HandleMapEntries*>(m_handles.m_entries)->m_third)
    {
        Handle* handle = static_cast<HandleMapEntries*>(m_handles.m_entries)->m_third;
        if (handle)
        {
            handle->FUN_00ba3a00();
            DAT_011f6238.MemoryManager_Deallocate(handle);
        }
        int cleared = 0;
        m_handles.FUN_00ba3aa0(3, &cleared);
    }

    if (static_cast<RefMapEntries*>(m_refs.m_entries)->m_pHeadNode)
    {
        DestroyableReference* ref = static_cast<RefMapEntries*>(m_refs.m_entries)->m_pHeadNode;
        if (ref)
        {
            delete ref;
        }
        int cleared = 0;
        m_refs.FUN_00ba3aa0(1, &cleared);
    }

    if (static_cast<RefMapEntries*>(m_refs.m_entries)->m_third)
    {
        DestroyableReference* ref = static_cast<RefMapEntries*>(m_refs.m_entries)->m_third;
        if (ref)
        {
            delete ref;
        }
        int cleared = 0;
        m_refs.FUN_00ba3aa0(3, &cleared);
    }
}

extern float DAT_01202400;
extern float DAT_0120240c;

// Returns true if either global float DAT_01202400 or DAT_0120240c is greater than zero.
// @fnv 0x00c036b0
// src: COMMUNITY 0x00c036b0
int __cdecl ImageSpaceEffectGetHit_IsActive()
{
    return DAT_01202400 > 0.0f || DAT_0120240c > 0.0f;
}

class FUN_00c036f0_sub28;
class FUN_00c036f0_sub5c;

class FUN_00c036f0_sub28
{
  public:
    void FUN_00ba3aa0(int aiMode, FUN_00c036f0_sub5c** appRef);
};

class FUN_00c036f0_sub5c
{
  public:
    void ImageSpaceTexture_BorrowRenderedTexture(int aiValue);
};

class FUN_00c036f0_cls
{
  public:
    void InitSubObjects(int aUnused);
};

// Sets value 0x1b on the sub-objects at offsets 0x5c and 0x6c, then calls the sub-object at 0x28 with modes 2 and 3 passing each pointer.
// @fnv 0x00c036f0
void FUN_00c036f0_cls::InitSubObjects(int aUnused)
{
    FUN_00c036f0_sub5c* pSub = (FUN_00c036f0_sub5c*)((char*)this + 0x5c);
    pSub->ImageSpaceTexture_BorrowRenderedTexture(0x1b);
    ((FUN_00c036f0_sub28*)((char*)this + 0x28))->FUN_00ba3aa0(2, &pSub);
    pSub = (FUN_00c036f0_sub5c*)((char*)this + 0x6c);
    pSub->ImageSpaceTexture_BorrowRenderedTexture(0x1b);
    ((FUN_00c036f0_sub28*)((char*)this + 0x28))->FUN_00ba3aa0(3, &pSub);
}


class SpawnedPrimary_c03a20
{
  public:
    virtual void Vslot00();
    int unk04, unk08, unk0C, unk10, unk14, unk18;
    int unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48;
    int unk4C, unk50, unk54, unk58, unk5C, unk60;
    int unk64, unk68;
    virtual ~SpawnedPrimary_c03a20();
};

class SpawnedSecondary_c03a20
{
  public:
    virtual void Vslot00();
    int unk04, unk08, unk0C, unk10, unk14, unk18;
    int unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48;
    int unk4C, unk50, unk54;
    virtual ~SpawnedSecondary_c03a20();
};

class FUN_00c03a20_cls : public SpawnedPrimary_c03a20, public SpawnedSecondary_c03a20
{
  public:
    NiPointer<NiRefObject> m_c4;
    NiPointer<NiRefObject> m_c8;
    virtual ~FUN_00c03a20_cls();
};

// @fnv 0x00c03a20
FUN_00c03a20_cls::~FUN_00c03a20_cls()
{}

struct ShaderObj
{
    virtual void Unused0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;

    void IncRefCount()
    {
        InterlockedIncrement(&m_iObjectReferenceCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_iObjectReferenceCount) == 0)
            DeleteThis();
    }
};

struct ShaderDesc
{
    const char* m_pFile;
    int m_04;
};

void BuildShaderPath(const char* file, char* out);
int sprintf_s(char* buf, unsigned int size, const char* fmt, ...);

struct ShaderOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
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
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    NiPointer<ShaderObj> m_spVertexShaderObject;
    NiPointer<ShaderObj> m_spPixelShaderObject;

    ShaderObj* CreateVertexShader(char* path, int* desc, void* p, char* name);
    ShaderObj* CreatePixelShader(char* path, int* desc, void* p, char* name);
    void ImageSpaceShader_LoadShaders(ShaderDesc* vsDesc, ShaderDesc* psDesc, const char* name, void* vsArg, void* psArg);
};

// Builds vertex and pixel shader paths and names, creates the vertex shader, and creates the pixel shader only when psArg is non-null.
// @fnv 0x00c03ae0
// src: XBOX_PDB 0x00c03ae0
void ShaderOwner::ImageSpaceShader_LoadShaders(ShaderDesc* pVertexDesc, ShaderDesc* pPixelDesc, const char* name, void* pVertexArg,
                               void* pPixelArg)
{
    char path[0x104];
    char shaderName[0x104];

    BuildShaderPath(pVertexDesc->m_pFile, path);
    sprintf_s(shaderName, 0x104, "IS%s.vso", name);
    m_spVertexShaderObject = CreateVertexShader(path, &pVertexDesc->m_04, pVertexArg, shaderName);

    if (pPixelArg)
    {
        BuildShaderPath(pPixelDesc->m_pFile, path);
        sprintf_s(shaderName, 0x104, "IS%s.pso", name);
        m_spPixelShaderObject = CreatePixelShader(path, &pPixelDesc->m_04, pPixelArg, shaderName);
    }
    else
    {
        m_spPixelShaderObject = 0;
    }
}

// FUN_00c03d70 : copies a member into a global and returns.
//   mov eax,[ecx+0x5c] / mov [0x126f74c],eax / ret 4
extern int g_00c03d70;

struct Cls_00c03d70
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
    void __thiscall ImageSpaceShader_InitPass(int a);
};

// @fnv 0x00c03d70
// src: COMMUNITY 0x00c03d70
void __thiscall Cls_00c03d70::ImageSpaceShader_InitPass(int a)
{
    g_00c03d70 = unk5C;
}

struct FUN_00c04030_renderer
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c(int a, int b, int c, int d, int e);
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
};

struct FUN_00c04030_class
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbc();
    virtual void vfc0(FUN_00c04030_renderer* renderer);

    void __thiscall SetupRenderer();
};

extern FUN_00c04030_renderer* DAT_011f9508;

FUN_00c04030_renderer* __cdecl NiDX9ShaderDeclaration_Create(FUN_00c04030_renderer* renderer, int a, int b);

// Obtains a renderer via FUN_00e76700, configures it with two vf8c calls, calls vfb4, then passes it to vfc0.
// @fnv 0x00c04030
void __thiscall FUN_00c04030_class::SetupRenderer()
{
    FUN_00c04030_renderer* renderer = NiDX9ShaderDeclaration_Create(DAT_011f9508, 2, 1);

    renderer->vf8c(0, 0, 0, 2, 0);
    renderer->vf8c(1, 7, 5, 1, 0);
    renderer->vfb4();
    this->vfc0(renderer);
}

// FUN_00c043f0: thiscall, one stack arg, two guarded virtual calls on this->m_30 / this->m_34.

struct B4630X;
struct B4630Y;
struct B4630Holder
{
    B4630X* m_00;
};
struct B4630G;

struct B4630X
{
    void* unk00_vptr;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    const char* m_20;
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
    int m_68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    struct B4630Y* m_b8;
};
struct B4630Y
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int m_34;
};
struct B4630G
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    void* m_44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    void* m_5c;
};

extern int DAT_011f91e0;
extern char DAT_011f4288;

struct B4630Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78(void* a0, void* a1, int a2, int a3, int a4, int a5, int a6, void* a7, const char* a8, int a9,
                     int a10);
};

class FUN_00c043f0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    struct B4630Obj* m_30;
    struct B4630Obj* m_34;
    void __thiscall ImageSpaceShader_SetupGeometryConstants(int a1);
};

// @fnv 0x00c043f0
// src: COMMUNITY 0x00c043f0
void __thiscall FUN_00c043f0_cls::ImageSpaceShader_SetupGeometryConstants(int a1)
{
    B4630X* x = (*reinterpret_cast<B4630Holder**>(&DAT_011f91e0))->m_00;
    int* pos = &x->m_68;
    const char* name = x->m_20 != 0 ? x->m_20 : reinterpret_cast<const char*>(&DAT_011f4288);
    int edi = x->m_b8->m_34;
    B4630Obj* obj = this->m_30;
    if (obj != 0)
    {
        void* g44 = (*reinterpret_cast<B4630G**>(&DAT_0126f74c))->m_44;
        if (g44 != 0)
        {
            obj->v78(g44, x, 0, 0, edi, a1, 0, pos, name, 0, 1);
        }
    }
    obj = this->m_34;
    if (obj != 0)
    {
        void* g5c = (*reinterpret_cast<B4630G**>(&DAT_0126f74c))->m_5c;
        if (g5c != 0)
        {
            obj->v78(g5c, x, 0, 0, edi, a1, 0, pos, name, 0, 1);
        }
    }
}






class C04620Object
{
  public:
    virtual ~C04620Object();
};



class C04620Base
{
  public:
    virtual ~C04620Base();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    NiTPrimitiveArray<C04620Object*> m_kThirdFollowingStreamField;
    NiTPrimitiveArray<C04620Object*> m_kTextureSwapList;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
};

class FUN_00c04620 : public C04620Base
{
  public:
    virtual ~FUN_00c04620();

    ImageSpaceTexture* m_pkTexture;
};

// @fnv 0x00c04620
FUN_00c04620::~FUN_00c04620()
{
    if (m_pkTexture)
    {
        delete m_pkTexture;
        m_kTextureSwapList.SetAt(2, 0);
    }
    if (m_kThirdFollowingStreamField.GetAt(0))
    {
        delete m_kThirdFollowingStreamField.GetAt(0);
        m_kThirdFollowingStreamField.SetAt(0, 0);
    }
}

class FUN_00c048b0_base
{
  public:
    virtual void unk00();
    ~FUN_00c048b0_base();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct SpawnedSub18
{
    void unk00(int flag, unsigned int* pOut);
};

struct SpawnedSub68
{
    ~SpawnedSub68();
};

struct SpawnedInner
{
    virtual void Release(int flag);
};

class FUN_00c048b0 : public FUN_00c048b0_base
{
  public:
    virtual ~FUN_00c048b0();
    SpawnedSub18 m_18;
    SpawnedInner** m_1c;
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
    SpawnedSub68 m_68;
};

// @fnv 0x00c048b0
FUN_00c048b0::~FUN_00c048b0()
{
    if (*m_1c != 0)
    {
        SpawnedInner* pInner = *m_1c;
        if (pInner != 0)
        {
            pInner->Release(1);
        }
        unsigned int uiOut = 0;
        m_18.unk00(0, &uiOut);
    }
}

extern "C" int fnv_particle_shader_renderer_level;
extern bool g_bC04990Enabled;

class C04990Geometry
{
  public:
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
    float m_fAlpha;

    bool IsAlphaVisible();
};

// Returns true when the particle shader renderer level exceeds 4, the feature is enabled, and m_fAlpha is above zero; otherwise false.
// @fnv 0x00c04990
bool C04990Geometry::IsAlphaVisible()
{
    if (fnv_particle_shader_renderer_level > 4 && g_bC04990Enabled)
        return m_fAlpha > 0.0f;
    return false;
}

extern float DAT_01016248;
extern void* DAT_010bcaac;

struct FUN_00ba4080_class
{
    void FUN_00ba4080();
    FUN_00ba4080_class()
    {
        FUN_00ba4080();
    }
    ~FUN_00ba4080_class();
};
struct FUN_00a90180_class
{
    unsigned int unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54;
    void FUN_00a90180(unsigned int);
};
struct FourFloats
{
    float x, y, z, w;
    FourFloats() : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
    {}
    FourFloats(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
    {}
};
struct TailC049C0
{
    unsigned int flags;
    TailC049C0() : flags(0)
    {}
    ~TailC049C0();
};
struct FUN_00c049c0 : FUN_00ba4080_class
{
    void* vtable;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    FUN_00a90180_class region;
    FourFloats color;
    unsigned char m68, m69, m6a, m6b;
    unsigned int m6c, m70;
    TailC049C0 m74;
    FUN_00c049c0();
};
// @fnv 0x00c049c0
FUN_00c049c0::FUN_00c049c0() : vtable(&DAT_010bcaac), color(), m68(0), m69(0), m6a(0), m6c(0), m70(0), m74()
{
    region.FUN_00a90180(3);
    color = FourFloats(0.0f, DAT_01016248, 0.0f, 0.0f);
}

extern "C" void __cdecl FUN_00ba4080();

extern unsigned char DAT_010bcae8;
extern char str_011ae684;
extern unsigned char DAT_011ae694;

struct FUN_00c04d20_class
{
    void* m_vtbl;
    unsigned char pad04[0x54];
    unsigned char m_58;
    char* m_5c;
    unsigned char* m_60;
    unsigned int m_64;

    FUN_00c04d20_class();
};

// Calls FUN_00ba4080, then sets m_58 and m_64 to 0 and assigns the vtable, m_5c and m_60 pointers.
// @fnv 0x00c04d20
FUN_00c04d20_class::FUN_00c04d20_class()
{
    FUN_00ba4080();
    m_58 = 0;
    m_64 = 0;
    m_vtbl = &DAT_010bcae8;
    m_5c = &str_011ae684;
    m_60 = &DAT_011ae694;
}

struct FUN_00c050b0_cls
{
    char unk00[0x5];
    unsigned char m_05;
    char unk06[0x60 - 0x06];
    int m_60;
    int m_64;
    float m_68;
    float m_6c;
    float m_70;
    float m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;

    void Init(int a, unsigned int b);
};

// Sets m_05 to 1, clears the m_68..m_84 fields, stores a and b, and sets m_68..m_74 to 1.0 or 0.0 from bits 0-3 of b.
// @fnv 0x00c050b0
void FUN_00c050b0_cls::Init(int a, unsigned int auiFlags)
{
    float zero = 0.0f;
    float one = 1.0f;
    m_05 = 1;
    *(volatile int*)&m_68 = 0;
    *(volatile int*)&m_6c = 0;
    *(volatile int*)&m_70 = 0;
    *(volatile int*)&m_74 = 0;
    *(volatile int*)&m_78 = 0;
    *(volatile int*)&m_7c = 0;
    *(volatile int*)&m_80 = 0;
    *(volatile int*)&m_84 = 0;
    m_60 = a;
    m_64 = auiFlags;
    m_68 = (auiFlags & 1) > 0 ? one : zero;
    m_6c = (auiFlags & 2) > 0 ? one : zero;
    m_70 = (auiFlags & 4) > 0 ? one : zero;
    m_74 = (auiFlags & 8) > 0 ? one : zero;
}

struct S_00c05250_Obj
{
    virtual ~S_00c05250_Obj();
};





struct _Base_00ba3d30
{
    virtual ~_Base_00ba3d30();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NiTPrimitiveArray<S_00c05250_Obj*> m_18;
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
};

struct FUN_00c05250 : _Base_00ba3d30
{
    ImageSpaceTexture m_5c[2];
    ~FUN_00c05250();
};

// Deletes the first three objects in m_18 and clears their slots via SetAt.
// @fnv 0x00c05250
FUN_00c05250::~FUN_00c05250()
{
    S_00c05250_Obj* p;

    if (m_18.m_pBase[0])
    {
        delete m_18.m_pBase[0];
        p = 0;
        m_18.SetAt(0, p);
    }
    if (m_18.m_pBase[1])
    {
        delete m_18.m_pBase[1];
        p = 0;
        m_18.SetAt(1, p);
    }
    if (m_18.m_pBase[2])
    {
        delete m_18.m_pBase[2];
        p = 0;
        m_18.SetAt(2, p);
    }
}

struct Property
{
    int value00;
    int value04;
    int value08;
    int value0c;
    void ImageSpaceTexture_BorrowRenderedTexture(int count);
};

struct PropertyCollection
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    void FUN_00ba3aa0(int index, Property** entry);
};

struct EffectProperties
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    PropertyCollection collection;
    Property first;
    Property second;
    void InitProperties(int unused);
};

// Initializes the first and second Property entries with count 26 and registers them in the collection at indices 2 and 3.
// @fnv 0x00c05370
void EffectProperties::InitProperties(int)
{
    Property* entry = &first;
    entry->ImageSpaceTexture_BorrowRenderedTexture(26);
    collection.FUN_00ba3aa0(2, &entry);
    entry = &second;
    entry->ImageSpaceTexture_BorrowRenderedTexture(26);
    collection.FUN_00ba3aa0(3, &entry);
}

// Constructor-like method: base call, vtable store, field init, flag bit.

struct FUN_00c05880_cls
{
    void* m_pVTable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int m_1c;
    unsigned int unk20;
    unsigned int m_24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int m_38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int m_58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int m_100;
    void FUN_00bb4520();
    FUN_00c05880_cls* InitializeFields_00c05880();
};

// @fnv 0x00c05880
// src: GUESS 0x00c05880 (confidence: low)
FUN_00c05880_cls* FUN_00c05880_cls::InitializeFields_00c05880()
{
    FUN_00bb4520();
    unsigned int zero = 0;
    unsigned int flag = 0x800000u;
    m_pVTable = (void*)&DAT_010bcb60;
    m_100 = zero;
    m_58 = 0x1d;
    m_1c = 0xc;
    if ((m_24 & flag) == 0)
        *(volatile unsigned int*)&m_38 = zero;
    m_24 |= flag;
    return this;
}

struct ShaderEntry
{
    unsigned int unknown00;
    unsigned int unknown04;
    void* value;
};
struct ShaderEntryTable
{
    unsigned int unknown00, unknown04, unknown08, unknown0c;
    unsigned int unknown10, unknown14, unknown18, unknown1c, unknown20;
    ShaderEntry** entries;
};
struct ShaderInterface
{
    virtual void slot_000();
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void slot_010();
    virtual void slot_014();
    virtual void slot_018();
    virtual void slot_01c();
    virtual void slot_020();
    virtual void slot_024();
    virtual void slot_028();
    virtual void slot_02c();
    virtual void slot_030();
    virtual void slot_034();
    virtual void slot_038();
    virtual void slot_03c();
    virtual void slot_040();
    virtual void slot_044();
    virtual void slot_048();
    virtual void slot_04c();
    virtual void slot_050();
    virtual void slot_054();
    virtual void slot_058();
    virtual void slot_05c();
    virtual void slot_060();
    virtual void slot_064();
    virtual void slot_068();
    virtual void slot_06c();
    virtual void slot_070();
    virtual void slot_074();
    virtual void slot_078();
    virtual void slot_07c();
    virtual void slot_080();
    virtual void slot_084();
    virtual void slot_088();
    virtual void slot_08c();
    virtual void slot_090();
    virtual void slot_094();
    virtual void slot_098();
    virtual void slot_09c();
    virtual void slot_0a0();
    virtual void slot_0a4();
    virtual void slot_0a8();
    virtual void slot_0ac();
    virtual void slot_0b0();
    virtual void slot_0b4();
    virtual void slot_0b8();
    virtual void slot_0bc();
    virtual void slot_0c0();
    virtual void slot_0c4();
    virtual void slot_0c8();
    virtual void slot_0cc();
    virtual void slot_0d0();
    virtual void slot_0d4();
    virtual void slot_0d8();
    virtual void slot_0dc();
    virtual void slot_0e0();
    virtual void slot_0e4();
    virtual void slot_0e8();
    virtual void slot_0ec();
    virtual void slot_0f0();
    virtual void* GetValue(int kind, int flags);
};
struct ShaderUpdater
{
    void Lighting30Shader_SetTextureMode(ShaderEntry*, ShaderInterface*);
    void UpdateShaderEntry(ShaderEntryTable*, ShaderInterface*, int);
};
// Fetches value kind 3 from the interface into the entry at index, then calls FUN_00bb9640 on the entry.
// @fnv 0x00c0bae0
void ShaderUpdater::UpdateShaderEntry(ShaderEntryTable* table, ShaderInterface* interfaceObject, int index)
{
    ShaderEntry* entry = table->entries[index];
    entry->value = interfaceObject->GetValue(3, 0);
    Lighting30Shader_SetTextureMode(entry, interfaceObject);
}

// CopyOwnerValuesToItems candidate
class Cb50Item
{
  public:
    unsigned int unk00;
    unsigned int m_04;
    unsigned int m_08;
};
class Cb50Hold
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    Cb50Item* m_10;
    Cb50Item* m_14;
    Cb50Item* m_18;
};
class Cb50Ctx
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    Cb50Hold* m_24;
};
class Cb50Owner
{
  public:
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void vSlot08();
    virtual void vSlot0c();
    virtual void vSlot10();
    virtual void vSlot14();
    virtual void vSlot18();
    virtual void vSlot1c();
    virtual void vSlot20();
    virtual void vSlot24();
    virtual void vSlot28();
    virtual void vSlot2c();
    virtual void vSlot30();
    virtual void vSlot34();
    virtual void vSlot38();
    virtual void vSlot3c();
    virtual void vSlot40();
    virtual void vSlot44();
    virtual void vSlot48();
    virtual void vSlot4c();
    virtual void vSlot50();
    virtual void vSlot54();
    virtual void vSlot58();
    virtual void vSlot5c();
    virtual void vSlot60();
    virtual void vSlot64();
    virtual void vSlot68();
    virtual void vSlot6c();
    virtual void vSlot70();
    virtual void vSlot74();
    virtual void vSlot78();
    virtual void vSlot7c();
    virtual void vSlot80();
    virtual void vSlot84();
    virtual void vSlot88();
    virtual void vSlot8c();
    virtual void vSlot90();
    virtual void vSlot94();
    virtual void vSlot98();
    virtual void vSlot9c();
    virtual void vSlota0();
    virtual void vSlota4();
    virtual void vSlota8();
    virtual void vSlotac();
    virtual void vSlotb0();
    virtual void vSlotb4();
    virtual void vSlotb8();
    virtual void vSlotbc();
    virtual void vSlotc0();
    virtual void vSlotc4();
    virtual void vSlotc8();
    virtual void vSlotcc();
    virtual void vSlotd0();
    virtual void vSlotd4();
    virtual void vSlotd8();
    virtual void vSlotdc();
    virtual void vSlote0();
    virtual void vSlote4();
    virtual void vSlote8();
    virtual void vSlotec();
    virtual void vSlotf0();
    virtual unsigned int vSlotf4(unsigned int a, unsigned int b);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    Cb50Item* m_ac;
    Cb50Item* m_b0;
};

// Copies m_04 from owner's m_ac and m_b0 items into the first two context items' m_08, and if flag is set stores vSlotf4(2,0) into the third item's m_08.
// @fnv 0x00c0bb50
void __stdcall CopyOwnerValuesToItems(Cb50Ctx* ctx, Cb50Owner* owner, unsigned char flag)
{
    Cb50Item* p = ctx->m_24->m_10;
    p->m_08 = owner->m_ac->m_04;
    Cb50Item* q = ctx->m_24->m_14;
    q->m_08 = owner->m_b0->m_04;
    if (flag != 0)
    {
        Cb50Item* r = ctx->m_24->m_18;
        r->m_08 = owner->vSlotf4(2, 0);
    }
}

struct S_00c0bba0_Dst
{
    int unk00;
    int unk04;
    int unk08;
};
struct S_00c0bba0_A
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    S_00c0bba0_Dst** unk24;
};
struct S_00c0bba0_B
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
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
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int* unkb0;
};
extern int DAT_011f9510;

// Stores the value pointed to by b->unkb0 into dst->unk08, falling back to DAT_011f9510 when that value is zero.
// @fnv 0x00c0bba0
void __stdcall SetDstValueFromB(S_00c0bba0_A* a, S_00c0bba0_B* pValueHolder)
{
    S_00c0bba0_Dst* dst = *a->unk24;
    int v = *pValueHolder->unkb0;
    if (v == 0)
        v = DAT_011f9510;
    dst->unk08 = v;
}

struct FUN_00c0bbd0_Value
{
    char unk00;
    char unk01;
    char unk02;
    char unk03;
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    int unk08;
};

struct FUN_00c0bbd0_Entry
{
    char unk00;
    char unk01;
    char unk02;
    char unk03;
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    FUN_00c0bbd0_Value* unk08;
    FUN_00c0bbd0_Value* unk0c;
};

struct FUN_00c0bbd0_Arg
{
    char unk00;
    char unk01;
    char unk02;
    char unk03;
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    char unk08;
    char unk09;
    char unk0a;
    char unk0b;
    char unk0c;
    char unk0d;
    char unk0e;
    char unk0f;
    char unk10;
    char unk11;
    char unk12;
    char unk13;
    char unk14;
    char unk15;
    char unk16;
    char unk17;
    char unk18;
    char unk19;
    char unk1a;
    char unk1b;
    char unk1c;
    char unk1d;
    char unk1e;
    char unk1f;
    char unk20;
    char unk21;
    char unk22;
    char unk23;
    FUN_00c0bbd0_Entry* unk24;
};

extern int DAT_011f95e4;
extern int DAT_011f95e8;

// Stores DAT_011f95e4 and DAT_011f95e8 into the unk08 fields of the two values referenced by arg->unk24.
// @fnv 0x00c0bbd0
// src: COMMUNITY 0x00c0bbd0
void __stdcall Lighting30Shader_SetProjShadowMaps(FUN_00c0bbd0_Arg* arg)
{
    arg->unk24->unk08->unk08 = DAT_011f95e4;
    arg->unk24->unk0c->unk08 = DAT_011f95e8;
}

struct FNV_Target
{
    int unk00;
    int unk04;
    int m_p08;
};
struct FNV_Mid
{
    int unk00;
    FNV_Target* m_p04;
};
struct FNV_A1
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
    FNV_Mid* m_p24;
};
struct FNV_Node
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDC();
    virtual void vE0();
    virtual void vE4();
    virtual void vE8();
    virtual void vEC();
    virtual void vF0();
    virtual int v3D(int a, int b);
    unsigned char Method15(int a);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_flags20;
};
struct FNV_Mgr
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
    int unkD8;
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
    int m_194;
};
extern unsigned int DAT_011f9544;
extern unsigned int DAT_011f95d4;
extern unsigned char DAT_011f9427;
FNV_Mgr* __cdecl Callee1();

// Calls v3D(4,0) on the node and stores the resulting value into a1->m_p24->m_p04->m_p08, choosing between DAT_011f95d4 and DAT_011f9544 based on flags and a3.
// @fnv 0x00c0bc00
void __stdcall SetNodeResultValue(FNV_A1* a1, FNV_Node* apNode, int aiCode)
{
    int edi = Callee1()->m_194;
    int ret = apNode->v3D(4, 0);
    if (ret == 0)
    {
        int ebx = DAT_011f95d4;
        if (aiCode == 0x1be || aiCode == 0x1c0)
            goto L64;
        if ((unsigned int)(apNode->m_flags20 & 0x20000) > 0u)
        {
            ret = DAT_011f9544;
            goto L6a;
        }
    L4e:
        if (DAT_011f9427 != 0 && apNode->Method15(0x15) != 0)
            goto L68;
    L64:
        if (edi == 0)
            goto L6e;
    L68:
        ret = ebx;
    L6a:
        if (ret != 0)
            goto store;
    L6e:
        ret = ebx;
    }
store:
    a1->m_p24->m_p04->m_p08 = ret;
}

struct C0BC90Texture;

struct C0BC90Geometry
{
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc3A();
    virtual void vfunc3B();
    virtual void vfunc3C();
    virtual C0BC90Texture* GetProperty(int iType, int iIndex);

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
    float m_fAlpha;
};

struct C0BC90TextureStage
{
    int unk00;
    int unk04;
    C0BC90Texture* m_pkTexture;
};

struct C0BC90StageList
{
    int unk00;
    int unk04;
    int unk08;
    C0BC90TextureStage* m_pkStage;
};

struct C0BC90Pass
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
    C0BC90StageList* m_pkStages;
};

extern C0BC90Texture* g_pkC0BC90DefaultTexture;

class C0BC90ShaderBase
{
  public:
    void SetupTextureStage(C0BC90TextureStage* pkStage, C0BC90Geometry* pkGeometry);
};

class C0BC90Shader : public C0BC90ShaderBase
{
  public:
    static float ms_fTextureBlend;
    static float ms_fAlpha;

    void SetupPassTextureStage(C0BC90Pass* pkPass, C0BC90Geometry* pkGeometry);
};

// @fnv 0x00c0bc90
void C0BC90Shader::SetupPassTextureStage(C0BC90Pass* pkPass, C0BC90Geometry* pkGeometry)
{
    C0BC90Texture* pkTexture = pkGeometry->GetProperty(5, 0);
    C0BC90TextureStage* pkStage = pkPass->m_pkStages->m_pkStage;
    ms_fTextureBlend = 1.0f;
    if (!pkTexture)
    {
        ms_fTextureBlend = 0.0f;
        pkTexture = g_pkC0BC90DefaultTexture;
    }
    pkStage->m_pkTexture = pkTexture;
    SetupTextureStage(pkStage, pkGeometry);
    ms_fAlpha = pkGeometry->m_fAlpha;
}

namespace fnv_00c0bcf0 {
struct C0BCF0Texture;

extern C0BCF0Texture* DAT_011f9518;
extern C0BCF0Texture* DAT_011f9510;

struct C0BCF0TextureStage
{
    int unk00;
    int unk04;
    C0BCF0Texture* m_pkTexture;
};

struct C0BCF0Pass
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
    C0BCF0TextureStage** m_ppkStages;
};

struct C0BCF0Property
{
    C0BCF0Texture* m_pkTexture;
};

struct C0BCF0Geometry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int m_uiValue1;
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
    C0BCF0Property* m_pkProperty;
};

class C0BCF0ShaderBase
{
  public:
    void SetupTextureStage(C0BCF0TextureStage* pkStage, C0BCF0Geometry* pkGeometry);
};

class C0BCF0Shader : public C0BCF0ShaderBase
{
  public:
    void ApplyTextureStage(C0BCF0Pass* pkPass, C0BCF0Geometry* pkGeometry, unsigned int uiStage);
};

// Selects the geometry's texture (or a default based on flag 0x80), assigns it to the pass's stage, and calls SetupTextureStage.
// @fnv 0x00c0bcf0
void C0BCF0Shader::ApplyTextureStage(C0BCF0Pass* pkPass, C0BCF0Geometry* pkGeometry, unsigned int uiStage)
{
    C0BCF0TextureStage** ppkStages = pkPass->m_ppkStages;
    C0BCF0Texture* pkTexture = pkGeometry->m_pkProperty->m_pkTexture;
    C0BCF0TextureStage* pkStage = ppkStages[uiStage];
    if (!pkTexture)
        pkTexture = (pkGeometry->m_uiValue1 & 0x80) > 0 ? DAT_011f9518 : DAT_011f9510;
    pkStage->m_pkTexture = pkTexture;
    SetupTextureStage(pkStage, pkGeometry);
}
}  // namespace fnv_00c0bcf0

struct TexStage
{
    int unk00;
    int unk04;
    int m_08;
    int m_0c;
    int unk10[20];
    int m_iObjectReferenceCount;  // 0x60
    void ReturnToPool();
    void DecRef()
    {
        if (--m_iObjectReferenceCount == 0)
            ReturnToPool();
    }
};

struct TexStagePtr
{
    TexStage* m_p;
    TexStagePtr() : m_p(0)
    {}
    ~TexStagePtr()
    {
        if (m_p)
            m_p->DecRef();
    }
};

struct RefTex
{
    virtual void v00();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};

struct RenderStateGroup
{
    static RenderStateGroup* __cdecl GetFree();
    void SetRenderState(int state, int value, bool save);
};

struct ShaderPass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned int m_18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    RenderStateGroup* m_30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    RefTex* m_44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    RefTex* m_5c;
    int unk60;
    int m_iObjectReferenceCount;  // 0x64

    static void __cdecl CreateStage(TexStagePtr* out);
    void SetStage(unsigned int idx, TexStage* stage);
    void Destroy();

    RenderStateGroup* GetRSG()
    {
        if (m_30 == 0)
            m_30 = RenderStateGroup::GetFree();
        return m_30;
    }
};

void __cdecl SetupStage(TexStage* stage, unsigned int idx, int a, int b, int c);

extern int DAT_011f9534;

extern int DAT_011fd084;
extern int DAT_011fd088;
extern int DAT_011fd08c;
extern int DAT_011fd0b8;
extern int DAT_011fd0bc;
extern int DAT_011fd0e4;
extern int DAT_011fd0e8;
extern int DAT_011fd110;
extern int DAT_011fd114;
extern int DAT_011fc4a4;
extern int DAT_011fc4a8;
extern int DAT_011fc4ac;
extern int DAT_011fc4d8;
extern int DAT_011fc4dc;
extern int DAT_011fc504;
extern int DAT_011fc508;
extern int DAT_011fc530;
extern int DAT_011fc534;

struct ShaderPassPtr
{
    ShaderPass* m_p;
    ShaderPassPtr() : m_p(0)
    {}
    ~ShaderPassPtr()
    {
        if (m_p)
        {
            if (--m_p->m_iObjectReferenceCount == 0)
                m_p->Destroy();
        }
    }
    void operator=(const ShaderPassPtr& sp)
    {
        if (m_p != sp.m_p)
        {
            if (m_p)
            {
                if (--m_p->m_iObjectReferenceCount == 0)
                    m_p->Destroy();
            }
            m_p = sp.m_p;
            if (m_p)
                ++m_p->m_iObjectReferenceCount;
        }
    }
    ShaderPass* operator->() const
    {
        return m_p;
    }
};

extern ShaderPassPtr DAT_01202250;
extern ShaderPassPtr DAT_01202254;
extern ShaderPassPtr DAT_01202258;
extern ShaderPassPtr DAT_0120225c;
extern ShaderPassPtr DAT_01202260;
extern ShaderPassPtr DAT_01202264;
extern ShaderPassPtr DAT_01202268;
extern ShaderPassPtr DAT_0120226c;
extern ShaderPassPtr DAT_01202270;

static __forceinline void AssignTex(RefTex*& dst, RefTex* src)
{
    RefTex* old = dst;
    if (old != src)
    {
        if (old)
        {
            if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->DeleteThis();
        }
        dst = src;
        if (src)
            InterlockedIncrement(&src->m_iObjectReferenceCount);
    }
}

struct FUN_00c0e630_cls
{
    int unk00[0x8c / 4];
    RefTex* m_8c;
    RefTex* m_90;
    RefTex* m_94;
    RefTex* m_98;
    int unk9c[(0xdc - 0x9c) / 4];
    RefTex* m_dc;
    RefTex* m_e0;
    RefTex* m_e4;
    RefTex* m_e8;
    RefTex* m_ec;
    RefTex* m_f0;
    RefTex* m_f4;
    RefTex* m_f8;
    RefTex* m_fc;

    void ParallaxShader_PresetADTPasses_2x();
};

static __forceinline void SetupStages(ShaderPassPtr& spRenderPass, TexStagePtr& spStage)
{
    unsigned int n = spRenderPass->m_18;
    if (n < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 0, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
}

static __forceinline void SetupRenderStates(ShaderPassPtr& spRenderPass)
{
    spRenderPass->GetRSG()->SetRenderState(0x1b, 0, true);
    spRenderPass->GetRSG()->SetRenderState(0xf, 0, true);
    spRenderPass->GetRSG()->SetRenderState(7, 1, true);
    spRenderPass->GetRSG()->SetRenderState(0x17, 4, true);
    spRenderPass->GetRSG()->SetRenderState(0xe, 1, true);
}

// Configures the eight global shader passes: sets up their stages, assigns textures from m_8c..m_fc, applies render states and writes size constants.
// @fnv 0x00c0e630
// src: COMMUNITY 0x00c0e630
void FUN_00c0e630_cls::ParallaxShader_PresetADTPasses_2x()
{
    ShaderPassPtr spRenderPass;
    TexStagePtr spStage;

    spRenderPass = DAT_01202250;
    SetupStages(spRenderPass, spStage);
    AssignTex(spRenderPass->m_5c, m_8c);
    AssignTex(spRenderPass->m_44, m_dc);
    DAT_011fd084 = 0x780;
    DAT_011fc4a4 = 0x2c;

    spRenderPass = DAT_01202254;
    SetupStages(spRenderPass, spStage);
    AssignTex(spRenderPass->m_5c, m_8c);
    AssignTex(spRenderPass->m_44, m_e0);
    DAT_011fd088 = 0x780;
    DAT_011fc4a8 = 0x2c;

    spRenderPass = DAT_01202258;
    SetupStages(spRenderPass, spStage);
    AssignTex(spRenderPass->m_5c, m_8c);
    AssignTex(spRenderPass->m_44, m_e4);
    SetupRenderStates(spRenderPass);
    DAT_011fd08c = 0x780;
    DAT_011fc4ac = 0x3c;

    spRenderPass = DAT_0120225c;
    SetupStages(spRenderPass, spStage);
    AssignTex(spRenderPass->m_5c, m_90);
    AssignTex(spRenderPass->m_44, m_e8);
    SetupRenderStates(spRenderPass);
    DAT_011fd0b8 = 0x7f0;
    DAT_011fc4d8 = 0x2c;

    spRenderPass = DAT_01202260;
    SetupStages(spRenderPass, spStage);
    AssignTex(spRenderPass->m_5c, m_90);
    AssignTex(spRenderPass->m_44, m_ec);
    SetupRenderStates(spRenderPass);
    DAT_011fd0bc = 0x7f0;
    DAT_011fc4dc = 0x3c;

    spRenderPass = DAT_01202264;
    SetupStages(spRenderPass, spStage);
    AssignTex(spRenderPass->m_5c, m_94);
    AssignTex(spRenderPass->m_44, m_f0);
    SetupRenderStates(spRenderPass);
    DAT_011fd0e4 = 0x780;
    DAT_011fc504 = 0x2c;

    spRenderPass = DAT_01202268;
    SetupStages(spRenderPass, spStage);
    AssignTex(spRenderPass->m_5c, m_94);
    AssignTex(spRenderPass->m_44, m_f4);
    SetupRenderStates(spRenderPass);
    DAT_011fd0e8 = 0x780;
    DAT_011fc508 = 0x3c;

    spRenderPass = DAT_0120226c;
    SetupStages(spRenderPass, spStage);
    AssignTex(spRenderPass->m_5c, m_98);
    AssignTex(spRenderPass->m_44, m_f8);
    SetupRenderStates(spRenderPass);
    DAT_011fd110 = 0x7f0;
    DAT_011fc530 = 0x2c;

    spRenderPass = DAT_01202270;
    SetupStages(spRenderPass, spStage);
    AssignTex(spRenderPass->m_5c, m_98);
    AssignTex(spRenderPass->m_44, m_fc);
    SetupRenderStates(spRenderPass);
    DAT_011fd114 = 0x7f0;
    DAT_011fc534 = 0x3c;
}

namespace fnv_00c11790 {

typedef NiPointer<NiRefObject> RefObjectPtr;

void AssignStageFromPool(StageReturn*& rpStage);

struct StageRef : StageReturn
{
    void DecRefCount()
    {
        if (--m_iObjectReferenceCount == 0)
            ReturnToPool();
    }
};

struct StagePtr
{
    StageReturn* m_pObject;

    StagePtr() : m_pObject(0)
    {}
    ~StagePtr()
    {
        if (m_pObject)
            ((StageRef*)m_pObject)->DecRefCount();
    }
};

void __cdecl SetupStage(StageReturn* pStage, int iIndex, int a, int b, int c);

struct RenderStateBlock
{
    void SetState(int iState, int iValue, int iFlag);
};
RenderStateBlock* __cdecl CreateRenderStateBlock();

struct BeamPass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_iStageIndex;
    unsigned int m_uiNumberOfStages;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    RenderStateBlock* m_pRenderState;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    RefObjectPtr m_spPixelShaderObject;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    RefObjectPtr m_spVertexShaderObject;
    int unk60;
    int m_iObjectReferenceCount;

    void SetStage(int iIndex, StageReturn* pStage);
    void SetVertexShader(NiRefObject* pShader)
    {
        m_spVertexShaderObject = pShader;
    }
    void SetPixelShader(NiRefObject* pShader)
    {
        m_spPixelShaderObject = pShader;
    }
    void Destroy();

    RenderStateBlock* GetRenderState()
    {
        if (m_pRenderState == 0)
            m_pRenderState = CreateRenderStateBlock();
        return m_pRenderState;
    }
};

struct BeamPassPtr
{
    BeamPass* m_pObject;

    BeamPassPtr() : m_pObject(0)
    {}
    void operator=(BeamPass* pObject)
    {
        if (m_pObject != pObject)
        {
            m_pObject = pObject;
            if (m_pObject)
                ++m_pObject->m_iObjectReferenceCount;
        }
    }
    ~BeamPassPtr()
    {
        if (--m_pObject->m_iObjectReferenceCount == 0)
            m_pObject->Destroy();
    }
};

extern BeamPass* DAT_0120229c;
extern int DAT_011fd1cc;
extern int DAT_011fc5ec;

struct BeamShader
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
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
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    NiRefObject* m_pReferencedObjectSecondary;
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
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    NiRefObject* m_pReferencedObject;

    void ApplyShaderPass();
};

// @fnv 0x00c11790
void BeamShader::ApplyShaderPass()
{
    BeamPassPtr spRenderPass;
    StagePtr spStage;
    spRenderPass = DAT_0120229c;

    if (spRenderPass.m_pObject->m_uiNumberOfStages < 3)
    {
        AssignStageFromPool(spStage.m_pObject);
        SetupStage(spStage.m_pObject, 0, 1, 2, 1);
        spRenderPass.m_pObject->SetStage(spRenderPass.m_pObject->m_iStageIndex, spStage.m_pObject);
        AssignStageFromPool(spStage.m_pObject);
        SetupStage(spStage.m_pObject, 1, 1, 2, 1);
        spRenderPass.m_pObject->SetStage(spRenderPass.m_pObject->m_iStageIndex, spStage.m_pObject);
        AssignStageFromPool(spStage.m_pObject);
        SetupStage(spStage.m_pObject, 2, 1, 2, 1);
        spRenderPass.m_pObject->SetStage(spRenderPass.m_pObject->m_iStageIndex, spStage.m_pObject);
    }

    spRenderPass.m_pObject->SetVertexShader(m_pReferencedObjectSecondary);
    spRenderPass.m_pObject->SetPixelShader(m_pReferencedObject);
    spRenderPass.m_pObject->GetRenderState()->SetState(0x13, 9, 1);
    spRenderPass.m_pObject->GetRenderState()->SetState(0x14, 1, 1);
    DAT_011fd1cc = 0x400;
    DAT_011fc5ec = 0x20;
}
}  // namespace fnv_00c11790

struct RefHandle
{
    RefObject* object;
    explicit RefHandle(RefObject* ptr = 0) : object(ptr)
    {}
    ~RefHandle()
    {
        if (object != 0)
            object->DecRefCount(DAT_00fdf1c4);
    }
    operator RefObject*() const
    {
        return object;
    }
};
extern RefHandle DAT_011fda48[208];
// @fnv 0x00c163a0
// src: GUESS 0x00c163a0 (confidence: low)
RefObject* __cdecl Object_ProcessAndReturnValue_00c163a0(unsigned int index)
{
    return index <= 207 ? DAT_011fda48[index] : static_cast<const RefHandle&>(RefHandle());
}

struct CpuOpaque;
extern CpuOpaque DAT_012024b8;
// @fnv 0x00c1a3a0
// src: COMMUNITY 0x00c1a3a0
CpuOpaque* __cdecl TallGrassTriStrips_GetRTTI()
{
    return &DAT_012024b8;
}

class C1A3B0Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};

struct C1A3B0Point3
{
    float x;
    float y;
    float z;
};

extern "C" C1A3B0Point3 _NiPoint3_ZERO;

class C1A3B0Bound
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        return reinterpret_cast<C1A3B0Heap&>(g_memoryManager).Allocate(uiSize);
    }

    C1A3B0Bound& operator=(const C1A3B0Bound& kBound)
    {
        m_kCenter = kBound.m_kCenter;
        m_fBoundRadius = kBound.m_fBoundRadius;
        return *this;
    }

    const C1A3B0Point3& GetNavMeshData() const
    {
        return m_kCenter;
    }
    float GetRadius() const
    {
        return m_fBoundRadius;
    }
    void SetCenterAndRadius(const C1A3B0Point3& kTargetCenter, float fRadius)
    {
        m_kCenter = kTargetCenter;
        m_fBoundRadius = fRadius;
    }

    C1A3B0Point3 m_kCenter;
    float m_fBoundRadius;
};

class C1A3B0Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void SetObjectBound(C1A3B0Bound* pkBound);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    C1A3B0Bound* m_pkBound;
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
    C1A3B0Bound m_kWorldBound;

    void SetWorldBound(C1A3B0Bound kBound);
};

// Stores kBound as the world bound, lazily allocates m_pkBound if null, then copies kBound's center and radius into m_pkBound.
// @fnv 0x00c1a3b0
void C1A3B0Object::SetWorldBound(C1A3B0Bound kBound)
{
    m_kWorldBound = kBound;
    if (!m_pkBound)
    {
        SetObjectBound(new C1A3B0Bound);
        m_pkBound->SetCenterAndRadius(_NiPoint3_ZERO, 0.0f);
    }
    m_pkBound->SetCenterAndRadius(kBound.GetNavMeshData(), kBound.GetRadius());
}

struct FUN_00c1a500_out
{
    unsigned int m_i00;
    unsigned int m_i04;
    unsigned int m_i08;
    float m_f0c;
};

class FUN_00c1a500_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    FUN_00c1a500_out* m_pOut20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned short m_wC4;
    unsigned short unkC6;
    unsigned int m_iC8;
    unsigned int m_iCC;
    unsigned int m_iD0;
    float m_fD4;
    void FUN_00a71d30(unsigned int a1);
    void UpdateOutput(unsigned int a1);
};

// Copies m_iC8, m_iCC, m_iD0 and m_fD4 into the output struct at m_pOut20, then calls FUN_00a71d30 when m_wC4 is greater than zero.
// @fnv 0x00c1a500
void FUN_00c1a500_cls::UpdateOutput(unsigned int a1)
{
    unsigned int i00 = m_iC8;
    volatile float f = m_fD4;
    FUN_00c1a500_out* out = m_pOut20;
    out->m_i00 = i00;
    out->m_i04 = m_iCC;
    unsigned int i08 = m_iD0;
    out->m_f0c = f;
    out->m_i08 = i08;
    if (m_wC4 > 0)
    {
        FUN_00a71d30(a1);
    }
}

class NiRenderer;

struct C1A550Point3
{
    float x;
    float y;
    float z;
};

class C1A550Bound
{
  public:
    const C1A550Point3& GetNavMeshData() const
    {
        return m_kCenter;
    }
    float GetRadius() const
    {
        return m_fBoundRadius;
    }
    void SetCenterAndRadius(const C1A550Point3& kTargetCenter, float fRadius)
    {
        m_kCenter = kTargetCenter;
        m_fBoundRadius = fRadius;
    }

    C1A550Point3 m_kCenter;
    float m_fBoundRadius;
};

class C1A550Object
{
  public:
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    C1A550Bound* m_pkBound;
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
    unsigned short m_usActive;
    unsigned short unkC6;
    C1A550Bound m_kWorldBound;

    void RenderImmediate(NiRenderer* pkRenderer);
    void RenderIfActive(NiRenderer* pkRenderer);
};

// Copies the world bound center and radius into m_pkBound, then calls RenderImmediate when m_usActive is greater than zero.
// @fnv 0x00c1a550
void C1A550Object::RenderIfActive(NiRenderer* pkRenderer)
{
    m_pkBound->SetCenterAndRadius(m_kWorldBound.GetNavMeshData(), m_kWorldBound.GetRadius());
    if (m_usActive > 0)
        RenderImmediate(pkRenderer);
}

extern int DAT_012024c0;
// @fnv 0x00c1a650
// src: COMMUNITY 0x00c1a650
int* __cdecl TallGrassTriShape_GetRTTI()
{
    return &DAT_012024c0;
}

struct FUN_00c1a6a0_out
{
    int m_00;
    int m_04;
    int m_08;
    float m_0c;
};

struct FUN_00c1a6a0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    FUN_00c1a6a0_out* m_pOutput;
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
    unsigned short m_c4;
    unsigned short unkC6;
    int m_c8;
    int m_cc;
    int m_d0;
    float m_d4;
    void CopyStateToOutput(int a1);
    void unkTail(int a1);
};

// Copies m_c8, m_cc, m_d0 and m_d4 into the output struct's fields and calls unkTail when m_c4 is greater than zero.
// @fnv 0x00c1a6a0
void FUN_00c1a6a0_cls::CopyStateToOutput(int a1)
{
    int c8 = m_c8;
    volatile float f = m_d4;
    FUN_00c1a6a0_out* out = m_pOutput;
    out->m_00 = c8;
    out->m_04 = m_cc;
    int d0 = m_d0;
    out->m_0c = f;
    out->m_08 = d0;
    if (m_c4 > 0)
    {
        unkTail(a1);
    }
}

struct S_00c1a6f0_Dst
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    float f;
};

struct S_00c1a6f0_Self
{
    char p00[0x20];
    S_00c1a6f0_Dst* m_20;
    char p24[0xc4 - 0x24];
    unsigned short m_c4;
    char pc6[0xc8 - 0xc6];
    unsigned int m_c8;
    unsigned int m_cc;
    unsigned int m_d0;
    float m_d4;

    void __thiscall FUN_00a74600(int p);
    void __thiscall CopyStateToDestination(int p);
};

// Copies m_c8, m_cc, m_d0 and m_d4 into the destination struct pointed to by m_20, then calls FUN_00a74600 if m_c4 is nonzero.
// @fnv 0x00c1a6f0
void __thiscall S_00c1a6f0_Self::CopyStateToDestination(int p)
{
    unsigned int a = m_c8;
    volatile float tmp = m_d4;
    S_00c1a6f0_Dst* dst = m_20;
    dst->a = a;
    dst->b = m_cc;
    unsigned int c = m_d0;
    dst->f = tmp;
    dst->c = c;
    if (m_c4 > 0)
    {
        FUN_00a74600(p);
        return;
    }
}

extern long g_liveObjectCount;

struct CountedObjectBase
{
    virtual ~CountedObjectBase();
    int m_iRefCount;

    CountedObjectBase()
    {
        m_iRefCount = 0;
        InterlockedIncrement((volatile long*)&g_liveObjectCount);
    }
};

struct FUN_00c1cf20 : CountedObjectBase
{
    int m_iValue;
    FUN_00c1cf20();
    virtual ~FUN_00c1cf20();
};

// Initializes m_iValue to 0 and runs the CountedObjectBase constructor, which increments g_liveObjectCount.
// @fnv 0x00c1cf20
FUN_00c1cf20::FUN_00c1cf20()
{
    m_iValue = 0;
}

namespace fnv_00c1d980 {
extern int DAT_010bd698;
void __cdecl ReleaseObjectArray(int aiValue);

class FUN_00c1d980_pool
{
  public:
    void MemoryManager_Deallocate(void* apMemory);
};
extern FUN_00c1d980_pool DAT_011f6238;

struct FUN_00c1d980_cls
{
    int m_vptr;
    int m_04;

    FUN_00c1d980_cls* FUN_00c1d980(unsigned char acFlags);
};

// @fnv 0x00c1d980
FUN_00c1d980_cls* FUN_00c1d980_cls::FUN_00c1d980(unsigned char acFlags)
{
    int value = m_04;
    m_vptr = (int)&DAT_010bd698;
    ReleaseObjectArray(value);
    if (acFlags & 1)
    {
        DAT_011f6238.MemoryManager_Deallocate(this);
    }
    return this;
}
}  // namespace fnv_00c1d980

namespace fnv_00c1d9b0 {
extern int DAT_010bd6a0;
void __cdecl ReleaseObjectArray(int aiValue);

class FUN_00c1d9b0_pool
{
  public:
    void MemoryManager_Deallocate(void* apMemory);
};
extern FUN_00c1d9b0_pool DAT_011f6238;

struct FUN_00c1d9b0_cls
{
    int m_vptr;
    int m_04;

    FUN_00c1d9b0_cls* FUN_00c1d9b0(unsigned char acFlags);
};

// @fnv 0x00c1d9b0
FUN_00c1d9b0_cls* FUN_00c1d9b0_cls::FUN_00c1d9b0(unsigned char acFlags)
{
    int value = m_04;
    m_vptr = (int)&DAT_010bd6a0;
    ReleaseObjectArray(value);
    if (acFlags & 1)
    {
        DAT_011f6238.MemoryManager_Deallocate(this);
    }
    return this;
}
}  // namespace fnv_00c1d9b0

struct FUN_00c1f4e0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned char m_b14;

    void __thiscall NiPSysModifier_SetActive(unsigned char value);
};

// @fnv 0x00c1f4e0
// src: XBOX_PDB 0x00c1f4e0
void FUN_00c1f4e0_cls::NiPSysModifier_SetActive(unsigned char value)
{
    m_b14 = value;
}

struct DecompPass266
{
    void* unk00;
    void* unk04;
    void* m_resource;
    void ApplyPairToState(unsigned int value);
    void NiD3DTextureStage_SetFilterMode(unsigned int value);
};
struct ShaderPasses
{
    DecompPass266* m_primary;
    DecompPass266* m_secondary;
    DecompPass266* m_tertiary;
};
struct GlobalShader
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    ShaderPasses* m_passes;
};

extern unsigned int DAT_011f91e4;
struct ObjectHandle
{
    void* m_object;
};

struct Renderer
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual unsigned int getProperty();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    ObjectHandle* m_primary;
    ObjectHandle* m_secondary;
    unsigned short FUN_00b704b0();
};
struct TextureGenerator
{
    void* BSRenderedTexture_GetTexture(unsigned int code);
};
struct ShaderResource
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned char m_bSlotEnabled;
    unsigned char unkED, unkEE, unkEF;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    TextureGenerator* m_generator;
};
struct ResourceHandle
{
    ShaderResource* m_resource;
};
struct RenderOptions
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned char unk08;
    unsigned char m_bSlotEnabled;
    unsigned short unk0a;
    ResourceHandle* m_handle;
};

// @fnv 0x00c02e20
void __stdcall ApplyRendererToShaderPasses(unsigned int opcode, Renderer* renderer)
{
    GlobalShader* g = (GlobalShader*)DAT_0126f74c;
    if ((unsigned int)(opcode - 445) <= 36)
    {
        if (opcode < 452 || opcode > 455)
        {
            if ((unsigned int)(opcode - 456) > 3)
                return;
        }
    }
    if (opcode >= 728 && opcode <= 751)
        return;

    DecompPass266* first = g->m_passes->m_primary;
    first->m_resource = renderer->m_primary->m_object;
    first->ApplyPairToState(renderer->getProperty());

    DecompPass266* second = g->m_passes->m_secondary;
    if (second)
    {
        void* resource = renderer->m_secondary->m_object;
        if (!resource)
            resource = (void*)DAT_011f9510;
        second->m_resource = resource;
        second->ApplyPairToState(renderer->getProperty());
    }

    if ((unsigned int)(DAT_011f91e4 - 452) <= 3 && renderer->FUN_00b704b0() > 0)
    {
        RenderOptions* options = (RenderOptions*)DAT_011f91e0;
        ShaderResource* resource = options->m_handle->m_resource;
        if (resource->m_bSlotEnabled && resource->m_generator && options->m_bSlotEnabled > 0)
        {
            DecompPass266* pTertiaryPass = g->m_passes->m_tertiary;
            pTertiaryPass->m_resource = resource->m_generator->BSRenderedTexture_GetTexture(0);
            pTertiaryPass->NiD3DTextureStage_SetFilterMode(1);
            pTertiaryPass->ApplyPairToState(0);
        }
    }
}

struct C08
{
    float r, g, b;
};
struct V08
{
    float r, g, b, a;
};
extern C08 DAT_011f4998;
extern V08 DAT_011fa0c0;
struct M08c
{
    int unk00, unk04, unk08;
    float unk0c;
};
struct M08b
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    M08c* unk6c;
};
struct M08a
{
    int unk00;
    M08b* unk04;
};
struct M08
{
    int unk00, unk04;
    M08a* unk08;
};
extern M08* DAT_011f91ac;
struct L08
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    C08 color;
    C08* ptr;
    int unk38, unk3c;
    float dimmer;
};
// @fnv 0x00c03010
void __stdcall AccumulateLightColor(L08* light)
{
    C08 color = light->ptr ? *light->ptr : light->color;
    if (color.r == DAT_011f4998.r && color.g == DAT_011f4998.g && color.b == DAT_011f4998.b)
        return;
    float scale;
    if (_DAT_011F941E)
        scale = DAT_011f91ac->unk08->unk04->unk6c->unk0c * light->dimmer;
    else
    {
        if (!(light->dimmer < 1.0f))
            goto accumulated;
        scale = light->dimmer;
    }
    color.r *= scale;
    color.g *= scale;
    color.b *= scale;
accumulated:
    V08 accumColor = DAT_011fa0c0;
    accumColor.r += color.r;
    accumColor.g += color.g;
    accumColor.b += color.b;
    if (!_DAT_011F941E)
    {
        if (!(accumColor.r < 1.0f))
            accumColor.r = 1.0f;
        if (!(accumColor.g < 1.0f))
            accumColor.g = 1.0f;
        if (!(accumColor.b < 1.0f))
            accumColor.b = 1.0f;
    }
    DAT_011fa0c0 = accumColor;
}

class NiRenderTargetGroup;
namespace fnv_00c03d80 {
struct RenderColor
{
    float r, g, b, a;
};
struct RenderSettings
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    unsigned int flags;
    RenderColor clearColor;
};
extern RenderSettings DAT_01202410;
extern RenderColor DAT_011ad840;
extern bool DAT_011f9426;
struct TextureInput
{
    BSRenderedTexture* GetRenderedTexture() const;
};
struct RenderGeometry;
struct RenderPrimary
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void SetGeometry(RenderGeometry*);
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void SetMode(int);
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void SetSettings(RenderSettings*);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
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
    void ProcessEntries();
};
struct RenderSecondary
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    TextureInput** textures;
    void RenderSecondaryGeometry(RenderGeometry*, int, RenderSettings*, bool);
};
struct RenderEffect : RenderPrimary, RenderSecondary
{
};
struct RenderGeometry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
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
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    RenderPrimary* owner;
};
struct RenderDevice
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void SetClearColor(const RenderColor*);
    virtual void slot0b0();
    virtual void GetClearColor(RenderColor*);
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual NiRenderTargetGroup* GetCurrentGroup();
    virtual NiRenderTargetGroup* GetDefaultGroup();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void ApplyColor(const RenderColor*);
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int state;
    int unk204;
    unsigned char apply;
};
extern RenderDevice* DAT_011f4748;
struct RenderManager
{
    BSRenderedTexture* texture;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    RenderColor color;
};
extern RenderManager* DAT_011f91ac;
void __cdecl BSRenderedTexture_Start(unsigned int, int);
void __cdecl BSRenderedTexture_StartOffscreen(unsigned int, NiRenderTargetGroup*);
NiRenderTargetGroup* __cdecl GetCurrentItem();
void __cdecl FUN_00b6b790();
struct FUN_00ba8cd0
{
    int mode, geometry, enabled, unknown;
    ~FUN_00ba8cd0();
};
FUN_00ba8cd0 __cdecl FUN_00ba8ec0(RenderGeometry*, int, int, int, int);
void __cdecl BSBatchRenderer_RenderPassImmediately(void*, unsigned short, int, int, int);

// Sets up the geometry's owner, settings and mode, applies clear color and render target, runs the 0x2f6 pass, and restores the previous clear color.
// @fnv 0x00c03d80
void RenderSecondary::RenderSecondaryGeometry(RenderGeometry* geometry, int unused, RenderSettings* apSettings,
                                              bool restore)
{
    RenderSettings* settings = apSettings ? apSettings : &DAT_01202410;
    NiPointer<BSRenderedTexture> texture(textures[0]->GetRenderedTexture());
    RenderEffect* effect = static_cast<RenderEffect*>(this);
    geometry->owner = effect;
    effect->SetGeometry(geometry);
    effect->SetSettings(settings);
    effect->ProcessEntries();
    unsigned int flags = settings->flags;
    RenderColor oldClearColor = {0, 0, 0, 0};
    if (!texture.m_pObject && DAT_011f9426)
    {
        flags = 1;
        reinterpret_cast<RenderDevice*>(DAT_011f9508)->GetClearColor(&oldClearColor);
        reinterpret_cast<RenderDevice*>(DAT_011f9508)->SetClearColor(reinterpret_cast<RenderColor*>(&DAT_011a9bd0));
    }
    else if (flags & 1)
    {
        reinterpret_cast<RenderDevice*>(DAT_011f9508)->GetClearColor(&oldClearColor);
        reinterpret_cast<RenderDevice*>(DAT_011f9508)->SetClearColor(&settings->clearColor);
    }
    if (texture.m_pObject)
    {
        if (DAT_011f4748->state == 0)
            BSRenderedTexture_StartOffscreen(flags, texture->GetGroup());
    }
    else
    {
        if (DAT_011f4748->state == 0)
            BSRenderedTexture_Start(flags, 0);
    }
    RenderColor* color = texture.m_pObject == DAT_011f91ac->texture ? &DAT_011f91ac->color : 0;
    if (!texture.m_pObject && DAT_011f9426)
    {
        RenderDevice* device = DAT_011f4748;
        if (DAT_011f4748->GetCurrentGroup() == device->GetDefaultGroup())
            color = &DAT_011ad840;
    }
    if ((DAT_011f4748->state == 1 || DAT_011f4748->state == 2) && DAT_011f4748->apply == 1)
        DAT_011f4748->ApplyColor(color);
    effect->SetMode(0x2f6);
    FUN_00ba8cd0 pass = FUN_00ba8ec0(geometry, 0x2f6, 1, 0, 0);
    BSBatchRenderer_RenderPassImmediately(&pass, 0x2f6, 0, 0, 0);
    if (texture.m_pObject && restore)
    {
        NiRenderTargetGroup* group = DAT_011f4748->GetCurrentGroup();
        if (GetCurrentItem() != group)
            FUN_00b6b790();
    }
    if (settings->flags & 1)
        reinterpret_cast<RenderDevice*>(DAT_011f9508)->SetClearColor(&oldClearColor);
}
}  // namespace fnv_00c03d80





class FUN_00c05420 : public ImageSpaceEffect
{
  public:
    FUN_00c05420();
    virtual ~FUN_00c05420();

    int m_iMode;
    ImageSpaceTexture m_akTextures[2];
};

// Initializes m_iMode to 0 and sets the primitive array size to 4.
// @fnv 0x00c05420
FUN_00c05420::FUN_00c05420() : m_iMode(0)
{
    pTextures.SetSize(4);
}

struct FUN_00c05730_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    FUN_00c046e0_holder* m_pHolder;
    int unk20;
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
    float m_fRed;
    float m_fGreen;
    float m_fBlue;

    bool SetColor(int);
};

// @fnv 0x00c05730
bool FUN_00c05730_class::SetColor(int)
{
    m_pHolder->m_pParam->SetShaderConstantVector4(0, m_fRed, m_fGreen, m_fBlue, 1.0f);
    return false;
}

struct RefTex111
{
    virtual void Unused0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
struct ElemObj
{
    void __thiscall SetNodeValue(int a, int b, int c);
};
ElemObj* __cdecl FUN_00e7f5d0();
void __cdecl AssignStageFromPool(StageReturn*& p);
struct RefPtr
{
    RefTex111* m_pObject;
};
static __forceinline void AssignRef(RefTex111*& dst, RefTex111* src)
{
    RefTex111* old = dst;
    if (old != src)
    {
        if (old)
        {
            if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->DeleteThis();
        }
        dst = src;
        if (src)
            InterlockedIncrement(&src->m_iObjectReferenceCount);
    }
}
struct StagePtr
{
    StageReturn* m_pObject;
    StagePtr() : m_pObject(0)
    {}
    static __forceinline void Release(StageReturn* p)
    {
        --p->m_iObjectReferenceCount;
        if (p->m_iObjectReferenceCount == 0)
            p->ReturnToPool();
    }
    ~StagePtr()
    {
        if (m_pObject)
            Release(m_pObject);
    }
};
struct ClusterObj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int m_18;
    unsigned int GetCount() const
    {
        return m_18;
    }
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    ElemObj* m_30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    RefPtr m_44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    RefPtr m_5c;
    unsigned int unk60;
    int m_64;
    void __thiscall NiD3DPass_SetStage(int idx, StageReturn* s);
    void __thiscall FUN_00e80190();
};
struct ClusterPtr
{
    ClusterObj* m_pObject;
    ClusterPtr() : m_pObject(0)
    {}
    ClusterObj* operator->()
    {
        return m_pObject;
    }
    void operator=(ClusterObj* const& p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
            {
                if (--m_pObject->m_64 == 0)
                    m_pObject->FUN_00e80190();
            }
            m_pObject = p;
            if (m_pObject)
                ++m_pObject->m_64;
        }
    }
    ~ClusterPtr()
    {
        if (m_pObject)
        {
            if (--m_pObject->m_64 == 0)
                m_pObject->FUN_00e80190();
        }
    }
};
struct StageFields
{
    unsigned int unk00;
    unsigned int unk04;
    int m_08;
    int m_0c;
};
extern ClusterObj* DAT_01202230;
extern ClusterObj* DAT_01202234;
extern ClusterObj* DAT_01202238;
extern ClusterObj* DAT_0120223c;
extern ClusterObj* DAT_01202240;
extern ClusterObj* DAT_01202244;
extern ClusterObj* DAT_01202248;
extern ClusterObj* DAT_0120224c;
extern int DAT_011f9534;
extern int DAT_011fcfe4;
extern int DAT_011fc404;
extern int DAT_011fcfe8;
extern int DAT_011fc408;
extern int DAT_011fd008;
extern int DAT_011fc428;
extern int DAT_011fd00c;
extern int DAT_011fc42c;
extern int DAT_011fd02c;
extern int DAT_011fc44c;
extern int DAT_011fd030;
extern int DAT_011fc450;
extern int DAT_011fd050;
extern int DAT_011fc470;
extern int DAT_011fd054;
extern int DAT_011fc474;
struct FUN_00c0d200_class
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    RefTex111* m_ac;
    RefTex111* m_b0;
    RefTex111* m_b4;
    RefTex111* m_b8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    RefTex111* m_110;
    RefTex111* m_114;
    RefTex111* m_118;
    RefTex111* m_11c;
    RefTex111* m_120;
    RefTex111* m_124;
    RefTex111* m_128;
    RefTex111* m_12c;
    void InitClusterStages();
};
void __cdecl ConfigureBeamStage(FUN_00c0d200_class* self, int a, int b, int c, int d);

// For each of the eight cluster globals, fills up to seven stage slots and assigns textures, then sets the resolution globals.
// @fnv 0x00c0d200
void FUN_00c0d200_class::InitClusterStages()
{
    ClusterPtr cur;
    StagePtr stage;
    cur = DAT_01202230;
    if (cur->GetCount() < 7)
    {
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 0, 1, 2, 1);
        cur->NiD3DPass_SetStage(0, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 1, 1, 2, 1);
        cur->NiD3DPass_SetStage(1, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 2, 1, 2, 1);
        cur->NiD3DPass_SetStage(2, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 3, 1, 2, 1);
        cur->NiD3DPass_SetStage(3, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 4, 3, 0, 1);
        ((StageFields*)stage.m_pObject)->m_08 = DAT_011f9534;
        ((StageFields*)stage.m_pObject)->m_0c = 1;
        cur->NiD3DPass_SetStage(4, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 5, 1, 2, 1);
        cur->NiD3DPass_SetStage(5, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 6, 3, 0, 1);
        cur->NiD3DPass_SetStage(6, stage.m_pObject);
    }
    AssignRef(cur->m_5c.m_pObject, this->m_ac);
    AssignRef(cur->m_44.m_pObject, this->m_110);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(15, 0, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(7, 1, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(23, 4, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(14, 1, 1);
    DAT_011fcfe4 = 1920;
    DAT_011fc404 = 44;
    cur = DAT_01202234;
    if (cur->m_18 < 7)
    {
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 0, 1, 2, 1);
        cur->NiD3DPass_SetStage(0, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 1, 1, 2, 1);
        cur->NiD3DPass_SetStage(1, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 2, 1, 2, 1);
        cur->NiD3DPass_SetStage(2, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 3, 1, 2, 1);
        cur->NiD3DPass_SetStage(3, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 4, 3, 0, 1);
        ((StageFields*)stage.m_pObject)->m_08 = DAT_011f9534;
        ((StageFields*)stage.m_pObject)->m_0c = 1;
        cur->NiD3DPass_SetStage(4, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 5, 1, 2, 1);
        cur->NiD3DPass_SetStage(5, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 6, 3, 0, 1);
        cur->NiD3DPass_SetStage(6, stage.m_pObject);
    }
    AssignRef(cur->m_5c.m_pObject, this->m_ac);
    AssignRef(cur->m_44.m_pObject, this->m_114);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(15, 0, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(7, 1, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(23, 4, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(14, 1, 1);
    DAT_011fcfe8 = 1920;
    DAT_011fc408 = 60;
    cur = DAT_01202238;
    if (cur->m_18 < 7)
    {
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 0, 1, 2, 1);
        cur->NiD3DPass_SetStage(0, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 1, 1, 2, 1);
        cur->NiD3DPass_SetStage(1, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 2, 1, 2, 1);
        cur->NiD3DPass_SetStage(2, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 3, 1, 2, 1);
        cur->NiD3DPass_SetStage(3, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 4, 3, 0, 1);
        ((StageFields*)stage.m_pObject)->m_08 = DAT_011f9534;
        ((StageFields*)stage.m_pObject)->m_0c = 1;
        cur->NiD3DPass_SetStage(4, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 5, 1, 2, 1);
        cur->NiD3DPass_SetStage(5, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 6, 3, 0, 1);
        cur->NiD3DPass_SetStage(6, stage.m_pObject);
    }
    AssignRef(cur->m_5c.m_pObject, this->m_b0);
    AssignRef(cur->m_44.m_pObject, this->m_118);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(15, 0, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(7, 1, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(23, 4, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(14, 1, 1);
    DAT_011fd008 = 2032;
    DAT_011fc428 = 44;
    cur = DAT_0120223c;
    if (cur->m_18 < 7)
    {
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 0, 1, 2, 1);
        cur->NiD3DPass_SetStage(0, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 1, 1, 2, 1);
        cur->NiD3DPass_SetStage(1, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 2, 1, 2, 1);
        cur->NiD3DPass_SetStage(2, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 3, 1, 2, 1);
        cur->NiD3DPass_SetStage(3, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 4, 3, 0, 1);
        ((StageFields*)stage.m_pObject)->m_08 = DAT_011f9534;
        ((StageFields*)stage.m_pObject)->m_0c = 1;
        cur->NiD3DPass_SetStage(4, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 5, 1, 2, 1);
        cur->NiD3DPass_SetStage(5, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 6, 3, 0, 1);
        cur->NiD3DPass_SetStage(6, stage.m_pObject);
    }
    AssignRef(cur->m_5c.m_pObject, this->m_b0);
    AssignRef(cur->m_44.m_pObject, this->m_11c);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(15, 0, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(7, 1, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(23, 4, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(14, 1, 1);
    DAT_011fd00c = 2032;
    DAT_011fc42c = 60;
    cur = DAT_01202240;
    if (cur->m_18 < 7)
    {
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 0, 1, 2, 1);
        cur->NiD3DPass_SetStage(0, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 1, 1, 2, 1);
        cur->NiD3DPass_SetStage(1, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 2, 1, 2, 1);
        cur->NiD3DPass_SetStage(2, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 3, 1, 2, 1);
        cur->NiD3DPass_SetStage(3, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 4, 3, 0, 1);
        ((StageFields*)stage.m_pObject)->m_08 = DAT_011f9534;
        ((StageFields*)stage.m_pObject)->m_0c = 1;
        cur->NiD3DPass_SetStage(4, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 5, 1, 2, 1);
        cur->NiD3DPass_SetStage(5, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 6, 3, 0, 1);
        cur->NiD3DPass_SetStage(6, stage.m_pObject);
    }
    AssignRef(cur->m_5c.m_pObject, this->m_b4);
    AssignRef(cur->m_44.m_pObject, this->m_120);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(27, 0, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(15, 0, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(7, 1, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(23, 4, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(14, 1, 1);
    DAT_011fd02c = 1920;
    DAT_011fc44c = 44;
    cur = DAT_01202244;
    if (cur->m_18 < 7)
    {
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 0, 1, 2, 1);
        cur->NiD3DPass_SetStage(0, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 1, 1, 2, 1);
        cur->NiD3DPass_SetStage(1, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 2, 1, 2, 1);
        cur->NiD3DPass_SetStage(2, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 3, 1, 2, 1);
        cur->NiD3DPass_SetStage(3, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 4, 3, 0, 1);
        ((StageFields*)stage.m_pObject)->m_08 = DAT_011f9534;
        ((StageFields*)stage.m_pObject)->m_0c = 1;
        cur->NiD3DPass_SetStage(4, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 5, 1, 2, 1);
        cur->NiD3DPass_SetStage(5, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 6, 3, 0, 1);
        cur->NiD3DPass_SetStage(6, stage.m_pObject);
    }
    AssignRef(cur->m_5c.m_pObject, this->m_b4);
    AssignRef(cur->m_44.m_pObject, this->m_124);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(27, 0, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(15, 0, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(7, 1, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(23, 4, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(14, 1, 1);
    DAT_011fd030 = 1920;
    DAT_011fc450 = 60;
    cur = DAT_01202248;
    if (cur->m_18 < 7)
    {
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 0, 1, 2, 1);
        cur->NiD3DPass_SetStage(0, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 1, 1, 2, 1);
        cur->NiD3DPass_SetStage(1, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 2, 1, 2, 1);
        cur->NiD3DPass_SetStage(2, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 3, 1, 2, 1);
        cur->NiD3DPass_SetStage(3, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 4, 3, 0, 1);
        ((StageFields*)stage.m_pObject)->m_08 = DAT_011f9534;
        ((StageFields*)stage.m_pObject)->m_0c = 1;
        cur->NiD3DPass_SetStage(4, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 5, 1, 2, 1);
        cur->NiD3DPass_SetStage(5, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 6, 3, 0, 1);
        cur->NiD3DPass_SetStage(6, stage.m_pObject);
    }
    AssignRef(cur->m_5c.m_pObject, this->m_b8);
    AssignRef(cur->m_44.m_pObject, this->m_128);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(27, 0, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(15, 0, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(7, 1, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(23, 4, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(14, 1, 1);
    DAT_011fd050 = 2032;
    DAT_011fc470 = 44;
    cur = DAT_0120224c;
    if (cur->m_18 < 7)
    {
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 0, 1, 2, 1);
        cur->NiD3DPass_SetStage(0, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 1, 1, 2, 1);
        cur->NiD3DPass_SetStage(1, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 2, 1, 2, 1);
        cur->NiD3DPass_SetStage(2, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 3, 1, 2, 1);
        cur->NiD3DPass_SetStage(3, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 4, 3, 0, 1);
        ((StageFields*)stage.m_pObject)->m_08 = DAT_011f9534;
        ((StageFields*)stage.m_pObject)->m_0c = 1;
        cur->NiD3DPass_SetStage(4, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 5, 1, 2, 1);
        cur->NiD3DPass_SetStage(5, stage.m_pObject);
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage((FUN_00c0d200_class*)stage.m_pObject, 6, 3, 0, 1);
        cur->NiD3DPass_SetStage(6, stage.m_pObject);
    }
    AssignRef(cur->m_5c.m_pObject, this->m_b8);
    AssignRef(cur->m_44.m_pObject, this->m_12c);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(27, 0, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(15, 0, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(7, 1, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(23, 4, 1);
    if (!cur->m_30)
        cur->m_30 = FUN_00e7f5d0();
    cur->m_30->SetNodeValue(14, 1, 1);
    DAT_011fd054 = 2032;
    DAT_011fc474 = 60;
}

extern ShaderPassPtr DAT_01202294;
extern ShaderPassPtr DAT_01202298;
extern int DAT_011fd150;
extern int DAT_011fc570;
extern int DAT_011fd180;
extern int DAT_011fc5a0;
struct TargetShader
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    RefTex* m_bc;
    RefTex* m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    int m_e4;
    int m_e8;
    int m_ec;
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    RefTex* m_130;
    RefTex* m_134;
    void ParallaxShader_PresetDiffusePtPasses_2x();
};

static __forceinline void SetupFourStages(ShaderPassPtr& pass, TexStagePtr& stage)
{
    unsigned int count = pass->m_18;
    if (count < 4)
    {
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 0, 1, 2, 1);
        pass->SetStage(0, stage.m_p);
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 1, 1, 2, 1);
        pass->SetStage(1, stage.m_p);
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 2, 1, 2, 1);
        pass->SetStage(2, stage.m_p);
        ShaderPass::CreateStage(&stage);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        SetupStage(stage.m_p, 3, 3, 0, 1);
        pass->SetStage(3, stage.m_p);
    }
}

// @fnv 0x00c113b0
// src: COMMUNITY 0x00c113b0
void TargetShader::ParallaxShader_PresetDiffusePtPasses_2x()
{
    ShaderPassPtr pass;
    TexStagePtr stage;
    pass = DAT_01202294;
    SetupFourStages(pass, stage);
    AssignTex(pass->m_5c, m_bc);
    AssignTex(pass->m_44, m_130);
    pass->GetRSG()->SetRenderState(0x13, 2, true);
    pass->GetRSG()->SetRenderState(0x14, 2, true);
    DAT_011fd150 = 0x480;
    DAT_011fc570 = 8;
    pass = DAT_01202298;
    SetupFourStages(pass, stage);
    AssignTex(pass->m_5c, m_c0);
    AssignTex(pass->m_44, m_134);
    pass->GetRSG()->SetRenderState(0x13, 2, true);
    pass->GetRSG()->SetRenderState(0x14, 2, true);
    DAT_011fd180 = 0x480;
    DAT_011fc5a0 = 8;
}

namespace fnv_00c124c0 {
struct InitRenderState
{
    void SetNodeValue(int, int, bool);
};
InitRenderState* __cdecl FUN_00e7f5d0();
struct RenderStateShaderPass : ShaderPass
{
    void FUN_00e80190();
    void NiD3DPass_SetStage(unsigned int, TexStage*);
    InitRenderState* const& GetRSG()
    {
        if (!m_30)
            m_30 = (RenderStateGroup*)FUN_00e7f5d0();
        return (InitRenderState* const&)m_30;
    }
};
struct InitShaderPassPtr
{
    RenderStateShaderPass* m_p;
    InitShaderPassPtr() : m_p(0)
    {}
    ~InitShaderPassPtr()
    {
        if (m_p && --m_p->m_iObjectReferenceCount == 0)
            m_p->FUN_00e80190();
    }
    void operator=(const InitShaderPassPtr& other)
    {
        if (m_p != other.m_p)
        {
            if (m_p && --m_p->m_iObjectReferenceCount == 0)
                m_p->FUN_00e80190();
            m_p = other.m_p;
            if (m_p)
                ++m_p->m_iObjectReferenceCount;
        }
    }
    RenderStateShaderPass* operator->() const
    {
        return m_p;
    }
};
struct InitStageLifetime : TexStage
{
    void NiD3DTextureStage_ReturnStageToPool();
    void Release()
    {
        if (--m_iObjectReferenceCount == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};
struct InitTexStagePtr
{
    TexStage* m_p;
    InitTexStagePtr() : m_p(0)
    {}
    ~InitTexStagePtr()
    {
        if (m_p)
            ((InitStageLifetime*)m_p)->Release();
    }
};
void __cdecl AssignStageFromPool(InitTexStagePtr*);
void __cdecl ConfigureBeamStage(TexStage*, unsigned int, int, int, int);
struct InitPassView
{
    void NiD3DPass_SetVertexShader(RefTex*);
    void NiD3DPass_SetPixelShader(RefTex*);
    void FUN_00b80040(int, int, bool);
};
struct ShaderInitialization
{
    RefTex* texture000;
    RefTex* texture004;
    RefTex* texture008;
    RefTex* texture00c;
    RefTex* texture010;
    RefTex* texture014;
    RefTex* texture018;
    RefTex* texture01c;
    RefTex* texture020;
    RefTex* texture024;
    RefTex* texture028;
    RefTex* texture02c;
    RefTex* texture030;
    RefTex* texture034;
    RefTex* texture038;
    RefTex* texture03c;
    RefTex* texture040;
    RefTex* texture044;
    RefTex* texture048;
    RefTex* texture04c;
    RefTex* texture050;
    RefTex* texture054;
    RefTex* texture058;
    RefTex* texture05c;
    RefTex* texture060;
    RefTex* texture064;
    RefTex* texture068;
    RefTex* texture06c;
    RefTex* texture070;
    RefTex* texture074;
    RefTex* texture078;
    RefTex* texture07c;
    RefTex* texture080;
    RefTex* texture084;
    RefTex* texture088;
    RefTex* texture08c;
    RefTex* texture090;
    RefTex* texture094;
    RefTex* texture098;
    RefTex* texture09c;
    RefTex* texture0a0;
    RefTex* texture0a4;
    RefTex* texture0a8;
    RefTex* texture0ac;
    RefTex* texture0b0;
    RefTex* texture0b4;
    RefTex* texture0b8;
    RefTex* texture0bc;
    RefTex* texture0c0;
    RefTex* texture0c4;
    RefTex* texture0c8;
    RefTex* texture0cc;
    RefTex* texture0d0;
    RefTex* texture0d4;
    RefTex* texture0d8;
    RefTex* texture0dc;
    RefTex* texture0e0;
    RefTex* texture0e4;
    RefTex* texture0e8;
    RefTex* texture0ec;
    RefTex* texture0f0;
    RefTex* texture0f4;
    RefTex* texture0f8;
    RefTex* texture0fc;
    RefTex* texture100;
    RefTex* texture104;
    RefTex* texture108;
    RefTex* texture10c;
    RefTex* texture110;
    RefTex* texture114;
    RefTex* texture118;
    RefTex* texture11c;
    RefTex* texture120;
    RefTex* texture124;
    RefTex* GetTexture094() const
    {
        return texture094;
    }
    RefTex* GetTexture098() const
    {
        return texture098;
    }
    RefTex* GetTexture09c() const
    {
        return texture09c;
    }
    RefTex* GetTexture0a0() const
    {
        return texture0a0;
    }
    RefTex* GetTexture0a4() const
    {
        return texture0a4;
    }
    RefTex* GetTexture0a8() const
    {
        return texture0a8;
    }
    RefTex* GetTexture0cc() const
    {
        return texture0cc;
    }
    RefTex* GetTexture0d0() const
    {
        return texture0d0;
    }
    RefTex* GetTexture0d4() const
    {
        return texture0d4;
    }
    RefTex* GetTexture0d8() const
    {
        return texture0d8;
    }
    RefTex* GetTexture0dc() const
    {
        return texture0dc;
    }
    RefTex* GetTexture0e0() const
    {
        return texture0e0;
    }
    RefTex* GetTexture0e4() const
    {
        return texture0e4;
    }
    RefTex* GetTexture0e8() const
    {
        return texture0e8;
    }
    RefTex* GetTexture0ec() const
    {
        return texture0ec;
    }
    RefTex* GetTexture0f0() const
    {
        return texture0f0;
    }
    RefTex* GetTexture0f8() const
    {
        return texture0f8;
    }
    RefTex* GetTexture0fc() const
    {
        return texture0fc;
    }
    RefTex* GetTexture100() const
    {
        return texture100;
    }
    RefTex* GetTexture114() const
    {
        return texture114;
    }
    RefTex* GetTexture118() const
    {
        return texture118;
    }
    RefTex* GetTexture11c() const
    {
        return texture11c;
    }
    RefTex* GetTexture120() const
    {
        return texture120;
    }
    RefTex* GetTexture124() const
    {
        return texture124;
    }
    void SkinShader_PresetPasses();
};
extern int DAT_011fb7d4;
extern int DAT_011fb7e0;
extern int DAT_011fb7f0;
extern int DAT_011fb7fc;
extern int DAT_011fb80c;
extern int DAT_011fb818;
extern int DAT_011fc3b4;
extern int DAT_011fc3c0;
extern int DAT_011fc3d0;
extern int DAT_011fc3dc;
extern int DAT_011fc3ec;
extern int DAT_011fc3f8;
extern int DAT_011fc40c;
extern int DAT_011fc418;
extern int DAT_011fc430;
extern int DAT_011fc43c;
extern int DAT_011fc454;
extern int DAT_011fc460;
extern int DAT_011fc478;
extern int DAT_011fc484;
extern int DAT_011fc4a0;
extern int DAT_011fc4bc;
extern int DAT_011fc4d4;
extern int DAT_011fc4ec;
extern int DAT_011fc500;
extern int DAT_011fc518;
extern int DAT_011fc52c;
extern int DAT_011fc544;
extern int DAT_011fc56c;
extern int DAT_011fc578;
extern int DAT_011fc59c;
extern int DAT_011fc5a8;
extern int DAT_011fcf94;
extern int DAT_011fcfa0;
extern int DAT_011fcfb0;
extern int DAT_011fcfbc;
extern int DAT_011fcfcc;
extern int DAT_011fcfd8;
extern int DAT_011fcfec;
extern int DAT_011fcff8;
extern int DAT_011fd010;
extern int DAT_011fd01c;
extern int DAT_011fd034;
extern int DAT_011fd040;
extern int DAT_011fd058;
extern int DAT_011fd064;
extern int DAT_011fd080;
extern int DAT_011fd09c;
extern int DAT_011fd0b4;
extern int DAT_011fd0cc;
extern int DAT_011fd0e0;
extern int DAT_011fd0f8;
extern int DAT_011fd10c;
extern int DAT_011fd124;
extern int DAT_011fd14c;
extern int DAT_011fd158;
extern int DAT_011fd17c;
extern int DAT_011fd188;
extern InitShaderPassPtr DAT_012022c0;
extern InitShaderPassPtr DAT_012022c4;
extern InitShaderPassPtr DAT_012022c8;
extern InitShaderPassPtr DAT_012022cc;
extern InitShaderPassPtr DAT_012022d0;
extern InitShaderPassPtr DAT_012022d4;
extern InitShaderPassPtr DAT_012022d8;
extern InitShaderPassPtr DAT_012022dc;
extern InitShaderPassPtr DAT_012022e0;
extern InitShaderPassPtr DAT_012022e4;
extern InitShaderPassPtr DAT_012022e8;
extern InitShaderPassPtr DAT_012022ec;
extern InitShaderPassPtr DAT_012022f0;
extern InitShaderPassPtr DAT_012022f4;
extern InitShaderPassPtr DAT_012022f8;
extern InitShaderPassPtr DAT_012022fc;
extern InitShaderPassPtr DAT_01202300;
extern InitShaderPassPtr DAT_01202304;
extern InitShaderPassPtr DAT_01202308;
extern InitShaderPassPtr DAT_0120230c;
extern InitShaderPassPtr DAT_01202310;
extern InitShaderPassPtr DAT_01202314;
extern InitShaderPassPtr DAT_01202318;
extern InitShaderPassPtr DAT_0120231c;
extern InitShaderPassPtr DAT_01202320;
extern InitShaderPassPtr DAT_01202324;
// Configures each shader pass in DAT_012022c0..DAT_01202324: adds texture stages, assigns textures, sets RSG states and writes size constants.
// @fnv 0x00c124c0
// src: COMMUNITY 0x00c124c0
void ShaderInitialization::SkinShader_PresetPasses()
{
    InitShaderPassPtr pass;
    InitTexStagePtr stage;
    pass = DAT_012022c0;
    unsigned int uiStageCount = pass->m_18;
    if (uiStageCount < 7)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 3, 0, 1);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 1, 2, 1);
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 3, 0, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
    }
    AssignTex(pass->m_5c, texture0ac);
    AssignTex(pass->m_44, texture104);
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fcfec = 1152;
    DAT_011fc40c = 12;
    pass = DAT_012022c4;
    if (pass->m_18 < 7)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 3, 0, 1);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 1, 2, 1);
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 3, 0, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
    }
    AssignTex(pass->m_5c, texture0b0);
    AssignTex(pass->m_44, texture104);
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fcff8 = 3200;
    DAT_011fc418 = 12;
    pass = DAT_012022c8;
    if (pass->m_18 < 7)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 3, 0, 1);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 1, 2, 1);
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 3, 0, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
    }
    AssignTex(pass->m_5c, texture0b4);
    AssignTex(pass->m_44, texture108);
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fd010 = 1264;
    DAT_011fc430 = 12;
    pass = DAT_012022cc;
    if (pass->m_18 < 7)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 3, 0, 1);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 1, 2, 1);
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 3, 0, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
    }
    AssignTex(pass->m_5c, texture0b8);
    AssignTex(pass->m_44, texture108);
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fd01c = 3312;
    DAT_011fc43c = 12;
    pass = DAT_012022d0;
    if (pass->m_18 < 7)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 3, 0, 1);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 1, 2, 1);
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 3, 0, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
    }
    AssignTex(pass->m_5c, texture0bc);
    AssignTex(pass->m_44, texture10c);
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fd034 = 1152;
    DAT_011fc454 = 12;
    pass = DAT_012022d4;
    if (pass->m_18 < 7)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 3, 0, 1);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 1, 2, 1);
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 3, 0, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
    }
    AssignTex(pass->m_5c, texture0c0);
    AssignTex(pass->m_44, texture10c);
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fd040 = 3200;
    DAT_011fc460 = 12;
    pass = DAT_012022d8;
    if (pass->m_18 < 7)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 3, 0, 1);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 1, 2, 1);
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 3, 0, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
    }
    AssignTex(pass->m_5c, texture0c4);
    AssignTex(pass->m_44, texture110);
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fd058 = 1264;
    DAT_011fc478 = 12;
    pass = DAT_012022dc;
    if (pass->m_18 < 7)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 3, 0, 1);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 1, 2, 1);
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 3, 0, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
    }
    AssignTex(pass->m_5c, texture0c8);
    AssignTex(pass->m_44, texture110);
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fd064 = 3312;
    DAT_011fc484 = 12;
    pass = DAT_012022e0;
    unsigned int uiStageCount8 = pass->m_18;
    if (uiStageCount8 < 8)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 1, 2, 1);
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 3, 0, 1);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 1, 2, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 7, 3, 0, 1);
        pass->NiD3DPass_SetStage(7, stage.m_p);
    }
    AssignTex(pass->m_5c, texture08c);
    AssignTex(pass->m_44, texture0f4);
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fd080 = 1920;
    DAT_011fc4a0 = 44;
    pass = DAT_012022e4;
    if (pass->m_18 < 8)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 1, 2, 1);
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 3, 0, 1);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 1, 2, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 7, 3, 0, 1);
        pass->NiD3DPass_SetStage(7, stage.m_p);
    }
    AssignTex(pass->m_5c, texture090);
    AssignTex(pass->m_44, texture0f4);
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fd09c = 3968;
    DAT_011fc4bc = 44;
    pass = DAT_012022e8;
    if (pass->m_18 < 8)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 1, 2, 1);
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 3, 0, 1);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 1, 2, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 7, 3, 0, 1);
        pass->NiD3DPass_SetStage(7, stage.m_p);
    }
    ((InitPassView*)pass.m_p)->NiD3DPass_SetVertexShader(GetTexture094());
    ((InitPassView*)pass.m_p)->NiD3DPass_SetPixelShader(GetTexture0f8());
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fd0b4 = 2032;
    DAT_011fc4d4 = 44;
    pass = DAT_012022ec;
    if (pass->m_18 < 8)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 1, 2, 1);
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 3, 0, 1);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 1, 2, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 7, 3, 0, 1);
        pass->NiD3DPass_SetStage(7, stage.m_p);
    }
    ((InitPassView*)pass.m_p)->NiD3DPass_SetVertexShader(GetTexture098());
    ((InitPassView*)pass.m_p)->NiD3DPass_SetPixelShader(GetTexture0f8());
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fd0cc = 4080;
    DAT_011fc4ec = 44;
    pass = DAT_012022f0;
    if (pass->m_18 < 8)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 1, 2, 1);
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 3, 0, 1);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 1, 2, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 7, 3, 0, 1);
        pass->NiD3DPass_SetStage(7, stage.m_p);
    }
    ((InitPassView*)pass.m_p)->NiD3DPass_SetVertexShader(GetTexture09c());
    ((InitPassView*)pass.m_p)->NiD3DPass_SetPixelShader(GetTexture0fc());
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fd0e0 = 1920;
    DAT_011fc500 = 44;
    pass = DAT_012022f4;
    if (pass->m_18 < 8)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 1, 2, 1);
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 3, 0, 1);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 1, 2, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 7, 3, 0, 1);
        pass->NiD3DPass_SetStage(7, stage.m_p);
    }
    ((InitPassView*)pass.m_p)->NiD3DPass_SetVertexShader(GetTexture0a0());
    ((InitPassView*)pass.m_p)->NiD3DPass_SetPixelShader(GetTexture0fc());
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fd0f8 = 3968;
    DAT_011fc518 = 44;
    pass = DAT_012022f8;
    if (pass->m_18 < 8)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 1, 2, 1);
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 3, 0, 1);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 1, 2, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 7, 3, 0, 1);
        pass->NiD3DPass_SetStage(7, stage.m_p);
    }
    ((InitPassView*)pass.m_p)->NiD3DPass_SetVertexShader(GetTexture0a4());
    ((InitPassView*)pass.m_p)->NiD3DPass_SetPixelShader(GetTexture100());
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fd10c = 2032;
    DAT_011fc52c = 44;
    pass = DAT_012022fc;
    if (pass->m_18 < 8)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 1, 2, 1);
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 3, 0, 1);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 1, 2, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 7, 3, 0, 1);
        pass->NiD3DPass_SetStage(7, stage.m_p);
    }
    ((InitPassView*)pass.m_p)->NiD3DPass_SetVertexShader(GetTexture0a8());
    ((InitPassView*)pass.m_p)->NiD3DPass_SetPixelShader(GetTexture100());
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fd124 = 4080;
    DAT_011fc544 = 44;
    pass = DAT_01202300;
    if (pass->m_18 < 4)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        ConfigureBeamStage(stage.m_p, 3, 3, 0, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 1, 2, 1);
        pass->NiD3DPass_SetStage(4, stage.m_p);
    }
    ((InitPassView*)pass.m_p)->NiD3DPass_SetVertexShader(GetTexture0cc());
    ((InitPassView*)pass.m_p)->NiD3DPass_SetPixelShader(GetTexture114());
    pass->GetRSG()->SetNodeValue(168, 15, true);
    ((InitPassView*)pass.m_p)->FUN_00b80040(2, 2, false);
    DAT_011fd14c = 1920;
    DAT_011fc56c = 12;
    pass = DAT_01202304;
    if (pass->m_18 < 4)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        ConfigureBeamStage(stage.m_p, 3, 3, 0, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 1, 2, 1);
        pass->NiD3DPass_SetStage(4, stage.m_p);
    }
    ((InitPassView*)pass.m_p)->NiD3DPass_SetVertexShader(GetTexture0d0());
    ((InitPassView*)pass.m_p)->NiD3DPass_SetPixelShader(GetTexture114());
    pass->GetRSG()->SetNodeValue(168, 15, true);
    ((InitPassView*)pass.m_p)->FUN_00b80040(2, 2, false);
    DAT_011fd158 = 3968;
    DAT_011fc578 = 12;
    pass = DAT_01202308;
    if (pass->m_18 < 4)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        ConfigureBeamStage(stage.m_p, 3, 3, 0, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 1, 2, 1);
        pass->NiD3DPass_SetStage(4, stage.m_p);
    }
    ((InitPassView*)pass.m_p)->NiD3DPass_SetVertexShader(GetTexture0d4());
    ((InitPassView*)pass.m_p)->NiD3DPass_SetPixelShader(GetTexture118());
    pass->GetRSG()->SetNodeValue(168, 15, true);
    ((InitPassView*)pass.m_p)->FUN_00b80040(2, 2, false);
    DAT_011fd17c = 1920;
    DAT_011fc59c = 12;
    pass = DAT_0120230c;
    if (pass->m_18 < 4)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        ConfigureBeamStage(stage.m_p, 3, 3, 0, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 1, 2, 1);
        pass->NiD3DPass_SetStage(4, stage.m_p);
    }
    ((InitPassView*)pass.m_p)->NiD3DPass_SetVertexShader(GetTexture0d8());
    ((InitPassView*)pass.m_p)->NiD3DPass_SetPixelShader(GetTexture118());
    pass->GetRSG()->SetNodeValue(168, 15, true);
    ((InitPassView*)pass.m_p)->FUN_00b80040(2, 2, false);
    DAT_011fd188 = 3968;
    DAT_011fc5a8 = 12;
    pass = DAT_01202310;
    if (pass->m_18 < 8)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 1, 2, 1);
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 1, 2, 1);
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 1, 2, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 7, 3, 0, 1);
        pass->NiD3DPass_SetStage(7, stage.m_p);
    }
    ((InitPassView*)pass.m_p)->NiD3DPass_SetVertexShader(GetTexture0dc());
    ((InitPassView*)pass.m_p)->NiD3DPass_SetPixelShader(GetTexture11c());
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fcf94 = 526208;
    DAT_011fc3b4 = 316;
    DAT_011fb7d4 = 768;
    pass = DAT_01202314;
    if (pass->m_18 < 8)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 1, 2, 1);
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 1, 2, 1);
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 1, 2, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 7, 3, 0, 1);
        pass->NiD3DPass_SetStage(7, stage.m_p);
    }
    ((InitPassView*)pass.m_p)->NiD3DPass_SetVertexShader(GetTexture0e0());
    ((InitPassView*)pass.m_p)->NiD3DPass_SetPixelShader(GetTexture11c());
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fcfa0 = 528256;
    DAT_011fc3c0 = 316;
    DAT_011fb7e0 = 768;
    pass = DAT_01202318;
    if (pass->m_18 < 8)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 1, 2, 1);
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 1, 2, 1);
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 1, 2, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 7, 3, 0, 1);
        pass->NiD3DPass_SetStage(7, stage.m_p);
    }
    ((InitPassView*)pass.m_p)->NiD3DPass_SetVertexShader(GetTexture0e4());
    ((InitPassView*)pass.m_p)->NiD3DPass_SetPixelShader(GetTexture120());
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fcfb0 = 526208;
    DAT_011fc3d0 = 316;
    DAT_011fb7f0 = 768;
    pass = DAT_0120231c;
    if (pass->m_18 < 8)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 1, 2, 1);
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 1, 2, 1);
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 1, 2, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 7, 3, 0, 1);
        pass->NiD3DPass_SetStage(7, stage.m_p);
    }
    ((InitPassView*)pass.m_p)->NiD3DPass_SetVertexShader(GetTexture0e8());
    ((InitPassView*)pass.m_p)->NiD3DPass_SetPixelShader(GetTexture120());
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fcfbc = 528256;
    DAT_011fc3dc = 316;
    DAT_011fb7fc = 768;
    pass = DAT_01202320;
    if (pass->m_18 < 8)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 1, 2, 1);
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 1, 2, 1);
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 1, 2, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 7, 3, 0, 1);
        pass->NiD3DPass_SetStage(7, stage.m_p);
    }
    ((InitPassView*)pass.m_p)->NiD3DPass_SetVertexShader(GetTexture0ec());
    ((InitPassView*)pass.m_p)->NiD3DPass_SetPixelShader(GetTexture124());
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fcfcc = 526208;
    DAT_011fc3ec = 316;
    DAT_011fb80c = 768;
    pass = DAT_01202324;
    if (pass->m_18 < 8)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(0, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(1, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 2, 1, 2, 1);
        pass->NiD3DPass_SetStage(2, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 3, 1, 2, 1);
        pass->NiD3DPass_SetStage(3, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 4, 1, 2, 1);
        pass->NiD3DPass_SetStage(4, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 5, 1, 2, 1);
        pass->NiD3DPass_SetStage(5, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 6, 1, 2, 1);
        pass->NiD3DPass_SetStage(6, stage.m_p);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.m_p, 7, 3, 0, 1);
        pass->NiD3DPass_SetStage(7, stage.m_p);
    }
    ((InitPassView*)pass.m_p)->NiD3DPass_SetVertexShader(GetTexture0f0());
    ((InitPassView*)pass.m_p)->NiD3DPass_SetPixelShader(GetTexture124());
    pass->GetRSG()->SetNodeValue(168, 15, true);
    pass->GetRSG()->SetNodeValue(27, 0, true);
    pass->GetRSG()->SetNodeValue(15, 0, true);
    pass->GetRSG()->SetNodeValue(7, 1, true);
    pass->GetRSG()->SetNodeValue(23, 4, true);
    pass->GetRSG()->SetNodeValue(14, 1, true);
    DAT_011fcfd8 = 528256;
    DAT_011fc3f8 = 316;
    DAT_011fb818 = 768;
}
}  // namespace fnv_00c124c0

struct C16400Shader
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    RefTex* m_8c;
    RefTex* m_90;
    RefTex* m_94;
    RefTex* m_98;
    RefTex* m_9c;
    RefTex* m_a0;
    RefTex* m_a4;
    RefTex* m_a8;
    RefTex* m_ac;
    RefTex* m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    int m_e4;
    int m_e8;
    int m_ec;
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fc;
    int m_100;
    RefTex* m_104;
    RefTex* m_108;
    RefTex* m_10c;
    RefTex* m_110;
    RefTex* m_114;
    RefTex* m_118;
    RefTex* m_11c;
    RefTex* m_120;
    RefTex* m_124;
    RefTex* m_128;
    void SpeedTreeBranchShader_Func_87();
};
extern int DAT_011f950c;
extern int DAT_011f9534;
extern int DAT_011f9538;
extern int DAT_011faa40;
extern int DAT_011faa60;
extern int DAT_011faa70;
extern int DAT_011faac8;
extern int DAT_011faacc;
extern int DAT_011faad0;
extern int DAT_011faad8;
extern int DAT_011faadc;
extern int DAT_011fad90;
extern int DAT_011fad94;
extern int DAT_011fada0;
extern int DAT_011fada4;
extern int DAT_011fae08;
extern int DAT_011fae24;
extern int DAT_011fae30;
extern int DAT_011fae34;
extern int DAT_011fae40;
extern int DAT_011fae44;
extern int DAT_011fb228;
extern int DAT_011fb238;
extern int DAT_011fb620;
extern int DAT_011fb640;
extern int DAT_011fb650;
extern int DAT_011fb6a8;
extern int DAT_011fb6ac;
extern int DAT_011fb6b0;
extern int DAT_011fb6b8;
extern int DAT_011fb6bc;
extern int DAT_011fb970;
extern int DAT_011fb974;
extern int DAT_011fb980;
extern int DAT_011fb984;
extern int DAT_011fb9e8;
extern int DAT_011fba04;
extern int DAT_011fba10;
extern int DAT_011fba14;
extern int DAT_011fba20;
extern int DAT_011fba24;
extern int DAT_011fbe08;
extern int DAT_011fbe18;
extern int DAT_011fc200;
extern int DAT_011fc220;
extern int DAT_011fc230;
extern int DAT_011fc288;
extern int DAT_011fc28c;
extern int DAT_011fc290;
extern int DAT_011fc298;
extern int DAT_011fc29c;
extern int DAT_011fc550;
extern int DAT_011fc554;
extern int DAT_011fc560;
extern int DAT_011fc564;
extern int DAT_011fc5c8;
extern int DAT_011fc5e4;
extern int DAT_011fc5f0;
extern int DAT_011fc5f4;
extern int DAT_011fc600;
extern int DAT_011fc604;
extern int DAT_011fc9e8;
extern int DAT_011fc9f8;
extern int DAT_011fcde0;
extern int DAT_011fce00;
extern int DAT_011fce10;
extern int DAT_011fce68;
extern int DAT_011fce6c;
extern int DAT_011fce70;
extern int DAT_011fce78;
extern int DAT_011fce7c;
extern int DAT_011fd130;
extern int DAT_011fd134;
extern int DAT_011fd140;
extern int DAT_011fd144;
extern int DAT_011fd1a8;
extern int DAT_011fd1c4;
extern int DAT_011fd1d0;
extern int DAT_011fd1d4;
extern int DAT_011fd1e0;
extern int DAT_011fd1e4;
extern int DAT_011fd5c8;
extern int DAT_011fd5d8;
extern ShaderPassPtr DAT_01202350;
extern ShaderPassPtr DAT_01202354;
extern ShaderPassPtr DAT_01202358;
extern ShaderPassPtr DAT_0120235c;
extern ShaderPassPtr DAT_01202360;
extern ShaderPassPtr DAT_01202364;
extern ShaderPassPtr DAT_01202368;
extern ShaderPassPtr DAT_0120236c;
extern ShaderPassPtr DAT_01202370;
extern ShaderPassPtr DAT_01202374;
static __forceinline void SetupC16400Stages1(ShaderPassPtr& pass, TexStagePtr& stage)
{
    unsigned int count = pass->m_18;
    if (count < 1)
    {
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 0, 1, 2, 1);
        pass->SetStage(pass->unk14, stage.m_p);
    }
}

static __forceinline void SetupC16400Stages2(ShaderPassPtr& pass, TexStagePtr& stage)
{
    unsigned int count = pass->m_18;
    if (count < 2)
    {
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 0, 1, 2, 1);
        pass->SetStage(pass->unk14, stage.m_p);
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 0, 1, 2, 1);
        pass->SetStage(pass->unk14, stage.m_p);
    }
}

static __forceinline void SetupC16400Stages4(ShaderPassPtr& pass, TexStagePtr& stage)
{
    unsigned int count = pass->m_18;
    if (count < 4)
    {
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 0, 1, 2, 1);
        pass->SetStage(pass->unk14, stage.m_p);
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 1, 3, 2, 1);
        stage.m_p->m_08 = DAT_011f9534;
        pass->SetStage(pass->unk14, stage.m_p);
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 2, 3, 2, 1);
        stage.m_p->m_08 = DAT_011f9538;
        pass->SetStage(pass->unk14, stage.m_p);
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 3, 1, 2, 1);
        stage.m_p->m_08 = DAT_011f950c;
        pass->SetStage(pass->unk14, stage.m_p);
    }
}
// Configures ten shader passes: ensures their stages exist, assigns textures from m_8c..m_128, sets render states and copies render-state groups.
// @fnv 0x00c16400
// src: COMMUNITY 0x00c16400
void C16400Shader::SpeedTreeBranchShader_Func_87()
{
    ShaderPassPtr pass;
    TexStagePtr stage;
    pass = DAT_01202350;
    SetupC16400Stages1(pass, stage);
    AssignTex(pass->m_5c, m_8c);
    AssignTex(pass->m_44, m_104);
    pass->GetRSG()->SetRenderState(27, 0, true);
    pass->GetRSG()->SetRenderState(15, 0, true);
    pass->GetRSG()->SetRenderState(7, 1, true);
    pass->GetRSG()->SetRenderState(23, 4, true);
    pass->GetRSG()->SetRenderState(14, 1, true);
    DAT_011fce00 = DAT_011fcde0;
    DAT_011fc220 = DAT_011fc200;
    DAT_011fb640 = DAT_011fb620;
    DAT_011faa60 = DAT_011faa40;
    pass = DAT_01202354;
    SetupC16400Stages2(pass, stage);
    AssignTex(pass->m_5c, m_90);
    AssignTex(pass->m_44, m_108);
    pass->GetRSG()->SetRenderState(27, 0, true);
    pass->GetRSG()->SetRenderState(15, 0, true);
    pass->GetRSG()->SetRenderState(7, 1, true);
    pass->GetRSG()->SetRenderState(23, 4, true);
    pass->GetRSG()->SetRenderState(14, 1, true);
    DAT_011fce68 = DAT_011fce10;
    DAT_011fc288 = DAT_011fc230;
    DAT_011fb6a8 = DAT_011fb650;
    DAT_011faac8 = DAT_011faa70;
    pass = DAT_01202358;
    SetupC16400Stages2(pass, stage);
    AssignTex(pass->m_5c, m_94);
    AssignTex(pass->m_44, m_10c);
    pass->GetRSG()->SetRenderState(27, 0, true);
    pass->GetRSG()->SetRenderState(15, 0, true);
    pass->GetRSG()->SetRenderState(7, 1, true);
    pass->GetRSG()->SetRenderState(23, 4, true);
    pass->GetRSG()->SetRenderState(14, 1, true);
    DAT_011fce6c = DAT_011fce7c;
    DAT_011fc28c = DAT_011fc29c;
    DAT_011fb6ac = DAT_011fb6bc;
    DAT_011faacc = DAT_011faadc;
    pass = DAT_0120235c;
    SetupC16400Stages4(pass, stage);
    AssignTex(pass->m_5c, m_98);
    AssignTex(pass->m_44, m_110);
    pass->GetRSG()->SetRenderState(27, 0, true);
    pass->GetRSG()->SetRenderState(15, 0, true);
    pass->GetRSG()->SetRenderState(7, 1, true);
    pass->GetRSG()->SetRenderState(23, 4, true);
    pass->GetRSG()->SetRenderState(14, 1, true);
    DAT_011fce78 = DAT_011fce70;
    DAT_011fc298 = DAT_011fc290;
    DAT_011fb6b8 = DAT_011fb6b0;
    DAT_011faad8 = DAT_011faad0;
    pass = DAT_01202360;
    SetupC16400Stages1(pass, stage);
    AssignTex(pass->m_5c, m_9c);
    AssignTex(pass->m_44, m_114);
    pass->GetRSG()->SetRenderState(19, 2, true);
    pass->GetRSG()->SetRenderState(20, 2, true);
    DAT_011fd140 = DAT_011fd130;
    DAT_011fc560 = DAT_011fc550;
    DAT_011fb980 = DAT_011fb970;
    DAT_011fada0 = DAT_011fad90;
    pass = DAT_01202364;
    SetupC16400Stages4(pass, stage);
    AssignTex(pass->m_5c, m_a0);
    AssignTex(pass->m_44, m_118);
    pass->GetRSG()->SetRenderState(19, 2, true);
    pass->GetRSG()->SetRenderState(20, 2, true);
    DAT_011fd144 = DAT_011fd134;
    DAT_011fc564 = DAT_011fc554;
    DAT_011fb984 = DAT_011fb974;
    DAT_011fada4 = DAT_011fad94;
    pass = DAT_0120236c;
    SetupC16400Stages1(pass, stage);
    AssignTex(pass->m_5c, m_a8);
    AssignTex(pass->m_44, m_120);
    pass->GetRSG()->SetRenderState(19, 2, true);
    pass->GetRSG()->SetRenderState(20, 2, true);
    DAT_011fd1e0 = DAT_011fd1d0;
    DAT_011fc600 = DAT_011fc5f0;
    DAT_011fba20 = DAT_011fba10;
    DAT_011fae40 = DAT_011fae30;
    pass = DAT_01202370;
    SetupC16400Stages4(pass, stage);
    AssignTex(pass->m_5c, m_ac);
    AssignTex(pass->m_44, m_124);
    pass->GetRSG()->SetRenderState(19, 2, true);
    pass->GetRSG()->SetRenderState(20, 2, true);
    DAT_011fd1e4 = DAT_011fd1d4;
    DAT_011fc604 = DAT_011fc5f4;
    DAT_011fba24 = DAT_011fba14;
    DAT_011fae44 = DAT_011fae34;
    pass = DAT_01202368;
    SetupC16400Stages1(pass, stage);
    AssignTex(pass->m_5c, m_a4);
    AssignTex(pass->m_44, m_11c);
    pass->GetRSG()->SetRenderState(19, 9, true);
    pass->GetRSG()->SetRenderState(20, 1, true);
    DAT_011fd1c4 = DAT_011fd1a8;
    DAT_011fc5e4 = DAT_011fc5c8;
    DAT_011fba04 = DAT_011fb9e8;
    DAT_011fae24 = DAT_011fae08;
    pass = DAT_01202374;
    SetupC16400Stages1(pass, stage);
    AssignTex(pass->m_5c, m_b0);
    AssignTex(pass->m_44, m_128);
    pass->GetRSG()->SetRenderState(27, 1, true);
    pass->GetRSG()->SetRenderState(19, 5, true);
    pass->GetRSG()->SetRenderState(20, 6, true);
    pass->GetRSG()->SetRenderState(15, 0, true);
    pass->GetRSG()->SetRenderState(7, 1, true);
    pass->GetRSG()->SetRenderState(23, 3, true);
    pass->GetRSG()->SetRenderState(14, 0, true);
    DAT_011fd5d8 = DAT_011fd5c8;
    DAT_011fc9f8 = DAT_011fc9e8;
    DAT_011fbe18 = DAT_011fbe08;
    DAT_011fb238 = DAT_011fb228;
}

extern int _DAT_012024fc;
extern int _DAT_012024f8;
extern char UNK_00fdd3b0;
void __cdecl FUN_00ec658f(void*);

// The game's function-local null NiPointer and its initialization guard are
// referenced explicitly here; their original storage is 0x012024f8/0x012024fc.
// @fnv 0x00c1d8b0
template <> void NiTArray<NiPointer<NiObject>, NiTNewInterface<NiPointer<NiObject> > >::SetAt(unsigned int index, const NiPointer<NiObject>& value)
{
    int one = 1;
    if ((*(unsigned char*)&_DAT_012024fc & one) == 0)
    {
        _DAT_012024fc |= one;
        _DAT_012024f8 = 0;
        FUN_00ec658f(&UNK_00fdd3b0);
    }

    if (index >= m_usSize)
    {
        m_usSize = (unsigned short)(index + 1);
        if (value.m_pObject != (NiObject*)_DAT_012024f8)
            m_usESize += one;
    }
    else
    {
        if (value.m_pObject != (NiObject*)_DAT_012024f8)
        {
            if (m_pBase[index].m_pObject == (NiObject*)_DAT_012024f8)
                m_usESize += one;
        }
        else if (m_pBase[index].m_pObject != (NiObject*)_DAT_012024f8)
        {
            m_usESize += 0xffff;
        }
    }

    m_pBase[index] = value;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);










// Finds the first empty slot in the array and stores element there, incrementing m_usESize; returns the index, or appends via SetAtGrow if none is free.
// @fnv 0x00c1f420
template <> unsigned int NiTArray<NiPointer<NiObject>, NiTNewInterface<NiPointer<NiObject> > >::AddFirstEmpty(const NiPointer<NiObject>& element)
{
    if (element == NiPointer<NiObject>(0))
        return (unsigned int)~0;

    for (unsigned short i = 0; i < m_usSize; i++)
    {
        if (m_pBase[i] == NiPointer<NiObject>(0))
        {
            m_pBase[i] = element;
            m_usESize++;
            return i;
        }
    }

    return SetAtGrow(m_usSize, element);
}

struct FNVSampler
{
    void __thiscall SetNodeValue(int attribute, int mode, int enabled);
};

struct FNVFace
{

    unsigned int unk000;

    unsigned int unk004;

    unsigned int unk008;

    unsigned int unk00c;

    unsigned int unk010;

    unsigned int unk014;

    unsigned int unk018;

    unsigned int unk01c;

    unsigned int unk020;

    unsigned int unk024;

    unsigned int unk028;

    unsigned int unk02c;

    unsigned int unk030;

    unsigned int unk034;

    unsigned int unk038;

    unsigned int unk03c;

    unsigned int unk040;

    unsigned int unk044;

    unsigned int unk048;

    unsigned int unk04c;

    unsigned int unk050;

    unsigned int unk054;

    unsigned int unk058;

    unsigned int unk05c;

    unsigned int unk060;

    void __thiscall NiD3DTextureStage_ReturnStageToPool();
    void DecRef()
    {
        if (--unk060 == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};

struct FNVCubeSurface
{

    unsigned int unk00;

    unsigned int unk04;

    unsigned int unk08;

    unsigned int unk0c;

    unsigned int unk10;

    void* m_currentFace;

    unsigned int m_faceCount;

    unsigned int unk1c;

    unsigned int unk20;

    unsigned int unk24;

    unsigned int unk28;

    unsigned int unk2c;

    FNVSampler* m_sampler;

    unsigned int unk34;

    unsigned int unk38;

    unsigned int unk3c;

    unsigned int unk40;

    RefObject* m_colorTarget;

    unsigned int unk48;

    unsigned int unk4c;

    unsigned int unk50;

    unsigned int unk54;

    unsigned int unk58;

    RefObject* m_depthTarget;

    unsigned int unk60;

    unsigned int m_iObjectReferenceCount;

    unsigned int GetNumberOfFaces() const
    {
        return m_faceCount;
    }
    void __thiscall FUN_00e80190();

    void __thiscall NiD3DPass_SetStage(void* currentFace, FNVFace* replacement);
};

struct FNVRenderManager
{

    unsigned int unk000;

    unsigned int unk004;

    unsigned int m_faceFormat;

    unsigned int m_faceFlags;

    unsigned int unk010;

    unsigned int unk014;

    unsigned int unk018;

    unsigned int unk01c;

    unsigned int unk020;

    unsigned int unk024;

    unsigned int unk028;

    unsigned int unk02c;

    unsigned int unk030;

    unsigned int unk034;

    unsigned int unk038;

    unsigned int unk03c;

    unsigned int unk040;

    unsigned int unk044;

    unsigned int unk048;

    unsigned int unk04c;

    unsigned int unk050;

    unsigned int unk054;

    unsigned int unk058;

    unsigned int unk05c;

    unsigned int unk060;

    unsigned int unk064;

    unsigned int unk068;

    unsigned int unk06c;

    unsigned int unk070;

    unsigned int unk074;

    unsigned int unk078;

    unsigned int unk07c;

    unsigned int unk080;

    unsigned int unk084;

    unsigned int unk088;

    unsigned int unk08c;

    unsigned int unk090;

    unsigned int unk094;

    unsigned int unk098;

    unsigned int unk09c;

    unsigned int unk0a0;

    unsigned int unk0a4;

    unsigned int unk0a8;

    unsigned int unk0ac;

    unsigned int unk0b0;

    unsigned int unk0b4;

    unsigned int unk0b8;

    unsigned int unk0bc;

    unsigned int unk0c0;

    unsigned int unk0c4;

    RefObject* m_depthTarget0;

    RefObject* m_depthTarget1;

    RefObject* m_depthTarget2;

    RefObject* m_depthTarget3;

    RefObject* m_depthTarget4;

    unsigned int unk0dc;

    unsigned int unk0e0;

    unsigned int unk0e4;

    unsigned int unk0e8;

    unsigned int unk0ec;

    unsigned int unk0f0;

    unsigned int unk0f4;

    unsigned int unk0f8;

    unsigned int unk0fc;

    unsigned int unk100;

    unsigned int unk104;

    unsigned int unk108;

    unsigned int unk10c;

    unsigned int unk110;

    unsigned int unk114;

    unsigned int unk118;

    unsigned int unk11c;

    unsigned int unk120;

    unsigned int unk124;

    unsigned int unk128;

    unsigned int unk12c;

    unsigned int unk130;

    unsigned int unk134;

    unsigned int unk138;

    RefObject* m_colorTarget0;

    RefObject* m_colorTarget1;

    RefObject* m_colorTarget2;

    RefObject* m_colorTarget3;

    RefObject* m_colorTarget4;

    void __thiscall SetupCubeSurfaces();
};

extern FNVCubeSurface* DAT_012022a0;

extern FNVCubeSurface* DAT_012022a4;

extern FNVCubeSurface* DAT_012022a8;

extern FNVCubeSurface* DAT_012022ac;

extern FNVCubeSurface* DAT_012022b0;

extern unsigned int DAT_011fd1f0, DAT_011fd208, DAT_011fd220, DAT_011fd238, DAT_011fd250;

extern unsigned int DAT_011fc610, DAT_011fc628, DAT_011fc638, DAT_011fc640, DAT_011fc650, DAT_011fc658, DAT_011fc668,
    DAT_011fc670;

extern void __cdecl AssignStageFromPool(FNVFace** destination);

extern void __cdecl ConfigureBeamStage(FNVFace* target, int face, int enabled, int channel, int layer);

struct FNVFaceRef
{

    FNVFace* face;

    FNVFaceRef() : face(0)
    {}

    ~FNVFaceRef()
    {

        if (face)
            face->DecRef();
    }
};

struct FNVCubeRef
{

    FNVCubeSurface* surface;

    FNVCubeRef() : surface(0)
    {}

    ~FNVCubeRef()
    {
        if (surface && --surface->m_iObjectReferenceCount == 0)
            surface->FUN_00e80190();
    }

    void operator=(FNVCubeSurface* const& next)
    {

        if (surface == next)
            return;

        if (surface && --surface->m_iObjectReferenceCount == 0)
            surface->FUN_00e80190();

        surface = next;

        if (surface)
            ++surface->m_iObjectReferenceCount;
    }
};

static __forceinline void AssignTarget(RefObject*& dst, RefObject* src)
{
    RefObject* old = dst;
    if (old != src)
    {
        if (old && InterlockedDecrement((volatile long*)&old->m_iObjectReferenceCount) == 0)
            old->DeleteThis();
        dst = src;
        if (src)
            InterlockedIncrement((volatile long*)&src->m_iObjectReferenceCount);
    }
}

// For each of the five cube surfaces, adds six faces when fewer than six exist, assigns depth/color targets, sets sampler states and writes render-state globals.
// @fnv 0x00c11980
void __thiscall FNVRenderManager::SetupCubeSurfaces()
{

    FNVRenderManager* owner = this;

    FNVRenderManager* pManager = owner;

    FNVCubeRef current;

    FNVFaceRef faceRef;

    current = DAT_012022a0;

    if (current.surface->GetNumberOfFaces() < 6)
    {

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 0, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 1, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 2, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        faceRef.face->unk008 = DAT_011f9534;

        faceRef.face->unk00c = 1;

        ConfigureBeamStage(faceRef.face, 3, 3, 0, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 4, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 5, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);
    }

    AssignTarget(current.surface->m_depthTarget, owner->m_depthTarget0);

    AssignTarget(current.surface->m_colorTarget, owner->m_colorTarget0);

    if (!current.surface->m_sampler)
        current.surface->m_sampler = reinterpret_cast<FNVSampler*>(FUN_00e7f5d0());

    current.surface->m_sampler->SetNodeValue(19, 2, 1);

    if (!current.surface->m_sampler)
        current.surface->m_sampler = reinterpret_cast<FNVSampler*>(FUN_00e7f5d0());

    current.surface->m_sampler->SetNodeValue(20, 2, 1);

    DAT_011fd1f0 = 0x480;

    DAT_011fc610 = 0x28;

    current = DAT_012022a4;

    if (current.surface->GetNumberOfFaces() < 6)
    {

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 0, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 1, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 2, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        faceRef.face->unk008 = DAT_011f9534;

        faceRef.face->unk00c = 1;

        ConfigureBeamStage(faceRef.face, 3, 3, 0, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 4, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 5, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);
    }

    AssignTarget(current.surface->m_depthTarget, pManager->m_depthTarget1);

    AssignTarget(current.surface->m_colorTarget, pManager->m_colorTarget1);

    if (!current.surface->m_sampler)
        current.surface->m_sampler = reinterpret_cast<FNVSampler*>(FUN_00e7f5d0());

    current.surface->m_sampler->SetNodeValue(19, 2, 1);

    if (!current.surface->m_sampler)
        current.surface->m_sampler = reinterpret_cast<FNVSampler*>(FUN_00e7f5d0());

    current.surface->m_sampler->SetNodeValue(20, 2, 1);

    DAT_011fd208 = 0x4f0;

    DAT_011fc628 = 0x28;

    current = DAT_012022a8;

    if (current.surface->GetNumberOfFaces() < 6)
    {

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 0, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 1, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 2, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        faceRef.face->unk008 = DAT_011f9534;

        faceRef.face->unk00c = 1;

        ConfigureBeamStage(faceRef.face, 3, 3, 0, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 4, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 5, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);
    }

    AssignTarget(current.surface->m_depthTarget, pManager->m_depthTarget2);

    AssignTarget(current.surface->m_colorTarget, pManager->m_colorTarget2);

    if (!current.surface->m_sampler)
        current.surface->m_sampler = reinterpret_cast<FNVSampler*>(FUN_00e7f5d0());

    current.surface->m_sampler->SetNodeValue(19, 2, 1);

    if (!current.surface->m_sampler)
        current.surface->m_sampler = reinterpret_cast<FNVSampler*>(FUN_00e7f5d0());

    current.surface->m_sampler->SetNodeValue(20, 2, 1);

    DAT_011fd220 = 0x480;

    DAT_011fc640 = DAT_011fc638;

    current = DAT_012022ac;

    if (current.surface->GetNumberOfFaces() < 6)
    {

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 0, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 1, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 2, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        faceRef.face->unk008 = DAT_011f9534;

        faceRef.face->unk00c = 1;

        ConfigureBeamStage(faceRef.face, 3, 3, 0, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 4, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 5, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);
    }

    AssignTarget(current.surface->m_depthTarget, pManager->m_depthTarget3);

    AssignTarget(current.surface->m_colorTarget, pManager->m_colorTarget3);

    if (!current.surface->m_sampler)
        current.surface->m_sampler = reinterpret_cast<FNVSampler*>(FUN_00e7f5d0());

    current.surface->m_sampler->SetNodeValue(19, 2, 1);

    if (!current.surface->m_sampler)
        current.surface->m_sampler = reinterpret_cast<FNVSampler*>(FUN_00e7f5d0());

    current.surface->m_sampler->SetNodeValue(20, 2, 1);

    DAT_011fd238 = 0x480;

    DAT_011fc658 = DAT_011fc650;

    current = DAT_012022b0;

    if (current.surface->GetNumberOfFaces() < 6)
    {

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 0, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 1, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 2, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        faceRef.face->unk008 = DAT_011f9534;

        faceRef.face->unk00c = 1;

        ConfigureBeamStage(faceRef.face, 3, 3, 0, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 4, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);

        AssignStageFromPool(&faceRef.face);

        ConfigureBeamStage(faceRef.face, 5, 1, 2, 1);

        current.surface->NiD3DPass_SetStage(current.surface->m_currentFace, faceRef.face);
    }

    AssignTarget(current.surface->m_depthTarget, pManager->m_depthTarget4);

    AssignTarget(current.surface->m_colorTarget, pManager->m_colorTarget4);

    if (!current.surface->m_sampler)
        current.surface->m_sampler = reinterpret_cast<FNVSampler*>(FUN_00e7f5d0());

    current.surface->m_sampler->SetNodeValue(19, 2, 1);

    if (!current.surface->m_sampler)
        current.surface->m_sampler = reinterpret_cast<FNVSampler*>(FUN_00e7f5d0());

    current.surface->m_sampler->SetNodeValue(20, 2, 1);

    DAT_011fd250 = 0x480;

    DAT_011fc670 = DAT_011fc668;
}

struct Color374
{
    float r, g, b, a;
    Color374(float red, float green, float blue, float alpha) : r(red), g(green), b(blue), a(alpha)
    {}
};
extern Color374 _DAT_011fa270;
extern unsigned char DAT_011F941E;
struct Settings374
{
    unsigned int unk00, unk04, unk08;
    float scale;
};
struct Material374
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    Settings374* settings;
};
struct Group374
{
    unsigned int unk00;
    Material374* material;
};
struct Manager374
{
    unsigned int unk00, unk04;
    Group374* group;
};
extern Manager374* _DAT_011f91ac;
struct Source374
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    NiPoint3 fallback;
    const NiPoint3* color;
    unsigned int unk38, unk3c;
    float multiplier;
};
// @fnv 0x00c03180
void __stdcall ApplySourceColor(Source374* source)
{
    NiPoint3 color = source->color ? *source->color : source->fallback;
    if (DAT_011F941E)
        color *= (_DAT_011f91ac->group->material->settings->scale * source->multiplier);
    _DAT_011fa270 = Color374(color.x, color.y, color.z, 1.0f);
}

extern "C" void __cdecl BSShaderManager_ReturnVelocityBuffers();

// @fnv 0x00c04950
// src: COMMUNITY 0x00c04950
void __cdecl ImageSpaceEffectMotionBlur_Shutdown()
{
    BSShaderManager_ReturnVelocityBuffers();
}


template <> void NiTArray<S_00c05250_Obj*, NiTMallocInterface<S_00c05250_Obj*> >::SetAt(unsigned int, S_00c05250_Obj* const&) throw();

struct FUN_00c04da0 : _Base_00ba3d30
{
    ~FUN_00c04da0();
};
// If the first element of m_18 is non-null, deletes it and clears that slot to null.
// @fnv 0x00c04da0
FUN_00c04da0::~FUN_00c04da0()
{
    if (m_18.m_pBase[0])
    {
        delete m_18.m_pBase[0];
        m_18.SetAt(0, 0);
    }
}

// @fnv 0x00c05870
// src: GUESS 0x00c05870 (confidence: low)
float __cdecl Runtime_EvaluateValue_00c05870()
{
    return 1.0f;
}

extern "C" unsigned int __cdecl _rotl(unsigned int, int);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
inline void NiD3DShaderConstantMap::IncRefCount()
{
    NiRefObject::IncRefCount();
}
inline void NiD3DShaderConstantMap::DecRefCount()
{
    NiRefObject::DecRefCount();
}

// The shared declarations for these virtual slots do not yet accept an entry.
// Keep the entry-taking calls here until their signatures are available there.
typedef void (__thiscall* ShaderConstantEntryCall)(NiD3DShaderConstantMap*, NiShaderConstantMapEntry*);
inline void AddShaderConstantEntry(NiD3DShaderConstantMap* map, NiShaderConstantMapEntry* entry)
{
    reinterpret_cast<ShaderConstantEntryCall>((*reinterpret_cast<void***>(map))[32])(map, entry);
}
inline void AddDefinedShaderConstantEntry(NiD3DShaderConstantMap* map, NiShaderConstantMapEntry* entry)
{
    reinterpret_cast<ShaderConstantEntryCall>((*reinterpret_cast<void***>(map))[33])(map, entry);
}

struct State
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    NiPointer<NiD3DShaderConstantMap> pixel;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    NiPointer<NiD3DShaderConstantMap> vertex;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int refs;
    void DestroyState();
};
struct StatePtr
{
    State* p;
    StatePtr() : p(0)
    {}
    ~StatePtr()
    {
        if (p && --p->refs == 0)
            p->DestroyState();
    }
    StatePtr& operator=(const StatePtr& other)
    {
        if (p != other.p)
        {
            if (p && --p->refs == 0)
                p->DestroyState();
            p = other.p;
            if (p)
                ++p->refs;
        }
        return *this;
    }
};
extern StatePtr DAT_01200ec0[112];
extern unsigned DAT_01200a28[112];
extern unsigned DAT_01200868[112];
extern NiShaderConstantMapEntry* DAT_01201080[17];
extern NiShaderConstantMapEntry* DAT_012010c4[10];
struct Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* renderer;
    int unk1c;
    int unk20;
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
    NiD3DShaderConstantMap* pixel;
    NiD3DShaderConstantMap* vertex;
    void InitShaderConstantMaps();
};
// @fnv 0x00c06f80
void Owner::InitShaderConstantMaps()
{
    StatePtr state;
    for (int index = 0; index < 112; ++index)
    {
        state = DAT_01200ec0[index];
        if (index == 102 || index == 103)
            continue;
        NiD3DShaderConstantMap* vertex = new NiD3DShaderConstantMap(renderer, 0);
        NiD3DShaderConstantMap* pixel = new NiD3DShaderConstantMap(renderer, 2);
        {
            unsigned mask = 1;
            for (int entry = 0; entry < 17; ++entry)
            {
                unsigned currentMask = mask;
                currentMask = _rotl(currentMask, 1);
                if (currentMask & DAT_01200a28[index])
                {
                    NiShaderConstantMapEntry* e = DAT_01201080[entry];
                    if (e)
                    {
                        if ((e->m_uiValue1 & 0xf0000000) == 0x20000000)
                            AddDefinedShaderConstantEntry(vertex, e);
                        else
                            AddShaderConstantEntry(vertex, e);
                    }
                }
                mask = currentMask;
            }
        }
        {
            unsigned mask = 1;
            for (int entry = 0; entry < 10; ++entry)
            {
                unsigned currentMask = mask;
                currentMask = _rotl(currentMask, 1);
                if (currentMask & DAT_01200868[index])
                {
                    NiShaderConstantMapEntry* e = DAT_012010c4[entry];
                    if (e)
                    {
                        if ((e->m_uiValue1 & 0xf0000000) == 0x20000000)
                            AddDefinedShaderConstantEntry(pixel, e);
                        else
                            AddShaderConstantEntry(pixel, e);
                    }
                }
                mask = currentMask;
            }
        }
        state.p->vertex = vertex;
        state.p->pixel = pixel;
    }
    DAT_01200ec0[102].p->vertex = vertex;
    DAT_01200ec0[102].p->pixel = pixel;
    DAT_01200ec0[103].p->vertex = vertex;
    DAT_01200ec0[103].p->pixel = pixel;
}

void __cdecl FUN_00a74640();
// @fnv 0x00c1a630
// src: COMMUNITY 0x00c1a630
void __cdecl TallGrassTriShape_CreateClone()
{
    FUN_00a74640();
}

extern "C" void _ReadWriteBarrier();
struct P440Light;
struct P440Pass;
struct P440Camera;
struct P440Renderer;
struct P440Material;
struct P440Geometry;
struct P440List;
struct P440Extra;
struct P440LightFlags;
struct P440Position
{
    float x, y, z, r;
};
struct P440Vector
{
    float x, y, z;
    float FUN_00457990();
};
struct P440LightFlags
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int flags;
};
struct P440Light
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    float alpha;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    bool special;
    char unked;
    short unkee;
    unsigned int unkf0;
    unsigned int unkf4;
    P440LightFlags* settings;
};
struct P440Pass
{
    unsigned int unk00;
    unsigned short shader;
    unsigned char blend;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char count;
    unsigned char capacity;
    unsigned char unk0b;
    P440Light** lights;
    void BSShaderProperty_RenderPass_ClearSceneLights();
    void AllocateElemArray(unsigned char);
};
struct P440List
{
    unsigned int unk00;
    P440Pass** passes;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int count;
    void FUN_00ba9ee0(P440Geometry*, unsigned int, bool, unsigned char, P440Light*, P440Light*, P440Light*, P440Light*);
};
struct P440Material
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    int skinned;
};
struct P440PropertyState
{
    P440LightFlags* flags;
    unsigned int unk04;
    P440Light* fade;
};
struct P440Geometry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    P440Position* position;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    P440PropertyState properties;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    P440Material* material;
    unsigned int unkbc;
};
struct P440Camera
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    P440Light* defaultLight;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    float scale;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned char mode;
    char unk121;
    short unk122;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    P440Light* depthLight;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    P440Vector position;
    P440Vector GetPosition() const
    {
        return position;
    }
    const P440Vector& GetPositionRef() const
    {
        return position;
    }
};
struct P440Renderer
{
    unsigned int unk00;
    unsigned int unk04;
    P440Camera* active;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    int mode;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    float scale;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    P440Camera* camera;
    const P440Vector& GetCameraPosition() const
    {
        return camera->position;
    }
};
struct P440Extra
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    int enabled;
};
struct P440Shader
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int flags;
    unsigned int flags2;
    float alpha;
    float opacity;
    unsigned int unk30;
    float distance;
    unsigned int cacheKey;
    P440List* passes;
    P440List* depthPasses;
    P440List* normalPasses;
    P440List* shadowPasses;
    unsigned int unk4c;
    unsigned int unk50;
    P440List* specialPasses;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    bool dirty;
    char unk75;
    short unk76;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    int* materialFlags;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    P440Extra* extra;
    __declspec(noinline) bool FUN_004a2020(int index)
    {
        unsigned int word = (unsigned int)index >> 5;
        unsigned int bit = (unsigned int)index % 32;
        return ((word == 0 ? flags : flags2) & (1u << bit)) > 0;
    }
    void BSShaderProperty_SetFlag(int, bool);
    void EnsureNewObj(int);
    void EnsureBa9740Obj(int);
    void EnsureAllocated(int);
    void CreateSpawnedObjectIfMissing(int);
    void FUN_00ba95e0(int);
    void BSShaderProperty_SetAlpha(float);
    void SortShadowSceneLights(P440Position*);
    P440Light* FUN_00b70590(void**);
    P440Light* BSShaderLightingProperty_GetNextActiveLight(void**);
    P440Light* BSShaderLightingProperty_GetFirstActiveNonShadowLight(void**);
    P440Light* BSShaderLightingProperty_GetNextActiveNonShadowLight(void**);
    P440List* GetPasses(P440Geometry*, unsigned int, int, unsigned int, P440Renderer*, int);
};
extern P440Renderer* DAT_011f4748;
extern float DAT_011f9458, DAT_011f9460, DAT_011f9468, DAT_011f946c;
extern float DAT_011f9470;
extern unsigned char DAT_011f91a7;
P440Renderer* __cdecl BSShaderManager_GetAccumulator();
bool __cdecl IsParticleShaderRendererEnabled();
int __cdecl GetGlobalFloatAsUInt();
bool __cdecl BSShaderManager_GetShadows();
float __cdecl LinearInterpolate(float, float, float, float, float);
// Selects and configures the P440List of render passes for a P440Shader based on mode, geometry, lights, and fade flags, returning the populated pass list.
// @fnv 0x00c058f0
P440List* P440Shader::GetPasses(P440Geometry* geometry, unsigned int key, int unused, unsigned int mode,
                                P440Renderer* renderer, int unused2)
{
    unsigned int uiCacheKey = (mode << 8) | key;
    P440PropertyState* pGeometryProperties = &geometry->properties;
    bool opaque;
    opaque = true;
    bool translucent = false;
    if (mode == 7)
    {
        if (((flags & 0x8000) > 0) || ((flags & 0x10000) > 0))
            return 0;
        EnsureNewObj(1);
        P440List* passList = depthPasses;
        if (passList->count)
        {
            P440Pass* pass = passList->passes[0];
            if (pass->count > 0)
                pass->lights[0] = DAT_011f4748->active->depthLight;
        }
        else
        {
            if (geometry->material->skinned)
            {
                if (!FUN_004a2020(1))
                    passList->FUN_00ba9ee0(geometry, 0x1c9, 1, 1, DAT_011f4748->active->depthLight, 0, 0, 0);
                else
                    passList->FUN_00ba9ee0(geometry, 0x1cb, 1, 1, DAT_011f4748->active->depthLight, 0, 0, 0);
            }
            else
            {
                if (!FUN_004a2020(1))
                    passList->FUN_00ba9ee0(geometry, 0x1c8, 1, 1, DAT_011f4748->active->depthLight, 0, 0, 0);
                else
                    passList->FUN_00ba9ee0(geometry, 0x1ca, 1, 1, DAT_011f4748->active->depthLight, 0, 0, 0);
            }
        }
        return depthPasses;
    }
    if (mode == 8)
    {
        if (((flags & 0x8000) > 0) || ((flags & 0x10000) > 0) || ((flags2 & 0x10) > 0))
            return normalPasses;
        EnsureBa9740Obj(1);
        P440List* passList = normalPasses;
        if (passList->count)
        {
            P440Pass* pass = passList->passes[0];
            if (0 < pass->count)
                pass->lights[0] = DAT_011f4748->active->depthLight;
        }
        else
        {
            bool skin = false;
            if (geometry->material->skinned)
                skin = true;
            if (!FUN_004a2020(1))
            {
                if (skin)
                    passList->FUN_00ba9ee0(geometry, 0x1d4, 1, 1, DAT_011f4748->active->depthLight, 0, 0, 0);
                else
                    passList->FUN_00ba9ee0(geometry, 0x1d3, 1, 1, DAT_011f4748->active->depthLight, 0, 0, 0);
            }
            else
            {
                if (skin)
                    passList->FUN_00ba9ee0(geometry, 0x1d6, 1, 1, DAT_011f4748->active->depthLight, 0, 0, 0);
                else
                    passList->FUN_00ba9ee0(geometry, 0x1d5, 1, 1, DAT_011f4748->active->depthLight, 0, 0, 0);
            }
        }
        return normalPasses;
    }
    if (mode == 9)
    {
        EnsureAllocated(1);
        P440List* passList = shadowPasses;
        if (passList->count == 0)
        {
            if ((flags & 0x100000) > 0)
                passList->FUN_00ba9ee0(geometry, 0x1df, 1, 0, 0, 0, 0, 0);
            else if (!FUN_004a2020(1))
                passList->FUN_00ba9ee0(geometry, 0x1dd, 1, 0, 0, 0, 0, 0);
            else
                passList->FUN_00ba9ee0(geometry, 0x1de, 1, 0, 0, 0, 0, 0);
        }
        return shadowPasses;
    }
    if (mode == 15)
    {
        CreateSpawnedObjectIfMissing(1);
        P440List* passList = specialPasses;
        if (!passList->count && !geometry->unkbc)
        {
            if (FUN_004a2020(0x25))
                passList->FUN_00ba9ee0(geometry, 0x1bc, 1, 0, 0, 0, 0, 0);
            else
                passList->FUN_00ba9ee0(geometry, 0x1bb, 1, 0, 0, 0, 0, 0);
        }
        return specialPasses;
    }
    float previousDistance = distance;
    unsigned long shaderFlags = flags;
    bool fade80 = ((shaderFlags & 0x80) > 0) && DAT_011f9460 > 0.0f;
    bool fade20000 = ((shaderFlags & 0x20000) > 0) && DAT_011f9468 > 0.0f;
    bool fadeFar =
        (((shaderFlags & 0x4000000) > 0) || FUN_004a2020(0x1b) == 1) && DAT_011f9470 > 0.0f && !FUN_004a2020(0x23);
    bool fadeNear = ((shaderFlags & 1) > 0) && DAT_011f9458 > 0.0f;
    if (fade20000 || fade80 || fadeFar || fadeNear)
    {
        P440Vector cameraPosition = renderer->camera->GetPosition();
        P440Position bound = geometry->position ? *geometry->position : *(P440Position*)&DAT_011f4288;
        P440Vector delta;
        delta.x = bound.x - cameraPosition.x;
        delta.y = bound.y - cameraPosition.y;
        delta.z = bound.z - cameraPosition.z;
        distance = delta.FUN_00457990() - bound.r;
        if (BSShaderManager_GetAccumulator()->active)
            distance *= BSShaderManager_GetAccumulator()->active->scale;
        if (distance != previousDistance)
        {
            if (fade20000)
            {
                if ((distance < DAT_011f9468 && DAT_011f9468 <= previousDistance) ||
                    (distance >= DAT_011f9468 && DAT_011f9468 > previousDistance))
                    cacheKey = 0;
            }
            else if (fade80)
            {
                if ((distance < DAT_011f9460 && DAT_011f9460 <= previousDistance) ||
                    (distance >= DAT_011f9460 && DAT_011f9460 > previousDistance))
                    cacheKey = 0;
            }
            if (fadeFar && ((distance < DAT_011f9470 && DAT_011f9470 <= previousDistance) ||
                            (distance >= DAT_011f9470 && DAT_011f9470 > previousDistance)))
                cacheKey = 0;
            if (fadeNear)
            {
                if ((distance < DAT_011f9458 && DAT_011f9458 <= previousDistance) ||
                    (distance >= DAT_011f9458 && DAT_011f9458 > previousDistance))
                    cacheKey = 0;
                if (distance >= DAT_011f9458)
                    fadeNear = true;
            }
        }
    }
    if (pGeometryProperties)
    {
        P440Light* light = pGeometryProperties->fade;
        float value = 1.0f;
        if (light)
        {
            if (fadeFar)
            {
                if (DAT_011f9470 != 0.0f && DAT_011f9470 <= distance)
                    opaque = false;
                else if (DAT_011f946c != 0.0f && DAT_011f9470 != 0.0f && DAT_011f946c <= distance &&
                         distance < DAT_011f9470)
                    value = LinearInterpolate(0.0f, 1.0f, DAT_011f9470, DAT_011f946c, distance);
                else
                    value = light->alpha * opacity;
            }
            else
                value = light->alpha * opacity;
        }
        else
            value = opacity;
        BSShaderProperty_SetAlpha(value);
        if (value < 1.0f)
            translucent = true;
    }
    if (dirty)
    {
        P440Position bound = geometry->position ? *geometry->position : *(P440Position*)&DAT_011f4288;
        SortShadowSceneLights(&bound);
    }
    void* lightIterator;
    if (cacheKey == uiCacheKey && dirty)
    {
        P440Light* defaultLight = BSShaderManager_GetAccumulator()->camera->defaultLight;
        for (unsigned int i = 0; i < passes->count; ++i)
        {
            P440Pass* pass = passes->passes[i];
            if (pass->shader >= 0x17f && pass->shader <= 0x1ba)
            {
                unsigned char lightCount = 1;
                P440Light* light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&lightIterator);
                while (light)
                {
                    lightCount++;
                    light = BSShaderLightingProperty_GetNextActiveNonShadowLight(&lightIterator);
                }
                if (lightCount > 0)
                {
                    if (pass->capacity < lightCount)
                    {
                        pass->BSShaderProperty_RenderPass_ClearSceneLights();
                        pass->AllocateElemArray(lightCount);
                        pass->capacity = lightCount;
                    }
                    light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&lightIterator);
                    pass->lights[0] = defaultLight;
                    int lightIndex = 1;
                    while (light && lightIndex < lightCount)
                    {
                        pass->lights[lightIndex++] = light;
                        light = BSShaderLightingProperty_GetNextActiveNonShadowLight(&lightIterator);
                    }
                    pass->count = (unsigned char)lightIndex;
                }
                else
                    pass->count = 0;
            }
            else if (pass->shader >= 0x1bd && pass->shader <= 0x1c3)
            {
                if (1 == pass->count)
                {
                    void* blendIterator;
                    P440Light* light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&blendIterator);
                    if (light)
                        pass->lights[0] = light;
                    else
                        pass->lights[0] = defaultLight;
                }
            }
            else if (pass->shader >= 0x1c4 && pass->shader <= 0x1c7)
            {
                if (pass->count == 1)
                {
                    void* specialIterator;
                    P440Light* light = FUN_00b70590(&specialIterator);
                    if (!light || !light->special || (light->settings->flags & 1))
                    {
                        cacheKey = 0;
                        break;
                    }
                    pass->lights[0] = light;
                }
            }
        }
        dirty = false;
    }
    if (cacheKey == uiCacheKey)
        return passes;
    FUN_00ba95e0(-1);
    passes->count = 0;
    dirty = false;
    _ReadWriteBarrier();
    bool enabled = !((flags & 0x100000) > 0) || DAT_011f91a7;
    bool specialBlend = opaque && (FUN_004a2020(0x1a) || FUN_004a2020(0x1b));
    if (alpha == 0.0f || !enabled || (fadeFar && !specialBlend))
        return passes;
    bool flag1 = FUN_004a2020(1);
    bool flag7 = FUN_004a2020(7) != 0;
    bool flag17 = FUN_004a2020(0x11);
    bool flag21 = FUN_004a2020(0x15);
    bool flag15 = FUN_004a2020(0xf);
    bool flag16 = FUN_004a2020(0x10);
    bool flag11 = FUN_004a2020(0xb);
    bool flag28 = FUN_004a2020(0x1c);
    bool flag10 = FUN_004a2020(0xa);
    bool material = *materialFlags != 0;
    bool skinned = false;
    bool isNear = FUN_004a2020(0) && (int)(uiCacheKey & 8) > 0 && fadeNear;
    bool hasAlpha = translucent || (geometry->properties.flags->unk18 & 1);
    bool environment = IsParticleShaderRendererEnabled() && !FUN_004a2020(0xd) && GetGlobalFloatAsUInt() &&
                       BSShaderManager_GetAccumulator()->camera->mode != 1 && BSShaderManager_GetAccumulator()->camera->mode != 3;
    if (geometry->material->skinned || FUN_004a2020(0x25))
        skinned = true;
    if (extra)
        environment = false;
    if (flag15)
    {
        if (flag16)
            passes->FUN_00ba9ee0(geometry, 0x1d0, 1, 0, 0, 0, 0, 0);
        else if (!skinned)
            passes->FUN_00ba9ee0(geometry, (flag1 ? 0x1ce : 0x1cc), 1, 0, 0, 0, 0, 0);
        else
            passes->FUN_00ba9ee0(geometry, (flag1 ? 0x1cf : 0x1cd), 1, 0, 0, 0, 0, 0);
        passes->passes[passes->count - 1]->blend = 6;
        goto done;
    }
    if ((flags2 & 0x40) > 0)
    {
        passes->FUN_00ba9ee0(geometry, 0x1d1 + (flag1 ? 1 : 0), 1, 0, 0, 0, 0, 0);
        passes->passes[passes->count - 1]->blend = 7;
    }
    P440Light* defaultLight = BSShaderManager_GetAccumulator()->camera->defaultLight;
    passes->FUN_00ba9ee0(geometry, 0, 1, 0, 0, 0, 0, 0);
    P440Pass* pass = passes->passes[passes->count - 1];
    pass->count = 1;
    P440Light* light = FUN_00b70590(&lightIterator);
    while (light)
    {
        if (!light->special)
            pass->count++;
        light = BSShaderLightingProperty_GetNextActiveLight(&lightIterator);
    }
    if (pass->count > 0)
    {
        if (pass->capacity < pass->count)
        {
            pass->BSShaderProperty_RenderPass_ClearSceneLights();
            pass->AllocateElemArray(pass->count);
            pass->capacity = pass->count;
        }
        light = FUN_00b70590(&lightIterator);
        pass->lights[0] = defaultLight;
        unsigned char lightIndex = 1;
        while (light)
        {
            if (!light->special)
                pass->lights[lightIndex++] = light;
            light = BSShaderLightingProperty_GetNextActiveLight(&lightIterator);
        }
        pass->count = lightIndex;
    }
    else
        pass->lights = 0;
    BSShaderProperty_SetFlag(0x1e, false);
    if (FUN_004a2020(0x12))
    {
        if (isNear)
        {
            if (environment)
                pass->shader = 0x1ae;
            else
                pass->shader = 0x190;
        }
        else
        {
            if (environment)
                pass->shader = 0x19f;
            else
                pass->shader = 0x181;
        }
    }
    else if (isNear)
    {
        if (!flag1)
        {
            if (flag11)
            {
                if (skinned)
                {
                    if (environment)
                    {
                        if (flag28)
                            pass->shader = 0x1b8;
                        else
                            pass->shader = 0x1b7;
                    }
                    else
                    {
                        if (flag28)
                            pass->shader = 0x19a;
                        else
                            pass->shader = 0x199;
                    }
                }
                else
                {
                    if (environment)
                    {
                        if (flag28)
                            pass->shader = 0x1b0;
                        else
                            pass->shader = 0x1af;
                    }
                    else
                    {
                        if (flag28)
                            pass->shader = 0x192;
                        else
                            pass->shader = 0x191;
                    }
                }
            }
            else if (flag10)
            {
                if (environment)
                    pass->shader = 0x1b1;
                else
                    pass->shader = 0x193;
            }
            else if (material)
            {
                if (skinned)
                {
                    if (environment)
                        pass->shader = 0x1b9;
                    else
                        pass->shader = 0x19b;
                }
                else
                {
                    if (environment)
                        pass->shader = 0x1b3;
                    else
                        pass->shader = 0x195;
                }
            }
            else
            {
                if (skinned)
                {
                    if (environment)
                        pass->shader = 0x1b5;
                    else
                        pass->shader = 0x197;
                }
                else
                {
                    if (environment)
                        pass->shader = 0x1ac;
                    else
                        pass->shader = 0x18e;
                }
            }
        }
        else if (!flag11)
        {
            if (flag10)
            {
                if (environment)
                    pass->shader = 0x1b2;
                else
                    pass->shader = 0x194;
            }
            else if (material)
            {
                if (skinned)
                {
                    if (environment)
                        pass->shader = 0x1ba;
                    else
                        pass->shader = 0x19c;
                }
                else
                {
                    if (environment)
                        pass->shader = 0x1b4;
                    else
                        pass->shader = 0x196;
                }
            }
            else
            {
                if (skinned)
                {
                    if (environment)
                        pass->shader = 0x1b6;
                    else
                        pass->shader = 0x198;
                }
                else
                {
                    if (environment)
                        pass->shader = 0x1ad;
                    else
                        pass->shader = 0x18f;
                }
            }
        }
    }
    else
    {
        if (!flag1)
        {
            if (flag11)
            {
                if (skinned)
                {
                    if (environment)
                    {
                        if (flag28)
                            pass->shader = 0x1a9;
                        else
                            pass->shader = 0x1a8;
                    }
                    else
                    {
                        if (flag28)
                            pass->shader = 0x18b;
                        else
                            pass->shader = 0x18a;
                    }
                }
                else
                {
                    if (environment)
                    {
                        if (flag28)
                            pass->shader = 0x1a1;
                        else
                            pass->shader = 0x1a0;
                    }
                    else
                    {
                        if (flag28)
                            pass->shader = 0x183;
                        else
                            pass->shader = 0x182;
                    }
                }
            }
            else if (flag10)
            {
                if (environment)
                    pass->shader = 0x1a2;
                else
                    pass->shader = 0x184;
            }
            else if (material)
            {
                if (skinned)
                {
                    if (environment)
                        pass->shader = 0x1aa;
                    else
                        pass->shader = 0x18c;
                }
                else
                {
                    if (environment)
                        pass->shader = 0x1a4;
                    else
                        pass->shader = 0x186;
                }
            }
            else
            {
                if (skinned)
                {
                    if (environment)
                        pass->shader = 0x1a6;
                    else
                        pass->shader = 0x188;
                }
                else
                {
                    if (environment)
                        pass->shader = 0x19d;
                    else
                        pass->shader = 0x17f;
                }
            }
        }
        else if (!flag11)
        {
            if (flag10)
            {
                if (environment)
                    pass->shader = 0x1a3;
                else
                    pass->shader = 0x185;
            }
            else if (material)
            {
                if (skinned)
                {
                    if (environment)
                        pass->shader = 0x1ab;
                    else
                        pass->shader = 0x18d;
                }
                else
                {
                    if (environment)
                        pass->shader = 0x1a5;
                    else
                        pass->shader = 0x187;
                }
            }
            else
            {
                if (skinned)
                {
                    if (environment)
                        pass->shader = 0x1a7;
                    else
                        pass->shader = 0x189;
                }
                else
                {
                    if (environment)
                        pass->shader = 0x19e;
                    else
                        pass->shader = 0x180;
                }
            }
        }
    }
    if (FUN_004a2020(0x1a))
        pass->blend = FUN_004a2020(0x35) ? 1 : 4;
    else if (FUN_004a2020(0x1b))
        pass->blend = FUN_004a2020(0x35) ? 1 : 5;
    else if (hasAlpha)
        pass->blend = opacity < 1.0f ? 14 : 1;
    else if (renderer->mode == 2 || FUN_004a2020(0x22) || FUN_004a2020(0x21))
        pass->blend = 10;
    if (BSShaderManager_GetShadows())
    {
        light = FUN_00b70590(&lightIterator);
        while (light)
        {
            if (light->special)
            {
                passes->FUN_00ba9ee0(geometry, 0, 0, 1, light, 0, 0, 0);
                pass = passes->passes[passes->count - 1];
                if (skinned)
                    pass->shader = (flag1 ? 0x1c7 : 0x1c5);
                else
                    pass->shader = (flag1 ? 0x1c6 : 0x1c4);
                if (FUN_004a2020(0x1a))
                    pass->blend = FUN_004a2020(0x35) ? 1 : 4;
                else if (FUN_004a2020(0x1b))
                    pass->blend = FUN_004a2020(0x35) ? 1 : 5;
            }
            light = BSShaderLightingProperty_GetNextActiveLight(&lightIterator);
        }
    }
    if (extra && extra->enabled)
    {
        passes->FUN_00ba9ee0(geometry, 14 + (flag1 ? 1 : 0), 1, 0, 0, 0, 0, 0);
        passes->passes[passes->count - 1]->blend = 14;
    }
    else if (FUN_004a2020(9) || opacity < 1.0f)
    {
        if (!geometry->properties.flags || !(geometry->properties.flags->unk18 & 1))
        {
            if (skinned)
                passes->FUN_00ba9ee0(geometry, 12 + (flag1 ? 1 : 0), 1, 0, 0, 0, 0, 0);
            else
                passes->FUN_00ba9ee0(geometry, 10 + (flag1 ? 1 : 0), 1, 0, 0, 0, 0, 0);
            pass = passes->passes[passes->count - 1];
            pass->blend = FUN_004a2020(9) ? 1 : 14;
            if (opacity < 1.0f || alpha < 1.0f)
                pass->blend = 14;
        }
    }
    if (extra)
    {
        passes->FUN_00ba9ee0(geometry, 0x1e0 + (flag1 ? 1 : 0), 1, 0, 0, 0, 0, 0);
        passes->passes[passes->count - 1]->blend = 1;
    }
    if (flag7)
    {
        unsigned long shaderID;
        if (flag21)
            shaderID = (skinned ? 0x1c0 : 0x1be);
        else if (!flag17)
        {
            if (flag1)
                shaderID = 0x1c1 + (skinned ? 1 : 0);
            else
                shaderID = (skinned ? 0x1bf : 0x1bd);
        }
        if (!flag21 && flag17)
        {
            light = FUN_00b70590(&lightIterator);
            if (light)
            {
                passes->FUN_00ba9ee0(geometry, 0, 0, 1, light, 0, 0, 0);
                pass = passes->passes[passes->count - 1];
            }
            else
            {
                passes->FUN_00ba9ee0(geometry, 0, 0, 1, defaultLight, 0, 0, 0);
                pass = passes->passes[passes->count - 1];
            }
            pass->shader = 0x1c3;
        }
        else
        {
            passes->FUN_00ba9ee0(geometry, 0, 0, 0, 0, 0, 0, 0);
            pass = passes->passes[passes->count - 1];
            pass->shader = shaderID;
        }
        if (hasAlpha)
            pass->blend = 1;
    }
done:
    cacheKey = uiCacheKey;
    return passes;
}

struct FUN_00c02c30_Obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3A();
    virtual unsigned short v3B();
    char p04[0xc4 - 4];
    unsigned char* m_c4;
};

extern unsigned int DAT_011a9bd0;
extern unsigned int DAT_011a9bd4;
extern unsigned int DAT_011a9bd8;
extern unsigned int DAT_011a9bdc;
extern unsigned int DAT_011fa2d0;
extern unsigned int DAT_011fa2d4;
extern unsigned int DAT_011fa2d8;
extern unsigned int DAT_011fa2dc;

struct S00c02c30_ColorA
{
    float r, g, b, a;
};

// @fnv 0x00c02c30
// src: COMMUNITY 0x00c02c30
void __stdcall ShadowLightShader_UpdateTogglesConstantLand(unsigned int uiUnused, int param_2, FUN_00c02c30_Obj* apObj, int iIndex)
{
    S00c02c30_ColorA kColor = *reinterpret_cast<S00c02c30_ColorA*>(&DAT_011a9bd0);
    kColor.r = 1.0f;
    if (param_2 != 0)
        kColor.g = 1.0f;
    kColor.b = (float)apObj->m_c4[iIndex];
    kColor.a = (float)(apObj->v3B() + 1.0);
    *reinterpret_cast<S00c02c30_ColorA*>(&DAT_011fa2d0) = kColor;
}

// Returns a2->v3D(4, a3), or DAT_011f95d4 when that is zero.
// @fnv 0x00c02f30
// src: COMMUNITY 0x00c02f30
int __stdcall ShadowLightShader_GetCubeMap(FNV_Node* apNode, int a3)
{
    int flag194 = Callee1()->m_194;
    int tex = apNode->v3D(4, a3);
    if (!tex)
    {
        if (DAT_011f9427 && (apNode->m_flags20 & 0x200000))
        {
            tex = DAT_011f95d4;
        }
        else if (flag194)
        {
            tex = DAT_011f95d4;
        }
        if (!tex)
            tex = DAT_011f95d4;
    }
    return tex;
}

struct S00c03c80_entry;
struct S00c03c80_item
{
    virtual void v00() = 0;
    virtual void v04() = 0;
    virtual void v08() = 0;
    virtual void v0c() = 0;
    virtual void v10() = 0;
    virtual void v14() = 0;
    virtual void v18() = 0;
    virtual void v1c() = 0;
    virtual void v20() = 0;
    virtual void v24() = 0;
    virtual void v28() = 0;
    virtual void v2c() = 0;
    virtual void v30() = 0;
    virtual void v34() = 0;
    virtual void v38() = 0;
    virtual void v3c() = 0;
    virtual void v40() = 0;
    virtual void v44() = 0;
    virtual void v48() = 0;
    virtual void v4c() = 0;
    virtual void v50() = 0;
    virtual void v54() = 0;
    virtual void v58() = 0;
    virtual void v5c() = 0;
    virtual void v60() = 0;
    virtual void v64() = 0;
    virtual void v68() = 0;
    virtual void v6c() = 0;
    virtual void v70() = 0;
    virtual void v74() = 0;
    virtual void v78() = 0;
    virtual void v7c() = 0;
    virtual void v80() = 0;
    virtual void v84() = 0;
    virtual void v88() = 0;
    virtual void v8c() = 0;
    virtual void v90() = 0;
    virtual int Get94();
    virtual int Get98();
};
struct S00c03c80_entry
{
    S00c03c80_item* __thiscall ImageSpaceTexture_GetTexture();
};
struct S00c03c80_meta
{
    int unk00;
    int unk04;
    int value08;
    void* value0c;
};
struct S00c03c80_provider
{
    virtual void v00() = 0;
    virtual void v04() = 0;
    virtual void v08() = 0;
    virtual void v0c() = 0;
    virtual void v10() = 0;
    virtual void v14() = 0;
    virtual void v18() = 0;
    virtual void v1c() = 0;
    virtual void v20() = 0;
    virtual void v24() = 0;
    virtual void v28() = 0;
    virtual void v2c() = 0;
    virtual void v30() = 0;
    virtual void v34() = 0;
    virtual void v38() = 0;
    virtual void v3c() = 0;
    virtual void v40() = 0;
    virtual void v44() = 0;
    virtual void v48() = 0;
    virtual void v4c() = 0;
    virtual void v50() = 0;
    virtual void v54() = 0;
    virtual void v58() = 0;
    virtual void v5c() = 0;
    virtual void v60() = 0;
    virtual void v64() = 0;
    virtual void v68() = 0;
    virtual void v6c() = 0;
    virtual void v70() = 0;
    virtual void v74() = 0;
    virtual void v78() = 0;
    virtual void v7c() = 0;
    virtual void v80() = 0;
    virtual void v84() = 0;
    virtual void v88() = 0;
    virtual void v8c() = 0;
    virtual void v90() = 0;
    virtual void v94() = 0;
    virtual void v98() = 0;
    virtual void v9c() = 0;
    virtual void va0() = 0;
    virtual void va4() = 0;
    virtual void va8() = 0;
    virtual void vac() = 0;
    virtual S00c03c80_meta* GetMeta(int);
};
struct S00c03c80_manager
{
    virtual void v00() = 0;
    virtual void v04() = 0;
    virtual void v08() = 0;
    virtual void v0c() = 0;
    virtual void v10() = 0;
    virtual void v14() = 0;
    virtual void v18() = 0;
    virtual void v1c() = 0;
    virtual void v20() = 0;
    virtual void v24() = 0;
    virtual void v28() = 0;
    virtual void v2c() = 0;
    virtual void v30() = 0;
    virtual void v34() = 0;
    virtual void v38() = 0;
    virtual void v3c() = 0;
    virtual void v40() = 0;
    virtual void v44() = 0;
    virtual void v48() = 0;
    virtual void v4c() = 0;
    virtual void v50() = 0;
    virtual void v54() = 0;
    virtual void v58() = 0;
    virtual void v5c() = 0;
    virtual void v60() = 0;
    virtual void v64() = 0;
    virtual void v68() = 0;
    virtual void v6c() = 0;
    virtual void v70() = 0;
    virtual void v74() = 0;
    virtual void v78() = 0;
    virtual void v7c() = 0;
    virtual void v80() = 0;
    virtual void v84() = 0;
    virtual void v88() = 0;
    virtual void v8c() = 0;
    virtual void v90() = 0;
    virtual void v94() = 0;
    virtual void v98() = 0;
    virtual void v9c() = 0;
    virtual void va0() = 0;
    virtual void va4() = 0;
    virtual void va8() = 0;
    virtual void vac() = 0;
    virtual void vb0() = 0;
    virtual void vb4() = 0;
    virtual void vb8() = 0;
    virtual void vbc() = 0;
    virtual void vc0() = 0;
    virtual void vc4() = 0;
    virtual S00c03c80_provider* GetProvider();
};
extern S00c03c80_manager* _DAT_011f4748;
struct S00c03c80_processor
{
    void __thiscall ImageSpaceShaderParam_SetTextureOffsets(unsigned int, int, void*);
};
struct S00c03c80_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
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
    int unk8c;
    int unk90;
    int unk94;
    S00c03c80_entry** m_entries;
    unsigned short unk9c;
    unsigned short m_uiItemCount;
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
    S00c03c80_processor* m_processor;
    void __thiscall ProcessEntries();
};
// Iterates m_entries, calling m_processor->FUN_00b8a6e0 with item data or provider meta values for each index.
// @fnv 0x00c03c80
void S00c03c80_cls::ProcessEntries()
{
    for (unsigned int i = 0; i < m_uiItemCount; ++i)
    {
        S00c03c80_item* item;
        if (m_entries[i] != 0 && (item = m_entries[i]->ImageSpaceTexture_GetTexture()) != 0)
        {
            if (m_processor != 0)
                m_processor->ImageSpaceShaderParam_SetTextureOffsets(i, item->Get94(), (void*)item->Get98());
        }
        else
        {
            if (m_processor != 0)
            {
                void* meta;
                S00c03c80_provider* provider = _DAT_011f4748->GetProvider();
                if (provider == 0)
                {
                    meta = 0;
                }
                else
                {
                    S00c03c80_meta* m = provider->GetMeta(0);
                    if (m == 0)
                        meta = 0;
                    else
                        meta = m->value0c;
                }
                S00c03c80_provider* provider2 = _DAT_011f4748->GetProvider();
                int second;
                if (provider2 == 0)
                {
                    second = 0;
                }
                else
                {
                    S00c03c80_meta* m2 = provider2->GetMeta(0);
                    if (m2 == 0)
                        second = 0;
                    else
                        second = m2->value08;
                }
                m_processor->ImageSpaceShaderParam_SetTextureOffsets(i, second, meta);
            }
        }
    }
}

struct S00c04f50_V4
{
    float x;
    float y;
    float z;
    float w;
};

struct S00c04f50_P3
{
    float x;
    float y;
    float z;

    S00c04f50_P3& operator=(const S00c04f50_P3& o)
    {
        x = o.x;
        y = o.y;
        z = o.z;
        return *this;
    }
};

struct S00c04f50_Src
{
    S00c04f50_P3 pos;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
};

struct S00c04f50_I4
{
    int x;
    int y;
    int z;
    int w;
};

struct S00c04f50_Tmp
{
    float f00;
    float f04;
    float f08;
    float f0c;
    float f10;
    float f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    float f28;
    float f2c;
    float f30;
    float f34;
};

struct S00c04f50_Mat
{
    S00c04f50_P3 m00;
    float m03;
    float m10;
    float m11;
    float m12;
    float m13;
    float m20;
    float m21;
    float m22;
    float m23;
    float m30;
    float m31;
    float m32;
    float m33;
};

template <class T> inline T S00c04f50_Max(T a, T b)
{
    return (a > b) ? a : b;
}

struct S00c04f50_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
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
    bool m_58;
    char unk59;
    char unk5a;
    char unk5b;
    S00c04f50_V4* m_5c;
    S00c04f50_Src* m_60;
    int unk64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    S00c04f50_Mat m_88;

    S00c04f50_Mat& ImageSpaceEffectCinematic_Func_08();
};

// Fills m_88 with the m_60 source's position, a far value and three 4-component rows, using m_5c for some values when m_58 is set, and returns m_88.
// @fnv 0x00c04f50
// src: COMMUNITY 0x00c04f50
S00c04f50_Mat& S00c04f50_cls::ImageSpaceEffectCinematic_Func_08()
{
    float fFar;
    S00c04f50_V4 r1;
    S00c04f50_I4 r2;
    S00c04f50_V4 r3;
    r2.x = m_68;
    r2.y = m_6c;
    r2.z = m_70;
    r2.w = m_74;
    S00c04f50_Src* src = m_60;
    if (m_58)
    {
        S00c04f50_V4* p = m_5c;
        float a = p->w;
        float b = src->unk0c;
        fFar = S00c04f50_Max(a, b);
        r1.x = p->x;
        r1.y = p->y;
        r1.z = p->z;
        r1.w = 1.0f;
        *(float*)&r2.z = 1.0f;
        *(float*)&r2.w = 1.0f;
    }
    else
    {
        fFar = src->unk0c;
        r1.x = src->unk10;
        r1.y = src->unk14;
        r1.z = src->unk18;
        r1.w = src->unk1c;
    }
    r3.x = src->unk20;
    r3.y = src->unk24;
    r3.z = src->unk28;
    r3.w = src->unk2c;
    m_88.m00.x = src->pos.x;
    m_88.m00.y = src->pos.y;
    m_88.m00.z = src->pos.z;
    m_88.m03 = fFar;
    m_88.m10 = r1.x;
    m_88.m11 = r1.y;
    m_88.m12 = r1.z;
    m_88.m13 = r1.w;
    m_88.m20 = *(const float*)&r2.x;
    m_88.m21 = *(const float*)&r2.y;
    m_88.m22 = *(const float*)&r2.z;
    m_88.m23 = *(const float*)&r2.w;
    m_88.m30 = r3.x;
    m_88.m31 = r3.y;
    m_88.m32 = r3.z;
    m_88.m33 = r3.w;
    return m_88;
}

struct EffectBaseX
{
    int m_04;
    int m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
    int m_30, m_34, m_38, m_3c, m_40, m_44, m_48, m_4c, m_50, m_54;
    virtual void vBase();
    EffectBaseX();
};

struct ZeroFour
{
    float m_kPointA, m_kPointB, m_iThirdValue, m_iFourthElementInteger;
    __forceinline ZeroFour() : m_kPointA(0.0f), m_kPointB(0.0f), m_iThirdValue(0.0f), m_iFourthElementInteger(0.0f)
    {}
};

struct FUN_00c05680 : EffectBaseX
{
    ZeroFour m_zero;
    FUN_00c05680();
};

void EffectBaseX::vBase()
{}

// Constructs a FUN_00c05680 object by initializing its m_zero member to zero.
// @fnv 0x00c05680
FUN_00c05680::FUN_00c05680() : m_zero()
{}

namespace ShaderSelection {
struct Binding
{
    void FUN_00a5f860(void*);
};
extern void* DAT_01200ec0;
extern void* DAT_01200ec4;
extern void* DAT_01200ec8;
extern void* DAT_01200ecc;
extern void* DAT_01200ed0;
extern void* DAT_01200ed4;
extern void* DAT_01200ed8;
extern void* DAT_01200edc;
extern void* DAT_01200ee0;
extern void* DAT_01200ee4;
extern void* DAT_01200ee8;
extern void* DAT_01200eec;
extern void* DAT_01200ef0;
extern void* DAT_01200ef4;
extern void* DAT_01200ef8;
extern void* DAT_01200efc;
extern void* DAT_01200f00;
extern void* DAT_01200f04;
extern void* DAT_01200f08;
extern void* DAT_01200f0c;
extern void* DAT_01200f10;
extern void* DAT_01200f14;
extern void* DAT_01200f18;
extern void* DAT_01200f1c;
extern void* DAT_01200f20;
extern void* DAT_01200f24;
extern void* DAT_01200f28;
extern void* DAT_01200f2c;
extern void* DAT_01200f30;
extern void* DAT_01200f34;
extern void* DAT_01200f38;
extern void* DAT_01200f3c;
extern void* DAT_01200f40;
extern void* DAT_01200f44;
extern void* DAT_01200f48;
extern void* DAT_01200f4c;
extern void* DAT_01200f50;
extern void* DAT_01200f54;
extern void* DAT_01200f58;
extern void* DAT_01200f5c;
extern void* DAT_01200f60;
extern void* DAT_01200f64;
extern void* DAT_01200f68;
extern void* DAT_01200f6c;
extern void* DAT_01200f70;
extern void* DAT_01200f74;
extern void* DAT_01200f78;
extern void* DAT_01200f7c;
extern void* DAT_01200f80;
extern void* DAT_01200f84;
extern void* DAT_01200f88;
extern void* DAT_01200f8c;
extern void* DAT_01200f90;
extern void* DAT_01200f94;
extern void* DAT_01200f98;
extern void* DAT_01200f9c;
extern void* DAT_01200fa0;
extern void* DAT_01200fa4;
extern void* DAT_01200fa8;
extern void* DAT_01200fac;
extern void* DAT_01200fb0;
extern void* DAT_01200fb4;
extern void* DAT_01200fb8;
extern void* DAT_01200fbc;
extern void* DAT_01200fc0;
extern void* DAT_01200fc4;
extern void* DAT_01200fc8;
extern void* DAT_01200fcc;
extern void* DAT_01200fd0;
extern void* DAT_01200fd4;
extern void* DAT_01200fd8;
extern void* DAT_01200fdc;
extern void* DAT_01200fe0;
extern void* DAT_01200fe4;
extern void* DAT_01200fe8;
extern void* DAT_01200fec;
extern void* DAT_01200ff0;
extern void* DAT_01200ff4;
extern void* DAT_01200ff8;
extern void* DAT_01200ffc;
extern void* DAT_01201000;
extern void* DAT_01201004;
extern void* DAT_01201008;
extern void* DAT_0120100c;
extern void* DAT_01201010;
extern void* DAT_01201014;
extern void* DAT_01201018;
extern void* DAT_0120101c;
extern void* DAT_01201020;
extern void* DAT_01201024;
extern void* DAT_01201028;
extern void* DAT_0120102c;
extern void* DAT_01201030;
extern void* DAT_01201034;
extern void* DAT_01201038;
extern void* DAT_0120103c;
extern void* DAT_01201040;
extern void* DAT_01201044;
extern void* DAT_01201048;
extern void* DAT_0120104c;
extern void* DAT_01201050;
extern void* DAT_01201054;
extern void* DAT_01201058;
extern void* DAT_0120105c;
extern void* DAT_01201060;
extern void* DAT_01201064;
extern void* DAT_01201068;
extern void* DAT_0120106c;
extern void* DAT_01201070;
extern void* DAT_01201074;
extern void* DAT_01201078;
extern void* DAT_0120107c;
struct Shader
{
    void* field0;
    void* field4;
    void* field8;
    void* fieldc;
    void* field10;
    void* field14;
    void* field18;
    void* field1c;
    void* field20;
    void* field24;
    Binding binding;
    void* field2c;
    void* field30;
    void* field34;
    void* field38;
    void* field3c;
    void* field40;
    void* field44;
    void* field48;
    void* field4c;
    void* field50;
    void* field54;
    void* field58;
    void* field5c;
    void* field60;
    void* field64;
    void* field68;
    void* field6c;
    void* field70;
    void* field74;
    void* field78;
    void* field7c;
    void* field80;
    void* field84;
    void* field88;
    void* field8c;
    void* field90;
    void* field94;
    void* Lighting30Shader_SelectPass(unsigned int);
};
// Selects a DAT_01200xxx value and a Shader field by pass index, calls binding.FUN_00a5f860 on that field, and returns the DAT value.
// @fnv 0x00c0abd0
// src: COMMUNITY 0x00c0abd0
void* Shader::Lighting30Shader_SelectPass(unsigned int pass)
{
    void* result = 0;
    switch (pass)
    {
    case 10:
        result = DAT_01200ec4;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 11:
        result = DAT_01200ec8;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 12:
        result = DAT_01200ecc;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 13:
        result = DAT_01200ed0;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 14:
        result = DAT_01200ed4;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 15:
        result = DAT_01200ed8;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 376:
        result = DAT_01200ec0;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 383:
        result = DAT_01200edc;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 384:
        result = DAT_01200ee0;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 385:
        result = DAT_01200ee4;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 386:
        result = DAT_01200ee8;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 387:
        result = DAT_01200eec;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 388:
        result = DAT_01200ef0;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 389:
        result = DAT_01200ef4;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 390:
        result = DAT_01200ef8;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 391:
        result = DAT_01200efc;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 392:
        result = DAT_01200f00;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 393:
        result = DAT_01200f04;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 394:
        result = DAT_01200f08;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 395:
        result = DAT_01200f0c;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 396:
        result = DAT_01200f10;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 397:
        result = DAT_01200f14;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 398:
        result = DAT_01200f18;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 399:
        result = DAT_01200f1c;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 400:
        result = DAT_01200f20;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 401:
        result = DAT_01200f24;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 402:
        result = DAT_01200f28;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 403:
        result = DAT_01200f2c;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 404:
        result = DAT_01200f30;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 405:
        result = DAT_01200f34;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 406:
        result = DAT_01200f38;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 407:
        result = DAT_01200f3c;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 408:
        result = DAT_01200f40;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 409:
        result = DAT_01200f44;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 410:
        result = DAT_01200f48;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 411:
        result = DAT_01200f4c;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 412:
        result = DAT_01200f50;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 413:
        result = DAT_01200f54;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 414:
        result = DAT_01200f58;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 415:
        result = DAT_01200f5c;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 416:
        result = DAT_01200f60;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 417:
        result = DAT_01200f64;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 418:
        result = DAT_01200f68;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 419:
        result = DAT_01200f6c;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 420:
        result = DAT_01200f70;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 421:
        result = DAT_01200f74;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 422:
        result = DAT_01200f78;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 423:
        result = DAT_01200f7c;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 424:
        result = DAT_01200f80;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 425:
        result = DAT_01200f84;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 426:
        result = DAT_01200f88;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 427:
        result = DAT_01200f8c;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 428:
        result = DAT_01200f90;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 429:
        result = DAT_01200f94;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 430:
        result = DAT_01200f98;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 431:
        result = DAT_01200f9c;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 432:
        result = DAT_01200fa0;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 433:
        result = DAT_01200fa4;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 434:
        result = DAT_01200fa8;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 435:
        result = DAT_01200fac;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 436:
        result = DAT_01200fb0;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 437:
        result = DAT_01200fb4;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 438:
        result = DAT_01200fb8;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 439:
        result = DAT_01200fbc;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 440:
        result = DAT_01200fc0;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 441:
        result = DAT_01200fc4;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 442:
        result = DAT_01200fc8;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 445:
        result = DAT_01200fd4;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 446:
        result = DAT_01200fd8;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 447:
        result = DAT_01200fdc;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 448:
        result = DAT_01200fe0;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 449:
        result = DAT_01200fe4;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 450:
        result = DAT_01200fe8;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 451:
        result = DAT_01200fec;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 730:
        result = DAT_01201060;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 731:
        result = DAT_01201064;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 736:
        result = DAT_01201068;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 737:
        result = DAT_0120106c;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 742:
        result = DAT_01201070;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 743:
        result = DAT_01201074;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 748:
        result = DAT_01201078;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 749:
        result = DAT_0120107c;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 452:
        result = DAT_01200ff0;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 453:
        result = DAT_01200ff4;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 454:
        result = DAT_01200ff8;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 455:
        result = DAT_01200ffc;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 480:
        result = DAT_01201058;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 481:
        result = DAT_0120105c;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 456:
        binding.FUN_00a5f860(field7c);
        result = DAT_01201000;
        goto finished;
    case 457:
        binding.FUN_00a5f860(field84);
        result = DAT_01201004;
        goto finished;
    case 458:
        result = DAT_01201008;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 459:
        result = DAT_0120100c;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 460:
        binding.FUN_00a5f860(field7c);
        result = DAT_01201010;
        goto finished;
    case 461:
        binding.FUN_00a5f860(field84);
        result = DAT_01201010;
        goto finished;
    case 462:
        result = DAT_01201014;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 463:
        result = DAT_01201014;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 464:
        binding.FUN_00a5f860(field7c);
        result = DAT_01201018;
        goto finished;
    case 465:
        binding.FUN_00a5f860(field7c);
        result = DAT_0120101c;
        goto finished;
    case 466:
        result = DAT_01201020;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 443:
        result = DAT_01200fcc;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 444:
        result = DAT_01200fd0;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 467:
        result = DAT_01201024;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 468:
        result = DAT_01201028;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 469:
        result = DAT_0120102c;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 470:
        result = DAT_01201030;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 471:
        binding.FUN_00a5f860(field7c);
        result = DAT_01201034;
        goto finished;
    case 472:
        binding.FUN_00a5f860(field84);
        result = DAT_01201038;
        goto finished;
    case 473:
        result = DAT_0120103c;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 474:
        result = DAT_01201040;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 475:
        result = DAT_01201044;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 476:
        result = DAT_01201048;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 477:
        binding.FUN_00a5f860(field7c);
        result = DAT_0120104c;
        goto finished;
    case 478:
        result = DAT_01201050;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 479:
        binding.FUN_00a5f860(field7c);
        result = DAT_01201054;
        goto finished;
    }
finished:
    return result;
}
}


struct TextureReceiver
{
    TextureReceiver* BSRenderedTexture_GetTexture(int code);
};
struct C0CD80Pass
{
    unsigned int NiD3DTextureStage_SetFilterMode(unsigned int code);
    unsigned int ApplyPairToState(unsigned int code);
};
struct C0CD80Rdr
{
    unsigned short FUN_00b704b0();
};
struct C0CD80Item
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    int unkE0, unkE4, unkE8;
    unsigned char unkEC;
    int unkF0, unkF4, unkF8, unkFC, unk100, unk104, unk108;
    TextureReceiver* m_gen;
};
struct C0CD80Mgr
{
    unsigned char unk00, unk01, unk02, unk03, unk04, unk05, unk06, unk07, unk08, unk09;
    C0CD80Item** m_kNode;
};
extern unsigned int DAT_011f91b0;
extern long DAT_01201c7c;
struct C0CD80Shader
{
    void Lighting30Shader_SetTextureMode(ShaderEntry* entry, ShaderInterface* iface);
    void Lighting30Shader_UpdateDiffuseNormalStages(unsigned int technique, Renderer* renderer);
};

// For certain technique values, stores the renderer's primary and secondary objects, and a tertiary one from a manager item, into the global shader's passes.
// @fnv 0x00c0cd80
// src: COMMUNITY 0x00c0cd80
void C0CD80Shader::Lighting30Shader_UpdateDiffuseNormalStages(unsigned int technique, Renderer* renderer)
{
    GlobalShader* g = (GlobalShader*)DAT_0126f74c;

    if (technique < 0x1BD || technique > 0x1E1 || (technique >= 0x1C4 && technique <= 0x1C7) ||
        (technique - 0x1C8) <= 3)
    {
        if (!(technique >= 0x2D8 && technique <= 0x2EF))
        {
            DecompPass266* primary = g->m_passes->m_primary;
            primary->m_resource = renderer->m_primary->m_object;
            Lighting30Shader_SetTextureMode((ShaderEntry*)primary, (ShaderInterface*)renderer);

            DecompPass266* secondary = g->m_passes->m_secondary;
            if (secondary)
            {
                void* tex = renderer->m_secondary->m_object;
                if (!tex)
                    tex = (void*)DAT_011f9510;
                secondary->m_resource = tex;
                Lighting30Shader_SetTextureMode((ShaderEntry*)secondary, (ShaderInterface*)renderer);
            }

            if ((DAT_011f91e4 - 0x1C4) <= 3 && ((C0CD80Rdr*)renderer)->FUN_00b704b0() > 0)
            {
                C0CD80Mgr* mgr = (C0CD80Mgr*)DAT_011f91e0;
                C0CD80Item* item = *mgr->m_kNode;
                if (item->unkEC && item->m_gen && mgr->unk09 > 0)
                {
                    DecompPass266* tertiary = g->m_passes->m_tertiary;
                    tertiary->m_resource = item->m_gen->BSRenderedTexture_GetTexture(0);
                    if (DAT_011f91b0 == 3)
                        ((C0CD80Pass*)tertiary)->NiD3DTextureStage_SetFilterMode(1);
                    else
                        ((C0CD80Pass*)tertiary)->NiD3DTextureStage_SetFilterMode(0);
                    ((C0CD80Pass*)tertiary)->ApplyPairToState(0);
                    bool lit = ((BSShaderPPLightingProperty*)renderer)->FUN_004a2020(8);
                    lit = lit != 0;
                    *(float*)&DAT_01201c7c = (float)lit;
                }
            }
        }
    }

    if (technique == 0x2E0 || technique == 0x2E1 || technique == 0x2EC || technique == 0x2ED)
    {
        DecompPass266* primary = g->m_passes->m_primary;
        primary->m_resource = renderer->m_primary->m_object;
        Lighting30Shader_SetTextureMode((ShaderEntry*)primary, (ShaderInterface*)renderer);
    }

    if ((technique - 0x1D3) <= 3)
    {
        DecompPass266* primary = g->m_passes->m_primary;
        primary->m_resource = renderer->m_primary->m_object;
        Lighting30Shader_SetTextureMode((ShaderEntry*)primary, (ShaderInterface*)renderer);
    }
}

struct SplatterItem
{
    int unk00;
    int unk04;
};

struct SplatterGeom
{
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8;
    SplatterItem* unkAC;
    SplatterItem* unkB0;
    int* unkB4;
};

struct BloodUpdater : ShaderUpdater
{
    void SetupTextureStages(SplatterGeom* geom, ShaderEntryTable* table);
    void ApplyTextureStages(SplatterGeom* geom, ShaderEntryTable* table);
    void Lighting30Shader_SetProjShadowMaps(ShaderEntryTable* table);
    void CopyOwnerValuesToItems(ShaderEntryTable* table, SplatterGeom* geom, int flag);
    void SetNodeResultValue(ShaderEntryTable* table, SplatterGeom* geom, int kind);
    void ApplyTextureStage(ShaderEntryTable* table, SplatterGeom* geom, int zero);
    void SetDstValueFromB(ShaderEntryTable* table, SplatterGeom* geom);
    void Lighting30Shader_SetHairMaps(ShaderEntryTable* table, SplatterGeom* geom);
    void SetupPassTextureStage(ShaderEntryTable* table, SplatterGeom* geom);
    void Lighting30Shader_UpdatePassTextureStages(unsigned int kind, SplatterGeom* geom);
};

// Dispatches on kind to update shader entry table values from geom, calling helper methods like SetupTextureStages or SetNodeResultValue.
// @fnv 0x00c0cf10
// src: COMMUNITY 0x00c0cf10
void BloodUpdater::Lighting30Shader_UpdatePassTextureStages(unsigned int kind, SplatterGeom* geom)
{
    ShaderEntryTable* table = (ShaderEntryTable*)DAT_0126f74c;
    switch (kind)
    {
    case 0xe:
    case 0xf:
        SetupTextureStages(geom, table);
        break;
    case 0x181:
        table->entries[4]->value = (void*)DAT_011f9530;
        table->entries[5]->value = (void*)(*geom->unkB4);
        break;
    case 0x182:
    case 0x183:
    case 0x18A:
    case 0x18B:
    case 0x191:
    case 0x192:
    case 0x199:
    case 0x19A:
        UpdateShaderEntry(table, (ShaderInterface*)geom, 4);
        break;
    case 0x186:
    case 0x187:
    case 0x18C:
    case 0x18D:
    case 0x195:
    case 0x196:
    case 0x19B:
    case 0x19C:
        table->entries[6]->value = (void*)(*geom->unkB4);
        break;
    case 0x1A0:
    case 0x1A1:
    case 0x1A8:
    case 0x1A9:
    case 0x1AF:
    case 0x1B0:
    case 0x1B7:
    case 0x1B8:
        Lighting30Shader_SetProjShadowMaps(table);
        UpdateShaderEntry(table, (ShaderInterface*)geom, 4);
        break;
    case 0x1A4:
    case 0x1A5:
    case 0x1AA:
    case 0x1AB:
    case 0x1B3:
    case 0x1B4:
    case 0x1B9:
    case 0x1BA:
        table->entries[6]->value = (void*)(*geom->unkB4);
        Lighting30Shader_SetProjShadowMaps(table);
        break;
    case 0x18E:
    case 0x18F:
    case 0x197:
    case 0x198:
        return;
    case 0x190:
        Lighting30Shader_SetHairMaps(table, geom);
        break;
    case 0x19D:
    case 0x19E:
    case 0x1A6:
    case 0x1A7:
    case 0x1AC:
    case 0x1AD:
    case 0x1B5:
    case 0x1B6:
        Lighting30Shader_SetProjShadowMaps(table);
        break;
    case 0x19F:
        Lighting30Shader_SetHairMaps(table, geom);
        Lighting30Shader_SetProjShadowMaps(table);
        break;
    case 0x1AE:
        Lighting30Shader_SetHairMaps(table, geom);
        Lighting30Shader_SetProjShadowMaps(table);
        break;
    case 0x1A2:
    case 0x1B1:
        Lighting30Shader_SetProjShadowMaps(table);
        // ponytail: share the texture tail by natural fallthrough.
    case 0x184:
    case 0x193:
        table->entries[4]->value = (void*)geom->unkAC->unk04;
        table->entries[5]->value = (void*)geom->unkB0->unk04;
        break;
    case 0x1A3:
    case 0x1B2:
        Lighting30Shader_SetProjShadowMaps(table);
        // ponytail: share the flag-helper tail by natural fallthrough.
    case 0x185:
    case 0x194:
        CopyOwnerValuesToItems(table, geom, 1);
        break;
    case 0x1BD:
    case 0x1BE:
    case 0x1BF:
    case 0x1C0:
    case 0x1C1:
    case 0x1C2:
    case 0x1C3:
        SetNodeResultValue(table, geom, kind);
        SetupPassTextureStage(table, geom);
        ApplyTextureStage(table, geom, 0);
        break;
    case 0x1E0:
    case 0x1E1:
        ApplyTextureStages(geom, table);
        break;
    case 0x1CC:
    case 0x1CE:
    case 0x1D0:
        SetDstValueFromB(table, geom);
        break;
    default:
        break;
    }
}

extern ClusterObj* DAT_01202230;
extern "C" void __cdecl FUN_00e804d0(void* pSlot);
struct C0D170Self
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
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
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void at158();
    bool ProcessEntries_00c0d170();
};
// Iterates 33 slots starting at DAT_01202230, calling FUN_00e804d0 on each, then calls at158 and returns true.
// @fnv 0x00c0d170
// src: GUESS 0x00c0d170 (confidence: low)
bool C0D170Self::ProcessEntries_00c0d170()
{
    void* slot = &DAT_01202230;
    int n = 0x21;
    do
    {
        FUN_00e804d0(slot);
        slot = (char*)slot + 4;
    } while (--n);
    this->at158();
    return true;
}

struct ColorA_c1a310
{
    float r, g, b, a;
};
struct Obj_c1a310
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    float unk38;
};
// Copies DAT_011a9bd0 into a color, sets r to 1.0, g to 1.0 if b is set, b from p->unk38 or DAT_01018f5c, and stores it to DAT_011fa2d0.
// @fnv 0x00c1a310
// src: COMMUNITY 0x00c1a310
void __stdcall SpeedTreeBranchShader_UpdateTogglesConstant(int aUnused, int abGreen, Obj_c1a310* p)
{
    ColorA_c1a310 c = *(ColorA_c1a310*)&DAT_011a9bd0;
    c.r = 1.0f;
    if (abGreen)
        c.g = 1.0f;
    c.b = p ? p->unk38 : DAT_01018f5c;
    *(ColorA_c1a310*)&DAT_011fa2d0 = c;
}

extern "C" void __cdecl CreateTriStripsObject();
// @fnv 0x00c1a390
// src: COMMUNITY 0x00c1a390
void __cdecl TallGrassTriStrips_CreateClone()
{
    CreateTriStripsObject();
}

namespace ShaderBias {
struct RefObject
{
    virtual void slot0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct ShaderRefPointer
{
    RefObject* object;
    __forceinline void operator=(RefObject* value)
    {
        RefObject* old = object;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->DeleteThis();
            object = value;
            if (value)
                InterlockedIncrement(&value->m_iObjectReferenceCount);
        }
    }
};
struct RenderStateBlock
{
    void SetNodeValue(unsigned int, unsigned int, bool);
};
RenderStateBlock* FUN_00e7f5d0();
struct ShaderStage
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int texture;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    int references;
    void NiD3DTextureStage_ReturnStageToPool();
    __forceinline void Release()
    {
        --references;
        if (references == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};
struct ShaderStagePointer
{
    ShaderStage* object;
    ShaderStagePointer() : object(0)
    {}
    ~ShaderStagePointer()
    {
        if (object)
            object->Release();
    }
};
void AssignStageFromPool(ShaderStagePointer*);
void ConfigureBeamStage(ShaderStage*, unsigned int, unsigned int, unsigned int, bool);
extern unsigned int DAT_011f9534;
struct ShaderPass
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int stageCount;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    RenderStateBlock* state;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    ShaderRefPointer pixelShader;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    ShaderRefPointer vertexShader;
    unsigned int unk60;
    int references;
    __forceinline unsigned int Count()
    {
        return stageCount;
    }
    void FUN_00e80190();
    void NiD3DPass_SetStage(unsigned int, ShaderStage*);
    __forceinline RenderStateBlock* const& GetState()
    {
        if (!state)
            state = FUN_00e7f5d0();
        return state;
    }
};
struct ShaderPassPointer
{
    ShaderPass* object;
    ShaderPassPointer() : object(0)
    {}
    ~ShaderPassPointer()
    {
        if (object && --object->references == 0)
            object->FUN_00e80190();
    }
    __forceinline void operator=(ShaderPass* const& value)
    {
        if (object != value)
        {
            if (object && --object->references == 0)
                object->FUN_00e80190();
            object = value;
            if (object)
                ++object->references;
        }
    }
    __forceinline ShaderPass* operator->()
    {
        return object;
    }
};
extern float DAT_01200458;
extern ShaderPass* DAT_011feb58;
extern RefObject *DAT_011fdfcc, *DAT_011fdc70;
extern unsigned int DAT_011fd7e0, DAT_011fcc00;
extern ShaderPass* DAT_011feb5c;
extern RefObject *DAT_011fdfd0, *DAT_011fdc70;
extern unsigned int DAT_011fd7e4, DAT_011fcc04;
extern ShaderPass* DAT_011feb70;
extern RefObject *DAT_011fdfd4, *DAT_011fdc74;
extern unsigned int DAT_011fd7f8, DAT_011fcc18;
extern ShaderPass* DAT_011feb74;
extern RefObject *DAT_011fdfd8, *DAT_011fdc74;
extern unsigned int DAT_011fd7fc, DAT_011fcc1c;
extern ShaderPass* DAT_011feb88;
extern RefObject *DAT_011fdfdc, *DAT_011fdc70;
extern unsigned int DAT_011fd810, DAT_011fcc30;
extern ShaderPass* DAT_011feb8c;
extern RefObject *DAT_011fdfe0, *DAT_011fdc70;
extern unsigned int DAT_011fd814, DAT_011fcc34;
extern ShaderPass* DAT_011feba0;
extern RefObject *DAT_011fdfe4, *DAT_011fdc74;
extern unsigned int DAT_011fd828, DAT_011fcc48;
extern ShaderPass* DAT_011feba4;
extern RefObject *DAT_011fdfe8, *DAT_011fdc74;
extern unsigned int DAT_011fd82c, DAT_011fcc4c;
inline unsigned int FloatBits(float value)
{
    return *(unsigned int*)&value;
}
// Sets vertex/pixel shaders, render-state values and DAT flags on eight global ShaderPass objects, adding a configured stage to four of them.
// @fnv 0x00c02340
// src: COMMUNITY 0x00c02340
void ShadowLightShader_PresetWaterFogPasses_2x()
{
    ShaderPassPointer pass;
    ShaderStagePointer stage;
    pass = DAT_011feb58;
    pass->vertexShader = DAT_011fdfcc;
    pass->pixelShader = DAT_011fdc70;
    pass->GetState()->SetNodeValue(168, 3, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd7e0 = 16388;
    DAT_011fcc00 = 0x140040;
    pass = DAT_011feb5c;
    pass->vertexShader = DAT_011fdfd0;
    pass->pixelShader = DAT_011fdc70;
    pass->GetState()->SetNodeValue(168, 3, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd7e4 = 34816;
    DAT_011fcc04 = 0x140040;
    pass = DAT_011feb70;
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 1, 2, true);
    pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    pass->vertexShader = DAT_011fdfd4;
    pass->pixelShader = DAT_011fdc74;
    pass->GetState()->SetNodeValue(168, 3, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd7f8 = 16388;
    DAT_011fcc18 = 0x140040;
    pass = DAT_011feb74;
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 1, 2, true);
    pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    pass->vertexShader = DAT_011fdfd8;
    pass->pixelShader = DAT_011fdc74;
    pass->GetState()->SetNodeValue(168, 3, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd7fc = 34816;
    DAT_011fcc1c = 0x140040;
    pass = DAT_011feb88;
    pass->vertexShader = DAT_011fdfdc;
    pass->pixelShader = DAT_011fdc70;
    pass->GetState()->SetNodeValue(168, 3, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd810 = 16388;
    DAT_011fcc30 = 0x140040;
    pass = DAT_011feb8c;
    pass->vertexShader = DAT_011fdfe0;
    pass->pixelShader = DAT_011fdc70;
    pass->GetState()->SetNodeValue(168, 3, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd814 = 34816;
    DAT_011fcc34 = 0x140040;
    pass = DAT_011feba0;
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 1, 2, true);
    pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    pass->vertexShader = DAT_011fdfe4;
    pass->pixelShader = DAT_011fdc74;
    pass->GetState()->SetNodeValue(168, 3, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd828 = 16388;
    DAT_011fcc48 = 0x140040;
    pass = DAT_011feba4;
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 1, 2, true);
    pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    pass->vertexShader = DAT_011fdfe8;
    pass->pixelShader = DAT_011fdc74;
    pass->GetState()->SetNodeValue(168, 3, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd82c = 34816;
    DAT_011fcc4c = 0x140040;
}
}

struct __declspec(novtable) ISBaseA
{
    virtual ~ISBaseA();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
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
    void FUN_00be2200();
    void FUN_00be0870();
    ISBaseA()
    {
        FUN_00be2200();
    }
};
struct __declspec(novtable) ISBaseB
{
    virtual ~ISBaseB();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
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
    void FUN_00ba4080();
    ISBaseB()
    {
        FUN_00ba4080();
    }
};
struct ISRefObj
{
    int unk00;
};
struct ISPtr
{
    ISRefObj* m_p;
    ISPtr() : m_p(0)
    {}
    ~ISPtr();
};
struct ISEffect : ISBaseA, ISBaseB
{
    ISPtr unkc4;
    ISPtr unkc8;
    virtual ~ISEffect();
    void SetupRenderer();
    ISEffect();
};
// Constructs an ISEffect, sets unk68 to 0x18, calls FUN_00be0870 and SetupRenderer.
// @fnv 0x00c04570
ISEffect::ISEffect()
{
    unk68 = 0x18;
    FUN_00be0870();
    SetupRenderer();
}

template <> __declspec(noalias) void NiTArray<ImageSpaceEffectParam*, NiTMallocInterface<ImageSpaceEffectParam*> >::SetAt(unsigned int, ImageSpaceEffectParam* const&) throw();

struct FUN_00c056a0 : ImageSpaceEffect
{
    virtual ~FUN_00c056a0();
};
// Destroys the first element of pEffectParamList if it is non-null, then clears the slot.
// @fnv 0x00c056a0
FUN_00c056a0::~FUN_00c056a0()
{
    if (pEffectParamList.m_pBase[0])
    {
        // The game's slot zero is the scalar deleting destructor; the shared
        // header currently declares only a nonvirtual destructor.
        typedef void* (__thiscall *DeletingDestructor)(ImageSpaceEffectParam*, unsigned int);
        ImageSpaceEffectParam* param = pEffectParamList.m_pBase[0];
        if (param)
            (*reinterpret_cast<DeletingDestructor**>(param))[0](param, 1);
        pEffectParamList.SetAt(0, 0);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);






// Stores element at uiIndex in m_pBase, growing m_usSize if needed and adjusting m_usESize when the slot's null state changes.
// @fnv 0x00c1d7e0
template <> void NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > >::SetAt(unsigned int uiIndex, const NiPointer<NiAVObject>& element)
{
    static const NiPointer<NiAVObject> kNull(0);

    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element != kNull)
            m_usESize++;
    }
    else
    {
        if (element != kNull)
        {
            if (m_pBase[uiIndex] == kNull)
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex] != kNull)
                m_usESize--;
        }
    }

    m_pBase[uiIndex] = element;
}





struct Pass04120
{
    StageReturn* m_pObject;
    Pass04120() : m_pObject(0)
    {}
    ~Pass04120()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
};
// The shared pass header has no indexed SetStage declaration. This binding
// supplies only that call; all pass data and other methods use NiD3DPass.
struct D3DPassStageBinding
{
    void SetStage(unsigned int index, BeamStage* stage);
};

inline void NiD3DPass::SetRenderState(unsigned int state, unsigned int value, bool save)
{
    if (!m_pkRenderStateGroup)
        m_pkRenderStateGroup = reinterpret_cast<D3DRenderStateGroup*>(FUN_00e7f5d0());
    reinterpret_cast<ElemObj*>(m_pkRenderStateGroup)->SetNodeValue(state, value, save);
}

inline void NiD3DPass::SetPixelShader(NiD3DPixelShader* shader)
{
    NiRefObject* incoming = reinterpret_cast<NiRefObject*>(shader);
    NiRefObject* old = reinterpret_cast<NiRefObject*>(m_spPixelShader.m_pObject);
    if (old != incoming)
    {
        if (old)
            old->DecRefCount();
        m_spPixelShader.m_pObject = shader;
        if (incoming)
            incoming->IncRefCount();
    }
}
void __cdecl AssignStageFromPool(Pass04120*);
void __cdecl ConfigureBeamStage(BeamStage*, unsigned int, int, int, int);
struct Target04120
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void Configure();

    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58;
    NiD3DPass* m_shader;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98;
    unsigned short m_stageCount;
    unsigned short unk9e;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0;
    NiRefObject* m_texture;
    NiRefObject* m_property;

    bool ConfigureBeam();
};
// Allocates beam stages, sets shader render states, copies texture and property references, and stores the shader pointer in DAT_0126f74c.
// @fnv 0x00c04120
bool Target04120::ConfigureBeam()
{
    Pass04120 pass;
    NiD3DPass::CreateD3DPass(m_shader);
    for (unsigned int i = 0; i < m_stageCount; ++i)
    {
        AssignStageFromPool(&pass);
        ConfigureBeamStage(pass.m_pObject, i, 3, 2, 1);
        reinterpret_cast<D3DPassStageBinding*>(m_shader)->SetStage(m_shader->m_uiCurrentStage, pass.m_pObject);
    }
    m_shader->SetRenderState(7, 0, 1);
    m_shader->SetRenderState(14, 0, 1);
    m_shader->SetRenderState(27, 0, 1);
    m_shader->SetRenderState(15, 0, 1);
    m_shader->SetRenderState(168, 15, 1);
    Configure();
    {
        NiD3DPass* shader = m_shader;
        NiRefObject* incoming = m_texture;
        NiRefObject* old = reinterpret_cast<NiRefObject*>(shader->m_spVertexShader.m_pObject);
        if (old != incoming)
        {
            if (old)
                old->DecRefCount();
            shader->m_spVertexShader.m_pObject = reinterpret_cast<NiD3DVertexShader*>(incoming);
            if (incoming)
                incoming->IncRefCount();
        }
    }
    m_shader->SetPixelShader(reinterpret_cast<NiD3DPixelShader*>(m_property));
    DAT_0126f74c = reinterpret_cast<int>(m_shader);
    return true;
}

namespace fnv_00c0fdc0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct ShaderRefPointer
{
    RefObject* object;
    __forceinline void operator=(RefObject* value)
    {
        RefObject* old = object;
        if (old != value)
        {
            if (old && InterlockedDecrement(reinterpret_cast<volatile long*>(&old->m_iObjectReferenceCount)) == 0)
                old->DeleteThis();
            object = value;
            if (value)
                InterlockedIncrement(reinterpret_cast<volatile long*>(&value->m_iObjectReferenceCount));
        }
    }
};
struct RenderStateBlock
{
    void SetNodeValue(unsigned int, unsigned int, bool);
};
RenderStateBlock* FUN_00e7f5d0();
struct ShaderStage
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int texture;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    int references;
    void NiD3DTextureStage_ReturnStageToPool();
    __forceinline void Release()
    {
        --references;
        if (references == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};
struct ShaderStagePointer
{
    ShaderStage* object;
    ShaderStagePointer() : object(0)
    {}
    ~ShaderStagePointer()
    {
        if (object)
            object->Release();
    }
};
void AssignStageFromPool(ShaderStagePointer*);
void ConfigureBeamStage(ShaderStage*, unsigned int, unsigned int, unsigned int, bool);
extern unsigned int DAT_011f9534;
struct ShaderPass
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int stageCount;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    RenderStateBlock* state;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    ShaderRefPointer pixelShader;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    ShaderRefPointer vertexShader;
    unsigned int unk60;
    int references;
    __forceinline unsigned int Count()
    {
        return stageCount;
    }
    void FUN_00e80190();
    void NiD3DPass_SetStage(unsigned int, ShaderStage*);
    __forceinline RenderStateBlock* GetState()
    {
        if (!state)
            state = FUN_00e7f5d0();
        return state;
    }
};
struct ShaderPassPointer
{
    ShaderPass* object;
    ShaderPassPointer() : object(0)
    {}
    ~ShaderPassPointer()
    {
        if (object && --object->references == 0)
            object->FUN_00e80190();
    }
    __forceinline void operator=(ShaderPass* const& value)
    {
        if (object != value)
        {
            if (object && --object->references == 0)
                object->FUN_00e80190();
            object = value;
            if (object)
                ++object->references;
        }
    }
    __forceinline ShaderPass* operator->()
    {
        return object;
    }
};
extern ShaderPass* passVariant0;
extern ShaderPass* passVariant1;
extern ShaderPass* passVariant2;
extern ShaderPass* passVariant3;
extern ShaderPass* passVariant4;
extern ShaderPass* passVariant5;
extern ShaderPass* passVariant6;
extern ShaderPass* passVariant7;
extern unsigned int DAT_011fcee4;
extern unsigned int DAT_011fcee8;
extern unsigned int DAT_011fcf10;
extern unsigned int DAT_011fcf14;
extern unsigned int DAT_011fcf3c;
extern unsigned int DAT_011fcf40;
extern unsigned int DAT_011fcf68;
extern unsigned int DAT_011fcf6c;
extern unsigned int DAT_011fc304;
extern unsigned int DAT_011fc308;
extern unsigned int DAT_011fc330;
extern unsigned int DAT_011fc334;
extern unsigned int DAT_011fc35c;
extern unsigned int DAT_011fc360;
extern unsigned int DAT_011fc388;
extern unsigned int DAT_011fc38c;
struct ShaderSetup
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    RefObject* shader9c;
    RefObject* shadera0;
    RefObject* shadera4;
    RefObject* shadera8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    RefObject* shader100;
    RefObject* shader104;
    RefObject* shader108;
    RefObject* shader10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    RefObject* shader150;
    RefObject* shader154;
    RefObject* shader158;
    RefObject* shader15c;
    void ParallaxShader_PresetADTSPasses_2x();
};
__forceinline void ConfigureStage(ShaderPass* pass, ShaderStagePointer& stage, unsigned int index, unsigned int kind,
                                  unsigned int operation)
{
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, index, kind, operation, true);
    pass->NiD3DPass_SetStage(index, stage.object);
}
__forceinline void ConfigureSpecialStage(ShaderPass* pass, ShaderStagePointer& stage)
{
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 5, 3, 0, true);
    stage.object->texture = DAT_011f9534;
    stage.object->unk0c = 1;
    pass->NiD3DPass_SetStage(5, stage.object);
}
// Configures the eight global shader pass variants by setting up their stages, vertex and pixel shaders, render states, and associated global values.
// @fnv 0x00c0fdc0
// src: COMMUNITY 0x00c0fdc0
void ShaderSetup::ParallaxShader_PresetADTSPasses_2x()
{
    ShaderPassPointer pass;
    ShaderStagePointer stage;
    pass = passVariant0;
    if (pass->Count() < 8)
    {
        ConfigureStage(pass.object, stage, 0, 1, 2);
        ConfigureStage(pass.object, stage, 1, 1, 2);
        ConfigureStage(pass.object, stage, 2, 1, 2);
        ConfigureStage(pass.object, stage, 3, 1, 2);
        ConfigureStage(pass.object, stage, 4, 1, 2);
        ConfigureSpecialStage(pass.object, stage);
        ConfigureStage(pass.object, stage, 6, 1, 2);
        ConfigureStage(pass.object, stage, 7, 3, 0);
    }
    pass->vertexShader = shader9c;
    pass->pixelShader = shader100;
    pass->GetState()->SetNodeValue(27, 0, true);
    pass->GetState()->SetNodeValue(15, 0, true);
    pass->GetState()->SetNodeValue(7, 1, true);
    pass->GetState()->SetNodeValue(23, 4, true);
    pass->GetState()->SetNodeValue(14, 1, true);
    DAT_011fcee4 = 0x780;
    DAT_011fc304 = 0x2c;
    pass = passVariant1;
    if (pass->Count() < 8)
    {
        ConfigureStage(pass.object, stage, 0, 1, 2);
        ConfigureStage(pass.object, stage, 1, 1, 2);
        ConfigureStage(pass.object, stage, 2, 1, 2);
        ConfigureStage(pass.object, stage, 3, 1, 2);
        ConfigureStage(pass.object, stage, 4, 1, 2);
        ConfigureSpecialStage(pass.object, stage);
        ConfigureStage(pass.object, stage, 6, 1, 2);
        ConfigureStage(pass.object, stage, 7, 3, 0);
    }
    pass->vertexShader = shader9c;
    pass->pixelShader = shader104;
    pass->GetState()->SetNodeValue(27, 0, true);
    pass->GetState()->SetNodeValue(15, 0, true);
    pass->GetState()->SetNodeValue(7, 1, true);
    pass->GetState()->SetNodeValue(23, 4, true);
    pass->GetState()->SetNodeValue(14, 1, true);
    DAT_011fcee8 = 0x780;
    DAT_011fc308 = 0x3c;
    pass = passVariant2;
    if (pass->Count() < 8)
    {
        ConfigureStage(pass.object, stage, 0, 1, 2);
        ConfigureStage(pass.object, stage, 1, 1, 2);
        ConfigureStage(pass.object, stage, 2, 1, 2);
        ConfigureStage(pass.object, stage, 3, 1, 2);
        ConfigureStage(pass.object, stage, 4, 1, 2);
        ConfigureSpecialStage(pass.object, stage);
        ConfigureStage(pass.object, stage, 6, 1, 2);
        ConfigureStage(pass.object, stage, 7, 3, 0);
    }
    pass->vertexShader = shadera0;
    pass->pixelShader = shader108;
    pass->GetState()->SetNodeValue(27, 0, true);
    pass->GetState()->SetNodeValue(15, 0, true);
    pass->GetState()->SetNodeValue(7, 1, true);
    pass->GetState()->SetNodeValue(23, 4, true);
    pass->GetState()->SetNodeValue(14, 1, true);
    DAT_011fcf10 = 0x7f0;
    DAT_011fc330 = 0x2c;
    pass = passVariant3;
    if (pass->Count() < 8)
    {
        ConfigureStage(pass.object, stage, 0, 1, 2);
        ConfigureStage(pass.object, stage, 1, 1, 2);
        ConfigureStage(pass.object, stage, 2, 1, 2);
        ConfigureStage(pass.object, stage, 3, 1, 2);
        ConfigureStage(pass.object, stage, 4, 1, 2);
        ConfigureSpecialStage(pass.object, stage);
        ConfigureStage(pass.object, stage, 6, 1, 2);
        ConfigureStage(pass.object, stage, 7, 3, 0);
    }
    pass->vertexShader = shadera0;
    pass->pixelShader = shader10c;
    pass->GetState()->SetNodeValue(27, 0, true);
    pass->GetState()->SetNodeValue(15, 0, true);
    pass->GetState()->SetNodeValue(7, 1, true);
    pass->GetState()->SetNodeValue(23, 4, true);
    pass->GetState()->SetNodeValue(14, 1, true);
    DAT_011fcf14 = 0x7f0;
    DAT_011fc334 = 0x3c;
    pass = passVariant4;
    if (pass->Count() < 8)
    {
        ConfigureStage(pass.object, stage, 0, 1, 2);
        ConfigureStage(pass.object, stage, 1, 1, 2);
        ConfigureStage(pass.object, stage, 2, 1, 2);
        ConfigureStage(pass.object, stage, 3, 1, 2);
        ConfigureStage(pass.object, stage, 4, 1, 2);
        ConfigureSpecialStage(pass.object, stage);
        ConfigureStage(pass.object, stage, 6, 1, 2);
        ConfigureStage(pass.object, stage, 7, 3, 0);
    }
    pass->vertexShader = shadera4;
    pass->pixelShader = shader150;
    pass->GetState()->SetNodeValue(27, 0, true);
    pass->GetState()->SetNodeValue(15, 0, true);
    pass->GetState()->SetNodeValue(7, 1, true);
    pass->GetState()->SetNodeValue(23, 4, true);
    pass->GetState()->SetNodeValue(14, 1, true);
    DAT_011fcf3c = 0x780;
    DAT_011fc35c = 0x2c;
    pass = passVariant5;
    if (pass->Count() < 8)
    {
        ConfigureStage(pass.object, stage, 0, 1, 2);
        ConfigureStage(pass.object, stage, 1, 1, 2);
        ConfigureStage(pass.object, stage, 2, 1, 2);
        ConfigureStage(pass.object, stage, 3, 1, 2);
        ConfigureStage(pass.object, stage, 4, 1, 2);
        ConfigureSpecialStage(pass.object, stage);
        ConfigureStage(pass.object, stage, 6, 1, 2);
        ConfigureStage(pass.object, stage, 7, 3, 0);
    }
    pass->vertexShader = shadera4;
    pass->pixelShader = shader154;
    pass->GetState()->SetNodeValue(27, 0, true);
    pass->GetState()->SetNodeValue(15, 0, true);
    pass->GetState()->SetNodeValue(7, 1, true);
    pass->GetState()->SetNodeValue(23, 4, true);
    pass->GetState()->SetNodeValue(14, 1, true);
    DAT_011fcf40 = 0x780;
    DAT_011fc360 = 0x3c;
    pass = passVariant6;
    if (pass->Count() < 8)
    {
        ConfigureStage(pass.object, stage, 0, 1, 2);
        ConfigureStage(pass.object, stage, 1, 1, 2);
        ConfigureStage(pass.object, stage, 2, 1, 2);
        ConfigureStage(pass.object, stage, 3, 1, 2);
        ConfigureStage(pass.object, stage, 4, 1, 2);
        ConfigureSpecialStage(pass.object, stage);
        ConfigureStage(pass.object, stage, 6, 1, 2);
        ConfigureStage(pass.object, stage, 7, 3, 0);
    }
    pass->vertexShader = shadera8;
    pass->pixelShader = shader158;
    pass->GetState()->SetNodeValue(27, 0, true);
    pass->GetState()->SetNodeValue(15, 0, true);
    pass->GetState()->SetNodeValue(7, 1, true);
    pass->GetState()->SetNodeValue(23, 4, true);
    pass->GetState()->SetNodeValue(14, 1, true);
    DAT_011fcf68 = 0x7f0;
    DAT_011fc388 = 0x2c;
    pass = passVariant7;
    if (pass->Count() < 8)
    {
        ConfigureStage(pass.object, stage, 0, 1, 2);
        ConfigureStage(pass.object, stage, 1, 1, 2);
        ConfigureStage(pass.object, stage, 2, 1, 2);
        ConfigureStage(pass.object, stage, 3, 1, 2);
        ConfigureStage(pass.object, stage, 4, 1, 2);
        ConfigureSpecialStage(pass.object, stage);
        ConfigureStage(pass.object, stage, 6, 1, 2);
        ConfigureStage(pass.object, stage, 7, 3, 0);
    }
    pass->vertexShader = shadera8;
    pass->pixelShader = shader15c;
    pass->GetState()->SetNodeValue(27, 0, true);
    pass->GetState()->SetNodeValue(15, 0, true);
    pass->GetState()->SetNodeValue(7, 1, true);
    pass->GetState()->SetNodeValue(23, 4, true);
    pass->GetState()->SetNodeValue(14, 1, true);
    DAT_011fcf6c = 0x7f0;
    DAT_011fc38c = 0x3c;
}
}  // namespace fnv_00c0fdc0
