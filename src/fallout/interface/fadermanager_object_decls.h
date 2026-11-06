// fallout/interface/fadermanager_object_decls.h: private FaderManager declarations
#ifndef FADERMANAGER_OBJECT_DECLS_H
#define FADERMANAGER_OBJECT_DECLS_H

// File-static fader table and private manager layout.
#include <stddef.h>

template <int> struct FNVAssert;
template <> struct FNVAssert<1>
{
};
#define FNV_STATIC_ASSERT(cond) typedef FNVAssert<(cond) ? 1 : 0> FNVAssertLine##__LINE__

#include "../../../include/FADER_ENUM.h"

// These private helpers use the game's sized deallocation during constructor unwinding.
#include "../../../include/NiMemObject.h"

class FaderManager
{
  public:
    NiNode* m_pRootBelowMenus;  // +0x0
    NiNode* m_pRootAboveMenus;  // +0x4
    bool HasFader(FADER_ENUM eFader);
    float GetFadeValue(FADER_ENUM eFader);
    void StopFader(FADER_ENUM eFader, bool bForce);
    void AdvanceFaders(bool bUpdate);
    void AddFader(FADER_ENUM eFader, float fDuration, bool bFadeOut);
    void AddRoot(NiNode* pParent, float m_fProjectionDepth, bool m_bUseAlternateRoot);
};
FNV_STATIC_ASSERT(sizeof(FaderManager) == 8);
FNV_STATIC_ASSERT(offsetof(FaderManager, m_pRootBelowMenus) == 0);
FNV_STATIC_ASSERT(offsetof(FaderManager, m_pRootAboveMenus) == 4);

// One entry per FADER_ENUM value (FADER_COUNT == 3); entry size is 0x1C.
struct FaderEntry
{
    bool m_bUseAlternateRoot;  // +0x00
    unsigned char pad01[3];
    const char* pTextureName;  // +0x04
    bool bUnk08;               // +0x08
    unsigned char pad09[3];
    float fUnk0C;                     // +0x0C
    BSFadeNode* pFadeNode;            // +0x10
    float fAlpha;                     // +0x14
    NiPointer<NiNode> m_pParentNode;  // +0x18
};
FNV_STATIC_ASSERT(sizeof(FaderEntry) == 0x1C);
FNV_STATIC_ASSERT(offsetof(FaderEntry, bUnk08) == 0x08);
FNV_STATIC_ASSERT(offsetof(FaderEntry, fUnk0C) == 0x0C);
FNV_STATIC_ASSERT(offsetof(FaderEntry, pFadeNode) == 0x10);
FNV_STATIC_ASSERT(offsetof(FaderEntry, fAlpha) == 0x14);
FNV_STATIC_ASSERT(offsetof(FaderEntry, m_pParentNode) == 0x18);

static FaderEntry s_faders[FADER_ENUM_FADER_COUNT];
static bool s_bAllowDetach;
extern const float s_faderClearedAlpha;
extern TES* g_TES;

#endif
