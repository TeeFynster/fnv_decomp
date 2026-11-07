#pragma once

#include "BSShaderProperty.h"
#include "NiColorA.h"

class ShadowSceneLight;
class NiTriBasedGeom;

// PC layout (0x7c): the constructor (0x00b71720) and MakeClone's allocation (push 0x7c at 0x00b71826) both follow
// the PDB: the light list at +0x60, fForcedDarkness = 1.0 at +0x6c, uiReferenceID at +0x70, bLightListChanged at
// +0x74 and kLightListFence at +0x78. The 0x80-byte shader property allocated at many sites (constructor 0x00b6fc90)
// is BSShaderNoLightingProperty.
class BSShaderLightingProperty : public BSShaderProperty
{
  public:
    BSShaderLightingProperty();
    BSShaderLightingProperty& operator=(const BSShaderLightingProperty& property);

    NiObject* MakeClone(CloningProcess& process);
    void CopyLightingDataTo(BSShaderLightingProperty* property, CloningProcess& process);
    __declspec(noinline) void CopyMemberData(BSShaderLightingProperty* source, CloningProcess& process);
    void CopyMemberData(BSShaderLightingProperty* source, CloningProcess* process);
    static NiObject* CreateObject();

    bool CopyLightingDataTo(ShadowSceneLight* light, NiBound* bound, void*& iter);
    bool CopyLightingDataTo(ShadowSceneLight* light, NiBound* bound, void** iter);
    void ResortLights(NiBound* bound);
    bool AreLightsSorted(NiBound* bound);
    ShadowSceneLight* GetFirstAttachedLight(void*& iter);
    ShadowSceneLight* GetFirstAttachedLight(void** iter);
    ShadowSceneLight* GetFirstActiveLight(void*& iter);
    ShadowSceneLight* GetFirstActiveLight(void** iter);
    ShadowSceneLight* GetFirstActiveNonShadowLight(void*& iter);
    ShadowSceneLight* GetFirstActiveNonShadowLight(void** iter);
    ShadowSceneLight* GetNextLight(void*& iter);
    ShadowSceneLight* GetNextLight(void** iter);
    ShadowSceneLight* GetNextAttachedLight(void*& iter);
    ShadowSceneLight* GetNextAttachedLight(void** iter);
    ShadowSceneLight* GetNextAttachedLight(void* iter);
    ShadowSceneLight* GetNextVisibleNonShadowLight(void*& iter);
    ShadowSceneLight* GetNextVisibleNonShadowLight(void** iter);
    void AttachLight(ShadowSceneLight* light, NiBound* bound);
    void RemoveLight(ShadowSceneLight* light);
    unsigned short GetNumberofLights();
    unsigned short GetNumberOfActiveLights();
    unsigned short GetNumberofActiveNonShadowLights();
    unsigned char IsLightingProperty();

    static void SetShaderConstant(int index, NiColorA value);
    static void SetLight(unsigned int index, ShadowSceneLight* light, float scale);
    static void SetLight1x2x(unsigned int index, ShadowSceneLight* light, float scale);
    static void SetPointLight3x(unsigned int index, ShadowSceneLight* light, float scale);
    static void SetSpotLight3x(unsigned int index, ShadowSceneLight* light, float scale);
    static void ResetLights(int count);

    void SetForcedDarkness(float darkness);
    float GetForcedDarkness();
    void SetReferenceID(unsigned int referenceID);
    unsigned int GetReferenceID();
    void FenceAllLights();
    void ClearLights() throw();
    void ClearLights(NiTriBasedGeom* geometry);
    void RemoveItemsAfterPos(NiTriBasedGeom* geometry);
    void RemoveItemsAfterPos(void* geometry);
    void SetLightListChanged(bool changed);

    void BSShaderLightingProperty_FenceAllLights();

    unsigned char lLightList[12];
    float fForcedDarkness;
    unsigned int uiReferenceID;
    bool bLightListChanged;
    unsigned char _pad75[3];
    void* kLightListFence;
};
