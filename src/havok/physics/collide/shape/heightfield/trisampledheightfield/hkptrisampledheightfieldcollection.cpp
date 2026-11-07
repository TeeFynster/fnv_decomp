
// src/havok/physics/collide/shape/heightfield/trisampledheightfield/hkptrisampledheightfieldcollection.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/trisampledheightfield/hkptrisampledheightfieldcollection.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep the unit's minimal SIMD type: the CRT's additional byte arrays change /GS code generation.
#define _INCLUDED_MM2
// Exe 0x00d26510 FUN_00d26510: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" LocalM128 _mm_setr_ps(float a, float b, float c, float d);
extern "C" void _mm_store_ss(float* p, LocalM128 a);

#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkpSampledHeightFieldShape.h"
#include "../../../../../../../include/hkpTriSampledHeightFieldCollection.h"

struct FUN_00d263f0_t
{
    char pad0[0x18];
    void* m_obj;    // +0x18
    int m_field1c;  // +0x1c
    char pad20[0x20];
    char m_buf40[0x40];  // +0x40

    int hkpTriSampledHeightFieldCollection_calcSizeForSpu(int a, int b);
};

// Calls a virtual function on m_obj with a and b-0x40, then maps the result to an offset in m_buf40 or stores it in m_field1c, returning -1 when out of range.
// @fnv 0x00d263f0
// src: HAVOK_LIB 0x00d263f0
int FUN_00d263f0_t::hkpTriSampledHeightFieldCollection_calcSizeForSpu(int a, int aiLimit)
{
    int iAdjusted = aiLimit - 0x40;
    void* obj = m_obj;
    int iResult = (*(int(__thiscall**)(void*, int, int))(*(unsigned char**)obj + 0x18))(obj, a, iAdjusted);
    if (iResult >= 0 && iResult <= iAdjusted)
    {
        if (m_obj == m_buf40)
        {
            m_field1c = 0;
            return iResult + 0x40;
        }
        m_field1c = iResult;
        return 0x40;
    }
    return -1;
}

struct FUN_00d26760_StandIn
{
    void FUN_00d26760();
};

struct FUN_00d26880_MemoryManagerClient
{
    virtual void BeforeAllocate1() = 0;
    virtual void BeforeAllocate2() = 0;
    virtual void Deallocate(void* object, unsigned short size) = 0;
};

struct FUN_00d26880_MemoryRouter
{
    unsigned char Padding[0x10];
    FUN_00d26880_MemoryManagerClient* Manager;
};

FUN_00d26880_MemoryRouter* _D1A0E0GetMemoryRouter();

struct FUN_00d26880_StandIn : public hkpTriSampledHeightFieldCollection
{
    hkpTriSampledHeightFieldCollection* hkpTriSampledHeightFieldCollection_Destroy(unsigned int flags);
};

// Runs FUN_00d26760 on this, then if flags bit 0 is set, frees this through the memory router's manager using the size at offset 4, and returns this.
// @fnv 0x00d26880
// src: COMMUNITY 0x00d26880
hkpTriSampledHeightFieldCollection* FUN_00d26880_StandIn::hkpTriSampledHeightFieldCollection_Destroy(unsigned int flags)
{
    reinterpret_cast<FUN_00d26760_StandIn*>(this)->FUN_00d26760();

    if (flags & 1u)
    {
        FUN_00d26880_MemoryRouter* router = _D1A0E0GetMemoryRouter();
        unsigned short size = *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(this) + 4);
        router->Manager->Deallocate(this, size);
    }

    return this;
}

// @fnv 0x00d26390
// src: GUESS 0x00d26390 (confidence: high)
int hkpTriSampledHeightFieldCollection_ReturnZero()
{
    return 0;
}

struct FUN_00d263a0_cls
{
    int unk00;
    int unk04;
    hkpSampledHeightFieldShape* unk08;
    int GetNextKey(unsigned int key);
};

// Returns the next key in a sequence derived from the given key, or -1 when the sequence is exhausted.
// @fnv 0x00d263a0
int __thiscall FUN_00d263a0_cls::GetNextKey(unsigned int key)
{
    if ((key & 1) == 0)
        return key | 1;
    unsigned int hi = key >> 16;
    unsigned int idx = ((key >> 1) & 0x7fff) + 1;
    unsigned int uiLimit = unk08->m_iXResolution - 1;
    if (idx == uiLimit)
    {
        unsigned int uiLimit2 = unk08->m_iZResolution - 1;
        hi++;
        idx = 0;
        if (hi == uiLimit2)
            return -1;
    }
    return (int)(((hi << 15) + idx) * 2);
}

// @fnv 0x00d26440
// src: GUESS 0x00d26440 (confidence: high)
int __stdcall Object_ReturnZero_00d26440(int arg0)
{
    return 0;
}

struct FUN_00d26450_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* unk18;
    void* hkpTriSampledHeightFieldCollection_getHeightFieldShape();
};
// @fnv 0x00d26450
// src: XBOX_PDB 0x00d26450
void* FUN_00d26450_Obj::hkpTriSampledHeightFieldCollection_getHeightFieldShape()
{
    return unk18;
}

struct S_d264d0_Coll : public hkpTriSampledHeightFieldCollection
{
    hkpSampledHeightFieldShape* hkpTriSampledHeightFieldCollection_getHeightFieldShape();
    void hkpTriSampledHeightFieldCollection_setWeldingInfo(unsigned int key, unsigned short value);
};

// src: XBOX_PDB 0x00d26450
__declspec(noinline) hkpSampledHeightFieldShape* S_d264d0_Coll::hkpTriSampledHeightFieldCollection_getHeightFieldShape()
{
    return m_pHeightFieldShape;
}

// Computes an index from key and count, then stores value in m_kWeldingInfo.m_data at that index.
// @fnv 0x00d264d0
// src: HAVOK_LIB 0x00d264d0
void S_d264d0_Coll::hkpTriSampledHeightFieldCollection_setWeldingInfo(unsigned int key, unsigned short value)
{
    unsigned int count = hkpTriSampledHeightFieldCollection_getHeightFieldShape()->m_iXResolution;
    unsigned int idx = ((count - 1) * (key >> 16) + ((key >> 1) & 0x7fff)) * 2 | (key & 1);
    m_kWeldingInfo.m_data[idx] = value;
}

extern int DAT_010ce390;
extern int DAT_010ce370;

void __stdcall FUN_00d21410(int a, int b);

struct Target26700
{
    void __thiscall FUN_00c90510();
};

struct FUN_00d26700
{
    void* m_vptr1;  // +0x00
    int m_04;
    int m_08;
    int m_0c;
    void* m_vptr2;  // +0x10
    int m_14;
    void* m_p;  // +0x18
    int m_1c;
    volatile float m_f;  // +0x20
    volatile int m_uiX;  // +0x24
    volatile int m_uiY;  // +0x28
    volatile int m_uiZ;  // +0x2c
    LocalM128 m_v;          // +0x30

    FUN_00d26700(void* p, float f);
};

// Initializes a FUN_00d26700 object with a pointer and float, sets vtable pointers and default values, then calls a method on the pointer.
// @fnv 0x00d26700
FUN_00d26700::FUN_00d26700(void* p, float f)
{
    FUN_00d21410(7, 2);
    m_vptr1 = &DAT_010ce390;
    m_vptr2 = &DAT_010ce370;
    m_uiX = 0;
    m_uiY = 0;
    m_uiZ = 0x80000000;
    m_f = f;
    m_p = p;
    m_v = _mm_setzero_ps();
    ((Target26700*)p)->FUN_00c90510();
}

// hkMemoryRouter is the shared Havok memory router: 0x00c85750 returns it, heap at +0x10.
namespace HavokHeap {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}


__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return HavokHeap::hkMemoryRouter_getInstance().heap();
}

template <class T, class Allocator>
__forceinline hkArray<T, Allocator>::~hkArray() throw()
{
    hkMemoryAllocator& alloc = Allocator().get(this);
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

struct RefD267 : public hkReferencedObject
{
    void FUN_00c905b0() throw();
};

class hkBase0D267
{
  public:
    virtual ~hkBase0D267() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08[2];
};

class hkBase1D267
{
  public:
    virtual ~hkBase1D267() throw()
    {}
    int unk14;
};

class FUN_00d26760 : public hkBase0D267, public hkBase1D267
{
  public:
    RefD267* m_pkRef;
    int unk1C[2];
    hkArray<short> m_ppData;

    virtual ~FUN_00d26760() throw();
};

// @fnv 0x00d26760
FUN_00d26760::~FUN_00d26760() throw()
{
    m_pkRef->FUN_00c905b0();
}

struct FUN_00d26450_S
{
    hkpSampledHeightFieldShape* hkpTriSampledHeightFieldCollection_getHeightFieldShape();
};

struct FUN_00d267c0_Alloc
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void Free(void* data, int size);
};

void* hkMemoryRouter_getInstance(void);
void hkArrayUtil__reserve(int a1, int a2, int a3, int a4);

struct FUN_00d267c0_t : FUN_00d26450_S
{
    void hkpTriSampledHeightFieldCollection_initWeldingInfo(int mode);
};

// Resizes the internal buffer to the computed index when mode is not 6, otherwise frees the buffer and resets its state fields.
// @fnv 0x00d267c0
// src: HAVOK_LIB 0x00d267c0
void FUN_00d267c0_t::hkpTriSampledHeightFieldCollection_initWeldingInfo(int mode)
{
    if (mode != 6)
    {
        const hkpSampledHeightFieldShape* o = hkpTriSampledHeightFieldCollection_getHeightFieldShape();
        int idx = (2 * o->m_iZResolution - 2) * (o->m_iXResolution - 1);
        char* arr = (char*)this + 0x24;
        char* cur = (char*)hkMemoryRouter_getInstance();
        if ((*(int*)(arr + 8) & 0x3fffffff) < idx)
        {
            hkArrayUtil__reserve(*(int*)(cur + 0x10), (int)arr, idx, 2);
        }
        cur = (char*)hkMemoryRouter_getInstance();
        int alloc = *(int*)(cur + 0x10);
        int a = *(int*)(arr + 8) & 0x3fffffff;
        if (a < idx)
        {
            int m = a * 2;
            hkArrayUtil__reserve(alloc, (int)arr, idx < m ? m : idx, 2);
        }
        *(int*)(arr + 4) = idx;
    }
    else
    {
        char* cur = (char*)hkMemoryRouter_getInstance();
        FUN_00d267c0_Alloc* alloc = *(FUN_00d267c0_Alloc**)(cur + 0x10);
        int a = *(int*)((char*)this + 0x2c);
        *(int*)((char*)this + 0x28) = 0;
        if (!(a & 0x80000000))
        {
            alloc->Free(*(void**)((char*)this + 0x24), (a & 0x3fffffff) * 2);
        }
        *(int*)((char*)this + 0x24) = 0;
        *(unsigned int*)((char*)this + 0x2c) = 0x80000000;
    }
}

struct S00d26510_Vec
{
    LocalM128 m_vComponents;
    void set(float a, float b, float c, float d)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
    void mul4(const hkVector4& v)
    {
        m_vComponents = _mm_mul_ps(v.m_vComponents, m_vComponents);
    }
};

struct S00d26510_Shape
{
    virtual ~S00d26510_Shape();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int m_ulUserData;
    int m_type;
};

struct S00d26510_ShapeB
{
    virtual ~S00d26510_ShapeB();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int m_ulUserData;
    int m_type;
    S00d26510_ShapeB(int type)
    {
        m_sReferenceCount = 1;
        m_ulUserData = 0;
        m_type = type;
    }
};

struct S00d26510_Convex : public S00d26510_ShapeB
{
    float m_fSphereRadius;
    S00d26510_Convex(int type, float radius) : S00d26510_ShapeB(type)
    {
        m_fSphereRadius = radius;
    }
};

struct S00d26510_Tri : public S00d26510_Convex
{
    unsigned short m_kWeldingInfo;
    unsigned char m_eWeldingType;
    unsigned char m_ucWeldingPadding;
    int unk18;
    int unk1C;
    LocalM128 m_kVertexA;
    LocalM128 m_kVertexB;
    LocalM128 m_kVertexC;
    LocalM128 m_kVertexTransform;

    void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }
    S00d26510_Tri(float radius) : S00d26510_Convex(3, radius)
    {
        m_kWeldingInfo = 0;
        m_eWeldingType = 6;
        m_kVertexTransform = _mm_setzero_ps();
        m_ucWeldingPadding = 0;
    }
    virtual ~S00d26510_Tri();
};

struct S00d26510_Container
{
    virtual ~S00d26510_Container();
    virtual const S00d26510_ShapeB* AllocateStorage_00d26510(unsigned int key, void* buffer) const;
};

struct S00d26510_Coll : public S00d26510_Shape, public S00d26510_Container
{
    int unk14;
    hkpSampledHeightFieldShape* m_pHeightFieldShape;
    int m_iChildSize;
    float m_fSphereRadius;
    unsigned short* m_weldingData;
    int m_weldingSize;
    int m_weldingCap;
    LocalM128 m_kTriangleExtrusion;

    hkpSampledHeightFieldShape* getHF() const;
    virtual const S00d26510_ShapeB* AllocateStorage_00d26510(unsigned int key, void* buffer) const;
};

__declspec(noinline) hkpSampledHeightFieldShape* S00d26510_Coll::getHF() const
{
    return m_pHeightFieldShape;
}

// Constructs a triangle shape in the provided buffer from heightfield vertices, welding data, and extrusion vector.
// @fnv 0x00d26510
// src: GUESS 0x00d26510 (confidence: low)
const S00d26510_ShapeB* S00d26510_Coll::AllocateStorage_00d26510(unsigned int key, void* buffer) const
{
    const S00d26510_Coll* coll = this;
    const hkpSampledHeightFieldShape* hf = coll->getHF();
    int x = (key & 0xffff) >> 1;
    int z = key >> 16;
    S00d26510_Tri* tri = new (buffer) S00d26510_Tri(m_fSphereRadius);
    S00d26510_Vec vertices[4];
    for (int i = 0; i < 4; i++)
    {
        int xx = ((key & 0xffff) >> 1) + (i >> 1);
        int zz = (key >> 16) + (i & 1);
        vertices[i].set((float)xx, hf->GetHeightAtGridPoint(xx, zz), (float)zz, 0.0f);
        vertices[i].mul4(hf->m_kHeightScaleVector);
    }
    hkBool flipB;
    // The shared vf14 declaration has no output parameter yet.
    typedef void (__thiscall* GetTriangleFlip)(const hkpSampledHeightFieldShape*, hkBool&);
    (*reinterpret_cast<GetTriangleFlip const* const*>(hf))[14](hf, flipB);
    int flip = flipB.m_cBooleanValue != 0;
    int iParity = key & 1;
    tri->m_kVertexA = vertices[(~flip & iParity) * 3].m_vComponents;
    tri->m_kVertexB = vertices[(flip + 1) * iParity + 1].m_vComponents;
    tri->m_kVertexC = vertices[flip - iParity + 2].m_vComponents;
    int size = coll->m_weldingSize;
    int type = size ? 0 : 6;
    int iWeldingInfo = size;
    if (size)
        iWeldingInfo = coll->m_weldingData[((coll->getHF()->m_iXResolution - 1) * z + x) * 2 | iParity];
    tri->m_kWeldingInfo = (unsigned short)iWeldingInfo;
    tri->m_eWeldingType = type;
    LocalM128 sq = _mm_mul_ps(coll->m_kTriangleExtrusion, coll->m_kTriangleExtrusion);
    LocalM128 len = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
    float l;
    _mm_store_ss(&l, len);

    tri->m_ucWeldingPadding = l > 0.0f;
    tri->m_kVertexTransform = coll->m_kTriangleExtrusion;
    return tri;
}

// FUN_00d26870 - MSVC this-adjusting thunk for a secondary base.
//
// The original is 8 bytes:
//     00d26870  83 e9 10          sub  ecx, 0x10
//     00d26873  e9 08 00 00 00    jmp  00d26880
//
// It is the adjustor thunk that cl 15.00.30729.01 emits for a virtual that a
// DERIVED class overrides but that was DECLARED by a SECONDARY base: the slot
// in the secondary base's vftable must hand the callee the address of the
// complete object, so the thunk subtracts the offset of the secondary base
// (0x10) from the incoming `this` before tail-jumping to the implementation.
//
// The game's own RTTI confirms the shape (the image has intact RTTI):
//     010ce36c  COL -> 011322d0, off = 16      (secondary vftable)
//     010ce370  00d26870  <-- this thunk, slot 0 of that vftable
//     010ce38c  COL -> 01132274, off = 0       (primary vftable)
//     010ce390  00d26880  <-- the implementation, slot 0 of the primary vftable
//     both COLs point at the type descriptor of hkpTriSampledHeightFieldCollection
// so the class really does have a second base at +0x10 and really does override
// that base's first virtual.
//
// Source shape (the standard cl adjustor-thunk recipe):
//   * two bases declare the same virtual at the same slot,
//   * the first base is padded so that the second base lands at +0x10,
//   * the derived class overrides the virtual - DECLARED ONLY, never defined,
//     so the `jmp` target stays an undefined external and the checker resolves
//     it from the original's own bytes (0x00d26880),
//   * a DEFINED key function in the derived class makes the compiler emit the
//     vftable, and with it the thunk.
//
// The thunk is the only DEFINED function symbol carrying the name FUN_00d26870
// (the three declarations below are undefined externals), which is what the
// canary requires.

struct TtrcHeightFieldShapeBase
{
    TtrcHeightFieldShapeBase();
    virtual void FUN_00d26870();
    char pad[0x0c];  // the vptr plus padding: this base is 0x10 bytes
};

struct TtrcHeightFieldShape
{
    TtrcHeightFieldShape();
// @fnv 0x00d26870
    virtual void FUN_00d26870();
};

struct TtrcHeightFieldCollection : public TtrcHeightFieldShapeBase, public TtrcHeightFieldShape
{
    TtrcHeightFieldCollection();
    virtual void key_fn();  // key function - defined, so the vftable is emitted
    void FUN_00d26870();    // the shared override - declared only
};

TtrcHeightFieldCollection::TtrcHeightFieldCollection()
{}
void TtrcHeightFieldCollection::key_fn()
{}
