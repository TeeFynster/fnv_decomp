#pragma once

class CStringArgument;
class Script;
class ScriptLineBuffer;
class TESObjectREFR;
enum COMPILER_NAME;

class ScriptCompiler
{
public:
    ScriptCompiler();

    bool FUN_005aedb0(Script* script, TESObjectREFR* ownerObject, COMPILER_NAME compilerIndex, bool flag);
    bool FUN_005aeb90(Script*, CStringArgument*);
    unsigned int ParseLine(CStringArgument*);
    bool FUN_005b1180(CStringArgument*);
    bool FUN_005aff40(Script*, CStringArgument*, ScriptLineBuffer*);
};
