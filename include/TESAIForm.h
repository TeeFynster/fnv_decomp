#pragma once

#include "BaseFormComponent.h"
#include "PackageList.h"

class Actor;
class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class PackedRecordData;
class TESForm;
class TESObject;
class TESPackage;

class TESAIForm : public BaseFormComponent
{
public:
    TESAIForm();
    ~TESAIForm();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
    virtual unsigned short GetSaveSize(unsigned int flags);
    virtual void SaveGame(unsigned int flags);
    virtual void LoadGame(unsigned int flags, unsigned int version);

    void InitializeComponent();
    void ClearComponent();
    void FreeDataComponent();
    void DestroyPackageList()
    {
        packages.FUN_0067e3a0();
    }
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    void Save();
    void InitItem(TESForm* form);
    void CopyAISettings(TESAIForm* source);
    void CopyAIPackageList(TESAIForm* source);
    void CopyAIPackageList(const TESAIForm* source);
    void CopyAIDataFromAIDATA(PackedRecordData* data);
    void SetAIData(PackedRecordData* data);
    void FUN_0047f0b0(PackedRecordData* data);
    void TESAIForm_AddPackage(unsigned int package);
    void TESAIForm_SetResponsibility(int value, bool addChange);
    void TESAIForm_SetAggression(int value, bool addChange);
    void TESAIForm_SetConfidence(int value, bool addChange);
    void TESAIForm_SetEnergy(int value, bool addChange);

    unsigned char GetAggression();
    void SetAggression(unsigned char value, bool addChange);
    unsigned char GetAssistance();
    void SetAssistance(unsigned char value);
    static float GetConfidenceLevel(unsigned char confidence);
    float GetConfidenceLevel();
    unsigned char GetConfidence();
    unsigned char _GetByte05();
    void SetConfidence(unsigned char value, bool addChange);
    unsigned char GetEnergy();
    void SetEnergy(unsigned char value, bool addChange);
    unsigned char GetResponsibility();
    void SetResponsibility(unsigned char value, bool addChange);
    unsigned char GetMood();
    unsigned char MenuTopic_GetTopicIsChoice();
    void SetAIMood(unsigned char value);
    unsigned int GetServiceFlags();
    void SetServiceFlags(unsigned int flags, bool addChange);
    bool GetOffersService(unsigned int service);
    void SetOffersService(unsigned int service, bool offered);
    int GetTrainingSkill();
    void SetTrainingSkill(int value);
    unsigned char GetTrainingSkillLevel();
    void SetTrainingSkillLevel(unsigned char value);
    bool IsObjectUsable(TESObject* object);
    bool HasAnAggroRadius();
    void SetHasAggroRadius(bool value);
    unsigned int GetAggroRadius();
    void SetAggroRadius(unsigned int value);

    bool HasPackage(TESPackage* package);
    void AddPackage(TESPackage* package);
    bool MovePackage(TESPackage* package, bool moveUp);
    void InsertPackageAt(TESPackage* package, TESPackage* position, bool before);
    void DeletePackage(TESPackage* package);
    static TESPackage* GetCurrentPackage(Actor* actor);
    static void FindAvailablePackages(Actor* actor, BSSimpleList<TESPackage*>* packages, float start, float hour);
    static void FindAvailablePackages(Actor* actor, void* packages, float start, float hour);
    PackageList* GetPackageList();
    const PackageList* GetPackageList() const;

    void AddFormChange(int flags);
    void DispatchToOuter(int flags);
    void SaveGame(BGSSaveFormBuffer* buffer);
    void LoadGame(BGSLoadFormBuffer* buffer);
    void TESAIForm_LoadGame_0047f980(BGSLoadFormBuffer* buffer);
    unsigned int GetSaveSizeTES(unsigned int flags);
    void SaveGameTES(unsigned int flags);
    void LoadGameTES(unsigned int flags);
    TESAIForm& operator=(const TESAIForm& source);

    unsigned char aggression;
    unsigned char confidence;
    unsigned char energy;
    unsigned char responsibility;
    unsigned char mood;
    unsigned char pad[3];
    unsigned int services;
    unsigned char skill;
    unsigned char level;
    unsigned char assistance;
    bool radius;
    unsigned int distance;
    // Explicit cleanup through DestroyPackageList() avoids the shared PackageList destructor.
    union
    {
        struct
        {
            PackageList packages;
        };
    };
};
