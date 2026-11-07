#include "../../../../include/BSThreadCriticalSectionPC.h"
// gamebryo2.2/corelibs/nimain/nistream.cpp: NiStream, NiStreamImpl, ThisObj, Receiver and more (64 functions)
#include "../../../../include/MEM_CONTEXT.h"
#include "../../../../include/AutoMemContext.h"
#include "../../../../include/hkBool.h"
#include "../../../../include/hkReferencedObject.h"
#include "../../../../include/hkpContactListener.h"
#include "../../../../include/hkpEntityListener.h"
#include "../../../../include/hkpPhantomListener.h"
#include "../../../../include/hkpWorldDeletionListener.h"
#include "../../../../include/NiTMallocInterface.h"
#include "../../../../include/NiTPrimitiveArray.h"
class ImageSpaceTexture;
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/bhkCapsuleShape.h"
#include "../../../../include/MapEntryCount.h"
#include "../../../../include/NiMemStream.h"
#include "../../../../include/bhkAabbPhantom.h"
#include "../../../../include/bhkBoxShape.h"
#include "../../../../include/bhkConvexListShape.h"
#include "../../../../include/bhkConvexSweepShape.h"
#include "../../../../include/bhkConvexTransformShape.h"
#include "../../../../include/bhkConvexVerticesShape.h"
#include "../../../../include/bhkCylinderShape.h"
#include "../../../../include/bhkMoppBvTreeShape.h"
#include "../../../../include/bhkMouseSpringAction.h"
#include "../../../../include/bhkNiTriStripsShape.h"
#include "../../../../include/bhkPackedNiTriStripsShape.h"
#include "../../../../include/bhkSphereShape.h"
#include "../../../../include/bhkTriangleShape.h"
#include "../../../../include/hkMemorySystem.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiFile.h"
#include "../../../../include/hkMemoryRouter.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiObjectGroup.h"
#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiTMapBase.h"
#include "../../../../include/bhkBallAndSocketConstraint.h"
#include "../../../../include/bhkBallSocketConstraintChain.h"
#include "../../../../include/bhkBlendCollisionObject.h"
#include "../../../../include/bhkBreakableConstraint.h"
#include "../../../../include/bhkCollisionObject.h"
#include "../../../../include/bhkExtendedMeshShapeData.h"
#include "../../../../include/bhkHingeConstraint.h"
#include "../../../../include/bhkHingeLimitsConstraint.h"
#include "../../../../include/bhkLimitedHingeConstraint.h"
#include "../../../../include/bhkMalleableConstraint.h"
#include "../../../../include/bhkPrismaticConstraint.h"
#include "../../../../include/bhkRagdollConstraint.h"
#include "../../../../include/bhkRagdollLimitsConstraint.h"
#include "../../../../include/bhkRagdollTemplateData.h"
#include "../../../../include/bhkStiffSpringConstraint.h"
#include "../../../../include/bhkWheelConstraint.h"
#include "../../../../include/hkMemoryAllocator.h"
#include "../../../../include/hkPackedNiTriStripsData.h"
#include "../../../../include/bhkLiquidAction.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
#include "../../../../include/NiTNewInterface.h"
#include "../../../../include/NiTArray.h"
#include "../../../../include/NiTLargeArray.h"
#include "../../../../include/NiTLargePrimitiveArray.h"
#include "../../../../include/NiTLargeObjectArray.h"

// Shared pointer declarations keep this unit's reference-counting operations inline.
template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0) {}
template <class T> inline NiPointer<T>::NiPointer(T* pkNew) : m_pObject(pkNew)
{ if (m_pObject != 0) m_pObject->IncRefCount(); }
template <class T> inline NiPointer<T>::NiPointer(const NiPointer<T>& kSrc) : m_pObject(kSrc.m_pObject)
{ if (m_pObject != 0) m_pObject->IncRefCount(); }
template <class T> inline NiPointer<T>::~NiPointer()
{ if (m_pObject != 0) m_pObject->DecRefCount(); }
template <class T> inline NiPointer<T>::operator T*() const { return m_pObject; }
template <class T> inline T* NiPointer<T>::operator->() const { return m_pObject; }
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0) m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0) m_pObject->IncRefCount();
    }
    return *this;
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer<T>& kSrc)
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject != 0) m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject != 0) m_pObject->IncRefCount();
    }
    return *this;
}
template <class T> inline bool operator==(const NiPointer<T>& a, const NiPointer<T>& b)
{ return a.m_pObject == b.m_pObject; }
template <class T> inline bool operator!=(const NiPointer<T>& a, const NiPointer<T>& b)
{ return a.m_pObject != b.m_pObject; }

#include "../../../../include/NiTMapItem.h"

#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/NiTStringTemplateMap.h"
#include "../../../../include/NiTStringPointerMap.h"
#include "../../../../include/NiTSet.h"
#include "../../../../include/NiTPrimitiveSet.h"

#include "../../../../include/NiStream.h"
#include "../../../../include/bhkExtendedMeshShape.h"
#include "../../../../include/bhkFixedConstraint.h"
#include "../../../../include/bhkListShape.h"
#include "../../../../include/bhkMultiSphereShape.h"
#include "../../../../include/bhkPlaneShape.h"
#include "../../../../include/bhkRigidBody.h"
#include "../../../../include/bhkTransformShape.h"

// This unit owns the binary transfer implementations; the shared class exposes
// their signatures while its callback storage remains opaque.
static __forceinline unsigned int& StreamPosition(NiBinaryStream* stream)
{ return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(stream) + 4); }
static __forceinline NiBinaryStream::ReadFunction& StreamReadCallback(NiBinaryStream* stream)
{ return *reinterpret_cast<NiBinaryStream::ReadFunction*>(reinterpret_cast<char*>(stream) + 8); }
static __forceinline NiBinaryStream::WriteFunction& StreamWriteCallback(NiBinaryStream* stream)
{ return *reinterpret_cast<NiBinaryStream::WriteFunction*>(reinterpret_cast<char*>(stream) + 12); }
__forceinline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
{ unsigned int n = StreamReadCallback(this)(this, buffer, bytes, sizes, count); StreamPosition(this) += n; return n; }
__forceinline unsigned int NiBinaryStream::BinaryWrite(const void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
{ unsigned int n = StreamWriteCallback(this)(this, buffer, bytes, sizes, count); StreamPosition(this) += n; return n; }
template <class T> __forceinline unsigned int NiBinaryStream::BinaryRead(T* buffer, unsigned int count)
{ unsigned int size = sizeof(T); return BinaryRead(buffer, sizeof(T) * count, &size, 1); }
__forceinline unsigned int NiBinaryStream::Read(void* buffer, unsigned int bytes)
{ unsigned int size = bytes; return BinaryRead(buffer, bytes, &size, 1); }
__forceinline unsigned int NiBinaryStream::Read(void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
{ return BinaryRead(buffer, bytes, sizes, count); }
__forceinline unsigned int NiBinaryStream::Write(const void* buffer, unsigned int bytes)
{ unsigned int size = 1; return BinaryWrite(buffer, bytes, &size, 1); }
template <class T> static __forceinline unsigned int WriteStreamValues(NiBinaryStream* stream, const T* buffer, unsigned int count = 1)
{ unsigned int size = sizeof(T); return stream->BinaryWrite(buffer, sizeof(T) * count, &size, 1); }
inline void NiBinaryStream::ReadComp(void* buffer, unsigned int bytes, unsigned int componentSize)
{
    unsigned int size = componentSize;
    unsigned int n = StreamReadCallback(this)(this, buffer, bytes, &size, 1);
    StreamPosition(this) += n;
}
static __forceinline unsigned int ReadStreamCallbackAt12(NiBinaryStream& stream, void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
{ unsigned int n = (*reinterpret_cast<NiBinaryStream::ReadFunction*>(reinterpret_cast<char*>(&stream) + 12))(&stream, buffer, bytes, sizes, count); StreamPosition(&stream) += n; return n; }

inline NiFixedString& NiFixedString::operator=(const NiFixedString& other)
{
    if (m_kHandle != other.m_kHandle)
    {
        char* replacement = other.m_kHandle;
        NiGlobalStringTable::IncRefCount(replacement);
        NiGlobalStringTable::DecRefCount(m_kHandle);
        m_kHandle = replacement;
    }
    return *this;
}
inline NiFixedString& NiFixedString::operator=(const char* text)
{
    if (m_kHandle != text)
    {
        char* previous = m_kHandle;
        m_kHandle = NiGlobalStringTable::AddString(text);
        NiGlobalStringTable::DecRefCount(previous);
    }
    return *this;
}
inline bool NiFixedString::operator==(const NiFixedString& other) const { return m_kHandle == other.m_kHandle; }
inline bool NiFixedString::operator!=(const NiFixedString& other) const { return m_kHandle != other.m_kHandle; }

inline void NiRefObject::IncRefCount() { InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount)); }
inline void NiRefObject::DecRefCount() { if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount))) DeleteThis(); }

class NiTexture;
extern "C" bool __cdecl fnv_NiStreamGetTexture(const char* textureName, NiPointer<NiTexture>& texture);
extern "C" void __cdecl fnv_CopyFilePath(char* destination, unsigned int destinationSize, const char* source,
                                         unsigned int sourceSize);
extern "C" bool __cdecl fnv_StandardizeFilePath(char* path);
extern "C" char fnv_NiStreamCriticalSection;
extern "C" void(__stdcall* fnv_EnterCriticalSection)(void* section);
extern "C" void(__stdcall* fnv_LeaveCriticalSection)(void* section);

typedef NiTLargeObjectArray<NiPointer<NiObject> > NiStreamTopObjects;
typedef NiTLargeObjectArray<NiFixedString> NiStreamFixedStrings;
// These original out-of-line instantiations must remain out of line in this unit.
template <> void NiTLargeArray<NiPointer<NiObject>, NiTNewInterface<NiPointer<NiObject> > >::SetAt(unsigned int, const NiPointer<NiObject>&) throw();
template <> void NiTLargeArray<NiPointer<NiObject>, NiTNewInterface<NiPointer<NiObject> > >::SetSize(unsigned int);

// DAT_011f4788 is NiStream's post-process list, a NiTPrimitiveArray<void(*)(NiStream&,NiObject*)> (RTTI vftable
// 0x0109bd88, built by 0x00A660A0); 0x00A64330 is its AddFirstEmpty (returns -1 for a null function).
typedef void(__cdecl* NiStreamPostProcess)(NiStream&, NiObject*);
typedef NiTPrimitiveArray<NiStreamPostProcess> NiStreamPostProcessArray;
extern NiStreamPostProcessArray* DAT_011f4788;
class NiShader;
extern NiTStringTemplateMap<NiTPointerMap<const char*, NiShader*>, NiShader*>* DAT_011f4784;
extern bool DAT_011f4780;

inline void NiStreamReadUInt(NiBinaryStream* stream, unsigned int& value)
{
    unsigned int componentSize = sizeof(value);
    StreamPosition(stream) += StreamReadCallback(stream)(stream, &value, sizeof(value), &componentSize, 1);
}

inline void NiStreamWriteUInt(NiBinaryStream* stream, unsigned int& value)
{
    unsigned int componentSize = sizeof(value);
    StreamPosition(stream) += StreamWriteCallback(stream)(stream, &value, sizeof(value), &componentSize, 1);
}

// @fnv 0x00A634E0
NiObjectGroup* NiStream::GetObjectGroup(unsigned int groupID)
{
    return m_kGroups.m_pBase[groupID];
}

// @fnv 0x00A63430
__declspec(noinline) NiObject* NiStream::GetLoadedObject()
{
    unsigned int linkIndex = m_uiLinkIndex;
    m_uiLinkIndex = linkIndex + 1;
    unsigned int linkID = m_kLinkIDs.m_pBase[linkIndex];
    if (linkID == 0xFFFFFFFF)
        return 0;
    return m_kObjects.m_pBase[linkID].m_pObject;
}

// @fnv 0x00A64700
void NiStream::SetLinkIDCount(unsigned int numberOfLinkIDs)
{
    NiTPrimitiveSet<unsigned int>& linkIDBlocks = (NiTPrimitiveSet<unsigned int>&)m_kLinkIDBlocks;
    if (linkIDBlocks.m_uiUsed == linkIDBlocks.m_uiAlloced)
    {
        unsigned int allocationCount = linkIDBlocks.m_uiAlloced;
        if (allocationCount > 0)
            allocationCount *= 2;
        else
            allocationCount = 1;
        linkIDBlocks.Realloc(allocationCount);
    }
    static_cast<unsigned int*>(linkIDBlocks.m_pBase)[linkIDBlocks.m_uiUsed] = numberOfLinkIDs;
    ++linkIDBlocks.m_uiUsed;
}

// @fnv 0x00A635B0
void NiStream::RegisterObjects()
{
    for (unsigned int index = 0; index < m_kTopObjects.m_uiSize; ++index)
    {
        NiObject* object = (NiObject*)m_kTopObjects.m_pBase[index].m_pObject;
        object->RegisterStreamables(*this);
    }
}

// @fnv 0x00A63380
bool NiStream::Save(NiBinaryStream* stream)
{
    m_pkOstr = stream;
    bool result = SaveStream();
    m_pkOstr = 0;
    return result;
}

// @fnv 0x00A633D0
void NiStream::GetTexture(const char* textureName, NiPointer<NiTexture>& texture)
{
    fnv_NiStreamGetTexture(textureName, texture);
}

// @fnv 0x00A636F0
void NiStream::SetStreamPath(const char* path)
{
    if (path != 0 && path[0] != '\0')
    {
        char* destination = m_acStreamPath;
        fnv_CopyFilePath(destination, 0x104, path, 0x103);
        fnv_StandardizeFilePath(destination);
    }
    else
    {
        m_acStreamPath[0] = '\0';
    }
}

// @fnv 0x00A63330
bool NiStream::Load(NiBinaryStream* stream)
{
    typedef bool(__thiscall * StreamReadyFunction)(NiBinaryStream*);
    if (!((StreamReadyFunction*)(*reinterpret_cast<void***>(stream)))[1](stream))
    {
        m_pkIstr = 0;
        return false;
    }
    m_pkIstr = stream;
    bool result = LoadStream();
    m_pkIstr = 0;
    return result;
}

// @fnv 0x00A644F0
void NiStream::ClearTopLevelObjects()
{
    fnv_EnterCriticalSection(&fnv_NiStreamCriticalSection);
    ((NiStreamTopObjects&)m_kTopObjects).RemoveAll();
    ((NiStreamFixedStrings&)m_kFixedStrings).RemoveAll();
    for (unsigned int index = 0; index < m_kObjectSizes.m_uiSize; ++index)
        m_kObjectSizes.m_pBase[index] = 0;
    m_kObjectSizes.m_uiSize = 0;
    m_kObjectSizes.m_uiESize = 0;
    fnv_LeaveCriticalSection(&fnv_NiStreamCriticalSection);
}

// @fnv 0x00A64920
void NiStream::RegisterPostProcess(NiStreamPostProcess function)
{
    DAT_011f4788->AddFirstEmpty(function);
}

// @fnv 0x00A64900
// Physics bootstrap calls the original out-of-line registration function.
__declspec(noinline) int NiStream::RegisterObjectLoader(const char* name, NiObject*(__cdecl* loader)())
{
    DAT_011f4784->SetAt(name, (NiShader*)loader);
    return 0;
}

// @fnv 0x00A636B0
bool NiStream::GetLastLoadedFilePath(char* buffer, unsigned int size)
{
    if (DAT_011f4780)
    {
        fnv_CopyFilePath(buffer, 0x104, m_acStreamPath, 0x103);
        DAT_011f4780 = false;
        return true;
    }
    return false;
}

// @fnv 0x00A632F0
bool NiStream::Load(char* buffer, int size)
{
    // The explicit initialization and teardown below own the stream lifetime.
    unsigned int streamStorage[sizeof(NiMemStream) / sizeof(unsigned int)];
    NiMemStream& stream = *reinterpret_cast<NiMemStream*>(streamStorage);
    stream.FUN_00aa2fb0(buffer, size);
    bool result = Load(reinterpret_cast<NiBinaryStream*>(&stream));
    stream.NiMemStreamDestructor();
    return result;
}

// @fnv 0x00A635E0
bool NiStream::Save(char*& buffer, int& size)
{
    // The explicit initialization and teardown below own the stream lifetime.
    unsigned int streamStorage[sizeof(NiMemStream) / sizeof(unsigned int)];
    NiMemStream& stream = *reinterpret_cast<NiMemStream*>(streamStorage);
    stream.NiMemStream_NiMemStream();
    bool result = Save(reinterpret_cast<NiBinaryStream*>(&stream));
    size = stream.m_uiLogicalSize;
    buffer = stream.NiMemStream_Str();
    stream.NiMemStreamDestructor();
    return result;
}

// @fnv 0x00A64620
NiObject* NiStream::DeserializeObject()
{
    unsigned int linkID;
    NiStreamReadUInt(m_pkIstr, linkID);
    if (linkID == 0xFFFFFFFF)
        return 0;
    return m_kObjects.m_pBase[linkID].m_pObject;
}

// @fnv 0x00A64550
void NiStream::ChangeObject(NiObject* object)
{
    NiObject* pointer = object;
    if (object)
        object->IncRefCount();
    ((NiStreamTopObjects&)m_kObjects)
        .SetAt(m_uiLoad, reinterpret_cast<const NiPointer<NiObject>&>(pointer));
    if (object)
        object->DecRefCount();
}

// @fnv 0x00A63D80
void NiStream::SaveTopLevelObjects()
{
    unsigned int count = m_kTopObjects.m_uiSize;
    NiStreamWriteUInt(m_pkOstr, count);
    for (unsigned int index = 0; index < count; ++index)
        SaveLinkID(m_kTopObjects.m_pBase[index].m_pObject);
}

// @fnv 0x00A66370
void NiStream::InsertObject(NiObject* object)
{
    NiObject* pointer = object;
    if (object)
        object->IncRefCount();
    NiStreamTopObjects& objects = (NiStreamTopObjects&)m_kTopObjects;
    unsigned int index = objects.m_uiSize;
    if (index >= objects.m_uiMaxSize)
        objects.SetSize(index + objects.m_uiGrowBy);
    objects.SetAt(index, reinterpret_cast<const NiPointer<NiObject>&>(pointer));
    if (object)
        object->DecRefCount();
}

extern __declspec(thread) unsigned int t_uiMemContextC68;

// The scoped Havok context at 0x00c68230 saves and restores TLS 0x012722b4.
inline AutoMemContext::AutoMemContext(int context)
{
    m_eMemoryContext = static_cast<MEM_CONTEXT>(t_uiMemContextC68);
    t_uiMemContextC68 = context;
}
inline AutoMemContext::~AutoMemContext()
{
    t_uiMemContextC68 = m_eMemoryContext;
}

// RTTI at vftable 0x010c3af8 names bhkMemoryAllocator (4 bytes); allocation/free slots are 0x00c66170/0x00c661a0.
class bhkMemoryAllocator : public hkMemoryAllocator
{
  public:
    bhkMemoryAllocator()
    {}
    virtual ~bhkMemoryAllocator();
    virtual void* blockAlloc(int);
    virtual void blockFree(void*, int);
    virtual void getMemoryStatistics(MemoryStatistics&);
    virtual int getAllocatedSize(const void*, int);
};

hkMemoryRouter* __cdecl GetMemoryRouterC68();

// No include/ header yet: constructor 0x00cd0a60, setAllocator 0x00cd06c0.
class hkFreeListMemorySystem : public hkMemorySystem
{
  public:
    void* operator new(unsigned int, void* pvWhere)
    {
        return pvWhere;
    }
    void operator delete(void*, void*)
    {}
    hkFreeListMemorySystem();
    void setAllocator(hkMemoryAllocator* pkAllocator);
};

typedef void(__cdecl* hkErrorReportFunctionC68)(const char* pcMessage, void* pvObject);
class hkBaseSystemC68
{
  public:
    static hkBool isInitialized()
    {
        return s_bInitialized;
    }
    static int __cdecl init(hkMemoryRouter* pkRouter, hkErrorReportFunctionC68 pfnErrorReport,
                            void* pvErrorReportObject);
    static bool s_bInitialized;
};
void __cdecl HavokErrorReportC68(const char* pcMessage, void* pvObject);

inline void* hkReferencedObject::operator new(std::size_t uiBytes)
{
    hkReferencedObject* b =
        static_cast<hkReferencedObject*>(GetMemoryRouterC68()->heap().blockAlloc(uiBytes));
    b->m_usMemSizeAndFlags = static_cast<unsigned short>(uiBytes);
    return b;
}
inline void hkReferencedObject::operator delete(void* p)
{
    hkReferencedObject* b = static_cast<hkReferencedObject*>(p);
    GetMemoryRouterC68()->heap().blockFree(p, b->m_usMemSizeAndFlags);
}

class bhkWorldListenerBaseC68 : public hkReferencedObject,
                                public hkpContactListener,
                                public hkpEntityListener,
                                public hkpPhantomListener,
                                public hkpWorldDeletionListener
{
  public:
    bhkWorldListenerBaseC68();
    virtual void WorldDeletedCallback(hkpWorld* world);
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
};

class bhkWorldListenerC68 : public bhkWorldListenerBaseC68
{
  public:
    bhkWorldListenerC68()
    {}
};

extern MemoryManager g_kMemoryManagerC68;

class bhkSingletonC68
{
  public:
    void* operator new(unsigned int uiSize)
    {
        return g_kMemoryManagerC68.Allocate(uiSize);
    }
    void operator delete(void* pvMem)
    {
        g_kMemoryManagerC68.Deallocate(pvMem);
    }
    bhkSingletonC68();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};

class bhkAngularDashpotAction
{
  public:
    static NiObject* __cdecl CreateObject();
};
class bhkDashpotAction
{
  public:
    static NiObject* __cdecl CreateObject();
};
class bhkMotorAction
{
  public:
    static NiObject* __cdecl CreateObject();
};
class bhkOrientHingedBodyAction
{
  public:
    static NiObject* __cdecl CreateObject();
};
class bhkSpringAction
{
  public:
    static NiObject* __cdecl CreateObject();
};
class bhkPCollisionObject
{
  public:
    static NiObject* __cdecl CreateObject();
};
class bhkSPCollisionObject
{
  public:
    static NiObject* __cdecl CreateObject();
};

class bhkBlendController
{
  public:
    static NiObject* __cdecl CreateObject();
};
class bhkRigidBodyT
{
  public:
    static NiObject* __cdecl CreateObject();
};
class bhkSimpleShapePhantom
{
  public:
    static NiObject* __cdecl CreateObject();
};
class bhkCachingShapePhantom
{
  public:
    static NiObject* __cdecl CreateObject();
};
class bhkExtraData
{
  public:
    static NiObject* __cdecl CreateObject();
};
class bhkRagdollTemplate
{
  public:
    static NiObject* __cdecl CreateObject();
};

class bhkPoseArray
{
  public:
    static NiObject* __cdecl CreateObject();
};

void __cdecl InitializeSelectionMasks();

extern hkMemorySystem* g_pkMemorySystemC68;
extern bhkWorldListenerC68* g_pkWorldListenerC68;
extern bhkSingletonC68* g_pkSingletonC68;
extern char g_acMemorySystemBufferC68[];
inline hkMemorySystem& GetMemorySystemC68()
{
    return *g_pkMemorySystemC68;
}
extern char g_acStackBufferC68[0x60000];

// Initializes the Havok physics system, sets up memory router and stack, registers Havok object loaders, and creates the world listener and singleton.
// @fnv 0x00c68230
void InitHavokPhysics()
{
    AutoMemContext kContext(0x10);
    bool bNeedsInit = !hkBaseSystemC68::isInitialized();
    if (bNeedsInit)
    {
        static bhkMemoryAllocator s_kMallocAllocator;

        hkMemorySystem::FrameInfo kInfo;
        kInfo.m_iSolverBufferSize = 0;
        hkFreeListMemorySystem* pkMemorySystem = new (g_acMemorySystemBufferC68) hkFreeListMemorySystem;
        pkMemorySystem->setAllocator(&s_kMallocAllocator);
        g_pkMemorySystemC68 = pkMemorySystem;
        hkMemorySystem::ReplaceInstance(pkMemorySystem);

        hkMemoryRouter* pkRouter = GetMemorySystemC68().CreateMemoryRouter(kInfo, hkMemorySystem::Flags(1));
        pkRouter->m_temp = pkRouter->m_heap;
        *reinterpret_cast<hkMemoryAllocator**>(reinterpret_cast<char*>(pkRouter) + 0x18) = pkRouter->m_heap;

        char* pcStack = g_acStackBufferC68;
        int iStackSize = sizeof(g_acStackBufferC68);
        int iMisalign = (int)pcStack & 0xf;
        if (iMisalign)
        {
            int iActionIndex = 0x10 - iMisalign;
            pcStack += iActionIndex;
            iStackSize -= iActionIndex;
        }
        pkRouter->m_stack.m_start.m_storage = (void*)(reinterpret_cast<int>(pcStack));
        pkRouter->m_stack.m_next.m_storage = (void*)(reinterpret_cast<int>(pcStack));
        pkRouter->m_stack.m_end.m_storage = (void*)(reinterpret_cast<int>(pcStack + iStackSize));
        hkBaseSystemC68::init(pkRouter, HavokErrorReportC68, 0);

        InitializeSelectionMasks();
        g_pkWorldListenerC68 = new bhkWorldListenerC68;

        NiStream::RegisterObjectLoader("bhkBoxShape", bhkBoxShape::CreateObject);
        NiStream::RegisterObjectLoader("bhkConvexListShape", bhkConvexListShape::CreateObject);
        NiStream::RegisterObjectLoader("bhkConvexSweepShape", bhkConvexSweepShape::CreateObject);
        NiStream::RegisterObjectLoader("bhkConvexTransformShape", bhkConvexTransformShape::CreateObject);
        NiStream::RegisterObjectLoader("bhkConvexVerticesShape", bhkConvexVerticesShape::CreateObject);
        NiStream::RegisterObjectLoader("bhkCylinderShape", bhkCylinderShape::CreateObject);
        NiStream::RegisterObjectLoader("bhkExtendedMeshShapeData", bhkExtendedMeshShapeData::CreateObject);
        NiStream::RegisterObjectLoader("bhkExtendedMeshShape", bhkExtendedMeshShape::CreateObject);
        NiStream::RegisterObjectLoader("bhkMultiSphereShape", bhkMultiSphereShape::CreateObject);
        NiStream::RegisterObjectLoader("bhkpMeshShape", bhkNiTriStripsShape::CreateObject);
        NiStream::RegisterObjectLoader("bhkNiTriStripsShape", bhkNiTriStripsShape::CreateObject);
        NiStream::RegisterObjectLoader("bhkPackedNiTriStripsShape", bhkPackedNiTriStripsShape::CreateObject);
        NiStream::RegisterObjectLoader("hkPackedNiTriStripsData", hkPackedNiTriStripsData::CreateObject);
        NiStream::RegisterObjectLoader("bhkPlaneShape", bhkPlaneShape::CreateObject);
        NiStream::RegisterObjectLoader("bhkSphereShape", bhkSphereShape::CreateObject);
        NiStream::RegisterObjectLoader("bhkTriangleShape", bhkTriangleShape::CreateObject);
        NiStream::RegisterObjectLoader("bhkMoppBvTreeShape", bhkMoppBvTreeShape::CreateObject);
        NiStream::RegisterObjectLoader("bhkTransformShape", bhkTransformShape::CreateObject);
        NiStream::RegisterObjectLoader("bhkCapsuleShape", bhkCapsuleShape::CreateObject);
        NiStream::RegisterObjectLoader("bhkListShape", bhkListShape::CreateObject);
        NiStream::RegisterObjectLoader("bhkBallAndSocketConstraint", bhkBallAndSocketConstraint::CreateObject);
        NiStream::RegisterObjectLoader("bhkBallSocketConstraintChain", bhkBallSocketConstraintChain::CreateObject);
        NiStream::RegisterObjectLoader("bhkHingeConstraint", bhkHingeConstraint::CreateObject);
        NiStream::RegisterObjectLoader("bhkHingeLimitsConstraint", bhkHingeLimitsConstraint::CreateObject);
        NiStream::RegisterObjectLoader("bhkFixedConstraint", bhkFixedConstraint::CreateObject);
        NiStream::RegisterObjectLoader("bhkLimitedHingeConstraint", bhkLimitedHingeConstraint::CreateObject);
        NiStream::RegisterObjectLoader("bhkPrismaticConstraint", bhkPrismaticConstraint::CreateObject);
        NiStream::RegisterObjectLoader("bhkRagdollConstraint", bhkRagdollConstraint::CreateObject);
        NiStream::RegisterObjectLoader("bhkRagdollLimitsConstraint", bhkRagdollLimitsConstraint::CreateObject);
        NiStream::RegisterObjectLoader("bhkStiffSpringConstraint", bhkStiffSpringConstraint::CreateObject);
        NiStream::RegisterObjectLoader("bhkWheelConstraint", bhkWheelConstraint::CreateObject);
        NiStream::RegisterObjectLoader("bhkBreakableConstraint", bhkBreakableConstraint::CreateObject);
        NiStream::RegisterObjectLoader("bhkMalleableConstraint", bhkMalleableConstraint::CreateObject);
        NiStream::RegisterObjectLoader("bhkAngularDashpotAction", bhkAngularDashpotAction::CreateObject);
        NiStream::RegisterObjectLoader("bhkDashpotAction", bhkDashpotAction::CreateObject);
        NiStream::RegisterObjectLoader("bhkLiquidAction", bhkLiquidAction::CreateObject);
        NiStream::RegisterObjectLoader("bhkMouseSpringAction", bhkMouseSpringAction::CreateObject);
        NiStream::RegisterObjectLoader("bhkMotorAction", bhkMotorAction::CreateObject);
        NiStream::RegisterObjectLoader("bhkOrientHingedBodyAction", bhkOrientHingedBodyAction::CreateObject);
        NiStream::RegisterObjectLoader("bhkSpringAction", bhkSpringAction::CreateObject);
        NiStream::RegisterObjectLoader("bhkAabbPhantom", bhkAabbPhantom::CreateObject);
        NiStream::RegisterObjectLoader("bhkCollisionObject", bhkCollisionObject::CreateObject);
        NiStream::RegisterObjectLoader("bhkPCollisionObject", bhkPCollisionObject::CreateObject);
        NiStream::RegisterObjectLoader("bhkSPCollisionObject", bhkSPCollisionObject::CreateObject);
        NiStream::RegisterObjectLoader("bhkBlendCollisionObject", bhkBlendCollisionObject::CreateObject);
        NiStream::RegisterObjectLoader("bhkBlendController", bhkBlendController::CreateObject);
        NiStream::RegisterObjectLoader("bhkRigidBody", bhkRigidBody::CreateObject);
        NiStream::RegisterObjectLoader("bhkRigidBodyT", bhkRigidBodyT::CreateObject);
        NiStream::RegisterObjectLoader("bhkSimpleShapePhantom", bhkSimpleShapePhantom::CreateObject);
        NiStream::RegisterObjectLoader("bhkCachingShapePhantom", bhkCachingShapePhantom::CreateObject);
        NiStream::RegisterObjectLoader("bhkExtraData", bhkExtraData::CreateObject);
        NiStream::RegisterObjectLoader("bhkRagdollTemplate", bhkRagdollTemplate::CreateObject);
        NiStream::RegisterObjectLoader("bhkRagdollTemplateData", bhkRagdollTemplateData::CreateObject);
        NiStream::RegisterObjectLoader("bhkPoseArray", bhkPoseArray::CreateObject);

        if (!g_pkSingletonC68)
            g_pkSingletonC68 = new bhkSingletonC68;
    }
}

extern int(__stdcall* DAT_00fdf1c4)(void*);
extern char* EmptyFS;
extern char* DAT_011f3ec0;
extern char* DAT_011f3ec4;

// @fnv 0x00a42230
void __cdecl ClearGlobalStrings()
{
    char* old = DAT_011f3ec0;
    int(__stdcall * pfn)(void*) = DAT_00fdf1c4;
    if (old)
    {
        DAT_011f3ec0 = NiGlobalStringTable::AddString(0);
        if (old != EmptyFS)
            pfn((void*)(old - 8));
    }
    old = DAT_011f3ec4;
    if (old)
    {
        DAT_011f3ec4 = NiGlobalStringTable::AddString(0);
        if (old != EmptyFS)
            pfn((void*)(old - 8));
    }
}

struct S_00a48070_Obj
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    char m_acInputFilePath[0x104];
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    unsigned int m_uiNativeThreadId;
    char m_acSecondPathBuffer[0x104];
    char m_acLastPath[0x104];
    void FUN_00a66150();
    void Object_ReleaseStorage_00a65300();
    bool OpenFile(const char* p);
};

void FUN_00a47f40(S_00a48070_Obj* obj, int a, NiObject** b, void* c);
// Initializes obj, releases and clears p3 when OpenFile returns false, otherwise calls FUN_00a47f40, then finalizes obj.
// @fnv 0x00a48070
void CreateOrReleaseRef(const char* apPath, int p2, NiObject** ppRef, void* p4)
{
    S_00a48070_Obj obj;
    obj.FUN_00a66150();
    if (!obj.OpenFile(apPath))
    {
        NiObject* pOldRef = *ppRef;
        if (pOldRef)
        {
            if (InterlockedDecrement((long*)&pOldRef->m_uiRefCount) == 0)
                pOldRef->DeleteThis();
            *ppRef = 0;
        }
    }
    else
    {
        FUN_00a47f40(&obj, p2, ppRef, p4);
    }
    obj.Object_ReleaseStorage_00a65300();
}

void __fastcall _Call_a5d3a0(void*);
extern int DAT_010984ec;
struct Obj
{
    void* vtable;
    int f04;
    int f08;
    int f0C;
    int f10;
    unsigned char f14;
};
// @fnv 0x00a48110
// src: EXE 0x00a48110
void* NiRotData_CreateObject()
{
    Obj* p = (Obj*)BSFadeNode::operator new(0x18);
    if (p)
    {
        _Call_a5d3a0(p);
        p->f08 = 0;
        p->f0C = 0;
        p->f10 = 0;
        p->f14 = 0;
        p->vtable = &DAT_010984ec;
        return p;
    }
    return 0;
}

void __cdecl FUN_00a61c50(NiObject* pkObject, void* pvArg);

// @fnv 0x00a633b0
// src: COMMUNITY 0x00a633b0
void __stdcall NiTexture_SetTexture(const NiObject* pkObject)
{
    FUN_00a61c50((NiObject*)pkObject, 0);
}

namespace fnv_00a633f0 {
extern int EmptyFS;

}  // namespace fnv_00a633f0

// @fnv 0x00a633f0
int NiStream::FindIndex(int* pVal)
{
    int v = *pVal;
    if (v == fnv_00a633f0::EmptyFS)
        return -1;

    int i = 0;
    if (m_kFixedStrings.m_uiSize > 0)
    {
        int* p = (int*)m_kFixedStrings.m_pBase;
        while (i < m_kFixedStrings.m_uiSize)
        {
            if (v == *p)
                return i;
            ++p;
            ++i;
        }
    }
    return -1;
}

// @fnv 0x00a63460
__declspec(noinline) unsigned int NiStream::GetLinkID()
{
    unsigned int idx = (*(unsigned int*)((char*)this + 0x270))++;
    return (*(unsigned int**)((char*)this + 0x264))[idx];
}

struct ShaderBufferRecord;
struct FUN_00a63480_holder
{
    char pad[0x274];
    NiTStringPointerMap<ShaderBufferRecord*> map;
};

// @fnv 0x00a63480
// src: XBOX_PDB 0x00a63480
unsigned int __fastcall NiStream_GetLinkIDFromObject(FUN_00a63480_holder* self, int, const char* name)
{
    if (!name)
        return 0xffffffff;
    unsigned int id = 0xffffffff;
    self->map.GetAt(name, (ShaderBufferRecord*&)id);
    return id;
}

namespace fnv_00a634b0 {
struct ShaderBufferRecord;
typedef void(__cdecl* NamedFunction)();
extern NiTStringPointerMap<NamedFunction>* DAT_011f4784;
// Looks up a function pointer in DAT_011f4784 by name and calls it, returning the result or 0 if not found.
// @fnv 0x00a634b0
void* InvokeNamedFunction(const char* name)
{
    void*(__cdecl * fn)();
    if (!DAT_011f4784->GetAt(name, (void(__cdecl*&)())fn))
        return 0;
    return fn();
}
}  // namespace fnv_00a634b0

// Searches the array at pThis+0xcc for val and returns its index, or 0 if not found.
// @fnv 0x00a634f0
// src: COMMUNITY 0x00a634f0
unsigned int __fastcall NiStream_GetIDFromGroup(char* pThis, int, int aiValue)
{
    unsigned int count = *(unsigned short*)(pThis + 0xd2);
    for (unsigned int i = 0; i < count; ++i)
    {
        if (aiValue == ((int*)*(void**)(pThis + 0xcc))[i])
            return i;
    }
    return 0;
}

namespace fnv_00a63520 {
extern void* DAT_011f4784;

// @fnv 0x00a63520
// src: COMMUNITY 0x00a63520
void __cdecl NiStream_UnregisterLoader(const char* apKey)
{
    NiTPointerMap<const char*, NiObject*(__cdecl*)()>* map =
        reinterpret_cast<NiTPointerMap<const char*, NiObject*(__cdecl*)()>*>(DAT_011f4784);
    map->RemoveAt(apKey);
}
}  // namespace fnv_00a63520

template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::GetSize() const
{
    return m_usSize;
}
template <class T, class TAlloc> inline T NiTArray<T, TAlloc>::RemoveAt(unsigned int uiIndex)
{
    if (uiIndex >= m_usSize)
        return T(0);
    T element = m_pBase[uiIndex];
    m_pBase[uiIndex] = T(0);
    if (element != T(0))
        m_usESize--;
    if (uiIndex == (unsigned short)(m_usSize - 1))
        m_usSize--;
    return element;
}
template <class T, class TAlloc> inline T& NiTArray<T, TAlloc>::GetAt(unsigned int uiIndex)
{
    return m_pBase[uiIndex];
}
namespace fnv_00a63540 {
typedef void (*S_00a63540_PostProcess)(void*);
extern NiTPrimitiveArray<S_00a63540_PostProcess>* DAT_011f4788;
// Removes the given post-process callback from the global post-process array by finding and removing the matching entry.
// @fnv 0x00a63540
void RemovePostProcess(S_00a63540_PostProcess apPostProcess)
{
    for (unsigned int ui = 0; ui < DAT_011f4788->GetSize(); ui++)
    {
        if (DAT_011f4788->GetAt(ui) == apPostProcess)
        {
            DAT_011f4788->RemoveAt(ui);
            break;
        }
    }
}
}  // namespace fnv_00a63540

extern "C" int __cdecl strcpy_s(char* destination, unsigned int size, const char* source);
extern "C" char* __cdecl strtok_s(char* text, const char* delimiters, char** context);
extern long __cdecl FUN_00eca6d3(const char* text);

// Copies text into a 16-byte buffer, splits it on '.' with strtok_s, and packs each token's FUN_00eca6d3 value into a 32-bit integer.
// @fnv 0x00a63630
// src: XBOX_PDB 0x00a63630
unsigned int __cdecl NiStream_GetVersionFromString(const char* text)
{
    char buffer[16];
    char* context;

    strcpy_s(buffer, 16, text);
    int shift = 24;
    unsigned int value = 0;
    char* token = strtok_s(buffer, ".", &context);
    while (token)
    {
        value |= (unsigned int)(FUN_00eca6d3(token) << shift);
        shift -= 8;
        token = strtok_s(0, ".", &context);
    }
    return value;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

template <> void NiTLargeArray<NiFixedString, NiTNewInterface<NiFixedString> >::SetSize(unsigned int) throw();

// Stores element at uiIndex in m_pBase, growing m_uiSize if needed and adjusting m_uiESize when the slot's emptiness changes.
// @fnv 0x00a63730
template <> __declspec(noinline) void NiTLargeArray<NiFixedString, NiTNewInterface<NiFixedString> >::SetAt(unsigned int uiIndex, const NiFixedString& element) throw()
{
    if (uiIndex >= m_uiSize)
    {
        m_uiSize = uiIndex + 1;
        if (element != NiFixedString())
            m_uiESize++;
    }
    else
    {
        if (element != NiFixedString())
        {
            if (m_pBase[uiIndex] == NiFixedString())
                m_uiESize++;
        }
        else
        {
            if (m_pBase[uiIndex] != NiFixedString())
                m_uiESize--;
        }
    }
    m_pBase[uiIndex] = element;
}

void NiFree(void* p);



struct S_00a63910_MapBase
{
    unsigned int m_uiHashSize;
    NiTMapItem<char*, void*>** m_ppkHashTable;
    unsigned int m_uiCount;

    virtual ~S_00a63910_MapBase() throw()
    {
        RemoveAll();
        NiFree(m_ppkHashTable);
    }
    void RemoveAll();
};

struct S_00a63910_Map : S_00a63910_MapBase
{
    virtual ~S_00a63910_Map() throw()
    {
        RemoveAll();
    }
};

struct FUN_00a63910 : S_00a63910_Map
{
    bool m_bCopy;

    virtual ~FUN_00a63910() throw();
};

// Frees the m_key strings of all hash table items when m_bCopy is set, then defers to the base class destructor.
// @fnv 0x00a63910
FUN_00a63910::~FUN_00a63910() throw()
{
    if (m_bCopy)
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            NiTMapItem<char*, void*>* pkItem = m_ppkHashTable[i];
            while (pkItem)
            {
                NiTMapItem<char*, void*>* pkSave = pkItem;
                pkItem = pkItem->m_pkNext;
                NiFree(pkSave->m_key);
            }
        }
    }
}

#include <string.h>

void NiPath_Standardize(char* path);

// Copies name into m_acInputFilePath, calls FUN_00aa2a00, attempts to get a file, and calls LoadFile if it is good.
// @fnv 0x00a63be0
bool NiStream::Load(const char* apFilePath)
{
    strcpy_s(m_acFileName, 0x104, apFilePath);
    NiPath_Standardize(m_acFileName);
    if (m_acFileName && m_acFileName[0])
    {
        strncpy_s(m_acStreamPath, 0x104, m_acFileName, 0x103);
        NiPath_Standardize(m_acStreamPath);
    }
    else
    {
        m_acStreamPath[0] = 0;
    }
    NiFile* f = NiFile::GetFile(m_acFileName, 0, 0x8000);
    if (f && static_cast<bool>(*f))
    {
        bool b = Load(static_cast<NiBinaryStream*>(f));
        delete f;
        return b;
    }
    delete f;
    m_uiNativeThreadId = 1;
    strcpy_s(m_acLastErrorMessage, 0x104, "Cannot open file.");
    return false;
}

struct Holder
{
    char _0[0xA0];
    void** m_pBase;
    unsigned short m_usExtra;
    unsigned short m_usElementCount;
};
struct Arg
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Holder* f3();
    char _4[0x2C];
    unsigned int m_flags;
};
struct ThisObj
{
    void SetFlagsRecursively(Arg* p);
};
// Clears bit 0x10, sets mask 0xE in m_flags, then recurses on each non-null element in the f3() holder.
// @fnv 0x00a63cb0
void ThisObj::SetFlagsRecursively(Arg* apArg)
{
    apArg->m_flags = (apArg->m_flags & ~0x10) | 0xE;
    Holder* h = apArg->f3();
    if (h)
    {
        for (unsigned int i = 0; i < h->m_usElementCount; ++i)
        {
            Arg* child = (Arg*)h->m_pBase[i];
            if (child)
                SetFlagsRecursively(child);
        }
    }
}

struct Link
{
    int unk00;
    Link* unk04;
};
class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f4280;
struct Item
{
    virtual void* First();
    virtual void* Second();
    virtual Link* Query();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};
struct Receiver
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
    unsigned int unk0d8;
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
    Item** unk1f0;
    int unk1f4;
    unsigned int count;
    void SetFlagsRecursively(Item* item);
    void __thiscall NiStream_SetSelectiveUpdateFlagsForOldVersions();
};
// Iterates the Item array and calls SetFlagsRecursively on items whose Query() chain reaches g_011f4280 and whose unk18 is zero.
// @fnv 0x00a63d10
// src: XBOX_PDB 0x00a63d10
void __thiscall Receiver::NiStream_SetSelectiveUpdateFlagsForOldVersions()
{
    if (unk0d8 >= 0x401000cU)
        return;
    unsigned int index = 0;
    if (count <= 0)
        return;
    do
    {
        Item* item = unk1f0[index];
        if (item)
        {
            Link* value = item->Query();
            if (value)
            {
                do
                {
                    if (value == (Link*)&g_011f4280)
                    {
                        if (item->unk18 == 0)
                            SetFlagsRecursively(item);
                        break;
                    }
                    value = value->unk04;
                } while (value);
            }
        }
        ++index;
    } while (index < count);
}

namespace sa63df0 {

template <class T> inline void NiBinaryStreamLoad(NiBinaryStream& kStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    ReadStreamCallbackAt12(kStream, pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

template <class T> inline void StreamLoadBinary(NiBinaryStream& kStream, T& kValue)
{
    NiBinaryStreamLoad(kStream, &kValue, 1);
}


// Reads m_kObjects.m_uiSize binary values from m_pkOstr and returns the stream position captured before the reads.
}  // namespace sa63df0
// @fnv 0x00a63df0
unsigned int NiStream::PreSaveObjectSizeTable()
{
    int iPosition = m_pkOstr->GetPosition();
    int iSkipped = 0;
    for (unsigned int i = 0; i < m_kObjects.m_uiSize; i++)
        sa63df0::StreamLoadBinary(*m_pkOstr, iSkipped);
    return iPosition;
}


template <class T> inline void NiStreamSaveBinaryA63E(NiBinaryStream& binstream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    binstream.BinaryWrite(&value, uiSize, &uiSize, 1);
}

// Seeks back to uiStartPos and writes the object-size table.
// @fnv 0x00a63e60
bool NiStream::SaveObjectSizeTable(unsigned int uiStartPos)
{
    unsigned int uiDelta = m_pkOstr->GetPosition() - uiStartPos;
    m_pkOstr->Seek(-(int)uiDelta);
    for (unsigned int i = 0; i < m_kObjectSizes.m_uiSize; i++)
    {
        unsigned int uiLinkID = m_kObjectSizes.m_pBase[i];
        NiStreamSaveBinaryA63E(*m_pkOstr, uiLinkID);
    }
    return true;
}

namespace fnv_00a63ee0 {

typedef char _sizecheck_NiFixedString[sizeof(NiFixedString) == 4 ? 1 : -1];
// NiStream.h does not declare the fixed-string table writer at 0x00a63ee0.
struct FUN_00a63ee0_shell : public NiStream
{
    void NiStream_SaveFixedStringTable();
};

extern char* _EmptyFS;

template <class T> inline void SaveBinary_a63ee0(NiBinaryStream& kStream, const T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&kValue, sizeof(T), &uiSize, 1);
}

inline unsigned int GetSize_a63ee0(const char* self)
{
    return *(const unsigned int*)(self + 0x240);
}

// Writes the string array size, max length, and each string's length and data to the binary stream at offset 0x250.
// @fnv 0x00a63ee0
// src: XBOX_PDB 0x00a63ee0
void FUN_00a63ee0_shell::NiStream_SaveFixedStringTable()
{
    char* self = (char*)this;
    SaveBinary_a63ee0(**(NiBinaryStream**)(self + 0x250), GetSize_a63ee0(self));

    unsigned int stMaxLength = 0;
    for (unsigned short us = 0; us < *(unsigned int*)(self + 0x240); us++)
    {
        char* kString = (*(char***)(self + 0x238))[us];
        if (kString != _EmptyFS)
        {
            unsigned int stLength = ((unsigned int*)kString)[-1];
            if (stLength > stMaxLength)
                stMaxLength = stLength;
        }
    }
    unsigned int uiMaxLength = stMaxLength;
    SaveBinary_a63ee0(**(NiBinaryStream**)(self + 0x250), uiMaxLength);

    for (unsigned short us = 0; us < *(unsigned int*)(self + 0x240); us++)
    {
        char*& kString = (*(char***)(self + 0x238))[us];
        unsigned int stLength = (kString == _EmptyFS) ? 0 : ((unsigned int*)kString)[-1];
        unsigned int uiLength = stLength;
        const char* pcString = kString;
        SaveBinary_a63ee0(**(NiBinaryStream**)(self + 0x250), uiLength);
        (*(NiBinaryStream**)(self + 0x250))->Write(pcString, uiLength);
    }
}
}  // namespace fnv_00a63ee0

namespace fnv_00a640b0 {
int strcpy_s(char* dest, unsigned int size, const char* src);
void _fnv_CopyFilePath(char* dest, unsigned int destSize, const char* src, unsigned int count);
void _fnv_StandardizeFilePath(char* path);


}  // namespace fnv_00a640b0
// Copies and standardizes the input file path, opens it read-only via NiFile::GetFile, and delegates to Load if the file is valid.
// @fnv 0x00a640b0
bool NiStream::Save(const char* name)
{
    fnv_00a640b0::strcpy_s(m_acFileName, 0x104, name);
    fnv_00a640b0::_fnv_StandardizeFilePath(m_acFileName);
    if (m_acFileName && m_acFileName[0])
    {
        fnv_00a640b0::_fnv_CopyFilePath(m_acStreamPath, 0x104, m_acFileName, 0x103);
        fnv_00a640b0::_fnv_StandardizeFilePath(m_acStreamPath);
    }
    else
    {
        m_acStreamPath[0] = 0;
    }
    NiFile* file = NiFile::GetFile(m_acFileName, static_cast<NiFile::OpenMode>(1), 0x8000);
    if (file)
    {
        if (*file)
        {
            bool result = Save(static_cast<NiBinaryStream*>(file));
            delete file;
            return result;
        }
        delete file;
    }
    return false;
}

struct NiStreamW
{
    int unk00;
    unsigned int m_04;
    int unk08;
    void* m_0C;
};

typedef unsigned int(__cdecl* StreamWriteFn)(NiStreamW* s, const void* buf, unsigned int size, unsigned int* pCount,
                                             unsigned int flag);


static __forceinline void S_Save(NiStreamW* o, const void* v, unsigned int n, unsigned int elem)
{
    unsigned int sz = elem;
    o->m_04 += ((StreamWriteFn)o->m_0C)(o, v, n, &sz, 1);
}

// Writes the length of str and, if non-zero, the string bytes to m_250 via S_Save.
// @fnv 0x00a64160
// src: XBOX_PDB 0x00a64160
void NiStream::SaveCString(const char* apString)
{
    unsigned int len;
    if (apString != 0)
        len = (unsigned int)strlen(apString);
    else
        len = 0;
    S_Save(reinterpret_cast<NiStreamW*>(m_pkOstr), &len, 4, 4);
    if (len > 0)
        S_Save(reinterpret_cast<NiStreamW*>(m_pkOstr), apString, len, 1);
}

typedef unsigned int(__cdecl* StreamWriteFn)(NiStreamW* s, const void* buf, unsigned int size, unsigned int* pCount,
                                             unsigned int flag);

extern unsigned int DAT_0109bc30;

// NiStream.h does not declare the fixed-string ID writer at 0x00a641f0.
struct FUN_00a641f0_cls
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
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    NiStreamW* m_250;
    unsigned int GetObjectLinkId(void* p);
    void WriteObjectLink(void* a1);
};

// Writes four bytes: DAT_0109bc30 if the argument's first pointer matches NiGlobalStringTable::ms_pcEmptyString, otherwise its object link ID.
// @fnv 0x00a641f0
void FUN_00a641f0_cls::WriteObjectLink(void* apObject)
{
    unsigned int id;
    if (*(void**)apObject == NiGlobalStringTable::ms_pcEmptyString)
    {
        NiStreamW* s = m_250;
        StreamWriteFn fn = (StreamWriteFn)s->m_0C;
        *(unsigned int*)&apObject = 4;
        s->m_04 += fn(s, &DAT_0109bc30, 4, (unsigned int*)&apObject, 1);
    }
    else
    {
        id = GetObjectLinkId(apObject);
        NiStreamW* s = m_250;
        StreamWriteFn fn = (StreamWriteFn)s->m_0C;
        *(unsigned int*)&apObject = 4;
        s->m_04 += fn(s, &id, 4, (unsigned int*)&apObject, 1);
    }
}

struct NiStreamLoader
{
    unsigned int unk00;
    unsigned int m_uiPos;
    typedef unsigned int(__cdecl* ReadProcRef)(NiStreamLoader*, unsigned char*, unsigned int, const unsigned int&,
                                               unsigned int);
    ReadProcRef m_pfnRead;
};


// Reads a 4-byte value from m_pStreamLoader, grows m_ppData if full, and appends the value to m_ppData.
// @fnv 0x00a645b0
// src: XBOX_PDB 0x00a645b0
void NiStream::ReadLinkID()
{
    unsigned int value;
    NiStreamLoader* loader = reinterpret_cast<NiStreamLoader*>(m_pkIstr);
    loader->m_uiPos += ((NiStreamLoader::ReadProcRef)(loader->m_pfnRead))(loader, (unsigned char*)&value, 4u, 4u, 1u);
    unsigned int uiCapacity = m_kLinkIDs.m_uiAlloced;
    NiTPrimitiveSet<unsigned int>* arr = reinterpret_cast<NiTPrimitiveSet<unsigned int>*>(&m_kLinkIDs);
    if (arr->m_uiUsed == uiCapacity)
    {
        arr->Realloc(uiCapacity > 0 ? uiCapacity * 2 : 1);
    }
    arr->m_pBase[arr->m_uiUsed] = value;
    arr->m_uiUsed++;
}

struct S_00a64670_Ctx;

typedef int(__cdecl* S_00a64670_Callback)(S_00a64670_Ctx*, int*, int, int*, int);

struct S_00a64670_Ctx
{
    int unk00;
    int unk04;
    S_00a64670_Callback unk08;
};

struct S_00a64670_Array
{
    unsigned int* data;
    unsigned int capacity;
    unsigned int count;

    void NiTSet_NiScreenGeometryData_ScreenElement_NiTMallocInterface_NiScreenGeometryData_ScreenElement_Add(unsigned int);
};

struct S_00a64670_B0
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
};

struct S_00a64670_B1
{
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
};

struct S_00a64670_B2
{
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
};

struct S_00a64670_B3
{
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
};

struct S_00a64670_B4
{
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
};

struct S_00a64670_B5
{
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
};

struct S_00a64670_B6
{
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
};

struct S_00a64670_B7
{
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
};

struct S_00a64670_B8
{
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
};

struct S_00a64670_Base : S_00a64670_B0,
                         S_00a64670_B1,
                         S_00a64670_B2,
                         S_00a64670_B3,
                         S_00a64670_B4,
                         S_00a64670_B5,
                         S_00a64670_B6,
                         S_00a64670_B7,
                         S_00a64670_B8
{
    int unk240;
    int unk244;
    int unk248;
};

struct S_00a64670_Foo : S_00a64670_Base
{
    S_00a64670_Ctx* unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    S_00a64670_Array unk264;

    void ReadLinkID();
    void NiStream_ReadMultipleLinkIDs();
};

inline void ReadStreamCount(S_00a64670_Ctx* ctx, int* output, int size)
{
    ctx->unk04 += ctx->unk08(ctx, output, size, &size, 1);
}
// Reads a count, appends it to the array, then calls FUN_00a645b0 once per count.
// @fnv 0x00a64670
// src: XBOX_PDB 0x00a64670
void S_00a64670_Foo::NiStream_ReadMultipleLinkIDs()
{
    unsigned int count;
    S_00a64670_Ctx* ctx = unk24c;
    ReadStreamCount(ctx, (int*)&count, 4);
    S_00a64670_Array& array = unk264;
    if (array.count == array.capacity)
        array.NiTSet_NiScreenGeometryData_ScreenElement_NiTMallocInterface_NiScreenGeometryData_ScreenElement_Add(array.capacity > 0 ? array.capacity * 2 : 1);
    array.data[array.count] = count;
    ++array.count;
    unsigned int limit = *(volatile unsigned int*)&count;
    unsigned int i = 0;
    if (limit > 0)
        do
        {
            ReadLinkID();
            limit = *(volatile unsigned int*)&count;
            ++i;
        } while (i < limit);
}

// Reads one 4-byte object size for each loaded object.
// @fnv 0x00a64740
bool NiStream::LoadObjectSizeTable()
{
    NiTLargePrimitiveArray<unsigned int>& links = (NiTLargePrimitiveArray<unsigned int>&)m_kObjectSizes;
    links.SetSize(m_kObjects.m_uiSize);
    for (unsigned int index = 0; index < m_kObjects.m_uiSize; ++index)
    {
        unsigned int value = 0;
        m_pkIstr->Read(&value, 4);
        links.SetAt(index, value);
    }
    return true;
}

// The shared class omits the sized constructor; call its original thiscall entry.
extern "C" void fnv_NiObjectGroupConstruct();
namespace fnv_00a647f0 {

template <class T> inline unsigned int QLoadB(NiBinaryStream& binstream, T& value)
{
    unsigned int uiComponentSize = sizeof(T);
    return binstream.BinaryRead(&value, sizeof(T), &uiComponentSize, 1);
}
}  // namespace fnv_00a647f0
template <> inline void NiTArray<NiObjectGroup*, NiTMallocInterface<NiObjectGroup*> >::SetAt(unsigned int uiIndex, NiObjectGroup* const& element)
{
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element)
            m_usESize++;
    }
    else
    {
        if (element)
        {
            if (m_pBase[uiIndex] == 0)
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex] != 0)
                m_usESize--;
        }
    }
    m_pBase[uiIndex] = element;
}
namespace fnv_00a647f0 {
// Reads the group count from the stream, resizes the group array, and allocates NiObjectGroup instances for each group.
// @fnv 0x00a647f0
}  // namespace fnv_00a647f0
void NiStream::LoadGroups()
{
    unsigned int uiNumGroups;
    fnv_00a647f0::QLoadB(**(NiBinaryStream**)((char*)this + 0x24c), uiNumGroups);
    uiNumGroups++;
    ((NiTPrimitiveArray<ImageSpaceTexture*>*)((char*)this + 0xc8))->SetSize(uiNumGroups);
    {
        int iNull = 0;
        ((NiTPrimitiveArray<int>*)((char*)this + 0xc8))->SetAt(0, iNull);
    }
    for (unsigned int uiRenderPassIndex = 1; uiRenderPassIndex < uiNumGroups; uiRenderPassIndex++)
    {
        unsigned int uiSize;
        fnv_00a647f0::QLoadB(**(NiBinaryStream**)((char*)this + 0x24c), uiSize);
        void* pvMem = BSFadeNode::operator new(sizeof(NiObjectGroup));
        NiObjectGroup* pkGroup = pvMem ? reinterpret_cast<NiObjectGroup* (__thiscall*)(NiObjectGroup*, unsigned int)>(&fnv_NiObjectGroupConstruct)(static_cast<NiObjectGroup*>(pvMem), uiSize) : 0;
        ((NiTPrimitiveArray<NiObjectGroup*>*)((char*)this + 0xc8))->SetAt(uiRenderPassIndex, pkGroup);
    }
}

extern "C" unsigned int __cdecl strlen(const char* pcStr);

extern unsigned int g_uiNifMaxVersion_011a9b0c;
extern unsigned int g_uiNifMaxUserVersion_011a9b10;

// Writes the NIF header (version, endianness, object count, and optional creator/export info) to the backing stream.
// @fnv 0x00a64940
void NiStream::SaveHeader()
{
    m_pkOstr->SetEndianSwap(false);
    m_pkOstr->Write(static_cast<const void*>("Gamebryo File Format, Version 20.2.0.7\n"));
    WriteStreamValues(m_pkOstr, &g_uiNifMaxVersion_011a9b0c);
    WriteStreamValues(m_pkOstr, &m_bSaveLittleEndian);
    WriteStreamValues(m_pkOstr, &g_uiNifMaxUserVersion_011a9b10);
    {
        unsigned int uiObjects = m_kObjects.m_uiSize;
        WriteStreamValues(m_pkOstr, &uiObjects);
    }
    if (g_uiNifMaxUserVersion_011a9b10)
    {
        WriteStreamValues(m_pkOstr, &m_kHeader.m_uiVersion);
        unsigned char ucLength = (unsigned char)(strlen(m_kHeader.m_acAuthor) + 1);
        WriteStreamValues(m_pkOstr, &ucLength);
        WriteStreamValues(m_pkOstr, m_kHeader.m_acAuthor, ucLength);
        ucLength = (unsigned char)(strlen(m_kHeader.m_acProcessScript) + 1);
        WriteStreamValues(m_pkOstr, &ucLength);
        WriteStreamValues(m_pkOstr, m_kHeader.m_acProcessScript, ucLength);
        ucLength = (unsigned char)(strlen(m_kHeader.m_acExportScript) + 1);
        WriteStreamValues(m_pkOstr, &ucLength);
        WriteStreamValues(m_pkOstr, m_kHeader.m_acExportScript, ucLength);
    }
    m_pkOstr->SetEndianSwap(m_bSaveLittleEndian ^ true);
}

namespace fnv_00a64b80 {
// 0x00a64b80 reads and writes a dword at +0 of each swap-list texture; the shared ImageSpaceTexture keeps three bools there
class SwapTextureView_00a64b80
{
  public:
    unsigned int m_uiValueBeforeCount;
};

}  // namespace fnv_00a64b80
// Gamebryo NiTArray.inl bodies this unit's original inlines (SetAt stays out of line)

template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    unsigned int uiIndex = m_usSize;
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Find(const T& element) const
{
    for (unsigned int i = 0; i < m_usSize; i++)
    {
        if (m_pBase[i] == element)
            return i;
    }
    return 0;
}
template <class T, class TAlloc> __declspec(noinline) void NiTArray<T, TAlloc>::SetAt(unsigned int pos, const T& value)
{
    if (pos >= m_usSize)
    {
        m_usSize = (unsigned short)(pos + 1);
        if (value)
            ++m_usESize;
    }
    else if (value)
    {
        if (!m_pBase[pos])
            ++m_usESize;
    }
    else
    {
        if (m_pBase[pos])
            --m_usESize;
    }
    m_pBase[pos] = value;
}
namespace fnv_00a64b80 {

class ImageSpaceShaderParam
{
  public:
    virtual void Vf00();
    virtual void Vf04();
    virtual void Vf08();
    virtual void Vf0c();
    virtual void Vf10();
    virtual void Vf14();
    virtual void Vf18();
    virtual void Vf1c();
    virtual void Vf20();
    virtual void Vf24();
    virtual void Vf28();
    virtual void Vf2c();
    virtual void Vf30();
    virtual void Vf34();
    virtual void Vf38();
    virtual void Vf3c();
    virtual void Vf40();
    virtual void Vf44();
    virtual void Vf48();
    virtual void Vf4c();
    virtual void Vf50();
    virtual void Vf54();
    virtual void Vf58();
    virtual void Vf5c();
    virtual void Vf60();
    virtual void Vf64();
    virtual void Vf68();
    virtual void Vf6c();
    virtual void Vf70();
    virtual void Vf74();
    virtual void Vf78();
    virtual unsigned int GetCount();
    virtual SwapTextureView_00a64b80* GetTexture();
};

class ImageSpaceShaderW
{
  public:
    void UpdateTextureSwapList();
    unsigned int FindTexture(SwapTextureView_00a64b80* pkTexture) const
    {
        for (unsigned int k = 0; k < m_kTextureSwapList.m_usSize; k++)
        {
            if (pkTexture == m_kTextureSwapList.m_pBase[k])
                return k;
        }
        return 0;
    }

    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
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
    NiTArray<SwapTextureView_00a64b80*, NiTMallocInterface<SwapTextureView_00a64b80*> > m_kTextureSwapList;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    ImageSpaceShaderParam** m_ppParams;
    unsigned int m_uiParamMax;
    unsigned int m_uiParamCount;
};

// Rebuilds m_kTextureSwapList from shader params and accumulates GetCount into each texture's m_uiValueBeforeCount.
// @fnv 0x00a64b80
void ImageSpaceShaderW::UpdateTextureSwapList()
{
    m_kTextureSwapList.SetSize(1);
    m_kTextureSwapList.SetAt(0, 0);

    for (unsigned int i = 0; i < m_uiParamCount; i++)
    {
        ImageSpaceShaderParam* pkParam = m_ppParams[i];
        if (pkParam)
        {
            SwapTextureView_00a64b80* pkTexture = pkParam->GetTexture();
            if (pkTexture)
            {
                if (FindTexture(pkTexture) != 0)
                    continue;
                m_kTextureSwapList.Add(pkTexture);
                pkTexture->m_uiValueBeforeCount = 0;
            }
        }
    }

    for (unsigned int j = 0; j < m_uiParamCount; j++)
    {
        ImageSpaceShaderParam* pkParam = m_ppParams[j];
        if (pkParam)
        {
            SwapTextureView_00a64b80* pkTexture = pkParam->GetTexture();
            if (pkTexture)
            {
                unsigned int uiElapsedMilliseconds = pkTexture->m_uiValueBeforeCount;
                pkTexture->m_uiValueBeforeCount = uiElapsedMilliseconds + pkParam->GetCount();
            }
        }
    }
}
}  // namespace fnv_00a64b80

extern int _fnv_NiStreamCriticalSection;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

// Locks the critical section, removes all top objects, zeroes four fields, and unlocks the section.
// @fnv 0x00a64ca0
void NiStream::ResetStreamState()
{
    EnterCriticalSection(&_fnv_NiStreamCriticalSection);
    reinterpret_cast<NiStreamTopObjects*>(&m_kObjects)->RemoveAll();
    m_kLinkIDs.m_uiUsed = 0;
    m_kLinkIDBlocks.m_uiUsed = 0;
    m_uiLinkIndex = 0;
    m_uiLinkBlockIndex = 0;
    LeaveCriticalSection(&_fnv_NiStreamCriticalSection);
}


void* __cdecl _NiMalloc(size_t);

// Reads a length-prefixed null-terminated string from the stream into pcString, allocating memory when the length is positive.
// @fnv 0x00a64ce0
void NiStream::ReadCString(char*& pcString)
{
    int iStringLength;
    m_pkIstr->ReadComp(&iStringLength, 4, 4);
    if (iStringLength > 0)
    {
        pcString = (char*)_NiMalloc(iStringLength + 1);
        m_pkIstr->ReadComp(pcString, iStringLength, 1);
        (pcString)[iStringLength] = 0;
    }
    else
    {
        pcString = 0;
    }
}

// ---------------------------------------------------------------------------
// FUN_00a64d80 - read a length-prefixed block out of a NiStream.
//
// The function is a member of the game's stream object; the low level buffer
// it works on sits at +0x24c.  The buffer keeps its read cursor at +0x04 and
// the low level read routine at +0x08.  The read routine takes
// (buffer, destination, byte count, &size, flags); "size" selects the kind of
// value that is read (4 = a four byte value, 1 = a raw block) and is handed
// back to the caller.
//
// The two reads are made through the same buffer pointer, which is reloaded
// from the stream object before the second read.
// ---------------------------------------------------------------------------

// @fnv 0x00a64d80
// src: XBOX_PDB 0x00a64d80
__declspec(noinline) void NiStream::LoadRTTIString(unsigned int param)
{
    unsigned int count;
    NiBinaryStream* s = m_pkIstr;
    {
        // the kind of the value that is read; it dies right after the read
        unsigned int size = 4;
        StreamPosition(s) += StreamReadCallback(s)(s, &count, 4, &size, 1);
    }
    s = m_pkIstr;
    {
        // the raw block that follows the length
        unsigned int size = 1;
        StreamPosition(s) += StreamReadCallback(s)(s, reinterpret_cast<void*>(param), count, &size, 1);
    }
    reinterpret_cast<unsigned char*>(count)[param] = 0;
}

typedef char*(__cdecl* StrMakeFn)(char* p);
typedef int(__cdecl* StreamReadFn)(NiBinaryStream* self, void* dst, unsigned int size, unsigned int* count, int flag);

static __forceinline unsigned int BinaryRead(NiBinaryStream* s, void* pvBuffer, unsigned int uiTotalBytes,
                                             unsigned int* puiComponentSizes, unsigned int uiNumComponents = 1)
{
    unsigned int res = StreamReadCallback(s)(s, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    StreamPosition(s) += res;
    return res;
}

static __forceinline void ReadStream(NiBinaryStream* s, unsigned int& val)
{
    unsigned int comp = sizeof(unsigned int);
    BinaryRead(s, &val, sizeof(unsigned int), &comp, 1);
}

static __forceinline void ReadStream(NiBinaryStream* s, char* buf, unsigned int bytes)
{
    unsigned int comp = 1;
    BinaryRead(s, buf, bytes, &comp, 1);
}

char* __cdecl FUN_00a5b690(char* p);
char* __cdecl _NiMalloc_00aa1070(unsigned int size);
void __cdecl _NiFree_00aa10f0(char* p);
__declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);

// NiStream.h lacks the char** string-table reader used at 0x00a64ea0.
class Cls_a64ea0
{
  public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    unsigned int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    unsigned int unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC;
    unsigned int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    unsigned int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C;
    unsigned int unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C;
    unsigned int unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    unsigned int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C;
    unsigned int unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC;
    unsigned int unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    unsigned int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC;
    unsigned int unk200, unk204, unk208, unk20C, unk210, unk214, unk218, unk21C;
    unsigned int unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    unsigned int unk240, unk244, unk248;
    NiBinaryStream* m_stream;
    void NiStream_LoadCStringAsFixedString(char** target);
};

// Reads a length-prefixed string into *target, using allocated storage for lengths >= 0x400 and a stack buffer for positive smaller lengths.
// @fnv 0x00a64ea0
// src: XBOX_PDB 0x00a64ea0
void Cls_a64ea0::NiStream_LoadCStringAsFixedString(char** apString)
{
    unsigned int len;
    char buf[0x400];
    ReadStream(m_stream, len);
    if ((int)len >= 0x400)
    {
        char* tmp = _NiMalloc_00aa1070(len + 1);
        ReadStream(m_stream, tmp, len);
        tmp[len] = 0;
        char* old = *apString;
        if (old != tmp)
        {
            *apString = FUN_00a5b690(tmp);
            if (old != NiGlobalStringTable::ms_pcEmptyString)
                InterlockedDecrement((long volatile*)(old - 8));
        }
        _NiFree_00aa10f0(tmp);
    }
    else if ((int)len > 0)
    {
        ReadStream(m_stream, buf, len);
        buf[len] = 0;
        char* old = *apString;
        if (old != buf)
        {
            *apString = FUN_00a5b690(buf);
            if (old != NiGlobalStringTable::ms_pcEmptyString)
                InterlockedDecrement((long volatile*)(old - 8));
        }
    }
    else
    {
        char* old = *apString;
        if (old != 0)
        {
            *apString = FUN_00a5b690(0);
            if (old != NiGlobalStringTable::ms_pcEmptyString)
                InterlockedDecrement((long volatile*)(old - 8));
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

void* __cdecl NiTObjectArray_NiPointer_NiScreenTexture_NiTObjectArray_NiPointer_NiScreenTexture(unsigned int);
void __cdecl FUN_00a47600(void*);

// Resizes the large array to uiMaxSize, copying existing elements, zeroing new slots, and freeing the old buffer.
// @fnv 0x00a64fe0
template <> void NiTLargeArray<NiPointer<NiObject>, NiTNewInterface<NiPointer<NiObject> > >::SetSize(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_uiMaxSize)
    {
        return;
    }

    unsigned int i;
    if (uiMaxSize < m_uiSize)
    {
        for (i = uiMaxSize; i < m_uiSize; i++)
        {
            if (m_pBase[i] != NiPointer<NiObject>(0))
            {
                m_pBase[i] = 0;
                m_uiESize--;
            }
        }
        m_uiSize = uiMaxSize;
    }

    NiPointer<NiObject>* pSaveBase = m_pBase;
    m_uiMaxSize = uiMaxSize;
    if (m_uiMaxSize > 0)
    {
        m_pBase = (NiPointer<NiObject>*)NiTObjectArray_NiPointer_NiScreenTexture_NiTObjectArray_NiPointer_NiScreenTexture(m_uiMaxSize);
        for (i = 0; i < m_uiSize; i++)
        {
            m_pBase[i] = pSaveBase[i];
        }
        for (i = m_uiSize; i < m_uiMaxSize; i++)
        {
            m_pBase[i] = 0;
        }
    }
    else
    {
        m_pBase = 0;
    }
    FUN_00a47600(pSaveBase);
}

extern int DAT_0109bdcc, DAT_0109bd54, DAT_0109bc64, DAT_0109bd4c, DAT_0109bd98, DAT_01081fc8, DAT_0109bc3c;
void __cdecl FUN_00a47600(void*);
void _NiFreeAlias(void*);
void Object_ProcessEntries_00a644a0(void*);
struct VObj
{
    virtual void* Del(int);
};
typedef NiTPointerMap<const NiObject*, unsigned int> NiStreamRegisterMap;

struct Bk
{
    void* vt;
};
struct FUN_00a65300_holder
{
    void* vt;
    char p0[0xc4];
    void* vt_c8;
    void* c_cc;
    char p1[0x11c];
    void* vt_1ec;
    void* a1f0;
    char p2[0x10];
    void* vt_204;
    void* a208;
    char p3[0x10];
    void* vt_21c;
    void* a220;
    char p4[0x10];
    void* vt_234;
    void* a238;
    char p5[0x10];
    VObj* istr;
    VObj* ostr;
    void* l254;
    char p6[0x0c];
    void* l264;
    char p7[0x0c];
    NiStreamRegisterMap map;
    char p8[0x20];
    VObj* bg;
    void ClearTopLevelObjects();
};
// Calls Del(1) on three members, clears top-level objects and the map, and passes stored pointers to cleanup routines.
// @fnv 0x00a65300
// src: GUESS 0x00a65300 (confidence: low)
void __fastcall Object_ReleaseStorage_00a65300(FUN_00a65300_holder* s)
{
    s->vt = &DAT_0109bdcc;
    if (s->istr)
        s->istr->Del(1);
    if (s->ostr)
        s->ostr->Del(1);
    s->ClearTopLevelObjects();
    if (s->bg)
        s->bg->Del(1);
    NiStreamRegisterMap* m = &s->map;
    *reinterpret_cast<void**>(m) = &DAT_0109bd54;
    m->RemoveAll();
    *reinterpret_cast<void**>(m) = &DAT_0109bc64;
    m->RemoveAll();
    _NiFreeAlias(m->m_ppkHashTable);
    _NiFreeAlias(s->l264);
    _NiFreeAlias(s->l254);
    s->vt_234 = &DAT_0109bd4c;
    Object_ProcessEntries_00a644a0(s->a238);
    s->vt_21c = &DAT_0109bd98;
    FUN_00a47600(s->a220);
    s->vt_204 = &DAT_01081fc8;
    _NiFreeAlias(s->a208);
    s->vt_1ec = &DAT_0109bd98;
    FUN_00a47600(s->a1f0);
    s->vt_c8 = &DAT_0109bc3c;
    _NiFreeAlias(s->c_cc);
}

namespace fnv_00a65400 {
extern "C" char* __cdecl strstr(const char* pStr, const char* pSub);
extern "C" int __cdecl strcpy_s(char* pDest, unsigned int uiSize, const char* pSrc);
int __cdecl FUN_00404d80(char* pDest, unsigned int uiSize, const char* pSrc);

bool __cdecl NiBinaryStream_GetEndianMatchHint();
extern unsigned int g_uiNifMinVersion_011a9b08;
extern unsigned int g_uiNifMaxVersion_011a9b0c;
extern unsigned int g_uiNifMinUserVersion_011f478c;
extern unsigned int g_uiNifMaxUserVersion_011a9b10;

void __cdecl NiStreamLoadBinary_char_00a643b0(NiStream& kStream, unsigned char& ucValue);
void __cdecl NiStreamLoadBinary_float(NiStream& kStream, unsigned int& uiValue);
void __cdecl NiStreamLoadBinary_char(NiStream& kStream, char* pcString, unsigned int uiLength);


// Reads and validates the NIF file header from m_pUnderlyingStream, storing version, endian, and object count, returning false on any validation failure.
// @fnv 0x00a65400
}  // namespace fnv_00a65400
bool NiStream::LoadHeader()
{
    char acBuffer[0x80];
    m_pkIstr->GetLine(acBuffer, 0x80);
    if (!fnv_00a65400::strstr(acBuffer, "File Format"))
    {
        m_uiNativeThreadId = 2;
        fnv_00a65400::strcpy_s(m_acLastErrorMessage, 0x104, "Not a NIF file");
        return false;
    }
    m_pkIstr->SetEndianSwap(false);
    m_pkIstr->BinaryRead(&m_uiNifFileVersion);
    if (m_uiNifFileVersion < fnv_00a65400::g_uiNifMinVersion_011a9b08)
    {
        m_uiNativeThreadId = 3;
        fnv_00a65400::strcpy_s(m_acLastErrorMessage, 0x104, "NIF version is too old.");
        return false;
    }
    if (m_uiNifFileVersion > fnv_00a65400::g_uiNifMaxVersion_011a9b0c)
    {
        m_uiNativeThreadId = 4;
        fnv_00a65400::strcpy_s(m_acLastErrorMessage, 0x104, "Unknown NIF version.");
        return false;
    }
    reinterpret_cast<unsigned char&>(m_bSourceIsLittleEndian) = 1;
    if (m_uiNifFileVersion >= 0x14000003)
        fnv_00a65400::NiStreamLoadBinary_char_00a643b0(*this, reinterpret_cast<unsigned char&>(m_bSourceIsLittleEndian));
    if (reinterpret_cast<unsigned char&>(m_bSourceIsLittleEndian) != 1 && fnv_00a65400::NiBinaryStream_GetEndianMatchHint())
    {
        m_uiNativeThreadId = 6;
        fnv_00a65400::FUN_00404d80(m_acLastErrorMessage, 0x104, "Endian mismatch.");
        return false;
    }
    if (m_uiNifFileVersion >= 0xa000108)
    {
        fnv_00a65400::NiStreamLoadBinary_float(*this, m_uiNifFileUserDefinedVersion);
        if (m_uiNifFileVersion == 0xa000165)
            m_uiNifFileUserDefinedVersion = 1;
    }
    if (m_uiNifFileUserDefinedVersion < fnv_00a65400::g_uiNifMinUserVersion_011f478c)
    {
        m_uiNativeThreadId = 3;
        fnv_00a65400::strcpy_s(m_acLastErrorMessage, 0x104, "NIF user defined version is too old.");
        return false;
    }
    if (m_uiNifFileUserDefinedVersion > fnv_00a65400::g_uiNifMaxUserVersion_011a9b10)
    {
        m_uiNativeThreadId = 4;
        fnv_00a65400::FUN_00404d80(m_acLastErrorMessage, 0x104, "Unknown NIF user defined version.");
        return false;
    }
    unsigned int uiObjects;
    fnv_00a65400::NiStreamLoadBinary_float(*this, uiObjects);
    reinterpret_cast<NiStreamTopObjects*>(&m_kObjects)->SetSize(uiObjects);
    m_kHeader.m_uiVersion = 0;
    if (m_uiNifFileVersion > 0xa000100 && (m_uiNifFileVersion <= 0xa000108 || m_uiNifFileUserDefinedVersion))
    {
        if (m_uiNifFileVersion > 0xa000101)
        {
            fnv_00a65400::NiStreamLoadBinary_float(*this, m_kHeader.m_uiVersion);
            if (m_uiNifFileVersion == 0xa000102)
                m_uiNifFileVersion = 0xa000101;
        }
        unsigned char ucLength;
        fnv_00a65400::NiStreamLoadBinary_char_00a643b0(*this, ucLength);
        fnv_00a65400::NiStreamLoadBinary_char(*this, m_kHeader.m_acAuthor, ucLength);
        fnv_00a65400::NiStreamLoadBinary_char_00a643b0(*this, ucLength);
        fnv_00a65400::NiStreamLoadBinary_char(*this, m_kHeader.m_acProcessScript, ucLength);
        fnv_00a65400::NiStreamLoadBinary_char_00a643b0(*this, ucLength);
        fnv_00a65400::NiStreamLoadBinary_char(*this, m_kHeader.m_acExportScript, ucLength);
        if (m_kHeader.m_uiVersion < 0x15)
        {
            m_uiNativeThreadId = 3;
            fnv_00a65400::FUN_00404d80(m_acLastErrorMessage, 0x104, "NIF BSversion is too old");
            return false;
        }
    }
    m_pkIstr->SetEndianSwap(reinterpret_cast<unsigned char&>(m_bSourceIsLittleEndian) != 1);
    return true;
}

namespace fnv_00a65720 {

template <class T> inline void LoadValue(NiBinaryStream* stream, T& value)
{
    unsigned int componentSize = sizeof(T);
    stream->BinaryRead(&value, sizeof(T), &componentSize, 1);
}

}  // namespace fnv_00a65720

inline NiObject* NiStream::GetLoadedObject(unsigned int id)
{
    return id == 0xffffffff ? 0 : m_kObjects.m_pBase[id].m_pObject;
}

// @fnv 0x00a65720
void NiStream::LoadTopLevelObjects()
{
    unsigned int count;
    fnv_00a65720::LoadValue(m_pkIstr, count);
    NiStreamTopObjects& topObjects = (NiStreamTopObjects&)m_kTopObjects;
    topObjects.SetSize(count);
    for (unsigned int i = 0; i < count; ++i)
    {
        unsigned int id;
        fnv_00a65720::LoadValue(m_pkIstr, id);
        NiObject* object = GetLoadedObject(id);
        NiObject* reference = object;
        if (reference)
            reference->IncRefCount();
        topObjects.SetAt(i, reinterpret_cast<const NiPointer<NiObject>&>(reference));
        if (object)
            object->DecRefCount();
    }
}

namespace fnv_00a65800 {
extern "C" int __cdecl strcmp(const char* pA, const char* pB);
extern "C" int __cdecl strcpy_s(char* pDest, unsigned int uiSize, const char* pSrc);
extern "C" int __cdecl strcat_s(char* pDest, unsigned int uiSize, const char* pSrc);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

__declspec(nothrow) void* __cdecl _NiMalloc_00aa1070(unsigned int uiSize);
__declspec(nothrow) void __cdecl _NiFree_00aa10f0(void* pvMem);

typedef NiObject*(__cdecl* CreateFunction)();

struct LoaderMap
{
    __declspec(nothrow) bool FUN_00a53c30(const char* pcKey, CreateFunction& pfnValue);
};
extern LoaderMap* g_pkLoaders_011f4784;


// Reads RTTI class names and object indices from m_pUnderlyingStream, resolves create functions, and instantiates objects into m_kThirdFollowingStreamField.
// @fnv 0x00a65800
}  // namespace fnv_00a65800
bool NiStream::LoadRTTIAndObjects()
{
    NiStreamTopObjects& objects = reinterpret_cast<NiStreamTopObjects&>(m_kObjects);
    unsigned short usNumRTTI;
    m_pkIstr->BinaryRead(&usNumRTTI);
    fnv_00a65800::CreateFunction* ppkCreate = (fnv_00a65800::CreateFunction*)fnv_00a65800::_NiMalloc_00aa1070(usNumRTTI * sizeof(fnv_00a65800::CreateFunction));
    for (unsigned int i = 0; i < usNumRTTI; i++)
    {
        char acClassName[256];
        unsigned int uiLength;
        m_pkIstr->BinaryRead(&uiLength);
        m_pkIstr->BinaryRead(acClassName, uiLength);
        acClassName[uiLength] = 0;
        if (m_uiNifFileVersion < 0x14010001 && fnv_00a65800::strcmp(acClassName, "NiControllerManager") == 0)
        {
            m_uiNativeThreadId = 3;
            fnv_00a65800::strcpy_s(m_acLastErrorMessage, 0x104, "Older files may not contain animation data. Reexport required.");
            return false;
        }
        if (!fnv_00a65800::g_pkLoaders_011f4784->FUN_00a53c30(acClassName, ppkCreate[i]))
        {
            m_uiNativeThreadId = 5;
            fnv_00a65800::strcpy_s(m_acLastErrorMessage, 0x104, acClassName);
            fnv_00a65800::strcat_s(m_acLastErrorMessage, 0x104, ": cannot find create function.");
            ppkCreate[i] = 0;
        }
        if (acClassName[0] == 'b' && acClassName[1] == 'h' && fnv_00a65800::strcmp(acClassName, "bhkConvexListShape") == 0)
            ppkCreate[i] = 0;
    }
    for (unsigned int j = 0; j < objects.m_uiMaxSize; j++)
    {
        bool bFailed = false;
        unsigned short usIndex;
        m_pkIstr->BinaryRead(&usIndex);
        if (m_uiNifFileVersion >= 0x14020005 && (usIndex & 0x8000))
        {
            usIndex &= 0x7fff;
            bFailed = true;
        }
        bool bCreate = ppkCreate[usIndex] != 0;
        if (bCreate)
            bCreate = true;
        if (!bCreate)
        {
            if (!bFailed)
            {
                fnv_00a65800::_NiFree_00aa10f0(ppkCreate);
                return false;
            }
            objects.SetAt(j, 0);
        }
        else
        {
            NiPointer<NiObject> spRetainedObject = ppkCreate[usIndex]();
            objects.SetAt(j, spRetainedObject);
        }
    }
    fnv_00a65800::_NiFree_00aa10f0(ppkCreate);
    return true;
}

namespace fnv_00a65b00 {
void* __cdecl _NiMalloc_00aa1070(unsigned int size) throw();
void __cdecl _NiFree_00aa10f0(void* apMemory) throw();
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*) throw();

template <class T> __forceinline void NiStreamLoad(NiBinaryStream& kStream, T& value)
{
    unsigned int uiComponentSize = sizeof(T);
    kStream.BinaryRead(&value, sizeof(T), &uiComponentSize, 1);
}

__forceinline void NiStreamLoad(NiBinaryStream& kStream, char* pcBuffer, unsigned int uiTotalBytes)
{
    unsigned int uiComponentSize = 1;
    kStream.BinaryRead(pcBuffer, uiTotalBytes, &uiComponentSize, 1);
}

// NiStream.h does not declare LoadFixedStrings (0x00a65b00).
class StreamEx
{
  public:
    bool LoadFixedStrings();

    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    NiTLargeObjectArray<NiFixedString> m_kFixedStringTable;
    NiBinaryStream* m_spIStream;
};

// Reads a count and string lengths from m_spIStream, allocates a buffer, loads each string into m_kFixedStringTable via FUN_00a63730, and frees the buffer.
// @fnv 0x00a65b00
bool StreamEx::LoadFixedStrings()
{
    unsigned int ItemUpdateArray;
    NiStreamLoad(*m_spIStream, ItemUpdateArray);
    m_kFixedStringTable.SetSize(ItemUpdateArray);

    unsigned int uiMaxLen;
    NiStreamLoad(*m_spIStream, uiMaxLen);
    char* pcBuffer = (char*)_NiMalloc_00aa1070(uiMaxLen + 1);

    for (unsigned short ui = 0; ui < ItemUpdateArray; ui++)
    {
        unsigned int uiLen = 0;
        NiStreamLoad(*m_spIStream, uiLen);
        NiStreamLoad(*m_spIStream, pcBuffer, uiLen);
        pcBuffer[uiLen] = '\0';
        NiFixedString kString(static_cast<const char*>(pcBuffer));
        m_kFixedStringTable.SetAt(ui, kString);
    }

    _NiFree_00aa10f0(pcBuffer);
    return true;
}
}  // namespace fnv_00a65b00

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* pkCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* pkCriticalSection);

struct NiStreamLs;

struct NiSemaphoreLs
{
    void NiThread_Suspend();
};

typedef void(__cdecl* PostProcessFunction)(NiStreamLs& kStream, NiObject* pkObject);

extern NiTPrimitiveArray<PostProcessFunction>* g_pkPostProcessFunctions_011f4788;
extern char g_kCleanupCriticalSection_011f4800[];

// NiStream.h lacks LoadFixedStrings and the post-load pass at 0x00a63d10.
struct NiStreamLs
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
    virtual bool LoadHeader();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void LoadTopLevelObjects();
    virtual void v19();
    virtual bool LoadObject();
    virtual void v21();
    virtual void v22();
    virtual bool LoadObjectSizeTable();

    char pad004[0xd8 - 4];
    unsigned int m_uiNifVersion;
    char pad0dc[0x1ec - 0xdc];
    NiStreamTopObjects m_kThirdFollowingStreamField;
    char pad204[0x208 - 0x204];
    unsigned int* m_puiObjectSizes;
    char pad20c[0x220 - 0x20c];
    NiObject** m_ppkTopObjects;
    int unk224;
    unsigned int m_uiTopObjects;
    char pad22c[0x24c - 0x22c];
    NiBinaryStream* m_pUnderlyingStream;
    char pad250[0x25c - 0x250];
    int unk25c;
    int unk260;
    int pad264[2];
    int unk26c;
    int unk270;
    char pad274[0x28c - 0x274];
    int m_eStreamThreadStatus;
    int pad290;
    unsigned int StreamThreadContext;
    unsigned int m_uiBackgroundLoadState;
    unsigned int BackgroundLoadThreadInfo;
    NiSemaphoreLs* m_pkSemaphore;

    void FUN_00a644f0();
    bool LoadRTTIAndObjects();
    bool LoadFixedStrings();
    void LoadGroups();
    void Clear();
    void NiStream_SetSelectiveUpdateFlagsForOldVersions();
    bool NiStream_LoadStream();
};

// Loads a NIF stream by reading the header, objects, and top-level links, then runs post-process functions and cleans up.
// @fnv 0x00a65c60
// src: XBOX_PDB 0x00a65c60
bool NiStreamLs::NiStream_LoadStream()
{
    if (!LoadHeader())
        return false;
    BackgroundLoadThreadInfo = 0;
    m_uiBackgroundLoadState = 0;
    StreamThreadContext = 0;
    FUN_00a644f0();
    bool bRTTI = m_uiNifVersion >= 0x05000001;
    if (bRTTI && !LoadRTTIAndObjects())
        return false;
    if (m_uiNifVersion >= 0x14020005 && !LoadObjectSizeTable())
        return false;
    if (m_uiNifVersion >= 0x14010001 && !LoadFixedStrings())
        return false;
    if (m_uiNifVersion >= 0x05000006)
        LoadGroups();

    unsigned int uiObjects = m_kThirdFollowingStreamField.m_uiMaxSize;
    for (; StreamThreadContext < uiObjects; StreamThreadContext++)
    {
        if (m_eStreamThreadStatus == 2)
            goto abort;
        if (m_eStreamThreadStatus == 3)
        {
            m_eStreamThreadStatus = 4;
            m_pkSemaphore->NiThread_Suspend();
        }
        if (bRTTI)
        {
            NiObject* pkObject = m_kThirdFollowingStreamField.m_pBase[StreamThreadContext].m_pObject;
            if (pkObject)
            {
                pkObject->LoadBinary(*reinterpret_cast<NiStream*>(this));
            }
            else
            {
                m_pUnderlyingStream->GetPosition();
                m_pUnderlyingStream->Seek(m_puiObjectSizes[StreamThreadContext]);
            }
        }
        else if (!LoadObject())
        {
            Clear();
            return false;
        }
    }
    LoadTopLevelObjects();
    for (; m_uiBackgroundLoadState < uiObjects; m_uiBackgroundLoadState++)
    {
        if (m_eStreamThreadStatus == 3)
        {
            m_eStreamThreadStatus = 4;
            m_pkSemaphore->NiThread_Suspend();
        }
        NiObject* pkObject = m_kThirdFollowingStreamField.m_pBase[m_uiBackgroundLoadState].m_pObject;
        if (pkObject)
            pkObject->LinkObject(*reinterpret_cast<NiStream*>(this));
    }
    for (; BackgroundLoadThreadInfo < uiObjects; BackgroundLoadThreadInfo++)
    {
        if (m_eStreamThreadStatus == 3)
        {
            m_eStreamThreadStatus = 4;
            m_pkSemaphore->NiThread_Suspend();
        }
        NiObject* pkObject = m_kThirdFollowingStreamField.m_pBase[BackgroundLoadThreadInfo].m_pObject;
        if (pkObject)
            pkObject->PostLinkObject(*reinterpret_cast<NiStream*>(this));
    }
    if (m_eStreamThreadStatus == 2)
        goto abort;
    if (m_eStreamThreadStatus == 3)
    {
        m_eStreamThreadStatus = 4;
        m_pkSemaphore->NiThread_Suspend();
    }
    if (g_pkPostProcessFunctions_011f4788->m_usESize > 0)
    {
        for (unsigned int i = 0; i < m_uiTopObjects; i++)
        {
            NiObject* pkObject = m_ppkTopObjects[i];
            if (pkObject)
            {
                for (unsigned int j = 0; j < g_pkPostProcessFunctions_011f4788->m_usSize; j++)
                {
                    PostProcessFunction pfnFunc = g_pkPostProcessFunctions_011f4788->m_pBase[j];
                    if (pfnFunc)
                        pfnFunc(*this, pkObject);
                }
            }
        }
    }
    if (m_eStreamThreadStatus == 2)
    {
    abort:
        EnterCriticalSection(g_kCleanupCriticalSection_011f4800);
        m_kThirdFollowingStreamField.RemoveAll();
        unk25c = 0;
        unk26c = 0;
        unk260 = 0;
        unk270 = 0;
        LeaveCriticalSection(g_kCleanupCriticalSection_011f4800);
        return false;
    }
    NiStream_SetSelectiveUpdateFlagsForOldVersions();
    EnterCriticalSection(g_kCleanupCriticalSection_011f4800);
    m_kThirdFollowingStreamField.RemoveAll();
    unk25c = 0;
    unk26c = 0;
    unk260 = 0;
    unk270 = 0;
    LeaveCriticalSection(g_kCleanupCriticalSection_011f4800);
    return true;
}

// @fnv 0x00a65f80
template <> unsigned int NiTLargeArray<NiFixedString, NiTNewInterface<NiFixedString> >::AddFirstEmpty(const NiFixedString& element)
{
    if (element == NiFixedString())
        return 0xffffffff;
    for (unsigned int i = 0; i < m_uiSize; i++)
    {
        if (m_pBase[i] == NiFixedString())
        {
            m_pBase[i] = element;
            m_uiESize++;
            return i;
        }
    }
    unsigned int uiIndex = m_uiSize;
    if (uiIndex >= m_uiMaxSize)
        SetSize(uiIndex + m_uiGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}

extern MemoryManager g_memoryManager;
struct FUN_00a66030_obj
{
    void FUN_00a63850();
};
// Calls the object's cleanup method and, when the low bit of flags is set, deallocates the object through g_memoryManager, then returns the object pointer.
// @fnv 0x00a66030
// src: COMMUNITY 0x00a66030
FUN_00a66030_obj* __fastcall NiTStringTemplateMap_NiTPointerMap_char_const_NiObject_cdecl_void_NiObject_cdecl_void_Destroy(FUN_00a66030_obj* apThis, int, unsigned int flags)
{
    apThis->FUN_00a63850();
    if (flags & 1)
        g_memoryManager.Deallocate(apThis);
    return apThis;
}

extern MemoryManager g_memoryManager;
struct FUN_00a66050_obj
{
    void FUN_00a63910();
};
// Calls FUN_00a63910 and deallocates self through g_memoryManager when flags bit 0 is set.
// @fnv 0x00a66050
FUN_00a66050_obj* __fastcall FUN_00a66050(FUN_00a66050_obj* apObject, int, unsigned int flags)
{
    apObject->FUN_00a63910();
    if (flags & 1)
        g_memoryManager.Deallocate(apObject);
    return apObject;
}

namespace fnv_00a66070 {
void __cdecl Object_ProcessEntries_00a644a0(void*);

extern MemoryManager g_memoryManager;
extern int DAT_0109bd4c;
struct Holder66070
{
    void* vf;
    void* mem;
    void* FUN_00a66070(unsigned int);
};
// Saves mem, sets vf to DAT_0109bd4c, calls FUN_00a644a0 with the saved pointer, and conditionally calls _DeallocateAlias on this.
// @fnv 0x00a66070
void* Holder66070::FUN_00a66070(unsigned int flags)
{
    void* tmp = mem;
    vf = (void*)&DAT_0109bd4c;
    Object_ProcessEntries_00a644a0(tmp);
    if (flags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}
}  // namespace fnv_00a66070

void* __cdecl NiMalloc(unsigned int uiSize);

// The post-process list's constructor is inline in the original 0x00a660a0.
template <class T, class TAlloc> inline void* NiTArray<T, TAlloc>::operator new(size_t size)
{
    return g_memoryManager.Allocate(size);
}
template <class T, class TAlloc> inline NiTArray<T, TAlloc>::NiTArray(unsigned int uiMaxSize, unsigned int uiGrowBy) throw()
{
    m_usMaxSize = (unsigned short)uiMaxSize;
    m_usGrowBy = (unsigned short)uiGrowBy;
    m_usSize = 0;
    m_usESize = 0;
    if (m_usMaxSize > 0)
        m_pBase = static_cast<T*>(NiMalloc(sizeof(T) * m_usMaxSize));
    else
        m_pBase = 0;
}
template <class T> inline NiTPrimitiveArray<T>::NiTPrimitiveArray(unsigned int uiMaxSize, unsigned int uiGrowBy) throw()
    : NiTArray<T, NiTMallocInterface<T> >(uiMaxSize, uiGrowBy)
{
}

namespace fnv_00a660a0 {
extern "C" void* fnv_zlib_memset(void* dst, int c, int n);
void* __cdecl NiMalloc(unsigned int uiSize);

extern MemoryManager g_memoryManager;

class A660A0Object
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        return g_memoryManager.Allocate(uiSize);
    }
    static void operator delete(void* pvMem);
};

class A660A0MapBase : public A660A0Object
{
  public:
    __forceinline A660A0MapBase(unsigned int uiHashSize) throw()
    {
        m_uiHashSize = uiHashSize;
        m_uiCount = 0;
        unsigned int uiSize = sizeof(void*) * m_uiHashSize;
        m_ppkHashTable = static_cast<void**>(NiMalloc(uiSize));
        fnv_zlib_memset(m_ppkHashTable, 0, m_uiHashSize * sizeof(void*));
        m_bValueAt0C = false;
    }
    virtual ~A660A0MapBase();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    bool m_bValueAt0C;
};

class A660A0Map : public A660A0MapBase
{
  public:
    __forceinline A660A0Map() throw() : A660A0MapBase(59)
    {}
    virtual ~A660A0Map();
};

extern A660A0Map* DAT_011f4784;
extern NiStreamPostProcessArray* DAT_011f4788;
extern bool DAT_011f4780;

// Allocates a global A660A0Map and the post-process function array, and sets the DAT_011f4780 flag to true.
// @fnv 0x00a660a0
// src: COMMUNITY 0x00a660a0
void __cdecl NiStream__SDMInit()
{
    DAT_011f4784 = new A660A0Map;
    DAT_011f4788 = new NiTPrimitiveArray<NiStreamPostProcess>(0, 3);
    DAT_011f4780 = true;
}
}  // namespace fnv_00a660a0

extern int DAT_01081ef0;
extern int DAT_0109bc64;
extern int DAT_0109bd54;
extern int DAT_0109bd90;
extern int DAT_0109bdcc;
extern int DAT_0109bf6c;
extern int DAT_0109bf74;
extern unsigned int DAT_011a9b0c;
extern unsigned int DAT_011a9b10;
extern bool DAT_011f4780;
void* __cdecl _NiMalloc(unsigned int uiSize);
void* __cdecl _fnv_zlib_memset(void* pDst, int iValue, unsigned int uiSize);

struct VPtr_a66150
{
    const void* m_pVtbl;
    VPtr_a66150(const void* pVtbl) : m_pVtbl(pVtbl)
    {}
};

struct StreamHeader_a66150
{
    unsigned int m_uiFormatVersion;
    char m_acAuthor[64];
    char m_acProcessScript[64];
    char m_acExportScript[64];
    StreamHeader_a66150()
    {
        m_uiFormatVersion = 0x22;
        m_acAuthor[0] = 0;
        m_acProcessScript[0] = 0;
        m_acExportScript[0] = 0;
    }
};

// Constructor-only storage: replacing these by-value records with
// NiTPrimitiveArray<NiObjectGroup*> / NiTLarge{Object,Primitive}Array<T>
// changes 0x00a66150 from 508 to 569 bytes (VC9 /O2, checked with rebind).
// Regular container operations elsewhere use the shared templates.
struct NiStreamConstructorSmallArray : VPtr_a66150
{
    void** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    NiStreamConstructorSmallArray(const void* pVtbl, unsigned int uiMaxSize, unsigned int uiGrowBy) : VPtr_a66150(0)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usGrowBy == 0)
            m_usGrowBy = 1;
        if (m_usMaxSize > 0)
            m_pBase = (void**)_NiMalloc(sizeof(void*) * m_usMaxSize);
        else
            m_pBase = 0;
        m_pVtbl = pVtbl;
    }
};

struct NiStreamConstructorLargeArray : VPtr_a66150
{
    void** m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    NiStreamConstructorLargeArray(const void* pVtbl, unsigned int uiMaxSize, unsigned int uiGrowBy) : VPtr_a66150(0)
    {
        m_uiMaxSize = uiMaxSize;
        m_uiGrowBy = uiGrowBy;
        m_uiSize = 0;
        m_uiESize = 0;
        if (m_uiGrowBy == 0)
            m_uiGrowBy = 1;
        if (m_uiMaxSize > 0)
            m_pBase = (void**)_NiMalloc(sizeof(void*) * m_uiMaxSize);
        else
            m_pBase = 0;
        m_pVtbl = pVtbl;
    }
};

struct Set_a66150
{
    unsigned int* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
    Set_a66150(unsigned int uiInitialSize)
    {
        if (uiInitialSize > 0)
            m_pBase = (unsigned int*)_NiMalloc(sizeof(unsigned int) * uiInitialSize);
        else
            m_pBase = 0;
        m_uiElementCount = uiInitialSize;
        m_uiAllocatedCapacity = 0;
    }
};

// RTTI 0x0109bc64 / 0x0109bd54: NiStream's object-to-link-ID map.
template <> __forceinline
NiTMapBase<NiTPointerAllocator<unsigned int>, const NiObject*, unsigned int>::NiTMapBase(unsigned int uiHashSize)
{
    m_uiHashSize = uiHashSize;
    m_kItemCount.m_uiCount = 0;
    unsigned int uiSize = sizeof(EntryType*) * m_uiHashSize;
    m_ppkHashTable = static_cast<EntryType**>(_NiMalloc(uiSize));
    _fnv_zlib_memset(m_ppkHashTable, 0, sizeof(EntryType*) * m_uiHashSize);
}

template <> __forceinline
NiTPointerMap<const NiObject*, unsigned int>::NiTPointerMap(unsigned int uiHashSize)
    : NiTMapBase<NiTPointerAllocator<unsigned int>, const NiObject*, unsigned int>(uiHashSize)
{}

struct Affinity_a66150
{
    unsigned int m_uiIdealProcessor;
    unsigned int m_uiProcessorAffinityMask;
    Affinity_a66150() : m_uiIdealProcessor(0xffffffff), m_uiProcessorAffinityMask(0xffffffff)
    {}
};

struct ErrorInfo_a66150
{
    unsigned int m_uiNativeThreadId;
    char m_acSecondPathBuffer[260];
    ErrorInfo_a66150()
    {
        m_uiNativeThreadId = 0;
        m_acSecondPathBuffer[0] = 0;
    }
};

struct FUN_00a66150 : VPtr_a66150
{
    StreamHeader_a66150 m_kHeader;                   // +0x04
    NiStreamConstructorSmallArray m_kObjectGroups;   // +0xc8
    unsigned int m_uiNifVersion;                     // +0xd8
    unsigned int StreamFileInfo;                     // +0xdc
    char m_acInputFilePath[260];                     // +0xe0
    bool m_bFirstStreamFlag;                         // +0x1e4
    bool m_bSecondStreamFlag;                        // +0x1e5
    unsigned int m_uiUnk1E8;                         // +0x1e8
    NiStreamConstructorLargeArray m_kThirdFollowingStreamField;  // +0x1ec
    NiStreamConstructorLargeArray ObjectSerializationStream;     // +0x204
    NiStreamConstructorLargeArray m_kTopLevelObjects;            // +0x21c
    NiStreamConstructorLargeArray m_kStringTable;                // +0x234
    void* m_pUnderlyingStream;                       // +0x24c
    void* m_pBackingStream;                          // +0x250
    Set_a66150 m_kSecondFollowingStreamField;        // +0x254
    unsigned int StreamObjectIndex;                  // +0x260
    Set_a66150 m_kSecondUnsignedIntSet;              // +0x264
    unsigned int m_uiObjectIndexCount;               // +0x270
    NiTPointerMap<const NiObject*, unsigned int> m_kObjectToIndexMap;                  // +0x274
    unsigned short m_usAVObjectFlags;                // +0x284
    unsigned short m_usTimeControllerFlags;          // +0x286
    unsigned short m_usPropertyFlags;                // +0x288
    unsigned int m_eStreamThreadStatus;              // +0x28c
    bool m_bThreadActive;                            // +0x290
    unsigned int m_uiUnk294;
    unsigned int m_uiUnk298;
    unsigned int m_uiUnk29C;
    void* m_pBackgroundLoadThread;               // +0x2a0
    void* BackgroundLoadTask;                    // +0x2a4
    unsigned int m_eThreadPriority;              // +0x2a8
    Affinity_a66150 m_kBackgroundLoadSemaphore;  // +0x2ac
    char m_acLoadPath[260];                      // +0x2b4
    ErrorInfo_a66150 m_kError;                   // +0x3b8
    FUN_00a66150();
};

// Initializes the NifStream object, its stream arrays, maps, thread state, and error fields.
// @fnv 0x00a66150
FUN_00a66150::FUN_00a66150()
    : VPtr_a66150(&DAT_0109bdcc), m_kObjectGroups(&DAT_0109bd90, 0, 1),
      m_kThirdFollowingStreamField(&DAT_0109bf6c, 0, 1024), ObjectSerializationStream(&DAT_01081ef0, 0, 1),
      m_kTopLevelObjects(&DAT_0109bf6c, 0, 1), m_kStringTable(&DAT_0109bf74, 0, 128), m_kSecondFollowingStreamField(0),
      m_kSecondUnsignedIntSet(0), m_kObjectToIndexMap(37), m_pBackgroundLoadThread(0), BackgroundLoadTask(0),
      m_eThreadPriority(2)
{
    m_pUnderlyingStream = 0;
    m_pBackingStream = 0;
    m_uiNifVersion = DAT_011a9b0c;
    StreamFileInfo = DAT_011a9b10;
    m_bFirstStreamFlag = true;
    m_acInputFilePath[0] = 0;
    StreamObjectIndex = 0;
    m_uiObjectIndexCount = 0;
    m_bSecondStreamFlag = true;
    DAT_011f4780 = true;
    m_eStreamThreadStatus = 0;
    m_kError.m_uiNativeThreadId = 0;
    m_kError.m_acSecondPathBuffer[0] = 0;
}

extern MemoryManager g_memoryManager;
struct FUN_00a66350_obj
{
    void _NiStreamDtorAlias();
};
// Calls the NiStream destructor alias and deallocates the object via g_memoryManager when the low bit of flags is set.
// @fnv 0x00a66350
FUN_00a66350_obj* __fastcall NiStreamDtor(FUN_00a66350_obj* apStream, int, unsigned int flags)
{
    apStream->_NiStreamDtorAlias();
    if (flags & 1)
        g_memoryManager.Deallocate(apStream);
    return apStream;
}

struct FUN_00a53c30_cls
{
    bool FUN_00a53c30(NiObject* key, NiObject** out);
};

struct UnsignedIntValue
{
    unsigned int value;
};
struct FUN_00b57ea0_cls
{
    void FUN_00b57ea0(NiObject* key, UnsignedIntValue value);
};


// Adds object to linkMap and objects array, incrementing its reference count, then decrements it and returns true.
// @fnv 0x00a663e0
bool NiStream::RegisterSaveObject(NiObject* object)
{
    NiObject* obj = object;
    FUN_00a53c30_cls* map = reinterpret_cast<FUN_00a53c30_cls*>(&m_kRegisterMap);
    if (map->FUN_00a53c30(obj, &object))
    {
        return false;
    }
    UnsignedIntValue count = {m_kObjects.m_uiSize};
    ((FUN_00b57ea0_cls*)map)->FUN_00b57ea0(obj, count);
    object = obj;
    if (obj != 0)
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&obj->m_uiRefCount));
    }
    unsigned int index = m_kObjects.m_uiSize;
    NiStreamTopObjects* arr = reinterpret_cast<NiStreamTopObjects*>(&m_kObjects);
    if (index >= arr->m_uiMaxSize)
    {
        arr->SetSize(arr->m_uiGrowBy + index);
    }
    arr->SetAt(index, reinterpret_cast<const NiPointer<NiObject>&>(object));
    if (obj != 0)
    {
        long rc = InterlockedDecrement(reinterpret_cast<volatile long*>(&obj->m_uiRefCount));
        if (rc == 0)
        {
            obj->DeleteThis();
        }
    }
    return true;
}

extern char* _EmptyFS;


// Adds str to names if Find(str) returns -1, then returns true.
// @fnv 0x00a66480
bool NiStream::RegisterFixedString(const NiFixedString& str)
{
    int index = -1;
    if (str.m_kHandle != _EmptyFS)
    {
        for (unsigned int i = 0; i < m_kFixedStrings.m_uiSize; i++)
        {
            if (str.m_kHandle == m_kFixedStrings.m_pBase[i].m_kHandle)
            {
                index = i;
                break;
            }
        }
    }
    if (index == -1)
        reinterpret_cast<NiStreamFixedStrings*>(&m_kFixedStrings)->AddFirstEmpty(str);
    return true;
}

template <class T, class TAlloc> inline unsigned int NiTLargeArray<T, TAlloc>::Add(const T& object)
{
    unsigned int index = m_uiSize;
    if (index >= m_uiMaxSize)
        SetSize(index + m_uiGrowBy);
    SetAt(index, object);
    return index;
}

namespace fnv_00a664e0 {

typedef NiObject*(__cdecl* ObjectFactory)();
extern NiTStringPointerMap<ObjectFactory>* DAT_011f4784;

// Looks up a class factory by name, creates and ref-counts a NiObject, adds it to topObjects, and calls load on it.
// @fnv 0x00a664e0
}  // namespace fnv_00a664e0
bool NiStream::LoadObject()
{
    char className[256];
    union Creation
    {
        NiObject*(__cdecl* factory)();
        NiObject* instance;
    } creation;
    LoadRTTIString(reinterpret_cast<unsigned int>(className));
    if (!fnv_00a664e0::DAT_011f4784->GetAt(className, creation.factory))
    {
        m_uiNativeThreadId = 5;
        strcpy_s(m_acLastErrorMessage, 260, className);
        strcat_s(m_acLastErrorMessage, 260, ": cannot find create function.");
        return false;
    }
    NiObject* pCreatedObject = creation.factory();
    creation.instance = pCreatedObject;
    if (pCreatedObject)
        InterlockedIncrement(reinterpret_cast<volatile long*>(&pCreatedObject->m_uiRefCount));
    reinterpret_cast<NiStreamTopObjects*>(&m_kObjects)->Add(reinterpret_cast<const NiPointer<NiObject>&>(creation.instance));
    if (pCreatedObject && !InterlockedDecrement(reinterpret_cast<volatile long*>(&pCreatedObject->m_uiRefCount)))
        pCreatedObject->DeleteThis();
    pCreatedObject->LoadBinary(*reinterpret_cast<NiStream*>(this));
    return true;
}

namespace fnv_00a665f0 {
void* __cdecl FUN_00ec61c0(void* pvDest, int iValue, unsigned int uiSize);
void* __cdecl _NiMalloc_00aa1070(unsigned int uiSize);
void __cdecl _NiFree_00aa10f0(void* pvMem);

struct RtNiRTTI
{
    const char* m_pcName;
    const RtNiRTTI* m_pBaseRTTI;
};



class RtMapBase
{
  public:
    RtMapBase(unsigned int uiHashSize)
    {
        m_uiHashSize = uiHashSize;
        m_uiCount = 0;
        unsigned int uiSize = sizeof(NiTMapItem<const char*, unsigned short>*) * m_uiHashSize;
        m_ppkHashTable = (NiTMapItem<const char*, unsigned short>**)_NiMalloc_00aa1070(uiSize);
        FUN_00ec61c0(m_ppkHashTable, 0, m_uiHashSize * sizeof(NiTMapItem<const char*, unsigned short>*));
    }
    virtual void v00();
    virtual unsigned int KeyToHashIndex(const char* pcKey) const;
    virtual bool IsKeysEqual(const char* pcKey1, const char* pcKey2) const;

    unsigned int GetCount() const
    {
        return m_uiCount;
    }
    NiTMapItem<const char*, unsigned short>* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
    void GetNext(NiTMapItem<const char*, unsigned short>*& pos, const char*& key, unsigned short& val) const
    {
        NiTMapItem<const char*, unsigned short>* pkItem = pos;
        key = pkItem->m_key;
        val = pkItem->m_val;
        if (pkItem->m_pkNext)
        {
            pos = pkItem->m_pkNext;
            return;
        }
        unsigned int i = KeyToHashIndex(pkItem->m_key);
        for (++i; i < m_uiHashSize; i++)
        {
            pkItem = m_ppkHashTable[i];
            if (pkItem)
            {
                pos = pkItem;
                return;
            }
        }
        pos = 0;
    }
    bool GetAt(const char* key, unsigned short& val) const
    {
        unsigned int uiIndex = KeyToHashIndex(key);
        NiTMapItem<const char*, unsigned short>* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem)
        {
            if (IsKeysEqual(key, pkItem->m_key))
            {
                val = pkItem->m_val;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
    bool FUN_00c74990(const char* key, unsigned short& val) const;
    void FUN_00a643e0(const char* key, unsigned short val);
    void FUN_00a63910();

    unsigned int m_uiHashSize;
    NiTMapItem<const char*, unsigned short>** m_ppkHashTable;
    unsigned int m_uiCount;
};

class RtStringTmpl : public RtMapBase
{
  public:
    RtStringTmpl(unsigned int uiHashSize, bool bCopy) : RtMapBase(uiHashSize)
    {
        m_bCopy = bCopy;
    }
    virtual void v00();
    virtual unsigned int KeyToHashIndex(const char* pcKey) const;
    virtual bool IsKeysEqual(const char* pcKey1, const char* pcKey2) const;
    bool m_bCopy;
};

class RtStringMap : public RtStringTmpl
{
  public:
    RtStringMap(unsigned int uiHashSize = 37, bool bCopy = false) : RtStringTmpl(uiHashSize, bCopy)
    {}
    virtual void v00();
    virtual unsigned int KeyToHashIndex(const char* pcKey) const;
    virtual bool IsKeysEqual(const char* pcKey1, const char* pcKey2) const;
};

struct RtStream
{
    void* m_vtbl;
    char pad004[0x1f0 - 4];
    NiObject** m_ppkObjects;
    unsigned int m_uiMaxObjects;
    unsigned int m_uiNumObjects;
    char pad1fc[0x250 - 0x1fc];
    NiBinaryStream* m_pBackingStream;

    void SaveCString(const char* pcString);
    void WriteRTTIHeader();
};

// Writes the RTTI name table and per-object RTTI IDs (with clone flag) to the backing stream.
// @fnv 0x00a665f0
void RtStream::WriteRTTIHeader()
{
    RtStringMap kRTTIMap;
    unsigned int i;
    for (i = 0; i < m_uiNumObjects; i++)
    {
        const char* pcName = m_ppkObjects[i]->GetStreamableRTTI()->m_pcName;
        unsigned short usID;
        if (!kRTTIMap.FUN_00c74990(pcName, usID))
            kRTTIMap.FUN_00a643e0(pcName, (unsigned short)kRTTIMap.GetCount());
    }

    unsigned short usNumRTTI = (unsigned short)kRTTIMap.GetCount();
    const char** ppcRTTINames = (const char**)_NiMalloc_00aa1070(usNumRTTI * sizeof(const char*));
    NiTMapItem<const char*, unsigned short>* pkPos = kRTTIMap.GetFirstPos();
    while (pkPos)
    {
        const char* pcName;
        unsigned short usID;
        kRTTIMap.GetNext(pkPos, pcName, usID);
        ppcRTTINames[usID] = pcName;
    }

    WriteStreamValues(m_pBackingStream, &usNumRTTI);
    for (i = 0; i < usNumRTTI; i++)
        SaveCString(ppcRTTINames[i]);
    _NiFree_00aa10f0(ppcRTTINames);

    for (i = 0; i < m_uiNumObjects; i++)
    {
        NiObject* pkObject = m_ppkObjects[i];
        unsigned short usID;
        kRTTIMap.GetAt(pkObject->GetStreamableRTTI()->m_pcName, usID);
        if (pkObject->StreamCanSkip())
            usID |= 0x8000;
        WriteStreamValues(m_pBackingStream, &usID);
    }

    kRTTIMap.FUN_00a63910();
}
}  // namespace fnv_00a665f0

namespace fnv_00a66850 {
// NiStream.h lacks the save passes called by 0x00a66850, including 0x00a63ee0.
struct FUN_00a66850_shell : public NiStream
{
    bool NiStream_SaveStream();
};

}  // namespace fnv_00a66850
// Gamebryo NiTLargeArray.inl: the original inlines SetAt
template <class T, class TAlloc> inline void NiTLargeArray<T, TAlloc>::SetAt(unsigned int uiIndex, const T& element)
{
        if (uiIndex >= m_uiSize)
        {
            m_uiSize = uiIndex + 1;
            if (element != T(0))
                m_uiESize++;
        }
        else
        {
            if (element != T(0))
            {
                if (m_pBase[uiIndex] == T(0))
                    m_uiESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != T(0))
                    m_uiESize--;
            }
        }
        m_pBase[uiIndex] = element;
}
class TESForm;
namespace fnv_00a66850 {
typedef NiTLargeArray<::TESForm*, NiTMallocInterface<::TESForm*> > SizeArray;

struct VStream
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
    virtual void SaveHeader();
    virtual void v15();
    virtual void v16();
    virtual void RegisterSaveObjects();
    virtual void v18();
    virtual void SaveTopLevelObjects();
    virtual void v20();
    virtual unsigned int GetStartingOffset();
    virtual void BackPatch(unsigned int);
    void WriteRTTIHeader();
    void NiStream_SaveFixedStringTable();
    void UpdateTextureSwapList();
    void WriteData();
};

// Registers save objects, writes the header and each object's binary data, records per-object sizes, then back-patches and clears the object lists.
// @fnv 0x00a66850
// src: XBOX_PDB 0x00a66850
bool FUN_00a66850_shell::NiStream_SaveStream()
{
    VStream* pkThis = (VStream*)this;
    pkThis->RegisterSaveObjects();
    SizeArray& kObjectSizes = *(SizeArray*)((char*)this + 0x204);
    kObjectSizes.SetSize(*(unsigned int*)((char*)this + 0x1f8));
    pkThis->SaveHeader();
    pkThis->WriteRTTIHeader();
    unsigned int uiStartingOffset = pkThis->GetStartingOffset();
    pkThis->NiStream_SaveFixedStringTable();
    pkThis->UpdateTextureSwapList();
    pkThis->WriteData();
    for (unsigned int i = 0; i < *(unsigned int*)((char*)this + 0x1f8); i++)
    {
        NiObject* pkObject = (*(NiObject***)((char*)this + 0x1f0))[i];
        unsigned int uiStartInBytes = (*(NiBinaryStream**)((char*)this + 0x250))->GetPosition();
        pkObject->SaveBinary(*reinterpret_cast<NiStream*>(this));
        unsigned int uiSizeInBytes = (*(NiBinaryStream**)((char*)this + 0x250))->GetPosition() - uiStartInBytes;
        kObjectSizes.SetAt(i, (TESForm*)uiSizeInBytes);
    }
    pkThis->SaveTopLevelObjects();
    pkThis->BackPatch(uiStartingOffset);
    ((::NiStreamTopObjects*)((char*)this + 0x1ec))->RemoveAll();
    reinterpret_cast<NiTPointerMap<const NiObject*, unsigned int>*>(&m_kRegisterMap)->RemoveAll();
    return true;
}
}  // namespace fnv_00a66850

extern int DAT_010a256c;

void NiFreeAlias(void*);

// Sets the vtable pointer, frees the buffer at offset 0x10 if the flags at 0x20 and 0x21 are clear, and calls the NiBinaryStream destructor.
// @fnv 0x00aa2d30
__declspec(noinline) void NiMemStream::NiMemStreamDestructor()
{
    *(void**)this = &DAT_010a256c;
    if (!m_bFlag20 && !m_bFlag21)
        NiFreeAlias(m_kRayStart);
    NiBinaryStream::~NiBinaryStream();
}

struct Flag
{
    int m_flag;
    Flag(int f = 1) : m_flag(f)
    {}
    Flag(const Flag& other) : m_flag(other.m_flag)
    {}
};

namespace fnv_00c68050 {



typedef BSThreadCriticalSectionPC* LPCRITICAL_SECTION;

extern "C"
{
    __declspec(dllimport) void __stdcall EnterCriticalSection(LPCRITICAL_SECTION);
    __declspec(dllimport) void __stdcall LeaveCriticalSection(LPCRITICAL_SECTION);
    __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(void);
}

struct PointerCallback
{
    static void __cdecl HandlePointer(void*);
};

struct AudioTlsState
{
    unsigned int m_uiMemoryContextId;
    hkMemoryRouter m_router;
    void* m_pStackBuffer;
};

// 0x00c68050 indexes 16 thread routers after a critical section; this is a task manager, not NiStream.
struct TaskManager
{
    BSThreadCriticalSectionPC m_cs;
    AudioTlsState m_threads[16];
    int m_uiNumThreads;
    void RegisterThread();
};


// Registers the calling thread in the task manager by allocating a 0x5000 stack and initializing its memory router under a critical section.
// @fnv 0x00c68050
void TaskManager::RegisterThread()
{
    TaskManager* pThis = reinterpret_cast<TaskManager*>(this);
    EnterCriticalSection(&pThis->m_cs);
    if (pThis->m_uiNumThreads < 16)
    {
        AutoMemContext scope(16);
        AudioTlsState* thread = &pThis->m_threads[pThis->m_uiNumThreads];
        hkMemorySystem::GetMonitorStream()->InitializeThreadRouter(&thread->m_router, "bhkTaskletThread", Flag(1));
        hkMemoryRouter& router = thread->m_router;
        PointerCallback::HandlePointer(&router);
        void* pStack = thread->m_router.m_heap->blockAlloc(0x5000);
        thread->m_pStackBuffer = pStack;
        router.m_stack.m_start.m_storage = (void*)(reinterpret_cast<int>(pStack));
        router.m_stack.m_next.m_storage = (void*)(reinterpret_cast<int>(pStack));
        router.m_stack.m_end.m_storage = (void*)(reinterpret_cast<int>((char*)pStack + 0x5000));
        thread->m_uiMemoryContextId = GetCurrentThreadId();
        pThis->m_uiNumThreads++;
    }
    LeaveCriticalSection(&pThis->m_cs);
}
}  // namespace fnv_00c68050

struct GlobalObjectO2_00c67fe0
{
    void RegisterThread();
};
extern GlobalObjectO2_00c67fe0 g_01267830;
// @fnv 0x00c681b0
// src: GUESS 0x00c681b0 (confidence: medium)
void NiStream_RegisterThread_Thunk()
{
    g_01267830.RegisterThread();
}

#include <xmmintrin.h>
// ---------------------------------------------------------------------------
// Stand-ins for the game's objects.
//
//  The original is the constructor of `bhkWorldCinfo`, a class that derives
//  from `hkpWorldCinfo`; both keep a type-table pointer in their first dword
//  and the derived one overwrites the base's with its own.
//
//  The float constants live in .rdata in the game, so they are modelled as
//  `const` objects of this translation unit: that is what lets cl 15.00.30729.01
//  prove that a store through `this` cannot alias them, and therefore hoist
//  their loads to the top of the constructor (exactly like the original).
// ---------------------------------------------------------------------------

extern int FNV_vtbl_010c3c44;         // bhkWorldCinfo's type table
extern unsigned char FNV_b_011afe5c;  // 3
extern float FNV_f_01267b38;          // runtime initialised (.bss)

union FNV_const_bits
{
    unsigned int u;
    float f;
};

static const FNV_const_bits FNV_k_01011d78 = {0x00000000u};  // 0.0f
static const FNV_const_bits FNV_k_011afed4 = {0xC2C43334u};
static const FNV_const_bits FNV_k_0101e2bc = {0x3DCCCCCDu};  // 0.1f
static const FNV_const_bits FNV_k_0104da48 = {0x7F7FFFEEu};
static const FNV_const_bits FNV_k_unused = {0x00000000u};

struct FNV_bhkBaseCinfo
{
    int* m_vtbl;                   // +0x00
    int unk04;                     // +0x04
    int unk08;                     // +0x08
    int unk0c;                     // +0x0c
    __m128 m_vec;                  // +0x10
    int unk20;                     // +0x20
    volatile float m_f24;          // +0x24
    unsigned char m_b28;           // +0x28
    unsigned char m_b29;           // +0x29
    unsigned short unk2a;          // +0x2a
    int unk2c;                     // +0x2c
    int unk30;                     // +0x30
    int unk34;                     // +0x34
    int unk38;                     // +0x38
    int unk3c;                     // +0x3c
    int unk40;                     // +0x40
    int unk44;                     // +0x44
    int unk48;                     // +0x48
    int unk4c;                     // +0x4c
    int unk50;                     // +0x50
    volatile float m_f54;          // +0x54
    int unk58;                     // +0x58
    int unk5c;                     // +0x5c
    int unk60;                     // +0x60
    int unk64;                     // +0x64
    volatile float m_f68;          // +0x68
    int unk6c;                     // +0x6c
    int unk70;                     // +0x70
    int unk74;                     // +0x74
    int unk78;                     // +0x78
    int unk7c;                     // +0x7c
    int unk80;                     // +0x80
    int unk84;                     // +0x84
    int unk88;                     // +0x88
    int unk8c;                     // +0x8c
    int unk90;                     // +0x90
    int unk94;                     // +0x94
    int unk98;                     // +0x98
    int unk9c;                     // +0x9c
    int unkA0;                     // +0xa0
    unsigned short unkA4;          // +0xa4
    unsigned char unkA6;           // +0xa6
    volatile unsigned char m_ba7;  // +0xa7
    int unkA8;                     // +0xa8
    int unkAC;                     // +0xac
    int unkB0;                     // +0xb0
    int unkB4;                     // +0xb4
    int unkB8;                     // +0xb8
    int unkBC;                     // +0xbc
    int unkC0;                     // +0xc0
    int unkC4;                     // +0xc4
    int unkC8;                     // +0xc8
    int unkCC;                     // +0xcc
    unsigned char unkD0;           // +0xd0
    unsigned char m_bd1;           // +0xd1

    FNV_bhkBaseCinfo();
};

struct FUN_00c681c0_bhkWorldCinfo : public FNV_bhkBaseCinfo
{
    FUN_00c681c0_bhkWorldCinfo();
};

// Constructs a bhkWorldCinfo by initializing the vtable, scalar fields, and a vector with constant values.
// @fnv 0x00c681c0
FUN_00c681c0_bhkWorldCinfo::FUN_00c681c0_bhkWorldCinfo() : FNV_bhkBaseCinfo()
{
    m_vtbl = &FNV_vtbl_010c3c44;
    m_b29 = 0;
    m_f54 = FNV_k_0101e2bc.f;
    m_f24 = FNV_k_0104da48.f;
    m_vec = _mm_setr_ps(FNV_k_01011d78.f, FNV_k_011afed4.f, FNV_k_01011d78.f, FNV_k_01011d78.f);
    m_bd1 = FNV_b_011afe5c;
    m_ba7 = 0;
    m_b28 = 3;
    m_f68 = FNV_f_01267b38;
}

struct Thing
{
    int unk00;
    int unk04;
    int m_iValue;
};

struct Stream
{
    void FUN_00a63460();
    Thing* FUN_00a63430();
};

struct FirstPart
{
    int m_i00;
};

struct ObjBase
{
    int m_i00;
};

struct Derived : FirstPart, ObjBase
{
    int m_i08;
    int m_iFirst;
    int m_iSecond;
};

struct FUN_00c89860_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual ObjBase* Resolve(int* apOut);

    void bhkSerializable_LinkObject(Stream* apStream);
    void bhkConstraint_LinkObject(Stream* apStream);
};

// Reads two Thing values from apStream, resolves a Derived object, and stores the values into m_iFirst and m_iSecond before calling FUN_00c87670.
// @fnv 0x00c89860
// src: XBOX_PDB 0x00c89860
void FUN_00c89860_cls::bhkConstraint_LinkObject(Stream* apStream)
{
    apStream->FUN_00a63460();
    Thing* pFirst = apStream->FUN_00a63430();
    Thing* pSecond = apStream->FUN_00a63430();

    int iOut;
    Derived* pObject = static_cast<Derived*>(Resolve(&iOut));

    if (pFirst != 0)
    {
        pObject->m_iFirst = pFirst->m_iValue;
        pObject->m_iSecond = (pSecond != 0) ? pSecond->m_iValue : 0;
    }

    bhkSerializable_LinkObject(apStream);
}

struct S_00ca76b0_Obj
{
    virtual void vfn_00();
    virtual void vfn_04();
    long m_rc;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    void FUN_00a67000();
};

struct S_00ca76b0_Elem
{
    S_00ca76b0_Obj* p;
    int x;
    S_00ca76b0_Elem()
    {
        p = 0;
        x = 0;
    }
    ~S_00ca76b0_Elem()
    {
        if (p && !InterlockedDecrement(&p->m_rc))
            p->vfn_04();
    }
    S_00ca76b0_Elem& operator=(const S_00ca76b0_Elem& o)
    {
        if (p != o.p)
        {
            if (p && !InterlockedDecrement(&p->m_rc))
                p->vfn_04();
            p = o.p;
            if (p)
                InterlockedIncrement(&p->m_rc);
        }
        x = o.x;
        return *this;
    }
};

// This element carries both a reference and a second dword; its original
// SetAt updates the extent without treating either field as an empty slot.
template <> void NiTLargeArray<S_00ca76b0_Elem, NiTNewInterface<S_00ca76b0_Elem> >::SetSize(unsigned int);
template <> __declspec(noinline) void NiTLargeArray<S_00ca76b0_Elem, NiTNewInterface<S_00ca76b0_Elem> >::SetAt(unsigned int index, const S_00ca76b0_Elem& value)
{
    if (index >= m_uiSize)
        m_uiSize = index + 1;
    m_pBase[index] = value;
}

struct S_00ca76b0_Holder
{
    int unk00;
    int unk04;
    NiTLargeObjectArray<S_00ca76b0_Elem> arr;
};

struct S_00ca76b0_Stream
{
    int unk00;
    unsigned int unk04;
    unsigned int FUN_00a63460();
    S_00ca76b0_Obj* FUN_00a63430();
};

struct S_00ca76b0_Cls
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual S_00ca76b0_Holder* vfn_b4(char* flag);
    void bhkShape_LinkObject(S_00ca76b0_Stream* s);
    void bhkNiTriStripsShape_LinkObject(S_00ca76b0_Stream* s);
};

// Reads a count and objects from s, conditionally prepares the holder array, fills entries, and calls FUN_00c84cc0.
// @fnv 0x00ca76b0
// src: XBOX_PDB 0x00ca76b0
void S_00ca76b0_Cls::bhkNiTriStripsShape_LinkObject(S_00ca76b0_Stream* apStream)
{
    char flag;
    S_00ca76b0_Holder* h = vfn_b4(&flag);
    unsigned int count = apStream->FUN_00a63460();
    if (apStream->unk04 < 2)
    {
        NiTLargeObjectArray<S_00ca76b0_Elem>* arr = &h->arr;
        arr->SetSize(count);
        for (unsigned int i = 0; i < count; i++)
        {
            const S_00ca76b0_Elem tmp;
            arr->Add(tmp);
        }
    }
    for (unsigned int i = 0; i < count; i++)
    {
        S_00ca76b0_Obj* o = apStream->FUN_00a63430();
        o->FUN_00a67000();
        S_00ca76b0_Obj*& slot = h->arr.m_pBase[i].p;
        S_00ca76b0_Obj* old = slot;
        if (old != o)
        {
            if (old && !InterlockedDecrement(&old->m_rc))
                old->vfn_04();
            slot = o;
            if (o)
                InterlockedIncrement(&o->m_rc);
        }
    }
    bhkShape_LinkObject(apStream);
}


struct ExtraBase
{
    void LinkObject(NiStream& stream);
};

struct LinkedHolder : ExtraBase
{
    void AddLinked(NiObject* pObj);
    void LinkObjects(NiStream& stream);
};

// Links the holder's own object and then adds each loaded object from the link stream as a linked object.
// @fnv 0x00cc21f0
void LinkedHolder::LinkObjects(NiStream& stream)
{
    AutoMemContext guard(0x10);
    ExtraBase::LinkObject(stream);
    unsigned int ItemUpdateArray = stream.GetLinkID();
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        NiObject* pObj = stream.GetLoadedObject();
        if (pObj)
            AddLinked(pObj);
    }
}

struct S_00cc4870_Stream
{
    int FUN_00a63460();
    int FUN_00a63430();
};
struct S_00cc4870
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4(char* out);
    void bhkConstraint_LinkObject(S_00cc4870_Stream* stream);
    void bhkBreakableConstraint_LinkObject(S_00cc4870_Stream* stream);
};
// Calls vfn_b4 and FUN_00c89860, then calls FUN_00a63460 once and FUN_00a63430 twice.
// @fnv 0x00cc4870
// src: XBOX_PDB 0x00cc4870
void S_00cc4870::bhkBreakableConstraint_LinkObject(S_00cc4870_Stream* stream)
{
    char tmp;
    vfn_b4(&tmp);
    bhkConstraint_LinkObject(stream);
    stream->FUN_00a63460();
    stream->FUN_00a63430();
    stream->FUN_00a63430();
}

namespace fnv_00a64df0 {
#include <windows.h>


}  // namespace fnv_00a64df0
// @fnv 0x00a64df0
void NiStream::ReadFixedString(NiFixedString& result)
{
    unsigned int id;
    m_pkIstr->Read(&id, 4);
    if (id == 0xffffffffu)
        result = static_cast<const char*>(0);
    else
        result = m_kFixedStrings.m_pBase[id];
}

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* section);

struct S_00c68150_Lock
{
    void* m_debugInfo;
    long m_lLockCount;
    long m_recursionCount;
    void* m_owningThread;
    void* m_lockSemaphore;
    unsigned long m_spinCount;
    ~S_00c68150_Lock()
    {
        DeleteCriticalSection(this);
    }
};

struct S_00c68150_Elem
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
    ~S_00c68150_Elem();
};

struct FUN_00c68150
{
    S_00c68150_Lock m_lock;
    S_00c68150_Elem m_entries[16];
    ~FUN_00c68150();
};

// Destroys the object, releasing the critical section and the 16-entry array via the member destructors.
// @fnv 0x00c68150
FUN_00c68150::~FUN_00c68150()
{}

// Stores object at index, extends m_uiSize to index + 1 when needed, and adjusts m_uiESize based on the slot and object.
// @fnv 0x00cc1a10
template <> void NiTLargeArray<NiPointer<NiObject>, NiTNewInterface<NiPointer<NiObject> > >::SetAt(unsigned int index, const NiPointer<NiObject>& object) throw()
{
    if (index >= m_uiSize)
    {
        m_uiSize = index + 1;
        if (object != NiPointer<NiObject>(0))
            ++m_uiESize;
    }
    else
    {
        if (object != NiPointer<NiObject>(0))
        {
            if (m_pBase[index] == NiPointer<NiObject>(0))
                ++m_uiESize;
        }
        else
        {
            if (m_pBase[index] != NiPointer<NiObject>(0))
                --m_uiESize;
        }
    }
    m_pBase[index] = object;
}
