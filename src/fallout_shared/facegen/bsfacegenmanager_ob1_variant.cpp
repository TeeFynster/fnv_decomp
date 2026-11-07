
// src/fallout_shared/facegen/bsfacegenmanager_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1 (unit src/fallout_shared/facegen/bsfacegenmanager.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../../include/BSFaceGenManager.h"
#include "bsfacegenmanager_decls.h"

static __forceinline void DeadQ1()
{
    int dq[1];
}
static __forceinline void DeadQ2()
{
    int dq[2];
}
static __forceinline void DeadQ3()
{
    int dq[3];
}
static __forceinline void DeadQ4()
{
    int dq[4];
}
static __forceinline void DeadQ5()
{
    int dq[5];
}
static __forceinline void DeadQ6()
{
    int dq[6];
}
static __forceinline void DeadQ7()
{
    int dq[7];
}
static __forceinline void DeadQ8()
{
    int dq[8];
}
static __forceinline void DeadQ9()
{
    int dq[9];
}
static __forceinline void DeadQ10()
{
    int dq[10];
}
static __forceinline void DeadQ11()
{
    int dq[11];
}
void ReportAssertionViolation(const char*, int);
void FUN_00ec7c56();

struct ContainerBase
{
    void* m_ownedAux;
};
struct CoordVec;
struct CoordConstIter
{
    void* m_aux;
    float* m_ptr;
    CoordConstIter()
    {
        m_aux = 0;
    }
    CoordConstIter(float* ptr, const ContainerBase* pVec);
    void DoNothing();
    bool IsNotIdentical(const CoordConstIter& other) const;
    float* ProcessEntries_0064dda0() const;
    CoordConstIter operator++(int)
    {
        DeadQ1();
        CoordConstIter tmp = *this;
        DoNothing();
        return tmp;
    }
};
struct CoordIterBase : CoordConstIter
{
    CoordIterBase(float* ptr, const ContainerBase* pVec);
};
struct CoordIter : CoordIterBase
{
    CoordIter(float* ptr, const ContainerBase* pVec) : CoordIterBase(ptr, pVec)
    {}
    CoordIter operator++(int)
    {
        CoordIter tmp = *this;
        DoNothing();
        return tmp;
        DeadQ1();
    }
};
struct CoordVec : ContainerBase
{
    int unk04;
    int unk08;
    float* m_pHeadNode;
    float* m_last;
    float* m_kRayEnd;
    unsigned int m_rows;
    unsigned int m_cols;
    CoordIter begin()
    {
        return CoordIter(m_pHeadNode, this);
        DeadQ1();
    }
    CoordConstIter EvaluateValue_0065fd10() const;
    CoordConstIter end() const
    {
        return CoordConstIter(m_last, this);
    }
    CoordVec& ProcessEntries_00aaef90(const CoordVec& rhs);
};
inline CoordConstIter::CoordConstIter(float* ptr, const ContainerBase* pVec)
{
    m_aux = 0;
    if (!(pVec != 0 && ((const CoordVec*)pVec)->m_pHeadNode <= ptr && ptr <= ((const CoordVec*)pVec)->m_last))
        FUN_00ec7c56();
    m_aux = pVec->m_ownedAux;
    m_ptr = ptr;
}
// @fnv 0x00aaef90
// src: GUESS 0x00aaef90 (confidence: low)
CoordVec& CoordVec::ProcessEntries_00aaef90(const CoordVec& rhs)
{
    (m_rows == rhs.m_rows && m_cols == rhs.m_cols)
        ? (void)0
        : ReportAssertionViolation("d:\\_fallout3\\platforms\\common\\code\\sdk\\facegen\\matrixVT.hpp", 0x29e);
    CoordIter it2 = begin();
    CoordConstIter it1 = rhs.EvaluateValue_0065fd10();
    for (; it2.IsNotIdentical(end()) && it1.IsNotIdentical(rhs.end()); it2++, it1++)
        *it2.ProcessEntries_0064dda0() -= (*it1.ProcessEntries_0064dda0());
    return *this;
    DeadQ2();
}

#include <vector>
#include <string.h>
void __cdecl ReportAssertionViolation(const char*, int);
struct MatrixRow
{
    float* data;
    unsigned int count;
    MatrixRow(float* p, unsigned int n) : data(p), count(n)
    {}
    float& operator[](unsigned int i)
    {
        return data[i];
    }
};
inline void copyColumn(float* dst, const float* src, unsigned int count)
{
    memcpy(dst, src, count * sizeof(float));
}
struct MatrixOps
{
    std::vector<float> data;
    unsigned int columns;
    unsigned int rows;
    MatrixOps(unsigned int c, unsigned int r) : columns(c), rows(r)
    {
        data.resize(rows * columns);
    }
    MatrixOps(const MatrixOps& o)
    {
        unsigned int c = o.columns;
        unsigned int r = o.rows;
        columns = c;
        rows = r;
        unsigned int n = columns * rows;
        data.resize(n);
        unsigned int dstCount = data.size();
        unsigned int srcCount = o.data.size();
        if (dstCount && srcCount)
        {
            const float* src = &o.data[0];
            float* dst = &data[0];
            unsigned int columnBytes = r * sizeof(float);
            unsigned int byteCount = c * columnBytes;
            memcpy(dst, src, byteCount);
        }
    }
    ~MatrixOps();
    unsigned int getColumns() const
    {
        return columns;
    }
    unsigned int getRows() const
    {
        return rows;
    }
// src: GUESS 0x0060b370 (confidence: low)
    MatrixRow ForwardCall_0060b370(unsigned int i)
    {
        return MatrixRow(&data[0] + i * rows, rows);
    }
    MatrixOps ProcessEntries_00aaf110(unsigned int, unsigned int, unsigned int, unsigned int);
};
// @fnv 0x00aaf110
// src: GUESS 0x00aaf110 (confidence: low)
MatrixOps MatrixOps::ProcessEntries_00aaf110(unsigned int startColumn, unsigned int startRow, unsigned int columnCount,
                                  unsigned int rowCount)
{
    if (startRow >= 0 && startColumn >= 0)
    {
    }
    else
        ReportAssertionViolation("d:\\_fallout3\\platforms\\common\\code\\sdk\\facegen\\matrixVT.hpp", 0x425);
    if (startRow + rowCount <= rows && startColumn + columnCount <= columns)
    {
    }
    else
        ReportAssertionViolation("d:\\_fallout3\\platforms\\common\\code\\sdk\\facegen\\matrixVT.hpp", 0x427);
    MatrixOps temporary(columnCount, rowCount);
    if (columnCount > 0 && rowCount > 0)
    {
        for (unsigned int column = 0; column < temporary.getColumns(); column++)
        {
            copyColumn(&temporary.ForwardCall_0060b370(column)[0], &ForwardCall_0060b370(column + startColumn)[startRow],
                       temporary.getRows());
        }
    }
    return temporary;
}

MatrixOps::~MatrixOps()
{}
