// gamebryo2.2/corelibs/nimain/nitribasedgeomdata.cpp: NiTriBasedGeomData (12 functions)

#include "../../../../include/NiGeometryData.h"
#include "../../../../include/NiTriBasedGeomData.h"
#include "../../../../include/StrArr.h"
// Constructs a NiTriBasedGeomData by initializing the NiGeometryData base and storing the triangle count in m_usTriangles.
// @fnv 0x00a8a920
NiTriBasedGeomData::NiTriBasedGeomData(unsigned short ausVertexCount, NiPoint3* apVertices, NiPoint3* apNormals,
                                       NiColorA* d, NiPoint2* apTextureCoords, unsigned short f,
                                       NiGeometryData__DataFlags aeDataFlags, unsigned short ausTriangleCount)
    : NiGeometryData(ausVertexCount, apVertices, apNormals, d, apTextureCoords, f, aeDataFlags),
      m_usTriangles(ausTriangleCount)
{}

void __fastcall FUN_00a67c00(void* pThis);
extern void* vftable_NiTriBasedGeomData;

// @fnv 0x00a8a970
NiTriBasedGeomData* __fastcall InitializeTriBasedGeomData(NiTriBasedGeomData* pThis)
{
    FUN_00a67c00(pThis);
    pThis->m_usTriangles = 0;
    *(void**)pThis = &vftable_NiTriBasedGeomData;
    return pThis;
}

struct FakeBinaryStream
{
    int pad;
    unsigned int position;
    unsigned int(__cdecl* read)(void*, void*, unsigned int, unsigned int*, unsigned int);
};

// Loads NiGeometryData binary data from the stream, then reads 2 bytes from the stream's binary reader into this+0x40.
// @fnv 0x00a8aa30
void NiTriBasedGeomData::LoadBinary(NiStream& kStream)
{
    NiGeometryData::LoadBinary(kStream);
    FakeBinaryStream* __restrict input =
        *reinterpret_cast<FakeBinaryStream**>(reinterpret_cast<char*>(&kStream) + 0x24c);
    unsigned int size = 2;
    input->position += input->read(input, &m_usTriangles, 2, &size, 1);
}

struct NiBinaryStream_Save
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(void*, const void*, unsigned int, unsigned int*, unsigned int);
};

// @fnv 0x00a8aa70
void NiTriBasedGeomData::SaveBinary(NiStream& kStream)
{
    NiGeometryData::SaveBinary(kStream);
    NiBinaryStream_Save* __restrict output = *(NiBinaryStream_Save**)((char*)&kStream + 0x250);
    unsigned int size = 2;
    output->m_uiStreamFlags += output->m_pfnWrite(output, &m_usTriangles, 2, &size, 1);
}

extern char const* const g_011f4a70_arg1;

// @fnv 0x00a8a9f0
// src: COMMUNITY 0x00a8a9f0
char const* const* __cdecl NiTriBasedGeomData_GetRTTI()
{
    return &g_011f4a70_arg1;
}


#include "../../../../include/NiTPrimitiveArray.h"

// The shared classes do not declare their viewer-string overrides yet.
void RegisterGeometryFields();
typedef void (__thiscall* RegisterGeometryFieldsFn)(NiGeometryData*, NiTPrimitiveArray<char*>*);

extern char const* const g_011f4a70_arg1;
char* __cdecl _FUN_00a7d330(char const* pString);
char* __cdecl NiGetViewerString_00a7d490(char const* pString, unsigned short usValue);

// Calls RegisterFields, then appends a string from g_011f4a70_arg1 and a formatted m_usTriangles entry to pkStrings, growing it when full.
// @fnv 0x00a8aab0
void __fastcall AppendTrianglesInfo(NiTriBasedGeomData* pThis, void*, NiTPrimitiveArray<char*>* pkStrings)
{
    reinterpret_cast<RegisterGeometryFieldsFn>(&RegisterGeometryFields)(pThis, pkStrings);

    char* pString = _FUN_00a7d330(g_011f4a70_arg1);

    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiCapacity = pkStrings->m_usMaxSize;
    if (uiSize >= uiCapacity)
    {
        unsigned int uiGrowSize = pkStrings->m_usGrowBy;
        pkStrings->SetSize(uiSize + uiGrowSize);
    }

    pkStrings->SetAt(uiSize, pString);

    pString = NiGetViewerString_00a7d490("m_usTriangles", pThis->m_usTriangles);

    uiSize = pkStrings->m_usSize;
    uiCapacity = pkStrings->m_usMaxSize;
    if (uiSize >= uiCapacity)
    {
        unsigned int uiGrowSize = pkStrings->m_usGrowBy;
        pkStrings->SetSize(uiSize + uiGrowSize);
    }

    pkStrings->SetAt(uiSize, pString);
}

// @fnv 0x00a8a990
NiTriBasedGeomData::~NiTriBasedGeomData()
{}

// The shared classes do not declare their equality overrides yet.
void GeometryDataIsEqual();
typedef bool (__thiscall* GeometryDataIsEqualFn)(NiGeometryData*, const NiGeometryData*);

// @fnv 0x00a8a9c0
unsigned char __fastcall MatchesTriangleCount(NiTriBasedGeomData* pThis, void*, const NiGeometryData* pkObject)
{
    if (!reinterpret_cast<GeometryDataIsEqualFn>(&GeometryDataIsEqual)(pThis, pkObject))
        return false;
    return pThis->m_usTriangles == static_cast<const NiTriBasedGeomData*>(pkObject)->m_usTriangles;
}

// @fnv 0x00a8a9b0
bool NiTriBasedGeomData::RegisterStreamables(NiStream& kStream)
{
    return NiGeometryData::RegisterStreamables(kStream);
}

// @fnv 0x00d3dd00
void NiTriBasedGeomData::GetTriangles(unsigned short&, const unsigned short*&, const unsigned short*&, unsigned int&)
{}

// @fnv 0x00a8a9a0
void NiTriBasedGeomData::LinkObject(NiStream& kStream)
{
    NiGeometryData::LinkObject(kStream);
}
