#include "../../../../../include/hkArray.h"

// src/havok/common/visualize/shape/hkdisplaycone.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaycone.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
struct __declspec(align(16)) Vertex
{
    __m128 value;
};
struct Edge
{
    int polygon, end, start, adjacent;
};
// Exe 0x00de57a0: three-word Havok owning arrays, initialized with DONT_DEALLOCATE_FLAG.

struct GeometryBuffers
{
    hkArray<Vertex> vertices;
    hkArray<Edge> edges;
    GeometryBuffers() : vertices(), edges()
    {}
    static void* operator new(unsigned int, void* position)
    {
        return position;
    }
};
struct Allocator
{
    virtual void unused();
    virtual void* __thiscall Allocate(unsigned int);
};
struct GlobalContext
{
    int unk00, unk04, unk08, unk0c;
    Allocator* allocator;
};
extern "C" GlobalContext* __cdecl FUN_00c85750();
extern "C" void __cdecl ResizeAudioStream(Allocator*, hkArray<Vertex>*, int);
extern "C" void __cdecl FUN_00c908c0(Allocator*, hkArray<Edge>*, int, int);
struct ForwardArg
{
    GeometryBuffers* value;
};
struct MeshBuilder;
extern "C" void __fastcall FUN_00de54b0(MeshBuilder*, ForwardArg);
struct MeshBuilder
{
    int unk00;
    int unk04;
    GeometryBuffers* geometry;
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
    Vertex initialVertex;
    int unk70, unk74, unk78, unk7c;
    volatile int segmentCount;
    void __thiscall InitializeGeometry();
};
// Allocates GeometryBuffers, calls FUN_00de54b0, appends initialVertex to vertices, and fills edges with segmentCount entries.
// @fnv 0x00de57a0
void __thiscall MeshBuilder::InitializeGeometry()
{
    GlobalContext* context = FUN_00c85750();
    Allocator* resourceAllocator = context->allocator;
    GeometryBuffers* raw = static_cast<GeometryBuffers*>(resourceAllocator->Allocate(sizeof(GeometryBuffers)));
    GeometryBuffers* buffers = raw ? new (raw) GeometryBuffers() : 0;
    geometry = buffers;
    ForwardArg arg;
    arg.value = buffers;
    FUN_00de54b0(this, arg);
    hkArray<Vertex>& vertices = geometry->vertices;
    GlobalContext* manager = FUN_00c85750();
    if (vertices.m_iElementCount == (vertices.m_iCapacityState & 0x3fffffffu))
    {
        ResizeAudioStream(manager->allocator, &vertices, sizeof(Vertex));
    }
    __m128 value = _mm_load_ps(reinterpret_cast<const float*>(&initialVertex));
    _mm_store_ps(reinterpret_cast<float*>(&vertices.m_data[vertices.m_iElementCount]), value);
    ++vertices.m_iElementCount;
    hkArray<Edge>& edges = geometry->edges;
    int required = segmentCount;
    GlobalContext* manager2 = FUN_00c85750();
    Allocator* edgeAllocator = manager2->allocator;
    int capacity = edges.m_iCapacityState & 0x3fffffffu;
    if (capacity < required)
    {
        int newCapacity = capacity * 2;
        if (required >= newCapacity)
            newCapacity = required;
        FUN_00c908c0(edgeAllocator, &edges, newCapacity, sizeof(Edge));
    }
    edges.m_iElementCount = required;
    int index = 0;
    int noAdjacent = -1;
    int initialCount = segmentCount;
    --initialCount;
    if (initialCount > 0)
    {
        do
        {
            Edge& entry = geometry->edges.m_data[index];
            entry.polygon = segmentCount;
            entry.end = index + 1;
            entry.start = index;
            entry.adjacent = noAdjacent;
            ++index;
        } while (index < segmentCount - 1);
    }
    Edge& last = geometry->edges.m_data[index];
    last.polygon = segmentCount;
    last.adjacent = noAdjacent;
    last.end = 0;
    last.start = index;
}

namespace fnv_00de58c0 {
struct __declspec(align(16)) S_00de58c0_V4
{
    float x, y, z, w;
};

struct S_00de58c0_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int bytes);
};

struct S_00de58c0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00de58c0_Heap* m_pStreamAllocator;
    S_00de58c0_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct S_00de58c0_Arr
{
    S_00de58c0_V4* m_data;
    int m_iElementCount;
    int m_cap;
};

struct S_00de58c0_Local
{
    S_00de58c0_V4* m_data;
    int m_iElementCount;
    int m_cap;
    int m_pStackAllocation;
    float m_buf[1024];
};

struct S_00de58c0_Alloc;
S_00de58c0_Router* __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(S_00de58c0_Alloc* a, S_00de58c0_Arr* arr, int n, int elemSize);

struct S_00de58c0_Obj
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
    S_00de58c0_V4 m_60;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int m_80;
    void FUN_00de54b0(struct S_00de58c0_Local* out);
    void FUN_00de58c0(struct S_00de58c0_Arr* out, struct S_00de58c0_Alloc* alloc);
};

static inline __m128& Q(S_00de58c0_V4& v)
{
    return *(__m128*)&v;
}

// Fills a local array via FUN_00de54b0, then writes four vectors per entry to out (m_60, entry i twice, entry i+1 mod m_80), growing out as needed.
// @fnv 0x00de58c0
void S_00de58c0_Obj::FUN_00de58c0(S_00de58c0_Arr* out, S_00de58c0_Alloc* alloc)
{
    S_00de58c0_Local tmp;
    tmp.m_data = (S_00de58c0_V4*)tmp.m_buf;
    tmp.m_iElementCount = 0;
    tmp.m_cap = 0x80000100;
    FUN_00de54b0(&tmp);
    int n = m_80;
    int newSize = n * 4;
    if ((out->m_cap & 0x3fffffff) < newSize)
    {
        int iDoubledCap = (out->m_cap & 0x3fffffff) * 2;
        FUN_00c908c0(alloc, out, newSize < iDoubledCap ? iDoubledCap : newSize, 16);
    }
    out->m_iElementCount = newSize;
    int iWrite = 0;
    for (int iRead = 0; iRead < m_80;)
    {
        Q(out->m_data[iWrite++]) = Q(m_60);
        Q(out->m_data[iWrite++]) = Q(tmp.m_data[iRead]);
        Q(out->m_data[iWrite++]) = Q(tmp.m_data[iRead]);
        iRead++;
        Q(out->m_data[iWrite++]) = Q(tmp.m_data[iRead % m_80]);
    }
    S_00de58c0_Heap& h = FUN_00c85750()->heap();
    tmp.m_iElementCount = 0;
    if ((tmp.m_cap & 0x80000000) == 0)
        h.ReturnMemory(tmp.m_data, (tmp.m_cap & 0x3fffffff) * 16);
}
}  // namespace fnv_00de58c0
