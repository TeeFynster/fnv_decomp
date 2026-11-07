#pragma once

#include "TESForm.h"
#include "NiTPointerMap.h"
#include "BSSimpleArray.h"
#include "MapEntryCount.h"

class NavMeshInfo;
class NavMesh;
class NavigationRequest;
class TeleportableReference;
class TESObjectCELL;
class TESObjectREFR;
class TESWorldSpace;

typedef BSSimpleArray<NavMeshInfo*, 1024> NavMeshInfoArray;

class NavMeshInfoMap : public TESForm
{
public:
    virtual ~NavMeshInfoMap();
    virtual void SaveForm(void);
    virtual bool LoadForm2(TESFile* modInfo);
    virtual bool Sort(TESForm* form);
    virtual void MarkAsUnmodified(unsigned int changedFlags);
    virtual void InitItem(void);
    virtual void SetQuestItem(bool set);

    bool m_bNavMeshInfoArraysValid;
    unsigned char pad19[3];
    NiTPointerMap<unsigned int, NavMeshInfo*> m_kNavMeshInfosByFormID;
    NiTPointerMap<unsigned int, NiTPointerMap<unsigned int, NavMeshInfoArray*>*>
        m_kNavMeshInfoArraysByWorldspace;
    bool m_bKeepNavMeshLoaded;
    unsigned char pad3D[3];

    NavMeshInfoMap();
    bool Load(TESFile* file);
    NavMeshInfo* FUN_00693d70(unsigned int formID);
    bool ValidateNavMeshInfoArrays();
    void InsertNavMeshInfo(NavMeshInfo* info);
    void ClearNavMeshInfoMaps();
    void ValidateNavMeshes();
    bool LoadNavMeshInfoMap(TESFile* file);
    void SaveNavMeshInfoMap();
    void StartSave();
    void EndSave();
    void SetAlteredAndRevertNavMeshes(bool value);
    bool FUN_00460340();
    bool ProcessBeforeSave();
    bool SavesBefore_006b6910(TESForm* form);
    void RegisterNavMeshInfo(TeleportableReference* info);
    void ProcessState_006b6990(unsigned int id);
    void ProcessState_006b6990(NavMesh* mesh);
    void ActivateNavigationEntry(int identifier);
    int FindNavMeshInfoForCell(TESObjectCELL* cell);
    void* FindNavMeshInfoForCellKey(TESWorldSpace* worldSpace, int cellKey);
    int FindNavMeshInfoForCellKey(void* worldSpace, int cellKey);
    unsigned int LookupScriptMessageValue(const char* message);
    int LookupScriptMessageValue(TESObjectCELL* cell);
    void GetAllNavMeshInfo(BSSimpleArray<void*, 1024>* array);
    void RemoveInfoFromCellKeyMap(NavMeshInfo* info);
    void RemoveInfoFromCellKeyMap(unsigned int info);
    void RemoveInfoFromCellKeyMap(NavigationRequest* request);
};
