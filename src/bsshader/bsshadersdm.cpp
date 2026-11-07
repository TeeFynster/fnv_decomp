// bsshader/bsshadersdm.cpp: BSShaderInitializer (3 functions)

#include "../../include/BSFadeNode.h"
#include "bsshadersdm_decls.h"
// BSShaderRenderUtility_bsshadersdm: local type (was include/BSShaderRenderUtility.h, which had no evidence of one real class); its methods are 0x00469860 TESDataHandler::IsFormIDCreated, 0x00b6ba70 BSShaderUtil::InitSDM, 0x00b6bb30 BSShaderUtil::RecursiveSetPropertyFadeAlpha, 0x00b6c0d0 BSShaderUtil::RenderScene
class AnimIdle;
class BSShaderAccumulator;
class NiCamera;

class BSShaderRenderUtility_bsshadersdm
{
public:
    bool IsRenderTargetId(unsigned int value);
    static void InitializeMultiBounds();
    static void SetRenderCamera(NiCamera* camera, BSShaderAccumulator* accumulator, bool unused);
    static void SetRenderCamera(AnimIdle* camera, AnimIdle* accumulator, bool unused);
    static void SetRenderCamera(void* camera, unsigned int accumulator, bool unused);
    static void SetAlphaOnNode(NiNode* node, float alpha);
};
#include "../../include/StrArr.h"

// @fnv 0x00bc2940
void BSShaderInitializer::InitializeMultiBounds()
{
    if (!DAT_01201f70)
    {
        BSFadeNode::InitializeMultiBounds();
        BSShaderRenderUtility_bsshadersdm::InitializeMultiBounds();
        DAT_01201f70 = true;
    }
}

void __stdcall BoltShaderProperty_ExtendBolt(float, float);
void __stdcall BoltShaderProperty_CleanupBolt(float, float);
// Calls FUN_00bc2660 with a and b when flag is false, otherwise calls FUN_00bc1cc0 with a and c.
// @fnv 0x00bc28b0
void __stdcall DispatchFloatPair(float afFirst, float afSecond, float afThird, bool abUseThird)
{
    if (!abUseThird)
    {
        BoltShaderProperty_ExtendBolt(afFirst, afSecond);
        return;
    }
    BoltShaderProperty_CleanupBolt(afFirst, afThird);
}

void __stdcall WriteToSettingArray(StrArr*);
char* _FUN_00a7d330(const char*);
struct GlobalObjectO2_00a7b610
{
    const char* f0;
};
extern GlobalObjectO2_00a7b610 g_01201f68;
// @fnv 0x00bc28f0
// src: XBOX_PDB 0x00bc28f0
void __stdcall BoltShaderProperty_GetViewerStrings(StrArr* pStrArr)
{
    WriteToSettingArray(pStrArr);
    char* pStr = _FUN_00a7d330(g_01201f68.f0);
    unsigned int uiIndex = pStrArr->m_usSize;
    unsigned int cnt = pStrArr->m_usMaxSize;
    if (uiIndex >= cnt)
    {
        pStrArr->SetSize(pStrArr->m_usGrowBy + uiIndex);
    }
    pStrArr->SetAt(uiIndex, pStr);
}
