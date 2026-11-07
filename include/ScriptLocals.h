#pragma once

class Script;
class ScriptDefinition;
class FormFlagRecord;
class ScriptLocalVariable;
class TESForm;
class TESBoundObject;
class ScriptHeaderData;
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;
template <class T> class BSSimpleList;

class ScriptLocals
{
public:
    Script* m_pOwnerScript;
    char m_cActionFlags;
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    BSSimpleList<FormFlagRecord*>* m_pLocalVariableList;
    BSSimpleList<ScriptLocalVariable*>* m_pVariableList;
    ScriptDefinition* m_pExtendedLocals;

    ScriptLocals();
    ~ScriptLocals();
    void Destroy();
#ifdef __vecDelDtor
    void* __vecDelDtor(unsigned int);
#endif
    void ClearActionFlags();
    bool GetLocalData(TESForm*, unsigned int);
    TESBoundObject* GetLocalData();
    void ClearActionFlagsForForm(TESForm*);
    bool CheckActionFlag(TESForm*, unsigned int);
    FormFlagRecord* GetActionEntry(TESForm*, bool);
    TESBoundObject* GetActionEntry();
    void Save(ScriptHeaderData*);
    void ClearActionList();
    void InitializeActionList();
    void CopyActionListFrom(ScriptLocals*);
    void* GetActionList();
    void ResetFormData(Script*);
    void SetVariable(unsigned int, double);
    double GetVariable(unsigned int, Script*);
    BSSimpleList<ScriptLocalVariable*>* GetLocalList();
    bool IsReferenceVariable(unsigned int);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void Revert(BGSLoadFormBuffer*);
    void Revert();
    static void ProcessPendingTasks();
    FormFlagRecord* ScriptLocals_GetActionObject(ScriptLocals* locals, bool create);
    bool SetActionFlag(TESForm* form, unsigned int flag);
    void FUN_005a85c0();
};
