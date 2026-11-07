#include "../../include/NiD3DGPUProgramCache.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiD3DPixelShader.h"
#include "../../include/NiD3DShaderConstantMap.h"
#include "../../include/NiPropertyState.h"
#include "../../include/NiRefObject.h"
#include "../../include/Transform.h"
#include "../../include/NiTransform.h"
#include "../../include/Vec4.h"
#include "../../include/Bound.h"
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
#include "../../include/NiColorA.h"

inline Vec4::Vec4(const Vec4& other)
{
    *this = other;
}

inline NiTransform::NiTransform() {}

// src/bsshader/skyshader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/skyshader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern void* g_011ff8d8;

// @fnv 0x00b887b0
// src: COMMUNITY 0x00b887b0
void* __cdecl SkyShader_GetRTTI()
{
    return &g_011ff8d8;
}

extern void __cdecl AddToTwoCounters(int, int, int);
extern void __cdecl _FUN_00b98070(int, int);


// @fnv 0x00b8a1a0
// src: COMMUNITY 0x00b8a1a0
void __stdcall SkyShader_PostGeometry(const NiPropertyState* apState)
{
    void* pkSkyProp = apState->m_aspProps[3];
    int val = *(int*)((char*)pkSkyProp + 0x8c);
    if (val == 0 || val == 6)
        AddToTwoCounters(6, 7, 0);

    void* rendererSpecific = apState->m_aspProps[4];
    if (rendererSpecific && (*(unsigned char*)((char*)rendererSpecific + 0x18) & 1))
        _FUN_00b98070(0, 0);
}

struct S
{
    void FUN_00b88670();
    void* DestroyIfFlagged(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// Calls FUN_00b88670, then frees this with _delete when bit 0 of a1 is set, and returns this.
// @fnv 0x00b8a360
void* S::DestroyIfFlagged(unsigned int auiFlags)
{
    FUN_00b88670();
    if (auiFlags & 1)
        _delete(this, 0xf0);
    return this;
}

struct Struct00b884b0
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void vattach(void*);
    char _pad[104];
    void* m_aiIndexedValues[11];
    void AttachAll();
};
// @fnv 0x00b884b0
void Struct00b884b0::AttachAll()
{
    void** p = m_aiIndexedValues;
    int n = 11;
    do
    {
        vattach(*p);
        ++p;
    } while (--n);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);




inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<long volatile*>(&m_uiRefCount)) == 0)
        DeleteThis();
}
inline void NiD3DPixelShader::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<long volatile*>(&m_uiRefCount)) == 0)
        DeleteThis();
}
inline void NiD3DPass::DecRefCount()
{
    if (--m_uiRefCount == 0)
        Release();
}
template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0) {}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pObject)
{
    if (m_pObject != pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pObject;
    }
    return *this;
}

struct ShaderBase
{
    virtual ~ShaderBase();
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
};

struct FUN_00b88670 : ShaderBase
{
    NiPointer<NiD3DPass> m_aspPasses[11];
    NiPointer<NiD3DPixelShader> m_aspPixelShaders[11];
    NiPointer<NiD3DPixelShader> m_aspVertexShaders[8];
    virtual ~FUN_00b88670();
};

// Releases the shader's 11 pass pointers, 11 pixel shaders and 8 vertex shaders by assigning null to each NiPointer slot.
// @fnv 0x00b88670
FUN_00b88670::~FUN_00b88670()
{
    unsigned int i;
    for (i = 0; i < 11; i++)
        m_aspPasses[i] = 0;
    for (i = 0; i < 11; i++)
        m_aspPixelShaders[i] = 0;
    for (i = 0; i < 8; i++)
        m_aspVertexShaders[i] = 0;
}

extern unsigned int DAT_011f91e4;
struct Dev_Stand
{
    void* unk00;
    void* unk04;
    void* m_08;
    void ApplyPairToState(int a1);
};
struct Pair_Stand
{
    Dev_Stand* m_00;
    Dev_Stand* m_04;
};
struct Mgr_Stand
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
    Pair_Stand* m_24;
};
extern Mgr_Stand* DAT_0126f74c;
struct Node_Stand
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual int f51();
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
    void* m_70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* m_80;
};
struct Holder_Stand
{
    void* unk00;
    void* unk04;
    void* unk08;
    Node_Stand* m_0c;
};

// @fnv 0x00b89cc0
// src: COMMUNITY 0x00b89cc0
void __stdcall SkyShader_SetupGeometryTextures(Holder_Stand* apHolder)
{
    Mgr_Stand* mgr = DAT_0126f74c;
    Node_Stand* esi = apHolder->m_0c;
    if (esi->m_70 != 0)
    {
        Dev_Stand* d = mgr->m_24->m_00;
        d->m_08 = esi->m_70;
        d->ApplyPairToState(esi->f51());
        reinterpret_cast<NiD3DPass*>(d)->ApplyRenderStateChanges(false);
    }
    void* val;
    unsigned int v = DAT_011f91e4;
    if (esi->m_80 != 0)
    {
        val = esi->m_80;
    }
    else
    {
        if (v != 0x2d4 && v != 0x23c && v != 0x23a && v != 0x2d2 && v != 0x23d && v != 0x23e)
        {
            return;
        }
        val = esi->m_70;
        if (val == 0)
        {
            return;
        }
    }
    Dev_Stand* d = mgr->m_24->m_04;
    if (d == 0)
    {
        return;
    }
    d->m_08 = val;
    d->ApplyPairToState(esi->f51());
    reinterpret_cast<NiD3DPass*>(d)->ApplyRenderStateChanges(false);
}

class NiD3DVertexShader;
namespace fnv_00b8a1f0 {

// Unit-local view of NiPointer for 0x00b8a1f0 (namespace fnv_00b8a1f0): built on the shared NiPointer, that code does not compile or does not match.
template <class T> class NiPointer_00b8a1f0
{
  public:
    NiPointer_00b8a1f0();
    ~NiPointer_00b8a1f0();
    T* m_pObject;
};


extern NiColorA g_kDefaultColor;
extern NiColorA g_kColorA;
extern NiColorA g_kColorB;
extern NiColorA g_kColorC;
extern NiColorA g_kColorD;
extern NiColorA g_kColorE;
extern NiColorA g_kColorF;
extern NiColorA g_kColorG;

struct ShaderBase
{
    ShaderBase();
    virtual ~ShaderBase();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    bool unk24;
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
};

struct FUN_00b8a1f0 : ShaderBase
{
    FUN_00b8a1f0();
    virtual ~FUN_00b8a1f0();
    unsigned int m_uiPassCount;
    NiPointer_00b8a1f0<NiD3DPass> m_aspPasses[11];
    NiPointer_00b8a1f0<NiD3DPixelShader> m_aspPixelShaders[11];
    NiPointer_00b8a1f0<NiD3DVertexShader> m_aspVertexShaders[8];
};

// Initializes the shader: sets m_uiPassCount to 11, resets the global colors to g_kDefaultColor, and sets unk24 to true.
// @fnv 0x00b8a1f0
FUN_00b8a1f0::FUN_00b8a1f0()
{
    m_uiPassCount = 11;
    g_kColorD = g_kDefaultColor;
    g_kColorE = g_kDefaultColor;
    g_kColorF = g_kDefaultColor;
    g_kColorA = g_kDefaultColor;
    g_kColorB = g_kDefaultColor;
    g_kColorC = g_kDefaultColor;
    g_kColorG = g_kDefaultColor;
    unk24 = true;
}
}  // namespace fnv_00b8a1f0

extern void* g_011f9508;
void* __cdecl NiDX9ShaderDeclaration_Create(void*, int, int);
void* __cdecl Object_DispatchCommandFour(unsigned int);

struct SpawnedMgr
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
    virtual void v35(int, int, int, int, int);
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
};

struct SpawnedObject
{
    SpawnedObject();
    void* operator new(unsigned int sz)
    {
        return Object_DispatchCommandFour(sz);
    }
    void operator delete(void*)
    {}
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
    virtual void v48(void*);
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
    void Init0();
    void Init1();
    char _pad[0xf0 - 4];
};

// @fnv 0x00b8a390
// src: COMMUNITY 0x00b8a390
SpawnedObject* __cdecl SkyShader_CreateShader()
{
    SpawnedMgr* mgr = (SpawnedMgr*)NiDX9ShaderDeclaration_Create(g_011f9508, 3, 1);
    mgr->v35(0, 0, 0, 2, 0);
    mgr->v35(1, 5, 4, 3, 0);
    mgr->v35(2, 7, 5, 1, 0);
    mgr->v45();

    SpawnedObject* obj = new SpawnedObject();
    obj->v19();
    obj->Init0();
    obj->Init1();
    obj->v71();
    obj->v48(mgr);
    return obj;
}

struct ShaderStateTable
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
    void* pShader6C;
    void* pShader70;
    void* pShader74;
    void* pShader78;
    void* pShader7C;
    void* pShader80;
    void* pShader84;
    void* pShader88;
    void* pShader8C;
    void* pShader90;
    void* pShader94;
    void SelectShaderByType(unsigned int aeType);
};

extern void* g_pCurrentShaderObject;

// Sets g_pCurrentShaderObject to the shader pointer matching aeType, leaving it unchanged for unknown types.
// @fnv 0x00b884e0
void ShaderStateTable::SelectShaderByType(unsigned int aeType)
{
    switch (aeType)
    {
    case 0x9:
        g_pCurrentShaderObject = pShader6C;
        break;
    case 0x239:
        g_pCurrentShaderObject = pShader88;
        break;
    case 0x2D3:
        g_pCurrentShaderObject = pShader90;
        break;
    case 0x2D4:
        g_pCurrentShaderObject = pShader94;
        break;
    case 0x2D5:
        g_pCurrentShaderObject = pShader8C;
        break;
    case 0x2D2:
        g_pCurrentShaderObject = pShader70;
        break;
    case 0x23B:
        g_pCurrentShaderObject = pShader78;
        break;
    case 0x23D:
        g_pCurrentShaderObject = pShader7C;
        break;
    case 0x23E:
        g_pCurrentShaderObject = pShader80;
        break;
    case 0x23C:
        g_pCurrentShaderObject = pShader84;
        break;
    case 0x23A:
        g_pCurrentShaderObject = pShader74;
        break;
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

struct StageReturn

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

    int m_60;

    void ReturnToPool();
    void DecRefCount()
    {
        if (--m_60 == 0)
            ReturnToPool();
    }
};

void __cdecl AssignStageFromPool(StageReturn*& p);

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


inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<long volatile*>(&m_uiRefCount));
}
struct ElemObj

{

    void __thiscall SetNodeValue(int a, int b, int c);
};

ElemObj* __cdecl FUN_00e7f5d0();

void __cdecl FUN_00e804d0(void*);

struct ClusterObj

{

    unsigned int unk000;

    unsigned int unk004;

    unsigned int unk008;

    unsigned int unk00c;

    unsigned int unk010;

    int m_14;

    unsigned int unk018;

    unsigned int unk01c;

    unsigned int unk020;

    unsigned int unk024;

    unsigned int unk028;

    unsigned int unk02c;

    ElemObj* m_30;

    unsigned int unk034;

    unsigned int unk038;

    unsigned int unk03c;

    unsigned int unk040;

    NiRefObject* m_44;

    unsigned int unk048;

    unsigned int unk04c;

    unsigned int unk050;

    unsigned int unk054;

    unsigned int unk058;

    NiRefObject* m_5c;

    __forceinline void SetPixelShader(NiRefObject* p)
    {
        if (m_5c != p)
        {
            if (m_5c)
                m_5c->DecRefCount();
            m_5c = p;
            if (m_5c)
                m_5c->IncRefCount();
        }
    }
    __forceinline void SetVertexShader(NiRefObject* p)
    {
        if (m_44 != p)
        {
            if (m_44)
                m_44->DecRefCount();
            m_44 = p;
            if (m_44)
                m_44->IncRefCount();
        }
    }
    void __thiscall NiD3DPass_SetStage(int idx, StageReturn* s);
};

struct PassSlot
{
    ClusterObj* object;
    operator ClusterObj*() const
    {
        return object;
    }
};

struct ShaderPassBuilder

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

    unsigned int unk064;

    unsigned int unk068;

    PassSlot m_6c;

    PassSlot m_70;

    ClusterObj* m_74;

    ClusterObj* m_78;

    ClusterObj* m_7c;

    ClusterObj* m_80;

    ClusterObj* m_84;

    ClusterObj* m_88;

    PassSlot m_8c;

    ClusterObj* m_90;

    PassSlot m_94;

    NiRefObject* m_98;

    NiRefObject* m_9c;

    NiRefObject* m_a0;

    unsigned int unk0a4;

    NiRefObject* m_a8;

    NiRefObject* m_ac;

    NiRefObject* m_b0;

    NiRefObject* m_b4;

    NiRefObject* m_b8;

    NiRefObject* m_bc;

    NiRefObject* m_c0;

    NiRefObject* m_c4;

    NiRefObject* m_c8;

    NiRefObject* m_cc;

    NiRefObject* m_d0;

    NiRefObject* m_d4;

    NiRefObject* m_d8;

    NiRefObject* m_dc;

    NiRefObject* m_e0;

    bool InitPasses();
};

void __cdecl ConfigureBeamStage(StageReturn* self, int a, int b, int c, int d);

static __forceinline void AddProp(ClusterObj*& slot, int t, int a)

{

    ClusterObj* cp = slot;

    if (!cp->m_30)

        cp->m_30 = FUN_00e7f5d0();

    cp->m_30->SetNodeValue(t, a, 1);
}

static __forceinline void SetBlend(ClusterObj* cp, int source, int dest)
{
    if (!cp->m_30)
        cp->m_30 = FUN_00e7f5d0();
    cp->m_30->SetNodeValue(0x13, source, 1);
    if (!cp->m_30)
        cp->m_30 = FUN_00e7f5d0();
    cp->m_30->SetNodeValue(0x14, dest, 1);
}

// Creates each shader pass object if missing, configures its properties and blend modes, then assigns its pixel and vertex shaders; returns true.
// @fnv 0x00b887c0
bool ShaderPassBuilder::InitPasses()

{

    ShaderPassBuilder* self = this;

    StagePtr stage;

    ClusterObj*& pPass6c = self->m_6c.object;

    if (self->m_6c == 0)

    {

        FUN_00e804d0(&pPass6c);

        AssignStageFromPool(stage.m_pObject);

        ConfigureBeamStage(stage.m_pObject, 0, 3, 2, 1);

        pPass6c->NiD3DPass_SetStage(pPass6c->m_14, stage.m_pObject);

        AddProp(pPass6c, 0x1b, 1);

        SetBlend(pPass6c, 2, 2);

        AddProp(pPass6c, 0xe, 0);

        AddProp(pPass6c, 0xa8, 0);
    }

    pPass6c->SetPixelShader(self->m_ac);

    pPass6c->SetVertexShader(self->m_d0);

    ClusterObj*& pPass8c = self->m_8c.object;

    if (!self->m_8c)

    {

        FUN_00e804d0(&pPass8c);

        AssignStageFromPool(stage.m_pObject);

        ConfigureBeamStage(stage.m_pObject, 0, 3, 2, 1);

        pPass8c->NiD3DPass_SetStage(pPass8c->m_14, stage.m_pObject);

        AddProp(pPass8c, 0xf, 0);

        AddProp(pPass8c, 0x1b, 0);

        AddProp(pPass8c, 7, 1);

        AddProp(pPass8c, 0xe, 0);

        AddProp(pPass8c, 0x17, 4);

        AddProp(pPass8c, 0xa8, 8);
    }

    pPass8c->SetPixelShader(self->m_c0);

    pPass8c->SetVertexShader(self->m_e0);

    ClusterObj*& pPass90 = self->m_90;

    if (pPass90 == 0)

    {

        FUN_00e804d0(&pPass90);

        AssignStageFromPool(stage.m_pObject);

        ConfigureBeamStage(stage.m_pObject, 0, 3, 2, 1);

        pPass90->NiD3DPass_SetStage(pPass90->m_14, stage.m_pObject);

        AddProp(pPass90, 0x1b, 1);

        SetBlend(pPass90, 2, 2);

        AddProp(pPass90, 0xf, 0);

        AddProp(pPass90, 7, 1);

        AddProp(pPass90, 0xe, 0);

        AddProp(pPass90, 0x17, 4);

        AddProp(pPass90, 0xa8, 8);
    }

    pPass90->SetPixelShader(self->m_b8);

    pPass90->SetVertexShader(self->m_d8);

    ClusterObj*& pPass94 = self->m_94.object;

    if (!self->m_94)

    {

        FUN_00e804d0(&pPass94);

        AssignStageFromPool(stage.m_pObject);

        ConfigureBeamStage(stage.m_pObject, 0, 3, 2, 1);

        pPass94->NiD3DPass_SetStage(pPass94->m_14, stage.m_pObject);

        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage(stage.m_pObject, 1, 3, 2, 1);

        pPass94->NiD3DPass_SetStage(pPass94->m_14, stage.m_pObject);

        AddProp(pPass94, 0xf, 0);

        AddProp(pPass94, 0x1b, 1);

        SetBlend(pPass94, 1, 6);

        AddProp(pPass94, 7, 1);

        AddProp(pPass94, 0xe, 0);

        AddProp(pPass94, 0x17, 4);

        AddProp(pPass94, 0xa8, 8);
    }

    pPass94->SetPixelShader(self->m_bc);

    pPass94->SetVertexShader(self->m_dc);

    ClusterObj*& pPass70 = self->m_70.object;

    if (!self->m_70)

    {

        FUN_00e804d0(&pPass70);

        AssignStageFromPool(stage.m_pObject);

        ConfigureBeamStage(stage.m_pObject, 0, 3, 2, 1);

        pPass70->NiD3DPass_SetStage(pPass70->m_14, stage.m_pObject);

        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage(stage.m_pObject, 1, 3, 2, 1);

        pPass70->NiD3DPass_SetStage(pPass70->m_14, stage.m_pObject);

        AddProp(pPass70, 7, 0);

        AddProp(pPass70, 0xe, 0);

        AddProp(pPass70, 0x1b, 1);

        SetBlend(pPass70, 5, 2);

        AddProp(pPass70, 0x34, 0);

        AddProp(pPass70, 0xf, 0);

        AddProp(pPass70, 0xa8, 7);
    }

    pPass70->SetPixelShader(self->m_9c);

    pPass70->SetVertexShader(self->m_c8);

    ClusterObj*& pPass78 = self->m_78;

    if (!pPass78)

    {

        FUN_00e804d0(&pPass78);

        AssignStageFromPool(stage.m_pObject);

        ConfigureBeamStage(stage.m_pObject, 0, 3, 2, 1);

        pPass78->NiD3DPass_SetStage(pPass78->m_14, stage.m_pObject);

        AddProp(pPass78, 0xe, 0);

        AddProp(pPass78, 0x1b, 1);

        SetBlend(pPass78, 5, 2);

        AddProp(pPass78, 0xa8, 7);
    }

    pPass78->SetPixelShader(self->m_a8);

    pPass78->SetVertexShader(self->m_d4);

    ClusterObj*& pPass7c = self->m_7c;

    if (pPass7c == 0)

    {

        FUN_00e804d0(&pPass7c);

        AssignStageFromPool(stage.m_pObject);

        ConfigureBeamStage(stage.m_pObject, 0, 3, 2, 1);

        pPass7c->NiD3DPass_SetStage(pPass7c->m_14, stage.m_pObject);

        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage(stage.m_pObject, 1, 3, 2, 1);

        pPass7c->NiD3DPass_SetStage(pPass7c->m_14, stage.m_pObject);

        AddProp(pPass7c, 0xe, 0);

        AddProp(pPass7c, 0x1b, 1);

        SetBlend(pPass7c, 5, 6);

        AddProp(pPass7c, 0xa8, 7);
    }

    pPass7c->SetPixelShader(self->m_b0);
    pPass7c->SetVertexShader(self->m_c8);

    ClusterObj*& c = self->m_80;

    if (!c)

    {

        FUN_00e804d0(&c);

        AssignStageFromPool(stage.m_pObject);

        ConfigureBeamStage(stage.m_pObject, 0, 3, 2, 1);

        c->NiD3DPass_SetStage(c->m_14, stage.m_pObject);

        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage(stage.m_pObject, 1, 3, 2, 1);

        c->NiD3DPass_SetStage(c->m_14, stage.m_pObject);

        AddProp(c, 0xe, 0);

        AddProp(c, 0x1b, 1);

        SetBlend(c, 5, 6);

        AddProp(c, 0xa8, 7);
    }

    c->SetPixelShader(self->m_b4);
    c->SetVertexShader(self->m_cc);

    ClusterObj*& pPass84 = self->m_84;

    if (!pPass84)

    {

        FUN_00e804d0(&pPass84);

        AssignStageFromPool(stage.m_pObject);

        ConfigureBeamStage(stage.m_pObject, 0, 3, 2, 1);

        pPass84->NiD3DPass_SetStage(pPass84->m_14, stage.m_pObject);

        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage(stage.m_pObject, 1, 3, 2, 1);

        pPass84->NiD3DPass_SetStage(pPass84->m_14, stage.m_pObject);

        AddProp(pPass84, 0xe, 0);

        AddProp(pPass84, 0x1b, 1);

        SetBlend(pPass84, 5, 6);

        AddProp(pPass84, 0xa8, 7);
    }

    pPass84->SetPixelShader(self->m_9c);
    pPass84->SetVertexShader(self->m_c8);

    ClusterObj*& val = self->m_74;

    if (0 == val)

    {

        FUN_00e804d0(&val);

        AssignStageFromPool(stage.m_pObject);

        ConfigureBeamStage(stage.m_pObject, 0, 3, 2, 1);

        val->NiD3DPass_SetStage(val->m_14, stage.m_pObject);

        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage(stage.m_pObject, 1, 3, 2, 1);

        val->NiD3DPass_SetStage(val->m_14, stage.m_pObject);

        AddProp(val, 0xf, 1);

        AddProp(val, 0x18, 0);

        AddProp(val, 0x19, 5);

        AddProp(val, 0x1b, 1);

        SetBlend(val, 1, 2);
    }

    val->SetPixelShader(self->m_a0);

    val->SetVertexShader(self->m_c8);

    ClusterObj*& pPass88 = self->m_88;

    if (!pPass88)

    {

        FUN_00e804d0(&pPass88);

        AddProp(pPass88, 0xe, 0);

        AddProp(pPass88, 0x1b, 1);

        SetBlend(pPass88, 5, 6);

        AddProp(pPass88, 0xa8, 7);
    }

    pPass88->SetPixelShader(self->m_98);
    pPass88->SetVertexShader(self->m_c4);

    return true;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
inline void NiD3DShaderConstantMap::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<long volatile*>(&m_uiRefCount)) == 0)
        DeleteThis();
}
struct ConstantMapPointer
{
    NiD3DShaderConstantMap* object;
    void operator=(NiD3DShaderConstantMap* value)
    {
        if (object != value)
        {
            if (object)
                object->DecRefCount();
            object = value;
            if (value)
                InterlockedIncrement(reinterpret_cast<long volatile*>(&value->m_uiRefCount));
        }
    }
};
extern float DAT_011ff910;
extern float DAT_011ff920;
extern float DAT_011ff930;
extern float DAT_011ff8c8;
struct ConstantMapOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    void* renderer;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    ConstantMapPointer pixelConstants;
    ConstantMapPointer vertexConstants;
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
    void CreateShaderConstantMaps();
};
// Creates the pixel and vertex NiD3DShaderConstantMap objects if missing and registers their shader constants.
// @fnv 0x00b8a480
void ConstantMapOwner::CreateShaderConstantMaps()
{
    if (!pixelConstants.object)
    {
        pixelConstants = new NiD3DShaderConstantMap(reinterpret_cast<GraphicsRenderer*>(renderer), 2u);
        pixelConstants.object->SetConstant("Params", 0x10000005, 0, 4, 1, "", 8, 4, &unkE8, 0);
    }
    if (!vertexConstants.object)
    {
        vertexConstants = new NiD3DShaderConstantMap(reinterpret_cast<GraphicsRenderer*>(renderer), 0u);
        vertexConstants.object->SetConstant("WorldViewProjTranspose", 0x20000009, 0, 0, 4, 0, 0, 0, 0, 0);
        vertexConstants.object->SetConstant("WorldTranspose", 0x20000009, 0, 8, 4, 0, 0, 0, 0, 0);
        vertexConstants.object->SetConstant("Color0", 0x10000007, 0, 4, 1, "", 16, 4, &DAT_011ff910, 0);
        vertexConstants.object->SetConstant("Color1", 0x10000007, 0, 5, 1, "", 16, 4, &DAT_011ff920, 0);
        vertexConstants.object->SetConstant("Color2", 0x10000007, 0, 6, 1, "", 16, 4, &DAT_011ff930, 0);
        vertexConstants.object->SetConstant("eyepos", 0x10000007, 0, 7, 1, "", 16, 4, &DAT_011ff8c8, 0);
        vertexConstants.object->SetConstant("Params", 0x10000004, 0, 12, 1, "", 4, 4, &unkE4, 0);
    }
}

struct Pool_b899a0
{
    void* __thiscall Game_DoHeapAlloc(unsigned int size);
    void __thiscall FUN_00aa3e90(void* p);
};
extern Pool_b899a0 DAT_011f6238;
inline void* operator new[](unsigned int size, Pool_b899a0& pool)
{
    return pool.Game_DoHeapAlloc(size);
}
inline void operator delete[](void* p, Pool_b899a0& pool)
{
    pool.FUN_00aa3e90(p);
}
struct Pt3_b899a0
{
    float x;
    float y;
    float z;
    Pt3_b899a0()
    {}
    Pt3_b899a0(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
    {}
};
struct Col_b899a0
{
    float r;
    float g;
    float b;
    float a;
    Col_b899a0();
};
extern Col_b899a0 DAT_011a9bd0;
// Geometry-data prefix: the sphere is at 0x10 (NiGeometryData::m_kBound), not at 0 as in Bound.
struct SkyGeometryDataView
{
    int u00;
    int u04;
    int u08;
    int u0c;
    Pt3_b899a0 m_kCenter;
    float m_fBoundRadius;
};
struct Shape_b899a0 : NiRefObject
{
    Shape_b899a0(unsigned short a1, Pt3_b899a0* points, void* a3, Col_b899a0* colors, void* a5, unsigned short a6,
                 unsigned int a7, unsigned short a8, unsigned short* indices);
    void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    void operator delete(void*)
    {}
    int s08;
    int s0c;
    int s10;
    int s14;
    int s18;
    int s1c;
    int s20;
    int s24;
    int s28;
    int s2c;
    int s30;
    int s34;
    int s38;
    int s3c;
    int s40;
    int s44;
    int s48;
    int s4c;
    int s50;
    int s54;
    int s58;
    int s5c;
    int s60;
    int s64;
    int s68;
    int s6c;
    int s70;
    int s74;
    int s78;
    int s7c;
    int s80;
    int s84;
    int s88;
    int s8c;
    int s90;
    int s94;
    int s98;
    int s9c;
    int sa0;
    int sa4;
    int sa8;
    int sac;
    int sb0;
    int sb4;
    SkyGeometryDataView* m_spGeometryData;
    int sbc;
    int sc0;
};
struct ShapePtr_b899a0
{
    Shape_b899a0* m_p;
    ShapePtr_b899a0(Shape_b899a0* p) : m_p(p)
    {
        if (m_p)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&m_p->m_uiRefCount));
    }
    ~ShapePtr_b899a0()
    {
        if (m_p)
            m_p->DecRefCount();
    }
    void operator=(const ShapePtr_b899a0& o)
    {
        if (m_p != o.m_p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = o.m_p;
            if (m_p)
                InterlockedIncrement(reinterpret_cast<long volatile*>(&m_p->m_uiRefCount));
        }
    }
    Shape_b899a0* operator->() const
    {
        return m_p;
    }
    operator Shape_b899a0*() const
    {
        return m_p;
    }
};
struct Shell_b899a0
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
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
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
    int f7c;
    int f80;
    int f84;
    int f88;
    int f8c;
    int f90;
    int f94;
    unsigned char m_aucFlags98[8];
    int fa0;
    int fa4;
    int fa8;
    int fac;
    int fb0;
    int fb4;
    void FUN_00baf3c0();
    void AddProperties(Shape_b899a0* obj, unsigned int flag);
};
// Allocates a 4-vertex quad shape with two triangles, sets its bound to origin with radius 1000, and stores it in rspOut.
// @fnv 0x00b899a0
// src: COMMUNITY 0x00b899a0
void __cdecl SkyShader_CreateSkyQuad(ShapePtr_b899a0& rspOut)
{
    Pt3_b899a0* pkVerts = (Pt3_b899a0*)DAT_011f6238.Game_DoHeapAlloc(0x30);
    pkVerts[0] = Pt3_b899a0(-1.0f, -1.0f, 0.999999f);
    pkVerts[1] = Pt3_b899a0(1.0f, -1.0f, 0.999999f);
    pkVerts[2] = Pt3_b899a0(1.0f, 1.0f, 0.999999f);
    pkVerts[3] = Pt3_b899a0(-1.0f, 1.0f, 0.999999f);
    unsigned short* pusTris = (unsigned short*)DAT_011f6238.Game_DoHeapAlloc(0xc);
    pusTris[0] = 0;
    pusTris[1] = 1;
    pusTris[2] = 2;
    pusTris[3] = 3;
    pusTris[4] = 0;
    pusTris[5] = 2;
    Col_b899a0* pkColors = new (DAT_011f6238) Col_b899a0[4];
    for (unsigned int i = 0; i < 4; i++)
    {
        Col_b899a0 kColor = DAT_011a9bd0;
        pkColors[i] = kColor;
    }
    ShapePtr_b899a0 pShape = new Shape_b899a0(4, pkVerts, 0, pkColors, 0, 0, 0, 2, pusTris);
    SkyGeometryDataView* pkGeometryData = pShape->m_spGeometryData;
    pkGeometryData->m_kCenter = Pt3_b899a0(0.0f, 0.0f, 0.0f);
    pkGeometryData->m_fBoundRadius = 1000.0f;
    Shell_b899a0 kShell;
    kShell.FUN_00baf3c0();
    kShell.f00 = 6;
    kShell.f90 = 4;
    kShell.AddProperties(pShape, 1);
    rspOut = pShape;
}

struct Shader447
{
    void LoadShaders();
    bool InitPasses();
    bool SkyShader_ReloadShaders();
};
// @fnv 0x00b89960
// src: COMMUNITY 0x00b89960
bool Shader447::SkyShader_ReloadShaders()
{
    LoadShaders();
    return InitPasses();
}

struct GeoData
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
    void* data;
};
struct Geometry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Bound* bound;
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
    NiTransform world;

    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    GeoData* geometryData;
    void* skin;
};
struct Camera
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
    NiPoint3 position;
};
struct Context
{
    int unk00;
    int unk04;
    Camera* camera;
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
    bool relative;
};
Context* __cdecl BSShaderManager_GetCurrentAccumulator();
struct Property
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
    Vec4 color;

    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    float strength;
    unsigned short index;
    unsigned short flags;
    unsigned int kind;
};
struct Extra
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int flags;
};
struct RenderArg
{
    int unk00, unk04, unk08;
    Property* property;
    Extra* extra;
};
struct Device
{
    void NiDX9Renderer_SetModelTransform(NiTransform*, int);
};
struct Pass
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
    virtual void Render(void*, Geometry*, void*, int, void*, RenderArg*, int, NiTransform*, Bound*, int, int);
};
struct EndDevice
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
    virtual void End(Extra*);
};
struct ManagerAccess
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
    void* pass44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    void* pass5c;
};
extern Geometry** DAT_011f91e0;
extern unsigned int DAT_011f91e4;
extern Bound DAT_011f4288;
extern Camera* DAT_011f95d8;
extern Vec4 DAT_011fa2a0;
extern NiPoint3 DAT_011f474c;
extern float DAT_011ff8a8;
extern float DAT_011ff8b4[];
extern const double runtimeInitializationDouble6;
extern bool DAT_011F941E;
extern float DAT_011ad87c;
extern Vec4 DAT_011ff8e0, DAT_011ff8f0, DAT_011ff900;
struct Shader
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Device* device;
    EndDevice* endDevice;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    Pass* first;
    Pass* second;
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
    float sVertexIndex;
    float strength;
    float setting;
    void SkyShader_SetupGeometryConstants(float);
};
// Sets up transform and shader uniforms from a RenderArg, then dispatches the geometry to the first and second render passes and signals the end device.
// @fnv 0x00b89d80
// src: COMMUNITY 0x00b89d80
void Shader::SkyShader_SetupGeometryConstants(float apRenderArg)
{
    Vec4& out8c8 = *(Vec4*)&DAT_011ff8c8;
    Vec4& out910 = *(Vec4*)&DAT_011ff910;
    Vec4& out920 = *(Vec4*)&DAT_011ff920;
    Vec4& out930 = *(Vec4*)&DAT_011ff930;
    unsigned int mode = DAT_011f91e4;
    Geometry* geometry = *DAT_011f91e0;
    NiTransform* world = &geometry->world;
    Bound* bound = geometry->bound ? geometry->bound : &DAT_011f4288;
    void* data = geometry->geometryData->data;
    RenderArg* pRenderArg = *(RenderArg**)&apRenderArg;
    void* skin = geometry->skin;
    Property* property = pRenderArg->property;
    if (BSShaderManager_GetCurrentAccumulator()->relative)
    {
        NiTransform tTransform;
        tTransform = *world;
        NiPoint3 position = *reinterpret_cast<NiPoint3*>(&tTransform.m_Translate);
        position.x -= DAT_011f95d8->position.x;
        position.y -= DAT_011f95d8->position.y;
        position.z -= DAT_011f95d8->position.z;
        Camera* camera = BSShaderManager_GetCurrentAccumulator()->camera;
        if (camera)
        {
            position.x += camera->position.x;
            position.y += camera->position.y;
            position.z += camera->position.z;
        }
        *reinterpret_cast<NiPoint3*>(&tTransform.m_Translate) = position;
        device->NiDX9Renderer_SetModelTransform(&tTransform, 0);
    }
    else
        device->NiDX9Renderer_SetModelTransform(world, 0);
    Vec4 value = DAT_011fa2a0;
    NiPoint3 tDelta;
    tDelta.x = value.x - DAT_011f474c.x;
    tDelta.y = value.y - DAT_011f474c.y;
    tDelta.z = value.z - DAT_011f474c.z;
    value.x = tDelta.x;
    value.y = tDelta.y;
    value.z = tDelta.z;
    value.w = 0.0f;
    out8c8 = value;
    if (mode == 5)
        out8c8.z = -DAT_011ff8a8 / runtimeInitializationDouble6;
    if (property->kind == 3)
    {
        strength = property->strength;
        sVertexIndex = DAT_011ff8b4[property->index];
    }
    else
        strength = 0.0f;
    if (DAT_011F941E)
        setting = DAT_011ad87c;
    switch (property->kind)
    {
    case 0:
    case 1:
    case 3:
    case 5:
    case 6:
    case 7:
        out910 = property->color;
        break;
    case 2:
        out910 = DAT_011ff8e0;
        out920 = DAT_011ff8f0;
        out930 = DAT_011ff900;
        break;
    default:
        out910.x = 0;
        out910.y = 0;
        out910.z = 0;
        out910.w = 1;
        out920.x = 0;
        out920.y = 0;
        out920.z = 0;
        out930.x = 0;
        out930.y = 0;
        out930.z = 0;
    }
    if (first)
    {
        void* pass = ((ManagerAccess*)DAT_0126f74c)->pass44;
        if (pass)
            first->Render(pass, geometry, skin, 0, data, pRenderArg, 0, world, bound, 0, 1);
    }
    if (second)
    {
        void* pass = ((ManagerAccess*)DAT_0126f74c)->pass5c;
        if (pass)
            second->Render(pass, geometry, skin, 0, data, pRenderArg, 0, world, bound, 0, 1);
    }
    if (property->kind == 0 || property->kind == 6)
        AddToTwoCounters(6, 0, 0);
    Extra* extra = pRenderArg->extra;
    if (extra && (extra->flags & 1))
        endDevice->End(extra);
}

#include <stdlib.h>
void* __cdecl fnv_zlib_memset(void*, int, unsigned int);

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
void __cdecl FUN_00be0c00(const char*, char*);
int __cdecl BSsprintf(char*, int, const char*, ...);
extern float DAT_011ff8ac;
extern float DAT_011ff8b0;
struct SkyShader
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
    NiRefObject* m_98;
    NiRefObject* m_9c;
    NiRefObject* m_a0;
    NiRefObject* m_a4;
    NiRefObject* m_a8;
    NiRefObject* m_ac;
    NiRefObject* m_b0;
    NiRefObject* m_b4;
    NiRefObject* m_b8;
    NiRefObject* m_bc;
    NiRefObject* m_c0;
    NiRefObject* m_c4;
    NiRefObject* m_c8;
    NiRefObject* m_cc;
    NiRefObject* m_d0;
    NiRefObject* m_d4;
    NiRefObject* m_d8;
    NiRefObject* m_dc;
    NiRefObject* m_e0;
    NiRefObject* FUN_00be0fe0(const char*, const char**, const char*, const char*);
    NiRefObject* FUN_00be1750(const char*, const char**, const char*, const char*);
    void LoadShaders();
};
// Requests vertex and pixel shader objects for sky shader variants and stores the returned pointers in member fields.
// @fnv 0x00b874f0
// src: XBOX_PDB 0x00b874f0
void SkyShader::LoadShaders()
{
    char compiledName[260];
    char sourceName[260];
    char numberBuffer[349];
    const char* shader3[19];
    const char* shader16[19];
    const char* shader0[19];
    shader0[0] = "sky\\v\\sky.v.hlsl";
    shader0[1] = 0;
    shader0[2] = 0;
    fnv_zlib_memset(shader0 + 3, 0, 64);
    FUN_00be0c00(shader0[0], sourceName);
    BSsprintf(compiledName, 260, "SKY.vso");
    NiRefObject* next0 =
        FUN_00be0fe0(sourceName, shader0 + 1, NiD3DGPUProgramCache::GetVertexShaderProfile(), compiledName);
    if (m_98 != next0)
    {
        if (m_98)
            m_98->DecRefCount();
        m_98 = next0;
        if (next0)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&next0->m_uiRefCount));
    }
    const char* shader1[19];
    shader1[0] = "sky\\v\\sky.v.hlsl";
    shader1[1] = "TEX";
    shader1[2] = 0;
    shader1[3] = 0;
    shader1[4] = 0;
    fnv_zlib_memset(shader1 + 5, 0, 56);
    FUN_00be0c00(shader1[0], sourceName);
    BSsprintf(compiledName, 260, "SKYT.vso");
    NiRefObject* next1 =
        FUN_00be0fe0(sourceName, shader1 + 1, NiD3DGPUProgramCache::GetVertexShaderProfile(), compiledName);
    if (m_9c != next1)
    {
        if (m_9c)
            m_9c->DecRefCount();
        m_9c = next1;
        if (next1)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&next1->m_uiRefCount));
    }
    const char* shader2[19];
    shader2[0] = "sky\\v\\sky.v.hlsl";
    shader2[1] = "DEPTH_VALUE";
    shader2[2] = "0.99995f";
    shader2[3] = "TEX";
    shader2[4] = 0;
    shader2[5] = 0;
    shader2[6] = 0;
    fnv_zlib_memset(shader2 + 7, 0, 48);
    FUN_00be0c00(shader2[0], sourceName);
    BSsprintf(compiledName, 260, "SKYMM.vso");
    NiRefObject* next2 =
        FUN_00be0fe0(sourceName, shader2 + 1, NiD3DGPUProgramCache::GetVertexShaderProfile(), compiledName);
    if (m_a0 != next2)
    {
        if (m_a0)
            m_a0->DecRefCount();
        m_a0 = next2;
        if (next2)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&next2->m_uiRefCount));
    }
    shader16[0] = "sky\\v\\sky.v.hlsl";
    shader16[1] = "DEPTH_VALUE";
    shader16[2] = "1.0f";
    shader16[3] = "HORIZFADE";
    shader16[4] = 0;
    shader16[5] = 0;
    shader16[6] = 0;
    fnv_zlib_memset(shader16 + 7, 0, 48);
    FUN_00be0c00(shader16[0], sourceName);
    BSsprintf(compiledName, 260, "SKYSTARS.vso");
    NiRefObject* next3 =
        FUN_00be0fe0(sourceName, shader16 + 1, NiD3DGPUProgramCache::GetVertexShaderProfile(), compiledName);
    if (m_a8 != next3)
    {
        if (m_a8)
            m_a8->DecRefCount();
        m_a8 = next3;
        if (next3)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&next3->m_uiRefCount));
    }
    const char* shader4[19];
    shader4[0] = "sky\\v\\sky.v.hlsl";
    shader4[1] = "OCCLUSION";
    shader4[2] = 0;
    shader4[3] = 0;
    shader4[4] = 0;
    fnv_zlib_memset(shader4 + 5, 0, 56);
    FUN_00be0c00(shader4[0], sourceName);
    BSsprintf(compiledName, 260, "SKYOCC.vso");
    NiRefObject* next4 =
        FUN_00be0fe0(sourceName, shader4 + 1, NiD3DGPUProgramCache::GetVertexShaderProfile(), compiledName);
    if (m_ac != next4)
    {
        if (m_ac)
            m_ac->DecRefCount();
        m_ac = next4;
        if (next4)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&next4->m_uiRefCount));
    }
    const char* shader5[19];
    shader5[0] = "sky\\v\\sky.v.hlsl";
    shader5[1] = "TEX";
    shader5[2] = 0;
    shader5[3] = "CLOUDS";
    shader5[4] = 0;
    shader5[5] = 0;
    shader5[6] = 0;
    fnv_zlib_memset(shader5 + 7, 0, 48);
    FUN_00be0c00(shader5[0], sourceName);
    BSsprintf(compiledName, 260, "SKYCLOUDS.vso");
    NiRefObject* next5 =
        FUN_00be0fe0(sourceName, shader5 + 1, NiD3DGPUProgramCache::GetVertexShaderProfile(), compiledName);
    if (m_b0 != next5)
    {
        if (m_b0)
            m_b0->DecRefCount();
        m_b0 = next5;
        if (next5)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&next5->m_uiRefCount));
    }
    const char* shader13[19] = {"sky\\v\\sky.v.hlsl", "HORIZFADE", 0, "TEX", 0, "CLOUDS", 0, 0, 0};
    FUN_00be0c00(shader5[0], sourceName);
    BSsprintf(compiledName, 260, "SKYCLOUDSFADE.vso");
    NiRefObject* next6 =
        FUN_00be0fe0(sourceName, shader13 + 1, NiD3DGPUProgramCache::GetVertexShaderProfile(), compiledName);
    if (m_b4 != next6)
    {
        if (m_b4)
            m_b4->DecRefCount();
        m_b4 = next6;
        if (next6)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&next6->m_uiRefCount));
    }
    const char* shader7[19];
    shader7[0] = "sky\\p\\sky.p.hlsl";
    shader7[1] = 0;
    shader7[2] = 0;
    fnv_zlib_memset(shader7 + 3, 0, 64);
    FUN_00be0c00(shader7[0], sourceName);
    BSsprintf(compiledName, 260, "SKY.pso");
    NiRefObject* next7 =
        FUN_00be1750(sourceName, shader7 + 1, NiD3DGPUProgramCache::GetPixelShaderProfile(false), compiledName);
    if (m_c4 != next7)
    {
        if (m_c4)
            m_c4->DecRefCount();
        m_c4 = next7;
        if (next7)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&next7->m_uiRefCount));
    }
    const char* shader8[19];
    shader8[0] = "sky\\p\\sky.p.hlsl";
    shader8[1] = "TEX";
    shader8[2] = 0;
    shader8[3] = 0;
    shader8[4] = 0;
    fnv_zlib_memset(shader8 + 5, 0, 56);
    FUN_00be0c00(shader8[0], sourceName);
    BSsprintf(compiledName, 260, "SKYTEX.pso");
    NiRefObject* next8 =
        FUN_00be1750(sourceName, shader8 + 1, NiD3DGPUProgramCache::GetPixelShaderProfile(false), compiledName);
    if (m_c8 != next8)
    {
        if (m_c8)
            m_c8->DecRefCount();
        m_c8 = next8;
        if (next8)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&next8->m_uiRefCount));
    }
    const char* shader9[19];
    shader9[0] = "sky\\p\\sky.p.hlsl";
    shader9[1] = "HORIZFADE";
    shader9[2] = 0;
    shader9[3] = "TEX";
    shader9[4] = 0;
    shader9[5] = 0;
    shader9[6] = 0;
    fnv_zlib_memset(shader9 + 7, 0, 48);
    FUN_00be0c00(shader8[0], sourceName);
    BSsprintf(compiledName, 260, "SKYTEXFADE.pso");
    NiRefObject* next9 =
        FUN_00be1750(sourceName, shader9 + 1, NiD3DGPUProgramCache::GetPixelShaderProfile(false), compiledName);
    if (m_cc != next9)
    {
        if (m_cc)
            m_cc->DecRefCount();
        m_cc = next9;
        if (next9)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&next9->m_uiRefCount));
    }
    _gcvt(DAT_011ff8ac, 12, numberBuffer);
    const char* shader10[19];
    shader10[0] = "sky\\p\\sky.p.hlsl";
    shader10[1] = "OCCLUSION";
    shader10[2] = 0;
    shader10[3] = 0;
    shader10[4] = 0;
    fnv_zlib_memset(shader10 + 5, 0, 56);
    FUN_00be0c00(shader10[0], sourceName);
    BSsprintf(compiledName, 260, "SKYSUNOCCL.pso");
    NiRefObject* next10 =
        FUN_00be1750(sourceName, shader10 + 1, NiD3DGPUProgramCache::GetPixelShaderProfile(false), compiledName);
    if (m_d0 != next10)
    {
        if (m_d0)
            m_d0->DecRefCount();
        m_d0 = next10;
        if (next10)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&next10->m_uiRefCount));
    }
    const char* shader11[19];
    shader11[0] = "sky\\p\\sky.p.hlsl";
    shader11[1] = "HORIZFADE";
    shader11[2] = 0;
    shader11[3] = 0;
    shader11[4] = 0;
    fnv_zlib_memset(shader11 + 5, 0, 56);
    FUN_00be0c00(shader11[0], sourceName);
    BSsprintf(compiledName, 260, "SKYSHORIZFADE.pso");
    NiRefObject* next11 =
        FUN_00be1750(sourceName, shader11 + 1, NiD3DGPUProgramCache::GetPixelShaderProfile(false), compiledName);
    if (m_d4 != next11)
    {
        if (m_d4)
            m_d4->DecRefCount();
        m_d4 = next11;
        if (next11)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&next11->m_uiRefCount));
    }
    const char* shader12[19];
    shader12[0] = "sky\\v\\sky.v.hlsl";
    shader12[1] = "DEPTH_VALUE";
    shader12[2] = "0.999999";
    shader12[3] = "SI";
    shader12[4] = 0;
    shader12[5] = 0;
    shader12[6] = 0;
    fnv_zlib_memset(shader12 + 7, 0, 48);
    FUN_00be0c00(shader12[0], sourceName);
    BSsprintf(compiledName, 260, "SKYFAR.vso");
    NiRefObject* next12 =
        FUN_00be0fe0(sourceName, shader12 + 1, NiD3DGPUProgramCache::GetVertexShaderProfile(), compiledName);
    if (m_b8 != next12)
    {
        if (m_b8)
            m_b8->DecRefCount();
        m_b8 = next12;
        if (next12)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&next12->m_uiRefCount));
    }
    const char* shader6[19] = {"sky\\v\\sky.v.hlsl", "DEPTH_VALUE", "0.999999", "SI", 0, "SI_CLOUDS", "", 0, 0};
    FUN_00be0c00(shader6[0], sourceName);
    BSsprintf(compiledName, 260, "SKYCLOUDSI.vso");
    NiRefObject* next13 =
        FUN_00be0fe0(sourceName, shader6 + 1, NiD3DGPUProgramCache::GetVertexShaderProfile(), compiledName);
    if (m_bc != next13)
    {
        if (m_bc)
            m_bc->DecRefCount();
        m_bc = next13;
        if (next13)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&next13->m_uiRefCount));
    }
    const char* shader14[19];
    shader14[0] = "sky\\v\\sky_quad.v.hlsl";
    shader14[1] = "SI";
    shader14[2] = 0;
    shader14[3] = 0;
    shader14[4] = 0;
    fnv_zlib_memset(shader14 + 5, 0, 56);
    FUN_00be0c00(shader14[0], sourceName);
    BSsprintf(compiledName, 260, "SKYQUADSI.vso");
    NiRefObject* next14 =
        FUN_00be0fe0(sourceName, shader14 + 1, NiD3DGPUProgramCache::GetVertexShaderProfile(), compiledName);
    if (m_c0 != next14)
    {
        if (m_c0)
            m_c0->DecRefCount();
        m_c0 = next14;
        if (next14)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&next14->m_uiRefCount));
    }
    _gcvt(DAT_011ff8b0, 12, numberBuffer);
    const char* shader15[19];
    shader15[0] = "sky\\p\\sky.p.hlsl";
    shader15[1] = "SI";
    shader15[2] = numberBuffer;
    shader15[3] = 0;
    shader15[4] = 0;
    fnv_zlib_memset(shader15 + 5, 0, 56);
    FUN_00be0c00(shader15[0], sourceName);
    BSsprintf(compiledName, 260, "SKYSI.pso");
    NiRefObject* next15 =
        FUN_00be1750(sourceName, shader15 + 1, NiD3DGPUProgramCache::GetPixelShaderProfile(false), compiledName);
    if (m_e0 != next15)
    {
        if (m_e0)
            m_e0->DecRefCount();
        m_e0 = next15;
        if (next15)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&next15->m_uiRefCount));
    }
    _gcvt(DAT_011ff8ac, 12, numberBuffer);
    shader3[0] = "sky\\p\\sky.p.hlsl";
    shader3[1] = "SI";
    shader3[2] = numberBuffer;
    shader3[3] = "SI_SUN";
    shader3[4] = 0;
    shader3[5] = 0;
    shader3[6] = 0;
    fnv_zlib_memset(shader3 + 7, 0, 48);
    FUN_00be0c00(shader3[0], sourceName);
    BSsprintf(compiledName, 260, "SKYSISUN.pso");
    NiRefObject* next16 =
        FUN_00be1750(sourceName, shader3 + 1, NiD3DGPUProgramCache::GetPixelShaderProfile(false), compiledName);
    if (m_d8 != next16)
    {
        if (m_d8)
            m_d8->DecRefCount();
        m_d8 = next16;
        if (next16)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&next16->m_uiRefCount));
    }
    const char* shader17[19];
    shader17[0] = "sky\\p\\sky.p.hlsl";
    shader17[1] = "SI";
    shader17[2] = 0;
    shader17[3] = "SI_CLOUDS";
    shader17[4] = 0;
    shader17[5] = 0;
    shader17[6] = 0;
    fnv_zlib_memset(shader17 + 7, 0, 48);
    FUN_00be0c00(shader17[0], sourceName);
    BSsprintf(compiledName, 260, "SKYSICLOUDS.pso");
    NiRefObject* next17 =
        FUN_00be1750(sourceName, shader17 + 1, NiD3DGPUProgramCache::GetPixelShaderProfile(false), compiledName);
    if (m_dc != next17)
    {
        if (m_dc)
            m_dc->DecRefCount();
        m_dc = next17;
        if (next17)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&next17->m_uiRefCount));
    }
}
