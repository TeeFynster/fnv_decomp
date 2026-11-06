#include "../../include/NiRect.h"
#include "../../include/BSSimpleArray.h"
// bscore/bssimplearray_private_decls.h: declares BSSimpleArrayPacketEffect, BSSimpleArrayPacketDebug, PacketNodeRecord, PathingGraphNode and more
#ifndef FNV_BSSIMPLEARRAY_PRIVATE_DECLS_H
#define FNV_BSSIMPLEARRAY_PRIVATE_DECLS_H

#include "../../include/BSScrapArray.h"
#include "../../include/NiNode.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiRect.h"
#include "../../include/PathingAvoidNode.h"
#include "../../include/PathingGraphNode.h"


// Canonical placeholder for the runtime copy routine at 0x00ec7230 (_memmove is 0x00ec44d0).
void* __cdecl FUN_00ec7230(void*, const void*, unsigned int);
extern "C" void* __cdecl bsearch(const void*, const void*, unsigned int, unsigned int, BSSimpleArrayCompare);

extern unsigned int DAT_0106c264;
extern unsigned int DAT_0106f798;
extern unsigned int DAT_01073e50;
class BSSimpleArrayPacketEffect
{
  public:
    void FUN_007883b0(unsigned int, bool);
};
extern unsigned int DAT_0109504c;
class BSSimpleArrayPacketDebug
{
  public:
    void InitArray(unsigned int, bool);
};

class TESObjectREFR;

class PacketNodeRecord
{
    char storage[0x30];
};
class BSSimpleArrayPacketNode
{
  public:
    void FUN_006d0510(unsigned int);
};
class BSSimpleArrayPacketReserve
{
  public:
    unsigned int FUN_00761540();
};

#include <stddef.h>
#define FNV_BSSA_JOIN_I(a, b) a##b
#define FNV_BSSA_JOIN(a, b) FNV_BSSA_JOIN_I(a, b)
#define FNV_BSSA_ASSERT(x) typedef char FNV_BSSA_JOIN(bssimplearray_assert_, __LINE__)[(x) ? 1 : -1]
namespace Tile {
class Value;
}
class BGSBodyPart;
class BGSReconstructFormsMap;
class OffsetData
{
  public:
    unsigned int iOffset;
    BGSReconstructFormsMap* m_pFormLookupMap;
};
class ScrapHeapBuffer
{
  public:
    void Deallocate(void* memory);
};
class ButtonIcon
{
  public:
    float m_fGlyphWidthInPixels, m_fHorizontalOffset, m_fGlyphVerticalOffset, m_fHorizontalSpacing;
    NiRect<float> m_kTextureCoordinates;
};
#include "../../include/SANDBOX_PROCEDURE.h"
class SandboxProcedureData
{
  public:
    TESObjectREFR* pTarget;
    SANDBOX_PROCEDURE eProcedure;
    int m_iActivityState, m_iProcedureData;
    SandboxProcedureData();
};
// This real specialization isolates its private helper ABI from legacy accepted declarations.


typedef BSSimpleArray<Tile::Value*, 8> BSSimpleArrayTileLayout;
typedef BSScrapArray<OffsetData, 1024> BSScrapArrayOffsetLayout;
FNV_BSSA_ASSERT(sizeof(BSSimpleArrayTileLayout) == 16);
FNV_BSSA_ASSERT(offsetof(BSSimpleArrayTileLayout, pBuffer) == 4);
FNV_BSSA_ASSERT(offsetof(BSSimpleArrayTileLayout, iSize) == 8);
FNV_BSSA_ASSERT(offsetof(BSSimpleArrayTileLayout, SimpleArrayStorage) == 12);
FNV_BSSA_ASSERT(sizeof(BSScrapArrayOffsetLayout) == 20);
FNV_BSSA_ASSERT(offsetof(BSScrapArrayOffsetLayout, m_pAllocator) == 16);
typedef BSSimpleArray<PathingAvoidNode, 1024> BSSimpleArrayAvoidLayout;
FNV_BSSA_ASSERT(sizeof(BSSimpleArrayAvoidLayout) == 16);
FNV_BSSA_ASSERT(offsetof(BSSimpleArrayAvoidLayout, pBuffer) == 4);
FNV_BSSA_ASSERT(offsetof(BSSimpleArrayAvoidLayout, iSize) == 8);
FNV_BSSA_ASSERT(offsetof(BSSimpleArrayAvoidLayout, SimpleArrayStorage) == 12);
FNV_BSSA_ASSERT(sizeof(OffsetData) == 8);
FNV_BSSA_ASSERT(offsetof(OffsetData, iOffset) == 0);
FNV_BSSA_ASSERT(offsetof(OffsetData, m_pFormLookupMap) == 4);
FNV_BSSA_ASSERT(sizeof(NiRect<float>) == 16);
FNV_BSSA_ASSERT(offsetof(NiRect<float>, m_fMinimumU) == 0);
FNV_BSSA_ASSERT(offsetof(NiRect<float>, m_fMaximumU) == 4);
FNV_BSSA_ASSERT(offsetof(NiRect<float>, m_fMinimumV) == 8);
FNV_BSSA_ASSERT(offsetof(NiRect<float>, m_fMaximumV) == 12);
FNV_BSSA_ASSERT(sizeof(ButtonIcon) == 32);
FNV_BSSA_ASSERT(offsetof(ButtonIcon, m_fGlyphWidthInPixels) == 0);
FNV_BSSA_ASSERT(offsetof(ButtonIcon, m_fHorizontalOffset) == 4);
FNV_BSSA_ASSERT(offsetof(ButtonIcon, m_fGlyphVerticalOffset) == 8);
FNV_BSSA_ASSERT(offsetof(ButtonIcon, m_fHorizontalSpacing) == 12);
FNV_BSSA_ASSERT(offsetof(ButtonIcon, m_kTextureCoordinates) == 16);
FNV_BSSA_ASSERT(sizeof(SandboxProcedureData) == 16);
FNV_BSSA_ASSERT(offsetof(SandboxProcedureData, pTarget) == 0);
FNV_BSSA_ASSERT(offsetof(SandboxProcedureData, eProcedure) == 4);
FNV_BSSA_ASSERT(offsetof(SandboxProcedureData, m_iActivityState) == 8);
FNV_BSSA_ASSERT(offsetof(SandboxProcedureData, m_iProcedureData) == 12);
FNV_BSSA_ASSERT(sizeof(NiPoint3) == 12);
FNV_BSSA_ASSERT(offsetof(NiPoint3, x) == 0);
FNV_BSSA_ASSERT(offsetof(NiPoint3, y) == 4);
FNV_BSSA_ASSERT(offsetof(NiPoint3, z) == 8);
FNV_BSSA_ASSERT(sizeof(PathingAvoidNode) == 36);
FNV_BSSA_ASSERT(offsetof(PathingAvoidNode, m_kLocation) == 0);
FNV_BSSA_ASSERT(offsetof(PathingAvoidNode, TwoComponentVector) == 12);
FNV_BSSA_ASSERT(offsetof(PathingAvoidNode, fRadius) == 24);
FNV_BSSA_ASSERT(offsetof(PathingAvoidNode, m_fPathingCostCur) == 28);
FNV_BSSA_ASSERT(offsetof(PathingAvoidNode, eType) == 32);

#endif
