#include "../../../../include/BSFadeNode.h"
#include "../../../../include/BSResizableTriShape.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/StrArr.h"

// src/gamebryo2.2/corelibs/nimain/bsresizabletrishape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/bsresizabletrishape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f5b34;

// @fnv 0x00a86d20
// src: COMMUNITY 0x00a86d20
GlobalObjectO2_00a7b610* __cdecl BSResizableTriShape_GetRTTI()
{
    return &g_011f5b34;
}

// @fnv 0x00a86d30
void* BSResizableTriShape::GetBoundingVolume()
{
    return (NiBound*)((char*)this + 0xc8);
}

extern "C" void __cdecl _delete(void*, unsigned int);
void __fastcall FUN_00a89760(void*);
extern void* DAT_0109e704;

// Preserve the original x86 field offsets where shared headers expose no matching fields.

// The shared class has no scalar deleting destructor declaration; use the original register ABI here.
// Sets the vtable pointer, calls FUN_00a89760 on this, and if flags bit 0 is set deletes this with size 0xd8, returning this.
// @fnv 0x00a86da0
void* __fastcall DestroyResizableTriShape(BSResizableTriShape* self, void*, unsigned int flags)
{
    ((void**)(self))[0] = &DAT_0109e704;
    FUN_00a89760(self);
    if (flags & 1)
        _delete(self, 0xd8);
    return self;
}

struct FUN_00a74600_shell
{
    void __thiscall FUN_00a74600(NiRenderer* apRenderer);
};

// Copies four dwords from offsets 0xc8-0xd4 into the NiBound at this+0x20, then calls FUN_00a74600 with the renderer.
// @fnv 0x00a86e40
void BSResizableTriShape::RenderWithRenderer(NiRenderer* apRenderer)
{
    float fW = *(float*)((char*)this + 0xd4);
    NiBound* pkDest = *(NiBound**)((char*)this + 0x20);
    *reinterpret_cast<unsigned int*>(&pkDest->m_kCenter.x) = *(unsigned int*)((char*)this + 0xc8);
    *reinterpret_cast<unsigned int*>(&pkDest->m_kCenter.y) = *(unsigned int*)((char*)this + 0xcc);
    *reinterpret_cast<unsigned int*>(&pkDest->m_kCenter.z) = *(unsigned int*)((char*)this + 0xd0);
    pkDest->m_fRadius = fW;
    ((FUN_00a74600_shell*)this)->FUN_00a74600(apRenderer);
}

struct FUN_00a74480_holder
{
    void __thiscall FUN_00a74480(unsigned int);
};
// The shared class has no matching constructor declaration; initialise existing storage here.
// Calls the base constructor with a, installs the vtable pointer, and zeroes the field at offset 0xC4.
// @fnv 0x00a86dd0
BSResizableTriShape* __fastcall ConstructResizableTriShape(BSResizableTriShape* self, void*, unsigned int a)
{
    ((FUN_00a74480_holder*)self)->FUN_00a74480(a);
    *(void**)self = (void*)&DAT_0109e704;
    *(unsigned int*)((char*)self + 0xC4) = 0;
    return self;
}

struct FUN_00a744c0_holder
{
    void __thiscall NiTriShape_CopyMembers(BSResizableTriShape* pkClone, CloningProcess& kCloning);
};
// @fnv 0x00a86e80
NiObject* BSResizableTriShape::MakeClone(CloningProcess& kCloning)
{
    BSResizableTriShape* pkObject;
    pkObject = (BSResizableTriShape*)BSFadeNode::operator new(0xD8);
    if (pkObject)
    {
        ((BSFadeNode*)pkObject)->FUN_00a744a0();
        *(void**)pkObject = (void*)&DAT_0109e704;
    }
    else
    {
        pkObject = 0;
    }
    ((FUN_00a744c0_holder*)this)->NiTriShape_CopyMembers(pkObject, kCloning);
    *(unsigned int*)((char*)pkObject + 0xC4) = *(unsigned int*)((char*)this + 0xC4);
    return (NiObject*)pkObject;
}

// NiStream has different class/struct declarations in the working and approved headers.
// Keep the original pointer ABI for these stream entry points without a local stream definition.
struct FUN_00a71d10_shell
{
    void __thiscall NiParticleMeshes_SaveBinary(void*);
};
// @fnv 0x00a86ed0
void __fastcall SaveResizableTriShape(BSResizableTriShape* self, void*, void* stream)
{
    ((FUN_00a71d10_shell*)self)->NiParticleMeshes_SaveBinary(stream);
    NiBinaryStream* __restrict input = *(NiBinaryStream**)((char*)stream + 0x250);
    unsigned int size = 4;
    *(unsigned int*)((char*)input + 4) +=
        (*(NiBinaryStream::WriteFunction*)((char*)input + 0xc))(input, (void*)((char*)self + 0xc4), 4, &size, 1);
}

struct BaseX86f10
{
    void __thiscall NiParticleMeshes_LoadBinary(void*);
};
// Calls FUN_00a98ea0, then reads 4 bytes into this+0xc4 and advances the binary stream position.
// @fnv 0x00a86f10
void __fastcall LoadResizableTriShape(BSResizableTriShape* self, void*, void* stream)
{
    ((BaseX86f10*)self)->NiParticleMeshes_LoadBinary(stream);
    NiBinaryStream* __restrict input = *(NiBinaryStream**)((char*)stream + 0x24c);
    unsigned int size = 4;
    *(unsigned int*)((char*)input + 4) +=
        (*(NiBinaryStream::ReadFunction*)((char*)input + 8))(input, (char*)self + 0xc4, 4, &size, 1);
}

struct P03MM
{
    void* __thiscall Allocate(unsigned int);
};
extern P03MM g_memoryManager;
extern unsigned int _NiPoint3_ZERO;
extern unsigned char DAT_011f4270;
extern unsigned char DAT_011f4274;
struct NiTransformDummy
{
    char d[52];
};
struct NiBoundUpdateHelper
{
    void __thiscall Update(NiBound const&, NiTransformDummy const&);
};
struct WBHelper
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
    virtual void SetWorldBound(NiBound*);
};
// Allocates and initialises the world bound if absent, then updates it from the object's bound and transform.
// @fnv 0x00c1a4a0
void BSResizableTriShape::UpdateWorldBound()
{
    NiBound* kBound;
    if (!*(NiBound**)((char*)this + 0x20))
    {
        kBound = (NiBound*)g_memoryManager.Allocate(16);
        ((WBHelper*)this)->SetWorldBound(kBound);
        kBound = *(NiBound**)((char*)this + 0x20);
        *reinterpret_cast<unsigned int*>(&kBound->m_kCenter.x) = _NiPoint3_ZERO;
        *reinterpret_cast<unsigned int*>(&kBound->m_kCenter.y) = *(unsigned int*)&DAT_011f4270;
        *reinterpret_cast<unsigned int*>(&kBound->m_kCenter.z) = *(unsigned int*)&DAT_011f4274;
        kBound->m_fRadius = 0.0f;
    }
    ((NiBoundUpdateHelper*)*(NiBound**)((char*)this + 0x20))
        ->Update(*(NiBound*)((char*)this + 0xC8), *(NiTransformDummy*)((char*)this + 0x68));
}

struct Caller74690
{
    void __thiscall FUN_00a74690(StrArr* strings);
};

char* __cdecl _FUN_00a7d330(char* value);
char* __cdecl NiGetViewerString_00a7d510(char const* text, char const* value);

extern char str_0109e800[];

// @fnv 0x00a86f50
void BSResizableTriShape::GetViewerStrings(NiViewerStringsArray* array)
{
    StrArr* strings = (StrArr*)array;
    char* value;
    unsigned int index;
    unsigned int count;

    ((Caller74690*)this)->FUN_00a74690(strings);

    value = _FUN_00a7d330(*reinterpret_cast<char**>(&g_011f5b34));
    index = strings->m_usSize;
    count = strings->m_usMaxSize;

    if (index >= count)
        strings->SetSize(static_cast<unsigned int>(strings->m_usGrowBy) + index);

    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d510(str_0109e800, *(char**)((char*)this + 0xc4));
    index = strings->m_usSize;
    count = strings->m_usMaxSize;

    if (index >= count)
        strings->SetSize(static_cast<unsigned int>(strings->m_usGrowBy) + index);

    strings->SetAt(index, value);
}

struct TriShapeImmediateRenderer
{
    void FUN_00a745c0();
};

// The shared class only declares RenderImmediate with a renderer argument.
// Copies the local bound into the world bound, then calls the base immediate renderer.
// @fnv 0x00a86e00
void __fastcall RenderResizableTriShape(BSResizableTriShape* self, void*)
{
    NiBound* pBound = *(NiBound**)((char*)self + 0x20);
    NiBound& m_bound = *(NiBound*)((char*)self + 0xc8);
    float w = m_bound.m_fRadius;
    *reinterpret_cast<unsigned int*>(&pBound->m_kCenter.x) = *reinterpret_cast<unsigned int*>(&m_bound.m_kCenter.x);
    *reinterpret_cast<unsigned int*>(&pBound->m_kCenter.y) = *reinterpret_cast<unsigned int*>(&m_bound.m_kCenter.y);
    *reinterpret_cast<unsigned int*>(&pBound->m_kCenter.z) = *reinterpret_cast<unsigned int*>(&m_bound.m_kCenter.z);
    pBound->m_fRadius = w;
    ((TriShapeImmediateRenderer*)self)->FUN_00a745c0();
}

void __cdecl NiParticleMeshes_LinkObject();
// @fnv 0x00a86d40
// src: XBOX_PDB 0x00a86d40
void __cdecl BSResizableTriShape_LinkObject()
{
    NiParticleMeshes_LinkObject();
}

void __cdecl NiParticleMeshes_IsEqual();

// @fnv 0x00a877f0
// src: XBOX_PDB 0x00a877f0
void __cdecl BSResizableTriShape_IsEqual()
{
    NiParticleMeshes_IsEqual();
}

struct TriShapePrimitiveSetter
{
    void NiParticleMeshes_RegisterStreamables(unsigned int value);
};

// @fnv 0x00a87190
void BSResizableTriShape::SetNumPrimitives(unsigned int value)
{
    ((TriShapePrimitiveSetter*)this)->NiParticleMeshes_RegisterStreamables(value);
}

struct BoundRadiusValue
{
    float v;
};

struct BoundCenterBits
{
    int x;
    int y;
    int z;
};

// Keep the original centre/radius value arguments: the shared NiBound has a nontrivial copy constructor.
// @fnv 0x00a86d50
void __fastcall SetResizableTriShapeBounds(BSResizableTriShape* self, void*, BoundCenterBits p, BoundRadiusValue rw)
{
    *(float*)((char*)self + 0xd4) = rw.v;
    float t = rw.v;
    *(BoundCenterBits*)((char*)self + 0xc8) = p;
    NiBound* pBound = *(NiBound**)((char*)self + 0x20);
    *reinterpret_cast<unsigned int*>(&pBound->m_kCenter.x) = p.x;
    *reinterpret_cast<unsigned int*>(&pBound->m_kCenter.y) = p.y;
    *reinterpret_cast<unsigned int*>(&pBound->m_kCenter.z) = p.z;
    pBound->m_fRadius = t;
}
