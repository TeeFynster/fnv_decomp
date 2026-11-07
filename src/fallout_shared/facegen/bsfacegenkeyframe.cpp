// fallout_shared/facegen/bsfacegenkeyframe.cpp: BSFaceGenKeyframeMultiple and BSFaceGenKeyframe (26 functions)

#include "layout_support.h"
#include "../../../include/BSFaceGenManager.h"
#include "../../../include/NiTPointerList.h"
#include "../../../include/BSFaceGenKeyframeMultiple.h"
#include "../../../include/SETTING_VALUE.h"
#include "../../../include/SettingT_GameSettingCollection_.h"

// These virtual slots still have unnamed, untyped declarations in the shared base.
typedef BS_FACEGEN_MORPH_TYPE(__thiscall* KeyframeTypeSlot)(const BSFaceGenKeyframe*);
typedef bool(__thiscall* KeyframeMultipleSlot)(BSFaceGenKeyframe*);
typedef bool(__thiscall* KeyframeCompatibilitySlot)(BSFaceGenKeyframe*, BSFaceGenKeyframe*);

// @fnv 0x00488d50
float BSFaceGenKeyframe::GetTime()
{
    return fTime;
}

// @fnv 0x0064f850
void BSFaceGenKeyframeMultiple::NormalizeFaceGenValues()
{
    BSFaceGenManager::NormalizeFaceGenValues(m_pfFaceGenValues, m_uiFaceGenValueCount);
}

// Sets eType to the given morph type and returns true if it changed, otherwise returns false.
// @fnv 0x0064eb00
bool BSFaceGenKeyframe::SetType(BS_FACEGEN_MORPH_TYPE type)
{
    if (type != eType)
    {
        eType = type;
        return true;
    }
    return false;
}

// Sets fTime to the given time and returns true if it changed, otherwise returns false.
// @fnv 0x0064eb30
bool BSFaceGenKeyframe::SetTime(float time)
{
    if (time != fTime)
    {
        fTime = time;
        return true;
    }
    return false;
}

// @fnv 0x0064ed00
BSFaceGenKeyframeMultiple::~BSFaceGenKeyframeMultiple()
{
    BSFaceGenKeyframeMultiple::ApplyFaceGenValues(0, true);
}

// Returns true if quantity is in range and the keyframe value at that index lies between 0.0 and 1.0.
// @fnv 0x0064fb90
bool BSFaceGenKeyframeMultiple::IsQuantityInRange(unsigned int uiIndex)
{
    return uiIndex < m_uiFaceGenValueCount ? (m_pfFaceGenValues[uiIndex] >= 0.0 && m_pfFaceGenValues[uiIndex] <= 1.0)
                                           : false;
}

// Returns the largest value among the keyframes whose validity check passes, or 0.0f if none do.
// @fnv 0x0064f760
float BSFaceGenKeyframeMultiple::GetAttributeStrength()
{
    float fMaxValue = 0.0f;
    for (unsigned int quantity = 0; quantity < m_uiFaceGenValueCount; ++quantity)
    {
        if (IsQuantityInRange(quantity))
        {
            if (m_pfFaceGenValues[quantity] > fMaxValue)
                fMaxValue = m_pfFaceGenValues[quantity];
        }
    }
    return fMaxValue;
}

// @fnv 0x0064f880
bool BSFaceGenKeyframeMultiple::HasNonzeroQuantity()
{
    for (unsigned int i = 0; i < m_uiFaceGenValueCount; ++i)
    {
        float quantity = m_pfFaceGenValues[i];
        if (quantity < 0.0 || quantity > 1.0)
            continue;
        if (quantity > 0.0)
            return true;
    }
    return false;
}

// @fnv 0x0064eb60
BSFaceGenKeyframeMultiple::BSFaceGenKeyframeMultiple(BS_FACEGEN_MORPH_TYPE aeMorphType, unsigned int count)
    : BSFaceGenKeyframe(aeMorphType)
{
    m_pfFaceGenValues = 0;
    m_uiFaceGenValueCount = 0;
    BSFaceGenKeyframeMultiple::ApplyFaceGenValues(count, true);
}

// @fnv 0x0064f480
bool BSFaceGenKeyframeMultiple::ClearData(bool initialize)
{
    bool changed = false;
    if (vfn_0c() != 0.0)
        changed = true;
    vfn_10(0.0f);
    for (unsigned int i = 0; i < GetCount(); ++i)
    {
        if (IsQuantityInRange(i))
        {
            changed = true;
            break;
        }
    }
    ApplyFaceGenValues(GetCount(), initialize);
    return changed;
}

// @fnv 0x0064fc00
void BSFaceGenKeyframeMultiple::ApplyFaceGenValues(unsigned int count, bool initialize)
{
    if (count != m_uiFaceGenValueCount)
    {
        if (m_pfFaceGenValues)
        {
            delete[] m_pfFaceGenValues;
            m_pfFaceGenValues = 0;
        }
        m_uiFaceGenValueCount = count;
        if (m_uiFaceGenValueCount > 0)
        {
            m_pfFaceGenValues = new float[m_uiFaceGenValueCount];
            BSFaceGenManager::ApplyFaceGenValues(m_pfFaceGenValues, m_uiFaceGenValueCount, initialize);
        }
    }
    if (m_uiFaceGenValueCount > 0)
        BSFaceGenManager::ApplyFaceGenValues(m_pfFaceGenValues, m_uiFaceGenValueCount, initialize);
}

// @fnv 0x0064ea80
BSFaceGenKeyframe::BSFaceGenKeyframe(BS_FACEGEN_MORPH_TYPE type)
{
    eType = type;
    fTime = 0.0f;
}

// @fnv 0x0064eae0
BSFaceGenKeyframe::~BSFaceGenKeyframe()
{
}

// Returns true if apOther is not a matching BSFaceGenKeyframeMultiple or any of its per-index values differ from this keyframe's.
// @fnv 0x0064f690
bool BSFaceGenKeyframeMultiple::DiffersFrom(BSFaceGenKeyframe* apOther)
{
    BSFaceGenKeyframeMultiple* pkeyframe = (apOther && ((KeyframeMultipleSlot)(*(void***)apOther)[17])(apOther))
                                             ? static_cast<BSFaceGenKeyframeMultiple*>(apOther)
                                             : 0;
    if (!pkeyframe ||
        ((KeyframeTypeSlot)(*(void***)pkeyframe)[1])(pkeyframe) != ((KeyframeTypeSlot)(*(void***)this)[1])(this) ||
        pkeyframe->GetCount() != GetCount())
    {
        return true;
    }
    for (unsigned int i = 0; i < GetCount(); ++i)
    {
        if (pkeyframe->BSFaceGenKeyframeMultiple_GetQuantity(i) != BSFaceGenKeyframeMultiple_GetQuantity(i))
        {
            return true;
        }
    }
    return false;
}

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting1262;

// Returns the float value of originalRuntimeFloatSetting1262 if it is greater than 0.0, otherwise returns 0.0f.
// @fnv 0x0064fb10
// src: XBOX_PDB 0x0064fb10
float __cdecl BSFaceGenAnimationData_GetExpressionTargetChangePerSec()
{
    return originalRuntimeFloatSetting1262.Float()->f > 0.0 ? originalRuntimeFloatSetting1262.Float()->f : 0.0f;
}

namespace fnv_0064fb50 {
extern SettingT_GameSettingCollection_ g_011d577c;

// Returns the float value from g_011d577c if it is greater than zero, otherwise returns 0.0f.
// @fnv 0x0064fb50
// src: XBOX_PDB 0x0064fb50
float __cdecl BSFaceGenAnimationData_GetExpressionStrengthAddPerSec()
{
    return g_011d577c.Float()->f > 0.0 ? g_011d577c.Float()->f : 0.0f;
}
}  // namespace fnv_0064fb50

// @fnv 0x0064ec10
BSFaceGenKeyframeMultiple::BSFaceGenKeyframeMultiple(const BSFaceGenKeyframeMultiple& aOther)
    : BSFaceGenKeyframe((BS_FACEGEN_MORPH_TYPE)-1)
{
    SetType(((KeyframeTypeSlot)(*(void***)&aOther)[1])(&aOther));
    SetTime(const_cast<BSFaceGenKeyframeMultiple&>(aOther).vfn_0c());
    m_pfFaceGenValues = 0;
    m_uiFaceGenValueCount = 0;
    BSFaceGenKeyframeMultiple::ApplyFaceGenValues(const_cast<BSFaceGenKeyframeMultiple&>(aOther).GetCount(), true);
    for (unsigned int i = 0; i < m_uiFaceGenValueCount; i++)
        SetQuantity_0064a4d0(i, const_cast<BSFaceGenKeyframeMultiple&>(aOther).BSFaceGenKeyframeMultiple_GetQuantity(i));
}

// @fnv 0x0064f5b0
void BSFaceGenKeyframeMultiple::CopyFromKeyframe(BSFaceGenKeyframe* apFrom)
{
    BSFaceGenKeyframeMultiple* pSourceMultiple = apFrom && ((KeyframeMultipleSlot)(*(void***)apFrom)[17])(apFrom)
                                                   ? static_cast<BSFaceGenKeyframeMultiple*>(apFrom)
                                                   : 0;
    if (!pSourceMultiple)
        return;
    SetType(((KeyframeTypeSlot)(*(void***)pSourceMultiple)[1])(pSourceMultiple));
    vfn_10(pSourceMultiple->vfn_0c());
    ApplyFaceGenValues(pSourceMultiple->GetCount(), true);
    for (unsigned int i = 0; i < m_uiFaceGenValueCount; i++)
        SetQuantity_0064a4d0(i, pSourceMultiple->BSFaceGenKeyframeMultiple_GetQuantity(i));
}

// Allocates a new keyframe by copying *this and returns the pointer.
// @fnv 0x0064f530
// src: XBOX_PDB 0x0064f530
BSFaceGenKeyframeMultiple* BSFaceGenKeyframeMultiple::CreateCopy_0064f530()
{
    BSFaceGenKeyframeMultiple* preturn;
    preturn = new BSFaceGenKeyframeMultiple(*this);
    return preturn;
}

extern double _gModifierZero;

// Loops over the keyframes, calling the virtual at vtable slot 19; returns false if any keyframe is active and its value exceeds _gModifierZero, otherwise true.
// @fnv 0x0064f7e0
// src: XBOX_PDB 0x0064f7e0
bool BSFaceGenKeyframeMultiple::IsEmpty_0064f7e0()
{
    unsigned int i;
    for (i = 0; i < m_uiFaceGenValueCount; ++i)
    {
        if (IsQuantityInRange(i) && m_pfFaceGenValues[i] > _gModifierZero)
            return false;
    }
    return true;
}

// @fnv 0x0064ed60
bool BSFaceGenKeyframeMultiple::AddToCompatibleList(NiTPointerList<BSFaceGenKeyframe*>* apList)
{
    if (!apList)
        return false;
    if (vfn_0c() < 0.0)
        return false;
    if (apList->GetSize())
    {
        BSFaceGenKeyframeMultiple* pFirst = static_cast<BSFaceGenKeyframeMultiple*>(apList->GetHead());
        BSFaceGenKeyframeMultiple* pValid =
            (pFirst && ((KeyframeMultipleSlot)(*(void***)pFirst)[17])(pFirst)) ? pFirst : 0;
        if (!pValid ||
            ((KeyframeTypeSlot)(*(void***)pValid)[1])(pValid) != ((KeyframeTypeSlot)(*(void***)this)[1])(this))
            return false;
    }
    BSFaceGenKeyframeMultiple* pCopy = new BSFaceGenKeyframeMultiple(*this);
    apList->AddTail(pCopy);
    return true;
}

// Blends this frame's quantities with frames a and b using weight clamped to [0,1], copying or interpolating per index, and returns the last SetQuantity result.
// @fnv 0x0064f0b0
bool BSFaceGenKeyframeMultiple::BlendWith(BSFaceGenKeyframe* apLeft, BSFaceGenKeyframe* apRight, float weight)
{
    BSFaceGenKeyframeMultiple* leftX = apLeft && ((KeyframeMultipleSlot)(*(void***)apLeft)[17])(apLeft)
        ? static_cast<BSFaceGenKeyframeMultiple*>(apLeft)
        : 0;
    BSFaceGenKeyframeMultiple* right3 = apRight && ((KeyframeMultipleSlot)(*(void***)apRight)[17])(apRight)
        ? static_cast<BSFaceGenKeyframeMultiple*>(apRight)
        : 0;
    bool _deleteLeft = false;
    bool deleteRight = false;
    bool resultB = false;
    if (!leftX || !right3 || leftX == right3 ||
        ((KeyframeTypeSlot)(*(void***)leftX)[1])(leftX) != ((KeyframeTypeSlot)(*(void***)right3)[1])(right3))
        return false;
    if (leftX == this)
    {
        leftX = new BSFaceGenKeyframeMultiple(*this);
        _deleteLeft = true;
    }
    else if (right3 == this)
    {
        right3 = new BSFaceGenKeyframeMultiple(*this);
        deleteRight = true;
    }
    float blendA;
    if (weight < 0.0)
        blendA = 0.0f;
    else if (weight > 1.0)
        blendA = 1.0f;
    else
        blendA = weight;
    unsigned _maximum;
    if (leftX->GetCount() >= right3->GetCount())
        _maximum = leftX->GetCount();
    else
        _maximum = right3->GetCount();
    SetType(((KeyframeTypeSlot)(*(void***)leftX)[1])(leftX));
    for (unsigned index = 0; index < m_uiFaceGenValueCount; ++index)
    {
        if (blendA == 0.0 || !right3->IsQuantityInRange(index))
        {
            if (leftX->IsQuantityInRange(index))
                resultB = SetQuantity(index, leftX->GetQuantity(index));
        }
        else if (blendA == 1.0 || !leftX->IsQuantityInRange(index))
        {
            if (right3->IsQuantityInRange(index))
                resultB = SetQuantity(index, right3->GetQuantity(index));
        }
        else if (leftX->IsQuantityInRange(index) && right3->IsQuantityInRange(index))
        {
            resultB =
                SetQuantity(index, leftX->GetQuantity(index) * (1.0 - blendA) + blendA * right3->GetQuantity(index));
        }
    }
    if (_deleteLeft)
    {
        delete leftX;
    }
    if (deleteRight)
    {
        delete right3;
    }
    return resultB;
}

namespace fnv_0064eea0 {
bool __cdecl FloatEQ(float a, float b, float c);
}

// @fnv 0x0064eea0
bool BSFaceGenKeyframeMultiple::BlendFrom(BSFaceGenKeyframe* pOther, float f, bool b1, bool b2)
{
    BSFaceGenKeyframeMultiple* pfOther = (pOther != 0 && ((KeyframeMultipleSlot)(*(void***)pOther)[17])(pOther))
        ? static_cast<BSFaceGenKeyframeMultiple*>(pOther)
        : 0;
    float fClamped;
    bool bChanged = false;

    if (pfOther == 0 || pfOther == this ||
        ((KeyframeTypeSlot)(*(void***)this)[1])(this) != ((KeyframeTypeSlot)(*(void***)pfOther)[1])(pfOther) ||
        GetCount() != pfOther->GetCount())
    {
        return false;
    }

    if (f < 0.0f)
    {
        fClamped = 0.0f;
    }
    else if (f > 1.0f)
    {
        fClamped = 1.0f;
    }
    else
    {
        fClamped = f;
    }

    for (unsigned int i = 0; i < m_uiFaceGenValueCount; ++i)
    {
        if (!b1 && fnv_0064eea0::FloatEQ(pfOther->BSFaceGenKeyframeMultiple_GetQuantity(i), 0.0f, 0.001f))
        {
            continue;
        }
        if (pfOther->BSFaceGenKeyframeMultiple_GetQuantity(i) < 3.4028234663852886e38)
        {
            if (f < 1.0f && BSFaceGenKeyframeMultiple_GetQuantity(i) < 3.4028234663852886e38)
            {
                bChanged = bChanged | this->SetQuantity_0064a4d0(i, BSFaceGenKeyframeMultiple_GetQuantity(i) * (1.0 - fClamped) +
                                                              pfOther->BSFaceGenKeyframeMultiple_GetQuantity(i) * fClamped);
            }
            else
            {
                bChanged = bChanged | this->SetQuantity_0064a4d0(i, pfOther->BSFaceGenKeyframeMultiple_GetQuantity(i));
            }
        }
        else if (b2)
        {
            bChanged = bChanged | this->SetQuantity_0064a4d0(i, 3.402823466e38f);
        }
    }
    return bChanged;
}

float xBaseRate();
float xRateScale();
float xAbs(float f);

// For compatible inputs, moves active values toward pOther by a time-scaled step and returns true.
// @fnv 0x0064f900
bool BSFaceGenKeyframeMultiple::Interpolate(float fTime, BSFaceGenKeyframe* pOther)
{
    float qfTOqo;
    BSFaceGenKeyframeMultiple* qsSDDgz = (pOther && ((KeyframeMultipleSlot)(*(void***)pOther)[17])(pOther))
        ? static_cast<BSFaceGenKeyframeMultiple*>(pOther)
        : 0;
    float qrEZrs;
    bool qpqRa = false;
    unsigned int qSVM;
    if (fTime <= 0.0 || !qsSDDgz ||
        ((KeyframeTypeSlot)(*(void***)qsSDDgz)[1])(qsSDDgz) != ((KeyframeTypeSlot)(*(void***)this)[1])(this) ||
        qsSDDgz->GetCount() != GetCount() ||
        !((KeyframeCompatibilitySlot)(*(void***)this)[11])(this, qsSDDgz))
        return false;
    qfTOqo = (xBaseRate() + xRateScale() * pOther->GetAttributeStrength()) * fTime;
    for (qSVM = 0; qSVM < GetCount(); qSVM++)
    {
        if (!IsQuantityInRange(qSVM))
            continue;
        qrEZrs = qsSDDgz->GetQuantity(qSVM) - GetQuantity(qSVM);
        if (xAbs(qrEZrs) < qfTOqo)
            qpqRa |= SetQuantity(qSVM, qsSDDgz->GetQuantity(qSVM));
        else if (qrEZrs < 0.0)
            qpqRa |= SetQuantity(qSVM, GetQuantity(qSVM) - qfTOqo);
        else if (qrEZrs > 0.0)
            qpqRa |= SetQuantity(qSVM, GetQuantity(qSVM) + qfTOqo);
    }
    return true;
}
