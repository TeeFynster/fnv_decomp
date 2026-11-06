// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niblendaccumtransforminterpolator.inl
//
// Covered functions (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x00496340  NiBlendAccumTransformInterpolator::ResetAccumulation  (111 bytes)
#ifndef FNV_NIBLENDACCUMTRANSFORMINTERPOLATOR_INL
#define FNV_NIBLENDACCUMTRANSFORMINTERPOLATOR_INL

#include "../../../../include/NiBlendAccumTransformInterpolator.h"
#include "../../../../include/NiBlendInterpolator.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/NiQuaternion.h"
#include "../../../../include/NiRefObject.h"
#include <string.h>

#pragma intrinsic(memcpy)

// @fnv 0x00496340
void NiBlendAccumTransformInterpolator::ResetAccumulation()
{
    if (m_ucInterpCount == 1)
    {
        // A single interpolator contributes no accumulation, so the
        // accumulated transform is left invalid.
        NiQuatTransform kTransform;
        // Preserve the original inline copy instead of calling the shared
        // out-of-line assignment operator.
        memcpy(&m_kAccumulatedTransform, &kTransform, sizeof(kTransform));
    }
    else
    {
        m_kAccumulatedTransform.GetTransformScale(const_cast<NiPoint3*>(&NiPoint3::ZERO));
        m_kAccumulatedTransform.SetLocalRotation(const_cast<NiQuaternion*>(&NiQuaternion::IDENTITY));
        m_kAccumulatedTransform.SetScale(1.0f);
    }
    m_bHasAccumulation = true;
}

#endif
