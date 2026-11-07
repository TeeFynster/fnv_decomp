
#include "../../../../include/BSBlendTreadTransfInterpolator.h"
#include "../../../../include/NiBlendInterpolator.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/BSTreadTransfInterpolator.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiQuaternion.h"
// @fnv 0x00a432d0
bool BSBlendTreadTransfInterpolator::UpdateTransform(float time, NiObjectNET* target, NiQuatTransform& arValue)
{
    bool result = false;
    if (m_ucInterpCount == 1)
        result = UpdateSingleInterpolator(time, target, arValue);
    else if (m_ucInterpCount > 0)
    {
        NormalizeWeights();
        result = UpdateAccumulatedTransform(time, target, arValue);
    }
    m_fLastTime = time;
    return result;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f3ed0;

// @fnv 0x00a42fe0
// src: COMMUNITY 0x00a42fe0
GlobalObjectO2_00a7b610* __cdecl BSBlendTreadTransfInterpolator_GetRTTI()
{
    return &g_011f3ed0;
}

extern int DAT_01097904;
NiBlendInterpolator* __fastcall NiBlendInterpolator_NiBlendInterpolator(NiBlendInterpolator*);
// @fnv 0x00a42ff0
NiObject* BSBlendTreadTransfInterpolator::MakeClone(CloningProcess& kCloning)
{
    BSBlendTreadTransfInterpolator* pkObject;
    pkObject = (BSBlendTreadTransfInterpolator*)BSFadeNode::operator new(0x34);
    if (pkObject)
    {
        NiBlendInterpolator_NiBlendInterpolator(pkObject);
        pkObject->m_fPhase = 0.0f;
        *(void**)pkObject = (void*)&DAT_01097904;
    }
    else
    {
        pkObject = 0;
    }
    CopyMembers(pkObject, &kCloning);
    pkObject->m_fPhase = m_fPhase;
    return pkObject;
}

// @fnv 0x00a39100
// src: COMMUNITY 0x00a39100
bool __stdcall NiBlendAccumTransformInterpolator_InterpolatorIsCorrectType(NiInterpolator* pkInterpolator)
{
    return pkInterpolator->IsTransformValueSupported();
}

namespace fnv_00a43160 {
extern const NiPoint3 DAT_011a8400;
extern const NiQuaternion DAT_011f3704;
extern const float DAT_01096b8c;
extern const float DAT_0109696c;
extern const double DAT_01012070;
extern const float DAT_01015f5c;

} // namespace fnv_00a43160

// Keep the original bitwise quaternion copies independent of operator= in the headers.
static __forceinline void CopyTreadQuaternion(NiQuaternion& destination, const NiQuaternion& source)
{
    unsigned int* out = reinterpret_cast<unsigned int*>(&destination);
    const unsigned int* in = reinterpret_cast<const unsigned int*>(&source);
    out[0] = in[0];
    out[1] = in[1];
    out[2] = in[2];
    out[3] = in[3];
}

__forceinline NiQuatTransform::NiQuatTransform()
{
    reinterpret_cast<NiPoint3&>(x) = fnv_00a43160::DAT_011a8400;
    CopyTreadQuaternion(reinterpret_cast<NiQuaternion&>(qx), fnv_00a43160::DAT_011f3704);
    scale = fnv_00a43160::DAT_01096b8c;
}

class NiBlendInterpolator__InterpArrayItem
{
  public:
    NiInterpolator* interpolator;
    float weight;
    float normalizedWeight;
    int priority;
    float easeSpinner;
    float time;
};
// @fnv 0x00a43160
bool BSBlendTreadTransfInterpolator::UpdateAccumulatedTransform(float time, NiObjectNET* object, NiQuatTransform& arResult)
{
    using namespace fnv_00a43160;
    float total = 0.0f;
    for (unsigned char i = 0; i < m_ucArraySize; ++i)
    {
        NiBlendInterpolator__InterpArrayItem& item = m_pInterpArray[i];
        if (item.interpolator && item.normalizedWeight > 0.0f)
        {
            float sampleTime = time;
            if (item.normalizedWeight != 0.0f)
            {
                if (m_uiObjectFlags & 1)
                    sampleTime = item.time;
                if (sampleTime != DAT_0109696c)
                {
                    NiQuatTransform transform;
                    if (item.interpolator->UpdateTransform(sampleTime, object, transform))
                    {
                        total += static_cast<BSTreadTransfInterpolator*>(item.interpolator)->secondValue * item.normalizedWeight;
                    }
                }
            }
        }
    }
    float& combined = m_fPhase;
    combined += total;
    if (combined > 1.0f)
        m_fPhase = combined - DAT_01012070;
    else if (combined < 0.0f)
        m_fPhase = combined + DAT_01012070;
    float* __restrict pfOut = (float*)&arResult;
    pfOut[7] = pfOut[4] = pfOut[0] = DAT_01015f5c;
    return true;
}

void __cdecl NiBlendInterpolator_RegisterStreamables();
// @fnv 0x00a40a00
// src: XBOX_PDB 0x00a40a00
void __cdecl BSBlendTreadTransfInterpolator_RegisterStreamables()
{
    NiBlendInterpolator_RegisterStreamables();
}

void __cdecl NiBlendInterpolator_SaveBinary();
// @fnv 0x00a40a10
// src: XBOX_PDB 0x00a40a10
void __cdecl BSBlendTreadTransfInterpolator_SaveBinary()
{
    NiBlendInterpolator_SaveBinary();
}

void __cdecl NiBlendInterpolator_LoadBinary();

// @fnv 0x00a42fc0
// src: XBOX_PDB 0x00a42fc0
void __cdecl BSBlendTreadTransfInterpolator_LoadBinary()
{
    NiBlendInterpolator_LoadBinary();
}

void __cdecl NiBlendInterpolator_IsEqual();

// @fnv 0x00a42fd0
// src: XBOX_PDB 0x00a42fd0
void __cdecl BSBlendTreadTransfInterpolator_IsEqual()
{
    NiBlendInterpolator_IsEqual();
}

extern float DAT_0109696c;
// Parameterless quaternion member call: the quaternion address is passed in ECX.
void __fastcall FUN_00a38560(NiQuaternion* quaternion);
// @fnv 0x00a43040
bool BSBlendTreadTransfInterpolator::UpdateSingleInterpolator(float afTime, NiObjectNET* target, NiQuatTransform& arTransform)
{
    if (m_uiObjectFlags & 1)
        afTime = m_fSingleInterpolatorTime;
    if (afTime == DAT_0109696c)
    {
        arTransform.x = -3.4028234663852886e38f;
        arTransform.qy = -3.4028234663852886e38f;
        arTransform.scale = -3.4028234663852886e38f;
        return false;
    }
    if (m_pSingleInterpolator->UpdateTransform(afTime, target, arTransform))
    {
        m_fPhase += static_cast<BSTreadTransfInterpolator*>(m_pSingleInterpolator)->secondValue;
        if (m_fPhase > 1.0f)
            m_fPhase = m_fPhase - 1.0;
        else if (m_fPhase < 0.0f)
            m_fPhase = m_fPhase + 1.0;
        if (arTransform.qy != -3.4028234663852886e38)
        {
            NiQuaternion qRotation = reinterpret_cast<NiQuaternion&>(arTransform.qx);
            FUN_00a38560(&qRotation);
            CopyTreadQuaternion(reinterpret_cast<NiQuaternion&>(arTransform.qx), qRotation);
        }
        return true;
    }
    arTransform.x = -3.4028234663852886e38f;
    arTransform.qy = -3.4028234663852886e38f;
    arTransform.scale = -3.4028234663852886e38f;
    return false;
}

static volatile float BlendTimeValue = -3.402823466e+38f;
extern int DAT_0109697c;

// The shared class has no default constructor; initialize its declared fields here.
void __fastcall InitializeInterpolator(NiInterpolator* interpolator);

// @fnv 0x00a36890
// src: GAMEBRYO_LIB 0x00a36890
NiBlendInterpolator* __fastcall NiBlendInterpolator_NiBlendInterpolator(NiBlendInterpolator* interpolator)
{
    InitializeInterpolator(interpolator);
    *reinterpret_cast<void**>(interpolator) = &DAT_0109697c;
    interpolator->m_uiObjectFlags = 0;
    interpolator->m_ucArraySize = 0;
    interpolator->m_ucInterpCount = 0;
    interpolator->m_ucSingleIdx = 0xff;
    interpolator->m_cHighPriority = -128;
    interpolator->m_cNextHighPriority = -128;
    interpolator->m_pInterpArray = 0;
    interpolator->m_pSingleInterpolator = 0;
    interpolator->m_fWeightThreshold = 0.0f;
    interpolator->m_fSingleInterpolatorTime = BlendTimeValue;
    interpolator->m_fHighSumOfWeights = BlendTimeValue;
    interpolator->m_fNextHighSumOfWeights = BlendTimeValue;
    interpolator->m_fTrailingValue = BlendTimeValue;
    return interpolator;
}
