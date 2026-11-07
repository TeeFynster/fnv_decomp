#define FNV64_HKVECTOR4_OWN_DEFAULT
#define FNV64_HKVECTOR4_OWN_ASSIGN
#include "../../../../../../include/hkVector4.h"
#include <string.h>

// src/havok/physics/constraintsolver/constraint/atom/hkpbuildjacobianfromatoms_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/constraintsolver/constraint/atom/hkpbuildjacobianfromatoms.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

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
void Hkpbuildjacobianfromatoms_UpdateState_00d6ce70(FUN_00d6ce70_Vector* v, FUN_00d6ce70_Scale* s, FUN_00d6ce70_Dest* dest, FUN_00d6ce70_Cursor* cursor);
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
static void WriteFloatRecord(WriterContext* object, float** cursor, WriterArgs args);
void RecordWrite_use(WriterContext* object, float** cursor, WriterArgs args);
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
static void Hkpbuildjacobianfromatoms_WriteFloatSolverRecord(S00d6d990_Src* src, S00d6d990_Rec** cur, WriterContext* obj, int a1);
void S00d6d990_Caller(S00d6d990_Src* s, S00d6d990_Rec** c, WriterContext* o, int a);
extern double _DAT_010c9300;
static void Hkpbuildjacobianfromatoms_WriteTypeOneRecordAndAdvance(WriterContext* object, float** cursor, WriterArgs args);
void RecordWriteAlt_use(WriterContext* object, float** cursor, WriterArgs args);

#include <xmmintrin.h>
struct S00d6e280_Obj
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char m_flag2;
    unsigned char m_flag3;
    float m_f4;
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
    int m_64;
};

struct S00d6e280_Other
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
    int m_64;
};

struct S00d6e280_Arg
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
    __m128 m_30;
};

struct __declspec(align(16)) S00d6e280_Call
{
    unsigned int va[4];
    unsigned int vb[4];
    float c;
    int d;
};

struct S00d6e280_Rec
{
    union
    {
        float f00;
        unsigned char type00;
    };
    unsigned char b04;
    unsigned char b05;
    unsigned short s06;
    int i08;
    int i0c;
};

extern "C" void hk1dLinearFrictionBuildJacobian(S00d6e280_Call* p, S00d6e280_Other* o, S00d6e280_Rec** cursor);

// @fnv 0x00d6e280
// src: GUESS 0x00d6e280 (confidence: low)
static __declspec(noinline) void Object_ProcessAndReturnValue_00d6e280(S00d6e280_Rec** cursor, __m128* table, S00d6e280_Obj* self,
                                              S00d6e280_Other* other, const S00d6e280_Arg* a1)
{
    if (self->m_flag2 != 0)
    {
        if (self->m_f4 > 0.0f)
        {
            S00d6e280_Call c;
            _mm_store_ps((float*)&c.va, _mm_load_ps((const float*)&a1->m_30));
            _mm_store_ps((float*)&c.vb, table[self->m_flag3]);
            c.c = self->m_f4;
            c.d = other->m_64;
            hk1dLinearFrictionBuildJacobian(&c, other, cursor);
            return;
        }
    }
    S00d6e280_Rec* rec = *cursor;
    double v = rec->f00;
    rec->b04 = 1;
    rec = rec + 1;
    (rec - 1)->f00 = (float)(v + DAT_010c9300);
    (rec - 1)->type00 = 3;
    *cursor = rec;
}

void __fastcall S00d6e280_Wrap(S00d6e280_Obj* self, S00d6e280_Other* other, S00d6e280_Arg* a1)
{
    S00d6e280_Rec* cur = 0;
    __m128* tab = 0;
    Object_ProcessAndReturnValue_00d6e280(&cur, tab, self, other, a1);
}

struct NodeKind
{
    unsigned short kind;
};
struct FnvNode
{
    short unk00;
    short unk02;
    int unk04;
    int unk08;
    int unk0c;
    short unk10;
    unsigned short unk12;
    NodeKind* unk14;
    int unk18;
    int unk1c;
    hkVector4 vec1;
    hkVector4 vec2;
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
    __m128 vec;
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
    void CopySelectedFields(FnvSubObject* src);
};
struct FnvPacket
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
    FnvSubObject* unk30;
    FnvSubObject* unk34;
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
union DispatchArgs
{
    unsigned int raw;
    unsigned char flag;
};
void __cdecl Hkpbuildjacobianfromatoms_WriteVectorPairRecordAndAdvance(__m128* a, __m128* b, void* dest);
void __cdecl hkSimpleContactConstraintDataBuildJacobian(NodeKind* node, FnvPacket* packet, DispatchArgs args, void* dest);
void __cdecl hkSolverBuildJacobianFromAtomsNotContact(NodeKind* node, DispatchArgs args, FnvPacket* packet, void* dest);

// @fnv 0x00d6ecb0
// src: GUESS 0x00d6ecb0 (confidence: low)
static __declspec(noinline) void hkSimpleContactConstraintDataBuildJacobian_CopyMemory_00d6ecb0(FnvPacket* arg1, void* arg2, FnvNode* node)
{
    FnvPacket localPacket = *arg1;
    __m128 v1;
    memcpy(&v1, &node->vec1, sizeof(v1));
    __m128 v2;
    memcpy(&v2, &node->vec2, sizeof(v2));
    NodeKind* kind = node->unk14;
    DispatchArgs args;
    args.raw = node->unk12;
    FnvSubObject obj1;
    obj1.CopySelectedFields(arg1->unk30);
    FnvSubObject obj2;
    obj2.CopySelectedFields(arg1->unk34);
    obj1.vec = _mm_mul_ps(obj1.vec, v1);
    obj2.vec = _mm_mul_ps(obj2.vec, v2);
    localPacket.unk30 = &obj1;
    localPacket.unk34 = &obj2;
    Hkpbuildjacobianfromatoms_WriteVectorPairRecordAndAdvance(&obj1.vec, &obj2.vec, arg2);
    if (kind->kind == 0x16)
    {
        args.flag = 1;
        hkSimpleContactConstraintDataBuildJacobian(kind, &localPacket, args, arg2);
    }
    else
    {
        hkSolverBuildJacobianFromAtomsNotContact(kind, args, &localPacket, arg2);
    }
    Hkpbuildjacobianfromatoms_WriteVectorPairRecordAndAdvance(&arg1->unk30->vec, &arg1->unk34->vec, arg2);
}
extern "C" FnvNode* FetchNode();
FnvPacket* volatile sourcePacket;
void* volatile sourceDest;
void TargetCaller()
{
    hkSimpleContactConstraintDataBuildJacobian_CopyMemory_00d6ecb0(sourcePacket, sourceDest, FetchNode());
}

extern const __m128 DAT_010c44d0;
struct Body337
{
    __m128 unk00, unk10, unk20;
    __m128 inverseInertia;
    __m128 unk40;
    __m128 basisX, basisY, basisZ;
};
// Solver input is 0x38 bytes with body pointers at +0x30/+0x34; include/Pair.h is two 32-bit values (0x08 bytes).
struct AngularJacobianBodyInputs
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    const Body337* first;
    const Body337* second;
};
struct Jacobian337
{
    __m128 first, second;
};
// @fnv 0x00d6cc80
// src: GUESS 0x00d6cc80 (confidence: low)
static __declspec(noinline) void Object_UpdateFields_00d6cc80(const AngularJacobianBodyInputs* pair, Jacobian337* output, const __m128* direction,
                                              float* effectiveMass)
{
    __m128 value = *direction;
    const Body337* second = pair->second;
    const Body337* first = pair->first;
    __m128 negative = _mm_xor_ps(value, DAT_010c44d0);
    __m128 rowA = _mm_mul_ps(_mm_shuffle_ps(*direction, *direction, 0x55), first->basisY);
    rowA = _mm_add_ps(rowA, _mm_mul_ps(_mm_shuffle_ps(*direction, *direction, 0), first->basisX));
    rowA = _mm_add_ps(rowA, _mm_mul_ps(_mm_shuffle_ps(*direction, *direction, 0xaa), first->basisZ));
    output->first = rowA;
    __m128 rowB = _mm_mul_ps(_mm_shuffle_ps(negative, negative, 0x55), second->basisY);
    rowB = _mm_add_ps(rowB, _mm_mul_ps(_mm_shuffle_ps(negative, negative, 0), second->basisX));
    rowB = _mm_add_ps(rowB, _mm_mul_ps(_mm_shuffle_ps(negative, negative, 0xaa), second->basisZ));
    output->second = rowB;
    __m128 contributionA = _mm_mul_ps(output->first, output->first);
    contributionA = _mm_mul_ps(contributionA, first->inverseInertia);
    __m128 contributionB = _mm_mul_ps(rowB, rowB);
    contributionB = _mm_mul_ps(contributionB, second->inverseInertia);
    __m128 total = _mm_add_ps(contributionA, contributionB);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(total, total, 0x55), total);
    sum = _mm_add_ss(_mm_shuffle_ps(total, total, 0xaa), sum);
    float scalar;
    _mm_store_ss(&scalar, sum);
    float denominator = (float)(scalar + DAT_010c9300);
    float reciprocal = 1.0f / denominator;
    output->first.m128_f32[3] = reciprocal;
    *effectiveMass = reciprocal;
}
void BuildJacobian337(const AngularJacobianBodyInputs* pair, Jacobian337* output, const __m128* direction, float* mass)
{
    Object_UpdateFields_00d6cc80(pair, output, direction, mass);
}

extern "C" float __cdecl Atan2(float a, float b);
extern const unsigned char DAT_010d33c1[];
extern const unsigned char DAT_010d33c2[];

struct Child
{
    float unk00;
    float f04;
};
struct Src
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    float f40;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    Child* child;
};
struct Mat
{
    __m128 rows[4];
};
struct Out
{
    __m128 row;
    float f10, f14, f18, f1c;
};
struct Obj
{
    unsigned char unk00, unk01, flag, axis;
    float f04, f08, f0c;
};

static __m128 cross_uv(__m128 u, __m128 v)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xD2), _mm_shuffle_ps(u, u, 0xC9)),
                      _mm_mul_ps(_mm_shuffle_ps(v, v, 0xC9), _mm_shuffle_ps(u, u, 0xD2)));
}

static float sum3(__m128 v)
{
    __m128 s = _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v);
    s = _mm_add_ss(_mm_shuffle_ps(v, v, 0xAA), s);
    float r;
    _mm_store_ss(&r, s);
    return r;
}

// @fnv 0x00d6d2e0
// src: GUESS 0x00d6d2e0 (confidence: low)
static __declspec(noinline) int Object_ProcessEntries_00d6d2e0(Obj* self, Src* src, Mat* a2, Mat* a3, Out* out)
{
    if (self->flag != 0)
    {
        unsigned axis = self->axis;
        unsigned offW = DAT_010d33c1[axis];
        unsigned offU = DAT_010d33c2[axis];
        out->f1c = src->f40 * self->f0c;
        out->row = a2->rows[axis];
        __m128 W = *(__m128*)((unsigned char*)a2 + offW);
        __m128 U = *(__m128*)((unsigned char*)a3 + offU);
        __m128 V = a3->rows[axis];
        out->f10 = self->f04;
        out->f14 = self->f08;
        float dot = sum3(_mm_mul_ps(U, W));
        float triple = sum3(_mm_mul_ps(cross_uv(U, V), W));
        out->f18 = Atan2(dot, triple);
        float n = src->child->f04 * -1.0;
        const double kPi = 3.14159265358979323846f;
        const double kTwo = 6.28318530717958647692f;
        while (n - out->f18 > kPi)
            out->f18 = (float)(out->f18 + kTwo);
        while (out->f18 - n > kPi)
            out->f18 = (float)(out->f18 - kTwo);
        return 0;
    }
    return 1;
}

extern Obj* g_obj;
extern Src* g_src;
extern Mat* g_a2;
extern Mat* g_a3;
extern Out* g_out;
int g_sink;

void zz_probe_call()
{
    g_sink = Object_ProcessEntries_00d6d2e0(g_obj, g_src, g_a2, g_a3, g_out);
}

struct S00d6f300_A
{
    short m_00;
    unsigned char m_02;
    unsigned char m_03;
    short m_04;
    short m_06;
    float m_08;
    void* m_0c;
};
struct S00d6f300_O
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
    __m128 m_30;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    unsigned char* m_64;
};
struct S00d6f300_Cmd
{
    float f;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    int u8;
    int uc;
};
struct __declspec(align(16)) S00d6f300_Real
{
    float r;
};
struct S00d6f300_B
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
    hkVector4 m_30;
};
struct S00d6f300_Pair
{
    float a;
    float b;
};
struct __declspec(align(16)) S00d6f300_Info
{
    float res;
    S00d6f300_O* o;
    S00d6f300_Pair ab;
    float c;
    float d;
    // The output starts at +0x18, below hkVector4's SIMD alignment.
    float out[4];
};
void ComputeJacobian(const __m128* n, const __m128* pos, S00d6f300_O* o, S00d6f300_Cmd* cur, S00d6f300_Info* info);
void _hkCalcMotorData(void* h, S00d6f300_Info* info, hkVector4* out);
void _hk1dLinearVelocityMotorCommitJacobian(hkVector4* out, S00d6f300_O* o, S00d6f300_Cmd* cur, S00d6f300_Cmd** p);
extern const double DAT_010c9300;

// @fnv 0x00d6f300
// src: GUESS 0x00d6f300 (confidence: low)
static __declspec(noinline) void Object_ProcessAndReturnValue_00d6f300(S00d6f300_A* s, S00d6f300_O* o, S00d6f300_B* a2, __m128* a3,
                                              S00d6f300_Cmd** p)
{
    unsigned char* base = o->m_64;
    unsigned char* a = base + s->m_04;
    float* b = (float*)(base + s->m_06);
    if (s->m_02)
    {
        void* h = s->m_0c;
        if (h)
        {
            if (*a == 0)
                *b = s->m_08;
            S00d6f300_Cmd* cur = *p;
            S00d6f300_Info info;
            info.ab.a = 0.0f;
            info.ab.b = 0.0f;
            ComputeJacobian(&a3[s->m_03], &a2->m_30.m_vComponents, o, cur, &info);
            info.o = o;
            info.ab = *(S00d6f300_Pair*)o->m_64;
            info.c = s->m_08 - *b;
            __m128 d = _mm_sub_ps(a2->m_30.m_vComponents, a3[3]);
            __m128 m = _mm_mul_ps(d, a3[s->m_03]);
            float dot;
            _mm_store_ss(&dot, _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m)));
            info.d = *b - dot;
            _hkCalcMotorData(h, &info, reinterpret_cast<hkVector4*>(info.out));
            _hk1dLinearVelocityMotorCommitJacobian(reinterpret_cast<hkVector4*>(info.out), o, cur, p);
            if (*b != s->m_08 || *a == 0)
            {
                *b = s->m_08;
                *a = 1;
            }
            return;
        }
    }
    S00d6f300_Cmd* q = *p;
    q->b4 = 1;
    q->f = (float)(q->f + DAT_010c9300);
    *(unsigned char*)q = 3;
    *p = q + 1;
}

void S00d6f300_caller(S00d6f300_A* s, S00d6f300_O* o, S00d6f300_B* a2, __m128* a3, S00d6f300_Cmd** p)
{
    Object_ProcessAndReturnValue_00d6f300(s, o, a2, a3, p);
    Object_ProcessAndReturnValue_00d6f300(s + 1, o, a2, a3, p);
}
