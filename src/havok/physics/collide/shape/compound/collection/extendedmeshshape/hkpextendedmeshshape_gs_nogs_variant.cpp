#include "../../../../../../../../include/hkArray.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/BSAudio.h"
#include "../../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../../include/hkVector4.h"


// src/havok/physics/collide/shape/compound/collection/extendedmeshshape/hkpextendedmeshshape_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/shape/compound/collection/extendedmeshshape/hkpextendedmeshshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/compound/collection/extendedmeshshape/hkpextendedmeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/extendedmeshshape/hkpextendedmeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00d554a0_class
{
    int m_d0;
    int __thiscall hkpShapeContainer_getNumChildShapes();
    int __thiscall GetOrInitValue();
};
void __cdecl hkAabbUtil_calcAabb_00d26230(void* first, void* second, void* third, float value, int last);
struct FUN_00d56040_shell
{
    void __thiscall hkpExtendedMeshShape_getAabbImpl(void* first, float value, int last);
};
__declspec(nothrow) BSAudio* __cdecl hkMemoryRouter_getInstance();
inline hkMemoryRouter* audio()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}
__declspec(nothrow) void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);
static __forceinline void hkShortArray_reserveExactly(hkArrayBase<short>& self, int n)
{
        hkMemoryRouter* m = audio();
        if (self.getCapacity() < n)
            hkArrayUtil__reserve(m->heap(), (&self), n, sizeof(short));
    }

static __forceinline void hkShortArray_reserve(hkArrayBase<short>& self, int n)
{
        hkMemoryAllocator& alloc = audio()->heap();
        if (self.getCapacity() < n)
        {
            int cap = 2 * self.getCapacity();
            hkArrayUtil__reserve(alloc, (&self), n < cap ? cap : n, sizeof(short));
        }
    }

static __forceinline void hkShortArray_SetSizeAndGrow(hkArrayBase<short>& self, int n)
{
        hkShortArray_reserve(self, n);
        self.m_iElementCount = n;
    }
struct Elem
{
    char pad0[0x14];
    int m_uiItemCount;
    char pad1[0x4c - 0x18];
    int m_offset;
    char pad2[0x60 - 0x50];
};
struct FUN_00d56070_class
{
    char pad0[0xb0];
    int m_bits;
    Elem* m_pElements;
    int m_iCapacityFlags;
    char pad1[0xcc - 0xbc];
    hkArrayBase<short> m_aiIndexedValues;
    void SetShortAtKey(int key, short value);
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}
struct S_00d56880_Elem
{
    unsigned char unk0;
    unsigned char unk1;
    short unk2;
    int unk4;
    short unk8;
    short unka;
    int unkc;
    int unk10;
    void* m_data;
    int m_iElementCount;
    int m_cap;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    S_00d56880_Elem()
    {
        unk8 = 0;
        unk2 = 0;
        unka = 1;
        unk0 = 1;
        unk1 = 1;
        unkc = 0;
        unk4 = 0;
        unk10 = 0;
        m_data = 0;
        m_iElementCount = 0;
        m_cap = 0x80000000;
    }
};
struct S_00d56880_Array
{
    S_00d56880_Elem* m_data;
    int m_iElementCount;
    int m_cap;
    int getCapacity() const
    {
        return m_cap & 0x3fffffff;
    }
    __forceinline void GrowArrayCapacity(hkMemoryAllocator& a, int n)
    {
        if (getCapacity() < n)
        {
            int cap2 = 2 * getCapacity();
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(a, this, newSize, sizeof(S_00d56880_Elem));
        }
    }
    __forceinline S_00d56880_Elem* expandBy(int n)
    {
        hkMemoryAllocator& a = audio()->heap();
        int oldsize = m_iElementCount;
        GrowArrayCapacity(a, oldsize + n);
        S_00d56880_Elem* p = m_data + m_iElementCount;
        for (int i = 0; i < n; i++)
            new (p + i) S_00d56880_Elem();
        m_iElementCount += n;
        return m_data + oldsize;
    }
};
struct S_00d56880
{
    int unk0;
    int unk4;
    int unk8;
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
    S_00d56880_Array m_aiIndexedValues;
    S_00d56880_Elem* AppendElement();
};
struct FUN_00d55520_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_18;
};
int __stdcall hkpExtendedMeshShape__getNumChildShapesInShapesSubpart(FUN_00d55520_cls* a1);
struct SpawnedOwner
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
    int m_0xdc;

    int hkpExtendedMeshShape_getMeshMaterial(int aiIndex);
};
struct FUN_00d555d0_cls
{
    int m_d0;
    int GetSpawnedValue(int aiKey);
};
struct Child
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual int v18(int a1, int a2);
};
struct Group
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Child** m_14;
    int m_18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    unsigned int m_3c;
};
struct FUN_00d55a90_cls
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
    Group* m_0c0;
    int m_0c4;

    int __thiscall hkpExtendedMeshShape_calcSizeForSpu(int a1, int a2);
};
struct S_00d55bd0_Bool
{
    char m_cBooleanValue;
    S_00d55bd0_Bool(bool b) : m_cBooleanValue(b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};
struct S_00d55bd0_Shape
{
    int unk0;
    int unk4;
    int unk8;
    int m_type;
};
struct S_00d55bd0_TriangleShape : S_00d55bd0_Shape
{
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_kVertexA;
    hkVector4 m_kVertexB;
    hkVector4 m_kVertexC;
};
S_00d55bd0_Bool IsDegenerateTriangle(const hkVector4& a, const hkVector4& b,
                                     const hkVector4& c, float tolerance);
struct S_00d55bd0_TrianglesSubpart
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int m_iTriangleCount;
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
};
struct S_00d55bd0_ShapesSubpart
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int m_iChildShapeCount;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
};
static const float DAT_011b2e90 = 1e-07f;
struct S_00d55bd0_MeshShape
{
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void vf10();
    virtual const S_00d55bd0_Shape* GetShapeForKey(unsigned int key, void* buffer) const;
    int unk4;
    int unk8;
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
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int m_iNumBitsForSubpartIndex;
    S_00d55bd0_TrianglesSubpart* m_kTrianglesSubparts;
    unsigned int m_numTrianglesSubparts;
    int unkac;
    S_00d55bd0_ShapesSubpart* m_kShapesSubparts;
    unsigned int m_numShapesSubparts;

    unsigned int FindNextNonDegenerateShapeKey(unsigned int initialKey) const;
};
struct BufferAllocator
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Release(void* data, unsigned bytes);
};
struct Container
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    hkReferencedObject** data;
    int count;
    unsigned capacityFlags;
    void ProcessEntries_00d56800();
};
struct FUN_00d55b40_Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float unk20[4];
    float unk30[4];
    float unk40[4];
};
struct __declspec(align(16)) FUN_00d55b40_Buffer
{
    int v[128];
};
extern char* __cdecl IsDegenerateTriangle(char* result, const void* v0, const void* v1, const void* v2, float tol);
struct bhkShapeOwner
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual int v3(int);
    virtual void* v4();
    virtual void* v5(int, void*);
    struct
    {
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
        int unka0;
        int unka4;
    } unk04;
    int unk_a8;
    int unk_ac;
    int unk_b0;
    int unk_b4;
    int GetShapeKey();
};
void __stdcall Object_DoNothing_00d554e0(int a);
void __stdcall hkpExtendedMeshShape_DoNothing(int a0);
struct ElemD562
{
    unsigned char m_b0;
    unsigned char m_b1;
    short m_s2;
    int m_i4;
    short m_s8;
    short m_sA;
    int m_iC;
    int m_i10;
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    hkVector4 m_kVec;
    int unk40, unk44;
    unsigned char unk48;
    unsigned char m_b49;
    short unk4A;
    int unk4C;
    int m_i50;
    int unk54, unk58, unk5C;

    ElemD562()
    {
        m_s8 = 0;
        m_s2 = 0;
        m_b0 = 0;
        m_b1 = 1;
        m_sA = 1;
        m_iC = 0;
        m_i4 = 0;
        m_i10 = 0;
        m_b49 = 0;
        m_kVec.setZero4();
        m_i50 = 0;
    }
};
static __forceinline void ArrayD562_reserve(hkArrayBase<ElemD562>& self, hkMemoryAllocator& alloc, int n)
{
        if (self.getCapacity() < n)
        {
            int cap = 2 * self.getCapacity();
            hkArrayUtil__reserve(alloc, (&self), n < cap ? cap : n, sizeof(ElemD562));
        }
    }

static __forceinline ElemD562& ArrayD562_AllocatePair(hkArrayBase<ElemD562>& self)
{
        hkMemoryAllocator& alloc = audio()->heap();
        int oldSize = self.m_iElementCount;
        ArrayD562_reserve(self, alloc, oldSize + 1);
        new (self.m_data + self.m_iElementCount) ElemD562();
        self.m_iElementCount += 1;
        return self.m_data[oldSize];
    }
struct OwnerD562
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    ElemD562 m_kInline;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC;
    int unkB0;
    hkArrayBase<ElemD562> m_kArray;

    ElemD562* hkpExtendedMeshShape_expandOneTriangleSubparts();
};

extern "C" __m128 _mm_add_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_load_ps1(float const* _A);
extern "C" __m128 _mm_max_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_min_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_mul_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_sub_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_xor_ps(__m128 _A, __m128 _B);
extern float DAT_0104da48;

struct S00d55950_hkAabb
{
    __m128 m_kMinimumCorner;
    __m128 m_kMaximumCorner;
};

void __cdecl calcAabbExtents(void* elem, void* unk80, S00d55950_hkAabb* aabb);

extern __m128 DAT_010c44d0;
extern __m128 DAT_010c71d0;
struct S00d55950_MeshTransform
{
    __m128 rotation0, rotation1, rotation2;
    struct
    {
        int x, y, z, w;
    } translation;
    void hkRotation_set(const void* quaternion);
};
struct S00d55950_MeshChild
{
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void getAabb(const S00d55950_MeshTransform& transform, float tolerance, S00d55950_hkAabb& out);
};
// src: XBOX_PDB 0x00d558b0
static __declspec(noinline) void calcAabbExtents_00d558b0(const S_00d56880_Elem* elem, S00d55950_hkAabb* out)
{
    out->m_kMinimumCorner = _mm_load_ps1(&DAT_0104da48);
    out->m_kMaximumCorner = _mm_xor_ps(out->m_kMinimumCorner, DAT_010c44d0);
    S00d55950_MeshTransform transform;
    transform.translation.x = elem->unk30;
    transform.translation.y = elem->unk34;
    transform.translation.z = elem->unk38;
    transform.translation.w = elem->unk3c;
    transform.hkRotation_set(&elem->unk20);
    for (int i = 0; i < elem->m_iElementCount; ++i)
    {
        S00d55950_hkAabb aabb;
        static_cast<S00d55950_MeshChild**>(elem->m_data)[i]->getAabb(transform, 0.0f, aabb);
        out->m_kMinimumCorner = _mm_min_ps(out->m_kMinimumCorner, aabb.m_kMinimumCorner);
        out->m_kMaximumCorner = _mm_max_ps(out->m_kMaximumCorner, aabb.m_kMaximumCorner);
    }
}

struct S_00d55950
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
    __m128 m_vHalfExtents;
    __m128 m_kCenterPosition;
    int unkB0;
    Elem* m_pElements;
    int m_iCapacityFlags;
    int unkBC;
    S_00d56880_Elem* m_elems2;
    int m_numElems2;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    float m_ucUnknownByte;

    void hkpExtendedMeshShape_recalcAabbExtents();
};

// @fnv 0x00d55950
// src: XBOX_PDB 0x00d55950
void S_00d55950::hkpExtendedMeshShape_recalcAabbExtents()
{
    S00d55950_hkAabb bounds;
    bounds.m_kMinimumCorner = _mm_load_ps1(&DAT_0104da48);
    bounds.m_kMaximumCorner = _mm_xor_ps(bounds.m_kMinimumCorner, DAT_010c44d0);
    __m128 padVec = _mm_load_ps1(&this->m_ucUnknownByte);

    for (int i = 0; i < this->m_iCapacityFlags; ++i)
    {
        S00d55950_hkAabb tempAabb;
        calcAabbExtents(&this->m_pElements[i], &this->unk80, &tempAabb);
        tempAabb.m_kMinimumCorner = _mm_sub_ps(tempAabb.m_kMinimumCorner, padVec);
        tempAabb.m_kMaximumCorner = _mm_add_ps(tempAabb.m_kMaximumCorner, padVec);
        bounds.m_kMinimumCorner = _mm_min_ps(bounds.m_kMinimumCorner, tempAabb.m_kMinimumCorner);
        bounds.m_kMaximumCorner = _mm_max_ps(bounds.m_kMaximumCorner, tempAabb.m_kMaximumCorner);
    }

    for (int j = 0; j < this->m_numElems2; ++j)
    {
        S00d55950_hkAabb tempAabb;
        calcAabbExtents_00d558b0(&this->m_elems2[j], &tempAabb);
        bounds.m_kMinimumCorner = _mm_min_ps(bounds.m_kMinimumCorner, tempAabb.m_kMinimumCorner);
        bounds.m_kMaximumCorner = _mm_max_ps(bounds.m_kMaximumCorner, tempAabb.m_kMaximumCorner);
    }

    this->m_kCenterPosition = _mm_mul_ps(_mm_add_ps(bounds.m_kMaximumCorner, bounds.m_kMinimumCorner), DAT_010c71d0);
    this->m_vHalfExtents = _mm_mul_ps(_mm_sub_ps(bounds.m_kMaximumCorner, bounds.m_kMinimumCorner), DAT_010c71d0);
}
