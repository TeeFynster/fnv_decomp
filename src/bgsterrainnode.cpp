#include "../include/BGSDistantTreeBlock.h"

// fallout_shared/distant terrain system/bgsterrainnode.cpp
// BGSTerrainNode::BGSTerrainNode (0x006fd210).
//
// Recursive distant-terrain quad-tree node constructor: nulls the payload
// pointers, derives the node center/corner radius from the base cell and
// level size, subdivides while above the manager minimum, then derives the
// split/morph distances from the [TerrainManager] INI mults.

#include <float.h>
#include <stddef.h>
#include "../include/NiPoint2.h"
#include "../include/TES.h"
#include "../include/BSSimpleList.h"
#include "../include/TESFile.h"
#include "../include/TESWorldSpace.h"
#include "../include/NiNode.h"
#include "../include/Tile.h"
#include "../include/AnimIdle.h"
#include "../include/GO.h"
#include "../include/GameTimerRecord.h"
#include "../include/AutoMemContext.h"
#include "../include/SettingT_GameSettingCollection_.h"

#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]

#include "../include/MEM_CONTEXT.h"
#include "../include/BGSTerrainManager.h"
#include "../include/BGSTerrainNode.h"

// Shared DistantTreeBlockLocal_006fe330 is 0x35 bytes; the game allocates 0x4C at 0x006FE3D1.
// Keep this local definition until the approved shared layout supports that size.
// local form of BGSDistantTreeBlock: 0x006fe330 needs the 0x4c-byte allocation; the shared layout changes its allocation immediate (one byte differs).
class DistantTreeBlockLocal_006fe330
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C,
        unk40, unk44, unk48;
    DistantTreeBlockLocal_006fe330(BGSTerrainNode* pNode, unsigned int uiTreeBlockIndex, unsigned short sX, unsigned short sY);
    ~DistantTreeBlockLocal_006fe330();
    bool IsLoaded();
    void Prepare();
    void Attach();
};
class BGSTerrainManager;
class BGSTerrainChunk;
class BGSDistantObjectBlock;


extern SettingT_GameSettingCollection_ fSplitDistanceMult;
extern SettingT_GameSettingCollection_ fMorphStartDistanceMult;
extern SettingT_GameSettingCollection_ fMorphEndDistanceMult;
extern SettingT_GameSettingCollection_ bKeepLowDetailTerrain;

int Warning(const char* aFormat, ...);

extern "C" void* memset(void* pDestination, int cValue, unsigned int uSize);

FNV_STATIC_ASSERT(sizeof(BGSTerrainNode) == 96);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, pManager) == 0);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, iLevel) == 4);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_sX) == 8);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_sY) == 10);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_bWithinMaximumLevel) == 12);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_bNodeStateFlag) == 13);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, pChunk) == 16);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, pBlock) == 20);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, pTrees) == 24);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_pSceneNode) == 28);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, pChildren) == 32);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, pParent) == 48);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, Center) == 52);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_fNodeRadius) == 64);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_fSplitDistance) == 68);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_fMorphStartDistance) == 72);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_fMorphEndDistance) == 76);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, TerrainNodeData) == 80);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_bFlagBeforeParentPosition) == 84);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_eParentPosition) == 88);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_bPersistent) == 92);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_bNodeInitialized) == 93);

const char kBGSTerrainNodeFileLabel[] =
    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Distant Terrain System\\BGSTerrainNode.cpp";
const int kBGSTerrainNodeCtorLine = 76;
const char kInvalidMorphDistances[] =
    "MODELS: Morph distances are invalid.  Please ensure that fMorphDistanceMult is less than fSplitDistanceMult under [TerrainManager] in the INI (or delete both)";

// Initializes a terrain node: stores manager/parent/level/coords, computes center and distances, and recursively creates four child nodes unless at min level.
// @fnv 0x006fd210
BGSTerrainNode::BGSTerrainNode(BGSTerrainManager* pManagerArg, BGSTerrainNode* pParentArg, short sX, short sY,
                               unsigned int uiSize, bool bPersistentArg)
{
    AutoMemContext fCornerX(MEM_CONTEXT_MEM_CONTEXT_LODMANAGER, true, kBGSTerrainNodeFileLabel,
                            kBGSTerrainNodeCtorLine);
    m_bNodeInitialized = true;
    pChunk = 0;
    pBlock = 0;
    pTrees = 0;
    pManager = pManagerArg;
    pParent = pParentArg;
    iLevel = uiSize;
    m_sX = sX;
    m_sY = sY;
    for (int i = 0; i < 4; i++)
        pChildren[i] = 0;
    if (uiSize <= pManager->GetMaxLevel())
        m_bWithinMaximumLevel = true;
    else
        m_bWithinMaximumLevel = false;
    float fCenterX = (float)(iLevel << 12);
    float fCornerY = m_sX * 4096.0 + fCenterX * 0.5;
    float fZ = m_sY * 4096.0 + fCenterX * 0.5;
    float fMin = m_sX * 4096.0;
    float kCtx = m_sY * 4096.0;
    NiPoint3 corner(fMin, kCtx, 0.0f);
    Center = NiPoint3(fCornerY, fZ, 0.0f);
    m_fNodeRadius = static_cast<const NiPoint3&>(Center - corner).ComputeMagnitude();
    m_bPersistent = bPersistentArg;
    if (uiSize > pManager->GetMinLevel())
    {
        unsigned int uH = iLevel >> 1;
        short sMX = m_sX + (iLevel >> 1);
        short sMid = m_sY + (iLevel >> 1);
        bool bChildPersistent = false;
        if (*bKeepLowDetailTerrain.FUN_00408d60() && uH == pManager->GetMaxLevel())
            bChildPersistent = true;
        pChildren[0] = new BGSTerrainNode(pManager, this, m_sX, m_sY, uH, bChildPersistent);
        pChildren[1] = new BGSTerrainNode(pManager, this, m_sX, sMid, uH, bChildPersistent);
        pChildren[2] = new BGSTerrainNode(pManager, this, sMX, m_sY, uH, bChildPersistent);
        pChildren[3] = new BGSTerrainNode(pManager, this, sMX, sMid, uH, bChildPersistent);
        pChildren[0]->m_eParentPosition = BGSTerrainNode__PARENT_POSITION_PP_UPPER_LEFT;
        pChildren[1]->m_eParentPosition = BGSTerrainNode__PARENT_POSITION_PP_LOWER_LEFT;
        pChildren[2]->m_eParentPosition = BGSTerrainNode__PARENT_POSITION_PP_UPPER_RIGHT;
        pChildren[3]->m_eParentPosition = BGSTerrainNode__PARENT_POSITION_PP_LOWER_RIGHT;
        m_fSplitDistance = m_fNodeRadius * fSplitDistanceMult.Float()->f;
    }
    else
    {
        memset(pChildren, 0, sizeof(pChildren));
        m_fSplitDistance = 0.0f;
    }
    if (pParent)
    {
        m_fMorphStartDistance = pParent->m_fNodeRadius * fMorphStartDistanceMult.Float()->f;
        m_fMorphEndDistance = pParent->m_fNodeRadius * fMorphEndDistanceMult.Float()->f;
        if (m_fMorphEndDistance > m_fMorphStartDistance)
            Warning(kInvalidMorphDistances);
    }
    else
    {
        m_fMorphStartDistance = FLT_MIN;
        m_fMorphEndDistance = FLT_MAX;
        m_eParentPosition = BGSTerrainNode__PARENT_POSITION_PP_TOPLEVEL;
    }
    m_bNodeStateFlag = false;
}

struct FUN_00485b60
{
    unsigned int TESForm_GetFormIDWithoutIndex();
    TESFile* GetFile(int);
    unsigned int Go();
};
// Calls FUN_00485bc0, checks whether the first file's list is non-empty, and ORs that flag into bit 24 of the result.
// @fnv 0x00485b60
unsigned int FUN_00485b60::Go()
{
    char flag;
    unsigned int result;
    TESFile* file;
    result = TESForm_GetFormIDWithoutIndex();
    flag = 0;
    file = GetFile(0);
    if (!file->GetMasterList_00464df0()->IsEmpty())
        flag = 1;
    result |= flag << 24;
    return result;
}

struct FUN_006fca40
{
    void* Del(unsigned int);
};
struct FUN_006fd7b0
{
    void Go(int);
};
struct FUN_006fd750
{
    void Unload();
};
// Calls Go(7), then for each of the four pointers at offset 0x20 calls Del(1) on the non-null ones.
// @fnv 0x006fd750
void FUN_006fd750::Unload()
{
    ((FUN_006fd7b0*)this)->Go(7);
    for (int i = 0; i < 4; i++)
    {
        FUN_006fca40* c = ((FUN_006fca40**)((char*)this + 0x20))[i];
        FUN_006fca40* p = c;
        p ? p->Del(1) : 0;
    }
}

extern int DAT_011d8670;

// @fnv 0x006fd8e0
// src: COMMUNITY 0x006fd8e0
int __cdecl BGSTerrainManager_GetActive()
{
    return DAT_011d8670;
}

void __cdecl operator delete(void*);
struct FUN_006fa420
{
    void Dtor();
};
struct FUN_006fd8f0
{
    void* Del(unsigned int flags);
};
// Calls Dtor on this object, frees it with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006fd8f0
void* FUN_006fd8f0::Del(unsigned int flags)
{
    ((FUN_006fa420*)this)->Dtor();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl operator delete(void*);
struct FUN_006f5370
{
    void Dtor();
};
struct FUN_006fd920
{
    void* Del(unsigned int flags);
};
// Calls Dtor on this object, frees it with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006fd920
void* FUN_006fd920::Del(unsigned int flags)
{
    ((FUN_006f5370*)this)->Dtor();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_006fd980_shell;
struct Mgr
{
    FUN_006fd980_shell* _ref_00726070();
};
void BGSDistantTreeBlock_DeallocateStaticData();
struct FUN_006fd980_shell
{
    Mgr* pManager;
    int f4, f8;
    char fc;
    char m_bNodeStateFlag;
    char fe, ff;
    void* pChunk;
    void* pBlock;
    int f18, f1c;
    FUN_006fd980_shell* pChildren[4];
    void ClearSelectedParts(int a);
    void BGSTerrainNode_UnloadDataRecurse(int a);
};
// @fnv 0x006fd980
// src: COMMUNITY 0x006fd980
void FUN_006fd980_shell::BGSTerrainNode_UnloadDataRecurse(int aiFlags)
{
    if (pChunk || pBlock)
        ClearSelectedParts(aiFlags);
    for (int i = 0; i < 4; i++)
    {
        if (pChildren[i])
            pChildren[i]->BGSTerrainNode_UnloadDataRecurse(aiFlags);
    }
    m_bNodeStateFlag = 0;
    if (aiFlags & 4)
    {
        if (this == pManager->_ref_00726070())
            BGSDistantTreeBlock_DeallocateStaticData();
    }
}

struct FUN_006fe280_shell
{
    int f0;
    GO m;
    NiObj* GetNiObj(bool b);
};
// Returns a NiObj pointer: a null-initialized GO when b is true, otherwise the stored m member.
// @fnv 0x006fe280
NiObj* FUN_006fe280_shell::GetNiObj(bool abNull)
{
    return (abNull ? GO(0) : m);
}

struct FUN_006ff0a0
{
    bool Chk(int idx);
};
struct Ent
{
    int a;
    void* b;
    int c;
    int d;
    int e;
};
// Returns true when the Ent at index idx in the array at this+0xc4 has a null b pointer.
// @fnv 0x006ff0a0
bool FUN_006ff0a0::Chk(int aiIndex)
{
    return (*(Ent**)((char*)this + 0xc4))[aiIndex].b == 0;
}

struct FUN_006ff210_shell
{
    char pad[0x58];
    int mode;
    NiPoint2 BGSTerrainNode_SetFloatPairForLinkID();
};
// Returns a NiPoint2 chosen from the mode field: (0.5,0), (0.5,0.5), (0,0) or (0,0.5), defaulting to (0,0).
// @fnv 0x006ff210
// src: COMMUNITY 0x006ff210
NiPoint2 FUN_006ff210_shell::BGSTerrainNode_SetFloatPairForLinkID()
{
    float x, y;
    switch (mode)
    {
    case 1:
        x = 0.5f;
        y = 0.0f;
        break;
    case 3:
        x = 0.5f;
        y = 0.5f;
        break;
    case 2:
        x = 0.0f;
        y = 0.0f;
        break;
    case 4:
        x = 0.0f;
        y = 0.5f;
        break;
    default:
        x = y = 0.0f;
        break;
    }
    return NiPoint2(x, y);
}

// The shared SetBool declaration is nonvirtual; these terrain calls use slot 60.
typedef void (__thiscall* TerrainSetBoolFunction)(NiNode*, int, int, int);
#define SetTerrainNodeBool(node, index, enabled, value) \
    ((*reinterpret_cast<TerrainSetBoolFunction**>(node))[60](node, index, enabled, value))

namespace fnv_006ff2c0 {
struct Chunk
{
    int BGSTerrainChunk_GetTexture(int i);
};
struct Holder
{
    int f0, f4, f8, fc;
    Chunk* chunk;
};
extern AnimIdle g_timeGlobal;
struct FUN_006ff2c0_shell
{
    char pad[0x10];
    Tile* tile;
    char pad2[0x30 - 0x14];
    Holder* holder;
    char pad3[0x50 - 0x34];
    int section;
    bool flag;
    NiPoint2 BGSTerrainNode_SetFloatPairForLinkID();
    void UpdateTileFromChunk();
};
// @fnv 0x006ff2c0
void FUN_006ff2c0_shell::UpdateTileFromChunk()
{
    int c;
    NiNode* b;
    int a;
    c = holder->chunk->BGSTerrainChunk_GetTexture(0);
    a = holder->chunk->BGSTerrainChunk_GetTexture(1);
    b = reinterpret_cast<NiNode*>(tile->GetModel_0056c7f0());
    if (b)
    {
        SetTerrainNodeBool(b, 0, 1, c);
        SetTerrainNodeBool(b, 1, 1, a);
        NiPoint2 pt = BGSTerrainNode_SetFloatPairForLinkID();
        section = g_timeGlobal.GetSection();
        b->BSShaderPPLightingProperty_SetLODTexParams(pt.x, pt.y, 0.0f);
        flag = true;
    }
}
}  // namespace fnv_006ff2c0

struct FUN_006ff380_shell
{
    int f0, f4, f8, fc;
    Tile* tile;
    int f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c, f40, f44, f48, f4c, f50;
    char flag;
    void BGSTerrainNode_EndFade();
};
// @fnv 0x006ff380
// src: COMMUNITY 0x006ff380
void FUN_006ff380_shell::BGSTerrainNode_EndFade()
{
    NiNode* node;
    flag = 0;
    node = tile->GetModel_0056c7f0();
    if (node)
    {
        node->BSShaderPPLightingProperty_SetLODTexParams(0.0f, 0.0f, 1.0f);
        SetTerrainNodeBool(node, 0, 1, 0);
        SetTerrainNodeBool(node, 1, 1, 0);
    }
}

namespace fnv_006ff4c0 {
struct Inner
{
    unsigned int Conv() const;
};
struct Mgr
{
    unsigned int GetThreadID();
};
struct Block
{
    void BGSDistantObjectBlock_CreateApocalypseTask(unsigned int a, unsigned int b, unsigned short c, unsigned short d);
};
struct FUN_006ff4c0_shell
{
    Mgr* pManager;
    unsigned int iLevel;
    unsigned short m_sX;
    unsigned short m_sY;
    int fc, f10;
    Block* pBlock;
    int f18, f1c;
    FUN_006ff4c0_shell* pChildren[4];
    unsigned int _ref_00726070();
    Inner* Conv() const;
    void ProcessBlock();
};
// @fnv 0x006ff4c0
void FUN_006ff4c0_shell::ProcessBlock()
{
    if (_ref_00726070() == pManager->GetThreadID() && pBlock)
    {
        pBlock->BGSDistantObjectBlock_CreateApocalypseTask(Conv()->Conv(), iLevel, m_sX, m_sY);
    }
    else if (_ref_00726070() > pManager->GetThreadID())
    {
        for (int i = 0; i < 4; i++)
        {
            if (pChildren[i])
                pChildren[i]->ProcessBlock();
        }
    }
}
}  // namespace fnv_006ff4c0

struct FUN_006fda10_shell
{
    void* pad0[4];
    FUN_006fd8f0* pChunk;  // +0x10
    void* pad14[3];
    FUN_006fda10_shell* pChildren[4];  // +0x20
    char pad30[0x2c];
    bool m_bPersistent;  // +0x5c

    void BGSTerrainNode_DestroyRecurse();
};

// @fnv 0x006fda10
// src: COMMUNITY 0x006fda10
void FUN_006fda10_shell::BGSTerrainNode_DestroyRecurse()
{
    int i;

    if (pChunk && m_bPersistent)
    {
        FUN_006fd8f0* b = pChunk;
        FUN_006fd8f0* a = b;
        a ? a->Del(1) : 0;
        pChunk = 0;
    }

    for (i = 0; i < 4; i++)
    {
        if (pChildren[i])
            pChildren[i]->BGSTerrainNode_DestroyRecurse();
    }
}


extern GameTimerRecord g_timeGlobal;

extern SettingT_GameSettingCollection_ g_011d8740;

struct FUN_006ff3f0_shell : FUN_006ff380_shell
{
    void BGSTerrainNode_UpdateFadeParameters();
};

// @fnv 0x006ff3f0
// src: COMMUNITY 0x006ff3f0
void FUN_006ff3f0_shell::BGSTerrainNode_UpdateFadeParameters()
{
    unsigned int delta;
    unsigned int section = g_timeGlobal.GetSection();
    delta = section - f50;

    if (!tile || !tile->GetModel_0056c7f0())
        return;

    if (delta > (unsigned int)*g_011d8740.Setting_Int())
    {
        BGSTerrainNode_EndFade();
    }
    else
    {
        float f = (double)delta / (unsigned int)*g_011d8740.Setting_Int();
        NiPoint2 pt = ((FUN_006ff210_shell*)this)->BGSTerrainNode_SetFloatPairForLinkID();
        tile->GetModel_0056c7f0()->BSShaderPPLightingProperty_SetLODTexParams(pt.x, pt.y, f);
    }
}

struct ClearPartA
{
    int unk00;
    ~ClearPartA();
    void SetAllAppCulled();
};
struct ClearPartB
{
    int unk00;
    ~ClearPartB();
};
struct ClearFlagHolder
{
    int unk00;
    int unk04;
    int unk08;
    char cUnk0C;
    bool bActive;
};
int __cdecl BGSTerrainManager_GetActive();

struct FUN_006fd7b0_Owner
{
    int m_uiClearFlags;
    int unk04;
    int unk08;
    bool bInitialized;
    ClearPartA* pPartA;
    ClearPartB* pPartB;
    DistantTreeBlockLocal_006fe330* pPartC;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    ClearFlagHolder* pFlagHolder;
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
    bool bCheckOwner;

    void ClearSelectedParts(unsigned int auiFlags);
};

// Deletes pPartA/pPartB/pPartC according to auiFlags bits, conditionally keeping pPartA, and clears pFlagHolder->bActive.
// @fnv 0x006fd7b0
// src: GUESS 0x006fd7b0 (confidence: medium)
void FUN_006fd7b0_Owner::ClearSelectedParts(unsigned int auiFlags)
{
    if (bInitialized && pPartA && (auiFlags & 1))
    {
        if (!bCheckOwner || m_uiClearFlags != BGSTerrainManager_GetActive() || auiFlags == 7)
        {
            delete pPartA;
            pPartA = 0;
        }
        else
            pPartA->SetAllAppCulled();
    }
    if (pPartB && (auiFlags & 2))
    {
        delete pPartB;
        pPartB = 0;
    }
    if (pPartC && (auiFlags & 4))
    {
        delete pPartC;
        pPartC = 0;
    }
    if (pFlagHolder)
        pFlagHolder->bActive = false;
}

struct TerrainUpdate;
struct SceneUpdate
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual SceneUpdate* CastNode(int) = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void Refresh() = 0;
    void SetTaskFlag2000(bool);
    void NiCamera_SetMaxFarNearRatio(float);
    void FUN_00450f90(bool);
};
struct TerrainMgrUpdate
{
    unsigned int GetDaysPassed();
};
struct ChunkUpdate
{
    int f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24, f28, f2c;
    ChunkUpdate(TerrainUpdate*, unsigned int, short, short);
    bool AnimatingText_IsDisplayFinished();
    bool GetInitialized();
    void BGSTerrainChunk_Attach();
    void BGSTerrainChunk_Show();
    SceneUpdate* GetRoot();
    SceneUpdate* GetModel_0056c7f0();
    SceneUpdate* GetMenuRoot();
    SceneUpdate* GetObject3D();
};
struct WorldRefUpdate
{
    TESWorldSpace* Get();
    SceneUpdate* GetMenuRoot();
};
extern TES* g_TES;
extern SettingT_GameSettingCollection_ g_011d86f8;
struct TerrainUpdate
{
    TerrainMgrUpdate* manager;
    unsigned int level;
    short cellX, cellY;
    bool hasGeometry, childrenLoaded;
    unsigned char f0e, f0f;
    ChunkUpdate* chunk;
    void* block;
    void* trees;
    SceneUpdate* scene;
    TerrainUpdate* children[4];
    TerrainUpdate* parent;
    float x, y, z, radius, split, startMorph, endMorph;
    unsigned int fadeStart;
    bool fading;
    unsigned char f55, f56, f57;
    int position;
    bool persistent, splitNode;
    unsigned char f5e, f5f;
    void UpdateTerrainNode(void*, bool);
    bool BGSTerrainNode_ShouldSplit(void*);
    bool GetByteAtOffset5C();
    bool BGSTerrainNode_CheckMeshSolidUnderMe(bool);
    void UpdateTileFromChunk();
    void ClearSelectedParts(int);
    void BGSTerrainNode_UnloadDataRecurse(int);
    WorldRefUpdate* Get();
    bool BGSTerrainNode_CheckIntersectsLoadedRange();
    void UpdateVisibility(SceneUpdate*);
};
// Recursively updates a terrain node: decides split vs geometry state, creates or refreshes its chunk, and updates child nodes and scene objects.
// @fnv 0x006fdaa0
void TerrainUpdate::UpdateTerrainNode(void* arg, bool update)
{
    AutoMemContext context4((MEM_CONTEXT)35, true, kBGSTerrainNodeFileLabel, 284);
    bool below2 = manager->GetDaysPassed() < level;
    bool splitNow2 = BGSTerrainNode_ShouldSplit(arg);
    if (splitNow2 && GetByteAtOffset5C() && chunk && !chunk->AnimatingText_IsDisplayFinished())
        chunk->BGSTerrainChunk_Attach();
    if (below2 || splitNow2)
    {
        splitNode = true;
        if (GetByteAtOffset5C() && !chunk)
            chunk = new ChunkUpdate(this, level, cellX, cellY);
        for (int childIndex2 = 0; childIndex2 < 4; childIndex2++)
        {
            if (children[childIndex2])
                children[childIndex2]->UpdateTerrainNode(arg, update);
        }
        if (chunk && BGSTerrainNode_CheckMeshSolidUnderMe(true))
        {
            for (int loadedIndex2 = 0; loadedIndex2 < 4; loadedIndex2++)
            {
                if (children[loadedIndex2]->chunk && children[loadedIndex2]->chunk->GetInitialized())
                    children[loadedIndex2]->UpdateTileFromChunk();
            }
            ClearSelectedParts(1);
        }
        if (BGSTerrainNode_CheckMeshSolidUnderMe(true))
            childrenLoaded = true;
    }
    else if (hasGeometry)
    {
        SceneUpdate* oldRoot = chunk ? chunk->GetRoot() : 0;
        splitNode = false;
        if (!chunk)
            chunk = new ChunkUpdate(this, level, cellX, cellY);
        else
        {
            bool unusedState5 = false;
            if (chunk->GetInitialized() && chunk->AnimatingText_IsDisplayFinished() && GetByteAtOffset5C())
                chunk->BGSTerrainChunk_Show();
            if (chunk->GetInitialized() && !chunk->AnimatingText_IsDisplayFinished() && (!parent || parent->BGSTerrainNode_CheckMeshSolidUnderMe(true)))
            {
                chunk->BGSTerrainChunk_Attach();
                chunk->GetModel_0056c7f0()->NiCamera_SetMaxFarNearRatio((float)((level / 4.0) * g_011d86f8.Float()->f));
                SceneUpdate* root7 = Get()->GetMenuRoot();
                root7->SetTaskFlag2000(false);
                root7->Refresh();
                root7->SetTaskFlag2000(true);
            }
        }
        if (chunk->AnimatingText_IsDisplayFinished() && childrenLoaded)
        {
            for (int unloadIndex4 = 0; unloadIndex4 < 4; unloadIndex4++)
                if (children[unloadIndex4])
                    children[unloadIndex4]->BGSTerrainNode_UnloadDataRecurse(1);
            childrenLoaded = false;
        }
        if (oldRoot && Get()->Get() != g_TES->GetHitSound())
        {
            TESWorldSpace* worldVal = g_TES->GetHitSound();
            if (worldVal->GetParentUseFlag(TESWorldSpace::PU_LOD) && !worldVal->GetParentUseFlag(TESWorldSpace::PU_LAND) && BGSTerrainNode_CheckIntersectsLoadedRange())
                oldRoot->FUN_00450f90(true);
        }
        if (update && chunk)
        {
            SceneUpdate* geometryB = chunk->GetMenuRoot();
            SceneUpdate* objects3 = chunk->GetObject3D();
            if (geometryB)
                UpdateVisibility(geometryB->CastNode(0));
            if (objects3)
                UpdateVisibility(objects3->CastNode(0));
        }
    }
}

extern const char kBGSTerrainNodeFileLabel[];

struct TerrainSceneX
{
    const char* GetName();
};

unsigned int TerrainTreeLevelX();
bool TerrainTreesEnabledX();
void TerrainTreesInitX(const char* pName);

struct TerrainNodeX : BGSTerrainNode
{
    unsigned int GetLevel();
    TerrainSceneX* GetOwner();
    bool WantsTrees(int iArg);
    void BGSTerrainNode_UpdateTrees(int iArg);
};

// @fnv 0x006fe330
// src: COMMUNITY 0x006fe330
void TerrainNodeX::BGSTerrainNode_UpdateTrees(int iArg)
{
    AutoMemContext kMemContext((MEM_CONTEXT)0x25, true, kBGSTerrainNodeFileLabel, 0x1ed);
    if (GetLevel() == TerrainTreeLevelX())
    {
        if (!TerrainTreesEnabledX())
        {
            TerrainTreesInitX(GetOwner()->GetName());
        }
        if (WantsTrees(iArg))
        {
            if (pTrees == 0)
            {
                pTrees = reinterpret_cast<BGSDistantTreeBlock*>(new DistantTreeBlockLocal_006fe330(this, iLevel, m_sX, m_sY));
            }
            else if (pTrees != 0)
            {
                if (pTrees->IsLoaded())
                {
                    pTrees->Prepare();
                    pTrees->Attach();
                }
            }
        }
        else if (pTrees != 0)
        {
            delete pTrees;
            pTrees = 0;
        }
    }
    else if (GetLevel() > TerrainTreeLevelX())
    {
        for (int i = 0; i < 4; i++)
        {
            if (pChildren[i] != 0)
            {
                ((TerrainNodeX*)pChildren[i])->BGSTerrainNode_UpdateTrees(iArg);
            }
        }
    }
}

namespace fnv_006ff0d0 {
extern TES* g_TES;

class TerrainVisibility
{
  public:
    unsigned int GetCount();
    bool Chk(int idx);
    void Hide(unsigned int idx);
    void Show(unsigned int idx);
    void Finish();
    void Reset();
};

class TerrainNodeX
{
  public:
    void* pManager;
    unsigned int iLevel;
    short m_sX;
    short m_sY;
    bool IsReady();
    void UpdateVisibility(TerrainVisibility* pVisArg, int unused);
};

// @fnv 0x006ff0d0
void TerrainNodeX::UpdateVisibility(TerrainVisibility* pVisibility, int unused)
{
    TESWorldSpace* pWorld = g_TES->GetParentWorldSpace();
    TerrainVisibility* pVis3 = pVisibility;
    if (pVis3)
    {
        if (IsReady())
        {
            for (unsigned int i = 0; i < iLevel; i++)
            {
                for (unsigned int j_ = 0; j_ < iLevel; j_++)
                {
                    if (iLevel * i + j_ < pVis3->GetCount())
                    {
                        int x5 = m_sX + i;
                        int y3 = m_sY + j_;
                        unsigned int idx5 = iLevel * i + j_;
                        TESObjectCELL* pCell4 = pWorld->GetCellAtGridPosition(x5, y3);
                        if (!pVis3->Chk(idx5) && g_TES->IsCellBuffered(pCell4, true))
                            pVis3->Hide(idx5);
                        else
                            pVis3->Show(idx5);
                    }
                }
            }
            pVis3->Finish();
        }
        else
        {
            pVis3->Reset();
        }
    }
}
}  // namespace fnv_006ff0d0

extern "C" char DAT_0106e4e0;
struct Thread006f
{
    unsigned FUN_0059bb30();
};
struct Ret006f
{
    Ret006f* Modelloader_GetReferencedThis();
};
struct Node006f;
struct FUN_006f5160
{
    char data[0x2c];
    FUN_006f5160(Node006f*, int, unsigned short, unsigned short, bool);
    ~FUN_006f5160();
    void* GetNiObj(bool);
    unsigned char FUN_00529ea0();
    void BGSDistantObjectBlock_Attach();
    unsigned char GetByteAtOffset35();
    void ResetAndCreateTask(Ret006f*, int, unsigned short, unsigned short);
    void BGSDistantObjectBlock_SwitchToHigh(Ret006f*, int, unsigned short, unsigned short);
    unsigned char GetField24();
    void BGSDistantObjectBlock_Detach();
    void* FUN_006fd920(unsigned);
};
struct Node006f
{
    Thread006f* thread;
    int f4;
    unsigned short f8, fa;
    int fc, f10;
    FUN_006f5160* block;
    int f18, f1c;
    Node006f* children[4];
    unsigned FUN_00726070();
    bool BGSTerrainNode_ShouldLoadBlock(int);
    bool BGSTerrainNode_ShouldLoadBlockLowPriority(int);
    void BGSTerrainNode_UpdateBlockVisibility(bool);
    Ret006f* Modelloader_GetReferencedThis();
    void UpdateBlock(int, bool);
};
// @fnv 0x006fdfc0
void Node006f::UpdateBlock(int a, bool abFlag)
{
    AutoMemContext guard((MEM_CONTEXT)0x24, true, &DAT_0106e4e0, 0x1ae);
    if (FUN_00726070() == thread->FUN_0059bb30())
    {
        if (BGSTerrainNode_ShouldLoadBlock(a))
        {
            bool flag = BGSTerrainNode_ShouldLoadBlockLowPriority(a);
            if (!block)
            {
                block = new FUN_006f5160(this, f4, f8, fa, flag);
            }
            else if (block && block->GetNiObj(false))
            {
                if (block->FUN_00529ea0())
                    block->BGSDistantObjectBlock_Attach();
                if (abFlag)
                    BGSTerrainNode_UpdateBlockVisibility(false);
            }
            if (block)
            {
                if (block->GetByteAtOffset35() && flag)
                    block->ResetAndCreateTask(Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis(), f4, f8, fa);
                else if (!block->GetByteAtOffset35() && !flag)
                    block->BGSDistantObjectBlock_SwitchToHigh(Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis(), f4, f8, fa);
            }
            if (block->GetField24())
                block->BGSDistantObjectBlock_Detach();
        }
        else if (block)
        {
            delete block;
            block = 0;
        }
    }
    else if (FUN_00726070() > thread->FUN_0059bb30())
    {
        for (int i = 0; i < 4; ++i)
        {
            if (children[i])
                children[i]->UpdateBlock(a, abFlag);
        }
    }
}

struct NodeObj
{
    bool PathingRequestCover_GetSortDistanceFromTarget();
};
struct GridObj
{
    unsigned int GetFlagOrValue();
    bool FUN_006ff0a0(int idx);
    void DisableEntry(int idx);
    void SetEntryActive(int idx);
    void FinalizeEntries();
    void ResetRecordSelection();
};
struct ObjA
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
    virtual GridObj* v10();
};
struct BlockObj
{
    ObjA* GetNiObj(int a);
    void* GetSelectedValue(int a);
    void* GetSelectedValue(int a, int b, int c, int d);
    void UpdateLodVisibility(void* p);
    void VisitNodeTree(void* p);
};
extern TES* DAT_011dea10;
struct FeeNode
{
    int f00;
    unsigned int count;
    short baseX;
    short baseY;
    char f0C;
    char f0D;
    short f0E;
    void* pChunk;
    BlockObj* pBlock;
    bool BGSTerrainNode_CheckIntersectsLoadedRange();
    void BGSTerrainNode_UpdateBlockVisibility(int a);
};
// @fnv 0x006fee90
// src: COMMUNITY 0x006fee90
void FeeNode::BGSTerrainNode_UpdateBlockVisibility(int a)
{
    TESWorldSpace* getter5 = DAT_011dea10->GetParentWorldSpace();
    GridObj* grid;
    if (pBlock)
    {
        if (pBlock->GetNiObj(0))
        {
            grid = pBlock->GetNiObj(0)->v10();
            if (BGSTerrainNode_CheckIntersectsLoadedRange())
            {
                if (grid)
                {
                    unsigned int i;
                    for (i = 0; i < count; i++)
                    {
                        unsigned int j_;
                        for (j_ = 0; j_ < count; j_++)
                        {
                            if ((unsigned int)(count * i + j_) < grid->GetFlagOrValue())
                            {
                                int x4 = baseX + i;
                                int y3 = baseY + j_;
                                int idx4 = count * i + j_;
                                NodeObj* node = reinterpret_cast<NodeObj*>(getter5->GetCellAtGridPosition(x4, y3));
                                if (!grid->FUN_006ff0a0(idx4) && DAT_011dea10->FUN_004511e0(reinterpret_cast<TESObjectCELL*>(node), 1) &&
                                    node->PathingRequestCover_GetSortDistanceFromTarget())
                                {
                                    grid->DisableEntry(idx4);
                                }
                                else
                                {
                                    grid->SetEntryActive(idx4);
                                }
                            }
                        }
                    }
                    grid->FinalizeEntries();
                }
            }
            else
            {
                if (grid)
                {
                    grid->ResetRecordSelection();
                }
            }
        }
    }
    if (pBlock)
    {
        if (pBlock->GetSelectedValue(1))
        {
            if (BGSTerrainNode_CheckIntersectsLoadedRange())
            {
                pBlock->UpdateLodVisibility(
                    pBlock->GetSelectedValue(1, count, (unsigned short)baseX, (unsigned short)baseY));
            }
            else
            {
                pBlock->VisitNodeTree(pBlock->GetSelectedValue(1));
            }
        }
    }
}
