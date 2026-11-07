
// src/bsshader/particleshaderproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/particleshaderproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/MemoryManager.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiNode.h"
#include "../../include/NiColorA.h"

inline NiPoint3::NiPoint3(float fX, float fY, float fZ)
{
    x = fX;
    y = fY;
    z = fZ;
}
inline void NiPoint3::Set(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
}
inline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(x * scalar, y * scalar, z * scalar);
}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& kRhs) const
{
    return NiPoint3(x - kRhs.x, y - kRhs.y, z - kRhs.z);
}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& kRhs) const
{
    return NiPoint3(x + kRhs.x, y + kRhs.y, z + kRhs.z);
}

extern int g_01200434;

// @fnv 0x00ba7f10
// src: XBOX_PDB 0x00ba7f10
int& __cdecl ParticleShaderProperty_GetRTTI()
{
    return g_01200434;
}

#include "../../include/NiTPrimitiveArray.h"
struct BaseStr
{
    void WriteToSettingArray(NiTPrimitiveArray<char*>*);
};
struct ParticleShaderProperty : BaseStr
{
    void GetViewerStrings_00ba7f20(NiTPrimitiveArray<char*>*);
};
char* __cdecl _FUN_00a7d330(const char*);
// @fnv 0x00ba7f20
// src: XBOX_PDB 0x00ba7f20
void ParticleShaderProperty::GetViewerStrings_00ba7f20(NiTPrimitiveArray<char*>* apStrings)
{
    WriteToSettingArray(apStrings);
    char* str = _FUN_00a7d330((const char*)g_01200434);
    unsigned int size = *(unsigned short*)((char*)apStrings + 0xA);
    if (size >= *(unsigned short*)((char*)apStrings + 8))
        apStrings->SetSize(size + *(unsigned short*)((char*)apStrings + 0xE));
    apStrings->SetAt(size, str);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern int DAT_0101fbcc;
extern int DAT_01016ca4;
extern int DAT_01200424;
char** __cdecl NiTObjectArray_NiPointer_NiTexture_NiTObjectArray_NiPointer_NiTexture(unsigned int);
int __cdecl GetFloatQuadTable();
void* _fnv_zlib_memset(void*, int, unsigned int);
extern MemoryManager g_memoryManager;
struct ParticleShader
{
    static unsigned int __cdecl GetShaderParticleCount();
};
inline NiColorA::NiColorA(float fR, float fG, float fB, float fA)
{
    r = fR;
    g = fG;
    b = fB;
    a = fA;
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
        DeleteThis();
}
inline void NiNode::DecRefCount()
{
    if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
        DeleteThis();
}
template <class T> inline NiPointer<T>::NiPointer()
{
    m_pObject = 0;
}
template <class T> inline NiPointer<T>::NiPointer(T* pObject)
{
    m_pObject = pObject;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pObject)
{
    if (m_pObject != pObject)
    {
        if (pObject != 0)
            pObject->IncRefCount();
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pObject;
    }
    return *this;
}
struct GlobalObject_004aff00
{
    const void* vt;
    char** m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    GlobalObject_004aff00(unsigned int uiMaxSize, unsigned int uiGrowBy)
    {
        vt = &DAT_0101fbcc;
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = NiTObjectArray_NiPointer_NiTexture_NiTObjectArray_NiPointer_NiTexture(m_usMaxSize);
        else
            m_pBase = 0;
    }
    ~GlobalObject_004aff00();
    void RemoveAll();
};
struct PrimArray : GlobalObject_004aff00
{
    PrimArray(unsigned int uiMaxSize, unsigned int uiGrowBy) : GlobalObject_004aff00(uiMaxSize, uiGrowBy)
    {
        vt = &DAT_01016ca4;
    }
};
struct BoundDataBlock
{
    char data[0x30];
    static void* operator new[](unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
};
struct FUN_00ba8e50
{
    FUN_00ba8e50();
    ~FUN_00ba8e50();
    virtual void vf0();
    char pad[0x5c];
};
struct FUN_00ba7f70 : FUN_00ba8e50
{
    BoundDataBlock* pParticles;                // 0x60
    int m_iParticleDataValue;                  // 0x64
    float m_fParticleParameter1;               // 0x68
    bool m_bParticleEnabled;                   // 0x6c
    int iParticleCount;                        // 0x70
    float m_fParticleParameter3;               // 0x74
    float m_fParticleParameter4;               // 0x78
    float m_fParticleParameter5;               // 0x7c
    float m_fParticleParameter6;               // 0x80
    float m_fParticleParameter7;               // 0x84
    float m_fParticleParameter8;               // 0x88
    float m_fParticleParameter2;               // 0x8c
    NiPoint3 Velocity;                         // 0x90
    NiPoint3 Acceleration;                     // 0x9c
    float m_fRotation;                         // 0xa8
    float m_fParticleParameter9;               // 0xac
    float m_fParticleParameter10;              // 0xb0
    float m_fParticleParameter11;              // 0xb4
    float fUnkB8, fUnkBC, fUnkC0;              // 0xb8
    NiColorA Color1;                          // 0xc4
    NiColorA Color2;                          // 0xd4
    NiColorA Color3;                          // 0xe4
    float fUnkF4, fUnkF8, fUnkFC, fUnk100;     // 0xf4
    float fScaleTime;                          // 0x104
    float fUnk108, fUnk10C, fUnk110, fUnk114;  // 0x108
    NiPointer<NiRefObject> spRetainedObject;   // 0x118
    PrimArray kArray;                          // 0x11c
    void* pParticleBuffer;                     // 0x12c
    float fAlpha;                              // 0x130
    float m_fParticleParameter12;              // 0x134
    float m_fParticleParameter13;              // 0x138
    NiPoint3 m_vecParticlePosition;            // 0x13c
    float fUnk148;                             // 0x148
    FUN_00ba7f70();
};
// Initialises particle system fields to defaults, clears kArray, allocates pParticles for the shader's particle count and zeroes it.
// @fnv 0x00ba7f70
FUN_00ba7f70::FUN_00ba7f70() : spRetainedObject(0), kArray(10, 10)
{
    spRetainedObject = 0;
    iParticleCount = 0;
    m_fParticleParameter3 = 0.0f;
    m_iParticleDataValue = 0;
    m_bParticleEnabled = true;
    m_fParticleParameter4 = 1.0f;
    fScaleTime = 0.0f;
    m_fParticleParameter5 = 0.0f;
    m_fParticleParameter6 = 0.0f;
    m_fParticleParameter7 = 0.0f;
    m_fParticleParameter2 = 0.0f;
    Velocity = NiPoint3(0.0f, 0.0f, 0.0f);
    Acceleration = NiPoint3(0.0f, 0.0f, 0.0f);
    m_fParticleParameter8 = 0.0f;
    m_fRotation = 0.0f;
    m_fParticleParameter9 = 0.0f;
    m_fParticleParameter10 = 0.0f;
    m_fParticleParameter11 = 0.0f;
    Color1 = NiColorA(0.0f, 0.0f, 0.0f, 0.0f);
    Color2 = NiColorA(0.0f, 0.0f, 0.0f, 0.0f);
    Color3 = NiColorA(0.0f, 0.0f, 0.0f, 0.0f);
    fAlpha = 1.0f;
    m_fParticleParameter12 = 1.0f;
    m_fParticleParameter13 = 1.0f;
    m_vecParticlePosition = NiPoint3(0.0f, 0.0f, 0.0f);
    fUnk148 = 0.0f;
    kArray.RemoveAll();
    GetFloatQuadTable();
    pParticleBuffer = 0;
    unsigned int iparticleCount = ParticleShader::GetShaderParticleCount();
    pParticles = new BoundDataBlock[iparticleCount];
    _fnv_zlib_memset(pParticles, 0, iparticleCount * sizeof(BoundDataBlock));
    ++DAT_01200424;
    *(int*)((char*)this + 0x58) = 0x18;
    *(int*)((char*)this + 0x1c) = 0x11;
}

struct Particle
{
    float m_fFirstFloatValue;
    float unk04;
    float unk08;
    float fTime;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
};

struct ParticleSystemBase
{
    virtual void vf0();
};

struct ParticleEmitter : ParticleSystemBase
{
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
    Particle* pParticles;
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
    float fScaleTime;

    int GetParticleCount();
    void AdvanceParticleTimes(float fTime);
};

// @fnv 0x00ba6cf0
void ParticleEmitter::AdvanceParticleTimes(float fTime)
{
    float fTimeSinceScaleStart = fTime - fScaleTime;
    int iCount = GetParticleCount();
    for (int i = 0; i < iCount; i++)
    {
        if (pParticles[i].m_fFirstFloatValue != 3.402823466385288598e+38)
            pParticles[i].fTime += fTimeSinceScaleStart;
    }
    fScaleTime = fTime;
}

extern int DAT_011f6238;
extern int DAT_01200420;
unsigned int __cdecl FUN_00ba52d0();

struct FloatQuad
{
    float v;

    static void* operator new[](unsigned int uiSize)
    {
        return reinterpret_cast<MemoryManager*>(&DAT_011f6238)->Game_DoHeapAlloc(uiSize);
    }
};

// @fnv 0x00ba73a0
int __cdecl GetFloatQuadTable()
{
    char** ppTable = reinterpret_cast<char**>(&DAT_01200420);
    if (*ppTable != 0)
        return (int)*ppTable;

    unsigned int uiQuadCount = FUN_00ba52d0();
    char* pBase = (char*)new FloatQuad[uiQuadCount * 4];
    unsigned int i = 0;
    *ppTable = pBase;

    if (uiQuadCount > 0)
    {
        char* p = pBase + 8;
        do
        {
            float fIndexValue = (float)i;
            float* pQuad = (float*)(p - 8);
            pQuad[0] = fIndexValue;
            pQuad[1] = fIndexValue;
            pQuad[2] = fIndexValue;
            pQuad[3] = fIndexValue;
            p += 16;
        } while (++i < uiQuadCount);
        return (int)*ppTable;
    }
    return (int)pBase;
}

struct ShaderArrayEntry
{
    int unk00;
    short unk04;
    unsigned char m_06;
};

struct ShaderArrayHolder
{
    int unk00;
    ShaderArrayEntry** m_ppItems;
    int unk08;
    int unk0c;
    unsigned int m_uiCount;
    void Insert(int, int, int, int, int, int, int, int);
};

struct ShaderArrayOwner
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
    ShaderArrayHolder* m_pHolder;
    void Prep(int);
    ShaderArrayHolder* EnsureShaderArrayEntries(int, int, int, int, int, int);
};

// Calls Prep(-1); if the holder's count is zero, inserts two entries (0x41 and 0x241) and sets each new entry's m_06 to 0xe and 1, then returns the holder.
// @fnv 0x00ba7420
ShaderArrayHolder* ShaderArrayOwner::EnsureShaderArrayEntries(int p1, int, int, int, int, int)
{
    Prep(-1);
    ShaderArrayHolder* h = m_pHolder;
    if (h->m_uiCount == 0)
    {
        h->Insert(p1, 0x41, 1, 0, 0, 0, 0, 0);
        ShaderArrayEntry* e = m_pHolder->m_ppItems[m_pHolder->m_uiCount - 1];
        e->m_06 = 0xe;
        m_pHolder->Insert(p1, 0x241, 1, 0, 0, 0, 0, 0);
        m_pHolder->m_ppItems[m_pHolder->m_uiCount - 1]->m_06 = 1;
    }
    return m_pHolder;
}

struct FUN_00aa5140
{
    FUN_00aa5140();
    int FUN_00aa5230(int);
    static FUN_00aa5140& Get()
    {
        static FUN_00aa5140 generator;
        return generator;
    }
};
inline float RandomRange(const float& high, const float& low)
{
    unsigned int random = FUN_00aa5140::Get().FUN_00aa5230(-1);
    float result = low + (high - low) * random * 2.3283064365386963e-10;
    return result;
}
struct ParticleInitializer : FUN_00ba7f70
{
    void InitParticles(float time);
};
// Initializes each particle's fields with randomized life, angle, rotation and speed variations, sets fScaleTime, and resets iParticleCount to 0.
// @fnv 0x00ba6e00
void ParticleInitializer::InitParticles(float time)
{
    unsigned int count = FUN_00ba52d0();
    float lifeVariation = m_fParticleParameter6 / m_fParticleParameter5;
    float speedVariation = m_fParticleParameter8 / m_fParticleParameter7;
    fScaleTime = time;
    for (unsigned int i = 0; i < count; ++i)
    {
        reinterpret_cast<Particle*>(pParticles)[i].m_fFirstFloatValue = 3.4028234663852886e+38f;
        reinterpret_cast<Particle*>(pParticles)[i].unk04 = 3.4028234663852886e+38f;
        reinterpret_cast<Particle*>(pParticles)[i].unk08 = 3.4028234663852886e+38f;
        reinterpret_cast<Particle*>(pParticles)[i].fTime = -10000.0f;
        reinterpret_cast<Particle*>(pParticles)[i].unk10 = 0.0f;
        reinterpret_cast<Particle*>(pParticles)[i].unk14 = 0.0f;
        reinterpret_cast<Particle*>(pParticles)[i].unk18 = 0.0f;
        reinterpret_cast<Particle*>(pParticles)[i].unk1C = RandomRange(1.0f + lifeVariation, 1.0f - lifeVariation);
        float angle = RandomRange(m_fParticleParameter9 + m_fRotation, m_fRotation - m_fParticleParameter9);
        angle = angle * 0.01745329238474369;
        reinterpret_cast<Particle*>(pParticles)[i].unk20 = angle;
        float rotationSpeed = RandomRange(m_fParticleParameter11 + m_fParticleParameter10,
                                          m_fParticleParameter10 - m_fParticleParameter11);
        rotationSpeed = rotationSpeed * 0.01745329238474369;
        reinterpret_cast<Particle*>(pParticles)[i].unk24 = rotationSpeed;
        reinterpret_cast<Particle*>(pParticles)[i].unk28 = RandomRange(1.0f + speedVariation, 1.0f - speedVariation);
        int boundX = (int)m_fParticleParameter12;
        float textureX = (float)FUN_00aa5140::Get().FUN_00aa5230(boundX);
        int boundY = (int)m_fParticleParameter13;
        float textureY = (float)FUN_00aa5140::Get().FUN_00aa5230(boundY);
        float v = textureY / m_fParticleParameter13;
        float u = textureX / m_fParticleParameter12;
        float texture = v * 100.0 + u;
        reinterpret_cast<Particle*>(pParticles)[i].unk2C = texture;
    }
    iParticleCount = 0;
}

#include <string.h>
inline const NiPoint3* NormalizePoint(NiPoint3& point)
{
    point.Unitize_004a0c10();
    return &point;
}
inline NiPoint3 MakePoint(float x, float y, float z)
{
    NiPoint3 p(x, y, z);
    return p;
}
inline NiPoint3& MulPoint(NiPoint3& out, const NiPoint3& v, float t)
{
    const NiPoint3& a = v;
    out.x = a.x * t;
    out.y = a.y * t;
    out.z = a.z * t;
    return out;
}
inline NiPoint3& AddPoint(NiPoint3& out, const NiPoint3& l, const NiPoint3& r)
{
    out.x = l.x + r.x;
    out.y = l.y + r.y;
    out.z = l.z + r.z;
    return out;
}

inline void CopyPoint(NiPoint3& dst, const NiPoint3& src)
{
    dst = src;
}
extern NiPoint3 DAT_011f426c;
extern double DAT_01029790;
extern double DAT_01012070;
unsigned int __cdecl FUN_00ecadb8();

inline float RandSigned()
{
    volatile float r = (float)((double)(int)FUN_00ecadb8() * 2.0 / DAT_01029790 - DAT_01012070);
    return r;
}

struct PickObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    PickObj* m_pAlt;
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
    NiPoint3 m_pos8c;
};

struct PickCtx
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
    unsigned int m_uiCount;
};

struct PickSrc
{
    int unk00;
    int unk04;
    PickCtx* m_pCtx;
    int unk0C;
    int unk10;
    PickObj** m_ppObjs;
};

struct PickView
{
    unsigned int u0;
    unsigned int u4;
    unsigned char u8;
};
struct ArrView
{
    char* base;
    unsigned int stride;
    unsigned char flag;
};
struct ArrView2
{
    char* base;
    unsigned int stride;
    unsigned int unk08;
    unsigned char flag;
};
union PickWork
{
    float vector[3];
    ArrView view;
    NiPoint3& point()
    {
        return reinterpret_cast<NiPoint3&>(vector);
    }
};
struct PickWorkspace
{
    NiPoint3 left;
    PickWork other;
    PickWork work;
};
struct PickMesh
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
    virtual bool vf8c();
};

struct PickShape
{
    int unk00;
    int unk04;
    unsigned short m_usElementCount;
    unsigned short unk0A;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    NiPoint3* m_pVecA;
    NiPoint3* m_pVecB;
    int unk28;
    int unk2C;
    PickMesh* m_pMesh;
    bool FUN_00a67360(int);
    void NiGeometryData_GetVerticesIterator(void*);
    void GetBounds(void*);
    void NiGeometryData_UnlockPackedVertexData();
};

struct PickMover
{
    NiPoint3* FUN_004b4500(NiPoint3*, const NiPoint3*);
    __declspec(noalias) NiPoint3* ComputeValue_00524c40(NiPoint3*, const NiPoint3*);
};

struct PickElem
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
    int unk68_mover;
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
    PickShape* m_pB8;
    PickSrc* m_pBC;
};

struct EmitterPick : ParticleEmitter
{
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    PickElem** m_ppArr;
    unsigned short unk124;
    unsigned short m_usElementCount;
    void PickParticle(int idx);
};

// @fnv 0x00ba74a0
void EmitterPick::PickParticle(int aiIndex)
{
    NiPoint3 a = DAT_011f426c;
    NiPoint3 b = DAT_011f426c;
    PickElem* e = 0;
    PickWorkspace scratch;
    if (m_usElementCount > 0)
    {
        for (;;)
        {
            unsigned int r = FUN_00ecadb8();
            e = m_ppArr[r % m_usElementCount];
            if (e == 0)
                continue;
            if (e->m_pB8 == 0)
                continue;
            break;
        }
        PickSrc* s = e->m_pBC;
        if (s != 0)
        {
            unsigned int n = s->m_pCtx->m_uiCount;
            PickObj* pObj = s->m_ppObjs[FUN_00ecadb8() % n];
            PickObj* pAltObj = pObj->m_pAlt;
            float t = (float)((int)FUN_00ecadb8() / 32767.0);
            float fLerpS = 1.0f - t;
            a = AddPoint(scratch.work.point(), MulPoint(scratch.left, pObj->m_pos8c, t),
                         MulPoint(scratch.other.point(), pAltObj->m_pos8c, fLerpS));
            float dz = RandSigned();
            float dx = RandSigned();
            scratch.work.vector[0] = dx;
            scratch.work.vector[1] = 0.0f;
            scratch.work.vector[2] = dz;
            NiPoint3* __restrict r = reinterpret_cast<PickMover*>(&e->unk68_mover)
                                           ->FUN_004b4500(&scratch.other.point(), NormalizePoint(scratch.work.point()));
            b = *r;
            goto L_0353;
        }
        PickShape* pShape = e->m_pB8;
        unsigned short cnt = pShape->m_usElementCount;
        unsigned int uiRemainder = FUN_00ecadb8() % cnt;
        pShape = e->m_pB8;
        if (pShape == 0)
            goto L_0353;
        {

            bool ok = false;
            PickMesh* mesh = pShape->m_pMesh;
            if (mesh != 0 && mesh->vf8c())
            {
                scratch.work.view.base = 0;
                scratch.work.view.stride = 0;
                scratch.work.view.flag = 0;
                scratch.other.view.base = 0;
                scratch.other.view.stride = 0;
                scratch.other.view.flag = 0;
                if (pShape->FUN_00a67360(1) != 0)
                {
                    pShape->NiGeometryData_GetVerticesIterator(&scratch.work.view);
                    pShape->GetBounds(&scratch.other.view);
                    NiPoint3* __restrict pVecA =
                        (NiPoint3*)((char*)scratch.work.view.base + scratch.work.view.stride * uiRemainder);
                    a = *pVecA;
                    NiPoint3* __restrict pVecB =
                        (NiPoint3*)((char*)scratch.other.view.base + scratch.other.view.stride * uiRemainder);
                    b = *pVecB;
                    pShape->NiGeometryData_UnlockPackedVertexData();
                }
            }
            else
            {
                NiPoint3* pVecA = pShape->m_pVecA != 0 ? pShape->m_pVecA + uiRemainder : (NiPoint3*)&DAT_011f426c;
                NiPoint3* pVecBBase = pShape->m_pVecB;
                a = *pVecA;
                NiPoint3* __restrict pVecB = pVecBBase != 0 ? pVecBBase + uiRemainder : (NiPoint3*)&DAT_011f426c;
                b = *pVecB;
            }
            if (reinterpret_cast<unsigned char&>(unk6C) != 0)
            {
                PickMover* pMover = reinterpret_cast<PickMover*>(&e->unk68_mover);
                {
                    NiPoint3* __restrict r = pMover->ComputeValue_00524c40(&scratch.work.point(), &a);
                    a = *r;
                }
                {
                    NiPoint3* __restrict r = pMover->FUN_004b4500(&scratch.work.point(), &b);
                    b = *r;
                }
            }
        }
    }
    else
    {
        a = DAT_011f426c;
        b = DAT_011f426c;
    }
L_0353:
    int byteOffset = aiIndex * sizeof(Particle);
    reinterpret_cast<Particle*>(byteOffset + reinterpret_cast<char*>(pParticles))->m_fFirstFloatValue = a.x;
    reinterpret_cast<Particle*>(byteOffset + reinterpret_cast<char*>(pParticles))->unk04 = a.y;
    reinterpret_cast<Particle*>(byteOffset + reinterpret_cast<char*>(pParticles))->unk08 = a.z;
    reinterpret_cast<Particle*>(byteOffset + reinterpret_cast<char*>(pParticles))->fTime = fScaleTime;
    reinterpret_cast<Particle*>(byteOffset + reinterpret_cast<char*>(pParticles))->unk10 = b.x;
    reinterpret_cast<Particle*>(byteOffset + reinterpret_cast<char*>(pParticles))->unk14 = b.y;
    reinterpret_cast<Particle*>(byteOffset + reinterpret_cast<char*>(pParticles))->unk18 = b.z;
}

#include <math.h>
extern NiPoint3 NiPoint3_ZERO;
struct ParticleSceneNode
{
    int unk00, unk04;
    const char* name;
    int unk0C, unk10, unk14;
    ParticleSceneNode* parent;
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
    NiPoint3 worldPosition;
};
struct ParticleUpdater : FUN_00ba7f70
{
    void PickParticle(int);
    void ParticleShaderProperty_GenerateFromCollisionBones(int);
    void ParticleShaderProperty_GenerateFromRay(int);
    void ParticleShaderProperty_UpdateParticles(float time, bool compensate, bool emit);
};
// Ages and emits particles, optionally compensating for parent node movement.
// @fnv 0x00ba7b60
// src: XBOX_PDB 0x00ba7b60
void ParticleUpdater::ParticleShaderProperty_UpdateParticles(float time, bool compensate, bool emit)
{
    float delta = time - fScaleTime;
    delta = (float)fabs(delta);
    float amount = delta;
    int count = FUN_00ba52d0();
    int maximum = (int)(count * m_fParticleParameter4);
    int limit = count;
    if (count >= maximum)
        limit = maximum;
    amount = amount / m_fParticleParameter5 * limit + m_fParticleParameter3;
    int remaining = (int)amount;
    m_fParticleParameter3 = amount - remaining;
    NiPoint3 movement = NiPoint3_ZERO;
    if (compensate)
    {
        ParticleSceneNode* node = static_cast<ParticleSceneNode*>(pParticleBuffer)->parent;
        while (node)
        {
            if (!strcmp(node->name, "Bip01"))
            {
                movement = node->worldPosition - node->parent->worldPosition;
                break;
            }
            node = node->parent;
        }
    }
    for (int i = 0; i < count; ++i)
    {
        Particle* particle = reinterpret_cast<Particle*>(pParticles) + i;
        float age = time - particle->fTime;
        if (!(age < 0.0f) && !(age * particle->unk1C > m_fParticleParameter5))
            continue;
        if (particle->m_fFirstFloatValue != 3.4028234663852886e+38)
        {
            reinterpret_cast<Particle*>(pParticles)[i].m_fFirstFloatValue = 3.4028234663852886e+38f;
            reinterpret_cast<Particle*>(pParticles)[i].unk04 = 3.4028234663852886e+38f;
            reinterpret_cast<Particle*>(pParticles)[i].unk08 = 3.4028234663852886e+38f;
            reinterpret_cast<Particle*>(pParticles)[i].fTime = -10000.0f;
            reinterpret_cast<Particle*>(pParticles)[i].unk10 = 0.0f;
            reinterpret_cast<Particle*>(pParticles)[i].unk14 = 0.0f;
            reinterpret_cast<Particle*>(pParticles)[i].unk18 = 0.0f;
            --iParticleCount;
        }
        if (emit && remaining > 0 && iParticleCount < limit)
        {
            switch (m_iParticleDataValue)
            {
            case 0:
                PickParticle(i);
                break;
            case 1:
                ParticleShaderProperty_GenerateFromCollisionBones(i);
                break;
            case 2:
                ParticleShaderProperty_GenerateFromRay(i);
                break;
            }
            --remaining;
            ++iParticleCount;
            if (compensate)
            {
                reinterpret_cast<Particle*>(pParticles)[i].m_fFirstFloatValue -= movement.x;
                reinterpret_cast<Particle*>(pParticles)[i].unk04 -= movement.y;
                reinterpret_cast<Particle*>(pParticles)[i].unk08 -= movement.z;
            }
        }
    }
    fScaleTime = time;
}

#include <stdlib.h>
extern "C" void _ReadWriteBarrier();

inline float RandomSigned()
{
    return (const float&)((float)(rand() * 2.0 / 32767.0 - 1.0));
}
inline float RandomLast()
{
    float r = (float)(rand() * 2.0 / 32767.0 - 1.0);
    _ReadWriteBarrier();
    return r;
}
inline float RandomUnit()
{
    return (float)(rand() / 32767.0);
}

struct M_004b4500
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    NiPoint3 __declspec(noalias) FUN_004b4500(const NiPoint3*);
};
struct EmitterNode
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    EmitterNode* parent;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    M_004b4500 rotation;
    NiPoint3 position;
    int unk98, unk9c, unka0, unka4;
    unsigned short count;
};
struct ParticleSpawner : ParticleEmitter
{
    int unk108, unk10c, unk110, unk114, unk118, unk11c;
    EmitterNode** emitters;
    unsigned short capacity, count;
    void ParticleShaderProperty_GenerateFromCollisionBones(unsigned int index);
};
// Selects a random emitter when available and writes position, direction, and time fields to the indexed particle.
// @fnv 0x00ba7860
// src: XBOX_PDB 0x00ba7860
void ParticleSpawner::ParticleShaderProperty_GenerateFromCollisionBones(unsigned int index)
{
    NiPoint3 position;
    NiPoint3 direction;
    if (count > 0)
    {
        EmitterNode* node;
        do
        {
            node = emitters[(unsigned int)rand() % count];
        } while (!node);
        if (node->count > 0 && node->parent)
        {
            EmitterNode* parent = node->parent;
            float t = RandomUnit();
            position = node->position * t + parent->position * (1.0f - t);
            float z = RandomSigned();
            direction = NiPoint3(RandomLast(), 0.0f, z);
            direction.Unitize_004a0c10();
            direction = node->rotation.FUN_004b4500(&direction);
        }
        else
        {
            position = node->position;
            float z = RandomSigned();
            float y = RandomSigned();
            direction = NiPoint3(RandomLast(), y, z);
            direction.Unitize_004a0c10();
        }
    }
    else
    {
        direction = position = *(const NiPoint3*)&DAT_011f426c;
    }
    Particle* const& particles = pParticles;
    particles[index].m_fFirstFloatValue = position.x;
    particles[index].unk04 = position.y;
    particles[index].unk08 = position.z;
    particles[index].fTime = fScaleTime;
    particles[index].unk10 = direction.x;
    particles[index].unk14 = direction.y;
    particles[index].unk18 = direction.z;
}

struct Transform71
{
    NiPoint3* ComputeValue_00524c40(NiPoint3*, const NiPoint3*);
    NiPoint3* FUN_004b4500(NiPoint3*, const NiPoint3*);
};
struct Object71
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
    Transform71 transform;
};
struct Record71
{
    float x, y, z, scale, dx, dy, dz, unk1c, unk20, unk24, unk28, unk2c;
};
struct Array71
{
    const void* vt;
    Object71** m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
};
struct Target71
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
    Record71* pParticles;
    int m_iParticleDataValue;
    float m_fParticleParameter1;
    bool m_bParticleEnabled;
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
    float fScaleTime;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    Array71 kArray;
    void ParticleShaderProperty_GenerateFromRay(unsigned int index);
};
inline float RandomUnit71()
{
    return (float)(rand() / 32767.0);
}
inline float ParseFloatValue(const double& d)
{
    return (float)d;
}
inline float RandomSigned71()
{
    return ParseFloatValue((float)(rand() * 2.0 / 32767.0 - 1.0));
}
// Computes a particle position and direction from the first object in kArray, transforms them if enabled, and writes them into pParticles at the given index.
// @fnv 0x00ba71d0
// src: COMMUNITY 0x00ba71d0
void Target71::ParticleShaderProperty_GenerateFromRay(unsigned int index)
{
    NiPoint3 position;
    NiPoint3 direction;
    if (kArray.m_usSize > 0)
    {
        Object71* object = kArray.m_pBase[0];
        if (object)
        {
            direction.Set(0.0f, m_fParticleParameter1 * RandomUnit71(), 0.0f);
            position = direction;
            direction = NiPoint3(RandomSigned71(), 0.0f, RandomSigned71());
            direction.Unitize_004a0c10();
            if (m_bParticleEnabled)
            {
                NiPoint3 result;
                const NiPoint3* __restrict p = object->transform.ComputeValue_00524c40(&result, &position);
                position = *p;
                const NiPoint3* __restrict q = object->transform.FUN_004b4500(&result, &direction);
                direction = *q;
            }
        }
    }
    else
    {
        static_cast<NiPoint3&>(position) = NiPoint3_ZERO;
        static_cast<NiPoint3&>(direction) = NiPoint3_ZERO;
    }
    pParticles[index].x = position.x;
    pParticles[index].y = position.y;
    pParticles[index].z = position.z;
    pParticles[index].scale = fScaleTime;
    pParticles[index].dx = direction.x;
    pParticles[index].dy = direction.y;
    pParticles[index].dz = direction.z;
}

extern int DAT_010b8250;
void __fastcall FUN_00baa0e0(void*);
extern MemoryManager g_dealloc;
void operator delete[](void* p)
{
    g_dealloc.Deallocate(p);
}
template <class T> NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
GlobalObject_004aff00::~GlobalObject_004aff00()
{
    vt = &DAT_0101fbcc;
    delete[] reinterpret_cast<NiPointer<NiNode>*>(m_pBase);
}
struct BaseParticle
{
    const void* vt;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40,
        unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    ~BaseParticle()
    {
        FUN_00baa0e0(this);
    }
};
struct FUN_00ba7df0 : FUN_00ba8e50
{
    BoundDataBlock* pParticles;
    int m_iParticleDataValue;
    float m_fParticleParameter1;
    bool m_bParticleEnabled;
    int iParticleCount;
    float m_fParticleParameter3;
    float m_fParticleParameter4;
    float m_fParticleParameter5;
    float m_fParticleParameter6;
    float m_fParticleParameter7;
    float m_fParticleParameter8;
    float m_fParticleParameter2;
    NiPoint3 Velocity;
    NiPoint3 Acceleration;
    float m_fRotation;
    float m_fParticleParameter9;
    float m_fParticleParameter10;
    float m_fParticleParameter11;
    float fUnkB8, fUnkBC, fUnkC0;
    NiColorA Color1;
    NiColorA Color2;
    NiColorA Color3;
    float fUnkF4, fUnkF8, fUnkFC, fUnk100;
    float fScaleTime;
    float fUnk108, fUnk10C, fUnk110, fUnk114;
    NiPointer<NiRefObject> spRetainedObject;
    PrimArray kArray;
    void* pParticleBuffer;
    float fAlpha;
    float m_fParticleParameter12;
    float m_fParticleParameter13;
    NiPoint3 m_vecParticlePosition;
    float fUnk148;
    ~FUN_00ba7df0();
};

// Releases the retained object, removes array entries, deletes the particle array, and deallocates a global pointer when a global counter reaches zero.
// @fnv 0x00ba7df0
FUN_00ba7df0::~FUN_00ba7df0()
{

    if (spRetainedObject.m_pObject)
    {
        spRetainedObject.m_pObject->DecRefCount();
        spRetainedObject.m_pObject = 0;
    }
    kArray.RemoveAll();
    delete[] pParticles;
    if (--DAT_01200424 == 0)
    {
        g_dealloc.Deallocate(reinterpret_cast<void*>(DAT_01200420));
        DAT_01200420 = 0;
    }
}
