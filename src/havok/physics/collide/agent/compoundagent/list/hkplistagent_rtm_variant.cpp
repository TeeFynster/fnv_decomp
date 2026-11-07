// src/havok/physics/collide/agent/compoundagent/list/hkplistagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/compoundagent/list/hkplistagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent/compoundagent/list/hkplistagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/list/hkplistagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkpListAgent.h"

// Exe 0x00d369a0 vf03: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);

extern "C" void _ReadWriteBarrier();
struct S00d369a0_ShapeBase
{
    virtual void v00();
    int unk04, unk08, unk0C;
};
struct S00d369a0_Container
{
    virtual void v00();
};
struct S00d369a0_Bits : S00d369a0_ShapeBase, S00d369a0_Container
{
    int unk14;
    int unk18;
    int m1C;
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
    unsigned int m50[8];
    inline int enabled(unsigned k, unsigned int& m) const
    {
        if (k < 256)
        {
            return m50[k >> 5] & m;
        }
        return 1;
    }
};

struct S00d369a0_Motion
{
    LocalM128 c0, c1, c2, translation;
    LocalM128 v40;
    union
    {
        LocalM128 v50;
        struct
        {
            float x50, y54, z58, f5c;
        };
    };
    LocalM128 v60, v70, v80;
    union
    {
        LocalM128 v90;
        struct
        {
            float x90, y94, z98, f9c;
        };
    };
    float fa0;
};
struct S00d369a0_Body
{
    S00d369a0_Bits* m00;
    int unk04;
    S00d369a0_Motion* m08;
    int unk0C;
};
struct S00d369a0_Config
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54;
    float f58;
};

struct S00d369a0_Transform
{
    LocalM128 c0, c1, c2, translation;
    void __thiscall hkTransform_setMulInverseMul(S00d369a0_Motion* a, S00d369a0_Motion* b);
};
struct S00d369a0_ProcessInput
{
    S00d369a0_Body* a;
    S00d369a0_Body* b;
    int zero;
    S00d369a0_Config* config;
    void* cache;
    int unk14, unk18, unk1C;
    S00d369a0_Transform transform;
    LocalM128 unk60;
    LocalM128 tim;
};
extern "C" void* __cdecl hkMemoryRouter_getInstance();
extern "C" void __cdecl hkAgent1nMachine_Process(void* a, S00d369a0_ProcessInput* b, S00d369a0_Container* c, void* d, int e);
extern "C" unsigned int _rotl(unsigned int, int);
extern "C" void _ReadWriteBarrier();
// @fnv 0x00d369a0
void hkpListAgent::vf03(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                        const CollisionAgentContext& context, hkpCdBodyPairCollector& collector)
{
    S00d369a0_Body* a1 = (S00d369a0_Body*)&bodyA;
    S00d369a0_Body* a2 = (S00d369a0_Body*)&bodyB;
    S00d369a0_Config* a3 = (S00d369a0_Config*)&context;
    int a4 = (int)&collector;
    S00d369a0_ProcessInput input;
    S00d369a0_Bits* bits = a2->m00;
    input.b = a2;
    input.zero = 0;
    input.a = a1;
    float dt = a3->f58;
    input.config = a3;
    input.cache = this->m_pContactManager;
    S00d369a0_Motion* o = a1->m08;
    S00d369a0_Motion* p = a2->m08;
    LocalM128 d0 = _mm_sub_ps(o->v40, o->v50);
    LocalM128 d1 = _mm_sub_ps(p->v50, p->v40);
    float f0 = dt * o->f5c;
    float f1 = dt * p->f5c;
    input.tim = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&f0), _mm_load_ss(&f0), 0), d0);
    input.tim = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&f1), _mm_load_ss(&f1), 0), d1), input.tim);
    input.tim.m128_f32[3] = (f0 * o->f9c) * o->fa0 + (f1 * p->f9c) * p->fa0;
    input.transform.hkTransform_setMulInverseMul(o, p);
    int count = bits->m1C;
    unsigned int* out = (unsigned int*)hkMemoryRouter_getInstance();
    unsigned int* dst = (unsigned int*)*out;
    *out = (unsigned int)dst + ((count * 4 + 0x83) & 0xffffff80);
    int n = 0;
    unsigned int mask = 1;
    for (int i = 0; i < count; ++i, *(volatile unsigned int*)& mask = _rotl(*(volatile unsigned int*)&mask, 1))
    {
        if (bits->enabled(i, mask))
            dst[n++] = i;
    }
    dst[n] = 0xffffffff;
    hkAgent1nMachine_Process(this->m0 + 4, &input, bits, dst, a4);
    *(unsigned int*)hkMemoryRouter_getInstance() = (unsigned int)dst;
}
