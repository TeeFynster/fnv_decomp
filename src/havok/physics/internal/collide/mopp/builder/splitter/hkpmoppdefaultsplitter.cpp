
// src/havok/physics/internal/collide/mopp/builder/splitter/hkpmoppdefaultsplitter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/builder/splitter/hkpmoppdefaultsplitter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../include/BSAudio.h"
#include "../../../../../../../../include/hkBool.h"

struct FUN_00e0a070
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    int m_10;
    void* m_14;
    int m_18;
    void* m_1c;
    void VisitNode(void* node);
};

// Links node into one of two singly-linked lists on this, chosen by the byte at node+4, incrementing the matching count.
// @fnv 0x00e0a070
void FUN_00e0a070::VisitNode(void* node)
{
    if (node)
    {
        if (*reinterpret_cast<char*>(reinterpret_cast<unsigned char*>(node) + 4))
        {
            *reinterpret_cast<void**>(node) = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x18);
            ++*reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x1c);
            *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x18) = node;
        }
        else
        {
            *reinterpret_cast<void**>(node) = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x10);
            ++*reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x14);
            *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x10) = node;
        }
    }
}

extern "C" void* DAT_010ea610;

struct FUN_00e09ba0
{
    void* m_00;
    unsigned short m_04;
    unsigned short m_06;
    void* m_08;
    void* m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;

    FUN_00e09ba0();
};

// Initializes the object: sets m_06 to 1, points m_00 at DAT_010ea610, and zeroes m_10, m_14, m_18, m_1c, m_08 and m_0c.
// @fnv 0x00e09ba0
FUN_00e09ba0::FUN_00e09ba0()
{
    m_06 = 1;
    m_00 = &DAT_010ea610;
    m_10 = 0;
    m_14 = 0;
    m_18 = 0;
    m_1c = 0;
    m_08 = 0;
    m_0c = 0;
}

extern int DAT_0102e388;
// @fnv 0x00e09bd0
// src: GUESS 0x00e09bd0 (confidence: low)
void __fastcall Hkpmoppdefaultsplitter_UpdateState_00e09bd0(void* p, int)
{
    *reinterpret_cast<void**>(p) = &DAT_0102e388;
}

struct S_00e0a0a0
{
    int unk0, unk4, unk8, unkC, unk10, unk14, unk18, unk1C;
    int hkpMoppDefaultSplitter_getFreeNodes();
};
// @fnv 0x00e0a0a0
// src: XBOX_PDB 0x00e0a0a0
int S_00e0a0a0::hkpMoppDefaultSplitter_getFreeNodes()
{
    return unk1C + unk14;
}


// Extent bit views at tree-node offsets 0x0c..0x20; these are min/max floats, not hkKeyPair keys.
struct MoppExtentBits
{
    int m_kMinimumCorner;
    int m_kMaximumCorner;
};

struct hkNodeE09F
{
    hkNodeE09F* m_next;
    hkBool m_uiBufferCapacity;
    int unk08;
    MoppExtentBits m_keys[3];
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    hkBool unk38;
    hkBool unk39;
    hkBool unk3A;
    hkBool unk3B;
    hkBool unk3C;
    hkBool unk3D;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
};

struct hkRangeE09F
{
    int m_kMinimumCorner;
    int m_kMaximumCorner;
};

struct hkAxisE09F
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class hkAxisHandlerE09F
{
  public:
    virtual void V00() throw();
    virtual void V04() throw();
    virtual void V08() throw();
    virtual void V0C() throw();
    virtual void V10() throw();
    virtual void V14() throw();
    virtual void V18() throw();
    virtual void addRange(hkAxisE09F* pkAxis, int iAxis, int iMin, int iMax, int* piMinOut, int* piMaxOut) throw();
};

class FUN_00e09f80_class
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    hkNodeE09F* m_kFreeListEntries;
    int m_numFree;
    int unk20;
    int unk24;
    hkAxisHandlerE09F* m_handler;
    int unk2C;
    int unk30;
    hkAxisE09F* m_axes;

    void hkpMoppDefaultSplitter_calculateMaxMinId(hkRangeE09F* pkRange, hkNodeE09F* pkNode) throw();
    hkNodeE09F* AllocateNode(int iOwner, hkRangeE09F* pkRange) throw();
};

// Pops a free node from the free list, resets its flags and range fields, links it to the owner, and registers its three key ranges with the axis handler.
// @fnv 0x00e09f80
hkNodeE09F* FUN_00e09f80_class::AllocateNode(int iOwner, hkRangeE09F* pkRange) throw()
{
    hkNodeE09F* pkNode = m_kFreeListEntries;
    m_kFreeListEntries = pkNode->m_next;
    m_numFree--;
    pkNode->unk38 = false;
    pkNode->unk39 = false;
    pkNode->unk40 = -1;
    pkNode->unk5C = -1;
    pkNode->unk3A = false;
    pkNode->unk3B = false;
    pkNode->unk3C = false;
    pkNode->unk3D = false;
    pkNode->m_uiBufferCapacity = true;
    pkNode->m_next = (hkNodeE09F*)iOwner;
    pkNode->unk60 = pkRange->m_kMinimumCorner;
    hkpMoppDefaultSplitter_calculateMaxMinId(pkRange, pkNode);
    for (int i = 0; i < 3; i++)
        m_handler->addRange(&m_axes[i], i, pkRange->m_kMinimumCorner, pkRange->m_kMaximumCorner,
                            &pkNode->m_keys[i].m_kMinimumCorner, &pkNode->m_keys[i].m_kMaximumCorner);
    return pkNode;
}

extern "C" double DAT_01011588;
extern "C" double DAT_01021928;
extern "C" double DAT_010ea600;
extern "C" double DAT_010737c8;
extern "C" float DAT_010ea608;
struct FNVRange
{
    int begin, end;
    float lower, upper, defaultFactor;
    int unk14, unk18, unk1c;
    float value;
};
struct FNVResponse
{
    int unk00, unk04, unk08, unk0c, unk10;
    float magnitude;
    int unk18;
    float maximum;
    float ComputeResponse(FNVRange* range);
};
// @fnv 0x00e0a750
float FNVResponse::ComputeResponse(FNVRange* range)
{
    float displacement = range->value - static_cast<float>((range->upper + range->lower) * DAT_01011588);
    float factor;
    if (range->begin < range->end)
    {
        float difference = range->upper - range->lower;
        float limit = maximum;
        double dDenominator = double(difference) + (limit < difference ? limit : difference);
        if (dDenominator > 0.0)
            factor = float(1.0 / dDenominator);
        else
            factor = DAT_010ea608;
    }
    else
    {
        factor = range->defaultFactor;
    }
    float amount = factor * displacement;
    if (amount < 0.0f)
        return 0.0f;
    float fSquared = amount * amount;
    float fFourth = fSquared * fSquared;
    float fEighth = fFourth * fFourth;
    float response = static_cast<float>(fSquared * DAT_010ea600 + fFourth * DAT_01021928 + fEighth * DAT_010737c8);
    response *= magnitude;
    return response;
}

struct SortElemE0AB
{
    int m_00;
    int m_04;
    float m_key;
    int m_0c;
    int m_10;
};

struct SortLessE0AB
{
    bool operator()(const SortElemE0AB& kA, const SortElemE0AB& kB) const
    {
        return kA.m_key < kB.m_key;
    }
};

template <typename T> inline void swapE0AB(T& kA, T& kB)
{
    __declspec(align(16)) T kTmp = kB;
    kB = kA;
    kA = kTmp;
}

// Sorts the range [iD, iH] of pArr in place by m_key using a Hoare-style quicksort with a middle pivot, recursing on the left part and looping on the right.
// @fnv 0x00e0ab60
void __cdecl QuickSortElements(SortElemE0AB* pElements, int iLow, int iHigh, SortLessE0AB kCmpLess)
{
setRecursion:
    int i = iLow;
    int j = iHigh;
    __declspec(align(16)) SortElemE0AB kPivot = pElements[(iLow + iHigh) >> 1];

    do
    {
        while (kCmpLess(pElements[i], kPivot))
            i++;
        while (kCmpLess(kPivot, pElements[j]))
            j--;

        if (i <= j)
        {
            if (j != i)
            {
                swapE0AB(pElements[i], pElements[j]);
            }
            j--;
            i++;
        }
    } while (i <= j);

    if (iLow < j)
        QuickSortElements(pElements, iLow, j, kCmpLess);
    if (i < iHigh)
    {
        iLow = i;
        goto setRecursion;
    }
}

struct FUN_00e09bd0_Obj
{
    void __thiscall Hkpmoppdefaultsplitter_UpdateState_00e09bd0();
};

struct FUN_00e0ac80_Alloc
{
    virtual void FUN_00e0ac80_0();
    virtual void FUN_00e0ac80_1();
    virtual void __thiscall FUN_00e0ac80_2(void* p, unsigned short size);
};

BSAudio* __cdecl hkMemoryRouter_getInstance(void);

struct FUN_00e0ac80_class
{
    int unk00;
    unsigned short m_04;

    FUN_00e0ac80_class* __thiscall Construct(int flags);
};

// @fnv 0x00e0ac80
FUN_00e0ac80_class* FUN_00e0ac80_class::Construct(int flags)
{
    reinterpret_cast<FUN_00e09bd0_Obj*>(this)->Hkpmoppdefaultsplitter_UpdateState_00e09bd0();

    if (flags & 1)
    {
        BSAudio* audio = hkMemoryRouter_getInstance();
        reinterpret_cast<FUN_00e0ac80_Alloc*>(audio->pListener)->FUN_00e0ac80_2(this, this->m_04);
    }

    return this;
}

struct Interval
{
    float min, max;
};
struct Node
{
    int unk00, unk04, unk08;
    Interval extent[3];
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    const char* unk60;
};
struct Obj
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    const char* unk34;
    void hkpMoppDefaultSplitter_resortAxis(Node*, int*, float*);
};
// Writes axes ordered by node extent length (x0.66 when unk60 equals unk34 plus 0, 32 or 64) and weights; identity order and zero weights if node is null.
// @fnv 0x00e09970
// src: HAVOK_LIB 0x00e09970
void Obj::hkpMoppDefaultSplitter_resortAxis(Node* node, int* axes, float* weights)
{
    if (node)
    {
        float best = 0.0f;
        float length[3];
        int index = 0;
        length[0] = node->extent[0].max - node->extent[0].min;
        if (node->unk60 == unk34)
            length[0] *= 0.6600000262260437;
        if (length[0] > best)
        {
            best = length[0];
            index = 0;
        }
        length[1] = node->extent[1].max - node->extent[1].min;
        if (node->unk60 == unk34 + 32)
            length[1] *= 0.6600000262260437;
        if (length[1] > best)
        {
            best = length[1];
            index = 1;
        }
        length[2] = node->extent[2].max - node->extent[2].min;
        if (node->unk60 == unk34 + 64)
            length[2] *= 0.6600000262260437;
        if (length[2] > best)
        {
            best = length[2];
            index = 2;
        }
        int j = (index + 1) % 3;
        int k = (index + 2) % 3;
        axes[0] = index;
        weights[0] = 0.0f;
        if (length[j] < length[k])
        {
            axes[1] = k;
            float v = best - length[k];
            v /= best;
            v = v * v * v * 16.0;
            weights[1] = v * 0.05000000074505806;
            axes[2] = j;
            v = best - length[j];
            v /= best;
            v = v * v * v * 16.0;
            weights[2] = v * 0.05000000074505806;
        }
        else
        {
            axes[1] = j;
            float v = best - length[j];
            v /= best;
            v = v * v * v * 16.0;
            weights[1] = v * 0.05000000074505806;
            axes[2] = k;
            v = best - length[k];
            v /= best;
            v = v * v * v * 16.0;
            weights[2] = v * 0.05000000074505806;
        }
    }
    else
    {
        axes[0] = 0;
        axes[1] = 1;
        axes[2] = 2;
        weights[0] = 0.0f;
        weights[1] = 0.0f;
        weights[2] = 0.0f;
    }
}


struct NodeE0A
{
    NodeE0A* m_next;
    hkBool m_bSlotEnabled;
    char unk05;
    short unk06;
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
    bool m_flag38;
    bool m_flag39;
    bool m_flag3A;
    bool m_flag3B;
    bool m_flag3C;
    bool m_flag3D;
    short unk3E;
    int m_index40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int m_index5C;
    int unk60;
    float m_maxDistance;
    int unk68;
    float m_minDistance;
    int m_count70;
    int m_count74;
};

class NodePoolE0A
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    NodeE0A* m_kFreeListEntries;
    int m_numFree;

    NodeE0A* PopNode();
};

// Pops a NodeE0A from the free list, resets its flags, indices, distances, and counts to defaults, and returns the node.
// @fnv 0x00e0a020
NodeE0A* NodePoolE0A::PopNode()
{
    NodeE0A* node = m_kFreeListEntries;
    m_kFreeListEntries = node->m_next;
    m_numFree--;
    node->m_flag38 = false;
    node->m_flag39 = false;
    node->m_flag3A = false;
    node->m_flag3B = false;
    node->m_flag3C = false;
    node->m_flag3D = false;
    node->m_index40 = -1;
    node->m_index5C = -1;
    node->m_bSlotEnabled = false;
    node->m_minDistance = 1000000.0f;
    node->m_count70 = 0;
    node->m_maxDistance = 10000000000.0f;
    node->m_count74 = 0;
    return node;
}

// Exe 0x00e0a950 FUN_00e0a950: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_xor_ps(LocalM128, LocalM128);
extern LocalM128 DAT_010c44d0;
extern double DAT_01011588;

struct FUN_00e0a950_E
{
    int a, b, c, d, e;
};

struct FUN_00e0a950_Sink
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20(FUN_00e0a950_E* e, const LocalM128* v, float f, int a2, void* p);
};

struct FUN_00e0a950_Src
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    const LocalM128* unk60;
    float unk64;
    float unk68;
};

struct Cls_00e0a950
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24;
    FUN_00e0a950_Sink* unk28;
    void hkpMoppDefaultSplitter_sortLeftAndRight(int a0, FUN_00e0a950_Src* a1, int a2, int* a3, int* a4, FUN_00e0a950_E** a5, FUN_00e0a950_E** a6,
                      FUN_00e0a950_E** a7, FUN_00e0a950_E** a8);
};

// Switches on a0 (0-3) to adjust the pointers a3-a8 and swap or copy E records; case 3 calls unk28->v20 with a vector and its negation.
// @fnv 0x00e0a950
// src: XBOX_PDB 0x00e0a950
void Cls_00e0a950::hkpMoppDefaultSplitter_sortLeftAndRight(int a0, FUN_00e0a950_Src* a1, int a2, int* a3, int* a4, FUN_00e0a950_E** a5,
                                FUN_00e0a950_E** a6, FUN_00e0a950_E** a7, FUN_00e0a950_E** a8)
{
    switch (a0)
    {
    case 1:
        *a5 += 1;
        break;
    case 2: {
        *a7 -= 1;
        *a6 -= 1;
        FUN_00e0a950_E* p = *a6;
        if (*a5 != *a7)
        {
            FUN_00e0a950_E t = *p;
            **a7 = **a5;
            **a5 = t;
        }
        break;
    }
    case 3: {
        *a3 -= 1;
        *a4 += 1;
        *a7 -= 1;
        const LocalM128* v = a1->unk60;
        float f = (a1->unk68 + a1->unk64) * DAT_01011588;
        unk28->v20(*a5, v, f, a2, *a7);
        LocalM128 neg = _mm_xor_ps(*v, DAT_010c44d0);
        unk28->v20(*a5, &neg, -f, a2, *a5);
        *a5 += 1;
        break;
    }
    case 0: {
        *a7 -= 1;
        *a8 -= 1;
        *a6 -= 1;
        FUN_00e0a950_E* p = *a6;
        FUN_00e0a950_E* q = *a5;
        FUN_00e0a950_E t1 = *q;
        FUN_00e0a950_E t2 = *p;
        **a7 = **a8;
        **a8 = t1;
        if (*a5 != *a6)
            **a5 = t2;
        break;
    }
    }
}

struct SplitItem
{
    int m_00;
};

struct SplitList
{
    SplitItem* m_data;
    int m_iElementCount;
    int m_pRayCursor;
};

struct SplitRange
{
    float m_kMinimumCorner;
    float m_kMaximumCorner;
};

struct PositionEntry
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    float m_pos;
    int m_kAxisEndPoints;
    int m_18;
    int m_1c;
};

struct SplitNode
{
    SplitNode* m_parent;
    int m_04;
    int m_08;
    SplitRange m_range[3];
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    PositionEntry* m_kTriangleNormal;
    int m_64;
    int m_68;
    float m_fSplitOffset;
    SplitNode* m_fMinimumU;
    SplitNode* m_fMaximumU;
    int m_uiItemCount;
};

struct SplitSettings
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    bool m_progress;
};

class SplitBuilder;

class SplitMonitor
{
  public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void step(SplitNode* root, SplitBuilder* builder, int flags);
};

class SplitClassifier
{
  public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void classify(PositionEntry* plane, int axis, SplitItem* items, int numItems, float* minOut, float* maxOut);
    virtual void skip(PositionEntry* plane, int axis, SplitItem* items, int numItems, float* minOut, float* maxOut);
};

struct SplitLess
{
};

void QuickSortElements(SplitItem* items, int lo, int hi, SplitLess cmp);

__forceinline void quickSortItems(SplitItem* items, int numItems, SplitLess cmpLess)
{
    if (numItems > 1)
    {
        QuickSortElements(items, 0, numItems - 1, cmpLess);
    }
}

__forceinline void quickSortItems(SplitItem* items, int numItems)
{
    quickSortItems(items, numItems, SplitLess());
}

__forceinline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
struct Scratch
{
    union
    {
        SplitLess first;
        SplitRange range;
    } b;
    union
    {
        PositionEntry* plane;
        SplitLess less;
    } a;
};
class SplitBuilder
{
  public:
    int m_00;
    int m_04;
    SplitSettings* m_settings;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    SplitMonitor* m_monitor;
    SplitClassifier* m_classifier;
    SplitNode* m_pTreeNode;
    int m_iValue;
    PositionEntry* m_kPlaneArray;

    SplitNode* AllocateNode(SplitNode* parent, SplitList* list);
    SplitNode* PopNode();
    void hkpMoppDefaultSplitter_resortAxis(SplitNode* node, int* axes, float* offsets);
    void hkpMoppDefaultSplitter_findSplittingPlanePositions(SplitNode* node, PositionEntry* plane, SplitList* list, SplitRange* range, int depth);
    void hkpMoppDefaultSplitter_calculateMaxMinId(SplitList* list, SplitNode* node);
    void hkpMoppDefaultSplitter_groupPrimitives(SplitList* list, SplitNode* node, int depth, SplitList* left, SplitList* right);
    SplitNode* hkpMoppDefaultSplitter_split(SplitNode* parent, SplitList* list, int side, int depth);
};

// Recursively builds a split tree node by classifying and sorting items against candidate planes, then splitting the list into left and right children.
// @fnv 0x00e0a270
// src: HAVOK_LIB 0x00e0a270
SplitNode* SplitBuilder::hkpMoppDefaultSplitter_split(SplitNode* parent, SplitList* list, int side, int depth)
{
    if (list->m_iElementCount == 1)
    {
        if (m_settings->m_progress && m_1c == 0)
        {
            m_monitor->step(m_pTreeNode, this, 0x800);
        }
        return AllocateNode(parent, list);
    }

    if (m_settings->m_progress && m_14 == 0)
    {
        m_monitor->step(m_pTreeNode, this, 0x800);
    }

    SplitNode* node = PopNode();
    node->m_uiItemCount = list->m_iElementCount;
    node->m_parent = parent;
    if (parent == 0)
    {
        m_pTreeNode = node;
    }
    else
    {
        if (side == 0)
        {
            parent->m_fMinimumU = node;
        }
        else
        {
            parent->m_fMaximumU = node;
        }
        node->m_range[0] = parent->m_range[0];
        node->m_range[1] = parent->m_range[1];
        node->m_range[2] = parent->m_range[2];
    }

    Scratch scratch;
    int i;
    PositionEntry* last = 0;
    int axes[3];
    float offsets[3];
    hkpMoppDefaultSplitter_resortAxis(parent, axes, offsets);

    for (i = 0; i < 3; i++)
    {
        PositionEntry* plane = &m_kPlaneArray[axes[i]];
        float cost = offsets[i] + plane->m_pos;
        scratch.a.plane = plane;
        if (cost > node->m_fSplitOffset)
        {
            break;
        }
        SplitRange* range = &node->m_range[axes[i]];
        m_classifier->classify(scratch.a.plane, axes[i], list->m_data, list->m_iElementCount, &range->m_kMinimumCorner,
                               &range->m_kMaximumCorner);
        new (&scratch.b.first) SplitLess();
        quickSortItems(list->m_data, list->m_iElementCount, scratch.b.first);
        last = scratch.a.plane;
        hkpMoppDefaultSplitter_findSplittingPlanePositions(node, scratch.a.plane, list, range, depth);
    }
    for (; i < 3; i++)
    {
        int axis = axes[i];
        m_classifier->skip(&m_kPlaneArray[axis], axis, list->m_data, list->m_iElementCount,
                           &node->m_range[axis].m_kMinimumCorner, &node->m_range[axis].m_kMaximumCorner);
    }

    for (int j = 3; j < m_iValue; j++)
    {
        PositionEntry* plane = &m_kPlaneArray[j];
        if (plane->m_pos > node->m_fSplitOffset)
        {
            break;
        }
        SplitRange& range = scratch.b.range;
        m_classifier->classify(plane, j, list->m_data, list->m_iElementCount, &range.m_kMinimumCorner, &range.m_kMaximumCorner);
        new (&scratch.a.less) SplitLess();
        quickSortItems(list->m_data, list->m_iElementCount, scratch.a.less);
        last = plane;
        hkpMoppDefaultSplitter_findSplittingPlanePositions(node, plane, list, &range, depth);
    }

    hkpMoppDefaultSplitter_calculateMaxMinId(list, node);
    if (last != node->m_kTriangleNormal)
    {
        PositionEntry* plane = node->m_kTriangleNormal;
        float fMin;
        float fScaledValue;
        m_classifier->classify(plane, plane->m_kAxisEndPoints, list->m_data, list->m_iElementCount, &fMin, &fScaledValue);
    }

    SplitList right;
    SplitList left;
    hkpMoppDefaultSplitter_groupPrimitives(list, node, depth, &left, &right);
    node->m_fMaximumU = hkpMoppDefaultSplitter_split(node, &right, 1, depth + 1);
    node->m_fMinimumU = hkpMoppDefaultSplitter_split(node, &left, 0, depth + 1);
    return node;
}

void* __cdecl AllocateWithHeader(void* pvAllocator, int iNumBytes);
void __cdecl hkMemoryRouter_easyFree(void* pvAllocator, void* pvMem);

template <typename T> inline T* hkAllocateStackE0A5(int n)
{
    void* pvAllocator = (void*)hkMemoryRouter_getInstance()->pListener;
    return (T*)AllocateWithHeader(pvAllocator, n * sizeof(T));
}

template <typename T> inline void hkDeallocateStackE0A5(T* p)
{
    void* pvAllocator = (void*)hkMemoryRouter_getInstance()->pListener;
    hkMemoryRouter_easyFree(pvAllocator, p);
}

class hkInputE0A5
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual int GetLogicalSize() throw();
};

class hkOutputE0A5
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int getA() throw();
    virtual int getB() throw();
    virtual void finish(int iResult, void* pvOwner, int iSize) throw();
};

struct hkSettingsE0A5
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    bool m_14;
};

struct hkBuffersE0A5
{
    int m_00;
    char* m_04;
    char* m_08;
};

struct hkNodeAE0A5
{
    hkNodeAE0A5* m_next;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40,
        unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78;
};

struct hkNodeBE0A5
{
    hkNodeBE0A5* m_next;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40,
        unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
};

// Two-field MOPP node pool (head/count), matching hkpFreeList rather than the 0x34-byte hkFreeList allocator.
template <typename T> struct MoppNodeFreeList
{
    T* m_pFirstNode;
    int m_uiItemCount;

    void push(T* pkNode)
    {
        pkNode->m_next = m_pFirstNode;
        m_uiItemCount++;
        m_pFirstNode = pkNode;
    }
    void init(char* pBuf, int n)
    {
        m_pFirstNode = 0;
        m_uiItemCount = 0;
        T* p = (T*)pBuf;
        for (int i = 0; i < n; i++)
            push(&p[i]);
    }
};

// The split call at 0x00e0a270 takes primitives/count/split budget, not the 0x10-byte hkJob metadata.
struct MoppPrimitiveSpan
{
    int m_00;
    int m_iElementCount;
    int m_extra;
};

struct hkStackE0A5
{
    int m_iElementCount;
    int m_pRayCursor;
    int* m_data;
    int m_0c;
};

class hkProcessorE0A5
{
  public:
    int m_00;
    int m_04;
    hkSettingsE0A5* m_settings;
    hkStackE0A5* m_aiEntries;
    MoppNodeFreeList<hkNodeAE0A5> m_nodesA;
    MoppNodeFreeList<hkNodeBE0A5> m_nodesB;
    int m_20;
    hkOutputE0A5* m_pRayCastOutput;
    hkInputE0A5* m_pRayCastInput;
    int m_2c;
    int m_30;
    int m_34;
    int m_iNumBits;

    int hkpMoppDefaultSplitter_split(int a, MoppPrimitiveSpan* pkJob, int b, int c) throw();
    int hkpMoppDefaultSplitter_buildTree(hkInputE0A5* pkInput, int iArg, hkOutputE0A5* pkOutput, hkSettingsE0A5* pkSettings,
                     hkBuffersE0A5* pkBuffers) throw();
};

// Configures the processor with input, output, settings and buffers, allocates a stack, runs FUN_00e0a270, and finalizes the output.
// @fnv 0x00e0a550
// src: HAVOK_LIB 0x00e0a550
int hkProcessorE0A5::hkpMoppDefaultSplitter_buildTree(hkInputE0A5* pkInput, int iArg, hkOutputE0A5* pkOutput, hkSettingsE0A5* pkSettings,
                                  hkBuffersE0A5* pkBuffers) throw()
{
    m_settings = pkSettings;
    m_20 = iArg;
    m_pRayCastInput = pkInput;
    m_pRayCastOutput = pkOutput;

    MoppPrimitiveSpan kJob;
    int iSize = pkInput->GetLogicalSize();
    kJob.m_iElementCount = iSize;
    kJob.m_extra = pkSettings->m_04;
    kJob.m_00 = pkBuffers->m_00;

    m_iNumBits = 0;
    int n = kJob.m_iElementCount;
    if (n)
    {
        int iBits = 0;
        do
        {
            n >>= 1;
            iBits++;
        } while (n);
        m_iNumBits = iBits;
    }

    int iNumNodes = m_settings->m_14 ? 0x1000 : kJob.m_iElementCount + kJob.m_extra;

    m_nodesA.m_pFirstNode = 0;
    m_nodesA.m_uiItemCount = 0;
    hkNodeAE0A5* pkNodesA = (hkNodeAE0A5*)pkBuffers->m_04;
    for (int i = 0; i < iNumNodes; i++)
        m_nodesA.push(pkNodesA++);

    m_nodesB.m_pFirstNode = 0;
    m_nodesB.m_uiItemCount = 0;
    hkNodeBE0A5* pkNodesB = (hkNodeBE0A5*)pkBuffers->m_08;
    for (int i = 0; i < iNumNodes; i++)
        m_nodesB.push(pkNodesB++);

    m_30 = pkOutput->getA();
    m_34 = pkOutput->getB();

    hkStackE0A5 kStack;
    int iStackCapacity = m_settings->m_08 + 2;
    kStack.m_data = hkAllocateStackE0A5<int>(iStackCapacity);
    kStack.m_pRayCursor = iStackCapacity;
    kStack.m_iElementCount = 0;
    kStack.m_0c = 0;
    m_aiEntries = &kStack;

    int iResult = hkpMoppDefaultSplitter_split(0, &kJob, 0, 0);
    {
        pkOutput->finish(iResult, this, iNumNodes * 2);
    }

    m_aiEntries = 0;
    m_34 = 0;
    m_30 = 0;
    hkDeallocateStackE0A5(kStack.m_data);
    return iResult;
}

#include <math.h>
extern double const DAT_0101de30;
extern double DAT_01034208;

struct FUN_00e0a6c0_Parameters
{
    int m_00;
    int m_04;
    char m_08[0x0c];
    int m_14;
    char m_18[0x04];
    float m_1c;
    char m_20[0x14];
    int m_34;
};

struct FUN_00e0a6c0_Class
{
    char m_00[0x10];
    float m_10;

    float hkpMoppCostFunction_costNumUnBalanced(const FUN_00e0a6c0_Parameters* parameters);
};

// Scales |m_14 - m_34| by m_1c, adjusts it by m_00 < m_04 (returning 0 if negative), takes the 4th power and returns it times m_10.
// @fnv 0x00e0a6c0
// src: HAVOK_LIB 0x00e0a6c0
float FUN_00e0a6c0_Class::hkpMoppCostFunction_costNumUnBalanced(const FUN_00e0a6c0_Parameters* parameters)
{
    int difference = parameters->m_14 - parameters->m_34;
    double absoluteDifference = fabs(static_cast<double>(difference));
    float value = static_cast<float>(absoluteDifference) * parameters->m_1c;

    if (parameters->m_00 < parameters->m_04)
    {
        value = static_cast<float>(static_cast<double>(value) - DAT_0101de30);
        value = static_cast<float>(static_cast<double>(value) * DAT_01034208);
        if (value < 0.0f)
            return 0.0f;
    }
    else
    {
        value = value * value;
    }

    value = value * value * value * value;
    return value * m_10;
}

struct S00e098b0_Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct S00e098b0_Range
{
    S00e098b0_Elem* data;
    int count;
};

struct S00e098b0_Handler
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual int addRange(S00e098b0_Elem* elem, unsigned int* output);
};

struct S00e098b0_Owner
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
    S00e098b0_Handler* handler;
};

struct NodeBounds
{
    void* next;
    int active;
    int count;
    unsigned int key0min, key0max, key1min, key1max, key2min, key2max;
    unsigned int minimum, maximum;
    int maxResults;
    unsigned int bounds[4];
};
struct MatchOwner
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    S00e098b0_Handler* handler;
    void hkpMoppDefaultSplitter_calculateMaxMinId(S00e098b0_Range* range, NodeBounds* node);
};
// Iterates a range of elements, calls handler->addRange on each, and accumulates min/max values and per-result bounds into the NodeBounds node.
// @fnv 0x00e098b0
// src: HAVOK_LIB 0x00e098b0
void MatchOwner::hkpMoppDefaultSplitter_calculateMaxMinId(S00e098b0_Range* range, NodeBounds* node)
{
    S00e098b0_Elem* elem = range->data;
    unsigned int minimum = elem->unk00;
    unsigned int maximum = elem->unk00;
    NodeBounds* dest = node;
    unsigned int output[1];
    dest->maxResults = 0;
    dest->bounds[0] = ~0u;
    dest->bounds[1] = 0;
    for (int remaining = range->count - 1; remaining >= 0; ++elem, --remaining)
    {
        unsigned int value = elem->unk00;
        if (value > maximum)
            maximum = value;
        if (value < minimum)
            minimum = value;
        int count = handler->addRange(elem, output);
        if (count > dest->maxResults)
            dest->maxResults = count;
        for (int i = 0; i < count; ++i)
        {
            unsigned int result = output[i];
            if (result < dest->bounds[i])
                dest->bounds[i] = result;
            if (result > dest->bounds[i + 1])
                dest->bounds[i + 1] = result;
        }
    }
    dest->count = range->count;
    dest->minimum = minimum;
    dest->maximum = maximum;
}

extern "C" __int64 __emul(int, int);
void __cdecl QuickSortElements(SortElemE0AB* pArr, int iD, int iH, SortLessE0AB kCmpLess);
inline void SortE0AC(SortElemE0AB* a, int n, SortLessE0AB c)
{
    if (n > 1)
        QuickSortElements(a, 0, n - 1, c);
}
inline int CountE0AC(SortElemE0AB** b, SortElemE0AB** e)
{
    return (int)(*e - *b);
}
struct InnerE0AC
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_14;
};
struct BoxE0AC
{
    int unk00;
    int unk04;
    int unk08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
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
    int unk58;
    int unk5c;
    InnerE0AC* m_60;
};
struct TableE0AC
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
class HandlerE0AC
{
  public:
    virtual void V00() throw();
    virtual void V04() throw();
    virtual void V08() throw();
    virtual void V0C() throw();
    virtual void V10() throw();
    virtual void V14() throw();
    virtual void Method(TableE0AC* entry, int axis, SortElemE0AB* arr, int n, int* out1, int* out2) throw();
};
class ThisE0AC
{
  public:
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
    HandlerE0AC* m_28;
    int unk2c;
    int unk30;
    TableE0AC* m_34;

    void hkpMoppDefaultSplitter_distributeMiddle(SortElemE0AB** p0, SortElemE0AB** p1, SortElemE0AB** p2, SortElemE0AB** p3, SortElemE0AB** p4,
                      SortElemE0AB** p5, BoxE0AC* box) throw();
};

// Picks the box axis with the largest extent (excluding one), sorts the p4..p5 range, then moves elements between the p0/p1 and p2/p3 ranges to rebalance them.
// @fnv 0x00e0acb0
// src: HAVOK_LIB 0x00e0acb0
void ThisE0AC::hkpMoppDefaultSplitter_distributeMiddle(SortElemE0AB** p0, SortElemE0AB** p1, SortElemE0AB** p2, SortElemE0AB** p3,
                            SortElemE0AB** p4, SortElemE0AB** p5, BoxE0AC* box) throw()
{
    int n = (int)(*p5 - *p4);
    if (n == 0)
        return;
    float best = 0.0f;
    int axis = 0;
    int iExcluded = box->m_60->m_14;
    if (iExcluded != 0)
    {
        float d = box->m_10 - box->m_0c;
        if (d > best)
            best = d;
    }
    if (iExcluded != 1)
    {
        float d = box->m_18 - box->m_14;
        if (d > best)
        {
            best = d;
            axis = 1;
        }
    }
    if (iExcluded != 2)
    {
        float d = box->m_20 - box->m_1c;
        if (d > best)
            axis = 2;
    }
    struct Outs
    {
        int first;
        int second;
    };
    Outs outs;
    m_28->Method(m_34 + axis, axis, *p4, n, &outs.first, &outs.second);
    SortE0AC(*p4, n, SortLessE0AB());
    const int& byteA = ((char*)*p1 - (char*)*p0);
    struct hSol
    {
        int a, b;
    } h;
    int truncA, truncB;
    int signA, signB;
    int quotA, quotB;
    h.a = (int)((unsigned __int64)__emul(0x66666667, byteA) >> 32);
    h.b = (int)((unsigned __int64)__emul(0x66666667, ((char*)*p3 - (char*)*p2)) >> 32);
    truncB = h.b >> 3;
    truncA = h.a >> 3;
    signB = (unsigned)truncB >> 31;
    signA = (unsigned)truncA >> 31;
    quotB = signB + truncB;
    quotA = signA + truncA;
    bool flag = quotA < quotB;
    while (*p4 < *p5)
    {
        int countA = (int)(*p1 - *p0);
        int countB = (int)(*p3 - *p2);
        int a = countA;
        int b = countB;
        if (flag)
            b *= 4;
        else
            a *= 4;
        if (a < b)
        {
            SortElemE0AB tmpA = (*p5)[-1];
            (*p5)[-1] = **p4;
            SortElemE0AB tmpB = **p2;
            **p1 = tmpA;
            **p4 = tmpB;
            (*p1)++;
            (*p2)++;
            (*p4)++;
            (*p3)++;
            flag = true;
        }
        else
        {
            (*p3)++;
            (*p4)++;
            flag = false;
        }
    }
}

extern float DAT_01017d00;
extern unsigned int DAT_010d51b0;
extern unsigned int DAT_010ea5f8;

struct Item20
{
    unsigned int id;
    int unk04;
    float f08;
    float f0c;
    float f10;
};
struct ObjRef
{
    int unk00, unk04, unk08, unk0c;
    float f10;
};
struct OutRec
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    ObjRef* picked;
    float out64, out68, out6c;
};
struct ItemSpan
{
    Item20* data;
    int count;
    int window;
};
struct SearchCtx
{
    int tag, copied38;
    float range0, range1, inv;
    int index, count;
    float countF;
    float sample;
    ObjRef* obj;
    unsigned int minId, maxId;
    int pick, pos;
    float cand;
    int half;
    float termA;
    int unk44, unk48;
    float s850, s6c0, termB;
    int unk58, unk5c, unk60, unk64;
    float s750, penalty;
    int unk70, unk74, unk78, unk7c, unk80;
    float f10;
};
struct CandList
{
    int count;
    int unk04;
    Item20** data;
    Item20* last;
    void RemoveExpiredEntries(float value);
    void hkpMoppDefaultSplitter_hkpMoppMaxList_addElement(Item20* item);
};
struct LimitsObj
{
    int unk00, unk04, maxWindow, halfSrc, enabled;
};
struct ScorerObj
{
    int unk00, unk04;
    float f08, f0c, f10, f14, f18, f1c;
    float ComputeResponse(SearchCtx* ctx);
    float hkpMoppCostFunction_costUnbalancedPlaneLeft(SearchCtx* ctx);
    float hkpMoppCostFunction_costNumUnBalanced(SearchCtx* ctx);
};
struct SeqOwner
{
    int unk00, unk04;
    LimitsObj* limits;
    CandList* list;
    int unk10, unk14, unk18, unk1c;
    ScorerObj* scorer;
    int unk24, unk28, unk2c, unk30, unk34;
    int field38;
    void hkpMoppDefaultSplitter_findSplittingPlanePositions(OutRec* out, ObjRef* obj, ItemSpan* span, float* range, int tag);
};

static __forceinline int computeEnd(int flag, int half, int cursor, int listCount, int& low)
{
    int e;
    if (flag > 0)
    {
        e = half + cursor;
        if (e > listCount)
            e = listCount;
        int l = cursor - half;
        if (l < 0)
        {
            low = 0;
            return e;
        }
        low = l;
        return e;
    }
    return listCount;
}
// For each item in span, scores candidates from the candidate list and updates out with the lowest cost found, then clears the list.
// @fnv 0x00e09be0
// src: HAVOK_LIB 0x00e09be0
void SeqOwner::hkpMoppDefaultSplitter_findSplittingPlanePositions(OutRec* out, ObjRef* obj, ItemSpan* span, float* range, int tag)
{
    struct Indices
    {
        int i;
        int cursor;
        int j;
    };
    Indices indices;
    SearchCtx ctx;
    ctx.tag = tag;
    ctx.copied38 = this->field38;
    ctx.range0 = range[0];
    ctx.range1 = range[1];

    indices.cursor = 0;
    int window = span->window;
    int count = span->count;
    ctx.count = count;
    ctx.obj = obj;
    unsigned int uiFirstId = span->data[0].id;
    ctx.countF = 1.0f / (float)count;
    ctx.minId = uiFirstId;
    ctx.maxId = uiFirstId;
    float delta = range[1] - range[0];
    if (DAT_01017d00 > delta)
        ctx.inv = 1.0f;
    else
        ctx.inv = 1.0f / delta;

    int cap = this->limits->maxWindow;
    if (window > cap)
        window = cap;

    for (indices.i = 0; indices.i < span->count; ++indices.i)
    {
        ctx.index = indices.i;
        float* __restrict p = &span->data[indices.i].f08;
        ctx.sample = *p;
        unsigned int id = span->data[indices.i].id;
        if (ctx.minId >= id)
            ctx.minId = id;
        if (ctx.maxId <= id)
            ctx.maxId = id;
        this->list->RemoveExpiredEntries(ctx.sample);

        CandList* pCandList = this->list;
        int n = pCandList->count - 1;
        if (n > window)
        {
            do
            {
                Item20* entry = pCandList->data[n];
                pCandList->last = entry;
                pCandList->data[n] = 0;
                --pCandList->count;
                --n;
            } while (n > window);
        }
        LimitsObj* limits = this->limits;
        int halfSrc = limits->halfSrc;
        ScorerObj* scorer = this->scorer;
        int flag = limits->enabled;
        ctx.s750 = scorer->ComputeResponse(&ctx);
        int spanW = (int)(ctx.maxId - ctx.minId);
        ctx.f10 = ctx.obj->f10;
        if (spanW < 16)
            ctx.penalty = scorer->f18 * *(double*)&DAT_010ea5f8;
        else
            ctx.penalty = 0.0f;
        indices.j = 0;
        int low = 0;
        pCandList = this->list;
        float base = ctx.f10 + ctx.s750 + ctx.penalty;
        int listCount = pCandList->count;
        ctx.half = halfSrc >> 1;
        float best = *(float*)&DAT_010d51b0;
        Item20* cand = 0;
        if (listCount == 0)
        {
            cand = pCandList->last;
            if (cand == 0)
                goto after;
            goto score;
        }
        if (base > out->out6c)
            goto after;
        indices.j = computeEnd(flag, ctx.half, indices.cursor, listCount, low) - 1;
    loop_head:
        if (indices.j < low)
            goto dec_cursor;
        if (indices.j <= this->list->count)
            cand = this->list->data[indices.j];
        else
            cand = 0;
    score:
        int rem = span->count - indices.i;
        ctx.cand = cand->f0c;
        ctx.pick = indices.j;
        ctx.pos = rem + indices.j;
        ctx.s850 = scorer->hkpMoppCostFunction_costUnbalancedPlaneLeft(&ctx);
        ctx.s6c0 = scorer->hkpMoppCostFunction_costNumUnBalanced(&ctx);

        float jScaled = (float)indices.j * ctx.countF;
        ctx.termA = jScaled * 5.0 * scorer->f08;
        float diff = ctx.cand - ctx.sample;
        float diffNorm = diff * ctx.inv;
        ctx.termB = diffNorm * scorer->f0c;
        float sum = ctx.s6c0 + ctx.s850 + ctx.termA + ctx.termB;
        float cost = sum + base;
        if (cost < best)
        {
            best = cost;
            indices.cursor = indices.j;
            if (out->out6c > cost)
            {
                out->out6c = cost;
                out->out64 = ctx.sample;
                out->picked = ctx.obj;
                out->out68 = ctx.cand;
                if (indices.j - ctx.half < low)
                {
                    low = indices.j - ctx.half;
                    if (low < 0)
                        low = 0;
                }
            }
        }
        --indices.j;
        goto loop_head;
    dec_cursor:
        --indices.cursor;
    after:
        this->list->hkpMoppDefaultSplitter_hkpMoppMaxList_addElement(&span->data[indices.i]);
    }
    CandList* tail = this->list;
    for (int n = tail->count - 1; n > 0; --n)
        tail->data[n] = 0;
    tail->last = 0;
    tail->count = 0;
}
// src: HAVOK_LIB 0x00e0a850
__declspec(noinline) float ScorerObj::hkpMoppCostFunction_costUnbalancedPlaneLeft(SearchCtx* c)
{
    float center = (c->range0 + c->range1) * 0.5;
    float diff = c->cand - center;
    float inv;
    if (c->tag < c->copied38)
    {
        float span = c->range1 - c->range0;
        float cap = this->f1c;
        float v = cap < span ? cap : span;
        float denom = span + v;
        if (denom > 0.0f)
            inv = 1.0f / denom;
        else
            inv = DAT_010ea608;
    }
    else
        inv = c->inv;
    float scaled = inv * diff;
    if (scaled > 0.0f)
        return 0.0f;
    float square = scaled * scaled;
    float fourth = square * square;
    float eighth = fourth * fourth;
    float poly = fourth * 3.0 + square * DAT_010ea600 + eighth * DAT_010737c8;
    float result = poly * f14;
    return result;
}

extern "C" double fabs(double);
// src: HAVOK_LIB 0x00e0a6c0
__declspec(noinline) float ScorerObj::hkpMoppCostFunction_costNumUnBalanced(SearchCtx* c)
{
    float d = (float)(c->index - c->pos);
    d = (float)fabs(d);
    d = d * c->countF;
    if (c->tag < c->copied38)
    {
        d = d - 0.75;
        d = d * 6.0;
        if (d < 0.0f)
            d = 0.0f;
    }
    else
        d = d * d;
    d = d * d * d * d;
    d = d * f10;
    return d;
}

struct QuadExtent
{
    float min;
    float max;
};

struct QuadElement
{
    unsigned primitiveID;
    unsigned secondaryID;
    QuadExtent extent;
    unsigned originalID;
};

struct QuadRange
{
    QuadElement* m_elements;
    int m_iCapacity;
    int m_numTotal;
};

struct QuadCenter
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
    float m_uiX;
    float m_uiY;
};

int __cdecl hkMath_hkFloatToInt(float f);

class QuadSplitter
{
  public:
    __declspec(noalias) void hkpMoppDefaultSplitter_sortLeftAndRight(int quadrant, QuadCenter* center, int context, int* total, int* counter,
                                          QuadElement** cur, QuadElement** mid, QuadElement** p2, QuadElement** p3);
    __declspec(noalias) void hkpMoppDefaultSplitter_distributeMiddle(QuadElement** p0, QuadElement** mid, QuadElement** p2, QuadElement** p3,
                                          QuadElement** p4, QuadElement** p5, QuadCenter* center);
    void hkpMoppDefaultSplitter_groupPrimitives(QuadRange* in, QuadCenter* center, int context, QuadRange* outA, QuadRange* outB);
};

// Partitions elements in in into outA and outB by quadrant relative to center, updating capacities and totals.
// @fnv 0x00e0a0b0
// src: HAVOK_LIB 0x00e0a0b0
void QuadSplitter::hkpMoppDefaultSplitter_groupPrimitives(QuadRange* in, QuadCenter* center, int context, QuadRange* outA, QuadRange* outB)
{
    int total = in->m_numTotal;
    int counter = 0;
    QuadElement* cur;
    QuadElement* p0;
    QuadElement* pMid;
    QuadElement* p2;
    QuadElement* p3;
    QuadElement* p4;
    QuadElement* mid;
    QuadElement* end;
    QuadElement* p5;

    p0 = in->m_elements;
    mid = p0 + in->m_iCapacity;
    end = p0 + (in->m_iCapacity + in->m_numTotal);
    p2 = end;
    p3 = end;
    p5 = end;
    cur = (p0 != 0) ? p0 : p0;

    while (cur < mid)
    {
        int quadrant = 0;
        if (cur->extent.min < center->m_uiX)
        {
            if (cur->extent.max <= center->m_uiY)
                quadrant = 1;
            else
                quadrant = 3;
        }
        else if (cur->extent.max > center->m_uiY)
            quadrant = 2;

        hkpMoppDefaultSplitter_sortLeftAndRight(quadrant, center, context, &total, &counter, &cur, &mid, &p2, &p3);
    }

    p4 = p3;
    hkpMoppDefaultSplitter_distributeMiddle(&p0, &mid, &p2, &p4, &p3, &p5, center);

    pMid = mid;
    outA->m_iCapacity = pMid - p0;
    outA->m_numTotal = hkMath_hkFloatToInt((float)outA->m_iCapacity * total / in->m_iCapacity);
    outB->m_iCapacity = p4 - p2;
    outB->m_numTotal = total - outA->m_numTotal;
    outA->m_elements = p0;
    outB->m_elements = pMid + outA->m_numTotal;

    if (outB->m_numTotal != 0)
    {
        QuadElement* dst = outB->m_elements;
        QuadElement* last = p4;
        for (; p2 < last; ++p2)
            *dst++ = *p2;
    }
}

namespace fnv_00e0a850 {
extern const double DAT_01011588;
extern const double DAT_01021928;
extern const double DAT_010ea600;
extern const double DAT_010737c8;
extern const float DAT_010ea608;
struct FnParams
{
    int first, last;
    float lower, upper, default_scale;
    int unknown14, unknown18, unknown1c, unknown20, unknown24, unknown28, unknown2c, unknown30, unknown34;
    float displacement;
};
struct FnvCurve
{
    int unknown00, unknown04, unknown08, unknown0c, unknown10;
    float coefficient;
    int unknown18;
    float threshold;
    float hkpMoppCostFunction_costUnbalancedPlaneLeft(FnParams* p);
};
// Returns 0 if scale*phase is positive, otherwise an even polynomial in scale*phase times coefficient, with scale from p's bounds and threshold.
// @fnv 0x00e0a850
// src: HAVOK_LIB 0x00e0a850
float FnvCurve::hkpMoppCostFunction_costUnbalancedPlaneLeft(FnParams* apParams)
{
    float phase = apParams->displacement - (float)((apParams->upper + apParams->lower) * DAT_01011588);
    float scale;
    if (apParams->first < apParams->last)
    {
        float width = apParams->upper - apParams->lower;
        float bound = threshold;
        float selected;
        if (bound < width)
            selected = bound;
        else
            selected = width;
        if (width + selected > 0.0f)
            scale = 1.0f / (width + selected);
        else
            scale = DAT_010ea608;
    }
    else
        scale = apParams->default_scale;
    float x = scale * phase;
    if (x > 0.0f)
        return 0.0f;
    float x2 = x * x;
    float x4 = x2 * x2;
    float x8 = x4 * x4;
    float poly = (x2 * DAT_010ea600 + x4 * DAT_01021928) + x8 * DAT_010737c8;
    return poly * coefficient;
}
}  // namespace fnv_00e0a850
