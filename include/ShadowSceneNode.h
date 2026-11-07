#pragma once

#include "NiNode.h"
#include "NiPoint3.h"

class ShadowSceneLight;
class NiLight;
class BSFogProperty;
class NiCamera;
class BSPortalGraph;
class NiNodeW7;
class SceneObject;
struct ShadowListItem;

struct ShadowList
{
    ShadowListItem* head;
    ShadowListItem* tail;
    unsigned int count;

    ShadowList();
    ~ShadowList();
    void RemoveAll();
};

template <class T> class ShadowSceneList : public NiTPointerList<NiPointer<T> >
{
  public:
    ShadowSceneList();
    ~ShadowSceneList();
    void RemoveAll();
};

class BSCompoundFrustum
{
  public:
    BSCompoundFrustum();
    ~BSCompoundFrustum();
    void FUN_00c47770();

    unsigned char unk00[164];
};

class ShadowSceneNode : public NiNode
{
  public:
    ShadowSceneNode();
    virtual ~ShadowSceneNode();

    unsigned char _unverified_bFrustumAddedToVis[1];
    unsigned char _padAD[3];
    unsigned char _unverified_fStoredFarClip[4];
    ShadowList lLightList;
    ShadowList lShadowLightList;
    void* kShadowLightListIterator;
    void* kShadowLightActiveFence;
    void* kShadowLightFadingInFence;
    NiPointer<ShadowSceneLight> kShadowLightActiveFenceObject;
    NiPointer<ShadowSceneLight> kShadowLightFadingInFenceObject;
    ShadowSceneLight* pSunLight;
    ShadowSceneList<ShadowSceneLight> lLightQueueAdd;
    ShadowSceneList<ShadowSceneLight> lLightQueueRemove;
    ShadowSceneList<ShadowSceneLight> lLightQueueUpdate;
    ShadowSceneList<NiAVObject> lObjectQueueUpdate;
    ShadowSceneList<NiAVObject> lObjectQueueUpdateActiveOnly;
    unsigned char cSceneGraphIndex;
    unsigned char _pad121[3];
    NiPointer<NiRefObject> pWindowReflectionEnvMap;
    NiPointer<NiCamera> spCubeMapCamera;
    int iCurrentCubeMapFace;
    bool bDisableLightUpdate;
    bool bWireframe;
    unsigned char _pad132[2];
    NiPointer<BSFogProperty> spFog;
    BSCompoundFrustum kCompoundFrustum;
    bool bVisibleUnboundSpace;
    unsigned char _pad1DD[3];
    BSPortalGraph* pBSPortalGraph;
    NiPoint3 kLightingOffset;
    NiPoint3 kEyePosition;
    bool bAllowLightRemoveQueues;
    unsigned char _pad1FD[3];

    void AttachLight(NiAVObject* object);
    void AddObject(NiAVObject* object);
    void RemoveObject(NiAVObject* object);
    void RemoveSceneObject(NiAVObject* object, bool flag);
    void RemoveSceneObject(NiNode* object, bool flag);
    void UpdateShadowLights();
    float CalculateLightingAtPoint(NiPoint3 point, int& count, float& ambient, float& diffuse, NiLight* ignore);
    float FUN_00b5b610(NiPoint3 kPos, int* piOut, float* pfA, float* pfB, NiPoint3 kPos2, NiAVObject* pkLight);
    void SetFogPropertyForIndex(BSFogProperty* property);
    ShadowSceneLight* GetShadowSceneLight(NiLight* light, bool flag);
    void SetCreatureType(unsigned char type);
    unsigned char ShadowSceneNode_GetDisableLightUpdate();
    void RemoveObject_00b5b1c0(NiAVObject* object);
    void RemoveObject_00b5b1c0(SceneObject* object);
    void FUN_00b5ca70(NiNode* node, float radius);
    void FUN_00b5ca70(NiNodeW7* node, float radius);
    void RemoveAllLights();
    void ShadowSceneNode_RemoveLight(NiNode* node);
};
