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
    void FUN_006fd7b0(int flags);
    void FUN_006fd7b0(unsigned int flags);
    void FUN_006fd980(int flags);
    void FUN_006fda10();
    void FUN_006fe330(int flags);
    bool FUN_006fe550(void* context);
    bool FUN_006fe620(int flags);
    bool FUN_006fe6d0(int flags);
    bool FUN_006fe920(bool checkChildren);
    bool FUN_006fede0();
    void FUN_006fee90(int flags);
    void FUN_006fee90(bool update);
    NiPoint2 FUN_006ff210();
    void FUN_006ff380();
    void FUN_006ff3f0();
    bool GetByteAtOffset5C();
    unsigned int GetLevel();
    bool WantsTrees(int flags);
    bool IsReady();
};
