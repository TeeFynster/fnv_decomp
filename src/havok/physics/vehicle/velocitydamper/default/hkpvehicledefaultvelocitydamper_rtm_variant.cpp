
// src/havok/physics/vehicle/velocitydamper/default/hkpvehicledefaultvelocitydamper_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/vehicle/velocitydamper/default/hkpvehicledefaultvelocitydamper.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/vehicle/velocitydamper/default/hkpvehicledefaultvelocitydamper.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/velocitydamper/default/hkpvehicledefaultvelocitydamper.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpVehicleDefaultVelocityDamper.h"

#include <emmintrin.h>

extern double DAT_01012060;

class FnvVehicleState
{
  public:
    void hkpRigidBody_setAngularVelocity(const hkVector4* value);
};

class FnvVehicleDefaultVelocityDamper : public hkpVehicleDefaultVelocityDamper
{
  public:
    void hkpVehicleDefaultVelocityDamper_applyVelocityDamping(float timeStep, const void* data);
};

// @fnv 0x00e43ae0
// src: HAVOK_SRC 0x00e43ae0
void __thiscall FnvVehicleDefaultVelocityDamper::hkpVehicleDefaultVelocityDamper_applyVelocityDamping(float timeStep, const void* data)
{
    const char* dataBase = reinterpret_cast<const char*>(data);
    const float* state = *reinterpret_cast<const float* const*>(dataBase + 0x18);

    __declspec(align(16)) hkVector4 values;
    unsigned int* scalarCopy = reinterpret_cast<unsigned int*>(&values);
    const unsigned int* scalarSource = reinterpret_cast<const unsigned int*>(state + 0x1C0 / 4);
    scalarCopy[0] = scalarSource[0]; scalarCopy[1] = scalarSource[1];
    scalarCopy[2] = scalarSource[2]; scalarCopy[3] = scalarSource[3];

    __m128 vector = _mm_load_ps(&values.x);
    __m128 squares = _mm_mul_ps(vector, vector);

    __m128 sum01 = _mm_shuffle_ps(squares, squares, 0x55);
    sum01 = _mm_add_ss(sum01, squares);

    __m128 sum2 = _mm_shuffle_ps(squares, squares, 0xAA);
    sum2 = _mm_add_ss(sum2, sum01);

    float threshold2 = this->m_fCollisionThreshold * this->m_fCollisionThreshold;
    float factor;
    if (_mm_cvtss_f32(sum2) > threshold2)
        factor = 1.0f - this->m_fCollisionSpinDamping * timeStep;
    else
        factor = 1.0f - this->m_fSpinDamping * timeStep;
    factor = (float)((factor < DAT_01012060) ? 0.0 : (double)factor);

    const float& fr = factor;
    __m128 s = _mm_load_ss(&fr);
    s = _mm_shuffle_ps(s, s, 0);
    __m128 scaled = _mm_mul_ps(s, vector);
    _mm_store_ps(&values.x, scaled);

    FnvVehicleState* st = (FnvVehicleState*)state;
    st->hkpRigidBody_setAngularVelocity(&values);
}
