#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkgpMesh_IConvexOverlap.h"
#include "../../../../../../include/hkAabb.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/Vec4.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/BSAudio.h"


// src/havok/common/internal/geometryprocessing/mesh/hkgpmesh_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/internal/geometryprocessing/mesh/hkgpmesh.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/internal/geometryprocessing/mesh/hkgpmesh.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/geometryprocessing/mesh/hkgpmesh.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00e12140_cls
{
    void hkgpMesh_setPartIdsAsPlaneIndices();
};
extern "C" void __cdecl Deallocate(void*);
extern int DAT_010eadfc;
struct FUN_00e22450
{
    void* m_p;
    FUN_00e22450(char f);
};
struct FUN_00e234e0_
{
    void FreeAllItems();
};
struct FUN_00e238e0_
{
    void ProcessState_00e238e0();
};
void __cdecl ProcessEntries();
void __cdecl hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_reset();
struct FUN_00e24a80_Class
{
    void __thiscall hkgpAbstractMesh_hkgpTriangulatorType_hkgpTriangulatorBase_VertexBase_hkgpTriangulatorBase_TriangleBase_hkgpTriangulatorBase_DefaultEdgeData_hkContainerHeapAllocator_hkContainerHeapAllocator_1_Edge_hkgpTriangulatorType_hkgpTriangulatorBase_VertexBase_hkgpTriangulatorBase_TriangleBase_hkgpTriangulatorBase_DefaultEdgeData_hkContainerHeapAllocator_hkContainerHeapAllocator_1_Vertex_hkgpTriangulatorType_hkgpTriangulatorBase_VertexBase_hkgpTriangulatorBase_TriangleBase_hkgpTriangulatorBase_();
};
struct Subobject
{
    virtual void Release(unsigned int flags);
};
struct __declspec(align(16)) S_00e120e0_Vec
{
    float x;
    float y;
    float z;
    float w;
    float x2;
    float y2;
    float z2;
    float w2;
};
struct S_00e120e0_Shape
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S_00e120e0_Vec GetData();
};
struct S_00e120e0_Collector
{
    float m_fValue;
    int m_iFilter;
    S_00e120e0_Shape* m_pShape;
    bool m_bHit;
    bool m_bFlag;
    S_00e120e0_Collector(float fValue, int iFilter, S_00e120e0_Shape* pShape, bool bFlag)
    {
        m_fValue = fValue;
        m_iFilter = iFilter;
        m_bHit = false;
        m_pShape = pShape;
        m_bFlag = bFlag;
    }
    virtual void Add();
};
void __cdecl AabbTree_ProcessIfPresent_00d1d570(void* pWorld, const S_00e120e0_Vec& kData, S_00e120e0_Collector* pCollector);
struct S_00e120e0
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
    bool TestShapeHit(S_00e120e0_Shape* pShape, float fValue, bool bFlag);
};
struct E122D0Face
{
    E122D0Face* m_next;
    int unk04;
    int m_kVertices[3];
};
struct E122D0Edge
{
    E122D0Face* m_face;
    int m_uiEdgeIndex;

    E122D0Edge()
    {}
    E122D0Edge(E122D0Face* face, int index) : m_face(face), m_uiEdgeIndex(index)
    {}
};
struct E122D0Mesh
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
    E122D0Face* m_faces;

    E122D0Edge FindEdge(int vertexA, int vertexB);
};
struct Allocator
{
    virtual void v00();
    virtual void* allocate(int);
    virtual void v08();
    virtual void v0c();
    __declspec(nothrow) virtual void freeBlock(void*, int);
};
struct VectorArray
{
    hkVector4* data;
    int size;
    int capacity;
    VectorArray() : data(0), size(0), capacity(0x80000000)
    {}
    void release(Allocator& heap)
    {
        size = 0;
        if (!(capacity & 0x80000000))
            heap.freeBlock(data, (capacity & 0x3fffffff) * 16);
    }
};
struct Options
{
    unsigned int unk00, unk04;
    unsigned char flag08, flag09, flag0a, flag0b;
    unsigned int unk0c;
    __declspec(nothrow) void hkgpConvexHull_BuildConfig_BuildConfig();
};
struct FUN_00d76ca0
{
    __declspec(nothrow) virtual ~FUN_00d76ca0();
    unsigned short memorySize, referenceCount;
    int unk08, unk0c, unk10;
    __declspec(nothrow) FUN_00d76ca0();
    static void* allocate(Allocator& heap, unsigned int bytes)
    {
        void* memory = heap.allocate(bytes);
        ((FUN_00d76ca0*)memory)->memorySize = (unsigned short)bytes;
        return memory;
    }
    static void* operator new(unsigned int bytes)
    {
        return allocate(reinterpret_cast<Allocator&>(hkMemoryRouter::getInstance().heap()), bytes);
    }
    __declspec(nothrow) void hkgpConvexHull_build(hkVector4*, int, const Options&);
    __declspec(nothrow) int GetInnerField1A8();
};
struct Hull
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    int count;
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
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    FUN_00d76ca0* builder;
    __declspec(nothrow) void ReleaseSubobject();
    __declspec(nothrow) void hkgpMesh_fetchPositions(VectorArray&);
    bool BuildHull();
};
void __cdecl __debugbreak();
int __stdcall hkgpAbstractMesh_struct_hkgpMeshBase_Edge_struct_hkgpMeshBase_Vertex_struct_hkgpMeshBase_Triangle_struct_hkContainerHeapAllocator_checkTopology(int);
extern char DAT_0103d078[];
extern char DAT_010eaf08[];
extern char DAT_010eaeb4[];
struct CharBuffer
{
    char* begin;
    char* end;
    unsigned int capacity;
    void FUN_00cb1600(char*, unsigned int);
    CharBuffer* ProcessAndReturnValue_00cc01c0(const char*);
    CharBuffer* WriteInt(int);
    void FUN_00cc00e0();
};
struct ErrorReporter
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual int Report(int, unsigned int, const char*, const char*, int);
};
extern ErrorReporter* DAT_01268360;
bool __stdcall CheckError(bool report);
struct FUN_00e14fe0_node
{
    FUN_00e14fe0_node* m_pNext;
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
    void* m_pKey34;
};
struct FUN_00e14fe0_cls
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
    FUN_00e14fe0_node* m_pHead2c;
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    char m_b100;
    char m_b101;
    void RemoveTriangle(FUN_00e14fe0_node* apNode);
    void hkgpMesh_removePlaneTriangles(void* apKey);
};
extern int DAT_01268370;
struct ArrayHeader
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ArrayHeader() throw() : m_pData(0), m_iArrayLength(0), m_uCapacity(0x80000000)
    {}
};
struct ArrayPair
{
    ArrayHeader m_kFirst;
    ArrayHeader m_kSecond;

    ~ArrayPair() throw();
};
struct Builder
{
    void hkgpConvexHull_generateGeometry(int aiFlag, ArrayPair* apPair) throw();
};
struct FUN_00e1d900_cls
{
    void hkgpMesh_appendFromGeometry(ArrayPair* apPair, int* apGlobal, int aiValue) throw();
    void hkgpMesh_appendFromConvexHull(Builder* apBuilder);
};
struct QueryObject
{
    virtual void First();
    virtual float Evaluate(int first, int second, int mode);
    int IsBelowThreshold(int first, int second, float threshold);
};
struct S_00e22580_Item
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
    float m_3c;
};
struct S_00e22580_Tri
{
    int unk0;
    int unk4;
    S_00e22580_Item* m_items[3];
};
struct S_00e22580_Obj
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    S_00e22580_Tri* m_20;
};
struct S_00e22580_Wrap
{
    S_00e22580_Tri* m_tri;
    S_00e22580_Wrap(S_00e22580_Tri* t) : m_tri(t)
    {}
    virtual void Dummy();
};
struct S_00e22580_Tester
{
    virtual void v0();
    virtual void v1();
    virtual bool Test(S_00e22580_Wrap* a, S_00e22580_Wrap* b, float f);
};
struct S_00e22580_Self
{
    int unk0;
    int m_iWordAt04;
    int m_8;
    S_00e22580_Tester* m_iThirdValue;
    bool TrianglesShareItem(S_00e22580_Obj* a, S_00e22580_Obj* b);
};
struct DataBlock
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;

    DataBlock& hkgpMeshBase_Vertex_Vertex(const DataBlock& arSource);
};
struct StateBlock
{
    int unk00;
    int unk04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    unsigned short m_uMode : 3;
    unsigned short m_bFlag : 1;
    unsigned short m_uItemCount : 12;
    unsigned short m_u22;

    StateBlock& hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_Triangle(const StateBlock& arSource);
};
struct Node
{
    Node* next;
    Node* previous;
    Node* hkgpMeshBase_Vertex_Vertex(Node* source);
};
struct Manager
{
};
struct Object
{
    Manager* manager;
};
struct This
{
    Object* object;
    int ready;
    int unk08;
    Node* head;
    unsigned int count;
    Manager* AllocateChainedSlotBlock();
    void PushFront(Node* volatile source);
};
struct S_00e25f00_Alloc
{
    virtual ~S_00e25f00_Alloc();
    virtual void* AllocateMemoryBlock(int n);
    virtual void ReleaseBlock(void* p, int n);
    virtual void* AllocateBufferWithSize(int& n);
    virtual void ReturnMemory(void* p, int n);
};
template <typename T> struct S_00e25f00_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline ~S_00e25f00_Array() throw()
    {
        _clearAndDeallocate(*reinterpret_cast<S_00e25f00_Alloc*>(hkMemoryRouter::get().m_heap));
    }

    static __forceinline void destruct(T* p, int n) throw()
    {
        for (int i = 0; i < n; i++)
            p[i].~T();
    }
    __forceinline void clear() throw()
    {
        destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(S_00e25f00_Alloc& alloc) throw()
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
struct S_00e25f00_Elem
{
    int unk0;
    int unk4;
    int unk8;
};
struct S_00e25f00
{
    S_00e25f00_Array<S_00e25f00_Array<S_00e25f00_Elem> > m_arrays;
    int unkC;
    S_00e25f00* FUN_00e25f00(unsigned int flags);
};
struct E25FB0Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned int m_ppLinks[3];
};
struct E25FB0Edge
{
    E25FB0Node* m_node;
    unsigned int m_uiEdgeIndex;
};
inline E25FB0Edge E25FB0MakeEdge(unsigned int packed)
{
    E25FB0Edge e;
    e.m_uiEdgeIndex = packed & 3;
    e.m_node = (E25FB0Node*)(packed & ~3);
    return e;
}
struct E25FB0Item
{
    char m_enabled;
    char unk01;
    char unk02;
    char unk03;
    int m_data;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct E25FB0Mesh
{
    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_setEdgeData(E25FB0Edge* edge, const int* data);
    void ProcessItems(E25FB0Edge edge, const E25FB0Item* items);
};
struct DataBlock_00e118e0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned char data;
};
struct Inputs_00e118e0
{
    unsigned int unk00;
    unsigned int unk04;
    DataBlock_00e118e0* first;
    DataBlock_00e118e0* second;
    DataBlock_00e118e0* third;
};
struct FUN_00e118e0_class
{
    void __thiscall ValidateTriangleAndComputePlane(void*, void*, void*, void*, void*);
    void __thiscall hkgpMesh_setPlane(const volatile Inputs_00e118e0*, void*, void*);
};
struct E12160Vertex
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_vContactPosition[4];
};
struct E12160Triangle
{
    int unk00;
    int unk04;
    E12160Vertex* m_kVertices[3];
};
bool __cdecl TriangleHasVertexAtPoint(const E12160Triangle* triangle, const float* point);
// Exe 0x00e21e30: unit-local ListNode view; declarations and layout are preserved.
struct HkgpmeshListNodeView
{
    HkgpmeshListNodeView* m_pNext;
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
    int m_i34;
};
struct FUN_00e12230_cls
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
    HkgpmeshListNodeView* m_pHead;

    void ReplaceValueInList(int oldValue, int newValue);
};
struct S_00e12920_Node
{
    S_00e12920_Node* next;
    int unk04, unk08, unk0C, unk10;
    unsigned int flags[3];
};
struct S_00e12920
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
    S_00e12920_Node* head;
    bool hkgpMesh_isClosedManifold();
};
typedef unsigned int hkUint32;
struct S_00e13910_Triangle
{
    int m_unk00;
    int m_unk04;
    void* m_kVertices[3];
    hkUint32 m_ppLinks[3];
};
struct S_00e13910_Edge
{
    S_00e13910_Triangle* m_pkTriangle;
    hkUint32 m_uiEdgeIndex;

    S_00e13910_Edge() : m_pkTriangle(0), m_uiEdgeIndex(0)
    {}
    S_00e13910_Edge(S_00e13910_Triangle* t, hkUint32 i) : m_pkTriangle(t), m_uiEdgeIndex(i)
    {}
    S_00e13910_Edge(hkUint32 l)
    {
        m_uiEdgeIndex = l & 3u;
        m_pkTriangle = (S_00e13910_Triangle*)(l & ~3u);
    }

    __forceinline bool isValid() const
    {
        return m_pkTriangle != 0;
    }

    __forceinline S_00e13910_Edge next() const
    {
        return S_00e13910_Edge(m_pkTriangle, (9 >> (m_uiEdgeIndex << 1)) & 3);
    }

    __forceinline S_00e13910_Edge prev() const
    {
        return S_00e13910_Edge(m_pkTriangle, (0x12 >> (m_uiEdgeIndex << 1)) & 3);
    }

    __forceinline S_00e13910_Edge link() const
    {
        hkUint32 l = m_pkTriangle->m_ppLinks[m_uiEdgeIndex];
        return S_00e13910_Edge(l);
    }

    __forceinline void*& start() const
    {
        return m_pkTriangle->m_kVertices[m_uiEdgeIndex];
    }

    __forceinline void*& apex() const
    {
        return prev().start();
    }

    __forceinline void bind(const S_00e13910_Edge& other) const
    {
        m_pkTriangle->m_ppLinks[m_uiEdgeIndex] = other.m_uiEdgeIndex + (hkUint32)other.m_pkTriangle;
        if (other.m_pkTriangle)
        {
            other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = m_uiEdgeIndex + (hkUint32)m_pkTriangle;
        }
    }

    static __forceinline S_00e13910_Edge null()
    {
        static S_00e13910_Edge n(0, 0);
        return n;
    }
};
S_00e13910_Edge __stdcall FlipEdge(S_00e13910_Edge edge);
// CreateTriangle (0x00e19cf0, 101 bytes)
//
//   push ebp / mov ebp,esp / and esp,-16 / sub esp,0x54
//   push ebx / push esi / push edi
//   mov  edi, ecx
//   lea  eax, [esp+0x10]          ; the 16-byte aligned local HullTriangle
//   push eax
//   lea  ecx, [edi+0x20]          ; the pool at this+0x20
//   call 0xe241a0                 ; pool->FUN_00e241a0(&local)
//   ...
//   mov  [esi+0x30], 0xffffffff   ; t->m_30 = -1
//   mov  [esi+0x14], eax          ; t->m_14 = 0   (eax = the zero register)
//   mov  [esi+0x18], eax          ; t->m_18 = 0
//   mov  [esi+0x1c], eax          ; t->m_1C = 0
//   mov  eax, [ebp+8]
//   push 1
//   mov  [esi+0x10], edx          ; t->m_10 = c
//   ...
//   call 0xe11710                 ; FUN_00e11710(a->pos,b->pos,c->pos,&t->m_20,1)
//
// The three zero stores go through a VOLATILE POINTER (not a volatile cast of
// the member): that is what keeps the zero register (xor eax,eax) and the
// `push 1` of the last argument in the original's positions - a plain or
// cast-volatile store lets MSVC hoist the constant push above the stores and
// lets the -1 store sink down to the call.
struct __declspec(align(16)) HullPlane
{
    float v[4];
};
struct HullVertex
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float pos[4];
};
struct __declspec(align(16)) HullTriangle
{
    int unk00;
    int unk04;
    HullVertex* m_08;
    HullVertex* m_0C;
    HullVertex* m_10;
    int m_14;
    int m_18;
    int m_1C;
    HullPlane m_20;
    int m_30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
};
struct HullTrianglePool
{
    HullTriangle* UpdateFields_00e241a0(HullTriangle* storage);
};
struct FUN_00e19cf0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    HullTrianglePool m_kNodePool;

    void ValidateTriangleAndComputePlane(float* a, float* b, float* c, HullPlane* out, char normalize);
    HullTriangle* CreateTriangle(HullVertex* a, HullVertex* b, HullVertex* c);
};
extern "C" double __cdecl sqrt(double);
extern float DAT_010d51c4;
extern double DAT_01021928;
extern double DAT_010290b0;
extern double DAT_0109cc78;
extern int DAT_010eb000;
extern int DAT_011bdee0;
struct FUN_00d9c110_object
{
    void FUN_00d9c110();
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
};
struct FUN_00e1b750
{
    int* vtable;
    short unk04;
    volatile short active06;
    volatile int f08, f0c, f10, f14, f18;
    int unk1c;
    volatile int f20, f24, f28, f2c, f30;
    int unk34;
    int* ptr38;
    int unk3c;
    FUN_00d9c110_object sub40;
    volatile int fc0, fc4, fc8, fcc, fd0, fd4, fd8, fdc, fe0;
    int unk_e4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    volatile float f104;
    float f108, f10c;
    FUN_00e1b750();
    void ResetState();
};
class E21CE0Ostream
{
  public:
    E21CE0Ostream(void* buf, int bufSize);
    E21CE0Ostream& operator<<(const char* str);
    // hkOstream destructor body (Havok was built without EH): called explicitly
    void destroy();

    int unk00;
    int unk04;
    int unk08;
};
class E21CE0Error
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual int message(int type, int id, const char* description, const char* file, int line);
};
extern E21CE0Error* g_E21CE0Error;
int __cdecl ReportNotImplemented();
struct VecData;
struct Components
{
    int x, y, z, w;
    void copy(const VecData* from);
};
struct VecData
{
    int unk00, unk04, unk08, unk0c, x, y, z, w;
};
inline void Components::copy(const VecData* from)
{
    x = from->x;
    y = from->y;
    z = from->z;
    w = from->w;
}
struct VectorGroup
{
    int unk00, unk04;
    VecData* first;
    VecData* second;
    VecData* third;
};
struct InputPacket
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    VectorGroup* group;
};
struct Triple
{
    Components first, second, third;
};
int __cdecl hkGeometryProcessing_checkTrianglesIntersection(void*, const Triple*);
struct FUN_00e22270_Class
{
    int unk00;
    unsigned int flags;
    int unk08, unk0c, output;
    float hkgpMeshInternals_TriangleOverlap_addLeaf(InputPacket*);
};
struct Target
{
    virtual void v00();
    virtual void v01();
    virtual void Forward(int a);
};
struct FUN_00e22470_cls
{
    int unk00;
    Target* m_04;
    void IConvexOverlapImpl_ShapeBridge_getSupportingVertex(int a);
};
struct FUN_00e22970_Item
{
    int m_data[12];
};
struct FUN_00e22970_Cls
{
    FUN_00e22970_Item* m_pItems;
    int m_uiItemCount;
    int m_pRayCursor;

    void AppendItems(void* apArg1, const FUN_00e22970_Item* apSrc, int aCount);
};
void __cdecl hkArrayUtil__reserve(void* apArg1, FUN_00e22970_Cls* apThis, int aCapacity, int aElemSize);
extern "C" void* __cdecl memcpy(void* apDst, const void* apSrc, unsigned int aCount);
struct FUN_00e229f0_cls
{
    int* m_data;
    int m_uiItemCount;
    unsigned int m_capBits;

    void AppendInts(int a1, int* a2, int a3);
};
void __cdecl hkArrayUtil__reserve(int a1, void* self, int newCap, int elemSize);
struct FUN_00e22c80_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;

    FUN_00e22c80_cls* ComputeValue_00e22c80(unsigned int value, FUN_00e22c80_cls* src);
};
extern unsigned int DAT_01267e30;
extern unsigned int DAT_01267e34;
extern unsigned int DAT_01267e38;
extern unsigned int DAT_01267e3c;
extern float DAT_0104da48;
extern unsigned int DAT_0126ebf0;
extern unsigned int DAT_0126ebe8;
extern unsigned int DAT_0126ebec;
struct FUN_00e22ca0_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
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
    float m_40;
    unsigned char m_44;
    unsigned int m_48;
    unsigned int m_4c;
    unsigned int m_50;
    FUN_00e22ca0_cls();
};
struct FUN_00e22f20_cls
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
    FUN_00e22f20_cls& hkgpMeshBase_Triangle_Triangle(const FUN_00e22f20_cls& src);
};
struct SearchItem
{
    int unk00;
    int unk04;
    unsigned int hashX;
    unsigned int hashY;
};
struct SearchPath
{
    SearchItem** nodes;
    int depth;
};
struct HashEntry
{
    SearchItem* left;
    SearchItem* right;
    int result;
};
struct HashBucket
{
    HashEntry* entries;
    int count;
    int unk08;
};
struct HashTableBase
{
    HashBucket* buckets;
    unsigned int bucketCount;
};
struct SearchOwner
{
    int LookupPairResult(SearchPath* path);
};
struct Entry
{
    Entry* next;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned int links[3];
    unsigned int flags;
};
struct Ref
{
    unsigned int value;
    unsigned int extra;
};
struct Tally
{
    int good;
    int bad;
};
struct Scanner
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
    Entry* head;
    bool CheckLinks();
    int Visit(Ref* ref);
};
struct PoolNode;
struct PoolNode
{
    PoolNode* m_00;
    PoolNode* m_04;

    PoolNode* hkgpMeshBase_Triangle_Triangle(void* value);
};
struct FreeCtx
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    int unk04F0;
    int unk04F4;
    int unk04F8;
    int unk04FC;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050C;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052C;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053C;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054C;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055C;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056C;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057C;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058C;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059C;
    int unk05A0;
    int unk05A4;
    int unk05A8;
    int unk05AC;
    int unk05B0;
    int unk05B4;
    int unk05B8;
    int unk05BC;
    int unk05C0;
    int unk05C4;
    int unk05C8;
    int unk05CC;
    int unk05D0;
    int unk05D4;
    int unk05D8;
    int unk05DC;
    int unk05E0;
    int unk05E4;
    int unk05E8;
    int unk05EC;
    int unk05F0;
    int unk05F4;
    int unk05F8;
    int unk05FC;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060C;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061C;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062C;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063C;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064C;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065C;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066C;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067C;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068C;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069C;
    int unk06A0;
    int unk06A4;
    int unk06A8;
    int unk06AC;
    int unk06B0;
    int unk06B4;
    int unk06B8;
    int unk06BC;
    int unk06C0;
    int unk06C4;
    int unk06C8;
    int unk06CC;
    int unk06D0;
    int unk06D4;
    int unk06D8;
    int unk06DC;
    int unk06E0;
    int unk06E4;
    int unk06E8;
    int unk06EC;
    int unk06F0;
    int unk06F4;
    int unk06F8;
    int unk06FC;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070C;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071C;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072C;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073C;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074C;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075C;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076C;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077C;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078C;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079C;
    int unk07A0;
    int unk07A4;
    int unk07A8;
    int unk07AC;
    int unk07B0;
    int unk07B4;
    int unk07B8;
    int unk07BC;
    int unk07C0;
    int unk07C4;
    int unk07C8;
    int unk07CC;
    int unk07D0;
    int unk07D4;
    int unk07D8;
    int unk07DC;
    int unk07E0;
    int unk07E4;
    int unk07E8;
    int unk07EC;
    int unk07F0;
    int unk07F4;
    int unk07F8;
    int unk07FC;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080C;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081C;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082C;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083C;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084C;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085C;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086C;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087C;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088C;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089C;
    int unk08A0;
    int unk08A4;
    int unk08A8;
    int unk08AC;
    int unk08B0;
    int unk08B4;
    int unk08B8;
    int unk08BC;
    int unk08C0;
    int unk08C4;
    int unk08C8;
    int unk08CC;
    int unk08D0;
    int unk08D4;
    int unk08D8;
    int unk08DC;
    int unk08E0;
    int unk08E4;
    int unk08E8;
    int unk08EC;
    int unk08F0;
    int unk08F4;
    int unk08F8;
    int unk08FC;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090C;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091C;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092C;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093C;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094C;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095C;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096C;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097C;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098C;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099C;
    int unk09A0;
    int unk09A4;
    int unk09A8;
    int unk09AC;
    int unk09B0;
    int unk09B4;
    int unk09B8;
    int unk09BC;
    int unk09C0;
    int unk09C4;
    int unk09C8;
    int unk09CC;
    int unk09D0;
    int unk09D4;
    int unk09D8;
    int unk09DC;
    int unk09E0;
    int unk09E4;
    int unk09E8;
    int unk09EC;
    int unk09F0;
    int unk09F4;
    int unk09F8;
    int unk09FC;
    PoolNode* m_a00;
    int m_a04;
};
struct Holder
{
    FreeCtx* m_00;
};
FreeCtx* __cdecl AllocateChainedSlotBlock(void);
class FUN_00e241a0_cls
{
  public:
    Holder* m_00;
    int m_04;
    int unk08;
    PoolNode* m_0c;
    int m_10;

    void UpdateFields_00e241a0(void* value);
};
struct FUN_00e247a0_cls
{
    unsigned char m_00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    char* m_04;
    unsigned int m_08;
    unsigned int m_0c;
    FUN_00e247a0_cls* hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_EdgeDataValue_EdgeDataValue();
};
extern "C" void _ReadWriteBarrier(void);
struct E24850Element
{
    E24850Element* m_next;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
struct E24850Block
{
    E24850Element m_elements[32];
    E24850Element* m_firstFree;
    int m_iAllocatedCount;

    void* allocate()
    {
        E24850Element* e = m_firstFree;
        m_firstFree = e->m_next;
        m_iAllocatedCount++;
        return e;
    }
};
struct E24850Node
{
    E24850Node* m_next;
    E24850Node* m_pSecondNode;

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
    E24850Node(void* data);
};
struct E24850List
{
    E24850Block** m_kBlocks;
    int m_iBlockCount;
    int m_blocksCapacity;
    E24850Node* m_pFirstNode;
    int m_iNodeCount;

    E24850Block* addBlock();
    E24850Node* hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_allocate(void* data);
};
// Text writer: format an integer into a scratch buffer and write it to the stream.
int __cdecl CC0280Format(char* pcBuffer, unsigned int uiSize, const char* pcFormat, ...);
class CC0280Stream
{
  public:
    virtual void Unk_00();
    virtual int Write(const void* pvData, int iSize);
};
static __declspec(noinline) void CC0280WriteString(CC0280Stream* pkStream, const char* pcText)
{
    int iLen = 0;
    while (pcText[iLen])
        iLen++;
    pkStream->Write(&iLen, 4);
    if (iLen > 0)
        pkStream->Write(pcText, iLen);
}
class CC0280Writer
{
  public:
    int unk00;
    int unk04;
    CC0280Stream* m_pDataStream;

    CC0280Writer& WriteInt(int iValue);
};
struct BSAudio;
namespace fnvc_adapt {
BSAudio* __cdecl hkMemoryRouter_getInstance();
}
struct FUN_00d9be30_cls
{
    int m_vptr;
    void UpdateState_00d9be30();
};
struct FUN_00d9c010_cls
{
    void ClearBuffers();
};
struct FUN_00e23860_cls
{
    void FreeAllBlocks();
};
extern int DAT_010eb000;
extern int DAT_010eaf50;
extern int DAT_0102e388;
extern int DAT_010d40a4;
struct FUN_00e18a50_cls
{
    int m_vptr00;
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
    int m_vptr40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAc;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBc;
    int m_data3;
    int m_cnt3;
    unsigned int m_cap3;
    int m_data2;
    int m_cnt2;
    unsigned int m_cap2;
    int m_data1;
    int m_cnt1;
    unsigned int m_cap1;

    void UpdateState_00e18a50();
    void ResetState();
};
// Havok ray/plane-triangle cast step: intersect the cast ray with the triangle's plane, test the hit point
// against the triangle, and keep the closest hit fraction.
extern __m128 DAT_010c7160;
// constant vector (zero)
extern float DAT_010c8440;
// point-in-triangle tolerance (-FLT_EPSILON)
static inline float ToReal(__m128 v)
{
    float f;
    _mm_store_ss(&f, v);
    return f;
}
struct __declspec(align(16)) Vec4f
{
    float v[4];
    __m128 Get() const
    {
        return _mm_load_ps(v);
    }
    void Set(__m128 q)
    {
        _mm_store_ps(v, q);
    }
};
struct TriVertex
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Vec4f m_vContactPosition;
};
struct CastTri
{
    int unk00;
    int unk04;
    TriVertex* m_kVertices[3];
    const Vec4f& GetVertex(int i) const
    {
        return m_kVertices[i]->m_vContactPosition;
    }
    int unk14;
    int unk18;
    int unk1c;
    Vec4f m_kTriangleNormal;
};
struct CastBody
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    CastTri* m_tri;
};
bool __cdecl hkGeometryProcessing_checkPointInsideTriangle(const Vec4f* pkPoint, const Vec4f& kA, const Vec4f& kB, const Vec4f& kC, float fTolerance);
static inline __m128 Dot3(__m128 a, __m128 b)
{
    const __m128 m = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m));
}
static inline __m128 Dot4xyz1(__m128 a, __m128 b)
{
    const __m128 m = _mm_mul_ps(a, b);
    const __m128 zw = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), _mm_shuffle_ps(a, a, 0xff));
    const __m128 xy = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    return _mm_add_ps(zw, xy);
}
struct TriRayCaster
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Vec4f m_kRayStart;
    Vec4f m_dir;
    CastTri* m_hitTri;
    float m_fHitDistance;
    float RayCastBody(CastBody* pkBody);
};
struct SceneVec
{
    float x;
    float y;
    float z;
    float w;
};
struct SceneBone
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    SceneVec m_10;
    __m128 m_20;
    __m128 m_30;
};
struct SceneSet
{
    unsigned int unk00;
    unsigned int unk04;
    SceneBone* m_08;
    SceneBone* m_0c;
    SceneBone* m_10;
};
void __cdecl hkAabbUtil_calcAabb_00cbeb70(void* v, int count, void* p);
typedef unsigned int BufferAddress138;
struct FUN_00e227f0_cls
{
    unsigned int unk00;
    SceneSet* m_04;
    void* ComputeValues_00e227f0(BufferAddress138 bufferAddress);
};
struct __declspec(align(16)) S_Vec
{
    float v[4];
};
struct S_00e11910_Src
{
    int unk00;
    int unk04;
    float* m_pVtxA;
    float* m_pVtxB;
    float* m_pVtxC;
    int unk14;
    int unk18;
    int unk1C;
    S_Vec m_vHitNormal;
};
struct S_00e11910_Cls
{
    char ValidateTriangleAndComputePlane(float* a, float* b, float* c, S_Vec* out, int normalize);
    char UpdateTriangleNormal(S_00e11910_Src* self);
};
struct E11B00Vertex
{
    E11B00Vertex* m_next;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4 m_vContactPosition;
};
struct E11B00Hull
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    E11B00Vertex* m_kVertices;

    void updateFaces();
    static void updateStatistics();
    void ScaleMeshVerticesAndUpdateStatistics(const hkVector4& scale);
};
struct S_00e12260_Aabb
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};
struct S_00e12260_CollectorBase
{
    int m_uiItemCount;
    S_00e12260_CollectorBase()
    {}
    virtual void AddHit(int hit);
};
struct S_00e12260_Collector : S_00e12260_CollectorBase
{
    hkVector4 m_verts[3];
    S_00e12260_Collector(const hkVector4& a, const hkVector4& b, const hkVector4& c)
    {
        m_uiItemCount = 0;
        m_verts[0] = a;
        m_verts[1] = b;
        m_verts[2] = c;
    }
    virtual void AddHit(int hit);
};
void hkAabbUtil_calcAabb_00cbeb70(const hkVector4* verts, int numVerts, S_00e12260_Aabb& aabbOut);
void AabbTree_ProcessIfPresent_00d1d570(void* tree, const S_00e12260_Aabb& aabb, S_00e12260_Collector* collector);
struct S_00e12260
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
    int CountTriangleTreeHits(const hkVector4& a, const hkVector4& b, const hkVector4& c);
};
struct S_00e13660_Res
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
    float m_40;
    unsigned char m_44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    S_00e13660_Res();
};
struct FUN_00e13660_cls
{
    void FindClosestMeshTriangle(unsigned int a1, S_00e13660_Res* out);
    float ProcessAndReturnValue_00e13660(unsigned int a1, __m128* out, bool* flag);
};
typedef unsigned int HullU32;
struct HullTriAN
{
    HullTriAN* m_next;
    HullTriAN* m_pSecondNode;
    void* m_kVertices[3];
    HullU32 m_ppLinks[3];
};
struct HullEdgeAN
{
    HullTriAN* m_pkTriangle;
    HullU32 m_uiEdgeIndex;
    __forceinline HullEdgeAN(HullU32 l)
    {
        m_uiEdgeIndex = l & 3u;
        m_pkTriangle = (HullTriAN*)(l & ~3u);
    }
    __forceinline bool isValid() const
    {
        return m_pkTriangle != 0;
    }
};
__forceinline void UnlinkAN(HullU32& link)
{
    HullU32 l = link;
    if (l & ~3u)
    {
        HullEdgeAN e(l);
        e.m_pkTriangle->m_ppLinks[e.m_uiEdgeIndex] = 0;
    }
    link = 0;
}
struct HullTriListAN
{
    int unk00;
    int unk04;
    int unk08;
    HullTriAN* m_uiBufferCapacity;
    int m_iAllocatedCount;
    void release(HullTriAN* t);
    __forceinline void remove(HullTriAN* t)
    {
        HullTriAN* n = t->m_next;
        HullTriAN* p = t->m_pSecondNode;
        if (n)
            n->m_pSecondNode = p;
        if (p)
            p->m_next = n;
        else
            m_uiBufferCapacity = n;
        m_iAllocatedCount--;
        release(t);
    }
};
struct HullImplAN
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    HullTriListAN m_uiTriangleCount;
    void RemoveTriangle(HullTriAN* t);
};
struct WeightedVertex
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    __m128 position;
};
struct VertexTriple
{
    unsigned int unk00;
    unsigned int unk04;
    WeightedVertex* first;
    WeightedVertex* second;
    WeightedVertex* third;
};
struct FUN_00e21ed0_Class
{
    unsigned int unk00;
    VertexTriple* vertices;
    void SelectDominantVertex(const __m128* direction, __m128* output);
};
static __forceinline __m128 Dot3(__m128 product)
{
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), xy);
}
static __forceinline float Scalar(__m128 value)
{
    float result;
    _mm_store_ss(&result, value);
    return result;
}
struct __declspec(align(16)) Float4
{
    float x;
    float y;
    float z;
    float w;
};
struct FUN_00e221e0_Vertex
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __declspec(align(16)) Vec4 unk10;
};
struct FUN_00e221e0_Triangle
{
    int unk00;
    int unk04;
    FUN_00e221e0_Vertex* unk08;
    FUN_00e221e0_Vertex* unk0C;
    FUN_00e221e0_Vertex* unk10;
};
struct FUN_00e221e0_Input
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    FUN_00e221e0_Triangle* unk20;
};
float __cdecl hkGeometryProcessing_squaredDistanceFromPointToTriangle(const Vec4* point, const Vec4* a, const Vec4* b, const Vec4* c, Float4* closest,
                           Float4* weights);
struct FUN_00e221e0_Collector
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __declspec(align(16)) Vec4 unk10;
    float unk20;
    int unk24;
    int unk28;
    int unk2C;
    __declspec(align(16)) Vec4 unk30;
    __declspec(align(16)) Vec4 unk40;
    FUN_00e221e0_Triangle* unk50;

    float UpdateClosestPoint(FUN_00e221e0_Input* input);
};
struct PoolItemAB
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
};
struct PoolBlockAB
{
    PoolItemAB m_items[32];
    int unka00;
    int m_iAllocatedCount;
};
struct BlockAllocAB
{
    virtual void v00();
    virtual void v04();
    __declspec(nothrow) virtual void ReleaseBlock(void* p, int size);
};
template <int SIZE> __forceinline void MemCpyOneAB(void* dst, const void* src)
{
    for (int i = 0; i < SIZE / 4; i++)
        ((unsigned int*)dst)[i] = ((const unsigned int*)src)[i];
}
template <class T> struct ArrAB
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            MemCpyOneAB<sizeof(T)>(m_data + index, m_data + m_iElementCount);
    }
};
struct FUN_00e22f90_cls
{
    ArrAB<PoolBlockAB*> m_kBlocks;
    void hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(PoolItemAB* item);
};
extern int DAT_010eade0;
struct FUN_00e121c0_probe
{
    int m_vptr;
    int unk04;
    int unk08;
    int unk0c;
    float m_v10x;
    float m_v10y;
    float m_v10z;
    float m_v10w;
    float m_v20x;
    float m_v20y;
    float m_v20z;
    float m_v20w;
    int m_i30;
    float m_f34;
};
void __cdecl hkVector4_VisitRayIntersectedTreeLeaves(void* owner, const void* a, const void* b, FUN_00e121c0_probe* out, float f);
struct FUN_00e121c0_cls
{
    float ProcessAndReturnValue_00e121c0(const __m128* a, const __m128* b, int* outI);
};
inline const S_00e13910_Edge& nullMeshEdge()
{
    static S_00e13910_Edge edge(0, 0);
    return edge;
}
struct TriangleNode
{
    TriangleNode* m_next;
    TriangleNode* m_pSecondNode;
};
struct TrianglePool
{
    int unk00;
    int unk04;
    int unk08;
    TriangleNode* m_pFirstNode;
    int m_uiItemCount;

    void hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(void* p);
    __forceinline void remove(TriangleNode* t)
    {
        TriangleNode* next = t->m_next;
        TriangleNode* prev = t->m_pSecondNode;
        if (next)
            next->m_pSecondNode = prev;
        if (prev)
            prev->m_next = next;
        else
            m_pFirstNode = next;
        m_uiItemCount--;
        hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(t);
    }
};
static __forceinline void bind(S_00e13910_Edge a, S_00e13910_Edge b)
{
    if (b.isValid())
    {
        S_00e13910_Edge temp = a;
        a = b;
        b = temp;
    }
    if (a.isValid())
    {
        a.bind(b);
    }
}
struct EdgeMesh
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    TrianglePool m_uiTriangleCount;

    bool UnbindEdgePair(S_00e13910_Edge a, S_00e13910_Edge b);
};
struct TriangleE15
{
    hkVector4 m_kVertices[3];
};
struct VertexE15
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4 m_vContactPosition;
};
struct TriangleEntryE15
{
    int unk00;
    int unk04;
    VertexE15* m_pkVertices[3];
};
void __cdecl CalcAabbE15(const hkVector4* pkPoints, int iNumPoints, hkAabb& kAabbOut);
int __cdecl TrianglesOverlapE15(const TriangleE15* pkA, const TriangleE15* pkB);
class AabbCollectorE15
{
  public:
    virtual void AddHit(TriangleEntryE15* pkEntry);
    hkArray<TriangleEntryE15*> m_kHits;
};
struct BroadPhaseE15
{
};
void __cdecl QueryAabbE15(BroadPhaseE15* pkBroadPhase, const hkAabb& kAabb, AabbCollectorE15* pkCollector);
class TriangleQueryE15
{
  public:
    void hkgpMesh_enumerateTriangleOverlaps(const hkVector4& kA, const hkVector4& kB, const hkVector4& kC,
                      hkArray<TriangleEntryE15*>* pkOverlapsOut) throw();
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
    BroadPhaseE15 m_kBroadPhase;
};
struct FUN_00e21d40_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    hkVector4 m_10;
    hkVector4 m_20;

    void hkgpMesh_LineShape_getSupportingVertex(const hkVector4* dir, hkVector4* out);
};
static float DotProduct3(__m128 a, __m128 b)
{
    __m128 p = _mm_mul_ps(a, b);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    s = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    float r;
    _mm_store_ss(&r, s);
    return r;
}
struct T27Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned int m_ppLinks[3];
};
struct T27Edge
{
    T27Node* m_node;
    unsigned int m_uiEdgeIndex;
};
inline T27Edge T27MakeEdge(unsigned int packed)
{
    T27Edge e;
    e.m_uiEdgeIndex = packed & 3;
    e.m_node = (T27Node*)(packed & 0xfffffffc);
    return e;
}
struct T27Slot
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void Assign(unsigned int value);
};
struct T27Item
{
    char m_enabled;
    char unk01;
    char unk02;
    char unk03;
    T27Slot m_data;
};
struct T27Cls
{
    unsigned int LookupPairResult(T27Edge* path);
    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_clearEdgeData(T27Edge* path);
    unsigned __int64 hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_backupBothEdgeData(T27Edge edge, T27Item* items);
};
struct S_00e11a90_Node
{
    S_00e11a90_Node* next;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4 vec;
};
struct S_00e11a90_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    S_00e11a90_Node* head;

    void ResetNodeVectors();
    void __thiscall ProcessEntries_00e11a90(int value);
};
__declspec(nothrow) void ReleaseSubobject();
struct S_00e12360_Vtx
{
    int unk00, unk04, unk08, unk0c;
    __m128 pos;
};
struct S_00e12360_Node
{
    S_00e12360_Node* next;
    S_00e12360_Node* prev;
    S_00e12360_Vtx* v0;
    S_00e12360_Vtx* v1;
    S_00e12360_Vtx* v2;
};
struct S_00e12360_Mesh
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28;
    S_00e12360_Node* head;
};
__forceinline float S_00e12360_Len(const S_00e12360_Node* n)
{
    __m128 a = n->v0->pos;
    __m128 e1 = _mm_sub_ps(n->v1->pos, a);
    __m128 e2 = _mm_sub_ps(n->v2->pos, a);
    __m128 c = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(e2, e2, 0xd2), _mm_shuffle_ps(e1, e1, 0xc9)),
                          _mm_mul_ps(_mm_shuffle_ps(e2, e2, 0xc9), _mm_shuffle_ps(e1, e1, 0xd2)));
    __m128 sq = _mm_mul_ps(c, c);
    __m128 d = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
    float r;
    _mm_store_ss(&r, _mm_sqrt_ss(d));
    return r;
}
struct S_00e12360_This : S_00e12360_Mesh
{
    void SortNodesByTriangleMagnitude(float scale);
};
struct HullFloodTriangle
{
    HullFloodTriangle* m_next;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_ppLinks[3];
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int m_vis;
};
inline void* operator new(unsigned int, void* storage)
{
    return storage;
}
struct HullFloodEdge
{
    HullFloodTriangle* m_node;
    int m_k;
    HullFloodEdge(HullFloodTriangle* node, int k) : m_node(node), m_k(k)
    {}
};
void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize);
struct HullFloodStack
{
    HullFloodEdge* m_data;
    int m_iElementCount;
    unsigned int m_cap;
    void release(Allocator& heap);
    void pushBack(const HullFloodEdge& edge);
};
inline void HullFloodStack::release(Allocator& heap)
{
    m_iElementCount = 0;
    if (!(m_cap & 0x80000000))
        heap.freeBlock(m_data, (m_cap & 0x3fffffff) * 8);
}
inline void HullFloodStack::pushBack(const HullFloodEdge& edge)
{
    hkMemoryRouter& mgr = hkMemoryRouter::getInstance();
    if (m_iElementCount == (int)(m_cap & 0x3fffffff))
        ResizeAudioStream(mgr.m_heap, this, sizeof(HullFloodEdge));
    ::new (static_cast<void*>(m_data + m_iElementCount)) HullFloodEdge(edge);
    m_iElementCount++;
}
struct HullConnectivity
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
    HullFloodTriangle* m_pFirstNode;
    int hkgpMesh_floodFillDetachedParts();
};
struct Vertex
{
    Vertex* m_next;
    Vertex* m_pSecondNode;
};
struct Triangle
{
    Triangle* m_next;
    unsigned int unk04;
    Vertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
};
static inline int nextIndex(int i)
{
    return (9 >> (i << 1)) & 3;
}
struct Edge
{
    Triangle* m_pkTriangle;
    int m_uiEdgeIndex;

    Edge(Triangle* triangle, int index) : m_pkTriangle(triangle), m_uiEdgeIndex(index)
    {}
    unsigned int uid() const
    {
        return (unsigned int)m_pkTriangle + m_uiEdgeIndex;
    }
    bool isNaked() const
    {
        return (m_pkTriangle->m_ppLinks[m_uiEdgeIndex] & ~3u) == 0;
    }
    Vertex* start() const
    {
        return m_pkTriangle->m_kVertices[m_uiEdgeIndex];
    }
    Vertex* end() const
    {
        return m_pkTriangle->m_kVertices[nextIndex(m_uiEdgeIndex)];
    }
    void bind(const Edge& other) const
    {
        m_pkTriangle->m_ppLinks[m_uiEdgeIndex] = other.uid();
        other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = uid();
    }
};
void __cdecl ResizeAudioStream(void*, void*, int);
struct VertexList
{
    int unk00;
    int unk04;
    int unk08;
    Vertex* m_pFirstNode;
    int m_uiItemCount;

    void hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(Vertex* vertex);
    void remove(Vertex* vertex)
    {
        Vertex* next = vertex->m_next;
        Vertex* prev = vertex->m_pSecondNode;
        if (next)
            next->m_pSecondNode = prev;
        if (prev)
            prev->m_next = next;
        else
            m_pFirstNode = next;
        --m_uiItemCount;
        hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(vertex);
    }
};
struct HullMesh
{
    int unk00;
    int unk04;
    VertexList m_kVertices;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    Triangle* m_uiTriangleCount;

    void hkgpMesh_replaceVertex(Vertex* from, Vertex* to);
};
extern const float DAT_0104a494;
extern float DAT_0106c2e0;
struct S_00e14160_Node
{
    S_00e14160_Node* m_next;
    int unk04;
    int unk08;
    int unk0c;
    hkVector4 m_pos;
};
struct S_00e14160_Tri
{
    S_00e14160_Tri* m_next;
    int unk04;
    S_00e14160_Node* m_kPointA;
    S_00e14160_Node* m_kPointB;
    S_00e14160_Node* m_iThirdValue;
};
struct S_00e14160
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S_00e14160_Node* m_kNodeCollection;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    S_00e14160_Tri* m_tris;

    float ProcessAndReturnValue_00e13660(const hkVector4& p, hkVector4* out, int flag);
    float AccumulateNodeDistancesToLimit(const hkVector4& dir, float limit);
};
static __forceinline __m128 S_dot3(__m128 a, __m128 b)
{
    __m128 t = _mm_mul_ps(a, b);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(t, t, 0x55), t);
    return _mm_add_ss(_mm_shuffle_ps(t, t, 0xaa), s);
}
struct E142Hull
{
    const hkVector4* hkgpConvexHull_getCenterOfMass();
};
void __cdecl Geometry_MapCoordinatesToSphere(const hkVector4* in, hkVector4* out);
static inline float E142ToReal(__m128 v)
{
    float f;
    _mm_store_ss(&f, v);
    return f;
}
struct E14a90Node
{
    E14a90Node* m_next;
    E14a90Node* m_pSecondNode;
    E14a90Node* m_v0;
    E14a90Node* m_v1;
    E14a90Node* m_v2;
    int uNewnk;
    int uTmpnk;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    float m_mark;
};
struct E14a90List
{
    int unk;
    int unkCur;
    int unkValue;
    E14a90Node* m_pFirstNode;
    int m_uiItemCount;

    void hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(E14a90Node* node);
    __forceinline void remove(E14a90Node* node)
    {
        E14a90Node* next = node->m_next;
        E14a90Node* prev = node->m_pSecondNode;
        if (next)
            next->m_pSecondNode = prev;
        if (prev)
            prev->m_next = next;
        else
            m_pFirstNode = next;
        m_uiItemCount--;
        hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(node);
    }
};
struct E14a90Owner
{
    int unk;
    int unkCur;
    E14a90List m_verts;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    E14a90Node* m_tris;

    void ReleaseSubobject();
    int hkgpMesh_removeOrphanVertices();
};
template <class T> __forceinline void SwapVertices(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
extern float DAT_01012054;
void __cdecl ResizeAudioStream(void* alloc, void* sizePtr, int elemSize) throw();
struct EdgeNode : S_00e13910_Triangle
{
    __m128 m_20;
    int m_30;
};
typedef S_00e13910_Edge PairItem;
struct PairArray
{
    PairItem* m_data;
    int m_iElementCount;
    int m_cap;
};
struct EdgeMeshFlip
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    EdgeNode* m_2c;
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    unsigned char unk100;
    unsigned char m_101;

    void hkgpMesh_bindEdgeList(PairArray* arr);
    void hkgpMesh_flipPartOrientation(int a1);
};
void __cdecl ResizeAudioStream(void* alloc, void* array, int elemSize);
template <class T> __forceinline void E153F0ConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
typedef hkArray<hkVector4> E153F0Points;
struct E153F0Vertex
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkVector4 m_vContactPosition;
};
struct E153F0Edge
{
    E122D0Face* m_face;
    int m_uiEdgeIndex;

    static int next(int i)
    {
        return (9 >> (i << 1)) & 3;
    }
    const hkVector4& start() const
    {
        return ((E153F0Vertex*)m_face->m_kVertices[m_uiEdgeIndex])->m_vContactPosition;
    }
    const hkVector4& end() const
    {
        return ((E153F0Vertex*)m_face->m_kVertices[next(m_uiEdgeIndex)])->m_vContactPosition;
    }
};
struct E153F0Edges
{
    E153F0Edge* m_data;
    int m_iElementCount;
};
struct E153F0Aabb
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};
float __cdecl getLoopSurfaceArea(const E153F0Edges* edges);
struct __declspec(align(16)) AabbE21F
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};
void __cdecl hkAabbUtil_calcAabb_00cbeb70(const hkVector4* pElementBuffer, int iNumPoints, AabbE21F& kAabbOut);
struct VertE21F
{
    int unk;
    int unkCur;
    int unkValue;
    int unk0c;
    hkVector4 m_pos;
};
struct TriE21F
{
    int unk;
    int unkCur;
    VertE21F* m_verts[3];
};
class FUN_00e21fc0_cls
{
  public:
    int unk;
    TriE21F* m_tri;

    AabbE21F hkgpMesh_TriangleShape_getBoundingBox() const;
};
struct FUN_00e226b0_cls
{
    unsigned int unk00;
    SceneSet* m_04;
    void FindSupportingBoneCandidate(SceneVec* v, SceneVec* out);
};
static __forceinline float SceneDot3(const SceneVec* a, const SceneVec* b)
{
    __m128 p = _mm_load_ps(&a->x);
    p = _mm_mul_ps(p, *(__m128*)b);
    __m128 yx = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    __m128 r = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), yx);
    float f;
    _mm_store_ss(&f, r);
    return f;
}
static __forceinline void SceneCopyBone(volatile SceneVec* dst, const SceneBone* b)
{
    *(volatile unsigned int*)&dst->x = *(const unsigned int*)&b->m_10.x;
    *(volatile unsigned int*)&dst->y = *(const unsigned int*)&b->m_10.y;
    *(volatile unsigned int*)&dst->z = *(const unsigned int*)&b->m_10.z;
    *(volatile unsigned int*)&dst->w = *(const unsigned int*)&b->m_10.w;
}
struct TriAreaGreater
{
    int unk00;
    static __forceinline __m128 area(const CastTri* t)
    {
        const Vec4f& a = t->GetVertex(0);
        const Vec4f& b = t->GetVertex(1);
        const Vec4f& c = t->GetVertex(2);
        const __m128 e1 = _mm_sub_ps(b.Get(), a.Get());
        const __m128 e2 = _mm_sub_ps(c.Get(), a.Get());
        const __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(e1, e1, 0xc9), _mm_shuffle_ps(e2, e2, 0xd2)),
                                        _mm_mul_ps(_mm_shuffle_ps(e2, e2, 0xc9), _mm_shuffle_ps(e1, e1, 0xd2)));
        return _mm_sqrt_ss(Dot3(cross, cross));
    }
    __forceinline bool operator()(const CastTri* a, const CastTri* b) const
    {
        return ToReal(area(a)) > ToReal(area(b));
    }
};
void __cdecl Hkgpmesh_SortTrianglePointerRange(CastTri** pArr, int d, int h, TriAreaGreater cmpLess);
struct MemAllocator
{
    virtual void v00();
    virtual void* Alloc(unsigned int size);
    virtual void v08();
    virtual void v0C();
    virtual void Free(void* p, unsigned int size);
};
// 12-byte slot; flags word: element count in low 30 bits, bit 31 = no buffer.
struct FUN_00e25ba0_Slot
{
    void* m_pData;
    int m_unk04;
    int m_flags;
};
struct FUN_00e25ba0_Table
{
    FUN_00e25ba0_Slot* m_pSlots;
    int m_uiItemCount;
    int m_cap;
    int m_unk0C;
};
extern "C" void __cdecl hkArrayUtil__reserve(MemAllocator* alloc, FUN_00e25ba0_Table* table, int newCap, int elemSize);
struct FUN_00e25ba0_cls
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    FUN_00e25ba0_Table* m_pTable;

    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_createEdgeDataHashTable();
};
struct HkV4
{
    __m128 m_vComponents;
};
struct HkVert
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    HkV4 m_vContactPosition;
};
struct __declspec(align(16)) Vec4F
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
};
struct __declspec(align(16)) Mat3Diffs
{
    Vec4F m_d0;
    Vec4F m_d1;
    Vec4F m_d2;
    __forceinline Mat3Diffs(__m128 a, __m128 b, __m128 c)
    {
        _mm_store_ps(&m_d0.m_uiX, a);
        _mm_store_ps(&m_d1.m_uiX, b);
        _mm_store_ps(&m_d2.m_uiX, c);
    }
    __m128* FUN_00cd51c0(Vec4F* out);
};
float __cdecl Hkgpmesh_ComputeValues_00e13870(char* self, unsigned int idx);
// FUN_00e144d0 : thiscall, float x, __m128* a, __m128* out, int count
// Clamped-distance accumulation with a dot3 weighted correction.
struct CollideShape
{
    double ProcessAndReturnValue_00e13660(__m128* out, const __m128* v, unsigned char* flag);
    float ProcessEntries_00e144d0(float x, __m128* a, __m128* out, int count);
};
struct __declspec(align(16)) Float4Bits
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    unsigned int w;
};
extern __m128 DAT_010c71d0;
extern const float DAT_01011d78;
void __cdecl ResizeAudioStream(void*, void*, int) throw();
struct __declspec(align(16)) CellVec
{
    float x, y, z, w;
    __m128& quad()
    {
        return reinterpret_cast<__m128&>(*this);
    }
    const __m128& quad() const
    {
        return reinterpret_cast<const __m128&>(*this);
    }
};
struct CellBounds
{
    CellVec min, max;
};
static __forceinline __m128 CellCorner(const float& x, const float& y, const float& z)
{
    return _mm_setr_ps(x, y, z, DAT_01011d78);
}
void __cdecl Hkgeometryprocessing_GetCubeBoundsFromLargestExtent(CellBounds*) throw();
struct BuildInput
{
    hkVector4* data;
    int count, stride;
};
struct BuildOptions
{
    int unk00, unk04, unk08, unk0c;
    BuildOptions* hkgpConvexHull_BuildConfig_BuildConfig() throw();
};
namespace CellBuild {
struct FUN_00d76ca0
{
    int vptr;
    unsigned short memorySize, referenceCount;
    int unk08, unk0c, unk10;
    FUN_00d76ca0() throw();
    ~FUN_00d76ca0() throw()
    {
        ReleaseStorage_00d76940();
    }
    void ReleaseStorage_00d76940() throw();
    int hkgpConvexHull_build_00d77200(const BuildInput&, const BuildOptions*) throw();
    bool hkgpConvexHull_isPointInside(const CellVec&, int, float) throw();
};
}
template <class T> static __forceinline void CellConstruct(T* p, int n, const T& value) throw()
{
    for (int i = 0; i < n; ++i)
        p[i].quad() = value.quad();
}
template <class T> struct CellArray
{
    T* data;
    int size, capacity;
    CellArray() throw() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline T& expand() throw()
    {
        hkMemoryRouter& router = hkMemoryRouter::get();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(router.m_heap, this, sizeof(T));
        return data[size++];
    }
    __forceinline void push(const T& value) throw()
    {
        hkMemoryRouter& router = hkMemoryRouter::get();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(router.m_heap, this, sizeof(T));
        T* p = data + size;
        if (p)
            new (p) T(value);
        ++size;
    }
    __forceinline void pushVector(const T& value) throw()
    {
        hkMemoryRouter& router = hkMemoryRouter::get();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(router.m_heap, this, sizeof(T));
        T* p = data + size;
        CellConstruct(p, 1, value);
        ++size;
    }
    __forceinline void release() throw()
    {
        Allocator& heap = reinterpret_cast<Allocator&>(hkMemoryRouter::get().getHeap());
        int cap = capacity;
        size = 0;
        if (!(cap & 0x80000000))
            heap.freeBlock(data, (cap & 0x3fffffff) * sizeof(T));
        data = 0;
        capacity = 0x80000000;
    }
};
struct CellMesh
{
    void hkgpMesh_fetchPositions(CellArray<hkVector4>&) throw();
    CellBounds ProcessEntries_00e11530() throw();
    float ProcessAndReturnValue_00e13660(const CellVec&, CellVec*, bool*) throw();
    void CollectPoints(int depthLimit, float scale, CellArray<CellVec>& output, bool invert);
};
struct FUN_00e21dd0_cls
{
    __m128 unk00;
    __m128 unk10;
    __m128 unk20;
    void hkgpMesh_LineShape_getBoundingBox(__m128* result);
};
extern float DAT_01016248;
struct FUN_00e21e60_pair
{
    __m128 m_v00;
    __m128 m_v10;
    unsigned int m_u20;
};
struct FUN_00e21e60_cls
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    __m128 m_v10;
    float m_f20;
    unsigned int m_u24;

    float hkgpMesh_WeldingPolicy_addLeaf(FUN_00e21e60_pair* p);
};
struct LocVertex
{
    int unk00;
    int unk04;
    int m_uiX;
    int m_uiY;
};
struct LocTriangle
{
    LocTriangle* m_next;
    LocTriangle* m_pSecondNode;
    LocVertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
};
struct LocEdge
{
    LocTriangle* m_pkTriangle;
    int m_uiEdgeIndex;
    LocEdge()
    {}
    LocEdge(const LocEdge& o)
    {
        m_pkTriangle = o.m_pkTriangle;
        m_uiEdgeIndex = o.m_uiEdgeIndex;
    }
    LocEdge(LocTriangle* t, int i) : m_pkTriangle(t), m_uiEdgeIndex(i)
    {}
    static int next(int i)
    {
        return (9 >> (i << 1)) & 3;
    }
    static int prev(int i)
    {
        return (18 >> (i << 1)) & 3;
    }
    LocEdge nextEdge() const
    {
        return LocEdge(m_pkTriangle, next(m_uiEdgeIndex));
    }
    LocEdge prevEdge() const
    {
        return LocEdge(m_pkTriangle, prev(m_uiEdgeIndex));
    }
    LocEdge link() const
    {
        const unsigned int l = m_pkTriangle->m_ppLinks[m_uiEdgeIndex];
        LocEdge e;
        e.m_uiEdgeIndex = l & 3;
        e.m_pkTriangle = (LocTriangle*)(l & ~3u);
        return e;
    }
    LocVertex* start() const
    {
        return m_pkTriangle->m_kVertices[m_uiEdgeIndex];
    }
    LocVertex* end() const
    {
        return m_pkTriangle->m_kVertices[next(m_uiEdgeIndex)];
    }
};
struct LocResult
{
    int m_type;
    LocEdge m_kEdge;
    LocResult()
    {}
    LocResult(int type, const LocEdge& e) : m_type(type), m_kEdge(e.m_pkTriangle, e.m_uiEdgeIndex)
    {}
};
static inline const LocEdge& invalidEdge()
{
    static LocEdge e(0, 0);
    return e;
}
static inline int orientation(const LocVertex* a, const LocVertex* b, int x, int y)
{
    const int ay = a->m_uiY, ax = a->m_uiX;
    return (b->m_uiX - ax) * (y - ay) - (b->m_uiY - ay) * (x - ax);
}
static inline int orientation(LocEdge e, int x, int y)
{
    return orientation(e.start(), e.end(), x, y);
}
struct LocTriangulator
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
    LocTriangle* m_pHeadNode;
    int m_maxIterations;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
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
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;

    LocTriangle* m_grid[256];
    LocResult LocatePoint(int x, int y);
};
#include <math.h>
extern __m128 DAT_010ec7f0;
static __m128 MeshSetAll(const float& f)
{
    __m128 a = _mm_load_ss(&f);
    return _mm_shuffle_ps(a, a, 0);
}
extern const float DAT_010141cc;
extern const float DAT_0104da4c = 1.1920928955078125e-7f;
struct EVec
{
    float x, y, z, w;
    const __m128& quad() const
    {
        return reinterpret_cast<const __m128&>(*this);
    }
    __m128 dot(const EVec& a) const
    {
        __m128 v = _mm_mul_ps(quad(), a.quad());
        return _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v));
    }
    char* FUN_00c7f520(char* out, float tolerance);
};
struct EVertex
{
    int unk00, unk04, unk08, unk0c;
    EVec position;
};
struct ELocalVec
{
    union
    {
        EVec scalar;
        __m128 simd;
    };
    ELocalVec(const EVec& v)
    {
        scalar = v;
    }
};
struct EFace
{
    EFace* next;
    int unk04;
    EVertex* vertices[3];
    unsigned int edges[3];
    EVec normal;
};
struct ENode
{
    ENode* next;
    int unk04, unk08, unk0c;
    EVec position, normal;
};
struct EParams
{
    float value, spacing, tolerance, offset, angle;
    unsigned char flag14, flag15, flag16, flag17;
    int filter;
};
struct EArray
{
    EVec* data;
    int size;
    unsigned int capacity;
};
struct EAppend
{
    EArray* owner;
    EVec* dest;
    EAppend(EArray* a) : owner(a), dest(a->data + a->size)
    {}
    ~EAppend()
    {
        ++owner->size;
    }
    operator EVec&()
    {
        return *dest;
    }
};
struct EMatrix
{
    EVec rows[3];
    __declspec(noalias) EVec* FUN_00cd51c0(EVec* out);
};
void __cdecl ResizeAudioStream(void*, void*, int);
struct EMesh
{
    int unk00, unk04, unk08, unk0c, unk10;
    ENode* nodes;
    int unk18, unk1c, unk20, unk24, unk28;
    EFace* faces;
    __declspec(noalias) float hkgpMesh_projectPointOnSurface(float value, EVec* point, int filter);
    void hkgpMesh_generateSurfaceSamples(EParams* p, EArray* out);
};
static __m128 load(const EVec& v)
{
    return _mm_load_ps(&v.x);
}
static void store(EVec& v, __m128 a)
{
    _mm_store_ps(&v.x, a);
}
static float sum3(__m128 p)
{
    __m128 y = _mm_shuffle_ps(p, p, 0x55);
    __m128 z = _mm_shuffle_ps(p, p, 0xaa);
    y = _mm_add_ss(y, p);
    z = _mm_add_ss(z, y);
    float r;
    _mm_store_ss(&r, z);
    return r;
}
struct S_00e21e30_Alloc
{
    virtual void unk0();
    virtual void unk4();
    virtual void ReleaseBlock(void* p, int n);
};
struct FUN_00e21e30
{
    int unk4;
    FUN_00e21e30();
// @fnv 0x00e21e30
    virtual ~FUN_00e21e30()
    {}
    void operator delete(void* p, unsigned int nbytes)
    {
        (*reinterpret_cast<S_00e21e30_Alloc*>(hkMemoryRouter::getInstance().m_heap)).ReleaseBlock(p, static_cast<int>(nbytes));
    }
};
FUN_00e21e30::FUN_00e21e30()
{}
extern "C" void __cdecl Deallocate(void*);
struct FUN_00e22500_cls
{
    int unk04;
    virtual ~FUN_00e22500_cls()
    {}

    FUN_00e22500_cls* FUN_00e22500(unsigned char acFlags);
};

// hkgpMesh::clone() (Havok 7.1.0-r1, hkInternal/hkgpMesh.obj), written in the SDK's shape:
typedef unsigned long S00e1c5e0_Ulong;
typedef S00e1c5e0_Ulong S00e1c5e0_Uid;

struct S00e1c5e0_EmptyBase
{
};

template <typename T, int N> struct S00e1c5e0_PoolAllocator
{
    struct Item
    {
        unsigned char m_data[sizeof(T)];
    };
    struct Pool
    {
        Item m_items[N];
        Item* m_free;
        int m_uiBufferCapacity;
    };
    struct PoolArray
    {
        Pool** m_data;
        int m_iElementCount;
        int m_iCapacityState;
        int GetLogicalSize() const
        {
            return m_iElementCount;
        }
        Pool*& operator[](int i)
        {
            return m_data[i];
        }
    };
    __forceinline T* allocate(const T& value)
    {
        return new (allocateItem()) T(value);
    }
    __forceinline Item* allocateItem()
    {
        Pool* pool = (m_pools.GetLogicalSize() && m_pools[0]->m_free) ? m_pools[0] : GetOrCreatePool();
        Item* item = pool->m_free;
        pool->m_free = *(Item**)item;
        ++pool->m_uiBufferCapacity;
        return item;
    }
    Pool* AllocateChainedSlotBlock();
    Pool* GetOrCreatePool()
    {
        return AllocateChainedSlotBlock();
    }
    PoolArray m_pools;
};

template <typename T, typename BASE> struct S00e1c5e0_List
{
    struct Item : BASE
    {
        __forceinline T* next() const
        {
            return m_next;
        }
        __forceinline T*& next()
        {
            return m_next;
        }
        __forceinline T* prev() const
        {
            return m_pSecondNode;
        }
        __forceinline T*& prev()
        {
            return m_pSecondNode;
        }
        Item() : BASE()
        {}

      protected:
        Item(const Item& other) : BASE(other)
        {}

      private:
        T* m_next;
        T* m_pSecondNode;
    };
    inline T* allocate(const T& value)
    {
        T* item = m_pThreadAllocator.allocate(value);
        item->prev() = 0;
        item->next() = m_uiBufferCapacity;
        if (m_uiBufferCapacity)
            m_uiBufferCapacity->prev() = item;
        m_uiBufferCapacity = item;
        m_iAllocatedCount++;
        return item;
    }
    __forceinline T* getFirst() const
    {
        return m_uiBufferCapacity;
    }
    S00e1c5e0_PoolAllocator<T, 32> m_pThreadAllocator;
    T* m_uiBufferCapacity;
    int m_iAllocatedCount;
    unsigned int m_uiUniqueId;
};


struct __declspec(align(16)) S00e1c5e0_Vec4
{
    int x, y, z, w;
};

struct S00e1c5e0_Vertex : S00e1c5e0_List<S00e1c5e0_Vertex, S00e1c5e0_EmptyBase>::Item
{
    S00e1c5e0_Vec4 m_vContactPosition;
    S00e1c5e0_Vec4 m_v20;
    S00e1c5e0_Vec4 m_v30;
    int m_i40;
    int m_i44;
};

struct S00e1c5e0_Triangle : S00e1c5e0_List<S00e1c5e0_Triangle, S00e1c5e0_EmptyBase>::Item
{
    __forceinline S00e1c5e0_Vertex*& vertex(int i)
    {
        return m_kVertices[i];
    }
    __forceinline S00e1c5e0_Uid& link(int i)
    {
        return m_ppLinks[i];
    }
    S00e1c5e0_Vertex* m_kVertices[3];
    S00e1c5e0_Uid m_ppLinks[3];
    S00e1c5e0_Vec4 m_kTriangleNormal;
    int m_i30, m_i34, m_i38, m_i3c, m_i40;
};

__forceinline S00e1c5e0_Ulong S00e1c5e0_uid2ulong(void* t, unsigned int i)
{
    return (*(const S00e1c5e0_Ulong*)&t) + (S00e1c5e0_Ulong)i;
}
template <typename T> __forceinline void S00e1c5e0_ulong2uid(S00e1c5e0_Ulong uid, T*& t, unsigned int& i)
{
    i = (unsigned int)(uid & 3);
    uid &= ~3;
    t = *(T**)&uid;
}

struct S00e1c5e0_Edge
{
    __forceinline static const S00e1c5e0_Edge& null()
    {
        if (!(DAT_0126ebf0 & 1))
        {
            DAT_0126ebf0 |= 1;
            new (&DAT_0126ebe8) S00e1c5e0_Edge(0, 0);
        }
        return *reinterpret_cast<const S00e1c5e0_Edge*>(&DAT_0126ebe8);
    }
    __forceinline S00e1c5e0_Edge(S00e1c5e0_Triangle* t, unsigned i) : m_pkTriangle(t), m_uiEdgeIndex(i)
    {}
    __forceinline S00e1c5e0_Edge(const S00e1c5e0_Uid& id)
    {
        S00e1c5e0_ulong2uid(id, m_pkTriangle, m_uiEdgeIndex);
    }
    __forceinline S00e1c5e0_Edge link() const
    {
        return S00e1c5e0_Edge(m_pkTriangle->link(m_uiEdgeIndex));
    }
    __forceinline S00e1c5e0_Uid uid() const
    {
        return S00e1c5e0_uid2ulong(m_pkTriangle, m_uiEdgeIndex);
    }
    __forceinline S00e1c5e0_Triangle* triangle() const
    {
        return m_pkTriangle;
    }
    __forceinline bool isValid() const
    {
        return triangle() != 0;
    }
    __forceinline bool isNaked() const
    {
        return !link().isValid();
    }
    __forceinline void bind(const S00e1c5e0_Edge& edge) const
    {
        m_pkTriangle->link(m_uiEdgeIndex) = edge.uid();
        if (edge.isValid())
            edge.m_pkTriangle->link(edge.m_uiEdgeIndex) = uid();
    }
    S00e1c5e0_Triangle* m_pkTriangle;
    unsigned int m_uiEdgeIndex;
};

struct S00e1c5e0_MapBase
{
    S00e1c5e0_MapBase() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~S00e1c5e0_MapBase()
    {
        Object_DoNothing();
    }
    void EnsureCapacity(Allocator* a, int numElements);
    int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(Allocator* a, S00e1c5e0_Ulong key, S00e1c5e0_Ulong val);
    S00e1c5e0_Ulong LookupHashEntry(S00e1c5e0_Ulong key, S00e1c5e0_Ulong def) const;
    int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(S00e1c5e0_Ulong key);
    void ProcessArgument(Allocator* a);
    void Object_DoNothing();
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};
struct S00e1c5e0_Map : S00e1c5e0_MapBase
{
    S00e1c5e0_Map(int nelem = 0)
    {
        EnsureCapacity(&reinterpret_cast<Allocator&>(hkMemoryRouter::getInstance().heap()), nelem);
    }
    ~S00e1c5e0_Map()
    {
        ProcessArgument(&reinterpret_cast<Allocator&>(hkMemoryRouter::getInstance().heap()));
    }
};
template <typename K, typename V> struct S00e1c5e0_PointerMap
{
    __forceinline int insert(K key, V val)
    {
        return m_map.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(&reinterpret_cast<Allocator&>(hkMemoryRouter::getInstance().heap()), S00e1c5e0_Ulong(key), S00e1c5e0_Ulong(val));
    }
    __forceinline V FindValueForKey(K key, V def) const
    {
        return (V)m_map.LookupHashEntry(S00e1c5e0_Ulong(key), S00e1c5e0_Ulong(def));
    }
    __forceinline int remove(K key)
    {
        return m_map.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(S00e1c5e0_Ulong(key));
    }
    S00e1c5e0_Map m_map;
};

struct S00e1c5e0_Mesh
{
    typedef S00e1c5e0_Vertex Vertex;
    typedef S00e1c5e0_Triangle Triangle;
    typedef S00e1c5e0_Edge Edge;
    int* vtable;
    unsigned short m_usMemSizeAndFlags, m_sReferenceCount;
    S00e1c5e0_List<Vertex, S00e1c5e0_EmptyBase> m_kVertices;
    S00e1c5e0_List<Triangle, S00e1c5e0_EmptyBase> m_uiTriangleCount;
    void* m_shared38;
    S00e1c5e0_Mesh* hkgpMesh_clone() const;
};

// @fnv 0x00e1c5e0
// src: HAVOK_LIB 0x00e1c5e0
S00e1c5e0_Mesh* S00e1c5e0_Mesh::hkgpMesh_clone() const
{
    void* memory = reinterpret_cast<Allocator&>(hkMemoryRouter::getInstance().heap()).allocate(0x110);
    static_cast<S00e1c5e0_Mesh*>(memory)->m_usMemSizeAndFlags = 0x110;
    S00e1c5e0_Mesh* m = reinterpret_cast<S00e1c5e0_Mesh*>(new (memory) FUN_00e1b750());
    S00e1c5e0_PointerMap<Vertex*, Vertex*> vmap;
    m->m_shared38 = m_shared38;
    for (Vertex* v = m_kVertices.getFirst(); v; v = v->next())
        vmap.insert(v, m->m_kVertices.allocate(*v));
    S00e1c5e0_PointerMap<S00e1c5e0_Ulong, S00e1c5e0_Ulong> emap;
    for (Triangle* t = m_uiTriangleCount.getFirst(); t; t = t->next())
    {
        Triangle* nt = m->m_uiTriangleCount.allocate(*t);
        for (int i = 0; i < 3; ++i)
            nt->vertex(i) = vmap.FindValueForKey(t->vertex(i), 0);
        for (int i = 0; i < 3; ++i)
        {
            Edge o(t, i);
            Edge n(nt, i);
            if (o.isNaked())
                n.bind(Edge::null());
            else
            {
                Edge l(emap.FindValueForKey(o.link().uid(), 0));
                if (l.isValid())
                {
                    n.bind(l);
                    emap.remove(o.uid());
                }
                else
                    emap.insert(o.uid(), n.uid());
            }
        }
    }
    return m;
}

namespace fnv_00e230f0 {
struct FlagByte
{
    char value;
    __forceinline FlagByte(bool b) : value(b)
    {}
    __forceinline operator bool() const
    {
        return value != 0;
    }
};
struct MapBase
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    MapBase() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~MapBase();
    class IteratorTag;
    typedef IteratorTag* Iterator;
    Iterator FindSlot(unsigned long key) const;
    int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(Allocator& a, unsigned long key, unsigned long val);
    void ProcessArgument(Allocator& a);
    void EnsureCapacity(Allocator& a, int minCap);
    FlagByte valid(Iterator it) const
    {
        return (int)it <= m_iPairCount;
    }
    FlagByte contains(unsigned long key) const
    {
        return valid(FindSlot(key));
    }
    int count() const
    {
        return m_iCapacityFlags & 0x7fffffff;
    }
};
struct LocalMap : MapBase
{
    LocalMap(int n = 0)
    {
        reserve(n);
    }
    ~LocalMap()
    {
        ProcessArgument(reinterpret_cast<Allocator&>(hkMemoryRouter::getInstance().heap()));
    }
    __forceinline void reserve(int n)
    {
        EnsureCapacity(reinterpret_cast<Allocator&>(hkMemoryRouter::getInstance().heap()), n);
    }
    __forceinline int insert(unsigned long key, unsigned long value)
    {
        return hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(reinterpret_cast<Allocator&>(hkMemoryRouter::getInstance().heap()), key, value);
    }
};
template <class T> struct PointerKeyMap
{
    LocalMap storage;
    PointerKeyMap()
    {}
    __forceinline FlagByte contains(T* key) const
    {
        return storage.contains((unsigned long)key);
    }
    __forceinline int insert(T* key, T* value)
    {
        return storage.insert((unsigned long)key, (unsigned long)value);
    }
    int count() const
    {
        return storage.count();
    }
};
struct TopoFace : S_00e13910_Triangle
{
    __forceinline void*& vertex(int i)
    {
        return m_kVertices[i];
    }
    __forceinline hkUint32& link(int i)
    {
        return m_ppLinks[i];
    }
};
struct TopoEdge;
template <class E, class T> struct EdgeCore
{
    T* m_pkTriangle;
    hkUint32 m_uiEdgeIndex;
    __forceinline EdgeCore()
    {}
    __forceinline EdgeCore(T* t, unsigned i) : m_pkTriangle(t), m_uiEdgeIndex(i)
    {}
    __forceinline EdgeCore(const hkUint32& packed)
    {
        unpack(packed, m_pkTriangle, m_uiEdgeIndex);
    }
    static __forceinline void unpack(hkUint32 packed, T*& tri, hkUint32& idx)
    {
        idx = packed & 3;
        packed &= ~3u;
        tri = (T*)packed;
    }
    __forceinline E next() const
    {
        return E(m_pkTriangle, (9 >> (m_uiEdgeIndex << 1)) & 3);
    }
    __forceinline E prev() const
    {
        return E(m_pkTriangle, (0x12 >> (m_uiEdgeIndex << 1)) & 3);
    }
    __forceinline E link() const
    {
        return E(m_pkTriangle->link(m_uiEdgeIndex));
    }
    __forceinline bool isValid() const
    {
        return m_pkTriangle != 0;
    }
    __forceinline T* triangle() const
    {
        return m_pkTriangle;
    }
    __forceinline void*& start() const
    {
        return m_pkTriangle->vertex(m_uiEdgeIndex);
    }
    __forceinline void*& end() const
    {
        return m_pkTriangle->vertex((9 >> (m_uiEdgeIndex << 1)) & 3);
    }
    __forceinline void*& apex() const
    {
        return m_pkTriangle->vertex((0x12 >> (m_uiEdgeIndex << 1)) & 3);
    }
};
struct TopoEdge : EdgeCore<TopoEdge, TopoFace>
{
    typedef EdgeCore<TopoEdge, TopoFace> Base;
    __forceinline TopoEdge(TopoFace* t, unsigned i) : Base(t, i)
    {}
    __forceinline TopoEdge(const hkUint32& packed) : Base(packed)
    {}
    __forceinline TopoEdge(const TopoEdge& other) : Base(other.m_pkTriangle, other.m_uiEdgeIndex)
    {}
};

struct VertexNode
{
    VertexNode* next;
};

struct MeshClass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    VertexNode* m_kVertices;
    int m_iStridedVertexCount;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    TopoFace* m_uiTriangleCount;

    __forceinline bool hasVertex(void* v) const
    {
        for (VertexNode* n = m_kVertices; n; n = n->next)
        {
            if (v == (void*)n)
                return true;
        }
        return false;
    }
    __forceinline bool hasTriangle(TopoFace* t) const
    {
        for (TopoFace* n = m_uiTriangleCount; n; n = (TopoFace*)n->m_unk00)
        {
            if (n == t)
                return true;
        }
        return false;
    }

    int hkgpAbstractMesh_struct_hkgpMeshBase_Edge_struct_hkgpMeshBase_Vertex_struct_hkgpMeshBase_Triangle_struct_hkContainerHeapAllocator_checkTopology(bool checkCount) const;
};

// @fnv 0x00e230f0
// src: HAVOK_LIB 0x00e230f0
int MeshClass::hkgpAbstractMesh_struct_hkgpMeshBase_Edge_struct_hkgpMeshBase_Vertex_struct_hkgpMeshBase_Triangle_struct_hkContainerHeapAllocator_checkTopology(bool checkCount) const
{
    PointerKeyMap<void> vertices;
    PointerKeyMap<TopoFace> triangles;

    for (TopoFace* tri = m_uiTriangleCount; tri; tri = (TopoFace*)tri->m_unk00)
    {
        for (int i = 0; i < 3; ++i)
        {
            TopoEdge edge(tri, i);
            TopoEdge link = edge.link();

            if (!vertices.contains(edge.start()))
            {
                bool found = false;
                void* v = edge.start();
                for (VertexNode* cursor = m_kVertices; cursor; cursor = cursor->next)
                {
                    if (v == (void*)cursor)
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    return 2;
                }
                vertices.insert(v, v);
            }

            if (edge.start() == edge.end())
            {
                return 7;
            }

            if (link.isValid())
            {
                if (tri == link.m_pkTriangle)
                {
                    return 6;
                }

                if (!triangles.contains(link.m_pkTriangle))
                {
                    bool found = false;
                    for (TopoFace* cursor = m_uiTriangleCount; cursor; cursor = (TopoFace*)cursor->m_unk00)
                    {
                        if (cursor == link.triangle())
                        {
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        return 3;
                    }
                    triangles.insert(link.m_pkTriangle, link.m_pkTriangle);
                }

                int ls = link.m_uiEdgeIndex << 1;
                if (edge.start() != link.m_pkTriangle->m_kVertices[(9 >> ls) & 3] || link.start() != edge.end())
                {
                    return 5;
                }

                if (edge.apex() == link.m_pkTriangle->m_kVertices[(0x12 >> ls) & 3])
                {
                    return 4;
                }
            }
        }
    }

    if (checkCount && vertices.count() != m_iStridedVertexCount)
    {
        return 1;
    }

    return 0;
}
}  // namespace fnv_00e230f0

extern "C" void _ReadWriteBarrier();
void ResizeAudioStream(void*, void*, int);
struct ProbeVertexBase
{
};
struct ProbeTriangleBase
{
};
template <class T, class Payload> struct ProbeList
{
    struct Item : Payload
    {
        __forceinline Item() : Payload()
        {}
        __forceinline Item(const Item& value) : Payload(value)
        {}

      private:
        T* next;
        T* previous;
    };
};
template <class V, class Payload> struct ProbeVertexCore : ProbeList<V, Payload>::Item
{
    static __forceinline bool isOrdered(const V* a, const V* b)
    {
        int order = a->compare(*b);
        if (order < 0)
            return true;
        if (order > 0)
            return false;
        return true;
    }
};
template <class T, class Payload, class V> struct ProbeTriangleCore : ProbeList<T, Payload>::Item
{
    typedef const V& Param;
    __forceinline void setVertices(Param a, Param b, Param c)
    {
        vertices[0] = a;
        vertices[1] = b;
        vertices[2] = c;
    }
    __forceinline V& vertex(int n)
    {
        return vertices[n];
    }
    __forceinline V vertex(int n) const
    {
        return vertices[n];
    }
    __forceinline unsigned long& link(int n)
    {
        return links[n];
    }
    __forceinline unsigned long link(int n) const
    {
        return links[n];
    }

  private:
    V vertices[3];
    unsigned long links[3];
};
struct ProbeVertex : ProbeVertexCore<ProbeVertex, ProbeVertexBase>
{
    int x, y;
    unsigned long constrained : 1;
    unsigned long data : 31;
    __forceinline int compare(const ProbeVertex& v) const
    {
        if (x < v.x)
            return -1;
        if (x > v.x)
            return 1;
        if (y < v.y)
            return -1;
        if (y > v.y)
            return 1;
        return 0;
    }
};
struct ProbeTriangle : ProbeTriangleCore<ProbeTriangle, ProbeTriangleBase, ProbeVertex*>
{
    unsigned short constraints : 3;
    unsigned short root : 1;
    unsigned short region : 12;
    unsigned short sets;
};

struct ProbeEdge;
template <class E, class V, class T> struct ProbeTopology
{
  protected:
    T* owner;
    unsigned number;

  public:
    __forceinline ProbeTopology()
    {}
    __forceinline ProbeTopology(T* p, unsigned i) : owner(p), number(i)
    {}
    __forceinline ProbeTopology(const unsigned long& packed)
    {
        unpack(packed, owner, number);
    }
    static __forceinline void unpack(unsigned long word, T*& p, unsigned& i)
    {
        i = word & 3;
        word &= ~3u;
        p = *(T**)&word;
    }
    static __forceinline unsigned long pack(void* p, unsigned i)
    {
        return *(const unsigned long*)&p + i;
    }
    static __forceinline unsigned after(unsigned i)
    {
        return (9 >> (i << 1)) & 3;
    }
    static __forceinline unsigned before(unsigned i)
    {
        return (18 >> (i << 1)) & 3;
    }
    static __forceinline const E& null()
    {
        static const E edge(0, 0);
        return edge;
    }
    __forceinline E next() const
    {
        return E(owner, after(number));
    }
    __forceinline E prev() const
    {
        return E(owner, before(number));
    }
    __forceinline E link() const
    {
        return E(owner->link(number));
    }
    __forceinline E prevCw() const
    {
        return prev().link();
    }
    __forceinline E prevCcw() const
    {
        return next().link();
    }
    __forceinline T* triangle() const
    {
        return owner;
    }
    __forceinline int index() const
    {
        return (int)number;
    }
    __forceinline V*& start() const
    {
        return owner->vertex(number);
    }
    __forceinline V*& end() const
    {
        return owner->vertex(after(number));
    }
    __forceinline V*& apex() const
    {
        return owner->vertex(before(number));
    }
    __forceinline bool isValid() const
    {
        return triangle() != 0;
    }
    __forceinline bool isNaked() const
    {
        return !link().isValid();
    }
    __forceinline bool isBound() const
    {
        return !isNaked();
    }
    __forceinline bool isMaster() const
    {
        return V::isOrdered(start(), end()) || isNaked();
    }
    __forceinline E master() const
    {
        if (isMaster())
            return E(owner, number);
        else
            return link();
    }
    __forceinline unsigned long uid() const
    {
        return pack(owner, number);
    }
    __forceinline void bind(const ProbeTopology& other) const
    {
        owner->link(number) = other.uid();
        if (other.isValid())
            other.owner->link(other.number) = uid();
    }
};
struct ProbeEdge : ProbeTopology<ProbeEdge, ProbeVertex, ProbeTriangle>
{
    typedef ProbeTopology<ProbeEdge, ProbeVertex, ProbeTriangle> Base;
    __forceinline ProbeEdge()
    {}
    __forceinline ProbeEdge(ProbeTriangle* p, unsigned i) : Base(p, i)
    {}
    __forceinline ProbeEdge(unsigned long value) : Base(value)
    {}
    __forceinline ProbeEdge(const ProbeEdge& e) : Base(e.owner, e.number)
    {}
    __forceinline void operator=(const ProbeEdge& e)
    {
        unsigned* out = reinterpret_cast<unsigned*>(this);
        const unsigned* in = reinterpret_cast<const unsigned*>(&e);
        out[0] = in[0];
        out[1] = in[1];
    }
    __forceinline bool isConstrained() const
    {
        const ProbeEdge e = master();
        return 0 != (e.triangle()->constraints & (1 << e.index()));
    }
    __forceinline void setConstrained() const
    {
        const ProbeEdge e = master();
        e.triangle()->constraints |= 1 << e.index();
    }
    __forceinline void clearConstrained() const
    {
        const ProbeEdge e = master();
        e.triangle()->constraints &= ~(1 << e.index());
    }
    __forceinline int takeConstraint() const
    {
        const int flag = isConstrained();
        if (flag)
            clearConstrained();
        return flag;
    }
};
enum ProbeRareStatus
{
    rSuccess = 0,
    rPresent = 1,
    rConstraint = 2
};
struct ProbeOutput
{
    int type;
    ProbeEdge edge;
    __forceinline ProbeOutput(int status, const ProbeEdge& e) : type(status), edge(e)
    {}
    __declspec(noinline) ProbeOutput(ProbeRareStatus status, const ProbeEdge& e) : type(status), edge(e)
    {}
};
struct ProbeLocation
{
    int type;
    ProbeEdge edge;
};
struct ProbeObjectTag
{
};
struct ProbePlacement
{
};
inline void* operator new(unsigned size, ProbePlacement* p)
{
    return p;
}
template <class T> static __forceinline void ProbeCopyRange(T* destination, int count, const T& source, ProbeObjectTag)
{
    for (int i = 0; i < count; ++i)
        ::new ((ProbePlacement*)(destination + i)) T(source);
}
struct ProbeHeapPolicy
{
    __forceinline Allocator& get(const void*) const
    {
        return reinterpret_cast<Allocator&>(hkMemoryRouter::getInstance().heap());
    }
};
template <class T> struct ProbeArrayBase
{
    T* data;
    int size, capacity;
    __forceinline ProbeArrayBase() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline ProbeArrayBase(T* p, int n, int limit) : data(p), size(n), capacity(limit | 0x80000000)
    {}
    __forceinline int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    __forceinline void append(Allocator& heap, const T& value)
    {
        if (size == getCapacity())
            ResizeAudioStream(&heap, this, sizeof(T));
        ProbeCopyRange(data + size, 1, value, ProbeObjectTag());
        ++size;
    }
    __forceinline void clear()
    {
        for (int i = 0; i < size; ++i)
            data[i].~T();
        size = 0;
    }
    __forceinline void dispose(Allocator& heap)
    {
        clear();
        if ((capacity & 0x80000000u) == 0)
            heap.freeBlock(data, getCapacity() * sizeof(T));
        data = 0;
        capacity = 0x80000000;
    }
};
template <class T> struct ProbeArrayOwned : ProbeArrayBase<T>
{
    __forceinline ProbeArrayOwned()
    {}
    __forceinline ProbeArrayOwned(T* p, int n, int cap) : ProbeArrayBase<T>(p, n, cap)
    {}
    __forceinline ~ProbeArrayOwned()
    {
        dispose(ProbeHeapPolicy().get(this));
    }
    __forceinline void pushBack(const T& value)
    {
        append(ProbeHeapPolicy().get(this), value);
    }
};
template <class T, int N> struct ProbeArray : ProbeArrayOwned<T>
{
    T storage[N];
    __forceinline ProbeArray() : ProbeArrayOwned<T>(storage, 0, N)
    {}
};

struct ProbeAttr
{
    bool present;
    ProbeArray<unsigned long, 4> tags;
    ProbeAttr() : present(false)
    {}
    ~ProbeAttr()
    {}
};
template <class T> struct ProbePool
{
    void* blocks;
    int size, capacity;
    T* head;
    int count;
    unsigned uid;
    void* rawAllocate();
    void attach(T*);
};
struct ProbeVPool : ProbePool<ProbeVertex>
{
// src: HAVOK_LIB 0x00e247c0
    __declspec(noinline) ProbeVertex* hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_allocate(const ProbeVertex& value)
    {
        ProbeVertex* p = (ProbeVertex*)rawAllocate();
        new (p) ProbeVertex(value);
        attach(p);
        return p;
    }
    __forceinline ProbeVertex* allocate(const ProbeVertex& value = ProbeVertex())
    {
        return hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_allocate(value);
    }
};
struct ProbeTPool : ProbePool<ProbeTriangle>
{
// src: HAVOK_LIB 0x00e24850
    __declspec(noinline) ProbeTriangle* hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_allocate(const ProbeTriangle& value)
    {
        ProbeTriangle* p = (ProbeTriangle*)rawAllocate();
        new (p) ProbeTriangle(value);
        attach(p);
        return p;
    }
    __forceinline ProbeTriangle* allocate(const ProbeTriangle& value = ProbeTriangle())
    {
        return hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_allocate(value);
    }
};
struct ProbeMesh
{
    int vptr;
    short size, refs;
    ProbeVPool vertices;
    ProbeTPool triangles;
};
struct ProbeThis
{
    int u00, u04;
    ProbeMesh mesh;
    ProbeArray<ProbeEdge, 64> queue;
    void* attributes;
    void* dataBlocks;
    int dataSize, dataCapacity;
    ProbeTriangle* roots[256];
    __forceinline static int rootIndex(int x, int y)
    {
        x >>= 11;
        y >>= 11;
        return (y << 4) + x;
    }
    __forceinline void setRoot(ProbeTriangle* t)
    {
        int x = (t->vertex(0)->x + t->vertex(1)->x + t->vertex(2)->x) / 3;
        int y = (t->vertex(0)->y + t->vertex(1)->y + t->vertex(2)->y) / 3;
        roots[rootIndex(x, y)] = t;
        t->root = 1;
    }
    __forceinline ProbeVertex* makeVertex(int x, int y, int flag)
    {
        ProbeVertex* p = mesh.vertices.allocate();
        p->x = x;
        p->y = y;
        p->constrained = flag;
        p->data = 0;
        p->data = ~p->data;
        return p;
    }
    __forceinline ProbeTriangle* makeTriangle(ProbeVertex* a, ProbeVertex* b, ProbeVertex* c)
    {
        ProbeTriangle* t = mesh.triangles.allocate();
        t->setVertices(a, b, c);
        t->constraints = 0;
        t->region = 0;
        t->root = 0;
        t->sets = 0;
        setRoot(t);
        return t;
    }
    __forceinline void copyData(ProbeTriangle* from, ProbeTriangle* to)
    {
        to->region = from->region;
        to->sets = from->sets;
    }
    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_backupBothEdgeData(ProbeEdge, ProbeAttr*);
    void ProcessItems(ProbeEdge, const ProbeAttr*);
    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_flushConform();
    ProbeEdge hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_locateExistingVertex(ProbeEdge, const ProbeVertex*) const;
    ProbeOutput hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_insertVertex(int x, int y, bool conform, const ProbeLocation& where, bool split);
};

// @fnv 0x00e27ea0
// src: HAVOK_LIB 0x00e27ea0
ProbeOutput ProbeThis::hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_insertVertex(int x, int y, bool conform, const ProbeLocation& where, bool split)
{
    ProbeEdge edge(where.edge);
    switch (where.type)
    {
    case 0: {
        ProbeVertex* added = makeVertex(x, y, true);
        const int cA = edge.next().takeConstraint();
        const int m_ucPackageByte = edge.prev().takeConstraint();
        ProbeTriangle* first = makeTriangle(edge.end(), edge.apex(), added);
        ProbeTriangle* second = makeTriangle(edge.apex(), edge.start(), added);
        edge.apex() = added;
        copyData(edge.triangle(), first);
        copyData(edge.triangle(), second);
        ProbeEdge(first, 0).bind(edge.prevCcw());
        ProbeEdge(second, 0).bind(edge.prevCw());
        ProbeEdge(first, 1).bind(ProbeEdge(second, 2));
        ProbeEdge(first, 2).bind(edge.next());
        ProbeEdge(second, 1).bind(edge.prev());
        if (cA)
            ProbeEdge(first, 0).setConstrained();
        if (m_ucPackageByte)
            ProbeEdge(second, 0).setConstrained();
        ProbeEdge result(first, 2);
        const ProbeVertex* addedVertex = result.start();
        if (conform)
        {
            queue.pushBack(ProbeEdge(first, 0));
            queue.pushBack(ProbeEdge(second, 0));
            queue.pushBack(edge);
            hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_flushConform();
            result = hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_locateExistingVertex(result, addedVertex);
        }
        return ProbeOutput(0, result);
    }
    case 1:
        if (split || !edge.isConstrained())
        {
            ProbeVertex* added = makeVertex(x, y, true);
            const int mainConstraint = edge.takeConstraint();
            ProbeAttr values[2];
            if (mainConstraint)
                hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_backupBothEdgeData(edge, values);
            if (edge.isBound())
            {
                ProbeEdge opposite = edge.link();
                const int cA = edge.prev().takeConstraint();
                const int m_ucPackageByte = opposite.prev().takeConstraint();
                ProbeTriangle* first = makeTriangle(edge.apex(), edge.start(), added);
                ProbeTriangle* second = makeTriangle(opposite.apex(), opposite.start(), added);
                copyData(edge.triangle(), first);
                copyData(opposite.triangle(), second);
                edge.start() = opposite.start() = added;
                ProbeEdge(first, 0).bind(edge.prevCw());
                ProbeEdge(second, 0).bind(opposite.prevCw());
                ProbeEdge(first, 1).bind(opposite);
                ProbeEdge(second, 1).bind(edge);
                ProbeEdge(first, 2).bind(edge.prev());
                ProbeEdge(second, 2).bind(opposite.prev());
                if (cA)
                    ProbeEdge(first, 0).setConstrained();
                if (m_ucPackageByte)
                    ProbeEdge(second, 0).setConstrained();
                if (split && mainConstraint)
                {
                    ProbeEdge(first, 1).setConstrained();
                    ProbeEdge(second, 1).setConstrained();
                    ProcessItems(ProbeEdge(first, 1), values);
                    ProcessItems(ProbeEdge(second, 1).link(), values);
                }
                if (conform)
                {
                    queue.pushBack(edge.next());
                    queue.pushBack(opposite.next());
                    queue.pushBack(ProbeEdge(first, 0));
                    queue.pushBack(ProbeEdge(second, 0));
                }
            }
            else
            {
                const int cA = edge.prev().takeConstraint();
                ProbeTriangle* first = makeTriangle(edge.apex(), edge.start(), added);
                copyData(edge.triangle(), first);
                edge.start() = added;
                ProbeEdge(first, 0).bind(edge.prevCw());
                ProbeEdge(first, 1).bind(ProbeEdge::null());
                ProbeEdge(first, 2).bind(edge.prev());
                if (cA)
                    ProbeEdge(first, 0).setConstrained();
                if (split && mainConstraint)
                {
                    ProbeEdge(first, 1).setConstrained();
                    ProbeEdge(first, 2).link().next().setConstrained();
                    ProcessItems(ProbeEdge(first, 1), values);
                    ProcessItems(ProbeEdge(first, 2).link().next(), values);
                }
                if (conform)
                {
                    queue.pushBack(edge.next());
                    queue.pushBack(ProbeEdge(first, 0));
                }
            }
            if (conform)
            {
                const ProbeVertex* addedVertex = edge.start();
                hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_flushConform();
                edge = hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_locateExistingVertex(edge, addedVertex);
            }
            return ProbeOutput(0, edge);
        }
        else
        {
            return ProbeOutput(ProbeRareStatus(2), edge);
        }
    case 2:
        if (!edge.start()->constrained)
        {
            edge.start()->constrained = true;
            return ProbeOutput(ProbeRareStatus(0), edge);
        }
        else
        {
            return ProbeOutput(ProbeRareStatus(1), edge);
        }
    default:
        break;
    }
    return ProbeOutput(10, ProbeEdge::null());
}
