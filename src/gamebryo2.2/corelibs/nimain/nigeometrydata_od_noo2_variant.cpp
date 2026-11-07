
// src/gamebryo2.2/corelibs/nimain/nigeometrydata_od_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /GF (unit src/gamebryo2.2/corelibs/nimain/nigeometrydata.cpp lists /MT /O2 /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "nigeometrydata_decls.h"
#pragma optimize("", off)
#pragma optimize("", on)

class NiGPUProgram;
class NiGPUProgramOwner
{
  public:
    void SetProgram(NiGPUProgram* program);
    void IncRefCount();
    void DecRefCount();
};

class ShaderOwner
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    NiPointer<NiGPUProgramOwner> m_spProgramOwner;
    void NiGeometry_SetAdditionalGeometryData(NiGPUProgram* program);
};

// @fnv 0x00539ef0
// src: COMMUNITY 0x00539ef0
void ShaderOwner::NiGeometry_SetAdditionalGeometryData(NiGPUProgram* program)
{
    ((NiGPUProgramOwner*)m_spProgramOwner)->SetProgram(program);
}
