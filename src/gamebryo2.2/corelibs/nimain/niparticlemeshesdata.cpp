
// src/gamebryo2.2/corelibs/nimain/niparticlemeshesdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niparticlemeshesdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiLinesData.h"
#include "../../../../include/NiParticleMeshesData.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiMatrix3.h"

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f5f0c;

// @fnv 0x00a98b00
// src: COMMUNITY 0x00a98b00
GlobalObjectO2_00a7b610* __cdecl NiParticleMeshesData_GetRTTI()
{
    return &g_011f5f0c;
}

// @fnv 0x00a98a10
// src: XBOX_PDB 0x00a98a10
void NiParticleMeshesData::LoadBinary_00a98a10(NiStream& stream)
{
    NiParticlesData::LoadBinary(stream);
    stream.ResetStreamState();
}

// Removes node children from usActive up to m_usActive, then clamps m_usActive to m_usVertices.
// @fnv 0x00a98a30
// src: XBOX_PDB 0x00a98a30
void NiParticleMeshesData::SetActiveVertexCount(unsigned short usActive)
{
    unsigned short i;
    for (i = usActive; i < m_usActive; ++i)
        m_spRootNode.m_pObject->RemoveNthObject(i);
    if (usActive <= m_usVertices)
        m_usActive = usActive;
    else
        m_usActive = m_usVertices;
}

// Registers the base NiLinesData streamables, then registers the streamables of the node at offset 0x70; returns false if the base call fails.
// @fnv 0x00a98a80
// src: XBOX_PDB 0x00a98a80
bool NiParticleMeshesData::RegisterStreamables_00a98a80(NiStream& kStream)
{
    if (!((NiLinesData*)this)->NiLinesData::RegisterStreamables(kStream))
        return 0;
    m_spRootNode.m_pObject->RegisterStreamables(kStream);
    return 1;
}

// @fnv 0x00a98ab0
// src: XBOX_PDB 0x00a98ab0
void NiParticleMeshesData::SaveBinary_00a98ab0(NiStream& kStream)
{
    NiNode* pkNode;
    NiParticlesData::SaveBinary(kStream);
    pkNode = m_spRootNode.m_pObject;
    kStream.SaveLinkID(pkNode);
}

// Checks the base hook against pkObject, then compares this holder's mesh node with the other holder's mesh node via IsEqual.
// @fnv 0x00a98ad0
bool NiParticleMeshesData::IsMeshNodeEqual(void* pkObject)
{
    NiParticleMeshesData* pkPart = (NiParticleMeshesData*)pkObject;
    if (!NiParticlesData::IsEqual((NiObject*)pkObject))
        return false;
    NiNode* mine = m_spRootNode.m_pObject;
    NiNode* other = pkPart->m_spRootNode.m_pObject;
    // IsEqual is slot 23; this caller normalizes its raw result byte.
    typedef unsigned char (__thiscall *EqualityResultByte)(NiObject*, NiObject*);
    return reinterpret_cast<EqualityResultByte>((*reinterpret_cast<void***>(mine))[23])(mine, other);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

// Links the object to kStream, then swaps m_spRootNode to the stream's object, releasing the old one and retaining the new one.
// @fnv 0x00a98d60
// src: XBOX_PDB 0x00a98d60
void NiParticleMeshesData::LinkObject_00a98d60(NiStream& kStream)
{
    ((NiLinesData*)this)->NiLinesData::LinkObject(kStream);
    NiObject* pkNew = kStream.GetLoadedObject();
    NiObject* pkOld = m_spRootNode.m_pObject;
    if (pkOld != pkNew)
    {
        if (pkOld && InterlockedDecrement((volatile long*)&pkOld->m_uiRefCount) == 0)
            pkOld->DeleteThis();
        m_spRootNode.m_pObject = (NiNode*)pkNew;
        if (pkNew)
            InterlockedIncrement((volatile long*)&pkNew->m_uiRefCount);
    }
}

void __cdecl _delete(void*, unsigned int);

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

inline void NiNode::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}

inline void NiNode::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}

inline void NiAVObject::DecRefCount()
{
    if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
        DeleteThis();
}

// The shared smart pointer declares these operations out of line. Keep the
// original unit's inline ownership operations here.
template <> inline NiPointer<NiNode>::NiPointer() : m_pObject(0)
{}

template <> inline NiPointer<NiNode>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

template <> inline NiPointer<NiNode>& NiPointer<NiNode>::operator=(NiNode* object)
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

// Initializes the object by allocating a new NiNode with zero children and setting the flag to false.
// @fnv 0x00a98b10
NiParticleMeshesData::NiParticleMeshesData() throw()
{
    m_spRootNode = new NiNode(0);
    m_bModifierActive = false;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend) throw();

// The shared base has no declaration for its particle-removal implementation.
struct ParticleRemoval : NiParticlesData
{
    void FUN_00a964c0(unsigned short usParticle);
};

// @fnv 0x00a98bf0
void NiParticleMeshesData::RemoveParticleMesh(unsigned short usParticle)
{
    unsigned short usFinalIndex = m_usActive - 1;
    if (usParticle == usFinalIndex)
    {
        m_spRootNode.m_pObject->RemoveNthObject(usFinalIndex);
    }
    else
    {
        NiAVObject* pkFinal = 0;
        m_spRootNode.m_pObject->RemoveNthObject2(usFinalIndex, &pkFinal);
        m_spRootNode.m_pObject->RemoveNthObject(usParticle);
        m_spRootNode.m_pObject->ReplaceNthObject(usParticle, pkFinal);
        if (pkFinal)
            pkFinal->DecRefCount();
    }
    ((ParticleRemoval*)this)->FUN_00a964c0(usParticle);
}

extern "C" double __cdecl fabs(double);

inline float fabsf(float _X)
{
    return ((float)fabs((double)_X));
}
inline float fabs(float _X)
{
    return (fabsf(_X));
}

// @fnv 0x00a98c90
void NiParticleMeshesData::UpdateParticleMeshes()
{
    for (unsigned int i = 0; i < m_usActive; i++)
    {
        NiAVObject* pkMesh = m_spRootNode.m_pObject->m_kChildren.m_pBase[i].m_pObject;
        if (pkMesh)
        {
            pkMesh->m_kLocal.m_Translate = m_pkVertex[i];
            if (m_pkRotations)
                m_pkRotations[i].ToRotationMatrix(pkMesh->m_kLocal.m_Rotate);
            pkMesh->m_kLocal.m_fScale = fabs(m_pfSizes[i] * m_pfRadii[i]);
        }
    }
}

inline void* __cdecl operator new(unsigned int, void* where)
{
    return where;
}
// Allocates a 0x78-byte object, constructs it, sets the bool at offset 0x40 to true, and returns it.
// @fnv 0x00a98d30
// src: EXE 0x00a98d30
NiParticleMeshesData* __cdecl NiParticleMeshesData_CreateObject()
{
    NiParticleMeshesData* pObject = ::new (NiMemObject::operator new(0x78)) NiParticleMeshesData();
    pObject->m_bHasRadii = true;
    return pObject;
}

struct FUN_0096ad30_This
{
    int unk00;
    int unk04;
    unsigned short m_pRayCursor;
    unsigned short m_uiItemCount;
    unsigned short m_unk0C;
    unsigned short m_growth;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, void*);
};
void __stdcall FUN_00a97420(void*);
void* __cdecl NiViewerStrings_NiGetViewerString_Title(void*);
// Calls FUN_00a97420 on p, fetches an item via FUN_00a7d330, grows the container if count reaches capacity, then stores the item at index count.
// @fnv 0x00a98de0
// src: XBOX_PDB 0x00a98de0
void __stdcall NiParticleMeshesData_GetViewerStrings(FUN_0096ad30_This* pContainer)
{
    FUN_00a97420(pContainer);
    void* item = NiViewerStrings_NiGetViewerString_Title(*(void**)&g_011f5f0c);
    unsigned int count = pContainer->m_uiItemCount;
    unsigned int capacity = pContainer->m_pRayCursor;
    if (count >= capacity)
        pContainer->FUN_0096ad30((unsigned int)pContainer->m_growth + count);
    pContainer->FUN_0096ae90(count, &item);
}

#include <windows.h>

// Calls FUN_00a98b90 on this, frees this with _delete when flags has bit 1 set, and returns this.
// @fnv 0x00a98dc0
void* __fastcall DestroyIfFlagged(NiParticleMeshesData* self, void*, unsigned int flags)
{
    self->NiParticleMeshesData::~NiParticleMeshesData();
    if (flags & 1)
        _delete(self, 0x78);
    return self;
}

// @fnv 0x00a98b90
NiParticleMeshesData::~NiParticleMeshesData() throw()
{
    m_spRootNode = (NiNode*)0;
}
