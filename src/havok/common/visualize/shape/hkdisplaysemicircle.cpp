// src/havok/common/visualize/shape/hkdisplaysemicircle.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaysemicircle.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
struct VectorArray
{
    __m128* data;
    int size;
    unsigned int capacityAndFlags;
};
struct Heap
{
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    virtual void unknown3();
    virtual void deallocate(void*, unsigned int);
};
struct GlobalContext
{
    int unk00, unk04, unk08, unk0c;
    Heap* heap;
    __forceinline Heap* getHeap()
    {
        return heap;
    }
};
extern GlobalContext* __cdecl hkMemoryRouter_getInstance();
extern void __cdecl hkArrayUtil__reserve(void*, VectorArray*, int, int);
struct Geometry
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
    void __thiscall hkDisplaySemiCircle_generatePoints(VectorArray*);
    void __thiscall hkDisplaySemiCircle_getWireframeGeometry(VectorArray*, void*);
};
// Fills a temporary array via FUN_00de4af0, then writes consecutive pairs (i, i+1) from it into destination, 2*unk9c entries, growing destination as needed.
// @fnv 0x00de4c40
// src: HAVOK_SRC 0x00de4c40
void __thiscall Geometry::hkDisplaySemiCircle_getWireframeGeometry(VectorArray* destination, void* allocator)
{
    VectorArray temporary = {0, 0, 0x80000000u};
    hkDisplaySemiCircle_generatePoints(&temporary);
    int required = unk9c * 2;
    int capacity = destination->capacityAndFlags & 0x3fffffff;
    if (capacity < required)
    {
        int newCapacity = capacity * 2;
        if (required >= newCapacity)
            newCapacity = required;
        hkArrayUtil__reserve(allocator, destination, newCapacity, 16);
    }
    destination->size = required;
    int outputIndex = 0;
    for (int i = 0; i < unk9c; ++i)
    {
        destination->data[outputIndex++] = temporary.data[i];
        destination->data[outputIndex++] = temporary.data[i + 1];
    }
    Heap* heap = hkMemoryRouter_getInstance()->getHeap();
    temporary.size = 0;
    if ((temporary.capacityAndFlags & 0x80000000u) == 0)
    {
        heap->deallocate(temporary.data, (temporary.capacityAndFlags & 0x3fffffff) * 16);
    }
}

#include <xmmintrin.h>
namespace fnv_00de4d20 {
#include <xmmintrin.h>

struct S_de4d20_Heap
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int n);
};

struct S_de4d20_Holder
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_de4d20_Heap* unk10;

    S_de4d20_Heap& heap()
    {
        return *unk10;
    }
};

S_de4d20_Holder* hkMemoryRouter_getInstance() throw();
void FUN_00c90940(S_de4d20_Heap& h, void* arr, int elemSize) throw();

struct __declspec(align(16)) S_de4d20_Vec
{
    float x;
    float y;
    float z;
    float w;
};

struct S_de4d20_Cell
{
    int a;
    int b;
    int c;
    int d;
};

struct S_de4d20_Grid
{
    S_de4d20_Vec* data;
    int size;
    unsigned int cap;
    S_de4d20_Cell* cells;
    int cellSize;
    unsigned int cellCap;

    static void* operator new(unsigned int n)
    {
        return hkMemoryRouter_getInstance()->heap().AllocateMemoryBlock(n);
    }

    static void operator delete(void*)
    {}

    S_de4d20_Grid() throw()
    {
        data = 0;
        size = 0;
        cap = 0x80000000;
        cells = 0;
        cellSize = 0;
        cellCap = 0x80000000;
    }
};

struct S_de4d20_Context
{
    int unk0;
    int unk4;
    S_de4d20_Grid* m8;
    int unkc;
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

    __declspec(align(16)) S_de4d20_Vec m80;

    int unk90;
    int unk94;
    int unk98;
    int m9c;

    void hkDisplaySemiCircle_generatePoints(S_de4d20_Grid* g) throw();
    void hkDisplaySemiCircle_buildGeometry() throw();
};

// Allocates a grid, stores it in m8, calls FUN_00de4af0, appends m80 to the grid data, and fills m9c cells with index ranges.
// @fnv 0x00de4d20
// src: HAVOK_SRC 0x00de4d20
void S_de4d20_Context::hkDisplaySemiCircle_buildGeometry() throw()
{
    S_de4d20_Grid* g = new S_de4d20_Grid;
    m8 = g;
    hkDisplaySemiCircle_generatePoints(g);

    S_de4d20_Grid* arr = m8;
    S_de4d20_Holder* r = hkMemoryRouter_getInstance();

    if (arr->size == (int)(arr->cap & 0x3fffffff))
        FUN_00c90940(r->heap(), arr, 0x10);

    int i = 0;
    int off = 0;

    *(__m128*)&arr->data[arr->size] = *(__m128*)&m80;
    arr->size++;

    volatile S_de4d20_Grid* current = m8;
    int last = current->size - 1;

    if (m9c > 0)
    {
        do
        {
            S_de4d20_Cell* c = (S_de4d20_Cell*)((char*)m8->cells + off);

            c->a = last;
            c->b = i + 1;
            c->c = i;
            c->d = -1;

            off += 16;
            i++;
        } while (i < m9c);
    }
}
}  // namespace fnv_00de4d20
