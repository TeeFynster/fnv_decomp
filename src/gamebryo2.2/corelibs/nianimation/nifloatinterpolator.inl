
#include "nifloatinterpolator_decls.h"
// @fnv 0x0052ce40
void NiFloatInterpolator::SetAnimationKeys(TimedAnimationKey* keys, unsigned int count, NiAnimationKey::KeyType type)
{
    if (count > 0) {
        if (!data.operator->())
            data = new NiFloatData;
        data->SetColorKeys(keys, count, type);
        lastIndex = 0;
    } else {
        if (data.operator->())
            data->SetColorKeys(0, 0, NiAnimationKey::NOINTERP);
    }
}
