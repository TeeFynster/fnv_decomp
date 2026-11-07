#include <xmmintrin.h>
typedef ::__m128 LocalM128;
// src/havok/physics/dynamics/motion/util/hkprigidmotionutil_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/motion/util/hkprigidmotionutil_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS- /EHs-c- /Gy (unit lists /MT /O2 /GS- /EHs-c- /Gy). Declarations copied from that unit's skeleton.

// src/havok/physics/dynamics/motion/util/hkprigidmotionutil_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-11-01 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/dynamics/motion/util/hkprigidmotionutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/dynamics/motion/util/hkprigidmotionutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/util/hkprigidmotionutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <math.h>
namespace StepReleaseFitPrivate {
typedef ::__m128 LocalM128;
extern "C"
{
    void _ReadWriteBarrier();
using ::_mm_store_ps;
using ::_mm_load_ss;
using ::_mm_shuffle_ps;
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_sub_ps;
using ::_mm_add_ss;
using ::_mm_and_ps;
using ::_mm_cmplt_ps;
using ::_mm_cmpeq_ps;
using ::_mm_movemask_ps;
using ::_mm_store_ss;
}

static __forceinline LocalM128 StepReleaseFitbroadcast(float f)
{
    LocalM128 v = _mm_load_ss(&f);
    return _mm_shuffle_ps(v, v, 0);
}
static __forceinline float StepReleaseFitscalarCopy(float f)
{
    return f;
}

extern const LocalM128 DAT_01017d10;
extern const LocalM128 DAT_010cbf80;
extern const LocalM128 DAT_01268370;
extern const float DAT_010c7948[256];
extern const double DAT_01011588;
extern const double DAT_010ce4b0;
extern const double DAT_0106b9e8;
extern const double DAT_0101ff40;
extern const float DAT_010177e8;

struct __declspec(align(16)) StepReleaseFitQuaternion
{
    union
    {
        struct
        {
            float x, y, z, w;
        };
        struct
        {
            unsigned int ix, iy, iz, iw;
        };
    };
    void setMul(const StepReleaseFitQuaternion*, const StepReleaseFitQuaternion*);
    void normalize_005611c0();
};
struct StepReleaseFitMotionState
{
    LocalM128 rotationX, rotationY, rotationZ;
    LocalM128 translation;
    LocalM128 center0;
    LocalM128 center1;
    StepReleaseFitQuaternion rotation0;
    StepReleaseFitQuaternion rotation1;
    LocalM128 centerLocal;
    LocalM128 deltaAngle;
    float objectRadius, linearDamping, angularDamping;
    unsigned char maxLinear, maxAngular, unkAE, unkAF;
    unsigned int unkB0, unkB4, unkB8, unkBC;
    void hkRotation_set(const StepReleaseFitQuaternion*);
};
struct StepReleaseFitMotion
{
    void* vtable;
    unsigned int unk04;
    unsigned char type, unk09, unk0A, unk0B;
    unsigned int unk0C;
    StepReleaseFitMotionState state;
    LocalM128 linearVelocity;
    LocalM128 angularVelocity;
};
struct StepReleaseFitStepInfo
{
    float startTime, endTime, deltaTime, invDeltaTime;
};
static __forceinline float StepReleaseFitlengthSquared3(LocalM128 v)
{
    LocalM128 squares = _mm_mul_ps(v, v);
    LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(squares, squares, 0x55), squares);
    LocalM128 xyz = _mm_add_ss(_mm_shuffle_ps(squares, squares, 0xaa), xy);
    float result;
    _mm_store_ss(&result, xyz);
    return result;
}
static __forceinline float StepReleaseFitcosineApprox(float squaredAngle)
{
    float fourth = squaredAngle * squaredAngle;
    return (float)(1.0 - double(0.822948f) * squaredAngle - double(0.130529f) * fourth -
                   double(0.044408f) * squaredAngle * fourth);
}
struct StepReleaseFitStepArgs
{
    const StepReleaseFitStepInfo* info;
    void** objects;
    int count;
    int motionOffset;
    const StepReleaseFitStepInfo& step() const
    {
        return *info;
    }
    StepReleaseFitMotion& motion() const
    {
        return *(StepReleaseFitMotion*)((char*)*objects + motionOffset);
    }
    void advance()
    {
        ++objects;
    }
};
static __forceinline bool StepReleaseFitcheckVelocities(StepReleaseFitMotion* motion)
{
    LocalM128 limit = DAT_010cbf80;
    LocalM128 mask = DAT_01017d10;
    LocalM128 linear = motion->linearVelocity;
    LocalM128 angular = motion->angularVelocity;
    LocalM128 absLinear = _mm_and_ps(linear, mask);
    LocalM128 absAngular = _mm_and_ps(angular, mask);
    int valid = _mm_movemask_ps(_mm_cmplt_ps(absLinear, limit)) & _mm_movemask_ps(_mm_cmplt_ps(absAngular, limit));
    valid &= _mm_movemask_ps(_mm_cmpeq_ps(linear, linear)) & _mm_movemask_ps(_mm_cmpeq_ps(angular, angular));
    return (valid & 7) == 7;
}
struct StepReleaseFitStateArgument
{
    StepReleaseFitMotionState* p;
};
static __forceinline void StepReleaseFitadvanceMotion(StepReleaseFitStateArgument late,
                                                      const StepReleaseFitStepInfo& info,
                                                      StepReleaseFitMotionState& state, LocalM128& angularVelocity,
                                                      LocalM128& linearVelocity, StepReleaseFitMotion* motion)
{
    state.center1 = _mm_add_ps(
        _mm_mul_ps(StepReleaseFitbroadcast(StepReleaseFitscalarCopy(info.deltaTime)), linearVelocity), state.center1);
    state.center1.m128_f32[3] = info.invDeltaTime;
    _ReadWriteBarrier();
    StepReleaseFitQuaternion previous;
    previous.ix = state.rotation1.ix;
    previous.iy = state.rotation1.iy;
    previous.iz = state.rotation1.iz;
    previous.iw = state.rotation1.iw;
    *(LocalM128*)&state.rotation0 = *(LocalM128*)&previous;
    LocalM128 oldAngular = angularVelocity;
    float halfStep = (float)(info.deltaTime * DAT_01011588);
    StepReleaseFitQuaternion increment;
    *(LocalM128*)&increment = _mm_mul_ps(StepReleaseFitbroadcast(halfStep), oldAngular);
    float angleSquared = (float)(StepReleaseFitlengthSquared3(*(LocalM128*)&increment) * DAT_010ce4b0);
    float maxAngleProduct = DAT_010c7948[state.maxAngular] * info.deltaTime;
    float maxAngle = maxAngleProduct > DAT_0106b9e8 ? DAT_010177e8 : maxAngleProduct;
    float maxAngleSquared = maxAngle * maxAngle;
    if (angleSquared <= maxAngleSquared)
    {
        increment.w = StepReleaseFitcosineApprox(angleSquared);
    }
    else
    {
        float angle = (float)sqrt(angleSquared);
        float inverse = 1.0f / angle;
        float factor = inverse * maxAngle;
        angleSquared = maxAngle * maxAngle;
        angularVelocity = _mm_mul_ps(StepReleaseFitbroadcast(factor), oldAngular);
        *(LocalM128*)&increment = _mm_mul_ps(StepReleaseFitbroadcast(factor), *(LocalM128*)&increment);
        increment.w = StepReleaseFitcosineApprox(angleSquared);
    }
    previous.setMul(&increment, &previous);
    previous.normalize_005611c0();
    state.deltaAngle = _mm_add_ps(*(LocalM128*)&increment, *(LocalM128*)&increment);
    float angle = (float)sqrt(angleSquared);
    state.deltaAngle.m128_f32[3] = (float)(angle * DAT_0101ff40);
    _mm_store_ps((float*)&state.rotation1, *(LocalM128*)&previous);
    state.hkRotation_set(&late.p->rotation1);
}
// @fnv 0x00d28680
// src: XBOX_PDB 0x00d28680
extern "C" void __cdecl hkRigidMotionUtilStep(StepReleaseFitStepArgs args)
{
    for (int remaining = args.count - 1; remaining >= 0; args.advance(), --remaining)
    {
        StepReleaseFitMotion* motion = &args.motion();
        if (motion->type == 5)
            continue;
        StepReleaseFitMotionState& state = motion->state;
        if (!StepReleaseFitcheckVelocities(motion))
        {
            motion->linearVelocity = DAT_01268370;
            motion->angularVelocity = DAT_01268370;
        }
        LocalM128 center = state.center1;
        const StepReleaseFitStepInfo* info = args.info;
        _ReadWriteBarrier();
        state.center0 = center;
        state.center0.m128_f32[3] = info->startTime;
        _ReadWriteBarrier();
        LocalM128 oldLinear = motion->linearVelocity;
        unsigned int maxLinearIndex = state.maxLinear;
        double maxLinear = DAT_010c7948[maxLinearIndex];
        float speedSquared;
        {
            LocalM128 squares = _mm_mul_ps(oldLinear, oldLinear);
            LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(squares, squares, 0x55), squares);
            LocalM128 xyz = _mm_add_ss(_mm_shuffle_ps(squares, squares, 0xaa), xy);
            _mm_store_ss(&speedSquared, xyz);
        }
        if (speedSquared > maxLinear * maxLinear)
        {
            float speed = (float)sqrt(speedSquared);
            float inverse = 1.0f / speed;
            float factor = inverse * DAT_010c7948[maxLinearIndex];
            info = args.info;
            motion->linearVelocity = _mm_mul_ps(StepReleaseFitbroadcast(factor), oldLinear);
        }
        StepReleaseFitStateArgument lateInput = {&motion->state};
        StepReleaseFitadvanceMotion(lateInput, *info, state, motion->angularVelocity, motion->linearVelocity, motion);
        LocalM128 local = state.centerLocal;
        LocalM128 rotated = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(local, local, 0x55), state.rotationY),
                                               _mm_mul_ps(_mm_shuffle_ps(local, local, 0), state.rotationX)),
                                    _mm_mul_ps(_mm_shuffle_ps(local, local, 0xaa), state.rotationZ));
        state.translation = _mm_sub_ps(state.center1, rotated);
    }
}

}
