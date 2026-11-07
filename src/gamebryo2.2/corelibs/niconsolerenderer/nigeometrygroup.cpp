// gamebryo2.2/corelibs/niconsolerenderer/nigeometrygroup.cpp: NiGeometryGroup, NiGeometryBufferData (6 functions)

#include "../../../../include/NiGeometryBufferData.h"
#include "../../../../include/NiGeometryGroup.h"
#include "nigeometrygroup_decls.h"
// Initializes the NiGeometryGroup vtable pointer, sets m_uiRefCount to 0, and clears the second member.
// @fnv 0x00e986f0
NiGeometryGroup::NiGeometryGroup()
{
    DAT_00fdf0e4((volatile long*)&m_uiRefCount, 0);
    m_pD3DDevice = 0;
}

// @fnv 0x00e98750
void NiGeometryGroup::RemoveObject(NiGeometryBufferData* data)
{
    InterlockedDecrement((volatile long*)&m_uiRefCount);
    unsigned int count = data->m_uiRegisterStreamCount;
    data->m_pkOwnerGroup = 0;
    for (unsigned int i = 0; i < count; ++i)
        vf07(data, i);
    data->ReleaseBuffers();
}

// Initializes the NiGeometryBufferData object: sets the vtable pointer, zeroes all fields, sets one field to 4, and clears m_pusIndexArray.
// @fnv 0x00e947c0
NiGeometryBufferData::NiGeometryBufferData()
{
    m_uiValue1 = 0;
    m_pkOwnerGroup = 0;
    m_uiGroupIndex = 0;
    m_pkVertexDeclaration = 0;
    m_bIsInitialized = false;
    m_uiVertexCount = 0;
    m_uiVertexDataSize = 0;
    m_uiRegisterStreamCount = 0;
    m_puiVertexStrides = 0;
    m_ppkVertexBuffers = 0;
    m_uiStartIndex = 0;
    m_uiPrimitiveCount = 0;
    m_pkIndexBuffer = 0;
    m_uiBufferSize = 0;
    m_eRequestType = 4;
    m_uiIndexArrayCount = 0;
    m_uiMinimumIndex = 0;
    m_uiMaximumIndex = 0;
    m_pusIndexData = 0;
    m_pusIndexArray = 0;
}

__declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

// @fnv 0x00e98730
// src: COMMUNITY 0x00e98730
void __fastcall NiGeometryGroup_AddObject(int pObject, int, int pArg)
{
    InterlockedIncrement((long volatile*)(pObject + 4));
    *(int*)(pArg + 8) = pObject;
}

struct FakeDevice
{
    virtual void F0();
    virtual void F1();
    virtual unsigned long __stdcall Release();
};

// Releases the attached D3D device, if present.
// @fnv 0x00e98710
NiGeometryGroup::~NiGeometryGroup()
{
    void* device = m_pD3DDevice;
    if (device != 0)
        ((FakeDevice*)device)->Release();
}

// The game's deleting destructor uses NiMemObject's sized deallocation.
// @fnv 0x00e98790
void* __fastcall DeleteNiGeometryGroup(NiGeometryGroup* group, int, unsigned int flags)
{
    group->NiGeometryGroup::~NiGeometryGroup();
    if (flags & 1)
        NiMemObject::operator delete(group, sizeof(NiGeometryGroup));
    return group;
}
