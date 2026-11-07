
// src/fallout_shared/tesleveledlist_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Ob1 /Oy- /GS /EHsc /Gy /GF (unit src/fallout_shared/tesleveledlist.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../include/BGSCameraPath.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSLoadGameBuffer.h"
#include "../../include/BSFile.h"
#include "../../include/BaseProcess.h"
#include "../../include/ExtraDataList.h"
#include "../../include/FileEntryList.h"
#include "../../include/HighProcess.h"
#include "../../include/TESContainer.h"
#include "../../include/TESFile.h"
#include "../../include/TESForm.h"
#include "../../include/TESGlobal.h"
#include "../../include/TESLeveledList.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/bhkLiquidAction.h"
#include "tesleveledlist_decls.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiPoint3.h"
extern "C" double __cdecl floor(double value);
extern "C" int __cdecl _ftol2_sse();
unsigned int DialogueRandom();

extern const char str_010c3570[];
extern const char str_010c3568[];
extern const char str_01015a9c[];

inline const char* NiRTTI::GetName() const
{
    return m_pcName;
}

#include "../../include/NiTPrimitiveArray.h"

extern "C" unsigned int __cdecl strlen(const char* s);
void* NiMalloc(unsigned int uiSize);
int NiSprintf(char* pcDest, unsigned int uiDestSize, const char* pcFormat, ...);

inline char* NiPoint3::FormatToBuffer(const char* pcPrefix) const
{
    unsigned int uiLen = strlen(pcPrefix) + 64;
    char* pcString = (char*)NiMalloc(uiLen);
    NiSprintf(pcString, uiLen, "%s = (%g, %g, %g)", pcPrefix, x, y, z);
    return pcString;
}

inline char* CreateDebugString(const char* pcText)
{
    unsigned int uiLen = strlen(pcText) + 9;
    char* pcString = (char*)NiMalloc(uiLen);
    NiSprintf(pcString, uiLen, "%s", pcText);
    return pcString;
}

inline char* CreateDebugString(const char* pcPrefix, float fValue)
{
    unsigned int uiLen = strlen(pcPrefix) + 20;
    char* pcString = (char*)NiMalloc(uiLen);
    double dValue = fValue;
    NiSprintf(pcString, uiLen, "%s = %g", pcPrefix, dValue);
    return pcString;
}

class NiBaseModifier
{
  public:
    void* m_ppVirtualMethodTable;
    int m_iRefCount;
    int m_unk08;
    void GetViewerStrings(NiViewerStringsArray* pkStrings);
};

class NiPointModifier : public NiBaseModifier
{
  public:
    float GetAttributeStrength() const
    {
        return m_fValue;
    }
    void BSMultiBoundCapsule_GetViewerStrings(NiViewerStringsArray* pkStrings);

    static NiRTTI ms_kRTTI;
    NiPoint3 m_kPathOffset;
    NiPoint3 m_kLightVector;
    float m_fValue;
};

// @fnv 0x00c61120
// src: XBOX_PDB 0x00c61120
void NiPointModifier::BSMultiBoundCapsule_GetViewerStrings(NiViewerStringsArray* pkStrings)
{
    NiBaseModifier::GetViewerStrings(pkStrings);
    pkStrings->Add(CreateDebugString(static_cast<const NiRTTI&>(ms_kRTTI).GetName()));
    pkStrings->Add(m_kPathOffset.FormatToBuffer(str_010c3570));
    pkStrings->Add(m_kLightVector.FormatToBuffer(str_010c3568));
    pkStrings->Add(CreateDebugString(str_01015a9c, GetAttributeStrength()));
}
