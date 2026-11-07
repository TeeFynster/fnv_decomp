#include "../../include/BSShaderProperty.h"
#include "../../include/NiFrustum.h"
#include "../../include/ImageSpaceTexture.h"
#include "../../include/NiTArray.h"
#include "../../include/NiFrustum.h"

// src/staging/blk_00bc0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/ImageSpaceEffectParam.h"
#include "../../include/Bound.h"
#include "../../include/BSFogProperty.h"
#include "../../include/BSShader.h"
#include "../../include/BSShaderPPLightingProperty.h"
#include "../../include/NiDX9Renderer.h"
#include "../../include/NiInterpolator.h"
#include "../../include/NiObjectNET.h"
#include "../../include/NiTimeController.h"
#include "../../include/NiUpdateData.h"
#include "../../include/Vec4.h"

#include "../../include/NiTPointerMap.h"
#include "../../include/NiTPrimitiveArray.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

#include "../../include/BSFaceGenMorphData.h"
#include "../../include/BSFadeNode.h"
#include "../../include/BSShaderAccumulator.h"
#include "../../include/BSShaderManager.h"
#include "../../include/BSShaderProperty.h"
#include "../../include/NiPoint3.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiCamera.h"
#include "../../include/NiColor.h"
#include "../../include/NiColorA.h"
#include "../../include/NiD3DGPUProgramCache.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiD3DPixelShader.h"
#include "../../include/NiD3DShaderConstantMap.h"
#include "../../include/NiD3DShaderDeclaration.h"
#include "../../include/NiD3DVertexShader.h"
#include "../../include/NiFloatInterpController.h"
#include "../../include/NiFloatInterpolator.h"
#include "../../include/NiGeometry.h"
#include "../../include/NiObject.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiShader.h"
#include "../../include/NiSortAdjustNode.h"
#include "../../include/StrArr.h"
// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3; this unit defines inline bodies for both NiPoint3 and the stand-in in different forms (constructor/temporary, operand order), so one NiPoint3 cannot carry both.
#include "../../include/NiPoint3.h"
class Allocator;
class Elem16;
struct Mat;
struct Matrix4;
class NiPoint3;

struct LocalVec3
{
public:
    union
    {
        float x;
        unsigned int xb;
    };
    union
    {
        float y;
        unsigned int yb;
    };
    union
    {
        float z;
        unsigned int zb;
    };

    LocalVec3();
    // Keep the implicit copy constructor trivial for by-value calls.
    LocalVec3(float x, float y = 0.0f, float z = 0.0f);
    LocalVec3(const float* data);

    __forceinline LocalVec3& operator=(const LocalVec3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    LocalVec3 operator+(const LocalVec3& other) const;
    LocalVec3 operator-(const LocalVec3& other) const;
    NiPoint3 operator-(const NiPoint3& other) const;
    LocalVec3 operator-() const;
    LocalVec3 operator*(float scale) const;
    LocalVec3 operator*(double scale) const;
    LocalVec3& operator+=(const LocalVec3& other);
    LocalVec3& operator*=(float scale);
    LocalVec3& operator/=(float scale);
    bool operator==(const LocalVec3& other) const;
    bool operator!=(const LocalVec3& other) const;
    float& operator[](int index);
    float& operator[](unsigned int index);

    LocalVec3* Self();
    void Set(float x, float y, float z);
    void AssignOutput(const LocalVec3& other);
    LocalVec3 Neg() const;
    LocalVec3 Add(const LocalVec3& other) const;
    LocalVec3 Added(const LocalVec3& other) const;
    LocalVec3& AddTo(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other) const;
    void Subtract(const LocalVec3& other);
    LocalVec3 Scale(float scale) const;
    LocalVec3 ApplyScaled(float scale);
    LocalVec3 ApplyScaled(float scale) const;
    LocalVec3 ScaleSwizzled(float scale);
    LocalVec3 ScaleSwizzled(float scale) const;
    void ScaleByInverse(float scale);
    void Normalize();
    void Unitize();
    LocalVec3 Cross(const LocalVec3& other) const;
    float Dot(const LocalVec3& other) const;
    float DotProduct(const LocalVec3& other);
    float DotProduct(const LocalVec3& other) const;
    float DotProduct(const LocalVec3* other) const;
    float Length() const;
    float LengthSquared() const;
    float GetSquaredXYLength();
    float GetSquaredXYLength() const;
    Elem16& expand(Allocator& allocator);

    void SetComponents(float x, float y, float z);
    bool FUN_00439090(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other) const;
    bool HasEqualComponents(const char* other);
    void ScaleComponents(float scale);
    LocalVec3 FUN_00439e90(const LocalVec3& other);
    LocalVec3 FUN_00439e90(const LocalVec3& other) const;
    void SubtractIntoVector();
    LocalVec3 SubtractIntoVector(const LocalVec3& other);
    LocalVec3 SubtractIntoVector(const LocalVec3& other) const;
    LocalVec3 SubtractIntoVector(LocalVec3* other);
    LocalVec3 SubtractIntoVector(const LocalVec3* other);
    void SubtractIntoVector(LocalVec3* output, const LocalVec3* other);
    LocalVec3* SubtractIntoVector(void* output, void* other);
    void FUN_0043d410(float x, int y, int z);
    void FUN_0043d410(float x, unsigned int y, unsigned int z);
    float FUN_00457910();
    float FUN_00457990();
    float FUN_00457990() const;
    void Unitize_004a0c10();
    float FUN_004a7290();
    float FUN_004a7290() const;
    LocalVec3 FUN_004b3800(const LocalVec3& other) const;
    LocalVec3 ProcessAndReturnValue_0053d280(float divisor);
    float NiPoint3_XYLength();
    float NiPoint3_XYLength() const;
    void ComputeValue_0063c8a0(const LocalVec3* other);
    void ComputeValue_0063c8a0(void* other);
    void FUN_006815c0();
    float CVec3_Distance(LocalVec3* other);
    float CVec3_Distance(const LocalVec3& other) const;
    LocalVec3 TransformPointByMatrix4(const Mat& matrix);
    LocalVec3 TransformPointByMatrix4(const Matrix4* matrix);
    void Normalize_00b12790();
    LocalVec3 Diff_00b13040(void* other);
    LocalVec3 Diff_00b13040(const LocalVec3& other) const;
    float FUN_00b2a180(void* other);
    LocalVec3& AddComponents(void* other);
    void ProcessEntries_00ddc870();
    void FUN_00e0f6e0();
};

// The original constructors inline the shared RGBA initialization in this unit.
__forceinline NiColorA::NiColorA(float fR, float fG, float fB, float fA)
    : r(fR), g(fG), b(fB), a(fA)
{}

// NiColorA's shared header does not yet declare these methods. Keep their
// thiscall entry points here without introducing another color class.
extern "C" void NiColorA_LoadBinary();
extern "C" void NiColorA_SaveBinary();
extern "C" void NiColorA_FormatToBuffer();

// Keep this unit's smart-pointer bodies: using the shared NiPointer inline bodies
// changes 0x00bd4d30 from 405 to 407 bytes (comparison/assignment codegen).
template <class T> class StagingNiPointer
{
  public:
    T* m_pObject;
    StagingNiPointer(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    StagingNiPointer(const StagingNiPointer<T>& other)
    {
        m_pObject = other.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~StagingNiPointer()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    StagingNiPointer<T>& operator=(T* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    StagingNiPointer<T>& operator=(const StagingNiPointer<T>& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    bool operator==(T* object) const
    {
        return m_pObject == object;
    }
    bool operator==(const StagingNiPointer<T>& other) const
    {
        return m_pObject == other.m_pObject;
    }
    bool operator!=(const StagingNiPointer<T>& other) const
    {
        return m_pObject != other.m_pObject;
    }
};

struct ShaderVector4
{
    float x, y, z, w;
};

// NiPoint3 methods the shared header only declares, inline in this unit (0x00bd66c0 reads the camera's
// up/right axes as points).
__forceinline NiPoint3::NiPoint3(float fX, float fY, float fZ)
{
    x = fX;
    y = fY;
    z = fZ;
}
__forceinline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline float NiPoint3::operator*(const NiPoint3& pt) const
{
    return y * pt.y + x * pt.x + z * pt.z;
}

extern "C" void* g_01201f5c;

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

inline void StrArr::AppendInline(char* string)
{
    unsigned int index = m_usSize;
    if (index >= m_usMaxSize)
        SetSize(index + m_usGrowBy);
    SetAt(index, string);
}

inline void NiRefObject::IncrementReferenceCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}
inline void NiRefObject::IncRefCount()
{
    ++*(volatile long*)&m_uiRefCount;
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}
inline void NiD3DShaderConstantMap::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}
inline void NiD3DShaderConstantMap::DecRefCount()
{
    if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
        DeleteThis();
}
template <class T> class AtomicNiPointer
{
    static void IncRef(T* object)
    {
        InterlockedIncrement((volatile long*)&object->m_uiRefCount);
    }
    static void DecRef(T* object)
    {
        if (InterlockedDecrement((volatile long*)&object->m_uiRefCount) == 0)
            object->DeleteThis();
    }
public:
    T* m_pObject;
    AtomicNiPointer(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject) IncRef(m_pObject);
    }
    ~AtomicNiPointer()
    {
        if (m_pObject) DecRef(m_pObject);
    }
    AtomicNiPointer& operator=(T* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject) DecRef(m_pObject);
            m_pObject = object;
            if (m_pObject) IncRef(m_pObject);
        }
        return *this;
    }
};

inline bool IsKindOfType(const NiObject* object, const NiRTTI* type)
{
    const NiRTTI* compare = object->GetRTTI();
    while (compare)
    {
        if (compare == type)
            return true;
        compare = compare->m_pBaseRTTI;
    }
    return false;
}

// @fnv 0x00bc0f70
// src: XBOX_PDB 0x00bc0f70
void* __cdecl BoltShader_GetRTTI()
{
    return &g_01201f5c;
}

extern MemoryManager g_memoryManager;
extern void* DAT_01201f4c;

// @fnv 0x00bc0c50
// src: XBOX_PDB 0x00bc0c50
void __cdecl BoltShader_ClearSegmentIndexArray()
{
    if (DAT_01201f4c)
        g_memoryManager.Deallocate(DAT_01201f4c);
    DAT_01201f4c = 0;
}

extern "C" void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00bc1fa0_class
{
    void FUN_00bc1fa0();
};
struct FUN_00bc2510_class : FUN_00bc1fa0_class
{
    void* FUN_00bc2510(int a);
};
// Calls FUN_00bc1fa0, then deletes this with size 0x190 when bit 0 of a is set, and returns this.
// @fnv 0x00bc2510
void* FUN_00bc2510_class::FUN_00bc2510(int aiFlags)
{
    FUN_00bc1fa0();
    if (aiFlags & 1)
        operator delete(this, 0x190);
    return this;
}

extern bool DAT_01201f70;
void __cdecl ReleaseFadeNodeResources();
void __cdecl ReleaseStringHolders();

// @fnv 0x00bc2960
// src: GUESS 0x00bc2960 (confidence: low)
void __cdecl Object_UpdateFields_00bc2960()
{
    if (DAT_01201f70)
    {
        ReleaseFadeNodeResources();
        ReleaseStringHolders();
        DAT_01201f70 = false;
    }
}

extern int DAT_010ba730;
void __cdecl FUN_00c5faa0();
extern "C" void __cdecl operator delete(void*, unsigned int);

struct FUN_00bc2c20_class
{
    int* m_pVT;
    void* FUN_00bc2c20(int bFlag);
};

// @fnv 0x00bc2c20
void* FUN_00bc2c20_class::FUN_00bc2c20(int aiFlags)
{
    m_pVT = &DAT_010ba730;
    FUN_00c5faa0();
    if (aiFlags & 1)
        operator delete(this, 0xc0);
    return this;
}

struct Unknown
{
    void ReleaseReference_00a360d0();
};
struct FUN_00bc3350_Class : Unknown
{
    FUN_00bc3350_Class* FUN_00bc3350(int f);
};
void __cdecl _delete(void* p, int size);
// Calls FUN_00a360d0, then deletes this with size 0x38 when bit 0 of f is set, and returns this.
// @fnv 0x00bc3350
FUN_00bc3350_Class* FUN_00bc3350_Class::FUN_00bc3350(int aiFlags)
{
    ReleaseReference_00a360d0();
    if (aiFlags & 1)
        _delete(this, 0x38);
    return this;
}

struct FUN_00bc34a0_class
{
    void* __thiscall BSRefractionStrengthController_GetTargetFloatValue(float* out);
};

// @fnv 0x00bc34a0
// src: XBOX_PDB 0x00bc34a0
void* __thiscall FUN_00bc34a0_class::BSRefractionStrengthController_GetTargetFloatValue(float* out)
{
    *out = *(float*)((char*)*(void**)((char*)this + 0x2c) + 0xe0);
    return *(void**)((char*)this + 0x2c);
}

struct NiStream;

struct FUN_00bc3780_Class : BSShaderProperty
{
    // BSShaderProperty does not yet declare its stream override.
    void __thiscall BSShaderProperty_SaveBinary(NiStream&);
    void __thiscall VolumetricFogShaderProperty_SaveBinary(NiStream& stream);
};
// @fnv 0x00bc3780
// src: XBOX_PDB 0x00bc3780
void __thiscall FUN_00bc3780_Class::VolumetricFogShaderProperty_SaveBinary(NiStream& stream)
{
    BSShaderProperty_SaveBinary(stream);
    ((void (__thiscall*)(NiColorA*, NiStream&))NiColorA_SaveBinary)((NiColorA*)((char*)this + 0x60), stream);
}

extern void* __cdecl operator new(unsigned int);
extern void __cdecl operator delete(void*, unsigned int);
extern int DAT_010bab28;
void __fastcall FUN_00baa0e0(void*);
struct FUN_00bc3800_Class
{
    void* m_p;
    void* __thiscall FUN_00bc3800(int flags);
};
// @fnv 0x00bc3800
void* __thiscall FUN_00bc3800_Class::FUN_00bc3800(int flags)
{
    m_p = &DAT_010bab28;
    FUN_00baa0e0(this);
    if (flags & 1)
        operator delete(this, 0x70);
    return this;
}

struct FUN_00bc4980_class
{
    void __thiscall ParticleShader_SetCurrentPass(void* p, char c);
};

// @fnv 0x00bc4980
// src: XBOX_PDB 0x00bc4980
void __thiscall FUN_00bc4980_class::ParticleShader_SetCurrentPass(void* p, char c)
{
    *(void**)((char*)this + 0x6c) = p;
    *(char*)((char*)this + 0x64) = c;
}

void __cdecl FUN_00bc5320();

extern "C" void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00bc5980_cls
{
    void* __thiscall FUN_00bc5980(int flags);
};

// @fnv 0x00bc5980
void* __thiscall FUN_00bc5980_cls::FUN_00bc5980(int flags)
{
    FUN_00bc5320();
    if (flags & 1)
        operator delete(this, 0xa8);
    return this;
}

extern "C" void __cdecl _delete(void*, unsigned int);

struct FUN_00bd0440_class
{
    void __thiscall FUN_00bcf920();
    void* __thiscall FUN_00bd0440(int);
};

// Calls FUN_00bcf920, then deletes this with size 0x128 when bit 0 of a is set, and returns this.
// @fnv 0x00bd0440
void* __thiscall FUN_00bd0440_class::FUN_00bd0440(int aiFlags)
{
    FUN_00bcf920();
    if (aiFlags & 1)
        _delete(this, 0x128);
    return this;
}

void __cdecl FUN_00bd2c40();
extern "C" void __cdecl operator delete(void*, unsigned int);
struct FUN_00bd2fd0_class
{
    void* __thiscall FUN_00bd2fd0(int flags);
};
// @fnv 0x00bd2fd0
void* __thiscall FUN_00bd2fd0_class::FUN_00bd2fd0(int flags)
{
    FUN_00bd2c40();
    if (flags & 1)
        operator delete(this, 0xa8);
    return this;
}

struct FUN_00bd4570_t
{
    void __thiscall FUN_00bd4570();
};

void __cdecl operator delete(void* p, size_t n);

struct FUN_00bd4d00_class
{
    FUN_00bd4d00_class* __thiscall FUN_00bd4d00(int flag);
};

// Calls FUN_00bd4570 on this, frees this with operator delete when flag has bit 0 set, and returns this.
// @fnv 0x00bd4d00
FUN_00bd4d00_class* __thiscall FUN_00bd4d00_class::FUN_00bd4d00(int aiFlags)
{
    ((FUN_00bd4570_t*)this)->FUN_00bd4570();
    if (aiFlags & 1)
        operator delete(this, 0x12c);
    return this;
}

extern char DAT_012023d4;
void* __cdecl GetImageSpaceTexture();
struct FUN_00bd6ab0_Class
{
    float m_f;
    int ImageSpaceEffectDepthOfField_IsActive();
};
// Returns 1 if the float at offset 0x70 is positive, DAT_012023d4 is set, and GetImageSpaceTexture returns non-null; otherwise 0.
// @fnv 0x00bd6ab0
// src: COMMUNITY 0x00bd6ab0
int FUN_00bd6ab0_Class::ImageSpaceEffectDepthOfField_IsActive()
{
    if (*(float*)((char*)this + 0x70) > 0.0f && DAT_012023d4)
    {
        void* p = GetImageSpaceTexture();
        if (p)
            return 1;
    }
    return 0;
}

void __cdecl FUN_00bd74a0();
void __cdecl operator delete(void*, unsigned int);

struct FUN_00bd8480_Class
{
    void* __thiscall FUN_00bd8480(int flags);
};

// Calls FUN_00bd74a0, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00bd8480
void* __thiscall FUN_00bd8480_Class::FUN_00bd8480(int flags)
{
    FUN_00bd74a0();
    if (flags & 1)
        operator delete(this, 0x140);
    return this;
}

struct LodShaderBase
{
    void FUN_00e814b0();
};
struct FUN_00bc0970_class : LodShaderBase
{
    void BoltShader_RecreateRendererData();
};
// @fnv 0x00bc0970
// src: XBOX_PDB 0x00bc0970
void FUN_00bc0970_class::BoltShader_RecreateRendererData()
{
    if (*(int*)((char*)this + 0x28))
    {
        void(__thiscall * f1)(void*) = (void(__thiscall*)(void*))(*(int**)(*(int*)((char*)this + 0x18c)))[0x28];
        f1(*(void**)((char*)this + 0x18c));
        void(__thiscall * f2)(void*) = (void(__thiscall*)(void*))(*(int**)(*(int*)((char*)this + 0x190)))[0x22];
        f2(*(void**)((char*)this + 0x190));
    }
    FUN_00e814b0();
}

extern "C" void __cdecl FUN_00c5f570();
extern int DAT_010ba730;
extern float _NiPoint3_ZERO;
extern int _DAT_011f4270;
extern int _DAT_011f4274;

struct FUN_00bc2bd0_class
{
    int* __thiscall BSOrderedNode_BSOrderedNode();
};

// @fnv 0x00bc2bd0
// src: XBOX_PDB 0x00bc2bd0
int* __thiscall FUN_00bc2bd0_class::BSOrderedNode_BSOrderedNode()
{
    FUN_00c5f570();
    *(int**)(char*)this = &DAT_010ba730;
    *(int*)((char*)this + 0xac) = *(int*)&_NiPoint3_ZERO;
    *(int*)((char*)this + 0xb0) = _DAT_011f4270;
    *(int*)((char*)this + 0xb4) = _DAT_011f4274;
    *(float*)((char*)this + 0xb8) = 0.0f;
    *(char*)((char*)this + 0xbc) = 0;
    return (int*)this;
}

// @fnv 0x00bc3040
// src: XBOX_PDB 0x00bc3040
void __fastcall BSMaterialEmittanceMultController_GetTargetFloatValue(void* self, int, float* out)
{
    *out = *(float*)((char*)*(int**)((char*)self + 0x2c) + 0x40);
}

void __stdcall NiFloatInterpController_GetViewerStrings(StrArr*);
struct GlobalObjectO2_00a7b610
{
    char* pData;
};
extern GlobalObjectO2_00a7b610 g_01201f90;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(char*);
// @fnv 0x00bc31f0
// src: XBOX_PDB 0x00bc31f0
void __stdcall BSMaterialEmittanceMultController_GetViewerStrings(StrArr* pStrArr)
{
    NiFloatInterpController_GetViewerStrings(pStrArr);
    char* p = NiViewerStrings_NiGetViewerString_Title(g_01201f90.pData);
    unsigned int i = *(unsigned short*)((char*)pStrArr + 0xa);
    unsigned int j = *(unsigned short*)((char*)pStrArr + 0x8);
    if (i >= j)
        pStrArr->SetSize(*(unsigned short*)((char*)pStrArr + 0xe) + i);
    pStrArr->SetAt(i, p);
}

// @fnv 0x00bd9150
// src: GUESS 0x00bd9150 (confidence: low)
void __fastcall Runtime_ReleaseStorage_00bd9150(void* p)
{
    g_memoryManager.Deallocate(*(void**)p);
}

struct ShadowSceneLight;

struct Shader_00bd9540
{
    char pad[0x3c];
    BSShaderProperty::ShaderPassList* pPasses;
    int BSShaderProperty_AddPass_Ambient(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count, unsigned char type, bool* out,
                     bool a, bool b, bool c, bool d);
};
// Selects a shader pass from the four bool flags and type, adds it to pPasses for type 1 or increments count otherwise, then sets out to false.
// @fnv 0x00bd9540
// src: COMMUNITY 0x00bd9540
int Shader_00bd9540::BSShaderProperty_AddPass_Ambient(NiGeometry* geom, ShadowSceneLight* light, unsigned short* pusCount,
                                  unsigned char type, bool* pbOut, bool a, bool b, bool c, bool d)
{
    if (!a)
    {
        if (b)
        {
            if (c)
            {
                if (type == 1)
                    pPasses->Add(geom, 0x5b, true, 1, light, 0, 0, 0);
                else
                    ++*pusCount;
            }
            else
            {
                if (type == 1)
                    pPasses->Add(geom, 0x5a, true, 1, light, 0, 0, 0);
                else
                    ++*pusCount;
            }
        }
        else
        {
            if (c)
            {
                if (type == 1)
                    pPasses->Add(geom, 0x59, true, 1, light, 0, 0, 0);
                else
                    ++*pusCount;
            }
            else if (!d)
            {
                if (type == 1)
                    pPasses->Add(geom, 0x58, true, 1, light, 0, 0, 0);
                else
                    ++*pusCount;
            }
            else
            {
                if (type == 1)
                    pPasses->Add(geom, 0x60, true, 1, light, 0, 0, 0);
                else
                    ++*pusCount;
            }
        }
    }
    else
    {
        if (b)
        {
            if (c)
            {
                if (type == 1)
                    pPasses->Add(geom, 0x5f, true, 1, light, 0, 0, 0);
                else
                    ++*pusCount;
            }
            else
            {
                if (type == 1)
                    pPasses->Add(geom, 0x5e, true, 1, light, 0, 0, 0);
                else
                    ++*pusCount;
            }
        }
        else
        {
            if (c)
            {
                if (type == 1)
                    pPasses->Add(geom, 0x5d, true, 1, light, 0, 0, 0);
                else
                    ++*pusCount;
            }
            else
            {
                if (type == 1)
                    pPasses->Add(geom, 0x5c, true, 1, light, 0, 0, 0);
                else
                    ++*pusCount;
            }
        }
    }
    *pbOut = false;
    return 0;
}

struct NiTexture;

struct ImageSpaceShaderParam
{
    void SetShaderConstantVector4(int, float, float, float, float);
};
extern float DAT_011ae614;
extern float DAT_011ae618;
extern float DAT_01201f2c;
extern float DAT_01201f30;
extern float DAT_01201f34;
extern float DAT_01201f38;
extern float DAT_01201f3c;
extern NiTexture* DAT_01201f40;
extern NiTexture* DAT_01201f44;
extern NiTexture* DAT_01201f48;
struct FUN_00bc0550_class
{
    char ApplyImageSpaceTextures(int);
};
// @fnv 0x00bc0550
char FUN_00bc0550_class::ApplyImageSpaceTextures(int)
{
    char* pTileTexture = (char*)*(char**)((char*)this + 0x2c);
    ((ImageSpaceTexture*)(*(char**)(pTileTexture + 0xc)))->SetTexture(DAT_01201f40);
    ((ImageSpaceTexture*)(*(char**)(*(char**)((char*)this + 0x2c) + 0x10)))->SetTexture(DAT_01201f48);
    ((ImageSpaceTexture*)(*(char**)(*(char**)((char*)this + 0x2c) + 8)))->SetTexture(DAT_01201f44);
    ImageSpaceShaderParam* p = (ImageSpaceShaderParam*)*(char**)*(char**)((char*)this + 0x1c);
    p->SetShaderConstantVector4(1, DAT_011ae614, DAT_01201f2c, DAT_011ae618, 0.0f);
    p->SetShaderConstantVector4(2, DAT_01201f30, DAT_01201f34, DAT_01201f38, DAT_01201f3c);
    return 0;
}

struct GlobalObjectO2_00a7b610_2
{
    char* pData;
};
extern GlobalObjectO2_00a7b610_2 g_01201f9c;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(char*);

// @fnv 0x00bc3450
// src: XBOX_PDB 0x00bc3450
void __stdcall BSRefractionFirePeriodController_GetViewerStrings(StrArr* pArray)
{
    NiFloatInterpController_GetViewerStrings((StrArr*)pArray);
    char* s = NiViewerStrings_NiGetViewerString_Title(g_01201f9c.pData);
    unsigned int i = *(unsigned short*)((char*)pArray + 0xa);
    if (i >= *(unsigned short*)((char*)pArray + 8))
        pArray->SetSize(i + *(unsigned short*)((char*)pArray + 0xe));
    pArray->SetAt(i, s);
}

// Adds a pass (0x1e5 or 0x1e6 depending on a and type) to pPasses, or increments count when type is not 1; clears out and returns 0.
// @fnv 0x00bd9e60
// src: COMMUNITY 0x00bd9e60
int __fastcall BSShaderProperty_AddPass_NormalsClear(Shader_00bd9540* self, int edx, NiGeometry* geom, unsigned short* count, unsigned char type,
                            bool* pbOut, bool a)
{
    if (!a)
    {
        if (type == 1)
        {
            self->pPasses->Add(geom, 0x1e5, *pbOut, 0, 0, 0, 0, 0);
            *pbOut = false;
            return 0;
        }
        ++*count;
        *pbOut = false;
        return 0;
    }
    if (type == 1)
    {
        self->pPasses->Add(geom, 0x1e6, *pbOut, 0, 0, 0, 0, 0);
        *pbOut = false;
        return 0;
    }
    ++*count;
    *pbOut = false;
    return 0;
}

struct FUN_00bd9f90_class : Shader_00bd9540
{
    int BSShaderProperty_AddPass_ZOnly_TexEffect(NiGeometry* geom, unsigned short* count, unsigned char type, bool* out, bool a);
};

// Adds geom to pPasses with pass 5 or 4 depending on a and type, or increments count when type is not 1; clears out and returns 0.
// @fnv 0x00bd9f90
// src: COMMUNITY 0x00bd9f90
int FUN_00bd9f90_class::BSShaderProperty_AddPass_ZOnly_TexEffect(NiGeometry* geom, unsigned short* count, unsigned char type, bool* pbOut, bool a)
{
    if (a)
    {
        if (type == 1)
        {
            pPasses->Add(geom, 5, *pbOut, false, 0, 0, 0, 0);
            *pbOut = false;
        }
        else
        {
            (*count)++;
            *pbOut = false;
        }
    }
    else
    {
        if (type == 1)
        {
            pPasses->Add(geom, 4, *pbOut, false, 0, 0, 0, 0);
            *pbOut = false;
        }
        else
        {
            (*count)++;
            *pbOut = false;
        }
    }
    return 0;
}

struct Shader_00bdf650
{
    BSShaderProperty::ShaderPassList* pPasses;
    void BSShaderPPLightingProperty_AddDepthMapPass_2x(NiGeometry* geom, bool a, bool b, ShadowSceneLight* light);
};

// Selects a pass index from the two bool flags and adds geom to the pass list at this+0x40 with the light from light+0x1a0.
// @fnv 0x00bdf650
// src: XBOX_PDB 0x00bdf650
void Shader_00bdf650::BSShaderPPLightingProperty_AddDepthMapPass_2x(NiGeometry* geom, bool abFirstFlag, bool abSecondFlag, ShadowSceneLight* light)
{
    ShadowSceneLight* l = (ShadowSceneLight*)*(int*)((char*)light + 0x1a0);
    if (!abFirstFlag)
    {
        if (!abSecondFlag)
            ((BSShaderProperty::ShaderPassList*)*(int*)((char*)this + 0x40))->Add(geom, 0x10, true, 1, l, 0, 0, 0);
        else
            ((BSShaderProperty::ShaderPassList*)*(int*)((char*)this + 0x40))->Add(geom, 0x11, true, 1, l, 0, 0, 0);
    }
    else
    {
        if (!abSecondFlag)
            ((BSShaderProperty::ShaderPassList*)*(int*)((char*)this + 0x40))->Add(geom, 0x12, true, 1, l, 0, 0, 0);
        else
            ((BSShaderProperty::ShaderPassList*)*(int*)((char*)this + 0x40))->Add(geom, 0x13, true, 1, l, 0, 0, 0);
    }
}

extern int DAT_011f91c0;
extern unsigned int DAT_01201f50;

// Initializes DAT_01201f50 to 75 plus 160 when DAT_011f91c0 is at least 2, then returns it.
// @fnv 0x00bc0b40
// src: COMMUNITY 0x00bc0b40
unsigned int __cdecl BoltShader_GetMaxSegments()
{
    if (DAT_01201f50 == 0)
        DAT_01201f50 = 75 + ((DAT_011f91c0 < 2) ? 0 : 160);
    return DAT_01201f50;
}

struct FUN_00bc0c70_class
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
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void v7d();
    virtual void v7e();
    virtual void v7f();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v8a();
    virtual void v8b();
    virtual void v8c();
    virtual void v8d();
    virtual void v8e();
    virtual void v8f();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v9a();
    virtual void v9b();
    virtual void v9c();
    virtual void v9d();
    virtual void v9e();
    virtual void v9f();
    virtual void vaa();
    virtual void vab();
    virtual void vac();
    virtual void vad();
    virtual void vae();
    virtual void vaf();
    virtual void vb0();
    virtual void vb1();
    virtual void vb2();
    virtual void vb3();
    virtual void vb4();
    virtual void vb5();
    virtual void vb6();
    virtual void vb7();
    virtual void vb8();
    virtual void vb9();
    virtual void vba();
    virtual void vbb();
    virtual void vbc();
    virtual void vbd();
    virtual void vbe();
    virtual void vbf();
    virtual void vc0();
    virtual void vc1();
    virtual void vc2();
    virtual void vc3();
    virtual void vc4();
    virtual void vc5();
    virtual void vc6();
    virtual void vc7();
    virtual void vc8();
    virtual void vc9();
    virtual void vca();
    virtual void vcb();
    virtual void vcc();
    virtual void vcd();
    virtual void vce();
    virtual void vcf();
    virtual void vd0();
    virtual void vd1();
    virtual void vd2();
    virtual void vd3();
    virtual void vd4();
    virtual void vd5();
    virtual void vd6();
    virtual void vd7();
    virtual void vd8();
    virtual void vd9();
    virtual void vda();
    virtual void vdb();
    virtual void vdc();
    virtual void vdd();
    virtual void vde();
    virtual void vdf();
    virtual void ve0();
    virtual void ve1();
    virtual void ve2();
    virtual void ve3();
    virtual void ve4();
    virtual void ve5();
    virtual void ve6();
    virtual void ve7();
    virtual void ve8();
    virtual void ve9();
    virtual void vea();
    virtual void veb();
    virtual void vec();
    virtual void ved();
    virtual void vee();
    virtual void vef();
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vfa();
    virtual void vfb();
    virtual void vfc();
    virtual void vfd();
    virtual void vfe();
    virtual void vff();
    int CallVirtual128WithField168();
};
// @fnv 0x00bc0c70
int FUN_00bc0c70_class::CallVirtual128WithField168()
{
    void** vt = *(void***)this;
    void* e = *(void**)((char*)this + 0x168);
    return ((int(__thiscall*)(void*, void*))vt[0x128 / 4])(this, e);
}

struct FUN_00bc1c70_class
{
    char pad[0x78];
    int m_field78;
    int m_field7c;
    char pad2[0x140 - 0x80];
    int m_field140;
    char pad3[0x174 - 0x144];
    char m_field174;
    char pad4[0x184 - 0x175];
    int m_field184;
    void BoltShaderProperty_CleanupSegments(int arg);
};

// @fnv 0x00bc1c70
// src: COMMUNITY 0x00bc1c70
void FUN_00bc1c70_class::BoltShaderProperty_CleanupSegments(int aiAmount)
{
    int divisor = m_field140;
    int rem = aiAmount % divisor;
    m_field78 += rem;
    if (m_field174 != 0 && m_field78 >= divisor)
    {
        m_field78 -= divisor;
        m_field174 = 0;
    }
    m_field184 -= rem;
    if (m_field174 == 0 && m_field78 >= m_field7c)
        m_field78 = m_field7c;
}

int __cdecl __ftol2_sse();

struct FUN_00bc1cc0_class
{
    char pad0000[0x70];
    float m_f70;
    char pad0074[4];
    int m_i78;
    int m_i7c;
    char pad0080[0xC0];
    int m_i140;
    char pad0144[0x30];
    unsigned char m_b174;
    char pad0175[0x0B];
    float m_f180;
    int m_i184;
    int m_i188;

    void __thiscall BoltShaderProperty_CleanupBolt(float f1, float f2);
};

// Advances m_i78 by a remainder derived from f1 and m_i188/m_f70, clamps it, decrements m_i184 and adds f1*f2 to m_f180.
// @fnv 0x00bc1cc0
// src: COMMUNITY 0x00bc1cc0
void __thiscall FUN_00bc1cc0_class::BoltShaderProperty_CleanupBolt(float f1, float f2)
{
    float fProduct = f1 * f2;
    int iValue = (int)(f1 * (m_i188 / m_f70));
    if (!(iValue > 0))
        iValue = 1;

    int iRemainder = iValue % m_i140;
    m_i78 += iRemainder;

    if (m_b174 != 0 && m_i78 >= m_i140)
    {
        m_i78 -= m_i140;
        m_b174 = 0;
    }

    if (m_b174 == 0 && m_i78 >= m_i7c)
        m_i78 = m_i7c;

    m_i184 -= iRemainder;
    m_f180 += fProduct;
}

struct FUN_00bc3240_class
{
    void BSRefractionFirePeriodController_GetTargetFloatValue(float* out);
};
// @fnv 0x00bc3240
// src: XBOX_PDB 0x00bc3240
void FUN_00bc3240_class::BSRefractionFirePeriodController_GetTargetFloatValue(float* out)
{
    *out = *reinterpret_cast<long*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x2c) + 0xe4);
}

// @fnv 0x00bc3340
// src: XBOX_PDB 0x00bc3340
GlobalObjectO2_00a7b610_2* __cdecl BSRefractionFirePeriodController_GetRTTI()
{
    return &g_01201f9c;
}

struct GlobalObjectO2_00a7b610_3
{
    char* pData;
};
extern GlobalObjectO2_00a7b610_3 g_01201fa8;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(char*);

// @fnv 0x00bc3700
// src: XBOX_PDB 0x00bc3700
void __stdcall BSRefractionStrengthController_GetViewerStrings(StrArr* pStrArr)
{
    NiFloatInterpController_GetViewerStrings(pStrArr);
    char* p = NiViewerStrings_NiGetViewerString_Title(g_01201fa8.pData);
    unsigned int idx = *(unsigned short*)((char*)pStrArr + 0xa);
    unsigned int size = *(unsigned short*)((char*)pStrArr + 8);
    if (idx >= size)
        pStrArr->SetSize(*(unsigned short*)((char*)pStrArr + 0xe) + idx);
    pStrArr->SetAt(idx, p);
}

struct FUN_00bc3750_class : BSShaderProperty
{
    // BSShaderProperty does not yet declare its stream override.
    void BSShaderProperty_LoadBinary(NiStream&);
    void LoadFromStream(NiStream& stream);
};
// @fnv 0x00bc3750
void FUN_00bc3750_class::LoadFromStream(NiStream& stream)
{
    BSShaderProperty_LoadBinary(stream);
    ((void (__thiscall*)(NiColorA*, NiStream&))NiColorA_LoadBinary)((NiColorA*)((char*)this + 0x60), stream);
}

void __cdecl FUN_00bc39f0();
struct FUN_00bc3d80_class
{
    void* FUN_00bc3d80(int flags);
};
// Calls FUN_00bc39f0, then if flags has bit 0 set deletes this with size 0x180, and returns this.
// @fnv 0x00bc3d80
void* FUN_00bc3d80_class::FUN_00bc3d80(int flags)
{
    FUN_00bc39f0();
    if (flags & 1)
        _delete(this, 0x180);
    return this;
}

struct FUN_00bc4810_class
{
    int* vtbl;
    void CallVtblSlot74WithFieldB4();
};

// @fnv 0x00bc4810
void FUN_00bc4810_class::CallVtblSlot74WithFieldB4()
{
    ((void(__thiscall*)(void*, int))(vtbl[74]))(this, *(int*)((char*)this + 0xb4));
}

void __cdecl FUN_00bcd4a0();

struct FUN_00bce7d0_class
{
    FUN_00bce7d0_class* __thiscall FUN_00bce7d0(int flags);
};

// @fnv 0x00bce7d0
FUN_00bce7d0_class* FUN_00bce7d0_class::FUN_00bce7d0(int flags)
{
    FUN_00bcd4a0();
    if (flags & 1)
        _delete(this, 0x160);
    return this;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct RefObject
{
    virtual void Unused() = 0;
    virtual void Release() = 0;

    long m_iObjectReferenceCount;
};

extern NiD3DPass* DAT_012022c0;
extern GlobalObjectO2_00a7b610 g_01202328;

struct FUN_00bcfa50_class : NiShader
{
    char m_auiShapeKeys[0x78];
    RefObject* m_pObjects[26];
    RefObject* m_pOtherObjects[13];

    bool ReleaseAllReferences();
};

// Initializes the shader, then releases and clears all referenced objects in m_pObjects, m_pOtherObjects and the DAT_012022c0 pass array, returning true.
// @fnv 0x00bcfa50
bool FUN_00bcfa50_class::ReleaseAllReferences()
{
    NiShader::Initialize();

    for (int i = 0; i < 26; ++i)
    {
        RefObject* object = m_pObjects[i];
        if (object)
        {
            if (InterlockedDecrement(&object->m_iObjectReferenceCount) == 0)
                object->Release();
            m_pObjects[i] = 0;
        }
    }

    for (int i = 0; i < 13; ++i)
    {
        RefObject* object = m_pOtherObjects[i];
        if (object)
        {
            if (InterlockedDecrement(&object->m_iObjectReferenceCount) == 0)
                object->Release();
            m_pOtherObjects[i] = 0;
        }
    }

    NiD3DPass** pass = &DAT_012022c0;
    NiD3DPass** end = (NiD3DPass**)&g_01202328;
    do
    {
        NiD3DPass* pPass = *pass;
        if (pPass)
        {
            if (--pPass->m_uiRefCount == 0)
                pPass->DestroyPass();
            *pass = 0;
        }
        ++pass;
    } while (reinterpret_cast<long>(pass) < reinterpret_cast<long>(end));

    return true;
}

struct FUN_00bd1480_t
{
    void FUN_00bd0ce0();
    void* FUN_00bd1480(int flags);
};
// Calls FUN_00bd0ce0, then deletes this with size 0xec when flags has bit 0 set, and returns this.
// @fnv 0x00bd1480
void* FUN_00bd1480_t::FUN_00bd1480(int flags)
{
    FUN_00bd0ce0();
    if (flags & 1)
        operator delete(this, 0xec);
    return this;
}

struct FUN_00bd5d70_Class
{
    char pad[0xc];
    unsigned short m_usElementCount;  // +0xc
    unsigned short m_usMax;           // +0xe
    void* m_pData;                    // +0x10
    void* m_pDataEnd;                 // +0x14
    char DistantLODGroup_Add(void* src, unsigned int idx);
};

// @fnv 0x00bd5d70
// src: COMMUNITY 0x00bd5d70
char FUN_00bd5d70_Class::DistantLODGroup_Add(void* pSource, unsigned int uiIndex)
{
    if (m_usMax == m_usElementCount || pSource == 0)
        return 0;
    unsigned int off = (unsigned int)m_usMax << 4;
    char* dst = (char*)m_pData + off;
    *(unsigned int*)(dst + 0) = *(unsigned int*)((char*)pSource + 0);
    *(unsigned int*)(dst + 4) = *(unsigned int*)((char*)pSource + 4);
    *(unsigned int*)(dst + 8) = *(unsigned int*)((char*)pSource + 8);
    *(unsigned int*)(dst + 0xc) = *(unsigned int*)((char*)pSource + 0xc);
    ((unsigned int*)m_pDataEnd)[m_usMax] = uiIndex;
    m_usMax++;
    return 1;
}

struct ISTex
{
    char pad[0x10];
    void CreateRenderTargetTexture(unsigned int);
};

struct ImageSpaceTextureReturnHelper
{
    void AddRenderedTexture();
};

struct FUN_00bd6980_class
{
    char pad_00[0x28];
    NiTPrimitiveArray<int> m_Array;
    char pad_38[0x24];  // Array is 0x10 bytes; the next original field is at 0x5c.
    char* m_pFlagOwner;
    char pad_5c[0x1c];
    char m_RenderedTexture[0x10];
    ISTex m_Texture1;
    ISTex m_Texture2;
    char m_Texture[0x10];

    void UpdateTextures(int);
};

// @fnv 0x00bd6980
void FUN_00bd6980_class::UpdateTextures(int)
{
    int value;

    value = reinterpret_cast<int>(&m_Texture1);
    m_Texture1.CreateRenderTargetTexture(0x25);
    m_Array.SetAt(2, value);

    value = reinterpret_cast<int>(&m_Texture2);
    m_Texture2.CreateRenderTargetTexture(0x26);
    m_Array.SetAt(3, value);

    if (m_pFlagOwner[3] != 0)
    {
        value = reinterpret_cast<int>(m_RenderedTexture);
        m_Array.SetAt(5, value);
    }
    else
    {
        reinterpret_cast<ImageSpaceTextureReturnHelper*>(m_RenderedTexture)->AddRenderedTexture();
        value = 0;
        m_Array.SetAt(5, value);
    }

    value = reinterpret_cast<int>(m_Texture);
    reinterpret_cast<ImageSpaceTexture*>(m_Texture)->SetTexture(reinterpret_cast<NiTexture*>(GetImageSpaceTexture()));
    m_Array.SetAt(4, value);
}

struct FUN_00bd6f30_class
{
    void FUN_00bd6f30();
};
struct FUN_00bd6fa0_class : FUN_00bd6f30_class
{
    FUN_00bd6fa0_class* FUN_00bd6fa0(char aFlag);
};
// @fnv 0x00bd6fa0
FUN_00bd6fa0_class* FUN_00bd6fa0_class::FUN_00bd6fa0(char aFlag)
{
    FUN_00bd6f30();
    if (aFlag & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

extern MemoryManager g_memoryManager;
struct FUN_00bd71e0_class
{
    void FUN_00bd6fc0();
    void* FUN_00bd71e0(int bFlag);
};
// @fnv 0x00bd71e0
void* FUN_00bd71e0_class::FUN_00bd71e0(int bFlag)
{
    FUN_00bd6fc0();
    if (bFlag & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct FUN_00bd8550_Class
{
    char pad0[0x10];
    unsigned short m_usElementCount;  // +0x10
    unsigned short m_usIndex;         // +0x12
    void* m_pData;                    // +0x14
    int* m_pEntryData;                // +0x18
    bool PushEntry(void* src, int value);
};

// @fnv 0x00bd8550
bool FUN_00bd8550_Class::PushEntry(void* src, int value)
{
    if (m_usIndex != m_usElementCount && src)
    {
        unsigned int idx = m_usIndex;
        void* dst = (char*)m_pData + (idx << 4);
        *(int*)dst = *(int*)src;
        *(int*)((char*)dst + 4) = *(int*)((char*)src + 4);
        *(int*)((char*)dst + 8) = *(int*)((char*)src + 8);
        *(int*)((char*)dst + 0xc) = *(int*)((char*)src + 0xc);
        m_pEntryData[m_usIndex] = value;
        m_usIndex++;
        return true;
    }
    return false;
}

namespace fnv_00bd9230 {
struct ISTex
{
    void* GetTexture();
};
// @fnv 0x00bd9230
// src: COMMUNITY 0x00bd9230
int __fastcall ImageSpaceEffectRefraction_IsActive(ISTex* p, int)
{
    return !((ISTex*)((char*)p + 0x58))->GetTexture() ? 0 : 1;
}
}  // namespace fnv_00bd9230

struct FUN_00bd9d00_class
{
    char pad[0x3c];
    BSShaderProperty::ShaderPassList* pPasses;

    int __thiscall BSShaderProperty_TexEffect(NiGeometry* geom, unsigned short* count, unsigned char type, bool* enabled, bool flag);
};

// Adds a pass to pPasses for type 1 (0x24f when flag is set, else 0x24e), otherwise increments *count, and clears *enabled; returns 0.
// @fnv 0x00bd9d00
// src: COMMUNITY 0x00bd9d00
int __thiscall FUN_00bd9d00_class::BSShaderProperty_TexEffect(NiGeometry* geom, unsigned short* count, unsigned char type,
                                                bool* enabled, bool flag)
{
    if (flag)
    {
        if (type == 1)
        {
            pPasses->Add(geom, 0x24f, *enabled, 0, 0, 0, 0, 0);
            *enabled = false;
        }
        else
        {
            ++(*count);
            *enabled = false;
        }
    }
    else
    {
        if (type == 1)
        {
            pPasses->Add(geom, 0x24e, *enabled, 0, 0, 0, 0, 0);
            *enabled = false;
        }
        else
        {
            ++(*count);
            *enabled = false;
        }
    }

    return 0;
}

struct FUN_00bdc030_class
{
    char pad[0x3c];
    BSShaderProperty::ShaderPassList* pPasses;

    int __thiscall BSShaderProperty_AddPass_2x_TexEffect(NiGeometry* geometry, unsigned short* count, unsigned char type, bool* out, bool flag);
};

// Adds geometry to pPasses with pass id 0x251 or 0x250 when type is 1, otherwise increments count; always clears out and returns 0.
// @fnv 0x00bdc030
// src: COMMUNITY 0x00bdc030
int __thiscall FUN_00bdc030_class::BSShaderProperty_AddPass_2x_TexEffect(NiGeometry* geometry, unsigned short* count, unsigned char type,
                                                bool* out, bool flag)
{
    if (flag)
    {
        if (type == 1)
        {
            pPasses->Add(geometry, 0x251, *out, false, 0, 0, 0, 0);
            *out = false;
            return 0;
        }

        ++(*count);
        *out = false;
        return 0;
    }

    if (type == 1)
    {
        pPasses->Add(geometry, 0x250, *out, false, 0, 0, 0, 0);
        *out = false;
        return 0;
    }

    ++(*count);
    *out = false;
    return 0;
}

struct FUN_00bd0f70_RefObject
{
    // Virtual destructor for the reference object; does nothing.
// @fnv 0x00bd0f70
    virtual ~FUN_00bd0f70_RefObject()
    {}
    virtual void DeleteThis()
    {}
};

struct FUN_00bd0f70_class : public NiShader
{
    bool HairShader_Initialize();
};

// src: COMMUNITY 0x00bd0f70
bool FUN_00bd0f70_class::HairShader_Initialize()
{
    NiShader::Initialize();

    FUN_00bd0f70_RefObject** objects = reinterpret_cast<FUN_00bd0f70_RefObject**>(reinterpret_cast<char*>(this) + 0x94);
    int count = 7;
    do
    {
        FUN_00bd0f70_RefObject* object = *objects;
        if (object)
        {
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(reinterpret_cast<char*>(object) + 4)) == 0)
                object->DeleteThis();
            *objects = 0;
        }
        ++objects;
        --count;
    } while (count);

    objects = reinterpret_cast<FUN_00bd0f70_RefObject**>(reinterpret_cast<char*>(this) + 0xBC);
    count = 7;
    do
    {
        FUN_00bd0f70_RefObject* object = *objects;
        if (object)
        {
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(reinterpret_cast<char*>(object) + 4)) == 0)
                object->DeleteThis();
            *objects = 0;
        }
        ++objects;
        --count;
    } while (count);

    objects = reinterpret_cast<FUN_00bd0f70_RefObject**>(reinterpret_cast<char*>(this) + 0xB0);
    count = 3;
    do
    {
        FUN_00bd0f70_RefObject* object = *objects;
        if (object)
        {
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(reinterpret_cast<char*>(object) + 4)) == 0)
                object->DeleteThis();
            *objects = 0;
        }
        ++objects;
        --count;
    } while (count);

    objects = reinterpret_cast<FUN_00bd0f70_RefObject**>(reinterpret_cast<char*>(this) + 0xD8);
    count = 3;
    do
    {
        FUN_00bd0f70_RefObject* object = *objects;
        if (object)
        {
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(reinterpret_cast<char*>(object) + 4)) == 0)
                object->DeleteThis();
            *objects = 0;
        }
        ++objects;
        --count;
    } while (count);

    NiD3DPass** passes = reinterpret_cast<NiD3DPass**>(reinterpret_cast<char*>(this) + 0x8C);
    count = 2;
    do
    {
        NiD3DPass* pass = *passes;
        if (pass)
        {
            int* refCount = reinterpret_cast<int*>(reinterpret_cast<char*>(pass) + 0x64);
            if (--*refCount == 0)
                pass->DestroyPass();
            *passes = 0;
        }
        ++passes;
        --count;
    } while (count);

    return true;
}

class BC0500RefObject
{
  public:
    virtual ~BC0500RefObject();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};

extern StagingNiPointer<BC0500RefObject> g_spBC0500Shared;

class BC0500Effect
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
    ImageSpaceTexture** m_ppTextures;

    void ReleaseTextures();
};

// Clears the shared pointer and, for each of the 5 textures, releases its texture via SetTexture(0).
// @fnv 0x00bc0500
void BC0500Effect::ReleaseTextures()
{
    g_spBC0500Shared = 0;
    for (int i = 0; i < 5; i++)
    {
        ImageSpaceTexture* pkTexture = m_ppTextures[i];
        if (pkTexture)
            pkTexture->SetTexture(0);
    }
}

struct S_00bc0920_Class;

typedef void(__thiscall* S_00bc0920_FN)(S_00bc0920_Class*);

struct S_00bc0920_VTable
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4c;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5c;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6c;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7c;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8c;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9c;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAc;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBc;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCc;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDc;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEc;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFc;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10c;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11c;
    void* unk120;
    void* unk124;
    void* unk128;
    void* unk12c;
    void* unk130;
    void* unk134;
    void* unk138;
    S_00bc0920_FN unk13c;
    S_00bc0920_FN unk140;
};

struct S_00bc0920_Class
{
    S_00bc0920_VTable* vtbl;
    void CallVTableSlots13cAnd140();
};

// @fnv 0x00bc0920
void S_00bc0920_Class::CallVTableSlots13cAnd140()
{
    this->vtbl->unk13c(this);
    this->vtbl->unk140(this);
}

extern "C" void* __cdecl fnv_zlib_memset(void* dst, int value, unsigned int size);
int __cdecl sprintf_s(char* buffer, unsigned int size, const char* format, ...);

struct ShaderObject
{
    virtual void Destroy();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

void __cdecl FUN_00be0c00(const char* src, char* dst);

struct ShaderMacroInfo
{
    int iCount;
    int iFlags;
    char acData[64];
};

struct ShaderDesc
{
    const char* pcFile;
    ShaderMacroInfo kInfo;
    ShaderDesc(const char* file) : pcFile(file)
    {
        kInfo.iCount = 0;
        kInfo.iFlags = 0;
        fnv_zlib_memset(kInfo.acData, 0, sizeof(kInfo.acData));
    }
};

struct BoltShader
{
    void* vtbl;
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
    StagingNiPointer<ShaderObject> m_spTreeVertexShader;
    StagingNiPointer<ShaderObject> m_spPixelShaderVariants;

    ShaderObject* CreateVS(char* path, ShaderMacroInfo* info, const char* profile, char* name);
    ShaderObject* CreatePS(char* path, ShaderMacroInfo* info, const char* profile, char* name);
    void CreateShaders();
};

// Builds the vertex and pixel shader paths and names, then creates the VS and PS and stores them in the two shader pointers.
// @fnv 0x00bc09b0
void BoltShader::CreateShaders()
{
    char acPath[260];
    char acName[260];

    ShaderDesc kVS("bolt\\v\\bolt.v.hlsl");
    FUN_00be0c00(kVS.pcFile, acPath);
    sprintf_s(acName, 260, "BOLT.vso");
    m_spTreeVertexShader = CreateVS(acPath, &kVS.kInfo, "vs_1_1", acName);

    const char* pcPixelProfile = NiD3DGPUProgramCache::GetPixelShaderProfile(true);
    ShaderDesc kPS("bolt\\p\\bolt.p.hlsl");
    FUN_00be0c00(kPS.pcFile, acPath);
    sprintf_s(acName, 260, "BOLT.pso");
    m_spPixelShaderVariants = CreatePS(acPath, &kPS.kInfo, pcPixelProfile, acName);
}

struct BC1BA0Cell
{
    int unk00;
    float m_fValue;
    int unk08;
    int unk0C;
};

class BC1BA0Graph
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    BC1BA0Cell* m_pkCells;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int m_iStart;
    int m_iEnd;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    int m_iRows;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int m_iColumns;
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
    bool m_bWrapped;

    void AddValueToColumnRange(float fTimeSinceScaleStart);
};

// @fnv 0x00bc1ba0
void BC1BA0Graph::AddValueToColumnRange(float afDelta)
{
    bool bWrap = m_bWrapped;
    int i = m_iStart;
    while ((bWrap && i < m_iColumns) || i <= m_iEnd)
    {
        for (int j = 0; j < m_iRows; j++)
        {
            int iIndex = j * m_iColumns + i;
            m_pkCells[iIndex].m_fValue = m_pkCells[iIndex].m_fValue + afDelta;
        }
        if (++i >= m_iColumns && bWrap)
        {
            i = 0;
            bWrap = false;
        }
    }
}

class BC1C10Graph
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int m_iStart;
    int m_iEnd;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    int m_iColumns;
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
    bool m_bWrapped;
    unsigned char unk175;
    unsigned char unk176;
    unsigned char unk177;
    int unk178;
    int unk17C;
    int unk180;
    int m_iTotal;

    void RemoveFromEnd(int iCount);
};

// Removes iCount modulo m_iColumns entries from the end, adjusting m_iEnd, m_iStart, m_bWrapped and m_iTotal.
// @fnv 0x00bc1c10
void BC1C10Graph::RemoveFromEnd(int iCount)
{
    int iRemove = iCount % m_iColumns;
    m_iEnd -= iRemove;
    if (m_bWrapped && m_iEnd < 0)
    {
        m_iStart += m_iColumns;
        m_bWrapped = false;
    }
    if (!m_bWrapped)
    {
        m_iTotal -= iRemove;
        if (m_iEnd <= m_iStart)
            m_iEnd = m_iStart;
    }
    else
    {
        m_iTotal -= iRemove;
    }
}

// FUN_00bc1f90 : a one-line function - getter
extern int g_target_00bc1f90;
// @fnv 0x00bc1f90
// src: XBOX_PDB 0x00bc1f90
void* BoltShaderProperty_GetRTTI()
{
    return &g_target_00bc1f90;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct SpawnedBase_b10020
{
    char unk00[0x190];
};

struct SpawnedObj_b10020 : SpawnedBase_b10020
{
    SpawnedObj_b10020();
    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};

struct FUN_00bc2020_cls : BSShaderProperty
{
    SpawnedBase_b10020* BoltShaderProperty_CreateClone(unsigned int arg);
};

// Allocates a SpawnedObj_b10020, initializes it via FUN_00ba8b10 with arg, and returns it as a SpawnedBase_b10020 pointer.
// @fnv 0x00bc2020
// src: XBOX_PDB 0x00bc2020
SpawnedBase_b10020* FUN_00bc2020_cls::BoltShaderProperty_CreateClone(unsigned int arg)
{
    SpawnedBase_b10020* obj = new SpawnedObj_b10020();
    CopyMemberData(reinterpret_cast<BSShaderProperty*>(obj), reinterpret_cast<CloningProcess*>(arg));
    return obj;
}

struct FUN_00bc2540_class : BSShaderProperty
{
    BSShaderProperty::ShaderPassList* __thiscall BoltShaderProperty_GetRenderPasses(NiGeometry* geom, int a0C, int a10, int a14, int a18, int a1C);
};
// @fnv 0x00bc2540
// src: XBOX_PDB 0x00bc2540
BSShaderProperty::ShaderPassList* FUN_00bc2540_class::BoltShaderProperty_GetRenderPasses(NiGeometry* geom, int a0C, int a10, int a14, int a18, int a1C)
{
    CheckCreateRenderPassArray(1);
    BSShaderProperty::ShaderPassList* passes = static_cast<BSShaderProperty::ShaderPassList*>(pRenderPassList);
    if (passes->m_uiCount == 0)
    {
        passes->Add(geom, 0x242, true, 0, 0, 0, 0, 0);
        passes = static_cast<BSShaderProperty::ShaderPassList*>(pRenderPassList);
        BSShaderProperty::ShaderPassEntry* last = passes->m_kRenderPasses.m_pBase[passes->m_uiCount - 1];
        last->m_ucLightIndex = 1;
    }
    return static_cast<BSShaderProperty::ShaderPassList*>(pRenderPassList);
}

// FUN_00bc2590: ring-buffer advance loop, thiscall, one int count parameter.
class FUN_00bc2590_cls
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int m_74;
    int m_78;
    int m_7c;
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
    int m_128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int m_140;
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
    bool m_174;
    unsigned char unk175;
    unsigned char unk176;
    unsigned char unk177;
    void BoltShaderProperty_CreateSegment(int i, int cursor, int prev, int wrap);
    void BoltShaderProperty_ExtendSegments(int count);
};

// Advances m_7c by count steps, wraps it at m_140, keeps m_78 in sync, sets m_174, and calls FUN_00bc20a0 for each of m_128 entries.
// @fnv 0x00bc2590
// src: COMMUNITY 0x00bc2590
void FUN_00bc2590_cls::BoltShaderProperty_ExtendSegments(int count)
{
    int step = 1;
    if (count > 0)
    {
        int remaining = count;
        do
        {
            m_7c += step;
            if (m_7c >= m_140)
            {
                m_7c = 0;
            }
            int cursor = m_7c;
            if (cursor == m_78)
            {
                m_78 += step;
                if (m_78 >= m_140)
                {
                    m_78 -= m_140;
                }
            }
            m_174 = m_78 > cursor;
            for (int i = 0; i < m_128; i += step)
            {
                int prev;
                if (cursor == 0)
                {
                    prev = m_174 ? m_140 - step : 0;
                }
                else
                {
                    prev = cursor - step;
                }
                int wrap;
                if (cursor < m_74)
                {
                    wrap = m_174 ? m_140 - m_74 + cursor : 0;
                }
                else
                {
                    wrap = cursor - m_74;
                }
                BoltShaderProperty_CreateSegment(i, cursor, prev, wrap);
            }
            remaining -= step;
        } while (remaining != 0);
    }
}

struct S_00bc2ae0_Foo
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    BSShaderAccumulator* unkC4;
};

extern void __stdcall NiNode_OnVisible(S_00bc2ae0_Foo*);

// @fnv 0x00bc2ae0
// src: XBOX_PDB 0x00bc2ae0
void __stdcall BSClearZNode_OnVisible(S_00bc2ae0_Foo* pFoo)
{
    BSShaderAccumulator* target = pFoo->unkC4;

    if (target)
    {
        target->bAccumulate = 0;
        target->_unverified_eAccumulationMode = BSShaderAccumulator::BSSA_ACCUMLOD;
    }

    NiNode_OnVisible(pFoo);

    if (target)
    {
        target->bAccumulate = 1;
        target->_unverified_eAccumulationMode = BSShaderAccumulator::BSSA_ACCUMNORMAL;
    }
}

struct FUN_00bc2c50_class
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    float unkB8;
    unsigned char unkBC;

    void __thiscall ForwardToBase(FUN_00bc2c50_class* destination, int value);

    void __thiscall CopyTailFields(FUN_00bc2c50_class* destination, int value);
};

// Calls ForwardToBase, then copies unkAC through unkBC from this object into destination.
// @fnv 0x00bc2c50
void __thiscall FUN_00bc2c50_class::CopyTailFields(FUN_00bc2c50_class* destination, int value)
{
    ForwardToBase(destination, value);

    float copiedValue = unkB8;

    destination->unkAC = unkAC;
    destination->unkB0 = unkB0;
    destination->unkB4 = unkB4;
    destination->unkB8 = copiedValue;
    destination->unkBC = unkBC;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct SpawnedObj_b9965
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
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
    SpawnedObj_b9965();
    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};

// Allocates and constructs a new SpawnedObj_b9965 via its operator new and returns the pointer.
// @fnv 0x00bc2cb0
// src: EXE 0x00bc2cb0
SpawnedObj_b9965* BSOrderedNode_CreateObject()
{
    return new SpawnedObj_b9965();
}

struct FUN_00bc2d20_sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    bool Object_HasEqualFloatComponents(void* other);
};

struct FUN_00bc2d20_cls
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
    FUN_00bc2d20_sub m_ac;
    unsigned char m_bc;
    bool NiNode_IsEqual(FUN_00bc2d20_cls* other);
    unsigned char Equals(FUN_00bc2d20_cls* other);
};

// Compares this object with another: checks FUN_00a5e600, m_bc equality, and if m_bc is nonzero delegates to m_ac.FUN_00a92660.
// @fnv 0x00bc2d20
unsigned char FUN_00bc2d20_cls::Equals(FUN_00bc2d20_cls* other)
{
    unsigned char ok = NiNode_IsEqual(other);
    if (ok)
    {
        if (m_bc != other->m_bc)
            return 0;
        if (m_bc != 0)
            return m_ac.Object_HasEqualFloatComponents(&other->m_ac);
        ok = 1;
    }
    return ok;
}

struct CpuOpaque;
extern CpuOpaque DAT_01201f90;
// @fnv 0x00bc3100
// src: XBOX_PDB 0x00bc3100
CpuOpaque* __cdecl BSMaterialEmittanceMultController_GetRTTI()
{
    return &DAT_01201f90;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct SpawnedBase_b9523
{
    virtual void unk00();
    char unk04[0x34];
    SpawnedBase_b9523();
};

struct SpawnedObj_b9523 : SpawnedBase_b9523
{
    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};

struct FUN_00bc3110_cls
{
    void FUN_00a57620(SpawnedBase_b9523* p, unsigned int arg);
    SpawnedBase_b9523* BSMaterialEmittanceMultController_CreateClone(unsigned int arg);
};

// Allocates a SpawnedObj_b9523, initializes it via FUN_00a57620 with arg, and returns it as a SpawnedBase_b9523 pointer.
// @fnv 0x00bc3110
// src: XBOX_PDB 0x00bc3110
SpawnedBase_b9523* FUN_00bc3110_cls::BSMaterialEmittanceMultController_CreateClone(unsigned int arg)
{
    SpawnedBase_b9523* p = new SpawnedObj_b9523();
    FUN_00a57620(p, arg);
    return p;
}

struct StrListNode
{
    void* m_pData;
    StrListNode* m_pNext;
};

struct StrListOwner
{
    virtual void v0();
    virtual void v1();
    virtual StrListNode* v2();
};

extern char g_sentinel_011fa010;

// Walks the linked list returned by the object's v2() and returns true if it reaches the sentinel node, false otherwise or when pObj is null.
// @fnv 0x00bc3260
bool __stdcall ContainsSentinelNode(void* apListOwner)
{
    if (apListOwner == 0)
        return false;
    StrListNode* pNode = ((StrListOwner*)apListOwner)->v2();
    while (pNode != 0)
    {
        if (pNode == (StrListNode*)&g_sentinel_011fa010)
            return true;
        pNode = pNode->m_pNext;
    }
    return false;
}

class BBC3370CloningProcess;

class BBC3370Object
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
};

class BBC3370Controller : public BBC3370Object
{
  public:
    BBC3370Controller();
    virtual ~BBC3370Controller();

    void CopyMemberData(BBC3370Controller* pkDest, BBC3370CloningProcess& kCloning);

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
};

class BBC3370DerivedController : public BBC3370Controller
{
  public:
    BBC3370DerivedController()
    {}
    virtual ~BBC3370DerivedController();

    BBC3370Controller* BSRefractionFirePeriodController_CreateClone(BBC3370CloningProcess& kCloning);
};

// @fnv 0x00bc3370
// src: XBOX_PDB 0x00bc3370
BBC3370Controller* BBC3370DerivedController::BSRefractionFirePeriodController_CreateClone(BBC3370CloningProcess& kCloning)
{
    BBC3370DerivedController* pkClone = new BBC3370DerivedController;
    CopyMemberData(pkClone, kCloning);
    return pkClone;
}

extern void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern void __fastcall FUN_00a57640(void* self);
extern void* DAT_010ba948;

void* __cdecl operator new(unsigned int size)
{
    return Object_DispatchCommandFour(size);
}

struct Base_00a57640
{
    void* m_pvt;
};

struct Derived_00bc33f0 : Base_00a57640
{
    char pad04[0x34];

    Derived_00bc33f0()
    {
        FUN_00a57640(this);
        m_pvt = (void*)&DAT_010ba948;
    }
};

// Allocates a Derived_00bc33f0 object with operator new and returns it after its constructor runs.
// @fnv 0x00bc33f0
Derived_00bc33f0* __cdecl CreateDerived()
{
    return new Derived_00bc33f0();
}

struct CpuOpaque;
extern CpuOpaque DAT_01201fa8;
// @fnv 0x00bc3610
// src: XBOX_PDB 0x00bc3610
CpuOpaque* __cdecl BSRefractionStrengthController_GetRTTI()
{
    return &DAT_01201fa8;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct Base_b9218
{
    virtual ~Base_b9218();
    Base_b9218();
};

struct Obj_b9218 : Base_b9218
{
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
    Obj_b9218()
    {}
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};

struct FUN_00bc3620_cls
{

    void Attach(Obj_b9218* o, int p);
    Obj_b9218* CreateAndAttach(int p);
};

// Allocates a new Obj_b9218, attaches it with the given parameter, and returns the new object.
// @fnv 0x00bc3620
Obj_b9218* FUN_00bc3620_cls::CreateAndAttach(int p)
{
    Obj_b9218* o = new Obj_b9218();
    Attach(o, p);
    return o;
}

struct InterpDerivedBc36 : NiFloatInterpController
{
};
// Allocates and returns a new InterpDerivedBc36 object.
// @fnv 0x00bc36a0
void* __cdecl CreateInterpDerivedBc36()
{
    return new InterpDerivedBc36;
}

extern unsigned char DAT_01201fb0;

// @fnv 0x00bc37a0
// src: XBOX_PDB 0x00bc37a0
void* __cdecl VolumetricFogShaderProperty_GetRTTI()
{
    return &DAT_01201fb0;
}

struct RGBWords
{
    unsigned int r, g, b;
};
extern int DAT_010bab28;
extern RGBWords DAT_011a9be0;
extern float DAT_01016410;
struct __declspec(novtable) FUN_00bc37b0_class : BSShaderProperty
{
    FUN_00bc37b0_class();
};
// @fnv 0x00bc37b0
FUN_00bc37b0_class::FUN_00bc37b0_class()
{
    *reinterpret_cast<int**>(this) = &DAT_010bab28;
    NiColorA& color = *reinterpret_cast<NiColorA*>(reinterpret_cast<char*>(this) + 0x60);
    color.a = color.b = color.g = color.r = 0.0f;
    RGBWords& rgb = *reinterpret_cast<RGBWords*>(&color);
    unsigned int red = DAT_011a9be0.r;
    double alpha = DAT_01016410;
    rgb.r = red;
    rgb.g = DAT_011a9be0.g;
    rgb.b = DAT_011a9be0.b;
    *reinterpret_cast<volatile float*>(&color.a) = alpha;
    iShaderPropertyType = 0x16;

}

struct FUN_00bc37b0 : BSShaderProperty
{
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    static void* operator new(unsigned int size)
    {
        return BSFadeNode::operator new(size);
    }
    FUN_00bc37b0();
};

struct Bc38Quad
{
    int a;
    int b;
    int c;
    int d;
};

struct Bc38Owner : BSShaderProperty
{
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    FUN_00bc37b0* CreateFadeNode(int aArg);
};

// Allocates a FUN_00bc37b0, initializes it via FUN_00ba8b10 with aArg, copies the quad at unk60 into the new object, and returns it.
// @fnv 0x00bc3830
FUN_00bc37b0* Bc38Owner::CreateFadeNode(int aArg)
{
    FUN_00bc37b0* pNode = new FUN_00bc37b0();
    CopyMemberData(pNode, reinterpret_cast<CloningProcess*>(aArg));
    Bc38Quad* pQuad = (Bc38Quad*)&unk60;
    *(Bc38Quad*)&pNode->unk60 = *pQuad;
    return pNode;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct SpawnedObj_b9755
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
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
    SpawnedObj_b9755();
    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};

// Allocates and constructs a new SpawnedObj_b9755, returning the pointer.
// @fnv 0x00bc38c0
// src: EXE 0x00bc38c0
SpawnedObj_b9755* VolumetricFogShaderProperty_CreateObject()
{
    return new SpawnedObj_b9755();
}

class BC3930Key
{
  public:
    bool operator!=(const BC3930Key& kOther) const;

    int unk00;
};

class BC3930Property : public BSShaderProperty
{
  public:
    // The shared base does not yet declare the equality implementation used here.
    bool IsEqualBase(BSShaderProperty* pkOther);
    BC3930Key m_kControlPoint;

    bool VolumetricFogShaderProperty_IsEqual(BC3930Property* pkOther);
};

// Returns false if the control-point keys differ, otherwise compares the base property.
// @fnv 0x00bc3930
// src: XBOX_PDB 0x00bc3930
bool BC3930Property::VolumetricFogShaderProperty_IsEqual(BC3930Property* pkOther)
{
    if (pkOther->m_kControlPoint != m_kControlPoint)
        return false;
    return IsEqualBase(pkOther);
}

extern const char* g_01201fb0;
extern const char DAT_010babec[];
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);

struct Prop_bc3960 : BSShaderProperty
{
    NiColorA m_kColor60;
    void WriteToSettingArray(StrArr* pkStrings);
    void AppendStrings(StrArr* pkStrings);
};

// @fnv 0x00bc3960
void Prop_bc3960::AppendStrings(StrArr* pkStrings)
{
    WriteToSettingArray(pkStrings);
    pkStrings->AppendInline(NiViewerStrings_NiGetViewerString_Title(g_01201fb0));
    pkStrings->AppendInline(((char* (__thiscall*)(NiColorA*, char*))NiColorA_FormatToBuffer)(&m_kColor60, (char*)DAT_010babec));
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

extern const NiPoint3 NiPoint3_ZERO;
struct RefObj
{
    virtual ~RefObj();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct Base_b67380
{
    virtual ~Base_b67380();
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
};
struct FUN_00bc39f0 : Base_b67380
{
    StagingNiPointer<RefObj> m_sp104;
    StagingNiPointer<RefObj> m_sp108;
    NiPoint3 m_akPts[3];
    float m_afVals[3];
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
    StagingNiPointer<RefObj> m_sp17c;
    virtual ~FUN_00bc39f0();
};
// Clears the three NiPointer members and resets each of the three m_akPts points to NiPoint3_ZERO and each m_afVals entry to 0.0f.
// @fnv 0x00bc39f0
FUN_00bc39f0::~FUN_00bc39f0()
{
    m_sp17c = 0;
    m_sp104 = 0;
    m_sp108 = 0;
    for (int i = 0; i < 3; i++)
    {
        memcpy(&m_akPts[i], &NiPoint3_ZERO, sizeof(NiPoint3));
        m_afVals[i] = 0.0f;
    }
}

extern int DAT_01201fb8;

// @fnv 0x00bc3ba0
// src: COMMUNITY 0x00bc3ba0
void* __cdecl HairShaderProperty_GetRTTI()
{
    return &DAT_01201fb8;
}

class BC3DB0RefObject
{
  public:
    virtual ~BC3DB0RefObject();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};


class BC3DB0CloningProcess;

class BC3DB0Base
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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

    void Lighting30ShaderProperty_CopyMembers(BC3DB0Base* pkDest, BC3DB0CloningProcess& kCloning);
};

class BC3DB0Property : public BC3DB0Base
{
  public:
    NiColorA m_kFogTint;
    StagingNiPointer<BC3DB0RefObject> m_spTexture;

    void CloneTo(BC3DB0Property* pkDest, BC3DB0CloningProcess& kCloning);
};

// CopyMemberData
// Copies the base data, then copies m_spTexture and the color into pkDest.
// @fnv 0x00bc3db0
void BC3DB0Property::CloneTo(BC3DB0Property* pkDest, BC3DB0CloningProcess& kCloning)
{
    Lighting30ShaderProperty_CopyMembers(pkDest, kCloning);
    pkDest->m_spTexture = m_spTexture;
    pkDest->m_kFogTint = m_kFogTint;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct SpawnedObj9441
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
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
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    SpawnedObj9441();
    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};

// Allocates and constructs a new SpawnedObj9441 via its operator new and returns the pointer.
// @fnv 0x00bc4340
SpawnedObj9441* CreateSpawnedObj9441()
{
    return new SpawnedObj9441();
}

struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t(int value)
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = value;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

void* Object_DispatchCommandFour(unsigned int size);

struct Spawned_t
{
    void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(0x180);
    }
    Spawned_t();
};

struct FUN_00bc43b0_cls
{
    int unk00;
    void CloneTo(Spawned_t* obj, bool flag);
    Spawned_t* CreateSpawned(bool flag);
};

// Sets the TLS value to 0x28, allocates a Spawned_t, initializes it via CloneTo with flag, and returns it.
// @fnv 0x00bc43b0
Spawned_t* FUN_00bc43b0_cls::CreateSpawned(bool flag)
{
    TlsGuard_t guard(0x28);
    Spawned_t* obj = new Spawned_t();
    bool take = flag;
    flag = false;
    CloneTo(obj, take);
    return obj;
}

class SomeObj
{
  public:
    unsigned int Query(unsigned int key);
    void Apply(unsigned int value);
};

unsigned char __stdcall ProbeObj(SomeObj* obj);

// Calls ProbeObj on obj, queries key 0xa, and applies the value if it is nonzero; returns the probe result.
// @fnv 0x00bc45d0
unsigned char __stdcall ProbeAndApply(SomeObj* obj)
{
    unsigned char result = ProbeObj(obj);
    unsigned int value = obj->Query(0xa);
    if (value != 0)
    {
        obj->Apply(value);
    }
    return result;
}

extern StagingNiPointer<NiRefObject> DAT_01201fc4;

// @fnv 0x00bc4610
void __cdecl ClearRefObject()
{
    DAT_01201fc4 = static_cast<NiRefObject*>(0);
}

struct LodChildA
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
};
struct LodChildB
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
};
struct FUN_00bc4640_cls : LodShaderBase
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
    int m_28;
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
    LodChildA* m_b8;
    LodChildB* m_bc;
    void BeamShader_RecreateRendererData();
};
// If m_28 is nonzero, calls v28 on m_b8 and v22 on m_bc, then calls LodShaderBase::FUN_00e814b0.
// @fnv 0x00bc4640
// src: XBOX_PDB 0x00bc4640
void FUN_00bc4640_cls::BeamShader_RecreateRendererData()
{
    if (m_28 != 0)
    {
        m_b8->v28();
        m_bc->v22();
    }
    LodShaderBase::FUN_00e814b0();
}

void* __cdecl FUN_00ec61c0(void*, int, unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
void __cdecl FUN_00be0c00(const char*, char*);
int __cdecl BSsprintf(char*, int, const char*, ...);
const char* __cdecl FUN_00b4f380(bool);
struct BeamDesc
{
    const char* file;
    unsigned int count;
    unsigned int flags;
    char arguments[64];
    BeamDesc(const char* name) : file(name), count(0), flags(0)
    {
        FUN_00ec61c0(arguments, 0, 64);
    }
};
struct BeamPtr
{
    RefObject* ptr;
    void Assign(RefObject* p)
    {
        RefObject* old = ptr;
        if (old != p)
        {
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->Release();
            ptr = p;
            if (p)
                InterlockedIncrement(&p->m_iObjectReferenceCount);
        }
    }
};
struct TargetBeam
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
    BeamPtr vertex;
    BeamPtr pixel;
    RefObject* FUN_00be0fe0(const char*, unsigned int*, const char*, const char*);
    RefObject* FUN_00be1750(const char*, unsigned int*, const char*, const char*);
    void BeamShader_LoadShaders();
};
// Builds source and binary paths for the beam vertex and pixel shaders and assigns the compiled shader objects to vertex and pixel.
// @fnv 0x00bc4680
// src: COMMUNITY 0x00bc4680
void TargetBeam::BeamShader_LoadShaders()
{
    BeamDesc vertexDesc("beam\\v\\beam.v.hlsl");
    char sourcePath[260];
    char binaryPath[260];
    FUN_00be0c00(vertexDesc.file, sourcePath);
    BSsprintf(binaryPath, 260, "BEAM.vso");
    vertex.Assign(FUN_00be0fe0(sourcePath, &vertexDesc.count, "vs_1_1", binaryPath));
    const char* profile = FUN_00b4f380(true);
    BeamDesc pixelDesc("beam\\p\\beam.p.hlsl");
    FUN_00be0c00(pixelDesc.file, sourcePath);
    BSsprintf(binaryPath, 260, "BEAM.pso");
    pixel.Assign(FUN_00be1750(sourcePath, &pixelDesc.count, profile, binaryPath));
}

void* __cdecl FUN_00ec61c0(void*, int, unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct CountedRef
{
    virtual void unused();
    virtual void Release();
    long references;
};
struct PassView
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
    int references;
    void FUN_00e80190();
};
struct PassPtr
{
    PassView* ptr;
    PassPtr() : ptr(0)
    {}
    ~PassPtr()
    {
        if (ptr && --ptr->references == 0)
            ptr->FUN_00e80190();
    }
    void clear()
    {
        PassView* old = ptr;
        if (old)
        {
            if (--old->references == 0)
                old->FUN_00e80190();
            ptr = 0;
        }
    }
};
struct RefPtr
{
    CountedRef* ptr;
    RefPtr() : ptr(0)
    {}
    ~RefPtr()
    {
        if (ptr && InterlockedDecrement(&ptr->references) == 0)
            ptr->Release();
    }
    void assign(CountedRef* value)
    {
        CountedRef* old = ptr;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->references) == 0)
                old->Release();
            ptr = value;
            if (value)
                InterlockedIncrement(&value->references);
        }
    }
    void clear()
    {
        CountedRef* old = ptr;
        if (old)
        {
            if (InterlockedDecrement(&old->references) == 0)
                old->Release();
            ptr = 0;
        }
    }
};
struct FUN_00be2200
{
    virtual ~FUN_00be2200();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned char flag24;
    RefPtr source;
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
    int mode;
    int flags;
    float value;
    float matrix[16];
    FUN_00be2200();
};
struct FUN_00bc4830 : FUN_00be2200
{
    PassPtr pass;
    RefPtr first;
    RefPtr second;
    FUN_00bc4830(CountedRef* source);
    virtual ~FUN_00bc4830();
};
// @fnv 0x00bc4830
FUN_00bc4830::FUN_00bc4830(CountedRef* pSource)
{
    mode = 16;
    flag24 = 1;
    flags = 0x243;
    pass.clear();
    source.assign(pSource);
    first.clear();
    second.clear();
    value = 0.0f;
    FUN_00ec61c0(matrix, 0, 0x40);
}

extern char DAT_01201fc8;

// @fnv 0x00bc4970
// src: XBOX_PDB 0x00bc4970
void* BeamShader_GetRTTI()
{
    return &DAT_01201fc8;
}

// FUN_00bc5030: thiscall member that calls virtual slot 0x140 and then
// tail-jumps to the next virtual slot 0x144 of the same object.
struct FUN_00bc5030_cls
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();

    void TileShader_LoadShaders();
};

// @fnv 0x00bc5030
// src: COMMUNITY 0x00bc5030
void FUN_00bc5030_cls::TileShader_LoadShaders()
{
    v80();
    v81();
}

struct FUN_00bc52f0_class
{
    virtual void unk00() = 0;
    virtual void unk01() = 0;
    virtual void unk02() = 0;
    virtual void unk03() = 0;
    virtual void unk04() = 0;
    virtual void unk05() = 0;
    virtual void unk06() = 0;
    virtual void unk07() = 0;
    virtual void unk08() = 0;
    virtual void unk09() = 0;
    virtual void unk10() = 0;
    virtual void unk11() = 0;
    virtual void unk12() = 0;
    virtual void unk13() = 0;
    virtual void unk14() = 0;
    virtual void unk15() = 0;
    virtual void unk16() = 0;
    virtual void unk17() = 0;
    virtual void unk18() = 0;
    virtual void unk19() = 0;
    virtual void unk20() = 0;
    virtual void unk21() = 0;
    virtual void unk22() = 0;
    virtual void unk23() = 0;
    virtual void unk24() = 0;
    virtual void unk25() = 0;
    virtual void unk26() = 0;
    virtual void unk27() = 0;
    virtual void unk28() = 0;
    virtual void unk29() = 0;
    virtual void unk30() = 0;
    virtual void unk31() = 0;
    virtual void unk32() = 0;
    virtual void unk33() = 0;
    virtual void unk34() = 0;
    virtual void unk35() = 0;
    virtual void unk36() = 0;
    virtual void unk37() = 0;
    virtual void unk38() = 0;
    virtual void unk39() = 0;
    virtual void unk40() = 0;
    virtual void unk41() = 0;
    virtual void unk42() = 0;
    virtual void unk43() = 0;
    virtual void unk44() = 0;
    virtual void unk45() = 0;
    virtual void unk46() = 0;
    virtual void unk47() = 0;
    virtual void unk48() = 0;
    virtual void unk49() = 0;
    virtual void unk50() = 0;
    virtual void unk51() = 0;
    virtual void unk52() = 0;
    virtual void unk53() = 0;
    virtual void unk54() = 0;
    virtual void unk55() = 0;
    virtual void unk56() = 0;
    virtual void unk57() = 0;
    virtual void unk58() = 0;
    virtual void unk59() = 0;
    virtual void unk60() = 0;
    virtual void unk61() = 0;
    virtual void unk62() = 0;
    virtual void unk63() = 0;
    virtual void unk64() = 0;
    virtual void unk65() = 0;
    virtual void unk66() = 0;
    virtual void unk67() = 0;
    virtual void unk68() = 0;
    virtual void unk69() = 0;
    virtual void unk70() = 0;
    virtual void unk71() = 0;
    virtual void unk72() = 0;
    virtual void unk73() = 0;
    virtual void unk128(int) = 0;

    void* field04;
    void* field08;
    void* field0c;
    void* field10;
    void* field14;
    void* field18;
    void* field1c;
    void* field20;
    void* field24;
    void* field28;
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

    int field6c;
    int field70;
    int field74;

    void __thiscall VolumetricFogShader_ClearPassStages();
};

// @fnv 0x00bc52f0
// src: XBOX_PDB 0x00bc52f0
void __thiscall FUN_00bc52f0_class::VolumetricFogShader_ClearPassStages()
{
    int* p = &field6c;
    int count = 3;

    do
    {
        unk128(*p);
        ++p;
        --count;
    } while (count != 0);
}

struct ShaderBase5320
{
    unsigned field04, field08, field0c, field10, field14, field18, field1c;
    unsigned field20, field24, field28, field2c, field30, field34, field38, field3c;
    unsigned field40, field44, field48, field4c, field50, field54, field58, field5c;
    unsigned field60, field64, field68;
    virtual ~ShaderBase5320();
};
struct Resource5320
{
    virtual void Unused();
    virtual void Release();
    long refs;
};
struct Slot5320
{
    Resource5320* object;
    ~Slot5320();
};
struct OtherSlot5320
{
    void* object;
    ~OtherSlot5320();
};
extern int DAT_010baf60;
struct FUN_00bc5320_Class : ShaderBase5320
{
    OtherSlot5320 other[3];
    Slot5320 first[2];
    Slot5320 second[2];
    ~FUN_00bc5320_Class();
};
// Releases the two resource slots in first and second by decrementing each object's ref count and calling Release when it reaches zero.
// @fnv 0x00bc5320
FUN_00bc5320_Class::~FUN_00bc5320_Class()
{
    for (unsigned i = 0; i < 2; ++i)
    {
        Resource5320* p = first[i].object;
        if (p)
        {
            if (!InterlockedDecrement(&p->refs))
                p->Release();
            first[i].object = 0;
        }
    }
    for (unsigned i = 0; i < 2; ++i)
    {
        Resource5320* p = second[i].object;
        if (p)
        {
            if (!InterlockedDecrement(&p->refs))
                p->Release();
            second[i].object = 0;
        }
    }
}

// FUN_00bc5440 : a one-line function - getter
extern int g_target_00bc5440;
// @fnv 0x00bc5440
// src: XBOX_PDB 0x00bc5440
void* VolumetricFogShader_GetRTTI()
{
    return &g_target_00bc5440;
}

struct RefList0
{
    char pad[0x64];
    int m_refs;
    void FUN_00e80190();
};
struct RefEnt
{
    virtual void v0();
    virtual void Release();
    volatile long m_iObjectReferenceCount;
};

struct FUN_00bc5450_cls
{
    char pad[0x6c];
    RefList0* m_pRefs[3];
    RefEnt* m_pRefs2[2];
    RefEnt* m_pRefs3[2];
    bool FUN_00be0870();
    bool ReleaseAllRefs();
};

// Calls FUN_00be0870, then releases and clears every entry in m_pRefs, m_pRefs2 and m_pRefs3, returning the first call's result.
// @fnv 0x00bc5450
bool FUN_00bc5450_cls::ReleaseAllRefs()
{
    bool b = FUN_00be0870();

    int delta = -1;
    RefList0** pCur = m_pRefs;
    for (int i = 3; i != 0; --i)
    {
        RefList0* p = *pCur;
        if (p)
        {
            if ((p->m_refs += delta) == 0)
            {
                p->FUN_00e80190();
            }
            *pCur = 0;
        }
        ++pCur;
    }

    RefEnt** ppRefs2 = m_pRefs2;
    for (int i = 2; i != 0; --i)
    {
        RefEnt* q = *ppRefs2;
        if (q)
        {
            if (InterlockedDecrement(&q->m_iObjectReferenceCount) == 0)
            {
                q->Release();
            }
            *ppRefs2 = 0;
        }
        ++ppRefs2;
    }

    RefEnt** ppRefs3 = m_pRefs3;
    for (int i = 2; i != 0; --i)
    {
        RefEnt* q = *ppRefs3;
        if (q)
        {
            if (InterlockedDecrement(&q->m_iObjectReferenceCount) == 0)
            {
                q->Release();
            }
            *ppRefs3 = 0;
        }
        ++ppRefs3;
    }

    return b;
}

namespace fnv_00bc58a0 {
struct FUN_00be2200
{
    virtual ~FUN_00be2200();
    unsigned int m_state04;
    unsigned int m_state08;
    unsigned int m_state0c;
    unsigned int m_state10;
    unsigned int m_state14;
    unsigned int m_state18;
    unsigned int m_state1c;
    unsigned int m_state20;
    unsigned int m_state24;
    unsigned int m_state28;
    unsigned int m_state2c;
    unsigned int m_state30;
    unsigned int m_state34;
    unsigned int m_state38;
    unsigned int m_state3c;
    unsigned int m_state40;
    unsigned int m_state44;
    unsigned int m_state48;
    unsigned int m_state4c;
    unsigned int m_state50;
    unsigned int m_state54;
    unsigned int m_state58;
    unsigned int m_state5c;
    unsigned int m_state60;
    unsigned int m_state64;
    volatile unsigned int m_shaderStage;
    FUN_00be2200();
};
struct ShaderValue
{
    unsigned int m_uiFilterValue;
    ShaderValue();
};
struct InputShaderValue : ShaderValue
{
    ~InputShaderValue();
};
struct OutputShaderValue : ShaderValue
{
    ~OutputShaderValue();
};
struct FUN_00bc58a0 : FUN_00be2200
{
    InputShaderValue m_inputValues[3];
    OutputShaderValue m_outputValues[2];
    OutputShaderValue m_auxiliaryValues[2];
    float m_constants[8];
    FUN_00bc58a0();
    virtual ~FUN_00bc58a0();
};
// Initializes all eight m_constants to 0.0f and sets m_shaderStage to 19.
// @fnv 0x00bc58a0
FUN_00bc58a0::FUN_00bc58a0()
{
    m_constants[7] = m_constants[6] = m_constants[5] = m_constants[4] = m_constants[3] = m_constants[2] =
        m_constants[1] = m_constants[0] = 0.0f;
    m_shaderStage = 19;
}
}  // namespace fnv_00bc58a0

extern int DAT_01202228;

// @fnv 0x00bcb450
// src: XBOX_PDB 0x00bcb450
void* __cdecl GeometryDecalShader_GetRTTI()
{
    return &DAT_01202228;
}

struct BlockRecord
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
    unsigned int eventType;
};
struct DispatchInfo
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned short eventCode;
};
struct DispatchHandler
{
    virtual void unknownVirtual0();
    virtual void unknownVirtual1();
    virtual void unknownVirtual2();
    virtual void unknownVirtual3();
    virtual void unknownVirtual4();
    virtual void unknownVirtual5();
    virtual void unknownVirtual6();
    virtual void unknownVirtual7();
    virtual void unknownVirtual8();
    virtual void unknownVirtual9();
    virtual void unknownVirtual10();
    virtual void unknownVirtual11();
    virtual void unknownVirtual12();
    virtual void unknownVirtual13();
    virtual void unknownVirtual14();
    virtual void unknownVirtual15();
    virtual void unknownVirtual16();
    virtual void unknownVirtual17();
    virtual void unknownVirtual18();
    virtual void unknownVirtual19();
    virtual void unknownVirtual20();
    virtual void unknownVirtual21();
    virtual void unknownVirtual22();
    virtual void unknownVirtual23();
    virtual void unknownVirtual24();
    virtual void unknownVirtual25();
    virtual void unknownVirtual26();
    virtual void unknownVirtual27();
    virtual void unknownVirtual28();
    virtual void unknownVirtual29();
    virtual void Dispatch(void* target, unsigned int eventType, unsigned short eventCode, int mode,
                          unsigned int eventData);
};
struct DispatchRegistry
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
    DispatchHandler* handler;
};
extern DispatchRegistry* DAT_0126f74c;
struct EventSystem
{
    void NiDX9Renderer_CalculateBoneMatrices(BlockRecord* block, unsigned int token, int zero, int type, int enabled);
};
extern EventSystem* DAT_011f9508;
struct EventInvoker
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
    unsigned int disabledFlag;
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
    void* channel;
    int DispatchEvent(int unused1, BlockRecord* block, DispatchInfo* info, int unused4, int unused5, int unused6,
                      unsigned int token, int unused8);
};
// @fnv 0x00bcb460
int EventInvoker::DispatchEvent(int unused1, BlockRecord* block, DispatchInfo* info, int unused4, int unused5,
                                int unused6, unsigned int token, int unused8)
{
    if (block != 0 && info != 0 && disabledFlag == 0 && channel != 0)
    {
        DAT_011f9508->NiDX9Renderer_CalculateBoneMatrices(block, token, 0, 3, 1);
        DAT_0126f74c->handler->Dispatch(channel, block->eventType, info->eventCode, 3, info->unk04);
    }
    return 0;
}

struct FUN_00bcc570_class
{
    virtual void V0() = 0;
    virtual void V1() = 0;
    virtual void V2() = 0;
    virtual void V3() = 0;
    virtual void V4() = 0;
    virtual void V5() = 0;
    virtual void V6() = 0;
    virtual void V7() = 0;
    virtual void V8() = 0;
    virtual void V9() = 0;
    virtual void V10() = 0;
    virtual void V11() = 0;
    virtual void V12() = 0;
    virtual void V13() = 0;
    virtual void V14() = 0;
    virtual void V15() = 0;
    virtual void V16() = 0;
    virtual void V17() = 0;
    virtual void V18() = 0;
    virtual void V19() = 0;
    virtual void V20() = 0;
    virtual void V21() = 0;
    virtual void V22() = 0;
    virtual void V23() = 0;
    virtual void V24() = 0;
    virtual void V25() = 0;
    virtual void V26() = 0;
    virtual void V27() = 0;
    virtual void V28() = 0;
    virtual void V29() = 0;
    virtual void V30() = 0;
    virtual void V31() = 0;
    virtual void V32() = 0;
    virtual void V33() = 0;
    virtual void V34() = 0;
    virtual void V35() = 0;
    virtual void V36() = 0;
    virtual void V37() = 0;
    virtual void V38() = 0;
    virtual void V39() = 0;
    virtual void V40() = 0;
    virtual void V41() = 0;
    virtual void V42() = 0;
    virtual void V43() = 0;
    virtual void V44() = 0;
    virtual void V45() = 0;
    virtual void V46() = 0;
    virtual void V47() = 0;
    virtual void V48() = 0;
    virtual void V49() = 0;
    virtual void V50() = 0;
    virtual void V51() = 0;
    virtual void V52() = 0;
    virtual void V53() = 0;
    virtual void V54() = 0;
    virtual void V55() = 0;
    virtual void V56() = 0;
    virtual void V57() = 0;
    virtual void V58() = 0;
    virtual void V59() = 0;
    virtual void V60() = 0;
    virtual void V61() = 0;
    virtual void V62() = 0;
    virtual void V63() = 0;
    virtual void V64() = 0;
    virtual void V65() = 0;
    virtual void V66() = 0;
    virtual void V67() = 0;
    virtual void V68() = 0;
    virtual void V69() = 0;
    virtual void V70() = 0;
    virtual void V71() = 0;
    virtual void V72() = 0;
    virtual void V73() = 0;
    virtual void V74() = 0;
    virtual void V75() = 0;
    virtual void V76() = 0;
    virtual void V77() = 0;
    virtual void V78() = 0;
    virtual void V79() = 0;
    virtual void V80() = 0;
    virtual void V81() = 0;
    virtual void V82() = 0;
    virtual void V83() = 0;
    virtual void V84() = 0;
    virtual void V85() = 0;
    virtual void V86() = 0;

    void __thiscall CallV81ThenV86();
};

// @fnv 0x00bcc570
void __thiscall FUN_00bcc570_class::CallV81ThenV86()
{
    V81();
    return V86();
}

extern int DAT_01202230[33];

struct S_00bcce10
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74(int);
    void ParallaxShader_ClearPassStages();
};

// Calls vf74 for each of the 33 entries in DAT_01202230.
// @fnv 0x00bcce10
// src: COMMUNITY 0x00bcce10
void S_00bcce10::ParallaxShader_ClearPassStages()
{
    for (int i = 0; i < 33; ++i)
        vf74(DAT_01202230[i]);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);

struct RefObj_bcd
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> struct NiPtr_bcd
{
    T* m_pObject;
    NiPtr_bcd& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct Base_bcd
{
    virtual void v00();
    int unk04[23];
    int m_i60;
    bool m_b64;
    int m_i68;
    NiPtr_bcd<RefObj_bcd> m_spA;
    NiPtr_bcd<RefObj_bcd> m_spB;
    int unk74[6];
    Base_bcd(RefObj_bcd* p, int a, int b, int c);
    ~Base_bcd();
};

struct Elem_bcd
{
    int unk00;
    Elem_bcd();
    ~Elem_bcd();
};

struct FUN_00bcd390 : Base_bcd
{
    Elem_bcd m_aA[20];
    Elem_bcd m_aB[33];
    virtual void v00();
    FUN_00bcd390(RefObj_bcd* p);
};

// Constructs the object by initializing the base with p, then sets m_i68 to 3, clears m_b64, assigns m_spA to p and m_spB to null, and m_i60 to 0.
// @fnv 0x00bcd390
FUN_00bcd390::FUN_00bcd390(RefObj_bcd* apRefObj) : Base_bcd(apRefObj, 0, 0, 0)
{
    m_i68 = 3;
    m_b64 = false;
    m_spA = apRefObj;
    m_spB = 0;
    m_i60 = 0;
}

extern int DAT_012022b4;
// @fnv 0x00bcd490
// src: COMMUNITY 0x00bcd490
int* __cdecl ParallaxShader_GetRTTI()
{
    return &DAT_012022b4;
}

namespace fnv_00bcd5d0 {
struct FUN_00bcd5d0_Item
{
    char pad[0x64];
    int m_refs;
    void FUN_00e80190();
};
struct FUN_00bcd5d0_Obj
{
    virtual void v0();
    virtual void Release();
    volatile long m_iObjectReferenceCount;
};

extern FUN_00bcd5d0_Item* DAT_01202230[33];

struct FUN_00bcd5d0_cls
{
    char pad[0x8c];
    FUN_00bcd5d0_Obj* m_slots[20];
    FUN_00bcd5d0_Obj* m_slots2[33];

    void FUN_00be0870();
    bool ClearAllSlots();
};

// @fnv 0x00bcd5d0
bool FUN_00bcd5d0_cls::ClearAllSlots()
{
    FUN_00be0870();

    int i;
    FUN_00bcd5d0_Obj** pCur = m_slots;
    for (i = 20; i != 0; --i)
    {
        FUN_00bcd5d0_Obj* o = *pCur;
        if (o)
        {
            if (InterlockedDecrement(&o->m_iObjectReferenceCount) == 0)
            {
                o->Release();
            }
            *pCur = 0;
        }
        ++pCur;
    }

    pCur = m_slots2;
    for (i = 33; i != 0; --i)
    {
        FUN_00bcd5d0_Obj* o = *pCur;
        if (o)
        {
            if (InterlockedDecrement(&o->m_iObjectReferenceCount) == 0)
            {
                o->Release();
            }
            *pCur = 0;
        }
        ++pCur;
    }

    int delta = -1;
    FUN_00bcd5d0_Item** pItem = DAT_01202230;
    for (i = 0; i < 33; i++)
    {
        FUN_00bcd5d0_Item* it = pItem[i];
        if (it)
        {
            if ((it->m_refs += delta) == 0)
            {
                it->FUN_00e80190();
            }
            pItem[i] = 0;
        }
    }
    return true;
}
}  // namespace fnv_00bcd5d0

namespace fnv_00bcd680 {
struct RendererStub;
extern RendererStub* DAT_011f9508;
struct PassStub
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
    virtual void SetStage(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e);
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void Finish();
};
PassStub* __cdecl NiDX9ShaderDeclaration_Create(RendererStub* r, int a, int b);
struct ShaderObj
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
    virtual void Init19();
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
    virtual void SetPass(PassStub* p);
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void Init71();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void Init81();
    virtual void v52();
    virtual void v53();
    virtual void Init84();
    ShaderObj(PassStub* p);
    static void* operator new(unsigned int);
    static void operator delete(void*);
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
};

// Creates a pass with six stages, finishes it, constructs a ShaderObj from it, runs several init calls, sets the pass and returns the object.
// @fnv 0x00bcd680
// src: XBOX_PDB 0x00bcd680
ShaderObj* __cdecl ParallaxShader_CreateShader()
{
    PassStub* pass = NiDX9ShaderDeclaration_Create(DAT_011f9508, 6, 1);
    pass->SetStage(0, 0, 0, 2, 0);
    pass->SetStage(1, 3, 3, 2, 0);
    pass->SetStage(2, 5, 4, 3, 0);
    pass->SetStage(3, 7, 5, 1, 0);
    pass->SetStage(4, 0xe, 0xd, 2, 0);
    pass->SetStage(5, 0xf, 0xe, 2, 0);
    pass->Finish();
    ShaderObj* obj = new ShaderObj(pass);
    obj->Init19();
    obj->Init81();
    obj->Init84();
    obj->Init71();
    obj->SetPass(pass);
    return obj;
}
}  // namespace fnv_00bcd680

extern unsigned int g_b3804_table[26];

struct FUN_00bcf7c0_cls
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void Dispatch(unsigned int value);
    void DispatchAllTableEntries();
};

// Iterates over the 26 entries of g_b3804_table and calls Dispatch on each value.
// @fnv 0x00bcf7c0
void FUN_00bcf7c0_cls::DispatchAllTableEntries()
{
    unsigned int* p = g_b3804_table;
    while ((int)p < (int)(g_b3804_table + 26))
    {
        Dispatch(*p);
        ++p;
    }
}

struct CpuOpaque;
extern CpuOpaque DAT_01202328;
// @fnv 0x00bcf910
// src: COMMUNITY 0x00bcf910
CpuOpaque* __cdecl SkinShader_GetRTTI()
{
    return &DAT_01202328;
}

struct ShaderBase
{
    virtual void Initialize();
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
    ~ShaderBase();
};
struct FUN_00bcf920 : ShaderBase
{
    StagingNiPointer<NiD3DVertexShader> vertex[26];
    StagingNiPointer<NiD3DPixelShader> pixel[13];
    virtual void Initialize();
    ~FUN_00bcf920();
};
// @fnv 0x00bcf920
FUN_00bcf920::~FUN_00bcf920()
{
    for (unsigned i = 0; i < 26; ++i)
    {
        NiD3DVertexShader* p = vertex[i].m_pObject;
        if (p)
        {
            if (!InterlockedDecrement((volatile long*)&p->m_uiRefCount))
                p->DeleteThis();
            vertex[i].m_pObject = 0;
        }
    }
    for (unsigned j = 0; j < 13; ++j)
    {
        NiD3DPixelShader* p = pixel[j].m_pObject;
        if (p)
        {
            if (!InterlockedDecrement((volatile long*)&p->m_uiRefCount))
                p->DeleteThis();
            pixel[j].m_pObject = 0;
        }
    }
    NiD3DPass** p = &DAT_012022c0;
    do
    {
        NiD3DPass* pass = *p;
        if (pass)
        {
            if (!--pass->m_uiRefCount)
                pass->DestroyPass();
            *p = 0;
        }
        ++p;
    } while ((int)p < (int)&g_01202328);
}

// FUN_00bd0470: thiscall member that calls virtual slot 0x148 and tail-jumps to slot 0x14c
struct FUN_00bd0470_cls
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();

    void ShadowLightShader_LoadShaders();
};

// @fnv 0x00bd0470
// src: COMMUNITY 0x00bd0470
void FUN_00bd0470_cls::ShadowLightShader_LoadShaders()
{
    v82();
    v83();
}

struct FUN_00bd0490_class
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();

    void HairShader_ReloadShaders();
};

// @fnv 0x00bd0490
// src: COMMUNITY 0x00bd0490
void FUN_00bd0490_class::HairShader_ReloadShaders()
{
    v81();
}

struct S_00bd04a0_Res
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
};
struct S_00bd04a0_Obj
{
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int m_28;
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
    S_00bd04a0_Res* m_a94[7];
    S_00bd04a0_Res* m_b0[3];
    S_00bd04a0_Res* m_bc[7];
    S_00bd04a0_Res* m_d8[3];
    void ShadowLightShader_RecreateRendererData();
    void HairShader_RecreateRendererData();
};
// @fnv 0x00bd04a0
// src: COMMUNITY 0x00bd04a0
void S_00bd04a0_Obj::HairShader_RecreateRendererData()
{
    if (m_28)
    {
        for (int i = 0; i < 7; i++)
        {
            S_00bd04a0_Res* r = m_a94[i];
            if (r)
                r->vfa0();
        }
        for (int i = 0; i < 7; i++)
        {
            S_00bd04a0_Res* r = m_bc[i];
            if (r)
                r->vfa0();
        }
    }
    for (int i = 0; i < 3; i++)
    {
        S_00bd04a0_Res* r = m_b0[i];
        if (r)
            r->vf88();
        S_00bd04a0_Res* q = m_d8[i];
        if (q)
            q->vf88();
    }
    ShadowLightShader_RecreateRendererData();
}

namespace fnv_00bd0540 {
extern const char str_010bbb38[];
extern const char str_010bbb30[];
extern const char str_010bbb2c[];
extern const char str_010bbb28[];
extern const char str_010bbb20[];
extern const char str_010bbb1c[];
extern const char str_010bbb08[];
extern const char str_010bbaf8[];
extern const char str_010bbae8[];
extern const char str_010a93ec[];
extern const char str_010a93e4[];
extern char DAT_01011584;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
void* __cdecl FUN_00ec61c0(void* dst, int val, unsigned int n);
void __cdecl FUN_00be0c00(void* val, void* buf);
void __cdecl BSsprintf(char* dst, unsigned int n, const char* fmt, int i);

struct Elem540
{
    const char* f00;
    const char* f04;
    void* f08;
    const char* f0c;
    void* f10;
    const char* f14;
    void* f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
};

struct FUN_00bd0540_class
{
    char pad00[0x94];
    RefObject* m_arr94[7];
    char padb0[0x0c];
    RefObject* m_arrBC[7];
    RefObject* __thiscall FUN_00be0fe0(void* buf, void* pField, const char* str, char* buf2);
    void InitRefObjects();
};

// @fnv 0x00bd0540
void FUN_00bd0540_class::InitRefObjects()
{
    Elem540 arrB[7];
    Elem540 arrA[7];
    char bufB[0x104];
    char bufA[0x104];

    arrA[0].f00 = str_010bbb38;
    arrA[0].f04 = str_010bbb30;
    arrA[0].f08 = &DAT_01011584;
    arrA[0].f0c = 0;
    FUN_00ec61c0(&arrA[0].f10, 0, 0x3c);
    arrA[1].f00 = str_010bbb38;
    arrA[1].f04 = str_010bbb30;
    arrA[1].f08 = &DAT_01011584;
    arrA[1].f0c = str_010bbb2c;
    arrA[1].f10 = &DAT_01011584;
    arrA[1].f14 = 0;
    FUN_00ec61c0(&arrA[1].f18, 0, 0x34);
    arrA[2].f00 = str_010bbb38;
    arrA[2].f04 = str_010bbb28;
    arrA[2].f08 = &DAT_01011584;
    arrA[2].f0c = str_010bbb20;
    arrA[2].f10 = &DAT_01011584;
    arrA[2].f14 = 0;
    FUN_00ec61c0(&arrA[2].f18, 0, 0x34);
    arrA[3].f00 = str_010bbb38;
    arrA[3].f04 = str_010bbb30;
    arrA[3].f08 = &DAT_01011584;
    arrA[3].f0c = str_010bbb2c;
    arrA[3].f10 = &DAT_01011584;
    arrA[3].f14 = str_010bbb1c;
    arrA[3].f18 = &DAT_01011584;
    arrA[3].f1c = 0;
    FUN_00ec61c0(&arrA[3].f20, 0, 0x2c);
    arrA[4].f00 = str_010bbb38;
    arrA[4].f04 = str_010bbb28;
    arrA[4].f08 = &DAT_01011584;
    arrA[4].f0c = str_010bbb20;
    arrA[4].f10 = &DAT_01011584;
    arrA[4].f14 = str_010bbb1c;
    arrA[4].f18 = &DAT_01011584;
    arrA[4].f1c = 0;
    FUN_00ec61c0(&arrA[4].f20, 0, 0x2c);
    arrA[5].f00 = str_010bbb38;
    arrA[5].f04 = str_010bbb28;
    arrA[5].f08 = &DAT_01011584;
    arrA[5].f0c = str_010bbb2c;
    arrA[5].f10 = &DAT_01011584;
    arrA[5].f14 = str_010bbb1c;
    arrA[5].f18 = &DAT_01011584;
    arrA[5].f1c = 0;
    FUN_00ec61c0(&arrA[5].f20, 0, 0x2c);
    arrA[6].f00 = str_010bbb38;
    arrA[6].f04 = str_010bbb28;
    arrA[6].f08 = &DAT_01011584;
    arrA[6].f0c = str_010bbb2c;
    arrA[6].f10 = &DAT_01011584;
    arrA[6].f14 = 0;
    FUN_00ec61c0(&arrA[6].f18, 0, 0x34);

    arrB[0].f00 = str_010bbb08;
    arrB[0].f04 = str_010bbb30;
    arrB[0].f08 = &DAT_01011584;
    arrB[0].f0c = 0;
    FUN_00ec61c0(&arrB[0].f10, 0, 0x3c);
    arrB[1].f00 = str_010bbb08;
    arrB[1].f04 = str_010bbb30;
    arrB[1].f08 = &DAT_01011584;
    arrB[1].f0c = str_010bbb2c;
    arrB[1].f10 = &DAT_01011584;
    arrB[1].f14 = 0;
    FUN_00ec61c0(&arrB[1].f18, 0, 0x34);
    arrB[2].f00 = str_010bbb08;
    arrB[2].f04 = str_010bbb28;
    arrB[2].f08 = &DAT_01011584;
    arrB[2].f0c = str_010bbb20;
    arrB[2].f10 = &DAT_01011584;
    arrB[2].f14 = 0;
    FUN_00ec61c0(&arrB[2].f18, 0, 0x34);
    arrB[3].f00 = str_010bbb08;
    arrB[3].f04 = str_010bbb30;
    arrB[3].f08 = &DAT_01011584;
    arrB[3].f0c = str_010bbb2c;
    arrB[3].f10 = &DAT_01011584;
    arrB[3].f14 = str_010bbb1c;
    arrB[3].f18 = &DAT_01011584;
    arrB[3].f1c = 0;
    FUN_00ec61c0(&arrB[3].f20, 0, 0x2c);
    arrB[4].f00 = str_010bbb08;
    arrB[4].f04 = str_010bbb28;
    arrB[4].f08 = &DAT_01011584;
    arrB[4].f0c = str_010bbb20;
    arrB[4].f10 = &DAT_01011584;
    arrB[4].f14 = str_010bbb1c;
    arrB[4].f18 = &DAT_01011584;
    arrB[4].f1c = 0;
    FUN_00ec61c0(&arrB[4].f20, 0, 0x2c);
    arrB[5].f00 = str_010bbb08;
    arrB[5].f04 = str_010bbb28;
    arrB[5].f08 = &DAT_01011584;
    arrB[5].f0c = str_010bbb2c;
    arrB[5].f10 = &DAT_01011584;
    arrB[5].f14 = str_010bbb1c;
    arrB[5].f18 = &DAT_01011584;
    arrB[5].f1c = 0;
    FUN_00ec61c0(&arrB[5].f20, 0, 0x2c);
    arrB[6].f00 = str_010bbb08;
    arrB[6].f04 = str_010bbb28;
    arrB[6].f08 = &DAT_01011584;
    arrB[6].f0c = str_010bbb2c;
    arrB[6].f10 = &DAT_01011584;
    arrB[6].f14 = 0;
    FUN_00ec61c0(&arrB[6].f18, 0, 0x34);

    for (int i = 0; i < 7; i++)
    {
        if (arrA[i].f00 != 0)
        {
            FUN_00be0c00((void*)arrA[i].f00, bufB);
            BSsprintf(bufA, 0x104, str_010bbaf8, i);
            RefObject* nv = FUN_00be0fe0(bufB, &arrA[i].f04, str_010a93ec, bufA);
            RefObject* old = m_arr94[i];
            if (old != nv)
            {
                if (old != 0)
                {
                    if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                        old->Release();
                }
                m_arr94[i] = nv;
                if (nv != 0)
                    InterlockedIncrement(&nv->m_iObjectReferenceCount);
            }
        }
    }
    if (DAT_011f91c0 >= 2)
    {
        for (int i = 0; i < 7; i++)
        {
            FUN_00be0c00((void*)arrB[i].f00, bufB);
            BSsprintf(bufA, 0x104, str_010bbae8, i);
            RefObject* nv = FUN_00be0fe0(bufB, &arrB[i].f04, str_010a93e4, bufA);
            RefObject* old = m_arrBC[i];
            if (old != nv)
            {
                if (old != 0)
                {
                    if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                        old->Release();
                }
                m_arrBC[i] = nv;
                if (nv != 0)
                    InterlockedIncrement(&nv->m_iObjectReferenceCount);
            }
        }
    }
}
}  // namespace fnv_00bd0540

namespace fnv_00bd0ae0 {
struct StageReturn
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
    int m_iObjectReferenceCount;
    void ReturnToPool();
    void DecRef()
    {
        if (--m_iObjectReferenceCount == 0)
            ReturnToPool();
    }
};

struct StageReturnPtr
{
    StageReturn* m_p;
    StageReturnPtr() : m_p(0)
    {}
    operator StageReturn*() const
    {
        return m_p;
    }
    ~StageReturnPtr()
    {
        if (m_p)
            m_p->DecRef();
    }
};

void __cdecl CreateNewStage_e7edf0(StageReturnPtr& out);
struct ShaderPassOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* m_pDirectInputDevice;
    void InsertStage(void* list, StageReturn* stage);
};

struct ShaderPassOwnerPtr
{
    ShaderPassOwner* m_p;
    ShaderPassOwner* operator->() const
    {
        return m_p;
    }
};
void __cdecl ShaderPassHelper_e804d0(ShaderPassOwnerPtr& owner);
void __cdecl ShaderPassSetup_be0cf0(StageReturn* pass, int index, int a, int b, int c);

int __cdecl ShaderQuery_4dc060(int arg);

extern int DAT_011fcf84;
extern int DAT_011fcf88;
extern int DAT_011fc3a4;
extern int DAT_011fc3a8;

struct ShaderBase
{
    virtual void Initialize();
};

struct FUN_00bd0ae0_class : ShaderBase
{
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
    ShaderPassOwnerPtr m_spOwners[2];

    bool HairShader_CreatePasses();
};

// @fnv 0x00bd0ae0
// src: COMMUNITY 0x00bd0ae0
bool FUN_00bd0ae0_class::HairShader_CreatePasses()
{
    for (int i = 0; i < 2; i++)
    {
        ShaderPassHelper_e804d0(m_spOwners[i]);
        StageReturnPtr spRenderPass;

        CreateNewStage_e7edf0(spRenderPass);
        ShaderPassSetup_be0cf0(spRenderPass.m_p, 0, 1, 2, 1);
        m_spOwners[i]->InsertStage(m_spOwners[i]->m_pDirectInputDevice, spRenderPass);

        CreateNewStage_e7edf0(spRenderPass);
        ShaderPassSetup_be0cf0(spRenderPass.m_p, 1, 1, 2, 1);
        m_spOwners[i]->InsertStage(m_spOwners[i]->m_pDirectInputDevice, spRenderPass);

        CreateNewStage_e7edf0(spRenderPass);
        ShaderPassSetup_be0cf0(spRenderPass.m_p, 2, 1, 2, 1);
        m_spOwners[i]->InsertStage(m_spOwners[i]->m_pDirectInputDevice, spRenderPass);

        CreateNewStage_e7edf0(spRenderPass);
        ShaderPassSetup_be0cf0(spRenderPass.m_p, 3, 3, 2, 1);
        m_spOwners[i]->InsertStage(m_spOwners[i]->m_pDirectInputDevice, spRenderPass);

        CreateNewStage_e7edf0(spRenderPass);
        ShaderPassSetup_be0cf0(spRenderPass.m_p, 4, 1, 2, 1);
        m_spOwners[i]->InsertStage(m_spOwners[i]->m_pDirectInputDevice, spRenderPass);

        if (ShaderQuery_4dc060(0) >= 2)
        {
            CreateNewStage_e7edf0(spRenderPass);
            ShaderPassSetup_be0cf0(spRenderPass.m_p, 5, 3, 2, 1);
            m_spOwners[i]->InsertStage(m_spOwners[i]->m_pDirectInputDevice, spRenderPass);
        }
    }
    DAT_011fcf84 = DAT_011fcf88 = 0x482;
    DAT_011fc3a4 = 0x2c;
    DAT_011fc3a8 = 0x3c;
    return true;
}
}  // namespace fnv_00bd0ae0

extern int DAT_011fdff8;
extern int DAT_011fe000;

class FUN_00bd0cb0_base
{
  public:
    virtual void v00(int) = 0;
    virtual void v01(int) = 0;
    virtual void v02(int) = 0;
    virtual void v03(int) = 0;
    virtual void v04(int) = 0;
    virtual void v05(int) = 0;
    virtual void v06(int) = 0;
    virtual void v07(int) = 0;
    virtual void v08(int) = 0;
    virtual void v09(int) = 0;
    virtual void v10(int) = 0;
    virtual void v11(int) = 0;
    virtual void v12(int) = 0;
    virtual void v13(int) = 0;
    virtual void v14(int) = 0;
    virtual void v15(int) = 0;
    virtual void v16(int) = 0;
    virtual void v17(int) = 0;
    virtual void v18(int) = 0;
    virtual void v19(int) = 0;
    virtual void v20(int) = 0;
    virtual void v21(int) = 0;
    virtual void v22(int) = 0;
    virtual void v23(int) = 0;
    virtual void v24(int) = 0;
    virtual void v25(int) = 0;
    virtual void v26(int) = 0;
    virtual void v27(int) = 0;
    virtual void v28(int) = 0;
    virtual void v29(int) = 0;
    virtual void v30(int) = 0;
    virtual void v31(int) = 0;
    virtual void v32(int) = 0;
    virtual void v33(int) = 0;
    virtual void v34(int) = 0;
    virtual void v35(int) = 0;
    virtual void v36(int) = 0;
    virtual void v37(int) = 0;
    virtual void v38(int) = 0;
    virtual void v39(int) = 0;
    virtual void v40(int) = 0;
    virtual void v41(int) = 0;
    virtual void v42(int) = 0;
    virtual void v43(int) = 0;
    virtual void v44(int) = 0;
    virtual void v45(int) = 0;
    virtual void v46(int) = 0;
    virtual void v47(int) = 0;
    virtual void v48(int) = 0;
    virtual void v49(int) = 0;
    virtual void v50(int) = 0;
    virtual void v51(int) = 0;
    virtual void v52(int) = 0;
    virtual void v53(int) = 0;
    virtual void v54(int) = 0;
    virtual void v55(int) = 0;
    virtual void v56(int) = 0;
    virtual void v57(int) = 0;
    virtual void v58(int) = 0;
    virtual void v59(int) = 0;
    virtual void v60(int) = 0;
    virtual void v61(int) = 0;
    virtual void v62(int) = 0;
    virtual void v63(int) = 0;
    virtual void v64(int) = 0;
    virtual void v65(int) = 0;
    virtual void v66(int) = 0;
    virtual void v67(int) = 0;
    virtual void v68(int) = 0;
    virtual void v69(int) = 0;
    virtual void v70(int) = 0;
    virtual void v71(int) = 0;
    virtual void v72(int) = 0;
    virtual void v73(int) = 0;
};

class FUN_00bd0cb0_class : public FUN_00bd0cb0_base
{
  public:
    virtual void v74(int) = 0;
    void __thiscall CallVirtualOnGlobalRange();
};

// Calls v74 on this for each int in the global range from DAT_011fdff8 up to DAT_011fe000.
// @fnv 0x00bd0cb0
void __thiscall FUN_00bd0cb0_class::CallVirtualOnGlobalRange()
{
    int* p = &DAT_011fdff8;
    int* end = &DAT_011fe000;

    do
    {
        this->v74(*p);
        ++p;
    } while ((long)p < (long)end);
}

struct GlobalObjectO2_00bd0f60
{
    char* pData;
};
extern GlobalObjectO2_00bd0f60 g_01202330;

// @fnv 0x00bd0f60
// src: COMMUNITY 0x00bd0f60
GlobalObjectO2_00bd0f60* __cdecl HairShader_GetRTTI()
{
    return &g_01202330;
}

struct BdElem
{
    int m_00;

    BdElem();
    ~BdElem();
};

struct FUN_00bd2b60_base
{
    virtual void unk00();
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

    FUN_00bd2b60_base();
    ~FUN_00bd2b60_base();
};

struct FUN_00bd2b60_cls : FUN_00bd2b60_base
{
    int m_68;
    BdElem m_6c[4];
    BdElem m_7c[2];
    int m_84;
    float m_88;
    float m_8c;
    float m_90;
    float m_94;
    float m_98;
    float m_9c;
    float m_a0;
    float m_a4;

    FUN_00bd2b60_cls();
    virtual void unk00();
};

// Zeroes the float members m_88 through m_a4, sets m_84 to 0 and m_68 to 8.
// @fnv 0x00bd2b60
FUN_00bd2b60_cls::FUN_00bd2b60_cls()
{
    m_84 = 0;
    *(volatile float*)&m_88 = 0.0f;
    m_8c = 0.0f;
    m_90 = 0.0f;
    m_94 = 0.0f;
    m_98 = 0.0f;
    m_9c = 0.0f;
    m_a0 = 0.0f;
    m_a4 = 0.0f;
    *(volatile int*)&m_68 = 8;
}

extern int DAT_0120233c;

// @fnv 0x00bd2c30
// src: COMMUNITY 0x00bd2c30
void* __cdecl SpeedTreeFrondShader_GetRTTI()
{
    return &DAT_0120233c;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

struct ShaderRefObject
{
    virtual void Destroy();
    virtual void DeleteThis();
    long m_uiRefCount;
};

template <class T> struct ShaderRefPtr
{
    T* m_pObject;
    ShaderRefPtr<T>& operator=(T* object)
    {
        T* old = m_pObject;
        if (old != object)
        {
            if (old)
            {
                if (InterlockedDecrement((volatile long*)&old->m_uiRefCount) == 0)
                    old->DeleteThis();
            }
            m_pObject = object;
            if (m_pObject)
                InterlockedIncrement(&m_pObject->m_uiRefCount);
        }
        return *this;
    }
};

struct StageReturn
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
    int m_iObjectReferenceCount;
    void ReturnToPool();
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
        {
            m_pObject->DecRefCount();
        }
    }
};

struct ShaderPass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_kTextureStages;
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
    ShaderRefPtr<ShaderRefObject> m_spObject44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    ShaderRefPtr<ShaderRefObject> m_spObject5c;
    int SetStage(unsigned int index, StageReturn* stage);
};

struct ShaderPassPtr
{
    ShaderPass* m_pObject;
    ShaderPass* operator->() const
    {
        return m_pObject;
    }
};

void __cdecl ShaderCreatePass(ShaderPassPtr& pass);
void __cdecl AssignStageFromPool(StagePtr& stage);
void __cdecl ShaderSetupStage(StageReturn* stage, int a, int b, int c, int d);

struct FUN_00bd2d50_class
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
    ShaderRefObject* m_pObject6c;
    int unk70;
    int unk74;
    int unk78;
    ShaderRefObject* m_pObject7c;
    int unk80;
    ShaderPassPtr m_spPass;
    void CreateShaderPassWithStage();
};

// Creates a shader pass, builds a stage, configures it with ShaderSetupStage, assigns the stage to the pass, and sets the pass's two shader objects.
// @fnv 0x00bd2d50
void FUN_00bd2d50_class::CreateShaderPassWithStage()
{
    ShaderCreatePass(m_spPass);
    StagePtr stage;
    AssignStageFromPool(stage);
    ShaderSetupStage(stage.m_pObject, 0, 3, 2, 1);
    m_spPass->SetStage(m_spPass->m_kTextureStages, stage.m_pObject);
    m_spPass->m_spObject5c = m_pObject6c;
    m_spPass->m_spObject44 = m_pObject7c;
}

extern void* g_apvBD4000Shaders[30];

class BD4000Renderer
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
    virtual void vfunc3D();
    virtual void vfunc3E();
    virtual void vfunc3F();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void vfunc49();
    virtual void Register(void* pvShader);

    void RegisterAllShaders();
};

// Registers each of the 30 shader pointers in g_apvBD4000Shaders via Register.
// @fnv 0x00bd4000
void BD4000Renderer::RegisterAllShaders()
{
    for (int i = 0; i < 30; i++)
        Register(g_apvBD4000Shaders[i]);
}

namespace fnv_00bd4030 {
extern void* DAT_01202350;
extern void* DAT_01202354;
extern void* DAT_01202358;
extern void* DAT_0120235C;
extern void* DAT_01202360;
extern void* DAT_01202364;
extern void* DAT_01202368;
extern void* DAT_0120236C;
extern void* DAT_01202370;
extern void* DAT_01202374;
extern void* DAT_01202378;
extern void* DAT_0120237C;
extern void* DAT_01202380;
extern void* DAT_01202384;
extern void* DAT_01202388;
extern void* DAT_0120238C;
extern void* DAT_01202390;
extern void* DAT_01202394;
extern void* DAT_01202398;
extern void* DAT_0120239C;
extern void* DAT_012023A0;
extern void* DAT_012023A4;
extern void* DAT_012023A8;
extern void* DAT_012023AC;
extern void* DAT_012023B0;
extern void* DAT_012023B4;
extern void* DAT_012023B8;
extern void* DAT_012023BC;
extern void* DAT_012023C0;
extern void* DAT_012023C4;
extern void* DAT_0126F74C;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct RefObj
{
    virtual void v0();
    virtual void Release();
    long m_iObjectReferenceCount;
};
struct FUN_00bd4030_class
{
    char pad00[0x28];
    RefObj* m_p28;
    char pad2c[0x40];
    RefObj* m_p6c;
    void UpdateReferenceState_00bd4030(unsigned int code);
};
// @fnv 0x00bd4030
// src: GUESS 0x00bd4030 (confidence: low)
void FUN_00bd4030_class::UpdateReferenceState_00bd4030(unsigned int code)
{
    switch (code)
    {
    case 0x151:
        DAT_0126F74C = DAT_01202368;
        break;
    case 0xdf:
        DAT_0126F74C = DAT_01202378;
        break;
    case 0xe8:
        DAT_0126F74C = DAT_0120237C;
        break;
    case 0xf1:
        DAT_0126F74C = DAT_01202380;
        break;
    case 0xfa:
        DAT_0126F74C = DAT_01202384;
        break;
    case 0x108:
        DAT_0126F74C = DAT_01202388;
        break;
    case 0x114:
        DAT_0126F74C = DAT_0120238C;
        break;
    case 0x11f:
        DAT_0126F74C = DAT_01202390;
        break;
    case 0x12a:
        DAT_0126F74C = DAT_01202394;
        break;
    case 0x9f:
        DAT_0126F74C = DAT_01202398;
        break;
    case 0xaa:
        DAT_0126F74C = DAT_0120239C;
        break;
    case 0xb5:
        DAT_0126F74C = DAT_012023A0;
        break;
    case 0xc0:
        DAT_0126F74C = DAT_012023A4;
        break;
    case 0x137:
        DAT_0126F74C = DAT_012023A8;
        break;
    case 0x143:
        DAT_0126F74C = DAT_012023AC;
        break;
    case 0x60:
        DAT_0126F74C = DAT_01202350;
        break;
    case 0x7a:
        DAT_0126F74C = DAT_01202354;
        break;
    case 0x7b:
        DAT_0126F74C = DAT_01202358;
        break;
    case 0x7e:
        DAT_0126F74C = DAT_0120235C;
        break;
    case 0x130:
        DAT_0126F74C = DAT_01202360;
        break;
    case 0x131:
        DAT_0126F74C = DAT_01202364;
        break;
    case 0x158:
        DAT_0126F74C = DAT_0120236C;
        break;
    case 0x159:
        DAT_0126F74C = DAT_01202370;
        break;
    case 0x15f:
        DAT_0126F74C = DAT_012023B0;
        break;
    case 0x256:
        DAT_0126F74C = DAT_01202374;
        break;
    case 0x165:
        DAT_0126F74C = DAT_012023B4;
        break;
    case 0x16b:
        DAT_0126F74C = DAT_012023B8;
        break;
    case 0x171:
        DAT_0126F74C = DAT_012023BC;
        break;
    case 0x177:
        DAT_0126F74C = DAT_012023C0;
        break;
    case 0x234:
        DAT_0126F74C = DAT_012023C4;
        break;
    }
    RefObj* nv = m_p6c;
    RefObj* old = m_p28;
    if (old != nv)
    {
        if (old)
        {
            if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->Release();
        }
        m_p28 = nv;
        if (nv)
            InterlockedIncrement(&nv->m_iObjectReferenceCount);
    }
}
}  // namespace fnv_00bd4030

namespace fnv_00bd44c0 {

struct FUN_00b79b00
{
    virtual void vf00();
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
    FUN_00b79b00(int, int, int, int);
    ~FUN_00b79b00();
};

struct FUN_00bd44c0 : FUN_00b79b00
{
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    StagingNiPointer<NiD3DPixelShader> unk8c[30];
    StagingNiPointer<NiD3DVertexShader> unk104[10];
    FUN_00bd44c0(int a);
};

// Initializes the base FUN_00b79b00 with a and zeros, then sets unk68 to 5.
// @fnv 0x00bd44c0
FUN_00bd44c0::FUN_00bd44c0(int a) : FUN_00b79b00(a, 0, 0, 0)
{
    unk68 = 5;
}
}  // namespace fnv_00bd44c0

extern int DAT_01202348;

// @fnv 0x00bd4560
// src: COMMUNITY 0x00bd4560
void* __cdecl SpeedTreeBranchShader_GetRTTI()
{
    return &DAT_01202348;
}

namespace fnv_00bd4570 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct FUN_00b79de0
{
    virtual ~FUN_00b79de0();
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
};
struct GlobalRef
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
    int refs;
    void FUN_00e80190();
};
extern GlobalRef* DAT_01202350[30];
struct FUN_00bd4570 : FUN_00b79de0
{
    AtomicNiPointer<NiD3DPixelShader> pixels[30];
    AtomicNiPointer<NiD3DVertexShader> vertices[10];
    virtual ~FUN_00bd4570();
};
// @fnv 0x00bd4570
FUN_00bd4570::~FUN_00bd4570()
{
    for (unsigned int i = 0; i < 30; ++i)
        pixels[i] = (NiD3DPixelShader*)0;
    for (unsigned int i = 0; i < 10; ++i)
        vertices[i] = (NiD3DVertexShader*)0;
    for (int i = 0; i < 30; ++i)
    {
        GlobalRef* object = DAT_01202350[i];
        if (object)
        {
            if (--object->refs == 0)
                object->FUN_00e80190();
            DAT_01202350[i] = 0;
        }
    }
}
}  // namespace fnv_00bd4570

struct FUN_00bd46a0_Obj
{
    virtual void Unused();
    virtual void Release();
    long m_iObjectReferenceCount;
};

struct FUN_00bd46a0_Item
{
    char pad_00[0x64];
    int m_uiItemCount;

    void __thiscall OnLastRef();
};

struct FUN_00bd46a0_cls
{
    char pad_00[0x8c];
    FUN_00bd46a0_Obj* m_slots[30];
    FUN_00bd46a0_Obj* m_slots2[10];

    bool __thiscall ClearAllReferences();
    void __thiscall FUN_00be0870();
};

extern FUN_00bd46a0_Item* DAT_01202350[30];

// @fnv 0x00bd46a0
bool __thiscall FUN_00bd46a0_cls::ClearAllReferences()
{
    int i;
    FUN_00bd46a0_Obj* obj;
    FUN_00bd46a0_Item* item;

    FUN_00be0870();
    for (i = 0; i < 30; i++)
    {
        obj = m_slots[i];
        if (obj != 0)
        {
            if (InterlockedDecrement(&obj->m_iObjectReferenceCount) == 0)
            {
                obj->Release();
            }
            m_slots[i] = 0;
        }
    }
    for (i = 0; i < 10; i++)
    {
        obj = m_slots2[i];
        if (obj != 0)
        {
            if (InterlockedDecrement(&obj->m_iObjectReferenceCount) == 0)
            {
                obj->Release();
            }
            m_slots2[i] = 0;
        }
    }
    for (i = 0; i < 30; i++)
    {
        item = DAT_01202350[i];
        if (item != 0)
        {
            item->m_uiItemCount += -1;
            if (item->m_uiItemCount == 0)
            {
                item->OnLastRef();
            }
            DAT_01202350[i] = 0;
        }
    }
    return true;
}

struct S_00bd6150_Foo
{
    int unk00;
    int unk04;
    int unk08;
    short unk0c;
    unsigned short m_uiItemCount;
    float* m_kFloatData;
    int* m_intData;

    void __thiscall DistantLODGroup_UpdateGroupBound();
    void ResetEntries();
};

// @fnv 0x00bd6150
void S_00bd6150_Foo::ResetEntries()
{
    for (int i = 0; i < (int)m_uiItemCount; ++i)
    {
        m_kFloatData[i * 4 + 2] = 0.0f;
        m_kFloatData[i * 4 + 3] = 0.0f;
        m_intData[i] = 0;
    }

    m_uiItemCount = 0;
    DistantLODGroup_UpdateGroupBound();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);

struct CallbackOwner;
struct ReleaseCallback
{
    virtual void Method00();
    virtual void Method01();
    virtual void Method02();
    virtual void Method03();
    virtual void Method04();
    virtual void Method05();
    virtual void Method06();
    virtual void Method07();
    virtual void Method08();
    virtual void Method09();
    virtual void Method10();
    virtual void Method11();
    virtual void Method12();
    virtual void Method13();
    virtual void Method14();
    virtual void Method15();
    virtual void Method16();
    virtual void Method17();
    virtual void Method18();
    virtual void Method19();
    virtual void Method20();
    virtual void Method21();
    virtual void Method22();
    virtual void Method23();
    virtual void Method24();
    virtual void Method25();
    virtual void Method26();
    virtual void Method27();
    virtual void Method28();
    virtual void Method29();
    virtual void Method30();
    virtual void Method31();
    virtual void Method32();
    virtual void Method33();
    virtual void Method34();
    virtual void Method35();
    virtual void Method36();
    virtual void Method37();
    virtual void Method38();
    virtual void Method39();
    virtual void Method40();
    virtual void Method41();
    virtual void Method42();
    virtual void Method43();
    virtual void Method44();
    virtual void Method45();
    virtual void Method46();
    virtual void Method47();
    virtual void Method48();
    virtual void Method49();
    virtual void Method50();
    virtual void Method51();
    virtual void Method52();
    virtual void Method53();
    virtual void Method54();
    virtual void Method55();
    virtual void Method56();
    virtual void Method57();
    virtual void OnDetach(CallbackOwner* owner);
};

struct CallbackOwner
{
    virtual void Unused();
    virtual void Release();
    volatile long referenceCount;
    void* unknown08;
    void* unknown0c;
    void* unknown10;
    void* unknown14;
    ReleaseCallback* callback;
    void DecrementReference()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            Release();
    }
};

struct ObjectReference
{
    CallbackOwner* object;
    void Reset()
    {
        if (object)
        {
            object->DecrementReference();
            object = 0;
        }
    }
    ~ObjectReference()
    {
        if (object)
            object->DecrementReference();
    }
};

struct FUN_00bd6570
{
    ObjectReference owner;
    ObjectReference other;
    ObjectReference additional;
    void* unknown0c;
    void* allocation10;
    void* allocation14;
    void ResetEntries();
    ~FUN_00bd6570();
};
// Releases the three object references, detaches the owner's callback, frees allocation10 and allocation14, and calls ResetEntries.
// @fnv 0x00bd6570
FUN_00bd6570::~FUN_00bd6570()
{
    additional.Reset();
    other.Reset();
    if (owner.object->callback)
        owner.object->callback->OnDetach(owner.object);
    owner.Reset();
    ResetEntries();
    if (allocation10)
    {
        g_memoryManager.Deallocate(allocation10);
        allocation10 = 0;
    }
    {
        void* buffer = allocation14;
        g_memoryManager.Deallocate(buffer);
    }
    allocation14 = 0;
}

class BdRef;
class BdData;
class BdQuery
{
  public:
    unsigned int unk00;
    void Query(int slot, unsigned int* out);
};
class BdRef
{
  public:
    unsigned int unk00;
    void Touch();
};
class BdData
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    BdRef* m_08;
    BdRef* m_0c;
    unsigned int unk10;
    int m_14;
};
class FUN_00bd6a30_cls
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
    unsigned int unk24;
    BdQuery m_28;
    BdData* m_2c;
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
    BdRef m_7c;
    void TouchRefsAndQuery();
};
// Touches m_2c's refs, queries slots 2-4 into v, and if m_2c->m_14 is nonzero touches m_7c and queries slot 5.
// @fnv 0x00bd6a30
void FUN_00bd6a30_cls::TouchRefsAndQuery()
{
    m_2c->m_08->Touch();
    unsigned int v = 0;
    m_28.Query(2, &v);
    m_2c->m_0c->Touch();
    v = 0;
    m_28.Query(3, &v);
    v = 0;
    m_28.Query(4, &v);
    if (m_2c->m_14 != 0)
    {
        m_7c.Touch();
        v = 0;
        m_28.Query(5, &v);
    }
}

void* __cdecl NiMalloc(unsigned int uiSize);
void __cdecl NiFree(void* pvMem);

template <class T> class BBD6AE0MallocInterface
{
  public:
    static T* Allocate(unsigned int auiCount)
    {
        return (T*)NiMalloc(sizeof(T) * auiCount);
    }
    static void Deallocate(T* pArray)
    {
        NiFree(pArray);
    }
};



// Resizes the array to uiMaxSize: trims and clears removed elements, reallocates storage, copies existing elements and zero-fills the rest.
// @fnv 0x00bd6ae0
template <class T, class TAlloc> void NiTArray<T, TAlloc>::SetSize(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_usMaxSize)
        return;

    unsigned short i;
    if (uiMaxSize < m_usSize)
    {
        for (i = (unsigned short)uiMaxSize; i < m_usSize; i++)
        {
            if (m_pBase[i] != T(0))
            {
                m_pBase[i] = T(0);
                m_usESize--;
            }
        }
        m_usSize = (unsigned short)uiMaxSize;
    }

    T* pSaveBase = m_pBase;
    m_usMaxSize = (unsigned short)uiMaxSize;
    if (uiMaxSize > 0)
    {
        m_pBase = TAlloc::Allocate(m_usMaxSize);
        for (i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
        for (i = m_usSize; i < m_usMaxSize; i++)
            m_pBase[i] = T(0);
    }
    else
    {
        m_pBase = 0;
    }
    TAlloc::Deallocate(pSaveBase);
}

template class NiTArray<bool, BBD6AE0MallocInterface<bool> >;

// Candidate reconstruction of FUN_00bd7120 (a constructor).
struct FNV_Elem_00bd7120
{
    unsigned char b00;
    unsigned char b01;
    unsigned char b02;
    int p04;
    volatile int p08;
    int p0c;
    FNV_Elem_00bd7120();
    ~FNV_Elem_00bd7120();
};

FNV_Elem_00bd7120::FNV_Elem_00bd7120()
{
    b00 = 0;
    b01 = 0;
    b02 = 0;
    p04 = 0;
    p08 = 0;
    p0c = 0;
}

struct FNV_Sub28_00bd7120
{
    void FNV_SetSize_00bd7120(int n);
    char pad[0x10];
};

struct FNV_Sub58_00bd7120
{
    void FNV_SetSize_00bd7120(int n);
    char pad[0x10];
};

struct FNV_Base_00bd7120
{
    char unk04[0x24];
    FNV_Sub28_00bd7120 m_28;
    char unk38[0x20];
    FNV_Sub58_00bd7120 m_58;
    FNV_Base_00bd7120();
    virtual ~FNV_Base_00bd7120();
    void FNV_Final_00bd7120();
};

struct FUN_00bd7120_Class : FNV_Base_00bd7120
{
    float m_f68;
    float m_f6c;
    float m_f70;
    int m_i74;
    int m_i78;
    FNV_Elem_00bd7120 m_uiX;
    FNV_Elem_00bd7120 m_aiIndexedValues[3];
    FUN_00bd7120_Class();
    ~FUN_00bd7120_Class();
    virtual void FUN_00bd7120_v1();
};

// Initializes the object: sets the sizes of m_28 and m_58, zeroes m_f68, m_f6c, m_f70 and m_i74, then calls FNV_Final_00bd7120.
// @fnv 0x00bd7120
FUN_00bd7120_Class::FUN_00bd7120_Class()
{
    m_28.FNV_SetSize_00bd7120(6);
    m_f68 = 0.0f;
    m_f6c = 0.0f;
    m_f70 = 0.0f;
    m_i74 = 0;
    m_58.FNV_SetSize_00bd7120(4);
    FNV_Final_00bd7120();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

struct Base_bd74a0
{
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
    virtual ~Base_bd74a0();
};

struct FUN_00bd74a0 : Base_bd74a0
{
    AtomicNiPointer<NiRefObject> m_spArr[6];
    AtomicNiPointer<NiRefObject> m_sp130;
    int unk134;
    AtomicNiPointer<NiRefObject> m_sp138;
    AtomicNiPointer<NiRefObject> m_sp13c;
    virtual ~FUN_00bd74a0();
};

// Destructor that clears the six m_spArr entries and the m_sp130 and m_sp13c reference-counted pointers.
// @fnv 0x00bd74a0
FUN_00bd74a0::~FUN_00bd74a0()
{
    for (int i = 0; i < 6; i++)
        m_spArr[i] = 0;
    m_sp130 = 0;
    m_sp13c = 0;
}

// Accessor for the global object at 0x012023e8.
extern int DAT_012023e8;

// @fnv 0x00bd7610
// src: XBOX_PDB 0x00bd7610
int* __cdecl BSCubeMapCamera_GetRTTI()
{
    return &DAT_012023e8;
}

extern float DAT_0104eb20;
extern int DAT_011f9ef8;

struct RemovableEntry
{
    float m_f00;
    float m_f04;
    float m_f08;
    float m_f0C;
};

struct FUN_00bd85b0_cls
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    unsigned short m_unk10;
    unsigned short m_uiItemCount;
    RemovableEntry* m_pEntries;
    unsigned int* m_pKeys;
    int RemoveEntry(unsigned short index);
};

// Removes the entry at index by moving the last entry into its slot, clearing the last slot, and decrementing the count and a global counter.
// @fnv 0x00bd85b0
int FUN_00bd85b0_cls::RemoveEntry(unsigned short index)
{
    if (index < m_uiItemCount)
    {
        if ((int)index != (int)m_uiItemCount - 1)
        {
            m_pEntries[index] = m_pEntries[m_uiItemCount - 1];
            m_pKeys[index] = m_pKeys[m_uiItemCount - 1];
        }
        m_pEntries[m_uiItemCount - 1].m_f00 = 0.0f;
        m_pEntries[m_uiItemCount - 1].m_f04 = 0.0f;
        m_pEntries[m_uiItemCount - 1].m_f08 = DAT_0104eb20;
        m_pEntries[m_uiItemCount - 1].m_f0C = 0.0f;
        m_pKeys[m_uiItemCount - 1] = 0;
        m_uiItemCount--;
        DAT_011f9ef8--;
    }
    return m_uiItemCount;
}

// FUN_00bd9120: builds an array of 4-byte elements and hands the pointer to the owner.
//
// The element type carries its own array allocator: the compiler turns
// "new Element[count]" into the total byte count (with the usual overflow
// guard) and then calls the allocator that lives in the global holder.

struct Bd9120Allocator
{
    void* Game_DoHeapAlloc(unsigned int size);  // allocates size bytes, callee pops
};

extern Bd9120Allocator DAT_011f6238;

// Allocate unconstructed vector storage with the game's array allocator.
inline void* operator new[](unsigned int size, Bd9120Allocator& allocator)
{
    return allocator.Game_DoHeapAlloc(size);
}
  // the global allocator holder
extern int DAT_011bf558;              // number of elements to build

struct Bd9120Element
{
    static void* operator new[](unsigned int bytes)
    {
        return DAT_011f6238.Game_DoHeapAlloc(bytes);
    }
    int m_uiFilterValue;
};

struct Bd9120Buffer
{
    Bd9120Element* m_pElements;

    void* InitializeFields_00bd9120();
};

// Allocates an array of Bd9120Element of size DAT_011bf558, stores it in m_pElements and returns this.
// @fnv 0x00bd9120
// src: GUESS 0x00bd9120 (confidence: low)
void* Bd9120Buffer::InitializeFields_00bd9120()
{
    m_pElements = new Bd9120Element[DAT_011bf558];
    return this;
}

struct Global_00bd9240
{
    char pad[0x2f8];
    Vec4 m_2f8;
};

extern Global_00bd9240* DAT_011f91ac;

struct Callee_00b8a790
{
    int Run(int flag, float x, float y, float z, float w);
};

struct Inner_00bd9240
{
    Callee_00b8a790* m_00;
};

struct FUN_00bd9240_cls
{
    char pad[0x1c];
    Inner_00bd9240* m_1c;

    bool RunWithGlobalVector(unsigned char flag);
};

// Copies the global Vec4 at DAT_011f91ac->m_2f8 and passes its components to m_1c->m_00->Run with flag 0, then returns true.
// @fnv 0x00bd9240
bool FUN_00bd9240_cls::RunWithGlobalVector(unsigned char flag)
{
    Vec4 tmp(Vec4::Uninitialized);
    tmp = DAT_011f91ac->m_2f8;
    m_1c->m_00->Run(0, tmp.x, tmp.y, tmp.z, tmp.w);
    return true;
}

struct FUN_00bd92b0_mgr
{
    virtual void v0();
    virtual void v1(int a, int b, int c, int d);
    void SetAccumulatorAt(int idx, int val, int flag);
    void BSTextureManager_ReturnRenderedTexture(int v);
};

struct FUN_00bd92b0_sub
{
    void ImageSpaceTexture_ClearTexture();
    int ImageSpaceTexture_GetRenderedTexture();
};

extern int DAT_011f91a8;

struct FUN_00bd92b0_class
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual unsigned char v7(int a);
    char m_pad4;
    unsigned char m_b5;
    char unk06[6];
    int* m_p0c;
    char unk10[0x0c];
    int* m_p1c;
    char unk20[0x0c];
    int* m_p2c;

    void ImageSpaceEffectRefraction_Render(int a1, int a2, int a3, int a4);
};

// @fnv 0x00bd92b0
// src: COMMUNITY 0x00bd92b0
void FUN_00bd92b0_class::ImageSpaceEffectRefraction_Render(int a1, int a2, int a3, int a4)
{
    if (m_b5)
        m_b5 = v7(a3);

    int inner = *m_p0c;
    char* base = inner ? (char*)inner - 0x6c : 0;
    FUN_00bd92b0_mgr* pMgr = (FUN_00bd92b0_mgr*)(base + 0x6c);

    int* pField2c = m_p2c;
    int* pField1c = m_p1c;
    int iField2c0 = *pField2c;
    int b = *pField1c;

    pMgr->SetAccumulatorAt(0, iField2c0, 0);
    pMgr->SetAccumulatorAt(1, m_p2c[1], 0);
    FUN_00bd92b0_sub* sub = (FUN_00bd92b0_sub*)((char*)this + 0x58);
    pMgr->SetAccumulatorAt(2, (int)sub, 0);

    pMgr->v1(a1, a2, b, 1);

    pMgr->SetAccumulatorAt(0, 0, 0);
    pMgr->SetAccumulatorAt(1, 0, 0);
    pMgr->SetAccumulatorAt(2, 0, 0);

    FUN_00bd92b0_mgr* g = (FUN_00bd92b0_mgr*)DAT_011f91a8;
    int r = sub->ImageSpaceTexture_GetRenderedTexture();
    g->BSTextureManager_ReturnRenderedTexture(r);
    sub->ImageSpaceTexture_ClearTexture();
}

struct ShadowSceneLight;
struct PassArray9840
{
    void __thiscall FUN_00ba9ee0(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*,
                                 ShadowSceneLight*, ShadowSceneLight*);
};
struct Shader9840
{
    void* field00;
    void* field04;
    void* field08;
    void* field0c;
    void* field10;
    void* field14;
    void* field18;
    void* field1c;
    void* field20;
    void* field24;
    void* field28;
    void* field2c;
    void* field30;
    void* field34;
    void* field38;
    PassArray9840* passes;
    int __thiscall BSShaderProperty_AddPass_DiffuseDirOrPoint(NiGeometry*, ShadowSceneLight*, unsigned short*, unsigned char, bool&, bool, bool, bool,
                                bool);
};
// Chooses a pass index from the boolean flags and type, calls the pass array for type 1 or increments count otherwise, then clears out and returns 0.
// @fnv 0x00bd9840
// src: COMMUNITY 0x00bd9840
int Shader9840::BSShaderProperty_AddPass_DiffuseDirOrPoint(NiGeometry* geometry, ShadowSceneLight* light, unsigned short* count, unsigned char type,
                             bool& out, bool a, bool b, bool c, bool d)
{
    if (!a)
    {
        if (!b)
        {
            if (!d)
            {
                if (type == 1)
                {
                    passes->FUN_00ba9ee0(geometry, 300, out, 1, light, 0, 0, 0);
                }
                else
                {
                    ++*count;
                }
            }
            else
            {
                if (type == 1)
                {
                    passes->FUN_00ba9ee0(geometry, 304, out, 1, light, 0, 0, 0);
                }
                else
                {
                    ++*count;
                }
            }
        }
        else
        {
            if (!d)
            {
                if (type == 1)
                {
                    passes->FUN_00ba9ee0(geometry, 301, out, 1, light, 0, 0, 0);
                }
                else
                {
                    ++*count;
                }
            }
            else
            {
                if (type == 1)
                {
                    passes->FUN_00ba9ee0(geometry, 305, out, 1, light, 0, 0, 0);
                }
                else
                {
                    ++*count;
                }
            }
        }
    }
    else
    {
        if (!b)
        {
            if (type == 1)
            {
                passes->FUN_00ba9ee0(geometry, 302, out, 1, light, 0, 0, 0);
            }
            else
            {
                ++*count;
            }
        }
        else
        {
            if (type == 1)
            {
                passes->FUN_00ba9ee0(geometry, 303, out, 1, light, 0, 0, 0);
            }
            else
            {
                ++*count;
            }
        }
    }
    out = false;
    return 0;
}

struct ShadowSceneLight;

struct Shader_00bd9bc0
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
    BSShaderProperty::ShaderPassList* pPasses;

    int BSShaderProperty_AddPass_Fog(NiGeometry* geom, unsigned short* count, unsigned char type, bool* enabled, bool a, bool b,
                     bool c);
};

// @fnv 0x00bd9bc0
// src: COMMUNITY 0x00bd9bc0
int Shader_00bd9bc0::BSShaderProperty_AddPass_Fog(NiGeometry* geom, unsigned short* count, unsigned char type, bool* enabled, bool a,
                                  bool b, bool c)
{
    if (!b)
    {
        if (!a)
        {
            if (!c)
            {
                if (type == 1)
                    pPasses->Add(geom, 0x252, *enabled, 0, 0, 0, 0, 0);
                else
                    ++*count;
            }
            else
            {
                if (type == 1)
                    pPasses->Add(geom, 0x253, *enabled, 0, 0, 0, 0, 0);
                else
                    ++*count;
            }
        }
        else
        {
            if (!c)
            {
                if (type == 1)
                    pPasses->Add(geom, 0x254, *enabled, 0, 0, 0, 0, 0);
                else
                    ++*count;
            }
            else
            {
                if (type == 1)
                    pPasses->Add(geom, 0x255, *enabled, 0, 0, 0, 0, 0);
                else
                    ++*count;
            }
        }
    }
    else
    {
        if (type == 1)
            pPasses->Add(geom, 0x256, *enabled, 0, 0, 0, 0, 0);
        else
            ++*count;
    }
    *enabled = false;
    return 0;
}

struct ShaderPassSelection : Shader_00bd9540
{
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    BSShaderProperty::ShaderPassList* additionalPasses;
    int AddAdditionalPass(NiGeometry* geometry, unsigned int unused, bool enabled, bool alternate);
};

// If enabled and additionalPasses is set, adds geometry to additionalPasses with pass id 21 when alternate is true, otherwise 20, and returns 0.
// @fnv 0x00bda030
int ShaderPassSelection::AddAdditionalPass(NiGeometry* geometry, unsigned int unused, bool enabled, bool alternate)
{
    if (enabled && additionalPasses)
        additionalPasses->Add(geometry, alternate ? 21 : 20, false, 0, 0, 0, 0, 0);
    return 0;
}

struct FUN_00ba9ee0_Class
{
    void __thiscall FUN_00ba9ee0(int a, int b, int c, int d, int e, int f, int g, int h);
};

struct FUN_00bda060_Class
{
    char pad[0x44];
    FUN_00ba9ee0_Class* m_44;

    void __thiscall BSShaderProperty_AddConstAlphaPass(int a, bool b, bool c);
};

// @fnv 0x00bda060
// src: COMMUNITY 0x00bda060
void __thiscall FUN_00bda060_Class::BSShaderProperty_AddConstAlphaPass(int a, bool abUseMode8, bool abUseMode7)
{
    if (abUseMode8)
    {
        m_44->FUN_00ba9ee0(a, 8, 1, 0, 0, 0, 0, 0);
    }
    else
    {
        m_44->FUN_00ba9ee0(a, abUseMode7 ? 7 : 6, 1, 0, 0, 0, 0, 0);
    }
}

namespace fnv_00bdb380 {
struct Key
{
    unsigned int first, second, third;
    bool FUN_00439090(const Key* other);
};
extern "C" Key DAT_011f4998;
struct AllocationManager
{
    void* Game_DoHeapAlloc(unsigned int count);
};
extern "C" AllocationManager DAT_011f6238;
// Exe 0x00bdb380: unit-local ShaderPassEntry view; declarations and layout are preserved.

struct RenderPassStack
{
    unsigned int field00;
    BSShaderProperty::ShaderPassEntry** passes;
    unsigned int field08;
    unsigned int field0c;
    unsigned int count;
    BSShaderProperty::ShaderPassEntry* Last() const
    {
        return passes[count - 1];
    }
};
struct Message
{
    unsigned int type;
    unsigned int actor;
    unsigned int data;
    unsigned int state;
    __cdecl Message(void* actor, unsigned int code, int first, int second, int third, ...);
    static void* operator new(unsigned int count)
    {
        return DAT_011f6238.Game_DoHeapAlloc(count);
    }
};
struct Shader
{
    Message* CreatePassMessage(void* actor, unsigned short* missed, unsigned char passType, unsigned char useAlternate,
                               unsigned int context);
};
// Checks the actor's resource key against DAT_011f4998, enables the last render pass, and returns a new Message (0x2d6/0x2d7) or increments missed.
// @fnv 0x00bdb380
Message* Shader::CreatePassMessage(void* actor, unsigned short* missed, unsigned char passType,
                                   unsigned char useAlternate, unsigned int context)
{
    Message* result = 0;
    void* resource = *reinterpret_cast<void**>(reinterpret_cast<char*>(actor) + 0xa4);
    if (resource)
    {
        Key* key = *reinterpret_cast<Key**>(reinterpret_cast<char*>(resource) + 0x34);
        if (!key)
            key = reinterpret_cast<Key*>(reinterpret_cast<char*>(resource) + 0x28);
        if (Key(*key).FUN_00439090(&DAT_011f4998))
        {
            RenderPassStack* stack = *reinterpret_cast<RenderPassStack**>(reinterpret_cast<char*>(this) + 0x3c);
            BSShaderProperty::ShaderPassEntry* last = stack->Last();
            if (last)
                last->m_bRendered = true;
            if (!useAlternate)
            {
                if (passType == 1)
                {
                    result = new Message(actor, 0x2d6, 0, 0, 0);
                }
                else
                {
                    ++*missed;
                }
            }
            else
            {
                if (passType == 1)
                {
                    result = new Message(actor, 0x2d7, 0, 0, 0);
                }
                else
                {
                    ++*missed;
                }
            }
        }
    }
    return result;
}
}  // namespace fnv_00bdb380

struct ShaderTarget
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
    BSShaderProperty::ShaderPassList* pPasses;
    int BSShaderProperty_AddPass_AD2(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, unsigned char, bool*, bool,
                     bool, bool, bool, bool, bool, bool);
};
// Selects a shader pass index from the boolean flags and type, adds it to pPasses when type is 1, otherwise increments count; sets out to false and returns 0.
// @fnv 0x00bdc0d0
// src: COMMUNITY 0x00bdc0d0
int ShaderTarget::BSShaderProperty_AddPass_AD2(NiGeometry* geometry, ShadowSceneLight* light0, ShadowSceneLight* light1,
                               unsigned short* count, unsigned char type, bool* out, bool a, bool b, bool c,
                               bool unused, bool d, bool e, bool f)
{
    if (!a)
    {
        if (!b)
        {
            if (!c)
            {
                if (!e)
                {
                    if (!d)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->Add(geometry, 0xd7, true, 2, light0, light1, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->Add(geometry, 0xdf, true, 2, light0, light1, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->Add(geometry, 0xe0, true, 2, light0, light1, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->Add(geometry, 0xe8, true, 2, light0, light1, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
                else
                {
                    if (!d)
                    {
                        if (type == 1)
                            pPasses->Add(geometry, 0xd9, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                    else
                    {
                        if (type == 1)
                            pPasses->Add(geometry, 0xe2, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                }
            }
            else
            {
                if (!d)
                {
                    if (type == 1)
                        pPasses->Add(geometry, 0xdb, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
                else
                {
                    if (type == 1)
                        pPasses->Add(geometry, 0xe4, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
            }
        }
        else
        {
            if (!c)
            {
                if (!d)
                {
                    if (type == 1)
                        pPasses->Add(geometry, 0xd8, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
                else
                {
                    if (type == 1)
                        pPasses->Add(geometry, 0xe1, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
            }
        }
    }
    else
    {
        if (!b)
        {
            if (!c)
            {
                if (!e)
                {
                    if (!d)
                    {
                        if (type == 1)
                            pPasses->Add(geometry, 0xdc, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                    else
                    {
                        if (type == 1)
                            pPasses->Add(geometry, 0xe5, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                }
            }
            else
            {
                if (!d)
                {
                    if (type == 1)
                        pPasses->Add(geometry, 0xde, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
                else
                {
                    if (type == 1)
                        pPasses->Add(geometry, 0xe7, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
            }
        }
        else
        {
            if (!c)
            {
                if (!d)
                {
                    if (type == 1)
                        pPasses->Add(geometry, 0xdd, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
                else
                {
                    if (type == 1)
                        pPasses->Add(geometry, 0xe6, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
            }
        }
    }
    *out = false;
    return 0;
}

struct PassArray
{
    void FUN_00ba9ee0(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*,
                      ShadowSceneLight*, ShadowSceneLight*);
};
struct ShaderPassSelector : Shader_00bd9540
{
    int BSShaderProperty_AddPass_DiffusePoint2(NiGeometry* geom, ShadowSceneLight* light0, ShadowSceneLight* light1, unsigned short* count,
                     unsigned char type, bool* out, bool a, bool b, bool c, bool d, bool e);
};
// Picks a shadow pass id from the a/b/d/e flags and type, adds it via FUN_00ba9ee0 when type==1, otherwise increments *count, then clears *out.
// @fnv 0x00bdda20
// src: COMMUNITY 0x00bdda20
int ShaderPassSelector::BSShaderProperty_AddPass_DiffusePoint2(NiGeometry* geom, ShadowSceneLight* light0, ShadowSceneLight* light1,
                                     unsigned short* count, unsigned char type, bool* out, bool a, bool b, bool c,
                                     bool d, bool e)
{
    if (!a)
    {
        if (!b)
        {
            if (!d)
            {
                if (!e)
                {
                    if (type == 1)
                    {
                        ((PassArray*)pPasses)->FUN_00ba9ee0(geom, 0x132, *out, 2, light0, light1, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
                else
                {
                    if (type == 1)
                    {
                        ((PassArray*)pPasses)->FUN_00ba9ee0(geom, 0x137, *out, 2, light0, light1, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
            }
            else
            {
                if (type == 1)
                {
                    ((PassArray*)pPasses)->FUN_00ba9ee0(geom, 0x134, *out, 2, light0, light1, 0, 0);
                }
                else
                {
                    ++*count;
                }
            }
        }
        else
        {
            if (type == 1)
            {
                ((PassArray*)pPasses)->FUN_00ba9ee0(geom, 0x133, *out, 2, light0, light1, 0, 0);
            }
            else
            {
                ++*count;
            }
        }
    }
    else
    {
        if (!b)
        {
            if (!d)
            {
                if (type == 1)
                {
                    ((PassArray*)pPasses)->FUN_00ba9ee0(geom, 0x135, *out, 2, light0, light1, 0, 0);
                }
                else
                {
                    ++*count;
                }
            }
        }
        else
        {
            if (type == 1)
            {
                ((PassArray*)pPasses)->FUN_00ba9ee0(geom, 0x136, *out, 2, light0, light1, 0, 0);
            }
            else
            {
                ++*count;
            }
        }
    }
    *out = false;
    return 0;
}

// Shader property render-pass collection: when only counting/adding the single override pass, add pass
// 0x153 (or just count it); otherwise defer to the base implementation.

class BDD80Geometry;
class BDD80ShadowLight;

class BDD80RenderPassArray
{
  public:
    void Add(BDD80Geometry* pkGeometry, unsigned short m_usShaderPassType, bool bFirst, unsigned char m_ucLightCount,
             BDD80ShadowLight* pkLight0, BDD80ShadowLight* pkLight1, BDD80ShadowLight* pkLight2,
             BDD80ShadowLight* pkLight3);
};

class BDD80ShaderPropertyBase
{
  public:
    int CreateRenderPasses(BDD80Geometry* pkGeometry, int iRenderMode, unsigned short* pusPassCount,
                           unsigned char ucMode, bool* pbFirst, bool bSkip, int iArg6, int iArg7, int iArg8, int iArg9,
                           int iArg12);
};

class BDD80ShaderProperty : public BDD80ShaderPropertyBase
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
    BDD80RenderPassArray* m_pkRenderPasses;

    int AddRenderPass(BDD80Geometry* pkGeometry, int iRenderMode, unsigned short* pusPassCount, unsigned char ucMode,
                      bool* pbFirst, bool bSkip, int iArg6, int iArg7, int iArg8, int iArg9, int iArg10, bool bOverride,
                      int iArg12);
};

// @fnv 0x00bddd80
int BDD80ShaderProperty::AddRenderPass(BDD80Geometry* pkGeometry, int iRenderMode, unsigned short* pusPassCount,
                                       unsigned char ucMode, bool* pbFirst, bool bSkip, int iArg6, int iArg7, int iArg8,
                                       int iArg9, int iArg10, bool bOverride, int iArg12)
{
    if (bOverride)
    {
        if (!bSkip)
        {
            if (ucMode == 1)
            {
                m_pkRenderPasses->Add(pkGeometry, 0x153, *pbFirst, 0, 0, 0, 0, 0);
                return 0;
            }
            ++*pusPassCount;
        }
        return 0;
    }
    return CreateRenderPasses(pkGeometry, iRenderMode, pusPassCount, ucMode, pbFirst, bSkip, iArg6, iArg7, iArg8, iArg9,
                              iArg12);
}

struct Shader_00bdde10
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
    BSShaderProperty::ShaderPassList* pPasses;
    int BSShaderProperty_AddPass_SpecularPoint2(NiGeometry* geom, ShadowSceneLight* light0, ShadowSceneLight* light1, unsigned short* count,
                     unsigned char type, bool* enabled, bool a, bool b, bool c, bool d);
};

// @fnv 0x00bdde10
// src: COMMUNITY 0x00bdde10
int Shader_00bdde10::BSShaderProperty_AddPass_SpecularPoint2(NiGeometry* geom, ShadowSceneLight* light0, ShadowSceneLight* light1,
                                  unsigned short* count, unsigned char type, bool* enabled, bool a, bool b, bool c,
                                  bool d)
{
    if (!a)
    {
        if (!b)
        {
            if (!c)
            {
                if (!d)
                {
                    if (type == 1)
                    {
                        pPasses->Add(geom, 0x16c, *enabled, 2, light0, light1, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
                else
                {
                    if (type == 1)
                    {
                        pPasses->Add(geom, 0x16d, *enabled, 2, light0, light1, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
            }
            else
            {
                if (type == 1)
                {
                    pPasses->Add(geom, 0x171, *enabled, 2, light0, light1, 0, 0);
                }
                else
                {
                    ++*count;
                }
            }
        }
        else
        {
            if (type == 1)
            {
                pPasses->Add(geom, 0x16e, *enabled, 2, light0, light1, 0, 0);
            }
            else
            {
                ++*count;
            }
        }
    }
    else if (!b)
    {
        if (!d)
        {
            if (type == 1)
            {
                pPasses->Add(geom, 0x16f, *enabled, 2, light0, light1, 0, 0);
            }
            else
            {
                ++*count;
            }
        }
        else
        {
            if (type == 1)
            {
                pPasses->Add(geom, 0x170, *enabled, 2, light0, light1, 0, 0);
            }
            else
            {
                ++*count;
            }
        }
    }
    *enabled = false;
    return 0;
}

struct ShadowSceneLight;
struct RPA
{
    void Add(NiGeometry* geom, unsigned short pass, bool enabled, unsigned char numLights, ShadowSceneLight* l0,
             ShadowSceneLight* l1, ShadowSceneLight* l2, ShadowSceneLight* l3);
};
struct Shader_bddfb0
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
    RPA* pPasses;
    int BSShaderProperty_AddPass_SpecularPoint3(NiGeometry* geom, ShadowSceneLight* l0, ShadowSceneLight* l1, ShadowSceneLight* l2,
                     unsigned short* count, unsigned char type, bool* out, bool a, bool b, bool c, bool d);
};

// @fnv 0x00bddfb0
// src: COMMUNITY 0x00bddfb0
int Shader_bddfb0::BSShaderProperty_AddPass_SpecularPoint3(NiGeometry* geom, ShadowSceneLight* pLight0, ShadowSceneLight* pLight1,
                                ShadowSceneLight* pLight2, unsigned short* count, unsigned char type, bool* out, bool a,
                                bool b, bool c, bool d)
{
    if (!a)
    {
        if (!b)
        {
            if (!c)
            {
                if (!d)
                {
                    if (type == 1)
                        pPasses->Add(geom, 0x172, *out, 3, pLight0, pLight1, pLight2, 0);
                    else
                        ++*count;
                }
                else
                {
                    if (type == 1)
                        pPasses->Add(geom, 0x173, *out, 3, pLight0, pLight1, pLight2, 0);
                    else
                        ++*count;
                }
            }
            else
            {
                if (type == 1)
                    pPasses->Add(geom, 0x177, *out, 3, pLight0, pLight1, pLight2, 0);
                else
                    ++*count;
            }
        }
        else
        {
            if (type == 1)
                pPasses->Add(geom, 0x174, *out, 3, pLight0, pLight1, pLight2, 0);
            else
                ++*count;
        }
    }
    else if (!b)
    {
        if (!d)
        {
            if (type == 1)
                pPasses->Add(geom, 0x175, *out, 3, pLight0, pLight1, pLight2, 0);
            else
                ++*count;
        }
        else
        {
            if (type == 1)
                pPasses->Add(geom, 0x176, *out, 3, pLight0, pLight1, pLight2, 0);
            else
                ++*count;
        }
    }
    *out = false;
    return 0;
}

struct ISRefObject
{
    virtual ~ISRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
};
struct ISTexRef : ISRefObject
{
};

struct ISTexPtr
{
    ISTexRef* m_pObject;
    ISTexPtr& operator=(ISTexRef* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (p)
                p->IncRefCount();
        }
        return *this;
    }
};
extern ISTexPtr g_ISTex0;
extern ISTexPtr g_ISTex1;
extern ISTexPtr g_ISTex2;

struct ISParam
{
    virtual ~ISParam();
};
struct ISTexObj
{
    ~ISTexObj();
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};

struct ISParamArr
{
    void* m_vt;
    ISParam** m_pBase;
    int unk08;
    int unk0c;
    void SetAt(unsigned int index, ISParam* const& item);
};
struct ISTexArr
{
    void* m_vt;
    ISTexObj** m_pBase;
    int unk08;
    int unk0c;
    void SetAt(unsigned int index, ISTexObj* const& item);
};

struct ISEffectBase
{
    virtual ~ISEffectBase();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ISParamArr m_params;
    ISTexArr m_textures;
};

struct FUN_00bc0360 : ISEffectBase
{
    virtual ~FUN_00bc0360();
};

// Releases the three global texture references and deletes parameter 0 and texture slots 3, 4 and 2, clearing each slot afterwards.
// @fnv 0x00bc0360
FUN_00bc0360::~FUN_00bc0360()
{
    g_ISTex0 = 0;
    g_ISTex1 = 0;
    g_ISTex2 = 0;
    if (m_params.m_pBase[0])
    {
        delete m_params.m_pBase[0];
        m_params.SetAt(0, 0);
    }
    if (m_textures.m_pBase[3])
    {
        delete m_textures.m_pBase[3];
        m_textures.SetAt(3, 0);
    }
    if (m_textures.m_pBase[4])
    {
        delete m_textures.m_pBase[4];
        m_textures.SetAt(4, 0);
    }
    if (m_textures.m_pBase[2])
    {
        delete m_textures.m_pBase[2];
        m_textures.SetAt(2, 0);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);

class FUN_00bc0940_obj
{
  public:
    virtual void v00();
    virtual void v01();
    long m_iObjectReferenceCount;
};

extern FUN_00bc0940_obj* DAT_01201f58;

// Decrements the reference count of the global object at DAT_01201f58 and calls its v01() when the count reaches zero, then clears the pointer.
// @fnv 0x00bc0940
// src: COMMUNITY 0x00bc0940
void __cdecl BoltShader_Free()
{
    if (DAT_01201f58 == 0)
        return;
    FUN_00bc0940_obj* obj = DAT_01201f58;
    long* rc = &DAT_01201f58->m_iObjectReferenceCount;
    if (InterlockedDecrement(rc) == 0)
        obj->v01();
    DAT_01201f58 = 0;
}

// 0x00bc34c0 evaluates the interpolator at 0x34 and calls the refraction setter 0x00b66700.
class ShaderRefractionController : public NiFloatInterpController
{
public:
    void UpdateFloatController(NiUpdateData& kUpdateData);
};

inline bool NiTimeController::GetManagerControlled() const
{
    return (bool)(((m_uiObjectFlags & MANAGERCONTROLLED_MASK) >> 5) & 1);
}

extern const float g_fInvalidTimeBC3;

// @fnv 0x00bc34c0
void ShaderRefractionController::UpdateFloatController(NiUpdateData& kUpdateData)
{
    if (GetManagerControlled())
    {
        m_fControllerTime = g_fInvalidTimeBC3;
    }
    else if (AdvanceController(kUpdateData.fTime) &&
             (!m_spControllerInterpolator.m_pObject || !m_spControllerInterpolator.m_pObject->AlwaysUpdate()))
    {
        return;
    }

    if (m_spControllerInterpolator.m_pObject)
    {
        float fValue;
        if (m_spControllerInterpolator.m_pObject->UpdateFloat(m_fControllerTime, m_pkTarget, fValue))
            ((BSShaderPPLightingProperty*)m_pkTarget)->SetRefractionPower(fValue);
    }
}

#include "../../include/NiMemObject.h"

class NiFloatData;

struct FUN_00a63430_class
{
    NiFloatData* FUN_00a63430();
};


struct FUN_00bc3540_class
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
    NiFloatInterpolator* m_object34;
    void FUN_00a57630(void* value);
    void SetInterpolatorFromValue(void* value);
};
// @fnv 0x00bc3540
void FUN_00bc3540_class::SetInterpolatorFromValue(void* value)
{
    FUN_00a57630(value);
    if (*(unsigned int*)((char*)value + 0xd8) < 0x0a010068u)
    {
        NiFloatData* data = ((FUN_00a63430_class*)value)->FUN_00a63430();
        NiFloatInterpolator* replacement = new NiFloatInterpolator(data);
        NiFloatInterpolator* old = m_object34;
        if (old != replacement)
        {
            if (old != 0 && InterlockedDecrement((volatile long*)&old->m_uiRefCount) == 0)
                old->DeleteThis();
            m_object34 = replacement;
            if (replacement != 0)
                InterlockedIncrement((volatile long*)&replacement->m_uiRefCount);
        }
        m_object34->Collapse();
    }
}

extern "C" void _ReadWriteBarrier();

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct EffectRef
{
    virtual ~EffectRef();
    virtual void DeleteThis();
    volatile long count;
};
template <bool Ordered> struct EffectPtr
{
    EffectRef* value;
    EffectPtr()
    {
        if (Ordered)
            _ReadWriteBarrier();
        value = 0;
    }
    ~EffectPtr()
    {
        if (value && !InterlockedDecrement(&value->count))
            value->DeleteThis();
    }
    EffectPtr& operator=(EffectRef* other)
    {
        EffectRef* previous = value;
        if (previous != other)
        {
            if (previous && !InterlockedDecrement(&previous->count))
                previous->DeleteThis();
            value = other;
        }
        return *this;
    }
};
struct EffectVector
{
    float x, y, z;
};
extern EffectVector DAT_011f426c;
struct EffectQuad
{
    float x, y, z, w;
    EffectQuad() : x(0), y(0), z(0), w(0)
    {}
};
struct FUN_00b66f50
{
    virtual ~FUN_00b66f50();
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
    FUN_00b66f50();
};
struct FUN_00bc3bb0 : FUN_00b66f50
{
    EffectPtr<false> first, second;
    EffectVector a, b, c;
    volatile float d, e, f;
    EffectQuad q0, q1, q2, RunFourthVirtual;
    EffectPtr<true> third;
    FUN_00bc3bb0();
    virtual ~FUN_00bc3bb0();
};
// Constructor: clears the effect pointers, initialises three vectors from DAT_011f426c, zeroes the floats, and sets unk1c to 9.
// @fnv 0x00bc3bb0
FUN_00bc3bb0::FUN_00bc3bb0()
{
    third = 0;
    first = 0;
    second = 0;
    a = DAT_011f426c;
    d = 0.0f;
    b = DAT_011f426c;
    e = 0.0f;
    c = DAT_011f426c;
    f = 0.0f;
    unk1c = 9;
}

struct StrArray
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    unsigned int Add(char* item)
    {
        unsigned int idx = m_usSize;
        if (idx >= m_usMaxSize)
            SetSize(idx + m_usGrowBy);
        SetAt(idx, item);
        return idx;
    }
};
struct NiTexture;
struct TexPtr
{
    NiTexture* m_pObject;
    operator NiTexture*() const
    {
        return m_pObject;
    }
};
struct DebugStrGlobal
{
    char* pData;
};
extern DebugStrGlobal g_01201fb8;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(char*);
char* __cdecl NiGetViewerString_00a7d5a0(const char*, void*);
char* __cdecl NiGetViewerString(const char*, bool);

struct ShaderBase_00b690d0
{
    void GetDebugInfo_b690d0(StrArray* arr);
};
struct TerrainShader : ShaderBase_00b690d0
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
    unsigned int flags24;
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
    TexPtr m_kTerrainTexture;
    bool GetFlag(unsigned int mask)
    {
        return (flags24 & mask) > 0;
    }
    void HairShaderProperty_GetViewerStrings(StrArray* arr);
};

// Appends base debug info plus height map, light flags and point-light status strings to arr.
// @fnv 0x00bc4460
// src: XBOX_PDB 0x00bc4460
void TerrainShader::HairShaderProperty_GetViewerStrings(StrArray* arr)
{
    GetDebugInfo_b690d0(arr);
    arr->Add(NiViewerStrings_NiGetViewerString_Title(g_01201fb8.pData));
    arr->Add(NiGetViewerString_00a7d5a0("height map", m_kTerrainTexture));
    arr->Add(NiGetViewerString("primary light is point", GetFlag(0x80)));
    arr->Add(NiGetViewerString("second light", GetFlag(0x100)));
    arr->Add(NiGetViewerString("third light", GetFlag(0x200)));
}

struct FUN_00bc5050_base
{
    virtual void vf00() = 0;
    virtual void vf01() = 0;
    virtual void vf02() = 0;
    virtual void vf03() = 0;
    virtual void vf04() = 0;
    virtual void vf05() = 0;
    virtual void vf06() = 0;
    virtual void vf07() = 0;
    virtual void vf08() = 0;
    virtual void vf09() = 0;
    virtual void vf0a() = 0;
    virtual void vf0b() = 0;
    virtual void vf0c() = 0;
    virtual void vf0d() = 0;
    virtual void vf0e() = 0;
    virtual void vf0f() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void vf13() = 0;
    virtual void vf14() = 0;
    virtual void vf15() = 0;
    virtual void vf16() = 0;
    virtual void vf17() = 0;
    virtual void vf18() = 0;
    virtual void vf19() = 0;
    virtual void vf1a() = 0;
    virtual void vf1b() = 0;
    virtual void vf1c() = 0;
    virtual void vf1d() = 0;
    virtual void vf1e() = 0;
    virtual void vf1f() = 0;
    virtual void vf20() = 0;
    virtual void vf21() = 0;
    virtual void vf22() = 0;
    virtual void vf23() = 0;
    virtual void vf24() = 0;
    virtual void vf25() = 0;
    virtual void vf26() = 0;
    virtual void vf27() = 0;
    virtual void vf28() = 0;
    virtual void vf29() = 0;
    virtual void vf2a() = 0;
    virtual void vf2b() = 0;
    virtual void vf2c() = 0;
    virtual void vf2d() = 0;
    virtual void vf2e() = 0;
    virtual void vf2f() = 0;
    virtual void vf30() = 0;
    virtual void vf31() = 0;
    virtual void vf32() = 0;
    virtual void vf33() = 0;
    virtual void vf34() = 0;
    virtual void vf35() = 0;
    virtual void vf36() = 0;
    virtual void vf37() = 0;
    virtual void vf38() = 0;
    virtual void vf39() = 0;
    virtual void vf3a() = 0;
    virtual void vf3b() = 0;
    virtual void vf3c() = 0;
    virtual void vf3d() = 0;
    virtual void vf3e() = 0;
    virtual void vf3f() = 0;
    virtual void vf40() = 0;
    virtual void vf41() = 0;
    virtual void vf42() = 0;
    virtual void vf43() = 0;
    virtual void vf44() = 0;
    virtual void vf45() = 0;
    virtual void vf46() = 0;
    virtual void vf47() = 0;
    virtual void vf48() = 0;
    virtual void vf49() = 0;
    virtual void vf4a() = 0;
    virtual void vf4b() = 0;
    virtual void vf4c() = 0;
    virtual void vf4d() = 0;
    virtual void vf4e() = 0;
    virtual void vf4f() = 0;
    virtual void vf50() = 0;
    virtual void vf51() = 0;
    virtual void vf52() = 0;
};

struct FUN_00bc5050_class : FUN_00bc5050_base
{
    void PrecipitationShader_ReloadShaders();
};

// @fnv 0x00bc5050
// src: XBOX_PDB 0x00bc5050
void FUN_00bc5050_class::PrecipitationShader_ReloadShaders()
{
    vf4f();
    vf52();
}

void* __cdecl FUN_00ec61c0(void*, int, unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct ShaderRef_bc5070 : RefObject
{
    void IncRefCount()
    {
        InterlockedIncrement(&m_iObjectReferenceCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_iObjectReferenceCount) == 0)
            Release();
    }
};
struct Config_bc5070
{
    const char* filename;
    unsigned int flags;
    unsigned int macros[17];
    Config_bc5070(const char* path)
    {
        filename = path;
        flags = 0;
        FUN_00ec61c0(macros, 0, 0x44);
    }
};
void __cdecl FUN_00be0c00(const char*, char*);
int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
extern bool DAT_011ad80e;
struct FUN_00bc5070_shell
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
    StagingNiPointer<ShaderRef_bc5070> shaders[2];
    ShaderRef_bc5070* FUN_00be0fe0(const char*, unsigned int*, const char*, const char*);
    void LoadVolumetricFogShaders();
};
// @fnv 0x00bc5070
void FUN_00bc5070_shell::LoadVolumetricFogShaders()
{
    const char* profileNames[2] = {"vs_2_0", "vs_3_0"};
    Config_bc5070 configs[2] = {Config_bc5070("vfog\\VolumetricFog.v.hlsl"),
                                Config_bc5070("vfog\\VolumetricFog.v.hlsl")};
    char binaryName[260];
    char sourceName[260];
    for (int i = 0; i < 2; ++i)
    {
        if (i == 1 && !DAT_011ad80e)
            continue;
        FUN_00be0c00(configs[i].filename, sourceName);
        sprintf_s(binaryName, 260, "VolumetricFog%03d.vso", i);
        shaders[i] = FUN_00be0fe0(sourceName, &configs[i].flags, profileNames[i], binaryName);
    }
}

extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern bool DAT_011ad80e;
void __cdecl FUN_00be0c00(const char*, char*);
int __cdecl BSsprintf(char*, int, const char*, ...);

struct ShaderMacro
{
    const char* Name;
    const char* Definition;
};

struct FogShaderDesc
{
    const char* filename;
    ShaderMacro macros[9];
};

struct VolumetricFog
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
    BeamPtr pixelShaders[2];

    RefObject* FUN_00be1750(const char*, unsigned int*, const char*, const char*);
    void CreatePixelShaders();
};

// @fnv 0x00bc51a0
void VolumetricFog::CreatePixelShaders()
{
    const char* shaderTargets[2];
    shaderTargets[0] = "ps_2_a";
    shaderTargets[1] = "ps_3_0";

    FogShaderDesc shaderDescs[2];
    shaderDescs[0].filename = "vfog\\VolumetricFog.p.hlsl";
    shaderDescs[0].macros[0].Name = 0;
    fnv_zlib_memset(&shaderDescs[0].macros[0].Definition, 0, 0x44);

    shaderDescs[1].filename = "vfog\\VolumetricFog.p.hlsl";
    shaderDescs[1].macros[0].Name = "SINGLE_PASS";
    shaderDescs[1].macros[0].Definition = "";
    shaderDescs[1].macros[1].Name = 0;
    fnv_zlib_memset(&shaderDescs[1].macros[1].Definition, 0, 0x3c);

    for (int i = 0; i < 2; ++i)
    {
        if (i == 1 && !DAT_011ad80e)
            continue;

        char szFullPath[260];
        FUN_00be0c00(shaderDescs[i].filename, szFullPath);

        char szShaderName[260];
        BSsprintf(szShaderName, 260, "VolumetricFog%03d.pso", i);

        RefObject* pShader =
            FUN_00be1750(szFullPath, (unsigned int*)shaderDescs[i].macros, shaderTargets[i], szShaderName);
        pixelShaders[i].Assign(pShader);
    }
}

struct PassStates
{
    void Set(int state, int value, int enabled);
};
PassStates* __cdecl MakeStates();
struct LocalStage : StageReturn
{
    void Setup(int);
};

struct LocalPass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int stages;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    PassStates* states;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    ShaderRefPtr<ShaderRefObject> object44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    ShaderRefPtr<ShaderRefObject> object5c;
    void SetPassStage(int stages, StageReturn* stage);
    PassStates* GetStates()
    {
        if (!states)
            states = MakeStates();
        return states;
    }
};
struct LocalPassPtr
{
    LocalPass* object;
    LocalPass* operator->() const
    {
        return object;
    }
};
void __cdecl CreateLocalPass(LocalPassPtr&);
extern bool DAT_011ad80e;
struct ShaderConfig
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
    LocalPassPtr passes[3];
    ShaderRefObject* object78;
    ShaderRefObject* object7c;
    ShaderRefObject* object80;
    ShaderRefObject* object84;
    bool VolumetricFogShader_LoadStagesAndPasses();
};
// @fnv 0x00bc5510
// src: COMMUNITY 0x00bc5510
bool ShaderConfig::VolumetricFogShader_LoadStagesAndPasses()
{
    for (int index = 0; index < 3; ++index)
    {
        if (index == 2 && !DAT_011ad80e)
            continue;
        LocalPassPtr& pass = passes[index];
        if (!pass.object)
        {
            CreateLocalPass(pass);
            StagePtr stage;
            AssignStageFromPool(stage);
            ShaderSetupStage(stage.m_pObject, 0, 3, 2, 1);
            ((LocalStage*)stage.m_pObject)->Setup(0);
            pass->SetPassStage(pass->stages, stage.m_pObject);
        }
        switch (index)
        {
        case 0:
        case 1:
            pass->object44 = object80;
            pass->object5c = object78;
            break;
        case 2:
            pass->object44 = object84;
            pass->object5c = object7c;
            break;
        }
        pass->GetStates()->Set(168, 15, 1);
        pass->GetStates()->Set(7, 0, 1);
        pass->GetStates()->Set(14, 0, 1);
        pass->GetStates()->Set(23, 8, 1);
        pass->GetStates()->Set(27, 1, 1);
        LocalPass* cachedPass = pass.object;
        cachedPass->GetStates()->Set(19, 2, 1);
        cachedPass->GetStates()->Set(20, 2, 1);
        if (index == 1)
            passes[1]->GetStates()->Set(22, 3, 1);
        else if (index == 0)
            passes[0]->GetStates()->Set(22, 2, 1);
        else if (index == 2)
            passes[2]->GetStates()->Set(22, 1, 1);
        pass->GetStates()->Set(52, 1, 1);
        pass->GetStates()->Set(56, 8, 1);
        pass->GetStates()->Set(57, 1, 1);
        pass->GetStates()->Set(55, 3, 1);
        pass->GetStates()->Set(54, 3, 1);
    }
    return true;
}

extern StagingNiPointer<NiRefObject> DAT_012021e0;
extern StagingNiPointer<NiRefObject> DAT_012021e4;
struct FUN_00bcb210 : ShaderBase5320
{
    PassPtr passes[2];
    StagingNiPointer<NiRefObject> vertex[2];
    StagingNiPointer<NiRefObject> pixel[2];
    StagingNiPointer<NiRefObject> resource84;
    StagingNiPointer<NiRefObject> resource88;
    StagingNiPointer<NiRefObject> resource8c;
    virtual ~FUN_00bcb210();
};
// Releases the shader's two passes, vertex/pixel pointers, three resource pointers and two global references by clearing them.
// @fnv 0x00bcb210
FUN_00bcb210::~FUN_00bcb210()
{
    resource84 = 0;
    resource88 = 0;
    resource8c = 0;
    for (int i = 0; i < 2; ++i)
    {
        passes[i].clear();
        vertex[i] = 0;
        pixel[i] = 0;
    }
    DAT_012021e0 = 0;
    DAT_012021e4 = 0;
}

struct FUN_00bcd4a0 : ShaderBase
{
    StagingNiPointer<NiD3DVertexShader> vertex[20];
    StagingNiPointer<NiD3DPixelShader> pixel[33];
    virtual void Initialize();
    ~FUN_00bcd4a0();
};

// Releases the vertex and pixel shader references and clears the pass pointers.
// @fnv 0x00bcd4a0
FUN_00bcd4a0::~FUN_00bcd4a0()
{
    for (int i = 0; i < 20; i++)
    {
        NiD3DVertexShader* p = vertex[i].m_pObject;
        if (p)
        {
            if (InterlockedDecrement((volatile long*)&p->m_uiRefCount) == 0)
                p->DeleteThis();
            vertex[i].m_pObject = 0;
        }
    }
    for (int i = 0; i < 33; i++)
    {
        NiD3DPixelShader* p = pixel[i].m_pObject;
        if (p)
        {
            if (InterlockedDecrement((volatile long*)&p->m_uiRefCount) == 0)
                p->DeleteThis();
            pixel[i].m_pObject = 0;
        }
    }
    PassPtr* passes = (PassPtr*)DAT_01202230;
    for (int i = 0; i < 33; i++)
        passes[i].clear();
}

extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct PixelRef
{
    virtual void Destroy();
    virtual void DeleteThis();
    long refs;
    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refs) == 0)
            DeleteThis();
    }
};
struct PixelPtr
{
    PixelRef* ptr;
    void operator=(PixelRef* value)
    {
        if (ptr != value)
        {
            PixelRef* old = ptr;
            if (old)
                old->DecRefCount();
            ptr = value;
            if (value)
                value->IncRefCount();
        }
    }
};
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
struct Macro
{
    const char* name;
    const char* value;
};
struct PixelDesc
{
    const char* file;
    const char* macros[18];
};
extern int DAT_011f91c0;
void __cdecl FUN_00be0c00(const char*, char*);
int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
struct PixelLoader
{
    int unk000;
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
    PixelPtr shaders[33];
    PixelRef* FUN_00be1750(char*, const char**, const char*, char*);
    void ParallaxShader_LoadPixelShaders();
};
// @fnv 0x00bcd7c0
// src: COMMUNITY 0x00bcd7c0
void PixelLoader::ParallaxShader_LoadPixelShaders()
{
    PixelDesc desc[33];
    desc[0].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[0].macros[0] = "PARALLAX";
    desc[0].macros[1] = "";
    desc[0].macros[2] = 0;
    fnv_zlib_memset(&desc[0].macros[3], 0, 60);
    desc[1].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[1].macros[0] = "PARALLAX";
    desc[1].macros[1] = "";
    desc[1].macros[2] = "OPT";
    desc[1].macros[3] = "";
    desc[1].macros[4] = 0;
    fnv_zlib_memset(&desc[1].macros[5], 0, 52);
    desc[2].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[2].macros[0] = "PARALLAX";
    desc[2].macros[1] = "";
    desc[2].macros[2] = "SI";
    desc[2].macros[3] = "";
    desc[2].macros[4] = 0;
    fnv_zlib_memset(&desc[2].macros[5], 0, 52);
    desc[3].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[3].macros[0] = "PARALLAX";
    desc[3].macros[1] = "";
    desc[3].macros[2] = "PROJ_SHADOW";
    desc[3].macros[3] = "";
    desc[3].macros[4] = 0;
    fnv_zlib_memset(&desc[3].macros[5], 0, 52);
    desc[4].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[4].macros[0] = "PARALLAX";
    desc[4].macros[1] = "";
    desc[4].macros[2] = "SI";
    desc[4].macros[3] = "";
    desc[4].macros[4] = "PROJ_SHADOW";
    desc[4].macros[5] = "";
    desc[4].macros[6] = 0;
    fnv_zlib_memset(&desc[4].macros[7], 0, 44);
    desc[5].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[5].macros[0] = "LIGHTS";
    desc[5].macros[1] = "2";
    desc[5].macros[2] = "PARALLAX";
    desc[5].macros[3] = "";
    desc[5].macros[4] = 0;
    fnv_zlib_memset(&desc[5].macros[5], 0, 52);
    desc[6].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[6].macros[0] = "LIGHTS";
    desc[6].macros[1] = "2";
    desc[6].macros[2] = "PARALLAX";
    desc[6].macros[3] = "";
    desc[6].macros[4] = "SI";
    desc[6].macros[5] = "";
    desc[6].macros[6] = 0;
    fnv_zlib_memset(&desc[6].macros[7], 0, 44);
    desc[7].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[7].macros[0] = "LIGHTS";
    desc[7].macros[1] = "2";
    desc[7].macros[2] = "PARALLAX";
    desc[7].macros[3] = "";
    desc[7].macros[4] = "PROJ_SHADOW";
    desc[7].macros[5] = "";
    desc[7].macros[6] = 0;
    fnv_zlib_memset(&desc[7].macros[7], 0, 44);
    desc[8].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[8].macros[0] = "LIGHTS";
    desc[8].macros[1] = "2";
    desc[8].macros[2] = "PARALLAX";
    desc[8].macros[3] = "";
    desc[8].macros[4] = "SI";
    desc[8].macros[5] = "";
    desc[8].macros[6] = "PROJ_SHADOW";
    desc[8].macros[7] = "";
    desc[8].macros[8] = 0;
    memset(&desc[8].macros[9], 0, 36);
    desc[9].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[9].macros[0] = "SPECULAR";
    desc[9].macros[1] = "";
    desc[9].macros[2] = "PARALLAX";
    desc[9].macros[3] = "";
    desc[9].macros[4] = 0;
    fnv_zlib_memset(&desc[9].macros[5], 0, 52);
    desc[10].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[10].macros[0] = "SPECULAR";
    desc[10].macros[1] = "";
    desc[10].macros[2] = "PARALLAX";
    desc[10].macros[3] = "";
    desc[10].macros[4] = "SI";
    desc[10].macros[5] = "";
    desc[10].macros[6] = 0;
    fnv_zlib_memset(&desc[10].macros[7], 0, 44);
    desc[11].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[11].macros[0] = "SPECULAR";
    desc[11].macros[1] = "";
    desc[11].macros[2] = "PARALLAX";
    desc[11].macros[3] = "";
    desc[11].macros[4] = "PROJ_SHADOW";
    desc[11].macros[5] = "";
    desc[11].macros[6] = 0;
    fnv_zlib_memset(&desc[11].macros[7], 0, 44);
    desc[12].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[12].macros[0] = "SPECULAR";
    desc[12].macros[1] = "";
    desc[12].macros[2] = "PARALLAX";
    desc[12].macros[3] = "";
    desc[12].macros[4] = "SI";
    desc[12].macros[5] = "";
    desc[12].macros[6] = "PROJ_SHADOW";
    desc[12].macros[7] = "";
    desc[12].macros[8] = 0;
    memset(&desc[12].macros[9], 0, 36);
    desc[13].file = "lighting\\2x\\p\\AD.p.hlsl";
    desc[13].macros[0] = "LIGHTS";
    desc[13].macros[1] = "2";
    desc[13].macros[2] = "PARALLAX";
    desc[13].macros[3] = "";
    desc[13].macros[4] = 0;
    fnv_zlib_memset(&desc[13].macros[5], 0, 52);
    desc[14].file = "lighting\\2x\\p\\AD.p.hlsl";
    desc[14].macros[0] = "LIGHTS";
    desc[14].macros[1] = "2";
    desc[14].macros[2] = "PARALLAX";
    desc[14].macros[3] = "";
    desc[14].macros[4] = "SI";
    desc[14].macros[5] = "";
    desc[14].macros[6] = 0;
    fnv_zlib_memset(&desc[14].macros[7], 0, 44);
    desc[15].file = "lighting\\2x\\p\\AD.p.hlsl";
    desc[15].macros[0] = "LIGHTS";
    desc[15].macros[1] = "2";
    desc[15].macros[2] = "PARALLAX";
    desc[15].macros[3] = "";
    desc[15].macros[4] = "PROJ_SHADOW";
    desc[15].macros[5] = "";
    desc[15].macros[6] = 0;
    fnv_zlib_memset(&desc[15].macros[7], 0, 44);
    desc[16].file = "lighting\\2x\\p\\AD.p.hlsl";
    desc[16].macros[0] = "LIGHTS";
    desc[16].macros[1] = "2";
    desc[16].macros[2] = "PARALLAX";
    desc[16].macros[3] = "";
    desc[16].macros[4] = "SI";
    desc[16].macros[5] = "";
    desc[16].macros[6] = "PROJ_SHADOW";
    desc[16].macros[7] = "";
    desc[16].macros[8] = 0;
    memset(&desc[16].macros[9], 0, 36);
    desc[17].file = "lighting\\2x\\p\\AD.p.hlsl";
    desc[17].macros[0] = "LIGHTS";
    desc[17].macros[1] = "3";
    desc[17].macros[2] = "PARALLAX";
    desc[17].macros[3] = "";
    desc[17].macros[4] = 0;
    fnv_zlib_memset(&desc[17].macros[5], 0, 52);
    desc[18].file = "lighting\\2x\\p\\AD.p.hlsl";
    desc[18].macros[0] = "LIGHTS";
    desc[18].macros[1] = "3";
    desc[18].macros[2] = "PARALLAX";
    desc[18].macros[3] = "";
    desc[18].macros[4] = "SI";
    desc[18].macros[5] = "";
    desc[18].macros[6] = 0;
    fnv_zlib_memset(&desc[18].macros[7], 0, 44);
    desc[19].file = "lighting\\2x\\p\\AD.p.hlsl";
    desc[19].macros[0] = "LIGHTS";
    desc[19].macros[1] = "3";
    desc[19].macros[2] = "PARALLAX";
    desc[19].macros[3] = "";
    desc[19].macros[4] = "PROJ_SHADOW";
    desc[19].macros[5] = "";
    desc[19].macros[6] = 0;
    fnv_zlib_memset(&desc[19].macros[7], 0, 44);
    desc[20].file = "lighting\\2x\\p\\AD.p.hlsl";
    desc[20].macros[0] = "LIGHTS";
    desc[20].macros[1] = "3";
    desc[20].macros[2] = "PARALLAX";
    desc[20].macros[3] = "";
    desc[20].macros[4] = "SI";
    desc[20].macros[5] = "";
    desc[20].macros[6] = "PROJ_SHADOW";
    desc[20].macros[7] = "";
    desc[20].macros[8] = 0;
    memset(&desc[20].macros[9], 0, 36);
    desc[21].file = "lighting\\2x\\p\\DiffusePt.p.hlsl";
    desc[21].macros[0] = "LIGHTS";
    desc[21].macros[1] = "2";
    desc[21].macros[2] = "PARALLAX";
    desc[21].macros[3] = "";
    desc[21].macros[4] = 0;
    fnv_zlib_memset(&desc[21].macros[5], 0, 52);
    desc[22].file = "lighting\\2x\\p\\DiffusePt.p.hlsl";
    desc[22].macros[0] = "LIGHTS";
    desc[22].macros[1] = "3";
    desc[22].macros[2] = "PARALLAX";
    desc[22].macros[3] = "";
    desc[22].macros[4] = 0;
    fnv_zlib_memset(&desc[22].macros[5], 0, 52);
    desc[23].file = "lighting\\2x\\p\\Texture.p.hlsl";
    desc[23].macros[0] = "PARALLAX";
    desc[23].macros[1] = "";
    desc[23].macros[2] = 0;
    fnv_zlib_memset(&desc[23].macros[3], 0, 60);
    desc[24].file = "lighting\\2x\\p\\Specular.p.hlsl";
    desc[24].macros[0] = "PARALLAX";
    desc[24].macros[1] = "";
    desc[24].macros[2] = 0;
    fnv_zlib_memset(&desc[24].macros[3], 0, 60);
    desc[25].file = "lighting\\2x\\p\\Specular.p.hlsl";
    desc[25].macros[0] = "PARALLAX";
    desc[25].macros[1] = "";
    desc[25].macros[2] = "PROJ_SHADOW";
    desc[25].macros[3] = "";
    desc[25].macros[4] = 0;
    fnv_zlib_memset(&desc[25].macros[5], 0, 52);
    desc[26].file = "lighting\\2x\\p\\Specular.p.hlsl";
    desc[26].macros[0] = "POINT";
    desc[26].macros[1] = "";
    desc[26].macros[2] = "PARALLAX";
    desc[26].macros[3] = "";
    desc[26].macros[4] = 0;
    fnv_zlib_memset(&desc[26].macros[5], 0, 52);
    desc[27].file = "lighting\\2x\\p\\Specular.p.hlsl";
    desc[27].macros[0] = "NUM_PT_LIGHTS";
    desc[27].macros[1] = "2";
    desc[27].macros[2] = "POINT";
    desc[27].macros[3] = "";
    desc[27].macros[4] = "PARALLAX";
    desc[27].macros[5] = "";
    desc[27].macros[6] = 0;
    fnv_zlib_memset(&desc[27].macros[7], 0, 44);
    desc[28].file = "lighting\\2x\\p\\Specular.p.hlsl";
    desc[28].macros[0] = "NUM_PT_LIGHTS";
    desc[28].macros[1] = "3";
    desc[28].macros[2] = "POINT";
    desc[28].macros[3] = "";
    desc[28].macros[4] = "PARALLAX";
    desc[28].macros[5] = "";
    desc[28].macros[6] = 0;
    fnv_zlib_memset(&desc[28].macros[7], 0, 44);
    desc[29].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[29].macros[0] = "SPECULAR";
    desc[29].macros[1] = "";
    desc[29].macros[2] = "LIGHTS";
    desc[29].macros[3] = "2";
    desc[29].macros[4] = "PARALLAX";
    desc[29].macros[5] = "";
    desc[29].macros[6] = 0;
    fnv_zlib_memset(&desc[29].macros[7], 0, 44);
    desc[30].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[30].macros[0] = "SPECULAR";
    desc[30].macros[1] = "";
    desc[30].macros[2] = "LIGHTS";
    desc[30].macros[3] = "2";
    desc[30].macros[4] = "PARALLAX";
    desc[30].macros[5] = "";
    desc[30].macros[6] = "SI";
    desc[30].macros[7] = "";
    desc[30].macros[8] = 0;
    memset(&desc[30].macros[9], 0, 36);
    desc[31].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[31].macros[0] = "SPECULAR";
    desc[31].macros[1] = "";
    desc[31].macros[2] = "LIGHTS";
    desc[31].macros[3] = "2";
    desc[31].macros[4] = "PARALLAX";
    desc[31].macros[5] = "";
    desc[31].macros[6] = "PROJ_SHADOW";
    desc[31].macros[7] = "";
    desc[31].macros[8] = 0;
    memset(&desc[31].macros[9], 0, 36);
    desc[32].file = "lighting\\2x\\p\\ADTS.p.hlsl";
    desc[32].macros[0] = "SPECULAR";
    desc[32].macros[1] = "";
    desc[32].macros[2] = "LIGHTS";
    desc[32].macros[3] = "2";
    desc[32].macros[4] = "PARALLAX";
    desc[32].macros[5] = "";
    desc[32].macros[6] = "SI";
    desc[32].macros[7] = "";
    desc[32].macros[8] = "PROJ_SHADOW";
    desc[32].macros[9] = "";
    desc[32].macros[10] = 0;
    memset(&desc[32].macros[11], 0, 28);
    static const char format[] = "PAR2%03i.pso";
    char path[260];
    char name[260];
    int shaderLevel = DAT_011f91c0;
    if (shaderLevel >= 2)
    {
        for (int index = 0; index < 29; ++index)
        {
            FUN_00be0c00(desc[index].file, path);
            sprintf_s(name, 260, format, index);
            shaders[index] = FUN_00be1750(path, desc[index].macros, "ps_2_0", name);
        }
        if (shaderLevel >= 5)
        {
            for (int index = 29; index < 33; ++index)
            {
                FUN_00be0c00(desc[index].file, path);
                sprintf_s(name, 260, format, index);
                shaders[index] = FUN_00be1750(path, desc[index].macros, "ps_2_0", name);
            }
        }
    }
}

struct SPGeom;

struct SPPassInfo
{
    int unk00;
    int unk04;
    int unk08;
    SPGeom* pGeom;
};

extern unsigned int g_uiSPCurrentPass;

struct SPShaderBase
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void FinishSetup();

    void SetupStage(SPGeom* apGeom, int aiStage, int aiUnk, bool abFlag);
    void SetSamplerA(SPGeom* apGeom, int aiValue, int aiUnk);
    void SetSamplerB(SPGeom* apGeom, int aiValue, int aiUnk);
    void SetTextureStage(SPGeom* apGeom, int aiStage, int aiUnk, bool abFlag);
    void SetExtraStage(SPGeom* apGeom, int aiStage, int aiUnk, bool abFlag);
    void SetAlphaStage(int aiStage);
    void BaseSetup(SPPassInfo* apPass);
};

struct SPShader : SPShaderBase
{
    void SetupShaderPass(SPPassInfo* apPass);
};

// Selects shader stages and samplers based on g_uiSPCurrentPass, falling back to BaseSetup, then calls FinishSetup.
// @fnv 0x00bce500
void SPShader::SetupShaderPass(SPPassInfo* apPass)
{
    SPGeom* pGeom = apPass->pGeom;
    switch (g_uiSPCurrentPass)
    {
    case 0xDA:
    case 0xE3:
    case 0xEC:
    case 0xF5:
        SetupStage(pGeom, 3, 0, true);
    case 0xD9:
    case 0xE2:
    case 0xEB:
    case 0xF4:
        SetSamplerA(pGeom, 0, 0);
        SetSamplerB(pGeom, 1, 0);
        SetTextureStage(pGeom, 2, 0, true);
        break;
    case 0x103:
    case 0x10F:
    case 0x11A:
    case 0x125:
        SetupStage(pGeom, 4, 0, true);
    case 0x101:
    case 0x10E:
    case 0x119:
    case 0x124:
        SetSamplerA(pGeom, 0, 0);
        SetSamplerB(pGeom, 1, 0);
        SetTextureStage(pGeom, 3, 0, true);
        break;
    case 0x9A:
    case 0xA5:
    case 0xB0:
    case 0xBB:
        SetupStage(pGeom, 4, 0, true);
    case 0x99:
    case 0xA4:
    case 0xAF:
    case 0xBA:
        SetSamplerA(pGeom, 0, 0);
        SetSamplerB(pGeom, 1, 0);
        SetTextureStage(pGeom, 3, 0, true);
        SetExtraStage(pGeom, 2, 0, true);
        break;
    case 0x134:
    case 0x140:
        SetSamplerA(pGeom, 1, 0);
        SetSamplerB(pGeom, 0, 0);
        SetTextureStage(pGeom, 2, 0, true);
        break;
    case 0x153:
        SetSamplerA(pGeom, 0, 0);
        SetTextureStage(pGeom, 2, 0, true);
        break;
    case 0x15C:
    case 0x162:
    case 0x168:
    case 0x16E:
    case 0x174:
        SetSamplerA(pGeom, 1, 0);
        SetSamplerB(pGeom, 0, 0);
        SetTextureStage(pGeom, 2, 0, true);
        SetExtraStage(pGeom, 6, 0, true);
        break;
    case 0x231:
    case 0x232:
    case 0x233:
        SetSamplerA(pGeom, 0, 0);
        SetAlphaStage(6);
        break;
    default:
        BaseSetup(apPass);
        return;
    }
    FinishSetup();
}

extern char str_010af114;

extern char str_010aed54;

extern char DAT_01011584;

extern char str_010aeba0;

extern char str_010aeb98;

extern char DAT_01063f3c;

extern char str_010af0b0;

extern char DAT_01063f30;

extern char str_010af090;

extern char str_010af0c8;

extern char DAT_01063ee8;

extern char DAT_01063f24;

extern char str_010aeb8c;

extern char DAT_010bb96c;

extern char str_010a93cc;

extern int DAT_011f91c0;

struct FeatureDescription
{

    const char* name;

    const char* family;

    const char* source;

    const char* variant;

    const char* suffix;

    const char* selection;

    const char* support;

    const char* fallback;

    const char* p08;

    const char* p09;

    const char* p0a;

    const char* p0b;

    const char* p0c;

    const char* p0d;

    const char* p0e;

    const char* p0f;

    const char* p10;

    const char* p11;

    const char* p12;
};

struct FeatureObject
{
    virtual void v00();
    virtual void Release();
    volatile long references;
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);

void __cdecl FUN_00be0c00(const char*, char*);

int __cdecl BSsprintf(char*, unsigned int, const char*, ...);

struct FeatureManager
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
    FeatureObject* features[13];
    FeatureObject* __thiscall LoadFeature(char*, const char**, const char*, char*);
    void __thiscall LoadAllFeatures();
};

// Builds 13 feature descriptors and, when DAT_011f91c0 >= 2, loads each named feature into the features array with reference counting.
// @fnv 0x00bcf320
void FeatureManager::LoadAllFeatures()
{

    FeatureDescription descriptors[13];

    descriptors[0].name = &str_010af114;

    descriptors[0].family = &str_010aed54;

    descriptors[0].source = &DAT_01011584;

    descriptors[0].variant = 0;

    fnv_zlib_memset(&descriptors[0].suffix, 0, 60);

    descriptors[1].name = &str_010af114;

    descriptors[1].family = &str_010aed54;

    descriptors[1].source = &DAT_01011584;

    descriptors[1].variant = &str_010aeba0;

    descriptors[1].suffix = &DAT_01011584;

    descriptors[1].selection = 0;

    fnv_zlib_memset(&descriptors[1].support, 0, 52);

    descriptors[2].name = &str_010af114;

    descriptors[2].family = &str_010aeb98;

    descriptors[2].source = &DAT_01063f3c;

    descriptors[2].variant = &str_010aed54;

    descriptors[2].suffix = &DAT_01011584;

    descriptors[2].selection = 0;

    fnv_zlib_memset(&descriptors[2].support, 0, 52);

    descriptors[3].name = &str_010af114;

    descriptors[3].family = &str_010aeb98;

    descriptors[3].source = &DAT_01063f3c;

    descriptors[3].variant = &str_010aed54;

    descriptors[3].suffix = &DAT_01011584;

    descriptors[3].selection = &str_010aeba0;

    descriptors[3].support = &DAT_01011584;

    descriptors[3].fallback = 0;

    fnv_zlib_memset(&descriptors[3].p08, 0, 44);

    descriptors[4].name = &str_010af0b0;

    descriptors[4].family = &str_010aeb98;

    descriptors[4].source = &DAT_01063f3c;

    descriptors[4].variant = &str_010aed54;

    descriptors[4].suffix = &DAT_01011584;

    descriptors[4].selection = 0;

    fnv_zlib_memset(&descriptors[4].support, 0, 52);

    descriptors[5].name = &str_010af0b0;

    descriptors[5].family = &str_010aeb98;

    descriptors[5].source = &DAT_01063f3c;

    descriptors[5].variant = &str_010aed54;

    descriptors[5].suffix = &DAT_01011584;

    descriptors[5].selection = &str_010aeba0;

    descriptors[5].support = &DAT_01011584;

    descriptors[5].fallback = 0;

    fnv_zlib_memset(&descriptors[5].p08, 0, 44);

    descriptors[6].name = &str_010af0b0;

    descriptors[6].family = &str_010aeb98;

    descriptors[6].source = &DAT_01063f30;

    descriptors[6].variant = &str_010aed54;

    descriptors[6].suffix = &DAT_01011584;

    descriptors[6].selection = 0;

    fnv_zlib_memset(&descriptors[6].support, 0, 52);

    descriptors[7].name = &str_010af0b0;

    descriptors[7].family = &str_010aeb98;

    descriptors[7].source = &DAT_01063f30;

    descriptors[7].variant = &str_010aed54;

    descriptors[7].suffix = &DAT_01011584;

    descriptors[7].selection = &str_010aeba0;

    descriptors[7].support = &DAT_01011584;

    descriptors[7].fallback = 0;

    fnv_zlib_memset(&descriptors[7].p08, 0, 44);

    descriptors[8].name = &str_010af090;

    descriptors[8].family = &str_010aeb98;

    descriptors[8].source = &DAT_01063f3c;

    descriptors[8].variant = &str_010aed54;

    descriptors[8].suffix = &DAT_01011584;

    descriptors[8].selection = 0;

    fnv_zlib_memset(&descriptors[8].support, 0, 52);

    descriptors[9].name = &str_010af090;

    descriptors[9].family = &str_010aeb98;

    descriptors[9].source = &DAT_01063f30;

    descriptors[9].variant = &str_010aed54;

    descriptors[9].suffix = &DAT_01011584;

    descriptors[9].selection = 0;

    fnv_zlib_memset(&descriptors[9].support, 0, 52);

    descriptors[10].name = &str_010af0c8;

    descriptors[10].family = &str_010aeb98;

    descriptors[10].source = &DAT_01063ee8;

    descriptors[10].variant = &str_010aed54;

    descriptors[10].suffix = 0;
    descriptors[10].selection = 0;

    fnv_zlib_memset(&descriptors[10].support, 0, 52);

    descriptors[11].name = &str_010af0c8;

    descriptors[11].family = &str_010aeb98;

    descriptors[11].source = &DAT_01063f24;

    descriptors[11].variant = &str_010aed54;

    descriptors[11].suffix = 0;
    descriptors[11].selection = 0;

    fnv_zlib_memset(&descriptors[11].support, 0, 52);

    descriptors[12].name = &str_010af0c8;

    descriptors[12].family = &str_010aeb8c;

    descriptors[12].source = &DAT_01011584;

    descriptors[12].variant = &str_010aeb98;

    descriptors[12].suffix = &DAT_01063f24;

    descriptors[12].selection = &str_010aed54;

    descriptors[12].support = 0;
    descriptors[12].fallback = 0;

    fnv_zlib_memset(&descriptors[12].p08, 0, 44);

    if (DAT_011f91c0 >= 2)
    {

        char qualifiedName[260];

        char formatBuffer[260];

        int index = 0;
        FeatureDescription* descriptor = descriptors;
        FeatureObject** destination = features;

        for (; index < 13; ++index, ++destination, ++descriptor)
        {

            if (!descriptor->name)
                continue;

            FUN_00be0c00(descriptor->name, qualifiedName);

            BSsprintf(formatBuffer, 0x104, &DAT_010bb96c, index);

            FeatureObject* next = LoadFeature(qualifiedName, &descriptor->family, &str_010a93cc, formatBuffer);

            FeatureObject* old = *destination;

            if (old != next)
            {

                if (old && InterlockedDecrement(&old->references) == 0)
                    old->Release();

                *destination = next;

                if (next)
                    InterlockedIncrement(&next->references);
            }
        }
    }
}

NiD3DShaderDeclaration* __cdecl NiDX9ShaderDeclaration_Create(void* apRenderer, int aiType, int aiFlag);

class FUN_00bcf7f0
{
  public:
    static void* operator new(unsigned int size)
    {
        return BSFaceGenMorphData::operator new(size);
    }
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048(NiD3DShaderDeclaration* apDesc);
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    FUN_00bcf7f0(NiD3DShaderDeclaration* apVertexDesc, NiD3DShaderDeclaration* apPixelDesc);
    char pad[0x124];
};

// Creates vertex and pixel descriptors, configures their elements, builds a shader from them, initializes it and returns the shader.
// @fnv 0x00bcfb00
FUN_00bcf7f0* __cdecl CreateFaceGenMorphShader()
{
    NiD3DShaderDeclaration* pVertexDesc = NiDX9ShaderDeclaration_Create(DAT_011f9508, 6, 1);
    NiD3DShaderDeclaration* pPixelDesc = NiDX9ShaderDeclaration_Create(DAT_011f9508, 8, 1);
    pVertexDesc->SetEntry(0, 0, (NiShaderDeclaration::ShaderParameter)0, (NiShaderDeclaration::ShaderParameterType)2, 0);
    pVertexDesc->SetEntry(1, 3, (NiShaderDeclaration::ShaderParameter)3, (NiShaderDeclaration::ShaderParameterType)2, 0);
    pVertexDesc->SetEntry(2, 5, (NiShaderDeclaration::ShaderParameter)4, (NiShaderDeclaration::ShaderParameterType)3, 0);
    pVertexDesc->SetEntry(3, 7, (NiShaderDeclaration::ShaderParameter)5, (NiShaderDeclaration::ShaderParameterType)1, 0);
    pVertexDesc->SetEntry(4, 0xe, (NiShaderDeclaration::ShaderParameter)0xd, (NiShaderDeclaration::ShaderParameterType)2, 0);
    pVertexDesc->SetEntry(5, 0xf, (NiShaderDeclaration::ShaderParameter)0xe, (NiShaderDeclaration::ShaderParameterType)2, 0);
    pVertexDesc->GetD3DDeclaration();
    pPixelDesc->SetEntry(0, 0, (NiShaderDeclaration::ShaderParameter)0, (NiShaderDeclaration::ShaderParameterType)2, 0);
    pPixelDesc->SetEntry(1, 1, (NiShaderDeclaration::ShaderParameter)1, (NiShaderDeclaration::ShaderParameterType)3, 0);
    pPixelDesc->SetEntry(2, 2, (NiShaderDeclaration::ShaderParameter)2, (NiShaderDeclaration::ShaderParameterType)4, 0);
    pPixelDesc->SetEntry(3, 3, (NiShaderDeclaration::ShaderParameter)3, (NiShaderDeclaration::ShaderParameterType)2, 0);
    pPixelDesc->SetEntry(4, 5, (NiShaderDeclaration::ShaderParameter)4, (NiShaderDeclaration::ShaderParameterType)3, 0);
    pPixelDesc->SetEntry(5, 7, (NiShaderDeclaration::ShaderParameter)5, (NiShaderDeclaration::ShaderParameterType)1, 0);
    pPixelDesc->SetEntry(6, 0xe, (NiShaderDeclaration::ShaderParameter)0xd, (NiShaderDeclaration::ShaderParameterType)2, 0);
    pPixelDesc->SetEntry(7, 0xf, (NiShaderDeclaration::ShaderParameter)0xe, (NiShaderDeclaration::ShaderParameterType)2, 0);
    pPixelDesc->GetD3DDeclaration();
    FUN_00bcf7f0* pShader = new FUN_00bcf7f0(pVertexDesc, pPixelDesc);
    pShader->v019();
    pShader->v081();
    pShader->v084();
    pShader->v071();
    pShader->v048(pVertexDesc);
    return pShader;
}

struct FUN_00bd0ce0 : ShaderBase
{
    PassPtr passes[2];
    StagingNiPointer<RefObj> vs1[7];
    StagingNiPointer<RefObj> vs2[3];
    StagingNiPointer<RefObj> ps1[7];
    StagingNiPointer<RefObj> ps2[3];
    StagingNiPointer<RefObj> spE4;
    StagingNiPointer<RefObj> spE8;

    virtual void Initialize();
    ~FUN_00bd0ce0();
};

// Releases the shader's vertex/pixel shader pointers, clears both passes and resets the remaining references to null.
// @fnv 0x00bd0ce0
FUN_00bd0ce0::~FUN_00bd0ce0()
{
    for (int i = 0; i < 7; ++i)
        vs1[i] = 0;
    for (int i = 0; i < 7; ++i)
        ps1[i] = 0;
    for (int i = 0; i < 3; ++i)
        vs2[i] = 0;
    for (int i = 0; i < 3; ++i)
        ps2[i] = 0;
    for (int i = 0; i < 2; ++i)
        passes[i].clear();
    spE4 = 0;
    spE8 = 0;
    unk060 = 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct Ref1090
{
    virtual void vf00();
    virtual void DeleteThis();
    volatile long refs;
    void Inc()
    {
        InterlockedIncrement(&refs);
    }
    void Dec()
    {
        if (InterlockedDecrement(&refs) == 0)
            DeleteThis();
    }
};
struct Ptr1090
{
    Ref1090* value;
    Ptr1090(const Ptr1090& p) : value(p.value)
    {
        if (value)
            value->Inc();
    }
    ~Ptr1090()
    {
        if (value)
            value->Dec();
    }
    Ptr1090& operator=(Ref1090* p)
    {
        if (value != p)
        {
            if (value)
                value->Dec();
            value = p;
            if (p)
                p->Inc();
        }
        return *this;
    }
    operator Ref1090*() const
    {
        return value;
    }
};
struct Obj1090
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
    Ptr1090 m_30;
    Ptr1090 m_34;
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
    Ptr1090 m_7c;
    Ptr1090 m_80;
    Ptr1090 m_84;
    Ptr1090 m_88;
    void ShadowLightShader_CreateConstantMapsAlt();
};
Obj1090* __cdecl BSShaderManager_GetShader(int);
// @fnv 0x00bd1090
// src: COMMUNITY 0x00bd1090
void Obj1090::ShadowLightShader_CreateConstantMapsAlt()
{
    Obj1090* source = BSShaderManager_GetShader(1);
    Ptr1090 first(source->m_30);
    Ptr1090 second(source->m_34);
    m_34 = second.value;
    m_30 = first.value;
    m_7c = source->m_7c.value;
    m_80 = source->m_80.value;
    m_84 = source->m_84.value;
    m_88 = source->m_88.value;
}

struct Ref_bd12c0
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct Pass_bd12c0
{
    void IncRefCount();
    void DecRefCount();
};
struct VShader_bd12c0
{
    void IncRefCount();
    void DecRefCount();
};
struct PShader_bd12c0
{
    void IncRefCount();
    void DecRefCount();
};

struct ShaderBase_bd12c0
{
    ShaderBase_bd12c0(Ref_bd12c0* a, Ref_bd12c0* b, int c, int d);
    virtual ~ShaderBase_bd12c0();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    StagingNiPointer<Ref_bd12c0> m_sp28;
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
};

struct FUN_00bd12c0 : ShaderBase_bd12c0
{
    StagingNiPointer<Pass_bd12c0> m_spPasses[2];
    StagingNiPointer<VShader_bd12c0> m_spVS94[7];
    StagingNiPointer<PShader_bd12c0> m_spPSb0[3];
    StagingNiPointer<VShader_bd12c0> m_spVSbc[7];
    StagingNiPointer<PShader_bd12c0> m_spPSd8[3];
    StagingNiPointer<Ref_bd12c0> m_spe4;
    StagingNiPointer<Ref_bd12c0> m_spe8;

    FUN_00bd12c0(Ref_bd12c0* a, Ref_bd12c0* b);
    virtual ~FUN_00bd12c0();
};

// @fnv 0x00bd12c0
FUN_00bd12c0::FUN_00bd12c0(Ref_bd12c0* apRefA, Ref_bd12c0* apRefB) : ShaderBase_bd12c0(apRefA, apRefB, 0, 0)
{
    unk68 = 2;
    m_spe4 = apRefA;
    m_spe8 = apRefB;
    m_sp28 = (Ref_bd12c0*)m_spe8;
    unk60 = 0;
}

struct ShaderLayout
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void Set(int, int, int, int, int);
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void Finish();
};

ShaderLayout* __cdecl NiDX9ShaderDeclaration_Create(EventSystem*, int, int);
struct CreatedShader
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void Initialize19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void Attach(ShaderLayout*);
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void Initialize71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void Initialize81();
    virtual void slot82();
    virtual void slot83();
    virtual void Initialize84();
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
    static void* operator new(unsigned int);
    static void operator delete(void*);
    CreatedShader(ShaderLayout*, ShaderLayout*);
};
// @fnv 0x00bd14b0
// src: COMMUNITY 0x00bd14b0
CreatedShader* __cdecl HairShader_CreateShader()
{
    ShaderLayout* first = NiDX9ShaderDeclaration_Create(DAT_011f9508, 6, 1);
    ShaderLayout* second = NiDX9ShaderDeclaration_Create(DAT_011f9508, 8, 1);
    first->Set(0, 0, 0, 2, 0);
    first->Set(1, 3, 3, 2, 0);
    first->Set(2, 5, 4, 3, 0);
    first->Set(3, 7, 5, 1, 0);
    first->Set(4, 14, 13, 2, 0);
    first->Set(5, 15, 14, 2, 0);
    first->Finish();
    second->Set(0, 0, 0, 2, 0);
    second->Set(1, 1, 1, 3, 0);
    second->Set(2, 2, 2, 4, 0);
    second->Set(3, 3, 3, 2, 0);
    second->Set(4, 5, 4, 3, 0);
    second->Set(5, 7, 5, 1, 0);
    second->Set(6, 14, 13, 2, 0);
    second->Set(7, 15, 14, 2, 0);
    second->Finish();
    CreatedShader* shader = new CreatedShader(first, second);
    shader->Initialize19();
    shader->Initialize81();
    shader->Initialize84();
    shader->Initialize71();
    shader->Attach(first);
    return shader;
}

struct NiD3DPassPtr
{
    PassView* m_pObject;
    ~NiD3DPassPtr()
    {
        PassView* pkPass = m_pObject;
        if (pkPass && --pkPass->references == 0)
            pkPass->FUN_00e80190();
    }
};
struct FUN_00be0f10
{
    virtual void Unk_00();
    char m_auiShapeKeys[0x68];
    ~FUN_00be0f10();
};
struct FUN_00bd2c40 : FUN_00be0f10
{
    StagingNiPointer<NiD3DPixelShader> m_aspPixelShader[4];
    StagingNiPointer<NiD3DVertexShader> m_aspVertexShader[2];
    NiD3DPassPtr m_spPass;
    ~FUN_00bd2c40();
};

// Destructor releases the four pixel shader and two vertex shader references held by the object.
// @fnv 0x00bd2c40
FUN_00bd2c40::~FUN_00bd2c40()
{
    for (unsigned int i = 0; i < 4; i++)
    {
        RefObject* pkShader = (RefObject*)m_aspPixelShader[i].m_pObject;
        if (pkShader)
        {
            if (InterlockedDecrement(&pkShader->m_iObjectReferenceCount) == 0)
                pkShader->Release();
            m_aspPixelShader[i].m_pObject = 0;
        }
    }
    for (unsigned int i = 0; i < 2; i++)
    {
        RefObject* pkShader = (RefObject*)m_aspVertexShader[i].m_pObject;
        if (pkShader)
        {
            if (InterlockedDecrement(&pkShader->m_iObjectReferenceCount) == 0)
                pkShader->Release();
            m_aspVertexShader[i].m_pObject = 0;
        }
    }
}

class NiRenderer;
namespace fnv_00bd2e70 {
struct TLSData
{
    int unk000;
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
    int iAllocType;
};
extern __declspec(thread) TLSData g_tlsData;

struct MemContextGuard
{
    int iSaved;
    MemContextGuard(int iType)
    {
        iSaved = g_tlsData.iAllocType;
        g_tlsData.iAllocType = iType;
    }
    ~MemContextGuard()
    {
        g_tlsData.iAllocType = iSaved;
    }
};

extern NiRenderer* DAT_011f9508;

struct ShaderDecl
{
    static ShaderDecl* __cdecl Create(NiRenderer* pRenderer, unsigned int uiMaxStreamEntryCount,
                                      unsigned int uiStreamCount);
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
    virtual bool SetEntry(unsigned int uiEntry, unsigned int uiRegister, unsigned int eInput, unsigned int eType,
                          unsigned int uiStream);
    virtual void v24();
    virtual bool SetEntryEx(unsigned int uiStream, unsigned int uiEntry, unsigned int uiElapsedMilliseconds,
                            unsigned int eType, unsigned int eMethod, unsigned int eUsage, unsigned int uiUsageIndex,
                            unsigned int uiExtra);
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void MarkAsModified();
};

struct ShaderObj
{
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* p);
    ShaderObj();
    void Setup();
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
    virtual void Initialize();
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
    virtual void SetShaderDeclaration(ShaderDecl* pDecl);
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void InitPasses();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void CreatePasses();
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
};

// @fnv 0x00bd2e70
// src: COMMUNITY 0x00bd2e70
ShaderObj* __cdecl SpeedTreeFrondShader_CreateShader()
{
    MemContextGuard kGuard(0x1f);
    ShaderDecl* pDecl = ShaderDecl::Create(DAT_011f9508, 5, 1);
    pDecl->SetEntry(0, 0, (NiShaderDeclaration::ShaderParameter)0, (NiShaderDeclaration::ShaderParameterType)2, 0);
    pDecl->SetEntry(1, 3, (NiShaderDeclaration::ShaderParameter)3, (NiShaderDeclaration::ShaderParameterType)2, 0);
    pDecl->SetEntry(2, 5, (NiShaderDeclaration::ShaderParameter)4, (NiShaderDeclaration::ShaderParameterType)3, 0);
    pDecl->SetEntry(3, 7, (NiShaderDeclaration::ShaderParameter)5, (NiShaderDeclaration::ShaderParameterType)1, 0);
    pDecl->SetEntryEx(0, 4, 8, 0x80000000, 3, 2, 0, 0);
    pDecl->MarkAsModified();
    ShaderObj* pShader = new ShaderObj;
    pShader->Initialize();
    pShader->CreatePasses();
    pShader->Setup();
    pShader->InitPasses();
    pShader->SetShaderDeclaration(pDecl);
    return pShader;
}
}  // namespace fnv_00bd2e70

namespace fnv_00bd4ba0 {
struct GeomB8
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
};
struct GeomStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Bound* bound;
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
    GeomB8* unkb8;
    int unkbc;
};
struct PassArg
{
    int unk00;
    int unk04;
    int unk08;
};
struct FogStub;
struct PassShader
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void SetupPass(void* handler, GeomStub* geom, int bc, int a, int b8, PassArg* arg, int c, int* bounds68,
                           Bound* bound, int d, int e);
};
struct PassOwner
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
    PassShader* unk30;
    PassShader* unk34;
};
extern GeomStub** DAT_011f91e0;
extern Bound DAT_011f4288;
extern unsigned char DAT_011f91c4;
FogStub* __cdecl BSShaderManager_GetFogProperty(int idx);
PassOwner* __cdecl BSShaderManager_GetShader(int idx);
struct FUN_00bd4ba0_class
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void Apply(GeomStub* geom, FogStub* fog, int x);
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
    PassShader* unk30;
    PassShader* unk34;
    void Method_00b7dab0(PassArg* arg);
    void ApplyPasses(PassArg* arg);
};

// Reads the current geometry and its bound, calls Method_00b7dab0 and Apply, then runs SetupPass on the owner's and this object's shader passes.
// @fnv 0x00bd4ba0
void FUN_00bd4ba0_class::ApplyPasses(PassArg* pPassArg)
{
    GeomStub* geom = *DAT_011f91e0;
    Bound* bound = geom->bound;
    if (!bound)
        bound = &DAT_011f4288;
    int b8 = geom->unkb8->unk34;
    int bc = geom->unkbc;
    int x = pPassArg->unk08;
    Method_00b7dab0(pPassArg);
    FogStub* fog = BSShaderManager_GetFogProperty(DAT_011f91c4);
    Apply(geom, fog, x);
    PassOwner* owner = BSShaderManager_GetShader(1);
    owner->unk30->SetupPass((void*)DAT_0126f74c->unk44, geom, bc, 0, b8, pPassArg, 0, &geom->unk68, bound, 0, 1);
    owner->unk34->SetupPass(DAT_0126f74c->handler, geom, bc, 0, b8, pPassArg, 0, &geom->unk68, bound, 0, 1);
    PassShader* pShader30 = unk30;
    if (pShader30)
    {
        void* h = (void*)DAT_0126f74c->unk44;
        if (h)
            pShader30->SetupPass(h, geom, bc, 0, b8, pPassArg, 0, &geom->unk68, bound, 0, 1);
    }
    PassShader* pShader34 = unk34;
    if (pShader34)
    {
        void* h = DAT_0126f74c->handler;
        if (h)
            pShader34->SetupPass(h, geom, bc, 0, b8, pPassArg, 0, &geom->unk68, bound, 0, 1);
    }
}
}  // namespace fnv_00bd4ba0

void __cdecl FUN_00bb2f50(NiD3DShaderConstantMap* map, int count);

struct FUN_00bd4d30_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* m_pD3DDevice;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    StagingNiPointer<NiD3DShaderConstantMap> m_spFirstShaderConstantMap;
    StagingNiPointer<NiD3DShaderConstantMap> m_spSecondShaderConstantMap;
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
    StagingNiPointer<NiD3DShaderConstantMap> m_spCurrPixelConstantMap;
    StagingNiPointer<NiD3DShaderConstantMap> m_spCurrVertexConstantMap;

    void InitShaderConstantMaps();
};

// @fnv 0x00bd4d30
void FUN_00bd4d30_class::InitShaderConstantMaps()
{
    if (m_spSecondShaderConstantMap == 0)
        m_spSecondShaderConstantMap = new NiD3DShaderConstantMap((GraphicsRenderer*)m_pD3DDevice, (unsigned int)0);
    if (m_spFirstShaderConstantMap == 0)
        m_spFirstShaderConstantMap = new NiD3DShaderConstantMap((GraphicsRenderer*)m_pD3DDevice, (unsigned int)2);
    m_spCurrPixelConstantMap = m_spFirstShaderConstantMap;
    m_spCurrVertexConstantMap = m_spSecondShaderConstantMap;
    FUN_00bb2f50(m_spSecondShaderConstantMap, 0x2a);
}

void* __cdecl Object_DispatchCommandFour(unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct Ref
{
    virtual void unused();
    virtual void release();
    volatile long refs;
    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            release();
    }
};
template <class T> struct Ptr
{
    T* p;
    Ptr() : p(0)
    {}
    ~Ptr()
    {
        if (p)
            p->DecRefCount();
    }
    void operator=(const Ptr& q)
    {
        T* old = p;
        if (old != q.p)
        {
            if (old)
                old->DecRefCount();
            p = q.p;
            if (p)
                p->IncRefCount();
        }
    }
    void operator=(T* q)
    {
        T* old = p;
        if (old != q)
        {
            if (old)
                old->DecRefCount();
            p = q;
            if (p)
                p->IncRefCount();
        }
    }
    operator T*() const
    {
        return p;
    }
    T* operator->() const
    {
        return p;
    }
};

struct IntElement
{
    void* value;
    static void* operator new[](unsigned n)
    {
        return DAT_011f6238.Game_DoHeapAlloc(n);
    }
};
struct Member
{
    int a, b, c;
    Member();
};
struct Source : Ref
{
    int data;
    unsigned char mode;
    int indices;
    int multiplier;
    Ptr<Ref> texture;
    Ref* prop1;
    Ref* prop2;
    Ref* prop3;
    int unk28;
    unsigned int count;
    bool flag;
};
struct FUN_00ba63e0
{
    FUN_00ba63e0(int, bool);
    static void* operator new(unsigned size)
    {
        return Object_DispatchCommandFour(size);
    }
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28;
    void SetSize_Thunk(bool);
    void NiAdditionalGeometryData_SetDataBlock(int, int, unsigned, int);
    void NiAdditionalGeometryData_SetDataStream(int, int, int, int, int, int, int);
};
struct Owner
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
    FUN_00ba63e0* program;
    void FUN_00a67260(FUN_00ba63e0*);
};
struct Geometry : Ref
{
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
    Owner* owner;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    static void* operator new(unsigned size)
    {
        return Object_DispatchCommandFour(size);
    }
    void NiAVObject_AttachProperty(Ref*);
};
struct FUN_00c1a480 : Geometry
{
    FUN_00c1a480(int);
};
struct FUN_00c1a660 : Geometry
{
    FUN_00c1a660(int);
};
struct FUN_00b57f90 : Ref
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned flags20, flags24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    void* volatile dirty;
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
    void* parent;
    Ptr<Ref> texture;
    int unk84, unk88;
    FUN_00b57f90();
    static void* operator new(unsigned size)
    {
        return Object_DispatchCommandFour(size);
    }
};
extern int DAT_011f91c0;
void __cdecl FUN_00b57e30(Geometry*, int, int);
struct FUN_00bd6190
{
    Ptr<Geometry> geometry;
    Ptr<Source> source;
    Ptr<FUN_00b57f90> property;
    unsigned short capacity, count;
    ShaderVector4* values;
    IntElement* indices;
    Member member;
    int arg;
    FUN_00bd6190(Source*, int, bool);
    void DistantLODGroup_UpdateGroupBound();
};
// @fnv 0x00bd6190
FUN_00bd6190::FUN_00bd6190(Source* src, int argValue, bool flag)
{
    capacity = src->count;
    source = src;
    arg = argValue;
    values = (ShaderVector4*)new (DAT_011f6238) unsigned char[capacity][sizeof(ShaderVector4)];
    indices = new IntElement[capacity];
    for (int index = 0; index < capacity; ++index)
    {
        values[index].x = 0;
        values[index].y = 0;
        values[index].z = 0;
        values[index].w = 0;
        indices[index].value = 0;
    }
    count = capacity;
    for (int index = 0; index < count; ++index)
    {
        values[index].z = 0;
        values[index].w = 0;
        indices[index].value = 0;
    }
    count = 0;
    DistantLODGroup_UpdateGroupBound();
    geometry = (Geometry*)0;
    int data = src->data;
    if (src->mode == 1)
        geometry = new FUN_00c1a480(data);
    else
        geometry = new FUN_00c1a660(data);
    Ref* prop = DAT_011f91c0 < 2 ? src->prop2 : src->prop1;
    if (prop)
        geometry->NiAVObject_AttachProperty(prop);
    if (src->prop3)
        geometry->NiAVObject_AttachProperty(src->prop3);
    FUN_00b57f90* shader = new FUN_00b57f90;
    shader->texture = src->texture;
    shader->parent = this;
    if (flag)
    {
        if (!(shader->flags20 & 4))
            shader->dirty = 0;
        shader->flags20 |= 4;
    }
    else
    {
        if (shader->flags20 & 4)
            shader->dirty = 0;
        shader->flags20 &= ~4;
    }
    if (src->flag)
    {
        if (!(shader->flags24 & 0x2000))
            shader->dirty = 0;
        shader->flags24 |= 0x2000;
    }
    else
    {
        if (shader->flags24 & 0x2000)
            shader->dirty = 0;
        shader->flags24 &= ~0x2000;
    }
    geometry->NiAVObject_AttachProperty(shader);
    property = shader;
    FUN_00b57e30(geometry, 0, 0);
    Owner* owner = geometry->owner;
    if (!owner || !owner->program)
    {
        int total = src->multiplier * src->count;
        FUN_00ba63e0* program = new FUN_00ba63e0(total, true);
        program->SetSize_Thunk(true);
        program->NiAdditionalGeometryData_SetDataBlock(0, src->indices, total * 4, 0);
        program->NiAdditionalGeometryData_SetDataStream(0, 0, 0, 1, total, 4, 4);
        geometry->owner->FUN_00a67260(program);
    }
}

// The shared declaration has no virtual destructor; preserve the game's
// scalar-deleting virtual call without declaring another parameter class.
__forceinline void DeleteImageSpaceEffectParam(ImageSpaceEffectParam* param)
{
    typedef void* (__thiscall *DeletingDestructor)(ImageSpaceEffectParam*, unsigned int);
    if (param)
        (*(DeletingDestructor**)param)[0](param, 1);
}

#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTPrimitiveArray.h"
// Gamebryo NiTArray.inl: the original inlines GetAt
template <class T, class TAlloc> inline T& NiTArray<T, TAlloc>::GetAt(unsigned int uiIndex)
{
    return m_pBase[uiIndex];
}

struct FUN_00bd6f30
{
    virtual ~FUN_00bd6f30();
    int unk04, unk08, unk0C, unk10, unk14;
    NiTPrimitiveArray<ImageSpaceEffectParam*> m_Array;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78;
};

struct ISTexture_bd6fc0
{
    int unk00, unk04, unk08, unk0C;
    ~ISTexture_bd6fc0();
};

struct FUN_00bd6fc0 : FUN_00bd6f30
{
    ISTexture_bd6fc0 m_kTexture;
    ISTexture_bd6fc0 m_akTextures[3];
    virtual ~FUN_00bd6fc0();
};

// Deletes the effect parameter objects stored in m_Array at indices 2, 1, 0, 0 and 3, clearing each slot to null.
// @fnv 0x00bd6fc0
FUN_00bd6fc0::~FUN_00bd6fc0()
{
    if (m_Array.GetAt(2))
    {
        DeleteImageSpaceEffectParam(m_Array.GetAt(2));
        m_Array.SetAt(2, 0);
    }
    if (m_Array.GetAt(1))
    {
        DeleteImageSpaceEffectParam(m_Array.GetAt(1));
        m_Array.SetAt(1, 0);
    }
    if (m_Array.GetAt(0))
    {
        DeleteImageSpaceEffectParam(m_Array.GetAt(0));
        m_Array.SetAt(0, 0);
    }
    if (m_Array.GetAt(0))
    {
        DeleteImageSpaceEffectParam(m_Array.GetAt(0));
        m_Array.SetAt(0, 0);
    }
    if (m_Array.GetAt(3))
    {
        DeleteImageSpaceEffectParam(m_Array.GetAt(3));
        m_Array.SetAt(3, 0);
    }
}

extern NiPoint3 DAT_011a946c;
extern NiPoint3 DAT_011a9478;
extern const NiPoint3 DAT_011a9484;

struct ViewCamera
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
    NiPoint3 position;
    void SetLookAt(const NiPoint3& position, const NiPoint3& direction);
    void BSCubeMapCamera_SetupTransformation(unsigned int face);
};

// @fnv 0x00bd7200
// src: COMMUNITY 0x00bd7200
void ViewCamera::BSCubeMapCamera_SetupTransformation(unsigned int face)
{
    NiPoint3 direction0, position0, direction1, position1, position2;
    NiPoint3 direction3, position3, direction4, position4, direction5, position5;
    switch (face)
    {
    case 0: {
        direction0.x = -DAT_011a9478.x;
        direction0.y = -DAT_011a9478.y;
        direction0.z = -DAT_011a9478.z;
        position0.x = position.x - DAT_011a946c.x;
        position0.y = position.y - DAT_011a946c.y;
        position0.z = position.z - DAT_011a946c.z;
        SetLookAt(position0, direction0);
        break;
    }
    case 1: {
        direction1.x = -DAT_011a9478.x;
        direction1.y = -DAT_011a9478.y;
        direction1.z = -DAT_011a9478.z;
        double globalX = *(const volatile float*)&DAT_011a946c.x;
        position1.x = globalX + position.x;
        position1.y = position.y + DAT_011a946c.y;
        position1.z = position.z + DAT_011a946c.z;
        SetLookAt(position1, direction1);
        break;
    }
    case 2: {
        position2.x = position.x - DAT_011a9478.x;
        position2.y = position.y - DAT_011a9478.y;
        position2.z = position.z - DAT_011a9478.z;
        SetLookAt(position2, DAT_011a9484);
        break;
    }
    case 3: {
        direction3.x = -DAT_011a9484.x;
        direction3.y = -DAT_011a9484.y;
        direction3.z = -DAT_011a9484.z;
        position3.x = position.x + DAT_011a9478.x;
        position3.y = position.y + DAT_011a9478.y;
        position3.z = position.z + DAT_011a9478.z;
        SetLookAt(position3, direction3);
        break;
    }
    case 4: {
        direction4.x = -DAT_011a9478.x;
        direction4.y = -DAT_011a9478.y;
        direction4.z = -DAT_011a9478.z;
        position4.x = position.x - DAT_011a9484.x;
        position4.y = position.y - DAT_011a9484.y;
        position4.z = position.z - DAT_011a9484.z;
        SetLookAt(position4, direction4);
        break;
    }
    case 5: {
        direction5.x = -DAT_011a9478.x;
        direction5.y = -DAT_011a9478.y;
        direction5.z = -DAT_011a9478.z;
        position5.x = position.x + DAT_011a9484.x;
        position5.y = position.y + DAT_011a9484.y;
        position5.z = position.z + DAT_011a9484.z;
        SetLookAt(position5, direction5);
        break;
    }
    }
}

struct Bd84Owner : FUN_00bd74a0
{
    void RenderFaces();
    void BSCubeMapCamera_ClickCubeMapWithMask(int arg);
    void BSCubeMapCamera_Click(int arg);
};
// @fnv 0x00bd84b0
// src: XBOX_PDB 0x00bd84b0
void Bd84Owner::BSCubeMapCamera_Click(int arg)
{
    switch (unk114)
    {
    case 0:
        RenderFaces();
        break;
    case 1:
        goto done;
    case 2:
        goto done;
    case 3:
        BSCubeMapCamera_ClickCubeMapWithMask(arg);
        break;
    }
done:
    m_sp130 = 0;
    for (int i = 0; i < 6; i++)
    {
        m_spArr[i] = 0;
    }
}

struct Cand_bd9ac0
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
    BSShaderProperty::ShaderPassList* pPasses;

    int BSShaderProperty_AddPass_EnvMap(NiGeometry* geom, unsigned short* count, unsigned char type, bool* enabled, bool a, bool b);
};

// Adds a pass (0x244-0x247 selected by a/b/type) for the geometry, or increments count for non-type-1, then clears enabled and returns 0.
// @fnv 0x00bd9ac0
// src: COMMUNITY 0x00bd9ac0
int Cand_bd9ac0::BSShaderProperty_AddPass_EnvMap(NiGeometry* geom, unsigned short* count, unsigned char type, bool* enabled, bool abFlagA,
                              bool abFlagB)
{
    if (!abFlagA)
    {
        if (!abFlagB)
        {
            if (type == 1)
            {
                pPasses->Add(geom, 0x244, enabled[0], 0, 0, 0, 0, 0);
            }
            else
            {
                (*count)++;
            }
        }
        else
        {
            if (type == 1)
            {
                pPasses->Add(geom, 0x245, enabled[0], 0, 0, 0, 0, 0);
            }
            else
            {
                (*count)++;
            }
        }
    }
    else
    {
        if (!abFlagB)
        {
            if (type == 1)
            {
                pPasses->Add(geom, 0x246, enabled[0], 0, 0, 0, 0, 0);
            }
            else
            {
                (*count)++;
            }
        }
        else
        {
            if (type == 1)
            {
                pPasses->Add(geom, 0x247, enabled[0], 0, 0, 0, 0, 0);
            }
            else
            {
                (*count)++;
            }
        }
    }
    *enabled = false;
    return 0;
}

class ShadowSceneLightBD9;

class RenderPassArrayBD9
{
  public:
    void Add(NiGeometry* pkGeometry, unsigned short usPassType, bool bEnabled, unsigned char m_ucLightCount,
             ShadowSceneLightBD9* pkLight0, ShadowSceneLightBD9* pkLight1, ShadowSceneLightBD9* pkLight2,
             ShadowSceneLightBD9* pkLight3);
};

class ShaderPropertyBD9
{
  public:
    int BSShaderProperty_AddPass_Normals(NiGeometry* pkGeometry, unsigned short* pusPassCount, unsigned char ucMode, bool* pbFirstPass,
                     bool bAlpha, bool bHasAnimation);

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
    RenderPassArrayBD9* m_pkRenderPasses;
};

// @fnv 0x00bd9da0
// src: COMMUNITY 0x00bd9da0
int ShaderPropertyBD9::BSShaderProperty_AddPass_Normals(NiGeometry* pkGeometry, unsigned short* pusPassCount, unsigned char ucMode,
                                    bool* pbFirstPass, bool bAlpha, bool bHasAnimation)
{
    if (bHasAnimation)
    {
        if (ucMode == 1)
            m_pkRenderPasses->Add(pkGeometry, 0x1e4, *pbFirstPass, 0, 0, 0, 0, 0);
        else
            (*pusPassCount)++;
    }
    else if (!bAlpha)
    {
        if (ucMode == 1)
            m_pkRenderPasses->Add(pkGeometry, 0x1e2, *pbFirstPass, 0, 0, 0, 0, 0);
        else
            (*pusPassCount)++;
    }
    else
    {
        if (ucMode == 1)
            m_pkRenderPasses->Add(pkGeometry, 0x1e3, *pbFirstPass, 0, 0, 0, 0, 0);
        else
            (*pusPassCount)++;
    }
    *pbFirstPass = false;
    return 0;
}

struct ShadowSceneLight;
struct RenderPassSink
{
    void SubmitPass(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*,
                    ShadowSceneLight*, ShadowSceneLight*);
};
struct ShaderSelector
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
    RenderPassSink* pPasses;
    int BSShaderProperty_AddPass_AmbDiffTex(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count, unsigned char type, bool* out,
                     bool a, bool b, bool c, bool d, bool e, bool f, bool g);
};
// Chooses a pass id from the seven boolean flags and type, submits it via pPasses when type is 1, otherwise increments count; sets out to false and returns 0.
// @fnv 0x00bda0a0
// src: COMMUNITY 0x00bda0a0
int ShaderSelector::BSShaderProperty_AddPass_AmbDiffTex(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count, unsigned char type,
                                 bool* out, bool a, bool b, bool c, bool d, bool e, bool f, bool g)
{
    if (!a)
    {
        if (b)
        {
            if (c)
            {
                if (d)
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x88, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x6e, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                }
                else
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x86, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x87, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x6b, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x6c, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
            }
            else
            {
                if (d)
                {
                    if (!e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x6d, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                    }
                }
                else
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x83, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x84, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x69, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x6a, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
            }
        }
        else
        {
            if (c)
            {
                if (!d)
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x81, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x82, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x66, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x67, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
                else
                {
                }
            }
            else
            {
                if (d)
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x85, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x68, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                }
                else
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x7f, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (!g)
                            {
                                if (type == 1)
                                    pPasses->SubmitPass(geom, 0x80, true, 1, light, 0, 0, 0);
                                else
                                    ++*count;
                            }
                            else
                            {
                                if (type == 1)
                                    pPasses->SubmitPass(geom, 0x7b, true, 1, light, 0, 0, 0);
                                else
                                    ++*count;
                            }
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x64, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (!g)
                            {
                                if (type == 1)
                                    pPasses->SubmitPass(geom, 0x65, true, 1, light, 0, 0, 0);
                                else
                                    ++*count;
                            }
                            else
                            {
                                if (type == 1)
                                    pPasses->SubmitPass(geom, 0x7a, true, 1, light, 0, 0, 0);
                                else
                                    ++*count;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        if (b)
        {
            if (c)
            {
                if (d)
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x92, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x79, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                }
                else
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x90, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x91, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x76, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x77, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
            }
            else
            {
                if (d)
                {
                    if (!e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x78, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                    }
                }
                else
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x8d, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x8e, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x74, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x75, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
            }
        }
        else
        {
            if (c)
            {
                if (!d)
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x8b, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x8c, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x71, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x72, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
                else
                {
                }
            }
            else
            {
                if (d)
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x8f, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x73, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                        }
                    }
                }
                else
                {
                    if (e)
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x89, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x8a, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!f)
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x6f, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->SubmitPass(geom, 0x70, true, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
            }
        }
    }
    *out = false;
    return 0;
}

struct ShaderTwoLightSelector
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
    PassArray* passes;

    __forceinline void RegisterPass(NiGeometry* geometry, ShadowSceneLight* light0, ShadowSceneLight* light1,
                                    unsigned short* count, unsigned char type, unsigned short pass)
    {
        if (type == 1)
            passes->FUN_00ba9ee0(geometry, pass, true, 2, light0, light1, 0, 0);
        else
            ++*count;
    }

    int SelectTwoLightPass(NiGeometry* geometry, ShadowSceneLight* light0, ShadowSceneLight* light1,
                           unsigned short* count, unsigned char type, bool* first, bool a, bool b, bool c, bool unused,
                           bool e, bool f, bool g, bool h);
};

// Chooses a pass index from the boolean flags and registers it via RegisterPass, then clears *first and returns 0.
// @fnv 0x00bdca60
int ShaderTwoLightSelector::SelectTwoLightPass(NiGeometry* geometry, ShadowSceneLight* light0, ShadowSceneLight* light1,
                                               unsigned short* count, unsigned char type, bool* first, bool a, bool b,
                                               bool c, bool unused, bool e, bool f, bool g, bool h)
{
    if (!a)
    {
        if (b)
        {
            if (!c)
            {
                if (!f)
                {
                    if (!e)
                    {
                        RegisterPass(geometry, light0, light1, count, type, 0x117);
                    }
                    else
                    {
                        RegisterPass(geometry, light0, light1, count, type, 0x122);
                    }
                }
                else
                {
                    if (!e)
                    {
                        RegisterPass(geometry, light0, light1, count, type, 0x11a);
                    }
                    else
                    {
                        RegisterPass(geometry, light0, light1, count, type, 0x125);
                    }
                }
            }
            else
            {
            }
        }
        else
        {
            if (c)
            {
                if (!e)
                {
                    RegisterPass(geometry, light0, light1, count, type, 0x118);
                }
                else
                {
                    RegisterPass(geometry, light0, light1, count, type, 0x123);
                }
            }
            else
            {
                if (!f)
                {
                    if (!e)
                    {
                        if (!g)
                        {
                            if (!h)
                            {
                                RegisterPass(geometry, light0, light1, count, type, 0x116);
                            }
                            else
                            {
                                RegisterPass(geometry, light0, light1, count, type, 0x11b);
                            }
                        }
                        else
                        {
                            RegisterPass(geometry, light0, light1, count, type, 0x11f);
                        }
                    }
                    else
                    {
                        if (!g)
                        {
                            if (!h)
                            {
                                RegisterPass(geometry, light0, light1, count, type, 0x121);
                            }
                            else
                            {
                                RegisterPass(geometry, light0, light1, count, type, 0x126);
                            }
                        }
                        else
                        {
                            RegisterPass(geometry, light0, light1, count, type, 0x12a);
                        }
                    }
                }
                else
                {
                    if (!e)
                    {
                        RegisterPass(geometry, light0, light1, count, type, 0x119);
                    }
                    else
                    {
                        RegisterPass(geometry, light0, light1, count, type, 0x124);
                    }
                }
            }
        }
    }
    else
    {
        if (b)
        {
            if (!c)
            {
                if (!f)
                {
                    if (!e)
                    {
                        RegisterPass(geometry, light0, light1, count, type, 0x11d);
                    }
                    else
                    {
                        RegisterPass(geometry, light0, light1, count, type, 0x128);
                    }
                }
                else
                {
                }
            }
            else
            {
            }
        }
        else
        {
            if (c)
            {
                if (!e)
                {
                    RegisterPass(geometry, light0, light1, count, type, 0x11e);
                }
                else
                {
                    RegisterPass(geometry, light0, light1, count, type, 0x129);
                }
            }
            else
            {
                if (!f)
                {
                    if (!e)
                    {
                        if (!h)
                        {
                            RegisterPass(geometry, light0, light1, count, type, 0x11c);
                        }
                        else
                        {
                            RegisterPass(geometry, light0, light1, count, type, 0x120);
                        }
                    }
                    else
                    {
                        if (!h)
                        {
                            RegisterPass(geometry, light0, light1, count, type, 0x127);
                        }
                        else
                        {
                            RegisterPass(geometry, light0, light1, count, type, 0x12b);
                        }
                    }
                }
                else
                {
                }
            }
        }
    }
    *first = false;
    return 0;
}

class ShadowSceneLight;
struct Passes
{
    void FUN_00ba9ee0(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*,
                      ShadowSceneLight*, ShadowSceneLight*);
};
struct Shader
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
    Passes* passes;
    int BSShaderProperty_AddPass_ADTS(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count, unsigned char type, bool* out,
                     bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h);
};
// @fnv 0x00bdd050
// src: COMMUNITY 0x00bdd050
int Shader::BSShaderProperty_AddPass_ADTS(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count, unsigned char type,
                         bool* out, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h)
{
    if (!a)
    {
        if (b)
        {
            if (!c)
            {
                if (!f)
                {
                    if (!e)
                    {
                        if (type == 1)
                        {
                            passes->FUN_00ba9ee0(geom, 0x96, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->FUN_00ba9ee0(geom, 0xa1, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
                else
                {
                    if (!e)
                    {
                        if (type == 1)
                        {
                            passes->FUN_00ba9ee0(geom, 0x9a, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->FUN_00ba9ee0(geom, 0xa5, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
            }
        }
        else
        {
            if (!c)
            {
                if (!f)
                {
                    if (!e)
                    {
                        if (!g)
                        {
                            if (!h)
                            {
                                if (type == 1)
                                {
                                    passes->FUN_00ba9ee0(geom, 0x95, true, 1, light, 0, 0, 0);
                                }
                                else
                                {
                                    ++*count;
                                }
                            }
                            else
                            {
                                if (type == 1)
                                {
                                    passes->FUN_00ba9ee0(geom, 0x97, true, 1, light, 0, 0, 0);
                                }
                                else
                                {
                                    ++*count;
                                }
                            }
                        }
                        else
                        {
                            if (type == 1)
                            {
                                passes->FUN_00ba9ee0(geom, 0x9f, true, 1, light, 0, 0, 0);
                            }
                            else
                            {
                                ++*count;
                            }
                        }
                    }
                    else
                    {
                        if (!g)
                        {
                            if (!h)
                            {
                                if (type == 1)
                                {
                                    passes->FUN_00ba9ee0(geom, 0xa0, true, 1, light, 0, 0, 0);
                                }
                                else
                                {
                                    ++*count;
                                }
                            }
                            else
                            {
                                if (type == 1)
                                {
                                    passes->FUN_00ba9ee0(geom, 0xa2, true, 1, light, 0, 0, 0);
                                }
                                else
                                {
                                    ++*count;
                                }
                            }
                        }
                        else
                        {
                            if (type == 1)
                            {
                                passes->FUN_00ba9ee0(geom, 0xaa, true, 1, light, 0, 0, 0);
                            }
                            else
                            {
                                ++*count;
                            }
                        }
                    }
                }
                else
                {
                    if (!e)
                    {
                        if (type == 1)
                        {
                            passes->FUN_00ba9ee0(geom, 0x99, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->FUN_00ba9ee0(geom, 0xa4, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
            }
        }
    }
    else
    {
        if (b)
        {
            if (!c && !f)
            {
                if (!e)
                {
                    if (type == 1)
                    {
                        passes->FUN_00ba9ee0(geom, 0x9c, true, 1, light, 0, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
                else
                {
                    if (type == 1)
                    {
                        passes->FUN_00ba9ee0(geom, 0xa7, true, 1, light, 0, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
            }
        }
        else
        {
            if (!c && !f)
            {
                if (!e)
                {
                    if (!h)
                    {
                        if (type == 1)
                        {
                            passes->FUN_00ba9ee0(geom, 0x9b, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->FUN_00ba9ee0(geom, 0x9d, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
                else
                {
                    if (!h)
                    {
                        if (type == 1)
                        {
                            passes->FUN_00ba9ee0(geom, 0xa6, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->FUN_00ba9ee0(geom, 0xa8, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
            }
        }
    }
    *out = false;
    return 0;
}

struct ShaderPassBuilder : Shader_00bd9540
{
    int BSShaderProperty_AddPass_ADTS2(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, unsigned char, bool*, bool,
                     bool, bool, bool, bool, bool, bool, bool);
};
// Selects a shader pass index from the boolean flags and adds it to pPasses when type==1, otherwise increments *count; sets *out to false and returns 0.
// @fnv 0x00bdd520
// src: COMMUNITY 0x00bdd520
int ShaderPassBuilder::BSShaderProperty_AddPass_ADTS2(NiGeometry* geometry, ShadowSceneLight* light0, ShadowSceneLight* light1,
                                    unsigned short* count, unsigned char type, bool* out, bool a, bool b, bool c,
                                    bool d, bool e, bool f, bool g, bool h)
{
    if (!a)
    {
        if (b)
        {
            if (!c)
            {
                if (!f)
                {
                    if (!e)
                    {
                        if (type == 1)
                            pPasses->Add(geometry, 0xac, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                    else
                    {
                        if (type == 1)
                            pPasses->Add(geometry, 0xb7, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                }
                else
                {
                    if (!e)
                    {
                        if (type == 1)
                            pPasses->Add(geometry, 0xb0, true, 1, light0, 0, 0, 0);
                        else
                            ++*count;
                    }
                    else
                    {
                        if (type == 1)
                            pPasses->Add(geometry, 0xbb, true, 1, light0, 0, 0, 0);
                        else
                            ++*count;
                    }
                }
            }
        }
        else
        {
            if (!c)
            {
                if (!f)
                {
                    if (!e)
                    {
                        if (!g)
                        {
                            if (!h)
                            {
                                if (type == 1)
                                    pPasses->Add(geometry, 0xab, true, 2, light0, light1, 0, 0);
                                else
                                    ++*count;
                            }
                            else
                            {
                                if (type == 1)
                                    pPasses->Add(geometry, 0xad, true, 2, light0, light1, 0, 0);
                                else
                                    ++*count;
                            }
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->Add(geometry, 0xb5, true, 2, light0, light1, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!g)
                        {
                            if (!h)
                            {
                                if (type == 1)
                                    pPasses->Add(geometry, 0xb6, true, 2, light0, light1, 0, 0);
                                else
                                    ++*count;
                            }
                            else
                            {
                                if (type == 1)
                                    pPasses->Add(geometry, 0xb8, true, 2, light0, light1, 0, 0);
                                else
                                    ++*count;
                            }
                        }
                        else
                        {
                            if (type == 1)
                                pPasses->Add(geometry, 0xc0, true, 2, light0, light1, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
                else
                {
                    if (!e)
                    {
                        if (type == 1)
                            pPasses->Add(geometry, 0xaf, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                    else
                    {
                        if (type == 1)
                            pPasses->Add(geometry, 0xba, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                }
            }
        }
    }
    else
    {
        if (b)
        {
            if (!c && !f)
            {
                if (!e)
                {
                    if (type == 1)
                        pPasses->Add(geometry, 0xb2, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
                else
                {
                    if (type == 1)
                        pPasses->Add(geometry, 0xbd, true, 2, light0, light1, 0, 0);
                    else
                        ++*count;
                }
            }
        }
        else
        {
            if (!c && !f)
            {
                if (!e)
                {
                    if (!h)
                    {
                        if (type == 1)
                            pPasses->Add(geometry, 0xb1, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                    else
                    {
                        if (type == 1)
                            pPasses->Add(geometry, 0xb3, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                }
                else
                {
                    if (!h)
                    {
                        if (type == 1)
                            pPasses->Add(geometry, 0xbc, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                    else
                    {
                        if (type == 1)
                            pPasses->Add(geometry, 0xbe, true, 2, light0, light1, 0, 0);
                        else
                            ++*count;
                    }
                }
            }
        }
    }
    *out = false;
    return 0;
}

struct SelectColor
{
    float r, g, b;
    bool HasEqualComponents(const SelectColor&);
};
extern SelectColor DAT_011f4998;
extern bool DAT_011ad80d;
struct SelectMaterial
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
    SelectColor color;
    SelectColor* externalColor;
};
struct SelectLighting
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
    float alpha;
    float otherAlpha;
    bool FUN_004a2020(int);
};
struct SelectGeometry
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
    SelectMaterial* material;
    SelectLighting* lighting;
};
struct SelectShader
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
    BSShaderProperty::ShaderPassList* passes;
    int BSShaderProperty_AddPass_ADT(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count, unsigned char type, bool* out,
                     bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h, bool i, bool j, bool k);
};
// @fnv 0x00bde1d0
// src: COMMUNITY 0x00bde1d0
int SelectShader::BSShaderProperty_AddPass_ADT(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count, unsigned char type,
                               bool* out, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h, bool i,
                               bool j, bool k)
{
    if (!a)
    {
        if (b)
        {
            if (!c)
            {
                if (!f)
                {
                    if (!e)
                    {
                        if (type == 1)
                        {
                            passes->Add(geom, 255, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->Add(geom, 268, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
                else
                {
                    if (!e)
                    {
                        if (type == 1)
                        {
                            passes->Add(geom, 259, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->Add(geom, 271, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
            }
        }
        else
        {
            if (c)
            {
                if (!e)
                {
                    if (type == 1)
                    {
                        passes->Add(geom, 256, true, 1, light, 0, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
                else
                {
                    if (type == 1)
                    {
                        passes->Add(geom, 269, true, 1, light, 0, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
            }
            else
            {
                if (!f)
                {
                    if (!g)
                    {
                        if (!e)
                        {
                            if (!h && !i)
                            {
                                if (!j)
                                {
                                    if (type == 1)
                                    {
                                        SelectMaterial* mat = ((SelectGeometry*)geom)->material;
                                        SelectLighting* prop = ((SelectGeometry*)geom)->lighting;
                                        if (DAT_011ad80d &&
                                            (!mat || (mat->externalColor ? mat->externalColor : &mat->color)
                                                         ->HasEqualComponents(DAT_011f4998)) &&
                                            !(prop->alpha < 1.0f) && prop->FUN_004a2020(37))
                                        {
                                            passes->Add(geom, (prop->FUN_004a2020(34) ? 253 : 252), true, 1, light, 0,
                                                        0, 0);
                                        }
                                        else
                                        {
                                            passes->Add(geom, 251, true, 1, light, 0, 0, 0);
                                        }
                                    }
                                    else
                                    {
                                        ++*count;
                                    }
                                }
                                else
                                {
                                    if (type == 1)
                                    {
                                        passes->Add(geom, 260, true, 1, light, 0, 0, 0);
                                    }
                                    else
                                    {
                                        ++*count;
                                    }
                                }
                            }
                            else
                            {
                                if (i)
                                {
                                    if (type == 1)
                                    {
                                        passes->Add(geom, 565, true, 1, light, 0, 0, 0);
                                    }
                                    else
                                    {
                                        ++*count;
                                    }
                                }
                                else
                                {
                                    if (type == 1)
                                    {
                                        passes->Add(geom, 264, true, 1, light, 0, 0, 0);
                                    }
                                    else
                                    {
                                        ++*count;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (!h)
                            {
                                if (!j)
                                {
                                    if (type == 1)
                                    {
                                        passes->Add(geom, 266, true, 1, light, 0, 0, 0);
                                    }
                                    else
                                    {
                                        ++*count;
                                    }
                                }
                                else
                                {
                                    if (type == 1)
                                    {
                                        passes->Add(geom, 272, true, 1, light, 0, 0, 0);
                                    }
                                    else
                                    {
                                        ++*count;
                                    }
                                }
                            }
                            else
                            {
                                if (type == 1)
                                {
                                    passes->Add(geom, 276, true, 1, light, 0, 0, 0);
                                }
                                else
                                {
                                    ++*count;
                                }
                            }
                        }
                    }
                    else
                    {
                        if (!e)
                        {
                            if (type == 1)
                            {
                                passes->Add(geom, 254, true, 1, light, 0, 0, 0);
                            }
                            else
                            {
                                ++*count;
                            }
                        }
                        else
                        {
                            if (type == 1)
                            {
                                passes->Add(geom, 267, true, 1, light, 0, 0, 0);
                            }
                            else
                            {
                                ++*count;
                            }
                        }
                    }
                }
                else
                {
                    if (!e)
                    {
                        if (type == 1)
                        {
                            SelectMaterial* mat = ((SelectGeometry*)geom)->material;
                            SelectLighting* prop = ((SelectGeometry*)geom)->lighting;
                            if (DAT_011ad80d &&
                                (!mat ||
                                 (mat->externalColor ? mat->externalColor : &mat->color)->HasEqualComponents(DAT_011f4998)) &&
                                prop->FUN_004a2020(37) && !(prop->otherAlpha < 1.0f))
                            {
                                passes->Add(geom, 258, true, 1, light, 0, 0, 0);
                            }
                            else
                            {
                                passes->Add(geom, 257, true, 1, light, 0, 0, 0);
                            }
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->Add(geom, 270, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
            }
        }
    }
    else
    {
        if (b)
        {
            if (!c && !f)
            {
                if (!e)
                {
                    if (type == 1)
                    {
                        passes->Add(geom, 262, true, 1, light, 0, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
                else
                {
                    if (type == 1)
                    {
                        passes->Add(geom, 274, true, 1, light, 0, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
            }
        }
        else
        {
            if (c)
            {
                if (!e)
                {
                    if (type == 1)
                    {
                        passes->Add(geom, 263, true, 1, light, 0, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
                else
                {
                    if (type == 1)
                    {
                        passes->Add(geom, 275, true, 1, light, 0, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
            }
            else if (!f)
            {
                if (!e)
                {
                    if (!j)
                    {
                        if (type == 1)
                        {
                            passes->Add(geom, 261, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->Add(geom, 265, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
                else
                {
                    if (!j)
                    {
                        if (type == 1)
                        {
                            passes->Add(geom, 273, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->Add(geom, 277, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
            }
        }
    }
    *out = false;
    return 0;
}

namespace fnv_00bde9b0 {
struct Vec91
{
    float x, y, z;
    bool HasEqualComponents(const Vec91&);
    bool FUN_00439090(const Vec91&);
};
extern Vec91 DAT_011f4998;
extern bool DAT_011ad80d;
struct Color91
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
    Vec91 color;
    Vec91* external;
    Vec91& GetColor()
    {
        return external ? *external : color;
    }
};
struct Alpha91
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short flags;
    bool Enabled() const
    {
        return (flags >> 9) & 1;
    }
};
struct Flags91
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
    float alpha;
    float GetAlpha() const
    {
        return alpha;
    }
    bool FUN_004a2020(int);
};
struct Geometry91
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
    Alpha91* alpha;
    int unka0;
    Color91* color;
    Flags91* shader;
};
struct LightData91
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
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    Vec91 color;
};
struct Light91
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
    LightData91* data;
};
struct Pass91
{
    int unk00;
    unsigned short type;
    unsigned short unk06;
    unsigned char unk08, count, capacity, unk0b;
    Light91** lights;
    void BSShaderProperty_RenderPass_ClearSceneLights();
    void AllocateElemArray(unsigned int);
};
struct Passes91
{
    int unk00;
    Pass91** entries;
    int unk08, unk0c;
    unsigned int size;
    void FUN_00ba9ee0(Geometry91*, unsigned short, bool, unsigned char, Light91*, Light91*, Light91*, Light91*);
};
struct Shader91
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
    Passes91* passes;
    unsigned char BSShaderLightingProperty_GetNumberofActiveNonShadowLights();
    Light91* BSShaderLightingProperty_GetFirstActiveNonShadowLight(void*&);
    Light91* BSShaderLightingProperty_GetNextActiveNonShadowLight(void*&);
    bool FUN_004a2020(int);
    Pass91* BSShaderPPLightingProperty_AddPass_Opt(Geometry91*, Light91*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool);
};
// Builds a light pass from the shader's passes, fills its light list, and picks a pass type from the mode, light count and flags; returns the pass.
// @fnv 0x00bde9b0
// src: COMMUNITY 0x00bde9b0
Pass91* Shader91::BSShaderPPLightingProperty_AddPass_Opt(Geometry91* geometry, Light91* light, unsigned short* count, unsigned char mode,
                               bool* out, bool alternate, bool special, bool flagA, bool flagB, bool extra)
{
    Pass91* pass = 0;
    if (mode)
    {
        passes->FUN_00ba9ee0(geometry, 0, true, 0, 0, 0, 0, 0);
        pass = passes->entries[passes->size - 1];
        pass->capacity = pass->count = BSShaderLightingProperty_GetNumberofActiveNonShadowLights() + 1;
        pass->BSShaderProperty_RenderPass_ClearSceneLights();
        pass->AllocateElemArray(pass->count);
        pass->lights[0] = light;
        int lights = pass->count;
        int limit = extra ? 2 : 1;
        if (!flagA)
        {
            if (!flagB)
                limit += 5;
            else
                limit += 4;
            lights = lights < limit ? lights : limit;
        }
        else if (!flagB)
        {
            limit += 2;
            lights = lights < limit ? lights : limit;
        }
        pass->count = lights;
        void* position = 0;
        Light91* next = BSShaderLightingProperty_GetFirstActiveNonShadowLight(position);
        int i = 1;
        while (next && i < pass->count)
        {
            pass->lights[i++] = next;
            next = BSShaderLightingProperty_GetNextActiveNonShadowLight(position);
        }
    }
    int lights = pass->count;
    if (!alternate)
    {
        if (special)
        {
            if (flagA)
            {
                if (mode == 1)
                    pass->type = 210;
                else
                    ++*count;
            }
            else if (lights < 5)
            {
                if (mode == 1)
                    pass->type = 203;
                else
                    ++*count;
            }
            else
            {
                if (mode == 1)
                    pass->type = 196;
                else
                    ++*count;
            }
        }
        else if (flagA)
        {
            if (flagB)
            {
                if (mode == 1)
                    pass->type = 211;
                else
                    ++*count;
            }
            else
            {
                if (mode == 1)
                {
                    Color91* color = geometry->color;
                    Flags91* shader = geometry->shader;
                    Alpha91* alpha = geometry->alpha;
                    if (DAT_011ad80d && (!color || color->GetColor().HasEqualComponents(DAT_011f4998)) &&
                        !light->data->color.FUN_00439090(DAT_011f4998) && shader->FUN_004a2020(37) &&
                        (!alpha || !alpha->Enabled() || !(shader->GetAlpha() < 1.0f)) && !FUN_004a2020(7) &&
                        !FUN_004a2020(21) && !FUN_004a2020(17) && !shader->FUN_004a2020(26) &&
                        !shader->FUN_004a2020(27))
                        pass->type = 209;
                    else
                        pass->type = 208;
                }
                else
                    ++*count;
            }
        }
        else if (flagB)
        {
            if (lights < 5)
            {
                if (mode == 1)
                    pass->type = 204;
                else
                    ++*count;
            }
            else
            {
                if (mode == 1)
                    pass->type = 197;
                else
                    ++*count;
            }
        }
        else if (lights < 5)
        {
            if (mode == 1)
            {
                Color91* color = geometry->color;
                Flags91* shader = geometry->shader;
                if (DAT_011ad80d && (!color || color->GetColor().HasEqualComponents(DAT_011f4998)) &&
                    !light->data->color.FUN_00439090(DAT_011f4998) && shader->FUN_004a2020(37) &&
                    !(shader->GetAlpha() < 1.0f) && !FUN_004a2020(7) && !FUN_004a2020(21) && !FUN_004a2020(17) &&
                    !shader->FUN_004a2020(26) && !shader->FUN_004a2020(27))
                    pass->type = 202;
                else
                    pass->type = 201;
            }
            else
                ++*count;
        }
        else
        {
            if (mode == 1)
                pass->type = 195;
            else
                ++*count;
        }
    }
    else
    {
        if (special)
        {
            if (flagA)
            {
                if (mode == 1)
                    pass->type = 213;
                else
                    ++*count;
            }
            else if (lights < 5)
            {
                if (mode == 1)
                    pass->type = 206;
                else
                    ++*count;
            }
            else
            {
                if (mode == 1)
                    pass->type = 199;
                else
                    ++*count;
            }
        }
        else if (flagA)
        {
            if (flagB)
            {
                if (mode == 1)
                    pass->type = 214;
                else
                    ++*count;
            }
            else
            {
                if (mode == 1)
                    pass->type = 212;
                else
                    ++*count;
            }
        }
        else if (flagB)
        {
            if (lights < 5)
            {
                if (mode == 1)
                    pass->type = 207;
                else
                    ++*count;
            }
            else
            {
                if (mode == 1)
                    pass->type = 200;
                else
                    ++*count;
            }
        }
        else if (lights < 5)
        {
            if (mode == 1)
                pass->type = 205;
            else
                ++*count;
        }
        else
        {
            if (mode == 1)
                pass->type = 198;
            else
                ++*count;
        }
    }
    *out = false;
    return pass;
}
}  // namespace fnv_00bde9b0

namespace fnv_00bdef40 {
struct Vec98
{
    float x, y, z;
    bool Equal(const Vec98& v) const
    {
        return x == v.x && y == v.y && z == v.z;
    }
};
extern Vec98 DAT_011f4998;
struct Data98
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
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    Vec98 color;
};
struct Light98
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
    bool special;
    unsigned char unkf5, unkf6, unkf7;
    Data98* data;
};
struct Passes98
{
    void FUN_00ba9ee0(NiGeometry*, unsigned short, bool, unsigned char, Light98*, Light98*, Light98*, Light98*);
};
struct Shader98
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
    Passes98* passes;
    int BSShaderProperty_AddPass_Specular(NiGeometry*, Light98*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool, bool);
};
// If the light's color differs from DAT_011f4998, picks a pass id from the flag combination and either runs FUN_00ba9ee0 or increments *count, then clears *out.
// @fnv 0x00bdef40
// src: COMMUNITY 0x00bdef40
int Shader98::BSShaderProperty_AddPass_Specular(NiGeometry* geom, Light98* light, unsigned short* count, unsigned char mode, bool* out,
                           bool alternate, bool unused, bool flagA, bool flagB, bool flagC, bool flagD)
{
    bool special = light->special;
    if (!light->data->color.Equal(DAT_011f4998))
    {
        if (!alternate)
        {
            if (!special)
            {
                if (!flagB)
                {
                    if (!flagA)
                    {
                        if (!flagC)
                        {
                            if (!flagD)
                            {
                                if (mode == 1)
                                    passes->FUN_00ba9ee0(geom, 346, *out, 1, light, 0, 0, 0);
                                else
                                    ++*count;
                            }
                            else
                            {
                                if (mode == 1)
                                    passes->FUN_00ba9ee0(geom, 347, *out, 1, light, 0, 0, 0);
                                else
                                    ++*count;
                            }
                        }
                        else
                        {
                            if (mode == 1)
                                passes->FUN_00ba9ee0(geom, 351, *out, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!flagC)
                        {
                            if (!flagD)
                            {
                                if (mode == 1)
                                    passes->FUN_00ba9ee0(geom, 352, *out, 1, light, 0, 0, 0);
                                else
                                    ++*count;
                            }
                            else
                            {
                                if (mode == 1)
                                    passes->FUN_00ba9ee0(geom, 353, *out, 1, light, 0, 0, 0);
                                else
                                    ++*count;
                            }
                        }
                        else
                        {
                            if (mode == 1)
                                passes->FUN_00ba9ee0(geom, 357, *out, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
                else
                {
                    if (!flagA)
                    {
                        if (mode == 1)
                            passes->FUN_00ba9ee0(geom, 348, *out, 1, light, 0, 0, 0);
                        else
                            ++*count;
                    }
                    else
                    {
                        if (mode == 1)
                            passes->FUN_00ba9ee0(geom, 354, *out, 1, light, 0, 0, 0);
                        else
                            ++*count;
                    }
                }
            }
            else
            {
                if (!flagB)
                {
                    if (!flagC)
                    {
                        if (!flagD)
                        {
                            if (mode == 1)
                                passes->FUN_00ba9ee0(geom, 358, *out, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (mode == 1)
                                passes->FUN_00ba9ee0(geom, 359, *out, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (mode == 1)
                            passes->FUN_00ba9ee0(geom, 363, *out, 1, light, 0, 0, 0);
                        else
                            ++*count;
                    }
                }
                else
                {
                    if (mode == 1)
                        passes->FUN_00ba9ee0(geom, 360, *out, 1, light, 0, 0, 0);
                    else
                        ++*count;
                }
            }
        }
        else
        {
            if (!special)
            {
                if (!flagB)
                {
                    if (!flagA)
                    {
                        if (!flagD)
                        {
                            if (mode == 1)
                                passes->FUN_00ba9ee0(geom, 349, *out, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (mode == 1)
                                passes->FUN_00ba9ee0(geom, 350, *out, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!flagD)
                        {
                            if (mode == 1)
                                passes->FUN_00ba9ee0(geom, 355, *out, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (mode == 1)
                                passes->FUN_00ba9ee0(geom, 356, *out, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
            }
            else
            {
                if (!flagB)
                {
                    if (!flagD)
                    {
                        if (mode == 1)
                            passes->FUN_00ba9ee0(geom, 361, *out, 1, light, 0, 0, 0);
                        else
                            ++*count;
                    }
                    else
                    {
                        if (mode == 1)
                            passes->FUN_00ba9ee0(geom, 362, *out, 1, light, 0, 0, 0);
                        else
                            ++*count;
                    }
                }
            }
        }
        *out = false;
    }
    return 0;
}
}  // namespace fnv_00bdef40

// Credit: unverified prior contributor (2026-10-23).
struct ParallaxDescriptor
{
    const char* file;
    const char* macros[18];
};
struct ParallaxShader
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
    BeamPtr shaders[20];
    RefObject* FUN_00be0fe0(const char*, unsigned int*, const char*, const char*);
    void CreateParallaxShaders();
};
// Builds 20 parallax vertex-shader descriptors and, when DAT_011f91c0 >= 2, compiles each into shaders[i].
// @fnv 0x00bcc750
void ParallaxShader::CreateParallaxShaders()
{
    ParallaxDescriptor descriptors[20];
    descriptors[0].file = "lighting\\2x\\v\\ADTS.v.hlsl";
    descriptors[0].macros[0] = "PARALLAX";
    descriptors[0].macros[1] = "";
    descriptors[0].macros[2] = 0;
    FUN_00ec61c0(&descriptors[0].macros[3], 0, 60);
    descriptors[1].file = "lighting\\2x\\v\\ADTS.v.hlsl";
    descriptors[1].macros[0] = "PARALLAX";
    descriptors[1].macros[1] = "";
    descriptors[1].macros[2] = "PROJ_SHADOW";
    descriptors[1].macros[3] = "";
    descriptors[1].macros[4] = 0;
    FUN_00ec61c0(&descriptors[1].macros[5], 0, 52);
    descriptors[2].file = "lighting\\2x\\v\\ADTS.v.hlsl";
    descriptors[2].macros[0] = "LIGHTS";
    descriptors[2].macros[1] = "2";
    descriptors[2].macros[2] = "PARALLAX";
    descriptors[2].macros[3] = "";
    descriptors[2].macros[4] = 0;
    FUN_00ec61c0(&descriptors[2].macros[5], 0, 52);
    descriptors[3].file = "lighting\\2x\\v\\ADTS.v.hlsl";
    descriptors[3].macros[0] = "LIGHTS";
    descriptors[3].macros[1] = "2";
    descriptors[3].macros[2] = "PARALLAX";
    descriptors[3].macros[3] = "";
    descriptors[3].macros[4] = "PROJ_SHADOW";
    descriptors[3].macros[5] = "";
    descriptors[3].macros[6] = 0;
    FUN_00ec61c0(&descriptors[3].macros[7], 0, 44);
    descriptors[4].file = "lighting\\2x\\v\\ADTS.v.hlsl";
    descriptors[4].macros[0] = "SPECULAR";
    descriptors[4].macros[1] = "";
    descriptors[4].macros[2] = "PARALLAX";
    descriptors[4].macros[3] = "";
    descriptors[4].macros[4] = 0;
    FUN_00ec61c0(&descriptors[4].macros[5], 0, 52);
    descriptors[5].file = "lighting\\2x\\v\\ADTS.v.hlsl";
    descriptors[5].macros[0] = "SPECULAR";
    descriptors[5].macros[1] = "";
    descriptors[5].macros[2] = "PARALLAX";
    descriptors[5].macros[3] = "";
    descriptors[5].macros[4] = "PROJ_SHADOW";
    descriptors[5].macros[5] = "";
    descriptors[5].macros[6] = 0;
    FUN_00ec61c0(&descriptors[5].macros[7], 0, 44);
    descriptors[6].file = "lighting\\2x\\v\\ADTS.v.hlsl";
    descriptors[6].macros[0] = "SPECULAR";
    descriptors[6].macros[1] = "";
    descriptors[6].macros[2] = "LIGHTS";
    descriptors[6].macros[3] = "2";
    descriptors[6].macros[4] = "PARALLAX";
    descriptors[6].macros[5] = "";
    descriptors[6].macros[6] = 0;
    FUN_00ec61c0(&descriptors[6].macros[7], 0, 44);
    descriptors[7].file = "lighting\\2x\\v\\ADTS.v.hlsl";
    descriptors[7].macros[0] = "SPECULAR";
    descriptors[7].macros[1] = "";
    descriptors[7].macros[2] = "LIGHTS";
    descriptors[7].macros[3] = "2";
    descriptors[7].macros[4] = "PARALLAX";
    descriptors[7].macros[5] = "";
    descriptors[7].macros[6] = "PROJ_SHADOW";
    descriptors[7].macros[7] = "";
    descriptors[7].macros[8] = 0;
    memset(&descriptors[7].macros[9], 0, 36);
    descriptors[8].file = "lighting\\2x\\v\\AD.v.hlsl";
    descriptors[8].macros[0] = "LIGHTS";
    descriptors[8].macros[1] = "2";
    descriptors[8].macros[2] = "PARALLAX";
    descriptors[8].macros[3] = "";
    descriptors[8].macros[4] = 0;
    FUN_00ec61c0(&descriptors[8].macros[5], 0, 52);
    descriptors[9].file = "lighting\\2x\\v\\AD.v.hlsl";
    descriptors[9].macros[0] = "LIGHTS";
    descriptors[9].macros[1] = "2";
    descriptors[9].macros[2] = "PARALLAX";
    descriptors[9].macros[3] = "";
    descriptors[9].macros[4] = "PROJ_SHADOW";
    descriptors[9].macros[5] = "";
    descriptors[9].macros[6] = 0;
    FUN_00ec61c0(&descriptors[9].macros[7], 0, 44);
    descriptors[10].file = "lighting\\2x\\v\\AD.v.hlsl";
    descriptors[10].macros[0] = "LIGHTS";
    descriptors[10].macros[1] = "3";
    descriptors[10].macros[2] = "PARALLAX";
    descriptors[10].macros[3] = "";
    descriptors[10].macros[4] = 0;
    FUN_00ec61c0(&descriptors[10].macros[5], 0, 52);
    descriptors[11].file = "lighting\\2x\\v\\AD.v.hlsl";
    descriptors[11].macros[0] = "LIGHTS";
    descriptors[11].macros[1] = "3";
    descriptors[11].macros[2] = "PARALLAX";
    descriptors[11].macros[3] = "";
    descriptors[11].macros[4] = "PROJ_SHADOW";
    descriptors[11].macros[5] = "";
    descriptors[11].macros[6] = 0;
    FUN_00ec61c0(&descriptors[11].macros[7], 0, 44);
    descriptors[12].file = "lighting\\2x\\v\\DiffusePt.v.hlsl";
    descriptors[12].macros[0] = "LIGHTS";
    descriptors[12].macros[1] = "2";
    descriptors[12].macros[2] = "PARALLAX";
    descriptors[12].macros[3] = "";
    descriptors[12].macros[4] = 0;
    FUN_00ec61c0(&descriptors[12].macros[5], 0, 52);
    descriptors[13].file = "lighting\\2x\\v\\DiffusePt.v.hlsl";
    descriptors[13].macros[0] = "LIGHTS";
    descriptors[13].macros[1] = "3";
    descriptors[13].macros[2] = "PARALLAX";
    descriptors[13].macros[3] = "";
    descriptors[13].macros[4] = 0;
    FUN_00ec61c0(&descriptors[13].macros[5], 0, 52);
    descriptors[14].file = "lighting\\2x\\v\\Texture.v.hlsl";
    descriptors[14].macros[0] = "PARALLAX";
    descriptors[14].macros[1] = "";
    descriptors[14].macros[2] = 0;
    FUN_00ec61c0(&descriptors[14].macros[3], 0, 60);
    descriptors[15].file = "lighting\\2x\\v\\Specular.v.hlsl";
    descriptors[15].macros[0] = "PARALLAX";
    descriptors[15].macros[1] = "";
    descriptors[15].macros[2] = 0;
    FUN_00ec61c0(&descriptors[15].macros[3], 0, 60);
    descriptors[16].file = "lighting\\2x\\v\\Specular.v.hlsl";
    descriptors[16].macros[0] = "PARALLAX";
    descriptors[16].macros[1] = "";
    descriptors[16].macros[2] = "PROJ_SHADOW";
    descriptors[16].macros[3] = "";
    descriptors[16].macros[4] = 0;
    FUN_00ec61c0(&descriptors[16].macros[5], 0, 52);
    descriptors[17].file = "lighting\\2x\\v\\Specular.v.hlsl";
    descriptors[17].macros[0] = "POINT";
    descriptors[17].macros[1] = "";
    descriptors[17].macros[2] = "PARALLAX";
    descriptors[17].macros[3] = "";
    descriptors[17].macros[4] = 0;
    FUN_00ec61c0(&descriptors[17].macros[5], 0, 52);
    descriptors[18].file = "lighting\\2x\\v\\Specular.v.hlsl";
    descriptors[18].macros[0] = "NUM_PT_LIGHTS";
    descriptors[18].macros[1] = "2";
    descriptors[18].macros[2] = "POINT";
    descriptors[18].macros[3] = "";
    descriptors[18].macros[4] = "PARALLAX";
    descriptors[18].macros[5] = "";
    descriptors[18].macros[6] = 0;
    FUN_00ec61c0(&descriptors[18].macros[7], 0, 44);
    descriptors[19].file = "lighting\\2x\\v\\Specular.v.hlsl";
    descriptors[19].macros[0] = "NUM_PT_LIGHTS";
    descriptors[19].macros[1] = "3";
    descriptors[19].macros[2] = "POINT";
    descriptors[19].macros[3] = "";
    descriptors[19].macros[4] = "PARALLAX";
    descriptors[19].macros[5] = "";
    descriptors[19].macros[6] = 0;
    FUN_00ec61c0(&descriptors[19].macros[7], 0, 44);

    char sourceName[260];
    char binaryName[260];
    if (DAT_011f91c0 >= 2)
    {
        for (int i = 0; i < 20; ++i)
        {
            FUN_00be0c00(descriptors[i].file, sourceName);
            BSsprintf(binaryName, 260, "PAR2%03i.vso", i);
            shaders[i].Assign(FUN_00be0fe0(sourceName, (unsigned int*)descriptors[i].macros, "vs_2_0", binaryName));
        }
    }
}

extern int DAT_011ae61c;
struct FloatElem
{
    float v;
    static void* operator new[](unsigned int bytes)
    {
        return DAT_011f6238.Game_DoHeapAlloc(bytes);
    }
};
static inline unsigned int GetTableCount()
{
    if (DAT_01201f50 == 0)
        DAT_01201f50 = (DAT_011f91c0 >= 2) ? 0xeb : 0x4b;
    return DAT_01201f50;
}
// @fnv 0x00bc0b70
void* GetOrCreateTable()
{
    if (DAT_01201f4c)
        return DAT_01201f4c;
    unsigned int n = GetTableCount() * DAT_011ae61c;
    FloatElem* p = new FloatElem[n * 4];
    DAT_01201f4c = p;
    unsigned int i = 0;
    if (i < n)
    {
        do
        {
            float fIndex = (float)i;
            float fDivisor = (float)DAT_011ae61c;
            float q = fIndex / fDivisor;
            float r = (fIndex + 1.0f) / fDivisor;
            p[i * 4 + 0].v = q;
            p[i * 4 + 1].v = q;
            p[i * 4 + 2].v = r;
            p[i * 4 + 3].v = r;
            i++;
        } while (i < n);
        return DAT_01201f4c;
    }
    return DAT_01201f4c;
}

void __cdecl BSShaderProperty_RegisterStreamables();
// @fnv 0x00bc3770
// src: XBOX_PDB 0x00bc3770
void __cdecl BSShaderLightingProperty_RegisterStreamables()
{
    BSShaderProperty_RegisterStreamables();
}

void __cdecl FUN_00be0870();
// @fnv 0x00bc4600
// src: XBOX_PDB 0x00bc4600
void __cdecl ParticleShader_Initialize()
{
    FUN_00be0870();
}

struct FUN_00bcd380_class
{
    int __thiscall ParallaxShader_GetShaderDeclaration(int, int);
};
// @fnv 0x00bcd380
// src: COMMUNITY 0x00bcd380
int FUN_00bcd380_class::ParallaxShader_GetShaderDeclaration(int, int)
{
    return *(int*)((char*)this + 0x6c);
}

struct FUN_00bd0420_StandIn
{
    int __fastcall SkinShader_GetShaderDeclaration(int edx, void* a, void* b);
};
// @fnv 0x00bd0420
// src: COMMUNITY 0x00bd0420
int __fastcall FUN_00bd0420_StandIn::SkinShader_GetShaderDeclaration(int edx, void* a, void* apUnused)
{
    if (*(int*)((char*)a + 0xbc))
        return *(int*)((char*)this + 0x70);
    return *(int*)((char*)this + 0x6c);
}

struct FUN_00e81880_shell
{
    bool FUN_00e81880(NiGeometry*);
};
struct FUN_00bd16d0_class
{
    bool FUN_00bd16d0(NiGeometry*);
};
// @fnv 0x00bd16d0
bool FUN_00bd16d0_class::FUN_00bd16d0(NiGeometry* geom)
{
    return ((FUN_00e81880_shell*)this)->FUN_00e81880(geom);
}

struct NiTexture;

struct PassTexSlot
{
    int unk00;
    int unk04;
    NiTexture* pTexture;
};

struct PassTextureSlotCollection
{
    PassTexSlot* pSlot0;
    PassTexSlot* pSlot1;
    PassTexSlot* pSlot2;
    PassTexSlot* pSlot3;
    PassTexSlot* pSlot4;
    PassTexSlot* pSlot5;
    PassTexSlot* pSlot6;
    PassTexSlot* pSlot7;
};

struct PassOwner
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
    PassTextureSlotCollection* pPasses;
};

struct TexHolder
{
    NiTexture* pTexture;
};

struct ShaderPropertyStub
{
    char m_ucType;
};

struct ShaderPropertyData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct TextureReceiverStub
{
    NiTexture* GetTexture(int i);
};

struct RenderTargetHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct GeomStub2
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct PropStub
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
    TexHolder* pTexHolder;
};

struct GeomArg
{
    int unk00;
    int unk04;
    int unk08;
    PropStub* pProp;
};

struct RendererObj
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
    TextureReceiverStub* m_pReceiver;
};

struct RendererHolder
{
    RendererObj* pObj;
};

struct SceneStub
{
    int unk00;
    int unk04;
    int unk08;
    RendererHolder* pHolder;
};

// extern PassOwner* DAT_0126f74c;
extern unsigned int DAT_011f91e4;
extern NiTexture* DAT_011f95e4;
extern NiTexture* DAT_011f95e8;
extern SceneStub* DAT_011f91e0;

struct ShaderStub
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
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void v40();
    virtual void v41();
    virtual void UpdateConstants();

    NiTexture* LoadTexture(PropStub* prop, int i);
    void SetupPassTextures(GeomArg* geom);
};

// Assigns textures to the pass slots selected by DAT_011f91e4, loading from the geometry's prop or global textures, then calls UpdateConstants.
// @fnv 0x00bd4890
void ShaderStub::SetupPassTextures(GeomArg* geom)
{
    PropStub* prop = geom->pProp;
    PassOwner* owner = (PassOwner*)DAT_0126f74c;
    unsigned int pass = DAT_011f91e4;

    switch (pass)
    {
    case 0x7e:
    case 0x130:
    case 0x131:
    case 0x137:
    case 0x143:
    case 0x158:
    case 0x159:
    case 0x15f:
    case 0x165:
    case 0x16b:
    case 0x171:
    case 0x177: {
        PassTexSlot* slot = owner->pPasses->pSlot0;
        slot->pTexture = LoadTexture(prop, 0);
    }
    break;
    case 0x7a:
    case 0x7b:
    case 0x9f:
    case 0xaa:
    case 0xb5:
    case 0xc0:
    case 0xdf:
    case 0xe8:
    case 0xf1:
    case 0xfa:
    case 0x108:
    case 0x114:
    case 0x11f:
    case 0x12a:
        owner->pPasses->pSlot0->pTexture = prop->pTexHolder->pTexture;
        {
            PassTexSlot* slot = owner->pPasses->pSlot1;
            slot->pTexture = LoadTexture(prop, 0);
        }
        break;
    case 0x151:
    case 0x234:
        owner->pPasses->pSlot0->pTexture = prop->pTexHolder->pTexture;
        break;
    }

    switch (pass)
    {
    case 0xe8:
    case 0xfa:
        owner->pPasses->pSlot5->pTexture = DAT_011f95e4;
        owner->pPasses->pSlot6->pTexture = DAT_011f95e8;
        break;
    case 0xaa:
    case 0xc0:
    case 0x114:
    case 0x12a:
        owner->pPasses->pSlot6->pTexture = DAT_011f95e4;
        owner->pPasses->pSlot7->pTexture = DAT_011f95e8;
        break;
    case 0x165:
        owner->pPasses->pSlot1->pTexture = DAT_011f95e4;
        owner->pPasses->pSlot2->pTexture = DAT_011f95e8;
        break;
    }

    if (pass == 0x234)
    {
        PassTexSlot* slot = owner->pPasses->pSlot6;
        slot->pTexture = DAT_011f91e0->pHolder->pObj->m_pReceiver->GetTexture(0);
    }

    UpdateConstants();
}

struct ShaderSource
{
    int x, y, z;
};
struct ShaderSourceRecord
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned int flags;
    int unk28, unk2c, unk30, unk34;
    int associatedValue;
};
struct ShaderState
{
    int unk00, unk04;
    ShaderSourceRecord* controller;
    int unk0c, unk10, unk14;
    int x, y, z;
    void SetSource(const ShaderSource* source);
};
// Copies source x/y/z into this state, then clears flags 0x400, 0x800 and 0x1000 on the controller, zeroing its associatedValue when each was set.
// @fnv 0x00bd5dd0
void ShaderState::SetSource(const ShaderSource* source)
{
    if (source)
    {
        x = source->x;
        y = source->y;
        z = source->z;
    }
    ShaderSourceRecord* state = controller;
    if (state->flags & 0x400)
        state->associatedValue = 0;
    *reinterpret_cast<volatile unsigned int*>(&state->flags) &= ~0x400u;
    state = controller;
    if (state->flags & 0x800)
        state->associatedValue = 0;
    *reinterpret_cast<volatile unsigned int*>(&state->flags) &= ~0x800u;
    state = controller;
    if (state->flags & 0x1000)
        state->associatedValue = 0;
    *reinterpret_cast<volatile unsigned int*>(&state->flags) &= ~0x1000u;
}

class ImageSpaceEffect
{
  public:
    ImageSpaceEffect();
    virtual ~ImageSpaceEffect();
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
};

template <class T> class ISMallocIface6ec0
{
  public:
    static T* Allocate(unsigned int auiCount);
};



template <class T, class TAlloc>
inline NiTArray<T, TAlloc>::NiTArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
{
    m_usMaxSize = (unsigned short)uiMaxSize;
    m_usGrowBy = (unsigned short)uiGrowBy;
    m_usSize = 0;
    m_usESize = 0;

    if (m_usMaxSize > 0)
        m_pBase = TAlloc::Allocate(m_usMaxSize);
    else
        m_pBase = 0;
}

template <class T> class ISTPrimitiveArray6ec0 : public NiTArray<T, ISMallocIface6ec0<T> >
{
  public:
    ISTPrimitiveArray6ec0(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
        : NiTArray<T, ISMallocIface6ec0<T> >(uiMaxSize, uiGrowBy)
    {}
};

class FUN_00bd6ec0 : public ImageSpaceEffect
{
  public:
    FUN_00bd6ec0();
    virtual ~FUN_00bd6ec0();
    ISTPrimitiveArray6ec0<void*> m_kArray;
};

// Constructs the effect, default-initialising its m_kArray member.
// @fnv 0x00bd6ec0
FUN_00bd6ec0::FUN_00bd6ec0()
{}

extern int DAT_010bc560;

struct TextureManager_9160
{
    void BSTextureManager_ReturnRenderedTexture(int texture);
};
extern int DAT_011f91a8;

struct TextureResource_9160
{
    virtual void Release(int releaseFlag);
};
struct TextureList_9160
{
    int m_version;
    TextureResource_9160** m_data;
    void FUN_00ba3aa0(unsigned int index, TextureResource_9160*& value);
};
struct TextureWrapper_9160
{
    int ImageSpaceTexture_GetTexture();
    int ImageSpaceTexture_GetRenderedTexture();
    void ImageSpaceTexture_ClearTexture();
    void FUN_00ba3a00();
    ~TextureWrapper_9160()
    {
        FUN_00ba3a00();
    }
};
struct __declspec(novtable) Base_9160
{
    virtual ~Base_9160()
    {
        FUN_00ba3d30();
    }
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    TextureList_9160 m_ppData;
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
    void FUN_00ba3d30();
};
struct FUN_00bd9160 : Base_9160
{
    TextureWrapper_9160 m_texture;
    ~FUN_00bd9160();
};
// @fnv 0x00bd9160
FUN_00bd9160::~FUN_00bd9160()
{
    if (m_ppData.m_data[0])
    {
        TextureResource_9160* entry = m_ppData.m_data[0];
        if (entry)
            entry->Release(1);
        TextureResource_9160* empty = 0;
        m_ppData.FUN_00ba3aa0(0, empty);
    }
    if (m_texture.ImageSpaceTexture_GetTexture())
    {
        TextureManager_9160* manager = reinterpret_cast<TextureManager_9160*>(DAT_011f91a8);
        manager->BSTextureManager_ReturnRenderedTexture(m_texture.ImageSpaceTexture_GetRenderedTexture());
        m_texture.ImageSpaceTexture_ClearTexture();
    }
}

struct ShadowSceneLight;
// Exe 0x00bde170: unit-local ShaderPassList view; declarations and layout are preserved.
struct BlkShaderPassListView
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void __thiscall FUN_00ba9ee0(NiGeometry* geometry, unsigned short pass, bool enabled, unsigned char lightCount,
                                 ShadowSceneLight* light0, ShadowSceneLight* light1, ShadowSceneLight* light2,
                                 ShadowSceneLight* light3);
};
struct ShaderPassController
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44;
    BlkShaderPassListView* passes;
    void __thiscall SetPassEnabled(NiGeometry* geometry, bool alternate, bool enabled);
};
// If the first pass has no unk10 set, applies pass 0x1ee when enabled, else 0x1ec or 0x1ed depending on alternate.
// @fnv 0x00bde170
void ShaderPassController::SetPassEnabled(NiGeometry* geometry, bool alternate, bool enabled)
{
    BlkShaderPassListView* pPass = passes;
    if (pPass->unk10 != 0)
        return;
    if (enabled)
        pPass->FUN_00ba9ee0(geometry, 0x1ee, true, 0, 0, 0, 0, 0);
    else if (!alternate)
        pPass->FUN_00ba9ee0(geometry, 0x1ec, true, 0, 0, 0, 0, 0);
    else
        pPass->FUN_00ba9ee0(geometry, 0x1ed, true, 0, 0, 0, 0, 0);
}

extern float DAT_010ba600;
extern float DAT_01016410;

class FUN_00aa13e0
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
};

class FUN_00bc29e0Tail
{
  public:
    FUN_00bc29e0Tail()
    {
        m_fB4 = DAT_01016410;
    }
    unsigned char m_bAC;
    unsigned char m_bAD;
    float m_fB0;
    float m_fB4;
};

class FUN_00bc29e0 : public NiSortAdjustNode, public FUN_00bc29e0Tail
{
  public:
    FUN_00bc29e0() : NiSortAdjustNode(0), FUN_00bc29e0Tail()
    {
        m_fB0 = DAT_010ba600;
        m_bAD = 0;
        m_bAC = 0;
    }
    virtual ~FUN_00bc29e0();
};

class OwnerBC2A
{
  public:
    void FUN_00a5dc80(NiSortAdjustNode* pkNode, int iArg);
    FUN_00bc29e0* CreateNode(int iArg);
};

// Allocates and constructs a FUN_00bc29e0 node, passes it and iArg to FUN_00a5dc80, and returns the node.
// @fnv 0x00bc2a30
FUN_00bc29e0* OwnerBC2A::CreateNode(int iArg)
{
    FUN_00bc29e0* pkNode = new FUN_00bc29e0();
    FUN_00a5dc80(pkNode, iArg);
    return pkNode;
}

class hkSlotABCE8
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5C();
    virtual void unk60();
    virtual void unk64();
    virtual void unk68();
    virtual void unk6C();
    virtual void unk70();
    virtual void unk74();
    virtual void unk78();
    virtual void unk7C();
    virtual void unk80();
    virtual void unk84();
    virtual void unk88();
    virtual void unk8C();
    virtual void unk90();
    virtual void unk94();
    virtual void unk98();
    virtual void unk9C();
    virtual void update();
};

class hkSlotBBCE8
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5C();
    virtual void unk60();
    virtual void unk64();
    virtual void unk68();
    virtual void unk6C();
    virtual void unk70();
    virtual void unk74();
    virtual void unk78();
    virtual void unk7C();
    virtual void unk80();
    virtual void unk84();
    virtual void reset();
};

class hkBaseBCE8
{
  public:
    void ShadowLightShader_RecreateRendererData();
};

class hkObjBCE8 : public hkBaseBCE8
{
  public:
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned int unknown74;
    unsigned int unknown78;
    unsigned int unknown7c;
    unsigned int unknown80;
    unsigned int unknown84;
    unsigned int unknown88;
    hkSlotABCE8* m_kPointA[26];
    hkSlotBBCE8* m_kPointB[13];

    void SkinShader_RecreateRendererData();
};

// @fnv 0x00bce8f0
// src: COMMUNITY 0x00bce8f0
void hkObjBCE8::SkinShader_RecreateRendererData()
{
    for (int i = 0; i < 26; i++)
    {
        hkSlotABCE8* object = m_kPointA[i];
        if (object)
            object->update();
    }
    for (int i = 0; i < 13; i++)
    {
        hkSlotBBCE8* object = m_kPointB[i];
        if (object)
            object->reset();
    }
    ShadowLightShader_RecreateRendererData();
}

void* __cdecl FUN_00ec61c0(void*, int, unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern int DAT_011f91c0;
extern const char DAT_010bb95c;
extern const char DAT_010a93e4;
extern const char DAT_010aeb34;
extern const char DAT_010aeb54;
extern const char DAT_010aeb70;
extern const char DAT_010aeb8c;
extern const char DAT_010aeb98;
extern const char DAT_010aeba0;
extern const char DAT_010aebf4;
extern const char DAT_010aec10;
extern const char DAT_010aed54;
void __cdecl FUN_00be0c00(const char*, char*);
int __cdecl BSsprintf(char*, unsigned int, const char*, ...);
struct ShaderTail
{
    const char* arg12;
    const char* arg13;
    const char* arg14;
    const char* arg15;
    const char* arg16;
    const char* arg17;
};
struct ShaderEntry
{
    const char* filename;
    const char* arg00;
    const char* arg01;
    const char* arg02;
    const char* arg03;
    const char* arg04;
    const char* arg05;
    const char* arg06;
    const char* arg07;
    const char* arg08;
    const char* arg09;
    const char* arg10;
    const char* arg11;
    ShaderTail tail;
};
struct ShaderManager
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
    StagingNiPointer<ShaderObject> m_programs[26];
    ShaderObject* FUN_00be0fe0(const char*, const char* const*, const char*, const char*);
    void InitShaderPrograms();
};
// Builds a table of 26 ShaderEntry records and, when DAT_011f91c0 >= 2, creates m_programs entries via FUN_00be0fe0.
// @fnv 0x00bce950
void ShaderManager::InitShaderPrograms()
{
    ShaderEntry entries[26];
    // Shader variant 0
    entries[0].filename = &DAT_010aebf4;
    entries[0].arg00 = &DAT_010aed54;
    entries[0].arg01 = &DAT_01011584;
    entries[0].arg02 = 0;
    FUN_00ec61c0(&entries[0].arg03, 0, 60);
    // Shader variant 1
    entries[1].filename = &DAT_010aebf4;
    entries[1].arg00 = &DAT_010aec10;
    entries[1].arg01 = &DAT_01011584;
    entries[1].arg02 = &DAT_010aed54;
    entries[1].arg03 = &DAT_01011584;
    entries[1].arg04 = 0;
    FUN_00ec61c0(&entries[1].arg05, 0, 52);
    // Shader variant 2
    entries[2].filename = &DAT_010aebf4;
    entries[2].arg00 = &DAT_010aed54;
    entries[2].arg01 = &DAT_01011584;
    entries[2].arg02 = &DAT_010aeba0;
    entries[2].arg03 = &DAT_01011584;
    entries[2].arg04 = 0;
    FUN_00ec61c0(&entries[2].arg05, 0, 52);
    // Shader variant 3
    entries[3].filename = &DAT_010aebf4;
    entries[3].arg00 = &DAT_010aec10;
    entries[3].arg01 = &DAT_01011584;
    entries[3].arg02 = &DAT_010aed54;
    entries[3].arg03 = &DAT_01011584;
    entries[3].arg04 = &DAT_010aeba0;
    entries[3].arg05 = &DAT_01011584;
    entries[3].arg06 = 0;
    FUN_00ec61c0(&entries[3].arg07, 0, 44);
    // Shader variant 4
    entries[4].filename = &DAT_010aebf4;
    entries[4].arg00 = &DAT_010aeb98;
    entries[4].arg01 = &DAT_01063f3c;
    entries[4].arg02 = &DAT_010aed54;
    entries[4].arg03 = &DAT_01011584;
    entries[4].arg04 = 0;
    FUN_00ec61c0(&entries[4].arg05, 0, 52);
    // Shader variant 5
    entries[5].filename = &DAT_010aebf4;
    entries[5].arg00 = &DAT_010aec10;
    entries[5].arg01 = &DAT_01011584;
    entries[5].arg02 = &DAT_010aeb98;
    entries[5].arg03 = &DAT_01063f3c;
    entries[5].arg04 = &DAT_010aed54;
    entries[5].arg05 = &DAT_01011584;
    entries[5].arg06 = 0;
    FUN_00ec61c0(&entries[5].arg07, 0, 44);
    // Shader variant 6
    entries[6].filename = &DAT_010aebf4;
    entries[6].arg00 = &DAT_010aeb98;
    entries[6].arg01 = &DAT_01063f3c;
    entries[6].arg02 = &DAT_010aed54;
    entries[6].arg03 = &DAT_01011584;
    entries[6].arg04 = &DAT_010aeba0;
    entries[6].arg05 = &DAT_01011584;
    entries[6].arg06 = 0;
    FUN_00ec61c0(&entries[6].arg07, 0, 44);
    // Shader variant 7
    entries[7].filename = &DAT_010aebf4;
    entries[7].arg00 = &DAT_010aec10;
    entries[7].arg01 = &DAT_01011584;
    entries[7].arg02 = &DAT_010aeb98;
    entries[7].arg03 = &DAT_01063f3c;
    entries[7].arg04 = &DAT_010aed54;
    entries[7].arg05 = &DAT_01011584;
    entries[7].arg06 = &DAT_010aeba0;
    entries[7].arg07 = &DAT_01011584;
    entries[7].arg08 = 0;
    entries[7].arg09 = 0;
    entries[7].arg10 = 0;
    entries[7].arg11 = 0;
    entries[7].tail = ShaderTail();
    // Shader variant 8
    entries[8].filename = &DAT_010aeb54;
    entries[8].arg00 = &DAT_010aeb98;
    entries[8].arg01 = &DAT_01063f3c;
    entries[8].arg02 = &DAT_010aed54;
    entries[8].arg03 = &DAT_01011584;
    entries[8].arg04 = 0;
    FUN_00ec61c0(&entries[8].arg05, 0, 52);
    // Shader variant 9
    entries[9].filename = &DAT_010aeb54;
    entries[9].arg00 = &DAT_010aec10;
    entries[9].arg01 = &DAT_01011584;
    entries[9].arg02 = &DAT_010aeb98;
    entries[9].arg03 = &DAT_01063f3c;
    entries[9].arg04 = &DAT_010aed54;
    entries[9].arg05 = &DAT_01011584;
    entries[9].arg06 = 0;
    FUN_00ec61c0(&entries[9].arg07, 0, 44);
    // Shader variant 10
    entries[10].filename = &DAT_010aeb54;
    entries[10].arg00 = &DAT_010aeb98;
    entries[10].arg01 = &DAT_01063f3c;
    entries[10].arg02 = &DAT_010aed54;
    entries[10].arg03 = &DAT_01011584;
    entries[10].arg04 = &DAT_010aeba0;
    entries[10].arg05 = &DAT_01011584;
    entries[10].arg06 = 0;
    FUN_00ec61c0(&entries[10].arg07, 0, 44);
    // Shader variant 11
    entries[11].filename = &DAT_010aeb54;
    entries[11].arg00 = &DAT_010aec10;
    entries[11].arg01 = &DAT_01011584;
    entries[11].arg02 = &DAT_010aeb98;
    entries[11].arg03 = &DAT_01063f3c;
    entries[11].arg04 = &DAT_010aed54;
    entries[11].arg05 = &DAT_01011584;
    entries[11].arg06 = &DAT_010aeba0;
    entries[11].arg07 = &DAT_01011584;
    entries[11].arg08 = 0;
    entries[11].arg09 = 0;
    entries[11].arg10 = 0;
    entries[11].arg11 = 0;
    entries[11].tail = ShaderTail();
    // Shader variant 12
    entries[12].filename = &DAT_010aeb54;
    entries[12].arg00 = &DAT_010aeb98;
    entries[12].arg01 = &DAT_01063f30;
    entries[12].arg02 = &DAT_010aed54;
    entries[12].arg03 = &DAT_01011584;
    entries[12].arg04 = 0;
    FUN_00ec61c0(&entries[12].arg05, 0, 52);
    // Shader variant 13
    entries[13].filename = &DAT_010aeb54;
    entries[13].arg00 = &DAT_010aec10;
    entries[13].arg01 = &DAT_01011584;
    entries[13].arg02 = &DAT_010aeb98;
    entries[13].arg03 = &DAT_01063f30;
    entries[13].arg04 = &DAT_010aed54;
    entries[13].arg05 = &DAT_01011584;
    entries[13].arg06 = 0;
    FUN_00ec61c0(&entries[13].arg07, 0, 44);
    // Shader variant 14
    entries[14].filename = &DAT_010aeb54;
    entries[14].arg00 = &DAT_010aeb98;
    entries[14].arg01 = &DAT_01063f30;
    entries[14].arg02 = &DAT_010aed54;
    entries[14].arg03 = &DAT_01011584;
    entries[14].arg04 = &DAT_010aeba0;
    entries[14].arg05 = &DAT_01011584;
    entries[14].arg06 = 0;
    FUN_00ec61c0(&entries[14].arg07, 0, 44);
    // Shader variant 15
    entries[15].filename = &DAT_010aeb54;
    entries[15].arg00 = &DAT_010aec10;
    entries[15].arg01 = &DAT_01011584;
    entries[15].arg02 = &DAT_010aeb98;
    entries[15].arg03 = &DAT_01063f30;
    entries[15].arg04 = &DAT_010aed54;
    entries[15].arg05 = &DAT_01011584;
    entries[15].arg06 = &DAT_010aeba0;
    entries[15].arg07 = &DAT_01011584;
    entries[15].arg08 = 0;
    entries[15].arg09 = 0;
    entries[15].arg10 = 0;
    entries[15].arg11 = 0;
    entries[15].tail = ShaderTail();
    // Shader variant 16
    entries[16].filename = &DAT_010aeb34;
    entries[16].arg00 = &DAT_010aeb98;
    entries[16].arg01 = &DAT_01063f3c;
    entries[16].arg02 = &DAT_010aed54;
    entries[16].arg03 = &DAT_01011584;
    entries[16].arg04 = 0;
    FUN_00ec61c0(&entries[16].arg05, 0, 52);
    // Shader variant 17
    entries[17].filename = &DAT_010aeb34;
    entries[17].arg00 = &DAT_010aeb98;
    entries[17].arg01 = &DAT_01063f3c;
    entries[17].arg02 = &DAT_010aec10;
    entries[17].arg03 = &DAT_01011584;
    entries[17].arg04 = &DAT_010aed54;
    entries[17].arg05 = &DAT_01011584;
    entries[17].arg06 = 0;
    FUN_00ec61c0(&entries[17].arg07, 0, 44);
    // Shader variant 18
    entries[18].filename = &DAT_010aeb34;
    entries[18].arg00 = &DAT_010aeb98;
    entries[18].arg01 = &DAT_01063f30;
    entries[18].arg02 = &DAT_010aed54;
    entries[18].arg03 = &DAT_01011584;
    entries[18].arg04 = 0;
    FUN_00ec61c0(&entries[18].arg05, 0, 52);
    // Shader variant 19
    entries[19].filename = &DAT_010aeb34;
    entries[19].arg00 = &DAT_010aeb98;
    entries[19].arg01 = &DAT_01063f30;
    entries[19].arg02 = &DAT_010aec10;
    entries[19].arg03 = &DAT_01011584;
    entries[19].arg04 = &DAT_010aed54;
    entries[19].arg05 = &DAT_01011584;
    entries[19].arg06 = 0;
    FUN_00ec61c0(&entries[19].arg07, 0, 44);
    // Shader variant 20
    entries[20].filename = &DAT_010aeb70;
    entries[20].arg00 = &DAT_010aeb98;
    entries[20].arg01 = &DAT_01063ee8;
    entries[20].arg02 = &DAT_010aed54;
    entries[20].arg03 = &DAT_01011584;
    entries[20].arg04 = 0;
    FUN_00ec61c0(&entries[20].arg05, 0, 52);
    // Shader variant 21
    entries[21].filename = &DAT_010aeb70;
    entries[21].arg00 = &DAT_010aeb98;
    entries[21].arg01 = &DAT_01063ee8;
    entries[21].arg02 = &DAT_010aec10;
    entries[21].arg03 = &DAT_01011584;
    entries[21].arg04 = &DAT_010aed54;
    entries[21].arg05 = 0;
    entries[21].arg06 = 0;
    FUN_00ec61c0(&entries[21].arg07, 0, 44);
    // Shader variant 22
    entries[22].filename = &DAT_010aeb70;
    entries[22].arg00 = &DAT_010aeb98;
    entries[22].arg01 = &DAT_01063f24;
    entries[22].arg02 = &DAT_010aed54;
    entries[22].arg03 = &DAT_01011584;
    entries[22].arg04 = 0;
    FUN_00ec61c0(&entries[22].arg05, 0, 52);
    // Shader variant 23
    entries[23].filename = &DAT_010aeb70;
    entries[23].arg00 = &DAT_010aeb98;
    entries[23].arg01 = &DAT_01063f24;
    entries[23].arg02 = &DAT_010aec10;
    entries[23].arg03 = &DAT_01011584;
    entries[23].arg04 = &DAT_010aed54;
    entries[23].arg05 = 0;
    entries[23].arg06 = 0;
    FUN_00ec61c0(&entries[23].arg07, 0, 44);
    // Shader variant 24
    entries[24].filename = &DAT_010aeb70;
    entries[24].arg00 = &DAT_010aeb8c;
    entries[24].arg01 = &DAT_01011584;
    entries[24].arg02 = &DAT_010aeb98;
    entries[24].arg03 = &DAT_01063f24;
    entries[24].arg04 = &DAT_010aed54;
    entries[24].arg05 = 0;
    entries[24].arg06 = 0;
    FUN_00ec61c0(&entries[24].arg07, 0, 44);
    // Shader variant 25
    entries[25].filename = &DAT_010aeb70;
    entries[25].arg00 = &DAT_010aeb8c;
    entries[25].arg01 = &DAT_01011584;
    entries[25].arg02 = &DAT_010aeb98;
    entries[25].arg03 = &DAT_01063f24;
    entries[25].arg04 = &DAT_010aec10;
    entries[25].arg05 = &DAT_01011584;
    entries[25].arg06 = &DAT_010aed54;
    entries[25].arg07 = 0;
    entries[25].arg08 = 0;
    entries[25].arg09 = 0;
    entries[25].arg10 = 0;
    entries[25].arg11 = 0;
    entries[25].tail = ShaderTail();
    if (DAT_011f91c0 >= 2)
    {
        char name[260];
        char path[260];
        for (int i = 0; i < 26; ++i)
        {
            const ShaderEntry& entry = entries[i];
            if (entry.filename)
            {
                FUN_00be0c00(entry.filename, path);
                BSsprintf(name, 260, &DAT_010bb95c, i);
                m_programs[i] = FUN_00be0fe0(path, &entry.arg00, &DAT_010a93e4, name);
            }
        }
    }
}

class PropBD3F
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C(void* pObj);

    char unk04[0x18];
    int m_iShaderType;
    char unk20[0x38];
    int m_i58;
};

class ObjBD3F
{
  public:
    PropBD3F* FUN_00a59d30(unsigned int uiType);
};

// Gets the type-3 property of pkObj, uses it only if m_iShaderType is 10, sets m_i58 to 4, calls vf9C(pkObj) and always returns true.
// @fnv 0x00bd3fc0
// src: COMMUNITY 0x00bd3fc0
bool __stdcall SpeedTreeBranchShader_SetupGeometry(ObjBD3F* pkObj)
{
    PropBD3F* pkProp = pkObj->FUN_00a59d30(3);
    PropBD3F* pkShader = (pkProp ? pkProp->m_iShaderType == 10 : false) ? pkProp : 0;
    pkShader->m_i58 = 4;
    pkShader->vf9C(pkObj);
    return true;
}

inline void NiCamera::UpdateViewFrustum(const NiFrustum& frustum)
{
    m_kViewFrustum = frustum;
}

extern "C" double __cdecl tan(double);
inline float tanf(float _X)
{
    return (float)tan((double)_X);
}

extern float g_011c7b14_arg1;



class FUN_00bd8290 : public NiCamera
{
  public:
    int m_114;
    AtomicNiPointer<NiRefObject> m_spArr[6];
    AtomicNiPointer<NiRefObject> m_sp130;
    int m_134;
    AtomicNiPointer<NiRefObject> m_sp138;
    AtomicNiPointer<NiRefObject> m_sp13c;

    FUN_00bd8290(int iArg);
    virtual ~FUN_00bd8290();
};

// Stores iArg in m_114, nulls m_spArr/m_sp130/m_sp138, sets a tan(pi/4) perspective frustum via UpdateViewFrustum, and creates a BSShaderAccumulator in m_sp13c.
// @fnv 0x00bd8290
FUN_00bd8290::FUN_00bd8290(int iArg)
{
    m_114 = iArg;
    for (int i = 0; i < 6; i++)
    {
        m_spArr[i] = 0;
    }
    m_sp130 = 0;
    m_sp138 = 0;

    NiFrustum kFrustum;
    kFrustum.Init(false);
    kFrustum.m_bOrthographic = false;
    double dTan = tanf(0.7853982f);
    float fTan = (float)dTan;
    kFrustum.m_fLeftBound = -fTan;
    kFrustum.m_fRightBound = fTan;
    kFrustum.m_fTopBound = fTan;
    kFrustum.m_fBottomBound = -fTan;
    kFrustum.m_fNearPlane = 1.0f;
    kFrustum.m_fFarPlane = g_011c7b14_arg1;
    UpdateViewFrustum(kFrustum);

    m_sp13c = new BSShaderAccumulator((BSShaderManager::BATCHRENDERER_CREATION_MODE)0x63, 1, 0x2f7);
}

struct ShadowSceneLight;

extern SelectColor DAT_011f4998;
extern int DAT_011f91c0;
extern unsigned int DAT_011ad828;
extern unsigned char DAT_011f91a7;

struct PassElem
{
    int unk00;
    int unk04;
    short unk08;
    unsigned char unk0a;
    unsigned char m_0b;
};

struct PassSinkBdaf10
{
    int unk00;
    PassElem** m_04;
    int unk08;
    int unk0c;
    int m_10;
    void __thiscall FUN_00ba9ee0(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*,
                                 ShadowSceneLight*, ShadowSceneLight*);
};

struct GeomInfo
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
    int* m_ac;
    int unk_b0;
    int* m_b4;
};

struct F8Obj
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
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    SelectColor m_d4;
};

struct IterObj
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
    F8Obj* m_f8;
};



struct ShaderBdaf10
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
    PassArray9840* m_3c;
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
    int unkc4;
    unsigned short m_c8;
    short unk_ca;
    IterObj* __thiscall BSShaderLightingProperty_GetFirstActiveNonShadowLight(void*);
    IterObj* __thiscall BSShaderLightingProperty_GetNextActiveNonShadowLight(void*);
    void __thiscall EmitShadowPasses(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count,
                                     unsigned char type, bool* out, bool flag6);
};

// Emits shadow rendering passes for geom and light into m_3c, or increments *count when type is not 1.
// @fnv 0x00bdaf10
void __thiscall ShaderBdaf10::EmitShadowPasses(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count,
                                               unsigned char type, bool* out, bool flag6)
{
    GeomInfo* info = geom->FUN_00a59d30(3);
    bool* pOut = out;
    bool flag = DAT_011f91c0 <= 1;
    unsigned short n = (m_c8 < DAT_011ad828) ? m_c8 : DAT_011ad828;
    if (DAT_011f91a7)
    {
        if (type == 1)
            m_3c->FUN_00ba9ee0(geom, 0x93, *pOut, 0, 0, 0, 0, 0);
        else
            ++*count;
        *pOut = false;
        for (unsigned char i = 0; i < n; ++i)
        {
            if (info->m_ac[i + 1] != 0)
            {
                if (type == 1)
                {
                    m_3c->FUN_00ba9ee0(geom, 0x1f2, *pOut, 0, 0, 0, 0, 0);
                    ((PassSinkBdaf10*)m_3c)->m_04[((PassSinkBdaf10*)m_3c)->m_10 - 1]->m_0b = i + 1;
                }
                else
                {
                    ++*count;
                }
            }
        }
        return;
    }
    if (!flag6)
    {
        if (type == 1)
            m_3c->FUN_00ba9ee0(geom, 0x93, *pOut, 1, light, 0, 0, 0);
        else
            ++*count;
    }
    else
    {
        if (type == 1)
            m_3c->FUN_00ba9ee0(geom, 0x94, *pOut, 1, light, 0, 0, 0);
        else
            ++*count;
    }
    *pOut = false;
    if (*info->m_b4 != 0)
    {
        if (type == 1)
            m_3c->FUN_00ba9ee0(geom, 0x1f1, false, 0, 0, 0, 0, 0);
        else
            ++*count;
    }
    if (flag)
    {
        void* cursor;
        IterObj* obj = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&cursor);
        while (obj)
        {
            if (!obj)
                break;
            SelectColor& col = obj->m_f8->m_d4;
            if (!(col.r == DAT_011f4998.r && col.g == DAT_011f4998.g && col.b == DAT_011f4998.b))
            {
                if (type == 1)
                    m_3c->FUN_00ba9ee0(geom, 0x1ef, *pOut, 1, (ShadowSceneLight*)obj, 0, 0, 0);
                else
                    ++*count;
            }
            obj = BSShaderLightingProperty_GetNextActiveNonShadowLight(&cursor);
        }
    }
    for (unsigned char i = 0; i < n; ++i)
    {
        if (info->m_ac[i + 1] != 0)
        {
            if (!flag6)
            {
                if (type == 1)
                {
                    m_3c->FUN_00ba9ee0(geom, 0x1f2, *pOut, 1, light, 0, 0, 0);
                    ((PassSinkBdaf10*)m_3c)->m_04[((PassSinkBdaf10*)m_3c)->m_10 - 1]->m_0b = i + 1;
                }
                else
                {
                    ++*count;
                }
            }
            else
            {
                if (type == 1)
                {
                    m_3c->FUN_00ba9ee0(geom, 0x1f3, *pOut, 1, light, 0, 0, 0);
                    ((PassSinkBdaf10*)m_3c)->m_04[((PassSinkBdaf10*)m_3c)->m_10 - 1]->m_0b = i + 1;
                }
                else
                {
                    ++*count;
                }
            }
        }
    }
    for (unsigned char i = 0; i < n; ++i)
    {
        if (info->m_ac[i + 1] == 0)
            continue;
        if (info->m_b4[i + 1] != 0)
        {
            if (type == 1)
            {
                m_3c->FUN_00ba9ee0(geom, 0x1f4, *pOut, 0, 0, 0, 0, 0);
                ((PassSinkBdaf10*)m_3c)->m_04[((PassSinkBdaf10*)m_3c)->m_10 - 1]->m_0b = i + 1;
            }
            else
            {
                ++*count;
            }
        }
        if (flag)
        {
            void* cursor;
            IterObj* obj = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&cursor);
            while (obj)
            {
                if (!obj)
                    break;
                SelectColor& col = obj->m_f8->m_d4;
                if (!(col.r == DAT_011f4998.r && col.g == DAT_011f4998.g && col.b == DAT_011f4998.b))
                {
                    if (type == 1)
                    {
                        m_3c->FUN_00ba9ee0(geom, 0x1f5, *pOut, 1, (ShadowSceneLight*)obj, 0, 0, 0);
                        ((PassSinkBdaf10*)m_3c)->m_04[((PassSinkBdaf10*)m_3c)->m_10 - 1]->m_0b = i + 1;
                    }
                    else
                    {
                        ++*count;
                    }
                }
                obj = BSShaderLightingProperty_GetNextActiveNonShadowLight(&cursor);
            }
        }
    }
}

struct BDBF60_Shader
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
    BSShaderProperty::ShaderPassList* pPasses;
    int __thiscall BSShaderProperty_AddPass_2X_EnvMap(NiGeometry* geom, ShadowSceneLight* light, ShadowSceneLight* alternateLight,
                                unsigned short* count, unsigned char type, bool* enabled, bool sharedPass,
                                bool useAlternatePass, bool useSpecialPass);
};
// If type is 1, adds a pass to pPasses for geom, with the pass id and light chosen by the flags; otherwise increments *count.
// @fnv 0x00bdbf60
// src: COMMUNITY 0x00bdbf60
int __thiscall BDBF60_Shader::BSShaderProperty_AddPass_2X_EnvMap(NiGeometry* geom, ShadowSceneLight* light, ShadowSceneLight* alternateLight,
                                           unsigned short* count, unsigned char type, bool* enabled, bool sharedPass,
                                           bool useAlternatePass, bool useSpecialPass)
{
    if (!sharedPass)
    {
        if (type == 1)
        {
            unsigned short pass;
            if (useAlternatePass)
                pass = 0x24B;
            else if (!useSpecialPass)
                pass = 0x248;
            else
            {
                pPasses->Add(geom, 0x24A, *enabled, 0, 0, 0, 0, 0);
                return 0;
            }
            if (alternateLight)
            {
                pPasses->Add(geom, pass, *enabled, 1, alternateLight, 0, 0, 0);
            }
            else
            {
                pPasses->Add(geom, pass, *enabled, 1, light, 0, 0, 0);
            }
            return 0;
        }
    }
    else if (type == 1)
    {
        if (alternateLight)
        {
            pPasses->Add(geom, 0x249, *enabled, 1, alternateLight, 0, 0, 0);
            return 0;
        }
        pPasses->Add(geom, 0x249, *enabled, 1, light, 0, 0, 0);
        return 0;
    }
    ++*count;
    return 0;
}

struct ShadowSceneLight;
struct ShaderPassOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    BSShaderProperty::ShaderPassList* pPasses;
    typedef BSShaderProperty::ShaderPassList RPA;
    int __thiscall AddShadowPass(NiGeometry* geom, ShadowSceneLight* l0, ShadowSceneLight* l1, ShadowSceneLight* l2,
                                 unsigned short* count, bool flag, bool* out, bool b8, bool b9, bool b10, bool b11,
                                 bool b12, bool b13, bool b14);
};
extern "C" void _ReadWriteBarrier();
// Picks a pass id (233-250) from the b8-b14 flags and adds it to pPasses with the lights when flag is true, else increments *count; always clears *out.
// @fnv 0x00bdc530
int __thiscall ShaderPassOwner::AddShadowPass(NiGeometry* apGeometry, ShadowSceneLight* apLight0,
                                              ShadowSceneLight* apLight1, ShadowSceneLight* apLight2,
                                              unsigned short* count, bool flag, bool* out, bool b8, bool b9, bool b10,
                                              bool b11, bool b12, bool b13, bool b14)
{
    if (!b8)
    {
        if (!b9)
        {
            if (!b10)
            {
                if (!b13)
                {
                    if (!b12)
                    {
                        if (!b14)
                        {
                            if (flag == true)
                            {
                                pPasses->Add(apGeometry, 233, true, 3, apLight0, apLight1, apLight2, 0);
                            }
                            else
                                ++*count;
                        }
                        else
                        {
                            if (flag == true)
                            {
                                pPasses->Add(apGeometry, 241, true, 3, apLight0, apLight1, apLight2, 0);
                            }
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!b14)
                        {
                            if (flag == true)
                            {
                                pPasses->Add(apGeometry, 242, true, 3, apLight0, apLight1, apLight2, 0);
                            }
                            else
                                ++*count;
                        }
                        else
                        {
                            if (flag == true)
                            {
                                pPasses->Add(apGeometry, 250, true, 3, apLight0, apLight1, apLight2, 0);
                            }
                            else
                                ++*count;
                        }
                    }
                }
                else
                {
                    if (!b12)
                    {
                        if (flag == true)
                        {
                            pPasses->Add(apGeometry, 235, true, 3, apLight0, apLight1, apLight2, 0);
                        }
                        else
                            ++*count;
                    }
                    else
                    {
                        if (flag == true)
                        {
                            pPasses->Add(apGeometry, 244, true, 3, apLight0, apLight1, apLight2, 0);
                        }
                        else
                            ++*count;
                    }
                }
            }
            else
            {
                if (!b12)
                {
                    if (flag == true)
                    {
                        pPasses->Add(apGeometry, 237, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
                else
                {
                    if (flag == true)
                    {
                        pPasses->Add(apGeometry, 246, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
            }
        }
        else
        {
            if (b10)
                goto done;
            if (!b13)
            {
                if (!b12)
                {
                    if (flag == true)
                    {
                        pPasses->Add(apGeometry, 234, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
                else
                {
                    if (flag == true)
                    {
                        pPasses->Add(apGeometry, 243, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
            }
            else
            {
                if (!b12)
                {
                    if (flag == true)
                    {
                        pPasses->Add(apGeometry, 236, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
                else
                {
                    if (flag == true)
                    {
                        pPasses->Add(apGeometry, 245, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
            }
        }
    }
    else
    {
        if (!b9)
        {
            if (!b10)
            {
                if (b13)
                    goto done;
                if (!b12)
                {
                    if (flag == true)
                    {
                        pPasses->Add(apGeometry, 238, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
                else
                {
                    if (flag == true)
                    {
                        pPasses->Add(apGeometry, 247, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
            }
            else
            {
                if (!b12)
                {
                    if (flag == true)
                    {
                        pPasses->Add(apGeometry, 240, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
                else
                {
                    if (flag == true)
                    {
                        pPasses->Add(apGeometry, 249, true, 3, apLight0, apLight1, apLight2, 0);
                    }
                    else
                        ++*count;
                }
            }
        }
        else
        {
            if (b10)
                goto done;
            if (b13)
                goto done;
            if (!b12)
            {
                if (flag == true)
                {
                    pPasses->Add(apGeometry, 239, true, 3, apLight0, apLight1, apLight2, 0);
                }
                else
                    ++*count;
            }
            else
            {
                if (flag == true)
                {
                    pPasses->Add(apGeometry, 248, true, 3, apLight0, apLight1, apLight2, 0);
                }
                else
                    ++*count;
            }
        }
    }
done:
    *out = false;
    return 0;
}

// FUN_00bc2660: thiscall, /MT /O2 /GS /EHsc /Gy, 2 float stack args, returns void
extern const double DAT_01012060;
float __cdecl FUN_00ec9e10(double x);
int __cdecl FUN_00ec62c0();

class FUN_00bc2660_cls
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    float m_070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    float m_084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    int m_140;
    float m_144;
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
    float m_180;
    int unk184;
    int m_188;
    void BoltShaderProperty_ExtendSegments(int n);
    void BoltShaderProperty_ExtendBolt(float a1, float a2);
};

// Adds a1 to m_070, advances m_084 toward a2 in whole m_144 steps, adds the step count to m_188 and stores a clamped remainder in m_180.
// @fnv 0x00bc2660
// src: COMMUNITY 0x00bc2660
void FUN_00bc2660_cls::BoltShaderProperty_ExtendBolt(float a1, float a2)
{
    m_070 = m_070 + a1;
    float t1 = a2 - m_084;
    float x = t1 / m_144;
    volatile float t3v = FUN_00ec9e10(x);
    float t3 = t3v;
    m_084 = t3 * m_144 + m_084;
    int n = (int)t3;
    BoltShaderProperty_ExtendSegments(n);
    float t4 = m_084;
    float t5 = (float)m_140 * m_144;
    float t6 = (t4 < t5) ? t4 : t5;
    float t7 = m_084 - t6;
    float t8 = (t7 < DAT_01012060) ? 0.0f : t7;
    m_188 += n;
    m_180 = t8;
}

struct FloatTarget3080
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
    float m_fValue40;
    int m_iCount44;
};
struct FloatController3080 : ShaderRefractionController
{
    void BSMaterialEmittanceMultController_Update(NiUpdateData& kUpdateData);
};
// @fnv 0x00bc3080
// src: XBOX_PDB 0x00bc3080
void FloatController3080::BSMaterialEmittanceMultController_Update(NiUpdateData& kUpdateData)
{
    if (GetManagerControlled())
    {
        m_fControllerTime = g_fInvalidTimeBC3;
    }
    else if (AdvanceController(kUpdateData.fTime) &&
             (!m_spControllerInterpolator.m_pObject || !m_spControllerInterpolator.m_pObject->AlwaysUpdate()))
    {
        return;
    }

    if (m_spControllerInterpolator.m_pObject)
    {
        float fValue;
        if (m_spControllerInterpolator.m_pObject->UpdateFloat(m_fControllerTime, m_pkTarget, fValue))
        {
            FloatTarget3080* pkTarget = (FloatTarget3080*)m_pkTarget;
            pkTarget->m_fValue40 = fValue;
            pkTarget->m_iCount44++;
        }
    }
}

struct IntTargetBC3
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
};
struct IntControllerBC3 : ShaderRefractionController
{
    void BSRefractionFirePeriodController_Update(NiUpdateData& kUpdateData);
};
// Advances controller time unless manager-controlled, evaluates the interpolator, and stores its value rounded half away from zero in the target's unkE4.
// @fnv 0x00bc3290
// src: XBOX_PDB 0x00bc3290
void IntControllerBC3::BSRefractionFirePeriodController_Update(NiUpdateData& kUpdateData)
{
    if (GetManagerControlled())
    {
        m_fControllerTime = g_fInvalidTimeBC3;
    }
    else if (AdvanceController(kUpdateData.fTime) &&
             (!m_spControllerInterpolator.m_pObject || !m_spControllerInterpolator.m_pObject->AlwaysUpdate()))
    {
        return;
    }

    if (m_spControllerInterpolator.m_pObject)
    {
        float fValue;
        if (m_spControllerInterpolator.m_pObject->UpdateFloat(m_fControllerTime, m_pkTarget, fValue))
        {
            float fHalf = (fValue > 0.0f) ? 0.5f : -0.5f;
            fValue = fValue + fHalf;
            ((IntTargetBC3*)m_pkTarget)->unkE4 = (int)fValue;
        }
    }
}

namespace sbc8d40 {

class Source
{
  public:
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
    virtual void* GetTexture();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual int GetFlags();
};

struct Event
{
    int unk000;
    int unk004;
    int unk008;
    Source* m_pkSource;
};

struct Target
{
    int unk000;
    int unk004;
    void* m_pvTexture;

    void ApplyPairToState(int iFlags);
    void FUN_00e7eb00(int iArg);
};

struct TargetHolder
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    Target** m_ppkTarget;
};

extern TargetHolder* DAT_0126f74c;

// If the event's source has a texture, stores it in the target at *DAT_0126f74c->m_ppkTarget, calls ApplyPairToState with the source flags, then FUN_00e7eb00(0).
// @fnv 0x00bc8d40
void __stdcall OnTextureEvent(Event* pkEvent)
{
    Target* pkTarget = *DAT_0126f74c->m_ppkTarget;
    if (pkTarget)
    {
        Source* pkSource = pkEvent->m_pkSource;
        void* pvTexture = pkSource->GetTexture();
        if (pvTexture)
        {
            pkTarget->m_pvTexture = pvTexture;
            pkTarget->ApplyPairToState(pkSource->GetFlags());
            pkTarget->FUN_00e7eb00(0);
        }
    }
}

}

struct S_00bcc590_Foo
{
    void SetEntryField(int);
    void ShadowLightShader_SetProjectedShadowMaskMap(int);
    void SetPassValues(unsigned int);
    void ParallaxShader_SetupStaticTextures(unsigned int);
};
// Switches on value: some set SetEntryField/FUN_00b7c170 to 4/5, 5/6 or 6/7, a listed set does nothing, and the rest call SetPassValues(value).
// @fnv 0x00bcc590
// src: COMMUNITY 0x00bcc590
void S_00bcc590_Foo::ParallaxShader_SetupStaticTextures(unsigned int value)
{
    switch (value)
    {
    case 0x99:
    case 0x9a:
    case 0xaf:
    case 0xb0:
    case 0xda:
    case 0xec:
    case 0x101:
    case 0x103:
    case 0x119:
    case 0x11a:
    case 0x134:
    case 0x140:
    case 0x153:
    case 0x15c:
    case 0x168:
    case 0x16e:
    case 0x174:
        break;
    case 0x162:
        SetEntryField(4);
        ShadowLightShader_SetProjectedShadowMaskMap(5);
        break;
    case 0xe2:
    case 0xe3:
    case 0xf4:
    case 0xf5:
        SetEntryField(5);
        ShadowLightShader_SetProjectedShadowMaskMap(6);
        break;
    case 0xa4:
    case 0xa5:
    case 0xba:
    case 0xbb:
    case 0x10e:
    case 0x10f:
    case 0x124:
    case 0x125:
        SetEntryField(6);
        ShadowLightShader_SetProjectedShadowMaskMap(7);
        break;
    default:
        SetPassValues(value);
        break;
    }
}

struct ManagerBase
{
    void ShadowLightShader_RecreateRendererData();
};

namespace sbcc6f0 {

class PassA
{
  public:
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
    virtual void Reset();
};

class PassB
{
  public:
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
    virtual void Reset();
};

struct Manager : ManagerBase
{
    int unk000;
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
    PassA* m_apPassA[20];
    PassB* m_apPassB[33];

    void ResetAllPasses();
};

// Calls Reset on each non-null PassA and PassB in m_apPassA and m_apPassB, then calls FUN_00b71b90.
// @fnv 0x00bcc6f0
void Manager::ResetAllPasses()
{
    for (int i = 0; i < 20; i++)
    {
        PassA* pkPass = m_apPassA[i];
        if (pkPass)
            pkPass->Reset();
    }
    for (int i = 0; i < 33; i++)
    {
        PassB* pkPass = m_apPassB[i];
        if (pkPass)
            pkPass->Reset();
    }
    ShadowLightShader_RecreateRendererData();
}

}

class PassObject_ce40
{
  public:
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class PassPointer_ce40
{
  public:
    T* m_pObject;
    PassPointer_ce40<T>& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

// 0x00b55560 returns a shader; slot 60 is BSShader::SetRenderPass.
BSShader* __cdecl GetTechniqueShader(int);

extern int g_iCurrentPass_ce40;
extern int g_aiPassIndex_ce40[33];

class TechniqueShader_ce40
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    PassPointer_ce40<PassObject_ce40> m_pkTechniquePass;
    unsigned int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68;
    PassObject_ce40* m_pkDefaultPass;

    void SelectShaderProgram(unsigned int uiTechnique);
    void SetTechniquePass(unsigned int uiTechnique);
};

// @fnv 0x00bcce40
void TechniqueShader_ce40::SetTechniquePass(unsigned int uiTechnique)
{
    m_pkTechniquePass = m_pkDefaultPass;
    switch (uiTechnique)
    {
    case 0xd9:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[0];
        break;
    case 0xda:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[1];
        break;
    case 0xe2:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[2];
        break;
    case 0xe3:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[3];
        break;
    case 0xeb:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[4];
        break;
    case 0xec:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[5];
        break;
    case 0xf4:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[6];
        break;
    case 0xf5:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[7];
        break;
    case 0x99:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[17];
        break;
    case 0x9a:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[18];
        break;
    case 0xa4:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[19];
        break;
    case 0xa5:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[20];
        break;
    case 0xaf:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[21];
        break;
    case 0xb0:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[22];
        break;
    case 0xba:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[23];
        break;
    case 0xbb:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[24];
        break;
    case 1:
    case 2:
        SelectShaderProgram(uiTechnique);
        GetTechniqueShader(1)->SetRenderPass(uiTechnique);
        m_pkTechniquePass = m_pkDefaultPass;
        break;
    case 0x101:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[8];
        break;
    case 0x102:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[9];
        break;
    case 0x103:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[10];
        break;
    case 0x10e:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[11];
        break;
    case 0x10f:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[12];
        break;
    case 0x119:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[13];
        break;
    case 0x11a:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[14];
        break;
    case 0x124:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[15];
        break;
    case 0x125:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[16];
        break;
    case 0x134:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[25];
        break;
    case 0x140:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[26];
        break;
    case 0x153:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[27];
        break;
    case 0x15c:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[28];
        break;
    case 0x162:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[29];
        break;
    case 0x168:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[30];
        break;
    case 0x16e:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[31];
        break;
    case 0x174:
        g_iCurrentPass_ce40 = g_aiPassIndex_ce40[32];
        break;
    default:
        SelectShaderProgram(uiTechnique);
        GetTechniqueShader(1)->SetRenderPass(uiTechnique);
        break;
    }
}

struct ShaderPassSetup_bce800
{
    void SetVertexShaderSlot(int iSlot);
    void SetPixelShaderSlot(int iSlot);
    void SetupDefaultPass(unsigned int uiPass);
    void SkinShader_SetupStaticTextures(unsigned int uiPass);
};

// Sets vertex/pixel shader slots (5,6 or 6,7) for some pass ids, does nothing for other listed ids, and calls SetupDefaultPass for the rest.
// @fnv 0x00bce800
// src: COMMUNITY 0x00bce800
void ShaderPassSetup_bce800::SkinShader_SetupStaticTextures(unsigned int uiPass)
{
    switch (uiPass)
    {
    case 0xc5:
    case 0xc8:
    case 0xcc:
    case 0xcf:
    case 0xd3:
    case 0xd6:
    case 0xdb:
    case 0xde:
    case 0xed:
    case 0xf0:
    case 0x100:
    case 0x107:
    case 0x118:
    case 0x11e:
    case 0x133:
    case 0x136:
    case 0x13f:
    case 0x142:
        break;
    case 0xe4:
    case 0xe7:
    case 0xf6:
    case 0xf9:
        SetVertexShaderSlot(5);
        SetPixelShaderSlot(6);
        break;
    case 0x10d:
    case 0x113:
    case 0x123:
    case 0x129:
        SetVertexShaderSlot(6);
        SetPixelShaderSlot(7);
        break;
    default:
        SetupDefaultPass(uiPass);
        break;
    }
}

class PassObject_fd20
{
  public:
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class PassPointer_fd20
{
  public:
    T* m_pObject;
    PassPointer_fd20<T>& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    PassPointer_fd20<T>& operator=(const PassPointer_fd20<T>& kOther)
    {
        if (m_pObject != kOther.m_pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = kOther.m_pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};


class Program_fd20
{
  public:
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

extern int g_iCurrentPass_fd20;
extern int g_aiPassIndex_fd20[26];

class TechniqueShader_fd20
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    PassPointer_fd20<PassObject_fd20> m_pkTechniquePass;
    unsigned int unk2c;
    PassPointer_fd20<Program_fd20> m_spVertexProgram;
    PassPointer_fd20<Program_fd20> m_spPixelProgram;
    unsigned int unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    PassObject_fd20* m_pkPass6c;
    PassObject_fd20* m_pkPass70;
    unsigned int unk74, unk78;
    PassPointer_fd20<Program_fd20> m_spVertexProgram250;
    PassPointer_fd20<Program_fd20> m_spPixelProgram250;
    PassPointer_fd20<Program_fd20> m_spVertexProgramDefault;
    PassPointer_fd20<Program_fd20> m_spPixelProgramDefault;

    void SelectShaderProgram(unsigned int uiTechnique);
    void SkinShader_InitPass(unsigned int uiTechnique);
};

// Per technique id sets the current pass and technique pass, or selects a shader and renderer technique, then picks the 0x250 or default vertex/pixel programs.
// @fnv 0x00bcfd20
// src: COMMUNITY 0x00bcfd20
void TechniqueShader_fd20::SkinShader_InitPass(unsigned int uiTechnique)
{
    switch (uiTechnique)
    {
    case 0xdb:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[0];
        m_pkTechniquePass = m_pkPass6c;
        break;
    case 0xde:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[1];
        m_pkTechniquePass = m_pkPass70;
        break;
    case 0xe4:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[2];
        m_pkTechniquePass = m_pkPass6c;
        break;
    case 0xe7:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[3];
        m_pkTechniquePass = m_pkPass70;
        break;
    case 0xed:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[4];
        m_pkTechniquePass = m_pkPass6c;
        break;
    case 0xf0:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[5];
        m_pkTechniquePass = m_pkPass70;
        break;
    case 0xf6:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[6];
        m_pkTechniquePass = m_pkPass6c;
        break;
    case 0xf9:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[7];
        m_pkTechniquePass = m_pkPass70;
        break;
    case 0xc5:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[20];
        m_pkTechniquePass = m_pkPass6c;
        break;
    case 0xc8:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[21];
        m_pkTechniquePass = m_pkPass70;
        break;
    case 0xcc:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[22];
        m_pkTechniquePass = m_pkPass6c;
        break;
    case 0xcf:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[23];
        m_pkTechniquePass = m_pkPass70;
        break;
    case 0xd3:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[24];
        m_pkTechniquePass = m_pkPass6c;
        break;
    case 0xd6:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[25];
        m_pkTechniquePass = m_pkPass70;
        break;
    case 1:
    case 2:
        SelectShaderProgram(uiTechnique);
        GetTechniqueShader(1)->SetRenderPass(uiTechnique);
        m_pkTechniquePass = m_pkPass6c;
        break;
    case 3:
        SelectShaderProgram(uiTechnique);
        GetTechniqueShader(1)->SetRenderPass(uiTechnique);
        m_pkTechniquePass = m_pkPass70;
        break;
    case 0x100:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[8];
        m_pkTechniquePass = m_pkPass6c;
        break;
    case 0x107:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[9];
        m_pkTechniquePass = m_pkPass70;
        break;
    case 0x10d:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[10];
        m_pkTechniquePass = m_pkPass6c;
        break;
    case 0x113:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[11];
        m_pkTechniquePass = m_pkPass70;
        break;
    case 0x118:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[12];
        m_pkTechniquePass = m_pkPass6c;
        break;
    case 0x11e:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[13];
        m_pkTechniquePass = m_pkPass70;
        break;
    case 0x123:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[14];
        m_pkTechniquePass = m_pkPass6c;
        break;
    case 0x129:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[15];
        m_pkTechniquePass = m_pkPass70;
        break;
    case 0x133:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[16];
        m_pkTechniquePass = m_pkPass6c;
        break;
    case 0x136:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[17];
        m_pkTechniquePass = m_pkPass70;
        break;
    case 0x13f:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[18];
        m_pkTechniquePass = m_pkPass6c;
        break;
    case 0x142:
        g_iCurrentPass_fd20 = g_aiPassIndex_fd20[19];
        m_pkTechniquePass = m_pkPass70;
        break;
    default:
        SelectShaderProgram(uiTechnique);
        GetTechniqueShader(1)->SetRenderPass(uiTechnique);
        break;
    }
    if (uiTechnique == 0x250 || uiTechnique == 0x251)
    {
        m_spVertexProgram = m_spVertexProgram250;
        m_spPixelProgram = m_spPixelProgram250;
    }
    else
    {
        m_spVertexProgram = m_spVertexProgramDefault;
        m_spPixelProgram = m_spPixelProgramDefault;
    }
}

extern unsigned int DAT_011f91e4;
struct RenderArgument625
{
    int unk00;
    int unk04;
    int unk08;
    void* unk0c;
};
struct RenderShader625
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    void ShadowLightShader_SetDiffuseMap(void*, unsigned int, unsigned int);
    void ShadowLightShader_SetNormalMap(void*, unsigned int, unsigned int);
    void ShadowLightShader_SetGlowMap(void*, unsigned int, unsigned int, unsigned int);
    void ShadowLightShader_SetupGeometryTextures(RenderArgument625*);
    void SetShaderPasses(RenderArgument625*);
};
// @fnv 0x00bd02e0
void RenderShader625::SetShaderPasses(RenderArgument625* arg)
{
    void* pass = arg->unk0c;
    switch (DAT_011f91e4)
    {
    case 219:
    case 222:
    case 228:
    case 231:
    case 237:
    case 240:
    case 246:
    case 249:
        ShadowLightShader_SetDiffuseMap(pass, 0, 0);
        ShadowLightShader_SetNormalMap(pass, 1, 0);
        ShadowLightShader_SetGlowMap(pass, 3, 0, 1);
        break;
    case 197:
    case 200:
    case 204:
    case 207:
    case 211:
    case 214:
    case 256:
    case 263:
    case 269:
    case 275:
    case 280:
    case 286:
    case 291:
    case 297:
        ShadowLightShader_SetDiffuseMap(pass, 0, 0);
        ShadowLightShader_SetNormalMap(pass, 1, 0);
        ShadowLightShader_SetDiffuseMap(pass, 2, 1);
        ShadowLightShader_SetNormalMap(pass, 3, 1);
        ShadowLightShader_SetGlowMap(pass, 4, 0, 1);
        break;
    case 307:
    case 310:
    case 319:
    case 322:
        ShadowLightShader_SetNormalMap(pass, 0, 0);
        ShadowLightShader_SetGlowMap(pass, 4, 0, 1);
        break;
    default:
        ShadowLightShader_SetupGeometryTextures(arg);
        return;
    }
    v66();
}

extern NiCamera* DAT_011f917c;
extern float DAT_012023e0;
extern "C" NiPoint3 DAT_012004f0;
extern "C" float DAT_011f9410;
extern "C" float DAT_012003c4;
struct ShaderPair66
{
    void* field00;
    void* field04;
    Callee_00b8a790* first;
    Callee_00b8a790* second;
};
struct Shader66
{
    unsigned int field00, field04, field08, field0c, field10, field14, field18;
    ShaderPair66* shaders;
    unsigned int field20, field24, field28, field2c, field30, field34, field38;
    unsigned int field3c, field40, field44, field48, field4c, field50, field54;
    unsigned int field58, field5c, field60, field64;
    float center, radius, parameter;
    int mode;
    float distance;
    bool UpdateShaderParameters(int unused);
};

// Calls Run(0-2) on both shader entries from fields of DAT_011f917c and mode, Run(3) on the second if DAT_011f9410 > 0, and sets DAT_012003c4 to 3.0f.
// @fnv 0x00bd66c0
bool Shader66::UpdateShaderParameters(int unused)
{
    float nearClip = DAT_011f917c->m_kViewFrustum.m_fNearPlane;
    float farClip = DAT_011f917c->m_kViewFrustum.m_fFarPlane;
    float range = farClip - nearClip;
    float product = nearClip * farClip;
    float firstFlag = (mode == 1 || mode == 0) ? 1.0f : 0.0f;
    float secondFlag = (mode == 2 || mode == 0) ? 1.0f : 0.0f;
    Callee_00b8a790* shader = shaders->first;
    float low = center - radius;
    float high = radius + center;
    shader->Run(0, low, high, center, DAT_012023e0);
    shader->Run(1, parameter, firstFlag, secondFlag, 0.0f);
    shader->Run(2, -100000000.0f, nearClip, range, product);
    shader = shaders->second;
    shader->Run(0, low, high, center, DAT_012023e0);
    shader->Run(1, parameter, firstFlag, secondFlag, 0.0f);
    shader->Run(2, -100000000.0f, nearClip, range, product);
    NiPoint3 kUp;
    kUp.x = DAT_011f917c->m_kWorld.m_Rotate.m_pEntry[0][1];
    kUp.y = DAT_011f917c->m_kWorld.m_Rotate.m_pEntry[1][1];
    kUp.z = DAT_011f917c->m_kWorld.m_Rotate.m_pEntry[2][1];
    NiPoint3 kRight;
    kRight.x = DAT_011f917c->m_kWorld.m_Rotate.m_pEntry[0][2];
    kRight.y = DAT_011f917c->m_kWorld.m_Rotate.m_pEntry[1][2];
    kRight.z = DAT_011f917c->m_kWorld.m_Rotate.m_pEntry[2][2];
    NiPoint3 kPos = *(const NiPoint3*)&DAT_012004f0;
    float scale = DAT_011f9410;
    if (scale > 0.0f)
    {
        const float& ratio = distance / (30.0 * scale);
        shader->Run(3, kRight * kPos, -kUp * kPos, ratio, 0.0f);
    }
    DAT_012003c4 = 3.0f;
    return true;
}

struct Frustum_bd7620
{
    float l;
    float r;
    float t;
    float b;
    float n;
    float f;
    bool ortho;
};
struct Port_bd7620
{
    float l;
    float r;
    float t;
    float b;
};
// The camera path initializes time and the five update flags, leaving trailing padding untouched.
inline NiUpdateData::NiUpdateData(float time)
    : fTime(time), pad1(0), pad2(0), pad3(0), pad4(0), pad5(0)
{}
// NiDX9Renderer::vf99 is the camera setter; retain its six-argument ABI until the shared declaration is typed.
static __forceinline void SetRendererCamera(NiDX9Renderer* renderer, const NiPoint3& pos,
    const NiPoint3& dir, const NiPoint3& up, const NiPoint3& right,
    const Frustum_bd7620& frustum, const Port_bd7620& port)
{
    typedef void (__thiscall* CameraSetter)(NiDX9Renderer*, const NiPoint3&, const NiPoint3&,
        const NiPoint3&, const NiPoint3&, const Frustum_bd7620&, const Port_bd7620&);
    ((CameraSetter)(*(void***)renderer)[99])(renderer, pos, dir, up, right, frustum, port);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);

struct Culler_bd7620
{
    int unk00;
    int unk04;
    int unk08;
    void* m_pkAccumulationCamera;
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
    Culler_bd7620(void* vis);
    ~Culler_bd7620();
    void SetFrustum(const Frustum_bd7620* fr);
};
struct Scene_bd7620
{
    void Cull(Culler_bd7620* c);
};
struct Cam_bd7620 : NiCamera
{
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
    BSShaderAccumulator* m_p13c;
    void CullScene(Scene_bd7620* scene);
};

// Sets the renderer camera, runs the accumulation camera Begin/End, and culls the scene with a frustum culler.
// @fnv 0x00bd7620
void Cam_bd7620::CullScene(Scene_bd7620* scene)
{
    if (!scene)
        return;
    NiPoint3 kRight;
    kRight.x = m_kWorld.m_Rotate.m_pEntry[0][2];
    NiDX9Renderer* r = (NiDX9Renderer*)DAT_011f9508;
    int mode = r->m_eFrameState;
    kRight.y = m_kWorld.m_Rotate.m_pEntry[1][2];
    kRight.z = m_kWorld.m_Rotate.m_pEntry[2][2];
    NiPoint3 kUp;
    kUp.x = m_kWorld.m_Rotate.m_pEntry[0][1]; kUp.y = m_kWorld.m_Rotate.m_pEntry[1][1]; kUp.z = m_kWorld.m_Rotate.m_pEntry[2][1];
    NiPoint3 kWorldPosition;
    kWorldPosition.x = m_kWorld.m_Rotate.m_pEntry[0][0]; kWorldPosition.y = m_kWorld.m_Rotate.m_pEntry[1][0]; kWorldPosition.z = m_kWorld.m_Rotate.m_pEntry[2][0];
    if ((mode == 1 || mode == 2) && r->m_bRenderTargetGroupActive == 1)
        SetRendererCamera(r, m_kWorld.m_Translate, kWorldPosition, kUp, kRight, *(const Frustum_bd7620*)&m_kViewFrustum, *(const Port_bd7620*)&m_kPort);
    m_p13c->StartAccumulating((NiCamera*)this);
    BSShaderAccumulator* acc = m_p13c;
    acc->bAccumulate = true;
    Culler_bd7620 kCuller(0);
    NiUpdateData kData(0.0f);
    NiCamera::Update(kData);
    kCuller.m_pkAccumulationCamera = this;
    kCuller.SetFrustum(&*(const Frustum_bd7620*)&m_kViewFrustum);
    scene->Cull(&kCuller);
    m_p13c->FinishAccumulating();
    if (m_p13c->m_uiRefCount < 2)
        ((NiRefObject*)m_p13c)->IncrementReferenceCount();
}

struct Shader_00bd9770 : Shader9840
{
    int BSShaderProperty_AmbientDirAndPoint(NiGeometry* pkGeometry, ShadowSceneLight* pkLight0, ShadowSceneLight* pkLight1,
                     unsigned short* puiPassCount, unsigned char ucType, bool* pbEnabled, bool bFirst, bool bSecond);
};

// If ucType is 1, adds a pass for the two lights (id chosen by bFirst and bSecond); otherwise increments *puiPassCount; then clears *pbEnabled.
// @fnv 0x00bd9770
// src: COMMUNITY 0x00bd9770
int Shader_00bd9770::BSShaderProperty_AmbientDirAndPoint(NiGeometry* pkGeometry, ShadowSceneLight* pkLight0, ShadowSceneLight* pkLight1,
                                  unsigned short* puiPassCount, unsigned char ucType, bool* pbEnabled, bool bFirst,
                                  bool bSecond)
{
    if (!bFirst)
    {
        if (!bSecond)
        {
            if (ucType == 1)
            {
                passes->FUN_00ba9ee0(pkGeometry, 0x7c, true, 2, pkLight0, pkLight1, 0, 0);
            }
            else
            {
                ++*puiPassCount;
            }
        }
        else
        {
            if (ucType == 1)
            {
                passes->FUN_00ba9ee0(pkGeometry, 0x7e, true, 2, pkLight0, pkLight1, 0, 0);
            }
            else
            {
                ++*puiPassCount;
            }
        }
    }
    else
    {
        if (ucType == 1)
        {
            passes->FUN_00ba9ee0(pkGeometry, 0x7d, true, 2, pkLight0, pkLight1, 0, 0);
        }
        else
        {
            ++*puiPassCount;
        }
    }
    *pbEnabled = false;
    return 0;
}

struct Shader_00bd9f00 : Shader9840
{
    int BSShaderProperty_AddPass_ZOnly(NiGeometry* pkGeometry, unsigned short* puiPassCount, unsigned char ucType, bool* pbEnabled,
                     bool bFirst, bool bSecond);
};

// If ucType is 1 adds pass 3 (bFirst) or 1 or 2 (bSecond) via passes->FUN_00ba9ee0, else increments *puiPassCount; then clears *pbEnabled.
// @fnv 0x00bd9f00
// src: COMMUNITY 0x00bd9f00
int Shader_00bd9f00::BSShaderProperty_AddPass_ZOnly(NiGeometry* pkGeometry, unsigned short* puiPassCount, unsigned char ucType,
                                  bool* pbEnabled, bool bFirst, bool bSecond)
{
    if (bFirst)
    {
        if (ucType == 1)
        {
            passes->FUN_00ba9ee0(pkGeometry, 3, *pbEnabled, 0, 0, 0, 0, 0);
        }
        else
        {
            ++*puiPassCount;
        }
    }
    else
    {
        if (ucType == 1)
        {
            passes->FUN_00ba9ee0(pkGeometry, bSecond ? 2 : 1, *pbEnabled, 0, 0, 0, 0, 0);
        }
        else
        {
            ++*puiPassCount;
        }
    }
    *pbEnabled = false;
    return 0;
}

namespace fnv_00bc0c90 {
extern "C" double __cdecl FUN_00ec9e10(double);

struct Vec2A
{
    float x, y;
    Vec2A() : x(0.0f), y(0.0f)
    {}
    Vec2A(float _x, float _y) : x(_x), y(_y)
    {}
};


struct BoltAllocElem
{
    float x, y, z, w;
    static void* operator new[](unsigned int bytes)
    {
        return DAT_011f6238.Game_DoHeapAlloc(bytes);
    }
};

struct FUN_00bc0c90 : FUN_00be2200
{
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
    Vec2A pt1;
    Vec2A pt2;
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
    PassPtr pass;
    float f16C;
    float f170;
    float f174;
    float f178;
    float f17C;
    float f180;
    float f184;
    float f188;
    RefPtr first;
    RefPtr second;

    FUN_00bc0c90(CountedRef* source);
    virtual ~FUN_00bc0c90();
};

// Initializes mode, flags, and source, copies DAT_011a9be0 into f16C and f17C, and allocates a zeroed BoltAllocElem array sized from DAT_01201f50.
// @fnv 0x00bc0c90
FUN_00bc0c90::FUN_00bc0c90(CountedRef* apSource)
    : FUN_00be2200(), pt1(), pt2(), pass(), f16C(0.0f), f170(0.0f), f174(0.0f), f178(0.0f), f17C(0.0f), f180(0.0f),
      f184(0.0f), f188(0.0f), first(), second()
{
    mode = 0xf;
    flag24 = 1;
    flags = 0x242;
    pass.clear();
    source.assign(apSource);
    first.clear();
    second.clear();

    matrix[0] = 0.0f;
    *(NiColorA*)&pt1 = NiColorA(0.0f, 0.0f, 0.0f, 0.0f);
    *(NiColorA*)&f16C = *(NiColorA*)&DAT_011a9be0;
    *(NiColorA*)&f17C = *(NiColorA*)&DAT_011a9be0;

    if (!DAT_01201f50)
    {
        DAT_01201f50 = (DAT_011f91c0 < 2 ? 0 : 0xa0) + 0x4b;
    }
    float fVal = (float)DAT_01201f50 * 0.25;
    unsigned int count = (unsigned int)(float)FUN_00ec9e10(fVal);
    count *= 4;
    BoltAllocElem* p = new BoltAllocElem[count];
    *(void**)&value = p;
    fnv_zlib_memset(p, 0, count * sizeof(BoltAllocElem));
    fnv_zlib_memset(&unk128, 0, 0x40);
    fnv_zlib_memset(&matrix[1], 0, 0xa0);
}
}  // namespace fnv_00bc0c90

#include <string.h>
struct NLPt4
{
    float x, y, z, w;
    NLPt4()
    {}
    NLPt4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
    {}
};
struct Lighting30Packet4
{
    float x, y, z, w;
};
extern NLPt4 DAT_01202148;
extern NLPt4 DAT_01202158;
extern Lighting30Packet4 DAT_011a9bd0;
extern unsigned char DAT_011f91c4;
BSFogProperty* __cdecl BSShaderManager_GetFogProperty(int);
struct FogFlag
{
    int unk0;
    int unk4;
    bool enabled;
};
struct FogShader
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    FogFlag* fogRange;
    int unk174;
    FogFlag* fogColor;
    void SetFogMode(unsigned int mode);
};
// Enables fogRange and fogColor based on mode, then writes fog start, end, density, and color into DAT_01202148 and DAT_01202158 from the BSFogProperty.
// @fnv 0x00bc6de0
void FogShader::SetFogMode(unsigned int mode)
{
    if (mode >= 82 && mode <= 87)
        fogRange->enabled = true;
    else
        fogRange->enabled = false;
    if ((mode >= 74 && mode <= 81) || mode == 86 || mode == 87)
        fogColor->enabled = true;
    else
        fogColor->enabled = false;
    BSFogProperty* fog = BSShaderManager_GetFogProperty(DAT_011f91c4);
    if (fog)
    {
        float start = fog->nearDepth;
        float end = fog->farDepth;
        NiColor color = fog->color;
        float density = fog->density;
        if (end == 0.0f && start == 0.0f)
        {
            DAT_01202148 = NLPt4(500000.0f, 0.0f, density, 0.0f);
            memcpy(&DAT_01202158, &DAT_011a9bd0, sizeof(DAT_01202158));
        }
        else
        {
            DAT_01202148 = NLPt4(end, end - start, density, 0.0f);
            DAT_01202158 = NLPt4(color.r, color.g, color.b, 1.0f);
        }
    }
}

inline void BSShaderProperty::SetFlag(unsigned int mask, bool enabled)
{
    if (enabled)
    {
        if (!(ulFlags[1] & mask))
            *static_cast<volatile int*>(&iLastRenderPassState) = 0;
        ulFlags[1] |= mask;
    }
    else
    {
        if (ulFlags[1] & mask)
            *static_cast<volatile int*>(&iLastRenderPassState) = 0;
        ulFlags[1] &= ~mask;
    }
}
struct Settings383
{
    unsigned int value0, value1, value2, value3, value4, value5, value6;
    bool flag400, flag800, flag1000;
    unsigned char unk1f;
};
struct Owner383
{
    unsigned int unk00, unk04, unk08;
    BSShaderProperty* property;
    unsigned int unk10, unk14, unk18;
    Settings383 settings;
    void CopySettings(const Settings383* source);
};
// Copies the Settings383 block from source into settings and mirrors its three flags onto property via SetFlag.
// @fnv 0x00bd86a0
void Owner383::CopySettings(const Settings383* source)
{
    if (source)
        memmove(&settings, source, sizeof(settings));
    property->SetFlag(0x400, settings.flag400);
    property->SetFlag(0x800, settings.flag800);
    property->SetFlag(0x1000, settings.flag1000);
}

struct FUN_00bddbc0_class : Shader_00bd9540
{
    int BSShaderProperty_AddPass_DiffusePoint3(NiGeometry* geom, ShadowSceneLight* l0, ShadowSceneLight* l1, ShadowSceneLight* l2,
                     unsigned short* count, unsigned char type, bool* out, bool a, bool b, bool c, bool d, bool e);
};

// If type is 1, adds a pass to pPasses for geom and the three lights (id chosen by flags a, b, d, e), else increments *count; then clears *out.
// @fnv 0x00bddbc0
// src: COMMUNITY 0x00bddbc0
int FUN_00bddbc0_class::BSShaderProperty_AddPass_DiffusePoint3(NiGeometry* geom, ShadowSceneLight* l0, ShadowSceneLight* l1, ShadowSceneLight* l2,
                                     unsigned short* count, unsigned char type, bool* out, bool abFlagA, bool abFlagB,
                                     bool abFlagC, bool abFlagD, bool abFlagE)
{
    if (!abFlagA)
    {
        if (!abFlagB)
        {
            if (!abFlagD)
            {
                if (!abFlagE)
                {
                    if (type == 1)
                    {
                        pPasses->Add(geom, 0x13e, *out, 3, l0, l1, l2, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
                else
                {
                    if (type == 1)
                    {
                        pPasses->Add(geom, 0x143, *out, 3, l0, l1, l2, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
            }
            else
            {
                if (type == 1)
                {
                    pPasses->Add(geom, 0x140, *out, 3, l0, l1, l2, 0);
                }
                else
                {
                    ++*count;
                }
            }
        }
        else
        {
            if (type == 1)
            {
                pPasses->Add(geom, 0x13f, *out, 3, l0, l1, l2, 0);
            }
            else
            {
                ++*count;
            }
        }
    }
    else
    {
        if (!abFlagB)
        {
            if (!abFlagD)
            {
                if (type == 1)
                {
                    pPasses->Add(geom, 0x141, *out, 3, l0, l1, l2, 0);
                }
                else
                {
                    ++*count;
                }
            }
        }
        else
        {
            if (type == 1)
            {
                pPasses->Add(geom, 0x142, *out, 3, l0, l1, l2, 0);
            }
            else
            {
                ++*count;
            }
        }
    }
    *out = false;
    return 0;
}

struct S3e40_Count
{
    unsigned short* ptr;
};
struct S3e40_Color
{
    float r, g, b;
    float ComputeWeightedSum();
};
struct S3e40_Vec
{
    float x, y, z;
    float ComputeWeightedSum();
    float FUN_00457990();
};
__forceinline float S3e40_Len(const S3e40_Color& v)
{
    S3e40_Color t = v;
    return t.ComputeWeightedSum();
}
struct S3e40_Xform
{
    float px, py, pz, angle;
};
extern const S3e40_Xform DAT_011f4288;
struct S3e40_State
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
    float posX, posY, posZ;
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
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    S3e40_Color dir;
};
struct S3e40_Light
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
    S3e40_State* state;
};
union SharedWork
{
    S3e40_Xform bound;
    S3e40_Color color;
    S3e40_Light* first;
    SharedWork(const S3e40_Xform& v) : bound(v)
    {}
    SharedWork(const S3e40_Color& v) : color(v)
    {}
};
struct S3e40_Ref
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short status;
    unsigned char Mode() const
    {
        return (status >> 9) & 1;
    }
};
struct S3e40_Geom
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S3e40_Xform* world;
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
    S3e40_Ref* fallback;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    void* shader;
    S3e40_Ref* FUN_00a59d30(bool b);
};
struct S3e40_Root
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
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    S3e40_Light* currentLight;
};
struct S3e40_View
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
    S3e40_Root* root;
};
struct S3e40_Passes
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int count;
    void FUN_00ba9ee0(S3e40_Geom*, unsigned short, bool, unsigned char, S3e40_Light*, S3e40_Light*, S3e40_Light*,
                      S3e40_Light*);
};
S3e40_View* __cdecl BSShaderManager_GetAccumulator();
float __cdecl BSMAX_00404010(float, float);
bool __cdecl BSShaderManager_GetShadows();
struct S3e40_Shader
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned int renderFlags;
    unsigned int lightFlags;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    unsigned int passState;
    S3e40_Passes* passes;
    S3e40_Light* pass7;
    S3e40_Light* pass8;
    S3e40_Light* pass9;
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
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int callback;
    void SetBit(unsigned int& bits, unsigned int mask, bool on)
    {
        if (((bits & mask) != 0) != on)
            passState = 0;
        if (on)
            bits |= mask;
        else
            bits &= ~mask;
    }
    void SetFlag(unsigned int mask, bool on)
    {
        SetBit(lightFlags, mask, on);
    }
    S3e40_Light* GetPasses(S3e40_Geom*, unsigned int, unsigned short*, int, S3e40_Light*, bool);
    void SetPassEnabled(S3e40_Geom*, bool, int);
    void FUN_00ba95e0(int);
    unsigned short BSShaderLightingProperty_GetNumberofActiveNonShadowLights();
    S3e40_Light* BSShaderLightingProperty_GetFirstActiveNonShadowLight(int*);
    S3e40_Light* BSShaderLightingProperty_GetNextActiveNonShadowLight(int*);
    void BSShaderProperty_SetFlag(unsigned int, bool);
    void BSShaderPPLightingProperty_AddDepthMapPass_2x(S3e40_Geom*, bool, bool, S3e40_Light*);
    void BSShaderProperty_TexEffect(S3e40_Geom*, unsigned short*, bool, bool*, int);
    S3e40_Light* HairShaderProperty_GetRenderPasses(S3e40_Geom* geom, unsigned int subType, S3e40_Count counter, int passType,
                              S3e40_Light* preferred, bool insert);
};
__forceinline bool S3e40_Less(const float& a, const double& b)
{
    return a < b;
}
// @fnv 0x00bc3e40
// src: XBOX_PDB 0x00bc3e40
S3e40_Light* S3e40_Shader::HairShaderProperty_GetRenderPasses(S3e40_Geom* geom, unsigned int subType, S3e40_Count counter, int passType,
                                        S3e40_Light* preferred, bool insert)
{
    TlsGuard_t guard(0x28);
    if ((renderFlags & 0x8000) > 0u)
        goto delegated;
    if ((renderFlags & 0x10000) > 0u)
        goto delegated;
    goto regular;
delegated:
    return GetPasses(geom, subType, counter.ptr, passType, preferred, insert);
regular:

    unsigned int key = (passType << 8) | subType;
    if (passType == 7)
        return pass7;
    if (passType == 8)
        return pass8;
    if (passType == 9)
    {
        SetPassEnabled(geom, geom->shader != 0, 0);
        return pass9;
    }

    if (passState != key || !insert)
    {
        if (insert == true)
        {
            FUN_00ba95e0(-1);
            passes->count = 0;
            passState = key;
        }
        else
        {
            *counter.ptr = 0;
        }

        S3e40_Light* sceneLight = BSShaderManager_GetAccumulator()->root->currentLight;
        if (BSShaderLightingProperty_GetNumberofActiveNonShadowLights() == 0)
        {
            if (insert == true)
            {
                passes->FUN_00ba9ee0(geom, 0xc1, true, 1, sceneLight, 0, 0, 0);
                SetFlag(0x80, false);
                SetFlag(0x100, false);
                SetFlag(0x200, false);
            }
            else
            {
                ++*counter.ptr;
            }
        }
        else
        {
            float dist;
            passType = 0;
            S3e40_Light* __restrict primary = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&passType);
            {
                S3e40_State* ss = sceneLight->state;
                dist = S3e40_Len(ss->dir);
            }
            float quality;
            S3e40_State* ps;
            {
                const S3e40_Xform* wp = geom->world;
                if (!wp)
                    wp = &DAT_011f4288;
                SharedWork world(*wp);
                ps = primary->state;
                {
                    S3e40_Vec delta = {ps->posX - world.bound.px, ps->posY - world.bound.py, ps->posZ - world.bound.pz};
                    quality = BSMAX_00404010(0.0f, delta.FUN_00457990() - world.bound.angle);
                }
            }
            {
                SharedWork work(ps->dir);
                S3e40_Light* secondLight;
                S3e40_Light* secondary;
                {

                    if ((double)dist > (float)((1.0 / quality * quality) * work.color.ComputeWeightedSum()))
                    {
                        work.first = sceneLight;
                        secondLight = 0;
                        secondary = 0;
                        SetFlag(0x80, false);
                        SetFlag(0x100, false);
                        SetFlag(0x200, false);
                        if (primary)
                        {
                            secondLight = primary;
                            SetFlag(0x100, true);
                        }
                        primary = BSShaderLightingProperty_GetNextActiveNonShadowLight(&passType);
                        if (primary)
                        {
                            secondary = primary;
                            SetFlag(0x200, true);
                        }
                    }
                    else
                    {
                        work.first = primary;
                        SetFlag(0x80, true);
                        if (dist > 0.0f)
                        {
                            primary = BSShaderLightingProperty_GetNextActiveNonShadowLight(&passType);
                            if (primary)
                            {
                                secondLight = sceneLight;
                                secondary = primary;
                                SetFlag(0x100, true);
                                SetFlag(0x200, true);
                            }
                            else
                            {
                                secondLight = sceneLight;
                                secondary = 0;
                                SetFlag(0x100, true);
                                SetFlag(0x200, false);
                            }
                        }
                        else
                        {
                            primary = BSShaderLightingProperty_GetNextActiveNonShadowLight(&passType);
                            if (primary)
                            {
                                secondLight = primary;
                                primary = BSShaderLightingProperty_GetNextActiveNonShadowLight(&passType);
                                secondary = primary;
                                SetFlag(0x100, true);
                                BSShaderProperty_SetFlag(0x29, primary != 0);
                            }
                            else
                            {
                                secondLight = 0;
                                secondary = 0;
                                SetFlag(0x100, false);
                                SetFlag(0x200, false);
                            }
                        }
                    }
                }
                if (insert == true)
                    passes->FUN_00ba9ee0(geom, 0xc2, true, 3, work.first, secondLight, secondary, 0);
                else
                    ++*counter.ptr;
            }
        }
        if (BSShaderManager_GetShadows() && insert)
        {
            S3e40_Ref* ref = geom->FUN_00a59d30(false);
            if (!ref)
                ref = geom->fallback;
            bool marked = ref && (ref->Mode() != 0);
            BSShaderPPLightingProperty_AddDepthMapPass_2x(geom, geom->shader != 0, marked, preferred);
        }
    }
    if (callback)
    {
        bool changed = true;
        BSShaderProperty_TexEffect(geom, counter.ptr, insert, &changed, 0);
    }
    return reinterpret_cast<S3e40_Light*>(passes);
}

extern "C" void _ReadWriteBarrier();
static __forceinline float Lower(float a, float b)
{
    return a < b ? a : b;
}
static __forceinline float Upper(float a, float b)
{
    return a > b ? a : b;
}
extern "C" double __cdecl sqrt(double);
inline float sqrtf(float value)
{
    return (float)sqrt((double)value);
}

inline LocalVec3::LocalVec3()
{}

inline LocalVec3::LocalVec3(float a, float b, float c) : x(a), y(b), z(c)
{}

inline LocalVec3 LocalVec3::operator-(const LocalVec3& b) const
{
    LocalVec3 r;
    r.x = x - b.x;
    r.y = y - b.y;
    r.z = z - b.z;
    return r;
}

inline LocalVec3 LocalVec3::operator*(double f) const
{
    LocalVec3 r;
    r.x = (float)(x * f);
    r.y = (float)(y * f);
    r.z = (float)(z * f);
    return r;
}

inline LocalVec3 LocalVec3::operator+(const LocalVec3& b) const
{
    LocalVec3 r;
    r.x = x + b.x;
    r.y = y + b.y;
    r.z = z + b.z;
    return r;
}

inline LocalVec3& LocalVec3::operator+=(const LocalVec3& b)
{
    x += b.x;
    y += b.y;
    z += b.z;
    return *this;
}

inline float LocalVec3::Length() const
{
    return sqrtf(x * x + y * y + z * z);
}

inline NiPoint3 NiPoint3::operator-(const NiPoint3& b) const
{
    return NiPoint3(x - b.x, y - b.y, z - b.z);
}

inline NiPoint3 NiPoint3::operator+(const NiPoint3& b) const
{
    return NiPoint3(x + b.x, y + b.y, z + b.z);
}

inline NiPoint3 NiPoint3::operator*(float a) const
{
    return NiPoint3(x * a, y * a, z * a);
}

inline float NiPoint3::Length() const
{
    double squaredX = x * x;
    double squaredY = y * y;
    double squaredZ = z * z;
    float squaredLength = (float)(squaredX + squaredY + squaredZ);
    return (float)sqrt(squaredLength);
}
// Temporaries call the non-const overload: same inline body.
inline float NiPoint3::Length()
{
    double squaredX = x * x;
    double squaredY = y * y;
    double squaredZ = z * z;
    float squaredLength = (float)(squaredX + squaredY + squaredZ);
    return (float)sqrt(squaredLength);
}


struct Sphere
{
    float center[3];
    float radius;
    Sphere()
    {}
    void Set(const LocalVec3& point, float value)
    {
        memcpy(&center, &point, sizeof(center));
        radius = value;
    }
};
struct Vertex
{
    float x;
    float y;
    float z;
    float w;
};

extern NiRTTI DAT_012024c0;
extern NiRTTI DAT_012024b8;
extern float DAT_010bc3ec;

struct SphereRenderer
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
    virtual void slot_0f4();
    virtual void slot_0f8();
    virtual void SetSphere(Sphere sphere);              // slot_0fc
    virtual void SetVertexCount(unsigned short count);  // slot_100
};
struct RendererCountTable
{
    void* slot_000;
    void* slot_004;
    void* slot_008;
    void* slot_00c;
    void* slot_010;
    void* slot_014;
    void* slot_018;
    void* slot_01c;
    void* slot_020;
    void* slot_024;
    void* slot_028;
    void* slot_02c;
    void* slot_030;
    void* slot_034;
    void* slot_038;
    void* slot_03c;
    void* slot_040;
    void* slot_044;
    void* slot_048;
    void* slot_04c;
    void* slot_050;
    void* slot_054;
    void* slot_058;
    void* slot_05c;
    void* slot_060;
    void* slot_064;
    void* slot_068;
    void* slot_06c;
    void* slot_070;
    void* slot_074;
    void* slot_078;
    void* slot_07c;
    void* slot_080;
    void* slot_084;
    void* slot_088;
    void* slot_08c;
    void* slot_090;
    void* slot_094;
    void* slot_098;
    void* slot_09c;
    void* slot_0a0;
    void* slot_0a4;
    void* slot_0a8;
    void* slot_0ac;
    void* slot_0b0;
    void* slot_0b4;
    void* slot_0b8;
    void* slot_0bc;
    void* slot_0c0;
    void* slot_0c4;
    void* slot_0c8;
    void* slot_0cc;
    void* slot_0d0;
    void* slot_0d4;
    void* slot_0d8;
    void* slot_0dc;
    void* slot_0e0;
    void* slot_0e4;
    void* slot_0e8;
    void* slot_0ec;
    void* slot_0f0;
    void* slot_0f4;
    void* slot_0f8;
    void* sphere;
    void(__thiscall* count)(SphereRenderer*, unsigned short);
};
struct RendererCountView
{
    RendererCountTable* vtable;
};
struct BoundsObject
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
    virtual void SetGridPosition(LocalVec3* center);  // slot_0b8
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    LocalVec3 SetCenterPosition;
};
struct SpatialObject
{
    int unk00;
    int unk04;
    int unk08;
    BoundsObject* m_pBounds;  // +0x0c
};
struct HierarchyObject
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
    SpatialObject* m_pSpatial;  // +0xac
};
struct RadiusDataObject
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
    float m_fRadiusAdjustment;  // +0x28
};
struct GeometryBounds
{
    NiObject* m_pPrimary;             // +0x00
    HierarchyObject* m_pHierarchy;    // +0x04
    RadiusDataObject* m_pRadiusData;  // +0x08
    int m_unk0c;
    unsigned short m_unk10;
    unsigned short m_uiItemCount;  // +0x12
    Vertex* m_pVertexData;         // +0x14
    unsigned int* m_pKeys;         // +0x18
    void UpdateBounds();
};
struct SavedGeometry
{
    GeometryBounds* ptr;
};
// Computes the vertex bounding sphere and radius, then applies it to the primary or alternate SphereRenderer and updates the spatial bounds grid position.
// @fnv 0x00bd8750
void GeometryBounds::UpdateBounds()
{
    Sphere sphere;
    float f = DAT_010bc3ec;
    if (!m_uiItemCount)
        f = 0.0f;

    int count = m_uiItemCount;

    LocalVec3 min(f, f, f);
    LocalVec3 max(-f, -f, -f);

    for (int index = 0; index < m_uiItemCount; ++index)
    {
        min.x = Lower(min.x, m_pVertexData[index].x);
        max.x = Upper(max.x, m_pVertexData[index].x);
        min.y = Lower(min.y, m_pVertexData[index].y);
        max.y = Upper(max.y, m_pVertexData[index].y);
        min.z = Lower(min.z, m_pVertexData[index].z);
        max.z = Upper(max.z, m_pVertexData[index].z);
    }

    RadiusDataObject* radiusData = m_pRadiusData;
    if (radiusData != 0)
    {
        NiObject* primary = m_pPrimary;
        if (primary != 0)
        {
            LocalVec3 center = min + (max - min) * 0.5;
            sphere.Set(center, (max - center).Length() + radiusData->m_fRadiusAdjustment);

            SphereRenderer* renderer = IsKindOfType(primary, &DAT_012024c0) ? (SphereRenderer*)primary : 0;
            if (renderer)
            {
                renderer->SetSphere(sphere);
                RendererCountTable* table = reinterpret_cast<RendererCountView*>(renderer)->vtable;
                table->count(renderer, this->m_uiItemCount);
            }
            else
            {
                NiObject* fallback = this->m_pPrimary;
                SphereRenderer* alternate = fallback ? (SphereRenderer*)fallback->DynamicCast(&DAT_012024b8) : 0;
                if (alternate)
                {
                    alternate->SetSphere(sphere);
                    RendererCountTable* table = reinterpret_cast<RendererCountView*>(alternate)->vtable;
                    table->count(alternate, this->m_uiItemCount);
                }
            }

            BoundsObject* bounds = this->m_pHierarchy->m_pSpatial->m_pBounds;
            bounds->SetGridPosition(&center);
            LocalVec3 extent = max - center;
            memcpy(&bounds->SetCenterPosition, &extent, sizeof(extent));
        }
    }
}

namespace fnv_00bc0f80 {
struct Pass_bc0f80
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
    int count;
    void FUN_00e80190();
    void IncRefCount()
    {
        ++count;
    }
    void DecRefCount()
    {
        if (--count == 0)
            FUN_00e80190();
    }
};

extern StagingNiPointer<ShaderObject> DAT_01201f58;
struct FUN_00be0f10
{
    virtual ~FUN_00be0f10();
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
    void* unk070;
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
};
struct FUN_00bc0f80 : FUN_00be0f10
{
    StagingNiPointer<Pass_bc0f80> pass;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    StagingNiPointer<ShaderObject> refA;
    StagingNiPointer<ShaderObject> refB;
    virtual ~FUN_00bc0f80();
};

// @fnv 0x00bc0f80
FUN_00bc0f80::~FUN_00bc0f80()
{
    DAT_01201f58 = 0;
    g_memoryManager.Deallocate(unk070);
    unk070 = 0;
    pass = 0;
    if (ShaderObject* obj = refA)
    {
        long volatile* p = &obj->m_uiRefCount;
        if (InterlockedDecrement(p) == 0)
            obj->DeleteThis();
        refA.m_pObject = 0;
    }
    refB = 0;
}
}  // namespace fnv_00bc0f80

namespace fnv_00bcf7f0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct ShaderRefObject
{
    virtual ~ShaderRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> struct ShaderPtr
{
    T* m_pObject;
    ShaderPtr();
    ~ShaderPtr();
};

struct ShaderRefPtr
{
    ShaderRefObject* m_pObject;
    ShaderRefPtr& operator=(ShaderRefObject* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct ShaderBase
{
    ShaderBase(void* a, void* b, int c, int d);
    virtual ~ShaderBase();
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
    bool unk64;
    int unk68;
    ShaderRefPtr m_spPixelShaderObject;
    ShaderRefPtr m_spVertexShaderObject;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
};

struct FUN_00bcf7f0 : ShaderBase
{
    ShaderPtr<ShaderRefObject> m_aspPasses[26];
    ShaderPtr<ShaderRefObject> m_aspOtherPasses[13];
    FUN_00bcf7f0(ShaderRefObject* pPixel, ShaderRefObject* pVertex);
    virtual ~FUN_00bcf7f0();
};

// Passes pPixel and pVertex to the base and stores them in the reference pointers; sets unk68 to 4, unk64 to false and unk60 to 0.
// @fnv 0x00bcf7f0
FUN_00bcf7f0::FUN_00bcf7f0(ShaderRefObject* pPixel, ShaderRefObject* pVertex) : ShaderBase(pPixel, pVertex, 0, 0)
{
    unk68 = 4;
    unk64 = false;
    m_spPixelShaderObject = pPixel;
    m_spVertexShaderObject = pVertex;
    unk60 = 0;
}
}  // namespace fnv_00bcf7f0

namespace fnv_00bdb4a0 {
static __forceinline bool AlphaOrdered(float left, float right)
{
    return left < right;
}
struct SceneGeometry;
struct DrawLight;
// Exe 0x00bdb4a0: unit-local ShaderPassEntry view; declarations and layout are preserved.

struct RenderPassCollection
{
    unsigned int unknown00;
    BSShaderProperty::ShaderPassEntry** entries;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int size;
    void AddPass(SceneGeometry*, unsigned short, bool, unsigned char, DrawLight*, DrawLight*, DrawLight*, DrawLight*);
};
struct GeometryState
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned char flags;
};
struct GeometryData
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
    int normalCount;
};
struct GeometryProperty
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned short flags;
};
struct PropHelper
{
    void* GetProperty(unsigned int);
};
struct SceneGeometry : PropHelper
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
    GeometryState* state;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    GeometryData* data;
};
struct AttributeTester
{
    bool FUN_00439090(const void* property);
};
struct LightProperties
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
    AttributeTester primary;
    unsigned char unkd5;
    unsigned short unkd6;
    unsigned int unkd8;
    unsigned int unkdc;
    AttributeTester alternate;
};
struct DrawLight
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
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    LightProperties* properties;
    bool Matches(const void* property)
    {
        return properties->primary.FUN_00439090(property);
    }
    bool MatchesAlternate(const void* property)
    {
        return properties->alternate.FUN_00439090(property);
    }
};
struct ExtraPassContext
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
struct LightConfiguration
{
    unsigned int reserved00;
    unsigned int reserved04;
    unsigned int reserved08;
    unsigned int reserved0c;
    unsigned int VirtualFunction10;
    unsigned int reserved14;
    unsigned int reserved18;
    unsigned int reserved1c;
    unsigned int reserved20;
    unsigned int VirtualFunction24;
    unsigned int VirtualFunction28;
    unsigned int reserved2c;
    unsigned int reserved30;
    unsigned int category34;
};
struct DynCastHelper
{
    NiObject* DynamicCast(const void*);
};
struct ConfigurationArg
{
    LightConfiguration* value;
};
struct ShaderPassBuilder : DynCastHelper
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int renderFlags;
    unsigned int propertyFlags;
    float alphaCutoff;
    unsigned int unk2c;
    unsigned int unk30;
    float fade;
    unsigned int unk38;
    RenderPassCollection* passes;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    unsigned int unka0, unka4, unka8, unkac, unkb0;
    int* renderContext;
    unsigned int unkb8, unkbc, unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8;
    ExtraPassContext* extraContext;
    unsigned short BSShaderLightingProperty_GetNumberofActiveNonShadowLights();
    DrawLight* BSShaderLightingProperty_GetFirstActiveNonShadowLight(void**);
    DrawLight* BSShaderLightingProperty_GetNextActiveNonShadowLight(void**);
    BSShaderProperty::ShaderPassEntry* BSShaderProperty_AddPass_ZOnly(SceneGeometry*, unsigned short*, unsigned char, bool*, bool, bool);
    BSShaderProperty::ShaderPassEntry* BSShaderProperty_AddPass_NormalsClear(SceneGeometry*, unsigned short*, unsigned char, bool*, bool);
    void BSShaderProperty_AmbientDirAndPoint(SceneGeometry*, DrawLight*, DrawLight*, unsigned short*, unsigned char, bool*, bool, bool);
    void BSShaderProperty_AddPass_Ambient(SceneGeometry*, DrawLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool);
    void BSShaderProperty_AddPass_DiffuseDirOrPoint(SceneGeometry*, DrawLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool);
    void BSShaderPPLightingProperty_AddTexturePass_1x(SceneGeometry*, DrawLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool,
                      bool);
    void BSShaderProperty_AddPass_SpecularAmbientDirPoint(SceneGeometry*, DrawLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool,
                      bool);
    void BSShaderProperty_AddPass_EnvMap(SceneGeometry*, unsigned short*, unsigned char, bool*, bool, bool);
    void EmitShadowPasses(SceneGeometry*, DrawLight*, unsigned short*, unsigned char, bool*, bool);
    void BSShaderProperty_AddPass_Fog(SceneGeometry*, unsigned short*, unsigned char, bool*, bool, bool, bool);
    BSShaderProperty::ShaderPassEntry* BSShaderProperty_AddPass_ZOnly_TexEffect(SceneGeometry*, unsigned short*, unsigned char, bool*, bool);
    BSShaderProperty::ShaderPassEntry* BSShaderProperty_TexEffect(SceneGeometry*, unsigned short*, unsigned char, bool*, bool);
    void CreatePassMessage(SceneGeometry*, unsigned short*, unsigned char, bool, bool);
    void BSShaderProperty_AddPass_AmbDiffTex(SceneGeometry*, DrawLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool,
                      bool, bool);
// src: COMMUNITY 0x00bd9da0
    BSShaderProperty::ShaderPassEntry* BSShaderProperty_AddPass_Normals(SceneGeometry* geometry, unsigned short* count, unsigned char type, bool* first,
                                  bool overlay, bool effect)
    {
        if (effect)
        {
            if (type == 1)
            {
                passes->AddPass(geometry, 0x1e4, *first, 0, 0, 0, 0, 0);
                *first = false;
                return 0;
            }
        }
        else if (!overlay)
        {
            if (type == 1)
            {
                passes->AddPass(geometry, 0x1e2, *first, 0, 0, 0, 0, 0);
                *first = false;
                return 0;
            }
        }
        else if (type == 1)
        {
            passes->AddPass(geometry, 0x1e3, *first, 0, 0, 0, 0, 0);
            *first = false;
            return 0;
        }
        ++*static_cast<unsigned short*>(count);
        *first = false;
        return 0;
    }
    BSShaderProperty::ShaderPassEntry* AddEffectPass(SceneGeometry* geometry, unsigned short* count, unsigned char type, bool* first,
                                   bool overlay, bool effect)
    {
        BSShaderProperty_AddPass_Normals(geometry, count, type, first, overlay, effect);
        return 0;
    }
    __forceinline void GenerateLightingPasses(SceneGeometry* geometry, unsigned int passMask, unsigned short* count,
                                              unsigned char effectType, bool hasNoBasePass, bool addAdditional,
                                              bool basePass, bool hasNoOverlay, bool& needsShadow,
                                              bool hasRenderContext, bool needsExtraPass, bool needsNormal, bool attr0,
                                              bool attr1, bool attr2, bool opaque, bool translucent,
                                              bool blockedByEffect, bool allowFirstPass, bool specialBlend,
                                              bool hasHighFlags, bool lightingCondition, bool extraLight, bool useAlpha,
                                              bool useAlternate, DrawLight* primaryLight);
    void BSShaderPPLightingProperty_GetRenderPasses_1x(SceneGeometry* geometry, unsigned int passMask, unsigned short* count, int mode,
                      LightConfiguration* config, unsigned char effectType);
};
extern unsigned int DAT_010a91d4;
extern unsigned char DAT_011f91a7;
extern unsigned char DAT_011f9422;
extern float DAT_011f9458;
extern float DAT_011f9460;
extern float DAT_011f9468;
extern int DAT_011f4998;
extern int DAT_01200788;
extern int DAT_012024c8;
extern int DAT_012007a0;
extern void* __cdecl BSShaderManager_GetAccumulator();
struct DefaultRenderer
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
    DrawLight* light;
};
struct ShaderEngine
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
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    DefaultRenderer* renderer;
};
static DrawLight* GetDefaultLight()
{
    return static_cast<ShaderEngine*>(BSShaderManager_GetAccumulator())->renderer->light;
}
__forceinline void ShaderPassBuilder::GenerateLightingPasses(
    SceneGeometry* geometry, unsigned int passMask, unsigned short* count, unsigned char effectType, bool hasNoBasePass,
    bool addAdditional, bool basePass, bool hasNoOverlay, bool& needsShadow, bool hasRenderContext, bool needsExtraPass,
    bool needsNormal, bool attr0, bool attr1, bool attr2, bool opaque, bool translucent, bool blockedByEffect,
    bool allowFirstPass, bool specialBlend, bool hasHighFlags, bool lightingCondition, bool extraLight, bool useAlpha,
    bool useAlternate, DrawLight* primaryLight)
{
    bool first = true;
    if (translucent || blockedByEffect)
    {
        AddEffectPass(geometry, count, effectType, &first, hasNoOverlay, blockedByEffect)->m_ucLightIndex = 6;
        return;
    }
    if ((propertyFlags & 0x40) > 0)
        BSShaderProperty_AddPass_NormalsClear(geometry, count, effectType, &first, hasNoOverlay)->m_ucLightIndex = 7;
    unsigned short numLights = BSShaderLightingProperty_GetNumberofActiveNonShadowLights();
    if (allowFirstPass && (needsShadow || passMask == DAT_010a91d4))
    {
        if (!needsShadow && opaque)
            goto afterLighting;
        if (numLights >= 1 && !needsShadow)
        {
            DrawLight* light;
            void* cursor = 0;
            light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&cursor);
            if (!extraLight && !hasNoOverlay && !hasRenderContext)
            {
                BSShaderProperty_AmbientDirAndPoint(geometry, primaryLight, light, count, effectType, &first, false, attr0);
            }
            else
            {
                if ((passMask & 1) != 0)
                    BSShaderProperty_AddPass_Ambient(geometry, primaryLight, count, effectType, &first, hasNoOverlay, extraLight,
                                 hasRenderContext, attr0);
                if (primaryLight->Matches(&DAT_011f4998))
                    BSShaderProperty_AddPass_DiffuseDirOrPoint(geometry, primaryLight, count, effectType, &first, hasNoOverlay, false, false, attr0);
                if (light->Matches(&DAT_011f4998))
                    BSShaderProperty_AddPass_DiffuseDirOrPoint(geometry, light, count, effectType, &first, hasNoOverlay, true, false, attr0);
            }
            for (light = BSShaderLightingProperty_GetNextActiveNonShadowLight(&cursor); light; light = BSShaderLightingProperty_GetNextActiveNonShadowLight(&cursor))
            {
                if (light->Matches(&DAT_011f4998))
                    BSShaderProperty_AddPass_DiffuseDirOrPoint(geometry, light, count, effectType, &first, hasNoOverlay, true, false, attr0);
            }
            BSShaderPPLightingProperty_AddTexturePass_1x(geometry, primaryLight, count, effectType, &first, hasNoOverlay, false, needsExtraPass,
                         needsNormal, attr0, specialBlend);
            if (basePass)
            {
                light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&cursor);
                if (useAlternate && primaryLight->Matches(&DAT_011f4998))
                {
                    BSShaderProperty_AddPass_SpecularAmbientDirPoint(geometry, primaryLight, count, effectType, &first, hasNoOverlay, false, false,
                                 hasNoBasePass, false, attr0);
                }
                else
                {
                    BSShaderProperty_AddPass_SpecularAmbientDirPoint(geometry, light, count, effectType, &first, hasNoOverlay, true, false, hasNoBasePass,
                                 false, attr0);
                    light = BSShaderLightingProperty_GetNextActiveNonShadowLight(&cursor);
                }
                while (light)
                {
                    if (light->Matches(&DAT_011f4998))
                        BSShaderProperty_AddPass_SpecularAmbientDirPoint(geometry, light, count, effectType, &first, hasNoOverlay, true, false,
                                     hasNoBasePass, false, attr0);
                    light = BSShaderLightingProperty_GetNextActiveNonShadowLight(&cursor);
                }
            }
            if (addAdditional)
                BSShaderProperty_AddPass_EnvMap(geometry, count, effectType, &first, hasNoOverlay, needsNormal);
        }
        else
        {
            if ((needsShadow || !useAlternate) && !attr1 && !attr2)
            {
                BSShaderProperty_AddPass_AmbDiffTex(geometry, primaryLight, count, effectType, &first, hasNoOverlay, extraLight,
                             hasRenderContext, needsExtraPass, true, needsNormal, attr0);
                needsShadow = true;
            }
            else
            {
                BSShaderProperty_AddPass_AmbDiffTex(geometry, primaryLight, count, effectType, &first, hasNoOverlay, extraLight,
                             hasRenderContext, needsExtraPass, false, needsNormal, attr0);
            }
            if (useAlternate && !needsShadow)
                BSShaderProperty_AddPass_SpecularAmbientDirPoint(geometry, primaryLight, count, effectType, &first, hasNoOverlay, false, false,
                             hasNoBasePass, false, attr0);
            if (addAdditional)
                BSShaderProperty_AddPass_EnvMap(geometry, count, effectType, &first, hasNoOverlay, needsNormal);
        }
    }
    else
    {
        if (opaque)
            goto afterLighting;
        first = true;
        if (passMask & 1)
            BSShaderProperty_AddPass_Ambient(geometry, primaryLight, count, effectType, &first, hasNoOverlay, extraLight, hasRenderContext,
                         attr0);
        if (passMask & 2)
        {
            DrawLight* light;
            if (primaryLight->Matches(&DAT_011f4998))
                BSShaderProperty_AddPass_DiffuseDirOrPoint(geometry, primaryLight, count, effectType, &first, hasNoOverlay, false, false, attr0);
            void* cursor = 0;
            for (light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&cursor); light; light = BSShaderLightingProperty_GetNextActiveNonShadowLight(&cursor))
                if (light->Matches(&DAT_011f4998))
                    BSShaderProperty_AddPass_DiffuseDirOrPoint(geometry, light, count, effectType, &first, hasNoOverlay, true, false, attr0);
        }
        if (passMask & 4)
            BSShaderPPLightingProperty_AddTexturePass_1x(geometry, primaryLight, count, effectType, &first, hasNoOverlay, false, needsExtraPass,
                         needsNormal, attr0, specialBlend);
        if (basePass && (passMask & 8))
        {
            DrawLight* light;
            void* cursor = 0;
            light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&cursor);
            if (useAlternate && primaryLight->Matches(&DAT_011f4998))
            {
                BSShaderProperty_AddPass_SpecularAmbientDirPoint(geometry, primaryLight, count, effectType, &first, hasNoOverlay, false, false,
                             hasNoBasePass, false, attr0);
                first = false;
            }
            else if (light && light->Matches(&DAT_011f4998))
            {
                BSShaderProperty_AddPass_SpecularAmbientDirPoint(geometry, light, count, effectType, &first, hasNoOverlay, true, false, hasNoBasePass,
                             false, attr0);
                light = BSShaderLightingProperty_GetNextActiveNonShadowLight(&cursor);
            }
            while (light)
            {
                if (light->Matches(&DAT_011f4998))
                    BSShaderProperty_AddPass_SpecularAmbientDirPoint(geometry, light, count, effectType, &first, hasNoOverlay, true, false, hasNoBasePass,
                                 false, attr0);
                light = BSShaderLightingProperty_GetNextActiveNonShadowLight(&cursor);
            }
        }
        if (addAdditional && (8 & passMask))
            BSShaderProperty_AddPass_EnvMap(geometry, count, effectType, &first, hasNoOverlay, needsNormal);
    }
afterLighting:
    if (opaque)
        EmitShadowPasses(geometry, primaryLight, count, effectType, &first, false);
    if (passMask == DAT_010a91d4 && !needsShadow)
        BSShaderProperty_AddPass_Fog(geometry, count, effectType, &first, hasNoOverlay, attr0, useAlpha);
    if (extraContext)
    {
        if (0 != extraContext->enabled)
            BSShaderProperty_AddPass_ZOnly_TexEffect(geometry, count, effectType, &first, hasNoOverlay)->m_ucLightIndex = 1;
        BSShaderProperty_TexEffect(geometry, count, effectType, &first, hasNoOverlay)->m_ucLightIndex = 1;
    }
    if (DAT_011f9422 && (passMask & 1))
        CreatePassMessage(geometry, count, effectType, hasNoOverlay, hasRenderContext);
    unsigned long missingPassStatus = 0;
    if (lightingCondition)
        missingPassStatus = 10;
    else if (hasHighFlags)
        missingPassStatus = ((propertyFlags & 0x200000) > 0) ? 1 : 4;
    else if (useAlpha)
        missingPassStatus = 1;
    for (unsigned int i = 0; i < passes->size; ++i)
        if (passes->entries[i]->m_ucLightIndex == 0)
            passes->entries[i]->m_ucLightIndex = static_cast<unsigned char>(missingPassStatus);
}
// @fnv 0x00bdb4a0
// src: XBOX_PDB 0x00bdb4a0
void ShaderPassBuilder::BSShaderPPLightingProperty_GetRenderPasses_1x(SceneGeometry* geometry, unsigned int passMask, unsigned short* count, int mode,
                                     LightConfiguration* config, unsigned char effectType)
{
    const unsigned int initialFlags = renderFlags;
    bool hasNoBasePass;
    hasNoBasePass = (1 & initialFlags) > 0;
    bool addAdditional = (initialFlags & 0x80) > 0;
    bool basePass = hasNoBasePass;
    bool hasNoOverlay = (initialFlags & 2) > 0;
    bool needsShadow = (initialFlags & 0x20) > 0 || mode == 3;
    bool hasRenderContext = *renderContext != 0;
    bool needsExtraPass = (initialFlags & 0x400) > 0;
    bool needsNormal = false;
    if (0 != geometry->data->normalCount)
        needsNormal = true;
    needsNormal |= (propertyFlags & 0x20) > 0;
    bool attr0 = DynamicCast(&DAT_01200788) != 0;
    bool attr1 = DynamicCast(&DAT_012024c8) != 0;
    bool attr2 = DynamicCast(&DAT_012007a0) != 0;
    const unsigned long activeFlags = renderFlags;
    bool opaque = (activeFlags & 0x4000) > 0;
    bool translucent = (activeFlags & 0x8000) > 0;
    bool blockedByEffect = (activeFlags & 0x10000) > 0;
    bool shadowPass;
    shadowPass = (activeFlags & 0x200) > 0;
    bool allowFirstPass = !((activeFlags & 0x100000) > 0) || DAT_011f91a7 != 0;
    bool specialBlend = (activeFlags & 0x40000) > 0;
    bool hasHighFlags = ((activeFlags & 0x4000000) > 0) || ((activeFlags & 0x8000000) > 0);
    bool lightingCondition;
    if ((geometry->state->flags & 1) == 0 &&
        (config->category34 == 2 || (4 & propertyFlags) > 0 || (propertyFlags & 2) > 0))
        lightingCondition = true;
    else
        lightingCondition = false;
    GeometryProperty* property = static_cast<GeometryProperty*>(geometry->GetProperty(0));
    bool extraLight = property && ((static_cast<unsigned char>(property->flags >> 9) & 1) != 0);
    bool useAlpha = (property && ((property->flags & 1) != 0)) || AlphaOrdered(alphaCutoff, 1.0f);
    if ((renderFlags & 0x20000) > 0)
    {
        if (DAT_011f9468 != 0.0f && DAT_011f9468 <= fade)
            addAdditional = false;
        else
            addAdditional = true;
        basePass = false;
    }
    else if (DAT_011f9460 != 0.0f && DAT_011f9460 <= fade)
    {
        addAdditional = false;
    }
    if (DAT_011f9458 != 0.0f && fade >= DAT_011f9458)
        basePass = false;
    DrawLight* primaryLight = GetDefaultLight();
    bool useAlternate = basePass && primaryLight->MatchesAlternate(&DAT_011f4998);
    if (useAlpha)
    {
        bool alphaFirst = true;
        if (shadowPass)
        {
            BSShaderProperty_AddPass_ZOnly(geometry, count, effectType, &alphaFirst, hasNoOverlay, extraLight);
            basePass = false;
        }
        needsShadow = true;
    }
    GenerateLightingPasses(geometry, passMask, count, effectType, hasNoBasePass, addAdditional, basePass, hasNoOverlay,
                           needsShadow, hasRenderContext, needsExtraPass, needsNormal, attr0, attr1, attr2, opaque,
                           translucent, blockedByEffect, allowFirstPass, specialBlend, hasHighFlags, lightingCondition,
                           extraLight, useAlpha, useAlternate, primaryLight);
}
}  // namespace fnv_00bdb4a0

namespace fnv_00bdf790 {

struct PGeom;
struct PLight;
struct PRenderer;
struct PNode;
struct PColor
{
    int unk000;
    int unk004;
    int unk008;
    bool FUN_00439090(const NiColor&);
    bool HasEqualComponents(const NiColor&);
};

extern NiColor DAT_011f4998;
struct PAlpha
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    unsigned short flags;
    unsigned short extra;
    unsigned char GetMode() const
    {
        return (flags >> 9) & 1;
    }
};
struct PData
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    void* value;
    int unk02c;
};
struct PMaterial
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    PColor color;
    PColor* alternate;
};
struct PGeom
{
    int unk000;
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
    PAlpha* alpha;
    int unk0a0;
    PMaterial* material;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    PData* data;
    int unk0bc;
    PAlpha* FUN_00a59d30(unsigned int);
};
struct PLight
{
    int unk000;
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
    bool special;
    char bED;
    short wEE;
};
struct PPass
{
    int unk000;
    unsigned short shader;
    unsigned char type;
    unsigned char extra;
    bool enabled;
    char b09;
    short w0A;
};
struct PArray
{
    int unk000;
    PPass** items;
    int unk008;
    int unk00c;
    unsigned int count;
    void Add(PGeom*, unsigned short, bool, unsigned char, PLight*, PLight*, PLight*, PLight*);
};
struct PState
{
    int unk000;
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
    void* scene;
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
    unsigned char mode;
    char b121;
    short w122;
};
struct PContext
{
    int unk000;
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
    PState* state;
};
struct PScene
{
    int unk000;
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
    void* colors;
};
struct PSceneColors
{
    int unk000;
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
    PColor diffuse;
    PColor ambient;
};
struct PRenderer
{
    int unk000;
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
    int mode;
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
    int extra;
};
struct PEffect
{
    int unk000;
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
    void* value;
};
struct PShader
{
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    unsigned int flags;
    unsigned int flags2;
    float alpha;
    float opacity;
    int unk030;
    float intensity;
    int unk038;
    PArray* passes;
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
    int* value;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    PEffect* effect;
    virtual void virtual00();
    virtual void virtual01();
    virtual void virtual02();
    virtual void virtual03();
    virtual void virtual04();
    virtual void virtual05();
    virtual void virtual06();
    virtual void virtual07();
    virtual void virtual08();
    virtual void virtual09();
    virtual void virtual0a();
    virtual void virtual0b();
    virtual void virtual0c();
    virtual void virtual0d();
    virtual void virtual0e();
    virtual void virtual0f();
    virtual void virtual10();
    virtual void virtual11();
    virtual void virtual12();
    virtual void virtual13();
    virtual void virtual14();
    virtual void virtual15();
    virtual void virtual16();
    virtual void virtual17();
    virtual void virtual18();
    virtual void virtual19();
    virtual void virtual1a();
    virtual void virtual1b();
    virtual void virtual1c();
    virtual void virtual1d();
    virtual void virtual1e();
    virtual void virtual1f();
    virtual void virtual20();
    virtual void virtual21();
    virtual void virtual22();
    virtual void virtual23();
    virtual void virtual24();
    virtual void virtual25();
    virtual void virtual26();
    virtual void virtual27();
    virtual void virtual28();
    virtual void virtual29();
    virtual void virtual2a();
    virtual void virtual2b();
    virtual void virtual2c();
    virtual void virtual2d();
    virtual void virtual2e();
    virtual void virtual2f();
    virtual void virtual30();
    virtual void virtual31();
    virtual void virtual32();
    virtual void virtual33();
    virtual void virtual34();
    virtual void virtual35();
    virtual void virtual36();
    virtual void virtual37();
    virtual void virtual38();
    virtual void virtual39();
    virtual void virtual3a();
    virtual void virtual3b();
    virtual void virtual3c();
    virtual void virtual3d();
    virtual void virtual3e();
    virtual void virtual3f();
    virtual void virtual40();
    virtual void virtual41();
    virtual void virtual42();
    virtual void virtual43();
    virtual void virtual44();
    virtual void fallback(PGeom*, int, unsigned short*, int, PRenderer*, unsigned char);
    void BSShaderPPLightingProperty_GetRenderPasses_2x(PGeom*, int, unsigned short*, int, PRenderer*, unsigned char);
    void* FUN_00653290(const void*);
    bool FUN_004a2020(unsigned int);
    bool IsSpecial() const
    {
        return (flags2 & 0x800000) > 0;
    }
    unsigned short BSShaderLightingProperty_GetNumberofActiveNonShadowLights();
    PLight* BSShaderLightingProperty_GetFirstActiveNonShadowLight(PNode**);
    PLight* BSShaderLightingProperty_GetNextActiveNonShadowLight(PNode**);
    PLight* FUN_00b70590(PNode**);
    PLight* BSShaderLightingProperty_GetNextActiveLight(PNode**);
    void BSShaderProperty_AddPass_ZOnly(PGeom*, unsigned short*, unsigned char, bool*, bool, bool);
    void BSShaderProperty_AddPass_ZOnly_TexEffect(PGeom*, unsigned short*, unsigned char, bool*, bool);
    void BSShaderProperty_AddPass_NormalsClear(PGeom*, unsigned short*, unsigned char, bool*, bool);
    void BSShaderProperty_AddPass_Normals(PGeom*, unsigned short*, unsigned char, bool*, bool, bool);
    void BSShaderProperty_AddPass_ADTS(PGeom*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool, bool, bool,
                      bool);
    void BSShaderProperty_AddPass_ADTS2(PGeom*, PLight*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool,
                      bool, bool, bool);
    void BSShaderProperty_AddPass_ADT(PGeom*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool, bool, bool,
                      bool, bool, bool, bool);
    void SelectTwoLightPass(PGeom*, PLight*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool,
                      bool, bool, bool);
    void BSShaderPPLightingProperty_AddPass_Opt(PGeom*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool);
    void BSShaderProperty_AddPass_AD2(PGeom*, PLight*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool,
                      bool, bool);
    void AddShadowPass(PGeom*, PLight*, PLight*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool,
                       bool, bool, bool);
    void BSShaderProperty_AddPass_Ambient(PGeom*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool);
    void BSShaderProperty_AddPass_DiffuseDirOrPoint(PGeom*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool);
    void BSShaderProperty_AddPass_DiffusePoint2(PGeom*, PLight*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool);
    void BSShaderProperty_AddPass_DiffusePoint3(PGeom*, PLight*, PLight*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool,
                      bool);
    void AddRenderPass(PGeom*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool, bool, bool,
                      bool);
    void BSShaderProperty_AddPass_Specular(PGeom*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool, bool);
    void BSShaderProperty_AddPass_SpecularPoint3(PGeom*, PLight*, PLight*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool);
    void BSShaderProperty_AddPass_SpecularPoint2(PGeom*, PLight*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool);
    void BSShaderProperty_AddPass_2X_EnvMap(PGeom*, PLight*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool);
    void BSShaderPPLightingProperty_AddLandscapePasses_2x(PGeom*, PLight*, unsigned short*, unsigned char, bool*, bool, bool);
    void BSShaderProperty_AddPass_Fog(PGeom*, unsigned short*, unsigned char, bool*, bool, bool, bool);
    void BSShaderProperty_AddPass_2x_TexEffect(PGeom*, unsigned short*, unsigned char, bool*, bool);
    void CreatePassMessage(PGeom*, unsigned short*, unsigned char, bool, bool);
    void AddAdditionalPass(PGeom*, unsigned short*, unsigned char, bool);
};
extern unsigned char DAT_011f9427;
extern int DAT_011f95e4;
extern unsigned char DAT_011f91d8;
extern int DAT_011f91c0;
extern float DAT_011fd890;
extern unsigned char DAT_011f91a7;
extern float DAT_011f9468, DAT_011f9460, DAT_011f9458;
extern unsigned int DAT_010a91d4;
extern char DAT_011f9422, DAT_011ad80d;
extern GlobalObjectO2_00a7b610 g_01200788, g_012024c8, g_012007a0;
PContext* __cdecl BSShaderManager_GetAccumulator();
bool __cdecl BSShaderManager_GetShadows();
// @fnv 0x00bdf790
// src: XBOX_PDB 0x00bdf790
void PShader::BSShaderPPLightingProperty_GetRenderPasses_2x(PGeom* geom, int renderFlags, unsigned short* count, int mode, PRenderer* renderer,
                           unsigned char passMode)
{
    bool diffusePass = (flags & 1) > 0;
    bool ambientPass = (flags & 0x80) > 0;
    bool projected = (flags & 0x20000) > 0;
    bool flag21 = (flags & 0x200000) > 0;
    bool skinned = (flags & 2) > 0;
    bool vertex = (flags & 0x20) > 0 || mode == 3;
    bool flag8 = (flags & 0x100) > 0;
    bool flag10 = (flags & 0x400) > 0;
    bool hasValue = (*value != 0) & !flag10;
    bool data = false;
    if (geom->data->value)
        data = true;
    data |= ((flags2 & 0x20) > 0);
    bool special = !DAT_011f9427 && DAT_011f95e4 && (DAT_011f91d8 & 0x20) && DAT_011f91c0 >= 2 &&
                   !((flags & 0x2000) > 0) && (unsigned int)DAT_011fd890 && BSShaderManager_GetAccumulator()->state->mode != 1 &&
                   BSShaderManager_GetAccumulator()->state->mode != 3;
    bool castA = FUN_00653290(&g_01200788) != 0;
    bool castB = FUN_00653290(&g_012024c8) != 0;
    bool castC = FUN_00653290(&g_012007a0) != 0;
    bool flag22 = (flags & 0x400000) > 0;
    bool flag11 = (flags & 0x800) > 0;
    bool flag12 = (flags & 0x1000) > 0;
    bool flag14 = (flags & 0x4000) > 0;
    bool flag15 = (flags & 0x8000) > 0;
    bool flag16 = (flags & 0x10000) > 0;
    bool flag9 = (flags & 0x200) > 0;
    bool enabled = !((flags & 0x100000) > 0) || DAT_011f91a7;
    bool flag18 = (flags & 0x40000) > 0;
    bool flag26 = (flags & 0x4000000) > 0 || (flags & 0x8000000) > 0;
    bool decal = !(geom->alpha->flags & 1) && (renderer->mode == 2 || (flags2 & 4) > 0 || (flags2 & 2) > 0);
    PAlpha** alphaPtr = &geom->alpha;
    PAlpha* alphaProp = geom->FUN_00a59d30(0);
    if (!alphaProp)
        alphaProp = alphaPtr ? *alphaPtr : 0;
    bool transparent = (alphaProp && (alphaProp->flags & 1)) || alpha < 1.0 || opacity < 1.0;
    bool alphaTest = alphaProp && (alphaProp->GetMode() != 0);
    if (alphaTest)
        flag8 = false;
    bool flag23 = IsSpecial();
    if (!flag23)
    {
        if (projected != flag23)
        {
            if (DAT_011f9468 != 0.0 && intensity >= DAT_011f9468)
                ambientPass = false;
            else
                ambientPass = true;
            diffusePass = false;
        }
        else if (DAT_011f9460 != 0.0 && intensity >= DAT_011f9460)
            ambientPass = false;
        if (DAT_011f9458 != 0.0 && intensity >= DAT_011f9458)
            diffusePass = false;
    }
    PScene* scene = (PScene*)BSShaderManager_GetAccumulator()->state->scene;
    PLight* sceneLight = (PLight*)scene;
    bool blackAmbient = diffusePass && ((PSceneColors*)scene->colors)->ambient.FUN_00439090(DAT_011f4998);
    bool first = true;
    if (transparent)
    {
        bool transparentFirst = true;
        if ((flag9 || opacity < 1.0) && !(alphaProp && (alphaProp->flags & 1)) && !((flags & 0x8000) > 0) &&
            !((flags & 0x10000) > 0))
        {
            BSShaderProperty_AddPass_ZOnly(geom, count, passMode, &transparentFirst, skinned, alphaTest);
            if (opacity < 1.0 || alpha < 1.0)
                passes->items[passes->count - 1]->type = 14;
            diffusePass = false;
        }
        vertex = true;
    }
    bool firstPass = true;
    if (effect && effect->value)
    {
        BSShaderProperty_AddPass_ZOnly_TexEffect(geom, count, passMode, &firstPass, skinned);
        passes->items[passes->count - 1]->type = 14;
    }
    unsigned short lightCount = BSShaderLightingProperty_GetNumberofActiveNonShadowLights();
    bool doBase = (renderFlags & 1) > 0;
    bool doDiffuse = (renderFlags & 2) > 0;
    bool doSpecular = (renderFlags & 4) > 0;
    bool doAmbient = (renderFlags & 8) > 0 && diffusePass;
    bool doAmbientExtra = ambientPass && (renderFlags & 8) > 0;
    first = true;
    bool allFlags = (DAT_010a91d4 & renderFlags) == DAT_010a91d4;
    unsigned short integerLightCount = lightCount;
    unsigned int remaining = lightCount;
    if (flag15 || flag16)
    {
        BSShaderProperty_AddPass_Normals(geom, count, passMode, &firstPass, skinned, flag16);
        passes->items[passes->count - 1]->type = 6;
        return;
    }
    if ((flags2 & 0x40) > 0)
    {
        BSShaderProperty_AddPass_NormalsClear(geom, count, passMode, &firstPass, skinned);
        passes->items[passes->count - 1]->type = 7;
    }
    if (castB || castC)
    {
        fallback(geom, renderFlags, count, renderer->extra, renderer, passMode);
        return;
    }
    PNode* lightPosition = 0;
    if (BSShaderManager_GetShadows() && !decal && !flag12)
    {
        PNode* activePosition = 0;
        PLight* light = FUN_00b70590(&activePosition);
        if (light)
        {
            do
            {
                if (light->special)
                {
                    passes->Add(geom, 0, true, 1, light, 0, 0, 0);
                    PPass* pass = passes->items[passes->count - 1];
                    int shader;
                    if (skinned)
                        shader = 0x232;
                    else if (flag14)
                        shader = 0x233;
                    else
                        shader = castA ? 0x234 : 0x231;
                    pass->shader = shader;
                    pass->enabled = true;
                }
                light = BSShaderLightingProperty_GetNextActiveLight(&activePosition);
            } while (light);
        }
    }
    if (!flag14)
    {
        if (enabled)
        {
            if (doBase)
            {
                if (!DAT_011f9422)
                {
                    if (!vertex && !transparent)
                    {
                        if (!doDiffuse)
                            goto baseOnly;
                        if (!doSpecular || flag8 || flag22)
                            goto standardBase;
                    }
                    if (lightCount <= 1 && blackAmbient && (lightCount == 0 || !special) && doAmbient && !flag10)
                        goto combinedAmbient;
                    if (!vertex || !(flag11 || flag18 || special || flag12 || castA || hasValue))
                        goto materialPass;
                    if (flag10)
                        goto combinedNormal;
                combinedAmbient:
                    if (doAmbient)
                    {
                        if (!lightCount)
                        {
                            BSShaderProperty_AddPass_ADTS(geom, sceneLight, count, passMode, &firstPass, skinned, hasValue, flag10,
                                         false, special, flag11, castA, flag18);
                        }
                        else
                        {
                            PLight* light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&lightPosition);
                            BSShaderProperty_AddPass_ADTS2(geom, sceneLight, light, count, passMode, &firstPass, skinned, hasValue,
                                         flag10, false, special, flag11, castA, flag18);
                        }
                        allFlags = false;
                        goto ambientExtra;
                    }
                combinedNormal:
                    if (lightCount == 0)
                    {
                        BSShaderProperty_AddPass_ADT(geom, sceneLight, count, passMode, &firstPass, skinned, hasValue, flag10, false,
                                     special, flag11, flag12, castA, flag22, flag18, alphaTest);
                    }
                    else
                    {
                        PLight* light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&lightPosition);
                        SelectTwoLightPass(geom, sceneLight, light, count, passMode, &firstPass, skinned, hasValue, flag10,
                                     false, special, flag11, castA, flag18);
                    }
                    allFlags = false;
                    goto ambientExtra;
                materialPass:
                    int extraPass = 1;
                    PMaterial* material = geom->material;
                    if (!DAT_011ad80d ||
                        (material &&
                         !(material->alternate ? material->alternate : &material->color)->HasEqualComponents(DAT_011f4998)) ||
                        ((PSceneColors*)scene->colors)->diffuse.FUN_00439090(DAT_011f4998) || !FUN_004a2020(0x25) ||
                        (alphaProp && (alphaProp->GetMode() != 0) && opacity < 1.0) || FUN_004a2020(0x1a) ||
                        FUN_004a2020(0x1b) || FUN_004a2020(7) || FUN_004a2020(0x15) || FUN_004a2020(0x11) ||
                        geom->unk0bc)
                        extraPass = 0;
                    if (vertex || (((integerLightCount <= extraPass + 5 && !doAmbient && !flag10) ||
                                    (integerLightCount <= extraPass + 4 && !doAmbient && flag10) ||
                                    (integerLightCount <= extraPass + 2 && doAmbient && !flag10)) &&
                                   (lightCount > 1 || diffusePass) && !flag11 && !flag18 && !special && !flag12 &&
                                   !castA && !hasValue))
                    {
                        BSShaderPPLightingProperty_AddPass_Opt(geom, sceneLight, count, passMode, &firstPass, skinned, hasValue, doAmbient,
                                     flag10, extraPass != 0);
                        allFlags = false;
                        goto ambientExtra;
                    }
                }
            standardBase:
                if (doDiffuse)
                {
                    unsigned char globalMode = DAT_011f9427;
                    if (doSpecular && (!flag10 || !globalMode) && (lightCount <= 1 || vertex))
                    {
                        if (!lightCount)
                        {
                            BSShaderProperty_AddPass_ADT(geom, sceneLight, count, passMode, &firstPass, skinned, hasValue, flag10,
                                         false, special, flag11, flag12, castA, flag22, flag18, alphaTest);
                        }
                        else
                        {
                            PLight* light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&lightPosition);
                            SelectTwoLightPass(geom, sceneLight, light, count, passMode, &firstPass, skinned, hasValue,
                                         flag10, false, special, flag11, castA, flag18);
                        }
                        if (doAmbient)
                            goto ambientLighting;
                        allFlags = false;
                        goto ambientExtra;
                    }
                    if (!flag10 || !globalMode)
                    {
                        if (lightCount <= 1)
                        {
                            PLight* light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&lightPosition);
                            BSShaderProperty_AddPass_AD2(geom, sceneLight, light, count, passMode, &firstPass, skinned, hasValue,
                                         flag10, false, special, flag11, castA);
                            remaining = 0;
                        }
                        else
                        {
                            PLight* light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&lightPosition);
                            PLight* light2 = BSShaderLightingProperty_GetNextActiveNonShadowLight(&lightPosition);
                            AddShadowPass(geom, sceneLight, light, light2, count, passMode, &firstPass, skinned,
                                          hasValue, flag10, false, special, flag11, castA);
                            remaining -= 2;
                        }
                        first = false;
                        goto diffuseLighting;
                    }
                }
            baseOnly:
                BSShaderProperty_AddPass_Ambient(geom, sceneLight, count, passMode, &firstPass, skinned, alphaTest, hasValue, castA);
            }
        diffuseLighting:
            if (doDiffuse)
            {
                PLight* light;
                if (first)
                {
                    BSShaderProperty_AddPass_DiffuseDirOrPoint(geom, sceneLight, count, passMode, &firstPass, skinned, false, false, castA);
                    light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&lightPosition);
                }
                else
                    light = BSShaderLightingProperty_GetNextActiveNonShadowLight(&lightPosition);
                while (light)
                {
                    if (remaining <= 2)
                    {
                        PLight* light2 = BSShaderLightingProperty_GetNextActiveNonShadowLight(&lightPosition);
                        BSShaderProperty_AddPass_DiffusePoint2(geom, light, light2, count, passMode, &firstPass, skinned, flag10, false, flag11,
                                     castA);
                        if (remaining <= 1)
                            remaining = 0;
                        else
                            remaining -= 2;
                    }
                    else
                    {
                        PLight* light2 = BSShaderLightingProperty_GetNextActiveNonShadowLight(&lightPosition);
                        PLight* light3 = BSShaderLightingProperty_GetNextActiveNonShadowLight(&lightPosition);
                        BSShaderProperty_AddPass_DiffusePoint3(geom, light, light2, light3, count, passMode, &firstPass, skinned, flag10, false,
                                     flag11, castA);
                        remaining -= 3;
                    }
                    light = BSShaderLightingProperty_GetNextActiveNonShadowLight(&lightPosition);
                }
            }
            if (doSpecular)
                AddRenderPass(geom, sceneLight, count, passMode, &firstPass, skinned, false, flag10, data, castA, false,
                             flag11, flag18);
            if (doAmbient)
            {
            ambientLighting:
                int ambientRemaining = integerLightCount;
                if (blackAmbient)
                    BSShaderProperty_AddPass_Specular(geom, sceneLight, count, passMode, &firstPass, skinned, false, special, flag11, castA,
                                 flag18);
                PLight* light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&lightPosition);
                while (light)
                {
                    if (ambientRemaining > 2)
                    {
                        PLight* light2 = BSShaderLightingProperty_GetNextActiveNonShadowLight(&lightPosition);
                        PLight* light3 = BSShaderLightingProperty_GetNextActiveNonShadowLight(&lightPosition);
                        BSShaderProperty_AddPass_SpecularPoint3(geom, light, light2, light3, count, passMode, &firstPass, skinned, flag11, castA,
                                     flag18);
                        ambientRemaining -= 3;
                    }
                    else if (ambientRemaining > 1)
                    {
                        PLight* light2 = BSShaderLightingProperty_GetNextActiveNonShadowLight(&lightPosition);
                        BSShaderProperty_AddPass_SpecularPoint2(geom, light, light2, count, passMode, &firstPass, skinned, flag11, castA, flag18);
                        ambientRemaining -= 2;
                    }
                    else if (ambientRemaining > 0)
                    {
                        BSShaderProperty_AddPass_Specular(geom, light, count, passMode, &firstPass, skinned, false, special, flag11, castA,
                                     flag18);
                        --ambientRemaining;
                    }
                    light = BSShaderLightingProperty_GetNextActiveNonShadowLight(&lightPosition);
                }
            }
        ambientExtra:
            if (doAmbientExtra)
            {
                PLight* light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&lightPosition);
                BSShaderProperty_AddPass_2X_EnvMap(geom, sceneLight, light, count, passMode, &firstPass, skinned, projected, flag21);
                goto extraPass;
            }
        }
    }
    else
    {
        BSShaderPPLightingProperty_AddLandscapePasses_2x(geom, sceneLight, count, passMode, &firstPass, diffusePass, special);
    }
afterLighting:
    if (!allFlags)
    {
        if (passes->count && !flag14)
        {
            PPass* pass = passes->items[passes->count - 1];
            if (pass->shader != 0x252 && pass->shader != 0x254)
                pass->enabled = true;
        }
    }
    else if (!flag14)
    {
    extraPass:
        BSShaderProperty_AddPass_Fog(geom, count, passMode, &firstPass, skinned, castA, transparent);
    }
    if (effect)
    {
        BSShaderProperty_AddPass_2x_TexEffect(geom, count, passMode, &firstPass, skinned);
        passes->items[passes->count - 1]->type = 1;
    }
    if (DAT_011f9422)
    {
        if (renderFlags & 1)
            CreatePassMessage(geom, count, passMode, skinned, hasValue);
        if (!castA && !flag22 && !flag11 && !flag12 && !flag14 && !flag18)
            AddAdditionalPass(geom, count, passMode, skinned);
    }
    unsigned int passType = 0;
    if (decal)
        passType = 10;
    else if (flag26)
        passType = 4;
    else if (transparent)
        passType = opacity < 1.0 ? 14 : 1;
    if (passes)
    {
        for (unsigned int iPass = 0; iPass < passes->count; ++iPass)
            if (!passes->items[iPass]->type)
                passes->items[iPass]->type = passType;
    }
}
}  // namespace fnv_00bdf790

extern "C" int __cdecl rand(void);
extern "C" double __cdecl fabs(double);

inline void BoltScale(float& x, float& y, double s)
{
    x *= s;
    y *= s;
}
struct BoltDirection : public LocalVec3
{
    void Unitize_004a0c10();
};

struct Point4
{
    float x, y, z, w;
};
struct ShellBC
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    Point4* points;
    float unk64;
    int unk68;
    float unk6c;
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
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    float unk130;
    float unk134;
    int unk138;
    int unk13c;
    int unk140;
    float unk144;
    float unk148;
    void BoltShaderProperty_CreateSegment(int row, int col, int previous, int next);
};
// Computes points[row*width+col] from the previous point plus a scaled direction and random x/z jitter, then pulls its x/z toward a target when beyond unk130.
// @fnv 0x00bc20a0
// src: XBOX_PDB 0x00bc20a0
void ShellBC::BoltShaderProperty_CreateSegment(int row, int col, int previous, int next)
{
    int index = row * unk140 + col;
    Point4 a = points[row * unk140 + previous];
    int width = unk140;
    Point4 b = points[row * width + next];
    BoltDirection dir;
    dir.x = a.x - b.x;
    dir.y = a.y - b.y;
    dir.z = a.z - b.z;
    if (dir.y < 0.0f)
        memcpy(&dir, &NiPoint3_ZERO, sizeof(NiPoint3));
    dir.y += 1.0;
    dir.Unitize_004a0c10();
    float speed = unk144;
    dir.x *= speed;
    dir.y *= speed;
    dir.z *= speed;
    float ratio = (float)col / width;
    float random = (float)(rand() / 32767.0);
    points[index].x = (float)(dir.x + a.x + unk148 * random - unk148 * 0.5);
    points[index].y = dir.y + a.y;
    random = (float)(rand() / 32767.0);
    points[index].z = (float)(dir.z + a.z + unk148 * random - unk148 * 0.5);
    dir.x = unk64 * ratio - points[index].x;
    dir.y = unk6c * ratio - points[index].z;
    volatile float root = (float)sqrt((float)(dir.x * dir.x + dir.y * dir.y));
    float len = root;
    if (len > unk130)
    {
        double delta = len - unk130;
        double length = len;
        double scale = (float)(unk134 * delta / length);
        if ((float)fabs((float)(scale * length)) > unk130)
            scale = (float)(delta / length);
        BoltScale(dir.x, dir.y, scale);
        points[index].x += dir.x;
        points[index].z += dir.y;
    }
}

struct FUN_00bd44c0 : NiMemObject
{
    static void operator delete(void* pvMem);
    FUN_00bd44c0(NiD3DShaderDeclaration* apDecl);
    virtual ~FUN_00bd44c0();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void UseShaderDeclaration(NiD3DShaderDeclaration* apDecl);
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
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
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
};
// Creates an NiD3DShaderDeclaration via FUN_00e76700 with fixed SetEntry/SetEntryAlt entries, wraps it in a FUN_00bd44c0, calls setup methods and returns it.
// @fnv 0x00bd4750
// src: XBOX_PDB 0x00bd4750
FUN_00bd44c0* SpeedTreeBranchShader_CreateShader()
{
    NiD3DShaderDeclaration* pDecl = (NiD3DShaderDeclaration*)NiDX9ShaderDeclaration_Create(DAT_011f9508, 6, 1);
    pDecl->SetEntry(0, 0, (NiShaderDeclaration::ShaderParameter)0, (NiShaderDeclaration::ShaderParameterType)2, 0);
    pDecl->SetEntry(1, 3, (NiShaderDeclaration::ShaderParameter)3, (NiShaderDeclaration::ShaderParameterType)2, 0);
    pDecl->SetEntry(2, 7, (NiShaderDeclaration::ShaderParameter)5, (NiShaderDeclaration::ShaderParameterType)1, 0);
    pDecl->SetEntry(3, 0xe, (NiShaderDeclaration::ShaderParameter)0xd, (NiShaderDeclaration::ShaderParameterType)2, 0);
    pDecl->SetEntry(4, 0xf, (NiShaderDeclaration::ShaderParameter)0xe, (NiShaderDeclaration::ShaderParameterType)2, 0);
    pDecl->SetEntryAlt(0, 5, 0xa, (NiShaderDeclaration::ShaderParameter)0x80000000, (NiShaderDeclaration::ShaderParameterType)3, (NiShaderDeclaration::ShaderParameterUsage)2, 0, (NiShaderDeclaration::ShaderParameterTesselator)0);
    pDecl->GetD3DDeclaration();
    FUN_00bd44c0* pShader = new FUN_00bd44c0(pDecl);
    pShader->Unk_13();
    pShader->Unk_51();
    pShader->Unk_54();
    pShader->Unk_47();
    pShader->UseShaderDeclaration(pDecl);
    return pShader;
}

struct RemovalOwnerBd8670 : FUN_00bd85b0_cls
{
    __declspec(noinline) int RemoveEntry(unsigned short index);
};

int RemovalOwnerBd8670::RemoveEntry(unsigned short index)
{
    if (index < m_uiItemCount)
    {
        if (index != m_uiItemCount - 1)
        {
            m_pEntries[index] = m_pEntries[m_uiItemCount - 1];
            m_pKeys[index] = m_pKeys[m_uiItemCount - 1];
        }
        m_pEntries[m_uiItemCount - 1].m_f00 = 0.0f;
        m_pEntries[m_uiItemCount - 1].m_f04 = 0.0f;
        m_pEntries[m_uiItemCount - 1].m_f08 = DAT_0104eb20;
        m_pEntries[m_uiItemCount - 1].m_f0C = 0.0f;
        m_pKeys[m_uiItemCount - 1] = 0;
        m_uiItemCount--;
        DAT_011f9ef8--;
    }
    return m_uiItemCount;
}

struct Owner_bd8670 : RemovalOwnerBd8670
{
    int TallGrassGroup_RemoveTerrainChunk(unsigned int key);
};

// @fnv 0x00bd8670
// src: COMMUNITY 0x00bd8670
int Owner_bd8670::TallGrassGroup_RemoveTerrainChunk(unsigned int key)
{
    for (int i = m_uiItemCount - 1; i >= 0; i--)
    {
        if (key == m_pKeys[i])
            RemoveEntry(i);
    }
    return m_uiItemCount;
}

struct SingleLightPassSelector : Shader_00bd9540
{
    int BSShaderProperty_AddPass_SpecularAmbientDirPoint(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count, unsigned char type,
                     bool* enabled, bool a, bool b, bool c, bool d, bool e, bool f);
};

// If type is 1, adds a pass to pPasses with id 0x154-0x157 chosen by a and b; otherwise increments *count; then clears *enabled and returns 0.
// @fnv 0x00bd99c0
// src: COMMUNITY 0x00bd99c0
int SingleLightPassSelector::BSShaderProperty_AddPass_SpecularAmbientDirPoint(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count,
                                          unsigned char type, bool* enabled, bool a, bool b, bool c, bool d, bool e,
                                          bool f)
{
    if (!a)
    {
        if (!b)
        {
            if (type == 1)
                pPasses->Add(geom, 0x154, *enabled, 1, light, 0, 0, 0);
            else
                ++*count;
        }
        else
        {
            if (type == 1)
                pPasses->Add(geom, 0x155, *enabled, 1, light, 0, 0, 0);
            else
                ++*count;
        }
    }
    else
    {
        if (!b)
        {
            if (type == 1)
                pPasses->Add(geom, 0x156, *enabled, 1, light, 0, 0, 0);
            else
                ++*count;
        }
        else
        {
            if (type == 1)
                pPasses->Add(geom, 0x157, *enabled, 1, light, 0, 0, 0);
            else
                ++*count;
        }
    }
    *enabled = false;
    return 0;
}

extern int DAT_01201f64;
__declspec(noinline) void __cdecl BoltShader_ClearSegmentIndexArray();

struct PoolFreeStandIn
{
    void MemoryManager_Deallocate(void* p);
};

class FUN_00bc1fa0 : public BSShaderProperty
{
  public:
    virtual ~FUN_00bc1fa0();
    void* m_p60;
};

// Frees the m_p60 resource via the pool and calls FUN_00bc0c50 when the global count DAT_01201f64 reaches zero.
// @fnv 0x00bc1fa0
FUN_00bc1fa0::~FUN_00bc1fa0()
{
    reinterpret_cast<PoolFreeStandIn*>(&DAT_011f6238)->MemoryManager_Deallocate(m_p60);
    if (--DAT_01201f64 == 0)
        BoltShader_ClearSegmentIndexArray();
}

struct BSMaterialEmittanceMultController : NiFloatInterpController
{
};

// Allocates and returns a new BSMaterialEmittanceMultController instance.
// @fnv 0x00bc3190
// src: EXE 0x00bc3190
BSMaterialEmittanceMultController* BSMaterialEmittanceMultController_CreateObject()
{
    return new BSMaterialEmittanceMultController;
}

struct ParticleBound
{
    NiPoint3 center;
    float radius;
};
struct ParticleRTTI
{
    const char* name;
    const ParticleRTTI* base;
};
class ParticleNiObject
{
  public:
    virtual void Method00();
    virtual void Method01();
    virtual const ParticleRTTI* GetRTTI();
    virtual void Method03();
    virtual void Method04();
    virtual void Method05();
    virtual void Method06();
    virtual void Method07();
    virtual void Method08();
    virtual void Method09();
    virtual void Method10();
    virtual void Method11();
    virtual void Method12();
    virtual void Method13();
    virtual void Method14();
    virtual void Method15();
    virtual void Method16();
    virtual void Method17();
    virtual void Method18();
    virtual void Method19();
    virtual void Method20();
    virtual void Method21();
    virtual void Method22();
    virtual void Method23();
    virtual void Method24();
    virtual void Method25();
    virtual void Method26();
    virtual void Method27();
    virtual void Method28();
    virtual void Method29();
    virtual void Method30();
    virtual void Method31();
    virtual void Method32();
    virtual void Method33();
    virtual void Method34();
    virtual void Method35();
    virtual void Method36();
    virtual void Method37();
    virtual void Method38();
    virtual void Method39();
    virtual void Method40();
    virtual void Method41();
    virtual void Method42();
    virtual void Method43();
    virtual void Method44();
    virtual void Method45();
    virtual void Method46();
    virtual void Method47();
    virtual void Method48();
    virtual void Method49();
    virtual void Method50();
    virtual void Method51();
    virtual void Method52();
    virtual void Method53();
    virtual void Method54();
    virtual void Method55();
    virtual void Method56();
    virtual void Method57();
    virtual void Method58();
    virtual void Method59();
    virtual void Method60();
    virtual void Method61();
    virtual void Method62();
    virtual void SetObjectBound(ParticleBound bound);
    virtual void SetCount(unsigned short count);
    ParticleNiObject* DynamicCast(const void* type);
    bool IsKindOfType(const ParticleRTTI* desired) const
    {
        const ParticleRTTI* type = const_cast<ParticleNiObject*>(this)->GetRTTI();
        while (type)
        {
            if (type == desired)
                return true;
            type = type->base;
        }
        return false;
    }
};
extern GlobalObjectO2_00a7b610 g_012024b8;
extern GlobalObjectO2_00a7b610 g_012024c0;
struct BoundDataBlock
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    float radius;
};
inline float m_kBoundMin(float a, float b)
{
    return a < b ? a : b;
}
inline float m_kBoundMax(float a, float b)
{
    return a > b ? a : b;
}
// Computes a bounding sphere from m_kFloatData positions (skipping z <= -2147483648.0f) and passes it to unk00's SetObjectBound and SetCount.
// @fnv 0x00bd5e40
// src: COMMUNITY 0x00bd5e40
void S_00bd6150_Foo::DistantLODGroup_UpdateGroupBound()
{
    float limit = 5000000000.0f;
    if (m_uiItemCount == 0)
        limit = 0.0f;
    NiPoint3 minimum(limit, limit, limit);
    NiPoint3 maximum(-limit, -limit, -limit);
    for (int i = 0; i < m_uiItemCount; ++i)
    {
        float* position = m_kFloatData + 4 * i;
        if (position[2] > -2147483648.0f)
        {
            minimum.x = m_kBoundMin(minimum.x, position[0]);
            maximum.x = m_kBoundMax(maximum.x, position[0]);
            minimum.y = m_kBoundMin(minimum.y, position[1]);
            maximum.y = m_kBoundMax(maximum.y, position[1]);
            minimum.z = m_kBoundMin(minimum.z, position[2]);
            maximum.z = m_kBoundMax(maximum.z, position[2]);
        }
    }
    BoundDataBlock* data = (BoundDataBlock*)unk04;
    if (data)
    {
        ParticleNiObject* object = (ParticleNiObject*)unk00;
        if (object)
        {
            NiPoint3 difference = maximum - minimum;
            NiPoint3 upper = maximum;
            maximum = difference * 0.5f;
            minimum = minimum + maximum;
            difference = upper - minimum;
            ParticleBound bound;
            bound.center = minimum;
            bound.radius = difference.Length() + data->radius;
            bool compatible = object->IsKindOfType((const ParticleRTTI*)&g_012024c0);
            ParticleNiObject* geometry = compatible ? object : 0;
            if (geometry)
            {
                geometry->SetObjectBound(bound);
                geometry->SetCount(m_uiItemCount);
            }
            else
            {
                object = (ParticleNiObject*)unk00;
                geometry = object ? object->DynamicCast(&g_012024b8) : 0;
                if (geometry)
                {
                    geometry->SetObjectBound(bound);
                    geometry->SetCount(m_uiItemCount);
                }
            }
        }
    }
}

namespace EffectCleanupBD6 {

}
template <class T, class TAlloc> inline NiTArray<T, TAlloc>::~NiTArray()
{
        NiFree(m_pBase);
    }
namespace EffectCleanupBD6 {


class __declspec(novtable) FUN_00bd6f30 : public ImageSpaceEffect
{
  public:
    virtual ~FUN_00bd6f30();
    NiTArray<int, NiTMallocInterface<int> > m_kValues;
};

// Destructor for the ImageSpaceEffect subclass that owns a NiTArray<int, NiTMallocInterface<int> > of values; the base ImageSpaceEffect destructor handles the remaining cleanup.
// @fnv 0x00bd6f30
FUN_00bd6f30::~FUN_00bd6f30()
{}

}

namespace fnv_00bc1d40 {
#include <stdlib.h>

extern int DAT_011ae61c;
extern int DAT_01201f64;
void __cdecl GetOrCreateTable();
__declspec(noinline) unsigned int __cdecl BoltShader_GetMaxSegments();

struct C04Vec
{
    float x, y, z;
    C04Vec() {}
    C04Vec(float a, float b, float c) : x(a), y(b), z(c)
    {}
};
void* __cdecl _fnv_zlib_memset(void*, int, unsigned int);
struct FUN_00bc1d40 : BSShaderProperty
{
    ShaderVector4* field060;
    C04Vec position;
    float field070;
    int field074;
    int field078;
    int field07c;
    int field080;
    float field084;
    float randomValues[40];
    int field128;
    float field12c;
    float field130;
    float field134;
    float field138;
    float field13c;
    int field140;
    float field144;
    float field148;
    int field14c;
    float field150;

    NiColorA color154, color164;
    unsigned char flag174, flag175, flag176, flag177;
    int field178;
    int field17c;
    float field180;
    int field184;
    int field188;
    float field18c;
    FUN_00bc1d40();
    virtual ~FUN_00bc1d40();
};
// Initializes fields, allocates and zeroes a ShaderVector4 array sized by FUN_00bc0b40(), fills randomValues with rand()/32767.0, and increments DAT_01201f64.
// @fnv 0x00bc1d40
FUN_00bc1d40::FUN_00bc1d40()
{
    field084 = 0;
    field080 = 0;
    field180 = 0;
    field184 = 0;
    field070 = 0;
    field078 = 0;
    field07c = 0;
    C04Vec initialPosition(0, field12c, 0);
    flag174 = 0;
    flag176 = 1;
    flag177 = 1;
    position = initialPosition;
    field074 = 4;
    field140 = BoltShader_GetMaxSegments();
    field144 = 1;
    field148 = 1;
    field14c = DAT_011ae61c;
    field150 = 1;
    field128 = 1;
    field12c = 2048.0f;
    field130 = 100.0f;
    field134 = 3.0f;
    field138 = 3.0f;
    field13c = 1;
    field188 = 0;
    color154 = *(NiColorA*)&DAT_011a9be0;
    color164 = *(NiColorA*)&DAT_011a9be0;
    flag175 = 1;
    GetOrCreateTable();
    field178 = 0;
    unsigned int count = BoltShader_GetMaxSegments();
    field060 = (ShaderVector4*)new (DAT_011f6238) unsigned char[count][sizeof(ShaderVector4)];
    _fnv_zlib_memset(field060, 0, count * sizeof(ShaderVector4));
    for (unsigned int i = 0; i < 40; ++i)
        randomValues[i] = rand() / 32767.0;
    ++DAT_01201f64;
    field188 = 0;
    field18c = 1;
    iShader = 25;
    iShaderPropertyType = 15;
}
}  // namespace fnv_00bc1d40
