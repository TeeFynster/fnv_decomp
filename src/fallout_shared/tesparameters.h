// fallout_shared/tesparameters.h: local script function data and parameter metadata
#ifndef FNV_TESPARAMETERS_LOCAL_H
#define FNV_TESPARAMETERS_LOCAL_H

class TESForm;
class Script;
class ScriptFunctionInfo;
struct FunctionData
{
    union Parameter
    {
        float fValue;
        unsigned int m_uiFormID;
        void* pPointer;
    };
    unsigned short usFunction;
    Parameter uParam[2];
};
// src: COMMUNITY
struct ParamInfo
{
    const char* typeStr;
    unsigned int typeID;
    unsigned int isOptional;
};
struct ParamTypeInfo
{
    bool isTESForm;
    unsigned char pad[7];
};
extern ParamTypeInfo DAT_0118cdd5[];
bool __cdecl IsValidTypeValue(const FunctionData* apData, unsigned int auiParam);
struct ParamTypeMetadata
{
    unsigned int type;
    unsigned char pad[4];
};
extern ParamTypeMetadata DAT_0118cdd0[];
extern char DAT_01183140[];
extern const char DAT_01069608[];
extern const char DAT_010695a8[];
extern const char DAT_01069540[];
extern "C" void* __cdecl __RTDynamicCast(void* source, long vfDelta, void* sourceType, void* targetType,
                                         int isReference);
int __cdecl Warning(const char* format, ...);
// src: COMMUNITY
extern ScriptFunctionInfo g_scriptCommands[];
class ScriptFunctionData
{
  public:
    static unsigned int GetParamCount(const FunctionData* apData);
    static bool IsParamTESForm(const FunctionData* apData, unsigned int auiParam);
    static bool GetParamIsScriptVariable(const FunctionData* apData, unsigned int auiParam);
    static Script* GetScriptForParam(unsigned int auiParam, FunctionData* apData);
    static void InitItem(TESForm* apForm, FunctionData* apData);
};
#endif
