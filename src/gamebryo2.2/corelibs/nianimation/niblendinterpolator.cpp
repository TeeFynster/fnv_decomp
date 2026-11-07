// gamebryo2.2/corelibs/nianimation/niblendinterpolator.cpp: NiBlendInterpolator, InterpItem, LoadInterpItem, BlendSerializer and more (19 functions)

#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiStream.h"

#include "niblendinterpolator_types_NiBlendInterpolator.h"
#include "niblendinterpolator_types_NiBlendInterpolator__InterpArrayItem.h"
#include "niblendinterpolator_types_NiCloningProcess.h"

// Stream accessors stay inline here to preserve the original field reads.
inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x250);
}

inline NiBinaryStream& NiStream::Istr()
{
    return **reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}

inline unsigned int NiStream::GetFileVersion() const
{
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0xd8);
}

// @fnv 0x00a371f0
NiBlendInterpolator__InterpArrayItem& NiBlendInterpolator__InterpArrayItem::operator=(
    const NiBlendInterpolator__InterpArrayItem& source)
{
    NiInterpolator* previous = m_spControllerInterpolator.m_pObject;
    if (previous != source.m_spControllerInterpolator.m_pObject)
    {
        if (previous && InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->m_uiRefCount)) == 0)
            previous->DeleteThis();
        m_spControllerInterpolator.m_pObject = source.m_spControllerInterpolator.m_pObject;
        if (m_spControllerInterpolator.m_pObject)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&m_spControllerInterpolator.m_pObject->m_uiRefCount));
    }
    m_fWeight = source.m_fWeight;
    m_fNormalizedWeight = source.m_fNormalizedWeight;
    m_cPriority = source.m_cPriority;
    m_fEaseSpinner = source.m_fEaseSpinner;
    m_fLastEvaluationTime = source.m_fLastEvaluationTime;
    return *this;
}

// Finds the first two active interpolator items and normalizes their weights by priority, ease spinner, threshold and flags.
// @fnv 0x00a36bd0
void NiBlendInterpolator::UpdatePriorityData()
{
    NiBlendInterpolator__InterpArrayItem* pFirstItem = 0;
    NiBlendInterpolator__InterpArrayItem* pSecondItem = 0;
    for (unsigned char index = 0; index < m_ucArraySize; ++index)
    {
        if (m_pInterpArray[index].m_spControllerInterpolator.m_pObject)
        {
            if (!pFirstItem)
                pFirstItem = &m_pInterpArray[index];
            else
            {
                pSecondItem = &m_pInterpArray[index];
                break;
            }
        }
    }

    float firstWeight = pFirstItem->m_fWeight * pFirstItem->m_fEaseSpinner;
    float secondWeight = pSecondItem->m_fWeight * pSecondItem->m_fEaseSpinner;
    if (firstWeight == 0.0f && secondWeight == 0.0f)
    {
        pFirstItem->m_fNormalizedWeight = 0.0f;
        pSecondItem->m_fNormalizedWeight = 0.0f;
        return;
    }
    if (pFirstItem->m_cPriority > pSecondItem->m_cPriority)
    {
        if (pFirstItem->m_fEaseSpinner == 1.0f)
        {
            pFirstItem->m_fNormalizedWeight = 1.0f;
            pSecondItem->m_fNormalizedWeight = 0.0f;
            return;
        }
        float remainingEase = 1.0f - pFirstItem->m_fEaseSpinner;
        float inverseWeight = 1.0f / (pFirstItem->m_fEaseSpinner * firstWeight + remainingEase * secondWeight);
        pFirstItem->m_fNormalizedWeight = pFirstItem->m_fEaseSpinner * firstWeight * inverseWeight;
        pSecondItem->m_fNormalizedWeight = remainingEase * secondWeight * inverseWeight;
    }
    else if (pFirstItem->m_cPriority < pSecondItem->m_cPriority)
    {
        if (pSecondItem->m_fEaseSpinner == 1.0f)
        {
            pFirstItem->m_fNormalizedWeight = 0.0f;
            pSecondItem->m_fNormalizedWeight = 1.0f;
            return;
        }
        float remainingEase = 1.0f - pSecondItem->m_fEaseSpinner;
        float inverseWeight = 1.0f / (remainingEase * firstWeight + pSecondItem->m_fEaseSpinner * secondWeight);
        pFirstItem->m_fNormalizedWeight = remainingEase * firstWeight * inverseWeight;
        pSecondItem->m_fNormalizedWeight = pSecondItem->m_fEaseSpinner * secondWeight * inverseWeight;
    }
    else
    {
        float inverseWeight = 1.0f / (firstWeight + secondWeight);
        pFirstItem->m_fNormalizedWeight = firstWeight * inverseWeight;
        pSecondItem->m_fNormalizedWeight = secondWeight * inverseWeight;
    }

    if (m_uiObjectFlags & 2)
    {
        if (pFirstItem->m_fNormalizedWeight >= pSecondItem->m_fNormalizedWeight)
        {
            pFirstItem->m_fNormalizedWeight = 1.0f;
            pSecondItem->m_fNormalizedWeight = 0.0f;
        }
        else
        {
            pFirstItem->m_fNormalizedWeight = 0.0f;
            pSecondItem->m_fNormalizedWeight = 1.0f;
        }
    }
    else if (m_fWeightThreshold > 0.0f)
    {
        bool anyWeightRemoved = false;
        if (pFirstItem->m_fNormalizedWeight < m_fWeightThreshold)
        {
            pFirstItem->m_fNormalizedWeight = 0.0f;
            anyWeightRemoved = true;
        }
        if (pSecondItem->m_fNormalizedWeight < m_fWeightThreshold)
        {
            pSecondItem->m_fNormalizedWeight = 0.0f;
            anyWeightRemoved = true;
        }
        if (anyWeightRemoved)
            pSecondItem->m_fNormalizedWeight = 1.0f;
    }
}

// @fnv 0x00a36970
unsigned char NiBlendInterpolator::AddInterpolatorItem(NiInterpolator* interpolator, float weight, char priority,
                                                       float easeSpinner)
{
    unsigned char index = 0;
    for (; index < m_ucArraySize; ++index)
        if (!m_pInterpArray[index].m_spControllerInterpolator.m_pObject)
            break;
    if (index == m_ucArraySize && !GrowInterpolatorArray())
        return 0xff;

    NiBlendInterpolator__InterpArrayItem& item = m_pInterpArray[index];
    NiInterpolator* previous = item.m_spControllerInterpolator.m_pObject;
    if (previous != interpolator)
    {
        if (previous && InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->m_uiRefCount)) == 0)
            previous->DeleteThis();
        item.m_spControllerInterpolator.m_pObject = interpolator;
        if (interpolator)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&interpolator->m_uiRefCount));
    }
    item.m_fWeight = weight;
    item.m_cPriority = priority;
    item.m_fNormalizedWeight = 0.0f;
    item.m_fEaseSpinner = easeSpinner;
    item.m_fLastEvaluationTime = INVALID_TIME;

    if (priority > m_cNextHighPriority)
    {
        if (priority > m_cHighPriority)
        {
            m_cNextHighPriority = m_cHighPriority;
            m_cHighPriority = priority;
        }
        else if (priority != m_cHighPriority)
            m_cNextHighPriority = priority;
    }
    ++m_ucInterpCount;
    if (m_ucInterpCount == 1)
    {
        m_ucSingleIdx = index;
        m_pSingleInterpolator = interpolator;
    }
    else
    {
        m_fSingleInterpolatorTime = INVALID_TIME;
        m_ucSingleIdx = 0xff;
        m_pSingleInterpolator = 0;
    }
    m_fHighSumOfWeights = INVALID_TIME;
    m_uiObjectFlags |= 4;
    m_fNextHighSumOfWeights = INVALID_TIME;
    m_fTrailingValue = INVALID_TIME;
    return index;
}

// Removes the interpolator at index, releases it, recomputes high/next-high priorities and single-interpolator state, and invalidates cached weights.
// @fnv 0x00a36a90
void NiBlendInterpolator::RemoveInterpolatorAt(unsigned char index)
{
    NiBlendInterpolator__InterpArrayItem& item = m_pInterpArray[index];
    char priority = item.m_cPriority;
    NiInterpolator* previous = item.m_spControllerInterpolator.m_pObject;
    if (previous)
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->m_uiRefCount)) == 0)
            previous->DeleteThis();
        item.m_spControllerInterpolator.m_pObject = 0;
    }
    if (priority == m_cHighPriority || priority == m_cNextHighPriority)
    {
        m_cNextHighPriority = -128;
        m_cHighPriority = -128;
        for (unsigned char current = 0; current < m_ucArraySize; ++current)
        {
            NiBlendInterpolator__InterpArrayItem& candidate = m_pInterpArray[current];
            if (candidate.m_spControllerInterpolator.m_pObject && candidate.m_cPriority > m_cNextHighPriority)
            {
                if (candidate.m_cPriority > m_cHighPriority)
                {
                    m_cNextHighPriority = m_cHighPriority;
                    m_cHighPriority = candidate.m_cPriority;
                }
                else if (candidate.m_cPriority < m_cHighPriority)
                    m_cNextHighPriority = candidate.m_cPriority;
            }
        }
    }
    --m_ucInterpCount;
    if (m_ucInterpCount == 1)
    {
        if (m_ucArraySize == 2)
            m_ucSingleIdx = !index;
        else
        {
            for (unsigned char current = 0; current < m_ucArraySize; ++current)
                if (m_pInterpArray[current].m_spControllerInterpolator.m_pObject)
                {
                    m_ucSingleIdx = current;
                    break;
                }
        }
        NiBlendInterpolator__InterpArrayItem& single = m_pInterpArray[m_ucSingleIdx];
        m_pSingleInterpolator = single.m_spControllerInterpolator.m_pObject;
        m_fSingleInterpolatorTime = single.m_fLastEvaluationTime;
    }
    else if (m_ucInterpCount == 0)
    {
        m_fSingleInterpolatorTime = INVALID_TIME;
        m_cNextHighPriority = -128;
        m_cHighPriority = -128;
        m_ucSingleIdx = 0xff;
        m_pSingleInterpolator = 0;
    }
    m_fHighSumOfWeights = INVALID_TIME;
    m_uiObjectFlags |= 4;
    m_fNextHighSumOfWeights = INVALID_TIME;
    m_fTrailingValue = INVALID_TIME;
}

// @fnv 0x00a36e80
void NiBlendInterpolator::ProcessClone(CloningProcess& aCloneProcess)
{
    NiObject::ProcessClone(aCloneProcess);
    NiObject* cloneObject = 0;
    aCloneProcess.m_pCloneMap->GetAt(this, cloneObject);
    NiBlendInterpolator* clone = static_cast<NiBlendInterpolator*>(cloneObject);
    for (unsigned char index = 0; index < m_ucArraySize; ++index)
    {
        NiInterpolator* interpolator = m_pInterpArray[index].m_spControllerInterpolator.m_pObject;
        if (interpolator)
            interpolator->ProcessClone(aCloneProcess);
    }
    if (m_pSingleInterpolator)
    {
        NiInterpolator* singleClone;
        if (aCloneProcess.m_pCloneMap->GetAt(m_pSingleInterpolator, cloneObject))
            singleClone = static_cast<NiInterpolator*>(cloneObject);
        else
            singleClone = m_pSingleInterpolator;
        clone->m_pSingleInterpolator = singleClone;
    }
}

extern int DAT_0109697c;

extern MemoryManager g_memoryManager;

void __fastcall FUN_00a57010(void* pThis);

struct InterpArrayItem_Temp
{
    NiPointer<NiObject> m_spControllerInterpolator;
    float f1;
    float f2;
    char c1;
    float f3;
    float f4;
};

// Sets the vtable pointer, destroys each element of the array at offset 0x14, frees it, then calls FUN_00a57010.
// @fnv 0x00a37170
void __fastcall DestroyInterpolatorArray(NiBlendInterpolator* pThis, int)
{
    *reinterpret_cast<int**>(pThis) = &DAT_0109697c;
    InterpArrayItem_Temp* pArray = *reinterpret_cast<InterpArrayItem_Temp**>(reinterpret_cast<char*>(pThis) + 0x14);
    if (pArray)
    {
        int* pAlloc = reinterpret_cast<int*>(pArray) - 1;
        int count = *pAlloc;
        InterpArrayItem_Temp* pCur = pArray + count;
        while (--count >= 0)
        {
            --pCur;
            pCur->~InterpArrayItem_Temp();
        }
        g_memoryManager.Deallocate(pAlloc);
    }
    FUN_00a57010(pThis);
}

struct FUN_00a37260_shell : public NiBlendInterpolator
{
    void UpdateNormalizedWeights();
};

extern double _DAT_010241b0;

struct InterpArrayItem_Layout
{
    void* m_spControllerInterpolator;  // +0x0
    float m_fWeight;                   // +0x4
    float m_fNormalizedWeight;         // +0x8
    char m_cPriority;                  // +0xC
    char padD[3];
    float m_fEaseSpinner;         // +0x10
    float m_fLastEvaluationTime;  // +0x14
};

struct NiBlendInterpolator_Layout
{
    char pad0[0xC];
    unsigned char m_uiObjectFlags;         // +0xC
    unsigned char m_ucArraySize;    // +0xD
    unsigned char m_ucInterpCount;  // +0xE
    unsigned char m_ucSingleIdx;    // +0xF
    char m_cHighPriority;           // +0x10
    char m_cNextHighPriority;       // +0x11
    char pad12[2];
    InterpArrayItem_Layout* m_pInterpArray;  // +0x14
    NiInterpolator* m_pSingleInterpolator;   // +0x18
    float m_fWeightThreshold;                // +0x1C
    float m_fSingleInterpolatorTime;         // +0x20
    float m_fHighSumOfWeights;               // +0x24
    float m_fNextHighSumOfWeights;           // +0x28
    float m_fTrailingValue;                  // +0x2C
};

// Recomputes per-item normalized blend weights from weights, ease spinners and priorities, applying the weight threshold and optional single-winner selection.
// @fnv 0x00a37260
void FUN_00a37260_shell::UpdateNormalizedWeights()
{
    NiBlendInterpolator_Layout* pThis = reinterpret_cast<NiBlendInterpolator_Layout*>(this);

    if ((pThis->m_uiObjectFlags & 4) == 0)
    {
        return;
    }

    pThis->m_uiObjectFlags &= ~4;

    if (pThis->m_ucInterpCount == 1)
    {
        pThis->m_pInterpArray[pThis->m_ucSingleIdx].m_fNormalizedWeight = 1.0f;
        return;
    }
    else if (pThis->m_ucInterpCount == 2)
    {
        UpdatePriorityData();
        return;
    }

    unsigned char uc;

    if (pThis->m_fHighSumOfWeights == _DAT_010241b0)
    {
        pThis->m_fHighSumOfWeights = 0.0f;
        pThis->m_fNextHighSumOfWeights = 0.0f;
        pThis->m_fTrailingValue = 0.0f;
        for (uc = 0; uc < pThis->m_ucArraySize; uc++)
        {
            InterpArrayItem_Layout& kItem = pThis->m_pInterpArray[uc];
            if (kItem.m_spControllerInterpolator != 0)
            {
                float fRealWeight = kItem.m_fWeight * kItem.m_fEaseSpinner;
                if (kItem.m_cPriority == pThis->m_cHighPriority)
                {
                    pThis->m_fHighSumOfWeights += fRealWeight;
                    if (kItem.m_fEaseSpinner > pThis->m_fTrailingValue)
                    {
                        pThis->m_fTrailingValue = kItem.m_fEaseSpinner;
                    }
                }
                else if (kItem.m_cPriority == pThis->m_cNextHighPriority)
                {
                    pThis->m_fNextHighSumOfWeights += fRealWeight;
                }
            }
        }
    }

    float fOneMinusHighEaseSpinner = 1.0f - pThis->m_fTrailingValue;
    float fTotalSumOfWeights = pThis->m_fTrailingValue * pThis->m_fHighSumOfWeights +
                               fOneMinusHighEaseSpinner * pThis->m_fNextHighSumOfWeights;
    float fOneOverTotalSumOfWeights = (fTotalSumOfWeights > 0.0f) ? (1.0f / fTotalSumOfWeights) : 0.0f;

    for (uc = 0; uc < pThis->m_ucArraySize; uc++)
    {
        InterpArrayItem_Layout& kItem = pThis->m_pInterpArray[uc];
        if (kItem.m_spControllerInterpolator != 0)
        {
            if (kItem.m_cPriority == pThis->m_cHighPriority)
            {
                kItem.m_fNormalizedWeight =
                    pThis->m_fTrailingValue * kItem.m_fWeight * kItem.m_fEaseSpinner * fOneOverTotalSumOfWeights;
            }
            else if (kItem.m_cPriority == pThis->m_cNextHighPriority)
            {
                kItem.m_fNormalizedWeight =
                    fOneMinusHighEaseSpinner * kItem.m_fWeight * kItem.m_fEaseSpinner * fOneOverTotalSumOfWeights;
            }
            else
            {
                kItem.m_fNormalizedWeight = 0.0f;
            }
        }
    }

    if (pThis->m_fWeightThreshold > 0.0f)
    {
        float fSumOfNormalizedWeights = 0.0f;
        for (uc = 0; uc < pThis->m_ucArraySize; uc++)
        {
            InterpArrayItem_Layout& kItem = pThis->m_pInterpArray[uc];
            if (kItem.m_spControllerInterpolator != 0 && kItem.m_fNormalizedWeight != 0.0f)
            {
                if (kItem.m_fNormalizedWeight < pThis->m_fWeightThreshold)
                {
                    kItem.m_fNormalizedWeight = 0.0f;
                }
                fSumOfNormalizedWeights += kItem.m_fNormalizedWeight;
            }
        }

        if (fSumOfNormalizedWeights != 1.0f)
        {
            float fOneOverSumOfNormalizedWeights =
                (fSumOfNormalizedWeights > 0.0f) ? (1.0f / fSumOfNormalizedWeights) : 0.0f;

            for (uc = 0; uc < pThis->m_ucArraySize; uc++)
            {
                InterpArrayItem_Layout& kItem = pThis->m_pInterpArray[uc];
                if (kItem.m_fNormalizedWeight != 0.0f)
                {
                    kItem.m_fNormalizedWeight = kItem.m_fNormalizedWeight * fOneOverSumOfNormalizedWeights;
                }
            }
        }
    }

    if ((pThis->m_uiObjectFlags & 2) != 0)
    {
        unsigned char ucHighIndex = 0xFF;
        float fHighest = -1.0f;
        for (uc = 0; uc < pThis->m_ucArraySize; uc++)
        {
            if (pThis->m_pInterpArray[uc].m_fNormalizedWeight > fHighest)
            {
                ucHighIndex = uc;
                fHighest = pThis->m_pInterpArray[uc].m_fNormalizedWeight;
            }
            pThis->m_pInterpArray[uc].m_fNormalizedWeight = 0.0f;
        }

        pThis->m_pInterpArray[ucHighIndex].m_fNormalizedWeight = 1.0f;
    }
}

extern const char* const g_011f371c_arg1;
// @fnv 0x00a36960
// src: COMMUNITY 0x00a36960
const char* const* __cdecl NiBlendInterpolator_GetRTTI()
{
    return &g_011f371c_arg1;
}

struct InterpS
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual bool RegisterStreamables(NiStream& s);
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void Collapse2();
};
struct ItemS
{
    InterpS* m_spControllerInterpolator;
    int a[5];
};
struct BlendInterpS : InterpS
{
    unsigned char pad4[8];
    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char pad0f[5];
    ItemS* m_pInterpArray;
    InterpS* m_pSingleInterpolator;
};
// @fnv 0x00a36dc0
void __fastcall CollapseAllInterps(BlendInterpS* self, int)
{
    if (self->m_ucInterpCount == 1)
    {
        self->m_pSingleInterpolator->Collapse2();
        return;
    }
    for (unsigned char uc = 0; uc < self->m_ucArraySize; uc++)
    {
        ItemS* kItem = &self->m_pInterpArray[uc];
        if (kItem->m_spControllerInterpolator)
            kItem->m_spControllerInterpolator->Collapse2();
    }
}

namespace fnv_00a36e10 {
struct InterpS
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual bool IsEqual(InterpS* o);
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void SetActiveTimeRange(float a, float b);
};
struct ItemS
{
    InterpS* m_spControllerInterpolator;
    float f4;
    float f8;
    unsigned char c;
    float f10;
    int tail;
    bool IsEqual(ItemS& kDest);
};
struct BlendInterpS : InterpS
{
    unsigned char pad4[8];
    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char pad0f[5];
    ItemS* m_pInterpArray;
    InterpS* m_pSingleInterpolator;
};
// @fnv 0x00a36e10
// src: XBOX_PDB 0x00a36e10
void __fastcall NiBlendInterpolator_GuaranteeTimeRange(BlendInterpS* self, int, float m_fStartTime, float m_fMaximumDistance)
{
    if (self->m_ucInterpCount == 1)
    {
        self->m_pSingleInterpolator->SetActiveTimeRange(m_fStartTime, m_fMaximumDistance);
        return;
    }
    for (unsigned char uc = 0; uc < self->m_ucArraySize; uc++)
    {
        ItemS* kItem = &self->m_pInterpArray[uc];
        if (kItem->m_spControllerInterpolator)
            kItem->m_spControllerInterpolator->SetActiveTimeRange(m_fStartTime, m_fMaximumDistance);
    }
}
}  // namespace fnv_00a36e10

namespace fnv_00a36f80 {
struct InterpS
{
    virtual void v0();
    bool BSTextureSet_RegisterStreamables(NiStream& s);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual bool RegisterStreamables(NiStream& s);
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void Collapse2();
};
struct ItemS
{
    InterpS* m_spControllerInterpolator;
    int a[5];
};
struct BlendInterpS : InterpS
{
    unsigned char pad4[8];
    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char pad0f[5];
    ItemS* m_pInterpArray;
    InterpS* m_pSingleInterpolator;
};
// Registers the base streamables, then registers each item's interpolator when the flag bit is clear; returns false if the base call fails.
// @fnv 0x00a36f80
// src: XBOX_PDB 0x00a36f80
bool __fastcall NiBlendInterpolator_RegisterStreamables(BlendInterpS* self, int, NiStream& kStream)
{
    if (!self->BSTextureSet_RegisterStreamables(kStream))
        return false;
    if (!(self->m_uiObjectFlags & 1))
    {
        for (unsigned char uc = 0; uc < self->m_ucArraySize; uc++)
        {
            ItemS* kItem = &self->m_pInterpArray[uc];
            if (kItem->m_spControllerInterpolator)
                kItem->m_spControllerInterpolator->RegisterStreamables(kStream);
        }
    }
    return true;
}
}  // namespace fnv_00a36f80

namespace fnv_00a36fd0 {
struct ObjS;
struct InterpS
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual bool IsEqual(ObjS* o);
};
struct ItemS
{
    InterpS* m_spControllerInterpolator;
    float f4;
    float f8;
    unsigned char c;
    float f10;
    int tail;
    bool Equals(ItemS& o);
};
struct BlendS
{
    void* vptr;
    unsigned char pad4[8];
    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char m_ucSingleIdx;
    char m_cHighPriority;
    char m_cNextHighPriority;
    unsigned char pad12[2];
    ItemS* m_pInterpArray;
    InterpS* m_pSingleInterpolator;
    float m_fWeightThreshold;
    float m_fSingleInterpolatorTime;
    bool BSAnimNotes_IsEqual(ObjS* o);
};
// @fnv 0x00a36fd0
// src: XBOX_PDB 0x00a36fd0
bool __fastcall NiBlendInterpolator_IsEqual(BlendS* self, int, ObjS* pkObject)
{
    if (!self->BSAnimNotes_IsEqual(pkObject))
        return false;
    BlendS* pkDest = (BlendS*)pkObject;
    if (self->m_ucArraySize != pkDest->m_ucArraySize)
        return false;
    for (unsigned char us = 0; us < self->m_ucArraySize; us++)
    {
        if (!self->m_pInterpArray[us].Equals(pkDest->m_pInterpArray[us]))
            return false;
    }
    if (self->m_uiObjectFlags != pkDest->m_uiObjectFlags)
        return false;
    if (self->m_fWeightThreshold != pkDest->m_fWeightThreshold)
        return false;
    if (self->m_ucInterpCount != pkDest->m_ucInterpCount)
        return false;
    if (self->m_ucSingleIdx != pkDest->m_ucSingleIdx)
        return false;
    if (self->m_pSingleInterpolator && !self->m_pSingleInterpolator->IsEqual((ObjS*)pkDest->m_pSingleInterpolator))
        return false;
    if (self->m_pSingleInterpolator != pkDest->m_pSingleInterpolator)
        return false;
    if (self->m_fSingleInterpolatorTime != pkDest->m_fSingleInterpolatorTime)
        return false;
    if (self->m_cHighPriority != pkDest->m_cHighPriority || self->m_cNextHighPriority != pkDest->m_cNextHighPriority)
        return false;
    return true;
}
}  // namespace fnv_00a36fd0

struct FUN_00a370a0_obj
{
    int field0;
};
// @fnv 0x00a370a0
// src: GUESS 0x00a370a0 (confidence: low)
FUN_00a370a0_obj* __fastcall Object_InitializeFields_00a370a0(FUN_00a370a0_obj* self, int)
{
    self->field0 = 0;
    return self;
}

class FUN_00a36f10_cls;

class EqPeer
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual bool v23(EqPeer* other);
};

class FUN_00a36f10_cls
{
  public:
    EqPeer* m_pPeer;
    float m_fCoefficientA;
    float m_fB;
    unsigned char m_ucC;
    float m_fD;
    bool Equals(FUN_00a36f10_cls* other);
};

// Compares peer pointers (both null or equal via v23) and the four value fields against another instance, returning true only if all match.
// @fnv 0x00a36f10
bool FUN_00a36f10_cls::Equals(FUN_00a36f10_cls* other)
{
    if (m_pPeer != 0 && other->m_pPeer == 0)
        return false;
    if (m_pPeer == 0 && other->m_pPeer != 0)
        return false;
    if (m_pPeer != 0 && !m_pPeer->v23(other->m_pPeer))
        return false;
    if (m_fCoefficientA != other->m_fCoefficientA)
        return false;
    if (m_fB != other->m_fB)
        return false;
    if (m_ucC != other->m_ucC)
        return false;
    if (m_fD != other->m_fD)
        return false;
    return true;
}

struct ObjectWriter;
typedef unsigned int(__cdecl* WriteItemFn)(ObjectWriter*, const void*, unsigned int, unsigned int*, unsigned int);
struct ObjectWriter
{
    void* interfacePtr;
    unsigned int totalBytes;
    void* auxPtr;
    WriteItemFn write;
};
struct InterpItem
{
    void* interpolator;
    float weight;
    float normalizedWeight;
    char priority;
    char unk0d, unk0e, unk0f;
    float easeSpinner;
    float updateTime;
    void WriteToStream(NiStream* stream);
};
// Writes the interpolator, weight, normalizedWeight, priority and easeSpinner to the stream via its writer, accumulating byte counts.
// @fnv 0x00a378d0
void InterpItem::WriteToStream(NiStream* stream)
{
    stream->SaveLinkID(reinterpret_cast<const NiObject*>(interpolator));
    ObjectWriter* writer = *reinterpret_cast<ObjectWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    {
        unsigned int bytes = 4;
        writer->totalBytes += writer->write(writer, &weight, 4, &bytes, 1);
    }
    writer = *reinterpret_cast<ObjectWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    {
        unsigned int bytes = 4;
        writer->totalBytes += writer->write(writer, &normalizedWeight, 4, &bytes, 1);
    }
    writer = *reinterpret_cast<ObjectWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    {
        unsigned int bytes = 1;
        writer->totalBytes += writer->write(writer, &priority, 1, &bytes, 1);
    }
    writer = *reinterpret_cast<ObjectWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    {
        unsigned int bytes = 4;
        writer->totalBytes += writer->write(writer, &easeSpinner, 4, &bytes, 1);
    }
}

struct LoadBinStream;
typedef unsigned int(__cdecl* LoadBinReadFn)(LoadBinStream*, void*, unsigned int, unsigned int*, unsigned int);
struct LoadBinStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    LoadBinReadFn m_pfnRead;
    unsigned int BinaryRead(void* buf, unsigned int total, unsigned int* sizes, unsigned int count)
    {
        unsigned int read = m_pfnRead(this, buf, total, sizes, count);
        m_uiStreamFlags += read;
        return read;
    }
};


template <class T> inline void LoadStreamBinary(LoadBinStream* s, T& val)
{
    unsigned int size = sizeof(T);
    s->BinaryRead(&val, size, &size, 1);
}

struct LoadInterpItem
{
    NiInterpolator* m_spControllerInterpolator;
    float m_fWeight;
    float m_fNormalizedWeight;
    char m_cPriority;
    char unk0d, unk0e, unk0f;
    float m_fEaseSpinner;
    float m_fLastEvaluationTime;
    void LoadFromStream(NiStream* stream);
};

// @fnv 0x00a377b0
void LoadInterpItem::LoadFromStream(NiStream* stream)
{
    NiInterpolator* pInterpolator = (NiInterpolator*)stream->DeserializeObject();
    if (m_spControllerInterpolator != pInterpolator)
    {
        if (m_spControllerInterpolator)
            m_spControllerInterpolator->DecRefCount();
        m_spControllerInterpolator = pInterpolator;
        if (pInterpolator)
            pInterpolator->IncRefCount();
    }
    LoadStreamBinary(reinterpret_cast<LoadBinStream*>(&stream->Istr()), m_fWeight);
    LoadStreamBinary(reinterpret_cast<LoadBinStream*>(&stream->Istr()), m_fNormalizedWeight);
    if (stream->GetFileVersion() < 0x0a01006e)
    {
        int priority;
        LoadStreamBinary(reinterpret_cast<LoadBinStream*>(&stream->Istr()), priority);
        if (priority == 0x80000000)
            m_cPriority = (char)0x80;
        else
            m_cPriority = (char)priority;
    }
    else
    {
        LoadStreamBinary(reinterpret_cast<LoadBinStream*>(&stream->Istr()), m_cPriority);
    }
    LoadStreamBinary(reinterpret_cast<LoadBinStream*>(&stream->Istr()), m_fEaseSpinner);
}

struct InterpolatorRegistry;
#include "../../../../include/NiTMallocInterface.h"
#include "../../../../include/NiTPrimitiveArray.h"
// Gamebryo NiTArray.inl: the original inlines Add (SetAtGrow) and calls SetSize (0x0096ad30) / SetAt (0x0096ae90)
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    unsigned int index = m_usSize;
    unsigned int capacity = m_usMaxSize;
    if (index >= capacity)
        SetSize(index + m_usGrowBy);
    SetAt(index, element);
    return index;
}
struct LinkedInterpolator
{
    unsigned int m_pHeadNode;
    unsigned int m_iSecondInteger;
    void* m_object;
};
extern "C" void* DAT_011f36fc;
extern "C" InterpolatorRegistry* DAT_011f36f4;
extern "C" InterpolatorRegistry* DAT_011f36f8;
extern "C" unsigned char DAT_011a83ff;
extern "C" char UNK_01096b68, UNK_01096b54, UNK_01096b40;
extern "C" char UNK_01096b2c, UNK_01096b1c, UNK_01096b08;
extern "C" char UNK_01096af4, UNK_01096adc, UNK_01096ac4;
extern "C" char UNK_01096ab4, UNK_01096aa4;
extern "C" char UNK_01095dbc, UNK_01096a98, UNK_01096a8c;
extern "C" char UNK_01096a78, UNK_01096a68;
extern "C" const char* __cdecl NiViewerStrings_NiGetViewerString_Title(void*);
extern "C" const char* __cdecl NiGetViewerString_00a7d410(const void*, unsigned int);
struct ViewerBool
{
    bool flag;
};
union ViewerValue
{
    const char* value;
    ViewerBool boolean;
};
extern "C" const char* __cdecl NiGetViewerString(const void*, ViewerBool);
extern "C" const char* __cdecl NiGetViewerString_00a7d4d0(const void*, int);
extern "C" const char* __cdecl NiGetViewerString_00a7d550(const void*, float);
extern "C" const char* __cdecl NiGetViewerString_00a7d5e0(const void*, void*);
struct InterpolatorRegistry
{
    LinkedInterpolator* func_0x00a2e570(NiInterpolator*, unsigned int);
};
class BlendSerializer : public NiBlendInterpolator
{
  public:
    void NiBlendInterpolator_GetViewerStrings(NiViewerStringsArray* stream);
};
// Appends viewer strings for the blend interpolator's fields and, for each array entry with a linked interpolator, its priority, weights and interpolator strings.
// @fnv 0x00a38080
// src: XBOX_PDB 0x00a38080
void BlendSerializer::NiBlendInterpolator_GetViewerStrings(NiViewerStringsArray* stream)
{
    this->NiInterpolator::GetViewerStrings(stream);
    const char* uiValue;
    {
        ViewerValue temp;
        temp.value = NiViewerStrings_NiGetViewerString_Title(DAT_011f36fc);
        stream->Add(temp.value);
        temp.value = NiGetViewerString_00a7d410(&UNK_01096b68, this->m_ucArraySize);
        stream->Add(temp.value);
        temp.value = NiGetViewerString_00a7d410(&UNK_01096b54, DAT_011a83ff);
        stream->Add(temp.value);
        temp.boolean.flag = (this->m_uiObjectFlags & 1) != 0;
        temp.value = NiGetViewerString(&UNK_01096b40, temp.boolean);
        stream->Add(temp.value);
        temp.value = NiGetViewerString_00a7d550(&UNK_01096b2c, this->m_fWeightThreshold);
        stream->Add(temp.value);
        temp.value = NiGetViewerString_00a7d4d0(&UNK_01096b1c, this->m_cHighPriority);
        stream->Add(temp.value);
        temp.value = NiGetViewerString_00a7d4d0(&UNK_01096b08, this->m_cNextHighPriority);
        stream->Add(temp.value);
        temp.value = NiGetViewerString_00a7d550(&UNK_01096af4, this->m_fHighSumOfWeights);
        stream->Add(temp.value);
        temp.value = NiGetViewerString_00a7d550(&UNK_01096adc, this->m_fNextHighSumOfWeights);
        stream->Add(temp.value);
        temp.boolean.flag = ((this->m_uiObjectFlags >> 1) & 1) != 0;
        temp.value = NiGetViewerString(&UNK_01096ac4, temp.boolean);
        stream->Add(temp.value);
        temp.value = NiGetViewerString_00a7d410(&UNK_01096ab4, this->m_ucInterpCount);
        stream->Add(temp.value);
        temp.value = NiGetViewerString_00a7d410(&UNK_01096aa4, this->m_ucSingleIdx);
        stream->Add(temp.value);
    }
    for (unsigned int index = 0; index < this->m_ucArraySize; ++index)
    {
        if (this->m_pInterpArray[index].m_spControllerInterpolator.m_pObject && DAT_011f36f4)
        {
            LinkedInterpolator* linked =
                DAT_011f36f4->func_0x00a2e570(this->m_pInterpArray[index].m_spControllerInterpolator.m_pObject, 1);
            if (!linked && DAT_011f36f8)
            {
                NiInterpolator* retryInterpolator = this->m_pInterpArray[index].m_spControllerInterpolator.m_pObject;
                linked = DAT_011f36f8->func_0x00a2e570(retryInterpolator, 1);
            }
            if (linked)
            {
                void* linkedObject = linked->m_object;
                uiValue = NiGetViewerString_00a7d5e0(&UNK_01095dbc, linkedObject);
                stream->Add(uiValue);
                uiValue = NiGetViewerString_00a7d410(&UNK_01096a98, (unsigned char)this->m_pInterpArray[index].m_cPriority);
                stream->Add(uiValue);
                uiValue = NiGetViewerString_00a7d550(&UNK_01096a8c, this->m_pInterpArray[index].m_fWeight);
                stream->Add(uiValue);
                uiValue = NiGetViewerString_00a7d550(&UNK_01096a78, this->m_pInterpArray[index].m_fNormalizedWeight);
                stream->Add(uiValue);
                uiValue = NiGetViewerString_00a7d550(&UNK_01096a68, this->m_pInterpArray[index].m_fEaseSpinner);
                stream->Add(uiValue);
                NiInterpolator* finalInterpolator = this->m_pInterpArray[index].m_spControllerInterpolator.m_pObject;
                finalInterpolator->GetViewerStrings(stream);
            }
        }
    }
}

struct SBBinaryStream
{
    void* pVtable;
    unsigned int m_uiStreamFlags;
    void* pUnk08;
    unsigned int(__cdecl* m_pfnWrite)(SBBinaryStream* apThis, const void* apvBuffer, unsigned int auiBytes,
                                      unsigned int* apuiComponentSizes, unsigned int auiNumComponents);

    unsigned int BinaryWrite(const void* apvBuffer, unsigned int auiSize)
    {
        unsigned int uiSize = auiSize;
        unsigned int uiBytesWritten = m_pfnWrite(this, apvBuffer, auiSize, &uiSize, 1);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};


template <class T> inline void SBStreamSaveBinary(NiStream& arStream, const T& arValue)
{
    reinterpret_cast<SBBinaryStream*>(arStream.GetBinaryStream())->BinaryWrite(&arValue, sizeof(T));
}

struct SBEntry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

    void SaveBinary(NiStream& arStream);
};

struct SBBase
{
    void* pVtable;
    int unk04;
    int unk08;

    void SaveBinary(NiStream& arStream);
};

struct SBObject : SBBase
{
    unsigned char m_ucFlags;
    unsigned char m_ucEntryCount;
    unsigned char m_ucByte0E;
    unsigned char m_ucByte0F;
    unsigned char m_ucByte10;
    unsigned char m_ucByte11;
    SBEntry* m_pkEntryArray;
    void* m_pkLinked;
    int m_iValue1C;
    int m_iValue20;
    int m_iValue24;
    int m_iValue28;
    int m_iValue2C;

    void NiBlendInterpolator_SaveBinary(NiStream& arStream);
};

// Serializes the base fields, then unless flag bit 1 is set writes the extra bytes and values, each entry, and the link ID.
// @fnv 0x00a37ec0
// src: XBOX_PDB 0x00a37ec0
void SBObject::NiBlendInterpolator_SaveBinary(NiStream& arStream)
{
    SBBase::SaveBinary(arStream);
    SBStreamSaveBinary(arStream, m_ucFlags);
    SBStreamSaveBinary(arStream, m_ucEntryCount);
    SBStreamSaveBinary(arStream, m_iValue1C);
    if (m_ucFlags & 1)
        return;

    SBStreamSaveBinary(arStream, m_ucByte0E);
    SBStreamSaveBinary(arStream, m_ucByte0F);
    SBStreamSaveBinary(arStream, m_ucByte10);
    SBStreamSaveBinary(arStream, m_ucByte11);
    SBStreamSaveBinary(arStream, m_iValue20);
    SBStreamSaveBinary(arStream, m_iValue24);
    SBStreamSaveBinary(arStream, m_iValue28);
    SBStreamSaveBinary(arStream, m_iValue2C);
    for (unsigned char i = 0; i < m_ucEntryCount; i++)
        m_pkEntryArray[i].SaveBinary(arStream);
    arStream.SaveLinkID(reinterpret_cast<const NiObject*>(m_pkLinked));
}

// The engine replaces the global deallocation function with a sized variant;
// this is the routine the original's deleting destructor calls with the size
// of the object it is releasing.
void __cdecl operator delete(void* p, unsigned int n);

// Stand-in for NiBlendInterpolator (48 bytes, virtual destructor in vftable
// slot 0).  The real class is the engine's blend interpolator: it owns an
// array of interpolator entries and a single interpolator, and it carries a
// handful of flag bytes.
struct FUN_00a37670_NiBlendInterpolator
{
    virtual __declspec(noinline) ~FUN_00a37670_NiBlendInterpolator();
    static void operator delete(void* p, unsigned int n);
    int unk04;                      // NiObject
    float m_fLastTime;              // NiInterpolator
    unsigned char m_uiObjectFlags;         // +12
    unsigned char m_ucArraySize;    // +13
    unsigned char m_ucInterpCount;  // +14
    unsigned char m_ucSingleIdx;    // +15
    char m_cHighPriority;           // +16
    char m_cNextHighPriority;       // +17
    unsigned char unk18;
    unsigned char unk19;
    void* m_pInterpArray;             // +20
    void* m_pSingleInterpolator;      // +24
    float m_fWeightThreshold;         // +28
    float m_fSingleInterpolatorTime;  // +32
    float m_fHighSumOfWeights;        // +36
    float m_fNextHighSumOfWeights;    // +40
    float m_fTrailingValue;           // +44
};

// Clears m_pInterpArray and m_pSingleInterpolator, then sets m_ucInterpCount to zero.
// @fnv 0x00a37670
FUN_00a37670_NiBlendInterpolator::~FUN_00a37670_NiBlendInterpolator()
{
    // The real destructor walks the interpolator array and releases every
    // interpolator it holds, then drops the single interpolator.
    m_pInterpArray = 0;
    m_pSingleInterpolator = 0;
    m_ucInterpCount = 0;
}

void FUN_00a37670_NiBlendInterpolator::operator delete(void* p, unsigned int n)
{
    ::operator delete(p, n);
}
