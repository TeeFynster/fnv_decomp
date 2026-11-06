// Legacy impact-data layout and unit-local loading helpers.
#ifndef FNV_TASK_BGSIMPACTDATA_COPY_H
#define FNV_TASK_BGSIMPACTDATA_COPY_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "../../include/TESForm.h"
#include "../../include/BGSImpactData__IMPACT_DATA_DATA.h"
#include "../../include/BGSTextureSet.h"
#include "../../include/FileEntryList.h"
#include "../../include/TESModel.h"
#include "../../include/TESSound.h"
#include "TESFile.h"
enum BGSImpactData__ORIENTATION
{
    BGSImpactData__ORIENTATION_ORIENT_SURFACE_NORMAL = 0,
    BGSImpactData__ORIENTATION_ORIENT_PROJ_VECTOR = 1,
    BGSImpactData__ORIENTATION_ORIENT_PROJ_REFLECT = 2,
    BGSImpactData__ORIENTATION_ORIENT_COUNT = 3
};
#pragma pack(push, 4)
class BGSImpactData__OLD_IMPACT_DATA_DATA
{
  public:
    // The 2008 Load keeps its 56-byte oldData local in the /GS buffer class
    // (security cookie last, above only the this spill), which MSVC 9 does
    // for structs containing an array. The raw overlay below recovers that
    // codegen category; all field offsets and the 56-byte size are unchanged.
    union
    {
        struct
        {
            float m_fDecalMinWidth;                     // +0x0, 4 bytes
            float m_fEffectDuration;                    // +0x4, 4 bytes
            float m_fParallaxScale;                     // +0x8, 4 bytes
            BGSImpactData__ORIENTATION m_eOrientation;  // +0xC, 4 bytes
            unsigned char cFlags;                       // +0x10, 1 bytes
            unsigned char m_ucParallaxPasses;           // +0x11, 1 bytes
            unsigned char layoutPadding12[2];
            float m_fDecalMaxWidth;     // +0x14, 4 bytes
            float m_fProjectionDepth;   // +0x18, 4 bytes
            float m_fDecalMinHeight;    // +0x1C, 4 bytes
            float m_fDecalMaxHeight;    // +0x20, 4 bytes
            float m_fShininess;         // +0x24, 4 bytes
            float m_fAngleThreshold;    // +0x28, 4 bytes
            float m_fPlacementRadius;   // +0x2C, 4 bytes
            unsigned int iColor;        // +0x30, 4 bytes
            SOUND_LEVEL m_eSoundLevel;  // +0x34, 4 bytes
        };
        unsigned int rawChunkData[14];  // +0x0, 56 bytes
    };
    void Endian();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSImpactData__OLD_IMPACT_DATA_DATA) == 56);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fDecalMinWidth) == 0);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fEffectDuration) == 4);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fParallaxScale) == 8);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_eOrientation) == 12);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, cFlags) == 16);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_ucParallaxPasses) == 17);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fDecalMaxWidth) == 20);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fProjectionDepth) == 24);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fDecalMinHeight) == 28);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fDecalMaxHeight) == 32);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fShininess) == 36);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fAngleThreshold) == 40);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fPlacementRadius) == 44);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, iColor) == 48);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_eSoundLevel) == 52);
// TESFile accessors and initialization helpers used by LoadForm/InitItem.
struct TESFileFormInt : public TESFile
{
    int GetTESForm();
};
struct TESFileFormVersion : public TESFile
{
    unsigned short GetFormVersion();
};
struct TESFormInitFlag : public TESForm
{
    bool IsFormInitialized() const;
    static TESForm* GetFormByID(unsigned int formID);
};
int Warning(const char* format, ...);
#endif
