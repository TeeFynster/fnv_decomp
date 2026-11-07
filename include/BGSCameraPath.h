#pragma once

#include "TESForm.h"
#include "PerkEntryConditionSet.h"
#include "CameraShotData.h"
#include "MagicTarget.h"

class BGSCameraShot;
class NiFormArray;
class CameraPathMap;
class CameraResponse;
class CameraFlag;

class BGSCameraPath : public TESForm
{
public:
    PerkEntryConditionSet Conditions;
    BSSimpleList<BGSCameraShot*> m_kCameraShotList;
    CameraShotData data;
    unsigned char layoutPadding29[3];
    NiFormArray* m_pPathArray;
    BGSCameraPath* m_pFirstCameraPath;
    BGSCameraPath* m_pSecondCameraPath;

    BGSCameraPath();
    virtual ~BGSCameraPath();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* modInfo);
    virtual bool Sort(TESForm* form);
    virtual TESForm* CreateForm(void* arg0, void* mapToAddTo);
    virtual void InitItem();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    bool Load(TESFile* file);
    bool HasMissingPathArray();
    NiFormArray* GetEntryObject();
    void ResetFormData();
    void AssignParentPath(BGSCameraPath* parent);
    BGSCameraPath* GetPrevPath();
    BGSCameraPath* GetCameraPathAt(unsigned int);
    void SetPathArray(NiFormArray* paths);
    int HasNameForWarning();
    BSSimpleList<BGSCameraShot*>* GetShotList();
    PerkEntryConditionSet* GetConditions();
    const char* GetEditorID();

    void CopyCommonData(TESForm* src);
    void CopyFromForm(TESForm* apForm);
    void Save_0058ac10();
    bool Compare_0058a750(TESForm* form);
    TESForm* CreateDuplicateForm(bool abPersist, CameraPathMap* apMap);
    TESForm* CreateBaseClone(bool abPersist, CameraPathMap* apMap);

    bool IsFlag2Set();
    bool IsFlag80Set();
    bool GetZoomDefault();
    bool GetZoomDisable();
    bool FUN_00440d80();
    CameraResponse* FUN_00500940(unsigned int context, unsigned int flags);
    CameraFlag* FUN_00891170();
    BGSCameraPath* GetCameraPathToPlay(unsigned int context, unsigned int flags);

    BGSCameraPath* GetParentPath();
    void RemoveChild(BGSCameraPath* child);
    BGSCameraPath* GetPrevPathStub();
    void SetPrevPathStub(BGSCameraPath* prev);
    unsigned int GetChildCount();
    BGSCameraPath* GetChildAt(unsigned int index);
    void SetParentStub(BGSCameraPath* parent);
    void SetParentPath(BGSCameraPath* apParent);
    void SetPrevPathForm(BGSCameraPath* apPrev);
};
