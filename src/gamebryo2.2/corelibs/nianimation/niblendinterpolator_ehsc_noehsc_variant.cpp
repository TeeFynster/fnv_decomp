
// src/gamebryo2.2/corelibs/nianimation/niblendinterpolator_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/gamebryo2.2/corelibs/nianimation/niblendinterpolator.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "niblendinterpolator_types_NiBlendInterpolator.h"
#include "niblendinterpolator_types_NiBlendInterpolator__InterpArrayItem.h"
#include "niblendinterpolator_types_NiCloningProcess.h"

struct S_00a370b0_Class
{
    int* unk00;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char m_ucSingleIdx;
    unsigned char m_cHighPriority;
    unsigned char m_cNextHighPriority;
    unsigned char unk12;
    unsigned char unk13;
    void* m_pInterpArray;
    void* m_pSingleInterpolator;
    float m_fWeightThreshold;
    float m_fSingleInterpolatorTime;
    float m_fHighSumOfWeights;
    float m_fNextHighSumOfWeights;
    float m_fTrailingValue;

    void FUN_00a56ff0();
    S_00a370b0_Class* NiBlendInterpolator_NiBlendInterpolator_00a370b0(bool bFlags, float fWeightThreshold, unsigned char volatile ucArraySize);
};

struct S_00a370b0_Allocator
{
    void* Game_DoHeapAlloc(unsigned int nSize);
};

extern float DAT_0109696c;
extern int DAT_0109697c;
extern S_00a370b0_Allocator DAT_011f6238;

struct BlendItem
{
    void* m_spControllerInterpolator;
    float m_fWeight;
    float m_fNormalizedWeight;
    char m_cPriority;
    float m_fEaseSpinner;
    float m_fLastEvaluationTime;
    BlendItem() throw();
    ~BlendItem() throw();
    static void* operator new[](unsigned int size)
    {
        return DAT_011f6238.Game_DoHeapAlloc(size);
    }
};

// @fnv 0x00a370b0
// src: EXE 0x00a370b0
S_00a370b0_Class* __thiscall S_00a370b0_Class::NiBlendInterpolator_NiBlendInterpolator_00a370b0(bool bFlags, float fWeightThreshold,
                                                            unsigned char volatile ucArraySize)
{
    unsigned int nCount;
    unsigned int nSize;

    FUN_00a56ff0();
    unsigned char arraySize = ucArraySize;

    m_fWeightThreshold = fWeightThreshold;
    m_fSingleInterpolatorTime = DAT_0109696c;
    m_fHighSumOfWeights = DAT_0109696c;
    m_cHighPriority = (char)0x80;
    m_fNextHighSumOfWeights = DAT_0109696c;
    m_cNextHighPriority = (char)0x80;
    m_fTrailingValue = DAT_0109696c;
    unk00 = &DAT_0109697c;
    m_ucArraySize = arraySize;
    m_ucInterpCount = 0;
    m_ucSingleIdx = 0xff;
    m_pInterpArray = 0;
    m_pSingleInterpolator = 0;
    m_uiObjectFlags = bFlags ? 1 : 0;
    if (arraySize > 0)
        m_pInterpArray = new BlendItem[arraySize];
    return this;
}
