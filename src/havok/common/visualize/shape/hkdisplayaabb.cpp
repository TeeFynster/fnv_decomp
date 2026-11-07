
// src/havok/common/visualize/shape/hkdisplayaabb.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplayaabb.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include "../../../../../include/hkAabb.h"
struct VertexBuffer
{
    __m128* values;
    unsigned int count;
    unsigned int capacityFlags;
};
extern "C" void __cdecl hkArrayUtil__reserve(unsigned int allocator, VertexBuffer* output, unsigned int capacity,
                                     unsigned int alignment);
struct BoundsWriter
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
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    float minX;
    float minY;
    float minZ;
    unsigned int unk6c;
    float maxX;
    float maxY;
    float maxZ;
    void WriteBoundsVertices(VertexBuffer* output, unsigned int allocator);
};
// Expands output capacity to at least 24, then writes 24 SIMD vertex values from the bounds min/max into output->values.
// @fnv 0x00de1260
void BoundsWriter::WriteBoundsVertices(VertexBuffer* output, unsigned int allocator)
{
    int oldCapacity = output->capacityFlags & 0x3FFFFFFF;
    if (oldCapacity < 24)
    {
        int newCapacity = oldCapacity * 2;
        if (newCapacity <= 24)
            newCapacity = 24;
        hkArrayUtil__reserve(allocator, output, newCapacity, 16);
    }
    output->count = 24;
    output->values[0] = _mm_setr_ps(this->minX, this->minY, this->minZ, 0.0f);
    output->values[1] = _mm_setr_ps(this->minX, this->maxY, this->minZ, 0.0f);
    output->values[2] = _mm_setr_ps(this->minX, this->minY, this->minZ, 0.0f);
    output->values[3] = _mm_setr_ps(this->minX, this->minY, this->maxZ, 0.0f);
    output->values[4] = _mm_setr_ps(this->minX, this->minY, this->minZ, 0.0f);
    output->values[5] = _mm_setr_ps(this->maxX, this->minY, this->minZ, 0.0f);
    output->values[6] = _mm_setr_ps(this->maxX, this->maxY, this->maxZ, 0.0f);
    output->values[7] = _mm_setr_ps(this->maxX, this->maxY, this->minZ, 0.0f);
    output->values[8] = _mm_setr_ps(this->maxX, this->maxY, this->maxZ, 0.0f);
    output->values[9] = _mm_setr_ps(this->minX, this->maxY, this->maxZ, 0.0f);
    output->values[10] = _mm_setr_ps(this->maxX, this->maxY, this->maxZ, 0.0f);
    output->values[11] = _mm_setr_ps(this->maxX, this->minY, this->maxZ, 0.0f);
    output->values[12] = _mm_setr_ps(this->minX, this->maxY, this->minZ, 0.0f);
    output->values[13] = _mm_setr_ps(this->maxX, this->maxY, this->minZ, 0.0f);
    output->values[14] = _mm_setr_ps(this->minX, this->maxY, this->minZ, 0.0f);
    output->values[15] = _mm_setr_ps(this->minX, this->maxY, this->maxZ, 0.0f);
    output->values[16] = _mm_setr_ps(this->maxX, this->maxY, this->minZ, 0.0f);
    output->values[17] = _mm_setr_ps(this->maxX, this->minY, this->minZ, 0.0f);
    output->values[18] = _mm_setr_ps(this->minX, this->maxY, this->maxZ, 0.0f);
    output->values[19] = _mm_setr_ps(this->minX, this->minY, this->maxZ, 0.0f);
    output->values[20] = _mm_setr_ps(this->minX, this->minY, this->maxZ, 0.0f);
    output->values[21] = _mm_setr_ps(this->maxX, this->minY, this->maxZ, 0.0f);
    output->values[22] = _mm_setr_ps(this->maxX, this->minY, this->maxZ, 0.0f);
    output->values[23] = _mm_setr_ps(this->maxX, this->minY, this->minZ, 0.0f);
}

namespace fnv_00de15c0 {
// InitBoxMesh worker9 v1: __thiscall, no stack args, no frame in ORIG.
// Allocates a 24B DisplayGeometry { VertArr verts; FaceArr faces; } via the singleton
// allocator vtable slot +4, stores it at this->m_08, then pushes the 8 box
// corners (this->m_60 / this->m_70) into verts and 12 index triples into faces.

extern "C" const float DAT_01011d78;  // 0.0f (w component source)

struct __declspec(align(16)) Vec4f
{
    union
    {
        float f[4];
        __m128 v;
    };
};

struct AllocVt
{
    void* f0;
    void*(__thiscall* allocFn)(void* self, int bytes);
};
struct AllocObj
{
    AllocVt* vt;
};
struct Singleton
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    AllocObj* m_10;
};

extern "C" Singleton* hkMemoryRouter_getInstance();
static void StorePs(Vec4f* dst, __m128 v)
{
    dst->v = v;
}
extern "C" void hkArrayUtil__reserve(void* ctx, void* arr, int newcap, int elemSize);

struct VertArr
{
    Vec4f* data;
    int size;
    int cap;
};
struct Face
{
    int i0;
    int i1;
    int i2;
    int i3;
};
struct FaceArr
{
    Face* data;
    int size;
    int cap;
};
// hkGeometry layout (hkArray<hkVector4> vertices, hkArray<Triangle> triangles; 24 bytes) built locally with this unit's inline array growth
struct DisplayGeometry
{
    VertArr verts;
    FaceArr faces;
};

struct ThisCls
{
    int m_00;
    int m_04;
    DisplayGeometry* m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
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
    hkAabb m_60;
    void InitBoxMesh();
};

// Allocates a DisplayGeometry at m_08, appends the eight corners of the m_60 bounds as vertices, then appends 12 faces of three indices plus -1.
// @fnv 0x00de15c0
void ThisCls::InitBoxMesh()
{
    Singleton* s = hkMemoryRouter_getInstance();
    AllocObj* ao = s->m_10;
    DisplayGeometry* p = (DisplayGeometry*)ao->vt->allocFn(ao, 24);
    DisplayGeometry* result;
    if (p)
    {
        VertArr* va = &p->verts;
        va->data = 0;
        va->size = 0;
        va->cap = (int)0x80000000;
        FaceArr* fa = &p->faces;
        fa->data = 0;
        fa->size = 0;
        fa->cap = (int)0x80000000;
        result = p;
    }
    else
    {
        result = 0;
    }
    m_08 = result;

    // 8 box corners into verts
    {
        VertArr* a = &m_08->verts;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        StorePs(&a->data[sz], _mm_setr_ps(m_60.m_kMinimumCorner.x, m_60.m_kMinimumCorner.y, m_60.m_kMinimumCorner.z, DAT_01011d78));
    }
    {
        VertArr* a = &m_08->verts;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        StorePs(&a->data[sz], _mm_setr_ps(m_60.m_kMinimumCorner.x, m_60.m_kMinimumCorner.y, m_60.m_kMaximumCorner.z, DAT_01011d78));
    }
    {
        VertArr* a = &m_08->verts;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        StorePs(&a->data[sz], _mm_setr_ps(m_60.m_kMaximumCorner.x, m_60.m_kMinimumCorner.y, m_60.m_kMaximumCorner.z, DAT_01011d78));
    }
    {
        VertArr* a = &m_08->verts;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        StorePs(&a->data[sz], _mm_setr_ps(m_60.m_kMaximumCorner.x, m_60.m_kMinimumCorner.y, m_60.m_kMinimumCorner.z, DAT_01011d78));
    }
    {
        VertArr* a = &m_08->verts;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        StorePs(&a->data[sz], _mm_setr_ps(m_60.m_kMinimumCorner.x, m_60.m_kMaximumCorner.y, m_60.m_kMinimumCorner.z, DAT_01011d78));
    }
    {
        VertArr* a = &m_08->verts;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        StorePs(&a->data[sz], _mm_setr_ps(m_60.m_kMinimumCorner.x, m_60.m_kMaximumCorner.y, m_60.m_kMaximumCorner.z, DAT_01011d78));
    }
    {
        VertArr* a = &m_08->verts;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        StorePs(&a->data[sz], _mm_setr_ps(m_60.m_kMaximumCorner.x, m_60.m_kMaximumCorner.y, m_60.m_kMaximumCorner.z, DAT_01011d78));
    }
    {
        VertArr* a = &m_08->verts;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        StorePs(&a->data[sz], _mm_setr_ps(m_60.m_kMaximumCorner.x, m_60.m_kMaximumCorner.y, m_60.m_kMinimumCorner.z, DAT_01011d78));
    }

    // 12 index triples into faces
    {
        FaceArr* a = &m_08->faces;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        Face* fp = &a->data[sz];
        fp->i0 = 0;
        fp->i1 = 3;
        fp->i2 = 1;
        fp->i3 = -1;
    }
    {
        FaceArr* a = &m_08->faces;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        Face* fp = &a->data[sz];
        fp->i0 = 1;
        fp->i1 = 3;
        fp->i2 = 2;
        fp->i3 = -1;
    }
    {
        FaceArr* a = &m_08->faces;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        Face* fp = &a->data[sz];
        fp->i0 = 2;
        fp->i1 = 6;
        fp->i2 = 5;
        fp->i3 = -1;
    }
    {
        FaceArr* a = &m_08->faces;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        Face* fp = &a->data[sz];
        fp->i0 = 5;
        fp->i1 = 1;
        fp->i2 = 2;
        fp->i3 = -1;
    }
    {
        FaceArr* a = &m_08->faces;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        Face* fp = &a->data[sz];
        fp->i0 = 5;
        fp->i1 = 6;
        fp->i2 = 4;
        fp->i3 = -1;
    }
    {
        FaceArr* a = &m_08->faces;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        Face* fp = &a->data[sz];
        fp->i0 = 4;
        fp->i1 = 6;
        fp->i2 = 7;
        fp->i3 = -1;
    }
    {
        FaceArr* a = &m_08->faces;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        Face* fp = &a->data[sz];
        fp->i0 = 7;
        fp->i1 = 3;
        fp->i2 = 0;
        fp->i3 = -1;
    }
    {
        FaceArr* a = &m_08->faces;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        Face* fp = &a->data[sz];
        fp->i0 = 0;
        fp->i1 = 4;
        fp->i2 = 7;
        fp->i3 = -1;
    }
    {
        FaceArr* a = &m_08->faces;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        Face* fp = &a->data[sz];
        fp->i0 = 0;
        fp->i1 = 1;
        fp->i2 = 4;
        fp->i3 = -1;
    }
    {
        FaceArr* a = &m_08->faces;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        Face* fp = &a->data[sz];
        fp->i0 = 4;
        fp->i1 = 1;
        fp->i2 = 5;
        fp->i3 = -1;
    }
    {
        FaceArr* a = &m_08->faces;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        Face* fp = &a->data[sz];
        fp->i0 = 2;
        fp->i1 = 3;
        fp->i2 = 6;
        fp->i3 = -1;
    }
    {
        FaceArr* a = &m_08->faces;
        Singleton* sg = hkMemoryRouter_getInstance();
        void* ctx = sg->m_10;
        int sz = a->size;
        int newSize = sz + 1;
        if ((a->cap & 0x3fffffff) < newSize)
        {
            int dbl = (a->cap & 0x3fffffff) * 2;
            if (newSize < dbl)
                newSize = dbl;
            hkArrayUtil__reserve(ctx, a, newSize, 16);
        }
        a->size += 1;
        Face* fp = &a->data[sz];
        fp->i0 = 6;
        fp->i1 = 3;
        fp->i2 = 7;
        fp->i3 = -1;
    }
}
}  // namespace fnv_00de15c0
