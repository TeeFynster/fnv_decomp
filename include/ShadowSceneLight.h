#pragma once

#include <windows.h>
#include <d3d9.h>
#include "NiRefObject.h"
#include "BSSimpleArray.h"
#include "NiAVObject.h"
#include "NiPoint3.h"
#include "NiPoint3.h"
#include "NiPlane.h"
#include "NiFrustumPlanes.h"

class BSMultiBoundNode;
class BSPortal;
class BSPortalGraph;
class BSRenderedTexture;
class BSShaderAccumulator;
class NiCamera;
class NiLight;
class NiNode;
class NiSphere;
class NiTexture;
class NiTriBasedGeom;

#include "D3DXMATRIX.h"

class ShadowSceneLight : public NiRefObject
{
public:
    int _unverified_iEnabledPasses;
    float fLuminance;
    D3DXMATRIX kViewProjection;
    D3DXMATRIX kShadowView;
    D3DXMATRIX kShadowProj;
    float fLODDimmer;
    float fShadowLODDimmer;
    float fShadowLODDimmerTarget;
    float fShadowLODDimmerElapsed;
    NiTPointerList<NiPointer<NiTriBasedGeom> > lGeomList;
    bool bCastShadow;
    bool bCubeShadowMap;
    unsigned char _padEE[2];
    NiPointer<NiTexture> spSpecularAttenuationTexture;
    bool bPointLight;
    bool bAmbientLight;
    unsigned char _padF6[2];
    NiPointer<NiLight> spLight;
    bool bDynamicLight;
    unsigned char _padFD[3];
    NiPoint3 bPointPosition;
    NiPointer<BSRenderedTexture> spDynamicShadowMap;
    unsigned short usFrustumCull;
    unsigned char _pad112[2];
    NiPointer<NiAVObject> spFrustumVis;
    bool bShadowSpotlight;
    unsigned char _pad119[3];
    float fSpotlightFOV;
    float fSpotlightFalloff;
    bool bShowDebugTexture;
    unsigned char _pad125[3];
    NiPointer<NiAVObject> spShadowScene;
    NiTPointerList<NiPointer<NiAVObject> > lRootList;
    void* kGeomListFence;
    NiPointer<NiTriBasedGeom> kGeomListFenceObject;
    NiPointer<NiCamera> spShadowCamera;
    NiFrustumPlanes kShadowCameraPlanes;
    float pfClipSpacePlanes[24];
    bool bClipSpacePlanesReady;
    unsigned char _pad209[3];
    NiPointer<BSShaderAccumulator> spShadowAccumulator;
    BSSimpleArray<BSMultiBoundNode*, 1024> kMultiboundRooms;
    BSSimpleArray<BSPortal*, 1024> kPortals;
    BSSimpleArray<NiNode*, 1024> kProcessedNodes;
    BSPortalGraph* pPortalGraph;
    unsigned char _pad244[12];

    ShadowSceneLight();
    virtual ~ShadowSceneLight();
    void ClearShadowObjects();
    void AddObject(NiAVObject* object);
    void ProcessShadowObject(NiAVObject* object);
    void AddShadowObject(NiAVObject* object);
    void AddGeometry(NiTriBasedGeom* geometry);
    bool TestSphereFrustum(NiPoint3* sphere);
    bool BoundWithinLightRadius(NiPoint3* sphere, NiLight* light, float scale);
    bool TestSphereFrustum(const NiSphere& sphere);
    float ComputeLightAttenuation(NiPoint3 point, NiLight* light);
    float ComputeFade(int aiMemoryContext);
};
