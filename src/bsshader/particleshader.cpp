#include "../../include/NiPointer.h"
// bsshader/particleshader.cpp: ParticleShader, ShaderState (12 functions)

#include "particleshader_decls.h"
#include "../../include/BSShader.h"
// 0x00ba53f0 zeroes four scalar rows at unaligned offset 0xec.
struct ParticleShaderRow_00ba53f0 { float x, y, z, w; };
#include "../../include/MemoryManager.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiBound.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiObject.h"
#include "../../include/NiProperty.h"
#include "../../include/NiUpdateData.h"
#include "../../include/NiPoint3.h"
// The former Vector3 stand-in defined this constructor inline in its class.
inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
{
}

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#pragma intrinsic(memcpy)

inline NiUpdateData::NiUpdateData() {}
inline NiBound::NiBound(const NiBound& bound)
    { memcpy(this, &bound, sizeof(*this)); }
// Returns the cached particle count, computing it from the renderer level (26, or 78 when level >= 2) if not yet set.
// @fnv 0x00ba52d0
unsigned int ParticleShader::GetShaderParticleCount()
{
    register unsigned int count = fnv_particle_shader_particle_count;
    if (count == 0)
    {
        count = 26 + (fnv_particle_shader_renderer_level < 2 ? 0 : 52);
        fnv_particle_shader_particle_count = count;
    }
    return count;
}

// @fnv 0x00ba58b0
BSShader* ParticleShader::CreateShader()
{
    NiD3DVertexDeclaration* d = NiD3DVertexDeclaration::Create(DAT_011f9508, 5, 1);
    d->vfn_8c(0, 0, 0, 2, 0);
    d->vfn_8c(1, 3, 3, 2, 0);
    d->vfn_8c(2, 5, 4, 3, 0);
    d->vfn_8c(3, 7, 5, 1, 0);
    d->vfn_94(0, 4, 6, 0x80000000, 0, 10, 1, 0);
    d->vfn_b4();
    ParticleShader* pParticleShader = new FUN_00ba53f0(d);
    pParticleShader->Initialize();
    pParticleShader->vfn_13c();
    pParticleShader->vfn_140();
    pParticleShader->InitShaderConstants();
    pParticleShader->UseShaderDeclaration(reinterpret_cast<NiD3DShaderDeclaration*>(d));
    return pParticleShader;
}

// Assigns a NiD3DPass pointer, releasing the old pass when its refcount at offset 0x64 drops to zero and incrementing the new pass's refcount.
// @fnv 0x00ba53c0
void* __fastcall AssignNiD3DPass(void* pThis, int, void* param)
{
    NiD3DPass** ppThis = (NiD3DPass**)pThis;
    NiD3DPass** ppParam = (NiD3DPass**)param;
    NiD3DPass* old = *ppThis;
    if (old != *ppParam)
    {
        if (old)
        {
            unsigned int* piRefCount = &old->m_uiRefCount;
            *piRefCount -= 1;
            if (*piRefCount == 0)
                old->DestroyPass();
        }
        NiD3DPass* n = *ppParam;
        *ppThis = n;
        if (n)
            ++n->m_uiRefCount;
    }
    return pThis;
}

extern "C" void* g_012003f8;

// @fnv 0x00ba5730
// src: XBOX_PDB 0x00ba5730
void* __cdecl ParticleShader_GetRTTI()
{
    return &g_012003f8;
}

struct FUN_00ba6ce0_shell
{
    char __thiscall ParticleShaderProperty_SetupGeometry(int value);
};

// @fnv 0x00ba6ce0
// src: XBOX_PDB 0x00ba6ce0
char __thiscall FUN_00ba6ce0_shell::ParticleShaderProperty_SetupGeometry(int value)
{
    *(int*)((char*)this + 0x12c) = value;
    return 1;
}

struct FUN_00ba52f0_shell
{
    char _pad[0x74];
    void* _a;
    void* _b;
    void __thiscall ParticleShader_ClearPassStages();
};
// Calls the virtual function at vtable slot 74 twice, passing _a and then _b.
// @fnv 0x00ba52f0
// src: XBOX_PDB 0x00ba52f0
void __thiscall FUN_00ba52f0_shell::ParticleShader_ClearPassStages()
{
    typedef void(__thiscall * Fn)(FUN_00ba52f0_shell*, void*);
    (*(Fn**)this)[74](this, _a);
    (*(Fn**)this)[74](this, _b);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" void FUN_00be0f10();

struct ComTarget
{
    virtual void vfn_0();
    virtual void vfn_4();
    volatile long refCount;
};

struct RefSlot
{
    NiD3DPass* value;
    ~RefSlot()
    {
        NiD3DPass* p = value;
        if (p)
        {
            if (--p->m_uiRefCount == 0)
            {
                p->DestroyPass();
            }
        }
    }
    void Release()
    {
        NiD3DPass* p = value;
        if (p)
        {
            if (--p->m_uiRefCount == 0)
            {
                p->DestroyPass();
            }
            value = 0;
        }
    }
};

struct ComSlot1
{
    ComTarget* value;
    ~ComSlot1()
    {
        ComTarget* p = value;
        if (p)
        {
            if (InterlockedDecrement(&p->refCount) == 0)
            {
                p->vfn_4();
            }
        }
    }
    void Release()
    {
        ComTarget* p = value;
        if (p)
        {
            volatile long* pRef = &p->refCount;
            if (InterlockedDecrement(pRef) == 0)
            {
                p->vfn_4();
            }
            value = 0;
        }
    }
};

struct ComSlot2
{
    ComTarget* value;
    ~ComSlot2()
    {
        ComTarget* p = value;
        if (p)
        {
            if (InterlockedDecrement(&p->refCount) == 0)
            {
                p->vfn_4();
            }
        }
    }
    void Release()
    {
        ComTarget* p = value;
        if (p)
        {
            if (InterlockedDecrement(&p->refCount) == 0)
            {
                p->vfn_4();
            }
            value = 0;
        }
    }
};

extern MemoryManager g_memoryManager;

extern "C" ComTarget* DAT_012003f4;

struct FUN_00ba5740 : BSShader
{
    int unk6c;
    void* slot70;
    RefSlot slot74;
    RefSlot slot78;
    ComSlot1 slot7c;
    ComSlot2 slot80;

    virtual ~FUN_00ba5740();
};

// Releases the global ComTarget, frees slot70 through g_memoryManager, and releases the four reference slots.
// @fnv 0x00ba5740
FUN_00ba5740::~FUN_00ba5740()
{
    if (DAT_012003f4)
    {
        ComTarget* p = DAT_012003f4;
        if (InterlockedDecrement(&DAT_012003f4->refCount) == 0)
        {
            p->vfn_4();
        }
        DAT_012003f4 = 0;
    }
    g_memoryManager.Deallocate(slot70);
    slot70 = 0;
    slot74.Release();
    slot78.Release();
    slot7c.Release();
    slot80.Release();
}

namespace fnv_00ba69f0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);
struct ConstantMap
{
    static void* operator new(unsigned int) throw();
    static void operator delete(void*);
    ConstantMap(void*, int);
    virtual void ReportDiagnostic();
    virtual void destroy();
    virtual void add(const char*, unsigned int, unsigned int, unsigned int, unsigned int, const char*, unsigned int,
                     unsigned int, void*, unsigned int);
    virtual void FlushUsageData();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void predefined(const char*, unsigned int, unsigned int, const char*, unsigned int, unsigned int,
                            unsigned int, unsigned int);
    long refs;
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
};
struct MapPointer
{
    ConstantMap* ptr;
    void operator=(ConstantMap* value)
    {
        if (ptr != value)
        {
            ConstantMap* old = ptr;
            if (old && !InterlockedDecrement(&old->refs))
                old->destroy();
            ptr = value;
            if (value)
                InterlockedIncrement(&value->refs);
        }
    }
};
extern float scaleAdjustment;
extern "C" unsigned int fnv_particle_shader_particle_count;
extern "C" int fnv_particle_shader_renderer_level;
struct ShaderState
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    void* field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    MapPointer field30;
    MapPointer field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    int field60;
    int field64;
    int field68;
    int field6c;
    void* field70;
    int field74;
    int field78;
    int field7c;
    int field80;
    int field84;
    int field88;
    int field8c;
    int field90;
    int field94;
    int field98;
    int field9c;
    int fielda0;
    int fielda4;
    int fielda8;
    int fieldac;
    int fieldb0;
    int fieldb4;
    int fieldb8;
    int fieldbc;
    int fieldc0;
    int fieldc4;
    int fieldc8;
    int fieldcc;
    int fieldd0;
    int fieldd4;
    int fieldd8;
    int fielddc;
    int fielde0;
    int fielde4;
    int fielde8;
    int fieldec;
    int fieldf0;
    int fieldf4;
    int fieldf8;
    int fieldfc;
    int field100;
    int field104;
    int field108;
    int field10c;
    int field110;
    int field114;
    int field118;
    int field11c;
    int field120;
    int field124;
    int field128;
    void InitConstantMaps();
};
// Creates the field34 ConstantMap with predefined and added constants if absent, then creates field30 if absent.
// @fnv 0x00ba69f0
void ShaderState::InitConstantMaps()
{
    if (!field34.ptr)
    {
        field34 = new ConstantMap(field18, 0);
        field34.ptr->predefined("WorldViewProjTranspose", 0x20000009, 0, "", 0, 0, 0, 0);
        field34.ptr->add("Wind", 0x10000007, 0, 15, 1, "", 16, 4, &fieldec, 0);
        field34.ptr->add("Color1", 0x10000007, 0, 9, 1, "", 16, 4, &fieldfc, 0);
        field34.ptr->add("Color2", 0x10000007, 0, 10, 1, "", 16, 4, &field10c, 0);
        field34.ptr->add("Color3", 0x10000007, 0, 11, 1, "", 16, 4, &field11c, 0);
        field34.ptr->add("Velocity", 0x10000007, 0, 12, 1, "", 12, 4, &fieldd4, 0);
        field34.ptr->add("Acceleration", 0x10000007, 0, 13, 1, "", 12, 4, &fielde0, 0);
        field34.ptr->add("Scale Adjustment", 0x10000007, 0, 14, 1, "", 16, 4, &scaleAdjustment, 0);
        field34.ptr->add("fVars", 0x10000009, 0, 4, 5, "", 80, 4, &field84, 0);
        if (!fnv_particle_shader_particle_count)
            fnv_particle_shader_particle_count = fnv_particle_shader_renderer_level >= 2 ? 78 : 26;
        field34.ptr->add("particle data", 0x10000009, 0, 18, fnv_particle_shader_particle_count * 3, "",
                         fnv_particle_shader_particle_count * 48, 4, field70, 0);
    }
    if (!field30.ptr)
        field30 = new ConstantMap(field18, 2);
}
}  // namespace fnv_00ba69f0

struct S_00ba5320_Inner
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
    virtual unsigned int GetWidth(int value);
    virtual unsigned int GetHeight(int value);
};

struct S_00ba5320_Outer
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
    virtual void GetWidth();
    virtual void GetHeight();
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
    virtual S_00ba5320_Inner* GetRenderTarget();
};

extern S_00ba5320_Outer* DAT_011f4748;
extern float DAT_011adcc8;
extern float DAT_011adccc;
extern float DAT_011adcd0;
extern float DAT_011adcd4;
extern float DAT_011adcd8;

// @fnv 0x00ba5320
// src: COMMUNITY 0x00ba5320
void __cdecl ParticleShader_UpdateFov()
{
    S_00ba5320_Inner* pRenderTarget = DAT_011f4748->GetRenderTarget();
    unsigned int uiWidth = pRenderTarget->GetWidth(0);
    float value1 = (float)uiWidth;

    S_00ba5320_Inner* pRenderTarget2 = DAT_011f4748->GetRenderTarget();
    double dWidth = value1;
    unsigned int uiHeight = pRenderTarget2->GetHeight(0);
    float value2 = (float)uiHeight;

    float quotient = (float)(dWidth / value2);
    // Retain reciprocal precision while also storing the public float value.
    double inverse = 1.0f / DAT_011adcc8;
    DAT_011adccc = inverse;
    DAT_011adcd0 = inverse * quotient;
    DAT_011adcd8 = DAT_011adcd4 = 1.0f;
}

extern NiBound DAT_011f4288;
extern int DAT_012003f0;

struct BoundHolder
{
    int f00;
    int f04;
    int f08;
    int f0c;
    NiBound bound;
};

struct ArgObj
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    NiBound* bound;
};

NiObject* __cdecl ParticleShader_GetParticleGeometry();
void __cdecl FUN_00b57e30(NiObject*, int, int);

// @fnv 0x00ba68d0
// src: XBOX_PDB 0x00ba68d0
NiProperty* __cdecl ParticleShader_Start(NiAVObject* apObject, ArgObj* apArg)
{
    if (apObject)
    {
        NiNode* obj = apObject->IsSceneNode();
        if (obj)
        {
            NiObject* pPrototype = ParticleShader_GetParticleGeometry();
            NiAVObject* clone = (NiAVObject*)pPrototype->Clone();
            // The clone is geometry; its data pointer follows the NiAVObject base.
            BoundHolder* holder = *(BoundHolder**)((char*)clone + 0xb8);
            NiBound b = holder->bound;
            NiBound* pOtherBound = apArg->bound;
            if (!pOtherBound)
                pOtherBound = &DAT_011f4288;
            float t = pOtherBound->m_fRadius * 2.0f;
            float newRadius = (b.m_fRadius > t) ? b.m_fRadius : t;
            holder->bound.m_fRadius = newRadius;
            holder->bound.m_kCenter = b.m_kCenter;
            obj->AttachChildInAvailableSlot(clone, true);
            NiUpdateData updateData;
            updateData.fTime = 0.0f;
            updateData.pad1 = 0;
            updateData.pad2 = 0;
            updateData.pad3 = 0;
            updateData.pad4 = 0;
            updateData.pad5 = 0;
            obj->NiAVObject::Update(updateData);
            FUN_00b57e30(clone, 0, 0);
            NiProperty* pProperty = clone->GetProperty(3);
            int bValidType = 0;
            if (pProperty)
                // Shader-property type, beyond the NiProperty base.
                bValidType = (*(int*)((char*)pProperty + 0x1c) == 0x11);
            NiProperty* pKeptProperty = bValidType ? pProperty : 0;
            if (pKeptProperty)
            {
                typedef void (__thiscall *SetGeometry)(NiProperty*, NiObject*);
                (*(SetGeometry**)pKeptProperty)[0x9c / 4](pKeptProperty, clone);
                ParticleShader_GetParticleGeometry();
                ++DAT_012003f0;
            }
            return pKeptProperty;
        }
    }
    return 0;
}

struct Q64_Pool
{
    int unk00;
    void* __thiscall Game_DoHeapAlloc(unsigned int size);
};
struct Q64_Pt2
{
    float x;
    float y;
};
extern Q64_Pool DAT_011f6238;
extern int DAT_011f91c0;
extern unsigned int DAT_012003ec;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

void* __cdecl Object_DispatchCommandFour(unsigned int size);
unsigned int __cdecl GetFloatQuadTable();

inline void* operator new[](unsigned int n, Q64_Pool& p)
{
    return p.Game_DoHeapAlloc(n);
}

inline unsigned short* Q64_allocIdx(unsigned short t)
{
    return new (DAT_011f6238) unsigned short[t * 3];
}
inline NiPoint3* Q64_allocPos(unsigned short n)
{
    return ::new (DAT_011f6238) NiPoint3[n];
}
inline Q64_Pt2* Q64_allocUv(unsigned short n)
{
    return new (DAT_011f6238) Q64_Pt2[n];
}

struct Q64_Obj
{
    static void* operator new(unsigned int n)
    {
        return Object_DispatchCommandFour(n);
    }
    static void operator delete(void* p);
};
struct Q64_Sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    NiBound bound;
    void SetObjectBound(const NiPoint3& c, float r)
    {
        bound.m_kCenter = c;
        bound.m_fRadius = r;
    }
};

struct Q64_Buf : Q64_Obj
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
    void __thiscall SetSize_Thunk(int a);
    void __thiscall NiAdditionalGeometryData_SetDataBlock(int a, unsigned int b, unsigned int c, int d);
    void __thiscall NiAdditionalGeometryData_SetDataStream(int a, int b, int c, int d, unsigned short e, int f, int g);
    Q64_Buf(unsigned short nv, int a);
};
struct Q64_Geo : Q64_Obj
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
    void __thiscall FUN_00a67260(Q64_Buf* a);
    Q64_Geo(unsigned short nv, NiPoint3* verts, int a, int b, Q64_Pt2* uv, int c, int d, unsigned short tris,
            unsigned short* idx);
};
struct Q64_Ren : Q64_Obj
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
    Q64_Ren();
};
struct Q64_Top : Q64_Obj
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
    Q64_Sub* sub;
    int unkbc;
    int unkc0;
    void __thiscall NiAVObject_AttachProperty(Q64_Ren* a);
    Q64_Top(Q64_Geo* geo);
};

struct RefObj : ComTarget
{
    void IncRefCount()
    {
        InterlockedIncrement(&refCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refCount) == 0)
            vfn_4();
    }
};
using ::NiPointer;
// Builds and caches a Q64_Top containing repeated quad geometry with vertices, UVs, and a renderer.
// @fnv 0x00ba64e0
// src: XBOX_PDB 0x00ba64e0
NiObject* __cdecl ParticleShader_GetParticleGeometry()
{
    if (!DAT_011f91c0)
        return 0;
    if (DAT_012003f4)
        return reinterpret_cast<NiObject*>(DAT_012003f4);

    if (!DAT_012003ec)
        DAT_012003ec = 0x1a + (DAT_011f91c0 < 2 ? 0 : 0x34);
    unsigned short n = (unsigned short)DAT_012003ec;
    unsigned int tris = (unsigned short)(n * 2);
    unsigned short nv = (unsigned short)(n * 4);

    unsigned short* idx = Q64_allocIdx(tris);
    NiPoint3* verts = Q64_allocPos(nv);
    Q64_Pt2* uv = Q64_allocUv(nv);

    for (unsigned short i = 0; i < n; i++)
    {
        NiPoint3 p0;
        p0.x = -1.0f; p0.y = -1.0f; p0.z = 0.0f;
        NiPoint3 p1;
        p1.x = 1.0f; p1.y = -1.0f; p1.z = 0.0f;
        NiPoint3 p2;
        p2.x = 1.0f; p2.y = 1.0f; p2.z = 0.0f;
        NiPoint3 p3;
        p3.x = -1.0f; p3.y = 1.0f; p3.z = 0.0f;
        Q64_Pt2 u0 = {0.0f, 0.0f};
        Q64_Pt2 u1 = {1.0f, 0.0f};
        Q64_Pt2 u2 = {1.0f, 1.0f};
        Q64_Pt2 u3 = {0.0f, 1.0f};
        unsigned short v = i * 4;
        unsigned short* ip = idx + i * 6;
        verts[v] = p0;
        verts[v + 1] = p1;
        verts[v + 2] = p2;
        verts[v + 3] = p3;
        uv[v] = u0;
        uv[v + 1] = u1;
        uv[v + 2] = u2;
        uv[v + 3] = u3;
        ip[0] = v;
        ip[1] = v + 1;
        ip[2] = v + 2;
        ip[3] = v + 3;
        ip[4] = v;
        ip[5] = v + 2;
    }

    Q64_Geo* geo = new Q64_Geo(nv, verts, 0, 0, uv, 1, 0, tris, idx);
    Q64_Buf* buf = new Q64_Buf(nv, 1);
    buf->SetSize_Thunk(1);
    buf->NiAdditionalGeometryData_SetDataBlock(0, GetFloatQuadTable(), nv * 4, 1);
    buf->NiAdditionalGeometryData_SetDataStream(0, 0, 0, 1, nv, 4, 4);
    geo->FUN_00a67260(buf);

    Q64_Top* top = new Q64_Top(geo);
    Q64_Sub* sub = top->sub;
    NiBound kBound = sub->bound;
    sub->bound.m_fRadius = 512.0f;
    sub->bound.m_kCenter = kBound.m_kCenter;

    Q64_Ren* ren = new Q64_Ren;
    top->NiAVObject_AttachProperty(ren);

    if (DAT_012003f4 != (ComTarget*)top)
    {
        if (DAT_012003f4)
            ((RefObj*)DAT_012003f4)->DecRefCount();
        DAT_012003f4 = (ComTarget*)top;
        ((RefObj*)DAT_012003f4)->IncRefCount();
    }
    return reinterpret_cast<NiObject*>(DAT_012003f4);
}

extern void* __cdecl FUN_00ec61c0(void*, int, unsigned int);

struct ParticleMemoryManager
{
    void* __thiscall Game_DoHeapAlloc(unsigned int);
};
extern ParticleMemoryManager particleMemoryManager;

namespace ParticleConstruction {
struct RefObject
{
    virtual void unused();
    virtual void destroy();
    long references;
};
struct ObjectPointer
{
    RefObject* object;
    ObjectPointer() : object(0)
    {}
    ~ObjectPointer()
    {
        reset(0);
    }
    void reset(RefObject* next)
    {
        if (object != next)
        {
            RefObject* previous = object;
            if (previous && !InterlockedDecrement(&previous->references))
                previous->destroy();
            object = next;
            if (next)
                InterlockedIncrement(&next->references);
        }
    }
};

struct PassPointer
{
    NiD3DPass* pass;
    PassPointer() : pass(0)
    {}
    ~PassPointer()
    {
        reset();
    }
    void reset()
    {
        NiD3DPass* previous = pass;
        if (previous)
        {
            if (!--previous->m_uiRefCount)
                previous->DestroyPass();
            pass = 0;
        }
    }
};

struct Particle
{
    float x, y, z, w, a, b, c, d, e, f, g, h;
    static void* operator new[](unsigned int size)
    {
        return particleMemoryManager.Game_DoHeapAlloc(size);
    }
};
class FUN_00ba53f0 : public BSShader
{
  public:
    unsigned int unk6c;
    void* particles;
    PassPointer firstPass, secondPass;
    ObjectPointer vertexProgram, pixelProgram;
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
    NiPoint3 position, direction;
    // The shader stores these rows at 0xec with 4-byte alignment. Keep their
    // storage unaligned; all accesses below use the shared scalar members.
    unsigned char rowStorage[4 * sizeof(ParticleShaderRow_00ba53f0)];
    FUN_00ba53f0(NiD3DVertexDeclaration* declaration);
};
inline void InitializeShaderRow(ParticleShaderRow_00ba53f0& row)
{
    row.x = 0;
    row.y = 0;
    row.z = 0;
    row.w = 0;
}

inline void ZeroShaderRow(ParticleShaderRow_00ba53f0& row)
{
    float components[4] = {0, 0, 0, 0};
    memcpy(&row, components, sizeof(components));
}

// Initializes a particle shader with a vertex declaration, sets up particle arrays based on renderer level, and zeroes out matrix rows.
// @fnv 0x00ba53f0
FUN_00ba53f0::FUN_00ba53f0(NiD3DVertexDeclaration* apVertexDeclaration)
{
    InitializeShaderRow(*reinterpret_cast<ParticleShaderRow_00ba53f0*>(rowStorage + 0 * sizeof(ParticleShaderRow_00ba53f0)));
    InitializeShaderRow(*reinterpret_cast<ParticleShaderRow_00ba53f0*>(rowStorage + 1 * sizeof(ParticleShaderRow_00ba53f0)));
    InitializeShaderRow(*reinterpret_cast<ParticleShaderRow_00ba53f0*>(rowStorage + 2 * sizeof(ParticleShaderRow_00ba53f0)));
    InitializeShaderRow(*reinterpret_cast<ParticleShaderRow_00ba53f0*>(rowStorage + 3 * sizeof(ParticleShaderRow_00ba53f0)));
    iShaderType = 14;
    m_bUsesNiRenderState = true;
    unk6c = 0x241;
    firstPass.reset();
    secondPass.reset();
    reinterpret_cast<ObjectPointer&>(m_spShaderDecl).reset(reinterpret_cast<RefObject*>(apVertexDeclaration));
    vertexProgram.reset(0);
    pixelProgram.reset(0);
    position = NiPoint3(0.0f, 0.0f, 0.0f);
    direction = NiPoint3(0.0f, 0.0f, 0.0f);
    ZeroShaderRow(*reinterpret_cast<ParticleShaderRow_00ba53f0*>(rowStorage + 0 * sizeof(ParticleShaderRow_00ba53f0)));
    ZeroShaderRow(*reinterpret_cast<ParticleShaderRow_00ba53f0*>(rowStorage + 1 * sizeof(ParticleShaderRow_00ba53f0)));
    ZeroShaderRow(*reinterpret_cast<ParticleShaderRow_00ba53f0*>(rowStorage + 2 * sizeof(ParticleShaderRow_00ba53f0)));
    ZeroShaderRow(*reinterpret_cast<ParticleShaderRow_00ba53f0*>(rowStorage + 3 * sizeof(ParticleShaderRow_00ba53f0)));
    unsigned int count = fnv_particle_shader_particle_count;
    if (!count)
    {
        count = fnv_particle_shader_renderer_level >= 2 ? 78 : 26;
        fnv_particle_shader_particle_count = count;
    }
    particles = new Particle[count];
    FUN_00ec61c0(particles, 0, count * 48);
    FUN_00ec61c0(&unk84, 0, 80);
}
}
