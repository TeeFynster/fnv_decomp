#include "../../../include/NiTPointerList.h"
// fallout_shared/facegen/bsfacegenanimationdata.cpp: BSFaceGenAnimationData, BSFaceGenKeyframeMultiple, BSFaceGenEyeData (43 functions)

#include "../../../include/BSFaceGenKeyframe.h"
#include "../../../include/BSFaceGenKeyframeMultiple.h"
#include "../../../include/NiTPointerList.h"
#include "../../../include/NiTListItem.h"
#include "../../../include/BSFaceGenManager.h"

// The shared list lacks out-of-line constructor/destructor declarations needed by
// BSFaceGenAnimationData's constructor (0x00649680) and destructor (0x00649ce0).

#include "../../../include/BSFaceGenAnimationData.h"

#include "../../../include/NiQuaternion.h"
#include "../../../include/BSFadeNode.h"
#include "../../../include/NiExtraData.h"
#include "../../../include/NiFixedString.h"
#include "../../../include/NiPlane.h"
#include "../../../include/NiPoint2.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/RecursiveSpinLock.h"
#include "../../../include/Setting.h"
#include "../../../include/SettingT_GameSettingCollection_.h"
#include "bsfacegenanimationdata_decls.h"

// Deletes the target object if present and sets the target pointer to null.
// @fnv 0x0064b5e0
void BSFaceGenAnimationData::ClearTransitionTarget()
{
    if (target)
        delete target;
    target = 0;
}
// Forwards the four boolean arguments to the virtual functions at vtable slots 0x100 and 0x104.
// @fnv 0x0064ae60
void BSFaceGenAnimationData::SetMorphFlags(bool abArg1, bool abArg2, bool abArg3, bool abArg4)
{
    vfn_100(abArg1, abArg2, abArg3, abArg4);
    vfn_104(abArg1, abArg2, abArg3, abArg4);
}
// @fnv 0x0064a920
void BSFaceGenAnimationData::SetStateFlags(bool abDead, bool b)
{
    if (abDead && !dead)
    {
        vfn_b4(b ? 0.0f : 1.0f, true, true, true, true, true);
        dead = abDead;
        dirty = true;
    }
    else if (!abDead && dead)
    {
        dead = abDead;
        vfn_b4(b ? 0.0f : 1.0f, true, true, true, true, false);
        dirty = true;
        changed = true;
    }
}
// @fnv 0x0064ab40
void BSFaceGenAnimationData::AddModifierKeyframe(float* values, float time)
{
    BSFaceGenKeyframeMultiple frame(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_MODIFIER, 17);
    if (dead || !values || time < 0.0)
        return;
    frame.SetTime(time);
    for (unsigned i = 0; i < 17; i++)
        frame.SetQuantity_0064a4d0(i, values[i]);
    frame.InsertIntoKeyframeList((NiTPointerList<BSFaceGenKeyframe*>*)((char*)this + 0x88));
}
// @fnv 0x0064ad20
void BSFaceGenAnimationData::AddKeyframe(BS_FACEGEN_MORPH_TYPE type, float time, bool unused)
{
    if (dead)
        return;
    switch (type)
    {
    case BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_PHONEME: {
        BSFaceGenKeyframeMultiple frame(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_PHONEME, 16);
        frame.SetTime(time);
        frame.InsertIntoKeyframeList((NiTPointerList<BSFaceGenKeyframe*>*)((char*)this + 0xbc));
        break;
    }
    case BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_MODIFIER: {
        BSFaceGenKeyframeMultiple frame(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_MODIFIER, 17);
        frame.SetTime(time);
        frame.InsertIntoKeyframeList((NiTPointerList<BSFaceGenKeyframe*>*)((char*)this + 0x88));
        break;
    }
    case BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_CUSTOM: {
        BSFaceGenKeyframeMultiple frame(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_CUSTOM, 1);
        frame.SetTime(time);
        frame.InsertIntoKeyframeList((NiTPointerList<BSFaceGenKeyframe*>*)((char*)this + 0xf0));
        break;
    }
    }
}
// @fnv 0x0064aa00
void BSFaceGenAnimationData::InsertPhonemeKeyframe(float* values, float time)
{
    BSFaceGenKeyframeMultiple frame(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_PHONEME, 16);
    if (dead || !values || time < 0.0)
        return;
    unsigned i;
    for (i = 0; i < 16; i++)
    {
        if (values[i] < 0.0 || values[i] > 1.0)
            return;
    }
    frame.SetTime(time);
    for (i = 0; i < 16; i++)
        frame.SetQuantity_0064a4d0(i, values[i]);
    frame.InsertIntoKeyframeList((NiTPointerList<BSFaceGenKeyframe*>*)((char*)this + 0xbc));
}
// @fnv 0x0064b2b0
void BSFaceGenAnimationData::SetExpressionWeight(int expression, float quantity)
{
    if (expression < -1 || expression > 15 || quantity < 0.0 || quantity > 1.0)
        return;
    if (target)
        target->ClearData(true);
    else
    {
        target = new BSFaceGenKeyframeMultiple(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_EXPRESSION, 15);
        target->NormalizeFaceGenValues();
    }
    if (expression == -1 || quantity == 0.0)
        return;
    target->SetQuantity_0064a4d0(expression, quantity);
    if (!((BSFaceGenKeyframeMultiple*)((char*)this + 0x10))->vfn_2c(target))
        ClearTransitionTarget();
}
// Reads three rotation values, clamps each to a range, stores them into the quaternion, and returns whether it differs from identity.
// @fnv 0x0064a100
bool BSFaceGenAnimationData::CalculateRotationQuaternion(NiQuaternion& rotation)
{
    float fX = ((BSFaceGenKeyframeMultiple*)((char*)this + 0xa8))->BSFaceGenKeyframeMultiple_GetQuantity(16);
    float fZ = ((BSFaceGenKeyframeMultiple*)((char*)this + 0xa8))->BSFaceGenKeyframeMultiple_GetQuantity(15);
    float fY = ((BSFaceGenKeyframeMultiple*)((char*)this + 0xa8))->BSFaceGenKeyframeMultiple_GetQuantity(14);
    if (fX == DAT_010231b0)
        fX = 0.0f;
    fX = fX > DAT_01064f58 ? (fX < DAT_01064f50 ? fX : DAT_01064f50) : DAT_01064f58;
    if (fZ == DAT_010231b0)
        fZ = 0.0f;
    fZ = fZ > DAT_01064f58 ? (fZ < DAT_01064f50 ? fZ : DAT_01064f50) : DAT_01064f58;
    if (fY == DAT_010231b0)
        fY = 0.0f;
    fY = fY > DAT_01064f58 ? (fY < DAT_01064f50 ? fY : DAT_01064f50) : DAT_01064f58;
    rotation.SetRotationFromEulerXYZ(fX, fZ, fY);
    return rotation != NiQuaternion::IDENTITY;
}
// @fnv 0x0064a770
void BSFaceGenAnimationData::FadeOutMorphs(float time, bool expression, bool phoneme, bool modifier, bool custom)
{
    vfn_104(expression, phoneme, modifier, custom);
    if (expression)
    {
        ((BSFaceGenKeyframeMultiple*)((char*)this + 0x24))->vfn_10(0.0f);
        if (time > 0.0)
            vfn_f8(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_EXPRESSION, time, true);
        else
            ((BSFaceGenKeyframeMultiple*)((char*)this + 0x24))->ClearData(true);
    }
    if (modifier)
    {
        ((BSFaceGenKeyframeMultiple*)((char*)this + 0x38))->vfn_10(0.0f);
        if (time > 0.0)
            vfn_f8(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_MODIFIER, time, true);
        else
            ((BSFaceGenKeyframeMultiple*)((char*)this + 0x38))->ClearData(true);
    }
    if (phoneme)
    {
        ((BSFaceGenKeyframeMultiple*)((char*)this + 0x4c))->vfn_10(0.0f);
        if (time > 0.0)
            vfn_f8(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_PHONEME, time, true);
        else
            ((BSFaceGenKeyframeMultiple*)((char*)this + 0x4c))->ClearData(true);
    }
    if (custom)
    {
        ((BSFaceGenKeyframeMultiple*)((char*)this + 0x60))->vfn_10(0.0f);
        if (time > 0.0)
            vfn_f8(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_CUSTOM, time, true);
        else
            ((BSFaceGenKeyframeMultiple*)((char*)this + 0x60))->ClearData(true);
    }
}
// If index is within count and quantities[index] differs from value, stores value there and returns true; otherwise returns false.
// @fnv 0x0064a4d0
// src: XBOX_PDB 0x0064a4d0
bool BSFaceGenKeyframeMultiple::SetQuantity_0064a4d0(unsigned int index, float value)
{
    if (index < m_uiFaceGenValueCount && m_pfFaceGenValues[index] != value)
    {
        m_pfFaceGenValues[index] = value;
        return true;
    }
    return false;
}

extern NiFixedString* DAT_011d5744;

// Allocates the "FAD" fixed string and stores it in DAT_011d5744.
// @fnv 0x00649e40
// src: COMMUNITY 0x00649e40
void BSFaceGenAnimationData_InitTag()
{
    DAT_011d5744 = ::new NiFixedString("FAD");
}

extern const double gModifierZero;

struct BSFaceGenAnimationData_Vtable
{
    char pad[0xb8];
    void(__thiscall* vfn_b8)(void*, float, bool, bool, bool, bool, bool);
    void(__thiscall* vfn_bc)(void*, float, bool, bool, bool, bool);
};

// @fnv 0x0064a310
void BSFaceGenAnimationData::ResetFaceGenAnimationData(float afTime, bool abResetExpression, bool abResetPhoneme,
                                                   bool abResetModifier, bool abResetCustomMorph, bool abForDeath)
{
    reinterpret_cast<RecursiveSpinLock*>(reinterpret_cast<char*>(this) + 0x1a0)->Lock(0);

    (*reinterpret_cast<BSFaceGenAnimationData_Vtable**>(this))
        ->vfn_b8(this, afTime, abResetExpression, abResetPhoneme, abResetModifier, abResetCustomMorph, abForDeath);
    (*reinterpret_cast<BSFaceGenAnimationData_Vtable**>(this))
        ->vfn_bc(this, afTime, abResetExpression, abResetPhoneme, abResetModifier, abResetCustomMorph);

    if (afTime == gModifierZero)
    {
        if (abResetExpression)
        {
            reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0x74)->vfn_10(0.0f);
            reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0x74)->ClearData(true);
        }
        if (abResetModifier)
        {
            reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0xa8)->vfn_10(0.0f);
            reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0xa8)->ClearData(true);
            if (abForDeath)
            {
                reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0xa8)
                    ->SetQuantity_0064a4d0(0, 1.0f);
                reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0xa8)
                    ->SetQuantity_0064a4d0(1, 1.0f);
            }
        }
        if (abResetPhoneme)
        {
            reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0xdc)->vfn_10(0.0f);
            reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0xdc)->ClearData(true);
        }
        if (abResetCustomMorph)
        {
            reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0x110)->vfn_10(0.0f);
            reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0x110)->ClearData(true);
        }
    }

    reinterpret_cast<RecursiveSpinLock*>(reinterpret_cast<char*>(this) + 0x1a0)->Unlock();
}

extern double _gModifierZero;

// @fnv 0x0064a520
void BSFaceGenAnimationData::ResetFaceGenData(float afTime, bool abResetExpression, bool abResetPhoneme,
                                          bool abResetModifier, bool abResetCustomMorph, bool abForDeath)
{
    float pmods[17];

    reinterpret_cast<void(__thiscall*)(void*, bool, bool, bool, bool)>((*reinterpret_cast<void***>(this))[0xfc / 4])(
        this, abResetExpression, abResetPhoneme, abResetModifier, abResetCustomMorph);

    if (abResetExpression)
    {
        reinterpret_cast<void(__thiscall*)(void*, float)>((*reinterpret_cast<void***>(
            reinterpret_cast<char*>(this) + 0x10))[0x10 / 4])(reinterpret_cast<char*>(this) + 0x10, 0.0f);

        if (afTime > _gModifierZero)
        {
            reinterpret_cast<void(__thiscall*)(void*, int, float)>((*reinterpret_cast<void***>(this))[0x114 / 4])(
                this, -1, 1.0f);
        }
        else
        {
            reinterpret_cast<void(__thiscall*)(void*, int)>((*reinterpret_cast<void***>(
                reinterpret_cast<char*>(this) + 0x10))[0x20 / 4])(reinterpret_cast<char*>(this) + 0x10, 1);
        }
    }

    if (abResetModifier)
    {
        reinterpret_cast<void(__thiscall*)(void*, float)>((*reinterpret_cast<void***>(
            reinterpret_cast<char*>(this) + 0x94))[0x10 / 4])(reinterpret_cast<char*>(this) + 0x94, 0.0f);

        if (afTime > _gModifierZero)
        {
            if (abForDeath)
            {
                BSFaceGenManager::ApplyFaceGenValues(pmods, 0x11, 1);
                pmods[0] = 1.0f;
                pmods[1] = 1.0f;
                reinterpret_cast<void(__thiscall*)(void*, float*, float)>((*reinterpret_cast<void***>(this))[0xf0 / 4])(
                    this, pmods, afTime);
            }
            else
            {
                reinterpret_cast<void(__thiscall*)(void*, int, float, int)>(
                    (*reinterpret_cast<void***>(this))[0xf4 / 4])(this, 2, afTime, 1);
            }
        }
        else
        {
            reinterpret_cast<void(__thiscall*)(void*, int)>((*reinterpret_cast<void***>(
                reinterpret_cast<char*>(this) + 0x94))[0x20 / 4])(reinterpret_cast<char*>(this) + 0x94, 1);

            if (abForDeath)
            {
                reinterpret_cast<void(__thiscall*)(void*, int, float)>((*reinterpret_cast<void***>(this))[0xa0 / 4])(
                    this, 0, 1.0f);
                reinterpret_cast<void(__thiscall*)(void*, int, float)>((*reinterpret_cast<void***>(this))[0xa0 / 4])(
                    this, 1, 1.0f);
            }
        }
    }

    if (abResetPhoneme)
    {
        reinterpret_cast<void(__thiscall*)(void*, float)>((*reinterpret_cast<void***>(
            reinterpret_cast<char*>(this) + 0xc8))[0x10 / 4])(reinterpret_cast<char*>(this) + 0xc8, 0.0f);

        if (afTime > _gModifierZero)
        {
            reinterpret_cast<void(__thiscall*)(void*, int, float, int)>((*reinterpret_cast<void***>(this))[0xf4 / 4])(
                this, 0, afTime, 1);
        }
        else
        {
            reinterpret_cast<void(__thiscall*)(void*, int)>((*reinterpret_cast<void***>(
                reinterpret_cast<char*>(this) + 0xc8))[0x20 / 4])(reinterpret_cast<char*>(this) + 0xc8, 1);
        }
    }

    if (abResetCustomMorph)
    {
        reinterpret_cast<void(__thiscall*)(void*, float)>((*reinterpret_cast<void***>(
            reinterpret_cast<char*>(this) + 0xfc))[0x10 / 4])(reinterpret_cast<char*>(this) + 0xfc, 0.0f);

        if (afTime > _gModifierZero)
        {
            reinterpret_cast<void(__thiscall*)(void*, int, float, int)>((*reinterpret_cast<void***>(this))[0xf4 / 4])(
                this, 3, afTime, 1);
        }
        else
        {
            reinterpret_cast<void(__thiscall*)(void*, int)>((*reinterpret_cast<void***>(
                reinterpret_cast<char*>(this) + 0xfc))[0x20 / 4])(reinterpret_cast<char*>(this) + 0xfc, 1);
        }
    }
}

// @fnv 0x0064b400
void BSFaceGenAnimationData::SetMoodExpression(int aiMoodindex, bool abTalking)
{
    if (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c) != 0)
    {
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->ClearData(true);
    }
    else
    {
        *reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c) =
            new BSFaceGenKeyframeMultiple(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_EXPRESSION, 15);
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->NormalizeFaceGenValues();
    }

    if (*reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x18e))
        return;

    switch (aiMoodindex)
    {
    case 0:
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->SetQuantity_0064a4d0(5, 1.0f);
        break;
    case 1:
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->SetQuantity_0064a4d0(6, 1.0f);
        break;
    case 2:
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->SetQuantity_0064a4d0(7, 1.0f);
        break;
    case 3:
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->SetQuantity_0064a4d0(8, 1.0f);
        break;
    case 4:
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->SetQuantity_0064a4d0(9, 1.0f);
        break;
    case 5:
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->SetQuantity_0064a4d0(10, 1.0f);
        break;
    case 6:
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->SetQuantity_0064a4d0(11, 1.0f);
        break;
    case 7:
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->SetQuantity_0064a4d0(12, 1.0f);
        break;
    }

    if (!reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0x10)
             ->vfn_2c(*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c)))
    {
        typedef void(__thiscall * Vfn120)(void*);
        (*reinterpret_cast<Vfn120*>((*reinterpret_cast<char**>(this)) + 0x120))(this);
    }
}

class Script;

namespace facegen_script_list {
// Removes the head node from the list, fixes up head/tail links, deletes the node, decrements the count and returns its Script element.
// @fnv 0x007b5390
Script* __fastcall PopFrontScript(NiTPointerListBase<NiTPointerAllocator<unsigned int>, Script*>* pThis)
{
    NiTListItem<Script*>* pkNode = pThis->m_pkHead;
    pThis->m_pkHead = pThis->m_pkHead->m_pkNext;
    if (pThis->m_pkHead)
        pThis->m_pkHead->m_pkPrev = 0;
    else
        pThis->m_pkTail = 0;

    Script* pScript = pkNode->m_element;
    pThis->DeleteItem(pkNode);
    pThis->m_kItemCount.m_uiCount--;
    return pScript;
}
}  // namespace facegen_script_list

extern Setting originalRuntimeFloatSetting1271;
extern const double DAT_01023128;
// @fnv 0x00649f00
void ComputeAngleRange(float* afMin, float* afMax)
{
    *afMax = *originalRuntimeFloatSetting1271.Float() * DAT_01023128;
    if (*afMax < _gModifierZero)
        *afMax = 0.0f;
    if (*afMax > DAT_01064f50)
        *afMax = 1.5707964f;
    *afMin = *afMax * -1.0;
}

namespace fnv_00649f70 {
extern Setting originalRuntimeFloatSetting1271;
extern const double DAT_01023128;
// @fnv 0x00649f70
void ClampMinMaxFromSetting(float* afMin, float* afMax)
{
    *afMax = *originalRuntimeFloatSetting1271.Float() * DAT_01023128;
    if (*afMax < _gModifierZero)
        *afMax = 0.0f;
    if (*afMax > DAT_01064f50)
        *afMax = 1.5707964f;
    *afMin = *afMax * -1.0;
}
}  // namespace fnv_00649f70

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1273;
extern const double DAT_01023128;
extern double _gModifierZero;
void __cdecl ComputeAngleRange(float*, float*);
// @fnv 0x00649fe0
// src: COMMUNITY 0x00649fe0
void BSFaceGenAnimationData_GetTrackDeadZoneXYMinMax(float* afMin, float* afMax)
{
    float fMin;
    float fScaledValue;
    *afMax = *originalRuntimeFloatSetting1273.Float() * DAT_01023128;
    if (*afMax < _gModifierZero)
        *afMax = 0.0f;
    if (*afMax > DAT_01064f50)
        *afMax = 1.5707964f;
    ComputeAngleRange(&fMin, &fScaledValue);
    if (*afMax > fScaledValue)
        *afMax = fScaledValue;
    *afMin = *afMax * -1.0;
}

extern const double DAT_01023128;
extern const double DAT_01064f50;
extern double _gModifierZero;
extern Setting originalRuntimeFloatSetting1274;
void __cdecl ClampMinMaxFromSetting(float*, float*);

// Computes a clamped max eye angle from a runtime float setting and writes its negation as the min angle.
// @fnv 0x0064a070
void __cdecl GetEyeAngleLimits(float* afMinOut, float* afMaxOut)
{
    float fminEye;
    float fmaxEye;
    *afMaxOut = *originalRuntimeFloatSetting1274.Float() * DAT_01023128;
    if (*afMaxOut < _gModifierZero)
        *afMaxOut = 0.0f;
    if (*afMaxOut > DAT_01064f50)
        *afMaxOut = 1.5707963705062866f;
    ClampMinMaxFromSetting(&fminEye, &fmaxEye);
    if (*afMaxOut > fmaxEye)
        *afMaxOut = fmaxEye;
    *afMinOut = *afMaxOut * -1.0;
}

namespace fnv_0064b630 {
typedef char _sizecheck_NiPoint2[sizeof(NiPoint2) == 8 ? 1 : -1];

extern double _gModifierZero;
float RandomFloat0To1();
bool BSFaceGenManager_GetUseProceduralEyeBlinking();
extern Setting originalRuntimeFloatSetting1263;
extern Setting originalRuntimeFloatSetting1264;
extern Setting originalRuntimeFloatSetting1265;
extern Setting originalRuntimeFloatSetting1266;
extern Setting originalRuntimeFloatSetting1276;

class FaceGenKeyframeCalls
{
  public:
    virtual ~FaceGenKeyframeCalls();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void Blend(FaceGenKeyframeCalls*, float, bool, bool);
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void Copy(FaceGenKeyframeCalls*);
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual bool Update(float, FaceGenKeyframeCalls*);
    virtual bool IsChanged();
};

bool AdvanceKeyframe(float, NiTPointerList<BSFaceGenKeyframe*>*, FaceGenKeyframeCalls*, bool);

}  // namespace fnv_0064b630

// @fnv 0x0064b630
bool BSFaceGenAnimationData::UpdateFaceGenAnimation(float afTime)
{
    using namespace fnv_0064b630;
    reinterpret_cast<RecursiveSpinLock*>((char*)this + 0x1a0)->Lock(0);
    NiPoint2 delta;
    bool bchangedSpeech;
    float ftime = afTime;
    bool bchangedExp;
    float flookdown = reinterpret_cast<BSFaceGenKeyframeMultiple*>((char*)this + 0xa8)->BSFaceGenKeyframeMultiple_GetQuantity(8);
    bool bchangedAnim;
    bool bchangedCust;
    bool bchangedMod;
    bool bchangedPhon;

    if (fnv_0064b630::BSFaceGenManager_GetUseProceduralEyeBlinking() && !*((bool*)this + 0x18e) && reinterpret_cast<NiTPointerList<BSFaceGenKeyframe*>*>((char*)this + 0x88)->IsEmpty() &&
        *originalRuntimeFloatSetting1263.Float() > fnv_0064b630::_gModifierZero &&
        *originalRuntimeFloatSetting1264.Float() > fnv_0064b630::_gModifierZero &&
        *originalRuntimeFloatSetting1265.Float() > fnv_0064b630::_gModifierZero &&
        *originalRuntimeFloatSetting1266.Float() >= *originalRuntimeFloatSetting1265.Float() &&
        flookdown < *originalRuntimeFloatSetting1276.Float())
    {
        float fblinkdelay = *originalRuntimeFloatSetting1266.Float() - *originalRuntimeFloatSetting1265.Float();
        float pmods[17];
        BSFaceGenManager::ApplyFaceGenValues(pmods, 17, false);
        pmods[0] = 0.0f;
        pmods[1] = 0.0f;
        this->AddModifierKeyframe(
            pmods, *originalRuntimeFloatSetting1265.Float() + RandomFloat0To1() * fblinkdelay);
        BSFaceGenManager::ApplyFaceGenValues(pmods, 17, false);
        pmods[0] = 1.0f;
        pmods[1] = 1.0f;
        this->AddModifierKeyframe(
            pmods, *originalRuntimeFloatSetting1263.Float());
        BSFaceGenManager::ApplyFaceGenValues(pmods, 17, false);
        pmods[0] = 0.0f;
        pmods[1] = 0.0f;
        this->AddModifierKeyframe(
            pmods, *originalRuntimeFloatSetting1264.Float());
    }

    if (afTime > fnv_0064b630::_gModifierZero)
    {
        *((bool*)this + 0x18b) = false;

        bchangedSpeech = reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x10)
                             ->Update(ftime, *reinterpret_cast<FaceGenKeyframeCalls**>((char*)this + 0xc));
        if (!*((bool*)this + 0x190) && *((bool*)this + 0x18f))
            bchangedAnim = true;
        else
            bchangedAnim = reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x24)->IsChanged();
        if (!bchangedAnim && !bchangedSpeech)
            this->ClearTransitionTarget();
        if (bchangedSpeech)
        {
            reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x74)
                ->Copy(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x10));
            if (bchangedAnim)
                reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x74)
                    ->Blend(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x24), 1.0f, false, false);
        }
        else if (bchangedAnim)
        {
            reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x74)
                ->Copy(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x24));
        }
        bchangedExp = (bchangedSpeech || bchangedAnim) ? true : false;

        bchangedSpeech = AdvanceKeyframe(ftime, reinterpret_cast<NiTPointerList<BSFaceGenKeyframe*>*>((char*)this + 0x88),
                                         reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x94), false);
        if (!*((bool*)this + 0x190) && *((bool*)this + 0x18f))
            bchangedAnim = true;
        else
            bchangedAnim = reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x38)->IsChanged();
        if (bchangedSpeech)
        {
            reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xa8)
                ->Copy(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x94));
            if (bchangedAnim)
                reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xa8)
                    ->Blend(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x38), 1.0f, false, false);
        }
        else if (bchangedAnim)
        {
            reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xa8)
                ->Copy(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x38));
        }
        bchangedMod = (bchangedSpeech || bchangedAnim) ? true : false;

        bchangedSpeech = AdvanceKeyframe(ftime, reinterpret_cast<NiTPointerList<BSFaceGenKeyframe*>*>((char*)this + 0xbc),
                                         reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xc8), false);
        if (!*((bool*)this + 0x190) && *((bool*)this + 0x18f))
            bchangedAnim = true;
        else
            bchangedAnim = reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x4c)->IsChanged();
        if (bchangedSpeech)
        {
            reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xdc)
                ->Copy(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xc8));
            if (bchangedAnim)
                reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xdc)
                    ->Blend(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x4c), 1.0f, false, false);
        }
        else if (bchangedAnim)
        {
            reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xdc)
                ->Copy(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x4c));
        }
        bchangedPhon = (bchangedSpeech || bchangedAnim) ? true : false;

        bchangedSpeech = AdvanceKeyframe(ftime, reinterpret_cast<NiTPointerList<BSFaceGenKeyframe*>*>((char*)this + 0xf0),
                                         reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xfc), false);
        if (!*((bool*)this + 0x190) && *((bool*)this + 0x18f))
            bchangedAnim = true;
        else
            bchangedAnim = reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x60)->IsChanged();
        if (bchangedSpeech)
        {
            reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x110)
                ->Copy(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xfc));
            if (bchangedAnim)
                reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x110)
                    ->Blend(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x60), 1.0f, false, false);
        }
        else if (bchangedAnim)
        {
            reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x110)
                ->Copy(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x60));
        }
        bchangedCust = (bchangedSpeech || bchangedAnim) ? true : false;

        *((bool*)this + 0x18b) = bchangedExp || bchangedMod || bchangedPhon || bchangedCust;
    }

    *((bool*)this + 0x190) = *((bool*)this + 0x18f);
    reinterpret_cast<RecursiveSpinLock*>((char*)this + 0x1a0)->Unlock();
    return *((bool*)this + 0x18b);
}

extern unsigned char DAT_011d59e0;

// @fnv 0x0064bcb0
// src: XBOX_PDB 0x0064bcb0
unsigned char __cdecl BSFaceGenManager_GetUseProceduralEyeBlinking()
{
    return DAT_011d59e0;
}

struct BS_FACEGEN_MODIFIER
{
    int m;
};

struct FaceGenArrayIndex
{
    int value;
};
void __fastcall SetFaceGenArrayElement(BSFaceGenKeyframeMultiple*, FaceGenArrayIndex, float);

// If the modifier index is below 0x11, forwards the index and value to the object at offset 0x38.
// @fnv 0x00649c10
// src: GUESS 0x00649c10 (confidence: medium)
void BSFaceGenAnimationData::SetModifierKeyframeValue(BS_FACEGEN_MODIFIER aeModifier, float afValue)
{
    if (aeModifier.m < 0x11)
    {
        SetFaceGenArrayElement(reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0x38), *reinterpret_cast<FaceGenArrayIndex*>(&aeModifier.m), afValue);
    }
}

// If aeExpression is below 15, forwards aeExpression and afValue to the contained SetArrayElement handler.
// @fnv 0x00649a20
// src: COMMUNITY 0x00649a20
void BSFaceGenAnimationData::SetExpressionValue(int aeExpression, float afValue)
{
    if (aeExpression < 15)
        SetFaceGenArrayElement(&kf10, *reinterpret_cast<FaceGenArrayIndex*>(&aeExpression), afValue);
}

// Forwards aeModifier and afValue to the SetArrayElement handler at offset 0x94 when aeModifier is below 0x11.
// @fnv 0x00649a70
// src: COMMUNITY 0x00649a70
void BSFaceGenAnimationData::SetModifierValue(int aeModifier, float afValue)
{
    if (aeModifier < 0x11)
        SetFaceGenArrayElement(reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0x94), *reinterpret_cast<FaceGenArrayIndex*>(&aeModifier), afValue);
}

// If aePhoneme is below 0x10, forwards aePhoneme and afValue to m.SetArrayElement.
// @fnv 0x00649ae0
// src: COMMUNITY 0x00649ae0
void BSFaceGenAnimationData::SetPhonemeValue(int aePhoneme, float afValue)
{
    if (aePhoneme < 0x10)
    {
        SetFaceGenArrayElement(&kfc8, *reinterpret_cast<FaceGenArrayIndex*>(&aePhoneme), afValue);
    }
}

#include "../../../include/BS_FACEGEN_CUSTOM_MORPH.h"

// @fnv 0x00649b50
// src: COMMUNITY 0x00649b50
void BSFaceGenAnimationData::SetCustomMorphValue(BS_FACEGEN_CUSTOM_MORPH aeCustomMorph, float afValue)
{
    if (aeCustomMorph < 1)
        SetFaceGenArrayElement(reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0xfc), *reinterpret_cast<FaceGenArrayIndex*>(&aeCustomMorph), afValue);
}

// If aeExpression is below 15, forwards aeExpression and afValue to SetArrayElement on the member object.
// @fnv 0x00649be0
// src: GUESS 0x00649be0 (confidence: medium)
void BSFaceGenAnimationData::SetExpressionValue_00649be0(int aeExpression, float afValue)
{
    if (aeExpression < 15)
        SetFaceGenArrayElement(&kf24, *reinterpret_cast<FaceGenArrayIndex*>(&aeExpression), afValue);
}

// If aePhoneme is below 0x10, forwards the phoneme index and value to the SetArrayElement object at offset 0x4C.
// @fnv 0x00649c40
// src: GUESS 0x00649c40 (confidence: medium)
void BSFaceGenAnimationData::SetPhonemeValue_00649c40(int aePhoneme, float afValue)
{
    if (aePhoneme < 0x10)
    {
        SetFaceGenArrayElement(reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0x4C), *reinterpret_cast<FaceGenArrayIndex*>(&aePhoneme), afValue);
    }
}

// If aeCustomMorph is less than 1, forwards aeCustomMorph and afValue to m.SetArrayElement.
// @fnv 0x00649c70
// src: GUESS 0x00649c70 (confidence: medium)
void BSFaceGenAnimationData::SetCustomMorphKeyframeValue(int aeCustomMorph, float afValue)
{
    if (aeCustomMorph < 1)
        SetFaceGenArrayElement(&kf60, *reinterpret_cast<FaceGenArrayIndex*>(&aeCustomMorph), afValue);
}

void __cdecl _delete(void*, unsigned int);

namespace fnv_00649ec0 {
extern NiFixedString* DAT_011d5744;
// Clears DAT_011d5744, deleting the previous fixed string if non-null.
// @fnv 0x00649ec0
// src: GUESS 0x00649ec0 (confidence: low)
void Object_UpdateFields_00649ec0()
{
    NiFixedString* b = DAT_011d5744;
    NiFixedString* a;
    void* c;
    a = b;
    if (a)
        c = a->FUN_004b9900(1);
    else
        c = 0;
    DAT_011d5744 = 0;
}
}  // namespace fnv_00649ec0

extern NiRTTI g_011d57a4;

// @fnv 0x006499c0
const NiRTTI* BSFaceGenAnimationData::GetRTTI() const
{
    return &g_011d57a4;
}

// @fnv 0x00649a50
void __fastcall SetFaceGenArrayElement(BSFaceGenKeyframeMultiple* frame, FaceGenArrayIndex aiIndex, float afValue)
{
    frame->m_pfFaceGenValues[aiIndex.value] = afValue;
}

extern NiPoint3 _NiPoint3_ZERO;

// Resets the point to zero and stores the given flag in bFull.
// @fnv 0x0064bd60
void BSFaceGenAnimationData::Reset(bool abInstant)
{
    unk124.pt = _NiPoint3_ZERO;
    unk124.b188 = abInstant;
}

extern NiPoint3 _NiPoint3_ZERO;

// Tests the stored plane and the incoming point against zero, updates the flag at 0x174 and value at 0x178, stores the point at 0x124 and sets the byte at 0x189.
// @fnv 0x0064bcc0
// src: COMMUNITY 0x0064bcc0
void BSFaceGenAnimationData::SetHeadTrackVector(float afX, float afY, float afZ, int)
{
    if (((NiPlane*)((char*)this + 0x124))->HasEqualComponents(_NiPoint3_ZERO))
    {
        if (((NiPlane*)&afX)->operator==(_NiPoint3_ZERO))
        {
            *(int*)((char*)this + 0x174) = 1;
            *(float*)((char*)this + 0x178) = 0.0f;
        }
    }
    if (((NiPlane*)&afX)->HasEqualComponents(_NiPoint3_ZERO))
        *(int*)((char*)this + 0x174) = 0;
    *(NiPoint3*)((char*)this + 0x124) = *(NiPoint3*)&afX;
    *(char*)((char*)this + 0x189) = 1;
}

unsigned int _data_011c16bc;

// @fnv 0x0064b160
void BSFaceGenAnimationData::SetExpressionKeyframes(float* apQuantities)
{
    if (dead || apQuantities == 0)
    {
        ClearTransitionTarget();
        return;
    }

    if (target)
        delete target;

    target = new BSFaceGenKeyframeMultiple(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_EXPRESSION, 15);

    for (unsigned int iexp = 0; iexp < 15; ++iexp)
        target->SetQuantity_0064a4d0(iexp, apQuantities[iexp]);

    if (!reinterpret_cast<BSFaceGenKeyframe*>(reinterpret_cast<char*>(this) + 0x10)->vfn_2c(target))
        ClearTransitionTarget();
}

// Destructor that calls the cleanup routine with all four flags set to true.
// @fnv 0x00649ce0
BSFaceGenAnimationData::~BSFaceGenAnimationData()
{
    BSFaceGenAnimationData::SetMorphFlags(true, true, true, true);
}

extern const double DAT_01012060;

// @fnv 0x0064ac30
void BSFaceGenAnimationData::SetKeyframeQuantities(float* quantities, float time)
{
    BSFaceGenKeyframeMultiple keyframe(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_CUSTOM, 1);
    if (dead || quantities == 0 || time < DAT_01012060)
    {
        return;
    }

    keyframe.SetTime(time);
    for (unsigned int i = 0; i < 1; ++i)
    {
        keyframe.SetQuantity_0064a4d0(i, quantities[i]);
    }
    keyframe.AddToCompatibleList(
        reinterpret_cast<NiTPointerList<BSFaceGenKeyframe*>*>(reinterpret_cast<char*>(this) + 0xf0));
}

// 0x0064aec0  /MT /Od /Oy- /GS /EHsc /Gy  thiscall, 4 bools (ret 0x10)

// Optionally calls vfn_120, then for each enabled flag drains and deletes every item from the corresponding list (blk88, blkbc, blkf0).
// @fnv 0x0064aec0
void BSFaceGenAnimationData::ClearLists(bool abCallVirtual, bool abClearListBc, bool abClearList88, bool abClearListF0)
{
    if (abCallVirtual)
    {
        this->ClearTransitionTarget();
    }
    BSFaceGenKeyframe* pItem;
    if (abClearList88 && obj88.GetSize() != 0)
    {
        pItem = obj88.GetHead();
        while (pItem != 0)
        {
            delete pItem;
            obj88.RemoveHead();
            pItem = (obj88.GetSize() != 0) ? obj88.GetHead() : 0;
        }
    }
    if (abClearListBc && objbc.GetSize() != 0)
    {
        pItem = objbc.GetHead();
        while (pItem != 0)
        {
            delete pItem;
            objbc.RemoveHead();
            pItem = (objbc.GetSize() != 0) ? objbc.GetHead() : 0;
        }
    }
    if (abClearListF0 && objf0.GetSize() != 0)
    {
        pItem = objf0.GetHead();
        while (pItem != 0)
        {
            delete pItem;
            objf0.RemoveHead();
            pItem = (objf0.GetSize() != 0) ? objf0.GetHead() : 0;
        }
    }
}

// Switches on aiMode and returns whether the matching member's Call() returns 0, or 1 for other modes.
// @fnv 0x0064b0f0
unsigned char BSFaceGenAnimationData::Check(int aiMode)
{
    switch (aiMode)
    {
    case 0:
        return objbc.GetSize() == 0;
        break;
    case 2:
        return obj88.GetSize() == 0;
        break;
    case 3:
        return objf0.GetSize() == 0;
        break;
    }
    return 1;
}

unsigned char BSFaceGenManager_GetUseProceduralEyeBlinking();
void ComputeAngleRange(float*, float*);
void ClampMinMaxFromSetting(float*, float*);
void BSClamp_float(float&, float, float);

class BSFaceGenEyeData
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    BSFaceGenKeyframeMultiple modifiers;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    float eyeHeading;
    float eyePitch;
    void SetEyeHeadingAndPitch(float heading, float pitch);
};

// Clamps heading and pitch to the eye limits, writes the normalized values into modifier slots 8-11, and stores eyeHeading and eyePitch.
// @fnv 0x0064c410
void BSFaceGenEyeData::SetEyeHeadingAndPitch(float heading, float pitch)
{
    float maxPitch6;
    float maxHeading9;
    float minHeading3;
    float minPitch;
    if (!BSFaceGenManager_GetUseProceduralEyeBlinking())
        return;
    ComputeAngleRange(&minHeading3, &maxHeading9);
    ClampMinMaxFromSetting(&maxPitch6, &minPitch);
    BSClamp_float(heading, minHeading3, maxHeading9);
    BSClamp_float(pitch, maxPitch6, minPitch);
    if (heading >= 0.0)
    {
        modifiers.SetQuantity_0064a4d0(10, heading / maxHeading9);
        modifiers.SetQuantity_0064a4d0(9, 0.0f);
    }
    else
    {
        modifiers.SetQuantity_0064a4d0(10, 0.0f);
        modifiers.SetQuantity_0064a4d0(9, heading / minHeading3);
    }
    if (pitch >= 0.0)
    {
        modifiers.SetQuantity_0064a4d0(11, pitch / minPitch);
        modifiers.SetQuantity_0064a4d0(8, 0.0f);
    }
    else
    {
        modifiers.SetQuantity_0064a4d0(11, 0.0f);
        modifiers.SetQuantity_0064a4d0(8, pitch / maxPitch6);
    }
    eyeHeading = heading;
    eyePitch = pitch;
}

// 0x0064ca60  /MT /Od /Oy- /GS /EHsc /Gy
// Four stack arguments: time, list, keyframe, and the interpolation flag.

// @fnv 0x0064ca60
// Typed vtable calls retain the signatures of the shared base's placeholder slots.
bool AdvanceKeyframe(float afTime, NiTPointerList<BSFaceGenKeyframe*>* list, BSFaceGenKeyframe* key, bool flag)
{
    bool result2 = false;
    BSFaceGenKeyframe* kf;
    BSFaceGenKeyframe* head;
    BSFaceGenKeyframe* y3;
    BSFaceGenKeyframe* x3;
    if (key == 0 || list == 0)
        return false;
    if (list->GetSize() && list->GetHead())
    {
        x3 = list->GetHead();
        if (reinterpret_cast<int(__thiscall*)(BSFaceGenKeyframe*)>((*reinterpret_cast<void***>(x3))[1])(x3) != reinterpret_cast<int(__thiscall*)(BSFaceGenKeyframe*)>((*reinterpret_cast<void***>(key))[1])(key))
            return false;
    }
    if (list->GetSize() <= 0)
    {
        reinterpret_cast<void(__thiscall*)(BSFaceGenKeyframe*, float)>((*reinterpret_cast<void***>(key))[4])(key, 0.0f);
        return false;
    }
    reinterpret_cast<void(__thiscall*)(BSFaceGenKeyframe*, float)>((*reinterpret_cast<void***>(key))[4])(key, key->vfn_0c() + afTime);

    kf = list->GetHead();
    while (kf != 0 && key->vfn_0c() >= kf->vfn_0c())
    {
        result2 |= reinterpret_cast<bool(__thiscall*)(BSFaceGenKeyframe*, BSFaceGenKeyframe*, float, int, bool)>((*reinterpret_cast<void***>(key))[7])(key, kf, 1.0f, 1, flag);
        reinterpret_cast<void(__thiscall*)(BSFaceGenKeyframe*, float)>((*reinterpret_cast<void***>(key))[4])(key, key->vfn_0c() - kf->vfn_0c());
        list->RemoveHead();
        head = kf;
        y3 = head;
        y3 ? reinterpret_cast<int(__thiscall*)(BSFaceGenKeyframe*, int)>((*reinterpret_cast<void***>(y3))[0])(y3, 1) : 0;
        if (list->GetSize() > 0)
            kf = list->GetHead();
        else
            kf = 0;
    }
    if (kf != 0)
        result2 |= reinterpret_cast<bool(__thiscall*)(BSFaceGenKeyframe*, BSFaceGenKeyframe*, float, int, bool)>((*reinterpret_cast<void***>(key))[7])(key, kf, key->vfn_0c() / kf->vfn_0c(), 1, flag);
    else
        reinterpret_cast<void(__thiscall*)(BSFaceGenKeyframe*, float)>((*reinterpret_cast<void***>(key))[4])(key, 0.0f);
    return result2;
}

const NiFixedString& Get_Ni_FAD();

extern const NiPoint3 NiPoint3_ZERO;

#pragma inline_depth(0)
// @fnv 0x00649680
BSFaceGenAnimationData::BSFaceGenAnimationData()
    : NiExtraData(Get_Ni_FAD()), kf10(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_EXPRESSION, 15), kf24(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_EXPRESSION, 15), kf38(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_MODIFIER, 17), kf4c(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_PHONEME, 16),
      kf60(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_CUSTOM, 1), kf74(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_EXPRESSION, 15), obj88(), kf94(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_MODIFIER, 17), kfa8(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_MODIFIER, 17), objbc(),
      kfc8(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_PHONEME, 16), kfdc(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_PHONEME, 16), objf0(), kffc(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_CUSTOM, 1), kf110(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_CUSTOM, 1), unk124(), unk1a0()
{
    target = 0;
    unk124.pt = NiPoint3_ZERO;
    unk124.b18b = false;
    unk124.b188 = false;
    unk124.b18c = false;
    unk124.b18e = false;
    unk124.b191 = false;
    unk124.f194 = 0.0f;
    unk124.i174 = 0;
    unk124.f178 = 0.0f;
    unk124.f17c = 0.0f;
    unk124.f140 = 0.0f;
    unk124.f144 = 0.0f;
    unk124.i148 = 0;
    unk124.b14c = true;
    unk124.f138 = 0.0f;
    unk124.f13c = 0.0f;
    unk124.f130 = 0.0f;
    unk124.f134 = 0.0f;
    unk124.f150 = 0.0f;
    unk124.f154 = 0.0f;
    unk124.f158 = 0.0f;
    unk124.f15c = 0.0f;
    unk124.f160 = 0.0f;
    unk124.f164 = 0.0f;
    unk124.f168 = 0.0f;
    unk124.f16c = 0.0f;
    unk124.f170 = 0.0f;
    unk124.b189 = true;
    unk124.b18d = false;
    unk124.pt = NiPoint3_ZERO;
    unk124.b18f = false;
    unk124.b190 = false;
}
