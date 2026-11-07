#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkAabb.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkgpMesh_IConvexOverlap.h"


// src/havok/common/internal/geometryprocessing/mesh/hkgpmesh_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/internal/geometryprocessing/mesh/hkgpmesh.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
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
struct FUN_00e114c0_Class
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
    Subobject* unkE4;
    void ReleaseSubobject();
};
struct S_00e120e0_Shape
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual hkAabb GetData();
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
void __cdecl AabbTree_ProcessIfPresent_00d1d570(void* pWorld, const hkAabb& kData, S_00e120e0_Collector* pCollector);
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
__declspec(nothrow) hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();
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
        return allocate(reinterpret_cast<Allocator&>(hkMemoryRouter_getInstance().heap()), bytes);
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
struct S_00e25f00_Elem
{
    int unk0;
    int unk4;
    int unk8;
};
struct S_00e25f00
{
    hkArray<hkArray<S_00e25f00_Elem> > m_arrays;
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
// Exe 0x00e24e40: unit-local ListNode view; declarations and layout are preserved.
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
struct TriVertex
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkVector4 m_vContactPosition;
};
struct CastTri
{
    int unk00;
    int unk04;
    TriVertex* m_kVertices[3];
    const hkVector4& GetVertex(int i) const
    {
        return m_kVertices[i]->m_vContactPosition;
    }
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_kTriangleNormal;
};
struct CastBody
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    CastTri* m_tri;
};
bool __cdecl hkGeometryProcessing_checkPointInsideTriangle(const hkVector4* pkPoint, const hkVector4& kA, const hkVector4& kB, const hkVector4& kC, float fTolerance);
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
    hkVector4 m_kRayStart;
    hkVector4 m_dir;
    CastTri* m_hitTri;
    float m_fHitDistance;
    float RayCastBody(CastBody* pkBody);
};
struct SceneBone
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    hkVector4 m_10;
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
void hkAabbUtil_calcAabb_00cbeb70(const hkVector4* verts, int numVerts, hkAabb& aabbOut);
void AabbTree_ProcessIfPresent_00d1d570(void* tree, const hkAabb& aabb, S_00e12260_Collector* collector);
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
struct FUN_00e221e0_Vertex
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4 unk10;
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
float __cdecl hkGeometryProcessing_squaredDistanceFromPointToTriangle(const hkVector4* point, const hkVector4* a, const hkVector4* b, const hkVector4* c, hkVector4* closest,
                           hkVector4* weights);
struct FUN_00e221e0_Collector
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4 unk10;
    float unk20;
    int unk24;
    int unk28;
    int unk2C;
    hkVector4 unk30;
    hkVector4 unk40;
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
// The overlap array uses the Havok heap router (0x00c85750) and
// hkArrayUtil::_reserveMore (0x00c90940), as bound by hkgpmesh.cpp.
inline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return *reinterpret_cast<hkMemoryAllocator*>(hkMemoryRouter_getInstance().m_heap);
}

template <typename T>
__forceinline void hkArrayBase<T>::clear()
{
    for (int i = 0; i < m_iElementCount; ++i)
        m_data[i].~T();
    m_iElementCount = 0;
}

template <typename T>
__forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& heap)
{
    clear();
    if ((m_iCapacityState & 0x80000000) == 0)
        heap.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    _clearAndDeallocate(Allocator().get(this));
}

template <typename T>
__forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& heap, const T& item)
{
    if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        hkArrayUtil::_reserveMore(heap, this, sizeof(T));
    m_data[m_iElementCount] = item;
    m_iElementCount++;
}
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

extern const char str_010d365c[];
extern const char str_010d35f0[];

struct GpIntArrayLocalForm
{ // local form of hkArray: 0x00e24e40 needs the original constructor stores; shared base construction changes bytes.
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void _clearAndDeallocate(Allocator& a)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.freeBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(int));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void ClearAndRelease()
    {
        _clearAndDeallocate(reinterpret_cast<Allocator&>(hkMemoryRouter_getInstance().heap()));
    }
};

struct GpPoolItem
{
    GpIntArrayLocalForm m_ppData;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};

struct BlockAllocAB
{
    virtual void v00();
    virtual void v04();
    __declspec(nothrow) virtual void ReleaseBlock(void* p, int size);
};

struct GpPool
{
    GpPoolItem m_items[32];
    int unk380;
    int m_iAllocatedCount;

    static void operator delete(void* p, unsigned int size)
    {
        reinterpret_cast<BlockAllocAB*>(&hkMemoryRouter_getInstance().heap())->ReleaseBlock(p, size);
    }
};

struct GpPoolAllocator
{
    ArrAB<GpPool*> m_pools;

    void hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_32_struct_hkContainerHeapAllocator_release(GpPoolItem* item);
};

// @fnv 0x00e24e40
// src: HAVOK_LIB 0x00e24e40
void GpPoolAllocator::hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_32_struct_hkContainerHeapAllocator_release(GpPoolItem* item)
{
    if (item)
    {
        item->m_ppData.ClearAndRelease();
        for (int i = 0; i < m_pools.GetLogicalSize(); ++i)
        {
            if (item >= m_pools[i]->m_items && item <= m_pools[i]->m_items + 31)
            {
                if (--m_pools[i]->m_iAllocatedCount == 0)
                {
                    delete m_pools[i];
                    m_pools.removeAt(i);
                }
                return;
            }
        }
        char buf[512];
        CharBuffer ostr;
        ostr.FUN_00cb1600(buf, 0x200);
        ostr.ProcessAndReturnValue_00cc01c0(str_010d365c);
        if (DAT_01268360->Report(3, 0x90355365, buf, str_010d35f0, 0xaf))
            __debugbreak();
        ostr.FUN_00cc00e0();
    }
}
