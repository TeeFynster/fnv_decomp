#include "../../include/NiTMapItem.h"
// bsshader/imagespacemanager.cpp: ImageSpaceManager and image-space helpers (60 functions)

#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../include/NiPointer.h"
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTNewInterface.h"
#include "../../include/NiTArray.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/AutoMemContext.h"
#include "../../include/ImageSpaceManager.h"
#include "../../include/ImageSpaceTexture.h"
#include "../../include/NiGlobalStringTable.h"
#include "../../include/BSTextureManager.h"
#include "../../include/ImageSpaceModifierParameterData.h"
#include "../../include/NiPoint2.h"
#include "../../include/NiScreenElements.h"
#include "../../include/NiScreenElementsData.h"
#include "../../include/NiUpdateData.h"
#include "../../include/NiColorA.h"
#include "NiObject.h"
#include "NiRefObject_inline.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiCamera.h"
#include "../../include/NiPoint3.h"
#include "../../include/PointStorage.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPoint3.h"
#include "../../include/Vec4.h"

#include <math.h>

inline NiColorA::NiColorA(float fR, float fG, float fB, float fA)
{
    r = fR;
    g = fG;
    b = fB;
    a = fA;
}
inline NiUpdateData::NiUpdateData() {}
inline NiUpdateData::NiUpdateData(float time)
    : fTime(time), pad1(false), pad2(false), pad3(false), pad4(false), pad5(false)
{}

inline NiScreenElementsData* NiScreenElements::GetData()
{
    return static_cast<NiScreenElementsData*>(m_spModelData.m_pObject);
}

inline void NiAVObject::IncRefCount()
{
    NiRefObject::IncRefCount();
}

inline void NiAVObject::DecRefCount()
{
    NiRefObject::DecRefCount();
}

inline void NiGeometryData::IncRefCount()
{
    NiRefObject::IncRefCount();
}

inline void NiGeometryData::DecRefCount()
{
    NiRefObject::DecRefCount();
}

inline float NiPoint3::Length() const
{
    return sqrtf(x * x + y * y + z * z);
}

__forceinline NiPoint3 NiPoint3::operator-(const NiPoint3& o) const
{
    NiPoint3 r;
    r.x = x - o.x;
    r.y = y - o.y;
    r.z = z - o.z;
    return r;
}

extern __declspec(thread) int BSAudioThreadContext;

// ImageSpaceManager keeps several fields opaque in the shared layout. Cast those
// fields to their shared value types at use sites without introducing local layouts.
#include "imagespacemanager_geometry.h"
#include "imagespacemanager_types_ImageSpaceManager.h"
#include "imagespacemanager_effect.h"
#include "imagespacemanager_globals.h"

// @fnv 0x00b8b000
void ImageSpaceManager::SetRadialBlurParameters(float strength, float rampUp, float start, float rampDown,
                                                float downStart, const NiPoint2& arCenter)
{
    if (strength > fHighestRadialBlurStrengthValue)
    {
        fHighestRadialBlurStrengthValue = strength;
        fCurrentRadialBlurRampupValue = rampUp;
        fCurrentRadialBlurStartValue = start;
        fCurrentRadialBlurRampDownValue = rampDown;
        fCurrentRadialBlurDownStartValue = downStart;
        fCurrentRadialBlurCenter = arCenter;
    }
}

// If strength exceeds the stored maximum, records the new strength, mode, distance, range and mask constant for depth of field.
// @fnv 0x00b8b0d0
void ImageSpaceManager::SetDepthOfFieldParameters(float strength, unsigned int mode, float maskConst, float distance,
                                                  float range)
{
    if (strength > fHighestDOFStrengthValue)
    {
        fHighestDOFStrengthValue = strength;
        bCurrentDOFUseMask = false;
        if (mode > 2)
        {
            bCurrentDOFUseMask = true;
            mode -= 3;
        }
        fCurrentDOFMode = (ImageSpaceEffectDepthOfField__DepthOfFieldMode)mode;
        fCurrentDOFDistanceValue = distance;
        fCurrentDOFRangeValue = range;
        fCurrentDOFMaskConst = maskConst;
    }
}

extern ImageSpaceManager* DAT_011f91ac;
#pragma optimize("", off)
// @fnv 0x004e3270
// src: XBOX_PDB 0x004e3270
ImageSpaceManager* ImageSpaceManager::BSShaderManager_GetImageSpaceManager()
{
    return DAT_011f91ac;
}
#pragma optimize("", on)

// Creates a NiScreenElementsData and NiScreenElements, configures its data, names it "Imagespace Effect Geometry", and updates it with zero time.
// @fnv 0x00b8c170
void ImageSpaceManager::CreateMenuBackgroundGeometry()
{
    (*reinterpret_cast<NiPointer<NiScreenElementsData>*>(spScreenTriShapeData)) = new NiScreenElementsData(false, false, 1, 1, 1, 4, 1, 2, 1);
    (*reinterpret_cast<NiPointer<NiScreenElements>*>(spScreenTriShape)) = new NiScreenElements((*reinterpret_cast<NiPointer<NiScreenElementsData>*>(spScreenTriShapeData)));
    (*reinterpret_cast<NiPointer<NiScreenElements>*>(spScreenTriShape))->GetData()->FUN_00a87ae0(4, 0, 0);
    (*reinterpret_cast<NiPointer<NiScreenElements>*>(spScreenTriShape))->GetData()->SetRectangleBounds(0, DAT_01012054, 1.0f, DAT_010162c0, DAT_0104a494);
    (*reinterpret_cast<NiPointer<NiScreenElements>*>(spScreenTriShape))->GetData()->FUN_00a88130(0, 0, 0.0f, 0.0f, 1.0f, 1.0f);
    (*reinterpret_cast<NiPointer<NiScreenElements>*>(spScreenTriShape))->GetData()->NiScreenElementsData_UpdateBound();
    (*reinterpret_cast<NiPointer<NiScreenElements>*>(spScreenTriShape))->NiAVObject::SetName(::NiFixedString("Imagespace Effect Geometry"));
    (*reinterpret_cast<NiPointer<NiScreenElements>*>(spScreenTriShape))->UpdateSceneObject();
    NiUpdateData update;
    update.fTime = 0.0f;
    update.pad1 = false;
    update.pad2 = false;
    update.pad3 = false;
    update.pad4 = false;
    update.pad5 = false;
    (*reinterpret_cast<NiPointer<NiScreenElements>*>(spScreenTriShape))->NiAVObject::Update(update);
}

// @fnv 0x00b8b200
// src: COMMUNITY 0x00b8b200
void __stdcall ImageSpaceManager_SetUseSunbeams(bool value)
{
    DAT_012023f0 = value;
}

// @fnv 0x00b8b130
void ImageSpaceManager::ApplyDepthOfFieldParamModifierWeather(float strength, unsigned int mode, float maskConst,
                                                              float distance, float range)
{
    bWeatherDOFUseMask = false;
    fWeatherDOFStrengthValue += strength;
    fWeatherDOFMode = (ImageSpaceEffectDepthOfField__DepthOfFieldMode)mode;
    fWeatherDOFDistanceValue += distance;
    fWeatherDOFRangeValue += range;
    fWeatherDOFMaskConst += maskConst;
}

// Adds the r, g, b and a components of color to the tint color stored in the manager.
// @fnv 0x00b8b5c0
void ImageSpaceManager::ApplyTintColorParamModifierWeather(NiColorA& color)
{
    NiColorA& tint = kWeatherTintColor;
    tint.r += color.r;
    tint.g += color.g;
    tint.b += color.b;
    tint.a += color.a;
}

// Adds the r, g, b and a components of color to the fade color stored in the manager.
// @fnv 0x00b8b690
void ImageSpaceManager::ApplyFadeColorParamModifierWeather(NiColorA& color)
{
    NiColorA* fade = &kWeatherFadeColor;
    fade->r += color.r;
    fade->g += color.g;
    fade->b += color.b;
    fade->a += color.a;
}

// Accumulates the alpha-weighted RGB of color into a running tint sum and tracks the maximum alpha seen.
// @fnv 0x00b8b540
void ImageSpaceManager::ApplyTintColorParamModifier(NiColorA& color)
{
    if (color.a > fHighestTintValue)
        fHighestTintValue = color.a;
    float r = color.r * color.a;
    color.r = r;
    color.g = color.g * color.a;
    color.b = color.b * color.a;
    kTintColor.r += r;
    kTintColor.g += color.g;
    kTintColor.b += color.b;
    kTintColor.a += color.a;
}

// Tracks the maximum alpha seen and adds the alpha-premultiplied color into the accumulator, scaling r, g and b by a.
// @fnv 0x00b8b610
void ImageSpaceManager::SetFadeColorParamModifier(NiColorA& color)
{
    if (color.a > fHighestFadeValue)
        fHighestFadeValue = color.a;
    float r = color.r * color.a;
    color.r = r;
    color.g = color.g * color.a;
    color.b = color.b * color.a;
    kFadeColor.r += r;
    kFadeColor.g += color.g;
    kFadeColor.b += color.b;
    kFadeColor.a += color.a;
}

// Adds the given radial blur parameters and center offset into the manager's accumulated weather values.
// @fnv 0x00b8b6e0
void ImageSpaceManager::ApplyRadialBlurParamModifierWeather(float strength, float rampUp, float start, float rampDown,
                                                            float downStart, const NiPoint2& center)
{
    fWeatherRadialBlurStrengthValue += strength;
    fWeatherRadialBlurRampupValue += rampUp;
    fWeatherRadialBlurStartValue += start;
    fWeatherRadialBlurRampDownValue += rampDown;
    fWeatherRadialBlurDownStartValue += downStart;
    NiPoint2& weather = fWeatherRadialBlurCenter;
    weather.x += center.x;
    weather.y += center.y;
}

// Iterates the effect list up to EFFECT_TOP_LEVEL_END and calls Setup(this, 0) on each non-null ImageSpaceEffect.
// @fnv 0x00b8b360
void ImageSpaceManager::SetupEffects()
{
    for (int i = 0; i < ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_TOP_LEVEL_END; i++)
    {
        ImageSpaceEffect* effect = (*reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(pEffectList)).m_pBase[i];
        if (effect)
            effect->Setup(this, 0);
    }
}

// @fnv 0x00b8b390
bool ImageSpaceManager::IsEffectActive(ImageSpaceManager__ImageSpaceEffectEnum index)
{
    ImageSpaceEffect* effect = (*reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(pEffectList)).m_pBase[index];
    if (effect)
        return effect->IsActive();
    return false;
}

// Scans the effect list up to EFFECT_ENDOFFRAME_END, counts active effects and records the last active effect's enum index.
// @fnv 0x00b8b3f0
void ImageSpaceManager::PrepareEndOfFrameEffects()
{
    iLastEffect = ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_NONE;
    iActiveEffectsCount = 0;
    if (m_bHasEndOfFrameEffects)
    {
        for (int i = 0; i < ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_ENDOFFRAME_END; i++)
        {
            ImageSpaceEffect* effect = (*reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(pEffectList)).m_pBase[i];
            if (!effect)
                continue;
            if (!effect->IsActive())
                continue;
            iActiveEffectsCount++;
            iLastEffect = (ImageSpaceManager__ImageSpaceEffectEnum)i;
        }
    }
}

#include "imagespacemanager_array.h"

// @fnv 0x00b8b270
template <>
void NiTArray<bool, NiTMallocInterface<bool> >::SetAt(unsigned int index, const bool& value)
{
    if (index >= m_usSize)
    {
        m_usSize = (unsigned short)(index + 1);
        if (value)
            ++m_usESize;
    }
    else
    {
        if (value)
        {
            if (!m_pBase[index])
                ++m_usESize;
        }
        else if (m_pBase[index])
            --m_usESize;
    }
    m_pBase[index] = value;
}

// @fnv 0x00b8b190
BSRenderedTexture* ImageSpaceManager::GetDepthRenderedTexture()
{
    const ImageSpaceTexture& depth = (*reinterpret_cast<ImageSpaceTexture*>(DepthTexture));
    if (!depth.GetTexture())
        (*reinterpret_cast<ImageSpaceTexture*>(DepthTexture)).CreateRenderTargetTexture(BSTextureManager::BSTM_RT_SCENE_DEPTH_BUFFER);
    return depth.GetRenderedTexture();
}

extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);

// @fnv 0x00b8b9a0
void ImageSpaceManager::BeginParamModifiers()
{
    float alpha = (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afColorAndAlphaParameters[7];
    fHighestTintValue = alpha;
    kTintColor.r = (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afColorAndAlphaParameters[4] * alpha;
    kTintColor.g = (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afColorAndAlphaParameters[5] * alpha;
    kTintColor.b = (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afColorAndAlphaParameters[6] * alpha;
    kTintColor.a = (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afColorAndAlphaParameters[7];
    {
        NiColorA clear;
        clear.r = 0.0f;
        clear.g = 0.0f;
        clear.b = 0.0f;
        clear.a = 0.0f;
        kWeatherTintColor = clear;
    }
    fHighestFadeValue = 0.0f;
    kFadeColor.r = 0.0f;
    kFadeColor.g = 0.0f;
    kFadeColor.b = 0.0f;
    kFadeColor.a = 0.0f;
    kWeatherFadeColor.r = 0.0f;
    kWeatherFadeColor.g = 0.0f;
    kWeatherFadeColor.b = 0.0f;
    kWeatherFadeColor.a = 0.0f;
    fHighestBlurValue = 0.0f;
    fHighestDoubleValue = 0.0f;
    fHighestRadialBlurStrengthValue = 0.0f;
    fCurrentRadialBlurRampupValue = 0.0f;
    fCurrentRadialBlurStartValue = 0.0f;
    fCurrentRadialBlurRampDownValue = 0.0f;
    fCurrentRadialBlurDownStartValue = 0.0f;
    {
        NiPoint2 clear;
        clear.x = 0.0f;
        clear.y = 0.0f;
        fCurrentRadialBlurCenter = clear;
    }
    fHighestDOFStrengthValue = 0.0f;
    fCurrentDOFDistanceValue = 0.0f;
    fCurrentDOFRangeValue = 0.0f;
    fCurrentDOFMaskConst = 0.0f;
    fCurrentDOFMode = (ImageSpaceEffectDepthOfField__DepthOfFieldMode)3;
    bCurrentDOFUseMask = false;
    fHighestDepthRadialBlurStrengthValue = 0.0f;
    fHighestMotionBlurStrengthValue = 0.0f;
    fWeatherBlurValue = 0.0f;
    fWeatherDoubleValue = 0.0f;
    fWeatherRadialBlurStrengthValue = 0.0f;
    fWeatherRadialBlurRampupValue = 0.0f;
    fWeatherRadialBlurStartValue = 0.0f;
    fWeatherRadialBlurRampDownValue = 0.0f;
    fWeatherRadialBlurDownStartValue = 0.0f;
    {
        NiPoint2 clear;
        clear.x = 0.0f;
        clear.y = 0.0f;
        fWeatherRadialBlurCenter = clear;
    }
    fWeatherDOFStrengthValue = 0.0f;
    fWeatherDOFDistanceValue = 0.0f;
    fWeatherDOFRangeValue = 0.0f;
    fWeatherDOFMaskConst = 0.0f;
    fWeatherDOFMode = (ImageSpaceEffectDepthOfField__DepthOfFieldMode)3;
    bWeatherDOFUseMask = false;
    fWeatherMotionBlurStrengthValue = 0.0f;
    fnv_zlib_memset((*reinterpret_cast<ImageSpaceModifierParameterData (*)[2]>(WeatherParameterData)), 0, sizeof((*reinterpret_cast<ImageSpaceModifierParameterData (*)[2]>(WeatherParameterData))));
}


// If afBlurRadius exceeds the stored highest blur value at offset 0x25c, it stores afBlurRadius there.
// @fnv 0x00b8af10
void ImageSpaceManager::RaiseHighestBlurRadius(float afBlurRadius)
{
    float& fHighestBlur = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x25c);
    if (afBlurRadius > fHighestBlur)
        fHighestBlur = afBlurRadius;
}


// @fnv 0x00b8af40
// src: COMMUNITY 0x00b8af40
void ImageSpaceManager::ApplyBlurRadiusParamModifierWeather_00b8af40(float afBlurRadius)
{
    fWeatherBlurValue += afBlurRadius;
}


// Raises the float at offset 0x2f0 to afBlurRadius if afBlurRadius is greater than its current value.
// @fnv 0x00b8af60
void ImageSpaceManager::RaiseBlurRadius(float afBlurRadius)
{
    float& val = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x2f0);
    if (afBlurRadius > val)
        val = afBlurRadius;
}


// @fnv 0x00b8af90
// src: COMMUNITY 0x00b8af90
void ImageSpaceManager::ApplyMotionBlurStrengthParamModifierWeather_00b8af90(float afBlurRadius)
{
    *(float*)((char*)this + 0x2f4) += afBlurRadius;
}


// Raises the stored double-vision value to afDoubleVision when the new value is greater.
// @fnv 0x00b8afb0
// src: COMMUNITY 0x00b8afb0
void ImageSpaceManager::ApplyDoubleVisionParamModifier_00b8afb0(float afDoubleVision)
{
    if (afDoubleVision > fHighestDoubleValue)
        fHighestDoubleValue = afDoubleVision;
}


// @fnv 0x00b8afe0
void ImageSpaceManager::AddDoubleVision(float afDoubleVision)
{
    *(float*)((char*)this + 0x268) += afDoubleVision;
}

// @fnv 0x00b8b210
// src: COMMUNITY 0x00b8b210
void __fastcall ImageSpaceEffectDepthRadialBlur_SetMode(char* pThis, int, int mode)
{
    if (mode != *(int*)(pThis + 0x58))
    {
        *(bool*)(pThis + 0x5) = true;
        *(int*)(pThis + 0x58) = mode;
        *(float*)(pThis + 0x70) = (mode == 1 || mode == 0) ? 1.0f : 0.0f;
        *(float*)(pThis + 0x74) = (mode == 2 || mode == 0) ? 1.0f : 0.0f;
    }
}

struct VTableObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(void*);
    virtual void v9(void*, int);
    virtual void v10(void*);
};

struct PtrTable
{
    VTableObj* p00;
    VTableObj* p04;
    int p08;
    VTableObj* p0c;
    int p10;
    int p14;
    int p18;
    int p1c;
    VTableObj* p20;
};

// @fnv 0x00b8b440
void ImageSpaceManager::ApplyCurrentParameterData(bool bFlag)
{
    char* pThis = reinterpret_cast<char*>(this);
    PtrTable** ppTable = (PtrTable**)(pThis + 8);
    if ((*ppTable)->p00)
    {
        (*ppTable)->p00->v8(pThis + 0x50);
    }
    if ((*ppTable)->p04)
    {
        (*ppTable)->p04->v8(pThis + 0x14);
    }
    if ((*ppTable)->p20)
    {
        (*ppTable)->p20->v8(pThis + 0x5c);
    }
    if ((*ppTable)->p0c)
    {
        (*ppTable)->p0c->v9(pThis + 0x78, *(int*)(pThis + 0xa8));
        (*ppTable)->p0c->v10(pThis + 0x68);
    }
    if (!bFlag)
    {
        DAT_011ad87c = *(float*)(pThis + 0x34);
        DAT_011ad880 = 1.0f;
    }
    else
    {
        DAT_011ad880 = *(float*)(pThis + 0x34);
    }
    DAT_011f9190 = *(float*)(pThis + 0x40);
    DAT_011f918c = *(float*)(pThis + 0x48);
    DAT_011f9188 = *(float*)(pThis + 0x44);
    DAT_011f9184 = *(float*)(pThis + 0x1c);
}

// Sets the first three entries of the bool array at self+0x58 to true and the fourth to false.
// @fnv 0x00b8bc20
// src: COMMUNITY 0x00b8bc20
void __fastcall ImageSpaceEffectDepthOfField_DoStandard(char* self, int)
{
    NiTArray<bool, NiTMallocInterface<bool> >* arr =
        reinterpret_cast<NiTArray<bool, NiTMallocInterface<bool> >*>(self + 0x58);
    bool val;
    val = true;
    arr->SetAt(0, val);
    val = true;
    arr->SetAt(1, val);
    val = true;
    arr->SetAt(2, val);
    val = false;
    arr->SetAt(3, val);
}

class D3DRenderStateGroup
{
  public:
    void SetRenderState(unsigned int, unsigned int, bool);
    static D3DRenderStateGroup* __cdecl GetCurrentRenderStateGroup(void);
};

// Ensures the render state object exists, then sets render states 0x34, 0x38, 0x39 and 0x37 to 1, 7, 0x80 and 1.
// @fnv 0x00b8bfe0
// src: COMMUNITY 0x00b8bfe0
void __fastcall ImageSpaceShaderSunbeams_PresetRenderStages(char* pThis, int)
{
    char* pPass = *(char**)(pThis + 0x5c);
    if (*(D3DRenderStateGroup**)(pPass + 0x30) == 0)
        *(D3DRenderStateGroup**)(pPass + 0x30) = D3DRenderStateGroup::GetCurrentRenderStateGroup();
    (*(D3DRenderStateGroup**)(pPass + 0x30))->SetRenderState(0x34, 1, true);

    pPass = *(char**)(pThis + 0x5c);
    if (*(D3DRenderStateGroup**)(pPass + 0x30) == 0)
        *(D3DRenderStateGroup**)(pPass + 0x30) = D3DRenderStateGroup::GetCurrentRenderStateGroup();
    (*(D3DRenderStateGroup**)(pPass + 0x30))->SetRenderState(0x38, 7, true);

    pPass = *(char**)(pThis + 0x5c);
    if (*(D3DRenderStateGroup**)(pPass + 0x30) == 0)
        *(D3DRenderStateGroup**)(pPass + 0x30) = D3DRenderStateGroup::GetCurrentRenderStateGroup();
    (*(D3DRenderStateGroup**)(pPass + 0x30))->SetRenderState(0x39, 0x80, true);

    pPass = *(char**)(pThis + 0x5c);
    if (*(D3DRenderStateGroup**)(pPass + 0x30) == 0)
        *(D3DRenderStateGroup**)(pPass + 0x30) = D3DRenderStateGroup::GetCurrentRenderStateGroup();
    (*(D3DRenderStateGroup**)(pPass + 0x30))->SetRenderState(0x37, 1, true);
}

struct ShaderInitBlock_00b8c0e0
{
    const char* name;
    int zero;
    int pad[17];
};

struct Vtable_00b8c0e0
{
    char pad0[0x13c];
    void(__thiscall* fn_13c)(void*, ShaderInitBlock_00b8c0e0*, ShaderInitBlock_00b8c0e0*, const char*, const char*,
                             const char*);
    char pad1[0x14c - 0x140];
    void(__thiscall* fn_14c)(void*);
};

struct Obj_00b8c0e0
{
    Vtable_00b8c0e0* vt;
};

// Fills vertex and pixel shader init blocks with the TV shader paths, calls the vtable init with "TV", "vs_1_1", "ps_2_0", then the vtable finalize.
// @fnv 0x00b8c0e0
void __fastcall InitTVShader(Obj_00b8c0e0* pObj, int)
{
    ShaderInitBlock_00b8c0e0 vsBlock;
    ShaderInitBlock_00b8c0e0 psBlock;
    vsBlock.name = "imagespace\\1x\\v\\base.v.hlsl";
    vsBlock.zero = 0;
    fnv_zlib_memset(vsBlock.pad, 0, 0x44);
    psBlock.name = "imagespace\\2x\\p\\tv.p.hlsl";
    psBlock.zero = 0;
    fnv_zlib_memset(psBlock.pad, 0, 0x44);
    pObj->vt->fn_13c(pObj, &vsBlock, &psBlock, "TV", "vs_1_1", "ps_2_0");
    pObj->vt->fn_14c(pObj);
}

int __cdecl ImageSpaceEffectRadialBlur_GetBoundParams(int, int, int*);
// @fnv 0x00b8b1c0
// src: GUESS 0x00b8b1c0 (confidence: medium)
int __stdcall Object_ImageSpaceEffectRadialBlur_GetBoundParams_Thunk(int a, int b)
{
    return ImageSpaceEffectRadialBlur_GetBoundParams(a, b, &b);
}

extern float DAT_012023f4;
extern float DAT_012023f8;
// @fnv 0x00b8b1e0
// src: COMMUNITY 0x00b8b1e0
void __stdcall ImageSpaceManager_SetSunPosition(const int* aiValues)
{
    *reinterpret_cast<int*>(&DAT_012023f4) = aiValues[0];
    *reinterpret_cast<int*>(&DAT_012023f8) = aiValues[1];
}

extern ImageSpaceManager* DAT_011f91ac;

void __stdcall ImageSpaceManager_SetUseSunbeams(bool value);

extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);

extern "C" void* __cdecl _memmove(void*, const void*, unsigned int);
extern ImageSpaceModifierParameterData DAT_011ff940;
extern float DAT_012003d0;
extern float _DAT_01202400;

// Copies 0x98 bytes from the object's source pointer at 0xb0 or 0xac into offset 0x14, falling back to DAT_011ff940, then zeroes two floats.
// @fnv 0x00b8b500
void ImageSpaceManager::ResetToBaseParameterData()
{
    void* thisPtr = this;
    char* pSource = *(char**)((char*)thisPtr + 0xb0);
    if (pSource)
    {
        _memmove((char*)thisPtr + 0x14, pSource, 0x98);
        _DAT_01202400 = 0.0f;
        DAT_012003d0 = 0.0f;
        return;
    }
    pSource = *(char**)((char*)thisPtr + 0xac);
    if (pSource)
    {
        _memmove((char*)thisPtr + 0x14, pSource, 0x98);
        _DAT_01202400 = 0.0f;
        DAT_012003d0 = 0.0f;
        return;
    }
    _memmove((char*)thisPtr + 0x14, &DAT_011ff940, 0x98);
    _DAT_01202400 = 0.0f;
    DAT_012003d0 = 0.0f;
}

struct FUN_00b8bc80_shell
{
    NiTArray<bool, NiTMallocInterface<bool> > m_aiIndexedValues;  // at offset 0x58
    void __thiscall ImageSpaceEffectDepthOfField_DoMasked();
};
// Sets the bool array at offset 0x58: index 0, 1 and 3 to true and index 2 to false.
// @fnv 0x00b8bc80
// src: COMMUNITY 0x00b8bc80
void __thiscall FUN_00b8bc80_shell::ImageSpaceEffectDepthOfField_DoMasked()
{
    NiTArray<bool, NiTMallocInterface<bool> >* p = (NiTArray<bool, NiTMallocInterface<bool> >*)((char*)this + 0x58);
    p->SetAt(0, true);
    p->SetAt(1, true);
    p->SetAt(2, false);
    p->SetAt(3, true);
}

struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};

// These shader receivers expose storage already initialized by ImageSpaceEffectShader's
// constructor. A by-value NiTPrimitiveArray<ImageSpaceTexture*> adds a second array
// construction and cleanup: rebind reports 118 bytes instead of the original 98 at
// 0x00b8bce0, 0x00b8bea0 and 0x00b8c070. Keep passive storage and use the shared
// template for every array operation.
struct ShaderTextureArrayStorage
{
    unsigned char bytes[sizeof(NiTPrimitiveArray<ImageSpaceTexture*>)];
};

extern int DAT_010affa0;
extern int DAT_010affc0;

struct FUN_00b8bce0 : ImageSpaceEffectShader
{
    void* m_vtbl;
    char pad1[0x68];
    void* m_6c;
    char pad2[0x24];
    ShaderTextureArrayStorage m_ppData;
    FUN_00b8bce0();
};

// @fnv 0x00b8bce0
FUN_00b8bce0::FUN_00b8bce0()
{
    m_vtbl = &DAT_010affc0;
    m_6c = &DAT_010affa0;
    reinterpret_cast<NiTPrimitiveArray<ImageSpaceTexture*>*>(&m_ppData)->SetSize(5);
}

extern const char g_011fed88_arg1[];
// Returns the address of the string g_011fed88_arg1.
// @fnv 0x00b8bd90
const char* __cdecl GetArg1String()
{
    return g_011fed88_arg1;
}

namespace fnv_00b8bea0 {

struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
extern int DAT_010b0174;
extern int DAT_010b0198;
struct FUN_00b8bea0 : ImageSpaceEffectShader
{
    int* v0;
    char pad1[0x68];
    int* v6c;
    char pad2[0x24];
    ShaderTextureArrayStorage arr;
    FUN_00b8bea0();
};
// Initializes the object's two pointers to DAT_010b0198 and DAT_010b0174 and sets the texture array size to 2.
// @fnv 0x00b8bea0
FUN_00b8bea0::FUN_00b8bea0()
{
    v0 = &DAT_010b0198;
    v6c = &DAT_010b0174;
    reinterpret_cast<NiTPrimitiveArray<ImageSpaceTexture*>*>(&arr)->SetSize(2);
}
}  // namespace fnv_00b8bea0

struct FUN_00b8bf10_Desc
{
    const char* file;
    int flags;
    int r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16;
};
struct FUN_00b8bf10_Obj;
typedef void(__thiscall* FUN_00b8bf10_Add)(FUN_00b8bf10_Obj*, FUN_00b8bf10_Desc*, FUN_00b8bf10_Desc*, const char*,
                                           const char*, const char*);
typedef void(__thiscall* FUN_00b8bf10_Fin)(FUN_00b8bf10_Obj*);
struct FUN_00b8bf10_Obj
{
    void** vt;
};
// Registers the Sunbeams shader with vertex shader base.v.hlsl and pixel shader sunbeams.p.hlsl, then finalizes it.
// @fnv 0x00b8bf10
void __fastcall RegisterSunbeamsShader(FUN_00b8bf10_Obj* self, int unused)
{
    FUN_00b8bf10_Desc a;
    FUN_00b8bf10_Desc b;
    a.file = "imagespace\\1x\\v\\base.v.hlsl";
    a.flags = 0;
    fnv_zlib_memset(&a.r0, 0, 0x44);
    b.file = "imagespace\\2x\\p\\sunbeams.p.hlsl";
    b.flags = 0;
    fnv_zlib_memset(&b.r0, 0, 0x44);
    reinterpret_cast<FUN_00b8bf10_Add>(self->vt[0x13c / 4])(self, &a, &b, "Sunbeams", "vs_1_1", "ps_2_a");
    reinterpret_cast<FUN_00b8bf10_Fin>(self->vt[0x14c / 4])(self);
}

namespace fnv_00b8c070 {
extern int DAT_010b0318;
extern int DAT_010b0338;

struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
    char pad[0x94];
};


struct FUN_00b8c070 : ImageSpaceEffectShader
{
    ShaderTextureArrayStorage m;
    FUN_00b8c070();
};

// @fnv 0x00b8c070
FUN_00b8c070::FUN_00b8c070()
{
    *(int**)this = &DAT_010b0338;
    *(int**)((char*)this + 0x6c) = &DAT_010b0318;
    reinterpret_cast<NiTPrimitiveArray<ImageSpaceTexture*>*>(&m)->SetSize(4);
}
}  // namespace fnv_00b8c070

extern int DAT_010affa0;
extern int DAT_010affc0;
struct H_00c03a20
{
    void __thiscall FUN_00c03a20();
};
void __cdecl _delete(void*, unsigned int);
struct S_00b8bd50
{
    void* __thiscall FUN_00b8bd50(unsigned int);
};
// @fnv 0x00b8bd50
void* __thiscall S_00b8bd50::FUN_00b8bd50(unsigned int flags)
{
    *(int*)this = (int)&DAT_010affc0;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010affa0;
    ((H_00c03a20*)this)->FUN_00c03a20();
    if (flags & 1)
        _delete(this, 0xd0);
    return this;
}

struct Obj
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
};
// @fnv 0x00b8b3b0
void ImageSpaceManager::SetupShader()
{
    for (unsigned int i = 0x88; i < 0x1D0; i += 4)
    {
        if (*(char**)((char*)(*reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(pEffectList)).m_pBase + i))
        {
            char* pEntry = *(char**)((char*)(*reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(pEffectList)).m_pBase + i);
            Obj* o = pEntry ? (Obj*)(pEntry - 0x6C) : 0;
            o->f72();
        }
    }
}

extern int DAT_010b0198;
extern int DAT_010b0174;
void __cdecl _delete(void*, unsigned int);
struct UnkClass
{
    void FUN_00c03a20();
    void* DestroyIfFlagged(unsigned int);
};
// Resets two vtable pointers, calls FUN_00c03a20, and deletes this with size 0xd0 when flag bit 0 is set, returning this.
// @fnv 0x00b8bfa0
void* UnkClass::DestroyIfFlagged(unsigned int auiFlags)
{
    *(int**)this = &DAT_010b0198;
    *(int**)((char*)this + 0x6c) = &DAT_010b0174;
    FUN_00c03a20();
    if (auiFlags & 1)
        _delete(this, 0xd0);
    return this;
}

// @fnv 0x00b8aea0
void ImageSpaceManager::ResetWeatherData()
{
    char* self = reinterpret_cast<char*>(this);
    float* p = (float*)(self + 0x14c);
    int i = 0xf;
    for (; i; --i)
    {
        p[-0x26] = 1.0f;
        *p = 0.0f;
        ++p;
    }
    *(float*)(self + 0xf0) = 1.0f;
    *(float*)(self + 0xf4) = 1.0f;
    *(float*)(self + 0xf8) = 1.0f;
    *(float*)(self + 0x188) = 0.0f;
    *(float*)(self + 0x18c) = 0.0f;
    *(float*)(self + 0x190) = 0.0f;
    p = (float*)(self + 0x1b0);
    for (i += 0xc; i; --i)
    {
        p[-0x26] = 1.0f;
        *p = 0.0f;
        ++p;
    }
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long ulValue);


// Swap the header from big-endian.
// @fnv 0x00b8ad00
void ImageSpaceModifierParameterData::Endian()
{
    for (int i = 0; i < 15; i++)
        reinterpret_cast<unsigned int*>(m_afFirstParameterSet)[i] = _byteswap_ulong(reinterpret_cast<unsigned int*>(m_afFirstParameterSet)[i]);
    for (int j = 0; j < 3; j++)
        reinterpret_cast<unsigned int*>(m_afSecondParameterSet)[j] = _byteswap_ulong(reinterpret_cast<unsigned int*>(m_afSecondParameterSet)[j]);
    for (int j = 0; j < 3; j++)
        reinterpret_cast<unsigned int*>(m_afThirdParameterSet)[j] = _byteswap_ulong(reinterpret_cast<unsigned int*>(m_afThirdParameterSet)[j]);
    for (int j = 0; j < 12; j++)
        reinterpret_cast<unsigned int*>(m_afColorAndAlphaParameters)[j] = _byteswap_ulong(reinterpret_cast<unsigned int*>(m_afColorAndAlphaParameters)[j]);
    ShaderConstantData = _byteswap_ulong(ShaderConstantData);
}

extern ImageSpaceModifierParameterData DAT_011ff940;

// @fnv 0x00b8ad70
// src: COMMUNITY 0x00b8ad70
void __cdecl ImageSpaceManager_InitDefaultImagespaceValues()
{
    DAT_011ff940.m_afFirstParameterSet[0] = 0.5f;
    DAT_011ff940.m_afFirstParameterSet[1] = 7.0f;
    DAT_011ff940.m_afFirstParameterSet[3] = 1.0f;
    DAT_011ff940.m_afFirstParameterSet[4] = 1.0f;
    DAT_011ff940.m_afFirstParameterSet[5] = 1.0f;
    DAT_011ff940.m_afFirstParameterSet[6] = 2.25f;
    DAT_011ff940.m_afFirstParameterSet[7] = 0.225f;
    DAT_011ff940.m_afFirstParameterSet[8] = 1.0f;
    DAT_011ff940.m_afFirstParameterSet[9] = 0.0f;
    DAT_011ff940.m_afFirstParameterSet[10] = 0.0f;
    DAT_011ff940.m_afFirstParameterSet[11] = 1.5f;
    DAT_011ff940.m_afFirstParameterSet[12] = 1.5f;
    DAT_011ff940.m_afFirstParameterSet[13] = 1.0f;
    DAT_011ff940.m_afFirstParameterSet[2] = 1.0f;
    DAT_011ff940.m_afSecondParameterSet[0] = 0.03f;
    DAT_011ff940.m_afSecondParameterSet[2] = 0.2f;
    DAT_011ff940.m_afSecondParameterSet[1] = 0.7f;
    DAT_011ff940.m_afThirdParameterSet[0] = 0.5f;
    DAT_011ff940.m_afThirdParameterSet[1] = 0.5f;
    DAT_011ff940.m_afThirdParameterSet[2] = 0.02f;
    DAT_011ff940.m_afFourthParameterSet[3] = 2.5f;
    DAT_011ff940.m_afFourthParameterSet[0] = 0.21f;
    DAT_011ff940.m_afFourthParameterSet[1] = 0.5f;
    DAT_011ff940.m_afFourthParameterSet[2] = 0.78f;
    DAT_011ff940.m_afColorAndAlphaParameters[3] = 1.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[2] = 1.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[0] = 1.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[4] = 1.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[5] = 1.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[6] = 1.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[8] = 1.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[9] = 1.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[10] = 1.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[1] = 0.5f;
    DAT_011ff940.m_afColorAndAlphaParameters[7] = 0.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[11] = 0.0f;
}


// If fPriority exceeds the stored priority, stores the priority, type, four float parameters and the pair.
// @fnv 0x00b8b060
void ImageSpaceManager::SetIfHigherPriority(float fPriority, unsigned int iType, float fA, float fB, float fC, float fD,
                                           const NiPoint2& kPair)
{
    if (fPriority > fHighestDepthRadialBlurStrengthValue)
    {
        fHighestDepthRadialBlurStrengthValue = fPriority;
        fCurrentDepthRadialBlurRampupValue = fC;
        fCurrentDepthRadialBlurStartValue = fD;
        fCurrentDepthRadialBlurCenter = kPair;
        fCurrentDepthRadialBlurDistance = fA;
        fCurrentDepthRadialBlurMode = iType;
        fCurrentDepthRadialBlurRange = fB;
    }
}

extern ::NiCamera* DAT_011f917c;
using ::sqrt;

int __cdecl ImageSpaceEffectRadialBlur_GetBoundParams(int, int, int*);


// @fnv 0x00b8b7d0
void ImageSpaceManager::ApplyDepthOfFieldModifier(float afParam0, unsigned int aiParam1, float afParam2, float afParam3,
                                                 const NiBound& bound)
{
    const ::NiPoint3* pPosition = reinterpret_cast<const ::NiPoint3*>(&bound);
    ::NiCamera* g = DAT_011f917c;
    ::NiPoint3 gp = *reinterpret_cast<const ::NiPoint3*>(&g->m_kWorld.m_Translate);
    ::NiPoint3 pos = *pPosition;
    ::NiPoint3 d = pos;
    d.x = pos.x - gp.x;
    d.y = pos.y - gp.y;
    d.z = pos.z - gp.z;
    float t = d.x * d.x + d.y * d.y + d.z * d.z;
    t = (float)sqrt((double)t);
    float dist = t;
    ImageSpaceEffectRadialBlur_GetBoundParams((int)pPosition, (int)&pos, (int*)&t);
    t = t + afParam3;
    SetIfHigherPriority(afParam0, aiParam1, dist, dist, afParam2, t, *reinterpret_cast<const NiPoint2*>(&pos));
}

extern "C" void FUN_00ec61c0(void* a, unsigned int b, unsigned int c);
extern "C" void* FUN_00e7f5d0();

class ISPassCore
{
  public:
    void SetNodeValue(unsigned int a, unsigned int b, unsigned int c);
};

class ISPassHolder
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    ISPassCore* m_30;
};

struct FUN_00b8bdb0_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c(void* a, void* b, const char* c, const char* d, const char* e);
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    ISPassHolder* m_5c;
    void InitScanBlendPass();
};

// Sets up the IFVATSSCANBLEND shader with its vertex/pixel sources and configures three pass core entries on m_5c.
// @fnv 0x00b8bdb0
void FUN_00b8bdb0_cls::InitScanBlendPass()
{
    unsigned int f[0x26];
    f[0x13] = (unsigned int)"imagespace\\1x\\v\\base.v.hlsl";
    f[0x14] = 0;
    FUN_00ec61c0(&f[0x15], 0, 0x44);
    f[0] = (unsigned int)"imagespace\\2x\\p\\scanlines_blend.p.hlsl";
    f[1] = (unsigned int)"BLURSRC1";
    f[2] = 0;
    f[3] = (unsigned int)"VATS";
    f[4] = 0;
    f[5] = 0;
    FUN_00ec61c0(&f[6], 0, 0x34);
    this->v13c((void*)&f[0x13], (void*)&f[0], "IFVATSSCANBLEND", "vs_1_1", "ps_2_0");
    this->v14c();
    ISPassHolder* a = (ISPassHolder*)this->m_5c;
    if (a->m_30 == 0)
        a->m_30 = (ISPassCore*)FUN_00e7f5d0();
    a->m_30->SetNodeValue(0x1b, 1, 1);
    ISPassHolder* b = (ISPassHolder*)this->m_5c;
    if (b->m_30 == 0)
        b->m_30 = (ISPassCore*)FUN_00e7f5d0();
    b->m_30->SetNodeValue(0x13, 5, 1);
    if (b->m_30 == 0)
        b->m_30 = (ISPassCore*)FUN_00e7f5d0();
    b->m_30->SetNodeValue(0x14, 6, 1);
}

extern ::MemoryManager _g_memoryManager;
inline void MemFree(void* p)
{
    _g_memoryManager.Deallocate(p);
}

class CachedEntry : public NiRefObject
{
  public:
    NiPointer<NiRefObject> spObj08;
    int unk0C;
    void* pData10;
    int unk14;
    NiPointer<NiRefObject> spObj18;
    NiPointer<NiRefObject> spObj1C;
    NiPointer<NiRefObject> spObj20;
    NiPointer<NiRefObject> spObj24;
};



class CachedEntryMap
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    NiTMapItem<const char*, NiPointer<CachedEntry> >** m_ppkHashTable;
    unsigned int m_uiCount;

    void* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
    unsigned int GetCount() const
    {
        return m_uiCount;
    }
    __declspec(noinline) void GetNext(void*& pos, const char*& key, NiPointer<CachedEntry>& val) const
    {
        NiTMapItem<const char*, NiPointer<CachedEntry> >* pItem = (NiTMapItem<const char*, NiPointer<CachedEntry> >*)pos;
        key = pItem->m_key;
        val = pItem->m_val;
        pos = pItem->m_pkNext;
    }
    void RemoveAll();
};

CachedEntryMap* __cdecl GetCachedEntryMap();
void __cdecl ClearOtherCachedMap();

// Clears another cached map, then walks the cached entry map releasing each entry's pointers and data, and removes all entries.
// @fnv 0x00b59940
void __cdecl ClearCachedEntryMap()
{
    ClearOtherCachedMap();
    void* pos = GetCachedEntryMap()->GetFirstPos();
    const char* key;
    NiPointer<CachedEntry> spEntry;
    if (GetCachedEntryMap()->GetCount() > 0)
    {
        while (pos)
        {
            GetCachedEntryMap()->GetNext(pos, key, spEntry);
            if (spEntry)
            {
                spEntry->spObj08 = 0;
                MemFree(spEntry->pData10);
                spEntry->pData10 = 0;
                spEntry->spObj18 = 0;
                spEntry->spObj20 = 0;
                spEntry->spObj1C = 0;
                spEntry->spObj24 = 0;
            }
        }
        GetCachedEntryMap()->RemoveAll();
    }
}

typedef NiTArray<ImageSpaceEffectParam*, NiTMallocInterface<ImageSpaceEffectParam*> > ParamArray_b8b;


// Shuts down and destroys each effect, clears the array entries, and resets its size counters.
// @fnv 0x00b8b2e0
void ImageSpaceManager::ShutdownEffects()
{
    for (int i = 0; i < ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_COUNT; i++)
    {
        ImageSpaceEffect* pkEffect = (*reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(pEffectList)).m_pBase[i];
        if (pkEffect)
        {
            pkEffect->Shutdown();
            pkEffect->Destroy(true);
            ImageSpaceEffectParam* pkNull = 0;
            ((ParamArray_b8b*)&(*reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(pEffectList)))->SetAt(i, pkNull);
        }
    }
    for (unsigned short j = 0; j < (*reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(pEffectList)).m_usSize; j++)
        (*reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(pEffectList)).m_pBase[j] = 0;
    (*reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(pEffectList)).m_usSize = 0;
    (*reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(pEffectList)).m_usESize = 0;
}


struct ImageSpaceShaderParamGlobal
{
    void Init(int, int);
};
extern ImageSpaceShaderParamGlobal g_01202410;

extern ::BSTextureManager* DAT_011f91a8;
extern int DAT_011f4748;

// Initializes shaders, textures, effects, params and a rendered texture once, guarded by a TLS alloc-state guard and a one-time flag.
// @fnv 0x00b977d0
void ImageSpaceManager::Initialize()
{
    ::AutoMemContext kGuard(0x27);
    if (!bIsReady)
    {
        InitEffects();
        CreateMenuBackgroundGeometry();
        bIsReady = true;
        SetupEffects();
        g_01202410.Init(0, 0);
        InitDefaultParameter();
        NiColorA kTint;
        kTint.b = kTint.g = kTint.r = 0.0f;
        kTint.a = 0.3f;
        kRefractionTint = kTint;
        (*reinterpret_cast<NiRect<float>*>(CustomViewPort)).m_fMinimumU = 0.0f;
        (*reinterpret_cast<NiRect<float>*>(CustomViewPort)).m_fMaximumU = 1.0f;
        (*reinterpret_cast<NiRect<float>*>(CustomViewPort)).m_fMinimumV = 1.0f;
        (*reinterpret_cast<NiRect<float>*>(CustomViewPort)).m_fMaximumV = 0.0f;
        pEOFDest = 0;
        pSwapTarget = reinterpret_cast<BSRenderedTexture*>(
            DAT_011f91a8->CreateRenderTargetTexture(reinterpret_cast<::NiRenderer*>(DAT_011f4748), 3, 0, 0, 0));
    }
}

// 0x00b8bda0  mov al,[ecx+4]; ret
struct C00b8bda0
{
    char pad00[0x4];
    unsigned char m4;
    unsigned char ImageSpaceEffect_IsActive();
};

// @fnv 0x00b8bda0
// src: COMMUNITY 0x00b8bda0
unsigned char C00b8bda0::ImageSpaceEffect_IsActive()
{
    return m4;
}


__declspec(noinline) void ImageSpaceManager::FUN_00b8b540(NiColorA& color)
{
    fHighestTintValue = color.a;
}

__declspec(noinline) void ImageSpaceManager::FUN_00b8b610(NiColorA& color)
{
    fHighestFadeValue = color.a;
}


// Blends weather values into image-space settings and raises blur, radial blur, depth-of-field and motion-blur strengths to their maxima.
// @fnv 0x00b8ccb0
void ImageSpaceManager::EndWeatherModifiers()
{
    for (int i = 0; i < 15; i++)
    {
        float afWeatherValues[2];
        afWeatherValues[0] = (*reinterpret_cast<ImageSpaceModifierParameterData (*)[2]>(WeatherParameterData))[0].m_afFirstParameterSet[i];
        afWeatherValues[1] = (*reinterpret_cast<ImageSpaceModifierParameterData (*)[2]>(WeatherParameterData))[1].m_afFirstParameterSet[i];
        ::AutoMemContext ctx(0x27);
        float val = (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afFirstParameterSet[i];
        for (int j = 0; j < 2; j++)
        {
            float elem = afWeatherValues[j];
            float result = 0.0f;
            switch (j)
            {
            case 0:
                result = elem * val;
                break;
            case 1:
                result = elem + val;
                break;
            }
            val = result;
        }
        float diff = (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afFirstParameterSet[i] - val;
        (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afFirstParameterSet[i] -= diff;
    }

    for (int i = 0; i < 3; i++)
    {
        float afWeatherValues[2];
        afWeatherValues[0] = (*reinterpret_cast<ImageSpaceModifierParameterData (*)[2]>(WeatherParameterData))[0].m_afSecondParameterSet[i];
        afWeatherValues[1] = (*reinterpret_cast<ImageSpaceModifierParameterData (*)[2]>(WeatherParameterData))[1].m_afSecondParameterSet[i];
        ::AutoMemContext ctx(0x27);
        float val = (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afSecondParameterSet[i];
        for (int j = 0; j < 2; j++)
        {
            float elem = afWeatherValues[j];
            float result = 0.0f;
            switch (j)
            {
            case 0:
                result = elem * val;
                break;
            case 1:
                result = elem + val;
                break;
            }
            val = result;
        }
        float diff = (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afSecondParameterSet[i] - val;
        (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afSecondParameterSet[i] -= diff;
    }

    for (int i = 0; i < 12; i++)
    {
        float afWeatherValues[2];
        afWeatherValues[0] = (*reinterpret_cast<ImageSpaceModifierParameterData (*)[2]>(WeatherParameterData))[0].m_afColorAndAlphaParameters[i];
        afWeatherValues[1] = (*reinterpret_cast<ImageSpaceModifierParameterData (*)[2]>(WeatherParameterData))[1].m_afColorAndAlphaParameters[i];
        ::AutoMemContext ctx(0x27);
        float val = (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afColorAndAlphaParameters[i];
        for (int j = 0; j < 2; j++)
        {
            float elem = afWeatherValues[j];
            float result = 0.0f;
            switch (j)
            {
            case 0:
                result = elem * val;
                break;
            case 1:
                result = elem + val;
                break;
            }
            val = result;
        }
        float diff = (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afColorAndAlphaParameters[i] - val;
        (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afColorAndAlphaParameters[i] -= diff;
    }

    FUN_00b8b540(kWeatherTintColor);
    FUN_00b8b610(kWeatherFadeColor);

    float fBlurStrength = fWeatherBlurValue;
    if (fBlurStrength > fHighestBlurValue)
    {
        fHighestBlurValue = fBlurStrength;
    }

    float fWeatherDouble = fWeatherDoubleValue;
    if (fWeatherDouble > fHighestDoubleValue)
    {
        fHighestDoubleValue = fWeatherDouble;
    }

    float fWeatherRadialBlurStrength = fWeatherRadialBlurStrengthValue;
    if (fWeatherRadialBlurStrength > fHighestRadialBlurStrengthValue)
    {
        fHighestRadialBlurStrengthValue = fWeatherRadialBlurStrength;
        fCurrentRadialBlurRampupValue = fWeatherRadialBlurRampupValue;
        fCurrentRadialBlurStartValue = fWeatherRadialBlurStartValue;
        fCurrentRadialBlurRampDownValue = fWeatherRadialBlurRampDownValue;
        fCurrentRadialBlurDownStartValue = fWeatherRadialBlurDownStartValue;
        fCurrentRadialBlurCenter = fWeatherRadialBlurCenter;
    }

    float fDOFStrength = fWeatherDOFStrengthValue;
    float fDOFDistance = fWeatherDOFDistanceValue;
    float fDOFRange = fWeatherDOFRangeValue;
    unsigned int dofMode = fWeatherDOFMode;

    if (fDOFStrength > fHighestDOFStrengthValue)
    {
        fHighestDOFStrengthValue = fDOFStrength;
        bCurrentDOFUseMask = false;
        if (dofMode > 2)
        {
            bCurrentDOFUseMask = true;
            dofMode -= 3;
        }
        fCurrentDOFMode = (ImageSpaceEffectDepthOfField__DepthOfFieldMode)dofMode;
        fCurrentDOFDistanceValue = fDOFDistance;
        fCurrentDOFRangeValue = fDOFRange;
        fCurrentDOFMaskConst = 0.0f;
    }

    float fMotionBlurStrength = fWeatherMotionBlurStrengthValue;
    if (fMotionBlurStrength > fHighestMotionBlurStrengthValue)
    {
        fHighestMotionBlurStrengthValue = fMotionBlurStrength;
    }
}

extern float DAT_01202400;
extern float DAT_012003d0;

struct ImageSpaceModifierRampState
{
    void* vtable;
    bool unk04;
    bool bActive;
    bool unk06;
    bool unk07;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    float fWaterLevelItem;
    float m_fRampUp;
    float fStart;
    float fRampDown;
    float m_fRampDownStart;
    NiPoint2 m_kCenter;

    void SetParams(float strength, float rampup, float start, float rampDown, float downStart, const NiPoint2& center)
    {
        fWaterLevelItem = strength;
        m_fRampUp = rampup;
        fStart = start;
        fRampDown = rampDown;
        m_fRampDownStart = downStart;
        m_kCenter = center;
    }
};

struct ImageSpaceEffectDepthOfFieldParams
{
    void* vtable;
    bool unk04;
    bool bActive;
    bool unk06;
    bool unk07;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    float fDistance;
    float fImpulseRadiusSquared;
    float fWaterLevelItem;
    ImageSpaceEffectDepthOfField__DepthOfFieldMode eMode;
    float m_fMaskConstant;

    void SetStrength(float strength)
    {
        bActive = true;
        fWaterLevelItem = strength;
    }
    void SetDistance(float distance)
    {
        bActive = true;
        fDistance = distance;
    }
    void SetRange(float range)
    {
        fImpulseRadiusSquared = range;
        bActive = true;
    }
    void SetMode(ImageSpaceEffectDepthOfField__DepthOfFieldMode mode)
    {
        if (mode != eMode)
        {
            bActive = true;
            eMode = mode;
        }
    }
    void ImageSpaceEffectDepthOfField_DoMasked();
    void ImageSpaceEffectDepthOfField_DoStandard();
};

struct ImageSpaceEffectDepthRadialBlurParams
{
    void* vtable;
    bool unk04;
    bool bActive;
    bool unk06;
    bool unk07;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    float fWaterLevelItem;
    int unk70;
    int unk74;
    int unk78;
    float fNear;
    float fFar;
    float fDistance;
    int unk88;
    float fStrength2;
    float m_fRampUp;
    float fStart;
    int unk98;
    float fImpulseRadiusSquared;

    void SetStrength(float strength)
    {
        bActive = true;
        fWaterLevelItem = strength;
    }
    void SetDistance(float dist)
    {
        float r = fImpulseRadiusSquared;
        if (fImpulseRadiusSquared < dist)
        {
            r = dist;
        }
        fDistance = dist;
        bActive = true;
        fNear = dist - r;
        fFar = dist + r;
    }
    void SetRange(float range)
    {
        bActive = true;
        fImpulseRadiusSquared = range;
        fNear = fDistance - range;
        fFar = fDistance + range;
    }
    void SetParams(float strength, float rampup, float start)
    {
        fStrength2 = strength;
        m_fRampUp = rampup;
        fStart = start;
    }
    void ImageSpaceEffectDepthRadialBlur_SetMode(ImageSpaceEffectDepthRadialBlur__RadialBlurMode mode);
};

struct ImageSpaceModifierStrengthState
{
    void* vtable;
    bool unk04;
    bool bActive;
    bool unk06;
    bool unk07;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    float fWaterLevelItem;

    void SetStrength(float strength)
    {
        bActive = true;
        fWaterLevelItem = strength;
    }
};


// @fnv 0x00b8d020
void ImageSpaceManager::EndParamModifiers()
{
    if (kTintColor.a > 0.0f)
    {
        float a = kTintColor.a;
        kTintColor.r /= a;
        kTintColor.g /= a;
        kTintColor.b /= a;
        kTintColor.a /= a;
    }
    float tint = fHighestTintValue;
    kTintColor.a = tint;
    (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afColorAndAlphaParameters[4] = kTintColor.r;
    (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afColorAndAlphaParameters[5] = kTintColor.g;
    (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afColorAndAlphaParameters[6] = kTintColor.b;
    (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afColorAndAlphaParameters[7] = tint;

    if (kFadeColor.a > 0.0f)
    {
        float a = kFadeColor.a;
        kFadeColor.r /= a;
        kFadeColor.g /= a;
        kFadeColor.b /= a;
        kFadeColor.a /= a;
    }
    float fade = fHighestFadeValue;
    kFadeColor.a = fade;
    (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afColorAndAlphaParameters[8] = kFadeColor.r;
    (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afColorAndAlphaParameters[9] = kFadeColor.g;
    (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afColorAndAlphaParameters[10] = kFadeColor.b;
    (*reinterpret_cast<ImageSpaceModifierParameterData*>(CurrentParameterData)).m_afColorAndAlphaParameters[11] = fade;

    DAT_01202400 = fHighestDoubleValue;
    DAT_012003d0 = fHighestBlurValue;

    ImageSpaceModifierRampState* pRadialBlur =
        (ImageSpaceModifierRampState*)(*reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(pEffectList)).m_pBase[ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_RADIAL_BLUR];
    pRadialBlur->SetParams(fHighestRadialBlurStrengthValue, fCurrentRadialBlurRampupValue, fCurrentRadialBlurStartValue, fCurrentRadialBlurRampDownValue,
                           fCurrentRadialBlurDownStartValue, fCurrentRadialBlurCenter);

    ImageSpaceEffectDepthOfFieldParams* pDOF =
        (ImageSpaceEffectDepthOfFieldParams*)
            (*reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(pEffectList)).m_pBase[ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_DEPTH_OF_FIELD];
    pDOF->SetStrength(fHighestDOFStrengthValue);
    pDOF->SetDistance(fCurrentDOFDistanceValue);
    pDOF->SetRange(fCurrentDOFRangeValue);
    pDOF->m_fMaskConstant = fCurrentDOFMaskConst;
    pDOF->SetMode(static_cast<ImageSpaceEffectDepthOfField__DepthOfFieldMode>(fCurrentDOFMode));
    if (bCurrentDOFUseMask)
    {
        pDOF->ImageSpaceEffectDepthOfField_DoMasked();
    }
    else
    {
        pDOF->ImageSpaceEffectDepthOfField_DoStandard();
    }

    ImageSpaceEffectDepthRadialBlurParams* pDepthRadialBlur =
        (ImageSpaceEffectDepthRadialBlurParams*)
            (*reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(pEffectList)).m_pBase[ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_DEPTH_RADIAL_BLUR];
    pDepthRadialBlur->SetStrength(fHighestDepthRadialBlurStrengthValue);
    pDepthRadialBlur->SetDistance(fCurrentDepthRadialBlurDistance);
    pDepthRadialBlur->SetRange(fCurrentDepthRadialBlurRange);
    pDepthRadialBlur->ImageSpaceEffectDepthRadialBlur_SetMode(static_cast<ImageSpaceEffectDepthRadialBlur__RadialBlurMode>(fCurrentDepthRadialBlurMode));
    pDepthRadialBlur->SetParams(fHighestDepthRadialBlurStrengthValue, fCurrentDepthRadialBlurRampupValue, fCurrentDepthRadialBlurStartValue);

    ImageSpaceModifierStrengthState* pMotionBlur =
        (ImageSpaceModifierStrengthState*)
            (*reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(pEffectList)).m_pBase[ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_MOTION_BLUR];
    pMotionBlur->SetStrength(fHighestMotionBlurStrengthValue);
}

#include <math.h>
using ::sqrt;
using ::fabs;

extern "C" void* __cdecl memmove(void*, const void*, unsigned);

struct Vec2
{
    float x, y;
    Vec2(float a, float b) : x(a), y(b)
    {}
    Vec2 operator-(const Vec2& b) const
    {
        return Vec2(x - b.x, y - b.y);
    }
    Vec2& operator-=(const Vec2& b)
    {
        x -= b.x;
        y -= b.y;
        return *this;
    }
    float Length() const
    {
        return sqrt(x * x + y * y);
    }
};
struct Matrix
{
    float m[4][4];
};
extern ::NiCamera* DAT_011f9684;
// Transforms a 3D position with the camera matrix, maps it through the viewport, and computes a capped radius from the input r offset.
// @fnv 0x00b59d30
// src: COMMUNITY 0x00b59d30
NiPoint2* ImageSpaceEffectRadialBlur_GetBoundParams(::Vec4* apPoint, NiPoint2* apScreenPos, float* radius)
{
    ::NiCamera* camera = DAT_011f9684;
    ::NiPoint3 position = *(::NiPoint3*)apPoint;
    NiRect<float> vViewport = camera->m_kPort;
    bool bBehindCamera = false;
    Matrix matrix;
    memmove(&matrix, &camera->m_aafWorldToCam, sizeof(matrix));
    float w = position.x * matrix.m[3][0] + position.y * matrix.m[3][1] + position.z * matrix.m[3][2] + matrix.m[3][3];
    if (w < 0.0f)
        bBehindCamera = true;
    w = fabs(w);
    float fInvW = 1.0f / w;
    float x = position.x * matrix.m[0][0] + position.y * matrix.m[0][1] + position.z * matrix.m[0][2] + matrix.m[0][3];
    x *= fInvW;
    float y = position.x * matrix.m[1][0] + position.y * matrix.m[1][1] + position.z * matrix.m[1][2] + matrix.m[1][3];
    y *= fInvW;
    if ((x >= -1.0f && x <= 1.0f && y >= -1.0f && y <= 1.0f) || !bBehindCamera)
    {
        position.z += apPoint->w;
        float newW =
            position.x * matrix.m[3][0] + position.y * matrix.m[3][1] + position.z * matrix.m[3][2] + matrix.m[3][3];
        Vec2 vInitial(x, 1.0f - y);
        float nextX =
            position.x * matrix.m[0][0] + position.y * matrix.m[0][1] + position.z * matrix.m[0][2] + matrix.m[0][3];
        nextX /= newW;
        float nextY =
            position.x * matrix.m[1][0] + position.y * matrix.m[1][1] + position.z * matrix.m[1][2] + matrix.m[1][3];
        nextY /= newW;
        Vec2 vNext(nextX, 1.0f - nextY);
        Vec2 vDifference = vInitial;
        vDifference -= vNext;
        float size = vDifference.Length();
        size = size * 0.5;
        *radius = size;
        if (*radius > 0.5f)
            *radius = 0.5f;
    }
    else
    {
        *radius = 0.3f;
    }
    position.x = (vViewport.m_fMaximumU - vViewport.m_fMinimumU) * 0.5 * x;
    NiPoint2 result;
    result.x = position.x + (vViewport.m_fMaximumU + vViewport.m_fMinimumU) * 0.5;
    position.x = (vViewport.m_fMinimumV - vViewport.m_fMaximumV) * 0.5 * y;
    result.y = position.x + (vViewport.m_fMinimumV + vViewport.m_fMaximumV) * 0.5;
    result.y = 1.0f - result.y;
    if (result.x > 1.0f)
        result.x = 1.0f;
    else if (result.x < 0.0f)
        result.x = 0.0f;
    if (result.y > 1.0f)
        result.y = 1.0f;
    else if (result.y < 0.0f)
        result.y = 0.0f;
    if (bBehindCamera)
    {
        if (result.x <= 0.0f)
            result.x = 0.0f;
        else if (result.x > 0.0f)
            result.x = 1.0f;
    }
    *apScreenPos = result;
    return apScreenPos;
}

void __cdecl ImageSpaceEffectRadialBlur_GetBoundParams(int a1, int* a2, float* a3);
// Projects the bound and applies its projected radius to the radial-blur start and down-start.
// The original reuses the bound argument slot for the radius output.
// @fnv 0x00b8b760
// src: XBOX_PDB 0x00b8b760
void ImageSpaceManager::ApplyRadialBlurParamModifier(float a1, float a2, float a3, float a4, float a5, const NiBound& bound)
{
    int local[2];
    ImageSpaceEffectRadialBlur_GetBoundParams(reinterpret_cast<int>(&bound), local, &a5 + 1);
    SetRadialBlurParameters(a1, a2, *(&a5 + 1) + a3, a4, *(&a5 + 1) + a5,
                            *reinterpret_cast<const NiPoint2*>(local));
}

extern ::NiCamera* DAT_011f917c;
// Computes the distance from the camera world position and passes it as both depth-of-field bounds.
// @fnv 0x00b8b8d0
void ImageSpaceManager::SetDistanceEffect(float strength, unsigned int mode, float duration, const NiBound& bound)
{
    const ::NiPoint3* position = reinterpret_cast<const ::NiPoint3*>(&bound);
    const ::NiPoint3 worldPosition = *reinterpret_cast<const ::NiPoint3*>(&DAT_011f917c->m_kWorld.m_Translate);
    const volatile ::NiPoint3 sample = *position;
    // Built as plain data (the original constructs no NiPoint3 here).
    const PointStorage delta = {sample.x - worldPosition.x, sample.y - worldPosition.y, sample.z - worldPosition.z};
    const float distance = reinterpret_cast<const ::NiPoint3&>(delta).Length();
    SetDepthOfFieldParameters(strength, mode, duration, distance, distance);
}

namespace fnv_00b8bb70 {

extern ::NiCamera* DAT_011f917c;
static __forceinline float Dot(::NiPoint3 a, ::NiPoint3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// Computes the distance between the camera position and a given point, storing the result in both elements of the output array.
// @fnv 0x00b8bb70
// src: COMMUNITY 0x00b8bb70
void __stdcall ImageSpaceManager_GetDepthOfFieldParamsFromPoint(::NiPoint3* apPoint, float* out)
{
    ::NiPoint3 g;
    g = DAT_011f917c->m_kWorld.m_Translate;
    ::NiPoint3 pPoint;
    pPoint = *apPoint;
    ::NiPoint3 d = pPoint - g;
    float l = sqrtf(Dot(d, d));
    out[0] = l;
    out[1] = l;
}
}  // namespace fnv_00b8bb70


// Sets BSAudioThreadContext to 0x27, selects a float by mode, applies two operations from arr and blends toward the result using w, then restores the context.
// @fnv 0x00b8cb30
// src: COMMUNITY 0x00b8cb30
void ImageSpaceManager::ApplyParamModifier_00b8cb30(int mode, int aiIndex, float* apValues, float afWeight)
{
    int iSavedContext = BSAudioThreadContext;
    BSAudioThreadContext = 0x27;

    float* p = 0;
    switch (mode)
    {
    case 0:
        p = (float*)((char*)this + aiIndex * 4 + 0x50);
        break;
    case 1:
        p = (float*)((char*)this + aiIndex * 4 + 0x14);
        break;
    case 3:
        p = (float*)((char*)this + aiIndex * 4 + 0x78);
        break;
    }

    float fValue = *p;
    float fAccum = 0.0f;
    float t = fAccum;
    for (int i = 0; i < 2; i++)
    {
        float a = apValues[i];
        t = fAccum;
        switch (i)
        {
        case 0:
            t = a * fValue;
            break;
        case 1:
            t = a + fValue;
            break;
        }
        fValue = t;
    }

    *p = *p - (float)(*p - t) * afWeight;

    BSAudioThreadContext = iSavedContext;
}

// Adjustor thunk for FUN_00b8bd80: "sub ecx, 0x6c; jmp FUN_00b8bd50".
//
// MSVC emits a this-adjusting thunk for a virtual that a class inherits from a
// secondary base: the thunk receives the secondary base sub-object pointer
// (this + 0x6c), moves it back to the derived object (sub ecx, 0x6c) and
// tail jumps to the final overrider.
//
// The subtracted constant is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 26 int members (4 + 26 * 4 = 0x6c).
// Both bases declare the same virtual function, the derived class redeclares
// it and only defines its constructor, which is what makes the compiler emit
// the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00b8bd80();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00b8bd80();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b8bd80
// src: GUESS 0x00b8bd80 (confidence: low)
    virtual void AdjustThisAndForward_00b8bd80();
};

Derived::Derived()
{}

namespace fnv_00b8bfd0 {
// Adjustor thunk: sub ecx,0x6c; jmp <base implementation>
// PrimaryBase = vptr + 26 int fields = 4 + 104 = 0x6c bytes.
struct PrimaryBase
{
    virtual void FUN_00b8bfd0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
};

struct SecondaryBase
{
    virtual void FUN_00b8bfd0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b8bfd0
    virtual void FUN_00b8bfd0();
};

Derived::Derived()
{}
}  // namespace fnv_00b8bfd0


void* __cdecl Object_DispatchCommandFour(unsigned int size);
inline void* __cdecl operator new(unsigned int size)
{
    return Object_DispatchCommandFour(size);
}
void __cdecl operator delete(void*);

struct TLSData
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int currentHeap;
};

extern __declspec(thread) TLSData g_tlsData;

inline AutoMemContext::AutoMemContext(int newTag)
{
    m_eMemoryContext = static_cast<MEM_CONTEXT>(g_tlsData.currentHeap);
    g_tlsData.currentHeap = newTag;
}

inline AutoMemContext::~AutoMemContext()
{
    g_tlsData.currentHeap = m_eMemoryContext;
}


// Creates NiScreenElements, sets rectangle bounds and data using a1 and a2, then assigns the elements to a3.
// @fnv 0x00b8c3b0
void ImageSpaceManager::SetMenuBackgroundBlend(float afWidth, float afHeight,
                                                 void* screenElements)
{
    NiPointer<NiScreenElements>& apScreenElements = *static_cast<NiPointer<NiScreenElements>*>(screenElements);
    ::AutoMemContext memContext(0x27);
    NiPointer<NiScreenElementsData> spScreenData(new NiScreenElementsData(false, false, 1, 1, 1, 4, 1, 2, 1));
    (*reinterpret_cast<NiPointer<NiScreenElements>*>(spPartialScreenTriShape)) = ::new NiScreenElements(spScreenData);
    float width = afWidth * 2.0f;
    float height = afHeight * -2.0;
    (*reinterpret_cast<NiPointer<NiScreenElements>*>(spPartialScreenTriShape))->GetData()->FUN_00a87ae0(4, 0, 0);
    (*reinterpret_cast<NiPointer<NiScreenElements>*>(spPartialScreenTriShape))->GetData()->SetRectangleBounds(0, DAT_01012054, 1.0f, width, height);
    (*reinterpret_cast<NiPointer<NiScreenElements>*>(spPartialScreenTriShape))->GetData()->NiScreenElementsData_UpdateBound();
    (*reinterpret_cast<NiPointer<NiScreenElements>*>(spPartialScreenTriShape))->GetData()->FUN_00a88130(0, 0, 0.0f, 0.0f, afWidth, afHeight);
    (*reinterpret_cast<NiPointer<NiScreenElements>*>(spPartialScreenTriShape))->UpdateSceneObject();
    NiUpdateData updateData(0.0f);
    (*reinterpret_cast<NiPointer<NiScreenElements>*>(spPartialScreenTriShape))->NiAVObject::Update(updateData);
    (*reinterpret_cast<NiPointer<NiScreenElements>*>(spPartialScreenTriShape))->NiAVObject::SetName(::NiFixedString("Interface Effect Partial Screen Trishape"));
    apScreenElements = (*reinterpret_cast<NiPointer<NiScreenElements>*>(spPartialScreenTriShape));
}


