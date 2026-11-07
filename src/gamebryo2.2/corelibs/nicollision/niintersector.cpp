
// src/gamebryo2.2/corelibs/nicollision/niintersector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/niintersector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/MemoryManager.h"

struct VTableObject
{
    virtual void __fastcall Query(int value);
    virtual void __fastcall AddRef(int value);
    virtual void __fastcall Release(int value);
};
// @fnv 0x00eae6e0
// src: GAMEBRYO_SRC 0x00eae6e0
void __fastcall NiIntersector_Test(VTableObject* object, int value)
{
    object->Release(value);
}

static const float g_fltDefault = 3.402823466e+38f;

struct SpawnedBase
{
    virtual void v00()
    {}
    virtual void v04()
    {}
    virtual void v08()
    {}
};

class FUN_00eae720 : public SpawnedBase
{
  public:
    float m_fCoefficientA;
    float m_fB;
    float m_fInvB;
    float m_fC;
    int m_iD;
    int m_i18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
    float m_f30;
    float m_f34;

    FUN_00eae720(float a, float b, float c, int d);
};

// Initializes the object's fields: stores d and a, b, c, computes 1/b, and sets several float fields to g_fltDefault.
// @fnv 0x00eae720
FUN_00eae720::FUN_00eae720(float a, float b, float c, int d)
{
    float fDefault = g_fltDefault;
    *(volatile float*)&m_f20 = fDefault;
    m_f24 = fDefault;
    m_f28 = fDefault;
    m_f2C = fDefault;
    m_f30 = fDefault;
    m_f34 = fDefault;
    *(volatile int*)&m_iD = d;
    *(volatile int*)&m_i18 = 0;
    m_fCoefficientA = a;
    m_fB = b;
    m_fInvB = 1.0f / b;
    m_fC = c;
    m_f1C = fDefault;
}

struct FnvCpu_FUN_00eae6f0_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    float value;
    float NiIntersector_GetContactTime();
};
// @fnv 0x00eae6f0
// src: COMMUNITY 0x00eae6f0
float FnvCpu_FUN_00eae6f0_CpuObject::NiIntersector_GetContactTime()
{
    return value;
}

struct FnvCpu_FUN_00eae700_CpuObject
{
    char* NiIntersector_GetContactPoint();
};
// @fnv 0x00eae700
// src: COMMUNITY 0x00eae700
char* FnvCpu_FUN_00eae700_CpuObject::NiIntersector_GetContactPoint()
{
    return reinterpret_cast<char*>(this) + 32;
}

struct FnvCpu_FUN_00eae710_CpuObject
{
    char* NiIntersector_GetContactNormal();
};
// @fnv 0x00eae710
// src: COMMUNITY 0x00eae710
char* FnvCpu_FUN_00eae710_CpuObject::NiIntersector_GetContactNormal()
{
    return reinterpret_cast<char*>(this) + 44;
}

extern MemoryManager g_memoryManager;
struct FUN_00eae770
{
    virtual ~FUN_00eae770();
    void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
// @fnv 0x00eae770
FUN_00eae770::~FUN_00eae770()
{}

#include <float.h>
struct S_00eae7a0_Point
{
    float x, y, z;
    bool operator==(const S_00eae7a0_Point& o) const;
};

static const float DAT_01011d78 = 0.0f;
static const float DAT_010f1a7c = FLT_MAX;

struct S_00eae7a0_Solver
{
    float m_fMaxX;     // 04
    float m_fStep;     // 08
    float m_fInvStep;  // 0C
    float m_fMinX;     // 10
    int m_iMaxIter;    // 14
    int m_iResult;     // 18
    float m_fResult;   // 1C

    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual float Evaluate(const S_00eae7a0_Point& a, const S_00eae7a0_Point& b, float x);
    virtual void Finish(const S_00eae7a0_Point& a, const S_00eae7a0_Point& b);

    void Solve(const S_00eae7a0_Point& a, const S_00eae7a0_Point& b);
};

// Uses finite-difference slope estimates to update x, then stores a result and status in m_fResult and m_iResult.
// @fnv 0x00eae7a0
void S_00eae7a0_Solver::Solve(const S_00eae7a0_Point& apPointA, const S_00eae7a0_Point& apPointB)
{
    float x = 0.0f;
    float fValue = Evaluate(apPointA, apPointB, x);
    if (fValue <= -m_fMinX)
    {
        m_fResult = x;
        m_iResult = 3;
        Finish(apPointA, apPointB);
        return;
    }
    if (fValue <= FLT_EPSILON)
    {
        m_fResult = x;
        m_iResult = 2;
        Finish(apPointA, apPointB);
        return;
    }
    if (apPointA == apPointB)
    {
        m_fResult = DAT_010f1a7c;
        m_iResult = 1;
        return;
    }
    float fPrevValue = Evaluate(apPointA, apPointB, x - m_fStep);
    float slope = (fValue - fPrevValue) * m_fInvStep;
    if (slope >= 0.0f)
    {
        m_fResult = DAT_010f1a7c;
        m_iResult = 1;
        return;
    }
    float fMaxValue = Evaluate(apPointA, apPointB, m_fMaxX);
    if (fMaxValue > 0.0f)
    {
        fPrevValue = Evaluate(apPointA, apPointB, m_fMaxX - m_fStep);
        float maxSlope = (fMaxValue - fPrevValue) * m_fInvStep;
        if (maxSlope < DAT_01011d78)
        {
            m_fResult = DAT_010f1a7c;
            m_iResult = 1;
            return;
        }
    }
    for (int iIter = 1; iIter <= m_iMaxIter; iIter++)
    {
        x = x - fValue / slope;
        if (x > m_fMaxX)
        {
            m_fResult = DAT_010f1a7c;
            m_iResult = 1;
            return;
        }
        fValue = Evaluate(apPointA, apPointB, x);
        if (fValue <= m_fMinX)
        {
            m_fResult = x;
            m_iResult = 2;
            Finish(apPointA, apPointB);
            return;
        }
        fPrevValue = Evaluate(apPointA, apPointB, x - m_fStep);
        slope = (fValue - fPrevValue) * m_fInvStep;
        if (slope >= 0.0f)
        {
            m_fResult = DAT_010f1a7c;
            m_iResult = 1;
            return;
        }
    }
    m_fResult = x;
    m_iResult = 2;
    Finish(apPointA, apPointB);
}
