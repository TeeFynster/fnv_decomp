// Provisional build file (plan B2): exact copies of the falloutcharacterprogression recipe for other original addresses.
// NiNodeBooleanState_falloutcharacterprogression_copies_033: local type (was include/NiNodeBooleanState.h, which had no evidence of one real class); its methods are 0x008d0360 ReturnTrue, 0x008d51f0 CharacterProgression::QReadyToLevelUp, 0x008d5270 CharacterProgression::FinishLevelUp
#include "../include/NiAVObject.h"

class NiNode;

class NiNodeBooleanState_falloutcharacterprogression_copies_033
{
public:
    NiPointer<NiNode> pData;

    __declspec(noinline) bool GetBooleanValue();
    void CharacterProgression_FinishLevelUp();
};

// @fnv 0x008d0360
bool NiNodeBooleanState_falloutcharacterprogression_copies_033::GetBooleanValue()
{
    return true;
}

// A second compiled copy of GetBooleanValue, with its object pointer in ECX.
// @fnv 0x00af2c40
bool __fastcall NiNodeBooleanState_GetBooleanValue_Copy(NiNodeBooleanState_falloutcharacterprogression_copies_033* state)
{
    return true;
}
