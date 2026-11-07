#pragma once

#include "NiNode.h"

class BSNiBoundArray;
class INISettingCollection;
template <class T> class SettingT;

struct _LODMultType
{
    enum Type
    {
        NONE = 0,
        OBJECTS = 1,
        ITEMS = 2,
        ACTORS = 3,
        TREES = 4,
        LANDSCAPE = 5,
        DISTANT_LOD = 6,
        ACTOR_BODY_PART = 7,
        RENDERED_MENU = 8,
        INVISIBLE = 9,
        IMPOSTER = 10,
        COUNT = 11
    };
};
typedef _LODMultType::Type LOD_MULT_TYPE;

class BSFadeNode : public NiNode
{
  public:
    float fNearDistSqr;
    float fFarDistSqr;
    float fLastFade;
    float fCurrentFade;
    float fBoundRadius;
    float fTimeSinceUpdate;
    int eMultType;
    int iFrameCounter;
    void* pUserData;
    BSNiBoundArray* pBoundArray;
    unsigned char ParentRoomList[8];
    unsigned char ParentPortalList[8];

    BSFadeNode();
    BSFadeNode(const char* name);
    BSFadeNode(const char* name, void* rectangle);
    ~BSFadeNode();

    static NiObject* __cdecl CreateObject();
    static void InitializeMultiBounds();
    static SettingT<INISettingCollection> ms_kMinimumFadeDistanceSetting;
    static NiPointer<NiAlphaProperty> ms_pAlphaProperty;
    static NiFixedString* ms_pFadeNodeAnimationName;

    void __thiscall _Call_a5d3a0();
    void SetRange(float, float);
    void* GetLODMultType();
    LOD_MULT_TYPE GetLODMultType() const;
    void SetTaskFlag(bool culled);
    void SetFadeMode(int);
    void IncRefCount();
    void DecRefCount();
    bool IsVisible();

    void SetIgnoreFade(bool enabled);
    using NiNode::NiAVObject_SetTranslate;
    void NiAVObject_SetTranslate(const NiPoint3& position);
    using NiNode::NiAVObject_Update;
    void NiAVObject_Update(UpdData* data);
    void* FUN_0043b1b0();
    void FUN_004381b0();
    bool NiNode_QNotVisible() const;
    unsigned int QUserData();
    int FUN_004b9900(int flags);
    void* FUN_00a4bcf0(unsigned int a, unsigned int b, unsigned int c);
    void FUN_00c31af0();
    BSFadeNode* NiParticleSystem_00c1b5c0();
    void* FUN_00a94ce0();
    void* FUN_00c32d80();
    void FUN_00a744a0();
    void* FUN_00a981d0();
    void* FUN_00a2eed0();
};
