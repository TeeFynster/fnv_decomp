
// src/havok/common/visualize/process/hkinspectprocess.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/process/hkinspectprocess.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/MemoryManager.h"
#include "../../../../../include/ProcessContext.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkArrayStreamWriter.h"
#include "../../../../../include/hkMemoryAllocator.h"
// hkMemoryRouterQ_hkinspectprocess: local type (was include/hkMemoryRouterQ.h, which had no evidence of one real class); no method of it is bound to a named game function
class hkMemoryRouterQ_hkinspectprocess
{
public:
    int unk00;
    int unk04;
    int unk08;
    union
    {
        int unk0C;
        int unk0c;
    };
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }

    hkMemoryAllocator& debug();
};
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkClass.h"
#include "../../../../../include/hkClassMember.h"
#include "../../../../../include/hkOArchive.h"
#include "../../../../../include/hkProcessFactory.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkVtableClassRegistry.h"
#include "../../../../../include/hkInspectProcess.h"
#include <new>

// These small Havok operations are inlined by this unit in the original build.

inline hkProcess::hkProcess(hkBool selectable)
{
    *reinterpret_cast<hkBool*>(&unk04) = selectable;
}
inline hkProcess::~hkProcess() throw()
{}

// @fnv 0x00ddb2f0
void __stdcall GetPunctuationChars(char** apOutString, int* apiLength)
{
    *apOutString = "!\"#$%";
    *apiLength = 5;
}

extern hkProcess* DAT_01269cd0;
extern hkInspectProcess* DAT_01269cd4;
void __cdecl hkInspectProcess_create(hkProcess*);
extern hkProcessFactory* hkProcessFactory_registerProcess;
// @fnv 0x00ddb750
void __cdecl RegisterObjectInspectionProcess()
{
    DAT_01269cd4 = hkProcessFactory_registerProcess->RegisterProcess("ObjectInspection", hkInspectProcess_create);
}



// If addObject is set, calls WriteObjectHeader with object, type and flags; otherwise calls RemovePair with object.
// @fnv 0x00ddb5d0
// src: HAVOK_LIB 0x00ddb5d0
void __cdecl myTrackedObjectCallback(void* object, int type, char addObject, int flags, hkInspectProcess* inspectProcess)
{
    if (addObject)
    {
        inspectProcess->WriteObjectHeader(object, reinterpret_cast<const hkClass*>(type), flags);
    }
    else
    {
        inspectProcess->RemovePair(object);
    }
}

void __cdecl CreateImpl(hkProcess*);
extern hkInspectProcess* DAT_01269cd8;

// @fnv 0x00ddc1a0
hkInspectProcess* __cdecl CreateStatisticsProcess()
{
    return DAT_01269cd8 = ((hkProcessFactory*)DAT_01269cd0)->RegisterProcess("Statistics", CreateImpl);
}


// @fnv 0x00ddbeb0
// src: GUESS 0x00ddbeb0 (confidence: low)
hkInspectProcess* hkInspectProcess_GetDAT01269cd4()
{
    return DAT_01269cd4;
}

class hkSourceDDB6
{
  public:
    int unk00;
    void* m_target;

};

struct hkSourceListDDB6
{
    hkSourceDDB6** m_data;
    int m_iElementCount;
};

// The shared unk20/unk24/unk28 fields hold the inspection-pair array.
struct hkInspectArray
{
    void* m_data;
    int m_size;
    int m_capacityAndFlags;
    void initialize() throw()
    {
        m_data = 0;
        m_size = 0;
        m_capacityAndFlags = 0x80000000;
    }
};

void __cdecl myTrackedObjectCallback(void* userData);

// These callbacks are not yet declared by ProcessContext's shared layout.
extern "C" void FUN_00cd13c0();
extern "C" void FUN_00cd1140();
typedef void (__thiscall* AddInspectCallback)(ProcessContext*, void(__cdecl*)(void*), void*);
typedef void (__thiscall* RemoveInspectCallback)(ProcessContext*,
    void(__cdecl*)(void*, int, char, int, hkInspectProcess*));

// @fnv 0x00ddb600
hkInspectProcess::hkInspectProcess(const hkSourceListDDB6& sources) throw()
    : hkProcess(true)
{
    reinterpret_cast<hkInspectArray*>(&unk20)->initialize();
    context = sources.m_iElementCount > 0 ? (ProcessContext*)sources.m_data[0]->m_target : 0;
    if (context)
    {
        reinterpret_cast<hkReferencedObject*>(context)->addReference();
        reinterpret_cast<AddInspectCallback>(FUN_00cd13c0)(context, myTrackedObjectCallback, this);
    }
}

namespace fnv_00ddb670 {
extern "C" hkMemoryRouterQ_hkinspectprocess& __cdecl hkMemoryRouter_getInstance();

template <class T> __forceinline void destructDDB6(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

struct hkProcessObjectDDB6
{
    void* m_object;
    int unk04;
    int unk08;
};

struct hkInspectEntryDDB6
{
    int unk00;
    int unk04;
};

}  // namespace fnv_00ddb670

template <typename T>
__forceinline void hkArrayBase<T>::clear()
{
    fnv_00ddb670::destructDDB6(m_data, m_iElementCount);
    m_iElementCount = 0;
}

template <typename T>
__forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    clear();
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, getCapacity() * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <typename T>
__forceinline void hkArrayBase<T>::removeAt(int index)
{
    m_iElementCount--;
    if (m_iElementCount != index)
    {
        unsigned int* src = reinterpret_cast<unsigned int*>(m_data + m_iElementCount);
        unsigned int* dst = reinterpret_cast<unsigned int*>(m_data + index);
        int k = 0;
        do
        {
            dst[k] = src[k];
        } while (++k < (int)(sizeof(T) / 4));
    }
}

// @fnv 0x00ddb670
hkInspectProcess::~hkInspectProcess() throw()
{
    using namespace fnv_00ddb670;
    ProcessContext* pkContext = context;
    if (pkContext)
    {
        for (int i = 0; i < pkContext->unk2c; i++)
            RemovePair(reinterpret_cast<hkProcessObjectDDB6*>(pkContext->unk28)[i].m_object);
        reinterpret_cast<RemoveInspectCallback>(FUN_00cd1140)(context, myTrackedObjectCallback);
        reinterpret_cast<hkReferencedObject*>(context)->removeReference();
    }
    reinterpret_cast<hkArray<hkInspectEntryDDB6>*>(&unk20)->_clearAndDeallocate(fnv_00ddb670::hkMemoryRouter_getInstance().heap());
}

void* __cdecl hkMemoryRouter_getInstance();
// @fnv 0x00ddb710
// src: HAVOK_LIB 0x00ddb710
void* __cdecl hkInspectProcess_create(unsigned int value)
{
    hkMemoryRouterQ_hkinspectprocess* pCpuHolder = static_cast<hkMemoryRouterQ_hkinspectprocess*>(hkMemoryRouter_getInstance());
    hkInspectProcess* pCpuBlock =
        static_cast<hkInspectProcess*>(pCpuHolder->heap().blockAlloc(48));
    pCpuBlock->m_usMemSizeAndFlags = 48;
    pCpuBlock = ::new (pCpuBlock) hkInspectProcess(*reinterpret_cast<const hkSourceListDDB6*>(value));
    if (pCpuBlock)
        return reinterpret_cast<char*>(pCpuBlock) + 8;
    return 0;
}

inline void hkReferencedObject::operator delete(void* p)
{
    hkMemoryRouterQ_hkinspectprocess* mem = static_cast<hkMemoryRouterQ_hkinspectprocess*>(hkMemoryRouter_getInstance());
    mem->heap().blockFree(p, static_cast<hkReferencedObject*>(p)->m_usMemSizeAndFlags);
}

// Writes a 25-byte object header to the archive, resolving the actual class via the vtable registry when available.
// @fnv 0x00ddb310
int hkInspectProcess::WriteObjectHeader(void* object, const hkClass* pClassInfo, unsigned int flags)
{
    reinterpret_cast<hkOArchive*>(unk0c)->WriteUint32(25);
    const hkClass* pActualClass = pClassInfo;
    if (context->registry && pClassInfo->GetLastNodeFlag())
    {
        pActualClass = context->registry->GetClassFromVirtualInstance(object);
        if (!pActualClass)
            pActualClass = pClassInfo;
    }
    reinterpret_cast<hkOArchive*>(unk0c)->WriteUint8(33);
    reinterpret_cast<hkOArchive*>(unk0c)->WriteUint64(reinterpret_cast<unsigned int>(object));
    reinterpret_cast<hkOArchive*>(unk0c)->WriteUint64(reinterpret_cast<unsigned int>(pActualClass));
    reinterpret_cast<hkOArchive*>(unk0c)->WriteUint64(flags);
    return 25;
}

struct LayoutRulesDDB3
{
    unsigned char m_ucBytesInPointer;
    unsigned char m_bLittleEndian;
    unsigned char m_bReusePaddingOptimization;
    unsigned char m_bEmptyBaseClassOptimization;
};
extern const LayoutRulesDDB3 DAT_011b7b88;

class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126cae8;

struct TrackedObjectDDB3
{
    void* m_pvObject;
    int m_iType;
    int m_iFlags;
};

// Writes layout rules and each tracked object entry to the output archive.
// @fnv 0x00ddb3a0
void hkInspectProcess::init()
{
    if (!context)
        return;
    reinterpret_cast<hkOArchive*>(unk0c)->WriteUint32(0xd);
    reinterpret_cast<hkOArchive*>(unk0c)->WriteUint8(0x20);
    reinterpret_cast<hkOArchive*>(unk0c)->WriteInt64(reinterpret_cast<int>(&g_0126cae8), 0);
    reinterpret_cast<hkOArchive*>(unk0c)->WriteUint8(DAT_011b7b88.m_ucBytesInPointer);
    reinterpret_cast<hkOArchive*>(unk0c)->WriteUint8(DAT_011b7b88.m_bLittleEndian);
    reinterpret_cast<hkOArchive*>(unk0c)->WriteUint8(DAT_011b7b88.m_bReusePaddingOptimization);
    reinterpret_cast<hkOArchive*>(unk0c)->WriteUint8(DAT_011b7b88.m_bEmptyBaseClassOptimization);
    hkArray<TrackedObjectDDB3>& kObjects = *reinterpret_cast<hkArray<TrackedObjectDDB3>*>(&context->unk28);
    for (int i = 0; i < kObjects.GetLogicalSize(); i++)
    {
        TrackedObjectDDB3& kEntry = kObjects[i];
        WriteObjectHeader(kEntry.m_pvObject, kEntry.m_iType, kEntry.m_iFlags);
    }
}

namespace fnv_00ddb550 {
struct hkPairDDB5
{
    int m_key;
    int m_uiFilterValue;
};

}  // namespace fnv_00ddb550

// Writes a removal header and key, removes the matching inspection pair, and returns 9.
// @fnv 0x00ddb550
int hkInspectProcess::RemovePair(int iKey)
{
    using namespace fnv_00ddb550;
    reinterpret_cast<hkOArchive*>(unk0c)->WriteUint32(9);
    reinterpret_cast<hkOArchive*>(unk0c)->WriteUint8(0x22);
    reinterpret_cast<hkOArchive*>(unk0c)->WriteInt64(iKey, 0);
    for (int i = 0; i < unk24; i++)
    {
        if (reinterpret_cast<hkPairDDB5*>(unk20)[i].m_key == iKey)
        {
            reinterpret_cast<hkArray<hkPairDDB5>*>(&unk20)->removeAt(i);
            break;
        }
    }
    return 9;
}


void __cdecl ResizeAudioStream(hkMemoryAllocator* alloc, void* array, int sizeElem) throw();

template <typename T> struct hkArrQLocalForm
{ // local form of hkArray: 0x00ddb770 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrQLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArrQLocalForm()
    {
        ClearAndRelease();
    }

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }

    void _clearAndDeallocate(hkMemoryAllocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.bufFree(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void ClearAndRelease()
    {
        _clearAndDeallocate(static_cast<hkMemoryRouterQ_hkinspectprocess*>(hkMemoryRouter_getInstance())->heap());
    }

    void _pushBack(hkMemoryAllocator& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(&alloc, this, sizeof(T));
        }
        T* p = m_data + m_iElementCount;
        m_iElementCount++;
        *p = t;
    }
    void AddBack(const T& t)
    {
        _pushBack(static_cast<hkMemoryRouterQ_hkinspectprocess*>(hkMemoryRouter_getInstance())->heap(), t);
    }
};

struct hkLayoutRulesQ
{
    unsigned char m_ucBytesInPointer;
    unsigned char m_bLittleEndian;
    unsigned char m_bReusePaddingOptimization;
    unsigned char m_bEmptyBaseClassOptimization;
};

extern hkLayoutRulesQ DAT_010d6ae8;

// Constructor at 0x00dc1680 is hkStructureLayout; no shared header is available yet.
struct hkStructureLayout
{
    hkLayoutRulesQ m_kLayoutRules;
    hkStructureLayout(const hkLayoutRulesQ& rules) throw();
};

struct hkObjectPatchQ
{
    int unk00;
    int unk04;
    const void* m_object;
    int unk0C;
    const hkClass* m_class;
    int unk14;
};

struct hkWrittenObjectQ
{
    const void* m_object;
    const hkClass* m_class;
};

int __cdecl hkObjectSerialize_writeObject(hkArrayStreamWriter* writer, hkStructureLayout* layout, const void* object, int flags,
                         const void* original, const hkClass* pClassInfo, hkArrQLocalForm<hkObjectPatchQ>* patches) throw();

__forceinline int hkInspectProcess::sendRecursiveQ(const void* object, const hkClass* pClassInfo,
                                                   hkArrQLocalForm<hkWrittenObjectQ>* written) throw()
{
    return writeObject(object, pClassInfo, true, written);
}

// @fnv 0x00ddb770
// src: HAVOK_LIB 0x00ddb770
int hkInspectProcess::writeObject(const void* object, const hkClass* pClassInfo, hkBool recurse,
                                    hkArrQLocalForm<hkWrittenObjectQ>* written) throw()
{
    hkStructureLayout layout(DAT_010d6ae8);
    hkArrQLocalForm<hkObjectPatchQ> patches;

    const hkClass* realClass = pClassInfo;
    if (context->registry && pClassInfo->GetLastNodeFlag())
    {
        realClass = context->registry->GetClassFromVirtualInstance(object);
        if (!realClass)
        {
            realClass = pClassInfo;
        }
    }

    if (recurse)
    {
        int i;
        for (i = 0; i < written->GetLogicalSize(); i++)
        {
            if ((*written)[i].m_object == object)
            {
                break;
            }
        }
        if (i < written->GetLogicalSize())
        {
            return 0;
        }
        hkWrittenObjectQ w;
        w.m_object = object;
        w.m_class = realClass;
        written->AddBack(w);
    }

    hkArrQLocalForm<char> buffer;
    hkArrayStreamWriter writer(reinterpret_cast<hkCharArray*>(&buffer), 1);
    int size = hkObjectSerialize_writeObject(&writer, &layout, object, 0, object, realClass, &patches);
    if (size != buffer.GetLogicalSize() || size < 1)
    {
        return -1;
    }

    int total = size + 1;
    reinterpret_cast<hkOArchive*>(unk0c)->WriteUint32(total);
    reinterpret_cast<hkOArchive*>(unk0c)->WriteUint8(0x24);
    reinterpret_cast<hkOArchive*>(unk0c)->WriteRaw(buffer.m_data, buffer.GetLogicalSize());
    if (recurse)
    {
        for (int i = 0; i < patches.GetLogicalSize(); i++)
        {
            const void* obj = patches[i].m_object;
            const hkClass* cls = patches[i].m_class;
            total += sendRecursiveQ(obj, cls, written);
        }
    }
    return total;
}

namespace fnv_00ddb450 {
struct hkPathArray
{
    unsigned short* unk00;
};
static __forceinline int nextIndex(const hkPathArray* path, int i)
{
    return path->unk00[i + 1];
}
// Walks a hkPathArray through hkClassMember types to compute and return the pointer to a nested member within data.
// @fnv 0x00ddb450
// src: HAVOK_LIB 0x00ddb450
static __declspec(noinline) void* __cdecl _FindMemberItem(const hkClassMember* member, char* data, const hkPathArray* path,
                                                       int type, int aiIndex)
{
    char* p = data;
    for (;;)
    {
        switch (type)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 24:
        case 30:
        case 31:
        case 32:
            return p;
        case 14:
        case 15:
        case 16:
        case 17:
        case 18: {
            char* next = p + path->unk00[aiIndex + 1] * 16;
            type = 12;
            ++aiIndex;
            p = next;
        }
            continue;
        case 22:
        case 26: {
            int iIndex = path->unk00[aiIndex + 1];
            {
                char* next = *(char**)p + member->GetTagValue() * iIndex;
                type = member->m_eSubtype;
                ++aiIndex;
                p = next;
            }
            continue;
        }
        case 25: {
            if (!member)
                return 0;
            if (!member->m_class)
                return 0;
            const hkClass* k = member->GetClass();
            if (!k)
                return 0;
            member = &k->getMember(nextIndex(path, aiIndex));
            {
                char* next = p + member->m_offset;
                type = member->m_type;
                ++aiIndex;
                p = next;
            }
            continue;
        }
        case 20:
            return 0;
        default:
            return 0;
        }
    }
}

void* S00ddb450_Call(int type, char* data, const hkPathArray* path, int i, const hkClassMember* member)
{
    return _FindMemberItem(member, data, path, type, i);
}
}  // namespace fnv_00ddb450
