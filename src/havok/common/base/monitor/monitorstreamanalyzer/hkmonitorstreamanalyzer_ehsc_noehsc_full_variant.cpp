#include "../../../../../../include/hkArrayBase.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMonitorStreamAnalyzer.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}
__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkMemoryAllocator.h"




// The monitor's debug allocator is stored at +0x14, beyond the shared router prefix.
inline hkMemoryAllocator& monitorDebugHeap(hkMemoryRouter* manager)
{
    return **reinterpret_cast<hkMemoryAllocator**>(reinterpret_cast<char*>(manager) + 0x14);
}

// src/havok/common/base/monitor/monitorstreamanalyzer/hkmonitorstreamanalyzer_ehsc_noehsc_full_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/base/monitor/monitorstreamanalyzer/hkmonitorstreamanalyzer.cpp that match byte for byte only
// with VC9 SP1 and /MT /O2 /GS /EHs-c- /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


// src/havok/common/base/monitor/monitorstreamanalyzer/hkmonitorstreamanalyzer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/monitor/monitorstreamanalyzer/hkmonitorstreamanalyzer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Returns the smaller of the two float arguments.
// @fnv 0x00e0c260
// src: GAMEBRYO_LIB 0x00e0c260
float __cdecl NiMin_00e0c260(float a, float b)
{
    return (a < b) ? a : b;
}

// Returns the larger of the two float arguments.
// @fnv 0x00e0c290
float MaxFloat(float a, float b)
{
    return a > b ? a : b;
}

// @fnv 0x00e0c2c0
// src: HAVOK_LIB 0x00e0c2c0
int hkMonitorStreamAnalyzer_ThreadDrawInput_computePerThreadHeightToFit(int aiDividend, int aiDivisor, int c, int aiSubtrahend, int aiOffset, int aiUnused)
{
    return (aiDividend / aiDivisor - aiSubtrahend) / c - aiOffset;
}

// @fnv 0x00e0c2e0
unsigned int __fastcall RoundUpToNextPowerOfTwo(unsigned int uiValue)
{
    uiValue--;
    uiValue |= uiValue >> 1;
    uiValue |= uiValue >> 2;
    uiValue |= uiValue >> 4;
    uiValue |= uiValue >> 8;
    uiValue |= uiValue >> 16;
    return ++uiValue;
}

struct FUN_00e0f6e0
{
    int a;
    int b;
    int c;
    FUN_00e0f6e0();
};

// @fnv 0x00e0f6e0
FUN_00e0f6e0::FUN_00e0f6e0()
{
    a = 0;
    b = 0;
    c = 0x80000000;
}

struct FUN_00e0c310_s
{
    int hkMonitorStreamAnalyzer_getStreamBegin();
};

// @fnv 0x00e0c310
// src: HAVOK_LIB 0x00e0c310
int FUN_00e0c310_s::hkMonitorStreamAnalyzer_getStreamBegin()
{
    if (*(int*)((char*)this + 0x10) == 0)
        return 0;
    return *(int*)((char*)this + 0xc);
}

struct SubObject
{
    virtual void* unk00();
    virtual void* unk04();
    virtual void* unk08();
    virtual void* unk0c();
    virtual void __thiscall invoke(int* value, int mode);
};
struct FUN_00cc01a0_class
{
    int unk00;
    int unk04;
    SubObject* unk08;
    FUN_00cc01a0_class* __thiscall InvokeSubObject(int value);
};
// @fnv 0x00cc01a0
FUN_00cc01a0_class* __thiscall FUN_00cc01a0_class::InvokeSubObject(int value)
{
    unk08->invoke(&value, 1);
    return this;
}

struct Bins
{
    float weights[8];
    unsigned short counts[8];
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    double value;
    void Accumulate(struct AxisData* data, hkMonitorStream::TimerCommand* start, hkMonitorStream::TimerCommand* end);
};
struct AxisData
{
    int unk00;
    unsigned int xIndex;
    unsigned int yIndex;
    unsigned int mode;
    float xScale;
    float yScale;
};
// Adds scaled start-to-end deltas into the weight/count bins at data's x and y indices, and sets value from start based on mode.
// @fnv 0x00e0c5e0
void Bins::Accumulate(AxisData* pAxisData, hkMonitorStream::TimerCommand* start, hkMonitorStream::TimerCommand* end)
{
    unsigned int x = pAxisData->xIndex;
    if (x <= 7)
    {
        weights[x] += (float)(end->m_time0 - start->m_time0) * pAxisData->xScale;
        ++counts[x];
    }
    unsigned int y = pAxisData->yIndex;
    if (y <= 7)
    {
        weights[y] += (float)(end->m_time1 - start->m_time1) * pAxisData->yScale;
        ++counts[y];
    }
    unsigned int mode = pAxisData->mode;
    if (mode == 0)
        value = (double)start->m_time0 * pAxisData->xScale;
    else if (mode == 1)
        value = (double)start->m_time1 * pAxisData->yScale;
}

struct Node
{
    float value0;
    float value1;
    float value2;
    float value3;
    float value4;
    float value5;
    float value6;
    float value7;
    unsigned short flag0;
    unsigned short flag1;
    unsigned short flag2;
    unsigned short flag3;
    unsigned short flag4;
    unsigned short flag5;
    unsigned short flag6;
    unsigned short flag7;
    Node** children;
    int childCount;
};
// Multiplies the value at index by factor, clears the matching flag, and recurses into all children.
// @fnv 0x00e0c700
// src: HAVOK_LIB 0x00e0c700
void __cdecl reduceMainTree(Node* node, int index, float factor)
{
    (&node->value0)[index] *= factor;
    (&node->flag0)[index] = 0;
    for (int i = 0; i < node->childCount; ++i)
        reduceMainTree(node->children[i], index, factor);
}

extern "C" int __cdecl hkString_strLen(const char* str);

struct E0C860Node;

struct E0C860NodeArray
{
    E0C860Node** m_data;
    int m_iElementCount;

    E0C860Node*& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};

struct E0C860Node
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
    E0C860NodeArray m_children;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    const char* m_name;
    int m_flags;
};

// @fnv 0x00e0c860
int __cdecl GetTreeWidth(E0C860Node* node, int depth, int indent, bool onlyExpanded)
{
    int width = hkString_strLen(node->m_name) + depth * indent + 8;
    if (!onlyExpanded || (node->m_flags & 1))
    {
        for (int i = 0; i < node->m_children.GetLogicalSize(); i++)
        {
            int childWidth = GetTreeWidth(node->m_children[i], depth + 1, indent, onlyExpanded);
            if (childWidth > width)
                width = childWidth;
        }
    }
    return width;
}

inline void* operator new(unsigned int, void* p)
{
    return p;
}

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(hkMemoryAllocator* alloc, void* arr, int elemSize);
void __cdecl hkString_memCpy(void* dst, const void* src, int n);

struct S_e0ce00_Block
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
    S_e0ce00_Block();
};

struct S_e0ce00_Array
{
    S_e0ce00_Block* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline S_e0ce00_Block& AllocatePair(hkMemoryAllocator& alloc)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, sizeof(S_e0ce00_Block));
        new (m_data + m_iElementCount) S_e0ce00_Block;
        return m_data[m_iElementCount++];
    }
};


struct S_e0ce00
{
    S_e0ce00_Array* m_arrays;
    int unk4;
    int unk8;
    char* m_buf;
    int m_iElementCount;
    int m_iCapacityState;
    hkBool AppendBlock(const char* begin, const char* end, const S_e0ce00_Block& b);
};

// Appends a copy of the bytes from begin to end into m_buf at the current offset and records a block in m_arrays[b.unk18] with that offset and length.
// @fnv 0x00e0ce00
hkBool S_e0ce00::AppendBlock(const char* begin, const char* end, const S_e0ce00_Block& aBlock)
{
    int n = end - begin;
    if ((m_iCapacityState & 0x3fffffff) - m_iElementCount < n)
        return false;
    hkMemoryAllocator& alloc = hkMemoryRouter_getInstance()->heap();
    S_e0ce00_Array& arr = m_arrays[aBlock.unk18];
    S_e0ce00_Block& nb = arr.AllocatePair(alloc);
    nb = aBlock;
    nb.unk1C = m_iElementCount;
    nb.unk20 = nb.unk1C + n;
    int off = m_iElementCount;
    m_iElementCount = off + n;
    hkString_memCpy(m_buf + off, begin, n);
    return true;
}

namespace fnv_00e0d0a0 {
struct Entry
{
    void __thiscall FUN_00ddeff0(unsigned int flags);
};
void* __cdecl hkMemoryRouter_getInstance();
struct Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Entry** items;
    int count;
    unsigned int flags;
    void ClearItems();
};
// Calls FUN_00ddeff0(1) on each non-null item, resets count, and releases the items buffer via the device unless the high flag bit is set.
// @fnv 0x00e0d0a0
void Owner::ClearItems()
{
    int index = 0;
    int zero = 0;
    if (count > 0)
    {
        do
        {
            Entry* entry = items[index];
            if (entry != 0)
                entry->FUN_00ddeff0(1);
            ++index;
        } while (index < count);
    }
    count = zero;
    void* holder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* device = *(hkMemoryAllocator**)((char*)holder + 0x10);
    unsigned int mask = 0x80000000;
    unsigned int value = flags;
    count = zero;
    if ((mask & value) == 0)
    {
        unsigned int bytes = (value & 0x3fffffff) * 4;
        device->bufFree(items, bytes);
    }
    flags = mask;
    items = 0;
}
}  // namespace fnv_00e0d0a0

extern "C" void __cdecl reduceMainTree(void* object, int index, float amount);
extern "C" void __cdecl mergeSubTree(void* first, void* second, int index, int limit, float amount);
// Calls FUN_00e0c700 on first, then FUN_00e0d180 on first and second with index, limit and amount.
// @fnv 0x00e0d280
// src: HAVOK_LIB 0x00e0d280
void __cdecl hkMonitorStreamAnalyzer_mergeTreesForCombinedThreadSummary(void* first, void* second, int index, int limit, float amount)
{
    reduceMainTree(first, index, amount);
    mergeSubTree(first, second, index, limit, amount);
}

namespace fnv_00e0f800 {


hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
inline hkMemoryRouter* audio()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}

extern "C" void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* alloc, void* arr, int capacity, int elemSize);

extern float DAT_010eaa58;
extern float DAT_011bdd84;
extern char DAT_010cb2c0[];

typedef hkArray<char> hkArrayChar;

struct FUN_00e0f800
{
    hkArrayChar m00;
    hkArrayChar m0c;
    int m18;
    int m1c;
    void* m20;
    FUN_00e0f800(int n, int a, int b);
    void hkMonitorStreamAnalyzer_resetNumThreads(int a, int b);
};

// Sets DAT_011bdd84 to 16666.6f, reserves n elements in m0c, points m20 at DAT_010cb2c0, then calls FUN_00e0f710(a, b).
// @fnv 0x00e0f800
FUN_00e0f800::FUN_00e0f800(int aiCapacity, int a, int b)
{
    DAT_011bdd84 = 16666.6f;
    m0c.reserve(aiCapacity);
    m20 = DAT_010cb2c0;
    hkMonitorStreamAnalyzer_resetNumThreads(a, b);
}
}  // namespace fnv_00e0f800

int __cdecl Vsnprintf(char* buffer, unsigned int size, const char* format, ...);
void __cdecl hkOstream_printf(void* stream, const char* format, ...);

struct S_00e0bfe0_Item
{
    float values[8];
    unsigned short counts[8];
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    const char* name;
};

// Formats the item's name, max count and percentage into a buffer, then writes the values with nonzero counts to the stream.
// @fnv 0x00e0bfe0
void __cdecl WriteItemStats(void* stream, float totalTime, const S_00e0bfe0_Item* item)
{
    int maxCount = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (item->counts[i] && item->counts[i] > maxCount)
        {
            maxCount = item->counts[i];
        }
    }

    __declspec(align(64)) unsigned int buf[50];

    if (totalTime > 0.0f)
    {
        Vsnprintf((char*)buf, 200, "%s (%i) %4.1f%%", item->name, maxCount, (item->values[1] * 100.0) / totalTime);
    }
    else
    {
        Vsnprintf((char*)buf, 200, "%s (%i)", item->name, maxCount);
    }

    hkOstream_printf(stream, "%-34s%s", (char*)buf, "\t\t\t");

    for (int i = 0; i < 8; ++i)
    {
        if (item->counts[i] != 0)
        {
            hkOstream_printf(stream, "% 12.3f: ", item->values[i]);
        }
    }

    hkOstream_printf(stream, "\n");
}

extern "C" void __cdecl hkString_memSet(void* dst, int c, int n);

struct E0C150TgaHeader
{
    unsigned char m_idLength;
    unsigned char m_colorMapType;
    unsigned char m_imageType;
    unsigned char m_colorMapStartLo;
    unsigned char m_colorMapStartHi;
    unsigned char m_colorMapLengthLo;
    unsigned char m_colorMapLengthHi;
    unsigned char m_colorMapDepth;
    unsigned char m_xOriginLo;
    unsigned char m_xOriginHi;
    unsigned char m_yOriginLo;
    unsigned char m_yOriginHi;
    unsigned short m_fMaxFriction;
    unsigned short m_height;
    unsigned char m_bitsPerPixel;
    unsigned char m_descriptor;
};

struct E0C150Stream
{
    int write(const void* buf, int nbytes);
};

// Builds a 32-bit uncompressed TGA header from width and height, writes the header and pixel data to the stream, and returns true.
// @fnv 0x00e0c150
bool __cdecl WriteTgaImage(const void* pixels, E0C150Stream* stream, int width, int height)
{
    E0C150TgaHeader header;
    hkString_memSet(&header, 0, sizeof(header));
    header.m_imageType = 2;
    header.m_height = (unsigned short)height;
    header.m_fMaxFriction = (unsigned short)width;
    header.m_bitsPerPixel = 32;
    stream->write(&header, sizeof(header));
    stream->write(pixels, width * height * 4);
    return true;
}

class FUN_00e0c320_cls
{
  public:
    const char* m_pName;
    int m_i04;
    int m_i08;
    int m_i0c;
    float m_f10;
    float m_f14;
    int m_i18;
    int m_i1c;
    int m_i20;
    FUN_00e0c320_cls* InitHeading();
};

// @fnv 0x00e0c320
FUN_00e0c320_cls* FUN_00e0c320_cls::InitHeading()
{
    float one = 1.0f;
    float* pf10 = (float*)((char*)this + 0x10);
    float* pf14 = (float*)((char*)this + 0x14);
    m_pName = "Unknown Heading";
    m_i04 = 0;
    m_i08 = 1;
    m_i0c = 0;
    *pf10 = one;
    *pf14 = one;
    m_i18 = 0;
    m_i1c = 0;
    m_i20 = 0;
    return this;
}

struct S_00e0c750_Keys
{
    bool m_vStart;
    bool m_down;
    bool m_fMinimumU;
    bool m_fMaximumU;
};

struct S_00e0c750_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S_00e0c750_Node** m_children;
    int m_numChildren;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    S_00e0c750_Node* m_parent;
    const char* m_name;
    unsigned int m_expanded : 1;
};

// Moves from node p through the tree according to the keys flags (up, down, collapse, expand) and returns the resulting node.
// @fnv 0x00e0c750
S_00e0c750_Node* __cdecl NavigateTree(const S_00e0c750_Keys* keys, S_00e0c750_Node* pNode)
{
    S_00e0c750_Node* parent;
    parent = pNode;
    if (pNode == 0)
    {
        return 0;
    }
    if (keys->m_vStart)
    {
        S_00e0c750_Node* pParent;
        pParent = pNode->m_parent;
        S_00e0c750_Node* prev = pParent->m_children[0];
        if (prev != pNode)
        {
            for (int i = 0; i < pParent->m_numChildren; ++i)
            {
                if (pParent->m_children[i] == pNode)
                {
                    prev = pParent->m_children[i - 1];
                    break;
                }
            }
            while (prev->m_numChildren > 0 && prev->m_expanded)
            {
                prev = prev->m_children[prev->m_numChildren - 1];
            }
            parent = prev;
        }
        else if (pParent->m_parent)
        {
            parent = pParent;
        }
    }
    if (keys->m_down)
    {
        S_00e0c750_Node* c;
        c = parent;
        if (parent->m_numChildren > 0 && parent->m_expanded)
        {
            parent = parent->m_children[0];
        }
        else
        {
            for (;;)
            {
                for (int i = 0; i < c->m_parent->m_numChildren; ++i)
                {
                    if (c->m_parent->m_children[i] == c)
                    {
                        if (i < c->m_parent->m_numChildren - 1)
                        {
                            parent = c->m_parent->m_children[i + 1];
                            goto done_down;
                        }
                    }
                }
                if (!c->m_parent->m_parent)
                {
                    break;
                }
                c = c->m_parent;
            }
        done_down:;
        }
    }
    if (keys->m_fMinimumU)
    {
        if (parent->m_expanded)
        {
            parent->m_expanded = 0;
        }
        else if (parent->m_parent->m_parent)
        {
            parent = parent->m_parent;
            parent->m_expanded = 0;
        }
    }
    if (keys->m_fMaximumU)
    {
        if (0 == parent->m_expanded)
        {
            parent->m_expanded = 1;
        }
        parent->m_expanded = 1;
    }
    return parent;
}

struct E0CC40Node
{
    float m_iSlotIds[16];
    double m_base;
};

E0CC40Node* __cdecl findChildNode(E0CC40Node* node, double time, int axis);

// Walks down from hint (or root if hint is null or its axis value plus base is below time) via FUN_00e10820 until no child is returned, then returns the node.
// @fnv 0x00e0cc40
E0CC40Node* __cdecl FindNodeAtTime(E0CC40Node* root, E0CC40Node* hint, double time, int axis)
{
    E0CC40Node* node = hint;
    if (!node || !(node->m_iSlotIds[axis] + node->m_base >= time))
        node = root;
    while (node)
    {
        E0CC40Node* child = findChildNode(node, time, axis);
        if (!child)
            break;
        node = child;
    }
    return node;
}

// FUN_00e0ccf0 - a member function of the class that owns the spawned-entry array.
// The class layout is reconstructed from the code: +0x00 m_entries (SpawnedEntry*),
struct SpawnedEntry
{
    int unk00;
    int unk04;
    int unk08;
};

struct FUN_00e0ccf0_cls
{
    SpawnedEntry* m_entries;
    int m_uiItemCount;
    int unk08;
    int unk0C;
    int m_unk10;
    void hkMonitorStreamAnalyzer_reset();
};

// Proxy used to force MSVC 2008 to materialise the element address in a register
// (base + byte offset) instead of folding it into the store's addressing mode.
struct EntryRef
{
    SpawnedEntry* p;
    void operator=(int value)
    {
        p->unk04 = value;
    }
};

static __forceinline EntryRef MakeRef(SpawnedEntry* e)
{
    EntryRef r;
    r.p = e;
    return r;
}

// @fnv 0x00e0ccf0
// src: HAVOK_LIB 0x00e0ccf0
void FUN_00e0ccf0_cls::hkMonitorStreamAnalyzer_reset()
{
    m_unk10 = 0;
    int i = 0;
    if (m_uiItemCount > i)
    {
        unsigned int off = 0;
        do
        {
            SpawnedEntry* e = (SpawnedEntry*)((char*)m_entries + off);
            ++i;
            MakeRef(e) = 0;
            off += 12;
        } while (i < m_uiItemCount);
    }
}

struct Singleton
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* unk10;
};

struct Sink
{
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(void* a, int b, int c);
};

// @fnv 0x00e0cd20
void __cdecl ProcessRecords(unsigned char* pRecords, unsigned char* end, Sink* sink)
{
    while (pRecords < end)
    {
        unsigned int v = *(unsigned int*)pRecords;
        if (v < 10)
        {
            pRecords += 4;
            continue;
        }
        Singleton* pSingleton = (Singleton*)hkMemoryRouter_getInstance();
        sink->hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(pSingleton->unk10, (int)v, (int)v);
        char* s = *(char**)pRecords;
        switch (*s)
        {
        case 0x45:
        case 0x53:
        case 0x54:
        case 0x6c: {
            pRecords += 0xc;
            break;
        }
        case 0x4f: {
            int w = *(int*)(pRecords + 0xc);
            Singleton* g = (Singleton*)hkMemoryRouter_getInstance();
            sink->hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(g->unk10, w, w);
            pRecords += 0x10;
            break;
        }
        case 0x4c: {
            int w = *(int*)(pRecords + 0xc);
            Singleton* g = (Singleton*)hkMemoryRouter_getInstance();
            sink->hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(g->unk10, w, w);
            pRecords += 0x10;
            break;
        }
        case 0x4d: {
            pRecords += 8;
            break;
        }
        case 0x4e:
        case 0x50: {
            pRecords += 4;
            break;
        }
        case 0x70: {
            pRecords += 4;
            break;
        }
        default:
            return;
        }
    }
}


struct S_Flag
{
    char b;
    __forceinline S_Flag()
    {
        b = 0;
    }
    __forceinline S_Flag(const S_Flag& o)
    {
        b = o.b;
    }
};

void* __cdecl hkMonitorStreamAnalyzer_makeStatisticsTreeForMultipleFrames(void* apSelf, int aIndex, S_Flag aFlag);
void __cdecl hkMonitorStreamAnalyzer_writeStatisticsDetails(int a0, void* pArray, int a2, int a3, int a4, int a5, int a6);

struct FUN_00e0d0a0_s
{
    void ClearItems();
};

struct Array_e10630
{
    void** m_data;
    int m_iElementCount;
    unsigned int m_iCapacityState;
};

struct FUN_00e10630_cls
{
    int unk00;
    int m_count04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_18;
    int m_1c;
    int m_20;
    void ProcessItems(int a1, int a2);
};

// Collects m_count04 items via FUN_00e0ee00 into a temporary array, passes it to FUN_00e0fec0, then calls ClearItems and frees each item through the allocator.
// @fnv 0x00e10630
void FUN_00e10630_cls::ProcessItems(int a1, int a2)
{
    Array_e10630 arr;
    arr.m_data = 0;
    arr.m_iElementCount = 0;
    arr.m_iCapacityState = 0x80000000u;

    for (int i = 0; i < this->m_count04; ++i)
    {
        void* item = hkMonitorStreamAnalyzer_makeStatisticsTreeForMultipleFrames(this, i, S_Flag());
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        if (arr.m_iElementCount == (int)(arr.m_iCapacityState & 0x3fffffffu))
        {
            ResizeAudioStream(holder->m_heap, &arr, 4);
        }
        arr.m_data[arr.m_iElementCount++] = item;
    }

    hkMonitorStreamAnalyzer_writeStatisticsDetails(a1, &arr, this->m_18, this->m_1c, a2, this->m_20, 1);

    for (int j = 0; j < arr.m_iElementCount; ++j)
    {
        void* item = arr.m_data[j];
        if (item)
        {
            ((FUN_00e0d0a0_s*)item)->ClearItems();
            hkMemoryRouter* holder = hkMemoryRouter_getInstance();
            holder->m_heap->blockFree(item, 0x58);
        }
    }

    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* alloc = holder->m_heap;
    arr.m_iElementCount = 0;
    if ((arr.m_iCapacityState & 0x80000000u) == 0)
    {
        alloc->bufFree(arr.m_data, (arr.m_iCapacityState & 0x3fffffffu) * 4);
    }
}

struct FUN_00e0f700_s
{
    void* GetSelf_00e0f700(int dummy);
};

// @fnv 0x00e0f700
// src: GUESS 0x00e0f700 (confidence: high)
void* FUN_00e0f700_s::GetSelf_00e0f700(int dummy)
{
    return this;
}

struct S00e0c690_entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int m_4c;
};

struct FUN_00e0c690_owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S00e0c690_entry** m_30;
    int m_34;
};

extern FUN_00e0c690_owner* g_00e0c690_owner;

extern "C" int __cdecl hkString_strCmp(int a, unsigned int b);

// @fnv 0x00e0c690
// src: HAVOK_LIB 0x00e0c690
static __declspec(noinline) unsigned char findChildWithHint(unsigned int a1, int* a2, FUN_00e0c690_owner* o)
{
    unsigned int* pa = &a1;
    int idx = *a2;
    if (o->m_34 > idx)
    {
        S00e0c690_entry*& e = o->m_30[idx];
        if (hkString_strCmp(e->m_4c, *pa) == 0)
        {
            return 1;
        }
    }
    for (int i = 0; i < o->m_34; ++i)
    {
        S00e0c690_entry*& e = o->m_30[i];
        if (hkString_strCmp(e->m_4c, *pa) == 0)
        {
            *a2 = i;
            return 1;
        }
    }
    return 0;
}

unsigned char __cdecl S00e0c690_Wrap(unsigned int a1, int* a2)
{
    return findChildWithHint(a1, a2, g_00e0c690_owner);
}

struct Node_e0c8e0
{
    float values[8];
    unsigned short counts[8];
    Node_e0c8e0** children;
    int childCount;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    const char* name;
};

struct __declspec(align(64)) LineBuf_e0c8e0
{
    int c00;
    int c01;
    int c02;
    int c03;
    int c04;
    int c05;
    int c06;
    int c07;
    int c08;
    int c09;
    int d00;
    int d01;
    int d02;
    int d03;
    int d04;
    int d05;
    int d06;
    int d07;
    int d08;
    int d09;
    int e00;
    int e01;
    int e02;
    int e03;
    int e04;
    int e05;
    int e06;
    int e07;
    int e08;
    int e09;
    int f00;
    int f01;
    int f02;
    int f03;
    int f04;
    int f05;
    int f06;
    int f07;
    int f08;
    int f09;
    int g00;
    int g01;
    int g02;
    int g03;
    int g04;
    int g05;
    int g06;
    int g07;
    int g08;
    int g09;
};

// @fnv 0x00e0c8e0
// src: HAVOK_LIB 0x00e0c8e0
void __cdecl hkWriteRec(void* stream, Node_e0c8e0* item, int depth, float scale)
{
    if (depth != 0)
    {
        if (depth > 1)
        {
            int n = depth - 1;
            do
            {
                hkOstream_printf(stream, "\t");
                --n;
            } while (n != 0);
        }

        unsigned short* cp = item->counts;
        int maxv = 0;
        int nz = 0;
        if (item->counts[0] != 0)
        {
            ++nz;
            if ((int)item->counts[0] > maxv)
                maxv = (int)item->counts[0];
        }
        if (item->counts[1] != 0)
        {
            ++nz;
            if ((int)item->counts[1] > maxv)
                maxv = (int)item->counts[1];
        }
        if (item->counts[2] != 0)
        {
            ++nz;
            if ((int)item->counts[2] > maxv)
                maxv = (int)item->counts[2];
        }
        if (item->counts[3] != 0)
        {
            ++nz;
            if ((int)item->counts[3] > maxv)
                maxv = (int)item->counts[3];
        }
        if (item->counts[4] != 0)
        {
            ++nz;
            if ((int)item->counts[4] > maxv)
                maxv = (int)item->counts[4];
        }
        if (item->counts[5] != 0)
        {
            ++nz;
            if ((int)item->counts[5] > maxv)
                maxv = (int)item->counts[5];
        }
        if (item->counts[6] != 0)
        {
            ++nz;
            if ((int)item->counts[6] > maxv)
                maxv = (int)item->counts[6];
        }
        if (item->counts[7] != 0)
        {
            ++nz;
            if ((int)item->counts[7] > maxv)
                maxv = (int)item->counts[7];
        }

        LineBuf_e0c8e0 buf;
        Vsnprintf((char*)&buf, 200, "%s(%i)", item->name, maxv);
        if (maxv <= 1)
            Vsnprintf((char*)&buf, 200, "%s", item->name);
        else if (scale == 1.0f)
            Vsnprintf((char*)&buf, 200, "%s (%i)", item->name, maxv);
        else
            Vsnprintf((char*)&buf, 200, "%s (%4.1f)", item->name, scale * maxv);

        hkOstream_printf(stream, "%-32s", &buf);

        int tabs = 3;
        do
        {
            hkOstream_printf(stream, "\t");
            --tabs;
        } while (tabs != 0);

        if (nz > 0)
        {
            int left = nz;
            unsigned short* p = cp;
            for (int i = 0; i < 8; ++i, ++p)
            {
                int c = *p;
                if (c != 0)
                {
                    float v = item->values[i] * scale;
                    if (c < maxv)
                        v *= (float)maxv / (float)c;
                    --left;
                    if (left != 0)
                        hkOstream_printf(stream, "% 12.3f: ", v);
                    else
                        hkOstream_printf(stream, "% 12.3f\n", v);
                }
            }
        }
        else
        {
            hkOstream_printf(stream, "% 12.3f\n", 0.0);
        }
    }

    for (int i = 0; i < item->childCount; ++i)
        hkWriteRec(stream, item->children[i], depth + 1, scale);
}

struct S_00e0cbe0_Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
};

struct S_00e0cbe0_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S_00e0cbe0_Entry** unk30;
    int unk34;
};

int __cdecl hkString_strCmp(int a, int b);

// @fnv 0x00e0cbe0
// src: HAVOK_LIB 0x00e0cbe0
static __declspec(noinline) int __cdecl hkFindNextChildByName(S_00e0cbe0_Owner* owner, S_00e0cbe0_Entry* key, int value)
{
    int index;
    int* pvalue = &value;

    index = 0;
    while (index < owner->unk34)
    {
        if (owner->unk30[index] == key)
            break;
        ++index;
    }

    ++index;
    if (index >= owner->unk34)
        return 0;

    do
    {
        S_00e0cbe0_Entry** slot = &owner->unk30[index];
        if (!hkString_strCmp(*pvalue, (*slot)->unk4c))
            return reinterpret_cast<int>(owner->unk30[index]);
        ++index;
    } while (index < owner->unk34);

    return 0;
}

int __cdecl S00e0cbe0_Call(S_00e0cbe0_Owner* owner, S_00e0cbe0_Entry* key, int value)
{
    return hkFindNextChildByName(owner, key, value);
}

void __cdecl hkMonitorStreamAnalyzer_writeStatisticsDetailsToTga(void* array, void* name, void* owner, int argument, int flags);
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* alloc, void* array, int count, int size);
struct TempArray830
{
    void** data;
    int size;
    int capacity;
    void* local[6];
    TempArray830() : data(local), size(0), capacity(0x80000006)
    {}
    void reserve(int count)
    {
        hkMemoryAllocator& heap = hkMemoryRouter_getInstance()->heap();
        int cap = capacity & 0x3fffffff;
        if (cap < count)
        {
            int newCap = cap * 2;
            if (count >= newCap)
                newCap = count;
            hkArrayUtil__reserve(&heap, this, newCap, 4);
        }
    }
    void release()
    {
        hkMemoryAllocator& heap = hkMemoryRouter_getInstance()->heap();
        size = 0;
        if ((capacity & 0x80000000u) == 0)
            heap.bufFree(data, (capacity & 0x3fffffff) * 4);
    }
};
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* alloc, void* array, int count, int size);
struct Owner830
{
    void* data;
    int count;
    void hkMonitorStreamAnalyzer_drawThreadsToTga(void* name, int argument);
};
// @fnv 0x00e0f5e0
// src: HAVOK_LIB 0x00e0f5e0
void Owner830::hkMonitorStreamAnalyzer_drawThreadsToTga(void* name, int argument)
{
    TempArray830 temp;
    int num = count;
    temp.reserve(num);
    temp.size = num;
    for (int i = 0; i < num; i++)
        temp.data[i] = hkMonitorStreamAnalyzer_makeStatisticsTreeForMultipleFrames(this, i, S_Flag());
    hkMonitorStreamAnalyzer_writeStatisticsDetailsToTga(&temp, name, this, argument, 0);
    for (int j = 0; j < num; j++)
    {
        FUN_00e0d0a0_s* p = (FUN_00e0d0a0_s*)temp.data[j];
        if (p)
        {
            p->ClearItems();
            hkMemoryAllocator& heap = hkMemoryRouter_getInstance()->heap();
            heap.blockFree(p, 0x58);
        }
    }
    temp.release();
}

struct FUN_00e0d000;
struct FUN_00e0d000Array
{
    FUN_00e0d000* data;
    int size;
    int capacity;
    FUN_00e0d000Array() : data(0), size(0), capacity(0x80000000)
    {}
    FUN_00e0d000& AllocatePair();
};
struct FUN_00e0d000
{
    float values[8];
    unsigned short counts[8];
    FUN_00e0d000** children;
    int childCount;
    int childCapacity;
    int unk3c;
    int unk40;
    int unk44;
    FUN_00e0d000* linked;
    const char* name;
    int flags;
    int unk54;
    FUN_00e0d000() : children(0), childCount(0), childCapacity(0x80000000)
    {}
    FUN_00e0d000(int, const char*, int);
    __forceinline void accumulate(const FUN_00e0d000& src)
    {
        for (int i = 0; i < 8; ++i)
        {
            values[i] += src.values[i];
            counts[i] += src.counts[i];
        }
    }
};
struct FUN_00e0d000Total : FUN_00e0d000
{
    FUN_00e0d000Array linkedFUN_00e0d000;
    FUN_00e0d000Array childFUN_00e0d000;
    FUN_00e0d000Total() : FUN_00e0d000(0, 0, 0)
    {}
};
struct FUN_00e0d000Map
{
    FUN_00e0d000Total* GetValue(const char*, int);
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char*, FUN_00e0d000Total*);
};
int __cdecl hkString_strCmp(const char*, const char*);
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator*, FUN_00e0d000Array*, int, int);
__forceinline FUN_00e0d000& FUN_00e0d000Array::AllocatePair()
{
    hkMemoryAllocator& heap = monitorDebugHeap(hkMemoryRouter_getInstance());
    int oldSize = size;
    int count = oldSize + 1;
    int cap = capacity & 0x3fffffff;
    if (cap < count)
    {
        int newCap = cap * 2;
        if (count < newCap)
            count = newCap;
        hkArrayUtil__reserve(&heap, this, count, sizeof(FUN_00e0d000));
    }
    new (data + size) FUN_00e0d000;
    ++size;
    return data[oldSize];
}
__forceinline FUN_00e0d000* findOrAdd(FUN_00e0d000Array& array, const char* name)
{
    int i;
    FUN_00e0d000* found;
    for (i = array.size - 1; i >= 0; --i)
    {
        found = &array.data[i];
        if (hkString_strCmp(name, found->name) == 0)
            break;
    }
    if (i < 0)
    {
        found = new (&array.AllocatePair()) FUN_00e0d000(0, name, 0);
    }
    return found;
}
// @fnv 0x00e0f880
// src: HAVOK_LIB 0x00e0f880
void __cdecl hkBuildSizePerName(FUN_00e0d000* node, FUN_00e0d000Map* map)
{
    const char* name = node->name;
    FUN_00e0d000Total* total = map->GetValue(name, 0);
    if (!total)
    {
        total =
            new (monitorDebugHeap(hkMemoryRouter_getInstance()).blockAlloc(sizeof(FUN_00e0d000Total)))
                FUN_00e0d000Total;
        total->name = name;
        map->hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(name, total);
    }
    total->accumulate(*node);
    for (int i = 0; i < node->childCount; ++i)
    {
        FUN_00e0d000* child = node->children[i];
        hkBuildSizePerName(child, map);
        FUN_00e0d000* childTotal = findOrAdd(total->childFUN_00e0d000, child->name);
        childTotal->accumulate(*child);
    }
    if (node->linked)
    {
        int index;
        FUN_00e0d000* linkedTotal;
        const char* linkedName = node->linked->name;
        for (index = total->linkedFUN_00e0d000.size - 1; index >= 0; --index)
        {
            linkedTotal = &total->linkedFUN_00e0d000.data[index];
            if (hkString_strCmp(linkedName, linkedTotal->name) == 0)
                break;
        }
        if (index < 0)
            linkedTotal = new (&total->linkedFUN_00e0d000.AllocatePair()) FUN_00e0d000(0, linkedName, 0);
        linkedTotal->accumulate(*node->linked);
    }
}

extern unsigned int DAT_011bdea0[];

extern "C" unsigned int e0c1c0_tblidx(void);
extern volatile int g_e0c1c0_stride;
extern unsigned int* volatile g_e0c1c0_out;

// @fnv 0x00e0c1c0
// src: HAVOK_LIB 0x00e0c1c0
static __declspec(noinline) void drawDigit(unsigned int idx, int stride, unsigned int* out)
{
    unsigned int* entry = (unsigned int*)((unsigned int* volatile*)DAT_011bdea0)[idx];
    int stride4 = stride * 4;
    unsigned int* src = entry + 6;
    int shift = 0;

    do
    {
        unsigned int* dst = (unsigned int*)((unsigned char*)out + shift);
        unsigned int* p = src;
        int j = 7;

        do
        {
            unsigned int v = *p << shift;
            if (v & 0xf0000000u)
            {
                *dst = 0xff000000u;
            }
            p -= 1;
            dst = (unsigned int*)((char*)dst + stride4);
            --j;
        } while (j);

        shift += 4;
    } while (shift < 0x20);
}

void e0c1c0_caller(void)
{
    drawDigit(e0c1c0_tblidx(), g_e0c1c0_stride, g_e0c1c0_out);
}

struct S00e0c210_Obj
{
    int unk00;
};

// src: HAVOK_LIB 0x00e0c1c0
static __declspec(noinline) void drawDigit(S00e0c210_Obj* self, int digit, int* out)
{
    int** pout = &out;
    self->unk00 = digit;
    self = (S00e0c210_Obj*)((int)self + digit);
    (*pout)[0] = self->unk00;
}

// @fnv 0x00e0c210
// src: HAVOK_LIB 0x00e0c210
static __declspec(noinline) void __cdecl drawNumber(int value, S00e0c210_Obj* self, int* out)
{
    int place = 1000;
    int* cur = out;
    S00e0c210_Obj** pself = &self;
    int ten = 10;
    do
    {
        int quotient = value / place;
        int digit = quotient % ten;
        drawDigit(*pself, digit, cur);
        place /= 10;
        cur += 7;
    } while (place >= 1);
}

void __cdecl S00e0c210_Entry(int value, S00e0c210_Obj* self)
{
    drawNumber(value, self, 0);
}

union CommandWord
{
    unsigned int tag;
    const char* name;
};
struct NamedCommand
{
    CommandWord command;
    unsigned int time0;
    unsigned int time1;
    CommandWord object;
};
struct ValueCommand
{
    CommandWord command;
    float value;
};
struct SomeMap
{
    int __thiscall LookupBucketValue(unsigned int key, const char** out);
};


template <typename T> __forceinline T doSwap(T val)
{
    union
    {
        T val;
        unsigned int u;
        unsigned char b[4];
    } in, out;
    in.val = val;
    out.b[0] = (unsigned char)(in.u >> 24);
    out.b[1] = (unsigned char)(in.u >> 16);
    out.b[2] = (unsigned char)(in.u >> 8);
    out.b[3] = (unsigned char)(in.u);
    return out.val;
}

template <class T> __forceinline void swapInPlace(T& val)
{
    union
    {
        T val;
        unsigned int u;
    } in;
    union
    {
        T val;
        unsigned char b[4];
    } out;
    in.val = val;
    out.b[0] = (unsigned char)(in.u >> 24);
    out.b[1] = (unsigned char)(in.u >> 16);
    out.b[2] = (unsigned char)(in.u >> 8);
    out.b[3] = (unsigned char)in.u;
    val = out.val;
}
__forceinline bool isSmallTag(CommandWord* c, unsigned int tag, hkBool swap)
{
    if (!swap)
    {
        if (tag >= 10)
            return false;
        return true;
    }
    unsigned int s = doSwap(tag);
    if (s < 10)
    {
        c->tag = s;
        return true;
    }
    return false;
}
// @fnv 0x00e0c350
// src: HAVOK_LIB 0x00e0c350
void __cdecl hkMonitorStreamAnalyzer_applyStringMap(char* p, const char* end, SomeMap* map, hkBool swapBytes)
{
    if (p >= end)
        return;
loop:
    unsigned int tag = ((CommandWord*)p)->tag;
    if (!isSmallTag((CommandWord*)p, tag, swapBytes))
        goto do_command;
advance:
    p += 4;
next:
    if (p < end)
        goto loop;
    return;
do_command:
    const char* str;
    if (map->LookupBucketValue(tag, &str) != 0)
    {
        return;
    }
    ((CommandWord*)p)->name = str;

    switch (str[0])
    {
    case 'E':
    case 'S':
    case 'T':
    case 'l': {
        char* cur = p;
        p += 12;
        if (swapBytes)
        {
            swapInPlace(((hkMonitorStream::TimerCommand*)cur)->m_time0);
            swapInPlace(((hkMonitorStream::TimerCommand*)cur)->m_time1);
        }
        goto next;
    }
    case 'F':
    case 'N':
    case 'P':
    case 'p':
        goto advance;

    case 'O': {
        char* cur = p;
        p += 16;
        unsigned int key = ((NamedCommand*)cur)->object.tag;
        const char* str2;
        if (map->LookupBucketValue(key, &str2) == 0)
        {
            ((NamedCommand*)cur)->object.name = str2;
        }
        if (swapBytes)
        {
            swapInPlace(((hkMonitorStream::TimerCommand*)cur)->m_time0);
            swapInPlace(((hkMonitorStream::TimerCommand*)cur)->m_time1);
        }
        goto next;
    }
    case 'L': {
        char* cur = p;
        p += 16;
        unsigned int key = ((NamedCommand*)cur)->object.tag;
        const char* str2;
        if (map->LookupBucketValue(key, &str2) == 0)
        {
            ((NamedCommand*)cur)->object.name = str2;
        }
        if (swapBytes)
        {
            swapInPlace(((hkMonitorStream::TimerCommand*)cur)->m_time0);
            swapInPlace(((hkMonitorStream::TimerCommand*)cur)->m_time1);
        }
        goto next;
    }
    case 'M': {
        char* cur = p;
        p += 8;
        if (swapBytes)
        {
            swapInPlace(((ValueCommand*)cur)->value);
        }
        goto next;
    }
    default:
        return;
    }
}

extern int __cdecl hkString_strCmp(const char* a, const char* b);
struct RecEntry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    const char* unk4c;
};
struct RecBox
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    RecEntry** unk30;
    int unk34;
};
struct NameArg
{
    const char* unk00;
};
// @fnv 0x00e0cb80
// src: HAVOK_LIB 0x00e0cb80
static __declspec(noinline) RecEntry* hkFindChildByName(RecBox* box, NameArg name, bool flag)
{
    const char* n = name.unk00;
    for (int i = 0; i < box->unk34; ++i)
    {
        RecEntry*& e = box->unk30[i];
        if (hkString_strCmp(n, e->unk4c) == 0)
            return box->unk30[i];
    }
    if (flag && box->unk34 > 0)
        return box->unk30[0];
    return 0;
}
volatile int g_in_name;
RecBox* volatile g_in_box;
void* volatile g_out;
void* volatile g_out2;
void CallTarget_e0cb80()
{
    RecBox* box = g_in_box;
    NameArg a;
    a.unk00 = (const char*)g_in_name;
    g_out = hkFindChildByName(box, a, true);
    a.unk00 = (const char*)g_in_name;
    g_out2 = hkFindChildByName(box, a, false);
}

namespace fnv_00e0d100 {
struct NameArg
{
    const char* value;
};
struct IntArg
{
    int value;
};
struct BoolArg
{
    bool value;
};
__forceinline FUN_00e0d000*& childAt(FUN_00e0d000* parent, int i)
{
    return parent->children[i];
}
// @fnv 0x00e0d100
// src: HAVOK_LIB 0x00e0d100
static __declspec(noinline) FUN_00e0d000* createNewNode(FUN_00e0d000* parent, NameArg name, IntArg extra,
                                                       BoolArg findExisting)
{
    const char* key = name.value;
    if (findExisting.value)
    {
        int i = 0;
        {
            while (parent && key && i < parent->childCount)
            {
                if (childAt(parent, i)->name && hkString_strCmp(childAt(parent, i)->name, key) == 0)
                    return childAt(parent, i);
                ++i;
            }
        }
    }
    void* storage = hkMemoryRouter_getInstance()->heap().blockAlloc(0x58);
    if (storage)
        return new (storage) FUN_00e0d000((int)parent, key, extra.value);
    return 0;
}
FUN_00e0d000* CallCreate(FUN_00e0d000* parent, NameArg name, IntArg extra, BoolArg findExisting)
{
    return createNewNode(parent, name, extra, findExisting);
}
}  // namespace fnv_00e0d100

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator*, void*, int, int);
void __cdecl hkOstream_printf(void*, const char*, ...);
struct FUN_00e108b0
{
    char* data;
    int size;
    int capacity;
    FUN_00e108b0();
    void reserve(hkMemoryAllocator& a, int n)
    {
        if ((capacity & 0x3fffffff) < n)
        {
            int c = (capacity & 0x3fffffff) * 2;
            if (c <= n)
                c = n;
            hkArrayUtil__reserve(&a, this, c, 1);
        }
    }
    void reserve(int n)
    {
        reserve(monitorDebugHeap(hkMemoryRouter_getInstance()), n);
        size = n;
    }
    void append(char c)
    {
        hkMemoryRouter* r = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream((hkMemoryAllocator*)(&monitorDebugHeap(r)), this, 1);
        data[size++] = c;
    }
    void clearAndFree(hkMemoryAllocator& a)
    {
        if ((capacity & 0x80000000u) == 0)
            a.bufFree(data, capacity & 0x3fffffff);
    }
    void clearAndFree()
    {
        hkMemoryAllocator& a = *(&monitorDebugHeap(hkMemoryRouter_getInstance()));
        size = 0;
        clearAndFree(a);
    }
};
struct DumpFrame
{
    const char* heading;
    int a, b;
    int time;
    int d, e;
    int thread;
    int begin, end;
};
struct DumpFrames
{
    DumpFrame* data;
    int size, capacity;
};
struct DumpCommand
{
    const char* name;
    union
    {
        unsigned int timer;
        float value;
        void* pointer;
    } first;
    unsigned int second;
    const char* split;
};
struct DumpState
{
    DumpFrames* frames;
    int count, capacity;
    char* commands;
    int size, cap;
    int threads, spus;
    void hkMonitorStreamAnalyzer_writeRawStatistics(void* stream);
};
// @fnv 0x00e0eef0
// src: HAVOK_LIB 0x00e0eef0
void DumpState::hkMonitorStreamAnalyzer_writeRawStatistics(void* stream)
{
    hkMemoryAllocator* cleanupAllocator;
    FUN_00e108b0 indent;
    hkOstream_printf(stream, "StatisticsDumpInfo(num_threads=%i, num_spus=%i, num_frames=%i)\n", threads, spus,
                 frames->size);
    for (int i = 0; i < count; i++)
    {
        DumpFrames& f = frames[i];
        for (int j = 0; j < f.size; j++)
        {
            DumpFrame& frame = f.data[j];
            hkOstream_printf(stream, "FrameInfo(heading='%s', frame=%i, thread_id=%i, time_counter=%i)\n", frame.heading, j,
                         frame.thread, frame.time);
            DumpCommand* p = (DumpCommand*)(commands + frame.begin);
            DumpCommand* end = (DumpCommand*)(commands + frame.end);
            indent.reserve(1);
            indent.data[0] = 0;
            while (p < end)
            {
                switch (*p->name)
                {
                case 'T':
                    hkOstream_printf(stream, "%sTimerBegin('%s',%u,%u)\n", indent.data, p->name + 2, p->first.timer,
                                 p->second);
                    indent.data[indent.size - 1] = ' ';
                    indent.append(' ');
                    indent.append(0);
                    p = (DumpCommand*)((char*)p + 12);
                    break;
                case 'E':
                    indent.size -= 2;
                    indent.data[indent.size - 1] = 0;
                    hkOstream_printf(stream, "%sTimerEnd('%s',%u,%u)\n", indent.data, p->name + 2, p->first.timer,
                                 p->second);
                    p = (DumpCommand*)((char*)p + 12);
                    break;
                case 'L':
                    hkOstream_printf(stream, "%sTimerBegin('%s', %u, %u)\n", indent.data, p->name + 2, p->first.timer,
                                 p->second);
                    hkOstream_printf(stream, "%sTimerSplit('%s', %u, %u)\n", indent.data, p->split + 2, p->first.timer,
                                 p->second);
                    indent.data[indent.size - 1] = ' ';
                    indent.append(' ');
                    indent.append(0);
                    p = (DumpCommand*)((char*)p + 16);
                    break;
                case 'S':
                    indent.size -= 2;
                    indent.data[indent.size - 1] = 0;
                    hkOstream_printf(stream, "%sTimerSplit('%s', %u, %u)\n", indent.data, p->name + 2, p->first.timer,
                                 p->second);
                    indent.data[indent.size - 1] = ' ';
                    indent.append(' ');
                    indent.append(0);
                    p = (DumpCommand*)((char*)p + 12);
                    break;
                case 'l':
                    indent.size -= 2;
                    indent.data[indent.size - 1] = 0;
                    hkOstream_printf(stream, "%sTimerEnd('%s', %u, %u)\n", indent.data, p->name + 2, p->first.timer,
                                 p->second);
                    p = (DumpCommand*)((char*)p + 12);
                    break;
                case 'M':
                    hkOstream_printf(stream, "%sAddValue(%s,%f)\n", indent.data, p->name + 1, p->first.value);
                    p = (DumpCommand*)((char*)p + 8);
                    break;
                case 'N':
                    p = (DumpCommand*)((char*)p + 4);
                    break;
                case 'm': {
                    int bytes = p->second & 0x7fffffff;
                    const char* operation = (p->second & 0x80000000u) ? "Free" : "Alloc";
                    hkOstream_printf(stream, "%s%s%s(ptr=0x%p, nbytes=%i)\n", indent.data, operation, p->name + 1,
                                 p->first.pointer, bytes);
                    p = (DumpCommand*)((char*)p + 12);
                    break;
                }
                case 'F':
                case 'O':
                case 'P':
                case 'p':
                    break;
                default:
                    cleanupAllocator = &monitorDebugHeap(hkMemoryRouter_getInstance());
                    indent.size = 0;
                    goto cleanup;
                }
            }
        }
    }
    cleanupAllocator = &monitorDebugHeap(hkMemoryRouter_getInstance());
    indent.size = 0;
cleanup:
    if ((indent.capacity & 0x80000000u) == 0)
        cleanupAllocator->bufFree(indent.data, indent.capacity & 0x3fffffff);
}

namespace fnv_00e0fec0 {
struct TimerObj;
struct TimerArray
{
    TimerObj** m_data;
    int m_iElementCount;
};
struct TimerObj
{
    float m_uiFilterValue;
    float value04;
    float value08;
    float value0c;
    float value10;
    float value14;
    float value18;
    float value1c;
    unsigned short counts[8];
    TimerArray m_children;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    const char* m_name;
};
typedef TimerObj ThreadObj;
struct ArrayArg
{
    ThreadObj** m_data;
    int m_iElementCount;
};
struct AggObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    AggObj* DoNothing_00e0d000(int a, const char* name, int b);
    void ClearItems();
};
void __cdecl ext_free(int);
int __cdecl ext_init(int, const char*, int);
// src: GUESS 0x00e0d000 (confidence: high)
__declspec(noinline) AggObj* AggObj::DoNothing_00e0d000(int a, const char* name, int b)
{
    unk00 = ext_init(a, name, b);
    return this;
}
__declspec(noinline) void AggObj::ClearItems()
{
    ext_free(unk00);
}
struct AggArray
{
    AggObj** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    AggObj** m_originalData;
};
struct CfgObj
{
    int unk00;
    int f04;
    int f08;
    int f0c;
    char b10;
    char unk11;
    char unk12;
    char unk13;
    char unk14;
    char unk15;
    char unk16;
    char unk17;
    char unk18;
    char unk19;
    char b1a;
    char unk1b;
};
void __cdecl ext_merge(int, int);
// src: HAVOK_LIB 0x00e0d880
__declspec(noinline) void __cdecl hkMakeSumRecursive(AggObj* agg, TimerObj* timer)
{
    ext_merge(agg->unk04, (int)timer->m_name);
    agg->unk08 = 1;
}
struct SearchKey
{
    int value;
};
int __cdecl hkString_strCmp(const char*, const char*);
// src: HAVOK_LIB 0x00e0cb80
static __declspec(noinline) TimerObj* hkFindChildByName(TimerObj* root, SearchKey key, S_Flag flag)
{
    for (int i = 0; i < root->m_children.m_iElementCount; ++i)
    {
        if (!hkString_strCmp((const char*)key.value, root->m_children.m_data[i]->m_name))
            return root->m_children.m_data[i];
    }
    if (flag.b && root->m_children.m_iElementCount > 0)
        return root->m_children.m_data[0];
    return 0;
}
// src: HAVOK_LIB 0x00e0cbe0
static __declspec(noinline) TimerObj* hkFindNextChildByName(TimerObj* root, TimerObj* node, SearchKey key)
{
    int i = 0;
    while (i < root->m_children.m_iElementCount && root->m_children.m_data[i] != node)
        ++i;
    for (++i; i < root->m_children.m_iElementCount; ++i)
    {
        if (!hkString_strCmp((const char*)key.value, root->m_children.m_data[i]->m_name))
            return root->m_children.m_data[i];
    }
    return 0;
}
void __cdecl ext_show(void*, int, int, float);
// src: HAVOK_LIB 0x00e0c8e0
__declspec(noinline) void __cdecl hkWriteRec(void* stream, void* agg, int a, float f)
{
    ext_show(stream, ((AggObj*)agg)->unk08, a, f);
}
void __cdecl hkMonitorStreamAnalyzer_mergeTreesForCombinedThreadSummary(void* first, void* second, int index, int limit, float amount);
void __cdecl hkMonitorStreamAnalyzer_showCombinedThreadSummaryForSingleFrame(void* a, int a2, int a3, void* stream, CfgObj* cfg);

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* alloc, void* arr, int count, int elemSize);
extern "C" void __cdecl hkString_memSet(void* dst, int c, int n);
void* __cdecl fnv_zlib_memset(void* dst, int c, int n);

struct RootArg
{
    void* node;
};
struct TypeMap
{
    int unk00;
    int m_iElementCount;
    int unk08;
    void FUN_00d87790(S_Flag flag);
    int hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator();
    void SetBoolFromThreshold(char* valid, int iterator);
    void* hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(int iterator);
    int FindNextUsedSlot(int iterator);
    void FreeBuffer();
};
struct TypeItem
{
    float values[8];
    unsigned short counts[8];
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    const char* name;
    int unk50;
    int unk54;
    AggObj* entries;
    int size;
    int capacity;
    AggObj* other;
    int otherSize;
    int otherCapacity;
    void ProcessEntries_00e10930();
};
struct TypeArray
{
    TypeItem** data;
    int size;
    int capacity;
};
void __cdecl hkBuildSizePerName(void* node, TypeMap* map);
int __cdecl hkCompareInfosBySize(const TypeItem*, const TypeItem*);
void __cdecl hkAlgorithm_quickSortRecursive_hkMonitorStreamAnalyzerPrintByTypeInfo_bool_cdecl_hkMonitorStreamAnalyzerPrintByTypeInfo_const_hkMonitorStreamAnalyzerPrintByTypeInfo_const(TypeItem** data, int lo, int hi, int(__cdecl* compare)(const TypeItem*, const TypeItem*));
// src: HAVOK_LIB 0x00e0fc50
static __declspec(noinline) void printStatisticsByType(void* stream, void* rootNode, float fraction)
{
    TypeMap map;
    S_Flag flag;
    map.FUN_00d87790(flag);
    TypeArray arr;
    arr.data = 0;
    arr.size = 0;
    arr.capacity = (int)0x80000000;
    hkBuildSizePerName(rootNode, &map);
    int count = map.m_iElementCount;
    hkMemoryAllocator* heap = hkMemoryRouter_getInstance()->m_temp;
    if ((arr.capacity & 0x3fffffff) < count)
    {
        int cap = (arr.capacity & 0x3fffffff) * 2;
        if (cap <= count)
            cap = count;
        fnv_00e0fec0::hkArrayUtil__reserve(heap, &arr, cap, 4);
    }
    int iterator = map.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator();
    char valid;
    map.SetBoolFromThreshold(&valid, iterator);
    while (valid)
    {
        arr.data[arr.size++] = (TypeItem*)map.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(iterator);
        iterator = map.FindNextUsedSlot(iterator);
        map.SetBoolFromThreshold(&valid, iterator);
    }
    if (arr.size > 1)
        hkAlgorithm_quickSortRecursive_hkMonitorStreamAnalyzerPrintByTypeInfo_bool_cdecl_hkMonitorStreamAnalyzerPrintByTypeInfo_const_hkMonitorStreamAnalyzerPrintByTypeInfo_const(arr.data, 0, arr.size - 1, hkCompareInfosBySize);
    map.FreeBuffer();
    float maxTime = arr.data[arr.size - 1]->values[1];
    hkOstream_printf(stream, "\n\n");
    hkOstream_printf(stream, "************************************\n");
    hkOstream_printf(stream, "********** Per Type Times    *******\n");
    hkOstream_printf(stream, "************************************\n");
    for (int i = arr.size - 1; i >= 0; --i)
    {
        TypeItem* item = arr.data[i];
        if (item->values[1] > maxTime * fraction)
        {
            hkOstream_printf(stream, "\n");
            hkOstream_printf(stream, "************************************\n\n");
            for (int j = 0; j < item->size; ++j)
            {
                hkOstream_printf(stream, "\t\t");
                WriteItemStats(stream, 0.0f, (S_00e0bfe0_Item*)&item->entries[j]);
            }
            WriteItemStats(stream, maxTime, (S_00e0bfe0_Item*)item);
            for (int k = 0; k < item->otherSize; ++k)
            {
                hkOstream_printf(stream, "\t\t");
                WriteItemStats(stream, 0.0f, (S_00e0bfe0_Item*)&item->other[k]);
            }
        }
        item->ProcessEntries_00e10930();
        (&monitorDebugHeap(hkMemoryRouter_getInstance()))->blockFree(item, 0x70);
    }
    hkMemoryAllocator* temp = hkMemoryRouter_getInstance()->m_temp;
    arr.size = 0;
    if (arr.capacity >= 0)
        temp->bufFree(arr.data, (arr.capacity & 0x3fffffff) * 4);
}

struct WorkSlot
{
    AggObj agg;
};
struct ReportMetrics
{
    float total;
    int row;
    union
    {
        float pct;
        int flag8;
    };
    TimerArray* first;
    const char* name;
};

// @fnv 0x00e0fec0
// src: HAVOK_LIB 0x00e0fec0
void __cdecl hkMonitorStreamAnalyzer_writeStatisticsDetails(int a0, void* pArray_, int a2, int a3, int a4, int a5, int a6)
{
    void* stream = (void*)a0;
    ArrayArg* pArray = (ArrayArg*)pArray_;
    hkOstream_printf(stream, "Havok version: %s\n", "Havok-7.1.0-r1");
    ReportMetrics metrics;
    metrics.total = 0.0f;
    float time;

    metrics.first = &pArray->m_data[0]->m_children;
    SearchKey key = {a5};
    int flags = a4;
    {

        AggObj sum;
        sum.DoNothing_00e0d000(0, "Sum", 1);
        metrics.row = metrics.first->m_iElementCount;
        time = 1.0f / (float)metrics.row;
        int i = 0;
        if (metrics.row > 0)
        {
            do
            {
                hkMakeSumRecursive(&sum, metrics.first->m_data[i]);
                i++;
            } while (i < metrics.first->m_iElementCount);
        }
        S_Flag flag;
        flag.b = 1;
        TimerObj* node = hkFindChildByName((TimerObj*)&sum, key, flag);
        if (node)
        {
            do
            {
                metrics.total += node->m_uiFilterValue * time;
                node = hkFindNextChildByName((TimerObj*)&sum, node, key);
            } while (node);
        }
        if (metrics.total <= 0.0f)
            metrics.total = 1000.0f;
        if (flags & 1)
        {
            hkOstream_printf(stream, "\n\n");
            hkOstream_printf(stream, "*********************************\n");
            hkOstream_printf(stream, "********** Total Times    *******\n");
            hkOstream_printf(stream, "*********************************\n");
            hkOstream_printf(stream, "Timers are added together\n");
            hkWriteRec(stream, &sum, 0, time);
        }
        sum.ClearItems();
    }
    if (flags & 2)
    {
        hkOstream_printf(stream, "\n\n");
        hkOstream_printf(stream, "*********************************\n");
        hkOstream_printf(stream, "********** Per Frame Time *******\n");
        hkOstream_printf(stream, "*********************************\n");
        hkOstream_printf(stream, "Ascii Art all frames overview\n");
        unsigned int barw[12];
        char* bar = (char*)barw;
        S_Flag flag;
        flag.b = 1;
        hkString_memSet(bar, 0x20, 0x28);
        bar[40] = 0;
        metrics.row = 0;
        for (; metrics.row < metrics.first->m_iElementCount; metrics.row++)
        {
            ThreadObj* th = metrics.first->m_data[metrics.row];
            if (th->m_children.m_iElementCount == 0)
                continue;
            time = 0.0f;
            metrics.name = "Unknown";
            TimerObj* t = hkFindChildByName(th, key, flag);
            if (t)
            {
                do
                {
                    time += t->m_uiFilterValue;
                    metrics.name = t->m_name;
                    t = hkFindNextChildByName(th, t, key);
                } while (t);
            }
            metrics.pct = time * 20.0 / metrics.total;
            int bars = (int)metrics.pct;
            if (bars < 0)
                bars = 0;
            if (bars >= 0x28)
                bars = 0x27;
            char* p = bar;
            int cnt = 0;
            if (bars > 4)
            {
                int c = 4;
                do
                {
                    *p = 9;
                    c += 4;
                    p++;
                    cnt += 4;
                } while (c < bars);
            }
            int pos = cnt;
            if (cnt < bars)
            {
                int n = bars - cnt;
                fnv_zlib_memset(p, 0x20, n);
                p += n;
                pos = n + cnt;
            }
            *p = 0x23;
            pos++;
            cnt += 4;
            p++;
            if (pos < cnt)
            {
                int n2 = cnt - pos;
                fnv_zlib_memset(p, 0x20, n2);
                p += n2;
            }
            if (cnt < 0x28)
            {
                int n3 = (int)(((unsigned int)(0x27 - cnt)) >> 2) + 1;
                fnv_zlib_memset(p, 9, n3);
                p += n3;
            }
            *p = 0;
            hkOstream_printf(stream, bar);
            hkOstream_printf(stream, "%i %-12s %f\n", metrics.row, metrics.name, (double)time);
        }
    }
    if (flags & 4)
    {
        ArrayArg* pa = pArray;
        if (pa->m_iElementCount != 1 && (char)a6 != 0)
        {
            ThreadObj* th0 = pa->m_data[0];
            int outer = 0;
            if (th0->m_children.m_iElementCount > 0)
            {
                metrics.flag8 = flags & 8;
                do
                {
                    hkOstream_printf(stream, "\n");
                    hkOstream_printf(stream, "****************************************\n");
                    hkOstream_printf(stream, "****** Summary Frame:%i ******\n", outer);
                    hkOstream_printf(stream, "****************************************\n");
                    AggArray arr;
                    arr.m_data = 0;
                    arr.m_iElementCount = 0;
                    arr.m_iCapacityState = (int)0x80000000;
                    int cnt = pa->m_iElementCount;
                    hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
                    int top = (int)(router->m_stack.m_next.m_storage);
                    router->m_stack.m_next.m_storage = (void*)(top + ((cnt * 4 + 0x7f) & ~0x7f));
                    arr.m_iCapacityState = cnt | (int)0x80000000;
                    arr.m_data = (AggObj**)top;
                    arr.m_originalData = arr.m_data;
                    cnt = pa->m_iElementCount;
                    hkMemoryRouter* router2 = (hkMemoryRouter*)hkMemoryRouter_getInstance();
                    hkMemoryAllocator* heap = router2->m_heap;
                    if ((arr.m_iCapacityState & 0x3fffffff) < cnt)
                    {
                        int cap2 = (arr.m_iCapacityState & 0x3fffffff) * 2;
                        if (cnt >= cap2)
                            cap2 = cnt;
                        fnv_00e0fec0::hkArrayUtil__reserve((hkMemoryAllocator*)heap, &arr, cap2, 4);
                    }
                    arr.m_iElementCount = cnt;
                    for (int k = 0; k < pa->m_iElementCount; k++)
                    {
                        hkMemoryRouter* r3 = (hkMemoryRouter*)hkMemoryRouter_getInstance();
                        hkMemoryAllocator* h3 = r3->m_heap;
                        AggObj* obj = (AggObj*)h3->blockAlloc(0x58);
                        if (obj)
                            obj = obj->DoNothing_00e0d000(0, "", 1);
                        else
                            obj = 0;
                        arr.m_data[k] = obj;
                        ThreadObj* th = pa->m_data[k];
                        if (th->m_children.m_iElementCount > outer)
                            hkMakeSumRecursive(arr.m_data[k], th->m_children.m_data[outer]);
                    }
                    int m = 1;
                    CfgObj cfg;
                    CfgObj* cfgp = &cfg;
                    cfgp->f08 = 4;
                    cfgp->f0c = 2;
                    cfgp->f04 = 0x10;
                    cfgp->b10 = 0;
                    cfgp->b1a = 0;
                    for (; m < arr.m_iElementCount; m++)
                        hkMonitorStreamAnalyzer_mergeTreesForCombinedThreadSummary(arr.m_data[0], arr.m_data[m], m, 0, 0.0f);
                    hkMonitorStreamAnalyzer_showCombinedThreadSummaryForSingleFrame(arr.m_data[0], a2, a3, stream, cfgp);
                    if (metrics.flag8)
                    {
                        printStatisticsByType(stream, arr.m_data[0], 0.01f);
                    }
                    for (int k = 0; k < pa->m_iElementCount; k++)
                    {
                        AggObj* obj = arr.m_data[k];
                        if (obj)
                        {
                            obj->ClearItems();
                            hkMemoryRouter* r4 = (hkMemoryRouter*)hkMemoryRouter_getInstance();
                            r4->m_heap->blockFree(obj, 0x58);
                        }
                    }
                    AggObj** originalData = arr.m_originalData;
                    if (originalData == arr.m_data)
                    {
                        arr.m_iElementCount = 0;
                    }
                    hkMemoryRouter* r5 = (hkMemoryRouter*)hkMemoryRouter_getInstance();
                    r5->m_stack.m_next.m_storage = (void*)((int)originalData);
                    hkMemoryRouter* r6 = (hkMemoryRouter*)hkMemoryRouter_getInstance();
                    hkMemoryAllocator* h6 = r6->m_heap;
                    int capf = arr.m_iCapacityState;
                    arr.m_iElementCount = 0;
                    if ((capf & (int)0x80000000) == 0)
                        h6->bufFree(arr.m_data, (capf & 0x3fffffff) * 4);
                    arr.m_data = 0;
                    arr.m_iCapacityState = (int)0x80000000;
                    outer++;
                } while (outer < pa->m_data[0]->m_children.m_iElementCount);
            }
        }
        else
        {
            ThreadObj* th0 = pa->m_data[0];
            int ebp = 0;
            if (th0->m_children.m_iElementCount > 0)
            {
                do
                {
                    int ebx = 0;
                    if (pa->m_iElementCount > 0)
                    {
                        do
                        {
                            ThreadObj* th = pa->m_data[ebx];
                            if (ebp < th->m_children.m_iElementCount)
                            {

                                AggObj sum2;
                                sum2.DoNothing_00e0d000(0, "Sum", 1);
                                hkMakeSumRecursive(&sum2, th->m_children.m_data[ebp]);
                                hkOstream_printf(stream, "\n");
                                hkOstream_printf(stream, "****************************************\n");
                                hkOstream_printf(stream, "****** Summary Frame:%i Thread:%i ******\n", ebp, ebx);
                                hkOstream_printf(stream, "****************************************\n");
                                TimerObj* tm = th->m_children.m_data[ebp];
                                hkOstream_printf(stream, "%s\n", tm->m_name);
                                float one = 1.0f;
                                hkWriteRec(stream, &sum2, 0, one);
                                if (flags & 8)
                                {
                                    printStatisticsByType(stream, &sum2, 0.01f);
                                }
                                sum2.ClearItems();
                            }
                            ebx++;
                        } while (ebx < pa->m_iElementCount);
                    }
                    ebp++;
                } while (ebp < pa->m_data[0]->m_children.m_iElementCount);
            }
        }
    }
    if (flags & 0x10)
    {
        ThreadObj* th0 = pArray->m_data[0];
        int edi = 0;
        if (th0->m_children.m_iElementCount > 0)
        {
            do
            {
                int ebx = 0;
                if (pArray->m_iElementCount > 0)
                {
                    do
                    {
                        ThreadObj* th = pArray->m_data[ebx];
                        if (edi < th->m_children.m_iElementCount)
                        {
                            hkOstream_printf(stream, "\n\n");
                            hkOstream_printf(stream, "***************************************\n");
                            if (ebx < a2)
                                hkOstream_printf(stream, "***** Details Frame-%i Thread:%i ******\n", edi, ebx);
                            else
                                hkOstream_printf(stream, "***** Details Frame-%i Spu:%i ******\n", edi, ebx - a2);
                            hkOstream_printf(stream, "***************************************\n");
                            hkOstream_printf(stream, "%s\n", th->m_children.m_data[edi]->m_name);
                            float one = 1.0f;
                            hkWriteRec(stream, th->m_children.m_data[edi], 0, one);
                        }
                        ebx++;
                    } while (ebx < pArray->m_iElementCount);
                }
                edi++;
            } while (edi < pArray->m_data[0]->m_children.m_iElementCount);
        }
    }
}
}  // namespace fnv_00e0fec0

// FUN_00e0cc90 - __thiscall member of a lookup table object.
//
// The object layout is taken from the original's disassembly:
//   +0x00  int      unk00
//   +0x04  int      unk04
//   +0x08  Entry*   m_pEntries   (8-byte entries: {unsigned key; int value;})
//   +0x10  int      unk10
//   +0x14  int      m_iFallback  (returned when no entry matches)
//
// The function walks the entries, asks CompareStringsCaseInsensitive(key & ~1, arg) about each
// key, and returns the value of the first entry the helper rejects; if the
// helper accepts every entry, the fallback at +0x14 is returned.
int __cdecl CompareStringsCaseInsensitive(unsigned int key, int arg);

struct FUN_00e0cc90_cls
{
    int unk00;
    int unk04;
    struct Entry
    {
        unsigned int key;
        int value;
    };
    Entry* m_pEntries;  // +0x08
    int m_iArrayLength;       // +0x0c
    int unk10;
    int m_iFallback;  // +0x14
    int hkMonitorStreamColorTable_findColor(int arg);
};

// @fnv 0x00e0cc90
// src: HAVOK_LIB 0x00e0cc90
int FUN_00e0cc90_cls::hkMonitorStreamColorTable_findColor(int arg)
{
    for (int i = 0; i < m_iArrayLength; ++i)
    {
        unsigned int key = m_pEntries[i].key & 0xfffffffe;
        if (CompareStringsCaseInsensitive(key, arg) != 0)
        {
        }
        else
        {
            return m_pEntries[i].value;
        }
    }
    return m_iFallback;
}

struct S00e0d180_Node;

typedef hkArrayBase<S00e0d180_Node*> S00e0d180_Array;

struct S00e0d180_Node
{

    float values[8];

    unsigned short counts[8];

    S00e0d180_Array children;

    double accumulatedValue;

    S00e0d180_Node* linked;

    const char* name;

    int flags;

    int unk54;

    void* operator new(unsigned int size)
    {

        return hkMemoryRouter_getInstance()->heap().blockAlloc(size);
    }

    S00e0d180_Node(S00e0d180_Node* parent, const char* name, int flags);
};

// @fnv 0x00e0d180
// src: HAVOK_LIB 0x00e0d180
extern "C" void __cdecl mergeSubTree(void* first, void* second, int index, int limit, float amount)

{

    int lvl = index;

    if (lvl > 6)
    {

        lvl = 6;
    }

    index = 0;

    int i = 0;

    if (((S00e0d180_Node*)second)->children.m_iElementCount > 0)
    {

        double d = 1.0 - amount;

        int n = 0;

        do
        {

            S00e0d180_Node* src = ((S00e0d180_Node*)second)->children[i];

            S00e0d180_Node* dst;

            if (!findChildWithHint((unsigned int)((S00e0d180_Node*)second)->children[i]->name, &index,
                              (FUN_00e0c690_owner*)first))
            {

                void* slot = S00e0d180_Node::operator new(sizeof(S00e0d180_Node));
                if (slot)
                {
                    int f = src->unk54;
                    dst = ::new (slot) S00e0d180_Node((S00e0d180_Node*)first, src->name, f);
                }
                else
                    dst = 0;
            }
            else
            {

                dst = ((S00e0d180_Node*)first)->children[index];
            }

            dst->values[lvl] = (float)((double)src->values[limit] * d + (double)dst->values[lvl]);

            dst->counts[lvl] = src->counts[limit];

            mergeSubTree(dst, src, lvl, limit, amount);

            n = ((S00e0d180_Node*)second)->children.m_iElementCount;

            if (index < n - 1)
            {

                ++index;
            }

            ++i;

        } while (i < n);
    }
}

struct PrintArray
{
    char* data;
    int size;
    int m_iCapacity;
};

struct PrintStream
{
    int unk00;
    short unk04;
    short unk06;
    int unk08;
    void __thiscall FUN_00cc0630(PrintArray* a1);
    void __thiscall InvokeSubObject(char a1);
    void __thiscall ProcessAndReturnValue_00cc01c0(const char* a1);
    void __thiscall FUN_00cc00e0();
};

struct PrintNode
{
    float values[8];
    unsigned short counts[8];
    PrintNode** children;
    int childCount;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    const char* name;
    unsigned int flags;
};

struct PrintConfig
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    bool unk10;
    PrintNode* unk14;
    char unk18;
    char unk19;
    bool unk1a;
};

// @fnv 0x00e0d2c0
// src: HAVOK_LIB 0x00e0d2c0
void __cdecl hkMonitorStreamAnalyzer_showCombinedThreadSummaryRec(PrintStream* stream, PrintNode* node, int depth, const int threads, const int spus,
                          PrintConfig* cfg)
{
    PrintArray pad;
    PrintStream line;
    pad.data = 0;
    pad.size = 0;
    pad.m_iCapacity = 0x80000000;
    line.FUN_00cc0630(&pad);
    int numFields = threads + spus;
    if (0 != depth)
    {
        if (cfg->unk10)
        {
            line.InvokeSubObject(cfg->unk14 == node ? cfg->unk18 : ' ');
        }
        int spacing = cfg->unk08 * (depth - 1);
        for (int k = 0; k < spacing; ++k)
            line.InvokeSubObject(' ');
        if (cfg->unk10)
        {
            if (0 < node->childCount)
            {
                line.InvokeSubObject((node->flags & 1) ? cfg->unk19 : cfg->unk18);
            }
            else
            {
                line.InvokeSubObject(32);
            }
        }
        int sumThreads = 0;
        for (int i = 0; i < numFields; ++i)
            sumThreads += (*(node->counts + i));
        hkOstream_printf(&line, "%s (%i) ", node->name, sumThreads);

        float total = 0.0f;
        float idx = 0.0f;
        int j = 0;
        int countSpus = 0;
        for (int i = 0; i < numFields; ++i)
        {
            if (cfg->unk1a)
            {
                line.InvokeSubObject('\t');
            }
            else
            {
                int kIter = (depth - 1) * cfg->unk0c + cfg->unk04 * i - pad.size + cfg->unk00;
                for (int k = 0; kIter > k; ++k)
                    line.InvokeSubObject(' ');
            }
            hkOstream_printf(&line, "%-6.3f (%i)", (double)node->values[i], (*(i + node->counts)));
            if (i < threads)
            {
                total += node->values[i];
                j += (*(node->counts + i));
            }
            else
            {
                idx += node->values[i];
                countSpus += node->counts[i];
            }
        }
        unsigned int col = numFields;
        if (threads > 1)
        {
            if (cfg->unk1a)
            {
                line.InvokeSubObject('\t');
            }
            else
            {
                int kIter = cfg->unk0c * (depth - 1) + cfg->unk04 * col - pad.size + cfg->unk00;
                for (int k = 0; k < kIter; ++k)
                    line.InvokeSubObject(' ');
            }
            col += 1;
            hkOstream_printf(&line, "%-6.3f (%i)", (double)(total / threads), j);
        }
        if (spus > 1)
        {
            if (cfg->unk1a)
            {
                line.InvokeSubObject('\t');
            }
            else
            {
                int kIter = cfg->unk0c * (depth - 1) + cfg->unk04 * col - pad.size + cfg->unk00;
                for (int k = 0; k < kIter; ++k)
                    line.InvokeSubObject(' ');
            }
            hkOstream_printf(&line, "%-6.3f (%i)", (double)(idx / spus), countSpus);
        }
        stream->ProcessAndReturnValue_00cc01c0(pad.data);
        stream->InvokeSubObject('\n');
    }
    if (!cfg->unk10 || (node->flags & 1))
    {
        for (int i = 0; i < node->childCount; ++i)
            hkMonitorStreamAnalyzer_showCombinedThreadSummaryRec(stream, ((*(i + (node->children)))), depth + 1, threads, spus, cfg);
    }
    line.FUN_00cc00e0();
    hkMemoryAllocator& heap = hkMemoryRouter_getInstance()->heap();
    pad.size = 0;
    if ((pad.m_iCapacity & 0x80000000u) == 0)
        heap.bufFree(pad.data, pad.m_iCapacity & 0x3fffffff);
}

struct MonNode;

struct MonNode
{
    float m_uiFilterValue[8];
    unsigned short m_uiItemCount[8];
    hkArrayBase<MonNode*> m_children;
    int unk3c;
    double m_dValue;
};
struct MonNodeList
{
    MonNode** m_data;
    int m_iElementCount;
    MonNode*& operator[](int i) const
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};
struct AnimationTimingInfo
{
    int m_iValueAt00;
    int m_iFrameCount;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float m_fValueAt18;
    float m_startTimeOffset;
    float getOffset() const
    {
        return m_startTimeOffset;
    }
};
struct FrameInfo
{
    const char* m_pHeading;
    int m_iColor;
    int m_iTimer0;
    int m_uiTimer1;
    float m_fStartTime;
    float m_fEndTime;
    int m_uiThreadId;
    int m_iTimer0Index;
    int m_iTimer1Index;
};
struct FrameInfoArray
{
    FrameInfo* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    const FrameInfo& operator[](int i) const
    {
        return m_data[i];
    }
};
struct FrameInfoArrays
{
    FrameInfoArray* m_data;
    int m_iElementCount;
    const FrameInfoArray& operator[](int i) const
    {
        return m_data[i];
    }
};
typedef hkArrayBase<float> FloatArray;

extern double DAT_0103c7c8;
extern float DAT_011bdd84;
extern double DAT_010ea718;
extern float DAT_010ea710;
static __forceinline float hkMin2(float a, float b)
{
    return a < b ? a : b;
}
static __forceinline float hkMax2(float a, float b)
{
    return a > b ? a : b;
}
static __forceinline float clampFrameTime(float t)
{
    return (t < DAT_010ea718) ? DAT_010ea710 : t;
}

static __forceinline float addOffset(float a, float b)
{
    return a + b;
}
static __forceinline float getOffset(const AnimationTimingInfo& i)
{
    return i.m_startTimeOffset;
}
// @fnv 0x00e0dd30
// src: HAVOK_LIB 0x00e0dd30
void __cdecl hkMonitorStreamAnalyzer_getTimerLimits(const MonNodeList& threadNodes, const AnimationTimingInfo& input,
                          const FrameInfoArrays& frameInfos, float& maxFrameTime, FloatArray& startTimes)
{
    int numThreads = threadNodes.GetLogicalSize();
    int frameEnd = input.m_iValueAt00 + input.m_iFrameCount;
    int numFrames = threadNodes[0]->m_children.GetLogicalSize();
    int numFramesToDraw = input.m_iFrameCount;
    if (frameEnd > numFrames)
    {
        numFramesToDraw = numFrames - input.m_iValueAt00;
        frameEnd = numFrames;
    }
    if (numFramesToDraw <= 0)
        return;

    int n = input.m_iFrameCount;
    {
        hkMemoryRouter* router = hkMemoryRouter_getInstance();
        hkMemoryAllocator* heap = router->m_heap;
        int cap = startTimes.m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = cap * 2;
            if (n >= cap2)
                cap2 = n;
            hkArrayUtil__reserve(heap, &startTimes, cap2, 4);
        }
        int numToFill = n - startTimes.m_iElementCount;
        float* p = startTimes.m_data + startTimes.m_iElementCount;
        for (int i = 0; i < numToFill; ++i)
            p[i] = 0.0f;
        startTimes.m_iElementCount = n;
    }

    maxFrameTime = 0.0f;
    for (int f = input.m_iValueAt00; f < frameEnd; ++f)
    {
        int idx = f - input.m_iValueAt00;
        const FrameInfo& info = frameInfos[0][f];
        int timer = info.m_uiTimer1 == 0 ? info.m_iColor : info.m_iTimer0;
        startTimes[idx] = 1e30f;
        for (int t = 0; t < numThreads; ++t)
        {
            hkArrayBase<MonNode*>& children = threadNodes[t]->m_children[f]->m_children;
            if (children.GetLogicalSize() <= 0)
                continue;
            for (int c = 0; c < children.GetLogicalSize(); ++c)
            {
                MonNode* node = children[c];
                startTimes[idx] = hkMin2((float)node->m_dValue, startTimes[idx]);
            }
            for (int c = 0; c < children.GetLogicalSize(); ++c)
            {
                MonNode* node = children[c];
                float frameTime = (float)(node->m_uiFilterValue[timer] + node->m_dValue - startTimes[idx]);
                maxFrameTime = hkMax2(frameTime, maxFrameTime);
            }
        }
    }
    if (input.m_startTimeOffset > 0.0f)
    {
        int f = input.m_iValueAt00;
        if (frameEnd - f >= 4)
        {
            int end4 = frameEnd - 3;
            do
            {
                startTimes[f - input.m_iValueAt00] =
                    addOffset(startTimes[f - input.m_iValueAt00], input.m_startTimeOffset);
                {
                    float offset1 = input.m_startTimeOffset;
                    startTimes[(f + 1) - input.m_iValueAt00] += offset1;
                }
                startTimes[(f + 2) - input.m_iValueAt00] = input.getOffset() + startTimes[(f + 2) - input.m_iValueAt00];
                {
                    float value3 = startTimes[(f + 3) - input.m_iValueAt00];
                    startTimes[(f + 3) - input.m_iValueAt00] = input.m_startTimeOffset + value3;
                }
                f += 4;
            } while (f < end4);
        }
        if (f < frameEnd)
            do
            {
                {
                    int index4 = f - input.m_iValueAt00;
                    startTimes[index4] += input.m_startTimeOffset;
                }
                ++f;
            } while (f < frameEnd);
    }
    if (input.m_fValueAt18 > 0.0f)
    {
        maxFrameTime = input.m_fValueAt18;
        return;
    }
    if (numFramesToDraw == 1)
    {
        __declspec(align(8)) unsigned int ms = (unsigned int)(maxFrameTime / 1000.0);
        ms |= ms >> 1;
        ms |= ms >> 2;
        ms |= ms >> 4;
        ms |= ms >> 8;
        ms |= ms >> 16;
        ++ms;
        float upper = (float)(0.25 * DAT_011bdd84);
        float rounded = (float)((float)ms * 1000.0);
        float target = hkMin2(upper, rounded - DAT_011bdd84);
        maxFrameTime = (float)(target * DAT_0103c7c8 + DAT_011bdd84);
        float m = maxFrameTime;
        float r = (m < DAT_010ea718) ? DAT_010ea710 : m;
        maxFrameTime = r;
        DAT_011bdd84 = r;
    }
}

struct PixelSource
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_10;
    int m_14;
};
int __cdecl hkMonitorStreamAnalyzer_writeStatisticsDetailsToTexture(int a1, PixelSource* a2, int a3, void** out1, int* out2, int a6);
void __cdecl hkMemoryRouter_easyFree(hkMemoryAllocator* alloc, void* p);
// @fnv 0x00e0e470
// src: HAVOK_LIB 0x00e0e470
void __cdecl hkMonitorStreamAnalyzer_writeStatisticsDetailsToTga(int a1, PixelSource* a2, int a3, E0C150Stream* a4, int a5)
{
    void* out1 = 0;
    int q = 0;
    hkMonitorStreamAnalyzer_writeStatisticsDetailsToTexture(a1, a2, a3, &out1, &q, a5);
    void* p = *(void* volatile*)&out1;
    if (p != 0)
    {
        WriteTgaImage(p, a4, a2->m_14, q);
        hkMemoryRouter* h = hkMemoryRouter_getInstance();
        hkMemoryRouter_easyFree(h->m_heap, (void*)p);
    }
}

struct ReportFlag
{
    char b;
    ReportFlag() : b(0)
    {}
};
struct ReportResult
{
    char b;
};
struct ReportNode : FUN_00e0d000Total
{
    void ProcessEntries_00e10930();
};
struct ReportMap
{
    void* data;
    int size;
    int mask;
    int flags;
    void FUN_00d87790(ReportFlag);
    int hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator();
    ReportNode* hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(int);
    int FindNextUsedSlot(int);
    void SetBoolFromThreshold(ReportResult*, int);
    bool valid(int i)
    {
        ReportResult b;
        SetBoolFromThreshold(&b, i);
        return b.b != 0;
    }
    void FreeBuffer();
};
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator*, void*, int, int);
struct ReportArray
{
    ReportNode** data;
    int size;
    int capacity;
    ReportArray() : data(0), size(0), capacity(0x80000000)
    {}
    void reserve(int n)
    {
        hkMemoryAllocator& heap = hkMemoryRouter_getInstance()->temp();
        int cap = capacity & 0x3fffffff;
        if (cap < n)
        {
            int next = cap * 2;
            if (n >= next)
                next = n;
            hkArrayUtil__reserve(&heap, this, next, 4);
        }
    }
    void release()
    {
        hkMemoryAllocator& heap = hkMemoryRouter_getInstance()->temp();
        size = 0;
        if ((capacity & 0x80000000u) == 0)
            heap.bufFree(data, (capacity & 0x3fffffff) * 4);
    }
};
bool __cdecl hkCompareInfosBySize(ReportNode*, ReportNode*);
void __cdecl hkAlgorithm_quickSortRecursive_hkMonitorStreamAnalyzerPrintByTypeInfo_bool_cdecl_hkMonitorStreamAnalyzerPrintByTypeInfo_const_hkMonitorStreamAnalyzerPrintByTypeInfo_const(ReportNode**, int, int, bool(__cdecl*)(ReportNode*, ReportNode*));
void __cdecl hkBuildSizePerName(FUN_00e0d000*, ReportMap*);
// @fnv 0x00e0fc50
// src: HAVOK_LIB 0x00e0fc50
static __declspec(noinline) void printStatisticsByType(FUN_00e0d000* root, float threshold, void* stream)
{
    ReportArray nodes;
    {
        ReportMap map;
        map.FUN_00d87790(ReportFlag());
        hkBuildSizePerName(root, &map);
        nodes.reserve(map.size);
        int it = map.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator();
        while (map.valid(it))
        {
            ReportNode* item = map.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(it);
            int count = *(volatile int*)&nodes.size;
            ReportNode** data = *(ReportNode * * volatile*)&nodes.data;
            data[count] = item;
            ++nodes.size;
            it = map.FindNextUsedSlot(it);
        }
        if (nodes.size > 1)
            hkAlgorithm_quickSortRecursive_hkMonitorStreamAnalyzerPrintByTypeInfo_bool_cdecl_hkMonitorStreamAnalyzerPrintByTypeInfo_const_hkMonitorStreamAnalyzerPrintByTypeInfo_const(nodes.data, 0, nodes.size - 1, hkCompareInfosBySize);
        map.FreeBuffer();
    }
    float totalTime = nodes.data[nodes.size - 1]->values[1];
    hkOstream_printf(stream, "\n\n");
    hkOstream_printf(stream, "************************************\n");
    hkOstream_printf(stream, "********** Per Type Times    *******\n");
    hkOstream_printf(stream, "************************************\n");
    for (int i = nodes.size - 1; i >= 0; --i)
    {
        ReportNode* node = nodes.data[i];
        if (node->values[1] > totalTime * threshold)
        {
            hkOstream_printf(stream, "\n");
            hkOstream_printf(stream, "************************************\n\n");
            for (int j = 0; j < node->linkedFUN_00e0d000.size; ++j)
            {
                hkOstream_printf(stream, "\t\t");
                WriteItemStats(stream, 0.0f, reinterpret_cast<S_00e0bfe0_Item*>(&node->linkedFUN_00e0d000.data[j]));
            }
            WriteItemStats(stream, totalTime, reinterpret_cast<S_00e0bfe0_Item*>(node));
            for (int j = 0; j < node->childFUN_00e0d000.size; ++j)
            {
                hkOstream_printf(stream, "\t\t");
                WriteItemStats(stream, 0.0f, reinterpret_cast<S_00e0bfe0_Item*>(&node->childFUN_00e0d000.data[j]));
            }
        }
        node->ProcessEntries_00e10930();
        monitorDebugHeap(hkMemoryRouter_getInstance()).blockFree(node, 0x70);
    }
    nodes.release();
}
volatile FUN_00e0d000* reportRoot;
void* volatile reportStream;
volatile float reportThreshold;
void reportCaller()
{
    printStatisticsByType((FUN_00e0d000*)reportRoot, reportThreshold, reportStream);
}

namespace fnv_00e0d000 {


extern "C" void _ReadWriteBarrier(void);
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl ResizeAudioStream(int aiHeap, void* apList, int aiGrow);

struct FUN_00e0d000_cls;

struct SubList
{
    void** m_ppItems;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
};

struct OwnerNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    SubList m_kNode;
};

struct FUN_00e0d000_cls
{
    float m_af00[8];
    unsigned short m_au20[8];
    int m_i30;
    int m_i34;
    unsigned int m_u38;
    int unk3c;
    double m_d40;
    OwnerNode* m_pSharedOwner;
    int m_i4c;
    int m_i50;
    int m_i54;

    FUN_00e0d000_cls* DoNothing_00e0d000(OwnerNode* apOwner, int aiA, int aiB);
};

// @fnv 0x00e0d000
// src: GUESS 0x00e0d000 (confidence: high)
FUN_00e0d000_cls* FUN_00e0d000_cls::DoNothing_00e0d000(OwnerNode* apOwner, int aiA, int aiB)
{
    m_i30 = 0;
    m_i34 = 0;
    m_u38 = 0x80000000u;
    m_pSharedOwner = apOwner;
    m_i4c = aiA;
    m_i50 = 0;
    m_i54 = aiB;
    if (apOwner != 0)
    {
        SubList* list = &apOwner->m_kNode;
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        if (list->m_iArrayLength == (int)(list->m_uCapFlags & 0x3fffffffu))
        {
            ResizeAudioStream((int)holder->m_heap, list, 4);
        }
        void** slot = list->m_ppItems + list->m_iArrayLength;
        _ReadWriteBarrier();
        *slot = this;
        list->m_iArrayLength++;
    }
    for (int i = 0; i < 8; i++)
    {
        m_af00[i] = 0.0f;
        m_au20[i] = 0;
    }
    m_d40 = 0.0;
    return this;
}
}  // namespace fnv_00e0d000

namespace fnv_00e0d640 {
struct FUN_00e0d640_buf
{
    int unk00;
    int unk04;
    int unk08;
    char* m_pData;
    int m_iLen;
    int m_uiObjectFlags;
    void Destroy();
    void Init(char** pp);
    void PutChar(int c);
    void Assign(char* p);
};
struct FUN_00e0d640_cfg
{
    int m_iBase;
    int m_iStep;
    int m_iVal;
    int unk0C;
    unsigned char m_bFlag;
    char unk11[9];
    char m_bTab;
};
int GetTreeWidth(int a, int b, int c, int d);
void hkOstream_printf(FUN_00e0d640_buf* b, const char* fmt, ...);
hkMemoryRouter* hkMemoryRouter_getInstance();
void hkMonitorStreamAnalyzer_showCombinedThreadSummaryRec(FUN_00e0d640_buf* a, int b, int c, int d, int e, FUN_00e0d640_cfg* f);

// @fnv 0x00e0d640
// src: HAVOK_LIB 0x00e0d640
void __cdecl hkMonitorStreamAnalyzer_showCombinedThreadSummaryForSingleFrame(int a1, int a2, int a3, FUN_00e0d640_buf* a4, FUN_00e0d640_cfg* s)
{
    int i = 0;
    s->m_iBase = GetTreeWidth(a1, i, s->m_iVal, s->m_bFlag);
    FUN_00e0d640_buf buf;
    buf.m_pData = (char*)i;
    buf.m_iLen = i;
    buf.m_uiObjectFlags = (int)0x80000000;
    buf.Init(&buf.m_pData);
    hkOstream_printf(&buf, "Timer Name");
    if (a2 > 1 || a3 > 0)
    {
        for (i = 0; i < a2; i++)
        {
            if (s->m_bTab)
                buf.PutChar(9);
            else
            {
                int n = s->m_iStep * i - buf.m_iLen + s->m_iBase;
                if (n > 0)
                {
                    int c = n;
                    do
                    {
                        buf.PutChar(0x20);
                        c--;
                    } while (c != 0);
                }
            }
            hkOstream_printf(&buf, "Thread %d", i);
        }
        for (i = 0; i < a3; i++)
        {
            if (s->m_bTab)
                buf.PutChar(9);
            else
            {
                int n = (i + a2) * s->m_iStep - buf.m_iLen + s->m_iBase;
                if (n > 0)
                {
                    int c = n;
                    do
                    {
                        buf.PutChar(0x20);
                        c--;
                    } while (c != 0);
                }
            }
            hkOstream_printf(&buf, "Spu %d", i);
        }
        int k = a2 + a3;
        if (a2 > 1)
        {
            if (s->m_bTab)
                buf.PutChar(9);
            else
            {
                int n = s->m_iStep * k - buf.m_iLen + s->m_iBase;
                if (n > 0)
                {
                    int c = n;
                    do
                    {
                        buf.PutChar(0x20);
                        c--;
                    } while (c != 0);
                }
            }
            k++;
            hkOstream_printf(&buf, "Average Cpu");
        }
        if (a3 > 1)
        {
            if (s->m_bTab)
                buf.PutChar(9);
            else
            {
                int n = s->m_iStep * k - buf.m_iLen + s->m_iBase;
                if (n > 0)
                {
                    int c = n;
                    do
                    {
                        buf.PutChar(0x20);
                        c--;
                    } while (c != 0);
                }
            }
            hkOstream_printf(&buf, "Average Spu");
        }
    }
    a4->Assign(buf.m_pData);
    hkOstream_printf(a4, "\n\n");
    hkMonitorStreamAnalyzer_showCombinedThreadSummaryRec(a4, a1, 0, a2, a3, s);
    buf.Destroy();
    hkMemoryRouter* h = hkMemoryRouter_getInstance();
    hkMemoryAllocator* al = h->m_heap;
    buf.m_iLen = 0;
    if ((buf.m_uiObjectFlags & 0x80000000) == 0)
        al->bufFree(buf.m_pData, buf.m_uiObjectFlags & 0x3fffffff);
}
}  // namespace fnv_00e0d640

__forceinline const char* loadKey(const char* const volatile& s)
{
    return s;
}

struct StatsValue
{
    int value;
    StatsValue(int v) : value(v)
    {}
};


struct NodeInitializer
{
    FUN_00e0d000* DoNothing_00e0d000(int parent, const char* name, StatsValue value);
};

// src: HAVOK_LIB 0x00e0cb80
static __declspec(noinline) FUN_00e0d000* hkFindChildByName(FUN_00e0d000* owner, const char* key, S_Flag fallback)
{
    for (int n = 0; n < owner->childCount; ++n)
    {
        if (hkString_strCmp(loadKey(key), owner->children[n]->name) == 0)
            return owner->children[n];
    }
    if (fallback.b && owner->childCount > 0)
        return owner->children[0];
    return 0;
}

__forceinline int asLocal(const volatile int& v)
{
    return v;
}

// @fnv 0x00e0d880
// src: HAVOK_LIB 0x00e0d880
void __cdecl hkMakeSumRecursive(int parentArg, FUN_00e0d000* source)
{
    for (int i = 0; i < source->childCount; ++i)
    {
        FUN_00e0d000* item = source->children[i];
        FUN_00e0d000* dst = hkFindChildByName((FUN_00e0d000*)parentArg, item->name, S_Flag());

        if (!dst)
        {
            int parent = parentArg;
            hkMemoryRouter* holder = hkMemoryRouter_getInstance();
            void* mem = holder->m_heap->blockAlloc(sizeof(FUN_00e0d000));

            if (mem)
            {
                dst = ((NodeInitializer*)mem)->DoNothing_00e0d000(parent, item->name, StatsValue(item->unk54));
            }
            else
            {
                dst = 0;
            }
        }

        dst->accumulate(*item);
        hkMakeSumRecursive((int)dst, item);
    }
}

namespace fnv_00e0d980 {
inline void* __cdecl operator new(unsigned int, void* where) throw()
{
    return where;
}
hkMemoryRouter* hkMemoryRouter_getInstance() throw();
void ResizeAudioStream(hkMemoryAllocator& h, void* arr, int elemSize) throw();

struct S_e0d980_Str
{
    int unk0;
    S_e0d980_Str(int a) throw();
    S_e0d980_Str(const S_e0d980_Str& o) throw();
    ~S_e0d980_Str() throw();
};
struct S_e0d980_Item
{
    S_e0d980_Str name;
    int value;
    S_e0d980_Item(int a) throw() : name(a)
    {}
    S_e0d980_Item(const S_e0d980_Item& o) throw() : name(o.name)
    {
        value = o.value;
    }
};
struct S_e0d980_Arr
{
    S_e0d980_Item* data;
    int size;
    unsigned int cap;
    void push(const S_e0d980_Item& it)
    {
        hkMemoryRouter* r = hkMemoryRouter_getInstance();
        if (size == (int)(cap & 0x3fffffff))
            ResizeAudioStream(r->heap(), this, 8);
        S_e0d980_Item* p = data + size;
        if (p)
            new (p) S_e0d980_Item(it);
        size++;
    }
};
struct S_e0d980_Obj
{
    int unk0;
    int unk4;
    S_e0d980_Arr arr;
    void hkMonitorStreamColorTable_addColor(int a, int b) throw();
};
// @fnv 0x00e0d980
// src: HAVOK_LIB 0x00e0d980
void S_e0d980_Obj::hkMonitorStreamColorTable_addColor(int a, int b) throw()
{
    S_e0d980_Item t(a);
    t.value = b;
    arr.push(t);
}
}  // namespace fnv_00e0d980

extern float DAT_01012054;

typedef hkArrayBase<float> S00e0e4e0_FArr;
typedef hkArrayBase<void*> S00e0e4e0_PArr;
struct S00e0e4e0_Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S00e0e4e0_Entry
{
    S00e0e4e0_Info* m_info;
    int unk04;
    int unk08;
};
struct S00e0e4e0_EntryList
{
    S00e0e4e0_Entry* m_data;
};
struct S00e0e4e0_Node;
struct S00e0e4e0_NodeArr
{
    S00e0e4e0_Node** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S00e0e4e0_Node*& operator[](int i)
    {
        return m_data[i];
    }
    S00e0e4e0_Node* const& operator[](int i) const
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};
struct S00e0e4e0_Node
{
    float m_iSlotIds[8];
    unsigned short m_counts[8];
    S00e0e4e0_NodeArr m_children;
};
struct S00e0e4e0_Layout
{
    int unk00;
    int m_numPages;
    int m_width0;
    int m_width1;
    int m_extra;
    int m_height;
};

void __cdecl hkMonitorStreamAnalyzer_getTimerLimits(S00e0e4e0_NodeArr& img, S00e0e4e0_Layout* lay, S00e0e4e0_EntryList* list, float* f,
                          S00e0e4e0_FArr* out);
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* alloc, void* arr, int n, int elemSize);
static __forceinline void S00e0e4e0_push(S00e0e4e0_PArr* out, void* v)
{
    hkMemoryAllocator& a = hkMemoryRouter_getInstance()->heap();
    if (out->m_iElementCount == (out->m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(&a, out, 4);
    out->m_data[out->m_iElementCount] = v;
    out->m_iElementCount++;
}

static void outputStatsForFrame(float value, float step, int axis, S00e0e4e0_Node* node, int n, S00e0e4e0_PArr* out);

static __declspec(noinline) int getNodeSampledAtTick(int row, int col, const S00e0e4e0_NodeArr& nodes, int height, float range,
                                             float value, S00e0e4e0_Info* info);

// @fnv 0x00e0e4e0
// src: HAVOK_LIB 0x00e0e4e0
int __cdecl hkMonitorStreamAnalyzer_reverseLookupNodeAtTgaSample(int x, int y, S00e0e4e0_NodeArr& img, S00e0e4e0_Layout* lay, S00e0e4e0_EntryList* list)
{
    int numLevels = img.GetLogicalSize();
    int numPages = lay->m_numPages;
    if (numLevels < 1)
        return 0;
    int border = (numPages > 1) ? 0x20 : 0;
    if (x < border || x >= lay->m_height)
        return 0;
    int w = lay->m_width1 + lay->m_width0;
    int h = lay->m_height - border;
    int stride = w * numLevels + lay->m_extra;
    int total = stride * numPages;
    if (y < 0 || y >= total)
        return 0;
    int idx = total - y - 1;
    int row = idx / stride;
    int lvl = idx % stride / w;
    float range = DAT_01012054;
    S00e0e4e0_FArr arr;
    arr.m_data = 0;
    arr.m_iElementCount = 0;
    arr.m_iCapacityState = 0x80000000;
    hkMonitorStreamAnalyzer_getTimerLimits(img, lay, list, &range, &arr);
    S00e0e4e0_Node** slot = &img.m_data[lvl];
    S00e0e4e0_Info* info = list->m_data[lvl].m_info;
    int res = getNodeSampledAtTick(row, x - border, (*slot)->m_children, h, range, arr.m_data[row], info);
    hkMemoryAllocator& a = hkMemoryRouter_getInstance()->heap();
    arr.m_iElementCount = 0;
    if ((arr.m_iCapacityState & 0x80000000) == 0)
        a.bufFree(arr.m_data, (arr.m_iCapacityState & 0x3fffffff) * sizeof(float));
    return res;
}

__declspec(nothrow) hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
__declspec(nothrow) void __cdecl ResizeAudioStream(hkMemoryAllocator*, void*, int);
__declspec(nothrow) void __cdecl hkArrayUtil__reserve(hkMemoryAllocator*, void*, int, int);
__declspec(nothrow) int __cdecl hkString_strCmp(const char*, const char*);
struct AccumNode
{
    __declspec(nothrow) void Accumulate(AxisData*, hkMonitorStream::TimerCommand*, hkMonitorStream::TimerCommand*);
};
__forceinline hkMemoryAllocator& statsHeap()
{
    return hkMemoryRouter_getInstance()->heap();
}
namespace StatHeap {
hkMemoryRouter* hkMemoryRouter_getInstance();
}
struct BoolArg
{
    char b;
    __forceinline BoolArg(bool v)
    {
        b = v;
    }
};
// src: HAVOK_LIB 0x00e0d100
static __declspec(noinline) __declspec(nothrow) FUN_00e0d000* createNewNode(FUN_00e0d000* parent, const char* name,
                                                                           hkMonitorStreamAnalyzer::Node::NodeType type, BoolArg reuse)
{
    const char* const* pn = &name;
    const char* text = *pn;
    if (reuse.b)
    {
        for (int i = 0; parent && text && i < parent->childCount; ++i)
        {
            if (parent->children[i]->name && hkString_strCmp(parent->children[i]->name, text) == 0)
                return parent->children[i];
        }
    }
    void* mem = StatHeap::hkMemoryRouter_getInstance()->heap().blockAlloc(sizeof(FUN_00e0d000));
    return mem ? new (mem) FUN_00e0d000((int)parent, text, type) : 0;
}
struct Record
{
    const char* name;
    unsigned int x;
    unsigned int y;
};
struct ExtendedRecord
{
    Record timer;
    const char* extraName;
};
struct MetricRecord
{
    const char* name;
    float value;
};
struct RecordArray
{
    Record* data;
    int size;
    int capacity;
    Record local[16];
    __forceinline __declspec(nothrow) RecordArray() : data(local), size(0), capacity(0x80000010)
    {}
    __forceinline __declspec(nothrow) ~RecordArray()
    {
        release();
    }
    __forceinline void push(const Record& r)
    {
        hkMemoryAllocator& heap = hkMemoryRouter_getInstance()->heap();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(&heap, this, 12);
        new (data + size) Record(r);
        ++size;
    }
    __forceinline void resize(int count)
    {
        hkMemoryAllocator& heap = hkMemoryRouter_getInstance()->heap();
        int cap = capacity & 0x3fffffff;
        if (cap < count)
        {
            int newCap = cap * 2;
            if (count >= newCap)
                newCap = count;
            hkArrayUtil__reserve(&heap, this, newCap, 12);
        }
        size = count;
    }
    __forceinline __declspec(nothrow) void release()
    {
        hkMemoryAllocator& heap = hkMemoryRouter_getInstance()->heap();
        size = 0;
        if ((capacity & 0x80000000u) == 0)
            heap.bufFree(data, (capacity & 0x3fffffff) * 12);
        data = 0;
        capacity = 0x80000000;
    }
};
// @fnv 0x00e0e630
// src: HAVOK_LIB 0x00e0e630
FUN_00e0d000* __cdecl hkMonitorStreamAnalyzer_makeStatisticsTreeForSingleFrame(const char* begin, const char* end, AxisData* info, const char* name, S_Flag reuse)
{
    const char* cursor = begin;
    const char* tag;
    void* mem = StatHeap::hkMemoryRouter_getInstance()->heap().blockAlloc(sizeof(FUN_00e0d000));
    FUN_00e0d000* node = mem ? new (mem) FUN_00e0d000(0, name, 1) : 0;
    FUN_00e0d000* root = node;
    RecordArray frames;
    RecordArray openFrames;
    while (cursor < end)
    {
        const Record* r = (const Record*)cursor;
        tag = r->name;
        if ((unsigned int)tag < 10)
        {
            cursor += 4;
            continue;
        }
        switch (*tag)
        {
        case 'T': {
            BoolArg rb(reuse.b != 0);
            node = createNewNode(node, tag += 2, hkMonitorStreamAnalyzer::Node::NODE_TYPE_TIMER, rb);
            frames.push(*r);
            openFrames.push(*r);
            cursor += 12;
            break;
        }
        case 'E': {
            if (!frames.size)
                return root;
            const Record* start = &frames.data[frames.size - 1];
            if (tag[2] && hkString_strCmp(start->name + 2, tag + 2))
            {
                return root;
            }
            ((AccumNode*)node)->Accumulate(info, (hkMonitorStream::TimerCommand*)start, (hkMonitorStream::TimerCommand*)r);
            node = node->linked;
            --frames.size;
            openFrames.resize(openFrames.size - 1);
            cursor += 12;
            break;
        }
        case 'O':
            frames.push(*r);
            node = createNewNode(node, ((const ExtendedRecord*)r)->extraName, hkMonitorStreamAnalyzer::Node::NODE_TYPE_TIMER, BoolArg(reuse.b != 0));
            openFrames.push(*r);
            cursor += 16;
            break;
        case 'L': {
            frames.push(*r);
            openFrames.push(*r);
            BoolArg rb(reuse.b != 0);
            node = createNewNode(node, tag += 2, hkMonitorStreamAnalyzer::Node::NODE_TYPE_TIMER, rb);
            Record section = *r;
            section.name = ((const ExtendedRecord*)r)->extraName;
            frames.push(section);
            openFrames.push(section);
            BoolArg rb2(reuse.b != 0);
            node = createNewNode(node, section.name += 2, hkMonitorStreamAnalyzer::Node::NODE_TYPE_TIMER, rb2);
            cursor += 16;
            break;
        }
        case 'S': {
            if (!frames.size)
                return root;
            Record* start = &frames.data[frames.size - 1];
            ((AccumNode*)node)->Accumulate(*(AxisData* volatile*)&info, (hkMonitorStream::TimerCommand*)start, (hkMonitorStream::TimerCommand*)r);
            node = node->linked;
            BoolArg rb(reuse.b != 0);
            node = createNewNode(node, tag += 2, hkMonitorStreamAnalyzer::Node::NODE_TYPE_TIMER, rb);
            *start = *r;
            cursor += 12;
            break;
        }
        case 'l':
            if (frames.size <= 1 || frames.data[frames.size - 1].name[0] != 'S')
                return root;
            ((AccumNode*)node)->Accumulate(info, (hkMonitorStream::TimerCommand*)&frames.data[frames.size - 1], (hkMonitorStream::TimerCommand*)r);
            node = node->linked;
            --frames.size;
            openFrames.resize(openFrames.size - 1);
            ((AccumNode*)node)->Accumulate(info, (hkMonitorStream::TimerCommand*)&frames.data[frames.size - 1], (hkMonitorStream::TimerCommand*)r);
            node = node->linked;
            --frames.size;
            openFrames.resize(openFrames.size - 1);
            cursor += 12;
            break;
        case 'M': {
            BoolArg rb(reuse.b != 0);
            FUN_00e0d000* metric = createNewNode(node, tag += 2, hkMonitorStreamAnalyzer::Node::NODE_TYPE_SINGLE, rb);
            metric->values[0] += ((const MetricRecord*)r)->value;
            ++metric->counts[0];
            cursor += 8;
            break;
        }
        case 'P': {
            BoolArg rb(reuse.b != 0);
            node = createNewNode(node, tag += 2, hkMonitorStreamAnalyzer::Node::NODE_TYPE_DIRECTORY, rb);
            cursor += 4;
            break;
        }
        case 'p':
            node = node->linked;
            if (!node)
                return root;
            cursor += 4;
            break;
        case 'N':
            cursor += 4;
            break;
        case 'F':
            break;
        case 'm':
            cursor += 12;
            break;
        default:
            return root;
        }
    }
    return root;
}

typedef hkArray<E0C860Node*> S00e0ee00_Children;
struct S00e0ee00_Root
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
    S00e0ee00_Children m_children;
    S00e0ee00_Root(int a, const char* name, int b);
};
extern const char DAT_01063cbc[];
E0C860Node* __cdecl hkMonitorStreamAnalyzer_makeStatisticsTreeForSingleFrame(char* begin, char* end, S_e0ce00_Block* record, int unk0, hkBool flag);

struct S00e0ee00_Analyzer : public S_e0ce00
{
    S00e0ee00_Root* __cdecl hkMonitorStreamAnalyzer_makeStatisticsTreeForMultipleFrames(int aIndex, hkBool aFlag);
};
// @fnv 0x00e0ee00
// src: HAVOK_LIB 0x00e0ee00
S00e0ee00_Root* __cdecl S00e0ee00_Analyzer::hkMonitorStreamAnalyzer_makeStatisticsTreeForMultipleFrames(int aIndex, hkBool aFlag)
{
    S00e0ee00_Root* root = new (hkMemoryRouter_getInstance()->heap().blockAlloc(0x58)) S00e0ee00_Root(0, DAT_01063cbc, 1);
    root->m_children.setSize(m_arrays[aIndex].m_iElementCount);
    for (int i = 0; i < m_arrays[aIndex].m_iElementCount; i++)
    {
        S_e0ce00_Block& b = m_arrays[aIndex].m_data[i];
        char* begin = m_buf + b.unk1C;
        char* end = m_buf + b.unk20;
        E0C860Node*& slot = root->m_children[i];
        slot = hkMonitorStreamAnalyzer_makeStatisticsTreeForSingleFrame(begin, end, &b, b.unk0, aFlag);
    }
    return root;
}

namespace fnv_00e0f710 {
inline void* __cdecl operator new(unsigned int, void* w) throw()
{
    return w;
}


hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
int __cdecl hkArrayUtil__reserve(hkMemoryAllocator& heap, void* arr, int newCap, int elemSize);

struct S_00e0f710_Elem
{
    void* m_data;
    int m_iElementCount;
    unsigned int m_cap;
    S_00e0f710_Elem() : m_data(0), m_iElementCount(0), m_cap(0x80000000)
    {}
    __forceinline void ClearAndRelease()
    {
        hkMemoryAllocator& h2 = hkMemoryRouter_getInstance()->heap();
        unsigned int c = m_cap;
        m_iElementCount = 0;
        if ((c & 0x80000000) == 0)
        {
            h2.bufFree(m_data, (c & 0x3fffffff) * 36);
        }
        m_data = 0;
        m_cap = 0x80000000;
    }
};

struct S_00e0f710_Cls
{
    S_00e0f710_Elem* m_data;
    int m_iElementCount;
    unsigned int m_cap;
    int unk0c;
    int unk10;
    int unk14;
    int m_kPointA;
    int m_kPointB;

    void hkMonitorStreamAnalyzer_reset();
    void hkMonitorStreamAnalyzer_resetNumThreads(int a, int b);
};

// @fnv 0x00e0f710
// src: HAVOK_LIB 0x00e0f710
void S_00e0f710_Cls::hkMonitorStreamAnalyzer_resetNumThreads(int a, int b)
{
    hkMemoryAllocator& h = hkMemoryRouter_getInstance()->heap();
    int n = a + b;
    int cap = m_cap & 0x3fffffff;
    if (cap < n)
    {
        int c2 = cap * 2;
        hkArrayUtil__reserve(h, this, (n < c2) ? c2 : n, 12);
    }
    int diff = m_iElementCount - n;
    S_00e0f710_Elem* p = m_data + n;
    if (diff > 0)
    {
        for (int i = 0; i < diff; ++i)
        {
            p[i].ClearAndRelease();
        }
    }
    int sz = m_iElementCount;
    S_00e0f710_Elem* base = m_data;
    int fill = n - sz;
    S_00e0f710_Elem* q = base + sz;
    for (int i = 0; i < fill; ++i)
    {
        new (q) S_00e0f710_Elem();
        ++q;
    }
    m_iElementCount = n;
    m_kPointB = b;
    m_kPointA = a;
    hkMonitorStreamAnalyzer_reset();
}
}  // namespace fnv_00e0f710

namespace fnv_00e10930 {
struct S_00e0d0a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;

    void ClearItems();
};



hkMemoryRouter* hkMemoryRouter_getInstance();

struct S_00e10930_Foo : S_00e0d0a0
{
    S_00e0d0a0* unk58;
    int unk5c;
    int unk60;
    S_00e0d0a0* unk64;
    int unk68;
    int unk6c;

    void ProcessEntries_00e10930();
};

// @fnv 0x00e10930
// src: GUESS 0x00e10930 (confidence: low)
void S_00e10930_Foo::ProcessEntries_00e10930()
{
    hkMemoryAllocator* ebp = (&monitorDebugHeap(hkMemoryRouter_getInstance()));

    S_00e0d0a0* edi = unk64;
    int eax = unk68;
    if (eax > 0)
    {
        int ebx = eax;
        do
        {
            edi->ClearItems();
            edi++;
            ebx--;
        } while (ebx != 0);
    }

    eax = unk6c;
    unk68 = 0;
    if ((eax & 0x80000000) == 0)
    {
        ebp->bufFree(unk64, (eax & 0x3fffffff) * 0x58);
    }

    unk64 = 0;
    unk6c = 0x80000000;

    ebp = (&monitorDebugHeap(hkMemoryRouter_getInstance()));

    edi = unk58;
    eax = unk5c;
    if (eax > 0)
    {
        int ebx = eax;
        do
        {
            edi->ClearItems();
            edi++;
            ebx--;
        } while (ebx != 0);
    }

    eax = unk60;
    unk5c = 0;
    if ((eax & 0x80000000) == 0)
    {
        ebp->bufFree(unk58, (eax & 0x3fffffff) * 0x58);
    }

    unk58 = 0;
    unk60 = 0x80000000;

    ClearItems();
}
}  // namespace fnv_00e10930

__declspec(noinline) E0CC40Node* __cdecl FindNodeAtTime(E0CC40Node*, E0CC40Node*, double, int);

template <class T> __forceinline void copyFrameTicks(T* dst, int count, const T& value)
{
    for (int i = 0; i < count; ++i)
        dst[i] = value;
}

template <class T> struct FrameTickArrayBase
{ // local form of hkArrayBase: 0x00e0cec0 needs append(allocator, value) with ResizeAudioStream/copyFrameTicks, absent from the shared base.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline T& back()
    {
        return m_data[m_iElementCount - 1];
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int capacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void append(hkMemoryAllocator& allocator, const T& value)
    {
        if (m_iElementCount == capacity())
            ResizeAudioStream(&allocator, this, sizeof(T));
        copyFrameTicks(m_data + m_iElementCount, 1, value);
        ++m_iElementCount;
    }
};

struct FrameTickAllocator
{
    __forceinline hkMemoryAllocator& get(const void*)
    {
        return hkMemoryRouter_getInstance()->heap();
    }
};

template <class T> struct FrameTickArray : FrameTickArrayBase<T>
{
    __forceinline void AddBack(const T& value)
    {
        FrameTickArrayBase<T>::append(FrameTickAllocator().get(this), value);
    }
};

// @fnv 0x00e0cec0
// src: HAVOK_LIB 0x00e0cec0
static __declspec(noinline) void outputStatsForFrame(float start, float step, int axis, S00e0e4e0_Node* inputNode, int count,
                                              S00e0e4e0_PArr* output)

{

    MonNode* node = reinterpret_cast<MonNode*>(inputNode);

    FrameTickArray<MonNode*>& out = *reinterpret_cast<FrameTickArray<MonNode*>*>(output);
    MonNode* first = ((FrameTickArray<MonNode*>&)node->m_children)[0];
    MonNode* last = ((FrameTickArray<MonNode*>&)node->m_children).back();
    double leading = first->m_dValue - start;
    double t = 0.0;
    int n = count;
    while (n != 0 && leading > t)
    {
        t += step;
        out.AddBack(0);
        --n;
    }
    double end = last->m_uiFilterValue[axis] + last->m_dValue - start;
    node->m_dValue = first->m_dValue;
    node->m_uiFilterValue[axis] = (float)(start + end - node->m_dValue + 1.0);
    MonNode* hint = 0;
    while (n != 0 && t < end)
    {
        hint = (MonNode*)::FindNodeAtTime((E0CC40Node*)node, (E0CC40Node*)hint, t + start, axis);
        if (hint)
            out.AddBack(hint);
        t += step;
        --n;
    }
}
#pragma optimize("", on)

namespace NodeTickSupport {

template <class T> struct NodeTickArrayBase
{
    T* data;
    int size;
    int flags;
    __forceinline T& operator[](int index)
    {
        return data[index];
    }
    __forceinline T& back()
    {
        return data[size - 1];
    }
    __forceinline int GetLogicalSize() const
    {
        return size;
    }
    __forceinline int capacity() const
    {
        return flags & 0x3fffffff;
    }
    __forceinline void clear()
    {
        size = 0;
    }
};
template <class T> struct NodeTickArray : NodeTickArrayBase<T>
{
    __forceinline NodeTickArray()
    {
        data = 0;
        size = 0;
        flags = 0x80000000;
    }
    __forceinline void reserveExactly(int count)
    {
        hkMemoryAllocator& alloc = hkMemoryRouter_getInstance()->heap();
        if (capacity() < count)
            hkArrayUtil__reserve(&alloc, this, count, sizeof(T));
    }
    __forceinline ~NodeTickArray()
    {
        hkMemoryAllocator& alloc = hkMemoryRouter_getInstance()->heap();
        clear();
        if ((flags & 0x80000000u) == 0)
            alloc.bufFree(data, capacity() * sizeof(T));
        data = 0;
        flags = 0x80000000;
    }
};

}

// @fnv 0x00e0da00
// src: HAVOK_LIB 0x00e0da00
__declspec(noinline) int __cdecl getNodeSampledAtTick(int row, int col, const S00e0e4e0_NodeArr& nodes, int height, float range,
                                              float value, S00e0e4e0_Info* info)
{
    float step = range / height;
    NodeTickSupport::NodeTickArray<MonNode*> samples;
    samples.reserveExactly(height);
    MonNode* result = 0;
    const MonNodeList& roots = (const MonNodeList&)nodes;
    if (roots[row]->m_children.GetLogicalSize() > 0)
    {
        samples.clear();
        int axis = info->unk0c == 0 ? info->unk04 : info->unk08;
        ::outputStatsForFrame(value, step, axis, reinterpret_cast<S00e0e4e0_Node*>(roots[row]), height,
                       reinterpret_cast<S00e0e4e0_PArr*>(&samples));
        int size = samples.GetLogicalSize();
        if (col < size)
            result = samples[col];
    }
    return (int)result;
}
