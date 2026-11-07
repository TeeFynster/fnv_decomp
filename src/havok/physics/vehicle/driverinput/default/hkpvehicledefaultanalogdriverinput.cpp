
// src/havok/physics/vehicle/driverinput/default/hkpvehicledefaultanalogdriverinput.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/driverinput/default/hkpvehicledefaultanalogdriverinput.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkReferencedObject.h"

typedef float hkReal;


// No shared driver-input header exists yet; reflection gives the 0x8-byte reference-counted base.
class hkpVehicleDriverInput : public hkReferencedObject
{
  public:
    hkpVehicleDriverInput() {}
};

// No shared default-input header exists yet; reflected members occupy offsets 0x8 through 0x14.
class hkpVehicleDefaultAnalogDriverInput : public hkpVehicleDriverInput
{
  public:
    hkReal m_fSlopeUp;
    hkReal m_fDeadZone;
    hkReal m_fSlopeDown;
    hkBool m_bAutoReverse;

    hkpVehicleDefaultAnalogDriverInput();
    virtual ~hkpVehicleDefaultAnalogDriverInput();
};

struct FUN_00e43540_Arg1
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    unsigned char unkcc;
};

struct FUN_00e43540_Arg2
{
    int unk00;
    int unk04;
    int unk08;
    float unk0c;
};

class FUN_00e43540_cls : public hkpVehicleDefaultAnalogDriverInput
{
  public:
    float hkpVehicleDefaultAnalogDriverInput_calcAcceleratorInput(int a0, FUN_00e43540_Arg1* a1, FUN_00e43540_Arg2* a2, int a3);
};

// @fnv 0x00e43540
// src: HAVOK_LIB 0x00e43540
float FUN_00e43540_cls::hkpVehicleDefaultAnalogDriverInput_calcAcceleratorInput(int aiUnused, FUN_00e43540_Arg1* a1, FUN_00e43540_Arg2* a2, int aiUnused2)
{
    float v;
    if (a1->unkcc != 0 && m_bAutoReverse != 0)
    {
        v = -a2->unk0c;
    }
    else
    {
        v = a2->unk0c;
    }
    if (m_bAutoReverse == 0 && a1->unkcc != 0)
    {
        return 1.0f;
    }
    if (v > 0.0f)
    {
        return 0.0f;
    }
    volatile float r = (float)(v * -1.0);
    return r;
}

struct VehicleStatus
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned char unk10;
};

struct VehicleOutput
{
    float x;
    float y;
    float z;
    unsigned char autoReverse;
    unsigned char buttonPressed;
};

struct ButtonResult
{
    unsigned char value;
};

struct VehicleInput
{
    virtual void virtual0();
    virtual void virtual1();
    virtual void virtual2();
    virtual void virtual3();
    virtual float calculateX(float timeStep, void* vehicle, VehicleStatus* status, VehicleOutput* output);
    virtual float calculateY(float timeStep, void* vehicle, VehicleStatus* status, VehicleOutput* output);
    virtual ButtonResult calculateButton(float timeStep, void* vehicle, VehicleStatus* status, VehicleOutput* output);
    virtual float calculateZ(float timeStep, void* vehicle, VehicleStatus* status, VehicleOutput* output);
    void CalculateOutput(float timeStep, void* vehicle, VehicleStatus* status, VehicleOutput* output);
};

// Fills output with the results of calculateX, calculateY, calculateZ and calculateButton, and copies status->unk10 into output->autoReverse.
// @fnv 0x00e435f0
void VehicleInput::CalculateOutput(float timeStep, void* vehicle, VehicleStatus* status, VehicleOutput* output)
{
    output->x = calculateX(timeStep, vehicle, status, output);
    output->y = calculateY(timeStep, vehicle, status, output);
    output->z = calculateZ(timeStep, vehicle, status, output);
    output->autoReverse = status->unk10;
    output->buttonPressed = calculateButton(timeStep, vehicle, status, output).value;
}

// Initializes the three hkReal members and the hkBool member to zero/false.
// @fnv 0x00e43680
hkpVehicleDefaultAnalogDriverInput::hkpVehicleDefaultAnalogDriverInput()
{
    m_fSlopeUp = 0.0f;
    m_fDeadZone = 0.0f;
    m_fSlopeDown = 0.0f;
    m_bAutoReverse = false;
}


// VehicleReverseState: m_iGearCount sits at offset 0xcc.
struct VehicleReverseState
{
    char pad0[0xcc];
    char m_iGearCount;
};

struct hkpVehicleDriverInputFilteredInput
{
    char pad0[0xc];
    hkReal m_uiFilterValue;
};

// this-call wrapper with the layout of hkpVehicleDefaultAnalogDriverInput
struct AnalogDriverInput
{
    char pad0[0x14];
    char m_bAutoReverse;

    hkReal hkpVehicleDefaultAnalogDriverInput_calcBrakeInput(hkReal deltaTime, const VehicleReverseState* status,
                        const hkpVehicleDriverInputFilteredInput* input, int wheel);
};

// Returns the input's filter value, negated if the status byte and m_bAutoReverse are both set, with negative results returned as 0.
// @fnv 0x00e435a0
// src: HAVOK_LIB 0x00e435a0
hkReal AnalogDriverInput::hkpVehicleDefaultAnalogDriverInput_calcBrakeInput(hkReal deltaTime, const VehicleReverseState* status,
                                       const hkpVehicleDriverInputFilteredInput* input, int wheel)
{
    char reversing = status->m_iGearCount;
    hkReal v;
    if (reversing && m_bAutoReverse)
    {
        v = -input->m_uiFilterValue;
        if (!reversing)  // unreachable: keeps the flag live in a register
            v = input->m_uiFilterValue;
    }
    else
    {
        v = input->m_uiFilterValue;
    }

    if (v < 0.0f)
        return 0.0f;
    return v;
}

// No shared router header exists yet; the TLS accessor at 0x00c85750 supplies its heap at offset 0x10.
#include "../../../../../../include/hkMemoryRouter.h"

namespace hkRouterE43A {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}

inline void* __cdecl hkReferencedObject::operator new(std::size_t nbytes)
{
    hkReferencedObject* b = static_cast<hkReferencedObject*>(hkRouterE43A::hkMemoryRouter_getInstance().heap().blockAlloc(nbytes));
    b->m_usMemSizeAndFlags = (unsigned short)nbytes;
    return b;
}

// Reflected analog-status members: positions at 0x8/0xc, flags at 0x10/0x11, total size 0x14.
class hkpVehicleDriverInputAnalogStatus : public hkReferencedObject
{
  public:
    float m_fPositionX;
    float m_fPositionY;
    hkBool m_bFlag;
    hkBool m_bReverseButtonPressed;

    virtual ~hkpVehicleDriverInputAnalogStatus();
    hkpVehicleDriverInputAnalogStatus* clone_00e43a60() const;
};

// Allocates a new hkpVehicleDriverInputAnalogStatus, copies the current object into it, and returns the pointer to the copy.
// @fnv 0x00e43a60
// src: HAVOK_LIB 0x00e43a60
hkpVehicleDriverInputAnalogStatus* hkpVehicleDriverInputAnalogStatus::clone_00e43a60() const
{
    hkpVehicleDriverInputAnalogStatus* p = new hkpVehicleDriverInputAnalogStatus;
    *p = *this;
    return p;
}

#include <math.h>
namespace fnv_00e436b0 {
typedef float hkReal;

struct AnalogStatus
{
    void* vtable;
    int refCount;
    hkReal m_fPositionX;
    hkReal m_fPositionY;
};

inline hkReal hkFabs(hkReal r)
{
    return (hkReal)fabs(r);
}

class AnalogDriverInput
{
  public:
    void* vtable;
    int refCount;
    hkReal m_fSlopeUp;
    hkReal m_fDeadZone;
    hkReal m_fSlopeDown;
    bool m_bAutoReverse;

    hkReal GetOutput(hkReal deltaTime, const void* vehicle, const AnalogStatus* status, void* out) const;
};

// Computes a signed analog output value from the input position using the dead-zone and slope parameters.
// @fnv 0x00e436b0
hkReal AnalogDriverInput::GetOutput(hkReal deltaTime, const void* vehicle, const AnalogStatus* status, void* out) const
{
    const hkReal x = status->m_fPositionX;
    const hkReal fAbsPositionX = hkFabs(x);
    if (fAbsPositionX < m_fSlopeDown)
        return 0.0f;
    const hkReal sign = (x > 0.0f) ? 1.0f : -1.0f;
    if (fAbsPositionX < m_fSlopeUp)
    {
        const hkReal v = (fAbsPositionX - m_fSlopeDown) * m_fDeadZone;
        return v * sign;
    }
    const hkReal changeY = (m_fSlopeUp - m_fSlopeDown) * m_fDeadZone;
    const hkReal secondSlope = (1.0f - changeY) / ((1.0f - m_fSlopeDown) - (m_fSlopeUp - m_fSlopeDown));
    const hkReal v = changeY + (fAbsPositionX - m_fSlopeUp) * secondSlope;
    return v * sign;
}
}  // namespace fnv_00e436b0

// Exe 0x00e43780 FUN_00e43780: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef struct __declspec(intrin_type) __declspec(align(16)) {
    float f0, f1, f2, f3;
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_load_ps(const float*);
    void _mm_store_ss(float*, LocalM128);
    float _mm_cvtss_f32(LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_sqrt_ss(LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
}

extern const float DAT_01011d78 = 0.0f;
extern const float DAT_01016248 = 0.5f;
extern const float DAT_01017718 = 3.0f;
extern const float DAT_0104da4c = 1.1920928955078125e-07f;
extern const float DAT_010ebf10 = 1.38888896f;
extern const double DAT_0101ffa0 = 0.10000000149011612;

namespace e43780 {
struct HkVec
{
    float x, y, z, w;
    __forceinline const LocalM128& quad() const
    {
        return *(const LocalM128*)&x;
    }
};

struct Pad40
{
    int u00, u04, u08, u0c;
    int u10, u14, u18, u1c;
    int u20, u24, u28, u2c;
    int u30, u34, u38, u3c;
};

struct VehInst
{
    Pad40 p00, p40, p80;
    int uc0, uc4, uc8, ucc;
    int ud0, ud4, ud8, udc;
    int ue0, ue4, ue8, uec;
    HkVec m_kColumn0;
    HkVec m_kColumn1;
    HkVec m_kColumn2;
    Pad40 p120, p160;
    int u1a0, u1a4, u1a8, u1ac;
    HkVec m_pos;
};

struct ChassisX
{
    Pad40 p00;
    HkVec m_pos;
};

struct StatusX
{
    int u00, u04, u08, u0c, u10, u14;
    VehInst* m_veh;
    ChassisX* m_pChassisCollidable;
    Pad40 p20, p60;
    int ua0, ua4, ua8, uac;
    int ub0, ub4, ub8, ubc;
    int uc0, uc4, uc8;
    char m_iGearCount;
};

struct InputX
{
    int u00, u04, u08;
    hkReal m_uiFilterValue;
    char u10;
    ButtonResult m_flag;
};

static __forceinline ButtonResult makeBtn(unsigned char v)
{
    ButtonResult r;
    r.value = v;
    return r;
}

static __forceinline LocalM128 sqrtInv(LocalM128 x)
{
    LocalM128 r = _mm_rsqrt_ss(x);
    LocalM128 nr = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(DAT_01016248), r),
                           _mm_sub_ss(_mm_set_ss(DAT_01017718), _mm_mul_ss(_mm_mul_ss(x, r), r)));
    return _mm_andnot_ps(_mm_cmpeq_ss(x, _mm_set_ss(DAT_01011d78)), nr);
}

static __forceinline LocalM128 reduce3(LocalM128 m)
{
    LocalM128 s = _mm_shuffle_ps(m, m, 0x55);
    s = _mm_add_ss(s, m);
    LocalM128 t = _mm_shuffle_ps(m, m, 0xaa);
    return _mm_add_ss(t, s);
}

static __forceinline LocalM128 rotateDir(VehInst* veh, const HkVec& bodyPos)
{
    HkVec col0 = veh->m_kColumn0;
    HkVec col1 = veh->m_kColumn1;
    HkVec col2 = veh->m_kColumn2;

    LocalM128 v = _mm_load_ps(&bodyPos.x);
    LocalM128 r0 = _mm_load_ps(&col0.x);
    LocalM128 q = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), _mm_load_ps(&col1.x));
    q = _mm_add_ps(q, _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), r0));
    LocalM128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), _mm_load_ps(&col2.x));
    return _mm_add_ps(q, z);
}

class Cls : public hkpVehicleDefaultAnalogDriverInput
{
  public:
    ButtonResult hkpVehicleDefaultAnalogDriverInput_calcTryingToReverse(int a1, StatusX* status, InputX* input, int a4);
};

// Returns input->m_flag unless m_bAutoReverse is set, then picks a ButtonResult from the gear flag, filter value, a vector length and a normalized dot product.
// @fnv 0x00e43780
// src: HAVOK_SRC 0x00e43780
ButtonResult Cls::hkpVehicleDefaultAnalogDriverInput_calcTryingToReverse(int a1, StatusX* status, InputX* input, int a4)
{
    if (!m_bAutoReverse)
    {
        return input->m_flag;
    }

    VehInst* veh = status->m_veh;
    HkVec pos = veh->m_pos;
    char bReverse = status->m_iGearCount;

    float len;
    _mm_store_ss(&len, _mm_sqrt_ss(reduce3(_mm_mul_ps(pos.quad(), pos.quad()))));

    bool bLess = len < DAT_010ebf10;

    unsigned char res;
    if (input->m_uiFilterValue > DAT_0101ffa0)
    {
        res = 1;
        if (len > DAT_0104da4c)
        {
            HkVec bodyPos = status->m_pChassisCollidable->m_pos;
            LocalM128 q = rotateDir(veh, bodyPos);

            LocalM128 invP = sqrtInv(reduce3(_mm_mul_ps(pos.quad(), pos.quad())));
            LocalM128 invQ = sqrtInv(reduce3(_mm_mul_ps(q, q)));
            LocalM128 np = _mm_mul_ps(_mm_shuffle_ps(invP, invP, 0), pos.quad());
            LocalM128 nq = _mm_mul_ps(_mm_shuffle_ps(invQ, invQ, 0), q);
            float fDot;
            _mm_store_ss(&fDot, reduce3(_mm_mul_ps(nq, np)));

            if (fDot < DAT_0104da4c)
            {
                return makeBtn(1);
            }
        }
    }
    else
    {
        res = 0;
    }

    if (bReverse)
    {
        if (bLess)
        {
            return makeBtn(res);
        }
        return makeBtn(1);
    }
    else
    {
        if (bLess && res)
        {
            return makeBtn(1);
        }
        return makeBtn(0);
    }
}
}
