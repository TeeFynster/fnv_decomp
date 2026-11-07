
// src/gamebryo2.2/corelibs/nianimation/nikeybasedinterpolator_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nianimation/nikeybasedinterpolator.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiKeyBasedInterpolator.h"
#include "../../../../include/NiQuaternion.h"
#include "../../../../include/StrArr.h"

// NiQuaternion component-wise inequality comparison.
// Returns true when any of the four quaternion components differs.
// @fnv 0x0064a290
bool NiQuaternion::operator!=(const NiQuaternion& kOther) const
{
    return m_fVectorX != kOther.m_fVectorX || m_fVectorY != kOther.m_fVectorY || m_fVectorZ != kOther.m_fVectorZ ||
           m_fScalarPart != kOther.m_fScalarPart;
}

// @fnv 0x00a3ca10
NiKeyBasedInterpolator::NiKeyBasedInterpolator() throw()
{
}

extern "C" void __cdecl operator delete(void*, unsigned int);
extern "C" void* DAT_01097054;

// @fnv 0x00a3ca50
NiKeyBasedInterpolator* __fastcall DeleteKeyBasedInterpolator(NiKeyBasedInterpolator* self, void*, unsigned int flags)
{
    *reinterpret_cast<void**>(self) = &DAT_01097054;
    self->NiInterpolator::~NiInterpolator();
    if (flags & 1)
        ::operator delete(self, 0xc);
    return self;
}

// The shared class has no declaration for the indexed-key helper.
// @fnv 0x00a3ca80
NiAnimationKey* __fastcall GetInterpolatorKey(NiKeyBasedInterpolator* self, void*, unsigned int uiWhichKey,
                                          unsigned short usChannel)
{
    unsigned char stride = self->GetColorKeySize(usChannel);
    NiAnimationKey* keys = self->GetChannelKeys(usChannel);
    return (NiAnimationKey*)((char*)keys + uiWhichKey * stride);
}

namespace fnv_00a3cbf0 {
extern "C" void NiInterpolator_GetViewerStrings();
char* _FUN_00a7d330(const char*);
extern const char* _DAT_011f3740;

// The StrArr viewer-string overload is not declared by the shared class.
// @fnv 0x00a3cbf0
void __fastcall GetKeyBasedViewerStrings(NiKeyBasedInterpolator* self, void*, StrArr* pkStrings)
{
    typedef void(__thiscall * GetBaseViewerStrings)(NiInterpolator*, StrArr*);
    reinterpret_cast<GetBaseViewerStrings>(NiInterpolator_GetViewerStrings)(self, pkStrings);
    char* pcStr = _FUN_00a7d330(_DAT_011f3740);
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiSize, pcStr);
}
}  // namespace fnv_00a3cbf0

#include "../../../../include/NiAnimationKey.h"

static NiAnimationKey* KeyAt(NiAnimationKey* pkKeys, unsigned int uiIndex, unsigned char ucSize)
{
    return (NiAnimationKey*)((char*)pkKeys + uiIndex * ucSize);
}

extern float DAT_0109704c;
extern float DAT_01015f5c;

// @fnv 0x00a3cac0
void NiKeyBasedInterpolator::GetInterpolatorTimeRange(float& fBeginKeyTime, float& fEndKeyTime) const
{
    fBeginKeyTime = DAT_0109704c;
    fEndKeyTime = DAT_01015f5c;
    for (unsigned int us = 0; us < GetKeyChannelCount(); us++)
    {
        NiAnimationKey* pkBeginKey = KeyAt(GetChannelKeys(us), 0, GetColorKeySize(us));
        unsigned int uiLast = GetColorKeyCount(us) - 1;
        NiAnimationKey* pkEndKey = KeyAt(GetChannelKeys(us), uiLast, GetColorKeySize(us));
        if (pkBeginKey && pkEndKey)
        {
            if (pkBeginKey->m_fTime < fBeginKeyTime)
                fBeginKeyTime = pkBeginKey->m_fTime;
            if (pkEndKey->m_fTime > fEndKeyTime)
                fEndKeyTime = pkEndKey->m_fTime;
        }
    }
    if (fBeginKeyTime == 3.4028234663852886e+38 && fEndKeyTime == -3.4028234663852886e+38)
    {
        fBeginKeyTime = 0.0f;
        fEndKeyTime = 0.0f;
    }
}
