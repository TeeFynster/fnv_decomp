#include "../../../../include/hkArray.h"
#include "../../../../include/hkError.h"
#include "../../../../include/hkMemoryAllocator.h"
#include "../../../../include/hkOstream.h"
#include "../../../../include/hkReferencedObject.h"
#include "../../../../include/hkStringPtr.h"
#include "../../../../include/hkStringBuf.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/hkMemoryRouter.h"
#include "../../../../include/hkBool.h"
#include "../../../../include/hkVisualDebugger.h"
#include "../../../../include/hkVtableClassRegistry.h"
#include "../../../../include/hkSocket.h"
#include "../../../../include/hkStreamWriter.h"
#include "../../../../include/hkFileSystem.h"
#include "../../../../include/hkProcessHandler.h"

// src/havok/common/visualize/hkvisualdebugger.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/hkvisualdebugger.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

template <class T> inline T& routerHeap(hkMemoryRouter& router)
{
    return *reinterpret_cast<T*>(router.m_heap);
}

// Deletes every client that has no socket, which are the capture-file clients.
// @fnv 0x00cd12b0
void hkVisualDebugger::endCapture()
{
    for (int i = m_clients.m_size - 1; i >= 0; --i)
        if (m_clients.m_data[i].m_socket == 0)
            deleteClient(i);
}

// This 20-byte Havok factory object shares the allocator, not the scene-node layout.
struct VisualDebuggerFactoryObject
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    static void* __cdecl operator new(unsigned int size)
    {
        return BSFadeNode::operator new(size);
    }
    VisualDebuggerFactoryObject();
    ~VisualDebuggerFactoryObject();
};
// Allocates and constructs a VisualDebuggerFactoryObject object and returns it as a BSFadeNode pointer.
// @fnv 0x00ccf890
// src: EXE 0x00ccf890
BSFadeNode* bhkConvexListShape_CreateObject()
{
    return reinterpret_cast<BSFadeNode*>(new VisualDebuggerFactoryObject);
}

// @fnv 0x00cd1e40
hkVisualDebugger* hkVisualDebugger::FUN_00cd1e40(unsigned int flags)
{
    this->hkVisualDebugger::~hkVisualDebugger();

    if (flags & 1)
    {
        hkMemoryRouter* router = &hkMemoryRouter::getInstance();
        reinterpret_cast<hkMemoryAllocator*>(router->m_heap)->blockFree(this, m_usMemSizeAndFlags);
    }

    return this;
}

extern hkError* DAT_01268360;

// The shared socket header omits listen; the original call uses vtable +0x20.
inline int listenDebuggerSocket(hkSocket* socket, int port)
{
    typedef int (__thiscall* Listen)(hkSocket*, int);
    return (*reinterpret_cast<Listen**>(socket))[8](socket, port);
}
extern hkSocket*(__cdecl* DAT_011b3df0)();

// Creates the debugger's socket server if absent, listens on iListenPort, and reports the outcome via DAT_01268360->message.
// @fnv 0x00cd0d00
void hkVisualDebugger::serve(int iListenPort)
{
    DAT_01268360->beginSection(0x1293ade8, "Serving");
    if (!m_server)
    {
        m_server = DAT_011b3df0();
        if (m_server)
        {
            listenDebuggerSocket(m_server, iListenPort);
            unsigned int auiReportBuf[0x80];
            unsigned int streamStorage[sizeof(hkOstream) / sizeof(unsigned int)];
            hkOstream& kReportStream = *reinterpret_cast<hkOstream*>(streamStorage);
            kReportStream.FUN_00cb1600(auiReportBuf, sizeof(auiReportBuf));
            kReportStream.ProcessAndReturnValue_00cc01c0("Server created and will poll for new client(s) on port ")
                .WriteInt(iListenPort)
                .ProcessAndReturnValue_00cc01c0(" every frame");
            DAT_01268360->message(0, -1, (char*)auiReportBuf, ".\\hkVisualDebugger.cpp", 103);
            kReportStream.FUN_00cc00e0();
        }
        else
        {
            unsigned int auiReportBuf[0x80];
            unsigned int streamStorage[sizeof(hkOstream) / sizeof(unsigned int)];
            hkOstream& kReportStream = *reinterpret_cast<hkOstream*>(streamStorage);
            kReportStream.FUN_00cb1600(auiReportBuf, sizeof(auiReportBuf));
            kReportStream.ProcessAndReturnValue_00cc01c0(
                "Server could not be created, please check that you platform supports sockets with the hkBase library");
            DAT_01268360->message(0, -1, (char*)auiReportBuf, ".\\hkVisualDebugger.cpp", 107);
            kReportStream.FUN_00cc00e0();
        }
    }
    else
    {
        unsigned int auiReportBuf[0x80];
        unsigned int streamStorage[sizeof(hkOstream) / sizeof(unsigned int)];
        hkOstream& kReportStream = *reinterpret_cast<hkOstream*>(streamStorage);
        kReportStream.FUN_00cb1600(auiReportBuf, sizeof(auiReportBuf));
        kReportStream.ProcessAndReturnValue_00cc01c0(
            "Server has already been created, only one server allowed per visual debugger instance");
        DAT_01268360->message(0, -1, (char*)auiReportBuf, ".\\hkVisualDebugger.cpp", 112);
        kReportStream.FUN_00cc00e0();
    }
    DAT_01268360->endSection();
}

class hkStateCD0E
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual bool isActive();
};

class hkTargetCD0E
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void activate();
};

class hkControllerCD0E
{
  public:
    void hkOArchive_write32u(int mode);
    void hkOArchive_write8u(unsigned int flags);
    void HashUInt(float t);
    hkTargetCD0E* hkOArchive_getStreamWriter();
};

class hkItemCD0E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkStateCD0E m_uiContentCount;
    int unk10;
    int unk14;
    hkControllerCD0E* m_controller;
};

// Client record at debugger +0x10: socket key and process handler; no shared hkEntry definition exists.
struct DebuggerClientEntry
{
    int m_key;
    hkItemCD0E* m_item;
};

class hkOwnerCD0E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DebuggerClientEntry* m_entries;

    void ActivateEntry(int i, float t);
};

// @fnv 0x00cd0e00
void hkOwnerCD0E::ActivateEntry(int aiIndex, float t)
{
    DebuggerClientEntry& e = m_entries[aiIndex];
    if (e.m_item->m_uiContentCount.isActive())
    {
        hkControllerCD0E* c = e.m_item->m_controller;
        c->hkOArchive_write32u(5);
        c->hkOArchive_write8u(0);
        c->HashUInt(t);
        c->hkOArchive_getStreamWriter()->activate();
    }
}

template <class T> inline int indexOfCD11(const hkVisualDebugger::Array<T>& a, const T& t)
{
    for (int i = 0; i < a.m_size; i++)
    {
        if (a.m_data[i] == t)
            return i;
    }
    return -1;
}

template <class T> inline void removeAtCD11(hkVisualDebugger::Array<T>& a, int iIndex)
{
    a.m_size--;
    if (a.m_size != iIndex)
        a.m_data[iIndex] = a.m_data[a.m_size];
}

// Finds callback in the callback array and, if present, removes it and the matching user handle.
// @fnv 0x00cd1140
void hkVisualDebugger::removeTrackedObjectCallback(hkVisualDebuggerTrackedObjectCallback callback)
{
    int iIndex = indexOfCD11(m_trackCallbacks, callback);
    if (iIndex >= 0)
    {
        removeAtCD11(m_trackCallbacks, iIndex);
        removeAtCD11(m_trackCallbackHandles, iIndex);
    }
}

namespace fnv_00cd11a0 {

extern hkError* DAT_01268360;

}  // namespace fnv_00cd11a0

// @fnv 0x00cd11a0
void hkVisualDebugger::shutdown() throw()
{
    fnv_00cd11a0::DAT_01268360->beginSection(0x1293adef, "Shuting down Visual Debugger..");
    for (int i = m_clients.m_size - 1; i >= 0; --i)
    {
        writeStep(i, 0.0f);
        deleteClient(i);
        unsigned int auiReportBuf[0x80];
        unsigned int streamStorage[sizeof(hkOstream) / sizeof(unsigned int)];
        hkOstream& kReportStream = *reinterpret_cast<hkOstream*>(streamStorage);
        kReportStream.FUN_00cb1600(auiReportBuf, sizeof(auiReportBuf));
        kReportStream.ProcessAndReturnValue_00cc01c0("Client deleted.");
        fnv_00cd11a0::DAT_01268360->message(0, -1, (char*)auiReportBuf, ".\\hkVisualDebugger.cpp", 81);
        kReportStream.FUN_00cc00e0();
    }
    if (m_server)
    {
        delete m_server;
        m_server = 0;
        unsigned int auiReportBuf[0x80];
        unsigned int streamStorage[sizeof(hkOstream) / sizeof(unsigned int)];
        hkOstream& kReportStream = *reinterpret_cast<hkOstream*>(streamStorage);
        kReportStream.FUN_00cb1600(auiReportBuf, sizeof(auiReportBuf));
        kReportStream.ProcessAndReturnValue_00cc01c0("Server deleted.");
        fnv_00cd11a0::DAT_01268360->message(0, -1, (char*)auiReportBuf, ".\\hkVisualDebugger.cpp", 88);
        kReportStream.FUN_00cc00e0();
    }
    fnv_00cd11a0::DAT_01268360->endSection();
}

void __cdecl ResizeAudioStream(void*, void*, int);

// @fnv 0x00cd12e0
__declspec(noinline) void hkVisualDebugger::addDefaultProcess(const char* processName) throw()
{
    Array<hkStringPtr>* array = &m_defaultProcesses;
    hkMemoryRouter* router = &hkMemoryRouter::getInstance();
    if (array->m_size == (array->m_capacityAndFlags & 0x3fffffff))
    {
        ResizeAudioStream(router->m_heap, array, sizeof(hkStringPtr));
    }
    hkStringPtr* item = array->m_data + array->m_size;
    if (item != 0)
    {
        item->FUN_00cb0a60();
    }
    item = array->m_data + array->m_size++;
    *item = processName;
}

namespace fnv_00cd1330 {
void ResizeAudioStream(void*, void*, int);

template <typename T> inline T& allocatePairCD13(hkVisualDebugger::Array<T>& a)
{
    void* heap = hkMemoryRouter::getInstance().m_heap;
    if (a.m_size == (a.m_capacityAndFlags & 0x3FFFFFFF))
    {
        fnv_00cd1330::ResizeAudioStream(heap, &a, sizeof(T));
    }
    return a.m_data[a.m_size++];
}
}  // namespace fnv_00cd1330

// @fnv 0x00cd1330
void hkVisualDebugger::addTrackedObject(void* obj, const hkClass* klass, const char* group, unsigned long tagId)
{
    hkVisualDebuggerTrackedObject& e = fnv_00cd1330::allocatePairCD13(m_trackedObjects);
    e.m_ptr = obj;
    e.m_class = klass;
    e.m_tag = tagId;

    for (int i = 0; i < m_trackCallbacks.m_size; ++i)
    {
        m_trackCallbacks[i](obj, klass, true, tagId, m_trackCallbackHandles[i]);
    }
}

template <int SIZE> __forceinline void memCpyOneAlignedXcd13c0(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T> __forceinline void addBackXcd13c0(hkVisualDebugger::Array<T>& a, const T& e)
{
    hkMemoryRouter& router = hkMemoryRouter::getInstance();
    if (a.m_size == a.getCapacity())
        ResizeAudioStream(router.m_heap, &a, sizeof(T));
    memCpyOneAlignedXcd13c0<sizeof(T)>(a.m_data + a.m_size, &e);
    a.m_size++;
}

// Appends the callback and its user handle to the two parallel callback arrays.
// @fnv 0x00cd13c0
void hkVisualDebugger::addTrackedObjectCallback(hkVisualDebuggerTrackedObjectCallback callback, void* userHandle)
{
    addBackXcd13c0(m_trackCallbacks, callback);
    addBackXcd13c0(m_trackCallbackHandles, userHandle);
}

struct ItemCD17
{
    char unk00[0x38];
    int m_i38;
    int m_i3C;
};

struct EntryCD17
{
    int unk00;
    ItemCD17* m_pInventoryEntryData;
};

class SinkCD17
{
  public:
    int unk00;
    int m_i04;
    void Search(hkMemoryAllocator& kAlloc, int iValue, int iA, int iB);
};

class FUN_00cd1710_C
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    EntryCD17* m_pEntries;
    int m_iNumEntries;

    void hkVisualDebugger_getCurrentProcesses(SinkCD17* pkSink);
};

// For each entry with inventory data, calls pkSink->Search using m_i04, m_i38, and m_i3C.
// @fnv 0x00cd1710
// src: HAVOK_LIB 0x00cd1710
void FUN_00cd1710_C::hkVisualDebugger_getCurrentProcesses(SinkCD17* pkSink)
{
    int iEntryIndex = m_iNumEntries;
    for (int i = 0; i < iEntryIndex; i++)
    {
        EntryCD17& kEntry = m_pEntries[i];
        if (kEntry.m_pInventoryEntryData)
        {
            ItemCD17* pItem = kEntry.m_pInventoryEntryData;
            int iB = pItem->m_i3C;
            int iA = pItem->m_i38;
            int iValue = pkSink->m_i04;
            pkSink->Search(routerHeap<hkMemoryAllocator>(hkMemoryRouter::getInstance()), iValue, iA, iB);
        }
    }
}





template <typename T> __forceinline T* hkMemoryAllocator::_bufAlloc(int& n)
{
    int numBytes = n * sizeof(T);
    void* p = bufAlloc(numBytes);
    n = numBytes / (int)sizeof(T);
    return static_cast<T*>(p);
}

template <typename T> __forceinline void hkMemoryAllocator::_bufFree(void* p, int n)
{
    bufFree(p, n * sizeof(T));
}

template <typename T> __forceinline void destructVdb(T* pArr, int n) throw()
{
    for (int i = 0; i < n; i++)
        pArr[i].~T();
}

template <class T> __forceinline void copyVdb(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}

template <typename T> __forceinline hkVisualDebugger::Array<T>::~Array() throw()
{
    hkMemoryAllocator& kAlloc = routerHeap<hkMemoryAllocator>(hkMemoryRouter::getInstance());
    destructVdb(m_data, m_size);
    m_size = 0;
    if ((m_capacityAndFlags & 0x80000000) == 0)
        kAlloc.bufFree(m_data, (m_capacityAndFlags & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_capacityAndFlags = 0x80000000;
}

template <typename T>
__forceinline hkVisualDebugger::Array<T>& hkVisualDebugger::Array<T>::operator=(const Array& a) throw()
{
    hkMemoryAllocator& alloc = routerHeap<hkMemoryAllocator>(hkMemoryRouter::getInstance());
    if (getCapacity() < a.getSize())
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
            alloc._bufFree<T>(m_data, getCapacity());
        int n = a.getSize();
        m_data = alloc._bufAlloc<T>(n);
        m_capacityAndFlags = n;
    }
    m_size = a.getSize();
    copyVdb(m_data, a.m_data, m_size);
    return *this;
}

template <typename T> __forceinline void clearVdb(hkVisualDebugger::Array<T>& a) throw()
{
    destructVdb(a.m_data, a.m_size);
    a.m_size = 0;
}

class hkProcessContextVdb
{
  public:
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void SetOwnerPointer(hkVisualDebugger* pkOwner) throw();
};

// Destroys the visual debugger server by shutting it down, detaching process contexts, clearing default viewers, and releasing the class registry.
// @fnv 0x00cd1970
hkVisualDebugger::~hkVisualDebugger() throw()
{
    shutdown();
    for (int i = 0; i < m_contexts.getSize(); i++)
    {
        reinterpret_cast<hkProcessContextVdb*>(m_contexts[i])->SetOwnerPointer(0);
    }
    clearVdb(m_defaultProcesses);
    if (m_classReg)
    {
        m_classReg->removeReference();
    }
}

extern hkError* g_pkErrorCD1;

template <> __forceinline hkArray<char, hkContainerTempAllocator>::~hkArray()
{
    hkMemoryAllocator& kAlloc = *static_cast<hkMemoryAllocator*>(hkMemoryRouter::getInstance().m_temp);
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        kAlloc.bufFree(m_data, m_iCapacityState & 0x3fffffff);
}

__forceinline hkStringBuf::~hkStringBuf() throw()
{
}

// The shared writer header omits the const validity query; capture calls vtable +0x0c.
inline hkBool* isDebuggerWriterValid(const hkStreamWriter* writer, hkBool* result) throw()
{
    typedef hkBool* (__thiscall* IsValid)(const hkStreamWriter*, hkBool*);
    return (*reinterpret_cast<IsValid* const*>(writer))[3](writer, result);
}

extern hkFileSystem* g_pkFileSystemCD1;

// No shared hkServerProcessHandler header: its process-handler interface is at +0x08 in capture.
class hkServerProcessHandler
{
  public:
    virtual void v00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkProcessHandler m_kProcessHandler;
    int getProcessId(const char* pcName) throw()
    {
        return m_kProcessHandler.getProcessId(pcName);
    }
    void selectProcess(int aiAllocationTag) throw()
    {
        m_kProcessHandler.selectProcess(aiAllocationTag);
    }
};

inline const char* hkStringPtr::cString() const
{
    return reinterpret_cast<const char*>(reinterpret_cast<unsigned long>(m_pcText) & ~1);
}

// Opens a file writer for pcCaptureFilename, adds it as a client, selects default viewers, and logs the capture status via g_pkErrorCD1.
// @fnv 0x00cd1b20
void hkVisualDebugger::capture(const char* pcCaptureFilename) throw()
{
    g_pkErrorCD1->beginSection(0x1293ade7, "Capturing");

    hkStreamWriter* pkWriter = g_pkFileSystemCD1->OpenWriter(pcCaptureFilename);
    hkBool writerValid;
    if (pkWriter && *isDebuggerWriterValid(pkWriter, &writerValid))
    {
        {
            unsigned int reportBuf[128];
            hkOstream ostr(reportBuf, sizeof(reportBuf));
            ostr << "Capturing simulation state to '" << pcCaptureFilename << "'";
            g_pkErrorCD1->message(0, -1, (const char*)reportBuf, ".\\hkVisualDebugger.cpp", 125);
        }
        createClient(0, 0, pkWriter);
        static_cast<const hkStreamWriter*>(pkWriter)->removeReference();

        hkVisualDebuggerClient& kClient = m_clients[m_clients.getSize() - 1];
        hkStringBuf kViewerNames;
        kViewerNames = "Turning on the following viewers: [";
        for (int i = 0; i < m_defaultProcesses.getSize(); i++)
        {
            int aiAllocationTag = kClient.m_processHandler->getProcessId(m_defaultProcesses[i].cString());
            if (aiAllocationTag >= 0)
            {
                kViewerNames.appendJoin(" ", m_defaultProcesses[i].cString());
                kClient.m_processHandler->selectProcess(aiAllocationTag);
            }
        }
        kViewerNames += "]";
        {
            unsigned int reportBuf[128];
            hkOstream ostr(reportBuf, sizeof(reportBuf));
            ostr << kViewerNames.cString();
            g_pkErrorCD1->message(0, -1, (const char*)reportBuf, ".\\hkVisualDebugger.cpp", 147);
        }
    }
    else
    {
        unsigned int reportBuf[128];
        hkOstream ostr(reportBuf, sizeof(reportBuf));
        ostr << "Capture file '" << pcCaptureFilename << "' could not be opened for writing";
        g_pkErrorCD1->message(0, -1, (const char*)reportBuf, ".\\hkVisualDebugger.cpp", 151);
    }

    g_pkErrorCD1->endSection();
}

// Client record: two reference-counted pointers, unlike include/Pair.h's two integer values.
struct DebuggerClientReferences
{
    const hkReferencedObject* m_kPointA;
    const hkReferencedObject* m_kPointB;
};

inline void memCpy4_cd0e(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T> __forceinline void hkArrayBase<T>::removeAt(int index)
{
    m_iElementCount--;
    if (m_iElementCount != index)
        memCpy4_cd0e(m_data + index, m_data + m_iElementCount, sizeof(T));
}

struct Owner_cd0e
{
    int unk00, unk04, unk08, unk0C;
    hkArray<DebuggerClientReferences> m_pairs;
    void RemovePair(int index);
};

// Releases both nonnull references in the indexed pair, then removes that array entry.
// @fnv 0x00cd0e60
void Owner_cd0e::RemovePair(int index)
{
    DebuggerClientReferences& pair = m_pairs[index];
    if (pair.m_kPointB)
        pair.m_kPointB->removeReference();
    if (pair.m_kPointA)
        pair.m_kPointA->removeReference();
    m_pairs.removeAt(index);
}

inline void memCpy4_836(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T> inline void removeAt836(hkVisualDebugger::Array<T>& a, int index)
{
    a.m_size--;
    if (a.m_size != index)
        memCpy4_836(a.m_data + index, a.m_data + a.m_size, sizeof(T));
}

// Removes obj from the tracked objects and tells each tracked-object callback it was removed.
// @fnv 0x00cd10a0
void hkVisualDebugger::removeTrackedObject(void* obj)
{
    for (int i = 0; i < m_trackedObjects.getSize(); i++)
    {
        if (m_trackedObjects[i].m_ptr == obj)
        {
            removeAt836(m_trackedObjects, i);
            for (int j = 0; j < m_trackCallbacks.getSize(); j++)
                m_trackCallbacks[j](obj, 0, false, 0, m_trackCallbackHandles[j]);
            return;
        }
    }
}

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* heap, void* array, int numElements, int sizeOfElement) throw();
void __cdecl WriteCompilerInfo(void* p) throw();

template <class T> __forceinline T& allocateDebuggerEntry(hkArray<T>& a) throw()
{
    hkMemoryAllocator& heap = routerHeap<hkMemoryAllocator>(hkMemoryRouter::getInstance());
    int n = a.m_iElementCount;
    int newSize = n + 1;
    int cap = a.m_iCapacityState & 0x3fffffff;
    if (cap < newSize)
    {
        int cap2 = 2 * cap;
        if (newSize >= cap2)
            cap2 = newSize;
        hkArrayUtil__reserve(&heap, &a, cap2, sizeof(T));
    }
    a.m_iElementCount++;
    return a.m_data[n];
}

// The shared handler header leaves the argument-taking call at vtable +0x10 unnamed.
inline void enableDebuggerProcess(hkProcessHandler* handler, int id)
{
    typedef void (__thiscall* Enable)(hkProcessHandler*, int);
    return (*reinterpret_cast<Enable**>(handler))[4](handler, id);
}

struct Process_cd14
{
    int* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    hkProcessHandler m_viewer;
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
    static void* operator new(unsigned int nbytes) throw()
    {
        Process_cd14* p = (Process_cd14*)routerHeap<hkMemoryAllocator>(hkMemoryRouter::getInstance()).blockAlloc(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    Process_cd14* FUN_00d60f30(void* owner, void* a, void* b) throw();
    void VisitEntryNames() throw();
};

struct Entry_cd14
{
    const char* m_name;
    Process_cd14* m_process;
};

struct Server_cd14
{
    int unk00, unk04, unk08, unk0C;
    hkArray<Entry_cd14> m_entries;
    int m_pOwnerObject;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int* m_types;
    int m_numTypes;
    void ActivateEntry(int i, float t);
    void AddEntry(const char* name, void* a, void* b);
};

// Allocates a new entry in m_entries, initializes its process with owner and parameters, enables matching viewer types, and activates the entry.
// @fnv 0x00cd1440
void Server_cd14::AddEntry(const char* name, void* a, void* apCompilerInfo)
{
    if (apCompilerInfo)
        WriteCompilerInfo(apCompilerInfo);
    Entry_cd14& e = allocateDebuggerEntry(m_entries);
    e.m_name = name;
    e.m_process = ((Process_cd14*)Process_cd14::operator new(sizeof(Process_cd14)))
                      ->FUN_00d60f30(&m_pOwnerObject, a, apCompilerInfo);
    e.m_process->VisitEntryNames();
    for (int i = 0; i < m_numTypes; i++)
    {
        int type = m_types[i] & ~1;
        int id = e.m_process->m_viewer.getProcessId(reinterpret_cast<const char*>(type));
        if (id >= 0)
            enableDebuggerProcess(&e.m_process->m_viewer, id);
    }
    ActivateEntry(m_entries.m_iElementCount - 1, 0.0f);
}

extern const char DAT_010cafd8[];
extern const char DAT_010cae1c[];

// The shared socket header omits accept; polling calls vtable +0x28.
inline char* acceptDebuggerClient(hkSocket*& socket)
{
    typedef char* (__thiscall* Accept)(hkSocket*);
    return (*reinterpret_cast<Accept**>(socket))[10](socket);
}

// Stops the timer, reports a message and client data when available, then restarts the timer if frame timing is enabled.
// @fnv 0x00cd1520
void hkVisualDebugger::pollForNewClients()
{
    if (m_suppressPollForNewClients)
        return;

    if (m_amTimingFrame)
    {
        m_frameTimer.stop();
    }

    if (m_server)
    {
        char* client = acceptDebuggerClient(m_server);
        if (client)
        {
            int szBuffer[0x80];
            unsigned int streamStorage[sizeof(hkOstream) / sizeof(unsigned int)];
            hkOstream& ostr = *reinterpret_cast<hkOstream*>(streamStorage);
            ostr.FUN_00cb1600(szBuffer, sizeof(szBuffer));
            ostr.ProcessAndReturnValue_00cc01c0(DAT_010cafd8);
            DAT_01268360->message(0, -1, (char*)szBuffer, DAT_010cae1c, 0xe8);
            ostr.FUN_00cc00e0();
            createClient(reinterpret_cast<hkSocket*>(client), reinterpret_cast<hkStreamReader*>(client + 8),
                         reinterpret_cast<hkStreamWriter*>(client + 0x14));
        }
    }

    if (m_amTimingFrame)
    {
        m_frameTimer.start();
    }
}

extern hkError* g_pkErrorC17;

void __cdecl hkVisualDebuggerInitFactoryC17() throw();

// @fnv 0x00cd1780
hkVisualDebugger::hkVisualDebugger(const Array<hkProcessContext*>& kContexts, const hkVtableClassRegistry* pkClassReg) throw()
    : m_server(0), m_suppressPollForNewClients(false), m_classReg(pkClassReg), m_amTimingFrame(false),
      m_frameTimer("Frame Timer")
{
    m_contexts = kContexts;
    for (int i = 0; i < m_contexts.getSize(); i++)
        reinterpret_cast<hkProcessContextVdb*>(m_contexts[i])->SetOwnerPointer(this);

    g_pkErrorC17->beginSection(0x1293adef, "Visual Debugger");
    {
        unsigned int reportBuf[128];
        hkOstream ostr(reportBuf, sizeof(reportBuf));
        ostr << "VDB Server instance has been created";
        g_pkErrorC17->message(0, -1, (const char*)reportBuf, ".\\hkVisualDebugger.cpp", 0x28);
    }
    hkVisualDebuggerInitFactoryC17();
    addDefaultProcess("Debug Display");
    addDefaultProcess("Shapes");
    addDefaultProcess("MousePicking");
    if (m_classReg)
        m_classReg->addReference();
    g_pkErrorC17->endSection();
}

namespace fnv_00cd1610 {
struct DefaultProcessSlot
{
    unsigned int taggedPtr;
    void Object_UpdateFields_00cb0c00();
};
extern "C" int __cdecl hkString_strCmp(unsigned int taggedObject, unsigned int wanted);

extern "C" hkError* DAT_01268360;
struct FUN_00cd1610_cls
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
    DefaultProcessSlot* m_processes;
    int m_uiItemCount;
    void hkVisualDebugger_removeDefaultProcess(unsigned int wanted);
};
// Removes the process slot matching wanted from m_processes, or logs an error via DAT_01268360 if it is not found.
// @fnv 0x00cd1610
// src: HAVOK_LIB 0x00cd1610
void FUN_00cd1610_cls::hkVisualDebugger_removeDefaultProcess(unsigned int wanted)
{
    for (int i = 0; i < m_uiItemCount; ++i)
    {
        unsigned int current = m_processes[i].taggedPtr;
        if (hkString_strCmp(current & ~1u, wanted) == 0)
        {
            m_processes[i].Object_UpdateFields_00cb0c00();
            --m_uiItemCount;
            if (m_uiItemCount != i)
            {
                DefaultProcessSlot& slotLast = m_processes[m_uiItemCount];
                m_processes[i] = slotLast;
            }
            return;
        }
    }
    DAT_01268360->beginSection(0x76565454, "removeDefaultProcess");
    unsigned int reportStorage[sizeof(hkOstream) / sizeof(unsigned int) + 128];
    hkOstream& message = *reinterpret_cast<hkOstream*>(reportStorage);
    char* reportBuffer = reinterpret_cast<char*>(reportStorage + sizeof(hkOstream) / sizeof(unsigned int));
    message.FUN_00cb1600(reportBuffer, 512);
    message.ProcessAndReturnValue_00cc01c0("The default Process'")
        .ProcessAndReturnValue_00cc01c0((const char*)wanted)
        .ProcessAndReturnValue_00cc01c0("', cannot not be removed from the default process list as it cannot be found!");
    DAT_01268360->message(0, -1, reportBuffer, ".\\hkVisualDebugger.cpp", 318);
    message.FUN_00cc00e0();
    DAT_01268360->endSection();
}
}  // namespace fnv_00cd1610
