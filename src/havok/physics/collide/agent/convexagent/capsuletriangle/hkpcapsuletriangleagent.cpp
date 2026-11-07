#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
// Preserve the original intrinsic layout: the SDK union's byte arrays change
// stack protection and alias analysis with this unit's original compiler.
#define _INCLUDED_MM2
// Exe 0x00cd72a0 ComputeInverseLengths: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned int m128_u32[4];
} __m128, LocalM128;

#define FNV_VEC4_SCALAR
#include "../../../../../../../include/Vec4.h"

#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkVector4.h"

// src/havok/physics/collide/agent/convexagent/capsuletriangle/hkpcapsuletriangleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/capsuletriangle/hkpcapsuletriangleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void CreateObjectFromFactory();
void Object_CollectPenetratingBodyPair();
void staticGetClosestPoints();
void Object_ProcessEntries_00daf8e0();

// Writes four function pointers into the first 16 bytes of p and clears the two bytes at offsets 16 and 17.
// @fnv 0x00d3ab60
// src: GUESS 0x00d3ab60 (confidence: medium)
void Object_InitializeAgentFunctionTable_00d3ab60(void* apObject)
{
    *(void**)apObject = (void*)&CreateObjectFromFactory;
    *(void**)((char*)apObject + 4) = (void*)&Object_CollectPenetratingBodyPair;
    *(void**)((char*)apObject + 8) = (void*)&staticGetClosestPoints;
    *(void**)((char*)apObject + 12) = (void*)&Object_ProcessEntries_00daf8e0;
    *(char*)((char*)apObject + 16) = 0;
    *(char*)((char*)apObject + 17) = 0;
}

void __cdecl CreateAllocatedObject();
void __cdecl Object_UpdateFields_00d3ac80();
void __cdecl Object_UpdateFields_00d3b1a0();
void __cdecl Object_UpdateFields_00d3b220();

// @fnv 0x00d3ab90
// src: GUESS 0x00d3ab90 (confidence: low)
void __cdecl Hkpcapsuletriangleagent_UpdateState_00d3ab90(void** apTable)
{
    apTable[0] = (void*)&CreateAllocatedObject;
    apTable[1] = (void*)&Object_UpdateFields_00d3b1a0;
    apTable[2] = (void*)&Object_UpdateFields_00d3b220;
    apTable[3] = (void*)&Object_UpdateFields_00d3ac80;
    ((unsigned char*)apTable)[0x10] = 1;
    ((unsigned char*)apTable)[0x11] = 0;
}

void __cdecl CreateTriAgent2();
void __cdecl Object_UpdateFields_00d38ac0();
void __cdecl hkpMultiSphereTriangleAgent_UpdateState_00d38ed0();
void __cdecl Object_UpdateFields_00d3ac80();
void __cdecl CreateTriAgent();
void __cdecl hkpMultiSphereTriangleAgent_staticGetPenetrations();
void __cdecl Object_ProcessEntries_00d386c0();
void __cdecl Object_ProcessEntries_00daf8e0();

typedef void (__cdecl *S_00d389f0_Func)();

struct S_00d389f0_AgentFuncs
{
    S_00d389f0_Func m_pCreateFunc;
    S_00d389f0_Func m_pQueryPenetrationsFunc;
    S_00d389f0_Func m_getClosestPointsFunc;
    S_00d389f0_Func m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};

struct S_00d389f0_Dispatcher
{
    void AppendRecordAndRegisterAgents(S_00d389f0_AgentFuncs& f, int typeA, int typeB);
};

// Registers two agent function tables with the dispatcher, one for type 3 to 0x15 and one for 0x15 to 3.
// @fnv 0x00d389f0
// src: GUESS 0x00d389f0 (confidence: low)
void __cdecl hkpMultiSphereTriangleAgent_staticGetPenetrations_UpdateState_00d389f0(S_00d389f0_Dispatcher* dispatcher)
{
    {
        S_00d389f0_AgentFuncs agentFuncs;
        agentFuncs.m_pCreateFunc = CreateTriAgent2;
        agentFuncs.m_pQueryPenetrationsFunc = Object_UpdateFields_00d38ac0;
        agentFuncs.m_getClosestPointsFunc = hkpMultiSphereTriangleAgent_UpdateState_00d38ed0;
        agentFuncs.m_pLinearCastFunc = Object_UpdateFields_00d3ac80;
        agentFuncs.m_bIsFlipped = true;
        agentFuncs.m_bIsPredictive = false;
        dispatcher->AppendRecordAndRegisterAgents(agentFuncs, 3, 0x15);
    }
    {
        S_00d389f0_AgentFuncs agentFuncs;
        agentFuncs.m_pCreateFunc = CreateTriAgent;
        agentFuncs.m_pQueryPenetrationsFunc = hkpMultiSphereTriangleAgent_staticGetPenetrations;
        agentFuncs.m_getClosestPointsFunc = Object_ProcessEntries_00d386c0;
        agentFuncs.m_pLinearCastFunc = Object_ProcessEntries_00daf8e0;
        agentFuncs.m_bIsFlipped = false;
        agentFuncs.m_bIsPredictive = false;
        dispatcher->AppendRecordAndRegisterAgents(agentFuncs, 0x15, 3);
    }
}

struct ReceiverBase { virtual void Release(unsigned int value); int unk04; };
struct NoteDispatcher {
    virtual void Unknown00(unsigned int, void*);
    virtual void Unknown04(unsigned int, void*);
    virtual void Unknown08(unsigned int, void*);
    virtual void Unknown0C(unsigned int, void*);
    virtual void Unknown10(unsigned int, void*);
    virtual void Dispatch(unsigned int id, void* value);
};
struct FUN_00d39930_class : ReceiverBase {
    NoteDispatcher* dispatcher;
    unsigned short receiverIds[3];
    void __thiscall DispatchToReceivers(void* value);
};
// Dispatches value to each non-0xFFFF receiver id via dispatcher, then releases this if non-null.
// @fnv 0x00d39930
void FUN_00d39930_class::DispatchToReceivers(void* value)
{
    unsigned short* id = receiverIds;
    int count = 3;
    do {
        unsigned int current = *id;
        if ((unsigned short)current != 0xFFFF)
            dispatcher->Dispatch(current, value);
        ++id;
    } while (--count != 0);
    if (this)
        Release(1);
}

extern const int DAT_010ce7fc;

struct CallbackState {
    const int* m_pIntegerValue;
    float m_fFirstLightParameter;
    int m_iValue;
};

void __cdecl staticGetClosestPoints(void* apFirst, void* apSecond, void* apThird,
                          CallbackState* apState);

// Builds a CallbackState with a max float, the given value and a constant pointer, then passes it to FUN_00d3a280 with the three pointers reordered.
// @fnv 0x00d3b220
// src: GUESS 0x00d3b220 (confidence: low)
void __cdecl Object_UpdateFields_00d3b220(void* apOne, void* apTwo, void* apThree, int aiValue)
{
    CallbackState kState;
    kState.m_fFirstLightParameter = 3.40282e+38f;
    kState.m_iValue = aiValue;
    kState.m_pIntegerValue = &DAT_010ce7fc;
    staticGetClosestPoints(apTwo, apOne, apThree, &kState);
}

struct AllocIface {
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

void __cdecl ComputeInverseLengths(void* value, void* self);

extern char DAT_010ceefc[];
extern char DAT_010cef38[];

struct FUN_00d39980_cls {
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    unsigned short m_w0C;
    unsigned short m_w0E;
    unsigned short m_w10;
    unsigned short m_w12;
    void* m_sub;
};

// @fnv 0x00d39980
FUN_00d39980_cls* __cdecl CreateAllocatedObject(int a1, int a2, int a3, int a4)
{
    hkMemoryRouter* pAllocHolder = hkMemoryRouter_getInstance();
    FUN_00d39980_cls* pObject = (FUN_00d39980_cls*)((AllocIface*)pAllocHolder->m_heap)->Alloc(0x28);
    pObject->m_w04 = 0x28;
    pObject->m_w06 = 1;
    pObject->m_i08 = a4;
    pObject->m_w0C = 0xffff;
    pObject->m_w0E = 0xffff;
    pObject->m_w10 = 0xffff;
    pObject->m_vptr = DAT_010ceefc;
    ComputeInverseLengths((void*)(*(int*)a1 + 0x20), &pObject->m_sub);
    pObject->m_vptr = DAT_010cef38;
    return pObject;
}

extern "C" LocalM128 _mm_xor_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);

extern const LocalM128 DAT_010c4c00;

inline void hkVector4::operator=(const hkVector4& o) { m_vComponents = o.m_vComponents; }
inline void hkVector4::setBroadcast3(const hkVector4& v) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff); }
inline void hkVector4::mul4(const hkVector4& a) { m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents); }
inline void hkVector4::add4(const hkVector4& a) { m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents); }
inline void hkVector4::addMul4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents)); }
inline void hkVector4::setNeg4(const hkVector4& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c4c00); }
inline void hkVector4::neg() { m_vComponents = _mm_xor_ps(m_vComponents, DAT_010c4c00); }

struct Elem_d3b260 {
    hkVector4 m_pos;
    hkVector4 m_dir;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};

struct Buffer_d3b260 {
    Elem_d3b260* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Elem_d3b260 m_pElements[256];
    hkVector4 m_vHitNormal;
    float m_fHitFraction;
    int unk3034;
    int unk3038;
    int unk303c;
    unsigned short m_idx[4];
    unsigned char m_kPointA;
    unsigned char m_kPointB;
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};



struct Agent_d3b260 {
    void hkpCapsuleTriangleAgent_processCollision(int b, int a, int c, Buffer_d3b260* buf);
    void hkpSymmetricAgentLinearCast_hkpCapsuleTriangleAgent_processCollision(int a, int b, int c, Buffer_d3b260* buf);
};

// @fnv 0x00d3b260
// src: XBOX_PDB 0x00d3b260
void Agent_d3b260::hkpSymmetricAgentLinearCast_hkpCapsuleTriangleAgent_processCollision(int a, int b, int c, Buffer_d3b260* apBuffer)
{
    float dist = apBuffer->m_fHitFraction;
    Elem_d3b260* e = apBuffer->m_kRayEnd;
    hkpCapsuleTriangleAgent_processCollision(b, a, c, apBuffer);
    for (; e < apBuffer->m_kRayEnd; e++)
    {
        hkVector4 w;
        w.setBroadcast3(e->m_dir);
        w.mul4(e->m_dir);
        w.add4(e->m_pos);
        e->m_pos = w;
        e->m_dir.setNeg4(e->m_dir);
    }
    if (dist != apBuffer->m_fHitFraction)
    {
        apBuffer->m_vHitNormal.neg();
        unsigned char n = apBuffer->m_ucLowNibble;
        apBuffer->m_ucLowNibble = apBuffer->m_ucHighNibble;
        apBuffer->m_ucHighNibble = n;
        unsigned char t = apBuffer->m_kPointA;
        apBuffer->m_kPointA = apBuffer->m_kPointB;
        apBuffer->m_kPointB = t;
        int idx = apBuffer->m_kPointA + apBuffer->m_kPointB - 1;
        unsigned short w = apBuffer->m_idx[0];
        apBuffer->m_idx[0] = apBuffer->m_idx[idx];
        apBuffer->m_idx[idx] = w;
        if ((apBuffer->m_kPointA & apBuffer->m_kPointB) == 2)
        {
            unsigned short usTmp = apBuffer->m_idx[1];
            apBuffer->m_idx[1] = apBuffer->m_idx[2];
            apBuffer->m_idx[2] = usTmp;
        }
    }
}

struct __declspec(align(16)) FourWord {
    unsigned int x, y, z, w;
};

struct __declspec(align(16)) FourFloat {
    union { LocalM128 simd; FourWord words; };
};

struct __declspec(align(16)) MotionPacket {
    unsigned int word00;
    unsigned int word04;
    unsigned int word08;
    unsigned int word0c;
    unsigned int word10;
    unsigned int word14;
    unsigned int word18;
    unsigned int word1c;
    unsigned int word20;
    unsigned int word24;
    unsigned int word28;
    unsigned int word2c;
    unsigned int word30;
    unsigned int word34;
    unsigned int word38;
    unsigned int word3c;
    unsigned int word40;
    unsigned int word44;
    unsigned int word48;
    unsigned int word4c;
    FourFloat direction;
    unsigned int trailing60, trailing64, trailing68, trailing6c;
};

struct __declspec(align(16)) MotionCallData {
    const void* descriptor;
    float scale;
    FourWord direction;
    unsigned int mode;
};

extern "C" float DAT_0104da48;
extern "C" const LocalM128 DAT_010c44d0;
extern "C" unsigned char UNK_010ce80c;

extern "C" void __cdecl Object_ProcessEntries_00daf8e0(unsigned int second, unsigned int first,
                            MotionPacket* packet, MotionCallData* primary,
                            MotionCallData* secondary);

// Copies the input packet, XORs its direction with DAT_010c44d0, builds primary/secondary MotionCallData and calls FUN_00daf8e0.
// @fnv 0x00d3ac80
// src: GUESS 0x00d3ac80 (confidence: low)
void __cdecl Object_UpdateFields_00d3ac80(unsigned int first, unsigned int second,
                           const MotionPacket* apPacket, unsigned int mode,
                           unsigned int optionalMode)
{
    MotionPacket packetCopy = *apPacket;
    packetCopy.direction.simd = _mm_xor_ps(apPacket->direction.simd, DAT_010c44d0);
    const void* descriptor = &UNK_010ce80c;
    MotionCallData primary;
    primary.descriptor = descriptor;
    primary.scale = DAT_0104da48;
    primary.direction = apPacket->direction.words;
    primary.mode = mode;

    if (optionalMode) {
        MotionCallData secondary;
        secondary.descriptor = descriptor;
        secondary.scale = DAT_0104da48;
        secondary.direction = apPacket->direction.words;
        secondary.mode = optionalMode;
        Object_ProcessEntries_00daf8e0(second, first, &packetCopy, &primary, &secondary);
    } else {
        Object_ProcessEntries_00daf8e0(second, first, &packetCopy, &primary, 0);
    }
}

extern char DAT_010ce81c;
struct FUN_00d3b160_tmp { const void* vt; unsigned char flag; unsigned int a4; };
struct CallbackHost_d3b160 {
    void hkpCapsuleTriangleAgent_getPenetrations(void*, void*, void*, void*);
    void hkpSymmetricAgentLinearCast_hkpCapsuleTriangleAgent_getPenetrations(void*, void*, void*, unsigned int);
};

// Builds a temporary object holding a4 and a cleared flag with a vtable, then calls FUN_00d3a620 with a2, a1, a3 and that object.
// @fnv 0x00d3b160
// src: XBOX_PDB 0x00d3b160
void CallbackHost_d3b160::hkpSymmetricAgentLinearCast_hkpCapsuleTriangleAgent_getPenetrations(void* a1, void* a2, void* a3, unsigned int a4)
{
    FUN_00d3b160_tmp t;
    t.a4 = a4;
    t.flag = 0;
    t.vt = &DAT_010ce81c;
    hkpCapsuleTriangleAgent_getPenetrations(a2, a1, a3, &t);
}

struct Mat4 {
    Vec4::Aligned row0, row1, row2, row3;
};

void __cdecl hkCollideCapsuleUtilCapsVsTri(void* a, float b, void* c, float d, void* e, float f, int g, int h, int i);

static __forceinline void transform(Vec4::Aligned* out, const char* shape, int count, const Mat4* m)
{
    Vec4::Aligned p0 = m->row0;
    Vec4::Aligned p1 = m->row1;
    Vec4::Aligned p2 = m->row2;
    Vec4::Aligned p3 = m->row3;
    LocalM128 r0 = *(LocalM128*)&p0;
    LocalM128 r1 = *(LocalM128*)&p1;
    LocalM128 r2 = *(LocalM128*)&p2;
    LocalM128 r3 = *(LocalM128*)&p3;

    LocalM128* v = (LocalM128*)(shape + 0x20);
    for (int i = count - 1; i >= 0; --i) {
        LocalM128 vi = v[i];
        LocalM128 x = _mm_shuffle_ps(vi, vi, 0x00);
        LocalM128 y = _mm_shuffle_ps(vi, vi, 0x55);
        LocalM128 z = _mm_shuffle_ps(vi, vi, 0xaa);
        LocalM128 a = _mm_add_ps(_mm_mul_ps(y, r1), _mm_mul_ps(x, r0));
        LocalM128 b = _mm_add_ps(_mm_mul_ps(z, r2), r3);
        *(LocalM128*)&out[i] = _mm_add_ps(a, b);
    }
}

// Transforms two shapes' vertices by their matrices, then calls FUN_00cd6520 with the results, a4, a3's float at +8, a5 and a6.
// @fnv 0x00d399f0
void __cdecl TransformAndDispatch(char* a1, char* a2, char* pExtra, void* a4, int a5, int a6)
{
    const char* shapeA = *(const char**)a1;
    const char* shapeB = *(const char**)a2;

    Vec4::Aligned aTransformedA[2] = { Vec4(Vec4::Uninitialized), Vec4(Vec4::Uninitialized) };
    transform(aTransformedA, shapeA, 2, *(Mat4**)(a1 + 8));

    Vec4::Aligned aTransformedB[3] = { Vec4(Vec4::Uninitialized), Vec4(Vec4::Uninitialized), Vec4(Vec4::Uninitialized) };
    transform(aTransformedB, shapeB, 3, *(Mat4**)(a2 + 8));

    hkCollideCapsuleUtilCapsVsTri(&aTransformedA[0],
                 *(float*)(shapeA + 0x10),
                 &aTransformedB[0],
                 *(float*)(shapeB + 0x10),
                 a4,
                 *(float*)((char*)pExtra + 8),
                 a5,
                 a6,
                 0);
}

extern "C" LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
extern "C" void _mm_store_ss(float* p, LocalM128 a);
extern "C" LocalM128 _mm_load_ps(const float* p);
extern "C" void _mm_store_ps(float* p, LocalM128 a);
extern "C" LocalM128 _mm_rsqrt_ps(LocalM128 a);
extern LocalM128 DAT_010c71c0;
extern LocalM128 DAT_010c71d0;

static __forceinline float SqLenLane(LocalM128 x)
{
    LocalM128 sq = _mm_mul_ps(x, x);
    LocalM128 yx = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    LocalM128 zyx = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), yx);
    float r;
    _mm_store_ss(&r, zyx);
    return r;
}

// Computes Newton-refined inverse square roots of four vector lengths from pts and stores them plus a fifth value into out.
// @fnv 0x00cd72a0
void __cdecl ComputeInverseLengths(LocalM128* pts, float* out)
{
    LocalM128 c = pts[2];
    LocalM128 a = pts[0];
    LocalM128 b = pts[1];

    LocalM128 v = _mm_sub_ps(c, b);
    LocalM128 u = _mm_sub_ps(a, c);
    LocalM128 w = _mm_sub_ps(b, a);

    LocalM128 p = _mm_mul_ps(_mm_shuffle_ps(u, u, 0xc9), _mm_shuffle_ps(v, v, 0xd2));
    LocalM128 q = _mm_mul_ps(_mm_shuffle_ps(u, u, 0xd2), _mm_shuffle_ps(v, v, 0xc9));
    LocalM128 x = _mm_sub_ps(q, p);

    __declspec(align(16)) float lens[4];
    float fSqLen = SqLenLane(v);
    lens[0] = fSqLen;
    fSqLen = SqLenLane(u);
    lens[1] = fSqLen;
    fSqLen = SqLenLane(w);
    lens[2] = fSqLen;
    fSqLen = SqLenLane(x);
    lens[3] = fSqLen;

    LocalM128 l = _mm_load_ps(lens);
    LocalM128 r = _mm_rsqrt_ps(l);
    LocalM128 t = _mm_mul_ps(_mm_mul_ps(r, l), r);
    LocalM128 k1 = _mm_sub_ps(DAT_010c71c0, t);
    LocalM128 k2 = _mm_mul_ps(r, DAT_010c71d0);
    LocalM128 inv = _mm_mul_ps(k1, k2);

    _mm_store_ps(lens, inv);
    out[0] = lens[0];
    out[1] = lens[1];
    out[2] = lens[2];
    out[3] = lens[3];
    out[4] = fSqLen * lens[3];
}

struct __declspec(align(16)) ScalarVector {
    int x, y, z, w;
    LocalM128 quad() const { return *(const LocalM128*)this; }
};
struct Xf {
    ScalarVector r0, r1, r2, t;
};
struct Vt {
    void* f00; void* f04; void* f08; void* f0c;
    void* f10; void* f14; void* f18; void* f1c;
    void* f20; void* f24; void* f28; void* f2c;
    void* f30; void* f34; void* f38; void* f3c;
    int (__thiscall *fn)(void*, void*, void*, void*, void*, void*, void*, void*);
};
struct ShapeInterface {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual int refine(void*,void*,void*,void*,void*,void*,void*);
};
struct Shape : ShapeInterface {
    int unk04;
    int unk08;
    int unk0c;
    float radius;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 vertices[3];
};
struct Obj {
    Shape* base;
    int u;
    Xf* xf;
};
struct Par {
    float a;
    int flag;
    float c;
};
struct Info {
    unsigned char count;
    unsigned char type;
    unsigned short feature;
    int index;
};
struct Contact {
    LocalM128 normal;
    LocalM128 position;
    Contact& operator=(const Contact& c) { normal = c.normal; position = c.position; return *this; }
    void __thiscall SetPositionXYZ(void* arg);
};



static __forceinline void xform(const Xf& m, const LocalM128* src, LocalM128* dst, int hi)
{
    ScalarVector column0 = m.r0;
    LocalM128 c0 = column0.quad();
    ScalarVector column1 = m.r1;
    LocalM128 c1 = column1.quad();
    ScalarVector column2 = m.r2;
    LocalM128 c2 = column2.quad();
    ScalarVector translation = m.t;
    LocalM128 ct = translation.quad();
    for (int i = hi; i >= 0; --i) {
        LocalM128 v = src[i];
        LocalM128 x = _mm_shuffle_ps(v, v, 0);
        LocalM128 y = _mm_shuffle_ps(v, v, 0x55);
        LocalM128 z = _mm_shuffle_ps(v, v, 0xaa);
        dst[i] = _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, c1), _mm_mul_ps(x, c0)), _mm_add_ps(_mm_mul_ps(z, c2), ct));
    }
}

struct CollisionWorkspace { LocalM128 la[2]; LocalM128 lb[3]; };
// Transforms shape vertices, runs a collision query, optionally refines the contact, and writes the result to out.
// @fnv 0x00d39bf0
// src: XBOX_PDB 0x00d39bf0
int __cdecl hkpCapsuleTriangleAgent_getClosestPoint(Obj* a, Obj* b, Par* volatile apParams, void* q, Contact* apContactOut)
{
    CollisionWorkspace workspace;
    Shape* shapes[2];
    shapes[0] = a->base;
    shapes[1] = b->base;

    xform(*a->xf, (const LocalM128*)shapes[0]->vertices, workspace.la, 1);

    xform(*b->xf, (const LocalM128*)shapes[1]->vertices, workspace.lb, 2);

    Info info[3];
    LocalM128 res[6];
    Par* input = apParams;
    hkCollideCapsuleUtilCapsVsTri(workspace.la, shapes[0]->radius, workspace.lb, shapes[1]->radius, q, input->c, 0, (int)res, (int)info);

    float fDistA = ((float*)res)[7];
    float fDistB = ((float*)res)[15];
    int idx;
    if (fDistA < fDistB) {
        if (!(fDistA < input->c)) goto fail;
        idx = 0;
    } else {
        if (!(fDistB < input->c)) goto fail;
        idx = 1;
    }

    unsigned char n;
    n = info[idx].count;
    if (input->flag != 0 && n > 0) {
        const ScalarVector& source = *(ScalarVector*)(res + idx * 2 + 1);
        ScalarVector t;
        t.x = source.x;
        t.y = source.y;
        t.z = source.z;
        t.w = source.w;
        Xf* transformA = a->xf;
        Xf* transformB = b->xf;
        int r = shapes[1]->refine(&info[idx].feature, &n, res + idx * 2, transformB, shapes[0], transformA, &t);
        if (r != 0) { if (r == 1) ((Contact*)(res + idx * 2))->SetPositionXYZ(&t); } else goto fail;
    }

    *apContactOut = ((Contact*)res)[idx];
    return 1;
fail:
    return 0;
}

#include <windows.h>
extern DWORD DAT_0126835c;

extern "C" void _ReadWriteBarrier(void);
unsigned __int64 __cdecl __rdtsc(void);



typedef ScalarVector Vec4f;

struct ContactMatrix
{
    Vec4f row[4];
};

struct VirtObj
{
    virtual void v00();
    virtual void Run(const void* a, const void* b);
};

struct ManifoldPoint
{
    LocalM128 pos;
    int unk10;
    int unk14;
    int unk18;
    float dist;
};

struct HitRec
{
    ManifoldPoint pt0;
    ManifoldPoint pt1;
    ManifoldPoint pt2;
};

struct Context
{
    HitRec hit;
    LocalM128 capsule[2];
    LocalM128 triangle[3];
};

extern "C" void __cdecl hkCollideCapsuleUtilCapsVsTri(void* out1, float fx, void* out2, float fy, void* p, float afDepth, int zero, HitRec* hit, int zero2);

struct CollisionInput { int unk00; int unk04; float tolerance; };

struct __declspec(align(16)) RowPair { Vec4f first, second; };

struct CapsuleTriangleAgent {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void hkpCapsuleTriangleAgent_getPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionInput* input, VirtObj* collector);
};

// Transforms capsule and triangle vertices into world space, tests for intersection, and reports a hit to the collector if found.
// @fnv 0x00d3a620
// src: HAVOK_SRC 0x00d3a620
void CapsuleTriangleAgent::hkpCapsuleTriangleAgent_getPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionInput* input, VirtObj* collector)
{
    volatile DWORD tick;
    hkMonitorStream* pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        pRec->m_commandAndMonitor = "TtCapsTriangle";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }

    Context ctx;
    // Capsule and triangle vertices begin at 0x20 in their derived shape layouts.
    const hkpConvexShape* capsuleShape = static_cast<const hkpConvexShape*>(bodyA.m_pCollisionShape);
    const hkpConvexShape* triangleShape = static_cast<const hkpConvexShape*>(bodyB.m_pCollisionShape);
    const ContactMatrix* transformA = (const ContactMatrix*)bodyA.m_pMotionState;

    {
        RowPair xyRows;
        __declspec(align(16)) Vec4f c2;
        __declspec(align(16)) Vec4f c3;
        xyRows.first = transformA->row[0];
        xyRows.second = transformA->row[1];
        c2 = transformA->row[2];
        c3 = transformA->row[3];
        LocalM128 r0 = _mm_load_ps((const float*)&xyRows.first);
        LocalM128 r1 = _mm_load_ps((const float*)&xyRows.second);
        for (int i = 1; i >= 0; i--)
        {

            LocalM128 r2 = *(LocalM128*)&c2;
            LocalM128 r3 = *(LocalM128*)&c3;

            LocalM128 v = ((const LocalM128*)((const char*)capsuleShape + 0x20))[i];
            LocalM128 t = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0), r0), _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), r1));
            ctx.capsule[i] = _mm_add_ps(t, _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), r2), r3));
        }

    }

    const ContactMatrix* transformB = (const ContactMatrix*)bodyB.m_pMotionState;
    {
        __declspec(align(16)) Vec4f d0;
        __declspec(align(16)) Vec4f d1;
        RowPair translationAndZ;
        d0 = transformB->row[0];
        d1 = transformB->row[1];
        translationAndZ.second = transformB->row[2];
        translationAndZ.first = transformB->row[3];
        for (int i = 2; i >= 0; i--)
        {
            LocalM128 s1 = *(LocalM128*)&d1;
            LocalM128 s2 = *(LocalM128*)&translationAndZ.second;
            LocalM128 s3 = *(LocalM128*)&translationAndZ.first;
            LocalM128 s0 = *(LocalM128*)&d0;
            LocalM128 v = ((const LocalM128*)((const char*)triangleShape + 0x20))[i];
            LocalM128 t = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), s0);
            t = _mm_add_ps(t, _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), s1));
            ctx.triangle[i] = _mm_add_ps(t, _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), s2), s3));
        }

    }

    hkCollideCapsuleUtilCapsVsTri(ctx.capsule, capsuleShape->m_fSphereRadius, ctx.triangle, triangleShape->m_fSphereRadius, &this->unk14, input->tolerance, 0, &ctx.hit, 0);
    if (ctx.hit.pt0.dist < 0.0f || ctx.hit.pt1.dist < 0.0f)
    {
        collector->Run(&bodyA, &bodyB);
    }

    hkMonitorStream* pBuf2 = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf2->m_end.m_storage < pBuf2->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf2->m_end.m_storage);
        pRec->m_commandAndMonitor = "Et";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_time0 = tick;
        pBuf2->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }
}

namespace fnv_00d3b1a0 {
extern "C" const int DAT_010ce81c;

struct LocalState_d3b1a0 {
    const int* m_pIntegerValue;
    unsigned char m_bZero;
    int m_iValue;
};

typedef void (__cdecl *Call_d3a8c0)(int, int, int, LocalState_d3b1a0*);

// Initialises a LocalState_d3b1a0 with param4, a zero flag and a pointer to DAT_010ce81c, then calls FUN_00d3a8c0 with param2, param1, param3 and the state.
// @fnv 0x00d3b1a0
// src: GUESS 0x00d3b1a0 (confidence: low)
void __cdecl Object_UpdateFields_00d3b1a0(int param1, int param2, int param3, int aiValue) {
    LocalState_d3b1a0 state;
    state.m_iValue = aiValue;
    state.m_bZero = 0;
    state.m_pIntegerValue = &DAT_010ce81c;

    Call_d3a8c0 call = (Call_d3a8c0)Object_CollectPenetratingBodyPair;
    call(param2, param1, param3, &state);
}
}  // namespace fnv_00d3b1a0

namespace fnv_00d3b1e0 {
struct CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct CpuObject {
    void hkpCapsuleTriangleAgent_getClosestPoints(void*, void*, unsigned int, CpuCallData*);
    void hkpSymmetricAgentLinearCast_hkpCapsuleTriangleAgent_getClosestPoints(void*, void*, unsigned int, unsigned int);
};
// Builds a CpuCallData from fourth, DAT_0104da48 and &DAT_010ce7fc, then calls FUN_00d39ef0 with second, first, third and that data.
// @fnv 0x00d3b1e0
// src: XBOX_PDB 0x00d3b1e0
void CpuObject::hkpSymmetricAgentLinearCast_hkpCapsuleTriangleAgent_getClosestPoints(void* first, void* second, unsigned int third, unsigned int fourth)
{
    CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    hkpCapsuleTriangleAgent_getClosestPoints(second, first, third, &data);
}
}  // namespace fnv_00d3b1e0

extern "C" LocalM128 _mm_unpackhi_ps(LocalM128 a, LocalM128 b);

struct ContactNormalSetter : Contact
{
    ContactNormalSetter* SetPositionXYZ(const LocalM128* source);
};

// Copies the x, y and z components of *source into position, keeping position's existing w, and returns this.
// @fnv 0x00caad60
// src: GUESS 0x00caad60 (confidence: medium)
ContactNormalSetter* ContactNormalSetter::SetPositionXYZ(const LocalM128* source)
{
    LocalM128 incoming = *source;
    LocalM128 current = position;
    LocalM128 high = _mm_unpackhi_ps(incoming, current);
    position = _mm_shuffle_ps(incoming, high, 0xc4);
    return this;
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct MonitorRecord { const char* name; unsigned int time; unsigned int unk08; };
struct __declspec(align(16)) PlainVector { int x,y,z,w; LocalM128 quad() const { return *(const LocalM128*)this; } };
struct PlainMatrix { PlainVector r0,r1,r2,t; };
struct ContactRecord {
    LocalM128 position;
    LocalM128 normal;
    ContactRecord& operator=(const ContactRecord& o) { position=o.position; normal=o.normal; return *this; }
    void SetPositionXYZ(const PlainVector*);
};
struct CacheRecord { unsigned char flag; unsigned char unk01; unsigned short feature; unsigned int unk04; };
union __declspec(align(16)) TransformCacheScratch { PlainVector column; CacheRecord cache[3]; };
struct CollisionShape;
struct CapsuleShapeInterface {
    virtual void slot00(); virtual void slot04(); virtual void slot08(); virtual void slot0c();
    virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1c();
    virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void slot2c();
    virtual void slot30(); virtual void slot34(); virtual void slot38(); virtual void slot3c();
    virtual int process(unsigned short*,unsigned char*,ContactRecord*,const PlainMatrix*,const CollisionShape*,const PlainMatrix*,PlainVector*);
};
struct CollisionShape : CapsuleShapeInterface {
    unsigned int unk04,unk08,unk0c;
    float radius;
    unsigned int unk14,unk18,unk1c;
    hkVector4 points[3];
};
struct BodyRecord { const CollisionShape* shape; unsigned int unk04; const PlainMatrix* matrix; };
struct PointEvent { ContactRecord contact; const BodyRecord* a; const BodyRecord* b; unsigned int unk28,unk2c; };
struct Collector { virtual void slot00(); virtual void accept(const PointEvent*); };
struct ContactResults { ContactRecord points[3]; };
void __cdecl hkCollideCapsuleUtilCapsVsTri(hkVector4*,float,hkVector4*,float,void*,float,int,ContactResults*,CacheRecord*);
struct CollisionAgent {
    unsigned int unk00,unk04,unk08,unk0c,unk10,cache14;
    void hkpCapsuleTriangleAgent_getClosestPoints(const BodyRecord& a,const BodyRecord& b,const CollisionInput& input,Collector* output);
};
// @fnv 0x00d39ef0
// src: HAVOK_SRC 0x00d39ef0
void CollisionAgent::hkpCapsuleTriangleAgent_getClosestPoints(const BodyRecord& a,const BodyRecord& b,const CollisionInput& input,Collector* output) {
    {
        hkMonitorStream* stream=(hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if(stream->m_end.m_storage < stream->m_capacityMinus16.m_storage) {
            MonitorRecord* rec=(MonitorRecord*)stream->m_end.m_storage;
            rec->name="TtCapsTriangle";
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            rec->time=ticks;
            stream->m_end.m_storage=(char*)(rec+1);
        }
    }
    {
    PointEvent event;
    event.a=&a; event.b=&b;
    TransformCacheScratch transformCache;
    hkVector4 pointsA[2];
    hkVector4 pointsB[3];
    const CollisionShape* shapeA=a.shape;
    const CollisionShape* shapeB=b.shape;
    xform(*(const Xf*)a.matrix,&shapeA->points[0].m_vComponents,&pointsA[0].m_vComponents,1);
    xform(*(const Xf*)b.matrix,&shapeB->points[0].m_vComponents,&pointsB[0].m_vComponents,2);
    ContactResults result;
    CacheRecord* cache=transformCache.cache;
    hkCollideCapsuleUtilCapsVsTri(pointsA,shapeA->radius,pointsB,shapeB->radius,&cache14,input.tolerance,0,&result,cache);
    int index;
    if(result.points[0].normal.m128_f32[3] < result.points[1].normal.m128_f32[3]) {
        if(!(input.tolerance > result.points[0].normal.m128_f32[3])) goto done;
        index=0;
    } else {
        if(!(input.tolerance > result.points[1].normal.m128_f32[3])) goto done;
        index=1;
    }
    {
        unsigned char flag=cache[index].flag;
        if(input.unk04 && flag>0) {
            PlainVector normal=*(const PlainVector*)&result.points[index].normal;
            const PlainMatrix* transformA=a.matrix;
            const PlainMatrix* transformB=b.matrix;
            ContactRecord* contact=&result.points[index];
            int outcome=const_cast<CollisionShape*>(shapeB)->process(&cache[index].feature,&flag,contact,transformB,shapeA,transformA,&normal);
            if(outcome==0) goto done;
            if(outcome==1) result.points[index].SetPositionXYZ(&normal);
        }
        event.contact=result.points[index];
        output->accept(&event);
    }
    }
done:
    {
        hkMonitorStream* stream=(hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if(stream->m_end.m_storage < stream->m_capacityMinus16.m_storage) {
            MonitorRecord* rec=(MonitorRecord*)stream->m_end.m_storage;
            rec->name="Et";
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            rec->time=ticks;
            stream->m_end.m_storage=(char*)(rec+1);
        }
    }
}

extern char DAT_010cef80[], DAT_010c41f8[];
struct Timer { char* volatile name; unsigned time; unsigned extra; };
struct TimerPair { int unused; Timer* current; int unused2; Timer* end; };
struct Body { Shape* shape; int unused; Mat4* matrix; };
struct Input { int unk00,unk04; float tolerance; };
struct PenetrationCollector { virtual void unused(); virtual void add(Body*, Body*); };
struct AlignedPairData { Vec4::Aligned position, normal; };
struct Result { AlignedPairData points[3]; };
struct Cache { float inverseEdge0,inverseEdge1,inverseEdge2,inverseNormal,normalLength; };
struct OutputA { Vec4::Aligned points[2]; };
struct OutputB { Vec4::Aligned points[3]; };
struct Locals { Result result; OutputA outA; OutputB outB; };
static __forceinline void mytransform(Vec4::Aligned* out, const Shape* shape, int count, const Mat4* m)
{
    struct Rows { Vec4::Aligned p3,p2,p1,p0; } p = { Vec4(Vec4::Uninitialized), Vec4(Vec4::Uninitialized), Vec4(Vec4::Uninitialized), Vec4(Vec4::Uninitialized) };
    p.p0 = m->row0; p.p1 = m->row1; p.p2 = m->row2; p.p3 = m->row3;
    LocalM128 r0 = *(LocalM128*)&p.p0, r1 = *(LocalM128*)&p.p1, r2 = *(LocalM128*)&p.p2, r3 = *(LocalM128*)&p.p3;
    const LocalM128* v = (const LocalM128*)shape->vertices;
    for (int i = count - 1; i >= 0; --i) {
        LocalM128 vi = v[i];
        LocalM128 x = _mm_shuffle_ps(vi, vi, 0);
        LocalM128 y = _mm_shuffle_ps(vi, vi, 0x55);
        LocalM128 z = _mm_shuffle_ps(vi, vi, 0xaa);
        LocalM128 a = _mm_add_ps(_mm_mul_ps(r0, x), _mm_mul_ps(r1, y));
        LocalM128 b = _mm_add_ps(_mm_mul_ps(z, r2), r3);
        *(LocalM128*)&out[i] = _mm_add_ps(a, b);
    }
}
static __forceinline void mytransform2(Vec4::Aligned* out, const Shape* shape, int count, const Mat4* m)
{
    LocalM128 r0,r1,r2,r3; (void)r1; (void)r2; 
    struct Rows { Vec4::Aligned p0,p1,p2,p3; } p = { Vec4(Vec4::Uninitialized), Vec4(Vec4::Uninitialized), Vec4(Vec4::Uninitialized), Vec4(Vec4::Uninitialized) };
    p.p0 = m->row0; p.p1 = m->row1; p.p2 = m->row2; p.p3 = m->row3;
    r0 = _mm_load_ps((const float*)&p.p0); r1 = _mm_load_ps((const float*)&p.p1); r2 = _mm_load_ps((const float*)&p.p2); r3 = _mm_load_ps((const float*)&p.p3);
    const LocalM128* __restrict v = (const LocalM128*)shape->vertices;
    int i = count - 1;
    do {
        LocalM128 vi = v[i];
        LocalM128 x = _mm_shuffle_ps(vi, vi, 0); LocalM128 y = _mm_shuffle_ps(vi, vi, 0x55); LocalM128 z = _mm_shuffle_ps(vi, vi, 0xaa);
        LocalM128 a = _mm_add_ps(_mm_mul_ps(y, r1), _mm_mul_ps(x, r0));
        LocalM128 b = _mm_add_ps(_mm_mul_ps(z, r2), r3);
        *(LocalM128*)&out[i] = _mm_add_ps(b, a);
    } while (--i >= 0);
}
// Transforms two body shapes, tests for penetration, and adds the pair to the collector if the result normals indicate overlap.
// @fnv 0x00d3a8c0
// src: GUESS 0x00d3a8c0 (confidence: medium)
void __cdecl Object_CollectPenetratingBodyPair(Body* apBodyA, Body* apBodyB, Input* input, PenetrationCollector* collector)
{
    TimerPair* state = (TimerPair*)TlsGetValue(DAT_0126835c);
    Timer* timer = state->current;
    if (timer < state->end) {
        timer->name = DAT_010cef80;
        _ReadWriteBarrier();
        volatile unsigned t = (unsigned)__rdtsc();
        timer->time = t;
        state->current = timer + 1;
    }
    Locals l = {
        { { { Vec4(Vec4::Uninitialized), Vec4(Vec4::Uninitialized) },
            { Vec4(Vec4::Uninitialized), Vec4(Vec4::Uninitialized) },
            { Vec4(Vec4::Uninitialized), Vec4(Vec4::Uninitialized) } } },
        { { Vec4(Vec4::Uninitialized), Vec4(Vec4::Uninitialized) } },
        { { Vec4(Vec4::Uninitialized), Vec4(Vec4::Uninitialized), Vec4(Vec4::Uninitialized) } }
    };
    Cache cache;
    ComputeInverseLengths((void*)apBodyB->shape->vertices, &cache);
    Shape* pShapeA = apBodyA->shape;
    Shape* pShapeB = apBodyB->shape;
    mytransform(l.outA.points, pShapeA, 2, apBodyA->matrix);
    mytransform2(l.outB.points, pShapeB, 3, apBodyB->matrix);
    hkCollideCapsuleUtilCapsVsTri(&l.outA, pShapeA->radius, &l.outB, pShapeB->radius, &cache, input->tolerance, 0, (int)&l.result, 0);
    if (l.result.points[0].normal.w < 0.0f || l.result.points[1].normal.w < 0.0f)
        collector->add(apBodyA, apBodyB);
    state = (TimerPair*)TlsGetValue(DAT_0126835c);
    timer = state->current;
    if (timer < state->end) {
        timer->name = DAT_010c41f8;
        _ReadWriteBarrier();
        volatile unsigned t = (unsigned)__rdtsc();
        timer->time = t;
        state->current = timer + 1;
    }
}
