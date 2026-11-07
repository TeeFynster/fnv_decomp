// fallout_shared/tesimagespacemodifier.cpp: TESImageSpaceModifier, NiColorA, ImageSpaceModifierEffectData, NiColorInterpolator and more (37 functions)

#include "layout_support.h"
#include "../../include/ImageSpaceManager.h"
#include "../../include/ImageSpaceModifierEffectData.h"
#include "../../include/TESImageSpaceModifier.h"
#include "../../include/TESSound.h"
#include "../../include/NiColorData.h"
#include "../../include/NiPoint3.h"

#include <malloc.h>
void* __cdecl operator new(unsigned int);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);
extern "C" void* __cdecl memset(void*, int, unsigned int);
template <int N> struct EndianSizeTag
{
};
void BSEndian(unsigned int*, EndianSizeTag<4>);
class TimedAnimationKey
{
  public:
    float m_fTime;
};
class TimedFloatKey : public TimedAnimationKey
{
  public:
    float m_fValue;
    TimedFloatKey();
    ~TimedFloatKey();
    void TESRegionPoint_SetX(float);
    void FUN_004f5d90(float);
};
class ColorAnimationKey
{
  public:
    float m_fTime;
    NiColorA m_kRgbaColor;
};
class AlphaColor : public ColorAnimationKey
{
  public:
    AlphaColor();
    ~AlphaColor();
    void TESRegionPoint_SetX(float);
    void NiColorKey_SetColor(const NiColorA&);
};
class TESImageSpaceColorDataPointer
{
  public:
    NiColorData*& operator=(NiColorData*);
};
FNV_STATIC_ASSERT(sizeof(TESImageSpaceModifier::ImageSpaceModifierEffectData) == 0xf4);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, m_akFloatInterpolators) == 0x114);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pEffectEntryTable) == 0x654);
extern float DAT_0118aba0[2];
extern float DAT_0118aba8[2];

extern float DAT_011c96fc;
extern const float DAT_01018f98;
void BSClamp_float(float&, float, float);
extern TESImageSpaceModifier DAT_011c9750;
int __cdecl Warning(const char*, ...);
// Loads an IMAD record: reads the header, EDID/OBND/DNAM chunks and per-chunk arrays of entries, converting endianness and filling the linked lists.
// @fnv 0x0052d510
bool TESImageSpaceModifier::Load(TESFile* file)
{
    bool loadedData;
    unsigned char form = file->GetTESForm();
    if (form != ENUM_FORM_ID_IMAD_ID)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    loadedData = false;
    while (int chunk = file->GetChunkID())
    {
        switch (chunk)
        {
        case CHUNK_ID_EDID_ID: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case CHUNK_ID_OBND_ID:
            readOBNDSubRecord(file);
            break;
        case CHUNK_ID_DNAM_ID:
            file->GetChunkData(&Data, sizeof(Data));
            if (file->IsEndianConversionRequired())
                Data.Endian();
            loadedData = true;
            break;
        case CHUNK_ID_BNAM_ID: {
            unsigned int count = Data.m_uiEffectEntryCountSecond;
            pSecondEffectEntries = new TimedFloatKey[count];
            file->GetChunkData(pSecondEffectEntries, count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pSecondEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    BSEndian(&words[i], EndianSizeTag<4>());
            }
            m_kFloatInterpolatorOne.SetAnimationKeys(pSecondEffectEntries, count, NiAnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_VNAM_ID: {
            unsigned int count = Data.m_uiEffectEntryCountThird;
            pThirdEffectEntries = new TimedFloatKey[count];
            file->GetChunkData(pThirdEffectEntries, count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pThirdEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    BSEndian(&words[i], EndianSizeTag<4>());
            }
            m_kFloatInterpolatorTwo.SetAnimationKeys(pThirdEffectEntries, count, NiAnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_RNAM_ID: {
            unsigned int count = Data.m_uiEffectEntryCountFourth;
            pTenthEffectEntries = new TimedFloatKey[count];
            file->GetChunkData(pTenthEffectEntries, count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pTenthEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    BSEndian(&words[i], EndianSizeTag<4>());
            }
            m_kFloatInterpolatorNine.SetAnimationKeys(pTenthEffectEntries, count, NiAnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_SNAM_ID: {
            unsigned int count = Data.m_uiEffectEntryCountFifth;
            pEleventhEffectEntries = new TimedFloatKey[count];
            file->GetChunkData(pEleventhEffectEntries, count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pEleventhEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    BSEndian(&words[i], EndianSizeTag<4>());
            }
            m_kFloatInterpolatorTen.SetAnimationKeys(pEleventhEffectEntries, count, NiAnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_UNAM_ID: {
            unsigned int count = Data.m_uiEffectEntryCountSixth;
            pTwelfthEffectEntries = new TimedFloatKey[count];
            file->GetChunkData(pTwelfthEffectEntries, count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pTwelfthEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    BSEndian(&words[i], EndianSizeTag<4>());
            }
            m_kFloatInterpolatorEleven.SetAnimationKeys(pTwelfthEffectEntries, count, NiAnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_NAM1_ID: {
            unsigned int count = Data.m_uiEffectEntryCountTenth;
            pFourthEffectEntries = new TimedFloatKey[count];
            file->GetChunkData(pFourthEffectEntries, count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pFourthEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    BSEndian(&words[i], EndianSizeTag<4>());
            }
            m_kFloatInterpolatorThree.SetAnimationKeys(pFourthEffectEntries, count, NiAnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_NAM2_ID: {
            unsigned int count = Data.m_uiEffectEntryCountEleventh;
            pFifthEffectEntries = new TimedFloatKey[count];
            file->GetChunkData(pFifthEffectEntries, count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pFifthEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    BSEndian(&words[i], EndianSizeTag<4>());
            }
            m_kFloatInterpolatorFour.SetAnimationKeys(pFifthEffectEntries, count, NiAnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_TNAM_ID: {
            unsigned int count = Data.m_uiEffectEntryCountFirst;
            pFirstEffectRecordArray = new AlphaColor[count];
            file->GetChunkData(pFirstEffectRecordArray, count * sizeof(AlphaColor));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pFirstEffectRecordArray;
                for (unsigned int i = 0; i < count * sizeof(AlphaColor) / sizeof(unsigned int); ++i)
                    BSEndian(&words[i], EndianSizeTag<4>());
            }
            m_kColorInterpolatorOne.SetAnimationKeys(pFirstEffectRecordArray, count, NiAnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_NAM3_ID: {
            unsigned int count = Data.m_uiEffectEntryCountTwelfth;
            pSecondEffectRecordArray = new AlphaColor[count];
            file->GetChunkData(pSecondEffectRecordArray, count * sizeof(AlphaColor));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pSecondEffectRecordArray;
                for (unsigned int i = 0; i < count * sizeof(AlphaColor) / sizeof(unsigned int); ++i)
                    BSEndian(&words[i], EndianSizeTag<4>());
            }
            m_kColorInterpolatorTwo.SetAnimationKeys(pSecondEffectRecordArray, count, NiAnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_WNAM_ID: {
            unsigned int count = Data.m_uiEffectEntryCountSeventh;
            pSeventhEffectEntries = new TimedFloatKey[count];
            file->GetChunkData(pSeventhEffectEntries, count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pSeventhEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    BSEndian(&words[i], EndianSizeTag<4>());
            }
            m_kFloatInterpolatorFive.SetAnimationKeys(pSeventhEffectEntries, count, NiAnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_XNAM_ID: {
            unsigned int count = Data.m_uiEffectEntryCountEighth;
            pEighthEffectEntries = new TimedFloatKey[count];
            file->GetChunkData(pEighthEffectEntries, count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pEighthEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    BSEndian(&words[i], EndianSizeTag<4>());
            }
            m_kFloatInterpolatorSix.SetAnimationKeys(pEighthEffectEntries, count, NiAnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_YNAM_ID: {
            unsigned int count = Data.m_uiEffectEntryCountNinth;
            pNinthEffectEntries = new TimedFloatKey[count];
            file->GetChunkData(pNinthEffectEntries, count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pNinthEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    BSEndian(&words[i], EndianSizeTag<4>());
            }
            m_kFloatInterpolatorSeven.SetAnimationKeys(pNinthEffectEntries, count, NiAnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_NAM4_ID: {
            unsigned int count = Data.m_uiEffectEntryCountThirteenth;
            pSixthEffectEntries = new TimedFloatKey[count];
            file->GetChunkData(pSixthEffectEntries, count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pSixthEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    BSEndian(&words[i], EndianSizeTag<4>());
            }
            m_kFloatInterpolatorEight.SetAnimationKeys(pSixthEffectEntries, count, NiAnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_RDSD_ID: {
            unsigned int sound = 0;
            file->GetChunkData(&sound);
            pIntroSound = (TESSound*)sound;
            break;
        }
        case CHUNK_ID_RDSI_ID: {
            unsigned int sound = 0;
            file->GetChunkData(&sound);
            pOutroSound = (TESSound*)sound;
            break;
        }
        default:
            if (chunk >= 0x44414900 && chunk <= 0x444149ff)
            {
                unsigned int count;
                int column;
                int row = chunk & 0x3f;
                column = (chunk & 0xc0) >> 6;
                count = Data.m_auiKeyframeCountsByTypeAndChannel[row][column];
                pEffectEntryTable[row][column] = new TimedFloatKey[count];
                file->GetChunkData(pEffectEntryTable[row][column], count * sizeof(TimedFloatKey));
                if (file->IsEndianConversionRequired())
                {
                    unsigned int* words = (unsigned int*)pEffectEntryTable[row][column];
                    for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                        BSEndian(&words[i], EndianSizeTag<4>());
                }
                m_akFloatInterpolators[row][column].SetAnimationKeys(pEffectEntryTable[row][column], count,
                                                                     NiAnimationKey::LINKEY);
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x0052bd40
void TESImageSpaceModifier::ResetFormData()
{
    int i, j, kKey;
    memset(&Data, 0, sizeof(Data));
    Data.m_bOverride = false;
    Data.fDuration = 1.0f;
    Data.m_bUseRadialBlur = false;
    Data.m_kRadialBlurCenter = NiPoint2(0.5f, 0.5f);
    Data.m_bUseEffectEntries = false;
    Data.m_ucEffectMode = 0;
    for (i = 0; i < 21; ++i)
        for (j = 0; j < 2; ++j)
        {
            Data.m_auiKeyframeCountsByTypeAndChannel[i][j] = 2;
            pEffectEntryTable[i][j] = new TimedFloatKey[2];
            for (kKey = 0; kKey < 2; ++kKey)
            {
                pEffectEntryTable[i][j][kKey].TESRegionPoint_SetX(DAT_0118aba0[kKey]);
                pEffectEntryTable[i][j][kKey].FUN_004f5d90(DAT_0118aba8[j]);
            }
            m_akFloatInterpolators[i][j].SetAnimationKeys(
                pEffectEntryTable[i][j], Data.m_auiKeyframeCountsByTypeAndChannel[i][j], NiAnimationKey::LINKEY);
        }
    Data.m_uiEffectEntryCountFirst = 2;
    pFirstEffectRecordArray = new AlphaColor[2];
    for (i = 0; i < 2; ++i)
    {
        pFirstEffectRecordArray[i].TESRegionPoint_SetX(DAT_0118aba0[i]);
        pFirstEffectRecordArray[i].NiColorKey_SetColor(NiColorA(1.0f, 1.0f, 1.0f, 0.0f));
    }
    m_kColorInterpolatorOne.SetAnimationKeys(pFirstEffectRecordArray, Data.m_uiEffectEntryCountFirst,
                                             NiAnimationKey::LINKEY);
    Data.m_uiEffectEntryCountTwelfth = 2;
    pSecondEffectRecordArray = new AlphaColor[2];
    for (i = 0; i < 2; ++i)
    {
        pSecondEffectRecordArray[i].TESRegionPoint_SetX(DAT_0118aba0[i]);
        pSecondEffectRecordArray[i].NiColorKey_SetColor(NiColorA(1.0f, 1.0f, 1.0f, 0.0f));
    }
    m_kColorInterpolatorTwo.SetAnimationKeys(pSecondEffectRecordArray, Data.m_uiEffectEntryCountTwelfth,
                                             NiAnimationKey::LINKEY);
    Data.m_uiEffectEntryCountSecond = 2;
    pSecondEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pSecondEffectEntries[i].TESRegionPoint_SetX(DAT_0118aba0[i]);
        pSecondEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorOne.SetAnimationKeys(pSecondEffectEntries, Data.m_uiEffectEntryCountSecond,
                                             NiAnimationKey::LINKEY);
    Data.m_uiEffectEntryCountThird = 2;
    pThirdEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pThirdEffectEntries[i].TESRegionPoint_SetX(DAT_0118aba0[i]);
        pThirdEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorTwo.SetAnimationKeys(pThirdEffectEntries, Data.m_uiEffectEntryCountThird, NiAnimationKey::LINKEY);
    Data.m_uiEffectEntryCountFourth = 2;
    pTenthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pTenthEffectEntries[i].TESRegionPoint_SetX(DAT_0118aba0[i]);
        pTenthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorNine.SetAnimationKeys(pTenthEffectEntries, Data.m_uiEffectEntryCountFourth,
                                              NiAnimationKey::LINKEY);
    Data.m_uiEffectEntryCountFifth = 2;
    pEleventhEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pEleventhEffectEntries[i].TESRegionPoint_SetX(DAT_0118aba0[i]);
        pEleventhEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorTen.SetAnimationKeys(pEleventhEffectEntries, Data.m_uiEffectEntryCountFifth,
                                             NiAnimationKey::LINKEY);
    Data.m_uiEffectEntryCountSixth = 2;
    pTwelfthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pTwelfthEffectEntries[i].TESRegionPoint_SetX(DAT_0118aba0[i]);
        pTwelfthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorEleven.SetAnimationKeys(pTwelfthEffectEntries, Data.m_uiEffectEntryCountSixth,
                                                NiAnimationKey::LINKEY);
    Data.m_uiEffectEntryCountTenth = 2;
    pFourthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pFourthEffectEntries[i].TESRegionPoint_SetX(DAT_0118aba0[i]);
        pFourthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorThree.SetAnimationKeys(pFourthEffectEntries, Data.m_uiEffectEntryCountTenth,
                                               NiAnimationKey::LINKEY);
    Data.m_uiEffectEntryCountEleventh = 2;
    pFifthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pFifthEffectEntries[i].TESRegionPoint_SetX(DAT_0118aba0[i]);
        pFifthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorFour.SetAnimationKeys(pFifthEffectEntries, Data.m_uiEffectEntryCountEleventh,
                                              NiAnimationKey::LINKEY);
    Data.m_uiEffectEntryCountSeventh = 2;
    pSeventhEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pSeventhEffectEntries[i].TESRegionPoint_SetX(DAT_0118aba0[i]);
        pSeventhEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorFive.SetAnimationKeys(pSeventhEffectEntries, Data.m_uiEffectEntryCountSeventh,
                                              NiAnimationKey::LINKEY);
    Data.m_uiEffectEntryCountEighth = 2;
    pEighthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pEighthEffectEntries[i].TESRegionPoint_SetX(DAT_0118aba0[i]);
        pEighthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorSix.SetAnimationKeys(pEighthEffectEntries, Data.m_uiEffectEntryCountEighth,
                                             NiAnimationKey::LINKEY);
    Data.m_uiEffectEntryCountNinth = 2;
    pNinthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pNinthEffectEntries[i].TESRegionPoint_SetX(DAT_0118aba0[i]);
        pNinthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorSeven.SetAnimationKeys(pNinthEffectEntries, Data.m_uiEffectEntryCountNinth,
                                               NiAnimationKey::LINKEY);
    Data.m_uiEffectEntryCountThirteenth = 2;
    pSixthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pSixthEffectEntries[i].TESRegionPoint_SetX(DAT_0118aba0[i]);
        pSixthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorEight.SetAnimationKeys(pSixthEffectEntries, Data.m_uiEffectEntryCountThirteenth,
                                               NiAnimationKey::LINKEY);
    pIntroSound = 0;
    pOutroSound = 0;
}

// @fnv 0x00531720
void TESImageSpaceModifier::Apply(float startTime, float strength, NiAVObject* target)
{
    float effectTime;
    if (Data.m_bOverride)
        effectTime = (DAT_011c96fc - startTime) / Data.fDuration;
    else
        effectTime = 0.0f;
    BSClamp_float(effectTime, 0.0f, 1.0f);
    ImageSpaceManager* pManager = ImageSpaceManager::BSShaderManager_GetImageSpaceManager();
    float pfParameterValues[2];
    for (int i = 0; i < 21; ++i)
    {
        for (int j = 0; j < 2; ++j)
            m_akFloatInterpolators[i][j].UpdateFloat(effectTime, 0, pfParameterValues[j]);
        if (i >= 0 && i <= 13)
            pManager->ApplyParamModifier_00b8cb30(1, i, pfParameterValues, strength);
        if (i >= 14 && i <= 16)
            pManager->ApplyParamModifier_00b8cb30(0, i - 14, pfParameterValues, strength);
        if (i >= 17 && i <= 20)
            pManager->ApplyParamModifier_00b8cb30(3, i - 17, pfParameterValues, strength);
    }
    NiColorA kCurrentColor(0.0f, 0.0f, 0.0f, 0.0f);
    m_kColorInterpolatorOne.UpdateColorA(effectTime, 0, kCurrentColor);
    kCurrentColor.a *= strength;
    BSClamp_float(kCurrentColor.a, 0.0f, 1.0f);
    pManager->FUN_00b8b540(kCurrentColor);
    m_kColorInterpolatorTwo.UpdateColorA(effectTime, 0, kCurrentColor);
    kCurrentColor.a *= strength;
    BSClamp_float(kCurrentColor.a, 0.0f, 1.0f);
    pManager->FUN_00b8b610(kCurrentColor);
    float interpolatedBlur;
    m_kFloatInterpolatorOne.UpdateFloat(effectTime, 0, interpolatedBlur);
    float localDouble;
    m_kFloatInterpolatorTwo.UpdateFloat(effectTime, 0, localDouble);
    float interpolatedRadialBlurStrength;
    m_kFloatInterpolatorNine.UpdateFloat(effectTime, 0, interpolatedRadialBlurStrength);
    float fRadialBlurRampupResult;
    m_kFloatInterpolatorTen.UpdateFloat(effectTime, 0, fRadialBlurRampupResult);
    float radialBlurStartOutput;
    m_kFloatInterpolatorEleven.UpdateFloat(effectTime, 0, radialBlurStartOutput);
    float fRadialBlurRampDownSample;
    m_kFloatInterpolatorThree.UpdateFloat(effectTime, 0, fRadialBlurRampDownSample);
    float radialBlurDownStartParameter;
    m_kFloatInterpolatorFour.UpdateFloat(effectTime, 0, radialBlurDownStartParameter);
    float sampledDepthOfFieldStrength;
    m_kFloatInterpolatorFive.UpdateFloat(effectTime, 0, sampledDepthOfFieldStrength);
    float fDepthOfFieldDistanceOutput;
    m_kFloatInterpolatorSix.UpdateFloat(effectTime, 0, fDepthOfFieldDistanceOutput);
    float fCurrentDepthOfFieldRange;
    m_kFloatInterpolatorSeven.UpdateFloat(effectTime, 0, fCurrentDepthOfFieldRange);
    float motionBlurSample;
    m_kFloatInterpolatorEight.UpdateFloat(effectTime, 0, motionBlurSample);
    interpolatedBlur *= strength;
    BSClamp_float(interpolatedBlur, 0.0f, DAT_01018f98);
    pManager->RaiseHighestBlurRadius(interpolatedBlur);
    pManager->ApplyDoubleVisionParamModifier_00b8afb0(localDouble * strength);
    if (Data.m_bUseRadialBlur && target)
    {
        target->UpdateWorldBound();
        pManager->ApplyRadialBlurParamModifier(interpolatedRadialBlurStrength * strength, fRadialBlurRampupResult,
                               radialBlurStartOutput, fRadialBlurRampDownSample, radialBlurDownStartParameter,
                               target->NiAVObject_GetWorldBound());
    }
    else if (Data.m_bUseRadialBlur)
        pManager->SetRadialBlurParameters(interpolatedRadialBlurStrength * strength, fRadialBlurRampupResult,
                                          radialBlurStartOutput, fRadialBlurRampDownSample,
                                          radialBlurDownStartParameter, NiPoint2(0.5f, 0.5f));
    else
        pManager->SetRadialBlurParameters(interpolatedRadialBlurStrength * strength, fRadialBlurRampupResult,
                                          radialBlurStartOutput, fRadialBlurRampDownSample,
                                          radialBlurDownStartParameter, Data.m_kRadialBlurCenter);
    if (Data.m_bUseEffectEntries && target)
    {
        target->UpdateWorldBound();
        pManager->SetDistanceEffect(sampledDepthOfFieldStrength * strength, Data.m_ucEffectMode, 0.0f,
                                    target->NiAVObject_GetWorldBound());
    }
    else if (Data.m_bUseEffectEntries)
        pManager->SetDepthOfFieldParameters(sampledDepthOfFieldStrength * strength, Data.m_ucEffectMode, 0.0f, 0.0f,
                                            1.0f);
    else
        pManager->SetDepthOfFieldParameters(sampledDepthOfFieldStrength * strength, Data.m_ucEffectMode, 0.0f,
                                            fDepthOfFieldDistanceOutput, fCurrentDepthOfFieldRange);
    pManager->RaiseBlurRadius(motionBlurSample);
}

// @fnv 0x00531d20
void TESImageSpaceModifier::EvaluateInterpolators(float startTime, float strength)
{
    float effectTime;
    if (Data.m_bOverride)
        effectTime = (DAT_011c96fc - startTime) / Data.fDuration;
    else
        effectTime = 0.0f;
    ImageSpaceManager* pManager = ImageSpaceManager::BSShaderManager_GetImageSpaceManager();
    float pfParameterValues[2];
    for (int i = 0; i < 21; ++i)
    {
        for (int j = 0; j < 2; ++j)
            m_akFloatInterpolators[i][j].UpdateFloat(effectTime, 0, pfParameterValues[j]);
        if (i >= 0 && i <= 13)
            pManager->AccumulateComponentValues(1, i, pfParameterValues, strength);
        if (i >= 14 && i <= 16)
            pManager->AccumulateComponentValues(0, i - 14, pfParameterValues, strength);
        if (i >= 17 && i <= 20)
            pManager->AccumulateComponentValues(3, i - 17, pfParameterValues, strength);
    }
    NiColorA kCurrentColor(0.0f, 0.0f, 0.0f, 0.0f);
    m_kColorInterpolatorOne.UpdateColorA(effectTime, 0, kCurrentColor);
    kCurrentColor *= strength;
    pManager->FUN_00b8b5c0(kCurrentColor);
    m_kColorInterpolatorTwo.UpdateColorA(effectTime, 0, kCurrentColor);
    kCurrentColor *= strength;
    pManager->FUN_00b8b690(kCurrentColor);
    float interpolatedBlur;
    m_kFloatInterpolatorOne.UpdateFloat(effectTime, 0, interpolatedBlur);
    float localDouble;
    m_kFloatInterpolatorTwo.UpdateFloat(effectTime, 0, localDouble);
    float interpolatedRadialBlurStrength;
    m_kFloatInterpolatorNine.UpdateFloat(effectTime, 0, interpolatedRadialBlurStrength);
    float fRadialBlurRampupResult;
    m_kFloatInterpolatorTen.UpdateFloat(effectTime, 0, fRadialBlurRampupResult);
    float radialBlurStartOutput;
    m_kFloatInterpolatorEleven.UpdateFloat(effectTime, 0, radialBlurStartOutput);
    float fRadialBlurRampDownSample;
    m_kFloatInterpolatorThree.UpdateFloat(effectTime, 0, fRadialBlurRampDownSample);
    float radialBlurDownStartParameter;
    m_kFloatInterpolatorFour.UpdateFloat(effectTime, 0, radialBlurDownStartParameter);
    float sampledDepthOfFieldStrength;
    m_kFloatInterpolatorFive.UpdateFloat(effectTime, 0, sampledDepthOfFieldStrength);
    float fDepthOfFieldDistanceOutput;
    m_kFloatInterpolatorSix.UpdateFloat(effectTime, 0, fDepthOfFieldDistanceOutput);
    float fCurrentDepthOfFieldRange;
    m_kFloatInterpolatorSeven.UpdateFloat(effectTime, 0, fCurrentDepthOfFieldRange);
    float motionBlurSample;
    m_kFloatInterpolatorEight.UpdateFloat(effectTime, 0, motionBlurSample);
    pManager->ApplyBlurRadiusParamModifierWeather_00b8af40(interpolatedBlur * strength);
    pManager->AddDoubleVision(localDouble * strength);
    pManager->FUN_00b8b6e0(interpolatedRadialBlurStrength * strength, fRadialBlurRampupResult * strength,
                           radialBlurStartOutput * strength, fRadialBlurRampDownSample * strength,
                           radialBlurDownStartParameter * strength, Data.m_kRadialBlurCenter * strength);
    pManager->FUN_00b8b130(sampledDepthOfFieldStrength * strength, Data.m_ucEffectMode, 0.0f,
                           fDepthOfFieldDistanceOutput * strength, fCurrentDepthOfFieldRange * strength);
    pManager->ApplyMotionBlurStrengthParamModifierWeather_00b8af90(motionBlurSample * strength);
}

// Sets the form type to IMAD, calls the initializer, and if this is the global instance DAT_011c9750 calls the second initializer.
// @fnv 0x0052b8f0
TESImageSpaceModifier::TESImageSpaceModifier()
    : m_kFloatInterpolatorOne(0), m_kFloatInterpolatorTwo(0),
      m_kFloatInterpolatorNine(0), m_kFloatInterpolatorTen(0), m_kFloatInterpolatorEleven(0),
      m_kFloatInterpolatorThree(0), m_kFloatInterpolatorFour(0), m_kFloatInterpolatorFive(0),
      m_kFloatInterpolatorSix(0), m_kFloatInterpolatorSeven(0), m_kFloatInterpolatorEight(0)
{
    SetFormType(ENUM_FORM_ID_IMAD_ID);
    ResetFormData();
    if (this == &DAT_011c9750)
        NotifySaveLoadGameOfFormChange();
}
// @fnv 0x0052d260
void TESImageSpaceModifier::ClearData()
{
    for (int i = 0; i < 21; ++i)
        for (int j = 0; j < 2; ++j)
            m_akFloatInterpolators[i][j].FUN_007fc2b0(0);
    m_kColorInterpolatorOne.SetColorData(0);
    m_kColorInterpolatorTwo.SetColorData(0);
    m_kFloatInterpolatorOne.FUN_007fc2b0(0);
    m_kFloatInterpolatorTwo.FUN_007fc2b0(0);
    m_kFloatInterpolatorNine.FUN_007fc2b0(0);
    m_kFloatInterpolatorTen.FUN_007fc2b0(0);
    m_kFloatInterpolatorEleven.FUN_007fc2b0(0);
    m_kFloatInterpolatorThree.FUN_007fc2b0(0);
    m_kFloatInterpolatorFour.FUN_007fc2b0(0);
    m_kFloatInterpolatorFive.FUN_007fc2b0(0);
    m_kFloatInterpolatorSix.FUN_007fc2b0(0);
    m_kFloatInterpolatorSeven.FUN_007fc2b0(0);
    m_kFloatInterpolatorEight.FUN_007fc2b0(0);
    TESForm::ClearData();
    pIntroSound = 0;
    pOutroSound = 0;
}
// @fnv 0x0052d3d0
void TESImageSpaceModifier::InitItem()
{
    if (IsFormInitialized())
        return;
    unsigned int formID = (unsigned int)pIntroSound;
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        pIntroSound = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if (!pIntroSound)
            Warning("MASTERFILE: Could not find pIntroSound (%08X) for ImageSpaceModifier '%s' (%08X).", formID,
                    GetName(), GetFormID());
    }
    formID = (unsigned int)pOutroSound;
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        pOutroSound = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if (!pOutroSound)
            Warning("MASTERFILE: Could not find pOutroSound (%08X) for ImageSpaceModifier '%s' (%08X).", formID,
                    GetName(), GetFormID());
    }
    SetInitializationState(true);
}
// @fnv 0x005316c0
bool TESImageSpaceModifier::IsExpired(float startTime)
{
    if (!Data.m_bOverride)
        return false;
    if (startTime < -10000.0)
        return false;
    return DAT_011c96fc - startTime > Data.fDuration;
}
// @fnv 0x005330a0
void TESImageSpaceModifier::InitializeModifierData()
{
    InitializeComponent();
    Data.m_bOverride = true;
    pThirdEffectEntries->FUN_004f5d90(0.005f);
}

// NiColorA::operator*=(float) (community FalloutNV.pdb public symbol at this address).
// @fnv 0x005321d0
NiColorA& NiColorA::operator*=(float scale)
{
    r *= scale;
    g *= scale;
    b *= scale;
    a *= scale;
    return *this;
}
// @fnv 0x0052bad0
ImageSpaceModifierEffectData::ImageSpaceModifierEffectData()
{}
// @fnv 0x0052d3b0
void NiColorInterpolator::SetColorData(NiColorData* apColorData)
{
    reinterpret_cast<TESImageSpaceColorDataPointer&>(m_spColorData) = apColorData;
}
// @fnv 0x00532fd0
NiPoint2 operator*(float scale, const NiPoint2& arPoint)
{
    return arPoint * scale;
}
// @fnv 0x00532ff0
TESImageSpaceModifier* TESImageSpaceModifier::QDefault()
{
    return &DAT_011c9750;
}

struct NiStream;
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};

// Multiplies the point pt by the 3x3 matrix mat and stores the result in pOut, returning pOut.
// @fnv 0x004b3ae0
// src: GUESS 0x004b3ae0 (confidence: medium)
NiPoint3* NiPoint3_TransformByMatrix3(NiPoint3* pOut, const NiPoint3& pt, const float* mat)
{
    pOut->Set(pt.x * mat[0] + pt.y * mat[3] + pt.z * mat[6],
              pt.x * mat[1] + pt.y * mat[4] + pt.z * mat[7],
              pt.x * mat[2] + pt.y * mat[5] + pt.z * mat[8]);
    return pOut;
}

// @fnv 0x0052baf0
void __fastcall ConstructFloatInterpolator(NiFloatInterpolator* pThis)
{
    pThis->NiFloatInterpolator::NiFloatInterpolator(0);
}

#include "../../include/NiMemObject.h"
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

struct Obj52 : NiMemObject
{
    void FUN_00a3cc80();
    void* FUN_0052cf90(unsigned int);
    static void operator delete(void*, unsigned int);
};
// Calls FUN_00a3cc80, deletes this with size 0x18 when flags has bit 0 set, and returns this.
// @fnv 0x0052cf90
void* Obj52::FUN_0052cf90(unsigned int flags)
{
    FUN_00a3cc80();
    if (flags & 1)
        Obj52::operator delete(this, 0x18);
    return this;
}

// Exposes this unit's deleting-destructor entry without duplicating NiColorData's layout.
struct ImageSpaceColorData : NiColorData
{
    void* Destroy(unsigned int flags);
};

// @fnv 0x0052d130
void* ImageSpaceColorData::Destroy(unsigned int flags)
{
    NiColorData::~NiColorData();
    if (flags & 1)
        NiColorData::operator delete(this, sizeof(NiColorData));
    return this;
}

// Clamps the float pointed to by aVal to the range [aMin, aMax], writing the bound back when it is out of range.
// @fnv 0x005330e0
// src: XBOX_PDB 0x005330e0
void __cdecl BSClamp_float(float* aVal, float aMin, float aMax)
{
    if (*aVal > aMax)
        *aVal = aMax;
    else if (*aVal < aMin)
        *aVal = aMin;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f3748;

struct FUN_0052cf80_shell
{
    GlobalObjectO2_00a7b610* GetGlobalObject();
};

// @fnv 0x0052cf80
GlobalObjectO2_00a7b610* FUN_0052cf80_shell::GetGlobalObject()
{
    return &g_011f3748;
}

extern NiRTTI g_011f3750;

// @fnv 0x0052d120
const NiRTTI* NiColorData::GetRTTI() const
{
    return &g_011f3750;
}

struct ImageSpaceModifierDeleting : TESImageSpaceModifier
{
    void* __thiscall Destroy(unsigned int flags);
};

extern void* __cdecl _Deallocate(void*);

// Runs the destructor, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0052baa0
void* __thiscall ImageSpaceModifierDeleting::Destroy(unsigned int flags)
{
    TESImageSpaceModifier::~TESImageSpaceModifier();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00533060_shell
{
    void* __thiscall NiFloatData_GetAnim(void** a, void** b, char* c);
};
// @fnv 0x00533060
// src: COMMUNITY 0x00533060
void* __thiscall FUN_00533060_shell::NiFloatData_GetAnim(void** apFirst, void** apSecond, char* c)
{
    *apFirst = *(void**)((char*)this + 8);
    *apSecond = *(void**)((char*)this + 0x10);
    *c = *(char*)((char*)this + 0x14);
    return *(void**)((char*)this + 0xc);
}

namespace fnv_00533000 {
struct Flt
{
    operator unsigned int();
};
struct FUN_00533060_shell
{
    void* NiFloatData_GetAnim(void**, void**, char*);
};
struct FUN_00533000_shell
{
    char _pad[16];
    Flt m_kHandle;
    void* NiFloatInterpolator_GetKeys_0(void**, void**, char*);
};
// If the stored pointer is non-null, forwards to FUN_00533060; otherwise zeroes the three output pointers and returns null.
// @fnv 0x00533000
// src: COMMUNITY 0x00533000
void* FUN_00533000_shell::NiFloatInterpolator_GetKeys_0(void** a, void** b, char* c)
{
    if ((unsigned int)m_kHandle)
        return ((FUN_00533060_shell*)(unsigned int)m_kHandle)->NiFloatData_GetAnim(a, b, c);
    *a = 0;
    *b = 0;
    *c = 0;
    return 0;
}
}  // namespace fnv_00533000

// Destructor that calls TESImageSpaceModifier::ClearData on this object.
// @fnv 0x0052bbd0
TESImageSpaceModifier::~TESImageSpaceModifier()
{
    TESImageSpaceModifier::ClearData();
}

struct FUN_00532e40_s
{
    float x;
    float y;
    float z;
    float w;
    FUN_00532e40_s* AddDelta(FUN_00532e40_s* result, float* delta);
};

// @fnv 0x00532e40
FUN_00532e40_s* FUN_00532e40_s::AddDelta(FUN_00532e40_s* result, float* delta)
{
    FUN_00532e40_s temp = *this;
    temp.x += delta[0];
    temp.y += delta[1];
    temp.z += delta[2];
    temp.w += delta[3];
    *result = temp;
    return result;
}

struct FUN_00532ec0_v4
{
    float x;
    float y;
    float z;
    float w;
};
struct FUN_00532ec0
{
    FUN_00532ec0_v4* SUB(FUN_00532ec0_v4* result, const FUN_00532ec0_v4& sub);
};
// Subtracts the components of sub from this vector and stores the result in result, returning result.
// @fnv 0x00532ec0
FUN_00532ec0_v4* FUN_00532ec0::SUB(FUN_00532ec0_v4* result, const FUN_00532ec0_v4& sub)
{
    FUN_00532ec0_v4 tmp = *(FUN_00532ec0_v4*)this;
    tmp.x -= sub.x;
    tmp.y -= sub.y;
    tmp.z -= sub.z;
    tmp.w -= sub.w;
    *result = tmp;
    return result;
}

extern "C" void __fastcall CacheObjectValues(TESImageSpaceModifier*);

int __cdecl _memcmp(const void* left, const void* right, unsigned int count);
void* __cdecl FUN_00ec43fb(void* object, unsigned int type, void* data, const void* typeInfo, unsigned char option);
extern char _DAT_01183028;

// Looks up the TESImageSpaceModifier matching form, updates both objects, and returns false only if all compared fields and arrays are identical.
// @fnv 0x005310b0
bool TESImageSpaceModifier::Compare(TESForm* form)
{
    TESImageSpaceModifier* imageSpaceModifier;
    int i;
    int j;

    imageSpaceModifier =
        static_cast<TESImageSpaceModifier*>(FUN_00ec43fb(form, 0, &_DAT_01183028, &typeid(TESImageSpaceModifier), 0));

    if (!imageSpaceModifier)
        return true;

    CacheObjectValues(this);
    CacheObjectValues(imageSpaceModifier);

    if (pIntroSound !=
        imageSpaceModifier->pIntroSound)
        return true;

    if (pOutroSound !=
        imageSpaceModifier->pOutroSound)
        return true;

    if (TESForm::Compare(imageSpaceModifier))
        return true;

    if (_memcmp(&Data, &imageSpaceModifier->Data, 0xf4))
        return true;

    if (_memcmp(pSecondEffectEntries,
                imageSpaceModifier->pSecondEffectEntries,
                Data.m_uiEffectEntryCountSecond * 8))
        return true;

    if (_memcmp(pThirdEffectEntries,
                imageSpaceModifier->pThirdEffectEntries,
                Data.m_uiEffectEntryCountThird * 8))
        return true;

    if (_memcmp(pFirstEffectRecordArray,
                imageSpaceModifier->pFirstEffectRecordArray,
                Data.m_uiEffectEntryCountFirst * 0x14))
        return true;

    if (_memcmp(pSecondEffectRecordArray,
                imageSpaceModifier->pSecondEffectRecordArray,
                Data.m_uiEffectEntryCountTwelfth * 0x14))
        return true;

    if (_memcmp(pTenthEffectEntries,
                imageSpaceModifier->pTenthEffectEntries,
                Data.m_uiEffectEntryCountFourth * 8))
        return true;

    if (_memcmp(pEleventhEffectEntries,
                imageSpaceModifier->pEleventhEffectEntries,
                Data.m_uiEffectEntryCountFifth * 8))
        return true;

    if (_memcmp(pTwelfthEffectEntries,
                imageSpaceModifier->pTwelfthEffectEntries,
                Data.m_uiEffectEntryCountSixth * 8))
        return true;

    if (_memcmp(pFourthEffectEntries,
                imageSpaceModifier->pFourthEffectEntries,
                Data.m_uiEffectEntryCountTenth * 8))
        return true;

    if (_memcmp(pFifthEffectEntries,
                imageSpaceModifier->pFifthEffectEntries,
                Data.m_uiEffectEntryCountEleventh * 8))
        return true;

    if (_memcmp(pSeventhEffectEntries,
                imageSpaceModifier->pSeventhEffectEntries,
                Data.m_uiEffectEntryCountSeventh * 8))
        return true;

    if (_memcmp(pEighthEffectEntries,
                imageSpaceModifier->pEighthEffectEntries,
                Data.m_uiEffectEntryCountEighth * 8))
        return true;

    if (_memcmp(pNinthEffectEntries,
                imageSpaceModifier->pNinthEffectEntries,
                Data.m_uiEffectEntryCountNinth * 8))
        return true;

    if (_memcmp(pSixthEffectEntries,
                imageSpaceModifier->pSixthEffectEntries,
                Data.m_uiEffectEntryCountThirteenth * 8))
        return true;

    for (i = 0; i < 0x15; ++i)
    {
        for (j = 0; j < 2; ++j)
        {
            if (_memcmp(pEffectEntryTable[i][j],
                        imageSpaceModifier->pEffectEntryTable[i][j],
                        Data.m_auiKeyframeCountsByTypeAndChannel[i][j] * 8))
                return true;
        }
    }

    return false;
}

// @fnv 0x00531490
void ImageSpaceModifierEffectData::Endian()
{
    int j;
    int i;

    BSEndian(reinterpret_cast<unsigned int*>(&fDuration), EndianSizeTag<4>());

    for (j = 0; j < 21; ++j)
    {
        for (i = 0; i < 2; ++i)
        {
            BSEndian(&m_auiKeyframeCountsByTypeAndChannel[j][i],
                     EndianSizeTag<4>());
        }
    }

    BSEndian(&m_uiEffectEntryCountSecond, EndianSizeTag<4>());
    BSEndian(&m_uiEffectEntryCountThird, EndianSizeTag<4>());
    BSEndian(&m_uiEffectEntryCountFirst, EndianSizeTag<4>());
    BSEndian(&m_uiEffectEntryCountTwelfth, EndianSizeTag<4>());
    BSEndian(&m_uiEffectEntryCountFourth, EndianSizeTag<4>());
    BSEndian(&m_uiEffectEntryCountFifth, EndianSizeTag<4>());
    BSEndian(&m_uiEffectEntryCountSixth, EndianSizeTag<4>());
    BSEndian(&m_uiEffectEntryCountTenth, EndianSizeTag<4>());
    BSEndian(&m_uiEffectEntryCountEleventh, EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xcc), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xd0), EndianSizeTag<4>());
    BSEndian(&m_uiEffectEntryCountSeventh, EndianSizeTag<4>());
    BSEndian(&m_uiEffectEntryCountEighth, EndianSizeTag<4>());
    BSEndian(&m_uiEffectEntryCountNinth, EndianSizeTag<4>());
    BSEndian(&m_uiEffectEntryCountThirteenth, EndianSizeTag<4>());
}

struct FUN_0045cec0
{
    ~FUN_0045cec0();
};

struct FUN_00a3ca30
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    ~FUN_00a3ca30();
};

struct FUN_0052bb10 : public FUN_00a3ca30
{
    FUN_0045cec0 unk10;

    ~FUN_0052bb10();
};

FUN_0045cec0::~FUN_0045cec0()
{}

FUN_00a3ca30::~FUN_00a3ca30()
{}

// @fnv 0x0052bb10
FUN_0052bb10::~FUN_0052bb10()
{}

namespace Real {
struct InterpolatorBase
{
    unsigned int referenceCount;
    unsigned int flags;
    float lastTime;
    float currentTime;
    float startTime;
    float endTime;
    void* controller;
    ~InterpolatorBase();
};
struct ColorDataReference
{
    void* colorData;
    ~ColorDataReference();
};
struct FUN_0052bb70 : InterpolatorBase
{
    ColorDataReference colorData;
    ~FUN_0052bb70();
};
// Destructor for an interpolator that owns a ColorDataReference; the body is empty.
// @fnv 0x0052bb70
FUN_0052bb70::~FUN_0052bb70()
{}
}

struct SpawnedObject
{
    void Method(float* pOut, float f);
};

// @fnv 0x00532f40
// src: GUESS 0x00532f40 (confidence: low)
float* __cdecl Object_ProcessAndReturnValue_00532f40(float* pOut, float f, SpawnedObject* pObj)
{
    pObj->Method(pOut, f);
    return pOut;
}

struct FUN_00532f60_vec4
{
    float x;
    float y;
    float z;
    float w;
};

class FUN_00532f60_cls
{
  public:
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
    FUN_00532f60_vec4* ScaleVector4(FUN_00532f60_vec4* out, float scale);
};

// Multiplies the four floats of this object by scale and writes the result to out, returning out.
// @fnv 0x00532f60
FUN_00532f60_vec4* FUN_00532f60_cls::ScaleVector4(FUN_00532f60_vec4* out, float scale)
{
    FUN_00532f60_vec4 vecScaled = *(FUN_00532f60_vec4*)this;
    vecScaled.x *= scale;
    vecScaled.y *= scale;
    vecScaled.z *= scale;
    vecScaled.w *= scale;
    *out = vecScaled;
    return out;
}

// Caches the key counts and arrays from the shared interpolators.
// @fnv 0x0052ed90
extern "C" void __fastcall CacheObjectValues(TESImageSpaceModifier* modifier)
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            modifier->Data.m_auiKeyframeCountsByTypeAndChannel[i][j] = modifier->m_akFloatInterpolators[i][j].GetColorKeyCount(0);
            modifier->pEffectEntryTable[i][j] = (TimedFloatKey*)modifier->m_akFloatInterpolators[i][j].GetChannelKeys(0);
        }
    }
    modifier->Data.m_uiEffectEntryCountSecond = modifier->m_kFloatInterpolatorOne.GetColorKeyCount(0);
    modifier->pSecondEffectEntries = (TimedFloatKey*)modifier->m_kFloatInterpolatorOne.GetChannelKeys(0);
    modifier->Data.m_uiEffectEntryCountThird = modifier->m_kFloatInterpolatorTwo.GetColorKeyCount(0);
    modifier->pThirdEffectEntries = (TimedFloatKey*)modifier->m_kFloatInterpolatorTwo.GetChannelKeys(0);
    modifier->Data.m_uiEffectEntryCountFirst = modifier->m_kColorInterpolatorOne.GetColorKeyCount(0);
    modifier->pFirstEffectRecordArray = (AlphaColor*)modifier->m_kColorInterpolatorOne.GetChannelKeys(0);
    modifier->Data.m_uiEffectEntryCountTwelfth = modifier->m_kColorInterpolatorTwo.GetColorKeyCount(0);
    modifier->pSecondEffectRecordArray = (AlphaColor*)modifier->m_kColorInterpolatorTwo.GetChannelKeys(0);
    modifier->Data.m_uiEffectEntryCountFourth = modifier->m_kFloatInterpolatorNine.GetColorKeyCount(0);
    modifier->pTenthEffectEntries = (TimedFloatKey*)modifier->m_kFloatInterpolatorNine.GetChannelKeys(0);
    modifier->Data.m_uiEffectEntryCountFifth = modifier->m_kFloatInterpolatorTen.GetColorKeyCount(0);
    modifier->pEleventhEffectEntries = (TimedFloatKey*)modifier->m_kFloatInterpolatorTen.GetChannelKeys(0);
    modifier->Data.m_uiEffectEntryCountSixth = modifier->m_kFloatInterpolatorEleven.GetColorKeyCount(0);
    modifier->pTwelfthEffectEntries = (TimedFloatKey*)modifier->m_kFloatInterpolatorEleven.GetChannelKeys(0);
    modifier->Data.m_uiEffectEntryCountTenth = modifier->m_kFloatInterpolatorThree.GetColorKeyCount(0);
    modifier->pFourthEffectEntries = (TimedFloatKey*)modifier->m_kFloatInterpolatorThree.GetChannelKeys(0);
    modifier->Data.m_uiEffectEntryCountEleventh = modifier->m_kFloatInterpolatorFour.GetColorKeyCount(0);
    modifier->pFifthEffectEntries = (TimedFloatKey*)modifier->m_kFloatInterpolatorFour.GetChannelKeys(0);
    modifier->Data.m_uiEffectEntryCountSeventh = modifier->m_kFloatInterpolatorFive.GetColorKeyCount(0);
    modifier->pSeventhEffectEntries = (TimedFloatKey*)modifier->m_kFloatInterpolatorFive.GetChannelKeys(0);
    modifier->Data.m_uiEffectEntryCountEighth = modifier->m_kFloatInterpolatorSix.GetColorKeyCount(0);
    modifier->pEighthEffectEntries = (TimedFloatKey*)modifier->m_kFloatInterpolatorSix.GetChannelKeys(0);
    modifier->Data.m_uiEffectEntryCountNinth = modifier->m_kFloatInterpolatorSeven.GetColorKeyCount(0);
    modifier->pNinthEffectEntries = (TimedFloatKey*)modifier->m_kFloatInterpolatorSeven.GetChannelKeys(0);
    modifier->Data.m_uiEffectEntryCountThirteenth = modifier->m_kFloatInterpolatorEight.GetColorKeyCount(0);
    modifier->pSixthEffectEntries = (TimedFloatKey*)modifier->m_kFloatInterpolatorEight.GetChannelKeys(0);
}

bool TESForm_QEndianSwapOnSave();
void AppendChunk(unsigned int, void*, unsigned int);
void TESForm_AddChunk_00485910(unsigned int, unsigned int);
void* __memcpy(void*, const void*, unsigned int);
// Serializes the image space modifier: writes a header, then each data array (endian-swapped when needed) with its tag, plus intro/outro sound form IDs.
// @fnv 0x0052f250
void TESImageSpaceModifier::Save()
{
    TESForm::BeginFormRecord();
    CacheObjectValues(this);
    if (TESForm_QEndianSwapOnSave())
        Data.Endian();
    AppendChunk(0x4d414e44, &Data, 0xf4);
    if (TESForm_QEndianSwapOnSave())
        Data.Endian();
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountSecond / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pSecondEffectEntries, count * 4);
        if (TESForm_QEndianSwapOnSave())
            for (unsigned int idx = 0; idx < count; idx++)
                BSEndian(dataTmp + idx, EndianSizeTag<4>());
        AppendChunk(0x4d414e42, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountThird / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pThirdEffectEntries, count * 4);
        if (TESForm_QEndianSwapOnSave())
            for (unsigned int idx = 0; idx < count; idx++)
                BSEndian(dataTmp + idx, EndianSizeTag<4>());
        AppendChunk(0x4d414e56, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 20;
        unsigned int count = size * Data.m_uiEffectEntryCountFirst / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pFirstEffectRecordArray, count * 4);
        if (TESForm_QEndianSwapOnSave())
            for (unsigned int idx = 0; idx < count; idx++)
                BSEndian(dataTmp + idx, EndianSizeTag<4>());
        AppendChunk(0x4d414e54, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 20;
        unsigned int count = size * Data.m_uiEffectEntryCountTwelfth / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pSecondEffectRecordArray, count * 4);
        if (TESForm_QEndianSwapOnSave())
            for (unsigned int idx = 0; idx < count; idx++)
                BSEndian(dataTmp + idx, EndianSizeTag<4>());
        AppendChunk(0x334d414e, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountFourth / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pTenthEffectEntries, count * 4);
        if (TESForm_QEndianSwapOnSave())
            for (unsigned int idx = 0; idx < count; idx++)
                BSEndian(dataTmp + idx, EndianSizeTag<4>());
        AppendChunk(0x4d414e52, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountFifth / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pEleventhEffectEntries, count * 4);
        if (TESForm_QEndianSwapOnSave())
            for (unsigned int idx = 0; idx < count; idx++)
                BSEndian(dataTmp + idx, EndianSizeTag<4>());
        AppendChunk(0x4d414e53, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountSixth / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pTwelfthEffectEntries, count * 4);
        if (TESForm_QEndianSwapOnSave())
            for (unsigned int idx = 0; idx < count; idx++)
                BSEndian(dataTmp + idx, EndianSizeTag<4>());
        AppendChunk(0x4d414e55, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountTenth / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pFourthEffectEntries, count * 4);
        if (TESForm_QEndianSwapOnSave())
            for (unsigned int idx = 0; idx < count; idx++)
                BSEndian(dataTmp + idx, EndianSizeTag<4>());
        AppendChunk(0x314d414e, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountEleventh / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pFifthEffectEntries, count * 4);
        if (TESForm_QEndianSwapOnSave())
            for (unsigned int idx = 0; idx < count; idx++)
                BSEndian(dataTmp + idx, EndianSizeTag<4>());
        AppendChunk(0x324d414e, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountSeventh / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pSeventhEffectEntries, count * 4);
        if (TESForm_QEndianSwapOnSave())
            for (unsigned int idx = 0; idx < count; idx++)
                BSEndian(dataTmp + idx, EndianSizeTag<4>());
        AppendChunk(0x4d414e57, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountEighth / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pEighthEffectEntries, count * 4);
        if (TESForm_QEndianSwapOnSave())
            for (unsigned int idx = 0; idx < count; idx++)
                BSEndian(dataTmp + idx, EndianSizeTag<4>());
        AppendChunk(0x4d414e58, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountNinth / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pNinthEffectEntries, count * 4);
        if (TESForm_QEndianSwapOnSave())
            for (unsigned int idx = 0; idx < count; idx++)
                BSEndian(dataTmp + idx, EndianSizeTag<4>());
        AppendChunk(0x4d414e59, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountThirteenth / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pSixthEffectEntries, count * 4);
        if (TESForm_QEndianSwapOnSave())
            for (unsigned int idx = 0; idx < count; idx++)
                BSEndian(dataTmp + idx, EndianSizeTag<4>());
        AppendChunk(0x344d414e, dataTmp, count * 4);
        delete[] dataTmp;
    }
    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 2; j++)
        {
            unsigned int tag = 0x44414900 | i | (j << 6);
            unsigned int size = 8;
            unsigned int count2 = size * Data.m_auiKeyframeCountsByTypeAndChannel[i][j] / 4;
            unsigned int* dataTmp = new unsigned int[count2];
            __memcpy(dataTmp, pEffectEntryTable[i][j], count2 * 4);
            if (TESForm_QEndianSwapOnSave())
                for (unsigned int idx = 0; idx < count2; idx++)
                    BSEndian(dataTmp + idx, EndianSizeTag<4>());
            AppendChunk(tag, dataTmp, count2 * 4);
            delete[] dataTmp;
        }
    if (pIntroSound)
    {
        unsigned int intro = pIntroSound->GetFormID();
        TESForm_AddChunk_00485910(0x44534452, intro);
    }
    if (pOutroSound)
    {
        unsigned int outro = pOutroSound->GetFormID();
        TESForm_AddChunk_00485910(0x49534452, outro);
    }
    TESForm::FinishFormRecord();
}

extern char _DAT_011862b8;
extern "C" void* __cdecl FUN_00401460(void*, const void*, unsigned int);
struct PassPtr
{
    TESImageSpaceModifier* value;
};
extern "C" void __fastcall TESForm_CopyAllComponents(TESImageSpaceModifier*, PassPtr);
// Looks up a TESImageSpaceModifier by form, clears this object's data, then copies its sounds, Data struct and all list arrays into newly allocated storage.
// @fnv 0x00530160
void TESImageSpaceModifier::Copy(TESForm* form)
{
    unsigned int count;
    TESImageSpaceModifier* source = (TESImageSpaceModifier*)FUN_00ec43fb(form, 0, &_DAT_01183028, &_DAT_011862b8, 0);
    if (!source)
        return;
    CacheObjectValues(source);
    TESForm_CopyAllComponents(this, *(PassPtr*)&source);
    ClearData();
    pIntroSound = source->pIntroSound;
    pOutroSound = source->pOutroSound;
    FUN_00401460(&Data, &source->Data, sizeof(Data));
    count = Data.m_uiEffectEntryCountSecond;
    pSecondEffectEntries = new TimedFloatKey[count];
    FUN_00401460(pSecondEffectEntries, source->pSecondEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorOne.SetAnimationKeys(pSecondEffectEntries, count, NiAnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountThird;
    pThirdEffectEntries = new TimedFloatKey[count];
    FUN_00401460(pThirdEffectEntries, source->pThirdEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorTwo.SetAnimationKeys(pThirdEffectEntries, count, NiAnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountFirst;
    pFirstEffectRecordArray = new AlphaColor[count];
    FUN_00401460(pFirstEffectRecordArray, source->pFirstEffectRecordArray, count * sizeof(AlphaColor));
    m_kColorInterpolatorOne.SetAnimationKeys(pFirstEffectRecordArray, count, NiAnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountTwelfth;
    pSecondEffectRecordArray = new AlphaColor[count];
    FUN_00401460(pSecondEffectRecordArray, source->pSecondEffectRecordArray, count * sizeof(AlphaColor));
    m_kColorInterpolatorTwo.SetAnimationKeys(pSecondEffectRecordArray, count, NiAnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountFourth;
    pTenthEffectEntries = new TimedFloatKey[count];
    FUN_00401460(pTenthEffectEntries, source->pTenthEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorNine.SetAnimationKeys(pTenthEffectEntries, count, NiAnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountFifth;
    pEleventhEffectEntries = new TimedFloatKey[count];
    FUN_00401460(pEleventhEffectEntries, source->pEleventhEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorTen.SetAnimationKeys(pEleventhEffectEntries, count, NiAnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountSixth;
    pTwelfthEffectEntries = new TimedFloatKey[count];
    FUN_00401460(pTwelfthEffectEntries, source->pTwelfthEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorEleven.SetAnimationKeys(pTwelfthEffectEntries, count, NiAnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountTenth;
    pFourthEffectEntries = new TimedFloatKey[count];
    FUN_00401460(pFourthEffectEntries, source->pFourthEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorThree.SetAnimationKeys(pFourthEffectEntries, count, NiAnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountEleventh;
    pFifthEffectEntries = new TimedFloatKey[count];
    FUN_00401460(pFifthEffectEntries, source->pFifthEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorFour.SetAnimationKeys(pFifthEffectEntries, count, NiAnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountSeventh;
    pSeventhEffectEntries = new TimedFloatKey[count];
    FUN_00401460(pSeventhEffectEntries, source->pSeventhEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorFive.SetAnimationKeys(pSeventhEffectEntries, count, NiAnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountEighth;
    pEighthEffectEntries = new TimedFloatKey[count];
    FUN_00401460(pEighthEffectEntries, source->pEighthEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorSix.SetAnimationKeys(pEighthEffectEntries, count, NiAnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountNinth;
    pNinthEffectEntries = new TimedFloatKey[count];
    FUN_00401460(pNinthEffectEntries, source->pNinthEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorSeven.SetAnimationKeys(pNinthEffectEntries, count, NiAnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountThirteenth;
    pSixthEffectEntries = new TimedFloatKey[count];
    FUN_00401460(pSixthEffectEntries, source->pSixthEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorEight.SetAnimationKeys(pSixthEffectEntries, count, NiAnimationKey::LINKEY);
    {
        int j;
        for (int i = 0; i < 21; ++i)
        {
            for (j = 0; j < 2; ++j)
            {
                count = Data.m_auiKeyframeCountsByTypeAndChannel[i][j];
                pEffectEntryTable[i][j] = new TimedFloatKey[count];
                FUN_00401460(pEffectEntryTable[i][j], source->pEffectEntryTable[i][j], count * sizeof(TimedFloatKey));
                m_akFloatInterpolators[i][j].SetAnimationKeys(pEffectEntryTable[i][j], count, NiAnimationKey::LINKEY);
            }
        }
    }
}

struct BlendColor
{
    float r, g, b, a;
    BlendColor(float, float, float, float);
    BlendColor FUN_00532ec0(const BlendColor&) const;
    BlendColor AddDelta(const BlendColor&) const;
};
BlendColor Object_ProcessAndReturnValue_00532f40(float, const BlendColor&);
struct BlendPoint
{
    float x, y;
    BlendPoint();
    BlendPoint(float, float);
    BlendPoint Subtract(const BlendPoint&) const;
    BlendPoint AddPointComponents(const BlendPoint&) const;
};
BlendPoint FUN_00532fd0(float, const BlendPoint&);
// Interpolates two TESImageSpaceModifiers by blend and strength and pushes the blended values into the ImageSpaceManager.
// @fnv 0x00532220
void TESImageSpaceModifier::BlendModifiers(float blend, TESImageSpaceModifier* pPreviousModifier,
                              TESImageSpaceModifier* pNextModifier, float previousStrength, float nextStrength,
                              NiAVObject* previousTarget, NiAVObject* nextTarget)
{
    if (!pPreviousModifier)
        pPreviousModifier = TESImageSpaceModifier::QDefault();
    if (!pNextModifier)
        pNextModifier = TESImageSpaceModifier::QDefault();
    float time = 0.0f;
    ImageSpaceManager* manager4 = ImageSpaceManager::BSShaderManager_GetImageSpaceManager();
    float strength_15 = previousStrength + blend * (nextStrength - previousStrength);
    float values[2];
    for (int i = 0; i < 21; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            float first, second6;
            pPreviousModifier->m_akFloatInterpolators[i][j].UpdateFloat(time, 0, first);
            pNextModifier->m_akFloatInterpolators[i][j].UpdateFloat(time, 0, second6);
            values[j] = first + blend * (second6 - first);
        }
        if (i >= 0 && i <= 13)
            manager4->ApplyParamModifier_00b8cb30(1, i, values, strength_15);
        if (i >= 14 && i <= 16)
            manager4->ApplyParamModifier_00b8cb30(0, i - 14, values, strength_15);
        if (i >= 17 && i <= 20)
            manager4->ApplyParamModifier_00b8cb30(3, i - 17, values, strength_15);
    }
    BlendColor color(0, 0, 0, 0), aFirstColor(0, 0, 0, 0), secondColor(0, 0, 0, 0);
    pPreviousModifier->m_kColorInterpolatorOne.UpdateColorA(time, 0, (NiColorA&)aFirstColor);
    pNextModifier->m_kColorInterpolatorOne.UpdateColorA(time, 0, (NiColorA&)secondColor);
    color = aFirstColor.AddDelta(Object_ProcessAndReturnValue_00532f40(blend, secondColor.FUN_00532ec0(aFirstColor)));
    color.a *= strength_15;
    BSClamp_float(color.a, 0.0f, 1.0f);
    manager4->FUN_00b8b540((NiColorA&)color);
    pPreviousModifier->m_kColorInterpolatorTwo.UpdateColorA(time, 0, (NiColorA&)aFirstColor);
    pNextModifier->m_kColorInterpolatorTwo.UpdateColorA(time, 0, (NiColorA&)secondColor);
    color = aFirstColor.AddDelta(Object_ProcessAndReturnValue_00532f40(blend, secondColor.FUN_00532ec0(aFirstColor)));
    color.a *= strength_15;
    BSClamp_float(color.a, 0.0f, 1.0f);
    manager4->FUN_00b8b610((NiColorA&)color);
    float firstValue, secondValue3;
    pPreviousModifier->m_kFloatInterpolatorOne.UpdateFloat(time, 0, firstValue);
    pNextModifier->m_kFloatInterpolatorOne.UpdateFloat(time, 0, secondValue3);
    float blur2 = firstValue + blend * (secondValue3 - firstValue);
    pPreviousModifier->m_kFloatInterpolatorTwo.UpdateFloat(time, 0, firstValue);
    pNextModifier->m_kFloatInterpolatorTwo.UpdateFloat(time, 0, secondValue3);
    float doubleVision = firstValue + blend * (secondValue3 - firstValue);
    pPreviousModifier->m_kFloatInterpolatorNine.UpdateFloat(time, 0, firstValue);
    pNextModifier->m_kFloatInterpolatorNine.UpdateFloat(time, 0, secondValue3);
    float kRadialStrength = firstValue + blend * (secondValue3 - firstValue);
    pPreviousModifier->m_kFloatInterpolatorTen.UpdateFloat(time, 0, firstValue);
    pNextModifier->m_kFloatInterpolatorTen.UpdateFloat(time, 0, secondValue3);
    float radialRampUp_19 = firstValue + blend * (secondValue3 - firstValue);
    pPreviousModifier->m_kFloatInterpolatorEleven.UpdateFloat(time, 0, firstValue);
    pNextModifier->m_kFloatInterpolatorEleven.UpdateFloat(time, 0, secondValue3);
    float radialStart_8 = firstValue + blend * (secondValue3 - firstValue);
    pPreviousModifier->m_kFloatInterpolatorThree.UpdateFloat(time, 0, firstValue);
    pNextModifier->m_kFloatInterpolatorThree.UpdateFloat(time, 0, secondValue3);
    float radialRampDown_15 = firstValue + blend * (secondValue3 - firstValue);
    pPreviousModifier->m_kFloatInterpolatorFour.UpdateFloat(time, 0, firstValue);
    pNextModifier->m_kFloatInterpolatorFour.UpdateFloat(time, 0, secondValue3);
    float radialDownStart_3 = firstValue + blend * (secondValue3 - firstValue);
    pPreviousModifier->m_kFloatInterpolatorFive.UpdateFloat(time, 0, firstValue);
    pNextModifier->m_kFloatInterpolatorFive.UpdateFloat(time, 0, secondValue3);
    float depthStrength_4 = firstValue + blend * (secondValue3 - firstValue);
    float firstDepthDistance_, secondDepthDistance, firstDepthRange_2, secondDepthRange_12;
    pPreviousModifier->m_kFloatInterpolatorSix.UpdateFloat(time, 0, firstDepthDistance_);
    pNextModifier->m_kFloatInterpolatorSix.UpdateFloat(time, 0, secondDepthDistance);
    pPreviousModifier->m_kFloatInterpolatorSeven.UpdateFloat(time, 0, firstDepthRange_2);
    pNextModifier->m_kFloatInterpolatorSeven.UpdateFloat(time, 0, secondDepthRange_12);
    pPreviousModifier->m_kFloatInterpolatorEight.UpdateFloat(time, 0, firstValue);
    pNextModifier->m_kFloatInterpolatorEight.UpdateFloat(time, 0, secondValue3);
    float motion_24 = firstValue + blend * (secondValue3 - firstValue);
    blur2 *= strength_15;
    BSClamp_float(blur2, 0.0f, 7.0f);
    manager4->RaiseHighestBlurRadius(blur2);
    manager4->ApplyDoubleVisionParamModifier_00b8afb0(doubleVision * strength_15);
    BlendPoint aFirstCenter(0.5f, 0.5f), secondCenter5(0.5f, 0.5f), center7;
    if (pPreviousModifier->Data.m_bUseRadialBlur && previousTarget)
    {
        previousTarget->UpdateWorldBound();
        manager4->GetRadialBlurCenterFromWorldBound((void*)&previousTarget->NiAVObject_GetWorldBound(), (NiPoint2*)&aFirstCenter);
    }
    if (pNextModifier->Data.m_bUseRadialBlur && nextTarget)
    {
        previousTarget->UpdateWorldBound();
        manager4->GetRadialBlurCenterFromWorldBound((void*)&nextTarget->NiAVObject_GetWorldBound(), (NiPoint2*)&secondCenter5);
    }
    if (!pPreviousModifier->Data.m_bUseRadialBlur)
        aFirstCenter = (const BlendPoint&)pPreviousModifier->Data.m_kRadialBlurCenter;
    if (!pNextModifier->Data.m_bUseRadialBlur)
        secondCenter5 = (const BlendPoint&)pNextModifier->Data.m_kRadialBlurCenter;
    center7 = aFirstCenter.AddPointComponents(FUN_00532fd0(blend, secondCenter5.Subtract(aFirstCenter)));
    manager4->SetRadialBlurParameters(kRadialStrength * strength_15, radialRampUp_19, radialStart_8, radialRampDown_15,
                                      radialDownStart_3, (const NiPoint2&)center7);
    BlendPoint firstDepthB(0, 0), secondDepth(0, 0), depth5;
    if (pPreviousModifier->Data.m_bUseEffectEntries && previousTarget)
    {
        previousTarget->UpdateWorldBound();
        manager4->GetDepthOfFieldParamsFromWorldBound((void*)&previousTarget->NiAVObject_GetWorldBound(), (NiPoint2*)&firstDepthB);
    }
    if (pNextModifier->Data.m_bUseEffectEntries && nextTarget)
    {
        nextTarget->UpdateWorldBound();
        manager4->GetDepthOfFieldParamsFromWorldBound((void*)&nextTarget->NiAVObject_GetWorldBound(), (NiPoint2*)&secondDepth);
    }
    if (!pPreviousModifier->Data.m_bUseEffectEntries)
        firstDepthB = BlendPoint(firstDepthDistance_, firstDepthRange_2);
    if (!pNextModifier->Data.m_bUseEffectEntries)
        secondDepth = BlendPoint(secondDepthDistance, secondDepthRange_12);
    depth5 = firstDepthB.AddPointComponents(FUN_00532fd0(blend, secondDepth.Subtract(firstDepthB)));
    manager4->SetDepthOfFieldParameters(depthStrength_4 * strength_15,
                                        blend < 0.5 ? pPreviousModifier->Data.m_ucEffectMode
                                                    : pNextModifier->Data.m_ucEffectMode,
                                        0.0f, depth5.x, depth5.y);
    manager4->RaiseBlurRadius(motion_24);
}
