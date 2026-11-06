#pragma once

#include "bhkconvert_decls.h"
#pragma strict_gs_check(on)
// @fnv 0x0056df80
hkTransform& FromHK(hkTransform& out, const NiTransform& in)
{
    VisitAndFetchThree(*reinterpret_cast<hkRotation*>(&reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(&out)->GetItem()),
                       in.m_Rotate);
    // The conversion fills SIMD storage without calling a default constructor.
    __m128 position;
    reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(&position)->GetItem();
    out.FUN_0056d300(FUN_004a3e00(reinterpret_cast<hkVector4&>(position), in.m_Translate));
    return out;
}

#pragma strict_gs_check(on)
// @fnv 0x00458620
NiPoint3& SetNiPoint3FromHkVector4(NiPoint3& out, const hkVector4& in)
{
    // These output lanes are initialized by FUN_00458700.
    __m128 x, y, z;
    out.x = FUN_004587d0(in.FUN_00458700(reinterpret_cast<hkSimdReal&>(x), 0).getReal());
    out.y = FUN_004587d0(in.FUN_00458700(reinterpret_cast<hkSimdReal&>(y), 1).getReal());
    out.z = FUN_004587d0(in.FUN_00458700(reinterpret_cast<hkSimdReal&>(z), 2).getReal());
    return out;
}
