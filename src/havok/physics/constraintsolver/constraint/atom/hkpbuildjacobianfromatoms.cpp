#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
// Preserve this unit's original intrinsic union: RTM changes x87 load ordering
// when the additional union views from xmmintrin.h are introduced.
// Exe-matched intrinsic packet; __m128 remains an ABI compatibility alias.
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#define _INCLUDED_MM2
#define FNV_FOURFLOATVECTOR_NO_SSE

#include "../../../../../../include/V4.h"
// local form of hkVector4: 0x00d6d450 needs its original packet form (compiled function extent differs: 469 vs 372).


#if !defined(FNV_FOURFLOATVECTOR_NO_SSE)
#include <xmmintrin.h>
#else
#endif

class SimdReal;
class SimdScalar;
class ScalarValue;
class Transform;
class NiPoint3;

#pragma pack(push, 4)

class PacketCallLocal_00d6d450
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

    PacketCallLocal_00d6d450();
    PacketCallLocal_00d6d450(float x, float y, float z, float w);
    PacketCallLocal_00d6d450(const __m128& vector);

    PacketCallLocal_00d6d450* hkVector4_hkVector4(float x, float y, float z, float w);
    void SetValue(PacketCallLocal_00d6d450* vector);
    void __thiscall SetQuaternionComponentsFromVector(const PacketCallLocal_00d6d450* vector);
    PacketCallLocal_00d6d450& ComputeValue_00e531a0(int parameter);
    PacketCallLocal_00d6d450 ProcessAndReturnValue_00e53260(int parameter);
    void normalize_005611c0();

    void operator=(const PacketCallLocal_00d6d450& vector);
    float& operator()(int index);
    const float& operator()(int index) const;
    float& component(int index);
    float& At(int index);
    const float& At(int index) const;

    __m128 length3() const;
    float getW() const;
    ScalarValue Dot(const PacketCallLocal_00d6d450& vector) const;
    ScalarValue LengthSq() const;
    ScalarValue Length() const;
    ScalarValue InverseLength() const;
    void Normalize();
    bool NormalizeNonzero();
    void Mul(const ScalarValue& scalar);
    void Add(const PacketCallLocal_00d6d450& vector);
    void Sub(const PacketCallLocal_00d6d450& vector);
    void Cross(const PacketCallLocal_00d6d450& a, const PacketCallLocal_00d6d450& b);

    void setAbs4(const PacketCallLocal_00d6d450& vector);
    void setMul4(const SimdReal& scalar, const PacketCallLocal_00d6d450& vector);
    void addMul4(const SimdReal& scalar, const PacketCallLocal_00d6d450& vector);
    void setAddMul4(const PacketCallLocal_00d6d450& a, const PacketCallLocal_00d6d450& b, const SimdReal& scalar);
    SimdReal getSimdAt3() const;
    SimdReal lengthSquared3() const;
    void setXYZ_W(__m128 xyz, __m128 w);
    void setSqrtInverse4(const PacketCallLocal_00d6d450& vector);
    void setAddMul(const PacketCallLocal_00d6d450& a, const PacketCallLocal_00d6d450& b, const SimdScalar& scalar);
    void addMul(const float& scalar, const PacketCallLocal_00d6d450& vector);
    void transformed(const Transform& transform, const PacketCallLocal_00d6d450& vector);
    void addScaled(const PacketCallLocal_00d6d450& base, const PacketCallLocal_00d6d450& direction, float amount);
    void* AddVector(void*, NiPoint3*, void*, float);
    void* AddVector(void*, void*);
    void* ScaleSwizzled();
};

#pragma pack(pop)

#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkMatrix3.h"
#include "../../../../../../include/hkRotation.h"
#include "../../../../../../include/hkpTwistLimitConstraintAtom.h"

__forceinline V4::V4() {}
__forceinline PacketCallLocal_00d6d450::PacketCallLocal_00d6d450() {}

// src/havok/physics/constraintsolver/constraint/atom/hkpbuildjacobianfromatoms.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/constraint/atom/hkpbuildjacobianfromatoms.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// The .rdata double added to the first matrix element (0.25) lives in the
// original image, so it is only declared here.
extern const double DAT_010c9300;

// arg1: the six float vector
struct FUN_00d6ce70_Vector
{
    float f00;
    float f04;
    float f08;
    float f0c;
    float f10;
    float f14;
};

// arg2: the scale struct, the two floats at +4 and +8 are read
struct FUN_00d6ce70_Scale
{
    float unk00;
    float f04;
    float f08;
};

// arg3: the destination struct, the product is stored at +0x1c
struct FUN_00d6ce70_Dest
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float f1c;
};

// the 0x40 byte matrix block the cursor walks over
struct FUN_00d6ce70_Matrix
{
    float m00;
    float m01;
    float m02;
    float m03;
    float m10;
    float m11;
    float m12;
    float m13;
    float m20;
    float m21;
    float m22;
    float m23;
    float m30;
    float m31;
    float m32;
    float m33;
};

// arg4: the cursor pointing at the next matrix block
struct FUN_00d6ce70_Cursor
{
    FUN_00d6ce70_Matrix* matrix;
};

// @fnv 0x00d6ce70
// src: GUESS 0x00d6ce70 (confidence: low)
void Hkpbuildjacobianfromatoms_UpdateState_00d6ce70(FUN_00d6ce70_Vector* v, FUN_00d6ce70_Scale* s, FUN_00d6ce70_Dest* dest, FUN_00d6ce70_Cursor* cursor)
{
    dest->f1c = s->f08 * v->f00;

    FUN_00d6ce70_Matrix* m = cursor->matrix;
    m->m00 = (float)((double)m->m00 + DAT_010c9300);
    *((unsigned char*)&m->m00) = 15;

    m = m + 1;
    cursor->matrix = m;

    (m - 1)->m20 = v->f08 * s->f04;
    (m - 1)->m21 = v->f0c * s->f04;
    (m - 1)->m22 = v->f04;
    (m - 1)->m23 = v->f10;
    (m - 1)->m30 = v->f14;
}

namespace fnv_00d6f2b0 {
extern "C" double DAT_010c9300;
struct EventRecord
{
    union
    {
        float accumulator;
        struct
        {
            unsigned char opcode;
            unsigned char option;
            unsigned short other;
        };
    };
    unsigned short context6c;
    unsigned short context70;
    unsigned int inputBits;
    unsigned int valueBits;
};
struct RecordSource
{
    volatile int& f60() const
    {
        return *reinterpret_cast<volatile int*>(reinterpret_cast<char*>(const_cast<RecordSource*>(this)) + 0x60);
    }
    volatile int& f6c() const
    {
        return *reinterpret_cast<volatile int*>(reinterpret_cast<char*>(const_cast<RecordSource*>(this)) + 0x6c);
    }
    volatile int& f70() const
    {
        return *reinterpret_cast<volatile int*>(reinterpret_cast<char*>(const_cast<RecordSource*>(this)) + 0x70);
    }
};
// Advances *dest past a new EventRecord filled from source fields, inputBits and option, with accumulator incremented by DAT_010c9300.
// @fnv 0x00d6f2b0
void __cdecl AppendEventRecord(const RecordSource* source, EventRecord** dest, volatile unsigned int inputBits,
                               volatile unsigned char option)
{
    volatile EventRecord* record = *dest;
    double next = record->accumulator + DAT_010c9300;
    int n70 = source->f70();
    int iField6c = source->f6c();
    int n60 = source->f60();
    record->accumulator = (float)next;
    record->context70 = (unsigned short)n70;
    unsigned int uiInputBits = inputBits;
    record->valueBits = (unsigned int)n60;
    unsigned char ucOption = option;
    record->context6c = (unsigned short)iField6c;
    record->inputBits = uiInputBits;
    record->opcode = 1;
    record->option = ucOption;
    *dest = const_cast<EventRecord*>(record + 1);
}
}  // namespace fnv_00d6f2b0

struct WriterContext
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
};
struct WriterArgs
{
    unsigned int value_bits;
    unsigned char flag;
};
struct WriterRecord
{
    unsigned char type;
    unsigned char flag;
    unsigned short unk02;
    unsigned short low;
    unsigned short high;
    unsigned int value;
    unsigned int whole;
};
extern double _DAT_010c9300;
// Advances the cursor past a written record, filling its type, flag, value, whole, low and high fields and adding a constant to the float at the cursor.
// @fnv 0x00d6f270
static void __declspec(noinline) WriteFloatRecord(WriterContext* pContext, float** cursor, WriterArgs args)
{
    float* record = *cursor;
    float old = *record;
    int high = pContext->unk70;
    old += _DAT_010c9300;
    int low = pContext->unk6c;
    int whole = pContext->unk60;
    *record = old;
    WriterRecord* out = (WriterRecord*)record;
    out->high = (unsigned short)high;
    unsigned int value = args.value_bits;
    out->whole = (unsigned int)whole;
    unsigned char flag = args.flag;
    out->low = (unsigned short)low;
    out->value = value;
    out->type = 1;
    out->flag = flag;
    *cursor = (float*)(out + 1);
}
void RecordWrite_use(WriterContext* object, float** cursor, WriterArgs args)
{
    WriteFloatRecord(object, cursor, args);
}

struct S00d6d990_Src
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char m02;
    unsigned char m03;
    unsigned char m04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    float m08;
};

struct S00d6d990_Tmp
{
    int key;
    int ctx;
    float f;
    unsigned int val;
};

struct S00d6d990_Rec
{
    unsigned char type;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char flag;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    float unk08;
    float unk0c;
};

void S00d6d990_Sink(S00d6d990_Tmp* t, WriterContext* obj, S00d6d990_Rec** cur);

// Writes a float record to the writer context, either via S00d6d990_Sink when m02 and m08 are set, or by appending a record with type 3 and an adjusted value.
// @fnv 0x00d6d990
// src: GUESS 0x00d6d990 (confidence: medium)
static __declspec(noinline) void Hkpbuildjacobianfromatoms_WriteFloatSolverRecord(S00d6d990_Src* src, S00d6d990_Rec** cur, WriterContext* obj, int a1)
{
    if (src->m02 != 0 && src->m08 != 0.0f)
    {
        S00d6d990_Tmp t;
        t.key = (src->m03 << 4) + a1;
        t.f = src->m08;
        t.val = src->m04;
        t.ctx = obj->unk64;
        S00d6d990_Sink(&t, obj, cur);
        return;
    }
    S00d6d990_Rec* p = *cur;
    float v = *(float*)p;
    double r = v + DAT_010c9300;
    p->flag = src->m04;
    *(float*)p = (float)r;
    p->type = 3;
    *cur = p + 1;
}

void S00d6d990_Caller(S00d6d990_Src* s, S00d6d990_Rec** c, WriterContext* o, int a)
{
    Hkpbuildjacobianfromatoms_WriteFloatSolverRecord(s, c, o, a);
}

extern double _DAT_010c9300;
// Writes a WriterRecord with type 1, storing whole, high, low, value, and flag fields, then advances the cursor past the record.
// @fnv 0x00d6ea30
// src: GUESS 0x00d6ea30 (confidence: medium)
static void __declspec(noinline) Hkpbuildjacobianfromatoms_WriteTypeOneRecordAndAdvance(WriterContext* apWriter, float** cursor, WriterArgs args)
{
    float* record = *cursor;
    float old = *record;
    int high = apWriter->unk70;
    old += _DAT_010c9300;
    int low = apWriter->unk6c;
    int whole = apWriter->unk60;
    *record = old;
    WriterRecord* out = (WriterRecord*)record;
    out->high = (unsigned short)high;
    unsigned int value = args.value_bits;
    out->whole = (unsigned int)whole;
    unsigned char flag = args.flag;
    out->low = (unsigned short)low;
    out->value = value;
    out->type = 1;
    out->flag = flag;
    *cursor = (float*)(out + 1);
}
void RecordWriteAlt_use(WriterContext* object, float** cursor, WriterArgs args)
{
    Hkpbuildjacobianfromatoms_WriteTypeOneRecordAndAdvance(object, cursor, args);
}

struct Ea70Src
{
    float f00;
    float f04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    float f24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    float f40;
    float f44;
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
};

struct Ea70Obj
{
    unsigned short type;
    unsigned short unk02;
    unsigned short count;
    unsigned short stride;
    unsigned short unk08;
    unsigned char recStride;
    unsigned char unk0b;
    unsigned short unk0c;
    unsigned short unk0e;
    unsigned short unk10;
    unsigned short u12;
    Ea70Obj* next;
    unsigned int unk18;
    unsigned int unk1c;
    float f20;
    float f24;

    const float* vert(int i) const
    {
        return (const float*)((const char*)this + 0x4c + i * 32);
    }
};

struct Ea70Flag
{
    unsigned char v;
};

void hkSimpleContactConstraintDataBuildJacobian(Ea70Obj* a, Ea70Src* b, Ea70Flag c, int* d);
void hkSolverBuildJacobianFromAtomsNotContact(Ea70Obj* a, int b, Ea70Src* c, int* d);

static inline void Ea70Step(const float* x, float* y, const Ea70Obj* self, const Ea70Src* src, float& a)
{
    a = *x;
    float v = self->f24 * src->f04 * src->f00 / self->f20;
    if (v + a < *y)
        *y = v + a;
}

// @fnv 0x00d6ea70
// src: GUESS 0x00d6ea70 (confidence: low)
static __declspec(noinline) void hkSimpleContactConstraintDataBuildJacobian_ProcessEntries_00d6ea70(Ea70Src* src, Ea70Obj* self, int* alloc)
{
    float a;
    *alloc -= 16;
    __declspec(align(16)) Ea70Src L = *src;
    float scale = self->f20;
    unsigned int w12 = self->u12;
    L.f24 = src->f24 * scale;
    L.f40 = src->f40 * scale;
    L.f44 = scale * src->f44;

    Ea70Obj* node = self;
    do
        node = node->next;
    while (node->type >= 0x17);
    char* rec = (char*)node + 0x30 + (node->stride << 5);
    int count;
    count = node->count;
    long recStride = node->recStride;

    for (int m = 0; m < count; m++)
    {
        Ea70Step(node->vert(m), (float*)(rec + 0x10), self, src, a);
        rec += recStride;
    }
    Ea70Obj* next = self->next;
    if (next->type == 0x16)
    {
        Ea70Flag flag;
        flag.v = 1;
        hkSimpleContactConstraintDataBuildJacobian(next, &L, flag, alloc);
    }
    else
    {
        hkSolverBuildJacobianFromAtomsNotContact(next, w12, &L, alloc);
    }
}

void Ea70_caller(Ea70Src* s, Ea70Obj* o, int* a)
{
    hkSimpleContactConstraintDataBuildJacobian_ProcessEntries_00d6ea70(s, o, a);
}

extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ss(const float* p);
extern "C" void _mm_store_ps(float* p, __m128 a);

struct S6edf0_Vec
{
    __m128 m_vComponents;
    void add4(const S6edf0_Vec& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
};

struct S6edf0_Quat
{
    S6edf0_Vec v;
    void hkVector4_setRotatedDir(unsigned int a, const S6edf0_Vec* b);
    void hkVector4_setMul3(const hkMatrix3* a, S6edf0_Vec* b);
};

struct S6edf0_Motion
{
    S6edf0_Vec m00;
    S6edf0_Vec m10;
    S6edf0_Vec m20;
    S6edf0_Vec m30;
    S6edf0_Vec m40;
    hkMatrix3 m50;
    void CopySelectedFields(unsigned int a);
};

struct S6edf0_Blob
{
    unsigned int u00;
    unsigned int u04;
    unsigned int u08;
    unsigned int u0c;
    unsigned int u10;
    unsigned int u14;
    unsigned int u18;
    unsigned int u1c;
    unsigned int u20;
    unsigned int u24;
    unsigned int u28;
    unsigned int u2c;
    unsigned int u30;
    unsigned int u34;
    unsigned int u38;
    unsigned int u3c;
    unsigned int u40;
    unsigned int u44;
    unsigned int u48;
    unsigned int u4c;
    unsigned int u50;
    unsigned int u54;
    unsigned int u58;
    unsigned int u5c;
    unsigned int u60;
    unsigned int u64;
    unsigned int u68;
    unsigned int u6c;
    unsigned int u70;
    unsigned int u74;
    unsigned int u78;
    unsigned int u7c;
};

struct S6edf0_Ctx
{
    int u00;
    int u04;
    int u08;
    int u0c;
    unsigned short m10;
    unsigned short m12;
    unsigned short* m14;
    int u18;
    int u1c;
    S6edf0_Vec m20;
    S6edf0_Vec m30;
};

extern const float DAT_01012054;

struct S6edf0_Frames
{
    hkMatrix3 rb;
    S6edf0_Quat qb;
    S6edf0_Quat qa;
    hkMatrix3 ra;
};

struct S6edf0_Frames2
{
    hkMatrix3 ga;
    S6edf0_Quat ib;
    hkMatrix3 gb;
    S6edf0_Quat ia;
};

union S6edf0_Tag
{
    unsigned int i;
    unsigned char b;
};

void WriteVector(hkMatrix3* a, hkMatrix3* b, unsigned int c);
void hkSimpleContactConstraintDataBuildJacobian(unsigned short* p, S6edf0_Blob* b, S6edf0_Tag t, unsigned int c);
void hkSolverBuildJacobianFromAtomsNotContact(unsigned short* p, S6edf0_Tag t, S6edf0_Blob* b, unsigned int c);

// Builds motion data from src and ctx, then calls FUN_00d72190 if *ctx->m14 is 0x16 or FUN_00d6f460 otherwise, bracketed by two WriteVector calls.
// @fnv 0x00d6edf0
// src: GUESS 0x00d6edf0 (confidence: low)
void hkMatrix3_UpdateState_00d6edf0(S6edf0_Ctx* ctx, S6edf0_Blob* src, unsigned int arg3)
{
    S6edf0_Tag tag;
    __declspec(align(16)) PacketCallLocal_00d6d450 neg;
    S6edf0_Frames frames;
    hkMatrix3 tmp;
    S6edf0_Frames2 gr;
    S6edf0_Motion ma;
    S6edf0_Motion mb;
    S6edf0_Blob blob;
    blob = *src;
    tag.i = ctx->m12;
    unsigned short* p = ctx->m14;

    frames.qa.hkVector4_setRotatedDir(src->u38, &ctx->m20);
    frames.qb.hkVector4_setRotatedDir(src->u3c, &ctx->m30);
    ma.CopySelectedFields(src->u30);
    mb.CopySelectedFields(src->u34);

    ma.m40.add4(frames.qa.v);
    mb.m40.add4(frames.qb.v);
    blob.u30 = (unsigned int)&ma;
    blob.u34 = (unsigned int)&mb;

    frames.ra.SetDiagonalElements(reinterpret_cast<const hkVector4&>(frames.qa.v));
    frames.rb.SetDiagonalElements(reinterpret_cast<const hkVector4&>(frames.qb.v));

    tmp.m_kColumn0.m_vComponents = frames.ra.m_kColumn0.m_vComponents;
    tmp.m_kColumn1.m_vComponents = frames.ra.m_kColumn1.m_vComponents;
    tmp.m_kColumn2.m_vComponents = frames.ra.m_kColumn2.m_vComponents;
    frames.ra._setMul(tmp, ma.m50);
    tmp.m_kColumn0.m_vComponents = frames.rb.m_kColumn0.m_vComponents;
    tmp.m_kColumn1.m_vComponents = frames.rb.m_kColumn1.m_vComponents;
    tmp.m_kColumn2.m_vComponents = frames.rb.m_kColumn2.m_vComponents;
    frames.rb._setMul(tmp, mb.m50);

    gr.ga.m_kColumn0.m_vComponents = frames.ra.m_kColumn0.m_vComponents;
    gr.ga.m_kColumn1.m_vComponents = frames.ra.m_kColumn1.m_vComponents;
    gr.ga.m_kColumn2.m_vComponents = frames.ra.m_kColumn2.m_vComponents;
    _mm_store_ps(&neg.x, _mm_load_ss(&DAT_01012054));
    gr.ga.Multiply(reinterpret_cast<const hkSimdReal&>(neg));
    gr.gb.m_kColumn0.m_vComponents = frames.rb.m_kColumn0.m_vComponents;
    gr.gb.m_kColumn1.m_vComponents = frames.rb.m_kColumn1.m_vComponents;
    gr.gb.m_kColumn2.m_vComponents = frames.rb.m_kColumn2.m_vComponents;
    _mm_store_ps(&neg.x, _mm_load_ss(&DAT_01012054));
    gr.gb.Multiply(reinterpret_cast<const hkSimdReal&>(neg));

    gr.ia.hkVector4_setMul3(&gr.ga, &ma.m20);
    gr.ib.hkVector4_setMul3(&gr.gb, &mb.m20);
    ma.m10.add4(gr.ia.v);
    mb.m10.add4(gr.ib.v);

    WriteVector(&gr.ga, &gr.gb, arg3);
    if (*p == 0x16)
    {
        tag.b = 1;
        hkSimpleContactConstraintDataBuildJacobian(p, &blob, tag, arg3);
    }
    else
    {
        hkSolverBuildJacobianFromAtomsNotContact(p, tag, &blob, arg3);
    }
    WriteVector(&frames.ra, &frames.rb, arg3);
}

__declspec(align(16)) struct FUN_00d71f90_cls
{
    unsigned char m_b00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned int m_i04;
    float m_f08;
    unsigned int unk0C;
    unsigned int m_i10;
    unsigned int m_i14;
    unsigned int m_i18;
    unsigned int m_i1C;
    unsigned int m_i20;
    unsigned int m_i24;
    unsigned int m_i28;
    unsigned int m_i2C;
    unsigned int m_i30;
    unsigned int m_i34;
    unsigned int m_i38;
    unsigned int m_i3C;
    unsigned int m_i40;
    unsigned int m_i44;
    unsigned int m_i48;
    unsigned int m_i4C;
    __m128 m_v50;
    __m128 m_v60;
    __m128 m_v70;

    FUN_00d71f90_cls* CopySelectedFields(const FUN_00d71f90_cls* src);
};

// Copies the named fields (not unk01 to unk03 or unk0C) from src into this and returns this.
// @fnv 0x00d71f90
// src: GUESS 0x00d71f90 (confidence: medium)
FUN_00d71f90_cls* FUN_00d71f90_cls::CopySelectedFields(const FUN_00d71f90_cls* src)
{
    FUN_00d71f90_cls* dst = this;
    dst->m_b00 = src->m_b00;
    dst->m_i04 = src->m_i04;
    dst->m_f08 = src->m_f08;
    dst->m_i10 = src->m_i10;
    dst->m_i14 = src->m_i14;
    dst->m_i18 = src->m_i18;
    dst->m_i1C = src->m_i1C;
    dst->m_i20 = src->m_i20;
    dst->m_i24 = src->m_i24;
    dst->m_i28 = src->m_i28;
    dst->m_i2C = src->m_i2C;
    dst->m_i30 = src->m_i30;
    dst->m_i34 = src->m_i34;
    dst->m_i38 = src->m_i38;
    dst->m_i3C = src->m_i3C;
    dst->m_i40 = src->m_i40;
    dst->m_i44 = src->m_i44;
    dst->m_i48 = src->m_i48;
    dst->m_i4C = src->m_i4C;
    dst->m_v50 = src->m_v50;
    dst->m_v60 = src->m_v60;
    dst->m_v70 = src->m_v70;
    return this;
}

namespace fnv_00dced90 {
extern "C" void _ReadWriteBarrier(void);
extern double DAT_010c9300;

// Copies *a and *b into two 16-byte slots at *out, adds DAT_010c9300 to the first float, sets the first byte to 0x19, and advances *out by 0x20.
// @fnv 0x00dced90
// src: GUESS 0x00dced90 (confidence: medium)
void __cdecl Hkpbuildjacobianfromatoms_WriteVectorPairRecordAndAdvance(const __m128* a, const __m128* b, char** ppCursor)
{
    char* p = *ppCursor;
    _ReadWriteBarrier();
    *(__m128*)p = *a;
    double first = (double)*(float*)p;
    __m128 vb = *b;
    _ReadWriteBarrier();
    double biased = first + DAT_010c9300;
    *(__m128*)(p + 0x10) = vb;
    p += 0x20;
    *(float*)(p - 0x20) = (float)biased;
    (p - 0x20)[0] = 0x19;
    *ppCursor = p;
}
}  // namespace fnv_00dced90

struct FUN_00dcedd0_Fields
{
    float x, y, z, w;
};
struct __declspec(align(16)) FUN_00dcedd0_Record
{
    union
    {
        __m128 value;
        FUN_00dcedd0_Fields fields;
        unsigned char type;
    };
    void* object;
};
// Stores value, object, and type 0x1a into the record at cursor, adds a small epsilon to x, and advances cursor.
// @fnv 0x00dcedd0
// src: GUESS 0x00dcedd0 (confidence: high)
void __cdecl Hkpbuildjacobianfromatoms_WriteType1ARecordAndAdvance(const __m128* value, void* object, FUN_00dcedd0_Record** cursor)
{
    FUN_00dcedd0_Record* record = *cursor;
    record->value = *value;
    record->fields.x += 1.1920928955078125e-7;
    record->object = object;
    record->type = 0x1a;
    *cursor = record + 1;
}

struct Aux
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char idx;
    unsigned char unk03;
    float unk04;
    float unk08;
};

struct Self
{
    __m128 grid[16];
};

struct Buf
{
    float g0[4];
    float g1[4];
    float g2[4];
    float f30;
    float f34;
};

extern "C" void __cdecl ComputeAngularJacobian(void* out, unsigned int a1, unsigned int a3);
extern "C" Aux* stub_aux(void);
extern "C" Self* stub_self(void);
extern "C" unsigned int stub_a1(void);
extern "C" Self* stub_p30(void);
extern "C" unsigned int stub_a3(void);

// Stores p30->grid[3], self->grid[3], self->grid[aux->idx] and aux's two floats in a local buffer, then calls ComputeAngularJacobian with a1 and a3.
// @fnv 0x00d6d220
// src: GUESS 0x00d6d220 (confidence: low)
static __declspec(noinline) void Object_UpdateFields_00d6d220(Aux* aux, Self* self, unsigned int a1, const Self* p30, unsigned int a3)
{
    __declspec(align(16)) Buf b;
    _mm_store_ps(b.g0, p30->grid[3]);
    _mm_store_ps(b.g1, self->grid[3]);
    _mm_store_ps(b.g2, self->grid[aux->idx]);
    b.f30 = aux->unk04;
    b.f34 = aux->unk08;
    ComputeAngularJacobian(&b, a1, a3);
}

void stub_caller(void)
{
    Object_UpdateFields_00d6d220(stub_aux(), stub_self(), stub_a1(), stub_p30(), stub_a3());
}

extern "C" void __cdecl hk1dLinearLimitBuildJacobian(void* out, unsigned int a1, unsigned int a3);

struct F4
{
    float x, y, z, w;
};

// Builds a local buffer of three vectors and two floats from b, d and a2, then calls FUN_00dcfa30 with it, a1 and a3.
// @fnv 0x00d6d280
// src: GUESS 0x00d6d280 (confidence: low)
static __declspec(noinline) void Object_UpdateFields_00d6d280(char* b, char* d, unsigned int a1, char* a2, unsigned int a3)
{
    __declspec(align(16)) struct Buf
    {
        F4 m_v0;
        F4 m_v1;
        F4 m_v2;
        float m_f3;
        float m_f4;
    } buf;

    buf.m_f3 = *(float*)(d + 4);
    _mm_store_ps(&buf.m_v0.x, *(const __m128*)((const char*)a2 + 0x30));
    buf.m_f4 = *(float*)(d + 8);
    _mm_store_ps(&buf.m_v1.x, *(const __m128*)((const char*)b + 0x30));
    _mm_store_ps(&buf.m_v2.x, *(const __m128*)(b + ((unsigned int)(unsigned char)d[2] << 4)));

    hk1dLinearLimitBuildJacobian((void*)&buf, a1, a3);
}

void S00d6d280_Entry(char* d, char* b, unsigned int a1, char* a2, unsigned int a3)
{
    Object_UpdateFields_00d6d280(b, d, a1, a2, a3);
}

extern "C" void _ReadWriteBarrier(void);

// Copies six __m128 values from first and second into *output, adds DAT_010c9300 to the first float, sets the first byte to 0x1b, and advances *output by 6.
// @fnv 0x00dcee10
void __cdecl WriteVector(__m128* first, __m128* second, __m128** output)
{
    __m128* destination = *output;
    destination[0] = first[0];
    destination[1] = first[1];
    destination[2] = first[2];
    destination[3] = second[0];
    destination[4] = second[1];
    destination[5] = second[2];
    _ReadWriteBarrier();
    reinterpret_cast<float*>(destination)[0] += DAT_010c9300;
    reinterpret_cast<unsigned char*>(destination)[0] = 0x1b;
    *output = destination + 6;
}

extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" void _mm_store_ss(float*, __m128);

extern __m128 DAT_01268370[3];

struct ConstraintMotion
{
    __m128 m00;
    __m128 m10;
    __m128 m20;
    __m128 m30;
    __m128 m40;
    __m128 m50;
    __m128 m60;
    __m128 m70;
};

union MathVec
{
    __m128 q;
    void mul(const MathVec& other)
    {
        q = _mm_mul_ps(q, other.q);
    }
    void add(const MathVec& other)
    {
        q = _mm_add_ps(q, other.q);
    }
};

static inline void VectorCross(__m128& result, const __m128& lhs, const __m128& rhs)
{
    __m128 first = _mm_mul_ps(_mm_shuffle_ps(lhs, lhs, 0xc9), _mm_shuffle_ps(rhs, rhs, 0xd2));
    __m128 second = _mm_mul_ps(_mm_shuffle_ps(lhs, lhs, 0xd2), _mm_shuffle_ps(rhs, rhs, 0xc9));
    result = _mm_sub_ps(first, second);
}

static inline float Diagonal(const __m128& argA, __m128 argB, __m128 massA, const __m128& massB)
{
    const __m128& r0 = argA;
    const __m128& d30 = massB;
    const __m128& c30 = massA;
    __m128 aa = _mm_mul_ps(r0, r0);
    __m128 bb = _mm_mul_ps(argB, argB);
    aa = _mm_mul_ps(aa, c30);
    bb = _mm_mul_ps(bb, d30);
    __m128 S = _mm_add_ps(bb, aa);
    __m128 Cs = _mm_add_ps(c30, d30);
    __m128 u = _mm_unpackhi_ps(S, Cs);
    __m128 w = _mm_shuffle_ps(S, u, 0xc4);
    __m128 w2 = _mm_shuffle_ps(w, w, 0x4e);
    __m128 rr = _mm_add_ps(w2, w);
    __m128 h = _mm_add_ps(_mm_shuffle_ps(rr, rr, 0xb1), rr);
    float L;
    _mm_store_ss(&L, h);
    return L;
}
struct SegCtx
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    float m_f20;
    float m_f24;
    unsigned int unk28;
    unsigned int unk2c;
    ConstraintMotion* m_p30;
    ConstraintMotion* m_p34;
};

struct PivotPair
{
    const __m128* m_kPointA;
    const __m128* m_kPointB;
    const __m128& A() const
    {
        return *m_kPointA;
    }
    const __m128& B() const
    {
        return *m_kPointB;
    }
};

struct ConstraintEntry
{
    __m128 m_dir;
    __m128 m_angA;
    __m128 m_angB;
};

// Fills three ConstraintEntry slots in out from pivot pair pv and segment context c, computing cross terms, diagonal mass, and dot products.
// @fnv 0x00d6c970
// src: GUESS 0x00d6c970 (confidence: medium)
void __cdecl Hkpbuildjacobianfromatoms_BuildThreeConstraintRows(PivotPair pv, SegCtx* apSegCtx, __m128* out)
{
    ConstraintMotion* pMotionA = apSegCtx->m_p30;
    ConstraintMotion* pMotionB = apSegCtx->m_p34;
    const __m128* tp = DAT_01268370;
    __m128* pEntry = out + 1;
    double K = DAT_010c9300;
    int n = 3;
    do
    {
        float fp = apSegCtx->m_f24;
        float fq = apSegCtx->m_f20;
        pEntry[-1] = *tp;

        __m128 P = _mm_sub_ps(pv.A(), pMotionA->m40);
        __m128 Q = _mm_sub_ps(pv.B(), pMotionB->m40);

        __m128 T = *tp;
        __m128 X, Y;
        VectorCross(X, P, T);
        VectorCross(Y, T, Q);

        __m128 c50 = pMotionA->m50;
        __m128 c60 = pMotionA->m60;
        __m128 c70 = pMotionA->m70;
        __m128 o0 = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(X, X, 0), c50), _mm_mul_ps(_mm_shuffle_ps(X, X, 0x55), c60)),
            _mm_mul_ps(_mm_shuffle_ps(X, X, 0xaa), c70));
        pEntry[0] = o0;

        __m128 d50 = pMotionB->m50;
        __m128 d60 = _mm_load_ps(pMotionB->m60.m128_f32);
        __m128 d70 = pMotionB->m70;
        __m128 o1 = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(Y, Y, 0x55), d60), _mm_mul_ps(_mm_shuffle_ps(Y, Y, 0), d50)),
            _mm_mul_ps(_mm_shuffle_ps(Y, Y, 0xaa), d70));
        pEntry[1] = o1;

        __m128 mass_a = pMotionA->m30;
        __m128 mass_b = pMotionB->m30;
        float L = Diagonal(pEntry[0], o1, mass_a, mass_b);
        float M = (float)((double)L + K);

        pEntry[1].m128_f32[3] = M;
        pEntry[0].m128_f32[3] = fp / M;

        __m128 BA = _mm_sub_ps(pv.B(), pv.A());
        __m128 prod = _mm_mul_ps(BA, *tp);
        __m128 dx = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod);
        __m128 dz = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), dx);
        float D;
        _mm_store_ss(&D, dz);
        pEntry[-1].m128_f32[3] = D * fq;

        tp++;
        pEntry += 3;
    } while (--n != 0);
}

extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" void _mm_store_ss(float*, __m128);
extern const __m128 DAT_010c44d0;
extern const double DAT_010c9300;
struct Body409
{
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned unk20, unk24, unk28, unk2c;
    __m128 inertia;
    unsigned unk40, unk44, unk48, unk4c;
    __m128 basisX, basisY, basisZ;
};
// Unlike include/Pair.h's two ints, this solver context has body pointers at +0x30 and +0x34.
struct ConstraintBodyPairContext
{
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned unk20, unk24, unk28, unk2c;
    Body409* first;
    Body409* second;
};
struct Jacobian409
{
    __m128 first, second;
};
// Adapted from another contributor's previously checked near-match.
// Computes Jacobian rows for a pair of bodies from a vector, sums their inertia-weighted squares, and stores the reciprocal in outRecip.
// @fnv 0x00d6cd70
// src: GUESS 0x00d6cd70 (confidence: medium)
void Hkpbuildjacobianfromatoms_ComputeJacobianInverseEffectiveMass(const __m128& in, const ConstraintBodyPairContext& xf, Jacobian409& out, float& outRecip)
{
    const Body409* Q = xf.second;
    __m128 vNeg = _mm_xor_ps(in, DAT_010c44d0);
    __m128 v = in;
    const Body409* P = xf.first;
    __m128 vBasisX = P->basisX;
    __m128 vBasisY = P->basisY;
    __m128 vBasisZ = P->basisZ;
    __m128 vJacobianFirst = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), vBasisY);
    vJacobianFirst = _mm_add_ps(vJacobianFirst, _mm_mul_ps(_mm_shuffle_ps(v, v, 0), vBasisX));
    vJacobianFirst = _mm_add_ps(vJacobianFirst, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), vBasisZ));
    out.first = vJacobianFirst;
    __m128 vQBasisX = Q->basisX;
    __m128 vQBasisY = Q->basisY;
    __m128 vQBasisZ = Q->basisZ;
    __m128 vJacobianSecond = _mm_mul_ps(_mm_shuffle_ps(vNeg, vNeg, 0x55), vQBasisY);
    vJacobianSecond = _mm_add_ps(vJacobianSecond, _mm_mul_ps(_mm_shuffle_ps(vNeg, vNeg, 0), vQBasisX));
    vJacobianSecond = _mm_add_ps(vJacobianSecond, _mm_mul_ps(_mm_shuffle_ps(vNeg, vNeg, 0xaa), vQBasisZ));
    out.second = vJacobianSecond;
    __m128 o0 = out.first;
    __m128 o1 = vJacobianSecond;
    __m128 d = _mm_mul_ps(_mm_mul_ps(o0, o0), P->inertia);
    d = _mm_add_ps(d, _mm_mul_ps(_mm_mul_ps(o1, o1), Q->inertia));
    __m128 s = _mm_add_ss(_mm_shuffle_ps(d, d, 0x55), d);
    s = _mm_add_ss(_mm_shuffle_ps(d, d, 0xaa), s);
    float f;
    _mm_store_ss(&f, s);
    f = (float)(f + DAT_010c9300);
    float r = 1.0f / f;
    out.first.m128_f32[3] = r;
    outRecip = r;
}

extern "C"
{
    __m128 _mm_load_ps1(const float* p);
    __m128 _mm_load_ss(const float* p);
    __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
    __m128 _mm_add_ps(__m128 a, __m128 b);
    __m128 _mm_sub_ps(__m128 a, __m128 b);
    __m128 _mm_mul_ps(__m128 a, __m128 b);
    __m128 _mm_add_ss(__m128 a, __m128 b);
    __m128 _mm_mul_ss(__m128 a, __m128 b);
    __m128 _mm_sqrt_ss(__m128 a);
    void _mm_store_ss(float* p, __m128 a);
}

extern const double DAT_010d33d0;
extern float Atan2(float y, float x);

__forceinline hkSimdReal::hkSimdReal() {}
__forceinline hkSimdReal::hkSimdReal(const __m128& x) : m_vValue(x) {}
__forceinline hkSimdReal::hkSimdReal(float x)
{
    m_vValue = _mm_load_ss(&x);
}
__forceinline hkSimdReal::operator float() const
{
    float r;
    _mm_store_ss(&r, m_vValue);
    return r;
}
__forceinline const __m128& hkSimdReal::getQuad() const
{
    return m_vValue;
}
__forceinline __m128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}

__forceinline void hkVector4::setAdd4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void hkVector4::mul4(const float& s)
{
    __m128 ss = _mm_load_ss(&s);
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(ss, ss, 0), m_vComponents);
}
__forceinline void hkVector4::setCross(const hkVector4& v0, const hkVector4& v1)
{
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}
__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
}
__forceinline hkSimdReal hkVector4::length3() const
{
    return _mm_sqrt_ss(this->dot3(*this).getQuad());
}
__forceinline hkMatrix3::hkMatrix3() {}
__forceinline hkVector4& hkMatrix3::getColumn(int x)
{
    return (&m_kColumn0)[x];
}
__forceinline const hkVector4& hkMatrix3::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}
__forceinline hkRotation::hkRotation() {}
__forceinline const hkVector4& hkRotation::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}

struct SixteenWordFloatRecord
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
    float m_fThirdQueryValue;
};

struct Vector4AndFourScalars
{
    hkVector4 m_kConstraintAxis;
    float m_kMinimumCorner;
    float m_kMaximumCorner;
    float m_fThirdScalar;
    float m_fTau;
};

__forceinline void hkInternalConstraintUtils_inlineCalcRelativeAngle(
    const hkVector4& twistAxisAinWorld, const hkVector4& twistAxisBinWorld, const hkVector4& planeAxisAinWorld,
    const hkVector4& planeAxisBinWorld, hkVector4& axisOut, float& angleOut, float& tauMaxOut)
{
    hkVector4 twist_axis_ws;
    twist_axis_ws.setAdd4(twistAxisBinWorld, twistAxisAinWorld);
    const float twist_axis_ws_length3 = twist_axis_ws.length3();
    if (twist_axis_ws_length3 > DAT_010d33d0)
    {
        tauMaxOut = twist_axis_ws_length3 * 0.5f;
        twist_axis_ws.mul4(1.0f / twist_axis_ws_length3);
    }
    else
    {
        tauMaxOut = 0.0f;
        twist_axis_ws = twistAxisBinWorld;
    }

    hkRotation m_ws_us;
    {
        hkVector4& c0 = m_ws_us.m_kColumn0;
        hkVector4& c1 = m_ws_us.m_kColumn1;
        hkVector4& c2 = m_ws_us.m_kColumn2;
        c0 = twist_axis_ws;
        c1.setCross(twist_axis_ws, planeAxisBinWorld);
        c2.setCross(c1, c0);
    }

    float d1 = m_ws_us.getColumn(1).dot3(planeAxisAinWorld);
    float d2 = m_ws_us.getColumn(2).dot3(planeAxisAinWorld);
    float currentTwistAngle = Atan2(d1, d2);

    angleOut = currentTwistAngle;
    axisOut = twist_axis_ws;
}

// Computes twist axis, current angle, and tau factor for a twist limit constraint atom, storing results into info.
// @fnv 0x00d6d450
// src: GUESS 0x00d6d450 (confidence: medium)
static __declspec(noinline) int hkRotation_ComputeTwistLimitInfo(const SixteenWordFloatRecord* in, const hkRotation* apBaseB,
                                             Vector4AndFourScalars* info, const hkpTwistLimitConstraintAtom* atom,
                                             const hkRotation* baseA)
{
    const hkRotation*& baseB = apBaseB;
    info->m_kConstraintAxis = baseA->getColumn(atom->m_ucTwistAxis);
    info->m_kMinimumCorner = atom->m_fMinAngle;
    info->m_kMaximumCorner = atom->m_fMaxAngle;

    hkVector4 axis;
    float currentAngle;
    float tauFactor;
    hkInternalConstraintUtils_inlineCalcRelativeAngle(
        baseA->getColumn(atom->m_ucTwistAxis), baseB->getColumn(atom->m_ucTwistAxis),
        baseA->getColumn(atom->m_ucReferenceAxis), baseB->getColumn(atom->m_ucReferenceAxis), axis, currentAngle,
        tauFactor);

    info->m_fThirdScalar = currentAngle;
    info->m_kConstraintAxis = axis;
    info->m_fTau = in->m_fThirdQueryValue * atom->m_fAngularLimitsTauFactor * tauFactor * tauFactor;
    return 0;
}

int TwistLimit_Entry(const SixteenWordFloatRecord* in, const hkRotation* baseB, const hkpTwistLimitConstraintAtom* atom,
                     Vector4AndFourScalars* info, const hkRotation* baseA)
{
    return hkRotation_ComputeTwistLimitInfo(in, baseB, info, atom, baseA);
}

extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_xor_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);

extern const __m128 DAT_010c4c00;
extern const __m128 DAT_010c44d0;

union S6f0c0_Arg
{
    unsigned int i;
    unsigned short s;
    unsigned char b;
    void* p;
};

struct S6f0c0_Rec
{
    unsigned char type;
    unsigned char unk01;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
    S6f0c0_Arg unk08;
    S6f0c0_Arg unk0c;
};

struct S6f0c0_Bone
{
    int unk00;
    unsigned short unk04;
    unsigned short count;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char idx;
    unsigned char unk0b;
    int unk0c;
    __m128 unk10;
    __m128 unk20;
    __m128 data;
    PacketCallLocal_00d6d450 axis;
};

struct S6f0c0_Link
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    union
    {
        __m128 vel;
    };
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
    void InitializeFields_00d72030(S6f0c0_Link* prev);
};
struct S6f0c0_Blob
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
    S6f0c0_Link* link30;
    S6f0c0_Link* link34;
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
};

struct S6f0c0_Ctx
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S6f0c0_Bone* bone;
    int unk18;
    int unk1c;
    PacketCallLocal_00d6d450 dir;
};

union S6f0c0_Tag
{
    unsigned int i;
    unsigned char b;
};

struct S6f0c0_Key
{
    unsigned int idx;
    unsigned int b;
    unsigned int a;
    void* p;
    S6f0c0_Key(unsigned int idx_, void* p_, unsigned int b_, unsigned int a_) : idx(idx_)
    {
        p = p_;
        b = b_;
        a = a_;
    }
};

inline void S6f0c0_Emit(S6f0c0_Blob* source, S6f0c0_Rec** cursor, void* data, unsigned int index)
{
    S6f0c0_Rec* record = *cursor;
    float value = *(float*)record;
    unsigned int hi = source->unk70;
    value += 1.1920928955078125e-07;
    unsigned int lo = source->unk6c;
    unsigned int whole = source->unk60;
    *(float*)record = value;
    record->unk04 = (unsigned short)lo;
    record->unk06 = (unsigned short)hi;
    record->unk08.p = data;
    record->type = 1;
    record->unk0c.i = whole;
    record->unk01 = (unsigned char)index;
    *cursor = record + 1;
}

void __cdecl hkSimpleContactConstraintDataBuildJacobian(S6f0c0_Bone* bone, S6f0c0_Blob* blob, S6f0c0_Tag tag, S6f0c0_Rec** cursor);
void __cdecl Hkpbuildjacobianfromatoms_WriteType1ARecordAndAdvance(const __m128* value, unsigned int flag, S6f0c0_Rec** cursor);

// Writes a bone record to the cursor, computes a direction vector from the bone axis and context dir, and emits two vector records.
// @fnv 0x00d6f0c0
// src: GUESS 0x00d6f0c0 (confidence: low)
static __declspec(noinline) void Object_UpdateFields_00d6f0c0(S6f0c0_Ctx* ctx, S6f0c0_Blob* src, S6f0c0_Rec** cursor)
{
    __m128 v;
    PacketCallLocal_00d6d450 dir = ctx->dir;
    S6f0c0_Blob blobCopy = *src;
    S6f0c0_Bone* bone = ctx->bone;
    --*cursor;
    S6f0c0_Emit(src, cursor, (char*)&bone->data + bone->count * 32, bone->idx);
    bool neg = src->unk6c == 0;
    S6f0c0_Link link;
    S6f0c0_Link* lp = &link;
    __m128 vDir;
    const __m128& localDirection = *(__m128*)&dir;
    if (!neg)
    {
        lp->InitializeFields_00d72030(src->link30);
        vDir = localDirection;
        src->link30 = lp;
    }
    else
    {
        lp->InitializeFields_00d72030(src->link34);
        vDir = localDirection;
        src->link34 = lp;
        vDir = _mm_xor_ps(vDir, DAT_010c4c00);
    }
    PacketCallLocal_00d6d450 ax = bone->axis;
    __m128 axis = *(__m128*)&ax;
    __m128 d = _mm_mul_ps(axis, vDir);
    __m128 t = _mm_add_ss(_mm_shuffle_ps(d, d, 0x55), d);
    d = _mm_add_ss(_mm_shuffle_ps(d, d, 0xaa), t);
    v = _mm_xor_ps(_mm_sub_ps(vDir, _mm_mul_ps(_mm_shuffle_ps(d, d, 0), axis)), DAT_010c44d0);
    unsigned int flag = neg != 0;
    Hkpbuildjacobianfromatoms_WriteType1ARecordAndAdvance(&v, flag, cursor);
    link.vel = _mm_add_ps(link.vel, v);
    S6f0c0_Tag tag;
    tag.b = 0;
    hkSimpleContactConstraintDataBuildJacobian(bone, &blobCopy, tag, cursor);
    v = _mm_xor_ps(v, DAT_010c44d0);
    Hkpbuildjacobianfromatoms_WriteType1ARecordAndAdvance(&v, flag, cursor);
}

void S6f0c0_Caller(S6f0c0_Ctx* ctx, S6f0c0_Blob* src, S6f0c0_Rec** cursor)
{
    Object_UpdateFields_00d6f0c0(ctx, src, cursor);
}

#include <math.h>
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" void _mm_store_ss(float*, __m128);
extern float DAT_0104da4c;
extern float DAT_010d33d8[];
extern float DAT_010d33e0[];
extern float DAT_010d33e4;
float __cdecl Atan2(float a, float b);
struct Ctx
{
    unsigned char m00;
    unsigned char m01;
    unsigned char m02;
    unsigned char m03;
    unsigned char m04;
    unsigned char m05;
    float m08;
    float m0c;
    float m10;
};
__declspec(align(16)) struct Out
{
    float m00;
    float m04;
    float m08;
    float m0c;
    float m10;
    float m14;
    float m18;
    float m1c;
};
struct AngleTemps
{
    float length;
    float reciprocal;
    float factor;
    float angle;
};
struct VecArg
{
    __m128* p;
};
// Returns 1 if the squared cross product of two indexed vectors is below a threshold, else fills out with a scaled axis and an angle and returns 0.
// @fnv 0x00d6d5d0
// src: GUESS 0x00d6d5d0 (confidence: medium)
static __declspec(noinline) int __cdecl Hkpbuildjacobianfromatoms_ComputeAxisAngleOrReportParallel(float* a1, VecArg a2, VecArg a3, Ctx* self, Out* out)
{
    float threshold = DAT_0104da4c;
    const __m128& A = a2.p[self->m03];
    const __m128& B = a3.p[self->m04];
    __m128 p1 = _mm_mul_ps(_mm_shuffle_ps(A, A, 0xd2), _mm_shuffle_ps(B, B, 0xc9));
    __m128 p2 = _mm_mul_ps(_mm_shuffle_ps(B, B, 0xd2), _mm_shuffle_ps(A, A, 0xc9));
    __m128 vCross = _mm_sub_ps(p2, p1);
    __m128 sq = _mm_mul_ps(vCross, vCross);
    __m128 t = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    t = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), t);
    AngleTemps tmp;
    _mm_store_ss(&tmp.length, t);
    if (threshold > tmp.length)
        return 1;
    unsigned int idx5 = self->m05;
    __m128 m = _mm_mul_ps(B, A);
    __m128 d = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    d = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), d);
    _mm_store_ss(&tmp.reciprocal, d);
    tmp.length = (float)sqrt((double)tmp.length);
    tmp.angle = Atan2(tmp.length, tmp.reciprocal) * DAT_010d33e0[idx5] + DAT_010d33d8[idx5];
    tmp.factor = *(&DAT_010d33e4 - self->m05);
    out->m1c = a1[0x10] * self->m10;
    __m128 scale = _mm_load_ss(&tmp.factor);
    scale = _mm_shuffle_ps(scale, scale, 0);
    tmp.reciprocal = 1.0f / tmp.length;
    __m128 inverse = _mm_load_ss(&tmp.reciprocal);
    out->m18 = tmp.angle;
    __m128 v = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(inverse, inverse, 0), vCross), scale);
    *(__m128*)&out->m00 = v;
    out->m10 = self->m08;
    out->m14 = self->m0c;
    return 0;
}
volatile int result;
void AngleCaller(float* a1, __m128* a2, __m128* a3, Ctx* self, Out* out)
{
    VecArg x = {a2}, y = {a3};
    result = Hkpbuildjacobianfromatoms_ComputeAxisAngleOrReportParallel(a1, x, y, self, out);
}

template <class T> class FieldValue
{
    T stored;

  public:
    __forceinline FieldValue()
    {}
    __forceinline FieldValue(T x) : stored(x)
    {}
    __forceinline T get() const
    {
        return stored;
    }
    __forceinline operator T() const
    {
        return get();
    }
    __forceinline T operator->() const
    {
        return stored;
    }
    __forceinline void operator=(T x)
    {
        stored = x;
    }
};
extern "C" void _ReadWriteBarrier();
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" float _mm_cvtss_f32(__m128);
extern "C" void _mm_store_ss(float*, __m128);
extern const double DAT_010d33d0;
extern const __m128 DAT_010c44d0;

struct PackedScalar
{
    __m128 value;
    __forceinline PackedScalar()
    {}
    PackedScalar(float f)
    {
        value = _mm_load_ss(&f);
    }
    PackedScalar(const __m128& v) : value(v)
    {}
    __forceinline const __m128& quad() const
    {
        return value;
    }
    operator float() const
    {
        float f;
        _mm_store_ss(&f, value);
        return f;
    }
};
class MathVector
{
  public:
    __m128 value;
    __forceinline const __m128& quad() const
    {
        return value;
    }
    __forceinline __m128& quad()
    {
        return value;
    }
    __forceinline void operator=(const MathVector& b)
    {
        value = b.value;
    }
    __forceinline void operator=(const __m128& b)
    {
        value = b;
    }
    __forceinline void add(const MathVector& a, const MathVector& b)
    {
        value = _mm_add_ps(a.value, b.value);
    }
    inline PackedScalar dot(const MathVector& b) const
    {
        __m128 p = _mm_mul_ps(value, b.value);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy);
    }
    inline PackedScalar length() const
    {
        return _mm_sqrt_ss(dot(*this).quad());
    }
    __forceinline void multiply(const PackedScalar& f)
    {
        value = _mm_mul_ps(_mm_shuffle_ps(f.quad(), f.quad(), 0), value);
    }
    __forceinline void cross(const MathVector& a, const MathVector& b)
    {
        __m128 p = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xc9), _mm_shuffle_ps(b.value, b.value, 0xd2));
        __m128 q = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xd2), _mm_shuffle_ps(b.value, b.value, 0xc9));
        value = _mm_sub_ps(p, q);
    }
};
static __forceinline PackedScalar scalar(__m128 v)
{
    return PackedScalar(v);
}
struct MatrixColumns
{
    MathVector x, y, z;
    __forceinline MathVector& column(int i)
    {
        return (&x)[i];
    }
};
struct AngleBasis : MatrixColumns
{
};
static __forceinline void relativeAngle(const MathVector& a, const MathVector& b, const MathVector& pa,
                                        const MathVector& pb, MathVector& axis, FieldValue<float>& angle,
                                        FieldValue<float>& tau)
{
    MathVector sum;
    sum.add(b, a);
    const float len = sum.length();
    if (len > 1.0e-16f)
    {
        tau = len * 0.5f;
        sum.multiply(1.0f / len);
    }
    else
    {
        tau = 0.0f;
        sum = b;
    }
    AngleBasis frame;
    {
        MathVector& x = frame.column(0);
        MathVector& y = frame.column(1);
        MathVector& z = frame.column(2);
        x = sum;
        y.cross(sum, pb);
        z.cross(y, x);
    }
    float d1 = frame.column(1).dot(pa);
    float d2 = frame.column(2).dot(pa);
    float angleValue = Atan2(d1, d2);
    angle = angleValue;
    axis = sum;
}
union AlignedVector
{
    __m128 vec;
};
struct Basis
{
    MathVector axis[3];
};
struct FnvSubObject
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
    union
    {
        __m128 vec;
    };
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    MathVector axis[3];
};
struct Property
{
    float a, b;
};
struct FnvPacket
{
    int unk00;
    FieldValue<float> scale;
    FieldValue<float> scale2;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    FnvSubObject* unk30;
    FnvSubObject* unk34;
    int unk38;
    Basis* unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    unsigned char* cache;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
};
struct AxisRecord
{
    unsigned short type;
    unsigned char active;
    unsigned char unk03;
    short initializedOffset;
    short angleOffset;
    int unk08;
    int unk0c;
    Basis basis;
    void* item[3];
};
struct OutputRecord
{
    union
    {
        float stamp;
        unsigned char type;
    };
    union
    {
        __m128 unused;
    };
};
struct StreamRecord
{
    union
    {
        float stamp;
        unsigned char type;
    };
    union
    {
        unsigned int u04;
        unsigned char flag;
    };
    float u08;
    float mass;
    AlignedVector second;
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
};
struct EvalInput
{
    float inverse;
    FnvPacket* context;
    Property property;
    float deltaNew, deltaOld;
};
struct EvalOutput
{
    FieldValue<float> f00, f04, f08, f0c, f10, f14;
};
extern "C" void __cdecl hkMatrix3_MultiplyMatrixColumns(Basis*, const Basis*, const Basis*);
extern "C" void __cdecl _hkCalcMotorData(void*, const EvalInput*, EvalOutput*);

static __forceinline __m128 rotate(FnvSubObject* o, __m128 v)
{
    __m128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), o->axis[1].quad());
    __m128 x = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), o->axis[0].quad());
    __m128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), o->axis[2].quad());
    return _mm_add_ps(_mm_add_ps(y, x), z);
}
static __forceinline void emptyRecord(StreamRecord** cursor, unsigned char flag)
{
    float* p = (float*)*cursor;
    StreamRecord* out = *cursor;
    double stamp = *p;
    out->flag = flag;
    *p = stamp + 1.1920928955078125e-7;
    out->type = 3;
    *cursor = (StreamRecord*)(p + 4);
}
// For an active record, writes one stream record per axis (type 15 with mass and solver outputs, or an empty record) and updates cached previous angles.
// @fnv 0x00d6dd60
// src: GUESS 0x00d6dd60 (confidence: medium)
static __declspec(noinline) void Object_WriteAxisRecordsAndCacheAngles(FnvPacket* context, AxisRecord* record, const Basis* a, const Basis* b,
                                              StreamRecord** cursor)
{
    unsigned char* initialized = context->cache + record->initializedOffset;
    float* previous = (float*)(context->cache + record->angleOffset);
    if (record->active)
    {
        Basis transformed;
        hkMatrix3_MultiplyMatrixColumns(&transformed, context->unk3c, &record->basis);
        EvalInput input;
        input.property.b = input.property.a = 0.0f;
        input.context = context;
        int axes[3] = {0, 1, 2};
        int other[3] = {1, 0, 0};

        for (int i = 0; i < 3; ++i)
        {
            void* current = record->item[i];
            if (current)
            {
                const int& axis = axes[i];
                const int& next = other[i];
                MathVector direction;
                FieldValue<float> oldAngle, newAngle, tau;
                relativeAngle(a->axis[axis], b->axis[axis], a->axis[next], b->axis[next], direction, oldAngle, tau);
                MathVector nextDirection;
                relativeAngle(transformed.axis[axis], b->axis[axis], transformed.axis[next], b->axis[next],
                              nextDirection, newAngle, tau);
                if (!initialized[i])
                {
                    previous[i] = oldAngle;
                    initialized[i] = 1;
                }
                StreamRecord* out = *cursor;
                __m128 neg = _mm_xor_ps(nextDirection.quad(), DAT_010c44d0);
                FnvSubObject* objectB = context->unk34;
                FnvSubObject* objectA = context->unk30;
                ((AlignedVector*)out)->vec = rotate(objectA, nextDirection.quad());
                out->second.vec = rotate(objectB, neg);
                __m128 weightedB = _mm_mul_ps(_mm_mul_ps(out->second.vec, out->second.vec), objectB->vec);
                __m128 first = ((AlignedVector*)out)->vec;
                __m128 weightedA = _mm_mul_ps(_mm_mul_ps(first, first), objectA->vec);
                __m128 total = _mm_add_ps(weightedB, weightedA);
                float sum = scalar(_mm_add_ss(_mm_shuffle_ps(total, total, 0xaa),
                                              _mm_add_ss(_mm_shuffle_ps(total, total, 0x55), total)));
                float mass = (float)(sum + 1.1920928955078125e-7);
                input.inverse = out->mass = 1.0f / mass;
                input.property = ((Property*)context->cache)[i];
                input.deltaNew = newAngle - previous[i];
                input.deltaOld = previous[i] - oldAngle;
                EvalOutput result;
                _hkCalcMotorData(current, &input, &result);
                reinterpret_cast<PacketCallLocal_00d6d450&>(out->second.vec).w = context->scale2 * result.f00;
                StreamRecord* __restrict emit = *cursor;
                emit->stamp += 1.1920928955078125e-7;
                emit->type = 15;
                emit->f20 = result.f08 * context->scale;
                emit->f24 = result.f0c * context->scale;
                emit->f28 = result.f04;
                emit->f2c = result.f10;
                emit->f30 = result.f14;
                *cursor = emit + 1;
                if (previous[i] != newAngle)
                    previous[i] = newAngle;
            }
            else
            {
                emptyRecord(cursor, 1);
            }
        }
    }
    else
    {
        emptyRecord(cursor, 3);
    }
}
FnvPacket* volatile sourcePacket;
AxisRecord* volatile sourceRecord;
const Basis* volatile sourceA;
const Basis* volatile sourceB;
StreamRecord** volatile sourceCursor;
void TargetCaller()
{
    Object_WriteAxisRecordsAndCacheAngles(sourcePacket, sourceRecord, sourceA, sourceB, sourceCursor);
}

extern "C"
{
    __m128 _mm_sub_ps(__m128 a, __m128 b);
    __m128 _mm_mul_ps(__m128 a, __m128 b);
    __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm8);
    __m128 _mm_add_ss(__m128 a, __m128 b);
    __m128 _mm_sub_ss(__m128 a, __m128 b);
    void _mm_store_ss(float* p, __m128 a);
    __m128 _mm_unpackhi_ps(__m128 a, __m128 b);
    int _mm_movemask_ps(__m128 a);
}
extern long(__stdcall* DAT_00fdf1ec)(long volatile*, long);
struct Rot
{
    V4 col0;
    V4 col1;
    V4 col2;
};
struct Body
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    V4 linear;
    V4 inertia;
    V4 center;
    Rot rot;
};
struct Constraint
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float timestep;
    float strength;
    int unk28;
    int unk2c;
    Body* bodyA;
    Body* bodyB;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    V4 speedLimit;
    int identifier;
    int unk64;
    long* notifications;
};
// hkTransform layout: 3x hkVector4 rotation columns (+0x00..+0x2c, unread here) then the translation at +0x30,
// the only member 0x00d6ced0 reads, represented here by the shared V4.
struct AtomTransform
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
    V4 position;
};
struct Input
{
    unsigned char b0, b1, b2, index;
    float threshold;
};
struct Record
{
    V4 axis;
    V4 angularA;
    V4 angularB;
};
extern float DAT_010c7948[];
extern double DAT_0104e138;
static __forceinline __m128 Cross(const __m128& a, const __m128& b)
{
    __m128 left = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 right = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(left, right);
}
static __forceinline __m128 Dot3V(__m128 a, __m128 b)
{
    __m128 m = _mm_mul_ps(a, b);
    __m128 y = _mm_shuffle_ps(m, m, 0x55);
    __m128 z = _mm_shuffle_ps(m, m, 0xaa);
    return _mm_add_ss(z, _mm_add_ss(y, m));
}
static __forceinline float Dot3(__m128 a, __m128 b)
{
    float f;
    _mm_store_ss(&f, Dot3V(a, b));
    return f;
}
static __forceinline __m128 Rotate(const Rot& b, __m128 v)
{
    return _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), b.col1.m),
                                 _mm_mul_ps(_mm_shuffle_ps(v, v, 0), b.col0.m)),
                      _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), b.col2.m));
}
static __forceinline float EffectiveMass(const V4& angularA, const V4& inertiaA, __m128 angularB, __m128 inertiaB)
{
    __m128 mass = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(angularB, angularB), inertiaB),
                             _mm_mul_ps(_mm_mul_ps(angularA.m, angularA.m), inertiaA.m));
    __m128 inertia = _mm_add_ps(inertiaA.m, inertiaB);
    __m128 high = _mm_unpackhi_ps(mass, inertia);
    __m128 total = _mm_shuffle_ps(mass, high, 0xc4);
    __m128 sum = _mm_add_ps(_mm_shuffle_ps(total, total, 0x4e), total);
    sum = _mm_add_ps(_mm_shuffle_ps(sum, sum, 0xb1), sum);
    float massValue;
    _mm_store_ss(&massValue, sum);
    return massValue;
}
// Fills three Record entries for a constraint, computing angular terms and effective mass, and appends a notification if the speed limit is exceeded.
// @fnv 0x00d6ced0
// src: GUESS 0x00d6ced0 (confidence: medium)
static void __declspec(noinline)
    hkVector4_BuildConstraintRowsAndCheckSpeedLimit(Input* input, Constraint* apConstraint, AtomTransform* apPointA, AtomTransform* apPointB, Record** cursor)
{
    Body* bodyA = apConstraint->bodyA;
    Body* bodyB = apConstraint->bodyB;
    Record* out = *cursor;
    float threshold = input->threshold;
    float inverse = DAT_010c7948[input->index] * (1.0f / apConstraint->timestep);
    V4 inverseV;
    inverseV.m = _mm_load_ss(&inverse);
    V4 pa;
    pa.m = apPointA->position.m;
    V4 ra;
    ra.m = _mm_sub_ps(pa.m, bodyA->center.m);
    V4 pb;
    pb.m = apPointB->position.m;
    V4 rb;
    rb.m = _mm_sub_ps(pb.m, bodyB->center.m);
    hkVector4 wa, wb;
    wa.hkVector4_setRotatedInverseDir(reinterpret_cast<const hkRotation&>(bodyA->rot), reinterpret_cast<const hkVector4&>(bodyA->linear));
    wb.hkVector4_setRotatedInverseDir(reinterpret_cast<const hkRotation&>(bodyB->rot), reinterpret_cast<const hkVector4&>(bodyB->linear));
    __m128 scale = _mm_shuffle_ps(inverseV.m, inverseV.m, 0);
    V4 velocity;
    velocity.m =
        _mm_sub_ps(_mm_add_ps(_mm_mul_ps(Cross(rb.m, wb.m_vComponents), scale), _mm_sub_ps(pb.m, pa.m)),
                   _mm_mul_ps(Cross(ra.m, wa.m_vComponents), scale));
    if (apConstraint->notifications)
    {
        __m128 diff = _mm_sub_ss(apConstraint->speedLimit.m, Dot3V(velocity.m, velocity.m));
        if (_mm_movemask_ps(diff) & 1)
        {
            unsigned int n = (unsigned int)DAT_00fdf1ec(apConstraint->notifications, 1);
            if (n < 128)
                apConstraint->notifications[n + 1] = apConstraint->identifier;
        }
    }
    const V4* pAxis = (const V4*)DAT_01268370;
    for (int i = 0; i < 3; ++i, ++pAxis)
    {
        float strength = apConstraint->strength;
        float timestep = apConstraint->timestep;
        out->axis.m = (*pAxis).m;
        __m128 rA = _mm_sub_ps(apPointA->position.m, bodyA->center.m);
        __m128 rB = _mm_sub_ps(apPointB->position.m, bodyB->center.m);
        __m128 vCrossA = Cross(rA, (*pAxis).m);
        __m128 vCrossB = Cross((*pAxis).m, rB);
        out->angularA.m = Rotate(bodyA->rot, vCrossA);
        out->angularB.m = Rotate(bodyB->rot, vCrossB);
        __m128 angA = out->angularA.m;
        __m128 angB = out->angularB.m;
        __m128 vInertiaB = bodyB->inertia.m;
        __m128 vInertiaA = bodyA->inertia.m;
        __m128 mass =
            _mm_add_ps(_mm_mul_ps(_mm_mul_ps(angB, angB), vInertiaB), _mm_mul_ps(_mm_mul_ps(angA, angA), vInertiaA));
        __m128 inertia = _mm_add_ps(vInertiaA, vInertiaB);
        __m128 high = _mm_unpackhi_ps(mass, inertia);
        __m128 total = _mm_shuffle_ps(mass, high, 0xc4);
        __m128 sum = _mm_add_ps(_mm_shuffle_ps(total, total, 0x4e), total);
        sum = _mm_add_ps(_mm_shuffle_ps(sum, sum, 0xb1), sum);
        float massValue;
        _mm_store_ss(&massValue, sum);
        float denominator = massValue + 1.1920928955078125e-7;
        out->angularB.w = denominator;
        out->angularA.w = strength / denominator;
        out->axis.w =
            Dot3(_mm_sub_ps(apPointB->position.m, apPointA->position.m), (*pAxis).m) * timestep;
        out->axis.w = velocity.f[i] * apConstraint->timestep;
        if (threshold == 3.402820018375656e38)
        {
            out->axis.x += 1.1920928955078125e-7;
            ((unsigned char*)out)[0] = 5;
        }
        else
        {
            out->axis.x += 1.1920928955078125e-7;
            ((unsigned char*)out)[0] = 6;
            out->angularB.w = threshold;
        }
        ++out;
    }
    *cursor = out;
}
extern Input* volatile callInput;
extern Constraint* volatile callObject;
extern AtomTransform* volatile callA;
extern AtomTransform* volatile callB;
extern Record** volatile callCursor;
void ConstraintWrite_use()
{
    hkVector4_BuildConstraintRowsAndCheckSpeedLimit(callInput, callObject, callA, callB, callCursor);
}

extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" void _ReadWriteBarrier();

struct AngularRecord
{
    unsigned char type, flag, enabled, axis;
    short initializedOffset, angleOffset, referenceOffset;
    short unk0a;
    float limit;
    void* solver;
};
struct AngularData
{
    float f00, f04;
};
struct AngularMatrix
{
    __m128 v00, v10, v20, inertia, v40, rotation0, rotation1, rotation2;
};
struct AngularInput
{
    float mass;
    WriterContext* context;
    AngularData base;
    float error, delta;
};
struct AngularOutput
{
    float p0, p1, p2, p3, p4, p5;
};
struct AngularRow
{
    union
    {
        __m128 angularA;
        struct
        {
            unsigned char type, unk01, unk02, unk03, flag, unk05, unk06, unk07;
            int unk08, unk0c;
        } header;
    };
    __m128 angularB;
    float p20, p24, p28, p2c, p30, p34, p38, p3c;
};
extern unsigned char DAT_010d33c1[];
extern unsigned char DAT_010d33c2[];
extern const __m128 DAT_010c44d0;

static __forceinline void AngularSum(float* out, __m128 m)
{
    __m128 y = _mm_shuffle_ps(m, m, 0x55);
    y = _mm_add_ss(y, m);
    __m128 z = _mm_shuffle_ps(m, m, 0xaa);
    _mm_store_ss(out, _mm_add_ss(z, y));
}
static __forceinline void AngularDot(float* out, __m128 a, __m128 b)
{
    AngularSum(out, _mm_mul_ps(a, b));
}
static __forceinline __m128 AngularRotate(AngularMatrix* m, __m128 a)
{
    __m128 r1 = m->rotation1, r0 = m->rotation0;
    __m128 y = _mm_mul_ps(_mm_shuffle_ps(a, a, 0x55), r1);
    __m128 x = _mm_mul_ps(_mm_shuffle_ps(a, a, 0), r0);
    __m128 sum = _mm_add_ps(y, x);
    __m128 z = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xaa), m->rotation2);
    return _mm_add_ps(sum, z);
}

static __forceinline float ReduceFloat(__m128 v)
{
    float r;
    AngularSum(&r, v);
    return r;
}

static __forceinline float ScalarValue(float v)
{
    return v;
}
static __forceinline __m128 VectorValue(__m128 v)
{
    return v;
}
static __forceinline AngularRow** CursorValue(AngularRow** v)
{
    return v;
}

struct RowCursor
{
    AngularRow* row;
};

struct AngularAxes
{
    __m128* p;
    AngularAxes(__m128* q) : p(q)
    {}
};
// Writes an angular constraint row to the solver, computing the angle from axis vectors and evaluating the solver if enabled.
// @fnv 0x00d6da00
// src: GUESS 0x00d6da00 (confidence: medium)
static __declspec(noinline) void Object_WriteAngularConstraintRow(WriterContext* apContext, AngularRecord* record, AngularAxes aa,
                                              AngularAxes ab, RowCursor& cur)
{
    AngularData* data = (AngularData*)apContext->unk64;
    unsigned char* initialized = (unsigned char*)data + record->initializedOffset;
    float* previous = (float*)((unsigned char*)data + record->angleOffset);
    void* solver = record->solver;
    if (solver && record->enabled)
    {
        unsigned axis = record->axis;
        const __m128* pa = (const __m128*)((unsigned)aa.p + DAT_010d33c1[axis]);
        const __m128* pb = (const __m128*)((unsigned)ab.p + DAT_010d33c2[axis]);
        const __m128* pc = (const __m128*)((unsigned)ab.p + (axis << 4));
        float dot;
        AngularDot(&dot, *pa, *pb);
        __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(*pc, *pc, 0xd2), _mm_shuffle_ps(*pb, *pb, 0xc9)),
                                  _mm_mul_ps(_mm_shuffle_ps(*pc, *pc, 0xc9), _mm_shuffle_ps(*pb, *pb, 0xd2)));
        float triple;
        AngularDot(&triple, cross, *pa);
        float angle = Atan2(dot, triple);
        if (record->referenceOffset)
        {
            float reference = -1.0 * ((AngularData*)((unsigned char*)apContext->unk64 + record->referenceOffset))->f04;
            while (reference - angle > 3.1415927410125732)
                angle += 6.2831854820251465;
            while (angle - reference > 3.1415927410125732)
                angle -= 6.2831854820251465;
        }
        if (!*initialized)
            *previous = angle;
        AngularRow* row = *(&cur.row);
        AngularInput input;
        input.base.f00 = 0.0f;
        input.base.f04 = 0.0f;
        const __m128* directionPtr = (const __m128*)((unsigned)aa.p + (record->axis << 4));
        AngularMatrix* matrixB = (AngularMatrix*)apContext->unk34;
        AngularMatrix* matrixA = (AngularMatrix*)apContext->unk30;
        __m128 neg = _mm_xor_ps(*directionPtr, DAT_010c44d0);
        row->angularA = AngularRotate(matrixA, *directionPtr);
        row->angularB = AngularRotate(matrixB, neg);
        __m128 va = row->angularA, vb = row->angularB;
        __m128 weightedB = _mm_mul_ps(_mm_mul_ps(vb, vb), matrixB->inertia);
        __m128 weightedA = _mm_mul_ps(_mm_mul_ps(va, va), matrixA->inertia);
        float mass = 1.0f / (float)(ReduceFloat(_mm_add_ps(weightedB, weightedA)) + _DAT_010c9300);
        row->angularA.m128_f32[3] = mass;
        input.mass = mass;
        input.context = apContext;
        input.base = *(AngularData*)apContext->unk64;
        input.error = record->limit - *previous;
        input.delta = ScalarValue(*previous) - angle;
        AngularOutput output;
        _hkCalcMotorData(solver, (const EvalInput*)&input, (EvalOutput*)&output);
        AngularRow** cursor = CursorValue((&cur.row));
        row->angularB.m128_f32[3] = ((float&)apContext->unk08) * output.p0;
        AngularRow* current = *cursor + 1;
        current[-1].angularA.m128_f32[0] += _DAT_010c9300;
        current[-1].header.type = 15;
        current[-1].p20 = ScalarValue(output.p2) * ((float&)apContext->unk04);
        double scaled = output.p3 * ((float&)apContext->unk04);
        *cursor = current;
        current[-1].p24 = scaled;
        current[-1].p28 = ScalarValue(output.p1);
        current[-1].p2c = output.p4;
        current[-1].p30 = output.p5;
        if (*previous != record->limit || !*initialized)
        {
            *previous = record->limit;
            *initialized = 1;
        }
    }
    else
    {
        AngularRow** cursor = CursorValue((&cur.row));
        AngularRow* current = *cursor;
        current->header.flag = 1;
        current->angularA.m128_f32[0] += _DAT_010c9300;
        current->header.type = 3;
        *cursor = (AngularRow*)((__m128*)current + 1);
    }
}
void AngularWrite_use(AngularRecord* record, WriterContext* object, __m128* axesA, __m128* axesB, AngularRow** cursor)
{
    AngularAxes aa(axesA), ab(axesB);
    Object_WriteAngularConstraintRow(object, record, aa, ab, *(RowCursor*)cursor);
}

extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_set_ss(float);
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern const float DAT_01011d78;
extern const float DAT_01017718;
extern float DAT_01016248;

struct SolverVector
{
    union
    {
        __m128 v;
        float f[4];
    };
    __forceinline void sub(const SolverVector& a, const SolverVector& b)
    {
        v = _mm_sub_ps(a.v, b.v);
    }
    __forceinline void normalized(const SolverVector& a, const __m128& fallback)
    {
        __m128 p = _mm_mul_ps(a.v, a.v);
        float len2;
        _mm_store_ss(&len2, _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p)));
        if (len2 > 1.1920928955078125e-7f)
        {
            __m128 square = _mm_mul_ps(a.v, a.v);
            __m128 s = _mm_add_ss(_mm_shuffle_ps(square, square, 0xaa),
                                  _mm_add_ss(_mm_shuffle_ps(square, square, 0x55), square));
            __m128 r = _mm_rsqrt_ss(s);
            __m128 mask = _mm_cmpeq_ss(s, _mm_load_ss(&DAT_01011d78));
            __m128 t = _mm_sub_ss(_mm_set_ss(DAT_01017718), _mm_mul_ss(_mm_mul_ss(s, r), r));
            __m128 inv = _mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(_mm_set_ss(DAT_01016248), r), t));
            v = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), a.v);
        }
        else
            v = fallback;
    }
};
struct SolverBody
{
    SolverVector unk00, unk10, unk20, inverseInertia;
    SolverVector center, basis0, basis1, basis2;
};
struct SolverGeometry
{
    SolverVector unk00, pointA, pointB;
    float separation, ratio;
};
struct PulleyWork
{
    SolverVector pivotA, pivotB, ropeAnchorA, ropeAnchorB;
    float separation, ratio;
};
struct PulleyState
{
    SolverVector unk00, unk10, unk20, unk30, unk40, unk50, unk60;
    float separation, ratio, biasFactor, massFactor;
};
struct SolverSettings
{
    float unk00, unk04, biasFactor, unk0c;
    float unk10, unk14, unk18, unk1c;
    float unk20, massFactor, unk28, unk2c;
    SolverBody* bodyA;
    SolverBody* bodyB;
};
struct SolverRecord
{
    SolverVector linearA, linearB, angularA, angularB;
};

static __forceinline __m128 squared3(__m128 v)
{
    __m128 p = _mm_mul_ps(v, v);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}
static __forceinline __m128 cross3(__m128 a, __m128 b)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                      _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
}
static __forceinline __m128 transform3(__m128 v, SolverBody* b)
{
    return _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), b->basis1.v),
                                 _mm_mul_ps(_mm_shuffle_ps(v, v, 0), b->basis0.v)),
                      _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), b->basis2.v));
}
// Computes pulley constraint linear/angular errors, effective mass, and bias for two bodies, storing results into the SolverRecord at *cursor.
// @fnv 0x00d6e6b0
// src: GUESS 0x00d6e6b0 (confidence: medium)
static __declspec(noinline) void Hkpbuildjacobianfromatoms_BuildPulleySolverRecord(SolverGeometry* geometry, SolverBody* anchorA, SolverSettings* settings,
                                              SolverBody* anchorB, SolverRecord** cursor)
{
    PulleyWork kIter;
    kIter.separation = geometry->separation;
    kIter.pivotA.v = anchorB->inverseInertia.v;
    kIter.ropeAnchorA.v = geometry->pointA.v;
    kIter.pivotB.v = anchorA->inverseInertia.v;
    kIter.ropeAnchorB.v = geometry->pointB.v;
    kIter.ratio = geometry->ratio;

    PulleyState z;
    SolverBody* pBodyA;
    pBodyA = settings->bodyA;
    SolverVector deltaA;
    deltaA.sub(kIter.ropeAnchorA, kIter.pivotA);
    SolverVector deltaB;
    deltaB.sub(kIter.pivotB, kIter.ropeAnchorB);
    SolverBody* pBodyB;
    pBodyB = settings->bodyB;
    SolverRecord* error;
    error = *cursor;
    SolverVector unitA;
    unitA.normalized(deltaA, DAT_01268370[0]);
    SolverVector unitB;
    unitB.normalized(deltaB, _mm_xor_ps(DAT_01268370[0], DAT_010c44d0));
    z.ratio = kIter.ratio;
    const float* scale = &z.ratio;
    unitB.v = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(scale), _mm_load_ss(scale), 0), unitB.v);
    z.biasFactor = settings->biasFactor;
    z.massFactor = settings->massFactor;
    error->linearB.v = unitB.v;
    error->linearA.v = unitA.v;
    SolverVector leverA;
    leverA.v = _mm_sub_ps(kIter.pivotA.v, pBodyA->center.v);
    SolverVector leverB;
    leverB.v = _mm_sub_ps(kIter.pivotB.v, pBodyB->center.v);
    SolverVector angularA;
    angularA.v = cross3(leverA.v, unitA.v);
    SolverVector angularB;
    angularB.v = cross3(unitB.v, leverB.v);
    error->angularA.v = transform3(angularA.v, pBodyA);
    error->angularB.v = transform3(angularB.v, pBodyB);
    SolverVector w;
    w.v = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(error->angularA.v, error->angularA.v), pBodyA->inverseInertia.v),
                     _mm_mul_ps(_mm_mul_ps(error->angularB.v, error->angularB.v), pBodyB->inverseInertia.v));
    float val;
    _mm_store_ss(&val, _mm_add_ss(_mm_shuffle_ps(w.v, w.v, 0xaa), _mm_add_ss(_mm_shuffle_ps(w.v, w.v, 0x55), w.v)));
    float a;
    a = z.ratio * z.ratio;
    SolverVector dA;
    dA.sub(kIter.ropeAnchorA, kIter.pivotA);
    SolverVector dB;
    dB.sub(kIter.pivotB, kIter.ropeAnchorB);
    float mass;
    mass = a * pBodyB->inverseInertia.f[3] + pBodyA->inverseInertia.f[3] + 1.1920928955078125e-7;
    float fDenominator;
    fDenominator = mass + val;
    error->angularA.f[3] = z.massFactor / fDenominator;
    float lengthA, lengthB;
    _mm_store_ss(&lengthA, _mm_sqrt_ss(squared3(dA.v)));
    _mm_store_ss(&lengthB, _mm_sqrt_ss(squared3(dB.v)));
    float p;
    p = z.ratio * lengthB + lengthA;
    float ratio2;
    ratio2 = p - kIter.separation;
    error->linearA.f[3] = ratio2 * z.biasFactor;
    float* length;
    length = (float*)*cursor;
    *cursor = (SolverRecord*)(16 + length);
    *length += 1.1920928955078125e-7;
    *(unsigned char*)length = 11;
}
extern SolverGeometry* getGeometry();
extern SolverSettings* getSettings();
extern SolverBody* getAnchorA();
extern SolverBody* getAnchorB();
extern SolverRecord** getCursor();
void SolverWrite_use()
{
    Hkpbuildjacobianfromatoms_BuildPulleySolverRecord(getGeometry(), getAnchorA(), getSettings(), getAnchorB(), getCursor());
}

extern "C" void _ReadWriteBarrier();
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" double sqrt(double);
extern float DAT_0104da4c;
extern float DAT_010d33e0[];
extern float DAT_010d33d8[];
extern float DAT_010d33e4;
extern double DAT_0103c7c8;

struct ConstraintSource
{
    unsigned char unk00, unk01, unk02, indexA, indexB, mode, limitOffset, unk07;
    float value08, value0c, scale;
};
struct ConstraintDest
{
    union
    {
        __m128 axis;
        float axisValues[4];
    };
    float value10, value14, angle, scale;
};
struct ConstraintContext
{
    int unk00, unk04, unk08;
    float timestep;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    float scale;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    struct LimitValues* limits;
};
struct LimitValues
{
    float base0, base1;
};
struct VectorInput
{
    __m128* p;
    VectorInput(__m128* v) : p(v)
    {}
};
// Computes axis-angle rotation from two vectors, applies mode scaling and optional limit clamping, returning 1 if vectors are parallel.
// @fnv 0x00d6d720
// src: GUESS 0x00d6d720 (confidence: medium)
static __declspec(noinline) int Object_ComputeLimitedAxisAngle(ConstraintSource* apSource, ConstraintDest* out,
                                             ConstraintContext* apContext, VectorInput a, VectorInput b)
{
    unsigned long result;
    float epsilon = DAT_0104da4c;
    const __m128& aAxis = a.p[apSource->indexA];
    const __m128& bAxis = b.p[apSource->indexB];
    __m128 crossAxis = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(bAxis, bAxis, 0xd2), _mm_shuffle_ps(aAxis, aAxis, 0xc9)),
                                  _mm_mul_ps(_mm_shuffle_ps(bAxis, bAxis, 0xc9), _mm_shuffle_ps(aAxis, aAxis, 0xd2)));
    __m128 square = _mm_mul_ps(crossAxis, crossAxis);
    float len2;
    _mm_store_ss(&len2, _mm_add_ss(_mm_shuffle_ps(square, square, 0xaa),
                                   _mm_add_ss(_mm_shuffle_ps(square, square, 0x55), square)));
    if (epsilon > len2)
        result = 1;
    else
    {
        __m128 prod = _mm_mul_ps(bAxis, aAxis);
        float dot;
        _mm_store_ss(&dot,
                     _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod)));
        unsigned modeIndex = apSource->mode;

        float length;
        length = (float)sqrt((double)len2);
        float angle = Atan2(length, dot) * DAT_010d33e0[modeIndex] + DAT_010d33d8[modeIndex];
        dot = (&DAT_010d33e4)[-apSource->mode];
        out->scale = apContext->scale * apSource->scale;
        __m128 sign = _mm_load_ss(&dot);
        sign = _mm_shuffle_ps(sign, sign, 0);
        float inverseLength = 1.0f / length;
        __m128 inverse = _mm_load_ss(&inverseLength);
        out->angle = angle;
        out->axis = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(inverse, inverse, 0), crossAxis), sign);
        out->value10 = apSource->value08;
        out->value14 = apSource->value0c;
        result = 0;
        unsigned char ucLimitOffset = apSource->limitOffset;
        if (ucLimitOffset > 1)
        {
            unsigned offset = ucLimitOffset;
            float* pLimitValue = (float*)((unsigned char*)apContext->limits + offset);
            float negativeBase;
            float current = *pLimitValue;
            negativeBase = -apContext->limits->base1;
            float delta = angle - current;
            float remaining = negativeBase - delta;
            float halfStep = (float)(apContext->timestep * 0.5);
            float scaledCurrent = (float)(current * DAT_0103c7c8);
            float half = scaledCurrent > halfStep ? scaledCurrent : halfStep;
            current -= half;
            float threshold = (float)((halfStep + 2.0 * half) * 0.5);
            float upper;
            upper = delta + half;
            if (-remaining > threshold && negativeBase != 0.0f)
            {
                current -= remaining;
                upper += remaining;
            }
            _ReadWriteBarrier();
            if (!(current > 1.192092896e-07f))
                current = 1.192092896e-07f;
            *(float*)((unsigned char*)apContext->limits + offset) = current;
            out->angle = upper;
        }
    }
    return result;
}
void ConstraintCaller(ConstraintSource* s, ConstraintDest* o, ConstraintContext* c, __m128* a, __m128* b)
{
    Object_ComputeLimitedAxisAngle(s, o, c, a, b);
}

extern "C" __m128 _mm_load_ps(const float*);
extern "C"
{
    extern __m128 _mm_add_ps(__m128 _A, __m128 _B);
    extern __m128 _mm_add_ss(__m128 _A, __m128 _B);
    extern __m128 _mm_andnot_ps(__m128 _A, __m128 _B);
    extern __m128 _mm_cmpeq_ss(__m128 _A, __m128 _B);
    extern __m128 _mm_load_ps1(float const* _A);
    extern __m128 _mm_load_ss(float const* _A);
    extern __m128 _mm_mul_ps(__m128 _A, __m128 _B);
    extern __m128 _mm_mul_ss(__m128 _A, __m128 _B);
    extern __m128 _mm_rsqrt_ss(__m128 _A);
    extern __m128 _mm_set_ss(float _A);
    extern __m128 _mm_shuffle_ps(__m128 _A, __m128 _B, unsigned int _Imm8);
    extern __m128 _mm_sqrt_ss(__m128 _A);
    extern void _mm_store_ss(float* _V, __m128 _A);
    extern __m128 _mm_sub_ps(__m128 _A, __m128 _B);
    extern __m128 _mm_sub_ss(__m128 _A, __m128 _B);
    extern __m128 _mm_xor_ps(__m128 _A, __m128 _B);
}

struct hkVec4
{
    union
    {
        __m128 q;
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
    };
    void operator=(const hkVec4& v)
    {
        q = v.q;
    }
    hkVec4* hkVector4_setRotatedDir(const struct hkTransF* t, const hkVec4* v);
    hkVec4* hkVector4_setMul3(const struct hkRot* m, const hkVec4* v);
};
struct hkVec4F
{
    float x;
    float y;
    float z;
    float w;
};
union hkVec4Copy
{
    __m128 q;
    hkVec4F f;
};
struct hkTrans
{
    hkVec4 m_kColumn0;
    hkVec4 m_kColumn1;
    hkVec4 m_kColumn2;
    hkVec4 m_vTranslation;
    hkVec4& col(int i)
    {
        return (&m_kColumn0)[i];
    }
    const hkVec4& col(int i) const
    {
        return (&m_kColumn0)[i];
    }
};
struct hkTransF
{
    hkVec4F m_kColumn0;
    hkVec4F m_kColumn1;
    hkVec4F m_kColumn2;
    hkVec4F m_vTranslation;
    const hkVec4F& col(int i) const
    {
        return (&m_kColumn0)[i];
    }
};
// local form of hkMatrix3: 0x00d6f460 needs inline column/copy operations with the original vector aliases; shared form gives 11040 bytes vs exe 11056.
struct hkRot
{
    hkVec4 m_kColumn0;
    hkVec4 m_kColumn1;
    hkVec4 m_kColumn2;
    hkVec4& col(int i)
    {
        return (&m_kColumn0)[i];
    }
    const hkVec4& col(int i) const
    {
        return (&m_kColumn0)[i];
    }
    void FUN_00cd4cc0(const hkVec4* v);
    void FUN_00cd5610(const hkRot* a, const hkRot* b);
    void Multiply(const hkVec4* s);
};
template <class T> struct ValueCell
{
    T value;
    ValueCell()
    {}
    ValueCell(T x) : value(x)
    {}
    void operator=(T x)
    {
        value = x;
    }
    operator T() const
    {
        return read();
    }
    T read() const
    {
        return value;
    }
    T operator->() const
    {
        return value;
    }
};
struct SolverResults
{
    float m_fAccumulatedImpulse;
    float m_fImpulseLimit;
};
struct Accum
{
    unsigned char m_type;
    int unk04;
    float unk08;
    hkVec4 m_vLinearVelocity;
    hkVec4 m_vAngularVelocity;
    hkVec4 m_vInverseInertiaAndMass;
    hkVec4 m_kCenterPosition;
    hkVec4 m_rot[3];
    Accum* CopySelectedFields(const Accum* src);
    Accum* InitializeFields_00d72030(const Accum* src);
};
struct QueryIn
{
    float m_subStepDeltaTime;
    float m_subStepInvDeltaTime;
    float m_fFirstQueryValue;
    float m_fSecondQueryValue;
    float m_fInverseStepCount;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float m_fThirdQueryValue;
    float unk28;
    float unk2c;
    const Accum* m_pBodyA;
    const Accum* m_pBodyB;
    const hkTransF* m_kBodyALocalFrame;
    const hkTransF* m_kBodyBLocalFrame;
    float m_fTau;
    float m_fMotorDamping;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    SolverResults* m_pByteBuffer;
    int unk68;
    int unk6c;
    int unk70;
    SolverResults* m_pUserData;
    int unk78;
    int unk7c;
};
struct QueryOut
{
    char* m_pQueryResultSchema;
};
struct SolverSchemaType
{
    unsigned char m_type;
    unsigned char m_flag;
};
struct SchemaHeader
{
    float m_word0;
    unsigned short m_low;
    unsigned short m_high;
    SolverResults* m_pRuntime;
    int m_whole;
};
struct SchemaNop
{
    float m_word0;
    unsigned char m_uiItemCount;
    int unk08;
    int unk0c;
};
struct SchemaAng
{
    hkVec4 m_angA;
    hkVec4 m_angB;
    float m_kMinimumCorner;
    float m_kMaximumCorner;
    float m_fTau;
};
struct SchemaMotor
{
    hkVec4 m_angA;
    hkVec4 m_angB;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
};
struct SchemaPulley
{
    hkVec4 m_linA;
    hkVec4 m_linB;
    hkVec4 m_angA;
    hkVec4 m_angB;
};
#include "../../../../../../include/hkBool.h"
struct Atom
{
    unsigned short m_type;
};
struct BridgeAtom
{
    unsigned short m_type;
    void(__cdecl* m_pBridge)(void* data, const QueryIn* in, QueryOut* out);
    void* m_pConstraintData;
};
struct LocalTransformsAtom
{
    unsigned short m_type;
    hkTrans m_kBodyALocalFrame;
    hkTrans m_kBodyBLocalFrame;
};
struct LocalTranslationsAtom
{
    unsigned short m_type;
    hkVec4 m_kTranslationA;
    hkVec4 m_kTranslationB;
};
struct LocalRotationsAtom
{
    unsigned short m_type;
    hkVec4 m_kRotationA[3];
    hkVec4 m_kRotationB[3];
};
struct BallSocketAtom
{
    unsigned short m_type;
    unsigned char m_solvingMethod;
    unsigned char m_ucBodiesToNotify;
    float m_usFlags;
};
struct StiffSpringAtom
{
    unsigned short m_type;
    float m_fRestLength;
};
struct LinAtom
{
    unsigned short m_type;
    unsigned char m_ucAxisIndex;
};
struct LinSoftAtom
{
    unsigned short m_type;
    unsigned char m_ucAxisIndex;
    float m_fTau;
    float m_fMotorDamping;
};
struct LinLimitAtom
{
    unsigned short m_type;
    unsigned char m_ucAxisIndex;
    float m_kMinimumCorner;
    float m_kMaximumCorner;
};
struct LinFrictionAtom
{
    unsigned short m_type;
    unsigned char m_bLimitEnabled;
    unsigned char m_ucFrictionAxis;
    float m_fFriction;
};
struct Motor
{
    void* m_dispatch;
    unsigned short m_allocation;
    short m_sReferenceCount;
    signed char m_kind;
};
struct LinMotorAtom
{
    unsigned short m_type;
    unsigned char m_bLimitEnabled;
    unsigned char m_ucMotorAxis;
    short m_iInitializedOffset;
    short m_sPreviousTargetPositionOffset;
    float m_vVector;
    Motor* m_pMotor;
};
struct TwoDAngAtom
{
    unsigned short m_type;
    unsigned char m_ucFreeRotationAxis;
};
struct AngAtom
{
    unsigned short m_type;
    unsigned char m_ucFirstConstrainedAxis;
    unsigned char m_ucNumConstrainedAxes;
};
struct AngLimitAtom
{
    unsigned short m_type;
    unsigned char m_bLimitEnabled;
    unsigned char m_ucLimitAxis;
    float m_fMinAngle;
    float m_fMaxAngle;
    float m_fAngularLimitsTauFactor;
};
struct TwistLimitAtom
{
    unsigned short m_type;
    unsigned char m_bLimitEnabled;
    unsigned char m_ucTwistAxis;
    unsigned char m_ucReferenceAxis;
    float m_fMinAngle;
    float m_fMaxAngle;
    float m_fAngularLimitsTauFactor;
};
struct ConeLimitAtom
{
    unsigned short m_type;
    unsigned char m_bLimitEnabled;
    unsigned char m_ucMemOffsetToAngleOffset;
    unsigned char m_ucMemOffsetToOldAngleOffset;
    unsigned char m_ucMemOffsetToFirstConstrainedDof;
    unsigned char m_ucAngleMeasurementMode;
    float m_fMinAngle;
    float m_fMaxAngle;
    float m_fAngularLimitsTauFactor;
};
struct AngFrictionAtom
{
    unsigned short m_type;
    unsigned char m_bLimitEnabled;
    unsigned char m_ucFirstFrictionAxis;
    unsigned char m_ucNumFrictionAxes;
    float m_fMaxFrictionTorque;
};
struct AngMotorAtom
{
    unsigned short m_type;
    unsigned char m_bLimitEnabled;
    unsigned char m_ucMotorAxis;
    short m_iInitializedOffset;
    short m_iPreviousTargetAngleOffset;
    short m_iCorrespondingAngLimitSolverResultOffset;
    float m_fTargetAngle;
    Motor* m_pMotor;
};
struct RagdollMotorAtom
{
    unsigned short m_type;
    unsigned char m_bLimitEnabled;
    short m_iInitializedOffset;
    short m_iPreviousTargetAnglesOffset;
    hkRot m_kMotorAxes;
    Motor* m_ppMotors[3];
};
struct PulleyAtom
{
    unsigned short m_type;
    hkVec4 m_kFixedPivotA;
    hkVec4 m_kFixedPivotB;
    float m_fLeverageOnBodyB;
    float m_fRopeLength;
};
struct ModifierAtom
{
    unsigned short m_type;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short m_usModifierAtomSize;
    unsigned short m_iChildSize;
    const Atom* m_pChildAtom;
    int unk18;
    int unk1c;
};
struct SoftContactAtom
{
    ModifierAtom m_base;
    float m_fTau;
    float m_fDamping;
    int unk28;
    int unk2c;
};
struct MassChangerAtom
{
    ModifierAtom m_base;
    hkVec4F m_kFactorA;
    hkVec4F m_kFactorB;
};
struct MovingSurfaceAtom
{
    ModifierAtom m_base;
    hkVec4F m_fVelocity;
};
struct CenterOfMassChangerAtom
{
    ModifierAtom m_base;
    hkVec4 m_kDisplacementA;
    hkVec4 m_kDisplacementB;
};
struct AlignedPairData
{
    hkVec4 m_vContactPosition;
    hkVec4F m_vSeparatingNormal;
};
struct ContactPointProps
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float m_usFlags;
};
struct ContactAtom
{
    unsigned short m_type;
    unsigned short unk02;
    unsigned short m_usNumContactPoints;
    unsigned short m_usMaxNumContactPoints;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char m_ucContactPointPropertiesStriding;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    AlignedPairData m_kPoints[1];
};
struct BallSocketInfo
{
    hkVec4 m_kPivotA;
    hkVec4 m_kPivotB;
};
struct StiffSpringInfo
{
    hkVec4 m_kPivotA;
    hkVec4 m_kPivotB;
    hkVec4 m_dir;
};
struct LinInfo
{
    hkVec4 m_kPivotA;
    hkVec4 m_kPivotB;
    hkVec4 m_kAxisEndPoints;
    float m_f30;
    float m_f34;
};
struct LinFrictionInfo
{
    hkVec4 m_kPivotVector;
    hkVec4 m_kAxisEndPoints;
    float m_fFriction;
    SolverResults* m_pRuntime;
};
struct AngInfo
{
    hkVec4 m_kPointA;
    hkVec4 m_kPointB;
    hkVec4 m_iThirdValue;
};
struct AngLimitInfo
{
    hkVec4 m_kAxisEndPoints;
    float m_kMinimumCorner;
    float m_kMaximumCorner;
    float m_fThirdScalar;
    float m_fTau;
};
struct AngFrictionInfo
{
    const hkVec4* m_axes;
    SolverResults* m_pRuntime;
    float m_fMaxFrictionTorque;
    int m_numAxes;
};
struct RagStatus
{
    ValueCell<float> m_fStatusValue;
};
struct MotorInput : public RagStatus
{
    const QueryIn* m_pStepInfo;
    SolverResults m_previous;
    float m_fTargetVelocity;
    float m_fMaxImpulse;
    MotorInput()
    {
        m_previous.m_fAccumulatedImpulse = 0.0f;
        m_previous.m_fImpulseLimit = 0.0f;
    }
};
struct MotorOutput
{
    ValueCell<float> m_f00;
    ValueCell<float> m_f04;
    ValueCell<float> m_f08;
    ValueCell<float> m_f0c;
    ValueCell<float> m_f10;
    ValueCell<float> m_f14;
};

extern const unsigned char DAT_010d33c0[];
extern float DAT_01016248;
struct PulleyInfo
{
    hkVec4 m_fixedPivotA;
    hkVec4 m_fixedPivotB;
    float m_fLeverageOnBodyB;
    float m_leverage;
};
struct PulleyScale
{
    float m_leverage;
    float m_dt;
    float m_rhs;
};
void __cdecl hkMatrix3_MultiplyMatrixColumns(hkRot* out, const hkTransF* t, const hkRot* m);
void __cdecl Hkp1dbilateralconstraintbuildjacobian_BuildJacobianAndAdvance(StiffSpringInfo* info, const QueryIn* in, QueryOut* out, float error);
void __cdecl hk1dLinearBilateralConstraintBuildJacobian(LinInfo* info, const QueryIn* in, QueryOut* out);
void __cdecl ComputeAngularJacobian(LinInfo* info, const QueryIn* in, QueryOut* out);
void __cdecl hk1dLinearLimitBuildJacobian(LinInfo* info, const QueryIn* in, QueryOut* out);
void __cdecl hk1dLinearFrictionBuildJacobian(LinFrictionInfo* info, const QueryIn* in, QueryOut* out);
void __cdecl hk1dAngularBilateralConstraintBuildJacobian(AngInfo* info, const QueryIn* in, QueryOut* out);
void __cdecl Hkp1dbilateralconstraintbuildjacobian_BuildRotatedVertexJacobianPairs(AngFrictionInfo* info, const QueryIn* in, QueryOut* out);
void __cdecl ComputeJacobian(const hkVec4* axis, const hkVec4* pivot, const QueryIn* in, char* schemas,
                             MotorInput* min);
void __cdecl _hkCalcMotorData(Motor* motor, MotorInput* min, MotorOutput* mout);
void __cdecl _hk1dLinearVelocityMotorCommitJacobian(MotorOutput* mout, const QueryIn* in, char* schemas, QueryOut* out);
void __cdecl WriteVector(const hkRot* a, const hkRot* b, QueryOut* out);
void __cdecl Hkpbuildjacobianfromatoms_WriteVectorPairRecordAndAdvance(const hkVec4* a, const hkVec4* b, QueryOut* out);
void __cdecl Hkpbuildjacobianfromatoms_WriteType1ARecordAndAdvance(const hkVec4* v, int which, QueryOut* out);
void __cdecl hkSimpleContactConstraintDataBuildJacobian(const Atom* atom, const QueryIn* in, hkBool writeHeader, QueryOut* out);
void __cdecl _hkSimpleContactConstraintDataAddALittleSurfaceViscosity(void* p);
void __cdecl hkSolverBuildJacobianFromAtomsNotContact(const Atom* atoms, int sizeOfAllAtoms, const QueryIn* queryIn, QueryOut* out);

extern "C" int __stdcall bs_index(int handle, int flag);
extern float DAT_010c7948[];
// src: GUESS 0x00d6ced0 (confidence: medium)
static __declspec(noinline) void hkVector4_BuildConstraintRowsAndCheckSpeedLimit(const BallSocketAtom* atom, const QueryIn* in, const hkTrans* baseA,
                                              const hkTrans* baseB, QueryOut* out)
{
    float maxImpulse = atom->m_usFlags;
    float tau = DAT_010c7948[atom->m_ucBodiesToNotify] * (1.0f / in->unk20);
    char* schemas = out->m_pQueryResultSchema;
    const Accum* bodyB = in->m_pBodyB;
    const Accum* bodyA = in->m_pBodyA;
    hkVec4 rA;
    rA.q = _mm_sub_ps(baseA->col(3).q, bodyA->m_kCenterPosition.q);
    hkVec4 rB;
    rB.q = _mm_sub_ps(baseB->col(3).q, bodyB->m_kCenterPosition.q);
    hkVector4 mA;
    mA.hkVector4_setRotatedInverseDir(reinterpret_cast<const hkRotation&>(bodyA->m_rot[0]), reinterpret_cast<const hkVector4&>(bodyA->m_vAngularVelocity));
    hkVector4 mB;
    mB.hkVector4_setRotatedInverseDir(reinterpret_cast<const hkRotation&>(bodyB->m_rot[0]), reinterpret_cast<const hkVector4&>(bodyB->m_vAngularVelocity));
    int handle = in->unk68;
    if (handle)
    {
        int r = bs_index(handle, 1);
        if (r < 0x80)
        {
            ((int*)in->unk68)[r + 1] = in->unk60;
        }
    }
    SchemaNop* s = (SchemaNop*)schemas;
    s[0].m_word0 = maxImpulse * tau * in->m_fThirdQueryValue + baseA->col(0).x + rA.x + bodyA->unk08 +
                   bodyA->m_vInverseInertiaAndMass.x + bodyA->m_vInverseInertiaAndMass.y +
                   bodyA->m_vInverseInertiaAndMass.z + bodyA->m_kCenterPosition.x + bodyA->m_kCenterPosition.y;
    s[0].unk08 = bodyA->unk04 + in->unk6c;
    s[1].m_word0 = baseB->col(1).y + rB.y + baseA->col(2).z;
    out->m_pQueryResultSchema = (char*)(s + 3);
}
static __forceinline void setHeader(SchemaHeader* h, int whole, int low, int high, SolverResults* runtime,
                                    unsigned char size)
{
    h->m_word0 = h->m_word0 + 1.192092896e-07f;
    ((SolverSchemaType*)h)->m_type = 1;
    h->m_low = (unsigned short)low;
    h->m_pRuntime = runtime;
    h->m_high = (unsigned short)high;
    h->m_whole = whole;
    ((SolverSchemaType*)h)->m_flag = size;
}
// src: GUESS 0x00d6ea30 (confidence: medium)
static __declspec(noinline) void Hkpbuildjacobianfromatoms_WriteTypeOneRecordAndAdvance(const QueryIn* in, QueryOut* out, SolverResults* runtime,
                                              unsigned char size)
{
    SchemaHeader* h = (SchemaHeader*)out->m_pQueryResultSchema;
    setHeader(h, in->unk60, in->unk6c, in->unk70, runtime, size);
    out->m_pQueryResultSchema = (char*)(h + 1);
}
static __forceinline void copyTransform(hkTrans& d, const hkTransF& s)
{
    const hkVec4 r0 = *(const hkVec4*)&s.m_kColumn0;
    const hkVec4 r1 = *(const hkVec4*)&s.m_kColumn1;
    const hkVec4 r2 = *(const hkVec4*)&s.m_kColumn2;
    const hkVec4 r3 = *(const hkVec4*)&s.m_vTranslation;
    d.col(0) = r0;
    d.col(1) = r1;
    d.col(2) = r2;
    d.col(3) = r3;
}
static __forceinline __m128 splat(float f)
{
    return _mm_load_ps1(&f);
}
static __forceinline __m128 dot3(__m128 a, __m128 b)
{
    __m128 x2 = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
}
template <typename T> static __forceinline T max2(T x, T y)
{
    return x > y ? x : y;
}
static __forceinline void copyRot(hkRot& d, const hkRot& s)
{
    d.col(0) = s.col(0);
    d.col(1) = s.col(1);
    d.col(2) = s.col(2);
}
static __forceinline __m128 normalize3(__m128 v)
{
    __m128 len2 = dot3(v, v);
    __m128 r = _mm_rsqrt_ss(len2);
    __m128 mask = _mm_cmpeq_ss(len2, _mm_set_ss(DAT_01011d78));
    __m128 inv = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(DAT_01016248), r),
                            _mm_sub_ss(_mm_set_ss(DAT_01017718), _mm_mul_ss(_mm_mul_ss(len2, r), r)));
    __m128 sel = _mm_andnot_ps(mask, inv);
    return _mm_mul_ps(_mm_shuffle_ps(sel, sel, 0), v);
}
static __forceinline __m128 cross(__m128 a, __m128 b)
{
    const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(cross0, cross1);
}
struct SimdReal
{
    __m128 m_vValue;
    __forceinline SimdReal(__m128 v) : m_vValue(v)
    {}
    __forceinline operator float() const
    {
        float f;
        _mm_store_ss(&f, m_vValue);
        return f;
    }
};
static __forceinline float toFloat(__m128 v)
{
    float f;
    _mm_store_ss(&f, v);
    return f;
}
static __forceinline void writeNop(QueryOut* out, unsigned char n)
{
    SchemaNop* s = (SchemaNop*)out->m_pQueryResultSchema;
    s->m_word0 = s->m_word0 + 1.192092896e-07f;
    s->m_uiItemCount = n;
    ((SolverSchemaType*)s)->m_type = 3;
    out->m_pQueryResultSchema = (char*)(s + 1);
}
static __forceinline void rotateToAngular(hkVec4& dst, __m128 axis, const Accum* body)
{
    __m128 r = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(axis, axis, 0x55), body->m_rot[1].q),
                          _mm_mul_ps(_mm_shuffle_ps(axis, axis, 0), body->m_rot[0].q));
    r = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(axis, axis, 0xaa), body->m_rot[2].q));
    dst.q = r;
}
static __forceinline float angularInvMass(const hkVec4& a, const hkVec4& b, const QueryIn& in)
{
    __m128 ja = a.q;
    __m128 jb = b.q;
    __m128 s = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(ja, ja), in.m_pBodyA->m_vInverseInertiaAndMass.q),
                          _mm_mul_ps(_mm_mul_ps(jb, jb), in.m_pBodyB->m_vInverseInertiaAndMass.q));
    return toFloat(_mm_add_ss(_mm_shuffle_ps(s, s, 0xaa), _mm_add_ss(_mm_shuffle_ps(s, s, 0x55), s)));
}
static __forceinline void initializeAngular(SchemaAng* target, const SchemaAng& source, float minimum, float maximum,
                                            float tau)
{
    target->m_angA = source.m_angA;
    target->m_angB = source.m_angB;
    target->m_kMinimumCorner = minimum;
    target->m_kMaximumCorner = maximum;
    target->m_fTau = tau;
    target->m_angA.x = target->m_angA.x + 1.192092896e-07f;
    ((SolverSchemaType*)target)->m_type = 0xd;
}
static __forceinline void buildAngLimit(const AngLimitInfo& info, const QueryIn& in, QueryOut* out)
{
    __m128 axis = info.m_kAxisEndPoints.q;
    const Accum* bodyA = in.m_pBodyA;
    const Accum* bodyB = in.m_pBodyB;
    SchemaAng* s = (SchemaAng*)out->m_pQueryResultSchema;
    __m128 neg_axis = _mm_xor_ps(axis, DAT_010c44d0);
    rotateToAngular(s->m_angA, axis, bodyA);
    rotateToAngular(s->m_angB, neg_axis, bodyB);
    __m128 ja = s->m_angA.q;
    __m128 jb = s->m_angB.q;
    __m128 sum = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(ja, ja), bodyA->m_vInverseInertiaAndMass.q),
                            _mm_mul_ps(_mm_mul_ps(jb, jb), bodyB->m_vInverseInertiaAndMass.q));
    float m = toFloat(_mm_add_ss(_mm_shuffle_ps(sum, sum, 0xaa), _mm_add_ss(_mm_shuffle_ps(sum, sum, 0x55), sum)));
    float eps = 1.192092896e-07f;
    float tau = info.m_fTau;
    float invMass = m + eps;
    s->m_angA.w = tau / invMass;
    float dt = -in.m_fFirstQueryValue;
    double minimum = info.m_kMinimumCorner * dt * tau;
    double maximum = info.m_kMaximumCorner * dt * tau;
    double rhs = info.m_fThirdScalar * dt;
    s->m_angB.w = rhs;
    s = (SchemaAng*)out->m_pQueryResultSchema;
    out->m_pQueryResultSchema = (char*)(s + 1);
    initializeAngular(s, *s, minimum, maximum, tau);
}
static __forceinline void buildMotorSchema(const hkVec4& axis, const QueryIn& in, QueryOut* out, MotorInput& min)
{
    SchemaMotor* s = (SchemaMotor*)out->m_pQueryResultSchema;
    __m128 a = axis.q;
    __m128 neg_a = _mm_xor_ps(a, DAT_010c44d0);
    rotateToAngular(s->m_angA, a, in.m_pBodyA);
    rotateToAngular(s->m_angB, neg_a, in.m_pBodyB);
    float m = angularInvMass(s->m_angA, s->m_angB, in);
    float invMass = 1.0f / (float)(m + 1.192092896e-07f);
    s->m_angA.w = invMass;
    min.m_fStatusValue = invMass;
}
static __forceinline float wrapAngle(float angle, float zero)
{
    while (zero - angle > 3.14159274f)
    {
        angle += 6.28318548f;
    }
    while (angle - zero > 3.14159274f)
    {
        angle -= 6.28318548f;
    }
    return angle;
}
static __forceinline void case1(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const BridgeAtom* a = (const BridgeAtom*)atoms;
    out->m_pQueryResultSchema -= 16;
    a->m_pBridge(a->m_pConstraintData, &in, out);
    in.m_pByteBuffer += 100000;
    atoms = (const Atom*)(a + 1);
    in.m_pUserData += 100000;
}
static __forceinline void case2(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const LocalTransformsAtom* a = (const LocalTransformsAtom*)atoms;
    {
        const hkTransF* t = in.m_kBodyALocalFrame;
        __m128 c0 = ((const hkVec4*)&t->col(0))->q;
        __m128 c1 = ((const hkVec4*)&t->col(1))->q;
        __m128 c2 = ((const hkVec4*)&t->col(2))->q;
        for (int i = 3; i >= 0; i--)
        {
            __m128 v = ((const hkVec4*)&a->m_kBodyALocalFrame.col(i))->q;
            __m128 s1 = _mm_shuffle_ps(v, v, 0x55);
            __m128 s0 = _mm_shuffle_ps(v, v, 0);
            __m128 r = _mm_add_ps(_mm_mul_ps(s0, c0), _mm_mul_ps(s1, c1));
            r = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c2));
            baseA.col(i).q = r;
        }
        baseA.col(3).q = _mm_add_ps(((const hkVec4*)&t->col(3))->q, baseA.col(3).q);
    }
    {
        const hkTransF* t = in.m_kBodyBLocalFrame;
        __m128 c0 = ((const hkVec4*)&t->col(0))->q;
        __m128 c1 = ((const hkVec4*)&t->col(1))->q;
        __m128 c2 = ((const hkVec4*)&t->col(2))->q;
        for (int i = 3; i >= 0; i--)
        {
            __m128 v = ((const hkVec4*)&a->m_kBodyBLocalFrame.col(i))->q;
            __m128 s1 = _mm_shuffle_ps(v, v, 0x55);
            __m128 s0 = _mm_shuffle_ps(v, v, 0);
            __m128 r = _mm_add_ps(_mm_mul_ps(s0, c0), _mm_mul_ps(s1, c1));
            r = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c2));
            baseB.col(i).q = r;
        }
        baseB.col(3).q = _mm_add_ps(((const hkVec4*)&t->col(3))->q, baseB.col(3).q);
    }
    atoms = (const Atom*)(a + 1);
}
static __forceinline void case3(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const LocalTranslationsAtom* a = (const LocalTranslationsAtom*)atoms;
    {
        const hkTransF* t = in.m_kBodyALocalFrame;
        __m128 v = a->m_kTranslationA.q;
        __m128 r = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), ((const hkVec4*)&t->col(1))->q),
                              _mm_mul_ps(_mm_shuffle_ps(v, v, 0), ((const hkVec4*)&t->col(0))->q));
        r = _mm_add_ps(r, _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), ((const hkVec4*)&t->col(2))->q),
                                     ((const hkVec4*)&t->col(3))->q));
        baseA.col(3).q = r;
    }
    {
        const hkTransF* t = in.m_kBodyBLocalFrame;
        __m128 v = a->m_kTranslationB.q;
        __m128 r = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), ((const hkVec4*)&t->col(1))->q),
                              _mm_mul_ps(_mm_shuffle_ps(v, v, 0), ((const hkVec4*)&t->col(0))->q));
        r = _mm_add_ps(r, _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), ((const hkVec4*)&t->col(2))->q),
                                     ((const hkVec4*)&t->col(3))->q));
        baseB.col(3).q = r;
    }
    atoms = (const Atom*)(a + 1);
}
struct RotCache
{
    __m128 x, y, z;
    __forceinline RotCache(const hkTransF* t)
        : x(((const hkVec4*)&t->col(0))->q), y(((const hkVec4*)&t->col(1))->q), z(((const hkVec4*)&t->col(2))->q)
    {}
    __forceinline void reset(const hkTransF* t)
    {
        x = ((const hkVec4*)&t->col(0))->q;
        y = ((const hkVec4*)&t->col(1))->q;
        z = ((const hkVec4*)&t->col(2))->q;
    }
};
class RotInput
{
    __m128 bits;

  public:
    __forceinline operator __m128() const
    {
        return bits;
    }
    __forceinline void apply(const RotCache& matrix, const RotInput& value)
    {
        __m128 v = value;
        __m128 px = _mm_mul_ps(matrix.x, _mm_shuffle_ps(v, v, 0));
        __m128 py = _mm_mul_ps(matrix.y, _mm_shuffle_ps(v, v, 0x55));
        __m128 pz = _mm_mul_ps(matrix.z, _mm_shuffle_ps(v, v, 0xaa));
        bits = _mm_add_ps(_mm_add_ps(px, py), pz);
    }
};
static __forceinline void case4(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const LocalRotationsAtom* a = (const LocalRotationsAtom*)atoms;
    RotCache cache(in.m_kBodyALocalFrame);
    for (int i = 3; i >= 0; --i)
        ((RotInput*)&baseA.col(i))->apply(cache, ((const RotInput*)a->m_kRotationA)[i]);

    cache.reset(in.m_kBodyBLocalFrame);

    for (int i = 3; i >= 0; --i)
        ((RotInput*)&baseB.col(i))->apply(cache, ((const RotInput*)a->m_kRotationB)[i]);

    atoms = (const Atom*)(a + 1);
}
static __forceinline void case5(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const BallSocketAtom* a = (const BallSocketAtom*)atoms;
    hkVector4_BuildConstraintRowsAndCheckSpeedLimit(a, &in, &baseA, &baseB, out);
    atoms = (const Atom*)(a + 1);
    in.m_pByteBuffer += 3;
    in.m_pUserData += 3;
}
static __forceinline void case6(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const StiffSpringAtom* a = (const StiffSpringAtom*)atoms;
    StiffSpringInfo info;
    __m128 pA = baseA.col(3).q;
    __m128 pB = baseB.col(3).q;
    info.m_kPivotA.q = pA;
    info.m_kPivotB.q = pB;
    __m128 d = _mm_sub_ps(pA, pB);
    float len = toFloat(_mm_sqrt_ss(dot3(d, d)));
    if (len <= 1.192092896e-07f)
    {
        info.m_dir.q = DAT_01268370[0];
        len = 0.0f;
    }
    else
    {
        info.m_dir.q = d;
        __declspec(align(16)) float inv = 1.0f / len;
        __m128 s = _mm_load_ss(&inv);
        info.m_dir.q = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), d);
    }
    float error = a->m_fRestLength - len;
    Hkp1dbilateralconstraintbuildjacobian_BuildJacobianAndAdvance(&info, &in, out, error);
    in.m_pByteBuffer += 1;
    atoms = (const Atom*)(a + 1);
    in.m_pUserData += 1;
}
static __forceinline void case7(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const LinAtom* a = (const LinAtom*)atoms;
    LinInfo info;
    info.m_kPivotA.q = baseA.col(3).q;
    info.m_kPivotB.q = baseB.col(3).q;
    info.m_kAxisEndPoints.q = baseB.col(a->m_ucAxisIndex).q;
    hk1dLinearBilateralConstraintBuildJacobian(&info, &in, out);
    in.m_pByteBuffer += 1;
    atoms = (const Atom*)((const char*)a + 4);
    in.m_pUserData += 1;
}
static __forceinline void case8(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const LinSoftAtom* a = (const LinSoftAtom*)atoms;
    LinInfo info;
    info.m_kPivotA.q = baseA.col(3).q;
    info.m_kPivotB.q = baseB.col(3).q;
    info.m_kAxisEndPoints.q = baseB.col(a->m_ucAxisIndex).q;
    info.m_f30 = a->m_fTau;
    info.m_f34 = a->m_fMotorDamping;
    ComputeAngularJacobian(&info, &in, out);
    in.m_pByteBuffer += 1;
    atoms = (const Atom*)(a + 1);
    in.m_pUserData += 1;
}
static __forceinline void case9(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const LinLimitAtom* a = (const LinLimitAtom*)atoms;
    LinInfo info;
    info.m_kPivotA.q = baseA.col(3).q;
    info.m_kPivotB.q = baseB.col(3).q;
    info.m_kAxisEndPoints.q = baseB.col(a->m_ucAxisIndex).q;
    info.m_f30 = a->m_kMinimumCorner;
    info.m_f34 = a->m_kMaximumCorner;
    hk1dLinearLimitBuildJacobian(&info, &in, out);
    in.m_pByteBuffer += 1;
    atoms = (const Atom*)(a + 1);
    in.m_pUserData += 1;
}
static __forceinline void case10(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const LinFrictionAtom* a = (const LinFrictionAtom*)atoms;
    if (a->m_bLimitEnabled && a->m_fFriction > 0.0f)
    {
        LinFrictionInfo info;
        info.m_kPivotVector.q = baseA.col(3).q;
        info.m_kAxisEndPoints.q = baseB.col(a->m_ucFrictionAxis).q;
        info.m_fFriction = a->m_fFriction;
        info.m_pRuntime = in.m_pByteBuffer;
        hk1dLinearFrictionBuildJacobian(&info, &in, out);
    }
    else
    {
        writeNop(out, 1);
    }
    in.m_pByteBuffer += 1;
    atoms = (const Atom*)(a + 1);
    in.m_pUserData += 1;
}
static __forceinline void case11(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const LinMotorAtom* a = (const LinMotorAtom*)atoms;
    char* initialized = (char*)in.m_pByteBuffer + a->m_iInitializedOffset;
    float* previousTargetPosition = (float*)((char*)in.m_pByteBuffer + a->m_sPreviousTargetPositionOffset);
    if (a->m_bLimitEnabled && a->m_pMotor)
    {
        Motor* motor = a->m_pMotor;
        if (!*initialized)
        {
            *previousTargetPosition = a->m_vVector;
        }
        MotorInput min;
        char* schemas = out->m_pQueryResultSchema;
        ComputeJacobian(&baseB.col(a->m_ucMotorAxis), &baseA.col(3), &in, schemas, &min);
        min.m_pStepInfo = &in;
        min.m_previous = *in.m_pByteBuffer;
        min.m_fTargetVelocity = a->m_vVector - *previousTargetPosition;
        min.m_fMaxImpulse = *previousTargetPosition -
                            toFloat(dot3(_mm_sub_ps(baseA.col(3).q, baseB.col(3).q), baseB.col(a->m_ucMotorAxis).q));
        MotorOutput mout;
        _hkCalcMotorData(motor, &min, &mout);
        _hk1dLinearVelocityMotorCommitJacobian(&mout, &in, schemas, out);
        if (*previousTargetPosition != a->m_vVector || !*initialized)
        {
            *previousTargetPosition = a->m_vVector;
            *initialized = 1;
        }
    }
    else
    {
        writeNop(out, 1);
    }
    in.m_pByteBuffer += 1;
    atoms = (const Atom*)(a + 1);
    in.m_pUserData += 1;
}
static __forceinline void case12(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const TwoDAngAtom* a = (const TwoDAngAtom*)atoms;
    int freeAxis = a->m_ucFreeRotationAxis;
    const char* bb = (const char*)&baseB;
    int o1 = DAT_010d33c0[freeAxis + 1];
    int o2 = DAT_010d33c0[freeAxis + 2];
    AngInfo info;
    info.m_kPointA.q = baseA.col(freeAxis).q;
    info.m_iThirdValue.q = ((const hkVec4*)(bb + o1))->q;
    info.m_kPointB.q = ((const hkVec4*)(bb + o2))->q;
    hk1dAngularBilateralConstraintBuildJacobian(&info, &in, out);
    info.m_iThirdValue.q = ((const hkVec4*)(bb + o2))->q;
    __m128 mask = DAT_010c44d0;
    info.m_kPointB.q = _mm_xor_ps(mask, ((const hkVec4*)(bb + o1))->q);
    hk1dAngularBilateralConstraintBuildJacobian(&info, &in, out);
    in.m_pByteBuffer += 2;
    atoms = (const Atom*)((const char*)a + 4);
    in.m_pUserData += 2;
}
static __forceinline void case13(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const AngAtom* a = (const AngAtom*)atoms;
    for (int i = a->m_ucFirstConstrainedAxis; i < a->m_ucFirstConstrainedAxis + a->m_ucNumConstrainedAxes; i++)
    {
        AngInfo info;
        info.m_kPointB.q = ((const hkVec4*)((const char*)&baseA + DAT_010d33c0[i]))->q;
        info.m_kPointA.q = ((const hkVec4*)((const char*)&baseA + DAT_010d33c0[i + 1]))->q;
        info.m_iThirdValue.q = ((const hkVec4*)((const char*)&baseB + DAT_010d33c0[i + 2]))->q;
        hk1dAngularBilateralConstraintBuildJacobian(&info, &in, out);
    }
    atoms = (const Atom*)((const char*)a + 4);
    in.m_pByteBuffer += a->m_ucNumConstrainedAxes;
    in.m_pUserData += a->m_ucNumConstrainedAxes;
}
static __forceinline int case14(const Atom* atoms, const QueryIn& in, const hkTrans& baseA, const hkTrans& baseB,
                                AngLimitInfo& info, QueryOut* out)
{
    const AngLimitAtom* a = (const AngLimitAtom*)atoms;
    int failed;
    if (a->m_bLimitEnabled)
    {
        int axis = a->m_ucLimitAxis;
        const hkVec4& perpBv = *(const hkVec4*)((const char*)&baseB + DAT_010d33c0[axis + 2]);
        const hkVec4& perpAv = *(const hkVec4*)((const char*)&baseA + DAT_010d33c0[axis + 1]);
        info.m_fTau = a->m_fAngularLimitsTauFactor * in.m_fTau;
        info.m_kMinimumCorner = a->m_fMinAngle;
        info.m_kMaximumCorner = a->m_fMaxAngle;
        info.m_kAxisEndPoints.q = baseA.col(axis).q;
        __m128 perpA = perpAv.q;
        __m128 perpB = perpBv.q;
        __m128 x2 = _mm_mul_ps(perpB, perpA);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        __m128 c = cross(perpB, baseB.col(axis).q);
        float cosA = toFloat(_mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xy));
        float sinA = toFloat(dot3(c, perpA));
        info.m_fThirdScalar = Atan2(cosA, sinA);
        float zero = in.m_pByteBuffer->m_fImpulseLimit * -1.0f;
        while (zero - info.m_fThirdScalar > 3.14159274f)
        {
            info.m_fThirdScalar += 6.28318548f;
        }
        while (info.m_fThirdScalar - zero > 3.14159274f)
        {
            info.m_fThirdScalar -= 6.28318548f;
        }
        failed = 0;
    }
    else
    {
        failed = 1;
    }
    return failed;
}
struct ConeScaled : hkVec4
{
    __forceinline ConeScaled(float f, const hkVec4& v)
    {
        __m128 a = _mm_load_ss(&f);
        q = _mm_mul_ps(_mm_shuffle_ps(a, a, 0), v.q);
    }
};
static __forceinline void scaleCone(hkVec4& in, float factor)
{
    __m128 q = _mm_load_ss(&factor);
    in.q = _mm_mul_ps(_mm_shuffle_ps(q, q, 0), in.q);
}
static __forceinline int case16(const Atom* atoms, const QueryIn& in, const hkTrans& baseA, const hkTrans& baseB,
                                AngLimitInfo& info, QueryOut* out)
{
    const ConeLimitAtom* a = (const ConeLimitAtom*)atoms;
    int failed;
    const hkVec4* twistA = &baseA.col(a->m_ucMemOffsetToAngleOffset);
    const hkVec4* refB = &baseB.col(a->m_ucMemOffsetToOldAngleOffset);
    hkVec4 crossAB;
    crossAB.q = cross(twistA->q, refB->q);
    float len2 = toFloat(dot3(crossAB.q, crossAB.q));
    if (len2 < 1.192092896e-07f)
    {
        failed = 1;
    }
    else
    {
        int mode = a->m_ucMemOffsetToFirstConstrainedDof;
        float cosA = toFloat(dot3(twistA->q, refB->q));
        float sinA = (float)sqrt((double)len2);
        float angle = Atan2(sinA, cosA) * DAT_010d33e0[mode] + DAT_010d33d8[mode];
        float sign = DAT_010d33e0[1 - a->m_ucMemOffsetToFirstConstrainedDof];
        failed = 0;
        info.m_fTau = a->m_fAngularLimitsTauFactor * in.m_fTau;
        float invLen = 1.0f / sinA;
        scaleCone(crossAB, invLen);
        info.m_kAxisEndPoints = ConeScaled(sign, crossAB);
        info.m_fThirdScalar = angle;
        info.m_kMinimumCorner = a->m_fMinAngle;
        info.m_kMaximumCorner = a->m_fMaxAngle;

        if (a->m_ucAngleMeasurementMode > 1)
        {
            float lo = *(float*)((char*)in.m_pByteBuffer + a->m_ucAngleMeasurementMode);
            float zero = -in.m_pByteBuffer->m_fImpulseLimit;
            float hi = angle - lo;
            float excess = zero - hi;
            float h = (float)(in.m_fSecondQueryValue * 0.5);
            float o = (float)(lo * double(0.05f));
            float m = max2(o, h);
            lo = lo - m;
            hi = hi + m;
            float k = (float)(0.5 * (h + m * 2.0f));
            if (-excess > k && zero != 0.0f)
            {
                lo = lo - excess;
                hi = excess + hi;
            }
            lo = max2(lo, 1.192092896e-07f);
            *(float*)((char*)in.m_pByteBuffer + a->m_ucAngleMeasurementMode) = lo;
            info.m_fThirdScalar = hi;
        }
    }
    return failed;
}
static __forceinline int case15(const Atom* atoms, const QueryIn& in, const hkTrans& baseA, const hkTrans& baseB,
                                AngLimitInfo& info, QueryOut* out)
{
    const TwistLimitAtom* a = (const TwistLimitAtom*)atoms;
    const hkVec4* refB = &baseB.col(a->m_ucReferenceAxis);
    const hkVec4* refA = &baseA.col(a->m_ucReferenceAxis);
    info.m_kMinimumCorner = a->m_fMinAngle;
    info.m_kMaximumCorner = a->m_fMaxAngle;
    __m128 axisB = baseB.col(a->m_ucTwistAxis).q;
    __m128 sum = _mm_add_ps(baseA.col(a->m_ucTwistAxis).q, axisB);
    float len = toFloat(_mm_sqrt_ss(dot3(sum, sum)));
    hkVec4 axis;
    ValueCell<float> halfLen;
    if (len > 1e-16f)
    {
        halfLen = (float)(len * 0.5);
        axis.q = _mm_mul_ps(splat(1.0f / len), sum);
    }
    else
    {
        halfLen = 0.0f;
        axis.q = axisB;
    }
    hkVec4 c[2];
    c[0].q = cross(axis.q, refB->q);
    c[1].q = cross(c[0].q, axis.q);
    __m128 ra = refA->q;
    float sinT = toFloat(dot3(ra, c[0].q));
    float cosT = toFloat(dot3(ra, c[1].q));
    info.m_fThirdScalar = Atan2(sinT, cosT);
    info.m_fTau = a->m_fAngularLimitsTauFactor * in.m_fTau * halfLen * halfLen;
    info.m_kAxisEndPoints.q = axis.q;
    return 0;
}
static __forceinline void case17(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const AngFrictionAtom* a = (const AngFrictionAtom*)atoms;
    if (a->m_bLimitEnabled && a->m_fMaxFrictionTorque != 0.0f)
    {
        AngFrictionInfo info;
        info.m_fMaxFrictionTorque = a->m_fMaxFrictionTorque;
        info.m_axes = &baseA.col(a->m_ucFirstFrictionAxis);
        info.m_numAxes = a->m_ucNumFrictionAxes;
        info.m_pRuntime = in.m_pByteBuffer;
        Hkp1dbilateralconstraintbuildjacobian_BuildRotatedVertexJacobianPairs(&info, &in, out);
    }
    else
    {
        writeNop(out, a->m_ucNumFrictionAxes);
    }
    atoms = (const Atom*)(a + 1);
    in.m_pByteBuffer += a->m_ucNumFrictionAxes;
    in.m_pUserData += a->m_ucNumFrictionAxes;
}
static __forceinline __m128 crossRef(const hkVec4& a, const hkVec4& b)
{
    const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2));
    const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9));
    return _mm_sub_ps(cross0, cross1);
}
static __forceinline void rotateRef(hkVec4& dst, const Accum* body, const hkVec4& v)
{
    __m128 r = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v.q, v.q, 0x55), body->m_rot[1].q),
                          _mm_mul_ps(_mm_shuffle_ps(v.q, v.q, 0), body->m_rot[0].q));
    r = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(v.q, v.q, 0xaa), body->m_rot[2].q));
    dst.q = r;
}
static __forceinline float buildAngMotorJac(SchemaMotor* s, const hkVec4& axis, const Accum* bodyA, const Accum* bodyB)
{
    hkVec4 neg_ax;
    neg_ax.q = _mm_xor_ps(axis.q, DAT_010c44d0);
    rotateRef(s->m_angA, bodyA, axis);
    rotateRef(s->m_angB, bodyB, neg_ax);
    __m128 ma = _mm_mul_ps(_mm_mul_ps(s->m_angA.q, s->m_angA.q), bodyA->m_vInverseInertiaAndMass.q);
    __m128 mb = _mm_mul_ps(_mm_mul_ps(s->m_angB.q, s->m_angB.q), bodyB->m_vInverseInertiaAndMass.q);
    __m128 m = _mm_add_ps(ma, mb);
    float invMass =
        1.0f / (float)(toFloat(_mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m))) +
                       1.192092896e-07f);
    s->m_angA.w = invMass;
    return invMass;
}
static __forceinline void case18(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const AngMotorAtom* a = (const AngMotorAtom*)atoms;
    float* previousTargetAngle = (float*)((char*)in.m_pByteBuffer + a->m_iPreviousTargetAngleOffset);
    char* initialized = (char*)in.m_pByteBuffer + a->m_iInitializedOffset;
    Motor* motor = a->m_pMotor;
    if (motor && a->m_bLimitEnabled)
    {
        int axis = a->m_ucMotorAxis;
        const hkVec4* perpA = (const hkVec4*)((const char*)&baseA + DAT_010d33c0[axis + 1]);
        const hkVec4* perpB = (const hkVec4*)((const char*)&baseB + DAT_010d33c0[axis + 2]);
        float cosA = toFloat(dot3(perpA->q, perpB->q));
        const hkVec4* axisB = &baseB.col(axis);
        float sinA = toFloat(dot3(crossRef(*perpB, *axisB), perpA->q));
        float angle = Atan2(cosA, sinA);
        short limitOffset = a->m_iCorrespondingAngLimitSolverResultOffset;
        if (limitOffset)
        {
            float zero = ((const SolverResults*)((char*)in.m_pByteBuffer + limitOffset))->m_fImpulseLimit * -1.0f;
            while (zero - angle > 3.14159274f)
            {
                angle += 6.28318548f;
            }
            while (angle - zero > 3.14159274f)
            {
                angle -= 6.28318548f;
            }
        }
        if (!*initialized)
        {
            *previousTargetAngle = angle;
        }
        MotorInput min;
        SchemaMotor* s = (SchemaMotor*)out->m_pQueryResultSchema;
        min.m_fStatusValue = buildAngMotorJac(s, baseA.col(a->m_ucMotorAxis), in.m_pBodyA, in.m_pBodyB);
        min.m_pStepInfo = &in;
        min.m_previous = *in.m_pByteBuffer;
        min.m_fTargetVelocity = a->m_fTargetAngle - *previousTargetAngle;
        min.m_fMaxImpulse = *previousTargetAngle - angle;
        MotorOutput mout;
        _hkCalcMotorData(motor, &min, &mout);
        s->m_angB.w = mout.m_f00.value * in.m_fFirstQueryValue;
        SchemaMotor* t = (SchemaMotor*)out->m_pQueryResultSchema;
        t->m_angA.x = t->m_angA.x + 1.192092896e-07f;
        ((SolverSchemaType*)t)->m_type = 0xf;
        t++;
        out->m_pQueryResultSchema = (char*)t;
        t[-1].m_f20 = in.m_subStepInvDeltaTime * mout.m_f08;
        t[-1].m_f24 = mout.m_f0c.value * in.m_subStepInvDeltaTime;
        t[-1].m_f28 = mout.m_f04;
        t[-1].m_f2c = mout.m_f10;
        t[-1].m_f30 = mout.m_f14;
        if (*previousTargetAngle != a->m_fTargetAngle || !*initialized)
        {
            *previousTargetAngle = a->m_fTargetAngle;
            *initialized = 1;
        }
    }
    else
    {
        writeNop(out, 1);
    }
    in.m_pByteBuffer += 1;
    atoms = (const Atom*)(a + 1);
    in.m_pUserData += 1;
}
static __forceinline float ragdollInvMass(const hkVec4& a, const hkVec4& b, const Accum* bodyA, const Accum* bodyB)
{
    __m128 ja = a.q;
    __m128 jb = b.q;
    __m128 s = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(ja, ja), bodyA->m_vInverseInertiaAndMass.q),
                          _mm_mul_ps(_mm_mul_ps(jb, jb), bodyB->m_vInverseInertiaAndMass.q));
    return toFloat(_mm_add_ss(_mm_shuffle_ps(s, s, 0xaa), _mm_add_ss(_mm_shuffle_ps(s, s, 0x55), s)));
}
static __forceinline void ragdollRelative(const hkVec4& axisA, const hkVec4& axisB, const hkVec4& planeA,
                                          const hkVec4& planeB, hkVec4& selected, float& angleOut, float& scaleOut)
{
    hkVec4 unit;
    unit.q = _mm_add_ps(axisB.q, axisA.q);
    float length = toFloat(_mm_sqrt_ss(dot3(unit.q, unit.q)));
    if (length > 1e-16f)
    {
        scaleOut = length * 0.5f;
        float inverse = 1.0f / length;
        __m128 f = _mm_load_ss(&inverse);
        unit.q = _mm_mul_ps(_mm_shuffle_ps(f, f, 0), unit.q);
    }
    else
    {
        scaleOut = 0.0f;
        unit = axisB;
    }
    hkRot frame;
    hkVec4& cross0 = frame.col(0);
    hkVec4& cross1 = frame.col(1);
    hkVec4& cross2 = frame.col(2);
    cross0 = unit;
    cross1.q = cross(unit.q, planeB.q);
    cross2.q = cross(cross1.q, cross0.q);
    float p = toFloat(dot3(cross1.q, planeA.q));
    float q = toFloat(dot3(cross2.q, planeA.q));
    selected = unit;
    angleOut = Atan2(p, q);
}
static __forceinline __m128 commitFirstAngle(char* initialized, float* previous, float angle, int i, const Accum*& bA,
                                             const Accum*& bB, const QueryIn& q)
{
    __m128 sign;
    if (!initialized[i])
    {
        previous[i] = angle;
        initialized[i] = 1;
        bA = q.m_pBodyA;
        sign = DAT_010c44d0;
        bB = q.m_pBodyB;
    }
    else
    {
        bA = q.m_pBodyA;
        sign = DAT_010c44d0;
        bB = q.m_pBodyB;
    }
    return sign;
}
static __forceinline ValueCell<float>& setMotorMass102(ValueCell<float>& destination, float value)
{
    destination = value;
    return destination;
}
static __forceinline void case19(const Atom*& atoms, QueryIn& input, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    QueryIn& in = input;
    const RagdollMotorAtom* a = (const RagdollMotorAtom*)atoms;
    char* initialized = (char*)in.m_pByteBuffer + a->m_iInitializedOffset;
    float* previousTargetAngles = (float*)((char*)in.m_pByteBuffer + a->m_iPreviousTargetAnglesOffset);
    if (a->m_bLimitEnabled)
    {
        hkRot target;
        hkMatrix3_MultiplyMatrixColumns(&target, in.m_kBodyBLocalFrame, &a->m_kMotorAxes);
        MotorInput min;
        min.m_pStepInfo = &in;
        int axisIndex[3] = {0, 1, 2};
        int refIndex[3] = {1, 0, 0};
        for (int i = 0; i < 3; i++)
        {
            Motor* motor = a->m_ppMotors[i];
            if (motor)
            {
                hkVec4 motorAxis;
                float angleData[1];
                float scale0;
                ragdollRelative(baseA.col(axisIndex[i]), baseB.col(axisIndex[i]), baseA.col(refIndex[i]),
                                baseB.col(refIndex[i]), motorAxis, angleData[0], scale0);
                float targetData[1];
                float scale1;

                ragdollRelative(target.col(axisIndex[i]), baseB.col(axisIndex[i]), target.col(refIndex[i]),
                                baseB.col(refIndex[i]), motorAxis, targetData[0], scale1);
                const Accum* bodyA;
                const Accum* bodyB;
                __m128 mk = commitFirstAngle(initialized, previousTargetAngles, angleData[0], i, bodyA, bodyB, in);
                SchemaMotor* s = (SchemaMotor*)out->m_pQueryResultSchema;
                __m128 m = motorAxis.q;
                __m128 neg_m = _mm_xor_ps(mk, m);
                rotateToAngular(s->m_angA, m, bodyA);
                rotateToAngular(s->m_angB, neg_m, bodyB);
                float invMass = 1.0f / (float)(ragdollInvMass(s->m_angA, s->m_angB, bodyA, bodyB) + 1.192092896e-07f);
                s->m_angA.w = invMass;
                setMotorMass102(min.m_fStatusValue, invMass);
                min.m_previous = in.m_pByteBuffer[i];
                min.m_fTargetVelocity = targetData[0] - previousTargetAngles[i];
                min.m_fMaxImpulse = previousTargetAngles[i] - angleData[0];
                MotorOutput mout;
                _hkCalcMotorData(motor, &min, &mout);
                s->m_angB.w = mout.m_f00 * in.m_fFirstQueryValue;
                SchemaMotor* t = (SchemaMotor*)out->m_pQueryResultSchema;
                t->m_angA.x = t->m_angA.x + 1.192092896e-07f;
                ((SolverSchemaType*)t)->m_type = 0xf;
                t++;
                out->m_pQueryResultSchema = (char*)t;
                t[-1].m_f20 = mout.m_f08 * in.m_subStepInvDeltaTime;
                t[-1].m_f24 = mout.m_f0c.value * in.m_subStepInvDeltaTime;
                t[-1].m_f28 = mout.m_f04;
                t[-1].m_f2c = mout.m_f10;
                t[-1].m_f30 = mout.m_f14;
                if (previousTargetAngles[i] != targetData[0])
                {
                    previousTargetAngles[i] = targetData[0];
                }
            }
            else
            {
                writeNop(out, 1);
            }
        }
    }
    else
    {
        writeNop(out, 3);
    }
    atoms = (const Atom*)(a + 1);
    in.m_pByteBuffer += 3;
    in.m_pUserData += 3;
}
static __forceinline __m128 normalize3_c20(__m128 v)
{
    const __m128 half = _mm_set_ss(0.5f);
    const __m128 three = _mm_set_ss(3.0f);
    const __m128 zero = _mm_load_ss(&DAT_01011d78);
    __m128 len2 = dot3(v, v);
    __m128 isZero = _mm_cmpeq_ss(len2, zero);
    __m128 r = _mm_rsqrt_ss(len2);
    __m128 inv = _mm_mul_ss(_mm_mul_ss(half, r), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, r), r)));
    __m128 sel = _mm_andnot_ps(isZero, inv);
    return _mm_mul_ps(_mm_shuffle_ps(sel, sel, 0), v);
}
struct CableVector
{
    __m128 data;
    __forceinline void operator=(const CableVector& a)
    {
        data = a.data;
    }
    __forceinline void operator=(const __m128& a)
    {
        data = a;
    }
    __forceinline void sub(const CableVector& a, const CableVector& b)
    {
        data = _mm_sub_ps(a.data, b.data);
    }
    __forceinline void scale(float f, const CableVector& a)
    {
        __m128 scale = _mm_load_ss(&f);
        data = _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), a.data);
    }
    __forceinline void crossOf(const CableVector& a, const CableVector& b)
    {
        data = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.data, a.data, 0xc9), _mm_shuffle_ps(b.data, b.data, 0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(a.data, a.data, 0xd2), _mm_shuffle_ps(b.data, b.data, 0xc9)));
    }
    __forceinline float length() const
    {
        return toFloat(_mm_sqrt_ss(dot3(data, data)));
    }
    __forceinline float lengthSquared() const
    {
        return toFloat(dot3(data, data));
    }
    __forceinline void normalize()
    {
        data = normalize3_c20(data);
    }
    __forceinline void neg(const CableVector& a)
    {
        data = _mm_xor_ps(a.data, DAT_010c44d0);
    }
};
struct CableInput
{
    CableVector positionA, positionB, fixedA, fixedB;
    ValueCell<float> rope, leverage;
};
struct CableRows
{
    const Accum* bodyA;
    const Accum* bodyB;
    CableVector positionA, positionB, dirA, dirB, fixedA, fixedB;
    float rope, leverage, dt, rhs;
};
static __forceinline void cableRows(const CableRows& info, SchemaPulley& jac)
{
    CableVector directionB;
    directionB.scale(info.leverage, info.dirB);
    *(CableVector*)&jac.m_linA = info.dirA;
    *(CableVector*)&jac.m_linB = directionB;
    CableVector relativeA, relativeB, crossA, crossB;
    relativeA.sub(info.positionA, *(const CableVector*)&info.bodyA->m_kCenterPosition);
    relativeB.sub(info.positionB, *(const CableVector*)&info.bodyB->m_kCenterPosition);
    crossA.crossOf(relativeA, info.dirA);
    crossB.crossOf(directionB, relativeB);
    rotateRef(jac.m_angA, info.bodyA, *(const hkVec4*)&crossA);
    rotateRef(jac.m_angB, info.bodyB, *(const hkVec4*)&crossB);
    __m128 ja = jac.m_angA.q;
    __m128 jb = jac.m_angB.q;
    __m128 sum = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(jb, jb), info.bodyB->m_vInverseInertiaAndMass.q),
                            _mm_mul_ps(_mm_mul_ps(ja, ja), info.bodyA->m_vInverseInertiaAndMass.q));
    float angular =
        toFloat(_mm_add_ss(_mm_shuffle_ps(sum, sum, 0xaa), _mm_add_ss(_mm_shuffle_ps(sum, sum, 0x55), sum)));
    float mass = info.leverage * info.leverage;
    mass = mass * info.bodyB->m_vInverseInertiaAndMass.w + info.bodyA->m_vInverseInertiaAndMass.w + 1.192092896e-07f;
    mass = mass + angular;
    jac.m_angA.w = info.rhs / mass;
    CableVector diffA, diffB;
    diffA.sub(info.fixedA, info.positionA);
    diffB.sub(info.positionB, info.fixedB);
    float length = diffA.length();
    length = diffB.length() * info.leverage + length;
    length = length - info.rope;
    jac.m_linA.w = length * info.dt;
}
static __forceinline void cablePrepare(const CableInput& setup, const QueryIn& in, QueryOut* out)
{
    const Accum* bodyA = in.m_pBodyA;
    const Accum* bodyB = in.m_pBodyB;
    SchemaPulley* jac = (SchemaPulley*)out->m_pQueryResultSchema;
    CableRows rows;
    __m128 dA = _mm_sub_ps(setup.fixedA.data, setup.positionA.data);
    __m128 dB = _mm_sub_ps(setup.positionB.data, setup.fixedB.data);
    __m128 dirA;
    __m128 dirB;
    if (toFloat(dot3(dA, dA)) > 1.192092896e-07f)
        dirA = normalize3_c20(dA);
    else
        dirA = DAT_01268370[0];
    dirB = DAT_01268370[0];
    if (toFloat(dot3(dB, dB)) > 1.192092896e-07f)
        dirB = normalize3_c20(dB);
    else
        dirB = _mm_xor_ps(dirB, DAT_010c44d0);
    rows.dirA = dirA;
    rows.dirB = dirB;
    rows.bodyA = bodyA;
    rows.bodyB = bodyB;
    rows.positionA = setup.positionA;
    rows.positionB = setup.positionB;
    rows.fixedA = setup.fixedA;
    rows.fixedB = setup.fixedB;
    rows.rope = setup.rope;
    rows.leverage = setup.leverage;
    rows.dt = in.m_fFirstQueryValue;
    rows.rhs = in.m_fThirdQueryValue;
    cableRows(rows, *jac);
    SchemaPulley* final = (SchemaPulley*)out->m_pQueryResultSchema;
    out->m_pQueryResultSchema = (char*)(final + 1);
    final->m_linA.x = 1.192092896e-07f + final->m_linA.x;
    ((SolverSchemaType*) final)->m_type = 0xb;
}
static __forceinline void case20(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const PulleyAtom* atom = (const PulleyAtom*)atoms;
    CableInput setup;
    setup.positionA = *(const CableVector*)&baseA.col(3);
    setup.positionB = *(const CableVector*)&baseB.col(3);
    setup.fixedA = *(const CableVector*)&atom->m_kFixedPivotA;
    setup.fixedB = *(const CableVector*)&atom->m_kFixedPivotB;
    setup.rope = atom->m_fLeverageOnBodyB;
    setup.leverage = atom->m_fRopeLength;
    cablePrepare(setup, in, out);
    atoms = (const Atom*)(atom + 1);
    in.m_pByteBuffer += 1;
    in.m_pUserData += 1;
}
class ScalarPacket
{
    __m128 value;

  public:
    __forceinline ScalarPacket(float f)
    {
        value = _mm_set_ss(f);
    }
    __forceinline operator const hkVec4&() const
    {
        return *(const hkVec4*)&value;
    }
};
struct ComMatrix
{
    hkVec4 x, y, z;
    __forceinline ComMatrix()
    {}
    __forceinline ComMatrix(const ComMatrix& a)
    {
        x = a.x;
        y = a.y;
        z = a.z;
    }
    __forceinline void operator=(const ComMatrix& a)
    {
        x = a.x;
        y = a.y;
        z = a.z;
    }
    __forceinline void skew(const hkVec4& a)
    {
        ((hkRot*)this)->FUN_00cd4cc0(&a);
    }
    __forceinline void transform(const ComMatrix& a, const hkRot& b)
    {
        ((hkRot*)this)->FUN_00cd5610((const hkRot*)&a, &b);
    }
    __forceinline void scale(const hkVec4& a)
    {
        ((hkRot*)this)->Multiply(&a);
    }
};
static __forceinline void case28(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const CenterOfMassChangerAtom* a = (const CenterOfMassChangerAtom*)atoms;
    QueryIn in6 = in;
    const Atom* child = a->m_base.m_pChildAtom;
    int childSize = a->m_base.m_iChildSize;
    hkVec4 dispA;
    dispA.hkVector4_setRotatedDir(in.m_kBodyALocalFrame, &a->m_kDisplacementA);
    hkVec4 dispB;
    dispB.hkVector4_setRotatedDir(in.m_kBodyBLocalFrame, &a->m_kDisplacementB);
    Accum accA;
    accA.CopySelectedFields(in.m_pBodyA);
    Accum accB;
    accB.CopySelectedFields(in.m_pBodyB);
    accA.m_kCenterPosition.q = _mm_add_ps(dispA.q, accA.m_kCenterPosition.q);
    accB.m_kCenterPosition.q = _mm_add_ps(dispB.q, accB.m_kCenterPosition.q);
    in6.m_pBodyA = &accA;
    in6.m_pBodyB = &accB;
    ComMatrix skewA;
    skewA.skew(dispA);
    ComMatrix skewB;
    skewB.skew(dispB);
    ComMatrix tmp(skewA);
    skewA.transform(tmp, *(const hkRot*)&accA.m_rot[0]);
    tmp = skewB;
    skewB.transform(tmp, *(const hkRot*)&accB.m_rot[0]);
    ComMatrix negA(skewA);
    hkVec4 minusOne;
    minusOne.q = _mm_load_ss(&DAT_01012054);
    negA.scale((const hkVec4&)minusOne);
    ComMatrix negB(skewB);
    hkVec4 minusOne2;
    minusOne2.q = _mm_load_ss(&DAT_01012054);
    negB.scale((const hkVec4&)minusOne2);
    hkVec4 dvA;
    dvA.hkVector4_setMul3((const hkRot*)&negA, &accA.m_vAngularVelocity);
    hkVec4 dvB;
    dvB.hkVector4_setMul3((const hkRot*)&negB, &accB.m_vAngularVelocity);
    accA.m_vLinearVelocity.q = _mm_add_ps(accA.m_vLinearVelocity.q, dvA.q);
    accB.m_vLinearVelocity.q = _mm_add_ps(accB.m_vLinearVelocity.q, dvB.q);
    WriteVector((const hkRot*)&negA, (const hkRot*)&negB, out);
    if (child->m_type == 0x16)
    {
        hkSimpleContactConstraintDataBuildJacobian(child, &in6, hkBool(true), out);
    }
    else
    {
        hkSolverBuildJacobianFromAtomsNotContact(child, childSize, &in6, out);
    }
    WriteVector((const hkRot*)&skewA, (const hkRot*)&skewB, out);
    atoms = (const Atom*)(a + 1);
}
static __forceinline void case23(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const SoftContactAtom* a = (const SoftContactAtom*)atoms;
    out->m_pQueryResultSchema -= 16;
    QueryIn in2 = in;
    float tauFactor = a->m_fTau;
    in2.m_fThirdQueryValue = tauFactor * in.m_fThirdQueryValue;
    in2.m_fTau = tauFactor * in.m_fTau;
    int childSize = a->m_base.m_iChildSize;
    in2.m_fMotorDamping = tauFactor * in.m_fMotorDamping;
    const Atom* c = (const Atom*)a;
    do
    {
        c = ((const ModifierAtom*)c)->m_pChildAtom;
    } while (c->m_type >= 0x17);
    const ContactAtom* contact = (const ContactAtom*)c;
    int numPoints = contact->m_usNumContactPoints;
    int striding = contact->m_ucContactPointPropertiesStriding;
    ContactPointProps* props = (ContactPointProps*)&contact->m_kPoints[contact->m_usMaxNumContactPoints];
    for (int i = 0; i < numPoints; i++)
    {
        float dist = contact->m_kPoints[i].m_vSeparatingNormal.w;
        float maxPen = a->m_fDamping * in.m_subStepInvDeltaTime * in.m_subStepDeltaTime / a->m_fTau;
        if (props->m_usFlags > maxPen + dist)
        {
            props->m_usFlags = maxPen + dist;
        }
        props = (ContactPointProps*)((char*)props + striding);
    }
    const Atom* child = a->m_base.m_pChildAtom;
    if (child->m_type == 0x16)
    {
        hkSimpleContactConstraintDataBuildJacobian(child, &in2, hkBool(true), out);
    }
    else
    {
        hkSolverBuildJacobianFromAtomsNotContact(child, childSize, &in2, out);
    }
    atoms = (const Atom*)(a + 1);
}
static __forceinline void case25(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const ModifierAtom* a = (const ModifierAtom*)atoms;
    out->m_pQueryResultSchema -= 16;
    QueryIn in4 = in;
    int childSize = a->m_iChildSize;
    const Atom* c = (const Atom*)a;
    do
    {
        c = ((const ModifierAtom*)c)->m_pChildAtom;
    } while (c->m_type >= 0x17);
    _hkSimpleContactConstraintDataAddALittleSurfaceViscosity((void*)&((const ContactAtom*)c)->unk10);
    const Atom* child = a->m_pChildAtom;
    if (child->m_type == 0x16)
    {
        hkSimpleContactConstraintDataBuildJacobian(child, &in4, hkBool(true), out);
    }
    else
    {
        hkSolverBuildJacobianFromAtomsNotContact(child, childSize, &in4, out);
    }
    atoms = (const Atom*)((const char*)a + 0x20);
}
static __forceinline void case24(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const MassChangerAtom* a = (const MassChangerAtom*)atoms;
    QueryIn in3 = in;
    const Atom* child = a->m_base.m_pChildAtom;
    int childSize = a->m_base.m_iChildSize;
    hkVec4 factorA;
    hkVec4 factorB;
    *(hkVec4F*)&factorA = a->m_kFactorA;
    *(hkVec4F*)&factorB = a->m_kFactorB;
    Accum accA;
    accA.CopySelectedFields(in.m_pBodyA);
    Accum accB;
    accB.CopySelectedFields(in.m_pBodyB);
    accA.m_vInverseInertiaAndMass.q = _mm_mul_ps(accA.m_vInverseInertiaAndMass.q, factorA.q);
    in3.m_pBodyA = &accA;
    in3.m_pBodyB = &accB;
    accB.m_vInverseInertiaAndMass.q = _mm_mul_ps(accB.m_vInverseInertiaAndMass.q, factorB.q);
    Hkpbuildjacobianfromatoms_WriteVectorPairRecordAndAdvance(&accA.m_vInverseInertiaAndMass, &accB.m_vInverseInertiaAndMass, out);
    if (child->m_type == 0x16)
    {
        hkSimpleContactConstraintDataBuildJacobian(child, &in3, hkBool(true), out);
    }
    else
    {
        hkSolverBuildJacobianFromAtomsNotContact(child, childSize, &in3, out);
    }
    Hkpbuildjacobianfromatoms_WriteVectorPairRecordAndAdvance(&in.m_pBodyA->m_vInverseInertiaAndMass, &in.m_pBodyB->m_vInverseInertiaAndMass, out);
    atoms = (const Atom*)(a + 1);
}
class SurfaceAxis
{
    __m128 q;

  public:
    __forceinline operator __m128() const
    {
        return q;
    }
    __forceinline void operator=(__m128 v)
    {
        q = v;
    }
};
static __forceinline void case26(const Atom*& atoms, QueryIn& in, hkTrans& baseA, hkTrans& baseB, QueryOut* out)
{
    const MovingSurfaceAtom* a = (const MovingSurfaceAtom*)atoms;
    hkVec4 velocity;
    *(hkVec4F*)&velocity = a->m_fVelocity;
    QueryIn in5 = in;
    const ContactAtom* contact = (const ContactAtom*)a->m_base.m_pChildAtom;
    out->m_pQueryResultSchema -= 16;
    Hkpbuildjacobianfromatoms_WriteTypeOneRecordAndAdvance(&in, out, (SolverResults*)&contact->m_kPoints[contact->m_usMaxNumContactPoints],
                 contact->m_ucContactPointPropertiesStriding);
    bool isBodyB = in.unk6c == 0;
    Accum acc;
    if (!isBodyB)
    {
        acc.InitializeFields_00d72030(in.m_pBodyA);
        in.m_pBodyA = &acc;
    }
    else
    {
        acc.InitializeFields_00d72030(in.m_pBodyB);
        in.m_pBodyB = &acc;
        velocity.q = _mm_xor_ps(velocity.q, DAT_010c4c00);
    }
    hkVec4 normal;
    *(hkVec4F*)&normal = contact->m_kPoints[0].m_vSeparatingNormal;
    int which = isBodyB != 0;
    __m128 n = normal.q;
    __m128 v = velocity.q;
    __m128 d = dot3(n, v);
    SurfaceAxis tangent;
    tangent = _mm_xor_ps(_mm_sub_ps(v, _mm_mul_ps(_mm_shuffle_ps(d, d, 0), n)), DAT_010c44d0);
    Hkpbuildjacobianfromatoms_WriteType1ARecordAndAdvance((const hkVec4*)&tangent, which, out);
    acc.m_vLinearVelocity.q = _mm_add_ps(acc.m_vLinearVelocity.q, tangent);
    hkSimpleContactConstraintDataBuildJacobian((const Atom*)contact, &in5, hkBool(false), out);
    tangent = _mm_xor_ps(tangent, DAT_010c44d0);
    Hkpbuildjacobianfromatoms_WriteType1ARecordAndAdvance((const hkVec4*)&tangent, which, out);
    atoms = (const Atom*)((const char*)a + 0x30);
}
struct AngularStorage : AngLimitInfo
{
};
// Iterates through a sequence of physics atoms, dispatching each by type to update the query output and build angular limits.
// @fnv 0x00d6f460
// src: XBOX_PDB 0x00d6f460
void __cdecl hkSolverBuildJacobianFromAtomsNotContact(const Atom* atoms, int sizeOfAllAtoms, const QueryIn* queryIn, QueryOut* out)
{
    QueryIn in = *queryIn;
    const Atom* atomsEnd = (const Atom*)((const char*)atoms + sizeOfAllAtoms);
    hkTrans baseA;
    copyTransform(baseA, *in.m_kBodyALocalFrame);
    hkTrans baseB;
    copyTransform(baseB, *in.m_kBodyBLocalFrame);
    AngularStorage angularStorage;
    AngLimitInfo& angLimitInfo = angularStorage;
    {
        SchemaHeader* h = (SchemaHeader*)out->m_pQueryResultSchema;
        setHeader(h, in.unk60, in.unk6c, in.unk70, in.m_pByteBuffer, 8);
        out->m_pQueryResultSchema = (char*)(h + 1);
    }
    while (atoms < atomsEnd)
    {
    nextAtom:
        switch (atoms->m_type)
        {
        case 0:
            atoms = (const Atom*)(((unsigned int)atoms + 15) & ~15u);
            goto nextAtom;
        case 1:
            case1(atoms, in, baseA, baseB, out);
            break;
        case 2:
            case2(atoms, in, baseA, baseB, out);
            break;
        case 3:
            case3(atoms, in, baseA, baseB, out);
            break;
        case 4:
            case4(atoms, in, baseA, baseB, out);
            break;
        case 5:
            case5(atoms, in, baseA, baseB, out);
            break;
        case 6:
            case6(atoms, in, baseA, baseB, out);
            break;
        case 7:
            case7(atoms, in, baseA, baseB, out);
            break;
        case 8:
            case8(atoms, in, baseA, baseB, out);
            break;
        case 9:
            case9(atoms, in, baseA, baseB, out);
            break;
        case 10:
            case10(atoms, in, baseA, baseB, out);
            break;
        case 11:
            case11(atoms, in, baseA, baseB, out);
            break;
        case 12:
            case12(atoms, in, baseA, baseB, out);
            break;
        case 13:
            case13(atoms, in, baseA, baseB, out);
            break;
        case 14: {
            const AngLimitAtom* saved = (const AngLimitAtom*)atoms;
            int result = case14(atoms, in, baseA, baseB, angLimitInfo, out);
            atoms = (const Atom*)(saved + 1);
            in.m_pByteBuffer += 1;
            in.m_pUserData += 1;
            if (result == 0)
                goto buildAngLimit;
            goto angLimitNop;
        }
        case 16: {
            const ConeLimitAtom* saved = (const ConeLimitAtom*)atoms;
            int result = case16(atoms, in, baseA, baseB, angLimitInfo, out);
            atoms = (const Atom*)(saved + 1);
            in.m_pByteBuffer += 1;
            in.m_pUserData += 1;
            if (result == 0)
                goto buildAngLimit;
            goto angLimitNop;
        }
        case 15: {
            const TwistLimitAtom* saved = (const TwistLimitAtom*)atoms;
            int result = case15(atoms, in, baseA, baseB, angLimitInfo, out);
            atoms = (const Atom*)(saved + 1);
            in.m_pByteBuffer += 1;
            in.m_pUserData += 1;
            if (result == 0)
                goto buildAngLimit;
            goto angLimitNop;
        }
        case 17:
            case17(atoms, in, baseA, baseB, out);
            break;
        case 18:
            case18(atoms, in, baseA, baseB, out);
            break;
        case 19:
            case19(atoms, in, baseA, baseB, out);
            break;
        case 20:
            case20(atoms, in, baseA, baseB, out);
            break;
        case 28:
            case28(atoms, in, baseA, baseB, out);
            break;
        case 23:
            case23(atoms, in, baseA, baseB, out);
            break;
        case 25:
            case25(atoms, in, baseA, baseB, out);
            break;
        case 24:
            case24(atoms, in, baseA, baseB, out);
            break;
        case 26:
            case26(atoms, in, baseA, baseB, out);
            break;
        case 27:
            out->m_pQueryResultSchema -= 16;
            atoms = (const Atom*)((const char*)atoms + 0x20);
            break;
        default:
            break;
        buildAngLimit:
            buildAngLimit(angLimitInfo, in, out);
            break;
        angLimitNop:
            writeNop(out, 1);
            break;
        }
    }
}

namespace PulleyRowImpl {

struct PulleyRowScalar
{
    __m128 q;
    PulleyRowScalar()
    {}
    PulleyRowScalar(const __m128& v) : q(v)
    {}
    PulleyRowScalar(float f) : q(_mm_load_ss(&f))
    {}
    operator float() const
    {
        float result;
        _mm_store_ss(&result, q);
        return result;
    }
    __m128 splat() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};
struct PulleyRowBody;
union PulleyRowVector
{
    void rotate(const PulleyRowBody& b, const PulleyRowVector& v);
    __m128 vec;
    PulleyRowVector()
    {}
    PulleyRowVector(const PulleyRowVector& other) : vec(other.vec)
    {}
    void operator=(const PulleyRowVector& other)
    {
        vec = other.vec;
    }
    void sub(const PulleyRowVector& a, const PulleyRowVector& b)
    {
        vec = _mm_sub_ps(a.vec, b.vec);
    }
    PulleyRowScalar dot(const PulleyRowVector& b) const
    {
        __m128 product = _mm_mul_ps(vec, b.vec);
        __m128 yx = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
        return PulleyRowScalar(_mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), yx));
    }
    PulleyRowScalar length() const
    {
        PulleyRowScalar sum = dot(*this);
        return PulleyRowScalar(_mm_sqrt_ss(sum.q));
    }
    __forceinline PulleyRowScalar inverseLength() const
    {
        __m128 h = _mm_set_ss(0.5f), t = _mm_set_ss(3.0f), z = _mm_set_ss(0.0f);
        __m128 squared = dot(*this).q;
        __m128 mask = _mm_cmpeq_ss(squared, z);
        __m128 root = _mm_rsqrt_ss(squared);
        __m128 refined = _mm_mul_ss(_mm_mul_ss(h, root), _mm_sub_ss(t, _mm_mul_ss(_mm_mul_ss(squared, root), root)));
        return PulleyRowScalar(_mm_andnot_ps(mask, refined));
    }
    __forceinline void normalize()
    {
        __m128 broadcast = inverseLength().splat();
        vec = _mm_mul_ps(broadcast, vec);
    }
    void cross(const PulleyRowVector& a, const PulleyRowVector& b)
    {
        __m128 first = _mm_mul_ps(_mm_shuffle_ps(a.vec, a.vec, 0xc9), _mm_shuffle_ps(b.vec, b.vec, 0xd2));
        __m128 second = _mm_mul_ps(_mm_shuffle_ps(a.vec, a.vec, 0xd2), _mm_shuffle_ps(b.vec, b.vec, 0xc9));
        vec = _mm_sub_ps(first, second);
    }
};
struct PulleyRowBody
{
    PulleyRowVector unk00, unk10, unk20, invInertia, com, rot0, rot1, rot2;
};
struct PulleyRowQuery
{
    int unk00;
    float unk04;
    float tau;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    float virtMass;
    int unk28;
    int unk2c;
    PulleyRowBody* bodyA;
    PulleyRowBody* bodyB;
};
struct PulleyRowGeometry
{
    PulleyRowVector r0, r1, r2, r3;
    float restLen, leverage;
};
struct PulleyRowSchema
{
    PulleyRowVector linear0, linear1, angular0, angular1;
};
inline void PulleyRowVector::rotate(const PulleyRowBody& b, const PulleyRowVector& v)
{
    __m128 x = _mm_shuffle_ps(v.vec, v.vec, 0), y = _mm_shuffle_ps(v.vec, v.vec, 0x55),
           z = _mm_shuffle_ps(v.vec, v.vec, 0xaa);
    __m128 r0 = _mm_mul_ps(x, b.rot0.vec), r1 = _mm_mul_ps(y, b.rot1.vec), r2 = _mm_mul_ps(z, b.rot2.vec);
    vec = _mm_add_ps(_mm_add_ps(r1, r0), r2);
}
struct PulleyRowWork
{
    PulleyRowBody* bodyA;
    PulleyRowBody* bodyB;
    int unused08;
    int unused0c;
    PulleyRowVector r0, r1, n1, n2, r2, r3;
    float restLen, leverage, tau, virtMass;
};
__forceinline void makePulleyRow(const PulleyRowWork& work, PulleyRowSchema* out)
{
    const PulleyRowBody* bodyA = work.bodyA;
    const PulleyRowBody* bodyB = work.bodyB;
    PulleyRowScalar leverageScalar(work.leverage);
    PulleyRowVector dirB;
    dirB.vec = _mm_mul_ps(leverageScalar.splat(), work.n2.vec);
    out->linear1 = dirB;
    out->linear0 = work.n1;
    PulleyRowVector relA, relB;
    relA.vec = _mm_sub_ps(work.r0.vec, bodyA->com.vec);
    relB.sub(work.r1, bodyB->com);
    PulleyRowVector crossA;
    crossA.cross(relA, work.n1);
    PulleyRowVector crossB;
    __m128 rightB = _mm_mul_ps(_mm_shuffle_ps(relB.vec, relB.vec, 0xc9), _mm_shuffle_ps(dirB.vec, dirB.vec, 0xd2));
    __m128 leftB = _mm_mul_ps(_mm_shuffle_ps(relB.vec, relB.vec, 0xd2), _mm_shuffle_ps(dirB.vec, dirB.vec, 0xc9));
    crossB.vec = _mm_sub_ps(leftB, rightB);
    {
        __m128 a0 = _mm_shuffle_ps(crossA.vec, crossA.vec, 0);
        __m128 a1 = _mm_shuffle_ps(crossA.vec, crossA.vec, 0x55);
        __m128 a2 = _mm_shuffle_ps(crossA.vec, crossA.vec, 0xaa);
        __m128 p0 = _mm_mul_ps(a0, bodyA->rot0.vec);
        __m128 p1 = _mm_mul_ps(a1, bodyA->rot1.vec);
        __m128 p2 = _mm_mul_ps(a2, bodyA->rot2.vec);
        out->angular0.vec = _mm_add_ps(_mm_add_ps(p1, p0), p2);
    }
    PulleyRowVector angularB;
    {
        __m128 b0 = _mm_shuffle_ps(crossB.vec, crossB.vec, 0);
        __m128 b1 = _mm_shuffle_ps(crossB.vec, crossB.vec, 0x55);
        __m128 b2 = _mm_shuffle_ps(crossB.vec, crossB.vec, 0xaa);
        __m128 p0 = _mm_mul_ps(b0, bodyB->rot0.vec);
        __m128 p1 = _mm_mul_ps(b1, bodyB->rot1.vec);
        __m128 p2 = _mm_mul_ps(b2, bodyB->rot2.vec);
        angularB.vec = _mm_add_ps(_mm_add_ps(p1, p0), p2);
    }
    out->angular1 = angularB;
    PulleyRowVector angularA = out->angular0;
    PulleyRowVector weighted;
    weighted.vec = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(angularA.vec, angularA.vec), bodyA->invInertia.vec),
                              _mm_mul_ps(_mm_mul_ps(angularB.vec, angularB.vec), bodyB->invInertia.vec));
    float angMass;
    {
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(weighted.vec, weighted.vec, 0x55), weighted.vec);
        _mm_store_ss(&angMass, _mm_add_ss(_mm_shuffle_ps(weighted.vec, weighted.vec, 0xaa), xy));
    }
    float linearMass = work.leverage * work.leverage;
    linearMass =
        (float)(linearMass * reinterpret_cast<const PacketCallLocal_00d6d450&>(bodyB->invInertia.vec).w + reinterpret_cast<const PacketCallLocal_00d6d450&>(bodyA->invInertia.vec).w + 1.1920928955078125e-7);
    float invMass = linearMass + angMass;
    PulleyRowVector deltaA;
    deltaA.vec = _mm_sub_ps(work.r2.vec, work.r0.vec);
    PulleyRowVector deltaB;
    deltaB.vec = _mm_sub_ps(work.r1.vec, work.r3.vec);
    reinterpret_cast<PacketCallLocal_00d6d450&>(out->angular0.vec).w = work.virtMass / invMass;
    float error = float(deltaA.length()) + float(deltaB.length()) * work.leverage;
    error = error - work.restLen;
    reinterpret_cast<PacketCallLocal_00d6d450&>(out->linear0.vec).w = error * work.tau;
}
// Normalizes the two rope direction vectors, builds a pulley row from in and mat into *outCursor via makePulleyRow, and advances the cursor.
// @fnv 0x00d6e300
// src: GUESS 0x00d6e300 (confidence: low)
static __declspec(noinline) void Object_UpdateFields_00d6e300(PulleyRowQuery* apQuery, PulleyRowSchema** outCursor,
                                              PulleyRowGeometry* apGeometry)
{
    PulleyRowWork work;
    __m128 anchorA, anchorB;
    _mm_store_ps((float*)&anchorA, apGeometry->r0.vec);
    work.r2 = apGeometry->r2;
    work.r1 = apGeometry->r1;
    PulleyRowSchema* out = *outCursor;
    work.n1.vec = _mm_sub_ps(work.r2.vec, apGeometry->r0.vec);
    _mm_store_ps((float*)&anchorB, apGeometry->r3.vec);
    work.n2.vec = _mm_sub_ps(work.r1.vec, apGeometry->r3.vec);
    work.bodyA = apQuery->bodyA;
    work.bodyB = apQuery->bodyB;
    PulleyRowBody* bodyA = work.bodyA;
    PulleyRowBody* bodyB = work.bodyB;
    const __m128& fallback = ((const PulleyRowVector*)DAT_01268370)->vec;
    PulleyRowVector normalizedA;
    if (float(work.n1.dot(work.n1)) > 1.1920928955078125e-7f)
    {
        normalizedA = work.n1;
        normalizedA.normalize();
    }
    else
        normalizedA.vec = fallback;
    PulleyRowVector normalizedB;
    if (float(work.n2.dot(work.n2)) > 1.1920928955078125e-7f)
    {
        normalizedB = work.n2;
        normalizedB.normalize();
    }
    else
        normalizedB.vec = _mm_xor_ps(fallback, DAT_010c44d0);
    work.n1 = normalizedA;
    work.n2 = normalizedB;
    work.r0.vec = anchorA;
    work.r3.vec = anchorB;
    work.restLen = apGeometry->restLen;
    work.leverage = apGeometry->leverage;
    work.tau = apQuery->tau;
    work.virtMass = apQuery->virtMass;

    makePulleyRow(work, out);

    PulleyRowSchema* cur = *outCursor;
    *outCursor = cur + 1;
    reinterpret_cast<PacketCallLocal_00d6d450&>(cur->linear0.vec).x = (float)(reinterpret_cast<PacketCallLocal_00d6d450&>(cur->linear0.vec).x + 1.1920928955078125e-7);
    *(unsigned char*)cur = 0xb;
}
void PulleyRow_use(PulleyRowQuery* in, PulleyRowSchema** cursor, PulleyRowGeometry* mat)
{
    Object_UpdateFields_00d6e300(in, cursor, mat);
}
}
