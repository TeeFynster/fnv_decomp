// gamebryo2.2/corelibs/nimain/nitristrips.cpp: NiTriStrips (10 functions)

#include "../../../../include/NiDX9Renderer.h"
#include "../../../../include/NiParticleMeshes.h"
#include "../../../../include/NiRenderer.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiGeometry.h"
#include "../../../../include/NiTriStrips.h"
extern unsigned int DAT_0109ed94;

// The shared base has no default constructor declaration.
// @fnv 0x00a89740
__declspec(noinline) NiTriBasedGeom* __fastcall InitTriBasedGeom(NiTriBasedGeom* self, void*)
{
    self->NiGeometry::NiGeometry();
    *reinterpret_cast<unsigned int**>(self) = &DAT_0109ed94;
    return self;
}

struct _FakeTriData
{
    char pad[0x1c];
    NiPoint3* m_pkVertex;
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
    virtual void GetTriangleVertexIndices(unsigned short, unsigned short&, unsigned short&, unsigned short&);
};

// @fnv 0x00a71e00
void __fastcall GetTriangleVertices(NiTriStrips* self, void*, unsigned short m_usTriangleID,
                                    NiPoint3** pkP0, NiPoint3** pkP1, NiPoint3** pkP2)
{
    _FakeTriData* pkModelData = reinterpret_cast<_FakeTriData*>(self->m_spModelData.m_pObject);
    NiPoint3* pkVertex = pkModelData->m_pkVertex;
    unsigned short usIndex0, usIndex1, usIndex2;
    pkModelData->GetTriangleVertexIndices(m_usTriangleID, usIndex0, usIndex1, usIndex2);
    *pkP0 = &pkVertex[usIndex0];
    *pkP1 = &pkVertex[usIndex1];
    *pkP2 = &pkVertex[usIndex2];
}

extern char const* const g_012024b8_arg1;

// @fnv 0x00a71d20
// src: COMMUNITY 0x00a71d20
char const* const* __cdecl NiTriStrips_GetRTTI()
{
    return &g_012024b8_arg1;
}

// Allocates 0xc4 bytes, constructs a NiGeometry in place, sets its vtable to NiParticleMeshes::vftable, and returns the pointer or 0 on failure.
// @fnv 0x00a9b150
// src: EXE 0x00a9b150
void* __cdecl NiParticles_CreateObject()
{
    void* pObject = BSFadeNode::operator new(0xc4);
    if (pObject)
    {
        NiGeometry* obj = static_cast<NiGeometry*>(pObject);
        obj->NiGeometry::NiGeometry();
        *reinterpret_cast<void**>(pObject) = &NiParticleMeshes::vftable;
        return pObject;
    }
    return 0;
}

// Calls FUN_00a80610, then if the renderer's field at 0x200 is 1 or 2 and the byte at 0x208 is 1, invokes virtual slot 110 with this.
// @fnv 0x00a71d70
void __fastcall RenderTriStrips(NiTriStrips* self, void*, NiRenderer* apkRenderer)
{
    self->NiGeometry::RenderImmediate(apkRenderer);
    int i = apkRenderer->m_eFrameState;
    if ((i == 1 || i == 2) && apkRenderer->m_bRenderTargetGroupActive == 1)
    {
        void** vtbl = *(void***)apkRenderer;
        ((void(__thiscall*)(NiRenderer*, void*))vtbl[110])(apkRenderer, self);
    }
}

char* _FUN_00a7d330(char const*);
// Calls the base handler, then appends the string returned by _FUN_00a7d330 to pkStrings, growing it by m_usGrowBy when m_usSize has reached m_usMaxSize.
// @fnv 0x00a71e70
void __fastcall AppendString(NiTriStrips* self, void*, StrArr* pkStrings)
{
    self->NiTriBasedGeom::GetViewerStrings(reinterpret_cast<NiViewerStringsArray*>(pkStrings));
    char* tmp = _FUN_00a7d330(g_012024b8_arg1);
    unsigned int sz = pkStrings->m_usSize;
    if (sz >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(sz + pkStrings->m_usGrowBy);
    pkStrings->SetAt(sz, tmp);
}

// @fnv 0x00a71d30
void __fastcall RenderTriStripsAlt(NiTriStrips* self, void*, NiRenderer* apkRenderer)
{
    NiDX9Renderer* pkRenderer = (NiDX9Renderer*)apkRenderer;
    self->NiGeometry::RenderImmediate(apkRenderer);
    if ((pkRenderer->m_eFrameState == 1 || pkRenderer->m_eFrameState == 2) && pkRenderer->m_bRenderTargetGroupActive == 1)
        ((void(__thiscall**)(NiRenderer*, void*)) * (void***)pkRenderer)[108](pkRenderer, self);
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern "C" void* DAT_0109cd44;
void __fastcall CopyTriStrips(NiTriStrips* self, void*, NiTriStrips* strips, int value);
// @fnv 0x00a71db0
NiTriStrips* __fastcall CreateTriStripsObject(NiTriStrips* self, void*, int value)
{
    NiTriStrips* strips = static_cast<NiTriStrips*>(Object_DispatchCommandFour(sizeof(NiTriStrips)));
    if (strips)
    {
        reinterpret_cast<NiTriBasedGeom*(__thiscall*)(NiTriBasedGeom*)>(InitTriBasedGeom)(strips);
        *reinterpret_cast<void**>(strips) = &DAT_0109cd44;
    }
    else
    {
        strips = 0;
    }
    reinterpret_cast<void(__thiscall*)(NiTriStrips*, NiTriStrips*, int)>(CopyTriStrips)(self, strips, value);
    return strips;
}

void __cdecl FUN_00a80400();

// @fnv 0x00a9b140
// src: XBOX_PDB 0x00a9b140
void __cdecl NiParticleMeshes_CopyMembers()
{
    FUN_00a80400();
}

void __cdecl NiLines_LoadBinary();
// @fnv 0x00a98ea0
// src: XBOX_PDB 0x00a98ea0
void __cdecl NiParticleMeshes_LoadBinary()
{
    NiLines_LoadBinary();
}
