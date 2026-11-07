
// src/havok/physics/constraintsolver/constraint/chain/hkppoweredchainsolverutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/constraint/chain/hkppoweredchainsolverutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkAabb.h"
#include "../../../../../../include/hkVector4.h"

struct FUN_00df0810_Channel
{
    float value1;
    float value2;
    int unk08;
    int unk0c;
    int unk10;
};

struct FUN_00df0810_Source
{
    unsigned char modes;
    FUN_00df0810_Channel channels[3];
};

struct FUN_00df0810_Dest
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float values[3];
    int unk1c;
};

// Selects value1 or value2 of a source channel based on its 2-bit mode and stores it into the destination's values array.
// @fnv 0x00df0810
void __cdecl CopyChannelValue(int index, int channel, FUN_00df0810_Source* sources, FUN_00df0810_Dest* dests)
{
    FUN_00df0810_Source* source = &sources[index];
    FUN_00df0810_Dest* dest = &dests[index];
    float value;
    if (((source->modes >> (channel * 2)) & 3) == 1)
        value = source->channels[channel].value1;
    else
        value = source->channels[channel].value2;
    dest->values[channel] = value;
}

#include <xmmintrin.h>
static __forceinline void CopyHelper(__m128* d, const void* s)
{
    d[0] = ((__m128*)s)[0];
    d[1] = ((__m128*)s)[1];
    d[2] = ((__m128*)s)[2];
    d[3] = ((__m128*)s)[3];
    d[4] = ((__m128*)s)[4];
    d[5] = ((__m128*)s)[5];
    d[6] = ((__m128*)s)[6];
    d[7] = ((__m128*)s)[7];
    d[8] = ((__m128*)s)[8];
}

struct ObjF
{
    float f000;
    float f004;
    float f008;
    float f00c;
    float f010;
    float f014;
    float f018;
    float f01c;
    float f020;
    float f024;
    float f028;
    float f02c;
    float f030;
    float f034;
    float f038;
    float f03c;
    float f040;
    float f044;
    float f048;
    float f04c;
    float f050;
    float f054;
    float f058;
    float f05c;
    float f060;
    float f064;
    float f068;
    float f06c;
    float f070;
    float f074;
    float f078;
    float f07c;
    float f080;
    float f084;
    float f088;
    float f08c;
    float f090;
    float f094;
    float f098;
    float f09c;
    float f0a0;
    float f0a4;
    float f0a8;
    float f0ac;
    float f0b0;
    float f0b4;
    float f0b8;
    float f0bc;
    float f0c0;
    float f0c4;
    float f0c8;
    float f0cc;
    float f0d0;
    float f0d4;
    float f0d8;
    float f0dc;
    float f0e0;
    float f0e4;
    float f0e8;
    float f0ec;
    float f0f0;
    float f0f4;
    float f0f8;
    float f0fc;
    float f100;
    float f104;
    float f108;
    float f10c;
    float f110;
    float f114;
    float f118;
    float f11c;
    float f120;
    float f124;
    float f128;
    float f12c;
    float f130;
    float f134;
    float f138;
    float f13c;
    float f140;
    float f144;
    float f148;
    float f14c;
    float f150;
    float f154;
    float f158;
    float f15c;
    float f160;
    float f164;
    float f168;
    float f16c;
    float f170;
    float f174;
    float f178;
    float f17c;
    float f180;
    float f184;
    float f188;
    float f18c;
    float f190;
    float f194;
    float f198;
    float f19c;
    float f1a0;
    float f1a4;
    float f1a8;
    float f1ac;
    float f1b0;
    float f1b4;
    float f1b8;
    float f1bc;
    float f1c0;
    float f1c4;
    float f1c8;
    float f1cc;
    float f1d0;
    float f1d4;
    float f1d8;
    float f1dc;
    float f1e0;
    float f1e4;
    float f1e8;
    float f1ec;
    float f1f0;
    float f1f4;
    float f1f8;
    float f1fc;
    float f200;
    float f204;
    float f208;
    float f20c;
    float f210;
    float f214;
    float f218;
    float f21c;
    float f220;
    float f224;
    float f228;
    float f22c;
    float f230;
    float f234;
    float f238;
    float f23c;
    float f240;
    float f244;
    float f248;
    float f24c;
    float f250;
    float f254;
    float f258;
    float f25c;
    float f260;
    float f264;
    float f268;
    float f26c;
    float f270;
    float f274;
    float f278;
    float f27c;
    float f280;
    float f284;
    float f288;
    float f28c;
    float f290;
    float f294;
    float f298;
    float f29c;
    float f2a0;
    float f2a4;
    float f2a8;
    float f2ac;
    float f2b0;
    float f2b4;
    float f2b8;
    float f2bc;
    float f2c0;
    float f2c4;
    float f2c8;
    float f2cc;
    float f2d0;
    float f2d4;
    float f2d8;
    float f2dc;
    float f2e0;
    float f2e4;
    float f2e8;
    float f2ec;
    float f2f0;
    float f2f4;
    float f2f8;
    float f2fc;
    float f300;
    float f304;
    float f308;
    float f30c;
    float f310;
    float f314;
    float f318;
    float f31c;
    float f320;
    float f324;
    float f328;
    float f32c;
    float f330;
    float f334;
    float f338;
    float f33c;
    float f340;
    float f344;
    float f348;
    float f34c;
    float f350;
    float f354;
    float f358;
    float f35c;
    float f360;
    float f364;
    float f368;
    float f36c;
    float f370;
    float f374;
    float f378;
    float f37c;
    float f380;
    float f384;
    float f388;
    float f38c;
    float f390;
    float f394;
    float f398;
    float f39c;
    float f3a0;
    float f3a4;
    float f3a8;
    float f3ac;
    float f3b0;
    float f3b4;
    float f3b8;
    float f3bc;
};

struct __declspec(align(16)) CBuf
{
    float f000;
    float f004;
    float f008;
    float f00c;
    float f010;
    float f014;
    float f018;
    float f01c;
    float f020;
    float f024;
    float f028;
    float f02c;
    float f030;
    float f034;
    float f038;
    float f03c;
    float f040;
    float f044;
    float f048;
    float f04c;
    float f050;
    float f054;
    float f058;
    float f05c;
    float f060;
    float f064;
    float f068;
    float f06c;
    float f070;
    float f074;
    float f078;
    float f07c;
    float f080;
    float f084;
    float f088;
    float f08c;
    float f090;
    float f094;
    float f098;
    float f09c;
    float f0a0;
    float f0a4;
    float f0a8;
    float f0ac;
    float f0b0;
};
struct __declspec(align(16)) BufA
{
    float f000;
    float f004;
    float f008;
    float f00c;
    float f010;
    float f014;
    float f018;
    float f01c;
    float f020;
    float f024;
    float f028;
    float f02c;
    float f030;
    float f034;
    float f038;
    float f03c;
    float f040;
    float f044;
    float f048;
    float f04c;
    float f050;
    float f054;
    float f058;
    float f05c;
    float f060;
    float f064;
    float f068;
    float f06c;
    float f070;
    float f074;
    float f078;
    float f07c;
    float f080;
    float f084;
    float f088;
    float f08c;
    float f090;
    float f094;
    float f098;
    float f09c;
    float f0a0;
    float f0a4;
    float f0a8;
    float f0ac;
    float f0b0;
    float f0b4;
    float f0b8;
    float f0bc;
    float f0c0;
    float f0c4;
    float f0c8;
    float f0cc;
    float f0d0;
    float f0d4;
    float f0d8;
    float f0dc;
    float f0e0;
    float f0e4;
    float f0e8;
    float f0ec;
    float f0f0;
    float f0f4;
    float f0f8;
    float f0fc;
    float f100;
    float f104;
    float f108;
    float f10c;
    float f110;
    float f114;
    float f118;
    float f11c;
    float f120;
    float f124;
    float f128;
    float f12c;
    float f130;
    float f134;
    float f138;
    float f13c;
    float f140;
    float f144;
    float f148;
    float f14c;
    float f150;
    float f154;
    float f158;
    float f15c;
    float f160;
    float f164;
    float f168;
    float f16c;
    float f170;
    float f174;
    float f178;
    float f17c;
};
struct __declspec(align(16)) BufB
{
    float f000;
    float f004;
    float f008;
    float f00c;
    float f010;
    float f014;
    float f018;
    float f01c;
    float f020;
    float f024;
    float f028;
    float f02c;
    float f030;
    float f034;
    float f038;
    float f03c;
    float f040;
    float f044;
    float f048;
    float f04c;
    float f050;
    float f054;
    float f058;
    float f05c;
    float f060;
    float f064;
    float f068;
    float f06c;
    float f070;
    float f074;
    float f078;
    float f07c;
    float f080;
    float f084;
    float f088;
    float f08c;
    float f090;
    float f094;
    float f098;
    float f09c;
    float f0a0;
    float f0a4;
    float f0a8;
    float f0ac;
    float f0b0;
    float f0b4;
    float f0b8;
    float f0bc;
};

extern void __cdecl ResetJacobianRows(int a, int b, void* c, void* d);
extern void __cdecl Object_ProcessEntries_00df07c0(int a, void* b);
extern void __cdecl _hkMatrix6SetTranspose(void* a, void* b);
extern void __cdecl hkMatrix3_ProcessEntries_00e29470(void* a, void* b, int c);
extern void __cdecl Object_SubtractVectorBundles(void* a, void* b);
extern void __cdecl Runtime_ForwardCall_00e298f0(void* a, void* b);
extern float DAT_0104da4c;

// @fnv 0x00df0870
// src: GUESS 0x00df0870 (confidence: low)
void __cdecl Hkppoweredchainsolverutil_UpdateState_00df0870(int arg0, ObjF* __restrict obj, int arg2, __m128* arg3, int* arg4)
{
    void* p180;
    float fClamped;
    float input;
    BufA A;
    BufB B;
    CBuf C;
    __m128* dst;

    *(__m128*)&A.f000 = *(__m128*)&obj->f240;
    *(__m128*)&A.f010 = *(__m128*)&obj->f250;
    *(__m128*)&A.f020 = *(__m128*)&obj->f260;
    *(__m128*)&A.f030 = *(__m128*)&obj->f270;
    *(__m128*)&A.f040 = *(__m128*)&obj->f280;
    *(__m128*)&A.f050 = *(__m128*)&obj->f290;
    *(__m128*)&A.f060 = *(__m128*)&obj->f2a0;
    *(__m128*)&A.f070 = *(__m128*)&obj->f2b0;
    *(__m128*)&A.f080 = *(__m128*)&obj->f2c0;
    *(__m128*)&A.f090 = *(__m128*)&obj->f2d0;
    *(__m128*)&A.f0a0 = *(__m128*)&obj->f2e0;
    *(__m128*)&A.f0b0 = *(__m128*)&obj->f2f0;
    *(__m128*)&A.f0c0 = *(__m128*)&obj->f300;
    *(__m128*)&A.f0d0 = *(__m128*)&obj->f310;
    *(__m128*)&A.f0e0 = *(__m128*)&obj->f320;
    *(__m128*)&A.f0f0 = *(__m128*)&obj->f330;
    *(__m128*)&A.f100 = *(__m128*)&obj->f340;
    *(__m128*)&A.f110 = *(__m128*)&obj->f350;
    *(__m128*)&A.f120 = *(__m128*)&obj->f360;
    *(__m128*)&A.f130 = *(__m128*)&obj->f370;
    *(__m128*)&A.f140 = *(__m128*)&obj->f380;
    *(__m128*)&A.f150 = *(__m128*)&obj->f390;
    *(__m128*)&A.f160 = *(__m128*)&obj->f3a0;
    *(__m128*)&A.f170 = *(__m128*)&obj->f3b0;

    ResetJacobianRows(arg2, arg0, &A.f000, &A.f0c0);
    Object_ProcessEntries_00df07c0(arg2, arg3);
    _hkMatrix6SetTranspose(obj, arg3);
    hkMatrix3_ProcessEntries_00e29470(&C, obj, *arg4);

    dst = (__m128*)(&obj->f0c0);
    dst[0] = *(__m128*)&A.f000;
    dst[1] = *(__m128*)&A.f010;
    dst[2] = *(__m128*)&A.f020;
    dst[3] = *(__m128*)&A.f030;
    dst[4] = *(__m128*)&A.f040;
    dst[5] = *(__m128*)&A.f050;
    dst[6] = *(__m128*)&A.f060;
    dst[7] = *(__m128*)&A.f070;
    dst[8] = *(__m128*)&A.f080;
    dst[9] = *(__m128*)&A.f090;
    dst[10] = *(__m128*)&A.f0a0;
    dst[11] = *(__m128*)&A.f0b0;

    Object_SubtractVectorBundles(dst, &C);

    input = obj->f0c0;
    fClamped = (DAT_0104da4c < input) ? input : DAT_0104da4c;
    obj->f0c0 = fClamped;
    input = obj->f150;
    fClamped = (DAT_0104da4c < input) ? input : DAT_0104da4c;
    obj->f150 = fClamped;
    input = obj->f0d4;
    fClamped = (DAT_0104da4c < input) ? input : DAT_0104da4c;
    obj->f0d4 = fClamped;
    input = obj->f164;
    fClamped = (DAT_0104da4c < input) ? input : DAT_0104da4c;
    obj->f164 = fClamped;
    input = obj->f0e8;
    fClamped = (DAT_0104da4c < input) ? input : DAT_0104da4c;
    obj->f0e8 = fClamped;
    input = obj->f178;
    fClamped = (DAT_0104da4c < input) ? input : DAT_0104da4c;
    obj->f178 = fClamped;

    *(__m128*)&B.f000 = dst[0];
    *(__m128*)&B.f010 = dst[1];
    *(__m128*)&B.f020 = dst[2];
    *(__m128*)&B.f030 = dst[3];
    *(__m128*)&B.f040 = dst[4];
    *(__m128*)&B.f050 = dst[5];
    *(__m128*)&B.f060 = dst[6];
    *(__m128*)&B.f070 = dst[7];
    *(__m128*)&B.f080 = dst[8];
    *(__m128*)&B.f090 = dst[9];
    *(__m128*)&B.f0a0 = dst[10];
    *(__m128*)&B.f0b0 = dst[11];

    Runtime_ForwardCall_00e298f0(dst, &B.f000);

    p180 = &obj->f180;
    hkMatrix3_ProcessEntries_00e29470(p180, dst, (int)(&A.f0c0));

    arg3[0] = *(__m128*)&obj->f300;
    arg3[1] = *(__m128*)&obj->f310;
    arg3[2] = *(__m128*)&obj->f320;
    CopyHelper(arg3 + 3, &obj->f330);

    *arg4 = (int)p180;
}

struct MatrixGroup
{
    char data0[0xc0];
    char data1[0xc0];
    char pad[0x240];
};

struct InputStruct
{
    char pad0[4];
    int count;
    char pad1[0x18];
    MatrixGroup* matrices;
    char pad2[8];
    hkAabb* aabbs;
};

extern "C" void __cdecl hkVector4_ComputeValues_00e29510(void* out, const void* matrix, const void* in);

// @fnv 0x00df11a0
// src: GUESS 0x00df11a0 (confidence: low)
void __cdecl hkAabb_ProcessEntries_00df11a0(InputStruct* apInput, hkAabb* out)
{
    out++;
    out[-1].m_kMinimumCorner.m_vComponents = _mm_setzero_ps();
    out[-1].m_kMaximumCorner.m_vComponents = _mm_setzero_ps();

    int i = 0;
    if (apInput->count <= 0)
        return;

    int offset = 0;
    do
    {
        const hkAabb* aabb = (const hkAabb*)((const char*)apInput->aabbs + offset);
        // Scalar storage preserves the uninitialized temporary without adding /GS buffer checks.
        struct __declspec(align(16))
        {
            float minX, minY, minZ, minW;
            float maxX, maxY, maxZ, maxW;
        } tempAabbStorage;
        hkAabb& tempAabb = *(hkAabb*)&tempAabbStorage;
        hkVector4_ComputeValues_00e29510(&tempAabb, &apInput->matrices[i].data0, &out[i - 1]);
        tempAabb.m_kMinimumCorner.m_vComponents =
            _mm_sub_ps(_mm_load_ps(&aabb->m_kMinimumCorner.x), tempAabb.m_kMinimumCorner.m_vComponents);
        tempAabb.m_kMaximumCorner.m_vComponents =
            _mm_sub_ps(_mm_load_ps(&aabb->m_kMaximumCorner.x), tempAabb.m_kMaximumCorner.m_vComponents);
        hkVector4_ComputeValues_00e29510(&out[i], &apInput->matrices[i].data1, &tempAabb);
        ++i;
        offset += sizeof(hkAabb);
    } while (i < apInput->count);
}
