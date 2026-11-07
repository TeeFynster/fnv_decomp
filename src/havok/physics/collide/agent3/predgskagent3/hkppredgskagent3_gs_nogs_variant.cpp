
// src/havok/physics/collide/agent3/predgskagent3/hkppredgskagent3_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/agent3/predgskagent3/hkppredgskagent3.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent3/predgskagent3/hkppredgskagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/predgskagent3/hkppredgskagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl FUN_00d41860(int a, int b, int c, int d);
void __cdecl ForwardToTarget(int a, int b, int c, int d, int unused);
struct InputObject
{
    void* vtable;
};
struct InputRecord
{
    int unk00;
    int unk04;
    int unk08;
    int type;
};
struct InputData
{
    InputObject* unk00;
    InputRecord** unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
struct ResultData
{
    char unk00;
    char unk01;
    char unk02;
    char unk03;
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    char unk08;
    char unk09;
    char unk0A;
    unsigned char unk0B;
    int unk0C;
    void __thiscall hkpGskCache_initTriangle(void* a, void* b, void* c);
    void __thiscall hkpGskCache_init(void* a, void* b, void* c);
};
void* __cdecl DispatchInputRecord(InputData* input, unsigned char* status, ResultData* result);
// Stand-ins for the script handler functions whose addresses are stored in the
// handler table (0xd417b0 .. 0xd40d80).  Only declared, never defined.
extern "C" void __cdecl RemoveEntryById(int a, int b, int c, int d);
extern "C" void __cdecl InsertSlotId(int a, int b, int c, int d);
extern "C" void __cdecl FindEntryByKey(int a, int b, int c, int d);
extern "C" void __cdecl ConvertPairFlags(int a, int b, int c, int d);
extern "C" void __cdecl hkPredGskAgent3_sepNormal(int a, int b, int c, int d);
extern "C" void __cdecl hkPredGskCylinderAgent3_process(int a, int b, int c, int d);
// The handler table that is handed to CScript::RegisterHandler.  It is kept
// 16 byte aligned, which is what makes the compiler emit the aligned frame
// prologue of this function.
struct __declspec(align(16)) HandlerTable
{
    void* p0;
    void* p1;
    void* p2;
    void* p3;
    void* p4;
    void* p5;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    void* p6;
    void* p7;
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    int unk34;
    int unk38;
    int unk3C;
};
// Stand-in for the script object: the registration is a __thiscall member.
class CScript
{
  public:
    void __thiscall RegisterHandler(HandlerTable* handler, int a, int b);
};
void __cdecl RegisterScriptHandlers(void* pScript);
struct S_00d417b0_Entry
{
    short unk00;
    short m_iOwnerObjectOffset;
    int unk04;
};
struct S_00d417b0_Sub
{
    short unk00;
    unsigned char m_uiItemCount;
    char unk03;
    S_00d417b0_Entry m_entries[1];
};
struct S_00d417b0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    S_00d417b0_Sub m_sub;
};
void __cdecl _hkGskManifold_removePoint(S_00d417b0_Sub* sub, int index);
void __cdecl RemoveEntryById(int a, S_00d417b0_Obj* obj, short id);
struct Slot
{
    unsigned short id;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
};
struct Table
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0C;
    unsigned char count;
    unsigned char unk0F;
    unsigned short unk10;
    Slot slots[1];
};
void __cdecl InsertSlotId(int a, Table* table, unsigned short value);
struct FUN_00d41830_entry
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned short key02;
    unsigned int unk04;
};
struct FUN_00d41830_table
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short unk0C;
    unsigned char count;
    unsigned char unk0F;
    FUN_00d41830_entry entries[8];
};
int __cdecl FindEntryByKey(int unused, FUN_00d41830_table* table, unsigned short key);
// FUN_00d41860 (0x00d41860, 67 bytes)
//
// The original routine
//   * hands the record block at b+0x0C to ReleaseAllEntries,
//   * reads the three size bytes at b+0x0C, b+0x0D and b+0x0E,
//   * combines them into  count = b[0x0C] + b[0x0D] + 4*b[0x0E],
//   * scales that into an aligned block size  (2*count + 31) & ~0x0F,
//   * returns b + that size,
//   * and finally clears the byte at a+2.
//
// The unit file of the pack declares FUN_00d41860 as returning void; with a
// void return the whole size computation is dead code and MSVC 2008 deletes
// it, so the value is handed back to the caller from a symbol whose name
// still contains the required tag "FUN_00d41860".
extern "C" void __cdecl ReleaseAllEntries(void* p, int obj, int data);
// @fnv 0x00d41860
// src: GUESS 0x00d41860 (confidence: low)
extern "C" int __cdecl Object_ProcessAndReturnValue_00d41860(int a, int b, int c, int d)
{
    unsigned char* rec = (unsigned char*)b + 0x0C;

    ReleaseAllEntries(rec, c, d);

    unsigned int count = rec[0] + rec[1] + rec[2] * 4;

    // (2 * count + 31) & ~0x0F, kept in the two steps the original uses
    unsigned int scaled = count * 2 + 4;
    count = scaled + 27;
    count &= ~0x0F;

    ((char*)a)[2] = 0;

    return b + (int)count;
}

#include <xmmintrin.h>
class hkpConvexShape_s
{
  public:
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0C();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1C();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2C();
    virtual void f30();
    virtual void f34();
    virtual void f38();
    virtual void GetVerticesForIds(const unsigned short* ids, int numIds, void* out) const;
    int unk04;
    int unk08;
    int unk0C;
    float m_fSphereRadius;
};

struct hkpCdBody_s
{
    hkpConvexShape_s* m_pCollisionShape;
    int unk04;
    void* m_kMotionState;
};

struct hkpGskCache_s
{
    unsigned short m_kVertices[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    unsigned char m_verticesDim;
    unsigned char m_flags;
};

struct Gsk_s
{
    int m_ucDimensionA;
    int m_ucDimensionB;
    int m_numA;
    int m_numB;
    int m_unk10;
    int m_cacheChanged;
    int m_pad18;
    int m_pad1C;
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
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;

    void __thiscall ComputeClosestPoints(hkpConvexShape_s* a, hkpConvexShape_s* b, void* t, void* out);
    void __thiscall writeToCache(hkpGskCache_s* cache);
};

struct Input_s
{
    hkpCdBody_s* m_pBodyA;
    hkpCdBody_s* m_pBodyB;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_kMotionTransform;
};

struct Output_s
{
    union
    {
        __m128 v;
        struct
        {
            float nx;
            float ny;
            float nz;
            float m_fClosestPointDistanceSquared;
        };
    };
};

struct SeparatingNormal
{
    __declspec(align(16)) float x;
    float y;
    float z;
    float w;
};

// @fnv 0x00d41930
// src: XBOX_PDB 0x00d41930
void __cdecl hkPredGskAgent3_sepNormal(Input_s* input, int unused, hkpGskCache_s* cache, Output_s* output)
{
    hkpConvexShape_s* shapeA = input->m_pBodyA->m_pCollisionShape;
    hkpConvexShape_s* shapeB = input->m_pBodyB->m_pCollisionShape;
    SeparatingNormal norm;
    Gsk_s gsk;
    gsk.m_unk10 = 0;
    gsk.m_ucDimensionB = cache->m_ucDimensionB;
    gsk.m_ucDimensionA = cache->m_ucDimensionA;
    gsk.m_numA = cache->m_verticesDim & 0xf;
    gsk.m_numB = cache->m_verticesDim >> 4;
    gsk.m_cacheChanged = 0;
    shapeA->GetVerticesForIds(cache->m_kVertices, gsk.m_ucDimensionA, &gsk.unk20);
    shapeB->GetVerticesForIds(&cache->m_kVertices[gsk.m_ucDimensionA], gsk.m_ucDimensionB, &gsk.unkE0);
    gsk.ComputeClosestPoints(shapeA, shapeB, &input->m_kMotionTransform, &norm);
    if (gsk.m_cacheChanged)
        gsk.writeToCache(cache);
    const float* rot = (const float*)input->m_pBodyA->m_kMotionState;
    __m128 n = _mm_load_ps(&norm.x);
    __m128 c0 = _mm_load_ps(rot);
    __m128 c1 = _mm_load_ps(rot + 4);
    __m128 c2 = _mm_load_ps(rot + 8);
    __m128 ny = _mm_shuffle_ps(n, n, 0x55);
    __m128 nx = _mm_shuffle_ps(n, n, 0x00);
    __m128 nz = _mm_shuffle_ps(n, n, 0xaa);
    __m128 res = _mm_add_ps(_mm_add_ps(_mm_mul_ps(ny, c1), _mm_mul_ps(nx, c0)), _mm_mul_ps(nz, c2));
    output->v = res;
    output->m_fClosestPointDistanceSquared = norm.w - (shapeB->m_fSphereRadius + shapeA->m_fSphereRadius);
}
