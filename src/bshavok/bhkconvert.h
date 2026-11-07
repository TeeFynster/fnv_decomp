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
    out.bhkRigidBodyCinfo_SetPosition(NI2HK(reinterpret_cast<hkVector4&>(position), in.m_Translate));
    return out;
}

#pragma strict_gs_check(on)
// @fnv 0x00458620
NiPoint3& SetNiPoint3FromHkVector4(NiPoint3& out, const hkVector4& in)
{
    // These output lanes are initialized by FUN_00458700.
    __m128 x, y, z;
    out.x = HK2NI(in.hkVector4_getSimdAt(reinterpret_cast<hkSimdReal&>(x), 0).getReal());
    out.y = HK2NI(in.hkVector4_getSimdAt(reinterpret_cast<hkSimdReal&>(y), 1).getReal());
    out.z = HK2NI(in.hkVector4_getSimdAt(reinterpret_cast<hkSimdReal&>(z), 2).getReal());
    return out;
}
