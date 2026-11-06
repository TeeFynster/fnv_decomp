#include "../../include/bhkUnaryAction.h"
#include <xmmintrin.h>

// @fnv 0x004b4d50
void bhkUnaryAction::Set(float x, float y, float z, float w)
{
    *reinterpret_cast<__m128*>(this) = _mm_setr_ps(x, y, z, w);
}
