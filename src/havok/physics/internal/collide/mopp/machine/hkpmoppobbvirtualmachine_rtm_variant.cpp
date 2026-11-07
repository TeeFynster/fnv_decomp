// src/havok/physics/internal/collide/mopp/machine/hkpmoppobbvirtualmachine_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/internal/collide/mopp/machine/hkpmoppobbvirtualmachine.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/internal/collide/mopp/machine/hkpmoppobbvirtualmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/machine/hkpmoppobbvirtualmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/HitArray.h"
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
struct GridSource {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float f10;
    float f14;
    float f18;
    float f1c;
    unsigned char* p20;
};
struct GridBounds {
    float f00;
    float f04;
    float f08;
    float unk0c;
    float f10;
    float f14;
    float f18;
};
struct __declspec(align(16)) GridScratch {
    int f00;
    int f04;
    int f08;
    int unk0c;
    int f10;
    int f14;
    int f18;
    int unk1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
};
struct GridCell {
    int m00;
    int unk04;
    int unk08;
    int unk0c;
    union {
        int m10;
        struct {
            short unk10;
            short m12;
        };
    };
    union {
        int m14;
        struct {
            short unk14;
            short m16;
        };
    };
    int m18;
    int unk1c;
    union {
        int m20;
        struct {
            short unk20;
            short m22;
        };
    };
    union {
        int m24;
        struct {
            short unk24;
            short m26;
        };
    };
    union {
        int m28;
        struct {
            short unk28;
            short m2a;
        };
    };
    int unk2c;
    void* m30;
    int m34;

    void hkpMoppObbVirtualMachine_queryAabb(GridSource* a1, GridBounds* a2, int a3);
    void Execute(GridScratch* s, unsigned char* p, int z);
};
extern "C" void _ReadWriteBarrier();
extern "C" void __debugbreak();
struct __declspec(align(16)) QueryState {
 union {int lower[4]; struct {int f00;int f04;int f08;int unk0c;};};
 union {int upper[4]; struct {int f10;int f14;int f18;int unk1c;};};
 union {int origin[3]; struct {int f20;int f24;int f28;};};
 union {unsigned primitiveOffset;unsigned f2c;};
 union {int shift;int f30;};
 union {unsigned properties[1];unsigned f34;};
};
struct CodeData {
 int unk00;int unk04;int unk08;int unk0c;
 float f10;float f14;float f18;float f1c;
 union {unsigned char* code;unsigned char* p20;};
};
struct AllocatorContext { int field00, field04, field08, field0c; void* allocator; };
extern AllocatorContext* __cdecl hkMemoryRouter_getInstance();
extern void __cdecl ResizeAudioStream(void*, void*, int);
extern unsigned char DAT_01269cbc;
extern void __cdecl ValidateHavokKeyCode(unsigned char*);
struct ErrorText { char* data; int length; int capacity; void FUN_00cb1600(char*,int); void ProcessAndReturnValue_00cc01c0(const char*); void FUN_00cc00e0(); };
struct ErrorReporter { virtual void ReportDiagnostic(); virtual void unused1(); virtual void unused2(); virtual int report(int,unsigned,const char*,const char*,int); };
extern ErrorReporter* DAT_01268360;
struct VirtualMachine {
 union {int m00;HitArray* hits;};
 int unk04;int unk08;int unk0c;
 union {int lower[4];struct {
 union {int m10;struct {short unk10;short m12;};};
 union {int m14;struct {short unk14;short m16;};};
 int m18;int unk1c;
 };};
 union {int upper[4];struct {
 union {int m20;struct {short unk20;short m22;};};
 union {int m24;struct {short unk24;short m26;};};
 union {int m28;struct {short unk28;short m2a;};};
 int unk2c;
 };};
 union {CodeData* data;void* m30;};
 union {int primitiveMask;int m34;};
 void Execute(const QueryState*,unsigned char*,int);
 __forceinline void AddHit(int value) {
  HitArray* out=hits;AllocatorContext* context=hkMemoryRouter_getInstance();
  if(out->size==(out->capacity&0x3fffffff)) ResizeAudioStream(context->allocator,out,4);
  int* destination=&reinterpret_cast<int*>(out->data)[out->size]; ++out->size; *destination=value; }
};

#ifndef _INCLUDED_MM2
// Exe 0x00dd1bf0 FUN_00dd1bf0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

extern "C" {
LocalM128 _mm_load_ss(const float*);
LocalM128 _mm_set_ss(float);
LocalM128 _mm_add_ps(LocalM128, LocalM128);
LocalM128 _mm_sub_ps(LocalM128, LocalM128);
LocalM128 _mm_mul_ps(LocalM128, LocalM128);
LocalM128 _mm_and_ps(LocalM128, LocalM128);
LocalM128 _mm_xor_ps(LocalM128, LocalM128);
LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
LocalM128 _mm_set_ps1(float);
}

#endif

extern "C" LocalM128 DAT_01017d10;
extern "C" LocalM128 DAT_010c44d0;

namespace ObbQueryDetail {
struct LowScalar { LocalM128 low; __forceinline LowScalar(float v):low(_mm_load_ss(&v)) {} __forceinline LocalM128 broadcast() const { return _mm_shuffle_ps(low,low,0); } };

struct ObbVector {

    __forceinline void add(const ObbVector& b) { m_vComponents=_mm_add_ps(m_vComponents,b.m_vComponents); }
    __forceinline void setAdd(const ObbVector& a,const ObbVector& b) { m_vComponents=_mm_add_ps(a.m_vComponents,b.m_vComponents); }
    __forceinline void setSub(const ObbVector& a,const ObbVector& b) { m_vComponents=_mm_sub_ps(a.m_vComponents,b.m_vComponents); }
    __forceinline void neg(const ObbVector& a) { m_vComponents=_mm_xor_ps(a.m_vComponents,DAT_010c44d0); }
    __forceinline void abs() { m_vComponents=_mm_and_ps(m_vComponents,DAT_01017d10); }
    __forceinline void times(const ObbVector& b) { m_vComponents=_mm_mul_ps(m_vComponents,b.m_vComponents); }
    __forceinline void scaleBy(const LowScalar& f) { m_vComponents=_mm_mul_ps(f.broadcast(),m_vComponents); }
    template<int i> __forceinline void splat(const ObbVector& a) { m_vComponents=_mm_shuffle_ps(a.m_vComponents,a.m_vComponents,i); }
    __forceinline void setFloat(float f) { m_vComponents=_mm_set_ps1(f); }
    LocalM128 m_vComponents;
    __forceinline float getComponent(int i) const { return m_vComponents.m128_f32[i]; }
};

struct ObbTransform {
    ObbVector m_kColumn0;
    ObbVector m_kColumn1;
    ObbVector m_kColumn2;
    ObbVector m_vTranslation;
};

struct ObbProgram {
    unsigned char m_type;
};

struct ObbCodeView {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ObbVector m_offset;   // w = scale
    const ObbProgram* m_pCollisionShape;
    __forceinline float getScale() const { return m_offset.m_vComponents.m128_f32[3]; }
};


struct ObbMachine : GridCell {
    void hkpMoppObbVirtualMachine_queryObb(const ObbCodeView* src, const ObbTransform* t, const ObbVector* halfExtents, float radius, unsigned int key);
};

// @fnv 0x00dd1bf0
// src: XBOX_PDB 0x00dd1bf0
void ObbMachine::hkpMoppObbVirtualMachine_queryObb(const ObbCodeView* src, const ObbTransform* t, const ObbVector* halfExtents, float radius, unsigned int key)
{
    m00 = key;
    m30 = (void*)src;

    float scale = src->getScale();

    ObbVector x,y,z,extra,center,hi,lo;
    x.splat<0>(*halfExtents); y.splat<0x55>(*halfExtents); z.splat<0xaa>(*halfExtents);
    x.times(t->m_kColumn0); y.times(t->m_kColumn1); z.times(t->m_kColumn2);
    x.abs(); y.abs(); z.abs();
    hi.setAdd(y,x); hi.add(z);
    extra.setFloat(radius); hi.add(extra);
    lo.neg(hi);
    center.setSub(t->m_vTranslation,src->m_offset);
    hi.add(center);
    lo.add(center);
    LowScalar factor(scale);
    hi.scaleBy(factor);
    lo.scaleBy(factor);

    m20 = fnv_FloatToInt(lo.getComponent(0)) - 1;
    m10 = fnv_FloatToInt(hi.getComponent(0)) + 1;
    m24 = fnv_FloatToInt(lo.getComponent(1)) - 1;
    m14 = fnv_FloatToInt(hi.getComponent(1)) + 1;
    m28 = fnv_FloatToInt(lo.getComponent(2)) - 1;
    m18 = fnv_FloatToInt(hi.getComponent(2)) + 1;

    GridScratch box;
    box.f10 = m20 >> 16;
    box.f00 = (m10 >> 16) + 1;
    box.f14 = m24 >> 16;
    box.f04 = (m14 >> 16) + 1;
    box.f18 = m28 >> 16;
    box.f08 = (m18 >> 16) + 1;
    box.f20 = 0;
    box.f24 = 0;
    box.f28 = 0;
    box.f2c = 0;
    box.f30 = 0;
    box.f34 = 0;

    const ObbProgram* shape = ((const ObbCodeView*)m30)->m_pCollisionShape;
    m34 = (shape->m_type == 13) ? -1 : 0;
    Execute(&box, (unsigned char*)shape, 0);
}

}
