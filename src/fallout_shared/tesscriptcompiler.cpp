#include "../../include/BSStringT.h"
// fallout_shared/tesscriptcompiler.cpp: ScriptCompiler, TESForm, S7f, S5a and more (36 functions)

#include "tesscriptcompiler_packet_decls.h"
#include "../../include/TESForm.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/SL.h"
#include "../../include/Script.h"
#include "../../include/StrMem.h"
#include "../../include/TESDataHandler.h"
#include "../../include/ScriptCompiler.h"
#include "../../include/BGSMessage.h"
#include <stddef.h>

// If DAT_011c40c8 is clear, sets it true, reads GetName(), resets it, and returns the name's length or 0 when there is no name.
// @fnv 0x00474cb0
// src: XBOX_PDB 0x00474cb0
int TESForm::GetFormEditorIDLength()
{
    if (DAT_011c40c8)
        return 0;
    DAT_011c40c8 = true;
    const char* name = GetName();
    DAT_011c40c8 = false;
    return name ? BSStringLength(name) : 0;
}

// @fnv 0x005b1120
ScriptFunctionInfo* GetFunctionByOpcode(SCRIPT_OUTPUT output)
{
    ScriptFunctionInfo* result = 0;
    if (output >= 0x100 && output < 0x1cd)
        result = &DAT_0118e8e0[output - 0x100];
    else if (output >= 0x1000 && output < 0x1280)
        result = (ScriptFunctionInfo*)&g_scriptCommands[output - 0x1000];
    return result;
}

struct ScriptVariableData;
struct CStringArgument
{
    bool GetVariable(ScriptVariableData*);
    ScriptReferencedObject* GetReferencedForm(unsigned int);
    bool GetReferencedForm(ScriptVariableData*, bool, bool);
    bool IsPartialScript();
    void* GetScriptLineList();
    void* GetReferencedObjectList();
    void* GetVariableList();
    void ClearAllScriptLines();
    void ClearAllReferenceObjects();
    void ClearAllVariables();
    void* __vecDelDtor(unsigned int);
    char* input;
    unsigned int m_uiInputOffset;
    int m_eCompilerIndex;
    char m_kScriptName[8];
    int m_eErrorCode;
    bool m_bIsPartialScript;
    char _pad_19[3];
    unsigned int m_uiLastLineNumber;
    char* pOutput;
    unsigned int m_uiOutputOffset;
    char header[20];
    char m_kVariableList[8];
    char m_kReferencedObjectList[8];
    Script* m_pCurrentScript;
    char m_kLineList[8];
};
typedef char _sizecheck_ScriptCompileData[sizeof(CStringArgument) == 88 ? 1 : -1];
// @fnv 0x00613790
void* CStringArgument::GetScriptLineList()
{
    return &m_kLineList;
}

struct S7f
{
    char pad[0x2a];
    unsigned char v;
    void SetValue(unsigned char a);
};
// @fnv 0x007f7c90
void S7f::SetValue(unsigned char aucValue)
{
    v = aucValue;
}

// Returns 1 if the string is a valid integer (optional leading '-', then digits only), otherwise 0.
// @fnv 0x004b1230
int IsIntegerString(const char* pcString)
{
    char c = *pcString;
    pcString++;
    if ((c >= '0' && c <= '9') || c == '-')
    {
        if (*pcString == 0 && c == '-')
            return 0;
        c = *pcString;
        pcString++;
        while (c != 0)
        {
            if (c < '0' || c > '9')
                return 0;
            c = *pcString;
            pcString++;
        }
        return 1;
    }
    return 0;
}

// Exe 0x005aea50: unit-local Interface view; declarations and layout are preserved.
struct TesscriptcompilerInterfaceView
{
    static void __cdecl PrintDebugMessage(const char*);
};
extern int DAT_011908f0;
extern int DAT_01196d18;
struct S5a
{
    S5a* ValidateScriptNameTables();
};
// @fnv 0x005aea50
S5a* S5a::ValidateScriptNameTables()
{
    if (DAT_01196d18 != 0x1280)
        TesscriptcompilerInterfaceView::PrintDebugMessage("The script function list doesn't have all the names filled in.\r\n");
    if (DAT_011908f0 != 0x1cd)
        TesscriptcompilerInterfaceView::PrintDebugMessage("The script console-command list doesn't have all the names filled in.\r\n");
    return this;
}

extern "C" void* __cdecl memset(void*, int, unsigned int);

struct ScriptVariableData
{
    char m_auiShapeKeys[0x200];
    unsigned int m_uiVariableID;
    char m_cTypeCode;
    unsigned int m_uiReferenceID;
    unsigned int m_uiFormID;
    void* pForm;
    ScriptVariableData* Reset();
};

// Clears the object's fields and zeroes its 0x200-byte buffer, then returns this.
// @fnv 0x005af310
ScriptVariableData* ScriptVariableData::Reset()
{
    m_uiVariableID = 0;
    m_uiFormID = 0;
    m_cTypeCode = 0;
    m_uiReferenceID = 0;
    pForm = 0;
    memset(this, 0, 0x200);
    return this;
}

void __cdecl FUN_00ec8d33(int a, int b, int c);

// @fnv 0x005afe10
// src: XBOX_PDB 0x005afe10
void __cdecl BSstrtoul(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_00ec8d33(aiArg1, aiArg2, aiArg3);
}

// Advances *apOffset past tab, space and comma characters in apExpLine, stopping at the first other character.
// @fnv 0x005b1b60
// src: XBOX_PDB 0x005b1b60
void __cdecl ScriptCompiler_SkipWhiteSpace(const char* apExpLine, int* apOffset)
{
    for (;;)
    {
        switch (apExpLine[*apOffset])
        {
        case 9:
        case 0x20:
        case 0x2c:
            ++*apOffset;
            break;
        default:
            return;
        }
    }
}

int __cdecl Cmd_NonDefault_Parse(unsigned short arg1, void* arg2, void* arg3, void* arg4, int arg5, int arg6);

// Calls FUN_005b3cd0 with the first four arguments and zero for the last two.
// @fnv 0x005b3c70
// src: EXE 0x005b3c70
int __cdecl Cmd_ShowMessage_Parse(unsigned short arg1, void* arg2, void* arg3, void* arg4)
{
    return Cmd_NonDefault_Parse(arg1, arg2, arg3, arg4, 0, 0);
}

int __cdecl Cmd_NonDefault_Parse(unsigned short, void*, void*, void*, int, int);

// @fnv 0x005b3c40
// src: EXE 0x005b3c40
int __cdecl Cmd_EssentialDeathReload_Parse(unsigned short param1, void* param2, void* param3, void* param4)
{
    return Cmd_NonDefault_Parse(param1, param2, param3, param4, 1, 0);
}

int __cdecl Cmd_NonDefault_Parse(unsigned short, void*, void*, void*, int, int);

// Calls FUN_005b3cd0 with the given arguments plus 0 and 1, returning its result.
// @fnv 0x005b3ca0
// src: EXE 0x005b3ca0
int __cdecl Cmd_ShowWarning_Parse(unsigned short arg1, void* arg2, void* arg3, void* arg4)
{
    return Cmd_NonDefault_Parse(arg1, arg2, arg3, arg4, 0, 1);
}

void __cdecl _Deallocate(void*);
struct List
{
    bool _ref_008256d0();
    void*& _ref_006815c0();
    void _ref_0063f7b0();
};
// @fnv 0x005ae670
void TESDataHandler::ClearHairList()
{
    List* pList = (List*)GetTESHairList();
    while (pList && !pList->_ref_008256d0())
    {
        void* item = pList->_ref_006815c0();
        _Deallocate(item);
        pList->_ref_0063f7b0();
    }
}

void* __cdecl memset(void* dst, int c, unsigned int n);

struct FUN_005af370_shell
{
    unsigned int m_uiValueBeforeData;
    char m_data[0x200];
    unsigned int uiSize;
    unsigned int uiElapsedMilliseconds;
    char m_auiShapeKeys[0x40c - 0x20c];
    unsigned int m_uiValueAfterSecondBuffer;
    char m_pAuxiliaryObject[8];
    unsigned int m_uiTrailingValue;
    FUN_005af370_shell();
};

// @fnv 0x005af370
FUN_005af370_shell::FUN_005af370_shell()
{
    m_uiValueBeforeData = 0;
    uiSize = 0;
    uiElapsedMilliseconds = 0;
    m_uiValueAfterSecondBuffer = 0;
    m_uiTrailingValue = 0;
    memset(m_data, 0, 0x200);
    memset((char*)this + 0x20c, 0, 0x200);
}

namespace fnv_005afeb0 {
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};
struct ScriptVariableData
{
    char pText[512];
    char pad[24];
    ScriptVariableData* Reset();
};
bool __cdecl ResolveScriptCommand(char*);
// @fnv 0x005afeb0
// src: COMMUNITY 0x005afeb0
bool __cdecl ScriptCompiler_IsValidVariableName(const char* apVarName)
{
    if (!apVarName || !apVarName[0])
        return false;
    TESForm* pform = TESForm::LookupFormByEditorID(apVarName);
    if (pform)
        return false;
    ScriptVariableData checkword;
    checkword.Reset();
    TaskQueueInterface::CopyStringToBuffer(checkword.pText, 512, apVarName);
    if (ResolveScriptCommand(checkword.pText))
        return false;
    return true;
}
}  // namespace fnv_005afeb0

#include "../../include/COMPILER_NAME.h"

namespace fnv_005aedb0 {

class Str6a70
{
  public:
    char* pString;
    unsigned short usLen, usMax;
    Str6a70& operator=(const char*);
};
void* __memcpy(void*, const void*, unsigned int);
extern const char* DAT_0118ca7c[];

struct FUN_005ae490;
struct FUN_005ae5c0;
template <class A, class B> class ScriptCompileDataT
{
  public:
    char* pText;
    unsigned int uiElapsedMilliseconds;
    COMPILER_NAME m_eCompilerIndex;
    Str6a70 m_pName;
    unsigned int unk14;
    bool bPartial;
    unsigned int unk1C[3];
    unsigned int kHeader[5];
    unsigned int unk3C[2];
    unsigned int kRefObjects[2];
    Script* pScript;
    unsigned int unk50;
    ScriptCompileDataT();
    ~ScriptCompileDataT();
};
typedef ScriptCompileDataT<FUN_005ae490, FUN_005ae5c0> CStringArgument;

}  // namespace fnv_005aedb0

// Builds compile data from the script and optional owner object, sets the compiler name, then calls FUN_005aeb90 to compile the script.
// @fnv 0x005aedb0
// src: XBOX_PDB 0x005aedb0
bool ScriptCompiler::CompilePartialScript(Script* apScript, TESObjectREFR* apOwnerObject, COMPILER_NAME eCompilerName,
                                  bool abOnLoad)
{
    bool bResult;
    fnv_005aedb0::CStringArgument compileData;
    compileData.m_eCompilerIndex = eCompilerName;
    compileData.bPartial = true;
    if (apOwnerObject && apOwnerObject->TESObjectREFR_GetScriptPointer())
    {
        compileData.pScript = apOwnerObject->TESObjectREFR_GetScriptPointer();
        fnv_005aedb0::__memcpy(compileData.kHeader, compileData.pScript->GetHeader(), 0x14);
        Script::CopyScriptReferences(
            compileData.pScript->GetReferencedObjectList(),
            (BSSimpleList<ScriptReferencedObject*>*)compileData.kRefObjects, 0);
    }
    else
    {
        compileData.pScript = apScript;
    }
    if (eCompilerName == 1 || !((TESForm*)compileData.pScript)->GetFormEditorIDLength())
        compileData.m_pName = fnv_005aedb0::DAT_0118ca7c[compileData.m_eCompilerIndex];
    else
        ((::BSStringT<char>*)&compileData.m_pName)->Set(((TESForm*)compileData.pScript)->GetName(), 0);
    compileData.pText = apScript->GetText();
    bResult = Compile_005aeb90(apScript, (CStringArgument*)&compileData);
    return bResult;
}

void* __cdecl memset(void*, int, unsigned int);
char* __cdecl AllocateZeroed(int, int);

extern char $SG3295[];
extern int _data_011c16bc;

struct FUN_005ae490
{
    unsigned char _padding0[4];
    int _field04;
    int _field08;
    StrMem _field0c;
    int _field14;
    unsigned char _field18;
    int _field1c;
    char* _field20;
    int _field24;
    unsigned char _field28[0x14];
    SL _field3c;
    SL _field44;
    int _field4c;
    SL _field50;

    FUN_005ae490();
};

// @fnv 0x005ae490
FUN_005ae490::FUN_005ae490()
{
    _field1c = 0;
    _field04 = 0;
    _field24 = 0;

    _field20 = AllocateZeroed(1, 0x4000);
    memset(_field20, 0, 4);
    memset(_field28, 0, 0x14);
    memset(_field20, 0, 4);

    _field08 = 0;
    _field18 = 0;
    _field4c = 0;

    _field0c.Set($SG3295, 0);

    _field14 = 0;
}

namespace fnv_005ae5c0 {


struct ListX
{
    unsigned char padding[8];
    ~ListX();
};

void __cdecl _Deallocate(void* ptr);
void __fastcall ClearList(void* ptr);
void __fastcall ScriptCompileData_ClearAllVariables(void* ptr);

struct FUN_005ae5c0
{
    unsigned char padding00[0x0c];
    ::BSStringT<char> _field0c;
    unsigned char stringTailPadding[0x0c];
    char* pOutput;
    unsigned char padding[0x18];
    ListX list1;
    ListX list2;
    unsigned int value;
    ListX list3;

    ~FUN_005ae5c0();
};

// Runs TESDataHandler cleanup, calls two helper teardown routines on this, then deallocates pOutput.
// @fnv 0x005ae5c0
FUN_005ae5c0::~FUN_005ae5c0()
{
    ((TESDataHandler*)this)->ClearHairList();
    ClearList(this);
    ScriptCompileData_ClearAllVariables(this);
    _Deallocate(pOutput);
}
}  // namespace fnv_005ae5c0

extern "C" int __cdecl isalnum(int);
extern "C" void* __cdecl memset(void*, int, unsigned int);

struct ScriptLineBuffer
{
    unsigned int m_uiValueBeforeData;
    char cLine[0x200];
    unsigned int uiSize;
    unsigned int uiElapsedMilliseconds;
    char cOutput[0x200];
    unsigned int m_uiValueAfterSecondBuffer;
    int unk410;
    int unk414;
    unsigned int m_uiTrailingValue;
};

struct ScriptSource
{
    char* pInput;
    unsigned int m_uiInputOffset;
};

void __cdecl ScriptCompileError(ScriptSource* apData, const char* apFormat, ...);

// Reads one line from the script source into the line buffer, skipping comments and leading whitespace and trimming trailing spaces and tabs.
// @fnv 0x005af3f0
int __cdecl ReadScriptLine(ScriptSource* apData, ScriptLineBuffer* apBuffer)
{
    char* pText5 = apData->pInput + apData->m_uiInputOffset;
    int _iOffset = 0;
    bool bSkip = true;
    unsigned char cChar;
    for (;;)
    {
        cChar = pText5[_iOffset++];
        switch ((char)cChar)
        {
        case ';':
            while (cChar && cChar != '\n')
            {
                cChar = pText5[_iOffset++];
            }
        case '\r':
            if (cChar && pText5[_iOffset] == '\n')
            {
                _iOffset++;
            }
        case 0:
            if (!bSkip)
            {
                while (apBuffer->uiSize &&
                       (apBuffer->cLine[apBuffer->uiSize - 1] == ' ' || apBuffer->cLine[apBuffer->uiSize - 1] == '\t'))
                {
                    apBuffer->uiSize--;
                    apBuffer->cLine[apBuffer->uiSize] = 0;
                }
                if (apBuffer->uiSize)
                {
                    apBuffer->cLine[apBuffer->uiSize] = 0;
                    return _iOffset;
                }
            }
            else if (!cChar)
            {
                return 0;
            }
            apBuffer->m_uiValueBeforeData++;
            apBuffer->uiSize = 0;
            memset(apBuffer->cLine, 0, 0x200);
            break;
        default:
            if (apBuffer->uiSize + 1 >= 0x200)
            {
                ScriptCompileError(apData, "Max script line length (%d characters) exceeded.", 0x200);
                apBuffer->m_uiTrailingValue = 0x10;
                return 0;
            }
            if (isalnum(cChar) || cChar == '"')
            {
                bSkip = false;
            }
            if (!bSkip)
            {
                apBuffer->cLine[apBuffer->uiSize] = cChar;
                apBuffer->uiSize++;
            }
            break;
        }
    }
}

struct Node_5afe30
{
    void** _ref_006815c0();
    Node_5afe30* _ref_00726070();
    bool _ref_008256d0();
};

struct Cls_5afe30
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    unsigned int count2c;
    Node_5afe30* BSFile_GetDevice();
    void* GetNodeValue(unsigned int idx);
};

// Returns the value stored in the idx-th node of the list, or null if idx is 0 or exceeds count2c.
// @fnv 0x005afe30
void* Cls_5afe30::GetNodeValue(unsigned int uiIndex)
{
    if (uiIndex == 0)
        return 0;
    if (uiIndex > count2c)
        return 0;
    unsigned int uiPos = 1;
    Node_5afe30* p = BSFile_GetDevice();
    while (p && !p->_ref_008256d0() && uiPos < uiIndex)
    {
        ++uiPos;
        p = p->_ref_00726070();
    }
    return *p->_ref_006815c0();
}

struct ScriptCommandView
{
    const char* longName;
    const char* shortName;
    unsigned int opcode;
    const char* helpText;
    unsigned int m_uiParameterCount;
    void* parameters;
    void* execute;
    void* parse;
    void* evaluate;
    void* reserved;
};
struct ScriptWordView
{
    char text[0x200];
    unsigned int referencedObjectIndex;
    char variableType;
    unsigned int functionCode;
};
extern ScriptCommandView DAT_0118cb50[];
int __cdecl BSstricmp(const char*, const char*);

// Matches word->text against the long or short names of three command tables and, on a hit, stores 'X' in variableType and the command opcode in functionCode.
// @fnv 0x005b1910
bool __cdecl ResolveScriptCommand(ScriptWordView* word)
{
    int index;
    for (index = 0; index < 16; ++index)
    {
        if (BSstricmp(DAT_0118cb50[index].longName, word->text) == 0 ||
            BSstricmp(DAT_0118cb50[index].shortName, word->text) == 0)
        {
            word->variableType = 'X';
            word->functionCode = DAT_0118cb50[index].opcode;
            return true;
        }
    }
    for (index = 0; index < 640; ++index)
    {
        if (BSstricmp(word->text, reinterpret_cast<ScriptCommandView*>(g_scriptCommands)[index].longName) == 0 ||
            BSstricmp(word->text, reinterpret_cast<ScriptCommandView*>(g_scriptCommands)[index].shortName) == 0)
        {
            word->variableType = 'X';
            word->functionCode = reinterpret_cast<ScriptCommandView*>(g_scriptCommands)[index].opcode;
            return true;
        }
    }
    for (index = 0; index < 205; ++index)
    {
        if (BSstricmp(word->text, reinterpret_cast<ScriptCommandView*>(DAT_0118e8e0)[index].longName) == 0 ||
            BSstricmp(word->text, reinterpret_cast<ScriptCommandView*>(DAT_0118e8e0)[index].shortName) == 0)
        {
            word->variableType = 'X';
            word->functionCode = reinterpret_cast<ScriptCommandView*>(DAT_0118e8e0)[index].opcode;
            return true;
        }
    }
    return false;
}

// Scans text from start to the null terminator, counting '(' and ')', and returns whether the final depth is zero.
// @fnv 0x005b1a90
// src: COMMUNITY 0x005b1a90
bool __cdecl ScriptCompiler_CheckParentheses(const char* text, unsigned int start)
{
    int depth_ = 0;
    unsigned int i = start;
    while (text[i] != 0)
    {
        switch (text[i])
        {
        case '(':
            depth_++;
            break;
        case ')':
            depth_--;
            break;
        }
        i++;
    }
    if (depth_ != 0)
    {
        return false;
    }
    return true;
}

// Counts double-quote characters in str from offset onward and returns true only if there are at least two and the count is even.
// @fnv 0x005b1b00
bool __cdecl HasBalancedQuotes(const char* pcString, int offset)
{
    int quoteCount = 0;
    int i = offset;
    while (pcString[i])
    {
        switch (pcString[i])
        {
        case '"':
            quoteCount++;
            break;
        }
        i++;
    }
    if (quoteCount < 2 || (quoteCount & 1))
        return false;
    return true;
}

struct FUN_005ae730_shell
{
    List* ComputeValue_005a8080();
    void ScriptCompileData_ClearAllVariables();
};
struct HairObject
{
    void* DestroyAndFree(unsigned int);
};
// Walks the list from FUN_005a8080 and, while the list is non-null and its check fails, calls DestroyAndFree(1) on each item and advances with FUN_0063f7b0.
// @fnv 0x005ae730
// src: COMMUNITY 0x005ae730
void FUN_005ae730_shell::ScriptCompileData_ClearAllVariables()
{
    List* list = ComputeValue_005a8080();
    while (list && !list->_ref_008256d0())
    {
        HairObject* object;
        void* item = list->_ref_006815c0();
        object = static_cast<HairObject*>(item);
        object ? object->DestroyAndFree(1) : 0;
        list->_ref_0063f7b0();
    }
}

struct ScriptRefHolder;
struct Target;
struct TesscriptcompilerListNodeView;
struct Item;

extern char DAT_01183028[];
extern char DAT_011841cc[];

struct Mgr
{
    void* FindFormByEditorID(ScriptRefHolder* p);
};
extern Mgr* DAT_011c3f2c;

int __cdecl BSstrlen(ScriptRefHolder* p);
void* __cdecl FUN_00ec43fb(void* obj, int vfdelta, void* src, void* dst, int isRef);
int __cdecl FUN_00ec7ec0(char* s, ScriptRefHolder* p, int idx);
int __cdecl FUN_00ec89e9(int c);
Target* __cdecl TESScriptableForm_GetFormScript(TESForm* f);



struct Target
{
    bool FUN_005ac6a0(ScriptRefHolder* p, int* out);
};

// Exe 0x005ae7a0: unit-local ListNode view; declarations and layout are preserved.
struct TesscriptcompilerListNodeView
{
    void*& Slot();
    TesscriptcompilerListNodeView* Next();
};

struct Buf
{
    char* GetBuf();
};

struct Item
{
    int value;
    char unk04[0x0c];
    unsigned char flag;
    char unk11[7];
    Buf m_18;
};

struct ScriptRefHolder
{
    char unk00[0x200];
    int m_200;
    signed char m_204;
    char unk205[7];
    int m_20c;
    TESForm* m_210;
};

struct CompilerCtx
{
    char unk00[0x4c];
    Target* m_4c;

    TesscriptcompilerListNodeView* ComputeValue_005a8080();
    bool ScriptCompileData_GetReferencedObject(ScriptRefHolder* p, int a, int b);
    bool ResolveReference(ScriptRefHolder* p);
};

// Resolves p's form to a Target and fills m_204/m_20c, falling back to scanning list items and m_4c, returning whether a match was found.
// @fnv 0x005ae7a0
bool CompilerCtx::ResolveReference(ScriptRefHolder* apRef)
{
    TesscriptcompilerListNodeView* cur;
    int idx;
    TESObjectREFR* r2;
    Target* t5;
    Item* item;
    char cA;

    idx = BSstrlen(apRef);
    if (apRef->m_210 != 0)
    {
        t5 = 0;
        r2 = (TESObjectREFR*)FUN_00ec43fb(apRef->m_210, 0, DAT_01183028, DAT_011841cc, 0);
        if (r2 != 0)
        {
            r2->TESObjectREFR_InitScript();
            t5 = (Target*)r2->TESObjectREFR_GetScriptPointer();
        }
        else
        {
            if (apRef->m_210 != 0)
            {
                if (apRef->m_210->FUN_00401170() == 0x47)
                {
                    t5 = TESScriptableForm_GetFormScript(apRef->m_210);
                }
            }
        }
        if (t5 == 0)
        {
            apRef->m_20c = 0;
            return false;
        }
        apRef->m_204 = t5->FUN_005ac6a0(apRef, &apRef->m_20c);
        if (apRef->m_204 == 0)
        {
            apRef->m_20c = 0;
            return false;
        }
        return true;
    }
    else
    {
        if (apRef->m_200 != 0)
        {
            apRef->m_20c = 0;
            apRef->m_204 = 0;
            return false;
        }
    }

    cur = ComputeValue_005a8080();
    apRef->m_20c = 0;
    while (cur != 0 && cur->Slot() != 0)
    {
        item = (Item*)cur->Slot();
        if (FUN_00ec7ec0(item->m_18.GetBuf(), apRef, idx) == 0)
        {
            cA = item->m_18.GetBuf()[idx];
            if (FUN_00ec89e9(cA) == 0 && cA != '-' && cA != '_')
            {
                if (item->flag != 0)
                {
                    apRef->m_204 = 's';
                }
                else
                {
                    apRef->m_204 = 'f';
                }
                apRef->m_20c = item->value;
                return true;
            }
        }
        cur = cur->Next();
    }

    if (m_4c != 0)
    {
        apRef->m_204 = m_4c->FUN_005ac6a0(apRef, &apRef->m_20c);
        if (apRef->m_204)
        {
            return true;
        }
    }

    if (DAT_011c3f2c->FindFormByEditorID(apRef) != 0)
    {
        if (ScriptCompileData_GetReferencedObject(apRef, 0, 0))
        {
            apRef->m_20c = 0;
            apRef->m_204 = 'G';
            return true;
        }
    }
    apRef->m_20c = 0;
    apRef->m_204 = 0;
    return false;
}

struct StrBuf8
{
    StrBuf8();
    ~StrBuf8();
    char* GetText();
    int _field00;
    int _field04;
};

struct ScriptNameRef
{
    char* GetName();
};

void __cdecl BSvsprintf(char* buf, const char* fmt, void* args);
void __cdecl BSStringT_char_SPrintF(StrBuf8* out, const char* fmt, char* name, unsigned int line, char* msg);
int __cdecl ConvertFromUni(char* a, int b);
void __cdecl Interface_PrintLine(int a);
void __cdecl Warning_005b5e40(int a);

// @fnv 0x005aea90
void __cdecl ReportScriptError(CStringArgument* self, const char* pcFormat, ...)
{
    void* args = (char*)&pcFormat + sizeof(pcFormat);
    char msg[0x108];
    BSvsprintf(msg, pcFormat, args);
    args = 0;
    StrBuf8 strBuf;
    BSStringT_char_SPrintF(&strBuf, "SCRIPTS: Script '%s', line %d:\n%s", ((ScriptNameRef*)&self->m_kScriptName)->GetName(),
                 self->m_uiLastLineNumber, msg);
    if (self->m_eCompilerIndex == 1)
    {
        Interface_PrintLine(ConvertFromUni(strBuf.GetText(), 0));
    }
    else
    {
        Warning_005b5e40(ConvertFromUni(strBuf.GetText(), 0));
    }
}

static const char scriptNameError[] = "You need to start scripts with \"scriptname ScriptName\"";

struct ScriptHeaderView
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int variableCount;
    unsigned char scriptType;
    unsigned char flags;
};
// @fnv 0x005aeb90
// src: XBOX_PDB 0x005aeb90
bool ScriptCompiler::Compile_005aeb90(Script* script, CStringArgument* pSource)
{
    if (!script || !pSource)
        return false;
    ((S7f*)script)->SetValue(0);
    Node_5afe30* buffer = 0;
    Node_5afe30* previous = 0;
    unsigned int opcode = 0xffff;
    ((ScriptHeaderView*)pSource->header)->scriptType = script->FUN_00500940()->scriptType;
    ((ScriptHeaderView*)pSource->header)->flags = script->FUN_00500940()->flags;
    ((ScriptHeaderView*)pSource->header)->variableCount = script->FUN_00500940()->variableCount;
    if (pSource->input)
    {
        do
        {
            opcode = ParseLine(pSource);
        } while (opcode != 0xffff);
        if (pSource->m_eErrorCode > 0)
            return false;
        pSource->m_uiLastLineNumber = 0;
        if (!pSource->m_bIsPartialScript)
        {
            buffer = (Node_5afe30*)pSource->GetScriptLineList();
            if (!buffer || (buffer && buffer->_ref_008256d0()))
            {
                ScriptCompileError((ScriptSource*)pSource, scriptNameError);
                return false;
            }
            ScriptLineBuffer* first = (ScriptLineBuffer*)*buffer->_ref_006815c0();
            opcode = first->unk410;
            if (opcode == 0xffff)
            {
                return false;
            }
            else if (opcode != 0x1d)
            {
                ScriptCompileError((ScriptSource*)pSource, scriptNameError);
                return false;
            }
            if (!VerifyBlocks(pSource))
                return false;
        }
    }
    buffer = (Node_5afe30*)pSource->GetScriptLineList();
    ScriptLineBuffer* currentLine = 0;
    while (buffer && !buffer->_ref_008256d0())
    {
        currentLine = (ScriptLineBuffer*)*buffer->_ref_006815c0();
        opcode = currentLine->unk410;
        pSource->m_uiLastLineNumber = currentLine->m_uiValueBeforeData;
        if (!ScriptCompiler_CompileLine(script, pSource, currentLine))
            return false;
        previous = buffer;
        buffer = buffer->_ref_00726070();
    }
    ((ScriptHeaderView*)pSource->header)->unk08 = pSource->m_uiOutputOffset;
    if (!pSource->IsPartialScript())
        return false;
    script->InitFromCompileData(pSource);
    ((S7f*)script)->SetValue(1);
    return true;
}

struct Word95
{
    char text[512];
    unsigned int reference;
    char kind;
    int code;
    int variable;
    void* form;
    Word95();
};
struct Line95
{
    unsigned int number;
    char input[512];
    unsigned int size;
    unsigned int cursor;
    char output[512];
    unsigned int outputSize;
    int code;
    unsigned int reference;
    int error;
    Line95();
};
struct Queue95
{
    void FUN_00905820(Line95**);
};
struct Name95
{
    int value;
    int length;
    void FUN_004037f0(const char*, int);
};
unsigned int __cdecl FUN_00ec6130(const char*);
int __cdecl ReadScriptLine(CStringArgument*, Line95*);
int __cdecl ScriptCompiler_GetNextWord(CStringArgument*, Word95*, const char*, unsigned int*, int, int);
void __cdecl ReportScriptError(CStringArgument*, const char*, ...);
void __cdecl FUN_00406d30(char*, unsigned int, const char*);
// @fnv 0x005aeed0
unsigned int ScriptCompiler::ParseLine(CStringArgument* pCompile)
{
    if (pCompile->m_uiInputOffset >= FUN_00ec6130(pCompile->input))
        return 65535;
    Line95* line8 = new Line95;
    line8->number = pCompile->m_uiLastLineNumber + 1;
    int consumed38 = ReadScriptLine(pCompile, line8);
    if (!consumed38)
    {
        pCompile->m_eErrorCode = line8->error;
        delete line8;
        return 65535;
    }
    pCompile->m_uiInputOffset += consumed38;
    Word95 word26;
    int parsed2 = ScriptCompiler_GetNextWord(pCompile, &word26, line8->input, &line8->cursor, 1, 1);
    if (!parsed2)
    {
        ReportScriptError(pCompile, "Syntax Error\r\n%s\r\nCould not parse this line.", line8->input);
        delete line8;
        return 65535;
    }
    line8->reference = word26.reference;
    bool valid46 = word26.kind == 'X';
    if (valid46)
    {
        if (word26.code >= 256 && word26.code < 461 && pCompile->m_eCompilerIndex != 1)
        {
            valid46 = false;
            ReportScriptError(pCompile, "Script command \"%s\" is a console-only command.", word26.text);
        }
    }
    else
    {
        ++pCompile->m_uiLastLineNumber;
        ReportScriptError(pCompile, "Script command \"%s\" not found.", word26.text);
        pCompile->m_eErrorCode = 13;
    }
    if (valid46)
    {
        line8->code = word26.code;
        FUN_00406d30(line8->input, 512, line8->input + line8->cursor);
        line8->size -= line8->cursor;
        pCompile->m_uiLastLineNumber = line8->number;
        if (line8->code == 29)
        {
            unsigned int cursor33 = 0;
            Word95 name21;
            if (ScriptCompiler_GetNextWord(pCompile, &name21, line8->input, &cursor33, 0, 0))
                ((Name95*)&pCompile->m_kScriptName)->FUN_004037f0(name21.text, 0);
            else
            {
                ReportScriptError(pCompile, "Syntax Error.  Missing script name.");
                pCompile->m_eErrorCode = 1;
                delete line8;
                return 65535;
            }
        }
        if ((line8->code == 22 || line8->code == 24) && !line8->input[0])
        {
            ReportScriptError(pCompile, "Syntax Error.  No condition specified for 'if' or 'elseif'.");
            pCompile->m_eErrorCode = 6;
            delete line8;
            return 65535;
        }
        ((Queue95*)pCompile->GetScriptLineList())->FUN_00905820(&line8);
        return line8->code;
    }
    else
    {
        delete line8;
        return 65535;
    }
}

struct LineListNode
{
    bool IsEmpty();
    ScriptLineBuffer*& Item();
    LineListNode* Next();
};

void __cdecl ReportCompileError(CStringArgument* apData, const char* apFormat, ...);

struct ScriptBlockScanner
{
    int ScanBlockLines(CStringArgument* apData, unsigned int* apStartLine);
};

// Counts lines until the if/else/endif block starting after *apStartLine closes.
// @fnv 0x005b13e0
int ScriptBlockScanner::ScanBlockLines(CStringArgument* apData, unsigned int* apStartLine)
{
    int iCount8 = 0;
    int iDepthA = 0;
    int eType4;
    LineListNode* pNodeX;
    ScriptLineBuffer* pLine;
    int bFound = 0;

    pNodeX = (LineListNode*)apData->GetScriptLineList();
    while (pNodeX && !pNodeX->IsEmpty() && !bFound)
    {
        pLine = pNodeX->Item();
        if (pLine->m_uiValueBeforeData > *apStartLine)
        {
            eType4 = pLine->unk410;
            switch (eType4)
            {
            case 0xffff:
                ReportCompileError(apData, "Mismatched if/else/endif.");
                return -1;
            case 0x12:
            case 0x13:
            case 0x14:
                break;
            case 0x16:
                ++iCount8;
                ++iDepthA;
                if (iDepthA >= 10)
                {
                    ReportCompileError(apData, "Max nesting of %d exceeded.", 10);
                    return -1;
                }
                break;
            case 0x17:
            case 0x18:
                if (iDepthA == 0)
                    bFound = 1;
                else
                    ++iCount8;
                break;
            case 0x19:
                if (iDepthA == 0)
                {
                    bFound = 1;
                }
                else
                {
                    --iDepthA;
                    ++iCount8;
                }
                break;
            default:
                ++iCount8;
                break;
            }
        }
        pNodeX = pNodeX->Next();
    }

    if (!bFound)
    {
        ReportCompileError(apData, "Mismatched if/else/endif block starting on line %d.", *apStartLine);
        return -1;
    }
    return iCount8;
}

// CRT isalnum in the game image
int __cdecl FUN_00ec86e1(int c);
int strcpy_s(char* dst, unsigned int size, const char* src);
void* __memcpy(void* dst, const void* src, unsigned int size);

typedef bool(__cdecl* ScriptParseFunctionB15)(unsigned short usParamCount, void* pParams,
                                              FUN_005af370_shell* pkLineBuffer, CStringArgument* pkData);

struct ScriptFunctionB15
{
    const char* pFunctionName;
    const char* m_pShortName;
    unsigned int m_eOutputType;
    const char* m_pDescription;
    bool m_bRequiresReference;
    unsigned short usParamCount;
    void* pParameters;
    void* m_pfnExecute;
    ScriptParseFunctionB15 m_pfnCompile;
};

int __cdecl ScriptCompiler_GetNextWord(CStringArgument* pkData, ScriptVariableData* pkWord, char* pInput, unsigned int* puiOffset,
                         int a5, int a6);
ScriptFunctionB15* __cdecl FUN_005b1120(unsigned int m_uiReferenceID);

struct FUN_005b1570_Class
{
    int CompileScriptLine(CStringArgument* pkData, unsigned int* puiLineNumber, char* pInput, char* pOutput);
};

// @fnv 0x005b1570
int FUN_005b1570_Class::CompileScriptLine(CStringArgument* pkData, unsigned int* puiLineNumber, char* pInput,
                                          char* pOutput)
{
    unsigned int uiIndex;
    unsigned int uiOutOffset;
    unsigned int uiLength;

    uiLength = BSStringLength(pInput);
    uiOutOffset = 0;
    for (uiIndex = 0; uiIndex < uiLength; uiIndex++)
    {
        if (FUN_00ec86e1(pInput[uiIndex]) || pInput[uiIndex] == '"')
        {
            ScriptVariableData kWord;
            kWord.Reset();
            if (!ScriptCompiler_GetNextWord(pkData, &kWord, pInput, &uiIndex, 1, 1))
                return 0;

            if (kWord.m_uiVariableID > 0)
            {
                if (kWord.m_cTypeCode == 'G')
                {
                    pOutput[uiOutOffset] = 'G';
                    uiOutOffset++;
                }
                else
                {
                    pOutput[uiOutOffset] = 'r';
                    uiOutOffset++;
                }
                *(unsigned short*)(pOutput + uiOutOffset) = kWord.m_uiVariableID;
                uiOutOffset += 2;
            }

            if (kWord.m_uiFormID > 0)
            {
                pOutput[uiOutOffset] = kWord.m_cTypeCode;
                uiOutOffset++;
                *(unsigned short*)(pOutput + uiOutOffset) = kWord.m_uiFormID;
                uiOutOffset += 2;
            }
            else if (kWord.m_cTypeCode == 'X')
            {
                pOutput[uiOutOffset] = 'X';
                uiOutOffset++;
                *(unsigned short*)(pOutput + uiOutOffset) = kWord.m_uiReferenceID;
                uiOutOffset += 2;

                ScriptFunctionB15* pkFunction = FUN_005b1120(kWord.m_uiReferenceID);
                if (!pkFunction)
                {
                    ScriptCompileError((ScriptSource*)pkData, "Syntax Error.  Undefined function '%s'.", &kWord);
                    return 0;
                }
                else if (pkFunction->m_bRequiresReference && *(bool*)&pkData->header[0x10] && kWord.m_uiVariableID == 0)
                {
                    ScriptCompileError((ScriptSource*)pkData,
                                       "Reference function '%s' requires explicit reference in quest script.", &kWord);
                    return 0;
                }

                if (pkFunction->pParameters)
                {
                    void* pParams = pkFunction->pParameters;
                    ScriptParseFunctionB15 pfnCompile = pkFunction->m_pfnCompile;
                    unsigned short usParamCount = pkFunction->usParamCount;
                    FUN_005af370_shell kLineBuffer;
                    strcpy_s(kLineBuffer.m_data, 0x200, pInput + uiIndex);
                    kLineBuffer.m_uiValueAfterSecondBuffer = 0;
                    kLineBuffer.m_uiValueBeforeData = *puiLineNumber;
                    if (!pfnCompile(usParamCount, pParams, &kLineBuffer, pkData))
                        return 0;
                    *(unsigned short*)(pOutput + uiOutOffset) = kLineBuffer.m_uiValueAfterSecondBuffer;
                    uiOutOffset += 2;
                    __memcpy(pOutput + uiOutOffset, kLineBuffer.m_auiShapeKeys, kLineBuffer.m_uiValueAfterSecondBuffer);
                    uiOutOffset += kLineBuffer.m_uiValueAfterSecondBuffer;
                    uiIndex += kLineBuffer.uiElapsedMilliseconds;
                }
                else
                {
                    *(unsigned short*)(pOutput + uiOutOffset) = 0;
                    uiOutOffset += 2;
                }
            }
            else if (kWord.m_cTypeCode != 'G')
            {
                if (kWord.m_uiVariableID == 0 && pkData->GetReferencedForm(&kWord, false, false))
                {
                    pOutput[uiOutOffset] = 'Z';
                    uiOutOffset++;
                    *(unsigned short*)(pOutput + uiOutOffset) = kWord.m_uiVariableID;
                    uiOutOffset += 2;
                }
                else
                {
                    ScriptCompileError((ScriptSource*)pkData, "Syntax Error.  Unknown command '%s'.", &kWord);
                    return 0;
                }
            }
        }

        if (uiIndex < uiLength)
        {
            pOutput[uiOutOffset] = pInput[uiIndex];
            uiOutOffset++;
        }
    }

    pOutput[uiOutOffset + 1] = 0;
    return uiOutOffset;
}

struct ScriptLineS
{
    unsigned int m_uiLineNumber;
    char padCur[0x40c];
    unsigned int m_uiType;
};
struct ScriptLineNode
{
    ScriptLineS*& FUN_006815c0();
    ScriptLineNode* FUN_00726070();
};
bool __fastcall FUN_008256d0(ScriptLineNode* pkNode);
// @fnv 0x005b1180
// src: XBOX_PDB 0x005b1180
bool ScriptCompiler::VerifyBlocks(CStringArgument* pkBuffer)
{
    unsigned int uiType5;
    bool bInBlock = false;
    ScriptLineNode* pIterCur = (ScriptLineNode*)pkBuffer->GetScriptLineList();
    while (pIterCur && !FUN_008256d0(pIterCur))
    {
        ScriptLineS* pkLine = pIterCur->FUN_006815c0();
        uiType5 = pkLine->m_uiType;
        switch (uiType5)
        {
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x1d:
        case 0x1f:
            break;
        case 0x10:
            if (bInBlock)
            {
                pkBuffer->m_uiLastLineNumber = pkLine->m_uiLineNumber;
                ReportScriptError(pkBuffer, "Nested begin/end blocks are not allowed.");
                return false;
            }
            else
            {
                bInBlock = true;
            }
            break;
        case 0x11:
            if (!bInBlock)
            {
                pkBuffer->m_uiLastLineNumber = pkLine->m_uiLineNumber;
                ReportScriptError(pkBuffer, "End without matching Begin.");
                return false;
            }
            else
            {
                bInBlock = false;
            }
            break;
        default:
            if (!bInBlock)
            {
                pkBuffer->m_uiLastLineNumber = pkLine->m_uiLineNumber;
                ReportScriptError(pkBuffer, "All script commands must be inside a begin/end block.");
                return false;
            }
            break;
        }
        pIterCur = pIterCur->FUN_00726070();
    }
    return true;
}

namespace fnv_005b12c0 {
struct ScriptLine
{
    unsigned int m_uiValueBeforeData;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
};

struct LineNode
{
    ScriptLine** FUN_006815c0();
    LineNode* FUN_00726070();
    bool FUN_008256d0();
};

struct CStringArgument
{
    LineNode* FUN_00613790();
};

void ReportScriptError(CStringArgument* apData, const char* apMsg, ...);

struct FUN_005b12c0_owner
{
    int CountLinesInBeginBlock(CStringArgument* apData, unsigned int* apLineNumber);
};

// @fnv 0x005b12c0
int FUN_005b12c0_owner::CountLinesInBeginBlock(CStringArgument* apData, unsigned int* apLineNumber)
{
    int count = 0;
    int type;
    int done = 0;
    LineNode* node5 = apData->FUN_00613790();
    ScriptLine* line6;
    while (node5 && !node5->FUN_008256d0() && !done)
    {
        line6 = *node5->FUN_006815c0();
        if (line6->m_uiValueBeforeData > *apLineNumber)
        {
            type = line6->unk410;
            switch (type)
            {
            case 0xffff:
                ReportScriptError(apData, "Begin without matching end starting on line %d.", *apLineNumber);
                return -1;
            case 18:
            case 19:
            case 20:
                break;
            case 16:
                ReportScriptError(apData, "Nested begin/end blocks are not allowed.");
                return -1;
            case 17:
                done = 1;
                break;
            default:
                count++;
                break;
            }
        }
        node5 = node5->FUN_00726070();
    }
    if (!done)
    {
        ReportScriptError(apData, "Mismatched begin/end block starting on line %d.", *apLineNumber);
        return -1;
    }
    return count;
}
}  // namespace fnv_005b12c0

class Item5AE6C0
{
  public:
    ~Item5AE6C0();
    int unk00;
};
class List5AE6C0
{
  public:
    Item5AE6C0* m_item;
    List5AE6C0* m_pkNext;
    bool IsEmpty();
    Item5AE6C0*& GetItem();
    void RemoveHead();
};
class Owner5AE6C0
{
  public:
    List5AE6C0* GetList();
    void ClearList();
};

// Deletes each head item, then removes that head, until the list is empty.
// @fnv 0x005ae6c0
void Owner5AE6C0::ClearList()
{
    List5AE6C0* pkList = GetList();
    while (pkList && !pkList->IsEmpty())
    {
        delete pkList->GetItem();
        pkList->RemoveHead();
    }
}

void __cdecl ReportScriptError(CStringArgument* a, const char* fmt, ...);
unsigned char __cdecl ResolveScriptCommand(ScriptVariableData* w);
extern "C" char* strchr(char* s, int c);
int __cdecl strcpy_s(char* dst, unsigned int n, const char* src);
extern "C" int isalnum(int c);
extern "C" int isalpha(int c);
extern "C" void* _FNV_DynamicCast(void* obj, int a, void* src, void* dst, int b);
extern int DAT_01186500;
struct ScriptFuncDef
{
    int field00;
    int field04;
    TESForm* pForm;
};
struct CompilerShell : public CStringArgument
{
    bool ScriptCompileData_GetReferencedObject(ScriptVariableData* w, int a, bool b);
    bool ResolveReference(ScriptVariableData* w);
    ScriptFuncDef* GetNodeValue(unsigned int idx);
};
// Parses a quoted string or identifier from apExpLine into apWord, resolving references or script commands when aAllowRef is set.
// @fnv 0x005af5f0
// src: XBOX_PDB 0x005af5f0
int __cdecl ScriptCompiler_GetNextWord(CompilerShell* aCompiler, ScriptVariableData* apWord, char* apExpLine, int* apOffset,
                         bool aAllowRef, bool aFlag5)
{
    ScriptCompiler_SkipWhiteSpace(apExpLine, apOffset);
    int len = 0;
    if (apExpLine[*apOffset] == '"')
    {
        if (!HasBalancedQuotes(apExpLine, *apOffset))
        {
            ReportScriptError((CStringArgument*)aCompiler, "Syntax Error.  Mismatched quotes.");
            return 0;
        }
        char* pEnd;
        char* pStart;
        pStart = strchr(apExpLine + *apOffset, '"');
        *pStart = ' ';
        pEnd = strchr(apExpLine + *apOffset, '"');
        *pEnd = 0;
        strcpy_s((char*)apWord, 0x200, pStart + 1);
        len = BSStringLength((const char*)apWord);
        *pStart = '"';
        *pEnd = '"';
        *apOffset = len + *apOffset + 2;
        if (apExpLine[*apOffset] == '.')
        {
            if (!aAllowRef)
            {
                ReportScriptError((CStringArgument*)aCompiler,
                                  "Syntax Error.  Reference not allowed in this context.");
                return 0;
            }
            if (apWord->m_uiVariableID > 0)
            {
                ReportScriptError((CStringArgument*)aCompiler, "Syntax Error.  Invalid reference syntax.");
                return 0;
            }
            *apOffset = *apOffset + 1;
            if (!aCompiler->ScriptCompileData_GetReferencedObject(apWord, 0, aFlag5))
            {
                ReportScriptError((CStringArgument*)aCompiler, "Unknown object '%s'.", apWord);
                return 0;
            }
            return ScriptCompiler_GetNextWord(aCompiler, apWord, apExpLine, apOffset, true, aFlag5);
        }
        ((char*)apWord)[len] = 0;
    }
    if (len == 0)
    {
        while (isalnum(apExpLine[*apOffset]) || apExpLine[*apOffset] == '.' || apExpLine[*apOffset] == '-' ||
               apExpLine[*apOffset] == '_')
        {
            {
                ((char*)apWord)[len] = apExpLine[*apOffset];
                len = len + 1;
                *apOffset = *apOffset + 1;
                if (((char*)apWord)[len - 1] == '.')
                {
                    if (isalpha(((char*)apWord)[0]))
                    {
                        if (!aAllowRef)
                        {
                            ReportScriptError((CStringArgument*)aCompiler,
                                              "Syntax Error.  Reference not allowed in this context.");
                            return 0;
                        }
                        if (apWord->m_uiVariableID != 0)
                        {
                            ReportScriptError((CStringArgument*)aCompiler,
                                              "Syntax Error.  Invalid reference syntax.");
                            return 0;
                        }
                        ((char*)apWord)[len - 1] = 0;
                        if (!aCompiler->ScriptCompileData_GetReferencedObject(apWord, 0, aFlag5))
                        {
                            ReportScriptError((CStringArgument*)aCompiler, "Unknown object '%s'.", apWord);
                            return 0;
                        }
                        return ScriptCompiler_GetNextWord(aCompiler, apWord, apExpLine, apOffset, true, aFlag5);
                    }
                }
                ((char*)apWord)[len] = 0;
            }
        }
    }
    if (aAllowRef)
    {
        if (apWord->m_uiVariableID > 0)
        {
            if (!aCompiler->ResolveReference(apWord) && !ResolveScriptCommand(apWord))
            {
                ReportScriptError((CStringArgument*)aCompiler, "Unknown variable or function '%s'.", apWord);
                return 0;
            }
            ScriptFuncDef* pScriptFunction = aCompiler->GetNodeValue(apWord->m_uiVariableID);
            void* castA;
            void* castB;
            castB = _FNV_DynamicCast(pScriptFunction->pForm, 0, &DAT_01183028, &DAT_011841cc, 0);
            castA = _FNV_DynamicCast(pScriptFunction->pForm, 0, &DAT_01183028, &DAT_01186500, 0);
            if (castB == 0 && castA == 0 && !aFlag5)
            {
                ReportScriptError(
                    (CStringArgument*)aCompiler,
                    "Syntax error.  Invalid reference '%s' (only quests and object references are allowed in this context).",
                    pScriptFunction->pForm->GetName());
                return 0;
            }
            if (castA != 0)
            {
                if (apWord->m_cTypeCode == 'X')
                {
                    ReportScriptError((CStringArgument*)aCompiler,
                                      "Syntax error.  Functions may not be called on quests.");
                    return 0;
                }
            }
        }
        if (apWord->m_cTypeCode == 0 && !aCompiler->ResolveReference(apWord))
        {
            ResolveScriptCommand(apWord);
        }
    }
    return len;
}

namespace fnv_005afa50 {
struct FUN_005afa50_list
{
    void*& head();
    FUN_005afa50_list* next();
};

struct CStringArgument
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    FUN_005afa50_list m_kReferencedObjectList;
};

struct FUN_005afa50_shell : public CStringArgument
{
    bool ScriptCompileData_VerifyReferencedObjectList();
};

struct FUN_005afa50_obj
{
    unsigned char _pad0[8];
    unsigned int m_08;
    unsigned int m_0c;
    char* GetName();
};

void __cdecl ReportScriptError(void* owner, const char* fmt, const char* name);

// Walks m_kReferencedObjectList and returns false, logging via FUN_005aea90, if any item has both m_08 and m_0c zero.
// @fnv 0x005afa50
// src: XBOX_PDB 0x005afa50
bool FUN_005afa50_shell::ScriptCompileData_VerifyReferencedObjectList()
{
    FUN_005afa50_list* list = &m_kReferencedObjectList;
    while (list != 0 && list->head() != 0)
    {
        FUN_005afa50_obj* item = (FUN_005afa50_obj*)list->head();
        list = list->next();
        if (item->m_08 == 0 && item->m_0c == 0)
        {
            ReportScriptError(this, "Unknown referenced object '%s'.", item->GetName());
            return false;
        }
    }
    return true;
}
}  // namespace fnv_005afa50

#include <stdlib.h>
int __cdecl IsIntegerString(const char*);
void* __cdecl FUN_00401460(void*, const void*, unsigned int);
unsigned int __cdecl BSstrlen(const char*);

namespace MsgCompileData {
extern "C" char DAT_01186130[];
}
struct MessageParseWord_5b3c
{
    char text[0x200];
    unsigned int reference;
    char type;
    unsigned int function;
    unsigned int variable;
    TESForm* form;
    MessageParseWord_5b3c* Reset();
};
struct MessageArrayWord_5b3c : MessageParseWord_5b3c
{
    MessageArrayWord_5b3c();
};
struct MessageParameter_5b3c
{
    char* name;
};
int __cdecl ScriptCompiler_GetNextWord(void*, MessageParseWord_5b3c*, char*, unsigned int*, bool, bool);
struct CompileMessageContext_5b3c
{
    bool ScriptCompileData_GetReferencedObject(MessageParseWord_5b3c*, bool, bool);
};
void __cdecl ReportScriptError(void*, const char*, ...);

// Parses and compiles a MessageBox script line into binary output, handling literal text, parameters, variables, buttons, and duration.
// @fnv 0x005b3cd0
// src: COMMUNITY 0x005b3cd0
bool __cdecl Cmd_NonDefault_Parse(unsigned short opcode, MessageParameter_5b3c* apParameter, ScriptLineBuffer* line,
                          CompileMessageContext_5b3c* context, bool hasButtons, bool literal)
{
    int size;
    {
        MessageParseWord_5b3c message;
        {
            BGSMessage* form;
            {
                unsigned short version;
                {
                    int count;
                    {
                        const char* text;
                        {
                            char* output;
                            line->uiElapsedMilliseconds = 0;
                            version = 1;
                            *(unsigned short*)&line->cOutput[line->m_uiValueAfterSecondBuffer] = version;
                            line->m_uiValueAfterSecondBuffer += 2;
                            message.Reset();
                            form = 0;
                            size = 0;
                            if (literal)
                            {
                                size = ScriptCompiler_GetNextWord(context, &message, line->cLine, &line->uiElapsedMilliseconds, false,
                                                    false);
                                if (!size)
                                {
                                    ReportScriptError(context, "No message text.");
                                    return false;
                                }
                                *(unsigned short*)&line->cOutput[line->m_uiValueAfterSecondBuffer] =
                                    (unsigned short)size;
                                line->m_uiValueAfterSecondBuffer += 2;
                                FUN_00401460(&line->cOutput[line->m_uiValueAfterSecondBuffer], &message, size);
                                line->m_uiValueAfterSecondBuffer += size;
                            }
                            else
                            {
                                MessageParseWord_5b3c word;
                                word.Reset();
                                size = ScriptCompiler_GetNextWord(context, &word, line->cLine, &line->uiElapsedMilliseconds, false,
                                                    false);
                                if (!size)
                                {
                                    ReportScriptError(context, "Missing parameter %s.\r\nCompiled script not saved!",
                                                 apParameter->name);
                                    return false;
                                }
                                if (word.reference > 0 || word.type)
                                {
                                    ReportScriptError(context,
                                                 "Parameter %s may not be a variable.\r\nCompiled script not saved!",
                                                 apParameter->name);
                                    return false;
                                }
                                if (!context->ScriptCompileData_GetReferencedObject(&word, false, false) || word.reference == 0)
                                {
                                    ReportScriptError(context,
                                                 "Item '%s' not found for parameter %s.\r\nCompiled script not saved!",
                                                 &word, apParameter->name);
                                    return false;
                                }
                                form = static_cast<BGSMessage*>(
                                    _FNV_DynamicCast(word.form, 0, DAT_01183028, MsgCompileData::DAT_01186130, 0));
                                if (word.variable == 0 && form == 0)
                                {
                                    ReportScriptError(context,
                                                 "Invalid message '%s' for parameter %s.\r\nCompiled script not saved!",
                                                 &word, apParameter->name);
                                    return false;
                                }
                                char* output = line->cOutput;
                                output[line->m_uiValueAfterSecondBuffer] = 'r';
                                line->m_uiValueAfterSecondBuffer++;
                                *(unsigned short*)&output[line->m_uiValueAfterSecondBuffer] =
                                    (unsigned short)word.reference;
                                line->m_uiValueAfterSecondBuffer += 2;
                            }
                            text = 0;
                            if (literal)
                                text = message.text;
                            else
                            {
                                // Address the description subobject directly: /Od adds a null check to base casts.
                                text = form ? reinterpret_cast<TESDescription*>(
                                                  (char*)form + offsetof(BGSMessage, TESDescription::m_uiDescriptionFileOffset) -
                                                  offsetof(TESDescription, m_uiDescriptionFileOffset))
                                                  ->GetDescription(0, static_cast<CHUNK_ID>(0x43534544))
                                            : 0;
                            }
                            count = 0;
                            while (text && *text)
                            {
                                if (*text == '%')
                                {
                                    if (text[1] == '%')
                                        text++;
                                    else
                                        count++;
                                }
                                text++;
                            }
                            if (count >= 10)
                            {
                                ReportScriptError(context, "Max variables of %d exceeded.", 10);
                                return false;
                            }
                            *(unsigned short*)&line->cOutput[line->m_uiValueAfterSecondBuffer] = (unsigned short)count;
                            line->m_uiValueAfterSecondBuffer += 2;
                            output = line->cOutput;
                            for (int i = 0; i < count; i++)
                            {
                                MessageParseWord_5b3c word;
                                word.Reset();
                                size = ScriptCompiler_GetNextWord(context, &word, line->cLine, &line->uiElapsedMilliseconds, true,
                                                    false);
                                if (!size)
                                {
                                    ReportScriptError(context,
                                                 "Too few variables in MessageBox parameters; expected %d, found %d.",
                                                 count, i);
                                    return false;
                                }
                                if (!word.type)
                                {
                                    ReportScriptError(context, "Unknown variable '%s' in MessageBox parameters.", &word);
                                    return false;
                                }
                                if (word.reference > 0)
                                {
                                    if (word.type == 'G')
                                    {
                                        output[line->m_uiValueAfterSecondBuffer] = 'G';
                                        line->m_uiValueAfterSecondBuffer++;
                                    }
                                    else
                                    {
                                        output[line->m_uiValueAfterSecondBuffer] = 'r';
                                        line->m_uiValueAfterSecondBuffer++;
                                    }
                                    *(unsigned short*)&output[line->m_uiValueAfterSecondBuffer] =
                                        (unsigned short)word.reference;
                                    line->m_uiValueAfterSecondBuffer += 2;
                                }
                                if (word.type != 'G')
                                {
                                    if (word.variable > 0)
                                    {
                                        output[line->m_uiValueAfterSecondBuffer] = word.type;
                                        line->m_uiValueAfterSecondBuffer++;
                                        *(unsigned short*)&output[line->m_uiValueAfterSecondBuffer] =
                                            (unsigned short)word.variable;
                                        line->m_uiValueAfterSecondBuffer += 2;
                                    }
                                    else
                                    {
                                        ReportScriptError(
                                            context,
                                            "Unknown compiler error in MessageBoxCompile.  Failed to parse variable '%s'.",
                                            &word);
                                        return false;
                                    }
                                }
                            }
                            if (!literal)
                            {
                                if (hasButtons)
                                {
                                    int buttons = 0;
                                    {
                                        MessageArrayWord_5b3c words[10];
                                        do
                                        {
                                            size = ScriptCompiler_GetNextWord(context, &words[buttons], line->cLine,
                                                                &line->uiElapsedMilliseconds, false, false);
                                            if (size > 0)
                                                buttons++;
                                        } while (size > 0 && buttons < 10);
                                        *(unsigned short*)&line->cOutput[line->m_uiValueAfterSecondBuffer] =
                                            (unsigned short)buttons;
                                        line->m_uiValueAfterSecondBuffer += 2;
                                        for (int j = 0; j < buttons; j++)
                                        {
                                            *(unsigned short*)&line->cOutput[line->m_uiValueAfterSecondBuffer] = 1;
                                            line->m_uiValueAfterSecondBuffer += 2;
                                            size = BSstrlen(words[j].text);
                                            *(unsigned short*)&line->cOutput[line->m_uiValueAfterSecondBuffer] =
                                                (unsigned short)size;
                                            line->m_uiValueAfterSecondBuffer += 2;
                                            FUN_00401460(&line->cOutput[line->m_uiValueAfterSecondBuffer], &words[j],
                                                         size);
                                            line->m_uiValueAfterSecondBuffer += size;
                                        }
                                    }
                                }
                                else
                                {
                                    int duration = 0;
                                    MessageParseWord_5b3c word;
                                    word.Reset();
                                    size = ScriptCompiler_GetNextWord(context, &word, line->cLine, &line->uiElapsedMilliseconds,
                                                        false, false);
                                    if (size > 0)
                                    {
                                        if (!IsIntegerString(word.text))
                                        {
                                            ReportScriptError(
                                                context,
                                                "Message time must be an integer.\r\nCompiled script not saved!");
                                            return false;
                                        }
                                        else
                                            duration = atol(word.text);
                                    }
                                    *(int*)&line->cOutput[line->m_uiValueAfterSecondBuffer] = duration;
                                    line->m_uiValueAfterSecondBuffer += 4;
                                }
                            }
                            return true;
                        }
                    }
                }
            }
        }
    }
}
