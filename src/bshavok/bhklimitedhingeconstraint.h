
#include "bhklimitedhingeconstraint_decls.h"
// @fnv 0x00caade0
void bhkLimitedHingeConstraint::PopulateOutput(bhkLimitedHingeOutput* output)
{
    reinterpret_cast<void (__thiscall*)(bhkLimitedHingeConstraint*, bhkLimitedHingeOutput*)>(bhkConvexShape_CopyCinfo)(this, output);
    output->first.SetQuaternionComponentsFromVector(GetFirst());
    output->second.SetQuaternionComponentsFromVector(GetSecond());
}
