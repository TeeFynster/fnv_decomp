#pragma once

#include "TESForm.h"

class BipedAnim;
class NiAVObject;
class NiNode;
class TESFormList;
class TESObjectREFR;
class TESWaterForm;

class TESObject : public TESForm
{
public:
    TESObject();
    virtual ~TESObject();

    virtual NiAVObject* GetModel3D();
    virtual bool IsBoundAnimObject() const;
    virtual TESWaterForm* GetAssociatedWaterForm() const;
    virtual bool IsAutoCalculated() const;
    virtual void SetPlayable(bool value);
    virtual NiNode* _CreateNiNode(TESObjectREFR* reference, bool arg1);
    virtual void Destroy3DModel(TESObjectREFR* requester);
    virtual bool HasLoaded3D();
    virtual bool IsModelValid() const;
    virtual void UpdateModel3D();
    virtual bool IsBoundItem();
    virtual bool ReplaceModelBip(BipedAnim* biped);
    virtual void Set3D(NiAVObject* object, bool debugPrint);
    virtual unsigned int AcquireReference();
    virtual unsigned int DecRef();
    virtual NiNode* CreateNiNode(TESObjectREFR* reference);

    const char* GetEditorID();
    bool vfn_62();
    bool AtA0();
    bool TESObjectBOOK_GetScroll();

    int GetFormType() const;
    unsigned int GetFormType();
    unsigned int _FNV_GetFormType();
    unsigned int FNV_GetFormType();
    TESObject* GetNext();
    NiAVObject* Get3D();
    unsigned int GetRefCount();
    TESFormList* GetParentList();
    unsigned int GetModelCount();
    bool IsObject();
    char* GetObjectDisplayName();
    void SetParentList(TESFormList* list);
    void nod_SetPrev(TESObject* object);
    void nod_SetNext(TESObject* object);
    TESObject* nod_GetPrev();
    TESObject* nod_GetNext();
    static NiAVObject* FindGeometryByName(NiAVObject* object, char* name);
    char* GetModelFileName(TESObjectREFR* reference);
    void BuildModelFileName(TESObjectREFR* reference, char* buffer);
    void GetLODModelFileName(TESObjectREFR* reference, char* buffer);
    void GetLODFlatFileName(TESObjectREFR* reference, char* buffer);

    NiNode* Get3DObject(TESObjectREFR* requester, bool abFirstPerson);
    NiNode* Create3DForReference(TESObjectREFR* reference);
    bool HasLoaded3D() const;
    bool IsInternal();
    bool IsInternalMarker();
    bool IsBoundAnimObject();
    TESWaterForm* GetAssociatedWaterForm();
    bool IsAutoCalculated();
    bool IsModelValid();
    bool IsBoundItem(BipedAnim* biped);
};
