#include "../../../../include/BSFadeNode.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiTArray.h"
#include "../../../../include/NiTObjectArray.h"
#include "../../../../include/NiTPrimitiveArray.h"

extern "C" void __cdecl _NiFreeC30(void* pvMem) throw();

// This unit supplies the inline implementation of the mesh pool array (the shared NiTArray, its bodies defined here).
typedef NiTObjectArray<NiPointer<NiAVObject> >* NiMeshPSysDataPool;
template <> NiMeshPSysDataPool* NiTNewInterface<NiMeshPSysDataPool>::Allocate(unsigned int uiNumElements) throw();
template <>
__forceinline NiTArray<NiMeshPSysDataPool, NiTNewInterface<NiMeshPSysDataPool> >::NiTArray(unsigned int uiCapacity,
                                                                                         unsigned int uiStep)
{
    this->m_usMaxSize = (unsigned short)uiCapacity;
    this->m_usGrowBy = (unsigned short)uiStep;
    this->m_usSize = 0;
    this->m_usESize = 0;
    if (this->m_usMaxSize > 0)
        this->m_pBase = NiTNewInterface<NiMeshPSysDataPool>::Allocate(this->m_usMaxSize);
    else
        this->m_pBase = 0;
}
extern MemoryManager _g_memoryManager;
inline void __cdecl operator delete(void* object) throw()
{
    _g_memoryManager._DeallocateAlias(object);
}

// @fnv 0x00c309a0 (compiler-generated scalar deleting destructor of the pool array base)
template <> inline NiTArray<NiMeshPSysDataPool, NiTNewInterface<NiMeshPSysDataPool> >::~NiTArray() throw()
{
    _NiFreeC30(this->m_pBase);
}

// Gamebryo inline bodies (NiTArray.inl / NiTCollection.h) this unit's original inlines:
template <class T, class TAlloc> inline NiTArray<T, TAlloc>::NiTArray(unsigned int uiCapacity, unsigned int uiStep)
{
    this->m_usMaxSize = (unsigned short)uiCapacity;
    this->m_usGrowBy = (unsigned short)uiStep;
    this->m_usSize = 0;
    this->m_usESize = 0;
    if (this->m_usMaxSize > 0)
        this->m_pBase = TAlloc::Allocate(this->m_usMaxSize);
    else
        this->m_pBase = 0;
}
template <class T> inline T* NiTNewInterface<T>::Allocate(unsigned int uiNumElements)
{
    return new T[uiNumElements];
}
template <class T>
inline NiTObjectArray<T>::NiTObjectArray(unsigned int uiCapacity, unsigned int uiStep)
    : NiTArray<T, NiTNewInterface<T> >(uiCapacity, uiStep)
{
}

// This allocation constructor is nonthrowing in the original inline path.
template <>
inline NiTObjectArray<NiPointer<NiAVObject> >::NiTObjectArray(unsigned int uiCapacity,
    unsigned int uiStep) throw()
    : NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > >(uiCapacity, uiStep)
{
}

extern MemoryManager _g_memoryManager;
template <class T, class TAlloc> inline void* NiTArray<T, TAlloc>::operator new(size_t size)
{
    return _g_memoryManager.Allocate(size);
}

template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::GetSize() const
{
    return this->m_usSize;
}

template <class T, class TAlloc> inline T NiTArray<T, TAlloc>::RemoveEnd()
{
    if (this->m_usSize == 0)
        return T(0);
    this->m_usSize--;
    T kItem = this->m_pBase[this->m_usSize];
    this->m_pBase[this->m_usSize] = T(0);
    if (kItem != T(0))
        this->m_usESize--;
    return kItem;
}

#include "../../../../include/NiMeshPSysData.h"
#include "../../../../include/NiPSysData.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/StrArr.h"

// Stream storage is opaque in the shared headers. Keep the original inline
// transfers and accessors here so their calls and byte counters remain inlined.
inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes,
    unsigned int* componentSizes, unsigned int componentCount)
{
    unsigned int transferred = (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))(
        this, buffer, bytes, componentSizes, componentCount);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += transferred;
    return transferred;
}

inline void NiBinaryStream::Write(void* data, unsigned int bytes)
{
    unsigned int actual = bytes;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) +=
        (*reinterpret_cast<WriteFunction*>(reinterpret_cast<char*>(this) + 12))(this, data, bytes, &actual, 1);
}

inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x250);
}

inline NiBinaryStream& NiStream::Istr()
{
    return **reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}

inline unsigned int NiStream::version()
{
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0xd8);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
inline void NiNode::DecRefCount()
{
    if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
        DeleteThis();
}

template <> inline NiPointer<NiNode>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

template <> inline NiPointer<NiNode>::NiPointer() { m_pObject = 0; }

// src/gamebryo2.2/corelibs/niparticle/nimeshpsysdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nimeshpsysdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C"
{
    extern void* g_012027c0;
}

// @fnv 0x00c30a80
// src: COMMUNITY 0x00c30a80
void* __cdecl NiMeshPSysData_GetRTTI()
{
    return &g_012027c0;
}

void __cdecl operator delete(void* p, unsigned int size);

// Calls FUN_00c309d0, then deletes this with size 0x98 when bit 0 of flags is set, and returns this.
// @fnv 0x00c30bd0
void* __thiscall NiMeshPSysData::FUN_00c30bd0(unsigned int flags)
{
    FUN_00c309d0();
    if (flags & 1)
        operator delete(this, 0x98);
    return this;
}

// Removes meshes from the new active count up to the previous count.
// @fnv 0x00c308d0
// src: XBOX_PDB 0x00c308d0
void __thiscall NiMeshPSysData::SetActiveVertexCount_00c308d0(unsigned short usStartIndex)
{
    unsigned short us;
    for (us = usStartIndex; us < m_usActive; us++)
    {
        m_pMeshNode.m_pObject->RemoveNthObject(us);
    }
    if (usStartIndex <= m_usVertices)
        m_usActive = usStartIndex;
    else
        m_usActive = m_usVertices;
}

// Registers the particle data and its mesh node.
// @fnv 0x00c30940
// src: XBOX_PDB 0x00c30940
bool NiMeshPSysData::RegisterStreamables_00c30940(NiStream& kStream)
{
    if (!((NiPSysData*)this)->NiPSysData::RegisterStreamables(kStream))
        return false;
    m_pMeshNode.m_pObject->RegisterStreamables(kStream);
    return true;
}

// @fnv 0x00c30a90
// src: XBOX_PDB 0x00c30a90
void __thiscall NiMeshPSysData::ResolveAddedParticles_00c30a90()
{
    unsigned short us;
    NiAVObject* pkMesh;
    for (us = m_usNumParticles; us < m_usNumParticles + m_usNumActive; us++)
    {
        pkMesh = m_pMeshNode.m_pObject->m_kChildren.m_pBase[us].m_pObject;
        if (pkMesh)
            pkMesh->m_uFlags &= ~1;
    }
    NiPSysData::ResolveAddedParticles();
}

// @fnv 0x00c30c50
// src: XBOX_PDB 0x00c30c50
NiObject* __thiscall NiMeshPSysData::CreateClone_00c30c50(CloningProcess& kCloning)
{
    NiMeshPSysData* pkObject;
    void* pMemory = BSFadeNode::operator new(0x98);
    if (pMemory)
        pkObject = ((NiMeshPSysData*)pMemory)->FUN_00c30c00();
    else
        pkObject = 0;
    CloneTo(pkObject, kCloning);
    return (NiObject*)pkObject;
}

void __stdcall FUN_00c255b0(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
// @fnv 0x00c31210
// src: XBOX_PDB 0x00c31210
void __stdcall NiMeshPSysData_GetViewerStrings(StrArr* pkStrings)
{
    FUN_00c255b0(pkStrings);
    char* pszStr = _FUN_00a7d330((const char*)g_012027c0);
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiAlloc = pkStrings->m_usMaxSize;
    if (uiSize >= uiAlloc)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiSize, pszStr);
}

// @fnv 0x00c30920
// src: XBOX_PDB 0x00c30920
void NiMeshPSysData::ProcessClone_00c30920(CloningProcess& kCloning)
{
    NiObject::ProcessClone(kCloning);
    m_pMeshNode.m_pObject->ProcessClone(kCloning);
}

// @fnv 0x00c30ca0
NiMeshPSysData* __cdecl CreateNiMeshPSysData()
{
    void* object = BSFadeNode::operator new(0x98);
    if (object)
        return static_cast<NiMeshPSysData*>(object)->FUN_00c30c00();
    return 0;
}

struct Mesh308Compat
{
    virtual void __thiscall a00();
    virtual void __thiscall a01();
    virtual void __thiscall a02();
    virtual void __thiscall a03();
    virtual void __thiscall a04();
    virtual void __thiscall a05();
    virtual void __thiscall a06();
    virtual void __thiscall a07();
    virtual void __thiscall a08();
    virtual void __thiscall a09();
    virtual void __thiscall a10();
    virtual void __thiscall a11();
    virtual void __thiscall a12();
    virtual void __thiscall a13();
    virtual void __thiscall a14();
    virtual void __thiscall a15();
    virtual void __thiscall a16();
    virtual void __thiscall a17();
    virtual void __thiscall a18();
    virtual void __thiscall a19();
    virtual void __thiscall a20();
    virtual void __thiscall a21();
    virtual void __thiscall a22();
    virtual char __thiscall a23(NiObject*);
};

// @fnv 0x00c30970
// src: XBOX_PDB 0x00c30970
char __thiscall NiMeshPSysData::IsEqual_00c30970(NiMeshPSysData* other)
{
    if (!((NiPSysData*)this)->NiPSysData::IsEqual(other))
        return 0;
    Mesh308Compat* thisMesh = reinterpret_cast<Mesh308Compat*>(m_pMeshNode.m_pObject);
    NiObject* otherMesh = other->m_pMeshNode.m_pObject;
    return thisMesh->a23(otherMesh) != 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* plValue);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* plValue);

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}

inline void NiRefObject::DecRefCount()
{
    if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
        DeleteThis();
}

class C30AE0ObjectPtr
{
  public:
    C30AE0ObjectPtr& operator=(NiObject* pObject)
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

    NiObject* m_pObject;
};

// @fnv 0x00c30ae0
void NiMeshPSysData::CloneTo(NiMeshPSysData* pkDest, CloningProcess& kCloning)
{
    NiPSysData::CopyMemberData(pkDest, kCloning);
    reinterpret_cast<C30AE0ObjectPtr&>(pkDest->m_pMeshNode) = m_pMeshNode.m_pObject->MakeClone(kCloning);
    pkDest->m_bUseDefaultPools = m_bUseDefaultPools;
}

// @fnv 0x00c30b70
// src: XBOX_PDB 0x00c30b70
void __thiscall NiMeshPSysData::LinkObject_00c30b70(NiStream& kStream)
{
    NiPSysData::LinkObject(kStream);
    NiObject* pkNode = kStream.GetLoadedObject();
    NiObject* pkOld = m_pMeshNode.m_pObject;
    if (pkOld != pkNode)
    {
        if (pkOld && InterlockedDecrement((volatile long*)&pkOld->m_uiRefCount) == 0)
            pkOld->DeleteThis();
        m_pMeshNode.m_pObject = static_cast<NiNode*>(pkNode);
        if (pkNode)
            InterlockedIncrement((volatile long*)&pkNode->m_uiRefCount);
    }
}

// Saves the pool configuration and a link to the mesh node.
// @fnv 0x00c30cc0
void NiMeshPSysData::WriteToStream(NiStream& stream)
{
    NiPSysData::SaveBinary(stream);
    stream.GetBinaryStream()->Write(&m_uiDefaultPoolsSize, 4);
    {
        bool bActive = m_bUseDefaultPools;
        stream.GetBinaryStream()->Write(&bActive, 1);
    }
    {
        unsigned int size = m_kPoolArrays.m_usSize;
        stream.GetBinaryStream()->Write(&size, 4);
    }
    for (unsigned int i = 0; i < m_kPoolArrays.m_usSize; ++i)
    {
        if (m_kPoolArrays.m_pBase[i])
        {
            unsigned int id = m_kPoolArrays.m_pBase[i]->m_usMaxSize;
            stream.GetBinaryStream()->Write(&id, 4);
        }
        else
        {
            unsigned int zero = 0;
            stream.GetBinaryStream()->Write(&zero, 4);
        }
    }
    stream.SaveLinkID(reinterpret_cast<const NiObject*>(m_pMeshNode.m_pObject));
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);

// @fnv 0x00c30df0
void __thiscall NiMeshPSysData::ReleaseSlotRef(unsigned int uiIndex, NiRefObject* pRef)
{
    if (uiIndex >= m_kPoolArrays.m_usSize)
    {
        if (pRef != 0)
        {
            NiRefObject* ref = pRef;
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(&ref->m_uiRefCount)) == 0)
            {
                ref->DeleteThis();
            }
        }
        return;
    }
    if (m_kPoolArrays.m_pBase[uiIndex] != 0)
    {
        if (m_kPoolArrays.m_pBase[uiIndex]->m_usSize < m_kPoolArrays.m_pBase[uiIndex]->m_usMaxSize)
        {
            m_kPoolArrays.m_pBase[uiIndex]->Add(reinterpret_cast<const NiPointer<NiAVObject>&>(pRef));
        }
    }
    if (pRef != 0)
    {
        NiRefObject* ref = pRef;
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&ref->m_uiRefCount)) == 0)
        {
            ref->DeleteThis();
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
extern "C" void __cdecl _NiFreeC30(void* pvMem) throw();

// Deletes each pool before releasing the pool array and mesh node.
// @fnv 0x00c309d0
NiMeshPSysData::~NiMeshPSysData() throw()
{
    while (m_kPoolArrays.GetSize() > 0)
    {
        NiMeshPSysDataPool pkElement = m_kPoolArrays.RemoveEnd();
        delete pkElement;
    }
}

// Initializes the mesh node reference and pool array.
// @fnv 0x00c30c00
NiMeshPSysData::NiMeshPSysData() throw()
{}

inline void NiAVObject::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}

inline void NiAVObject::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}

// References are released explicitly because this code has no unwind tables.
class ParticleReference
{
public:
    ParticleReference(NiAVObject* object = 0) : m_pObject(object)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ParticleReference(const ParticleReference& other) : m_pObject(other.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    void Release()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    operator NiAVObject*() const { return m_pObject; }
    NiAVObject* m_pObject;
};
typedef ParticleReference NiAVObjectPtrSI;

struct NiParticleInfoSI
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned short m_usFirstValue;
    unsigned short unk1A;
};

// @fnv 0x00c30e80
// src: XBOX_PDB 0x00c30e80
void NiMeshPSysData::RemoveParticle(unsigned short usParticleIndex)
{
    unsigned short usLastParticle = m_usActive - 1;
    unsigned short usParticleGeneration = reinterpret_cast<NiParticleInfoSI*>(m_pkParticleInfo)[usParticleIndex].m_usFirstValue;

    NiPSysData::vf41(usParticleIndex);

    NiAVObjectPtrSI spParticle = 0;
    if (usParticleIndex == usLastParticle)
    {
        m_pMeshNode.m_pObject->RemoveNthObject2(usLastParticle, &spParticle.m_pObject);
    }
    else
    {
        NiAVObjectPtrSI spFinalParticle = 0;
        m_pMeshNode.m_pObject->RemoveNthObject2(usLastParticle, &spFinalParticle.m_pObject);
        m_pMeshNode.m_pObject->RemoveNthObject2(usParticleIndex, &spParticle.m_pObject);
        m_pMeshNode.m_pObject->ReplaceNthObject(usParticleIndex, spFinalParticle);
        spFinalParticle.Release();
    }

    // Both reference wrappers have the same one-pointer calling convention.
    // Use the explicit-release wrapper to avoid adding an unwind temporary.
    typedef void (NiMeshPSysData::*PoolTransfer)(unsigned int, ParticleReference);
    PoolTransfer transfer = reinterpret_cast<PoolTransfer>(
        static_cast<void (NiMeshPSysData::*)(unsigned int, NiPointer<NiAVObject>)>(
            &NiMeshPSysData::ReleaseSlotRef));
    (this->*transfer)(usParticleGeneration, spParticle);
    spParticle.Release();
}

// Resizes the generation pools, initializing new pools to the default capacity.
// @fnv 0x00c30f90
void NiMeshPSysData::ResizeChildren(unsigned count)
{
    unsigned previous = m_kPoolArrays.m_usSize;
    if (count < previous)
    {
        while (m_kPoolArrays.m_usSize > count)
            delete m_kPoolArrays.RemoveEnd();
    }
    else if (count > previous)
    {
        m_kPoolArrays.SetSize(count);
        for (unsigned i = previous; i < count; ++i)
        {
            NiMeshPSysDataPool result = new NiTObjectArray<NiPointer<NiAVObject> >;
            result->SetSize(m_uiDefaultPoolsSize);
            m_kPoolArrays.SetAt(i, result);
        }
    }
}

template <class T> inline unsigned int NiBinaryStreamLoad(NiBinaryStream& kStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return kStream.BinaryRead(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}
template <class T> inline void ReadBinaryValue(NiStream& kStream, T& val)
{
    NiBinaryStreamLoad(kStream.Istr(), &val, 1);
}

inline void AddPool(NiTObjectArray<NiMeshPSysDataPool>& kPools, unsigned int uiIndex,
    NiMeshPSysDataPool pkPool, unsigned int uiPoolSize)
{
    pkPool->SetSize(uiPoolSize);
    kPools.SetAt(uiIndex, pkPool);
}

// Loads base particle data, fills pools for older versions, and otherwise reads pool sizes and creates a pool for each nonzero size.
// @fnv 0x00c31090
// src: XBOX_PDB 0x00c31090
void NiMeshPSysData::LoadBinary_00c31090(NiStream& kStream)
{
    unsigned int uiPoolSize;
    unsigned int uiNumGenerations;

    NiPSysData::LoadBinary(kStream);

    if (kStream.version() <= 0x0a010000)
    {
        this->m_uiDefaultPoolsSize = m_usVertices;
        FillPools(true);
    }
    else
    {
        bool bFillPoolsOnLoad;
        ReadBinaryValue(kStream, this->m_uiDefaultPoolsSize);
        ReadBinaryValue(kStream, bFillPoolsOnLoad);
        this->m_bUseDefaultPools = (bFillPoolsOnLoad != 0);
        ReadBinaryValue(kStream, uiNumGenerations);
        m_kPoolArrays.SetSize(uiNumGenerations);
        for (unsigned int i = 0; i < uiNumGenerations; i++)
        {
            ReadBinaryValue(kStream, uiPoolSize);
            if (uiPoolSize > 0)
            {
                AddPool(m_kPoolArrays, i, new NiTObjectArray<NiPointer<NiAVObject> >(0, 1), uiPoolSize);
            }
        }
    }

    kStream.ReadLinkIDStub();
}

