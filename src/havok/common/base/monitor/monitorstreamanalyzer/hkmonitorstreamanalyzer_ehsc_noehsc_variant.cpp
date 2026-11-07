#include "../../../../../../include/hkArrayBase.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkBool.h"
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

// src/havok/common/base/monitor/monitorstreamanalyzer/hkmonitorstreamanalyzer_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/base/monitor/monitorstreamanalyzer/hkmonitorstreamanalyzer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


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
    void Accumulate(struct AxisData* data, NiPoint3* start, NiPoint3* end);
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
void Bins::Accumulate(AxisData* pAxisData, NiPoint3* start, NiPoint3* end)
{
    // Monitor samples use the words at offsets 4 and 8 as unsigned counters.
    unsigned int x = pAxisData->xIndex;
    if (x <= 7)
    {
        weights[x] += (float)(reinterpret_cast<const unsigned int&>(end->y) - reinterpret_cast<const unsigned int&>(start->y)) * pAxisData->xScale;
        ++counts[x];
    }
    unsigned int y = pAxisData->yIndex;
    if (y <= 7)
    {
        weights[y] += (float)(reinterpret_cast<const unsigned int&>(end->z) - reinterpret_cast<const unsigned int&>(start->z)) * pAxisData->yScale;
        ++counts[y];
    }
    unsigned int mode = pAxisData->mode;
    if (mode == 0)
        value = (double)reinterpret_cast<const unsigned int&>(start->y) * pAxisData->xScale;
    else if (mode == 1)
        value = (double)reinterpret_cast<const unsigned int&>(start->z) * pAxisData->yScale;
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
struct S_e0ce00_Alloc;
struct S_e0ce00_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_e0ce00_Alloc* m_pStreamAllocator;
    S_e0ce00_Alloc& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_e0ce00_Router* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(S_e0ce00_Alloc* alloc, void* arr, int elemSize);
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
    __forceinline S_e0ce00_Block& AllocatePair(S_e0ce00_Alloc& alloc)
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
    S_e0ce00_Alloc& alloc = hkMemoryRouter_getInstance()->heap();
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
struct S_e0ce00_Alloc
{
    virtual void v00();
    virtual void v04();
    virtual void v08(void* apItem, int aSize);
    virtual void v0c();
    virtual void v10(void* apData, unsigned int aBytes);
};
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
        S_e0ce00_Router* holder = hkMemoryRouter_getInstance();
        if (arr.m_iElementCount == (int)(arr.m_iCapacityState & 0x3fffffffu))
        {
            ResizeAudioStream(holder->m_pStreamAllocator, &arr, 4);
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
            S_e0ce00_Router* holder = hkMemoryRouter_getInstance();
            holder->m_pStreamAllocator->v08(item, 0x58);
        }
    }

    S_e0ce00_Router* holder = hkMemoryRouter_getInstance();
    S_e0ce00_Alloc* alloc = holder->m_pStreamAllocator;
    arr.m_iElementCount = 0;
    if ((arr.m_iCapacityState & 0x80000000u) == 0)
    {
        alloc->v10(arr.m_data, (arr.m_iCapacityState & 0x3fffffffu) * 4);
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
void __cdecl hkArrayUtil__reserve(S_e0ce00_Alloc* alloc, void* array, int count, int size);
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
        S_e0ce00_Alloc& heap = hkMemoryRouter_getInstance()->heap();
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
        S_e0ce00_Alloc& heap = hkMemoryRouter_getInstance()->heap();
        size = 0;
        if ((capacity & 0x80000000u) == 0)
            heap.v10(data, (capacity & 0x3fffffff) * 4);
    }
};
void __cdecl hkArrayUtil__reserve(S_e0ce00_Alloc* alloc, void* array, int count, int size);
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
            S_e0ce00_Alloc& heap = hkMemoryRouter_getInstance()->heap();
            heap.v08(p, 0x58);
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
struct FUN_00e0d000Heap
{
    virtual void unused();
    virtual void* allocate(int);
};
struct FUN_00e0d000Router : S_e0ce00_Router
{
    FUN_00e0d000Heap* statsHeap;
    __forceinline FUN_00e0d000Heap& heapForStats()
    {
        return *statsHeap;
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
void __cdecl hkArrayUtil__reserve(FUN_00e0d000Heap*, FUN_00e0d000Array*, int, int);
__forceinline FUN_00e0d000& FUN_00e0d000Array::AllocatePair()
{
    FUN_00e0d000Heap& heap = static_cast<FUN_00e0d000Router*>(hkMemoryRouter_getInstance())->heapForStats();
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
            new (static_cast<FUN_00e0d000Router*>(hkMemoryRouter_getInstance())->heapForStats().allocate(sizeof(FUN_00e0d000Total)))
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
struct DumpRouter
{
    int a, b, c, d, e;
    S_e0ce00_Alloc* allocator;
    S_e0ce00_Alloc& heap()
    {
        return *allocator;
    }
};
void __cdecl hkArrayUtil__reserve(S_e0ce00_Alloc*, void*, int, int);
void __cdecl hkOstream_printf(void*, const char*, ...);
struct FUN_00e108b0
{
    char* data;
    int size;
    int capacity;
    FUN_00e108b0();
    void reserve(S_e0ce00_Alloc& a, int n)
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
        reserve(((DumpRouter*)hkMemoryRouter_getInstance())->heap(), n);
        size = n;
    }
    void append(char c)
    {
        DumpRouter* r = (DumpRouter*)hkMemoryRouter_getInstance();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream((S_e0ce00_Alloc*)r->allocator, this, 1);
        data[size++] = c;
    }
    void clearAndFree(S_e0ce00_Alloc& a)
    {
        if ((capacity & 0x80000000u) == 0)
            a.v10(data, capacity & 0x3fffffff);
    }
    void clearAndFree()
    {
        S_e0ce00_Alloc& a = *((DumpRouter*)hkMemoryRouter_getInstance())->allocator;
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
    S_e0ce00_Alloc* cleanupAllocator;
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
                    cleanupAllocator = &((DumpRouter*)hkMemoryRouter_getInstance())->heap();
                    indent.size = 0;
                    goto cleanup;
                }
            }
        }
    }
    cleanupAllocator = &((DumpRouter*)hkMemoryRouter_getInstance())->heap();
    indent.size = 0;
cleanup:
    if ((indent.capacity & 0x80000000u) == 0)
        cleanupAllocator->v10(indent.data, indent.capacity & 0x3fffffff);
}
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

        return reinterpret_cast<FUN_00e0d000Heap&>(hkMemoryRouter_getInstance()->heap()).allocate(size);
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
    S_e0ce00_Alloc& heap = hkMemoryRouter_getInstance()->heap();
    pad.size = 0;
    if ((pad.m_iCapacity & 0x80000000u) == 0)
        heap.v10(pad.data, pad.m_iCapacity & 0x3fffffff);
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
        S_e0ce00_Router* router = hkMemoryRouter_getInstance();
        S_e0ce00_Alloc* heap = router->m_pStreamAllocator;
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
void __cdecl hkMemoryRouter_easyFree(S_e0ce00_Alloc* alloc, void* p);
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
        S_e0ce00_Router* h = hkMemoryRouter_getInstance();
        hkMemoryRouter_easyFree(h->m_pStreamAllocator, (void*)p);
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
struct ReportHeap
{
    virtual void v00();
    virtual void v04();
    virtual void freeNode(void*, int);
    virtual void v0c();
    virtual void freeBuffer(void*, int);
};
struct ReportRouter
{
    int unk00, unk04, unk08;
    ReportHeap* tempHeap;
    ReportHeap* mapHeap;
    ReportHeap* nodeHeap;
    ReportHeap& temp()
    {
        return *tempHeap;
    }
    ReportHeap& stats()
    {
        return *nodeHeap;
    }
};
void __cdecl hkArrayUtil__reserve(ReportHeap*, void*, int, int);
struct ReportArray
{
    ReportNode** data;
    int size;
    int capacity;
    ReportArray() : data(0), size(0), capacity(0x80000000)
    {}
    void reserve(int n)
    {
        ReportHeap& heap = reinterpret_cast<ReportRouter*>(hkMemoryRouter_getInstance())->temp();
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
        ReportHeap& heap = reinterpret_cast<ReportRouter*>(hkMemoryRouter_getInstance())->temp();
        size = 0;
        if ((capacity & 0x80000000u) == 0)
            heap.freeBuffer(data, (capacity & 0x3fffffff) * 4);
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
        reinterpret_cast<ReportRouter*>(hkMemoryRouter_getInstance())->stats().freeNode(node, 0x70);
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

struct Se0e0c0_Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};
void* __cdecl AllocateWithHeader(Se0e0c0_Allocator* alloc, int numBytes);

struct Se0e0c0_Heap
{
    __forceinline Se0e0c0_Allocator& get(const void*)
    {
        return *(Se0e0c0_Allocator*)&hkMemoryRouter_getInstance()->heap();
    }
};

template <typename T> struct Se0e0c0_ArrayBaseLocalForm
{ // local form of hkArray: 0x00e0e0c0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
};
template <typename T> struct Se0e0c0_Array : Se0e0c0_ArrayBaseLocalForm<T>
{
    __forceinline Se0e0c0_Array()
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
    }
    __forceinline ~Se0e0c0_Array()
    {
        Se0e0c0_Allocator& alloc = Se0e0c0_Heap().get(this);
        this->m_iElementCount = 0;
        if ((this->m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
    }
};


struct Se0e0c0_Dummy;
struct Se0e0c0_Pair
{
    unsigned long key;
    unsigned long val;
};
struct Se0e0c0_MapBase
{
    Se0e0c0_Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    __forceinline Se0e0c0_MapBase() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    void EnsureCapacity(Se0e0c0_Allocator& alloc, int n);
    void ProcessArgument(Se0e0c0_Allocator& alloc);
    void Object_DoNothing();
    int get(unsigned long key, unsigned long* out) const;
    int insert(Se0e0c0_Allocator& alloc, unsigned long key, unsigned long val);
    __forceinline Se0e0c0_Dummy* GetFirstIterator() const
    {
        int i;
        for (i = 0; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != (unsigned long)-1)
                break;
        }
        return (Se0e0c0_Dummy*)i;
    }
    __forceinline Se0e0c0_Dummy* getNext(Se0e0c0_Dummy* it) const
    {
        int i = (int)it;
        for (i += 1; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != (unsigned long)-1)
                break;
        }
        return (Se0e0c0_Dummy*)i;
    }
    __forceinline hkBool isValid(Se0e0c0_Dummy* it) const
    {
        int i = (int)it;
        return hkBool(i <= m_iPairCount);
    }
};
struct Se0e0c0_PointerMap : Se0e0c0_MapBase
{
    __forceinline Se0e0c0_PointerMap()
    {
        EnsureCapacity(Se0e0c0_Heap().get(this), 0);
    }
    __forceinline ~Se0e0c0_PointerMap()
    {
        ProcessArgument(Se0e0c0_Heap().get(this));
        Object_DoNothing();
    }
};

struct Se0e0c0_FrameInfo
{
    const char* m_pHeading;
    int m_iColor;
    int m_iTimer0;
    unsigned int m_uiTimer1;
    float m_fStartTime;
    float m_fEndTime;
    int m_uiThreadId;
    int m_iTimer0Index;
    int m_iTimer1Index;
};
struct Se0e0c0_Node
{
    float m_uiFilterValue[8];
    unsigned short m_uiItemCount[8];
    Se0e0c0_ArrayBaseLocalForm<Se0e0c0_Node*> m_children;
    double m_dValue;
    Se0e0c0_Node* m_next;
    const char* m_name;
};
struct Se0e0c0_ColorPair
{
    const char* m_kColorName;
    unsigned int m_kDiffuseColor;
};
struct Se0e0c0_ColorTable
{
    void* vtbl;
    int m_refs;
    Se0e0c0_ArrayBaseLocalForm<Se0e0c0_ColorPair> m_kColorPairs;
};
struct Se0e0c0_Input
{
    int m_iValueAt00;
    int m_iFrameCount;
    int m_iValueAt08;
    int m_iValueAt0C;
    int m_iValueAt10;
    int m_iValueAt14;
    float m_fValueAt18;
    float m_fValueAt1C;
    hkBool m_bValueAt20;
    Se0e0c0_ColorTable* m_pColorTable;
};
struct Se0e0c0_SampleInfo
{
    float m_fValueAt00;
};

void __cdecl Se0e0c0_outputStatsForFrame(Se0e0c0_Node* root, float start, float samplesPerTick, int count,
                                         Se0e0c0_ArrayBaseLocalForm<Se0e0c0_Node*>& out, int timer);
void Se0e0c0_reserveExactly(Se0e0c0_ArrayBaseLocalForm<Se0e0c0_Node*>& a, int n);
int __cdecl Se0e0c0_strCasecmp(const char* a, const char* b);
extern const int* Se0e0c0_numbers[10];

static void __cdecl drawDigit(int digit, int y, int width, int* texture);

// src: HAVOK_LIB 0x00e0c210
static void __cdecl drawNumber(int value, int y, int width, int* texture)
{
    int offset = 0;
    for (int divisor = 1000; divisor >= 1; divisor /= 10)
    {
        int digit = (*(volatile int*)&value / divisor) % 10;
        drawDigit(digit, y, *(volatile int*)&width, texture + offset);
        offset += 7;
    }
}

// src: HAVOK_LIB 0x00e0c1c0
static void __cdecl drawDigit(int digit, int y, int width, int* texture)
{
    const int* number = Se0e0c0_numbers[digit];
    for (int x = 0; x < 8; x++)
    {
        for (int row = 0; row < 7; row++)
        {
            if ((number[6 - row] << (x * 4)) & 0xf0000000)
            {
                texture[row * width + x] = 0xff000000;
            }
        }
    }
}

static void __cdecl drawStatistics(const Se0e0c0_FrameInfo& info, int frame,
                                 const Se0e0c0_ArrayBaseLocalForm<Se0e0c0_Node*>& nodes, int* texture, int height,
                                 Se0e0c0_ColorTable* colorTable, int rowStride, int width, float maxFrameTime,
                                 float startTime, Se0e0c0_PointerMap& unknownTimers);

extern float Se0e0c0_lastFrameTime;
void Se0e0c0_setSize(Se0e0c0_Array<float>& a, int n, const float& fill);
unsigned int __cdecl Se0e0c0_roundUpPow2(unsigned int v);

// src: HAVOK_LIB 0x00e0dd30
void __cdecl hkMonitorStreamAnalyzer_getTimerLimits(const Se0e0c0_ArrayBaseLocalForm<Se0e0c0_Node*>& nodes, const Se0e0c0_Input& input,
                          Se0e0c0_ArrayBaseLocalForm<Se0e0c0_Array<Se0e0c0_FrameInfo> >& frameInfos, float& maxFrameTime,
                          Se0e0c0_Array<float>& startTimes)
{
    int numThreads = nodes.GetLogicalSize();
    int endFrame = input.m_iValueAt00 + input.m_iFrameCount;
    int available = nodes[0]->m_children.GetLogicalSize();
    int numFrames = input.m_iFrameCount;
    if (endFrame > available)
    {
        numFrames = available - input.m_iValueAt00;
        endFrame = available;
    }
    if (numFrames <= 0)
    {
        return;
    }
    float zero = 0.0f;
    Se0e0c0_setSize(startTimes, input.m_iFrameCount, zero);
    maxFrameTime = 0.0f;
    for (int f = input.m_iValueAt00; f < endFrame; f++)
    {
        int idx = f - input.m_iValueAt00;
        int timer = frameInfos[0][f].m_uiTimer1 == 0 ? frameInfos[0][f].m_iColor : frameInfos[0][f].m_iTimer0;
        startTimes[idx] = 1e30f;
        for (int t = 0; t < numThreads; t++)
        {
            const Se0e0c0_ArrayBaseLocalForm<Se0e0c0_Node*>& children = nodes[t]->m_children[f]->m_children;
            if (children.GetLogicalSize() > 0)
            {
                for (int i = 0; i < children.GetLogicalSize(); i++)
                {
                    float st = (float)children[i]->m_dValue;
                    startTimes[idx] = st < startTimes[idx] ? st : startTimes[idx];
                }
                for (int j = 0; j < children.GetLogicalSize(); j++)
                {
                    double end = children[j]->m_uiFilterValue[timer] + children[j]->m_dValue - startTimes[idx];
                    float e = (float)end;
                    maxFrameTime = maxFrameTime > e ? maxFrameTime : e;
                }
            }
        }
    }
    if (input.m_fValueAt1C > 0.0)
    {
        for (int f2 = input.m_iValueAt00; f2 < endFrame; f2++)
        {
            startTimes[f2 - input.m_iValueAt00] += input.m_fValueAt1C;
        }
    }
    if (input.m_fValueAt18 > 0.0)
    {
        maxFrameTime = input.m_fValueAt18;
        return;
    }
    if (numFrames == 1)
    {
        float rounded = (float)((__int64)Se0e0c0_roundUpPow2((int)(maxFrameTime / 1000.0) + 1) * 1000.0);
        float delta = rounded - Se0e0c0_lastFrameTime;
        float quarter = (float)(Se0e0c0_lastFrameTime / 4.0);
        maxFrameTime = (delta < quarter ? delta : quarter) * 0.05f + Se0e0c0_lastFrameTime;
        maxFrameTime = maxFrameTime > 16666.0f ? maxFrameTime : 16666.0f;
        Se0e0c0_lastFrameTime = maxFrameTime;
    }
}

// @fnv 0x00e0e0c0
// src: HAVOK_LIB 0x00e0e0c0
void __cdecl hkMonitorStreamAnalyzer_writeStatisticsDetailsToTexture(const Se0e0c0_ArrayBaseLocalForm<Se0e0c0_Node*>& nodes, const Se0e0c0_Input& input,
                          Se0e0c0_ArrayBaseLocalForm<Se0e0c0_Array<Se0e0c0_FrameInfo> >& frameInfos, int*& texture, int& height,
                          Se0e0c0_SampleInfo* sampleInfo)
{
    int numThreads = nodes.GetLogicalSize();
    if (numThreads < 1)
    {
        return;
    }
    float maxFrameTime = -1.0f;
    Se0e0c0_Array<float> startTimes;
    hkMonitorStreamAnalyzer_getTimerLimits(nodes, input, frameInfos, maxFrameTime, startTimes);

    int maxFrames = frameInfos[0].GetLogicalSize() - input.m_iValueAt00;
    int numFrames = input.m_iFrameCount > maxFrames ? maxFrames : input.m_iFrameCount;
    int endFrame = input.m_iValueAt00 + numFrames;
    int threadSpacing = input.m_iValueAt08 + input.m_iValueAt0C;
    int frameHeight = threadSpacing * numThreads + input.m_iValueAt10;
    int totalHeight = frameHeight * numFrames;
    int currentY = totalHeight;
    int border = (numFrames > 1) ? 32 : 0;
    int drawWidth = input.m_iValueAt14 - border;
    int numPixels = (input.m_iValueAt14 + 1) * totalHeight;

    texture = (int*)AllocateWithHeader((Se0e0c0_Allocator*)&hkMemoryRouter_getInstance()->heap(), numPixels * sizeof(int));
    height = totalHeight;
    hkString_memSet(texture, 0, numPixels * 4);
    if (sampleInfo)
    {
        sampleInfo->m_fValueAt00 = maxFrameTime;
    }

    Se0e0c0_PointerMap unknownTimers;

    for (int frame = input.m_iValueAt00; frame < endFrame; frame++)
    {
        currentY -= input.m_iValueAt10;
        if (numFrames > 1)
        {
            drawNumber(frame, currentY, input.m_iValueAt14,
                         texture + (currentY - threadSpacing) * input.m_iValueAt14);
        }
        for (int thread = 0; thread < numThreads; thread++)
        {
            currentY -= threadSpacing;
            int* row = texture + currentY * input.m_iValueAt14 + border;
            drawStatistics(frameInfos[thread][0], frame, nodes[thread]->m_children, row, input.m_iValueAt08,
                         input.m_pColorTable, input.m_iValueAt14, drawWidth, maxFrameTime,
                         startTimes[frame - input.m_iValueAt00], unknownTimers);
        }
    }

    float pixelsPerFrame = (drawWidth * 1000) / maxFrameTime;
    int startOffset = (int)(((int)input.m_fValueAt1C % 1000) * 0.001f * pixelsPerFrame);

    if (pixelsPerFrame > 5.0)
    {
        int x = border - startOffset;
        int i = 0;
        while (x < input.m_iValueAt14)
        {
            if (x >= 0)
            {
                for (int y = 0; y < totalHeight; y++)
                {
                    texture[y * input.m_iValueAt14 + x] = 0xff0000ff;
                }
            }
            i++;
            x = border - startOffset + (int)(i * pixelsPerFrame);
        }
    }

    int step = (int)((drawWidth * 16666) / maxFrameTime);
    if (step > 0)
    {
        for (int x = border - startOffset; x < input.m_iValueAt14; x += step)
        {
            if (x < 0)
                continue;
            for (int y = 0; y < totalHeight; y++)
            {
                texture[y * input.m_iValueAt14 + x] = 0xff00ff00;
                texture[y * input.m_iValueAt14 + x + 1] = 0xff00ff00;
            }
        }
    }

    if (input.m_bValueAt20)
    {
        for (Se0e0c0_Dummy* it = unknownTimers.GetFirstIterator(); unknownTimers.isValid(it);
             it = unknownTimers.getNext(it))
        {
        }
    }
}

__declspec(noinline) E0CC40Node* __cdecl FindNodeAtTime(E0CC40Node*, E0CC40Node*, double, int);

template <class T> __forceinline void copyElements(T* dst, int count, const T& value)
{
    for (int i = 0; i < count; ++i)
        dst[i] = value;
}

template <class T> struct SampleArrayBaseLocalForm
{ // local form of hkArrayBase: 0x00e0daf0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline SampleArrayBaseLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
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
    __forceinline void clear()
    {
        m_iElementCount = 0;
    }
    __forceinline void append(S_e0ce00_Alloc& allocator, const T& value)
    {
        if (m_iElementCount == capacity())
            ResizeAudioStream(&allocator, this, sizeof(T));
        copyElements(m_data + m_iElementCount, 1, value);
        ++m_iElementCount;
    }
    __forceinline void reserveExactly(S_e0ce00_Alloc& allocator, int count)
    {
        if (capacity() < count)
            hkArrayUtil__reserve(&allocator, this, count, sizeof(T));
    }
    __forceinline void release(S_e0ce00_Alloc& allocator)
    {
        clear();
        if ((m_iCapacityState & 0x80000000u) == 0)
            allocator.v10(m_data, capacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct SampleAllocator
{
    __forceinline S_e0ce00_Alloc& get(const void*)
    {
        return hkMemoryRouter_getInstance()->heap();
    }
};

template <class T> struct SampleArray : SampleArrayBaseLocalForm<T>
{
    __forceinline void AddBack(const T& value)
    {
        SampleArrayBaseLocalForm<T>::append(SampleAllocator().get(this), value);
    }
    __forceinline void reserveExactly(int count)
    {
        SampleArrayBaseLocalForm<T>::reserveExactly(SampleAllocator().get(this), count);
    }
    __forceinline ~SampleArray()
    {
        SampleArrayBaseLocalForm<T>::release(SampleAllocator().get(this));
    }
};

struct SampleNode
{
    float m_iSlotIds[8];
    unsigned short m_counts[8];
    SampleArray<SampleNode*> m_children;
    double m_base;
    SampleNode* m_parent;
    const char* m_name;
};

// src: HAVOK_LIB 0x00e0cec0
static __declspec(noinline) void outputStatsForFrame(SampleNode* root, float start, float delta, int count,
                                              SampleArray<SampleNode*>& output, int axis)
{
    SampleNode* firstChild = root->m_children[0];
    SampleNode* finalChild = root->m_children.back();
    double begin = firstChild->m_base - start;
    double tick = 0.0;
    int remaining = count;
    while (remaining && begin > tick)
    {
        tick += delta;
        output.AddBack(0);
        --remaining;
    }
    double finish = finalChild->m_iSlotIds[axis] + finalChild->m_base - start;
    root->m_base = firstChild->m_base;
    root->m_iSlotIds[axis] = float(start + finish - root->m_base + 1.0);
    SampleNode* previous = 0;
    while (remaining && tick < finish)
    {
        previous = (SampleNode*)FindNodeAtTime((E0CC40Node*)root, (E0CC40Node*)previous, tick + start, axis);
        if (previous)
            output.AddBack(previous);
        tick += delta;
        --remaining;
    }
}

struct ColorMapBase
{
    void* m_entries;
    int m_iElementCount;
    int m_mod;
    void EnsureCapacity(S_e0ce00_Alloc*, int);
    int LookupBucketValue(unsigned long key, unsigned long* out) const;
    int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(S_e0ce00_Alloc*, unsigned long key, unsigned long value);
    void ProcessArgument(S_e0ce00_Alloc*);
    void Object_DoNothing();
    __forceinline ColorMapBase() : m_entries(0), m_iElementCount(0), m_mod(-1)
    {}
    __forceinline ~ColorMapBase()
    {
        Object_DoNothing();
    }
};
struct ColorMapStorage : ColorMapBase
{
    __forceinline ColorMapStorage()
    {
        EnsureCapacity(&SampleAllocator().get(this), 0);
    }
    __forceinline ~ColorMapStorage()
    {
        ProcessArgument(&SampleAllocator().get(this));
    }
    __forceinline int insert(unsigned long key, unsigned long value)
    {
        return hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(&SampleAllocator().get(this), key, value);
    }
};
struct ColorMap
{
    ColorMapStorage m_map;
    __forceinline int get(const char* key, int* out) const
    {
        unsigned long value;
        if (m_map.LookupBucketValue((unsigned long)key, &value) == 0)
        {
            *out = int(value);
            return 0;
        }
        return 1;
    }
    __forceinline int insert(const char* key, int value)
    {
        return m_map.insert((unsigned long)key, (unsigned long)value);
    }
};
typedef Se0e0c0_FrameInfo TextureFrame;
struct ColorName
{
    unsigned long m_tagged;
    __forceinline operator const char*() const
    {
        return (const char*)(m_tagged & ~1u);
    }
};
struct ColorPair
{
    ColorName m_name;
    unsigned int m_kDiffuseColor;
};
struct TextureColors
{
    int unk00;
    int unk04;
    SampleArray<ColorPair> m_pairs;
    unsigned int m_uiColorValue;
};
int __cdecl CompareStringsCaseInsensitive(const char*, const char*);

static __forceinline void renderTextureColumns(const TextureFrame& info, int frame,
                                               const SampleArrayBaseLocalForm<SampleNode*>& trees, int* image, int rows,
                                               TextureColors& colors, int stride, int samples, float duration,
                                               float start, ColorMap& missing)
{
    ColorMap cache;
    float increment = duration / samples;
    SampleArray<SampleNode*> ticks;
    ticks.reserveExactly(samples);
    if (trees[frame]->m_children.GetLogicalSize() > 0)
    {
        ticks.clear();
        int axis = info.m_uiTimer1 == 0 ? info.m_iColor : info.m_iTimer0;
        outputStatsForFrame(trees[frame], start, increment, samples, ticks, axis);
        int size = ticks.GetLogicalSize();
        for (int column = 0; column < size && column < samples; ++column)
        {
            int color = -1;
            if (ticks[column])
            {
                SampleNode* current = ticks[column];
                while (current)
                {
                    const char* label = current->m_name;
                    if (cache.get(label, &color) == 1)
                    {
                        if (missing.get(label, &color) != 1)
                        {
                            current = current->m_parent;
                            continue;
                        }
                        bool found = false;
                        for (int entry = 0; entry < colors.m_pairs.GetLogicalSize(); ++entry)
                        {
                            if (CompareStringsCaseInsensitive(colors.m_pairs[entry].m_name, label) == 0)
                            {
                                color = colors.m_pairs[entry].m_kDiffuseColor;
                                found = true;
                                break;
                            }
                        }
                        if (found)
                        {
                            cache.insert(label, color);
                            break;
                        }
                        else
                        {
                            missing.insert(label, color);
                            current = current->m_parent;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
            for (int row = 0; row < rows; ++row)
                image[row * stride + column] = color;
        }
    }
}

// @fnv 0x00e0daf0
// src: HAVOK_LIB 0x00e0daf0
static __declspec(noinline) void drawStatistics(const Se0e0c0_FrameInfo& info, int frame,
                                              const Se0e0c0_ArrayBaseLocalForm<Se0e0c0_Node*>& trees, int* image, int rows,
                                              Se0e0c0_ColorTable* colors, int stride, int samples, float duration,
                                              float start, Se0e0c0_PointerMap& missing)
{
    renderTextureColumns((const TextureFrame&)info, frame, (const SampleArrayBaseLocalForm<SampleNode*>&)trees, image, rows,
                         *(TextureColors*)colors, stride, samples, duration, start, (ColorMap&)missing);
}
