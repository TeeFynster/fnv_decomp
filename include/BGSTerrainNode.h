#pragma once

#include "NiPoint2.h"
#include "NiPoint3.h"

class BGSTerrainManager;
class BGSTerrainChunk;
class BGSDistantObjectBlock;
class BGSDistantTreeBlock;
class NiNode;
class SceneUpdate;

enum BGSTerrainNode__PARENT_POSITION
{
    BGSTerrainNode__PARENT_POSITION_PP_TOPLEVEL = 0,
    BGSTerrainNode__PARENT_POSITION_PP_UPPER_LEFT = 1,
    BGSTerrainNode__PARENT_POSITION_PP_UPPER_RIGHT = 2,
    BGSTerrainNode__PARENT_POSITION_PP_LOWER_LEFT = 3,
    BGSTerrainNode__PARENT_POSITION_PP_LOWER_RIGHT = 4
};

class BGSTerrainNode
{
public:
    BGSTerrainManager* pManager;
    unsigned int iLevel;
    short m_sX;
    short m_sY;
    bool m_bWithinMaximumLevel;
    bool m_bNodeStateFlag;
    unsigned char layoutPaddingE[2];
    BGSTerrainChunk* pChunk;
    BGSDistantObjectBlock* pBlock;
    BGSDistantTreeBlock* pTrees;
    NiNode* m_pSceneNode;
    BGSTerrainNode* pChildren[4];
    BGSTerrainNode* pParent;
    NiPoint3 Center;
    float m_fNodeRadius;
    float m_fSplitDistance;
    float m_fMorphStartDistance;
    float m_fMorphEndDistance;
    unsigned int TerrainNodeData;
    bool m_bFlagBeforeParentPosition;
    unsigned char layoutPadding55[3];
    BGSTerrainNode__PARENT_POSITION m_eParentPosition;
    bool m_bPersistent;
    bool m_bNodeInitialized;
    unsigned char layoutPadding5E[2];

    BGSTerrainNode(BGSTerrainManager* pManagerArg, BGSTerrainNode* pParentArg,
                   short sX, short sY, unsigned int uiSize, bool bPersistentArg);
    void __thiscall ProcessBlock();
    void Unload();
    void UpdateTerrainNode(void* context, bool update);
    void UpdateBlock(int flags, bool update);
    void UpdateVisibility(SceneUpdate* scene);
    void UpdateVisibility(NiNode* scene);
    void UpdateVisibility(NiNode* scene, int unused);
    void UpdateTileFromChunk();
    void ClearSelectedParts(int flags);
    void ClearSelectedParts(unsigned int flags);
    void BGSTerrainNode_UnloadDataRecurse(int flags);
    void BGSTerrainNode_DestroyRecurse();
    void BGSTerrainNode_UpdateTrees(int flags);
    bool BGSTerrainNode_ShouldSplit(void* context);
    bool BGSTerrainNode_ShouldLoadBlock(int flags);
    bool BGSTerrainNode_ShouldLoadBlockLowPriority(int flags);
    bool BGSTerrainNode_CheckMeshSolidUnderMe(bool checkChildren);
    bool BGSTerrainNode_CheckIntersectsLoadedRange();
    void BGSTerrainNode_UpdateBlockVisibility(int flags);
    void BGSTerrainNode_UpdateBlockVisibility(bool update);
    NiPoint2 BGSTerrainNode_SetFloatPairForLinkID();
    void BGSTerrainNode_EndFade();
    void BGSTerrainNode_UpdateFadeParameters();
    bool GetByteAtOffset5C();
    unsigned int GetLevel();
    bool WantsTrees(int flags);
    bool IsReady();
};
