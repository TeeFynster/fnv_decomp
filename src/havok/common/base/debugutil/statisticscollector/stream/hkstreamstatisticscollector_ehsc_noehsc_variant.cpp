#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkMemoryRouter.h"

// src/havok/common/base/debugutil/statisticscollector/stream/hkstreamstatisticscollector_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/base/debugutil/statisticscollector/stream/hkstreamstatisticscollector.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/debugutil/statisticscollector/stream/hkstreamstatisticscollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/debugutil/statisticscollector/stream/hkstreamstatisticscollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct VirtualBase
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void Dispatch();
};
struct FUN_00ddf020_Class
{
    void __thiscall Dispatch_Thunk();
};
struct BSAudio;
BSAudio* __cdecl hkMemoryRouter_getInstance();
inline hkMemoryRouter* audio()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}
extern "C" void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* alloc, void* arr, int capacity, int elemSize);
extern "C" void __cdecl hkString_memCpy(void* dst, const void* src, int n);
union Swap16
{
    unsigned short u;
    unsigned char b[2];
};
inline void swap16(unsigned short* p)
{
    Swap16 in, out;
    in.u = *p;
    out.b[0] = in.b[1];
    out.b[1] = in.b[0];
    *p = out.u;
}
struct Record
{
    unsigned char type;
    unsigned char len;
    unsigned short a;
    unsigned short b;
};
struct Obj
{
    int pad[5];
    hkArray<char> m14;
    void SetData(const void* src, int n, hkBool swap);
};
void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize);
static int* _newCommand(hkArray<char>* a, int n);
int* __cdecl fnv_caller(hkArray<char>* a, int n);
inline void* operator new(size_t, void* p)
{
    return p;
}
struct MonitorNode;
struct MonitorChildren
{
    MonitorNode** data;
    int size;
    int capacity;
    void Search(void* heap, int index, MonitorNode** value, int count);
    __declspec(noinline) void CallWithFlag(void* heap, int index, MonitorNode** value)
    {
        Search(heap, index, value, 1);
    }
    MonitorNode*& back()
    {
        return data[size - 1];
    }
    void popBack()
    {
        --size;
    }
};
struct MonitorNode
{
    float value0, value1;
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned short count0, count1;
    int unk24, unk28, unk2c;
    MonitorChildren children;
    int unk3c, unk40, unk44, unk48;
    const char* name;
    int unk50, unk54;
    MonitorNode(MonitorNode* parent, const char* label, int type);
};
struct MonitorString
{
    unsigned int tagged;
    void InitializeTextHandle(const char* s);
    void FUN_00cb0bd0(const MonitorString& s);
    void Object_UpdateFields_00cb0c00();
};
struct MonitorStrings
{
    MonitorString* data;
    int size;
    int capacity;
};
extern "C" int __cdecl hkString_strCmp(const char* a, const char* b);
// src: HAVOK_LIB 0x00ddf070
static __declspec(noinline) MonitorNode* _newNode(const char* name, MonitorStrings* strings, MonitorNode* parent,
                                                      int first, int second)
{
    if (!name)
        name = "?";
    if (!second)
        second = first;
    MonitorNode* node = 0;
    for (int i = 0; parent && i < parent->children.size; ++i)
    {
        if (!hkString_strCmp(parent->children.data[i]->name, name))
        {
            node = parent->children.data[i];
            break;
        }
    }
    if (!node)
    {
        if (strings && name)
        {
            MonitorString text;
            text.InitializeTextHandle(name);
            void* heap = audio()->m_heap;
            if (strings->size == (strings->capacity & 0x3fffffff))
                ResizeAudioStream(heap, strings, 4);
            if (&strings->data[strings->size])
                strings->data[strings->size].FUN_00cb0bd0(text);
            ++strings->size;
            text.Object_UpdateFields_00cb0c00();
            name = (const char*)(strings->data[strings->size - 1].tagged & ~1u);
        }
        hkMemoryAllocator* allocator = audio()->m_heap;
        void* storage = allocator->blockAlloc(sizeof(MonitorNode));
        node = storage ? new (storage) MonitorNode(parent, name, 1) : 0;
    }
    ++node->count0;
    node->value0 += (float)first;
    ++node->count1;
    node->value1 += (float)second;
    return node;
}
void __cdecl AggregateChildValues(MonitorNode* node, MonitorStrings* strings);
// hkArray.h identifies hkMemoryRouter as the shared hkMemoryRouter definition:
// FUN_00c85750 is the TLS accessor, and its heap allocator is at +0x10.
template <class T, class Allocator> __forceinline hkArray<T, Allocator>::~hkArray()
{
    this->_clearAndDeallocate(hkMemoryRouter::getInstance().heap());
}
template <class T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
class ObjDDF9
{
  public:
    ~ObjDDF9() throw()
    {
        ClearItems();
    }
    void ClearItems() throw();
    static void operator delete(void* p, unsigned int nbytes)
    {
        hkMemoryRouter::getInstance().heap().blockFree(p, nbytes);
    }
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54;
};
void __stdcall hkStreamStatisticsCollector_makeTree(hkArray<ObjDDF9*>& kArray, int iParam) throw();
void __stdcall ClearAllItems(int iUnused0, int iUnused1);
extern int DAT_010d8040;
struct SubBase
{
    void FUN_00d06f50(int a1);
};
inline hkMemoryRouter* holderGet()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}
struct SpawnedHandle
{
    void* m_ptr;
    int m_uiFilterValue;
    unsigned int m_flags;
    SpawnedHandle()
    {}
    SpawnedHandle(void* p, int v, unsigned int f) : m_ptr(p), m_uiFilterValue(v), m_flags(f)
    {}
    void EnsureCapacity(void* allocator, int zero);
    int getCap() const
    {
        return (int)(m_flags & 0x3fffffff);
    }
    void SetSizeAndGrow(int n)
    {
        hkMemoryAllocator& alloc = hkMemoryRouter::getInstance().heap();
        if (getCap() < n)
        {
            int cap = 2 * getCap();
            hkArrayUtil__reserve(&alloc, this, n < cap ? cap : n, 1);
        }
        m_uiFilterValue = n;
    }
};
struct FUN_00ddf170_cls
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    SpawnedHandle m_14;
    SpawnedHandle m_20;

    FUN_00ddf170_cls* hkStreamStatisticsCollector_hkStreamStatisticsCollector(int a1, int a2);
};
int hkString_strLen(const char* s);
struct StrPacker
{
    int unk00, unk04, unk08, unk0c, unk10;
    hkArray<char> m14;
    void hkStreamStatisticsCollector_pushDir(const char* str);
};
struct FUN_00ddeff0
{
    int unk4;
    FUN_00ddeff0();
    virtual ~FUN_00ddeff0();
    void operator delete(void* p, unsigned int nbytes)
    {
        if (p)
            hkMemoryRouter::getInstance().heap().blockFree(p, nbytes);
    }
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
};
struct FUN_00ddf640_Cls : Obj
{
    unsigned char* hkStreamStatisticsCollector_popDir();
};

struct MonitorTreeNode
{
    void ClearItems();
};

extern char DAT_01063cbc;

template <class T> __forceinline void constructRange(T* p, int count, const T& value)
{
    for (int i = 0; i < count; ++i)
        p[i] = value;
}

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return audio()->heap();
}
template <class T> __forceinline void hkArrayBase<T>::popBack(int numElemsToRemove)
{
    m_iElementCount -= numElemsToRemove;
}
template <class T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& e)
{
    if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(&alloc, this, sizeof(T));
    T* p = m_data + m_iElementCount;
    constructRange(p, 1, e);
    m_iElementCount++;
}

struct MonitorTreeBuilder : Obj
{
    void hkStreamStatisticsCollector_makeTree(hkArray<MonitorNode*>* roots, MonitorStrings* strings);
};

// @fnv 0x00ddf740
// src: HAVOK_LIB 0x00ddf740
void MonitorTreeBuilder::hkStreamStatisticsCollector_makeTree(hkArray<MonitorNode*>* roots, MonitorStrings* strings)
{
    hkArray<MonitorNode*> stack;
    MonitorNode* top;
    if (roots->m_iElementCount > 0)
    {
        top = roots->m_data[0];
        while (roots->m_iElementCount > 1)
        {
            MonitorNode* p = roots->back();
            if (p)
            {
                ((MonitorTreeNode*)p)->ClearItems();
                audio()->m_heap->blockFree(p, sizeof(MonitorNode));
            }
            roots->popBack();
        }
    }
    else
    {
        void* storage = audio()->m_heap->blockAlloc(sizeof(MonitorNode));
        top = storage ? new (storage) MonitorNode(0, &DAT_01063cbc, 1) : 0;
        roots->pushBack(top);
    }
    stack.pushBack(top);

    for (int off = 0; off < m14.m_iElementCount;)
    {
        const Record* rec = (const Record*)(m14.m_data + off);
        const char* name = rec->len > 0 ? (const char*)rec + 6 : 0;
        int step = rec->len + 6;
        switch (rec->type)
        {
        case 'p':
            stack.popBack();
            break;
        case 'P': {
            MonitorNode* parent = stack.back();
            MonitorNode* child = _newNode(name, strings, parent, rec->a, rec->b);
            stack.pushBack(child);
            break;
        }
        case 'C':
            _newNode(name, strings, stack.back(), rec->a, rec->b);
            break;
        default:
            return;
        }
        off += step;
    }
    AggregateChildValues(top, strings);
}
