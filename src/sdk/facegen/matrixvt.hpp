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
    memcpy(FUN_006578b0(0), rhs.FUN_006578b0(0), m_uiRowCount * m_uiColumnCount * sizeof(float));
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
            result += SquareFloat(*FUN_0060b370(row, col).FUN_00629ab0());
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
            *const_cast<float*>(result.FUN_0060b370(i, j).FUN_00629ab0()) = 0.0f;

            k = 0;
            for (; k < m_uiColumnCount; ++k)
            {
                *const_cast<float*>(result.FUN_0060b370(i, j).FUN_00629ab0())
                    += *FUN_0060b370(i, k).FUN_00629ab0()
                     * *const_cast<FaceGenMatrix<float>&>(rhs).FUN_0060b370(k, j).FUN_00629ab0();
            }
        }
    }
    return result;
    }
}

#endif
