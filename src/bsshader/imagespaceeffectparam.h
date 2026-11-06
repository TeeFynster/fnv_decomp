#ifndef FNV_IMAGESPACEEFFECTPARAM_H
#define FNV_IMAGESPACEEFFECTPARAM_H
// The 4-float colour constructed here is Gamebryo's NiColorA (Xbox PDB: NiColorA::NiColorA at this address).
#include "../../include/NiColorA.h"
// @fnv 0x00414430
NiColorA::NiColorA(float fR, float fG, float fB, float fA)
{
    r = fR;
    g = fG;
    b = fB;
    a = fA;
}
#endif
