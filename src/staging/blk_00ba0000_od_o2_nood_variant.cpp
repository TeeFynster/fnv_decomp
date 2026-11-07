#define FNV64_HKVECTOR4_OWN_DEFAULT
#define FNV64_HKVECTOR4_OWN_ASSIGN

// src/staging/blk_00ba0000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00ba0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/staging/blk_00ba0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/Transform.h"
#include "../../include/hkVector4.h"
#include <string.h>
#include "../../include/NiPoint3.h"

struct Matrix
{
    float m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44;
};
struct __declspec(align(16)) AlignedMatrix : Matrix
{
};
struct Camera
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    NiPoint3 direction;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    NiPoint3 position;
    NiPoint3 up;
};
struct Geometry
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    AlignedMatrix view;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    Camera* camera;
};
struct Scene
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    Geometry** geometries;
};
extern Scene* DAT_011f91e0;
extern NiPoint3 DAT_011f474c;
extern hkVector4 DAT_01200510, DAT_01200520, DAT_01200540, DAT_01200570;
void __cdecl FUN_00b71a40(AlignedMatrix*, const Transform*, const NiPoint3*, float);
Matrix* __stdcall D3DXMatrixMultiply(Matrix*, const Matrix*, const Matrix*);
Matrix* __stdcall D3DXMatrixTranspose(Matrix*, const Matrix*);
struct Shader
{
    void TallGrassShader_SetupShadowData(int identity, const Transform* transform);
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    hkVector4 position;
    hkVector4 direction;
};
// @fnv 0x00baa850
// src: COMMUNITY 0x00baa850
void Shader::TallGrassShader_SetupShadowData(int identity, const Transform* transform)
{
    AlignedMatrix world;
    Matrix result;
    world.m12 = world.m13 = world.m14 = world.m21 = world.m23 = world.m24 = world.m31 = world.m32 = world.m34 =
        world.m41 = world.m42 = world.m43 = 0.0f;
    world.m11 = world.m22 = world.m33 = world.m44 = 1.0f;
    result.m11 = result.m22 = result.m33 = result.m44 = 1.0f;
    result.m12 = result.m13 = result.m14 = result.m21 = result.m23 = result.m24 = result.m31 = result.m32 = result.m34 =
        result.m41 = result.m42 = result.m43 = 0.0f;

    if (!identity)
        FUN_00b71a40(&world, transform, reinterpret_cast<const NiPoint3*>(&transform->position), transform->scale);
    world.m41 += DAT_011f474c.x;
    world.m42 += DAT_011f474c.y;
    world.m43 += DAT_011f474c.z;
    AlignedMatrix view = *static_cast<AlignedMatrix*>(&DAT_011f91e0->geometries[0]->view);
    AlignedMatrix product;
    D3DXMatrixMultiply(&product, &world, &view);
    result = product;
    D3DXMatrixTranspose(&result, &result);
    {
        float value[4] = {result.m11, result.m12, result.m13, result.m14};
        memcpy(&DAT_01200510, value, sizeof(value));
    }
    {
        float value[4] = {result.m21, result.m22, result.m23, result.m24};
        memcpy(&DAT_01200520, value, sizeof(value));
    }
    {
        float value[4] = {result.m31, result.m32, result.m33, result.m34};
        memcpy(&DAT_01200540, value, sizeof(value));
    }
    {
        float value[4] = {result.m41, result.m42, result.m43, result.m44};
        memcpy(&DAT_01200570, value, sizeof(value));
    }
    Camera* camera = DAT_011f91e0->geometries[0]->camera;
    NiPoint3 eye = camera->position;
    NiPoint3 forward = camera->direction;
    NiPoint3 up = camera->up;
    {
        float value[4] = {eye.x, eye.y, eye.z, 1.0f};
        memcpy(&position, value, sizeof(value));
    }
    {
        float value[4] = {forward.x, forward.y, forward.z, up.x};
        memcpy(&direction, value, sizeof(value));
    }
}
