#include <xmmintrin.h>
typedef ::__m128 LocalM128;
// src/staging/blk_00e00000_od_o2_nood_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00e00000_od_o2_nood_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/staging/blk_00e00000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00e00000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00e00000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/FinishingFlag.h"
struct __declspec(align(16)) FinishedObject
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;
    void* secondaryVtable;
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
    FinishedObject(FinishingFlag);
};
void* __cdecl Runtime_EvaluateValue_00e005f0();
// Havok type-registration helper: construct the class in finish-loading mode (flag 0) on the stack,
// then return its static registration data.
extern char DAT_010e8ab0[];
struct __declspec(align(16)) S_00e00cd0_Obj
{
    void* m_vtbl;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    void* m_vtbl10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4c;
    unsigned int m_50;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5c;
    S_00e00cd0_Obj(FinishingFlag flag);
};
const char* __cdecl getVtablehkpFastMeshShape();
// Havok vtable getter: finish-construct a throwaway instance in an aligned scratch buffer (the
// FinishingFlag constructor only re-installs the vtable and runs the members'
// finish constructors) and return its vtable pointer.
struct hkFinishMemberE01710
{
    void* m_ptr;
    hkFinishMemberE01710(FinishingFlag flag);
};
inline void* operator new(unsigned int, void* pvWhere) throw()
{
    return pvWhere;
}
struct __declspec(align(16)) hkObjectE01710
{
    virtual ~hkObjectE01710();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    hkFinishMemberE01710 m_member18;
    hkFinishMemberE01710 m_member1c;

    hkObjectE01710(FinishingFlag flag) : m_member18(flag), m_member1c(flag)
    {}
};
void* hkObjectE01710_AllocateStorage_00e01710();
// RTTI identifies hkpNullCollisionFilter. The finish constructor installs its
// primary and four interface type headers; its filter kind is at offset0x20.
struct __declspec(align(16)) FUN_00e00a80
{
    virtual ~FUN_00e00a80();
    unsigned short memorySizeAndFlags;
    short referenceCount;
    void* collidableFilterInterface;
    void* shapeCollectionFilterInterface;
    void* rayShapeCollectionFilterInterface;
    void* rayCollidableFilterInterface;
    unsigned unk18, unk1c;
    unsigned filterType;
    FUN_00e00a80(FinishingFlag);
};
// Complete, naturally padded object representation backs the placement lifetime.
struct __declspec(align(16)) FilterStorage402
{
    void* primaryTypeHeader;
    unsigned short memorySizeAndFlags;
    short referenceCount;
    void* collidableFilterInterface;
    void* shapeCollectionFilterInterface;
    void* rayShapeCollectionFilterInterface;
    void* rayCollidableFilterInterface;
    unsigned unk18, unk1c;
    unsigned filterType;
};
unsigned Object_ProcessAndReturnValue_00e00a60();
class __declspec(align(16)) S00e000e0_Object
{
  public:
    S00e000e0_Object(FinishingFlag flag);  // FUN_00d50c00
    void* m_ppVirtualMethodTable;
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
};
const void* __cdecl Object_GetConstructedVirtualTable_00e000e0();
struct Handle_e00290
{
    int m_v;
};
struct FUN_00e00290_sub
{
    void ReturnSelf(Handle_e00290 kHandle);
    int m_00;
};
extern int DAT_010cc040;
extern int DAT_010d79e8;
struct SmallArray_e00290
{
    void* m_pData;
    unsigned short m_usSize;
    unsigned short m_usCapacityAndFlags;
};
struct __declspec(align(16)) FUN_00e00290_obj
{
    int* m_pVtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    SmallArray_e00290 m_kArray;
    FUN_00e00290_sub m_kSub;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
};
int* __cdecl getVtablehkpConstraintChainInstance();
class __declspec(align(16)) S00e003b0_Object
{
  public:
    S00e003b0_Object(FinishingFlag flag);  // FUN_00e003d0
    void* m_ppVirtualMethodTable;
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
};
const void* __cdecl Runtime_GetVtableFromTemporary_00e003b0();
class __declspec(align(16)) S00e004d0_Object
{
  public:
    S00e004d0_Object(FinishingFlag flag);  // FUN_00e004f0
    void* m_ppVirtualMethodTable;
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
};
const void* __cdecl Runtime_GetVtableFromTemporary_00e004d0();
class __declspec(align(16)) S00e006b0_Object
{
  public:
    S00e006b0_Object(FinishingFlag flag);  // FUN_00e006d0
    void* m_ppVirtualMethodTable;
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
};
const void* __cdecl Runtime_GetVtableFromTemporary_00e006b0();
class __declspec(align(16)) S00e00b80_Object
{
  public:
    S00e00b80_Object(FinishingFlag flag);  // FUN_00e00ba0
    void* m_ppVirtualMethodTable;
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
};
const void* __cdecl getVtablehkpGroupFilter();
class __declspec(align(16)) S00e00f90_Object
{
  public:
    S00e00f90_Object(FinishingFlag flag);  // FUN_00e00fb0
    void* m_ppVirtualMethodTable;
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
};
const void* __cdecl Runtime_GetVtableFromTemporary_00e00f90();
class __declspec(align(16)) S00e01230_Object
{
  public:
    S00e01230_Object(FinishingFlag flag);  // FUN_00e01250
    virtual void vf00();
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
};
const void* __cdecl Runtime_UpdateState_00e01230();
struct LoadedPointer
{
    int m_uiFilterValue;
    LoadedPointer(FinishingFlag flag);
};
struct __declspec(align(16)) LoadedObject
{
    virtual void vf00();
    int unk04;
    LoadedPointer m_pHeadNode;
    LoadedPointer m_iSecondInteger;
    LoadedPointer m_third;
    LoadedObject(FinishingFlag flag) : m_pHeadNode(flag), m_iSecondInteger(flag), m_third(flag)
    {}
};
const void* Runtime_UpdateState_00e01830();
class __declspec(align(16)) S00e01e50_Object
{
  public:
    S00e01e50_Object(FinishingFlag flag);  // FUN_00e4ad00
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
const void* __cdecl Runtime_GetVtableFromTemporary_00e01e50();
class __declspec(align(16)) S00e020f0_Object
{
  public:
    S00e020f0_Object(FinishingFlag flag);  // FUN_00e4ae80
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
const void* __cdecl Runtime_GetVtableFromTemporary_00e020f0();
struct Handle_e02180
{
    int m_v;
};
struct FUN_00e02180_sub
{
    void ReturnSelf(Handle_e02180 kHandle);
    int m_00;
};
extern int DAT_010e9ccc;
struct __declspec(align(16)) FUN_00e02180_obj
{
    int* m_pVtbl;
    int unk04;
    FUN_00e02180_sub m_kSub08;
    int unk0C;
    FUN_00e02180_sub m_kSub10;
    FUN_00e02180_sub m_kSub14;
    FUN_00e02180_sub m_kSub18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};
int* __cdecl Object_ProcessAndReturnValue_00e02180();
class __declspec(align(16)) S00e02730_Object
{
  public:
    S00e02730_Object(FinishingFlag flag);  // FUN_00e4af80
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
const void* __cdecl Runtime_GetVtableFromTemporary_00e02730();
#include <xmmintrin.h>
struct S_00e11530_Node
{
    S_00e11530_Node* next;
    int unk04;
    int unk08;
    int unk0c;
    LocalM128 bounds;
};
struct S_00e11530_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S_00e11530_Node* unk14;

    LocalM128* ProcessEntries_00e11530(LocalM128* out);
};
struct VecQ
{
    float x, y, z, w;
};
extern VecQ DAT_012683a0;
struct __declspec(align(16)) TransformQ
{
    float m_rot[12];
    VecQ m_vTranslation;
};
struct __declspec(align(16)) RotationQ
{
    float m_col[12];
};
struct ShapeQ
{
    void ProcessEntries_00e11a90(const TransformQ* t);
    void UpdateFields_00e11b40(const RotationQ* r);
};
extern unsigned __int64 g_unk01268370[6];
struct __declspec(align(16)) Rot
{
    unsigned __int64 d[6];
};
#include "../../include/hkTransform.h"
struct Owner
{
    void ProcessEntries_00e11a90(const hkTransform* xf);
    void UpdateFields_00e11ca0(const LocalM128* src);
};
struct __declspec(align(16)) S00e00d70_Object
{
    void* first;
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
    int unk58;
    int unk5c;
    void hkpCylinderShape_hkpCylinderShape_00d57b20(FinishingFlag arg);
};
int __cdecl hkpCylinderShape_hkpCylinderShape_00d57b20_EvaluateValue_00e00d70();
namespace N {
typedef ::__m128 LocalM128;
extern "C"
{
    N::LocalM128 _mm_load_ps(const float*);
    N::LocalM128 _mm_load_ss(const float*);
    N::LocalM128 _mm_set_ss(float);
    N::LocalM128 _mm_set1_ps(float);
    N::LocalM128 _mm_shuffle_ps(N::LocalM128, N::LocalM128, unsigned int);
    N::LocalM128 _mm_mul_ps(N::LocalM128, N::LocalM128);
    N::LocalM128 _mm_add_ps(N::LocalM128, N::LocalM128);
    N::LocalM128 _mm_add_ss(N::LocalM128, N::LocalM128);
using ::_mm_store_ps;
using ::_mm_cvtss_f32;
}
}
// Exe 0x00e11630: unit-local Vector4f view; declarations and layout are preserved.
struct __declspec(align(16)) BlkVector4fView
{
    float v[4];
    void addScaled(const N::LocalM128& scale, const BlkVector4fView& n)
    {
        N::_mm_store_ps(v, N::_mm_add_ps(N::_mm_mul_ps(N::_mm_shuffle_ps(scale, scale, 0), N::_mm_load_ps(n.v)),
                                         N::_mm_load_ps(v)));
    }
};
inline float maxScore(float a, float b)
{
    return a > b ? a : b;
}
inline N::LocalM128 scaleNormal(const BlkVector4fView& n, const N::LocalM128& s)
{
    return N::_mm_mul_ps(N::_mm_shuffle_ps(s, s, 0), N::_mm_load_ps(n.v));
}
struct Vertex
{
    Vertex* next;
    Vertex* prev;
    int unk08;
    int unk0c;
    BlkVector4fView position;
    BlkVector4fView normal;
    BlkVector4fView extra;
    int handle40;
    int handle44;
    Vertex() : handle40(-1), handle44(-1)
    {}
    void copy(const Vertex& a)
    {
        position = a.position;
        normal = a.normal;
        extra = a.extra;
        handle40 = a.handle40;
        handle44 = a.handle44;
    }
};
inline bool vertexLess(const Vertex* a, const Vertex* b)
{
    for (int i = 0; i < 3; ++i)
    {
        if (b->position.v[i] < a->position.v[i])
            return false;
        if (b->position.v[i] > a->position.v[i])
            return true;
    }
    return false;
}
struct VertexTriple
{
    Vertex* values[3];
    Vertex*& operator[](int n)
    {
        return values[n];
    }
    Vertex* const& operator[](int n) const
    {
        return values[n];
    }
};
struct EdgeTriple
{
    unsigned int values[3];
    unsigned int& operator[](int n)
    {
        return values[n];
    }
    const unsigned int& operator[](int n) const
    {
        return values[n];
    }
};
union __declspec(align(16)) EdgeQuad
{
    float v[4];
    unsigned int bits[4];
};
struct EdgeNode
{
    EdgeNode* next;
    EdgeNode* volatile prev;
    VertexTriple vertices;
    EdgeTriple edges;
    EdgeQuad normal;
    EdgeQuad extra;
    int unk40;
    EdgeNode()
    {}
    void copy(const EdgeNode& a)
    {
        vertices = a.vertices;
        edges = a.edges;
        normal = a.normal;
        extra.bits[0] = a.extra.bits[0];
        extra.bits[1] = a.extra.bits[1];
        extra.bits[2] = a.extra.bits[2];
        extra.bits[3] = a.extra.bits[3];
        unk40 = a.unk40;
    }
};
struct EdgeMesh
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
    EdgeNode* head;
    int count;
};
struct EdgeRef
{
    EdgeNode* node;
    int index;
    EdgeRef(EdgeNode* n, int i) : node(n), index(i)
    {}
    Vertex* first() const
    {
        return node->vertices[index];
    }
    Vertex* second() const
    {
        return node->vertices[(9 >> (index << 1)) & 3];
    }
};
struct EdgeAllocator;
template <class T> struct EdgeArray
{
    T* data;
    int size;
    int capacity;
    EdgeArray() : data(0), size(0), capacity(0x80000000)
    {}
    int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    void grow(int elementSize);
};
struct EdgeAllocator
{
    virtual void f0();
    virtual void f4();
    virtual void f8();
    virtual void fc();
    virtual void release(void*, int);
    template <class T> void reserve(EdgeArray<T>& array, int needed, int elementSize);
    template <class T> void clear(EdgeArray<T>& array, int elementSize);
};
struct EdgeMemory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    EdgeAllocator* allocator;
};
EdgeMemory* hkMemoryRouter_getInstance();
void hkArrayUtil__reserve(void*, void*, int, int);
void FUN_00c90940(void*, void*, int);
float Hkgpmesh_ComputeValues_00e13870(EdgeNode*, int);
float ClampedAcos(float);
template <class T> inline void EdgeAllocator::reserve(EdgeArray<T>& array, int needed, int elementSize)
{
    int available = array.capacity & 0x3fffffff;
    if (available < needed)
    {
        int next = available * 2;
        if (needed >= next)
            next = needed;
        hkArrayUtil__reserve(this, &array, next, elementSize);
    }
}
template <class T> inline void EdgeArray<T>::grow(int elementSize)
{
    EdgeMemory* memory = hkMemoryRouter_getInstance();
    if (size == (capacity & 0x3fffffff))
        FUN_00c90940(memory->allocator, this, elementSize);
}
template <class T> inline void EdgeAllocator::clear(EdgeArray<T>& array, int elementSize)
{
    array.size = 0;
    if ((array.capacity & 0x80000000) == 0)
        release(array.data, (array.capacity & 0x3fffffff) * elementSize);
    array.data = 0;
    array.capacity = 0x80000000;
}
struct PoolPage
{
    unsigned int storage[640];
    void* freeHead;
    int used;
};
struct EdgePool
{
    PoolPage** pages;
    int pageCount;
    int unk08;
    void* head;
    int size;
    int unk14;
    PoolPage* AllocateChainedSlotBlock();
    template <class T> T* allocate(const T& value)
    {
        PoolPage* page;
        if (!pageCount || !(page = pages[0])->freeHead)
            page = AllocateChainedSlotBlock();
        T* item = (T*)page->freeHead;
        page->freeHead = item->next;
        ++page->used;
        item->copy(value);
        item->prev = 0;
        item->next = (T*)head;
        if (head)
            ((T*)head)->prev = item;
        ++size;
        head = item;
        return item;
    }
};
struct PointerSlotArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* slots[1];
};
extern PointerSlotArray* DAT_0126ebe8;
extern int DAT_0126ebec;
extern int DAT_0126ebf0;
inline void registerEdge(EdgeNode* node, int tag)
{
    if (!(DAT_0126ebf0 & 1))
    {
        DAT_0126ebf0 |= 1;
        DAT_0126ebe8 = 0;
        DAT_0126ebec = 0;
    }
    node->edges[tag] = (unsigned int)DAT_0126ebe8 + DAT_0126ebec;
    if (DAT_0126ebe8)
        DAT_0126ebe8->slots[DAT_0126ebec] = (void*)((unsigned int)node + tag);
}
struct EdgeProcessor
{
    int unk00;
    int unk04;
    EdgePool vertices;
    EdgePool edges;
    void UpdateTriangleNormal(EdgeNode*);
    void ProcessEntries_00e195c0(float threshold, float distance, const EdgeMesh* mesh);
};

#include "../../include/hkVector4.h"

// 0x00e11630 returns its result as a plain 16-byte value: the original stores it once through the hidden return
// pointer, which only a POD return type compiles to (the shared hkVector4 has a user copy assignment).
struct FUN_00e11630_Result
{
    LocalM128 m_vComponents;
};

struct FUN_00e11630_Vec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkVector4 m_v10;
};

struct FUN_00e11630_Params
{
    int unk00;
    int unk04;
    FUN_00e11630_Vec* m_p08;
    FUN_00e11630_Vec* m_p0c;
    FUN_00e11630_Vec* m_p10;
};

extern float DAT_0106c2e0;

// @fnv 0x00e11630
// src: GUESS 0x00e11630 (confidence: low)
FUN_00e11630_Result __stdcall Runtime_ComputeValues_00e11630(const FUN_00e11630_Params* p)
{
    FUN_00e11630_Result r;
    r.m_vComponents = _mm_add_ps(p->m_p0c->m_v10.m_vComponents, p->m_p08->m_v10.m_vComponents);
    r.m_vComponents = _mm_add_ps(r.m_vComponents, p->m_p10->m_v10.m_vComponents);
    LocalM128 k = _mm_load_ss(&DAT_0106c2e0);
    k = _mm_shuffle_ps(k, k, 0);
    r.m_vComponents = _mm_mul_ps(r.m_vComponents, k);
    return r;
}
