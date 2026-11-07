
// src/gamebryo2.2/corelibs/nimain/niquaternion_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/niquaternion.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "niquaternion_decls.h"
extern const unsigned int DAT_011a9e98[3];

struct M3_
{
    void FUN_004b4660(unsigned int, float, float, float);
};

struct FUN_004f0180_Class
{
    float w;
    float x;
    float y;
    float z;

    void NiQuaternion_ToRotation(M3_* rot);
};

// @fnv 0x004f0180
// src: XBOX_PDB 0x004f0180
void FUN_004f0180_Class::NiQuaternion_ToRotation(M3_* rot)
{
    float tx;
    float twy;
    float tyz;
    float twz;
    float tz;
    float txx;
    float txy;
    float tyy;
    float txz;
    float ty;
    float twx;
    float tzz;

    tx = 2.0 * x;
    ty = 2.0 * y;
    tz = 2.0 * z;

    twx = tx * w;
    twy = ty * w;
    twz = tz * w;
    txx = tx * x;
    txy = ty * x;
    txz = tz * x;
    tyy = ty * y;
    tyz = tz * y;
    tzz = tz * z;

    rot->FUN_004b4660(0, 1.0f - (tyy + tzz), txy + twz, txz - twy);
    rot->FUN_004b4660(1, txy - twz, 1.0f - (txx + tzz), tyz + twx);
    rot->FUN_004b4660(2, txz + twy, tyz - twx, 1.0f - (txx + tyy));
}
