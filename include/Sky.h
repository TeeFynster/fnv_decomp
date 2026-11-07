#pragma once

#ifndef FNV_LAYOUT_SUPPORT_H
#include "NiAVObject.h"
#endif
#include "NiColor.h"
#include "SkyTextureManager.h"
#ifndef FNV_NIPOINT3_H
#include "NiPoint3.h"
#endif

class BGSLoadGameBuffer;
class Clouds;
class ImageSpaceModifierInstanceForm;
class NiAVObject;
class Precipitation;
class SkyColorData;
class SkyInterpolationData;
class SkyObject;
class SkySound;
class TES;
class TESClimate;
class TESWeather;
template <class T> class BSSimpleList;


class Sky
{
public:
    enum SKY_MODE
    {
        SM_NONE = 0,
        SM_INTERIOR = 1,
        SM_FAKEEXTERIOR = 2,
        SM_FULL = 3,
        SM_COUNT = 4,
    };

    virtual ~Sky();

    NiPointer<NiAVObject> m_pRootNode;
    NiPointer<NiAVObject> m_pSkyNode;
    TESClimate* m_pCurrentClimate;
    TESWeather* m_pRegionWeather;
    TESWeather* m_pPreviousWeather;
    TESWeather* m_pQueuedWeather;
    TESWeather* m_pOverrideWeather;
    SkyObject* m_pAtmosphere;
    SkyObject* m_pStars;
    SkyObject* m_pSun;
    Clouds* m_pClouds;
    SkyObject* m_pPrimaryMoon;
    SkyObject* m_pSecondaryMoon;
    Precipitation* m_pPrecipitation;
    NiColor m_kSkyColors[10];
    NiPoint3 m_kSunlightColor;
    NiPoint3 m_kSkyColor;
    float m_fCurrentWeatherBlend;
    float m_fTargetWeatherBlend;
    float m_fCloudLayerAlpha[4];
    float m_fFogNearDistance;
    float m_fFogPower;
    float m_fFogFarDistance;
    float fWeatherChance;
    float m_fWeatherBlend;
    unsigned int eMode;
    BSSimpleList<SkySound*>* m_pSkySounds;
    float m_fWeatherFade;
    union { unsigned int SkySoundData; unsigned int field104; };
    union { unsigned int m_uiSkyFourthValue; unsigned int field108; };
    union { float SkyTextureState; float field10c; };
    union { float m_fValueBeforeSkyTextureManager; float field110; };
    union
    {
        unsigned int field114;
        struct
        {
            SkyTextureManager SkyController;
            unsigned char unk115[3];
        };
    };
    union { unsigned int uiFlags; unsigned int flags; };
    union { ImageSpaceModifierInstanceForm* m_pFirstImageSpaceModifierInstance; void* field11c; };
    union { ImageSpaceModifierInstanceForm* m_pSecondImageSpaceModifierInstance; void* field120; };
    union { ImageSpaceModifierInstanceForm* m_pLastWeatherImageSpaceModifier; void* field124; };
    union { ImageSpaceModifierInstanceForm* m_pLastWeatherImageSpaceModifier2; void* field128; };
    union { float SkyEnvironmentController; float field12c; };
    union { float SkyImageSpaceTransitionData; float field130; };
    union { float SkyImageSpaceBlendData; float field134; };


    // Compatibility view for the pathing receiver returned by TES::GetLogDate.
    // This interface does not add slots or storage to Sky.
    struct PathingReceiver
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
        virtual void v64();
        virtual void v65();
        virtual void v66();
        virtual void v67();
        virtual void v68();
        virtual void v69();
        virtual void v70();
        virtual void v71();
        virtual void v72();
        virtual void v73();
        virtual void v74();
        virtual void v75();
        virtual void v76();
        virtual void v77();
        virtual void v78();
        virtual void v79();
        virtual void v80();
        virtual void v81();
        virtual void v82();
        virtual void v83();
        virtual void v84();
        virtual void v85();
        virtual void v86();
        virtual void v87();
        virtual void v88();
        virtual void v89();
        virtual void v90();
        virtual void v91();
        virtual void v92();
        virtual void v93();
        virtual void v94();
        virtual void v95();
        virtual void v96();
        virtual void v97();
        virtual void v98();
        virtual void v99();
        virtual void v100();
        virtual void v101();
        virtual void v102();
        virtual void v103();
        virtual void v104();
        virtual void v105();
        virtual void v106();
        virtual void v107();
        virtual void v108();
        virtual void v109();
        virtual void v110();
        virtual void v111();
        virtual void v112();
        virtual void v113();
        virtual void v114();
        virtual void v115();
        virtual void v116();
        virtual void v117();
        virtual void v118();
        virtual void v119();
        virtual void v120();
        virtual void v121();
        virtual void v122();
        virtual void v123();
        virtual void v124();
        virtual void v125();
        virtual void v126();
        virtual void v127();
        virtual void v128();
        virtual void v129();
        virtual void v130();
        virtual void v131();
        virtual void v132();
        virtual void v133();
        virtual void v134();
        virtual void v135();
        virtual void v136();
        virtual void v137();
        virtual void v138();
        virtual void v139();
        virtual void v140();
        virtual void v141();
        virtual void v142();
        virtual void v143();
        virtual void v144();
        virtual void v145();
        virtual void v146();
        virtual void v147();
        virtual void v148();
        virtual void* vcall(TES*);
    };

    __forceinline void* vcall(TES* receiver)
    {
        return reinterpret_cast<PathingReceiver*>(this)->vcall(receiver);
    }

    Sky();
    static Sky* __cdecl GetInstance();
    static Sky* pInstance;

    unsigned int Deallocate();
    bool IsRaining();
    void LoadGame(BGSLoadGameBuffer*);
    void Update(float);
    void UpdateHDRValues();
    void SetCurrentClimate(TESClimate*, bool);
    void ResetWeather();
    void UpdateColors();
    void UpdateWeatherTransition(float);
    TESWeather* GetAudioBackendData();
    float GetFieldEC();
    float GetFieldCC();
    void SetMode(Sky::SKY_MODE);
    void LoadAllTextures();
    void UnloadAllTextures();
    SkyTextureManager* GetTextureManager();
    unsigned int GetTime() const;
    bool IsFlag4Set();

    void UpdateMoonPhase(bool);
    void Update_0063ac70(float);
    void UpdateColors_0063b120();
    float GetBeginSunriseColors();
    float GetEndSunsetColors();
    void FillColorBlend(SkyInterpolationData*, TESWeather*, float, int*, int*);
    void FillColorBlendColors(void*, TESWeather*, TESWeather*, int, int*, int*);
    void UpdateWind();
    void ResetWeather_0063d060();
    void UpdateFields_0063d0e0(TESWeather*, bool);
    void UpdateWeather_0063d1d0();
    void UpdateSound();
    void UnloadAllTextures_0063e210();
    void SetAcceleration(int);
    void SetAcceleration(bool);
    void UpdateHDRValues_0063ef20();
    float Sky_GetSunriseEnd();
    float Sky_GetSunsetBegin();
    void FillColorBlend(SkyColorData*, TESWeather*, float, float*, int*);
    void FillColorBlendColors(SkyColorData*, TESWeather*, int, int, float*, int*);
    void UpdateFog();
    void SetColor_0063c690(NiColor*, SkyColorData*, float);
    void InvalidateCachedValues();
    void HandleClimateChange();
    TESWeather* TESMain_GetThread();
    TESWeather* FUN_00825c00();
    int Sky_GetMode();
    float Sky_GetCurrentWeatherPct();
    float Sky_GetFlash();
    bool GetWeatherUpdateFlag();
};
