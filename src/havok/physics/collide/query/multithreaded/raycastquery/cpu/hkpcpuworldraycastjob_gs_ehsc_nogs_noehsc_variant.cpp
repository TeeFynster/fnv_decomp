
// src/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpuworldraycastjob_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpuworldraycastjob.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpuworldraycastjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpuworldraycastjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkMemoryRouter.h"

struct ValueHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned char value;
    unsigned char* CopyValue(unsigned char* output);
};
struct S_00df8990_Obj;
extern void(__cdecl* DAT_0126ec04)(void* a, void* b, S_00df8990_Obj* obj);
struct S_00df8990_Obj
{
    void InvokeCallback(void* a, void* b);
};
struct S_00df8d60_Bool
{
    char m_cBooleanValue;
    S_00df8d60_Bool()
    {}
};
struct S_00df8d60_Data
{
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    char unk4;
    signed char unk5;
};
struct S_00df8d60
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    float unk14;
    S_00df8d60_Bool CastBody_Thunk(const void* data);
    float hkCpuWorldRayCastCollector_addBroadPhaseHandle(const S_00df8d60_Data* data, int unused);
};
struct ParamBlock
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m_iValue;
};
struct Container
{
    void CastBody_Thunk(int* apOut, int aiValue);
};
struct FUN_00df8db0_cls
{
    int unk00;
    int unk04;
    int unk08;
    float m_fResult;

    float GetResult(ParamBlock* apParam);
};
extern int DAT_0101e594;
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
struct FUN_00df8960_cls
{
    int m_vptr;

    FUN_00df8960_cls* FUN_00df8960(unsigned char acFlags);
};
struct AdjustedBase
{
    void CastBody_Thunk(void* apFirst, int aiSecond);
};
struct AdjustOwner
{
    void* hkCpuWorldRayCastCollector_addMidPhaseHit(void* apFirst, int aiSecond);
};
struct FUN_00df8dd0_Param
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_i0c;
};
struct FUN_00df8dd0_helper
{
    void CastBody_Thunk(FUN_00df8dd0_Param** pp, unsigned int value);
};
struct FUN_00df8dd0_cls
{
    int unk00;
    int unk04;
    float m_f08;

    float hkCpuWorldRayCastCollector_addLeaf(FUN_00df8dd0_Param* p);
};
struct DF8930Primary
{
    virtual void vfunc00();
    virtual void FUN_00df8930();

    int unk04;
    int unk08;
};
struct DF8930Secondary
{
    virtual void FUN_00df8930();
};
struct DF8930Object : DF8930Primary, DF8930Secondary
{
    DF8930Object();

// @fnv 0x00df8930
    virtual void FUN_00df8930();
};
DF8930Object::DF8930Object()
{}
// Adjustor thunk for a secondary base of a multiply-inherited class.
//
// The original bytes at 0x00df8950 are
//     sub ecx, 8
//     jmp 0xdf9470
// i.e. the compiler-generated "[thunk]: Derived::FUN_00df8950`adjustor{8}'"
// that MSVC emits for the per-base vftable of the SECONDARY base: the
// secondary base subobject lives 8 bytes into the most-derived object, so
// the thunk has to move "this" back by 8 before tail-jumping into the
// most-derived implementation.
//
// The most-derived implementation of FUN_00df8950 is only DECLARED here (it
// lives in another translation unit of the game), so the tail jump stays an
// undefined external and the linker/checker resolves it from the original.
struct NiObjectBase
{
    NiObjectBase();
    virtual void FUN_00df8950(int flag);
    int unk04;
};
struct NiExtraDataBase
{
    NiExtraDataBase();
    virtual void FUN_00df8950(int flag);
};
class Derived : public NiObjectBase, public NiExtraDataBase
{
  public:
    Derived();
// @fnv 0x00df8950
    virtual void FUN_00df8950(int flag);
};
NiObjectBase::NiObjectBase()
{}
NiExtraDataBase::NiExtraDataBase()
{}
Derived::Derived()
{}
#include <xmmintrin.h>
extern char DAT_010dbb04[];
extern void(__cdecl* DAT_0126ec04)(void* a, void* b, struct S_00df8990_Obj* obj);
struct S_00df8990_Obj;
void __cdecl Runtime_ProcessEntries_00e2b9b0(void* a, void* b, S_00df8990_Obj* obj);
struct Source
{
    __m128 m_v00;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned char m_20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23;
    unsigned int m_24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int unk38;
    unsigned char m_3c;
};
struct Spawned
{
    unsigned int m_00;
    float m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
    Spawned(unsigned int first, unsigned int last)
        : m_00((unsigned int)DAT_010dbb04), m_04(1.0f), m_08(first), m_0c(first), m_10(last), m_14(0), m_18(0)
    {}
};
struct SubBase
{
    unsigned value;
};
struct Leading
{
    unsigned a, b, c, d;
};
struct WithSub : Leading, SubBase
{
};
struct Output
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    WithSub* m_10;
    unsigned int unk14;
    unsigned int unk18;
    Source* m_1c;
    Source* m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int m_50;
    SubBase* m_54;
    unsigned int unk58;
    unsigned int unk5c;
    Spawned* m_60;
};
struct Local
{
    union
    {
        __m128 m_vector;
        float elements[4];
    };
    unsigned int m_10;
    unsigned int* m_pSub;
    unsigned int m_18;
    unsigned int m_1c;
};
// Exe 0x00df8df0: unit-local Interface view; declarations and layout are preserved.
struct HkpcpuworldraycastjobInterfaceView
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c(void* a, Output* b, unsigned int c);
};
void __cdecl castRayBroadPhase(HkpcpuworldraycastjobInterfaceView* iface, Source* src, Output* out, Spawned* spawned);

#include <xmmintrin.h>
namespace fnv_00df8df0 {
#include <windows.h>
#include <xmmintrin.h>

extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern unsigned int DAT_0126835c;
extern const char DAT_010dbaf8, DAT_010dbae4, DAT_010dbad8, DAT_010dbacc;
extern const char DAT_010dbb0c[], DAT_010c41f8[];
extern const char DAT_010dbb04, DAT_010ccfac, DAT_010ccfa0, DAT_010ccf8c, DAT_010c3bb8;
extern __m128 DAT_01267e30, DAT_010c7170, DAT_010cd670;
extern const float DAT_01012068;
struct __declspec(align(16)) Vec
{
    float x, y, z, w;
};
struct Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Free(void*, int) throw();
};
static __forceinline hkMemoryRouter* pool()
{
    return hkMemoryRouter_getInstance();
}
void __cdecl hkArrayUtil__reserve(Allocator*, void*, int, int) throw();
void __cdecl hkAabbTreeRayCastUtil_hkAabbTreeData_hkAabbTreeAabb_unsigned_short_castRayFiltering(void*, void*, void*, int, void*, void*, int) throw();
void __cdecl hkAabbTreeRayCastUtil_struct_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_castRayFiltering(void*, void*, void*, int, void*, void*, int) throw();
void __cdecl hkTreeRayCastJobUtil_castRayKdTree(void*, void*, int, void*, int, int, int, int) throw();
void __cdecl hkVector4_ProcessEntries_00e2b070(void*, void*, int, void*, int, int, int, int, int) throw();
void __cdecl Runtime_ProcessEntries_00e2b510(void*, void*, int, void*, int, int, int, int, int) throw();
void __cdecl hkKdTreeUtils_castRayBundleIterative_ProcessEntries_00e2acf0(void*, void*, int, void*, int, int, int, int, int) throw();
void __cdecl castRayBroadPhase(void*, void*, void*, void*) throw();
struct Finalizer
{
    void __thiscall ProcessCallback(void*, void*, int) throw();
};
struct Header
{
    int unk00, unk04, unk08, type;
};
struct Vertex
{
    Vec position, bounds, extra0, extra1;
};
struct PartVectors
{
    Vec position, bounds;
};
struct PartInfo
{
    __forceinline void copyTo(unsigned char& t, int& p) const;
    unsigned char tag, tag1, tag2, tag3;
    unsigned int property;
    int unk08, unk0c;
};
struct FacePart : PartVectors, PartInfo
{
};
struct FaceParts
{
    FacePart parts[4];
};
struct FaceInfo
{
    int count, unkc4;
    int values[4];
    int unkd8, unkdc;
    int outputs[4];
    unsigned int flags, unkf4, unkf8, unkfc;
};
struct Face : FaceParts, FaceInfo
{
};
__forceinline void PartInfo::copyTo(unsigned char& t, int& p) const
{
    t = tag;
    p = property;
}
struct MeshRequest
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    Header* header;
    int unk20;
    Vertex* vertices;
    int vertexCount;
    Face* faces;
    int faceCount;
    void* shapeBuilder;
    void* passA;
    void* passB;
    void* finalPass;
};
struct OutputVertex
{
    Vec position, inverse;
};
struct VertexBuffer
{
    OutputVertex* data;
    int count, capacity;
    OutputVertex* storage;
    __forceinline void Init(int n) throw()
    {
        data = 0;
        count = 0;
        capacity = 0x80000000;
        hkMemoryRouter* p = pool();
        OutputVertex* memory = (OutputVertex*)p->m_stack.m_next.m_storage;
        p->m_stack.m_next.m_storage = (void*)((int)((unsigned char*)memory + ((n * 32 + 127) & ~127)));
        data = memory;
        capacity = n | 0x80000000;
        storage = memory;
        Allocator* a = *(Allocator* volatile*)&pool()->m_heap;
        int old = capacity & 0x3fffffff;
        if (old < n)
        {
            int next = old * 2;
            if (n >= next)
                next = n;
            hkArrayUtil__reserve(a, &data, next, 32);
        }
    }
    __forceinline void Clear() throw()
    {
        OutputVertex* saved = storage;
        if (saved == data)
            count = 0;
        pool()->m_stack.m_next.m_storage = (void*)((int)saved);
        Allocator* a = *(Allocator* volatile*)&pool()->m_heap;
        count = 0;
        if ((capacity & 0x80000000u) == 0)
            a->Free(data, (capacity & 0x3fffffff) * 32);
    }
};
union QueryScratch
{
    VertexBuffer vertices;
    Vec range;
};
struct __declspec(align(16)) Field
{
    const void* name0;
    const void* name1;
    const void* name2;
    const void* name3;
    int option;
    float weight;
    unsigned char dirty;
    unsigned char selected;
    short option1a;
    int unused1c;
    Vec vector20, vector30, vector40;
    int property50, property54, property58, property5c, flags60, flags64, flags68, flags6c;
    Vec vector70;
    __forceinline void Init() throw()
    {
        name0 = &DAT_010dbaf8;
        name1 = &DAT_010dbae4;
        name2 = &DAT_010dbad8;
        name3 = &DAT_010dbacc;
        weight = 1.0f;
        property50 = 0;
        property54 = 0;
        flags60 = 0;
        dirty = 0;
    }
    __forceinline void Reset() throw()
    {
        name3 = &DAT_010ccfac;
        name2 = &DAT_010ccfa0;
        *(const void* volatile*)&name1 = &DAT_010ccf8c;
        *(const void* volatile*)&name0 = &DAT_010c3bb8;
    }
};
struct State
{
    const void* type;
    float weight;
    int a, b, c, d, e;
    __forceinline void Init() throw()
    {
        type = &DAT_010dbb04;
        weight = 1.0f;
        a = 0;
        b = 0;
        c = 1;
        d = 0;
        e = 0;
    }
};
union SharedState
{
    Vec unit;
    State state;
};
struct __declspec(align(16)) Converted
{
    Vec position, bounds;
    unsigned char tag;
    unsigned char tag1, tag2, tag3;
    int property, unk28, unk2c;
    int value, kind, output;
    unsigned char flags, flags1;
    short flags2;
};

struct SimdValue
{
    __m128 v;
    __forceinline void sub(const SimdValue& a, const SimdValue& b)
    {
        v = _mm_sub_ps(a.v, b.v);
    }
    __forceinline void eq(const SimdValue& a, const __m128& b)
    {
        v = _mm_cmpeq_ps(a.v, b);
    }
    __forceinline void select(const SimdValue& a, const __m128& b, const SimdValue& c)
    {
        v = _mm_or_ps(_mm_and_ps(c.v, b), _mm_andnot_ps(c.v, a.v));
    }
};
struct TraceEntry
{
    const char* label;
    unsigned int stamp;
    unsigned int info;
};
struct TraceContext
{
    void* unk00;
    TraceEntry* head;
    void* unk08;
    TraceEntry* end;
};
// @fnv 0x00df8df0
// src: XBOX_PDB 0x00df8df0
void __cdecl hkCpuWorldRayCastJob(void* result, MeshRequest* request)
{
    {
        TraceContext* t = (TraceContext*)TlsGetValue(DAT_0126835c);
        TraceEntry* p = t->head;
        if (p < t->end)
        {
            p->label = DAT_010dbb0c;
            _ReadWriteBarrier();
            volatile unsigned int tick = (unsigned int)__rdtsc();
            p->stamp = tick;
            t->head = p + 1;
        }
    }
    union CountTemps
    {
        unsigned char* destination;
        int count;
        volatile unsigned int stamp;
    } iteration;
    union
    {
        int queryType;
        FaceInfo* queryFaces;
    };
    union
    {
        int queryRemaining;
        void* queryFinal;
    };
    union
    {
        Vertex* querySource;
        int* queryOutputs;
    };
    QueryScratch scratch;
    SharedState shared;
    State finalState;
    Field field;
    Field fields[4];
    if (request->shapeBuilder == 0)
    {
        queryType = request->header->type;
        querySource = request->vertices;
        int count = request->vertexCount;
        VertexBuffer& vertices = scratch.vertices;
        vertices.Init(count);
        vertices.count = count;
        fields[0].Init();
        fields[1].Init();
        fields[2].Init();
        fields[3].Init();
        hkMemoryRouter* p = pool();
        iteration.destination = (unsigned char*)p->m_stack.m_next.m_storage;
        p->m_stack.m_next.m_storage = (void*)((int)(iteration.destination + 128));
        if (count > 0)
        {
            Vertex* v = querySource;
            unsigned int offset = 0;
            queryRemaining = count;
            do
            {
                OutputVertex* out = (OutputVertex*)((char*)vertices.data + offset);
                *(__m128*)&out->position = *(__m128*)&v->position;
                SimdValue width;
                width.sub(*(SimdValue*)&v->bounds, *(SimdValue*)&v->position);
                SimdValue eq;
                eq.eq(width, DAT_01267e30);
                SimdValue selected;
                selected.select(width, DAT_010c7170, eq);
                __m128 value = selected.v;
                __m128 high = _mm_unpackhi_ps(value, DAT_010c7170);
                value = _mm_shuffle_ps(value, high, 0xc4);
                __m128 reciprocal = _mm_rcp_ps(value);
                __m128 product = _mm_mul_ps(reciprocal, value);
                product = _mm_mul_ps(product, reciprocal);
                reciprocal = _mm_sub_ps(_mm_add_ps(reciprocal, reciprocal), product);
                *(__m128*)&out->inverse = _mm_or_ps(_mm_andnot_ps(eq.v, reciprocal), _mm_and_ps(eq.v, DAT_010cd670));
                offset += 32;
                ++v;
            } while (--queryRemaining != 0);
        }
        *(__m128*)&shared.unit = _mm_set1_ps(DAT_01012068);
        Field* __restrict at = fields;
        queryRemaining = 4;
        do
        {
            *(__m128*)&at->vector70 = *(__m128*)&shared.unit;
            at->option = queryType;
            ++at;
        } while (queryRemaining-- != 1);
        hkAabbTreeRayCastUtil_hkAabbTreeData_hkAabbTreeAabb_unsigned_short_castRayFiltering(request->passA, vertices.data, querySource, queryType, fields, iteration.destination, count);
        hkAabbTreeRayCastUtil_struct_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_castRayFiltering(request->passB, vertices.data, querySource, queryType, fields, iteration.destination, count);
        pool()->m_stack.m_next.m_storage = (void*)((int)iteration.destination);
        Field* end = fields + 4;
        int remaining = 3;
        do
        {
            --end;
            end->Reset();
        } while (--remaining >= 0);
        vertices.Clear();
        queryFinal = request->finalPass;
        Vertex* source = request->vertices;
        finalState.Init();
        int remainingVertices = request->vertexCount;
        if (remainingVertices > 0)
        {
            iteration.count = remainingVertices;
            do
            {
                hkTreeRayCastJobUtil_castRayKdTree(queryFinal, source, queryType, &finalState, 0, 0, 0, 0);
                ++source;
            } while (--iteration.count != 0);
        }
        int remainingFaces = request->faceCount;
        Face* face = request->faces;
        if (remainingFaces > 0)
        {
            iteration.count = remainingFaces;
            do
            {
                *(__m128*)&scratch.range = *(__m128*)&shared.unit;
                hkVector4_ProcessEntries_00e2b070(request->passA, face, queryType, &scratch.range, 0, 0, 0, 0, 0);
                Runtime_ProcessEntries_00e2b510(request->passB, face, queryType, &scratch.range, 0, 0, 0, 0, 0);
                hkKdTreeUtils_castRayBundleIterative_ProcessEntries_00e2acf0(queryFinal, face, queryType, &scratch.range, 0, 0, 0, 0, 0);
                ++face;
            } while (--iteration.count != 0);
        }
    }
    else
    {
        field.Init();
        field.option = request->header->type;
        Vertex* vertex = request->vertices;
        shared.state.Init();
        iteration.count = 0;
        if (request->vertexCount > 0)
            do
            {
                field.weight = 1.0f;
                field.dirty = 0;
                castRayBroadPhase(request->shapeBuilder, vertex, &field, &shared.state);
                ++vertex;
                ++iteration.count;
            } while (iteration.count < request->vertexCount);
        int bundleCount = request->faceCount;
        Face* bundles = request->faces;
        __assume(bundles != 0);
        if (bundleCount > 0)
        {
            queryFaces = bundles;
            queryRemaining = bundleCount;
            do
            {
                iteration.count = 0;
                if (queryFaces->count > 0)
                {
                    Face* inputs = &static_cast<Face&>(*queryFaces);
                    __assume(inputs != 0);

                    do
                    {

                        Converted converted;
                        Converted& c = converted;
                        __m128 position = *(__m128*)&(inputs->parts[iteration.count]).position;
                        (inputs->parts[iteration.count]).copyTo(c.tag, c.property);
                        c.value = queryFaces->values[iteration.count];
                        c.flags = (unsigned char)queryFaces->flags;
                        *(__m128*)&c.position = position;
                        __m128 bounds = *(__m128*)&(inputs->parts[iteration.count]).bounds;
                        c.flags1 = 0;
                        *(__m128*)&c.bounds = bounds;
                        c.kind = 1;
                        c.output = 0;
                        field.weight = 1.0f;
                        field.dirty = 0;
                        castRayBroadPhase(request->shapeBuilder, &c, &field, &shared.state);
                        queryFaces->outputs[iteration.count] = c.output;
                        ++iteration.count;
                    } while (iteration.count < queryFaces->count);
                }
                queryFaces = reinterpret_cast<FaceInfo*>(reinterpret_cast<Face*>(queryFaces) + 1);
            } while (--queryRemaining != 0);
        }
    }
    {
        TraceContext* t = (TraceContext*)TlsGetValue(DAT_0126835c);
        TraceEntry* p = t->head;
        if (p < t->end)
        {
            p->label = DAT_010c41f8;
            _ReadWriteBarrier();
            iteration.stamp = (unsigned int)__rdtsc();
            p->stamp = iteration.stamp;
            t->head = p + 1;
        }
    }
    ((Finalizer*)result)->ProcessCallback(request, request, 0);
}
}  // namespace fnv_00df8df0
