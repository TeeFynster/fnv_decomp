// fallout_shared/sky/moon.cpp: Moon, TaskQueueInterface (11 functions)

#include "../../../include/BSShaderManager.h"
#include "../../../include/BSThread.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiColorA.h"
#include "../../../include/SkyShaderProperty.h"
#include "../../../include/TESSaveLoadGame.h"
#include "../../../include/BGSTerrainManager.h"

#include "../../../include/BSStringT.h"

#include "../../../include/MEM_CONTEXT.h"
#include "../../../include/AutoMemContext.h"

#include "../../../include/Moon.h"
#include "../../../include/SkyObject.h"

// @fnv 0x006366d0
float Moon::GetMoonVisibility()
{
    float fadeStart = 180.0 - m_fFadeStartAngle;
    float fadeEnd = 180.0 - m_fFadeEndAngle;
    if (fPos > 180.0)
        return 0.0f;
    else if (fPos <= m_fFadeStartAngle && fPos >= m_fFadeEndAngle)
        return (fPos - m_fFadeEndAngle) / (m_fFadeStartAngle - m_fFadeEndAngle);
    else if (fPos >= fadeStart && fPos <= fadeEnd)
        return (fadeEnd - fPos) / (fadeEnd - fadeStart);
    else if (fPos > m_fFadeStartAngle && fPos < fadeStart)
        return 1.0f;
    else
        return 0.0f;
}

// Returns a 0..1 visibility factor from fPos using start/end fade angles and their 180-degree mirrored late angles.
// @fnv 0x006367e0
float Moon::GetMoonShadowVisibility()
{
    struct FadeAngles
    {
        float start;
        float lateStart;
        float end;
        float lateEnd;
    } fadeAngles;
    fadeAngles.start = m_fFadeEndAngle;
    fadeAngles.end = m_fFadeEndAngle - m_fFadeAngleRange;
    fadeAngles.lateStart = 180.0 - fadeAngles.start;
    fadeAngles.lateEnd = 180.0 - fadeAngles.end;
    if (fPos > 180.0)
        return 0.0f;
    else if (fPos <= fadeAngles.start && fPos >= fadeAngles.end)
        return (fPos - fadeAngles.end) / (fadeAngles.start - fadeAngles.end);
    else if (fPos >= fadeAngles.lateStart && fPos <= fadeAngles.lateEnd)
        return (fadeAngles.lateEnd - fPos) / (fadeAngles.lateEnd - fadeAngles.lateStart);
    else if (fPos > fadeAngles.start && fPos < fadeAngles.lateStart)
        return 1.0f;
    else
        return 0.0f;
}

class TaskQueueInterface
{
  public:
    void SetTaskFlagDWord(bool, unsigned int);
    void NiAVObject_SetDisplayObject(bool bDisplay);
};

// @fnv 0x00635fe0
// src: XBOX_PDB 0x00635fe0
void TaskQueueInterface::NiAVObject_SetDisplayObject(bool bDisplay)
{
    SetTaskFlagDWord(bDisplay, 0x20);
}

class Flag512Receiver
{
  public:
    void NiAlphaProperty_SetBit(bool, unsigned int);
    void NiAlphaProperty_SetNoSorter(bool enabled);
};

// @fnv 0x00636000
// src: COMMUNITY 0x00636000
void Flag512Receiver::NiAlphaProperty_SetNoSorter(bool enabled)
{
    NiAlphaProperty_SetBit(enabled, 0x2000);
}

struct Calendar
{
    unsigned int GetGameDaysPassed(void);
};
extern Calendar g_calendar;
extern unsigned int DAT_011cca80;
void* __fastcall _ref_0084e3a0(const Sky*);
unsigned int __fastcall TESClimate_GetMoonPhaseDays(void*);

// @fnv 0x006368f0
bool __cdecl Moon::IsMoonVisible(const Sky* apSky)
{
    if (_ref_0084e3a0(apSky) && TESClimate_GetMoonPhaseDays(_ref_0084e3a0(apSky)))
    {
        unsigned int eNewPhase = (g_calendar.GetGameDaysPassed() % (TESClimate_GetMoonPhaseDays(_ref_0084e3a0(apSky)) * 8)) /
                                 TESClimate_GetMoonPhaseDays(_ref_0084e3a0(apSky));
        if (eNewPhase != DAT_011cca80)
        {
            DAT_011cca80 = eNewPhase;
            return true;
        }
    }
    return false;
}

struct FUN_00636980_Helper
{
    char pad[0x55];
    unsigned char f55;
    unsigned char TESClimate_GetMoonPhaseDays();
};

// @fnv 0x00636980
// src: COMMUNITY 0x00636980
unsigned char FUN_00636980_Helper::TESClimate_GetMoonPhaseDays()
{
    return f55 & ~0xc0;
}

struct NiAVObjectFlagQuery
{
    bool HasFlags(unsigned int);
};

// @fnv 0x006366b0
// src: XBOX_PDB 0x006366b0
bool NiAVObject::GetDisplayObject()
{
    return ((NiAVObjectFlagQuery*)this)->HasFlags(0x20);
}

// Clears the four NiPointer members, detaches the node from its parent if it has one, then clears the node pointer.
// @fnv 0x00634ce0
Moon::~Moon()
{
    m_pMoonShadowShape = 0;
    m_pMoonShape = 0;
    m_pMoonShadowNode = 0;
    m_pMoonNode = 0;
    if (m_pRootNode->GetParent())
    {
        m_pRootNode->GetParent()->RemoveObject(m_pRootNode);
    }
    m_pRootNode = 0;
}

// 0x00634a70  /MT /Od /Oy- /GS /EHsc /Gy /GF  thiscall ctor, 7 args (ret 0x1c)
// Moon::Moon(name, fadeStart, fadeEnd, shadowEarlyFade, speed, zOffset, size)

// Builds the moon texture paths from name and phase suffixes, stores fade/speed/z-offset/size parameters, and initialises position and node pointers.
// @fnv 0x00634a70
Moon::Moon(const char* name, float fadeStart, float fadeEnd, float shadowEarlyFade, float speed,
                           float zOffset, unsigned int size)
    : m_pMoonNode(0), m_pMoonShadowNode(0), m_pMoonShape(0), m_pMoonShadowShape(0)
{
    AutoMemContext memContext(MEM_CONTEXT_MEM_CONTEXT_SKY, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Moon.cpp", 50);
    const char* fmt = "\\Textures\\Sky\\%s_%s.dds";
    m_kMoonTexturePaths[3].PrintfString( fmt, name, "one_wan");
    m_kMoonTexturePaths[5].PrintfString( fmt, name, "one_wax");
    m_kMoonTexturePaths[2].PrintfString( fmt, name, "half_wan");
    m_kMoonTexturePaths[6].PrintfString( fmt, name, "half_wax");
    m_kMoonTexturePaths[1].PrintfString( fmt, name, "three_wan");
    m_kMoonTexturePaths[7].PrintfString( fmt, name, "three_wax");
    m_kMoonTexturePaths[0].PrintfString( fmt, name, "full");

    m_fFadeStartAngle = fadeStart;
    m_fFadeEndAngle = fadeEnd;
    m_fFadeAngleRange = shadowEarlyFade;
    fSpeed = speed;
    m_fGlyphVerticalOffset = zOffset;
    iSize = size;
    fPos = 0.0f;
    m_fValue = 3.402823466e+38F;
    m_pMoonNode = 0;
    m_pMoonShadowNode = 0;
    m_pMoonShape = 0;
    m_pMoonShadowShape = 0;
    m_eUpdateStatus = US_NOT_REQUIRED;
}

struct TESSaveLoadGame;

extern TESSaveLoadGame* g_TESSaveLoadGame;
extern double _gModifierZero;
extern double _DAT_010231b0;
extern double DAT_01012638;
extern double DAT_0103c348;
extern const double DAT_01023128;
extern float DAT_010249d8;

float __cdecl BSMIN(float, float);
float __fastcall GetFieldEC(const char*);

struct Mtx
{
    float m0, m1, m2, m3, m4, m5, m6, m7, m8;
    void _ref_006815c0();
    Mtx operator*(const Mtx&) const;
};

namespace MoonUpdateDetail {

struct Flt
{
    operator unsigned int() const;
};

struct PropHelper
{
    void* GetProperty(unsigned int);
};




struct SkyView
{
    int Sky_GetMode();
};

struct Twin_0084d030
{
    float GetStoredFloatValue();
};


struct TESFaction_RankDataView
{
    unsigned char* GetRankDataList();
};

struct FUN_00524ac0_shell
{
    void FUN_00524ac0(float);
};

struct FUN_004a0c90_shell
{
    void FUN_004a0c90(float);
};

} // namespace MoonUpdateDetail

// Updates moon position and visibility, sets texture and culling state on moon nodes, and applies rotation matrices when the sky view is active.
// @fnv 0x00636020
void Moon::Update(::Sky* apSky, float afSecondsPassed)
{
    using MoonUpdateDetail::Flt;
    using MoonUpdateDetail::PropHelper;
    using MoonUpdateDetail::SkyView;
    using MoonUpdateDetail::Twin_0084d030;
    using MoonUpdateDetail::TESFaction_RankDataView;
    using MoonUpdateDetail::FUN_00524ac0_shell;
    using MoonUpdateDetail::FUN_004a0c90_shell;
    float fTimePassed;
    float fvisShadow;
    float fvisMoon;
    float fvisStars;
    ::AutoMemContext tempMemContext(MEM_CONTEXT_MEM_CONTEXT_SKY, true,
                                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Moon.cpp", 0x124);

    ::SkyObject::Update(apSky, afSecondsPassed);

    if (m_fValue == _DAT_010231b0)
    {
        m_fValue = 0;
        fPos = DAT_010249d8;
    }
    if (((TESSaveLoadGame*)::g_TESSaveLoadGame)->GetLoading())
    {
        m_fValue = -((double)(g_calendar.GetGameDaysPassed() - 1) * 24.0);
        fPos = DAT_010249d8;
    }
    fTimePassed = GetFieldEC((const char*)apSky) - m_fValue;
    if (fTimePassed < _gModifierZero)
        fTimePassed = fTimePassed + 24.0;
    fPos = fSpeed * DAT_01012638 * fTimePassed + fPos;
    while (fPos < _gModifierZero)
        fPos = fPos + DAT_0103c348;
    while (fPos >= DAT_0103c348)
        fPos = fPos - DAT_0103c348;
    m_fValue = GetFieldEC((const char*)apSky);

    fvisMoon = GetMoonVisibility();
    fvisShadow = GetMoonShadowVisibility();
    fvisStars = ((Twin_0084d030*)((BSThread*)apSky)->GetThreadID())->GetStoredFloatValue();
    fvisShadow = BSMIN(fvisShadow, fvisStars);

    if (m_eUpdateStatus == US_INITIALIZE ||
        (m_eUpdateStatus == US_WHEN_CULLED && fvisMoon <= _gModifierZero && fvisShadow <= _gModifierZero))
    {
        SkyShaderProperty* pprop =
            (SkyShaderProperty*)((PropHelper*)((const Flt*)&m_pMoonShape)->operator unsigned int())->GetProperty(3);
        ::NiPointer< ::NiTexture> spTex(0);
        BSShaderManager::GetTexture(
            (const char*)((const Flt*)&m_kMoonTexturePaths[DAT_011cca80])->operator unsigned int(), true, spTex, true,
            false);
        ::NiTexture* ptex = (::NiTexture*)((const Flt*)&spTex)->operator unsigned int();
        if (ptex)
            pprop->SetTexture(ptex);
        ((::TaskQueueInterface*)((const Flt*)&m_pMoonShape)->operator unsigned int())->NiAVObject_SetDisplayObject(ptex != 0);
        m_eUpdateStatus = US_NOT_REQUIRED;
    }

    if (((SkyView*)apSky)->Sky_GetMode() == 3 || ((SkyView*)apSky)->Sky_GetMode() == 2)
    {
        if (!((::NiAVObject*)((const Flt*)&m_pRootNode)->operator unsigned int())->GetDisplayObject())
        {
            ((NiAVObject*)((const Flt*)&m_pRootNode)->operator unsigned int())->SetAppCulled(true);
            return;
        }
        Mtx matrixMoonZ;
        Mtx matrixMoonX;
        matrixMoonX._ref_006815c0();
        matrixMoonZ._ref_006815c0();
        ((FUN_00524ac0_shell*)&matrixMoonX)->FUN_00524ac0(-fPos * DAT_01023128);
        ((FUN_004a0c90_shell*)&matrixMoonZ)->FUN_004a0c90(m_fGlyphVerticalOffset * DAT_01023128);
        ((NiAVObject*)((const Flt*)&m_pRootNode)->operator unsigned int())->SetLocalRotation(matrixMoonX * matrixMoonZ);
        if (fvisMoon <= _gModifierZero && fvisShadow <= _gModifierZero)
        {
            ((NiAVObject*)((const Flt*)&m_pRootNode)->operator unsigned int())->SetAppCulled(true);
        }
        else
        {
            ((NiAVObject*)((const Flt*)&m_pRootNode)->operator unsigned int())->SetAppCulled(false);
            if (fvisMoon <= _gModifierZero ||
                !((::NiAVObject*)((const Flt*)&m_pMoonShape)->operator unsigned int())->GetDisplayObject())
            {
                ((NiAVObject*)((const Flt*)&m_pMoonNode)->operator unsigned int())->SetAppCulled(true);
            }
            else
            {
                ((NiAVObject*)((const Flt*)&m_pMoonNode)->operator unsigned int())->SetAppCulled(false);
                SkyShaderProperty* pshadeProperty =
                    (((PropHelper*)((const Flt*)&m_pMoonShape)->operator unsigned int())->GetProperty(3) == 0
                         ? 0
                         : ((BGSTerrainManager*)((PropHelper*)((const Flt*)&m_pMoonShape)->operator unsigned int())
                                ->GetProperty(3))
                                   ->GetMinLevel() == 0xd)
                        ? (SkyShaderProperty*)((PropHelper*)((const Flt*)&m_pMoonShape)->operator unsigned int())
                              ->GetProperty(3)
                        : 0;
                if (pshadeProperty)
                    ((NiColorA*)&pshadeProperty->propertyData[0x60])->a = fvisMoon;
            }
            if (fvisShadow <= _gModifierZero ||
                !((::NiAVObject*)((const Flt*)&m_pMoonShadowShape)->operator unsigned int())->GetDisplayObject())
            {
                ((NiAVObject*)((const Flt*)&m_pMoonShadowNode)->operator unsigned int())->SetAppCulled(true);
            }
            else
            {
                ((NiAVObject*)((const Flt*)&m_pMoonShadowNode)->operator unsigned int())->SetAppCulled(false);
                SkyShaderProperty* pshadeProperty =
                    (((PropHelper*)((const Flt*)&m_pMoonShadowShape)->operator unsigned int())->GetProperty(3) == 0
                         ? 0
                         : ((BGSTerrainManager*)((PropHelper*)((const Flt*)&m_pMoonShadowShape)
                                                     ->
                                                     operator unsigned int())
                                ->GetProperty(3))
                                   ->GetMinLevel() == 0xd)
                        ? (SkyShaderProperty*)((PropHelper*)((const Flt*)&m_pMoonShadowShape)->operator unsigned int())
                              ->GetProperty(3)
                        : 0;
                if (pshadeProperty)
                    *(NiColorA*)&pshadeProperty->propertyData[0x60] =
                        NiColorA(((float*)((TESFaction_RankDataView*)apSky)->GetRankDataList())[0],
                                  ((float*)((TESFaction_RankDataView*)apSky)->GetRankDataList())[1],
                                  ((float*)((TESFaction_RankDataView*)apSky)->GetRankDataList())[2], fvisShadow);
            }
        }
    }
}
