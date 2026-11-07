#pragma once

#include "BaseFormComponent.h"

class TESFile;
class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class Actor;
class RefX;
class TESObjectREFR;
class TESBoundObject;
template <class T> class BSStringT;
template <class T> class BSSimpleList;
template <class T_Key, class T_Data> class NiTPointerMap;
template <class T> class BSTCaseInsensitiveStringMap;
template <class T> class NiTLargePrimitiveArray;
enum ENUM_FORM_ID;

class TESForm : public BaseFormComponent
{
  public:
    bool FUN_00460340(); // exe 0x00460340: tests form flags (+8) bit 1 (altered)

    unsigned char cFormType;
    unsigned int iFormFlags;
    unsigned int iFormID;
    // Original member: BSSimpleList<TESFile*> m_kSourceFiles (item, next). Kept as
    // two pointer words here because 41 units carry their own BSSimpleList; it must
    // not be a byte array, which would give stack TESForm objects /GS cookies.
    TESFile* m_kSourceFiles[2];

    virtual ~TESForm();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool Unk_07(void);
    virtual bool LoadForm(TESFile* modInfo);
    virtual bool Unk_09(void* arg);
    virtual bool AppendForm(TESFile* modInfo);
    virtual void SaveForm(void);
    virtual bool LoadForm2(TESFile* modInfo);
    virtual void WriteFormInfo(TESFile* modInfo);
    virtual bool Unk_0E(void* arg);
    virtual bool Sort(TESForm* form);
    virtual TESForm* CreateForm(void* arg0, void* mapToAddTo);
    virtual void Unk_11(void* arg);
    virtual void MarkAsModified(unsigned int changedFlags);
    virtual void MarkAsUnmodified(unsigned int changedFlags);
    virtual unsigned int GetSaveSize(unsigned int changedFlags);
    // Exe/RTTI: slot 21 saves through a buffer; slot 22 is the legacy flags saver.
    // VC9 reverses virtual overload groups, so keep the legacy entry points distinct.
    virtual void SaveGame(BGSSaveFormBuffer* buffer);
    virtual void SaveGameLegacy(unsigned int changedFlags);
    // Slots 23 and 24 are the buffer and legacy two-flag loaders.
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    virtual void LoadGameLegacy(unsigned int changedFlags, unsigned int currentFlags);
    virtual void Unk_19(void* arg);
    virtual void Unk_1A();
    virtual void Unk_1B(void* arg0, void* arg1);
    virtual void Revert(BGSLoadFormBuffer* buffer);
    virtual void RevertLegacy(unsigned int flags);
    virtual void Unk_1E(void* arg);
    virtual bool Unk_1F(void* arg);
    virtual void Unk_20(void* arg);
    virtual void Unk_21(BGSLoadFormBuffer* arg);
    virtual void InitItem(void);
    virtual unsigned int GetTypeID(void);
    virtual void GetDebugName(BSStringT<char>* dst);
    virtual bool IsQuestItem(void);
    virtual bool Unk_26(void);
    virtual bool GetHavokDeath() const;
    virtual bool Unk_28(void);
    virtual bool Unk_29(bool set);
    virtual bool Unk_2A(bool set);
    virtual bool Unk_2B(void);
    virtual bool Unk_2C(void);
    virtual bool Unk_2D(void);
    virtual bool Unk_2E(void);
    virtual void Unk_2F(bool set);
    virtual bool Unk_30(void);
    virtual void MarkForDeletion(bool set);
    virtual void SetAltered(bool set);
    virtual void SetQuestItem(bool set);
    virtual void SetFormFlag40(bool set);
    virtual void SetHavokDeath(bool set);
    virtual void SetNeedToChangeProcess(bool set);
    virtual void Unk_37(void);
    virtual void readOBNDSubRecord(TESFile* modInfo);
    virtual bool IsActor_InEditor(void);
    virtual bool IsBoundObject(void);
    virtual bool Unk_3B(void);
    virtual bool GetIsReference() const;
    virtual bool Unk_3D(void);
    virtual bool Unk_3E(void);
    virtual bool IsMobileObject() const;
    virtual bool IsActor();
    virtual unsigned int Unk_41(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);
    virtual bool CheckFormGRUP(void* arg);
    virtual void InitFormGRUP(void* dst, void* arg1);
    virtual bool Unk_46(void);
    virtual bool Unk_47(void);
    virtual bool Unk_48(unsigned int formType);
    // Slot 73 (+0x124): TESNPC::Activate 0x00607990, TESCreature 0x005fa330, TESBoundObject 0x0050f670; all ret 0x14
    // (five arguments; the TESForm/TESObject default 0x00401270 returns false). Called on the base form at 0x008e8600.
    virtual bool Activate(TESObjectREFR* apTarget, TESObjectREFR* apActivator, bool abFlag, TESBoundObject* apObject, int aiCount);
    virtual void SetRefID(unsigned int refID, bool generateID);
    virtual char* GetName2(void);
    virtual char* GetName(void) const;
    virtual bool SetEditorID_AtRuntime(const char* edid);
    TESForm();
    bool IsActor() const;
    void FUN_00485110(TESFile* file);
    void BeginFormRecord();
    void FinishFormRecord();
    void TESForm___SaveData(void* data, int size);
    const char* TESForm_GetFormTypeString();
    TESFile* FUN_00484e60(int fileIndex);
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    unsigned int FUN_00401170();
    int GetFormEditorIDLength();
    void TESForm_ClearDataAllComponents();
    bool GetMaster();
    bool FUN_00440da0();
    TESFile* GetFile(int fileIndex);
    BSSimpleList<TESFile*>* GetSourceFiles();
    bool IsDeleted() const;
    unsigned int GetFormID();
    bool IsTemporary() const;
    void NotifySaveLoadGameOfFormChange();
    void SetInitializationState(bool initialized);
    bool GetDeleted() const;
    bool GetDisabled() const;
    bool IsStillLoading() const;
    static const int kArmor = 25;
    static const int kWeapon = 40;
    static TESForm* GetFormByID(unsigned int formID);
    bool IsFormInitialized() const;
    bool GetInitialized() const;
    unsigned int GetDataSizeAdjustment();
    void ReadTypedData(TESFile* file, void* data, unsigned short size);
    void SetFormType(ENUM_FORM_ID type);
    void LoadRecordHeader(TESFile* file);
    static void RemapFormIDForFile(unsigned int& formID, TESFile* file);
    unsigned int GetFormID() const;
    bool GetDisabled();
    bool IsInCombat();
    ENUM_FORM_ID GetFormType() const;
    int GetFormType();
    TESFile* GetOwnerMaster();
    void SetMasterFile(bool set);
    void SetDestroyed(bool set);
    void SetDestructible(bool set);
    void SetIgnoreFriendlyHits(bool set);
    static bool IsReservedFormID(unsigned int formID);
    bool IsReservedFormID();
    void SetFormFlags(int flags);
    void UpdateFormChangeFlags();
    static TESForm* LookupFormByEditorID(const char* editorID);
    static TESForm* CreateFormByType(ENUM_FORM_ID type);
    void SetFile(TESFile* file);
    static void InitializeFormIDMap();
    static NiTPointerMap<unsigned int, TESForm*>* ms_pFormIDMap;
    static BSTCaseInsensitiveStringMap<TESForm*>* ms_pEditorIDMap;
    static NiTLargePrimitiveArray<TESForm*>* ms_pAllForms;

    bool GetInitialized();
    bool IsDeleted();
    bool IsConstantGlobal();
    bool IsRadioStationObject();
    void ClearFormData();
    void NotifyFormIDChanged(int);
    void Revert(unsigned int flags);
    void Revert(Actor* actor);
    void RevertWithFlagClear(unsigned int flags);
    void SetCollisionDisabled(bool noCollision);
    const char* GetDescription();
    float GetFieldB8Float();
    int GetA();
    int GetB();
    unsigned int FNV_GetFormType();
    unsigned int FNV_GetFormType() const;
    unsigned int _FNV_GetFormType();
    TESForm* GetLeveled();
    TESForm* GetTemplate(int arg);
    bool GetFlag() const;
    bool IsPlayable();
    bool IsTerminalUsable(RefX* reference);
    int GetTerminalLevel(RefX* reference);

};
