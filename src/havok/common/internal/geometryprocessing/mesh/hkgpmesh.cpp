#include "../../../../../../include/hkArray.h"
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
// havok/common/internal/geometryprocessing/mesh/hkgpmesh.cpp: QhkVector4, BigSolver, BoundsMesh, TriangleChecker and more (160 functions)

#include "fnv_asm_helpers.h"
// Keep the compiler intrinsic representation used by this translation unit.
#ifndef _INCLUDED_MM2
#define _INCLUDED_MM2
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; } __m128, LocalM128;
extern "C" __m128 _mm_load_ps(const float* p);
extern "C" void _mm_store_ps(float* p, __m128 a);
extern "C" void _mm_store_ss(float* p, __m128 a);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_div_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sqrt_ss(__m128 a);
extern "C" __m128 _mm_load_ss(const float *p);
extern "C" __m128 _mm_set_ps1(float f);
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);
extern "C" __m128 _mm_set_ps(float, float, float, float);
extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_load_ss(const float* p);
extern "C" __m128 _mm_sub_ps(__m128,__m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" __m128 _mm_load_ps1(const float*);
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_setr_ps(float,float,float,float);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_rcp_ps(__m128);
static __m128 _mm_set1_ps(const float& f) { __m128 a = _mm_load_ss(&f); return _mm_shuffle_ps(a, a, 0); }
#endif

#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/BSAudio.h"
// local form of hkVector4: 0x00e16e50 needs original packed packet construction (shared extent 420 vs 439).


#if !defined(FNV_FOURFLOATVECTOR_NO_SSE)
#include <xmmintrin.h>
#else
union __m128;
#endif

class SimdReal;
class SimdScalar;
class ScalarValue;
class Transform;
class NiPoint3;

#pragma pack(push, 4)

class MeshPacketCallLocal_00e16e50
{
public:
#if defined(FNV_FOURFLOATVECTOR_NO_SSE)
    union Components
    {
        float m128_f32[4];
        unsigned __int64 m128_u64[2];
        signed char m128_i8[16];
        short m128_i16[8];
        int m128_i32[4];
        __int64 m128_i64[2];
        unsigned char m128_u8[16];
        unsigned short m128_u16[8];
        unsigned int m128_u32[4];
    };
#else
    typedef __declspec(align(4)) __m128 Components;
#endif

    union
    {
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
        Components m_vComponents;
        Components m;
        float f[4];
        Components values;
        Components q;
        Components value;
        Components quad;
        float elements[4];
        float m_fComponents[4];
    };

    MeshPacketCallLocal_00e16e50();
    MeshPacketCallLocal_00e16e50(float x, float y, float z, float w);
    MeshPacketCallLocal_00e16e50(const __m128& vector);

    MeshPacketCallLocal_00e16e50* hkVector4_hkVector4(float x, float y, float z, float w);
    void SetValue(MeshPacketCallLocal_00e16e50* vector);
    void __thiscall SetQuaternionComponentsFromVector(const MeshPacketCallLocal_00e16e50* vector);
    MeshPacketCallLocal_00e16e50& ComputeValue_00e531a0(int parameter);
    MeshPacketCallLocal_00e16e50 ProcessAndReturnValue_00e53260(int parameter);
    void normalize_005611c0();

    void operator=(const MeshPacketCallLocal_00e16e50& vector);
    float& operator()(int index);
    const float& operator()(int index) const;
    float& component(int index);
    float& At(int index);
    const float& At(int index) const;

    __m128 length3() const;
    float getW() const;
    ScalarValue Dot(const MeshPacketCallLocal_00e16e50& vector) const;
    ScalarValue LengthSq() const;
    ScalarValue Length() const;
    ScalarValue InverseLength() const;
    void Normalize();
    bool NormalizeNonzero();
    void Mul(const ScalarValue& scalar);
    void Add(const MeshPacketCallLocal_00e16e50& vector);
    void Sub(const MeshPacketCallLocal_00e16e50& vector);
    void Cross(const MeshPacketCallLocal_00e16e50& a, const MeshPacketCallLocal_00e16e50& b);

    void setAbs4(const MeshPacketCallLocal_00e16e50& vector);
    void setMul4(const SimdReal& scalar, const MeshPacketCallLocal_00e16e50& vector);
    void addMul4(const SimdReal& scalar, const MeshPacketCallLocal_00e16e50& vector);
    void setAddMul4(const MeshPacketCallLocal_00e16e50& a, const MeshPacketCallLocal_00e16e50& b, const SimdReal& scalar);
    SimdReal getSimdAt3() const;
    SimdReal lengthSquared3() const;
    void setXYZ_W(__m128 xyz, __m128 w);
    void setSqrtInverse4(const MeshPacketCallLocal_00e16e50& vector);
    void setAddMul(const MeshPacketCallLocal_00e16e50& a, const MeshPacketCallLocal_00e16e50& b, const SimdScalar& scalar);
    void addMul(const float& scalar, const MeshPacketCallLocal_00e16e50& vector);
    void transformed(const Transform& transform, const MeshPacketCallLocal_00e16e50& vector);
    void addScaled(const MeshPacketCallLocal_00e16e50& base, const MeshPacketCallLocal_00e16e50& direction, float amount);
    void* AddVector(void*, NiPoint3*, void*, float);
    void* AddVector(void*, void*);
    void* ScaleSwizzled();
};

#pragma pack(pop)

#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/Pair.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/Vec4.h"
#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkAabb.h"
#include "../../../../../../include/hkGeometry.h"
#include "../../../../../../include/hkMatrix4.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkgpMesh_IConvexOverlap.h"

inline __m128& Vec4::getQuad() { return *reinterpret_cast<__m128*>(this); }
inline const __m128& Vec4::getQuad() const { return *reinterpret_cast<const __m128*>(this); }
inline MeshPacketCallLocal_00e16e50::MeshPacketCallLocal_00e16e50() {}

__forceinline void hkVector4::SetAllComponents(float a) { q() = _mm_set_ps1(a); }
__forceinline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b) { q() = _mm_sub_ps(a.q(), b.q()); }
__forceinline void hkVector4::setAdd4(const hkVector4& a, const hkVector4& b) { q() = _mm_add_ps(a.q(), b.q()); }
__forceinline hkSimdReal hkVector4::dot3(const hkVector4& v) const
{
    __m128 prod = _mm_mul_ps(q(), v.q());
    return _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
}
inline void hkVector4::mul4(const hkVector4& other) { m_vComponents = _mm_mul_ps(m_vComponents, other.m_vComponents); }
inline __m128& hkVector4::q() { return m_vComponents; }
inline const __m128& hkVector4::q() const { return m_vComponents; }
inline hkVector4::hkVector4(const hkVector4& other) { m_vComponents = other.m_vComponents; }
inline void hkVector4::operator=(const hkVector4& other) { m_vComponents = other.m_vComponents; }
inline void hkVector4::set(float x, float y, float z, float w) { m_vComponents = _mm_setr_ps(x, y, z, w); }
inline float& hkVector4::operator()(int index) { return m_vComponents.m128_f32[index]; }
inline const float& hkVector4::operator()(int index) const { return m_vComponents.m128_f32[index]; }
inline float& hkMatrix4::operator()(int row, int column) { return (&m_kColumn0)[column](row); }
__forceinline hkSimdReal::hkSimdReal(const __m128& value) : m_vValue(value) {}
__forceinline hkSimdReal::operator float() const { float result; _mm_store_ss(&result, m_vValue); return result; }
inline hkAabb::hkAabb() {}
inline Pair::Pair() throw() {}
inline Pair::Pair(int aa, int bb) : a(aa), b(bb) {}
inline void* Pair::operator new(unsigned int, void* p) throw() { return p; }

// SSE_DECLARATIONS_DEFER_TO_SDK
// src/havok/common/internal/geometryprocessing/mesh/hkgpmesh.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/geometryprocessing/mesh/hkgpmesh.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00e12140_cls {
    void hkgpMesh_setPartIdsAsPlaneIndices();
};

// @fnv 0x00e12140
// src: HAVOK_LIB 0x00e12140
void FUN_00e12140_cls::hkgpMesh_setPartIdsAsPlaneIndices()
{
    if (*(int*)((char*)this + 0xd0) != 0 && *(int*)((char*)this + 0x2c) != 0) {
        int* p = *(int**)((char*)this + 0x2c);
        while (p) {
            *(int*)((char*)p + 0x30) = *(int*)((char*)p + 0x34);
            p = *(int**)((char*)p);
        }
    }
}

extern "C" void __cdecl Deallocate(void*);
extern int DAT_010eadfc;

struct FUN_00e22450 {
    void* m_p;
    FUN_00e22450(char f);
};

// Constructor that sets m_p to DAT_010eadfc and, if bit 0 of f is set, calls Deallocate on this.
// @fnv 0x00e22450
FUN_00e22450::FUN_00e22450(char acFlags)
{
    m_p = &DAT_010eadfc;
    if (acFlags & 1)
        Deallocate(this);
}

struct FUN_00e234e0_ { void FreeAllItems(); };
struct FUN_00e238e0_ {
    void ProcessState_00e238e0();
};
// @fnv 0x00e238e0
// src: GUESS 0x00e238e0 (confidence: low)
void FUN_00e238e0_::ProcessState_00e238e0()
{
    ((FUN_00e234e0_*)((char*)this + 8))->FreeAllItems();
    ((FUN_00e234e0_*)((char*)this + 0x20))->FreeAllItems();
}

void __cdecl ProcessEntries();
void __cdecl hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_reset();

struct FUN_00e24a80_Class {
    void __thiscall hkgpAbstractMesh_hkgpTriangulatorType_hkgpTriangulatorBase_VertexBase_hkgpTriangulatorBase_TriangleBase_hkgpTriangulatorBase_DefaultEdgeData_hkContainerHeapAllocator_hkContainerHeapAllocator_1_Edge_hkgpTriangulatorType_hkgpTriangulatorBase_VertexBase_hkgpTriangulatorBase_TriangleBase_hkgpTriangulatorBase_DefaultEdgeData_hkContainerHeapAllocator_hkContainerHeapAllocator_1_Vertex_hkgpTriangulatorType_hkgpTriangulatorBase_VertexBase_hkgpTriangulatorBase_TriangleBase_hkgpTriangulatorBase_();
};

// @fnv 0x00e24a80
// src: COMMUNITY 0x00e24a80
void __thiscall FUN_00e24a80_Class::hkgpAbstractMesh_hkgpTriangulatorType_hkgpTriangulatorBase_VertexBase_hkgpTriangulatorBase_TriangleBase_hkgpTriangulatorBase_DefaultEdgeData_hkContainerHeapAllocator_hkContainerHeapAllocator_1_Edge_hkgpTriangulatorType_hkgpTriangulatorBase_VertexBase_hkgpTriangulatorBase_TriangleBase_hkgpTriangulatorBase_DefaultEdgeData_hkContainerHeapAllocator_hkContainerHeapAllocator_1_Vertex_hkgpTriangulatorType_hkgpTriangulatorBase_VertexBase_hkgpTriangulatorBase_TriangleBase_hkgpTriangulatorBase_()
{
    ((void (__thiscall *)(void*))ProcessEntries)(this + 8);
    ((void (__thiscall *)(void*))hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_reset)(this + 0x20);
}

struct Subobject { virtual void Release(unsigned int flags); };
struct FUN_00e114c0_Class {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC;
    int unkC0; int unkC4; int unkC8; int unkCC; int unkD0; int unkD4; int unkD8; int unkDC;
    int unkE0; Subobject* unkE4;
    void ReleaseSubobject();
};
// Releases the subobject held in unkE4 with flag 1 if present, then clears the pointer.
// @fnv 0x00e114c0
void FUN_00e114c0_Class::ReleaseSubobject() {
    if (unkE4)
        unkE4->Release(1);
    unkE4 = 0;
}

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
        { m_fValue = fValue; m_iFilter = iFilter; m_bHit = false; m_pShape = pShape; m_bFlag = bFlag; }
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
// @fnv 0x00e120e0
bool S_00e120e0::TestShapeHit(S_00e120e0_Shape* pShape, float fValue, bool bFlag)
{
    S_00e120e0_Collector kCollector(fValue, unk38, pShape, bFlag);
    AabbTree_ProcessIfPresent_00d1d570(&unk40, pShape->GetData(), &kCollector);
    return kCollector.m_bHit;
}

struct E122D0Face {
    E122D0Face* m_next;
    int unk04;
    int m_kVertices[3];
};

struct E122D0Edge {
    E122D0Face* m_face;
    int m_uiEdgeIndex;

    E122D0Edge() {}
    E122D0Edge(E122D0Face* face, int index) : m_face(face), m_uiEdgeIndex(index) {}
};

struct E122D0Mesh {
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

// @fnv 0x00e122d0
E122D0Edge E122D0Mesh::FindEdge(int vertexA, int vertexB)
{
    for (E122D0Face* face = m_faces; face; face = face->m_next) {
        for (int prev = 2, i = 0; i < 3; prev = i++) {
            if (face->m_kVertices[prev] == vertexA && face->m_kVertices[i] == vertexB)
                return E122D0Edge(face, prev);
        }
    }
    static const E122D0Edge s_nullEdge(0, 0);
    return s_nullEdge;
}

struct Allocator { virtual void v00(); virtual void* allocate(int); virtual void v08(); virtual void v0c(); __declspec(nothrow) virtual void freeBlock(void*,int); };

inline Allocator& meshHeap(hkMemoryRouter& router) { return *reinterpret_cast<Allocator*>(router.m_heap); }
__declspec(nothrow) hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

struct VectorArray {MeshPacketCallLocal_00e16e50* data; int size; int capacity;
 VectorArray():data(0),size(0),capacity(0x80000000) {}
 void release(Allocator& heap) {size=0; if(!(capacity&0x80000000)) heap.freeBlock(data,(capacity&0x3fffffff)*16);}
 
};
struct Options {unsigned int unk00,unk04; unsigned char flag08,flag09,flag0a,flag0b; unsigned int unk0c; __declspec(nothrow) void hkgpConvexHull_BuildConfig_BuildConfig();};
struct FUN_00d76ca0 {__declspec(nothrow) virtual ~FUN_00d76ca0(); unsigned short memorySize,referenceCount; int unk08,unk0c,unk10;
 __declspec(nothrow) FUN_00d76ca0();
 static void* allocate(Allocator& heap,unsigned int bytes) { void* memory=heap.allocate(bytes); ((FUN_00d76ca0*)memory)->memorySize=(unsigned short)bytes; return memory;}
 static void* operator new(unsigned int bytes) {return allocate(meshHeap(hkMemoryRouter_getInstance()),bytes);}
 __declspec(nothrow) void hkgpConvexHull_build(MeshPacketCallLocal_00e16e50*,int,const Options&);
 __declspec(nothrow) int GetInnerField1A8();
};
struct Hull {
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
// Calls ReleaseSubobject, then if count>3 builds a FUN_00d76ca0 from the vertices with options flag09=0/flag0a=1, returning false if FUN_00d74e10()!=3.
// @fnv 0x00e13750
bool Hull::BuildHull() {
 ReleaseSubobject();
 if(count>3) {
  Options options; options.hkgpConvexHull_BuildConfig_BuildConfig(); options.flag09=0; options.flag0a=1;
  builder=new FUN_00d76ca0;
  VectorArray vertices;
  hkgpMesh_fetchPositions(vertices);
  builder->hkgpConvexHull_build(vertices.data,vertices.size,options);
  if(builder->GetInnerField1A8()!=3) {
   delete builder;
   builder=0;
   vertices.release(meshHeap(hkMemoryRouter_getInstance()));
   return false;
  }
  vertices.release(meshHeap(hkMemoryRouter_getInstance()));
 }
 return true;
}

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

// Calls FUN_00e230f0(1); if report is set and an error is returned, builds a message and reports it via DAT_01268360, returning whether the error is zero.
// @fnv 0x00e14b30
bool __stdcall CheckError(bool report)
{
    int error = hkgpAbstractMesh_struct_hkgpMeshBase_Edge_struct_hkgpMeshBase_Vertex_struct_hkgpMeshBase_Triangle_struct_hkContainerHeapAllocator_checkTopology(1);
    if (report && error)
    {
        CharBuffer message;
        unsigned int storage[128];
        char* text = reinterpret_cast<char*>(storage);
        message.FUN_00cb1600(text, 512);
        message.ProcessAndReturnValue_00cc01c0(DAT_010eaf08)->WriteInt(error)->ProcessAndReturnValue_00cc01c0(DAT_0103d078);
        if (DAT_01268360->Report(3, 0x4c5c2afa, text, DAT_010eaeb4, 0xb29))
            __debugbreak();
        message.FUN_00cc00e0();
    }
    return error == 0;
}

struct FUN_00e14fe0_node {
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

struct FUN_00e14fe0_cls {
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

// @fnv 0x00e14fe0
// src: HAVOK_LIB 0x00e14fe0
void FUN_00e14fe0_cls::hkgpMesh_removePlaneTriangles(void* apKey)
{
    FUN_00e14fe0_node* p = m_pHead2c;
    while (p) {
        FUN_00e14fe0_node* pNext = p->m_pNext;
        if (p->m_pKey34 == apKey)
            RemoveTriangle(p);
        p = pNext;
    }
    m_b101 = 0;
}

extern int DAT_01268370;

struct ArrayHeader {
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ArrayHeader() throw()
        : m_pData(0), m_iArrayLength(0), m_uCapacity(0x80000000)
    {
    }
};

struct ArrayPair {
    ArrayHeader m_kFirst;
    ArrayHeader m_kSecond;

    ~ArrayPair() throw();
};

struct Builder {
    void hkgpConvexHull_generateGeometry(int aiFlag, ArrayPair* apPair) throw();
};

struct FUN_00e1d900_cls {
    void hkgpMesh_appendFromGeometry(ArrayPair* apPair, int* apGlobal, int aiValue) throw();
    void hkgpMesh_appendFromConvexHull(Builder* apBuilder);
};

// @fnv 0x00e1d900
// src: HAVOK_LIB 0x00e1d900
void FUN_00e1d900_cls::hkgpMesh_appendFromConvexHull(Builder* apBuilder)
{
    ArrayPair kPair;
    apBuilder->hkgpConvexHull_generateGeometry(0, &kPair);
    hkgpMesh_appendFromGeometry(&kPair, &DAT_01268370, -1);
}

struct QueryObject { virtual void First(); virtual float Evaluate(int first, int second, int mode); int IsBelowThreshold(int first, int second, float threshold); };
// Returns whether Evaluate(first, second, 1) is less than or equal to threshold.
// @fnv 0x00e224d0
int QueryObject::IsBelowThreshold(int first, int second, float threshold) {
    return Evaluate(first, second, 1) <= threshold;
}

namespace fnv_00e22520 {
struct hkErrStreamE {
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    void Init(void* buf, int size);
    hkErrStreamE& Put(const char* s);
    void Finish();
};
struct hkErrorE {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int message(int type, int id, const char* desc, const char* file, int line);
};
extern hkErrorE* DAT_01268360;
extern const char s_10eae6c[];
extern const char s_10eae18[];

// @fnv 0x00e22520
// src: HAVOK_LIB 0x00e22520
void __stdcall hkGskShape_convertVertexIdsToVertices(int a, int b, int c)
{
    hkErrStreamE os;
    int buf[0x80];
    os.Init(buf, 0x200);
    os.Put(s_10eae6c);
    if (DAT_01268360->message(3, 0x50cc4da8, (const char*)buf, s_10eae18, 0x2c))
        __debugbreak();
    os.Finish();
}
}  // namespace fnv_00e22520

struct S_00e22580_Item {
    int unk0; int unk4; int unk8; int unkC; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38;
    float m_3c;
};
struct S_00e22580_Tri {
    int unk0;
    int unk4;
    S_00e22580_Item* m_items[3];
};
struct S_00e22580_Obj {
    int unk0; int unk4; int unk8; int unkC; int unk10; int unk14; int unk18; int unk1C;
    S_00e22580_Tri* m_20;
};
struct S_00e22580_Wrap {
    S_00e22580_Tri* m_tri;
    S_00e22580_Wrap(S_00e22580_Tri* t) : m_tri(t) {}
    virtual void Dummy();
};
struct S_00e22580_Tester {
    virtual void v0();
    virtual void v1();
    virtual bool Test(S_00e22580_Wrap* a, S_00e22580_Wrap* b, float f);
};
struct S_00e22580_Self {
    int unk0;
    int m_iWordAt04;
    int m_8;
    S_00e22580_Tester* m_iThirdValue;
    bool TrianglesShareItem(S_00e22580_Obj* a, S_00e22580_Obj* b);
};

// @fnv 0x00e22580
bool S_00e22580_Self::TrianglesShareItem(S_00e22580_Obj* a, S_00e22580_Obj* b)
{
    S_00e22580_Tri* p = a->m_20;
    S_00e22580_Tri* q = b->m_20;
    m_iWordAt04++;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (p->m_items[i] == q->m_items[j])
                return true;
        }
    }
    m_8++;
    S_00e22580_Wrap wrapA(p);
    S_00e22580_Wrap wrapB(q);
    if (m_iThirdValue->Test(&wrapA, &wrapB, 0.0f)) {
        for (int i = 0; i < 3; i++) {
            S_00e22580_Item* pa = p->m_items[i];
            S_00e22580_Item* pItemB = q->m_items[i];
            pa->m_3c = 0.0f;
            pItemB->m_3c = 0.0f;
        }
    }
    return false;
}

struct DataBlock {
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

// Copies the fourteen int fields m_i10 through m_i44 from arSource into this block and returns *this.
// @fnv 0x00e22ec0
// src: HAVOK_LIB 0x00e22ec0
DataBlock& DataBlock::hkgpMeshBase_Vertex_Vertex(const DataBlock& arSource)
{
    m_i10 = arSource.m_i10;
    m_i14 = arSource.m_i14;
    m_i18 = arSource.m_i18;
    m_i1c = arSource.m_i1c;
    m_i20 = arSource.m_i20;
    m_i24 = arSource.m_i24;
    m_i28 = arSource.m_i28;
    m_i2c = arSource.m_i2c;
    m_i30 = arSource.m_i30;
    m_i34 = arSource.m_i34;
    m_i38 = arSource.m_i38;
    m_i3c = arSource.m_i3c;
    m_i40 = arSource.m_i40;
    m_i44 = arSource.m_i44;
    return *this;
}

struct StateBlock {
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

// @fnv 0x00e23080
// src: HAVOK_LIB 0x00e23080
StateBlock& StateBlock::hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_Triangle(const StateBlock& arSource)
{
    m_i08 = arSource.m_i08;
    m_i0c = arSource.m_i0c;
    m_i10 = arSource.m_i10;
    m_i14 = arSource.m_i14;
    m_i18 = arSource.m_i18;
    m_i1c = arSource.m_i1c;
    m_uMode = arSource.m_uMode;
    m_bFlag = arSource.m_bFlag;
    m_uItemCount = arSource.m_uItemCount;
    m_u22 = arSource.m_u22;
    return *this;
}

namespace fnv_00e234e0 {




hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct FUN_00e234e0_cls {
    void** m_ppItems;
    int m_iArrayLength;
    int unk08;
    int m_i0c;
    int m_i10;
    void FreeAllItems();
};

// @fnv 0x00e234e0
void FUN_00e234e0_cls::FreeAllItems()
{
    for (int i = 0; i < m_iArrayLength; i++) {
        void* pItem = m_ppItems[i];
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(pItem, 0xa08);
    }
    m_iArrayLength = 0;
    m_i0c = 0;
    m_i10 = 0;
}
}  // namespace fnv_00e234e0

namespace fnv_00e23670 {


hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(hkMemoryAllocator* alloc, void* arr, int elemSize);

struct S_e23670_Elem {
    S_e23670_Elem* m_next;
    int unk4; int unk8; int unkC; int unk10;
};
struct S_e23670_Block {
    S_e23670_Elem m_pElements[32];
    S_e23670_Elem* m_free;
    int m_iAllocatedCount;
};
struct S_e23670 {
    S_e23670_Block** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_e23670_Block* hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_allocateNewPool();
};

// Allocates a block from the heap, links its 32 elements into a free list, grows m_data if full, stores the block and swaps it with the first slot.
// @fnv 0x00e23670
// src: HAVOK_LIB 0x00e23670
S_e23670_Block* S_e23670::hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_allocateNewPool()
{
    hkMemoryAllocator& heap = hkMemoryRouter_getInstance()->heap();
    S_e23670_Elem* next = 0;
    S_e23670_Block* b = (S_e23670_Block*)heap.blockAlloc(sizeof(S_e23670_Block));
    S_e23670_Elem* e;
    for (int i = 31; i >= 0; i--) {
        e = &b->m_pElements[i];
        e->m_next = next;
        next = e;
    }
    b->m_iAllocatedCount = 0;
    b->m_free = e;
    hkMemoryAllocator& alloc = hkMemoryRouter_getInstance()->heap();
    if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(&alloc, this, sizeof(S_e23670_Block*));
    S_e23670_Block** p = m_data + m_iElementCount;
    for (int k = 0; k < 1; k++)
        p[k] = b;
    m_iElementCount++;
    if (m_iElementCount > 1) {
        S_e23670_Block* tmp = m_data[0];
        m_data[0] = m_data[m_iElementCount - 1];
        m_data[m_iElementCount - 1] = tmp;
    }
    return b;
}
}  // namespace fnv_00e23670

namespace fnv_00e23860 {




hkMemoryRouter* hkMemoryRouter_getInstance();

inline void freeBlock(void* p)
{
    hkMemoryRouter_getInstance()->heap().blockFree(p, 0xa08);
}

// Frees each pointer in m_data via freeBlock, resets the count, then clears and releases the array storage.
// @fnv 0x00e23860
void __fastcall FreeAllBlocks(hkArray<void*>* array)
{
    for (int i = 0; i < array->m_iElementCount; i++) {
        freeBlock(array->m_data[i]);
    }
    array->m_iElementCount = 0;
    array->clearAndDeallocate();
}
}  // namespace fnv_00e23860

inline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return fnv_00e23860::hkMemoryRouter_getInstance()->heap();
}

template <typename T>
__forceinline void hkArrayBase<T>::clear()
{
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


namespace fnv_00e239c0 {
struct EntryHandler
{
    virtual void First();
    virtual void Second();
    virtual void Process(void* entry, unsigned int size);
};
struct EntryHandlerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    EntryHandler* handler;
};
EntryHandlerRecord* __cdecl hkMemoryRouter_getInstance();

struct EntryListNode
{
    void** entries;
    int count;
    int unk08;
    int unk0c;
    int unk10;
    void ProcessEntries();
};
// Calls Process on each entry's handler with size 0x288, then resets count, unk0c and unk10 to zero.
// @fnv 0x00e239c0
void EntryListNode::ProcessEntries()
{
    int i = 0;
    while (i < count)
    {
        void* entry = entries[i];
        EntryHandlerRecord* context = hkMemoryRouter_getInstance();
        context->handler->Process(entry, 0x288);
        ++i;
    }
    count = 0;
    unk0c = 0;
    unk10 = 0;
}
}  // namespace fnv_00e239c0

namespace fnv_00e23a60 {




hkMemoryRouter* hkMemoryRouter_getInstance();

inline void copyPtrs(void** dst, void* const* src, int n)
{
    for (int i = 0; i < n; ++i) {
        dst[i] = src[i];
    }
}

}  // namespace fnv_00e23a60

// Grows the array's storage via the allocator if its capacity is below the source's size, then copies the source's pointers and size.
// @fnv 0x00e23a60
template <>
hkArray<void*>& hkArray<void*>::operator=(const hkArray<void*>& aSource)
{
    hkMemoryAllocator& alloc = *fnv_00e23a60::hkMemoryRouter_getInstance()->m_heap;
    if (getCapacity() < aSource.m_iElementCount) {
        if ((m_iCapacityState & 0x80000000) == 0) {
            alloc.bufFree(m_data, getCapacity() * sizeof(void*));
        }
        int reqBytes = aSource.m_iElementCount * sizeof(void*);
        m_data = (void**)alloc.bufAlloc(reqBytes);
        m_iCapacityState = reqBytes / (int)sizeof(void*);
    }
    m_iElementCount = aSource.m_iElementCount;
    fnv_00e23a60::copyPtrs(m_data, aSource.m_data, m_iElementCount);
    return *this;
}

// Taking the address emits the shared inline assignment specialization used by this unit.
hkArray<void*>& (hkArray<void*>::* const meshPointerArrayAssign)(const hkArray<void*>&) = &hkArray<void*>::operator=;

namespace fnv_00e23c70 {




hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct PtrArrayBase {
    void** m_ppData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ~PtrArrayBase() throw()
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        unsigned int uCapacity = m_uCapacity;
        m_iArrayLength = 0;
        if ((uCapacity & 0x80000000) == 0)
            pAllocator->bufFree(m_ppData, (uCapacity & 0x3fffffff) * 4);
        m_uCapacity = 0x80000000;
        m_ppData = 0;
    }
};

struct FUN_00e23c70 : PtrArrayBase {
    ~FUN_00e23c70() throw();
};

// Frees each element of the array through the audio allocator, then resets the element count to zero.
// @fnv 0x00e23c70
FUN_00e23c70::~FUN_00e23c70() throw()
{
    for (int i = 0; i < m_iArrayLength; i++) {
        void* pItem = m_ppData[i];
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(pItem, 0x388);
    }
    m_iArrayLength = 0;
}
}  // namespace fnv_00e23c70

namespace fnv_00e23d70 {



hkMemoryRouter* hkMemoryRouter_getInstance();

struct S_00e23d70_Array { // distinct from hkArrayBase: own cleanup 0x00e23d70 frees pointed-to 0x488-byte blocks before the storage.
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _clearAndDeallocate(hkMemoryAllocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0) {
            alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(void*));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    void ProcessEntries_00e23d70();
};

// @fnv 0x00e23d70
// src: GUESS 0x00e23d70 (confidence: low)
void S_00e23d70_Array::ProcessEntries_00e23d70()
{
    for (int i = 0; i < m_iElementCount; i++) {
        void* block = m_data[i];
        hkMemoryRouter_getInstance()->heap().blockFree(block, 0x488);
    }
    m_iElementCount = 0;
    _clearAndDeallocate(hkMemoryRouter_getInstance()->heap());
}
}  // namespace fnv_00e23d70

struct Node
{
    Node* next;
    Node* previous;
    Node* hkgpMeshBase_Vertex_Vertex(Node* source);
};
struct Manager {};
struct Object { Manager* manager; };
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
// Takes a node from the manager's free list, links it before the current head, and increments the count.
// @fnv 0x00e24140
void This::PushFront(Node* volatile apNode)
{
    Node* node;
    {
        Manager* manager;
        if (ready != 0 && *(Node**)((char*)object->manager + 0xa00) != 0)
            manager = object->manager;
        else
            manager = AllocateChainedSlotBlock();
        Node** ppFreeHead = (Node**)((char*)manager + 0xa00);
        node = *ppFreeHead;
        Node* next = node->next;
        ++*(unsigned int*)((char*)manager + 0xa04);
        *ppFreeHead = next;
    }
    Node* argument = apNode;
    node = node->hkgpMeshBase_Vertex_Vertex(argument);
    node->previous = 0;
    node->next = head;
    if (head) head->previous = node;
    ++count;
    head = node;
}

namespace fnv_00e247c0 {
struct Node {
    Node* f0;
    Node* volatile f4;
    int f8;
    int fC;
    unsigned int f10;
};

struct Pool {
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
    Node* f280;
    int f284;
};

struct Manager {
    Pool* f0;
};

struct SelfCls {
    Manager* field00;
    int field04;
    int field08;
    Node* field0C;
    unsigned int field10;

    Pool* hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_allocateNewPool();
    Node* hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_allocate(Node* src);
};

// Takes a node from the pool (or a fresh one), copies f8/fC/f10 from src, clears f4, links it at the head of the list via field0C, and returns it.
// @fnv 0x00e247c0
// src: HAVOK_LIB 0x00e247c0
Node* SelfCls::hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_allocate(Node* apSource) {
    Pool* p;
    if (this->field04 == 0 || this->field00->f0->f280 == 0)
        p = this->hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_allocateNewPool();
    else
        p = this->field00->f0;

    Node* n = p->f280;
    Node* nx = n->f0;
    p->f284++;
    p->f280 = nx;

    n->f8 = apSource->f8;
    n->fC = apSource->fC;
    n->f10 = (n->f10 & ~1u) | (apSource->f10 & 1u);
    n->f10 = (apSource->f10 & ~1u) | (n->f10 & 1u);
    n->f4 = 0;
    n->f0 = this->field0C;
    if (this->field0C)
        this->field0C->f4 = n;
    this->field10++;
    this->field0C = n;
    return n;
}
}  // namespace fnv_00e247c0

namespace fnv_00e24f70 {
struct CpuAllocator {
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct CpuAllocatorHolder {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CpuAllocator* allocator;
};
CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();
struct CpuObject {
    unsigned int unk00;
    unsigned short size;
    void UpdateState_00e18a50();
    CpuObject* FUN_00e24f70(unsigned int flags);
};
// @fnv 0x00e24f70
CpuObject* CpuObject::FUN_00e24f70(unsigned int flags)
{
    UpdateState_00e18a50();
    if (flags & 1) {
        CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
}  // namespace fnv_00e24f70




template <typename T>
struct S_00e25f00_ArrayLocalForm { // local form of hkArray: 0x00e25f00 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline ~S_00e25f00_ArrayLocalForm() throw() { _clearAndDeallocate(hkMemoryRouter::getInstance().heap()); }

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
    __forceinline void _clearAndDeallocate(hkMemoryAllocator& alloc) throw()
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct S_00e25f00_Elem {
    int unk0;
    int unk4;
    int unk8;
};

struct S_00e25f00 {
    S_00e25f00_ArrayLocalForm<S_00e25f00_ArrayLocalForm<S_00e25f00_Elem> > m_arrays;
    int unkC;
    S_00e25f00* FUN_00e25f00(unsigned int flags);
};

// @fnv 0x00e25f00
S_00e25f00* S_00e25f00::FUN_00e25f00(unsigned int flags)
{
    m_arrays._clearAndDeallocate(hkMemoryRouter::getInstance().heap());
    if (flags & 1)
        hkMemoryRouter::getInstance().heap().blockFree(this, sizeof(S_00e25f00));
    return this;
}

struct E25FB0Node {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned int m_ppLinks[3];
};

struct E25FB0Edge {
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

struct E25FB0Item {
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

struct E25FB0Mesh {
    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_setEdgeData(E25FB0Edge* edge, const int* data);
    void ProcessItems(E25FB0Edge edge, const E25FB0Item* items);
};

// @fnv 0x00e25fb0
void E25FB0Mesh::ProcessItems(E25FB0Edge edge, const E25FB0Item* items)
{
    for (int i = 0; i < 2; i++) {
        if (items[i].m_enabled)
            hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_setEdgeData(&edge, &items[i].m_data);
        unsigned int next = edge.m_node->m_ppLinks[edge.m_uiEdgeIndex];
        if (!(next & ~3))
            return;
        edge = E25FB0MakeEdge(next);
    }
}

// ---------------------------------------------------------------------------
// hkgpMesh::IConvexOverlap - accessor for the hull the overlap was built for.
//
// The object is the Havok side of a convex hull overlap query.  It starts with
// its virtual table, keeps the list of hull vertices at offset 0x14 and the
// hkgpConvexHull the overlap belongs to at offset 0xe4.  The function simply
// hands that hull back to the caller.
// ---------------------------------------------------------------------------

// @fnv 0x00e114a0
// src: GUESS 0x00e114a0 (confidence: high)
hkgpConvexHull* hkgpMesh_IConvexOverlap::GetConvexHull()
{
    return pConvexHull;
}

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

// Passes the data pointers of the first, second and third input blocks to FUN_00e11710 along with argument2 and argument3.
// @fnv 0x00e118e0
// src: HAVOK_LIB 0x00e118e0
void FUN_00e118e0_class::hkgpMesh_setPlane(
    const volatile Inputs_00e118e0* inputs, void* argument2, void* argument3)
{
    DataBlock_00e118e0* third = inputs->third;
    DataBlock_00e118e0* second = inputs->second;
    DataBlock_00e118e0* first = inputs->first;
    ValidateTriangleAndComputePlane(&first->data, &second->data,
        &third->data, argument2, argument3);
}

struct E12160Vertex {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_vContactPosition[4];
};

struct E12160Triangle {
    int unk00;
    int unk04;
    E12160Vertex* m_kVertices[3];
};

// Returns true if any of the triangle's three vertices has coordinates exactly equal to the given point.
// @fnv 0x00e12160
bool __cdecl TriangleHasVertexAtPoint(const E12160Triangle* triangle, const float* point)
{
    for (int i = 0; i < 3; i++) {
        const float* p = triangle->m_kVertices[i]->m_vContactPosition;
        if (p[0] == point[0] && p[1] == point[1] && p[2] == point[2])
            return true;
    }
    return false;
}

// distinct from ListNode: 0x00e12230 reads a node key at +0x34 and next at +0; the shared list node contains only data/next pointers.
struct HkgpmeshListNodeView {
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

struct FUN_00e12230_cls {
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

// Walks the linked list from m_pHead and replaces every node's m_i34 equal to oldValue with newValue.
// @fnv 0x00e12230
void FUN_00e12230_cls::ReplaceValueInList(int oldValue, int newValue)
{
    HkgpmeshListNodeView* node = m_pHead;
    while (node != 0) {
        HkgpmeshListNodeView* next = node->m_pNext;
        if (node->m_i34 == oldValue) {
            node->m_i34 = newValue;
        }
        node = next;
    }
}

struct S_00e12920_Node {
    S_00e12920_Node* next;
    int unk04, unk08, unk0C, unk10;
    unsigned int flags[3];
};
struct S_00e12920 {
    int unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C,unk20,unk24,unk28;
    S_00e12920_Node* head;
    bool hkgpMesh_isClosedManifold();
};
// Returns false if any node in the linked list has a flags entry whose upper bits are all zero; otherwise returns true.
// @fnv 0x00e12920
// src: HAVOK_LIB 0x00e12920
bool S_00e12920::hkgpMesh_isClosedManifold()
{
    for (S_00e12920_Node* n = head; n; n = n->next) {
        for (int i = 0; i < 3; i++) {
            if ((n->flags[i] & 0xfffffffc) == 0)
                return false;
        }
    }
    return true;
}

typedef unsigned int hkUint32;

struct S_00e13910_Triangle {
    int m_unk00;
    int m_unk04;
    void* m_kVertices[3];
    hkUint32 m_ppLinks[3];
};

struct S_00e13910_Edge {
    S_00e13910_Triangle* m_pkTriangle;
    hkUint32 m_uiEdgeIndex;

    S_00e13910_Edge() : m_pkTriangle(0), m_uiEdgeIndex(0) {}
    S_00e13910_Edge(S_00e13910_Triangle* t, hkUint32 i) : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    S_00e13910_Edge(hkUint32 l) {
        m_uiEdgeIndex = l & 3u;
        m_pkTriangle = (S_00e13910_Triangle*)(l & ~3u);
    }

    __forceinline bool isValid() const {
        return m_pkTriangle != 0;
    }

    __forceinline S_00e13910_Edge next() const {
        return S_00e13910_Edge(m_pkTriangle, (9 >> (m_uiEdgeIndex << 1)) & 3);
    }

    __forceinline S_00e13910_Edge prev() const {
        return S_00e13910_Edge(m_pkTriangle, (0x12 >> (m_uiEdgeIndex << 1)) & 3);
    }

    __forceinline S_00e13910_Edge link() const {
        hkUint32 l = m_pkTriangle->m_ppLinks[m_uiEdgeIndex];
        return S_00e13910_Edge(l);
    }

    __forceinline void*& start() const {
        return m_pkTriangle->m_kVertices[m_uiEdgeIndex];
    }

    __forceinline void*& apex() const {
        return prev().start();
    }

    __forceinline void bind(const S_00e13910_Edge& other) const {
        m_pkTriangle->m_ppLinks[m_uiEdgeIndex] = other.m_uiEdgeIndex + (hkUint32)other.m_pkTriangle;
        if (other.m_pkTriangle) {
            other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = m_uiEdgeIndex + (hkUint32)m_pkTriangle;
        }
    }

    static __forceinline S_00e13910_Edge null() {
        static S_00e13910_Edge n(0, 0);
        return n;
    }
};

// @fnv 0x00e13910
S_00e13910_Edge __stdcall FlipEdge(S_00e13910_Edge edge) {
    S_00e13910_Edge link = edge.link();
    if (link.isValid()) {
        const S_00e13910_Edge nextLink = edge.next().link();
        const S_00e13910_Edge prevLink = edge.prev().link();
        const S_00e13910_Edge linkedNextLink = link.next().link();
        const S_00e13910_Edge linkedPrevLink = link.prev().link();
        edge.start() = link.apex();
        link.start() = edge.apex();
        edge.prev().bind(link.prev());
        edge.next().bind(nextLink);
        edge.bind(linkedPrevLink);
        link.next().bind(linkedNextLink);
        link.bind(prevLink);
        return edge.prev();
    }
    return S_00e13910_Edge::null();
}

namespace fnv_00e14fa0 {
// distinct from ListNode: 0x00e14fa0 reads a node key at +0x30 and next at +0; the shared list node contains only data/next pointers.
struct HkgpmeshListNodeView {
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
    int m_iKey;
};

struct FUN_00e14fa0_cls {
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
    char unk100;
    char m_bFlag;

    void RemoveTriangle(HkgpmeshListNodeView* apNode);
    void hkgpMesh_removePartTriangles(int aiKey);
};

// @fnv 0x00e14fa0
// src: HAVOK_LIB 0x00e14fa0
void FUN_00e14fa0_cls::hkgpMesh_removePartTriangles(int aiKey)
{
    HkgpmeshListNodeView* pNode = m_pHead;
    if (pNode != 0) {
        do {
            HkgpmeshListNodeView* pNext = pNode->m_pNext;
            if (pNode->m_iKey == aiKey)
                RemoveTriangle(pNode);
            pNode = pNext;
        } while (pNode != 0);
    }
    m_bFlag = 0;
}
}  // namespace fnv_00e14fa0

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

struct __declspec(align(16)) HullPlane {
    float v[4];
};

struct HullVertex {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float pos[4];
};

struct __declspec(align(16)) HullTriangle {
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

struct HullTrianglePool {
    HullTriangle* UpdateFields_00e241a0(HullTriangle* storage);
};

struct FUN_00e19cf0_cls {
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

// @fnv 0x00e19cf0
HullTriangle* FUN_00e19cf0_cls::CreateTriangle(HullVertex* pVertexA, HullVertex* pVertexB, HullVertex* pVertexC)
{
    HullTriangle local;
    HullTriangle* t = m_kNodePool.UpdateFields_00e241a0(&local);
    t->m_30 = -1;
    { volatile int* q = &t->m_14; *q = 0; }
    { volatile int* q = &t->m_18; *q = 0; }
    { volatile int* q = &t->m_1C; *q = 0; }
    t->m_08 = pVertexA;
    t->m_0C = pVertexB;
    t->m_10 = pVertexC;
    ValidateTriangleAndComputePlane(pVertexA->pos, pVertexB->pos, pVertexC->pos, &t->m_20, true);
    return t;
}

extern "C" double __cdecl sqrt(double);
extern float DAT_010d51c4;
extern double DAT_01021928;
extern double DAT_010290b0;
extern double DAT_0109cc78;
extern int DAT_010eb000;
extern int DAT_011bdee0;
struct FUN_00d9c110_object {
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
struct FUN_00e1b750 {
    int* vtable;
    short unk04; volatile short active06;
    volatile int f08, f0c, f10, f14, f18; int unk1c;
    volatile int f20, f24, f28, f2c, f30; int unk34;
    int* ptr38;
    int unk3c;
    FUN_00d9c110_object sub40;
    volatile int fc0, fc4, fc8, fcc, fd0, fd4, fd8, fdc, fe0; int unk_e4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    volatile float f104; float f108, f10c;
    FUN_00e1b750();
    void ResetState();
};
// @fnv 0x00e1b750
FUN_00e1b750::FUN_00e1b750() {
    active06 = 1;
    f08 = 0;
    f0c = 0;
    f14 = 0;
    f18 = 0;
    f10 = 0x80000000;
    f20 = 0;
    f24 = 0;
    f28 = 0x80000000;
    f2c = 0;
    f30 = 0;
    vtable = &DAT_010eb000;
    sub40.FUN_00d9c110();
    double initial = DAT_010d51c4;
    fc0 = 0;
    fc4 = 0;
    fc8 = 0x80000000;
    fcc = 0;
    fd0 = 0;
    fd4 = 0x80000000;
    fd8 = 0;
    fdc = 0;
    fe0 = 0x80000000;
    f104 = initial;
    double angle = DAT_01021928;
    ptr38 = &DAT_011bdee0;
    unk_e4 = 0;
    f108 = (float)sqrt(angle) * DAT_010290b0 * DAT_0109cc78 * 2.0f;
    f10c = 0.0f;
    ResetState();
}

class E21CE0Ostream {
public:
    E21CE0Ostream(void* buf, int bufSize);
    E21CE0Ostream& operator<<(const char* str);
    // hkOstream destructor body (Havok was built without EH): called explicitly
    void destroy();

    int unk00;
    int unk04;
    int unk08;
};

class E21CE0Error {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual int message(int type, int id, const char* description, const char* file, int line);
};

extern E21CE0Error* g_E21CE0Error;

// Builds a "Not implemented" message in a stack buffer, passes it to g_E21CE0Error->message with file and line, and breaks if it returns nonzero.
// @fnv 0x00e21ce0
int __cdecl ReportNotImplemented()
{
    int buf[0x80];
    E21CE0Ostream os(buf, sizeof(buf));
    os << "Not implemented";
    if (g_E21CE0Error->message(3, 0xcfa7dfcc, (const char*)buf,
            "d:\\build\\20091222_000100_AiAnBeClDePh\\Source\\Common/Internal/GeometryProcessing/Mesh/hkgpMesh.h", 0x118))
        __debugbreak();
    os.destroy();
    return 0;
}

struct VecData;
struct Components { int x,y,z,w; void copy(const VecData* from); };
struct VecData { int unk00,unk04,unk08,unk0c,x,y,z,w; };
inline void Components::copy(const VecData* from) { x=from->x; y=from->y; z=from->z; w=from->w; }
struct VectorGroup { int unk00,unk04; VecData* first; VecData* second; VecData* third; };
struct InputPacket { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c; VectorGroup* group; };
struct Triple { Components first,second,third; };
int __cdecl hkGeometryProcessing_checkTrianglesIntersection(void*,const Triple*);
struct FUN_00e22270_Class { int unk00; unsigned int flags; int unk08,unk0c,output; float hkgpMeshInternals_TriangleOverlap_addLeaf(InputPacket*); };
// @fnv 0x00e22270
// src: HAVOK_LIB 0x00e22270
float FUN_00e22270_Class::hkgpMeshInternals_TriangleOverlap_addLeaf(InputPacket* input) {
 __declspec(align(16)) Triple values;
 VectorGroup* group=input->group;
 values.first.copy(group->first);
 values.second.copy(group->second);
 values.third.copy(group->third);
 flags |= !!hkGeometryProcessing_checkTrianglesIntersection(&output,&values);
 volatile float outcome;
 if(flags) outcome=0.0f; else outcome=1.0f;
 return outcome;
}

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

// @fnv 0x00e22470
// src: HAVOK_LIB 0x00e22470
void FUN_00e22470_cls::IConvexOverlapImpl_ShapeBridge_getSupportingVertex(int a)
{
    m_04->Forward(a);
}

struct FUN_00e22970_Item {
    int m_data[12];
};

struct FUN_00e22970_Cls {
    FUN_00e22970_Item* m_pItems;
    int m_uiItemCount;
    int m_pRayCursor;

    void AppendItems(void* apArg1, const FUN_00e22970_Item* apSrc, int aCount);
};

void __cdecl hkArrayUtil__reserve(void* apArg1, FUN_00e22970_Cls* apThis, int aCapacity, int aElemSize);
extern "C" void* __cdecl memcpy(void* apDst, const void* apSrc, unsigned int aCount);

// Grows the item array if needed, copies aCount 0x30-byte items from apSrc to the end, and updates the count.
// @fnv 0x00e22970
void FUN_00e22970_Cls::AppendItems(void* apArg1, const FUN_00e22970_Item* apSrc, int aCount)
{
    int newCount = m_uiItemCount + aCount;
    if ((m_pRayCursor & 0x3fffffff) < newCount) {
        int newCap = (m_pRayCursor & 0x3fffffff) * 2;
        if (newCount >= newCap) {
            newCap = newCount;
        }
        hkArrayUtil__reserve(apArg1, this, newCap, 0x30);
    }
    FUN_00e22970_Item* pDestItem = m_pItems + m_uiItemCount;
    for (int i = 0; i < aCount; ++i) {
        if (&pDestItem[i]) {
            memcpy(&pDestItem[i], &apSrc[i], 0x30);
        }
    }
    m_uiItemCount = newCount;
}

struct FUN_00e229f0_cls {
    int* m_data;
    int m_uiItemCount;
    unsigned int m_capBits;

    void AppendInts(int a1, int* a2, int a3);
};

void __cdecl hkArrayUtil__reserve(int a1, void* self, int newCap, int elemSize);

// Grows the buffer if needed, copies a3 ints from a2 to the end, and updates the count.
// @fnv 0x00e229f0
void FUN_00e229f0_cls::AppendInts(int a1, int* pSource, int iCount)
{
    int newSize = m_uiItemCount + iCount;
    unsigned int cap = m_capBits & 0x3fffffffu;
    if ((int)cap < newSize) {
        int newCap = (int)(cap + cap);
        if (newSize >= newCap) newCap = newSize;
        hkArrayUtil__reserve(a1, this, newCap, 4);
    }
    int* dst = m_data + m_uiItemCount;
    if (iCount > 0) {
        int delta = (int)pSource - (int)dst;
        int n = iCount;
        do { *dst = *(int*)((char*)dst + delta); dst++; } while (--n != 0);
    }
    m_uiItemCount = newSize;
}

struct FUN_00e22c80_cls {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;

    FUN_00e22c80_cls* ComputeValue_00e22c80(unsigned int value, FUN_00e22c80_cls* src);
};

// @fnv 0x00e22c80
// src: GUESS 0x00e22c80 (confidence: low)
FUN_00e22c80_cls* FUN_00e22c80_cls::ComputeValue_00e22c80(unsigned int value, FUN_00e22c80_cls* src) {
    this->m_00 = value;
    unsigned int second = src->m_04;
    this->m_04 = src->m_00;
    this->m_08 = second;
    return this;
}

extern unsigned int DAT_01267e30;
extern unsigned int DAT_01267e34;
extern unsigned int DAT_01267e38;
extern unsigned int DAT_01267e3c;
extern float DAT_0104da48;
extern unsigned int DAT_0126ebf0;
extern unsigned int DAT_0126ebe8;
extern unsigned int DAT_0126ebec;

struct FUN_00e22ca0_cls {
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

// Initializes the object's fields from global defaults, sets m_40 to FLT_MAX, zeroes m_44/m_48, and copies the lazily-initialized globals into m_4c/m_50.
// @fnv 0x00e22ca0
FUN_00e22ca0_cls::FUN_00e22ca0_cls()
{
    this->m_00 = DAT_01267e30;
    this->m_04 = DAT_01267e34;
    this->m_08 = DAT_01267e38;
    this->m_0c = DAT_01267e3c;
    this->m_10 = DAT_01267e30;
    this->m_14 = DAT_01267e34;
    this->m_18 = DAT_01267e38;
    this->m_1c = DAT_01267e3c;
    this->m_20 = DAT_01267e30;
    this->m_24 = DAT_01267e34;
    this->m_28 = DAT_01267e38;
    this->m_2c = DAT_01267e3c;
    this->m_40 = 3.402820018375656e+38f;
    *(volatile unsigned char*)&this->m_44 = 0;
    *(volatile unsigned int*)&this->m_48 = 0;
    if ((DAT_0126ebf0 & 1u) == 0) {
        DAT_0126ebf0 |= 1u;
        DAT_0126ebe8 = 0;
        DAT_0126ebec = 0;
    }
    this->m_4c = DAT_0126ebe8;
    this->m_50 = DAT_0126ebec;
}

struct FUN_00e22f20_cls {
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

// Copies fields unk08 through unk40 from src into this object and returns *this.
// @fnv 0x00e22f20
// src: HAVOK_LIB 0x00e22f20
FUN_00e22f20_cls& FUN_00e22f20_cls::hkgpMeshBase_Triangle_Triangle(const FUN_00e22f20_cls& aSource) {
    unk08 = aSource.unk08;
    unk0C = aSource.unk0C;
    unk10 = aSource.unk10;
    unk14 = aSource.unk14;
    unk18 = aSource.unk18;
    unk1C = aSource.unk1C;
    unk20 = aSource.unk20;
    unk24 = aSource.unk24;
    unk28 = aSource.unk28;
    unk2C = aSource.unk2C;
    unk30 = aSource.unk30;
    unk34 = aSource.unk34;
    unk38 = aSource.unk38;
    unk3C = aSource.unk3C;
    unk40 = aSource.unk40;
    return *this;
}

struct SearchItem { int unk00; int unk04; unsigned int hashX; unsigned int hashY; };
struct SearchPath { SearchItem** nodes; int depth; };
struct HashEntry { SearchItem* left; SearchItem* right; int result; };
struct HashBucket { HashEntry* entries; int count; int unk08; };
struct HashTableBase { HashBucket* buckets; unsigned int bucketCount; };
struct SearchOwner { int LookupPairResult(SearchPath* path); };
// @fnv 0x00e23900
int SearchOwner::LookupPairResult(SearchPath* path)
{
    SearchItem** nodes = path->nodes;
    HashTableBase* table;
    if (nodes == 0 || (table = *(HashTableBase**)((char*)this + 0x24c)) == 0)
        return 0;
    int depth = path->depth;
    SearchItem* left = nodes[depth + 2];
    SearchItem* right = nodes[((9 >> (depth * 2)) & 3) + 2];
    unsigned int leftHash = left->hashY * 0x3442a5u;
    leftHash += left->hashX * 0x21528000u;
    unsigned int rightHash = right->hashY * 0x1958e9u;
    rightHash -= right->hashX * 0x538b8000u;
    HashBucket* bucket = table->buckets + ((leftHash ^ rightHash) % table->bucketCount);
    int count = bucket->count;
    int i = 0;
    if (count > 0) {
        HashEntry* entries = bucket->entries;
        HashEntry* cursor = entries;
        do {
            if (cursor->left == left && cursor->right == right) {
                if (i == -1)
                    return 0;
                HashEntry* found = entries + i;
                if (found == 0)
                    return 0;
                return found->result;
            }
            ++i;
            ++cursor;
        } while (i < count);
    }
    return 0;
}

struct Entry {
    Entry* next;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned int links[3];
    unsigned int flags;
};

struct Ref {
    unsigned int value;
    unsigned int extra;
};

struct Tally {
    int good;
    int bad;
};

struct Scanner {
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

// Walks the entry list, visits each link reference of flagged entries via Visit, tallies good and bad results, and returns whether good exceeds bad.
// @fnv 0x00e23bb0
bool Scanner::CheckLinks()
{
    Tally t;
    t.good = 0;
    t.bad = 0;
    for (Entry* e = head; e; e = e->next) {
        if (e->flags & 0x10) {
            Ref ref;
            Ref m;
            int i = 0;
            ref.value = (unsigned int)e;
            for (; i < 3; i++) {
                ref.extra = i;
                unsigned int link = e->links[i];
                if (link & 0xfffffffc) {
                    m.extra = link & 3;
                    m.value = e->links[i] & 0xfffffffc;
                    if (Visit(&ref)) {
                        t.good++;
                    } else if (Visit(&m)) {
                        t.bad++;
                    }
                } else {
                    if (Visit(&ref)) {
                        t.good++;
                    } else {
                        t.bad++;
                    }
                }
            }
        }
    }
    return t.good > t.bad;
}

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

// @fnv 0x00e241a0
// src: GUESS 0x00e241a0 (confidence: low)
void FUN_00e241a0_cls::UpdateFields_00e241a0(void* value)
{
    FreeCtx* ctx = 0;
    if (m_04 == 0)
    {
        ctx = AllocateChainedSlotBlock();
    }
    else
    {
        ctx = m_00->m_00;
        if (ctx->m_a00 == 0)
        {
            ctx = AllocateChainedSlotBlock();
        }
    }

    PoolNode* node = ctx->m_a00;
    ctx->m_a00 = node->m_00;
    ctx->m_a04++;

    PoolNode* n = node->hkgpMeshBase_Triangle_Triangle(value);
    n->m_04 = 0;
    n->m_00 = m_0c;
    if (m_0c != 0)
    {
        m_0c->m_04 = n;
    }
    m_10++;
    m_0c = n;
}

struct FUN_00e247a0_cls {
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

// @fnv 0x00e247a0
// src: HAVOK_LIB 0x00e247a0
FUN_00e247a0_cls* FUN_00e247a0_cls::hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_EdgeDataValue_EdgeDataValue() {
    FUN_00e247a0_cls* self = this;
    self->m_00 = 0;
    _ReadWriteBarrier();
    self->m_04 = (char*)self + 0x10;
    self->m_08 = 0;
    self->m_0c = 0x80000004u;
    return self;
}

struct E24850Element {
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

struct E24850Block {
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

struct E24850Node {
    E24850Node* m_next;
    E24850Node* m_pSecondNode;

    static void* operator new(unsigned int, void* p) { return p; }
    E24850Node(void* data);
};

struct E24850List {
    E24850Block** m_kBlocks;
    int m_iBlockCount;
    int m_blocksCapacity;
    E24850Node* m_pFirstNode;
    int m_iNodeCount;

    E24850Block* addBlock();
    E24850Node* hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_allocate(void* data);
};

// @fnv 0x00e24850
// src: HAVOK_LIB 0x00e24850
E24850Node* E24850List::hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_allocate(void* data)
{
    E24850Block* block;
    if (m_iBlockCount == 0 || (block = m_kBlocks[0])->m_firstFree == 0)
        block = addBlock();
    E24850Node* node = new (block->allocate()) E24850Node(data);
    node->m_pSecondNode = 0;
    node->m_next = m_pFirstNode;
    if (m_pFirstNode)
        m_pFirstNode->m_pSecondNode = node;
    m_iNodeCount++;
    m_pFirstNode = node;
    return node;
}

// Text writer: format an integer into a scratch buffer and write it to the stream.

int __cdecl CC0280Format(char* pcBuffer, unsigned int uiSize, const char* pcFormat, ...);

class CC0280Stream {
public:
    virtual void Unk_00();
    virtual int Write(const void* pvData, int iSize);
};

// File-static helper (reconstructed separately); MSVC passes its arguments in registers.
static __declspec(noinline) void CC0280WriteString(CC0280Stream* pkStream, const char* pcText)
{
    int iLen = 0;
    while (pcText[iLen])
        iLen++;
    pkStream->Write(&iLen, 4);
    if (iLen > 0)
        pkStream->Write(pcText, iLen);
}

class CC0280Writer {
public:
    int unk00;
    int unk04;
    CC0280Stream* m_pDataStream;

    CC0280Writer& WriteInt(int iValue);
};

// Formats iValue as a decimal string into a stack buffer and writes it to the stream via CC0280WriteString, returning *this.
// @fnv 0x00cc0280
CC0280Writer& CC0280Writer::WriteInt(int iValue)
{
    // Word-typed scratch buffer (this Havok code was built without /GS, so no cookie on the stack buffer).
    unsigned int auiBuffer[0x2728 / 4];
    char* pcBuffer = (char*)auiBuffer;
    CC0280Format(pcBuffer, sizeof(auiBuffer), "%i", iValue);
    CC0280WriteString(m_pDataStream, pcBuffer);
    return *this;
}






namespace fnvc_adapt { hkMemoryRouter* __cdecl hkMemoryRouter_getInstance(); }

struct FUN_00d9be30_cls { int m_vptr; void UpdateState_00d9be30(); };
struct FUN_00d9c010_cls { void ClearBuffers(); };
struct FUN_00e23860_cls { void FreeAllBlocks(); };

extern int DAT_010eb000;
extern int DAT_010eaf50;
extern int DAT_0102e388;
extern int DAT_010d40a4;

struct FUN_00e18a50_cls {
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

// Resets the vtable, frees the three arrays through the audio allocator, then destroys the embedded sub-objects and resets the vtable again.
// @fnv 0x00e18a50
// src: GUESS 0x00e18a50 (confidence: low)
void FUN_00e18a50_cls::UpdateState_00e18a50()
{
    m_vptr00 = (int)&DAT_010eb000;
    ResetState();

    hkMemoryRouter* pHolder = (hkMemoryRouter*)fnvc_adapt::hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    unsigned int uCap = m_cap1;
    m_cnt1 = 0;
    if ((uCap & 0x80000000u) == 0) {
        pAllocator->bufFree((void*)m_data1, (uCap & 0x3fffffffu) * 4);
    }
    m_data1 = 0;
    m_cap1 = 0x80000000u;

    pHolder = (hkMemoryRouter*)fnvc_adapt::hkMemoryRouter_getInstance();
    pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    uCap = m_cap2;
    m_cnt2 = 0;
    if ((uCap & 0x80000000u) == 0) {
        pAllocator->bufFree((void*)m_data2, (uCap & 0x3fffffffu) * 16);
    }
    m_data2 = 0;
    m_cap2 = 0x80000000u;

    pHolder = (hkMemoryRouter*)fnvc_adapt::hkMemoryRouter_getInstance();
    pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    uCap = m_cap3;
    m_cnt3 = 0;
    if ((uCap & 0x80000000u) == 0) {
        pAllocator->bufFree((void*)m_data3, (uCap & 0x3fffffffu) * 16);
    }
    m_data3 = 0;
    FUN_00d9be30_cls* pSub40 = (FUN_00d9be30_cls*)&m_vptr40;
    m_cap3 = 0x80000000u;

    pSub40->m_vptr = (int)&DAT_010d40a4;
    pSub40->UpdateState_00d9be30();
    ((FUN_00d9c010_cls*)((char*)pSub40 + 0x1c))->ClearBuffers();

    m_vptr00 = (int)&DAT_010eaf50;
    FUN_00e234e0_* pSub20 = (FUN_00e234e0_*)&unk20;
    pSub20->FreeAllItems();
    ((FUN_00e23860_cls*)pSub20)->FreeAllBlocks();

    FUN_00e234e0_* pSub08 = (FUN_00e234e0_*)&unk08;
    pSub08->FreeAllItems();
    ((FUN_00e23860_cls*)pSub08)->FreeAllBlocks();

    m_vptr00 = (int)&DAT_0102e388;
}

namespace fnv_00e21e00 {
extern int DAT_010eacf4;





namespace fnvc_adapt { hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw(); }

struct FUN_00e21e00_cls {
    int m_vptr;

    FUN_00e21e00_cls* FUN_00e21e00(unsigned char acFlags);
};

// Sets the vtable pointer and, if bit 0 of acFlags is set, frees this object through the audio allocator.
// @fnv 0x00e21e00
FUN_00e21e00_cls* FUN_00e21e00_cls::FUN_00e21e00(unsigned char acFlags)
{
    m_vptr = (int)&DAT_010eacf4;
    if (acFlags & 1) {
        hkMemoryRouter* pHolder = fnvc_adapt::hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(this, 0x30);
    }
    return this;
}
}  // namespace fnv_00e21e00

namespace fnv_00e22d80 {
extern int DAT_010cd664;





namespace fnvc_adapt { hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw(); }

struct FUN_00e22d80_cls {
    int m_vptr;

    FUN_00e22d80_cls* FUN_00e22d80(unsigned char acFlags);
};

// Sets the vtable pointer, then if bit 0 of acFlags is set, frees this object through the allocator obtained from FUN_00c85750.
// @fnv 0x00e22d80
FUN_00e22d80_cls* FUN_00e22d80_cls::FUN_00e22d80(unsigned char acFlags)
{
    m_vptr = (int)&DAT_010cd664;
    if (acFlags & 1) {
        hkMemoryRouter* pHolder = fnvc_adapt::hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(this, 0x14);
    }
    return this;
}
}  // namespace fnv_00e22d80

namespace fnv_00e23710 {


namespace fnvc_adapt { hkMemoryRouter* hkMemoryRouter_getInstance(); }
void ResizeAudioStream(hkMemoryAllocator& heap, void* arr, int elemSize);

struct S_00e23710_Elem {
    S_00e23710_Elem* next;
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20;
};
struct S_00e23710_Block {
    S_00e23710_Elem elems[32];
    S_00e23710_Elem* freeList;
    int used;
};

struct S_00e23710_Array {
    S_00e23710_Block** m_data;
    int m_iElementCount;
    int m_cap;
    S_00e23710_Block* hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_allocateNewPool();
};

// Allocates a block from the heap, links its 32 elements into a free list, grows the array if full, stores the block and returns it.
// @fnv 0x00e23710
// src: HAVOK_LIB 0x00e23710
S_00e23710_Block* S_00e23710_Array::hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_allocateNewPool()
{
    hkMemoryAllocator& heap = fnvc_adapt::hkMemoryRouter_getInstance()->heap();
    S_00e23710_Elem* prev = 0;
    S_00e23710_Block* block = (S_00e23710_Block*)heap.blockAlloc(sizeof(S_00e23710_Block));
    for (int i = 31; i >= 0; i--) {
        S_00e23710_Elem* e = &block->elems[i];
        e->next = prev;
        prev = e;
    }
    block->used = 0;
    block->freeList = prev;

    hkMemoryRouter* r = fnvc_adapt::hkMemoryRouter_getInstance();
    if (m_iElementCount == (m_cap & 0x3fffffff))
        ResizeAudioStream(r->heap(), this, 4);
    S_00e23710_Block** p = m_data + m_iElementCount;
    for (int k = 0; k < 1; k++) p[k] = block;
    m_iElementCount++;
    if (m_iElementCount > 1) {
        S_00e23710_Block* t = m_data[0];
        m_data[0] = m_data[m_iElementCount - 1];
        m_data[m_iElementCount - 1] = t;
    }
    return block;
}
}  // namespace fnv_00e23710

namespace fnv_00e23af0 {




namespace fnvc_adapt { hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw(); }

struct FUN_00e23af0_cls {
    void* m_pData;
    unsigned int m_uCount;
    unsigned int m_uiObjectFlags;

    FUN_00e23af0_cls* ClearAndFree(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// @fnv 0x00e23af0
FUN_00e23af0_cls* FUN_00e23af0_cls::ClearAndFree(unsigned char acFlags)
{
    hkMemoryRouter* pHolder = fnvc_adapt::hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    unsigned int uFlags = m_uiObjectFlags;
    m_uCount = 0;
    if ((uFlags & 0x80000000u) == 0) {
        unsigned int uCount = uFlags & 0x3fffffffu;
        pAllocator->bufFree(m_pData, uCount * 64u);
    }
    m_pData = 0;
    m_uiObjectFlags = 0x80000000u;
    if (acFlags & 1) {
        hkMemoryRouter* pHolder2 = fnvc_adapt::hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
        pAllocator2->blockFree(this, 12);
    }
    return this;
}
}  // namespace fnv_00e23af0

namespace fnv_00e23b50 {
extern "C" void* DAT_010eaf50;
extern "C" void* DAT_0102e388;





namespace fnvc_adapt { hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw(); }

struct SpawnedSub {
    void** m_ppItems;
    int m_iArrayLength;
    int unk08;
    int m_i0c;
    int m_i10;
    int unk14;

    void FreeAllItems();
    void FreeAllBlocks();
};

struct FUN_00e234e0_cls {
    void** m_ppItems;
    int m_iArrayLength;
    int unk08;
    int m_i0c;
    int m_i10;
    int unk14;

    void FreeAllItems();
    void FreeAllBlocks();
};

struct SpawnedObject {
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    FUN_00e234e0_cls m_sub08;
    SpawnedSub m_sub20;

    SpawnedObject* DestroySpawnedObject(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Resets the vtable, tears down both sub-objects, and if acFlags has bit 0 set, frees this object through the audio allocator.
// @fnv 0x00e23b50
SpawnedObject* SpawnedObject::DestroySpawnedObject(unsigned char acFlags)
{
    m_vptr = (int)&DAT_010eaf50;
    m_sub20.FreeAllItems();
    m_sub20.FreeAllBlocks();
    m_sub08.FreeAllItems();
    m_sub08.FreeAllBlocks();
    m_vptr = (int)&DAT_0102e388;
    if (acFlags & 1) {
        hkMemoryRouter* pHolder = fnvc_adapt::hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00e23b50

namespace fnv_00e23cf0 {
struct FixedAllocator {
    virtual void v00();
    virtual void v04();
    virtual void FreeBlock(void* p, unsigned int size);
    virtual void v0C();
    virtual void FreeArray(void* p, unsigned int size);
};



namespace fnvc_adapt { hkMemoryRouter* hkMemoryRouter_getInstance(); }

struct FUN_00e23cf0_cls {
    void** m_pItems;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    void ClearAndFreeItems();
};

// Frees each item in m_pItems via the allocator, resets the count, frees the item array, and clears the capacity and pointer.
// @fnv 0x00e23cf0
void FUN_00e23cf0_cls::ClearAndFreeItems()
{
    int i = 0;
    if (i < m_iArrayLength) {
        do {
            void* item = m_pItems[i];
            hkMemoryRouter* holder = fnvc_adapt::hkMemoryRouter_getInstance();
            reinterpret_cast<hkMemoryAllocator*>(holder->m_heap)->blockFree(item, 0x288);
            i++;
        } while (i < m_iArrayLength);
    }

    m_iArrayLength = 0;
    hkMemoryRouter* holder = fnvc_adapt::hkMemoryRouter_getInstance();
    FixedAllocator* alloc = reinterpret_cast<FixedAllocator*>(holder->m_heap);
    unsigned int cap = m_uCapBits;
    m_iArrayLength = 0;
    if ((cap & 0x80000000u) == 0) {
        alloc->FreeArray(m_pItems, (cap & 0x3fffffffu) * 4);
    }
    m_uCapBits = 0x80000000u;
    m_pItems = 0;
}
}  // namespace fnv_00e23cf0

namespace fnv_00e24760 {
struct SpawnedAllocator {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* p, unsigned int size);
};



namespace fnvc_adapt { hkMemoryRouter* hkMemoryRouter_getInstance(); }

struct FUN_00e24760_cls {
    int unk00;
    void* m_pData;
    unsigned int m_08;
    unsigned int m_0C;

    void ClearAndFreeBuffer();
};

// @fnv 0x00e24760
void FUN_00e24760_cls::ClearAndFreeBuffer()
{
    hkMemoryRouter* holder = fnvc_adapt::hkMemoryRouter_getInstance();
    SpawnedAllocator* alloc = reinterpret_cast<SpawnedAllocator*>(holder->m_heap);
    unsigned int flags = m_0C;
    m_08 = 0;
    if ((flags & 0x80000000u) == 0) {
        alloc->Free(m_pData, (flags & 0x3fffffffu) * 4);
    }
    *(volatile unsigned int*)&m_0C = 0x80000000u;
    *(void* volatile*)&m_pData = 0;
}
}  // namespace fnv_00e24760

namespace fnv_00e27df0 {




namespace fnvc_adapt { hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw(); }
extern int DAT_010eb0e0;
extern int DAT_010eb088;
extern int DAT_0102e388;

struct FUN_00e27df0_sub10 {
    int unk00;
    int unk04;
    int unk08;

    void ProcessEntries();
    void ClearAndFreeItems();
};

struct FUN_00e27df0_sub28 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;

    void hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_reset();
    void ProcessEntries_00e23d70();
};

struct FUN_00e27df0_sub250 {
    int unk00;

    void FUN_00e23c70();
};

struct FUN_00e27df0_cls {
    int m_vptr00;
    unsigned short m_uSize;
    unsigned short m_u06;
    int m_vptr08;
    int unk0c;
    FUN_00e27df0_sub10 m_sub10;
    int unk1c;
    int unk20;
    int unk24;
    FUN_00e27df0_sub28 m_sub28;
    void** m_pEntryData;
    int m_iArrayLength;
    unsigned int m_uCapBits;
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
    FUN_00e27df0_sub250 m_sub250;

    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_reset(int aiFlag);
    FUN_00e27df0_cls* FUN_00e27df0(unsigned char acFlags);
};

// @fnv 0x00e27df0
FUN_00e27df0_cls* FUN_00e27df0_cls::FUN_00e27df0(unsigned char acFlags)
{
    m_vptr00 = (int)&DAT_010eb0e0;
    hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_reset(1);
    m_sub250.FUN_00e23c70();
    hkMemoryRouter* pHolder = fnvc_adapt::hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    m_iArrayLength = 0;
    unsigned int uCap = m_uCapBits;
    if ((uCap & 0x80000000u) == 0) {
        pAllocator->bufFree(m_pEntryData, (uCap & 0x3fffffffu) * 8);
    }
    m_pEntryData = 0;
    *(volatile unsigned int*)&m_uCapBits = 0x80000000u;
    FUN_00e27df0_sub28* pSub28 = &m_sub28;
    *(volatile int*)&m_vptr08 = (int)&DAT_010eb088;
    pSub28->hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_reset();
    pSub28->ProcessEntries_00e23d70();
    m_sub10.ProcessEntries();
    m_sub10.ClearAndFreeItems();
    m_vptr08 = (int)&DAT_0102e388;
    m_vptr00 = (int)&DAT_0102e388;
    if (acFlags & 1) {
        hkMemoryRouter* pHolder2 = fnvc_adapt::hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
        pAllocator2->blockFree(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00e27df0

// Havok ray/plane-triangle cast step: intersect the cast ray with the triangle's plane, test the hit point
// against the triangle, and keep the closest hit fraction.
#ifndef _INCLUDED_MM2
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; } __m128, LocalM128;
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ps(const float* p);
#endif
#ifndef _INCLUDED_MM2
extern "C" void _mm_store_ps(float* p, __m128 a);
#endif
#ifndef _INCLUDED_MM2
extern "C" void _mm_store_ss(float* p, __m128 a);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_mul_ss(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sub_ss(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_div_ss(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
#endif

extern __m128 DAT_010c7160;    // constant vector (zero)
extern float DAT_010c8440;     // point-in-triangle tolerance (-FLT_EPSILON)

typedef __m128 MeshSimdQuad;
static inline float ToReal(MeshSimdQuad v) { float f; _mm_store_ss(&f, v); return f; }

struct __declspec(align(16)) Vec4f {
    float v[4];
    __m128 Get() const { return _mm_load_ps(v); }
    void Set(__m128 q) { _mm_store_ps(v, q); }
};
struct TriVertex {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Vec4f m_vContactPosition;
};
struct CastTri {
    int unk00;
    int unk04;
    TriVertex* m_kVertices[3];
    const Vec4f& GetVertex(int i) const { return m_kVertices[i]->m_vContactPosition; }
    int unk14;
    int unk18;
    int unk1c;
    Vec4f m_kTriangleNormal;
};
struct CastBody {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    CastTri* m_tri;
};
bool __cdecl hkGeometryProcessing_checkPointInsideTriangle(const Vec4f* pkPoint, const Vec4f& kA, const Vec4f& kB, const Vec4f& kC, float fTolerance);

static inline MeshSimdQuad Dot3(__m128 a, __m128 b)
{
    const __m128 m = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m));
}
static inline MeshSimdQuad Dot4xyz1(__m128 a, __m128 b)
{
    const __m128 m = _mm_mul_ps(a, b);
    const __m128 zw = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), _mm_shuffle_ps(a, a, 0xff));
    const __m128 xy = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    return _mm_add_ps(zw, xy);
}

struct TriRayCaster {
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

// @fnv 0x00e22320
float TriRayCaster::RayCastBody(CastBody* pkBody)
{
    CastTri* pkTri = pkBody->m_tri;
    const __m128 kWorldPosition = m_dir.Get();
    const MeshSimdQuad d = Dot3(pkTri->m_kTriangleNormal.Get(), kWorldPosition);
    if (ToReal(_mm_mul_ss(d, d)) > 1.192092896e-07f)
    {
        const __m128 kStart = m_kRayStart.Get();
        const MeshSimdQuad dist = Dot4xyz1(pkBody->m_tri->m_kTriangleNormal.Get(), kStart);
        const MeshSimdQuad t = _mm_div_ss(_mm_sub_ss(DAT_010c7160, dist), d);
        Vec4f kPoint;
        kPoint.Set(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(t, t, 0), kWorldPosition), kStart));
        if (ToReal(t) > 0.0f && ToReal(t) < m_fHitDistance)
        {
            if (hkGeometryProcessing_checkPointInsideTriangle(&kPoint, pkTri->GetVertex(0), pkTri->GetVertex(1), pkTri->GetVertex(2), DAT_010c8440))
            {
                m_fHitDistance = ToReal(t);
                m_hitTri = pkTri;
            }
        }
    }
    return m_fHitDistance;
}

struct SceneVec {
    float x;
    float y;
    float z;
    float w;
};

struct SceneBone {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    SceneVec m_10;
    __m128 m_20;
    __m128 m_30;
};

struct SceneSet {
    unsigned int unk00;
    unsigned int unk04;
    SceneBone* m_08;
    SceneBone* m_0c;
    SceneBone* m_10;
};

void __cdecl hkAabbUtil_calcAabb_00cbeb70(void* v, int count, void* p);

typedef unsigned int BufferAddress138;
struct FUN_00e227f0_cls {
    unsigned int unk00;
    SceneSet* m_04;
    void* ComputeValues_00e227f0(BufferAddress138 bufferAddress);
};

// @fnv 0x00e227f0
// src: GUESS 0x00e227f0 (confidence: low)
void* FUN_00e227f0_cls::ComputeValues_00e227f0(BufferAddress138 bufferAddress) {
    __declspec(align(16)) SceneVec L[6];
    SceneSet* s = m_04;
    SceneBone* b = s->m_08;

    L[0] = b->m_10;
    *(unsigned int*)&L[0].w = 0x3f000000u;

    b = s->m_08;
    L[1] = b->m_10;
    __m128 t = _mm_shuffle_ps(b->m_30, b->m_30, 0x55);
    t = _mm_shuffle_ps(t, t, 0);
    t = _mm_mul_ps(t, b->m_20);
    _mm_store_ps(&L[1].x, _mm_add_ps(t, _mm_load_ps(&L[1].x)));
    *(unsigned int*)&L[1].w = 0x3f000001u;

    b = s->m_0c;
    L[2] = b->m_10;
    *(unsigned int*)&L[2].w = 0x3f000002u;

    b = s->m_0c;
    L[3] = b->m_10;
    t = _mm_shuffle_ps(b->m_30, b->m_30, 0x55);
    t = _mm_shuffle_ps(t, t, 0);
    t = _mm_mul_ps(t, b->m_20);
    _mm_store_ps(&L[3].x, _mm_add_ps(t, _mm_load_ps(&L[3].x)));
    *(unsigned int*)&L[3].w = 0x3f000003u;

    b = s->m_10;
    L[4] = b->m_10;
    *(unsigned int*)&L[4].w = 0x3f000004u;

    b = s->m_10;
    L[5] = b->m_10;
    t = _mm_shuffle_ps(b->m_30, b->m_30, 0x55);
    void* result=reinterpret_cast<void*>(static_cast<const volatile unsigned int&>(bufferAddress));
    t = _mm_shuffle_ps(t, t, 0);
    t = _mm_mul_ps(t, b->m_20);
    _mm_store_ps(&L[5].x, _mm_add_ps(t, _mm_load_ps(&L[5].x)));
    *(unsigned int*)&L[5].w = 0x3f000005u;

    hkAabbUtil_calcAabb_00cbeb70(L, 6, result);
    return result;
}

struct __declspec(align(16)) S_Vec {
    float v[4];
};

struct S_00e11910_Src {
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

struct S_00e11910_Cls {
    char ValidateTriangleAndComputePlane(float* a, float* b, float* c, S_Vec* out, int normalize);
    char UpdateTriangleNormal(S_00e11910_Src* self);
};

// Computes a normalized vector from three vertex pointers offset by 4 and, on success, stores it into the struct's vector field and returns 1.
// @fnv 0x00e11910
// src: GUESS 0x00e11910 (confidence: medium)
char S_00e11910_Cls::UpdateTriangleNormal(S_00e11910_Src* self)
{
    S_Vec tmp;
    if (ValidateTriangleAndComputePlane(self->m_pVtxA + 4, self->m_pVtxB + 4, self->m_pVtxC + 4, &tmp, 1))
    {
        _mm_store_ps(self->m_vHitNormal.v, _mm_load_ps(tmp.v));
        return 1;
    }
    return 0;
}

namespace fnv_00e11a60 {
struct HkgpmeshListNodeView;

extern __m128 g_01267e30;

void __stdcall UpdateTriangleNormal(HkgpmeshListNodeView* apNode);

// distinct from ListNode: 0x00e11a60 uses a 16-byte vector at +0x20 in a 0x30-byte node; the shared list node contains only data/next pointers.
struct HkgpmeshListNodeView {
    HkgpmeshListNodeView* m_pNext;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    __m128 m_kVector;
};

struct FUN_00e11a60_cls {
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
    void ResetNodeVectors();
};

// Iterates the linked list from m_pHead, sets each node's m_kVector to g_01267e30, calls FUN_00e11910 on it, and advances via m_pNext.
// @fnv 0x00e11a60
void FUN_00e11a60_cls::ResetNodeVectors()
{
    HkgpmeshListNodeView* pNode = m_pHead;
    while (pNode) {
        pNode->m_kVector = g_01267e30;
        UpdateTriangleNormal(pNode);
        pNode = pNode->m_pNext;
    }
}
}  // namespace fnv_00e11a60



struct E11B00Vertex {
    E11B00Vertex* m_next;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4 m_vContactPosition;
};

struct E11B00Hull {
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

// Multiplies every vertex's vector by scale, then updates faces and statistics.
// @fnv 0x00e11b00
// src: GUESS 0x00e11b00 (confidence: medium)
void E11B00Hull::ScaleMeshVerticesAndUpdateStatistics(const hkVector4& scale)
{
    for (E11B00Vertex* v = m_kVertices; v; v = v->m_next)
        v->m_vContactPosition.mul4(scale);
    updateFaces();
    updateStatistics();
}

__declspec(align(16)) struct S_00e12260_Vector4
{
    float x;
    float y;
    float z;
    float w;
    S_00e12260_Vector4() {}
    void operator=(const S_00e12260_Vector4& v)
    {
        reinterpret_cast<__m128&>(*this) = reinterpret_cast<const __m128&>(v);
    }
};

struct S_00e12260_Aabb
{
    S_00e12260_Vector4 m_kMinimumCorner;
    S_00e12260_Vector4 m_kMaximumCorner;
};

struct S_00e12260_CollectorBase
{
    int m_uiItemCount;
    S_00e12260_CollectorBase() {}
    virtual void AddHit(int hit);
};
struct S_00e12260_Collector : S_00e12260_CollectorBase
{
    S_00e12260_Vector4 m_verts[3];
    S_00e12260_Collector(const S_00e12260_Vector4& a, const S_00e12260_Vector4& b, const S_00e12260_Vector4& c)
    {
        m_uiItemCount = 0;
        m_verts[0] = a;
        m_verts[1] = b;
        m_verts[2] = c;
    }
    virtual void AddHit(int hit);
};

void hkAabbUtil_calcAabb_00cbeb70(const S_00e12260_Vector4* verts, int numVerts, S_00e12260_Aabb& aabbOut);
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
    int CountTriangleTreeHits(const S_00e12260_Vector4& a, const S_00e12260_Vector4& b, const S_00e12260_Vector4& c);
};

// Builds a collector from three vertices, computes their AABB, queries the tree at unk40, and returns the collector's hit count.
// @fnv 0x00e12260
// src: GUESS 0x00e12260 (confidence: medium)
int S_00e12260::CountTriangleTreeHits(const S_00e12260_Vector4& a, const S_00e12260_Vector4& b, const S_00e12260_Vector4& c)
{
    S_00e12260_Collector collector(a, b, c);
    S_00e12260_Aabb aabb;
    hkAabbUtil_calcAabb_00cbeb70(collector.m_verts, 3, aabb);
    AabbTree_ProcessIfPresent_00d1d570(&unk40, aabb, &collector);
    return collector.m_uiItemCount;
}

namespace fnv_00e12640 {




extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* alloc, void* array, int numElements, int sizeElem);



struct E12640VectorArrayLocalForm { // local form of hkArray: 0x00e12640 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    hkVector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, this, newSize, sizeof(hkVector4));
        }
    }

    hkVector4* _expandBy(hkMemoryAllocator& alloc, int n)
    {
        int oldsize = m_iElementCount;
        GrowArrayCapacity(alloc, oldsize + n);
        m_iElementCount += n;
        return m_data + oldsize;
    }
};

struct E12640Vertex {
    E12640Vertex* m_next;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4 m_vContactPosition;
};

struct E12640Mesh {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    E12640Vertex* m_kVertices;
    int m_iStridedVertexCount;

    int hkgpMesh_fetchPositions(E12640VectorArrayLocalForm& out);
};

// @fnv 0x00e12640
// src: XBOX_PDB 0x00e12640
int E12640Mesh::hkgpMesh_fetchPositions(E12640VectorArrayLocalForm& out)
{
    int numVertices = m_iStridedVertexCount;
    hkVector4* dst = out._expandBy(hkMemoryRouter_getInstance().heap(), numVertices);
    for (E12640Vertex* v = m_kVertices; v; v = v->m_next) {
        *dst++ = v->m_vContactPosition;
    }
    return m_iStridedVertexCount;
}
}  // namespace fnv_00e12640

struct S_00e13660_Res {
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

struct FUN_00e13660_cls {
    void FindClosestMeshTriangle(unsigned int a1, S_00e13660_Res* out);
    float ProcessAndReturnValue_00e13660(unsigned int a1, __m128* out, bool* flag);
};

// @fnv 0x00e13660
// src: GUESS 0x00e13660 (confidence: low)
float FUN_00e13660_cls::ProcessAndReturnValue_00e13660(unsigned int a1, __m128* out, bool* pbFlag)
{
    __declspec(align(16)) S_00e13660_Res local;
    FindClosestMeshTriangle(a1, &local);
    float r = local.m_40;
    if (pbFlag != 0) {
        *pbFlag = local.m_44 != 0;
    }
    *out = *(__m128*)&local;
    return r;
}

namespace fnv_00e136c0 {
// FUN_00e136c0 (134 bytes) - Fallout: New Vegas
//
// The function sums a per-node 3x4 float matrix product over a linked list:
//
//   float FUN_00e136c0_cls::FUN_00e136c0()
//   {
//       float sum = 0.0f;
//       if (this->FUN_00e12920())          // list sanity check
//       {
//           for (ListNode* n = this->m_2c; n; n = n->m_00)
//           {
//               Triple t;                  // 3 x 16 bytes = one 3x4 matrix
//               OutVec  out;
//               t.r0 = n->m_08->m_10;      // three 16-byte vector loads
//               t.r1 = n->m_0c->m_10;
//               t.r2 = n->m_10->m_10;
//               __m128* r = t.FUN_00cd51c0((__m128*)&out);   // matrix * vector
//               float v;
//               _mm_store_ss(&v, *r);
//               sum = sum + v;
//           }
//           sum = (float)(sum / DAT_01034208);   // 1/6.0f
//       }
//       return sum;
//   }
//
// the for-header) makes MSVC 2008 rank the statements the way the original does.
// With `for`, the leaves of the later statements (the two pointer loads
// `mov ecx,[esi+0xc]` / `mov edx,[esi+0x10]`) are hoisted ABOVE the first
// 16-byte store, and the `lea` of the address-taken out-parameter lands BEFORE
// the second 16-byte store - exactly the original's layout. The `do { } while`
// form keeps every store adjacent to its value load and does not match.
//
// The `Triple` matrix and the `OutVec` out-parameter are address-taken locals,
// so the frame layout (0x4c), the aligned prologue and the x87 tail all fall
// out of the source shape.



extern double DAT_01034208;               // 0x01034208 = __real@4018000000000000

// A holder object: the three per-node values live in the member at +0x10.
struct VecHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    __m128 m_10;
};

// The 3x4 float matrix that is filled in and then handed to FUN_00cd51c0 as
// `this` (0x30 bytes: three 16-byte rows).
__declspec(align(16)) struct Triple
{
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

    __m128* FUN_00cd51c0(__m128* out);
};

// The 16-byte out-parameter passed on the stack to FUN_00cd51c0.
__declspec(align(16)) struct OutVec
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

// One node of the list hanging off this->m_2c.
// distinct from ListNode: 0x00e136c0 uses three vertex pointers at +8/+12/+16 in a 0x14-byte node; the shared list node contains only data/next pointers.
struct HkgpmeshListNodeView
{
    HkgpmeshListNodeView* m_00;          // next
    unsigned int unk04;
    VecHolder* m_08;
    VecHolder* m_0c;
    VecHolder* m_10;
};

class FUN_00e136c0_cls
{
public:
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
    HkgpmeshListNodeView* m_2c;

    bool hkgpMesh_isClosedManifold();
    float SumNodeTripleProducts() throw();
};

// If FUN_00e12920 succeeds, sums the first component of FUN_00cd51c0 over the m_2c node list and divides by DAT_01034208; otherwise returns 0.
// @fnv 0x00e136c0
// src: GUESS 0x00e136c0 (confidence: medium)
float FUN_00e136c0_cls::SumNodeTripleProducts() throw()
{
    float sum = 0.0f;
    if (hkgpMesh_isClosedManifold())
    {
        HkgpmeshListNodeView* node = m_2c;
        if (node != 0)
        {
            // The `for` form is what reproduces the original's scheduling.
            for ( ; node != 0; node = node->m_00)
            {
                Triple tripleVecs;
                OutVec out;
                _mm_store_ps((float*)&tripleVecs.unk00, node->m_08->m_10);
                _mm_store_ps((float*)&tripleVecs.unk10, node->m_0c->m_10);
                _mm_store_ps((float*)&tripleVecs.unk20, node->m_10->m_10);
                OutVec* pOut = &out;
                __m128* result = tripleVecs.FUN_00cd51c0((__m128*)pOut);
                float t;
                _mm_store_ss(&t, *result);
                sum = sum + t;
            }
        }
        sum = (float)(sum / DAT_01034208);
    }
    return sum;
}
}  // namespace fnv_00e136c0

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
    __forceinline bool isValid() const { return m_pkTriangle != 0; }
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
        if (n) n->m_pSecondNode = p;
        if (p) p->m_next = n;
        else m_uiBufferCapacity = n;
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
// Unlinks the triangle's three edge links and removes it from the triangle list.
// @fnv 0x00e13f10
void HullImplAN::RemoveTriangle(HullTriAN* apTriangle)
{
    for (int i = 0; i < 3; ++i)
        UnlinkAN(apTriangle->m_ppLinks[i]);
    m_uiTriangleCount.remove(apTriangle);
}

namespace fnv_00e157f0 {
extern float DAT_01267e30;

struct TargetClass {
    void ReleaseSubobject();

    char pad00[8];
    FUN_00e234e0_ m_sub8;
    char pad09[0x17];
    FUN_00e234e0_ m_sub20;
    char pad21[0xcf];
    __m128 m_vecF0;
    bool m_b100;
    bool m_b101;

    void ResetState();
};

// @fnv 0x00e157f0
void TargetClass::ResetState() {
    ReleaseSubobject();
    m_vecF0 = *(__m128*)&DAT_01267e30;
    m_sub8.FreeAllItems();
    m_sub20.FreeAllItems();
    m_b100 = false;
    m_b101 = false;
}
}  // namespace fnv_00e157f0

namespace fnv_00e191a0 {
extern __m128 DAT_01267e30;

struct SpawnedObject {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    __m128 m_v10;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    __m128 m_v30;
};

__declspec(align(16)) struct PendingBlockB {
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
    int m_40;
    int m_44;
};

struct Sub08B_cls {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    SpawnedObject* PushFront(PendingBlockB* out);
};

struct FUN_00e191a0_cls {
    unsigned int unk00;
    unsigned int unk04;
    Sub08B_cls m_08;
    void SplitEdgeWithNewVertex(void* a, unsigned int b, unsigned int c, SpawnedObject* d, int e);
    void* ProcessAndReturnValue_00e191a0(void* a1, unsigned int a2, unsigned int a3, const __m128* a4, int a5);
};

// @fnv 0x00e191a0
// src: GUESS 0x00e191a0 (confidence: low)
void* FUN_00e191a0_cls::ProcessAndReturnValue_00e191a0(void* pResult, unsigned int a2, unsigned int a3, const __m128* a4, int a5) {
    PendingBlockB tmp;
    tmp.m_40 = -1;
    tmp.m_44 = -1;
    SpawnedObject* p = m_08.PushFront(&tmp);
    p->m_v30 = DAT_01267e30;
    p->m_v10 = *a4;
    SplitEdgeWithNewVertex(pResult, *(volatile unsigned int*)&a2, *(volatile unsigned int*)&a3, p, a5);
    return pResult;
}
}  // namespace fnv_00e191a0

struct WeightedVertex {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    __m128 position;
};

struct VertexTriple {
    unsigned int unk00;
    unsigned int unk04;
    WeightedVertex* first;
    WeightedVertex* second;
    WeightedVertex* third;
};

struct FUN_00e21ed0_Class {
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

// @fnv 0x00e21ed0
void FUN_00e21ed0_Class::SelectDominantVertex(const __m128* direction, __m128* output)
{
    VertexTriple* set = vertices;
    WeightedVertex* a = set->first;
    WeightedVertex* b = set->second;
    WeightedVertex* c = set->third;
    __m128 vDirection = *direction;

    __m128 vScoreFirst = Dot3(_mm_mul_ps(a->position, vDirection));
    __m128 vScoreSecond = Dot3(_mm_mul_ps(b->position, vDirection));
    __m128 vScoreThird = Dot3(_mm_mul_ps(c->position, vDirection));

    unsigned int selected;
    if (Scalar(vScoreFirst) > Scalar(vScoreSecond))
        selected = Scalar(vScoreFirst) > Scalar(vScoreThird) ? 0 : 2;
    else
        selected = Scalar(vScoreSecond) > Scalar(vScoreThird) ? 1 : 2;

    WeightedVertex* chosen = (&set->first)[selected];
    *output = chosen->position;
    reinterpret_cast<unsigned int*>(output)[3] = 0x3f000000u | selected;
}



struct __declspec(align(16)) Float4 {
    float x;
    float y;
    float z;
    float w;
};

struct FUN_00e221e0_Vertex {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Vec4 unk10;
};

struct FUN_00e221e0_Triangle {
    int unk00;
    int unk04;
    FUN_00e221e0_Vertex* unk08;
    FUN_00e221e0_Vertex* unk0C;
    FUN_00e221e0_Vertex* unk10;
};

struct FUN_00e221e0_Input {
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

float __cdecl hkGeometryProcessing_squaredDistanceFromPointToTriangle(const Vec4* point, const Vec4* a, const Vec4* b, const Vec4* c, Float4* closest, Float4* weights);

struct FUN_00e221e0_Collector {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Vec4 unk10;
    float unk20;
    int unk24;
    int unk28;
    int unk2C;
    Vec4 unk30;
    Vec4 unk40;
    FUN_00e221e0_Triangle* unk50;

    float UpdateClosestPoint(FUN_00e221e0_Input* input);
};

// @fnv 0x00e221e0
float FUN_00e221e0_Collector::UpdateClosestPoint(FUN_00e221e0_Input* input)
{
    FUN_00e221e0_Triangle* tri = input->unk20;
    Float4 closest;
    Float4 weights;
    float dist = hkGeometryProcessing_squaredDistanceFromPointToTriangle(&unk10, &tri->unk08->unk10, &tri->unk0C->unk10, &tri->unk10->unk10, &closest, &weights);
    if (dist < unk20) {
        unk20 = dist;
        unk30.getQuad() = *(const __m128*)&closest;
        unk40.getQuad() = *(const __m128*)&weights;
        unk50 = tri;
    }
    return unk20;
}

struct PoolItemAB {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
};
struct PoolBlockAB {
    PoolItemAB m_items[32];
    int unka00;
    int m_iAllocatedCount;
};
struct BlockAllocAB {
    virtual void v00();
    virtual void v04();
    __declspec(nothrow) virtual void ReleaseBlock(void* p, int size);
};
template <int SIZE> __forceinline void MemCpyOneAB(void* dst, const void* src) { for (int i = 0; i < SIZE / 4; i++) ((unsigned int*)dst)[i] = ((const unsigned int*)src)[i]; }
template <class T> struct ArrAB {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
    __forceinline void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            MemCpyOneAB<sizeof(T)>(m_data + index, m_data + m_iElementCount);
    }
};
struct FUN_00e22f90_cls {
    ArrAB<PoolBlockAB*> m_kBlocks;
    void hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(PoolItemAB* item);
};
// @fnv 0x00e22f90
// src: XBOX_PDB 0x00e22f90
void FUN_00e22f90_cls::hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(PoolItemAB* item)
{
    if (item)
    {
        for (int i = 0; i < m_kBlocks.GetLogicalSize(); i++)
        {
            if (item >= m_kBlocks[i]->m_items && item <= &m_kBlocks[i]->m_items[31])
            {
                if (--m_kBlocks[i]->m_iAllocatedCount == 0)
                {
                    PoolBlockAB* pBlock = m_kBlocks[i];
                    ((BlockAllocAB&)meshHeap(hkMemoryRouter_getInstance())).ReleaseBlock(pBlock, sizeof(PoolBlockAB));
                    m_kBlocks.removeAt(i);
                }
                return;
            }
        }
        {
            unsigned int buf[128];
            CharBuffer ostr;
            ostr.FUN_00cb1600((char*)buf, sizeof(buf));
            ostr.ProcessAndReturnValue_00cc01c0("Item does not belong to the pool allocator");
            if (DAT_01268360->Report(3, 0x90355365, (char*)buf, "d:\\build\\20091222_000100_AiAnBeClDePh\\Source\\Common/Internal/GeometryProcessing/hkGeometryProcessing.inl", 0xaf))
                __debugbreak();
            ostr.FUN_00cc00e0();
        }
    }
}

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
#endif
extern int DAT_010eade0;
struct FUN_00e121c0_probe {
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
struct FUN_00e121c0_cls {
    float ProcessAndReturnValue_00e121c0(const __m128* a, const __m128* b, int* outI);
};
// Builds a probe from a and b minus a, calls FUN_00d1d0b0 on this+0x40, writes the probe's m_i30 to *outI if given, and returns its m_f34.
// @fnv 0x00e121c0
// src: GUESS 0x00e121c0 (confidence: low)
float FUN_00e121c0_cls::ProcessAndReturnValue_00e121c0(const __m128* a, const __m128* b, int* outI)
{
    __declspec(align(16)) FUN_00e121c0_probe t;
    __m128 va = *a;
    __m128 vd = _mm_sub_ps(*b, va);
    t.m_vptr = (int)&DAT_010eade0;
    t.m_i30 = 0;
    _mm_store_ps(&t.m_v10x, va);
    _mm_store_ps(&t.m_v20x, vd);
    t.m_f34 = 1.0f;
    hkVector4_VisitRayIntersectedTreeLeaves((char*)this + 0x40, a, b, &t, 1.0f);
    int v = t.m_i30;
    float r = t.m_f34;
    if (outI != 0) {
        *outI = v;
    }
    return r;
}

inline const S_00e13910_Edge& nullMeshEdge() {
    static S_00e13910_Edge edge(0, 0);
    return edge;
}
struct TriangleNode {
    TriangleNode* m_next;
    TriangleNode* m_pSecondNode;
};

struct TrianglePool {
    int unk00;
    int unk04;
    int unk08;
    TriangleNode* m_pFirstNode;
    int m_uiItemCount;

    void hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(void* p);
    __forceinline void remove(TriangleNode* t) {
        TriangleNode* next = t->m_next;
        TriangleNode* prev = t->m_pSecondNode;
        if (next) next->m_pSecondNode = prev;
        if (prev) prev->m_next = next;
        else m_pFirstNode = next;
        m_uiItemCount--;
        hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(t);
    }
};

static __forceinline void bind(S_00e13910_Edge a, S_00e13910_Edge b) {
    if (b.isValid()) {
        S_00e13910_Edge temp = a;
        a = b;
        b = temp;
    }
    if (a.isValid()) {
        a.bind(b);
    }
}

struct EdgeMesh {
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

// For three edge steps rebinds each edge's linked neighbours and clears the links, then removes both edges' triangles from the pool and returns true.
// @fnv 0x00e12e10
bool EdgeMesh::UnbindEdgePair(S_00e13910_Edge a, S_00e13910_Edge b) {
    struct TrianglePair {
        S_00e13910_Triangle* first;
        S_00e13910_Triangle* second;
    } saved;
    saved.first = a.m_pkTriangle;
    saved.second = b.m_pkTriangle;
    for (int i = 0; i < 3; ++i) {
        if (a.m_pkTriangle != b.link().m_pkTriangle) {
            S_00e13910_Edge c = a.link();
            S_00e13910_Edge d = b.link();
            if (d.isValid()) {
                S_00e13910_Edge temp = c;
                c = d;
                d = temp;
            }
            if (c.isValid()) c.bind(d);
        }
        b.bind(nullMeshEdge());
        a.bind(nullMeshEdge());
        a = a.next();
        b = b.prev();
    }
    m_uiTriangleCount.remove((TriangleNode*)saved.first);
    m_uiTriangleCount.remove((TriangleNode*)saved.second);
    return true;
}

hkMemoryRouter* __cdecl GetMemoryRouterE15() throw();
void __cdecl ReserveMoreE15(hkMemoryAllocator* pkHeap, void* pkArray, int iElemSize);
template <typename T>
inline void ConstructWithCopyE15(T* pDst, int iCount, const T& kItem)
{
    for (int i = 0; i < iCount; ++i)
        pDst[i] = kItem;
}
template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    hkMemoryRouter* pkRouter = GetMemoryRouterE15();
    hkMemoryAllocator* pkHeap = pkRouter->m_heap;
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        pkHeap->bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
}

template <typename T>
__forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& kItem)
{
    if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        ReserveMoreE15(&alloc, this, sizeof(T));
    ConstructWithCopyE15(m_data + m_iElementCount, 1, kItem);
    m_iElementCount++;
}
// This overlap path copies vector storage as four words, as in the original scalar copy.
static __forceinline void copyOverlapPosition(hkVector4& destination, const hkVector4& source) {
    unsigned int* out = reinterpret_cast<unsigned int*>(&destination);
    const unsigned int* in = reinterpret_cast<const unsigned int*>(&source);
    out[0] = in[0]; out[1] = in[1]; out[2] = in[2]; out[3] = in[3];
}
struct TriangleE15 {
    hkVector4 m_kVertices[3];
};
struct VertexE15 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4 m_vContactPosition;
};
struct TriangleEntryE15 {
    int unk00;
    int unk04;
    VertexE15* m_pkVertices[3];
};
void __cdecl CalcAabbE15(const hkVector4* pkPoints, int iNumPoints, hkAabb& kAabbOut);
int __cdecl TrianglesOverlapE15(const TriangleE15* pkA, const TriangleE15* pkB);
class AabbCollectorE15 {
public:
    virtual void AddHit(TriangleEntryE15* pkEntry);
    hkArray<TriangleEntryE15*> m_kHits;
};
struct BroadPhaseE15 {
};
void __cdecl QueryAabbE15(BroadPhaseE15* pkBroadPhase, const hkAabb& kAabb, AabbCollectorE15* pkCollector);
class TriangleQueryE15 {
public:
    void hkgpMesh_enumerateTriangleOverlaps(const hkVector4& kA, const hkVector4& kB, const hkVector4& kC, hkArray<TriangleEntryE15*>* pkOverlapsOut) throw();
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

// Builds a triangle from kA, kB, kC, queries the broad phase for AABB hits, and adds entries whose triangles overlap to pkOverlapsOut.
// @fnv 0x00e15220
// src: HAVOK_LIB 0x00e15220
void TriangleQueryE15::hkgpMesh_enumerateTriangleOverlaps(const hkVector4& kA, const hkVector4& kB, const hkVector4& kC, hkArray<TriangleEntryE15*>* pkOverlapsOut) throw()
{
    AabbCollectorE15 kCollector;
    TriangleE15 kTriangle;
    copyOverlapPosition(kTriangle.m_kVertices[0], kA);
    copyOverlapPosition(kTriangle.m_kVertices[1], kB);
    copyOverlapPosition(kTriangle.m_kVertices[2], kC);
    hkAabb kAabb;
    CalcAabbE15(kTriangle.m_kVertices, 3, kAabb);
    QueryAabbE15(&m_kBroadPhase, kAabb, &kCollector);
    for (int i = 0; i < kCollector.m_kHits.m_iElementCount; i++)
    {
        TriangleE15 kOther;
        copyOverlapPosition(kOther.m_kVertices[0], kCollector.m_kHits.m_data[i]->m_pkVertices[0]->m_vContactPosition);
        copyOverlapPosition(kOther.m_kVertices[1], kCollector.m_kHits.m_data[i]->m_pkVertices[1]->m_vContactPosition);
        copyOverlapPosition(kOther.m_kVertices[2], kCollector.m_kHits.m_data[i]->m_pkVertices[2]->m_vContactPosition);
        if (TrianglesOverlapE15(&kTriangle, &kOther))
            pkOverlapsOut->pushBack(kCollector.m_kHits.m_data[i]);
    }
}

namespace fnv_00e15ab0 {
inline const S_00e13910_Edge& nullMeshEdge() {
    static S_00e13910_Edge edge(0, 0);
    return edge;
}
struct MeshFaceList {
    int unk00, unk04, unk08;
    S_00e13910_Triangle* tail;
    int count;
    void hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(S_00e13910_Triangle* face);
    __forceinline void remove(S_00e13910_Triangle* face) {
        S_00e13910_Triangle* previous = (S_00e13910_Triangle*)face->m_unk00;
        S_00e13910_Triangle* next = (S_00e13910_Triangle*)face->m_unk04;
        if (previous) previous->m_unk04 = (int)next;
        if (next) next->m_unk00 = (int)previous;
        else tail = previous;
        --count;
        hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(face);
    }
};
struct FanAnchor474 { S_00e13910_Triangle* triangle; void* vertex; unsigned int index; };
struct EdgeMesh {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    MeshFaceList faces;
    void UpdateTriangleNormal(S_00e13910_Triangle*);
    void RemoveEdge(S_00e13910_Edge edge, bool notify);
};
// Removes the given edge and its opposite from the mesh, updating adjacent links and removing the associated triangles from faces.
// @fnv 0x00e15ab0
void EdgeMesh::RemoveEdge(S_00e13910_Edge edge, bool notify)
{
    FanAnchor474 anchor;
anchor.triangle = edge.m_pkTriangle;
anchor.index = edge.m_uiEdgeIndex;
anchor.vertex = anchor.triangle->m_kVertices[(9 >> (2*anchor.index)) & 3];
_ReadWriteBarrier();
    S_00e13910_Edge cursor(anchor.triangle, anchor.index);
    do {
        cursor.start() = anchor.vertex;
        if (notify) UpdateTriangleNormal(cursor.m_pkTriangle);
        cursor = cursor.prev().link();
    } while (cursor.isValid() && (unsigned int)cursor.m_pkTriangle + cursor.m_uiEdgeIndex != (unsigned int)anchor.triangle + anchor.index);
    if (!cursor.isValid()) {
        cursor = S_00e13910_Edge(anchor.triangle->m_ppLinks[anchor.index]).next();
        while (cursor.isValid()) {
            cursor.start() = anchor.vertex;
            if (notify) UpdateTriangleNormal(cursor.m_pkTriangle);
            cursor = cursor.link().next();
        }
    }
    S_00e13910_Edge opposite = edge.link();
    if (opposite.isValid()) {
        S_00e13910_Edge a = opposite.next().link();
        S_00e13910_Edge b = opposite.prev().link();
        if (b.isValid()) {
            S_00e13910_Edge temp = a;
            a = b;
            b = temp;
        }
        if (a.isValid()) {
            a.bind(b);
            opposite.next().bind(nullMeshEdge());
            opposite.prev().bind(nullMeshEdge());
        }
        unsigned int packedLink = opposite.m_pkTriangle->m_ppLinks[opposite.m_uiEdgeIndex];
        if (packedLink & ~3u) {
            S_00e13910_Edge linked(packedLink);
            linked.m_pkTriangle->m_ppLinks[linked.m_uiEdgeIndex] = 0;
        }
        opposite.m_pkTriangle->m_ppLinks[opposite.m_uiEdgeIndex] = 0;
        faces.remove(opposite.m_pkTriangle);
    }
    S_00e13910_Edge a = edge.next().link();
    S_00e13910_Edge b = edge.prev().link();
    if (b.isValid()) {
        S_00e13910_Edge temp = a;
        a = b;
        b = temp;
    }
    if (a.isValid()) {
        a.bind(b);
        edge.next().bind(nullMeshEdge());
        edge.prev().bind(nullMeshEdge());
    }
    faces.remove(edge.m_pkTriangle);
}
}  // namespace fnv_00e15ab0



struct FUN_00e21d40_cls {
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

// Compares the dot product of dir against m_10 and m_20, then stores the one with the larger product into out.
// @fnv 0x00e21d40
// src: XBOX_PDB 0x00e21d40
void FUN_00e21d40_cls::hkgpMesh_LineShape_getSupportingVertex(const hkVector4* dir, hkVector4* out)
{
    float da = DotProduct3(dir->v, m_10.v);
    float db = DotProduct3(m_20.v, dir->v);
    if (da > db) {
        out->v = m_10.v;
    } else {
        out->v = m_20.v;
    }
}

struct T27Node {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned int m_ppLinks[3];
};

struct T27Edge {
    T27Node* m_node;
    unsigned int m_uiEdgeIndex;
};

inline T27Edge T27MakeEdge(unsigned int packed) {
    T27Edge e;
    e.m_uiEdgeIndex = packed & 3;
    e.m_node = (T27Node*)(packed & 0xfffffffc);
    return e;
}

struct T27Slot {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void Assign(unsigned int value);
};

struct T27Item {
    char m_enabled;
    char unk01;
    char unk02;
    char unk03;
    T27Slot m_data;
};

struct T27Cls {
    unsigned int LookupPairResult(T27Edge* path);
    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_clearEdgeData(T27Edge* path);
    unsigned __int64 hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_backupBothEdgeData(T27Edge edge, T27Item* items);
};

// @fnv 0x00e27ae0
// src: HAVOK_LIB 0x00e27ae0
unsigned __int64 T27Cls::hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_backupBothEdgeData(T27Edge edge, T27Item* items) {
    items[0].m_enabled = 0;
    items[1].m_enabled = 0;

    union {
        unsigned __int64 bits;
        struct {
            unsigned int last;
            T27Node* previous;
        } parts;
    } result;
    for (int i = 0; i < 2; ++i, ++items) {
        unsigned int value = LookupPairResult(&edge);
        if (value != 0) {
            items->m_data.Assign(value);
            items->m_enabled = 1;
            hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_clearEdgeData(&edge);
        }

        T27Node* node = ((volatile T27Edge*)&edge)->m_node;
        unsigned int index = edge.m_uiEdgeIndex;
        unsigned int packed = node->m_ppLinks[index];
        result.parts.previous = node;
        result.parts.last = packed;
        if ((packed & 0xfffffffc) == 0)
            break;

        edge = T27MakeEdge((unsigned int)packed);
        result.parts.last = (unsigned int)edge.m_node;
    }
    return result.bits;
}



struct FUN_00c7f640_Obj {
    int x;
    int y;
    int z;
    int w;

    void __thiscall setTransformedPos_00c7f640(int value, hkVector4* data);
};

struct S_00e11a90_Node {
    S_00e11a90_Node* next;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00c7f640_Obj vec;
};

struct S_00e11a90_Class {
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

// Applies value to each node's vector via FUN_00c7f640, then resets node vectors and releases the subobject.
// @fnv 0x00e11a90
// src: GUESS 0x00e11a90 (confidence: low)
void S_00e11a90_Class::ProcessEntries_00e11a90(int value) {
    for (S_00e11a90_Node* node = head; node != 0; node = node->next) {
        FUN_00c7f640_Obj* source = &node->vec;
        const int* values = &source->x;
        hkVector4 data;

        reinterpret_cast<int*>(&data)[0] = values[0];
        reinterpret_cast<int*>(&data)[1] = values[1];
        reinterpret_cast<int*>(&data)[2] = values[2];
        reinterpret_cast<int*>(&data)[3] = values[3];

        source->setTransformedPos_00c7f640(value, &data);
    }

    ResetNodeVectors();
    ReleaseSubobject();
}

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sqrt_ss(__m128 a);
#endif

struct S_00e12360_Vtx {
    int unk00, unk04, unk08, unk0c;
    __m128 pos;
};
struct S_00e12360_Node {
    S_00e12360_Node* next;
    S_00e12360_Node* prev;
    S_00e12360_Vtx* v0;
    S_00e12360_Vtx* v1;
    S_00e12360_Vtx* v2;
};
struct S_00e12360_Mesh {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28;
    S_00e12360_Node* head;
};

__forceinline float S_00e12360_Len(const S_00e12360_Node* n)
{
    __m128 a = n->v0->pos;
    __m128 e1 = _mm_sub_ps(n->v1->pos, a);
    __m128 e2 = _mm_sub_ps(n->v2->pos, a);
    __m128 c = _mm_sub_ps(
        _mm_mul_ps(_mm_shuffle_ps(e2, e2, 0xd2), _mm_shuffle_ps(e1, e1, 0xc9)),
        _mm_mul_ps(_mm_shuffle_ps(e2, e2, 0xc9), _mm_shuffle_ps(e1, e1, 0xd2)));
    __m128 sq = _mm_mul_ps(c, c);
    __m128 d = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
    float r;
    _mm_store_ss(&r, _mm_sqrt_ss(d));
    return r;
}

struct S_00e12360_This : S_00e12360_Mesh {
    void SortNodesByTriangleMagnitude(float scale);
};

// Bubble-sorts the node list so nodes with the larger scaled cross-product magnitude of their three vertices come first.
// @fnv 0x00e12360
// src: GUESS 0x00e12360 (confidence: medium)
void S_00e12360_This::SortNodesByTriangleMagnitude(float scale)
{
    bool swapped;
    do {
        S_00e12360_Node* cur = head;
        float m = S_00e12360_Len(cur) * scale;
        swapped = false;
        while (cur->next) {
            S_00e12360_Node* nx = cur->next;
            float mn = S_00e12360_Len(nx) * scale;
            if (mn > m) {
                S_00e12360_Node* p = nx->prev;
                if (p) {
                    S_00e12360_Node* s = nx->next;
                    S_00e12360_Node* e = p->prev;
                    if (s) { s->prev = p; p->next = s; } else p->next = 0;
                    if (e) { e->next = nx; nx->prev = e; } else { head = nx; nx->prev = 0; }
                    p->prev = nx;
                    nx->next = p;
                }
                swapped = true;
            }
            m = mn;
            cur = nx;
        }
    } while (swapped);
}

struct HullFloodTriangle {
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
inline void* operator new(unsigned int, void* storage) { return storage; }
struct HullFloodEdge {
    HullFloodTriangle* m_node;
    int m_k;
    HullFloodEdge(HullFloodTriangle* node,int k):m_node(node),m_k(k) {}
};
void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize);
struct HullFloodStack {
    HullFloodEdge* m_data;
    int m_iElementCount;
    unsigned int m_cap;
    void release(Allocator& heap);
    void AddBack(const HullFloodEdge& edge);
};
inline void HullFloodStack::release(Allocator& heap) {
    m_iElementCount = 0;
    if (!(m_cap & 0x80000000)) heap.freeBlock(m_data, (m_cap & 0x3fffffff) * 8);
}
inline void HullFloodStack::AddBack(const HullFloodEdge& edge) {
    hkMemoryRouter& mgr = hkMemoryRouter_getInstance();
    if (m_iElementCount == (int)(m_cap & 0x3fffffff)) ResizeAudioStream(reinterpret_cast<Allocator*>(mgr.m_heap), this, sizeof(HullFloodEdge));
    ::new (static_cast<void*>(m_data + m_iElementCount)) HullFloodEdge(edge);
    m_iElementCount++;
}
struct HullConnectivity {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28;
    HullFloodTriangle* m_pFirstNode;
    int hkgpMesh_floodFillDetachedParts();
};
// Performs a flood fill over the hull triangle list, assigning a component index to each visited triangle and returning the total component count.
// @fnv 0x00e12960
// src: HAVOK_LIB 0x00e12960
int HullConnectivity::hkgpMesh_floodFillDetachedParts() {
    int counter = 0;
    for (HullFloodTriangle* n = m_pFirstNode; n; n = n->m_next) n->m_vis = -1;
    HullFloodStack stack;
    stack.m_data = 0;
    stack.m_iElementCount = 0;
    stack.m_cap = 0x80000000;
    for (HullFloodTriangle* cur = m_pFirstNode; cur; cur = cur->m_next) {
        if (cur->m_vis != -1) continue;
        stack.m_iElementCount = 0;
        stack.AddBack(HullFloodEdge(cur, 0));
        stack.AddBack(HullFloodEdge(cur, 1));
        stack.AddBack(HullFloodEdge(cur, 2));
        cur->m_vis = counter;
        counter++;
        do {
            HullFloodEdge e = stack.m_data[stack.m_iElementCount - 1];
            int tagged = e.m_node->m_ppLinks[e.m_k];
            e.m_k = tagged & 3;
            e.m_node = (HullFloodTriangle*)(tagged & ~3);
            stack.m_iElementCount--;
            if (!e.m_node) continue;
            if (e.m_node->m_vis != -1) continue;
            int tt = e.m_k + e.m_k;
            int a = (9 >> tt) & 3;
            e.m_node->m_vis = counter - 1;
            stack.AddBack(HullFloodEdge(e.m_node, a));
            int b = (18 >> tt) & 3;
            stack.AddBack(HullFloodEdge(e.m_node, b));
        } while (stack.m_iElementCount != 0);
    }
    stack.release(meshHeap(hkMemoryRouter_getInstance()));
    return counter;
}

struct Vertex {
    Vertex* m_next;
    Vertex* m_pSecondNode;
};

struct Triangle {
    Triangle* m_next;
    unsigned int unk04;
    Vertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
};

static inline int nextIndex(int i) { return (9 >> (i << 1)) & 3; }

struct Edge {
    Triangle* m_pkTriangle;
    int m_uiEdgeIndex;

    Edge(Triangle* triangle, int index) : m_pkTriangle(triangle), m_uiEdgeIndex(index) {}
    unsigned int uid() const { return (unsigned int)m_pkTriangle + m_uiEdgeIndex; }
    bool isNaked() const { return (m_pkTriangle->m_ppLinks[m_uiEdgeIndex] & ~3u) == 0; }
    Vertex* start() const { return m_pkTriangle->m_kVertices[m_uiEdgeIndex]; }
    Vertex* end() const { return m_pkTriangle->m_kVertices[nextIndex(m_uiEdgeIndex)]; }
    void bind(const Edge& other) const
    {
        m_pkTriangle->m_ppLinks[m_uiEdgeIndex] = other.uid();
        other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = uid();
    }
};

void __cdecl ResizeAudioStream(void*, void*, int);

template <typename T>
struct HullWorkArrayLocalForm { // local form of hkArray: 0x00e12bc0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    HullWorkArrayLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    void ClearAndRelease()
    {
        Allocator& heap = meshHeap(hkMemoryRouter_getInstance());
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0) heap.freeBlock(m_data, (cap & 0x3fffffff) * sizeof(T));
    }
    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
    void AddBack(const T& t)
    {
        hkMemoryRouter& router = hkMemoryRouter_getInstance();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff)) ResizeAudioStream(reinterpret_cast<Allocator*>(router.m_heap), this, sizeof(T));
        m_data[m_iElementCount] = t;
        m_iElementCount++;
    }
};

struct VertexList {
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
        if (next) next->m_pSecondNode = prev;
        if (prev) prev->m_next = next;
        else m_pFirstNode = next;
        --m_uiItemCount;
        hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(vertex);
    }
};

struct HullMesh {
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

// Replaces vertex 'from' with 'to' in all triangles, binds matching naked edges between affected triangles, then removes 'from' from the vertex list.
// @fnv 0x00e12bc0
// src: HAVOK_LIB 0x00e12bc0
void HullMesh::hkgpMesh_replaceVertex(Vertex* from, Vertex* to)
{
    HullWorkArrayLocalForm<Triangle*> affected;
    for (Triangle* t = m_uiTriangleCount; t; t = t->m_next)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (t->m_kVertices[i] == from)
            {
                affected.AddBack(t);
                t->m_kVertices[i] = to;
            }
            else if (t->m_kVertices[i] == to)
            {
                affected.AddBack(t);
            }
        }
    }
    for (int i = 0; i < affected.GetLogicalSize(); ++i)
    {
        Triangle* a = affected[i];
        for (int j = i + 1; j < affected.GetLogicalSize(); ++j)
        {
            Triangle* b = affected[j];
            for (int k = 0; k < 3; ++k)
            {
                Edge e0(a, k);
                if (!e0.isNaked()) continue;
                for (int l = 0; l < 3; ++l)
                {
                    Edge e1(b, l);
                    if (e1.isNaked() && e0.start() == e1.end() && e0.end() == e1.start())
                    {
                        e0.bind(e1);
                    }
                }
            }
        }
    }
    m_kVertices.remove(from);
    affected.ClearAndRelease();
}

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ss(const float *p);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_set_ps1(float f);
#endif

extern const float DAT_0104a494;
extern float DAT_0106c2e0;



struct S_00e14160_Node {
    S_00e14160_Node* m_next;
    int unk04;
    int unk08;
    int unk0c;
    hkVector4 m_pos;
};

struct S_00e14160_Tri {
    S_00e14160_Tri* m_next;
    int unk04;
    S_00e14160_Node* m_kPointA;
    S_00e14160_Node* m_kPointB;
    S_00e14160_Node* m_iThirdValue;
};

struct S_00e14160 {
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

// Sums the square roots of FUN_00e13660 results for points built from dir and each node position and triangle centroid, stopping once the total reaches limit.
// @fnv 0x00e14160
// src: GUESS 0x00e14160 (confidence: medium)
float S_00e14160::AccumulateNodeDistancesToLimit(const hkVector4& dir, float limit)
{
    float total = 0.0f;
    for (S_00e14160_Node* n = m_kNodeCollection; n; n = n->m_next) {
        __m128 v = n->m_pos.q();
        __m128 d = _mm_mul_ss(S_dot3(dir.q(), v), _mm_load_ss(&DAT_0104a494));
        hkVector4 p;
        hkVector4 out;
        p.q() = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(d, d, 0), dir.q()), v);
        total += (float)sqrt((double)ProcessAndReturnValue_00e13660(p, &out, 0));
        if (total >= limit) break;
    }
    for (S_00e14160_Tri* t = m_tris; t; t = t->m_next) {
        __m128 c = _mm_add_ps(_mm_add_ps(t->m_kPointA->m_pos.q(), t->m_kPointB->m_pos.q()), t->m_iThirdValue->m_pos.q());
        __m128 k = _mm_load_ss(&DAT_0106c2e0);
        __m128 v = _mm_mul_ps(c, _mm_shuffle_ps(k, k, 0));
        __m128 d = _mm_mul_ss(S_dot3(dir.q(), v), _mm_load_ss(&DAT_0104a494));
        hkVector4 p;
        hkVector4 out;
        p.q() = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(d, d, 0), dir.q()), v);
        total += (float)sqrt((double)ProcessAndReturnValue_00e13660(p, &out, 0));
        if (total >= limit) break;
    }
    return total;
}

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_setzero_ps(void);
#endif





struct E142Hull {
    const MeshPacketCallLocal_00e16e50* hkgpConvexHull_getCenterOfMass();
};

void __cdecl Geometry_MapCoordinatesToSphere(const hkVector4* in, hkVector4* out);

struct E142Obj {
    E142Hull* GetConvexHull();
    float AccumulateNodeDistancesToLimit(const hkVector4& dir, float bound);
    float FindMinimumByRefiningGridSearch(hkVector4& out);
};

static inline float E142ToReal(__m128 v) { float f; _mm_store_ss(&f, v); return f; }

// Runs seven rounds of a refining 4x4 grid search, evaluating FUN_00e14160 per sample and keeping the sample with the smallest result in out; returns that result.
// @fnv 0x00e142d0
// src: GUESS 0x00e142d0 (confidence: medium)
float E142Obj::FindMinimumByRefiningGridSearch(hkVector4& out)
{
    MeshPacketCallLocal_00e16e50 V = *GetConvexHull()->hkgpConvexHull_getCenterOfMass();
    float lo[2];
    float hi[2];
    lo[0] = 0.0f;
    lo[1] = 0.0f;
    hi[0] = 1.0f;
    hi[1] = 1.0f;
    __m128 zero = _mm_setzero_ps();
    float best;
    int n = 7;
    do
    {
        float w = (float)((hi[0] - lo[0]) * 0.25);
        float h = (float)(w * 0.5);
        float d = hi[0] - lo[0];
        int bestIdx[2];
        bestIdx[0] = 0;
        bestIdx[1] = 0;
        best = DAT_0104da48;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                hkVector4 P;
                P.q() = zero;
                P.x = (float)(j * 0.25 * d + lo[0] + h);
                P.y = (float)(i * 0.25 * d + lo[1] + h);
                hkVector4 Q;
                Geometry_MapCoordinatesToSphere(&P, &Q);
                __m128 t = _mm_sub_ss(DAT_010c7160, Q.dot3(*reinterpret_cast<const hkVector4*>(&V)).m_vValue);
                Q.w = E142ToReal(t);
                float r = AccumulateNodeDistancesToLimit(Q, best);
                if (r < best)
                {
                    best = r;
                    out = Q;
                    bestIdx[0] = j;
                    bestIdx[1] = i;
                }
            }
        }
        lo[0] += bestIdx[0] * 0.25 * d;
        lo[1] += bestIdx[1] * 0.25 * d;
        hi[0] = w + lo[0];
    } while (--n);
    return best;
}

struct E14a90Node {
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

struct E14a90List {
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

struct E14a90Owner {
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

// Marks vertices referenced by m_tris, removes unmarked nodes from m_verts, calls ReleaseSubobject if any were removed, and returns the count removed.
// @fnv 0x00e14a90
// src: HAVOK_LIB 0x00e14a90
int E14a90Owner::hkgpMesh_removeOrphanVertices()
{
    int numRemoved = 0;
    E14a90Node* v;
    for (v = m_verts.m_pFirstNode; v; v = v->m_next)
        v->m_mark = 0.0f;
    for (E14a90Node* t = m_tris; t; t = t->m_next) {
        E14a90Node* a = t->m_v0;
        E14a90Node* b = t->m_v1;
        E14a90Node* c = t->m_v2;
        a->m_mark = 1.0f;
        b->m_mark = 1.0f;
        c->m_mark = 1.0f;
    }
    v = m_verts.m_pFirstNode;
    while (v) {
        E14a90Node* cur = v;
        v = v->m_next;
        if (cur->m_mark == 0.0f) {
            m_verts.remove(cur);
            numRemoved++;
        }
    }
    if (numRemoved)
        ReleaseSubobject();
    return numRemoved;
}

template<class T> __forceinline void SwapVertices(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ss(const float*);
#endif

extern float DAT_01012054;

void __cdecl ResizeAudioStream(void* alloc, void* sizePtr, int elemSize) throw();

struct EdgeNode : S_00e13910_Triangle {
    __m128 m_20;
    int m_30;
};

typedef S_00e13910_Edge PairItem;

struct PairArray {
    PairItem* m_data;
    int m_iElementCount;
    int m_cap;
};

struct EdgeMeshFlip {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    EdgeNode* m_2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c;
    int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac;
    int unkb0; int unkb4; int unkb8; int unkbc;
    int unkc0; int unkc4; int unkc8; int unkcc;
    int unkd0; int unkd4; int unkd8; int unkdc;
    int unke0; int unke4; int unke8; int unkec;
    int unkf0; int unkf4; int unkf8; int unkfc;
    unsigned char unk100;
    unsigned char m_101;

    void hkgpMesh_bindEdgeList(PairArray* arr);
    void hkgpMesh_flipPartOrientation(int a1);
};

// For nodes whose m_30 equals a1, scales m_20, swaps the first two vertices and clears edge links, then passes the collected edges to FUN_00e124d0.
// @fnv 0x00e150e0
// src: XBOX_PDB 0x00e150e0
void EdgeMeshFlip::hkgpMesh_flipPartOrientation(int a1) {
    PairArray arr;
    arr.m_data = 0;
    arr.m_iElementCount = 0;
    arr.m_cap = 0x80000000;

    EdgeNode* n = m_2c;
    if (n != 0) {
        do {
            if (n->m_30 == a1) {
                __m128 tsc = _mm_load_ss(&DAT_01012054);
                __m128 sc = _mm_shuffle_ps(tsc, tsc, 0);
                n->m_20 = _mm_mul_ps(n->m_20, sc);
                for (int i = 0; i < 3; ++i) {
                    hkMemoryRouter& r = hkMemoryRouter_getInstance();
                    if (arr.m_iElementCount == (int)(arr.m_cap & 0x3fffffff)) {
                        ResizeAudioStream(reinterpret_cast<Allocator*>(r.m_heap), (int*)&arr.m_data, 8);
                    }
                    PairItem* p = &arr.m_data[arr.m_iElementCount];
                    if (p != 0) {
                        p->m_pkTriangle = (S_00e13910_Triangle*)n;
                        p->m_uiEdgeIndex = (unsigned int)i;
                    }
                    arr.m_iElementCount++;
                }
                SwapVertices(n->m_kVertices[0], n->m_kVertices[1]);
            }
            n = (EdgeNode*)n->m_unk00;
        } while (n != 0);
    }

    for (int k = 0; k < arr.m_iElementCount; ++k) {
        PairItem& pr = arr.m_data[k];
        unsigned int v = pr.m_pkTriangle->m_ppLinks[pr.m_uiEdgeIndex];
        if ((v & ~3u) != 0) {
            PairItem other(v);
            other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = 0;
        }
        pr.m_pkTriangle->m_ppLinks[pr.m_uiEdgeIndex] = 0;
    }

    this->hkgpMesh_bindEdgeList(&arr);
    this->m_101 = 0;

    hkMemoryRouter& r2 = hkMemoryRouter_getInstance();
    Allocator* alloc = reinterpret_cast<Allocator*>(r2.m_heap);
    int cap = arr.m_cap;
    arr.m_iElementCount = 0;
    if ((cap & 0x80000000) == 0) {
        alloc->freeBlock(arr.m_data, (cap & 0x3fffffff) * 8);
    }
}

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
#endif
void __cdecl ResizeAudioStream(void* alloc, void* array, int elemSize);



template <class T>
__forceinline void E153F0ConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

struct E153F0PointsLocalForm
{ // local form of hkArray: 0x00e153f0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    hkVector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    E153F0PointsLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void reserve(int n)
    {
        Allocator& alloc = meshHeap(hkMemoryRouter_getInstance());
        int cap = getCapacity();
        if (cap < n)
        {
            int newCap = 2 * cap;
            hkArrayUtil__reserve((int)&alloc, this, n < newCap ? newCap : n, sizeof(hkVector4));
        }
    }
    void AddBack(const hkVector4& t)
    {
        Allocator& alloc = meshHeap(hkMemoryRouter_getInstance());
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(hkVector4));
        E153F0ConstructWithCopy(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    void ClearAndRelease(Allocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.freeBlock(m_data, getCapacity() * sizeof(hkVector4));
    }
};

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

    static int next(int i) { return (9 >> (i << 1)) & 3; }
    const hkVector4& start() const { return ((E153F0Vertex*)m_face->m_kVertices[m_uiEdgeIndex])->m_vContactPosition; }
    const hkVector4& end() const { return ((E153F0Vertex*)m_face->m_kVertices[next(m_uiEdgeIndex)])->m_vContactPosition; }
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


// Returns the sum of the x, y and z extents of the AABB around all edge start and end points, or 0.0f if the edge set is empty.
// @fnv 0x00e153f0
// src: XBOX_PDB 0x00e153f0
float __cdecl getLoopSurfaceArea(const E153F0Edges* edges)
{
    if (edges->m_iElementCount != 0)
    {
        E153F0PointsLocalForm points;
        points.reserve(edges->m_iElementCount * 2);
        for (int i = 0; i < edges->m_iElementCount; i++)
        {
            points.AddBack(edges->m_data[i].start());
            points.AddBack(edges->m_data[i].end());
        }

        E153F0Aabb aabb;
        hkAabbUtil_calcAabb_00cbeb70(points.m_data, points.m_iElementCount, &aabb);
        __m128 extent = _mm_sub_ps(aabb.m_kMaximumCorner.m_vComponents, aabb.m_kMinimumCorner.m_vComponents);
        float result;
        _mm_store_ss(&result, _mm_add_ss(_mm_shuffle_ps(extent, extent, 0xaa), _mm_add_ss(_mm_shuffle_ps(extent, extent, 0x55), extent)));

        points.ClearAndRelease(meshHeap(hkMemoryRouter_getInstance()));
        return result;
    }
    return 0.0f;
}

struct __declspec(align(16)) VecE21F {
    float x, y, z, w;
};

struct __declspec(align(16)) AabbE21F {
    VecE21F m_kMinimumCorner;
    VecE21F m_kMaximumCorner;
};

void __cdecl hkAabbUtil_calcAabb_00cbeb70(const VecE21F* pElementBuffer, int iNumPoints, AabbE21F& kAabbOut);

struct VertE21F {
    int unk;
    int unkCur;
    int unkValue;
    int unk0c;
    VecE21F m_pos;
};

struct TriE21F {
    int unk;
    int unkCur;
    VertE21F* m_verts[3];
};

class FUN_00e21fc0_cls {
public:
    int unk;
    TriE21F* m_tri;

    AabbE21F hkgpMesh_TriangleShape_getBoundingBox() const;
};

// Computes and returns the axis-aligned bounding box of the three vertices referenced by m_tri.
// @fnv 0x00e21fc0
// src: HAVOK_LIB 0x00e21fc0
AabbE21F FUN_00e21fc0_cls::hkgpMesh_TriangleShape_getBoundingBox() const
{
    VecE21F verts[3];
    verts[0] = m_tri->m_verts[0]->m_pos;
    verts[1] = m_tri->m_verts[1]->m_pos;
    verts[2] = m_tri->m_verts[2]->m_pos;
    AabbE21F kAabb;
    hkAabbUtil_calcAabb_00cbeb70(verts, 3, kAabb);
    return kAabb;
}

struct FUN_00e226b0_cls {
    unsigned int unk00;
    SceneSet* m_04;
    void FindSupportingBoneCandidate(SceneVec* v, SceneVec* out);
};

static __forceinline float SceneDot3(const SceneVec* a, const SceneVec* b) {
    __m128 p = _mm_load_ps(&a->x); p = _mm_mul_ps(p, *(__m128*)b);
    __m128 yx = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    __m128 r = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), yx);
    float f;
    _mm_store_ss(&f, r);
    return f;
}

static __forceinline void SceneCopyBone(volatile SceneVec* dst, const SceneBone* b) {
    *(volatile unsigned int*)&dst->x = *(const unsigned int*)&b->m_10.x;
    *(volatile unsigned int*)&dst->y = *(const unsigned int*)&b->m_10.y;
    *(volatile unsigned int*)&dst->z = *(const unsigned int*)&b->m_10.z;
    *(volatile unsigned int*)&dst->w = *(const unsigned int*)&b->m_10.w;
}

// Picks the candidate (two per bone for three bones) with the largest dot product against v, storing it in out with its index encoded in w.
// @fnv 0x00e226b0
// src: GUESS 0x00e226b0 (confidence: medium)
void FUN_00e226b0_cls::FindSupportingBoneCandidate(SceneVec* v, SceneVec* out) {
    __declspec(align(16)) SceneVec L;
    SceneBone* ptr = m_04->m_08;

    *(volatile unsigned int*)&L.x = *(unsigned int*)&ptr->m_10.x;
    *(volatile unsigned int*)&L.y = *(unsigned int*)&ptr->m_10.y;
    unsigned int z = *(unsigned int*)&ptr->m_10.z;
    *(volatile unsigned int*)&L.w = *(unsigned int*)&ptr->m_10.w;
    *(unsigned int*)&L.z = z;
    *(unsigned int*)&L.w = 0x3f000000u;

    *(__m128*)out = *(__m128*)&L;
    *(unsigned int*)&out->w = 0x3f000000u;
    __m128 p0 = _mm_load_ps(&v->x); p0 = _mm_mul_ps(p0, *(__m128*)out);
    __m128 y0 = _mm_add_ss(_mm_shuffle_ps(p0, p0, 0x55), p0);
    __m128 r0 = _mm_add_ss(_mm_shuffle_ps(p0, p0, 0xaa), y0);
    float b;
    _mm_store_ss(&b, r0);
    b = *(volatile float*)&b;

    for (int i = 1; 6 > i; ++i) {
        ptr = (&m_04->m_08)[i >> 1];
        SceneCopyBone(&L, ptr);
        if (i & 1) {
            __m128 d = _mm_shuffle_ps(ptr->m_30, ptr->m_30, 0x55);
            d = _mm_shuffle_ps(d, d, 0);
            d = _mm_mul_ps(d, ptr->m_20);
            _mm_store_ps(&L.x, _mm_add_ps(d, _mm_load_ps(&L.x)));
        }
        unsigned int kIter = (unsigned int)i | 0x3f000000u;
        *(unsigned int*)&L.w = kIter;

        float t = SceneDot3(v, &L);
        if (t > b) {
            *(__m128*)out = *(__m128*)&L;
            *(unsigned int*)&out->w = kIter;
            b = t;
        }
    }
}

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sqrt_ss(__m128 a);
#endif

struct TriAreaGreater {
    int unk00;
    static __forceinline __m128 area(const CastTri* t)
    {
        const Vec4f& a = t->GetVertex(0);
        const Vec4f& b = t->GetVertex(1);
        const Vec4f& c = t->GetVertex(2);
        const __m128 e1 = _mm_sub_ps(b.Get(), a.Get());
        const __m128 e2 = _mm_sub_ps(c.Get(), a.Get());
        const __m128 cross = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(e1, e1, 0xc9), _mm_shuffle_ps(e2, e2, 0xd2)),
            _mm_mul_ps(_mm_shuffle_ps(e2, e2, 0xc9), _mm_shuffle_ps(e1, e1, 0xd2)));
        return _mm_sqrt_ss(Dot3(cross, cross));
    }
    __forceinline bool operator()(const CastTri* a, const CastTri* b) const
    {
        return ToReal(area(a)) > ToReal(area(b));
    }
};

// Recursively quick-sorts the CastTri array in place using the TriAreaGreater comparator to partition around a pivot.
// @fnv 0x00e22a50
// src: GUESS 0x00e22a50 (confidence: medium)
void __cdecl Hkgpmesh_SortTrianglePointerRange(CastTri** pArr, int aiLow, int aiHigh, TriAreaGreater cmpLess)
{
    int i, j;
    __declspec(align(16)) CastTri* str;
begin:
    j = aiHigh;
    i = aiLow;
    str = pArr[(aiLow + aiHigh) >> 1];
    do {
        while (cmpLess(pArr[i], str))
            i++;
        while (cmpLess(str, pArr[j]))
            j--;
        if (i <= j) {
            if (j != i) {
                CastTri* t = pArr[j];
                pArr[j] = pArr[i];
                pArr[i] = t;
            }
            j--;
            i++;
        }
    } while (i <= j);
    if (aiLow < j)
        Hkgpmesh_SortTrianglePointerRange(pArr, aiLow, j, cmpLess);
    if (i < aiHigh) {
        aiLow = i;
        goto begin;
    }
}

struct MemAllocator {
    virtual void v00();
    virtual void* Alloc(unsigned int size);
    virtual void v08();
    virtual void v0C();
    virtual void Free(void* p, unsigned int size);
};



// 12-byte slot; flags word: element count in low 30 bits, bit 31 = no buffer.
struct FUN_00e25ba0_Slot {
    void* m_pData;
    int m_unk04;
    int m_flags;
};

struct FUN_00e25ba0_Table {
    FUN_00e25ba0_Slot* m_pSlots;
    int m_uiItemCount;
    int m_cap;
    int m_unk0C;
};

extern "C" void __cdecl hkArrayUtil__reserve(MemAllocator* alloc, FUN_00e25ba0_Table* table, int newCap, int elemSize);

struct FUN_00e25ba0_cls {
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

// Allocates a table, initializes its slot array to 0x407 entries, and stores the pointer in m_pTable.
// @fnv 0x00e25ba0
// src: HAVOK_LIB 0x00e25ba0
void FUN_00e25ba0_cls::hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_createEdgeDataHashTable() {
    hkMemoryRouter* audio1 = (hkMemoryRouter*)&hkMemoryRouter_getInstance();
    FUN_00e25ba0_Table* t = (FUN_00e25ba0_Table*)audio1->m_heap->blockAlloc(0x10);
    if (t != 0) {
    t->m_pSlots = 0;
    t->m_cap = (int)0x80000000;
    t->m_uiItemCount = 0;
    t->m_unk0C = 0;

    hkMemoryRouter* audio2 = (hkMemoryRouter*)&hkMemoryRouter_getInstance();
    MemAllocator* alloc = reinterpret_cast<MemAllocator*>(audio2->m_heap);
    int cap = t->m_cap & 0x3fffffff;
    if (cap < 0x407) {
        cap = cap * 2;
        if (cap <= 0x407) {
            cap = 0x407;
        }
        hkArrayUtil__reserve(alloc, t, cap, 0xc);
    }

    int n = t->m_uiItemCount - 0x407;
    int* base = (int*)((char*)t->m_pSlots + 0x3054);
    _ReadWriteBarrier();
    if (n > 0) {
        int* w = base + 2;
        int k = n;
        do {
            hkMemoryRouter* audio3 = (hkMemoryRouter*)&hkMemoryRouter_getInstance();
            MemAllocator* a3 = reinterpret_cast<MemAllocator*>(audio3->m_heap);
            w[-1] = 0;
            if ((w[0] & 0x80000000) == 0) {
                a3->Free((void*)w[-2], (*w & 0x3fffffff) * 12);
            }
            w[-2] = 0;
            w[0] = (int)0x80000000;
            w += 3;
            k--;
        } while (k != 0);
    }

    int m = 0x407 - t->m_uiItemCount;
    FUN_00e25ba0_Slot* y = &t->m_pSlots[t->m_uiItemCount];
    if (m > 0) {
        do {
            if (y != 0) {
                y->m_pData = 0;
                y->m_unk04 = 0;
                y->m_flags = (int)0x80000000;
            }
            y++;
            m--;
        } while (m != 0);
    }

    t->m_uiItemCount = 0x407;
    for (int i = 0; i < 0x3054; ) {
        FUN_00e25ba0_Slot* s = (FUN_00e25ba0_Slot*)((char*)t->m_pSlots + i);
        i += 12;
        s->m_unk04 = 0;
    }
    m_pTable = t;
    } else {
        m_pTable = 0;
    }
}

namespace fnv_00e27450 {
struct Vertex { int unk00; int unk04; int m_uiX; int m_uiY; };
struct VKey { int m_k; VKey(const Vertex* v) : m_k((v->m_uiX << 15) + v->m_uiY) {} };
struct Triangle { int unk00; int unk04; Vertex* m_v[3]; };
struct EdgeRef { Triangle* m_tri; int m_idx; };
struct EdgeEntry { Vertex* m_kPointA; Vertex* m_kPointB; int m_uiFilterValue; };
__forceinline void copyEntry(void* dst, const void* src)
{
    int i = 0;
    do { static_cast<int*>(dst)[i] = static_cast<const int*>(src)[i]; } while (++i < 3);
}
struct EdgeBucket { // distinct from hkArrayBase: 0x00e27450 implements a two-vertex hash bucket, with keyed lookup/removal.
    EdgeEntry* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline int indexOf(Vertex* a, Vertex* b) const
    {
        int endIdx = -1;
        if (endIdx < 0) endIdx = m_iElementCount;
        for (int i = 0; i < endIdx; ++i) if (m_data[i].m_kPointA == a && m_data[i].m_kPointB == b) return i;
        return -1;
    }
    __forceinline EdgeEntry* get(Vertex* a, Vertex* b)
    {
        int i = indexOf(a, b);
        return i == -1 ? 0 : &m_data[i];
    }
    __forceinline void remove(Vertex* a, Vertex* b)
    {
        int i = indexOf(a, b);
        --m_iElementCount;
        if (m_iElementCount != i) copyEntry(&m_data[i], &m_data[m_iElementCount]);
    }
};
__forceinline unsigned edgeHash(const Vertex* a, const Vertex* b)
{
    return ((a->m_uiX << 15) + a->m_uiY) * 0x3442a5 ^ ((b->m_uiX << 15) + b->m_uiY) * 0x1958e9;
}
__forceinline unsigned edgeHash2(const Vertex* a, const Vertex* b)
{
    VKey ka(a); VKey kb(b); return ka.m_k * 0x3442a5 ^ kb.m_k * 0x1958e9;
}
struct EdgeMap {
    EdgeBucket* m_buckets; unsigned m_numBuckets; int unk08; int m_uiItemCount;
    __forceinline EdgeEntry* get(Vertex* a, Vertex* b) { return m_buckets[edgeHash(a,b)%m_numBuckets].get(a,b); }
    __forceinline void remove(Vertex* a, Vertex* b)
    {
        unsigned h = edgeHash2(a,b) % m_numBuckets;
        --m_uiItemCount;
        EdgeBucket* bucket = m_buckets + h;
        if (bucket->indexOf(a,b) >= 0) bucket->remove(a,b);
    }
};
struct EdgeSet { void hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_32_struct_hkContainerHeapAllocator_release(int value); };

struct EdgeOwner {
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
    EdgeMap* m_map;
    EdgeSet m_set;
    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_clearEdgeData(const EdgeRef& e);
    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_destroyEdgeDataHashTable();
};
// If m_map exists, looks up e's edge, passes its filter value to m_set.FUN_00e24e40 and removes it, then calls FUN_00e27400 if m_map is empty.
// @fnv 0x00e27450
// src: HAVOK_LIB 0x00e27450
void EdgeOwner::hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_clearEdgeData(const EdgeRef& e)
{
    if (m_map) {
        Vertex* a = e.m_tri->m_v[e.m_idx];
        Vertex* b = e.m_tri->m_v[(9 >> (e.m_idx * 2)) & 3];
        EdgeEntry* entry = m_map->get(a,b);
        if (entry) { m_set.hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_32_struct_hkContainerHeapAllocator_release(entry->m_uiFilterValue); m_map->remove(a,b); }
        if (m_map->m_uiItemCount == 0) hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_destroyEdgeDataHashTable();
    }
}
}  // namespace fnv_00e27450

namespace fnv_00e126c0 {
void __cdecl hkArrayUtil__reserve(Allocator* alloc, void* arr, int numElem, int sizeElem) throw();



template <class T>
__forceinline T* expandGeometryArray(::hkArray<T>& array, int n)
{
    Allocator& alloc = meshHeap(hkMemoryRouter_getInstance());
    int oldSize = array.m_iElementCount;
    int newSize = oldSize + n;
    int cap = array.m_iCapacityState & 0x3fffffff;
    if (cap < newSize) {
        int cap2 = cap + cap;
        hkArrayUtil__reserve(&alloc, &array, newSize < cap2 ? cap2 : newSize, sizeof(T));
    }
    array.m_iElementCount += n;
    return array.m_data + oldSize;
}

struct hkgpVertex {
    hkgpVertex* m_next;
    int unk04;
    int unk08;
    int unk0c;
    hkVector4 m_pObservedSource;
};

struct hkgpTriangle {
    hkgpTriangle* m_next;
    int unk04;
    hkgpVertex* m_kVertices[3];
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int m_iMaterialIndex;
};

struct HashEntryTable {
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    HashEntryTable() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1) { reserve(meshHeap(hkMemoryRouter_getInstance()), 0); }
    ~HashEntryTable() throw();
    int GetLogicalSize() const { return m_iCapacityFlags & 0x7fffffff; }
    void reserve(Allocator& alloc, int n) throw();
    void insert(Allocator& alloc, const void* key, int val) throw();
    int FindValueForKey(const void* key, int def) const throw();
    void ClearAndRelease(Allocator& alloc) throw();
};

struct PointerKeyIntegerMap {
    HashEntryTable m_map;

    void reserve(int n) { m_map.reserve(meshHeap(hkMemoryRouter_getInstance()), n); }
    void insert(const void* key, int val) { m_map.insert(meshHeap(hkMemoryRouter_getInstance()), key, val); }
    int FindValueForKey(const void* key, int def) const { return m_map.FindValueForKey(key, def); }
    int GetLogicalSize() const { return m_map.GetLogicalSize(); }
    ~PointerKeyIntegerMap() { m_map.ClearAndRelease(meshHeap(hkMemoryRouter_getInstance())); }
};

template <class T> __forceinline void hkSwap(T& a, T& b) { T t = a; a = b; b = t; }

struct hkgpConvexHullImpl {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    hkgpVertex* m_firstVertex;
    int m_iStridedVertexCount;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    hkgpTriangle* m_firstTriangle;
    int m_iTriangleCount;

    void hkgpMesh_appendToGeometry(hkGeometry& geom, bool flip);
};

// Appends the convex hull's vertices and triangles to the given hkGeometry, remapping vertex indices and optionally flipping winding order.
// @fnv 0x00e126c0
// src: XBOX_PDB 0x00e126c0
void hkgpConvexHullImpl::hkgpMesh_appendToGeometry(hkGeometry& geom, bool abFlipWinding)
{
    if (m_iTriangleCount <= 0)
        return;
    const int baseIndex = geom.m_kVertices.m_iElementCount;
    hkVector4* vertices = expandGeometryArray(geom.m_kVertices, m_iStridedVertexCount);
    hkGeometry::Triangle* triangles = expandGeometryArray(geom.m_uiTriangleCount, m_iTriangleCount);
    PointerKeyIntegerMap vertexIndexMap;
    int numVertices = m_iStridedVertexCount;
    vertexIndexMap.reserve(numVertices + 1);
    for (hkgpVertex* v = m_firstVertex; v; v = v->m_next)
    {
        vertexIndexMap.insert(v, vertexIndexMap.GetLogicalSize() + baseIndex);
        *vertices++ = v->m_pObservedSource;
    }
    for (hkgpTriangle* t = m_firstTriangle; t; t = t->m_next)
    {
        triangles->m_kPointA = vertexIndexMap.FindValueForKey(t->m_kVertices[0], -1);
        triangles->m_kPointB = vertexIndexMap.FindValueForKey(t->m_kVertices[1], -1);
        triangles->m_iThirdValue = vertexIndexMap.FindValueForKey(t->m_kVertices[2], -1);
        triangles->m_iMaterialIndex = t->m_iMaterialIndex;
        if (abFlipWinding)
            hkSwap(triangles->m_kPointB, triangles->m_iThirdValue);
        triangles++;
    }
}
}  // namespace fnv_00e126c0

struct HkV4 {
    __m128 m_vComponents;
};
struct HkVert {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    HkV4 m_vContactPosition;
};

struct __declspec(align(16)) Vec4F {
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
};

struct __declspec(align(16)) Mat3Diffs {
    Vec4F m_d0;
    Vec4F m_d1;
    Vec4F m_d2;
    __forceinline Mat3Diffs(__m128 a, __m128 b, __m128 c) { _mm_store_ps(&m_d0.m_uiX, a); _mm_store_ps(&m_d1.m_uiX, b); _mm_store_ps(&m_d2.m_uiX, c); }
    __m128* FUN_00cd51c0(Vec4F* out);
};

// @fnv 0x00e13870
// src: GUESS 0x00e13870 (confidence: low)
float __cdecl Hkgpmesh_ComputeValues_00e13870(char* self, unsigned int idx)
{
    unsigned int tagged = *(unsigned int*)(self + 0x14 + idx * 4);
    unsigned int tag = tagged & 3;
    char* ptr = (char*)(tagged & 0xfffffffcu);
    if (ptr == 0) {
        return 0.0f;
    }
    char* a = *(char**)(self + 8 + idx * 4);
    const HkV4& o = ((HkVert*)a)->m_vContactPosition;
    __m128 av = o.m_vComponents;
    char* b = *(char**)(ptr + 8 + tag * 4);
    __m128 bv = *(__m128*)(b + 0x10);
    int si = 0x12 >> (idx * 2);
    int ti = 0x12 >> (tag * 2);

    char* c = *(char**)(self + 8 + (si & 3) * 4);
    char* d = *(char**)(ptr + 8 + (ti & 3) * 4);
    Vec4F res;
    __m128* r = Mat3Diffs(_mm_sub_ps(bv, o.m_vComponents), _mm_sub_ps(*(__m128*)(c + 0x10), av), _mm_sub_ps(*(__m128*)(d + 0x10), av)).FUN_00cd51c0(&res);
    float f;
    _mm_store_ss(&f, *r);
    return f;
}

// FUN_00e144d0 : thiscall, float x, __m128* a, __m128* out, int count
// Clamped-distance accumulation with a dot3 weighted correction.

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ss(const float*);
#endif

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

// Repeats count times: takes a sqrt of FUN_00e13660 clamped to +/- x/2 (negated if flagged), then adds a scaled copy of *a to *out; returns the last value.
// @fnv 0x00e144d0
// src: GUESS 0x00e144d0 (confidence: low)
float CollideShape::ProcessEntries_00e144d0(float x, __m128* a, __m128* out, int count)
{
    float r = 0.0f;
    float halfT = (float)(x * 0.5);
    unsigned char flag = 0;
    Float4Bits cv;
    cv.x = DAT_01267e30;
    cv.y = DAT_01267e34;
    cv.z = DAT_01267e38;
    cv.w = DAT_01267e3c;

    if (count > 0)
    {
        float negHalfT = -halfT;
        do
        {
            float s = (float)((float)sqrt(this->ProcessAndReturnValue_00e13660(out, (const __m128*)&cv, &flag)));
            r = (s < negHalfT) ? negHalfT : ((s > halfT) ? halfT : s);
            if (flag != 0)
            {
                r = -r;
            }
            float dist = x - r;
            __m128 dot = Dot3(_mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&dist), _mm_load_ss(&dist), 0), *(__m128*)&cv), *a);
            *out = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), *a), *out);
            --count;
        } while (count != 0);
    }
    return r;
}

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_min_ps(__m128, __m128);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_max_ps(__m128, __m128);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_set_ps(float, float, float, float);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_setr_ps(float, float, float, float);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ss(const float*);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
#endif
extern __m128 DAT_010c71d0;
extern const float DAT_01011d78;
void __cdecl ResizeAudioStream(void*, void*, int) throw();

struct __declspec(align(16)) CellVec {
    float x, y, z, w;
    __m128& quad() { return reinterpret_cast<__m128&>(*this); }
    const __m128& quad() const { return reinterpret_cast<const __m128&>(*this); }
};
struct CellBounds { CellVec min, max; };
static __forceinline __m128 CellCorner(const float& x, const float& y, const float& z) {
    return _mm_setr_ps(x,y,z,DAT_01011d78);
}
void __cdecl Hkgeometryprocessing_GetCubeBoundsFromLargestExtent(CellBounds*) throw();
struct BuildInput { MeshPacketCallLocal_00e16e50* data; int count, stride; };
struct BuildOptions {
    int unk00, unk04, unk08, unk0c;
    BuildOptions* hkgpConvexHull_BuildConfig_BuildConfig() throw();
};
namespace CellBuild {
struct FUN_00d76ca0 {
    int vptr;
    unsigned short memorySize, referenceCount;
    int unk08, unk0c, unk10;
    FUN_00d76ca0() throw();
    ~FUN_00d76ca0() throw() { ReleaseStorage_00d76940(); }
    void ReleaseStorage_00d76940() throw();
    int hkgpConvexHull_build_00d77200(const BuildInput&, const BuildOptions*) throw();
    bool hkgpConvexHull_isPointInside(const CellVec&, int, float) throw();
};
}
template<class T> static __forceinline void CellConstruct(T* p,int n,const T& value) throw() { for(int i=0;i<n;++i) p[i].quad()=value.quad(); }
template<class T> struct CellArray {
    T* data; int size, capacity;
    CellArray() throw() : data(0), size(0), capacity(0x80000000) {}
    __forceinline T& expand() throw() {
        hkMemoryRouter& router = hkMemoryRouter_getInstance();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(reinterpret_cast<Allocator*>(router.m_heap), this, sizeof(T));
        return data[size++];
    }
    __forceinline void push(const T& value) throw() {
        hkMemoryRouter& router = hkMemoryRouter_getInstance();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(reinterpret_cast<Allocator*>(router.m_heap), this, sizeof(T));
        T* p = data + size;
        if (p) new(p) T(value);
        ++size;
    }
    __forceinline void pushVector(const T& value) throw() {
        hkMemoryRouter& router = hkMemoryRouter_getInstance();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(reinterpret_cast<Allocator*>(router.m_heap), this, sizeof(T));
        T* p = data + size;
        CellConstruct(p,1,value);
        ++size;
    }
    __forceinline void release() throw() {
        Allocator& heap = meshHeap(hkMemoryRouter_getInstance());
        int cap = capacity;
        size = 0;
        if (!(cap & 0x80000000)) heap.freeBlock(data, (cap & 0x3fffffff)*sizeof(T));
        data = 0; capacity = 0x80000000;
    }
};
struct CellMesh {
    void hkgpMesh_fetchPositions(CellArray<MeshPacketCallLocal_00e16e50>&) throw();
    CellBounds ProcessEntries_00e11530() throw();
    float ProcessAndReturnValue_00e13660(const CellVec&, CellVec*, bool*) throw();
    void CollectPoints(int depthLimit, float scale, CellArray<CellVec>& output, bool invert);
};
// Subdivides the bounds into octants with a work stack and pushes cell centers, with a scaled distance in w, into output for cells that pass the inside test.
// @fnv 0x00e14620
void CellMesh::CollectPoints(int depthLimit, float scale, CellArray<CellVec>& output, bool invert)
{
    CellBuild::FUN_00d76ca0 builder;
    {
    CellArray<MeshPacketCallLocal_00e16e50> vertices;
    hkgpMesh_fetchPositions(vertices);
    BuildInput input;
    input.data = vertices.data;
    input.count = vertices.size;
    input.stride = 16;
    BuildOptions options;
    if (builder.hkgpConvexHull_build_00d77200(input, options.hkgpConvexHull_BuildConfig_BuildConfig()) != 3) {
        vertices.release();
        return;
    }
    vertices.release();
    }
    CellArray<CellBounds> pending;
    pending.push(ProcessEntries_00e11530());
    Hkgeometryprocessing_GetCubeBoundsFromLargestExtent(pending.data);
    reinterpret_cast<int&>(pending.data[0].min.w) = 0x3f000000;
    do {
        CellBounds bounds = pending.data[pending.size-1];
        --pending.size;
        CellVec sum;
        sum.quad() = _mm_add_ps(bounds.max.quad(), bounds.min.quad());
        CellVec center;
        center.quad() = _mm_mul_ps(sum.quad(), DAT_010c71d0);
        __m128 delta = _mm_sub_ps(center.quad(), bounds.max.quad());
        __m128 square = _mm_mul_ps(delta, delta);
        float radiusSquared;
        int depth = reinterpret_cast<const int&>(bounds.min.w) & 0xc0ffffff;
        bool inside = false;
        _mm_store_ss(&radiusSquared, Dot3(square));
        CellVec closest;
        float distance = ProcessAndReturnValue_00e13660(center, &closest, &inside);
        bool accepted = invert ? !inside : inside;
        if (distance > radiusSquared) {
            if (!accepted && builder.hkgpConvexHull_isPointInside(center, 0, 0.0f)) {
                CellVec point = center;
                point.w = (float)sqrt((double)distance) * scale;
                output.pushVector(point);
            }
        } else if (depth < depthLimit) {
            int i=0;
            ++depth;
            depth |= 0x3f000000;
            for (; i<8; ++i) {
                CellBounds& child = pending.expand();
                __m128 corner;
                switch (i) {
                case 0: corner = CellCorner(bounds.min.x,bounds.min.y,bounds.min.z); break;
                case 1: corner = CellCorner(bounds.max.x,bounds.min.y,bounds.min.z); break;
                case 2: corner = CellCorner(bounds.max.x,bounds.max.y,bounds.min.z); break;
                case 3: corner = CellCorner(bounds.min.x,bounds.max.y,bounds.min.z); break;
                case 4: corner = CellCorner(bounds.min.x,bounds.min.y,bounds.max.z); break;
                case 5: corner = CellCorner(bounds.max.x,bounds.min.y,bounds.max.z); break;
                case 6: corner = CellCorner(bounds.max.x,bounds.max.y,bounds.max.z); break;
                case 7: corner = CellCorner(bounds.min.x,bounds.max.y,bounds.max.z); break;
                default: corner = _mm_mul_ps(sum.quad(), DAT_010c71d0); break;
                }
                child.min.quad() = _mm_min_ps(center.quad(),corner);
                child.max.quad() = _mm_max_ps(center.quad(),corner);
                reinterpret_cast<int&>(child.min.w) = depth;
            }
        }
    } while (pending.size);
    pending.release();
}

struct FUN_00e21dd0_cls { __m128 unk00; __m128 unk10; __m128 unk20; void hkgpMesh_LineShape_getBoundingBox(__m128* result); };
// Stores the element-wise minimum and maximum of unk10 and unk20 into result[0] and result[1].
// @fnv 0x00e21dd0
// src: XBOX_PDB 0x00e21dd0
void FUN_00e21dd0_cls::hkgpMesh_LineShape_getBoundingBox(__m128* result) {
    __m128 a = unk10;
    __m128 b = unk20;
    __m128 lower = a;
    lower = _mm_min_ps(lower, b);
    __m128 upper = a;
    upper = _mm_max_ps(upper, b);
    result[0] = lower;
    result[1] = upper;
}

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ss(const float* p);
#endif

extern float DAT_01016248;

struct FUN_00e21e60_pair {
    __m128 m_v00;
    __m128 m_v10;
    unsigned int m_u20;
};

struct FUN_00e21e60_cls {
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    __m128 m_v10;
    float m_f20;
    unsigned int m_u24;

    float hkgpMesh_WeldingPolicy_addLeaf(FUN_00e21e60_pair* p);
};

// If the squared distance from m_v10 to the scaled sum of p's two vectors is <= m_f20, stores p->m_u20 in m_u24; always returns 1.0f.
// @fnv 0x00e21e60
// src: XBOX_PDB 0x00e21e60
float FUN_00e21e60_cls::hkgpMesh_WeldingPolicy_addLeaf(FUN_00e21e60_pair* p)
{
    __m128 sum = _mm_add_ps(p->m_v10, p->m_v00);
    __m128 half = _mm_load_ss(&DAT_01016248);
    __m128 mid = _mm_mul_ps(sum, _mm_shuffle_ps(half, half, 0));
    __m128 d = _mm_sub_ps(mid, m_v10);
    __m128 sq = _mm_mul_ps(d, d);
    __m128 yy = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 zz = _mm_shuffle_ps(sq, sq, 0xaa);
    __m128 xy = _mm_add_ss(yy, sq);
    __m128 r = _mm_add_ss(zz, xy);
    float dist;
    _mm_store_ss(&dist, r);
    if (dist <= m_f20) {
        m_u24 = p->m_u20;
    }
    return 1.0f;
}

namespace fnv_00e22480 {
extern float DAT_01011d78;
extern float DAT_01012068;

__declspec(align(16)) struct Vec4Packet {
    unsigned int m_uiX;
    unsigned int m_uiY;
    unsigned int m_uiZ;
    unsigned int m_w;
};

struct FUN_00e22480_cls {
    virtual void Slot00();
    virtual void Slot01(Vec4Packet* out, unsigned int arg);
    void IConvexOverlapImpl_ShapeBridge_convertVertexIdsToVertices(unsigned int a1, unsigned int a2, unsigned int a3);
};

// Stores a Vec4Packet with DAT_01012068 and DAT_01011d78 values and calls Slot01 with a3.
// @fnv 0x00e22480
// src: XBOX_PDB 0x00e22480
void FUN_00e22480_cls::IConvexOverlapImpl_ShapeBridge_convertVertexIdsToVertices(unsigned int auiUnused1, unsigned int auiUnused2, unsigned int a3)
{
    Vec4Packet v;
    _mm_store_ps((float*)&v, _mm_setr_ps(DAT_01012068, DAT_01011d78, DAT_01011d78, DAT_01011d78));
    this->Slot01(&v, a3);
}
}  // namespace fnv_00e22480

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
    LocEdge() {}
    LocEdge(const LocEdge& o) { m_pkTriangle = o.m_pkTriangle; m_uiEdgeIndex = o.m_uiEdgeIndex; }
    LocEdge(LocTriangle* t, int i) : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    static int next(int i) { return (9 >> (i << 1)) & 3; }
    static int prev(int i) { return (18 >> (i << 1)) & 3; }
    LocEdge nextEdge() const { return LocEdge(m_pkTriangle, next(m_uiEdgeIndex)); }
    LocEdge prevEdge() const { return LocEdge(m_pkTriangle, prev(m_uiEdgeIndex)); }
    LocEdge link() const
    {
        const unsigned int l = m_pkTriangle->m_ppLinks[m_uiEdgeIndex];
        LocEdge e; e.m_uiEdgeIndex = l & 3; e.m_pkTriangle = (LocTriangle*)(l & ~3u); return e;
    }
    LocVertex* start() const { return m_pkTriangle->m_kVertices[m_uiEdgeIndex]; }
    LocVertex* end() const { return m_pkTriangle->m_kVertices[next(m_uiEdgeIndex)]; }
};

struct LocResult
{
    int m_type;
    LocEdge m_kEdge;
    LocResult() {}
    LocResult(int type, const LocEdge& e) : m_type(type), m_kEdge(e.m_pkTriangle, e.m_uiEdgeIndex) {}
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
static inline int orientation(LocEdge e, int x, int y) { return orientation(e.start(), e.end(), x, y); }

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

// Finds the triangle or edge containing point (x, y) by walking the triangulation, returning a LocResult with type and edge.
// @fnv 0x00e24200
LocResult LocTriangulator::LocatePoint(int x, int y)
{
    LocTriangle* t = m_grid[(y >> 11) * 16 + (x >> 11)];
    if (t == 0) t = m_pHeadNode;
    LocEdge edge(t, 0);
    for (LocTriangle* root = m_pHeadNode; root; root = root->m_next)
    {
        const int numIter = m_maxIterations;
        int o = orientation(edge, x, y);
        while (o < 0)
        {
            edge = edge.link().nextEdge();
            o = orientation(edge, x, y);
        }
        for (int i = numIter; i > 0; --i)
        {
            const LocEdge edges[2] = { edge.nextEdge(), edge.prevEdge() };
            const int orients[2] = { orientation(edges[0], x, y), orientation(edges[1], x, y) };
            const int best = orients[0] >= orients[1] ? 1 : 0;
            const int iOrientBest = orients[best];
            LocEdge e = edges[best];
            if (iOrientBest >= 0)
            {
                const int code = (o == 0 ? 1 : 0) + (orients[0] == 0 ? 2 : 0) + (orients[1] == 0 ? 4 : 0);
                switch (code)
                {
                case 0: { LocResult r; r.m_type = 0; r.m_kEdge = edge; return r; }
                case 1: return LocResult(1, edge);
                case 2: return LocResult(1, edges[0]);
                case 4: return LocResult(1, edges[1]);
                case 3: return LocResult(2, edges[0]);
                case 6: return LocResult(2, edges[1]);
                case 5: { LocResult r; r.m_type = 2; r.m_kEdge = edge; return r; }
                default:
                    return LocResult(3, invalidEdge());
                }
            }
            o = -iOrientBest;
            e = e.link();
            edge.m_pkTriangle = e.m_pkTriangle;
            edge.m_uiEdgeIndex = e.m_uiEdgeIndex;
        }
        // restart from the next root triangle (field-wise, so index 0 is known at the loop top)
        edge.m_pkTriangle = root;
        edge.m_uiEdgeIndex = 0;
    }
    {
        // HK_ERROR: hkErrStream on a local buffer; its destructor runs on both paths
        CharBuffer msg;
        unsigned int buf[0x80];
        msg.FUN_00cb1600((char*)buf, 0x200);
        msg.ProcessAndReturnValue_00cc01c0("Cycle detected during point location");
        if (DAT_01268360->Report(3, 0xb8c66b5f, (const char*)buf, "d:\\build\\20091222_000100_AiAnBeClDePh\\Source\\Common/Internal/GeometryProcessing/Triangulator/hkgpTriangulator.inl", 0x34f))
        {
            __debugbreak();
            msg.FUN_00cc00e0();
        }
        else
            msg.FUN_00cc00e0();
    }
    return LocResult(4, invalidEdge());
}

#include <math.h>
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sub_ps(__m128,__m128);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sqrt_ss(__m128);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ss(const float*);
#endif
extern __m128 DAT_010ec7f0;
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ps1(const float*);
#endif
#ifndef _INCLUDED_MM2
static __m128 _mm_set1_ps(const float& f) {__m128 a=_mm_load_ss(&f);return _mm_shuffle_ps(a,a,0);}
#endif
extern const float DAT_010141cc;
extern const float DAT_0104da4c=1.1920928955078125e-7f;
struct EVec {
    float x,y,z,w;
    const __m128& quad() const {return reinterpret_cast<const __m128&>(*this);}
    __m128 dot(const EVec& a) const {__m128 v=_mm_mul_ps(quad(),a.quad());return _mm_add_ss(_mm_shuffle_ps(v,v,0xaa),_mm_add_ss(_mm_shuffle_ps(v,v,0x55),v));}
    char* FUN_00c7f520(char* out, float tolerance);
};
struct EVertex { int unk00,unk04,unk08,unk0c; EVec position; };
struct ELocalVec {union {EVec scalar; __m128 simd;}; ELocalVec(const EVec& v) {scalar=v;}};
struct EFace { EFace* next; int unk04; EVertex* vertices[3]; unsigned int edges[3]; EVec normal; };
struct ENode { ENode* next; int unk04,unk08,unk0c; EVec position,normal; };
struct EParams {float value,spacing,tolerance,offset,angle; unsigned char flag14,flag15,flag16,flag17; int filter;};
struct EArray {EVec* data; int size; unsigned int capacity;};
struct EAppend {
 EArray* owner; EVec* dest;
 EAppend(EArray* a):owner(a),dest(a->data+a->size) {}
 ~EAppend() {++owner->size;}
 operator EVec&() {return *dest;}
};
struct EMatrix {EVec rows[3]; __declspec(noalias) EVec* FUN_00cd51c0(EVec* out);};
void __cdecl ResizeAudioStream(void*,void*,int);
struct EMesh {
    int unk00,unk04,unk08,unk0c,unk10;
    ENode* nodes;
    int unk18,unk1c,unk20,unk24,unk28;
    EFace* faces;
    __declspec(noalias) float hkgpMesh_projectPointOnSurface(float value,EVec* point,int filter);
    void hkgpMesh_generateSurfaceSamples(EParams* p,EArray* out);
};
static __m128 load(const EVec& v) {return _mm_load_ps(&v.x);}
static void store(EVec& v,__m128 a) {_mm_store_ps(&v.x,a);}
static float sum3(__m128 p) {
    __m128 y=_mm_shuffle_ps(p,p,0x55);
    __m128 z=_mm_shuffle_ps(p,p,0xaa);
    y=_mm_add_ss(y,p);
    z=_mm_add_ss(z,y);
    float r; _mm_store_ss(&r,z); return r;
}
// Populates out with node and edge-interpolated points offset by normals, keeping those within tolerance of the target value.
// @fnv 0x00e17010
// src: XBOX_PDB 0x00e17010
void EMesh::hkgpMesh_generateSurfaceSamples(EParams* apParams,EArray* out) {
    float tolerance=apParams->tolerance*apParams->value;
    float matrix=apParams->offset*apParams->value;
    ENode* t;
    if(apParams->flag15) {
        t=nodes;
        while(t) {
            
            EVec point;
            store(point,_mm_add_ps(_mm_mul_ps(_mm_set1_ps(matrix),load(t->normal)),load(t->position)));
            float r=hkgpMesh_projectPointOnSurface(apParams->value,&point,apParams->filter);
            if(r>tolerance) {
                point.w=(float)fabs(r);
                hkMemoryRouter& router=hkMemoryRouter_getInstance();
                if(out->size==(int)(out->capacity&0x3fffffff)) ResizeAudioStream(reinterpret_cast<Allocator*>(router.m_heap),out,16);
                store(EAppend(out),load(point));
                
            }
            t=t->next;
        }
    }
    if(apParams->flag16 == 0) return;
    for(EFace* face=faces;face;face=face->next) {
        char valid;
        if(!*face->normal.FUN_00c7f520(&valid,DAT_010141cc)) continue;
        for(int i=0;i<3;++i) {
            int shift=i<<1;
            EVertex** pick=&face->vertices[(9>>shift)&3];
            EVertex* base=face->vertices[i];
            for(int d=0;3 > d;++d) {
                if((&base->position.x)[d]<(&(*pick)->position.x)[d]) break;
                if((&base->position.x)[d]>(&(*pick)->position.x)[d]) {if(face->edges[i]&~3) goto nextEdge; break;}
            }
            {
                ELocalVec normal(face->normal);
                if(face->edges[i]&~3) {
                    char validOther;
                    if(!*((EFace*)(face->edges[i]&~3))->normal.FUN_00c7f520(&validOther,DAT_010141cc)) goto nextEdge;
                    
                    float dot; _mm_store_ss(&dot,((EFace*)(face->edges[i]&~3))->normal.dot(face->normal));
                    if(dot>apParams->angle) goto nextEdge;
                    normal.simd=_mm_add_ps(((EFace*)(face->edges[i]&~3))->normal.quad(),normal.simd);
                    if(apParams->flag14) {
                        ELocalVec a(face->vertices[i]->position);
                        ELocalVec b((*pick)->position);
                        ELocalVec c(face->vertices[(0x12>>shift)&3]->position);
                        S_00e13910_Edge linked(face->edges[i]);
                        ELocalVec d(((EVertex*)linked.prev().start())->position);
                        EMatrix offset;
                        store(offset.rows[0],_mm_sub_ps(b.simd,a.simd));
                        store(offset.rows[1],_mm_sub_ps(c.simd,a.simd));
                        store(offset.rows[2],_mm_sub_ps(d.simd,a.simd));
                        EVec dotVector;
                        EVec* r=offset.FUN_00cd51c0(&dotVector);
                        float det; _mm_store_ss(&det,load(*r));
                        if(det < DAT_0104da4c) goto nextEdge;
                    }
                }
                float z=sum3(_mm_mul_ps(normal.simd,normal.simd));
                if(z!=0.0f) {
                    float length=(float)sqrt((double)z);
                    float inv=1.0f/length;
                    normal.simd=_mm_mul_ps(normal.simd,_mm_set1_ps(inv));
                    __m128 diff=_mm_sub_ps(load(face->vertices[i]->position),load((*pick)->position));
                    __m128 j;
                    j = _mm_mul_ps(diff,diff);
                    __m128 y=_mm_shuffle_ps(j,j,0x55);
                    __m128 length2=_mm_shuffle_ps(j,j,0xaa);
                    y=_mm_add_ss(y,j);length2=_mm_add_ss(length2,y);
                    __m128 root=_mm_sqrt_ss(length2);
                    float distance;_mm_store_ss(&distance,root);
                    int count=(int)(distance/apParams->spacing+0.5)+3;
                    if(count>64) count=64;
                    for(int k=0;k<=count;++k) {
                        float node=apParams->flag17?0.5:(double)k/count;
                        EVec point;
                        __m128 tVec=_mm_set1_ps(node);
                        store(point,_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0,tVec),face->vertices[i]->position.quad()),_mm_mul_ps(load((*pick)->position),tVec)),_mm_mul_ps(_mm_set1_ps(matrix),normal.simd)));
                        float r=hkgpMesh_projectPointOnSurface(apParams->value,&point,apParams->filter);
                        float delta=r-apParams->value;
                        if((float)fabs(delta)<tolerance) {
                            point.w=(float)fabs(r);
                            hkMemoryRouter& router=hkMemoryRouter_getInstance();
                            if(out->size==(int)(out->capacity&0x3fffffff)) ResizeAudioStream(reinterpret_cast<Allocator*>(router.m_heap),out,16);
                            store(EAppend(out),load(point));
                            
                        }
                        if(apParams->flag17) break;
                    }
                }
            }
nextEdge:;
        }
    }
}




struct FUN_00e21e30 {
    int unk4;
    FUN_00e21e30();
// Empty virtual destructor of the FUN_00e21e30 class.
// @fnv 0x00e21e30
    virtual ~FUN_00e21e30() {}
    void operator delete(void* p, unsigned int nbytes) {
        (*reinterpret_cast<hkMemoryRouter*>(&::hkMemoryRouter_getInstance())).heap().blockFree(p, static_cast<int>(nbytes));
    }
};

FUN_00e21e30::FUN_00e21e30() {}

extern "C" void __cdecl Deallocate(void*);

struct FUN_00e22500_cls {
    int unk04;
    virtual ~FUN_00e22500_cls() {}

    FUN_00e22500_cls* FUN_00e22500(unsigned char acFlags);
};

// @fnv 0x00e22500
FUN_00e22500_cls* FUN_00e22500_cls::FUN_00e22500(unsigned char acFlags)
{
    this->FUN_00e22500_cls::~FUN_00e22500_cls();
    if (acFlags & 1) {
        Deallocate(this);
    }
    return this;
}

namespace fnv_00e22db0 {
struct S_00e22db0_Iface {
    virtual void unk00();
    virtual void unk04();
    virtual void release(void* p, unsigned short size);
};

namespace fnvc_adapt { hkMemoryRouter* __cdecl hkMemoryRouter_getInstance(); }

struct FUN_00e22db0 {
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
    FUN_00e22db0();
// Empty virtual destructor for the FUN_00e22db0 class.
// @fnv 0x00e22db0
    virtual ~FUN_00e22db0() {}
    static void operator delete(void* p, unsigned int size)
    {
        hkMemoryRouter* sv = fnvc_adapt::hkMemoryRouter_getInstance();
        sv->m_heap->blockFree(p, 0x60);
    }
};

FUN_00e22db0::FUN_00e22db0() {}
}  // namespace fnv_00e22db0

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_set_ps1(float);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sub_ps(__m128, __m128);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sqrt_ss(__m128);
#endif

typedef float hkReal;




__forceinline hkSimdReal operator-(const hkSimdReal& r) { return _mm_sub_ss(DAT_010c7160, r.m_vValue); }

struct CheckVector {
    __m128 m_vComponents;

    __forceinline void operator=(const CheckVector& v) { m_vComponents = v.m_vComponents; }
    __forceinline hkReal& operator()(int i) { return m_vComponents.m128_f32[i]; }
    __forceinline void setSub4(const CheckVector& a, const CheckVector& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(hkReal s) { __m128 scale = _mm_load_ss(&s); m_vComponents = _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), m_vComponents); }
    __forceinline void setCross(const CheckVector& v1, const CheckVector& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9), _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2), _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline hkSimdReal dot3(const CheckVector& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    __forceinline hkSimdReal lengthSquared3() const { return dot3(*this); }
    __forceinline hkSimdReal length3() const { return _mm_sqrt_ss(lengthSquared3().m_vValue); }
};

class TriangleChecker {
public:
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
    bool m_degenerate;
    hkReal m_minEdgeLengthSquared;
    hkReal m_fMinTriangleAreaSquared;

    void SetField100(const CheckVector& a, const CheckVector& b, const CheckVector& c);
    void SetFlag100_00e11500(const CheckVector& a, const CheckVector& b);
    bool ValidateTriangleAndComputePlane(const CheckVector& a, const CheckVector& b, const CheckVector& c, CheckVector& planeOut, bool report);
};

// src: GUESS 0x00e114f0 (confidence: low)
__declspec(noinline) void TriangleChecker::SetField100(const CheckVector& a, const CheckVector& b, const CheckVector& c)
{
    m_degenerate = true;
}

// src: GUESS 0x00e11500 (confidence: medium)
__declspec(noinline) void TriangleChecker::SetFlag100_00e11500(const CheckVector& a, const CheckVector& b)
{
    m_degenerate = true;
}

// Validates triangle edges and area against tolerance thresholds, computes and normalizes the plane, and reports degenerate cases.
// @fnv 0x00e11710
// src: GUESS 0x00e11710 (confidence: medium)
bool TriangleChecker::ValidateTriangleAndComputePlane(const CheckVector& a, const CheckVector& b, const CheckVector& c, CheckVector& planeOut, bool report)
{
    const hkReal tolerance = m_minEdgeLengthSquared;
    bool ok = true;

    CheckVector ab; ab.setSub4(b, a);
    if (report && ab.lengthSquared3() <= tolerance)
    {
        SetFlag100_00e11500(a, b);
        ok = false;
    }

    CheckVector ac; ac.setSub4(c, a);
    if (report && ac.lengthSquared3() <= tolerance)
    {
        SetFlag100_00e11500(a, c);
        ok = false;
    }

    CheckVector cb; cb.setSub4(c, b);
    if (report && cb.lengthSquared3() <= tolerance)
    {
        SetFlag100_00e11500(c, b);
        ok = false;
    }

    planeOut.setCross(ab, ac);
    const hkReal len = planeOut.length3();
    planeOut(3) = len;
    if (report && len < m_fMinTriangleAreaSquared)
    {
        SetField100(a, b, c);
        ok = false;
    }

    planeOut.mul4(1.0f / planeOut(3));
    planeOut(3) = -planeOut.dot3(a);
    return ok;
}

struct S00e124d0_Obj {
    unsigned int m_h0;
    unsigned int m_h4;
    unsigned int m_kVertices[3];
    unsigned int m_ppLinks[3];
};

struct S00e124d0_Entry {
    S00e124d0_Obj* m_obj;
    int m_iIndex;
};

template <unsigned int ELEMENTSIZE>
inline void S00e124d0_memCpyOne(void* dst, const void* src) {
    const int* s = static_cast<const int*>(src);
    int* d = static_cast<int*>(dst);
    unsigned int i = 0;
    do {
        d[i] = s[i];
        ++i;
    } while (i < ELEMENTSIZE / sizeof(int));
}

template <typename T>
inline void S00e124d0_destruct(T* p, int n) {
    for (int k = 0; k < n; ++k) {
        p[k].~T();
    }
}

struct S00e124d0_Table {
    S00e124d0_Entry* m_data;
    int m_uiItemCount;

    inline void removeAt(int index) {
        S00e124d0_destruct(m_data + index, 1);
        m_uiItemCount--;
        if (m_uiItemCount != index) {
            S00e124d0_memCpyOne<sizeof(S00e124d0_Entry)>(m_data + index, m_data + m_uiItemCount);
        }
    }
};

static inline int S00e124d0_Map(int s) {
    return (9 >> (2 * s)) & 3;
}

static inline bool ReverseEdges(const S00e124d0_Entry& a, const S00e124d0_Entry& b) {
    return a.m_obj->m_kVertices[a.m_iIndex] == b.m_obj->m_kVertices[S00e124d0_Map(b.m_iIndex)] &&
           a.m_obj->m_kVertices[S00e124d0_Map(a.m_iIndex)] == b.m_obj->m_kVertices[b.m_iIndex];
}
// Iterates edge pairs, links matching vertices via m_ppLinks, and removes entries when edges are reversed or one is null.
// @fnv 0x00e124d0
// src: HAVOK_LIB 0x00e124d0
void __stdcall hkgpMesh_bindEdgeList(S00e124d0_Table* t) {
    for (int i = 0; i < t->m_uiItemCount; ++i) {
        for (int j = i + 1; j < t->m_uiItemCount; ++j) {
            S00e124d0_Entry* ei = &t->m_data[i];
            S00e124d0_Entry* ej = &t->m_data[j];
            if (ej->m_obj && !ReverseEdges(*ei,*ej)) continue;
            ei->m_obj->m_ppLinks[ei->m_iIndex] = (unsigned int)ej->m_obj + ej->m_iIndex;
            if (ej->m_obj != 0) {
                ej->m_obj->m_ppLinks[ej->m_iIndex] = (unsigned int)ei->m_obj + ei->m_iIndex;
            }
            t->removeAt(j);
            t->removeAt(i);
            --i;
            break;
        }
    }
}

static __forceinline void setXYZ(float* p, float v) { p[0]=v;p[1]=v;p[2]=v; }
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ss(const float*);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_min_ps(__m128, __m128);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_max_ps(__m128, __m128);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_set_ps1(float);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_setr_ps(float,float,float,float);
#endif

struct __declspec(align(16)) BoundsCopy { float x,y,z,w; };
static __forceinline float fMinimumInputValue(float a, float b) { return a > b ? a : b; }
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sub_ps(__m128, __m128);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_rcp_ps(__m128);
#endif


struct BoundNode {
    BoundNode* m_next;
    int unk04;
    int unk08;
    int unk0c;
    __m128 m_vec;
};

extern const float DAT_01011d78;
extern const float DAT_01012068;
extern float DAT_01012054;
extern float DAT_0102295c;
extern __m128 DAT_010c7170;

// Mesh triangle: three vertex pointers and a plane at +0x20; Bound is a 16-byte sphere.
struct MeshPlaneTriangle {
    MeshPlaneTriangle* next; int unk04; BoundNode* points[3];
    int unk14,unk18,unk1c; __m128 plane;
};
struct BoundsMesh {
    int unk00;
    int unk04, unk08, unk0c, unk10;
    BoundNode* m_14;
    int m_18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    MeshPlaneTriangle* faces;
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
    int m_e4;
    int unke8,unkec,unkf0,unkf4,unkf8,unkfc;
    unsigned char badGeometry,unk101,unk102,unk103;
    float edgeThreshold,areaThreshold;
    __declspec(noinline) bool ValidateTriangleAndComputePlane(const __m128*,const __m128*,const __m128*,__m128*,bool);
    __declspec(noinline) bool UpdateTriangleNormal(MeshPlaneTriangle*);


    void UpdateFields_00e11ca0(__m128*);
    __declspec(noinline) void ResetNodeVectors();
    void ScaleMeshVerticesAndUpdateStatistics(__m128* p);
    void BuildHull();
    float hkgpMesh_normalize(__m128* a1, __m128* a2, float a3);
};


static __forceinline float scalarLength(__m128 v) {
    __m128 q=_mm_mul_ps(v,v);
    __m128 d=_mm_add_ss(_mm_shuffle_ps(q,q,0xaa),_mm_add_ss(_mm_shuffle_ps(q,q,0x55),q));
    float f; _mm_store_ss(&f,d);return f;
}
// src: GUESS 0x00e11710 (confidence: medium)
bool BoundsMesh::ValidateTriangleAndComputePlane(const __m128* a,const __m128* b,const __m128* c,__m128* out,bool check) {
    float threshold=edgeThreshold;
    bool valid=true;
    __m128 u=_mm_sub_ps(*b,*a);
    if(check && scalarLength(u)<threshold) {badGeometry=1;valid=false;}
    __m128 v=_mm_sub_ps(*c,*a);
    if(check && scalarLength(v)<threshold) {badGeometry=1;valid=false;}
    __m128 w=_mm_sub_ps(*c,*b);
    if(check && scalarLength(w)<threshold) {badGeometry=1;valid=false;}
    __m128 cross=_mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v,v,0xd2),_mm_shuffle_ps(u,u,0xc9)),_mm_mul_ps(_mm_shuffle_ps(v,v,0xc9),_mm_shuffle_ps(u,u,0xd2)));
    *out=cross;
    __m128 q=_mm_mul_ps(cross,cross);
    __m128 d=_mm_add_ss(_mm_shuffle_ps(q,q,0xaa),_mm_add_ss(_mm_shuffle_ps(q,q,0x55),q));
    d=_mm_sqrt_ss(d);
    float len;_mm_store_ss(&len,d);
    out->m128_f32[3]=len;
    if(check && areaThreshold>len) {badGeometry=1;valid=false;}
    float inv=1.0f/out->m128_f32[3];
    *out=_mm_mul_ps(_mm_set_ps1(inv),*out);
    __m128 product=_mm_mul_ps(*a,*out);
    __m128 dot=_mm_add_ss(_mm_shuffle_ps(product,product,0xaa),_mm_add_ss(_mm_shuffle_ps(product,product,0x55),product));
    __m128 neg=_mm_sub_ss(DAT_010c7160,dot);
    _mm_store_ss(&out->m128_f32[3],neg);
    return valid;
}
// src: GUESS 0x00e11910 (confidence: medium)
bool BoundsMesh::UpdateTriangleNormal(MeshPlaneTriangle* face) {
    __m128 plane;
    if(ValidateTriangleAndComputePlane(&face->points[0]->m_vec,&face->points[1]->m_vec,&face->points[2]->m_vec,&plane,true)) {
        face->plane=plane;return true;
    }
    return false;
}
void BoundsMesh::ResetNodeVectors() {
    for(MeshPlaneTriangle* f=faces;f;f=f->next) {
        f->plane=*(__m128*)&DAT_01267e30;
        UpdateTriangleNormal(f);
    }
}
// Computes min/max of the node vectors; a1 becomes a scaled center, a2 the smallest extent divided by a3; runs helper passes, then BuildHull if m_e4 was set.
// @fnv 0x00e13fa0
// src: XBOX_PDB 0x00e13fa0
float BoundsMesh::hkgpMesh_normalize(__m128* a1, __m128* a2, float a3)
{
    { __m128* __restrict start=a1;
    *start = _mm_setr_ps(DAT_01011d78,DAT_01011d78,DAT_01011d78,DAT_01011d78);
    *a2 = _mm_setr_ps(DAT_01012068,DAT_01012068,DAT_01012068,DAT_01012068);
    }
    if (m_18 != 0) {
        bool flag = m_e4 != 0;
        __m128 mn = m_14->m_vec;
        BoundNode* node = m_14;
        __m128 mx = mn;
        while (node != 0) {
            __m128 v = node->m_vec;
            mn = _mm_min_ps(mn, v);
            mx = _mm_max_ps(mx, v);
            node = node->m_next;
        }
        *a1 = _mm_add_ps(mx, mn);
        __m128 scale1 = _mm_load_ss(&DAT_0102295c);
        *a1 = _mm_mul_ps(_mm_shuffle_ps(scale1, scale1, 0), *a1);
        *a2 = _mm_sub_ps(mx, mn);
        float* f = (float*)a2;
        float m = fMinimumInputValue(f[0],f[1]);
        setXYZ(f,fMinimumInputValue(m,f[2]));
        float inv = 1.0f / a3;
        *a2 = _mm_mul_ps(_mm_set_ps1(inv), *a2);
        BoundsCopy saved = *(BoundsCopy*)a2;
        __m128 s = *a2;
        __m128 w = _mm_unpackhi_ps(s, DAT_010c7170);
        __m128 t = _mm_shuffle_ps(s, w, 0xc4);
        __m128 r = _mm_rcp_ps(t);
        __m128 p = _mm_mul_ps(_mm_mul_ps(r, t), r);
        *a2 = _mm_sub_ps(_mm_add_ps(r, r), p);
        UpdateFields_00e11ca0(a1);
        ScaleMeshVerticesAndUpdateStatistics(a2);
        ResetNodeVectors();
        *a2 = *(__m128*)&saved;
        __m128 scale2 = _mm_load_ss(&DAT_01012054);
        *a1 = _mm_mul_ps(_mm_shuffle_ps(scale2, scale2, 0), *a1);
        if (flag) {
            BuildHull();
        }
    }
    return ((float*)a2)[0];
}

extern char DAT_010eaf30[];
extern char DAT_010eaf44[];
typedef S_00e13910_Triangle NakedFace;
typedef S_00e13910_Edge NakedEdgeRef;
inline bool edgesMatch(const NakedEdgeRef& a, const NakedEdgeRef& b) { return !b.m_pkTriangle || (a.m_pkTriangle->m_kVertices[a.m_uiEdgeIndex] == b.m_pkTriangle->m_kVertices[(9 >> (b.m_uiEdgeIndex * 2)) & 3] && a.m_pkTriangle->m_kVertices[(9 >> (a.m_uiEdgeIndex * 2)) & 3] == b.m_pkTriangle->m_kVertices[b.m_uiEdgeIndex]); }

void __cdecl ResizeAudioStream(void*, void*, int);
static inline void copyEdge(void*, const void*, int);

struct NakedArray
{
    NakedEdgeRef* data;
    int size;
    int cap;
    void reserve(Allocator& heap, int capacity)
    {
        if ((int)(cap & 0x3fffffff) < capacity)
        {
            int n = (int)(cap & 0x3fffffff)*2;
            if (n <= capacity) n = capacity;
            hkArrayUtil__reserve(&heap, (FUN_00e22970_Cls*)this, n, 8);
        }
    }
    void clear() { size=0; }
    void deallocate(Allocator& heap)
    {
        if (!(cap & 0x80000000))
            heap.freeBlock(data, (cap & 0x3fffffff)*8);
    }
    void release(Allocator& heap) { clear(); deallocate(heap); }
    void removeAt(int index)
    {
        --size;
        if (size != index) copyEdge(data + index, data + size, sizeof(NakedEdgeRef));
    }
    void append(const NakedEdgeRef& edge)
    {
        Allocator& heap = meshHeap(hkMemoryRouter_getInstance());
        if (size == (int)(cap & 0x3fffffff))
            ResizeAudioStream(&heap, this, 8);
        new (data + size) NakedEdgeRef(edge);
        ++size;
    }
};

static inline void copyEdge(void* destination, const void* source, int bytes)
{
    int i = 0;
    do { *(int*)((char*)destination+i) = *(const int*)((const char*)source+i); i+=4; } while (i<bytes);
}

void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize);

struct MeshEdgeRepair
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
    NakedFace* m_pHead2c;
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
    void hkgpMesh_fixBindings();
};

// Collects unlinked edges from the m_pHead2c face list, binds matching reversed pairs, and logs the initial edge count and twice the number of pairs bound.
// @fnv 0x00e14d10
// src: HAVOK_LIB 0x00e14d10
void MeshEdgeRepair::hkgpMesh_fixBindings()
{
    NakedArray arr;
    arr.data = 0;
    arr.size = 0;
    arr.cap = 0x80000000;

    int fixed = 0;
    arr.reserve(meshHeap(hkMemoryRouter_getInstance()), 0x400);

    for (NakedFace* face = m_pHead2c; face != 0; face = (NakedFace*)face->m_unk00)
    {
        int k = 0;
        unsigned int* pe = face->m_ppLinks;
        for (; k < 3; ++k, ++pe)
        {
            if ((*pe & 0xfffffffc) == 0)
            {
                arr.append(NakedEdgeRef(face, k));
            }
        }
    }

    int iOriginalCount = arr.size;
    for (int i = 0; i < arr.size; ++i)
    {
        int j = i + 1;
        if (j >= arr.size)
            continue;
        NakedEdgeRef* pEdgeA = arr.data + i;
        NakedEdgeRef* pEdgeB = arr.data + j;
        for (;;)
        {
            if (!edgesMatch(*pEdgeA,*pEdgeB)) goto nomatch;
            pEdgeA->bind(*pEdgeB);
            arr.removeAt(j);
            fixed++;
            i--;
            break;
        nomatch:
            ++j;
            ++pEdgeB;
            if (j >= arr.size)
                break;
        }
    }

    if (iOriginalCount != 0)
    {
        int buf[0x80];
        CharBuffer msg;
        msg.FUN_00cb1600((char*)buf, 0x200);
        msg.ProcessAndReturnValue_00cc01c0(DAT_010eaf30)->WriteInt(iOriginalCount)->ProcessAndReturnValue_00cc01c0(DAT_010eaf44)->WriteInt(fixed * 2);
        DAT_01268360->Report(0, 0xffffffff, (const char*)buf, DAT_010eaeb4, 0xcc2);
        msg.FUN_00cc00e0();
    }

    m_b101 = 0;
    arr.release(meshHeap(hkMemoryRouter_getInstance()));
}



namespace hkRouter { __declspec(nothrow) hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw(); }
__declspec(nothrow) void __cdecl ResizeAudioStream(void*,void*,int) throw();
template<class T> struct HullArray {
 T* data; int size; int capacityAndFlags;
 __declspec(nothrow) __forceinline HullArray():data(0),size(0),capacityAndFlags(0x80000000) {}
 __declspec(nothrow) __forceinline ~HullArray() {
  hkMemoryAllocator& heap=hkRouter::hkMemoryRouter_getInstance().heap();
  size=0;
  if((capacityAndFlags&0x80000000u)==0) heap.bufFree(data,(capacityAndFlags&0x3fffffff)*sizeof(T));
 }
 __forceinline void AddBack(const T& value) {
  hkMemoryRouter& router=hkRouter::hkMemoryRouter_getInstance();
  if(size==(capacityAndFlags&0x3fffffff)) ResizeAudioStream(router.m_heap,this,sizeof(T));
  data[size]=value; ++size;
 }
 __forceinline int indexOf(T value) const {
  for(int i=0;i<size;++i) if(data[i]==value) return i;
  return -1;
 }
};
template<class T> struct HullLocalArray : HullArray<T> {
 T* localMemory;
 __declspec(nothrow) __forceinline HullLocalArray(int capacity) {
  hkMemoryRouter& router=hkRouter::hkMemoryRouter_getInstance();
  T* memory=static_cast<T*>(static_cast<void*>(reinterpret_cast<char*&>(router.m_stack.m_next.m_storage)));
  reinterpret_cast<char*&>(router.m_stack.m_next.m_storage)+=((capacity*sizeof(T)+127)&~127);
  this->data=memory;
  this->capacityAndFlags=capacity|0x80000000;
  localMemory=memory;
 }
 __declspec(nothrow) __forceinline ~HullLocalArray() {
  if(!wasReallocated()) this->size=0; deallocateStack(localMemory);
 }
 __forceinline bool wasReallocated() const { return localMemory!=this->data; }
 static __forceinline void deallocateStack(void* p) { reinterpret_cast<char*&>(hkRouter::hkMemoryRouter_getInstance().m_stack.m_next.m_storage)=static_cast<char*>(p);
 }
};
struct HullDescriptor {
 enum Kind { TRIANGLE=1,EDGE=2,VERTEX=3 };
 int kind;
 S_00e13910_Edge edge;
};
inline unsigned int encodedEdge(const S_00e13910_Edge& edge) {
 return edge.m_uiEdgeIndex+reinterpret_cast<unsigned int>(edge.m_pkTriangle);
}
// Collects triangles referenced by descriptors into a local array, then returns 1 if every descriptor's triangle is found in that array.
// @fnv 0x00e155b0
// src: HAVOK_LIB 0x00e155b0
int __cdecl hkgpMesh_Location_Region_hasCommonSuperset(const HullDescriptor* const* descriptors,int count) {
 HullLocalArray<S_00e13910_Triangle*> faces(64);
 for(int i=0;i<count;++i) {
  S_00e13910_Edge edge=descriptors[i]->edge;
  switch(descriptors[i]->kind) {
  case HullDescriptor::TRIANGLE: faces.AddBack(edge.m_pkTriangle); break;
  case HullDescriptor::EDGE:
   faces.AddBack(edge.m_pkTriangle);
   edge=edge.link();
   if(edge.isValid()) faces.AddBack(edge.m_pkTriangle);
   break;
  case HullDescriptor::VERTEX:
   do {
    faces.AddBack(edge.m_pkTriangle);
    edge=edge.prev().link();
   } while(edge.isValid() && encodedEdge(edge)!=encodedEdge(descriptors[i]->edge));
   break;
  default: break;
  }
 }
 for(int i=0;i<count;++i) {
  S_00e13910_Triangle* triangle=descriptors[i]->edge.m_pkTriangle;
  if(faces.indexOf(triangle)==-1) return 0;
 }
 return 1;
}

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ps1(const float*);
#endif
float ZToReal(__m128 v) {
    float f;
    _mm_store_ss(&f,v);
    return f;
}
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ss(const float*);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sub_ps(__m128,__m128);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_sqrt_ss(__m128);
#endif
extern double DAT_01011588, DAT_01016408;
void __cdecl ResizeAudioStream(Allocator*,void*,int);
struct ZBox {
    __m128 low,high;
}
;
struct ZPlane {
    bool* FUN_00c7f520(bool*,float);
}
;
void __cdecl Runtime_ProcessEntries_00cbebf0(const Vec4f**,int,ZBox*);
template<class T> struct ZArray {
    T* data;
    int size;
    unsigned capacity;
    ZArray():data(0),size(0),capacity(0x80000000) {
    }
    void append(const T& item) {
        Allocator& a=meshHeap(hkMemoryRouter_getInstance());
        if(size==(capacity&0x3fffffff)) ResizeAudioStream(&a,this,sizeof(T));
        new(data+size) T(item);
        ++size;
    }
    void release() {
        Allocator& a=meshHeap(hkMemoryRouter_getInstance());
        size=0;
        if(!(capacity&0x80000000)) a.freeBlock(data,(capacity&0x3fffffff)*sizeof(T));
        data=0;
        capacity=0x80000000;
    }
}
;
struct ZNode {
    ZNode* next;
    int unk04;
    TriVertex* unk08;
    TriVertex* unk0c;
    TriVertex* unk10;
    int unk14,unk18,unk1c;
    ZPlane unk20;
    int unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    int unk40;
}
;
template<> void ZArray<ZNode*>::append(ZNode* const& item) {
    Allocator& a=meshHeap(hkMemoryRouter_getInstance());
    if(size==(capacity&0x3fffffff)) ResizeAudioStream(&a,this,4);
    data[size++]=item;
}
struct ZTree {
    void UpdateState_00d9be30();
    void BuildTree(ZBox*,ZNode**,int,ZArray<int>*);
}
;
struct Z_E15E50 {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28;
    ZNode* unk2c;
    int unk30,unk34,unk38,unk3c;
    ZTree unk40;
    void BuildTreeFromPaddedNodeBounds();
}
;
// Builds padded boxes for each node passing the FUN_00c7f520 test, calls BuildTree on them, and remaps those nodes' unk40 indices through the resulting mapping.
// @fnv 0x00e15e50
// src: GUESS 0x00e15e50 (confidence: medium)
void Z_E15E50::BuildTreeFromPaddedNodeBounds() {
    unk40.UpdateState_00d9be30();
    ZArray<ZBox> boxes;
    ZArray<ZNode*> nodes;
    int index=0;
    for(ZNode* node=unk2c; node; node=node->next) {
        const Vec4f* vertices[3]={
            &node->unk08->m_vContactPosition,&node->unk0c->m_vContactPosition,&node->unk10->m_vContactPosition}
            ;
            bool ok;
            if(*node->unk20.FUN_00c7f520(&ok,DAT_010141cc)) {
                ZBox box;
                Runtime_ProcessEntries_00cbebf0(vertices,3,&box);
                __m128* pBox=(__m128*)&box;
                (void)box.low;
                __m128 v=_mm_sub_ps(pBox[0],pBox[1]);
                v=_mm_mul_ps(v,v);
                __m128 y=_mm_shuffle_ps(v,v,0x55);
                __m128 z=_mm_shuffle_ps(v,v,0xaa);
                y=_mm_add_ss(y,v);
                __m128 s=_mm_add_ss(z,y);
                float len=ZToReal(_mm_sqrt_ss(s))*DAT_01011588;
                len=len*0.009999999776482582;
                __m128 r=_mm_load_ps1(&len);
                pBox[1]=_mm_add_ps(pBox[1],r);
                pBox[0]=_mm_sub_ps(pBox[0],r);
                node->unk40=index++;
                boxes.append(box);
                nodes.append(node);
            }
            else node->unk40=0x7fffffff;
        }
        ZArray<int> mapping;
        unk40.BuildTree(boxes.data,nodes.data,boxes.size,&mapping);
        for(ZNode* node=unk2c; node; node=node->next) if(node->unk40!=0x7fffffff) node->unk40=mapping.data[node->unk40];
        mapping.release();
        nodes.release();
        boxes.release();
    }

extern char DAT_010eb0d0[];
extern char DAT_010eb0c4[];
extern char DAT_010eb0b8[];
extern float DAT_01013ea4;
void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();
struct E15Target {
    void BuildTreeFromPaddedNodeBounds() throw();
};
template <typename T>
struct E1D960ArrayLocalForm { // local form of hkArray: 0x00e1d960 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    E1D960ArrayLocalForm() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~E1D960ArrayLocalForm() throw()
    {
        Allocator& alloc = meshHeap(hkMemoryRouter_getInstance());
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.freeBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int indexOf(const T& t) const throw()
    {
        for (int i = 0; i < m_iElementCount; i++)
            if (m_data[i] == t) return i;
        return -1;
    }
    void AddBack(const T& t) throw()
    {
        Allocator& alloc = meshHeap(hkMemoryRouter_getInstance());
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, sizeof(T));
        E153F0ConstructWithCopy(m_data + m_iElementCount, 1, t);
        ++m_iElementCount;
    }
};
struct E1D960Body {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    E12160Triangle* m_pTriangle;
};
struct E1D960Pair {
    E1D960Body* a;
    E1D960Body* b;
};
struct QueryBase {
    virtual ~QueryBase() throw() {}
};
struct QueryCtx : QueryBase {
    E1D960ArrayLocalForm<E1D960Pair>* arr;
    QueryCtx(E1D960ArrayLocalForm<E1D960Pair>* a) throw() : arr(a) {}
};
void __cdecl HkaabbtreequeryutilsGsEhscNogsNoehsc_ProcessEntries_00d1d890(void* a, void* b, QueryCtx* ctx) throw();
bool __cdecl hkgpMesh_clipTriangles(void* self, E12160Triangle* fa, void* obj, E12160Triangle* fb, float f) throw();
struct DelTarget {
    virtual ~DelTarget();
};
struct E1D960Mesh {
    __declspec(nothrow) void RemoveTriangle(E12160Triangle* apNode);
};
__declspec(nothrow) bool __cdecl TriangleHasVertexAtPoint(const E12160Triangle* triangle, const float* point);
struct MeshMerge960 {
    FUN_00e1b750* hkgpMesh_trim(Builder* apBuilder);
};
// Builds an object from apBuilder, tests triangle pairs against this, removes coincident pairs and returns it if any test succeeded, else deletes it.
// @fnv 0x00e1d960
// src: HAVOK_LIB 0x00e1d960
FUN_00e1b750* MeshMerge960::hkgpMesh_trim(Builder* apBuilder)
{
    bool phaseFlag = false;
    FUN_00e1b750* obj = new (FUN_00d76ca0::allocate(meshHeap(hkMemoryRouter_getInstance()), 0x110)) FUN_00e1b750();
    ((FUN_00e1d900_cls*)obj)->hkgpMesh_appendFromConvexHull(apBuilder);
    {
        unsigned int buf[0x80];
        CharBuffer msg;
        msg.FUN_00cb1600((char*)buf, 0x200);
        msg.ProcessAndReturnValue_00cc01c0(DAT_010eb0d0);
        DAT_01268360->Report(0, (unsigned int)-1, (char*)buf, DAT_010eaeb4, 0x8fd);
        msg.FUN_00cc00e0();
    }
    void* sub = &obj->sub40;
    bool found;
    do {
        found = false;
        ((E15Target*)obj)->BuildTreeFromPaddedNodeBounds();
        ((E15Target*)this)->BuildTreeFromPaddedNodeBounds();
        E1D960ArrayLocalForm<E1D960Pair> pairs;
        {
            QueryCtx ctx(&pairs);
            HkaabbtreequeryutilsGsEhscNogsNoehsc_ProcessEntries_00d1d890(sub, sub, &ctx);
        }
        for (int i = 0; i < pairs.m_iElementCount; i++) {
            E12160Triangle* ta = pairs.m_data[i].a->m_pTriangle;
            E12160Triangle* tb = pairs.m_data[i].b->m_pTriangle;
            if (hkgpMesh_clipTriangles(this, ta, obj, tb, DAT_01013ea4)) {
                found = true;
                phaseFlag = true;
            }
        }
    } while (found);
    if (phaseFlag) {
        {
            {
                unsigned int buf[0x80];
                CharBuffer msg;
                msg.FUN_00cb1600((char*)buf, 0x200);
                msg.ProcessAndReturnValue_00cc01c0(DAT_010eb0c4);
                DAT_01268360->Report(0, (unsigned int)-1, (char*)buf, DAT_010eaeb4, 0x918);
                msg.FUN_00cc00e0();
            }
            E1D960ArrayLocalForm<E1D960Pair> pairs;
            E1D960ArrayLocalForm<E12160Triangle*> merged;
            ((E15Target*)obj)->BuildTreeFromPaddedNodeBounds();
            ((E15Target*)this)->BuildTreeFromPaddedNodeBounds();
            {
                QueryCtx ctx(&pairs);
                HkaabbtreequeryutilsGsEhscNogsNoehsc_ProcessEntries_00d1d890(&((FUN_00e1b750*)this)->sub40, sub, &ctx);
            }
            for (int i = 0; i < pairs.m_iElementCount; i++) {
                const E1D960Pair& pair = pairs.m_data[i];
                E12160Triangle* ta = pair.a->m_pTriangle;
                E12160Triangle* tb = pair.b->m_pTriangle;
                if (merged.indexOf(ta) != -1) continue;
                if (merged.indexOf(tb) != -1) continue;
                if (!TriangleHasVertexAtPoint(ta, tb->m_kVertices[0]->m_vContactPosition)) continue;
                if (!TriangleHasVertexAtPoint(ta, tb->m_kVertices[1]->m_vContactPosition)) continue;
                if (!TriangleHasVertexAtPoint(ta, tb->m_kVertices[2]->m_vContactPosition)) continue;
                if (!TriangleHasVertexAtPoint(tb, ta->m_kVertices[0]->m_vContactPosition)) continue;
                if (!TriangleHasVertexAtPoint(tb, ta->m_kVertices[1]->m_vContactPosition)) continue;
                if (!TriangleHasVertexAtPoint(tb, ta->m_kVertices[2]->m_vContactPosition)) continue;
                merged.AddBack(ta);
                merged.AddBack(tb);
                ((E1D960Mesh*)this)->RemoveTriangle(ta);
                ((E1D960Mesh*)obj)->RemoveTriangle(tb);
            }
        }
        {
            unsigned int buf[0x80];
            CharBuffer msg;
            msg.FUN_00cb1600((char*)buf, 0x200);
            msg.ProcessAndReturnValue_00cc01c0(DAT_010eb0b8);
            DAT_01268360->Report(0, (unsigned int)-1, (char*)buf, DAT_010eaeb4, 0x939);
            msg.FUN_00cc00e0();
        }
        ((E15Target*)this)->BuildTreeFromPaddedNodeBounds();
        return obj;
    }
    if (obj) {
        delete (DelTarget*)obj;
    }
    return 0;
}

template<class T> __forceinline void copyRange360(T* p, int count, const T& value) { for (int i=0; i<count; ++i) p[i] = value; }
struct Piece {
    virtual void destroy(unsigned int);
    hkgpConvexHull* GetConvexHull();
};
template<class T> struct Array360 {
    T* data;
    int size;
    int capacity;
    Array360() : data(0), size(0), capacity(0x80000000) {}
    T& operator[](int i) { return data[i]; }
    int GetLogicalSize() const { return size; }
};
typedef Array360<Piece*> Pieces;
struct Builder360 {
    virtual void destroy(unsigned int);
    int* BuildProjectedBoundaryMesh(int**, int);
    void hkgpMesh_floodFillDetachedParts();
    void hkgpMesh_explodeParts(Pieces*, int, int);
};
struct Factory360 { Builder360* hkgpMesh_clone();
int* hkgpMesh_cutAndCap(int* result, int input, Pieces* output, float low, float high); };
void __cdecl ResizeAudioStream(void*, void*, int);
struct Hull360 {
    float ComputeScaledPowerRatio();
    float hkgpConvexHull_getVolume();
};
// Builds pieces and checks each hull against high/low; on success appends all pieces to output, else destroys them; the status is written through result.
// @fnv 0x00e1f360
// src: HAVOK_LIB 0x00e1f360
int* Factory360::hkgpMesh_cutAndCap(int* result, int input, Pieces* output, float low, float high)
{
    Builder360* builder = hkgpMesh_clone();
    int* out = *(int* volatile*)&result;
    *out = 10;
    int status = *builder->BuildProjectedBoundaryMesh(&result, input);
    *out = status;
    if (status == 0) {
        Pieces pieces;
        builder->hkgpMesh_floodFillDetachedParts();
        builder->hkgpMesh_explodeParts(&pieces, 1, 1);
        for (int i = 0; i < pieces.GetLogicalSize(); ++i) {
            Hull360* hull = (Hull360*)pieces[i]->GetConvexHull();
            if (!hull) *out = 2;
            else if (hull->ComputeScaledPowerRatio() < high || hull->hkgpConvexHull_getVolume() < low) *out = 8;
        }
        if (*out == 0) {
            for (int i = 0; i < pieces.GetLogicalSize(); ++i) {
                Piece** item = &pieces[i];
                hkMemoryRouter& router = hkMemoryRouter_getInstance();
                if (output->size == (output->capacity & 0x3fffffff))
                    ResizeAudioStream(reinterpret_cast<Allocator*>(router.m_heap), output, 4);
                Piece** slot = &output->data[output->size];
                copyRange360(slot, 1, *item);
                output->size++;
            }
        } else {
            for (int i = 0; i < pieces.GetLogicalSize(); ++i) {
                Piece* item = pieces[i];
                if (item) item->destroy(1);
                _ReadWriteBarrier();
            }
        }
        Allocator& heap = meshHeap(hkMemoryRouter_getInstance());
        pieces.size = 0;
        if ((pieces.capacity & 0x80000000u) == 0) heap.freeBlock(pieces.data, (pieces.capacity & 0x3fffffff)*4);
    }
    if (builder) builder->destroy(1);
    return out;
}

extern int DAT_010eae0c;
extern int DAT_0126ec00;
extern int DAT_01268370;
extern int DAT_01268380;
extern int DAT_01268390;
extern int DAT_012683a0;
extern float DAT_0104da48;
extern float DAT_0104e148;
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_load_ss(const float* p);
#endif

struct S00e4c730_Obj
{
    int hkGsk_getClosestPoint(void* p1, int p2, void* p3);
};

struct QuadFields { unsigned int x,y,z,w; };
struct S00e22de0_frame
{
    volatile float m_f;      // 0x00
    int m_kPointA;                 // 0x04
    void* m_p8;              // 0x08
    int m_kPointB;                 // 0x0c
    QuadFields m_v10;   // 0x10
    QuadFields m_v20;   // 0x20
    QuadFields m_v30;   // 0x30
    QuadFields m_v40;   // 0x40
    void* m_pa0;            // 0x50
    void* m_pa1;            // 0x54
    int unk58;
    int unk5C;
    QuadFields m_v60;   // 0x60
    QuadFields m_out;   // 0x70
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    S00e4c730_Obj m_obj;     // 0x90
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int m_flag;              // 0xa8
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
};

// Fills a local frame from a, b, c and DAT_01268370..DAT_012683a0, calls FUN_00e4c730, and returns the w of its output, or DAT_0104e148 if it returns nonzero.
// @fnv 0x00e22de0
// src: XBOX_PDB 0x00e22de0
float __stdcall IConvexOverlapImpl_distance(int a, int b, bool c)
{
    S00e22de0_frame f;
    S00e22de0_frame* __restrict q = &f;
    DAT_0126ec00++;
    *(void**)&q->m_f = &DAT_010eae0c;
    q->m_kPointA = a;
    q->m_p8 = &DAT_010eae0c;
    q->m_kPointB = b;
    q->m_pa0 = (void*)&q->m_f;
    *(__m128*)&q->m_v10 = *(const __m128*)&DAT_01268370;
    *(__m128*)&q->m_v20 = *(const __m128*)&DAT_01268380;
    int flag = (c == 0);
    q->m_pa1 = &q->m_p8;
    *(__m128*)&q->m_v30 = *(const __m128*)&DAT_01268390;
    *(__m128*)&q->m_v40 = *(const __m128*)&DAT_012683a0;
    *(__m128*)&q->m_v60 = _mm_load_ss(&DAT_0104da48);
    q->m_flag = flag;
    if (q->m_obj.hkGsk_getClosestPoint(&q->m_v10, 0, &q->m_out) == 0)
    {
        _mm_store_ss((float*)&q->m_f, _mm_shuffle_ps(*(__m128*)&q->m_out, *(__m128*)&q->m_out, 0xff));
        q->m_f = q->m_f;
        return q->m_f;
    }
    else
    {
        *(float*)&q->m_f = DAT_0104e148;
    }
    return q->m_f;
}

struct S00e24650_Vtx {
    unsigned int unk00;
    unsigned int unk04;
    int m_uiX;
    int m_uiY;
};

struct S00e24650_Tri {
    unsigned int unk00;
    unsigned int unk04;
    S00e24650_Vtx* m_kVertices[3];
    unsigned int m_ppLinks[3];
};

struct S00e24650_Edge {
    S00e24650_Tri* m_pkTriangle;
    unsigned int m_uiEdgeIndex;
    S00e24650_Edge() {}
    S00e24650_Edge(S00e24650_Tri* t, unsigned int i) : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    S00e24650_Edge(unsigned int tagged) {m_pkTriangle=(S00e24650_Tri*)tagged; m_uiEdgeIndex=(unsigned int)m_pkTriangle&3; m_pkTriangle=(S00e24650_Tri*)((unsigned int)m_pkTriangle&~3u);}
    S00e24650_Edge(const S00e24650_Edge& o) { m_pkTriangle=o.m_pkTriangle; m_uiEdgeIndex=o.m_uiEdgeIndex; }
    S00e24650_Edge next() const { S00e24650_Edge r(*this); r.m_uiEdgeIndex=(9 >> (r.m_uiEdgeIndex << 1)) & 3; return r; }
    S00e24650_Edge prev() const { return S00e24650_Edge(m_pkTriangle, (0x12 >> (m_uiEdgeIndex << 1)) & 3); }
    S00e24650_Edge link() const { return S00e24650_Edge(m_pkTriangle->m_ppLinks[m_uiEdgeIndex]); }
    bool isNaked() const { return (m_pkTriangle->m_ppLinks[m_uiEdgeIndex] & 0xfffffffcu) == 0; }
    S00e24650_Vtx* start() const { return m_pkTriangle->m_kVertices[m_uiEdgeIndex]; }
    S00e24650_Vtx* end() const { return m_pkTriangle->m_kVertices[(9>>(m_uiEdgeIndex<<1))&3]; }
};

struct EdgeWalker { S00e24650_Edge hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_locateExistingVertex(S00e24650_Edge k, unsigned int a4); S00e24650_Edge hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_locateExistingEdge(S00e24650_Edge e, unsigned int a4, S00e24650_Vtx* v); };

// Walks edge e (FUN_00e23df0, then link/next to a naked edge for border start vertices, then prev/link) until an edge ending at v is found.
// @fnv 0x00e24650
// src: HAVOK_LIB 0x00e24650
S00e24650_Edge EdgeWalker::hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_locateExistingEdge(S00e24650_Edge e, unsigned int a4, S00e24650_Vtx* v)
{
    S00e24650_Edge arg(e); e=hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_locateExistingVertex(arg,a4);
    if (e.end() == v)
        return e;
    {
        S00e24650_Vtx* s = e.start();
        if (s->m_uiX == 0 || s->m_uiX == 0x7fff || s->m_uiY == 0 || s->m_uiY == 0x7fff) {
            while (!e.isNaked())
                e = e.link().next();
        }
    }
    while (e.end() != v)
        e = e.prev().link();
    return e;
}

struct S_00e248b0_Tri {
    int unk00;
    int unk04;
    int v[3];
    unsigned int link[3];
};

static __forceinline int S_00e248b0_next(int e) { return (9 >> (e * 2)) & 3; }

struct S_00e248b0_Edge {
    S_00e248b0_Tri* tri;
    int e;
    S_00e248b0_Edge() {}
    S_00e248b0_Edge(S_00e248b0_Tri* t, int i) : tri(t), e(i) {}
    bool isNaked() const { return (tri->link[e] & ~3u) == 0; }
    S_00e248b0_Edge link() const { unsigned int l = tri->link[e]; S_00e248b0_Edge r; r.e = l & 3; r.tri = (S_00e248b0_Tri*)(l & ~3u); return r; }
    S_00e248b0_Edge next() const { return S_00e248b0_Edge(tri, S_00e248b0_next(e)); }
    int start() const { return tri->v[e]; }
    int end() const { return tri->v[S_00e248b0_next(e)]; }
    unsigned int uid() const { return (unsigned int)tri + e; }
};

struct S_00e248b0_Elem {
    S_00e248b0_Tri* tri;
    int e;
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



static __forceinline hkMemoryAllocator* S_00e248b0_heap(hkMemoryRouter& r)
{
    return (hkMemoryAllocator*)reinterpret_cast<Allocator*>(r.m_heap);
}

void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize);

struct S_00e248b0_Arr {
    S_00e248b0_Elem* m_data;
    int m_iElementCount;
    int m_cap;
    S_00e248b0_Arr() : m_data(0), m_iElementCount(0), m_cap(0x80000000) {}
    static void* operator new(unsigned int size) { return S_00e248b0_heap(hkMemoryRouter_getInstance())->blockAlloc(size); }
};

static __forceinline S_00e248b0_Arr* BoundaryCore(S_00e248b0_Edge& cur, S_00e248b0_Edge start) { S_00e248b0_Arr* arr=0;
        
        arr = new S_00e248b0_Arr;
        do
        {
            hkMemoryRouter& r = hkMemoryRouter_getInstance();
            if (arr->m_iElementCount == (arr->m_cap & 0x3fffffff))
                ResizeAudioStream(reinterpret_cast<Allocator*>(r.m_heap), arr, 0x40);
            S_00e248b0_Elem* el = &arr->m_data[arr->m_iElementCount++];
            el->tri = cur.tri;
            el->e = cur.e;
            if (cur.end() == start.start())
                break;
            cur = cur.next();
            while (!cur.isNaked())
                cur = cur.link().next();
        } while (cur.uid() != start.uid());

        if (arr->m_iElementCount > 0)
        {
            S_00e248b0_Elem* first = &arr->m_data[0];
            S_00e248b0_Elem* last = &arr->m_data[arr->m_iElementCount - 1];
            int nl = S_00e248b0_next(last->e);
            if (first->tri->v[first->e] != last->tri->v[nl])
                arr->m_iElementCount = 0;
        }
        if (arr->m_iElementCount < 3)
        {
            if (arr->m_iElementCount == 2)
            {
                S_00e248b0_Elem* d = arr->m_data;
                S_00e248b0_Tri* t1 = d[1].tri;
                if (t1 == 0)
                    goto done;
                int e1 = d[1].e;
                int n1 = S_00e248b0_next(e1);
                if (d[0].tri->v[d[0].e] == t1->v[n1])
                {
                    int n0 = S_00e248b0_next(d[0].e);
                    if (d[0].tri->v[n0] == t1->v[e1])
                        goto done;
                }
            }
            hkMemoryAllocator* heap = S_00e248b0_heap(hkMemoryRouter_getInstance());
            int cap = arr->m_cap;
            arr->m_iElementCount = 0;
            if ((cap & 0x80000000) == 0)
                heap->bufFree(arr->m_data, (cap & 0x3fffffff) * sizeof(S_00e248b0_Elem));
            arr->m_data = 0;
            arr->m_cap = 0x80000000;
            S_00e248b0_heap(hkMemoryRouter_getInstance())->blockFree(arr, 12);
            return 0;
        }
done:
        return arr;
}
// Returns a boundary array for the edge if it is naked, otherwise returns null.
// @fnv 0x00e248b0
// src: HAVOK_LIB 0x00e248b0
S_00e248b0_Arr* __cdecl hkgpMeshInternals_createRing(S_00e248b0_Edge cur) { S_00e248b0_Arr* result=0; if(cur.isNaked()) result=BoundaryCore(cur,cur); return result; }

template <typename V> struct TriBase {
    int m_unk00;
    int m_unk04;
    V m_vtx[3];
    __forceinline V& vtx(int i) { return m_vtx[i]; }
};
typedef TriBase<void*> Tri;

template <typename SELF, typename T> struct EdgeBase {
    EdgeBase() {}
    EdgeBase(T* t, hkUint32 i) : m_tri(t), m_idx(i) {}
    static __forceinline const SELF& none() { static const SELF e(0, 0); return e; }
    __forceinline void*& from() const { return m_tri->vtx(m_idx); }
    T* m_tri;
    hkUint32 m_idx;
};
struct EdgeT : EdgeBase<EdgeT, Tri> {
    EdgeT() {}
    EdgeT(Tri* t, hkUint32 i) : EdgeBase<EdgeT, Tri>(t, i) {}
    EdgeT(const EdgeT& o) : EdgeBase<EdgeT, Tri>(o.m_tri, o.m_idx) {}
};

struct Bool8 {
    char m_kPointB;
    Bool8(bool b) { m_kPointB = (char)b; }
    operator bool() const { return m_kPointB != 0; }
};
struct KindT { int v; Bool8 operator==(int o) const { return v == o; } };
struct Where {
    enum { IN_FACE = 0, ON_EDGE = 1, AT_VERTEX = 2 };
    KindT m_kind;
    EdgeT m_usTrailingValue;
};

struct S00e24aa0_Obj {
    int unk00;
    Where LocatePoint(int x, int y);
    EdgeT hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_locateExistingEdge(EdgeT e, void* a, void* b);
    EdgeT hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_locateExistingEdge_00e24aa0(int x0, int y0, int x1, int y1);
};

// Returns the edge between two points if both are vertices, otherwise returns EdgeT::none().
// @fnv 0x00e24aa0
// src: HAVOK_LIB 0x00e24aa0
EdgeT S00e24aa0_Obj::hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_locateExistingEdge_00e24aa0(int x0, int y0, int x1, int y1)
{
    Where w0 = LocatePoint(x0, y0);
    Where w1 = LocatePoint(x1, y1);
    if ((w0.m_kind == Where::AT_VERTEX) && (w1.m_kind == Where::AT_VERTEX))
    {
        return hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_locateExistingEdge(w0.m_usTrailingValue, w0.m_usTrailingValue.from(), w1.m_usTrailingValue.from());
    }
    return EdgeT::none();
}

struct GateE10 { char value; GateE10() {} GateE10(bool b):value(b) {} operator bool() const { return value != 0; } };
extern "C" __m128 _mm_set_ss(float);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128,__m128);
extern "C" __m128 _mm_andnot_ps(__m128,__m128);

// The unit's normalization test binds to hkVector4::isNormalized3 at 0x00c7f520.
// Its declaration is not in the shared header yet; preserve the member-call ABI here.
GateE10* __cdecl MeshVectorIsNormalized3();
static __forceinline GateE10* meshVectorIsNormalized3(const hkVector4& vector, GateE10& result, float epsilon) {
    typedef GateE10* (__thiscall* Test)(const hkVector4*, GateE10*, float);
    return ((Test)MeshVectorIsNormalized3)(&vector, &result, epsilon);
}
static __forceinline float meshVectorSquaredLength(const __m128& vector) {
    __m128 q = _mm_mul_ps(vector,vector);
    __m128 y = _mm_shuffle_ps(q,q,0x55);
    __m128 a = _mm_add_ss(y,q);
    __m128 z = _mm_shuffle_ps(q,q,0xaa);
    float value; _mm_store_ss(&value,_mm_add_ss(z,a)); return value;
}
static __forceinline int meshVectorUnitNonzero(__m128& vector) {
    float sq=meshVectorSquaredLength(vector);
    if(sq!=0.0f) { float r=sqrtf(sq); r=1.0f/r; vector=_mm_mul_ps(_mm_set_ps1(r),vector); return 0; }
    return 1;
}
static __forceinline hkVector4& meshVectorFastUnit(hkVector4& vector, __m128 cZero, __m128 cThree, __m128 cHalf) {
    __m128 vec = vector.q();
    __m128 sq = _mm_mul_ps(vec, vec);
    __m128 s1 = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 a1 = _mm_add_ss(s1, sq);
    __m128 s2 = _mm_shuffle_ps(sq, sq, 0xaa);
    __m128 len = _mm_add_ss(s2, a1);
    __m128 r = _mm_rsqrt_ss(len);
    __m128 eq = _mm_cmpeq_ss(len, cZero);
    __m128 scale = _mm_andnot_ps(eq, _mm_mul_ss(_mm_mul_ss(cHalf, r), _mm_sub_ss(cThree, _mm_mul_ss(_mm_mul_ss(len, r), r))));
    vector.q() = _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), vec);
    return vector;
}
struct VertE10 {
    VertE10* next;
    int unk04;
    int unk08;
    int unk0c;
    hkVector4 pos10;
    hkVector4 acc20;
};
struct FaceE10 {
    FaceE10* next;
    int unk04;
    VertE10* verts[3];
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 nrm20;
};
struct HostE10 {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    VertE10* list14;
    int unk18; int unk1c; int unk20; int unk24; int unk28;
    FaceE10* faces2c;
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
    unsigned char b100;
    unsigned char flag101;
    void AccumulateAndNormalizeVertexNormals();
};
extern const float DAT_010141cc = 0.0001f;
extern float DAT_01017718;
extern float DAT_01016248;
float __cdecl ClampedAcos(float);

// Accumulates face normals into vertex acc20 fields, normalizes each vertex accumulator, and sets flag101 to 1.
// @fnv 0x00e11e10
// src: GUESS 0x00e11e10 (confidence: medium)
void HostE10::AccumulateAndNormalizeVertexNormals()
{
    float len1;
    float len2;
    float dot;
    for (VertE10* v = list14; v != 0; v = v->next)
        _mm_store_ps(&v->acc20.x, _mm_load_ps((const float*)&DAT_01267e30));
    for (FaceE10* f = faces2c; f != 0; f = f->next) {
        GateE10 normalized;
        if (!f ? false:*meshVectorIsNormalized3(f->nrm20, normalized, DAT_010141cc)) {
            for (int i = 0; i < 3; ++i) {
                VertE10* A = f->verts[i];
                VertE10* B = f->verts[(i + 1) % 3];
                VertE10* pVertC = f->verts[(i + 2) % 3];
                __m128 posA = _mm_load_ps(&A->pos10.x);
                __m128 edges[2]; edges[0] = _mm_sub_ps(_mm_load_ps(&B->pos10.x), posA);
                edges[1] = _mm_sub_ps(_mm_load_ps(&pVertC->pos10.x), posA);
                if (meshVectorUnitNonzero(edges[0]) == 0) {
                    if (meshVectorUnitNonzero(edges[1]) == 0) {
                        __m128 pd = _mm_mul_ps(edges[1], edges[0]);
                        __m128 u1 = _mm_shuffle_ps(pd, pd, 0x55);
                        __m128 c1 = _mm_add_ss(u1, pd);
                        __m128 u2 = _mm_shuffle_ps(pd, pd, 0xaa);
                        __m128 c2 = _mm_add_ss(u2, c1);
                        _mm_store_ss(&dot, c2);
                        float ang = ClampedAcos(dot);
                        __m128 scalar = _mm_load_ss(&ang);
                        __m128 acc = A->acc20.q();
                        acc = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(scalar,scalar,0), _mm_load_ps(&f->nrm20.x)), acc);
                        A->acc20.q() = acc;
                    }
                }
            }
        }
    }
    VertE10* v = list14;
    if (v != 0) {
    __m128 constants[3];
    constants[1] = _mm_set_ss(DAT_01011d78);
    constants[0] = _mm_set_ss(DAT_01017718);
    constants[2] = _mm_set_ss(DAT_01016248);
    do {
        GateE10 normalized;
        if (!*meshVectorIsNormalized3(meshVectorFastUnit(v->acc20,constants[1],constants[0],constants[2]), normalized, DAT_010141cc))
            _mm_store_ps(&v->acc20.x, _mm_load_ps((const float*)&DAT_01267e30));
        v->acc20.w = 0.0f;
        v = v->next;
    } while (v != 0);
    }
    flag101 = 1;
}

struct ByteFlag { char data; ByteFlag() {} ByteFlag(bool x):data(x) {} operator bool() const {return data!=0;} ByteFlag& operator=(bool x){data=x;return *this;} };
struct hkVec4 {
    __m128 m_vComponents;
    hkVec4() {}
    hkVec4(const hkVec4& o) : m_vComponents(o.m_vComponents) {}
    __forceinline void operator=(const hkVec4& o) { m_vComponents = o.m_vComponents; }
    void setMul4(__m128 r, const hkVec4& a) { m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), a.m_vComponents); }
    void addMul4(__m128 r, const hkVec4& a) { m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(r, r, 0), a.m_vComponents), m_vComponents); }
    __forceinline void add4(const hkVec4& a) { m_vComponents = _mm_add_ps(a.m_vComponents, m_vComponents); }
    void mul4(__m128 r) { m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents); }
    __m128 getSimd0() const { return m_vComponents; }
    __m128 getSimd1() const { return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55); }
    __m128 getSimd2() const { return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa); }
    __m128 getSimdAt(int i) const {
        switch(i) {
        case 0: return m_vComponents;
        case 1: return _mm_shuffle_ps(m_vComponents,m_vComponents,0x55);
        case 2: return _mm_shuffle_ps(m_vComponents,m_vComponents,0xaa);
        default: return _mm_shuffle_ps(m_vComponents,m_vComponents,0xff);
        }
    }
    const float& operator()(int i) const { return m_vComponents.m128_f32[i]; }
};
template<class T> struct ListLinks { T* next; T* prev; };
struct MeshVertex : ListLinks<MeshVertex> {
    hkVec4 m_vContactPosition;
    hkVec4 m_vHitNormal;
};
struct FaceLinks { int unk00, unk04; };
template<class V> struct FaceBase : FaceLinks {
    V m_kVertices[3];
    unsigned int m_ppLinks[3];
    __forceinline V& vertex(int i) { return m_kVertices[i]; }
    __forceinline V vertex(int i) const { return m_kVertices[i]; }
};
struct MeshTriangle : FaceBase<MeshVertex*> {
    hkVec4 m_kTriangleNormal;
    __forceinline hkVec4& position(int i) { return vertex(i)->m_vContactPosition; }
    __forceinline const hkVec4& position(int i) const { return vertex(i)->m_vContactPosition; }
};
struct MeshLocation {
    unsigned int m_tri;
    unsigned int m_uiEdgeIndex;
    static __forceinline const MeshLocation& none() {
        if ((DAT_0126ebf0 & 1) == 0) {
            DAT_0126ebf0 |= 1;
            DAT_0126ebe8 = 0;
            DAT_0126ebec = 0;
        }
        return *(const MeshLocation*)&DAT_0126ebe8;
    }
    MeshLocation() {}
    MeshLocation(unsigned int t, unsigned int i) : m_tri(t), m_uiEdgeIndex(i) {}
};
struct MeshHit {
    int m_type;
    MeshLocation m_loc;
    MeshHit() : m_type(0), m_loc(MeshLocation::none()) {}
    MeshHit(int ty, MeshLocation l) : m_type(ty), m_loc(l) {}
};
struct MeshResult {
    hkVec4 m_dir;
    hkVec4 m_vHitNormal;
    hkVec4 m_bary;
    hkVec4 m_kPoint;
    float m_fHitFraction;
    ByteFlag m_kHitFlags;
    MeshHit m_bHasHit;
    MeshResult();
    __forceinline MeshResult& operator=(const MeshResult& o)
    {
        m_dir = o.m_dir;
        m_vHitNormal = o.m_vHitNormal;
        m_bary = o.m_bary;
        m_kPoint = o.m_kPoint;
        m_fHitFraction = o.m_fHitFraction;
        m_kHitFlags = o.m_kHitFlags;
        m_bHasHit = o.m_bHasHit;
        return *this;
    }
};
struct MeshPoint { unsigned int x, y, z, w; };
extern const void* DAT_010eadc8;
struct __declspec(align(16)) ClosestQuery {
    const void* m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    MeshPoint m_kPoint;
    float m_fHitFraction;
    int unk24;
    int unk28;
    int unk2c;
    hkVec4 m_closest;
    hkVec4 m_bary;
    MeshTriangle* m_tri;
    ClosestQuery(const MeshPoint& p) : m_kPoint(p), m_fHitFraction(3.40282e+38f)
    {
        m_vtbl = &DAT_010eadc8;
        m_tri = 0;
        m_closest = *(hkVec4*)&DAT_01267e30;
    }
};
void __cdecl hkVector4_ProcessEntries_00d1dbb0(void* tree, const MeshPoint* p, ClosestQuery* q);

extern "C" __m128 _mm_load_ss(const float* p);
static __forceinline __m128 Splat(__m128 v) { return _mm_shuffle_ps(v, v, 0); }

static __forceinline void SetMul4(__m128& d, __m128 r, const __m128& a) { d = _mm_mul_ps(Splat(r), a); }
static __forceinline void AddMul4(__m128& d, __m128 r, const __m128& a) { d = _mm_add_ps(_mm_mul_ps(Splat(r), a), d); }

// hkgpMesh: triangle tree at +0x40 and per-vertex-normal flag at +0x101; no shared header yet.
struct hkgpMesh {
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
    int m_iValueAt40;
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
    bool m_hasVertexNormals;
    void FindClosestMeshTriangle(const MeshPoint* p, MeshResult* out);
};

// Finds the mesh triangle closest to point p and fills out with hit fraction, direction, barycentrics, point, normal and hit location.
// @fnv 0x00e13210
// src: GUESS 0x00e13210 (confidence: medium)
void hkgpMesh::FindClosestMeshTriangle(const MeshPoint* apPoint, MeshResult* apResult)
{
    if (!m_hasVertexNormals) {
        unsigned int buf[128];
        CharBuffer msg;
        msg.FUN_00cb1600((char*)buf, 0x200);
        msg.ProcessAndReturnValue_00cc01c0("assignVertexNormals not called");
        if (DAT_01268360->Report(3, 0x672b48d7, (const char*)buf, ".\\GeometryProcessing\\Mesh\\hkgpMesh.cpp", 0x525)) {
            __debugbreak();
        }
        msg.FUN_00cc00e0();
    }
    ClosestQuery q(*apPoint);
    hkVector4_ProcessEntries_00d1dbb0(&m_iValueAt40, apPoint, &q);
    if (q.m_tri != 0) {
        *apResult = MeshResult();
        apResult->m_fHitFraction = q.m_fHitFraction;
        apResult->m_dir = q.m_closest;
        apResult->m_bary = q.m_bary;
        float lenSq = ToReal(Dot3(apResult->m_dir.m_vComponents, apResult->m_dir.m_vComponents));
        if (lenSq != 0.0f) {
            float len = (float)sqrt(lenSq);
            float inv = 1.0f / len;
            apResult->m_dir.mul4(_mm_load_ss(&inv));
        }
        int m0 = q.m_bary(0) == 0.0f ? 0 : 1;
        int m1 = q.m_bary(1) == 0.0f ? 0 : 2;
        int m2 = q.m_bary(2) == 0.0f ? 0 : 4;
        int mask = m2 + m1 + m0;
        MeshTriangle* t = q.m_tri;
        MeshVertex* vs[3];
        vs[1] = t->m_kVertices[1];
        vs[2] = t->m_kVertices[2];
        vs[0] = t->m_kVertices[0];
        apResult->m_kPoint.setMul4(apResult->m_bary.getSimdAt(0), t->position(0));
        apResult->m_kPoint.addMul4(apResult->m_bary.getSimdAt(1), t->position(1));
        apResult->m_kPoint.addMul4(apResult->m_bary.getSimdAt(2), t->position(2));
        apResult->m_kHitFlags=false;
        apResult->m_vHitNormal=t->m_kTriangleNormal;
        apResult->m_bHasHit=MeshHit(1,MeshLocation((unsigned int)t,0));
        if (mask>0 && mask<7) switch(mask) {
        case 4:
            apResult->m_vHitNormal = vs[2]->m_vHitNormal;
            apResult->m_bHasHit = MeshHit(3, MeshLocation((unsigned int)t, 2));
            break;
        case 2:
            apResult->m_vHitNormal = vs[1]->m_vHitNormal;
            apResult->m_bHasHit = MeshHit(3, MeshLocation((unsigned int)t, 1));
            break;
        case 6: {
            unsigned int l = t->m_ppLinks[1];
            if (l & ~3u) apResult->m_vHitNormal.add4(((MeshTriangle*)(l & ~3u))->m_kTriangleNormal);
            apResult->m_bHasHit = MeshHit(2, MeshLocation((unsigned int)t, 1));
            break;
        }
        case 1:
            apResult->m_vHitNormal = vs[0]->m_vHitNormal;
            apResult->m_bHasHit = MeshHit(3, MeshLocation((unsigned int)t, 0));
            break;
        case 5: {
            unsigned int l = t->m_ppLinks[2];
            if (l & ~3u) apResult->m_vHitNormal.add4(((MeshTriangle*)(l & ~3u))->m_kTriangleNormal);
            apResult->m_bHasHit = MeshHit(2, MeshLocation((unsigned int)t, 2));
            break;
        }
        case 3: {
            unsigned int l = t->m_ppLinks[0];
            if (l & ~3u) apResult->m_vHitNormal.add4(((MeshTriangle*)(l & ~3u))->m_kTriangleNormal);
            apResult->m_bHasHit = MeshHit(2, MeshLocation((unsigned int)t, 0));
            break;
        }
        }
        apResult->m_kHitFlags = (ToReal(Dot3(apResult->m_dir.m_vComponents, apResult->m_vHitNormal.m_vComponents)) < 0.0f) ? true : false;
    } else {
        *apResult = MeshResult();
        apResult->m_dir = *(hkVec4*)&DAT_01267e30;
        apResult->m_bary = *(hkVec4*)&DAT_01267e30;
        apResult->m_fHitFraction = 3.40282e+38f;
        _ReadWriteBarrier();
        apResult->m_kHitFlags = false;
        apResult->m_bHasHit = MeshHit();
    }
}

extern "C" __m128 _mm_set_ss(float);

extern float DAT_0106c2e0;
void __stdcall setTransformedPos_00c7f640(int arg, void* p);

struct Ex_Holder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __m128 m_10;
};

struct Ex_Node {
    Ex_Node* m_00;
    int unk04;
    Ex_Holder* m_08;
    Ex_Holder* m_0c;
    Ex_Holder* m_10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int m_30;
};

struct Ex_Scratch {
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
    char m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    void FUN_00e22ca0();
};

struct __declspec(align(16)) LocalVec {
__m128 value;
LocalVec() {}
__forceinline void set(__m128 a,__m128 b) { value=_mm_add_ps(a,b); }
__forceinline void add(__m128 a) { value=_mm_add_ps(a,value); }
__forceinline void mul(__m128 a) { value=_mm_mul_ps(value,a); }

};
struct Ex_Target {
    void FindClosestMeshTriangle(LocalVec* a, Ex_Scratch* b);
};

struct LocalOwner {
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
    Ex_Node* m_2c;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C;
    int unk90; int unk94; int unk98; int unk9C;
    int unkA0; int unkA4; int unkA8; int unkAC;
    int unkB0; int unkB4; int unkB8; int unkBC;
    int unkC0; int unkC4; int unkC8; int unkCC;
    int unkD0; int unkD4; int unkD8; int unkDC;
    int unkE0; int unkE4; int unkE8; int unkEC;
    int unkF0; int unkF4; int unkF8; int unkFC;
    unsigned char unk100;
    unsigned char m_101;
    void RemoveTriangle(Ex_Node* n);
    void ProcessAndRemoveMatchingNodes(int key, int arg2, unsigned int arg3, unsigned char flag);
};

// For each node with m_30 == key, averages its three vertex vectors, applies FUN_00c7f640, runs FUN_00e13210, and removes the node if m_44 == flag.
// @fnv 0x00e15020
// src: GUESS 0x00e15020 (confidence: medium)
void LocalOwner::ProcessAndRemoveMatchingNodes(int key, int arg2, unsigned int arg3, unsigned char flag) {
    Ex_Node* node = m_2c;
    if (node != 0) {
        Ex_Node* next;
        do {
            next = node->m_00;
            if (node->m_30 == key) {
                LocalVec a;
                a.set(node->m_0c->m_10, node->m_08->m_10);
                
                 __m128 t = _mm_set_ss(0.3333333432674408f);
__m128 K = _mm_shuffle_ps(t,t,0);
                a.add(node->m_10->m_10);
                a.mul(K);
                setTransformedPos_00c7f640(arg2, &a);
                Ex_Scratch obj;
                obj.FUN_00e22ca0();
                ((Ex_Target*)(*(volatile unsigned int*)&arg3))->FindClosestMeshTriangle(&a, &obj);
                if ((int)obj.m_44 == (int)flag) {
                    RemoveTriangle(node);
                }
            }
            node = next;
        } while (node != 0);
    }
    m_101 = 0;
}

struct E17Ends { int start; int end; };

struct E17MergeState { int pass; union { int next; float score; }; };
struct E17Mem
{
    virtual void v00();
    virtual void* allocate(int size);
    virtual void deallocate(void* p, int size);
    virtual void v0c();
    virtual void freeBlock(void* p, int size);
};

__forceinline E17Mem& e17Heap() { return *(E17Mem*)&meshHeap(hkMemoryRouter_getInstance()); }

void __cdecl ResizeAudioStream(E17Mem* alloc, void* array, int elemSize);

struct E17Face
{
    E17Face* m_next;
    int unk04;
    int m_kVertices[3];
    unsigned int m_ppLinks[3];
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int m_iMaterialIndex;
};

struct E17Edge
{
    E17Face* m_face;
    int m_uiEdgeIndex;

    E17Edge(E17Face* face, int index) : m_face(face), m_uiEdgeIndex(index) {}
    static int next(int i) { return (9 >> (i << 1)) & 3; }
    int start() const { return m_face->m_kVertices[m_uiEdgeIndex]; }
    int end() const { return m_face->m_kVertices[next(m_uiEdgeIndex)]; }
};

template <class T>
__forceinline void e17Construct(T* p, const T& t) { new (p) T(t); }
template <class T>
__forceinline void e17Construct(T** p, T* const& t) { *p = t; }

template<unsigned Bytes> __forceinline void e17CopyWords(void* dest,const void* src)
{
    unsigned word=0;
    do {
        static_cast<unsigned*>(dest)[word]=static_cast<const unsigned*>(src)[word];
        ++word;
    } while(word<Bytes/sizeof(unsigned));
}
template<class T> __forceinline void e17Destroy(T* p,int count) {
    for(int item=0;item<count;++item) p[item].~T();
}
template <class T>
struct E17ArrayLocalForm
{ // local form of hkArray: 0x00e17b00 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    E17ArrayLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~E17ArrayLocalForm()
    {
        E17Mem& heap = e17Heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            heap.freeBlock(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
    T& back() { return m_data[m_iElementCount - 1]; }
    void AddBack(const T& t)
    {
        E17Mem& heap = e17Heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&heap, this, sizeof(T));
        e17Construct(m_data + m_iElementCount, t);
        m_iElementCount++;
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            e17CopyWords<sizeof(T)>(m_data+index,m_data+m_iElementCount);
    }
    void hkArrayBase_struct_hkgpMeshBase_Edge_append(E17Mem* heap, const T* data, int n);
    void append(const T* data, int n) { hkArrayBase_struct_hkgpMeshBase_Edge_append(&e17Heap(), data, n); }

    static void* operator new(unsigned int size) { return e17Heap().allocate(size); }
    static void operator delete(void* p) { e17Heap().deallocate(p, sizeof(E17ArrayLocalForm)); }
};

typedef E17ArrayLocalForm<E17Edge> E17Loop;

typedef hkArray<E17Loop*> E17LoopList;

float __cdecl getLoopSurfaceArea(const E17Loop* loop);

template <class T>
__forceinline void e17Swap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

struct E17Mesh
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
    E17Face* m_faces;

    int hkgpMesh_extractAllLoops(E17LoopList* out, int material) throw();
};

// Collects boundary loops from faces matching a material, merges loops sharing endpoints, and appends the largest-area loop first to out.
// @fnv 0x00e17b00
// src: HAVOK_LIB 0x00e17b00
int E17Mesh::hkgpMesh_extractAllLoops(E17LoopList* apOutLoops, int material) throw()
{
    E17ArrayLocalForm<E17Loop*> loops;
    for (E17Face* face = m_faces; face; face = face->m_next)
    {
        if (material == -1 || face->m_iMaterialIndex == material)
        {
            for (int j = 0; j < 3; j++)
            {
                if ((face->m_ppLinks[j] & 0xfffffffc) == 0)
                {
                    E17Loop* loop = new E17Loop;
                    loop->AddBack(E17Edge(face, j));
                    loops.AddBack(loop);
                }
            }
        }
    }
    if (loops.GetLogicalSize() == 0)
        return 0;

    int pass;
    for (pass = 0; pass < 1; pass++)
    {
        int i=0;
        for (; i<loops.GetLogicalSize(); i++)
        {
            for (int k = i+1; k < loops.GetLogicalSize(); k++)
            {
                E17Ends endsA;
                endsA.start = (*loops[i])[0].start();
                endsA.end = loops[i]->back().end();
                if (endsA.start == endsA.end)
                    continue;
                E17Ends endsB;
                endsB.start = (*loops[k])[0].start();
                endsB.end = loops[k]->back().end();
                if (endsB.start == endsB.end)
                    continue;
                if (endsB.start == endsA.end)
                {
                    loops[i]->append(loops[k]->m_data, loops[k]->m_iElementCount);
                    delete loops[k];
                    loops.removeAt(k);
                    k--;

                    pass = -1;
                }
                else if (endsA.start == endsB.end)
                {
                    loops[k]->append(loops[i]->m_data, loops[i]->m_iElementCount);
                    int saved=k;
                    e17Swap(loops[i], loops[saved]);
                    delete loops[saved];
                    loops.removeAt(saved);
                    k=--saved;
                    pass = -1;
                }
            }
        }
    }

    int bestIndex = 0;
    float best = getLoopSurfaceArea(loops[0]);
    for (int i = 1; i < loops.GetLogicalSize(); i++)
    {
        float area = getLoopSurfaceArea(loops[i]);
        if (area > best)
        {
            best = area;
            bestIndex = i;
        }
    }
    if (bestIndex != 0)
        e17Swap(loops[0], loops[bestIndex]);

    apOutLoops->append(loops.m_data, loops.m_iElementCount);
    return loops.GetLogicalSize();
}

struct SplitFace : S_00e13910_Triangle {
    __forceinline void*& vertex(int i) { return m_kVertices[i]; }
    __forceinline hkUint32& link(int i) { return m_ppLinks[i]; }
    __forceinline void corners(void* const& a, void* const& b, void* const& c) {
        m_kVertices[0] = a; m_kVertices[1] = b; m_kVertices[2] = c;
    }
};
struct SplitEdge;
template<class E, class T> struct SplitCore {
    T* m_pkTriangle;
    hkUint32 m_uiEdgeIndex;
    __forceinline SplitCore() {}
    __forceinline SplitCore(T* t, unsigned i) : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    __forceinline SplitCore(const hkUint32& packed) { unpack(packed, m_pkTriangle, m_uiEdgeIndex); }
    static __forceinline void unpack(hkUint32 packed, T*& tri, hkUint32& idx) {
        idx = packed & 3; packed &= ~3u; tri = (T*)packed;
    }
    __forceinline E next() const { return E(m_pkTriangle, (9 >> (m_uiEdgeIndex << 1)) & 3); }
    __forceinline E prev() const { return E(m_pkTriangle, (0x12 >> (m_uiEdgeIndex << 1)) & 3); }
    __forceinline E link() const { return E(m_pkTriangle->link(m_uiEdgeIndex)); }
    __forceinline bool isValid() const { return m_pkTriangle != 0; }
    __forceinline void*& start() const { return m_pkTriangle->vertex(m_uiEdgeIndex); }
    __forceinline void*& end() const { return m_pkTriangle->vertex((9 >> (m_uiEdgeIndex << 1)) & 3); }
    __forceinline void*& apex() const { return m_pkTriangle->vertex((0x12 >> (m_uiEdgeIndex << 1)) & 3); }
    __forceinline void bind(const E& other) const {
        m_pkTriangle->link(m_uiEdgeIndex) = (hkUint32)other.m_pkTriangle + other.m_uiEdgeIndex;
        if (other.m_pkTriangle) other.m_pkTriangle->link(other.m_uiEdgeIndex) = (hkUint32)m_pkTriangle + m_uiEdgeIndex;
    }
    static __forceinline const E& null() { static const E e(0, 0); return e; }
};
struct SplitEdge : SplitCore<SplitEdge, SplitFace> {
    typedef SplitCore<SplitEdge, SplitFace> Base;
    __forceinline SplitEdge(SplitFace* t, unsigned i) : Base(t, i) {}
    __forceinline SplitEdge(const hkUint32& packed) : Base(packed) {}
    __forceinline SplitEdge(const SplitEdge& other) : Base(other.m_pkTriangle, other.m_uiEdgeIndex) {}
};

struct ConvexHullBuilder : public FUN_00e19cf0_cls {
    __declspec(noinline) bool UpdateTriangleNormal(SplitFace* t);
    SplitEdge SplitEdgeWithNewVertex(SplitEdge edge, void* vertex, bool flag);
};

// src: GUESS 0x00e11910 (confidence: medium)
bool ConvexHullBuilder::UpdateTriangleNormal(SplitFace* t) {
    __m128 plane;
    HullTriangle* tri = (HullTriangle*)t;
    if (((BoundsMesh*)this)->ValidateTriangleAndComputePlane((__m128*)tri->m_08->pos, (__m128*)tri->m_0C->pos, (__m128*)tri->m_10->pos, &plane, true)) {
        *(__m128*)&tri->m_20 = plane;
        return true;
    }
    return false;
}

// Splits the edge's triangle (and its linked triangle if any) by inserting a new vertex, updating the mesh topology and optionally recomputing hull planes.
// @fnv 0x00e18ed0
// src: GUESS 0x00e18ed0 (confidence: medium)
SplitEdge ConvexHullBuilder::SplitEdgeWithNewVertex(SplitEdge edge, void* vertex, bool abUpdatePlanes) {
    if (!edge.link().isValid()) {
        SplitFace* t1 = (SplitFace*)m_kNodePool.UpdateFields_00e241a0((HullTriangle*)edge.m_pkTriangle);
        t1->corners(vertex, edge.apex(), edge.start());
        edge.start() = vertex;
        SplitEdge(t1, 1).bind(edge.prev().link());
        SplitEdge(t1, 0).bind(edge.prev());
        SplitEdge(t1, 2).bind(SplitEdge::null());
        if (abUpdatePlanes) {
            UpdateTriangleNormal(t1);
            UpdateTriangleNormal(edge.m_pkTriangle);
        }
    } else {
        SplitEdge link = edge.link();
        SplitFace* t1 = (SplitFace*)m_kNodePool.UpdateFields_00e241a0((HullTriangle*)edge.m_pkTriangle);
        SplitFace* t2 = (SplitFace*)m_kNodePool.UpdateFields_00e241a0((HullTriangle*)link.m_pkTriangle);
        t1->corners(vertex, edge.apex(), link.end());
        t2->corners(vertex, link.apex(), edge.end());
        edge.start() = vertex;
        link.start() = vertex;
        SplitEdge(t1, 1).bind(edge.prev().link());
        SplitEdge(t2, 1).bind(link.prev().link());
        SplitEdge(t1, 0).bind(edge.prev());
        SplitEdge(t2, 0).bind(link.prev());
        SplitEdge(t1, 2).bind(link);
        SplitEdge(t2, 2).bind(edge);
        if (abUpdatePlanes) {
            UpdateTriangleNormal(t1);
            UpdateTriangleNormal(t2);
            UpdateTriangleNormal(edge.m_pkTriangle);
            UpdateTriangleNormal(link.m_pkTriangle);
        }
    }
    return edge.prev();
}

namespace fnv_00e1b820 {
struct VertexCopy;
// A moving corner view pairs the current vertex with its corresponding edge.
struct CornerStore {VertexCopy* vertex;unsigned word04,word08,link;};
struct FUN_00cb18f0_t { int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(int); };
extern const float s_faderClearedAlpha;
extern const float g_011c5aa8_arg1;

struct Bits4 { unsigned a,b,c,d; };
struct __declspec(align(16)) PositionBits:Bits4 {};
struct VertexCopy;
struct TriangleCopy;
template<class T> struct ListLinks {
    T* next; T* prev;
    ListLinks() {}
    ListLinks(const ListLinks&) {}
};
struct VertexCopy:ListLinks<VertexCopy> {
    PositionBits position,normal,data;
    int refs,tag;
    __forceinline VertexCopy(const VertexCopy& v):ListLinks<VertexCopy>(v),position(v.position),normal(v.normal),data(v.data),refs(v.refs),tag(v.tag) {}
};
struct TriangleCopy:ListLinks<TriangleCopy> {
    VertexCopy* vertices[3]; unsigned links[3];
    PositionBits plane;
    int part,planeId,material,tag; unsigned leaf;
    __forceinline VertexCopy*& vertex(int i) {return vertices[i];}
    __forceinline VertexCopy* vertex(int i) const {return vertices[i];}
    __forceinline unsigned& link(int i) {return links[i];}
};
template<class T> struct CopyPool {
    struct Block {T entries[32];T* free;int used;};
    Block** blocks; int size,capacity;
    T* head; int count; unsigned uid;
    Block* AllocateChainedSlotBlock();
    __forceinline T* allocateRaw() {
        Block* block=(size && blocks[0]->free)?blocks[0]:AllocateChainedSlotBlock();
        T* free=block->free;
        block->free=free->next;
        ++block->used;
        return free;
    }
    __forceinline T* clone(const T& value) {
        T* item=new (allocateRaw()) T(value);
        item->prev=0;
        item->next=head;
        if(head)head->prev=item;
        head=item;
        ++count;
        return item;
    }
};
struct PartsMap {
    int data,size,mask;
    __forceinline PartsMap():data(0),size(0),mask(-1) {reserve(0);}
    void EnsureCapacity(Allocator*,int);
    unsigned long LookupHashEntry(unsigned long,unsigned long) const;
    int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(Allocator*,unsigned long,unsigned long);
    void ProcessArgument(Allocator*);
    void Object_DoNothing();
    static void* operator new(unsigned n,Allocator* heap){return heap->allocate(n);}
    __forceinline void reserve(int n){EnsureCapacity(&meshHeap(hkMemoryRouter_getInstance()),n);}
    __forceinline unsigned long lookup(unsigned long k)const{return LookupHashEntry(k,0);}
    __forceinline void insert(unsigned long k,unsigned long v){hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(&meshHeap(hkMemoryRouter_getInstance()),k,v);}
    __forceinline void record(Allocator& a,unsigned long k,unsigned long v){hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(&a,k,v);}
};
template<class T> struct PartArray {
    T* data; int size,capacity;
    PartArray():data(0),size(0),capacity(0x80000000){}
    __forceinline T& operator[](int i){return data[i];}
    __forceinline void reserve(Allocator& heap,int n){
        int c=capacity&0x3fffffff;
        if(c<n){int twice=c+c;if(n<twice)n=twice;hkArrayUtil__reserve((int)&heap,this,n,sizeof(T));}
    }
    __forceinline T* expand(Allocator& heap,int n){int old=size;reserve(heap,old+n);T* out=data+old;size+=n;return out;}
};
struct PartMesh {
    int vf;short memorySize,refcount;
    CopyPool<VertexCopy> vertices;
    CopyPool<TriangleCopy> triangles;
    int material;
    int hkgpMesh_countParts()const;
    void hkgpMesh_simplify(float*);
    void BuildHull();
    int hkgpMesh_explodeParts(PartArray<PartMesh*>& output,bool simplify,bool convex)const;
};

// Splits this PartMesh into per-part sub-meshes in output, deduplicating vertices and edges, optionally simplifying and building convex hulls.
// @fnv 0x00e1b820
// src: HAVOK_LIB 0x00e1b820
int PartMesh::hkgpMesh_explodeParts(PartArray<PartMesh*>& output,bool simplify,bool convex)const {
    VertexCopy** to=0;
    int parts=hkgpMesh_countParts();
    if(!parts)return 0;
    PartArray<PartsMap*> maps;
    PartsMap edgeMap;
    PartMesh** destinations=output.expand(meshHeap(hkMemoryRouter_getInstance()),parts);
    int edgeCount=triangles.count;
    Allocator* edgeHeap=&meshHeap(hkMemoryRouter_getInstance());
    edgeMap.EnsureCapacity(edgeHeap,edgeCount*3);
    {
        Allocator& heap=meshHeap(hkMemoryRouter_getInstance());
        int c=maps.capacity&0x3fffffff;
        if(c<parts){int n=c+c;if(parts>=n)n=parts;hkArrayUtil__reserve((int)&heap,&maps,n,4);}
    }
    maps.size=parts;
    for(int i=0;i<parts;++i){
        destinations[i]=0;
        maps[i]=new (&meshHeap(hkMemoryRouter_getInstance())) PartsMap;
    }
    for(const TriangleCopy* source=triangles.head;source;source=source->next){
        int group=source->part;
        if(group!=-1){
            if(!destinations[group]){
                PartMesh* mesh=(PartMesh*)meshHeap(hkMemoryRouter_getInstance()).allocate(0x110);
                mesh->memorySize=0x110;
                mesh=(PartMesh*)new (mesh) FUN_00e1b750;
                destinations[group]=mesh;
                mesh->material=material;
            }
            PartsMap* map=maps[source->part];
            TriangleCopy* triangle=destinations[group]->triangles.clone(*source);
            to=triangle->vertices;
            const int delta=(const char*)source-(const char*)triangle;
            for(int i=0;i<3;++i,++to){
                VertexCopy* old=((const CornerStore*)((const char*)to+delta))->vertex;
                VertexCopy* vertex=(VertexCopy*)map->lookup((unsigned long)old);
                if(!vertex){
                    vertex=destinations[group]->vertices.clone(*old);
                    map->record(meshHeap(hkMemoryRouter_getInstance()),(unsigned long)old,(unsigned long)vertex);
                }
                CornerStore* destination=(CornerStore*)to; destination->vertex=vertex; destination->link=0;
            }
            for(int i=0;i<3;++i){
                S_00e13910_Edge edge((S_00e13910_Triangle*)source,i);
                S_00e13910_Edge target((S_00e13910_Triangle*)triangle,i);
                S_00e13910_Edge link=edge.link();
                if(link.isValid()&&((TriangleCopy*)link.m_pkTriangle)->part==source->part){
                    unsigned long key=(unsigned long)link.m_pkTriangle+link.m_uiEdgeIndex;
                    S_00e13910_Edge mapped(edgeMap.lookup(key));
                    if(mapped.isValid()){
                        target.m_pkTriangle->m_ppLinks[target.m_uiEdgeIndex]=(unsigned long)mapped.m_pkTriangle+mapped.m_uiEdgeIndex;
                        mapped.m_pkTriangle->m_ppLinks[mapped.m_uiEdgeIndex]=(unsigned long)target.m_pkTriangle+target.m_uiEdgeIndex;
                        ((FUN_00cb18f0_t*)&edgeMap)->hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(key);
                    } else {
                        edgeMap.insert((unsigned long)edge.m_pkTriangle+edge.m_uiEdgeIndex,(unsigned long)target.m_pkTriangle+target.m_uiEdgeIndex);
                        target.m_pkTriangle->m_ppLinks[target.m_uiEdgeIndex]=key;
                    }
                }
            }
        }
    }
    int result=parts;
    for(int i=0;i<result;++i){
        PartsMap* map=maps[i];
        if(map){
            map->ProcessArgument(&meshHeap(hkMemoryRouter_getInstance()));
            map->Object_DoNothing();
            ((hkMemoryAllocator*)&meshHeap(hkMemoryRouter_getInstance()))->blockFree(map,12);
        }
        if(simplify){
            float tolerance[2];
            PartMesh* mesh=destinations[i];
            tolerance[0]=s_faderClearedAlpha;tolerance[1]=g_011c5aa8_arg1;
            mesh->hkgpMesh_simplify(tolerance);
        }
        if(convex)destinations[i]->BuildHull();
    }
    hkMemoryRouter_getInstance();hkMemoryRouter_getInstance();
    edgeMap.ProcessArgument(&meshHeap(hkMemoryRouter_getInstance()));
    edgeMap.Object_DoNothing();
    Allocator& heap=meshHeap(hkMemoryRouter_getInstance());
    maps.size=0;
    if(!(maps.capacity&0x80000000u))heap.freeBlock(maps.data,(maps.capacity&0x3fffffff)*4);
    return result;
}
}  // namespace fnv_00e1b820

extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern double DAT_01012060;
void __cdecl ResizeAudioStream(void*, void*, int) throw();

struct CutVec {
    __m128 q;
    __forceinline __m128& quad() {return q;}
    __forceinline const __m128& quad() const {return q;}
    __forceinline float& component(int i) {return q.m128_f32[i];}
    __forceinline const float& component(int i) const {return q.m128_f32[i];}
};
template<class T> struct CutLinks {
    T* next;
    T* prev;
    CutLinks() {}
    CutLinks(const CutLinks&) {}
};
struct CutVertex : CutLinks<CutVertex> {
    CutVec position,attribute,distance;
    int tag40,tag44;
    CutVertex():tag40(-1),tag44(-1) {}
    __forceinline int compare(const CutVertex& other) const {
        for(int axis=0;axis<3;++axis) {
            if(position.component(axis)<other.position.component(axis)) return -1;
            if(position.component(axis)>other.position.component(axis)) return 1;
        }
        return 0;
    }
    static __forceinline bool ordered(const CutVertex* first,const CutVertex* second) {
        const int order=first->compare(*second);
        if(order<0) return true;
        if(order>0) return false;
        return true;
    }
    typedef CutVertex Data;
};
struct CutTriangle;
template<class T> struct CutTopology : CutLinks<T> {
    CutVertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
    __forceinline CutVertex*& vertex(int i) {return m_kVertices[i];}
    __forceinline unsigned int& link(int i) {return m_ppLinks[i];}
};
struct CutWords {unsigned int x,y,z,w;};
struct __declspec(align(16)) CutPlaneBits : CutWords {};
struct CutTriangle : CutTopology<CutTriangle> {
    CutPlaneBits normal;
    int side, unk34, unk38, unk3c, unk40;
    typedef CutTriangle Data;
};
static __forceinline unsigned long cutPack(void* tri,unsigned int index) {
    return reinterpret_cast<const unsigned long&>(tri)+(unsigned long)index;
}
template<class T> static __forceinline void cutUnpack(unsigned long bits,T*& tri,unsigned int& index) {
    index=bits&3;
    bits&=~3u;
    tri=reinterpret_cast<T*&>(bits);
}
struct CutEdge;
template<class E,class T> struct CutEdgeBase {
    T* m_pkTriangle;
    unsigned int m_uiEdgeIndex;
    __forceinline CutEdgeBase(T* face,unsigned int index):m_pkTriangle(face),m_uiEdgeIndex(index) {}
    __forceinline CutEdgeBase(const unsigned int& packed) {
        cutUnpack(packed,m_pkTriangle,m_uiEdgeIndex);
    }
    __forceinline T* triangle() const {return m_pkTriangle;}
    __forceinline bool isValid() const {return m_pkTriangle!=0;}
    __forceinline E next() const {return E(m_pkTriangle,(9>>(m_uiEdgeIndex<<1))&3);}
    __forceinline E prev() const {return E(m_pkTriangle,(18>>(m_uiEdgeIndex<<1))&3);}
    __forceinline E link() const {return E(m_pkTriangle->link(m_uiEdgeIndex));}
    __forceinline CutVertex*& start() const {return m_pkTriangle->vertex(m_uiEdgeIndex);}
    __forceinline CutVertex*& end() const {return m_pkTriangle->vertex((9>>(m_uiEdgeIndex<<1))&3);}
    __forceinline bool master() const {return CutVertex::ordered(start(),end()) || !link().isValid();}
    __forceinline void unbind() const {
        if(link().isValid()) {
            E other=link();
            other.m_pkTriangle->link(other.m_uiEdgeIndex)=0;
        }
        m_pkTriangle->link(m_uiEdgeIndex)=0;
    }
    __forceinline void bind(const CutEdgeBase& other) const {
        m_pkTriangle->link(m_uiEdgeIndex)=cutPack(other.m_pkTriangle,other.m_uiEdgeIndex);
        if(other.m_pkTriangle) other.m_pkTriangle->link(other.m_uiEdgeIndex)=cutPack(m_pkTriangle,m_uiEdgeIndex);
    }
};
struct CutEdge:CutEdgeBase<CutEdge,CutTriangle> {
    typedef CutEdgeBase<CutEdge,CutTriangle> Base;
    __forceinline CutEdge(CutTriangle* t,unsigned int i):Base(t,i) {}
    __forceinline CutEdge(const unsigned int& packed):Base(packed) {}
    __forceinline CutEdge(const CutEdge& e):Base(e.m_pkTriangle,e.m_uiEdgeIndex) {}
};
struct CutBlock {
    PoolItemAB items[32];
    PoolItemAB* free;
    int used;
};
struct CutFreeList {
    CutBlock** blocks;
    int numBlocks;
    int capacity;
    CutBlock* AllocateChainedSlotBlock();
};
template<class T> struct CutPool : CutFreeList {
    T* head;
    int count;
    void hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(T*);
    __forceinline void remove(T* node) {
        T* next=(T*)node->next;
        T* prev=(T*)node->prev;
        if(next) next->prev=prev;
        if(prev) prev->next=next;
        else head=next;
        --count;
        hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(node);
    }
    __forceinline T* allocate(const typename T::Data& source) {
        CutBlock* block;
        if (numBlocks && blocks[0]->free) block = blocks[0];
        else block = AllocateChainedSlotBlock();
        T* node=(T*)block->free;
        block->free=(PoolItemAB*)node->next;
        ++block->used;
        new (node) T(source);
        node->prev=0;
        node->next=head;
        if(head) head->prev=node;
        ++count;
        head=node;
        return node;
    }
};
template<> __forceinline CutTriangle* CutPool<CutTriangle>::allocate(const CutTriangle& source) {
    CutBlock* block;
    if(numBlocks && blocks[0]->free) block=blocks[0];
    else block=AllocateChainedSlotBlock();
    CutTriangle* node=(CutTriangle*)block->free;
    block->free=(PoolItemAB*)node->next;
    ++block->used;
    new (node) CutTriangle(source);
    node->prev=0;
    node->next=head;
    if(head) head->prev=node;
    ++count;
    head=node;
    return node;
}
struct CutArray {
    CutTriangle** data;
    int size;
    int capacity;
};
struct CutMesh {
    int unk00, unk04;
    CutPool<CutVertex> vertices;
    int unk1c;
    CutPool<CutTriangle> faces;
    int unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unk48a8, unkac;
    int unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec;
    CutVec plane;
    int unk100;
    float tolerance;
    __declspec(noinline) int ProcessEntries_00e11990(const CutVec&, int);
    void hkgpMesh_removeOrphanVertices();
    void ReleaseSubobject();
    void ResolveLinkNodes();
    int* SplitMeshAlongPlane(int* result, const CutVec& p, bool splitSides);
};
// src: GUESS 0x00e11990 (confidence: low)
__declspec(noinline) int CutMesh::ProcessEntries_00e11990(const CutVec& p,int channel) {
    bool positive=false, negative=false;
    for(CutVertex* v=vertices.head;v;v=v->next) {
        __m128 product=_mm_mul_ps(v->position.quad(),p.quad());
        __m128 sum=_mm_add_ss(_mm_shuffle_ps(product,product,0x55),product);
        sum=_mm_add_ss(_mm_shuffle_ps(product,product,0xaa),sum);
        sum=_mm_add_ss(sum,_mm_shuffle_ps(p.quad(),p.quad(),0xff));
        float dist;
        _mm_store_ss(&dist,sum);
        float squared=dist*dist;
        if(squared<=tolerance) dist=0;
        v->distance.component(channel)=dist;
        if(dist>0) positive=true;
        else if(dist<0) negative=true;
    }
    int code=0;
    if(positive) code=1;
    if(negative) code+=2;
    return code;
}
static __forceinline const CutEdge& cutNullEdge() {
    static CutEdge edge(0,0);
    return edge;
}
static __forceinline void cutUnlink(CutTriangle* face,int index) {
    unsigned int link=face->m_ppLinks[index];
    if(link&~3u) {
        S_00e13910_Edge other(link);
        other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex]=0;
    }
    face->m_ppLinks[index]=0;
}
static __forceinline void cutSeparate(CutTriangle* face,int index) {
    CutEdge edge(face,index);
    if(edge.link().isValid() && face->side!=edge.link().m_pkTriangle->side) edge.unbind();
}
// Splits the mesh along the plane p, removes degenerate faces, and optionally separates linked faces on opposite sides.
// @fnv 0x00e1bd30
// src: GUESS 0x00e1bd30 (confidence: medium)
int* CutMesh::SplitMeshAlongPlane(int* result,const CutVec& p,bool splitSides) {
    if(ProcessEntries_00e11990(p,0)==3) {
    plane.quad()=p.quad();
    bool changed;
    do {
        changed=false;
        for(CutTriangle* face=faces.head;face;face=face->next) {
            for(int i=0;i<3;++i) {
                CutEdge edge(face,i);
                if(!edge.master()) goto nextEdge;
                CutVertex* start=edge.start();
                CutVertex* end=edge.end();
                const float* endPosition=&end->position.component(0);
                float a=start->distance.component(0);
                float b=end->distance.component(0);
                if(a*b<DAT_01012060) {
                    float fraction=a/(a-b);
                    CutVertex* vertex=vertices.allocate(CutVertex());
                    __m128 origin=_mm_load_ps(&start->position.component(0));
                    __m128 t=_mm_load_ss(&fraction);
                    vertex->position.quad()=_mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_load_ps(endPosition),origin),_mm_shuffle_ps(t,t,0)),origin);
                    vertex->distance.quad()=reinterpret_cast<const __m128&>(DAT_01267e30);
                    if(!edge.link().isValid()) {
                        CutTriangle* added=faces.allocate(*face);
                        CutEdge aedge(added,0);
                        aedge.start()=edge.start();
                        aedge.next().start()=vertex;
                        aedge.prev().start()=edge.prev().start();
                        edge.start()=vertex;
                        aedge.prev().bind(edge.prev().link());
                        aedge.next().bind(edge.prev());
                        _ReadWriteBarrier();
                        aedge.bind(cutNullEdge());
                    } else {
                        CutEdge opposite=edge.link();
                        CutTriangle* added=faces.allocate(*face);
                        CutTriangle* other=faces.allocate(*opposite.triangle());
                        CutEdge aedge(added,0), bedge(other,0);
                        aedge.start()=edge.start();
                        aedge.next().start()=vertex;
                        aedge.prev().start()=edge.prev().start();
                        bedge.start()=opposite.start();
                        bedge.next().start()=vertex;
                        bedge.prev().start()=opposite.prev().start();
                        opposite.start()=vertex;
                        edge.start()=vertex;
                        aedge.prev().bind(edge.prev().link());
                        aedge.next().bind(edge.prev());
                        aedge.bind(opposite);
                        bedge.prev().bind(opposite.prev().link());
                        bedge.next().bind(opposite.prev());
                        bedge.bind(edge);
                    }
                    --i;
                    changed=true;
                }
            nextEdge:;
            }
        }
    } while(changed);
    CutArray remove;
    remove.data=0; remove.size=0; remove.capacity=0x80000000;
    for(CutTriangle* face=faces.head;face;face=face->next) {
        float distances[3];
        for(int j=0;j<3;++j) distances[j]=((CutVertex*)face->m_kVertices[j])->distance.component(0);
        float sum=distances[0]+distances[1]+distances[2];
        if(sum==0.0f) {
            hkMemoryRouter& r=hkMemoryRouter_getInstance();
            if(remove.size==(remove.capacity&0x3fffffff)) ResizeAudioStream(reinterpret_cast<Allocator*>(r.m_heap),&remove,4);
            remove.data[remove.size++]=face;
        } else face->side=sum>=0.0f?0:1;
    }
    for(int i=0;i<remove.size;++i) {
        cutUnlink(remove.data[i],0);
        cutUnlink(remove.data[i],1);
        cutUnlink(remove.data[i],2);
    }
    for(int i=0;i<remove.size;++i) {
        faces.remove(remove.data[i]);
    }
    if(remove.size>0) { hkgpMesh_removeOrphanVertices(); ReleaseSubobject(); }
    if(splitSides) {
        for(CutTriangle* face=faces.head;face;face=face->next) {
            cutSeparate(face,0);
            cutSeparate(face,1);
            cutSeparate(face,2);
        }
        ResolveLinkNodes();
    }
    *result=0;
    hkMemoryRouter& r=hkMemoryRouter_getInstance();
    Allocator* allocator=reinterpret_cast<Allocator*>(r.m_heap);
    remove.size=0;
    if((remove.capacity&0x80000000)==0) allocator->freeBlock(remove.data,(remove.capacity&0x3fffffff)*4);
    return result;
    } else {
    for(CutTriangle* face=faces.head;face;face=face->next) face->side=0;
    *result=1;
    return result;
    }
}

namespace N {
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct { float x, y, z, w; };
} __m128, LocalM128;
extern "C" {
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_add_ps(__m128, __m128);
__m128 _mm_add_ss(__m128, __m128);
__m128 _mm_sub_ss(__m128, __m128);
__m128 _mm_xor_ps(__m128, __m128);
__m128 _mm_shuffle_ps(__m128, __m128, int);
__m128 _mm_load_ss(const float*);
void _mm_store_ss(float*, __m128);
}
}

extern __m128 DAT_010c44d0;
extern __m128 DAT_010c7160;
extern double DAT_01017cf8;
extern float DAT_010959f4;
extern int DAT_010eadb4;

struct S_00e22050_V4 {
    N::__m128 m_vComponents;
};

struct S_00e22050_Plane {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    S_00e22050_V4 m_kTriangleNormal;
};

struct S_00e22050_Arg {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    S_00e22050_Plane* m_kTriangleNormal;
};

struct S_00e22050_Obj {
    int* vtbl;
    S_00e22050_Plane* m_kTriangleNormal;
};

struct S_00e22050_Support {
    virtual void v0();
    virtual void v1();
    virtual void v2(const S_00e22050_V4& dir, S_00e22050_V4& out);
};

struct S_00e22050_Cast {
    virtual void v0();
    virtual float v1(S_00e22050_Support* s, S_00e22050_Obj* o, unsigned char flag);
};

struct S_00e22050 {
    int unk00;
    float m_tol;
    S_00e22050_Cast* m_cast;
    S_00e22050_Support* m_pSupport;
    char m_bHasHit;
    char m_flag;
    float hkgpMesh_CollideShapeTriangle_addLeaf(S_00e22050_Arg* a);
};

static __forceinline float getReal(N::__m128 v) {
    float f;
    N::_mm_store_ss(&f, v);
    return f;
}

static N::__m128 Dot4(N::__m128 a, N::__m128 b) {
    N::__m128 m = N::_mm_mul_ps(a, b);
    N::__m128 r = N::_mm_add_ss(N::_mm_shuffle_ps(m, m, 0xaa), N::_mm_shuffle_ps(a, a, 0xff));
    return N::_mm_add_ps(r, N::_mm_add_ss(N::_mm_shuffle_ps(m, m, 0x55), m));
}

static N::__m128 Dot4B(N::__m128 a, N::__m128 b) {
    N::__m128 m;
    N::__m128 r = N::_mm_add_ss(N::_mm_shuffle_ps((m = N::_mm_mul_ps(a, b)), m, 0xaa), N::_mm_shuffle_ps(a, a, 0xff));
    return N::_mm_add_ps(r, N::_mm_add_ss(N::_mm_shuffle_ps(m, m, 0x55), m));
}

// Queries m_pSupport along the plane normal and its negation; if both band checks pass, calls m_cast->v1, sets m_bHasHit and returns 0 when below m_tol, else 1.
// @fnv 0x00e22050
// src: XBOX_PDB 0x00e22050
float S_00e22050::hkgpMesh_CollideShapeTriangle_addLeaf(S_00e22050_Arg* a)
{
    S_00e22050_Plane* pPlane = a->m_kTriangleNormal;
    S_00e22050_V4 n;
    S_00e22050_V4 neg;
    n.m_vComponents = pPlane->m_kTriangleNormal.m_vComponents;
    neg.m_vComponents = N::_mm_xor_ps(pPlane->m_kTriangleNormal.m_vComponents, *(N::__m128*)&DAT_010c44d0);
    float f = -m_tol;
    float fThreshold = f < DAT_01017cf8 ? DAT_010959f4 : f;
    S_00e22050_Obj o;
    S_00e22050_V4 out;
    N::__m128 threshold = N::_mm_load_ss(&fThreshold);
    m_pSupport->v2(n, out);
    if (!(getReal(Dot4(pPlane->m_kTriangleNormal.m_vComponents, out.m_vComponents)) < getReal(threshold))) {
        m_pSupport->v2(neg, out);
        if (!(getReal(Dot4B(pPlane->m_kTriangleNormal.m_vComponents, out.m_vComponents)) > getReal(N::_mm_sub_ss(*(N::__m128*)&DAT_010c7160, threshold)))) {
            o.vtbl = &DAT_010eadb4;
            o.m_kTriangleNormal = pPlane;
            float r = m_cast->v1(m_pSupport, &o, m_flag);
            if (r < m_tol) { m_bHasHit = 1; return 0.0f; }
        }
    }
    return 1.0f;
}

struct S00e22640_Pair { int lo; int hi; };
void __cdecl hkArrayUtil__reserve(void* allocator, void* self, int newCap, int elemSize);
template <typename T>
struct S00e22640_hkArrayLocalForm { // local form of hkArrayBase: 0x00e22640 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data; int m_iElementCount; int m_iCapacityState;
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void reserve(void* alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n) {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(alloc, this, newSize, sizeof(T));
        }
    }
    static __forceinline void constructWithArray(T* t, int n, const T* tcopy)
    {
        for (int i = 0; i < n; ++i) {
            new (t + i) T(tcopy[i]);
        }
    }
    __forceinline void append(void* alloc, const T* a, int numElems)
    {
        int newsize = m_iElementCount + numElems;
        if (newsize > getCapacity()) {
            reserve(alloc, newsize);
        }
        constructWithArray(m_data + m_iElementCount, numElems, a);
        m_iElementCount = newsize;
    }
};
struct S00e22640_Arr : S00e22640_hkArrayLocalForm<S00e22640_Pair> {
    void hkArrayBase_struct_hkgpMeshBase_Edge_append(void* allocator, const S00e22640_Pair* src, int n);
};
// Appends n elements from src to the array using the allocator.
// @fnv 0x00e22640
// src: HAVOK_LIB 0x00e22640
void S00e22640_Arr::hkArrayBase_struct_hkgpMeshBase_Edge_append(void* allocator, const S00e22640_Pair* src, int aiCount)
{
    append(allocator, src, aiCount);
}

__forceinline int delayValue(int value,int) {return value;}
__forceinline int delayValue(int value) {_ReadWriteBarrier();return value;}

struct Face;
struct LayerVertex {
    int unk00, unk04;
    int unk08, unk0c;
    __forceinline int compare(const LayerVertex& b) const {
        if (unk08 < b.unk08) return -1;
        if (unk08 > b.unk08) return 1;
        if (unk0c < b.unk0c) return -1;
        if (unk0c > b.unk0c) return 1;
        return 0;
    }
    static __forceinline bool ordered(const LayerVertex* a, const LayerVertex* b) {
        int cmp=a->compare(*b);
        if(cmp < 0) return true;
        if(cmp > 0) return false;
        return true;
    }
};
struct Face {
    Face* m_next;
    int unk04;
    LayerVertex* m_kVertices[3];
    unsigned int m_kEdges[3];
    struct { unsigned short marks:3; unsigned short root:1; unsigned short region:12; } bits;
    unsigned short unk22;
    __forceinline LayerVertex*& vertex(int i) { return m_kVertices[i]; }
    __forceinline unsigned int& link(int i) { return m_kEdges[i]; }
};
template<class E, class T> struct LayerCore {
    T* m_face;
    unsigned int m_uiEdgeIndex;
    __forceinline LayerCore() {}
    __forceinline LayerCore(T* t, unsigned i):m_face(t),m_uiEdgeIndex(i){}
    __forceinline LayerCore(const unsigned int& id) { unpack(id,m_face,m_uiEdgeIndex); }
    static __forceinline void unpack(unsigned id,T*& t,unsigned& i) {
        i=id & 3; id &= ~3u; t=(T*)id;
    }
    __forceinline E next() const { return E(m_face,(9 >> (m_uiEdgeIndex << 1)) & 3); }
    __forceinline E link() const { return E(m_face->link(m_uiEdgeIndex)); }
    __forceinline T* triangle() const { return m_face; }
    __forceinline LayerVertex*& start() const { return m_face->vertex(m_uiEdgeIndex); }
    __forceinline LayerVertex*& end() const { return m_face->vertex((9 >> (m_uiEdgeIndex << 1)) & 3); }
    __forceinline bool valid() const { return m_face!=0; }
    __forceinline bool unlinked() const { return !link().valid(); }
    __forceinline bool isMaster() const { return LayerVertex::ordered(start(),end()) || unlinked(); }
    __forceinline E canonical() const {
        if(isMaster()) return E(m_face,m_uiEdgeIndex);
        else return link();
    }
};
struct LayerEdge : LayerCore<LayerEdge,Face> {
    typedef LayerCore<LayerEdge,Face> Base;
    __forceinline LayerEdge() {}
    __forceinline LayerEdge(Face* f,unsigned i):Base(f,i){}
    __forceinline LayerEdge(const unsigned int& id):Base(id){}
    __forceinline LayerEdge(const LayerEdge& b):Base(b.m_face,b.m_uiEdgeIndex){}
    __forceinline bool constrained() const {
        LayerEdge c=canonical();
        return (_ReadWriteBarrier(),0) != (c.m_face->bits.marks & (1 << (unsigned char)c.m_uiEdgeIndex));
    }
};
struct QueryResult { int unk00; LayerEdge m_kEdge; };
template <typename T>
struct EdgeArrayLocalForm { // local form of hkArray: 0x00e24b70 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const { return m_iElementCount; }
    T& back() { return m_data[m_iElementCount - 1]; }
    void popBack() { m_iElementCount--; }
    void clear() { m_iElementCount = 0; }

    void AddBack(const T& val) throw() {
        hkMemoryRouter& router = hkMemoryRouter_getInstance();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff)) {
            ResizeAudioStream(reinterpret_cast<Allocator*>(router.m_heap), this, sizeof(T));
        }
        new (&m_data[m_iElementCount]) T(val);
        m_iElementCount++;
    }
};

template <typename T, int N>
struct InplaceEdgeArray : public EdgeArrayLocalForm<T> {
    T m_kStorage[N];

    InplaceEdgeArray() throw() {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000 | N;
    }

    ~InplaceEdgeArray() throw() {
        Allocator& heap = meshHeap(hkMemoryRouter_getInstance());
        this->m_iElementCount = 0;
        if ((this->m_iCapacityState & 0x80000000) == 0) {
            heap.freeBlock(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
    }
};

struct Mesh {
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
    Face* m_faces;
    int unk38;
    int unk3c;
    InplaceEdgeArray<LayerEdge,64> m_kEdges;

    QueryResult* LocatePoint(QueryResult* res, int unk1, int unk2) throw();
    int hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_partition();
};

// Flood-fills faces from the seed edge, assigning region layers and returning the total layer count.
// @fnv 0x00e24b70
// src: HAVOK_LIB 0x00e24b70
int Mesh::hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_partition() {
    for (Face* f = m_faces; f; f = f->m_next) {
        f->bits.region=4095;
    }

    InplaceEdgeArray<LayerEdge, 64> localEdges;
    InplaceEdgeArray<LayerEdge,64>* current = &m_kEdges;
    InplaceEdgeArray<LayerEdge,64>* next = &localEdges;
    int layer = -1;
    QueryResult res;
    next->AddBack(LocatePoint(&res, 0, 0)->m_kEdge);

    do {
        InplaceEdgeArray<LayerEdge,64>* saved = next;
        next = current;
        current = saved;
        next->clear();
        ++layer;
        do {
            Face* face = current->back().m_face;
            current->popBack();
            if (face->bits.region == 4095) {
                face->bits.region=layer;
                for (int i = 0; i < 3; i++) {
                    LayerEdge neighbor=LayerEdge(face,i).link();
                    Face* n=neighbor.triangle();
                    if(neighbor.valid() && n->bits.region == 4095) {
                        if(neighbor.constrained()) next->AddBack(neighbor);
                        else current->AddBack(neighbor);
                    }
                }
            }
        } while (current->GetLogicalSize() > 0);

    } while (next->GetLogicalSize() > 0);

    return layer + 1;
}

void __cdecl ResizeAudioStream(void*, void*, int);
typedef unsigned long S00e25cd0_Ulong;
template<class T> static __forceinline void S00e25cd0_constructWithCopy(T* t, int n, const T& tcopy) {
    for(int i=0; i<n; ++i) {
        t[i] = tcopy;
    }
}
template<class T> struct S00e25cd0_ArrayLocalForm { // local form of hkArray: 0x00e25cd0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data; int m_iElementCount; int m_iCapacityState;
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
    __forceinline int indexOf(const T& t, int startIdx=0, int endIdx=-1) const {
        if(endIdx < 0) endIdx = m_iElementCount;
        for(int i=startIdx; i<endIdx; ++i) {
            if(m_data[i] == t) return i;
        }
        return -1;
    }
    __forceinline T& AllocatePair() {
        hkMemoryRouter& router = hkMemoryRouter_getInstance();
        if(m_iElementCount == (m_iCapacityState & 0x3fffffff)) ResizeAudioStream(reinterpret_cast<Allocator*>(router.m_heap), this, sizeof(T));
        for(int i=0; i<1; ++i) new(m_data+m_iElementCount+i) T;
        return m_data[m_iElementCount++];
    }
    __forceinline void AddBack(const T& t) {
        hkMemoryRouter& router = hkMemoryRouter_getInstance();
        if(m_iElementCount == (m_iCapacityState & 0x3fffffff)) ResizeAudioStream(reinterpret_cast<Allocator*>(router.m_heap), this, sizeof(T));
        S00e25cd0_constructWithCopy(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};
struct S00e25cd0_EdgeData : S00e25cd0_ArrayLocalForm<S00e25cd0_Ulong> {
    S00e25cd0_Ulong m_inline[4];
    __forceinline S00e25cd0_EdgeData() { m_data=m_inline; m_iElementCount=0; m_iCapacityState=0x80000004; }
    __forceinline void appendOrReplace(const S00e25cd0_ArrayLocalForm<S00e25cd0_Ulong>& data) {
        for(int i=0; i<data.GetLogicalSize(); ++i) {
            if(indexOf(data[i]) == -1) AddBack(data[i]);
        }
    }
};
struct S00e25cd0_Vertex {
    int unk00, unk04;
    int m_uiX, m_uiY;
    __forceinline S00e25cd0_Ulong pack() const { return (m_uiX << 15) + m_uiY; }
};
struct S00e25cd0_Triangle {
    int unk00, unk04;
    S00e25cd0_Vertex* m_kVertices[3];
    __forceinline S00e25cd0_Vertex*& vertex(unsigned i) { return m_kVertices[i]; }
};
struct S00e25cd0_Edge {
    S00e25cd0_Triangle* m_pkTriangle;
    unsigned m_uiEdgeIndex;
    static __forceinline unsigned ip1mod3(unsigned i) { return (0x09 >> (i << 1)) & 3; }
    __forceinline S00e25cd0_Vertex*& start() const { return m_pkTriangle->vertex(m_uiEdgeIndex); }
    __forceinline S00e25cd0_Vertex*& end() const { return m_pkTriangle->vertex(ip1mod3(m_uiEdgeIndex)); }
};
template<class A, class B> static __forceinline S00e25cd0_Ulong S00e25cd0_makeHash(A a, B b) {
    const S00e25cd0_Ulong va = *(const S00e25cd0_Ulong*)&a;
    const S00e25cd0_Ulong vb = *(const S00e25cd0_Ulong*)&b;
    return (va*3424933) ^ (vb*1661161);
}
struct S00e25cd0_Box {
    S00e25cd0_Vertex* m_kVertices[2];
    S00e25cd0_EdgeData* m_data;
    __forceinline S00e25cd0_Box() { m_kVertices[0]=m_kVertices[1]=0; m_data=0; }
    __forceinline S00e25cd0_Box(const S00e25cd0_Edge& edge) : m_data(0) {
        m_kVertices[0] = edge.start();
        m_kVertices[1] = edge.end();
    }
    __forceinline S00e25cd0_Ulong getHash() const { const S00e25cd0_Vertex* a = m_kVertices[0]; const S00e25cd0_Vertex* b = m_kVertices[1]; return S00e25cd0_makeHash(a->pack(), b->pack()); }
    __forceinline bool operator==(const S00e25cd0_Box& other) const { return m_kVertices[0]==other.m_kVertices[0] && m_kVertices[1]==other.m_kVertices[1]; }
};
struct S00e25cd0_Table {
    S00e25cd0_ArrayLocalForm<S00e25cd0_ArrayLocalForm<S00e25cd0_Box> > m_buckets;
    int m_numItems;
    __forceinline S00e25cd0_ArrayLocalForm<S00e25cd0_Box>& lookupBucket(int hash) { return m_buckets[((unsigned)hash) % m_buckets.GetLogicalSize()]; }
    __forceinline S00e25cd0_Box* find(int hash, const S00e25cd0_Box& value) {
        S00e25cd0_ArrayLocalForm<S00e25cd0_Box>& values = lookupBucket(hash);
        const int index = values.indexOf(value);
        if(index == -1) return 0;
        else return &values[index];
    }
    __forceinline S00e25cd0_Box* insert(int hash, const S00e25cd0_Box& value) {
        ++m_numItems;
        S00e25cd0_ArrayLocalForm<S00e25cd0_Box>& values = lookupBucket(hash);
        values.AllocatePair() = value;
        return &values[values.GetLogicalSize()-1];
    }
    __forceinline S00e25cd0_Box* find(const S00e25cd0_Box& value) { return find((int)value.getHash(), value); }
    __forceinline S00e25cd0_Box* insert(const S00e25cd0_Box& value) { return insert((int)value.getHash(), value); }
};
struct S00e25cd0_Pool
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk01e0;
    int unk01e4;
    int unk01e8;
    int unk01ec;
    int unk01f0;
    int unk01f4;
    int unk01f8;
    int unk01fc;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020c;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021c;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022c;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023c;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024c;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025c;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026c;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027c;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028c;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029c;
    int unk02a0;
    int unk02a4;
    int unk02a8;
    int unk02ac;
    int unk02b0;
    int unk02b4;
    int unk02b8;
    int unk02bc;
    int unk02c0;
    int unk02c4;
    int unk02c8;
    int unk02cc;
    int unk02d0;
    int unk02d4;
    int unk02d8;
    int unk02dc;
    int unk02e0;
    int unk02e4;
    int unk02e8;
    int unk02ec;
    int unk02f0;
    int unk02f4;
    int unk02f8;
    int unk02fc;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030c;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031c;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032c;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033c;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034c;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035c;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036c;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037c;
    S00e25cd0_EdgeData* m_380;
    int m_384;
};
struct S00e25cd0_PoolAlloc {
    S00e25cd0_Pool** data; int count; int cap;
    S00e25cd0_Pool* hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_32_struct_hkContainerHeapAllocator_allocateNewPool();
    __forceinline S00e25cd0_EdgeData* allocate() {
        S00e25cd0_Pool* b;
        if(count == 0 || (b=data[0])->m_380 == 0) b=hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_32_struct_hkContainerHeapAllocator_allocateNewPool();
        S00e25cd0_EdgeData* node=b->m_380;
        b->m_380 = (S00e25cd0_EdgeData*)node->m_data;
        ++b->m_384;
        return new(node) S00e25cd0_EdgeData;
    }
};
struct S00e25cd0_Tri
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk01e0;
    int unk01e4;
    int unk01e8;
    int unk01ec;
    int unk01f0;
    int unk01f4;
    int unk01f8;
    int unk01fc;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020c;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021c;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022c;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023c;
    int unk0240;
    int unk0244;
    int unk0248;
    S00e25cd0_Table* m_24c;
    S00e25cd0_PoolAlloc m_250;
    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_createEdgeDataHashTable();
    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_setEdgeData(const S00e25cd0_Edge& edge, const S00e25cd0_ArrayLocalForm<S00e25cd0_Ulong>& data);
};
// Finds or creates a box entry for edge in m_24c, allocates an edge data slot if new, and appends or replaces data in it.
// @fnv 0x00e25cd0
// src: HAVOK_LIB 0x00e25cd0
void S00e25cd0_Tri::hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_setEdgeData(const S00e25cd0_Edge& edge, const S00e25cd0_ArrayLocalForm<S00e25cd0_Ulong>& data) {
    if(!m_24c) hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_createEdgeDataHashTable();
    S00e25cd0_Box box(edge);
    S00e25cd0_Box* edgeData = m_24c->find(box);
    if(!edgeData) {
        edgeData = m_24c->insert(box);
        edgeData->m_data = m_250.allocate();
    }
    edgeData->m_data->appendOrReplace(data);
}

namespace fnv_00e275d0 {
struct FUN_00e25f00_cls { void FUN_00e25f00(int a); };
struct AllocOps { virtual void v0(); virtual void v1(); virtual void Free(void* p, int sz); };
struct Iface { virtual void s0(); virtual void s1(); virtual void s2(); virtual void Do(); };
struct Vert { int unk0,unk4,x,y; unsigned constrained:1,data:31; Vert() {} };
struct TriE275 : TriBase<Vert*> {
 unsigned int m_ppLinks[3]; unsigned short edges:3,root:1,region:12; unsigned short sets;
 __forceinline Vert*& vertex(int i) { return m_vtx[i]; }
__forceinline void corners(Vert* const& a,Vert* const& b,Vert* const& c) {m_vtx[0]=a;m_vtx[1]=b;m_vtx[2]=c;}
TriE275() {} __declspec(noinline) TriE275& hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_Triangle(const TriE275& value);};
struct VBlock { Vert items[32]; Vert* free; int used; };
struct VPool { VBlock** blocks; int count,capacity; Vert* head; int numUsed,uid;
 VBlock* hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_allocateNewPool();
 __declspec(noinline) Vert* hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_allocate(const Vert& k=Vert()); };
struct TBlock { TriE275 items[32]; TriE275* free; int used; };
struct TPool {
    TBlock** blocks; int count,capacity; TriE275* head; int numUsed,uid;
    TBlock* hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_allocateNewPool(); __declspec(noinline) TriE275* hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_allocate(const TriE275& k=TriE275());
};
// src: HAVOK_LIB 0x00e23080
__declspec(noinline) TriE275& TriE275::hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_Triangle(const TriE275& value) {
 m_vtx[0]=value.m_vtx[0];m_vtx[1]=value.m_vtx[1];m_vtx[2]=value.m_vtx[2];
 m_ppLinks[0]=value.m_ppLinks[0];m_ppLinks[1]=value.m_ppLinks[1];m_ppLinks[2]=value.m_ppLinks[2];
 edges=value.edges;root=value.root;region=value.region;sets=value.sets;return *this;
}
// src: HAVOK_LIB 0x00e247c0
__declspec(noinline) Vert* VPool::hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_allocate(const Vert& value) {
 VBlock* block;
 if(count && blocks[0]->free) block=blocks[0]; else block=hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_allocateNewPool();
 Vert* item=block->free;block->free=(Vert*)item->unk0;++block->used;
 item->x=value.x;item->y=value.y;item->constrained=value.constrained;item->data=value.data;
 item->unk4=0;item->unk0=(int)head;if(head)head->unk4=(int)item;head=item;++numUsed;
 return item;
}
// src: HAVOK_LIB 0x00e24850
__declspec(noinline) TriE275* TPool::hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_allocate(const TriE275& value) {
 TBlock* block;
 if(count && blocks[0]->free) block=blocks[0]; else block=hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_allocateNewPool();
 TriE275* item=block->free;block->free=(TriE275*)item->m_unk00;++block->used;
 item->hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_Triangle(value);
 item->m_unk04=0;item->m_unk00=(int)head;if(head)head->m_unk04=(int)item;head=item;++numUsed;
 return item;
}
struct MeshBoundaryEdge { TriE275* face; unsigned int index; MeshBoundaryEdge(TriE275* t,unsigned int i):face(t),index(i){}unsigned int uid() const {return (unsigned int)face+index;} unsigned int& link() const {return face->m_ppLinks[index];}void bind(MeshBoundaryEdge other) const {link()=other.uid();other.link()=uid();}};
struct EdgeWorkStack { S_00e13910_Edge* data; int size,capacity; S_00e13910_Edge storage[64]; };
struct Mesh {
    int unk0, unk4;
    Iface m_08;
    int unk0c;
    VPool m_10;
    TPool m_28;
    EdgeWorkStack m_aiEntries;
    FUN_00e25f00_cls* m_24c;
    int** m_250;
    int m_254;
    int unk258;
    TriE275* grid[256];
static __forceinline int gridCell(int horizontal,int vertical) {
 horizontal >>= 11; vertical >>= 11; return (vertical<<4)+horizontal;
}
__forceinline void indexFace(TriE275* face) {
 const int horizontal=(face->vertex(0)->x+face->vertex(1)->x+face->vertex(2)->x)/3;
 const int vertical=(face->vertex(0)->y+face->vertex(1)->y+face->vertex(2)->y)/3;
 grid[gridCell(horizontal,vertical)]=face;
 face->root=1;
}
__forceinline TriE275* createFace(Vert* a,Vert* b,Vert* c) {
  TriE275* result=m_28.hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_allocate();
 result->corners(a,b,c);
 result->edges=0; result->region=0; result->root=0; result->sets=0;
 indexFace(result); return result;
}
__forceinline Vert* createCorner(int x,int y,int constrained) {
  Vert* p=m_10.hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_allocate();
 p->x=x; p->y=y; p->constrained=constrained; p->data=0; p->data=~p->data; return p;
}
    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_reset(bool build);
};
// Calls m_08.Do, clears the grid, frees m_24c and the m_250 blocks, and when build is set creates two root triangles over a 0x7fff square.
// @fnv 0x00e275d0
// src: HAVOK_LIB 0x00e275d0
void Mesh::hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_reset(bool abBuildRoots)
{
    m_08.Do();
    for (int i=0;i<256;i++) grid[i]=0;
    if (m_24c) {
        AllocOps* pAllocOps = (AllocOps*)reinterpret_cast<Allocator*>(hkMemoryRouter_getInstance().m_heap);
        m_24c->FUN_00e25f00(0);
        pAllocOps->Free(m_24c, 0x10);
        m_24c = 0;
    }
    for (int i = 0; i < m_254; i++) {
        int* p = m_250[i];
        hkMemoryRouter& r = hkMemoryRouter_getInstance();
        AllocOps* pAllocOps = (AllocOps*)reinterpret_cast<Allocator*>(r.m_heap);
        pAllocOps->Free(p, 0x388);
    }
    m_254 = 0;
    if (abBuildRoots) {
Vert* v0=createCorner(0,0,0); Vert* v1=createCorner(0,0x7fff,0);
 Vert* v2=createCorner(0x7fff,0,0); Vert* v3=createCorner(0x7fff,0x7fff,0);
 TriE275* t1=createFace(v0,v2,v3); TriE275* t2=createFace(v0,v3,v1);
t1->m_ppLinks[0]=t1->m_ppLinks[1]=t1->m_ppLinks[2]=0;t2->m_ppLinks[0]=t2->m_ppLinks[1]=t2->m_ppLinks[2]=0;MeshBoundaryEdge(t1,2).bind(MeshBoundaryEdge(t2,0));
    }
}
}  // namespace fnv_00e275d0

extern "C" __m128 _mm_setr_ps(float x, float y, float z, float w);
struct __declspec(align(16)) BoundVec { union { __m128 q; float f[4]; }; };
extern "C" __m128 _mm_set_ps(float w, float z, float y, float x);
extern "C" __m128 _mm_max_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_min_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern float DAT_0104e148;
extern const float DAT_01011d78;
extern double DAT_010cbf48;
extern double DAT_01011588;
extern double DAT_01029790;
struct BigConst { Float4 v[4]; };
extern BigConst DAT_0126a3e0;
struct PointsArg { float* m_data; int m_uiItemCount; int m_iElementIndex; };
struct TailA { Float4 columns[4]; void hkMatrix4_setMul(const BigConst* a, const Float4* b); };
struct TailB { Float4 columns[4]; void hkMatrix4_CopyColumnsAndApplyValue(const TailA* p, float z); };
struct E27850This {
    void UpdateTransformedBounds(PointsArg* pts, Float4* mat, unsigned char flagA, unsigned char flagB);
    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_reset(int a);
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
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int m_65c;
    TailB m_660;
    TailA m_6a0;
};
// Computes a transformed bounding box from pts and mat, expands it, and updates m_65c, m_6a0, and m_660.
// @fnv 0x00e27850
// src: GUESS 0x00e27850 (confidence: medium)
void E27850This::UpdateTransformedBounds(PointsArg* apPoints, Float4* apMatrix, unsigned char flagA, unsigned char flagB) {
    BoundVec mn;
    BoundVec fa;
    __declspec(align(16)) Float4 c2;
    mn.q = _mm_setr_ps(DAT_0104da48, DAT_0104da48, DAT_0104da48, DAT_01011d78);
    fa.q = _mm_setr_ps(DAT_0104e148, DAT_0104e148, DAT_0104e148, DAT_01011d78);
    long yy;
    yy = apPoints->m_uiItemCount;
    if (yy > 0) {
        __m128 col1 = _mm_load_ps(&apMatrix[1].x);
        int w = apPoints->m_iElementIndex;
        _mm_store_ps(&c2.x, _mm_load_ps(&apMatrix[0].x));
        float* p = apPoints->m_data;
        do {
            float t = (int)16 <= w ? p[3] : 0.0f;
            __m128 pt = _mm_setr_ps(p[0], p[1], p[2], t);
            __m128 fb = _mm_add_ps((_mm_mul_ps(_mm_shuffle_ps(pt, pt, 0), (_mm_load_ps(&c2.x)))), (_mm_mul_ps(_mm_shuffle_ps(pt, pt, 0x55), col1)));
            fb = _mm_add_ps(fb, _mm_mul_ps(_mm_shuffle_ps(pt, pt, 0xaa), ((__m128&)apMatrix[2])));
            fb = _mm_add_ps(fb, ((__m128&)apMatrix[3]));
            mn.q = _mm_min_ps(mn.q, fb);
            fa.q = _mm_max_ps(fa.q, fb);
            p = (float*)((char*)p + w);
        } while (--yy);
    }
    if ((double)fa.f[0] - (double)mn.f[0] < DAT_010cbf48) {
        mn.f[0] = (float)((double)mn.f[0] - DAT_010cbf48);
        fa.f[0] = (float)(DAT_010cbf48 + (double)fa.f[0]);
    }
    if ((double)fa.f[1] - (double)mn.f[1] < DAT_010cbf48) {
        mn.f[1] = (float)((double)mn.f[1] - DAT_010cbf48);
        fa.f[1] = (float)(DAT_010cbf48 + (double)fa.f[1]);
    }
    Float4& s = c2;
    { __m128 vd = _mm_sub_ps(fa.q, mn.q); _mm_store_ps(&s.x, vd); }
    if (flagB) {
        int i = (s.x > s.y) ? 0 : 1;
        int j = 1 - i;
        float ptr = (float)(((double)(&s.x)[i] - (double)(&s.x)[j]) * DAT_01011588);
        mn.f[j] = mn.f[j] - ptr;
        fa.f[j] = fa.f[j] + ptr;
        (&s.x)[j] = (&s.x)[i];
    }
    int v = flagA != 0;
    m_65c = v;
    float f = (float)v;
    __declspec(align(16)) BigConst ws = DAT_0126a3e0;
    float range;
    range = (float)(DAT_01029790 - (f * 2.0f));
    ws.v[0].x = range / s.x;
    ws.v[1].y = range / s.y;
    ws.v[3].x = f - ws.v[0].x * mn.f[0];
    (*(ws.v + 3)).y = f - ws.v[1].y * mn.f[1];
    m_6a0.hkMatrix4_setMul(&ws, apMatrix);
    m_660.hkMatrix4_CopyColumnsAndApplyValue(&m_6a0, 0.0f);
    hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_reset(1);
}

namespace fnv_00e12890 {
// FUN_00e12890: collect the linked list at this+0x2c into an output vector,
// marking nodes when a flag byte is set, then sort the collected pointers.

struct FUN_00e12890_Holder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_10;
};

struct FUN_00e12890_Node {
    FUN_00e12890_Node* m_00;
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
    int m_34;
};

struct FUN_00e12890_List {
    FUN_00e12890_Node** m_00;
    int m_04;
    unsigned int m_08;
};

struct FUN_00e12890_cls {
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
    FUN_00e12890_Node* m_2c;
    int m_30;
    void hkgpMesh_fetchAreaSortedTriangles(FUN_00e12890_List* out, int flag);
};

FUN_00e12890_Holder* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(void* allocator, void* list, int count, int elemSize);
void __cdecl Hkgpmesh_SortTrianglePointerRange(void* data, int start, int end, int flag);

// Appends each node in the m_2c chain to out (setting node->m_34 to -1 when flag is set), then calls FUN_00e22a50 on out's items if there is more than one.
// @fnv 0x00e12890
// src: HAVOK_LIB 0x00e12890
void FUN_00e12890_cls::hkgpMesh_fetchAreaSortedTriangles(FUN_00e12890_List* apList, int flag) {
    apList->m_04 = 0;
    int need = m_30;
    FUN_00e12890_Holder* holder = (FUN_00e12890_Holder*)hkMemoryRouter_getInstance();
    if ((int)(apList->m_08 & 0x3fffffff) < need) {
        hkArrayUtil__reserve(holder->m_10, apList, need, 4);
    }
    FUN_00e12890_Node* node = m_2c;
    int one = 1;
    if (node != 0) {
        need = -1;
        do {
            if (*(char*)&flag) {
                node->m_34 = need;
            }
            FUN_00e12890_Node** slot = apList->m_00 + apList->m_04;
            *slot = node;
            *slot = node;
            apList->m_04 += one;
            node = node->m_00;
        } while (node != 0);
    }
    *(char*)&flag = 0;
    if (apList->m_04 > one) {
        Hkgpmesh_SortTrianglePointerRange(apList->m_00, 0, apList->m_04 - 1, flag);
    }
}
}  // namespace fnv_00e12890

namespace fnv_00e15830 {
inline void* __cdecl operator new(unsigned int, void* where) throw() { return where; }





hkMemoryRouter& hkMemoryRouter_getInstance() throw();
void ResizeAudioStream(hkMemoryAllocator& alloc, void* array, int elemSize) throw();

template <typename T>
struct S_00e15830_ArrayLocalForm { // local form of hkArray: 0x00e15830 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    S_00e15830_ArrayLocalForm() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~S_00e15830_ArrayLocalForm() throw() { _clearAndDeallocate(hkMemoryRouter_getInstance().heap()); }

    int getCapacity() const throw() { return m_iCapacityState & 0x3fffffff; }
    int GetLogicalSize() const throw() { return m_iElementCount; }
    void clear() throw() { m_iElementCount = 0; }
    T& back() throw() { return m_data[m_iElementCount - 1]; }
    void popBack() throw() { m_iElementCount--; }

    void _pushBack(hkMemoryAllocator& alloc, const T& t) throw()
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(alloc, this, sizeof(T));
        new (m_data + m_iElementCount) T(t);
        m_iElementCount++;
    }
    void AddBack(const T& t) throw() { _pushBack(hkMemoryRouter_getInstance().heap(), t); }

    void _clearAndDeallocate(hkMemoryAllocator& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct S_00e15830_Node {
    S_00e15830_Node* m_next;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    unsigned int m_ppLinks[3];
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int m_iValueAt0x30;
    int unk34;
    int m_iMaterialIndex;
};

struct S_00e15830_Edge {
    S_00e15830_Node* m_node;
    int m_uiEdgeIndex;
    S_00e15830_Edge(S_00e15830_Node* n, int i) throw() : m_node(n), m_uiEdgeIndex(i) {}
    unsigned int link() const throw() { return m_node->m_ppLinks[m_uiEdgeIndex]; }
    S_00e15830_Edge linked() const throw() { return S_00e15830_Edge((S_00e15830_Node*)(link() & ~3u), link() & 3); }
    bool sameMaterial() const throw()
    {
        unsigned int l = link();
        return (l & ~3u) == 0 || m_node->m_iMaterialIndex == ((S_00e15830_Node*)(l & ~3u))->m_iMaterialIndex;
    }
};

struct S_00e15830_Mesh {
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
    S_00e15830_Node* m_kNodeCollection;
    int hkgpMesh_floodFillDetachedOrMaterialBoundariesParts();
};

// Flood-fills connected triangles that share a material into numbered regions; returns the region count.
// Flood-fills the node collection to assign each node a region ID based on material connectivity and returns the total number of regions.
// @fnv 0x00e15830
// src: HAVOK_LIB 0x00e15830
int S_00e15830_Mesh::hkgpMesh_floodFillDetachedOrMaterialBoundariesParts()
{
    int numRegions = 0;
    for (S_00e15830_Node* n = m_kNodeCollection; n; n = n->m_next)
        n->m_iValueAt0x30 = -1;

    S_00e15830_ArrayLocalForm<S_00e15830_Edge> stack;
    for (S_00e15830_Node* n = m_kNodeCollection; n; n = n->m_next)
    {
        if (n->m_iValueAt0x30 != -1)
            continue;
        stack.clear();
        stack.AddBack(S_00e15830_Edge(n, 0));
        stack.AddBack(S_00e15830_Edge(n, 1));
        stack.AddBack(S_00e15830_Edge(n, 2));
        n->m_iValueAt0x30 = numRegions++;
        do
        {
            S_00e15830_Edge edge = stack.back();
            S_00e15830_Edge neighbourEdge = edge.linked();
            int index = neighbourEdge.m_uiEdgeIndex;
            S_00e15830_Node* other = neighbourEdge.m_node;
            stack.popBack();
            if (other && other->m_iValueAt0x30 == -1 &&
                edge.sameMaterial())
            {
                other->m_iValueAt0x30 = numRegions - 1;
                stack.AddBack(S_00e15830_Edge(other, (9 >> (index << 1)) & 3));
                stack.AddBack(S_00e15830_Edge(other, (0x12 >> (index << 1)) & 3));
            }
        } while (stack.GetLogicalSize());
    }
    return numRegions;
}
}  // namespace fnv_00e15830

typedef float QhkReal;
typedef unsigned char QhkUint8;
typedef unsigned short QhkUint16;
typedef unsigned int QhkUint32;
typedef unsigned long __w64 QhkUlong;
enum QhkResult
{
HK_SUCCESS=0,
HK_FAILURE=1
};
typedef unsigned __w64 Qhk_size_t;class QhkFinishLoadedObjectFlag
{
public:
QhkFinishLoadedObjectFlag():m_bFinishing(0){}
int m_bFinishing;
};
class QhkBool
{
public:
typedef char CompileTimeTrueType;inline operator bool()const
{
return m_cBooleanValue !=0;
}
private:
char m_cBooleanValue;};
template<typename TYPE>
class QhkPadSpu
{
public:
__forceinline QhkPadSpu(){}
private:
TYPE m_kStorage;};
template<typename T>struct QhkSizeOfTypeOrVoid{enum{val=sizeof(T)};};
class Qmemrouter;
namespace Qr{Qmemrouter&__cdecl hkMemoryRouter_getInstance() throw();}
void __cdecl ResizeAudioStream(void*,void*,int) throw();
class Qmemalloc
{
public:
__forceinline void*__cdecl operator new(Qhk_size_t,void*p){return p;}
virtual ~Qmemalloc();
virtual void*AllocateMemoryBlock(int numBytes)=0;
virtual void ReleaseBlock(void*p,int numBytes)=0;
virtual void*AllocateBufferWithSize(int&reqNumBytesInOut);
virtual void ReturnMemory(void*p,int numBytes);template<typename TYPE>
inline void _bufFree(void*p,int numElem)
{
const int SIZE_ELEM=QhkSizeOfTypeOrVoid<TYPE>::val;
ReturnMemory(p,numElem*SIZE_ELEM);
}
public:
enum MemoryState
{
MEMORY_STATE_OK,
MEMORY_STATE_OUT_OF_MEMORY
};};struct QhkStackMemory
{
public:
__forceinline QhkStackMemory();protected:
QhkPadSpu<void*>m_next;
QhkPadSpu<void*>m_kRayStart;
QhkPadSpu<void*>m_kRayEnd;};
class Qmemrouter
{
public:
__forceinline void*__cdecl operator new(Qhk_size_t,void*p){return p;}
typedef Qmemalloc Allocator;
static Qmemrouter&__cdecl GetMonitorStream(){return Qr::hkMemoryRouter_getInstance();}inline Allocator&heap(){return*m_pStreamAllocator;}
protected:
QhkStackMemory m_aiEntries;
Allocator*m_pTemp;
Allocator*m_pStreamAllocator;
Allocator*m_pDebugAllocator;};
class QhkBaseObject
{
public:
static const struct QhkInternalClassMember Members[];
__forceinline virtual ~QhkBaseObject(){}
public:
__forceinline QhkBaseObject(){}
};
class QhkReferencedObject:public QhkBaseObject
{
public:
__forceinline void*__cdecl operator new(Qhk_size_t nbytes){;QhkReferencedObject*b=static_cast<QhkReferencedObject*>(Qmemrouter::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<QhkUint16>(nbytes);;return b;}
public:
enum
{
MASK_MEMSIZE=0x7fff
};
QhkUint16 m_usMemSizeAndFlags;
public:
QhkReferencedObject(class QhkFinishLoadedObjectFlag flag){}
};template<bool N>struct QhkTraitBool{typedef QhkTraitBool<N>type;enum{result=N};};
typedef QhkTraitBool<true>QhkTypeIsPod;
template<typename T>
struct QhkIsPodType:public QhkTraitBool<(sizeof(*static_cast<T*>(0)==*static_cast<const QhkTypeIsPod*>(0))==sizeof(QhkBool::CompileTimeTrueType))>{};
class QhkArrayUtil
{
public:
template<typename T>static __forceinline void construct(T*t,int n,QhkTypeIsPod);
template<typename T>static __forceinline void constructWithCopy(T*t,int n,const T&tcopy,QhkTypeIsPod);
template<typename T>static __forceinline void destruct(T*t,int n,QhkTypeIsPod);
static void __cdecl GrowArray(Qmemalloc&a,void*array,int sizeElem){ResizeAudioStream(&a,array,sizeElem);}};template<typename T>
__forceinline void QhkArrayUtil::constructWithCopy(T*t,int n,const T&tcopy,QhkTypeIsPod)
{
for(int i=0;i<n;++i)
{
t[i]=tcopy;
}
}
template<typename T>
__forceinline void QhkArrayUtil::destruct(T*t,int n,QhkTypeIsPod)
{
}
struct QhkContainerHeapAllocator
{
Qmemalloc&get(const void*){return Qmemrouter::GetMonitorStream().heap();}
};
template<typename T>
class QhkArrayBaseLocalForm
{ // local form of hkArrayBase: 0x00e15220 needs the original inline/out-of-line helper split; shared replacement changes bytes.
public:
typedef QhkArrayBaseLocalForm<T>ThisType;
__forceinline QhkArrayBaseLocalForm();
protected:
__forceinline QhkArrayBaseLocalForm(const QhkArrayBaseLocalForm&a){;}
public:
__forceinline void _useExternalArray(T*,int cap);
__forceinline ~QhkArrayBaseLocalForm();
__forceinline T&operator[](int i);
__forceinline int GetLogicalSize()const;
__forceinline int getCapacity()const;
__forceinline void clear();
__forceinline void _clearAndDeallocate(Qmemalloc&alloc);
__forceinline void _pushBack(Qmemalloc&alloc,const T&e);
protected:
__forceinline QhkArrayBaseLocalForm<T>&copyFromArray(Qmemalloc&,const QhkArrayBaseLocalForm<T>&src,QhkTypeIsPod);
public:
enum
{
CAPACITY_MASK=int(0x3FFFFFFF),
FLAG_MASK=int(0xC0000000),
DONT_DEALLOCATE_FLAG=int(0x80000000),
FORCE_SIGNED=-1
};
protected:
friend class QhkStatisticsCollector;
T*m_data;
int m_iElementCount;
int m_iCapacityState;
public:
QhkArrayBaseLocalForm(QhkFinishLoadedObjectFlag f){}
};
template<typename T,typename Allocator=QhkContainerHeapAllocator>
class QhkArray:public QhkArrayBaseLocalForm<T>
{
public:
typedef Allocator AllocatorType;
__forceinline QhkArray():QhkArrayBaseLocalForm<T>(){}
__forceinline ~QhkArray();protected:
__forceinline QhkArray(const QhkArray&a);
public:
__forceinline QhkArray&operator=(const QhkArrayBaseLocalForm<T>&a);
__forceinline void ClearAndRelease(){QhkArrayBaseLocalForm<T>::_clearAndDeallocate(AllocatorType().get(this));}
__forceinline void AddBack(const T&e){QhkArrayBaseLocalForm<T>::_pushBack(AllocatorType().get(this),e);}
};
template<typename T>
__forceinline T&QhkArrayBaseLocalForm<T>::operator[](int i)
{
;
return m_data[i];
}
template<typename T>
__forceinline int QhkArrayBaseLocalForm<T>::GetLogicalSize()const
{
return m_iElementCount;
}
template<typename T>
__forceinline int QhkArrayBaseLocalForm<T>::getCapacity()const
{
return(m_iCapacityState&static_cast<int>(CAPACITY_MASK));
}
template<typename T>
__forceinline void QhkArrayBaseLocalForm<T>::clear()
{
QhkArrayUtil::destruct(m_data,m_iElementCount,typename QhkIsPodType<T>::type());
m_iElementCount=0;
}
template<typename T>
__forceinline QhkArrayBaseLocalForm<T>::QhkArrayBaseLocalForm()
:m_data(0),
m_iElementCount(0),
m_iCapacityState(DONT_DEALLOCATE_FLAG)
{
}
template<typename T>
__forceinline QhkArrayBaseLocalForm<T>::~QhkArrayBaseLocalForm()
{
;
;
}
template<typename T>
__forceinline void QhkArrayBaseLocalForm<T>::_clearAndDeallocate(Qmemalloc&alloc)
{
clear();
if((m_iCapacityState&DONT_DEALLOCATE_FLAG)==0)
{
alloc._bufFree<T>(m_data,getCapacity());
}
m_data=0;
m_iCapacityState=DONT_DEALLOCATE_FLAG;
}
template<typename T>
__forceinline void QhkArrayBaseLocalForm<T>::_pushBack(Qmemalloc&alloc,const T&t)
{
if(m_iElementCount==getCapacity())
{
;
QhkArrayUtil::GrowArray(alloc,this,sizeof(T));
}
QhkArrayUtil::constructWithCopy(m_data+m_iElementCount,1,t,typename QhkIsPodType<T>::type());
m_iElementCount++;}
template<typename T,typename Allocator>
__forceinline QhkArray<T,Allocator>::~QhkArray()
{
ClearAndRelease();
}
typedef __m128 QhkQuadReal;
class QhkSimdReal
{
public:
QhkSimdReal(const QhkQuadReal&x)
:m_vValue(x)
{
}
QhkSimdReal(QhkReal x)
{
m_vValue=_mm_load_ss(&x);
}
operator QhkReal()const
{
QhkReal s;
_mm_store_ss(&s,m_vValue);
return s;
}
__forceinline QhkQuadReal broadcast()const
{
return _mm_shuffle_ps(m_vValue,m_vValue,0);
}
private:
QhkQuadReal m_vValue;};
typedef const QhkSimdReal&QhkSimdRealParameter;namespace QhkMath
{
inline QhkReal __cdecl sqrt(QhkReal r){return::sqrtf(r);}
inline QhkReal __cdecl sqrtInverse(QhkReal r){return 1.0f / QhkMath::sqrt(r);}
inline QhkReal __cdecl fabs(QhkReal r){return::fabsf(r);}
}
class QhkVector4
{
public:
__forceinline void*__cdecl operator new(Qhk_size_t nbytes){;void*obj=Qmemrouter::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
QhkBool::CompileTimeTrueType operator==(const QhkTypeIsPod&)const;
__forceinline void operator=(const QhkVector4&v);
__forceinline void setInt24W(int value);
__forceinline void add4(const QhkVector4&a);
__forceinline void setSub4(const QhkVector4&a,const QhkVector4&b);
__forceinline void mul4(QhkSimdRealParameter a);
__forceinline void setAddMul4(const QhkVector4&a,const QhkVector4&b,QhkSimdRealParameter r);
__forceinline void setMin4(const QhkVector4&a,const QhkVector4&b);
__forceinline void setMax4(const QhkVector4&a,const QhkVector4&b);
__forceinline QhkSimdReal dot3(const QhkVector4&a)const;
__forceinline QhkSimdReal lengthSquared3()const;
__forceinline QhkResult normalize3IfNotZero();
__forceinline QhkReal&operator()(int i);
__forceinline const QhkReal&operator()(int i)const;
QhkBool FUN_00c7f520(QhkReal eps=1e-4f)const throw();
private:
QhkQuadReal m_vComponents;
public:
operator QhkQuadReal()const
{
return m_vComponents;
}
};
class QhkMatrix3
{ // local form of hkMatrix3: 0x00e175b0 needs inline QhkVector4 columns and QhkSimdReal determinant return; shared form gives 1436 bytes versus exe 1356.
public:
__forceinline void*__cdecl operator new(Qhk_size_t nbytes){;void*obj=Qmemrouter::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline QhkVector4&getColumn(int i);
QhkSimdReal FUN_00cd51c0() throw();
protected:
QhkVector4 m_kColumn0;
QhkVector4 m_kColumn1;
QhkVector4 m_kColumn2;};inline void QhkVector4::operator=(const QhkVector4&v)
{
m_vComponents=v.m_vComponents;
}
void QhkVector4::setInt24W(int value)
{
(reinterpret_cast<QhkUint32*>(this))[3]=value |=0x3f000000;
}
inline void QhkVector4::add4(const QhkVector4&v)
{
m_vComponents=_mm_add_ps(m_vComponents,v.m_vComponents);
}
inline void QhkVector4::setSub4(const QhkVector4&v0,const QhkVector4&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void QhkVector4::mul4(QhkSimdRealParameter s)
{
m_vComponents=_mm_mul_ps(s.broadcast(),m_vComponents);
}
inline void QhkVector4::setAddMul4(const QhkVector4&a,const QhkVector4&b,QhkSimdRealParameter r)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(r.broadcast(),b.m_vComponents));
}
inline QhkSimdReal QhkVector4::dot3(const QhkVector4&a)const
{
QhkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
QhkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
inline QhkSimdReal QhkVector4::lengthSquared3()const
{
return this->dot3(*this);
}
inline QhkReal&QhkVector4::operator()(int a)
{
return reinterpret_cast<QhkReal*>(&m_vComponents)[a];
}
inline const QhkReal&QhkVector4::operator()(int a)const
{
return reinterpret_cast<const QhkReal*>(&m_vComponents)[a];
}
inline QhkResult QhkVector4::normalize3IfNotZero()
{
const QhkReal lengthSqrd3=this->lengthSquared3();
if(lengthSqrd3 !=0.0f)
{
this->mul4(QhkMath::sqrtInverse(lengthSqrd3));
return HK_SUCCESS;
}
return HK_FAILURE;
}
inline QhkVector4&QhkMatrix3::getColumn(int x)
{
return(&m_kColumn0)[x];
}
class QhkAabb
{
public:
__forceinline void*__cdecl operator new(Qhk_size_t nbytes){;void*obj=Qmemrouter::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
QhkVector4 m_kMinimumCorner;
QhkVector4 m_kMaximumCorner;};
struct QhkGeometryProcessing
{
template<typename T,const int N,typename ALLOCATOR=QhkContainerHeapAllocator>
struct DynamicMemoryAllocator
{
struct Item
{
QhkUint8 m_data[sizeof(T)];
};
struct Pool
{
__forceinline void*__cdecl operator new(Qhk_size_t nbytes){;void*obj=Qmemrouter::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;Qmemrouter::GetMonitorStream().heap().ReleaseBlock(p,sizeof(Pool));}}__forceinline void*__cdecl operator new(Qhk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](Qhk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
Item m_items[N];
Item*m_free;
int m_uiBufferCapacity;
};
inline DynamicMemoryAllocator(){}
inline ~DynamicMemoryAllocator();
__forceinline T*allocate(){return(new(allocateItem())T());}
__forceinline T*allocate(const T&value){return(new(allocateItem())T(value));}
inline void release(T*item);
__forceinline bool needRelease()const{return(false);}
__forceinline void clear();
private:
inline Item*allocateItem();
inline Pool*GetOrCreatePool();
inline void releasePool(Pool*pool)const;
DynamicMemoryAllocator(const DynamicMemoryAllocator&){}
void operator=(const DynamicMemoryAllocator&){}
private:
QhkArray<Pool*,ALLOCATOR>m_pools;
};
static __forceinline QhkReal tetrahedronVolume6(const QhkVector4&a,const QhkVector4&b,const QhkVector4&c,const QhkVector4&d);};__forceinline QhkReal QhkGeometryProcessing::tetrahedronVolume6(const QhkVector4&a,const QhkVector4&b,const QhkVector4&c,const QhkVector4&d)
{
QhkMatrix3 m;
m.getColumn(0).setSub4(b,a);
m.getColumn(1).setSub4(c,a);
m.getColumn(2).setSub4(d,a);
return(m.FUN_00cd51c0());
}
class QhkgpTopology
{
public:
static __forceinline QhkUlong uid2ulong(void*t,QhkUint32 i){return(*(const QhkUlong*)&t)+(QhkUlong)i;}
template<typename T>
static __forceinline void ulong2uid(QhkUlong uid,T*&t,QhkUint32&i){i=(QhkUint32)(uid&3);uid&=~3;t=*(T**)&uid;}
typedef QhkUlong Uid;template<typename T>
static __forceinline void unpackUid(Uid uid,T*&t,QhkUint32&i){ulong2uid(uid,t,i);}
template<typename EDGE,typename VERTEX,typename TRIANGLE,typename VERTEX_MEMBER=VERTEX*>
struct Edge
{
public:
typedef VERTEX tVertex;
typedef VERTEX_MEMBER tMVertex;
typedef TRIANGLE tTriangle;
protected:
static __forceinline unsigned ip1mod3(unsigned i);
static __forceinline unsigned ip2mod3(unsigned i);
public:
__forceinline static const EDGE&null(){static const EDGE e(0,0);return(e);}
public:
__forceinline Edge(){}
__forceinline Edge(tTriangle*t,unsigned i):m_pkTriangle(t),m_uiEdgeIndex(i){}
__forceinline Edge(const Uid&id){unpackUid(id,m_pkTriangle,m_uiEdgeIndex);}
__forceinline EDGE next()const{return(EDGE(m_pkTriangle,ip1mod3(m_uiEdgeIndex)));}
__forceinline EDGE prev()const{return(EDGE(m_pkTriangle,ip2mod3(m_uiEdgeIndex)));}
__forceinline EDGE link()const{return(EDGE(m_pkTriangle->link(m_uiEdgeIndex)));}
__forceinline EDGE turnCcw()const{return(link().next());}
__forceinline EDGE turnCw()const{return(prev().link());}
__forceinline EDGE nextCw()const{return(link().prev());}
__forceinline EDGE nextCcw()const{return(link().next());}
__forceinline EDGE prevCw()const{return(prev().link());}
__forceinline EDGE prevCcw()const{return(next().link());}
__forceinline EDGE master()const{if(isMaster())return(EDGE(m_pkTriangle,m_uiEdgeIndex));else return(link());}
__forceinline TRIANGLE*triangle()const{return(m_pkTriangle);}
__forceinline int index()const{return((int)m_uiEdgeIndex);}
__forceinline Uid uid()const{return packUid(m_pkTriangle,m_uiEdgeIndex);}
__forceinline tMVertex&start()const{return(m_pkTriangle->vertex(m_uiEdgeIndex));}
__forceinline tMVertex&end()const{return(m_pkTriangle->vertex(ip1mod3(m_uiEdgeIndex)));}
__forceinline tMVertex&apex()const{return(m_pkTriangle->vertex(ip2mod3(m_uiEdgeIndex)));}
__forceinline EDGE self()const{return(EDGE(m_pkTriangle,m_uiEdgeIndex));}
__forceinline bool isValid()const{return(triangle()!=0);}
__forceinline bool isMaster()const{return(tVertex::isOrdered(start(),end())||isNaked());}
__forceinline bool isNaked()const{return(!link().isValid());}
__forceinline bool isBound()const{return(!isNaked());}
__forceinline bool canBind(const Edge&edge)const{return((!edge.isValid())||((start()==edge.end())&&(end()==edge.start())));}
__forceinline bool tryBind(const Edge&edge)const{const bool cb(canBind(edge));if(cb)bind(edge);return(cb);}
__forceinline void bind(const Edge&edge)const;
__forceinline void bindSides()const;
__forceinline void unbind()const;
__forceinline EDGE flip()const;
template<typename FNC>
__forceinline void applyFan(FNC&fnc)const;
__forceinline bool operator==(const EDGE&e)const{return(uid()==e.uid());}
__forceinline bool operator!=(const EDGE&e)const{return(uid()!=e.uid());}
protected:
tTriangle*m_pkTriangle;
QhkUint32 m_uiEdgeIndex;
};};
template<typename EDGE,typename VERTEX,typename TRIANGLE,typename VERTEX_MEMBER>
__forceinline unsigned QhkgpTopology::Edge<EDGE,VERTEX,TRIANGLE,VERTEX_MEMBER>::ip1mod3(unsigned i)
{
;
return((0x09>>(i<<1))&3);
}
template<typename EDGE,typename VERTEX,typename TRIANGLE,typename VERTEX_MEMBER>
__forceinline unsigned QhkgpTopology::Edge<EDGE,VERTEX,TRIANGLE,VERTEX_MEMBER>::ip2mod3(unsigned i)
{
;
return((0x12>>(i<<1))&3);
}
struct QhkgpAbstractMeshDefinitions
{
typedef QhkgpTopology::Uid Uid;
template<typename T,typename BASE,typename ALLOCATOR=QhkGeometryProcessing::DynamicMemoryAllocator<T,32>>
struct List
{
struct Item:BASE
{
__forceinline void*__cdecl operator new(Qhk_size_t nbytes){;void*obj=Qmemrouter::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;Qmemrouter::GetMonitorStream().heap().ReleaseBlock(p,sizeof(Item));}}__forceinline void*__cdecl operator new(Qhk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](Qhk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
__forceinline T*next()const{return(m_next);}
__forceinline T*&next(){return(m_next);}
__forceinline T*prev()const{return(m_pSecondNode);}
__forceinline T*&prev(){return(m_pSecondNode);}
public:
Item():BASE(){}
Item&operator=(const Item&){return(*this);}
protected:
Item(const Item&other):BASE(other){}
private:
T*m_next;
T*m_pSecondNode;
};
List():m_uiBufferCapacity(0),m_iAllocatedCount(0){}
inline ~List();
inline void reset();
inline T*allocate(const T&value=T());
inline void release(T*item);
inline void moveUp(T*item);
inline void moveDown(T*item);
__forceinline T*getFirst()const{return(m_uiBufferCapacity);}
__forceinline T*getLast()const{T*t=getFirst();if(t){while(t->next())t=t->next();}return(t);}
__forceinline int GetLogicalSize()const{return(m_iAllocatedCount);}
private:
List(const List&){}
void operator=(const List&){}
private:
ALLOCATOR m_pThreadAllocator;
T*m_uiBufferCapacity;
int m_iAllocatedCount;
QhkUint32 m_uiUniqueId;
};
template<typename VERTEX,typename BASE>
struct Vertex:List<VERTEX,BASE>::Item
{
typedef typename List<VERTEX,BASE>::Item tBase;
__forceinline void*__cdecl operator new(Qhk_size_t nbytes){;void*obj=Qmemrouter::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;Qmemrouter::GetMonitorStream().heap().ReleaseBlock(p,sizeof(Vertex));}}__forceinline void*__cdecl operator new(Qhk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](Qhk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
static __forceinline bool isOrdered(const VERTEX*a,const VERTEX*b)
{
const int c((*a).compare(*b));
;
if(c<0)return(true);
if(c>0)return(false);
return(true);
}
};
template<typename TRIANGLE,typename BASE,typename VERTEX>
struct Triangle:List<TRIANGLE,BASE>::Item
{
typedef typename List<TRIANGLE,BASE>::Item tBase;
typedef const VERTEX&vParm;
__forceinline void*__cdecl operator new(Qhk_size_t nbytes){;void*obj=Qmemrouter::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;Qmemrouter::GetMonitorStream().heap().ReleaseBlock(p,sizeof(Triangle));}}__forceinline void*__cdecl operator new(Qhk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](Qhk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
__forceinline void setVertices(vParm a,vParm b,vParm c){m_kVertices[0]=a;m_kVertices[1]=b;m_kVertices[2]=c;}
__forceinline bool hasReferences()const{return(0!=((link(0)|link(1)|link(2))>>2));}
__forceinline VERTEX vertex(int i)const{return(m_kVertices[i]);}
__forceinline VERTEX&vertex(int i){return(m_kVertices[i]);}
__forceinline Uid link(int i)const{return(m_ppLinks[i]);}
__forceinline Uid&link(int i){return(m_ppLinks[i]);}
private:
VERTEX m_kVertices[3];
Uid m_ppLinks[3];
};};
template<typename EDGE,typename VERTEX,typename TRIANGLE,typename ALLOCATOR=QhkContainerHeapAllocator>
class QhkgpAbstractMesh:public QhkReferencedObject
{
public:
__forceinline void*__cdecl operator new(Qhk_size_t nbytes){;QhkReferencedObject*b=static_cast<QhkReferencedObject*>(Qmemrouter::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<QhkUint16>(nbytes);;return b;}typedef QhkGeometryProcessing::DynamicMemoryAllocator<VERTEX,32,ALLOCATOR>VertexPoolAllocator;
typedef QhkGeometryProcessing::DynamicMemoryAllocator<TRIANGLE,32,ALLOCATOR>TrianglePoolAllocator;
typedef QhkgpAbstractMeshDefinitions::List<VERTEX,typename VERTEX::tBase,VertexPoolAllocator>VertexList;
typedef QhkgpAbstractMeshDefinitions::List<TRIANGLE,typename VERTEX::tBase,TrianglePoolAllocator>TriangleList;
VertexList m_kVertices;
TriangleList m_uiTriangleCount;};struct QhkgpMeshBase
{
struct NoFieldStruct{};
struct PlaceholderType{};
struct Vertex:QhkgpAbstractMeshDefinitions::Vertex<Vertex,NoFieldStruct>
{
QhkVector4 m_vContactPosition;
QhkVector4 m_vHitNormal;
QhkVector4 m_data;
int m_refs;
int m_ucOperationType;
__forceinline int compare(const Vertex&v)const{for(int i=0;i<3;i++){if(m_vContactPosition(i)<v.m_vContactPosition(i))return-1;if(m_vContactPosition(i)>v.m_vContactPosition(i))return 1;}return 0;}
};
struct Triangle:QhkgpAbstractMeshDefinitions::Triangle<Triangle,PlaceholderType,Vertex*>
{
QhkVector4 m_kTriangleNormal;
int m_iTriangleIndex;
int m_iTriangleValueAtOffset0x38;
int m_iMaterialIndex;
int m_ucOperationType;
QhkUint32 m_uiTriangleFlags;
};
struct Edge:QhkgpTopology::Edge<Edge,Vertex,Triangle,Vertex*>
{
Edge(){}
Edge(Triangle*t,unsigned i):QhkgpTopology::Edge<Edge,Vertex,Triangle,Vertex*>(t,i){}
Edge(const QhkgpTopology::Uid&id):QhkgpTopology::Edge<Edge,Vertex,Triangle,Vertex*>(id){}
};};
class QhkgpMesh:public QhkgpAbstractMesh<QhkgpMeshBase::Edge,QhkgpMeshBase::Vertex,QhkgpMeshBase::Triangle,QhkContainerHeapAllocator>
{
public:
struct IConvexOverlap
{
struct IConvexShape
{
virtual ~IConvexShape(){}
virtual int getMaxIndex()const{return 0;}
virtual void GetSupportPoint(const QhkVector4&d,QhkVector4&sv)const=0;
virtual QhkAabb GetAxisAlignedBounds()const=0;
};
};
struct LineShape:IConvexOverlap::IConvexShape
{
LineShape(const QhkVector4&a,const QhkVector4&b):m_kPointA(a),m_kPointB(b){m_kPointA.setInt24W(0);m_kPointB.setInt24W(1);}
virtual void GetSupportPoint(const QhkVector4&d,QhkVector4&sv)const{sv=(d.dot3(m_kPointA)>d.dot3(m_kPointB))? m_kPointA:m_kPointB;}
virtual QhkAabb GetAxisAlignedBounds()const{QhkAabb r;r.m_kMinimumCorner=m_kPointA;r.m_kMinimumCorner.setMin4(m_kPointA,m_kPointB);r.m_kMaximumCorner.setMax4(m_kPointA,m_kPointB);return r;}
QhkVector4 m_kPointA;
QhkVector4 m_kPointB;
};
QhkReal ProcessEntries_00e144d0(QhkReal d,const QhkVector4&p,QhkVector4&out,int mode)const throw();
bool TestShapeHit(IConvexOverlap::IConvexShape*s,QhkReal r,bool b)const throw();
void ProcessEntries_00e175b0(QhkReal offset,QhkArray<QhkVector4>&edgesOut)const;
};
// @fnv 0x00e175b0
// src: GUESS 0x00e175b0 (confidence: low)
void QhkgpMesh::ProcessEntries_00e175b0(QhkReal offset,QhkArray<QhkVector4>&edgesOut)const
{
const QhkReal offsetWarmup=offset*0.1f;
QhkArray<QhkVector4>vertices;
for(QhkgpMeshBase::Vertex*v=m_kVertices.getFirst();v;v=v->next())
{
QhkVector4 x;
x.setAddMul4(v->m_vContactPosition,v->m_vHitNormal,offsetWarmup);
const QhkReal sd=ProcessEntries_00e144d0(offset,v->m_vHitNormal,x,2);
if(sd>0)
{
x(3)=QhkMath::fabs(sd);
vertices.AddBack(x);
v->m_ucOperationType=vertices.GetLogicalSize()-1;
}
else
{
v->m_ucOperationType=-1;
}
}
for(QhkgpMeshBase::Triangle*t=m_uiTriangleCount.getFirst();t;t=t->next())
{
if(!t->m_kTriangleNormal.FUN_00c7f520(1e-4f))continue;
for(int i=0;i<3;i++)
{
QhkgpMeshBase::Edge e(t,i);
if(e.isMaster())
{
QhkVector4 normal=e.triangle()->m_kTriangleNormal;
if(e.isBound())
{
if(!e.link().triangle()->m_kTriangleNormal.FUN_00c7f520(1e-4f))continue;
if(e.triangle()->m_kTriangleNormal.dot3(e.link().triangle()->m_kTriangleNormal)>0.9999f)continue;
normal.add4(e.link().triangle()->m_kTriangleNormal);
QhkVector4 v0=e.start()->m_vContactPosition;
QhkVector4 v1=e.end()->m_vContactPosition;
QhkVector4 v2=e.apex()->m_vContactPosition;
QhkVector4 v3=e.link().apex()->m_vContactPosition;
if(QhkGeometryProcessing::tetrahedronVolume6(v0,v1,v2,v3)<1.192092896e-07F)continue;
}
if(normal.normalize3IfNotZero()==HK_SUCCESS)
{
if(e.start()->m_ucOperationType>=0&&e.end()->m_ucOperationType>=0)
{
const QhkVector4*a=&vertices[e.start()->m_ucOperationType];
const QhkVector4*b=&vertices[e.end()->m_ucOperationType];
LineShape line(*a,*b);
if(!TestShapeHit(&line,0.0f,true))
{
edgesOut.AddBack(*a);
edgesOut.AddBack(*b);
}
}
}
}
}
}
}

namespace fnv_00e1a7a0 {
inline void* __cdecl operator new(unsigned int, void* where) throw() { return where; }





hkMemoryRouter& hkMemoryRouter_getInstance() throw();
void ResizeAudioStream(hkMemoryAllocator& alloc, void* array, int elemSize) throw();

template <typename T>
struct S_00e1a7a0_ArrayLocalForm { // local form of hkArray: 0x00e1a7a0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~S_00e1a7a0_ArrayLocalForm() throw() { _clearAndDeallocate(hkMemoryRouter_getInstance().heap()); }

    int getCapacity() const throw() { return m_iCapacityState & 0x3fffffff; }
    int GetLogicalSize() const throw() { return m_iElementCount; }
    T& operator[](int i) throw() { return m_data[i]; }

    void _pushBack(hkMemoryAllocator& alloc, const T& t) throw()
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(alloc, this, sizeof(T));
        new (m_data + m_iElementCount) T(t);
        m_iElementCount++;
    }
    void AddBack(const T& t) throw() { _pushBack(hkMemoryRouter_getInstance().heap(), t); }

    void _clearAndDeallocate(hkMemoryAllocator& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

template <typename T, int N>
struct S_00e1a7a0_InplaceArray : S_00e1a7a0_ArrayLocalForm<T> {
    T m_kStorage[N];
    S_00e1a7a0_InplaceArray() throw()
    {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = N | 0x80000000;
    }
};



struct S_00e1a7a0_VertexData {
    Vec4 m_kPointA;
    Vec4 m_kPointB;
    Vec4 m_iThirdValue;
    int m_numRefs;
    int m_ucOperationType;
    S_00e1a7a0_VertexData& operator=(const S_00e1a7a0_VertexData& o) throw()
    {
        m_kPointA = o.m_kPointA;
        m_kPointB = o.m_kPointB;
        m_iThirdValue = o.m_iThirdValue;
        m_numRefs = o.m_numRefs;
        m_ucOperationType = o.m_ucOperationType;
        return *this;
    }
};

struct S_00e1a7a0_Vertex {
    S_00e1a7a0_Vertex* m_next;
    S_00e1a7a0_Vertex* m_pSecondNode;
    int unk8;
    int unkC;
    S_00e1a7a0_VertexData m_data;
    int unk48;
    int unk4C;
};

struct S_00e1a7a0_Triangle {
    S_00e1a7a0_Triangle* m_next;
    S_00e1a7a0_Triangle* m_pSecondNode;
    S_00e1a7a0_Vertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
};

struct S_00e1a7a0_Edge {
    S_00e1a7a0_Triangle* m_pkTriangle;
    int m_uiEdgeIndex;
    S_00e1a7a0_Edge() throw() {}
    S_00e1a7a0_Edge(S_00e1a7a0_Triangle* t, int i) throw() : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    unsigned int uid() const throw() { return (unsigned int)m_pkTriangle + m_uiEdgeIndex; }
    bool isValid() const throw() { return m_pkTriangle != 0; }
    S_00e1a7a0_Vertex*& start() const throw() { return m_pkTriangle->m_kVertices[m_uiEdgeIndex]; }
    S_00e1a7a0_Edge next() const throw() { return S_00e1a7a0_Edge(m_pkTriangle, (9 >> (m_uiEdgeIndex << 1)) & 3); }
    S_00e1a7a0_Edge prev() const throw() { return S_00e1a7a0_Edge(m_pkTriangle, (0x12 >> (m_uiEdgeIndex << 1)) & 3); }
    S_00e1a7a0_Edge link() const throw()
    {
        unsigned int l = m_pkTriangle->m_ppLinks[m_uiEdgeIndex];
        S_00e1a7a0_Edge e;
        e.m_uiEdgeIndex = l & 3;
        e.m_pkTriangle = (S_00e1a7a0_Triangle*)(l & ~3u);
        return e;
    }
};

struct S_00e1a7a0_Block {
    S_00e1a7a0_Vertex m_items[32];
    S_00e1a7a0_Vertex* m_free;
    int m_iAllocatedCount;
};

struct S_00e1a7a0_VertexList {
    S_00e1a7a0_ArrayLocalForm<S_00e1a7a0_Block*> m_kBlocks;
    S_00e1a7a0_Vertex* m_uiBufferCapacity;
    int m_iAllocatedCount;

    S_00e1a7a0_Block* AllocateChainedSlotBlock() throw();

    S_00e1a7a0_Vertex* allocate() throw()
    {
        S_00e1a7a0_Block* b;
        if (m_kBlocks.m_iElementCount == 0 || m_kBlocks.m_data[0]->m_free == 0)
            b = AllocateChainedSlotBlock();
        else
            b = m_kBlocks.m_data[0];
        S_00e1a7a0_Vertex* it = b->m_free;
        b->m_free = it->m_next;
        b->m_iAllocatedCount++;
        return it;
    }
    S_00e1a7a0_Vertex* append(const S_00e1a7a0_VertexData& d) throw()
    {
        S_00e1a7a0_Vertex* it = allocate();
        it->m_data = d;
        it->m_pSecondNode = 0;
        it->m_next = m_uiBufferCapacity;
        if (m_uiBufferCapacity)
            m_uiBufferCapacity->m_pSecondNode = it;
        m_iAllocatedCount++;
        m_uiBufferCapacity = it;
        return it;
    }
};

struct S_00e1a7a0_TriangleList {
    S_00e1a7a0_ArrayLocalForm<void*> m_kBlocks;
    S_00e1a7a0_Triangle* m_uiBufferCapacity;
    int m_iAllocatedCount;
};

struct S_00e1a7a0_Ostream {
    void* vtbl;
    int unk04;
    void* m_pStreamWriter;
    void FUN_00cb1600(void* buf, int size) throw();
    S_00e1a7a0_Ostream& ProcessAndReturnValue_00cc01c0(const char* s) throw();
    S_00e1a7a0_Ostream& WriteInt(int i) throw();
    void FUN_00cc00e0() throw();
};

struct S_00e1a7a0_Error {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int type, int id, const char* desc, const char* file, int line);
};
extern S_00e1a7a0_Error* DAT_01268360;

struct S_00e1a7a0_Mesh {
    int unk0;
    int unk4;
    S_00e1a7a0_VertexList m_kVertices;
    int unk1C;
    S_00e1a7a0_TriangleList m_uiTriangleCount;
    int hkgpMesh_removeButterflies(int tag);
};

// Splits "butterfly" vertices: a vertex whose triangle fan around it does not cover all its references
// gets a copy for each separate fan. Returns the number of vertices split.
// Counts triangle references per vertex, splits vertices whose edge fan is smaller than their reference count into new vertices, and logs the split count.
// @fnv 0x00e1a7a0
// src: HAVOK_LIB 0x00e1a7a0
int S_00e1a7a0_Mesh::hkgpMesh_removeButterflies(int aiOperationType)
{
    int numSplits = 0;
    for (S_00e1a7a0_Vertex* v = m_kVertices.m_uiBufferCapacity; v; v = v->m_next)
        v->m_data.m_numRefs = 0;
    for (S_00e1a7a0_Triangle* t = m_uiTriangleCount.m_uiBufferCapacity; t; t = t->m_next) {
        t->m_kVertices[0]->m_data.m_numRefs++;
        t->m_kVertices[1]->m_data.m_numRefs++;
        t->m_kVertices[2]->m_data.m_numRefs++;
    }
    for (S_00e1a7a0_Triangle* t = m_uiTriangleCount.m_uiBufferCapacity; t; t = t->m_next) {
        for (int i = 0; i < 3; i++) {
            S_00e1a7a0_Edge start(t, i);
            S_00e1a7a0_Vertex* v = start.start();
            S_00e1a7a0_InplaceArray<S_00e1a7a0_Edge, 16> fan;
            S_00e1a7a0_Edge e = start;
            do {
                fan.AddBack(e);
                e = e.prev().link();
            } while (e.isValid() && e.uid() != start.uid());
            if (!e.isValid()) {
                for (e = start.link().next(); e.isValid(); e = e.link().next())
                    fan.AddBack(e);
            }
            if (fan.GetLogicalSize() < v->m_data.m_numRefs) {
                S_00e1a7a0_Vertex* nv = m_kVertices.append(v->m_data);
                v->m_data.m_numRefs -= fan.GetLogicalSize();
                v->m_data.m_ucOperationType = aiOperationType;
                nv->m_data.m_numRefs = fan.GetLogicalSize();
                nv->m_data.m_ucOperationType = aiOperationType;
                for (int k = 0; k < fan.GetLogicalSize(); k++)
                    fan[k].start() = nv;
                numSplits++;
            }
        }
    }
    if (numSplits) {
        unsigned int buf[128]; // 512-byte text buffer (not char: the original has no GS cookie)
        S_00e1a7a0_Ostream ostr;
        ostr.FUN_00cb1600(buf, sizeof(buf));
        ostr.ProcessAndReturnValue_00cc01c0("Butterflies found: ").WriteInt(numSplits);
        DAT_01268360->message(0, -1, (const char*)buf, ".\\GeometryProcessing\\Mesh\\hkgpMesh.cpp", 0xb0d);
        ostr.FUN_00cc00e0();
    }
    return numSplits;
}
}  // namespace fnv_00e1a7a0

extern "C" __m128 _mm_load_ss(const float*); 
extern "C" __m128 _mm_sub_ps(__m128,__m128);
extern "C" __m128 _mm_set_ps1(float);
// hkVector4 stand-in: four floats, SIMD access through a reinterpret cast

// Migration blocked: shared vector copy/constructor declarations change 0x00e1ce10.
struct __declspec(align(16)) S_e1ce10_Vec4 {
    float x, y, z, w;
    __m128& q() { return *reinterpret_cast<__m128*>(this); }
    const __m128& q() const { return *reinterpret_cast<const __m128*>(this); }
    __forceinline void SetAllComponents(float a) { q() = _mm_set_ps1(a); }
    __forceinline void setSub4(const S_e1ce10_Vec4& a, const S_e1ce10_Vec4& b) { q() = _mm_sub_ps(a.q(), b.q()); }
    __forceinline void setAdd4(const S_e1ce10_Vec4& a, const S_e1ce10_Vec4& b) { q() = _mm_add_ps(a.q(), b.q()); }
    __forceinline float& operator()(int i) { return (&x)[i]; }
    void setTransformedPos_00c7f640(const struct S_e1ce10_Transform& transform, const S_e1ce10_Vec4& p) throw();
};
struct S_e1ce10_Bool {
    char m_cBooleanValue;
    S_e1ce10_Bool() {}
    operator bool() const { return m_cBooleanValue != 0; }
};
struct S_e1ce10_Plane : S_e1ce10_Vec4 {
    S_e1ce10_Bool FUN_00c7f520(float eps) const throw();
};
struct S_e1ce10_Aabb {
    S_e1ce10_Vec4 m_kMinimumCorner;
    S_e1ce10_Vec4 m_kMaximumCorner;
};
__forceinline void S_e1ce10_calcAabb(const S_e1ce10_Vec4& center, float innerRadius, S_e1ce10_Aabb& aabb)
{
    S_e1ce10_Vec4 extv;
    extv.SetAllComponents(innerRadius);
    aabb.m_kMinimumCorner.q() = _mm_sub_ps(center.q(), extv.q());
    aabb.m_kMinimumCorner.w = 0.0f;
    aabb.m_kMaximumCorner.q() = _mm_add_ps(center.q(), extv.q());
    aabb.m_kMaximumCorner.w = 0.0f;
}
// memory router / heap
void __cdecl hkArrayUtil__reserve(void* alloc, void* arr, int numElem, int sizeElem) throw(); // GrowArrayCapacity
void __cdecl ResizeAudioStream(void* alloc, void* arr, int sizeElem) throw(); // GrowArray
struct S_e1ce10_Pod {};
struct S_e1ce10_Class {};
template <class T> struct S_e1ce10_IsPod { typedef S_e1ce10_Class type; };
template <class T> struct S_e1ce10_IsPod<T*> { typedef S_e1ce10_Pod type; };
struct S_e1ce10_ArrayUtil {
    template <class T> static __forceinline void construct(T* t, int n, S_e1ce10_Pod) throw() {}
    template <class T> static __forceinline void construct(T* t, int n, S_e1ce10_Class) throw()
    {
        for (int i = 0; i < n; ++i)
            ::new (reinterpret_cast<void*>(t + i)) T;
    }
    template <class T> static __forceinline void constructWithCopy(T* t, int n, const T& tcopy, S_e1ce10_Pod) throw()
    {
        for (int i = 0; i < n; ++i)
            t[i] = tcopy;
    }
    template <class T> static __forceinline void destruct(T* t, int n, S_e1ce10_Pod) throw() {}
    template <class T> static __forceinline void destruct(T* t, int n, S_e1ce10_Class) throw()
    {
        for (int i = 0; i < n; ++i)
            static_cast<T*>(t)[i].~T();
    }
};
template <class T> struct S_e1ce10_ArrayLocalForm { // local form of hkArray: 0x00e1ce10 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_e1ce10_ArrayLocalForm() throw() : m_data(0), m_iElementCount(0), m_iCapacityState((int)0x80000000) {}
    __forceinline ~S_e1ce10_ArrayLocalForm() throw() { _clearAndDeallocate(meshHeap(hkMemoryRouter_getInstance())); }
    int GetLogicalSize() const { return m_iElementCount; }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    T& operator[](int i) { return m_data[i]; }
    const T& operator[](int i) const { return m_data[i]; }
    __forceinline void clear() throw()
    {
        S_e1ce10_ArrayUtil::destruct(m_data, m_iElementCount, typename S_e1ce10_IsPod<T>::type());
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(Allocator& alloc) throw()
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.freeBlock(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = (int)0x80000000;
    }
    __forceinline void GrowArrayCapacity(Allocator& alloc, int n) throw()
    {
        const int capacity = getCapacity();
        if (capacity < n) {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(Allocator& alloc, int n) throw()
    {
        GrowArrayCapacity(alloc, n);
        S_e1ce10_ArrayUtil::destruct(m_data + n, m_iElementCount - n, typename S_e1ce10_IsPod<T>::type());
        S_e1ce10_ArrayUtil::construct(m_data + m_iElementCount, n - m_iElementCount, typename S_e1ce10_IsPod<T>::type());
        m_iElementCount = n;
    }
    __forceinline void _setSize(Allocator& alloc, int n, const T& fill) throw()
    {
        GrowArrayCapacity(alloc, n);
        S_e1ce10_ArrayUtil::destruct(m_data + n, m_iElementCount - n, typename S_e1ce10_IsPod<T>::type());
        S_e1ce10_ArrayUtil::constructWithCopy(m_data + m_iElementCount, n - m_iElementCount, fill, typename S_e1ce10_IsPod<T>::type());
        m_iElementCount = n;
    }
    __forceinline void SetSizeAndGrow(int n) throw() { _setSize(meshHeap(hkMemoryRouter_getInstance()), n); }
    __forceinline void SetSizeAndGrow(int n, const T& fill) throw() { _setSize(meshHeap(hkMemoryRouter_getInstance()), n, fill); }
    __forceinline T& _expandOne(Allocator& alloc) throw()
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(T));
        S_e1ce10_ArrayUtil::construct(m_data + m_iElementCount, 1, typename S_e1ce10_IsPod<T>::type());
        return m_data[m_iElementCount++];
    }
    __forceinline T& AllocatePair() throw() { return _expandOne(meshHeap(hkMemoryRouter_getInstance())); }
    __forceinline void _pushBack(Allocator& alloc, const T& t) throw()
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(T));
        S_e1ce10_ArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, t, typename S_e1ce10_IsPod<T>::type());
        m_iElementCount++;
    }
    __forceinline void AddBack(const T& t) throw() { _pushBack(meshHeap(hkMemoryRouter_getInstance()), t); }
    __forceinline int indexOf(const T& t, int startIdx = 0, int endIdx = -1) const throw()
    {
        if (endIdx < 0)
            endIdx = m_iElementCount;
        for (int i = startIdx; i < endIdx; ++i) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};
// geometry input


struct S_e1ce10_Transform {
    S_e1ce10_Vec4 m_qRotation0;
};
// mesh elements (pool items: next/prev links, then the value)
template <class T> struct S_e1ce10_Item {
    T* m_next;
    T* m_pSecondNode;
    S_e1ce10_Item() {}
    S_e1ce10_Item(const S_e1ce10_Item&) {}
    S_e1ce10_Item& operator=(const S_e1ce10_Item&) { return *this; }
};
struct S_e1ce10_Triangle;
struct S_e1ce10_Vertex : S_e1ce10_Item<S_e1ce10_Vertex> {
    S_e1ce10_Vec4 m_vContactPosition;
    S_e1ce10_Vec4 m_20;
    S_e1ce10_Vec4 m_30;
    int m_40;
    int m_44;
    S_e1ce10_Vertex() : m_40(-1), m_44(-1) {}
};
struct S_e1ce10_TriangleBase : S_e1ce10_Item<S_e1ce10_Triangle> {
    S_e1ce10_Vertex* m_kVertices[3];
    unsigned int m_ppLinks[3]; // triangle pointer + edge index
    __forceinline void setVertices(S_e1ce10_Vertex* const& a, S_e1ce10_Vertex* const& b, S_e1ce10_Vertex* const& c) { m_kVertices[0] = a; m_kVertices[1] = b; m_kVertices[2] = c; }
    __forceinline S_e1ce10_Vertex*& vertex(int i) { return m_kVertices[i]; }
    __forceinline unsigned int& link(int i) { return m_ppLinks[i]; }
};
struct S_e1ce10_Triangle : S_e1ce10_TriangleBase {
    S_e1ce10_Vec4 m_kTriangleNormal;
    int m_iMaterialIndex;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    S_e1ce10_Triangle() {}
};
// fixed-size pool blocks (0x50-byte slots)
struct S_e1ce10_PoolBase {
    void* AllocateChainedSlotBlock() throw(); // allocate a new block
    void hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(void* item) throw();   // release an item
};
template <class T> struct S_e1ce10_PoolItem { unsigned char m_data[sizeof(T)]; };
template <class T> struct S_e1ce10_Block {
    S_e1ce10_PoolItem<T> m_items[32];
    S_e1ce10_PoolItem<T>* m_free;
    int m_uiBufferCapacity;
};
template <class T> struct S_e1ce10_PoolAllocator : S_e1ce10_PoolBase {
    S_e1ce10_Block<T>** m_kBlocks;
    int m_iBlockCount;
    int m_blocksCapacity;
    __forceinline S_e1ce10_PoolItem<T>* allocateItem() throw()
    {
        S_e1ce10_Block<T>* pool = (m_iBlockCount && m_kBlocks[0]->m_free) ? m_kBlocks[0] : (S_e1ce10_Block<T>*)AllocateChainedSlotBlock();
        S_e1ce10_PoolItem<T>* item = pool->m_free;
        pool->m_free = *(S_e1ce10_PoolItem<T>**)item;
        ++pool->m_uiBufferCapacity;
        return item;
    }
    __forceinline T* allocate(const T& value) throw() { return new (allocateItem()) T(value); }
};
template <class T> struct S_e1ce10_List {
    S_e1ce10_PoolAllocator<T> m_pThreadAllocator;
    T* m_pFirstNode;
    int m_uiItemCount;
    __forceinline T* allocate(const T& value = T()) throw()
    {
        T* item = m_pThreadAllocator.allocate(value);
        item->m_pSecondNode = 0;
        item->m_next = m_pFirstNode;
        if (m_pFirstNode)
            m_pFirstNode->m_pSecondNode = item;
        m_pFirstNode = item;
        m_uiItemCount++;
        return item;
    }
    __forceinline void release(T* item) throw()
    {
        T* next = item->m_next;
        T* prev = item->m_pSecondNode;
        if (next)
            next->m_pSecondNode = prev;
        if (prev)
            prev->m_next = next;
        else
            m_pFirstNode = next;
        m_uiItemCount--;
        m_pThreadAllocator.hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(item);
    }
};
// edge hash
__forceinline unsigned long S_e1ce10_uid2ulong(void* t, unsigned int i) { return (*(const unsigned long*)&t) + (unsigned long)i; }
__forceinline unsigned long S_e1ce10_packUid(void* t, unsigned int i) { return S_e1ce10_uid2ulong(t, i); }
template <class T> __forceinline void S_e1ce10_ulong2uid(unsigned long uid, T*& t, unsigned int& i) { i = (unsigned int)(uid & 3); uid &= ~3; t = *(T**)&uid; }
template <class T> __forceinline void S_e1ce10_unpackUid(unsigned long uid, T*& t, unsigned int& i) { S_e1ce10_ulong2uid(uid, t, i); }
struct S_e1ce10_Link {
    S_e1ce10_Triangle* m_pkTriangle;
    unsigned int m_uiEdgeIndex;
    __forceinline S_e1ce10_Link(S_e1ce10_Triangle* t, unsigned int i) : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    static __forceinline const S_e1ce10_Link& null()
    {
        static const S_e1ce10_Link s_null(0, 0);
        return s_null;
    }
    __forceinline unsigned long uid() const { return S_e1ce10_packUid(m_pkTriangle, m_uiEdgeIndex); }
    __forceinline S_e1ce10_Triangle* triangle() const { return m_pkTriangle; }
    __forceinline bool isValid() const { return triangle() != 0; }
    __forceinline void bind(const S_e1ce10_Link& edge) const;
    __forceinline S_e1ce10_Link(const unsigned int& id) { S_e1ce10_unpackUid(id, m_pkTriangle, m_uiEdgeIndex); }
    __forceinline S_e1ce10_Link link() const;
    __forceinline bool isNaked() const { return !link().isValid(); }
    __forceinline void unbind() const;
};
__forceinline void S_e1ce10_Link::bind(const S_e1ce10_Link& edge) const
{
    m_pkTriangle->link(m_uiEdgeIndex) = edge.uid();
    if (edge.isValid())
        edge.m_pkTriangle->link(edge.m_uiEdgeIndex) = uid();
}
__forceinline S_e1ce10_Link S_e1ce10_Link::link() const { return S_e1ce10_Link(m_pkTriangle->link(m_uiEdgeIndex)); }
__forceinline void S_e1ce10_Link::unbind() const
{
    if (!isNaked()) {
        S_e1ce10_Link l = link();
        l.m_pkTriangle->link(l.m_uiEdgeIndex) = 0;
    }
    m_pkTriangle->link(m_uiEdgeIndex) = 0;
}
template <typename T> __forceinline void S_e1ce10_swap(T& x, T& y)
{
    T t = x;
    x = y;
    y = t;
}
struct S_e1ce10_Edge {
    S_e1ce10_Vertex* m_kPointA;
    S_e1ce10_Vertex* m_kPointB;
    S_e1ce10_Link m_kEdge;
    int m_uiItemCount;
    S_e1ce10_Edge() : m_kPointA(0), m_kPointB(0), m_kEdge(0, 0), m_uiItemCount(0) {}
    S_e1ce10_Edge(S_e1ce10_Vertex* a, S_e1ce10_Vertex* b) : m_kPointA(a), m_kPointB(b), m_kEdge(0, 0) { m_uiItemCount = 0; }
    static __forceinline int hashOf(const S_e1ce10_Edge& e)
    {
        int a = (int)e.m_kPointA;
        int b = (int)e.m_kPointB;
        if (a > b) S_e1ce10_swap(a, b);
        return ((a * 45564901) ^ (b * 95564881)) % 5564887;
    }
    __forceinline int hash() const
    {
        return hashOf(*this);
    }
    __forceinline bool operator==(const S_e1ce10_Edge& e) const
    {
        return (e.m_kPointA == m_kPointA && e.m_kPointB == m_kPointB) || (e.m_kPointA == m_kPointB && e.m_kPointB == m_kPointA);
    }
};
struct S_e1ce10_EdgeHash {
    S_e1ce10_ArrayLocalForm< S_e1ce10_ArrayLocalForm<S_e1ce10_Edge> > m_buckets;
    int m_numItems;
    S_e1ce10_EdgeHash() throw() : m_numItems(0) {}
    __forceinline ~S_e1ce10_EdgeHash() throw() {}
    __forceinline void clear() throw() { m_buckets.clear(); m_numItems = 0; }
    __forceinline void setBucketsCount(int size) throw()
    {
        clear();
        m_buckets.SetSizeAndGrow(size);
        for (int i = 0; i < size; ++i)
            m_buckets[i].clear();
    }
    __forceinline S_e1ce10_ArrayLocalForm<S_e1ce10_Edge>& lookupBucket(int hash) throw()
    {
        const unsigned idx = ((unsigned)hash) % m_buckets.GetLogicalSize();
        return m_buckets[idx];
    }
    __forceinline S_e1ce10_Edge* find(int hash, const S_e1ce10_Edge& value) throw()
    {
        S_e1ce10_ArrayLocalForm<S_e1ce10_Edge>& values = lookupBucket(hash);
        const int index = values.indexOf(value);
        if (index == -1)
            return 0;
        else
            return &values[index];
    }
    __forceinline S_e1ce10_Edge* insert(int hash, const S_e1ce10_Edge& value) throw()
    {
        ++m_numItems;
        S_e1ce10_ArrayLocalForm<S_e1ce10_Edge>& values = lookupBucket(hash);
        values.AllocatePair() = value;
        return &values[values.GetLogicalSize() - 1];
    }
};
// broadphase tree used to weld vertices
struct S_e1ce10_TreeNodes {
    int unk00;
    ~S_e1ce10_TreeNodes() throw(); // FUN_00d9c010
};
struct S_e1ce10_Tree {
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S_e1ce10_TreeNodes m_1c;
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
    S_e1ce10_Tree() throw(); // FUN_00d9c110
    virtual void v00() throw();
    ~S_e1ce10_Tree() throw() { UpdateState_00d9be30(); }
    void UpdateState_00d9be30() throw();
    void UpdateState_00d9d110(const S_e1ce10_Aabb& aabb, S_e1ce10_Vertex* item) throw(); // insert
};
struct S_e1ce10_Collector {
    virtual void v00() throw();
    S_e1ce10_Vec4 m_vContactPosition;
    float m_radiusSquared;
    S_e1ce10_Vertex* m_closest;
    S_e1ce10_Collector(const S_e1ce10_Vec4& p, float radius) throw()
        : m_vContactPosition(p), m_radiusSquared(radius * radius), m_closest(0) {}
};
void __cdecl AabbTree_ProcessIfPresent_00d1d570(S_e1ce10_Tree* tree, const S_e1ce10_Aabb* aabb, S_e1ce10_Collector* collector) throw();
// report stream / error
struct S_e1ce10_Ostream {
    int unk00;
    int unk04;
    int unk08;
    S_e1ce10_Ostream(void* buf, int size) throw();   // FUN_00cb1600
    ~S_e1ce10_Ostream() throw();                      // FUN_00cc00e0
    S_e1ce10_Ostream& operator<<(const char* s) throw(); // FUN_00cc01c0
    S_e1ce10_Ostream& operator<<(int i) throw();         // FUN_00cc0280
};
struct S_e1ce10_Error {
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual int message(int type, int id, const char* desc, const char* file, int line) throw();
};
template <class T> struct S_e1ce10_PadSpu {
    T m_kStorage;
    T val() const { return m_kStorage; }
    T operator->() const { return m_kStorage; }
};
struct S_e1ce10_Mesh {
    int unk00;
    int unk04;
    S_e1ce10_List<S_e1ce10_Vertex> m_kVertices;
    int unk1c;
    S_e1ce10_List<S_e1ce10_Triangle> m_uiTriangleCount;
    int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58;
    int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80;
    int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8;
    int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0;
    int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8;
    int unkfc; int unk100; int unk104; int unk108;
    float m_weldTolerance;
    void hkgpMesh_appendFromGeometry(const hkGeometry& geom, const S_e1ce10_Transform& transform, int material) throw();
    void UpdateState_00e11510(const S_e1ce10_Vec4& a, const S_e1ce10_Vec4& b) throw(); // non-manifold edge
    void SetFlag100_00e11520(const S_e1ce10_Vec4& a, const S_e1ce10_Vec4& b) throw(); // bad orientation
    __declspec(noalias) void ValidateTriangleAndComputePlane(const S_e1ce10_Vec4* a, const S_e1ce10_Vec4* b, const S_e1ce10_Vec4* c, S_e1ce10_Vec4* plane, int normalize) throw();
    bool hkgpMesh_setPlane(S_e1ce10_Triangle* t, S_e1ce10_Plane* plane, int normalize) throw();
    void hkgpMesh_removeOrphanVertices() throw();
    void ReleaseSubobject() throw();
};
// Welds and transforms geometry vertices, builds triangles with edge links, removes degenerate triangles, and finalizes the mesh.
// @fnv 0x00e1ce10
// src: COMMUNITY 0x00e1ce10
void S_e1ce10_Mesh::hkgpMesh_appendFromGeometry(const hkGeometry& geom, const S_e1ce10_Transform& transform, int material) throw()
{
    S_e1ce10_ArrayLocalForm<S_e1ce10_Vertex*> vertexMap;
    S_e1ce10_Tree tree;
    S_e1ce10_EdgeHash edges;
    vertexMap.SetSizeAndGrow(reinterpret_cast<const S_e1ce10_ArrayLocalForm<S_e1ce10_Vec4>&>(geom.m_kVertices).GetLogicalSize(), 0);
    edges.setBucketsCount(0x2000);
    int numVertices = reinterpret_cast<const S_e1ce10_ArrayLocalForm<S_e1ce10_Vec4>&>(geom.m_kVertices).GetLogicalSize();
    for (int i = 0; i < numVertices; i++) {
        S_e1ce10_Vec4 v;
        reinterpret_cast<hkVector4&>(v).setTransformedPos_00c7f640(reinterpret_cast<const hkTransform&>(transform), reinterpret_cast<const hkVector4*>(reinterpret_cast<const S_e1ce10_ArrayLocalForm<S_e1ce10_Vec4>&>(geom.m_kVertices).m_data)[i]);
        S_e1ce10_Collector collector(v, m_weldTolerance);
        S_e1ce10_Aabb aabb;
        S_e1ce10_calcAabb(v, m_weldTolerance, aabb);
        AabbTree_ProcessIfPresent_00d1d570(&tree, &aabb, &collector);
        if (collector.m_closest) {
            vertexMap[i] = collector.m_closest;
        } else {
            S_e1ce10_Vertex* nv = m_kVertices.allocate();
            nv->m_vContactPosition.q() = v.q();
            nv->m_30.q() = reinterpret_cast<const S_e1ce10_Vec4*>(&DAT_01267e30)->q();
            vertexMap[i] = nv;
            tree.UpdateState_00d9d110(aabb, nv);
        }
    }
    for (int t = 0; t < reinterpret_cast<const S_e1ce10_ArrayLocalForm<hkGeometry::Triangle>&>(geom.m_uiTriangleCount).GetLogicalSize(); t++) {

        S_e1ce10_Vertex* vs[3];
        vs[0] = vertexMap[reinterpret_cast<const S_e1ce10_ArrayLocalForm<hkGeometry::Triangle>&>(geom.m_uiTriangleCount)[t].m_kPointA];
        vs[1] = vertexMap[reinterpret_cast<const S_e1ce10_ArrayLocalForm<hkGeometry::Triangle>&>(geom.m_uiTriangleCount)[t].m_kPointB];
        vs[2] = vertexMap[reinterpret_cast<const S_e1ce10_ArrayLocalForm<hkGeometry::Triangle>&>(geom.m_uiTriangleCount)[t].m_iThirdValue];
        if (vs[0] == vs[1] || vs[1] == vs[2] || vs[2] == vs[0])
            continue;
        S_e1ce10_Triangle* tri;
        {
        S_e1ce10_Vec4 p[3];
        p[0] = vs[0]->m_vContactPosition;
        p[1] = vs[1]->m_vContactPosition;
        p[2] = vs[2]->m_vContactPosition;
        tri = m_uiTriangleCount.allocate();
        tri->m_iMaterialIndex = material;
        tri->m_ppLinks[0] = 0;
        tri->m_ppLinks[1] = 0;
        tri->m_ppLinks[2] = 0;
        tri->m_38 = reinterpret_cast<const S_e1ce10_ArrayLocalForm<hkGeometry::Triangle>&>(geom.m_uiTriangleCount)[t].m_iMaterialIndex;
        tri->setVertices(vs[0], vs[1], vs[2]);
        ValidateTriangleAndComputePlane(&p[0], &p[1], &p[2], &tri->m_kTriangleNormal, 1);
        }
        for (int i = 2, j = 0; j < 3; i = j++) {
            S_e1ce10_Edge key(tri->vertex(i), tri->vertex(j));
            S_e1ce10_Edge* e = edges.find(key.hash(), key);
            if (!e)
                e = edges.insert(key.hash(), key);
            switch (++e->m_uiItemCount) {
            case 1:
                e->m_kEdge = S_e1ce10_Link(tri, i);
                break;
            case 2:
                if (key.m_kPointA == e->m_kPointB && key.m_kPointB == e->m_kPointA) {
                    S_e1ce10_Link(tri, i).bind(e->m_kEdge);
                    e->m_kEdge = S_e1ce10_Link::null();
                } else {
                    SetFlag100_00e11520(key.m_kPointA->m_vContactPosition, key.m_kPointB->m_vContactPosition);
                }
                break;
            default:
                UpdateState_00e11510(key.m_kPointA->m_vContactPosition, key.m_kPointB->m_vContactPosition);
                break;
            }
        }
    }
    S_e1ce10_ArrayLocalForm<S_e1ce10_Triangle*> invalid;
    for (S_e1ce10_Triangle* t = m_uiTriangleCount.m_pFirstNode; t; t = t->m_next) {
        S_e1ce10_Plane plane;
        if (!hkgpMesh_setPlane(t, &plane, 1) || !plane.FUN_00c7f520(1e-4f))
            invalid.AddBack(t);
    }
    if (invalid.GetLogicalSize()) {
        unsigned int reportBuf[128];
        S_e1ce10_Ostream ostr(reportBuf, sizeof(reportBuf));
        ostr << "Removing " << invalid.GetLogicalSize() << " invalid triangles";
        DAT_01268360->Report(0, (unsigned int)-1, (const char*)reportBuf, ".\\GeometryProcessing\\Mesh\\hkgpMesh.cpp", 0x695);
    }
    for (int i = 0; i < invalid.GetLogicalSize(); i++) {
        S_e1ce10_Link(invalid[i], 0).unbind();
        S_e1ce10_Link(invalid[i], 1).unbind();
        S_e1ce10_Link(invalid[i], 2).unbind();
    }
    for (int i = 0; i < invalid.GetLogicalSize(); i++)
        m_uiTriangleCount.release(invalid[i]);
    hkgpMesh_removeOrphanVertices();
    ReleaseSubobject();
}

extern "C" void _ReadBarrier();


extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_andnot_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_cmpeq_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ps1(const float* p);
extern "C" __m128 _mm_set_ps1(float a);
extern "C" __m128 _mm_load_ss(const float* p);
extern "C" __m128 _mm_max_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_min_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_rsqrt_ss(__m128 a);
extern "C" __m128 _mm_set_ss(float a);
extern "C" __m128 _mm_setr_ps(float a, float b, float c, float d);
extern "C" __m128 _mm_setzero_ps(void);

struct __declspec(align(16)) LocalVec4 {
    union { struct { float x,y,z,w; }; __m128 quad; }; LocalVec4& operator=(const LocalVec4& b) {quad=b.quad;return *this;}
};

struct CapVertex {
    int unk00; int unk04; int unk08; int unk0c;
    LocalVec4 position;
    int unk20; int unk24; int unk28; int unk2c;
    float weight;
};
struct PtObj {
    void hkVector4_setRotatedDir(void *dst, void *src);
};

struct AllocCtx {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Dealloc(void *p, int size);
    virtual void Slot0c();
    virtual void FreeBuf(void *p, int size);
};
struct AllocSvc {
    int unk_00_000;     int unk_00_004;     int unk_00_008;     int unk_00_00c;
    AllocCtx *m_10;
};


__forceinline AllocSvc* capMemory() {return (AllocSvc*)&hkMemoryRouter_getInstance();}

struct SubArr {
    void *m_pData;
    int m_iArrayLength;
    int m_iCap;
};

struct GridTag {};
template<class Payload> struct GridLinks:Payload {int next,prev;__forceinline GridLinks(){} __forceinline GridLinks(const GridLinks& b):Payload(b){} __forceinline GridLinks& operator=(const GridLinks&){return *this;}};
struct GridCore:GridLinks<GridTag> {};
struct RecPoint : GridCore {
int x,y;unsigned long constraint:1; unsigned long data:31;
};
struct Rec {
    int m_00;
    int m_04;
    int unk_08_008;
    int unk_08_00c;
    LocalVec4 projected;
    RecPoint point;
};

extern float DAT_01012054;
extern const float DAT_01012068;
extern double DAT_01011588;

__forceinline __m128 NormalizeVector3(__m128 value) {
    __m128 square = _mm_mul_ps(value, value);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(square, square, 0x55), square);
    sum = _mm_add_ss(_mm_shuffle_ps(square, square, 0xaa), sum);
    __m128 estimate = _mm_rsqrt_ss(sum);
    __m128 product = _mm_mul_ss(_mm_mul_ss(sum, estimate), estimate);
    __m128 correction = _mm_sub_ss(_mm_set_ss(3.0f), product);
    __m128 scale = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), estimate), correction);
    scale = _mm_andnot_ps(_mm_cmpeq_ss(sum, _mm_set_ss(0.0f)), scale);
    return _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), value);
}


__forceinline void NormalizeInPlace(LocalVec4& v) { v.quad=NormalizeVector3(v.quad); }
__forceinline void SetCross(LocalVec4& out,const LocalVec4& a,const LocalVec4& b) {
    __m128 ad=_mm_shuffle_ps(a.quad,a.quad,0xd2);
    __m128 ac=_mm_shuffle_ps(a.quad,a.quad,0xc9);
    __m128 bd=_mm_shuffle_ps(b.quad,b.quad,0xd2);
    __m128 bc=_mm_shuffle_ps(b.quad,b.quad,0xc9);
    out.quad=_mm_sub_ps(_mm_mul_ps(ac,bd),_mm_mul_ps(ad,bc));
}

struct SubObj10 {
    int unk_00_000;     int unk_00_004;     int unk_00_008;     int unk_00_00c;     int unk_00_010;     int unk_00_014;
    void ProcessEntries();
    void ClearAndFreeItems();
};
struct Int3;
struct SubObj28 {
    int unk_00_000;
    int unk_00_004;
    int unk_00_008;
    void *m_0chead;
    int unk_10_010;
    int unk_10_014;
    void hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_reset();
    void ProcessEntries_00e23d70();
    Int3 hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_insertVertex(int a, int b, int flag, void *tmp, int z);
};
struct Obj470 {
    SubArr m_aiIndexedValues;
    void FUN_00e23c70();
};
struct PartsMap {
    int data,size,mask;
    __forceinline PartsMap():data(0),size(0),mask(-1) {reserve(0);}
    void EnsureCapacity(Allocator*,int);
    unsigned long LookupHashEntry(unsigned long,unsigned long) const;
    int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(Allocator*,unsigned long,unsigned long);
    void ProcessArgument(Allocator*);
    void Object_DoNothing();
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(int);
    __forceinline void reserve(int n) {EnsureCapacity(&meshHeap(hkMemoryRouter_getInstance()),n);}
};
struct PoolObj {
    int unk_00_000;     int unk_00_004;     int unk_00_008;     int unk_00_00c;     int unk_00_010;     int unk_00_014;
    int unk_00_018;     int unk_00_01c;     int unk_00_020;     int unk_00_024;     int unk_00_028;     int unk_00_02c;
    int unk_00_030;     int unk_00_034;     int unk_00_038;     int unk_00_03c;     int unk_00_040;     int unk_00_044;
    int unk_00_048;     int unk_00_04c;     int unk_00_050;     int unk_00_054;     int unk_00_058;     int unk_00_05c;
    int unk_00_060;     int unk_00_064;     int unk_00_068;     int unk_00_06c;     int unk_00_070;     int unk_00_074;
    int unk_00_078;     int unk_00_07c;     int unk_00_080;     int unk_00_084;     int unk_00_088;     int unk_00_08c;
    int unk_00_090;     int unk_00_094;     int unk_00_098;     int unk_00_09c;     int unk_00_0a0;     int unk_00_0a4;
    int unk_00_0a8;     int unk_00_0ac;     int unk_00_0b0;     int unk_00_0b4;     int unk_00_0b8;     int unk_00_0bc;
    int unk_00_0c0;     int unk_00_0c4;     int unk_00_0c8;     int unk_00_0cc;     int unk_00_0d0;     int unk_00_0d4;
    int unk_00_0d8;     int unk_00_0dc;     int unk_00_0e0;     int unk_00_0e4;     int unk_00_0e8;     int unk_00_0ec;
    int unk_00_0f0;     int unk_00_0f4;     int unk_00_0f8;     int unk_00_0fc;     int unk_00_100;     int unk_00_104;
    int unk_00_108;     int unk_00_10c;     int unk_00_110;     int unk_00_114;     int unk_00_118;     int unk_00_11c;
    int unk_00_120;     int unk_00_124;     int unk_00_128;     int unk_00_12c;     int unk_00_130;     int unk_00_134;
    int unk_00_138;     int unk_00_13c;     int unk_00_140;     int unk_00_144;     int unk_00_148;     int unk_00_14c;
    int unk_00_150;     int unk_00_154;     int unk_00_158;     int unk_00_15c;     int unk_00_160;     int unk_00_164;
    int unk_00_168;     int unk_00_16c;     int unk_00_170;     int unk_00_174;     int unk_00_178;     int unk_00_17c;
    int unk_00_180;     int unk_00_184;     int unk_00_188;     int unk_00_18c;     int unk_00_190;     int unk_00_194;
    int unk_00_198;     int unk_00_19c;     int unk_00_1a0;     int unk_00_1a4;     int unk_00_1a8;     int unk_00_1ac;
    int unk_00_1b0;     int unk_00_1b4;     int unk_00_1b8;     int unk_00_1bc;     int unk_00_1c0;     int unk_00_1c4;
    int unk_00_1c8;     int unk_00_1cc;     int unk_00_1d0;     int unk_00_1d4;     int unk_00_1d8;     int unk_00_1dc;
    int unk_00_1e0;     int unk_00_1e4;     int unk_00_1e8;     int unk_00_1ec;     int unk_00_1f0;     int unk_00_1f4;
    int unk_00_1f8;     int unk_00_1fc;     int unk_00_200;     int unk_00_204;     int unk_00_208;     int unk_00_20c;
    int unk_00_210;     int unk_00_214;     int unk_00_218;     int unk_00_21c;     int unk_00_220;     int unk_00_224;
    int unk_00_228;     int unk_00_22c;     int unk_00_230;     int unk_00_234;     int unk_00_238;     int unk_00_23c;
    int unk_00_240;     int unk_00_244;     int unk_00_248;     int unk_00_24c;     int unk_00_250;     int unk_00_254;
    int unk_00_258;     int unk_00_25c;     int unk_00_260;     int unk_00_264;     int unk_00_268;     int unk_00_26c;
    int unk_00_270;     int unk_00_274;     int unk_00_278;     int unk_00_27c;     int unk_00_280;     int unk_00_284;
    int unk_00_288;     int unk_00_28c;     int unk_00_290;     int unk_00_294;     int unk_00_298;     int unk_00_29c;
    int unk_00_2a0;     int unk_00_2a4;     int unk_00_2a8;     int unk_00_2ac;     int unk_00_2b0;     int unk_00_2b4;
    int unk_00_2b8;     int unk_00_2bc;     int unk_00_2c0;     int unk_00_2c4;     int unk_00_2c8;     int unk_00_2cc;
    int unk_00_2d0;     int unk_00_2d4;     int unk_00_2d8;     int unk_00_2dc;     int unk_00_2e0;     int unk_00_2e4;
    int unk_00_2e8;     int unk_00_2ec;     int unk_00_2f0;     int unk_00_2f4;     int unk_00_2f8;     int unk_00_2fc;
    int unk_00_300;     int unk_00_304;     int unk_00_308;     int unk_00_30c;     int unk_00_310;     int unk_00_314;
    int unk_00_318;     int unk_00_31c;     int unk_00_320;     int unk_00_324;     int unk_00_328;     int unk_00_32c;
    int unk_00_330;     int unk_00_334;     int unk_00_338;     int unk_00_33c;     int unk_00_340;     int unk_00_344;
    int unk_00_348;     int unk_00_34c;     int unk_00_350;     int unk_00_354;     int unk_00_358;     int unk_00_35c;
    int unk_00_360;     int unk_00_364;     int unk_00_368;     int unk_00_36c;     int unk_00_370;     int unk_00_374;
    int unk_00_378;     int unk_00_37c;     int unk_00_380;     int unk_00_384;     int unk_00_388;     int unk_00_38c;
    int unk_00_390;     int unk_00_394;     int unk_00_398;     int unk_00_39c;     int unk_00_3a0;     int unk_00_3a4;
    int unk_00_3a8;     int unk_00_3ac;     int unk_00_3b0;     int unk_00_3b4;     int unk_00_3b8;     int unk_00_3bc;
    int unk_00_3c0;     int unk_00_3c4;     int unk_00_3c8;     int unk_00_3cc;     int unk_00_3d0;     int unk_00_3d4;
    int unk_00_3d8;     int unk_00_3dc;     int unk_00_3e0;     int unk_00_3e4;     int unk_00_3e8;     int unk_00_3ec;
    int unk_00_3f0;     int unk_00_3f4;     int unk_00_3f8;     int unk_00_3fc;     int unk_00_400;     int unk_00_404;
    int unk_00_408;     int unk_00_40c;     int unk_00_410;     int unk_00_414;     int unk_00_418;     int unk_00_41c;
    int unk_00_420;     int unk_00_424;     int unk_00_428;     int unk_00_42c;     int unk_00_430;     int unk_00_434;
    int unk_00_438;     int unk_00_43c;     int unk_00_440;     int unk_00_444;     int unk_00_448;     int unk_00_44c;
    int unk_00_450;     int unk_00_454;     int unk_00_458;     int unk_00_45c;     int unk_00_460;     int unk_00_464;
    int unk_00_468;     int unk_00_46c;     int unk_00_470;     int unk_00_474;     int unk_00_478;     int unk_00_47c;
    int unk_00_480;     int unk_00_484;     int unk_00_488;     int unk_00_48c;     int unk_00_490;     int unk_00_494;
    int unk_00_498;     int unk_00_49c;     int unk_00_4a0;     int unk_00_4a4;     int unk_00_4a8;     int unk_00_4ac;
    int unk_00_4b0;     int unk_00_4b4;     int unk_00_4b8;     int unk_00_4bc;     int unk_00_4c0;     int unk_00_4c4;
    int unk_00_4c8;     int unk_00_4cc;     int unk_00_4d0;     int unk_00_4d4;     int unk_00_4d8;     int unk_00_4dc;
    int unk_00_4e0;     int unk_00_4e4;     int unk_00_4e8;     int unk_00_4ec;     int unk_00_4f0;     int unk_00_4f4;
    int unk_00_4f8;     int unk_00_4fc;     int unk_00_500;     int unk_00_504;     int unk_00_508;     int unk_00_50c;
    int unk_00_510;     int unk_00_514;     int unk_00_518;     int unk_00_51c;     int unk_00_520;     int unk_00_524;
    int unk_00_528;     int unk_00_52c;     int unk_00_530;     int unk_00_534;     int unk_00_538;     int unk_00_53c;
    int unk_00_540;     int unk_00_544;     int unk_00_548;     int unk_00_54c;     int unk_00_550;     int unk_00_554;
    int unk_00_558;     int unk_00_55c;     int unk_00_560;     int unk_00_564;     int unk_00_568;     int unk_00_56c;
    int unk_00_570;     int unk_00_574;     int unk_00_578;     int unk_00_57c;     int unk_00_580;     int unk_00_584;
    int unk_00_588;     int unk_00_58c;     int unk_00_590;     int unk_00_594;     int unk_00_598;     int unk_00_59c;
    int unk_00_5a0;     int unk_00_5a4;     int unk_00_5a8;     int unk_00_5ac;     int unk_00_5b0;     int unk_00_5b4;
    int unk_00_5b8;     int unk_00_5bc;     int unk_00_5c0;     int unk_00_5c4;     int unk_00_5c8;     int unk_00_5cc;
    int unk_00_5d0;     int unk_00_5d4;     int unk_00_5d8;     int unk_00_5dc;     int unk_00_5e0;     int unk_00_5e4;
    int unk_00_5e8;     int unk_00_5ec;     int unk_00_5f0;     int unk_00_5f4;     int unk_00_5f8;     int unk_00_5fc;
    int unk_00_600;     int unk_00_604;     int unk_00_608;     int unk_00_60c;     int unk_00_610;     int unk_00_614;
    int unk_00_618;     int unk_00_61c;     int unk_00_620;     int unk_00_624;     int unk_00_628;     int unk_00_62c;
    int unk_00_630;     int unk_00_634;     int unk_00_638;     int unk_00_63c;     int unk_00_640;     int unk_00_644;
    int unk_00_648;     int unk_00_64c;     int unk_00_650;     int unk_00_654;     int unk_00_658;     int unk_00_65c;
    int unk_00_660;     int unk_00_664;     int unk_00_668;     int unk_00_66c;     int unk_00_670;     int unk_00_674;
    int unk_00_678;     int unk_00_67c;     int unk_00_680;     int unk_00_684;     int unk_00_688;     int unk_00_68c;
    int unk_00_690;     int unk_00_694;     int unk_00_698;     int unk_00_69c;     int unk_00_6a0;     int unk_00_6a4;
    int unk_00_6a8;     int unk_00_6ac;     int unk_00_6b0;     int unk_00_6b4;     int unk_00_6b8;     int unk_00_6bc;
    int unk_00_6c0;     int unk_00_6c4;     int unk_00_6c8;     int unk_00_6cc;     int unk_00_6d0;     int unk_00_6d4;
    int unk_00_6d8;     int unk_00_6dc;     int unk_00_6e0;     int unk_00_6e4;     int unk_00_6e8;     int unk_00_6ec;
    int unk_00_6f0;     int unk_00_6f4;     int unk_00_6f8;     int unk_00_6fc;     int unk_00_700;     int unk_00_704;
    int unk_00_708;     int unk_00_70c;     int unk_00_710;     int unk_00_714;     int unk_00_718;     int unk_00_71c;
    int unk_00_720;     int unk_00_724;     int unk_00_728;     int unk_00_72c;     int unk_00_730;     int unk_00_734;
    int unk_00_738;     int unk_00_73c;     int unk_00_740;     int unk_00_744;     int unk_00_748;     int unk_00_74c;
    int unk_00_750;     int unk_00_754;     int unk_00_758;     int unk_00_75c;     int unk_00_760;     int unk_00_764;
    int unk_00_768;     int unk_00_76c;     int unk_00_770;     int unk_00_774;     int unk_00_778;     int unk_00_77c;
    int unk_00_780;     int unk_00_784;     int unk_00_788;     int unk_00_78c;     int unk_00_790;     int unk_00_794;
    int unk_00_798;     int unk_00_79c;     int unk_00_7a0;     int unk_00_7a4;     int unk_00_7a8;     int unk_00_7ac;
    int unk_00_7b0;     int unk_00_7b4;     int unk_00_7b8;     int unk_00_7bc;     int unk_00_7c0;     int unk_00_7c4;
    int unk_00_7c8;     int unk_00_7cc;     int unk_00_7d0;     int unk_00_7d4;     int unk_00_7d8;     int unk_00_7dc;
    int unk_00_7e0;     int unk_00_7e4;     int unk_00_7e8;     int unk_00_7ec;     int unk_00_7f0;     int unk_00_7f4;
    int unk_00_7f8;     int unk_00_7fc;     int unk_00_800;     int unk_00_804;     int unk_00_808;     int unk_00_80c;
    int unk_00_810;     int unk_00_814;     int unk_00_818;     int unk_00_81c;     int unk_00_820;     int unk_00_824;
    int unk_00_828;     int unk_00_82c;     int unk_00_830;     int unk_00_834;     int unk_00_838;     int unk_00_83c;
    int unk_00_840;     int unk_00_844;     int unk_00_848;     int unk_00_84c;     int unk_00_850;     int unk_00_854;
    int unk_00_858;     int unk_00_85c;     int unk_00_860;     int unk_00_864;     int unk_00_868;     int unk_00_86c;
    int unk_00_870;     int unk_00_874;     int unk_00_878;     int unk_00_87c;     int unk_00_880;     int unk_00_884;
    int unk_00_888;     int unk_00_88c;     int unk_00_890;     int unk_00_894;     int unk_00_898;     int unk_00_89c;
    int unk_00_8a0;     int unk_00_8a4;     int unk_00_8a8;     int unk_00_8ac;     int unk_00_8b0;     int unk_00_8b4;
    int unk_00_8b8;     int unk_00_8bc;     int unk_00_8c0;     int unk_00_8c4;     int unk_00_8c8;     int unk_00_8cc;
    int unk_00_8d0;     int unk_00_8d4;     int unk_00_8d8;     int unk_00_8dc;     int unk_00_8e0;     int unk_00_8e4;
    int unk_00_8e8;     int unk_00_8ec;     int unk_00_8f0;     int unk_00_8f4;     int unk_00_8f8;     int unk_00_8fc;
    int unk_00_900;     int unk_00_904;     int unk_00_908;     int unk_00_90c;     int unk_00_910;     int unk_00_914;
    int unk_00_918;     int unk_00_91c;     int unk_00_920;     int unk_00_924;     int unk_00_928;     int unk_00_92c;
    int unk_00_930;     int unk_00_934;     int unk_00_938;     int unk_00_93c;     int unk_00_940;     int unk_00_944;
    int unk_00_948;     int unk_00_94c;     int unk_00_950;     int unk_00_954;     int unk_00_958;     int unk_00_95c;
    int unk_00_960;     int unk_00_964;     int unk_00_968;     int unk_00_96c;     int unk_00_970;     int unk_00_974;
    int unk_00_978;     int unk_00_97c;     int unk_00_980;     int unk_00_984;     int unk_00_988;     int unk_00_98c;
    int unk_00_990;     int unk_00_994;     int unk_00_998;     int unk_00_99c;     int unk_00_9a0;     int unk_00_9a4;
    int unk_00_9a8;     int unk_00_9ac;     int unk_00_9b0;     int unk_00_9b4;     int unk_00_9b8;     int unk_00_9bc;
    int unk_00_9c0;     int unk_00_9c4;     int unk_00_9c8;     int unk_00_9cc;     int unk_00_9d0;     int unk_00_9d4;
    int unk_00_9d8;     int unk_00_9dc;     int unk_00_9e0;     int unk_00_9e4;     int unk_00_9e8;     int unk_00_9ec;
    int unk_00_9f0;     int unk_00_9f4;     int unk_00_9f8;     int unk_00_9fc;
    void *m_a00;
    int m_a04;
};
struct Inner {
    PoolObj **m_00;
    int m_04;
    int m_08;
    void *m_0ctail;
    int m_10count;
    PoolObj *AllocateChainedSlotBlock();
};
struct NormalWords { int a,b,c,d; };
struct RecPayload {
    int m_08;
    int m_0c;
    int m_10;
    int m_14[3];
    NormalWords m_20;
    int m_30;
    int m_34; int m_38; int m_3c; int m_40;
};
struct __declspec(align(16)) PooledRec {
    void *m_00;
    int m_04;
    RecPayload p;
};
struct Out26010 { int m_00; int m_04; int m_08; };
struct Int2 {
    Int2() {}
    int m_00;
    int m_04;
};
struct Int3 {
    int m_00;
    int m_04;
    int m_08;
};
extern int DAT_010eb0e0;
extern int DAT_010eb088;
extern int DAT_0102e388;
struct CapMatrix { LocalVec4 rows[4]; int hkMatrix4_CopyColumnsAndApplyValue(const CapMatrix&,float); };
struct BigObj {
    void *m_vtbl;
    short m_04;
    short m_ref06;
    void *m_vtbl2;
    short m_0c;
    short m_ref0e;
    SubObj10 m_10;
    SubObj28 m_28;
    SubArr m_40arr;
    struct InlineEdge { int face; int index; };
    InlineEdge m_buf[64];
    int m_24c;
    Obj470 m_250;
    int unk_25c_25c;     int unk_25c_260;     int unk_25c_264;     int unk_25c_268;     int unk_25c_26c;     int unk_25c_270;
    int unk_25c_274;     int unk_25c_278;     int unk_25c_27c;     int unk_25c_280;     int unk_25c_284;     int unk_25c_288;
    int unk_25c_28c;     int unk_25c_290;     int unk_25c_294;     int unk_25c_298;     int unk_25c_29c;     int unk_25c_2a0;
    int unk_25c_2a4;     int unk_25c_2a8;     int unk_25c_2ac;     int unk_25c_2b0;     int unk_25c_2b4;     int unk_25c_2b8;
    int unk_25c_2bc;     int unk_25c_2c0;     int unk_25c_2c4;     int unk_25c_2c8;     int unk_25c_2cc;     int unk_25c_2d0;
    int unk_25c_2d4;     int unk_25c_2d8;     int unk_25c_2dc;     int unk_25c_2e0;     int unk_25c_2e4;     int unk_25c_2e8;
    int unk_25c_2ec;     int unk_25c_2f0;     int unk_25c_2f4;     int unk_25c_2f8;     int unk_25c_2fc;     int unk_25c_300;
    int unk_25c_304;     int unk_25c_308;     int unk_25c_30c;     int unk_25c_310;     int unk_25c_314;     int unk_25c_318;
    int unk_25c_31c;     int unk_25c_320;     int unk_25c_324;     int unk_25c_328;     int unk_25c_32c;     int unk_25c_330;
    int unk_25c_334;     int unk_25c_338;     int unk_25c_33c;     int unk_25c_340;     int unk_25c_344;     int unk_25c_348;
    int unk_25c_34c;     int unk_25c_350;     int unk_25c_354;     int unk_25c_358;     int unk_25c_35c;     int unk_25c_360;
    int unk_25c_364;     int unk_25c_368;     int unk_25c_36c;     int unk_25c_370;     int unk_25c_374;     int unk_25c_378;
    int unk_25c_37c;     int unk_25c_380;     int unk_25c_384;     int unk_25c_388;     int unk_25c_38c;     int unk_25c_390;
    int unk_25c_394;     int unk_25c_398;     int unk_25c_39c;     int unk_25c_3a0;     int unk_25c_3a4;     int unk_25c_3a8;
    int unk_25c_3ac;     int unk_25c_3b0;     int unk_25c_3b4;     int unk_25c_3b8;     int unk_25c_3bc;     int unk_25c_3c0;
    int unk_25c_3c4;     int unk_25c_3c8;     int unk_25c_3cc;     int unk_25c_3d0;     int unk_25c_3d4;     int unk_25c_3d8;
    int unk_25c_3dc;     int unk_25c_3e0;     int unk_25c_3e4;     int unk_25c_3e8;     int unk_25c_3ec;     int unk_25c_3f0;
    int unk_25c_3f4;     int unk_25c_3f8;     int unk_25c_3fc;     int unk_25c_400;     int unk_25c_404;     int unk_25c_408;
    int unk_25c_40c;     int unk_25c_410;     int unk_25c_414;     int unk_25c_418;     int unk_25c_41c;     int unk_25c_420;
    int unk_25c_424;     int unk_25c_428;     int unk_25c_42c;     int unk_25c_430;     int unk_25c_434;     int unk_25c_438;
    int unk_25c_43c;     int unk_25c_440;     int unk_25c_444;     int unk_25c_448;     int unk_25c_44c;     int unk_25c_450;
    int unk_25c_454;     int unk_25c_458;     int unk_25c_45c;     int unk_25c_460;     int unk_25c_464;     int unk_25c_468;
    int unk_25c_46c;     int unk_25c_470;     int unk_25c_474;     int unk_25c_478;     int unk_25c_47c;     int unk_25c_480;
    int unk_25c_484;     int unk_25c_488;     int unk_25c_48c;     int unk_25c_490;     int unk_25c_494;     int unk_25c_498;
    int unk_25c_49c;     int unk_25c_4a0;     int unk_25c_4a4;     int unk_25c_4a8;     int unk_25c_4ac;     int unk_25c_4b0;
    int unk_25c_4b4;     int unk_25c_4b8;     int unk_25c_4bc;     int unk_25c_4c0;     int unk_25c_4c4;     int unk_25c_4c8;
    int unk_25c_4cc;     int unk_25c_4d0;     int unk_25c_4d4;     int unk_25c_4d8;     int unk_25c_4dc;     int unk_25c_4e0;
    int unk_25c_4e4;     int unk_25c_4e8;     int unk_25c_4ec;     int unk_25c_4f0;     int unk_25c_4f4;     int unk_25c_4f8;
    int unk_25c_4fc;     int unk_25c_500;     int unk_25c_504;     int unk_25c_508;     int unk_25c_50c;     int unk_25c_510;
    int unk_25c_514;     int unk_25c_518;     int unk_25c_51c;     int unk_25c_520;     int unk_25c_524;     int unk_25c_528;
    int unk_25c_52c;     int unk_25c_530;     int unk_25c_534;     int unk_25c_538;     int unk_25c_53c;     int unk_25c_540;
    int unk_25c_544;     int unk_25c_548;     int unk_25c_54c;     int unk_25c_550;     int unk_25c_554;     int unk_25c_558;
    int unk_25c_55c;     int unk_25c_560;     int unk_25c_564;     int unk_25c_568;     int unk_25c_56c;     int unk_25c_570;
    int unk_25c_574;     int unk_25c_578;     int unk_25c_57c;     int unk_25c_580;     int unk_25c_584;     int unk_25c_588;
    int unk_25c_58c;     int unk_25c_590;     int unk_25c_594;     int unk_25c_598;     int unk_25c_59c;     int unk_25c_5a0;
    int unk_25c_5a4;     int unk_25c_5a8;     int unk_25c_5ac;     int unk_25c_5b0;     int unk_25c_5b4;     int unk_25c_5b8;
    int unk_25c_5bc;     int unk_25c_5c0;     int unk_25c_5c4;     int unk_25c_5c8;     int unk_25c_5cc;     int unk_25c_5d0;
    int unk_25c_5d4;     int unk_25c_5d8;     int unk_25c_5dc;     int unk_25c_5e0;     int unk_25c_5e4;     int unk_25c_5e8;
    int unk_25c_5ec;     int unk_25c_5f0;     int unk_25c_5f4;     int unk_25c_5f8;     int unk_25c_5fc;     int unk_25c_600;
    int unk_25c_604;     int unk_25c_608;     int unk_25c_60c;     int unk_25c_610;     int unk_25c_614;     int unk_25c_618;
    int unk_25c_61c;     int unk_25c_620;     int unk_25c_624;     int unk_25c_628;     int unk_25c_62c;     int unk_25c_630;
    int unk_25c_634;     int unk_25c_638;     int unk_25c_63c;     int unk_25c_640;     int unk_25c_644;     int unk_25c_648;
    int unk_25c_64c;     int unk_25c_650;     int unk_25c_654;     int unk_25c_658;
    int m_iValueBeforeForwardMatrix;
    CapMatrix forward;
    CapMatrix inverse;

    __forceinline RecPoint transformPoint(const LocalVec4& input) const {
                            __m128 n3 = input.quad;
                            __m128 r = _mm_mul_ps(_mm_shuffle_ps(n3, n3, 0x55), _mm_load_ps((float *)&inverse.rows[1]));
                            r = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(n3, n3, 0), _mm_load_ps((float *)&inverse.rows[0])));
                            r = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(n3, n3, 0xaa), _mm_load_ps((float *)&inverse.rows[2])));
                            r = _mm_add_ps(r, _mm_load_ps((float *)&inverse.rows[3]));
                            LocalVec4 ptr;
                            _mm_store_ps((float *)&ptr, r);
                            RecPoint vb;
                            long pool = m_iValueBeforeForwardMatrix;
                            long zz;
                            zz = 0x7fff - pool;
                            int s;
                            s = (int)(ptr.x < 0.0f ? ptr.x - 0.5 : ptr.x + 0.5);
                            vb.x = s < pool ? pool : (s > zz ? zz : s);
                            int i;
                            i = (int)(ptr.y < 0.0f ? ptr.y - 0.5 : ptr.y + 0.5);
                            vb.y = i < pool ? pool : (i > zz ? zz : i);

return vb;
}
    Int3 LocatePoint(int a, int b);
    Int2 hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_locateExistingEdge_00e24aa0(int a, int b, int c, int d);
    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_partition();
    void UpdateState_00e27b50(const LocalVec4& a,const LocalVec4& b,float f,bool n);
    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_reset(int n);
    Out26010 hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_insertEdge(int a, int b, int c, int d, int e, int f);
    Int3 hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_insertVertex(int a, int b, int flag, void *tmp, int z);
};

__forceinline void InitBigObj(BigObj *obj)
{
    obj->m_ref06 = 1;
    obj->m_ref0e = 1;
    obj->m_vtbl = &DAT_010eb0e0;
    obj->m_vtbl2 = &DAT_010eb088;
    obj->m_10.unk_00_000 = 0;
    obj->m_10.unk_00_004 = 0;
    obj->m_10.unk_00_008 = (int)0x80000000;
    obj->m_10.unk_00_00c = 0;
    obj->m_10.unk_00_010 = 0;
    obj->m_28.unk_00_000 = 0;
    obj->m_28.unk_00_004 = 0;
    obj->m_28.unk_00_008 = (int)0x80000000;
    obj->m_28.m_0chead = 0;
    obj->m_28.unk_10_010 = 0;
    obj->m_40arr.m_pData = obj->m_buf;
    obj->m_40arr.m_iArrayLength = 0;
    obj->m_40arr.m_iCap = (int)0x80000040;
    obj->m_250.m_aiIndexedValues.m_pData = 0;
    obj->m_250.m_aiIndexedValues.m_iArrayLength = 0;
    obj->m_250.m_aiIndexedValues.m_iCap = (int)0x80000000;
}

__forceinline void TeardownBigObj(BigObj *obj)
{
    obj->m_vtbl = &DAT_010eb0e0;
    obj->hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_reset(1);
    obj->m_250.FUN_00e23c70();
    AllocSvc *alloc = capMemory();
    AllocCtx *ctx = alloc->m_10;
    int cap = obj->m_40arr.m_iCap;
    obj->m_40arr.m_iArrayLength = 0;
    if ((cap & (int)0x80000000) == 0)
        ctx->FreeBuf(obj->m_40arr.m_pData, (cap & 0x3fffffff) * 8);
    obj->m_40arr.m_pData = 0;
    obj->m_40arr.m_iCap = (int)0x80000000;
    obj->m_vtbl2 = &DAT_010eb088;
    obj->m_28.hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_reset();
    obj->m_28.ProcessEntries_00e23d70();
    obj->m_10.ProcessEntries();
    obj->m_10.ClearAndFreeItems();
    obj->m_vtbl2 = &DAT_0102e388;
    obj->m_vtbl = &DAT_0102e388;
    capMemory();
}

__forceinline void capFinish(BigObj& obj){obj.m_24c=0;}
struct TriNode {
    TriNode *m_next;
    int m_04;
    // Three vertices followed by three tagged adjacency links.
    TriNode *m_aiIndexedValues[6];
    unsigned int m_flags;
    int unk24; int unk28; int unk2c;
    union {
        int m_30i;
        float m_30f;
    };
};

SubArr *__cdecl hkgpMeshInternals_createRing(TriNode *node, int idx);

struct BoundaryEdge {
    TriNode *face; int index;
    BoundaryEdge() {}
    BoundaryEdge(TriNode *f, int e) : face(f), index(e) {}
    BoundaryEdge(int packed) { index=packed & 3; face=(TriNode*)(packed & ~3); }
    int packed() const { return (int)face + index; }
    CapVertex *vertex() const { return (CapVertex*)face->m_aiIndexedValues[index]; }
    BoundaryEdge next() const { return BoundaryEdge(face, (9 >> (index * 2)) & 3); }
    BoundaryEdge previous() const { return BoundaryEdge(face, (0x12 >> (index * 2)) & 3); }
    BoundaryEdge link() const { return BoundaryEdge((int)face->m_aiIndexedValues[3 + index]); }
    bool valid() const { return face != 0; }
    void bind(const BoundaryEdge& other) const {
        face->m_aiIndexedValues[3 + index] = (TriNode*)other.packed();
        if (other.face) other.face->m_aiIndexedValues[3 + other.index] = (TriNode*)packed();
    }
};

struct MeshPoolView {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    Inner pool;
};
struct BuildStatus { int code; BuildStatus() {} BuildStatus(int value) : code(value) {} };

__forceinline BoundaryEdge LookupEdge51(PartsMap& map,int value) { return BoundaryEdge(map.LookupHashEntry(value,0)); }
struct SlotToken{unsigned long data:32;};
struct ThisCls {
    int unk_00_000;     int unk_00_004;     int unk_00_008;     int unk_00_00c;     int unk_00_010;     int unk_00_014;
    int unk_00_018;     int unk_00_01c;
    int unk20; int unk24; int unk28;
    TriNode* m_2c;
    bool hkgpMesh_isClosedManifold();
    void hkgpMesh_replaceVertex(SlotToken a,SlotToken b);
    void RemoveEdge(int a, int b, int c);
    BuildStatus SplitMeshAlongPlane(float *pVec, int flag);
    void hkgpMesh_removeOrphanVertices();
    BuildStatus BuildProjectedBoundaryMesh(float *pVec);
};


// src: GUESS 0x00e27b50 (confidence: low)
__declspec(noinline) void BigObj::UpdateState_00e27b50(const LocalVec4& a,const LocalVec4& b,float f,bool n) {
    m_iValueBeforeForwardMatrix=n?1:0;
    float span=float(32767-2*m_iValueBeforeForwardMatrix);
    float sn=(float)sin(f);
    float cs=(float)cos(f);
    float sx=(b.x-a.x)/span;
    float sy=(b.y-a.y)/span;
    forward.rows[0].quad=_mm_setr_ps(1.0f,0.0f,0.0f,0.0f);
    forward.rows[1].quad=_mm_setr_ps(0.0f,1.0f,0.0f,0.0f);
    forward.rows[2].quad=_mm_setr_ps(0.0f,0.0f,1.0f,0.0f);
    forward.rows[3].quad=_mm_setr_ps(0.0f,0.0f,0.0f,1.0f);
    forward.rows[0].x=cs*sx;
    forward.rows[1].x=sn*sy;
    forward.rows[3].x=a.x;
    forward.rows[0].y=-sn*sx;
    forward.rows[1].y=cs*sy;
    forward.rows[3].y=a.y;
    inverse.hkMatrix4_CopyColumnsAndApplyValue(forward,0.0f);
    hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_reset(1);
}

// Builds a boundary mesh from TriNode faces by projecting vertices, detecting overlaps, and linking edges into a PooledRec pool.
// @fnv 0x00e1de00
// src: GUESS 0x00e1de00 (confidence: medium)
BuildStatus ThisCls::BuildProjectedBoundaryMesh(float *apNormal)
{
    long basis3;
union SharedACurrent { TriNode** vertices; int index; }; SharedACurrent scratchA;
union SharedB51 {TriNode* face; SubArr* array;}; SharedB51 scratchB;

    SubArr y;
    y.m_pData = 0;
    y.m_iArrayLength = 0;
    y.m_iCap = (int)0x80000000;
    bool ptr = hkgpMesh_isClosedManifold();
    BuildStatus pStatus = SplitMeshAlongPlane(apNormal, 1);
    int *res = &pStatus.code;
    if (*res != 0)
        goto cap;
    if (!ptr)
        goto ptr;
    {
        long iSide;
        iSide = 0;
        for (; iSide < 2; iSide++)
        {
        b:
            for (int s = 0; s < y.m_iArrayLength; s++)
            {
                SubArr *sub;
                sub = ((SubArr **)y.m_pData)[s];
                if (sub)
                {
                    AllocSvc *val = capMemory();
                    AllocCtx *result;
                    result = val->m_10;
                    int ptr = sub->m_iCap;
                    sub->m_iArrayLength = 0;
                    if ((ptr & (int)0x80000000) == 0)
                        result->FreeBuf(sub->m_pData, (ptr & 0x3fffffff) * 64);
                    sub->m_pData = 0;
                    sub->m_iCap = (int)0x80000000;
                    AllocSvc *s = capMemory();
                    AllocCtx *zz;
                    zz = s->m_10;
                    zz->Dealloc(sub, 12);
                }
            }
            y.m_iArrayLength = 0;

            scratchB.face = m_2c;
            if (!scratchB.face)
            {
                goto missing_boundary;
            }
            for (; scratchB.face; scratchB.face = scratchB.face->m_next)
            {
                if (scratchB.face->m_30i != iSide)
                    continue;
                basis3=0;
                TriNode **queryY=scratchB.face->m_aiIndexedValues;
                for (; basis3<3; basis3++)
                {
                    if (((int)queryY[3] & ~3) == 0)
                    {
                        if (((CapVertex*)*queryY)->weight == 0.0f)
                        {
                            int pForm;
                            pForm = (9 >> (basis3 << 1)) & 3;
                            TriNode *rows = scratchB.face->m_aiIndexedValues[pForm];
                            if (((CapVertex*)rows)->weight == 0.0f)
                            {
                                bool bAlreadyInList = false;
                                for (int cap = 0; cap < y.m_iArrayLength; cap++)
                                {
                                    SubArr *sub;
                                    sub = ((SubArr **)y.m_pData)[cap];
                                    int iPointCount = sub->m_iArrayLength;
                                    
                                    for (int iInnerIndex = 0; iInnerIndex < iPointCount; iInnerIndex++)
                                    {
                                        if (((Rec*)sub->m_pData)[iInnerIndex].m_00 + ((Rec*)sub->m_pData)[iInnerIndex].m_04 == (int)((char *)scratchB.face + basis3))
                                        {
                                            bAlreadyInList = true;
                                            break;
                                        }
                                    }
                                }
                                if (!bAlreadyInList)
                                {
                                    SubArr *base;
                                    base = hkgpMeshInternals_createRing(scratchB.face, basis3);
                                    if (base)
                                    {
                                        AllocSvc *val = capMemory();
                                        if (y.m_iArrayLength == (y.m_iCap & 0x3fffffff))
                                            ResizeAudioStream((void*)val->m_10, &y, 4);
                                        ((SubArr **)y.m_pData)[y.m_iArrayLength] = base;
                                        y.m_iArrayLength++;
                                    }
                                }
                            }
                        }
                    }
                    queryY += 1;
                }
            }
            if (!y.m_iArrayLength)
            {
                goto missing_boundary;
            }
            for (int cap = 0; cap < y.m_iArrayLength; cap++)
            {
                SubArr *sub;
                sub = ((SubArr **)y.m_pData)[cap];
                switch (sub->m_iArrayLength)
                {
                case 3:
                {
                    Rec *pRecArray;
                    pRecArray = (Rec *)sub->m_pData;
                    if (pRecArray[0].m_00 != pRecArray[1].m_00)
                        break;
                    if (pRecArray[0].m_00 != pRecArray[2].m_00)
                        break;
                    AllocSvc *val = capMemory();
                    AllocCtx *result = val->m_10;
                    long ptr;
                    ptr = sub->m_iCap;
                    sub->m_iArrayLength = 0;
                    if ((ptr & 0x80000000) == 0)
                        result->FreeBuf(sub->m_pData, (ptr & 0x3fffffff) * 64);
                    sub->m_pData = 0;
                    sub->m_iCap = (int)0x80000000;
                    AllocSvc *s = capMemory();
                    AllocCtx *zz = s->m_10;
                    zz->Dealloc(sub, 12);
                    y.m_iArrayLength--;
                    if (y.m_iArrayLength != cap)
                        ((SubArr **)y.m_pData)[cap] = ((SubArr **)y.m_pData)[y.m_iArrayLength];
                    cap--;
                    break;
                }
                case 2:
                {
                    Rec *pRecArray;
                    pRecArray = (Rec *)sub->m_pData;
                    ((BoundaryEdge&)pRecArray[0]).bind((BoundaryEdge&)pRecArray[1]);
                    AllocSvc *val = capMemory();
                    AllocCtx *result;
                    result = val->m_10;
                    long ptr = sub->m_iCap;
                    sub->m_iArrayLength = 0;
                    if ((ptr & 0x80000000) == 0)
                        result->FreeBuf(sub->m_pData, (ptr & 0x3fffffff) * 64);
                    sub->m_pData = 0;
                    sub->m_iCap = (int)0x80000000;
                    AllocSvc *s = capMemory();
                    AllocCtx *zz;
                    zz = s->m_10;
                    zz->Dealloc(sub, 12);
                    y.m_iArrayLength--;
                    if (y.m_iArrayLength != cap)
                        ((SubArr **)y.m_pData)[cap] = ((SubArr **)y.m_pData)[y.m_iArrayLength];
                    cap--;
                    break;
                }
                }
            }
            if (y.m_iArrayLength ? true : false)
            {
                LocalVec4 tmp138 = *(LocalVec4*)&DAT_01267e30;
                LocalVec4 idx = *(LocalVec4*)&DAT_01267e30;

                float extent = fabs(apNormal[0]);
                float absoluteY = fabs(apNormal[1]);
                float fAbsZ = fabs(apNormal[2]);
                long iAxis;
                iAxis = 0;
                unsigned long zz = 1 + iAxis;
                long recA = iAxis + 2;
                if (absoluteY < extent)
                {
                    zz = 0;
                    iAxis = recA - 1;
                    extent = absoluteY;
                }
                if (fAbsZ < extent)
                    recA = iAxis;
                LocalVec4 z;
                _mm_store_ps((float *)&z, _mm_setzero_ps());
                ((float *)&z)[zz] = apNormal[recA];
                ((float *)&z)[recA] = -apNormal[zz];
                NormalizeInPlace(z);
                LocalVec4 c;
                SetCross(c, *(const LocalVec4*)apNormal, z);
                NormalizeInPlace(c);
                LocalVec4 vmin;
                SetCross(vmin, z, c);
                NormalizeInPlace(vmin);
                if ((bool)iSide)
                    { __m128 t=_mm_set_ss(-1.0f); z.quad=_mm_mul_ps(_mm_shuffle_ps(t,t,0), z.quad); }
                LocalVec4 ok[3];
                _mm_store_ps((float *)&ok[0], _mm_setr_ps(z.x, c.x, vmin.x, 0.0f));
                _mm_store_ps((float *)&ok[1], _mm_setr_ps(z.y, c.y, vmin.y, 0.0f));
                _mm_store_ps((float *)&ok[2], _mm_setr_ps(z.z, c.z, vmin.z, 0.0f));
                for (scratchA.index = 0; scratchA.index < y.m_iArrayLength; scratchA.index++)
                {
                    SubArr *sub = ((SubArr **)y.m_pData)[scratchA.index];
                    for (int inner51_1 = 0; inner51_1 < sub->m_iArrayLength; inner51_1++)
                    {
                        Rec *obj = &((Rec*)sub->m_pData)[inner51_1];
                        float *key = (float *)&obj->projected;
                        void *pVertexPos = &((CapVertex*)((TriNode*)obj->m_00)->m_aiIndexedValues[obj->m_04])->position;
                        ((PtObj *)key)->hkVector4_setRotatedDir(ok, pVertexPos);
                        if (0 == scratchA.index && inner51_1 == 0)
                        {
                            tmp138 = idx = obj->projected;
                        }
                        else
                        {
                            const LocalVec4& value51 = obj->projected;
                            tmp138.quad = _mm_min_ps(tmp138.quad, value51.quad);
                            idx.quad = _mm_max_ps(idx.quad, value51.quad);
                        }
                    }
                }
                LocalVec4 vExtent;
                vExtent.quad = _mm_sub_ps(idx.quad, tmp138.quad);
                if (vExtent.x < DAT_0104da4c || vExtent.y < DAT_0104da4c)
                {
                    *res = 4;
                    capMemory();
                    goto ptr;
                }
                {
                    BigObj slotPtr;
                    InitBigObj(&slotPtr);
                    LocalVec4 kIter;
                    _mm_store_ps((float *)&kIter, _mm_setr_ps(-1.0f, -1.0f, 0.0f, 0.0f));
                    LocalVec4 ptr;
                    _mm_store_ps((float *)&ptr, _mm_setr_ps(DAT_01012068, DAT_01012068, 0.0f, 0.0f));
                    capFinish(slotPtr);
                    slotPtr.UpdateState_00e27b50(kIter, ptr, 0.0f, true);
                    slotPtr.UpdateState_00e27b50(tmp138, idx, 0.0f, true);
                    for (int iRingIndex = 0; iRingIndex < y.m_iArrayLength; iRingIndex++)
                    {
                        scratchB.array = ((SubArr **)y.m_pData)[iRingIndex];
                        for (int mergeIndex = 0; mergeIndex < scratchB.array->m_iArrayLength; mergeIndex++)
                        {
                            Rec *obj;
                            obj = &((Rec*)scratchB.array->m_pData)[mergeIndex];
                            float *key;
                            key = (float *)&obj->projected;
                            obj->point=slotPtr.transformPoint(obj->projected);
                        }
                    }
                    for (int mn = 0; mn < y.m_iArrayLength; mn++)
                    {
                        SubArr *sub = ((SubArr **)y.m_pData)[mn];
                        int count = sub->m_iArrayLength;
                        for (int pVertexPos = 0; pVertexPos < count; pVertexPos++)
                        {
                            Rec *pRec = &((Rec*)sub->m_pData)[pVertexPos];
                            RecPoint *s = &((Rec*)sub->m_pData)[(pVertexPos + 1) % count].point;
                            if (pRec->point.x == s->x && pRec->point.y == s->y)
                            {
                                RemoveEdge(pRec->m_00, pRec->m_04, 0);
                                TeardownBigObj(&slotPtr);
                                goto b;
                            }
                        }
                    }
                for (int mergeIndex = 0; mergeIndex < y.m_iArrayLength; mergeIndex++)
                {
                    SubArr *sub = ((SubArr **)y.m_pData)[mergeIndex];
                    for (int mergePoint = 0; mergePoint < sub->m_iArrayLength; mergePoint++)
                    {
                        Rec *obj = &((Rec*)sub->m_pData)[mergePoint];
                        for (int d2 = 0; d2 < y.m_iArrayLength; d2++)
                        {
                            SubArr *pOtherRing = ((SubArr **)y.m_pData)[d2];
                            for (int k = 0; k < pOtherRing->m_iArrayLength; k++)
                            {
                                Rec *s;
                                s = &((Rec*)pOtherRing->m_pData)[k];
                                if (obj == s)
                                    continue;
                                if (obj->point.x != s->point.x)
                                    continue;
                                if (obj->point.y != s->point.y)
                                    continue;
                                TriNode*& q=((TriNode*)s->m_00)->m_aiIndexedValues[s->m_04];
                                TriNode*& va=((TriNode*)obj->m_00)->m_aiIndexedValues[obj->m_04];
if(va==q)continue;hkgpMesh_replaceVertex(*(SlotToken*)&va,*(SlotToken*)&q);
                            }
                        }
                    }
                }
                PartsMap a;
                for (int mn = 0; mn < y.m_iArrayLength; mn++)
                {
                    SubArr* insertRing = ((SubArr **)y.m_pData)[mn];
                    for (int inner51_3 = 0; inner51_3 < insertRing->m_iArrayLength; inner51_3++)
                    {
                        Rec *obj = &((Rec*)insertRing->m_pData)[inner51_3];
                        long iY = obj->point.y;
                        int ptr = obj->point.x;
                        Int3 rlow = slotPtr.LocatePoint(ptr, iY);
                        long v;
                        Int3 point = slotPtr.hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_insertVertex(ptr, iY, 1, &rlow, 0);
                        v = point.m_00;
                        if (v < 0 || 1 < v)
                        {
                            *res = 5;
                            {
                                AllocSvc *val = capMemory();
                                a.ProcessArgument((Allocator*)val->m_10);
                            }
                            a.Object_DoNothing();
                            TeardownBigObj(&slotPtr);
                            goto ptr;
                        }
                        unsigned long created;
                        created = obj->m_04 + obj->m_00;
                        int tmp = (int)((TriNode*)point.m_04)->m_aiIndexedValues[point.m_08];
                        AllocSvc *val = capMemory();
                        a.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert((Allocator*)val->m_10, tmp, created);
                    }
                }
                int iFailed = 0;
                for (int mn = 0; !iFailed && mn < y.m_iArrayLength; ++mn)
                {
                    SubArr* segmentRing = ((SubArr**)y.m_pData)[mn];
                    for (int pVertexPos = 0; !iFailed && pVertexPos < segmentRing->m_iArrayLength; ++pVertexPos)
                    {
                        Rec* x = (Rec*)segmentRing->m_pData;
                        RecPoint* next = &x[(pVertexPos + 1) % segmentRing->m_iArrayLength].point;
                        Out26010 result51 = slotPtr.hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_insertEdge(x[pVertexPos].point.x, x[pVertexPos].point.y, next->x, next->y, 1, 0);
                        
                        _ReadWriteBarrier();
                        if (result51.m_00 != 0)
                        {
                            *res = 6;
                            {
                                AllocSvc *val = capMemory();
                                a.ProcessArgument((Allocator*)val->m_10);
                            }
                            a.Object_DoNothing();
                            TeardownBigObj(&slotPtr);
                            goto ptr;
                        }
                    }
                }
                slotPtr.hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_partition();
                PartsMap edgeRecords;
                for (int edgeIndex = 0; edgeIndex < y.m_iArrayLength; edgeIndex++)
                {
                    SubArr *sub;
                    sub = ((SubArr **)y.m_pData)[edgeIndex];
                    const int& iPointCount = sub->m_iArrayLength;
                    void*& n = sub->m_pData;
                    for (int pVertexPos = 0; pVertexPos < iPointCount; pVertexPos++)
                    {
                        Rec *obj = &((Rec*)n)[pVertexPos];
                        BoundaryEdge originalEdge((TriNode*)obj->m_00,obj->m_04);
                        RecPoint *zz = &((Rec*)n)[(1 + pVertexPos) % iPointCount].point;
                        Int2 ptr = slotPtr.hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_locateExistingEdge_00e24aa0( obj->point.x, obj->point.y, zz->x, zz->y);
                        AllocSvc *val = capMemory();
                        edgeRecords.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert((Allocator*)val->m_10, ptr.m_00 + ptr.m_04, originalEdge.packed());
                    }
                }
                {
                    LocalVec4 s;
                    ((int *)&s)[0] = ((int *)apNormal)[0];
                    ((int *)&s)[1] = ((int *)apNormal)[1];
                    ((int *)&s)[2] = ((int *)apNormal)[2];
                    ((int *)&s)[3] = ((int *)apNormal)[3];
                    if (iSide == 0)
                    {
                        __m128 d=_mm_set_ss(-1.0f);
                        s.quad=_mm_mul_ps(_mm_shuffle_ps(d,d,0),s.quad);
                    }
                    TriNode *pFaceHead = (TriNode *)slotPtr.m_28.m_0chead;
                    PooledRec arr;
                    RecPayload& cnt=arr.p;
                    for (scratchB.face = pFaceHead; scratchB.face; scratchB.face = scratchB.face->m_next)
                    {
                        if ((scratchB.face->m_flags & 0x10) == 0)
                            continue;
                        Inner *ptr;
                        ptr = &((MeshPoolView*)this)->pool;
                        PoolObj *pPoolObj = 0;
                        if (!!ptr->m_04)
                        {
                            pPoolObj = *ptr->m_00;
                            if (pPoolObj->m_a00 == 0)
                                pPoolObj = 0;
                        }
                        if (!pPoolObj)
                            pPoolObj = ptr->AllocateChainedSlotBlock();
                        PooledRec *obj;
                        obj = (PooledRec *)pPoolObj->m_a00;
                        pPoolObj->m_a00 = obj->m_00;
                        pPoolObj->m_a04++;
                        obj->p.m_08 = cnt.m_08;
                        obj->p.m_0c = cnt.m_0c;
                        obj->p.m_10 = cnt.m_10;
                        obj->p.m_14[0] = cnt.m_14[0];
                        obj->p.m_14[1] = cnt.m_14[1];
                        obj->p.m_14[2] = cnt.m_14[2];
                        obj->p.m_20 = cnt.m_20;
                        obj->p.m_30 = cnt.m_30;
                        obj->p.m_34 = cnt.m_34;
                        obj->p.m_38 = cnt.m_38;
                        obj->p.m_3c = cnt.m_3c;
                        obj->p.m_40 = cnt.m_40;
                        obj->m_04 = 0;
                        obj->m_00 = ptr->m_0ctail;
                        if (ptr->m_0ctail)
                            ((PooledRec*)ptr->m_0ctail)->m_04 = (int)obj;
                        ptr->m_10count++;
                        ptr->m_0ctail = obj;
                        BoundaryEdge vertexEdges[3]={LookupEdge51(a,(int)scratchB.face->m_aiIndexedValues[0]),LookupEdge51(a,(int)scratchB.face->m_aiIndexedValues[1]),LookupEdge51(a,(int)scratchB.face->m_aiIndexedValues[2])};
                        __m128 faceNormal=s.quad; obj->p.m_08 = (int)vertexEdges[0].vertex();
                        obj->p.m_0c = (int)vertexEdges[1].vertex();
                        obj->p.m_10 = (int)vertexEdges[2].vertex();
                        obj->p.m_30 = iSide;
                        _mm_store_ps((float *)&obj->p.m_20, faceNormal);
                        char *rawy;
                        rawy = (char *)obj;
                        for (int mn = 0; mn < 3; mn++)
                        {
                            BoundaryEdge sourceEdge((int)scratchB.face->m_aiIndexedValues[3 + mn]);
                            long ptr;
                            ptr = sourceEdge.packed();
                            BoundaryEdge targetEdge(edgeRecords.LookupHashEntry(ptr, 0));
                            unsigned long sum;
                            TriNode *p = targetEdge.face;
                            sum = targetEdge.index;
                            if (targetEdge.valid())
                            {
                                obj->p.m_14[mn] = (int)p + sum;
                                ((TriNode*)p)->m_aiIndexedValues[3 + sum] = (TriNode*)rawy;
                                edgeRecords.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(ptr);
                            }
                            else
                            {
                                AllocSvc *val = capMemory();
                                edgeRecords.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert((Allocator*)val->m_10, (int)((char*)scratchB.face + mn), (int)rawy);
                                obj->p.m_14[mn] = 0;
                            }
                            ++rawy;
                        }
                    }
                }
                {
                    AllocSvc *val = capMemory();
                    edgeRecords.ProcessArgument((Allocator*)val->m_10);
                }
                edgeRecords.Object_DoNothing();
                {
                    AllocSvc *val = capMemory();
                    a.ProcessArgument((Allocator*)val->m_10);
                }
                a.Object_DoNothing();
                TeardownBigObj(&slotPtr);
                }
            }
        }
    }
    goto ptr;
missing_boundary:
    *res = 3;
    goto cap;
ptr:
    if (*res == 0)
    {
        for (TriNode *pFace = m_2c; pFace; pFace = pFace->m_next)
        {
            for (int mn = 0; mn < 3; mn++)
            {
                BoundaryEdge edge((int)pFace->m_aiIndexedValues[3+mn]);
                if(edge.valid())
                {
                    int s=(0x12 >> (edge.index*2))&3;
                    int rec=(0x12 >> (mn<<1))&3;
                    if(pFace->m_aiIndexedValues[rec]==edge.face->m_aiIndexedValues[s])
                    {
                        *res=7;
                        goto cap;
                    }
                }
            }
        }
        if (ptr)
        {
            bool j = hkgpMesh_isClosedManifold();
            if (j == 0)
                *res = 9;
        }
    }
cap:
    for (int s = 0; s < y.m_iArrayLength; s++)
    {
        SubArr *sub;
        sub = ((SubArr **)y.m_pData)[s];
        if (sub)
                {
                    AllocSvc *val = capMemory();
                    AllocCtx *result = val->m_10;
                    int ptr = sub->m_iCap;
                    sub->m_iArrayLength = 0;
                    if ((ptr & (int)0x80000000) == 0)
                        result->FreeBuf(sub->m_pData, (ptr & 0x3fffffff) * 64);
                    sub->m_pData = 0;
                    sub->m_iCap = (int)0x80000000;
                    AllocSvc *s = capMemory();
                    AllocCtx *zz = s->m_10;
                    zz->Dealloc(sub, 12);
                }
    }
    y.m_iArrayLength = 0;
    hkgpMesh_removeOrphanVertices();
    {
        AllocSvc *val = capMemory();
        AllocCtx *result = val->m_10;
        int ptr = y.m_iCap;
        y.m_iArrayLength = 0;
        if ((ptr & (int)0x80000000) == 0)
            result->FreeBuf(y.m_pData, (ptr & 0x3fffffff) * 4);
    }
    return pStatus;
}

extern "C" __m128 _mm_setr_ps(float,float,float,float);
template<class T> __forceinline void fillRange(T* output,int count,const T& value)throw(){for(int index=0;index<count;++index)output[index]=value;}
template<class T> __forceinline void copyConstructRange(T* output,int count,const T& value)throw(){for(int index=0;index<count;++index)new(output+index) T(value);}
extern "C" __m128 _mm_set_ps(float,float,float,float);
void __cdecl ResizeAudioStream(Allocator&,void*,int) throw();
void __cdecl hkArrayUtil__reserve(Allocator&,void*,int,int) throw();
template<class T> __forceinline void destroyRange(T* p,int n) throw() {
 for(int i=0;i<n;++i) {p[i].~T();}
}
template<class T> __forceinline void constructRange(T* p,int n) throw() {
 for(int i=0;i<n;++i) {new(p+i) T;}
}
template<class T> struct MeshArray {
 T* data; int size; int capacity;
 MeshArray(T* p,int n,int c)throw():data(p),size(n),capacity(c){}
 MeshArray() throw():data(0),size(0),capacity(0x80000000){}
 __forceinline void clear() throw() { destroyRange(data,size);size=0; }
 __forceinline void release(Allocator& heap) throw() { clear(); if(!(capacity&0x80000000)) heap.freeBlock(data,(capacity&0x3fffffff)*sizeof(T)); data=0; capacity=0x80000000; }
 __forceinline ~MeshArray() throw(){release(meshHeap(hkMemoryRouter_getInstance()));}
 __forceinline void reserve(Allocator& heap,int count) throw() {
  int cap=capacity&0x3fffffff;
  if(cap<count) {int grown=2*cap; if(count>=grown)grown=count; hkArrayUtil__reserve(heap,this,grown,sizeof(T));}
 }
 __forceinline void resize(int count) throw() {
  reserve(meshHeap(hkMemoryRouter_getInstance()),count);
  int removeCount=size-count;
  T* begin=data+count;
  destroyRange(begin,removeCount);
  int addCount=count-size;
  begin=data+size;
  constructRange(begin,addCount);
  size=count;
 }
 __forceinline void resize(int count,const T& value) throw() {
  reserve(meshHeap(hkMemoryRouter_getInstance()),count);
  fillRange(data+size,count-size,value);
  size=count;
 }
 __forceinline void push(const T& value) throw() {
  Allocator& heap=meshHeap(hkMemoryRouter_getInstance());
  if(size==(capacity&0x3fffffff)) ResizeAudioStream(heap,this,sizeof(T));
  new(data+size) T(value); ++size;
 }
};
struct __declspec(align(16)) MeshVec {float x,y,z,w;};
struct MeshLink {unsigned int value; MeshLink(){} MeshLink(unsigned int v):value(v){} operator unsigned int()const{return value;} };
struct MeshFace;
struct MeshFaceChain {MeshFace* next;MeshFace* prev;MeshFaceChain(){} MeshFaceChain(const MeshFaceChain&){} MeshFaceChain& operator=(const MeshFaceChain&){return *this;} };
struct MeshFace:MeshFaceChain {
 MeshVertex* vertices[3];MeshLink links[3];MeshVec plane;int material,group,tag,unk3c,unk40;
 __forceinline MeshVertex*& corner(int n) {return vertices[n];}

};
template<class E> struct MeshEdgeCore {
 MeshFace* face;int index;
 MeshEdgeCore(){}
 MeshEdgeCore(MeshFace* f,int n):face(f),index(n){}
 MeshEdgeCore(unsigned int packed):face((MeshFace*)(packed&~3u)),index(packed&3u){}
 bool valid()const {return face!=0;}
 MeshVertex*& start()const {return face->corner(index);}
 MeshVertex*& end()const {return face->corner((9>>(index*2))&3);}
};
struct MeshEdge:MeshEdgeCore<MeshEdge> {
 MeshEdge(){}
 MeshEdge(MeshFace* f,int n):MeshEdgeCore<MeshEdge>(f,n){}
 MeshEdge(unsigned int p):MeshEdgeCore<MeshEdge>(p){}
 MeshEdge(const MeshEdge& e):MeshEdgeCore<MeshEdge>(e.face,e.index){}
};

template<> __forceinline void destroyRange<int>(int*,int)throw(){}
template<> __forceinline void constructRange<int>(int*,int)throw(){}
template<> __forceinline void destroyRange<MeshVec>(MeshVec*,int)throw(){}
template<> __forceinline void constructRange<MeshVec>(MeshVec*,int)throw(){}
template<> __forceinline void destroyRange<MeshEdge*>(MeshEdge**,int)throw(){}
template<> __forceinline void constructRange<MeshEdge*>(MeshEdge**,int)throw(){}

template<> __forceinline void MeshArray<MeshEdge*>::push(MeshEdge* const& value) throw() {
 Allocator& heap=meshHeap(hkMemoryRouter_getInstance());
 if(size==(capacity&0x3fffffff)) ResizeAudioStream(heap,this,sizeof(MeshEdge*));
 data[size++]=value;
}
template<class T,int N> struct MeshInplaceArray: MeshArray<T> {
 T storage[N];
 MeshInplaceArray() throw():MeshArray<T>(storage,0,0x80000000|N) {}
};
struct GridVertex {int unk00,unk04,x,y; unsigned int encoded;};
struct GridFace {GridFace* next;int unk04;GridVertex* vertices[3];int unk14,unk18,unk1c; unsigned int flags;};
struct GridResult {int status;GridFace* face;int side;};
struct EdgeRange {void* data;int count;int stride;};
struct ReferenceBase {virtual void identity();unsigned short allocationSize,referenceCount;
 ReferenceBase() throw():referenceCount(1){}
 __forceinline ~ReferenceBase() throw(){}
};
struct GridPool {
 void* data;int count;int capacity;GridFace* head;int used;int unk14;
 GridPool() throw():data(0),count(0),capacity(0x80000000),head(0),used(0){}
 void clearVertices() throw(); void freeVertices() throw();
 void clearFaces() throw(); void freeFaces() throw();
};
struct GridInner : ReferenceBase {
 GridPool vertices;GridPool faces;
 __forceinline ~GridInner() throw(){ faces.clearFaces();faces.freeFaces();vertices.clearVertices();vertices.freeVertices(); }
};
struct GridAux {void* data;int size;int capacity;
 GridAux() throw():data(0),size(0),capacity(0x80000000){}
 void cleanup() throw();
 __forceinline ~GridAux() throw(){cleanup();}
};
struct __declspec(align(16)) Triangulation : ReferenceBase {
 GridInner mesh;
 MeshInplaceArray<MeshEdge,64> pending;
 int unk24c;
 GridAux auxiliary;
int unk25c; int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c; int unk280; int unk284; int unk288; int unk28c; int unk290; int unk294; int unk298; int unk29c; int unk2a0; int unk2a4; int unk2a8; int unk2ac; int unk2b0; int unk2b4; int unk2b8; int unk2bc; int unk2c0; int unk2c4; int unk2c8; int unk2cc; int unk2d0; int unk2d4; int unk2d8; int unk2dc; int unk2e0; int unk2e4; int unk2e8; int unk2ec; int unk2f0; int unk2f4; int unk2f8; int unk2fc; int unk300; int unk304; int unk308; int unk30c; int unk310; int unk314; int unk318; int unk31c; int unk320; int unk324; int unk328; int unk32c; int unk330; int unk334; int unk338; int unk33c; int unk340; int unk344; int unk348; int unk34c; int unk350; int unk354; int unk358; int unk35c; int unk360; int unk364; int unk368; int unk36c; int unk370; int unk374; int unk378; int unk37c; int unk380; int unk384; int unk388; int unk38c; int unk390; int unk394; int unk398; int unk39c; int unk3a0; int unk3a4; int unk3a8; int unk3ac; int unk3b0; int unk3b4; int unk3b8; int unk3bc; int unk3c0; int unk3c4; int unk3c8; int unk3cc; int unk3d0; int unk3d4; int unk3d8; int unk3dc; int unk3e0; int unk3e4; int unk3e8; int unk3ec; int unk3f0; int unk3f4; int unk3f8; int unk3fc; int unk400; int unk404; int unk408; int unk40c; int unk410; int unk414; int unk418; int unk41c; int unk420; int unk424; int unk428; int unk42c; int unk430; int unk434; int unk438; int unk43c; int unk440; int unk444; int unk448; int unk44c; int unk450; int unk454; int unk458; int unk45c; int unk460; int unk464; int unk468; int unk46c; int unk470; int unk474; int unk478; int unk47c; int unk480; int unk484; int unk488; int unk48c; int unk490; int unk494; int unk498; int unk49c; int unk4a0; int unk4a4; int unk4a8; int unk4ac; int unk4b0; int unk4b4; int unk4b8; int unk4bc; int unk4c0; int unk4c4; int unk4c8; int unk4cc; int unk4d0; int unk4d4; int unk4d8; int unk4dc; int unk4e0; int unk4e4; int unk4e8; int unk4ec; int unk4f0; int unk4f4; int unk4f8; int unk4fc; int unk500; int unk504; int unk508; int unk50c; int unk510; int unk514; int unk518; int unk51c; int unk520; int unk524; int unk528; int unk52c; int unk530; int unk534; int unk538; int unk53c; int unk540; int unk544; int unk548; int unk54c; int unk550; int unk554; int unk558; int unk55c; int unk560; int unk564; int unk568; int unk56c; int unk570; int unk574; int unk578; int unk57c; int unk580; int unk584; int unk588; int unk58c; int unk590; int unk594; int unk598; int unk59c; int unk5a0; int unk5a4; int unk5a8; int unk5ac; int unk5b0; int unk5b4; int unk5b8; int unk5bc; int unk5c0; int unk5c4; int unk5c8; int unk5cc; int unk5d0; int unk5d4; int unk5d8; int unk5dc; int unk5e0; int unk5e4; int unk5e8; int unk5ec; int unk5f0; int unk5f4; int unk5f8; int unk5fc; int unk600; int unk604; int unk608; int unk60c; int unk610; int unk614; int unk618; int unk61c; int unk620; int unk624; int unk628; int unk62c; int unk630; int unk634; int unk638; int unk63c; int unk640; int unk644; int unk648; int unk64c; int unk650; int unk654; int unk658;
 int border;
int unk660; int unk664; int unk668; int unk66c; int unk670; int unk674; int unk678; int unk67c; int unk680; int unk684; int unk688; int unk68c; int unk690; int unk694; int unk698; int unk69c;
 MeshVec axisX,axisY,axisZ,translation;
 __forceinline Triangulation(const MeshVec& lower,const MeshVec& upper,float tolerance) throw() {
  unk24c=0;
  initialize(lower,upper,tolerance,1);
 }
 void initialize(const MeshVec&,const MeshVec&,float,int) throw();
 void project(const EdgeRange&,const MeshVec&,int,int) throw();
 GridResult find(int,int) throw();
 GridResult insert(int,int,int,GridResult*,int) throw();
 GridResult constrain(int,int,int,int,int,MeshArray<MeshEdge*>*) throw();
 int componentCount() throw();
 void triangulate() throw();
 void finish(int) throw();
 __forceinline ~Triangulation() throw(){finish(1);}
 __forceinline void transform(const MeshVec& input,MeshVec& result) const {
  const __m128& v=*(const __m128*)&input;
  __m128 xy=_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v,v,0x55),*(const __m128*)&axisY),_mm_mul_ps(_mm_shuffle_ps(v,v,0),*(const __m128*)&axisX));
  __m128 xyz=_mm_add_ps(xy,_mm_mul_ps(_mm_shuffle_ps(v,v,0xaa),*(const __m128*)&axisZ));
  _mm_store_ps(&result.x,_mm_add_ps(xyz,*(const __m128*)&translation));
 }

};
inline int gridRound(float value,int lower,int upper) {
 int rounded=(int)(value<0 ? value-0.5 : value+0.5);
 if(rounded<lower)return lower;
 if(rounded>upper)return upper;
 return rounded;
}
struct PlaneBits {int x,y,z,w;};
struct RebuildPoolBlock {MeshFace objects[32];MeshFace* freeHead;int used;};
struct RebuildPool {
 RebuildPoolBlock** blocks;int count;int capacity;MeshFace* head;int used;
 RebuildPoolBlock* newBlock() throw();
 __forceinline MeshFace* add(const MeshFace& value) throw() {
  RebuildPoolBlock* block;
  if(!count || !(block=*blocks)->freeHead) block=newBlock();
  MeshFace* result=block->freeHead;
  block->freeHead=result->next;++block->used;
  copyConstructRange(result,1,value);
 result->prev=0;result->next=head;
  if(head)head->prev=result;
  ++used;head=result;return result;
 }
};
struct RebuildMesh {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 RebuildPool facePool;
int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8;
 MeshVec* planes; int planeCount;
int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8; int unkfc;
 char flag100,dirty;
 void hkgpMesh_removePlaneTriangles(int) throw();
 void hkgpMesh_removeOrphanVertices() throw();
 void BuildTreeFromPaddedNodeBounds() throw();
 void removeGroup(int,int) throw();
 void TriangulateBoundaryGroups();
};
// Rebuilds mesh faces from boundary edges by triangulating each group's projected boundary and adding new faces to facePool.
// @fnv 0x00e21100
// src: GUESS 0x00e21100 (confidence: medium)
void RebuildMesh::TriangulateBoundaryGroups() {
 const int oldCount=planeCount;
 if(oldCount==0) return;
 MeshArray<MeshArray<MeshEdge> > edges;
 MeshArray<int> tags;
 edges.resize(oldCount);
 tags.resize(planeCount,-1);
 for(MeshFace* face=facePool.head;face;face=face->next) {
  int group=face->group;
  if(group>=0) {
   tags.data[group]=face->tag;
   for(int side=0;side<3;++side) {
    if((face->links[side]&~3u)==0 || MeshEdge(face->links[side]).face->group!=group)
     edges.data[group].push(MeshEdge(face,side));
   }
  }
 }
 int group=0;
 if(edges.size>0) {
 MeshVec lower,upper;
  _mm_store_ps(&lower.x,_mm_setr_ps(-1.0f,-1.0f,0.0f,0.0f));
  _mm_store_ps(&upper.x,_mm_setr_ps(1.0f,1.0f,0.0f,0.0f));
 EdgeRange input;input.stride=16;
 do {
  MeshArray<MeshEdge>& boundary=edges.data[group];
  MeshArray<MeshVec> positions;
  positions.resize(boundary.size);
  for(int n=0;n<boundary.size;++n) _mm_store_ps(&positions.data[n].x,_mm_load_ps((const float*)&boundary.data[n].start()->m_vContactPosition));
  Triangulation grid(lower,upper,0.0f);
  input.data=positions.data;input.count=positions.size;
  grid.project(input,planes[group],1,1);
  int n=0;
  if(positions.size>0) {int byteOffset=0;
  do {
   MeshVec transformed;grid.transform(*reinterpret_cast<const MeshVec*>(reinterpret_cast<const unsigned char*>(positions.data)+byteOffset),transformed);
   int low=grid.border,high=0x7fff-low;
   int point[2];point[0]=gridRound(transformed.x,low,high);point[1]=gridRound(transformed.y,low,high);
   GridResult found=grid.find(point[0],point[1]);
   GridResult inserted=grid.insert(point[0],point[1],1,&found,0);
   if(inserted.status==0) {
    GridVertex* vertex=inserted.face->vertices[inserted.side];
    vertex->encoded=(vertex->encoded&1)|(n<<1);
   }
   ++n;
  }while((byteOffset+=16,n)<positions.size);
  }
  for(int n=0;n<boundary.size;++n) {
   MeshEdge& edge=boundary.data[n];
   int low=grid.border;
   MeshVec a;grid.transform((const MeshVec&)boundary.data[n].start()->m_vContactPosition,a);
   GridVertex first;first.x=gridRound(a.x,low,0x7fff-low);first.y=gridRound(a.y,low,0x7fff-low);
   MeshVec b;grid.transform((const MeshVec&)edge.end()->m_vContactPosition,b);
   GridVertex last;last.x=gridRound(b.x,low,0x7fff-low);last.y=gridRound(b.y,low,0x7fff-low);
   _ReadWriteBarrier();
   MeshInplaceArray<MeshEdge*,4> constraint;
   constraint.push(&edge);
   grid.constrain(first.x,first.y,last.x,last.y,1,&constraint);
  }
  if(grid.componentCount()>1) {
   grid.triangulate();
   removeGroup(group,oldCount);
   for(GridFace* triangle=grid.mesh.faces.head;triangle;triangle=triangle->next) {
    if(triangle->flags&0x10) {
     MeshVertex* outputVertices[3];
     outputVertices[0]=boundary.data[triangle->vertices[0]->encoded>>1].start();
     outputVertices[1]=boundary.data[triangle->vertices[1]->encoded>>1].start();
     outputVertices[2]=boundary.data[triangle->vertices[2]->encoded>>1].start();
     MeshFace source;
     MeshFace* face=facePool.add(source);
     face->material=-1;_ReadWriteBarrier();
     face->links[0]=0;face->links[1]=0;face->links[2]=0;
     __m128 planeValue=_mm_load_ps(&planes[group].x);face->group=group;_mm_store_ps(&face->plane.x,planeValue);face->tag=tags.data[group];
     face->vertices[0]=outputVertices[0];face->vertices[1]=outputVertices[1];face->vertices[2]=outputVertices[2];
    }
   }
   hkMemoryRouter_getInstance();
  }
 }while(++group<edges.size);
 }
 hkgpMesh_removePlaneTriangles(oldCount);
 hkgpMesh_removeOrphanVertices();
 BuildTreeFromPaddedNodeBounds();
 dirty=0;
}

namespace fnv_00e23530 {
#include <windows.h>


struct DynamicMemoryAllocator {
    virtual void v00();
    virtual void* Alloc(unsigned int auiSize);
    virtual void Free(void* apMemory, unsigned int auiSize);
};

struct PoolHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    DynamicMemoryAllocator* m_pAllocator;
};

PoolHolder* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(DynamicMemoryAllocator* apAllocator, void* apVector, unsigned int auiElemSize);

struct FUN_00e23530_cls {
    void** m_ppData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;

    void* AllocateChainedSlotBlock();
};

// Allocates a 0xa08-byte block of 32 chained slots, appends it to m_ppData, swaps it with entry 0 when there are several blocks, and returns it.
// @fnv 0x00e23530
// src: GUESS 0x00e23530 (confidence: medium)
void* FUN_00e23530_cls::AllocateChainedSlotBlock()
{
    PoolHolder* pHolder = hkMemoryRouter_getInstance();
    DynamicMemoryAllocator* pAllocator = pHolder->m_pAllocator;
    void* pPrev = 0;
    char* pBlock = (char*)pAllocator->Alloc(0xa08);

    int iCounter = 0x1f;
    char* pCur = pBlock + 0x9b0;
    char* pHead;
    do {
        *(void**)pCur = pPrev;
        pHead = pCur;
        pPrev = pCur;
        iCounter--;
        pCur -= 0x50;
    } while (iCounter >= 0);

    *(int*)(pBlock + 0xa04) = 0;
    *(char**)(pBlock + 0xa00) = pHead;

    PoolHolder* pHolder2 = hkMemoryRouter_getInstance();
    if (m_iArrayLength == (int)(m_uCapFlags & 0x3fffffffu)) {
        ResizeAudioStream(pHolder2->m_pAllocator, this, 4);
    }

    void** pSlot = &m_ppData[m_iArrayLength];
    *pSlot = pBlock;
    if (pSlot == 0) { return 0; }
    m_iArrayLength++;
    if (m_iArrayLength > 1) {
        void* pFirst = m_ppData[0];
        m_ppData[0] = m_ppData[m_iArrayLength - 1];
        m_ppData[m_iArrayLength - 1] = pFirst;
    }
    return pBlock;
}
}  // namespace fnv_00e23530

namespace fnv_00e235d0 {
#include <windows.h>


struct DynamicMemoryAllocator {
    virtual void v00();
    virtual void* Alloc(unsigned int auiSize);
    virtual void Free(void* apMemory, unsigned int auiSize);
};

struct PoolHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    DynamicMemoryAllocator* m_pAllocator;
};

PoolHolder* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(DynamicMemoryAllocator* apAllocator, void* apVector, unsigned int auiElemSize);

struct FUN_00e235d0_cls {
    void** m_ppData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;

    void* hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_32_struct_hkContainerHeapAllocator_allocateNewPool();
};

// Allocates a 0x388-byte block of 32 chained slots, appends it to m_ppData, swaps it with entry 0 when there are several blocks, and returns it.
// @fnv 0x00e235d0
// src: HAVOK_LIB 0x00e235d0
void* FUN_00e235d0_cls::hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_32_struct_hkContainerHeapAllocator_allocateNewPool()
{
    PoolHolder* pHolder = hkMemoryRouter_getInstance();
    DynamicMemoryAllocator* pAllocator = pHolder->m_pAllocator;
    void* pPrev = 0;
    char* pBlock = (char*)pAllocator->Alloc(0x388);

    int iCounter = 0x1f;
    char* pCur = pBlock + 0x364;
    char* pHead;
    do {
        *(void**)pCur = pPrev;
        pHead = pCur;
        pPrev = pCur;
        iCounter--;
        pCur -= 0x1c;
    } while (iCounter >= 0);

    *(int*)(pBlock + 0x384) = 0;
    *(char**)(pBlock + 0x380) = pHead;

    PoolHolder* pHolder2 = hkMemoryRouter_getInstance();
    if (m_iArrayLength == (int)(m_uCapFlags & 0x3fffffffu)) {
        ResizeAudioStream(pHolder2->m_pAllocator, this, 4);
    }

    void** pSlot = m_ppData + m_iArrayLength;
    for (int k = 0; k < 1; k++) pSlot[k] = pBlock;
    m_iArrayLength++;
    if (m_iArrayLength > 1) {
        void* pFirst = m_ppData[0];
        m_ppData[0] = m_ppData[m_iArrayLength - 1];
        m_ppData[m_iArrayLength - 1] = pFirst;
    }
    return pBlock;
}
}  // namespace fnv_00e235d0

namespace fnv_00e237b0 {
inline void* __cdecl operator new(unsigned int, void* where) { return where; }
struct FUN_00e237b0_Input {
    void* unk00; void* unk04; void* unk08; void* unk0c;
    void* unk10; void* unk14; void* unk18; void* unk1c; void* entry;
};

struct FUN_00e237b0_List {
    void** data;
    unsigned int size;
    unsigned int capacityAndFlags;
};
extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
extern "C" void __cdecl ResizeAudioStream(void*, FUN_00e237b0_List*, unsigned int);
struct FUN_00e237b0_Owner {
    void* unk00;
    FUN_00e237b0_List list;
    double hkgpMeshInternals_SimpleCollector_addLeaf(FUN_00e237b0_Input* input);
};
// Appends input->entry to the owner's list, growing the list by 4 if it is at capacity, and returns 1.0.
// @fnv 0x00e237b0
// src: XBOX_PDB 0x00e237b0
double FUN_00e237b0_Owner::hkgpMeshInternals_SimpleCollector_addLeaf(FUN_00e237b0_Input* input) {
    void* entry = input->entry;
    FUN_00e237b0_List* values = &list;
    hkMemoryRouter* alloc = hkMemoryRouter_getInstance();
    if (values->size == (values->capacityAndFlags & 0x3fffffff))
        ResizeAudioStream(static_cast<void*>(alloc->m_heap), values, 4);
    void** destination = values->data + values->size;
    __assume(destination != 0);
    new (destination) void*(entry);
    ++values->size;
    return 1.0;
}
}  // namespace fnv_00e237b0

namespace fnv_00e23800 {
extern "C" void __cdecl Deallocate(void*);
extern void* __cdecl hkMemoryRouter_getInstance();

struct FUN_00e23800_Vtbl {
    void* v0;
    void* v1;
    void* v2;
    void* v3;
    void* v4;
};

extern FUN_00e23800_Vtbl DAT_010cd664;

struct Holder {
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void v4(void* a, int b);
};

struct TlsHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Holder* unk10;
};

struct FUN_00e23800_Class {
    void* vptr;
    void* unk04;
    int unk08;
    int unk0c;
    void* FUN_00e23800(int flags);
};

// Frees the unk04 buffer through the holder's v4 unless unk0c's top bit is set, resets the fields and vtable, and calls Deallocate(this) if flags & 1.
// @fnv 0x00e23800
void* FUN_00e23800_Class::FUN_00e23800(int flags)
{
    TlsHolder* holder = (TlsHolder*)hkMemoryRouter_getInstance();
    Holder* h = holder->unk10;
    int c = this->unk0c;

    this->unk08 = 0;

    if (!(c & 0x80000000))
        h->v4(this->unk04, (c & 0x3fffffff) * 4);

    this->unk04 = 0;
    this->unk0c = 0x80000000;
    this->vptr = &DAT_010cd664;

    if (flags & 1)
        Deallocate(this);

    return this;
}
}  // namespace fnv_00e23800

namespace fnv_00e23a10 {




extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

struct E23A10Element {
    E23A10Element* m_next;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct E23A10Block {
    E23A10Element m_elements[32];
    E23A10Element* m_firstFree;
    int m_iAllocatedCount;
};

struct E23A10List {
    E23A10Block** m_kBlocks;
    int m_iBlockCount;
    int m_blocksCapacity;
    void* m_pFirstNode;
    int m_iNodeCount;

    void hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_reset();
};

// Releases all E23A10Block allocations from the heap and resets the block count, first node pointer, and node count to zero.
// @fnv 0x00e23a10
// src: HAVOK_LIB 0x00e23a10
void E23A10List::hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_reset()
{
    for (int i = 0; i < m_iBlockCount; i++) {
        E23A10Block* block = m_kBlocks[i];
        hkMemoryRouter_getInstance().heap().blockFree(block, sizeof(E23A10Block));
    }
    m_iBlockCount = 0;
    m_pFirstNode = 0;
    m_iNodeCount = 0;
}
}  // namespace fnv_00e23a10

namespace fnv_00e24de0 {




hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct SpawnedBase {
    unsigned short m_uSize;
    unsigned short m_u06;
    virtual ~SpawnedBase() throw() {}
};

struct SpawnedSubA {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void Release1();
    void Release2();
};

struct SpawnedSubB {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void Release1();
    void Release2();
};

struct SpawnedObject : SpawnedBase {
    SpawnedSubA m_subA;
    SpawnedSubB m_subB;

    virtual ~SpawnedObject() throw() {
        m_subB.Release1();
        m_subB.Release2();
        m_subA.Release1();
        m_subA.Release2();
    }

    SpawnedObject* hkgpAbstractMesh_hkgpTriangulatorType_hkgpTriangulatorBase_VertexBase_hkgpTriangulatorBase_TriangleBase_hkgpTriangulatorBase_DefaultEdgeData_hkContainerHeapAllocator_hkContainerHeapAllocator_1_Edge_hkgpTriangulatorType_hkgpTriangulatorBase_VertexBase_hkgpTriangulatorBase_TriangleBase_hkgpTriangulatorBase_DefaultEdgeData_hkContainerHeapAllocator_hkContainerHeapAllocator_1_Vertex_hkgpTriangulatorType_hkgpTriangulatorBase_VertexBase_hkgpTriangulatorBase_TriangleBase_hkgpTriangulatorBase_DefaultEdgeData_hkContainerHeapAllocator_hkContainerHeapAllocator_1_Triangle_hkContainerHeapAllocator_Destroy(unsigned char acFlags) throw();
};

// Destroys the SpawnedObject, and if acFlags has bit 0 set, frees its memory via the hkMemoryRouter's hkMemoryAllocator.
// @fnv 0x00e24de0
// src: COMMUNITY 0x00e24de0
SpawnedObject* SpawnedObject::hkgpAbstractMesh_hkgpTriangulatorType_hkgpTriangulatorBase_VertexBase_hkgpTriangulatorBase_TriangleBase_hkgpTriangulatorBase_DefaultEdgeData_hkContainerHeapAllocator_hkContainerHeapAllocator_1_Edge_hkgpTriangulatorType_hkgpTriangulatorBase_VertexBase_hkgpTriangulatorBase_TriangleBase_hkgpTriangulatorBase_DefaultEdgeData_hkContainerHeapAllocator_hkContainerHeapAllocator_1_Vertex_hkgpTriangulatorType_hkgpTriangulatorBase_VertexBase_hkgpTriangulatorBase_TriangleBase_hkgpTriangulatorBase_DefaultEdgeData_hkContainerHeapAllocator_hkContainerHeapAllocator_1_Triangle_hkContainerHeapAllocator_Destroy(unsigned char acFlags) throw()
{
    this->SpawnedObject::~SpawnedObject();
    if (acFlags & 1) {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00e24de0

struct Point61 {
    int unk00, unk04, x, y;
    __forceinline int order(const Point61& b) const {
        if (x < b.x) return -1;
        if (x > b.x) return 1;
        if (y < b.y) return -1;
        if (y > b.y) return 1;
        return 0;
    }
    static __forceinline bool before(const Point61* a, const Point61* b) {
        int c = a->order(*b);
        if (c < 0) return true;
        if (c > 0) return false;
        return true;
    }
};
template<class P,class T> struct FaceCore61 {
  T* next;T* previous;P* vertices[3]; unsigned int links[3];
  __forceinline P*& vertex(int i){return vertices[i];}
  __forceinline unsigned int& link(int i){return links[i];}
};
struct Face61 : FaceCore61<Point61,Face61> {
 unsigned short constraints:3; unsigned short root:1;unsigned short region:12;unsigned short sets;
};
template<class E,class V,class T> struct Topology61 {
    T* face;
    unsigned int index;
    __forceinline Topology61() {}
    __forceinline Topology61(T* t,unsigned i):face(t),index(i) {}
    __forceinline Topology61(const unsigned long& value) { unpack(value,face,index); }
    static __forceinline void unpack(unsigned long value,T*& t,unsigned& i) {
        i=value&3; value&=~3u; t=(T*)value;
    }
    __forceinline E next() const { return E(face,(9>>(index<<1))&3); }
    __forceinline E prev() const { return E(face,(0x12>>(index<<1))&3); }
    __forceinline E linked() const { return E((unsigned long)face->link(index)); }
    __forceinline bool valid() const { return face!=0; }
    __forceinline bool unbound() const { return !linked().valid(); }
    __forceinline bool primary() const { return V::before(start(),end()) || unbound(); }
    __forceinline E canonical() const { if(primary()) return E(face,index); else return linked(); }
    __forceinline V*& start() const { return face->vertex(index); }
    __forceinline V*& end() const { return face->vertex((9>>(index<<1))&3); }
    __forceinline V*& apex() const { return face->vertex((0x12>>(index<<1))&3); }
    __forceinline void bind(const Topology61& other) const {
        face->link(index)=(unsigned long)other.face+other.index;
        if(other.valid()) other.face->link(other.index)=(unsigned long)face+index;
    }
    __forceinline E exchange() const {
        E peer=linked();
        E a=prev();
        E b=peer.prev();
        start()=b.start();
        peer.start()=a.start();
        peer.bind(a.linked());
        bind(b.linked());
        a.bind(b);
        return prev();
    }
};
static __forceinline int orientation61(int ax,int ay,int bx,int by,int cx,int cy) {
    bx-=ax;by-=ay;cx-=ax;cy-=ay;
    return -(by*cx-bx*cy);
}
static __forceinline int orientation61(const Point61* a,const Point61* b,const Point61* c) {
    return orientation61(a->x,a->y,b->x,b->y,c->x,c->y);
}
static __forceinline int inside61(int ax,int ay,int bx,int by,int cx,int cy,int dx,int dy) {
    ax-=dx;ay-=dy;bx-=dx;by-=dy;cx-=dx;cy-=dy;
    const __int64 cross0=(__int64)(ax*by-bx*ay);
    const __int64 cross1=(__int64)(bx*cy-cx*by);
    const __int64 cross2=(__int64)(cx*ay-ax*cy);
    const __int64 norm0=(__int64)(ax*ax+ay*ay);
    const __int64 norm1=(__int64)(bx*bx+by*by);
    const __int64 norm2=(__int64)(cx*cx+cy*cy);
    return -(norm0*cross1+norm1*cross2+norm2*cross0)<0;
}
struct Edge61:Topology61<Edge61,Point61,Face61> {
    typedef Topology61<Edge61,Point61,Face61> Base;
    __forceinline Edge61() {}
    __forceinline Edge61(Face61* t,unsigned i):Base(t,i) {}
    __forceinline Edge61(unsigned long value):Base(value) {}
    __forceinline Edge61(const Edge61& e):Base(e.face,e.index) {}
    __forceinline void operator=(const Edge61& e) { face=e.face;index=e.index; }
    __forceinline bool constrained() const {const Base& e=canonical(); return 0!=(e.face->constraints & (1<<e.index));}
    __forceinline void clear() const {
        const Base& e=canonical();
        e.face->constraints &= ~(1<<e.index);
    }
    __forceinline void set() const {
        const Base& e=canonical();
        const int bits=e.face->constraints;
        e.face->constraints=bits | (1<<e.index);
    }
    __forceinline int take() const {
        int result=constrained()!=0;
        if(result) clear();
        return result;
    }
    __forceinline int flippable() const {
        if(!unbound() && !constrained()) {
            Edge61 peer=linked();Edge61 a=prev();Edge61 b=peer.prev();Point61* own=start();return orientation61(a.start(),own,b.start())>0 && orientation61(b.start(),peer.start(),a.start())>0;
        }
        return 0;
    }
    __forceinline Edge61 flip() const {
        const int a=prev().take();
        const int b=linked().prev().take();
        Edge61 result=exchange();
        if(a) result.linked().next().set();
        if(b) result.next().set();
        return result;
    }
};
static __forceinline int conforms61(const Point61* a,const Point61* b,const Point61* c,const Point61* p) {
    return !inside61(a->x,a->y,b->x,b->y,c->x,c->y,p->x,p->y);
}
static __forceinline int conforms61(const Edge61& e) {
    return e.unbound() || e.constrained() || conforms61(e.apex(),e.start(),e.end(),e.linked().apex());
}
struct Mesh61 {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    int unk20,unk24,unk28,unk2c,unk30;
    Face61* first;
    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_conformEdges();
};
// Iteratively flips flippable non-conforming edges until the mesh reaches a stable state.
// @fnv 0x00e24fa0
// src: HAVOK_LIB 0x00e24fa0
void Mesh61::hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_conformEdges() {
    bool changed;
    do {
        changed=false;
        for(Face61* t=first;t;t=t->next) {
            for(int i=0;i<3;++i) {
                Edge61 edge(t,i);
                if(!conforms61(edge) && edge.flippable()) {
                    edge=edge.flip();
                    changed=true;
                }
            }
        }
    } while(changed);
}

struct PointSol {
    int unk00, unk04;
    int x, y;
    __forceinline int compare(const PointSol& b) const {
        if(x<b.x) return -1;
        if(x>b.x) return 1;
        if(y<b.y) return -1;
        if(y>b.y) return 1;
        return 0;
    }
};
struct FaceSol {
    int unk00, unk04;
    PointSol* vertices[3];
    unsigned int links[3];
    unsigned short flags:3;
    __forceinline PointSol*& vertex(int i) { return vertices[i]; }
    __forceinline unsigned int& link(int i) { return links[i]; }
};
static __forceinline bool orderedSol(const PointSol* a,const PointSol* b) { const int c=a->compare(*b); if(c<0) return true; if(c>0) return false; return true; }
struct S00e25570_CBool {
    char m_cBooleanValue;
    __forceinline S00e25570_CBool(int b) : m_cBooleanValue((char)b) {}
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
};
struct EdgeSol;
template<class D> struct EdgeBaseSol {
    FaceSol* face;
    unsigned int index;
    EdgeBaseSol() {}
    EdgeBaseSol(FaceSol* f,unsigned int i):face(f),index(i){}
    static __forceinline void decode(unsigned int p,FaceSol*& f,unsigned int& i) { i=p&3; p&=~3u; f=(FaceSol*)p; }
    EdgeBaseSol(const unsigned int& p) { decode(p,face,index); }
    __forceinline D next() const { return D(face,(9>>(2*index))&3); }
    __forceinline D prev() const { return D(face,(0x12>>(2*index))&3); }
    __forceinline D link() const { return D(face->link(index)); }
    __forceinline PointSol*& start() const { return face->vertex(index); }
    __forceinline PointSol*& end() const { return face->vertex((9>>(2*index))&3); }
    __forceinline PointSol*& apex() const { return face->vertex((0x12>>(2*index))&3); }
    __forceinline bool valid() const { return face!=0; }
    __forceinline bool boundary() const { return !link().valid(); }
    __forceinline bool master() const { return orderedSol(start(),end()) || boundary(); }
    __forceinline D primary() const {
        if(master()) return D(face,index);
        return link();
    }
    __forceinline void bind(const D& b) const {
        face->link(index)=(unsigned int)b.face+b.index;
        if(b.face) b.face->link(b.index)=(unsigned int)face+index;
    }
    __forceinline D rotateDiagonal() const {
        D other=link(), before=prev(), across=other.prev();
        start()=across.start();
        other.start()=before.start();
        other.bind(before.link());
        bind(across.link());
        before.bind(across);
        return prev();
    }
};
static __forceinline int orientXY(int ox,int oy,int ax,int ay,int bx,int by) {
    ax-=ox;ay-=oy;bx-=ox;by-=oy;
    return -(ay*bx-ax*by);
}
static __forceinline int orientSol(const PointSol* o,const PointSol* a,const PointSol* b) {
    return orientXY(o->x,o->y,a->x,a->y,b->x,b->y);
}
struct EdgeSol:EdgeBaseSol<EdgeSol> {
    typedef EdgeBaseSol<EdgeSol> Base;
    EdgeSol() {}
    EdgeSol(FaceSol* f,unsigned int i):Base(f,i){}
    EdgeSol(unsigned int p):Base(p){}
    EdgeSol(const EdgeSol& e):Base(e.face,e.index){}
    __forceinline void operator=(const EdgeSol& e) { face=e.face; index=e.index; }
    __forceinline bool flagged() const {
        const EdgeSol& p=primary();
        const int x=p.face->flags & (1u<<p.index); const int r=x; return !(0==(r));
    }
    __forceinline bool flaggedNew() const {
        const EdgeSol& p=primary();
        const int x=p.face->flags & (1u<<p.index); const int& r=x; return (char)r!=0;
    }
    __forceinline bool flaggedV() const {
        EdgeSol p=primary();
        return S00e25570_CBool(((volatile FaceSol*)p.face)->flags & (1<<p.index));
    }
    __forceinline void setFlag() const {
        const EdgeSol& p=primary();
        int old=p.face->flags;
        p.face->flags=old|(1<<p.index);
    }
    __forceinline void clearFlag() const {
        const EdgeSol& p=primary();
        int old=p.face->flags;
        p.face->flags=old&~(1<<p.index);
    }
    __forceinline int takeFlag() const {
        int result=flaggedNew();
        if(result) clearFlag();
        return result;
    }
    __forceinline bool masterOf(PointSol* a,PointSol* b) const { return orderedSol(a,b) || boundary(); }
    __forceinline EdgeSol primaryOf(PointSol* a,PointSol* b) const {
        if(masterOf(a,b)) return EdgeSol(face,index);
        return link();
    }
    __forceinline int takeFlagV() const {
        PointSol* b=end(); PointSol* a=start();
        int result;
        { EdgeSol p=primaryOf(a,b); result=S00e25570_CBool(((volatile FaceSol*)p.face)->flags & (1<<p.index)); }
        if(result) { EdgeSol p=primaryOf(a,b); int old=p.face->flags; p.face->flags=old&~(1<<p.index); }
        return result;
    }
    __forceinline int takeFlagW() const {
        PointSol* b=end(); PointSol* a=start();
        int result;
        { EdgeSol p=primaryOf(a,b); result=S00e25570_CBool(((volatile FaceSol*)p.face)->flags & (1<<p.index)); }
        if(result) { EdgeSol p=primaryOf(start(),b); int old=p.face->flags; p.face->flags=old&~(1<<p.index); }
        return result;
    }
    __forceinline int takeFlagOld() const {
        int result=flaggedV();
        if(result) clearFlag();
        return result;
    }
    __forceinline int flippable() const {
        if(boundary()||flagged()) return 0;
        EdgeSol other=link(), before=prev(), across=other.prev();
        return orientSol(before.start(),start(),across.start())>0 &&
               orientSol(across.start(),other.start(),before.start())>0;
    }
    __forceinline EdgeSol flip() const {
        int first=prev().takeFlagV();
        int second=link().prev().takeFlag();
        EdgeSol result=rotateDiagonal();
        if(first) result.link().next().setFlag();
        if(second) result.next().setFlag();
        return result;
    }
};
static __forceinline int circleSol(int ax,int ay,int bx,int by,int cx,int cy,int ox,int oy) {
    ax-=ox; ay-=oy;
    bx-=ox; by-=oy;
    cx-=ox; cy-=oy;
    __int64 ab=(ax*by-bx*ay),bc=(bx*cy-cx*by),ca=(cx*ay-ax*cy);
    __int64 aa=(ax*ax+ay*ay),bb=(bx*bx+by*by),cc=(cx*cx+cy*cy);
    return -(aa*bc+bb*ca+cc*ab)<0;
}
static __forceinline int circlePointsSol(const PointSol* a,const PointSol* b,const PointSol* c,const PointSol* o) {
    return circleSol(a->x,a->y,b->x,b->y,c->x,c->y,o->x,o->y);
}
static __forceinline int needsFlipSol(const EdgeSol& e) { if(e.boundary()||e.flagged()) return 0; return circlePointsSol(e.apex(),e.start(),e.end(),e.link().apex()); }
struct StackSol {
    EdgeSol* data;
    int size,cap;
    __forceinline EdgeSol& back() { return data[size-1]; }
    __forceinline void popBack() { --size; }
    __forceinline void push(const EdgeSol& value) {
        hkMemoryRouter& r=hkMemoryRouter_getInstance();
        if(size==(cap&0x3fffffff)) ResizeAudioStream(reinterpret_cast<Allocator*>(r.m_heap),this,8);
        new(data+size) EdgeSol(value);
        ++size;
    }
};
struct MeshSol {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    StackSol stack;
    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_flushConform();
};
// Pops edges from the stack and flips flippable diagonals, pushing the resulting adjacent edges back until the stack is empty.
// @fnv 0x00e25570
// src: HAVOK_LIB 0x00e25570
void MeshSol::hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_flushConform() {
    do {
        EdgeSol e=stack.back();
        stack.popBack();
        if(needsFlipSol(e) && e.flippable()) {
            e=e.flip();
            stack.push(e.next());
            stack.push(e.link().prev());
        }
    } while(stack.size>0);
}

namespace fnv_00e27400 {
struct FUN_00e25f00_ {
    void FUN_00e25f00(int value);
};

struct FUN_00e27400_interface {
    virtual void FUN_00e27400_virtual_0();
    virtual void FUN_00e27400_virtual_1();
    virtual void FUN_00e27400_virtual_2(void* value, int flag);
};

struct FUN_00e27400_holder : FUN_00e27400_interface {
    int unk004;
    int unk008;
    int unk00c;
    FUN_00e27400_interface* unk010;
};

extern FUN_00e27400_holder* hkMemoryRouter_getInstance();

struct FUN_00e27400_layout {
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
};

struct FUN_00e27400_ : FUN_00e27400_layout {
    FUN_00e25f00_* unk24c;
    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_destroyEdgeDataHashTable();
};

// If unk24c is set, calls FUN_00e25f00 on it, passes it to FUN_00e27400_virtual_2, then nulls the pointer.
// @fnv 0x00e27400
// src: HAVOK_LIB 0x00e27400
void FUN_00e27400_::hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_destroyEdgeDataHashTable()
{
    if (this->unk24c != 0) {
        FUN_00e27400_interface* object = hkMemoryRouter_getInstance()->unk010;
        this->unk24c->FUN_00e25f00(0);
        object->FUN_00e27400_virtual_2(this->unk24c, 0x10);
        this->unk24c = 0;
    }
}
}  // namespace fnv_00e27400

extern char DAT_010eaf20[];
void __cdecl __debugbreak();

struct Tri14
{
    Tri14* m_next;
    int unk04;
    void* m_kVertices[3];
    unsigned int m_ppLinks[3];
};

struct Edge14
{
    Tri14* m_pkTriangle;
    unsigned int m_uiEdgeIndex;

    __forceinline void bind(Edge14 other) const {
        m_pkTriangle->m_ppLinks[m_uiEdgeIndex] = (unsigned int)other.m_pkTriangle + other.m_uiEdgeIndex;
        if (other.m_pkTriangle) {
            other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = m_uiEdgeIndex + (unsigned int)m_pkTriangle;
        }
    }
};

struct Mesh14
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
    Tri14* m_head2c;

    bool hkgpMesh_bindEdge(Edge14 edge, bool flag, bool report);
};

// Links an edge to a matching triangle in the mesh, or reports an error if no match is found.
// @fnv 0x00e14bd0
// src: HAVOK_LIB 0x00e14bd0
bool Mesh14::hkgpMesh_bindEdge(Edge14 edge, bool abSkipLinked, bool report)
{
    unsigned int index = edge.m_uiEdgeIndex;
    Tri14* tri = edge.m_pkTriangle;

    if ((tri->m_ppLinks[index] & ~3u) == 0)
    {
        void* v = tri->m_kVertices[index];
        void* vNext = tri->m_kVertices[(9 >> (index << 1)) & 3];

        for (Tri14* node = m_head2c; node; node = node->m_next)
        {
            for (int i = 0; i < 3; i++)
            {
                if (abSkipLinked && (node->m_ppLinks[i] & ~3u))
                    continue;
                if (node->m_kVertices[(9 >> (i << 1)) & 3] != v)
                    continue;
                if (node->m_kVertices[i] != vNext)
                    continue;

                node->m_ppLinks[i] = index + (unsigned int)tri;
                if (edge.m_pkTriangle)
                    edge.m_pkTriangle->m_ppLinks[edge.m_uiEdgeIndex] = i + (unsigned int)node;
                return true;
            }
        }

        if (report)
        {
            unsigned int buf[0x80];
            CharBuffer stream;
            stream.FUN_00cb1600((char*)buf, 0x200);
            stream.ProcessAndReturnValue_00cc01c0(DAT_010eaf20);
            if (DAT_01268360->Report(3, 0x1fb636c8, (char*)buf, DAT_010eaeb4, 0xb41))
                __debugbreak();
            stream.FUN_00cc00e0();
        }

        return false;
    }

    return true;
}

extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_sub_ps(__m128,__m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern __m128 DAT_010ec7f0;
extern float DAT_010718c0;
extern const float DAT_01011d78;
extern void* DAT_010eaf00[];
extern void* DAT_010cd664[];

struct __declspec(align(16)) ClipScalar160 {
    __m128 quad;
    __forceinline ClipScalar160() {}
    __forceinline ClipScalar160(__m128 v):quad(v) {}
    __forceinline operator __m128() const {return quad;}
    __forceinline float getReal() const {float f;_mm_store_ss(&f,quad);return f;}
};
struct __declspec(align(16)) ClipVertex160 {
    union { __m128 value; struct {float x,y,z,w;}; };
    __forceinline ClipVertex160() {}
    __forceinline __m128 get() const {return value;}
    __forceinline void set(__m128 v) {value=v;}
    void setTransformedPos_00c7f640(const void*,const ClipVertex160*);
};
struct ClipTriangle160 {
    ClipVertex160 vertices[3];
    __forceinline ClipTriangle160() {}
    __forceinline ClipTriangle160(const ClipVertex160& a,const ClipVertex160& b,const ClipVertex160& c) {
        vertices[0].set(a.get()); vertices[1].set(b.get()); vertices[2].set(c.get());
    }
};
struct TriangleIndex {unsigned int a,b,c,material;};

template<class T> struct ClipBufferBase {
    T* data; int count; unsigned int capacity;
    __forceinline ClipBufferBase():data(0),count(0),capacity(0x80000000u) {}
    __forceinline T& operator[](int i) {return data[i];}
    __forceinline int size() const {return count;}
    void AppendItems(Allocator*,const ClipTriangle160*,int);
};
template<class T> struct Buffer:ClipBufferBase<T> {};

struct OutputMesh {Buffer<ClipVertex160> vertices;Buffer<TriangleIndex> triangles;};
struct SourceMesh {Buffer<ClipVertex160> vertices;Buffer<TriangleIndex> triangles;};
extern void __cdecl ResizeAudioStream(Allocator*,void*,int);
extern void __cdecl hkAabbUtil_calcAabb_00cbeb70(const ClipTriangle160*,int,ClipVertex160*);
extern void __cdecl AabbTree_ProcessIfPresent_00d1d570(void*,const ClipVertex160*,void*);
extern int __cdecl hkGeometryProcessing_checkTrianglesIntersection(const ClipTriangle160*,const ClipVertex160*);
struct CollisionVertex {int unk00,unk04,unk08,unk0c;ClipVertex160 point;};
struct CollisionTriangle {
    int unk00,unk04;CollisionVertex* a;CollisionVertex* b;CollisionVertex* c;
    int unk14,unk18,unk1c;ClipVertex160 plane;
};
struct ContactList {
    void** vtable; CollisionTriangle** data; int count; unsigned int capacity;
    __forceinline ContactList():vtable(DAT_010eaf00),data(0),count(0),capacity(0x80000000u) {}
};
struct CollisionWorld {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    int world;
    void ClipSourceMeshAgainstCollisionTriangles(const void*,SourceMesh*,const void*,OutputMesh*);
};
static __forceinline float ClipReal160(const ClipScalar160& v) {return v.getReal();}
static __forceinline __m128 DotPlane160(const ClipVertex160& plane,const ClipVertex160& p,__m128 planeW) {
    ClipVertex160 productVector;
    productVector.set(plane.get());
    productVector.set(_mm_mul_ps(productVector.get(),p.get()));
    __m128 product=productVector.get();
    __m128 z=_mm_shuffle_ps(product,product,0xaa);
    __m128 y=_mm_shuffle_ps(product,product,0x55);
    return _mm_add_ps(_mm_add_ss(z,planeW),_mm_add_ss(y,product));
}
static __forceinline __m128 Distance160(const ClipVertex160& a,const ClipVertex160& b) {
    __m128 d=_mm_sub_ps(a.get(),b.get());
    __m128 sq=_mm_mul_ps(d,d);
    __m128 y=_mm_add_ss(_mm_shuffle_ps(sq,sq,0x55),sq);
    __m128 z=_mm_add_ss(_mm_shuffle_ps(sq,sq,0xaa),y);
    return _mm_sqrt_ss(z);
}
static __forceinline __m128 Intersection160(const ClipVertex160& a,const ClipVertex160& b,__m128 da,__m128 db) {
    __m128 t=_mm_div_ss(da,_mm_sub_ss(da,db));
    t=_mm_shuffle_ps(t,t,0);
    return _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0,t),a.get()),_mm_mul_ps(t,b.get()));
}
template<class T> static __forceinline void Reserve160(Buffer<T>& b,int count,int elementSize) {
    Allocator& allocator=meshHeap(hkMemoryRouter_getInstance());
    int cap=b.capacity&0x3fffffff;
    if(cap<count) {
        int next=cap*2;
        if(count<next) count=next;
        hkArrayUtil__reserve((int)&allocator,&b,count,elementSize);
    }
}
static __forceinline void AppendTriangle160(Buffer<ClipTriangle160>& b,const ClipTriangle160& value) {
    hkMemoryRouter& router=hkMemoryRouter_getInstance();
    if(b.count==(int)(b.capacity&0x3fffffff)) ResizeAudioStream(reinterpret_cast<Allocator*>(router.m_heap),&b,48);
    ClipTriangle160* destination=((ClipTriangle160*)b.data)+b.count;
    if(destination) *destination=value;
    ++b.count;
}
template<class T> static __forceinline void Release160(Buffer<T>& b,int elementSize) {
    Allocator& allocator=meshHeap(hkMemoryRouter_getInstance());
    b.count=0;
    if(!(b.capacity&0x80000000u)) allocator.freeBlock(b.data,(b.capacity&0x3fffffff)*elementSize);
    b.data=0;b.capacity=0x80000000u;
}
// Clips the input source mesh against the collision world's triangles and writes the resulting clipped vertices and triangle indices to the output mesh.
// @fnv 0x00e160f0
// src: GUESS 0x00e160f0 (confidence: medium)
void CollisionWorld::ClipSourceMeshAgainstCollisionTriangles(const void* inputTransform,SourceMesh* apSourceMesh,const void* outputTransform,OutputMesh* apOutputMesh) {
    ClipScalar160 epsilon=_mm_load_ss(&DAT_010718c0);
    Buffer<ClipTriangle160> original,generated;
    ContactList contacts;
    for(int faceIndex=0;faceIndex<apSourceMesh->triangles.size();++faceIndex) {
        original.count=0;contacts.count=0;
        ClipTriangle160 triangle;
        int iTriOffset=faceIndex*16;
        triangle.vertices[0].setTransformedPos_00c7f640(inputTransform,&apSourceMesh->vertices[((TriangleIndex*)((char*)apSourceMesh->triangles.data+iTriOffset))->a]);
        triangle.vertices[1].setTransformedPos_00c7f640(inputTransform,&apSourceMesh->vertices[((TriangleIndex*)((char*)apSourceMesh->triangles.data+iTriOffset))->b]);
        triangle.vertices[2].setTransformedPos_00c7f640(inputTransform,&apSourceMesh->vertices[((TriangleIndex*)((char*)apSourceMesh->triangles.data+iTriOffset))->c]);
        AppendTriangle160(original,triangle);
        ClipVertex160 bounds[2];
        hkAabbUtil_calcAabb_00cbeb70(&triangle,3,bounds);
        __m128 vBoundMax=bounds[1].value;
        __m128 expansion=_mm_load_ss(&DAT_01011d78);
        expansion=_mm_shuffle_ps(expansion,expansion,0);
        bounds[1].set(_mm_add_ps(expansion,vBoundMax));
        bounds[0].set(_mm_sub_ps(bounds[0].get(),expansion));
        AabbTree_ProcessIfPresent_00d1d570(&world,bounds,&contacts);
        for(int hitIndex=0;hitIndex<contacts.count;++hitIndex) {
            CollisionTriangle* hit=contacts.data[hitIndex];
            ClipVertex160 other[3]={hit->a->point,hit->b->point,hit->c->point};
            if(!hkGeometryProcessing_checkTrianglesIntersection(&triangle,other)) {
                --contacts.count;
                if(contacts.count!=hitIndex) contacts.data[hitIndex]=contacts.data[contacts.count];
                --hitIndex;
            }
        }
        for(int hitIndex=0;hitIndex<contacts.count;++hitIndex) {
            CollisionTriangle* hit=contacts.data[hitIndex];
            ClipVertex160 plane=hit->plane;
            for(int pieceIndex=0;pieceIndex<original.size();++pieceIndex) {
                __m128 planeW=_mm_shuffle_ps(plane.get(),plane.get(),0xff);
                ClipTriangle160& piece=original[pieceIndex];
                ClipVertex160 pointA,pointB,pointC;
                ClipScalar160 distances[3];
                distances[0]=DotPlane160(plane,piece.vertices[0],planeW);
                distances[1]=DotPlane160(plane,piece.vertices[1],planeW);
                distances[2]=DotPlane160(plane,piece.vertices[2],planeW);
                pointA.set(piece.vertices[0].get());
                pointB.set(piece.vertices[1].get());
                pointC.set(piece.vertices[2].get());
                for(int v=0;v<3;++v) {
                    float magnitude=(float)fabs(ClipReal160(distances[v]));
                    if(magnitude<=ClipReal160(epsilon)) distances[v]=_mm_load_ss(&DAT_01011d78);
                }
                ClipVertex160 intersections[3];
                intersections[0].set(Intersection160(pointA,pointB,distances[0],distances[1]));
                intersections[1].set(Intersection160(pointB,pointC,distances[1],distances[2]));
                intersections[2].set(Intersection160(pointC,pointA,distances[2],distances[0]));
                int mask=(ClipReal160(_mm_mul_ss(distances[0],distances[1]))<0.0f?1:0)
                    +(ClipReal160(_mm_mul_ss(distances[1],distances[2]))<0.0f?2:0)
                    +(ClipReal160(_mm_mul_ss(distances[2],distances[0]))<0.0f?4:0);
                unsigned long bit=1;
                for(int edge=0;edge<3;++edge,bit=(bit<<1)|((unsigned int)bit>>31)) {
                    if(!(mask&bit)) continue;
                    if(ClipReal160(Distance160(intersections[edge],pointA))<=ClipReal160(epsilon)
                        ||ClipReal160(Distance160(intersections[edge],pointB))<=ClipReal160(epsilon)
                        ||ClipReal160(Distance160(intersections[edge],pointC))<=ClipReal160(epsilon)
                        ||(float)fabs(ClipReal160(DotPlane160(plane,intersections[edge],planeW)))>ClipReal160(epsilon))
                        mask&=~bit;
                }
                switch(mask) {
                case 1:
                    AppendTriangle160(generated,ClipTriangle160(intersections[0],pointC,pointA));
                    piece.vertices[0].set(intersections[0].get());
                    break;
                case 2:
                    AppendTriangle160(generated,ClipTriangle160(intersections[1],pointA,pointB));
                    piece.vertices[1].set(intersections[1].get());
                    break;
                case 4:
                    AppendTriangle160(generated,ClipTriangle160(intersections[2],pointB,pointC));
                    piece.vertices[2].set(intersections[2].get());
                    break;
                case 3:
                    AppendTriangle160(generated,ClipTriangle160(intersections[0],intersections[1],pointA));
                    AppendTriangle160(generated,ClipTriangle160(intersections[1],piece.vertices[2],piece.vertices[0]));
                    piece.vertices[0].set(intersections[0].get());
                    piece.vertices[2].set(intersections[1].get());
                    break;
                case 5:
                    AppendTriangle160(generated,ClipTriangle160(intersections[2],intersections[0],pointC));
                    AppendTriangle160(generated,ClipTriangle160(intersections[0],piece.vertices[1],piece.vertices[2]));
                    piece.vertices[1].set(intersections[0].get());
                    piece.vertices[2].set(intersections[2].get());
                    break;
                case 6:
                    AppendTriangle160(generated,ClipTriangle160(intersections[1],intersections[2],pointB));
                    AppendTriangle160(generated,ClipTriangle160(intersections[2],piece.vertices[0],piece.vertices[1]));
                    piece.vertices[0].set(intersections[2].get());
                    piece.vertices[1].set(intersections[1].get());
                    break;
                }
            }
            int generatedCount=generated.count;
            const ClipTriangle160* generatedData=(const ClipTriangle160*)generated.data;
            Allocator& heap=meshHeap(hkMemoryRouter_getInstance());
            original.AppendItems(&heap,generatedData,generatedCount);
            generated.count=0;
        }
        Reserve160(apOutputMesh->vertices,apOutputMesh->vertices.count+3*original.count,16);
        Reserve160(apOutputMesh->triangles,apOutputMesh->triangles.count+original.count,16);
        int i=0;
        if(i<original.size()) {
        int iVertexOffset=0;
        do {
            unsigned long base=apOutputMesh->vertices.count;
            Allocator& vertexHeap=meshHeap(hkMemoryRouter_getInstance());
            int oldCount=apOutputMesh->vertices.count;
            long needed=oldCount+3;
            int capacity=apOutputMesh->vertices.capacity&0x3fffffff;
            if(capacity<needed) {
                int doubled=capacity*2;
                if(needed<doubled) needed=doubled;
                hkArrayUtil__reserve((int)&vertexHeap,&apOutputMesh->vertices,needed,16);
            }
            ClipVertex160* destination=((ClipVertex160*)apOutputMesh->vertices.data)+oldCount;
            apOutputMesh->vertices.count+=3;
            destination[0].setTransformedPos_00c7f640(outputTransform,&((ClipVertex160*)((char*)original.data+iVertexOffset))[0]);
            destination[1].setTransformedPos_00c7f640(outputTransform,&((ClipVertex160*)((char*)original.data+iVertexOffset))[1]);
            destination[2].setTransformedPos_00c7f640(outputTransform,&((ClipVertex160*)((char*)original.data+iVertexOffset))[2]);
            hkMemoryRouter& router=hkMemoryRouter_getInstance();
            Buffer<TriangleIndex>& outputTriangles=apOutputMesh->triangles;
            if(outputTriangles.count==(int)(outputTriangles.capacity&0x3fffffff))
                ResizeAudioStream(reinterpret_cast<Allocator*>(router.m_heap),&outputTriangles,16);
            TriangleIndex* index=((TriangleIndex*)outputTriangles.data)+outputTriangles.count++;
            index->a=base;index->b=base+1;index->c=base+2;index->material=0xffffffffu;
            ++i;iVertexOffset+=48;
        } while(i<original.size());
        }
    }
    Allocator& allocator=meshHeap(hkMemoryRouter_getInstance());
    contacts.count=0;
    if(!(contacts.capacity&0x80000000u)) allocator.freeBlock(contacts.data,(contacts.capacity&0x3fffffff)*4);
    contacts.data=0;contacts.capacity=0x80000000u;contacts.vtable=DAT_010cd664;
    Release160(generated,48);
    Release160(original,48);
}

extern "C" __m128 _mm_load_ps1(float const* p);



struct S_00e16e50_Array {
    MeshPacketCallLocal_00e16e50* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void reserve(Allocator& a, int n) {
        int cap = m_cap & 0x3fffffff;
        if (cap < n) {
            int c2 = cap * 2;
            hkArrayUtil__reserve((int)&a, this, (n < c2) ? c2 : n, 16);
        }
    }
    __forceinline void ClearAndRelease(Allocator& a) {
        m_iElementCount = 0;
        if ((m_cap & 0x80000000) == 0)
            a.freeBlock(m_data, (m_cap & 0x3fffffff) * 16);
    }
};
struct S_00e16e50_Local : S_00e16e50_Array {
    MeshPacketCallLocal_00e16e50 buf[32];
    S_00e16e50_Local() { m_data = buf; m_iElementCount = 0; m_cap = 0x80000020; }
};

extern double DAT_01011588;

static __forceinline float realSqrt(float x) { return (float)sqrt((double)x); }
static __forceinline float copyReal(const float& x) { return x; }


struct S_00e16e50 {
    double ProcessAndReturnValue_00e13660(MeshPacketCallLocal_00e16e50* in, MeshPacketCallLocal_00e16e50* out, bool* flag);
    float hkgpMesh_projectPointOnSurface(float scale, MeshPacketCallLocal_00e16e50* v, int n);
};

// Repeats n times updating v by a scaled correction and saving each result, then sets v to the average of the saved vectors and returns a signed length.
// @fnv 0x00e16e50
// src: XBOX_PDB 0x00e16e50
float S_00e16e50::hkgpMesh_projectPointOnSurface(float scale, MeshPacketCallLocal_00e16e50* v, int n)
{
    bool flag = false;
    MeshPacketCallLocal_00e16e50 tmp0;
    MeshPacketCallLocal_00e16e50 tmp = tmp0;
    S_00e16e50_Local loc;
    loc.reserve(meshHeap(hkMemoryRouter_getInstance()), n);
    for (int i = 0; i < n; i++) {
        float r0 = (float)sqrt(ProcessAndReturnValue_00e13660(v, &tmp, &flag));
        float s; (volatile float&)s = r0;
        if (flag) s = -s;
        float f = (float)((scale - s) * DAT_01011588);
        __m128 b = _mm_load_ps1(&f);
        __m128 r = _mm_add_ps(_mm_mul_ps(b, *(__m128*)&tmp), *(__m128*)v);
        *(__m128*)v = r;
        MeshPacketCallLocal_00e16e50* p = loc.m_data + loc.m_iElementCount;
        for (int k = 0; k < 1; k++) ((__m128*)p)[k] = r;
        loc.m_iElementCount++;
    }
    *(__m128*)v = *(__m128*)&DAT_01267e30;
    for (int i=0; i<loc.m_iElementCount; ++i) { __m128 a=_mm_load_ps(&v->x); __m128 b=_mm_load_ps(&loc.m_data[i].x); _mm_store_ps(&v->x,_mm_add_ps(b,a)); }
    float inv = 1.0f / loc.m_iElementCount;
    __m128 vv = *(__m128*)v;
    __m128 x = _mm_load_ss(&inv);
    __m128 y = x;
    *(__m128*)v = _mm_mul_ps(_mm_shuffle_ps(y, x, 0), vv);
    float r0 = (float)sqrt(ProcessAndReturnValue_00e13660(v, &tmp, &flag));
        float s; (volatile float&)s = r0;
        if (flag) s = -s;
    loc.ClearAndRelease(meshHeap(hkMemoryRouter_getInstance()));
    return s;
}

extern "C" {
__m128 _mm_sub_ps(__m128 a, __m128 b);
__m128 _mm_load_ss(const float* p);
__m128 _mm_sqrt_ss(__m128 a);
__m128 _mm_move_ss(__m128 a, __m128 b);
__m128 _mm_set_ss(float);
}
struct DistanceScalar {
    union {__m128 value; float lanes[4];};
    DistanceScalar() {}
    DistanceScalar(__m128 v):value(v) {}
    operator const __m128&() const { return value; }
    DistanceScalar& operator=(float f) { value=_mm_load_ss(&f); return *this; }
};
struct Bits4 { unsigned a,b,c,d; };
struct __declspec(align(16)) PositionBits:Bits4 { __m128 get() const {return reinterpret_cast<const __m128&>(*this);} };
typedef PositionBits SplitPoint;
struct SplitVertex:ListLinks<SplitVertex> { int unk08,unk0c; SplitPoint position; };
struct PartSplitFace:ListLinks<PartSplitFace> { SplitVertex* vertices[3]; int links[3]; SplitPoint m_20; int m_30;
    const SplitPoint& point(int i) const { return vertices[i]->position; }
};
struct SplitPair { int first, second; };
struct SplitPairs { SplitPair* data; int size; int capacity; SplitPairs():data(0),size(0),capacity(0x80000000) {} };
struct SplitMapEntry { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c; PartSplitFace* triangle; };
struct SplitMap { SplitMapEntry* ComputeValue_00d9a4c0(int); };
struct PartSplitEdge { PartSplitFace* triangle; unsigned int index; PartSplitEdge(PartSplitFace* t, unsigned int i):triangle(t),index(i) {}  __forceinline PartSplitEdge prev() const { return PartSplitEdge(triangle,(0x12>>(index*2))&3); } };
struct SplitHull {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    int tree40,unk44,unk48,unk4c,unk50,unk54,unk58;
    SplitMap map5c;
    int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
    int unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c;
    int unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc;
    int unkc0,unkc4,unkc8,unkcc,unkd0,unkd4,unkd8,unkdc;
    int unke0,unke4,unke8,unkec,unkf0,unkf4,unkf8,unkfc;
    char flag100,flag101;
    void BuildTreeFromPaddedNodeBounds();
    PartSplitEdge ProcessAndReturnValue_00e191a0(PartSplitEdge, const __m128&, int);
    void SplitOverlappingTaggedFaces(int firstTag, int secondTag);
};
void __cdecl Object_CollectOverlappingLeafPairs(void*,void*,SplitPairs*);
extern double DAT_01032980;
extern char str_010eb080[];
__forceinline float splitReal(__m128 v) { float f; _mm_store_ss(&f,v); return f; }
__forceinline __m128 splitPosition(const SplitVertex* v) { return v->position.get(); }
__forceinline __m128 splitSum3(__m128 v) {
    __m128 y = _mm_shuffle_ps(v,v,0x55);
    __m128 z = _mm_shuffle_ps(v,v,0xaa);
    y = _mm_add_ss(y,v);
    return _mm_add_ss(z,y);
}
__forceinline float splitLength(__m128 v) {
    __m128 sum = splitSum3(_mm_mul_ps(v,v));
    return splitReal(_mm_sqrt_ss(sum));
}
__forceinline DistanceScalar splitPlaneDot(__m128 point, __m128 plane) {
    const __m128& product = _mm_mul_ps(point,plane);
    __m128 y = _mm_add_ss(_mm_shuffle_ps(product,product,0x55),product);
    __m128 z = _mm_add_ss(_mm_shuffle_ps(product,product,0xaa),_mm_shuffle_ps(plane,plane,0xff));
    return _mm_add_ps(z,y);
}
__forceinline void splitCopy(Components& out,const SplitVertex* v) {
    out = *reinterpret_cast<const Components*>(&v->position);
}
extern "C" int __cdecl hkGeometryProcessing_checkTrianglesIntersection(const SplitPoint*,const SplitPoint*);
__forceinline int overlapFaces(const PartSplitFace* a,const PartSplitFace* b) {
    SplitPoint ta[3]={a->point(0),a->point(1),a->point(2)};
    SplitPoint tb[3]={b->point(0),b->point(1),b->point(2)};
    return hkGeometryProcessing_checkTrianglesIntersection(ta,tb);
}
__forceinline void setMagnitude(volatile float& out,float value) { out=(float)fabs((double)value); }
__forceinline float splitArea(const SplitPoint& v0,const SplitPoint& v1,const SplitPoint& v2) {
            const __m128& base=reinterpret_cast<const __m128&>(v0);
            __m128 ab=_mm_sub_ps(v1.get(),base);
            __m128 ac=_mm_sub_ps(v2.get(),base);
            __m128 cross=_mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(ac,ac,0xd2),_mm_shuffle_ps(ab,ab,0xc9)),
                _mm_mul_ps(_mm_shuffle_ps(ac,ac,0xc9),_mm_shuffle_ps(ab,ab,0xd2)));

return splitLength(cross);
}
__forceinline float splitAbs(float v){ float t=(float)fabs((double)v); return t; }
union PointScratch { __m128* point; volatile float magnitude; };
union VertexScratch { SplitVertex* const* vertex; volatile float magnitude; };
// Splits overlapping faces tagged firstTag and secondTag by computing plane intersections and inserting new edges via FUN_00e191a0.
// @fnv 0x00e1aec0
// src: GUESS 0x00e1aec0 (confidence: medium)
void SplitHull::SplitOverlappingTaggedFaces(int firstTag, int secondTag) {
    DistanceScalar initial=_mm_load_ss(&DAT_010141cc);
    SplitPairs pairs;
    DistanceScalar tolerance;
    _mm_store_ps(reinterpret_cast<float*>(&tolerance.value),initial);
    for (int pass=0; pass<1; ++pass) {
        BuildTreeFromPaddedNodeBounds();
        pairs.size=0;
        Object_CollectOverlappingLeafPairs(&tree40,&tree40,&pairs);
        for(int pair=0;pair<pairs.size;++pair) {
            PartSplitFace* a=map5c.ComputeValue_00d9a4c0(pairs.data[pair].first)->triangle;
            PartSplitFace* b=map5c.ComputeValue_00d9a4c0(pairs.data[pair].second)->triangle;
            if(b->m_30==firstTag) { PartSplitFace* t=a; a=b; b=t; }
            if(a->m_30!=firstTag || b->m_30!=secondTag) continue;
            if(!(splitArea(b->point(0),b->point(1),b->point(2))>DAT_01032980)) continue;
            if(!overlapFaces(a,b)) continue;
            SplitPoint plane=a->m_20;
            __m128 normal=plane.get();
            
            __m128 p0=splitPosition(b->vertices[0]),p1=splitPosition(b->vertices[1]);
            __m128 p2;
            DistanceScalar distance[3]={splitPlaneDot(p0,normal),splitPlaneDot(p1,normal),splitPlaneDot(p2=splitPosition(b->vertices[2]),normal)};
            for(int i=0;i<3;++i) {
                if(splitAbs(splitReal(distance[i]))<=splitReal(tolerance))
                    { distance[i]=0.0f; }
            }
            int mask=0;
            __m128 intersections[3];
            __m128 t=_mm_div_ss(distance[0],_mm_sub_ss(distance[0],distance[1]));
            t=_mm_shuffle_ps(t,t,0);
            intersections[0]=_mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0,t),p0),_mm_mul_ps(t,p1));
            t=_mm_div_ss(distance[1],_mm_sub_ss(distance[1],distance[2]));
            t=_mm_shuffle_ps(t,t,0);
            intersections[1]=_mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0,t),p1),_mm_mul_ps(t,p2));
            t=_mm_div_ss(distance[2],_mm_sub_ss(distance[2],distance[0]));
            t=_mm_shuffle_ps(t,t,0);
            intersections[2]=_mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0,t),p2),_mm_mul_ps(t,p0));
            mask=(splitReal(_mm_mul_ss(distance[0],distance[1]))<0 ? 1:0)
                    +(splitReal(_mm_mul_ss(distance[1],distance[2]))<0 ? 2:0)
                    +(splitReal(_mm_mul_ss(distance[2],distance[0]))<0 ? 4:0);
            for(int edge=0;edge<3;++edge) {
                if(mask & (1<<edge)) {
                    if(splitLength(_mm_sub_ps(intersections[edge],splitPosition(b->vertices[edge])))<=splitReal(tolerance) ||
                       splitLength(_mm_sub_ps(intersections[edge],splitPosition(b->vertices[(edge+1)%3])))<=splitReal(tolerance))
                        mask &= ~(1<<edge);
                }
            }
            for(int edge=0;edge<3;++edge) {
                if(mask & (1<<edge)) {
                    float error=splitReal(splitPlaneDot(intersections[edge],normal));
                    if(splitAbs(error)>splitReal(tolerance)) { mask=0; break; }
                }
            }
            switch(mask) {
            case 0: continue;
            case 1: ProcessAndReturnValue_00e191a0(PartSplitEdge(b,0),intersections[0],0);break;
            case 2: ProcessAndReturnValue_00e191a0(PartSplitEdge(b,1),intersections[1],0);break;
            case 3: {
                ProcessAndReturnValue_00e191a0(ProcessAndReturnValue_00e191a0(PartSplitEdge(b,0),intersections[0],0).prev(),intersections[1],0);break;
            }
            case 4: ProcessAndReturnValue_00e191a0(PartSplitEdge(b,2),intersections[2],0);break;
            case 6: {
                ProcessAndReturnValue_00e191a0(ProcessAndReturnValue_00e191a0(PartSplitEdge(b,1),intersections[1],0).prev(),intersections[2],0);break;
            }
            case 5: {
                ProcessAndReturnValue_00e191a0(ProcessAndReturnValue_00e191a0(PartSplitEdge(b,2),intersections[2],0).prev(),intersections[0],0);break;
            }
            default: {
                __m128 text[32];
                CharBuffer buffer;
                buffer.FUN_00cb1600(reinterpret_cast<char*>(text),sizeof(text));
                buffer.ProcessAndReturnValue_00cc01c0(str_010eb080)->WriteInt(mask);
                DAT_01268360->Report(0,-1,reinterpret_cast<char*>(text),DAT_010eaeb4,3334);
                buffer.FUN_00cc00e0();
                continue;
            }
            }
            pass=-1;
        }
    }
    flag101=0;
    Allocator& allocator=meshHeap(hkMemoryRouter_getInstance());
    pairs.size=0;
    if(!(pairs.capacity & 0x80000000u)) allocator.freeBlock(pairs.data,(pairs.capacity&0x3fffffff)*8);
}

struct EdgeByte {char value;EdgeByte(int b):value((char)b) {} __forceinline operator bool() const {return value!=0;}};

extern "C" void _ReadWriteBarrier();



struct EdgeFlag {int value;EdgeFlag(int b):value(b) {} __forceinline operator bool() const {return value!=0;}};

struct ConstraintPoint {

    int x,y;

    ConstraintPoint() {}

    ConstraintPoint(int X,int Y):x(X),y(Y) {}

    __forceinline int compare(const ConstraintPoint& b) const {

        if(x<b.x) return -1;

        if(x>b.x) return 1;

        if(y<b.y) return -1;

        if(y>b.y) return 1;

        return 0;

    }

    __forceinline ConstraintPoint operator-(const ConstraintPoint& b) const { return ConstraintPoint(x-b.x,y-b.y); }

    __forceinline int cross(const ConstraintPoint& b) const { return x*b.y-y*b.x; }

};

struct ConstraintVertex {

    int unk00, unk04;

    ConstraintPoint pos;

    __forceinline int isEqual(int x,int y) const {return pos.x==x && pos.y==y;}

};

typedef S_00e13910_Triangle ConstraintTriangle;

struct ConstraintFace : ConstraintTriangle {

    unsigned short constraints : 3;

    unsigned short visited : 1;

    unsigned short remaining : 12;

};

__forceinline int orient(const ConstraintVertex*,const ConstraintVertex*,const ConstraintVertex*);

struct ConstraintEdge;
template<class E> struct ConstraintEdgeCore {

__forceinline ConstraintEdgeCore() {}
__forceinline ConstraintEdgeCore(ConstraintTriangle* t,unsigned i):m_pkTriangle(t),m_uiEdgeIndex(i) {}
__forceinline ConstraintEdgeCore(const unsigned long& word) {unpack(word,m_pkTriangle,m_uiEdgeIndex);}
static __forceinline void unpack(unsigned long word,ConstraintTriangle*& t,unsigned& index) {index=word&3;word&=~3ul;t=*(ConstraintTriangle**)&word;}

ConstraintTriangle* m_pkTriangle;
unsigned m_uiEdgeIndex;
__forceinline ConstraintVertex* const& end() const {return (ConstraintVertex* const&)m_pkTriangle->m_kVertices[(9>>(m_uiEdgeIndex<<1))&3];}
__forceinline ConstraintVertex* const& apex() const {return (ConstraintVertex* const&)m_pkTriangle->m_kVertices[(18>>(m_uiEdgeIndex<<1))&3];}
__forceinline void turnLeft() {unsigned link=m_pkTriangle->m_ppLinks[m_uiEdgeIndex];m_uiEdgeIndex=(9>>((link&3)<<1))&3;m_pkTriangle=(ConstraintTriangle*)(link&~3u);}
__forceinline void turnRight() {unsigned index=(18>>(m_uiEdgeIndex<<1))&3;unsigned link=m_pkTriangle->m_ppLinks[index];m_uiEdgeIndex=link&3;m_pkTriangle=(ConstraintTriangle*)(link&~3u);}
__forceinline bool isValid() const { return m_pkTriangle!=0; }
__forceinline E next() const { return E(m_pkTriangle,(9>>(m_uiEdgeIndex<<1))&3); }
__forceinline E prev() const { return E(m_pkTriangle,(0x12>>(m_uiEdgeIndex<<1))&3); }
__forceinline E link() const { return E(m_pkTriangle->m_ppLinks[m_uiEdgeIndex]); }
__forceinline void*& start() const { return m_pkTriangle->m_kVertices[m_uiEdgeIndex]; }
__forceinline ConstraintVertex* const& vertex() const { return (ConstraintVertex* const&)start(); }
__forceinline unsigned rawLink() const {return m_pkTriangle->m_ppLinks[m_uiEdgeIndex];}
__forceinline void bindPacked(unsigned packed) const {

        unsigned index=packed&3u;

        ConstraintTriangle* other=(ConstraintTriangle*)(packed&~3u);

        m_pkTriangle->m_ppLinks[m_uiEdgeIndex]=(unsigned)other+index;

        if(other) other->m_ppLinks[index]=(unsigned)m_pkTriangle+m_uiEdgeIndex;

    }
__forceinline void bind(const ConstraintEdgeCore& other) const {

        m_pkTriangle->m_ppLinks[m_uiEdgeIndex]=other.m_uiEdgeIndex+(unsigned)other.m_pkTriangle;

        if(other.m_pkTriangle) other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex]=m_uiEdgeIndex+(unsigned)m_pkTriangle;

    }
__forceinline bool master() const {ConstraintVertex* b=end();ConstraintVertex* a=vertex();return a->pos.compare(b->pos)<=0 || !link().isValid();}
__forceinline E canonical() const {if(master())return E(m_pkTriangle,m_uiEdgeIndex);return link();}
__forceinline EdgeByte constrainedB() const {const E& e=canonical();const int c=((ConstraintFace*)e.m_pkTriangle)->constraints;return c & (1 << e.m_uiEdgeIndex);}
__forceinline bool constrained() const {const E e(canonical());return 0!=(((ConstraintFace*)e.m_pkTriangle)->constraints & (1 << e.m_uiEdgeIndex));}
__forceinline EdgeByte constrainedByte() const {

        const E& e=canonical();

        return ((ConstraintFace*)e.m_pkTriangle)->constraints & (1 << e.m_uiEdgeIndex);

    }
__forceinline void setConstraint() const {

        const E& e=canonical();

        ((ConstraintFace*)e.m_pkTriangle)->constraints |= 1 << e.m_uiEdgeIndex;

    }
__forceinline void clearConstraint() const {

        const E& e=canonical();

        ((ConstraintFace*)e.m_pkTriangle)->constraints &= ~(1 << e.m_uiEdgeIndex);

    }
__forceinline E flipBase() const {

        const ConstraintEdgeCore other=link();

        const ConstraintEdgeCore back=prev();

        const ConstraintEdgeCore acrossConstraint=other.prev();

        start()=acrossConstraint.start();

        other.start()=back.start();

        other.bind(back.link());

        bind(acrossConstraint.link());

        back.bind(acrossConstraint);

        return prev();

    }
};
struct ConstraintEdge : ConstraintEdgeCore<ConstraintEdge> {
__forceinline ConstraintEdge() {}
void operator=(const ConstraintEdge& e) {unsigned* d=reinterpret_cast<unsigned*>(this);const unsigned* q=reinterpret_cast<const unsigned*>(&e);d[0]=q[0];d[1]=q[1];}
__forceinline ConstraintEdge(const ConstraintEdge& e):ConstraintEdgeCore<ConstraintEdge>(e.m_pkTriangle,e.m_uiEdgeIndex) {}
__forceinline ConstraintEdge(ConstraintTriangle* t,unsigned i):ConstraintEdgeCore<ConstraintEdge>(t,i) {}
__forceinline ConstraintEdge(unsigned long l):ConstraintEdgeCore<ConstraintEdge>(l) {}
__forceinline int canFlip() const {

        if(!link().isValid() || constrained()) return 0;

const ConstraintEdge opposite=link();

const ConstraintEdge before=prev();

const ConstraintEdge acrossConstraint=opposite.prev();

        return orient(before.vertex(),vertex(),acrossConstraint.vertex())>0 && orient(acrossConstraint.vertex(),opposite.vertex(),before.vertex())>0;

    }
__forceinline int takeConstraint() const {

        int had=constrained();

        if(had) clearConstraint();

        return had;

    }
__forceinline ConstraintEdge flip() const {

        int first=prev().takeConstraint();

        int second=link().prev().takeConstraint();

        ConstraintEdge result=flipBase();

        if(first) result.link().next().setConstraint();

        if(second) result.next().setConstraint();

        return result;

    }
};
__forceinline const ConstraintEdge& nullConstraintEdge() {

    static ConstraintEdge edge(0,0);

    return edge;

}

__forceinline int orientRaw(int ax,int ay,int bx,int by,int cx,int cy) {

    bx-=ax; by-=ay; cx-=ax; cy-=ay;

    return -(by*cx-bx*cy);

}

__forceinline int orient(const ConstraintVertex* a,const ConstraintVertex* b,int x,int y) {

    return orientRaw(a->pos.x,a->pos.y,b->pos.x,b->pos.y,x,y);

}

__forceinline int orient(const ConstraintVertex* a,const ConstraintVertex* b,const ConstraintVertex* c) {

    return orientRaw(a->pos.x,a->pos.y,b->pos.x,b->pos.y,c->pos.x,c->pos.y);

}

__forceinline int orientInput(const ConstraintVertex* a,int bx,int by,int cx,int cy) {

    return orientRaw(a->pos.x,a->pos.y,bx,by,cx,cy);

}

__forceinline int allowed(int ax,int ay,int bx,int by) {

    if(ax==bx) {if(ax==0 && ay<by) return 0;else if(ax==32767 && ay>by) return 0;}

    if(ay==by) {if(ay==0 && ax>bx) return 0;else if(ay==32767 && ax<bx) return 0;}

    return 1;

}

struct ConstraintResult {

    int status;

    ConstraintEdge edge;

    __forceinline ConstraintResult() {}

    __forceinline ConstraintResult(int s,const ConstraintEdge& e):status(s),edge(e) {}

    __forceinline ConstraintResult* assign(int s,const ConstraintEdge& e) {status=s;edge=ConstraintEdge(e);return this;}

    __forceinline ConstraintResult* assignSpecial(int s,const ConstraintEdge& e) {status=s;edge=ConstraintEdge(e);return this;}

__forceinline ConstraintResult* assignFailure(int s,const ConstraintEdge& e) {ConstraintEdge t(e);status=s;edge=ConstraintEdge(t);return this;}

    ConstraintResult* ComputeValue_00e22c80(unsigned, ConstraintEdge*);

};

void __cdecl ResizeAudioStream(void*,void*,int);

struct ConstraintEdges {

    ConstraintEdge* data;

    int size;

    int capacity;

    __forceinline void push(const ConstraintEdge& edge) {

        Allocator& heap=meshHeap(hkMemoryRouter_getInstance());

        if(size==(capacity&0x3fffffff)) ResizeAudioStream(&heap,this,8);

        new(data+size) ConstraintEdge(edge);

        ++size;

    }

};

struct ConstraintIntArray {

    int* data;

    int size;

    int capacity;

};

struct ConstraintData : ConstraintIntArray { int inlineData[4]; };

struct ConstraintDataBlock {

    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;

    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;

    int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;

    int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;

    int unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c;

    int unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc;

    int unkc0,unkc4,unkc8,unkcc,unkd0,unkd4,unkd8,unkdc;

    int unke0,unke4,unke8,unkec,unkf0,unkf4,unkf8,unkfc;

    int unk100,unk104,unk108,unk10c,unk110,unk114,unk118,unk11c;

    int unk120,unk124,unk128,unk12c,unk130,unk134,unk138,unk13c;

    int unk140,unk144,unk148,unk14c,unk150,unk154,unk158,unk15c;

    int unk160,unk164,unk168,unk16c,unk170,unk174,unk178,unk17c;

    int unk180,unk184,unk188,unk18c,unk190,unk194,unk198,unk19c;

    int unk1a0,unk1a4,unk1a8,unk1ac,unk1b0,unk1b4,unk1b8,unk1bc;

    int unk1c0,unk1c4,unk1c8,unk1cc,unk1d0,unk1d4,unk1d8,unk1dc;

    int unk1e0,unk1e4,unk1e8,unk1ec,unk1f0,unk1f4,unk1f8,unk1fc;

    int unk200,unk204,unk208,unk20c,unk210,unk214,unk218,unk21c;

    int unk220,unk224,unk228,unk22c,unk230,unk234,unk238,unk23c;

    int unk240,unk244,unk248,unk24c,unk250,unk254,unk258,unk25c;

    int unk260,unk264,unk268,unk26c,unk270,unk274,unk278,unk27c;

    int unk280,unk284,unk288,unk28c,unk290,unk294,unk298,unk29c;

    int unk2a0,unk2a4,unk2a8,unk2ac,unk2b0,unk2b4,unk2b8,unk2bc;

    int unk2c0,unk2c4,unk2c8,unk2cc,unk2d0,unk2d4,unk2d8,unk2dc;

    int unk2e0,unk2e4,unk2e8,unk2ec,unk2f0,unk2f4,unk2f8,unk2fc;

    int unk300,unk304,unk308,unk30c,unk310,unk314,unk318,unk31c;

    int unk320,unk324,unk328,unk32c,unk330,unk334,unk338,unk33c;

    int unk340,unk344,unk348,unk34c,unk350,unk354,unk358,unk35c;

    int unk360,unk364,unk368,unk36c,unk370,unk374,unk378,unk37c;

    ConstraintData* freeHead;

    int used;

};

struct ConstraintDataPool {

    ConstraintDataBlock** blocks;

    int size,capacity;

    ConstraintDataBlock* hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_32_struct_hkContainerHeapAllocator_allocateNewPool();

    __forceinline ConstraintData* allocate() {

        ConstraintDataBlock* b;

        if(!size || !blocks[0]->freeHead) b=hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_32_struct_hkContainerHeapAllocator_allocateNewPool();

        else b=blocks[0];

        ConstraintData* p=b->freeHead;

        ++b->used;

        b->freeHead=*(ConstraintData**)p;

        p->data=p->inlineData;

        p->size=0;

        p->capacity=0x80000004;

        return p;

    }

};

struct ConstraintHashEntry {

    ConstraintVertex* a;

    ConstraintVertex* b;

    ConstraintData* data;

    ConstraintHashEntry():a(0),b(0),data(0) {}

};

struct ConstraintHashBucket {ConstraintHashEntry* data;int size,capacity;};

struct ConstraintHash {ConstraintHashBucket* buckets;unsigned bucketCount;int unk08;int size;};



struct ConstraintMesh {

    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;

    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;

    ConstraintEdges edges;

    int unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c;

    int unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c;

    int unk90,unk94,unk98,unk9c,unka0,unka4,unka8,unkac;

    int unkb0,unkb4,unkb8,unkbc,unkc0,unkc4,unkc8,unkcc;

    int unkd0,unkd4,unkd8,unkdc,unke0,unke4,unke8,unkec;

    int unkf0,unkf4,unkf8,unkfc,unk100,unk104,unk108,unk10c;

    int unk110,unk114,unk118,unk11c,unk120,unk124,unk128,unk12c;

    int unk130,unk134,unk138,unk13c,unk140,unk144,unk148,unk14c;

    int unk150,unk154,unk158,unk15c,unk160,unk164,unk168,unk16c;

    int unk170,unk174,unk178,unk17c,unk180,unk184,unk188,unk18c;

    int unk190,unk194,unk198,unk19c,unk1a0,unk1a4,unk1a8,unk1ac;

    int unk1b0,unk1b4,unk1b8,unk1bc,unk1c0,unk1c4,unk1c8,unk1cc;

    int unk1d0,unk1d4,unk1d8,unk1dc,unk1e0,unk1e4,unk1e8,unk1ec;

    int unk1f0,unk1f4,unk1f8,unk1fc,unk200,unk204,unk208,unk20c;

    int unk210,unk214,unk218,unk21c,unk220,unk224,unk228,unk22c;

    int unk230,unk234,unk238,unk23c,unk240,unk244,unk248;

    ConstraintHash* links;

    ConstraintDataPool attachments;

    ConstraintTriangle* cells[256];

    ConstraintResult LocatePoint(int,int);

    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_setEdgeData(ConstraintEdge*,const int*);

    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_flushConform();

    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_createEdgeDataHashTable();

    ConstraintEdge hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_locateExistingEdge(ConstraintEdge,ConstraintVertex*,ConstraintVertex*);

    __forceinline void cache(ConstraintTriangle* t) {

        int row=(((ConstraintVertex*)t->m_kVertices[0])->pos.y+((ConstraintVertex*)t->m_kVertices[1])->pos.y+((ConstraintVertex*)t->m_kVertices[2])->pos.y)/3>>11;

        int col=(((ConstraintVertex*)t->m_kVertices[0])->pos.x+((ConstraintVertex*)t->m_kVertices[1])->pos.x+((ConstraintVertex*)t->m_kVertices[2])->pos.x)/3>>11;

        cells[(row<<4)+col]=t;

        ((ConstraintFace*)t)->visited=1;

    }

    __forceinline ConstraintEdge optimize(const ConstraintEdge& edge) {

        ConstraintVertex* a=edge.vertex();

        ConstraintVertex* b=edge.end();

        edges.push(edge.next());

        edges.push(edge.prev());

        if(edge.link().isValid()) {

            edges.push(edge.link().next());

            edges.push(edge.link().prev());

        }

        hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_flushConform();

        ConstraintEdge result=hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_locateExistingEdge(edge,a,b);return result;

    }

    __forceinline void optimizeInto(ConstraintEdge& edge) {

        ConstraintVertex* a=edge.vertex();

        ConstraintVertex* b=edge.end();

        edges.push(edge.next());

        edges.push(edge.prev());

        if(edge.link().isValid()) {

            edges.push(edge.link().next());

            edges.push(edge.link().prev());

        }

        hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_flushConform();

        edge=hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_locateExistingEdge(edge,a,b);

    }

    ConstraintResult* hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_insertEdge(ConstraintResult* out,int x0,int y0,int x1,int y1,bool optimizeEdge,const int* data);

};

// Inserts a constraint edge between two points in the mesh, locating the inner edge, walking to the target, and flipping edges to maintain validity.
// @fnv 0x00e26010
// src: HAVOK_LIB 0x00e26010
ConstraintResult* ConstraintMesh::hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_insertEdge(ConstraintResult* apResult,int x0,int y0,int x1,int y1,bool optimizeEdge,const int* data) {

    if(x0==x1 && y0==y1) return apResult->assign(9,nullConstraintEdge());

    ConstraintEdge innerEdge;{const ConstraintResult located=LocatePoint(x0,y0);
    if(EdgeByte(located.status!=2)) return apResult->assign(6,nullConstraintEdge());
    innerEdge=located.edge;}

    ConstraintVertex* source=innerEdge.vertex();

    while(orient(innerEdge.vertex(),innerEdge.end(),x1,y1)<0) innerEdge=innerEdge.link().next();

    while(innerEdge.isValid()) {

        ConstraintEdge x;

        x = innerEdge.prev();

        if(orient(x.vertex(),x.end(),x1,y1)>0) break;

        innerEdge=x.link();

    }

    if(!innerEdge.isValid()) return apResult->assign(8,nullConstraintEdge());

    ConstraintVertex* target;

    {

    ConstraintEdge side;

    side = innerEdge.next();

    if(innerEdge.end()->isEqual(x1,y1)) {

        if(innerEdge.constrained()) return apResult->assign(1,innerEdge);

        innerEdge.setConstraint();

        if(data) hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_setEdgeData(&innerEdge,data);

        if(optimizeEdge) {
 ConstraintVertex* queueStart=innerEdge.vertex();
 ConstraintVertex* queueEnd=innerEdge.end();
 edges.push(innerEdge.next());
 edges.push(innerEdge.prev());
 if(innerEdge.link().isValid()) {
  edges.push(innerEdge.link().next());
  edges.push(innerEdge.link().prev());
 }
 hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_flushConform();
 {const ConstraintEdge recovered=hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_locateExistingEdge(innerEdge,queueStart,queueEnd);
 innerEdge=recovered;}
}

        cache(innerEdge.m_pkTriangle);

        return apResult->assign(0,innerEdge);

    }

    if(!allowed(x1,y1,x0,y0)) return apResult->assign(8,nullConstraintEdge());

    while(orient(side.vertex(),side.end(),x1,y1)<0) {

        if(side.constrained()) {

            if(orientInput(side.vertex(),x0,y0,x1,y1)==0) return apResult->assignSpecial(4,side);

            if(orientInput(side.end(),x0,y0,x1,y1)==0) return apResult->assignSpecial(4,side.next());

            return apResult->assignSpecial(3,side);

        }

        side=side.link();

        int sign=orient(source,side.apex(),x1,y1);

        if(sign<0) side=side.next();

        else if(sign>0) side=side.prev();

        else {

            if(!side.apex()->isEqual(x1,y1)) return apResult->assignSpecial(4,side.prev());

            side=side.prev();

        }

    }

    target=side.vertex();

    if(source==target) return apResult->assign(9,nullConstraintEdge());

    if(orient(side.vertex(),side.end(),x1,y1)!=0) return apResult->assign(7,nullConstraintEdge());

    if(!target->isEqual(x1,y1)) return apResult->assignFailure(4,side);

    if((source->pos.x==target->pos.x && (source->pos.x==0 || source->pos.x==32767)) ||

       (source->pos.y==target->pos.y && (source->pos.y==0 || source->pos.y==32767))) return apResult->assign(8,side);

    if(orient(innerEdge.vertex(),innerEdge.end(),target)==0) return apResult->assign(4,innerEdge.next());

    if(orient(innerEdge.vertex(),innerEdge.end(),target)<0) return apResult->assign(4,side);

    }

    int invalid=0;

    while(innerEdge.end()!=target) {

        ConstraintEdge old=innerEdge;

        innerEdge=innerEdge.next();

        while(orient(source,target,innerEdge.end())>0)

            innerEdge=ConstraintEdge(innerEdge.link()).next();

        ConstraintVertex* pivot = innerEdge.end();

        if(orient(old.vertex(),innerEdge.vertex(),pivot)>0) {

            innerEdge=old.next();

            int scan=0;

            while(innerEdge.end()!=pivot) {

                if(innerEdge.canFlip()) {

                    {

                        innerEdge=innerEdge.flip();

                        innerEdge=innerEdge.link();

                        if(scan) { innerEdge=ConstraintEdge(innerEdge.next()).link(); --scan; }

                        else innerEdge=innerEdge.prev();

                        continue;

                    }

                }

                ++scan;

                innerEdge=innerEdge.link().next();

            }

            innerEdge=ConstraintEdge(innerEdge.next()).link();

            if(invalid) {

                while(orient(source,target,innerEdge.apex())>0)

                    innerEdge=ConstraintEdge(innerEdge.prev()).link();

                innerEdge=innerEdge.prev();

                --invalid;

            }

        } else ++invalid;

    }

    innerEdge.setConstraint();

    if(data) hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_setEdgeData(&innerEdge,data);

    if(optimizeEdge) innerEdge=optimize(innerEdge);

    cache(innerEdge.m_pkTriangle);

    apResult->ComputeValue_00e22c80(0,&innerEdge);

    return apResult;

}



// src: GUESS 0x00e22c80 (confidence: low)
__declspec(noinline) ConstraintResult* ConstraintResult::ComputeValue_00e22c80(unsigned s, ConstraintEdge* e) {status=s;edge=*e;return this;}



// src: HAVOK_LIB 0x00e25cd0
__declspec(noinline) void ConstraintMesh::hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_setEdgeData(ConstraintEdge* edge,const int* input) {

    if(!links) hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_createEdgeDataHashTable();

    ConstraintVertex* a=edge->vertex();

    ConstraintVertex* b=edge->next().vertex();

    unsigned keyA=(a->pos.x<<15)+a->pos.y;

    unsigned keyB=(b->pos.x<<15)+b->pos.y;

    unsigned hash=(keyA*0x3442a5u) ^ (keyB*0x1958e9u);

    ConstraintHashBucket& bucket=links->buckets[hash%links->bucketCount];

    ConstraintHashEntry* entry=0;

    for(int i=0;i<bucket.size;++i) {

        if(bucket.data[i].a==a && bucket.data[i].b==b) {entry=&bucket.data[i];break;}

    }

    if(!entry) {

        ++links->size;

        if(bucket.size==(bucket.capacity&0x3fffffff)) ResizeAudioStream(reinterpret_cast<Allocator*>(hkMemoryRouter_getInstance().m_heap),&bucket,12);

        new(bucket.data+bucket.size) ConstraintHashEntry();

        entry=&bucket.data[bucket.size++];

        entry->a=a;

        entry->b=b;

        entry->data=0;

        entry->data=attachments.allocate();

    }

    ConstraintIntArray* dest=entry->data;

    const ConstraintIntArray* source=(const ConstraintIntArray*)input;

    for(int i=0;i<source->size;++i) {

        int j=0;

        while(j<dest->size && dest->data[j]!=source->data[i]) ++j;

        if(j==dest->size) {

            const int* value=&source->data[i];

            if(dest->size==(dest->capacity&0x3fffffff)) ResizeAudioStream(reinterpret_cast<Allocator*>(hkMemoryRouter_getInstance().m_heap),dest,4);

            dest->data[dest->size]=*value;

            ++dest->size;

        }

    }

}

struct __declspec(align(16)) S_00e27c90_V {
    float x, y, z, w;
};

struct S_00e27c90_T {
    S_00e27c90_V c0, c1, c2, c3;
    void hkRotation_set(const void* q);
};

struct __declspec(align(16)) S_00e27c90_Q {
    float x, y, z, w;
    void ComputeValues_00cd9d10(int angle, const S_00e27c90_V* axis);
};

struct S_00e27c90_U {
    S_00e27c90_V c0, c1, c2, c3;
    void hkMatrix4_CopyMatrixWithAffineFourthComponents(const S_00e27c90_T* t);
};


struct S_00e27c90_Obj {
    void UpdateTransformedBounds(int a, S_00e27c90_U* u, int b, int c);
    void UpdateBoundsForZRotation(int a, int angle, int b, int c);
};

// Builds a Z-axis rotation from angle, applies it to a copy of DAT_01268370 via FUN_00cb2d90, converts via FUN_00de90f0, and calls FUN_00e27850.
// @fnv 0x00e27c90
// src: GUESS 0x00e27c90 (confidence: medium)
void S_00e27c90_Obj::UpdateBoundsForZRotation(int a, int angle, int b, int c)
{
    S_00e27c90_Q q;
    {
        S_00e27c90_V axis;
        reinterpret_cast<__m128&>(axis) = _mm_setr_ps(0.0f, 0.0f, 1.0f, 0.0f);
        q.ComputeValues_00cd9d10(angle, &axis);
    }
    S_00e27c90_T t;
    S_00e27c90_V v0 = (*(S_00e27c90_T*)&DAT_01268370).c0;
    S_00e27c90_V v1 = (*(S_00e27c90_T*)&DAT_01268370).c1;
    S_00e27c90_V v2 = (*(S_00e27c90_T*)&DAT_01268370).c2;
    S_00e27c90_V v3 = (*(S_00e27c90_T*)&DAT_01268370).c3;
    *reinterpret_cast<__m128*>(&t.c0) = *reinterpret_cast<__m128*>(&v0);
    *reinterpret_cast<__m128*>(&t.c1) = *reinterpret_cast<__m128*>(&v1);
    *reinterpret_cast<__m128*>(&t.c2) = *reinterpret_cast<__m128*>(&v2);
    *reinterpret_cast<__m128*>(&t.c3) = *reinterpret_cast<__m128*>(&v3);
    t.hkRotation_set(&q);
    S_00e27c90_U u;
    u.hkMatrix4_CopyMatrixWithAffineFourthComponents(&t);
    UpdateTransformedBounds(a, &u, b, c);
}

extern "C" void _ReadBarrier();
extern "C" void _WriteBarrier();
extern "C" void _ReadWriteBarrier();
extern int DAT_010eb088;
extern int DAT_010eb0e0;
extern "C" __m128 _mm_setr_ps(float,float,float,float);
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_setzero_ps();

struct __declspec(align(16)) OptVec4 {
    float x, y, z, w;
__forceinline OptVec4& operator=(const OptVec4& o) {_mm_store_ps(&x,o.q());return *this;}
    __forceinline const __m128 &q() const { return *(const __m128 *)this; }
};


__declspec(nothrow) __declspec(nothrow) void __cdecl ResizeAudioStream(Allocator *ctx, void *arr, int eltSize) throw();
__declspec(nothrow) void __cdecl Geometry_MapCoordinatesToSphere(OptVec4 *pt, void *elem) throw();

extern double DAT_01015a40;



extern float DAT_0104da48;
struct LogGlobal {
    __declspec(nothrow) virtual void Slot00();
    __declspec(nothrow) virtual void Slot04();
    __declspec(nothrow) virtual void Slot08();
    __declspec(nothrow) virtual void LogCall(int a, int b, char *buf, char *file, int line);
};
extern char DAT_010eb128;
extern char DAT_010eb100;
extern char DAT_010eb10c;
extern char DAT_010eb11c;
extern char DAT_010eb0ec;
extern char DAT_010eb0f8;


float __cdecl ClampedAcos(float x);
struct LogSub { int state; void FUN_00cb1600(char *buf, int size); };
struct LogMid {
    int state;
    LogMid *ProcessAndReturnValue_00cc01c0(const char *s);
    LogMid *WriteInt(int value);
};
struct LogObj { int state; LogMid m_04; LogSub m_08; void FUN_00cc00e0(); };

struct SubArrInt {
    int *m_pData;
    int m_iArrayLength;
    int m_iCap;
    __forceinline void append(const int &value) throw();
};

struct ParameterHandle;
struct Param {
    int m_00;
    int m_04;
    int m_08;
};

struct TEnt;
struct BoundaryEntry;
struct NodeRes {
    BoundaryEntry *m_00;
    int m_04;
    __declspec(nothrow) void ClearAndFree(int arg) throw();
};
__declspec(nothrow) NodeRes *__cdecl hkgpMeshInternals_createRing(void *node, int idx) throw();

struct Node123 {
    void *m_00;
    char field_004; char field_005; char field_006; char field_007; char field_008; char field_009; char field_00a; char field_00b; char field_00c; char field_00d; char field_00e; char field_00f; char field_010; char field_011; char field_012; char field_013;
    int m_14[3];
};

struct ObjB {
    char enabled; char field_01; char field_02; char field_03;
    float tolerance;
    char flag08; char flag09; char flag0a; char flag0b; char flag0c; char flag0d;
    void hkgpConvexHull_BuildConfig_BuildConfig();
};
struct View {
    void *m_pData;
    int m_iArrayLength;
    int stride;
};

struct EdgeSelection { Pair first,second; };
struct PairArrRaw {
    Pair *m_pData; int m_iArrayLength; int m_iCap;
    __forceinline void append(const Pair& value) throw() {
        Allocator& heap=meshHeap(hkMemoryRouter_getInstance());
        if(m_iArrayLength==(m_iCap&0x3fffffff)) ResizeAudioStream(&heap,this,8);
        new(m_pData+m_iArrayLength) Pair(value);
        ++m_iArrayLength;
    }
};
struct HoleQuery { int status; Pair edge; };
struct BoundaryEntry {
    Pair edge;
    int field08; int field0c; int field10; int field14;
    int field18; int field1c; int field20; int field24;
    int field28; int field2c; int field30; int field34; int field38; int field3c;
};
struct SolverPool {
    void *data; int size; int capacity; void *head; int count; int unknown;
    __declspec(nothrow) SolverPool() throw() : data(0),size(0),capacity(0x80000000),head(0),count(0) {}
    __declspec(nothrow) void ProcessEntries() throw();
    __declspec(nothrow) void ClearAndFreeItems() throw();
    __declspec(nothrow) void hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_reset() throw();
    __declspec(nothrow) void ProcessEntries_00e23d70() throw();
};
struct SolverMesh {
    void *vtable;
    short memorySize; short references;
    SolverPool vertices; SolverPool triangles;
    __declspec(nothrow) SolverMesh() throw() : vtable(&DAT_010eb088), references(1) {}
    __declspec(nothrow) __forceinline ~SolverMesh() throw() {
        vtable=&DAT_010eb088;
        triangles.hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_struct_hkgpTriangulatorBase_VertexBase_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_Triangle_32_struct_hkContainerHeapAllocator_reset(); triangles.ProcessEntries_00e23d70();
        vertices.ProcessEntries(); vertices.ClearAndFreeItems();
    }
};
struct SolverTail {
    void *data; int size; int capacity;
    __declspec(nothrow) SolverTail() throw() {}
    __declspec(nothrow) void FUN_00e23c70() throw();
};
struct SolverRef {
    SolverRef() throw() : vtable(&DAT_010eb0e0), references(1) {}
    void *vtable;
    short memorySize; short references;
};
struct __declspec(align(16)) BigSolver : SolverRef {
    SolverMesh mesh;
    PairArrRaw m_40arr;
    Pair localPairs[64];
    struct EdgeMap *edgeMap;
    SolverTail tail;
    int field_25c; int field_260; int field_264; int field_268;
    int field_26c; int field_270; int field_274; int field_278;
    int field_27c; int field_280; int field_284; int field_288;
    int field_28c; int field_290; int field_294; int field_298;
    int field_29c; int field_2a0; int field_2a4; int field_2a8;
    int field_2ac; int field_2b0; int field_2b4; int field_2b8;
    int field_2bc; int field_2c0; int field_2c4; int field_2c8;
    int field_2cc; int field_2d0; int field_2d4; int field_2d8;
    int field_2dc; int field_2e0; int field_2e4; int field_2e8;
    int field_2ec; int field_2f0; int field_2f4; int field_2f8;
    int field_2fc; int field_300; int field_304; int field_308;
    int field_30c; int field_310; int field_314; int field_318;
    int field_31c; int field_320; int field_324; int field_328;
    int field_32c; int field_330; int field_334; int field_338;
    int field_33c; int field_340; int field_344; int field_348;
    int field_34c; int field_350; int field_354; int field_358;
    int field_35c; int field_360; int field_364; int field_368;
    int field_36c; int field_370; int field_374; int field_378;
    int field_37c; int field_380; int field_384; int field_388;
    int field_38c; int field_390; int field_394; int field_398;
    int field_39c; int field_3a0; int field_3a4; int field_3a8;
    int field_3ac; int field_3b0; int field_3b4; int field_3b8;
    int field_3bc; int field_3c0; int field_3c4; int field_3c8;
    int field_3cc; int field_3d0; int field_3d4; int field_3d8;
    int field_3dc; int field_3e0; int field_3e4; int field_3e8;
    int field_3ec; int field_3f0; int field_3f4; int field_3f8;
    int field_3fc; int field_400; int field_404; int field_408;
    int field_40c; int field_410; int field_414; int field_418;
    int field_41c; int field_420; int field_424; int field_428;
    int field_42c; int field_430; int field_434; int field_438;
    int field_43c; int field_440; int field_444; int field_448;
    int field_44c; int field_450; int field_454; int field_458;
    int field_45c; int field_460; int field_464; int field_468;
    int field_46c; int field_470; int field_474; int field_478;
    int field_47c; int field_480; int field_484; int field_488;
    int field_48c; int field_490; int field_494; int field_498;
    int field_49c; int field_4a0; int field_4a4; int field_4a8;
    int field_4ac; int field_4b0; int field_4b4; int field_4b8;
    int field_4bc; int field_4c0; int field_4c4; int field_4c8;
    int field_4cc; int field_4d0; int field_4d4; int field_4d8;
    int field_4dc; int field_4e0; int field_4e4; int field_4e8;
    int field_4ec; int field_4f0; int field_4f4; int field_4f8;
    int field_4fc; int field_500; int field_504; int field_508;
    int field_50c; int field_510; int field_514; int field_518;
    int field_51c; int field_520; int field_524; int field_528;
    int field_52c; int field_530; int field_534; int field_538;
    int field_53c; int field_540; int field_544; int field_548;
    int field_54c; int field_550; int field_554; int field_558;
    int field_55c; int field_560; int field_564; int field_568;
    int field_56c; int field_570; int field_574; int field_578;
    int field_57c; int field_580; int field_584; int field_588;
    int field_58c; int field_590; int field_594; int field_598;
    int field_59c; int field_5a0; int field_5a4; int field_5a8;
    int field_5ac; int field_5b0; int field_5b4; int field_5b8;
    int field_5bc; int field_5c0; int field_5c4; int field_5c8;
    int field_5cc; int field_5d0; int field_5d4; int field_5d8;
    int field_5dc; int field_5e0; int field_5e4; int field_5e8;
    int field_5ec; int field_5f0; int field_5f4; int field_5f8;
    int field_5fc; int field_600; int field_604; int field_608;
    int field_60c; int field_610; int field_614; int field_618;
    int field_61c; int field_620; int field_624; int field_628;
    int field_62c; int field_630; int field_634; int field_638;
    int field_63c; int field_640; int field_644; int field_648;
    int field_64c; int field_650; int field_654; int field_658;
    int baseVal;
    int field_660; int field_664; int field_668; int field_66c;
    int field_670; int field_674; int field_678; int field_67c;
    int field_680; int field_684; int field_688; int field_68c;
    int field_690; int field_694; int field_698; int field_69c;
    OptVec4 col0; OptVec4 col1; OptVec4 col2; OptVec4 col3;
    __declspec(nothrow) HoleQuery hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_insertVertex(int cx, int cy, int one, HoleQuery *input, int zero) throw();
    __declspec(nothrow) HoleQuery hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_insertEdge(int cxB, int cyB, int cxA, int cyA, int one, void *intArr) throw();
    __declspec(nothrow) void UpdateState_00e27b50(void *a, void *b, float c, int d) throw();
    __declspec(nothrow) void UpdateBoundsForZRotation(void *a, void *b, int c, int d) throw();
    __declspec(nothrow) HoleQuery LocatePoint(int cx, int cy) throw();
    __declspec(nothrow) int hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_partition() throw();
    __declspec(nothrow) void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_conformEdges() throw();
    __declspec(nothrow) __declspec(noinline) int CheckLinks() throw();
    __declspec(nothrow) __declspec(noinline) void *LookupPairResult(void *pair) throw();
    __declspec(nothrow) void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_reset(int) throw();
    __forceinline OptVec4 projectWorld(const OptVec4&) const;
    __forceinline TEnt quantizeWorld(const OptVec4&) const;
    __forceinline TEnt transformWorld(const OptVec4&) const;
__forceinline void initializeMap() throw() {edgeMap=0;}
    __declspec(nothrow) __forceinline BigSolver() throw();
    __declspec(nothrow) __forceinline ~BigSolver() throw() {
        vtable=&DAT_010eb0e0;
        hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_reset(1);
        tail.FUN_00e23c70();
        Allocator& ctx=meshHeap(hkMemoryRouter_getInstance());
        int cap=m_40arr.m_iCap;
        m_40arr.m_iArrayLength=0;
        if((cap&0x80000000)==0) ctx.freeBlock(m_40arr.m_pData,(cap&0x3fffffff)*8);
        m_40arr.m_pData=0; m_40arr.m_iCap=0x80000000;
    }
};

static __forceinline void SetV(OptVec4 &v, float a, float b, float c, float d)
{
    _mm_store_ps(&v.x, _mm_setr_ps(a, b, c, d));
}
    __declspec(nothrow) BigSolver::BigSolver() throw() {
        m_40arr.m_pData=localPairs; m_40arr.m_iArrayLength=0; m_40arr.m_iCap=0x80000040; tail.data=0; tail.size=0; tail.capacity=0x80000000;
                OptVec4 lo; OptVec4 adjx;
                SetV(lo, DAT_01012054, DAT_01012054, 0.0f, 0.0f);
                SetV(adjx, 1.0f, 1.0f, 0.0f, 0.0f);
initializeMap();
                UpdateState_00e27b50(&lo, &adjx, 0.0f, 1);
    }template <class T> struct HArr {
    T *m_pData; int m_iArrayLength; int m_iCap;
    __forceinline HArr() throw() : m_pData(0), m_iArrayLength(0), m_iCap((int)0x80000000) {}
    __forceinline ~HArr() throw()
    {
        hkMemoryRouter *svc = ((hkMemoryRouter*)&hkMemoryRouter_getInstance());
        Allocator *ctx = reinterpret_cast<Allocator*>(svc->m_heap);
        int cap = m_iCap;
        m_iArrayLength = 0;
        if ((cap & 0x80000000) == 0)
            ctx->freeBlock(m_pData, (cap & 0x3fffffff) * sizeof(T));
        m_pData = 0;
        m_iCap = (int)0x80000000;
    }
};
struct PairArr : HArr<Pair> {
    __forceinline void append(const Pair& value) throw() {
        Allocator& heap=meshHeap(hkMemoryRouter_getInstance());
        if(m_iArrayLength==(m_iCap&0x3fffffff)) ResizeAudioStream(&heap,this,8);
        new(m_pData+m_iArrayLength) Pair(value);
        ++m_iArrayLength;
    }
};

__forceinline void SubArrInt::append(const int &value) throw()
{
    hkMemoryRouter *svc = ((hkMemoryRouter*)&hkMemoryRouter_getInstance());
    if (m_iArrayLength == (m_iCap & 0x3fffffff))
        ResizeAudioStream(reinterpret_cast<Allocator*>(svc->m_heap), this, 4);
    m_pData[m_iArrayLength] = value;
    m_iArrayLength += 1;
}
struct InplaceIntArr4 : SubArrInt {
    int m_kStorage[4];
};
struct ArrView {
    void *m_pData;
    int m_iArrayLength;
    int m_iElt;
};
struct ObjA {
    void *vtable;
    unsigned short memorySize; unsigned short referenceCount; int field_008; int field_00c; int field_010;
    __declspec(nothrow) void FUN_00d76ca0() throw();
    __forceinline ObjA() throw() { FUN_00d76ca0(); }
    __forceinline ~ObjA() throw() { ReleaseStorage_00d76940(); }
    __declspec(nothrow) void UpdateState_00d76d90(void *out) throw();
    __declspec(nothrow) void ReleaseStorage_00d76940();
    __declspec(nothrow) int GetInnerField1A8();
    __declspec(nothrow) void hkgpConvexHull_build_00d77200(View *view, ObjB *obj);
    __declspec(nothrow) void hkgpMesh_bindEdgeList(void *arr) throw();
    __declspec(nothrow) void RemoveTriangle(void *item) throw();
};

struct TEnt {__forceinline int compareClear(const TEnt& v)const{const int bx=v.m_08;const int ax=m_08;if(ax<bx)return -1;if(ax>bx)return 1;const int by=v.m_0c;const int ay=m_0c;if(ay<by)return -1;if(ay>by)return 1;return 0;}__forceinline int compare(const TEnt& v)const{if(m_08<v.m_08)return -1;if(m_08>v.m_08)return 1;if(m_0c<v.m_0c)return -1;if(m_0c>v.m_0c)return 1;return 0;}static __forceinline bool ordered(const TEnt* a,const TEnt* b){int c=a->compare(*b);if(c<0)return true;if(c>0)return false;return true;}
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    unsigned int marker : 1;
    unsigned int userIndex : 31;
};
struct FlagValue56 {unsigned int value; __forceinline FlagValue56(int bits):value(bits) {} __forceinline operator int() const {return value!=0;} };
struct LowFlags56 {unsigned int value;__forceinline LowFlags56(unsigned int x):value(x){}};
static __forceinline unsigned int operator&(const LowFlags56& a,const unsigned int& b){unsigned int result=a.value;result&=b;return result;}
struct Flags56 {unsigned short bits; __forceinline LowFlags56 get() const {LowFlags56 x(bits);x.value&=7;return x;}};
struct BoundingVolumeNode {
    BoundingVolumeNode *m_00;
    int unk_04;
    TEnt *m_08[3];
    int m_14[3];
    union {
        unsigned short m_20;
        Flags56 word56;
        struct { unsigned short flags:3; unsigned short otherFlags:13; };
    };
    short unk_22;
    int field_024; int field_028; int field_02c;
};


struct VertexRecord {
    VertexRecord *next; VertexRecord *previous;
    int unknown08; int unknown0c;
    OptVec4 position;
};
struct BNode {
    __forceinline int& edgeLink(int i) {return m_14[i];}
    __forceinline void setCorners(const int& a,const int& b,const int& c) {vertices[0]=a;vertices[1]=b;vertices[2]=c;}

    __forceinline int& corner(int i) {return vertices[i];}
    BNode *next; BNode *previous;
    int vertices[3];
    int m_14[3];
    OptVec4 plane;
    int m_30; int unk_34; int m_38; int field_3c;
    int field_40; int field_44; int field_48; int field_4c;
};

struct ObjASub20 {
    void *data; int size; int capacity; void *head; int count; int unknown;
    __declspec(nothrow) BNode *UpdateFields_00e241a0(void *buf) throw();
};
struct ObjASub8 {
    void *data; int size; int capacity; void *head; int count; int unknown;
    __declspec(nothrow) void hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(void *node) throw();
    __forceinline void removeVertex(struct VertexRecord *v) throw();
};

__declspec(nothrow) void __cdecl ValidateTriangleAndComputePlane(void *a, void *b, void *c, void *d, int e) throw();

struct FillHolesMesh {
    int field_000; int field_004;
    ObjASub8 m_kVertices;
    ObjASub20 m_uiTriangleCount;
    int field_038; int field_03c; int field_040; int field_044;
    int field_048; int field_04c; int field_050; int field_054;
    int field_058; int field_05c; int field_060; int field_064;
    int field_068; int field_06c; int field_070; int field_074;
    int field_078; int field_07c; int field_080; int field_084;
    int field_088; int field_08c; int field_090; int field_094;
    int field_098; int field_09c; int field_0a0; int field_0a4;
    int field_0a8; int field_0ac; int field_0b0; int field_0b4;
    int field_0b8; int field_0bc; int field_0c0; int field_0c4;
    int field_0c8; int field_0cc; int field_0d0; int field_0d4;
    int field_0d8; int field_0dc; int field_0e0; int field_0e4;
    int field_0e8; int field_0ec; int field_0f0; int field_0f4;
    int field_0f8; int field_0fc;
    char field_100; char m_101;
    __declspec(nothrow) void hkgpMesh_bindEdgeList(void *arr);
    __declspec(nothrow) void RemoveTriangle(void *item);
    __declspec(nothrow) void ValidateTriangleAndComputePlane(void *a, void *b, void *c, void *d, int e) throw();
    __declspec(nothrow) void FillMeshBoundaryHoles(ParameterHandle param);
};

static __forceinline int CompareVerts(const TEnt *a, const TEnt *b)
{
    if (a->m_08 < b->m_08) return -1;
    if (a->m_08 > b->m_08) return 1;
    if (a->m_0c < b->m_0c) return -1;
    if (a->m_0c > b->m_0c) return 1;
    return 0;
}
static __forceinline int AreaParts(int x0,int y0,int x1,int y1,int x2,int y2) {
    int dx=x1-x0, dy=y1-y0, ex=x2-x0, ey=y2-y0;
    return dx*ey-dy*ex;
}
static __forceinline int Orient(const TEnt *b, const TEnt *a, const TEnt *c)
{
    return AreaParts(a->m_08,a->m_0c,b->m_08,b->m_0c,c->m_08,c->m_0c);
}
struct HBool { char m_cBooleanValue; __forceinline HBool(bool b) { m_cBooleanValue = (char)b; } __forceinline operator bool() const { return m_cBooleanValue != 0; } };

struct SavedFlag56 {unsigned int state; __forceinline SavedFlag56(const FlagValue56& x):state((char)x.value!=0) {} __forceinline operator int() const {return state;}};
static __forceinline unsigned long packEdgeUid(void* triangle,unsigned int index) {return *(const unsigned long*)&triangle+(unsigned long)index;}
template<class T,class I> static __forceinline void unpackEdgeUid(const unsigned long& value,T*& triangle,I& index) {unsigned long packed=value;index=I(packed&3);packed&=~3;triangle=*(T**)&packed;}
static __forceinline bool clearOrdered(const TEnt* a,const TEnt* b){return a->compareClear(*b)<=0;}
struct TEdge {
    BoundingVolumeNode *t; int i;
    __forceinline TEdge() {}
    __forceinline TEdge(BoundingVolumeNode *tt, int ii) : t(tt), i(ii) {}
    __forceinline TEnt *&start() const { return t->m_08[i]; }
    __forceinline TEnt *&end() const { return t->m_08[(9 >> (i << 1)) & 3]; }
    __forceinline TEdge next() const { TEdge r;r.t=t;r.i=(9>>(i*2))&3;return r; }
    __forceinline TEdge prev() const { TEdge r;r.t=t;r.i=(18>>(i*2))&3;return r; }
    __forceinline TEdge link() const { TEdge e;unpackEdgeUid(t->m_14[i],e.t,e.i);return e; }
    __forceinline bool hasLink() const { return (t->m_14[i] & ~3) != 0; }
    __forceinline bool isMaster() const { return TEnt::ordered(start(),end()) || !hasLink(); }
    __forceinline TEdge master() const { if (isMaster()) return *this; return link(); }
    __forceinline bool isConstrained() const {TEdge m=master();return 0!=(m.t->flags & (1<<m.i));}
__forceinline int take() const {const int r=isConstrained();if(r)clearConstrained();return r;}
    __forceinline HBool hb() const { TEdge m = master(); return (m.t->flags & (1 << m.i)) != 0; }
    __forceinline void setConstrained() const { TEdge m = master(); m.t->flags = m.t->m_20 | (1 << m.i); }
    __forceinline void clearConstrained() const { TEdge m = master(); m.t->flags &= ~(1 << m.i); }__forceinline bool clearIsMaster()const{return clearOrdered(start(),end()) || !hasLink();}__forceinline TEdge masterClear()const{if(clearIsMaster())return *this;return link();}__forceinline void clearSpecial()const{TEdge m=masterClear();m.t->flags &= ~(1<<m.i);}
    __forceinline void bind(const TEdge &o) const
    {
        t->m_14[i] = packEdgeUid(o.t,o.i);
        if (o.t) o.t->m_14[o.i] = packEdgeUid(t,i);
    }
};

static __forceinline unsigned __int64 bindingBitsCw(const TEdge& e){return *(const unsigned __int64*)&e;}
static __forceinline void bindSourceCw(unsigned __int64 bits,TEdge target){((BoundingVolumeNode*)(unsigned)bits)->m_14[(unsigned)(bits>>32)]=packEdgeUid(target.t,target.i);if(target.t)target.t->m_14[target.i]=(unsigned)bits+(unsigned)(bits>>32);}
static __forceinline void bindPackedCw(TEdge self,unsigned __int64 bits){BoundingVolumeNode* t=(BoundingVolumeNode*)(unsigned)bits;unsigned i=(unsigned)(bits>>32);self.t->m_14[self.i]=packEdgeUid(t,i);if(t)t->m_14[i]=packEdgeUid(self.t,self.i);}
static __forceinline unsigned __int64 linkedBitsCw(TEdge e){unsigned long raw=e.t->m_14[e.i];TEdge r;r.i=raw&3;r.t=(BoundingVolumeNode*)(raw&~3);return *(const unsigned __int64*)&r;}
__forceinline void ObjASub8::removeVertex(VertexRecord *v) throw()
{
    VertexRecord *nxt = v->next;
    VertexRecord *prv = v->previous;
    if (nxt)
        nxt->previous = prv;
    if (prv)
        prv->next = nxt;
    else
        head = nxt;
    count -= 1;
    hkGeometryProcessing_PoolAllocator_hkgpMeshBase_Triangle_32_hkContainerHeapAllocator_release(v);
}
struct TEdgeB {
    BNode *t; int i;
    __forceinline TEdgeB(BNode *tt, int ii) : t(tt), i(ii) {}
    __forceinline int start() const { return t->vertices[i]; }
    __forceinline int end() const { return t->vertices[(9 >> (i << 1)) & 3]; }
};
static __forceinline int PStart(const Pair &x) { return ((BNode *)x.a)->vertices[x.b]; }
static __forceinline int PEnd(const Pair &x) { return ((BNode *)x.a)->vertices[(9 >> (x.b << 1)) & 3]; }
struct EdgeMapEntry { TEnt *start; TEnt *end; void *value; };
struct EdgeMapBucket { EdgeMapEntry *m_pData; int m_iArrayLength; int m_iCap; };
struct EdgeMap { EdgeMapBucket *buckets; unsigned int numBuckets; };

// edge -> value lookup keyed on the edge's two vertex positions
void *BigSolver::LookupPairResult(void *pair) throw()
{
    const Pair *e = (const Pair *)pair;
    BoundingVolumeNode *t = (BoundingVolumeNode *)e->a;
    if (!t || !edgeMap)
        return 0;
    TEnt *a = t->m_08[e->b];
    TEnt *b = t->m_08[(9 >> (e->b << 1)) & 3];
    unsigned int hash = (unsigned int)(a->m_0c * 0x3442a5 + a->m_08 * 0x21528000) ^
                        (unsigned int)(b->m_0c * 0x1958e9 - b->m_08 * 0x538b8000);
    EdgeMapBucket &bucket = edgeMap->buckets[hash % edgeMap->numBuckets];
    int found = -1;
    for (int k = 0; k < bucket.m_iArrayLength; k++) {
        if (bucket.m_pData[k].start == a && bucket.m_pData[k].end == b) {
            found = k;
            break;
        }
    }
    if (found == -1)
        return 0;
    EdgeMapEntry *entry = &bucket.m_pData[found];
    return entry ? entry->value : 0;
}

// true when more boundary edges are mapped than missing
int BigSolver::CheckLinks() throw()
{
    int mapped = 0;
    int missing = 0;
    for (BoundingVolumeNode *t = (BoundingVolumeNode *)mesh.triangles.head; t; t = t->m_00) {
        if (!(t->m_20 & 0x10))
            continue;
        for (int i = 0; i < 3; i++) {
            TEdge e(t, i);
            if (!e.hasLink()) {
                if (LookupPairResult(&e)) mapped++;
                else missing++;
            } else {
                TEdge l = e.link();
                if (LookupPairResult(&e)) mapped++;
                else if (LookupPairResult(&l)) missing++;
            }
        }
    }
    return mapped > missing;
}

enum { VerifySolverSize = 1 / (sizeof(BigSolver)==0x6e0 ) };
enum { VerifyBoundarySize = 1 / (sizeof(BoundaryEntry)==0x40 ) };
enum { VerifyOptionsSize = 1 / (sizeof(ObjB)==0x10 ) };
enum { VerifyViewSize = 1 / (sizeof(View)==0x0c ) };
enum { VerifyVertexSize = 1 / (sizeof(VertexRecord)==0x20 ) };
enum { VerifyTriangleSize = 1 / (sizeof(BNode)==0x50 ) };


__forceinline OptVec4 BigSolver::projectWorld(const OptVec4& p) const {
    OptVec4 result; const __m128& q=p.q();
    const __m128 sum=_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(q,q,0x55),col1.q()),_mm_mul_ps(_mm_shuffle_ps(q,q,0),col0.q())),_mm_mul_ps(_mm_shuffle_ps(q,q,0xaa),col2.q()));
    _mm_store_ps(&result.x,_mm_add_ps(sum,col3.q())); return result;
}
static __forceinline int roundCoord(float v) {double d=v<0.0f?v-0.5:v+0.5;return (int)d;}
static __forceinline int boundCoord(int x,int lo,int hi) {return x<lo?lo:(x>hi?hi:x);}
__forceinline TEnt BigSolver::quantizeWorld(const OptVec4& p) const {
    const int lo=baseVal,hi=0x7fff-lo;TEnt result;
    result.m_08=boundCoord(roundCoord(p.x),lo,hi);result.m_0c=boundCoord(roundCoord(p.y),lo,hi);return result;
}
__forceinline TEnt BigSolver::transformWorld(const OptVec4& p) const {return quantizeWorld(projectWorld(p));}
static __forceinline void buildGrid(HArr<OptVec4>& arr,OptVec4& akGridVector) throw() {
    int i = 0;

    _mm_store_ps(&akGridVector.x, _mm_setzero_ps());
    for (; i < 8; i++) {
        OptVec4 pt;
        _mm_store_ps(&pt.x, _mm_load_ps(&akGridVector.x));
        pt.y = (float)(i / DAT_01015a40);
        for (int sv = 0; sv < 8; sv++) {
            pt.x = (float)(sv / DAT_01015a40);
            hkMemoryRouter *svc = ((hkMemoryRouter*)&hkMemoryRouter_getInstance());
            if (arr.m_iArrayLength == (arr.m_iCap & 0x3fffffff))
                ResizeAudioStream(reinterpret_cast<Allocator*>(svc->m_heap), &arr, 0x10);
            OptVec4 *elem = &((OptVec4*)arr.m_pData)[arr.m_iArrayLength];
            arr.m_iArrayLength++;
            Geometry_MapCoordinatesToSphere(&pt, elem);
        }
    }
}

static __forceinline void scanFlip(BigSolver& solver, const PairArr& pairs, const SubArrInt& arr2, bool& flag) throw()
{
// <<REGION flip_scan>>

    Pair* const& pd = pairs.m_pData;
    for (int rep = 0; rep < 1; rep++) {
        for (BoundingVolumeNode* tn=(BoundingVolumeNode*)solver.mesh.triangles.head; flag && tn; tn=tn->m_00) {
            if ((tn->m_20 & 0xfff0) != 0x10) continue;
            for (int tidx = 0; flag && tidx < 3; tidx++) {
                TEdge e(tn, tidx);
                if ((e.link().t->m_20 & 0xfff0) != 0x10)
                    continue;
                const int va = arr2.m_pData[e.start()->userIndex];
                const int vb = arr2.m_pData[e.end()->userIndex];
                for (int p = 0; p < pairs.m_iArrayLength; p++) {
                    if (!((PStart(pd[p]) == va && PEnd(pd[p]) == vb) || (PStart(pd[p]) == vb && PEnd(pd[p]) == va)))
                        continue;
                    if (!e.hasLink() || e.isConstrained()) {
                        flag = false;
                        continue;
                    }
                    TEdge l=e.link();
                    TEdge ep=e.prev();
                    TEdge lp;
                    lp = l.prev();
                    if (Orient(e.start(), ep.start(), lp.start()) <= 0 ||
                        Orient(l.start(), lp.start(), ep.start()) <= 0) {
                        flag = false;
                        continue;
                    }
// <</REGION flip_scan>>
// <<REGION flip_flags>>
                    _ReadWriteBarrier();TEdge master1 = ep.master();
                    int c1=0!=(master1.t->flags & (1<<master1.i));
                    if (c1)
                        ep.clearSpecial();
                    TEdge l2=e.link();
                    TEdge l2p=l2.prev();
                    int c2=l2p.isConstrained();
                    if (c2)
                        l2p.clearSpecial();
// <</REGION flip_flags>>
// <<REGION flip_bind>>
                    TEdge f;
                    f = e.link();
                    TEdge fp=f.prev();
                    tn->m_08[tidx] = fp.start();
                    f.t->m_08[f.i] = ep.start();
                    bindPackedCw(f,linkedBitsCw(ep));
                    bindPackedCw(e,bindingBitsCw(fp.link()));
                    bindSourceCw(bindingBitsCw(ep),fp);
                    if (c1) {
                        TEdge m;
                        m = ep.link().next().master();
                        m.t->m_20 |= (1 << m.i) & 7;
                    }
                    if (c2)
                        ep.next().setConstrained();
                    rep = -1;
                }
            }
        }
    }

// <</REGION flip_bind>>
}
static __forceinline Pair nextBlank(unsigned& state){if((state&1)==0){state|=1;DAT_0126ebf0=state;DAT_0126ebec=DAT_0126ebe8=0;}Pair r;r.b=DAT_0126ebec;r.a=DAT_0126ebe8;return r;}
static __forceinline void closeBoundaries(FillHolesMesh& owner,Param* param,HullTriangle& nodeStorage,int& counterB8) throw() {
    if ((bool)param->m_08) {
        bool y;
        EdgeSelection selection;
        y = true;
        float bestScore;
        unsigned state;
        for (;;) {
state=DAT_0126ebf0;selection.first=nextBlank(state);selection.second=nextBlank(state);bestScore=DAT_0104da48;
            for (BoundingVolumeNode *bn = (BoundingVolumeNode *)owner.m_uiTriangleCount.head; bn; bn = bn->m_00) {
                for (int idx = 0; idx < 3; idx++) {
                    if ((bn->m_14[idx] & ~3) != 0)
                        continue;
                    TEdge w(bn, (9 >> (idx << 1)) & 3);
                    if (!w.hasLink())
                        continue;
                    do {
                        int link = w.t->m_14[w.i];
                        BoundingVolumeNode *nextNode = (BoundingVolumeNode *)(link & ~3);
                        int nextIndex = (9 >> ((link & 3) * 2)) & 3;
                        w = TEdge(nextNode, nextIndex);
                    } while (w.hasLink());
                    if (w.t == bn)
                        continue;
                    OptVec4 va = ((VertexRecord*)bn->m_08[(9 >> (idx << 1)) & 3])->position;
                    OptVec4 vb = ((VertexRecord*)bn->m_08[idx])->position;
                    _mm_store_ps(&vb.x, _mm_sub_ps(vb.q(), va.q()));
                    OptVec4 vc = ((VertexRecord*)w.t->m_08[(9 >> (w.i << 1)) & 3])->position;
                    _mm_store_ps(&vc.x, _mm_sub_ps(vc.q(), va.q()));
                    __m128 cross = _mm_sub_ps(
                        _mm_mul_ps(_mm_shuffle_ps(vc.q(), vc.q(), 0xd2), _mm_shuffle_ps(vb.q(), vb.q(), 0xc9)),
                        _mm_mul_ps(_mm_shuffle_ps(vc.q(), vc.q(), 0xc9), _mm_shuffle_ps(vb.q(), vb.q(), 0xd2)));
                    if (y) {
                        __m128 d1 = _mm_mul_ps(_mm_load_ps(&((BNode*)bn)->plane.x), cross);
                        float dot1;
                        _mm_store_ss(&dot1, _mm_add_ss(_mm_shuffle_ps(d1,d1,0xaa),
                            _mm_add_ss(_mm_shuffle_ps(d1,d1,0x55),d1)));
                        if (!(dot1 > 0.0f))
                            continue;
                        __m128 d2 = _mm_mul_ps(_mm_load_ps(&((BNode*)w.t)->plane.x), cross);
                        float dot2;
                        _mm_store_ss(&dot2, _mm_add_ss(_mm_shuffle_ps(d2,d2,0xaa),
                            _mm_add_ss(_mm_shuffle_ps(d2,d2,0x55),d2)));
                        if (!(dot2 > 0.0f))
                            continue;
                    }
                    __m128 sqA = _mm_mul_ps(vb.q(), vb.q());
                    float valA;
                    _mm_store_ss(&valA, _mm_add_ss(_mm_shuffle_ps(sqA,sqA,0xaa),
                        _mm_add_ss(_mm_shuffle_ps(sqA,sqA,0x55),sqA)));
                    if (valA == 0.0f)
                        continue;
                    float invA = 1.0f / (float)sqrt((double)valA);
                    _mm_store_ps(&vb.x, _mm_mul_ps(_mm_set_ps1(invA), vb.q()));
                    __m128 sqB = _mm_mul_ps(vc.q(), vc.q());
                    float lenB;
                    _mm_store_ss(&lenB, _mm_add_ss(_mm_shuffle_ps(sqB,sqB,0xaa),
                        _mm_add_ss(_mm_shuffle_ps(sqB,sqB,0x55),sqB)));
                    if (lenB == 0.0f)
                        continue;
                    float invB = 1.0f / (float)sqrt((double)lenB);
                    _mm_store_ps(&vc.x, _mm_mul_ps(_mm_set_ps1(invB), vc.q()));
                    __m128 prod = _mm_mul_ps(vc.q(), vb.q());
                    float dotT;
                    _mm_store_ss(&dotT, _mm_add_ss(_mm_shuffle_ps(prod,prod,0xaa),
                        _mm_add_ss(_mm_shuffle_ps(prod,prod,0x55),prod)));
                    float ang = ClampedAcos(dotT);
                    if (ang < bestScore) {
                        bestScore = ang;
                        selection.first.a = (int)bn;
                        selection.first.b = idx;
                        selection.second.a = (int)w.t;
                        selection.second.b = w.i;
                    }
                }
            }
// <</REGION close_search>>
// <<REGION close_emit>>
            if (selection.first.a) {
                BoundingVolumeNode *bn = (BoundingVolumeNode *)selection.first.a;
                BoundingVolumeNode *other = (BoundingVolumeNode *)selection.second.a;
                int bi = selection.first.b;
                int bs = selection.second.b;
                int vA = (int)bn->m_08[(9 >> (bi << 1)) & 3];
                int closingVertices[2]={(int)bn->m_08[bi],(int)other->m_08[(9 >> (bs << 1)) & 3]};
                BNode *nb = owner.m_uiTriangleCount.UpdateFields_00e241a0(&nodeStorage);
                nb->m_30 = ((BNode*)bn)->m_30;
                nb->m_14[0] = 0;
                nb->m_14[1] = 0;
                nb->m_14[2] = 0;
                nb->m_38 = ((BNode*)bn)->m_38;
                nb->vertices[0] = vA;
                nb->vertices[1] = closingVertices[0];
                nb->vertices[2] = closingVertices[1];
                
                ((BoundsMesh*)&owner)->ValidateTriangleAndComputePlane((const __m128*)&((VertexRecord*)nb->corner(0))->position,(const __m128*)&((VertexRecord*)nb->corner(1))->position,(const __m128*)&((VertexRecord*)nb->corner(2))->position,(__m128*)&nb->plane,true);
                unsigned __int64 packedOther=*(unsigned __int64*)&selection.second;
                bn->m_14[bi] = (int)nb;
                nb->m_14[0] = packEdgeUid(bn,bi);
                nb->m_14[2] = packEdgeUid((BoundingVolumeNode*)(unsigned)packedOther,(unsigned)(packedOther>>32));
                if ((BoundingVolumeNode*)(unsigned)packedOther)
                    ((BoundingVolumeNode*)(unsigned)packedOther)->m_14[(unsigned)(packedOther>>32)] = packEdgeUid(nb,2);
                counterB8 += 1;
                y = true;
            } else {
                if (!y)
                    break;
                y = false;
            }
        }

    }
}
template<class T> static __forceinline void exchangeValues(T& a,T& b) {T saved=a;a=b;b=saved;}
struct ReportFrame { CharBuffer stream; };
struct ParameterHandle {Param* value; __forceinline Param* operator->() const {return value;} __forceinline operator Param*() const {return value;} };
static __forceinline void appendCountSummary(CharBuffer& os,int triangles,int vertices) {os.ProcessAndReturnValue_00cc01c0(&DAT_010eb100)->WriteInt(triangles)->ProcessAndReturnValue_00cc01c0(&DAT_010eb10c)->WriteInt(vertices)->ProcessAndReturnValue_00cc01c0(&DAT_010eb11c);}
// Iterates boundary nodes to fill mesh holes by solving triangulations, then closes remaining boundaries and reports the repair counts.
// @fnv 0x00e1f4e0
// src: GUESS 0x00e1f4e0 (confidence: medium)
void FillHolesMesh::FillMeshBoundaryHoles(ParameterHandle param)
{
// <<REGION setup>>
    int iSavedTriangleCount;
    HullTriangle nodeStorage;
    iSavedTriangleCount = m_uiTriangleCount.count;
    int iSavedVertexCount;
    iSavedVertexCount = m_kVertices.count;
    int repaired = 0;
    int counterB8 = 0;
    HArr<OptVec4> arr;
    OptVec4 akGridVector;
    {
    int i = 0;

    _mm_store_ps(&akGridVector.x, _mm_setzero_ps());
    for (; i < 8; i++) {
        OptVec4 pt;
        _mm_store_ps(&pt.x, _mm_load_ps(&akGridVector.x));
        pt.y = (float)(i / DAT_01015a40);
        for (int sv = 0; sv < 8; sv++) {
            pt.x = (float)(sv / DAT_01015a40);
            hkMemoryRouter *svc = ((hkMemoryRouter*)&hkMemoryRouter_getInstance());
            if (arr.m_iArrayLength == (arr.m_iCap & 0x3fffffff))
                ResizeAudioStream(reinterpret_cast<Allocator*>(svc->m_heap), &arr, 0x10);
            OptVec4 *elem = &((OptVec4*)arr.m_pData)[arr.m_iArrayLength];
            arr.m_iArrayLength++;
            Geometry_MapCoordinatesToSphere(&pt, elem);
        }
    }
}
// <</REGION setup>>
// <<REGION boundary>>
    if (!!param->m_04) {
    SubArrInt arr2;
    arr2.m_pData = 0;
    arr2.m_iArrayLength = 0;
    arr2.m_iCap = (int)0x80000000;
    bool counterC4;
    do {
    counterC4 = false;
    NodeRes* res; (void)res;
    for (Node123 *node = (Node123 *)m_uiTriangleCount.head; node; node = (Node123 *)node->m_00) {
        bool flag = false;
        for (int idx = 0; 3 > idx; idx++) {
            if ((node->m_14[idx] & ~3) != 0)
                continue;
            res = hkgpMeshInternals_createRing(node, idx);
            if (!res)
                continue;
            if (res->m_04 < 3)
                continue;
            arr2.m_iArrayLength = 0;
            for (int boundaryIndex57 = 0; boundaryIndex57 < res->m_04; boundaryIndex57++) {
                BoundaryEntry *entry = &res->m_00[boundaryIndex57];
                arr2.append(((BNode*)entry->edge.a)->vertices[entry->edge.b]);
            }
            ObjA objA;
            HArr<OptVec4> aPositions;
            {
                int need = arr2.m_iArrayLength;
                hkMemoryRouter& router = hkMemoryRouter_getInstance();
                Allocator *ctx=(Allocator*)reinterpret_cast<Allocator*>(router.m_heap);
                int capMask = aPositions.m_iCap & 0x3fffffff;
                if (capMask < need) {
                    int twice = capMask * 2;
                    hkArrayUtil__reserve((int)ctx, &aPositions, need < twice ? twice : need, 0x10);
                }
                aPositions.m_iArrayLength = need;
                int k2 = 0;
                if (k2 < arr2.m_iArrayLength) {
                    int byteOffset = 0;
                    do {
                        *(OptVec4*)((unsigned char*)aPositions.m_pData + byteOffset) =
                            ((VertexRecord*)arr2.m_pData[k2])->position;
                        ++k2;
                        byteOffset += 16;
                    } while (k2 < arr2.m_iArrayLength);
                }
            }
            ObjB objB;
            objB.hkgpConvexHull_BuildConfig_BuildConfig();
            View view;
            view.m_pData = aPositions.m_pData;
            view.m_iArrayLength = aPositions.m_iArrayLength;
            objB.enabled = 1;
            view.stride = 0x10;
            ((ObjA*)&objA)->hkgpConvexHull_build_00d77200(&view, &objB);
            int e2 = objA.GetInnerField1A8();
            if (e2 >= 2) {
                OptVec4 plane;
                ((ObjA*)&objA)->UpdateState_00d76d90(&plane);
// <</REGION boundary>>
// <<REGION solver>>
                for (int attempt=0; !counterC4 && attempt < arr.m_iArrayLength + 1; ++attempt) {
                BigSolver solver;

                flag = true;
                ArrView arrView = {aPositions.m_pData, aPositions.m_iArrayLength, 0x10};
                solver.UpdateBoundsForZRotation(&arrView, &plane, 1, 1);
                {
                    for (int iIndex = 0; iIndex < arr2.m_iArrayLength; iIndex++) {
                        const TEnt point=solver.transformWorld(((VertexRecord*)arr2.m_pData[iIndex])->position);
                        HoleQuery pForm=solver.LocatePoint(point.m_08,point.m_0c);
                        HoleQuery kResult=solver.hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_insertVertex(point.m_08,point.m_0c,1,&pForm,0);
                        if (kResult.status == 0) {
                            TEnt *cell = ((BoundingVolumeNode*)kResult.edge.a)->m_08[kResult.edge.b];
                            cell->userIndex = iIndex;
                        } else {
                            flag = false;
                        }

                    }
                }
// <</REGION solver>>
// <<REGION constraints>>
                
                
                PairArr pairs;
                {
                    for (int iConstraint = 0; iConstraint < res->m_04; iConstraint++) {
                        {
                            const Pair &source = res->m_00[iConstraint].edge;
                            hkMemoryRouter *svc = ((hkMemoryRouter*)&hkMemoryRouter_getInstance());
                            if (pairs.m_iArrayLength == (pairs.m_iCap & 0x3fffffff))
                                ResizeAudioStream(reinterpret_cast<Allocator*>(svc->m_heap), &pairs, 8);
                            new(pairs.m_pData + pairs.m_iArrayLength) Pair(source);
                            ++pairs.m_iArrayLength;
                        }
                        {
                            const Pair *source = &res->m_00[iConstraint].edge;
                            Pair value;
                            value.b = (9 >> (source->b << 1)) & 3;
                            value.a = source->a;
                            hkMemoryRouter *svc;
                            svc = ((hkMemoryRouter*)&hkMemoryRouter_getInstance());
                            if (pairs.m_iArrayLength == (pairs.m_iCap & 0x3fffffff))
                                ResizeAudioStream(reinterpret_cast<Allocator*>(svc->m_heap), &pairs, 8);
                            new(pairs.m_pData + pairs.m_iArrayLength) Pair(value);
                            ++pairs.m_iArrayLength;
                        }
                        {
                            const Pair *source = &res->m_00[iConstraint].edge;
                            Pair value;
                            value.b = (0x12 >> (source->b << 1)) & 3;
                            value.a = source->a;
                            hkMemoryRouter *svc;
                            svc = ((hkMemoryRouter*)&hkMemoryRouter_getInstance());
                            if (pairs.m_iArrayLength == (pairs.m_iCap & 0x3fffffff))
                                ResizeAudioStream(reinterpret_cast<Allocator*>(svc->m_heap), &pairs, 8);
                            new(pairs.m_pData + pairs.m_iArrayLength) Pair(value);
                            ++pairs.m_iArrayLength;
                        }
                        InplaceIntArr4 intArr;
                        intArr.m_pData = intArr.m_kStorage;
                        intArr.m_iArrayLength = 0;
                        intArr.m_iCap = (int)0x80000004;
                        {
                            hkMemoryRouter *svc;
                            svc = ((hkMemoryRouter*)&hkMemoryRouter_getInstance());
                            if (intArr.m_iArrayLength == (intArr.m_iCap & 0x3fffffff))
                                ResizeAudioStream(reinterpret_cast<Allocator*>(svc->m_heap), &intArr, 4);
                            intArr.m_pData[intArr.m_iArrayLength] = iConstraint;
                            intArr.m_iArrayLength += 1;
                        }
                        Pair edge = res->m_00[iConstraint].edge;
                        BNode *pEdgeNode=(BNode*)edge.a;
                        int ecnt=edge.b;
                        int idxA = (9 >> (ecnt << 1)) & 3;
                        const TEnt endPoint=solver.transformWorld(((VertexRecord*)pEdgeNode->vertices[idxA])->position);
                        const TEnt startPoint=solver.transformWorld(((VertexRecord*)pEdgeNode->vertices[ecnt])->position);
                        HoleQuery out26010=solver.hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_insertEdge(startPoint.m_08,startPoint.m_0c,endPoint.m_08,endPoint.m_0c,1,&intArr);
                        if (0 != out26010.status)
                            flag = false;
                        {
                            hkMemoryRouter *svc = ((hkMemoryRouter*)&hkMemoryRouter_getInstance());
                            Allocator *ctx = reinterpret_cast<Allocator*>(svc->m_heap);
                            int cap = intArr.m_iCap;
                            intArr.m_iArrayLength = 0;
                            if ((cap & 0x80000000) == 0)
                                ctx->freeBlock(intArr.m_pData, (cap & 0x3fffffff) * 4);
                        }

                    }
                }
// <</REGION constraints>>
// <<REGION flip_call>>
                if (solver.hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_partition() < 2)
                    flag = false;
                solver.hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_conformEdges();
                scanFlip(solver, pairs, arr2, flag);
                (void)pairs;
// <</REGION flip_call>>
// <<REGION rebuild>>
                int orientation=solver.CheckLinks();
                if (orientation != 0)
                    flag = false;
                if (flag) {
                    int iSavedCount = arr2.m_iArrayLength;
                    PairArr aUnlinkedEdges;
                    HArr<int> aNewNodes;
                    for (BoundingVolumeNode *pNode = (BoundingVolumeNode *)solver.mesh.triangles.head; pNode; pNode = pNode->m_00) {
                        if ((pNode->m_20 & 0xfff0) != 0x10)
                            continue;
VertexRecord* vtx[3];
vtx[0]=(VertexRecord*)arr2.m_pData[pNode->m_08[0]->userIndex];
vtx[1]=(VertexRecord*)arr2.m_pData[pNode->m_08[1]->userIndex];
vtx[2]=(VertexRecord*)arr2.m_pData[pNode->m_08[2]->userIndex];
if(orientation) exchangeValues(vtx[1],vtx[2]);
                        BNode *pNewNode = m_uiTriangleCount.UpdateFields_00e241a0(&nodeStorage);
                        BNode *pSourceNode = (BNode *)node;
                        pNewNode->m_30 = pSourceNode->m_30;
                        pNewNode->edgeLink(0) = 0;
                        pNewNode->edgeLink(1) = 0;
                        pNewNode->edgeLink(2) = 0;
                        pNewNode->m_38 = pSourceNode->m_38;
                        pNewNode->setCorners((int)vtx[0],(int)vtx[1],(int)vtx[2]);
                        ValidateTriangleAndComputePlane(&((VertexRecord*)pNewNode->corner(0))->position,
                            &((VertexRecord*)pNewNode->corner(1))->position,
                            &((VertexRecord*)pNewNode->corner(2))->position, &pNewNode->plane, 1);
                        for (int bi = 0; bi < 3; bi++) {
                            int raw = pNode->m_14[bi];
                            Pair kPair;
                            kPair.b = raw & 3;
                            kPair.a = raw & ~3;
                            void *found = solver.LookupPairResult(&kPair);
                            if (found) {
                                int eidx = **(int**)found;
                                BoundaryEntry *pEntry = &res->m_00[eidx];
                                pNewNode->m_14[bi] = packEdgeUid((void*)pEntry->edge.a,pEntry->edge.b);
                                if (pEntry->edge.a)
                                    ((BNode*)pEntry->edge.a)->m_14[pEntry->edge.b] = packEdgeUid(pNewNode,bi);
                            } else {
                                aUnlinkedEdges.append(Pair((int)pNewNode,bi));
                            }
                        }
                        {
                            hkMemoryRouter *svc;
                            svc = ((hkMemoryRouter*)&hkMemoryRouter_getInstance());
                            if (aNewNodes.m_iArrayLength == (aNewNodes.m_iCap & 0x3fffffff))
                                ResizeAudioStream(reinterpret_cast<Allocator*>(svc->m_heap), &aNewNodes, 4);
                            aNewNodes.m_pData[aNewNodes.m_iArrayLength] = (int)pNewNode;
                            aNewNodes.m_iArrayLength++;
                        }
                    }
// <</REGION rebuild>>
// <<REGION rollback>>
                    this->hkgpMesh_bindEdgeList(&aUnlinkedEdges);
                    if (!aUnlinkedEdges.m_iArrayLength) {
                        repaired++;
                        counterC4 = true;
                    } else {
                        flag = false;
                        for (int ai = 0; ai < aNewNodes.m_iArrayLength; ai++)
                            this->RemoveTriangle((void *)aNewNodes.m_pData[ai]);
                        for (int ui = iSavedCount; ui < arr2.m_iArrayLength; ui++) {
                            m_kVertices.removeVertex((VertexRecord *)arr2.m_pData[ui]);
                        }
                        {
                            hkMemoryRouter *svc = ((hkMemoryRouter*)&hkMemoryRouter_getInstance());
                            Allocator *ctx = reinterpret_cast<Allocator*>(svc->m_heap);
                            int cap = arr2.m_iCap;
                            int capacity;
                            capacity = cap&0x3fffffff;
                            if (capacity < iSavedCount)
                                hkArrayUtil__reserve((int)ctx, &arr2, iSavedCount<capacity*2 ? capacity*2 : iSavedCount, 4);
                            arr2.m_iArrayLength = iSavedCount;
                        }
                    }
                    (void)repaired;
                }
                if (!flag)
                    _mm_store_ps(&plane.x, _mm_load_ps(&((OptVec4*)arr.m_pData)[attempt-1].x));
// <</REGION rollback>>
// <<REGION cleanup>>
                }
            }
            res->ClearAndFree(1);
            if (counterC4) break;
        }
        if (counterC4) break;
    }
    } while (counterC4);
    {
        hkMemoryRouter *svc = ((hkMemoryRouter*)&hkMemoryRouter_getInstance());
        Allocator *ctx = reinterpret_cast<Allocator*>(svc->m_heap);
        int cap = arr2.m_iCap;
        arr2.m_iArrayLength = 0;
        if ((cap & 0x80000000) == 0)
            ctx->freeBlock(arr2.m_pData, (cap & 0x3fffffff) * 4);
    }

    }
// <</REGION cleanup>>
// <<REGION close_search>>
closeBoundaries(*this,param,nodeStorage,counterB8);
// <</REGION close_emit>>
// <<REGION report>>
    m_101 = 0;
    {
    ReportFrame reportFrame;
    CharBuffer& os=reportFrame.stream;
        int buf[0x80];
        os.FUN_00cb1600((char *)buf, 0x200);
        os.ProcessAndReturnValue_00cc01c0(&DAT_010eb128);
        DAT_01268360->Report(0, -1, (char *)buf, DAT_010eaeb4, 0xc62);
        os.FUN_00cc00e0();
    }
    {
    ReportFrame reportFrame;
    CharBuffer& os=reportFrame.stream;
        int buf[0x80];
        os.FUN_00cb1600((char *)buf, 0x200);
appendCountSummary(os,m_uiTriangleCount.count-iSavedTriangleCount,m_kVertices.count-iSavedVertexCount);
        DAT_01268360->Report(0, -1, (char *)buf, DAT_010eaeb4, 0xc63);
        os.FUN_00cc00e0();
    }
    {
    ReportFrame reportFrame;
    CharBuffer& os=reportFrame.stream;
        int buf[0x80];
        os.FUN_00cb1600((char *)buf, 0x200);
        os.ProcessAndReturnValue_00cc01c0(&DAT_010eb0ec)
            ->WriteInt(repaired)
            ->ProcessAndReturnValue_00cc01c0(&DAT_010eb0f8)
            ->WriteInt(counterB8);
        DAT_01268360->Report(0, -1, (char *)buf, DAT_010eaeb4, 0xc64);
        os.FUN_00cc00e0();
    }
    (void)iSavedTriangleCount;
    (void)iSavedVertexCount;
// <</REGION report>>
}

namespace PointBoundsIntrinsics {
extern "C" __m128 _mm_min_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_max_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_set_ps1(float value);
}
extern float DAT_0104e148;
extern const __m128 DAT_010c4c10;

struct PointBoundsOutput {
    void* value;
    __forceinline PointBoundsOutput(void* address) : value(address) {}
};

// Axis-aligned bounds of count points into p[0] (min) and p[1] (max); an empty set gives the inverted default box.
// Writes the min and max of count vectors, each ANDed with DAT_010c4c10, to the two vectors at p; for count 0 writes splats of two globals.
// @fnv 0x00cbeb70
// src: XBOX_PDB 0x00cbeb70
void __cdecl hkAabbUtil_calcAabb_00cbeb70(void* apPoints, int count, PointBoundsOutput p)
{
    if (count == 0) {
        __m128* dst = (__m128*)*(void* volatile*)&p.value;
        dst[0] = PointBoundsIntrinsics::_mm_set_ps1(DAT_0104da48);
        dst[1] = PointBoundsIntrinsics::_mm_set_ps1(DAT_0104e148);
        return;
    }
    const __m128* points = (const __m128*)apPoints;
    __m128 mn = *points;
    __m128 mx = mn;
    if (count > 1) {
        points++;
        count--;
        do {
            __m128 q = *points;
            points++;
            mn = PointBoundsIntrinsics::_mm_min_ps(mn, q);
            mx = PointBoundsIntrinsics::_mm_max_ps(mx, q);
            count--;
        } while (count != 0);
    }
    __m128 lo = PointBoundsIntrinsics::_mm_and_ps(DAT_010c4c10, mn);
    __m128* dst = (__m128*)p.value;
    dst[0] = lo;
    dst[1] = PointBoundsIntrinsics::_mm_and_ps(DAT_010c4c10, mx);
}

struct Point2I { int unk00, unk04; int x,y; };
struct WalkNode { WalkNode* next; };

struct WalkTriangle {
    WalkTriangle* nextNode;
    int unk04;
    Point2I* vertices[3];
    unsigned links[3];
    __forceinline Point2I*& vertex(int i) { return vertices[i]; }
};
template<class T> struct WalkEdgeBase {
    T* m_pkTriangle;
    unsigned m_uiEdgeIndex;
    WalkEdgeBase() {}
    WalkEdgeBase(T* t,unsigned i):m_pkTriangle(t),m_uiEdgeIndex(i) {}
};
struct WalkEdge:WalkEdgeBase<WalkTriangle> {
    WalkEdge() {}
    WalkEdge(WalkTriangle* t,unsigned i):WalkEdgeBase<WalkTriangle>(t,i) {}
    WalkEdge(const WalkEdge& e):WalkEdgeBase<WalkTriangle>(e.m_pkTriangle,e.m_uiEdgeIndex) {}
    WalkEdge(unsigned packed) { m_uiEdgeIndex=packed&3u; m_pkTriangle=(WalkTriangle*)(packed&~3u); }
    __forceinline Point2I*& end() const { return m_pkTriangle->vertex((9>>(2*m_uiEdgeIndex))&3); }
    __forceinline WalkEdge next() const { return WalkEdge(m_pkTriangle,(9>>(2*m_uiEdgeIndex))&3); }
    __forceinline WalkEdge prev() const { return WalkEdge(m_pkTriangle,(18>>(2*m_uiEdgeIndex))&3); }
    __forceinline WalkEdge link() const { return WalkEdge(m_pkTriangle->links[m_uiEdgeIndex]); }
    __forceinline Point2I*& start() const { return m_pkTriangle->vertex(m_uiEdgeIndex); }
};
__forceinline const WalkEdge& noWalkEdge() {
    static const WalkEdge edge(0,0);
    return edge;
}

struct WalkHit {
    int kind;
    WalkEdge edge;
    WalkHit(int k,const WalkEdge& e):kind(k),edge(e) {}
};
struct MeshWalk {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30;
    WalkNode* head;
    int maxSteps;
    __forceinline WalkHit find(WalkEdge edge,int x,int y) const;
};
extern char DAT_010eafd4[],DAT_010eaf60[];
__forceinline int sideScalars(int ax,int ay,int bx,int by,int x,int y) {
    int dx=bx-ax,dy=by-ay;
    int px=x-ax,py=y-ay;
    return dx*py-dy*px;
}
__forceinline int sidePoints(const Point2I* a,const Point2I* b,int x,int y) {
    return sideScalars(a->x,a->y,b->x,b->y,x,y);
}
__forceinline int sideEdge(const WalkEdge& e,int x,int y) {
    return sidePoints((Point2I*)e.start(),e.end(),x,y);
}
__forceinline WalkHit MeshWalk::find(WalkEdge edge,int x,int y) const {
    for (WalkNode* node=head;node;node=node->next) {
        int side;
        while ((side=sideEdge(edge,x,y))<0) edge=edge.link().next();
        for (int left=maxSteps;left>0;--left) {
            const WalkEdge choices[2]={edge.next(),edge.prev()};
            const int signs[2]={sideEdge(choices[0],x,y),sideEdge(choices[1],x,y)};
            const int which=signs[0]<signs[1]?0:1;
            const int dist=signs[which];
            const WalkEdge picked=choices[which];
            if (dist<0) { side=-dist; edge=picked.link(); }
            else {
                int bits=(side==0?1:0)+(signs[0]==0?2:0)+(signs[1]==0?4:0);
                switch(bits) {
                case 0:return WalkHit(0,edge);
                case 1:return WalkHit(1,edge);
                case 2:return WalkHit(1,choices[0]);
                case 4:return WalkHit(1,choices[1]);
                case 3:return WalkHit(2,choices[0]);
                case 6:return WalkHit(2,choices[1]);
                case 5:return WalkHit(2,edge);
                default:return WalkHit(3,noWalkEdge());
                }
            }
        }
        edge=WalkEdge((WalkTriangle*)node,0);
    }
    int storage[128];
    CharBuffer msg;
    msg.FUN_00cb1600((char*)storage,512);
    msg.ProcessAndReturnValue_00cc01c0(DAT_010eafd4);
    if (DAT_01268360->Report(3,0xb8c66b5f,(char*)storage,DAT_010eaf60,847)) fnv_Breakpoint();
    msg.FUN_00cc00e0();
    return WalkHit(4,noWalkEdge());
}
// Returns input unchanged if its start equals vertex, otherwise replaces it with the edge returned by MeshWalk::find for the vertex's x and y.
// @fnv 0x00e23df0
// src: HAVOK_LIB 0x00e23df0
S00e24650_Edge EdgeWalker::hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_locateExistingVertex(S00e24650_Edge input,unsigned int vertex) {
    WalkEdge& edge=reinterpret_cast<WalkEdge&>(input);
    const Point2I* point=reinterpret_cast<const Point2I*>(vertex);
    if (edge.start()!=point) edge=reinterpret_cast<const MeshWalk*>(this)->find(edge,point->x,point->y).edge;
    return input;
}

extern "C" double __cdecl fabs(double);

struct __declspec(align(16)) Vec4A {
    float x, y, z, w;
    const char* FUN_00c7f520(void* a, float c);
    __forceinline Vec4A& set(const Vec4A& v) {
        _mm_store_ps(&x, _mm_load_ps(&v.x));
        return *this;
    }
};
typedef Vec4A Plane;
struct PTri {
    int unk00;
    int unk04;
    void* m_08;
    void* m_0C;
    void* m_10;
    unsigned int m_ppLinks[3];
    Plane m_kTriangleNormal;
    int m_30;
    int unk34;
    int unk38;
    int unk3C;
};
struct PEdge {
    PTri* tri;
    int index;
    PEdge(PTri* t, int i) : tri(t), index(i) {}
};
struct PtrArr {
    PTri** data;
    int size;
    unsigned int cap;
};
struct EdgeArr {
    PEdge* data;
    int size;
    unsigned int cap;
};
struct VecArr {
    Vec4A* data;
    int size;
    unsigned int cap;
    void AddBack(const Vec4A& v);
};
struct TriPtrArr {
    PTri** data;
    int size;
    unsigned int cap;
    void AddBack(PTri* t);
};
__forceinline void VecArr::AddBack(const Vec4A& v)
{
    hkMemoryRouter& r = hkMemoryRouter_getInstance();
    if (size == (int)(cap & 0x3fffffff))
        ::ResizeAudioStream(reinterpret_cast<Allocator*>(r.m_heap), this, 16);
    data[size].set(v);
    size++;
}
__forceinline void TriPtrArr::AddBack(PTri* t)
{
    hkMemoryRouter& r = hkMemoryRouter_getInstance();
    if (size == (int)(cap & 0x3fffffff))
        ::ResizeAudioStream(reinterpret_cast<Allocator*>(r.m_heap), this, 4);
    PTri** dst = data + size;
    __assume(dst != 0);
    *dst = t;
    size++;
}


static __forceinline void PushEdge(EdgeArr& arr, const PEdge& e)
{
    hkMemoryRouter& r = hkMemoryRouter_getInstance();
    if (arr.size == (int)(arr.cap & 0x3fffffff))
        ::ResizeAudioStream(reinterpret_cast<Allocator*>(r.m_heap), &arr, 8);
    PEdge* dst = arr.data + arr.size;
    if (dst) {
        *dst = e;
    }
    arr.size++;
}
static __forceinline void FreeEdgeArr(EdgeArr& arr, int elem)
{
    hkMemoryRouter& r = hkMemoryRouter_getInstance();
    Allocator* ao = reinterpret_cast<Allocator*>(r.m_heap);
    int cap = (int)arr.cap;
    arr.size = 0;
    if ((cap & 0x80000000u) == 0)
        ao->freeBlock(arr.data, (cap & 0x3fffffff) * elem);
    arr.data = 0;
    arr.cap = 0x80000000;
}
static __forceinline void FreePtrArr(PtrArr& arr, int elem)
{
    hkMemoryRouter& r = hkMemoryRouter_getInstance();
    Allocator* ao = reinterpret_cast<Allocator*>(r.m_heap);
    int cap = (int)arr.cap;
    arr.size = 0;
    if ((cap & 0x80000000u) == 0)
        ao->freeBlock(arr.data, (cap & 0x3fffffff) * elem);
    arr.data = 0;
    arr.cap = 0x80000000;
}
static __forceinline float HSum3(__m128 m)
{
    __m128 sh = _mm_shuffle_ps(m, m, 0x55);
    __m128 sh2 = _mm_shuffle_ps(m, m, 0xaa);
    __m128 sum = _mm_add_ss(sh, m);
    __m128 tot = _mm_add_ss(sh2, sum);
    float out;
    _mm_store_ss(&out, tot);
    return out;
}

struct E13B00This {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28;
    PTri* m_2C;
    int m_30;
    int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C;
    int unk90; int unk94; int unk98; int unk9C;
    int unkA0; int unkA4; int unkA8; int unkAC;
    int unkB0; int unkB4; int unkB8; int unkBC;
    int unkC0; int unkC4; int unkC8;
    VecArr m_CC;
    TriPtrArr m_D8;
    void hkgpMesh_fetchAreaSortedTriangles(PtrArr* arr, int flag);
    int hkgpMesh_buildPlaneIndices(float a1, float a2, bool a3);
};

// Flood-fills groups of linked triangles whose plane dot is at least a1 and w difference at most a2, storing group planes in m_CC and seed triangles in m_D8.
// @fnv 0x00e13b00
// src: XBOX_PDB 0x00e13b00
int E13B00This::hkgpMesh_buildPlaneIndices(float afMinDot, float afMaxWDiff, bool a3)
{
    m_CC.size = 0;
    m_D8.size = 0;
    if (!m_30)
        return 0;
    PtrArr nxt;
    nxt.data = 0;
    nxt.size = 0;
    nxt.cap = 0x80000000;
    hkgpMesh_fetchAreaSortedTriangles(&nxt, 1);
    EdgeArr arrB;
    arrB.data = 0;
    arrB.size = 0;
    arrB.cap = 0x80000000;
    int i = 0;
    if (nxt.size > 0) {
        do {
            PTri* tri = nxt.data[i];
            if (tri->unk34 < 0) {
                bool c;
                const char* ptot = tri->m_kTriangleNormal.FUN_00c7f520(&c, DAT_010141cc);
                if (ptot[0]) {
                    Vec4A dot;
                    dot = tri->m_kTriangleNormal;
                    tri->unk34 = m_CC.size;
                    arrB.size = 0;
                    PushEdge(arrB, PEdge(tri, 0));
                    PushEdge(arrB, PEdge(tri, 1));
                    PushEdge(arrB, PEdge(tri, 2));
                    m_CC.AddBack(dot);
                    m_D8.AddBack(tri);
                    while (arrB.size != 0) {
                        PEdge ed = arrB.data[arrB.size - 1];
                        unsigned int V = ed.tri->m_ppLinks[ed.index];
                        int tmp = (int)(V & 3);
                        PTri* pNextTri = (PTri*)(V & ~3u);
                        arrB.size--;
                        if (!pNextTri)
                            continue;
                        if (pNextTri->unk34 != -1)
                            continue;
                        if (a3) {
                            if (pNextTri->unk38 != tri->unk38)
                                continue;
                        }
                        __m128 pm = _mm_mul_ps(_mm_load_ps(&pNextTri->m_kTriangleNormal.x), *(const __m128*)&dot);
                        __m128 psh = _mm_shuffle_ps(pm, pm, 0x55);
                        __m128 psum = _mm_add_ss(psh, pm);
                        __m128 secondShuffle = _mm_shuffle_ps(pm, pm, 0xaa);
                        __m128 linked = _mm_add_ss(secondShuffle, psum);
                        float link;
                        _mm_store_ss(&link, linked);
                        if (!(link >= afMinDot))
                            continue;
                        float cnt = dot.w - pNextTri->m_kTriangleNormal.w;
                        cnt = (float)fabs(cnt);
                        if (!(cnt <= afMaxWDiff))
                            continue;
                        pNextTri->unk34 = tri->unk34;
                        int arrA = (9 >> (tmp + tmp)) & 3;
                        PushEdge(arrB, PEdge(pNextTri, arrA));
                        int linkIdx = (0x12 >> (tmp + tmp)) & 3;
                        PushEdge(arrB, PEdge(pNextTri, linkIdx));
                    }
                }
            }
            i++;
        } while (i < nxt.size);
    }
    int result = m_CC.size;
    FreeEdgeArr(arrB, 8);
    FreePtrArr(nxt, 4);
    return result;
}

extern "C" void _WriteBarrier();
extern "C" double __cdecl fabs(double);
__declspec(nothrow) void __cdecl ResizeAudioStream(void*, void*, int);


struct __declspec(align(16)) CollapsePosition {
    float x,y,z,w;
    void operator=(const CollapsePosition& v) { reinterpret_cast<__m128&>(*this) = reinterpret_cast<const __m128&>(v); }
    __m128 quad() const { return reinterpret_cast<const __m128&>(*this); }
    void set(__m128 v) { reinterpret_cast<__m128&>(*this) = v; }
};
namespace CollapseThreshold {static float DAT_0104da4c=1.1920928955078125e-7f;}
struct CollapseVertex {
    int unk00,unk04,unk08,unk0c;
    CollapsePosition position;
    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40;
    int mark;
};
struct CollapseTriangle {
    CollapseTriangle* next;
    CollapseTriangle* prev;
    CollapseVertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
};
struct CollapseEdgeFields { CollapseTriangle* m_pkTriangle; unsigned int m_uiEdgeIndex; };
struct CollapseEdge : CollapseEdgeFields {
    CollapseEdge() {}
    CollapseEdge(CollapseTriangle* t,unsigned int i) {m_pkTriangle=t; m_uiEdgeIndex=i;}
    CollapseEdge(unsigned int packed) {m_uiEdgeIndex=packed&3; m_pkTriangle=(CollapseTriangle*)(packed&~3u);}
    __forceinline bool isValid() const {return m_pkTriangle!=0;}
    __forceinline CollapseEdge next() const {return CollapseEdge(m_pkTriangle,(9>>(m_uiEdgeIndex*2))&3);}
    __forceinline CollapseEdge prev() const {return CollapseEdge(m_pkTriangle,(18>>(m_uiEdgeIndex*2))&3);}
    __forceinline CollapseEdge link() const {return CollapseEdge(m_pkTriangle->m_ppLinks[m_uiEdgeIndex]);}
    __forceinline const CollapsePosition& endPosition() const {return m_pkTriangle->m_kVertices[(9>>(m_uiEdgeIndex*2))&3]->position;}
    __forceinline CollapseVertex*& end() const {return m_pkTriangle->m_kVertices[(9>>(m_uiEdgeIndex*2))&3];}
    __forceinline CollapseVertex*& start() const {return m_pkTriangle->m_kVertices[m_uiEdgeIndex];}
};
__forceinline CollapseVertex* collapseVertex(void* p) {return (CollapseVertex*)p;}
__forceinline float triangleArea(CollapseTriangle* n) {
    __m128 a = collapseVertex(n->m_kVertices[0])->position.quad();
    __m128 e1 = _mm_sub_ps(collapseVertex(n->m_kVertices[1])->position.quad(), a);
    __m128 e2 = _mm_sub_ps(collapseVertex(n->m_kVertices[2])->position.quad(), a);
    __m128 c = _mm_sub_ps(
        _mm_mul_ps(_mm_shuffle_ps(e2,e2,0xd2), _mm_shuffle_ps(e1,e1,0xc9)),
        _mm_mul_ps(_mm_shuffle_ps(e2,e2,0xc9), _mm_shuffle_ps(e1,e1,0xd2)));
    __m128 sq = _mm_mul_ps(c,c);
    __m128 d = _mm_add_ss(_mm_shuffle_ps(sq,sq,0xaa),_mm_add_ss(_mm_shuffle_ps(sq,sq,0x55),sq));
    float r; _mm_store_ss(&r,_mm_sqrt_ss(d)); return r;
}
template<class Action> __forceinline void walkFan(const CollapseEdge& edge, Action& action) {
    CollapseEdge cursor=edge;
    do {
        action(cursor);
        cursor=cursor.prev().link();
    } while(cursor.isValid() && (unsigned int)cursor.m_pkTriangle+cursor.m_uiEdgeIndex != (unsigned int)edge.m_pkTriangle+edge.m_uiEdgeIndex);
    if(!cursor.isValid()) {
        cursor=edge.link().next();
        while(cursor.isValid()) {
            action(cursor);
            _WriteBarrier(); cursor=cursor.link().next();
        }
    }
}
struct E17F40Hull;
struct CollapseContext {
    E17F40Hull* mesh;
    CollapsePosition target;
    float minDot,oldAreaSum,newAreaSum;
    CollapseContext(E17F40Hull* owner,const CollapsePosition& position):mesh(owner),target(position),minDot(1.0f),oldAreaSum(0.0f),newAreaSum(0.0f) {}
    __forceinline void operator()(CollapseEdge cursor);
};
struct __declspec(align(16)) CollapseStats {float minDot,oldAreaSum,newAreaSum;};
struct CollapseEdgeArray {
    CollapseEdge* data;
    int size, capacity;
    struct Slot {CollapseTriangle* triangle; unsigned int index;};
    Slot storage[16];
    __forceinline CollapseEdgeArray() throw(): data(reinterpret_cast<CollapseEdge*>(storage)),size(0),capacity(0x80000010) {}
    __forceinline void append(const CollapseEdge& e) throw() {
        Allocator& heap=meshHeap(hkMemoryRouter_getInstance());
        if (size == (capacity & 0x3fffffff)) ResizeAudioStream(&heap,this,8);
        new(data+size) CollapseEdge(e); ++size;
    }
    __forceinline void operator()(const CollapseEdge& e) throw() {append(e);}
    __forceinline ~CollapseEdgeArray() throw() {
        Allocator& heap=meshHeap(hkMemoryRouter_getInstance());
        size=0;
        if (!(capacity & 0x80000000)) heap.freeBlock(data,(capacity & 0x3fffffff)*8);
        data=0; capacity=0x80000000;
    }
};
struct E17F40Hull {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    int unk20,unk24,unk28;
    CollapseTriangle* faces;
    int unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c,unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc,unkc0,unkc4,unkc8,unkcc,unkd0,unkd4,unkd8,unkdc,unke0,unke4,unke8,unkec,unkf0,unkf4,unkf8,unkfc;
    bool error; float minLengthSquared, minArea;
    __declspec(nothrow) void hkgpMesh_removeOrphanVertices();
    __declspec(nothrow) void ReleaseSubobject();
    __declspec(nothrow) void hkgpMesh_setVerticesTag(int);
    __declspec(nothrow) void RemoveEdge(CollapseEdge,bool);
    __declspec(noinline) __declspec(nothrow) void SetFlag100_00e11500(const CollapsePosition*,const CollapsePosition*);
    __declspec(noinline) __declspec(nothrow) void SetField100(const CollapsePosition*,const CollapsePosition*,const CollapsePosition*);
    __declspec(noinline) __declspec(nothrow) bool ValidateTriangleAndComputePlane(const CollapsePosition*,const CollapsePosition*,const CollapsePosition*,CollapsePosition*,bool);
    __declspec(noinline) __declspec(nothrow) bool hkgpMesh_setPlane(const volatile CollapseTriangle*,CollapsePosition*,bool);
    void hkgpMesh_simplify(float* options);
};
// src: GUESS 0x00e11500 (confidence: medium)
void E17F40Hull::SetFlag100_00e11500(const CollapsePosition*,const CollapsePosition*) {error=true;}
// src: GUESS 0x00e114f0 (confidence: low)
void E17F40Hull::SetField100(const CollapsePosition*,const CollapsePosition*,const CollapsePosition*) {error=true;}
// src: GUESS 0x00e11710 (confidence: medium)
bool E17F40Hull::ValidateTriangleAndComputePlane(const CollapsePosition* a,const CollapsePosition* b,const CollapsePosition* c,CollapsePosition* out,bool check) {
    float tolerance = minLengthSquared;
    bool valid=true;
    __m128 ab = _mm_sub_ps(b->quad(),a->quad());
    if(check && ToReal(Dot3(ab,ab)) <= tolerance) {SetFlag100_00e11500(a,b);valid=false;}
    __m128 ac = _mm_sub_ps(c->quad(),a->quad());
    if(check && ToReal(Dot3(ac,ac)) <= tolerance) {SetFlag100_00e11500(a,c);valid=false;}
    __m128 bc = _mm_sub_ps(c->quad(),b->quad());
    if(check && ToReal(Dot3(bc,bc)) <= tolerance) {SetFlag100_00e11500(c,b);valid=false;}
    __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(ac,ac,0xd2),_mm_shuffle_ps(ab,ab,0xc9)),_mm_mul_ps(_mm_shuffle_ps(ac,ac,0xc9),_mm_shuffle_ps(ab,ab,0xd2)));
    out->set(cross);
    float length = ToReal(_mm_sqrt_ss(Dot3(cross,cross)));
    out->w=length;
    if (check && length < minArea) {SetField100(a,b,c);valid=false;}
    out->set(_mm_mul_ps(_mm_set_ps1(1.0f/out->w),out->quad()));
    out->w=ToReal(_mm_sub_ss(DAT_010c7160,Dot3(a->quad(),out->quad())));
    return valid;
}
// src: HAVOK_LIB 0x00e118e0
bool E17F40Hull::hkgpMesh_setPlane(const volatile CollapseTriangle* face,CollapsePosition* out,bool check) {
    return ValidateTriangleAndComputePlane(&collapseVertex(face->m_kVertices[0])->position,&collapseVertex(face->m_kVertices[1])->position,&collapseVertex(face->m_kVertices[2])->position,out,check);
}
__forceinline void CollapseContext::operator()(CollapseEdge cursor) {
                    oldAreaSum += triangleArea(cursor.m_pkTriangle);
                    CollapsePosition oldPlane;
                    mesh->hkgpMesh_setPlane(cursor.m_pkTriangle,&oldPlane,true);
                    CollapsePosition savedPosition=collapseVertex(cursor.start())->position;
                    collapseVertex(cursor.start())->position=target;
                    float newArea=triangleArea(cursor.m_pkTriangle);
                    CollapsePosition newPlane;
                    mesh->hkgpMesh_setPlane(cursor.m_pkTriangle,&newPlane,true);
                    collapseVertex(cursor.start())->position=savedPosition;
                    if(CollapseThreshold::DAT_0104da4c < newArea) {
                        float dot=ToReal(Dot3(oldPlane.quad(),newPlane.quad()));
                        minDot = minDot < dot ? minDot : dot;
                        newAreaSum += newArea;
                    }
}
// Iteratively collapses mesh edges whose fan area error and plane dot product stay within the given thresholds, then finalises the hull.
// @fnv 0x00e17f40
// src: XBOX_PDB 0x00e17f40
void E17F40Hull::hkgpMesh_simplify(float* options)
{
    bool changed;
    do {
        changed=false;
        CollapseTriangle* face=faces;
        while(face) {
            CollapseTriangle* nextFace=face->next;
            for (int edgeIndex=0,nextIndex=0;nextIndex<3;nextIndex=edgeIndex+1,(volatile int&)edgeIndex=nextIndex) {
                CollapseEdge edge(face,edgeIndex);
                CollapseEdge opposite=edge.link();
                if(!(edge.m_pkTriangle->m_ppLinks[edge.m_uiEdgeIndex]&~3u)) continue;
                CollapseContext context(this,edge.endPosition());
                walkFan(edge,context);
                if(!(context.minDot >= options[0])) continue;
                float areaError=context.oldAreaSum-context.newAreaSum;
                areaError=(float)fabs(areaError);
                if(!(areaError <= options[1])) continue;
                CollapseEdgeArray fanA;
                walkFan(edge,fanA);
                bool boundary=false;
                for(int i=0;i<fanA.size;++i) {
                    if(!fanA.data[i].link().isValid() || !fanA.data[i].next().link().isValid()) {boundary=true;break;}
                }
                if(boundary) continue;
                CollapseEdgeArray fanB;
                walkFan(opposite,fanB);
                for(int i=0;i<fanA.size;++i) collapseVertex(fanA.data[i].end())->mark=0;
                for(int i=0;i<fanB.size;++i) collapseVertex(fanB.data[i].end())->mark=0;
                for(int i=0;i<fanA.size;++i) collapseVertex(fanA.data[i].end())->mark+=1;
                for(int i=0;i<fanB.size;++i) collapseVertex(fanB.data[i].end())->mark+=2;
                int common=0;
                for(int i=0;i<fanA.size;++i) {
                    if(collapseVertex(fanA.data[i].end())->mark==3) ++common;
                }
                if(common==2) {
                    if(nextFace==face || nextFace==opposite.m_pkTriangle) nextFace=edge.next().link().m_pkTriangle;
                    RemoveEdge(edge,false);
                    changed=true;
                    break;
                }
            }
            face=nextFace;
        }
    }while(changed);
    hkgpMesh_removeOrphanVertices();
    ReleaseSubobject();
    hkgpMesh_setVerticesTag(-1);
}

#include <math.h>

namespace MeshTransformE27 {

extern "C" ::__m128 _mm_setr_ps(float x, float y, float z, float w);

extern double DAT_01029790;
extern float DAT_01011d78;





extern hkVector4 DAT_0126a3e0;
extern hkVector4 DAT_0126a3f0;
extern hkVector4 DAT_0126a400;
extern hkVector4 DAT_0126a410;

} // namespace MeshTransformE27

inline void hkMatrix4::setIdentity()

{
    m_kColumn0.m_vComponents = MeshTransformE27::DAT_0126a3e0.m_vComponents;
    m_kColumn1.m_vComponents = MeshTransformE27::DAT_0126a3f0.m_vComponents;
    m_kColumn2.m_vComponents = MeshTransformE27::DAT_0126a400.m_vComponents;
    m_kColumn3.m_vComponents = MeshTransformE27::DAT_0126a410.m_vComponents;
}

namespace MeshTransformE27 {

struct TwoComponentVector {
    float x;
    float y;
};

struct Sub6a0 {
    void hkMatrix4_CopyColumnsAndApplyValue(const hkMatrix4* pkTransform, float fTime);
};

struct Obj27b50 {
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c;
    int unk030, unk034, unk038, unk03c, unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c;
    int unk090, unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec;
    int unk0f0, unk0f4, unk0f8, unk0fc, unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c, unk140, unk144, unk148, unk14c;
    int unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac;
    int unk1b0, unk1b4, unk1b8, unk1bc, unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc, unk200, unk204, unk208, unk20c;
    int unk210, unk214, unk218, unk21c, unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c, unk260, unk264, unk268, unk26c;
    int unk270, unk274, unk278, unk27c, unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c;
    int unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc, unk2c0, unk2c4, unk2c8, unk2cc;
    int unk2d0, unk2d4, unk2d8, unk2dc, unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4, unk2f8, unk2fc;
    int unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c, unk320, unk324, unk328, unk32c;
    int unk330, unk334, unk338, unk33c, unk340, unk344, unk348, unk34c, unk350, unk354, unk358, unk35c;
    int unk360, unk364, unk368, unk36c, unk370, unk374, unk378, unk37c, unk380, unk384, unk388, unk38c;
    int unk390, unk394, unk398, unk39c, unk3a0, unk3a4, unk3a8, unk3ac, unk3b0, unk3b4, unk3b8, unk3bc;
    int unk3c0, unk3c4, unk3c8, unk3cc, unk3d0, unk3d4, unk3d8, unk3dc, unk3e0, unk3e4, unk3e8, unk3ec;
    int unk3f0, unk3f4, unk3f8, unk3fc, unk400, unk404, unk408, unk40c, unk410, unk414, unk418, unk41c;
    int unk420, unk424, unk428, unk42c, unk430, unk434, unk438, unk43c, unk440, unk444, unk448, unk44c;
    int unk450, unk454, unk458, unk45c, unk460, unk464, unk468, unk46c, unk470, unk474, unk478, unk47c;
    int unk480, unk484, unk488, unk48c, unk490, unk494, unk498, unk49c, unk4a0, unk4a4, unk4a8, unk4ac;
    int unk4b0, unk4b4, unk4b8, unk4bc, unk4c0, unk4c4, unk4c8, unk4cc, unk4d0, unk4d4, unk4d8, unk4dc;
    int unk4e0, unk4e4, unk4e8, unk4ec, unk4f0, unk4f4, unk4f8, unk4fc, unk500, unk504, unk508, unk50c;
    int unk510, unk514, unk518, unk51c, unk520, unk524, unk528, unk52c, unk530, unk534, unk538, unk53c;
    int unk540, unk544, unk548, unk54c, unk550, unk554, unk558, unk55c, unk560, unk564, unk568, unk56c;
    int unk570, unk574, unk578, unk57c, unk580, unk584, unk588, unk58c, unk590, unk594, unk598, unk59c;
    int unk5a0, unk5a4, unk5a8, unk5ac, unk5b0, unk5b4, unk5b8, unk5bc, unk5c0, unk5c4, unk5c8, unk5cc;
    int unk5d0, unk5d4, unk5d8, unk5dc, unk5e0, unk5e4, unk5e8, unk5ec, unk5f0, unk5f4, unk5f8, unk5fc;
    int unk600, unk604, unk608, unk60c, unk610, unk614, unk618, unk61c, unk620, unk624, unk628, unk62c;
    int unk630, unk634, unk638, unk63c, unk640, unk644, unk648, unk64c, unk650, unk654, unk658;
    int m_iFlipped;
    hkMatrix4 m_kTransform;
    Sub6a0 m_kSub;

    void UpdateState_00e27b50(const TwoComponentVector* pkFrom, const TwoComponentVector* pkTo, float fAngleDifference, bool bFlip);
    void hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_reset(int i);
};

// @fnv 0x00e27b50
// src: GUESS 0x00e27b50 (confidence: low)
void Obj27b50::UpdateState_00e27b50(const TwoComponentVector* pkFrom, const TwoComponentVector* pkTo, float fAngleDifference, bool bFlip)
{
    m_iFlipped = bFlip != false;
    float fScale = (float)(DAT_01029790 - m_iFlipped * 2.0);
    float fSin = sin(fAngleDifference);
    float fCos = cos(fAngleDifference);

    hkVector4 kScale;
    kScale.set((pkTo->x - pkFrom->x) / fScale, (pkTo->y - pkFrom->y) / fScale, DAT_01011d78, DAT_01011d78);

    m_kTransform.setIdentity();

    m_kTransform(0, 0) = kScale(0) * fCos;
    m_kTransform(0, 1) = kScale(1) * fSin;
    m_kTransform(0, 3) = pkFrom->x;
    m_kTransform(1, 0) = -fSin * kScale(0);
    m_kTransform(1, 1) = kScale(1) * fCos;
    m_kTransform(1, 3) = pkFrom->y;

    m_kSub.hkMatrix4_CopyColumnsAndApplyValue(&m_kTransform, 0.0f);
    hkgpTriangulatorType_struct_hkgpTriangulatorBase_VertexBase_struct_hkgpTriangulatorBase_TriangleBase_struct_hkgpTriangulatorBase_DefaultEdgeData_struct_hkContainerHeapAllocator_struct_hkContainerHeapAllocator_1_reset(1);
}


}
