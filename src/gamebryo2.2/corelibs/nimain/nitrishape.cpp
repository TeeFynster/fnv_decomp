// gamebryo2.2/corelibs/nimain/nitrishape.cpp: NiTriShape (17 functions)

#include "../../../../include/NiTriShape.h"
#include "../../../../include/NiTriBasedGeom.h"
#include "../../../../include/NiGeometry.h"
#include "../../../../include/NiRenderer.h"
#include "../../../../include/NiTriShapeData.h"
#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/StrArr.h"

// @fnv 0x00A74410
NiTriShape::NiTriShape(unsigned short numVertices, NiPoint3* vertices, NiPoint3* normals, NiColorA* colors,
                       NiPoint2* textures, unsigned short numTriangles, NiGeometryData__DataFlags dataFlags,
                       unsigned short sharedNormalsArraySize, unsigned short* m_kNavMeshTriangleList)
    : NiTriBasedGeom(new NiTriShapeData(numVertices, vertices, normals, colors, textures, numTriangles, dataFlags,
                                        sharedNormalsArraySize, m_kNavMeshTriangleList))
{}

void __fastcall FUN_00a89760(void* pThis);

// Calls FUN_00a89760 on pThis, frees pThis with operator delete when flags has bit 0 set, and returns pThis.
// @fnv 0x00a74530
void* __fastcall DestroyNiTriShape(void* pThis, int, unsigned int flags)
{
    FUN_00a89760(pThis);
    if (flags & 1)
        NiMemObject::operator delete(pThis, sizeof(NiTriShape));
    return pThis;
}

// Calls FUN_00a80610 on this, then if the renderer's state at offset 0x200 is 1 or 2 and byte 0x208 is 1, invokes renderer vtable slot 0x1b4 with this.
// @fnv 0x00a74600
void NiTriShape::RenderWithRenderer(NiRenderer* apkRenderer)
{
    NiGeometry::RenderImmediate(apkRenderer);
    int state = apkRenderer->m_eFrameState;
    if ((state == 1 || state == 2) && apkRenderer->m_bRenderTargetGroupActive == 1)
    {
        ((void(__thiscall*)(NiRenderer*, NiTriShape*))(*(void***)apkRenderer)[0x1b4 / 4])(apkRenderer, this);
    }
}

// NiTriShape and NiTriBasedGeom lack shared default-constructor declarations.
// 0x00a89740 initializes NiTriBasedGeom; 0x0109d454 is NiTriShape's vtable.
NiTriBasedGeom* __fastcall InitTriBasedGeom(NiTriBasedGeom* self) throw();
extern const void* const NiTriShape_vftable[];

// @fnv 0x00a744a0
NiTriShape* __fastcall InitTriShape(NiTriShape* self) throw()
{
    InitTriBasedGeom(self);
    *reinterpret_cast<const void* const**>(self) = NiTriShape_vftable;
    return self;
}

// @fnv 0x00a744d0
NiObject* NiTriShape::CreateObject()
{
    NiTriShape* self = static_cast<NiTriShape*>(NiMemObject::operator new(sizeof(NiTriShape)));
    if (self)
        return InitTriShape(self);
    return 0;
}

extern const char g_011f5b34_arg1[];
// @fnv 0x00a74520
// src: COMMUNITY 0x00a74520
const char* __cdecl NiTriShape_GetRTTI()
{
    return g_011f5b34_arg1;
}

// @fnv 0x00a74560
void NiTriShape::GetTrianglePoints(unsigned short ausTriangleIndex, NiPoint3** pkP0, NiPoint3** pkP1,
                                   NiPoint3** pkP2)
{
    NiTriShapeData* pkModelData = static_cast<NiTriShapeData*>(m_spModelData.m_pObject);
    NiPoint3* pkVertex = pkModelData->m_pkVertex;
    unsigned short* pusTriList = pkModelData->GetTriangleList();
    unsigned short usIndexOffset = ausTriangleIndex * 3;
    *pkP0 = &pkVertex[pusTriList[usIndexOffset++]];
    *pkP1 = &pkVertex[pusTriList[usIndexOffset++]];
    *pkP2 = &pkVertex[pusTriList[usIndexOffset++]];
}

// @fnv 0x00a74640
NiObject* NiTriShape::MakeClone(CloningProcess& kCloning)
{
    NiTriShape* pkClone = static_cast<NiTriShape*>(CreateObject());
    NiTriBasedGeom::CopyMemberData(pkClone, &kCloning);
    return pkClone;
}

// @fnv 0x00a89720
__declspec(noinline) NiTriBasedGeom::NiTriBasedGeom(NiTriBasedGeomData* data) throw() : NiGeometry(data)
{}

// Calls the base renderer, then submits this shape through renderer slot 107 when a render target is active.
// @fnv 0x00a745c0
void NiTriShape::RenderImmediate(NiRenderer* apkRenderer)
{
    NiRenderer* pkRenderer = apkRenderer;
    NiGeometry::RenderImmediate(pkRenderer);
    if ((pkRenderer->m_eFrameState == 1 || pkRenderer->m_eFrameState == 2) &&
        pkRenderer->m_bRenderTargetGroupActive == 1)
    {
        ((void(__thiscall**)(void*, void*))(*(void***)pkRenderer))[107](pkRenderer, this);
    }
}

namespace fnv_00a74690 {
char* NiViewerStrings_NiGetViewerString_Title(const char*);
extern const char* const g_011f5b34_arg1;
}  // namespace fnv_00a74690

// Calls the base handler, resolves g_011f5b34_arg1 to a string, grows pkStrings if its index reached the size, then stores the string at that index.
// @fnv 0x00a74690
void NiTriShape::GetViewerStrings(NiViewerStringsArray* strings)
{
    StrArr* pkStrings = reinterpret_cast<StrArr*>(strings);
    NiTriBasedGeom::GetViewerStrings(strings);
    char* pStr = fnv_00a74690::NiViewerStrings_NiGetViewerString_Title(fnv_00a74690::g_011f5b34_arg1);
    unsigned int uiIndex = *(unsigned short*)((char*)pkStrings + 0xa);
    if (uiIndex >= *(unsigned short*)((char*)pkStrings + 8))
        pkStrings->SetSize(uiIndex + *(unsigned short*)((char*)pkStrings + 0xe));
    pkStrings->SetAt(uiIndex, pStr);
}

// The shared NiTriShape has no constructor taking NiTriBasedGeomData*.
// @fnv 0x00a74480
NiTriShape* __fastcall InitTriShapeWithData(NiTriShape* self, void*, NiTriBasedGeomData* geometry)
{
    self->NiTriBasedGeom::NiTriBasedGeom(geometry);
    *reinterpret_cast<const void* const**>(self) = NiTriShape_vftable;
    return self;
}

extern void __cdecl NiParticleMeshes_CopyMembers();

// @fnv 0x00a744c0
// src: XBOX_PDB 0x00a744c0
void __cdecl NiTriShape_CopyMembers()
{
    NiParticleMeshes_CopyMembers();
}

void NiLines_RegisterStreamables();
// @fnv 0x00a74500
// src: XBOX_PDB 0x00a74500
void NiParticleMeshes_RegisterStreamables()
{
    NiLines_RegisterStreamables();
}

void NiLines_IsEqual();
// @fnv 0x00a74510
// src: XBOX_PDB 0x00a74510
void NiParticleMeshes_IsEqual()
{
    NiLines_IsEqual();
}

void NiLines_LinkObject(NiStream& stream);

// @fnv 0x00a98eb0
// src: XBOX_PDB 0x00a98eb0
void NiParticleMeshes_LinkObject(NiStream& stream)
{
    NiLines_LinkObject(stream);
}

void __cdecl NiLines_SaveBinary();

// @fnv 0x00a71d10
// src: XBOX_PDB 0x00a71d10
void __cdecl NiParticleMeshes_SaveBinary()
{
    NiLines_SaveBinary();
}
