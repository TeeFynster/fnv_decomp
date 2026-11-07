#include "../../include/ImageSpaceTexture.h"
// bsshader/tallgrassshader.cpp: TallGrassShader, Self, ShaderRegister, TallGrassPrograms and more (25 functions)

#include "tallgrassshader_decls.h"
#include "../../include/BSFadeNode.h"
#include "../../include/BSShader.h"
#include "../../include/AutoMemContext.h"
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
#include "../../include/NiDX9Renderer.h"

extern __declspec(thread) int gShaderAllocationContext;

inline AutoMemContext::AutoMemContext(int context)
{
    m_eMemoryContext = static_cast<MEM_CONTEXT>(gShaderAllocationContext);
    gShaderAllocationContext = context;
}

inline AutoMemContext::~AutoMemContext()
{
    gShaderAllocationContext = m_eMemoryContext;
}

// Creates the constants object with the given count (defaulting to 5 when count is -1) if it does not already exist.
// @fnv 0x00ba95e0
void TallGrassShader::InitializeConstants(unsigned int count)
{
    if (!constants)
    {
        if (count == (unsigned int)-1)
            count = 5;
        constants = new FUN_00ba94b0(count);
    }
}

struct Prop
{
    char pad[0x20];
    unsigned int flags;
    void BSShaderProperty_SetMotionBlurred(bool);
    void BSShaderProperty_SetFlag(int, int);
};
struct PropHelper
{
    Prop* GetProperty(unsigned int);
};
struct Node;
struct Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Node* v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
    virtual int v7();
};
struct Node
{
    char pad[0xa0];
    Obj** kids;
    unsigned short cap;
    unsigned short count;
};
// @fnv 0x00ba90a0
// src: COMMUNITY 0x00ba90a0
void BSShaderProperty_ToggleMotionBlurRecurse(Obj* apObj)
{
    if (!apObj)
        return;
    if (apObj->v7())
    {
        Prop* p = ((PropHelper*)apObj)->GetProperty(3);
        if (p)
            p->BSShaderProperty_SetMotionBlurred((p->flags & 0x10) <= 0);
        return;
    }
    Node* n = apObj->v3();
    if (n)
    {
        unsigned int cnt = n->count;
        for (unsigned int i = 0; i < cnt; i++)
        {
            Obj* c = n->kids[i];
            if (c)
                BSShaderProperty_ToggleMotionBlurRecurse(c);
        }
    }
}

namespace fnv_00ba9120 {
struct Prop
{
    char pad[0x20];
    unsigned char flags;
    void BSShaderProperty_SetMotionBlurred(int);
    void BSShaderProperty_SetFlag(int, int);
};
struct PropHelper
{
    Prop* GetProperty(unsigned int);
};
struct Node;
struct Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Node* v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
    virtual int v7();
};
struct Node
{
    char pad[0xa0];
    Obj** kids;
    unsigned short cap;
    unsigned short count;
};
// @fnv 0x00ba9120
// src: COMMUNITY 0x00ba9120
void BSShaderProperty_SetMotionBlurRecurse(Obj* pObj, int a)
{
    if (!pObj)
        return;
    if (pObj->v7())
    {
        Prop* p = ((PropHelper*)pObj)->GetProperty(3);
        if (p)
            p->BSShaderProperty_SetMotionBlurred(a);
        return;
    }
    Node* n = pObj->v3();
    if (n)
    {
        unsigned int cnt = n->count;
        for (unsigned int i = 0; i < cnt; i++)
        {
            Obj* c = n->kids[i];
            if (c)
                BSShaderProperty_SetMotionBlurRecurse(c, a);
        }
    }
}
}  // namespace fnv_00ba9120

namespace fnv_00ba91a0 {
struct Prop
{
    char pad[0x20];
    unsigned char flags;
    void BSShaderProperty_SetMotionBlurred(int);
    void BSShaderProperty_SetFlag(int, bool);
};
struct PropHelper
{
    Prop* GetProperty(unsigned int);
};
struct Node;
struct Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Node* v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
    virtual int v7();
};
struct Node
{
    char pad[0xa0];
    Obj** kids;
    unsigned short cap;
    unsigned short count;
};
// @fnv 0x00ba91a0
// src: XBOX_PDB 0x00ba91a0
void BSShaderProperty_SetFlagRecurse(Obj* pObj, int a, bool b)
{
    if (!pObj)
        return;
    if (pObj->v6())
    {
        Prop* p = ((PropHelper*)pObj)->GetProperty(3);
        if (p)
            p->BSShaderProperty_SetFlag(a, b);
        return;
    }
    Node* n = pObj->v3();
    if (n)
    {
        unsigned int cnt = n->count;
        for (unsigned int i = 0; i < cnt; i++)
        {
            Obj* c = n->kids[i];
            if (c)
                BSShaderProperty_SetFlagRecurse(c, a, b);
        }
    }
}
}  // namespace fnv_00ba91a0

extern int DAT_010b8480;
// @fnv 0x00ba9230
// src: GUESS 0x00ba9230 (confidence: low)
void __fastcall Tallgrassshader_ReleaseStorage_00ba9230(void** self, int)
{
    void* p = self[1];
    self[0] = &DAT_010b8480;
    g_memoryManager.Deallocate(p);
}

struct FUN_00ba8e50
{
    static __forceinline void* operator new(unsigned int size)
    {
        return BSFadeNode::operator new(size);
    }
    int pad[24];
    FUN_00ba8e50();
};
// Allocates and constructs a new property object, returning the pointer.
// @fnv 0x00ba9250
// src: EXE 0x00ba9250
FUN_00ba8e50* BSShaderProperty_CreateObject()
{
    return new FUN_00ba8e50;
}

struct FUN_00bac160_holder
{
    void ConfigureBeamPasses();
};
// @fnv 0x00bac8b0
// src: XBOX_PDB 0x00bac8b0
void __fastcall TallGrassShader_ReloadShaders(FUN_00bac160_holder* self, int)
{
    void** vt = *(void***)self;
    ((void(__thiscall*)(void*))vt[79])(self);
    self->ConfigureBeamPasses();
}

struct U
{
    char pad[8];
    int f;
};
struct T
{
    char pad[4];
    U* a;
    U* b;
    U* c;
};
struct S
{
    char pad[0x24];
    T* t;
};
extern S* DAT_0126f74c;
extern int DAT_011f95e4;
extern int DAT_011f95e8;
// @fnv 0x00bac8d0
// src: XBOX_PDB 0x00bac8d0
void __stdcall TallGrassShader_SetupPassTextures(unsigned int k)
{
    S* g = DAT_0126f74c;
    if ((k >= 0x1c && k <= 0x25) || k - 0x262 <= 9)
    {
        g->t->a->f = DAT_011f95e4;
        g->t->b->f = DAT_011f95e8;
    }
    if ((k >= 0x30 && k <= 0x39) || k - 0x276 <= 9)
    {
        g->t->b->f = DAT_011f95e4;
        g->t->c->f = DAT_011f95e8;
    }
}

namespace fnv_00bac950 {
struct TextureReceiver
{
    void* BSRenderedTexture_GetTexture(int);
};
struct Poly
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
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
    virtual void* s45();
};
struct Arg
{
    char pad[0xc];
    Poly* p;
};
struct Slot
{
    char pad[8];
    void* f;
};
struct Tbl
{
    Slot* a;
    Slot* b;
};
struct Cx
{
    char pad[0x24];
    Tbl* t;
};
struct Inner
{
    char pad[0x10c];
    TextureReceiver* tr;
};
struct GeomStub
{
    Inner* in;
};
extern GeomStub** DAT_011f91e0;
extern unsigned int DAT_011f91e4;
extern Cx* DAT_0126f74c;
struct Self
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
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
    virtual int s66();
    int TallGrassShader_SetupGeometryTextures(Arg* arg);
};
// Stores the result of p->s45() into the first slot, and for k in 0x284..0x287 also stores a texture from DAT_011f91e0[3] into the second slot, then calls s66().
// @fnv 0x00bac950
// src: XBOX_PDB 0x00bac950
int Self::TallGrassShader_SetupGeometryTextures(Arg* arg)
{
    unsigned int k = DAT_011f91e4;
    Poly* p = arg->p;
    Slot* a = DAT_0126f74c->t->a;
    a->f = p->s45();
    if (k - 0x284 <= 3)
    {
        Slot* b = DAT_0126f74c->t->b;
        b->f = DAT_011f91e0[3]->in->tr->BSRenderedTexture_GetTexture(0);
    }
    return s66();
}
}  // namespace fnv_00bac950

void __fastcall FUN_00baa570(void*);
void __cdecl __Dummy_00b6fef0(void*, unsigned int);
// Calls FUN_00baa570 on self, then if bit 0 of flags is set calls __Dummy_00b6fef0 with self and 0x1e0, and returns self.
// @fnv 0x00baced0
void* __fastcall FUN_00baced0(void* self, int, unsigned int flags)
{
    FUN_00baa570(self);
    if (flags & 1)
        __Dummy_00b6fef0(self, 0x1e0);
    return self;
}

struct NiTexture;

extern ImageSpaceTexture DAT_012005a4;
// @fnv 0x00bad4a0
// src: COMMUNITY 0x00bad4a0
void ImageSpaceEffectHDR_ClearAdaptedLight()
{
    if (DAT_012005a4.GetTexture())
    {
        DAT_012005a4.AddRenderedTexture();
        DAT_012005a4.ImageSpaceTexture_ClearTexture();
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RefObj_bacd00
{
    virtual ~RefObj_bacd00();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
            DeleteThis();
    }
};
struct RefPtr_bacd00
{
    RefObj_bacd00* m_pObject;
    RefPtr_bacd00& operator=(RefObj_bacd00* pObject)
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
struct V4_bacd00
{
    float x, y, z, w;
    V4_bacd00(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
    {}
};
struct G4_bacd00
{
    int a, b, c, d;
};
extern G4_bacd00 DAT_011a9bd0;
extern G4_bacd00 DAT_01200570;
extern int _fnv_particle_shader_renderer_level;
extern MemoryManager _g_memoryManager;
struct Elem_bacd00
{
    float f[4];
    static void* operator new[](unsigned int s)
    {
        return _g_memoryManager.Allocate(s);
    }
};
struct FUN_00bacd00 : BSShader
{
    NiPointer<NiD3DPass> m_aspPass[0x2c];
    float m_f11c;
    char pad120[8];
    NiPointer<NiD3DPixelShader> m_aspPS[0x18];
    NiPointer<NiD3DPixelShader> m_aspPS2[7];
    Elem_bacd00* m_pReferencedObject;
    int m_i1a8;
    unsigned short m_usElementCount;
    V4_bacd00 m_k1;
    V4_bacd00 m_k2;
    V4_bacd00 m_k3;
    FUN_00bacd00(RefObj_bacd00* pDecl);
    virtual ~FUN_00bacd00();
};

// @fnv 0x00bacd00
FUN_00bacd00::FUN_00bacd00(RefObj_bacd00* pDecl)
    : m_k1(0.0f, 0.0f, 0.0f, 0.0f), m_k2(0.0f, 0.0f, 0.0f, 0.0f), m_k3(0.0f, 0.0f, 0.0f, 0.0f)
{
    iShaderType = 6;
    reinterpret_cast<RefPtr_bacd00&>(m_spShaderDecl) = pDecl;
    m_f11c = 0.0f;
    DAT_01200570 = DAT_011a9bd0;
    if (_fnv_particle_shader_renderer_level >= 2)
        m_usElementCount = 0xe4;
    else
        m_usElementCount = 0x50;
    m_pReferencedObject = new Elem_bacd00[m_usElementCount];
    m_i1a8 = 0;
}

class NiRenderer;
namespace fnv_00bacf00 {
struct NiD3DVertexDeclaration
{
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void SetEntry(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    virtual void d36();
    virtual void SetEntry2(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                           unsigned int, unsigned int);
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void Finish();
    static NiD3DVertexDeclaration* Create(NiRenderer*, unsigned int, unsigned int);
};
extern NiRenderer* DAT_011f9508;
struct FUN_00bacd00
{
    static __forceinline void* operator new(unsigned int size)
    {
        return BSFadeNode::operator new(size);
    }
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void V4c();
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
    virtual void Vc0(NiD3DVertexDeclaration*);
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
    virtual void V11c();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void V13c();
    virtual void V140();
    char pad[0x1dc];
    FUN_00bacd00(NiD3DVertexDeclaration*);
};
// @fnv 0x00bacf00
FUN_00bacd00* CreateShaderFadeNode()
{
    AutoMemContext tempMemContext(0x1c);
    NiD3DVertexDeclaration* m_pVertexDeclaration1 = NiD3DVertexDeclaration::Create(DAT_011f9508, 5, 1);
    m_pVertexDeclaration1->SetEntry(0, 0, 0, 2, 0);
    m_pVertexDeclaration1->SetEntry(1, 3, 3, 2, 0);
    m_pVertexDeclaration1->SetEntry(2, 5, 4, 3, 0);
    m_pVertexDeclaration1->SetEntry(3, 7, 5, 1, 0);
    m_pVertexDeclaration1->SetEntry2(0, 4, 6, 0x80000000, 0, 5, 1, 0);
    m_pVertexDeclaration1->Finish();
    FUN_00bacd00* pshader = new FUN_00bacd00(m_pVertexDeclaration1);
    pshader->V4c();
    pshader->V13c();
    pshader->V11c();
    pshader->V140();
    pshader->Vc0(m_pVertexDeclaration1);
    return pshader;
}
}  // namespace fnv_00bacf00

struct NiPropertyState_stub
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
    virtual void v67();
    virtual void v68();
    virtual void v69();
    void NiShadeProperty_CopyMembers(FUN_00ba8e50*, unsigned int);
};
struct FUN_00ba8ff0_shell : NiPropertyState_stub
{
    char pad[0x1c];
    int f20;
    int f24;
    float f28;
    float f2c;
    char pad30[0x28];
    int f58;
    float f5c;
    FUN_00ba8e50* CreatePropertyStateCopy(unsigned int uiPass);
};
// @fnv 0x00ba8ff0
FUN_00ba8e50* FUN_00ba8ff0_shell::CreatePropertyStateCopy(unsigned int uiPass)
{
    FUN_00ba8e50* pResult = new FUN_00ba8e50;
    NiShadeProperty_CopyMembers(pResult, uiPass);
    *(int*)((char*)pResult + 0x20) = f20;
    *(int*)((char*)pResult + 0x24) = f24;
    *(float*)((char*)pResult + 0x28) = f28;
    *(float*)((char*)pResult + 0x2c) = f2c;
    *(int*)((char*)pResult + 0x38) = 0;
    *(int*)((char*)pResult + 0x58) = f58;
    *(float*)((char*)pResult + 0x5c) = f5c;
    return pResult;
}

struct S_00ba9380_Bin
{
    unsigned int unk00;
    unsigned int m_uiPos;
    unsigned int unk08;
    unsigned int(__cdecl* m_pfnRead)(S_00ba9380_Bin*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(void* p, unsigned int bytes, unsigned int* sz, unsigned int n)
    {
        return m_pfnRead(this, p, bytes, sz, n);
    }
};
static __forceinline void S_BinRead(S_00ba9380_Bin* bin, void* v, unsigned int bytes)
{
    unsigned int sz = 4;
    bin->m_uiPos += bin->Read(v, bytes, &sz, 1);
}
struct FUN_00ba9380_cls
{
    void SaveToStream(void* pOther);
    void BSShaderProperty_SaveBinary(void* pOther);
};
// Calls SaveToStream, then reads four 4-byte values from the stream at pOther+0x250 into this+0x58, this+0x20, this+0x24 and this+0x30.
// @fnv 0x00ba9380
// src: XBOX_PDB 0x00ba9380
void FUN_00ba9380_cls::BSShaderProperty_SaveBinary(void* pOther)
{
    char* pObj = (char*)pOther;
    SaveToStream(pOther);
    S_BinRead(*(S_00ba9380_Bin**)(pObj + 0x250), (char*)this + 0x58, 4);
    char* p = (char*)this + 0x20;
    for (int i = 0; i < 2; i++)
    {
        S_BinRead(*(S_00ba9380_Bin**)(pObj + 0x250), p, 4);
        p += 4;
    }
    S_BinRead(*(S_00ba9380_Bin**)(pObj + 0x250), (char*)this + 0x30, 4);
}

extern int DAT_010b8480;
extern int DAT_00ffdead;

struct S_00ba9520_Heap
{
    void MemoryManager_Deallocate(void* p);
};
extern S_00ba9520_Heap DAT_011f6238;

struct S_00ba9520_Entry
{
    unsigned short unk00;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
    unsigned short unk08;
    unsigned char unk0a;
    unsigned char unk0b;
    void* unk0c;
};

struct S_00ba9520_Base
{
    int unk00;
    S_00ba9520_Entry** unk04;
    int unk08;
    unsigned short unk0c;
    unsigned short unk0e;
    void* unk10;

    ~S_00ba9520_Base()
    {
        unk00 = (int)&DAT_010b8480;
        DAT_011f6238.MemoryManager_Deallocate(unk04);
    }
};

struct FUN_00ba9520 : S_00ba9520_Base
{
    ~FUN_00ba9520();
};

// Frees each non-null entry and its unk0c buffer, then sets unk10 to DAT_00ffdead before the base destructor runs.
// @fnv 0x00ba9520
FUN_00ba9520::~FUN_00ba9520()
{
    for (unsigned int i = 0; i < unk0c; ++i)
    {
        S_00ba9520_Entry* pEntry = unk04[i];
        if (pEntry != 0)
        {
            pEntry->unk04 = 0;
            if (pEntry->unk0c != 0)
            {
                DAT_011f6238.MemoryManager_Deallocate(pEntry->unk0c);
                pEntry->unk0c = 0;
            }
            pEntry->unk0b = 0;
            DAT_011f6238.MemoryManager_Deallocate(pEntry);
        }
    }
    unk10 = &DAT_00ffdead;
}


void __cdecl FUN_00e804d0(void*);

struct Shader_bad060 : BSShader
{
    NiPointer<NiD3DPass> m_aspPass[0x2c];
    void ConfigureBeamPasses();
    bool TallGrassShader_LoadStagesAndPasses();
};

// @fnv 0x00bad060
// src: COMMUNITY 0x00bad060
bool Shader_bad060::TallGrassShader_LoadStagesAndPasses()
{
    AutoMemContext kContext(0x1c);
    for (int i = 0; i < 0x2c; ++i)
    {
        FUN_00e804d0(&m_aspPass[i]);
    }
    ConfigureBeamPasses();
    return true;
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);
extern "C" char DAT_010a1e50, DAT_010af648, DAT_01011584;
extern "C" char DAT_010b8c54, DAT_010b8c48, DAT_010b8c34, DAT_010b8c24;
extern "C" char DAT_010b8c10, DAT_010b8bfc, DAT_010b8bec;
extern "C" char DAT_011fd884, DAT_011fa280, DAT_011fa290, DAT_01200510;
struct ShaderVariableMap : RefObj_bacd00
{
    ShaderVariableMap(void* context, int mode);
    static void* operator new(unsigned int)
    {
        return Object_DispatchCommandFour(0x44);
    }
    virtual void Register(const void* name, unsigned int type, int a, int b, int c, const void* desc, int stride,
                          int count, const void* data, int optional);
    typedef int(__thiscall* LookupFn)(ShaderVariableMap*, const void*);
    int Lookup(const void* name)
    {
        return reinterpret_cast<LookupFn>((*reinterpret_cast<void***>(this))[28])(this, name);
    }
};
struct ShaderRegister
{
    void InitializeShaderVariableMaps();
};
// Creates the main and extra ShaderVariableMap groups if missing, registers their variables, and caches the lookup result of the count-based variable.
// @fnv 0x00bad100
void ShaderRegister::InitializeShaderVariableMaps()
{
    AutoMemContext allocScope(28);
    RefPtr_bacd00& mainGroup = *reinterpret_cast<RefPtr_bacd00*>(reinterpret_cast<char*>(this) + 0x34);
    RefPtr_bacd00& extraGroup = *reinterpret_cast<RefPtr_bacd00*>(reinterpret_cast<char*>(this) + 0x30);
    if (!mainGroup.m_pObject)
    {
        mainGroup = new ShaderVariableMap(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x18), 0);
        static_cast<ShaderVariableMap*>(mainGroup.m_pObject)
            ->Register(&DAT_010a1e50, 0x20000009, 0, 9, 4, 0, 0, 0, 0, 0);
        static_cast<ShaderVariableMap*>(mainGroup.m_pObject)
            ->Register(&DAT_010af648, 0x10000007, 0, 13, 1, &DAT_01011584, 0x10, 4, &DAT_011fd884, 0);
        static_cast<ShaderVariableMap*>(mainGroup.m_pObject)
            ->Register(&DAT_010b8c54, 0x10000007, 0, 15, 1, &DAT_01011584, 0x10, 4, &DAT_011fa280, 0);
        static_cast<ShaderVariableMap*>(mainGroup.m_pObject)
            ->Register(&DAT_010b8c48, 0x10000007, 0, 14, 1, &DAT_01011584, 0x10, 4, &DAT_011fa290, 0);
        static_cast<ShaderVariableMap*>(mainGroup.m_pObject)
            ->Register(&DAT_010b8c34, 0x10000009, 0, 0, 9, &DAT_01011584, 0x90, 4, &DAT_01200510, 0);
        unsigned int count = *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x1ac);
        static_cast<ShaderVariableMap*>(mainGroup.m_pObject)
            ->Register(&DAT_010b8c24, 0x10000009, 0, 20, count, &DAT_01011584, count << 4, 4,
                       *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x1a4), 0);
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x1a8) =
            static_cast<ShaderVariableMap*>(mainGroup.m_pObject)->Lookup(&DAT_010b8c24);
    }
    if (!extraGroup.m_pObject)
    {
        extraGroup = new ShaderVariableMap(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x18), 2);
        static_cast<ShaderVariableMap*>(extraGroup.m_pObject)
            ->Register(&DAT_010b8c10, 0x10000007, 0, 2, 1, &DAT_01011584, 0x10, 4,
                       reinterpret_cast<char*>(this) + 0x1b0, 0);
        static_cast<ShaderVariableMap*>(extraGroup.m_pObject)
            ->Register(&DAT_010b8bfc, 0x10000007, 0, 4, 1, &DAT_01011584, 0x10, 4,
                       reinterpret_cast<char*>(this) + 0x1c0, 0);
        static_cast<ShaderVariableMap*>(extraGroup.m_pObject)
            ->Register(&DAT_010b8bec, 0x10000007, 0, 3, 1, &DAT_01011584, 0x10, 4,
                       reinterpret_cast<char*>(this) + 0x1d0, 0);
    }
}

struct FUN_00bad400_Elem
{
    // Virtual destructor for FUN_00bad400_Elem; empty body, so it only participates in the vtable.
// @fnv 0x00bad400
    virtual ~FUN_00bad400_Elem()
    {}
};
struct FUN_00ba3aa0_Arr
{
    int unk00;
    void SetAt(unsigned int index, FUN_00bad400_Elem* const& value);
};
struct FUN_00ba3d30_Base
{
    virtual ~FUN_00ba3d30_Base();
};
struct FUN_00bad400 : FUN_00ba3d30_Base
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00ba3aa0_Arr m18;
    FUN_00bad400_Elem** m1c;
    virtual ~FUN_00bad400();
};
FUN_00bad400::~FUN_00bad400()
{
    for (unsigned int i = 0; i < 13; ++i)
    {
        if (m1c[i])
        {
            delete m1c[i];
            FUN_00bad400_Elem* none = 0;
            m18.SetAt(i, none);
        }
    }
}

struct Matrix215
{
    float elements[4][4];
};
struct Source215
{
    unsigned unknown00, unknown04, unknown08, unknown0c, unknown10, unknown14, unknown18, unknown1c;
    unsigned unknown20, unknown24, unknown28, unknown2c, unknown30, unknown34, unknown38, unknown3c;
    unsigned unknown40, unknown44, unknown48, unknown4c, unknown50, unknown54, unknown58, unknown5c;
    unsigned unknown60, unknown64;
    float x;
    unsigned unknown6c, unknown70;
    float y;
    unsigned unknown78, unknown7c;
    float z;
};
extern bool DAT_0120045c, DAT_0120045d, DAT_0120045e, DAT_011adcdc;
extern NiDX9Renderer* DAT_011f9508;
extern Matrix215 DAT_01200470, DAT_012004b0;
extern NiPoint3 DAT_012004f0;
// If neither flag is set, copies the renderer's two matrices and the source's x/y/z point into globals and sets DAT_0120045e true and DAT_011adcdc false.
// @fnv 0x00ba9420
// src: COMMUNITY 0x00ba9420
void BSShaderProperty_PreviousTransform_SaveCamera(const Source215* source)
{
    if (!DAT_0120045c && !DAT_0120045d)
    {
        DAT_01200470 = *reinterpret_cast<const Matrix215*>(DAT_011f9508->kD3DView);
        DAT_012004b0 = *reinterpret_cast<const Matrix215*>(DAT_011f9508->kD3DProj);
        DAT_0120045e = true;
        DAT_011adcdc = false;
        NiPoint3 point(source->x, source->y, source->z);
        DAT_012004f0 = point;
    }
}

struct S_00ba92c0_Bin
{
    unsigned int unk00;
    unsigned int m_uiPos;
    unsigned int(__cdecl* m_pfnRead)(S_00ba92c0_Bin*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSize, unsigned int uiComponents)
    {
        return m_pfnRead(this, pvBuffer, uiBytes, puiComponentSize, uiComponents);
    }
};

static __forceinline void S_00ba92c0_BinRead(S_00ba92c0_Bin* pkBin, void* pvBuffer, unsigned int uiBytes)
{
    unsigned int uiComponentSize = 4;
    pkBin->m_uiPos += pkBin->Read(pvBuffer, uiBytes, &uiComponentSize, 1);
}

struct S_00ba92c0_Stream;

struct S_00ba92c0_Base
{
    void NiDitherProperty_LoadBinary(S_00ba92c0_Stream& kStream);
};

struct S_00ba92c0_Stream
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
    S_00ba92c0_Bin* m_pkBin;
};

struct S_00ba92c0_Prop : S_00ba92c0_Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    union
    {
        struct
        {
            unsigned int m_uiUnk20;
            unsigned int m_uiValue1;
        };
        unsigned int m_auiFlags[2];
    };
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
    __forceinline void SetFlag(unsigned int& uiFlags, unsigned int uiMask)
    {
        if (!(uiFlags & uiMask))
            unk38 = 0;
        uiFlags |= uiMask;
    }
    void BSShaderProperty_LoadBinary(S_00ba92c0_Stream& kStream);
};

// Reads unk58, the two flag words, sets flag 0x8000 when bit 0x2000 is set, then reads unk30 from the stream's bin.
// @fnv 0x00ba92c0
// src: XBOX_PDB 0x00ba92c0
void S_00ba92c0_Prop::BSShaderProperty_LoadBinary(S_00ba92c0_Stream& kStream)
{
    NiDitherProperty_LoadBinary(kStream);
    S_00ba92c0_BinRead(kStream.m_pkBin, &unk58, 4);
    for (int i = 0; i < 2; ++i)
        S_00ba92c0_BinRead(kStream.m_pkBin, &m_auiFlags[i], 4);
    if ((m_uiValue1 & 0x2000) > 0)
        SetFlag(m_uiValue1, 0x8000);
    S_00ba92c0_BinRead(kStream.m_pkBin, &unk30, 4);
}

extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
struct GrassThreadMemory
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
    int context;
};
extern "C" volatile unsigned int DAT_0126fd98;
extern "C" unsigned long __readfsdword(unsigned long);
struct GrassMemoryScope
{
    GrassThreadMemory* thread;
    int previous;
    GrassMemoryScope()
    {
        unsigned int index = DAT_0126fd98;
        thread = ((GrassThreadMemory**)__readfsdword(0x2c))[index];
        previous = thread->context;
        thread->context = 28;
    }
    ~GrassMemoryScope()
    {
        thread->context = previous;
    }
};
struct GrassMacro
{
    const char* name;
    const char* value;
};
inline GrassMacro* GrassMacroEnd(GrassMacro* macro)
{
    if (macro->name)
    {
        GrassMacro* next = macro + 1;
        do
        {
            macro = next++;
        } while (macro->name);
    }
    return macro;
}
struct GrassShaderDescriptor
{
    const char* source;
    const char* macros[18];
};
struct GrassShader
{
    virtual void Unused();
    virtual void DeleteThis();
    long references;
    void AddRef()
    {
        InterlockedIncrement(&references);
    }
    void Release()
    {
        if (!InterlockedDecrement(&references))
            DeleteThis();
    }
};
struct GrassShaderRef
{
    GrassShader* object;
    GrassShaderRef& operator=(GrassShader* shader)
    {
        if (object != shader)
        {
            if (object)
                object->Release();
            object = shader;
            if (object)
                object->AddRef();
        }
        return *this;
    }
};
extern int DAT_011f91c0;
extern bool DAT_011f948b, DAT_011f94a4, DAT_011f948a, DAT_011f9421;
const char* __cdecl FUN_00b4f380(int);
int __cdecl FUN_004dc060(int);
void __cdecl FUN_00be0c00(const char*, char*);
int __cdecl BSsprintf(char*, unsigned int, const char*, ...);
struct TallGrassPrograms
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
    GrassShaderRef vertexPrograms[24];
    GrassShaderRef pixelPrograms[7];
    GrassShader* FUN_00be0fe0(const char*, GrassMacro*, const char*, const char*);
    GrassShader* FUN_00be1750(const char*, GrassMacro*, const char*, const char*);
    void TallGrassShader_LoadShaders();
};
inline GrassMacro* FindGrassMacroEnd(GrassShaderDescriptor* desc)
{
    GrassMacro* macro = (GrassMacro*)desc->macros;
    if (macro->name)
    {
        GrassMacro* next = (GrassMacro*)(desc->macros + 2);
        do
        {
            macro = next++;
        } while (macro->name);
    }
    return macro;
}
// Builds vertex and pixel shader entries from descriptors, choosing profiles and binary names using global flags.
// @fnv 0x00baafc0
// src: COMMUNITY 0x00baafc0
void TallGrassPrograms::TallGrassShader_LoadShaders()
{
    GrassMemoryScope grassMemoryScope;
    GrassShaderDescriptor vertex[24];
    vertex[0].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[0].macros[0] = "VS_2_0";
    vertex[0].macros[1] = 0;
    vertex[0].macros[2] = 0;
    fnv_zlib_memset(&vertex[0].macros[3], 0, 60);
    vertex[1].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[1].macros[0] = "VS_2_0";
    vertex[1].macros[1] = 0;
    vertex[1].macros[2] = "VERTLIT";
    vertex[1].macros[3] = "";
    vertex[1].macros[4] = 0;
    fnv_zlib_memset(&vertex[1].macros[5], 0, 52);
    vertex[2].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[2].macros[0] = "VS_2_0";
    vertex[2].macros[1] = 0;
    vertex[2].macros[2] = "FIT_TO_SLOPE";
    vertex[2].macros[3] = "";
    vertex[2].macros[4] = 0;
    fnv_zlib_memset(&vertex[2].macros[5], 0, 52);
    vertex[3].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[3].macros[0] = "VS_2_0";
    vertex[3].macros[1] = 0;
    vertex[3].macros[2] = "VERTLIT";
    vertex[3].macros[3] = "";
    vertex[3].macros[4] = "FIT_TO_SLOPE";
    vertex[3].macros[5] = "";
    vertex[3].macros[6] = 0;
    fnv_zlib_memset(&vertex[3].macros[7], 0, 44);
    vertex[4].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[4].macros[0] = "VS_2_0";
    vertex[4].macros[1] = 0;
    vertex[4].macros[2] = "PTLIGHT";
    vertex[4].macros[3] = "";
    vertex[4].macros[4] = 0;
    fnv_zlib_memset(&vertex[4].macros[5], 0, 52);
    vertex[5].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[5].macros[0] = "VS_2_0";
    vertex[5].macros[1] = 0;
    vertex[5].macros[2] = "PTLIGHT";
    vertex[5].macros[3] = "";
    vertex[5].macros[4] = "VERTLIT";
    vertex[5].macros[5] = "";
    vertex[5].macros[6] = 0;
    fnv_zlib_memset(&vertex[5].macros[7], 0, 44);
    vertex[6].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[6].macros[0] = "VS_2_0";
    vertex[6].macros[1] = 0;
    vertex[6].macros[2] = "PTLIGHT";
    vertex[6].macros[3] = "";
    vertex[6].macros[4] = "FIT_TO_SLOPE";
    vertex[6].macros[5] = "";
    vertex[6].macros[6] = 0;
    fnv_zlib_memset(&vertex[6].macros[7], 0, 44);
    vertex[7].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[7].macros[0] = "VS_2_0";
    vertex[7].macros[1] = 0;
    vertex[7].macros[2] = "PTLIGHT";
    vertex[7].macros[3] = "";
    vertex[7].macros[4] = "VERTLIT";
    vertex[7].macros[5] = "";
    vertex[7].macros[6] = "FIT_TO_SLOPE";
    vertex[7].macros[7] = "";
    vertex[7].macros[8] = 0;
    vertex[7].macros[9] = 0;
    vertex[7].macros[10] = 0;
    vertex[7].macros[11] = 0;
    vertex[7].macros[12] = 0;
    vertex[7].macros[13] = 0;
    vertex[7].macros[14] = 0;
    vertex[7].macros[15] = 0;
    vertex[7].macros[16] = 0;
    vertex[7].macros[17] = 0;
    vertex[8].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[8].macros[0] = "VS_2_0";
    vertex[8].macros[1] = 0;
    vertex[8].macros[2] = "PROJ_SHADOW";
    vertex[8].macros[3] = "";
    vertex[8].macros[4] = 0;
    fnv_zlib_memset(&vertex[8].macros[5], 0, 52);
    vertex[9].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[9].macros[0] = "VS_2_0";
    vertex[9].macros[1] = 0;
    vertex[9].macros[2] = "VERTLIT";
    vertex[9].macros[3] = "";
    vertex[9].macros[4] = "PROJ_SHADOW";
    vertex[9].macros[5] = "";
    vertex[9].macros[6] = 0;
    fnv_zlib_memset(&vertex[9].macros[7], 0, 44);
    vertex[10].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[10].macros[0] = "VS_2_0";
    vertex[10].macros[1] = 0;
    vertex[10].macros[2] = "FIT_TO_SLOPE";
    vertex[10].macros[3] = "";
    vertex[10].macros[4] = "PROJ_SHADOW";
    vertex[10].macros[5] = "";
    vertex[10].macros[6] = 0;
    fnv_zlib_memset(&vertex[10].macros[7], 0, 44);
    vertex[11].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[11].macros[0] = "VS_2_0";
    vertex[11].macros[1] = 0;
    vertex[11].macros[2] = "VERTLIT";
    vertex[11].macros[3] = "";
    vertex[11].macros[4] = "FIT_TO_SLOPE";
    vertex[11].macros[5] = "";
    vertex[11].macros[6] = "PROJ_SHADOW";
    vertex[11].macros[7] = "";
    vertex[11].macros[8] = 0;
    vertex[11].macros[9] = 0;
    vertex[11].macros[10] = 0;
    vertex[11].macros[11] = 0;
    vertex[11].macros[12] = 0;
    vertex[11].macros[13] = 0;
    vertex[11].macros[14] = 0;
    vertex[11].macros[15] = 0;
    vertex[11].macros[16] = 0;
    vertex[11].macros[17] = 0;
    vertex[12].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[12].macros[0] = "VS_2_0";
    vertex[12].macros[1] = 0;
    vertex[12].macros[2] = "PTLIGHT";
    vertex[12].macros[3] = "";
    vertex[12].macros[4] = "PROJ_SHADOW";
    vertex[12].macros[5] = "";
    vertex[12].macros[6] = 0;
    fnv_zlib_memset(&vertex[12].macros[7], 0, 44);
    vertex[13].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[13].macros[0] = "VS_2_0";
    vertex[13].macros[1] = 0;
    vertex[13].macros[2] = "PTLIGHT";
    vertex[13].macros[3] = "";
    vertex[13].macros[4] = "VERTLIT";
    vertex[13].macros[5] = "";
    vertex[13].macros[6] = "PROJ_SHADOW";
    vertex[13].macros[7] = "";
    vertex[13].macros[8] = 0;
    vertex[13].macros[9] = 0;
    vertex[13].macros[10] = 0;
    vertex[13].macros[11] = 0;
    vertex[13].macros[12] = 0;
    vertex[13].macros[13] = 0;
    vertex[13].macros[14] = 0;
    vertex[13].macros[15] = 0;
    vertex[13].macros[16] = 0;
    vertex[13].macros[17] = 0;
    vertex[14].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[14].macros[0] = "VS_2_0";
    vertex[14].macros[1] = 0;
    vertex[14].macros[2] = "PTLIGHT";
    vertex[14].macros[3] = "";
    vertex[14].macros[4] = "FIT_TO_SLOPE";
    vertex[14].macros[5] = "";
    vertex[14].macros[6] = "PROJ_SHADOW";
    vertex[14].macros[7] = "";
    vertex[14].macros[8] = 0;
    vertex[14].macros[9] = 0;
    vertex[14].macros[10] = 0;
    vertex[14].macros[11] = 0;
    vertex[14].macros[12] = 0;
    vertex[14].macros[13] = 0;
    vertex[14].macros[14] = 0;
    vertex[14].macros[15] = 0;
    vertex[14].macros[16] = 0;
    vertex[14].macros[17] = 0;
    vertex[15].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[15].macros[0] = "VS_2_0";
    vertex[15].macros[1] = 0;
    vertex[15].macros[2] = "PTLIGHT";
    vertex[15].macros[3] = "";
    vertex[15].macros[4] = "VERTLIT";
    vertex[15].macros[5] = "";
    vertex[15].macros[6] = "FIT_TO_SLOPE";
    vertex[15].macros[7] = "";
    vertex[15].macros[8] = "PROJ_SHADOW";
    vertex[15].macros[9] = "";
    vertex[15].macros[10] = 0;
    vertex[15].macros[11] = 0;
    vertex[15].macros[12] = 0;
    vertex[15].macros[13] = 0;
    vertex[15].macros[14] = 0;
    vertex[15].macros[15] = 0;
    vertex[15].macros[16] = 0;
    vertex[15].macros[17] = 0;
    vertex[16].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[16].macros[0] = "VS_2_0";
    vertex[16].macros[1] = 0;
    vertex[16].macros[2] = "BILLBOARD";
    vertex[16].macros[3] = "";
    vertex[16].macros[4] = 0;
    fnv_zlib_memset(&vertex[16].macros[5], 0, 52);
    vertex[17].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[17].macros[0] = "VS_2_0";
    vertex[17].macros[1] = 0;
    vertex[17].macros[2] = "BILLBOARD";
    vertex[17].macros[3] = "";
    vertex[17].macros[4] = "FIT_TO_SLOPE";
    vertex[17].macros[5] = "";
    vertex[17].macros[6] = 0;
    fnv_zlib_memset(&vertex[17].macros[7], 0, 44);
    vertex[18].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[18].macros[0] = "VS_2_0";
    vertex[18].macros[1] = 0;
    vertex[18].macros[2] = "BILLBOARD";
    vertex[18].macros[3] = "";
    vertex[18].macros[4] = "PTLIGHT";
    vertex[18].macros[5] = "";
    vertex[18].macros[6] = 0;
    fnv_zlib_memset(&vertex[18].macros[7], 0, 44);
    vertex[19].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[19].macros[0] = "VS_2_0";
    vertex[19].macros[1] = 0;
    vertex[19].macros[2] = "BILLBOARD";
    vertex[19].macros[3] = "";
    vertex[19].macros[4] = "PTLIGHT";
    vertex[19].macros[5] = "";
    vertex[19].macros[6] = "FIT_TO_SLOPE";
    vertex[19].macros[7] = "";
    vertex[19].macros[8] = 0;
    vertex[19].macros[9] = 0;
    vertex[19].macros[10] = 0;
    vertex[19].macros[11] = 0;
    vertex[19].macros[12] = 0;
    vertex[19].macros[13] = 0;
    vertex[19].macros[14] = 0;
    vertex[19].macros[15] = 0;
    vertex[19].macros[16] = 0;
    vertex[19].macros[17] = 0;
    vertex[20].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[20].macros[0] = "VS_2_0";
    vertex[20].macros[1] = 0;
    vertex[20].macros[2] = "SHADOWMAP";
    vertex[20].macros[3] = "";
    vertex[20].macros[4] = 0;
    fnv_zlib_memset(&vertex[20].macros[5], 0, 52);
    vertex[21].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[21].macros[0] = "VS_2_0";
    vertex[21].macros[1] = 0;
    vertex[21].macros[2] = "SHADOWMAP";
    vertex[21].macros[3] = "";
    vertex[21].macros[4] = "FIT_TO_SLOPE";
    vertex[21].macros[5] = "";
    vertex[21].macros[6] = 0;
    fnv_zlib_memset(&vertex[21].macros[7], 0, 44);
    vertex[22].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[22].macros[0] = "VS_2_0";
    vertex[22].macros[1] = 0;
    vertex[22].macros[2] = "SHADOWMAP";
    vertex[22].macros[3] = "";
    vertex[22].macros[4] = "BILLBOARD";
    vertex[22].macros[5] = "";
    vertex[22].macros[6] = 0;
    fnv_zlib_memset(&vertex[22].macros[7], 0, 44);
    vertex[23].source = "tallgrass\\1x\\v\\lowDetail.v.hlsl";
    vertex[23].macros[0] = "VS_2_0";
    vertex[23].macros[1] = 0;
    vertex[23].macros[2] = "SHADOWMAP";
    vertex[23].macros[3] = "";
    vertex[23].macros[4] = "BILLBOARD";
    vertex[23].macros[5] = "";
    vertex[23].macros[6] = "FIT_TO_SLOPE";
    vertex[23].macros[7] = "";
    vertex[23].macros[8] = 0;
    vertex[23].macros[9] = 0;
    vertex[23].macros[10] = 0;
    vertex[23].macros[11] = 0;
    vertex[23].macros[12] = 0;
    vertex[23].macros[13] = 0;
    vertex[23].macros[14] = 0;
    vertex[23].macros[15] = 0;
    vertex[23].macros[16] = 0;
    vertex[23].macros[17] = 0;
    GrassShaderDescriptor pixel[7] = {

        {"tallgrass\\1x\\p\\highDetail.p.hlsl", {"PS_2_0", 0, 0}},

        {"tallgrass\\1x\\p\\highDetail_1pt.p.hlsl", {"PS_2_0", 0, 0}},

        {"tallgrass\\1x\\p\\highDetail.p.hlsl", {"PS_2_0", 0, "PROJ_SHADOW", "", 0}},

        {"tallgrass\\1x\\p\\highDetail_1pt.p.hlsl", {"PS_2_0", 0, "PROJ_SHADOW", "", 0}},

        {"tallgrass\\1x\\p\\highDetail.p.hlsl",
         {"PS_2_0", 0, "SHADOWMAP", "", "DEPTHBIAS", "-0.7", "SAMPLE", "1", "PASSES", "1", 0}},

        {"tallgrass\\1x\\p\\highDetail.p.hlsl",
         {"PS_2_0", 0, "SHADOWMAP", "", "DEPTHBIAS", "-0.7", "SAMPLE", "4", "PASSES", "1", 0}},

        {"tallgrass\\1x\\p\\highDetail.p.hlsl",
         {"PS_2_0", 0, "SHADOWMAP", "", "DEPTHBIAS", "-0.7", "SAMPLE", "4", "PASSES", "2", 0}},

    };
    const char* shaderProfile = FUN_00b4f380(1);
    char binaryShaderName[260];
    char sourcePath[260];
    if (DAT_011f91c0 != 1)
    {
        if (DAT_011f948b && DAT_011f94a4)
        {
            for (int shaderVariant = 0; shaderVariant < 2; shaderVariant++)
            {
                DAT_011f948a = !DAT_011f948a;
                for (int index = 0; index < 24; index++)
                {
                    FUN_00be0c00(vertex[index].source, sourcePath);
                    BSsprintf(binaryShaderName, 260, "GRASS2%03i.vso", index);
                    const char* vertexShaderProfile = "vs_2_0";
                    if (DAT_011f94a4 && DAT_011f948a)
                    {
                        BSsprintf(binaryShaderName, 260, "GRASS23x%03i.vso", index);
                        vertexShaderProfile = "vs_3_0";
                    }
                    vertexPrograms[index] = FUN_00be0fe0(sourcePath, (GrassMacro*)vertex[index].macros,
                                                         vertexShaderProfile, binaryShaderName);
                }
            }
        }
        else
        {
            for (int index = 0; index < 24; index++)
            {
                FUN_00be0c00(vertex[index].source, sourcePath);
                BSsprintf(binaryShaderName, 260, "GRASS2%03i.vso", index);
                const char* vertexShaderProfile = "vs_2_0";
                if (DAT_011f94a4 && DAT_011f948a)
                {
                    BSsprintf(binaryShaderName, 260, "GRASS23x%03i.vso", index);
                    vertexShaderProfile = "vs_3_0";
                }
                vertexPrograms[index] =
                    FUN_00be0fe0(sourcePath, (GrassMacro*)vertex[index].macros, vertexShaderProfile, binaryShaderName);
            }
        }
        for (int index = 0, pixelOffset = 0; pixelOffset < (int)sizeof(pixel);
             index++, pixelOffset += sizeof(GrassShaderDescriptor))
        {
            if (index >= 4 && FUN_004dc060(0) < 5)
                continue;
            if (DAT_011f948b)
            {
                DAT_011f9421 = true;
                for (int shaderVariant = 0; shaderVariant < 4; shaderVariant++)
                {
                    if (shaderVariant % 2 == 0)
                        DAT_011f9421 = !DAT_011f9421;
                    DAT_011f948a = !DAT_011f948a;
                    if (DAT_011f9421)
                    {
                        GrassMacro* macro = FindGrassMacroEnd(
                            reinterpret_cast<GrassShaderDescriptor*>(reinterpret_cast<char*>(pixel) + pixelOffset));
                        macro->name = "TRANSPARENCYMS";
                        macro->value = "";
                        BSsprintf(binaryShaderName, 260, "GRASS2%03iTMS.pso", index);
                    }
                    else
                        BSsprintf(binaryShaderName, 260, "GRASS2%03i.pso", index);
                    FUN_00be0c00(
                        reinterpret_cast<GrassShaderDescriptor*>(reinterpret_cast<char*>(pixel) + pixelOffset)->source,
                        sourcePath);
                    if (DAT_011f94a4 && DAT_011f948a)
                    {
                        if (DAT_011f9421)
                            BSsprintf(binaryShaderName, 260, "GRASS23x%03iTMS.pso", index);
                        else
                            BSsprintf(binaryShaderName, 260, "GRASS23x%03i.pso", index);
                        shaderProfile = "ps_3_0";
                    }
                    else
                        shaderProfile = FUN_00b4f380(1);
                    pixelPrograms[index] = FUN_00be1750(sourcePath,
                                                        (GrassMacro*)reinterpret_cast<GrassShaderDescriptor*>(
                                                            reinterpret_cast<char*>(pixel) + pixelOffset)
                                                            ->macros,
                                                        shaderProfile, binaryShaderName);
                }
            }
            else
            {
                if (DAT_011f9421)
                {
                    GrassMacro* macro = GrassMacroEnd((GrassMacro*)reinterpret_cast<GrassShaderDescriptor*>(
                                                          reinterpret_cast<char*>(pixel) + pixelOffset)
                                                          ->macros);
                    macro->name = "TRANSPARENCYMS";
                    macro->value = "";
                    if (DAT_011f94a4 && DAT_011f948a)
                        BSsprintf(binaryShaderName, 260, "GRASS23x%03iTMS.pso", index);
                    else
                        BSsprintf(binaryShaderName, 260, "GRASS2%03iTMS.pso", index);
                }
                else
                {
                    if (DAT_011f94a4 && DAT_011f948a)
                        BSsprintf(binaryShaderName, 260, "GRASS23x%03i.pso", index);
                    else
                        BSsprintf(binaryShaderName, 260, "GRASS2%03i.pso", index);
                }
                if (DAT_011f94a4 && DAT_011f948a)
                    shaderProfile = "ps_3_0";
                FUN_00be0c00(
                    reinterpret_cast<GrassShaderDescriptor*>(reinterpret_cast<char*>(pixel) + pixelOffset)->source,
                    sourcePath);
                pixelPrograms[index] = FUN_00be1750(
                    sourcePath,
                    (GrassMacro*)reinterpret_cast<GrassShaderDescriptor*>(reinterpret_cast<char*>(pixel) + pixelOffset)
                        ->macros,
                    shaderProfile, binaryShaderName);
            }
        }
    }
}

extern int DAT_010b8480;

namespace ba94b0 {

struct CtorBase
{
    int f00;
    int f04;
    int f08;
    int f0c;
    CtorBase(unsigned int n, int k);
    ~CtorBase();
};

class MidLevel : public CtorBase
{
  public:
    __forceinline MidLevel(unsigned int n) : CtorBase(n, 3)
    {
        f00 = (int)&DAT_010b8480;
    }
};

class FUN_00ba94b0 : public MidLevel
{
  public:
    int unk10;
    void FUN_00ba8d30(unsigned int n);
    FUN_00ba94b0(unsigned int n);
};

// Constructs a FUN_00ba94b0 object by calling the MidLevel base constructor, zeroing unk10, and invoking FUN_00ba8d30.
// @fnv 0x00ba94b0
FUN_00ba94b0::FUN_00ba94b0(unsigned int n) : MidLevel(n)
{
    unk10 = 0;
    FUN_00ba8d30(n);
}

}

struct State_c160
{
    void SetNodeValue(unsigned int, unsigned int, bool);
};
State_c160* FUN_00e7f5d0();
int FUN_004dc060(int);
extern bool DAT_011f941e, DAT_011f9421;
extern unsigned int DAT_011f9534, DAT_011f948c;
extern float DAT_01200458;
struct Stage_c160
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
    void NiD3DTextureStage_ReturnStageToPool();
    void DecRefCount()
    {
        --unk60;
        if (unk60 == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};
void AssignStageFromPool(Stage_c160**);
void ConfigureBeamStage(Stage_c160*, int, int, int, int);
struct StagePtr_c160
{
    Stage_c160* object;
    StagePtr_c160() : object(0)
    {}
    ~StagePtr_c160()
    {
        if (object)
            object->DecRefCount();
    }
};
struct Pass_c160
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
    State_c160* state;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    RefPtr_bacd00 pixel;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    RefPtr_bacd00 vertex;
    void NiD3DPass_SetStage(unsigned int, Stage_c160*);
    void Set(unsigned int key, unsigned int value)
    {
        if (!state)
            state = FUN_00e7f5d0();
        state->SetNodeValue(key, value, true);
    }
};
struct Shader_c160 : BSShader
{
    Pass_c160* passes[44];
    float value11c;
    unsigned int unk120;
    unsigned int unk124;
    RefObj_bacd00* vertex[24];
    RefObj_bacd00* pixel[7];
    void ConfigureBeamPasses();
};
// Configures up to 44 beam passes by assigning stages from a pool, setting node values, and linking vertex and pixel shader objects.
// @fnv 0x00bac160
void Shader_c160::ConfigureBeamPasses()
{
    AutoMemContext scope(28);
    StagePtr_c160 stage;
    int i;
    for (i = 0; i <= 19; ++i)
    {
        Pass_c160* pass = passes[i];
        if (pass->unk18 < 1)
        {
            {
                AssignStageFromPool(&stage.object);
                Stage_c160* current = stage.object;
                ConfigureBeamStage(current, 0, 3, 2, 0);
                pass->NiD3DPass_SetStage(pass->unk14, current);
            }
        }
        int pixelIndex;
        if (i >= 8)
        {
            if (i <= 15)
            {
                if (pass->unk18 < 3)
                {
                    {
                        AssignStageFromPool(&stage.object);
                        Stage_c160* current = stage.object;
                        ConfigureBeamStage(current, 1, 1, 2, 0);
                        pass->NiD3DPass_SetStage(pass->unk14, current);
                    }
                    {
                        AssignStageFromPool(&stage.object);
                        Stage_c160* current = stage.object;
                        ConfigureBeamStage(current, 2, 1, 2, 0);
                        pass->NiD3DPass_SetStage(pass->unk14, current);
                    }
                }
                pixelIndex = 2;
            }
            else
                pixelIndex = 0;
        }
        else
            pixelIndex = 0;
        pass->Set(27, 0);
        if (FUN_004dc060(0) >= 2)
        {
            pass->Set(15, 1);
            pass->Set(25, 5);
            pass->Set(24, 10);
            if (DAT_011f941e && !DAT_011f9421)
            {
                pass->Set(27, 1);
                pass->Set(19, 5);
                pass->Set(20, 6);
            }
        }
        pass->vertex = vertex[i];
        pass->pixel = pixel[pixelIndex];
    }
    for (i = 20; i <= 39; ++i)
    {
        Pass_c160* pass = passes[i];
        if (pass->unk18 < 2)
        {
            {
                AssignStageFromPool(&stage.object);
                Stage_c160* current = stage.object;
                ConfigureBeamStage(current, 0, 3, 2, 0);
                pass->NiD3DPass_SetStage(pass->unk14, current);
            }
            {
                AssignStageFromPool(&stage.object);
                Stage_c160* current = stage.object;
                ConfigureBeamStage(current, 1, 3, 2, 0);
                current->unk08 = DAT_011f9534;
                current->unk0c = 1;
                pass->NiD3DPass_SetStage(pass->unk14, current);
            }
        }
        int pixelIndex;
        if (i >= 28)
        {
            if (i <= 35)
            {
                if (pass->unk18 < 4)
                {
                    {
                        AssignStageFromPool(&stage.object);
                        Stage_c160* current = stage.object;
                        ConfigureBeamStage(current, 2, 1, 2, 0);
                        pass->NiD3DPass_SetStage(pass->unk14, current);
                    }
                    {
                        AssignStageFromPool(&stage.object);
                        Stage_c160* current = stage.object;
                        ConfigureBeamStage(current, 3, 1, 2, 0);
                        pass->NiD3DPass_SetStage(pass->unk14, current);
                    }
                }
                pixelIndex = 3;
            }
            else
                pixelIndex = 1;
        }
        else
            pixelIndex = 1;
        if (FUN_004dc060(0) >= 2)
        {
            pass->Set(15, 1);
            pass->Set(25, 5);
            pass->Set(24, 10);
            if (DAT_011f941e && !DAT_011f9421)
            {
                pass->Set(27, 1);
                pass->Set(19, 5);
                pass->Set(20, 6);
            }
        }
        else
            pass->Set(15, 0);
        pass->vertex = vertex[i - 20];
        pass->pixel = pixel[pixelIndex];
    }
    for (int j = 0; j < 4; ++j)
    {
        Pass_c160* pass = passes[j + 40];
        if (pass->unk18 < 2)
        {
            {
                AssignStageFromPool(&stage.object);
                Stage_c160* current = stage.object;
                ConfigureBeamStage(current, 0, 3, 2, 0);
                pass->NiD3DPass_SetStage(pass->unk14, current);
            }
            {
                AssignStageFromPool(&stage.object);
                Stage_c160* current = stage.object;
                ConfigureBeamStage(current, 1, 3, 2, 0);
                pass->NiD3DPass_SetStage(pass->unk14, current);
            }
        }
        pass->Set(27, 1);
        pass->Set(19, 9);
        pass->Set(20, 1);
        pass->Set(14, 0);
        float value = DAT_01200458;
        pass->Set(195, *reinterpret_cast<unsigned int*>(&value));
        pass->Set(152, 63);
        pass->vertex = vertex[j + 20];
        pass->pixel = pixel[DAT_011f948c + 4];
    }
}

#include <math.h>
struct GeomSub
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
    NiBound* m_pkWorldBound;
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
    int m_kWorldSpaceTransform;
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
    GeomSub* unkB8;
    int unkBC;
};

struct Param1Sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short word18;
    unsigned char byte1A;
};

struct Param2Sub7C
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
    float f34;
};

struct Param2
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
    unsigned int unk24;
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
    Param2Sub7C* unk7C;
};

struct Param1
{
    Param1Sub* unk00;
    int unk04;
    int unk08;
    Param2* unk0C;
};

struct VTable60
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
    virtual void vfunc24(GeomStub* geom, int unkBC, int zero1, int unk34, Param1* p1, int zero2, void* world,
                         NiBound* bound);
};

struct PassHandler
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
    virtual void vfunc30(int unk, GeomStub* geom, int unkBC, int zero1, int unk34, Param1* p1, int zero2, void* world,
                         NiBound* bound, int zero3, int one);
};

struct BloodSplatterShader
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
};

extern GeomStub** DAT_011f91e0;
extern NiBound DAT_011f4288;
extern unsigned char DAT_011f91a7;
extern float DAT_011f9ee0, DAT_011f9ee4, DAT_011f9ee8, DAT_011f9eec;
extern float DAT_011f940c;
extern float DAT_011f9188;
extern unsigned char DAT_011f9427;
extern char DAT_011f91d8;
extern float DAT_011fd890;
extern float DAT_011fd874, DAT_011fd878, DAT_011adce0, DAT_011fd880;

extern "C"
{
    extern V4_bacd00 DAT_011fa0c0;
    extern G4_bacd00 DAT_01200560;
    extern float DAT_0120055c;
    extern float DAT_01200530, DAT_01200534, DAT_01200538;
    extern float DAT_01200580;
    extern V4_bacd00 DAT_01200590;
}

int __cdecl BSRenderState_SetAlphaTestFuncRef(unsigned int a, unsigned int b, int c);

struct BSParticleShader : FUN_00bacd00
{
    void TallGrassShader_SetupInstanceSize(GeomStub* geom, Param2* p2);
    void SetShaderParams(Param1* p1);
};

// Sets particle shader uniforms from p1 and p2, calls the base vfunc24, and dispatches pass handlers when enabled.
// @fnv 0x00bac9c0
void BSParticleShader::SetShaderParams(Param1* p1)
{
    GeomStub* geom = *DAT_011f91e0;
    void* world = &geom->m_kWorldSpaceTransform;
    NiBound* bound = geom->m_pkWorldBound ? geom->m_pkWorldBound : &DAT_011f4288;
    int unk34 = geom->unkB8->unk34;
    int unkBC = geom->unkBC;
    Param2* p2 = p1->unk0C;

    ((VTable60*)this)->vfunc24(geom, unkBC, 0, unk34, p1, 0, world, bound);

    if (DAT_011f91a7)
    {
        DAT_011fa0c0 = V4_bacd00(1.0f, 1.0f, 1.0f, 1.0f);
    }

    *(G4_bacd00*)&DAT_01200560 = *(G4_bacd00*)&DAT_011f9ee0;

    if (p1->unk00)
    {
        m_k3 = V4_bacd00((float)(p1->unk00->byte1A / 255.0), 0.0f, 0.0f, 0.0f);
    }
    else
    {
        *(G4_bacd00*)&m_k3 = DAT_011a9bd0;
    }

    m_f11c = (float)((DAT_011f940c / 3600.0) * (double)6.28318f * p2->unk7C->f34);
    if (m_f11c >= 6.28318f)
    {
        m_f11c = (float)fmod(m_f11c, 6.28318f);
    }

    DAT_0120055c = m_f11c;

    if ((p2->unk24 & 0x800) > 0)
    {
        DAT_01200530 = 1.0f;
        DAT_01200534 = 1.0f;
    }
    else
    {
        DAT_01200530 = 0.0f;
        DAT_01200534 = 0.0f;
    }
    DAT_01200538 = 1.0f;

    TallGrassShader_SetupInstanceSize(geom, p2);

    if (DAT_011f941e)
    {
        DAT_01200580 = DAT_011f9188;
    }

    if (!DAT_011f9427 && DAT_011f95e4 && (DAT_011f91d8 & 0x20))
    {
        if (_fnv_particle_shader_renderer_level >= 2)
        {
            if ((unsigned int)DAT_011fd890)
            {
                struct FloatPair
                {
                    float x;
                    float y;
                } tmp;
                tmp.x = DAT_011fd874;
                tmp.y = DAT_011fd878;
                DAT_01200590.x = tmp.x;
                DAT_01200590.y = tmp.y;
                DAT_01200590.z = DAT_011adce0;
                DAT_01200590.w = DAT_011fd880;
            }
        }
    }

    if (_fnv_particle_shader_renderer_level < 2 || !DAT_011f941e)
    {
        BSRenderState_SetAlphaTestFuncRef((p1->unk00->word18 >> 10) & 7, p1->unk00->byte1A, 0);
    }

    PassHandler* pass = reinterpret_cast<PassHandler*>(m_spPixelConstantMap.m_pObject);
    if (pass)
    {
        int unk44 = ((BloodSplatterShader*)DAT_0126f74c)->unk44;
        if (unk44)
        {
            pass->vfunc30(unk44, geom, unkBC, 0, unk34, p1, 0, &geom->m_kWorldSpaceTransform, bound, 0, 1);
        }
    }
    pass = reinterpret_cast<PassHandler*>(m_spVertexConstantMap.m_pObject);
    if (pass)
    {
        int unk5c = ((BloodSplatterShader*)DAT_0126f74c)->unk5c;
        if (unk5c)
        {
            pass->vfunc30(unk5c, geom, unkBC, 0, unk34, p1, 0, &geom->m_kWorldSpaceTransform, bound, 0, 1);
        }
    }
}
