#ifndef ARMY_LUNA_2061_MATRIXVT_HPP
#define ARMY_LUNA_2061_MATRIXVT_HPP


#include "matrixvt_decls.h"
#include <string.h>

FNV_STATIC_ASSERT(sizeof(FR2MatrixVTCData) == 24);
FNV_STATIC_ASSERT(sizeof(FaceGenMatrix<float>) == 32);
FNV_STATIC_ASSERT(offsetof(FaceGenMatrix<float>, m_uiRowCount) == 24);
FNV_STATIC_ASSERT(offsetof(FaceGenMatrix<float>, m_uiColumnCount) == 28);

// @fnv 0x006581e0
template <> FaceGenMatrix<float>& FaceGenMatrix<float>::operator=(const FaceGenMatrix<float>& rhs)
{
    if (this == &rhs)
        return *this;

    m_uiRowCount = rhs.m_uiRowCount;
    m_uiColumnCount = rhs.m_uiColumnCount;
    reinterpret_cast<FR2MatrixVTCData*>(this)->SetElementCount(m_uiRowCount * m_uiColumnCount);
    memcpy(GetElementPointerChecked(0), rhs.GetElementPointerChecked(0), m_uiRowCount * m_uiColumnCount * sizeof(float));
    return *this;
}

// @fnv 0x006588a0
template <> float FaceGenMatrix<float>::GetTrace()
{
    float result = 0.0f;
    unsigned int row = 0;
    for (; row < m_uiRowCount; ++row)
    {
        unsigned int col = 0;
        for (; col < m_uiColumnCount; ++col)
        {
            result += SquareFloat(*ForwardCall_0060b370(row, col).NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt());
        }
    }
    return result;
}

// @fnv 0x00658360
template <> FaceGenMatrix<float> FaceGenMatrix<float>::operator*(const FaceGenMatrix<float>& rhs)
{
    unsigned int k;
    {
    unsigned int i;
    if (m_uiColumnCount == rhs.m_uiRowCount)
    {
    }
    else
    {
        ReportAssertionViolation("d:\\_fallout3\\platforms\\common\\code\\sdk\\facegen\\matrixVT.hpp", 0x113);
    }

    FaceGenMatrix<float> result(m_uiRowCount, rhs.m_uiColumnCount);
    i = 0;
    for (; i < m_uiRowCount; ++i)
    {
        unsigned int j = 0;
        for (; j < rhs.m_uiColumnCount; ++j)
        {
            *const_cast<float*>(result.ForwardCall_0060b370(i, j).NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt()) = 0.0f;

            k = 0;
            for (; k < m_uiColumnCount; ++k)
            {
                *const_cast<float*>(result.ForwardCall_0060b370(i, j).NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt())
                    += *ForwardCall_0060b370(i, k).NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt()
                     * *const_cast<FaceGenMatrix<float>&>(rhs).ForwardCall_0060b370(k, j).NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt();
            }
        }
    }
    return result;
    }
}

#endif
