#include "../../include/SettingT.h"
#include "../../include/NiFrustum.h"
// fallout_shared/screencustomsplatter.cpp: ScreenCustomSplatter, BSPortal, BSCustomSplatterExtraData (15 functions)

#include "../../include/NiFixedString.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiExtraData.h"
#include "../../include/BSFadeNode.h"
#include "../../include/AutoMemContext.h"
#include "../../include/BSCustomSplatterExtraData.h"
#include "../../include/NiUpdateData.h"
#include "../../include/NiCamera.h"
#include "../../include/NiFrustum.h"
#include "../../include/BSPortal.h"
#include "../../include/SkyTextureManager.h"

#include "../../include/SettingT_GameSettingCollection_.h"
class PortalEntry
{
  public:
    void BSMasterParticleSystem_ResetSystems();
};
class ScreenCustomSplatter
{
  public:
    static void Clear();
    static void Init();
};
// These allocations use the original sized exception-cleanup entry point.
class SplatterNode : public NiNode
{
  public:
    SplatterNode(unsigned short arraySize);
    static void operator delete(void*, unsigned int);
};
extern unsigned int DAT_011c77dc;
extern unsigned char DAT_011c77e8, DAT_011c77e9;
extern float DAT_011c77ec;
extern NiPointer<NiNode> DAT_011c7810;
extern NiPointer<NiTexture> DAT_011c7804, DAT_011c7808, DAT_011c780c;
extern SettingT_GameSettingCollection_ DAT_011ce284, DAT_011ce918, DAT_011cede8;
extern bool DAT_011f941e;

#include "../../include/MEM_CONTEXT.h"
class INISettingCollection;
using ::SettingT;
class NiRenderer;
class GraphicsRenderer
{
  public:
    unsigned int GetRenderTargetWidth();
    unsigned int GetRenderTargetHeight();
};
NiRenderer* NiXenonRenderer_GetRenderer();
extern SettingT<INISettingCollection> DAT_011c77f4;
extern NiPointer<NiNode> DAT_011c781c;
extern SettingT_GameSettingCollection_ DAT_011cfc2c;
extern NiPoint3 DAT_011a9478;
extern float DAT_01022960, DAT_01016248, DAT_0102295c, DAT_01022958, DAT_01189500, DAT_01189504;
extern double DAT_01011598, DAT_01011588;

// Releases each non-null portal entry; this is not the complete BSPortal destructor.
// @fnv 0x00c50930
void __fastcall ClearPortalEntries(BSPortal* portal)
{
    unsigned int count = portal->entries.count;
    for (unsigned int uiIndex = 0; uiIndex < count; uiIndex++)
    {
        PortalEntry* value;
        PortalEntry* slot;
        PortalEntry*& entry = portal->entries.data[uiIndex];
        slot = entry;
        value = slot;
        if (value)
            value->BSMasterParticleSystem_ResetSystems();
    }
}
// @fnv 0x004defb0
void ScreenCustomSplatter::Clear()
{
    if (DAT_011c77e8)
    {
        DAT_011c7810->NiNode_RemoveAllChildren();
        DAT_011c77dc = 0;
        DAT_011c77ec = 0.0f;
        DAT_011c77e9 = 0;
        SkyTextureManager::LoadTextureFromPath(&DAT_011c7808, DAT_011ce918.String());
        SkyTextureManager::LoadTextureFromPath(&DAT_011c7804, DAT_011ce284.String());
        if (DAT_011f941e)
            SkyTextureManager::LoadTextureFromPath(&DAT_011c780c, DAT_011cede8.String());
    }
}
// @fnv 0x004deb30
void ScreenCustomSplatter::Init()
{
    AutoMemContext mem(MEM_CONTEXT_MEM_CONTEXT_EFFECTS_OVERHEAD, true,
                       "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ScreenCustomSplatter.cpp", 189);
    DAT_011c77e8 = DAT_011c77f4.Bool()[0];
    if (DAT_011c77e8)
    {
        GraphicsRenderer* renderer = reinterpret_cast<GraphicsRenderer*>(NiXenonRenderer_GetRenderer());
        float fAspect = (float)renderer->GetRenderTargetWidth() / (float)renderer->GetRenderTargetHeight();
        reinterpret_cast<NiPointer<NiAVObject>&>(DAT_011c781c) = new NiCamera;
        DAT_011c781c->NiAVObject_SetTranslate(NiPoint3(0.0f, 0.0f, DAT_01022960));
        NiUpdateData update1(0.0f, false, false);
        DAT_011c781c->Update(update1);
        reinterpret_cast<NiCamera*>(DAT_011c781c.operator->())->AimAt(NiPoint3::ZERO, DAT_011a9478);
        NiFrustum frustum;
        frustum.Init(false);
        frustum.ortho = false;
        frustum.top = DAT_01016248;
        frustum.bottom = DAT_0102295c;
        frustum.left = (float)(fAspect * DAT_01011598);
        frustum.right = (float)(fAspect * DAT_01011588);
        frustum.farPlane = DAT_01022958;
        frustum.nearPlane = 1.0f;
        reinterpret_cast<NiCamera*>(DAT_011c781c.operator->())->UpdateViewFrustum(frustum);
        NiUpdateData update2(0.0f, false, false);
        DAT_011c781c->Update(update2);
        DAT_01189500 = frustum.right;
        DAT_01189504 = frustum.top;
        DAT_011c77ec = DAT_011cfc2c.Float()->f;
        DAT_011c77e9 = 0;
        reinterpret_cast<NiPointer<NiAVObject>&>(DAT_011c7810) = new SplatterNode(0);
        DAT_011c77dc = 0;
        SkyTextureManager::LoadTextureFromPath(&DAT_011c7808, DAT_011ce918.String());
        SkyTextureManager::LoadTextureFromPath(&DAT_011c7804, DAT_011ce284.String());
        if (DAT_011f941e)
            SkyTextureManager::LoadTextureFromPath(&DAT_011c780c, DAT_011cede8.String());
    }
}

extern NiFixedString* DAT_011c77e4;
// Allocates the "CSD" extra-data key and stores it in DAT_011c77e4.
// @fnv 0x004de580
void CreateCSDFadeNode()
{
    DAT_011c77e4 = new NiFixedString("CSD");
}

// @fnv 0x004de890
// src: COMMUNITY 0x004de890
NiFixedString* BSCustomSplatterExtraData_GetTag()
{
    return DAT_011c77e4;
}

extern float DAT_011feda4;

// @fnv 0x004de8a0
// src: COMMUNITY 0x004de8a0
void BSShaderBloodSplatter_SetFlareOffsetScale(float value)
{
    DAT_011feda4 = value;
}

extern float DAT_011ad874;

// @fnv 0x004de8b0
// src: COMMUNITY 0x004de8b0
void BSShaderBloodSplatter_SetFlareMult(float value)
{
    DAT_011ad874 = value;
}

extern float DAT_011ad878;

// @fnv 0x004de8c0
// src: COMMUNITY 0x004de8c0
void BSShaderBloodSplatter_SetGlobalAlpha(float f)
{
    DAT_011ad878 = f;
}

extern float DAT_011ad878;

// @fnv 0x004de8d0
// src: COMMUNITY 0x004de8d0
float BSShaderBloodSplatter_GetGlobalAlpha()
{
    return DAT_011ad878;
}

extern NiRTTI g_011c7820;

// @fnv 0x004dead0
const NiRTTI* BSCustomSplatterExtraData::GetRTTI() const
{
    return &g_011c7820;
}

// @fnv 0x004deb10
// src: GUESS 0x004deb10 (confidence: low)
void BSCustomSplatterExtraData::ForwardCall_004deb10()
{
    DestroyFields_00a7b300();
}

// @fnv 0x004dea80
BSCustomSplatterExtraData::BSCustomSplatterExtraData(SplatterWordsView* apSource) : NiExtraData(*BSCustomSplatterExtraData_GetTag())
{
    q = *apSource;
}

void __cdecl _delete(void*, unsigned int);
// @fnv 0x004deae0
void* BSCustomSplatterExtraData::DestroyIfFlagged(unsigned int flags)
{
    ForwardCall_004deb10();
    if (flags & 1)
        _delete(this, 0x1c);
    return this;
}

struct OpacityFadeState
{
    float elapsed;
    float duration;
    float opacity;
    unsigned int count;
};
struct TimeGlobal
{
    float FUN_0084d030();
};
extern TimeGlobal DAT_011f6394;
extern SettingT_GameSettingCollection_ DAT_011ceeb4, DAT_011cf6a8;
float LinearInterpolate(float, float, float, float, float);
float BSMIN(float, float);

// Advances each splatter child's elapsed time, removes expired ones, updates opacity and NiUpdateData, then advances the fade value toward 1.
// @fnv 0x004de600
// src: COMMUNITY 0x004de600
void ScreenCustomSplatter_Update()
{
    if (DAT_011c77e8)
    {
        unsigned int uiChildCount = reinterpret_cast<NiNode*>(DAT_011c7810.operator->())->FUN_0043b480();
        float elapsed = DAT_011f6394.FUN_0084d030();
        for (unsigned int index = 0; index < uiChildCount; ++index)
        {
            NiAVObject* child = static_cast<NiAVObject*>(
                reinterpret_cast<NiNode*>(DAT_011c7810.operator->())->FUN_0043b4a0(index));
            if (child)
            {
                BSCustomSplatterExtraData* extra = static_cast<BSCustomSplatterExtraData*>(
                    child->FUN_00a5bdd0(*BSCustomSplatterExtraData_GetTag()));
                OpacityFadeState* data = extra->GetOffsetC();
                data->elapsed += elapsed;
                if (data->elapsed >= data->duration)
                {
                    DAT_011c77dc -= data->count;
                    reinterpret_cast<NiNode*>(DAT_011c7810.operator->())->RemoveNthObject(index);
                }
                else
                {
                    if (!DAT_011c77e9 && data->elapsed / data->duration >= DAT_011c77ec)
                    {
                        data->opacity = 1.0f - LinearInterpolate(0.0f, 1.0f, DAT_011cfc2c.Float()->f * data->duration,
                                                                 data->duration, data->elapsed);
                    }
                    else if (DAT_011c77e9 && data->elapsed >= data->duration - DAT_011c77ec)
                    {
                        float fFadeFraction = (data->duration - DAT_011c77ec) / data->duration;
                        data->opacity = 1.0f - LinearInterpolate(0.0f, 1.0f, fFadeFraction * data->duration,
                                                                 data->duration, data->elapsed);
                    }
                    NiUpdateData updateData(data->elapsed, true, false);
                    child->Update(updateData);
                }
            }
        }
        BSShaderBloodSplatter_SetFlareOffsetScale(DAT_011ceeb4.Float()->f);
        BSShaderBloodSplatter_SetFlareMult(DAT_011cf6a8.Float()->f);
        float fade = BSShaderBloodSplatter_GetGlobalAlpha();
        if (fade < 1.0)
        {
            fade += elapsed / 0.4;
            fade = BSMIN(1.0f, fade);
            BSShaderBloodSplatter_SetGlobalAlpha(fade);
        }
    }
}


struct SplatterParams
{
    float fStart;
    float fAlpha;
    float fScale;
    unsigned int ItemUpdateArray;
};

struct SplatterGeometry
{
    bool AddExtraData(BSCustomSplatterExtraData* pData);
    void SetName(const NiFixedString& kName);
};

struct SplatterRoot
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual void V52();
    virtual void V53();
    virtual void V54();
    virtual void AttachChildInAvailableSlot(SplatterGeometry* pChild, bool abFirstAvailableSlot);
    void Update(NiUpdateData& kData);
};

extern NiPointer<SplatterRoot> g_spSplatterRoot;
extern SettingT_GameSettingCollection_ g_fSplatterDefaultAlpha;

SplatterGeometry* CreateDebrisNode(unsigned int ItemUpdateArray, float fSizeMin, float fSizeMax);
void BSShaderBloodSplatterProperty_SetFadeSourceRecurse(SplatterGeometry* pGeom, void* pList);

// @fnv 0x004de8e0
// src: COMMUNITY 0x004de8e0
void ScreenCustomSplatter_Activate(unsigned int ItemUpdateArray, float fAlpha, int iUnused, float fSizeMin, float fSizeMax)
{
    if (DAT_011c77e8)
    {
        unsigned int uiNum_2 = ItemUpdateArray;
        if (uiNum_2 > 0)
        {
            SplatterGeometry* pGeom = CreateDebrisNode(uiNum_2, fSizeMin, fSizeMax);
            DAT_011c77dc += uiNum_2;
            SplatterParams kParams2;
            kParams2.fScale = 1.0f;
            kParams2.fStart = 0.0f;
            if (fAlpha > 0.0)
            {
                kParams2.fAlpha = fAlpha;
            }
            else
            {
                kParams2.fAlpha = g_fSplatterDefaultAlpha.Float()->f;
            }
            kParams2.ItemUpdateArray = uiNum_2;
            BSCustomSplatterExtraData* pExtraData = new BSCustomSplatterExtraData(reinterpret_cast<SplatterWordsView*>(&kParams2));
            pGeom->AddExtraData(pExtraData);
            pGeom->SetName(NiFixedString("ScreenSplatterRoot"));
            g_spSplatterRoot->AttachChildInAvailableSlot(pGeom, true);
            BSShaderBloodSplatterProperty_SetFadeSourceRecurse(pGeom, pExtraData->GetList());
            NiUpdateData kUpdate(0.0f, false, false);
            g_spSplatterRoot->Update(kUpdate);
        }
    }
}
