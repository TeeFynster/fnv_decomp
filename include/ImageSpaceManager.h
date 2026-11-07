#pragma once

#include <stddef.h>

#include "NiBound.h"
#include "NiPoint2.h"
#include "NiColorA.h"

#define ISM_EFFECT_TYPE(suffix) ImageSpace##Effect##suffix
#define ISM_EFFECT_ENUM ImageSpaceManager__ImageSpace##EffectEnum
#define ISM_EFFECT_VALUE(suffix) ImageSpaceManager__ImageSpace##EffectEnum_##suffix
#define ISM_ADD_EFFECT Add##Effect
#define ISM_NESTED_EFFECT_ENUM ImageSpace##EffectEnum

class BSRenderedTexture;
class GraphicsRenderer;
class ISM_EFFECT_TYPE();
class ISM_EFFECT_TYPE(Param);
class ImageSpaceParameterData;
class ImageSpaceTexture;
class NiScreenElements;
class NiRenderer;
class NiTexture;
class RenderTexture;

enum ISM_EFFECT_ENUM
{
    ISM_EFFECT_VALUE(EFFECT_REFRACTION) = 0,
    ISM_EFFECT_VALUE(EFFECT_BLOOM) = 1,
    ISM_EFFECT_VALUE(EFFECT_HDR) = 2,
    ISM_EFFECT_VALUE(EFFECT_CINEMATIC) = 3,
    ISM_EFFECT_VALUE(EFFECT_DEPTH_OF_FIELD) = 4,
    ISM_EFFECT_VALUE(EFFECT_DEPTH_RADIAL_BLUR) = 5,
    ISM_EFFECT_VALUE(EFFECT_RADIAL_BLUR) = 6,
    ISM_EFFECT_VALUE(EFFECT_FULLSCREEN_BLUR) = 7,
    ISM_EFFECT_VALUE(EFFECT_GETHIT) = 8,
    ISM_EFFECT_VALUE(EFFECT_SUNBEAMS) = 9,
    ISM_EFFECT_VALUE(EFFECT_INTERFACE) = 10,
    ISM_EFFECT_VALUE(EFFECT_VATS_SCAN) = 11,
    ISM_EFFECT_VALUE(EFFECT_MOTION_BLUR) = 12,
    ISM_EFFECT_VALUE(EFFECT_ENDOFFRAME_END) = 13,
    ISM_EFFECT_VALUE(EFFECT_VOLUMETRIC_FOG) = 13,
    ISM_EFFECT_VALUE(EFFECT_MAP) = 14,
    ISM_EFFECT_VALUE(EFFECT_MENUBG) = 15,
    ISM_EFFECT_VALUE(EFFECT_BLUR_START) = 16,
    ISM_EFFECT_VALUE(EFFECT_BLUR3) = 16,
    ISM_EFFECT_VALUE(EFFECT_BLUR5) = 17,
    ISM_EFFECT_VALUE(EFFECT_BLUR7) = 18,
    ISM_EFFECT_VALUE(EFFECT_BLUR9) = 19,
    ISM_EFFECT_VALUE(EFFECT_BLUR11) = 20,
    ISM_EFFECT_VALUE(EFFECT_BLUR13) = 21,
    ISM_EFFECT_VALUE(EFFECT_BLUR15) = 22,
    ISM_EFFECT_VALUE(EFFECT_BLUR_END) = 22,
    ISM_EFFECT_VALUE(EFFECT_BRIGHTPASS_BLUR3) = 23,
    ISM_EFFECT_VALUE(EFFECT_BRIGHTPASS_BLUR5) = 24,
    ISM_EFFECT_VALUE(EFFECT_BRIGHTPASS_BLUR7) = 25,
    ISM_EFFECT_VALUE(EFFECT_BRIGHTPASS_BLUR9) = 26,
    ISM_EFFECT_VALUE(EFFECT_BRIGHTPASS_BLUR11) = 27,
    ISM_EFFECT_VALUE(EFFECT_BRIGHTPASS_BLUR13) = 28,
    ISM_EFFECT_VALUE(EFFECT_BRIGHTPASS_BLUR15) = 29,
    ISM_EFFECT_VALUE(EFFECT_TV) = 30,
    ISM_EFFECT_VALUE(EFFECT_WATER_FFT) = 31,
    ISM_EFFECT_VALUE(EFFECT_WATER_DISPLACEMENT) = 32,
    ISM_EFFECT_VALUE(EFFECT_NOISE) = 33,
    ISM_EFFECT_VALUE(EFFECT_TOP_LEVEL_END) = 34,
    ISM_EFFECT_VALUE(EFFECT_NIGHTVISION) = 34,
    ISM_EFFECT_VALUE(EFFECT_END) = 34,
    ISM_EFFECT_VALUE(EFFECT_SHADER_START) = 34,
    ISM_EFFECT_VALUE(EFFECT_SHADER_COPY) = 34,
    ISM_EFFECT_VALUE(EFFECT_SHADER_COPY_RENDER_TARGET1) = 35,
    ISM_EFFECT_VALUE(EFFECT_SHADER_RESTORE_EDRAM) = 36,
    ISM_EFFECT_VALUE(EFFECT_SHADER_NULL) = 37,
    ISM_EFFECT_VALUE(EFFECT_SHADER_COPYWITHALPHA) = 38,
    ISM_EFFECT_VALUE(EFFECT_SHADER_STENCILCOPY) = 39,
    ISM_EFFECT_VALUE(EFFECT_SHADER_STENCILCOPY_NOTEX_NODEPTH) = 40,
    ISM_EFFECT_VALUE(EFFECT_SHADER_REFRACTION) = 41,
    ISM_EFFECT_VALUE(EFFECT_SHADER_VOLUMETRIC_FOG) = 42,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BLUR) = 43,
    ISM_EFFECT_VALUE(EFFECT_SHADER_DOUBLEVIS) = 44,
    ISM_EFFECT_VALUE(EFFECT_SHADER_ALPHAMULT) = 45,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BLEND) = 46,
    ISM_EFFECT_VALUE(EFFECT_SHADER_TEXTUREMASK) = 47,
    ISM_EFFECT_VALUE(EFFECT_SHADER_MAP) = 48,
    ISM_EFFECT_VALUE(EFFECT_SHADER_MENUBG) = 49,
    ISM_EFFECT_VALUE(EFFECT_SHADER_CINEMATIC) = 50,
    ISM_EFFECT_VALUE(EFFECT_SHADER_DEPTH_OF_FIELD) = 51,
    ISM_EFFECT_VALUE(EFFECT_SHADER_DEPTH_OF_FIELD_MASK) = 52,
    ISM_EFFECT_VALUE(EFFECT_SHADER_MOTION_BLUR) = 53,
    ISM_EFFECT_VALUE(EFFECT_SHADER_RADIAL_BLUR) = 54,
    ISM_EFFECT_VALUE(EFFECT_SHADER_RADIAL_BLUR_MED) = 55,
    ISM_EFFECT_VALUE(EFFECT_SHADER_RADIAL_BLUR_HIGH) = 56,
    ISM_EFFECT_VALUE(EFFECT_SHADER_SUNBEAMS) = 57,
    ISM_EFFECT_VALUE(EFFECT_SHADER_HDR_BLENDINSHADER) = 58,
    ISM_EFFECT_VALUE(EFFECT_SHADER_HDR_BLENDINSHADER_CINEMATIC) = 59,
    ISM_EFFECT_VALUE(EFFECT_SHADER_HDR_BLENDINSHADER_CINEMATIC_ALPHAMASK) = 60,
    ISM_EFFECT_VALUE(EFFECT_SHADER_HDR_BLUR) = 61,
    ISM_EFFECT_VALUE(EFFECT_SHADER_HDR_BRIGHTPASSFILTER) = 62,
    ISM_EFFECT_VALUE(EFFECT_SHADER_HDR_DOWNSAMPLE16) = 63,
    ISM_EFFECT_VALUE(EFFECT_SHADER_HDR_DOWNSAMPLE9) = 64,
    ISM_EFFECT_VALUE(EFFECT_SHADER_HDR_DOWNSAMPLE4) = 65,
    ISM_EFFECT_VALUE(EFFECT_SHADER_HDR_DOWNSAMPLE4_LUMCLAMP) = 66,
    ISM_EFFECT_VALUE(EFFECT_SHADER_HDR_DOWNSAMPLE4_LIGHTADAPT) = 67,
    ISM_EFFECT_VALUE(EFFECT_SHADER_HDR_DOWNSAMPLE16_LUMCLAMP) = 68,
    ISM_EFFECT_VALUE(EFFECT_SHADER_HDR_DOWNSAMPLE16_LIGHTADAPT) = 69,
    ISM_EFFECT_VALUE(EFFECT_SHADER_HDR_LIGHTADAPT) = 70,
    ISM_EFFECT_VALUE(EFFECT_SHADER_HDR_LUMCLAMP) = 71,
    ISM_EFFECT_VALUE(EFFECT_SHADER_INTERFACE_SCANLINES_BLEND) = 72,
    ISM_EFFECT_VALUE(EFFECT_SHADER_INTERFACE_VATS_SCANLINES_BLEND) = 73,
    ISM_EFFECT_VALUE(EFFECT_SHADER_INTERFACE_SINGLEPASS) = 74,
    ISM_EFFECT_VALUE(EFFECT_SHADER_INTERFACE_VATS_SCAN) = 75,
    ISM_EFFECT_VALUE(EFFECT_SHADER_INTERFACE_MENUUNPACK) = 76,
    ISM_EFFECT_VALUE(EFFECT_SHADER_TV) = 77,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BLUR_START) = 78,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BLUR3) = 78,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BLUR5) = 79,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BLUR7) = 80,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BLUR9) = 81,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BLUR11) = 82,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BLUR13) = 83,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BLUR15) = 84,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BLUR_END) = 84,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BRIGHTPASS_BLUR_START) = 85,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BRIGHTPASS_BLUR3) = 85,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BRIGHTPASS_BLUR5) = 86,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BRIGHTPASS_BLUR7) = 87,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BRIGHTPASS_BLUR9) = 88,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BRIGHTPASS_BLUR11) = 89,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BRIGHTPASS_BLUR13) = 90,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BRIGHTPASS_BLUR15) = 91,
    ISM_EFFECT_VALUE(EFFECT_SHADER_BRIGHTPASS_BLUR_END) = 91,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_FFT_START) = 92,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_FFT_WATER_SPECTRUM) = 93,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_FFT_HORIZONTAL_BUTTERFLY) = 94,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_FFT_VERTICAL_BUTTERFLY) = 95,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_FFT_HORIZONTAL_SCRAMBLE) = 96,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_FFT_VERTICAL_SCRAMBLE) = 97,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_FFT_NORMALS) = 98,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_FFT_FILTER) = 99,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_FFT_DISPLAY_NORMALS) = 100,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_FFT_DISPLAY_HIGHW) = 101,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_FFT_DISPLAY_AMPLITUDE) = 102,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_FFT_DISPLAY_WATER_SPECTRUM) = 103,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_FFT_DISPLAY_WATER_HEIGHT) = 104,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_FFT_END) = 104,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_DISPLACEMENT_START) = 105,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_DISPLACEMENT_CLEAR_SIMULATION) = 105,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_DISPLACEMENT_TEX_OFFSET) = 106,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_DISPLACEMENT_WADING_RIPPLE) = 107,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_DISPLACEMENT_RAIN_RIPPLE) = 108,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_DISPLACEMENT_WADING_HEIGHTMAP) = 109,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_DISPLACEMENT_RAIN_HEIGHTMAP) = 110,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_DISPLACEMENT_BLEND_HEIGHTMAPS) = 111,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_DISPLACEMENT_SMOOTH_HEIGHTMAP) = 112,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_DISPLACEMENT_NORMALS) = 113,
    ISM_EFFECT_VALUE(EFFECT_SHADER_WATER_DISPLACEMENT_END) = 113,
    ISM_EFFECT_VALUE(EFFECT_SHADER_NOISE_SCROLL_AND_BLEND) = 114,
    ISM_EFFECT_VALUE(EFFECT_SHADER_NOISE_NORMALMAP) = 115,
    ISM_EFFECT_VALUE(EFFECT_COUNT) = 116,
    ISM_EFFECT_VALUE(EFFECT_NONE) = -1
};

class ImageSpaceManager
{
public:
    ImageSpaceManager();
    ~ImageSpaceManager();
    static void* operator new(size_t size);
    static void operator delete(void* data);

    enum ISM_NESTED_EFFECT_ENUM
    {
        EFFECT_SHADER_MENUBG = 49
    };

    BSRenderedTexture* pEOFDest;
    unsigned char pEffectList[16];
    unsigned char CurrentParameterData[152];
    const ImageSpaceParameterData* pBaseParameterData;
    const ImageSpaceParameterData* pOverRideBaseParameterData;
    unsigned char WeatherParameterData[304];
    bool bIsReady;
    unsigned char _pad1E5[3];
    int iActiveEffectsCount;
    int iLastEffect;
    unsigned char spScreenTriShape[4];
    unsigned char spScreenTriShapeData[4];
    unsigned char spPartialScreenTriShape[4];
    bool bEnablePartialRender;
    unsigned char _pad1FD[3];
    unsigned char spMenuUnpackGeom[4];
    unsigned char DepthTexture[16];
    NiColorA kTintColor;
    NiColorA kWeatherTintColor;
    float fHighestTintValue;
    NiColorA kFadeColor;
    NiColorA kWeatherFadeColor;
    float fHighestFadeValue;
    float fHighestBlurValue;
    float fWeatherBlurValue;
    float fHighestDoubleValue;
    float fWeatherDoubleValue;
    float fHighestRadialBlurStrengthValue;
    float fCurrentRadialBlurRampupValue;
    float fCurrentRadialBlurStartValue;
    float fCurrentRadialBlurRampDownValue;
    float fCurrentRadialBlurDownStartValue;
    float fWeatherRadialBlurStrengthValue;
    float fWeatherRadialBlurRampupValue;
    float fWeatherRadialBlurStartValue;
    float fWeatherRadialBlurRampDownValue;
    float fWeatherRadialBlurDownStartValue;
    NiPoint2 fCurrentRadialBlurCenter;
    NiPoint2 fWeatherRadialBlurCenter;
    float fHighestDOFStrengthValue;
    float fCurrentDOFDistanceValue;
    float fCurrentDOFRangeValue;
    float fCurrentDOFMaskConst;
    float fWeatherDOFStrengthValue;
    float fWeatherDOFDistanceValue;
    float fWeatherDOFRangeValue;
    float fWeatherDOFMaskConst;
    int fCurrentDOFMode;
    int fWeatherDOFMode;
    bool bCurrentDOFUseMask;
    bool bWeatherDOFUseMask;
    unsigned char _pad2CE[2];
    float fHighestDepthRadialBlurStrengthValue;
    float fCurrentDepthRadialBlurRampupValue;
    float fCurrentDepthRadialBlurStartValue;
    float fCurrentDepthRadialBlurDistance;
    float fCurrentDepthRadialBlurRange;
    NiPoint2 fCurrentDepthRadialBlurCenter;
    int fCurrentDepthRadialBlurMode;
    float fHighestMotionBlurStrengthValue;
    float fWeatherMotionBlurStrengthValue;
    NiColorA kRefractionTint;
    unsigned char CustomViewPort[16];
    BSRenderedTexture* pSwapTarget;

    static bool m_bHasEndOfFrameEffects;

    BSRenderedTexture* GetDepthRenderedTexture();
    void CreateMenuBackgroundGeometry();
    void BeginParamModifiers();
    void SetupEffects();
    bool IsEffectActive(ISM_EFFECT_ENUM);
    void PrepareEndOfFrameEffects();
    void SetRadialBlurParameters(float, float, float, float, float, const NiPoint2&);
    void SetDepthOfFieldParameters(float, unsigned int, float, float, float);
    void SetBlurRadiusParamModifier(float);
    void ApplyDepthOfFieldParamModifierWeather(float, unsigned int, float, float, float);
    void ApplyTintColorParamModifier(NiColorA&);
    void ApplyTintColorParamModifierWeather(NiColorA&);
    void SetFadeColorParamModifier(NiColorA&);
    void ApplyFadeColorParamModifierWeather(NiColorA&);
    void ApplyRadialBlurParamModifierWeather(float, float, float, float, float, const NiPoint2&);
    void Initialize();
    void Shutdown();
    void InitDefaultParameter();
    ISM_EFFECT_TYPE()* GetEffect(int);
    void ISM_ADD_EFFECT(int, ISM_EFFECT_TYPE()*);
    bool IsEffectActive(int);
    void SetupShader();
    void RenderEndOfFrameEffects(GraphicsRenderer*, BSRenderedTexture**, BSRenderedTexture**);
    void RenderEffect(ISM_EFFECT_TYPE()*, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ISM_EFFECT_TYPE(Param)*, bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, NiTexture*, BSRenderedTexture*, ISM_EFFECT_TYPE(Param)*, bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ISM_EFFECT_TYPE(Param)*, bool);
    void RenderEffect(ISM_EFFECT_TYPE()*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, BSRenderedTexture*, ISM_EFFECT_TYPE(Param)*, bool);
    void RenderEffect(ISM_EFFECT_TYPE()*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, ISM_EFFECT_TYPE(Param)*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, ISM_EFFECT_TYPE(Param)*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, ISM_EFFECT_TYPE(Param)*, bool);
    void ModifyParameterData(int, unsigned int, int, float);
    void ApplyCurrentParameterData(bool);
    void SetBaseParameterData(void*);
    void SetOverrideBaseParameterData(void*);
    void ResetToBaseParameterData();
    void ResetWeatherData();
    void ApplyParamModifier(int, unsigned int, float*, float);
    void ApplyParamModifierWeather(int, unsigned int, float*, float);
    void ApplyTintColorParamModifier(NiColorA*);
    void ApplyTintColorParamModifierWeather(NiColorA*);
    void SetFadeColorParamModifier(NiColorA*);
    void ApplyFadeColorParamModifierWeather(NiColorA*);
    void ApplyBlurRadiusParamModifierWeather(float);
    void ApplyDoubleVisionParamModifier(float);
    void ApplyDoubleVisionParamModifierWeather(float);
    void SetRadialBlurParameters(float, float, float, float, float, void*);
    void ApplyRadialBlurParamModifierWeather(float, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, void*);
    void SetDepthOfFieldParameters(float, unsigned int, float, void*);
    void ApplyMotionBlurStrengthParamModifier(float);
    void ApplyMotionBlurStrengthParamModifierWeather(float);
    void EndWeatherModifiers();
    void EndParamModifiers();
    float ApplyOperation(int, float, float);
    void GetRadialBlurCenterFromWorldBound(void*, NiPoint2*);
    void GetDepthOfFieldParamsFromWorldBound(void*, NiPoint2*);
    void EnableSunbeams(bool);
    void SetSunPosition(void*);
    BSRenderedTexture* GetRefractionNormalsTexture(bool);
    BSRenderedTexture* GetVolumetricFogTexture();
    void ReturnVolumetricFogTexture();
    float GetHDREmissiveMult();
    float GetHDRBlurRadius();
    float GetHDRBrightClamp();
    float GetHDRBrightScale();
    float GetHDREyeAdaptSpeed();
    float GetHDRTargetLUM();
    float GetHDRUpperLUMClamp();
    void SetVolumetricFogProps(NiColorA);
    void SetMotionBlurConst(float);
    void SetMenuBGBlendEnabled(bool);
    void SetMenuBGBlendValue(float);
    void EnablePartialRender(bool, NiScreenElements*);
    void SetMenuBackgroundBlend(float, float, void*);
    NiTexture* GetDepthTexture();
    ImageSpaceTexture* GetDepthImageSpaceTexture();
    void SetDepthTexture(BSRenderedTexture*);
    void SetDepthTexture(NiTexture*);
    void ReturnDepthTexture();
    NiScreenElements* GetMenuUnpackGeom();
    void SetMenuUnpackGeom(NiScreenElements*);
    void SetRefractionTint(void*);
    void* GetRefractionTint();
    void SetCustomViewPort(float, float, float, float);
    void ClearCustomViewPort();
    void* GetCustomViewport();
    BSRenderedTexture* GetSwapTarget();
    void InitEffects();
    void ShutdownEffects();
    void ShutdownGeometry();
    void SetIfHigherPriority(float, unsigned int, float, float, float, float, const NiPoint2&);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, const NiBound&);
    void SetDistanceEffect(float, unsigned int, float, const NiBound&);
    void AccumulateComponentValues(int, int, float*, float);
    void RaiseHighestBlurRadius(float);
    void RaiseBlurRadius(float);
    void AddDoubleVision(float);
    void RenderWithTextures(ISM_EFFECT_TYPE()*, void*, void*, void*, int, int);
    static ImageSpaceManager* BSShaderManager_GetImageSpaceManager();
    ISM_EFFECT_TYPE()* GetEffect_004ebbc0(int);
    bool ImageSpaceManager_SetMotionBlur(float);
    void ApplyBlurRadiusParamModifierWeather_00b8af40(float);
    void ApplyMotionBlurStrengthParamModifierWeather_00b8af90(float);
    void ApplyDoubleVisionParamModifier_00b8afb0(float);
    void FUN_00b8b130(float, unsigned int, float, float, float);
    void FUN_00b8b360();
    bool FUN_00b8b390(unsigned int);
    void FUN_00b8b3f0();
    void FUN_00b8b440(bool);
    void FUN_00b8b540(NiColorA&);
    void FUN_00b8b5c0(NiColorA&);
    void FUN_00b8b610(NiColorA&);
    void FUN_00b8b690(NiColorA&);
    void FUN_00b8b6e0(float, float, float, float, float, const NiPoint2&);
    void ApplyRadialBlurParamModifier(float, float, float, float, float, const NiBound&);
    void __thiscall ImageSpaceManager_SetActiveImageSpaceParams(void*);
    void ApplyParamModifier_00b8cb30(int, int, float*, float);
    void ImageSpaceManager_RenderEffect(int, NiRenderer*, BSRenderedTexture*, BSRenderedTexture*, int, bool);
    void ImageSpaceManager_RenderEffect(int, NiRenderer*, void*, void*, int, int);
    void ImageSpaceManager_RenderEffect(int, void*, void*, void*, int, int);
    void ImageSpaceManager_RenderEffect_2(int, NiRenderer*, void*, RenderTexture*, void*, int);
    void SetValue(int);
    ISM_EFFECT_TYPE()* GetEffect(unsigned int);
};

#undef ISM_NESTED_EFFECT_ENUM
#undef ISM_ADD_EFFECT
#undef ISM_EFFECT_VALUE
#undef ISM_EFFECT_ENUM
#undef ISM_EFFECT_TYPE
