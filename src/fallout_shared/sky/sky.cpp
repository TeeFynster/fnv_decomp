#include "../../../include/SettingT.h"
// fallout_shared/sky/sky.cpp: Sky, TESObjectCELL and supporting APIs (61 functions)

// Shared game layouts are included below; these declarations supply the
// remaining support APIs needed by this unit.
#include "../../../include/BSStringT.h"
#include "../../../include/BSSimpleList.h"
#include "../../../include/MEM_CONTEXT.h"
#include "../../../include/AnimIdle.h"
#include "../../../include/AutoMemHelper.h"
#include "../../../include/BSAudio.h"
#include "../../../include/BSOcclusionPlane.h"
#include "../../../include/BSSoundHandle.h"
#include "../../../include/ImageSpaceModifierInstanceDOF.h"
#include "../../../include/MobileObject.h"
#include "../../../include/NiAlphaProperty.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiPoint2.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/Setting.h"
#include "../../../include/SL.h"
#include "../../../include/Sun.h"
#include "../../../include/TESObjectCELL.h"
#include "../../../include/TESRegionList.h"
#include "../../../include/AutoMemContext.h"
#include "../../../include/NiColor.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESDataHandler.h"
#include "../../../include/Atmosphere.h"
#include "../../../include/BGSLoadGameBuffer.h"
#include "../../../include/BGSSaveLoadGame.h"
#include "../../../include/Clouds.h"
#include "../../../include/Moon.h"
#include "../../../include/Stars.h"
#include "../../../include/TESTexture.h"
#include "../../../include/Precipitation.h"
#include "../../../include/SettingT_GameSettingCollection_.h"
#include "../../../include/Sky.h"
#include "../../../include/TESClimate.h"
#include "../../../include/TESWeather.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/TESSaveLoadGame.h"
// BSAudio's shared declarations still return the old sound-handle types.
// These declarations expose the same APIs with their checked return type.
class SkyAudio : public BSAudio
{
public:
    BSSoundHandle GetSoundHandleByFormID(unsigned int formID, unsigned int flags);
    BSSoundHandle GetSoundHandleByFormID(int formID, int flags);
};

class TESForm_SkyExt : public TESForm
{
  public:
    static TESForm* GetFormByID(unsigned int);
};

class Renderer
{
  public:
    static bool SetBackgroundColor(NiColor&);
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
class GameSettingCollection;
using ::SettingT;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting76;
extern NiColor DAT_011a9b7c;
void* operator new(unsigned int);

// Additional out-of-line accessors used by this unit are absent from TESWeather.h.
class WeatherAccessMethods : public TESWeather
{
public:
    int TESWeather_GetColor(int, int);
    float TESWeather_GetFogData(int);
    unsigned char TESWeather_GetWeatherDataRaw(int);
    void* TESWeather_GetSoundList();
    int TESWeather_GetCloudColor(int, int);
};

// Climate-specific accessors not yet declared in the shared header.
class ClimateAccessMethods : public TESClimate
{
public:
    bool TESClimate_UsesMasser();
    bool TESClimate_UsesSecunda();
    void* TESClimate_GetTexture(int);
    unsigned char TESClimate_GetVolatilityIndex();
    TESWeather* TESClimate_GetRandomWeather();
};

// @fnv 0x00454b10
unsigned char TESObjectCELL::GetFakeExterior()
{
    return (formData[0x24 - sizeof(TESForm) - sizeof(TESFullName)] & 0x80) != 0;
}

// Updates sky colors, calls FUN_0063bce0, updates the two optional sky objects with time, and sets the renderer background color.
// @fnv 0x0063b0a0
void Sky::UpdateWeatherTransition(float time)
{
    UpdateColors();
    UpdateFog();
    if (m_pAtmosphere)
        m_pAtmosphere->Update(this, time);
    if (m_pSun)
        m_pSun->Update(this, time);
    Renderer::SetBackgroundColor(m_kSkyColors[1]);
}

// @fnv 0x0063c8f0
void Sky::SetCurrentClimate(TESClimate* climate, bool force)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_SKY, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Sky.cpp", 1464);
    if (!climate && (!m_pCurrentClimate || force))
        climate = dynamic_cast<TESClimate*>(TESForm_SkyExt::GetFormByID(0x15f));
    if (!climate)
        return;
    if (m_pCurrentClimate != climate || force)
    {
        m_pCurrentClimate = climate;
        InvalidateCachedValues();
        ResetWeather();
        flags |= 0x40;
    }
}

// @fnv 0x0063ecb0
void Sky::LoadGame(BGSLoadGameBuffer* buffer)
{
    if (g_BGSSaveLoadGame->BGSSaveLoadGame_GetPlayerLocationInvalid())
        return;
    if (m_pPrecipitation)
        m_pPrecipitation->FlushAll();
    if (m_pClouds)
    {
        m_pClouds->ClearCloudLayers();
        m_pClouds->ForceTransTextureUpdate();
    }
    m_pRegionWeather = dynamic_cast<TESWeather*>(TESForm_SkyExt::GetFormByID(buffer->ReadFormIdentifier()));
    m_pPreviousWeather = dynamic_cast<TESWeather*>(TESForm_SkyExt::GetFormByID(buffer->ReadFormIdentifier()));
    m_pQueuedWeather = dynamic_cast<TESWeather*>(TESForm_SkyExt::GetFormByID(buffer->ReadFormIdentifier()));
    m_pOverrideWeather = dynamic_cast<TESWeather*>(TESForm_SkyExt::GetFormByID(buffer->ReadFormIdentifier()));
    buffer->ReadDataBlock(&m_fFogFarDistance, 4);
    buffer->ReadDataBlock(&fWeatherChance, 4);
    buffer->ReadDataBlock(&m_fWeatherBlend, 4);
    unsigned int loadedFlags = 0;
    buffer->ReadDataBlock(&loadedFlags, 4);
    flags = (flags & ~8) | (loadedFlags & 8);
    buffer->ReadDataBlock(&m_fValueBeforeSkyTextureManager, 4);
    if (buffer->GetVersion() >= 18)
    {
        buffer->ReadDataBlock(&m_kSunlightColor.x, 4);
        buffer->ReadDataBlock(&m_kSunlightColor.y, 4);
        buffer->ReadDataBlock(&m_kSunlightColor.z, 4);
    }
    else
        buffer->ReadDataBlock(&m_kSunlightColor, 12);
    buffer->ReadDataBlock(&m_fFogNearDistance, 4);
    buffer->ReadDataBlock(&m_fFogPower, 4);
    buffer->ReadDataBlock(&eMode, 4);
    Update(0.0f);
    UpdateHDRValues();
}

// @fnv 0x00639d40
Sky::Sky() : m_pRootNode(0), m_pSkyNode(0), m_kSunlightColor(0.0f, 0.0f, 0.0f), m_kSkyColor(0.0f, 0.0f, 0.0f)
{
    m_pAtmosphere = 0;
    m_pStars = 0;
    m_pClouds = 0;
    m_pSun = 0;
    m_pPrimaryMoon = 0;
    m_pSecondaryMoon = 0;
    m_pPrecipitation = 0;
    m_pRootNode = 0;
    m_pSkyNode = 0;
    m_fFogFarDistance = 10.0f;
    eMode = 4;
    m_pCurrentClimate = 0;
    m_pOverrideWeather = 0;
    m_pQueuedWeather = 0;
    m_pPreviousWeather = 0;
    m_pRegionWeather = 0;
    fWeatherChance = 0.0f;
    m_pFirstImageSpaceModifierInstance = 0;
    m_pLastWeatherImageSpaceModifier = 0;
    m_pSecondImageSpaceModifierInstance = 0;
    m_pLastWeatherImageSpaceModifier2 = 0;
    for (int i = 0; i < 10; i++)
        m_kSkyColors[i] = DAT_011a9b7c;
    *(NiColor*)&m_kSkyColor = DAT_011a9b7c;
    m_fCurrentWeatherBlend = 0.0f;
    m_fTargetWeatherBlend = 1.0f;
    m_fWeatherBlend = 1.0f;
    m_fValueBeforeSkyTextureManager = 0.0f;
    m_pSkySounds = new BSSimpleList<SkySound*>;
    m_fWeatherFade = 0.0f;
    m_uiSkyFourthValue = 0;
    SkyTextureState = *originalRuntimeFloatSetting76.Float();
    flags = 0;
    UpdateMoonPhase(true);
    SkyEnvironmentController = 12.0f;
    SkyImageSpaceTransitionData = 23.99f;
    SkyImageSpaceBlendData = 0.0f;
}


// @fnv 0x0063a030
// src: XBOX_PDB 0x0063a030
void Sky::UpdateMoonPhase(bool abUpdate)
{
    if (abUpdate)
        flags |= 0x20;
    else
        flags &= ~0x20;
}


// @fnv 0x0063a610
// src: COMMUNITY 0x0063a610
void Clouds::ForceTransTextureUpdate()
{
    bForceUpdate = true;
}


class CloudColorMethods : public Clouds
{
public:
    void Clouds_SetColor(int, const NiColor*);
};

// Copies the NiColor pointed to by the second argument into the layer slot at offset 0x28 indexed by aiLayer.
// @fnv 0x0063b600
// src: XBOX_PDB 0x0063b600
void CloudColorMethods::Clouds_SetColor(int aiLayer, const NiColor* apColor)
{
    pColors[aiLayer] = *apColor;
}


float __cdecl BSMAX_00404010(float, float);
float __fastcall Sky_GetSunriseBegin(void*);
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting78;
extern float DAT_011cccfc;

// @fnv 0x0063b9b0
// src: COMMUNITY 0x0063b9b0
float Sky::GetBeginSunriseColors()
{
    if (flags & 0x1000)
    {
        DAT_011cccfc = BSMAX_00404010(0.0f, Sky_GetSunriseBegin(this) - originalRuntimeFloatSetting78.Float()->f);
        flags &= ~0x1000u;
    }
    return DAT_011cccfc;
}


float __cdecl BSMIN(float, float);
float __fastcall Sky_GetSunsetEnd(void*);
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting78;
extern float DAT_011ccd00;

// If the 0x2000 flag is set, clears it and recomputes DAT_011ccd00 from a setting plus FUN_00596030(this); returns DAT_011ccd00.
// @fnv 0x0063ba30
// src: COMMUNITY 0x0063ba30
float Sky::GetEndSunsetColors()
{
    if (flags & 0x2000)
    {
        DAT_011ccd00 = BSMIN(23.989999771118164f, Sky_GetSunsetEnd(this) + originalRuntimeFloatSetting78.Float()->f);
        flags &= ~0x2000;
    }
    return DAT_011ccd00;
}

// Returns the int stored at tbl[a][b].
// @fnv 0x0063bb40
// src: COMMUNITY 0x0063bb40
int WeatherAccessMethods::TESWeather_GetColor(int aiRow, int aiColumn)
{
    return m_auiWeatherColors[aiRow][aiColumn];
}

typedef char _sizecheck_NiPoint2[sizeof(NiPoint2) == 8 ? 1 : -1];

float __cdecl BSShaderManager_GetTimer(bool);
float __cdecl NiCosQ(float);
float __cdecl NiSinQ(float);
void __cdecl BSShaderManager_SetWindDirection(int, int);
void __cdecl BSShaderManager_SetWindMagnitude(float);
void __cdecl ShadowLightShader_SetProjectedShadowTranslate(NiPoint2);
void __fastcall _ref_006815c0(NiPoint2*);

extern double _DAT_01012640;
extern double _DAT_0104eea0;
extern double DAT_0104ee98;
extern int DAT_011a9b50;
extern int DAT_011a9b54;


// @fnv 0x0063c490
// src: COMMUNITY 0x0063c490
void Sky::UpdateWind()
{
    float fperiod;
    float fscale;
    float fUpdatePeriod;
    // Raw storage avoids the shared default constructor call in this /Od function.
    float windPerturb[2];

    if (*reinterpret_cast<TESWeather**>(reinterpret_cast<char*>(this) + 0x10) != 0 &&
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xf8) == 3 ||
         *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xf8) == 2))
    {
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xcc) =
            (*reinterpret_cast<TESWeather**>(reinterpret_cast<char*>(this) + 0x10))->GetWeatherData(0, 1.0f, 0.0f);
        if (*reinterpret_cast<TESWeather**>(reinterpret_cast<char*>(this) + 0x14) != 0)
        {
            *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xcc) =
                *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xcc) *
                *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xf4);
            *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xcc) =
                (1.0f - *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xf4)) *
                    (*reinterpret_cast<TESWeather**>(reinterpret_cast<char*>(this) + 0x14))
                        ->GetWeatherData(0, 1.0f, 0.0f) +
                *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xcc);
        }
        BSShaderManager_SetWindDirection(DAT_011a9b50, DAT_011a9b54);
        BSShaderManager_SetWindMagnitude(*reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xcc));
        _ref_006815c0(reinterpret_cast<NiPoint2*>(windPerturb));
        fperiod = 15.0f;
        fscale = 15.0f;
        fUpdatePeriod = (BSShaderManager_GetTimer(false) / _DAT_01012640) * _DAT_0104eea0 * fperiod;
        windPerturb[0] = NiSinQ(fUpdatePeriod) * fscale;
        windPerturb[1] = NiCosQ(fUpdatePeriod * DAT_0104ee98) * fscale;
        ShadowLightShader_SetProjectedShadowTranslate(*reinterpret_cast<NiPoint2*>(windPerturb));
    }
}

extern float runtimeInitializationFloat2719;
extern float DAT_011f52e0[512];

// Scales arg by 512.0 divided by runtimeInitializationFloat2719, masks the index to 0x1ff, and returns DAT_011f52e0[idx].
// @fnv 0x0063c600
// src: COMMUNITY 0x0063c600
float __cdecl NiSinQ(float afValue)
{
    int idx = (int)((512.0 / runtimeInitializationFloat2719) * afValue) & 0x1ff;
    return DAT_011f52e0[idx];
    return 0.0f;
}

struct FUN_0063c8a0_shell : public NiPoint3
{
    NiPoint3* ComputeValue_0063c8a0(void*);
};

struct NiPoint3Fields
{
    float x;
    float y;
    float z;
};

// Adds the x, y and z components of pt to this NiPoint3 and returns this.
// @fnv 0x0063c8a0
// src: GUESS 0x0063c8a0 (confidence: low)
NiPoint3* FUN_0063c8a0_shell::ComputeValue_0063c8a0(void* apPoint)
{
    reinterpret_cast<NiPoint3Fields*>(this)->x += reinterpret_cast<const NiPoint3Fields*>(apPoint)->x;
    reinterpret_cast<NiPoint3Fields*>(this)->y += reinterpret_cast<const NiPoint3Fields*>(apPoint)->y;
    reinterpret_cast<NiPoint3Fields*>(this)->z += reinterpret_cast<const NiPoint3Fields*>(apPoint)->z;
    return this;
}


// @fnv 0x0063c9f0
// src: COMMUNITY 0x0063c9f0
void Sky::InvalidateCachedValues()
{
    flags |= 0x3f00;
}


// @fnv 0x0063d000
// src: COMMUNITY 0x0063d000
bool ClimateAccessMethods::TESClimate_UsesMasser()
{
    return (m_ucTimeSettings[5] & 0x80) != 0;
}


// @fnv 0x0063d020
// src: COMMUNITY 0x0063d020
bool ClimateAccessMethods::TESClimate_UsesSecunda()
{
    return (m_ucTimeSettings[5] & 0x40) != 0;
}


// @fnv 0x0063d060
// src: COMMUNITY 0x0063d060
void Sky::ResetWeather_0063d060()
{
    flags |= 1;
    m_pOverrideWeather = 0;
    m_pPreviousWeather = 0;
    m_pRegionWeather = 0;
    SetAcceleration(0);
    if (m_pClouds != 0)
    {
        m_pClouds->ClearCloudLayers();
    }
    if (m_pPrecipitation != 0)
    {
        m_pPrecipitation->FlushAll();
    }
    UpdateHDRValues();
}

void __fastcall TESWeatherList_GetRandomWeather(char*);

// @fnv 0x0063d5c0
// src: XBOX_PDB 0x0063d5c0
void __fastcall TESClimate_GetRandomWeather(char* p)
{
    TESWeatherList_GetRandomWeather(p + 0x30);
}


// @fnv 0x0063dd50
// src: XBOX_PDB 0x0063dd50
unsigned char WeatherAccessMethods::TESWeather_GetWeatherDataRaw(int index)
{
    return m_aucWeatherFlags[index];
}

namespace fnv_0063e010 {

BSSoundHandle* const& __fastcall _ref_006815c0(void* pNode);
void* __fastcall _ref_00726070(void* pNode);

// Iterates the linked list at pThis+0xfc and calls Stop on each node's referenced object.
// @fnv 0x0063e010
// src: COMMUNITY 0x0063e010
void __fastcall Sky_StopPlayingAllWeatherSounds(char* pThis)
{
    for (void* pNode = *reinterpret_cast<void**>(pThis + 0xfc); pNode && _ref_006815c0(pNode);
         pNode = _ref_00726070(pNode))
    {
        _ref_006815c0(pNode)->Stop();
    }
}
}  // namespace fnv_0063e010


void __fastcall Clouds_RemoveTextures(void*);
void __fastcall Moon_RemoveTextures(void*);
void __fastcall Sun_RemoveTextures(void*);
void __fastcall Stars_UnloadGeometry(void*);

// @fnv 0x0063e210
// src: COMMUNITY 0x0063e210
void Sky::UnloadAllTextures_0063e210()
{
    if (m_pClouds)
    {
        Clouds_RemoveTextures(m_pClouds);
        (m_pClouds)->ClearCloudLayers();
    }
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x30))
    {
        Moon_RemoveTextures(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x30));
    }
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x34))
    {
        Moon_RemoveTextures(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x34));
    }
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x28))
    {
        Sun_RemoveTextures(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x28));
    }
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x24))
    {
        Stars_UnloadGeometry(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x24));
    }
}

namespace fnv_0063e290 {
// @fnv 0x0063e290
// src: COMMUNITY 0x0063e290
void __fastcall Stars_UnloadGeometry(void* pThis)
{
    if ((const char*)*(BSStringT<char>*)((char*)pThis + 4) != 0)
    {
        ((NiNode*)(const char*)*(BSStringT<char>*)((char*)pThis + 4))
            ->RemoveObject((::NiAVObject*)(const char*)*(BSStringT<char>*)((char*)pThis + 8));
    }
    *(NiPointer<NiNode>*)((char*)pThis + 8) = 0;
}
}  // namespace fnv_0063e290

// Toggles flag bit 8 based on on and f14, and sets f110 to fF4 when enabling or 0.0f when disabling.
// @fnv 0x0063e860
// src: XBOX_PDB 0x0063e860
void Sky::SetAcceleration(bool abEnabled)
{
    if (abEnabled && m_pPreviousWeather && !(flags & 8))
    {
        flags |= 8;
        m_fValueBeforeSkyTextureManager = m_fWeatherBlend;
    }
    else if (!abEnabled || !m_pPreviousWeather)
    {
        flags &= ~8;
        m_fValueBeforeSkyTextureManager = 0.0f;
    }
}

namespace fnv_0063bab0 {

// Fills a four-int blend from the current and last weather's color lookup at two times, zeroing the last-weather entries when there is no last weather.
}  // namespace fnv_0063bab0

// @fnv 0x0063bab0
// src: XBOX_PDB 0x0063bab0
void Sky::FillColorBlendColors(void* aColorBlend, TESWeather* apCurrentWeather, TESWeather* apLastWeather,
                                      int aeColorType, int* aeTime1, int* aeTime2)
{
    using namespace fnv_0063bab0;
    if (!apCurrentWeather)
        return;
    ((int*)aColorBlend)[0] = ((WeatherAccessMethods*)apCurrentWeather)->TESWeather_GetColor(aeColorType, *aeTime1);
    ((int*)aColorBlend)[1] = ((WeatherAccessMethods*)apCurrentWeather)->TESWeather_GetColor(aeColorType, *aeTime2);
    if (apLastWeather)
    {
        ((int*)aColorBlend)[2] = ((WeatherAccessMethods*)apLastWeather)->TESWeather_GetColor(aeColorType, *aeTime1);
        ((int*)aColorBlend)[3] = ((WeatherAccessMethods*)apLastWeather)->TESWeather_GetColor(aeColorType, *aeTime2);
    }
    else
    {
        ((int*)aColorBlend)[3] = 0;
        ((int*)aColorBlend)[2] = 0;
    }
}


// @fnv 0x0063c420
// src: COMMUNITY 0x0063c420
float __thiscall WeatherAccessMethods::TESWeather_GetFogData(int index)
{
    return m_afFogDistances[index];
}

struct Flt
{
    operator unsigned int(void) const;
};


class CloudGeometryMethods : public Clouds
{
public:
    int Clouds_GetLayer(int);
};

// @fnv 0x0063c440
// src: COMMUNITY 0x0063c440
int CloudGeometryMethods::Clouds_GetLayer(int index)
{
    return ((Flt*)((char*)this + 8 + index * 4))->operator unsigned int();
}

extern unsigned char DAT_0119f188;

// @fnv 0x0063c460
// src: COMMUNITY 0x0063c460
unsigned char BGSTerrainManager_IsEnabled()
{
    return DAT_0119f188;
}

extern int DAT_011c7a3c;

// @fnv 0x0063c470
// src: COMMUNITY 0x0063c470
int __cdecl TESWaterSystem_GetCurrentWaterType()
{
    return DAT_011c7a3c;
}

extern "C"
{
    extern float DAT_011c7a5c;
}

// @fnv 0x0063c480
// src: COMMUNITY 0x0063c480
float TESWaterListener_GetWaterHeight()
{
    return DAT_011c7a5c;
}

extern int DAT_011f95dc;
extern int DAT_011f95e0;

// @fnv 0x0063c640
// src: COMMUNITY 0x0063c640
void __cdecl BSShaderManager_SetWindDirection(int aiFirst, int aiSecond)
{
    DAT_011f95dc = aiFirst;
    DAT_011f95e0 = aiSecond;
}

extern float DAT_011ad824;

// @fnv 0x0063c660
// src: COMMUNITY 0x0063c660
void BSShaderManager_SetWindMagnitude(float value)
{
    DAT_011ad824 = value;
}

extern "C" float DAT_011fd884;
extern "C" float DAT_011fd888;

// @fnv 0x0063c670
// src: COMMUNITY 0x0063c670
void ShadowLightShader_SetProjectedShadowTranslate(float afValue1, float afValue2)
{
    DAT_011fd884 = afValue1;
    DAT_011fd888 = afValue2;
}

struct FUN_0063dd90_shell
{
    unsigned char pad[0x18];
    unsigned int m_flags;
    void SkySound_FlagToKill();
};

// @fnv 0x0063dd90
// src: XBOX_PDB 0x0063dd90
void FUN_0063dd90_shell::SkySound_FlagToKill()
{
    m_flags = m_flags | 0x80000000;
}


// @fnv 0x0063dff0
// src: COMMUNITY 0x0063dff0
void* WeatherAccessMethods::TESWeather_GetSoundList()
{
    return &soundList;
}


class SkyOverrideMethods : public Sky
{
public:
    void Sky_SetFastTravel(bool);
};

// Sets or clears bit 0x10 in flags; when setting, also zeroes the dword at offset 0x1c.
// @fnv 0x0063e8f0
// src: XBOX_PDB 0x0063e8f0
void SkyOverrideMethods::Sky_SetFastTravel(bool set)
{
    if (set)
    {
        m_pOverrideWeather = 0;
        flags |= 0x10;
    }
    else
    {
        flags &= ~0x10;
    }
}

namespace fnv_0063b120 {

extern const float runtimeFloatSettingDefault40;
extern const float g_011cc6cc_arg1;
extern const float g_011c7200_arg1;
extern const float runtimeFloatSettingDefault538;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting75;
extern SettingT_GameSettingCollection_ g_011ccccc;
extern NiColor DAT_011f4998;

struct FUN_00544890_shell
{
    void GetDataDirectionalColor(NiColor*);
    void TESObjectCELL_GetDataAmbientColor(NiColor*);
    void GetDataFogColor(NiColor*);
};
struct CP_008c48d0
{
    FUN_00544890_shell* GetPrevPath();
};
extern CP_008c48d0* g_TES;


struct SkyCloudColorCallMethods : public Sky
{
    void QueryTwoSources(void*, TESWeather*, TESWeather*, int, int*, int*);
};

struct Sky_COLOR_BLEND
{
    int data[8];
};

// Initialises or blends the sky's colour fields based on the mode at offset 0xf8, copying defaults, path colours, or per-slot blended colours.
}  // namespace fnv_0063b120

// @fnv 0x0063b120
// src: XBOX_PDB 0x0063b120
void Sky::UpdateColors_0063b120()
{
    using namespace fnv_0063b120;
    if (eMode == 0)
    {
        reinterpret_cast<NiPoint3&>(m_kSkyColors[4]) =
            NiPoint3(g_011cc6cc_arg1, runtimeFloatSettingDefault40, runtimeFloatSettingDefault40);
        reinterpret_cast<NiPoint3&>(m_kSkyColors[3]) = NiPoint3(g_011c7200_arg1, g_011c7200_arg1, runtimeFloatSettingDefault538);
        if (m_pClouds)
        {
            for (int i = 0; i < m_pClouds->GetOffset58(); i++)
            {
                NiPoint3 Color(0.1f, 0.1f, 0.1f);
                static_cast<CloudColorMethods*>(m_pClouds)->Clouds_SetColor(i, (NiColor*)&Color);
            }
        }
        m_kSkyColors[7] = m_kSkyColors[1] = m_kSkyColors[0] =
            m_kSkyColors[5] = m_kSkyColors[8] = reinterpret_cast<NiColor&>(m_kSkyColor) =
                DAT_011f4998;
    }
    else if (eMode == 1 && g_TES && g_TES->GetPrevPath())
    {
        g_TES->GetPrevPath()->GetDataDirectionalColor(&m_kSkyColors[4]);
        g_TES->GetPrevPath()->TESObjectCELL_GetDataAmbientColor(&m_kSkyColors[3]);
        g_TES->GetPrevPath()->GetDataFogColor(&m_kSkyColors[1]);
        m_kSkyColors[7] = m_kSkyColors[0] = m_kSkyColors[5] =
            m_kSkyColors[8] = reinterpret_cast<NiColor&>(m_kSkyColor) = m_kSkyColors[1];
        if (m_pClouds)
        {
            for (int i = 0; i < m_pClouds->GetOffset58(); i++)
            {
                static_cast<CloudColorMethods*>(m_pClouds)->Clouds_SetColor(i, &m_kSkyColors[1]);
            }
        }
    }
    else
    {
        Sky_COLOR_BLEND cb;
        int aeTime2;
        int aeTime1;
        FillColorBlend(reinterpret_cast<SkyInterpolationData*>(&cb), m_pRegionWeather, m_fWeatherBlend, &aeTime1, &aeTime2);
        for (int i = 0; i < 10; i++)
        {
            FillColorBlendColors(&cb, m_pRegionWeather, m_pPreviousWeather, i, &aeTime1,
                               &aeTime2);
            float fCurrentFlash = 0;
            if (m_pPreviousWeather == 0)
            {
                if (i == 4)
                    fCurrentFlash = m_fWeatherFade * g_011ccccc.Float()->f;
                else if (i == 3)
                    fCurrentFlash = m_fWeatherFade * originalRuntimeFloatSetting75.Float()->f;
            }
            SetColor_0063c690(&m_kSkyColors[i], reinterpret_cast<SkyColorData*>(&cb), fCurrentFlash);
        }
        if (m_pClouds)
        {
            for (int i = 0; i < m_pClouds->GetOffset58(); i++)
            {
                static_cast<SkyCloudColorCallMethods*>(this)
                    ->QueryTwoSources(&cb, m_pRegionWeather, m_pPreviousWeather, i, &aeTime1,
                                      &aeTime2);
                float fCurrentFlash = 0;
                if (m_pPreviousWeather == 0 && i == 0)
                    fCurrentFlash = m_fWeatherFade;
                NiPoint3 kcolor(0, 0, 0);
                SetColor_0063c690(reinterpret_cast<NiColor*>(&kcolor), reinterpret_cast<SkyColorData*>(&cb), fCurrentFlash);
                static_cast<CloudColorMethods*>(m_pClouds)->Clouds_SetColor(i, (NiColor*)&kcolor);
            }
        }
        reinterpret_cast<NiColor&>(m_kSkyColor) = m_kSkyColors[4];
    }
}


unsigned int __cdecl FUN_0042f5a0(unsigned int, unsigned int);
unsigned int __cdecl gm_GetTickCount(void);
struct Host
{
    unsigned int SkySound_GetNextCheck();
    void SkySound_SetNextCheck(unsigned int);
    bool SkySound_HandleCheckTime(unsigned int);
};
// @fnv 0x00639c90
// src: XBOX_PDB 0x00639c90
bool Host::SkySound_HandleCheckTime(unsigned int auiDuration)
{
    unsigned int curTick;
    curTick = gm_GetTickCount();
    {
        unsigned int last;
        last = SkySound_GetNextCheck();
        if (curTick > FUN_0042f5a0(0x80000000, last))
        {
            SkySound_SetNextCheck(curTick + auiDuration);
            return true;
        }
        else
        {
            return false;
        }
    }
}

void __cdecl _Deallocate(void*);
struct SkyDeallocationMethods : public Sky
{
    void FUN_0063a0b0();
    void* FUN_0063a080(unsigned int);
};
// Calls FUN_0063a0b0, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0063a080
void* SkyDeallocationMethods::FUN_0063a080(unsigned int flags)
{
    FUN_0063a0b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_0063d0e0 {
extern "C" void* __cdecl _alloca(unsigned int);
// The approved PlayerCharacter header lacks this weather-notification method.
class PlayerSkyWeatherMethods : public PlayerCharacter
{
  public:
    void PlayerCharacter_SetOccupiedRegion(int);
};
extern PlayerCharacter* g_thePlayer;
}  // namespace fnv_0063d0e0

// @fnv 0x0063d0e0
// src: GUESS 0x0063d0e0 (confidence: low)
void Sky::UpdateFields_0063d0e0(TESWeather* apWeather, bool b)
{
    using namespace fnv_0063d0e0;
    if (b)
    {
        m_pOverrideWeather = apWeather;
        m_pRegionWeather = apWeather;
        m_pQueuedWeather = 0;
    }
    else
    {
        m_pQueuedWeather = apWeather;
        m_pRegionWeather = apWeather;
        m_pOverrideWeather = 0;
    }
    m_pPreviousWeather = 0;
    SetAcceleration(0);
    m_fWeatherBlend = 1.0f;
    fWeatherChance = m_fFogFarDistance;
    static_cast<PlayerSkyWeatherMethods*>(g_thePlayer)->PlayerCharacter_SetOccupiedRegion(0);
    flags |= 2;
    flags &= ~1;
    UpdateHDRValues();
    if (m_pClouds)
        m_pClouds->ClearCloudLayers();
    if (m_pPrecipitation)
        m_pPrecipitation->FlushAll();
}


struct FUN_0063dd70_shell
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    bool SkySound_IsFlaggedToBeKilled();
};
// @fnv 0x0063dd70
// src: COMMUNITY 0x0063dd70
bool FUN_0063dd70_shell::SkySound_IsFlaggedToBeKilled()
{
    return 0 < (m18 & 0x80000000);
}

// Returns a pointer to the item at index a1 if a1 is less than 2, otherwise returns null.
// @fnv 0x0063cfa0
// src: COMMUNITY 0x0063cfa0
void* ClimateAccessMethods::TESClimate_GetTexture(int aiIndex)
{
    return aiIndex < 2 ? (void*)&m_kSunTextures[aiIndex] : 0;
}

namespace fnv_0063ac70 {

struct Calendar
{
    float GetGameTime();
    unsigned int GetGameDaysPassed();
};

NiNode* __cdecl Main_GetWorldSceneGraph();
NiAVObject* __fastcall BSSceneGraph_GetCameraRoot(NiNode*);
const NiPoint3& __fastcall NiAVObject_GetWorldTranslate(NiAVObject*);
bool __cdecl FUN_006368f0(const Sky*);
extern PlayerCharacter* g_thePlayer;
extern Calendar g_calendar;
extern AnimIdle g_timeGlobal;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting74;

}  // namespace fnv_0063ac70

// @fnv 0x0063ac70
// src: XBOX_PDB 0x0063ac70
void Sky::Update_0063ac70(float afSecondsPassed)
{
    using namespace fnv_0063ac70;
    AutoMemHelper tempMemContext(0x21, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Sky.cpp",
                                 0x1d8);
    bool bnewPhase;

    if (!reinterpret_cast<const BSOcclusionPlane*>(g_thePlayer)->GetCullResult())
        return;

    m_fFogFarDistance = g_calendar.GetGameTime();

    if (g_thePlayer && reinterpret_cast<const BSOcclusionPlane*>(g_thePlayer)->GetCullResult() &&
        NiAVObject_GetWorldTranslate(BSSceneGraph_GetCameraRoot(Main_GetWorldSceneGraph())).z < ((MobileObject*)g_thePlayer)->GetRelevantWaterHeight())
        flags |= 4;
    else
        flags &= ~4;

    if (eMode == 1 && !g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
    {
        UpdateWeatherTransition(afSecondsPassed);
        return;
    }

    HandleClimateChange();
    if (g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
        flags |= 1;
    UpdateWeather_0063d1d0();
    UpdateColors();
    UpdateFog();
    UpdateWind();
    UpdateSound();

    if (m_pAtmosphere)
        m_pAtmosphere->Update(static_cast<Sky*>(this), afSecondsPassed);
    if (m_pStars)
        m_pStars->Update(static_cast<Sky*>(this), afSecondsPassed);
    if (m_pClouds)
        ((SkyObject*)m_pClouds)->Update(static_cast<Sky*>(this), afSecondsPassed);
    if (m_pSun)
        m_pSun->Update(static_cast<Sky*>(this), afSecondsPassed);

    if ((flags & 0x20) && m_uiSkyFourthValue < g_calendar.GetGameDaysPassed() ||
        g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
    {
        bnewPhase = FUN_006368f0(this);
        if (m_pPrimaryMoon && bnewPhase && static_cast<Moon*>(m_pPrimaryMoon)->m_eUpdateStatus == Moon::US_NOT_REQUIRED)
            static_cast<Moon*>(m_pPrimaryMoon)->m_eUpdateStatus =
                static_cast<Moon::UpdateStatus>((g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading() != 0) + 1);
        if (m_pSecondaryMoon && bnewPhase && static_cast<Moon*>(m_pSecondaryMoon)->m_eUpdateStatus == Moon::US_NOT_REQUIRED)
            static_cast<Moon*>(m_pSecondaryMoon)->m_eUpdateStatus =
                static_cast<Moon::UpdateStatus>((g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading() != 0) + 1);
        m_uiSkyFourthValue = g_calendar.GetGameDaysPassed();
    }

    if (m_pPrimaryMoon)
        m_pPrimaryMoon->Update(static_cast<Sky*>(this), afSecondsPassed);
    if (m_pSecondaryMoon)
        m_pSecondaryMoon->Update(static_cast<Sky*>(this), afSecondsPassed);
    if (m_pPrecipitation)
        m_pPrecipitation->Update(afSecondsPassed);

    if (m_fWeatherFade > 0.0)
        m_fWeatherFade =
            1.0 - (g_timeGlobal.GetSection() - SkySoundData) / (originalRuntimeFloatSetting74.Float()->f * 1000.0);
    if (m_fWeatherFade < 0.0)
        m_fWeatherFade = 0.0f;

    Renderer::SetBackgroundColor(m_kSkyColors[1]);
    flags &= ~3;
}


namespace fnv_0063d5e0 {
struct SkySound
{
    bool HandleCheckTime(int);
    bool IsFlaggedToBeKilled();
    unsigned int GetNextCheck();
    void FlagToKill();
    void SetNextCheck(unsigned int);
    void Play(float);
    void* __vecDelDtor(unsigned int);
    char IdentifierState[12];
    void* m_pWeatherObject;
    int m_iSoundType;
    unsigned int auiFormId;
    unsigned int uiData;
};
typedef char _sizecheck_SkySound[sizeof(SkySound) == 28 ? 1 : -1];

struct SkySoundObj
{
    BSSoundHandle hSound;
    TESWeather* m_pWeatherObject;
    unsigned int eType;
    unsigned int iSoundFormID;
    ~SkySoundObj();
    bool SkySound_IsFlaggedToBeKilled();
    bool SkySound_HandleCheckTime(int);
    void SkySound_FlagToKill();
    void SkySound_Play(float);
};
SkySoundObj** __fastcall SoundListItem(SL*);
SL* __fastcall NextSoundListNode(SL*);
struct SkyEx : public Sky
{
    void Sky_ActivateWeatherSounds(TESWeather*);
    bool Sky_FindSkySound(unsigned int, TESWeather*);
};

extern AnimIdle g_timeGlobal;
extern unsigned char DAT_011ccb74;
extern bool DAT_011ccd04;
unsigned int DialogueRandom();

}  // namespace fnv_0063d5e0

// @fnv 0x0063d5e0
// src: XBOX_PDB 0x0063d5e0
void Sky::UpdateSound()
{
    using namespace fnv_0063d5e0;
    fnv_0063d5e0::SkySoundObj* m_pkActiveSoundList;
    SL* pCurrentNode = (SL*)m_pSkySounds;
    if (DAT_011ccd04)
    {
        SL* pSaveList = new SL;
        fnv_0063d5e0::SkySoundObj* oldHandle;
        SL* poldHandleNode;
        SL oldHandleList;
        while (pCurrentNode && (m_pkActiveSoundList = *SoundListItem(pCurrentNode)))
        {
            if (m_pkActiveSoundList->SkySound_IsFlaggedToBeKilled())
            {
                if (m_pkActiveSoundList->eType == 3)
                    --DAT_011ccb74;
                m_pkActiveSoundList->hSound.Release();
                delete m_pkActiveSoundList;
            }
            else
            {
                pSaveList->AddHead(reinterpret_cast<::SkySoundObj**>(&m_pkActiveSoundList));
            }
            pCurrentNode = NextSoundListNode(pCurrentNode);
        }
        poldHandleNode = &oldHandleList;
        while (poldHandleNode && (oldHandle = *SoundListItem(poldHandleNode)))
        {
            poldHandleNode = NextSoundListNode(poldHandleNode);
            if (oldHandle->hSound.IsValid())
            {
                bool bstillInUse = false;
                pCurrentNode = pSaveList;
                while (!bstillInUse && pCurrentNode && (m_pkActiveSoundList = *SoundListItem(pCurrentNode)))
                {
                    if (m_pkActiveSoundList->iSoundFormID == oldHandle->iSoundFormID)
                        bstillInUse = true;
                    pCurrentNode = NextSoundListNode(pCurrentNode);
                }
                if (!bstillInUse)
                {
                    oldHandle->hSound.Release();
                    delete oldHandle;
                }
            }
            else
            {
                delete oldHandle;
            }
        }
        oldHandleList.RemoveAll();
        ((SL*)m_pSkySounds)->RemoveAll();
        delete (SL*)m_pSkySounds;
        *(SL**)&m_pSkySounds = pSaveList;
        pCurrentNode = pSaveList;
        DAT_011ccd04 = false;
    }
    if (((SkyEx*)this)->GetWeatherUpdateFlag())
        ((SkyEx*)this)->Sky_ActivateWeatherSounds(m_pRegionWeather);
    while (pCurrentNode && (m_pkActiveSoundList = *SoundListItem(pCurrentNode)))
    {
        if (!m_pkActiveSoundList->hSound.IsValid())
        {
            pCurrentNode = NextSoundListNode(pCurrentNode);
            continue;
        }
        if ((eMode == 3 || eMode == 2) && ((TESWeather*)m_pkActiveSoundList->m_pWeatherObject == m_pRegionWeather ||
                                           (TESWeather*)m_pkActiveSoundList->m_pWeatherObject == m_pPreviousWeather))
        {
            float fWeight;
            if (m_pkActiveSoundList->eType == 3)
            {
                if (!m_pkActiveSoundList->hSound.IsPlaying() && m_pkActiveSoundList->SkySound_HandleCheckTime(30) &&
                    DialogueRandom() % (m_pkActiveSoundList->m_pWeatherObject->GetWeatherDataRaw(10) * DAT_011ccb74) == 0)
                {
                    if ((TESWeather*)m_pkActiveSoundList->m_pWeatherObject == m_pRegionWeather)
                    {
                        float fBeginPct = ((TESWeather*)m_pRegionWeather)->GetWeatherData(8, 0.999f, 0.0f);
                        fWeight = m_fWeatherBlend < fBeginPct ? 0.0 : (m_fWeatherBlend - fBeginPct) / (1.0 - fBeginPct);
                    }
                    else
                    {
                        float fEndPct = ((TESWeather*)m_pPreviousWeather)->GetWeatherData(9, 1.0f, 0.001f);
                        fWeight = m_fWeatherBlend < fEndPct ? 1.0 - m_fWeatherBlend / fEndPct : 0.0;
                    }
                    if (fWeight != 0.0)
                    {
                        m_pkActiveSoundList->SkySound_Play(fWeight);
                        m_fWeatherFade = fWeight;
                        SkySoundData = g_timeGlobal.GetSection();
                    }
                }
            }
            else if (1)
            {
                float faltWeight;
                if (m_pkActiveSoundList->eType == 1)
                {
                    float fBeginPct = ((TESWeather*)m_pRegionWeather)->GetWeatherData(6, 0.999f, 0.0f);
                    float fEndPct = m_pPreviousWeather
                                        ? ((TESWeather*)m_pPreviousWeather)->GetWeatherData(7, 1.0f, 0.001f)
                                        : 0.0f;
                    if ((TESWeather*)m_pkActiveSoundList->m_pWeatherObject == m_pRegionWeather)
                    {
                        fWeight = m_fWeatherBlend < fBeginPct ? 0.0 : (m_fWeatherBlend - fBeginPct) / (1.0 - fBeginPct);
                        faltWeight = m_fWeatherBlend < fEndPct ? 1.0 - m_fWeatherBlend / fEndPct : 0.0;
                    }
                    else
                    {
                        fWeight = m_fWeatherBlend < fEndPct ? 1.0 - m_fWeatherBlend / fEndPct : 0.0;
                        faltWeight =
                            m_fWeatherBlend < fBeginPct ? 0.0 : (m_fWeatherBlend - fBeginPct) / (1.0 - fBeginPct);
                    }
                }
                else
                {
                    if ((TESWeather*)m_pkActiveSoundList->m_pWeatherObject == m_pRegionWeather)
                    {
                        fWeight = m_fWeatherBlend;
                        faltWeight = 1.0f - m_fWeatherBlend;
                    }
                    else
                    {
                        fWeight = 1.0f - m_fWeatherBlend;
                        faltWeight = m_fWeatherBlend;
                    }
                }
                if (!((SkyEx*)this)
                         ->Sky_FindSkySound(m_pkActiveSoundList->iSoundFormID,
                                        (TESWeather*)m_pkActiveSoundList->m_pWeatherObject == m_pRegionWeather
                                            ? m_pPreviousWeather
                                            : m_pRegionWeather) ||
                    fWeight >= faltWeight)
                    m_pkActiveSoundList->SkySound_Play(fWeight);
            }
        }
        else
        {
            if (m_pkActiveSoundList->hSound.IsPlaying() &&
                !((SkyEx*)this)
                     ->Sky_FindSkySound(m_pkActiveSoundList->iSoundFormID,
                                    (TESWeather*)m_pkActiveSoundList->m_pWeatherObject == m_pRegionWeather ? m_pPreviousWeather
                                                                                                   : m_pRegionWeather))
                m_pkActiveSoundList->hSound.Stop();
            m_pkActiveSoundList->SkySound_FlagToKill();
            DAT_011ccd04 = true;
        }
        pCurrentNode = NextSoundListNode(pCurrentNode);
    }
}


extern TESSaveLoadGame* g_TESSaveLoadGame;


class SkySaveSizeMethods : public Sky
{
public:
    unsigned short Sky_GetSaveSize();
};

// @fnv 0x0063e940
// src: COMMUNITY 0x0063e940
unsigned short SkySaveSizeMethods::Sky_GetSaveSize()
{
    unsigned short v = 0;
    v += 4;
    v += 4;
    v += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x5d)
        v += 4;
    v += 4;
    v += 4;
    v += 4;
    v += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x69)
    {
        v += 4;
        v += 4;
    }
    return v;
}


// @fnv 0x0063bc60
// src: COMMUNITY 0x0063bc60
int WeatherAccessMethods::TESWeather_GetCloudColor(int iIndex, int a)
{
    int color;
    if (a == 1)
        color = 0x9b9b9b;
    else if (a == 3)
        color = 0x1c140f;
    else if (a == 0)
        color = 0x5b4b46;
    else
        color = 0x6c5953;
    if (m_iCloudLayerCount > 0)
    {
        if (iIndex >= m_iCloudLayerCount)
            iIndex = 0;
        color = m_auiCloudLayerColors[iIndex][a];
    }
    return color;
}

namespace fnv_0063e9f0 {
// Unit-local view of TESSaveLoadGame for 0x0063e9f0 (namespace fnv_0063e9f0): built on the shared TESSaveLoadGame, that code does not compile or does not match.
class TESSaveLoadGame_0063e9f0
{
  public:
    void TESSaveLoadGame_SaveGameDataOLD(void*, int);
    void TESSaveLoadGame_SaveNumericID(int*, int);
};

class SaveManager : public TESSaveLoadGame_0063e9f0
{
  public:
    unsigned char FUN_008df040();
};

extern SaveManager* DAT_011de45c;


class SkyLegacySaveMethods : public Sky
{
public:
    void Sky_SaveGameTES();
};

// @fnv 0x0063e9f0
// src: COMMUNITY 0x0063e9f0
void SkyLegacySaveMethods::Sky_SaveGameTES()
{
    int formID = 0;
    if (m_pRegionWeather)
        formID = m_pRegionWeather->GetFormID();
    DAT_011de45c->TESSaveLoadGame_SaveNumericID(&formID, 4);

    int formID2 = 0;
    if (m_pPreviousWeather)
        formID2 = m_pPreviousWeather->GetFormID();
    DAT_011de45c->TESSaveLoadGame_SaveNumericID(&formID2, 4);

    int formID3 = 0;
    if (m_pQueuedWeather)
        formID3 = m_pQueuedWeather->GetFormID();
    DAT_011de45c->TESSaveLoadGame_SaveNumericID(&formID3, 4);

    if (DAT_011de45c->FUN_008df040() >= 0x5d)
    {
        int formID4 = 0;
        if (m_pOverrideWeather)
            formID4 = m_pOverrideWeather->GetFormID();
        DAT_011de45c->TESSaveLoadGame_SaveNumericID(&formID4, 4);
    }

    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&m_fFogFarDistance, 4);
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&fWeatherChance, 4);
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&m_fWeatherBlend, 4);
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&eMode, 4);

    if (DAT_011de45c->FUN_008df040() >= 0x69)
    {
        DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&flags, 4);
        DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&m_fValueBeforeSkyTextureManager, 4);
    }
}
}  // namespace fnv_0063e9f0

struct SaveFormIDHelper
{
    void SerializeFormData(void* data, int value);
};



class SkySaveMethods : public Sky
{
public:
    void Sky_SaveGameBGS(BGSSaveFormBuffer*);
};

// @fnv 0x0063eb70
// src: COMMUNITY 0x0063eb70
void SkySaveMethods::Sky_SaveGameBGS(BGSSaveFormBuffer* buffer)
{
    buffer->SerializeFormData(m_pRegionWeather, 0);
    buffer->SerializeFormData(m_pPreviousWeather, 0);
    buffer->SerializeFormData(m_pQueuedWeather, 0);
    buffer->SerializeFormData(m_pOverrideWeather, 0);

    buffer->SaveData(&m_fFogFarDistance, 4, 0);
    buffer->SaveData(&fWeatherChance, 4, 0);
    buffer->SaveData(&m_fWeatherBlend, 4, 0);
    buffer->SaveData(&flags, 4, 0);
    buffer->SaveData(&m_fValueBeforeSkyTextureManager, 4, 0);
    buffer->SaveData(&m_kSunlightColor.x, 4, 0);
    buffer->SaveData(&m_kSunlightColor.y, 4, 0);
    buffer->SaveData(&m_kSunlightColor.z, 4, 0);
    buffer->SaveData(&m_fFogNearDistance, 4, 0);
    buffer->SaveData(&m_fFogPower, 4, 0);
    buffer->SaveData(&eMode, 4, 0);
}

class ElemC_b9476
{
  public:
    int unk00;
};
class ElemB_b9476
{
  public:
    ElemC_b9476* Resolve();
};
class ElemA_b9476
{
  public:
    int unk00;
    int Test();
    void Clear(int);
    ElemB_b9476* Get(int);
};
class ResultX_b9476
{
  public:
    void SetFlag(int);
    void Scale(float);
};

void* LookupB9476(void*, void*);
extern char DAT_012005b8;


class CloudLayerResetMethods : public Clouds
{
public:
    void Clouds_ClearTransTextures();
};

// For each item, clears m_18[i], and if m_08[i] passes Test, looks up its resolved element and resets the result's flag and scale.
// @fnv 0x00634930
// src: XBOX_PDB 0x00634930
void CloudLayerResetMethods::Clouds_ClearTransTextures()
{
    for (int i = 0; i < GetOffset58(); i++)
    {
        reinterpret_cast<ElemA_b9476&>(m_pCloudLayerTexture[i]).Clear(0);
        if (reinterpret_cast<ElemA_b9476&>(m_pCloudLayerGeometry[i]).Test())
        {
            ElemC_b9476* c = reinterpret_cast<ElemA_b9476&>(m_pCloudLayerGeometry[i]).Get(3)->Resolve();
            ResultX_b9476* r = (ResultX_b9476*)LookupB9476((void*)&DAT_012005b8, c);
            if (r)
            {
                r->SetFlag(0);
                r->Scale(0.0f);
            }
        }
    }
}

class SkySound
{
  public:
    void* field00;
    void* field04;
    void* field08;
    unsigned int field0c;
    void* field10;
    void* field14;
};

SkySound** __fastcall FUN_006815c0(void* node);
void* __fastcall FUN_00726070(void* node);


class SkySoundQueryMethods : public Sky
{
public:
    bool Sky_FindSkySound(void*, unsigned int);
};

// @fnv 0x0063e060
// src: XBOX_PDB 0x0063e060
bool SkySoundQueryMethods::Sky_FindSkySound(void* m_pWeatherObject, unsigned int uiType)
{
    for (void* node = m_pSkySounds; node != 0 && *FUN_006815c0(node) != 0; node = FUN_00726070(node))
    {
        if ((*FUN_006815c0(node))->field14 == m_pWeatherObject && (*FUN_006815c0(node))->field0c == uiType)
            return true;
    }
    return false;
}

struct FogVector
{
    float x, y, z;
};
struct FogNode
{
    void FUN_00450f90(bool);
    const FogVector& NiAVObject_GetWorldTranslate();
};
struct FogRoot
{
    FogNode* Modelloader_GetReferencedThis();
};
struct FogCelestial
{
    FogNode* FUN_005585e0();
    FogNode* NiObjectNET_GetControllers();
};
struct FogClouds : public Clouds
{
    FogNode* Clouds_GetLayer(int);
};
struct FogWater
{
    float Animation_GetGlobalTimeMultiplier();
    float FUN_00507b20();
    int FUN_004f9bf0();
    int DialoguePackage_GetActorStartedConversation();
};
struct FogCell
{
    float TESObjectCELL_GetWaterHeight();
    float TESObjectCELL_GetFogFar();
    float TESObjectCELL_GetFogNear();
    float TESObjectCELL_GetFogPower();
};
struct FogPlayer
{
    FogCell* FUN_008d6f30();
};
struct FogEnvironment
{
    FogCell* FUN_005f36f0();
};

struct FogCamera
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
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual float GetFarPlane();
    FogNode* BSSceneGraph_GetCameraRoot();
};
struct FogBlend
{
    int colors[4];
    float weights[4];
};
class FogSkyMethods : public Sky
{
public:
    FogClouds* FUN_0055b980();
    FogCelestial* BGSSaveFormBuffer_GetForm();
    FogCelestial* FUN_0045cd60();
};

int TESWaterSystem_GetCurrentWaterType();
bool TESWaterSystem_GetPlayerUnderwater();
bool TESWaterListener_GetUnderwater();
FogCamera* Main_GetWorldSceneGraph();
float TESWaterListener_GetWaterHeight();
unsigned char BGSTerrainManager_IsEnabled();
float BSMIN(float, float);
extern FogPlayer* DAT_011dea3c;
extern FogEnvironment* DAT_011dea10;
extern float DAT_011ccc60;
extern Setting DAT_01203144;
extern const double DAT_01012070, DAT_01011588, DAT_01012060, DAT_0103a480, DAT_0104ee90;
extern const float DAT_010317c4;
// @fnv 0x0063bce0
// src: COMMUNITY 0x0063bce0
void Sky::UpdateFog()
{
    FogWater* water = (FogWater*)TESWaterSystem_GetCurrentWaterType();
    if (TESWaterSystem_GetPlayerUnderwater() || TESWaterListener_GetUnderwater())
    {
        float height = Main_GetWorldSceneGraph()->BSSceneGraph_GetCameraRoot()->NiAVObject_GetWorldTranslate().z;
        if (water && (TESWaterListener_GetUnderwater() || height < DAT_011dea3c->FUN_008d6f30()->TESObjectCELL_GetWaterHeight()))
        {
            m_fCloudLayerAlpha[0] = water->Animation_GetGlobalTimeMultiplier();
            m_fCloudLayerAlpha[1] = water->FUN_00507b20();
            m_fFogPower = 1.0f;
            float level8 = TESWaterListener_GetWaterHeight();
            if (height < DAT_011dea3c->FUN_008d6f30()->TESObjectCELL_GetWaterHeight())
                level8 = DAT_011dea3c->FUN_008d6f30()->TESObjectCELL_GetWaterHeight();
            float blend8 = (level8 - height) * DAT_011ccc60;
            if (blend8 > DAT_01012070)
                blend8 = 1.0f;
            FogBlend colors4;
            colors4.colors[0] = water->FUN_004f9bf0();
            colors4.colors[1] = water->DialoguePackage_GetActorStartedConversation();
            colors4.colors[2] = 0;
            colors4.colors[3] = 0;
            colors4.weights[0] = 1.0f - blend8;
            colors4.weights[1] = blend8;
            colors4.weights[2] = 0.0f;
            colors4.weights[3] = 0.0f;
            SetColor_0063c690(&m_kSkyColors[1], reinterpret_cast<SkyColorData*>(&colors4), 0.0f);
            if (eMode == 3 || eMode == 2)
            {
                bool hidden = blend8 > DAT_01011588;
                for (int i = 0; i < static_cast<FogSkyMethods*>(this)->FUN_0055b980()->GetOffset58(); ++i)
                    static_cast<FogSkyMethods*>(this)->FUN_0055b980()->Clouds_GetLayer(i)->FUN_00450f90(hidden);
                static_cast<FogSkyMethods*>(this)->BGSSaveFormBuffer_GetForm()->FUN_005585e0()->FUN_00450f90(hidden);
                static_cast<FogSkyMethods*>(this)->FUN_0045cd60()->FUN_005585e0()->FUN_00450f90(hidden);
                static_cast<FogSkyMethods*>(this)->FUN_0045cd60()->NiObjectNET_GetControllers()->FUN_00450f90(hidden);
                reinterpret_cast<FogRoot&>(m_pRootNode).Modelloader_GetReferencedThis()->FUN_00450f90(hidden);
            }
            return;
        }
    }
    if (static_cast<WeatherAccessMethods*>(m_pRegionWeather) && (eMode == 3 || eMode == 2))
    {
        float sunriseStart1411 = GetBeginSunriseColors();
        float sunriseEnd119 = Sky_GetSunriseEnd();
        float sunsetStart2312 = Sky_GetSunsetBegin();
        float sunsetEnd544 = GetEndSunsetColors();
        float day1270;
        if (m_fFogFarDistance > sunriseStart1411 && m_fFogFarDistance < sunriseEnd119)
            day1270 = (m_fFogFarDistance - sunriseStart1411) / (sunriseEnd119 - sunriseStart1411);
        else if (m_fFogFarDistance >= sunriseEnd119 && m_fFogFarDistance <= sunsetStart2312)
            day1270 = 1.0f;
        else if (m_fFogFarDistance > sunsetStart2312 && m_fFogFarDistance < sunsetEnd544)
            day1270 = (sunsetEnd544 - m_fFogFarDistance) / (sunsetEnd544 - sunsetStart2312);
        else
            day1270 = 0.0f;
        float night12 = 1.0f - day1270;
        m_fCloudLayerAlpha[0] = static_cast<WeatherAccessMethods*>(m_pRegionWeather)->TESWeather_GetFogData(0) * day1270 + static_cast<WeatherAccessMethods*>(m_pRegionWeather)->TESWeather_GetFogData(2) * night12;
        m_fCloudLayerAlpha[1] = static_cast<WeatherAccessMethods*>(m_pRegionWeather)->TESWeather_GetFogData(1) * day1270 + static_cast<WeatherAccessMethods*>(m_pRegionWeather)->TESWeather_GetFogData(3) * night12;
        m_fFogPower = static_cast<WeatherAccessMethods*>(m_pRegionWeather)->TESWeather_GetFogData(4) * day1270 + static_cast<WeatherAccessMethods*>(m_pRegionWeather)->TESWeather_GetFogData(5) * night12;
        if (static_cast<WeatherAccessMethods*>(m_pPreviousWeather))
        {
            m_fCloudLayerAlpha[0] *= m_fWeatherBlend;
            m_fCloudLayerAlpha[0] +=
                (1.0f - m_fWeatherBlend) * (static_cast<WeatherAccessMethods*>(m_pPreviousWeather)->TESWeather_GetFogData(0) * day1270 + static_cast<WeatherAccessMethods*>(m_pPreviousWeather)->TESWeather_GetFogData(2) * night12);
            m_fCloudLayerAlpha[1] *= m_fWeatherBlend;
            m_fCloudLayerAlpha[1] +=
                (1.0f - m_fWeatherBlend) * (static_cast<WeatherAccessMethods*>(m_pPreviousWeather)->TESWeather_GetFogData(1) * day1270 + static_cast<WeatherAccessMethods*>(m_pPreviousWeather)->TESWeather_GetFogData(3) * night12);
            m_fFogPower *= m_fWeatherBlend;
            m_fFogPower +=
                (1.0f - m_fWeatherBlend) * (static_cast<WeatherAccessMethods*>(m_pPreviousWeather)->TESWeather_GetFogData(4) * day1270 + static_cast<WeatherAccessMethods*>(m_pPreviousWeather)->TESWeather_GetFogData(5) * night12);
        }
    }
    else if (eMode == 1 && DAT_011dea10 && DAT_011dea10->FUN_005f36f0())
    {
        float farValue4 = DAT_011dea10->FUN_005f36f0()->TESObjectCELL_GetFogFar();
        if (farValue4 <= DAT_01012060 || farValue4 > DAT_0103a480)
            farValue4 = DAT_010317c4;
        float nearValue3 = DAT_011dea10->FUN_005f36f0()->TESObjectCELL_GetFogNear();
        if (nearValue3 <= DAT_01012060 || nearValue3 > farValue4)
            nearValue3 = farValue4 * DAT_0104ee90;
        m_fCloudLayerAlpha[0] = nearValue3;
        m_fCloudLayerAlpha[1] = farValue4;
        m_fFogPower = DAT_011dea10->FUN_005f36f0()->TESObjectCELL_GetFogPower();
    }
    else
    {
        m_fCloudLayerAlpha[0] = DAT_010317c4;
        m_fCloudLayerAlpha[1] = DAT_010317c4;
        m_fFogPower = 1.0f;
    }
    if (!BGSTerrainManager_IsEnabled())
    {
        float farPlane20 = Main_GetWorldSceneGraph()->GetFarPlane();
        float minimum3 = *DAT_01203144.Setting_Float_00403e20();
        float ratio2 = (m_fCloudLayerAlpha[1] - farPlane20) / (m_fCloudLayerAlpha[1] - minimum3);
        m_fCloudLayerAlpha[0] = m_fCloudLayerAlpha[0] - (m_fCloudLayerAlpha[0] - minimum3) * ratio2;
        m_fCloudLayerAlpha[1] = farPlane20;
        m_fCloudLayerAlpha[0] = BSMIN(farPlane20, m_fCloudLayerAlpha[0]);
    }
}

namespace SkyAssets {
struct Object;
struct Scene;
struct Texture;
struct Pointer
{
    Object* object;
    Pointer(int);
    ~Pointer();
    Object* Modelloader_GetReferencedThis();
};
struct Update
{
    unsigned int unk0, unk4, unk8;
    Update(float, int, int);
};
struct Object
{
    void UpdateProperties();
    void NiAVObject_Update(Update*);
};
struct ScenePointer
{
    Object* object;
    Object* Modelloader_GetReferencedThis();
};
struct Texture
{
    void FUN_006348e0(Object*);
};
struct Property
{
    Texture* FUN_00a59d30();
};
struct Visible
{
    void NiAVObject_SetDisplayObject(bool);
};
struct Cloud
{
    Property* bhkNiCollisionObject_GetWorldObject(int);
    Property* FUN_0063d040(int);
    Visible* FUN_005585e0();
    Visible* NiObjectNET_GetControllers();
};
struct Weather : public TESClimate
{
    const char* TESClimate_GetNightSkyModel();
    TESTexture* TESClimate_GetTexture(int);
    bool TESClimate_UsesMasser();
    bool TESClimate_UsesSecunda();
};
extern Setting DAT_011ccc18;
extern Setting DAT_011ccc54;
extern Setting DAT_011ccbfc;
extern Setting DAT_011ccba4;
extern Setting DAT_011ccc94;
extern Setting DAT_011cccb8;
extern Setting DAT_011cccec;
extern Setting DAT_011ccc7c;
extern Setting DAT_011ccbcc;
extern Setting DAT_011ccc64;
extern Setting DAT_011ccbe8;
extern Setting DAT_011ccb98;
extern bool DAT_011f941e;
extern char DAT_0102d7c4, DAT_0104eeb8, DAT_0104eeb0, DAT_0104eea8;
int BSstricmp(const char*, const char*);
void FUN_00b55840(const char*, int, Pointer*, int, int);
}  // namespace SkyAssets

// @fnv 0x0063ca20
// src: COMMUNITY 0x0063ca20
void Sky::HandleClimateChange()
{
    using namespace SkyAssets;
    if (flags & 0x40)
    {
        if (static_cast<Stars*>(m_pStars) && (eMode == 3 || eMode == 2))
            static_cast<Stars*>(m_pStars)->LoadGeometry(reinterpret_cast<SkyAssets::Weather*>(m_pCurrentClimate)->TESClimate_GetNightSkyModel());
        if (reinterpret_cast<Cloud*>(m_pSun) && (eMode == 3 || eMode == 2))
        {
            BSStringT<char> name;
            Texture* texture = reinterpret_cast<Cloud*>(m_pSun)->bhkNiCollisionObject_GetWorldObject(3)->FUN_00a59d30();
            Object* objectSlot0 = 0;
            TESTexture* modelSlot14 = reinterpret_cast<SkyAssets::Weather*>(m_pCurrentClimate)->TESClimate_GetTexture(0);
            if (modelSlot14 && modelSlot14->GetTextureNameLength())
            {
                Pointer pointer(0);
                name = modelSlot14->GetTextureResourcePath();
                name += modelSlot14->GetTextureResourceName();
                FUN_00b55840(name.String(), 1, &pointer, 1, 0);
                objectSlot0 = pointer.Modelloader_GetReferencedThis();
                if (objectSlot0)
                    texture->FUN_006348e0(objectSlot0);
            }
            reinterpret_cast<Cloud*>(m_pSun)->FUN_005585e0()->NiAVObject_SetDisplayObject(objectSlot0 != 0);
            texture = reinterpret_cast<Cloud*>(m_pSun)->FUN_0063d040(3)->FUN_00a59d30();
            modelSlot14 = reinterpret_cast<SkyAssets::Weather*>(m_pCurrentClimate)->TESClimate_GetTexture(1);
            if (modelSlot14 && modelSlot14->GetTextureNameLength())
            {
                if (!DAT_011f941e && !BSstricmp(modelSlot14->GetTextureResourceName(), &DAT_0102d7c4))
                    name = &DAT_0104eeb8;
                else
                {
                    name = modelSlot14->GetTextureResourcePath();
                    name += modelSlot14->GetTextureResourceName();
                }
                Pointer pointer2(0);
                FUN_00b55840(name.String(), 1, &pointer2, 1, 0);
                objectSlot0 = pointer2.Modelloader_GetReferencedThis();
                if (objectSlot0)
                    texture->FUN_006348e0(objectSlot0);
            }
            reinterpret_cast<Cloud*>(m_pSun)->NiObjectNET_GetControllers()->NiAVObject_SetDisplayObject(objectSlot0 != 0);
        }
        if (reinterpret_cast<SkyAssets::Weather*>(m_pCurrentClimate)->TESClimate_UsesMasser() && !reinterpret_cast<Moon*&>(m_pPrimaryMoon))
        {
            reinterpret_cast<Moon*&>(m_pPrimaryMoon) = new Moon(&DAT_0104eeb0, *DAT_011cccb8.Setting_Float_00403e20(), *DAT_011ccc94.Setting_Float_00403e20(),
                                *DAT_011ccba4.Setting_Float_00403e20(), *DAT_011ccbfc.Setting_Float_00403e20(),
                                *DAT_011ccc54.Setting_Float_00403e20(), *DAT_011ccc18.Setting_Int());
            reinterpret_cast<Moon*&>(m_pPrimaryMoon)->Initialize(reinterpret_cast<NiNode*>(reinterpret_cast<ScenePointer&>(m_pSkyNode).Modelloader_GetReferencedThis()), &DAT_0104eeb0);
        }
        else if (!reinterpret_cast<SkyAssets::Weather*>(m_pCurrentClimate)->TESClimate_UsesMasser())
        {
            delete reinterpret_cast<Moon*&>(m_pPrimaryMoon);
            reinterpret_cast<Moon*&>(m_pPrimaryMoon) = 0;
        }
        if (reinterpret_cast<SkyAssets::Weather*>(m_pCurrentClimate)->TESClimate_UsesSecunda() && !reinterpret_cast<Moon*&>(m_pSecondaryMoon))
        {
            reinterpret_cast<Moon*&>(m_pSecondaryMoon) = new Moon(&DAT_0104eea8, *DAT_011ccb98.Setting_Float_00403e20(), *DAT_011ccbe8.Setting_Float_00403e20(),
                                *DAT_011ccc64.Setting_Float_00403e20(), *DAT_011ccbcc.Setting_Float_00403e20(),
                                *DAT_011ccc7c.Setting_Float_00403e20(), *DAT_011cccec.Setting_Int());
            reinterpret_cast<Moon*&>(m_pSecondaryMoon)->Initialize(reinterpret_cast<NiNode*>(reinterpret_cast<ScenePointer&>(m_pSkyNode).Modelloader_GetReferencedThis()), &DAT_0104eea8);
        }
        else if (!reinterpret_cast<SkyAssets::Weather*>(m_pCurrentClimate)->TESClimate_UsesSecunda())
        {
            delete reinterpret_cast<Moon*&>(m_pSecondaryMoon);
            reinterpret_cast<Moon*&>(m_pSecondaryMoon) = 0;
        }
        reinterpret_cast<ScenePointer&>(m_pRootNode).Modelloader_GetReferencedThis()->UpdateProperties();
        SkyAssets::Update update(0.0f, 0, 0);
        reinterpret_cast<ScenePointer&>(m_pRootNode).Modelloader_GetReferencedThis()->NiAVObject_Update(&update);
        flags &= ~0x40;
    }
}


bool Interface_IsInMenuMode();
bool FUN_00705ea0();
BSAudio* BSAudio_QInstance();

struct std
{
    static float __cdecl abs(float afValue);
};
struct FUN_0063e0d0_shell
{
    char pad[0x10];
    int iState;
    void SkySound_Play(float afVolume);
};
// @fnv 0x0063e0d0
// src: XBOX_PDB 0x0063e0d0
void FUN_0063e0d0_shell::SkySound_Play(float afVolume)
{
    if (!Interface_IsInMenuMode() && !FUN_00705ea0())
    {
        if (!((BSSoundHandle*)this)->IsValid())
        {
            const char* pName = *(BSStringT<char>*)this;
            BSSoundHandle kSound = ((SkyAudio*)BSAudio_QInstance())->GetSoundHandleByFormID(reinterpret_cast<unsigned int>(pName), 0x20u);
            *(BSSoundHandle*)this = kSound;
        }
        if (iState == 3)
        {
            if (!((BSSoundHandle*)this)->IsPlaying())
                ((BSSoundHandle*)this)->Play(false);
        }
        else if (((Host*)this)->SkySound_HandleCheckTime(1000))
        {
            if (!((BSSoundHandle*)this)->IsPlaying())
                ((BSSoundHandle*)this)->Play(true);
        }
        if (std::abs(((BSSoundHandle*)this)->GetVolume() - afVolume) > (double)0.01f)
            ((BSSoundHandle*)this)->SetVolume(afVolume);
    }
}

class Texture139;
class Property139
{
  public:
    void FUN_006348e0(Texture139*);
};
class Node139
{
  public:
    Property139* FUN_00a59d30(unsigned int);
    void NiAVObject_SetDisplayObject(bool);
};
// The shared Sun layout is sufficient; retain these undeclared accessors as
// free ECX helpers rather than another local copy of the class.
Node139* __fastcall SunFirstObject(Sun*);
Node139* __fastcall SunSecondObject(Sun*);
Node139* __fastcall SunThirdObject(Sun*);
Node139* __fastcall SunFourthObject(Sun*);
// 0x0063cfa0 returns a sun TESTexture; 0x0048cee0/0x00408da0 read its name length/text.
class Climate139 : public TESClimate
{
  public:
    TESTexture* TESClimate_GetTexture(int);
    const char* TESClimate_GetNightSkyModel();
};
int __cdecl FUN_00456a20(const char*, char*, unsigned int, unsigned int);
void __cdecl FUN_00b55840(const char*, bool, NiPointer<Texture139>&, bool, bool);
int __cdecl BSstricmp(const char*, const char*);
extern unsigned char DAT_011f941e;
struct SkyTextureRefreshMethods : public Sky
{
    void Sky_ReloadAllTextures();
};
// @fnv 0x0063e2f0
// src: COMMUNITY 0x0063e2f0
void SkyTextureRefreshMethods::Sky_ReloadAllTextures()
{
    AutoMemContext mem(MEM_CONTEXT_MEM_CONTEXT_SKY, true,
                       "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Sky.cpp", 2268);
    if (m_pClouds && m_pRegionWeather && !g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
    {
        for (int i = 0; i < m_pClouds->GetOffset58(); i++)
        {
            if (m_pRegionWeather->GetCloudTexture(i) &&
                m_pRegionWeather->GetCloudTexture(i)->GetTextureNameLength())
            {
                BSStringT<char> path;
                path.PrintfString("%s%s", m_pRegionWeather->GetCloudTexture(i)->GetTextureResourcePath(),
                             m_pRegionWeather->GetCloudTexture(i)->GetTextureResourceName());
                if (FUN_00456a20(path.String(), 0, 0, -1) && reinterpret_cast<Node139*>(static_cast<CloudGeometryMethods*>(m_pClouds)->Clouds_GetLayer(i))->FUN_00a59d30(5))
                {
                    NiPointer<Texture139> texture(0);
                    FUN_00b55840(path.String(), true, texture, true, false);
                    reinterpret_cast<Node139*>(static_cast<CloudGeometryMethods*>(m_pClouds)->Clouds_GetLayer(i))->FUN_00a59d30(3)->FUN_006348e0(texture);
                }
            }
        }
    }
    if (m_pPrimaryMoon)
    {
        Property139* ptr = reinterpret_cast<Property139*>(static_cast<Moon*>(m_pPrimaryMoon)->m_pMoonShadowShape->GetProperty(3));
        NiPointer<Texture139> prop(0);
        FUN_00b55840("Textures\\Sky\\MoonShadow.dds", true, prop, true, false);
        Texture139* tex = prop;
        if (tex)
            ptr->FUN_006348e0(tex);
        static_cast<Moon*>(m_pPrimaryMoon)->m_pMoonShadowShape->NiAVObject_SetDisplayObject(tex != 0);
        static_cast<Moon*>(m_pPrimaryMoon)->m_eUpdateStatus = Moon::US_INITIALIZE;
    }
    if (m_pSecondaryMoon)
    {
        Property139* ptr = reinterpret_cast<Property139*>(static_cast<Moon*>(m_pSecondaryMoon)->m_pMoonShadowShape->GetProperty(3));
        NiPointer<Texture139> prop(0);
        FUN_00b55840("Textures\\Sky\\MoonShadow.dds", true, prop, true, false);
        Texture139* tex = prop;
        if (tex)
            ptr->FUN_006348e0(tex);
        static_cast<Moon*>(m_pSecondaryMoon)->m_pMoonShadowShape->NiAVObject_SetDisplayObject(tex != 0);
        static_cast<Moon*>(m_pSecondaryMoon)->m_eUpdateStatus = Moon::US_INITIALIZE;
    }
    if (m_pSun && m_pCurrentClimate)
    {
        BSStringT<char> path;
        Property139* ptr = SunFirstObject((Sun*)m_pSun)->FUN_00a59d30(3);
        Texture139* tex = 0;
        NiPointer<Texture139> prop(0);
        TESTexture* model = ((Climate139*)m_pCurrentClimate)->TESClimate_GetTexture(0);
        if (model && model->GetTextureNameLength())
        {
            path = model->GetTextureResourcePath();
            path += model->GetTextureResourceName();
            FUN_00b55840(path.String(), true, prop, true, false);
            tex = prop;
            if (tex)
                ptr->FUN_006348e0(tex);
        }
        SunSecondObject((Sun*)m_pSun)->NiAVObject_SetDisplayObject(tex != 0);
        ptr = SunThirdObject((Sun*)m_pSun)->FUN_00a59d30(3);
        model = ((Climate139*)m_pCurrentClimate)->TESClimate_GetTexture(0);
        if (model && model->GetTextureNameLength())
        {
            if (!DAT_011f941e && !BSstricmp(model->GetTextureResourceName(), "Sky\\SunGlare.dds"))
                path = "Textures\\Sky\\SunGlareNonHDR.dds";
            else
            {
                path = model->GetTextureResourcePath();
                path += model->GetTextureResourceName();
            }
            NiPointer<Texture139> glare(0);
            FUN_00b55840(path.String(), true, glare, true, false);
            tex = glare;
            if (tex)
                ptr->FUN_006348e0(tex);
        }
        SunFourthObject((Sun*)m_pSun)->NiAVObject_SetDisplayObject(tex != 0);
    }
    if (m_pStars && m_pCurrentClimate)
        static_cast<Stars*>(m_pStars)->LoadGeometry(((Climate139*)m_pCurrentClimate)->TESClimate_GetNightSkyModel());
}

namespace fnv_0063ef20 {

struct GlobalObject_00633c90
{
    GlobalObject_00633c90(int v);
    ~GlobalObject_00633c90();
    int m_ptr;
};

struct ListX
{
    void BSSimpleList_NiPointer_bhkAction_AddHead(const GlobalObject_00633c90&);
};
struct TESX
{
    ListX* FUN_0043b5d0();
};
extern TESX* DAT_011dea10;

struct WeatherSub
{
    void* TESImageSpaceModifiableCountForm_6_GetFormImageSpaceModifying(int);
};

void* __cdecl FUN_00532ff0();
float __fastcall Sky_GetSunriseEnd(Sky*);
float __fastcall Sky_GetSunsetBegin(Sky*);
void __cdecl FNV_Warning(const char*, ...);
extern char DAT_0104ee38;

}  // namespace fnv_0063ef20

// @fnv 0x0063ef20
// src: XBOX_PDB 0x0063ef20
void Sky::UpdateHDRValues_0063ef20()
{
    using namespace fnv_0063ef20;
    float tmp;
    float y;
    unsigned long which5;
    float val;
    float tB;
    {
        float pct3;
        void* _res;
        int dVal;
        {
            float s;
            bool p;
            float idx;
            float q;
            float d3_2;
            float mid3;
            float pForm;
            if (m_pFirstImageSpaceModifierInstance == 0)
            {
                m_pFirstImageSpaceModifierInstance = reinterpret_cast<ImageSpaceModifierInstanceForm*>(new ImageSpaceModifierInstanceDOF);
                m_pLastWeatherImageSpaceModifier = reinterpret_cast<ImageSpaceModifierInstanceForm*>(new ImageSpaceModifierInstanceDOF);
                fnv_0063ef20::DAT_011dea10->FUN_0043b5d0()->BSSimpleList_NiPointer_bhkAction_AddHead((int)m_pLastWeatherImageSpaceModifier);
                fnv_0063ef20::DAT_011dea10->FUN_0043b5d0()->BSSimpleList_NiPointer_bhkAction_AddHead((int)m_pFirstImageSpaceModifierInstance);
                m_pSecondImageSpaceModifierInstance = reinterpret_cast<ImageSpaceModifierInstanceForm*>(new ImageSpaceModifierInstanceDOF);
                m_pLastWeatherImageSpaceModifier2 = reinterpret_cast<ImageSpaceModifierInstanceForm*>(new ImageSpaceModifierInstanceDOF);
                fnv_0063ef20::DAT_011dea10->FUN_0043b5d0()->BSSimpleList_NiPointer_bhkAction_AddHead((int)m_pLastWeatherImageSpaceModifier2);
                fnv_0063ef20::DAT_011dea10->FUN_0043b5d0()->BSSimpleList_NiPointer_bhkAction_AddHead((int)m_pSecondImageSpaceModifierInstance);
                ((ImageSpaceModifierInstanceDOF*)m_pFirstImageSpaceModifierInstance)->ImageSpaceModifierInstance_SetPermanent(true);
                ((ImageSpaceModifierInstanceDOF*)m_pLastWeatherImageSpaceModifier)->ImageSpaceModifierInstance_SetPermanent(true);
                ((ImageSpaceModifierInstanceDOF*)m_pSecondImageSpaceModifierInstance)->ImageSpaceModifierInstance_SetPermanent(true);
                ((ImageSpaceModifierInstanceDOF*)m_pLastWeatherImageSpaceModifier2)->ImageSpaceModifierInstance_SetPermanent(true);
                ((ImageSpaceModifierInstanceDOF*)m_pFirstImageSpaceModifierInstance)->m_bHasBeenApplied = 1;
                ((ImageSpaceModifierInstanceDOF*)m_pLastWeatherImageSpaceModifier)->m_bHasBeenApplied = 1;
                ((ImageSpaceModifierInstanceDOF*)m_pSecondImageSpaceModifierInstance)->m_bHasBeenApplied = 1;
                ((ImageSpaceModifierInstanceDOF*)m_pLastWeatherImageSpaceModifier2)->m_bHasBeenApplied = 1;
            }
            if (eMode == 1 || eMode == 0)
            {
                ((ImageSpaceModifierInstanceDOF*)m_pFirstImageSpaceModifierInstance)->FUN_0063f790(0.0f);
                ((ImageSpaceModifierInstanceDOF*)m_pSecondImageSpaceModifierInstance)->FUN_0063f790(0.0f);
                ((ImageSpaceModifierInstanceDOF*)m_pLastWeatherImageSpaceModifier)->FUN_0063f790(0.0f);
                ((ImageSpaceModifierInstanceDOF*)m_pLastWeatherImageSpaceModifier2)->FUN_0063f790(0.0f);
            }
            else
            {
                which5 = 0;
                p = false;
                tmp = 1.0f;
                val = GetBeginSunriseColors();
                tB = fnv_0063ef20::Sky_GetSunriseEnd(this);
                y = fnv_0063ef20::Sky_GetSunsetBegin(this);
                pct3 = GetEndSunsetColors();
                if (m_fFogFarDistance > val && m_fFogFarDistance < tB)
                {
                    p = true;
                    dVal = 0;
                    idx = (tB - val) * 0.5;
                    s = val + idx;
                    if (m_fFogFarDistance < s)
                    {
                        tmp = 1.0f - (s - m_fFogFarDistance) / idx;
                        which5 = 3;
                    }
                    else
                    {
                        tmp = 1.0f - (m_fFogFarDistance - s) / idx;
                        which5 = 1;
                    }
                }
                else if (m_fFogFarDistance > tB && m_fFogFarDistance < SkyEnvironmentController)
                {
                    p = true;
                    dVal = 1;
                    which5 = 4;
                    q = SkyEnvironmentController - tB;
                    tmp = 1.0f - (SkyEnvironmentController - m_fFogFarDistance) / q;
                }
                else if (SkyEnvironmentController < m_fFogFarDistance && m_fFogFarDistance < y)
                {
                    p = true;
                    dVal = 4;
                    which5 = 1;
                    pForm = y - SkyEnvironmentController;
                    tmp = 1.0f - (y - m_fFogFarDistance) / pForm;
                }
                else if (m_fFogFarDistance > y && m_fFogFarDistance < pct3)
                {
                    p = true;
                    dVal = 2;
                    d3_2 = (pct3 - y) * 0.5;
                    mid3 = y + d3_2;
                    if (m_fFogFarDistance < mid3)
                    {
                        tmp = 1.0f - (mid3 - m_fFogFarDistance) / d3_2;
                        which5 = 1;
                    }
                    else
                    {
                        tmp = 1.0f - (m_fFogFarDistance - mid3) / d3_2;
                        which5 = 3;
                    }
                }
                else
                {
                    if (m_fFogFarDistance >= pct3 || m_fFogFarDistance <= val)
                    {
                        dVal = 3;
                    }
                    else
                    {
                        FNV_Warning(
                            "MASTERFILE: Data error detected--Transition times stored in climate data are invalid.");
                        dVal = 1;
                    }
                }
                _res = 0;
                if (0 != m_pRegionWeather)
                {
                    _res = reinterpret_cast<WeatherSub*>(reinterpret_cast<char*>(m_pRegionWeather) + sizeof(TESForm))->TESImageSpaceModifiableCountForm_6_GetFormImageSpaceModifying(dVal);
                }
                if (!_res)
                {
                    _res = FUN_00532ff0();
                }
                if (!!_res)
                {
                    ((ImageSpaceModifierInstanceDOF*)m_pFirstImageSpaceModifierInstance)->FUN_0063f790(m_fWeatherBlend * tmp);
                    ((ImageSpaceModifierInstanceDOF*)m_pFirstImageSpaceModifierInstance)->FUN_0050f9a0(_res);
                }
                if (p)
                {
                    _res = 0;
                    if (0 != m_pRegionWeather)
                    {
                        _res = reinterpret_cast<WeatherSub*>(reinterpret_cast<char*>(m_pRegionWeather) + sizeof(TESForm))->TESImageSpaceModifiableCountForm_6_GetFormImageSpaceModifying(which5);
                    }
                    if (_res == 0)
                    {
                        _res = FUN_00532ff0();
                    }
                    if (0 != _res)
                    {
                        ((ImageSpaceModifierInstanceDOF*)m_pSecondImageSpaceModifierInstance)->FUN_0063f790((1.0f - tmp) * m_fWeatherBlend);
                        ((ImageSpaceModifierInstanceDOF*)m_pSecondImageSpaceModifierInstance)->FUN_0050f9a0(_res);
                    }
                }
                else
                {
                    ((ImageSpaceModifierInstanceDOF*)m_pSecondImageSpaceModifierInstance)->FUN_0063f790(0.0f);
                }
                if (m_pPreviousWeather != 0 && m_fWeatherBlend < 1.0)
                {
                    _res = 0;
                    _res = reinterpret_cast<WeatherSub*>(reinterpret_cast<char*>(m_pPreviousWeather) + sizeof(TESForm))->TESImageSpaceModifiableCountForm_6_GetFormImageSpaceModifying(dVal);
                    if (0 == _res)
                    {
                        _res = FUN_00532ff0();
                    }
                    if (0 != _res)
                    {
                        ((ImageSpaceModifierInstanceDOF*)m_pLastWeatherImageSpaceModifier)->FUN_0063f790((1.0f - m_fWeatherBlend) * tmp);
                        ((ImageSpaceModifierInstanceDOF*)m_pLastWeatherImageSpaceModifier)->FUN_0050f9a0(_res);
                    }
                    if (p)
                    {
                        _res = 0;
                        _res = reinterpret_cast<WeatherSub*>(reinterpret_cast<char*>(m_pPreviousWeather) + sizeof(TESForm))->TESImageSpaceModifiableCountForm_6_GetFormImageSpaceModifying(which5);
                        if (_res == 0)
                        {
                            _res = FUN_00532ff0();
                        }
                        if (!!_res)
                        {
                            ((ImageSpaceModifierInstanceDOF*)m_pLastWeatherImageSpaceModifier2)
                                ->FUN_0063f790((1.0f - m_fWeatherBlend) * (1.0f - tmp));
                            ((ImageSpaceModifierInstanceDOF*)m_pLastWeatherImageSpaceModifier2)->FUN_0050f9a0(_res);
                        }
                    }
                    else
                    {
                        ((ImageSpaceModifierInstanceDOF*)m_pLastWeatherImageSpaceModifier2)->FUN_0063f790(0.0f);
                    }
                }
                else
                {
                    ((ImageSpaceModifierInstanceDOF*)m_pLastWeatherImageSpaceModifier)->FUN_0063f790(0.0f);
                    ((ImageSpaceModifierInstanceDOF*)m_pLastWeatherImageSpaceModifier2)->FUN_0063f790(0.0f);
                }
            }
        }
    }
}


extern Setting g_011ccb8c;
extern unsigned char DAT_011ccb74;

BSAudio* __cdecl BSAudio_QInstance();

struct Entry
{
    int m00;
    int m04;
};

struct ParamObj : public TESWeather
{
    BSSimpleList<Entry*>* TESWeather_GetSoundList();
};

struct NodeObj
{
    BSSoundHandle m_handle;
    ParamObj* m0c;
    int m10;
    int m14;
    int m18;
    NodeObj(BSSoundHandle, ParamObj*, int, int);
};

struct NodeList
{
    NodeObj*& GetItem();
    NodeList* GetNext();
    void AddHead(NodeObj* const& item);
};

class SkySoundCreationMethods : public Sky
{
public:
    void Sky_ActivateWeatherSounds(ParamObj*);
};

// @fnv 0x0063ddb0
// src: COMMUNITY 0x0063ddb0
void SkySoundCreationMethods::Sky_ActivateWeatherSounds(ParamObj* pParamObj)
{
    if (!pParamObj)
        return;

    Entry* pItem_2;
    BSSimpleList<Entry*>* iter1 = pParamObj->TESWeather_GetSoundList();
    while (iter1 && (pItem_2 = iter1->GetItem()))
    {
        BSSoundHandle sound;
        int flags7;
        if (*g_011ccb8c.Bool() || pItem_2->m04 != 1)
        {
            flags7 = 0x21;
            if (pItem_2->m04 != 3)
                flags7 |= 0x10;
            sound = ((SkyAudio*)BSAudio_QInstance())->GetSoundHandleByFormID(pItem_2->m00, flags7);
        }

        bool found2 = false;
        NodeObj* node6;
        for (NodeList* iter7 = reinterpret_cast<NodeList*&>(m_pSkySounds); !found2 && iter7 && (node6 = iter7->GetItem()); iter7 = iter7->GetNext())
        {
            found2 = (node6->m14 == pItem_2->m00 && node6->m0c == pParamObj && node6->m10 == pItem_2->m04);
        }
        if (!found2)
        {
            reinterpret_cast<NodeList*&>(m_pSkySounds)->AddHead(new NodeObj(sound, pParamObj, pItem_2->m04, pItem_2->m00));
            if (pItem_2->m04 == 3)
                DAT_011ccb74++;
        }
        else
        {
            sound.Release();
        }
        iter1 = iter1->GetNext();
    }
}

struct SkyInterpolationData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float weight1;
    float weight2;
    float weight3;
    float weight4;
};


void FNV_Warning(const char*);


// @fnv 0x0063b630
// src: XBOX_PDB 0x0063b630
void Sky::FillColorBlend(SkyInterpolationData* pData, TESWeather* m_pWeatherObject, float fPct, int* pPhase,
                             int* pNextPhase)
{
    if (!m_pWeatherObject)
        return;

    float _fSunset;
    float fDayX;
    float fSunrise4;
    float fNight3;
    float midSunriseDay8;
    float halfSunriseDay2;
    float spanDayMid_2;
    float spanMidSunset3;
    float midSunsetNight4;
    float halfSunsetNight5;

    fSunrise4 = GetBeginSunriseColors();
    fDayX = Sky_GetSunriseEnd();
    _fSunset = Sky_GetSunsetBegin();
    fNight3 = GetEndSunsetColors();

    if (m_fFogFarDistance > fSunrise4 && m_fFogFarDistance < fDayX)
    {
        *pPhase = 0;
        halfSunriseDay2 = (fDayX - fSunrise4) * 0.5;
        midSunriseDay8 = fSunrise4 + halfSunriseDay2;
        if (m_fFogFarDistance < midSunriseDay8)
        {
            pData->weight1 = 1.0f - (midSunriseDay8 - m_fFogFarDistance) / halfSunriseDay2;
            *pNextPhase = 3;
        }
        else
        {
            pData->weight1 = 1.0f - (m_fFogFarDistance - midSunriseDay8) / halfSunriseDay2;
            *pNextPhase = 1;
        }
    }
    else if (m_fFogFarDistance >= fDayX && m_fFogFarDistance <= SkyEnvironmentController)
    {
        *pNextPhase = 1;
        *pPhase = 4;
        spanDayMid_2 = SkyEnvironmentController - fDayX;
        pData->weight1 = 1.0f - (SkyEnvironmentController - m_fFogFarDistance) / spanDayMid_2;
    }
    else if (SkyEnvironmentController <= m_fFogFarDistance && m_fFogFarDistance <= _fSunset)
    {
        *pNextPhase = 4;
        *pPhase = 1;
        spanMidSunset3 = _fSunset - SkyEnvironmentController;
        pData->weight1 = 1.0f - (_fSunset - m_fFogFarDistance) / spanMidSunset3;
    }
    else if (m_fFogFarDistance > _fSunset && m_fFogFarDistance < fNight3)
    {
        *pPhase = 2;
        halfSunsetNight5 = (fNight3 - _fSunset) * 0.5;
        midSunsetNight4 = _fSunset + halfSunsetNight5;
        if (m_fFogFarDistance < midSunsetNight4)
        {
            pData->weight1 = 1.0f - (midSunsetNight4 - m_fFogFarDistance) / halfSunsetNight5;
            *pNextPhase = 1;
        }
        else
        {
            pData->weight1 = 1.0f - (m_fFogFarDistance - midSunsetNight4) / halfSunsetNight5;
            *pNextPhase = 3;
        }
    }
    else if (m_fFogFarDistance >= fNight3 || m_fFogFarDistance <= fSunrise4)
    {
        *pNextPhase = 3;
        *pPhase = 3;
        pData->weight1 = 1.0f;
    }
    else
    {
        FNV_Warning("MASTERFILE: Data error detected--Transition times stored in climate data are invalid.");
        *pNextPhase = 1;
        *pPhase = 1;
        pData->weight1 = 1.0f;
    }

    pData->weight2 = 1.0f - pData->weight1;
    pData->weight3 = pData->weight1;
    pData->weight4 = pData->weight2;
    pData->weight1 = pData->weight1 * m_fWeatherBlend;
    pData->weight2 = pData->weight2 * m_fWeatherBlend;
    pData->weight3 = (1.0f - m_fWeatherBlend) * pData->weight3;
    pData->weight4 = (1.0f - m_fWeatherBlend) * pData->weight4;
}


struct SetHelper
{
    float x, y, z;
    NiPoint3* Set(float a, float b, float c);
};

union CU
{
    unsigned int u;
    unsigned short w;
};

struct SkyColorData
{
    CU c[4];
    float f[4];
};


struct Sh63c8a0
{
    void* ComputeValue_0063c8a0(NiPoint3* p);
};

struct ShA69690
{
    void NiColor_Clamp();
};

float __cdecl BSMIN(float a, float b);
void __cdecl BSClamp_float(float* p, float lo, float hi);


// @fnv 0x0063c690
// src: XBOX_PDB 0x0063c690
void Sky::SetColor_0063c690(NiColor* apOutRgb, SkyColorData* pSkyColorData, float t)
{
    float r = 0.0f;
    for (int i = 0; i < 4; i++)
        r += (float)(unsigned char)(pSkyColorData->c[i].u & 0xff) * pSkyColorData->f[i];
    reinterpret_cast<float*>(apOutRgb)[0] = r * (1.0f / 255.0f);
    r = 0.0f;
    for (int i = 0; i < 4; i++)
        r += (float)(unsigned char)((pSkyColorData->c[i].w >> 8) & 0xff) * pSkyColorData->f[i];
    reinterpret_cast<float*>(apOutRgb)[1] = r * (1.0f / 255.0f);
    r = 0.0f;
    for (int i = 0; i < 4; i++)
        r += (float)(unsigned char)((pSkyColorData->c[i].u >> 16) & 0xff) * pSkyColorData->f[i];
    reinterpret_cast<float*>(apOutRgb)[2] = r * (1.0f / 255.0f);
    t = BSMIN(1.0f, t);
    if (t > 0.0)
    {
        SetHelper sh;
        ((Sh63c8a0*)reinterpret_cast<float*>(apOutRgb))->ComputeValue_0063c8a0(sh.Set(t, t, t));
        if (m_pRegionWeather)
        {
            BSClamp_float(reinterpret_cast<float*>(apOutRgb), 0.0f, m_pRegionWeather->GetWeatherData(0xc, 1.0f, 0.0f));
            BSClamp_float(reinterpret_cast<float*>(apOutRgb) + 1, 0.0f, m_pRegionWeather->GetWeatherData(0xd, 1.0f, 0.0f));
            BSClamp_float(reinterpret_cast<float*>(apOutRgb) + 2, 0.0f, m_pRegionWeather->GetWeatherData(0xe, 1.0f, 0.0f));
            return;
        }
    }
    ((ShA69690*)reinterpret_cast<float*>(apOutRgb))->NiColor_Clamp();
}

class WeatherRegion
{
  public:
    void FUN_004f1050();
};

class WeatherDataHandler : public TESDataHandler
{
  public:
    TESRegionList* TESDataHandler_GetRegionList();
};
extern WeatherDataHandler* g_dataHandler;
class WeatherCell
{
  public:
    TESWeather* FUN_0059bb30();
};

extern PlayerCharacter* g_thePlayer;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting71;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting72;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting73;
TESForm* TESForm_GetFormByNumericID(unsigned int);

// Selects the current weather from the climate, cell or override, updates transition state and fade, and refreshes HDR values.
// @fnv 0x0063d1d0
// src: XBOX_PDB 0x0063d1d0
void Sky::UpdateWeather_0063d1d0()
{
    if (!m_pCurrentClimate)
        return;
    if ((flags & 1) || !m_pQueuedWeather ||
        ((m_fFogFarDistance + (m_fFogFarDistance < fWeatherChance ? 24 : 0) - fWeatherChance) >
             1.0 + (255 - static_cast<ClimateAccessMethods*>(m_pCurrentClimate)->TESClimate_GetVolatilityIndex()) * 22 * (1.0f / 255.0f) &&
         !m_pPreviousWeather))
    {
        m_pQueuedWeather = static_cast<ClimateAccessMethods*>(m_pCurrentClimate)->TESClimate_GetRandomWeather();
        if (!m_pQueuedWeather)
            m_pQueuedWeather = dynamic_cast<TESWeather*>(TESForm_GetFormByNumericID(0x15e));
        BSSimpleList<TESRegion*>* region = g_dataHandler->TESDataHandler_GetRegionList();
        while (region && region->GetItem())
        {
            ((WeatherRegion*)region->GetItem())->FUN_004f1050();
            region = region->GetNext();
        }
    }
    bool useDefault = m_pOverrideWeather == 0;
    if (m_pRegionWeather && g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
        useDefault = false;
    TESWeather* p = 0;
    if (useDefault)
    {
        p = m_pQueuedWeather;
        WeatherCell* cell = g_thePlayer->PlayerCharacter_GetCurrentRegion();
        if (cell && cell->FUN_0059bb30() && eMode != 2)
            p = cell->FUN_0059bb30();
    }
    else
    {
        p = m_pOverrideWeather;
    }
    if (p && (!m_pPreviousWeather || (flags & 0x10)) && p != m_pRegionWeather)
    {
        if ((flags & 0x10) || eMode == 1)
        {
            m_pPreviousWeather = 0;
            if (m_pPrecipitation)
                m_pPrecipitation->FlushAll();
        }
        else
        {
            m_pPreviousWeather = m_pRegionWeather;
        }
        m_pRegionWeather = p;
        if (!g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
            fWeatherChance = m_fFogFarDistance;
        flags |= 1;
    }
    else
    {
        flags &= ~1;
    }
    if (!m_pRegionWeather)
    {
        m_fWeatherBlend = 0.0f;
    }
    else if (!m_pPreviousWeather)
    {
        m_fWeatherBlend = 1.0f;
    }
    else
    {
        m_fWeatherBlend =
            (m_fFogFarDistance + (m_fFogFarDistance < fWeatherChance ? 24 : 0) - fWeatherChance) /
            m_pRegionWeather
                ->GetWeatherData(3, *originalRuntimeFloatSetting71.Float(), *originalRuntimeFloatSetting72.Float());
    }
    if (flags & 8)
        m_fWeatherBlend = (m_fWeatherBlend - m_fValueBeforeSkyTextureManager) * (1.0 + *originalRuntimeFloatSetting73.Float()) + m_fValueBeforeSkyTextureManager;
    if (m_fWeatherBlend > 1.0)
    {
        m_pPreviousWeather = 0;
        m_fWeatherBlend = 1.0f;
        SetAcceleration(false);
    }
    UpdateHDRValues();
}

namespace fnv_0063a630 {

extern Setting g_011ccb8c;
extern unsigned char DAT_011f426c;
extern bool DAT_011F941E;
extern float DAT_011ad87c, DAT_011ad880;
// These two out-of-line flag setters are not declared by include/NiNode.h.
// Extend its API here without repeating the scene-node layout or virtual table.
// The allocation overloads retain sized exception cleanup: the inherited
// unsized delete otherwise changes the exception tails for 0x0063a630.
class SkySceneNodeMethods : public NiNode
{
  public:
    SkySceneNodeMethods(unsigned short);
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void BSMultiBoundNode_SetCullingMode(bool);
    void NiAVObject_SetSelectiveUpdate(bool);
};
class SkyRootNode : public SkySceneNodeMethods
{
  public:
    int mac, mb0;
    SkyRootNode();
};
// Clouds.h has no out-of-line constructor declaration.
class CloudAllocation : public Clouds
{
public:
    CloudAllocation();
};

// This initialization path calls the sky precipitation constructor at 0x00636a40
// and its setup operation, which is absent from Precipitation.h.
class PrecipitationSetupMethods : public Precipitation
{
public:
    PrecipitationSetupMethods();
    void FUN_00636bb0();
};


struct RootPointer
{
    NiNode* p;
    bool FUN_0052aa80(int) const;
    NiNode* operator->() const;
    operator NiNode*() const;
    RootPointer& operator=(NiNode*);
};
class SkyInitializationMethods : public Sky
{
public:
    void Sky_Initialize(NiNode*, int);
};

// @fnv 0x0063a630
// src: COMMUNITY 0x0063a630
void SkyInitializationMethods::Sky_Initialize(NiNode* apRootNode, int arg)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_SKY, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Sky.cpp", 0x152);
    if (((const RootPointer&)reinterpret_cast<NiPointer<NiNode>&>(m_pRootNode)).FUN_0052aa80(0))
    {
        if (reinterpret_cast<NiPointer<NiNode>&>(m_pRootNode)->GetParent())
            reinterpret_cast<NiPointer<NiNode>&>(m_pRootNode)->GetParent()->RemoveObject((NiNode*)reinterpret_cast<NiPointer<NiNode>&>(m_pRootNode));
        reinterpret_cast<NiPointer<NiNode>&>(m_pRootNode) = 0;
    }
    if (apRootNode)
        reinterpret_cast<NiPointer<NiNode>&>(m_pRootNode) = apRootNode;
    else
    {
        reinterpret_cast<NiPointer<NiNode>&>(m_pRootNode) = new SkyRootNode;
        static_cast<SkySceneNodeMethods*>(reinterpret_cast<NiPointer<NiNode>&>(m_pRootNode).operator->())->BSMultiBoundNode_SetCullingMode(true);
        static_cast<SkySceneNodeMethods*>(reinterpret_cast<NiPointer<NiNode>&>(m_pRootNode).operator->())->NiAVObject_SetSelectiveUpdate(true);
    }
    reinterpret_cast<NiPointer<NiNode>&>(m_pRootNode)->NiAVObject_SetTranslate(reinterpret_cast<NiPoint3*>(&DAT_011f426c));
    if (reinterpret_cast<Atmosphere*&>(m_pAtmosphere))
        delete reinterpret_cast<Atmosphere*&>(m_pAtmosphere);
    reinterpret_cast<Atmosphere*&>(m_pAtmosphere) = new Atmosphere;
    reinterpret_cast<Atmosphere*&>(m_pAtmosphere)->Init2(reinterpret_cast<NiPointer<NiNode>&>(m_pRootNode), arg);
    if (reinterpret_cast<Stars*&>(m_pStars))
        delete reinterpret_cast<Stars*&>(m_pStars);
    reinterpret_cast<Stars*&>(m_pStars) = new Stars;
    reinterpret_cast<Stars*&>(m_pStars)->Initialize(reinterpret_cast<NiPointer<NiNode>&>(m_pRootNode));
    if (reinterpret_cast<Sun*&>(m_pSun))
        delete reinterpret_cast<Sun*&>(m_pSun);
    reinterpret_cast<Sun*&>(m_pSun) = new Sun;
    reinterpret_cast<Sun*&>(m_pSun)->Initialize(reinterpret_cast<NiPointer<NiNode>&>(m_pRootNode));
    reinterpret_cast<NiPointer<NiNode>&>(m_pSkyNode) = new SkySceneNodeMethods(0);
    reinterpret_cast<NiPointer<NiNode>&>(m_pRootNode)->AttachChildInAvailableSlot(static_cast<NiAVObject*>((NiNode*)reinterpret_cast<NiPointer<NiNode>&>(m_pSkyNode)), true);
    if (m_pPrecipitation)
        // The shared DestroyIfFlagged entry occupies the scalar-deleting slot.
        // A delete expression retains the original null check and call sequence.
        delete reinterpret_cast<SkyObject*>(m_pPrecipitation);
    if (*g_011ccb8c.Bool())
    {
        static_cast<PrecipitationSetupMethods*>(m_pPrecipitation = new PrecipitationSetupMethods)->FUN_00636bb0();
    }
    else
        m_pPrecipitation = 0;
    if (m_pClouds)
        delete m_pClouds;
    m_pClouds = new CloudAllocation;
    m_pClouds->Initialize(reinterpret_cast<NiPointer<NiNode>&>(m_pRootNode));
    {
        NiPointer<NiAlphaProperty> alpha = new NiAlphaProperty;
        alpha->NiAlphaProperty_SetSrcBlendMode(6);
        alpha->NiAlphaProperty_SetDestBlendMode(7);
        alpha->NiAlphaProperty_SetAlphaBlending(true);
        alpha->NiAlphaProperty_SetNoSorter(true);
        reinterpret_cast<NiPointer<NiNode>&>(m_pRootNode)->NiAVObject_AttachProperty((NiAlphaProperty*)alpha);
        alpha = 0;
    }
    if (DAT_011F941E)
    {
        DAT_011ad87c = 1.0f;
        DAT_011ad880 = 1.0f;
    }
    reinterpret_cast<NiPointer<NiNode>&>(m_pRootNode)->UpdateProperties();
}
}  // namespace fnv_0063a630

struct FUN_0063bb70_value
{
    int value;
};

struct FUN_0063bb70_result
{
    int value0;
    int value1;
    int value2;
    int value3;
};

struct SkyCloudColorQueryMethods : public Sky
{
    void QueryTwoSources(FUN_0063bb70_result* result, WeatherAccessMethods* first, WeatherAccessMethods* second, int value,
                         FUN_0063bb70_value* source1, FUN_0063bb70_value* source2);
};

// Calls the first object with both source values and optionally the second, then fills zero results from corresponding second-object results.
// @fnv 0x0063bb70
void SkyCloudColorQueryMethods::QueryTwoSources(FUN_0063bb70_result* result, WeatherAccessMethods* first,
                                         WeatherAccessMethods* second, int value, FUN_0063bb70_value* source1,
                                         FUN_0063bb70_value* source2)
{
    if (first == 0)
        return;

    result->value0 = first->TESWeather_GetCloudColor(value, source1->value);
    result->value1 = first->TESWeather_GetCloudColor(value, source2->value);

    if (second != 0)
    {
        result->value2 = second->TESWeather_GetCloudColor(value, source1->value);
        result->value3 = second->TESWeather_GetCloudColor(value, source2->value);

        if (result->value0 == 0)
            result->value0 = result->value2;

        if (result->value1 == 0)
            result->value1 = result->value3;

        if (result->value2 == 0)
            result->value2 = result->value0;

        if (result->value3 == 0)
            result->value3 = result->value1;
    }
    else
    {
        result->value3 = 0;
        result->value2 = 0;
    }
}
